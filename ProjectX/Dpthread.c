// #define INITGUID
#include <windows.h>
#include <dplay.h>
#include <dplobby.h>
#include <stdio.h>
#include <time.h>

#include <stdarg.h>
#include "typedefs.h"
#include "New3D.h"
#include "typedefs.h"
#include <dplay.h>
#include "new3d.h"
#include "quat.h"
#include "CompObjects.h"
#include "bgobjects.h"
#include "Object.h"
#include "mydplay.h"
#include "ships.h"
#include "main.h"
#include "Title.h"
#include "Text.h"
#include "screenpolys.h"
#include "magic.h"
#include "XMem.h"
#include "ddsurfhand.h"
#include "pickups.h"
#include "local.h"
#include "comm.h"
#include "gsutils.h"

#include "dpthread.h"
#include "demo_id.h"
#include "primary.h"

//#define	DPTEST
extern	LPDIRECTPLAYLOBBY2A					lpDPlayLobby;		//Lobby stuff...
extern LPDIRECTPLAY3 glpDP;
extern	BYTE	WhoIAm;
extern	BYTE	GameStatus[];
extern	char    IPAddressText[16];
extern	LPDPSESSIONDESC2	glpdpSD;
extern	SHORTNAMETYPE	Names;	// all the players short Names....
extern	BOOL	IsHost;
extern	GLOBALSHIP		Ships[];
extern GUID	ServiceProvidersGuids[];
extern	LIST	ServiceProvidersList;
extern uint16 PingTimes[MAX_PLAYERS];
extern SLIDER	MaxServerPlayersSlider;
extern BYTE	TeamNumber[];
extern LIST	TrackersList;
extern	BOOL IsServerGame;

extern BOOL IsLobbyLaunched;
extern BOOL NoMenuBack;


// TEMP?
extern char MissionTextNames[MAXLEVELS][128];
extern LIST	LevelList;
extern	SLIDER  PacketsSlider;

void DebugPrintf( const char * format, ... );
extern void SetMultiplayerPrefs( void );

//
// modify this struction with what ever you want.
// just make sure you modify the sprintf in ProcessForsakenInfo
// to print the values
//
typedef struct playerlist_tag {
	char	PlayerName[ 8 ];
	int		CurScore;
	DWORD	Ping;
	int16	Team;
} playerlist_t;

playerlist_t PlayerInfo[ MAX_PLAYERS ];
BOOL SendShutdownPacket;

uint16 PlayerPort[ MAX_PLAYERS ];
char GamespyEchoText[ 128 ];
char GamespySecureText[ 128 ];
BOOL bGameSpy = FALSE;
BOOL ServerHeartbeat = FALSE;
BOOL PeerPeerHeartbeat = FALSE;
BOOL ForceHeartbeat = FALSE;
BOOL DoHeartbeat = FALSE;

BOOL TrackerOveride = FALSE;

char heartbeat_location[ 32 ];
char heartbeat_servername[ 32 ];
char heartbeat_serverspec[ 32 ];
char heartbeat_serverconnection[ 32 ];
char heartbeat_serveradmin[ 32 ];

CRITICAL_SECTION PlayerInfoKey;

BOOL WinsockActive = FALSE;
BOOL WSA_Active = FALSE;
SOCKET sockfd;

HANDLE	DPSendThreadEvent = NULL;
HANDLE	DPSendThreadKillEvent = NULL;
HANDLE	DPListenThreadEvent = NULL;
HANDLE	DPListenThreadKillEvent = NULL;

HANDLE	ghDPSendThread = NULL;
HANDLE	ghDPListenThread = NULL;

char *udp_header = "\377\377\377\377";
char *UDP_MSG_Ping = "ping\n";
char *UDP_MSG_BouncedPing = "gnip\n";
char *UDP_MSG_Status = "status\n";
char *UDP_MSG_Forsaken = "forsaken\n";

#define THIS_GAMENAME "Forsaken"

DWORD WINAPI DPThread(LPVOID p);
BOOL LoadDP(void);
void PostServerInfo( struct sockaddr_in *addr );
char pBuf[4096];
char *srv_info;
HANDLE SendMutex;

struct sockaddr_in HostIP, TrackerIP;
struct sockaddr_in PlayerIP[ MAX_PLAYERS ];

u_short host_port;
u_short tracker_port;

char host_ip[ 16 ];
char tracker_ip[ 16 ];
uint32 tracker_addr = 0;
char tracker_name[ 128 ];

DWORD	heartbeat_freq;
int	heartbeat_type;

static const BYTE GuidMap[] = { 3, 2, 1, 0, '-', 5, 4, '-', 7, 6, '-', 
                                8, 9, '-', 10, 11, 12, 13, 14, 15 }; 
static const char szDigits[] = "0123456789ABCDEF"; 

char Gamespy_Secret_Key[] = "znoJ6k";

BOOL StringFromGUID(LPCGUID lpguid, LPSTR lpsz) 
{ 
    int i; 
 
    const BYTE * pBytes = (const BYTE *) lpguid; 
 
    *lpsz++ = '{'; 
 
    for (i = 0; i < sizeof(GuidMap); i++) 
    { 
        if (GuidMap[i] == '-') 
        { 
            *lpsz++ = '-'; 
        } 
        else 
        { 
            *lpsz++ = szDigits[ (pBytes[GuidMap[i]] & 0xF0) >> 4 ]; 
            *lpsz++ = szDigits[ (pBytes[GuidMap[i]] & 0x0F) ]; 
        } 
    } 
    *lpsz++ = '}'; 
    *lpsz   = '\0'; 
 
    return TRUE; 
} 
void GrabMutex( HANDLE *mutex, char *name) {

	if (*mutex == NULL) {
		*mutex = CreateMutex (NULL, FALSE, name);
	}

	// Enter Mutex

	WaitForSingleObject( *mutex, INFINITE );
}

void UpdatePlayerInfo( void )
{
	int i;

	if ( !WSA_Active )
		return;

	EnterCriticalSection( &PlayerInfoKey );

	for ( i = 0; i < MAX_PLAYERS; i++ )
	{
		if ( ( i == WhoIAm ) || ( GameStatus[ i ] == STATUS_Normal ) || ( GameStatus[ i ] == STATUS_StartingMultiplayer ) )
		{
			PlayerInfo[ i ].CurScore = Ships[ i ].Kills;

			// copy names / pings here ( inside critical section ) in case of simultaneous access by seperate threads
			strcpy( PlayerInfo[ i ].PlayerName, Names[ i ] );
			PlayerInfo[ i ].Ping = PingTimes[ i ];
			PlayerInfo[ i ].Team = TeamNumber[ i ];
		}
	}

	LeaveCriticalSection( &PlayerInfoKey );
}

void RequestPings( void )
{
	int i;
	char buf[ 256 ];
	char *pCh;

	if ( !ghDPSendThread )	// if no send thread active, no point in trying to send pings
		return;
	
	GrabMutex(&SendMutex, NULL);

	for ( i = 0; i < MAX_PLAYERS; i++ )
	{
		if ( i != WhoIAm )
		{
			PlayerInfo[ i ].Ping = 999999;
			if ( GameStatus[ i ] == STATUS_Normal )
			{
				if ( !PlayerIP[ i ].sin_port )	// get IP address if neccesary
				{
					char add[ 16 ];

					memset(&PlayerIP[ i ], 0, sizeof(PlayerIP[ i ]));
					if ( GetIPFromDP( add, Ships[ i ].dcoID ) )
					{
						PlayerIP[ i ].sin_family = AF_INET;
						PlayerIP[ i ].sin_port = htons( DEF_PORT );
						PlayerIP[ i ].sin_addr.s_addr = inet_addr( add );
					}
				}

				if ( PlayerIP[ i ].sin_port )
				{
					pCh = buf;
					pCh += sprintf( pCh, "%s", udp_header );
					pCh += sprintf( pCh, UDP_MSG_Ping );
					pCh += sprintf( pCh, "\\player\\%d", i );
					pCh += sprintf( pCh, "\\time\\%d", timeGetTime() );

					*(++pCh) = 0;	// ensure NULL terminated

					sendto(sockfd, buf, pCh - buf, 0, 
					(struct sockaddr*)&PlayerIP[ i ], sizeof(struct sockaddr_in));
				}
			}
		}else
		{
			PlayerInfo[ i ].Ping = 0;
		}
	}

	ReleaseMutex(SendMutex);
}


void GetUpTime( char *str, DWORD dwTime )
{
   FILETIME FileTime;
   FILETIME sysTime;
   SYSTEMTIME _sysTime;
   // use of 64bit integers should be fine as long
   // as you compile with MS Devstudio.
   __int64 t1, t2;
   int uptime;

   if (dwTime &&
         DosDateTimeToFileTime((WORD)(dwTime & 0xffff),
         (WORD)((dwTime >> 16) & 0xffff), &FileTime)) {

      GetSystemTime(&_sysTime);
      if (SystemTimeToFileTime(&_sysTime, &sysTime)) {

         t1 = ((__int64)FileTime.dwLowDateTime +
            ((__int64)FileTime.dwHighDateTime << 32));
         t2 = ((__int64)sysTime.dwLowDateTime +
            ((__int64)sysTime.dwHighDateTime << 32));
         // t1 = start time, t2 = Current time
         // Get the difference then divide by 10,000,000 to get seconds
         // MS Devstudio will convert the 64bit operations to multiple
         // 32bit operations.
         uptime = (int)((t2 - t1)/10000000);
         // Add an uptime key to the srv_info in the form of
         // "hours:minutes:seconds"
         sprintf(str, "\\Uptime\\%dh:%2.2dm:%2.2ds",
            uptime / 3600, (uptime/60) % 60, uptime % 60);
      }
   }
}

void GetGameType( char *buf, LPDPSESSIONDESC2 pSD )
{
	// game type
	if ( pSD->dwUser3 & BombGameBit ) {
		strcpy( buf, "bomb tag" );
	} else if ( pSD->dwUser3 & CTFGameBit ) {
		strcpy( buf, "ctf" );
	} else if ( pSD->dwUser3 & FlagGameBit ) {
		strcpy( buf, "flag chase" );
	} else if ( pSD->dwUser3 & BountyGameBit ) {
		if ( pSD->dwUser3 & TeamGameBit )
		{
			strcpy( buf, "team bounty hunt" );
		}else
		{
			strcpy( buf, "bounty hunt" );
		}
	} else {
		if ( pSD->dwUser3 & TeamGameBit )
		{
			strcpy( buf, "team game" );
		}else
		{
			strcpy( buf, "free for all" );
		}
	}
}

void GetGameSubType( char *buf, LPDPSESSIONDESC2 pSD )
{
	// CTF sub type
	if ( pSD->dwUser3 & CTFGameBit )
	{
		switch ( CTF_Type_Decode( pSD->dwUser3 ) )
		{
		case CTF_STANDARD:
			strcpy( buf, LT_CTF_Normal/*"normal"*/ );
			break;
		case CTF_MUST_CARRY:
			strcpy( buf, LT_CTF_MustCarry/*"carry it back"*/ );
			break;
		case CTF_CAN_CARRY:
			strcpy( buf, LT_CTF_CanCarry/*"can pick up"*/ );
			break;
		case CTF_ONE_TOUCH:
			strcpy( buf, LT_CTF_OneTouch/*"1 touch return"*/ );
			break;
		case CTF_NO_RETURN:
			strcpy( buf, LT_CTF_NoReturn/*"can't pick up"*/ );
			break;
		default:
			strcpy( buf, LT_CTF_Standard/*"standard"*/ );
		}
	}
}

BOOL IsGameJoinable( LPDPSESSIONDESC2 pSD )
{
	return ( ( pSD->dwFlags & DPSESSION_JOINDISABLED ) ? FALSE : TRUE );

#if 0
	// if server game & host choosing, return FALSE
	if ( ( pSD->dwUser3 & ServerGameStateBits ) == SERVER_STATE_HostChoosing )
		return FALSE;
	
	switch( MyGameStatus )
	{
	case STATUS_StartingMultiplayer:
	case STATUS_Normal:
		return TRUE;
	default:
		return FALSE;
	}
#endif

}

BOOL ProcessGamespy( int type )
{
	LPDPSESSIONDESC2 pSD = NULL;
	DWORD dwSize;
	HRESULT hr;
	char *levelname;
	char buf[ 128 ];
	int16 i, j;
 	char *pCh;

	// first get the size for the session desc
    if ((hr = IDirectPlay3_GetSessionDesc(glpDP, NULL, &dwSize)) == DPERR_BUFFERTOOSMALL)
    {
		// allocate memory for it
        pSD = (LPDPSESSIONDESC2) malloc(dwSize);
        if (pSD)
        {
            // now get the session desc
            hr = IDirectPlay3_GetSessionDesc(glpDP, pSD, &dwSize);
        }
        else
        {
            hr = E_OUTOFMEMORY;
        }
    }

	if ( !pSD )
		return FALSE;

	if ( hr != DP_OK )
	{
	 	free( pSD );
		return FALSE;
	}

	GrabMutex(&SendMutex, NULL);

	srv_info = &pBuf[0];

	if ( type & HEARTBEAT_GAMESPY_Pulse )
	{
		srv_info += sprintf( srv_info, "\\heartbeat\\%d\\gamename\\forsaken", DEF_PORT );
		ReleaseMutex(SendMutex);
	 	free( pSD );
		return TRUE;	// no need to append query ID / packet num / security code
	}
	if ( ( type & HEARTBEAT_GAMESPY_Basic ) || ( type & HEARTBEAT_GAMESPY_Status ) )
	{
		srv_info += sprintf( srv_info, "\\gamename\\forsaken\\gamever\\%1.2f\\location\\%s", PATCH_VERSION, heartbeat_location );
	}
	if ( ( type & HEARTBEAT_GAMESPY_Info ) || ( type & HEARTBEAT_GAMESPY_Status ) )
	{
		// get map name
		levelname = strchr( pSD->lpszSessionNameA, '~' );
		if ( levelname )
		{
			*levelname++ = 0;
		}else
		{
			levelname = "unknown";
		}
		
		GetGameType( buf, pSD );
				
		srv_info += sprintf( srv_info, "\\hostname\\%s\\hostport\\%d\\mapname\\%s\\gametype\\%s\\numplayers\\%d\\maxplayers\\%d", 
			heartbeat_servername[ 0 ] ? heartbeat_servername : pSD->lpszSessionNameA,
			DEF_PORT,
			levelname,
			buf,
			IsServerGame ? ( pSD->dwCurrentPlayers - 1 ) : pSD->dwCurrentPlayers,
			IsServerGame ? ( pSD->dwMaxPlayers - 1 ) : pSD->dwMaxPlayers );

			srv_info += sprintf( srv_info, "\\gamemode\\%s", 
				( pSD->dwUser3 & ServerGameStateBits ) ? "server" : "peer-peer"  );

	}
	if ( ( type & HEARTBEAT_GAMESPY_Rules ) || ( type & HEARTBEAT_GAMESPY_Status ) )
	{
		// session GUID
		StringFromGUID(&pSD->guidInstance, buf );
		srv_info += sprintf(srv_info, "\\cl_session\\%s", buf );

		srv_info += sprintf(srv_info, "\\cl_TCP\\%s", IPAddressText );
		srv_info += sprintf(srv_info, "\\cl_AutoStart\\" );

		// application GUID
		//StringFromGUID(&pSD->guidApplication, buf );
		//srv_info += sprintf(srv_info, "\\cl_application\\%s", buf );

		// up time
		GetUpTime( buf, pSD->dwUser1 );
		srv_info += sprintf( srv_info, "%s", buf );

		srv_info += sprintf( srv_info, "\\joinable\\%d", IsGameJoinable( pSD ) );

		buf[ 0 ] = 0;
		GetGameSubType( buf, pSD );
		if ( buf[ 0 ] )
		{
			srv_info += sprintf( srv_info, "\\ctftype\\%s", buf );
		}

		if ( pSD->dwUser3 & TeamGameBit )
		{
			srv_info += sprintf( srv_info, "\\HarmTM\\%d",( pSD->dwUser3 & HarmTeamMatesBit ) );
		}

		srv_info += sprintf( srv_info, "\\shortpackets\\%d",( pSD->dwUser3 & ShortPacketsBit ) ? 1 : 0 );
		srv_info += sprintf( srv_info, "\\bigpackets\\%d",( pSD->dwUser3 & BigPacketsBit ) ? 1 : 0 );
		srv_info += sprintf( srv_info, "\\packetrate\\%d", PacketsSlider.value );
		srv_info += sprintf( srv_info, "\\maxkills\\%d", ( pSD->dwUser2 & MaxKillsBits ) >> MaxKills_Shift );
		srv_info += sprintf( srv_info, "\\timelimit\\%d", ( pSD->dwUser3 & GameTimeBit ) >> GameTimeBit_Shift );

		switch( ( pSD->dwUser3 & CollisionTypeBits ) >> Collision_Type_BitShift )
		{
		case COLPERS_Forsaken:
			pCh = "on";
			break;
		case COLPERS_Descent:
			pCh = "off";
			break;
		case COLPERS_Server:
			pCh = "server";
			break;

			srv_info += sprintf(srv_info, "\\lagtolerance\\%s", pCh );
		}

		srv_info += sprintf(srv_info, "\\brightbikes\\%d", ( pSD->dwUser3 & BrightShipsBit ) ? 1 : 0 );
		srv_info += sprintf(srv_info, "\\exhausts\\%d", ( pSD->dwUser3 & BikeExhaustBit ) ? 1 : 0 );
		srv_info += sprintf(srv_info, "\\serverspec\\%s", heartbeat_serverspec );
		srv_info += sprintf(srv_info, "\\serverconnection\\%s", heartbeat_serverconnection );
		srv_info += sprintf(srv_info, "\\serveradmin\\%s", heartbeat_serveradmin );
	}

	if ( ( type & HEARTBEAT_GAMESPY_Players ) || ( type & HEARTBEAT_GAMESPY_Status ) )
	{
		j = 0;
		for ( i = IsServerGame ? 1 : 0 ; i < MAX_PLAYERS; i++ )
		{
			if ( ( i == WhoIAm ) || ( ( GameStatus[ i ] != STATUS_Null ) && ( GameStatus[ i ] != STATUS_Left ) && ( GameStatus[ i ] != STATUS_LeftCrashed ) ) )
			{
				srv_info += sprintf( srv_info, "\\player_%d\\%s", j, PlayerInfo[ i ].PlayerName );
				srv_info += sprintf( srv_info, "\\frags_%d\\%d", j, PlayerInfo[ i ].CurScore );
				srv_info += sprintf( srv_info, "\\ping_%d\\%d", j, PlayerInfo[ i ].Ping );
				srv_info += sprintf( srv_info, "\\team_%d\\%d", j, PlayerInfo[ i ].Team );
				j++;
			}
		}
	}
	
	if ( type & HEARTBEAT_GAMESPY_Echo )
	{
		srv_info += sprintf( srv_info, "\\echo\\%s", GamespyEchoText );
	}

	if ( type & HEARTBEAT_GAMESPY_Secure )
	{
		char encoded_val[(GAMESPY_VALIDATE_SIZE * 4) / 3 + 1];

		gs_encrypt(GamespySecureText, GAMESPY_VALIDATE_SIZE, Gamespy_Secret_Key);
		gs_encode(GamespySecureText, GAMESPY_VALIDATE_SIZE, encoded_val);

		srv_info += sprintf( srv_info, "\\validate\\%s", encoded_val );
	}

	ReleaseMutex(SendMutex);
	free( pSD );

	return TRUE;
}

BOOL ProcessForsakenInfo( int type )
{
	static char strAppGuid[128], strInstGuid[128];
	char	 *pChar;
	char buf[ 128 ];
	FILE *f = NULL;
	int i;
	LPDPSESSIONDESC2 pSD = NULL;
	DWORD dwSize;
	HRESULT hr;

	// first get the size for the session desc
    if ((hr = IDirectPlay3_GetSessionDesc(glpDP, NULL, &dwSize)) == DPERR_BUFFERTOOSMALL)
    {
		// allocate memory for it
        pSD = (LPDPSESSIONDESC2) malloc(dwSize);
        if (pSD)
        {
            // now get the session desc
            hr = IDirectPlay3_GetSessionDesc(glpDP, pSD, &dwSize);
        }
        else
        {
            hr = E_OUTOFMEMORY;
        }
    }

	if( !pSD )
		return FALSE;

	if ( hr != DP_OK )
	{
		free( pSD );
		return FALSE;
	}

	GrabMutex(&SendMutex, NULL);

	srv_info = &pBuf[0];

	strcpy ( srv_info, udp_header );
	srv_info += strlen( udp_header );

	if ( type & HEARTBEAT_Raw )
	{
		srv_info += sprintf( srv_info, "heartbeat\n" );
		ReleaseMutex(SendMutex);
		free( pSD );
		return TRUE;
	}							   	  

	srv_info += sprintf( srv_info, "forsaken\n" );

	StringFromGUID(&pSD->guidApplication, strAppGuid);
	StringFromGUID(&pSD->guidInstance, strInstGuid);

	srv_info += sprintf(srv_info, "\\AppGuid\\%s", strAppGuid);
	srv_info += sprintf(srv_info, "\\InstGuid\\%s", strInstGuid);

	if ( !type || ( type & HEARTBEAT_BasicInfo ) )
	{
		// session name
		pChar = srv_info + sprintf( srv_info, "\\session\\%s", pSD->lpszSessionNameA );
		srv_info = strchr( srv_info, '~' );
		if ( !srv_info )
		{
			srv_info = pChar;
		}
					    
		/*
		// session creation time / date
		srv_info += sprintf( srv_info, "\\created\\%x", pSD->dwUser1 );
		*/
		// session up time
		GetUpTime( buf, pSD->dwUser1 );
		srv_info += sprintf( srv_info, "%s", buf );

		strncpy( buf, pSD->lpszSessionNameA, 128 );
		buf[ 127 ] = 0;
		pChar = strchr( buf, '~' );
		if ( pChar )
		{
			srv_info += sprintf( srv_info, "\\level\\%s", ++pChar );
		}

		// num players
		srv_info += sprintf( srv_info, "\\curplayers\\%d", IsServerGame ? ( pSD->dwCurrentPlayers - 1 ) : pSD->dwCurrentPlayers );

		// max players
		if ( ( ( pSD->dwUser3 & ServerGameStateBits ) == SERVER_STATE_NeedHost ) ||
			( ( pSD->dwUser3 & ServerGameStateBits ) == SERVER_STATE_HostChoosing ) )
		{
			//server waiting for pseudohost )
			srv_info += sprintf( srv_info, "\\maxplayers\\%d", MaxServerPlayersSlider.value );
		}else
		{
			srv_info += sprintf( srv_info, "\\maxplayers\\%d", IsServerGame ? ( pSD->dwMaxPlayers - 1 ) : pSD->dwMaxPlayers );
		}

		// server game?
		srv_info += sprintf( srv_info, "\\server\\%d", 
			( ( pSD->dwUser3 & ServerGameStateBits ) > 0 ) );
	}

	if ( !type || ( type & HEARTBEAT_GameType ) )
	{
		GetGameType( buf, pSD );
		
		srv_info += sprintf( srv_info, "\\game\\%s", buf );

		buf[ 0 ] = 0;
		GetGameSubType( buf, pSD );
		if ( buf[ 0 ] )
		{
			srv_info += sprintf( srv_info, "\\ctftype\\%s", buf );
		}
		
		// harm team mates?
		if ( pSD->dwUser3 & TeamGameBit )
		{
			srv_info += sprintf( srv_info, "\\HarmTM\\%d",( pSD->dwUser3 & HarmTeamMatesBit ) );
		}
	}

	if ( !type || ( type & HEARTBEAT_PacketInfo ) )
	{																  
		// short packets
		srv_info += sprintf( srv_info, "\\shortpackets\\%d",( pSD->dwUser3 & ShortPacketsBit ) ? 1 : 0 );

		// group packets
		srv_info += sprintf( srv_info, "\\bigpackets\\%d",( pSD->dwUser3 & BigPacketsBit ) ? 1 : 0 );

		// packet rate
		srv_info += sprintf( srv_info, "\\packetrate\\%d", PacketsSlider.value );
	}

	if ( !type || ( type & HEARTBEAT_KillsInfo ) )
	{
		// max kills
		srv_info += sprintf( srv_info, "\\maxkills\\%d", ( pSD->dwUser2 & MaxKillsBits ) >> MaxKills_Shift );

		// current top
		srv_info += sprintf( srv_info, "\\topkills\\%d", ( ( pSD->dwUser2 & CurrentMaxKillsBits ) >> CurrentMaxKills_Shift ) );
	}

	if ( !type || ( type & HEARTBEAT_TimeInfo ) )
	{	 
		// time limit
		srv_info += sprintf( srv_info, "\\timelimit\\%d", ( pSD->dwUser3 & GameTimeBit ) >> GameTimeBit_Shift );

		// current top
		srv_info += sprintf( srv_info, "\\elapsedtime\\%d", 
			( ( pSD->dwUser3 & CurrentGameTimeBits ) >> CurrentGameTime_Shift ) +
			( ( ( pSD->dwUser3 & GameTimeBit ) >> GameTimeBit_Shift == ( pSD->dwUser3 & CurrentGameTimeBits ) >> CurrentGameTime_Shift ) ? 0 : 1 ) );
	}

	if ( !type || ( type & HEARTBEAT_ValidPickups ) )
	{
		uint32 pickupinfo[ MAX_PICKUPFLAGS ];

		PackPickupInfo( pickupinfo );
		srv_info += sprintf(srv_info, "\\validpickups\\" );

		for ( i = 0; i < MAX_PICKUPFLAGS; i++ )
		{
			srv_info += sprintf(srv_info, "%x ", pickupinfo[ i ] );
		}
	}										 

	if ( !type || ( type & HEARTBEAT_ExtraInfo ) )
	{
		switch( ( pSD->dwUser3 & CollisionTypeBits ) >> Collision_Type_BitShift )
		{
		case COLPERS_Forsaken:
			pChar = "on";
			break;
		case COLPERS_Descent:
			pChar = "off";
			break;
		case COLPERS_Server:
			pChar = "server";
			break;

			srv_info += sprintf(srv_info, "\\lagtolerance\\%s ", pChar );
		}

		srv_info += sprintf(srv_info, "\\brightbikes\\%d ", ( pSD->dwUser3 & BrightShipsBit ) ? 1 : 0 );
		srv_info += sprintf(srv_info, "\\exhausts\\%d ", ( pSD->dwUser3 & BikeExhaustBit ) ? 1 : 0 );
	}

	if ( !type || ( type & HEARTBEAT_PlayersList ) )
	{
		srv_info += sprintf( srv_info, "\n" );
		
		EnterCriticalSection( &PlayerInfoKey );
	
		for ( i = 0; i < MAX_PLAYERS; i++ )
		{
			if ( ( i == WhoIAm ) || ( GameStatus[ i ] == STATUS_Normal ) || ( GameStatus[ i ] == STATUS_StartingMultiplayer ) )
			{
				srv_info += sprintf(srv_info, "\"%s\" %d %d\n", PlayerInfo[ i ].PlayerName, PlayerInfo[ i ].CurScore, PlayerInfo[ i ].Ping);
			}
		}
		
		LeaveCriticalSection( &PlayerInfoKey );
	}

	ReleaseMutex(SendMutex);
   	free( pSD );
	return TRUE;
}

char *GAMESPY_KEY_Basic = "basic";
char *GAMESPY_KEY_Info = "info";
char *GAMESPY_KEY_Rules = "rules";
char *GAMESPY_KEY_Players = "players";
char *GAMESPY_KEY_Status = "status";
char *GAMESPY_KEY_Echo = "echo";
char *GAMESPY_KEY_Secure = "secure";

void ProcessGamespyKey( char *key, char *value, int *type )
{
	if ( !_strnicmp( key, GAMESPY_KEY_Basic, sizeof( GAMESPY_KEY_Basic ) ) )
	{
		*type |= HEARTBEAT_GAMESPY_Basic;
	}else if ( !_strnicmp( key, GAMESPY_KEY_Info, sizeof( GAMESPY_KEY_Info ) ) )
	{
		*type |= HEARTBEAT_GAMESPY_Info;
	}else if ( !_strnicmp( key, GAMESPY_KEY_Rules, sizeof( GAMESPY_KEY_Rules ) ) )
	{
		*type |= HEARTBEAT_GAMESPY_Rules;
	}else if ( !_strnicmp( key, GAMESPY_KEY_Players, sizeof( GAMESPY_KEY_Players ) ) )
	{
		*type |= HEARTBEAT_GAMESPY_Players;
	}else if ( !_strnicmp( key, GAMESPY_KEY_Status, sizeof( GAMESPY_KEY_Status ) ) )
	{
		*type |= HEARTBEAT_GAMESPY_Status;
	}else if ( !_strnicmp( key, GAMESPY_KEY_Echo, sizeof( GAMESPY_KEY_Echo ) ) )
	{
		char *pCh;
		
		*type |= HEARTBEAT_GAMESPY_Echo;
		strncpy( GamespyEchoText, value, sizeof( GamespyEchoText ) );
		pCh = strchr( GamespyEchoText, '\\' );
		if ( pCh )
		{
			*pCh = 0;
		}
	}
	else if ( !_strnicmp( key, GAMESPY_KEY_Secure, sizeof( GAMESPY_KEY_Secure ) ) )
	{
		*type |= HEARTBEAT_GAMESPY_Secure;
		strncpy( GamespySecureText, value, sizeof( GamespySecureText ) );
	}
}

void GamespyParsePacket( char *packet )
{
 	char *key, *value, *str;
	int type; 

	type = 0;
	str = packet;

	do
	{
		key = strchr(str, '\\' );
		if ( key )
		{
			value = strchr( ++key, '\\' );
			{
				if ( value )
				{
					ProcessGamespyKey( key, ++value, &type );
				}
			}
		}
		str = value;
	}while( key && value );

	if ( type )
	{
		ProcessGamespy( type );
	}
}


DWORD WINAPI ListenThread(LPVOID p) {

	struct sockaddr_in from;
	int len, from_len, SelectVal;
	fd_set	in;
	struct timeval tv;
	static char tmpbuf[ 4096 ];
	char *msgptr;
#ifdef UDP_PINGS
	char *tempptr;
#endif
#ifdef DPTEST	
	char buf[ 4096 ];
#endif
	uint16 status_type;

	HANDLE		eventHandles[2];

	eventHandles[0] = DPListenThreadEvent;
	eventHandles[1] = DPListenThreadKillEvent;

	while (WaitForMultipleObjects(2, eventHandles, FALSE, INFINITE) == WAIT_OBJECT_0)	// while just one event is TRUE
	{
		tv.tv_sec = 1;
		tv.tv_usec = 0;

		FD_ZERO (&in);
		FD_SET (sockfd, &in);
		SelectVal = select ( sockfd+1, &in, 0, 0, &tv );
		
		from_len = sizeof(struct sockaddr_in);

		if ( SelectVal < 0 )
		{
			break;
		} else if ( SelectVal != 0 )
		{
			len = recvfrom ( sockfd, &tmpbuf[0], sizeof(tmpbuf), 0, 
				(struct sockaddr *) &from, &from_len );
			if (len == SOCKET_ERROR && WSAGetLastError() != WSAEMSGSIZE)
				break;

			if ( bGameSpy )
			{
				if ( len )
				{
					GamespyParsePacket( tmpbuf );
					PostGamespyServerInfo( &from );
				}
				continue;
			}
			
			if ( len < ( sizeof( udp_header ) - 1 ) )
				continue;	// message is not even big enough for header

#ifdef DPTEST
			sprintf( buf, "recieving packet" );
			AddMessageToQue ( buf );
#endif

			if ( !memcmp( tmpbuf, udp_header, strlen( udp_header ) ) )	// if we have correct header...
			{
				msgptr = tmpbuf + strlen( udp_header );
#ifdef UDP_PINGS
				// ping message?
			   if ( !_strnicmp( msgptr, UDP_MSG_Ping, strlen( UDP_MSG_Ping ) ) )
			   {
				   // replace message with 'bounced' version
				   memcpy( (void *)msgptr, (void *)UDP_MSG_BouncedPing, strlen( UDP_MSG_Ping ) );

				   // bounce back message
				   GrabMutex( &SendMutex, NULL );

				   sendto(sockfd, tmpbuf, len, 0, 
						(struct sockaddr*)&from, sizeof(struct sockaddr_in));

				   ReleaseMutex( SendMutex );

			   // returned ping request?
			   }else if ( !_strnicmp( msgptr, UDP_MSG_BouncedPing, strlen( UDP_MSG_BouncedPing ) ) )
			   {
				   DWORD senttime;
				   BYTE player;

				   msgptr += strlen( UDP_MSG_BouncedPing );

				   tempptr = strstr( msgptr, "player\\" );
				   if ( tempptr )
				   {
					   if ( sscanf( tempptr, "player\\%d\\", &player ) != 1 )
					   {
						   player = WhoIAm;
					   }
				   }

				   tempptr = strstr( msgptr, "time\\" );
				   if ( tempptr )
				   {
					   if ( sscanf( tempptr, "time\\%d\\", &senttime ) != 1 )
					   {
						   senttime = 0;
					   }
				   }

				   if ( ( player != WhoIAm ) && senttime )
				   {

					   EnterCriticalSection( &PlayerInfoKey );
					   PlayerInfo[ player ].Ping = timeGetTime() - senttime;
					   if ( PlayerInfo[ player ].Ping > 999999 )
						   PlayerInfo[ player ].Ping = 999999;
					   LeaveCriticalSection( &PlayerInfoKey );
#ifdef DPTEST
					   sprintf( buf, "ping of %d recieved for player %d ( %s )", PlayerInfo[ player ].Ping, player, Names[ player ] );
					   AddMessageToQue ( buf );
#endif
				   }
			   // status request?
			   }else
#endif
			   if ( !_strnicmp( msgptr, UDP_MSG_Status, strlen( UDP_MSG_Status ) ) )
			   {
				  msgptr += strlen( UDP_MSG_Status );
				  
				  if( !(*msgptr) )	// added for Kali
				  {
					    ProcessForsakenInfo( 0 );
#ifdef DPTEST
						sprintf( buf, "sending status msg type 0\n");
					    AddMessageToQue ( buf );
#endif
						PostServerInfo( &from );
				  }else
				  {
					  if ( sscanf( msgptr, "%x", &status_type ) == 1 )
					  {
							ProcessForsakenInfo( status_type );
#ifdef DPTEST
							sprintf( buf, "sending status msg type %d\n", status_type);
						    AddMessageToQue ( buf );
#endif					
							PostServerInfo( &from );
					  }
				  }
#ifdef DPTEST
			   // game info?
			   }else if ( !_strnicmp( msgptr, UDP_MSG_Forsaken, strlen( UDP_MSG_Forsaken ) ) )
			   {
				  msgptr += strlen( UDP_MSG_Forsaken );
				  AddMessageToQue( "game info recieved" );
				  DebugPrintf( "\nrecieving: %s\n", msgptr );
			   }else
			   {
					AddMessageToQue( msgptr );
			   }
#else
			   }
#endif
			}
		}

	}
	
	DebugPrintf("listen thread exited OK\n");
	ExitThread(0);

	return 0;
}

void BroadcastUDP()
{
	int i;
	
	GrabMutex(&SendMutex, NULL);

	for ( i = 0; i < MAX_PLAYERS; i++ )
	{
		if ( ( i != WhoIAm ) && ( GameStatus[ i ] == STATUS_Normal ) )
		{
			if (srv_info != &pBuf[0]) 
			{
				*(++srv_info) = 0;	// ensure NULL terminated
				sendto(sockfd, (char *)&pBuf[0], srv_info - &pBuf[0], 0, 
				(struct sockaddr*)&PlayerIP[ i ], sizeof(struct sockaddr_in));
			}
		}
	}

	ReleaseMutex(SendMutex);
}

void PostServerInfo( struct sockaddr_in *addr ) 
{

	GrabMutex(&SendMutex, NULL);

	if ( !srv_info || ( srv_info == pBuf ) )
		return;

	//DebugPrintf("\nsending: %s\n", pBuf);

	*(++srv_info) = 0;	// ensure NULL terminated

	sendto(sockfd, (char *)&pBuf[0], srv_info - &pBuf[0], 0, 
		(struct sockaddr*)addr, sizeof(struct sockaddr_in));

	ReleaseMutex(SendMutex);
}

#define GAMESPY_MAX_PACKET_SIZE 1000 
#define GAMESPY_EXTRAS_SIZE 32

void PostGamespyServerInfo( struct sockaddr_in *addr ) 
{
	char *start, *mid, *end, *pCh;
	char packet[ GAMESPY_MAX_PACKET_SIZE + GAMESPY_EXTRAS_SIZE ];	// extra is for queryid key / value
	DWORD datasize;
	BOOL done;
	static uint16 qid = 1;
	char buf[ GAMESPY_EXTRAS_SIZE ];
	uint16 packet_num = 0;
	
	GrabMutex(&SendMutex, NULL);

	if ( !srv_info || ( srv_info == pBuf ) )
		return;

	*(++srv_info) = 0;	// ensure NULL terminated

	pCh = pBuf;
	packet[ 0 ] = 0;
	done = FALSE;
	do
	{
		start = NULL; mid = NULL; end = NULL;
		start = strchr( pCh, '\\' );
		if ( start )
			mid = strchr( ( start + 1 ), '\\' );
		if ( mid )
			end = strchr( ( mid + 1 ), '\\' );

		if ( !end )
		{
			end = pCh + strlen( pCh );
			done = TRUE;
		}

		if ( start && mid && end )
		{
			datasize = end - start;

			if ( strlen( packet ) + datasize > GAMESPY_MAX_PACKET_SIZE )
			{
				// append qid...
				sprintf( buf, "\\queryid\\%d.%d", qid, packet_num++ );
				strcat( packet, buf );
				
				// send existing packet
				sendto(sockfd, packet, strlen( packet ), 0, (struct sockaddr*)addr, sizeof(struct sockaddr_in));

				// clear packet
				packet[ 0 ] = 0;
			}

			strncat( packet, start, GAMESPY_MAX_PACKET_SIZE < ( end - start ) ? GAMESPY_MAX_PACKET_SIZE : ( end - start ) );
		}

		pCh = end;

	}while ( !done );

	// append qid...
	sprintf( buf, "\\queryid\\%d.%d", qid, packet_num++ );
   	strcat( packet, buf );

	// append final key...
	sprintf( buf, "\\final\\" );
   	strcat( packet, buf );

	sendto(sockfd, packet, strlen( packet ), 0, (struct sockaddr*)addr, sizeof(struct sockaddr_in));

	
	qid++;
	if ( qid > 100 )
		qid = 0;

	ReleaseMutex(SendMutex);
}

BOOL ConnectToWinsock(void)
{
	int err;
	WSADATA wsaData;
	uint32 addr;
	struct hostent *hp;
	char FAR * FAR *add; 

	memset(&HostIP, 0, sizeof(HostIP));
	memset(&TrackerIP, 0, sizeof(TrackerIP));

	
	// setup HostIP
	HostIP.sin_family = AF_INET;
	HostIP.sin_port = htons(host_port);
	HostIP.sin_addr.s_addr = inet_addr( IPAddressText );

	// setup TrackerIP	( address to send UDP packets to )
	TrackerIP.sin_family = AF_INET;
	TrackerIP.sin_port = htons (tracker_port);

	if ( !tracker_addr )
	{
		addr = 0;
		if ( tracker_name[ 0 ] )
		{
			hp = gethostbyname ( tracker_name ); 
			if ( hp )
			{
				add = hp->h_addr_list;
				if ( *add )
				{
					addr = *(uint32 *) *add;
				}
			}
		}

		if ( !addr )
		{
			addr = inet_addr( tracker_ip );
		}

		if ( addr == INADDR_NONE )
			return FALSE;

		tracker_addr = addr;
	}else
	{
		addr = tracker_addr;
	}

	TrackerIP.sin_addr.s_addr = addr;
	
/*
	// setup HostIP
	HostIP.sin_family = AF_INET;
	HostIP.sin_port = htons(DEF_PORT);
	HostIP.sin_addr.s_addr = inet_addr("100.106.0.237");

	// setup TrackerIP	( address to send UDP packets to )
	TrackerIP.sin_family = AF_INET;
	TrackerIP.sin_port = htons (MASTER_PORT);
	TrackerIP.sin_addr.s_addr = inet_addr("100.106.0.236");
*/	
	// Let's see if winsock is running
	err = WSAStartup( 0x0101, &wsaData );
	if (err !=0 ) {
		Msg ( "process: No winsock!\n" );
		return FALSE;
	}

	if ( LOBYTE (wsaData.wVersion) != 1 || HIBYTE (wsaData.wVersion) != 1 ) {
		Msg ( "process: Wrong winsock version!\n" );
		WSACleanup();
		return FALSE;
	}

	if ( ( sockfd = socket ( AF_INET, SOCK_DGRAM, 0 ) ) < 0 ) {
		Msg ( "process: Can't open datagram socket!\n" );
		WSACleanup();
		return FALSE;
	}

	if ( bind(sockfd, (struct sockaddr *) &HostIP, sizeof(HostIP) ) < 0 ) {
		Msg( "process: can't bind local address!\n" );
		WSACleanup();
		return FALSE;
	}

	return TRUE;
}

DWORD WINAPI DPThread(LPVOID p)
{
	HANDLE		eventHandles[2];

	eventHandles[0] = DPSendThreadEvent;
	eventHandles[1] = DPSendThreadKillEvent;

	while (WaitForMultipleObjects(2, eventHandles, FALSE, INFINITE) == WAIT_OBJECT_0)	// while just one event is TRUE
	{
		if ( IsHost )
		{							
			if ( bGameSpy )
			{
				if ( ProcessGamespy( HEARTBEAT_GAMESPY_Pulse ) )
				{
					PostServerInfo( &TrackerIP );	
				}
			}else
			{
				if ( ProcessForsakenInfo( heartbeat_type ) )
				{
					PostServerInfo( &TrackerIP );	
				}
			}
		}

		WaitForSingleObject( DPSendThreadKillEvent, heartbeat_freq );
	}

	DebugPrintf("send thread exited OK\n");
	ExitThread(0);

	return 0;
}

void DPStopThread(void) 
{
	TrackerOveride = FALSE;
	tracker_addr = 0;
	
	if ( !WSA_Active )
		return;

	// send one final shutdown packet if required...
	if ( SendShutdownPacket )
	{
		GrabMutex(&SendMutex, NULL);

		srv_info = &pBuf[0];

		strcpy ( srv_info, udp_header );
		srv_info += strlen( udp_header );

		srv_info += sprintf( srv_info, "shutdown\n" );
		ReleaseMutex(SendMutex);

		PostServerInfo( &TrackerIP );
	}
	
	// kill off all threads...
	
	if ( ghDPSendThread )
	{
		// wake up thread and wait for it to quit
		ResetEvent( DPSendThreadEvent );
		SetEvent( DPSendThreadKillEvent );
		WaitForSingleObject( ghDPSendThread , INFINITE);
		CloseHandle( ghDPSendThread );
		ghDPSendThread = NULL;
	}

	if ( ghDPListenThread )
	{
		// wake up thread and wait for it to quit
		ResetEvent( DPListenThreadEvent );
		SetEvent( DPListenThreadKillEvent );
		WaitForSingleObject( ghDPListenThread , INFINITE);
		CloseHandle( ghDPListenThread );
		ghDPListenThread = NULL;
	}

	WSACleanup();
	WSA_Active = FALSE;

	if ( SendMutex ) 
		CloseHandle( SendMutex );

	if ( DPSendThreadEvent )
	{
		CloseHandle( DPSendThreadEvent );
		DPSendThreadEvent = NULL;
	}
	if ( DPSendThreadKillEvent )
	{
		CloseHandle( DPSendThreadKillEvent );
		DPSendThreadKillEvent = NULL;
	}
	if ( DPListenThreadEvent )
	{
		CloseHandle( DPListenThreadEvent );
		DPListenThreadEvent = NULL;
	}
	if ( DPSendThreadKillEvent )
	{
		CloseHandle( DPSendThreadKillEvent );
		DPSendThreadKillEvent = NULL;
	}

}

BOOL DPStartThread( void ) {

	DWORD tID;

	if ( !TrackerOveride )
	{
		if ( !DoHeartbeat )
			return TRUE;

		// if no heartbeat info...
		if ( IsServerGame && !ServerHeartbeat )
			return TRUE;

		if ( !IsServerGame && !PeerPeerHeartbeat )
			return TRUE;
		
		if ( !ForceHeartbeat )
		{
			if ( IsLobbyLaunched )
			{
			   	HRESULT hr;
				DWORD dwDataSize;
				LPDPLCONNECTION lpdplconnection;

				hr =  IDirectPlayLobby_GetConnectionSettings( lpDPlayLobby, 0, NULL, &dwDataSize );
				if ( hr != DPERR_BUFFERTOOSMALL )
					return TRUE;

				lpdplconnection = ( LPDPLCONNECTION )malloc( dwDataSize );
				if ( !lpdplconnection )
					return TRUE;

				hr =  IDirectPlayLobby_GetConnectionSettings( lpDPlayLobby, 0, ( void *)lpdplconnection, &dwDataSize );
				if ( hr != DP_OK )
					return TRUE;

				if ( memcmp( &lpdplconnection->guidSP, &DPSPGUID_TCPIP , sizeof(GUID) ) != 0 )
					return TRUE;
			}else
			{
			  if ( memcmp( &ServiceProvidersGuids[ServiceProvidersList.selected_item], &DPSPGUID_TCPIP , sizeof(GUID) ) != 0 )
				  return TRUE;

			}
		}
	}

	if (ConnectToWinsock() == FALSE) 
	{
		//Msg( "Error Loading Winsock" );
		DebugPrintf( "Error Loading Winsock" );
		WSA_Active = FALSE;
		return FALSE;
	}

	WSA_Active = TRUE;

	// create all events for send / listen threads....
	DPSendThreadEvent = CreateEvent			(	NULL,		// no security
												TRUE,		// manual reset
												FALSE,		// initial event reset
												NULL);		// no name
	DPSendThreadKillEvent = CreateEvent		(	NULL,		// no security
												TRUE,		// manual reset
												FALSE,		// initial event reset
												NULL);		// no name
	DPListenThreadEvent = CreateEvent		(	NULL,		// no security
												TRUE,		// manual reset
												FALSE,		// initial event reset
												NULL);		// no name
	DPListenThreadKillEvent = CreateEvent	(	NULL,		// no security
												TRUE,		// manual reset
												FALSE,		// initial event reset
												NULL);		// no name

	SendMutex = NULL;
	pBuf[0] = 0;
	memset( PlayerInfo, 0, sizeof( PlayerInfo ) );
	InitializeCriticalSection( &PlayerInfoKey );

	memset( PingTimes, 0, sizeof ( PingTimes ) ); 

	ghDPSendThread = NULL;
	ghDPListenThread = NULL;

	if ( heartbeat_freq )
	{
		SetEvent( DPSendThreadEvent );

		ghDPSendThread = CreateThread( NULL, 16384, DPThread, NULL, 0, &tID );

		if ( !ghDPSendThread )
		{
			Msg( "Error Creating UDP send thread" );
			DPStopThread();
			return FALSE;
		}

	}

	SetEvent( DPListenThreadEvent );

	ghDPListenThread = CreateThread( NULL, 8192, ListenThread, NULL, 0, &tID);

	if ( !ghDPListenThread )
	{
		Msg( "Error Creating UDP listen thread" );
		DPStopThread();
		return FALSE;
	}

	return TRUE;
}

typedef BOOL (*ReadHeartbeatInfo)( FILE *, char * );

typedef struct {
	char *keyword;
	ReadHeartbeatInfo handle;
} READHEARTBEATINFOTABLE;

BOOL set_host_port( FILE *f, char *last_token )
{
	if ( fscanf( f, " %d", &host_port ) == 1 )
	{
		fscanf( f, " %80s", last_token );
		return TRUE;
	}
	else
		return FALSE;
}
   
BOOL set_host_ip( FILE *f, char *last_token )
{
	if ( fscanf( f, " %15s", host_ip ) == 1 )
	{
		fscanf( f, " %80s", last_token );
		return TRUE;
	}
	else
		return FALSE;
}			

BOOL set_tracker_port( FILE *f, char *last_token )
{
	if ( fscanf( f, " %d", &tracker_port ) == 1 )
	{
		fscanf( f, " %80s", last_token );
		return TRUE;
	}
	else
		return FALSE;
}

BOOL set_tracker_ip( FILE *f, char *last_token )
{
	if ( fscanf( f, " %15s", tracker_ip ) == 1 )
	{
		fscanf( f, " %80s", last_token );
		return TRUE;
	}
	else
		return FALSE;
}

BOOL set_tracker_name( FILE *f, char *last_token )
{
	if ( fscanf( f, " %127s", tracker_name ) == 1 )
	{
		fscanf( f, " %80s", last_token );
		return TRUE;
	}
	else
		return FALSE;
}

BOOL set_heartbeat_freq( FILE *f, char *last_token )
{
	if ( fscanf( f, " %d", &heartbeat_freq ) == 1 )
	{
		fscanf( f, " %80s", last_token );
		/*
		if ( heartbeat_freq < 5000 )
		{
			heartbeat_freq = 5000;
		}
		*/
		return TRUE;
	}
	else
		return FALSE;
}

BOOL set_heartbeat_type( FILE *f, char *last_token )
{
	if ( fscanf( f, " %d", &heartbeat_type ) == 1 )
	{
		fscanf( f, " %80s", last_token );
		return TRUE;
	}
	else
		return FALSE;
}

BOOL set_shutdown_flag( FILE *f, char *last_token )
{
	SendShutdownPacket = TRUE;
	fscanf( f, " %80s", last_token );
	return TRUE;
}

BOOL set_gamespy_flag( FILE *f, char *last_token )
{
	bGameSpy = TRUE;
	fscanf( f, " %80s", last_token );
	return TRUE;
}

BOOL set_location( FILE *f, char *last_token )
{
	if ( fscanf( f, " %32[^\n]", &heartbeat_location ) == 1 )
	{
		fscanf( f, " %80s", last_token );
		return TRUE;
	}
	else	 
		return FALSE;
}

BOOL set_servername( FILE *f, char *last_token )
{
	if ( fscanf( f, " %32[^\n]", &heartbeat_servername ) == 1 )
	{
		fscanf( f, " %80s", last_token );
		return TRUE;
	}
	else
		return FALSE;
}

BOOL set_serverspec( FILE *f, char *last_token )
{
	if ( fscanf( f, " %32s[^\n]", &heartbeat_serverspec ) == 1 )
	{
		fscanf( f, " %80s", last_token );
		return TRUE;
	}
	else
		return FALSE;
}

BOOL set_serverconnection( FILE *f, char *last_token )
{
	if ( fscanf( f, " %32s[^\n]", &heartbeat_serverconnection ) == 1 )
	{
		fscanf( f, " %80s", last_token );
		return TRUE;
	}
	else
		return FALSE;
}

BOOL set_serveradmin( FILE *f, char *last_token )
{
	if ( fscanf( f, " %32s[^\n]", &heartbeat_serveradmin ) == 1 )
	{
		fscanf( f, " %80s", last_token );
		return TRUE;
	}
	else
		return FALSE;
}

BOOL read_heartbeat_info( char *file )
{
	
	static READHEARTBEATINFOTABLE jumptab[] = {
		//{ "host_port",		set_host_port 			},
		{ "host_ip",		set_host_ip				},
		{ "tracker_port",	set_tracker_port		},
		{ "tracker_ip",		set_tracker_ip			},
		{ "tracker_name",	set_tracker_name		},
		{ "heartbeat_freq",	set_heartbeat_freq		},
		{ "heartbeat_type",	set_heartbeat_type		},
		{ "send_shutdown",	set_shutdown_flag		},
		{ "gamespy",		set_gamespy_flag		},
		{ "location",		set_location			},
		{ "servername",		set_servername			},
		{ "serverspec",		set_serverspec			},
		{ "serverconnection",	set_serverconnection	},
		{ "serveradmin",	set_serveradmin	},
		{ NULL,				NULL		  			}
	};
	FILE *f;
	char token[80];
	int j;

	if ( !file || !file[ 0 ] )
		return FALSE;	// no heartbeat file specified

	host_ip[ 0 ] = 0;
	host_port = DEF_PORT;
	tracker_ip[ 0 ] = 0;
	tracker_name[ 0 ] = 0;
	tracker_port = MASTER_PORT;

	heartbeat_freq = 0;
	heartbeat_type = HEARTBEAT_Raw;
	SendShutdownPacket = FALSE;

	heartbeat_location[ 0 ] = 0;
	heartbeat_servername[ 0 ] = 0;
	heartbeat_serverspec[ 0 ] = 0;
	heartbeat_serverconnection[ 0 ] = 0;
	heartbeat_serveradmin[ 0 ] = 0;

	bGameSpy = FALSE;

	f = fopen( file, "r" );
	if ( !f )
	{
		return FALSE;
	}

	if ( fscanf( f, " %80s", token ) == 1 )
	{
		do
		{
			for ( j = 0; jumptab[ j ].keyword; j++ )
			{
				if ( !_stricmp( token, jumptab[ j ].keyword ) )
					break;
			}
			if ( jumptab[ j ].handle )
			{
				(jumptab[ j ].handle)( f, token );
			}
			else
				fscanf( f, " %80s", token );
		} while ( !feof( f ) );
	}
	fclose( f );

	return TRUE;
}

#define TRACKERFOLDER				"TRACKER"
#define TRACKERFILE_EXTENSION		".trk"
#define TRACKERFILE_SEARCHPATH		TRACKERFOLDER"\\*"TRACKERFILE_EXTENSION

BOOL GetTrackerFiles( void )
{
	HANDLE h;
	WIN32_FIND_DATA TrackerFiles;
	char *tracker;
	char	TrackerList[256][256];
	int Count;
	int i;

	h = FindFirstFile( TRACKERFILE_SEARCHPATH,	// pointer to name of file to search for  
						(LPWIN32_FIND_DATA) &TrackerFiles );	// pointer to returned information 

	if ( h == INVALID_HANDLE_VALUE )
	{
		return FALSE;
	}

	Count = 0;
	do{
		// Get rid of the .trk
		tracker = strstr( &TrackerFiles.cFileName[0], "." );
		if( tracker )
			_strlwr( tracker );
		tracker = strstr( &TrackerFiles.cFileName[0], TRACKERFILE_EXTENSION );
		if ( tracker )
			*tracker = 0;
		strcpy( &TrackerList[Count][0] , &TrackerFiles.cFileName[0] );
		Count++;

	}while(	FindNextFile( h , (LPWIN32_FIND_DATA) &TrackerFiles ) );

	if ( !Count )
	{
		PrintErrorMessage ( NO_TRACKER_FILES, 1, NULL, ERROR_DONTUSE_MENUFUNCS);
		return FALSE;
	}

	qsort( (void *)TrackerList[0], (size_t) Count , 256 , strcmp );

	memset( &TrackersList, 0, sizeof( LIST ) );
	TrackersList.display_items = 8;
	for( i = 0 ; i < Count ; i++ )
	{
		strncpy( TrackersList.item[ TrackersList.items++ ], TrackerList[ i ], sizeof( TrackersList.item[ 0 ] ) ); 
	}

	FindClose(h);

	return TRUE;
}

void InitTrackersList( MENU *menu )
{
	if ( TrackersList.selected_item < 0 )
	{
		PrintErrorMessage ( NO_TRACKER_FILES, 1, NULL, ERROR_DONTUSE_MENUFUNCS);
	}
}

void ExitSetUpTracker( MENU *menu )
{
	char buf[ 256 ];

	SetMultiplayerPrefs();
	
	sprintf( buf, "tracker\\%s.trk", TrackersList.item[ TrackersList.selected_item ] );
	DoHeartbeat = read_heartbeat_info( buf );

}
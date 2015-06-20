/*
 * The X Men, October 1996
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * $Revision: 81 $
 *
 * $Header: /PcProjectX/Comm.c 81    11/11/98 16:00 Philipy $
 *
 * $Log: /PcProjectX/Comm.c $
 * 
 * 81    11/11/98 16:00 Philipy
 * various fixes for warnings / errors when compiling under VC6
 * 
 * 80    14/10/98 9:31 Phillipd
 * 
 * 79    18/09/98 14:15 Phillipd
 * 
 * 78    14/09/98 15:35 Philipy
 * added facility for server based collisions
 * 
 * 77    7/09/98 11:44 Philipy
 * 
 * 76    27/08/98 17:26 Philipy
 * Pseudohost can select level, & migrates on quitting
 * players booted to titles due to not having new level are now informed
 * 
 * 75    20/08/98 15:28 Philipy
 * You can now join server based games after being launched by a lobby.
 * Level name is updated after pseudohost selects level
 * AVI can now play if no sound hw exists
 * started gamespy support
 * 
 * 74    17/08/98 18:00 Philipy
 * removed loads of unreferenced local variables
 * 
 * 73    14/08/98 15:25 Philipy
 * added trilinear option to menus
 * fixed level name / shutdown packet in heartbeat
 * 
 * 
 * 72    14/08/98 9:13 Phillipd
 * DirectX6 is in effect.......
 * 
 * 71    12/08/98 12:59 Phillipd
 * 
 * 70    12/08/98 12:54 Phillipd
 * 
 * 69    12/08/98 12:53 Phillipd
 * 
 * 68    12/08/98 11:54 Phillipd
 * 
 * 67    11/08/98 16:52 Philipy
 * fixed bug which caused max players to always be set to 32 if lobby
 * launched & lobby sets max players to 0.
 * status request codes now expected in hex format ( eg.
 * FFFFFFFFstatus\nfe<NULL> )
 * heartbeat frequencies less than 5000 mS can now be specified. If none (
 * or 0 ) specified, no heartbeat packets will be sent.
 * 
 * 66    7/08/98 12:45 Philipy
 * heartbeat now enabled for non tcp games ( if heartbeat.txt exists )
 * status type 0 now treated as status type 254
 * if lobby launched with max players set to 0, host is able to set max
 * players
 * shutdown udp packet now sent ( if specified in heartbeat.txt )
 * 
 * 65    31/07/98 16:17 Philipy
 * added PPS to session desc
 * 
 * 64    28/07/98 14:44 Philipy
 * all server timeouts now configurable
 * 
 * 63    28/07/98 10:39 Philipy
 * Max players now works properly for server games
 * 
 * 62    16/07/98 10:53 Philipy
 * fixed dissapearing session after level change on server based game
 * 
 * 61    15/07/98 16:25 Philipy
 * now handles pseudohost quitting in titles & server quitting ( in
 * titiles or in game )
 * 
 * 60    14/07/98 17:56 Philipy
 * fixed pseudohost quitting in titles bug ( if server recieves
 * MSG_GAMEPARAM after pseudohost has quit )
 * 
 * 59    14/07/98 11:15 Philipy
 * various patch bugs
 * pseudohost quitting in titles
 * 
 * 58    9/07/98 12:43 Philipy
 * few minor fixes for patch release
 * 
 * 57    7/07/98 18:03 Philipy
 * added lobby autostart code ( when all players have recieved init msg )
 * added num primary weapons menu option ( propergated to other players &|
 * server )
 * extracted new title text for localisation
 * 
 * 56    3/07/98 11:53 Philipy
 * heartbeat & quickstart stuff
 * 
 * 55    6/22/98 2:16p Phillipd
 * Option to reset the score for every level..............
 * 
 * 54    17/06/98 19:33 Philipy
 * more win98 stuff
 * 
 * 53    16/06/98 16:32 Philipy
 * more lobby / join game stuff
 * 
 * 52    12/06/98 16:06 Philipy
 * fixed lobby stuff for Wireplay
 * 
 * 51    6/09/98 12:09p Phillipd
 * 
 * 50    22/05/98 17:51 Philipy
 * more work on session info
 * 
 * 49    20/05/98 9:38 Philipy
 * implemented front end server menus
 * removed ( invalid ) ping from sessions menu
 * changed EnumPlayers so that it solely uses MSG_NAME
 * 
 * 48    5/12/98 12:46p Phillipd
 * 
 * 47    11/05/98 15:15 Philipy
 * added session info stuff ( game type, ping etc )
 * 
 * 46    5/06/98 4:53p Phillipd
 * 
 * 45    4/27/98 4:01p Phillipd
 * 
 * 44    4/06/98 7:06p Phillipd
 * 
 * 43    8/03/98 16:48 Philipy
 * added CTF game bit for lobby hosted games
 * 
 * 42    3/07/98 12:09p Phillipd
 * Changing the lpDplayLobby pointer from version 2 to 1 was not a good
 * idead Phil
 * Hacking out our normal lobby code so it worked with this new pointer
 * was an even worse idea.....
 * Not checking it before checking it in was your worsed idea...
 * 
 * 41    6/03/98 18:02 Philipy
 * 
 * 40    6/03/98 17:57 Philipy
 * added lobby support
 * 
 * 39    3/06/98 5:13p Phillipd
 * 
 * 38    4/03/98 12:33 Oliverc
 * CTF mode fully enabled
 * 
 * 37    3/03/98 16:59 Oliverc
 * New multiplayer CTF mode stuff (1st attempt)
 * 
 * 36    3/02/98 4:32p Phillipd	    
 * 
 * 35    3/02/98 12:29p Phillipd
 * 
 * 34    26/02/98 19:44 Oliverc
 * Active movie files "cplay.c" and "media.c" no longer necessary
 * 
 * 33    24/02/98 16:54 Oliverc
 * 1st attempt at bounty hunt multiplayer game
 * 
 * 32    1/16/98 2:54p Phillipd
 * 
 * 31    1/09/98 10:31a Phillipd
 * Bugs fixed......
 * 
 * 30    12/17/97 5:19p Phillipd
 * 
 * 29    12/10/97 10:39a Phillipd
 * Players names are now propergated across the network when changed...
 * Difficulty levels are functional....
 * 
 * 28    11/29/97 4:35p Phillipd
 * Xmem is now in effect...use it allways....
 * 
 * 27    10/09/97 3:29p Phillipd
 * External forces coming...
 * Shield and Hull now floats
 * 
 * 26    9/30/97 4:20p Phillipd
 * 
 * 25    9/30/97 8:45a Phillipd
 * 
 * 24    9/29/97 11:55a Phillipd
 * Dawn of a new age with directplay 3
 * 
 * 23    17/07/97 15:38 Collinsd
 * BGObjects now use compobjs.
 * 
 * 22    8/07/97 16:30 Collinsd
 * Dicked about with include files FUCK!
 * 
 * 21    6/24/97 11:12a Phillipd
 * 
 * 20    6/18/97 11:27a Phillipd
 * 
 * 19    6/16/97 4:15p Phillipd
 * added random start positions for first time you get into a level...
 * 
 * 18    6/14/97 1:11p Phillipd
 * Back to Dplay2
 * 
 * 17    6/10/97 9:01a Phillipd
 * 
 * 16    6/03/97 10:46a Phillipd
 * 
 * 15    4/25/97 2:51p Phillipd
 * 
 * 14    4/10/97 4:29p Phillipd
 * DirectPlay3 is here...
 * 
 * 13    20-03-97 5:46p Collinsd
 * Countdown timer now works in multiplayer.
 * 
 * 12    2/14/97 3:21p Phillipd
 * 
 * 11    2/11/97 5:11p Phillipd
 * 
 * 10    2/07/97 4:59p Phillipd
 * 
 * 9     1/10/97 11:30a Phillipd
 * movies are now doable
 * 
 * 8     12/27/96 12:33p Phillipd
 * all files are not dependant on mydplay.h...just some..
 * including it several times in the same files didnt help..
 * 
 * 7     12/23/96 6:04p Phillipd
 * 
 * 6     12/17/96 4:57p Phillipd
 * Version Control Added..
 * 
 * 5     12/14/96 5:04p Phillipd
 * 
 * 4     11/22/96 9:20a Phillipd
 * 
 * 3     11/20/96 2:42p Phillipd
 * players can now restart and keep there score...
 * 
 * 2     10/11/96 12:51p Phillipd
 * Slight update...Destroy player is now handled as a system message..
 * 
 * 1     10/10/96 3:09p Phillipd
 * First SS update fo some of this...
 * DirectPlay 2 here we go.....
 */


/*==========================================================================
 *
 *  Copyright (C) 1995-1996 Microsoft Corporation. All Rights Reserved.
 *
 *  File:       comm.c
 *  Content:    DirectPlay related code
 *
 *
 ***************************************************************************/

#include "stdwin.h"
#include <dplay.h>
#include <stdio.h>
#include "comm.h"
#include "typedefs.h"
#include "new3d.h"
#include "quat.h"
#include "CompObjects.h"
#include "bgobjects.h"
#include "Object.h"
#include "mydplay.h"
#include "d3dappi.h"
#include "main.h"
#include "mydplay2.h"
#include "title.h"
#include "primary.h"
#include "XMem.h"
#include "dpthread.h"
#include "multiplayer.h"

/*
 * Externals
 */
extern	LIST	PlayersList;
extern	BOOL	HarmTeamMates;
extern BOOL	BrightShips;
extern	BOOL	MyBrightShips;
extern BOOL	BikeExhausts;
extern int32 ColPerspective;
extern SLIDER CTFSlider;
extern	int16	MaxKills;
extern	BOOL ResetKillsPerLevel;
extern DPID	PlayerIDs[ MAX_PLAYERS ];
extern DPID LobbyPlayerIDs[ MAX_PLAYERS ];
extern BOOL PseudoHostCanSetMaxPlayers;
extern SLIDER  PacketsSlider;

/*
 * Globals
 */

LPDPSESSIONDESC2                    glpdpSD = NULL;            // current session description
#ifdef MANUAL_SESSIONDESC_PROPAGATE
LPDPSESSIONDESC2                    glpdpSD_copy = NULL;            // current session description
#endif
LPDIRECTPLAYLOBBY2A					lpDPlayLobby = NULL;		//Lobby stuff...
//LPDIRECTPLAYLOBBYA					lpDPlayLobby = NULL;		//Lobby stuff...
LPDPLCONNECTION						glpdplConnection = NULL;	// connection settings

BOOL IsLobbyLaunched = FALSE;
BOOL LobbyAutoStart = FALSE;
extern	DPID                    dcoID;

extern	LPDIRECTPLAY4A              glpDP;     // directplay object pointer

extern	DPSESSIONDESC2			Old_Session;
extern	DWORD                   Old_WhoIAm;
extern	DWORD					Old_Kills;
extern	DWORD					Old_Deaths;
extern	char					Old_Name[256];
extern	BOOL					Rejoining;
extern	BOOL					TeamGame;

extern	WORD					Version;
extern	HANDLE					hPlayerEvent;					// player event to use
extern	SLIDER	MaxPlayersSlider;
extern	SLIDER	TimeLimit;
extern	BOOL	BombTag;
extern	BOOL	CaptureTheFlag;
extern	BOOL	CTF;
extern	BOOL	BountyHunt;
extern	uint16	RandomStartPosModify;
extern	BOOL	DplayRecieveThread;
extern	BOOL	UseShortPackets;
extern	BOOL	BigPackets;

extern	BOOL                    IsServer;
extern	BOOL					IsHost;   // is the user hosting/joining a game
extern	SHORTNAMETYPE			Names;	// all the players short Names....

void DebugPrintf( const char * format, ... );
BOOL JoinASession ( MENUITEM * Item );
													   
/*
 * DPlayClose
 *
 * Wrapper for DirectPlay Close API
 */
HRESULT DPlayClose(void)
{
    HRESULT hr=E_FAIL;

    if (glpDP) 
        hr = IDirectPlayX_Close(glpDP);
    
    return hr;
}

/*
 * DPlayCreate
 *
 * Wrapper for DirectPlay Create API. Retrieves a DirectPlay3/DirectPlay3A interface
 * based on the UNICODE flag
 * 
 */
HRESULT DPlayCreate(LPGUID lpGuid)
{
    HRESULT hr=E_FAIL;
    LPDIRECTPLAY lpDP=NULL;

    // create a DirectPlay1 interface
    if ((hr = DirectPlayCreate(lpGuid, &lpDP, NULL)) == DP_OK)
    {
        if (lpDP)
        {
            // query for a DirectPlay3(A) interface
#ifdef UNICODE
            hr = IDirectPlay_QueryInterface(lpDP,&IID_IDirectPlay4,(LPVOID *)&glpDP);
#else
            hr = IDirectPlay_QueryInterface(lpDP,&IID_IDirectPlay4A,(LPVOID *)&glpDP);
#endif
            // no longer need the DirectPlay1 interface
            IDirectPlay_Release(lpDP);
        }
    }

    return hr;
}
/*
 * DPlayCreatePlayer
 *
 * Wrapper for DirectPlay CreatePlayer API. 
 */

HRESULT DPlayCreatePlayer(LPDPID lppidID, LPTSTR lptszPlayerName, HANDLE hEvent, 
                          LPVOID lpData, DWORD dwDataSize)
{
    HRESULT hr=E_FAIL;
    DPNAME name;
    

	if ( !IsLobbyLaunched )
		SetupConnection( myglobs.hInstApp );
	
	ZeroMemory(&name,sizeof(name));
    name.dwSize = sizeof(DPNAME);

	// if launched by lobby, use players config name ( if not player ) rather than name given by lobby
	if ( IsLobbyLaunched )
	{
		if ( _stricmp( lptszPlayerName, DEFAULT_PLAYER_NAME ) )
		{
			strcpy( lptszPlayerName, Names[ WhoIAm ] );
		}
	}

#ifdef UNICODE
    name.lpszShortName = lptszPlayerName;
#else
    name.lpszShortNameA = lptszPlayerName;
#endif

	if( DplayRecieveThread )
	{
		if (glpDP)
			hr = IDirectPlayX_CreatePlayer(glpDP, lppidID, &name, hPlayerEvent, lpData, 
										  dwDataSize, 0);
	}else{
		if (glpDP)
			hr = IDirectPlayX_CreatePlayer(glpDP, lppidID, &name, NULL, lpData, 
										  dwDataSize, 0);
	}

	switch( hr )
	{
	case DPERR_CANTADDPLAYER :
		DebugPrintf("DPERR_CANTADDPLAYER\n");
		break;
	case DPERR_CANTCREATEPLAYER :
		DebugPrintf("DPERR_CANTCREATEPLAYER\n");
		break;
	case DPERR_INVALIDFLAGS :
		DebugPrintf("DPERR_INVALIDFLAGS\n");
		break;
	case DPERR_INVALIDPARAMS :
		DebugPrintf("DPERR_INVALIDPARAMS\n");
		break;
	case DPERR_NOCONNECTION :
		DebugPrintf("DPERR_NOCONNECTION\n");
		break;
	case DP_OK:
		DebugPrintf("DP_OK\n");
		break;
	}
                                    
    return hr;
}

void StoreSessionUserFields( LPDPSESSIONDESC2 lpDesc )
{
	SYSTEMTIME	SystemTime;
	FILETIME FileTime;
	WORD	date;
	WORD	time;

	// store the creation time for this session
	GetSystemTime( &SystemTime );
	SystemTimeToFileTime( &SystemTime , &FileTime );
	FileTimeToDosDateTime( &FileTime , &date , &time );
	lpDesc->dwUser1 = date + (time << 16);
	lpDesc->dwUser2 = RandomStartPosModify;	// only lower word is used...

	if ( MaxKills > 255 )	// ensure 8 bit
		MaxKills = 255;

	lpDesc->dwUser2 |= ( MaxKills << MaxKills_Shift );
	
	if ( TimeLimit.value > 30 )
		TimeLimit.value = 30;
	
	lpDesc->dwUser3 = 0;
	lpDesc->dwUser3 |= ( TimeLimit.value << GameTimeBit_Shift );
	lpDesc->dwUser3 |= ( TimeLimit.value << CurrentGameTime_Shift );

	if( TeamGame )
		lpDesc->dwUser3 |= TeamGameBit;
	if( BombTag )
		lpDesc->dwUser3 |= BombGameBit;
	if( CTF )
		lpDesc->dwUser3 |= CTFGameBit;
	if( CaptureTheFlag )
		lpDesc->dwUser3 |= FlagGameBit;
	if ( BountyHunt )
		lpDesc->dwUser3 |= BountyGameBit;
	if ( UseShortPackets )
		lpDesc->dwUser3 |= ShortPacketsBit;
	if ( BigPackets )
		lpDesc->dwUser3 |= BigPacketsBit;

	// new additions ( previously in MSG_INIT )
	if ( HarmTeamMates )
		lpDesc->dwUser3 |= HarmTeamMatesBit;
	if ( MyBrightShips )
		lpDesc->dwUser3 |= BrightShipsBit;
	if(ResetKillsPerLevel )
		lpDesc->dwUser3 |= ResetKillsPerLevelBit;

	if ( BikeExhausts )
		lpDesc->dwUser3 |= BikeExhaustBit;

	lpDesc->dwUser3 |= ( ColPerspective << Collision_Type_BitShift );

	if ( IsServer )
		lpDesc->dwUser3 |= SERVER_STATE_NeedHost;

	lpDesc->dwUser3 |= CTF_Type_Encode( ( DWORD )CTFSlider.value );

	if ( PseudoHostCanSetMaxPlayers )
		lpDesc->dwUser3 |= EnableMaxPlayersChangeBit;

	lpDesc->dwUser4 = Version;		// only the lower word is used...

	lpDesc->dwUser4 |= ( MaxPlayersSlider.value << MaxPlayers_Shift );	// max players must be stored seperately for server game

	lpDesc->dwUser4 |= ( PacketsSlider.value << PacketsPerSecond_Shift );
}

/*
 * DPlayCreateSession
 *
 * Wrapper for DirectPlay CreateSession API.Uses the global application guid (PROJX_GUID).
 */
HRESULT DPlayCreateSession(LPTSTR lptszSessionName)
{
    HRESULT hr = E_FAIL;
    DPSESSIONDESC2 dpDesc;

	ZeroMemory(&dpDesc, sizeof(dpDesc));
    dpDesc.dwSize = sizeof(dpDesc);
    dpDesc.dwFlags = DPSESSION_MIGRATEHOST | DPSESSION_KEEPALIVE | DPSESSION_DIRECTPLAYPROTOCOL;
	dpDesc.dwMaxPlayers = MaxPlayersSlider.value;

	StoreSessionUserFields( &dpDesc );

	Old_Session = dpDesc;
	Old_WhoIAm = 0;
	Old_Kills = 0;
	Old_Deaths = 0;


#ifdef UNICODE
    dpDesc.lpszSessionName = lptszSessionName;
#else
    dpDesc.lpszSessionNameA = lptszSessionName;
#endif

    // set the application guid
	dpDesc.guidApplication = PROJX_GUID;

    if (glpDP)
        hr = IDirectPlayX_Open(glpDP, &dpDesc, DPOPEN_CREATE);




    return hr;
}

/*
 * DPlayDestroyPlayer
 * 
 * Wrapper for DirectPlay DestroyPlayer API. 
 */
HRESULT DPlayDestroyPlayer(DPID pid)
{
    HRESULT hr=E_FAIL;
    
    if (glpDP)
        hr = IDirectPlayX_DestroyPlayer(glpDP, pid);

	ShutdownConnection();

    return hr;
}

/*
 * DPlayEnumPlayers
 *
 * Wrapper for DirectPlay API EnumPlayers
 */
HRESULT DPlayEnumPlayers(LPGUID lpSessionGuid, LPDPENUMPLAYERSCALLBACK2 lpEnumCallback, 
                         LPVOID lpContext, DWORD dwFlags)
{
    HRESULT hr=E_FAIL;

    if (glpDP)
        hr = IDirectPlayX_EnumPlayers(glpDP, lpSessionGuid, lpEnumCallback, lpContext, dwFlags);

    return hr;
}

/*
 * DPlayEnumSessions
 *
 * Wrapper for DirectPlay EnumSessions API.
 */
HRESULT DPlayEnumSessions(DWORD dwTimeout, LPDPENUMSESSIONSCALLBACK2 lpEnumCallback, 
                          LPVOID lpContext, DWORD dwFlags)
{
    HRESULT hr = E_FAIL;
    DPSESSIONDESC2 dpDesc;

    ZeroMemory(&dpDesc, sizeof(dpDesc));
    dpDesc.dwSize = sizeof(dpDesc);
        dpDesc.guidApplication = PROJX_GUID;

    if (glpDP)
	{
        hr = IDirectPlayX_EnumSessions(glpDP, &dpDesc, dwTimeout, lpEnumCallback,
                                        lpContext, dwFlags);
	}

    return hr;
}

/*
 * DPlayGetPlayerData
 * 
 * Wrapper for DirectPlay GetPlayerData API.
 */
HRESULT DPlayGetPlayerData(DPID pid, LPVOID lpData, LPDWORD lpdwDataSize, DWORD dwFlags)
{
    HRESULT hr=E_FAIL;

    if (glpDP) 
        hr = IDirectPlayX_GetPlayerData(glpDP, pid, lpData, lpdwDataSize, dwFlags);

    return hr;
}

/*
 * DPlayGetSessionDesc
 *
 * Wrapper for DirectPlay GetSessionDesc API. 
 */
HRESULT DPlayGetSessionDesc(void)
{
    HRESULT hr=E_FAIL;
    DWORD dwSize;


    // free old session desc, if any
    if (glpdpSD)
    {
        free(glpdpSD);
        glpdpSD = NULL;
    }

	if (glpDP)
    {
#ifdef MANUAL_SESSIONDESC_PROPAGATE
		if ( glpdpSD_copy )
		{
			glpdpSD = (LPDPSESSIONDESC2) malloc( sizeof( *glpdpSD_copy ) );
			if ( glpdpSD )
			{
				*glpdpSD = *glpdpSD_copy;
				return DP_OK;
			}else
			{
				return E_OUTOFMEMORY; 
			}
		}
#endif
		// first get the size for the session desc
        if ((hr = IDirectPlayX_GetSessionDesc(glpDP, NULL, &dwSize)) == DPERR_BUFFERTOOSMALL)
        {
			// allocate memory for it
            glpdpSD = (LPDPSESSIONDESC2) malloc(dwSize);
            if (glpdpSD)
            {
                // now get the session desc
                hr = IDirectPlayX_GetSessionDesc(glpDP, glpdpSD, &dwSize);
            }
            else
            {
                hr = E_OUTOFMEMORY;
            }
        }
    }

    return hr;
}

void UpdateSessionName( char *name )
{
	DPSESSIONDESC2 tempsd;

	DPlayGetSessionDesc();

	if ( glpdpSD )
	{
		tempsd = *glpdpSD;
		glpdpSD->lpszSessionNameA = name;
		DPlaySetSessionDesc( 1 );	// 1 ensures new session desc is sent to all players via guaranteed msg

		*glpdpSD = tempsd;	// restore old SD so that it is freed properly.
		DPlayGetSessionDesc(); // getting new SD will free up old one
	}
}

/*
 * DPlaySetSessionDesc
 *
 * Wrapper for DirectPlay SetSessionDesc API. 
 */
HRESULT DPlaySetSessionDesc(DWORD flags)
{
    HRESULT hr=E_FAIL;

    if (glpDP && glpdpSD)
    {
#ifdef MANUAL_SESSIONDESC_PROPAGATE
		if ( glpdpSD_copy )
		{
			free ( glpdpSD_copy );
			glpdpSD_copy = NULL;
		}
#endif
		
		// now set the session desc
		hr = IDirectPlayX_SetSessionDesc(glpDP, glpdpSD, /*flags*/0 );
    }

#ifdef MANUAL_SESSIONDESC_PROPAGATE
	if ( hr == DP_OK )
	{
	   	if ( !flags )	// lazy way of preventing messages, since no flags are currently defined
						// for IDirectPlayX::SetSessionDesc !!
		{
			SendGameMessage( MSG_SESSIONDESC, 0, 0, 0, 0 );	
		}
	}
#endif

#ifdef DEBUG_ON
	if ( hr != DP_OK )
	{
		switch ( hr )
		{
		case DPERR_ACCESSDENIED:
			DebugPrintf("DPlaySetSessionDesc() error - DPERR_ACCESSDENIED\n");
			break;
		case DPERR_INVALIDPARAMS:
			DebugPrintf("DPlaySetSessionDesc() error - DPERR_INVALIDPARAMS\n");
			break;
		case DPERR_NOSESSIONS:
			DebugPrintf("DPlaySetSessionDesc() error - DPERR_NOSESSIONS\n");
			break;
		default:
			DebugPrintf("DPlaySetSessionDesc() error - unknown\n");
		}
	}
#endif

    return hr;
}

/*
 * IsDPlay
 *
 * Returns TRUE if a DirectPlay interface exists, otherwise FALSE.
 */
BOOL IsDPlay(void)
{
    return (glpDP ? TRUE:FALSE);
}

/*
 * DPlayOpenSession
 *
 * Wrapper for DirectPlay OpenSession API. 
 */
HRESULT DPlayOpenSession(LPGUID lpSessionGuid)
{
    HRESULT hr = E_FAIL;
    DPSESSIONDESC2 dpDesc;

    ZeroMemory(&dpDesc, sizeof(dpDesc));
    dpDesc.dwSize = sizeof(dpDesc);

    // set the session guid
    if (lpSessionGuid)
        dpDesc.guidInstance = *lpSessionGuid;
    // set the application guid
        dpDesc.guidApplication = PROJX_GUID;

    // open it
    if (glpDP)
        hr = IDirectPlayX_Open(glpDP, &dpDesc, DPOPEN_JOIN);

    return hr;
}



/*
 * DPlayRelease
 *
 * Wrapper for DirectPlay Release API.
 */
HRESULT DPlayRelease(void)
{
    HRESULT hr = E_FAIL;

	DPStopThread();

	// flush all waiting guaranteed messages
	ProcessGuaranteedMessages( TRUE , FALSE , FALSE );

    if (glpDP != NULL)
    {
        // free session desc, if any
//        if (glpdpSD) 
//        {
//            free(glpdpSD);
//            glpdpSD = NULL;
//        }

        // release dplay
        hr = IDirectPlayX_Release(glpDP);
        glpDP = NULL;
    }

//	if( lpDPlayLobby )
//	{
//		lpDPlayLobby->lpVtbl->Release(lpDPlayLobby);
//		lpDPlayLobby = NULL;
//	}

    return hr;
}

/*
 * DPlaySetPlayerData
 *
 * Wrapper for DirectPlay SetPlayerData API
 */
HRESULT DPlaySetPlayerData(DPID pid, LPVOID lpData, DWORD dwSize, DWORD dwFlags)
{
    HRESULT hr=E_FAIL;

    if (glpDP)
        hr = IDirectPlayX_SetPlayerData(glpDP, pid, lpData, dwSize, dwFlags);
    
    return hr;
}

/*
 * DPlay Create Lobby interface...
 *
 * Wrapper for DirectPlay Lobby Create API
 */
HRESULT DPlayCreateLobby( void )
{
	LPDIRECTPLAYLOBBYA	lpDPlayLobbyA = NULL;
	LPDIRECTPLAYLOBBY2A	lpDPlayLobby2A = NULL;
	HRESULT				hr;
		
	if (lpDPlayLobby)
	{
		lpDPlayLobby->lpVtbl->Release(lpDPlayLobby);
		lpDPlayLobby = NULL;
	}
	
	// get ANSI DirectPlayLobby interface
	hr = DirectPlayLobbyCreate(NULL, &lpDPlayLobbyA, NULL, NULL, 0);
	if FAILED(hr)
		goto FAILURE;
	// get ANSI DirectPlayLobby2 interface
	hr = lpDPlayLobbyA->lpVtbl->QueryInterface(lpDPlayLobbyA,
							&IID_IDirectPlayLobby2A, (LPVOID *) &lpDPlayLobby2A);
	if FAILED(hr)
		goto FAILURE;
	 
	// don't need DirectPlayLobby interface anymore
	lpDPlayLobbyA->lpVtbl->Release(lpDPlayLobbyA);
	lpDPlayLobbyA = NULL;
   /*
	// fill modem combo box with available modems
//	FillModemComboBox(hWnd, lpDPlayLobby2A);
*/
	// Fill in the ANSI lobby interface
	lpDPlayLobby = lpDPlayLobby2A;
	 
	
	return (DP_OK);

FAILURE:
	DebugPrintf("DPlayCreateLobby failure\n");
	if (lpDPlayLobbyA)
		lpDPlayLobbyA->lpVtbl->Release(lpDPlayLobbyA);
	if (lpDPlayLobby2A)
		lpDPlayLobby2A->lpVtbl->Release(lpDPlayLobby2A);

	return (hr);
}



/*
 * DPlay Create a sevice provider address...
 *
 * Wrapper for DirectPlay CreateCompoundAddress API
 */

HRESULT	CreateServiceProviderAddress( LPGUID lpGuid ,LPDIRECTPLAYLOBBY2A lpDPlayLobby, LPVOID *lplpAddress, LPDWORD lpdwAddressSize , char * TCPIPAddress)
{
	DPCOMPOUNDADDRESSELEMENT	addressElements[3];
//	CHAR						szPhoneNumberString[256];
//	CHAR						szModemString[256];
	LPVOID						lpAddress = NULL;
	DWORD						dwAddressSize = 0;
	DWORD						dwElementCount;
	HRESULT						hr;

	dwElementCount = 0;

	if (IsEqualGUID(lpGuid, &DPSPGUID_MODEM))
	{
		// Modem needs a service provider, a phone number string and a modem string

		// service provider
		addressElements[dwElementCount].guidDataType = DPAID_ServiceProvider;
		addressElements[dwElementCount].dwDataSize = sizeof(GUID);
		addressElements[dwElementCount].lpData = (LPVOID) &DPSPGUID_MODEM;
		dwElementCount++;

#if 0
		// add a modem string if available
		lstrcpy(szModemString, "");
		// This is where you would fill in the name of the modem...
		addressElements[dwElementCount].guidDataType = DPAID_Modem;
		addressElements[dwElementCount].dwDataSize = lstrlen(szModemString) + 1;
		addressElements[dwElementCount].lpData = szModemString;
		dwElementCount++;

		// add phone number string
		lstrcpy(szPhoneNumberString, "");
		// This is where you would fill in the Phone number.. fill in szPhoneNumberString with the phone number...
		addressElements[dwElementCount].guidDataType = DPAID_Phone;
		addressElements[dwElementCount].dwDataSize = lstrlen(szPhoneNumberString) + 1;
		addressElements[dwElementCount].lpData = szPhoneNumberString;
		dwElementCount++;
#endif
	}
	// internet TCP/IP service provider
	else if (IsEqualGUID(lpGuid, &DPSPGUID_TCPIP))
	{
		// TCP/IP needs a service provider and an IP address

		// service provider
		addressElements[dwElementCount].guidDataType = DPAID_ServiceProvider;
		addressElements[dwElementCount].dwDataSize = sizeof(GUID);
		addressElements[dwElementCount].lpData = (LPVOID) &DPSPGUID_TCPIP;
		dwElementCount++;

		// This is where you would fill in the IP Address..
		addressElements[dwElementCount].guidDataType = DPAID_INet;
		addressElements[dwElementCount].dwDataSize = lstrlen(TCPIPAddress) + 1;
		addressElements[dwElementCount].lpData = (LPVOID) TCPIPAddress;
		dwElementCount++;
	}

	// IPX service provider
	else if (IsEqualGUID(lpGuid, &DPSPGUID_IPX))
	{
		// IPX just needs a service provider

		// service provider
		addressElements[dwElementCount].guidDataType = DPAID_ServiceProvider;
		addressElements[dwElementCount].dwDataSize = sizeof(GUID);
		addressElements[dwElementCount].lpData = (LPVOID) &DPSPGUID_IPX;
		dwElementCount++;
	}

	// anything else, let service provider collect settings, if any
	else
	{
		// service provider
		addressElements[dwElementCount].guidDataType = DPAID_ServiceProvider;
		addressElements[dwElementCount].dwDataSize = sizeof(GUID);
		addressElements[dwElementCount].lpData = (LPVOID) lpGuid;
		dwElementCount++;
	}

	// see how much room is needed to store this address
	hr = lpDPlayLobby->lpVtbl->CreateCompoundAddress(lpDPlayLobby,
						addressElements, dwElementCount,
						NULL, &dwAddressSize);
	if (hr != DPERR_BUFFERTOOSMALL)
	{
		switch( hr )
		{

		case DPERR_BUFFERTOOSMALL:
			goto FAILURE;
			break;
		case DPERR_INVALIDFLAGS:
			goto FAILURE;
			break;

		case DPERR_INVALIDPARAMS:
			goto FAILURE;
			break;

		default:
			break;
		}

		goto FAILURE;

	}

	// allocate space
	lpAddress = malloc(dwAddressSize);
	if (lpAddress == NULL)
	{
		hr = DPERR_NOMEMORY;
		goto FAILURE;
	}

	// create the address
	hr = lpDPlayLobby->lpVtbl->CreateCompoundAddress(lpDPlayLobby,
						addressElements, dwElementCount,
						lpAddress, &dwAddressSize);
	if FAILED(hr)
		goto FAILURE;

	// return the address info
	*lplpAddress = lpAddress;
	*lpdwAddressSize = dwAddressSize;

	return (DP_OK);

FAILURE:
	if (lpAddress)
	{
		free(lpAddress);
		lpAddress = NULL;
	}
	return (hr);
}


/*
 * DPlay Once a Sevice Provider is chosen then create the DirectPlay Interfence
 *
 * Wrapper for DirectPlay CreateCompoundAddress API
 */
HRESULT	OnceServiceProviderChosen( LPGUID lpGuid ,LPDIRECTPLAYLOBBY2A lpDPlayLobby, LPDIRECTPLAY4A *lplpDPlay , char * TCPIPAddress)
{
	LPDIRECTPLAY4A	lpDPlay = NULL;
	LPVOID			lpAddress = NULL;
	DWORD			dwAddressSize = 0;
	HRESULT			hr;

	// bail if we don't have a lobby interface
	if (lpDPlayLobby == NULL)
		return (DPERR_INVALIDOBJECT);

	// get service provider address from information in dialog
	hr = CreateServiceProviderAddress( lpGuid,lpDPlayLobby, &lpAddress, &dwAddressSize ,TCPIPAddress);
	if FAILED(hr)
		goto FAILURE;
	// interface already exists, so release it
	if (*lplpDPlay)
	{
		(*lplpDPlay)->lpVtbl->Release(*lplpDPlay);
		*lplpDPlay = NULL;
	}

	// create an ANSI DirectPlay3 interface
	hr = CoCreateInstance(&CLSID_DirectPlay, NULL, CLSCTX_INPROC_SERVER, 
						  &IID_IDirectPlay4A, (LPVOID*)&lpDPlay);
	if FAILED(hr)
		goto FAILURE;

	// initialize the connection using the address
	hr = lpDPlay->lpVtbl->InitializeConnection(lpDPlay, lpAddress, 0);
	if FAILED(hr)
	{
		switch ( hr )
		{
		case DPERR_ALREADYINITIALIZED:
			DebugPrintf("DPERR_ALREADYINITIALIZED\n");
			break;
		case DPERR_INVALIDFLAGS:
			DebugPrintf("DPERR_INVALIDFLAGS\n");
			break;
		case DPERR_INVALIDPARAMS:
			DebugPrintf("DPERR_INVALIDPARAMS\n");
			break;
		case DPERR_UNAVAILABLE:
			DebugPrintf("DPERR_UNAVAILABLE\n");
			break;
		}

		goto FAILURE;
	}

	// return the connected interface
	*lplpDPlay = lpDPlay;

	// set to NULL so we don't release it below
	lpDPlay = NULL;

FAILURE:
	if (lpDPlay)
	{
		lpDPlay->lpVtbl->Close(lpDPlay);
		lpDPlay->lpVtbl->Release(lpDPlay);
	}
	if( lpAddress )
	{
		free(lpAddress);
	}
	return (hr);
}

/*
 * DPLobbyRelease
 *
 * Wrapper for DirectPlayLobby Release API
 */
HRESULT DPLobbyRelease(void)
{
	HRESULT hr=E_FAIL;

	// free our connection settings
	if (glpdplConnection)
	{
		free(glpdplConnection);
		glpdplConnection = NULL;
	}

	// release the lobby object
	if (lpDPlayLobby)
	{
		hr = IDirectPlayLobby_Release(lpDPlayLobby);
		lpDPlayLobby = NULL;
	}
	return hr;
}


/*
 * DPLobbyGetConnectionSettings
 *
 * Wrapper for DirectPlayLobby GetConnectionSettings API
 */
HRESULT DPLobbyGetConnectionSettings(void)
{
	HRESULT hr=E_FAIL;
	DWORD dwSize = 0;

	if (lpDPlayLobby)
	{
		// get size for the connection settings structure
		hr = IDirectPlayLobby_GetConnectionSettings(lpDPlayLobby, 0, NULL, &dwSize);
		if (DPERR_BUFFERTOOSMALL == hr)
		{ 
			// if we already have one, free it
			if (glpdplConnection)
			{
				free(glpdplConnection);
				glpdplConnection = NULL;
			}
			// allocate memory for the new one
			glpdplConnection = (LPDPLCONNECTION) malloc(dwSize);
			// get the connection settings
			if (glpdplConnection)
				hr = IDirectPlayLobby_GetConnectionSettings(lpDPlayLobby, 0, glpdplConnection, &dwSize);
		}
	}

	return hr;
}
/*
 * DPLobbySetConnectionSettings
 *
 * Wrapper for DirectPlayLobby SetConnectionSettings API
 */
HRESULT DPLobbySetConnectionSettings(void)
{
	HRESULT hr=E_FAIL;

    hr = IDirectPlayLobby_SetConnectionSettings(lpDPlayLobby, 0, 0, glpdplConnection);

	switch( hr )
	{
	case DP_OK :
		DebugPrintf("IDirectPlayLobby_SetConnectionSettings DPERR_GENERIC");
		break;
	case DPERR_GENERIC :
		DebugPrintf("IDirectPlayLobby_SetConnectionSettings DPERR_GENERIC");
		break;
	case DPERR_INVALIDINTERFACE :
		DebugPrintf("IDirectPlayLobby_SetConnectionSettings DPERR_INVALIDINTERFACE");
		break;
	case DPERR_INVALIDOBJECT :
		DebugPrintf("IDirectPlayLobby_SetConnectionSettings DPERR_INVALIDOBJECT");
		break;
	case DPERR_INVALIDPARAMS :
		DebugPrintf("IDirectPlayLobby_SetConnectionSettings DPERR_INVALIDPARAMS");
		break;
	case DPERR_OUTOFMEMORY :
		DebugPrintf("IDirectPlayLobby_SetConnectionSettings DPERR_OUTOFMEMORY");
		break;
	}

	return hr;
}

/*
 * DPLobbyConnect
 *
 * Wrapper for DirectPlayLobby Connect API.
 */
HRESULT DPLobbyConnect(void)
{
	HRESULT hr=E_FAIL;
	LPDIRECTPLAY2A              glpDP2a;     // directplay object pointer

	hr = IDirectPlayLobby_Connect(lpDPlayLobby, 0, &glpDP2a, NULL) ;
    if (FAILED(hr))

		return hr;

	hr = IDirectPlay_QueryInterface(glpDP2a,&IID_IDirectPlay4A,(LPVOID *)&glpDP);

	return hr;
}

/*
 * DPlaySetPlayerName
 *
 * Wrapper for DirectPlay SetPlayerName API
 */
HRESULT DPlaySetPlayerName(DPID pid, char * NamePnt, DWORD dwFlags)
{
    HRESULT hr=E_FAIL;
	DPNAME	Name;

    if (glpDP)
	{
		memset(&Name, 0, sizeof(DPNAME));
		Name.dwSize = sizeof(DPNAME);
		Name.lpszShortNameA = NamePnt;
        Name.lpszLongNameA = NamePnt;
        hr = IDirectPlayX_SetPlayerName(glpDP, pid, &Name, dwFlags);
	}
    return hr;
}


/*�������������������������������������������������������������������
	Procedure	:	Were we launched by a lobby ??
	Input		:	nothing
	Output		:	BOOL TRUE/FALSE
�������������������������������������������������������������������*/
BOOL LaunchedByLobby(void)
{
	LPDIRECTPLAY2A		lpDirectPlay2A = NULL;
	LPDIRECTPLAY4A		lpDirectPlay4A = NULL;
	LPDPLCONNECTION		lpConnectionSettings = NULL;
	DWORD				dwSize;
	HRESULT				hr;


	// get an ANSI DirectPlay lobby interface
//	hr = DirectPlayLobbyCreate(NULL, &lpDPlayLobby, NULL, NULL, 0);


	hr = DPlayCreateLobby();

	if FAILED(hr)
		goto FAILURE;

    // get connection settings from the lobby
	// if this routine returns DPERR_NOTLOBBIED, then a lobby did not
	// launch this application and the user needs to configure the connection.

	// pass in a NULL pointer to just get the size of the connection setttings
	hr = lpDPlayLobby->lpVtbl->GetConnectionSettings(lpDPlayLobby, 0, NULL, &dwSize);

	if ( hr == DPERR_NOTLOBBIED )
	{
		goto FAILURE;
	}

	// allocate memory for the connection setttings
	glpdplConnection = (LPDPLCONNECTION) malloc(dwSize);
	if (NULL == glpdplConnection)
	{
		goto FAILURE;
	}

	// get the connection settings
	hr = lpDPlayLobby->lpVtbl->GetConnectionSettings(lpDPlayLobby, 0, glpdplConnection, &dwSize);
	if FAILED(hr)
	{
	 	DebugPrintf("GetConnectionSettings failed\n");
		goto FAILURE;
	}

	// return connection info
	if (glpdplConnection->dwFlags & DPLCONNECTION_CREATESESSION)
	{
		// host...
		IsHost = TRUE;
		DebugPrintf("I am hosting lobby session\n");
		
	}
	else
	{
		// client...
		DebugPrintf("I am joining lobby session\n");
		IsHost = FALSE;
	}

	// before connecting, the game should configure the session description
	// with any settings it needs

	// set flags and max players used by the game
    glpdplConnection->lpSessionDesc->dwFlags = DPSESSION_MIGRATEHOST | 
												   DPSESSION_KEEPALIVE | DPSESSION_DIRECTPLAYPROTOCOL;
	
	//if ( !glpdplConnection->lpSessionDesc->dwMaxPlayers )
	//	glpdplConnection->lpSessionDesc->dwMaxPlayers = MAX_PLAYERS;

    glpdplConnection->lpSessionDesc->dwUser1 = 0;
    glpdplConnection->lpSessionDesc->dwUser2 = 0;
    glpdplConnection->lpSessionDesc->dwUser3 = 0;
    glpdplConnection->lpSessionDesc->dwUser4 = 0;

    // store the updated connection settings
    hr = lpDPlayLobby->lpVtbl->SetConnectionSettings(lpDPlayLobby, 0, 0, glpdplConnection);
	if FAILED(hr)
	{
	 	DebugPrintf("SetConnectionSettings failed\n");
		goto FAILURE;
	}

	// connect to the session - returns an ANSI IDirectPlay2A interface
	hr = lpDPlayLobby->lpVtbl->Connect(lpDPlayLobby, 0, &lpDirectPlay2A, NULL);
	if FAILED(hr)
	{
	 	DebugPrintf("Connect failed\n");
		goto FAILURE;
	}

	// Obtain an IDirectPlayXA interface, the IDirectPlay2A interface will
	// be released at the end of the function
	//hr = lpDirectPlay2A->lpVtbl->QueryInterface(lpDirectPlay2A, IID_IDirectPlayXA, (LPVOID *) &glpDP);
	hr = IDirectPlay_QueryInterface(lpDirectPlay2A,&IID_IDirectPlay4A,(LPVOID *)&glpDP);

	if FAILED(hr)
	{
	 	DebugPrintf("QueryInterface failed\n");
		goto FAILURE;
	}


	if (lpDirectPlay2A)
	{
		lpDirectPlay2A->lpVtbl->Release(lpDirectPlay2A);
		lpDirectPlay2A = NULL;
	}

	/*
	if (lpDPlayLobby)
	{
		lpDPlayLobby->lpVtbl->Release(lpDPlayLobby);
		lpDPlayLobby = NULL;
	}
	*/


    // create our player
    hr = DPlayCreatePlayer(
                            &dcoID,
#ifdef UNICODE
							glpdplConnection->lpPlayerName->lpszShortName,
#else
							glpdplConnection->lpPlayerName->lpszShortNameA,
#endif
							NULL,
							NULL,
							0
                          );
    if (FAILED(hr))
    {
		DebugPrintf("LaunchedByLobby(): could not create player\n");
        goto FAILURE;
    }

    DebugPrintf("launched by lobby OK\n");
	return TRUE;

FAILURE:
	if (lpDirectPlay2A)
	{
		lpDirectPlay2A->lpVtbl->Release(lpDirectPlay2A);
		lpDirectPlay2A = NULL;
	}

	if (lpDPlayLobby)
	{
		lpDPlayLobby->lpVtbl->Release(lpDPlayLobby);
		lpDPlayLobby = NULL;
	}

	return FALSE;

	return (hr);
}

// We need a MENU here that gives all the usual Starting a game options!! If Im the HOST!
// And the usual Setup code for starting a session inside BOOL StartAHostSession ( MENUITEM * Item ) But dont
// do any of the Directplay stuff in there.....	In fact look at the one below this....

void ContinueLobbyLaunch( void )
{
	HRESULT hr;
	//int i;

	if( IsHost )
	{															   
		hr = DPlayGetSessionDesc();
		if ( hr != DP_OK )
		{
			DebugPrintf("ContinueLobbyLaunch() DPlayGetSessionDesc NOT DP_OK\n");
			exit( 1 );	// no way to recover!!
		}
		
		DebugPrintf("ContinueLobbyLaunch() - max players is set to %d\n", glpdpSD->dwMaxPlayers );
		DebugPrintf("ContinueLobbyLaunch() - num players is set to %d\n", glpdpSD->dwCurrentPlayers );
		/*
		// enumerate players
		
		DPlayEnumPlayers( NULL, EnumPlayers, (LPVOID) NULL, 0);
		DebugPrintf("ContinueLobbyLaunch() - enumerated actual players is set to %d\n", PlayersList.items );

		memset( LobbyPlayerIDs, 0, sizeof( LobbyPlayerIDs ) );
		
		for ( i = 0; i < PlayersList.items; i++ )
		{
			LobbyPlayerIDs[ i ] = PlayerIDs[ i ];
			
			DebugPrintf("player %d - %s ( ID %x )\n", i, PlayersList.item[ i ], LobbyPlayerIDs[ i ] );
		}
		*/

		StoreSessionUserFields( glpdpSD );
		
		Old_Session = *glpdpSD;
		Old_WhoIAm = 0;
		Old_Kills = 0;
		Old_Deaths = 0;

		hr = DPlaySetSessionDesc( 0 );
		if ( hr != DP_OK )
		{
			DebugPrintf("ContinueLobbyLaunch() DPlaySetSessionDesc NOT DP_OK\n");
		}
	}

/*
    // create our player
    hr = DPlayCreatePlayer(
                            &dcoID,
#ifdef UNICODE
							glpdplConnection->lpPlayerName->lpszShortName,
#else
							glpdplConnection->lpPlayerName->lpszShortNameA,
#endif
							NULL,
							NULL,
							0
                          );
    if (FAILED(hr))
    {
        goto FAIL;
    }
*/

	if ( !IsHost )
	{
		MyGameStatus = STATUS_WaitingForLobbyConnect;
	}

    return;

/*

FAIL:
	// cleanup and exit
	DPLobbyRelease();
	PrintErrorMessage ( "unable to connect to lobby session ( 2 )", 0, NULL, ERROR_QUIT );
    //return FALSE;
*/
}




/*�������������������������������������������������������������������
	Procedure	:	DPlayCreateSessionServer
	Input		:	name
	Output		:	HRESULT
�������������������������������������������������������������������*/

HRESULT DPlayCreateSessionServer( LPTSTR lptszSessionName )
{
    HRESULT hr = E_FAIL;
    DPSESSIONDESC2 dpDesc;

	IsServer = TRUE;
	IsHost = TRUE;

#ifdef MANUAL_SESSIONDESC_PROPAGATE
		if ( glpdpSD_copy )
		{
			free ( glpdpSD_copy );
			glpdpSD_copy = NULL;
		}
#endif

	ZeroMemory(&dpDesc, sizeof(dpDesc));
    dpDesc.dwSize = sizeof(dpDesc);
    dpDesc.dwFlags = DPSESSION_CLIENTSERVER | 
					 DPSESSION_KEEPALIVE | 
					 DPSESSION_DIRECTPLAYPROTOCOL | 
					 DPSESSION_NOPRESERVEORDER;
	dpDesc.dwMaxPlayers = 2;

	StoreSessionUserFields( &dpDesc );

#ifdef UNICODE
    dpDesc.lpszSessionName = lptszSessionName;
#else
    dpDesc.lpszSessionNameA = lptszSessionName;
#endif

    // set the application guid
	dpDesc.guidApplication = PROJX_GUID;

    if (glpDP)
        hr = IDirectPlayX_Open(glpDP, &dpDesc, DPOPEN_CREATE);

    return hr;
}

/*�������������������������������������������������������������������
	Procedure	:	DPlayCreatePlayerServer
	Input		:	loads of stuff
	Output		:	HRESULT
�������������������������������������������������������������������*/
HRESULT DPlayCreatePlayerServer(LPDPID lppidID, LPTSTR lptszPlayerName, HANDLE hEvent, 
								LPVOID lpData, DWORD dwDataSize)
{
    HRESULT hr=E_FAIL;
    DPNAME name;
    
	ZeroMemory(&name,sizeof(name));
    name.dwSize = sizeof(DPNAME);

#ifdef UNICODE
    name.lpszShortName = lptszPlayerName;
#else
    name.lpszShortNameA = lptszPlayerName;
#endif

	// hPlayerEvent will be null if the recieve message stuff is not on a seperate thread
	if (glpDP)
		hr = IDirectPlayX_CreatePlayer(glpDP, lppidID, &name, hPlayerEvent, lpData, 
									  dwDataSize, DPPLAYER_SERVERPLAYER );
                                    
    return hr;
}


BOOL GetIPFromDP( char *add, DPID dpid )
{
    char* pTrueAddress;
    DWORD   dwTempSize;
    DWORD   dwIndex;
    DWORD   dwInetSize;
	char *abyTemp;
	HRESULT hr;
	char buf[ 128 ];

    dwIndex = 0;
    pTrueAddress = NULL;

    // get size required for address
	hr = IDirectPlayX_GetPlayerAddress( glpDP, dpid, NULL, &dwTempSize );
	if ( ( hr != DP_OK ) && ( hr != DPERR_BUFFERTOOSMALL ) )
	{
		switch ( hr )
		{
		case DPERR_INVALIDOBJECT :
			strcpy( buf, "DPERR_INVALIDOBJECT" );
			break;
		case DPERR_INVALIDPARAMS :
			strcpy( buf, "DPERR_INVALIDPARAMS" );
			break;
		case DPERR_INVALIDPLAYER :
			strcpy( buf, "DPERR_INVALIDPLAYER" );
			break;
		default:
			strcpy( buf, "unknown error" );
			break;
		}
		DebugPrintf("GetIPFromDP() IDirectPlayXA_GetPlayerAddress cannot get address size ( %s )\n", buf );
		return FALSE;
	}

	// malloc space for address buffer
	abyTemp = ( char * )malloc( dwTempSize );
	if ( !abyTemp )
	{
	 	DebugPrintf("GetIPFromDP() malloc failed\n");
		return FALSE;
	}

    hr = IDirectPlayX_GetPlayerAddress( glpDP, dpid, (void *)abyTemp, &dwTempSize );
	if ( hr != DP_OK )
	{
	 	DebugPrintf("IDirectPlayXA_GetPlayerAddress failed\n");
		return FALSE;
	}

    else
    {    
	    while ( dwIndex < dwTempSize )
        {        
			if ( ! memcmp( abyTemp+dwIndex , &DPAID_INet , sizeof(GUID) ) )
            {
				dwInetSize   = * (  (DWORD*) (abyTemp + dwIndex + sizeof(GUID))  );
	            pTrueAddress = abyTemp + dwIndex + sizeof(GUID) + sizeof(DWORD);

		        if ( '\0' == *pTrueAddress )
				{
				    DebugPrintf("GetIPFromDP() Can't get true address.\n");
					return FALSE;
				}
		        else
				{
				    DebugPrintf( "GetIPFromDP() True address %s\n", pTrueAddress );
				}
			    break;
            }
	        else
            {
		        //NOTE: This is a hack, should truly move along on a chunk by chunk basis...
			    dwIndex++;    
			}
        }
    }
	
	strncpy( add, pTrueAddress, 16 );

	return TRUE;
}


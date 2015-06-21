/*
 * The X Men, June 1996
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * Authors: Phillipd, Collinsd, Philipy, Oliverc
 */

 /*==========================================================================
 *
 *  Copyright (C) 1995 Microsoft Corporation. All Rights Reserved.
 *
 *  File: oct2.c
 *
 ***************************************************************************/

//#define   REFLECTION

#define INSIDE_BSP // disable to use bounding box inside check instead
#define BSP_ONLY

//#define LOBBY_DEBUG

#ifdef LOBBY_DEBUG
#include <direct.h>
#include <stdlib.h>
#endif

#include <stdio.h>
#include "main.h"
#include "typedefs.h"
#include <dplay.h>
#include "new3d.h"
#include "quat.h"
#include "Node.h"
#include "CompObjects.h"
#include "bgobjects.h"
#include "Object.h"
#include "mydplay.h"
#include "ddsurfhand.h"
#include "getdxver.h"



#include <stdarg.h>
#include <math.h>
#include <time.h>

#include "d3dmain.h"

#include "2dtextures.h"
#include "mload.h"

#include "primary.h"
#include "secondary.h"
#include "triggers.h"
#include "pickups.h"

#include "Ships.h"
#include "exechand.h"
#include "collision.h"
#include "ddutil.h"
#include "2dpolys.h"
#include "lines.h"
#include "polys.h"
#include "lights.h"
#include "models.h"
#include "2dtextures.h"
#include "visi.h"
#include "tload.h"
#include "sfx.h"
#include "transexe.h"
#include "Text.h"
#include "Mxaload.h"
#include "dinput.h"
#include "camera.h"
#include "cdaudio.h"
#include "title.h"
#include "screenpolys.h"
#include "controls.h"
#include "comm.h"
#include "triggers.h"
#include "enemies.h"

#include "tasker.h"
#include "bsp.h"
#include "trigarea.h"
#include "multiplayer.h"

#include    <fcntl.h>
#include    <sys/types.h>
#include    <sys/stat.h>
#include    <io.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    <malloc.h>
#include    <string.h>
#include    "file.h"
#include    "pvrd3d.h"

#include    "PolySort.h"

#include    "Ai.h"
#include    "Water.h"
#include    "spotfx.h"

#include <process.h>
#include    "ExtForce.h"
#include    "Teleport.h"

#include    "rtlight.h"
#include    "avi.h"
#include    "restart.h"
#include    "demo_id.h"
#include    "force.h"
#include    "feedback.h"
#include    "goal.h"
#include    "splash.h"
#include    "LoadSave.h"
#include    "Credits.h"
#include    "XMem.h"
#include    "local.h"
#include "dpthread.h"

#ifdef SHADOWTEST
#include "triangles.h"
#include "shadows.h"
#endif


extern BOOL Bsp_Duplicate( BSP_HEADER *src, BSP_HEADER *dup );
extern BOOL Bsp_Identical( BSP_HEADER *b1, BSP_HEADER *b2 );
BSP_HEADER Bsp_Original;


extern BOOL OKToJoinSession;
extern DPID PseudoHostDPID;

extern int      BountyInLevel;
extern int      FlagsInLevel;
extern int      TeamFlagsInLevel[ MAX_TEAMS ];
extern int      TeamFlagsInShips[ MAX_TEAMS ];

extern BOOL NeedFlagAtHome;
extern BOOL OwnFlagTeleportsHome;
extern BOOL CanCarryOwnFlag;
extern LONGLONG LevelCheckSum;

BOOL OriginalLevels = FALSE;
BOOL CheatsDisabled = FALSE;
BOOL WaitingToQuit;

void ConfigureSpaceorbAxis( int joystick );
void DefaultJoystickSettings( USERCONFIG *u );

int folder_exists( char *pathspec, ... );

extern const char last_compiled[];
extern BOOL LevelsOnCD;
extern  float   Countdown_Float;

#ifdef MANUAL_SESSIONDESC_PROPAGATE
extern LPDPSESSIONDESC2                    glpdpSD_copy;
#endif
extern  uint32 BigPacketSize;
extern  uint32 MaxBigPacketSize;
extern  uint32 RecPacketSize;
extern  uint32 MaxRecPacketSize;

extern  uint32 CurrentBytesPerSecRec;
extern  uint32 CurrentBytesPerSecSent;
extern  uint32 MaxCurrentBytesPerSecRec;
extern  uint32 MaxCurrentBytesPerSecSent;


extern char *JoystickPOVDirections[];
extern VECTOR BikePos;

extern char cd_path[];
extern int ValidCD( void );

extern BOOL CTF;
extern BOOL CD_OK;

extern BOOL IPAddressExists;
extern uint8 QuickStart;

extern char *TeamName[ MAX_TEAMS ];
extern BOOL IsLobbyLaunched;
extern int16 DummyTextureIndex;

extern void Printint16( int16 num , int x , int y , int col );

extern void InitIndirectVisible( uint16 g );

extern  BOOL IsServerGame;

extern void AddIndirectVisible( uint16 g );
extern  BOOL    RearCameraDisable;
extern  MODELNAME       SplashModelNames[MAXMODELHEADERS];
extern USERCONFIG *player_config;
extern char biker_config[];

/********************
splash externs
*******************/
extern NEWSPLASHSCREENS NewSplashScreens[];
extern int NewCurrentSplashScreen;
extern DWORD SplashFinishTime;
extern DWORD SplashStartTime;
extern BYTE PreSplash_MyGameStatus;
extern MENU *PreSplash_Menu;
extern MENUITEM *PreSplash_MenuItem;
extern LPDIRECTDRAWSURFACE lpDDS_NewSplash;

extern BOOL LimitedLoad;
extern BOOL InSplashDemo;

extern MODELNAME *TitleModelSet;
extern float LevelTimeTaken;

extern BYTE PreDemoEndMyGameStatus;
extern CRITICAL_SECTION CompoundSfxKey;
extern CRITICAL_SECTION SfxHolderKey; 
extern int NumDupCompoundBuffers;
extern COMPOUND_SFX_INFO CompoundSfxBuffer[MAX_COMPOUND_BUFFERS];
extern  BOOL    RecordDemoToRam;
extern  TEXT    DemoGameName;

extern  BOOL FullRearView;

extern  int AckMsgsActiveMax;
extern  int AckMsgsActive;

extern MENU MENU_Controls;
extern MENU MENU_Options;
extern MENU MENU_LoadSavedGame;
extern MENU MENU_SaveGame;
extern MENU MENU_NEW_BetweenLevels;
extern MENU MENU_NEW_BetweenLevels;
extern MENU MENU_NEW_StartAttractMode;
extern MENU MENU_NEW_NumberOfCrystals;
extern MENU MENU_NEW_WatchTeamSelect;

#ifdef CD_LOOP_THREAD
extern BOOL RestartCDTrack;
extern CRITICAL_SECTION CDKey;
extern DWORD CDFinishTime;
#endif

extern float VDUoffsetX;
extern float VDUoffsetY;
extern  int16   NextworkOldKills;
extern  int16   NextworkOldDeaths;
extern  int16   NextworkOldBikeNum;
extern  BOOL    DS;

extern  size_t  MemUsed;
extern  size_t  ExecMemUsed;

#ifdef DEBUG_ON
extern size_t   SBufferMemUsedSW;
extern size_t   SBufferMemUsedHW;
extern size_t   MaxSBufferMemUsedHW;
extern size_t   MaxSBufferMemUsedSW;
extern uint32 CurrentBikeCompSpeech;
#endif

BOOL PreventFlips = FALSE;
BOOL Cheated = FALSE;

BOOL ServerRendering = TRUE;
BOOL ServerCollisions = TRUE;

uint16 Current_Max_Score;

void InitSoundInfo( MLOADHEADER * Mloadheader );
void InitShipSpeeds( void );

#define DEFAULT_SCREEN_ASPECT_RATIO ( 4.0F / 3.0F )

#define SAVESCREEN_3DFX

uint32              AnimOncePerFrame = 0;                   // used for stuff that is displayed more than once in a single frame..
int CurrentLoadingStep = 0;

extern BOOL bSoundEnabled;

extern LPDIRECTDRAWSURFACE      Lp_AVI_DDSurface;

extern TeamCol[];
extern int Num_StatsMessage_Parts;
extern LIST BikeList;
extern LIST LevelList;
extern DWORD BufferedKey[];

extern  BOOL ResetKillsPerLevel;

extern BOOL DebugVisible;
extern BOOL ECTSDemo;

extern int  outside_map;

extern BOOL E3DemoHost;
extern BOOL E3DemoClient;
extern  int16   NextNewModel;

BOOL    E3DemoLoop;
BOOL    bPolyText = FALSE;
BOOL    PolygonText = FALSE;
extern  BOOL    PolyText[255];
extern MENUSTATE MenuState;
extern JOYSTICKINFO JoystickInfo[MAX_JOYSTICKS]; 
extern  char * LogFilename;
extern  char * BatchFilename;
extern int  CDTrack[];
extern  BOOL    ShowEFZones;
extern  BOOL    ShowTeleports;
extern BOOL MenuFrozen;
extern  int16   MaxKills;
extern SPOT_SFX_LIST LoopingSfxListStart[];
extern  int16   NumGoldBars;

extern CRITICAL_SECTION SfxKey;
extern BOOL ReloadSfx;
extern float ReloadSfxPause;
extern  BOOL    IllegalTime;
extern  int     SinglePlayerTimeLimit;
extern  BOOL    BilinearSolidScrPolys;
extern  uint16  RandomStartPosModify;                           
extern  int BigPacketsSent;
extern  LONGLONG    LastPacketTime[MAX_PLAYERS+1];
extern  char * StatusTab[256];

BYTE    PreSynchupStatus;
char *CurrentLevelsList;

float Old_LevelTime_Float;
void InitFontTransTable( BOOL BlitText );

#ifdef SOFTWARE_ENABLE
/*-------------------------------------------------------------------
        Chris's Code
-------------------------------------------------------------------*/
void    CWExecute2( LPDIRECT3DDEVICE lpDev,
                    LPDIRECT3DEXECUTEBUFFER execbuf,
                    LPDIRECT3DVIEWPORT lpView,
                    WORD cwFlags);
void    SWRendView( void );
void    SetVTables( void );
void CWClearZBuffer( void );
BOOL CWRenderSmallCamera( LPDIRECT3DDEVICE lpDev, LPDIRECT3DVIEWPORT lpView );

extern  BOOL    SoftwareVersion;
extern  long    RenderingSmall;
extern  long    RenderingSmallXOff;
extern  long    RenderingSmallYOff;
extern  long    zRW;
/*-----------------------------------------------------------------*/
#endif

void InitModeCase(void);
BOOL  IsEqualGuid(GUID *lpguid1, GUID *lpguid2);
void InitPolyText( void );


// Ai Modes
char * AiModes[] = {
    "AIMODE_PLAYER",                    // Controlled by PLAYER
    "AIMODE_FOLLOWPATH",                // Follow node path
    "AIMODE_IDLE",                  // Do nothing for a while
    "AIMODE_SCAN",                  // Look around for a target
    "AIMODE_MOVETOTARGET",          // Move towards selected target   
    "AIMODE_FIRE",          // Move towards selected target   
    "AIMODE_DOGFIGHT",              // Dogfight with the selected target   
    "AIMODE_KILLMINE",              // Attack And kill a Mine....
    "AIMODE_RETREAT",                   // Try and get away from PLAYER
    "AIMODE_FORMATION",             // Stay in Formation and attack whan necessary...

    "AIMODE_DEATH_CRASHNBURN",      // Fall to the ground and Shatter...
    "AIMODE_DEATH_PINGOFF",         // Ping off in the dir of the bullet that killed me spinning as I go...
    "AIMODE_DEATH_PSYCHO",          // Twist and turn and shoot and explode...
    "",
    "",
    "",
};
extern  int EnemiesActive;

// Bomb Stuff
void    InitBombs( void );
BOOL    BombTag = FALSE;//TRUE;
float   NewBombTime = ( 100.0F * 30.0F );   // approx 30 seconds...
int     LowestBombTime = -1;
int     OldLowestBombTime = -1;
int     LastPersonISentABomb = 0;
int     NumOfBombToStart = 1;
BOOL    BombActive[MAXBOMBS];
float   BombTime[MAXBOMBS];
extern  int BombNumToSend;
extern  float BombTimeToSend;
void PassOnNewBomb( int i );
void UpdateBombs( void );
// End of Bomb Stuff
void CheckTimeLimit( void );

extern  int16 InGameLoadGameLevelNum;
#ifdef REFLECTION
void WierdShit( void );
#endif


BOOL    IMustQuit = FALSE;

// Capture The Flag Stuff
BOOL    CaptureTheFlag = FALSE;
BOOL    IHaveAFlag = FALSE;

// End of Capture The Flag


// Bounty Hunt
BOOL    BountyHunt = FALSE;

static char fname[256];
static int fnum = 0;
extern int CameraStatus;    


char *  InitViewMessages[] = {
#if defined( SELF_PLAY ) || defined( ECTS ) || defined( FINAL_RELEASE )
                                 "Loading... 1 of 10" ,
                                 "Loading... 2 of 10" ,
                                 "Loading... 3 of 10" ,
                                 "Loading... 4 of 10" ,
                                 "Loading... 5 of 10" ,
                                 "Loading... 6 of 10" ,
                                 "Loading... 7 of 10" ,
                                 "Loading... 8 of 10" ,
                                 "Loading... 9 of 10" ,
                                 "Loading... 10 of 10" ,
#else
                                 "Loading OffScreen Surfaces" ,
                                 "Texture Load Prep         " ,
                                 "Loading Textures          " ,
                                 "Loading Models            " ,
                                 "Loading World Mesh        " ,
                                 "Loading Collision Skins   " ,
                                 "Init Sound Info           " ,
                                 "Init Ambient Lighting     " ,
                                 "Loading Sfx               " ,
                                 "Everything Else...Nodes   " ,
#endif
                                 "" 
};

extern  float   MaxMoveSpeed;
extern  float   MoveAccell;
extern  float   MoveDecell;
extern  float   MaxTurboSpeed;
extern  float   TurboAccell;
extern  float   TurboDecell;
extern  float   MaxTurnSpeed;
extern  float   TurnAccell;
extern  float   TurnDecell;
extern  float   MaxRollSpeed;
extern  float   RollAccell;
extern  float   RollDecell;
extern  float   MaxBankAngle;
extern  float   BankAccell;
extern  float   BankDecell;

extern BOOL BrightShips;

extern  float   LastDistance[MAX_SFX];

BOOL    Is3Dfx;
BOOL    Is3Dfx2;

BOOL    IsPowerVRD3DDevice(void);
BOOL    PowerVR = FALSE;
BOOL    PowerVR_Overide = FALSE;
BOOL    bPolySort = FALSE;

void    Test( void )
{
    while( 1 )
    {
        TaskSleep(1);
    }
}
extern int GameCompleted;
extern  OFF_FILES OffsetFiles[];
extern  OFF_FILES Title_OffsetFiles[];
extern  OFF_FILES Splash_OffsetFiles[];

extern  int     DifficultyLevel;

extern int outside_group;

extern  BOOL    ScreenSaving;
extern  float   WhiteOut;
extern float mouse_dx;
extern float mouse_dy;
BOOL    InsideResizeViewport = FALSE;

DWORD   CurrentSrcBlend;
DWORD   CurrentDestBlend;
DWORD   CurrentTextureBlend;
 
LONGLONG    GameStartedTime;        // when the game started
LONGLONG    GameElapsedTime;        // Real how long the game has been going in game time not real..
LONGLONG    TempGameElapsedTime;    // Real how long the game has been going in game time not real..
LONGLONG    GameCurrentTime;        // How long the game has been going...
LONGLONG    LargeTime;
LONGLONG    LastTime;
LONGLONG    TimeDiff;
LONGLONG    Freq;
BOOL    JustExitedMenu =FALSE;

BOOL    Inside;
int     Depth;

void CalculateFramelag( void );
void SetGamePrefs( void );

MENU    MENU_EditMacro1;
MENU    MENU_EditMacro2;
MENU    MENU_EditMacro3;

extern  BOOL    ServerMode;
int     ServerCount = 0;

extern  DPID                    dcoID;

extern  FILE    *   DemoFp;
extern  FILE    *   DemoFpClean;

extern  BOOL    PlayDemo;
extern  BOOL    PauseDemo;
extern  BOOL    RecordDemo;
extern  SLIDER  DemoSpeed;
extern  SLIDER  DemoEyesSelect;
extern  BOOL    DemoScreenGrab;
extern  BOOL    ShowWeaponKills;

LPDIRECT3DEXECUTEBUFFER lpD3DNormCmdBuf;
LPDIRECT3DEXECUTEBUFFER lpD3DTransCmdBuf;
LPDIRECT3DEXECUTEBUFFER lpD3DSpcFxTransCmdBuf;
BOOL InitSpecialExecBufs( void );
void ReleaseSpecialExecBufs( void );

extern  BOOL    flush_input; // tells control routines to ignore next player input

extern  uint16  IsGroupVisible[MAXGROUPS];

extern  MXLOADHEADER ModelHeaders[MAXMODELHEADERS];
extern  MODELNAME   TitleModelNames[MAXMODELHEADERS];   

extern  char    TitleNames[8][64];  

extern  ENEMY   *   FirstEnemyUsed;

extern  CAMERA  CurrentCamera;
extern  CAMERA  MainCamera;         // the main viewing screen...

extern  CDInfo  cd_info;
extern  BOOL    CD_Present;

float   FPS = 0.0F;                 // Frames Per Second...
double  TPS = 0.0;                  // Textures Per Second...           
int Our_TrianglesDrawn = 0; // Textures Per Second...           

#define MYTIMER
#undef MYTIMER

#define LEVELSFILE          "levels.dat"

extern  MENU  *             GetPlayerNumMenu;


#define FOV_GROW(A)         ((A) + 10.0F)
#define FOV_SHRINK(A)       ((A) - 10.0F)

LONGLONG    DemoStartedTime;        // when the game started
LONGLONG    DemoEndedTime;          // when the game started
float       DemoTotalTime = 0.0F;   // total game time (in seconds)
int32       DemoGameLoops = 0;
float   DemoAvgFps = 0.0F;

#define MIN_VIEWPORT_WIDTH  (64)
#define MIN_VIEWPORT_HEIGHT (64)

#define VIEWPORT_GROW       (1.1F)
#define VIEWPORT_SHRINK     (1.0F/1.1F)

extern  TLOADHEADER Tloadheader;
extern  int16       SecondaryAmmo[ MAXSECONDARYWEAPONS ];
BOOL LockOutWindows = FALSE;

extern uint16   OnceOnly;
extern char                 MyName[ 32 ];
extern  BOOL                    IsHost;
extern  BOOL                    IsServer;
extern float    MessageTime[MAX_MESSAGES];
extern  char MessageBank[MAX_MESSAGES][200];
extern  int CurrentMessage;
extern  BYTE                    MyGameStatus;
BYTE PreWaitingToSendMessagesStatus;
extern  BYTE                    GameStatus[];   // Game Status for every Ship...
extern  BYTE                    OverallGameStatus;          // what the host says he is doing...
extern  LPDIRECT3DEXECUTEBUFFER Skin_Execs[ MAXGROUPS ];
extern  LPDIRECT3DEXECUTEBUFFER Portal_Execs[ MAXGROUPS ];
extern  float   PyroliteAmmo;
extern  float   SussGunAmmo;
extern  float   GeneralAmmo;
extern  SHIPCONTROL control;
extern  REGENPOINT  *   RegenPoints;
extern  int16           NumRegenPoints;
extern  float   PowerLevel;
extern  float   LaserTemperature;
extern  float   NitroFuel;
extern  SECONDARYWEAPONBULLET SecBulls[MAXSECONDARYWEAPONBULLETS];
extern  ENEMY * TestEnemy;

extern  DWORD                   Old_WhoIAm;
extern  DWORD                   Old_Kills;
extern  DWORD                   Old_Deaths;
extern  DWORD                   Old_TeamNumber;
extern  char                    Old_Name[256];
extern  BOOL                    Rejoining;
extern  char    biker_name[256];
extern  int16   SelectedBike;
extern  DPSESSIONDESC2          Old_Session;
extern  LPDPSESSIONDESC2                    glpdpSD;
extern  LPDIRECTPLAY4A                       glpDP;     // directplay object pointer
extern  BOOL    AutoDetail;
extern  LONGLONG    DemoTimeSoFar;

extern  float   cral;
extern  int     HullHit;
extern  int     ShieldHit;
extern  BOOL    TargetComputerOn;

extern  int ScoreSortTab[MAX_PLAYERS];
extern  int16   NumPickupsPerGroup[ MAXGROUPS ];
extern  PICKUP  Pickups[ MAXPICKUPS ];

extern  BOOL    DebugInfo;
extern  BOOL    GodMode;
extern  BOOL    GodModeOnceOnly;
extern  BOOL    EnhancedXHair;

extern  BOOL    TeamGame;
extern  BYTE    TeamNumber[MAX_PLAYERS];

extern  int     no_collision;       // disables player ship-to-background collisions
extern  SLIDER  TimeLimit;
extern  BOOL    CountDownOn;
extern  REGENPOINT  *   RegenSlotsCopy[ MAX_PLAYERS ];

extern  BOOL    ShowTrigZones;
extern  BOOL    ShowColZones;
extern  BOOL    NodeCube;
extern  BOOL    OldNodeCube;
extern  MATRIX  MATRIX_Identity;

extern  uint32  TotalFmPolysInUse;
extern  uint32  TotalPolysInUse;
extern  uint32  TotalScrPolysInUse;
extern  MODELNAME   ModelNames[MAXMODELHEADERS];
extern  BOOL    quitting;   
extern  int16   MakeColourMode;
extern  BOOL    ShowBoundingBoxes;

BOOL InitViewport( float scale );


BYTE    InitView_MyGameStatus;
BYTE    ChangeLevel_MyGameStatus;

LPDIRECTDRAWPALETTE ddpal;

void ProcessGameKeys( void );


float   GetPlayerNumCount1 = 0.0F;
float   GetPlayerNumCount2 = 0.0F;
int     GetPlayerNumCount = 0;

int RearCameraActive = 0;
int MissileCameraActive = 0;
uint16  CameraMissile = (uint16) -1;
int MissileCameraEnable = 0;
BYTE    TempMissileCam;

extern  uint16      PrimaryStats[TOTALPRIMARYWEAPONS*2];
extern  uint16      SecondaryStats[TOTALSECONDARYWEAPONS*2];

extern  REMOTECAMERA * ActiveRemoteCamera;

BOOL
Our_CalculateFrameRate(void);
BOOL VduFinished( MENU *Menu );
BOOL WriteMessage(const char *format, ...); // printf-a-like for bottom line of window

BOOL ScoreDisplay();
BOOL FreeScoreDisplay();
BOOL InitScoreDisplay();
BOOL StatsDisplay();
BOOL FreeStatsDisplay();
BOOL InitStatsDisplay();

int Secrets = 0;
int TotalSecrets = 0;
int CrystalsFound = 0;
extern  int16       NumInitEnemies;
extern  int16       NumKilledEnemies;

BOOL    ResizeViewport( float scale );
float   CurrentViewportScale;
BOOL    FullScreenViewport();

BOOL InitDInput(void);
BOOL TermDInput( void );
BOOL    ClearBuffers( BOOL ClearScreen, BOOL ClearZBuffer );
BOOL    ClearZBuffer();

BOOL    RenderCurrentCamera( LPDIRECT3DDEVICE lpDev, LPDIRECT3DVIEWPORT lpView );
void DrawLoadingBox( int current_loading_step, int current_substep, int total_substeps );
void FreeSfxHolder( int index ) ;
void ShowSplashScreen( int num );
void InitValidPickups();

void    PlotSimplePanel( void );

BOOL cursorclipped = FALSE;
RECT cursorclip;

LPDIRECT3DDEVICE lpD3Ddev = NULL;
D3DVIEWPORT viewport;
D3DVIEWPORT oldviewport;
HRESULT hresult;
int initfov = 0;
float viewplane_distance;
float hfov = START_FOV;
float chosen_fov = START_FOV;
float normal_fov = START_FOV;
float screen_aspect_ratio = DEFAULT_SCREEN_ASPECT_RATIO;
uint16 PanelHeight = 48;

BOOL    DrawPanel = FALSE;
BOOL    DrawSimplePanel = TRUE;
BOOL    ReMakeSimplePanel = TRUE;

BOOL    OldDrawPanel = TRUE;
BOOL    DrawCrosshair = TRUE;
#ifdef SELF_PLAY
BOOL    Panel = FALSE;
BOOL PreAttractModePanel = FALSE;
#else
BOOL    Panel = TRUE;
BOOL PreAttractModePanel = TRUE;
#endif

BOOL    UsedStippledAlpha = FALSE;
BOOL    CanCullFlag = FALSE;


BOOL ChangeLevel( void );
void SelectQuitCurrentGame( MENUITEM *Item );

BOOL ForsakenAnyKey = FALSE;

float pixel_aspect_ratio;
float ticksperframe = 14.0F;    
float Oldframelag;  
float framelag = 0.0F;  
float framelag2 = 0.0F; 
float avgframelag = 0.0F;   
float   Demoframelag = 0.5F;

extern int FontWidth;
extern int FontHeight;
extern int FontSourceWidth;
extern int FontSourceHeight;

extern  int PlayerSort[MAX_PLAYERS];
extern  int16   Stats[MAX_PLAYERS+1][MAX_PLAYERS+1];
extern int16 NumOfActivePlayers;

void GeneralBltFast( int srcx, int srcy , int w , int h  , int dstx , int dsty , LPDIRECTDRAWSURFACE Surface ,  char * FileName , DWORD flags , LPDIRECTDRAWSURFACE DestSurface);
void GeneralBlt( int srcx, int srcy , int w , int h  , int dstx , int dsty , int dstw , int dsth , LPDIRECTDRAWSURFACE SrcSurface ,     char * FileName , DWORD flags , LPDIRECTDRAWSURFACE DestSurface);

void CALLBACK TimerProc( UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2 );

int16       LevelNum = 0 ;
int16       NewLevelNum = 0 ;
int16       NumLevels = 0;
char    ShortLevelNames[MAXLEVELS][32];
char    LevelNames[MAXLEVELS][128];
char    ServerLevelNames[MAXLEVELS][ 8 ];
uint8   ServerLevelsListState = SERVERLEVELS_Waiting;
int16   NumServerLevels = 0;
char    CollisionNames[MAXLEVELS][128];
char    CollisionZNames[MAXLEVELS][128];
char    BspNames[MAXLEVELS][128];
char    BspZNames[MAXLEVELS][128];
char    ZoneNames[MAXLEVELS][128];
char    WaterNames[MAXLEVELS][128];
char    TextNames[MAXLEVELS][128];
char    MsgNames[MAXLEVELS][128];
char    ExternalForceNames[MAXLEVELS][128];
char    TeleportNames[MAXLEVELS][128];

char MissionTextNames[MAXLEVELS][128];
char MissionTextPics[MAXLEVELS][128];

int use_level_path = 0;
char level_path[128];
char level_names[MAXLEVELS][128];
int use_data_path = 0;
int use_local_data = 0;
char data_path[ 128 ] = "";
char normdata_path[128] = "data\\";
int16   CameraRendering = CAMRENDERING_None;

BOOL SeriousError = FALSE;
BOOL DoClipping = TRUE;
BOOL OnceOnlyChangeLevel = FALSE;

LPDIRECT3DEXECUTEBUFFER RenderBufs[ 2 ] = { NULL, NULL };
void InitRenderBufs( LPDIRECT3DDEVICE lpDev );
void ReleaseRenderBufs( void );
BOOL ChangeBackgroundColour( float R, float G, float B );
BOOL SetMatrixViewPort( void );
void PrintInitViewStatus( BYTE Status );
void GetHardwareCaps( void );

void UpdateBGObjectsClipGroup( CAMERA * Camera );
void UpdateEnemiesClipGroup( CAMERA * Camera  );
void SpecialDestroyGame( void );
BOOL SaveFullScreenSnapShot( int8 * Filename );
void InitMySessionsList(void);

extern  int16   PrimaryInLevel[ MAXPRIMARYWEAPONS ];
extern  int16   SecondaryInLevel[ MAXSECONDARYWEAPONS ];
extern  int16   PrimaryInPlayers[ MAXPRIMARYWEAPONS ];
extern  int16   SecondaryInPlayers[ MAXSECONDARYWEAPONS ];
extern  int16   PrimaryToGenerate[ MAXPRIMARYWEAPONS ];
extern  int16   SecondaryToGenerate[ MAXSECONDARYWEAPONS ];
extern  int16   MinesInLevel[ MAXSECONDARYWEAPONS ];
extern  int16   OrbsInLevel;
extern  int16   OrbsToGenerate;
extern  int16   OrbsInPlayers;

/*-------------------------------------------------------------------
        Weapon Names...
-------------------------------------------------------------------*/
char PrimaryNames[7][16] = {
                        { "Pulsar" } ,
                        { "Trojax" } ,
                        { "Pyrolite" } ,
                        { "Transpulse" } ,
                        { "Suss Gun" } ,
                        { "Laser" } ,
                        { "" }  
};
char SecondaryNames[12][16] = {
                        { "Mug" } ,
                        { "Solaris" } ,
                        { "Thief" } ,
                        { "Scatter" } ,
                        { "Gravgon" } , 
                        { "MFRL" } , 
                        { "Titan" } ,
                        { "Purge Mine" } ,
                        { "Pine Mine" } ,
                        { "Quantum Mine" } ,
                        { "Spider Mine" } ,
                        { "" }  

};
int PrimaryLengths[7] ={ 
                         sizeof("Puls")-1  ,
                         sizeof("Troj")-1  ,
                         sizeof("Pyro")-1  ,
                         sizeof("Tran")-1  ,
                         sizeof("Suss")-1  ,
                         sizeof("Beam")-1 };
int SecondaryLengths[12] = {
                         sizeof("Mug ")-1 ,
                         sizeof("Sola")-1 ,
                         sizeof("Thei")-1 ,
                         sizeof("Scat")-1 ,
                         sizeof("Grav")-1 , 
                         sizeof("MFRL")-1 , 
                         sizeof("Tita"  )-1 ,
                         sizeof("Purg")-1 ,
                         sizeof("Pine")-1 ,
                         sizeof("Quan")-1,
                         sizeof("Spid")-1 };
#if 0
int PrimaryLengths[7] ={ 
                         sizeof("Pulsar")-1  ,
                         sizeof("Trojax")-1  ,
                         sizeof("Pyrolite")-1  ,
                         sizeof("Transpulse")-1  ,
                         sizeof("Suss Gun")-1  ,
                         sizeof("Beam Laser")-1 };
int SecondaryLengths[12] = {
                         sizeof("Mug")-1 ,
                         sizeof("Solaris")-1 ,
                         sizeof("Thief")-1 ,
                         sizeof("Scatter")-1 ,
                         sizeof("Gravgon")-1 , 
                         sizeof("MFRL")-1 , 
                         sizeof("Titan")-1 ,
                         sizeof("Purge Mine")-1 ,
                         sizeof("Pine Mine")-1 ,
                         sizeof("Quantum Mine")-1,
                         sizeof("Spider Mine")-1 };
#endif


/*-------------------------------------------------------------------
        Panel Description Stuff...
-------------------------------------------------------------------*/
char    PanelNames[8][32] ={    
                           { "data\\pictures\\p320X50.bmp" } ,
                           { "data\\pictures\\p320X60.bmp" } ,
                           { "data\\pictures\\p320X100.bmp" } ,
                           { "data\\pictures\\p512X96.bmp" } ,
                           { "data\\pictures\\p640X100.bmp" } ,
                           { "data\\pictures\\p640X120.bmp" } ,
                           { "data\\pictures\\p800X150.bmp" } ,
                           { "" }
};

//  How much can we get away with not rendering... and how much do we have to blit???
int16   PanelVisibleY[8] = { 50,            //320X200
                             60,            //320X240
                             100,           //320X400
                             96,            //512X384
                             100,           //640X400
                             120,           //640X480
                             150 };         //800X600

int16   PanelVisibleX[8] = { 320,           //320X200
                             320,           //320X240
                             320,           //320X400
                             512,           //512X384
                             640,           //640X400
                             640,           //640X480
                             800 };         //800X600
                            
int16   CrossHairX[10] = { 192 ,192 ,160 , 128, 96, 224, 192, 160, 128, 96 };
int16   CrossHairY[10] = {  64, 64, 64, 64, 64, 32, 32, 32, 32, 32 };

int16   PrimaryX[6] = { 64+(48*0), 64+(48*1) , 64+(48*2) , 64+(48*3) , 64+(48*0), 64+(48*1) } ;
int16   PrimaryY[6] = { 96 , 96 , 96 , 96 , 96+(32*1) , 96+(32*1) };


int16   ModesX[8] = { 320,          //320X200
                      320,          //320X240
                      320,          //320X400
                      512,          //512X384
                      640,          //640X400
                      640,          //640X480
                      800 };        //800X600
int16   ModesY[8] = { 200,          //320X200
                      240,          //320X240
                      400,          //320X400
                      384,          //512X384
                      400,          //640X400
                      480,          //640X480
                      600 };        //800X600

float   ModeScaleX[8] ={ 1.0F ,         //320X200
                         1.0F ,         //320X240
                         1.0F ,         //320X400
                         1.6F ,         //512X384
                         2.0F ,         //640X400
                         2.0F ,         //640X480
                         2.5F  };           //800X600
      
float   ModeScaleY[8] ={ 1.0F  ,            //320X200
                         1.2F  ,            //320X240
                         2.0F  ,            //320X400
                         1.92F ,            //512X384
                         2.0F  ,            //640X400
                         2.4F  ,            //640X480
                         3.0F   };          //800X600


char    FontNames[8][64] = { { "data\\pictures\\font.bmp" } ,   //320X200
                             { "data\\pictures\\font.bmp" } ,   //320X240
                             { "data\\pictures\\font.bmp" } ,   //320X400
                             { "data\\pictures\\font512.bmp" } ,    //512X384
                             { "data\\pictures\\font512.bmp" } ,    //640X400
                             { "data\\pictures\\font800.bmp" } ,    //640X480
                             { "data\\pictures\\font800.bmp" } };   //800X600

char    DynamicFontNames[ 64 ];

char    ScoreNames[8][64] ={    
                           { "data\\pictures\\S320X200.bmp" } ,
                           { "data\\pictures\\S320X240.bmp" } ,
                           { "data\\pictures\\S320X400.bmp" } ,
                           { "data\\pictures\\S512X384.bmp" } ,
                           { "data\\pictures\\S640X400.bmp" } ,
                           { "data\\pictures\\S640X480.bmp" } ,
                           { "data\\pictures\\S800X600.bmp" } ,
                           { "" }
};

char    DynamicScoreNames[ 64 ];

char    StatsNames[8][64] ={    
                           { "data\\pictures\\T320X200.bmp" } ,
                           { "data\\pictures\\T320X240.bmp" } ,
                           { "data\\pictures\\T320X400.bmp" } ,
                           { "data\\pictures\\T512X384.bmp" } ,
                           { "data\\pictures\\T640X400.bmp" } ,
                           { "data\\pictures\\T640X480.bmp" } ,
                           { "data\\pictures\\T800X600.bmp" } ,
                           { "" }
};




/*-------------------------------------------------------------------
        Positions of stuff to go on the panel....
-------------------------------------------------------------------*/
int16   ModeCase = 0;
uint16  PrimaryChanged;
uint16  SecondaryChanged;
uint16  ShieldChanged;
uint16  HullChanged;
uint16  PowerChanged;
uint16  PrimaryNumChanged;
uint16  SecondaryNumChanged;

int     PrimaryWeaponShowX;
int     PrimaryWeaponShowY;
int     PrimaryWeaponTextX;
int     PrimaryWeaponTextY;
int     SecondaryWeaponShowX;
int     SecondaryWeaponShowY;
int     SecondaryWeaponTextX;
int     SecondaryWeaponTextY;
int     PanelShieldPosX;
int     PanelShieldPosY;
int     PanelHullPosX;
int     PanelHullPosY;
int     PanelShieldTextPosX;
int     PanelShieldTextPosY;
int     PanelHullTextPosX;
int     PanelHullTextPosY;
int     PanelShieldBarPosX;
int     PanelShieldBarPosY;
int     PanelHullBarPosX;
int     PanelHullBarPosY;
int     PrimaryWeaponNumX;
int     PrimaryWeaponNumY;
int     SecondaryWeaponNumX;
int     SecondaryWeaponNumY;
int     PanelPowerPosX;
int     PanelPowerPosY;  

int     WeaponSizeX;
int     WeaponSizeY;

void FillInPanelPositions()
{
    if( ModeCase != -1 )
    {
        PrimaryChanged = (uint16) -1;
        HullChanged = (uint16) -1;
        ShieldChanged = (uint16) -1;
        PowerChanged = (uint16) -1;     
        PrimaryNumChanged = (uint16) -1;        
        SecondaryNumChanged = (uint16) -1;      
        
        WeaponSizeX = (int) ceil(36.0F * ModeScaleX[ModeCase]);
        WeaponSizeY = (int) ceil(37.0F * ModeScaleY[ModeCase]);
        PrimaryWeaponShowX = (int) floor( ( ModesX[ModeCase] * 0.5F ) - ( 149.0F * ModeScaleX[ModeCase] ) );
        PrimaryWeaponShowY = (int) floor( ( 6.0F * ModeScaleY[ModeCase] ) );
        SecondaryChanged = (uint16) -1;
        SecondaryWeaponShowX = (int) floor( ( ModesX[ModeCase] * 0.5F ) + ( 113.0F * ModeScaleX[ModeCase] ) );
        SecondaryWeaponShowY = (int) floor( ( 6.0F * ModeScaleY[ModeCase] ) );

        PanelShieldBarPosX = ( int ) ( ( PanelVisibleX[ModeCase] * 0.5F ) - ( 80.0F * ModeScaleX[ModeCase] ) );
        PanelShieldBarPosY = (int) ( PanelVisibleY[ModeCase] - ( 16.0F * ModeScaleY[ModeCase] ) );
        PanelShieldPosX = ( int ) ( ( PanelVisibleX[ModeCase] * 0.5F ) - ( 28.0F * ModeScaleX[ModeCase] ) );
        PanelShieldPosY = (int) ( PanelVisibleY[ModeCase] - ( 17.0F * ModeScaleY[ModeCase] ) );
        PanelShieldTextPosX = ( int ) ( ( PanelVisibleX[ModeCase] * 0.5F ) - ( 98.0F * ModeScaleX[ModeCase] ) );
        PanelShieldTextPosY = (int) ( PanelVisibleY[ModeCase] - ( 17.0F * ModeScaleY[ModeCase] ) );

        PanelHullBarPosX = ( int ) ( ( PanelVisibleX[ModeCase] * 0.5F ) + ( 28.0F * ModeScaleX[ModeCase] ) );
        PanelHullBarPosY = (int) ( PanelVisibleY[ModeCase] - ( 16.0F * ModeScaleY[ModeCase] ) );
        PanelHullPosX = ( int ) ( ( PanelVisibleX[ModeCase] * 0.5F ) + ( 12.0F * ModeScaleX[ModeCase] ) );
        PanelHullPosY = (int) ( PanelVisibleY[ModeCase] - ( 17.0F * ModeScaleY[ModeCase] ) );
        PanelHullTextPosX = ( int ) ( ( PanelVisibleX[ModeCase] * 0.5F ) + ( 86.0F * ModeScaleX[ModeCase] ) );
        PanelHullTextPosY = (int) ( PanelVisibleY[ModeCase] - ( 17.0F * ModeScaleY[ModeCase] ) );

        PrimaryWeaponTextX = (int) ( ( PanelVisibleX[ModeCase] * 0.5F ) - ( 44.0F * ModeScaleX[ModeCase] ) );
        PrimaryWeaponTextY = (int) ( PanelVisibleY[ModeCase] - ( 45.0F * ModeScaleY[ModeCase] ) );
        SecondaryWeaponTextX = (int) ( ( PanelVisibleX[ModeCase] * 0.5F ) + ( 29.0F * ModeScaleX[ModeCase] ) );
        SecondaryWeaponTextY = (int) ( PanelVisibleY[ModeCase] - ( 45.0F * ModeScaleY[ModeCase] ) );

        PrimaryWeaponNumX = (int) ( ( PanelVisibleX[ModeCase] * 0.5F ) - ( 44.0F * ModeScaleX[ModeCase] ) );
        PrimaryWeaponNumY = (int) ( PanelVisibleY[ModeCase] - ( 39.0F * ModeScaleY[ModeCase] ) );
        SecondaryWeaponNumX = (int) ( ( PanelVisibleX[ModeCase] * 0.5F ) + ( 29.0F * ModeScaleX[ModeCase] ) );
        SecondaryWeaponNumY = (int) ( PanelVisibleY[ModeCase] - ( 39.0F * ModeScaleY[ModeCase] ) );

        
        PanelPowerPosX = (int) ( ( PanelVisibleX[ModeCase] * 0.5F ) - ( (FontWidth*7)>>1 ) );
        PanelPowerPosY = (int) ( PanelVisibleY[ModeCase] - ( 38 *ModeScaleY[ModeCase] ) );
    
    }
}
    
/*-------------------------------------------------------------------
        Off Screen Sufaces...Used to Blit to screen...
-------------------------------------------------------------------*/
LPDIRECTDRAWSURFACE     lpDDSOne;       // crosshair
LPDIRECTDRAWSURFACE     lpDDSTwo = NULL;       // Font Bitmap
LPDIRECTDRAWSURFACE     lpDDSThree;     // Panel
LPDIRECTDRAWSURFACE     lpDDSFour;     // Panel Contents

//LPDIRECTDRAWSURFACE     lpDDSOverlay;     // Panel
DDCOLORKEY ddcolorkey;

LPDIRECT3DMATERIAL lpBmat;      // a Material for the Background clearing

MLOADHEADER Mloadheader;
BOOL TestTransformClip(LPDIRECT3DVIEWPORT lpView);

MCLOADHEADER MCloadheader;                  //  inner skin collision map...
MCLOADHEADER MCloadheadert0;                //  0 thickness collision map...

extern  LPDIRECT3DEXECUTEBUFFER Portal_lpD3DExBuf;

extern  uint16          FirstFmPolyUsed;
extern  uint16          FirstPolyUsed;
extern  uint16          FirstLineUsed;
extern  uint16          FirstScrPolyUsed;
extern  GLOBALSHIP      Ships[MAX_PLAYERS+1];
extern  BYTE            WhoIAm;
extern  BYTE            Current_Camera_View;        // which object is currently using the camera view....
extern  BOOL            RemoteCameraActive;

extern  int16           ShowPortal;
extern  int16           ShowSkin;
extern  int16                   NamesAreLegal;
extern  SHORTNAMETYPE           Names;  // all the players short Names....

BOOL ServerMainGame(LPDIRECT3DDEVICE lpDev, LPDIRECT3DVIEWPORT lpView );

BOOL MainGame(LPDIRECT3DDEVICE lpDev, LPDIRECT3DVIEWPORT lpView );

void Build_View();
BOOL    Disp3dPanel( LPDIRECT3DDEVICE lpDev, LPDIRECT3DVIEWPORT lpView );
BOOL DispTracker( LPDIRECT3DDEVICE lpDev, LPDIRECT3DVIEWPORT lpView );

/**************************************************************************
  DirectInput Globals
 **************************************************************************/
LPDIRECTINPUT                   lpdi = NULL;
LPDIRECTINPUTDEVICE             lpdiMouse = NULL;
LPDIRECTINPUTDEVICE             lpdiKeyboard = NULL;
LPDIRECTINPUTDEVICE             lpdiBufferedKeyboard = NULL;
LPDIRECTINPUTDEVICE2            lpdiJoystick[MAX_JOYSTICKS];
DIDEVCAPS                       diJoystickCaps[MAX_JOYSTICKS];
int                             Num_Joysticks;



/*-------------------------------------------------------------------
    Global Variables
-------------------------------------------------------------------*/   
#define Near    ( 100.0F * GLOBAL_SCALE )
//#define Far       ( 65535.0F * GLOBAL_SCALE )
#define Far     ( 49152.0F * GLOBAL_SCALE )
#define MinNear ( 50.0F * GLOBAL_SCALE )

D3DMATRIX proj = {
    D3DVAL(2.0), D3DVAL(0.0), D3DVAL(0.0), D3DVAL(0.0),
    D3DVAL(0.0), D3DVAL(2.0), D3DVAL(0.0), D3DVAL(0.0),
    D3DVAL(0.0), D3DVAL(0.0), D3DVAL(Far/(Far-Near)), D3DVAL(1.0),
    D3DVAL(0.0), D3DVAL(0.0), D3DVAL(-Far*Near/(Far-Near)), D3DVAL(0.0) };

D3DMATRIX panelproj = {
    D3DVAL(2.0), D3DVAL(0.0), D3DVAL(0.0), D3DVAL(0.0),
    D3DVAL(0.0), D3DVAL(2.0), D3DVAL(0.0), D3DVAL(0.0),
    D3DVAL(0.0), D3DVAL(0.0), D3DVAL(Far/(Far-Near)), D3DVAL(1.0),
    D3DVAL(0.0), D3DVAL(0.0), D3DVAL(-Far*Near/(Far-Near)), D3DVAL(0.0) };

D3DMATRIX trackerproj = {
    D3DVAL(2.0), D3DVAL(0.0), D3DVAL(0.0), D3DVAL(0.0),
    D3DVAL(0.0), D3DVAL(2.0), D3DVAL(0.0), D3DVAL(0.0),
    D3DVAL(0.0), D3DVAL(0.0), D3DVAL(Far/(Far-Near)), D3DVAL(1.0),
    D3DVAL(0.0), D3DVAL(0.0), D3DVAL(-Far*Near/(Far-Near)), D3DVAL(0.0) };

MATRIX  ProjMatrix = {
    D3DVAL(2.0), D3DVAL(0.0), D3DVAL(0.0), D3DVAL(0.0),
    D3DVAL(0.0), D3DVAL(2.0), D3DVAL(0.0), D3DVAL(0.0),
    D3DVAL(0.0), D3DVAL(0.0), D3DVAL(Far/(Far-Near)), D3DVAL(1.0),
    D3DVAL(0.0), D3DVAL(0.0), D3DVAL(-Far*Near/(Far-Near)), D3DVAL(0.0) };


    VECTOR  SlideLeft   = { -1.0F, 0.0F, 0.0F };
    VECTOR  SlideRight  = { 1.0F, 0.0F, 0.0F };
    VECTOR  SlideUp     = { 0.0F, 1.0F, 0.0F };
    VECTOR  SlideDown   = { 0.0F, -1.0F, 0.0F };
    VECTOR  Forward     = { 0.0F, 0.0F, 1.0F };
    VECTOR  Backward    = { 0.0F, 0.0F,-1.0F };
    VECTOR  NullVector  = { 0.0F, 0.0F, 0.0F };

    VECTOR  Camera_Dir = { 0.0F, 0.0F,0.0F };


    D3DLIGHT light;


/*-------------------------------------------------------------------
-------------------------------------------------------------------*/
static D3DEXECUTEDATA d3dExData;
static D3DEXECUTEBUFFERDESC debDesc;

/*
 * Global projection, view, world and identity matricies
 */
D3DMATRIXHANDLE hProj;
D3DMATRIXHANDLE hView;
D3DMATRIXHANDLE hWorld;
D3DMATRIX view;
D3DMATRIX identity = {
    D3DVAL(1.0), D3DVAL(0.0), D3DVAL(0.0), D3DVAL(0.0),
    D3DVAL(0.0), D3DVAL(1.0), D3DVAL(0.0), D3DVAL(0.0),
    D3DVAL(0.0), D3DVAL(0.0), D3DVAL(1.0), D3DVAL(0.0),
    D3DVAL(0.0), D3DVAL(0.0), D3DVAL(0.0), D3DVAL(1.0)
};
MATRIX Identity = {
    D3DVAL(1.0), D3DVAL(0.0), D3DVAL(0.0), D3DVAL(0.0),
    D3DVAL(0.0), D3DVAL(1.0), D3DVAL(0.0), D3DVAL(0.0),
    D3DVAL(0.0), D3DVAL(0.0), D3DVAL(1.0), D3DVAL(0.0),
    D3DVAL(0.0), D3DVAL(0.0), D3DVAL(0.0), D3DVAL(1.0)
};


D3DMATRIX world = {
    D3DVAL(1.0), D3DVAL(0.0), D3DVAL(0.0), D3DVAL(0.0),
    D3DVAL(0.0), D3DVAL(1.0), D3DVAL(0.0), D3DVAL(0.0),
    D3DVAL(0.0), D3DVAL(0.0), D3DVAL(1.0), D3DVAL(0.0),
    D3DVAL(0.0), D3DVAL(0.0), D3DVAL(0.0), D3DVAL(1.0)
};

BOOL ZClearsOn = TRUE;
BOOL g_OddFrame = FALSE;


BOOL SetZProj( void )
{
    float Scale, NewNear;

    if( hfov > START_FOV )
    {
        Scale = ( ( MAX_FOV - hfov ) / ( MAX_FOV - START_FOV ) );
        NewNear = ( MinNear + ( ( Near - MinNear ) * Scale ) );
        proj._33 = D3DVAL(Far/(Far-NewNear));
        proj._43 = D3DVAL(-Far*NewNear/(Far-NewNear));
    }
    else
    {
        proj._33 = D3DVAL(Far/(Far-Near));
        proj._43 = D3DVAL(-Far*Near/(Far-Near));
    }

#ifdef Z_TRICK
    if( g_OddFrame )
    {
        proj._33 = ( 1.0f - ( 0.5f * proj._33 ) );
        proj._43 *= -0.5f;
    }else
    {
        proj._33 *= 0.5f;
        proj._43 *= 0.5f;
    }
    ProjMatrix._33 = proj._33;
    ProjMatrix._43 = proj._43;
    if (lpD3Ddev->lpVtbl->SetMatrix(lpD3Ddev, hProj, &proj) != D3D_OK)
    {
        return FALSE;
    }
#endif
    return TRUE;
}


SetFOV( float fov )
{
    HRESULT rval;
    float screen_width, screen_height;
    float Scale, NewNear;

    if ( fov <= 1.0F || fov >= 150.0F )
        fov = hfov;
    memset(&viewport, 0, sizeof(D3DVIEWPORT));
    viewport.dwSize = sizeof(D3DVIEWPORT);
    rval = d3dapp->lpD3DViewport->lpVtbl->GetViewport(d3dapp->lpD3DViewport, &viewport);
    if (rval != D3D_OK) {
        Msg( "GetViewport failed.\n%s", D3DAppErrorToString(rval) );
        return FALSE;
    }
    if ( d3dapp->bFullscreen )
    {
        screen_width = (float) d3dapp->ThisMode.w;
        screen_height = (float) d3dapp->ThisMode.h;
    }
    else
    {
        screen_width = (float) d3dapp->WindowsDisplay.w;
        screen_height = (float) d3dapp->WindowsDisplay.h;
    }
    pixel_aspect_ratio = screen_aspect_ratio * screen_height / screen_width;
    viewplane_distance = (float) ( viewport.dwWidth / ( 2 * tan( DEG2RAD( fov ) * 0.5 ) ) );
    proj._11 = 2 * viewplane_distance / viewport.dwWidth;
    proj._22 = 2 * viewplane_distance / ( viewport.dwHeight / pixel_aspect_ratio );

    if( fov > START_FOV )
    {
        Scale = ( ( MAX_FOV - fov ) / ( MAX_FOV - START_FOV ) );
        NewNear = ( MinNear + ( ( Near - MinNear ) * Scale ) );
        proj._33 = D3DVAL(Far/(Far-NewNear));
        proj._34 = D3DVAL( 1.0 );
        proj._43 = D3DVAL(-Far*NewNear/(Far-NewNear));
        proj._44 = D3DVAL( 0.0 );
    }
    else
    {
        proj._33 = D3DVAL(Far/(Far-Near));
        proj._34 = D3DVAL( 1.0 );
        proj._43 = D3DVAL(-Far*Near/(Far-Near));
        proj._44 = D3DVAL( 0.0 );
    }

#ifdef Z_TRICK
    if ( !ZClearsOn )
    {
        if( g_OddFrame )
        {
            proj._33 = ( 1.0f - ( 0.5f * proj._33 ) );
            proj._43 *= -0.5f;
        }else
        {
            proj._33 *= 0.5f;
            proj._43 *= 0.5f;
        }
    }
#endif

    ProjMatrix._11 = proj._11;
    ProjMatrix._22 = proj._22;
    ProjMatrix._33 = proj._33;
    ProjMatrix._34 = proj._34;
    ProjMatrix._43 = proj._43;
    ProjMatrix._44 = proj._44;

    hfov = fov;
    if (lpD3Ddev->lpVtbl->SetMatrix(lpD3Ddev, hProj, &proj) != D3D_OK)
    {
            return FALSE;
    }
    return TRUE;
}


void SetViewportError( char *where, D3DVIEWPORT *vp, HRESULT rval )
{
    static char msg[1024];

    sprintf( msg, "SetViewport failed in %s.\n"
        "%s\n"
        "size=%d(=sizeof()%d?)\n"
        "xpos=%d ypos=%d\n"
        "width=%d height=%d\n"
        "xscale=%f yscale=%f\n"
        "xmax=%f ymax=%f\n"
        "zmin=%f zmax=%f\n",
        where,
        D3DAppErrorToString( rval ),
        vp->dwSize, sizeof( *vp ),
        vp->dwX, vp->dwY,
        vp->dwWidth, vp->dwHeight,
        vp->dvScaleX, vp->dvScaleY,
        vp->dvMaxX, vp->dvMaxY,
        vp->dvMinZ, vp->dvMaxZ );
    Msg( msg );
}

BOOL
ResizeViewport( float scale )
{
    HRESULT rval;
    int left, top;
    int width, height;
    int maxwidth, maxheight;
    BOOL    NewDrawPanel;
    BOOL    NewDrawSimplePanel;
    
    InsideResizeViewport = TRUE;

    scale = 1.0F;

    /*
     * Setup the viewport for specified viewing area
     */
    memset(&viewport, 0, sizeof(D3DVIEWPORT));
    viewport.dwSize = sizeof(D3DVIEWPORT);
    rval = d3dapp->lpD3DViewport->lpVtbl->GetViewport(d3dapp->lpD3DViewport, &viewport);
    if (rval != D3D_OK) {
        Msg( "GetViewport failed.\n%s", D3DAppErrorToString(rval) );
        return FALSE;
    }
    maxwidth = d3dapp->szClient.cx;


//  DrawSimplePanel = FALSE;
    if( scale < 1.0F )
    {
        NewDrawSimplePanel = TRUE;
    }
    if( scale >= 1.0F )
    {
        NewDrawSimplePanel = FALSE;
    }
    
    if( NewDrawSimplePanel )
    {
        maxheight = d3dapp->szClient.cy - PanelVisibleY[ModeCase];
    }else{
        maxheight = d3dapp->szClient.cy;
    }
    if ( scale < 1.01F )
    {
        width = (int) floor( maxwidth * scale );
        if ( width < MIN_VIEWPORT_WIDTH )
        {
            width = MIN_VIEWPORT_WIDTH;
            scale = (float) width / maxwidth;
        }
        height = (int) floor( maxheight * scale );

        NewDrawPanel = FALSE;

        left = ( ( maxwidth - width ) >> 1 ) & ~1;
        top = ( ( maxheight - height ) >> 1 ) & ~1;
    }
    else
    {
        width = maxwidth;
        height = maxheight;
        if ( scale > 1.11F )
        {
            NewDrawPanel = TRUE;
            scale = 1.2F;
        }
        else
        {
            NewDrawPanel = FALSE;
        }
        left = 0;
        top = 0;
    }
    CurrentViewportScale = scale;

    // This disables the 3d panel...
    NewDrawPanel = DrawPanel;

    
    if( (NewDrawPanel != DrawPanel) || (NewDrawSimplePanel != DrawSimplePanel) )
    {
//      ReleaseView();
//      DrawPanel = NewDrawPanel;
//      DrawSimplePanel = NewDrawSimplePanel;
//      InitView();
    }
    
    
    viewport.dwX = left;
    viewport.dwY = top;
    viewport.dwWidth = width;
    viewport.dwHeight = height;
    viewport.dvScaleX = viewport.dwWidth / (float)2.0;
    viewport.dvScaleY = viewport.dwHeight / (float)2.0;
    viewport.dvMaxX = (float)D3DDivide(D3DVAL(viewport.dwWidth),
                                       D3DVAL(2 * viewport.dvScaleX));
    viewport.dvMaxY = (float)D3DDivide(D3DVAL(viewport.dwHeight),
                                       D3DVAL(2 * viewport.dvScaleY));
    rval = d3dapp->lpD3DViewport->lpVtbl->SetViewport(d3dapp->lpD3DViewport, &viewport);
    if (rval != D3D_OK) {
#ifdef DEBUG_VIEWPORT
        SetViewportError( "ResizeViewport", &viewport, rval );
#else
        Msg("SetViewport failed.\n%s", D3DAppErrorToString(rval));
#endif
        return FALSE;
    }
    SetFOV( hfov );

    // clear viewport
    D3DAppIClearBuffers();

    return TRUE;
}
BOOL
FullScreenViewport()
{
    HRESULT rval;
    int left, top;
    int width, height;
    int maxwidth, maxheight;

    /*
     * Setup the viewport for specified viewing area
     */
    memset(&viewport, 0, sizeof(D3DVIEWPORT));
    viewport.dwSize = sizeof(D3DVIEWPORT);
    rval = d3dapp->lpD3DViewport->lpVtbl->GetViewport(d3dapp->lpD3DViewport, &viewport);
    if (rval != D3D_OK) {
        Msg( "GetViewport failed.\n%s", D3DAppErrorToString(rval) );
        return FALSE;
    }
    maxwidth = d3dapp->szClient.cx;
    maxheight = d3dapp->szClient.cy;
    width = maxwidth;
    height = maxheight;
    left = 0;
    top = 0;

    viewport.dwX = left;
    viewport.dwY = top;
    viewport.dwWidth = width;
    viewport.dwHeight = height;
    viewport.dvScaleX = viewport.dwWidth / (float)2.0;
    viewport.dvScaleY = viewport.dwHeight / (float)2.0;
    viewport.dvMaxX = (float)D3DDivide(D3DVAL(viewport.dwWidth),
                                       D3DVAL(2 * viewport.dvScaleX));
    viewport.dvMaxY = (float)D3DDivide(D3DVAL(viewport.dwHeight),
                                       D3DVAL(2 * viewport.dvScaleY));
    rval = d3dapp->lpD3DViewport->lpVtbl->SetViewport(d3dapp->lpD3DViewport, &viewport);
    if (rval != D3D_OK) {
#ifdef DEBUG_VIEWPORT
        SetViewportError( "FullScreenViewport", &viewport, rval );
#else
        Msg("SetViewport failed.\n%s", D3DAppErrorToString(rval));
#endif
        return FALSE;
    }
    SetFOV( hfov );
    // clear viewport
    D3DAppIClearBuffers();
    D3DAppIClearBuffers();
    return TRUE;
}


void ReallyShowCursor( BOOL show )
{
    if ( show )
    {
        while ( ShowCursor( TRUE ) < 0 )
            ; // try again
    }
    else
    {
        while ( ShowCursor( FALSE ) >= 0 )
            ; // try again
    }
}

void
SetCursorClip( void )
{
    HRESULT         err;

    if ( !d3dapp )
    {
        DebugPrintf( "SetCursorClip: d3dapp is NULL\n" );
        ClipCursor( NULL );
        ReallyShowCursor( TRUE );
        return;
    }
    cursorclip.left = d3dapp->pClientOnPrimary.x + d3dapp->szClient.cx / 2;
    cursorclip.top = d3dapp->pClientOnPrimary.y + d3dapp->szClient.cy / 2;
    cursorclip.right = cursorclip.left + 1;
    cursorclip.bottom = cursorclip.top + 1;
    if ( cursorclipped )
    {
        if ( lpdiMouse )
        {
            err = IDirectInputDevice_Acquire(lpdiMouse);
        }
        if ( lpdiKeyboard )
        {
            err = IDirectInputDevice_Acquire(lpdiKeyboard);
        }
        if ( lpdiBufferedKeyboard )
        {
            err = IDirectInputDevice_Acquire(lpdiBufferedKeyboard);
        }
        DebugPrintf( "SetCursorClip: cursor is clipped\n" );
        ClipCursor( &cursorclip );
        SetCursorPos( cursorclip.left, cursorclip.top );
        ReallyShowCursor( FALSE );
    }
    else
    {
        if ( lpdiMouse )
        {
            err = IDirectInputDevice_Unacquire(lpdiMouse);
        }
        if ( lpdiKeyboard )
        {
            err = IDirectInputDevice_Unacquire(lpdiKeyboard);
        }
        if ( lpdiBufferedKeyboard )
        {
            err = IDirectInputDevice_Unacquire(lpdiBufferedKeyboard);
        }
        DebugPrintf( "SetCursorClip: cursor is not clipped\n" );
        ClipCursor( NULL );
        ReallyShowCursor( TRUE );
    }
}

void
OverrideDefaults(Defaults* defaults)
{
    strcpy(defaults->Name, "Forsaken");
}

static BOOL LevelValid( char *level )
{
    uint16 i;
    
    if ( !IsPseudoHost )
        return TRUE;

    for ( i = 0; i < NumServerLevels; i++ )
    {
        if ( !_strnicmp( level, ServerLevelNames[ i ], 7 ) )    // 8th char could be null terminator
            return TRUE;
    }

    return FALSE;
}

BOOL InitLevels( char *levels_list )
{
    int j;
#if !defined( SHAREWARE ) && !defined( LIMITED_LEVELS )
    FILE *f;
    char *short_start;
    int len;
    char TempFilename[ 256 ];
    char levels_file[ 256 ];
#endif
    char * LevelPath = "";
#if defined( SHAREWARE_MAGAZINE ) || defined( SHAREWARE_INTERNET )
    char *singleplayer_levels[] =
    {
        "volcano",
        "subway",
        NULL
    };
    char *multiplayer_levels[] =
    {
        "biodome",
        NULL
    };
    char *demo_levels[] =
    {
        "biodome",
        NULL
    };
    char **levels_table = NULL;
#elif defined( SHAREWARE_RETAIL ) || defined( SHAREWARE )
    char *singleplayer_levels[] =
    {
        "volcano",
        "subway",
        NULL
    };
    char *multiplayer_levels[] =
    {
        "biodome",
        NULL
    };
    char *demo_levels[] =
    {
        "biodome",
        NULL
    };
    char **levels_table = NULL;
#elif defined( LIMITED_LEVELS )
    char *singleplayer_levels[] =
    {
        NULL
    };
    char *multiplayer_levels[] =
    {
        "biodome",
        NULL
    };
    char *demo_levels[] =
    {
        "biodome",
        NULL
    };
    char **levels_table = NULL;

#elif defined( WIN98SHAREWARE )
    char *singleplayer_levels[] =
    {
        "vol2 5",
        "asubchb 9",
        NULL
    };
    char *multiplayer_levels[] =
    {
        "ship 10",
        NULL
    };
    char *splash_levels[] =
    {
        "endscene",
        "probeworld",
        "accworld",
        NULL
    };
    char **levels_table = NULL;

#elif defined( FINAL_RELEASE )
    char *singleplayer_levels[] =
    {
        "vol2 5",
        "asubchb 9",
        "nps-sp01 6",
        "thermal 3",
        "fedbankv 2",
        "pship 8",
        "spc-sp01 4",
        "bio-sphere 9",
        "nukerf 3",
        "capship 7",
        "space 8",
        "high 10",
        "military 5",
        "azt-sp01 3",
        "azchb 6",
        NULL
    };
    char *multiplayer_levels[] =
    {
        "biodome 6",
        "alpha 4",
        "ship 10",
        "sewer 3",
        "nuke-mp 9",
        "nedwheel 2",
        "tube 8",
        "oldtemple 9",
        "refinery 3",
        "cruise 7",
        "arena 8",
        "pandora 6",
        "midpand 3",
        NULL
    };
    char *splash_levels[] =
    {
        "endscene",
        "probeworld",
        "accworld",
        NULL
    };
    char **levels_table = NULL;
#endif

    CurrentLevelsList = levels_list;
    OriginalLevels = FALSE;

#if defined( SHAREWARE ) || defined( LIMITED_LEVELS )
    NumLevels = 0;
    levels_table = NULL;
    if ( !strcmp( levels_list, SINGLEPLAYER_LEVELS ) )
    {
        levels_table = singleplayer_levels;
    }
    else if ( !strcmp( levels_list, MULTIPLAYER_LEVELS ) )
    {
        levels_table = multiplayer_levels;
    }
    else if ( !strcmp( levels_list, DEMO_LEVELS ) )
    {
        levels_table = demo_levels;
    }
    if ( levels_table )
    {
        LevelPath = &normdata_path[ 0 ];
        NumLevels = 0;
        for ( j = 0; levels_table[ j ]; j++ )
        {
            strncpy( ShortLevelNames[ NumLevels ], levels_table[ NumLevels ], sizeof( ShortLevelNames[ NumLevels ] ) );
            ShortLevelNames[ NumLevels ][ sizeof( ShortLevelNames[ NumLevels ] ) - 1 ] = 0;

            if ( LevelValid( ShortLevelNames[ NumLevels ] ) )
            {
                CDTrack[ NumLevels ] = 2 + NumLevels;
                sprintf( LevelNames[ NumLevels ], "%slevels\\%s\\%s.mxv", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                sprintf( CollisionNames[ NumLevels ], "%slevels\\%s\\%s.mc", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                sprintf( CollisionZNames[ NumLevels ], "%slevels\\%s\\%sz.mc", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                sprintf( BspNames[ NumLevels ], "%slevels\\%s\\%s.bsp", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                sprintf( BspZNames[ NumLevels ], "%slevels\\%s\\%sz.bsp", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                sprintf( ZoneNames[ NumLevels ], "%slevels\\%s\\%s.zon", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                sprintf( WaterNames[ NumLevels ], "%slevels\\%s\\%s.wat", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                sprintf( TextNames[ NumLevels ], "%slevels\\%s\\%s.txt", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                sprintf( MsgNames[ NumLevels ], "%slevels\\%s\\%s.msg", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                sprintf( ExternalForceNames[ NumLevels ], "%slevels\\%s\\%s.gf", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                sprintf( TeleportNames[ NumLevels ], "%slevels\\%s\\%s.tel", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );

                sprintf( MissionTextNames[ NumLevels ], "%slevels\\%s\\%s.mis", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                sprintf( MissionTextPics[ NumLevels ], "levels\\%s\\%s.ppm", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );

                NumLevels++;
            }
        }
    }
#else
    if ( !levels_list )
        levels_list = LEVELSFILE;
    sprintf( levels_file, "levels\\%s", levels_list );
#ifndef FINAL_RELEASE
    if ( use_level_path )
    {
        Add_Path( level_path, levels_file, &TempFilename[ 0 ] );
        f = fopen( TempFilename, "r" );
        if ( !f )
            return FALSE;
        j = 0;
        while ( j < MAXLEVELS )
        {
            if ( !fgets( level_names[ j ], sizeof( level_names[ j ] ), f ) )
                break;
            len = strlen( level_names[ j ] );
            if ( !len )
                break;
            if ( level_names[ j ][ len - 1 ] == '\n' )
                level_names[ j ][ len - 1 ] = 0;
            short_start = strrchr( level_names[ j ], '\\' );
            if ( short_start )
                short_start++;
            else
                short_start = level_names[ j ];
            strncpy( ShortLevelNames[ j ], short_start, sizeof( ShortLevelNames[ j ] ) );
            ShortLevelNames[ j ][ sizeof( ShortLevelNames[ j ] ) - 1 ] = 0;

            if ( LevelValid( ShortLevelNames[ j ] ) )
            {
                sprintf( LevelNames[ j ], "%s.mxv", level_names[ j ] );
                sprintf( CollisionNames[ j ], "%s.mc",  level_names[ j ] );
                sprintf( CollisionZNames[ j ], "%sz.mc", level_names[ j ] );
                sprintf( BspNames[ j ], "%s.bsp",  level_names[ j ] );
                sprintf( BspZNames[ j ], "%sz.bsp",  level_names[ j ] );
                sprintf( ZoneNames[ j ], "%s.zon",  level_names[ j ] );
                sprintf( WaterNames[ j ], "%s.Wat",  level_names[ j ] );
                sprintf( TextNames[ j ], "%s.txt",  level_names[ j ] );
                sprintf( MsgNames[ j ], "%s.msg",  level_names[ j ] );
                sprintf( ExternalForceNames[ j ], "%s.gf",  level_names[ j ] );
                sprintf( TeleportNames[ j ], "%s.tel",  level_names[ j ] );

                sprintf( MissionTextNames[ j ], "%slevels\\%s\\%s.mis", LevelPath, ShortLevelNames[ j ], ShortLevelNames[ j ] );
                sprintf( MissionTextPics[ j ], "levels\\%s\\%s.ppm", LevelPath, ShortLevelNames[ j ], ShortLevelNames[ j ] );

                j++;
            }
        }
        NumLevels = j;
        fclose( f );
    }
    else
#endif
    {
#ifndef WIN98SHAREWARE
        if( use_data_path )
        {
            Add_Path( &data_path[ 0 ], levels_file, &TempFilename[ 0 ] );
            f = fopen( &TempFilename[ 0 ], "r" );
#if 0
            if( f == NULL )
            {
                Add_Path( &normdata_path[ 0 ], levels_file, &TempFilename[ 0 ] );
                f = fopen( &TempFilename[ 0 ], "r" );
                LevelPath = &normdata_path[ 0 ];
            }
            else
#endif
            {
                LevelPath = &data_path[ 0 ];
            }
        }
        else
        {
            Add_Path( &normdata_path[ 0 ], levels_file, &TempFilename[ 0 ] );
            f = fopen( &TempFilename[ 0 ], "r" );
            LevelPath = &normdata_path[ 0 ];
        }

        if ( f )
#else
        if ( 0 )    // fucking cheesy, but quick & easy!! - Phil
#endif
        {
            j = 0;
            while ( j < MAXLEVELS && fscanf( f, " %s", ShortLevelNames[ j ] ) == 1 )
            {
                if ( LevelValid( ShortLevelNames[ j ] ) )
                {
                    if (!fscanf( f, " %d", &CDTrack[ j ] ))
                        CDTrack[ j ] = 2;
#ifdef FINAL_RELEASE
                    LevelPath = data_path;
#endif
                    sprintf( LevelNames[ j ], "%slevels\\%s\\%s.mxv", LevelPath, ShortLevelNames[ j ], ShortLevelNames[ j ] );
#ifdef FINAL_RELEASE
                    // added check for level to patch
                    if ( !File_Exists( LevelNames[ j ] ) )
                    {
                        // level not on HD
                        LevelPath = normdata_path;
                        sprintf( LevelNames[ j ], "%slevels\\%s\\%s.mxv", LevelPath, ShortLevelNames[ j ], ShortLevelNames[ j ] );
                        // added check for level on CD to patch
                        if ( !File_Exists( LevelNames[ j ] ) )
                        {
                            continue; // level not on CD or CD not present
                        }
                    }
#endif
                    sprintf( CollisionNames[ j ], "%slevels\\%s\\%s.mc", LevelPath, ShortLevelNames[ j ], ShortLevelNames[ j ] );
                    sprintf( CollisionZNames[ j ], "%slevels\\%s\\%sz.mc", LevelPath, ShortLevelNames[ j ], ShortLevelNames[ j ] );
                    sprintf( BspNames[ j ], "%slevels\\%s\\%s.bsp", LevelPath, ShortLevelNames[ j ], ShortLevelNames[ j ] );
                    sprintf( BspZNames[ j ], "%slevels\\%s\\%sz.bsp", LevelPath, ShortLevelNames[ j ], ShortLevelNames[ j ] );
                    sprintf( ZoneNames[ j ], "%slevels\\%s\\%s.zon", LevelPath, ShortLevelNames[ j ], ShortLevelNames[ j ] );
                    sprintf( WaterNames[ j ], "%slevels\\%s\\%s.wat", LevelPath, ShortLevelNames[ j ], ShortLevelNames[ j ] );
                    sprintf( TextNames[ j ], "%slevels\\%s\\%s.txt", LevelPath, ShortLevelNames[ j ], ShortLevelNames[ j ] );
                    sprintf( MsgNames[ j ], "%slevels\\%s\\%s.msg", LevelPath, ShortLevelNames[ j ], ShortLevelNames[ j ] );
                    sprintf( ExternalForceNames[ j ], "%slevels\\%s\\%s.gf", LevelPath, ShortLevelNames[ j ], ShortLevelNames[ j ] );
                    sprintf( TeleportNames[ j ], "%slevels\\%s\\%s.tel", LevelPath, ShortLevelNames[ j ], ShortLevelNames[ j ] );

                    sprintf( MissionTextNames[ j ], "%slevels\\%s\\%s.mis", LevelPath, ShortLevelNames[ j ], ShortLevelNames[ j ] );
                    sprintf( MissionTextPics[ j ], "%slevels\\%s\\%s.ppm", LevelPath, ShortLevelNames[ j ], ShortLevelNames[ j ] );

                    j++;
                }
            }
            NumLevels = j;
            fclose( f );
        }
        else
        {
#ifdef FINAL_RELEASE
            NumLevels = 0;
            levels_table = NULL;
            if ( !strcmp( levels_list, SINGLEPLAYER_LEVELS ) )
            {
                levels_table = singleplayer_levels;
            }
            else if ( !strcmp( levels_list, MULTIPLAYER_LEVELS ) )
            {
                levels_table = multiplayer_levels;
            }
            else if ( !strcmp( levels_list, DEMO_LEVELS ) )
            {
                levels_table = multiplayer_levels;
            }
            else if ( !strcmp( levels_list, SPLASH_LEVELS ) )
            {
                levels_table = splash_levels;
            }
            if ( levels_table )
            {
                for ( j = 0; levels_table[ j ]; j++ )
                {
                    CDTrack[ NumLevels ] = 0;
                    if ( sscanf( levels_table[ j ], "%s %d", ShortLevelNames[ NumLevels ], &CDTrack[ NumLevels ] ) >= 1 )
                    {
                        LevelPath = data_path;
                        sprintf( LevelNames[ NumLevels ], "%slevels\\%s\\%s.mxv", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                        if ( !File_Exists ( LevelNames[ NumLevels ] ) )
                        {
                            LevelPath = normdata_path;
                            sprintf( LevelNames[ NumLevels ], "%slevels\\%s\\%s.mxv", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                            // added check for level on CD to patch
                            if ( !File_Exists( LevelNames[ NumLevels ] ) )
                            {
                                continue; // level not on CD or CD not present
                            }
                            LevelsOnCD = TRUE;
                        }
                        sprintf( CollisionNames[ NumLevels ], "%slevels\\%s\\%s.mc", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                        sprintf( CollisionZNames[ NumLevels ], "%slevels\\%s\\%sz.mc", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                        sprintf( BspNames[ NumLevels ], "%slevels\\%s\\%s.bsp", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                        sprintf( BspZNames[ NumLevels ], "%slevels\\%s\\%sz.bsp", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                        sprintf( ZoneNames[ NumLevels ], "%slevels\\%s\\%s.zon", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                        sprintf( WaterNames[ NumLevels ], "%slevels\\%s\\%s.wat", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                        sprintf( TextNames[ NumLevels ], "%slevels\\%s\\%s.txt", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                        sprintf( MsgNames[ NumLevels ], "%slevels\\%s\\%s.msg", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                        sprintf( ExternalForceNames[ NumLevels ], "%slevels\\%s\\%s.gf", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                        sprintf( TeleportNames[ NumLevels ], "%slevels\\%s\\%s.tel", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );

                        sprintf( MissionTextNames[ NumLevels ], "%slevels\\%s\\%s.mis", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                        sprintf( MissionTextPics[ NumLevels ], "%slevels\\%s\\%s.ppm", LevelPath, ShortLevelNames[ NumLevels ], ShortLevelNames[ NumLevels ] );
                        NumLevels++;
                    }
                }
                if ( NumLevels == j )
                    OriginalLevels = TRUE;
            }
#else
            return FALSE;
#endif
        }

    }
#endif

    if( !NumLevels ) return FALSE;

    LevelList.items = 0;
    LevelList.top_item = 0;
    LevelList.display_items = 8;
    LevelList.selected_item = 0;    // you can only ever start game on first level!
    NewLevelNum = 0;

    for (j = 0; j < NumLevels; j++)
    {
        strcpy( (char*) &LevelList.item[LevelList.items][0] , (char*) &ShortLevelNames[j][0] );
        LevelList.items++;
    }

    LoadLevelText( NULL );

    return TRUE;
}

BOOL SetMatrixViewPort( void )
{
    size_t size;
    LPVOID lpBufStart, lpInsStart, lpPointer;
    LPDIRECT3DEXECUTEBUFFER lpD3DExCmdBuf;
    D3DMATERIAL bmat;
    D3DMATERIALHANDLE hBmat;
    LPDIRECTDRAW lpDD = d3dapp->lpDD;
    LPDIRECT3D lpD3D = d3dapp->lpD3D;
    LPDIRECT3DDEVICE lpDev = d3dapp->lpD3DDevice;
    LPDIRECT3DVIEWPORT lpView = d3dapp->lpD3DViewport;

    memset(&bmat, 0, sizeof(D3DMATERIAL));
    bmat.dwSize = sizeof(D3DMATERIAL);
    bmat.dwRampSize = 1;
    if (lpD3D->lpVtbl->CreateMaterial(lpD3D, &lpBmat, NULL) != D3D_OK) {
        return FALSE;
    }
    if (lpBmat->lpVtbl->SetMaterial(lpBmat, &bmat) != D3D_OK) {
        return FALSE;
    }
    if (lpBmat->lpVtbl->GetHandle(lpBmat, lpDev, &hBmat) != D3D_OK) {
        return FALSE;
    }
    if (lpView->lpVtbl->SetBackground(lpView, hBmat) != D3D_OK) {
        return FALSE;
    }
  
   
    ticksperframe = 14.0F;
       
    /*
     * Set the view, world and projection matrices
     * Create a buffer for matrix set commands etc.
     */
    MAKE_MATRIX(lpDev, hView, identity);
    MAKE_MATRIX(lpDev, hProj, proj);
    MAKE_MATRIX(lpDev, hWorld, world);
    world = identity;
    size = 0;
    size += sizeof(D3DINSTRUCTION) * 3;
    size += sizeof(D3DSTATE) * 5;
   
       
    if (MakeExecuteBuffer( &debDesc, lpDev , &lpD3DExCmdBuf , size ) != TRUE ) return FALSE;
   
   
    /*
     * lock it so it can be filled
     */
    if (lpD3DExCmdBuf->lpVtbl->Lock(lpD3DExCmdBuf, &debDesc) != D3D_OK) return FALSE;
    
    lpBufStart = debDesc.lpData;
    memset(lpBufStart, 0, size);
    lpPointer = lpBufStart;
    
    lpInsStart = lpPointer;
    OP_STATE_TRANSFORM(3, lpPointer);
        STATE_DATA(D3DTRANSFORMSTATE_PROJECTION, hProj, lpPointer);
        STATE_DATA(D3DTRANSFORMSTATE_VIEW, hView, lpPointer);
        STATE_DATA(D3DTRANSFORMSTATE_WORLD, hWorld, lpPointer);
    OP_STATE_LIGHT(1, lpPointer);
        STATE_DATA(D3DLIGHTSTATE_AMBIENT, RGBA_MAKE(255, 255, 255, 0), lpPointer);
    OP_EXIT(lpPointer);
    /*
     * Setup the execute data describing the buffer
     */
    lpD3DExCmdBuf->lpVtbl->Unlock(lpD3DExCmdBuf);
    memset(&d3dExData, 0, sizeof(D3DEXECUTEDATA));
    d3dExData.dwSize = sizeof(D3DEXECUTEDATA);
    d3dExData.dwInstructionOffset = (ULONG) 0;
    d3dExData.dwInstructionLength = (ULONG) ((char *)lpPointer - (char*)lpInsStart);
    lpD3DExCmdBuf->lpVtbl->SetExecuteData(lpD3DExCmdBuf, &d3dExData);
    lpDev->lpVtbl->BeginScene(lpDev);
    lpDev->lpVtbl->Execute(lpDev, lpD3DExCmdBuf, lpView , D3DEXECUTE_CLIPPED);
    lpDev->lpVtbl->EndScene(lpDev);
    /*
     * We are done with the command buffer.
     */
    XRELEASE(lpD3DExCmdBuf);
   
    viewport.dwSize = sizeof(D3DVIEWPORT);
    if ((hresult = lpView->lpVtbl->GetViewport(lpView, (LPD3DVIEWPORT)&viewport)) != D3D_OK)
    {
        viewport.dwWidth = 320;
        viewport.dwHeight = 200;
    }
    lpD3Ddev = lpDev;
    if ( !initfov )
    {
        SetFOV( chosen_fov = normal_fov );
        initfov = 1;
    }

    if( InsideResizeViewport == FALSE )
    {
        InitViewport( 1.1F );
    }else{
        InsideResizeViewport = FALSE;
    }

    return TRUE;
}

struct {

    DWORD   ModeMask;
    DWORD   SourceMask;
    DWORD   DestMask;
    DWORD   Mode;
    DWORD   Source;
    DWORD   Dest;

} PreferredCaps[] = {

    { D3DPTBLENDCAPS_MODULATE,  D3DPBLENDCAPS_ONE,  D3DPBLENDCAPS_ONE,                  // Mask
        D3DTBLEND_MODULATE,     D3DBLEND_ONE,       D3DBLEND_ONE },                     // Value

    { D3DPTBLENDCAPS_MODULATEALPHA, D3DPBLENDCAPS_SRCALPHA, D3DPBLENDCAPS_SRCALPHA,     // Mask
      D3DTBLEND_MODULATEALPHA,      D3DBLEND_SRCALPHA,      D3DBLEND_SRCALPHA },        // Value

    { D3DPTBLENDCAPS_ADD,   D3DPBLENDCAPS_INVSRCALPHA,  D3DPBLENDCAPS_SRCALPHA,         // Mask
      D3DTBLEND_ADD,        D3DBLEND_INVSRCALPHA,       D3DBLEND_SRCALPHA },            // Value

    { D3DPTBLENDCAPS_MODULATEALPHA, D3DPBLENDCAPS_SRCALPHA, D3DPBLENDCAPS_INVSRCALPHA,  // Mask
      D3DTBLEND_MODULATEALPHA,      D3DBLEND_SRCALPHA,      D3DBLEND_INVSRCALPHA },     // Value

};

struct {

    DWORD   ModeMask;
    DWORD   SourceMask;
    DWORD   DestMask;
    DWORD   Mode;
    DWORD   Source;
    DWORD   Dest;

} NonPrimPreferredCaps[] = {

    { D3DPTBLENDCAPS_MODULATEALPHA, D3DPBLENDCAPS_SRCALPHA, D3DPBLENDCAPS_SRCALPHA,     // Mask
      D3DTBLEND_MODULATEALPHA,      D3DBLEND_SRCALPHA,      D3DBLEND_SRCALPHA },        // Value

    { D3DPTBLENDCAPS_MODULATE,  D3DPBLENDCAPS_ONE,  D3DPBLENDCAPS_ONE,                  // Mask
        D3DTBLEND_MODULATE,     D3DBLEND_ONE,       D3DBLEND_ONE },                     // Value

    { D3DPTBLENDCAPS_ADD,   D3DPBLENDCAPS_INVSRCALPHA,  D3DPBLENDCAPS_SRCALPHA,         // Mask
      D3DTBLEND_ADD,        D3DBLEND_INVSRCALPHA,       D3DBLEND_SRCALPHA },            // Value

    { D3DPTBLENDCAPS_MODULATEALPHA, D3DPBLENDCAPS_SRCALPHA, D3DPBLENDCAPS_INVSRCALPHA,  // Mask
      D3DTBLEND_MODULATEALPHA,      D3DBLEND_SRCALPHA,      D3DBLEND_INVSRCALPHA },     // Value
};

void    GetHardwareCaps( void )
{       
    int16                   Count;
    int16                   NumPreferredCaps;
    struct  _D3DPrimCaps *  TriCapsPtr;

/*-------------------------------------------------------------------
    Check for Culling Caps
-------------------------------------------------------------------*/
    CanCullFlag = FALSE;
    if( ( d3dappi.ThisDriver.Desc.dpcTriCaps.dwMiscCaps & D3DPMISCCAPS_CULLCCW ) &&
        ( d3dappi.ThisDriver.Desc.dpcTriCaps.dwMiscCaps & D3DPMISCCAPS_CULLNONE ) )
        CanCullFlag = TRUE;

/*-------------------------------------------------------------------
    Check for Translucency Caps
-------------------------------------------------------------------*/
    UsedStippledAlpha = FALSE;

    if( !Is3Dfx && !Is3Dfx2 )
    {
        TriCapsPtr = &d3dappi.ThisDriver.Desc.dpcTriCaps;
        NumPreferredCaps = ( sizeof( PreferredCaps ) / sizeof( PreferredCaps[ 0 ] ) );
        
        for( Count = 0; Count < NumPreferredCaps; Count++ )
        {
            if( ( TriCapsPtr->dwDestBlendCaps & PreferredCaps[ Count ].ModeMask ) &&
                ( TriCapsPtr->dwSrcBlendCaps & PreferredCaps[ Count ].SourceMask ) &&
                ( TriCapsPtr->dwDestBlendCaps & PreferredCaps[ Count ].DestMask ) )
            {
                CurrentTextureBlend = PreferredCaps[ Count ].Mode;
                CurrentSrcBlend = PreferredCaps[ Count ].Source;
                CurrentDestBlend = PreferredCaps[ Count ].Dest;
                break;
            }
        }
    }
    else
    {
        TriCapsPtr = &d3dappi.ThisDriver.Desc.dpcTriCaps;
        NumPreferredCaps = ( sizeof( NonPrimPreferredCaps ) / sizeof( NonPrimPreferredCaps[ 0 ] ) );
        
        for( Count = 0; Count < NumPreferredCaps; Count++ )
        {
            if( ( TriCapsPtr->dwDestBlendCaps & NonPrimPreferredCaps[ Count ].ModeMask ) &&
                ( TriCapsPtr->dwSrcBlendCaps & NonPrimPreferredCaps[ Count ].SourceMask ) &&
                ( TriCapsPtr->dwDestBlendCaps & NonPrimPreferredCaps[ Count ].DestMask ) )
            {
                CurrentTextureBlend = NonPrimPreferredCaps[ Count ].Mode;
                CurrentSrcBlend = NonPrimPreferredCaps[ Count ].Source;
                CurrentDestBlend = NonPrimPreferredCaps[ Count ].Dest;
                break;
            }
        }
    }

    if( Count == NumPreferredCaps )
    {
        UsedStippledAlpha = TRUE;
        if( d3dappi.ThisDriver.Desc.dpcTriCaps.dwShadeCaps & D3DPSHADECAPS_ALPHAFLATBLEND )
            UsedStippledAlpha = FALSE;
        if( d3dappi.ThisDriver.Desc.dpcTriCaps.dwShadeCaps & D3DPSHADECAPS_ALPHAGOURAUDBLEND )
            UsedStippledAlpha = FALSE;
    }

    bPolySort = FALSE;
//  if( PowerVR_Overide || (PowerVR = IsPowerVRD3DDevice() ) )
    if( PowerVR_Overide )
    {
        PowerVR = TRUE;
        //PowerVr
        CurrentTextureBlend = D3DTBLEND_MODULATEALPHA;
        CurrentDestBlend = D3DBLEND_INVSRCALPHA;
        CurrentSrcBlend = D3DBLEND_SRCALPHA;
    }
}



float   HealthCount = 0.0F;
int PowerSizes[6] = { 0 , 4 , 16 , 24 , 40 , 56 };
void TestBlt()
{
#if 0
    RECT    src;
    HRESULT ddrval;
    RECT    dest;
    DDBLTFX fx;
    int x;
    int y;
#endif
    int energy;

//  while( 1 )
    {
        if( DrawCrosshair && WhoIAm == Current_Camera_View)
        {
            if( bPolyText && PolyText[MyGameStatus])
            {
                // Add Crosshair Polygon..
                AddScreenPolyText( (uint16) 63 , (float) (viewport.dwX + (viewport.dwWidth>>1)) , (float) (viewport.dwY + (viewport.dwHeight>>1)) , 64, 255, 64, 255 );

                // Blt trojax PowerLevel / LaserTemperature
                energy = (int) ( ( PowerLevel * 0.01F ) * 9.0F );
                if( !energy )
                {
                    energy = (int) ( ( LaserTemperature *0.01F ) * 9.0F );
                    if( energy > 8 ) energy = 8;
                }
                if( energy )
                {
                    AddScreenPolyText( (uint16) (64+8-energy) , (float) (viewport.dwX + (viewport.dwWidth>>1))-16 , (float) (viewport.dwY + (viewport.dwHeight>>1))+4 , 64, 255, 64, 255 );
                }

                if ( ( control.turbo || Ships[WhoIAm].Object.CruiseControl == CRUISE_NITRO ) && NitroFuel )
                {
                    AddScreenPolyTextScale( 72, (float) ( (d3dappi.szClient.cx>>1) - (NitroFuel - 8) ), (float) (viewport.dwY + (viewport.dwHeight>>1)-7 ) ,
                                            (float) ( ( ( 1.0F / 100.0F ) * ( NitroFuel * 0.5F) ) * ( (32.0F-0.125F) + 0.125F ) ) , 1.0F,
                                            64, 255, 64, 255 );
                }

            
            }else{
                //  Blt Crosshair
                if( !EnhancedXHair )
                {
                    GeneralBltFast( 0 , 0 , 16 , 16  , (viewport.dwX + (viewport.dwWidth>>1))-8 , (viewport.dwY + (viewport.dwHeight>>1))-8 ,
                                    lpDDSOne ,  (char*) "data\\pictures\\panel.bmp" , DDBLTFAST_SRCCOLORKEY  | DDBLTFAST_WAIT , d3dapp->lpBackBuffer);
                }
                //  Blt Nitro...
                if ( ( control.turbo || Ships[WhoIAm].Object.CruiseControl == CRUISE_NITRO ) && NitroFuel )
                {
                    Printuint16( (uint16) NitroFuel , (d3dappi.szClient.cx>>1)-(1*FontWidth), (viewport.dwY + (viewport.dwHeight>>1))+8 , 2 );
                    GeneralBltFast( 0 , 24 , (int)NitroFuel , 3  , (d3dappi.szClient.cx>>1)-(int)(NitroFuel*0.5F) , (viewport.dwY + (viewport.dwHeight>>1))-8 ,
                                    lpDDSOne ,  (char*) "data\\pictures\\panel.bmp" , DDBLTFAST_SRCCOLORKEY  | DDBLTFAST_WAIT , d3dapp->lpBackBuffer);
                }
                // Blt trojax PowerLevel / LaserTemperature
                energy = (int) ( ( PowerLevel * 0.01F ) * 9.0F );
                if( !energy )
                {
                    energy = (int) ( ( LaserTemperature *0.01F ) * 9.0F );
                    if( energy > 8 ) energy = 8;
                }
                if( energy )
                {
                    GeneralBltFast( 0 , 24-energy , 4 , energy  , (viewport.dwX + (viewport.dwWidth>>1))-16 , (viewport.dwY + (viewport.dwHeight>>1))+4-energy ,
                                    lpDDSOne ,  (char*) "data\\pictures\\panel.bmp" , DDBLTFAST_SRCCOLORKEY  | DDBLTFAST_WAIT , d3dapp->lpBackBuffer);
                }
            }

            if( Ships[WhoIAm].Invul )
            {
                Print4x5Text( "I" , FontWidth , d3dappi.szClient.cy-((FontHeight*4)+8) , 2 );
                Printuint16( (uint16) (Ships[WhoIAm].InvulTimer / 60.0F) , FontWidth*4 , d3dappi.szClient.cy-((FontHeight*4)+8) , 2 );
            }
            if( Ships[WhoIAm].Object.Flags & SHIP_SuperNashram )
            {
                Print4x5Text( "S" , FontWidth , d3dappi.szClient.cy-((FontHeight*5)+10) , 2 );
                Printuint16( (uint16) (Ships[WhoIAm].SuperNashramTimer / 60.0F) , FontWidth*4 , d3dappi.szClient.cy-((FontHeight*5)+10) , 2 );
            }
            if( Ships[WhoIAm].Object.Flags & SHIP_Stealth )
            {
                Print4x5Text( "C" , FontWidth , d3dappi.szClient.cy-((FontHeight*6)+12) , 2 );
                Printuint16( (uint16) (Ships[WhoIAm].StealthTime / 60.0F) , FontWidth*4 , d3dappi.szClient.cy-((FontHeight*6)+12) , 2 );
            }

        }
        
        if( Panel && !PlayDemo)
        {
            if( DrawSimplePanel )
            {
                PlotSimplePanel();
            }else{
                if( !DrawPanel && (WhoIAm == Current_Camera_View ) ) 
                {
                    // Full Screen Minimum Stats...

                    if( bPolyText && PolyText[MyGameStatus])
                    {
                        // blt hull
                        AddScreenPolyText( (uint16) 56 , (float) FontWidth , (float) (d3dappi.szClient.cy-((FontHeight*1)+2) ), 32, 255, 32, 255 );
                        // blt shld
                        AddScreenPolyText( (uint16) 55 , (float) FontWidth , (float) (d3dappi.szClient.cy-((FontHeight*2)+4) ), 32, 255, 32, 255 );
                        // Blt Primary
                        AddScreenPolyText( (uint16)( Ships[WhoIAm].Primary + 38 ) , (float) (d3dappi.szClient.cx - ( FontWidth*6) - ( FontWidth*PrimaryLengths[Ships[WhoIAm].Primary] ) ), (float) (d3dappi.szClient.cy-((FontHeight*2)+4) ), 32, 255, 32, 255 );
                        // Blt Secondary
                        AddScreenPolyText( (uint16)( Ships[WhoIAm].Secondary + 44 ) , (float) (d3dappi.szClient.cx - ( FontWidth*6) - ( FontWidth*SecondaryLengths[Ships[WhoIAm].Secondary] ) ) , (float) (d3dappi.szClient.cy-((FontHeight*1)+2)), 32, 255, 32, 255 );
                        // Blt Power Pods
                        AddScreenPolyText( (uint16) (Ships[WhoIAm].Object.PowerLevel + 57 ), (float) (d3dappi.szClient.cx >> 1) - ( ( FontWidth * 7) >>1 ) , (float) (d3dappi.szClient.cy-((FontHeight*1)+2)), 32, 255, 32, 255 );
                        // Blt Mine..
                        energy = (int) GetBestMine();
                        if( energy != 65535 )
                        {
                            AddScreenPolyText( (uint16)( energy + 44 ) , (float) (d3dappi.szClient.cx - ( FontWidth*6) - ( FontWidth*SecondaryLengths[energy] ) ), (float) (FontHeight), 32, 255, 32, 255 );
                            Printuint16( (uint16) SecondaryAmmo[energy] , d3dappi.szClient.cx - ( FontWidth*5) , FontHeight , 2 );
                        }


                        
                        // poly shld bar
                        AddScreenPolyTextScale( 72, (float) (FontWidth*10)-4, (float) (d3dappi.szClient.cy-(FontHeight*2)-2) ,
                                                (float) ( ( ( 1.0F / 256.0F ) * ( Ships[WhoIAm].Object.Shield *0.25F ) ) * ( (32.0F-0.125F) + 0.125F ) ) , 1.0F,
                                                (uint8)(63+(ShieldHit * (192/24) )), (uint8)(255-(ShieldHit * (192/24) )), 64, 255 );
                        if( ShieldHit )
                            ShieldHit -=1;
                        
                        // poly hull bar
                        AddScreenPolyTextScale( 72, (float) (FontWidth*10)-4, (float) (d3dappi.szClient.cy-(FontHeight*1)-2) ,
                                                (float) ( ( ( 1.0F / 256.0F ) * ( Ships[WhoIAm].Object.Hull * 0.25F) ) * ( (32.0F-0.125F) + 0.125F ) ) , 1.0F,
                                                (uint8)(63+(HullHit * (192/24) )), (uint8)(255-(HullHit * (192/24) )), 64, 255 );
                        if( HullHit )
                            HullHit -=1;
                        

                    }else{
                        // blt hull
                        DoFontBlt( FontWidth*28 , FontHeight , FontWidth*4 , FontHeight , FontWidth , d3dappi.szClient.cy-((FontHeight*1)+2) );
                        // blt shld
                        DoFontBlt( FontWidth*28 , 0 , FontWidth*4 , FontHeight , FontWidth , d3dappi.szClient.cy-((FontHeight*2)+4) );
                        // Blt Primary
                        DoFontBlt( FontWidth*16 , FontHeight*Ships[WhoIAm].Primary , FontWidth*PrimaryLengths[Ships[WhoIAm].Primary] , FontHeight , d3dappi.szClient.cx - ( FontWidth*6) - ( FontWidth*PrimaryLengths[Ships[WhoIAm].Primary] ) , d3dappi.szClient.cy-((FontHeight*2)+4)  );
                        // Blt Secondary
                        DoFontBlt( FontWidth*16 , (FontHeight*6)+FontHeight*Ships[WhoIAm].Secondary , FontWidth*SecondaryLengths[Ships[WhoIAm].Secondary] , FontHeight , d3dappi.szClient.cx - ( FontWidth*6) - ( FontWidth*SecondaryLengths[Ships[WhoIAm].Secondary] ) , d3dappi.szClient.cy-((FontHeight*1)+2)  );
                        // Blt Power Pods
                        DoFontBlt( FontWidth*(32-7) , FontHeight*(7+Ships[WhoIAm].Object.PowerLevel) , FontWidth*7 , FontHeight , (d3dappi.szClient.cx >> 1) - ( ( FontWidth * 7) >>1 ) , d3dappi.szClient.cy-((FontHeight*1)+2) );
                        // Blt Mine..
                        energy = (int) GetBestMine();
                        if( energy != 65535 )
                        {
                            DoFontBlt( FontWidth*16 , (FontHeight*6)+FontHeight*energy , FontWidth*SecondaryLengths[energy] , FontHeight , d3dappi.szClient.cx - ( FontWidth*6) - ( FontWidth*SecondaryLengths[energy] ) , FontHeight  );
                            Printuint16( (uint16) SecondaryAmmo[energy] , d3dappi.szClient.cx - ( FontWidth*5) , FontHeight , 2 );
                        }
                        // blt shld bar
                        if( ShieldHit == 0 )
                        {
                            GeneralBltFast( 0 , 24 , (int)(Ships[WhoIAm].Object.Shield * 0.25F) , 3  , FontWidth*10 , d3dappi.szClient.cy-((FontHeight*2)+3) ,
                                            lpDDSOne ,  (char*) "data\\pictures\\panel.bmp" , DDBLTFAST_SRCCOLORKEY  | DDBLTFAST_WAIT, d3dapp->lpBackBuffer);
                        }else{
                            ShieldHit -=1;
                            GeneralBltFast( 0 , 24 + ((ShieldHit>>2)*8) , (int)(Ships[WhoIAm].Object.Shield * 0.25F) , 3  , FontWidth*10 , d3dappi.szClient.cy-((FontHeight*2)+3) ,
                                            lpDDSOne ,  (char*) "data\\pictures\\panel.bmp" , DDBLTFAST_SRCCOLORKEY  | DDBLTFAST_WAIT , d3dapp->lpBackBuffer);
                        }
                        Printuint16( (uint16) Ships[WhoIAm].Object.Shield , FontWidth*6 , d3dappi.szClient.cy-((FontHeight*2)+4) , 2 );
                        // blt hull bar
                        if( HullHit == 0 )
                        {
                            GeneralBltFast( 0 , 24 ,(int) (Ships[WhoIAm].Object.Hull *0.25F) , 3  , FontWidth*10 , d3dappi.szClient.cy-((FontHeight*1)+1) ,
                                            lpDDSOne ,  (char*) "data\\pictures\\panel.bmp" , DDBLTFAST_SRCCOLORKEY  | DDBLTFAST_WAIT , d3dapp->lpBackBuffer);
                        }else{
                            HullHit -=1;
                            GeneralBltFast( 0 , 24 + ((HullHit>>2)*8) , (int)(Ships[WhoIAm].Object.Hull *0.25F) , 3  , FontWidth*10 , d3dappi.szClient.cy-((FontHeight*1)+1) ,
                                            lpDDSOne ,  (char*) "data\\pictures\\panel.bmp" , DDBLTFAST_SRCCOLORKEY  | DDBLTFAST_WAIT , d3dapp->lpBackBuffer);
                        }

                    }

                    // blt shield num
                    Printuint16( (uint16) Ships[WhoIAm].Object.Shield , FontWidth*6 , d3dappi.szClient.cy-((FontHeight*2)+4) , 2 );
                    // blt hull num
                    if( Ships[WhoIAm].Object.Hull > 0.0F && Ships[WhoIAm].Object.Hull < 1.0F )
                    {
                        Printuint16( (uint16) 1 , FontWidth*6 , d3dappi.szClient.cy-((FontHeight*1)+2) , 2 );
                    }else{
                        Printuint16( (uint16) Ships[WhoIAm].Object.Hull , FontWidth*6 , d3dappi.szClient.cy-((FontHeight*1)+2) , 2 );
                    }
                    // Blt Primary ammo
                    if( Ships[WhoIAm].Primary == PYROLITE_RIFLE )
                    {
                        energy =  (int) PyroliteAmmo;
                    }else{
                        if( Ships[WhoIAm].Primary == SUSS_GUN )
                        {
                            energy = (int) SussGunAmmo;
                        }else{
                            energy = (int) GeneralAmmo;
                        }
                    }
                    Printuint16( (uint16) energy , d3dappi.szClient.cx - ( FontWidth*5) , d3dappi.szClient.cy-((FontHeight*2)+4) , 2 );
                    
                    // Blt Secondary ammo
                    Printuint16( (uint16) GetCurSecAmmo() , d3dappi.szClient.cx - ( FontWidth*5) , d3dappi.szClient.cy-((FontHeight*1)+2) , 2 );
                    
                }
            }
        
            if( (NamesAreLegal != 0) || IsHost )
            {
                ScoreSort();
                PrintScoreSort();
            }
            MessageQuePrint();
        }else{
            if( Panel )
            {
                ScoreSort();
                PrintScoreSort();
                MessageQuePrint();

                if( DemoEyesSelect.value != MAX_PLAYERS )
                {
                    Print4x5Text( Names[DemoEyesSelect.value] ,d3dappi.szClient.cx - (FontWidth*9), FontHeight , 0 );
                }
            }
        }
        if( Ships[WhoIAm].Object.Mode == GAMEOVER_MODE )
        {
            CenterPrint4x5Text( "Game Over" , (d3dappi.szClient.cy >> 1) - (FontHeight*2) , 2 );
        }
    }
            
//      TaskSleep( 1 );
}

void
ReleaseLevel(void)
{
    switch( MyGameStatus )
    {
    case    STATUS_Copyright:
    case    STATUS_Title:
    case    STATUS_BetweenLevels:
    case    STATUS_StartingSinglePlayer:
    case    STATUS_TitleLoadGameStartingSinglePlayer:
        break;
    
    default:
        if( GodMode ) LoseAllWeapons();

        ReleaseComponentedShips();
        KillThermo();
        NodeRelease();
        CameraRelease();
        ReleaseExternalForces();
        ReleaseTeleports();
        ReleaseTriggers();
        ReleaseTriggerArea();
        ReleaseRTLights();
        ReleaseGoal();

        if( CountDownOn || BombTag )
        {
            DeleteCountdownDigits();
        }

        KillAllBGObjects();
        ReleaseAllEnemies();
        ReleaseAllRestartPoints();
        DestroySound( DESTROYSOUND_All );
        ProcessGuaranteedMessages( TRUE , FALSE , FALSE );
        FreeServerMessageQue();


#ifdef SOFTWARE_ENABLE
        if( SoftwareVersion )
        {
            SetVTables();
            SWRendView();
            d3dappi.lpBackBuffer->lpVtbl->Unlock( d3dappi.lpBackBuffer, NULL );
        }
#endif
        break;
    }

}



void
ReleaseScene(void)
{
    int16   Count;

    if( RegenPoints != NULL )
    {
        free( RegenPoints );
        RegenPoints = NULL;
        NumRegenPoints = 0;

        for( Count = 0; Count < MAX_PLAYERS; Count++ )
        {
            if( RegenSlotsCopy[ Count ] != NULL )
            {
                free( RegenSlotsCopy[ Count ] );
                RegenSlotsCopy[ Count ] = NULL;
            }
        }
    }

    switch( MyGameStatus )
    {
    case    STATUS_Copyright:
    case    STATUS_BetweenLevels:
    case    STATUS_Title:
    case    STATUS_StartingSinglePlayer:
    case    STATUS_TitleLoadGameStartingSinglePlayer:
        break;
    
    default:
        DestroyGame();
        break;
    }

}

void
ReleaseView(void)
{
    switch( MyGameStatus )
    {
    case    STATUS_PlayingAVI:
        ReleaseDDSurf(lpDDSTwo);    //font
        lpDDSTwo = NULL;
        break;
    case    STATUS_Copyright:
        ReleaseTitle();
        break;
    case    STATUS_StartingMultiplayer:
    case    STATUS_GetPlayerNum:
    case    STATUS_BetweenLevels:
    case    STATUS_Title:
    case    STATUS_TitleLoadGameStartingSinglePlayer:
    case    STATUS_StartingSinglePlayer:
    case    STATUS_QuittingFromTitles:
    case    STATUS_WaitingToStartMultiPlayerClient:
    case    STATUS_WaitingToStartDemo:              // Added by DC 24/1/98

        ReleaseFlyGirl();

        FreeAllLastAFrameScrPolys();
        ReleaseTitle();
        ReleaseSpecialExecBufs();
        ReleaseTloadheader( &Tloadheader );
        ReleaseSysTload( SystemMemTPages, &CurrentSysTexture );
        ReleaseTitleModels();
        Free_All_Off_Files( &Title_OffsetFiles[ 0 ] );
        ReleaseRenderBufs();
        ReleasePolySort();
        break;

    case STATUS_ViewingScore:
#if 0   // used to release solid scr poly stuff
        ReleaseSpecialExecBufs();
        ReleaseTloadheader( &Tloadheader );
        ReleaseSysTload( SystemMemTPages, &CurrentSysTexture );
        Free_All_Off_Files( &Title_OffsetFiles[ 0 ] );
        ReleaseRenderBufs();
        ReleasePolySort();
#endif
        FreeScoreDisplay();
        break;

    case STATUS_ViewingStats:
        FreeStatsDisplay();
        break;

    default:
        ReleaseSpecialExecBufs();

        Bspfree();

        
        FreeAllLastAFrameScrPolys();
        ReleaseMloadheader(&Mloadheader);
        ReleaseTloadheader( &Tloadheader );
        ReleaseSysTload( SystemMemTPages, &CurrentSysTexture );
        ReleaseModels();
        
        if ( MCloadheader.Buffer )
        {
            free( MCloadheader.Buffer );
            MCloadheader.Buffer = NULL;
        }
        if ( MCloadheadert0.Buffer )
        {
            free( MCloadheadert0.Buffer );
            MCloadheadert0.Buffer = NULL;
        }
    
        Free_All_Off_Files( &OffsetFiles[ 0 ] );
        ReleaseSkinExecs();
        ReleasePortalExecs();
        ReleaseRenderBufs();
    
        WaterRelease();
        
        FreeTxtFile();
        FreeMsgFile();
        ReleaseDDSurf(lpDDSOne);
        ReleaseDDSurf(lpDDSTwo);
        lpDDSTwo = NULL;
        lpDDSOne = NULL;


        if( !DrawPanel && DrawSimplePanel )
        {
            ReleaseDDSurf(lpDDSThree);
           
            ReleaseDDSurf(lpDDSFour);
        }
        RELEASE(lpBmat);

//      TaskerInit();

    }

    if (CD_Present)
    {
        if (CdIsPlaying())
            CdStop();
    }

}
//extern    uint16  BackgroundModel;

BOOL
InitScene(void)
{
    int i;
//  BackgroundModel = (uint16) -1;

    OnceOnlyInitModel();
    InitXLights();
    InitPrimBulls();
    InitSecBulls();
    InitFmPoly();

#ifdef SHADOWTEST
    InitTriangles();
#endif

    InitPolys();
    InitScrPolys();
    InitLines();
    SetupSpotFX();
    InitPickups();
    InitAmmoUsed();
    InitAfterBurners();
    InitBGObjects();
    InitRestartPoints();
    InitEnemies();

    for( i = 0 ; i < MAX_PLAYERS ; i++ )
    {
        Ships[i].ModelNum = (uint16) -1;
    }


    QueryPerformanceFrequency((LARGE_INTEGER *) &Freq);

    switch( MyGameStatus )
    {
    case    STATUS_Copyright:
    case    STATUS_BetweenLevels:
    case    STATUS_Title:
    case    STATUS_StartingSinglePlayer:
    case    STATUS_TitleLoadGameStartingSinglePlayer:
    case    STATUS_StartingMultiplayer:
    case    STATUS_GetPlayerNum:
        if (!LoadTitleModels())
        {   Msg( "LoadTitleModels failed.\n" );
            return FALSE;
        }
        break;
    default:
        break;
    }
    
    return TRUE;
}

/*-------------------------------------------------------------------
    Procedure   :       Init the view...This might be title or score
                        or main game....
    Input       :       LPDIRECTDRAW lpDD, LPDIRECT3D lpD3D, LPDIRECT3DDEVICE lpDev,
                        LPDIRECT3DVIEWPORT lpView
    Output      :       BOOL TRUE/FLASE
-------------------------------------------------------------------*/

BOOL
InitView( void )
{
    LPDIRECTDRAW lpDD = d3dapp->lpDD;
    LPDIRECT3D lpD3D = d3dapp->lpD3D;
    LPDIRECT3DDEVICE lpDev = d3dapp->lpD3DDevice;
    LPDIRECT3DVIEWPORT lpView = d3dapp->lpD3DViewport;
    DWORD dwItems = INFINITE;

    CheatsDisabled = FALSE;

    // if viewing splash screens, initview will be called after viewing final screen
    if (( MyGameStatus == STATUS_SplashScreen ) || ( MyGameStatus == STATUS_FinishedShowingSplashScreen ))
        return TRUE;

    // flush keyboard buffer...
    if (lpdiBufferedKeyboard)
    {
        IDirectInputDevice_GetDeviceData( lpdiBufferedKeyboard, sizeof(DIDEVICEOBJECTDATA), NULL, &dwItems, 0); 
    }

    if( PowerVR )
    {
        MakeColourMode = MCM_PowerVR;
    }
    else
    {
        if(d3dapp->CurrDriver != 0)
        {
            if( UsedStippledAlpha != TRUE ) MakeColourMode = MCM_Normal;
            else MakeColourMode = MCM_Stipple;
        }
        else
        {
            MakeColourMode = MCM_Software;
        }
    }


    GetHardwareCaps();
    InitModeCase();

    switch( MyGameStatus )
    {
    case    STATUS_PlayingAVI:
        if ( bSoundEnabled )
            DestroySound( DESTROYSOUND_All );
        break;
    case    STATUS_Copyright:
        AddCommandToBat( "mkdir %%2\\data\\BGObjects\n" );
        AddCommandToBat( "mkdir %%2\\data\\Models\n" );
        AddCommandToBat( "mkdir %%2\\data\\Textures\n" );
        AddCommandToBat( "mkdir %%2\\data\\Pictures\n" );
        AddCommandToBat( "mkdir %%2\\data\\Offsets\n" );
        AddCommandToBat( "mkdir %%2\\data\\Sfx\n" );

        InitFont( FALSE );
        
        AddCommentToBat( "Started Loading Titles" );

        if( InitTitle( lpDD, lpD3D, lpDev, lpView ) != TRUE )
        {
            SeriousError = TRUE;
            return FALSE;
        }


        break;
    case    STATUS_BetweenLevels:
    case    STATUS_Title:
    case    STATUS_StartingSinglePlayer:
    case    STATUS_TitleLoadGameStartingSinglePlayer:
    case    STATUS_StartingMultiplayer:
    case    STATUS_GetPlayerNum:
        if( InitTitle( lpDD, lpD3D, lpDev, lpView ) != TRUE )
        {
            SeriousError = TRUE;
            return FALSE;
        }

        if ( !bSoundEnabled )
        {
            if (! InitializeSound( DESTROYSOUND_All ))
            {
                DebugPrintf("unable to initialise sound in initview\n");
                Msg("unable to initialise sound in initview\n");
                exit(1);
            }
        }

        CurrentSysTexture = 0;
                
        InitPolySort();

        InitRenderBufs(lpDev );

        InitSpecialExecBufs();
        
        if( !SetMatrixViewPort() )
        {
            SeriousError = TRUE;
            Msg( "SetMatrixViewPort() Failed\n" );
            return FALSE;
        }
        // Init the Texture Handler
        InitTload( &Tloadheader );

        if( !Load_All_Off_Files( &Title_OffsetFiles[ 0 ] ) )
        {
            SeriousError = TRUE;
            return FALSE;
        }
        
        if( !PreLoadFlyGirl() )
        {
            SeriousError = TRUE;
            return FALSE;
        }
        

#ifndef SELF_PLAY
        if( !PreInitModel( lpDev , TitleModelSet ) )
        {
            SeriousError = TRUE;
            return FALSE;
        }
        
#endif
        //  Load in And if nescessary ReScale Textures...
        if( !Tload( &Tloadheader ) )
        {
            SeriousError = TRUE;
            return FALSE;
        }

        // Load all system memory textures...
        if( !SysTload( SystemMemTPages, CurrentSysTexture ) )
        {
            SeriousError = TRUE;
            return FALSE;
        }

#ifndef SELF_PLAY
        if( !InitModel( lpDev , TitleModelSet ) )
        {
            SeriousError = TRUE;
            return FALSE;
        }
#endif
        
        if ( !AllocateCompFlyGirl() )
        {
            SeriousError = TRUE;
            return FALSE;
        }else
        {
            UpdateFlyGirl( &BikePos, &MATRIX_Identity, FALSE );
        }
        

        QueryPerformanceCounter((LARGE_INTEGER *) &LastTime);

        //DummyTextureIndex = FindTexture( &Tloadheader, "textures\\dummy.ppm" );
        DummyTextureIndex = FindTexture( &Tloadheader, "textures\\dummy.bmp" );
        if ( DummyTextureIndex != -1 )
        {
            Tloadheader.PlaceHolderFile[ DummyTextureIndex ] = ( char * )malloc( sizeof( char ) * 256 );
            Tloadheader.PlaceHolder[ DummyTextureIndex ] = TRUE;
        }

        if ( !CurrentMenu )
            MenuRestart( &MENU_Start );

        // if any levels are on CD, do not play CD audio in titles
        if ( !LevelsOnCD )
        {
            cd_info.current_track = CD_TITLE_TRACK;
            if( CD_OK )
            {
                PlayAudioTrack();
            }
        }
        break;

    case STATUS_ViewingScore:
        InitScoreDisplay();
        break;

    case STATUS_ViewingStats:
        InitStatsDisplay();
        break;
    
    default:
        InitView_MyGameStatus = MyGameStatus;
        MyGameStatus = STATUS_InitView_0;
        DrawLoadingBox( CurrentLoadingStep++, 0, 1 );
        D3DAppClearScreenOnly();
        CameraStatus = CAMERA_AtStart;  //prevents on screen menus from being suppressed
        break;
    }


    return TRUE;
}

BOOL FAR PASCAL InitJoystickInput(LPCDIDEVICEINSTANCE pdinst, 
                                  LPVOID pvRef) 
{ 
   LPDIRECTINPUT pdi = pvRef; 
   LPDIRECTINPUTDEVICE pdev;
   HRESULT hr;
   char tempstr[MAX_PATH];

   // create the DirectInput joystick device 
   if (pdi->lpVtbl->CreateDevice(pdi, &pdinst->guidInstance, 
                                 &pdev, NULL) != DI_OK) 
   { 
      return DIENUM_CONTINUE; 
   } 

   strcpy (tempstr, &pdinst->tszProductName[0]);
   JoystickInfo[Num_Joysticks].Name = (char *) malloc ( strlen( tempstr ) + 1 );
   strcpy (JoystickInfo[Num_Joysticks].Name, tempstr);

   hr = pdev->lpVtbl->QueryInterface( pdev, &IID_IDirectInputDevice2,
                                             (LPVOID *)&lpdiJoystick[Num_Joysticks]);
   pdev->lpVtbl->Release(pdev);

   if (hr != S_OK)
       return DIENUM_CONTINUE;

   diJoystickCaps[ Num_Joysticks ].dwSize = sizeof( DIDEVCAPS );
   hr = IDirectInputDevice2_GetCapabilities( lpdiJoystick[ Num_Joysticks ], &diJoystickCaps[ Num_Joysticks ] );

   if (hr != S_OK)
       return DIENUM_CONTINUE;

   Num_Joysticks++;

   if (Num_Joysticks > MAX_JOYSTICKS)
       Num_Joysticks = MAX_JOYSTICKS;

   return DIENUM_CONTINUE;
}

BOOL CALLBACK DIEnumDeviceObjectsProc( 
                      LPCDIDEVICEOBJECTINSTANCE lpddoi,
                      LPVOID pvRef) 
{ 
    GUID     AxisGUID[MAX_JOYSTICK_AXIS - 1];
  GUID   ButtonGUID = GUID_Button;
//  GUID   KeyGUID = GUID_Key;
  GUID   POVGUID = GUID_POV;
//  GUID     UnknownGUID = GUID_Unknown;
  GUID   CompareGUID;
  int   *joysticknumptr;
  int   joysticknum, axis;
  char tempstr[MAX_JOYNAME];
#if 1
   AxisGUID[0] = GUID_XAxis;
   AxisGUID[1] = GUID_YAxis;
   AxisGUID[2] = GUID_ZAxis;
   AxisGUID[3] = GUID_RxAxis;
   AxisGUID[4] = GUID_RyAxis;
   AxisGUID[5] = GUID_RzAxis;
   AxisGUID[6] = GUID_Slider; // js can have up to 2 sliders

  joysticknumptr = (int *)(pvRef);
  joysticknum = *joysticknumptr;

    CompareGUID = lpddoi->guidType;

    for (axis = 0; axis < MAX_JOYSTICK_AXIS - 1; axis++)
    {
        if (IsEqualGuid( &AxisGUID[axis], &CompareGUID ))
        {
            if ((axis == AXIS_SliderAxis0) && (JoystickInfo[joysticknum].Axis[AXIS_SliderAxis0].exists))
                axis++;

            JoystickInfo[joysticknum].Axis[axis].exists = TRUE;

            if (lpddoi->tszName && *lpddoi->tszName)
                strncpy( tempstr, lpddoi->tszName, MAX_JOYNAME );
            else
                sprintf( tempstr, "Axis %d", axis );

            JoystickInfo[joysticknum].Axis[axis].name = 
                (char *) malloc ( strlen ( tempstr ) + 1 );

            strcpy ( JoystickInfo[joysticknum].Axis[axis].name, tempstr );

            JoystickInfo[joysticknum].Axis[axis].feedback =
                ( lpddoi->dwType & DIDFT_FFACTUATOR ) ? TRUE : FALSE;

            if ( JoystickInfo[joysticknum].Axis[axis].feedback )
                DebugPrintf( "Joystick %s Axis %s supports force feedback\n",
                    JoystickInfo[ joysticknum ].Name,
                    JoystickInfo[ joysticknum ].Axis[ axis ].name );

/*
            if (lpddoi->tszName && *lpddoi->tszName)
                strncpy( JoystickInfo[joysticknum].Axis[axis].name, lpddoi->tszName, MAX_JOYNAME );
            else
                // no name given back by joystick for axis, therefore assign arbitrary name
                sprintf( JoystickInfo[joysticknum].Axis[axis].name, "Axis %d", axis );
*/

            JoystickInfo[joysticknum].NumAxis++;
            return DIENUM_CONTINUE; 
        }
    }

    if (IsEqualGuid( &ButtonGUID, &CompareGUID ))
    {

#ifdef USE_JOYSTICK_NAMES
        if (lpddoi->tszName && *lpddoi->tszName)
            strncpy( tempstr, lpddoi->tszName, MAX_JOYNAME );
        else
#endif
            sprintf( tempstr, "Button %d", JoystickInfo[joysticknum].NumButtons );

        JoystickInfo[joysticknum].Button[JoystickInfo[joysticknum].NumButtons].name = 
            (char *) malloc ( strlen ( tempstr ) + 1 );

        strcpy ( JoystickInfo[joysticknum].Button[JoystickInfo[joysticknum].NumButtons].name, tempstr );

        JoystickInfo[joysticknum].Button[JoystickInfo[joysticknum].NumButtons].feedback_trigger =
            ( lpddoi->dwType & DIDFT_FFEFFECTTRIGGER ) ? TRUE : FALSE;

        JoystickInfo[joysticknum].NumButtons++;

/*      
        if (lpddoi->tszName && *lpddoi->tszName)
            strncpy( JoystickInfo[joysticknum].Button[JoystickInfo[joysticknum].NumButtons++].name, lpddoi->tszName, MAX_JOYNAME );
        else
        {
            // no name given back by joystick for button, therefore assign arbitrary name
            sprintf( JoystickInfo[joysticknum].Button[JoystickInfo[joysticknum].NumButtons].name, "Button %d", JoystickInfo[joysticknum].NumButtons );
            JoystickInfo[joysticknum].NumButtons++;
        }
*/

        return DIENUM_CONTINUE; 
    }

    if (IsEqualGuid( &POVGUID, &CompareGUID ))
    {
        int dir;

#ifdef USE_JOYSTICK_NAMES
        if (lpddoi->tszName && *lpddoi->tszName)
            strncpy( tempstr, lpddoi->tszName, MAX_JOYNAME );
        else
#endif
            if ( JoystickInfo[ joysticknum ].NumPOVs )
                sprintf( tempstr, "Hat %d", JoystickInfo[joysticknum].NumPOVs + 1 );
            else
                sprintf( tempstr, "Hat" );

        JoystickInfo[joysticknum].POV[JoystickInfo[joysticknum].NumPOVs].name = 
            (char *) malloc ( strlen ( tempstr ) + 1 );

        strcpy ( JoystickInfo[joysticknum].POV[JoystickInfo[joysticknum].NumPOVs].name, tempstr );

        for ( dir = 0; dir < MAX_POV_DIRECTIONS; dir++ )
        {
            JoystickInfo[joysticknum].POV[JoystickInfo[joysticknum].NumPOVs].dirname[ dir ] = 
                (char *) malloc ( strlen ( tempstr ) + strlen( JoystickPOVDirections[ dir ] ) + 2 );
            
            strcpy ( JoystickInfo[joysticknum].POV[JoystickInfo[joysticknum].NumPOVs].dirname[ dir ], tempstr );
            strcat ( JoystickInfo[joysticknum].POV[JoystickInfo[joysticknum].NumPOVs].dirname[ dir ], " " );
            strcat ( JoystickInfo[joysticknum].POV[JoystickInfo[joysticknum].NumPOVs].dirname[ dir ], JoystickPOVDirections[ dir ] );
        }

        JoystickInfo[joysticknum].NumPOVs++;
/*      
        if (lpddoi->tszName && *lpddoi->tszName)
            strncpy( JoystickInfo[joysticknum].POV[JoystickInfo[joysticknum].NumPOVs++].name, lpddoi->tszName, MAX_JOYNAME );
        else
        {
            // no name given back by joystick for POV, therefore assign arbitrary name
            sprintf( JoystickInfo[joysticknum].POV[JoystickInfo[joysticknum].NumPOVs].name, "POV %d", JoystickInfo[joysticknum].NumPOVs );
            JoystickInfo[joysticknum].NumPOVs++;
        }
*/

        return DIENUM_CONTINUE; 
    }
#endif
  return DIENUM_CONTINUE; 
}


#ifdef USE_DINPUT_KEYNAMES

#define MAX_KEYS    (256)
DWORD KeyMax;
DIDEVICEOBJECTINSTANCE KeyInfo[ MAX_KEYS ];

BOOL CALLBACK DIEnumKeyboardObjectsProc( LPCDIDEVICEOBJECTINSTANCE lpddoi, LPVOID pvRef )
{
    DWORD key = lpddoi->dwOfs;
    if ( key < MAX_KEYS )
        KeyInfo[ key ] = *lpddoi;
    if ( KeyMax < key )
        KeyMax = key;
    return DIENUM_CONTINUE;
}


char *DI_KeyName( DWORD key )
{
    return ( key < MAX_KEYS && KeyInfo[ key ].dwSize ) ? KeyInfo[ key ].tszName : NULL;
}

#endif // USE_DINPUT_KEYNAMES


/**************************************************************************
  InitDInput
 **************************************************************************/
BOOL InitDInput(void)
{
    HRESULT         err;
    GUID     guid_mouse = GUID_SysMouse;
    GUID     guid_keyboard = GUID_SysKeyboard;
//  GUID     guid_joystick = GUID_Joystick;
    DIPROPDWORD dipdw =
        {
            {
                sizeof(DIPROPDWORD),        // diph.dwSize
                sizeof(DIPROPHEADER),       // diph.dwHeaderSize
                0,                          // diph.dwObj
                DIPH_DEVICE,                // diph.dwHow
            },
            DINPUT_BUFFERSIZE,              // dwData
        };
    LPDIRECTINPUTDEVICE         tempJoystick = NULL;
    LPVOID joysticknumptr;
    int i, j, k;
    BOOL failjoystick;

#if DIRECTINPUT_VERSION > 0x0700
    err = DirectInput8Create(myglobs.hInstApp, DIRECTINPUT_VERSION, &IID_IDirectInput8, &lpdi, NULL);
#else
    err = DirectInputCreateA(myglobs.hInstApp, DIRECTINPUT_VERSION, &lpdi, NULL);
#endif

    if(err != DI_OK)
    {
            return FALSE;
    }


    // Create a mouse.
    err = IDirectInput_CreateDevice(lpdi, &guid_mouse, &lpdiMouse, NULL);
    if ( err != DI_OK )
    {
        goto fail;
    }

    // Tell DirectInput that we want to receive data in mouse format
    err = IDirectInputDevice_SetDataFormat(lpdiMouse, &c_dfDIMouse);

    if(err != DI_OK)
    {
            goto fail;
    }

    // set desired access mode
    err = IDirectInputDevice_SetCooperativeLevel(lpdiMouse, myglobs.hWndMain,
        DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
    if(err != DI_OK)
    {
            goto fail;
    }

    err = IDirectInputDevice_Acquire(lpdiMouse);

    // try to create keyboard device
    if(IDirectInput_CreateDevice(lpdi, &guid_keyboard, &lpdiKeyboard, NULL) !=DI_OK)
    {
            goto fail;
    }

    // Tell DirectInput that we want to receive data in keyboard format
    if (IDirectInputDevice_SetDataFormat(lpdiKeyboard, &c_dfDIKeyboard) != DI_OK)
    {
            goto fail;
    }

    // set cooperative level
    if(IDirectInputDevice_SetCooperativeLevel(lpdiKeyboard, myglobs.hWndMain,
                     DISCL_NONEXCLUSIVE | DISCL_FOREGROUND) != DI_OK)
    {
            goto fail;
    }

#ifdef USE_DINPUT_KEYNAMES
    // get key info
    KeyMax = 0;
    memset( KeyInfo, 0, sizeof( KeyInfo ) );
    if (IDirectInputDevice_EnumObjects(lpdiKeyboard, DIEnumKeyboardObjectsProc, NULL, DIDFT_ALL ) != DI_OK)
    {
        // don't care -- fall back on internal key name info
    }
#endif // USE_DINPUT_KEYNAMES

    // try to acquire the keyboard
    err = IDirectInputDevice_Acquire(lpdiKeyboard);

    if(err != DI_OK)
    {
//            goto fail;
    }

    // try to create another keyboard device (which will be buffered, for menu screens)
    if(IDirectInput_CreateDevice(lpdi, &guid_keyboard, &lpdiBufferedKeyboard, NULL) !=DI_OK)
    {
            goto fail;
    }

    // Tell DirectInput that we want to receive data in keyboard format
    if (IDirectInputDevice_SetDataFormat(lpdiBufferedKeyboard, &c_dfDIKeyboard) != DI_OK)
    {
            goto fail;
    }

    // set cooperative level
    if(IDirectInputDevice_SetCooperativeLevel(lpdiBufferedKeyboard, myglobs.hWndMain,
                     DISCL_NONEXCLUSIVE | DISCL_FOREGROUND) != DI_OK)
    {
            goto fail;
    }

    // set the buffer size...
    err = lpdiBufferedKeyboard->lpVtbl->SetProperty(lpdiBufferedKeyboard, DIPROP_BUFFERSIZE, &dipdw.diph);

    if(err != DI_OK)
    {
            goto fail;
    }

    // try to acquire the keyboard
    err = IDirectInputDevice_Acquire(lpdiBufferedKeyboard);

    if(err != DI_OK)
    {
//            goto fail;
    }

    FF_Init();
    // try to create Joystick devices
    for ( i = 0; i < MAX_JOYSTICKS; i++ )
        lpdiJoystick[i] = NULL;
    Num_Joysticks = 0;

//  lpdi->lpVtbl->EnumDevices(lpdi, DIDEVTYPE_JOYSTICK, 
//                         InitJoystickInput, lpdi, DIEDFL_ATTACHEDONLY); 

    failjoystick = FALSE;
    for (i = 0; i < Num_Joysticks; i++)
    {
        JoystickInfo[i].assigned = FALSE;
        JoystickInfo[i].connected = TRUE;
        JoystickInfo[i].NumAxis = 0;
        JoystickInfo[i].NumButtons = 0;
        JoystickInfo[i].NumPOVs = 0;

        joysticknumptr = (LPVOID)&i;
        for (j = AXIS_Start; j <= AXIS_End; j++)
        {
            JoystickInfo[i].Axis[j].exists = FALSE;
        }
        lpdiJoystick[i]->lpVtbl->EnumObjects(lpdiJoystick[i], DIEnumDeviceObjectsProc, 
                           joysticknumptr, DIDFT_ALL); 

        for (j = AXIS_Start; j <= AXIS_End; j++)
        {
            JoystickInfo[i].Axis[j].action = SHIPACTION_Nothing;
            JoystickInfo[i].Axis[j].inverted = FALSE;
            JoystickInfo[i].Axis[j].deadzone = 20;
            JoystickInfo[i].Axis[j].fine = TRUE;
        }

        for (j = 0; j < JoystickInfo[i].NumButtons; j++)
            JoystickInfo[i].Button[j].action = SHIPACTION_Nothing;

        for (j = 0; j < JoystickInfo[i].NumPOVs; j++)
        {
            for (k = 0; k < MAX_POV_DIRECTIONS; k++)
                JoystickInfo[i].POV[j].action[k] = SHIPACTION_Nothing;
        }

        if ( diJoystickCaps[ i ].dwFlags & DIDC_FORCEFEEDBACK )
        {
            DIPROPDWORD DIPropAutoCenter;
            
            DIPropAutoCenter.diph.dwSize = sizeof(DIPropAutoCenter);
            DIPropAutoCenter.diph.dwHeaderSize = sizeof(DIPROPHEADER);
            DIPropAutoCenter.diph.dwObj = 0;
            DIPropAutoCenter.diph.dwHow = DIPH_DEVICE;
            DIPropAutoCenter.dwData = 0;
            
            err = IDirectInputDevice2_SetProperty( lpdiJoystick[ i ], DIPROP_AUTOCENTER, &DIPropAutoCenter.diph );
            if ( err != DI_OK )
            {
                DebugPrintf( "Unable to turn autocentering off for forcefeedback joystick %s\n",
                    JoystickInfo[ i ].Name );
                goto fail;
            }

            if ( !FF_InitJoystick( i ) )
            {
                DebugPrintf( "Unable to initialise force feedback info\n" );
                goto fail;
            }
        }
        else
        {
            JoystickInfo[ i ].feedback = NULL;
        }

        // Tell DirectInput that we want to receive data in joystick format
        if (IDirectInputDevice2_SetDataFormat(lpdiJoystick[i], &c_dfDIJoystick2) == DI_OK)
        {                                                    
            // set cooperative level
            if(IDirectInputDevice2_SetCooperativeLevel(lpdiJoystick[i], myglobs.hWndMain,
//                               DISCL_NONEXCLUSIVE | DISCL_FOREGROUND) == DI_OK)
                                 DISCL_EXCLUSIVE | DISCL_FOREGROUND) == DI_OK) // need exclusive mode for force-feedback joysticks
            {
                // try to acquire the Joystick
                err = IDirectInputDevice2_Acquire(lpdiJoystick[i]);
                if (err != DI_OK)
                {
                    failjoystick = TRUE;
                }
            }else
            {
                failjoystick = TRUE;
            }
        }else
        {
            failjoystick = TRUE;
        }

        
        if (failjoystick)
        {
            failjoystick = FALSE;
            IDirectInputDevice2_Release(lpdiJoystick[i]);
            lpdiJoystick[i] = NULL;
        }
#if NOW_DONE_INSIDE_DEFAULTJOYSTICKSETTINGS
        SetUpJoystickAxis(i);

       // if spaceorb...
        if ( !_stricmp( JoystickInfo[i].Name, "Spacetec SpaceOrb 360" ) )
        {
            DebugPrintf("Spaceorb detected - auto configuring axis...\n");
            ConfigureSpaceorbAxis( i );
        }
#endif
    }
    DebugPrintf( "InitDInput: %d joysticks connected\n", Num_Joysticks );
    DefaultJoystickSettings( &default_config );
    *player_config = default_config;
    DebugPrintf( "InitDInput: default configs initialised\n" );

    // if we get here, all DirectInput objects were created ok
    return TRUE;

fail:
    if (lpdiMouse)  IDirectInputDevice_Release(lpdiMouse), lpdiMouse  = NULL;
    if (lpdiKeyboard)  IDirectInputDevice_Release(lpdiKeyboard), lpdiKeyboard  = NULL;
    if (lpdiBufferedKeyboard)  IDirectInputDevice_Release(lpdiBufferedKeyboard), lpdiBufferedKeyboard  = NULL;
    for (i = 0; i < Num_Joysticks; i++)
    {
        if (lpdiJoystick[i])
        {
            FF_ReleaseJoystick( i );
            IDirectInputDevice2_Release(lpdiJoystick[i]);
            lpdiJoystick[i] = NULL;
        }
        if ( JoystickInfo[ i ].feedback )
        {
            free( JoystickInfo[ i ].feedback );
            JoystickInfo[ i ].feedback = NULL;
        }
    }
    if (lpdi)       IDirectInputDevice_Release(lpdi), lpdi     = NULL;
    return FALSE;                             
}

BOOL TermDInput( void )
{
    int i;

    if (lpdiMouse)
    {
        IDirectInputDevice_Unacquire(lpdiMouse);
        IDirectInputDevice_Release(lpdiMouse);
        lpdiMouse  = NULL;
    }
    if (lpdiKeyboard)
    {
        IDirectInputDevice_Unacquire(lpdiKeyboard);
        IDirectInputDevice_Release(lpdiKeyboard);
        lpdiKeyboard  = NULL;
    }
    if (lpdiBufferedKeyboard)
    {
        IDirectInputDevice_Unacquire(lpdiBufferedKeyboard);
        IDirectInputDevice_Release(lpdiBufferedKeyboard);
        lpdiBufferedKeyboard  = NULL;
    }

    for (i = 0; i < Num_Joysticks; i++)
    {
        if (lpdiJoystick[i])
        {
            FF_ReleaseJoystick( i );
            IDirectInputDevice2_Unacquire(lpdiJoystick[i]);
            IDirectInputDevice2_Release(lpdiJoystick[i]);
            lpdiJoystick[i]  = NULL;
        }
        if ( JoystickInfo[ i ].feedback )
        {
            free( JoystickInfo[ i ].feedback );
            JoystickInfo[ i ].feedback = NULL;
        }
    }

    if (lpdi)
    {
        IDirectInputDevice_Release(lpdi);
        lpdi     = NULL;
    }

    return TRUE;
}


void ProcessGameKeys( void )
{
    static int16 startpos = 0;

#ifdef SHAREWARE
    if ( MyGameStatus == STATUS_AttractMode )
    {
//      if ( WhichKeyPressed() )
        if ( AnyKeyPressed() )
        {
            PreDemoEndMyGameStatus = MyGameStatus;
            SelectQuitCurrentGame( NULL );
            Panel = PreAttractModePanel;
            return;
        }
    }
#endif

    if ( ( MyGameStatus == STATUS_Normal ) || ( MyGameStatus == STATUS_SinglePlayer ) || ( MyGameStatus == STATUS_PlayingDemo ) || (MyGameStatus == STATUS_AttractMode ) )
    {
//      if ( WhichKeyPressed() && ECTSDemo && PlayDemo )
        if ( AnyKeyPressed() && ECTSDemo && PlayDemo )
        {
            SelectQuitCurrentGame( NULL );
            return;
        }
        if( !E3DemoHost && !E3DemoClient && !ECTSDemo )
        {
            if ( IsKeyPressed( DIK_ESCAPE ) )
            {
                if ( !CurrentMenu && !JustExitedMenu )
                {
                    if( PlayDemo )
                    {
                        MenuRestart( &MENU_DemoPlaying );
                    }else{
                        MenuRestart( &MENU_InGame );
                    }
                }else{
                    JustExitedMenu = FALSE;
                }
            }
        }
        if ( IsKeyPressed( DIK_ESCAPE ) && ( IsKeyHeld( DIK_LSHIFT ) || IsKeyHeld( DIK_RSHIFT ) ) )
        {
            if ( !CurrentMenu && !JustExitedMenu )
            {
                if( PlayDemo )
                {
                    MenuRestart( &MENU_DemoPlaying );
                }else{
                    MenuRestart( &MENU_InGame );
                }
            }else{
                JustExitedMenu = FALSE;
            }
        }
#ifdef SAVESCREEN_3DFX
        if ( IsKeyPressed( DIK_F8 ) && ScreenSaving )
        {
            sprintf( fname, ".\\ScreenShots\\screen%d.ppm", fnum++ );
//          _spawnl( _P_WAIT, "grab.exe", "grab.exe", "-fp" , "-w 512" , "-h 384" , fname, NULL );

            folder_exists( SNAPSHOT_FOLDER );
            SaveFullScreenSnapShot( fname );
        }
 
#endif
        if ( DebugInfo && ( IsKeyHeld( DIK_LSHIFT ) || IsKeyHeld( DIK_RSHIFT ) ) )
        { // special debugging keys
            if ( IsKeyPressed( DIK_F1 ) )
            {
                if ( !CurrentMenu )
                {
                    MenuRestart( &MENU_DebugHelp );
                }
                else if ( CurrentMenu == &MENU_DebugHelp )
                {
                    MenuExit();
                }
            }

            if ( IsKeyPressed( DIK_F2 ) )
            {
                if ( IsKeyHeld( DIK_LCONTROL ) || IsKeyHeld( DIK_RCONTROL ) )
                    SetFOV( chosen_fov = normal_fov );
                else
                    SetFOV( chosen_fov = FOV_GROW( hfov ) );
            }

            if ( IsKeyPressed( DIK_F3 ) )
            {
                if ( IsKeyHeld( DIK_LCONTROL ) || IsKeyHeld( DIK_RCONTROL ) )
                    SetFOV( chosen_fov = normal_fov );
                else
                    SetFOV( chosen_fov = FOV_SHRINK( hfov ) );
            }

            if ( IsKeyPressed( DIK_F4 ) )
            {
                if ( !CurrentMenu )
                {
                    MenuRestart( &MENU_GotoRoom );
                }
            }

            if ( IsKeyPressed( DIK_F5 ) )
            {
                InitShipStartPos( WhoIAm, ++startpos );
                AddMessageToQue( "You are now in %s\n", Mloadheader.Group[ Ships[ WhoIAm ].Object.Group ].name );
            }

            if ( IsKeyPressed( DIK_F6 ) )
            {
                DoClipping = !DoClipping;
            }

            if ( IsKeyPressed( DIK_F7 ) )
            {
                ShowBoundingBoxes = !ShowBoundingBoxes;
            }

            if ( IsKeyPressed( DIK_F8 ) )
            {
                ShowEFZones = !ShowEFZones;
            }

            if ( IsKeyPressed( DIK_F9 ) )
            {
                if( ShowPortal == 4 ) ShowPortal = 0;
                else ShowPortal++;
            }

            if ( IsKeyPressed( DIK_F10 ) )
            {
                ShowColZones = !ShowColZones;
            }

#ifdef POLYGONAL_COLLISIONS
            if ( IsKeyPressed( DIK_F11 ) )
            {
                if( ShowSkin == 6 ) ShowSkin = 0;
                else ShowSkin++;
            }
#endif // POLYGONAL_COLLISIONS

            if( IsKeyPressed( DIK_F12 ) )
            {
                no_collision = !no_collision;
            }
        }else
        {
            if ( DebugInfo && ( IsKeyHeld( DIK_LCONTROL ) || IsKeyHeld( DIK_RCONTROL ) ) )
            {
                if ( IsKeyPressed( DIK_F1 ) )
                {
                    ShowTeleports = !ShowTeleports;
                }
            
                if ( IsKeyPressed( DIK_F2 ) )
                {
                    ShowTrigZones = !ShowTrigZones;
                }

            }else // normal game keys
            {

                if ( ( IsKeyHeld( DIK_LSHIFT ) || IsKeyHeld( DIK_RSHIFT ) ) )
                {
#ifndef SELF_PLAY

                    if ( IsKeyPressed( DIK_F6 ) )
                    {
                        PingNonGuarenteed();
                    }
                    if ( IsKeyPressed( DIK_F7 ) )
                    {
                        PingGuarenteed();
                    }
                    
                    
                    
                    if ( IsKeyPressed( DIK_F9 ) )
                    {
                        if ( !CurrentMenu )
                        {
                            MenuRestart( &MENU_EditMacro1 );
                        }
                        else if ( CurrentMenu == &MENU_EditMacro1 )
                        {
                            MenuExit();
                        }
                    }
                    if ( IsKeyPressed( DIK_F10 ) )
                    {
                        if ( !CurrentMenu )
                        {
                            MenuRestart( &MENU_EditMacro2 );
                        }
                        else if ( CurrentMenu == &MENU_EditMacro2 )
                        {
                            MenuExit();
                        }
                    }

                    if ( IsKeyPressed( DIK_F11 ) )
                    {
                        if ( !CurrentMenu )
                        {
                            MenuRestart( &MENU_EditMacro3 );
                        }
                        else if ( CurrentMenu == &MENU_EditMacro3 )
                        {
                            MenuExit();
                        }
                    }
#endif


                }else{

#ifndef SELF_PLAY
                    if( MyGameStatus == STATUS_SinglePlayer )
                    {
                        if ( IsKeyPressed( DIK_F10 ) )
                        {
                            NextTextMessage();
                        }
                        if ( IsKeyPressed( DIK_F9 ) )
                        {
                            LastTextMessage();
                        }
                    }else{
                        if ( IsKeyPressed( DIK_F9 ) )
                        {
                            SendGameMessage(MSG_TEXTMSG, 0, 0, TEXTMSGTYPE_Taunt1, 0);
                        }

                        if ( IsKeyPressed( DIK_F10 ) )
                        {
                            SendGameMessage(MSG_TEXTMSG, 0, 0, TEXTMSGTYPE_Taunt2, 0);
                        }

                        if ( IsKeyPressed( DIK_F11 ) )
                        {
                            SendGameMessage(MSG_TEXTMSG, 0, 0, TEXTMSGTYPE_Taunt3, 0);
                        }
                    }
#endif

                    if ( IsKeyPressed( DIK_F6 ) )
                    {
                        RearCameraActive ^=1;
                    }
    
#if !defined( PCIDENT ) && !defined( SHAREWARE )
                    if ( IsKeyPressed( DIK_F5 ) )
                    {
                        MissileCameraEnable ^=1;
                    }
                
                    // E3Demo some F keys are disabled.....
                    if( !DebugInfo && ( ECTSDemo || E3DemoClient || E3DemoLoop ) )
                        return;
                
#ifdef REMOTE_CAMERA_ENABLED
                    if ( IsKeyPressed( DIK_F8 ) )
                    {
                        if( !RemoteCameraActive )
                        {
                            RemoteCameraActive = TRUE;
                            Ships[MAX_PLAYERS].Object.Pos = Ships[WhoIAm].Object.Pos;
                            Ships[MAX_PLAYERS].Object.Group = Ships[WhoIAm].Object.Group;
                            Ships[MAX_PLAYERS].Object.Mode = NORMAL_MODE;
                            Ships[MAX_PLAYERS].enable = 1;
                            Current_Camera_View = MAX_PLAYERS;      // which object is currently using the camera view....
                        }else{
                            RemoteCameraActive = FALSE;
                            Ships[MAX_PLAYERS].enable = 0;
                            Current_Camera_View = WhoIAm;       // which object is currently using the camera view....
                        }
                    }
#endif
#endif
                    if ( IsKeyPressed( DIK_F1 )  )
                    {
                        if ( !CurrentMenu )
                        {
                            MenuRestart( &MENU_Controls );
                        }
                        else if ( CurrentMenu == &MENU_Controls )
                        {
                            MenuExit();
                        }
                    }
                    if ( IsKeyPressed( DIK_F2 )  )
                    {
                        if ( !CurrentMenu )
                        {
                            MenuRestart( &MENU_Options );
                        }
                        else if ( CurrentMenu == &MENU_Options )
                        {
                            MenuExit();
                        }
                    }
#if !defined( PCIDENT ) && !defined( SHAREWARE )
                    if ( MyGameStatus != STATUS_Normal )
                    {
                        // check for quick load/save only in single player
                        if ( IsKeyPressed( DIK_F3 ) ) // quick load
                        {
                            if ( !CurrentMenu )
                            {
                                MenuRestart( &MENU_LoadSavedGame );
                            }
                            else if ( CurrentMenu == &MENU_LoadSavedGame )
                            {
                                MenuExit();
                            }
                        }
                        
                        if ( IsKeyPressed( DIK_F4 ) ) // quick save
                        {
                            if ( !CurrentMenu )
                            {
                                MenuRestart( &MENU_SaveGame );
                            }
                            else if ( CurrentMenu == &MENU_SaveGame )
                            {
                                MenuExit();
                            }
                        }
                    }

                    if ( IsKeyPressed( DIK_F7 ) )
                    {
                        // toggle panel text
                        Panel = !Panel;
                    }
        
#if 0
                    if ( IsKeyPressed( DIK_F8 ) )
                    {
                        if( DebugInfo )
                        {
                            if( TargetComputerOn ) TargetComputerOn = FALSE;
                            else TargetComputerOn = TRUE;
                        }
                    }
#endif
#endif
                }
            }
        }
    }
}



/*-------------------------------------------------------------------
    Handle all things keys
-------------------------------------------------------------------*/
int My_Key_Up ( WPARAM wParam , LPARAM lParam )
{
    switch( wParam )
    {
    case VK_PAUSE:
        if( !( E3DemoClient || E3DemoLoop ) )
        {
#if !defined( SELF_PLAY ) && !defined( PCIDENT ) && !defined( EXTERNAL_DEMO )
            return 2; // signal pause
#endif
            break;
        }else{
            break;
        }
    }
    return 0;
}


void My_Key_Down ( WPARAM wParam , LPARAM lParam )
{
    switch( wParam )
    {
        case VK_ESCAPE:
        case VK_F12:
            break;
    }
}


/*-------------------------------------------------------------------
    Procedure   :       Set the View Matrix
    Input       :       nothing...  Current_Camera_View must be set
                                    to a legal ship number...
    Output      :       nothing
-------------------------------------------------------------------*/

void Build_View()
{
    VECTOR  Trans;
    VECTOR  Trans2;

    
    Trans.x = -CurrentCamera.Pos.x;
    Trans.y = -CurrentCamera.Pos.y;
    Trans.z = -CurrentCamera.Pos.z;

    ApplyMatrix( &CurrentCamera.InvMat, &Trans, &Trans2 );          /* Set Translation */

    view._11 = CurrentCamera.Mat._11; 
    view._12 = CurrentCamera.Mat._12;
    view._13 = CurrentCamera.Mat._13;
    view._14 = CurrentCamera.Mat._14;
               
    view._21 = CurrentCamera.Mat._21;
    view._22 = CurrentCamera.Mat._22;
    view._23 = CurrentCamera.Mat._23;
    view._24 = CurrentCamera.Mat._24;
               
    view._31 = CurrentCamera.Mat._31;
    view._32 = CurrentCamera.Mat._32;
    view._33 = CurrentCamera.Mat._33;
    view._34 = CurrentCamera.Mat._34;
                                          
    view._41 = Trans2.x;
    view._42 = Trans2.y;
    view._43 = Trans2.z;
    view._44 = CurrentCamera.Mat._44;
}


char TriggerName[256];

/*-------------------------------------------------------------------
    Procedure   :       Inits And Loads New Level..
    Input       :       nothing...
    Output      :       nothing
-------------------------------------------------------------------*/
BOOL ChangeLevel( void )
{
    //if( NewLevelNum != LevelNum )
    //{
        LevelNum = NewLevelNum;

//      NumGoldBars = 0;
        
        ReleaseLevel();
        KillNodeCubeLines();
        KillBoxLines();

        NextworkOldKills = -1;
        NextworkOldDeaths = -1;
        NextworkOldBikeNum = -1;

        ActiveRemoteCamera = NULL;
        MissileCameraActive = 0;
        CameraMissile = (uint16) -1;

        DPlayGetSessionDesc();

        if (glpdpSD && glpDP )
        {
            // call LevelCheckSum init
            InitCheckSum( &glpdpSD->guidInstance );
        }else{
            LevelCheckSum = 0;
        }




        // for patch, only single player requires CD
        if( ( ( MyGameStatus == STATUS_PostStartingSinglePlayer ) ||
              ( MyGameStatus == STATUS_SinglePlayer ) ||
              ( MyGameStatus == STATUS_TitleLoadGamePostStartingSinglePlayer ) )
          && !ValidCD() )
        {
            Msg( "Forsaken CD required" );
            SeriousError = TRUE;
            return( FALSE );
        }

        InitScene();
        InitTextMessages();
        InitMultiSfxHandle();

        OnceOnlyChangeLevel = TRUE;
        ChangeLevel_MyGameStatus = MyGameStatus;
        Change_Ext( &LevelNames[ LevelNum ][ 0 ], &TriggerName[ 0 ], ".TRG" );
        if( !Triggerload( TriggerName ) )
        {
            SeriousError = TRUE;
            return( FALSE );
        }

        MyGameStatus = STATUS_ChangeLevelPostInitView;
        InitView();
    //}
    return( TRUE );
}

void DrawLoadingBox( int current_loading_step, int current_substep, int total_substeps )
{
    HRESULT hr;
    DDBLTFX fx;
    RECT    dest, darkgreen, lightgreen;
    float xmin, xmax, ymin, ymax, loaded, one_step;
    int total_loading_steps = 11;
    int BarXMin = 20;
    int BarXMax = 180;
    int BarYMin = 155;
    int BarYMax = 160;
    float BorderX, BorderY;

    // if not in mission loading screen ( buffer flips disabled ), do not display loading status
    if ( !PreventFlips )
        return;

//  BorderX = (float)floor(ModeScaleX[ModeCase]);
//  BorderY = (float)floor(ModeScaleY[ModeCase]);
    BorderX = 1.0F;
    BorderY = 1.0F;

    if( d3dappi.szClient.cx >= 512 && d3dappi.szClient.cy >= 384 )
    {
        //coords for high res font...
        darkgreen.left = 10;
        darkgreen.right = 11;
        darkgreen.top = 194;
        darkgreen.bottom = 195;

        lightgreen.left = 50;
        lightgreen.right = 51;
        lightgreen.top = 194;
        lightgreen.bottom = 195;

    }else
    {
        //coords for low res font...
        darkgreen.left = 2;
        darkgreen.right = 3;
        darkgreen.top = 122;
        darkgreen.bottom = 123;

        lightgreen.left = 10;
        lightgreen.right = 11;
        lightgreen.top = 122;
        lightgreen.bottom = 123;
    }


    if ( !BorderX)
        BorderX = 1.0F;
    if ( !BorderY)
        BorderY = 1.0F;

    memset( &fx, 0, sizeof( DDBLTFX ) );
    fx.dwSize = sizeof( DDBLTFX );

    xmin = (BarXMin + VDUoffsetX) * ModeScaleX[ModeCase];
    xmax = (BarXMax + VDUoffsetX) * ModeScaleX[ModeCase];
    ymin = (BarYMin + VDUoffsetY) * ModeScaleY[ModeCase];
    ymax = (BarYMax + VDUoffsetY) * ModeScaleY[ModeCase];

    loaded = (float)current_loading_step / (float)total_loading_steps;
    xmax = ( ( xmax - xmin ) * loaded ) + xmin;

    loaded = (float)current_substep / (float)total_substeps;

    one_step = (float)( xmax - xmin ) / (float)total_loading_steps;
    one_step *= loaded;
    xmax += one_step;

    // specify co-ordinates to plot to...
    dest.left = (LONG)xmin;
    dest.right = (LONG)xmax;
    dest.top = (LONG)ymin;
    dest.bottom = (LONG)ymax;

    //DebugPrintf("blitted to l:%d r:%d t:%d b:%d\n", dest.left, dest.right, dest.top, dest.bottom );
    
    hr = d3dapp->lpFrontBuffer->lpVtbl->Blt( d3dapp->lpFrontBuffer, &dest, lpDDSTwo, &darkgreen, DDBLT_KEYSRC  | DDBLT_WAIT, &fx );
    if ( hr != DD_OK )
    {
        DebugPrintf("%s", D3DAppErrorToString(hr));
    }

    // top...
    dest.left = (LONG) ( (BarXMin + VDUoffsetX) * ModeScaleX[ModeCase]) ;
    dest.right = (LONG)((BarXMax + VDUoffsetX) * ModeScaleX[ModeCase]);
    dest.top = (LONG)((BarYMin - BorderY + VDUoffsetY) * ModeScaleY[ModeCase]);
    dest.bottom = (LONG)((BarYMin + VDUoffsetY) * ModeScaleY[ModeCase]);
    hr = d3dapp->lpFrontBuffer->lpVtbl->Blt( d3dapp->lpFrontBuffer, &dest, lpDDSTwo, &lightgreen, DDBLT_KEYSRC  | DDBLT_WAIT, &fx );
    // bottom...
    dest.left = (LONG) ( (BarXMin + VDUoffsetX) * ModeScaleX[ModeCase]) ;
    dest.right = (LONG)((BarXMax + VDUoffsetX) * ModeScaleX[ModeCase]);
    dest.top = (LONG)((BarYMax + VDUoffsetY) * ModeScaleY[ModeCase]);
    dest.bottom = (LONG)((BarYMax + BorderY + VDUoffsetY) * ModeScaleY[ModeCase]);
    hr = d3dapp->lpFrontBuffer->lpVtbl->Blt( d3dapp->lpFrontBuffer, &dest, lpDDSTwo, &lightgreen, DDBLT_KEYSRC  | DDBLT_WAIT, &fx );
    
    // left...
    dest.left = (LONG) ( (BarXMin - BorderX + VDUoffsetX) * ModeScaleX[ModeCase]) ;
    dest.right = (LONG)((BarXMin + VDUoffsetX) * ModeScaleX[ModeCase]);
    dest.top = (LONG)((BarYMin - BorderY + VDUoffsetY) * ModeScaleY[ModeCase]);
    dest.bottom = (LONG)((BarYMax + BorderY + VDUoffsetY) * ModeScaleY[ModeCase]);
    hr = d3dapp->lpFrontBuffer->lpVtbl->Blt( d3dapp->lpFrontBuffer, &dest, lpDDSTwo, &lightgreen, DDBLT_KEYSRC  | DDBLT_WAIT, &fx );
    // right...
    dest.left = (LONG) ( (BarXMax + VDUoffsetX) * ModeScaleX[ModeCase]) ;
    dest.right = (LONG)((BarXMax + BorderX + VDUoffsetX) * ModeScaleX[ModeCase]);
    dest.top = (LONG)((BarYMin - BorderY + VDUoffsetY) * ModeScaleY[ModeCase]);
    dest.bottom = (LONG)((BarYMax + BorderY + VDUoffsetY) * ModeScaleY[ModeCase]);
    hr = d3dapp->lpFrontBuffer->lpVtbl->Blt( d3dapp->lpFrontBuffer, &dest, lpDDSTwo, &lightgreen, DDBLT_KEYSRC  | DDBLT_WAIT, &fx );
}

static void UpdateKillsTime( void )
{   
    int i;

    // update session description with current leading kills & elapsed time...
    if ( !glpdpSD )
    {
        DPlayGetSessionDesc();
    }

    if ( glpdpSD )
    {
        uint16 highest_score = 0;
        uint16 minutes_left, old_minutes_left, old_highest_score;
        
        // if current level elapsed time is more than 1 min than stored elapsed time, store in SD
        minutes_left = ( uint16 ) ( ( Countdown_Float / 100.0F ) / 60.0F );
        if ( minutes_left > 30 )
            minutes_left = 30;
        old_minutes_left = ( uint16 ) ( ( glpdpSD->dwUser3 & CurrentGameTimeBits ) >> CurrentGameTime_Shift );

        if ( minutes_left != old_minutes_left )
        {
            glpdpSD->dwUser3 &= ~CurrentGameTimeBits;
            glpdpSD->dwUser3 |=  ( minutes_left << CurrentGameTime_Shift );

            if ( DPlaySetSessionDesc( 1 ) != DP_OK )
            {
                DebugPrintf("RenderScene(): Unable to set session desc!!\n");
            }
        }

        // find highest score
        if ( !TeamGame )
        {
            for( i = 0 ; i < MAX_PLAYERS ; i++ )
            {
                if ( ( i == WhoIAm ) || ( GameStatus[ i ] == STATUS_Normal ) )
                {
                    if ( Ships[ i ].Kills > highest_score )
                    {
                        highest_score = Ships[ i ].Kills;
                    }
                }
            }
        }else
        {
            uint16 current_team_score[ MAX_TEAMS ];

            memset( current_team_score, 0, sizeof( uint16 ) * MAX_TEAMS );

            for ( i = 0; i < MAX_PLAYERS; i++ )
            {
                if ( ( i == WhoIAm ) || ( GameStatus[ i ] == STATUS_Normal ) )
                {
                    current_team_score[ TeamNumber[ i ] ] += Ships[ i ].Kills;
                }
            }

            for ( i = 0; i < MAX_TEAMS; i++ )
            {
                if ( current_team_score[ i ] > highest_score )
                {
                    highest_score = current_team_score[ i ];
                }
            }
        }

        if ( highest_score > 255 )
            highest_score = 255;

        old_highest_score = ( uint16 ) ( ( glpdpSD->dwUser2 & CurrentMaxKillsBits ) >> CurrentMaxKills_Shift );

        if ( old_highest_score != highest_score )
        {
            glpdpSD->dwUser2 &= ~CurrentMaxKillsBits;
            glpdpSD->dwUser2 |= ( highest_score << CurrentMaxKills_Shift );

            if ( DPlaySetSessionDesc( 1 ) != DP_OK )
            {
                DebugPrintf("RenderScene(): Unable to set session desc!!\n");
            }
        }
    }
}

void GetLevelName( char *buf, int bufsize, int level )
{
    FILE *f;
    char *pCh;
    
    buf[ 0 ] = 0;

    if ( level < 0 )
        return;
    
    f = fopen( MissionTextNames[ level ], "r" );
    if ( f )
    {
        // read level name
        if ( !fgets( buf, bufsize, f ) )
        {
            // if error ( as oposed to end of file )
            if ( ferror( f ) != 0 )
            {
                buf[ 0 ] = 0;
            }
        }
    }
    if ( !buf[ 0 ] )
    {
        strncpy( buf, LevelList.item[ level ], bufsize );
    }

    pCh = strchr( buf, '\n' );
    if ( pCh )
        *pCh = 0;
    
    buf[ bufsize - 1 ] = 0; // ensure null terminated 
}

void StoreLevelNameInSessionDesc( char *str )
{
    char buf[ MAX_LEVEL_NAME_LENGTH + MAX_SESSION_DESC_LENGTH + 1 ];    // extra 1 for '~' char
    char *pCh;
    
    DPlayGetSessionDesc();
    if ( glpdpSD )
    {
        strncpy( buf, glpdpSD->lpszSessionNameA, MAX_SESSION_DESC_LENGTH );
        buf[ MAX_SESSION_DESC_LENGTH - 1 ] = 0; // ensure null terminated 

        pCh = strchr( buf, '~' );
        if ( pCh )
        {
            pCh++;
        }else
        {
            pCh = buf + strlen( buf );
            *pCh++ = '~';
        }

        strncpy( pCh, str, MAX_LEVEL_NAME_LENGTH );

        buf[ MAX_LEVEL_NAME_LENGTH + MAX_SESSION_DESC_LENGTH ] = 0; // ensure null terminated 

        UpdateSessionName( buf );
    }
}

float   Browl = 0.0F;
float QuitTime = 0.0F;
float   HostMultiPlayerTimeout;

int colourflash = 0;
char NodeName[256];
BOOL CreditsToggle = FALSE;

extern LPDPLCONNECTION glpdplConnection;
BOOL SetZCompare( void );

/*-------------------------------------------------------------------
    Procedure   :       Game Status Control...
    Input       :       nothing...
    Output      :       nothing
-------------------------------------------------------------------*/
BOOL
RenderScene(LPDIRECT3DDEVICE Null1, LPDIRECT3DVIEWPORT Null2 )
{
    uint16  i,e,o;
    char    buf[256];
    char full_level_name[ MAX_LEVEL_NAME_LENGTH ];
    LPDIRECTDRAWPALETTE ddpal;
    LPDIRECTDRAW lpDD = d3dapp->lpDD;
    LPDIRECT3D lpD3D = d3dapp->lpD3D;
    LPDIRECT3DDEVICE lpDev = d3dapp->lpD3DDevice;
    LPDIRECT3DVIEWPORT lpView = d3dapp->lpD3DViewport;
//  struct _stat stat_buf;
//  int result;
    static int WaitFrames = 2;
    BOOL done;
    DWORD       Temp;
    BYTE        msg;
    int         size;
    LONGLONG    TempTime;
    HRESULT hr;
    LONGLONG    Time_Freq;
    LONGLONG    Time_Value;
    float       Time_Float;
    float       time_diff;

    if ( SeriousError )
        return FALSE;

//  if ( !Bsp_Identical( &Bsp_Header[ 0 ], &Bsp_Original ) )
//  {
//      hr = 0;
//  }

    CalculateFramelag();
    AnimOncePerFrame++;



#ifdef CD_LOOP_THREAD
    if ( cd_info.IsPlaying )
    {
        EnterCriticalSection( &CDKey );

        if ( timeGetTime() > CDFinishTime )
        {
            CdStop();
            RestartCDTrack = TRUE;
        }
            
        LeaveCriticalSection( &CDKey );
    }
#endif

#if 0
    QuitTime -= framelag;
    if( QuitTime <= 0.0F )
    {
        QuitTime = 60.0F * 5.0F;
        result = _stat( "quit.bat", &stat_buf );
        if( result == 0 )
        {
            // file exists..
            quitting = TRUE;
            return FALSE;
        }
    }
#endif

    if ( bSoundEnabled )
    {
        EnterCriticalSection (&SfxKey);
    
        CheckSBufferList();
    
        LeaveCriticalSection (&SfxKey);
    }

#ifndef MULTIPLE_READINPUTS
    ReadInput();
#endif

    switch( MyGameStatus )
    {
    case STATUS_TryingToFindSession:
        D3DAppClearScreenOnly();

        if ( GeneralTimeout( &FindSessionTimeout ) )
        {
            PrintErrorMessage( CANNOT_FIND_SESSION, 0, NULL, ERROR_QUIT );
            MyGameStatus = STATUS_Title;
            break;
        }

        // search for matching session
        SessionsList.selected_item = -1;
        for ( i = 0; i < SessionsList.items; i++ )
        {
            if ( IsEqualGuid( &Sessions[ i ].guidInstance, &autojoin_session_guid ) )
            {
                SessionsList.selected_item = i;
                break;
            }
        }
        if( (SessionsList.selected_item != -1) && SessionsRefresh[SessionsList.selected_item] )
        {
            SelectSession( NULL );
        }
        else
        {
            CenterPrint4x5Text( SEARCHING_FOR_GAME , (d3dappi.szClient.cy>>1) , 2 );
            GetCurrentSessions_ReScan( NULL );
        }
        break;
    case STATUS_QuittingFromTitles:
        quitting = TRUE;
        if ( IsLobbyLaunched )
        {
            if ( IsHost )
            {
                free( glpdplConnection );
                glpdplConnection = NULL;
                free( glpdpSD );
                glpdpSD = NULL;
            }
        }
        break;
    case STATUS_QuittingFromInGame:
        StopCompoundSfx();
        OutputVisiStats( &Mloadheader, LevelNames[ LevelNum ] );
        MenuAbort();
        DestroyGame();  // DestroyGame changes MyGameStatus..So Set it back
        MyGameStatus = STATUS_QuittingFromInGame;
        ReleaseLevel();
        quitting = TRUE;
        break;
    case STATUS_SplashScreen:
        
        if ( NewSplashScreens[ NewCurrentSplashScreen ].flags & SPLASH_Timed )
        {
            DWORD currenttime = timeGetTime();

#ifdef WORK_IN_PROGRESS
            if ( ( NewSplashScreens[ NewCurrentSplashScreen ].flags & SPLASH_AccessCD ) && ( currenttime > ( SplashFinishTime - 500 ) ) )
            {
                char file[ 128 ];
                FILE    *   fp;
                uint32 dummy32;

                //NewSplashScreens[ NewCurrentSplashScreen ].flags & ~SPLASH_AccessCD;

                strcpy( file, normdata_path );
                strcat( file, "splash\\main.avi" );

                fp = fopen( file, "rb" );
                fread( &dummy32, sizeof( uint32 ), 1, fp );
                fclose( fp );
            }
#endif
            
            if ( currenttime > SplashFinishTime )
            {
                MyGameStatus = STATUS_FinishedShowingSplashScreen;
                break;
            }
        }

        if ( NewSplashScreens[ NewCurrentSplashScreen ].flags & SPLASH_Return )
        {
            if ( AnyKeyPressed() )
            {
                MyGameStatus = STATUS_FinishedShowingSplashScreen;
                break;
            }
        }

        if ( NewSplashScreens[ NewCurrentSplashScreen ].splashinfo->SplashDisplayFunc )
        {
            if ( !NewSplashScreens[ NewCurrentSplashScreen ].splashinfo->SplashDisplayFunc( NewSplashScreens[ NewCurrentSplashScreen ].splashinfo->SplashDisplayVar ) )
            {
                MyGameStatus = STATUS_FinishedShowingSplashScreen;
            }
        }
            
        break;
        
    case STATUS_FinishedShowingSplashScreen:
             
        if ( NewSplashScreens[ NewCurrentSplashScreen ].flags & SPLASH_ShowNext )
        {
            // call post splash function
            if ( NewSplashScreens[ NewCurrentSplashScreen ].splashinfo->PostSplashFunc )
                NewSplashScreens[ NewCurrentSplashScreen ].splashinfo->PostSplashFunc( NewSplashScreens[ NewCurrentSplashScreen ].splashinfo->PostSplashVar );

            // increment splash screen
            NewCurrentSplashScreen++;

            MyGameStatus = STATUS_SplashScreen;

            // set finish time if required
            if ( NewSplashScreens[ NewCurrentSplashScreen ].flags & SPLASH_Timed )
            {
                SplashFinishTime = timeGetTime() + NewSplashScreens[ NewCurrentSplashScreen ].time;
            }

            // call initialization function
            if ( NewSplashScreens[ NewCurrentSplashScreen ].splashinfo->PreSplashFunc )
            {
                if ( !NewSplashScreens[ NewCurrentSplashScreen ].splashinfo->PreSplashFunc( NewSplashScreens[ NewCurrentSplashScreen ].splashinfo->PreSplashVar ) )
                {
                    MyGameStatus = STATUS_FinishedShowingSplashScreen;
                }
            }
        }
        else
        {
            // finished current batch of splash screens...

            // restore old game status
            MyGameStatus = PreSplash_MyGameStatus; 

            // restore old menu status
            CurrentMenu = PreSplash_Menu;
            CurrentMenuItem = PreSplash_MenuItem;

            // call post splash function    ( now that game status has been changed back )
            if ( NewSplashScreens[ NewCurrentSplashScreen ].splashinfo->PostSplashFunc )
                NewSplashScreens[ NewCurrentSplashScreen ].splashinfo->PostSplashFunc( NewSplashScreens[ NewCurrentSplashScreen ].splashinfo->PostSplashVar );

        }
        
        break;
    case STATUS_WaitingToStartSinglePlayer:
        
        if( DisplayTitle() != TRUE )
        {
            SeriousError = TRUE;
            return FALSE;
        }
        
        done = VduFinished( &MENU_NEW_BetweenLevels );
            
        if ( done )
            WaitFrames--;
        if ( !WaitFrames )
        {
            WaitFrames = 2;
            PreventFlips = TRUE;
            CurrentLoadingStep = 1;
            DrawLoadingBox( CurrentLoadingStep++, 0, 1 );

            StartASinglePlayerGame( NULL );
        }
        
        break;
    case STATUS_WaitingToStartDemo:
        if( DisplayTitle() != TRUE )
        {
            SeriousError = TRUE;
            return FALSE;
        }
        done = VduFinished( &MENU_NEW_StartAttractMode );
            
        if ( done )
            WaitFrames--;
        if ( !WaitFrames )
        {
            WaitFrames = 2;
            PreventFlips = TRUE;
            CurrentLoadingStep = 1;
            LastMenu = CurrentMenu;
            VduClear();
            DrawLoadingBox( CurrentLoadingStep++, 0, 1 );
            ReleaseView();
            MyGameStatus = STATUS_Title;

            if( !CreditsToggle )
            {
                ShowSplashScreen( SPLASHSCREEN_AttractMode );
            }
            else
            {
                ShowSplashScreen( SPLASHSCREEN_Credits );
                SetupCredits();
            }
        }
        break;
    case STATUS_WaitingToStartEndGameSequence:
        if( DisplayTitle() != TRUE )
        {
            SeriousError = TRUE;
            return FALSE;
        }
        done = VduFinished( &MENU_NEW_GeneralLoading );
            
        if ( done )
            WaitFrames--;
        if ( !WaitFrames )
        {
            WaitFrames = 2;
            PreventFlips = TRUE;
            CurrentLoadingStep = 1;
            DrawLoadingBox( CurrentLoadingStep++, 0, 1 );

            MyGameStatus = STATUS_Title;
            ReleaseView();

            switch( GameCompleted )
            {
            case GAMECOMPLETE_WithoutAllCrystals:
            case GAMECOMPLETE_WithAllCrystalsExceptLast:
                SetupGameCompleteCredits();
                ShowSplashScreen( SPLASHSCREEN_GameComplete );
                break;
            case GAMECOMPLETE_WithAllCrystals:
                SetupGameCompleteCredits();
                ShowSplashScreen( SPLASHSCREEN_SpecialGameComplete );
                break;
            default:
                SetupGameCompleteCredits();
                ShowSplashScreen( SPLASHSCREEN_GameComplete );
            }
        }
        break;
    case STATUS_WaitingToStartMultiPlayerHost:
        Browl -= framelag;

        if( Browl <= 0.0F )
        {
            Browl = 30.0F;
            if( dcoID )
            {
                SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
            }
        }
        ReceiveGameMessages();

        if( DisplayTitle() != TRUE )
        {
            SeriousError = TRUE;
            return FALSE;
        }
        if ( VduFinished( NULL ) )
            WaitFrames--;
        if ( !WaitFrames )
        {
            WaitFrames = 2;
            PreventFlips = TRUE;
            CurrentLoadingStep = 1;
            DrawLoadingBox( CurrentLoadingStep++, 0, 1 );
            MyGameStatus = STATUS_StartingMultiplayer;
            GoToSynchup( NULL );
        }
        break;
    case STATUS_WaitingToStartMultiPlayerClient:
        Browl -= framelag;

        if( Browl <= 0.0F )
        {
            Browl = 30.0F;
            if( dcoID )
            {
                SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
            }
        }
        ReceiveGameMessages();

        if( DisplayTitle() != TRUE )
        {
            SeriousError = TRUE;
            return FALSE;
        }
        if ( VduFinished( NULL ) )
            WaitFrames--;
        if ( !WaitFrames )
        {
            WaitFrames = 2;
            LastMenu = CurrentMenu;
            VduClear();
            
            PreventFlips = TRUE;
            CurrentLoadingStep = 1;
            DrawLoadingBox( CurrentLoadingStep++, 0, 1 );

            MenuAbort();
            ReleaseView();
            LevelNum = -1;

            MyGameStatus = STATUS_PreStartingMultiplayerSynch;
            if( !ChangeLevel() ) 
                return( FALSE );
        }
        break;
    case STATUS_WaitingToStartTeamGame:
        Browl -= framelag;

        if( Browl <= 0.0F )
        {
            Browl = 30.0F;
            if( dcoID )
            {
                SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
            }
        }
        ReceiveGameMessages();

        if( DisplayTitle() != TRUE )
        {
            SeriousError = TRUE;
            return FALSE;
        }

        if ( VduFinished( NULL ) )
            WaitFrames--;
        if ( !WaitFrames )
        {
            WaitFrames = 2;
            LastMenu = CurrentMenu;
            VduClear();
            
            MenuAbort();

            PreventFlips = TRUE;
            CurrentLoadingStep = 1;
            DrawLoadingBox( CurrentLoadingStep++, 0, 1 );

            MyGameStatus = PreSynchupStatus;
        }

        if( IMustQuit )
            SpecialDestroyGame();

        break;
    case STATUS_Title:
    case STATUS_BetweenLevels:
    case STATUS_Copyright:
        if( DisplayTitle() != TRUE )
        {
            SeriousError = TRUE;
            return FALSE;
        }
        break;

    case STATUS_Normal:
        
        PreventFlips = FALSE;




        if ( !CheatsDisabled )
            DisableCheats();
    
        if( IMustQuit )
            SpecialDestroyGame();

        if( IsServer )
        {
            if( ServerMainGame( lpDev , lpView ) != TRUE )
                return FALSE;
        }else{
            if( MainGame( lpDev , lpView ) != TRUE )
                return FALSE;
        }

        if ( IsHost )
        {
            UpdateKillsTime();
            UpdatePlayerInfo();
        }

        
        if ( IsServer )
        {
            if ( !CheckPlayersActive() )
            {
                // no players active....reset back to titles
                QuickStart = QUICKSTART_Server;
                SelectQuitCurrentGame( NULL );
                PreventFlips = FALSE;
            }
        }


        if ( bSoundEnabled )
        {
            ProcessLoopingSfx();
#ifdef PLAYER_SPEECH_TAUNTS
            ProcessTaunt();
#endif
        }

        LevelTimeTaken += framelag;

        // if player is quiting nothing should stop him.....
        if( ( MyGameStatus != STATUS_QuitCurrentGame ) && ( MyGameStatus != STATUS_QuittingFromInGame ) )
        {
            if( IsHost )
            {
                if( NewLevelNum != LevelNum )
                {
                    // disable players joining...
                    DPlayGetSessionDesc();
                    
                    //glpdpSD->dwFlags = DPSESSION_MIGRATEHOST | DPSESSION_KEEPALIVE | DPSESSION_NEWPLAYERSDISABLED | DPSESSION_JOINDISABLED;
                    glpdpSD->dwFlags |= DPSESSION_NEWPLAYERSDISABLED | DPSESSION_JOINDISABLED;

                    DPlaySetSessionDesc(0);

                    for( i = 0 ; i < MAX_PLAYERS ; i++ )
                    {
                        if( (GameStatus[i] != STATUS_LeftCrashed ) && (GameStatus[i] != STATUS_Left ) && (GameStatus[i] != STATUS_Null ) && i != WhoIAm )
                        {
                            if( GameStatus[i] != STATUS_Normal )
                            {
                                SendGameMessage(MSG_YOUQUIT, 0, (BYTE) i , 0, 0);
                            }
                        }
                    }
                    // the level has ended or changed ..tell everyone to go onto new level
                    MyGameStatus = STATUS_LevelEnd;
                    GameStatus[WhoIAm] = MyGameStatus;
                    RandomStartPosModify += 1;
                    SendGameMessage(MSG_LONGSTATUS, 0, 0, 0, 0);
                    ProcessGuaranteedMessages( FALSE , TRUE , FALSE );
                    ServiceBigPacket(TRUE);
                    ServiceServer( TRUE );

                }
            }else{
                if( OverallGameStatus == STATUS_LevelEnd )
                {
                    // tell the host that I am now in the same state as him....
                    MyGameStatus = OverallGameStatus;
                    GameStatus[WhoIAm] = MyGameStatus;
                    SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
                }
            }
        }

        if ( WaitingToQuit )
        {
            D3DAppClearScreenOnly();
            CenterPrint4x5Text( PLEASE_WAIT, (d3dappi.szClient.cy>>1)-(FontHeight>>1) , 2 );
            SelectQuitCurrentGame( NULL );
        }
        break;
    case STATUS_LevelEnd:
        D3DAppClearScreenOnly();

        ReceiveGameMessages();
        Browl -= framelag;

        StopDemoRecording();

        if( Browl <= 0.0F )
        {
            if( IsHost )
            {
                if( dcoID )
                {
                    SendGameMessage(MSG_LONGSTATUS, 0, 0, 0, 0);
                }
            }else{
                if( dcoID )
                {
                    SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
                }
            }
            Browl = 30.0F;
        }
        if( IsHost )
        {

            // have all the enabled players switched over to STATUS_LevelEnd??
            for( i = 0 ; i < MAX_PLAYERS ; i++ )
            {
                if( ( Ships[i].enable != 0 ) && ( GameStatus[i] != STATUS_LevelEnd ) && ( i != WhoIAm ) )
                    break;
            }
            if( i != MAX_PLAYERS )
                break;  // not yet..
            OutputVisiStats( &Mloadheader, LevelNames[ LevelNum ] );
            // un load all graphics
            ReleaseView();
            ReleaseLevel();
            // tell them all they can now look at the scores...
            MyGameStatus = STATUS_ViewingScore;
            GameStatus[WhoIAm] = MyGameStatus;
            SendGameMessage(MSG_LONGSTATUS, 0, 0, 0, 0);
            ProcessGuaranteedMessages( FALSE , TRUE , FALSE );
            ServiceBigPacket(TRUE);
            ServiceServer( TRUE );

            InitScene();    // STATSTEST
            InitView();
            NextworkOldKills = -1;
            NextworkOldDeaths = -1;
            NextworkOldBikeNum = -1;
            HostMultiPlayerTimeout = 60.0F * 60.0F * 2.0F * 2.0F;
        }else{
            if( MyGameStatus != OverallGameStatus )
            {
                OutputVisiStats( &Mloadheader, LevelNames[ LevelNum ] );
                // un load all graphics
                ReleaseView();
                ReleaseLevel();
                // tell the host that I am now in the same state as him....
                MyGameStatus = STATUS_ViewingScore;

                GameStatus[WhoIAm] = MyGameStatus;
                SendGameMessage(MSG_STATUS, 0, 0, 0, 0);

                InitScene();    // STATSTEST
                InitView();
                NextworkOldKills = -1;
                NextworkOldDeaths = -1;
                NextworkOldBikeNum = -1;
                HostMultiPlayerTimeout = 60.0F * 60.0F * 2.0F * 2.0F;
            }
        }
        break;
    case STATUS_ViewingScore:

        ReceiveGameMessages();

        Browl -= framelag;
        if( Browl <= 0.0F )
        {
            if( IsHost )
            {
                if( dcoID )
                {
                    SendGameMessage(MSG_LONGSTATUS, 0, 0, 0, 0);
                }
            }else{
                if( dcoID )
                {
                    SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
                }
            }
            Browl = 30.0F;
        }

        ScoreDisplay();
#ifdef MULTIPLE_READINPUTS
        ReadInput();
#endif

        HostMultiPlayerTimeout -= framelag;

        if( IsKeyPressed( DIK_SPACE ) ||
            ( OverallGameStatus == STATUS_WaitingAfterScore ) ||
            ( IsServer && ( HostMultiPlayerTimeout < ( (60.0F * 60.0F * 2.0F * 2.0F) - ( 30.0F * 60.0F ) ) ) )
            )
        {
            D3DAppIClearBuffers();
            if( !IsServer )
                HostMultiPlayerTimeout = 60.0F * 60.0F * 2.0F;
            else
                HostMultiPlayerTimeout = 60.0F * 60.0F * 2.0F * 2.0F;

            if( IsHost )
            {
                // store full level name in session desc
                GetLevelName( full_level_name, MAX_LEVEL_NAME_LENGTH, NewLevelNum );
                StoreLevelNameInSessionDesc( full_level_name );
                RegSetA( "LevelName",  (LPBYTE)LevelList.item[ NewLevelNum ] , sizeof( LevelList.item[ NewLevelNum ] ) );

//              if ( IsLobbyLaunched )
//              {
//                  MyGameStatus = STATUS_QuittingFromInGame;
//              }else
                {
                    // tell them all I Am waiting
                    ReleaseView();
                    MyGameStatus = STATUS_WaitingAfterScore;
                    GameStatus[WhoIAm] = MyGameStatus;
                    SendGameMessage(MSG_LONGSTATUS, 0, 0, 0, 0);
                    ProcessGuaranteedMessages( FALSE , TRUE , FALSE );
                    ServiceBigPacket(TRUE);
                    ServiceServer( TRUE );
                    if( !ChangeLevel() ) return( FALSE );
                }
            }else{
//                  if ( IsLobbyLaunched )
//                  {
//                      MyGameStatus = STATUS_QuittingFromInGame;
//                  }else
                {
                    // tell the host that I am now Waiting for him to finish viewing the score....
                    ReleaseView();
                    MyGameStatus = STATUS_WaitingAfterScore;
                    GameStatus[WhoIAm] = MyGameStatus;

                    if( !ChangeLevel() ) return( FALSE );
                }
            }
        }
        break;
    case STATUS_WaitingAfterScore:

        InitFontTransTable( TRUE );
        D3DAppClearScreenOnly();
        e = 0;

        if( IsHost )
        {
            Printuint16( (uint16) (HostMultiPlayerTimeout / 60.0F) , 0 , 0 , 2 );
            HostMultiPlayerTimeout -= framelag;
        }

        if( DS )
        {
            DisplayStatusMessages();
        }else{

            for( i = 0 ; i < MAX_PLAYERS ; i++ )
            {
                if( MaxKills || ResetKillsPerLevel )
                {
                    Ships[i].Kills = 0;
                    Ships[i].Deaths = 0;
                    for( o = 0 ; o < MAX_PLAYERS ; o++ )
                    {
                        Stats[i][o] = 0;
                    }
                }
                
                if( (GameStatus[i] != STATUS_LeftCrashed ) && (GameStatus[i] != STATUS_Left ) && (GameStatus[i] != STATUS_Null ) )
                {

    //              if( GameStatus[i] == STATUS_ViewingScore )
    //              {
    //                  wsprintf( buf, "%-8s status %8s\n", &Names[i][0] , "viewing score" );
    //                  CenterPrint4x5Text( &buf[0] , (d3dappi.szClient.cy>>1)-( ( (FontHeight+2) * MAX_PLAYERS ) >> 1 )+ (e * (FontHeight+(FontHeight>>1)) ) , GameStatus[i] == STATUS_StartingMultiplayerSynch ? 2 : 1 );
    //              }
    //              else
                    {
                        wsprintf( buf, "%-8s status %14s\n", &Names[i][0] , &StatusTab[ GameStatus[i] ][0] );
                        CenterPrint4x5Text( &buf[0] , (d3dappi.szClient.cy>>1)-( ( (FontHeight+2) * MAX_PLAYERS ) >> 1 )+ (e * (FontHeight+(FontHeight>>1)) ) , GameStatus[i] == STATUS_WaitingAfterScore ? 2 : 1 );
                    }
                    
                    e++;
                }
            }
        }
        CenterPrint4x5Text( "waiting for all other players" , (d3dappi.szClient.cy>>1)-(FontHeight>>1) + ( ( FontHeight+2) * (MAX_PLAYERS+1)) , (colourflash>>3) &3);

        Browl -= framelag;
        if( Browl < 0.0F )
        {
            colourflash++;
            if( IsHost )
            {
                if( dcoID )
                {
                    SendGameMessage(MSG_LONGSTATUS, 0, 0, 0, 0);
                }
            }else{
                if( dcoID )
                {
                    SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
                }
            }
            Browl = 30.0F;
        }
        ReceiveGameMessages();

        if( IsHost )
        {

            // have all the enabled players switched over to STATUS_LevelEnd??
            for( i = 0 ; i < MAX_PLAYERS ; i++ )
            {
                if( ( ( ( GameStatus[ i ] >= STATUS_InitView_0 ) && ( GameStatus[ i ] <= STATUS_InitView_9 ) ) || ( GameStatus[i] == STATUS_ViewingScore ) ) && ( i != WhoIAm ) ) break;
            }
            if( HostMultiPlayerTimeout >= 0.0F )
            {
                if( i != MAX_PLAYERS )
                    break;  // not yet..
            }
            // tell them all they can now restart a new level...
            if( CountDownOn || BombTag )
            {
                InitBombs();
                CreateCountdownDigits();
                StartCountDown( (int16) TimeLimit.value, 0 );
            }

            DebugPrintf("STATUS_WaitingAfterScore setting MyGameStatus to STATUS_Normal\n");
            MyGameStatus = STATUS_Normal;
            InitFontTransTable( !bPolyText );
            GameStatus[WhoIAm] = MyGameStatus;
            SendGameMessage(MSG_LONGSTATUS, 0, 0, 0, 0);
            ProcessGuaranteedMessages( FALSE , TRUE , FALSE );
            ServiceBigPacket(TRUE);
            ServiceServer( TRUE );

            DPlayGetSessionDesc();

            if ( glpdpSD )
            {
                // re-enable joining.....
                glpdpSD->dwFlags &= ~( DPSESSION_NEWPLAYERSDISABLED | DPSESSION_JOINDISABLED );
                DPlaySetSessionDesc( 1 );
            }

        }else{
            if( OverallGameStatus == STATUS_Normal )
            {
                InitFontTransTable( !bPolyText );

                if( CountDownOn || BombTag )
                {
                    InitBombs();
                    CreateCountdownDigits();
                    StartCountDown( (int16) TimeLimit.value, 0 );
                }
                // tell the host that I am now in the same state as him....
                MyGameStatus = OverallGameStatus;
                GameStatus[WhoIAm] = MyGameStatus;
                SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
            }
        }
        break;

    case STATUS_Joining:
        PreventFlips = FALSE;
        D3DAppClearScreenOnly();

        ReceiveGameMessages();
        if( IMustQuit || IsHost || ( OverallGameStatus != STATUS_Normal ) )
        {
            SpecialDestroyGame();
            break;
        }
        Browl -= framelag;
        if( Browl <= 0.0F )
        {
            Browl = 30.0F;
            if( dcoID )
            {
                SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
            }
        }

        CenterPrint4x5Text( "Pickups Left   " , (d3dappi.szClient.cy>>1)-(FontHeight<<2), 8 );
        Printuint16( (uint16) Ships[WhoIAm].Pickups , (d3dappi.szClient.cx>>1)+((17*FontWidth>>1)), (d3dappi.szClient.cy>>1)-(FontHeight<<2), 2 );

        CenterPrint4x5Text( "RegenSlots Left" , (d3dappi.szClient.cy>>1)-(FontHeight<<1), 8 );
        Printuint16( (uint16) Ships[WhoIAm].RegenSlots , (d3dappi.szClient.cx>>1)+((17*FontWidth>>1)), (d3dappi.szClient.cy>>1)-(FontHeight<<1), 2 );

        CenterPrint4x5Text( "Mines Left     " , (d3dappi.szClient.cy>>1), 8 );
        Printuint16( (uint16) Ships[WhoIAm].Mines , (d3dappi.szClient.cx>>1)+((17*FontWidth>>1)), (d3dappi.szClient.cy>>1), 2 );

        CenterPrint4x5Text( "Triggers Left  " , (d3dappi.szClient.cy>>1)+(FontHeight<<1), 8 );
        Printuint16( (uint16) Ships[WhoIAm].Triggers , (d3dappi.szClient.cx>>1)+((17*FontWidth>>1)), (d3dappi.szClient.cy>>1)+(FontHeight<<1), 2 );

        CenterPrint4x5Text( "TrigVars Left  " , (d3dappi.szClient.cy>>1)+(FontHeight<<2), 8 );
        Printuint16( (uint16) Ships[WhoIAm].TrigVars , (d3dappi.szClient.cx>>1)+((17*FontWidth>>1)), (d3dappi.szClient.cy>>1)+(FontHeight<<2), 2 );
        
        // wait for all the pickup and mine stuff to be sent to me.....
        if( ( Ships[WhoIAm].Pickups == 0 ) && ( Ships[WhoIAm].Mines == 0 ) && ( Ships[WhoIAm].RegenSlots == 0 ) &&
            ( Ships[WhoIAm].Triggers == 0 ) && ( Ships[WhoIAm].TrigVars == 0 ) && OverallGameStatus == STATUS_Normal)
        {
            // broadcast "x is joining the game" to all players...
            if (TeamGame)
                SendGameMessage(MSG_TEXTMSG, 0, 0, TEXTMSGTYPE_JoiningTeamGame, 0);

            MyGameStatus = OverallGameStatus;
            QueryPerformanceCounter((LARGE_INTEGER *) &GameStartedTime);
            GameStatus[WhoIAm] = OverallGameStatus;
            SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
            SyncMines();
            InitShipRandomPos( WhoIAm );
            if( Rejoining && !TeamGame )
            {
                Ships[WhoIAm].Kills = (int16) Old_Kills;
                Ships[WhoIAm].Deaths = (int16) Old_Deaths;
                TeamNumber[WhoIAm] = (BYTE) Old_TeamNumber;
            }
            NextworkOldKills = -1;
            NextworkOldDeaths = -1;
            NextworkOldBikeNum = -1;
            SendGameMessage(MSG_NAME, 0, 0, 0, 0);
            SendGameMessage(MSG_SENDKILLSDEATHSBIKENUM, 0, 0, 0, 0);
            if( CountDownOn || BombTag )
            {
                InitBombs();
                CreateCountdownDigits();
                StartCountDown( (int16) TimeLimit.value, 0 );
                IllegalTime = TRUE;
            }
        }
        break;

    case STATUS_StartingMultiplayer:

        Browl -= framelag;

        if( Browl <= 0.0F )
        {
            Browl = 30.0F;
            if( dcoID )
            {
                if( TeamGame &&  (OverallGameStatus == STATUS_Normal) )
                {
//                  SendGameMessage(MSG_SENDKILLSDEATHSBIKENUM, 0, 0, 0, 0);
                }
                SendGameMessage(MSG_STATUS, 0, 0, 0, 0);

                if ( IsServer )
                {
                    static int first_of_batch = 0;
                    
                    DPlayGetSessionDesc();
                    if ( ( glpdpSD->dwUser3 & ServerGameStateBits ) == SERVER_STATE_HostChoosing )
                    {
                        SendGameMessage( MSG_LEVELNAMES, 0, 0, (BYTE)first_of_batch, 0 );
                        first_of_batch += MAXLEVELSPERBATCH;
                        if ( first_of_batch >= LevelList.items )
                        {
                            first_of_batch = 0;
                        }
                    }
                }
            }
        }

        ReceiveGameMessages();

        if( ( MyGameStatus == STATUS_QuitCurrentGame ) || ( MyGameStatus == STATUS_Title ) )
        {
            break;
        }
        
        if( ( CurrentMenu ) && ( CurrentMenuItem ) )
        {
            if( DisplayTitle() != TRUE )
                return FALSE;
        }

        // if status has been changed from titles, should exit this state straight away
        if ( MyGameStatus != STATUS_StartingMultiplayer )
            break;

        if( ( IsHost ) && ( !CurrentMenu ) && ( !CurrentMenuItem ) )
        {
            // disable players joining...
            DPlayGetSessionDesc();
            
            //glpdpSD->dwFlags = DPSESSION_MIGRATEHOST | DPSESSION_KEEPALIVE | DPSESSION_NEWPLAYERSDISABLED | DPSESSION_JOINDISABLED;
//          if( !IsServer )
            glpdpSD->dwFlags |= DPSESSION_NEWPLAYERSDISABLED | DPSESSION_JOINDISABLED;

            DPlaySetSessionDesc(0);
            D3DAppIClearBuffers();
            ReleaseView();
            // tell them all to load up a level
            MyGameStatus = STATUS_StartingMultiplayerSynch;
            GameStatus[WhoIAm] = MyGameStatus;
            SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
            ServiceBigPacket(TRUE);
            ServiceServer( TRUE );

            LevelNum = -1;
            if( !ChangeLevel() ) return( FALSE );
            if( !IsServer )
                HostMultiPlayerTimeout = 60.0F * 60.0F * 2.0F;
            else
                HostMultiPlayerTimeout = 60.0F * 60.0F * 2.0F * 2.0F;
        }
        else
        {
            if( !IsHost )
            {
                if( ( OverallGameStatus == STATUS_StartingMultiplayerSynch ) || 
                    ( (OverallGameStatus == STATUS_Normal) && (!TeamGame || PlayerReady[WhoIAm]) ) )
                {

                    if ((CameraStatus == CAMERA_AtLeftVDU) || (CameraStatus == CAMERA_AtRightVDU))
                    {   
                        //LastMenu = CurrentMenu;
                        //VduClear();
                        MenuChangeEx( &MENU_NEW_GeneralLoading );
                        MenuDraw( CurrentMenu );    // because menu processing will not be done when MyGameStatus changes
                    }else
                        D3DAppIClearBuffers();


                    PreSynchupStatus = MyGameStatus;
                    MyGameStatus = STATUS_WaitingToStartMultiPlayerClient;
                }
            }else
            {
                UpdatePlayerInfo();
            }
        }
        break;
    case    STATUS_PreStartingMultiplayerSynch:
        PreventFlips = FALSE;

        ReceiveGameMessages();
        if( IMustQuit )
        {
            SpecialDestroyGame();
            break;
        }
        MyGameStatus = STATUS_StartingMultiplayerSynch;
        if( OverallGameStatus == STATUS_Normal )
        {
            initShip( WhoIAm );
            MyGameStatus = STATUS_Joining;
            Browl = 0.0F;
        }else{
            smallinitShip( WhoIAm );
            MyGameStatus = STATUS_StartingMultiplayerSynch;
        }
        SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
        GameStatus[WhoIAm] = MyGameStatus;
        break;

    case    STATUS_StartingMultiplayerSynch:
        PreventFlips = FALSE;
        InitFontTransTable( TRUE );

        ReceiveGameMessages();

        if( IMustQuit )
        {
            SpecialDestroyGame();
            break;
        }

        D3DAppClearScreenOnly();
        e = 0;

        if( DS )
        {
            DisplayStatusMessages();
        }else{
            for( i = 0 ; i < MAX_PLAYERS ; i++ )
            {
                if( ( GameStatus[i] != STATUS_GetPlayerNum )&& (GameStatus[i] != STATUS_LeftCrashed ) && (GameStatus[i] != STATUS_Left ) && (GameStatus[i] != STATUS_Null ) )
                {
                    wsprintf( buf, "%-8s status %14s\n", &Names[i][0] , &StatusTab[ GameStatus[i] ][0] );
                    CenterPrint4x5Text( &buf[0] , (d3dappi.szClient.cy>>1)-( ( (FontHeight+2) * MAX_PLAYERS ) >> 1 )+ (e * (FontHeight+(FontHeight>>1)) ) , GameStatus[i] == STATUS_StartingMultiplayerSynch ? 2 : 1 );
                    e++;
                }
            }
        }
        CenterPrint4x5Text( "all players synching" , (d3dappi.szClient.cy>>1)-(FontHeight>>1) + ( ( FontHeight+2) * (MAX_PLAYERS+1)) , (colourflash>>3) &3);
        Browl -= framelag;
        if( Browl <= 0.0F )
        {
            colourflash++;
            Browl = 30.0F;
            if( dcoID )
            {
                SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
            }
        }

        if( CountDownOn || BombTag )
        {
            InitBombs();
            CreateCountdownDigits();
            StartCountDown( (int16) TimeLimit.value, 0 );
            IllegalTime = FALSE;
        }

        if( IsHost )
        {
            Printuint16( (uint16) (HostMultiPlayerTimeout / 60.0F) , 0 , 0 , 2 );
            HostMultiPlayerTimeout -= framelag;

            // have all the enabled players switched over to STATUS_StartingMultiplayer??
            for( i = 0 ; i < MAX_PLAYERS ; i++ )
            {
                if( (GameStatus[i] != STATUS_GetPlayerNum ) &&(GameStatus[i] != STATUS_LeftCrashed ) && (GameStatus[i] != STATUS_Left ) && ( (GameStatus[i] != STATUS_Null ) && ( GameStatus[i] != STATUS_StartingMultiplayerSynch ) ) && ( i != WhoIAm ) )
                    break;
            }
            if( HostMultiPlayerTimeout >= 0.0F )
            {
                if( i != MAX_PLAYERS )
                    break;  // not yet..
            }
            // tell them all they can now restart a new level...
            QueryPerformanceCounter((LARGE_INTEGER *) &GameStartedTime);
            DebugPrintf("STATUS_StartingMultiplayerSynch setting MyGameStatus to STATUS_Normal\n");
            MyGameStatus = STATUS_Normal;
            GameStatus[WhoIAm] = STATUS_Normal;
            SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
            ServiceBigPacket(TRUE);
            ServiceServer( TRUE );

            NextworkOldKills = -1;
            NextworkOldDeaths = -1;
            NextworkOldBikeNum = -1;
            InitFontTransTable( !bPolyText );

            // enable players to join again...
            if( !E3DemoHost && !E3DemoClient )
            {
                DPlayGetSessionDesc();
                
                //glpdpSD->dwFlags = DPSESSION_MIGRATEHOST | DPSESSION_KEEPALIVE;
                glpdpSD->dwFlags &= ~( DPSESSION_NEWPLAYERSDISABLED | DPSESSION_JOINDISABLED );

                DPlaySetSessionDesc(0);
            }
        }else{
            if( OverallGameStatus == STATUS_Normal )
            {
                QueryPerformanceCounter((LARGE_INTEGER *) &GameStartedTime);
                MyGameStatus = OverallGameStatus;
                GameStatus[WhoIAm] = MyGameStatus;
                SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
                NextworkOldKills = -1;
                NextworkOldDeaths = -1;
                NextworkOldBikeNum = -1;
                InitFontTransTable( !bPolyText );
            }
        }
        break;
    
    case STATUS_QuitCurrentGame:
        StopCompoundSfx();
        OutputVisiStats( &Mloadheader, LevelNames[ LevelNum ] );
        MenuAbort();
        MenuRestart( &MENU_Start );
        DestroyGame();  // DestroyGame changes MyGameStatus..So Set it back
        MyGameStatus = STATUS_QuitCurrentGame;
        ReleaseView();
        ReleaseLevel();


        if ( PreDemoEndMyGameStatus == STATUS_AttractMode )
        {
            PreDemoEndMyGameStatus = 0;

            MyGameStatus = STATUS_Title;
        }
        else
        {
            MyGameStatus = STATUS_Title;

            InitScene();
            InitView();
        }
        break;
    case STATUS_WaitingForLobbyConnect:

        ReceiveGameMessages();

        Browl -= framelag;

        if( Browl <= 0.0F )
        {
            Browl = 30.0F;

            // reget session info..
            hr = DPlayGetSessionDesc();
            if ( hr != DP_OK )
            {
                DebugPrintf("DPlayGetSessionDesc not OK\n");
            }

            if ( glpdpSD )
            {
                if ( glpdpSD->dwUser4 != 0 )
                {
                    switch ( glpdpSD->dwUser3 & ServerGameStateBits )
                    {
                    case SERVER_STATE_NoServer:     
                    case SERVER_STATE_Joinable:     
                        if( TeamGame )
                        {
                            JoinASessionEx( &MENU_NEW_WatchTeamSelect );
                        }else
                        {
                            JoinASessionEx( &MENU_NEW_JoinWaitingToStart );
                        }
                        break;
                    case SERVER_STATE_NeedHost:     
                        JoinASessionEx( &MENU_NEW_CreateGamePseudoHost );
                        break;
                    case SERVER_STATE_HostChoosing: 
                        D3DAppClearScreenOnly();
                        CenterPrint4x5Text( HOST_IS_SETTING_UP_GAME, (d3dappi.szClient.cy>>1)-(FontHeight>>1) , 2 );
                        break;
                    }
                }
            }else
            {
                DebugPrintf("no DPlay ptr!\n");
            }
        }

        if( DisplayTitle() != TRUE )
        {
            SeriousError = TRUE;
            return FALSE;
        }
        DebugPrintf("STATUS_WaitingForLobbyConnect 3\n");

        break;
    case STATUS_GetPlayerNum:
        D3DAppClearScreenOnly();
        ReceiveGameMessages();
        
        CenterPrint4x5Text( "Requesting Player Number" , (d3dappi.szClient.cy>>1)-(FontHeight>>1) + ( ( FontHeight+2) * (MAX_PLAYERS+1)) , 2 );
                                                                                
        sprintf( &buf[0] , "Attempt %d\n" , GetPlayerNumCount );
        CenterPrint4x5Text( &buf[0] , (d3dappi.szClient.cy>>1)-(FontHeight>>1) , 2 );

        
        GetPlayerNumCount1 -= framelag;
        GetPlayerNumCount2 -= framelag;

        if( WhoIAm != 0xff )
        {
            if( WhoIAm == MAX_PLAYERS )
            {
                PrintErrorMessage ( "The Game is Currently Un-Joinable", 3, NULL, ERROR_USE_MENUFUNCS );
                MyGameStatus = STATUS_Title;
                break;
            }
            if( WhoIAm == MAX_PLAYERS+1 )
            {
                PrintErrorMessage ( "You Dont have the level they are playing", 3, NULL, ERROR_USE_MENUFUNCS );
                MyGameStatus = STATUS_Title;
                break;
            }
            if( WhoIAm == MAX_PLAYERS+2 )
            {
                PrintErrorMessage ( "The Game is Full", 3, NULL, ERROR_USE_MENUFUNCS );
                MyGameStatus = STATUS_Title;
                break;
            }

            if( Rejoining )
            {
                Ships[WhoIAm].Kills = (int16) Old_Kills;
                Ships[WhoIAm].Deaths = (int16) Old_Deaths;
                TeamNumber[WhoIAm] = (BYTE) Old_TeamNumber;
            }
            memset(&Names, 0, sizeof(SHORTNAMETYPE) );
#ifdef ECTS
            for( i = 0 ; i < 8 ; i++ )
            {
                // force player to use same name as his bike
                Names[WhoIAm][i] = BikeList.item[WhoIAm % MAXBIKETYPES][i];
            }
            Names[WhoIAm][7] = 0;
            Ships[WhoIAm].BikeNum = (int16) WhoIAm % MAXBIKETYPES;
#else
            strncpy( (char*) &Names[WhoIAm][0] , &biker_name[0] , 7 );
            Names[WhoIAm][7] = 0;
            Ships[ WhoIAm ].BikeNum = ( SelectedBike % MAXBIKETYPES );
#endif
                  
            Old_Session = *glpdpSD;
            strcpy( (char*) &Old_Name[0] , (char*) &biker_name[0] );
        
            MyGameStatus = STATUS_StartingMultiplayer;
            MenuState = MENUSTATE_Select;

            SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
            SendGameMessage(MSG_NAME, 0, 0, 0, 0);
            SendGameMessage(MSG_SENDKILLSDEATHSBIKENUM, 0, 0, 0, 0);
            ServiceBigPacket(TRUE);
            ServiceServer( TRUE );

// hack for ramdemo...
            if( RecordDemoToRam )
                RecordDemo = TRUE;

            if( RecordDemo )
            {
                DemoFp = fopen( "Test.dmo" , "wb" );
                setvbuf( DemoFp, NULL, _IONBF , 0 );        // size of stream buffer...
                for( i = 0 ; i < 256 ; i++ )
                {
                    Demo_fwrite( &ShortLevelNames[NewLevelNum][i], sizeof(char), 1, DemoFp );
                    if( ShortLevelNames[NewLevelNum][i] == 0 )
                    {
                        break;
                    }
                }
                // Best way I can Think of to send the Host Name to the demo file...
                Temp = 1;
                TempTime = 1;
                Demo_fwrite( &TempTime, sizeof(LONGLONG), 1, DemoFp );
                size = sizeof( NAMEMSG );
                Demo_fwrite( &size, sizeof(int), 1, DemoFp );
                Demo_fwrite( &Temp, sizeof(DWORD), 1, DemoFp );
                msg = MSG_NAME;
                Demo_fwrite( &msg, sizeof(BYTE), 1, DemoFp );
                msg = WhoIAm;
                Demo_fwrite( &msg, sizeof(BYTE), 1, DemoFp );               // Whos Name it is..
                Demo_fwrite( &biker_name[0], 7, 1, DemoFp );
                msg = 0;
                Demo_fwrite( &msg, sizeof(BYTE), 1, DemoFp );               // terminator for name..
            }

            // menu change is done when session description is changed for lobby session
            if ( IsPseudoHost )
            {
                MyGameStatus = STATUS_GetLevelNames;
                PseudoHostAck_Timeout = PSEUDOHOST_WAIT_TIME;
            }else
            {
                MenuChangeEx( GetPlayerNumMenu );
            }
            break;
        }

        if( GetPlayerNumCount2 <= 0.0F )
        {
            // Time is Up No Player Number was got so quit back to the title screen...
            PrintErrorMessage ( "Couldnt Get a Player Number", 3, NULL, ERROR_USE_MENUFUNCS );
            MyGameStatus = STATUS_Title;
            break;
//          BailMultiplayer( (MENU*) NULL );
//          MenuRestart( &MENU_Start );
//          MyGameStatus = STATUS_Title;
        }

        if( GetPlayerNumCount1 <= 0.0F )
        {
            GetPlayerNumCount++;

            // Time to send another request for a Player Number...
            GetPlayerNumCount1 = 60.0F;     // approx 1 Second...
            SendGameMessage(MSG_HEREIAM, 0, 0, 0, 0);   // can I join your game...
            DebugPrintf("sending MSG_HEREIAM\n");
        }

        break;
    case STATUS_GetLevelNames:
        D3DAppClearScreenOnly();

        if ( GeneralTimeout( &PseudoHostAck_Timeout ) )
        {
            if( dcoID )
            {
                DPlayDestroyPlayer(dcoID);
                dcoID = 0;
            }

            DPlayRelease();
            MyGameStatus = STATUS_Title;
            RefreshDPlay();

            OKToJoinSession = FALSE;
            break;
        }

        ReceiveGameMessages();
        Browl -= framelag;
        if( Browl <= 0.0F )
        {
            Browl = 30.0F;
            if( dcoID )
            {
                SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
            }
        }

        CenterPrint4x5Text( QUERYING_SERVER_FOR_LEVELS, (d3dappi.szClient.cy>>1)-(FontHeight>>1) , 2 );

        switch( ServerLevelsListState )
        {
        case SERVERLEVELS_None:
            SendGameMessage(MSG_TOSERVER, 0, 0, TOSERVERMSG_Reset, 0);
            PrintErrorMessage("you do not have any of the levels on this server", 0, NULL, ERROR_DONTUSE_MENUFUNCS );
            PreWaitingToSendMessagesStatus = STATUS_Title;
            MyGameStatus = STATUS_WaitingToSendMessages;    // to ensure all guaranteed messages get sent
            SessionsList.selected_item = -1;
            MySessionsList.selected_item = -1;

            break;
        case SERVERLEVELS_Got:
            MenuChangeEx( &MENU_NEW_CreateGamePseudoHost );
            MyGameStatus = STATUS_StartingMultiplayer;
            MenuState = MENUSTATE_Select;
            break;
        }

        break;
    case STATUS_PlayingDemo:

        DemoGameLoops++;

        if( DemoSpeed.value > 8 )
        {
            // slower or normal playback speed...
            Demoframelag = 1.0F / (float) ( DemoSpeed.value - 7 );
        }else{
            Demoframelag = 1.0F * (float) ( 9 - DemoSpeed.value );
        }
        
        Oldframelag = framelag;

        if( PauseDemo )
        {
            framelag = 0.0F;
        }else{
            framelag *= Demoframelag;
        }

        if( DemoScreenGrab && !CurrentMenu )
        {
//          framelag = 2.24F;       // 30 fps
            framelag = 2.613333F;   // 25 fps
            Demoframelag = 1.0F;
            Oldframelag = framelag;
        }

        if( DemoScreenGrab && !CurrentMenu )
        {
            sprintf( fname, "ScreenS\\scr%04d.ppm", fnum );
//          _spawnl( _P_WAIT, "grab.exe", "grab.exe", "-fp" , "-w 512" , "-h 384" , fname, NULL );
            folder_exists( FMVSNAPSHOT_FOLDER );
            SaveFullScreenSnapShot( fname );
            fnum++;
            if( fnum > 9999 )
            {
                DemoScreenGrab = FALSE;
            }
        }

        if( MainGame( lpDev , lpView ) != TRUE )
            return FALSE;

        break;


    case STATUS_InitView_0:
        if( IsHost )
        {
            SendGameMessage(MSG_LONGSTATUS, 0, 0, 0, 0);
        }else{
            SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
        }
        ProcessGuaranteedMessages( FALSE , TRUE , FALSE );
        ServiceBigPacket(TRUE);
        ServiceServer( TRUE );


        DrawLoadingBox( CurrentLoadingStep++, 0, 1 );

        D3DAppClearScreenOnly();


        MenuFrozen = FALSE; // ensure that menus are OK to use once in game
        JustExitedMenu = FALSE; 

        QuickStart = QUICKSTART_None;
        WaitingToQuit = FALSE;
    
        ReceiveGameMessages();

        if (bPrimaryPalettized )
        {
            lpPalette = DDLoadPalette( lpDD , "data\\pictures\\pal.bmp");
            ddpal =  DDLoadPalette( lpDD , "data\\pictures\\pal.bmp");
            d3dappi.lpFrontBuffer->lpVtbl->SetPalette( d3dappi.lpFrontBuffer, ddpal );
            d3dappi.lpBackBuffer->lpVtbl->SetPalette( d3dappi.lpBackBuffer, ddpal );
        }
    

        
        if( !SetMatrixViewPort() )
        {
            SeriousError = TRUE;
            Msg( "SetMatrixViewPort() failed\n" );
            return FALSE;
        }
        
        // Init the font....
        if( !IsServer )
        {
            InitFont(FALSE);
        }else{
            InitFont(TRUE);
        }
    
        MyGameStatus = STATUS_InitView_1;
        PrintInitViewStatus( MyGameStatus );
        break;
    

    case STATUS_InitView_1:
        if( IsHost )
        {
            SendGameMessage(MSG_LONGSTATUS, 0, 0, 0, 0);
        }else{
            SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
        }
        ProcessGuaranteedMessages( FALSE , TRUE , FALSE );
        ServiceBigPacket(TRUE);
        ServiceServer( TRUE );

        
        DrawLoadingBox( CurrentLoadingStep++, 0, 1 );

        AddCommentToBat( "Started Loading Level" );

        SetOurRenderStates( NULL );
        D3DAppClearScreenOnly();

        ReceiveGameMessages();

        // Create the offscreen surface, by loading our bitmap
        lpDDSOne = DDLoadBitmap( lpDD, "data\\pictures\\panel.bmp" , 0, 0 );
        ddpal =  DDLoadPalette( lpDD , "data\\pictures\\panel.bmp");
        lpDDSOne->lpVtbl->SetPalette( lpDDSOne , ddpal );
        DDSetColorKey( lpDDSOne, RGB_MAKE( 0 , 0 , 0 ) );
        // Create the offscreen surface, by loading our bitmap.
        if( ( ModeCase != -1 ) && ( DrawPanel == FALSE ) && DrawSimplePanel )
        {
            lpDDSThree = DDLoadBitmap( lpDD, (char*) &PanelNames[ModeCase] , 0, 0 );
            ddpal =  DDLoadPalette( lpDD , (char*) &PanelNames[ModeCase]);
            lpDDSThree->lpVtbl->SetPalette( lpDDSThree , ddpal );
            DDSetColorKey( lpDDSThree, RGB_MAKE( 255 , 0 , 255 ) );
            PanelHeight = PanelVisibleY[ModeCase];

            lpDDSFour = DDLoadBitmap( lpDD, "data\\pictures\\pcontent.bmp" , 0, 0 );
            ddpal =  DDLoadPalette( lpDD , "data\\pictures\\pcontent.bmp" );
            lpDDSFour->lpVtbl->SetPalette( lpDDSFour , ddpal );
        }
    

        FillInPanelPositions();
        ReMakeSimplePanel = TRUE;
        
//      InitVisiExecList( lpDev );
        InitSkinExecs();
        InitPortalExecs();
        InitRenderBufs( lpDev );

        // Init the Texture Handler
        if( !InitTload( &Tloadheader ) )
        {
            SeriousError = TRUE;
            Msg( "InitTLoad failed\n" );
            return FALSE;
        }
    
        //  Prep the Texture Handler.....
        if( !PreMload( (char*) &LevelNames[LevelNum][0] , &Mloadheader ) )
        {
            SeriousError = TRUE;
            return FALSE; // the model and visipoly data
        }


        // Can Cope with no .Wat file!!!
        PreWaterLoad( (char*) &WaterNames[LevelNum][0] );
        
        
        if( OnceOnlyChangeLevel )
        {
            OnceOnlyChangeLevel = FALSE;

            if( !PreLoadShips() )
            {
                SeriousError = TRUE;
                return FALSE;
            }

            if( !PreLoadBGOFiles() )
            {
                SeriousError = TRUE;
                return FALSE;
            }

            if( !PreLoadRestartPoints() )
            {
                SeriousError = TRUE;
                return FALSE;
            }

            if( !PreLoadEnemies() )
            {
                SeriousError = TRUE;
                return FALSE;
            }
        }

        if ( !LimitedLoad )
        {
            EnableRelavantModels( &ModelNames[0] );

            if( !PreInitModel( lpDev , &ModelNames[0] ) )
            {
                SeriousError = TRUE;
                return FALSE;
            }
        }else
        {
            if( !PreInitModel( lpDev , &SplashModelNames[0] ) )
            {
                SeriousError = TRUE;
                return FALSE;
            }
        }

        if ( !LimitedLoad )
        {
            if( !Load_All_Off_Files( &OffsetFiles[ 0 ] ) )
            {
                SeriousError = TRUE;
                return FALSE;
            }
        }else
        {
            if( !Load_All_Off_Files( &Splash_OffsetFiles[ 0 ] ) )
            {
                SeriousError = TRUE;
                return FALSE;
            }

        }

        InitLogos();

        MyGameStatus = STATUS_InitView_2;
        PrintInitViewStatus( MyGameStatus );
        break;
    

    case STATUS_InitView_2:
        if( IsHost )
        {
            SendGameMessage(MSG_LONGSTATUS, 0, 0, 0, 0);
        }else{
            SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
        }
        ProcessGuaranteedMessages( FALSE , TRUE , FALSE );
        ServiceBigPacket(TRUE);
        ServiceServer( TRUE );

        
        DrawLoadingBox( CurrentLoadingStep++, 0, 1 );

        D3DAppClearScreenOnly();

        ReceiveGameMessages();


        //  Load in And if nescessary ReScale Textures...   
        if( !Tload( &Tloadheader ) )
        {
            SeriousError = TRUE;
            return FALSE;
        }
    
        if ( !LimitedLoad ) FixTextureUVs( &OffsetFiles[ 0 ] );
        else FixTextureUVs( &Splash_OffsetFiles[ 0 ] );

        // Load all system memory textures...
        if( !SysTload( SystemMemTPages, CurrentSysTexture ) )
        {
            SeriousError = TRUE;
            return FALSE;
        }

        MyGameStatus = STATUS_InitView_3;
        PrintInitViewStatus( MyGameStatus );
        break;
    

    case STATUS_InitView_3:
        if( IsHost )
        {
            SendGameMessage(MSG_LONGSTATUS, 0, 0, 0, 0);
        }else{
            SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
        }
        ProcessGuaranteedMessages( FALSE , TRUE , FALSE );
        ServiceBigPacket(TRUE);
        ServiceServer( TRUE );


        DrawLoadingBox( CurrentLoadingStep++, 0, 1 );
        
        D3DAppClearScreenOnly();

        ReceiveGameMessages();

        if ( !LimitedLoad )
        {
            if( !InitModel( lpDev , &ModelNames[0] ) )
                {
                SeriousError = TRUE;
                return FALSE;                               // all 3d models....
            }
        }else
        {
            if( !InitModel( lpDev , &SplashModelNames[0] ) )
                {
                SeriousError = TRUE;
                return FALSE;                               // all 3d models....
            }
        }

        MyGameStatus = STATUS_InitView_4;
        PrintInitViewStatus( MyGameStatus );
        break;
    

    case STATUS_InitView_4:
        if( IsHost )
        {
            SendGameMessage(MSG_LONGSTATUS, 0, 0, 0, 0);
        }else{
            SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
        }
        ProcessGuaranteedMessages( FALSE , TRUE , FALSE );
        ServiceBigPacket(TRUE);
        ServiceServer( TRUE );


        DrawLoadingBox( CurrentLoadingStep++, 0, 1 );
        
        D3DAppClearScreenOnly();

        ReceiveGameMessages();

        if( !Mload( (char*) &LevelNames[LevelNum][0] , &Mloadheader ) )
        {
            SeriousError = TRUE;
            return FALSE; // the model and visipoly data
        }

        InitVisiStats( &Mloadheader );

        MyGameStatus = STATUS_InitView_5;
        PrintInitViewStatus( MyGameStatus );
        break;
    

    case STATUS_InitView_5:
        if( IsHost )
        {
            SendGameMessage(MSG_LONGSTATUS, 0, 0, 0, 0);
        }else{
            SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
        }
        ProcessGuaranteedMessages( FALSE , TRUE , FALSE );
        ServiceBigPacket(TRUE);
        ServiceServer( TRUE );


        DrawLoadingBox( CurrentLoadingStep++, 0, 1 );
        
        D3DAppClearScreenOnly();
        ReceiveGameMessages();

        // Can Cope with no Bsp file!!!
#ifdef LOAD_ZBSP
        Bspload( (char*) &BspZNames[LevelNum][0], &Bsp_Header[ 0 ] );
        Bspload( (char*) &BspNames[LevelNum][0], &Bsp_Header[ 1 ] );
#else
#ifdef BSP_ONLY
        if ( !Bspload( (char*) &BspNames[LevelNum][0], &Bsp_Header[ 0 ] ) )
        {
            SeriousError = TRUE;
            Msg( "Bspload failed\n" );
            return FALSE;       // the collision data
        }
#else
        Bspload( (char*) &BspNames[LevelNum][0], &Bsp_Header[ 0 ] ); // load .BSP file into 0 skin
#endif
        Bsp_Header[ 1 ].State = FALSE; // no non-zero .BSP any more
#endif
//      if ( !Bsp_Duplicate( &Bsp_Header[ 0 ], &Bsp_Original ) )
//      {
//          SeriousError = TRUE;
//          Msg( "Bsp_Duplicate failed\n" );
//          return FALSE;
//      }
        
        // might not be any water...
        WaterLoad();

        ReadTxtFile( (char*) &TextNames[LevelNum][0] );
        
        ReadMsgFile( (char*) &MsgNames[LevelNum][0] );
        
        if( !MCload( (char*) &CollisionNames[LevelNum][0] , &MCloadheader ) )
        {
            SeriousError = TRUE;
            Msg( "MCload non zero failed\n" );
            return FALSE;       // the collision data
        }
        if( !MCload( (char*) &CollisionZNames[LevelNum][0] , &MCloadheadert0 ) )
        {
            SeriousError = TRUE;
            Msg( "MCload zero failed\n" );
            return FALSE;   // the collision data skin thickness 0
        }
    
        SetUpShips();
    
        cursorclipped = TRUE;
        SetCursorClip();

        if( !InitSpecialExecBufs() )
        {
            SeriousError = TRUE;
            Msg( "InitSpecialExecBufs() failed\n" );
            return FALSE;
        }
        
//      TaskerInit();
//      TaskCreate( (TaskFunc) Test , 0 );

        MyGameStatus = STATUS_InitView_6;
        PrintInitViewStatus( MyGameStatus );

        break;

    case STATUS_InitView_6:
        if( IsHost )
        {
            SendGameMessage(MSG_LONGSTATUS, 0, 0, 0, 0);
        }else{
            SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
        }
        ProcessGuaranteedMessages( FALSE , TRUE , FALSE );
        ServiceBigPacket(TRUE);
        ServiceServer( TRUE );


        DrawLoadingBox( CurrentLoadingStep++, 0, 1 );
        
        D3DAppClearScreenOnly();
        ReceiveGameMessages();

        InitSoundInfo( &Mloadheader );
        
        MyGameStatus = STATUS_InitView_7;
        PrintInitViewStatus( MyGameStatus );
        break;
    case STATUS_InitView_7:
        if( IsHost )
        {
            SendGameMessage(MSG_LONGSTATUS, 0, 0, 0, 0);
        }else{
            SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
        }
        ProcessGuaranteedMessages( FALSE , TRUE , FALSE );
        ServiceBigPacket(TRUE);
        ServiceServer( TRUE );


        D3DAppClearScreenOnly();
        ReceiveGameMessages();


#ifdef NO_PRECALCULATED_CELL_COLOURS
        CreateCellColours( &Mloadheader );
#endif

        MyGameStatus = STATUS_InitView_8;
        PrintInitViewStatus( MyGameStatus );

        break;
    case STATUS_InitView_8:
        if( IsHost )
        {
            SendGameMessage(MSG_LONGSTATUS, 0, 0, 0, 0);
        }else{
            SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
        }
        ProcessGuaranteedMessages( FALSE , TRUE , FALSE );
        ServiceBigPacket(TRUE);
        ServiceServer( TRUE );


        D3DAppClearScreenOnly();
        ReceiveGameMessages();


        MyGameStatus = STATUS_InitView_9;
        PrintInitViewStatus( MyGameStatus );
        QueryPerformanceCounter((LARGE_INTEGER *) &LastTime);
        // dummy call to timer ensures no pauses later...
        timeSetEvent( 10, 10, TimerProc, (DWORD)-1, TIME_ONESHOT ); 

        InitShipSpeeds();

        MyGameStatus = InitView_MyGameStatus;

        Current_Max_Score = 0;  // used by host to store highest score in session desc

        break;
    case STATUS_ChangeLevelPostInitView:
        Change_Ext( &LevelNames[ LevelNum ][ 0 ], &NodeName[ 0 ], ".NOD" );

        if( !Nodeload( NodeName ) )
        {
            SeriousError = TRUE;
            return( FALSE );
        }

        if( !LoadBGOFiles() )
        {
            SeriousError = TRUE;
            return( FALSE );
        }

        if( !LoadEnemies() )
        {
            SeriousError = TRUE;
            Msg( "LoadEnemies() failed\n" );
            return( FALSE );
        }

        if( !LoadSpotFX() )
        {
            SeriousError = TRUE;
            Msg( "LoadSpotFX() failed\n" );
            return( FALSE );
        }

        if( !LoadStartPoints() )
        {
            SeriousError = TRUE;
            Msg( "LoadStartPoints() failed\n" );
            return( FALSE );
        }

        if( !LoadRestartPoints() )
        {
            SeriousError = TRUE;
            Msg( "LoadRestartPoints() failed\n" );
            return( FALSE );
        }

        if ( !LimitedLoad )
        {
            if ( !InitializeSound( DESTROYSOUND_All ))
            {
                Msg("InitializeSound() failed\n");
                return FALSE;
            }
        }


        Change_Ext( &LevelNames[ LevelNum ][ 0 ], &NodeName[ 0 ], ".CAM" );

        if( !Cameraload( NodeName ) )
        {
            SeriousError = TRUE;
            return( FALSE );
        }

        // might not be any real-time lights
        LoadRTLights();

        if ( CaptureTheFlag || CTF )
            GoalLoad();

        InitThermo();

        if( ( ChangeLevel_MyGameStatus == STATUS_SinglePlayer ) ||
            ( ChangeLevel_MyGameStatus == STATUS_PostStartingSinglePlayer ) ||
            ( ChangeLevel_MyGameStatus == STATUS_TitleLoadGamePostStartingSinglePlayer) )
        {
            LoadTimeForLevel();
        }

        if( !LoadPickupsPositions() )
        {
            SeriousError = TRUE;
            Msg( "LoadPickupsPositions() failed\n" );
            return( FALSE );
        }

        // might not be any External Forces...
        ExternalForcesLoad( (char*) &ExternalForceNames[LevelNum][0] );
        // might not be any Teleports...
        TeleportsLoad( (char*) &TeleportNames[LevelNum][0] );
        // Can Cope with no Zone file!!!
        TriggerAreaload( (char*) &ZoneNames[LevelNum][0] );



        InitShipsChangeLevel(&Mloadheader);

        if( ( ChangeLevel_MyGameStatus == STATUS_SinglePlayer ) ||
            ( ChangeLevel_MyGameStatus == STATUS_PostStartingSinglePlayer ) ||
            ( ChangeLevel_MyGameStatus == STATUS_TitleLoadGamePostStartingSinglePlayer) )
        {
            if( CountDownOn || BombTag )
            {
                InitBombs();
                CreateCountdownDigits();
                StartCountDown( (int16) SinglePlayerTimeLimit, 0 );
            }
            else
            {
                DeleteCountdownDigits();
            }
        }

        GodModeOnceOnly = TRUE;

        QueryPerformanceCounter((LARGE_INTEGER *) &LastTime);

        if ( !LimitedLoad && !PlayDemo )
        {
            cd_info.current_track = CDTrack[ NewLevelNum ];
            PlayAudioTrack();
        }

        MyGameStatus = ChangeLevel_MyGameStatus;
        break;
    case STATUS_ChangeLevelPostPlayingDemo:
        WhoIAm = MAX_PLAYERS;
        Ships[WhoIAm].Object.Mode = DEMO_MODE;
        Ships[WhoIAm].enable = 1;
        dcoID = 0;
        glpDP = NULL;
        IsHost = TRUE;
#ifndef SELF_PLAY
        Current_Camera_View = MAX_PLAYERS;      // which object is currently using the camera view....
        AutoDetail = FALSE;
#endif
    
        for( i = 0 ; i < MAX_PLAYERS ; i++ )
        {
            GameStatus[i] = STATUS_Null;
        }
    
        DemoTimeSoFar = 0;
        if( DemoSpeed.value > 8 )
        {
            // slower or normal playback speed...
            Demoframelag = 1.0F / (float) ( DemoSpeed.value - 7 );
        }else{
            Demoframelag = 1.0F * (float) ( 9 - DemoSpeed.value );
        }
    
        QueryPerformanceCounter((LARGE_INTEGER *) &GameStartedTime);
        QueryPerformanceCounter((LARGE_INTEGER *) &DemoStartedTime);
        GameElapsedTime = 0;
        DemoGameLoops = 0;
        TempGameElapsedTime = GameStartedTime;
        MyGameStatus = STATUS_PlayingDemo;
        break;
    case STATUS_ChangeLevelPostAttractMode:
        WhoIAm = MAX_PLAYERS;
        Ships[WhoIAm].Object.Mode = DEMO_MODE;
        Ships[WhoIAm].enable = 1;
        dcoID = 0;
        glpDP = NULL;
        IsHost = TRUE;
#ifndef SELF_PLAY
        Current_Camera_View = 0;        // which object is currently using the camera view....
        AutoDetail = FALSE;
#endif
    
        for( i = 0 ; i < MAX_PLAYERS ; i++ )
        {
            GameStatus[i] = STATUS_Null;
        }
        DemoTimeSoFar = 0;
        Demoframelag = 1.0F;
        QueryPerformanceCounter((LARGE_INTEGER *) &GameStartedTime);
        GameElapsedTime = 0;
        TempGameElapsedTime = GameStartedTime;
        
        if ( InSplashDemo )
        {
            MyGameStatus = STATUS_SplashScreen;

            // if this demo is being used for splash screen, timer to start from here...
            SplashStartTime = timeGetTime();
            SplashFinishTime = SplashStartTime + NewSplashScreens[ NewCurrentSplashScreen ].time;
        }else
        {
            MyGameStatus = STATUS_AttractMode;
        }

        PreventFlips = FALSE;

        QueryPerformanceCounter((LARGE_INTEGER *) &GameStartedTime);
        QueryPerformanceCounter((LARGE_INTEGER *) &DemoStartedTime);
        GameElapsedTime = 0;
        DemoGameLoops = 0;

        break;
    case STATUS_AttractMode:

        DemoGameLoops++;

        if( DemoSpeed.value > 8 )
        {
            // slower or normal playback speed...
            Demoframelag = 1.0F / (float) ( DemoSpeed.value - 7 );
        }else{
            Demoframelag = 1.0F * (float) ( 9 - DemoSpeed.value );
        }
        
//      Demoframelag = 10.0F;
        Oldframelag = framelag;

        if( PauseDemo )
        {
            framelag = 0.0F;
        }else{
            framelag *= Demoframelag;
        }

#if 0
        DemoEyesSelect.value = 0;
#endif
        Current_Camera_View = DemoEyesSelect.value;     // which object is currently using the camera view....

        framelag *= Demoframelag;

        if( MainGame( lpDev , lpView ) != TRUE )
            return FALSE;
        break;

//  *********************** Single Player Game Stuff **********************************
    case    STATUS_StartingSinglePlayer:
        //D3DAppIClearBuffers();
        MenuAbort();
        ReleaseView();
        // tell them all to load up a level
        MyGameStatus = STATUS_PostStartingSinglePlayer;
        GameStatus[WhoIAm] = MyGameStatus;
        SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
        LevelNum = -1;
        if( !NewLevelNum )
        {
            NumGoldBars = 0;
            CrystalsFound = 0;
        }
        GameCompleted = GAMECOMPLETE_NotComplete;
        if( !ChangeLevel() ) return( FALSE );
        break;

    case    STATUS_PostStartingSinglePlayer:
        smallinitShip( WhoIAm );
//      if( CountDownOn )
//      {
//          CreateCountdownDigits();
//          StartCountDown( (int16) TimeLimit.value, 0 );
//      }
        
        QueryPerformanceCounter((LARGE_INTEGER *) &GameStartedTime);
        MyGameStatus = STATUS_SinglePlayer;
        GameStatus[WhoIAm] = MyGameStatus;
        LevelTimeTaken = 0.0F;

        QueryPerformanceCounter((LARGE_INTEGER *) &Time_Value);
        QueryPerformanceFrequency((LARGE_INTEGER *) &Time_Freq);
        Old_LevelTime_Float = ( ( Time_Value * 100.0F ) / Time_Freq );

        break;
    case STATUS_SinglePlayer:

        PreventFlips = FALSE;
            
        if( MainGame( lpDev , lpView ) != TRUE )
            return FALSE;

        if ( bSoundEnabled && !CurrentMenu )
        {
            ProcessLoopingSfx();
            ProcessEnemyBikerTaunt();
        }

        //LevelTimeTaken += framelag;

        QueryPerformanceCounter((LARGE_INTEGER *) &Time_Value);
        QueryPerformanceFrequency((LARGE_INTEGER *) &Time_Freq);
        Time_Float = ( ( Time_Value * 100.0F ) / Time_Freq );
        time_diff = ( Time_Float - Old_LevelTime_Float );
        Old_LevelTime_Float = Time_Float;

        if ( framelag )
        {
            LevelTimeTaken += time_diff;
        }

        /*
        sprintf( buf, "time so far %d", ((uint32)LevelTimeTaken) / 100 );
        Print4x5Text( buf, 10, 30, 2 );
        */

        // if player is quiting nothing should stop him.....
        if( MyGameStatus != STATUS_QuitCurrentGame )
        {
            if( IsHost )
            {
                if( NewLevelNum != LevelNum )
                {
                    D3DAppIClearBuffers();
                    ReleaseView();
                    // the level has ended or changed...
                    MyGameStatus = STATUS_ViewingStats;
                    GameStatus[WhoIAm] = MyGameStatus;
                    InitView();
                }
            }
        }
        break;
    case STATUS_ViewingStats:
        D3DAppIClearBuffers();

        ReleaseLevel();

        ReleaseView();
            
        MyGameStatus = STATUS_BetweenLevels;
        InitScene();
        InitView();
        MenuAbort();
        MenuRestart( &MENU_NEW_NumberOfCrystals );
        CameraStatus = CAMERA_AtRightVDU;
        break;


    case    STATUS_TitleLoadGameStartingSinglePlayer:
        //D3DAppIClearBuffers();
        MenuAbort();
        ReleaseView();
        // tell them all to load up a level
        MyGameStatus = STATUS_TitleLoadGamePostStartingSinglePlayer;
        GameStatus[WhoIAm] = MyGameStatus;
        LevelNum = -1;
        NumGoldBars = 0;
        CrystalsFound = 0;
        GameCompleted = GAMECOMPLETE_NotComplete;
        if( !ChangeLevel() ) return( FALSE );
        break;
    case    STATUS_InGameLoadGameStartingSinglePlayer:
        //D3DAppIClearBuffers();

        NewLevelNum = InGameLoadGameLevelNum;
        MenuAbort();
        ReleaseView();
        // tell them all to load up a level
        MyGameStatus = STATUS_TitleLoadGamePostStartingSinglePlayer;
        GameStatus[WhoIAm] = MyGameStatus;
        LevelNum = -1;
        NumGoldBars = 0;
        CrystalsFound = 0;
        GameCompleted = GAMECOMPLETE_NotComplete;
        if( !ChangeLevel() ) return( FALSE );
        break;
    case    STATUS_TitleLoadGamePostStartingSinglePlayer:

        smallinitShip( WhoIAm );
        InGameLoad( NULL );
        
        QueryPerformanceCounter((LARGE_INTEGER *) &GameStartedTime);
        QueryPerformanceCounter((LARGE_INTEGER *) &LastTime);

        MyGameStatus = STATUS_SinglePlayer;
        GameStatus[WhoIAm] = MyGameStatus;
        break;

//  ******************** End of Single Player Game Stuff *******************************

    case STATUS_PseudoHostWaitingForAck:
        ReceiveGameMessages();

        if( DisplayTitle() != TRUE )
        {
            SeriousError = TRUE;
            return FALSE;
        }

        Browl -= framelag;

        if( Browl <= 0.0F )
        {
            Browl = 30.0F;
            if( dcoID )
            {
                SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
            }

            DPlayGetSessionDesc();
            switch( glpdpSD->dwUser3 & ServerGameStateBits )
            {
            case SERVER_STATE_NoServer:
            case SERVER_STATE_NeedHost:
                // server is in wrong state.
                // probably because we have quit & rejoined the session and are recieving first ack msg.
                // therefore just ignore message
                break;
            case SERVER_STATE_HostChoosing:
                // server state has not changed
                break;
            case SERVER_STATE_Joinable:
                // server has made session joinable, therefore he must have recieved MSG_GAMEPARAMETERS
                MyGameStatus = STATUS_StartingMultiplayer;
                if ( TeamGame )
                {
                    MenuChangeEx( &MENU_NEW_WatchTeamSelect );
                }else
                {
                    MenuChangeEx( &MENU_NEW_PseudoHostWaitingToStart );
                }
                break;
            }
        }
        break;
    case STATUS_WaitingToSendMessages:
#ifdef  GUARANTEEDMESSAGES
        if ( GuaranteedMessagesActive )
        {
            D3DAppClearScreenOnly();
            CenterPrint4x5Text( "please wait...", (d3dappi.szClient.cy>>1)-(FontHeight>>1) , 2 );
            ReceiveGameMessages();  // this also ensures that guaranteed messages are sent
        }
        else
#endif
        {
            if ( !RefreshDPlay() )
                MyGameStatus = STATUS_Title;    // because we will have been thrown back a menu

            InitMySessionsList();
            GetCurrentSessions( NULL );

            MyGameStatus = PreWaitingToSendMessagesStatus;
        }
    default:
        break;
    }
    return TRUE;
}


float   Hdiv[MAX_PLAYERS] = { 1.0F ,
                              1.0F ,
                              1.0F ,
                              0.5F ,
                              0.5F ,
                              0.5F ,
                              1.0F ,
                              0.5F };
float   Vdiv[MAX_PLAYERS] = { 1.0F ,
                              0.5F ,
                              0.33333333F ,
                              0.5F ,
                              0.2F ,
                              0.33333333F ,
                              0.142857142F ,
                              0.25F  };
float   Hpos[MAX_PLAYERS][MAX_PLAYERS] = { { 0.0F } ,
                                           { 0.0F , 0.0F } ,
                                           { 0.0F , 0.0F , 0.0F } ,
                                           { 0.0F , 1.0F , 0.0F , 1.0F } ,
                                           { 0.0F , 0.0F , 0.0F , 0.0F , 0.0F } ,
                                           { 0.0F , 1.0F , 0.0F , 1.0F , 0.0F , 1.0F} ,
                                           { 0.0F , 0.0F , 0.0F , 0.0F , 0.0F , 0.0F , 0.0F} ,
                                           { 0.0F , 1.0F , 0.0F , 1.0F , 0.0F , 1.0F , 0.0F , 1.0F } };
float   Vpos[MAX_PLAYERS][MAX_PLAYERS] = { { 0.0F } ,
                                           { 0.0F , 1.0F } ,
                                           { 0.0F , 1.0F , 2.0F } ,
                                           { 0.0F , 0.0F , 1.0F , 1.0F } ,
                                           { 0.0F , 1.0F , 2.0F , 3.0F , 4.0F } ,
                                           { 0.0F , 0.0F , 1.0F , 1.0F , 2.0F , 2.0F} ,
                                           { 0.0F , 1.0F , 2.0F , 3.0F , 4.0F , 5.0F , 6.0F} ,
                                           { 0.0F , 0.0F , 1.0F , 1.0F , 2.0F , 2.0F , 3.0F , 3.0F } };
                                           

/*-------------------------------------------------------------------
    Procedure   :       Main Routines...
    Input       :       nothing...
    Output      :       nothing
-------------------------------------------------------------------*/
void MainRoutines( void )
{
    if( PlayDemo )
    {
        DemoPlayingDplayGameUpdate();
    }

    ProcessShips();

#ifdef SHADOWTEST
//  CreateSpotLight( (uint16) WhoIAm, SHIP_RADIUS, &Mloadheader );
//  CreateShadowsForShips();
#endif

    FirePrimary();
    if( !BombTag )
        FireSecondary();
    ProcessEnemies();
    ProcessSpotFX();
    ProcessPrimaryBullets();
    ProcessSecondaryBullets();
    if( !PlayDemo ) RegeneratePickups();
    ProcessPickups();
    ProcessBGObjects( TRUE );
    ProcessRestartPoints();
    ProcessModels();
    ProcessPolys();
    ProcessXLights( &Mloadheader );
    DoAfterBurnerEffects();
    FmPolyProcess();
    CheckTimeLimit();
    if( CountDownOn ) UpdateCountdownDigits();
    if( ForsakenAnyKey ) DisplayForsakenAnyKey();
    ShowScreenMultiples();
    ProcessActiveConditions();
    ProcessTriggerAreas();
    UpdateBombs();
    ProcessGoals();
#ifdef DOESNT_WORK_AND_A_BAD_IDEA_ANYWAY
    if ( outside_map && !DebugInfo && ( Ships[WhoIAm].Object.Mode != DEATH_MODE ) && ( Ships[WhoIAm].Object.Mode != LIMBO_MODE ) )
    {
        // bugger -- the player has managed to get outside the map, so kill him off...
        Ships[WhoIAm].ShipThatLastHitMe = MAX_PLAYERS;
        Ships[WhoIAm].Damage = 255 + 255;   //make sure I Die....
        DoDamage( OVERRIDE_INVUL );
    
    
        Ships[WhoIAm].Object.Mode = DEATH_MODE;
        Ships[WhoIAm].Timer = 0.0F;
        AddMessageToQue( "A Bomb Killed You..." );
        ShipDiedSend( WEPTYPE_Primary, 0);
    }
#endif
    WaterProcess();
    ProcessRTLights();
}

void CheckForRogueSfx( void )
{ 
    DWORD current_time, dwStatus;
    int i;

    // Dirty hack to kill off any rogue sfx!! 
    if ( bSoundEnabled && NumDupCompoundBuffers )
    {
        EnterCriticalSection( &CompoundSfxKey );
        
        current_time = GetTickCount();

        for ( i = 0; i < NumDupCompoundBuffers; i++ )
        {
            IDirectSoundBuffer_GetStatus( CompoundSfxBuffer[ i ].buffer, &dwStatus );

            // if buffer is playing, check whether it should have stopped by now...
            if (dwStatus & DSBSTATUS_PLAYING)
            {
                if ( current_time > ( CompoundSfxBuffer[ i ].finish_time + 50 ) )
                {
                    DebugPrintf("Rogue SFX killed off: SfxNum %d, SndObj index %d, start time %d finish time %d ( current time %d ), timerID %d  \n",
                    CompoundSfxBuffer[ i ].current_sfx, CompoundSfxBuffer[ i ].compound_buffer_lookup_index, CompoundSfxBuffer[ i ].start_time,
                    CompoundSfxBuffer[ i ].finish_time, current_time, CompoundSfxBuffer[ i ].timerID);

                    EnterCriticalSection( &SfxHolderKey );
                    KillCompoundSfxBuffer( i );
                    LeaveCriticalSection( &SfxHolderKey );

                    //SfxHolder[ CompoundSfxBuffer[ i ].SfxHolderIndex ].Used = FALSE;
                    FreeSfxHolder( CompoundSfxBuffer[ i ].SfxHolderIndex );
    

                }
            }
        }

        LeaveCriticalSection( &CompoundSfxKey );
    }
}

void CheckLevelEnd ( void )
{

#ifndef WIN98SHAREWARE

    if( HasLevelEnded() )
    {
        PauseAllSfx();
#ifdef FINAL_RELEASE
        if( OriginalLevels )
        {
#endif
            LevelNum = -1;
            if( NewLevelNum == ( LevelList.items - 2 ) )
            {
                // if they cheated at any point
                if ( Cheated )
                {
                    GameCompleted = GAMECOMPLETE_Cheated;
                }else
                {
                    // Check for Secret level...
                    if( CrystalsFound == ( LevelList.items - 1 ) )
                    {
                        //They can go to the secret level
                        NewLevelNum = ( LevelList.items - 1 );
                        GameCompleted = GAMECOMPLETE_GotAllCrystalsSoFar;
                    }else{
                        // go straight to the end sequence
                        GameCompleted = GAMECOMPLETE_WithoutAllCrystals;
                    }
                }
            }else if( NewLevelNum == ( LevelList.items - 1 ) ){
                // They have completed the Secret level
                if( CrystalsFound == ( LevelList.items ) )
                {
                    // they found the crystal on the secret level...Therefore they have access to the Secret Biker..
                    BikeList.items = MAXBIKETYPES;
                    // record this in their config
                    write_config( player_config, biker_config );
                    GameCompleted = GAMECOMPLETE_WithAllCrystals;
                }else
                {
                    GameCompleted = GAMECOMPLETE_WithAllCrystalsExceptLast;
                }
            }else{
                NewLevelNum++;
                GameCompleted = GAMECOMPLETE_NotComplete;
            }
            
            return;
#ifdef FINAL_RELEASE
        }else
        {
            if( NewLevelNum == ( LevelList.items - 1 ) )
            {
                // completed all levels ( not original levels )
                GameCompleted = GAMECOMPLETE_AdditionalLevels;
                return;
            }else
            {
                NewLevelNum++;
                GameCompleted = GAMECOMPLETE_NotComplete;
            }
        }
#endif
    }

#else

    if( HasLevelEnded() )
    {
        PauseAllSfx();

        LevelNum = -1;
        if( NewLevelNum == ( LevelList.items - 1 ) )
        {
            GameCompleted = GAMECOMPLETE_Win98Shareware;
        }else{
            NewLevelNum++;
            GameCompleted = GAMECOMPLETE_NotComplete;
        }
        
        return;
    }
#endif

}

/*-------------------------------------------------------------------
    Procedure   :       Main Render Loop...
    Input       :       nothing...
    Output      :       nothing
-------------------------------------------------------------------*/
BOOL
MainGame(LPDIRECT3DDEVICE lpDev, LPDIRECT3DVIEWPORT lpView )
{
    int i, active;
    int enabled[MAX_PLAYERS];
    static float fov_inc = 0.0F;
    RECT    src;
    HRESULT ddrval;

    QueryPerformanceCounter((LARGE_INTEGER *) &GameCurrentTime);

    if( PlayDemo )
    {
        if( PauseDemo )
        {
            TempGameElapsedTime = GameCurrentTime;
        }else{
            if( DemoScreenGrab && !CurrentMenu )
            {
                GameElapsedTime += (LONGLONG) ( ( ( 2 * ticksperframe ) / 1000.0F) * Freq );    // approx every 2 frames...
            }else{
                GameElapsedTime += (LONGLONG) ( ( GameCurrentTime - TempGameElapsedTime ) * Demoframelag );
            }
            TempGameElapsedTime = GameCurrentTime;

            GameCurrentTime = GameCurrentTime - GameStartedTime;
            GameCurrentTime = (LONGLONG) ( GameCurrentTime * Demoframelag );
        }
    }else{
        GameCurrentTime = GameCurrentTime - GameStartedTime;
    }




#ifdef DEBUG
    if ( framelag > 10.0F ) // check framelag out of reasonable range -> probably debugging
    {
        framelag = 10.0F; // clamp framelag to something reasonable
    }
#endif // DEBUG

/*-------------------------------------------------------------------
    Procedure   :    Main Routines to be called before Rendering....    
-------------------------------------------------------------------*/
    // set up groups indirectly visible by all active cameras
    /*
    // removed by Phil 11/11/98 ( VC6 warning )
    if( ServerMode && !PowerVR )
    {
        ServerCount++;
        if( ServerCount >= active )
        {
            ServerCount = 0;
        }
        InitIndirectVisible( Ships[enabled[ServerCount]].Object.Group );
    }
    else
    */
    {
        InitIndirectVisible( Ships[Current_Camera_View].Object.Group );
    }
    if( !PowerVR && ( ActiveRemoteCamera || (MissileCameraActive && MissileCameraEnable) ) )
    {
        AddIndirectVisible( (uint16) ( ( ActiveRemoteCamera ) ? ActiveRemoteCamera->Group : SecBulls[ CameraMissile ].GroupImIn ) );
    }

    MainRoutines();

    if( MyGameStatus == STATUS_QuitCurrentGame )
        return TRUE;


    
    TloadCheckForLostSurfaces(&Tloadheader);
    memset( (void*) &IsGroupVisible[0] , 0 , MAXGROUPS * sizeof(uint16) );
    cral += (framelag*2.0F);

    for( i = 0 ; i < MAX_SFX ; i++ )
    {
        LastDistance[i] = 100000.0F;
    }

#ifdef SOFTWARE_ENABLE
    if( SoftwareVersion )
    {
//      CWClearZBuffer();
    }
#endif

/*-------------------------------------------------------------------
    Procedure   :    Now the Rendering can begin...
-------------------------------------------------------------------*/
    if (lpDev->lpVtbl->BeginScene(lpDev) != D3D_OK)
        return FALSE;


    if( ServerMode && !PowerVR )
    {
        CameraRendering = CAMRENDERING_Server;
            
        active = 0;
        for ( i = 0 ; i < MAX_PLAYERS ; i++ )
        {
            if( Ships[i].enable != 0 )
            {
                enabled[active] = i;
                active++;
            }
        }
        if( active > 1 )
        {
            src.top = 0;
            src.left = 0;
            src.right = d3dappi.szClient.cx;
            src.bottom = d3dappi.szClient.cy;
            while( 1 )
            {
                ddrval = d3dapp->lpBackBuffer->lpVtbl->BltFast( d3dapp->lpBackBuffer, 0, 0, d3dapp->lpFrontBuffer, &src, DDBLTFAST_WAIT );
                if( ddrval == DD_OK )
                    break;
                if( ddrval == DDERR_SURFACELOST )
                {
            
                    d3dapp->lpBackBuffer->lpVtbl->Restore(d3dapp->lpBackBuffer);
                    d3dapp->lpFrontBuffer->lpVtbl->Restore(d3dapp->lpFrontBuffer);
                    break;
                }
                if( ddrval != DDERR_WASSTILLDRAWING )
                    break;
            }
        }
        
        Current_Camera_View = enabled[ServerCount];

        MainCamera.enable = 1;
        MainCamera.GroupImIn = Ships[enabled[ServerCount]].Object.Group;    
        MainCamera.Mat = Ships[enabled[ServerCount]].Object.FinalMat;   
        MainCamera.InvMat = Ships[enabled[ServerCount]].Object.FinalInvMat; 
        MainCamera.Pos = Ships[enabled[ServerCount]].Object.Pos;    
        MainCamera.Viewport = viewport; 
        MainCamera.Proj = proj; 

        
        MainCamera.Viewport.dwX = (long) ( viewport.dwX + ( ( viewport.dwWidth * Hdiv[active-1] ) * (Hpos[active-1][ServerCount] ) ) );
        MainCamera.Viewport.dwY = (long) ( viewport.dwY + ( ( viewport.dwHeight * Vdiv[active-1] ) * (Vpos[active-1][ServerCount]) ) );
        MainCamera.Viewport.dwWidth = (long) ( viewport.dwWidth * Hdiv[active-1] );
        MainCamera.Viewport.dwHeight = (long) ( viewport.dwHeight * Vdiv[active-1] );
        MainCamera.Viewport.dvScaleX = MainCamera.Viewport.dwWidth / (float)2.0;
        MainCamera.Viewport.dvScaleY = MainCamera.Viewport.dwHeight / (float)2.0;
        MainCamera.Viewport.dvMaxX = (float)D3DDivide(D3DVAL(MainCamera.Viewport.dwWidth),
                                           D3DVAL(2 * MainCamera.Viewport.dvScaleX));
        MainCamera.Viewport.dvMaxY = (float)D3DDivide(D3DVAL(MainCamera.Viewport.dwHeight),
                                           D3DVAL(2 * MainCamera.Viewport.dvScaleY));
    
        CurrentCamera = MainCamera;
        CurrentCamera.UseLowestLOD = TRUE;
        if( RenderCurrentCamera( lpDev , lpView ) != TRUE ) 
            return FALSE;

    }else{

        if( !FullRearView )
        {
            CameraRendering = CAMRENDERING_Main;
            MainCamera.enable = 1;
            MainCamera.GroupImIn = Ships[Current_Camera_View].Object.Group; 
            MainCamera.Mat = Ships[Current_Camera_View].Object.FinalMat;    
            MainCamera.InvMat = Ships[Current_Camera_View].Object.FinalInvMat;  
            MainCamera.Pos = Ships[Current_Camera_View].Object.Pos; 
            MainCamera.Viewport = viewport; 
            MainCamera.Proj = proj; 

            
            CurrentCamera = MainCamera;

            HUDNames();
            DispEnhancedCrosshair();

            CurrentCamera.UseLowestLOD = FALSE;
            if( RenderCurrentCamera( lpDev , lpView ) != TRUE ) 
                return FALSE;

#ifdef Z_TRICK
            if ( !ZClearsOn )
            {
                g_OddFrame = !g_OddFrame;
                SetZProj();
                if( !SetZCompare() )
                {
                    Msg("unable to set z compare\n");
                    return FALSE;
                }
            }
#endif
    
            if( RearCameraActive && !PowerVR && !RearCameraDisable && !InSplashDemo )
            {
                CameraRendering = CAMRENDERING_Rear;

                CurrentCamera.enable = 1;
                CurrentCamera.UseLowestLOD = TRUE;
                CurrentCamera.GroupImIn = Ships[Current_Camera_View].Object.Group;  
                CurrentCamera.Mat = Ships[Current_Camera_View].Object.FinalMat; 
                CurrentCamera.InvMat = Ships[Current_Camera_View].Object.FinalInvMat;   
                CurrentCamera.Pos = Ships[Current_Camera_View].Object.Pos;  
                CurrentCamera.Viewport = viewport;  
                CurrentCamera.Proj = proj;  
                
                CurrentCamera.InvMat._31 *= -1.0F;
                CurrentCamera.InvMat._32 *= -1.0F;
                CurrentCamera.InvMat._33 *= -1.0F;
                CurrentCamera.InvMat._11 *= -1.0F;
                CurrentCamera.InvMat._12 *= -1.0F;
                CurrentCamera.InvMat._13 *= -1.0F;
                
                CurrentCamera.Mat._13 *= -1.0F;
                CurrentCamera.Mat._23 *= -1.0F;
                CurrentCamera.Mat._33 *= -1.0F;
                CurrentCamera.Mat._11 *= -1.0F;
                CurrentCamera.Mat._21 *= -1.0F;
                CurrentCamera.Mat._31 *= -1.0F;
                
                CurrentCamera.Viewport.dwX = ( viewport.dwX + viewport.dwWidth ) - ( (viewport.dwWidth >>4) + ( viewport.dwWidth >>2 ) );
                CurrentCamera.Viewport.dwY = viewport.dwY + (viewport.dwHeight >>4);
                CurrentCamera.Viewport.dwWidth = viewport.dwWidth >>2;
                CurrentCamera.Viewport.dwHeight = viewport.dwHeight >>2;
                CurrentCamera.Viewport.dvScaleX = CurrentCamera.Viewport.dwWidth / (float)2.0;
                CurrentCamera.Viewport.dvScaleY = CurrentCamera.Viewport.dwHeight / (float)2.0;
                CurrentCamera.Viewport.dvMaxX = (float)D3DDivide(D3DVAL(CurrentCamera.Viewport.dwWidth),
                                                   D3DVAL(2 * CurrentCamera.Viewport.dvScaleX));
                CurrentCamera.Viewport.dvMaxY = (float)D3DDivide(D3DVAL(CurrentCamera.Viewport.dwHeight),
                                                   D3DVAL(2 * CurrentCamera.Viewport.dvScaleY));
                
                
                CurrentCamera.UseLowestLOD = TRUE;

    #ifdef SOFTWARE_ENABLE
                if( SoftwareVersion )
                {
                    if( !CWRenderSmallCamera( lpDev , lpView ) )
                        return FALSE;
                }
                else
    #endif
                {
                    if( RenderCurrentCamera( lpDev , lpView ) != TRUE ) 
                        return FALSE;
                }
            }

            if( !PowerVR && ( ActiveRemoteCamera || (MissileCameraActive && MissileCameraEnable) ) )
            {
                float main_fov;

                TempMissileCam = Current_Camera_View;
                Current_Camera_View = -1;
                if( ActiveRemoteCamera )
                {
                    CameraRendering = CAMRENDERING_Pip;

                    CurrentCamera.enable = 1;
                    CurrentCamera.GroupImIn = ActiveRemoteCamera->Group;    
                    CurrentCamera.Mat = ActiveRemoteCamera->Mat;    
                    CurrentCamera.InvMat = ActiveRemoteCamera->InvMat;  
                    CurrentCamera.Pos = ActiveRemoteCamera->Pos;
                }else{
                    CameraRendering = CAMRENDERING_Missile;

                    CurrentCamera.enable = 1;
                    CurrentCamera.GroupImIn = SecBulls[ CameraMissile ].GroupImIn;  
                    CurrentCamera.Mat = SecBulls[ CameraMissile ].Mat;  
                    MatrixTranspose( &SecBulls[ CameraMissile ].Mat, &CurrentCamera.InvMat );
                    
                    CurrentCamera.Pos = SecBulls[ CameraMissile ].Pos;
                }
                CurrentCamera.Viewport = viewport;
                main_fov = hfov;
                SetFOV( normal_fov ); // was SetFOV( START_FOV ), but this doesn't work for wide angle fov
                CurrentCamera.Proj = proj;  
                
                CurrentCamera.Viewport.dwX = viewport.dwX + (viewport.dwWidth >>4);
                CurrentCamera.Viewport.dwY = viewport.dwY + (viewport.dwHeight >>4);
                CurrentCamera.Viewport.dwWidth = viewport.dwWidth >>2;
                CurrentCamera.Viewport.dwHeight = viewport.dwHeight >>2;
                CurrentCamera.Viewport.dvScaleX = CurrentCamera.Viewport.dwWidth / (float)2.0;
                CurrentCamera.Viewport.dvScaleY = CurrentCamera.Viewport.dwHeight / (float)2.0;
                CurrentCamera.Viewport.dvMaxX = (float)D3DDivide(D3DVAL(CurrentCamera.Viewport.dwWidth),
                                                   D3DVAL(2 * CurrentCamera.Viewport.dvScaleX));
                CurrentCamera.Viewport.dvMaxY = (float)D3DDivide(D3DVAL(CurrentCamera.Viewport.dwHeight),
                                                   D3DVAL(2 * CurrentCamera.Viewport.dvScaleY));
                
                
                CurrentCamera.UseLowestLOD = TRUE;

    #ifdef SOFTWARE_ENABLE
                if( SoftwareVersion )
                {
                    if( !CWRenderSmallCamera( lpDev , lpView ) )
                        return FALSE;
                }
                else
    #endif
                {
                    if( RenderCurrentCamera( lpDev , lpView ) != TRUE ) 
                        return FALSE;
                }

                Current_Camera_View=TempMissileCam;
                SetFOV( main_fov );

            }
        }else{
            // Full Screen Rear View....
            CameraRendering = CAMRENDERING_Rear;
            CurrentCamera.enable = 1;
            CurrentCamera.GroupImIn = Ships[Current_Camera_View].Object.Group;  
            CurrentCamera.Mat = Ships[Current_Camera_View].Object.FinalMat; 
            CurrentCamera.InvMat = Ships[Current_Camera_View].Object.FinalInvMat;   
            CurrentCamera.Pos = Ships[Current_Camera_View].Object.Pos;  
            CurrentCamera.Viewport = viewport;  
            CurrentCamera.Proj = proj;  
            
            CurrentCamera.InvMat._31 *= -1.0F;
            CurrentCamera.InvMat._32 *= -1.0F;
            CurrentCamera.InvMat._33 *= -1.0F;
            CurrentCamera.InvMat._11 *= -1.0F;
            CurrentCamera.InvMat._12 *= -1.0F;
            CurrentCamera.InvMat._13 *= -1.0F;
            
            CurrentCamera.Mat._13 *= -1.0F;
            CurrentCamera.Mat._23 *= -1.0F;
            CurrentCamera.Mat._33 *= -1.0F;
            CurrentCamera.Mat._11 *= -1.0F;
            CurrentCamera.Mat._21 *= -1.0F;
            CurrentCamera.Mat._31 *= -1.0F;
    
            CurrentCamera.UseLowestLOD = FALSE;

#if 0
#ifdef SOFTWARE_ENABLE
            if( SoftwareVersion )
            {
                if( !CWRenderSmallCamera( lpDev , lpView ) )
                    return FALSE;
            }
            else
#endif
#endif
            {
                if( RenderCurrentCamera( lpDev , lpView ) != TRUE ) 
                    return FALSE;
            }
#ifdef Z_TRICK
            if ( !ZClearsOn )
            {
                g_OddFrame = !g_OddFrame;
                SetZProj();
                if( !SetZCompare() )
                {
                    Msg("unable to set z compare\n");
                    return FALSE;
                }
            }
#endif
        }
    }

    if( DrawPanel && (WhoIAm == Current_Camera_View ))
    {
        Disp3dPanel( lpDev, lpView );
    }
    
    if( TargetComputerOn )
    {
        lpDev->lpVtbl->Execute(lpDev, lpD3DTransCmdBuf, lpView , D3DEXECUTE_CLIPPED);
        DispTracker( lpDev, lpView );
    }


#ifdef REFLECTION
    if( !InSplashDemo )
    {
        VECTOR  TempUp;
        CameraRendering = CAMRENDERING_Missile;
//      CameraRendering = CAMRENDERING_Main;

        SetFOV( 90.0F );
        if( Ships[WhoIAm ^ 1].enable )
        {
            Current_Camera_View = WhoIAm ^ 1;

            CurrentCamera.enable = 1;
            CurrentCamera.UseLowestLOD = FALSE;
            CurrentCamera.GroupImIn = Ships[Current_Camera_View].Object.Group;

            ApplyMatrix( &Ships[WhoIAm].Object.Mat, &SlideUp, &TempUp );            /* Calc Direction Vector */

            MakeViewMatrix( &Ships[Current_Camera_View].Object.Pos, &Ships[WhoIAm].Object.Pos, &TempUp, &CurrentCamera.Mat);
            MatrixTranspose( &CurrentCamera.Mat, &CurrentCamera.InvMat );

//          CurrentCamera.Mat = Ships[Current_Camera_View].Object.FinalMat; 
//          CurrentCamera.InvMat = Ships[Current_Camera_View].Object.FinalInvMat;   
            CurrentCamera.Pos = Ships[Current_Camera_View].Object.Pos;  
            CurrentCamera.Viewport = viewport;  
            CurrentCamera.Proj = proj;  

            CurrentCamera.Viewport.dwX = 0;
            CurrentCamera.Viewport.dwY = 0;
            CurrentCamera.Viewport.dwWidth = 128;
            CurrentCamera.Viewport.dwHeight = 128;
            CurrentCamera.Viewport.dvScaleX = CurrentCamera.Viewport.dwWidth / (float)2.0;
            CurrentCamera.Viewport.dvScaleY = CurrentCamera.Viewport.dwHeight / (float)2.0;
            CurrentCamera.Viewport.dvMaxX = (float)D3DDivide(D3DVAL(CurrentCamera.Viewport.dwWidth),
                                               D3DVAL(2 * CurrentCamera.Viewport.dvScaleX));
            CurrentCamera.Viewport.dvMaxY = (float)D3DDivide(D3DVAL(CurrentCamera.Viewport.dwHeight),
                                               D3DVAL(2 * CurrentCamera.Viewport.dvScaleY));
            
            {
                if( RenderCurrentCamera( lpDev , lpView ) != TRUE ) 
                    return FALSE;
            }
        }
        Current_Camera_View = WhoIAm;
        SetFOV( START_FOV );
    }
#endif

    if (lpDev->lpVtbl->EndScene(lpDev) != D3D_OK)
        return FALSE;

#ifdef REFLECTION
    WierdShit();
#endif

    ScreenPolyProcess();
    DispHUDNames();
    DispUntriggeredNMEs();

#ifdef INSIDE_BSP
    Inside = PointInsideSkin( &Ships[WhoIAm].Object.Pos, Ships[WhoIAm].Object.Group );
#endif

#ifdef SOFTWARE_ENABLE
    if( !SoftwareVersion )
#endif
    {
        if( Our_CalculateFrameRate() != TRUE)
            return FALSE;
    }


/* Secondary routines called after rendering */
        
    if( !PlayDemo )
    {
        DplayGameUpdate();
    }


    if( (Ships[WhoIAm].Object.Speed.z) > (MaxMoveSpeed) )
    {
        float diff;
        diff = ( Ships[WhoIAm].Object.Speed.z - MaxMoveSpeed ) / (  MaxTurboSpeed - MaxMoveSpeed );

        if( diff > 0.0F )
        {
            fov_inc += diff * diff * framelag;
            if ( fov_inc > 30.0F )
                fov_inc = 30.0F;
        }
        else
        {
            fov_inc *= (float) pow( 0.95, framelag );
        }
    }
    else
    {
        fov_inc *= (float) pow( 0.95, framelag );
    }
    SetFOV( chosen_fov + fov_inc );

#ifdef SOFTWARE_ENABLE
    if( !SoftwareVersion )
#endif
    {
        if( CurrentMenu && CurrentMenuItem )
        {
            MenuDraw( CurrentMenu );

            MenuItemDrawCursor( CurrentMenuItem );

            if ( DrawSimplePanel )
                TestBlt();
// Just to make sure that another press of escape doesnt take you back into the menu you wanted to exit!!
            JustExitedMenu = TRUE;
            
            MenuProcess();
        }
        else
        {
            if( !ServerMode )
            {
#ifndef REFLECTION
                if( !FullRearView )
                    TestBlt();
#endif
            }
//          TaskDispatch();
        }
    }

    ProcessGameKeys();

    CheckForRogueSfx();

    CheckLevelEnd();

    return TRUE;
}

BOOL    ScoreDisplaySfx = TRUE;
/*-------------------------------------------------------------------
    Procedure   :       Init Score Display Stuff...
    Input       :       nothing...
    Output      :       BOOL TRUE/FALSE
-------------------------------------------------------------------*/
BOOL    InitScoreDisplay()
{
#ifdef SCROLLING_MESSAGES
    int i;
#endif
     //Create the offscreen surface, by loading our bitmap.

    if( ModeCase != -1 )
    {
        lpDDSOne = DDLoadBitmap( d3dapp->lpDD,/* (char*) &ScoreNames[ModeCase]*/ DynamicScoreNames , 0, 0 );
        ddpal =  DDLoadPalette( d3dapp->lpDD , /*(char*) &ScoreNames[ModeCase]*/DynamicScoreNames);
        lpDDSOne->lpVtbl->SetPalette( lpDDSOne , ddpal );
    }

    InitFont(TRUE);
    ChangeBackgroundColour( 0, 0, 0 );

#ifdef SCROLLING_MESSAGES
    // get random phrases...
    for (i = 0; i < Num_StatsMessage_Parts; i++)
    {
        StatsMessages[i].current_variation = Random_Range(StatsMessages[i].num_variations);
    }
#endif
    // process scores...
    ScoreSort();

    ScoreDisplaySfx = TRUE;

    PreventFlips = FALSE;

    return TRUE;
}
/*-------------------------------------------------------------------
    Procedure   :       Free Score Display Stuff...
    Input       :       nothing...
    Output      :       BOOL TRUE/FALSE
-------------------------------------------------------------------*/
BOOL    FreeScoreDisplay()
{
    ReleaseDDSurf(lpDDSOne);    
    ReleaseDDSurf(lpDDSTwo);
    lpDDSTwo = NULL;
    lpDDSOne = NULL;
    return TRUE;
}

void ScrollingTeamMessage(char **str, int num_strings, int *col)
{
    static uint16 StartChar = 0;
    static float TotalShift = 0;
    char *message;
    int MaxChars, i;
    uint16 CurrentChar;
    int TotalLength;
    uint16 CurrentMessagePos, ProcessedChars, CurrentCharOffset, CurrentString, CurrentStrLen;
    int xpos;

    TotalShift += 0.5F * framelag;

    TotalLength = 0;
    for (i = 0; i < num_strings; i++)
        TotalLength += strlen( str[i] );

    if (StartChar > (TotalLength - 1))
        StartChar = 0;

    while( TotalShift >= FontWidth )
    {
        StartChar++;
        if (StartChar == TotalLength)
            StartChar = 0;
        TotalShift -= FontWidth;
    }

    MaxChars = (d3dappi.szClient.cx / FontWidth) + 2;

    message = (char *)calloc( MaxChars, sizeof(char) );
    
    CurrentChar = StartChar;
    CurrentMessagePos = 0;
    ProcessedChars = 0;
    xpos = 0 - (int)TotalShift;

    while( ProcessedChars++ <= MaxChars )
    {
        // find out which string CurrentChar is in...
        CurrentCharOffset = 0;
        for (CurrentString = 0; CurrentString < num_strings; CurrentString++)
        {
            if ( CurrentChar < strlen( str[CurrentString] ) + CurrentCharOffset )
            {
                CurrentStrLen = strlen( str[CurrentString] );
                break;
            }
            else
                CurrentCharOffset += strlen( str[CurrentString] );
        }

        // get next character from string, and add to message...
        message[CurrentMessagePos++] = str[CurrentString][CurrentChar++ - CurrentCharOffset];

        if ( (CurrentChar - CurrentCharOffset) == CurrentStrLen )
        {
            // display text so far...
            message[CurrentMessagePos] = 0;
            PrintClipped4x5Text( message, xpos, d3dappi.szClient.cy - (FontHeight*2) , col[CurrentString] );
            xpos += FontWidth * strlen( message );
            message[0] = 0;
            CurrentMessagePos = 0;

            if (CurrentString == num_strings - 1)
                CurrentChar = 0;
        }
    }
    // display remaining text...
    message[CurrentMessagePos] = 0;
    PrintClipped4x5Text( message, xpos, d3dappi.szClient.cy - (FontHeight*2) , col[CurrentString] );

    free (message);
}

/*-------------------------------------------------------------------
    Procedure   :       Score Display...
    Input       :       nothing...
    Output      :       BOOL TRUE/FALSE
-------------------------------------------------------------------*/
BOOL ScoreDisplay()
{
    RECT    src;
    RECT    dest;
    HRESULT ddrval;
    DDBLTFX fx;
    int x;
    int y;
    int i;
#ifdef  PHILHASTIME
    int e;
    char    TempStr[256];
#endif
    int col;
    int num_teams;
//  BOOL TeamOK[MAX_TEAMS];
    int16 TeamScore[MAX_TEAMS];
    static float pulse = 0.0F;
    BOOL pulseon;
    int16 myteam;
    BOOL TeamOK[MAX_TEAMS];
    int active_players;
    int count = 0;

    int Names1X;
    int Kills1X;
    int Deaths1X;
    int Names2X;
    int Kills2X;
    int Deaths2X;
    int YSpaceing = (FontHeight+(FontHeight>>1));


    active_players = 0;
    for( i = 0 ; i < MAX_PLAYERS ; i++ )
    {
        if ( ( (GameStatus[ i ] == STATUS_ViewingScore) ||
            (GameStatus[ i ] == STATUS_WaitingAfterScore ) ||
            (GameStatus[ i ] == STATUS_Left) ||
            ( ( GameStatus[ i ] >= STATUS_InitView_0 ) && ( GameStatus[ i ] <= STATUS_InitView_9 ) ) ) 
            && !( IsServerGame && i == 0 ) )
            active_players++;
    }

//  active_players = MAX_PLAYERS;

    if( active_players <= 16 )
    {

        Names1X = ( d3dappi.szClient.cx >> 1 ) -  (FontWidth*10);
        Kills1X = ( d3dappi.szClient.cx >> 1 ) +  (FontWidth*2);
        Deaths1X = ( d3dappi.szClient.cx >> 1 ) +  (FontWidth*10);
    }else{
        Names1X = ( d3dappi.szClient.cx >> 1 ) -  (FontWidth*10) - (FontWidth*20);
        Kills1X = ( d3dappi.szClient.cx >> 1 ) +  (FontWidth*2) - (FontWidth*20);
        Deaths1X = ( d3dappi.szClient.cx >> 1 ) +  (FontWidth*10) - (FontWidth*20);
        Names2X = ( d3dappi.szClient.cx >> 1 ) -  (FontWidth*10) + (FontWidth*10);
        Kills2X = ( d3dappi.szClient.cx >> 1 ) +  (FontWidth*2) + (FontWidth*10);
        Deaths2X = ( d3dappi.szClient.cx >> 1 ) +  (FontWidth*10) + (FontWidth*10);
    }




    pulse += framelag/60.0F;
    if (pulse > 1.0F)
        pulse -= (float)floor((double)pulse);

    if (pulse <= 0.5F)
        pulseon = TRUE;
    else
        pulseon = FALSE;

    //  Blt Background
    src.top = 0;
    src.left = 0;
    src.right = d3dappi.szClient.cx;
    src.bottom = d3dappi.szClient.cy;
    x = 0;
    y = 0;
    memset(&fx, 0, sizeof(DDBLTFX));
    fx.dwSize = sizeof(DDBLTFX);
    dest.top = 0;
    dest.bottom = d3dappi.szClient.cy;
    dest.left = 0;
    dest.right = d3dappi.szClient.cx;
            
    while( 1 )
    {
        ddrval = d3dapp->lpBackBuffer->lpVtbl->Blt( d3dapp->lpBackBuffer, NULL, lpDDSOne, NULL, DDBLT_WAIT, &fx );
        if( ddrval == DD_OK )
            break;
        if( ddrval == DDERR_SURFACELOST )
        {
            d3dapp->lpFrontBuffer->lpVtbl->Restore(d3dapp->lpFrontBuffer);
            d3dapp->lpBackBuffer->lpVtbl->Restore(d3dapp->lpBackBuffer);
            DDReLoadBitmap( lpDDSOne,/* (char*) &ScoreNames[ModeCase] */DynamicScoreNames );
            break;
        }
        if( ddrval != DDERR_WASSTILLDRAWING )
            break;
    }

    num_teams = 0;

    if (TeamGame)
    {
        memset(&TeamScore, 0, sizeof(int16) * MAX_TEAMS);
        memset(&TeamOK, FALSE, sizeof(BOOL) * MAX_TEAMS);

        for (i = 0; i < MAX_PLAYERS; i++)
        {
            if ( (TeamNumber[i] < MAX_TEAMS) &&
                 ( (GameStatus[ i ] == STATUS_ViewingScore) ||
                 (GameStatus[ i ] == STATUS_WaitingAfterScore ) ||
                 ( ( GameStatus[ i ] >= STATUS_InitView_0 ) && ( GameStatus[ i ] <= STATUS_InitView_9 ) ) ) &&
                 (Ships[i].Kills != -32767) )
            {
                if ( WhoIAm == ScoreSortTab[i] )
                    myteam = TeamNumber[ i ];
                TeamScore[TeamNumber[i]] += Ships[i].Kills;
                if (!TeamOK[TeamNumber[i]])
                {
                    num_teams++;
                    TeamOK[TeamNumber[i]] = TRUE;
                }

                
            }
        }
    }

#ifdef  PHILHASTIME
    Print4x5Text( "kills" , ( d3dappi.szClient.cx >> 1 ) +  ( ( (active_players*FontWidth*4) + (2*FontWidth) + (1*FontWidth) ) >> 1 )  ,  ( d3dappi.szClient.cy >> 1 ) - ( ( (active_players*(FontHeight+(FontHeight/2))) + (FontHeight*5) ) >> 1 ), 1 );
    Print4x5Text( "deaths" , ( d3dappi.szClient.cx >> 1 ) -  ( ( (active_players*FontWidth*4) + (8*FontWidth) + (4*FontWidth) ) >> 1 )  ,  ( d3dappi.szClient.cy >> 1 ) + ( ( (active_players*(FontHeight+(FontHeight/2))) + (FontHeight*2) ) >> 1 ), 1 );
#else
    if( active_players <= 16 )
    {
 
        if( CTF || CaptureTheFlag || BountyHunt )
        {
            Print4x5Text( "Score" , ( d3dappi.szClient.cx >> 1 ) - (2*FontWidth) ,  ( d3dappi.szClient.cy >> 1 ) - ( ( (active_players*YSpaceing ) >> 1 ) + FontHeight  ) , 2 );
        }else{
            Print4x5Text( "kills" , ( d3dappi.szClient.cx >> 1 ) - (2*FontWidth) ,  ( d3dappi.szClient.cy >> 1 ) - ( ( (active_players*YSpaceing ) >> 1 ) + FontHeight  ) , 2 );
            Print4x5Text( "deaths" , ( d3dappi.szClient.cx >> 1 ) + (5*FontWidth) ,  ( d3dappi.szClient.cy >> 1 ) - ( ( (active_players*YSpaceing) >> 1 ) + FontHeight  ) , 1 );
        }
    }else{
        if( CTF || CaptureTheFlag || BountyHunt )
        {
            Print4x5Text( "Score" , Kills1X ,  ( d3dappi.szClient.cy >> 1 ) - ( ( ((active_players >> 2)*YSpaceing ) ) + FontHeight  ) , 2 );
            Print4x5Text( "Score" , Kills2X ,  ( d3dappi.szClient.cy >> 1 ) - ( ( ((active_players >> 2)*YSpaceing ) ) + FontHeight  ) , 2 );
        }else{
            Print4x5Text( "kills" , Kills1X ,  ( d3dappi.szClient.cy >> 1 ) - ( ( ((active_players >> 2)*YSpaceing ) ) + FontHeight  ) , 2 );
            Print4x5Text( "kills" , Kills2X ,  ( d3dappi.szClient.cy >> 1 ) - ( ( ((active_players >> 2)*YSpaceing ) ) + FontHeight  ) , 2 );
            Print4x5Text( "deaths" , Deaths1X ,  ( d3dappi.szClient.cy >> 1 ) - ( ( ((active_players >> 2)*YSpaceing) ) + FontHeight  ) , 1 );
            Print4x5Text( "deaths" , Deaths2X ,  ( d3dappi.szClient.cy >> 1 ) - ( ( ((active_players >> 2)*YSpaceing) ) + FontHeight  ) , 1 );
        }
    }

#endif

    if( !E3DemoHost && !E3DemoClient )
    {
        CenterPrint4x5Text( "Press Space to continue" , d3dappi.szClient.cy - (FontHeight*2) , 0 );
    }

    for( i = 0 ; i < MAX_PLAYERS ; i++ )
    {
        if( ( (GameStatus[ ScoreSortTab[i] ] == STATUS_ViewingScore) ||
            (GameStatus[ ScoreSortTab[i] ] == STATUS_WaitingAfterScore ) ||
            (GameStatus[ ScoreSortTab[i] ] == STATUS_Left) ||
            ( ( GameStatus[ ScoreSortTab[i] ] >= STATUS_InitView_0 ) && ( GameStatus[ ScoreSortTab[i] ] <= STATUS_InitView_9 ) ) )
            && !( IsServerGame && ScoreSortTab[i] == 0 ) )
        {
            if (TeamGame)
            {
                if (WhoIAm == ScoreSortTab[i])
                {
                    if( ScoreDisplaySfx )
                    {
                        if( i == 0 )
                        {
                            // Gee im top of the table...
                            PlaySfx( SFX_BIKER_VP, 1.0F );
                        }else if( i == active_players-1)
                        {
                            // oow im at the bottom
                            PlaySfx( SFX_BIKER_LP, 1.0F );
                        }
                        ScoreDisplaySfx = FALSE;
                    }

                    if (pulseon)
                        col = 0;
                    else
                        col = TeamCol[TeamNumber[WhoIAm]];
                }else
                    col = TeamCol[TeamNumber[ScoreSortTab[i]]];
            }else
            {
                if (WhoIAm == ScoreSortTab[i])
                {
                    if( ScoreDisplaySfx )
                    {
                        if( i == 0 )
                        {
                            // Gee im top of the table...
                            PlaySfx( SFX_BIKECOMP_GK, 1.0F );
                        }else if( i == active_players-1)
                        {
                            // oow im at the bottom
                            PlaySfx( SFX_BIKECOMP_PK, 1.0F );
                        }
                        ScoreDisplaySfx = FALSE;
                    }
                    col = 0;

                }
                else
                    col = 2;
            }
#ifdef  PHILHASTIME
            TempStr[0] = Names[ScoreSortTab[i]][0];
            TempStr[1] = 0;
            // print up first letter of name..
            Print4x5Text( (char*) &TempStr ,  ( ( d3dappi.szClient.cx >> 1 ) -  ( (active_players*FontWidth*4) >> 1 ) )  +  ( i*(4*FontWidth) )  , ( d3dappi.szClient.cy >> 1 ) - ( ( (active_players*(FontHeight+(FontHeight/2))) + (FontHeight*5) ) >> 1 ), col  );
            // print up fiorst 5 chars of the name...
            for( e= 0 ; e < 5 ; e++ )
            {
                TempStr[e] = Names[ScoreSortTab[i]][e];
            }
            TempStr[5] = 0;
            Print4x5Text( (char*) &TempStr , ( d3dappi.szClient.cx >> 1 ) -  ( ( (active_players*FontWidth*4) + (8*FontWidth) + (4*FontWidth) ) >> 1 )  ,  ( d3dappi.szClient.cy >> 1 ) - ( ( (active_players*(FontHeight+(FontHeight/2))) + (FontHeight*2)  >> 1 ) ) + (i * (FontHeight+(FontHeight/2))), col);
            // print kills...
            Printint16( Ships[ScoreSortTab[i]].Kills , ( d3dappi.szClient.cx >> 1 ) +  ( ( (active_players*FontWidth*4) + (2*FontWidth) + (1*FontWidth) ) >> 1 )  ,  ( d3dappi.szClient.cy >> 1 ) - ( ( (active_players*(FontHeight+(FontHeight/2))) + (FontHeight*2) ) >> 1 ) + (i * (FontHeight+(FontHeight/2))), col);
            // print deaths...
            Printuint16( Ships[ScoreSortTab[i]].Deaths ,  ( ( d3dappi.szClient.cx >> 1 ) -  ( (active_players*FontWidth*4) >> 1 ) ) + ( ( i*(4*FontWidth) )  )  ,  ( d3dappi.szClient.cy >> 1 ) + ( ( (active_players*(FontHeight+(FontHeight/2))) + (FontHeight*2) ) >> 1 ), 1 );
            
            for( e = 0 ; e < MAX_PLAYERS ; e++ )
            {
                // print stats...
                if( ( GameStatus[ScoreSortTab[e]] == STATUS_Left) || ( Ships[ScoreSortTab[e]].enable)  )
                {
                    
                    if( i == e )
                         Printuint16( Stats[ScoreSortTab[i]][ScoreSortTab[e]] ,  ( ( d3dappi.szClient.cx >> 1 ) -  ( (active_players*FontWidth*4) >> 1 ) ) + ( e*(4*FontWidth) )  ,  ( d3dappi.szClient.cy >> 1 ) - ( ( (active_players*(FontHeight+(FontHeight/2))) + (FontHeight*2) ) >> 1 ) + (i * (FontHeight+(FontHeight/2))), 1 );
                    else Printuint16( Stats[ScoreSortTab[i]][ScoreSortTab[e]] ,  ( ( d3dappi.szClient.cx >> 1 ) -  ( (active_players*FontWidth*4) >> 1 ) ) + ( e*(4*FontWidth) )  ,  ( d3dappi.szClient.cy >> 1 ) - ( ( (active_players*(FontHeight+(FontHeight/2))) + (FontHeight*2) ) >> 1 ) + (i * (FontHeight+(FontHeight/2))), 0 );
                }
            }
#else
            if( active_players < 16 )
            {
                Print4x5Text( (char*) &Names[ScoreSortTab[i]][0] , Names1X ,  ( ( d3dappi.szClient.cy >> 1 ) - (active_players*YSpaceing>>1) ) + (count * YSpaceing) , col);
                // print kills...
                Printint16( Ships[ScoreSortTab[i]].Kills , Kills1X  ,  ( ( d3dappi.szClient.cy >> 1 ) - (active_players*YSpaceing>>1) ) + (count * YSpaceing), col);
                // print deaths...
                if( !CTF && !CaptureTheFlag && !BountyHunt )
                {
                    Printuint16( Ships[ScoreSortTab[i]].Deaths , Deaths1X  ,  ( ( d3dappi.szClient.cy >> 1 ) - (active_players*YSpaceing>>1) ) + (count * YSpaceing), 1 );
                }
            }else{
                if( count < (active_players >> 1) )
                {
                    Print4x5Text( (char*) &Names[ScoreSortTab[i]][0] , Names1X ,  ( ( d3dappi.szClient.cy >> 1 ) - ((active_players >> 2)*YSpaceing) ) + (count * YSpaceing) , col);
                    // print kills...
                    Printint16( Ships[ScoreSortTab[i]].Kills , Kills1X  ,  ( ( d3dappi.szClient.cy >> 1 ) - ((active_players >> 2)*YSpaceing) ) + (count * YSpaceing), col);
                    // print deaths...
                    if( !CTF && !CaptureTheFlag && !BountyHunt )
                    {
                        Printuint16( Ships[ScoreSortTab[i]].Deaths , Deaths1X  ,  ( ( d3dappi.szClient.cy >> 1 ) - ((active_players >> 2)*YSpaceing ) ) + (count * YSpaceing), 1 );
                    }
                }else{
                    Print4x5Text( (char*) &Names[ScoreSortTab[i]][0] , Names2X ,  ( ( d3dappi.szClient.cy >> 1 ) - ((active_players >> 2)*YSpaceing) ) + ((count-(active_players>>1)) * YSpaceing) , col);
                    // print kills...
                    Printint16( Ships[ScoreSortTab[i]].Kills , Kills2X  ,  ( ( d3dappi.szClient.cy >> 1 ) - ((active_players >> 2)*YSpaceing) ) + ((count-(active_players>>1)) * YSpaceing), col);
                    // print deaths...
                    if( !CTF && !CaptureTheFlag && !BountyHunt )
                    {
                        Printuint16( Ships[ScoreSortTab[i]].Deaths , Deaths2X  ,  ( ( d3dappi.szClient.cy >> 1 ) - ((active_players >> 2)*YSpaceing ) ) + ((count-(active_players>>1)) * YSpaceing), 1 );
                    }

                }
            }

            count++;
#endif
        }
    }

    if ( TeamGame )
    {
        char buf[MAX_TEAMS][32];
        int buf_width[ MAX_TEAMS ];
        int buf_col[ MAX_TEAMS ];
        int num_bufs = 0;
        int total_width = 0;
        int gap_width = FontWidth * 3;
        int bufxpos[ MAX_TEAMS ];
        int total_screen_width = d3dappi.szClient.cx;

        for ( i = 0; i < MAX_TEAMS; i++ )
        {
            if ( TeamOK[ i ] )
            {
                sprintf( buf[ num_bufs ], "%-8s %d", TeamName[ i ], TeamScore[ i ] );
                buf_width[ num_bufs ] = strlen( buf[ num_bufs ] ) * FontWidth;
                total_width += buf_width[ num_bufs ];

                if ( i == TeamNumber[ WhoIAm ] )
                    buf_col[ num_bufs ] = pulseon ? 0 : TeamCol[ i ];
                else
                    buf_col[ num_bufs ] = TeamCol[ i ];

                num_bufs++;

            }
        }

        total_width += gap_width * ( num_bufs - 1 );

        for( i = 0; i < num_bufs; i++ )
        {
            if ( !i )
                bufxpos[ i ] = ( total_screen_width / 2 ) - ( total_width / 2 );
            else
                bufxpos[ i ] = bufxpos[ i - 1 ] + buf_width[ i - 1 ] + gap_width; 

            Print4x5Text( buf[ i ] ,bufxpos[ i ],  d3dappi.szClient.cy - (FontHeight*4) , 
                 buf_col[ i ]);

        }
    }

    return TRUE;
}

#if 0
    RECT rectOverlaySource, rectOverlayDest;
    DDOVERLAYFX ddofx;

    lpDDSOverlay =  DDLoadBitmapOverlay( lpDD, (char*) &PanelNames[0] , 320, 80 );
    DDSetColorKey( lpDDSOverlay, RGB_MAKE( 255 , 0 , 255 ) );
    
    /* Set the overlay source rect */
    SetRect(&rectOverlaySource,0,0,320,80);
    /* Fill the entire display with the overlay */
    SetRect(&rectOverlayDest, 0 , 0 , 320 , 80 );

    memset(&ddofx, 0, sizeof(DDOVERLAYFX));
    ddofx.dwSize = sizeof(DDOVERLAYFX);
    /* Position, set colorkey values, and show the front overlay buffer */
    lpDDSOverlay->lpVtbl->UpdateOverlay( lpDDSOverlay , &rectOverlaySource,
                                      lpDDSOverlay,
                                      &rectOverlayDest,
                                      DDOVER_SHOW | DDOVER_KEYDESTOVERRIDE,
                                      &ddofx);
#endif

#if 0
            memset(&fx, 0, sizeof(DDBLTFX));
            fx.dwSize = sizeof(DDBLTFX);
            fx.dwAlphaSrcConstBitDepth = 8;
            fx.dwAlphaSrcConst = 128;
            fx.dwAlphaDestConstBitDepth = 8;
            fx.dwAlphaDestConst = 255;
            dest.top = d3dappi.szClient.cy-PanelVisibleY[ModeCase];
            dest.bottom = d3dappi.szClient.cy;
            dest.left = 0;
            dest.right = d3dappi.szClient.cx;
#endif
#if 0
                ddrval = d3dapp->lpBackBuffer->lpVtbl->Blt( d3dapp->lpBackBuffer, &dest, lpDDSThree, &src, DDBLT_KEYSRC | DDBLT_WAIT | DDBLT_ALPHASRCCONSTOVERRIDE | DDBLT_ALPHADESTCONSTOVERRIDE | DDBLT_ALPHADEST | DDBLT_ALPHASRC , &fx );
#endif

#if defined( FINAL_RELEASE )
BOOL NoDebugMsgs = FALSE;
#else
BOOL NoDebugMsgs = FALSE;
#endif

/*-------------------------------------------------------------------
    Procedure   :       Check for a valid Crc in a Dplay Message..
    Input       :       int8    *   String
    Output      :       BOOL TRUE/FALSE
-------------------------------------------------------------------*/
void DebugPrintf( const char * format, ... )
{
#ifndef FINAL_RELEASE
    static char buf1[256], buf2[512];
    va_list args;

    if ( NoDebugMsgs )
        return;

    va_start( args, format );
    vsprintf( buf1, format, args );
    wsprintf( buf2, "%hs", buf1 );

    OutputDebugString( buf2 );
    va_end( args );

    AddCommentToLog( buf2 );
#endif
}



/*-------------------------------------------------------------------
    Procedure   :       General blit fast...
    Input       :       int     srcx,srcy , width , height , dstx , dsty
                :       LPDIRECTDRAWSURFACE Surface
                :       char * FileName , LPDIRECTDRAWSURFACE DestSurface
    Output      :       BOOL TRUE/FALSE
-------------------------------------------------------------------*/
#ifdef  USEINLINE
_inline
#endif
void GeneralBltFast( int srcx, int srcy , int w , int h  , int dstx , int dsty , LPDIRECTDRAWSURFACE SrcSurface ,   char * FileName , DWORD flags , LPDIRECTDRAWSURFACE DestSurface)
{
    RECT    src;
    HRESULT ddrval;
    src.top = srcy;
    src.left = srcx;
    src.right = src.left+w;
    src.bottom = src.top+h;
    while( 1 )
    {
        ddrval = DestSurface->lpVtbl->BltFast( DestSurface, dstx, dsty, SrcSurface, &src, flags );
        if( ddrval == DD_OK )
            break;
        if( ddrval == DDERR_SURFACELOST )
        {
    
            d3dapp->lpFrontBuffer->lpVtbl->Restore(d3dapp->lpFrontBuffer);
            d3dapp->lpBackBuffer->lpVtbl->Restore(d3dapp->lpBackBuffer);
            DestSurface->lpVtbl->Restore(DestSurface);
            DDReLoadBitmap( SrcSurface, FileName );
            break;
        }
        if( ddrval != DDERR_WASSTILLDRAWING )
            break;
    }
}
/*-------------------------------------------------------------------
    Procedure   :       General blit fast...
    Input       :       int     srcx,srcy , width , height , dstx , dsty ,dstw , dsth ,
                :       LPDIRECTDRAWSURFACE Surface
                :       char * FileName , LPDIRECTDRAWSURFACE DestSurface
    Output      :       BOOL TRUE/FALSE
-------------------------------------------------------------------*/
#ifdef  USEINLINE
//_inline
#endif
void GeneralBlt( int srcx, int srcy , int w , int h  , int dstx , int dsty , int dstw , int dsth , LPDIRECTDRAWSURFACE SrcSurface ,     char * FileName , DWORD flags , LPDIRECTDRAWSURFACE DestSurface)
{
    RECT    dst;
    RECT    src;
    DDBLTFX fx;
    HRESULT ddrval;
    src.top = srcy;
    src.left = srcx;
    src.right = src.left+w;
    src.bottom = src.top+h;

    dst.top = dsty;
    dst.left = dstx;
    dst.right = dst.left+dstw;
    dst.bottom = dst.top+dsth;

    memset(&fx, 0, sizeof(DDBLTFX));
    fx.dwSize = sizeof(DDBLTFX);

    
    while( 1 )
    {
        ddrval = DestSurface->lpVtbl->Blt( DestSurface, &dst, SrcSurface, &src, DDBLT_WAIT | DDBLT_ASYNC , &fx );
        if( ddrval == DD_OK )
            break;
        if( ddrval == DDERR_SURFACELOST )
        {
            d3dapp->lpFrontBuffer->lpVtbl->Restore(d3dapp->lpFrontBuffer);
            d3dapp->lpBackBuffer->lpVtbl->Restore(d3dapp->lpBackBuffer);
            DestSurface->lpVtbl->Restore(DestSurface);
            DDReLoadBitmap( SrcSurface, FileName );
            break;
        }
        if( ddrval != DDERR_WASSTILLDRAWING )
            break;
    }
}

/*-------------------------------------------------------------------
    Procedure   :       Do font blt..
    Input       :       int sx , int sy , int sw , int sh , int x ,int y
    Output      :       nothing
-------------------------------------------------------------------*/
#ifdef  USEINLINE
_inline
#endif
void DoFontBlt(int sx , int sy , int sw , int sh , int x ,int y)
{
    RECT    src;
    HRESULT ddrval;
    src.left = sx;
    src.top = sy;
    src.right = sx+sw;
    src.bottom = sy+sh;
    while( 1 )
    {
        ddrval = d3dapp->lpBackBuffer->lpVtbl->BltFast( d3dapp->lpBackBuffer, x, y, lpDDSTwo, &src, DDBLTFAST_SRCCOLORKEY  | DDBLTFAST_WAIT );
        if( ddrval == DD_OK )
            break;
        if( ddrval == DDERR_SURFACELOST )
        {
            d3dapp->lpFrontBuffer->lpVtbl->Restore(d3dapp->lpFrontBuffer);
            d3dapp->lpBackBuffer->lpVtbl->Restore(d3dapp->lpBackBuffer);
            d3dapp->lpBackBuffer->lpVtbl->Restore(d3dapp->lpBackBuffer);
            ReInitFont();
            break;
        }
        if( ddrval != DDERR_WASSTILLDRAWING )
            break;
    }
}


/*-------------------------------------------------------------------
    Procedure   :    Clear the Zbuffer / screen 
-------------------------------------------------------------------*/
BOOL    ClearBuffers( BOOL ClearScreen, BOOL ClearZBuffer )
{
    int clearflags;
    D3DRECT dummy;
    if (!d3dappi.bRenderingIsOK)
    {
        return FALSE;
    }
    /*
     * Decided wether to clear just back buffer or also z-buffer
     */

    clearflags = 0;


    if( myglobs.bClearsOn || ClearScreen )  // toggle clearing the screen...
    {
        clearflags |= D3DCLEAR_TARGET;
    }

#ifndef SOFTWARE_ENABLE
#ifdef Z_TRICK
    if ( ZClearsOn || ClearZBuffer )    // never clear Z buffer unless told to...
#else
    if (d3dapprs.bZBufferOn || ClearZBuffer )   // If a ZBuffer is enabled then always clear it..
#endif
    {
        clearflags |= D3DCLEAR_ZBUFFER;
    }
#endif

#ifdef SOFTWARE_ENABLE
    if ( ( myglobs.bClearsOn || ClearScreen || ClearZBuffer ) && SoftwareVersion )
    {
        CWClearZBuffer();
    }
#endif

    if( clearflags != 0 )
    {
#ifdef SOFTWARE_ENABLE
        if( SoftwareVersion )
        {
            if (RenderingSmall)
            {
                dummy.x1 = CurrentCamera.Viewport.dwX+RenderingSmallXOff;
                dummy.y1 = CurrentCamera.Viewport.dwY+RenderingSmallYOff;
                dummy.x2 = CurrentCamera.Viewport.dwX+CurrentCamera.Viewport.dwWidth+RenderingSmallXOff;
                dummy.y2 = CurrentCamera.Viewport.dwY+CurrentCamera.Viewport.dwHeight+RenderingSmallYOff;

                
            }
            else
            {
                dummy.x1 = CurrentCamera.Viewport.dwX;
                dummy.y1 = CurrentCamera.Viewport.dwY;
                dummy.x2 = CurrentCamera.Viewport.dwX+CurrentCamera.Viewport.dwWidth;
                dummy.y2 = CurrentCamera.Viewport.dwY+CurrentCamera.Viewport.dwHeight;
            }
        }
        else
#endif
        {
            dummy.x1 = CurrentCamera.Viewport.dwX;
            dummy.y1 = CurrentCamera.Viewport.dwY;
            dummy.x2 = CurrentCamera.Viewport.dwX+CurrentCamera.Viewport.dwWidth;
            dummy.y2 = CurrentCamera.Viewport.dwY+CurrentCamera.Viewport.dwHeight;
        }

        LastError =
                  d3dappi.lpD3DViewport->lpVtbl->Clear(d3dappi.lpD3DViewport,
                                                       1, &dummy,
                                                       clearflags);
        if (LastError != D3D_OK)
        {
            return FALSE;
        }
    }
    return TRUE;
}

/*-------------------------------------------------------------------
    Procedure   :    Clear the Zbuffer
-------------------------------------------------------------------*/
BOOL    ClearZBuffer()
{
    int clearflags;
    D3DRECT dummy;

    if (!d3dappi.bRenderingIsOK) return FALSE;

    clearflags = D3DCLEAR_ZBUFFER;

    dummy.x1 = CurrentCamera.Viewport.dwX;
    dummy.y1 = CurrentCamera.Viewport.dwY;
    dummy.x2 = CurrentCamera.Viewport.dwX+CurrentCamera.Viewport.dwWidth;
    dummy.y2 = CurrentCamera.Viewport.dwY+CurrentCamera.Viewport.dwHeight;

    LastError = d3dappi.lpD3DViewport->lpVtbl->Clear( d3dappi.lpD3DViewport, 1, &dummy, clearflags );
    if (LastError != D3D_OK) return FALSE;
    return TRUE;
}


void InitRenderBufs( LPDIRECT3DDEVICE lpDev )
{
    int Count;
    D3DEXECUTEBUFFERDESC debdesc;

    for( Count = 0; Count < 2; Count++ )
    {
        if( RenderBufs[ Count ] != NULL )
        {
            XRELEASE( RenderBufs[ Count ] );
            RenderBufs[ Count ] = NULL;
        }
        MakeExecuteBuffer( &debdesc, lpDev, &RenderBufs[ Count ], 32767 );
    }
}


void ReleaseRenderBufs( void )
{
    int Count;

    for( Count = 0; Count < 2; Count++ )
    {
        if( RenderBufs[ Count ] != NULL )
        {
            XRELEASE( RenderBufs[ Count ] );
            RenderBufs[ Count ] = NULL;
        }
    }
}


/*-------------------------------------------------------------------
    Procedure   :    Render 1 Frame Using CurrentCamera...
    Input       :
    Output      :   BOOL TRUE/FALSE
-------------------------------------------------------------------*/
    BOOL    ClearScrOverride;
    BOOL    ClearZOverride;

BOOL    RenderCurrentCamera( LPDIRECT3DDEVICE lpDev, LPDIRECT3DVIEWPORT lpView )
{
    HRESULT rval;
    int16   Count;
    VISGROUP    *g;
    uint16  group;
    uint16  i;
    float   R, G, B;
    NumOfTransExe = 0;

    Build_View();
    CurrentCamera.View = view;
    if (lpDev->lpVtbl->SetMatrix(lpDev, hView, &view) != D3D_OK)
        return FALSE;

    rval = d3dapp->lpD3DViewport->lpVtbl->SetViewport(d3dapp->lpD3DViewport, &CurrentCamera.Viewport);
    if (rval != D3D_OK) {
#ifdef DEBUG_VIEWPORT
        SetViewportError( "RenderCurrentCamera1", &CurrentCamera.Viewport, rval );
#else
        Msg("SetViewport failed.\n%s", D3DAppErrorToString(rval));
#endif
        return FALSE;
    }


    // Ship Model Enable/Disable
    SetShipsVisibleFlag();

    // PowerVr Translucent PolySort....
    if( !InitPolySort() )
        return FALSE;

    
    // find visible groups
    FindVisible( &CurrentCamera, &Mloadheader );

    BuildVisibleLightList( CurrentCamera.GroupImIn );
    
    UpdateBGObjectsClipGroup( &CurrentCamera );
    UpdateEnemiesClipGroup( &CurrentCamera );

    ClearScrOverride = FALSE;
    ClearZOverride = FALSE;
    if( CurrentCamera.GroupImIn != (uint16) -1 && !DebugVisible )
    {
        for ( g = CurrentCamera.visible.first_visible; g; g = g->next_visible )
        {
            if( Mloadheader.Group[ g->group ].BGClear_Flag )
            {
                if ( Mloadheader.Group[ g->group ].BGClear_Flag & 0x80 )
                {
                    R = Mloadheader.Group[ g->group ].BGClear_Red;
                    G = Mloadheader.Group[ g->group ].BGClear_Green;
                    B = Mloadheader.Group[ g->group ].BGClear_Blue;
                    ChangeBackgroundColour( R, G, B );
                    ClearScrOverride = TRUE;
                }
#ifdef SOFTWARE_ENABLE
                else
                    ClearZOverride = TRUE; // this never had any effect before Z_TRICK, now it messes it up, so...get rid!
#endif
                break;
            }
        }
    }

    if (ClearBuffers( ClearScrOverride, ClearZOverride ) != TRUE )
        return FALSE;

    // reset all the normal execute status flags...
#ifdef SOFTWARE_ENABLE
    if( SoftwareVersion )
    {
        CWExecute2( lpDev, lpD3DNormCmdBuf, lpView , D3DEXECUTE_CLIPPED );
    }
    else
#endif
    {
        lpDev->lpVtbl->Execute(lpDev, lpD3DNormCmdBuf, lpView , D3DEXECUTE_CLIPPED);
    }

    // set all the Translucent execute status flags...
    if( WhiteOut != 0.0F)
    {
#ifdef SOFTWARE_ENABLE
        if( SoftwareVersion )
        {
            CWExecute2( lpDev, lpD3DSpcFxTransCmdBuf, lpView , D3DEXECUTE_CLIPPED );
        }
        else
#endif
        {
            lpDev->lpVtbl->Execute(lpDev, lpD3DSpcFxTransCmdBuf, lpView , D3DEXECUTE_CLIPPED);
        }
    }


    // display background
#ifdef SOFTWARE_ENABLE
/*-----------------------------------------------------------------------------
        Chris Walsh's Code
-----------------------------------------------------------------------------*/
    if( SoftwareVersion )
    {
        if ( !CWDisplayBackground( &Mloadheader, &CurrentCamera ) )
            return FALSE;
    }
    else
/*---------------------------------------------------------------------------*/
#endif
    {
        if ( !DisplayBackground( &Mloadheader, &CurrentCamera ) )
            return FALSE;
    }

    // reset all the normal execute status flags...
#ifdef SOFTWARE_ENABLE
    if( SoftwareVersion )
    {
        CWExecute2( lpDev, lpD3DNormCmdBuf, lpView , D3DEXECUTE_CLIPPED );
    }
    else
#endif
    {
        if( WhiteOut == 0.0F)
            lpDev->lpVtbl->Execute(lpDev, lpD3DNormCmdBuf, lpView , D3DEXECUTE_CLIPPED);
    }

    if( !bPolySort )
    {
/*-------------------------------------------------------------------
    Display Non Group Clipped Non Faceme Transluecent Polys
-------------------------------------------------------------------*/
        if( !DisplaySolidGroupUnclippedPolys( RenderBufs[ 0 ], lpDev, lpView ) )
                return FALSE;

#ifdef SHADOWTEST
        if( !DisplaySolidGroupUnclippedTriangles( RenderBufs[ 0 ], lpDev, lpView ) )
                return FALSE;
#endif
    }

    
    // display clipped opaque objects
    for ( g = CurrentCamera.visible.first_visible; g; g = g->next_visible )
    {
        group = g->group;

        // Do the Background animation for that group.....
        BackGroundTextureAnimation( &Mloadheader , group );

#ifdef CLIP_LINES
        ClipGroup( &CurrentCamera, group );
#else
        ClipGroup( &CurrentCamera, CurrentCamera.GroupImIn );
#endif

#ifndef FINAL_RELEASE
//      if( d3dapp->bIsPrimary )
        {
            i = FirstLineUsed;
            while( i != (uint16) -1 )
            {
                if( LinesDispGroup( group, RenderBufs[ 0 ], &i ) )
                {
                    if( lpDev->lpVtbl->Execute(lpDev, RenderBufs[ 0 ], lpView, D3DEXECUTE_CLIPPED ) != D3D_OK )
                        return FALSE;
                }
            }
        }
#endif

        ClipGroup( &CurrentCamera, group );


        if( MyGameStatus == STATUS_SplashScreen )
            GroupWaterProcessDisplay( group );

        if ( !LimitedLoad )
        {
            if( !ModelDisp( group, lpDev, &ModelNames[0] ) )
                return FALSE;
        }else
        {
            if( !ModelDisp( group, lpDev, &SplashModelNames[0] ) )
                return FALSE;
        }

/*-------------------------------------------------------------------
    Display Group Clipped Non Faceme Transluecent Polys
-------------------------------------------------------------------*/
        if( !bPolySort )
        {
            if( !DisplaySolidGroupClippedPolys( RenderBufs[ 1 ], group, lpDev, lpView ) )
                return FALSE;
#ifdef SHADOWTEST
            if( !DisplaySolidGroupClippedTriangles( RenderBufs[ 1 ], group, lpDev, lpView ) )
                return FALSE;
#endif
        }

//      if (Mod_Ship_Exec_Buffer( group, lpDev, lpView ) != TRUE)
//          return FALSE;
    }

    ClipGroup( &CurrentCamera, CurrentCamera.GroupImIn );
//  DisplayWaterMesh();

    // set all the Translucent execute status flags...
#ifdef SOFTWARE_ENABLE
    if( SoftwareVersion )
    {
        CWExecute2( lpDev, lpD3DTransCmdBuf, lpView , D3DEXECUTE_CLIPPED );
    }
    else
#endif
    {
        lpDev->lpVtbl->Execute(lpDev, lpD3DTransCmdBuf, lpView , D3DEXECUTE_CLIPPED);
    }


/*-------------------------------------------------------------------
    Display Skin & BSP Node Info
-------------------------------------------------------------------*/
    if( ShowSkin || OldNodeCube || NodeCube || ShowTrigZones || ShowColZones || ShowEFZones || ShowTeleports )
    {
        if( OldNodeCube || NodeCube ) ClearZBuffer();

        for( Count = 0; Count < MAXGROUPS; Count++ )
        {
            if( Skin_Execs[ Count ] != NULL )
            {
#ifdef SOFTWARE_ENABLE
                if( SoftwareVersion )
                {
                    CWExecute2( lpDev, Skin_Execs[ Count ], lpView , D3DEXECUTE_CLIPPED );
                }
                else
#endif
                {
                    if (lpDev->lpVtbl->Execute(lpDev, Skin_Execs[ Count ], lpView , D3DEXECUTE_CLIPPED) != D3D_OK)
                        return FALSE;
                }
            }
        }

#if 0
        for ( g = CurrentCamera.visible.first_visible; g; g = g->next_visible )
        {
            group = g->group;
            ClipGroup( &CurrentCamera, group );
    
//          if( d3dapp->bIsPrimary )
            {
                i = FirstLineUsed;
                while( i != (uint16) -1 )
                {
                    if( LinesDispGroup( group, RenderBufs[ 0 ], &i ) )
                    {
                        if( lpDev->lpVtbl->Execute(lpDev, RenderBufs[ 0 ], lpView, D3DEXECUTE_CLIPPED ) != D3D_OK )
                            return FALSE;
                    }
                }
            }
        }
#endif

    }

#ifdef SOFTWARE_ENABLE
    if( SoftwareVersion )
    {
        CWExecute2( lpDev, lpD3DTransCmdBuf, lpView , D3DEXECUTE_CLIPPED);
    }
    else
#endif
    {
        lpDev->lpVtbl->Execute(lpDev, lpD3DTransCmdBuf, lpView , D3DEXECUTE_CLIPPED);
    }

    // display clipped translucencies
    for ( g = CurrentCamera.visible.first_visible; g; g = g->next_visible )
    {
        group = g->group;
        ClipGroup( &CurrentCamera, group );
        if( MyGameStatus != STATUS_SplashScreen )
            GroupWaterProcessDisplay( group );



/*-------------------------------------------------------------------
    Display Group Clipped Non Faceme Transluecent Polys
-------------------------------------------------------------------*/
        if( !bPolySort )
        {
            if( !DisplayGroupClippedPolys( RenderBufs[ 1 ], group, lpDev, lpView ) )
                return FALSE;

#ifdef SHADOWTEST
            if( !DisplayGroupClippedTriangles( RenderBufs[ 1 ], group, lpDev, lpView ) )
                return FALSE;
#endif

/*-------------------------------------------------------------------
    Display Group Clipped Faceme Transluecent Polys
-------------------------------------------------------------------*/
            if( !DisplayGroupClippedFmPolys( RenderBufs[ 0 ], group, lpDev, lpView ) )
                    return FALSE;

            ExecuteTransExe( group );
        }
        else
        {
            i = FirstFmPolyUsed;
            while( i != (uint16) -1 )
            {
                PVR_FmPolyDispGroup( group, &i );
            }

            i = FirstPolyUsed;
            while( i != (uint16) -1 )
            {
                PVR_PolyDispGroup( group, &i );
            }

            ExecuteTransExe( group );
        }

    }


    ClipGroup( &CurrentCamera, CurrentCamera.GroupImIn );


/*-------------------------------------------------------------------
    Display Non Group Clipped Faceme Transluecent Polys
-------------------------------------------------------------------*/
    if( !bPolySort )
    {
        if( !DisplayGroupUnclippedFmPolys( RenderBufs[ 0 ], lpDev, lpView ) )
                return FALSE;

/*-------------------------------------------------------------------
    Display Non Group Clipped Non Faceme Transluecent Polys
-------------------------------------------------------------------*/
        if( !DisplayGroupUnclippedPolys( RenderBufs[ 0 ], lpDev, lpView ) )
                return FALSE;
#ifdef SHADOWTEST
        if( !DisplayGroupUnclippedTriangles( RenderBufs[ 0 ], lpDev, lpView ) )
            return FALSE;
#endif
    }
    
    // display unclipped translucencies
    for ( g = CurrentCamera.visible.first_visible; g; g = g->next_visible )
    {
        group = g->group;
        ExecuteTransExeUnclipped( group );
    }


/*-------------------------------------------------------------------
    Display Portals
-------------------------------------------------------------------*/
    if( ShowPortal )
    {
        for( Count = 0; Count < MAXGROUPS; Count++ )
        {
            if( Portal_Execs[ Count ] != NULL )
            {
#ifdef SOFTWARE_ENABLE
                if( SoftwareVersion )
                {
                    CWExecute2( lpDev, Portal_Execs[ Count ], lpView , D3DEXECUTE_CLIPPED );
                }
                else
#endif
                {
                    if (lpDev->lpVtbl->Execute(lpDev, Portal_Execs[ Count ], lpView , D3DEXECUTE_CLIPPED) != D3D_OK)
                        return FALSE;
                }
            }
        }
    }

    // PowerVR Translucent Poly Sorted Display...
    if( !PolyListExecute() )
        return FALSE;

    
    
    DoLensflareEffect();
    DoAllSecBullLensflare();

/*-------------------------------------------------------------------
    Display Transluecent Screen Polys
-------------------------------------------------------------------*/
    if( !bPolySort )
    {
        if( !DisplayNonSolidScrPolys( RenderBufs[ 1 ], lpDev, lpView ) )
            return FALSE;
    }
    else
    {
        while( i != (uint16) -1 )
        {
            PVR_ScreenPolysDisp( &i );
        }
    }

    // reset all the normal execute status flags...
#ifdef SOFTWARE_ENABLE
    if( SoftwareVersion )
    {
        CWExecute2( lpDev, lpD3DNormCmdBuf, lpView , D3DEXECUTE_CLIPPED);
    }
    else
#endif
    {
        lpDev->lpVtbl->Execute(lpDev, lpD3DNormCmdBuf, lpView , D3DEXECUTE_CLIPPED);
    }


/*-------------------------------------------------------------------
    Display Solid Screen Polys
-------------------------------------------------------------------*/
    BilinearSolidScrPolys = FALSE;

    if( !DisplaySolidScrPolys( RenderBufs[ 1 ], lpDev, lpView ) )
        return FALSE;

    rval = d3dapp->lpD3DViewport->lpVtbl->SetViewport(d3dapp->lpD3DViewport, &viewport);
    if (rval != D3D_OK) {
#ifdef DEBUG_VIEWPORT
        SetViewportError( "RenderCurrentCamera2", &viewport, rval );
#else
        Msg("SetViewport failed.\n%s", D3DAppErrorToString(rval));
#endif
        return FALSE;
    }

#ifdef SOFTWARE_ENABLE

    if( SoftwareVersion )
    {
        SetVTables();
        SWRendView();
        d3dappi.lpBackBuffer->lpVtbl->Unlock( d3dappi.lpBackBuffer, NULL );
    }

#endif

    return TRUE;
}
    

extern  int     NumOfVertsConsidered;
extern  int     NumOfVertsTouched;

int our_count = 0;
int our_this_frames = 0;
int our_last_polygons = 0;
time_t our_last_time = 0;
/*-------------------------------------------------------------------
    Procedure   :    Our Calculate frame rate...
    Input       :
    Output      :   BOOL TRUE/FALSE
-------------------------------------------------------------------*/
BOOL
Our_CalculateFrameRate(void)
{
    double t;
    int p, f , i;
    D3DSTATS stats;
    time_t our_this_time;
    char buf[256];
    /*
     * Calculate the frame rate and get other stats.
     */

    our_count++;
    our_this_frames++;
    if (our_count == 25)
    {
        our_count = 0;
        our_this_time = GetTickCount();
        t = (our_this_time - our_last_time) / (double)CLOCKS_PER_SEC;
        our_last_time = our_this_time;

        memset(&stats, 0, sizeof(D3DSTATS));
        stats.dwSize = sizeof(D3DSTATS);
        d3dapp->lpD3DDevice->lpVtbl->GetStats( d3dapp->lpD3DDevice, &stats);
        p = stats.dwTrianglesDrawn - our_last_polygons;
        Our_TrianglesDrawn = p;
        our_last_polygons = stats.dwTrianglesDrawn;


        f = our_this_frames;
        our_this_frames = 0;

#if 1
        FPS = (float)(f / t);
#else
        FPS = 60.0F / framelag;
#endif
        TPS = (long)(p / t);
    }

    
    if( ( MyGameStatus == STATUS_PlayingDemo ) || ( MyGameStatus == STATUS_AttractMode ) )
    {
        QueryPerformanceCounter((LARGE_INTEGER *) &DemoEndedTime);
        TimeDiff = DemoEndedTime - DemoStartedTime;
        DemoTotalTime = ( (float) TimeDiff / (float) Freq );
        DemoAvgFps = DemoGameLoops / DemoTotalTime;
    }
    
    if( myglobs.bShowFrameRate )
    {
#ifdef DISPLAY_BUILD_DATETIME
        sprintf(&buf[0], "%4.2f  %s", FPS, last_compiled );
#else
//      sprintf(&buf[0], "%4.2f %4d %4d %4d %4d", FPS , BigPacketSize , MaxBigPacketSize ,RecPacketSize , MaxRecPacketSize );
            sprintf(&buf[0], "%4.2f", FPS );
#endif
        CenterPrint4x5Text( (char *) &buf[0] , FontHeight+viewport.dwY , 2 );
    }
#ifdef DISPLAY_BUILD_DATETIME
    else
    {
        CenterPrint4x5Text( (char *)last_compiled, FontHeight+viewport.dwY , 2 );
    }
#endif

    if( myglobs.bShowInfo )
    {
#if 0
        sprintf(&buf[0], "%d Gvis %d tri %d PPBP",
                            (int) NumGroupsVisible,
                            (int) Our_TrianglesDrawn / 25,
                            BigPacketsSent
                            );
        

        CenterPrint4x5Text( (char *) &buf[0] , (FontHeight * 2) + (FontHeight>>1) + viewport.dwY , 2 );
#endif
        
#if 0
        sprintf(&buf[0], "%d Mem %d ExecMem %d SoftwareSfx",
                            (int) MemUsed ,
                            (int) ExecMemUsed,
                            (int) SBufferMemUsedSW
                            );
        

        CenterPrint4x5Text( (char *) &buf[0] , (FontHeight * 6) + (FontHeight>>1) + viewport.dwY , 2 );
#endif


#ifdef DEBUG_POLY_DETAILS
        sprintf(&buf[0], "FmPolys %d, Polys %d, ScrPolys %d",
                            (int) TotalFmPolysInUse,
                            (int) TotalPolysInUse,
                            (int) TotalScrPolysInUse
                            );
        

        CenterPrint4x5Text( (char *) &buf[0] , (FontHeight * 6) + (FontHeight>>1) + viewport.dwY , 2 );
#endif

#if 1
        sprintf( &buf[0] , "In %s framelag%5.2f Clear=%c%c",
                 (GroupImIn == (uint16) -1) ? "(outside)" : Mloadheader.Group[GroupImIn].name,
                 framelag,
                 ClearScrOverride ? 'S' : ' ',
                 ClearZOverride ? 'Z' : ' '
                 );
#ifdef INSIDE_BSP
                 CenterPrint4x5Text( (char *) &buf[0] , (FontHeight * 4) + (FontHeight>>1) + viewport.dwY , (!Inside) ? 1 : 2 );
#else
                 CenterPrint4x5Text( (char *) &buf[0] , (FontHeight * 4) + (FontHeight>>1) + viewport.dwY , (outside_group) ? 1 : 2 );
#endif
#else
        sprintf(&buf[0], "%d before %d after",
                            Tloadheader.VidMemBefore ,Tloadheader.VidMemAfter , 
                            NumOfVertsTouched
                            );
        CenterPrint4x5Text( (char *) &buf[0] , (FontHeight*6) + (FontHeight) + viewport.dwY , 2 );

#endif
    

        /*
        sprintf( &buf[0], "NeedFlagAtHome %d", NeedFlagAtHome );
        Print4x5Text( (char *) &buf[0], 16, 50 + ( ( MAXPRIMARYWEAPONS + MAXSECONDARYWEAPONS + 9 + 0 ) * FontHeight ) , 2 );
            
        sprintf( &buf[0], "OwnFlagTeleportsHome %d", OwnFlagTeleportsHome );
        Print4x5Text( (char *) &buf[0], 16, 50 + ( ( MAXPRIMARYWEAPONS + MAXSECONDARYWEAPONS + 9 + 1 ) * FontHeight ) , 2 );

        sprintf( &buf[0], "CanCarryOwnFlag %d", CanCarryOwnFlag );
        Print4x5Text( (char *) &buf[0], 16, 50 + ( ( MAXPRIMARYWEAPONS + MAXSECONDARYWEAPONS + 9 + 2 ) * FontHeight ) , 2 );
        */

#if 0
        if( IsServerGame && IsServer )
        {
            CorrectForExtraOrMissingPickups();

            for( i = 1; i < MAXPRIMARYWEAPONS; i++ )
            {
                sprintf( &buf[0], "L %hd - P %hd - G %hd %s", PrimaryInLevel[ i ], PrimaryInPlayers[ i ], PrimaryToGenerate[ i ], PrimaryNames[ i ] );
                Print4x5Text( (char *) &buf[0], 16, ( ( i + 5 ) * FontHeight ) , 2 );
            }

            for( i = 1; i < MAXSECONDARYWEAPONS; i++ )
            {
                if( ( i >= PURGEMINE ) && ( i <= SPIDERMINE ) )
                {
                    sprintf( &buf[0], "L %hd - P %hd - G %hd - D %hd %s", SecondaryInLevel[ i ], SecondaryInPlayers[ i ], SecondaryToGenerate[ i ], MinesInLevel[ i ], SecondaryNames[ i ] );
                }
                else
                {
                    sprintf( &buf[0], "L %hd - P %hd - G %hd %s", SecondaryInLevel[ i ], SecondaryInPlayers[ i ], SecondaryToGenerate[ i ], SecondaryNames[ i ] );
                }

                Print4x5Text( (char *) &buf[0], 16, ( ( i + 6 + MAXPRIMARYWEAPONS ) * FontHeight ) , 2 );
            }

            sprintf( &buf[0], "L %hd - P %hd - G %hd Orbitals", OrbsInLevel, OrbsInPlayers, OrbsToGenerate );
            Print4x5Text( (char *) &buf[0], 16, ( ( MAXPRIMARYWEAPONS + MAXSECONDARYWEAPONS + 7 ) * FontHeight ) , 2 );

            if ( CTF )
            {
                for ( i = 0; i < MAX_TEAMS; i++ )
                {
                    sprintf( &buf[0], "L %d - P %d Flag %s", TeamFlagsInLevel[ i ], TeamFlagsInShips[ i ], TeamName[ i ] );
                    Print4x5Text( (char *) &buf[0], 16, ( ( MAXPRIMARYWEAPONS + MAXSECONDARYWEAPONS + 9 + i ) * FontHeight ) , 2 );
                }
            }
        }
#endif

        if( DS )
        {
            DisplayStatusMessages();
        }else if( ShowWeaponKills )
        {
            for( i = 0 ; i < MAXPRIMARYWEAPONS+1 ; i++ )
            {
                Printuint16( PrimaryStats[i] , (d3dappi.szClient.cx>>1)-(5*FontWidth), (viewport.dwY + (viewport.dwHeight>>2))+( i * ( FontHeight+(FontHeight>>1) ) ), 2 );
            }

            for( i = 0 ; i < TOTALSECONDARYWEAPONS ; i++ )
            {
                Printuint16( SecondaryStats[i] , (d3dappi.szClient.cx>>1)+(1*FontWidth), (viewport.dwY + (viewport.dwHeight>>2))+( i * ( FontHeight+(FontHeight>>1) ) ), 2 );
            }
                
        }else{
            sprintf( &buf[0], "CurRec %5d CurSent %5d MaxRec %5d MaxSent %5d", CurrentBytesPerSecRec , CurrentBytesPerSecSent , MaxCurrentBytesPerSecRec ,MaxCurrentBytesPerSecSent );
            CenterPrint4x5Text( (char *) &buf[0] , (FontHeight * 8) + (FontHeight>>1) + viewport.dwY , 2 );
            sprintf(&buf[0], "Rec %5d Sent %5d MaxRec %5d MaxSent %5d", RecPacketSize , BigPacketSize , MaxRecPacketSize , MaxBigPacketSize );
            CenterPrint4x5Text( (char *) &buf[0] , (FontHeight * 9) + (FontHeight>>1) + viewport.dwY , 2 );
        }



#ifdef DEBUG_SFX
        sprintf( buf, "sbuffer mem used hw %d ( max %d )", SBufferMemUsedHW, MaxSBufferMemUsedHW );
        CenterPrint4x5Text( buf , (FontHeight*8) + (FontHeight) + viewport.dwY , 2 );
        sprintf( buf, "sbuffer mem used sw %d ( max %d )", SBufferMemUsedSW, MaxSBufferMemUsedSW );
        CenterPrint4x5Text( buf , (FontHeight*10) + (FontHeight) + viewport.dwY , 2 );
        sprintf( buf, "currentbikecomp %d", CurrentBikeCompSpeech );
        CenterPrint4x5Text( buf , (FontHeight*12) + (FontHeight) + viewport.dwY , 2 );
#endif


    }
    return TRUE;
}


/*-------------------------------------------------------------------
    Procedure   :    Disp3d Panel..
    Input       :
    Output      :   BOOL TRUE/FALSE
-------------------------------------------------------------------*/
BOOL    Disp3dPanel( LPDIRECT3DDEVICE lpDev, LPDIRECT3DVIEWPORT lpView )
{
    VECTOR  Trans;
    MATRIX  Matrix;
    MATRIX  rotMatrix;
    MATRIX  finalMatrix;
    VECTOR  Pos;
    VECTOR  Temp;
    VECTOR  Scale;
    int clearflags;
    D3DRECT dummy;
    D3DVIEWPORT newviewport;
    float screen_width, screen_height;


//  return TRUE;

    newviewport.dwSize = sizeof(D3DVIEWPORT);
    newviewport.dwX = 0;
    newviewport.dwY = 0;
    newviewport.dwWidth = d3dapp->szClient.cx;
    newviewport.dwHeight = d3dapp->szClient.cy;
    newviewport.dvScaleX = newviewport.dwWidth / (float)2.0;
    newviewport.dvScaleY = newviewport.dwHeight / (float)2.0;
    newviewport.dvMaxX = (float)D3DDivide(D3DVAL(newviewport.dwWidth),
                                       D3DVAL(2 * newviewport.dvScaleX));
    newviewport.dvMaxY = (float)D3DDivide(D3DVAL(newviewport.dwHeight),
                                       D3DVAL(2 * newviewport.dvScaleY));
    
    if( d3dapp->lpD3DViewport->lpVtbl->SetViewport(d3dapp->lpD3DViewport, &newviewport) != D3D_OK )
        return FALSE;

    if ( d3dapp->bFullscreen )
    {
        screen_width = (float) d3dapp->ThisMode.w;
        screen_height = (float) d3dapp->ThisMode.h;
    }
    else
    {
        screen_width = (float) d3dapp->WindowsDisplay.w;
        screen_height = (float) d3dapp->WindowsDisplay.h;
    }
    pixel_aspect_ratio = screen_aspect_ratio * screen_height / screen_width;
    viewplane_distance = (float) ( newviewport.dwWidth / ( 2 * tan( DEG2RAD( normal_fov ) * 0.5 ) ) );
    panelproj._11 = 2 * viewplane_distance / newviewport.dwWidth;
    panelproj._22 = 2 * viewplane_distance / ( newviewport.dwHeight / pixel_aspect_ratio );

    if (lpD3Ddev->lpVtbl->SetMatrix(lpD3Ddev, hProj, &panelproj) != D3D_OK)
    {
            return FALSE;
    }

    
    
    clearflags = 0;
    if (d3dapprs.bZBufferOn != 0 )          // If a ZBuffer is enabled then always clear it..
    {
        clearflags |= D3DCLEAR_ZBUFFER;
    }
    if( clearflags != 0 )
    {
        dummy.x1 = newviewport.dwX;
        dummy.x2 = newviewport.dwX+newviewport.dwWidth;

        dummy.y1 = newviewport.dwY + ( newviewport.dwHeight >> 1 );
        dummy.y2 = dummy.y1+( newviewport.dwHeight >> 1);

        if( d3dappi.lpD3DViewport->lpVtbl->Clear(d3dappi.lpD3DViewport,
                                                 1, &dummy,
                                                 clearflags) != D3D_OK )
                                                 return FALSE;
    }

    Trans.x = 0.0F;
    Trans.y = -180.0F;
    Trans.z = 280.0F;

    Trans.x -= ( ( Ships[WhoIAm].Object.Speed.x * -4.0F ) + ( Ships[WhoIAm].Object.Angle.y * 8.0F ) );
    Trans.y -= ( ( Ships[WhoIAm].Object.Speed.y * -2.0F ) + ( Ships[WhoIAm].Object.Angle.x * 4.0F ) );
    Trans.z += ( Ships[WhoIAm].Object.Speed.z * 4.0F );
    

    Pos.x = -( ( Ships[WhoIAm].Object.Speed.x * -4.0F ) + ( Ships[WhoIAm].Object.Angle.y * 8.0F ) );
    Pos.y = -( ( Ships[WhoIAm].Object.Speed.y * -2.0F ) + ( Ships[WhoIAm].Object.Angle.x * 4.0F ) );
    Pos.z = +( Ships[WhoIAm].Object.Speed.z * 4.0F );

    ApplyMatrix( &MainCamera.Mat, &Pos, &Temp );

    Temp.x += MainCamera.Pos.x;
    Temp.y += MainCamera.Pos.y;
    Temp.z += MainCamera.Pos.z;

    Matrix = MainCamera.Mat;
    Matrix._41 = Temp.x;
    Matrix._42 = Temp.y;
    Matrix._43 = Temp.z;

    Scale.x = 0.5F;
    Scale.y = 0.5F;
    Scale.z = 0.5F;
    ScaleMatrix( &Matrix, &Scale );
    

    BuildRotMatrix( Ships[WhoIAm].Object.Angle.x, Ships[WhoIAm].Object.Angle.y, Ships[WhoIAm].Object.Angle.y+Ships[WhoIAm].Object.Angle.z, &rotMatrix);


    MatrixMultiply( &Matrix, &rotMatrix, &finalMatrix );

//  XLightMxloadHeader( &ModelHeaders[MODEL_Panel] , &Temp , SHIP_RADIUS*4.0F , &finalMatrix );
    XLightMxloadHeader( &ModelHeaders[MODEL_Eyeball] , &Temp , SHIP_RADIUS*4.0F , &finalMatrix );
    
    
    
//  view = identity;
    view._41 = Trans.x;
    view._42 = Trans.y;
    view._43 = Trans.z;
    view._11 = rotMatrix._11; 
    view._12 = rotMatrix._12;
    view._13 = rotMatrix._13;
    view._14 = rotMatrix._14;
               
    view._21 = rotMatrix._21;
    view._22 = rotMatrix._22;
    view._23 = rotMatrix._23;
    view._24 = rotMatrix._24;
               
    view._31 = rotMatrix._31;
    view._32 = rotMatrix._32;
    view._33 = rotMatrix._33;
    view._34 = rotMatrix._34;
                                          
    view._44 = rotMatrix._44;

    if (lpDev->lpVtbl->SetMatrix(lpDev, hView, &view) != D3D_OK)
        return FALSE;

//  if (ExecuteMxloadHeader( &ModelHeaders[MODEL_Panel], (uint16) -1 ) != TRUE )
    if (ExecuteMxloadHeader( &ModelHeaders[MODEL_Eyeball], (uint16) -1 ) != TRUE )
        return FALSE;

    if( d3dapp->lpD3DViewport->lpVtbl->SetViewport(d3dapp->lpD3DViewport, &viewport) != D3D_OK )
        return FALSE;

    if (lpD3Ddev->lpVtbl->SetMatrix(lpD3Ddev, hProj, &proj) != D3D_OK)
    {
            return FALSE;
    }


    return TRUE;
}





#if 0
                if( ModeCase != -1 )
                {
                    //  Blt Panel
                    GeneralBltFast( 0 , 0 , PanelVisibleX[ModeCase] , PanelVisibleY[ModeCase]  , 0  , d3dappi.szClient.cy-PanelVisibleY[ModeCase] ,
                                    lpDDSThree , (char*) &PanelNames[ModeCase] , DDBLTFAST_SRCCOLORKEY  | DDBLTFAST_WAIT , d3dapp->lpBackBuffer);
                    //  Primary one
                    GeneralBltFast( PrimaryX[Ships[WhoIAm].Primary] , PrimaryY[Ships[WhoIAm].Primary] , 48 , 32  , PrimaryWeaponShowX , PrimaryWeaponShowY ,
                                    lpDDSOne ,  (char*) "data\\pictures\\panel.bmp" , DDBLTFAST_SRCCOLORKEY  | DDBLTFAST_WAIT , d3dapp->lpBackBuffer);
                    
                    HealthCount+=  framelag;
                    //  Health one
                    src.top = ( ( (int) (HealthCount * 0.25F) ) & 15 ) * 8;
                    src.left = 0;
                    src.right = 32;
                    src.bottom = src.top+8;
            
                    memset(&fx, 0, sizeof(DDBLTFX));
                    fx.dwSize = sizeof(DDBLTFX);
                    dest.top = ( d3dappi.szClient.cy-10 )- ( Ships[WhoIAm].Shield >> 3 );
                    dest.bottom = d3dappi.szClient.cy-10;
                    dest.left = (d3dappi.szClient.cx >> 1) - 16 - 4;
                    dest.right = (d3dappi.szClient.cx >> 1) - 4;
                    
                    while( 1 )
                    {
                        ddrval = d3dapp->lpBackBuffer->lpVtbl->Blt( d3dapp->lpBackBuffer, &dest, lpDDSOne, &src, DDBLT_KEYSRC | DDBLT_WAIT , &fx );
                        if( ddrval == DD_OK )
                            break;
                        if( ddrval == DDERR_SURFACELOST )
                        {
                            d3dapp->lpFrontBuffer->lpVtbl->Restore(d3dapp->lpFrontBuffer);
                            d3dapp->lpBackBuffer->lpVtbl->Restore(d3dapp->lpBackBuffer);
                            DDReLoadBitmap( lpDDSOne, "data\\pictures\\panel.bmp" );
                            break;
                        }
                        if( ddrval != DDERR_WASSTILLDRAWING )
                            break;
                    }
            
                    //  Hull one
                    src.top = ( ( (int) ( (HealthCount * 0.25F) + 8 ) ^ 15 ) & 15 ) * 8;
                    src.left = 0;
                    src.right = 32;
                    src.bottom = src.top+8;
            
                    memset(&fx, 0, sizeof(DDBLTFX));
                    fx.dwSize = sizeof(DDBLTFX);
                    dest.top = ( d3dappi.szClient.cy-10 )- ( Ships[WhoIAm].Hull >> 3 );
                    dest.bottom = d3dappi.szClient.cy-10;
                    dest.left = (d3dappi.szClient.cx >> 1) + 4;
                    dest.right = (d3dappi.szClient.cx >> 1) + 4 + 16;
                    
                    while( 1 )
                    {
                        ddrval = d3dapp->lpBackBuffer->lpVtbl->Blt( d3dapp->lpBackBuffer, &dest, lpDDSOne, &src, DDBLT_KEYSRC | DDBLT_WAIT , &fx );
                        if( ddrval == DD_OK )
                            break;
                        if( ddrval == DDERR_SURFACELOST )
                        {
                            d3dapp->lpFrontBuffer->lpVtbl->Restore(d3dapp->lpFrontBuffer);
                            d3dapp->lpBackBuffer->lpVtbl->Restore(d3dapp->lpBackBuffer);
                            DDReLoadBitmap( lpDDSOne, "data\\pictures\\panel.bmp" );
                            break;
                        }
                        if( ddrval != DDERR_WASSTILLDRAWING )
                            break;
                    }
                    //  Powerpods
                    src.top = 0;
                    src.left = 32+64;
                    src.right = src.left+PowerSizes[Ships[WhoIAm].PowerLevel];
                    src.bottom = src.top+8;
                    y =  d3dappi.szClient.cy-74;
                    x =  ( d3dappi.szClient.cx >> 1 ) - 28;
            
                    while( 1 )
                    {
                        ddrval = d3dapp->lpBackBuffer->lpVtbl->BltFast( d3dapp->lpBackBuffer, x, y, lpDDSOne, &src, DDBLTFAST_SRCCOLORKEY  | DDBLTFAST_WAIT );
                        if( ddrval == DD_OK )
                            break;
                        if( ddrval == DDERR_SURFACELOST )
                        {
                            d3dapp->lpFrontBuffer->lpVtbl->Restore(d3dapp->lpFrontBuffer);
                            d3dapp->lpBackBuffer->lpVtbl->Restore(d3dapp->lpBackBuffer);
                            DDReLoadBitmap( lpDDSOne, "data\\pictures\\panel.bmp" );
                            break;
                        }
                        if( ddrval != DDERR_WASSTILLDRAWING )
                            break;
                    }
                }
                
                //  Blt Score
                Printuint16( Ships[WhoIAm].Shield , PanelShieldPosX, PanelShieldPosY , 2 );
                Printuint16( Ships[WhoIAm].Hull , PanelHullPosX, PanelHullPosY , 2 );
                // Blt Primary
                if( Ships[WhoIAm].Primary == PYROLITE_RIFLE )
                {
                    energy =  (int) PyroliteAmmo;
                }else{
                    if( Ships[WhoIAm].Primary == SUSS_GUN )
                    {
                        energy = (int) SussGunAmmo;
                    }else{
                        energy = (int) GeneralAmmo;
                    }
                }
                Printuint16( (uint16) energy , ( d3dappi.szClient.cx >> 1) - 64 , d3dappi.szClient.cy-( 48 - FontHeight - (FontHeight>>1) ), 2  );
            
                DoFontBlt( FontWidth*16 , FontHeight*Ships[WhoIAm].Primary , FontWidth*PrimaryLengths[Ships[WhoIAm].Primary] , FontHeight , PrimaryWeaponTextX , PrimaryWeaponTextY   );
                // Blt Secondary
                DoFontBlt( FontWidth*16 , (FontHeight*6)+FontHeight*Ships[WhoIAm].Secondary , FontWidth*SecondaryLengths[Ships[WhoIAm].Secondary] , FontHeight ,SecondaryWeaponTextX - ( FontWidth*SecondaryLengths[Ships[WhoIAm].Secondary] ) , SecondaryWeaponTextY );
                Printuint16( (uint16) GetCurSecAmmo() , SecondaryWeaponNumX - ( 4*FontWidth)  , SecondaryWeaponNumY + (FontHeight + (FontHeight>>1) ) , 2 );
                // blt shld
                DoFontBlt( FontWidth*28 , 0 , FontWidth*4 , FontHeight , PanelShieldTextPosX , PanelShieldTextPosY );
                // blt hull
                DoFontBlt( FontWidth*28 , FontHeight , FontWidth*4 , FontHeight , PanelHullTextPosX , PanelHullTextPosY );
#endif
/*-------------------------------------------------------------------
    Procedure   :   Init View port without calling initview..
    Input       :   Nothing
    Output      :   Nothing
-------------------------------------------------------------------*/
BOOL
InitViewport( float scale )
{
    HRESULT rval;
    int left, top;
    int width, height;
    int maxwidth, maxheight;

    /*
     * Setup the viewport for specified viewing area
     */
    memset(&viewport, 0, sizeof(D3DVIEWPORT));
    viewport.dwSize = sizeof(D3DVIEWPORT);
    rval = d3dapp->lpD3DViewport->lpVtbl->GetViewport(d3dapp->lpD3DViewport, &viewport);
    if (rval != D3D_OK) {
        Msg( "GetViewport failed.\n%s", D3DAppErrorToString(rval) );
        return FALSE;
    }
    maxwidth = d3dapp->szClient.cx;

    DrawSimplePanel = FALSE;
    if( scale < 1.01F )
        DrawSimplePanel = TRUE;

    if( DrawSimplePanel )
    {
        maxheight = d3dapp->szClient.cy - PanelVisibleY[ModeCase];
    }else{
        maxheight = d3dapp->szClient.cy;
    }
    if ( scale < 1.01F )
    {
        width = (int) floor( maxwidth * scale );
        if ( width < MIN_VIEWPORT_WIDTH )
        {
            width = MIN_VIEWPORT_WIDTH;
            scale = (float) width / maxwidth;
        }
        height = (int) floor( maxheight * scale );
        DrawPanel = FALSE;
        left = ( ( maxwidth - width ) >> 1 ) & ~1;
        top = ( ( maxheight - height ) >> 1 ) & ~1;
    }
    else
    {
        width = maxwidth;
        height = maxheight;
        if ( scale > 1.11F )
        {
            DrawPanel = TRUE;
            scale = 1.2F;
        }
        else
        {
            DrawPanel = FALSE;
        }
        left = 0;
        top = 0;
    }
    CurrentViewportScale = scale;

    viewport.dwX = left;
    viewport.dwY = top;
    viewport.dwWidth = width;
    viewport.dwHeight = height;
    viewport.dvScaleX = viewport.dwWidth / (float)2.0;
    viewport.dvScaleY = viewport.dwHeight / (float)2.0;
    viewport.dvMaxX = (float)D3DDivide(D3DVAL(viewport.dwWidth),
                                       D3DVAL(2 * viewport.dvScaleX));
    viewport.dvMaxY = (float)D3DDivide(D3DVAL(viewport.dwHeight),
                                       D3DVAL(2 * viewport.dvScaleY));
    rval = d3dapp->lpD3DViewport->lpVtbl->SetViewport(d3dapp->lpD3DViewport, &viewport);
    if (rval != D3D_OK) {
#ifdef DEBUG_VIEWPORT
        SetViewportError( "InitViewport", &viewport, rval );
#else
        Msg("SetViewport failed.\n%s", D3DAppErrorToString(rval));
#endif
        return FALSE;
    }
    SetFOV( hfov );

    // clear viewport
    D3DAppIClearBuffers();

    return TRUE;
}


/*-------------------------------------------------------------------
    Procedure   :   Plot Simple Panel...
    Input       :   Nothing
    Output      :   Nothing
-------------------------------------------------------------------*/
void    PlotSimplePanel( void )
{
    int energy;

    // Blt Primary
    if( ( Ships[WhoIAm].Primary != PrimaryChanged ) || ( ReMakeSimplePanel == TRUE ) )
    {
        PrimaryChanged = Ships[WhoIAm].Primary;
        GeneralBlt( ( Ships[WhoIAm].Primary & 3 ) * 64 ,
                    ( ( Ships[WhoIAm].Primary >> 2 )& 3 ) * 64 ,
                    64 , 64 , PrimaryWeaponShowX , PrimaryWeaponShowY ,
                    WeaponSizeX , WeaponSizeY ,
                    lpDDSFour , "data\\pictures\\pcontent.bmp" , 0 , lpDDSThree);

        GeneralBltFast( FontWidth*16 , FontHeight*Ships[WhoIAm].Primary  , FontWidth*PrimaryLengths[Ships[WhoIAm].Primary] , FontHeight ,
                        PrimaryWeaponTextX , PrimaryWeaponTextY , lpDDSTwo ,
                        /*&FontNames[ModeCase][0]*/DynamicFontNames ,
                         DDBLTFAST_WAIT, lpDDSThree);
    }
    
    

    // Blt Secondary
    if( ( Ships[WhoIAm].Secondary != SecondaryChanged ) || ( ReMakeSimplePanel == TRUE ) )
    {
        SecondaryChanged = Ships[WhoIAm].Secondary;
        GeneralBlt( ( (Ships[WhoIAm].Secondary+6) & 3 ) * 64 ,
                    ( ( (Ships[WhoIAm].Secondary+6) >> 2 )& 3 ) * 64 ,
                    64 , 64 , SecondaryWeaponShowX , SecondaryWeaponShowY ,
                    WeaponSizeX , WeaponSizeY ,
                    lpDDSFour , "data\\pictures\\pcontent.bmp" , 0 , lpDDSThree);
        GeneralBltFast( FontWidth*16 , (FontHeight*6)+FontHeight*Ships[WhoIAm].Secondary  , FontWidth*SecondaryLengths[Ships[WhoIAm].Secondary] , FontHeight ,
                        SecondaryWeaponTextX , SecondaryWeaponTextY , lpDDSTwo ,
                        /*&FontNames[ModeCase][0]*/DynamicFontNames ,
                        DDBLTFAST_WAIT, lpDDSThree);
    }


    // blt shld
    if( ReMakeSimplePanel == TRUE )
    {
        GeneralBltFast( FontWidth*28 , 0 , FontWidth*4 , FontHeight  , PanelShieldTextPosX , PanelShieldTextPosY ,
                        lpDDSTwo ,
                        /*&FontNames[ModeCase][0]*/DynamicFontNames ,
                        DDBLTFAST_SRCCOLORKEY  | DDBLTFAST_WAIT, lpDDSThree);
    }
    if( ( Ships[WhoIAm].Object.Shield != ShieldChanged ) || ( ReMakeSimplePanel == TRUE ) )
    {
        ShieldChanged = (uint16) Ships[WhoIAm].Object.Shield;

        Printuint16AnySurface( (uint16) Ships[WhoIAm].Object.Shield , PanelShieldPosX, PanelShieldPosY , 2 , DDBLTFAST_WAIT, lpDDSThree );
        
        if( ShieldHit == 0 )
        {
            GeneralBltFast( 64 - (int)(Ships[WhoIAm].Object.Shield *0.5F) , 24 , 56 , 3 , PanelShieldBarPosX , PanelShieldBarPosY ,
                            lpDDSOne ,  (char*) "data\\pictures\\panel.bmp" , DDBLTFAST_WAIT, lpDDSThree);
        }else{
            ShieldHit -=1;
            GeneralBltFast( 64 - (int)(Ships[WhoIAm].Object.Shield *0.5F) , 24 + ((ShieldHit>>2)*8) , 56 , 3  , PanelShieldBarPosX , PanelShieldBarPosY ,
                            lpDDSOne ,  (char*) "data\\pictures\\panel.bmp" , DDBLTFAST_WAIT , lpDDSThree);
            ShieldChanged = (uint16)-1;
        }
    }
    // blt Hull
    if( ReMakeSimplePanel == TRUE )
    {
        GeneralBltFast( FontWidth*28 , FontHeight , FontWidth*4 , FontHeight  , PanelHullTextPosX , PanelHullTextPosY ,
                        lpDDSTwo , 
                        /*&FontNames[ModeCase][0]*/DynamicFontNames ,
                        DDBLTFAST_SRCCOLORKEY  | DDBLTFAST_WAIT, lpDDSThree);
    }

    if( ( Ships[WhoIAm].Object.Hull != HullChanged ) || ( ReMakeSimplePanel == TRUE ) )
    {
        HullChanged = (uint16)Ships[WhoIAm].Object.Hull;
        Printuint16AnySurface( (uint16) Ships[WhoIAm].Object.Hull , PanelHullPosX, PanelHullPosY , 2 , DDBLTFAST_WAIT, lpDDSThree);
        if( HullHit == 0 )
        {
            GeneralBltFast( 64 - (int)(Ships[WhoIAm].Object.Hull *0.5F) , 24 , 56 , 3  , PanelHullBarPosX , PanelHullBarPosY ,
                            lpDDSOne ,  (char*) "data\\pictures\\panel.bmp" , DDBLTFAST_WAIT, lpDDSThree);
        }else{
            HullHit -=1;
            GeneralBltFast( 64 - (int)(Ships[WhoIAm].Object.Hull *0.5F) , 24 + ((HullHit>>2)*8) , 56 , 3  , PanelHullBarPosX , PanelHullBarPosY ,
                            lpDDSOne ,  (char*) "data\\pictures\\panel.bmp" , DDBLTFAST_WAIT , lpDDSThree);
            HullChanged = (uint16)-1;
        }
    }


    // Blt Power Pods
    if( ( PowerChanged != Ships[WhoIAm].Object.PowerLevel ) || ( ReMakeSimplePanel == TRUE ) )
    {
        GeneralBltFast( FontWidth*(32-7) , FontHeight*(7+Ships[WhoIAm].Object.PowerLevel) , FontWidth*7 , FontHeight  , PanelPowerPosX , PanelPowerPosY ,
                        lpDDSTwo , 
                        /*&FontNames[ModeCase][0]*/DynamicFontNames ,
                        DDBLTFAST_WAIT, lpDDSThree);

        PowerChanged = Ships[WhoIAm].Object.PowerLevel;
    }
    
    //  Blt Primary ammo
    if( Ships[WhoIAm].Primary == PYROLITE_RIFLE )
    {
        energy =  (int) PyroliteAmmo;
    }else{
        if( Ships[WhoIAm].Primary == SUSS_GUN )
        {
            energy = (int) SussGunAmmo;
        }else{
            energy = (int) GeneralAmmo;
        }
    }
    if( ( energy != PrimaryNumChanged ) || ( ReMakeSimplePanel == TRUE ) )
    {
        PrimaryNumChanged = energy;
        Printuint16AnySurface( (uint16) energy , PrimaryWeaponNumX , PrimaryWeaponNumY , 2 , DDBLTFAST_WAIT, lpDDSThree);
    }

    // Blt Secondary ammo
    if( ( (uint16) GetCurSecAmmo() != SecondaryNumChanged ) || ( ReMakeSimplePanel == TRUE ) )
    {
        SecondaryNumChanged = (uint16) GetCurSecAmmo();
        Printuint16AnySurface( (uint16) GetCurSecAmmo() , SecondaryWeaponNumX , SecondaryWeaponNumY , 2 , DDBLTFAST_WAIT, lpDDSThree );
    }
    
    //  Blt Panel
    GeneralBltFast( 0 , 0 , PanelVisibleX[ModeCase] , PanelVisibleY[ModeCase]  , 0  , d3dappi.szClient.cy-PanelVisibleY[ModeCase] ,
                    lpDDSThree , (char*) &PanelNames[ModeCase] , DDBLTFAST_SRCCOLORKEY  | DDBLTFAST_WAIT , d3dapp->lpBackBuffer);


    

    energy = (int) GetBestMine();
    // Blt Mine..
    if( energy != 65535 )
    {
        DoFontBlt( FontWidth*16 , (FontHeight*6)+FontHeight*energy , FontWidth*SecondaryLengths[energy] , FontHeight , d3dappi.szClient.cx - ( FontWidth*6) - ( FontWidth*SecondaryLengths[energy] ) , FontHeight  );
        Printuint16( (uint16) SecondaryAmmo[energy] , d3dappi.szClient.cx - ( FontWidth*5) , FontHeight , 2 );
    }

    ReMakeSimplePanel = FALSE;
}
    



void    FlipToGDISurface()
{
    d3dappi.lpDD->lpVtbl->FlipToGDISurface(d3dappi.lpDD);
}




/*-------------------------------------------------------------------
    Procedure   :       Make Specific Cmd Buffers...
    Input       :       nothing..
    Output      :       BOOL TRUE/FLASE
-------------------------------------------------------------------*/
BOOL
InitSpecialExecBufs( void )
{
    LPVOID lpBufStart, lpInsStart, lpPointer;
    size_t size;

    LPDIRECTDRAW lpDD = d3dapp->lpDD;
    LPDIRECT3D lpD3D = d3dapp->lpD3D;
    LPDIRECT3DDEVICE lpDev = d3dapp->lpD3DDevice;
    LPDIRECT3DVIEWPORT lpView = d3dapp->lpD3DViewport;


    size = 0;
    size += sizeof(D3DSTATE) * 9;
    size += sizeof(D3DINSTRUCTION) * 2;
    
    if (MakeExecuteBuffer( &debDesc, lpDev , &lpD3DNormCmdBuf , size ) != TRUE ) return FALSE;
    
    /*
     * lock it so it can be filled
     */
    if (lpD3DNormCmdBuf->lpVtbl->Lock(lpD3DNormCmdBuf, &debDesc) != D3D_OK) return FALSE;
    
    lpBufStart = debDesc.lpData;
    memset(lpBufStart, 0, size);
    lpPointer = lpBufStart;
    
    lpInsStart = lpPointer;


    //  this is for a normal non translucent buffers....
    if ( PowerVR )
    {
    OP_STATE_RENDER( 9, lpPointer);
    }
    else
    {
    OP_STATE_RENDER( 8, lpPointer);
    }
        STATE_DATA( D3DRENDERSTATE_TEXTUREMAPBLEND, D3DTBLEND_MODULATE, lpPointer );
        STATE_DATA( D3DRENDERSTATE_BLENDENABLE, FALSE, lpPointer );
        STATE_DATA( D3DRENDERSTATE_ZWRITEENABLE, TRUE, lpPointer );
        STATE_DATA( D3DRENDERSTATE_STIPPLEDALPHA , FALSE, lpPointer );
        STATE_DATA( D3DRENDERSTATE_SRCBLEND, D3DBLEND_ONE, lpPointer );
        STATE_DATA( D3DRENDERSTATE_DESTBLEND, D3DBLEND_ZERO, lpPointer );
        STATE_DATA( D3DRENDERSTATE_WRAPU, FALSE, lpPointer );
        STATE_DATA( D3DRENDERSTATE_WRAPV, FALSE, lpPointer );
        if ( PowerVR )
        {
            STATE_DATA( D3DRENDERSTATE_COLORKEYENABLE, TRUE, lpPointer );
        }
    OP_EXIT(lpPointer);
    
    /*
     * Setup the execute data describing the buffer
     */
    lpD3DNormCmdBuf->lpVtbl->Unlock(lpD3DNormCmdBuf);
    memset(&d3dExData, 0, sizeof(D3DEXECUTEDATA));
    d3dExData.dwSize = sizeof(D3DEXECUTEDATA);
    d3dExData.dwInstructionOffset = (ULONG) 0;
    d3dExData.dwInstructionLength = (ULONG) ((char *)lpPointer - (char*)lpInsStart);
    lpD3DNormCmdBuf->lpVtbl->SetExecuteData(lpD3DNormCmdBuf, &d3dExData);


    
    // Start of Trans exec Buffer...
    
    size = 0;

    if(d3dappi.ThisDriver.bIsHardware)
    {
        if( !UsedStippledAlpha )
        {
            size += sizeof(D3DSTATE) * 6;
        }else{
            size += sizeof(D3DSTATE) * 1;
        }
    }else{
        size += sizeof(D3DSTATE) * 1;
    }
    size += sizeof(D3DINSTRUCTION) * 2;

    
    if (MakeExecuteBuffer( &debDesc, lpDev , &lpD3DTransCmdBuf , size ) != TRUE ) return FALSE;
    
    
    /*
     * lock it so it can be filled
     */
    if (lpD3DTransCmdBuf->lpVtbl->Lock(lpD3DTransCmdBuf, &debDesc) != D3D_OK) return FALSE;
    
    lpBufStart = debDesc.lpData;
    memset(lpBufStart, 0, size);
    lpPointer = lpBufStart;
    
    lpInsStart = lpPointer;

    //  this is for Translucent buffers....
    if(d3dappi.ThisDriver.bIsHardware)
    {
        if( UsedStippledAlpha != TRUE )
        {
            if ( PowerVR )
            {
            OP_STATE_RENDER( 6, lpPointer);
            }
            else
            {
            OP_STATE_RENDER( 5, lpPointer);
            }

#if ACTUAL_TRANS
            STATE_DATA( D3DRENDERSTATE_ZWRITEENABLE, TRUE, lpPointer );
#else
            if( PowerVR )
            {
                STATE_DATA( D3DRENDERSTATE_ZWRITEENABLE, TRUE, lpPointer );
            }else{
                STATE_DATA( D3DRENDERSTATE_ZWRITEENABLE, FALSE, lpPointer );
            }
#endif

            STATE_DATA( D3DRENDERSTATE_BLENDENABLE, TRUE, lpPointer );
            STATE_DATA( D3DRENDERSTATE_SRCBLEND, CurrentSrcBlend, lpPointer );
            STATE_DATA( D3DRENDERSTATE_DESTBLEND, CurrentDestBlend, lpPointer );
            STATE_DATA( D3DRENDERSTATE_TEXTUREMAPBLEND, CurrentTextureBlend, lpPointer );
            if ( PowerVR )
            {
                STATE_DATA( D3DRENDERSTATE_COLORKEYENABLE, TRUE, lpPointer );
            }
        }
        else
        {
            OP_STATE_RENDER( 1, lpPointer);
//          STATE_DATA( D3DRENDERSTATE_BLENDENABLE, FALSE, lpPointer );
//          STATE_DATA( D3DRENDERSTATE_ZWRITEENABLE, FALSE, lpPointer );
            STATE_DATA( D3DRENDERSTATE_STIPPLEDALPHA , TRUE, lpPointer );
//          STATE_DATA( D3DRENDERSTATE_SRCBLEND, D3DBLEND_SRCCOLOR, lpPointer );
//          STATE_DATA( D3DRENDERSTATE_DESTBLEND, D3DBLEND_INVSRCCOLOR, lpPointer );
        }
    }
    else
    {
        OP_STATE_RENDER( 1, lpPointer);
        STATE_DATA( D3DRENDERSTATE_BLENDENABLE, TRUE, lpPointer );
    }

    OP_EXIT(lpPointer);
    
    /*
     * Setup the execute data describing the buffer
     */
    lpD3DTransCmdBuf->lpVtbl->Unlock(lpD3DTransCmdBuf);
    memset(&d3dExData, 0, sizeof(D3DEXECUTEDATA));
    d3dExData.dwSize = sizeof(D3DEXECUTEDATA);
    d3dExData.dwInstructionOffset = (ULONG) 0;
    d3dExData.dwInstructionLength = (ULONG) ((char *)lpPointer - (char*)lpInsStart);
    lpD3DTransCmdBuf->lpVtbl->SetExecuteData(lpD3DTransCmdBuf, &d3dExData);

    // Start of SpcFxTrans exec Buffer...
    
    size = 0;

    if(d3dappi.ThisDriver.bIsHardware)
    {
        if( !UsedStippledAlpha )
        {
            size += sizeof(D3DSTATE) * 5;
        }else{
            size += sizeof(D3DSTATE) * 1;
        }
    }else{
        size += sizeof(D3DSTATE) * 1;
    }

    size += sizeof(D3DINSTRUCTION) * 2;
    
    if (MakeExecuteBuffer( &debDesc, lpDev , &lpD3DSpcFxTransCmdBuf , size ) != TRUE ) return FALSE;
    
    /*
     * lock it so it can be filled
     */
    if (lpD3DSpcFxTransCmdBuf->lpVtbl->Lock(lpD3DSpcFxTransCmdBuf, &debDesc) != D3D_OK) return FALSE;
    
    lpBufStart = debDesc.lpData;
    memset(lpBufStart, 0, size);
    lpPointer = lpBufStart;
    
    lpInsStart = lpPointer;


    //  this is for SpcFxTranslucent buffers....
    if(d3dappi.ThisDriver.bIsHardware)
    {
        if( UsedStippledAlpha != TRUE )
        {
            OP_STATE_RENDER( 4, lpPointer);
            STATE_DATA( D3DRENDERSTATE_BLENDENABLE, TRUE, lpPointer );
            STATE_DATA( D3DRENDERSTATE_SRCBLEND, CurrentSrcBlend, lpPointer );
            STATE_DATA( D3DRENDERSTATE_DESTBLEND, CurrentDestBlend, lpPointer );
            STATE_DATA( D3DRENDERSTATE_TEXTUREMAPBLEND, CurrentTextureBlend, lpPointer );
        }
        else
        {
            OP_STATE_RENDER( 1, lpPointer);
            STATE_DATA( D3DRENDERSTATE_STIPPLEDALPHA , TRUE, lpPointer );
//          STATE_DATA( D3DRENDERSTATE_SRCBLEND, D3DBLEND_SRCCOLOR, lpPointer );
//          STATE_DATA( D3DRENDERSTATE_DESTBLEND, D3DBLEND_INVSRCCOLOR, lpPointer );
        }
    }
    else
    {
        OP_STATE_RENDER( 1, lpPointer);
        STATE_DATA( D3DRENDERSTATE_BLENDENABLE, TRUE, lpPointer );
    }

    OP_EXIT(lpPointer);
 
    /*
     * Setup the execute data describing the buffer
     */
    lpD3DSpcFxTransCmdBuf->lpVtbl->Unlock(lpD3DSpcFxTransCmdBuf);
    memset(&d3dExData, 0, sizeof(D3DEXECUTEDATA));
    d3dExData.dwSize = sizeof(D3DEXECUTEDATA);
    d3dExData.dwInstructionOffset = (ULONG) 0;
    d3dExData.dwInstructionLength = (ULONG) ((char *)lpPointer - (char*)lpInsStart);
    lpD3DSpcFxTransCmdBuf->lpVtbl->SetExecuteData(lpD3DSpcFxTransCmdBuf, &d3dExData);

    
    return TRUE;
}

/*-------------------------------------------------------------------
    Procedure   :       Release Specific Cmd Buffers...
    Input       :       nothing..
    Output      :       BOOL TRUE/FLASE
-------------------------------------------------------------------*/

void ReleaseSpecialExecBufs( void )
{
    if( lpD3DNormCmdBuf )
    {
        XRELEASE(lpD3DNormCmdBuf);
        lpD3DNormCmdBuf = NULL;
    }
    if( lpD3DTransCmdBuf )
    {
        XRELEASE(lpD3DTransCmdBuf);
        lpD3DTransCmdBuf = NULL;
    }
    if( lpD3DSpcFxTransCmdBuf )
    {
        XRELEASE(lpD3DSpcFxTransCmdBuf);
        lpD3DSpcFxTransCmdBuf = NULL;
    }
}

/*-------------------------------------------------------------------
    Procedure   :       Special Destroy game for dplay fuck up..
    Input       :       nothing..
    Output      :       nothing..
-------------------------------------------------------------------*/
void SpecialDestroyGame( void )
{
    IMustQuit = FALSE;
    
    if ( PlayDemo )
    {
        Panel = PreAttractModePanel;
        PlayDemo = FALSE;
    }

    switch( MyGameStatus )
    {
    case STATUS_WaitingToStartTeamGame:
    case STATUS_StartingMultiplayer:
    case STATUS_GetPlayerNum:

        DPlayDestroyPlayer(dcoID);
        dcoID = 0;
        DPlayRelease();
        MyGameStatus = STATUS_Title;
        MenuRestart( &MENU_ForceAbort );
        break;
    default:
        PreventFlips = FALSE;
        MyGameStatus = STATUS_QuitCurrentGame;
        break;
    }

}
/*-------------------------------------------------------------------
    Procedure   :       Calculate the framelag..
    Input       :       nothing..
    Output      :       nothing..
-------------------------------------------------------------------*/
void CalculateFramelag( void )
{
    framelag = 0.0F;
    if( IsServer )
    {
        while( framelag < 0.1F )
        {
            QueryPerformanceCounter((LARGE_INTEGER *) &LargeTime);
            TimeDiff = LargeTime - LastTime;
            framelag = (float) ( ( TimeDiff * 71.0 ) / Freq );
            framelag2 = framelag;
        }
    }else{
        QueryPerformanceCounter((LARGE_INTEGER *) &LargeTime);
        TimeDiff = LargeTime - LastTime;
        framelag = (float) ( ( TimeDiff * 71.0 ) / Freq );
        framelag2 = framelag;
    }

    LastTime = LargeTime;

    if( avgframelag == 0.0F )
    {
        avgframelag = framelag;
    }else{
        avgframelag += framelag;
        avgframelag *= 0.5F;
        avgframelag = (float) floor(avgframelag);
    }

    if( CurrentMenu && (MyGameStatus == STATUS_SinglePlayer) )
    {
        framelag = 0.0F;
    }

}


/*-------------------------------------------------------------------
    Procedure   :   Disp Tracker
    Input       :   LPDIRECT3DDEVICE    lpDev
                :   LPDIRECT3DVIEWPORT  lpView
    Output      :   BOOL                TRUE/FALSE
-------------------------------------------------------------------*/
BOOL DispTracker( LPDIRECT3DDEVICE lpDev, LPDIRECT3DVIEWPORT lpView )
{
    uint16      i;
    int         clearflags;
    D3DRECT     dummy;
    D3DVIEWPORT newviewport;
    float       screen_width, screen_height;
    VECTOR      TempVector;
    MATRIX      TempMatrix;
    float       TargetDistance;
    float       Red, Green, Blue, Trans;
    VECTOR      ShipDir, TargetDir;
    float       Cos;

    if ( d3dapp->bFullscreen )
    {
        screen_width = (float) d3dapp->ThisMode.w;
        screen_height = (float) d3dapp->ThisMode.h;
    }
    else
    {
        screen_width = (float) d3dapp->WindowsDisplay.w;
        screen_height = (float) d3dapp->WindowsDisplay.h;
    }
    pixel_aspect_ratio = screen_aspect_ratio * screen_height / screen_width;

    newviewport.dwSize = sizeof(D3DVIEWPORT);
    newviewport.dwX = 0;
    newviewport.dwY = 0;
    newviewport.dwWidth = ( d3dapp->szClient.cx / 3 ) & -2;
    newviewport.dwHeight = (uint32) ( (float) newviewport.dwWidth * pixel_aspect_ratio );
    newviewport.dvScaleX = newviewport.dwWidth / (float)2.0;
    newviewport.dvScaleY = newviewport.dwHeight / (float)2.0;
    newviewport.dvMaxX = (float)D3DDivide(D3DVAL(newviewport.dwWidth),
                                       D3DVAL(2 * newviewport.dvScaleX));
    newviewport.dvMaxY = (float)D3DDivide(D3DVAL(newviewport.dwHeight),
                                       D3DVAL(2 * newviewport.dvScaleY));
    
    if( d3dapp->lpD3DViewport->lpVtbl->SetViewport(d3dapp->lpD3DViewport, &newviewport) != D3D_OK )
        return FALSE;

    viewplane_distance = (float) ( newviewport.dwWidth / ( 2 * tan( DEG2RAD( normal_fov ) * 0.5 ) ) );
    panelproj._11 = 2 * viewplane_distance / newviewport.dwWidth;
    panelproj._22 = 2 * viewplane_distance / ( newviewport.dwHeight / pixel_aspect_ratio );

    if (lpD3Ddev->lpVtbl->SetMatrix(lpD3Ddev, hProj, &panelproj) != D3D_OK)
    {
            return FALSE;
    }

    clearflags = 0;
    if (d3dapprs.bZBufferOn != 0 )          // If a ZBuffer is enabled then always clear it..
    {
        clearflags |= D3DCLEAR_ZBUFFER;
    }
    if( clearflags != 0 )
    {
        dummy.x1 = newviewport.dwX;
        dummy.x2 = newviewport.dwX + newviewport.dwWidth;

        dummy.y1 = newviewport.dwY;
        dummy.y2 = newviewport.dwY + newviewport.dwHeight;

        if( d3dappi.lpD3DViewport->lpVtbl->Clear(d3dappi.lpD3DViewport,
                                                 1, &dummy,
                                                 clearflags) != D3D_OK )
                                                 return FALSE;
    }

    MatrixTranspose( &Ships[ WhoIAm ].Object.FinalMat, &TempMatrix );
    ShadeModel( MODEL_Tracker, &TempMatrix, ( 40.0F * GLOBAL_SCALE ), ( 220.0F * GLOBAL_SCALE ) );

    TempMatrix = MATRIX_Identity;
    TempMatrix._11 = 1.25F;
    TempMatrix._22 = 1.25F;
    TempMatrix._33 = 1.25F;
    MatrixMultiply( &TempMatrix, &Ships[ WhoIAm ].Object.FinalMat, &TempMatrix );

    view._11 = TempMatrix._11; 
    view._12 = TempMatrix._12;
    view._13 = TempMatrix._13;
    view._14 = TempMatrix._14;
               
    view._21 = TempMatrix._21;
    view._22 = TempMatrix._22;
    view._23 = TempMatrix._23;
    view._24 = TempMatrix._24;
               
    view._31 = TempMatrix._31;
    view._32 = TempMatrix._32;
    view._33 = TempMatrix._33;
    view._34 = TempMatrix._34;

    view._41 = 0.0F;
    view._42 = 0.0F;
    view._43 = ( 280.0F * GLOBAL_SCALE );
    view._44 = 1.0F;

    if (lpDev->lpVtbl->SetMatrix(lpDev, hView, &view) != D3D_OK)
        return FALSE;

    if (ReallyExecuteMxloadHeader( &ModelHeaders[MODEL_Tracker], (uint16) -1 ) != TRUE )
        return FALSE;

#if 0
    i = FindClosestPickup();
#else
    i = FindClosestShip();
#endif
    
    if( i != (uint16) -1 )
    {
        Red = 255.0F;
        Green = 255.0F;
        Blue = 255.0F;
        Trans = 255.0F;
#if 0
        TempVector.x = ( ( Pickups[ i ].Pos.x - Ships[ WhoIAm ].Object.Pos.x ) / 50.0F );
        TempVector.y = ( ( Pickups[ i ].Pos.y - Ships[ WhoIAm ].Object.Pos.y ) / 50.0F );
        TempVector.z = ( ( Pickups[ i ].Pos.z - Ships[ WhoIAm ].Object.Pos.z ) / 50.0F );
#else
        TempVector.x = ( ( Ships[ i ].Object.Pos.x - Ships[ WhoIAm ].Object.Pos.x ) / 50.0F );
        TempVector.y = ( ( Ships[ i ].Object.Pos.y - Ships[ WhoIAm ].Object.Pos.y ) / 50.0F );
        TempVector.z = ( ( Ships[ i ].Object.Pos.z - Ships[ WhoIAm ].Object.Pos.z ) / 50.0F );
#endif
        TargetDistance = VectorLength( &TempVector );

        if( TargetDistance > ( 130.0F * GLOBAL_SCALE ) )
        {
            NormaliseVector( &TempVector );
            TempVector.x *= ( 130.0F * GLOBAL_SCALE );
            TempVector.y *= ( 130.0F * GLOBAL_SCALE );
            TempVector.z *= ( 130.0F * GLOBAL_SCALE );
            Green = 64.0F;
            Blue = 64.0F;
        }
        else
        {
            ApplyMatrix( &Ships[ WhoIAm ].Object.FinalMat, &Forward, &ShipDir );
            NormaliseVector( &ShipDir );
            TargetDir = TempVector;
            NormaliseVector( &TargetDir );
            Cos = DotProduct( &ShipDir, &TargetDir );
            if( Cos < 0.0F )
            {
                Red = 256.0F + ( Cos * 192.0F );
                Green = 256.0F + ( Cos * 192.0F );
            }
        }

        TintModel( MODEL_Ping, Red, Green, Blue, Trans );

        MatrixTranspose( &Ships[ WhoIAm ].Object.FinalMat, &TempMatrix );
        ApplyMatrix( &TempMatrix, &TempVector, &TempVector );   // Calc Up Vector

        view = identity;
        view._11 = 1.25F;
        view._22 = 1.25F;
        view._33 = 1.25F;
        view._41 = TempVector.x;
        view._42 = TempVector.y;
        view._43 = TempVector.z + ( 280.0F * GLOBAL_SCALE );
        view._44 = 1.0F;

        if (lpDev->lpVtbl->SetMatrix(lpDev, hView, &view) != D3D_OK)
            return FALSE;

        if (ReallyExecuteMxloadHeader( &ModelHeaders[MODEL_Ping], (uint16) -1 ) != TRUE )
            return FALSE;
    }

    if( d3dapp->lpD3DViewport->lpVtbl->SetViewport(d3dapp->lpD3DViewport, &viewport) != D3D_OK )
        return FALSE;

    if (lpD3Ddev->lpVtbl->SetMatrix(lpD3Ddev, hProj, &proj) != D3D_OK)
    {
            return FALSE;
    }

    return TRUE;
}

#ifdef LOBBY_DEBUG

#define REGISTRY_LOBBY_KEY      (TEXT("Software\\Microsoft\\DirectPlay\\Applications\\Forsaken"))

#define LOBBY_GUID              "{27E96003-B1C3-11d1-B00C-080009C042E7}"
//#define LOBBY_COMMANDLINE     "-xmen -LogFile -NoAVI"


HKEY ghLobbyKey = NULL;     // lobby registry key handle
static DWORD                    gdwLobbyDisp;        // key created or opened

static LONG RegSetLobby(LPCTSTR lptszName, CONST BYTE * lpData, DWORD dwSize)
{
    return RegSetValueEx(ghLobbyKey, lptszName, 0, REG_SZ, lpData, dwSize);
}

void SetLobbyRegistrySettings( void )
{
    char buf[ 256 ];
    char *appname;
    int i;
    
    // set up registry key
    if ( !ghLobbyKey )
    {
#ifdef FINAL_RELEASE
        RegOpenKeyEx(REGISTRY_ROOT_KEY,
            REGISTRY_LOBBY_KEY,
            0,
            KEY_ALL_ACCESS,
            &ghLobbyKey
            );
#else
        RegCreateKeyEx(REGISTRY_ROOT_KEY,
            REGISTRY_LOBBY_KEY,
            0,
            NULL,                   
            REG_OPTION_NON_VOLATILE,
            KEY_ALL_ACCESS,
            NULL,
            &ghLobbyKey,
            &gdwLobbyDisp
            );
#endif
    }

    // set individual items 
    strcpy( buf, LOBBY_GUID );
    RegSetLobby("Guid", (CONST BYTE *)buf, sizeof( char ) * strlen( buf ) );

    buf[ 0 ] = 0;
    for ( i = 1; i < __argc; i++ )
    {
        strcat( buf, __argv[ i ] );
        strcat( buf, " " );
    }

//  strcpy( buf, LOBBY_COMMANDLINE );
    RegSetLobby("CommandLine", (CONST BYTE *)buf, sizeof( char ) * strlen( buf ) );

    _getcwd( buf, 256 );
    RegSetLobby("CurrentDirectory", (CONST BYTE *)buf, sizeof( char ) * strlen( buf ) );
    
    strcpy( buf, __argv[ 0 ] );
    appname = strrchr( buf, 92 );
    if( appname )
    {
        *appname = 0;
        RegSetLobby("Path", (CONST BYTE *)buf, sizeof( char ) * strlen( buf ) );
        RegSetLobby("File", (CONST BYTE *)&appname[ 1 ], sizeof( char ) * strlen( &appname[ 1 ] ) );
    }
}

#endif


/*-------------------------------------------------------------------
    Procedure   :   Once only init Stuff
    Input       :   Nothing
    Output      :   Nothing
-------------------------------------------------------------------*/
void    OnceOnlyInit( void )
{
    DWORD dwPlatform, dwVersion;

    GetDXVersion( &dwVersion, &dwPlatform);

    if ( dwVersion < 0x600 )
    {
        Msg("You need to install Direct X 6 or later in order to run 'Forsaken'\n");
        exit( 1 );
    }
    
    
    InitPolyText();

#ifndef FINAL_RELEASE
    DeleteFile( LogFilename );
    DeleteFile( BatchFilename );
#endif
    if (!InitDInput())
    {
        DebugPrintf( "Oct2.c OnceOnlyInit() Failed on InitDInput()\n" );
        exit(1);
    }
    FB_Initialise();

    InitValidPickups();
    SetupCharTransTable();

    QueryPerformanceCounter((LARGE_INTEGER *) &LargeTime);
    LastTime = LargeTime;
#ifdef SCROLLING_MESSAGES
    InitStatsMessages();
#endif

#ifdef LOBBY_DEBUG
        SetLobbyRegistrySettings();
#endif

}


/*-------------------------------------------------------------------
    Procedure   :   Once only Release Stuff
    Input       :   Nothing
    Output      :   Nothing
-------------------------------------------------------------------*/
void    OnceOnlyRelease( void )
{
    int joystick, i, j;


#ifdef MANUAL_SESSIONDESC_PROPAGATE
    if ( glpdpSD_copy )
        free ( glpdpSD_copy );
#endif
    
    DestroySound( DESTROYSOUND_All );
    TermDInput();

    if (CdIsPlaying())
    {
        CdStop();
        CloseCD();
    }

    for (joystick = 0; joystick < Num_Joysticks; joystick++)
    {
        free (JoystickInfo[joystick].Name);

        if ( JoystickInfo[ joystick ].connected )
        {
            for (i = 0; i < JoystickInfo[joystick].NumButtons; i++)
                free (JoystickInfo[joystick].Button[i].name);

            for (i = 0; i < JoystickInfo[joystick].NumPOVs; i++)
            {
                free (JoystickInfo[joystick].POV[i].name);
                for ( j = 0; j < MAX_POV_DIRECTIONS; j++ )
                {
                    if ( JoystickInfo[ joystick ].POV[ i ].dirname[ j ] )
                        free( JoystickInfo[ joystick ].POV[ i ].dirname[ j ] );
                    JoystickInfo[ joystick ].POV[ i ].dirname[ j ] = NULL;
                }
            }

            for (i = 0; i < MAX_JOYSTICK_AXIS; i++)
            {
                if (JoystickInfo[joystick].Axis[i].exists)
                    free (JoystickInfo[joystick].Axis[i].name);         
            }
        }
    }
}

/*-------------------------------------------------------------------
    Procedure   :   Change Background Colour
    Input       :   float   R   ( 0.0F - 1.0F )
                :   float   G   ( 0.0F - 1.0F )
                :   float   B   ( 0.0F - 1.0F )
    Output      :   BOOL    TRUE/FALSE
-------------------------------------------------------------------*/
BOOL ChangeBackgroundColour( float R, float G, float B )
{
    D3DMATERIAL bmat;
    D3DMATERIALHANDLE hBmat;
    LPDIRECT3D lpD3D = d3dapp->lpD3D;

    BOOL    HadtoCreate = FALSE;


    memset(&bmat, 0, sizeof(D3DMATERIAL));
    bmat.diffuse.r = R;
    bmat.diffuse.g = G;
    bmat.diffuse.b = B;
    bmat.dwSize = sizeof(D3DMATERIAL);
    bmat.dwRampSize = 1;


    if( !lpBmat )
    {
        if (lpD3D->lpVtbl->CreateMaterial(lpD3D, &lpBmat, NULL) != D3D_OK) return FALSE;
        HadtoCreate = TRUE;

    }

    if( lpBmat->lpVtbl->SetMaterial( lpBmat, &bmat ) != D3D_OK) return FALSE;
    if( lpBmat->lpVtbl->GetHandle(lpBmat, d3dapp->lpD3DDevice, &hBmat) != D3D_OK) return FALSE;
    if( d3dapp->lpD3DViewport->lpVtbl->SetBackground( d3dapp->lpD3DViewport, hBmat ) != D3D_OK) return FALSE;

    if( HadtoCreate )
    {
        RELEASE(lpBmat);
    }

    return TRUE;
}

/*-------------------------------------------------------------------
    Procedure   :   Print up how far the init view has to go...
    Input       :   BYTE GameStatus
    Output      :   void
-------------------------------------------------------------------*/
void PrintInitViewStatus( BYTE Status )
{
    int i;

    for( i = 0 ; i < ( Status - STATUS_InitView_0 )+1 ; i ++ )
    {
        CenterPrint4x5Text( InitViewMessages[i], ( d3dappi.szClient.cy >> 2 ) + ( i * ( FontHeight + ( FontHeight>>1 ) ) ) , 2 );
    }
}




/*-------------------------------------------------------------------
    Procedure   :   Detect if Power vr is being used...
    Input       :   Nothing
    Output      :   BOOL    FALSE/TRUE
-------------------------------------------------------------------*/
BOOL IsPowerVRD3DDevice(void)
{
    D3DTEXTUREHANDLE    hTex;
    DDSURFACEDESC       DDSurfDesc;
    LPDIRECTDRAWSURFACE lpDDSurface;
    LPDIRECT3DTEXTURE   lpD3DTexture;
    PPVR_CTL            lpPVRCtl;
    LPDIRECTDRAW lpDD = d3dapp->lpDD;
    LPDIRECT3DDEVICE lpD3DDev = d3dapp->lpD3DDevice;

    memset (&DDSurfDesc, 0, sizeof (DDSurfDesc));
    //  Try creating surface...
    DDSurfDesc.dwSize = sizeof (DDSURFACEDESC);
    DDSurfDesc.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH | DDSD_PIXELFORMAT;
    DDSurfDesc.dwHeight = 2;
    DDSurfDesc.dwWidth = 2;
    DDSurfDesc.ddsCaps.dwCaps = DDSCAPS_TEXTURE; 
    DDSurfDesc.ddpfPixelFormat.dwSize = sizeof (DDPIXELFORMAT); 
    DDSurfDesc.ddpfPixelFormat.dwFlags = DDPF_FOURCC; 
    DDSurfDesc.ddpfPixelFormat.dwFourCC = FOURCC_PVR_CTL; 
    //  If creation failed, PVR isn't present.
    if (lpDD->lpVtbl->CreateSurface(lpDD,&DDSurfDesc,&lpDDSurface,NULL) != DD_OK)
    {
        return FALSE;
    }
    //  Lock it to get pointer to our control structure.
    if (lpDDSurface->lpVtbl->Lock(lpDDSurface,NULL,&DDSurfDesc,DDLOCK_WAIT,NULL) != DD_OK)
    {
        RELEASE(lpDDSurface);
        return FALSE;
    }
    lpPVRCtl = (PPVR_CTL) DDSurfDesc.lpSurface;
    //  Get texturing interface
    if (lpDDSurface->lpVtbl->QueryInterface(lpDDSurface,&IID_IDirect3DTexture, &lpD3DTexture) !=DD_OK)
    {
        //  Have the pointer unlock surface now.
        lpDDSurface->lpVtbl->Unlock(lpDDSurface,&DDSurfDesc); 
        RELEASE(lpDDSurface);
        return FALSE;
    }
    //  Get a handle for the texture, if PowerVR is the supplied device we'll 
    //  see a non zero value in lpPVRCtl->pvReserved.
    lpD3DTexture->lpVtbl->GetHandle(lpD3DTexture,lpD3DDev,&hTex);
    //  Zero ? Yes, then its not PVR.
    if (!lpPVRCtl->pvReserved)
    {
        //  Have the pointer unlock surface now.
        lpDDSurface->lpVtbl->Unlock(lpDDSurface,&DDSurfDesc); 
        //  Release objects.
        RELEASE(lpD3DTexture);
        RELEASE(lpDDSurface);
        return FALSE;
    }
    //  Have the pointer unlock surface now.
    lpDDSurface->lpVtbl->Unlock(lpDDSurface,&DDSurfDesc); 
    //  Release objects.
    RELEASE(lpD3DTexture);
    RELEASE(lpDDSurface);
    //  Must be PVR !
    return TRUE;
}


/*-------------------------------------------------------------------
    Procedure   :   Pass On A New Bomb to SomeOne...
    Input       :   int Bomb Number...
    Output      :   Sets LowestBombTime...
-------------------------------------------------------------------*/
void PassOnNewBomb( int i )
{
    int j , e;
    
    BombNumToSend = i;
    BombTimeToSend = NewBombTime;


    j = LastPersonISentABomb;

    for( e = 0 ; e < MAX_PLAYERS ; e++ )
    {
        j++;
        if( j >= MAX_PLAYERS )
            j = 0;
        if( ( j != WhoIAm ) && ( GameStatus[j] == STATUS_Normal ) )
        {
            SendGameMessage( MSG_BOMB, 0, (BYTE) j, 0, 0 );
            LastPersonISentABomb = j;
            return;
        }
    }
    // uh oh Im the only one playing
    BombActive[i] = TRUE;
    BombTime[i] = NewBombTime;
}

/*-------------------------------------------------------------------
    Procedure   :   Finds The Bomb With the Shortest Fuse ...
    Input       :   Nothing
    Output      :   Sets LowestBombTime...
-------------------------------------------------------------------*/
extern  float       Time_Diff;
void UpdateBombs( void )
{
    int i;
    BOOL    BombHasBlownUp = FALSE;

    OldLowestBombTime = LowestBombTime;
    LowestBombTime = -1;
    if( !BombTag )
        return;

    for( i = 0 ; i < MAXBOMBS ; i++ )
    {
        if( BombActive[i] )
        {
            break;
        }
    }
    if( i == MAXBOMBS )
        ResetCountDownBombTag( 0.0F );

    if( !NumOfBombToStart || !IsHost )
    {
        for( i = 0 ; i < MAXBOMBS ; i++ )
        {
            if( BombActive[i] )
            {
                if( (BombTime[i] -= Time_Diff ) <= 0.0F )
                {
                    // One of My Bombs Has Blown Up.... Doh....
                    BombHasBlownUp = TRUE;
                    break;
                }else if( ( LowestBombTime == -1 ) || (BombTime[i] < BombTime[LowestBombTime] ) )
                {
                    LowestBombTime = i;
                }
            }
        }
        if( BombHasBlownUp )
        {
            Ships[WhoIAm].ShipThatLastHitMe = MAX_PLAYERS;
            Ships[WhoIAm].Damage = 255 + 255;   //make sure I Die....
            DoDamage( OVERRIDE_INVUL );
        
        
            Ships[WhoIAm].Object.Mode = DEATH_MODE;
            Ships[WhoIAm].Timer = 0.0F;
            AddMessageToQue( A_BOMB_KILLED_YOU );
            ShipDiedSend( WEPTYPE_Primary, 0);
        
        
            for( i = 0 ; i < MAXBOMBS ; i++ )
            {
                if( BombActive[i] )
                {
                    BombActive[i] = FALSE;
                    PassOnNewBomb( i );
                }
            }
            LowestBombTime = -1;
        }

        if( LowestBombTime != -1 )
        {
            if( LowestBombTime != OldLowestBombTime )
            {
                ResetCountDownBombTag( BombTime[LowestBombTime] );
            }
        }
    }

    UpdateCountdownDigits();


    if( NumOfBombToStart && IsHost )
    {
        while( NumOfBombToStart )
        {
            NumOfBombToStart--;
            PassOnNewBomb( NumOfBombToStart );
        }
        Time_Diff = 0.0F;
    }



}

/*-------------------------------------------------------------------
    Procedure   :       Init The Bombs...
    Input       :       nothing...
    Output      :       nothing..
-------------------------------------------------------------------*/
void InitBombs( void )
{
    int i;
    NewBombTime = ( 100.0F * 30.0F );   // approx 30 seconds...
    LowestBombTime = -1;
    OldLowestBombTime = -1;
    LastPersonISentABomb = 0;
    NumOfBombToStart = 1;

    for( i = 0 ; i < MAXBOMBS ; i++ )
    {
        BombActive[i]= FALSE;
        BombTime[i] = 0.0F;
    }
}




/*-------------------------------------------------------------------
    Procedure   :       Init Stats Display Stuff...
    Input       :       nothing...
    Output      :       BOOL TRUE/FALSE
-------------------------------------------------------------------*/
BOOL    InitStatsDisplay()
{
    // Create the offscreen surface, by loading our bitmap.

//  if( ModeCase != -1 )
//  {
//      lpDDSOne = DDLoadBitmap( d3dapp->lpDD, (char*) &StatsNames[ModeCase] , 0, 0 );
//      ddpal =  DDLoadPalette( d3dapp->lpDD , (char*) &StatsNames[ModeCase]);
//      lpDDSOne->lpVtbl->SetPalette( lpDDSOne , ddpal );
//  }
    InitFont(FALSE);
    ChangeBackgroundColour( 0, 0, 0 );

    HowManySecrets( &TotalSecrets , &Secrets );

    return TRUE;
}
/*-------------------------------------------------------------------
    Procedure   :       Free Stats Display Stuff...
    Input       :       nothing...
    Output      :       BOOL TRUE/FALSE
-------------------------------------------------------------------*/
BOOL    FreeStatsDisplay()
{
//  ReleaseDDSurf(lpDDSOne);
    ReleaseDDSurf(lpDDSTwo);
    lpDDSTwo = NULL;
    return TRUE;
}
/*-------------------------------------------------------------------
    Procedure   :       Stats Display...
    Input       :       nothing...
    Output      :       BOOL TRUE/FALSE
-------------------------------------------------------------------*/
BOOL StatsDisplay()
{
#if 0
    HRESULT ddrval;
    RECT    src;
    RECT    dest;
    DDBLTFX fx;
    int x,y;
#endif
    char buf[256];

#if 0
    //  Blt Background
    src.top = 0;
    src.left = 0;
    src.right = d3dappi.szClient.cx;
    src.bottom = d3dappi.szClient.cy;
    x = 0;
    y = 0;
    memset(&fx, 0, sizeof(DDBLTFX));
    fx.dwSize = sizeof(DDBLTFX);
    dest.top = 0;
    dest.bottom = d3dappi.szClient.cy;
    dest.left = 0;
    dest.right = d3dappi.szClient.cx;
            
    while( 1 )
    {
        ddrval = d3dapp->lpBackBuffer->lpVtbl->Blt( d3dapp->lpBackBuffer, &dest, lpDDSOne, &src, DDBLT_WAIT , &fx );
        if( ddrval == DD_OK )
            break;
        if( ddrval == DDERR_SURFACELOST )
        {
            d3dapp->lpFrontBuffer->lpVtbl->Restore(d3dapp->lpFrontBuffer);
            d3dapp->lpBackBuffer->lpVtbl->Restore(d3dapp->lpBackBuffer);
            DDReLoadBitmap( lpDDSOne, (char*) &StatsNames[ModeCase] );
            break;
        }
        if( ddrval != DDERR_WASSTILLDRAWING )
            break;
    }
#endif
    if( !GameCompleted )
    {
        if( Secrets == 1 )
        {
            sprintf( (char*) &buf ,"%d Secret found out of %d", Secrets , TotalSecrets );
        }else{
            sprintf( (char*) &buf ,"%d Secrets found out of %d", Secrets , TotalSecrets );
        }
        CenterPrint4x5Text( &buf[0] , (d3dappi.szClient.cy >> 1 ) - (FontHeight*2) , 2 );
        if( NumKilledEnemies == 1 )
        {
            sprintf( (char*) &buf ,"%d Enemy killed out of %d", NumKilledEnemies , NumInitEnemies );
        }else{
            sprintf( (char*) &buf ,"%d Enemies killed out of %d", NumKilledEnemies , NumInitEnemies );
        }
        CenterPrint4x5Text( &buf[0] , (d3dappi.szClient.cy >> 1 ) + (FontHeight*0) , 2 );
        if( CrystalsFound == 1 )
        {
            sprintf( (char*) &buf ,"%d Crystal found so far", CrystalsFound );
        }else{
            sprintf( (char*) &buf ,"%d Crystals found so far", CrystalsFound );
        }
        CenterPrint4x5Text( &buf[0] , (d3dappi.szClient.cy >> 1 ) + (FontHeight*2) , 2 );
    }else{
        CenterPrint4x5Text( "Congratulations" , (d3dappi.szClient.cy >> 1 ) - (FontHeight*2) , 2 );
        CenterPrint4x5Text( "Demo Complete" , (d3dappi.szClient.cy >> 1 ) + (FontHeight*0) , 2 );
        if( DifficultyLevel != 3 )
        {
            CenterPrint4x5Text( "Now Try a Harder Difficulty Setting" , (d3dappi.szClient.cy >> 1 ) + (FontHeight*2) , 2 );
        }else{
            CenterPrint4x5Text( "Try the real Game for a harder challenge" , (d3dappi.szClient.cy >> 1 ) + (FontHeight*2) , 2 );
        }
    }
    
    CenterPrint4x5Text( "Press Space to continue" , d3dappi.szClient.cy - (FontHeight*2) , 2 );
//  Our_CalculateFrameRate();


    return TRUE;
}

void InitModeCase(void)
{
#if 0
    if( d3dappi.szClient.cx >= 1024 && d3dappi.szClient.cy >= 768 )
        ModeCase = Mode1024X768;
    else if( d3dappi.szClient.cx >= 800 && d3dappi.szClient.cy >= 600 )
        ModeCase = Mode800X600;
    else if( d3dappi.szClient.cx >= 640 && d3dappi.szClient.cy >= 480 )
        ModeCase = Mode640X480;
    else if( d3dappi.szClient.cx >= 640 && d3dappi.szClient.cy >= 400 )
        ModeCase = Mode640X400;
    else if( d3dappi.szClient.cx >= 512 && d3dappi.szClient.cy >= 384 )
        ModeCase = Mode512X384;
    else if( d3dappi.szClient.cx >= 320 && d3dappi.szClient.cy >= 400 )
        ModeCase = Mode320X400;
    else if( d3dappi.szClient.cx >= 320 && d3dappi.szClient.cy >= 240 )
        ModeCase = Mode320X240;
    else
        ModeCase = Mode320X200;
#endif

    ModeCase = 0;   // now dynamic

    ModeScaleX[ 0 ] = (float)d3dappi.szClient.cx / 320.0F;
    ModeScaleY[ 0 ] = (float)d3dappi.szClient.cy / 200.0F;

    if ( ( d3dappi.szClient.cx >= 512 ) && ( d3dappi.szClient.cy >= 384 ) )
    {
        strcpy( DynamicFontNames, FontNames[ Mode512X384 ] );
    }else
    {
        strcpy( DynamicFontNames, FontNames[ Mode320X200 ] );
    }

    if( d3dappi.szClient.cx >= 800 && d3dappi.szClient.cy >= 600 )
        strcpy( DynamicScoreNames, ScoreNames[ Mode800X600 ] );
    else if( d3dappi.szClient.cx >= 640 && d3dappi.szClient.cy >= 480 )
        strcpy( DynamicScoreNames, ScoreNames[ Mode640X480 ] );
    else if( d3dappi.szClient.cx >= 640 && d3dappi.szClient.cy >= 400 )
        strcpy( DynamicScoreNames, ScoreNames[ Mode640X400 ] );
    else if( d3dappi.szClient.cx >= 512 && d3dappi.szClient.cy >= 384 )
        strcpy( DynamicScoreNames, ScoreNames[ Mode512X384 ] );
    else if( d3dappi.szClient.cx >= 320 && d3dappi.szClient.cy >= 400 )
        strcpy( DynamicScoreNames, ScoreNames[ Mode320X400 ] );
    else if( d3dappi.szClient.cx >= 320 && d3dappi.szClient.cy >= 240 )
        strcpy( DynamicScoreNames, ScoreNames[ Mode320X240 ] );
    else
        strcpy( DynamicScoreNames, ScoreNames[ Mode320X200 ] );

    // Check for Polygon Text.....
    bPolyText = FALSE;
    if(( d3dappi.szClient.cx >= 512 && d3dappi.szClient.cy >= 384 ) && PolygonText && !IsServer )
        bPolyText = TRUE;

}

/*-------------------------------------------------------------------
    Procedure   :       Get Bit Shift required to make first bit of
                :       mask bit 0
    Input       :       int32   Mask
    Output      :       int16   Shift Value
-------------------------------------------------------------------*/
int16 GetBitShift( int32 Mask )
{
    int16   Count;

    if( Mask )
    {
        Count = 0;

        while( !( Mask & 1 ) )
        {
            Count++;
            Mask >>= 1;
        }

        return( Count );
    }

    return( 0 );
}


/*-------------------------------------------------------------------
    Procedure   :       Render Snapshot
    Input       :       Nothing
    Output      :       Nothing
-------------------------------------------------------------------*/
void RenderSnapshot( void )
{
    LPDIRECT3DDEVICE lpDev = d3dapp->lpD3DDevice;
    LPDIRECT3DVIEWPORT lpView = d3dapp->lpD3DViewport;

    lpDev->lpVtbl->BeginScene(lpDev);

    CurrentCamera.enable = 1;
    CurrentCamera.UseLowestLOD = TRUE;
    CurrentCamera.GroupImIn = Ships[Current_Camera_View].Object.Group;  
    CurrentCamera.Mat = Ships[Current_Camera_View].Object.FinalMat; 
    CurrentCamera.InvMat = Ships[Current_Camera_View].Object.FinalInvMat;   
    CurrentCamera.Pos = Ships[Current_Camera_View].Object.Pos;  
    CurrentCamera.Viewport = viewport;  
    CurrentCamera.Proj = proj;  
    
    CurrentCamera.Viewport.dwX = 0;
    CurrentCamera.Viewport.dwY = 0;
    CurrentCamera.Viewport.dwWidth = 128;
    CurrentCamera.Viewport.dwHeight = 128;
    CurrentCamera.Viewport.dvScaleX = CurrentCamera.Viewport.dwWidth / (float)2.0;
    CurrentCamera.Viewport.dvScaleY = CurrentCamera.Viewport.dwHeight / (float)2.0;
    CurrentCamera.Viewport.dvMaxX = (float)D3DDivide(D3DVAL(CurrentCamera.Viewport.dwWidth),
                                       D3DVAL(2 * CurrentCamera.Viewport.dvScaleX));
    CurrentCamera.Viewport.dvMaxY = (float)D3DDivide(D3DVAL(CurrentCamera.Viewport.dwHeight),
                                       D3DVAL(2 * CurrentCamera.Viewport.dvScaleY));
    
    CurrentCamera.UseLowestLOD = TRUE;
    if( RenderCurrentCamera( lpDev , lpView ) != TRUE ) 
        return;

    lpDev->lpVtbl->EndScene(lpDev);
}

/*-------------------------------------------------------------------
    Procedure   :       Save PPM Bitmap
    Input       :       int8    *   Filename
                :       int8    *   Screen Pointer
                :       uint32      Width
                :       uint32      Height
                :       uint32      Bytes Per Pixel
                :       uint32      LineSize
                :       uint32      RedMask
                :       uint32      GreenMask
                :       uint32      BlueMask
                :       uint32      x1, y1, x2 ,y2 ( Portion of Screen )
    Output      :       BOOL        True/False
-------------------------------------------------------------------*/
BOOL SavePPM( uint8 * Filename, uint8 * ScreenPtr, uint32 Width, uint32 Height, uint32 BytesPerPixel,
              uint32 LineSize, uint32 RedMask, uint32 GreenMask, uint32 BlueMask,
              uint32 x1, uint32 y1, uint32 x2, uint32 y2 )
{
    uint32      XCount, YCount;
    uint32      RedMul, GreenMul, BlueMul;
    uint8       Red, Green, Blue;
    int16       RedShift, GreenShift, BlueShift;
    uint8   *   LinePtr;
    int8        Header[ 256 ];
    FILE    *   fp;
    int16       i;
    uint32      Val;
    uint32      Xoff, Yoff;
    uint32      Xsize, Ysize;

    if( ( x1 == x2 ) && ( y1 == y2 ) )
    {
        x1 = 0;
        y1 = 0;
        x2 = Width;
        y2 = Height;
    }

    Xoff = x1;
    Yoff = y1;
    Xsize = ( x2 - x1 );
    Ysize = ( y2 - y1 );

    fp = fopen( Filename, "wb" );

    if( fp != NULL )
    {
        sprintf( &Header[ 0 ], "P6%c#Forsaken (c)1998%c%d %d%c255%c", 10, 10, Xsize, Ysize, 10, 10 );

        i = 0;
        while( Header[ i ] )
        {
            fwrite( &Header[ i ], sizeof( int8 ), 1, fp );
            i++;
        }

        RedShift = GetBitShift( RedMask );
        GreenShift = GetBitShift( GreenMask );
        BlueShift = GetBitShift( BlueMask );

        RedMul = ( 256 / ( ( RedMask >> RedShift ) + 1 ) );
        GreenMul = ( 256 / ( ( GreenMask >> GreenShift ) + 1 ) );
        BlueMul = ( 256 / ( ( BlueMask >> BlueShift ) + 1 ) );

        ScreenPtr += ( Yoff * LineSize );

        for( YCount = 0; YCount < Ysize; YCount++ )
        {
            LinePtr = ( ScreenPtr + Xoff );

            for( XCount = 0; XCount < Xsize; XCount++ )
            {
                Val = 0;

                switch( BytesPerPixel )
                {
                    case 1:
                        Val = (uint32) LinePtr[0];
                        break;
                    case 2:
                        Val = (uint32) ( (uint32) LinePtr[0] ) |
                                     ( ( (uint32) LinePtr[1] ) << 8 );
                        break;
                    case 3:
                        Val = (uint32) ( (uint32) LinePtr[0] ) |
                                     ( ( (uint32) LinePtr[1] ) << 8 ) |
                                     ( ( (uint32) LinePtr[2] ) << 16 );
                        break;
                }
                LinePtr += BytesPerPixel;

                Red   = (uint8) ( ( ( Val & RedMask ) >> RedShift ) * RedMul );
                Green = (uint8) ( ( ( Val & GreenMask ) >> GreenShift ) * GreenMul );
                Blue  = (uint8) ( ( ( Val & BlueMask ) >> BlueShift ) * BlueMul );

                fwrite( &Red, sizeof( Red ), 1, fp );
                fwrite( &Green, sizeof( Green ), 1, fp );
                fwrite( &Blue, sizeof( Blue ), 1, fp );
            }

            ScreenPtr += LineSize;
        }

        fclose( fp );
    }
    else
    {
        DebugPrintf( "Failed to create %s\n", Filename );
        return( FALSE );
    }

    return( TRUE );
}

/*-------------------------------------------------------------------
    Procedure   :       Save SnapShot screen for saved game
    Input       :       int8    *   Filename
    Output      :       BOOL        True/False
-------------------------------------------------------------------*/
BOOL SaveSnapShot( int8 * Filename )
{
    HRESULT         hr;
    DDSURFACEDESC   SurfaceDesc;

    FreeAllLastAFrameScrPolys();
    RenderSnapshot();

    memset( &SurfaceDesc, 0, sizeof( SurfaceDesc ) );
    SurfaceDesc.dwSize = sizeof( SurfaceDesc );

    hr = d3dapp->lpBackBuffer->lpVtbl->Lock( d3dapp->lpBackBuffer, NULL, &SurfaceDesc,
                DDLOCK_SURFACEMEMORYPTR | DDLOCK_WAIT | DDLOCK_READONLY, NULL );

    if ( hr != DD_OK )
    {
        switch( hr )
        {
            case DDERR_INVALIDOBJECT:
                DebugPrintf( "Error Locking Surface ( Invalid Object )\n" );
                break;

            case DDERR_INVALIDPARAMS:
                DebugPrintf( "Error Locking Surface ( Invalid Params )\n" );
                break;

            case DDERR_OUTOFMEMORY:
                DebugPrintf( "Error Locking Surface ( Out of Memory )\n" );
                break;

            case DDERR_SURFACEBUSY:
                DebugPrintf( "Error Locking Surface ( Surface Busy )\n" );
                break;

            case DDERR_SURFACELOST:
                DebugPrintf( "Error Locking Surface ( Surface Lost )\n" );
                break;

            case DDERR_WASSTILLDRAWING:
                DebugPrintf( "Error Locking Surface ( Was Still Drawing )\n" );
                break;
        }
        return( FALSE );
    }

    SavePPM( Filename, SurfaceDesc.lpSurface, SurfaceDesc.dwWidth, SurfaceDesc.dwHeight,
              ( ( SurfaceDesc.ddpfPixelFormat.dwRGBBitCount + 7 )  / 8 ),
              SurfaceDesc.lPitch, SurfaceDesc.ddpfPixelFormat.dwRBitMask, SurfaceDesc.ddpfPixelFormat.dwGBitMask,
              SurfaceDesc.ddpfPixelFormat.dwBBitMask, 0, 0, 128, 128 );

    hr = d3dapp->lpBackBuffer->lpVtbl->Unlock( d3dapp->lpBackBuffer, NULL );
    if ( hr != DD_OK )
    {
        DebugPrintf( "Error Unlocking Surface\n" );
        return( FALSE );
    }

    if( CurrentMenu ) MenuDraw( CurrentMenu );
    MainGame( d3dapp->lpD3DDevice, d3dapp->lpD3DViewport );

    return( TRUE );
}

/*-------------------------------------------------------------------
    Procedure   :       Save SnapShot screen
    Input       :       int8    *   Filename
    Output      :       BOOL        True/False
-------------------------------------------------------------------*/
BOOL SaveFullScreenSnapShot( int8 * Filename )
{
    HRESULT         hr;
    DDSURFACEDESC   SurfaceDesc;

    memset( &SurfaceDesc, 0, sizeof( SurfaceDesc ) );
    SurfaceDesc.dwSize = sizeof( SurfaceDesc );

    hr = d3dapp->lpFrontBuffer->lpVtbl->Lock( d3dapp->lpFrontBuffer, NULL, &SurfaceDesc,
                DDLOCK_SURFACEMEMORYPTR | DDLOCK_WAIT | DDLOCK_READONLY, NULL );

    if ( hr != DD_OK )
    {
        switch( hr )
        {
            case DDERR_INVALIDOBJECT:
                DebugPrintf( "Error Locking Surface ( Invalid Object )\n" );
                break;

            case DDERR_INVALIDPARAMS:
                DebugPrintf( "Error Locking Surface ( Invalid Params )\n" );
                break;

            case DDERR_OUTOFMEMORY:
                DebugPrintf( "Error Locking Surface ( Out of Memory )\n" );
                break;

            case DDERR_SURFACEBUSY:
                DebugPrintf( "Error Locking Surface ( Surface Busy )\n" );
                break;

            case DDERR_SURFACELOST:
                DebugPrintf( "Error Locking Surface ( Surface Lost )\n" );
                break;

            case DDERR_WASSTILLDRAWING:
                DebugPrintf( "Error Locking Surface ( Was Still Drawing )\n" );
                break;
        }
        return( FALSE );
    }

    SavePPM( Filename, SurfaceDesc.lpSurface, SurfaceDesc.dwWidth, SurfaceDesc.dwHeight,
              ( ( SurfaceDesc.ddpfPixelFormat.dwRGBBitCount + 7 )  / 8 ),
              SurfaceDesc.lPitch, SurfaceDesc.ddpfPixelFormat.dwRBitMask, SurfaceDesc.ddpfPixelFormat.dwGBitMask,
              SurfaceDesc.ddpfPixelFormat.dwBBitMask, 0, 0, SurfaceDesc.dwWidth, SurfaceDesc.dwHeight );

    hr = d3dapp->lpFrontBuffer->lpVtbl->Unlock( d3dapp->lpFrontBuffer, NULL );
    if ( hr != DD_OK )
    {
        DebugPrintf( "Error Unlocking Surface\n" );
        return( FALSE );
    }
    return( TRUE );
}

BOOL GetValidCDPath( void )
{
    DWORD drivemask;
    int drive;
    UINT type;
#ifdef FINAL_RELEASE
    static char temp_path[128];
#endif

    if ( !cd_path[ 0 ] )
        return FALSE;
    drivemask = GetLogicalDrives();
    drive = toupper( cd_path[ 0 ] ) - 'A';
    if ( drive < 0 )
        return FALSE;
    if ( !( drivemask & ( 1 << drive ) ) )
        return FALSE;
    sprintf( cd_path, "%c:\\", 'A' + drive );
    type = GetDriveType( cd_path );
    if ( type != DRIVE_CDROM )
        return FALSE;
#ifdef FINAL_RELEASE
    strcpy( data_path, cd_path );
    strcat( data_path, "data\\" );
    use_data_path = 1;
    strncpy( temp_path, data_path, sizeof( temp_path ) );
    temp_path[ sizeof( temp_path ) - 1 ] = 0;
    strcpy( data_path, normdata_path );
    strcpy( normdata_path, temp_path );
#endif
    return TRUE;
}

int cd_present( void )
{
    static char volume_name[ 256 ];
    static char filesystem_name[ 256 ];
    DWORD sectors_per_cluster;
    DWORD bytes_per_sector;
    DWORD free_clusters;
    DWORD total_clusters;
    DWORD serial_number;
    DWORD max_pathname;
    DWORD flags;
    UINT errmode;
    BOOL vol_ok;

    if ( !GetDiskFreeSpace( cd_path, &sectors_per_cluster, &bytes_per_sector,
        &free_clusters, &total_clusters ) )
        return 0;
    if ( free_clusters )
        return 0;
    errmode = SetErrorMode( SEM_FAILCRITICALERRORS );
    vol_ok = GetVolumeInformation( cd_path, volume_name, sizeof( volume_name ),
        &serial_number, &max_pathname, &flags,
        filesystem_name, sizeof( filesystem_name ) );
    SetErrorMode( errmode );
    if ( !vol_ok )
        return 0;
#ifdef CD_VOLUME_NAME
    if ( _stricmp( volume_name, CD_VOLUME_NAME ) )
        return 0;
#endif
    return 1;
}



int ValidCD( void )
{
#ifdef CD_REQUIRED
    while ( !cd_present() )
    {
        if ( !RetryMsg( "Please insert the Forsaken CD\n" ) )
            return 0;
    }
#endif
    return 1;
}



#ifndef ACCLAIM_NY
#define DebugPrintf if ( 0 ) DebugPrintf
#endif


static int CheckFileWriteable( char *fname )
{
    HANDLE      fhandle;

    if ( ( fhandle = CreateFile( fname, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL ))
        == INVALID_HANDLE_VALUE )
    {
        DebugPrintf( "CreateFile( %s ) failed\n", fname );
        return 0;
    }
    else
    {
        DWORD attr;

        CloseHandle( fhandle );
        if ( ( attr = GetFileAttributes( fname ) ) == 0xFFFFFFFFL )
        {
            DebugPrintf( "GetFileAttributes( %s ) failed\n", fname );
            return -1;
        }
        if ( !SetFileAttributes( fname, FILE_ATTRIBUTE_NORMAL ) )
        {
            DebugPrintf( "SetFileAttributes( %s, 0x%x ) failed\n", fname, FILE_ATTRIBUTE_NORMAL );
            return -2;
        }
        if ( !SetFileAttributes( fname, attr ) )
        {
            DebugPrintf( "SetFileAttributes( %s, 0x%x ) failed\n", fname, attr );
            return -3;
        }
    }

    return 1;
}


#define CHECK_LEVEL     "probeworld"

int ValidInstall( void )
{
#if defined ( FINAL_RELEASE ) && !defined ( WIN98SHAREWARE ) 
    struct _stat stat;
    static char path[ MAX_PATH ];
    int j;

    for ( j = 0; j < __argc; j++ )
    {
        DebugPrintf( "argv[ %d ] = '%s'\n", j, __argv[ j ] );
    }

    if ( _stat( __argv[ 0 ], &stat ) )
    {
        DebugPrintf( "_stat( %s ) failed\n", __argv[ 0 ] );
        return 0;
    }
    if ( !( stat.st_mode & _S_IEXEC ) )
    {
        DebugPrintf( "_stat( %s ).st_mode not executable\n", __argv[ 0 ] );
        return 0;
    }
    if ( stat.st_mode & _S_IFDIR )
    {
        DebugPrintf( "_stat( %s ).st_mode is a directory\n", __argv[ 0 ] );
        return 0;
    }
    sprintf( path, "%c:\\", 'A' + stat.st_dev );
    if ( GetDriveType( path ) == DRIVE_CDROM )
    {
        DebugPrintf( "GetDriveType( %s ) returned CDROM (st_dev=%d)\n",
            path, stat.st_dev );
        return 0;
    }
    if ( CheckFileWriteable( "data\\models\\menu.mx" ) <= 0 )
        return 0; // this should always be installed
    sprintf( path, "%sdata\\levels\\%s\\%s.mxv", cd_path, CHECK_LEVEL, CHECK_LEVEL );
    switch ( CheckFileWriteable( path ) ) // this should exist, but never be writeable
    {
    case 0: // file not found
    case -1: // cannot get attrs
        return 0;
    case -2: // cannot set attrs
    case -3:
        break;
    default: // file writeable...!
        return 0;
    }
#endif
    return 1;
}

#ifdef  REFLECTION
LPDIRECTDRAWSURFACE lpDestTextureSurf = NULL;
void WierdShit( void )
{
    HDC                 hdcPrimary;
    HDC                 hdcDest;
    HRESULT             hr;
    DDSURFACEDESC ddsd2;
    LPDIRECT3DTEXTURE lpDestTexture = NULL;

    if( MyGameStatus != STATUS_Normal )
        return;


    if( !lpDestTextureSurf )
    {
        memcpy(&ddsd2, &d3dappi.ThisTextureFormat.ddsd, sizeof(DDSURFACEDESC));
        ddsd2.dwSize = sizeof(DDSURFACEDESC);
        ddsd2.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH | DDSD_PIXELFORMAT;
        ddsd2.ddsCaps.dwCaps = DDSCAPS_TEXTURE | DDSCAPS_SYSTEMMEMORY;

        ddsd2.dwHeight = 128;
        ddsd2.dwWidth = 256;
        
        if (d3dappi.lpDD->lpVtbl->CreateSurface(d3dappi.lpDD , &ddsd2, &lpDestTextureSurf, NULL) != DD_OK)
            lpDestTextureSurf = NULL;
    }
    if( !lpDestTextureSurf )
        return;


    if ((hr = d3dapp->lpBackBuffer->lpVtbl->GetDC( d3dapp->lpBackBuffer, &hdcPrimary )) == DD_OK)
    {
        if ((hr = lpDestTextureSurf->lpVtbl->GetDC( lpDestTextureSurf, &hdcDest )) == DD_OK)
        {

            StretchBlt(hdcDest, 0, 0, 128, 128, hdcPrimary, 0, 0, 128, 128, SRCCOPY);

            lpDestTextureSurf->lpVtbl->ReleaseDC(lpDestTextureSurf, hdcDest);
        }
        d3dapp->lpBackBuffer->lpVtbl->ReleaseDC( d3dapp->lpBackBuffer, hdcPrimary);
    }
    LastError = lpDestTextureSurf->lpVtbl->QueryInterface(lpDestTextureSurf,
                                             &IID_IDirect3DTexture,
                                             (LPVOID*)&lpDestTexture);

    Tloadheader.lpTexture[12]->lpVtbl->Load(Tloadheader.lpTexture[12], lpDestTexture);

}
#endif



/*-------------------------------------------------------------------
    Procedure   :       Server Main Routines...
    Input       :       nothing...
    Output      :       nothing
-------------------------------------------------------------------*/
void ServerMainRoutines( void )
{
    ProcessShips();
//  FirePrimary();
//  ProcessEnemies();
    ProcessSpotFX();
    ProcessPrimaryBullets();
    ProcessSecondaryBullets();
    if( !PlayDemo ) RegeneratePickups();
    ProcessPickups();
    ProcessBGObjects( TRUE );
//  ProcessRestartPoints();
    ProcessModels();
    ProcessPolys();
    ProcessXLights( &Mloadheader );
    DoAfterBurnerEffects();
    FmPolyProcess();
    CheckTimeLimit();
    if( CountDownOn ) UpdateCountdownDigits();
//  if( ForsakenAnyKey ) DisplayForsakenAnyKey();
//  ShowScreenMultiples();
    ProcessActiveConditions();
    ProcessTriggerAreas();
//  UpdateBombs();
    ProcessGoals();
    WaterProcess();
    ProcessRTLights();
}

/*-------------------------------------------------------------------
    Procedure   :       ServerMain Render Loop...
    Input       :       nothing...
    Output      :       nothing
-------------------------------------------------------------------*/
float   ServerDrawTimer = 0.0F;
#define PSEUDOHOST_CHECK_TIMER 1200.0F
float PseudoHostCheckTimer = PSEUDOHOST_CHECK_TIMER;

BOOL ServerMainGame(LPDIRECT3DDEVICE lpDev, LPDIRECT3DVIEWPORT lpView )
{
    int         i;
    LONGLONG    TempTime;
    VECTOR      ScatterDir;

    if ( !ServerChoosesGameType )
    {
        // check we have a pseudohost...
        PseudoHostCheckTimer -= framelag;
        if ( PseudoHostCheckTimer < 0.0F )
        {
            PseudoHostCheckTimer = PSEUDOHOST_CHECK_TIMER;
            if ( !PseudoHostDPID )
            {
                AllocatePseudoHost();
            }
        }
    }

    QueryPerformanceCounter((LARGE_INTEGER *) &GameCurrentTime);

    GameCurrentTime = GameCurrentTime - GameStartedTime;

//  Ships[WhoIAm].enable = FALSE;
/*-------------------------------------------------------------------
    Procedure   :    Main Routines to be called before Rendering....    
-------------------------------------------------------------------*/
    // set up groups indirectly visible by all active cameras
    InitIndirectVisible( Ships[Current_Camera_View].Object.Group );

    if( !PowerVR && ( ActiveRemoteCamera || (MissileCameraActive && MissileCameraEnable) ) )
    {
        AddIndirectVisible( (uint16) ( ( ActiveRemoteCamera ) ? ActiveRemoteCamera->Group : SecBulls[ CameraMissile ].GroupImIn ) );
    }

    ServerMainRoutines();

    if( MyGameStatus == STATUS_QuitCurrentGame )
        return TRUE;


    
    TloadCheckForLostSurfaces(&Tloadheader);
    memset( (void*) &IsGroupVisible[0] , 0 , MAXGROUPS * sizeof(uint16) );
    cral += (framelag*2.0F);

    for( i = 0 ; i < MAX_SFX ; i++ )
    {
        LastDistance[i] = 100000.0F;
    }

#ifdef SOFTWARE_ENABLE
    if( SoftwareVersion )
    {
//      CWClearZBuffer();
    }
#endif

/*-------------------------------------------------------------------
    Procedure   :    Now the Rendering can begin...
-------------------------------------------------------------------*/
    if( ServerRendering )
    {
        if (lpDev->lpVtbl->BeginScene(lpDev) != D3D_OK)
            return FALSE;

        PreventFlips = FALSE;
        
        CameraRendering = CAMRENDERING_Main;
        MainCamera.enable = 1;
        MainCamera.GroupImIn = Ships[Current_Camera_View].Object.Group; 
        MainCamera.Mat = Ships[Current_Camera_View].Object.FinalMat;    
        MainCamera.InvMat = Ships[Current_Camera_View].Object.FinalInvMat;  
        MainCamera.Pos = Ships[Current_Camera_View].Object.Pos; 
        MainCamera.Viewport = viewport; 
        MainCamera.Proj = proj; 
        CurrentCamera = MainCamera;
        CurrentCamera.UseLowestLOD = FALSE;
        if( RenderCurrentCamera( lpDev , lpView ) != TRUE ) 
            return FALSE;

        if (lpDev->lpVtbl->EndScene(lpDev) != D3D_OK)
            return FALSE;
    }else{
        ServerDrawTimer -= framelag;
        if( ServerDrawTimer > 0.0F )
        {
            PreventFlips = TRUE;
        }else{
            D3DAppClearScreenOnly();
            CenterPrint4x5Text( FORSAKEN_SERVER, (d3dappi.szClient.cy>>1)-(FontHeight>>1) , 2 );
            PreventFlips = FALSE;
            ServerDrawTimer = 60.0F;
        }
    }

    ScreenPolyProcess();


/* Secondary routines called after rendering */
        
    DplayGameUpdate();

    if( Our_CalculateFrameRate() != TRUE)
        return FALSE;


#ifdef SOFTWARE_ENABLE
    if( !SoftwareVersion )
#endif
    {
        if( CurrentMenu && CurrentMenuItem )
        {
            if( !ServerRendering )
            {
                D3DAppClearScreenOnly();
                PreventFlips = FALSE;
            }
            MenuDraw( CurrentMenu );

            MenuItemDrawCursor( CurrentMenuItem );

// Just to make sure that another press of escape doesnt take you back into the menu you wanted to exit!!
            JustExitedMenu = TRUE;
            
            MenuProcess();
        }else{
            ScoreSort();
            PrintScoreSort();
        }

    }

    ProcessGameKeys();

    CheckForRogueSfx();

    CheckLevelEnd();


    QueryPerformanceCounter((LARGE_INTEGER *) &TempTime);
    for( i = 1 ; i < MAX_PLAYERS ; i++ )
    {
        if( (GameStatus[i] != STATUS_GetPlayerNum ) && 
            (GameStatus[i] != STATUS_DisabledByServer ) &&
            (GameStatus[i] != STATUS_StartingMultiplayer ) &&
            (GameStatus[i] != STATUS_Joining ) &&
            (GameStatus[i] != STATUS_LeftCrashed ) &&
            (GameStatus[i] != STATUS_Left ) &&
            (GameStatus[i] != STATUS_Null ) )
        {
            if( ( (TempTime - LastPacketTime[i]) / Freq ) > 15 )
            {
//              SendGameMessage(MSG_YOUQUIT, 0, (BYTE) i , 0, 0);
                ScatterDir = Ships[ i ].LastMove;
                NormaliseVector( &ScatterDir );
                ScatterWeaponsForShip( (uint16) i, &ScatterDir, MAXPICKUPS ); // Scatter all weapons in direction.
                GameStatus[i] = STATUS_DisabledByServer;
                Ships[i].enable = FALSE;
                LastPacketTime[i] = TempTime;
            }
        }
    }
    return TRUE;
}

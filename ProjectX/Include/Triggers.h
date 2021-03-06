/*
 * The X Men, January 1997
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * Authors: Phillipd, Oliverc, Collinsd
 */
#ifndef TRIGGERS_INCLUDED
#define TRIGGERS_INCLUDED

/*
 * Defines
 */

#define DEBUG_TRIGGERS      0


#define MAXDATAPEREVENT     64  // in bytes

#define TRIGGEROP_Set       0
#define TRIGGEROP_Reset     1
#define TRIGGEROP_Inc       2
#define TRIGGEROP_Dec       3
#define TRIGGEROP_Or        4
#define TRIGGEROP_And       5
#define TRIGGEROP_Xor       6
#define TRIGGEROP_Multiply  7
#define TRIGGEROP_Divide    8
#define TRIGGEROP_Random    9
#define TRIGGEROP_Setflag   10
#define TRIGGEROP_Clearflag 11


#define TRIGGERTYPE_Equal               0
#define TRIGGERTYPE_NotEqual            1
#define TRIGGERTYPE_Less                2
#define TRIGGERTYPE_Greater             3
#define TRIGGERTYPE_LessEqual           4
#define TRIGGERTYPE_GreaterEqual        5
#define TRIGGERTYPE_FlagCount           6
#define TRIGGERTYPE_FlagTest            7


#define TRIGGEREVENT_Pickup         0
#define TRIGGEREVENT_Enemy          1
#define TRIGGEREVENT_OpenDoor       2
#define TRIGGEREVENT_CloseDoor      3
#define TRIGGEREVENT_LockDoor       4
#define TRIGGEREVENT_UnlockDoor     5
#define TRIGGEREVENT_StartBGOAnim   6
#define TRIGGEREVENT_StopBGOAnim    7
#define TRIGGEREVENT_StartTexAnim   8
#define TRIGGEREVENT_StopTexAnim    9
#define TRIGGEREVENT_StartExternalForce 10
#define TRIGGEREVENT_StopExternalForce  11
#define TRIGGEREVENT_EnableTeleport     12
#define TRIGGEREVENT_DisableTeleport    13
#define TRIGGEREVENT_WaterFill          14
#define TRIGGEREVENT_WaterDrain         15
#define TRIGGEREVENT_StartSpotFX        16
#define TRIGGEREVENT_StopSpotFX         17
#define TRIGGEREVENT_ShowMessage        18
#define TRIGGEREVENT_LightEnable        19
#define TRIGGEREVENT_LightDisable       20
#define TRIGGEREVENT_TriggerAreaEnable  21
#define TRIGGEREVENT_TriggerAreaDisable 22
#define TRIGGEREVENT_CameraEnable   23
#define TRIGGEREVENT_CameraDisable  24
 
/*
 * Structures
 */

typedef struct CONDITION{
    int     NumOfTriggers;
    struct  TRIGGER ** Triggers;
    int     NumOfEvents;
    struct  EVENT ** Events;
}CONDITION;

typedef struct EVENT{
    BYTE    Type;               // Which type of event to trigger..
    BYTE    Data[MAXDATAPEREVENT];
}EVENT;

typedef struct TRIGGERVAR{
    int     State;              // TRUE / FALSE ...
    int     InitState;
    int     NumOfTriggers;
    char    Name[32];
    struct  TRIGGER ** Triggers;
}TRIGGERVAR;

typedef struct TRIGGER{
    BYTE    Type;
    TRIGGERVAR *    TrigVar;    // TRUE / FALSE ...
    int     ActiveState;        // TRUE / FALSE ...
    int     Active;             // FALSE...TRUE...
    int     NumOfConditions;
    CONDITION ** Conditions;
}TRIGGER;

typedef struct TRIGGERMOD{
    int     Op;
    int     Val;
    float   Time;
    TRIGGERVAR *    TrigVar;
    struct TRIGGERMOD   *Next;
}TRIGGERMOD;


typedef struct TRIGGERMODQUE{
    float   Time;
    struct TRIGGERMOD   *TriggerMod;
}TRIGGERMODQUE;




/*
 * fn prototypes
 */
BOOL Triggerload( char * Filename );
void ReleaseTriggers( void );
void ApplyTriggerMod( TRIGGERMOD * TrigMod );
void ModifyTriggerVar( TRIGGERVAR * TrigVar , int Op , int Val );
void TestAllConditions( TRIGGER * Trig );
void AddCondition( CONDITION * Con );
void ProcessActiveConditions( void );
void ProcessEvent( EVENT * Event );
void GenTriggerList( uint16 Ship, SHORTTRIGGER * TriggerSlots, BYTE * NumTriggerSlots, BYTE Section );
void RegenTriggerList( SHORTTRIGGER * Slots, BYTE Num );
void CopyTriggers( uint16 Player );
void GenTrigVarList( uint16 Ship, SHORTTRIGVAR * TrigVarSlots, BYTE * NumTrigVarSlots, BYTE Section );
void RegenTrigVarList( SHORTTRIGVAR * Slots, BYTE Num );
void CopyTrigVars( uint16 Player );
void HowManySecrets( int * NumOfSecrets , int * SecretsFound );
BOOL HasLevelEnded( void );
BOOL IsAvatarActive( void );
BOOL CheckDecreaseTemperature( void );

// Event Prototypes...
void EVENT_PickupGenerate( uint8 * Data );
void EVENT_EnemyGenerate( uint8 * Data );
void EVENT_OpenDoor( uint8 * Data );
void EVENT_CloseDoor( uint8 * Data );
void EVENT_LockDoor( uint8 * Data );
void EVENT_UnlockDoor( uint8 * Data );
void EVENT_StartBGOAnim( uint8 * Data );
void EVENT_StopBGOAnim( uint8 * Data );
void EVENT_StartTexAnim( uint8 * Data );
void EVENT_StopTexAnim( uint8 * Data );
void EVENT_WaterFill( uint8 * Data );
void EVENT_WaterDrain( uint8 * Data );
void EVENT_StartSpotFX( uint8 * Data );
void EVENT_StopSpotFX( uint8 * Data );
void EVENT_ShowMessages( uint8 * Data );
void EVENT_StartExternalForce( uint8 * Data );
void EVENT_StopExternalForce( uint8 * Data );
void EVENT_EnableLight( uint8 * Data );
void EVENT_DisableLight( uint8 * Data );
void EVENT_TriggerAreaEnable( uint8 * Data );
void EVENT_TriggerAreaDisable( uint8 * Data );
void EVENT_CameraEnable( uint8 * Data );
void EVENT_CameraDisable( uint8 * Data );
void EVENT_TeleportEnable( uint8 * Data );
void EVENT_TeleportDisable( uint8 * Data );

FILE * SaveAllTriggers( FILE * fp );
FILE * LoadAllTriggers( FILE * fp );


#endif  // TRIGGERS_INCLUDED



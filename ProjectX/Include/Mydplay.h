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
 *  File:       mydplay.h
 *  Content:    main include file
 *
 *
 ***************************************************************************/

#ifndef MYDPLAY_INCLUDED
#define MYDPLAY_INCLUDED

#define IDIRECTPLAY2_OR_GREATER
#define WIN32_EXTRA_LEAN

 
 /*
 * defines
 */
#define FIND_SESSION_TIMEOUT    3600.0F

#define MULTIPLAYER_VERSION     (0x010d)
#define DEMO_MULTIPLAYER_VERSION (0x0109)

#define GUARANTEEDMESSAGES

#define MAXPACKETSPERBIGPACKET 64
#define MAXBIGPACKETBUFFERSIZE 1024
#define MAXPACKETSPERSERVERPACKET 64


#define SHORTBANK
#define VERYSHORTPACKETS

#define NOISEFALLOFFFACTOR ( 1.0F / 120.0F )    // approx 2 seconds....

#define NORMAL_MODE 0
#define DEATH_MODE 1
#define LIMBO_MODE 2        // this is what the ship is in while viewing its own death....but has blown up...
#define DEMO_MODE  3        // this is the mode the camera goes into when Playing back a Demo
#define GAMEOVER_MODE  4    // this is the mode the player goes into when single player has finished...


#define MAX_PLAYERS         32 //24 //16 //12
BOOL PlayerReady[MAX_PLAYERS];
#define MAX_SHIELD          255.0F
#define START_SHIELD        128.0F
#define MAX_HULL            255.0F
#define START_HULL          128.0F

#define MAXTEXTMSG          128     // the number of chars in a message you can send.....

#define MAXGENPICKUPCOUNT   5
#define MAXGENREGENSLOTCOUNT 6
#define MAXGENMINECOUNT     3 //4
#define MAXGENTRIGGERCOUNT  60
#define MAXGENTRIGVARCOUNT  60

#define MAXMULTIPLES        8

#define MAX_PICKUPFLAGS     2

#define MAX_BUFFER_SIZE    1024

#define FRAMELAGED_RECOIL   TRUE
#define ONEOFF_RECOIL       FALSE

#define MAX_TEAMS 4

#define NUMTITANBITS        10 

/*
 * structures
 */
/*-------------------------------------------------------------------
    Bodge Structures
-------------------------------------------------------------------*/
typedef struct SHORTMINE{

    uint16  OwnerType;
    uint16  Owner;
    uint16  BulletID;
    uint16  Group;
    VECTOR  Pos;
    VECTOR  Offset;
    VECTOR  Dir;
    VECTOR  UpVector;
    VECTOR  DropDir;
    uint16  Weapon;
    float   LifeCount;

}SHORTMINE;

/*-------------------------------------------------------------------
    Bodge Structures
-------------------------------------------------------------------*/
typedef struct SHORTKILLMINE{
    uint16  OwnerType;          // Owner ID
    uint16  Owner;              // Owner ID
    uint16  ID;                 // ID
    float   ShockwaveSize;      // Size
}SHORTKILLMINE;
/*-------------------------------------------------------------------
    Bodge Structures
-------------------------------------------------------------------*/

typedef struct MISSEDMINEMSG{
    int16   Type;
    void *  Struct;
}MISSEDMINEMSG;

/*-------------------------------------------------------------------
    Bodge Structures
-------------------------------------------------------------------*/
typedef struct SHORTPICKUP{
    int16   Type;
    int16   Group;
    uint16  Owner;              // Owner ID
    uint16  ID;                 // ID
    VECTOR  Pos;
    VECTOR  Dir;
    int16   RegenSlot;
    float   Speed;
    BOOL    Sparkle;
    float   LifeCount;
    uint16  TriggerMod;
}SHORTPICKUP;

typedef struct SHORTTRIGVAR{
    int     State;
}SHORTTRIGVAR;

typedef struct SHORTTRIGGER{
    int     Active;
}SHORTTRIGGER;

/*-------------------------------------------------------------------
    Bodge Structures
-------------------------------------------------------------------*/
typedef struct SHORTREGENSLOT{

    uint16  GenType;            // Generation Type
    uint16  RegenType;          // Regeneration Type
    float   GenDelay;           // Generation Delay ( 60hz )
    float   Lifespan;           // Lifespan of pickup ( 60hz )
    float   Wait;               // Global count
    int16   Status;             // Status of slot
    int16   Group;              // Group to generate pickup
    VECTOR  Pos;                // Position to generate pickup
    uint16  Type;               // Type of pickup
    uint16  TriggerMod;         // Trigger Mod Index
    uint16  PickupIndex;        // Pickup Index
    uint16  PickupID;           // Pickup ID

}SHORTREGENSLOT;

/*-------------------------------------------------------------------
    Bodge Structures
-------------------------------------------------------------------*/
typedef struct SHORTKILLPICKUP{
    uint16  Owner;              // Owner ID
    uint16  ID;                 // ID
    int16   Style;              // Style
}SHORTKILLPICKUP;

/*-------------------------------------------------------------------
    Bodge Structures
-------------------------------------------------------------------*/
typedef struct SHORTSERVERKILLPICKUP{
    uint16  Owner;              // Owner ID
    uint16  ID;                 // ID
    int16   Style;              // Style
    uint16  NewOwner;

}SHORTSERVERKILLPICKUP;

/*-------------------------------------------------------------------
    Bodge Structures
-------------------------------------------------------------------*/
typedef struct MISSEDPICKUPMSG{
    int16   Type;
    void *  Struct;
}MISSEDPICKUPMSG;


typedef char        SHORTNAMETYPE[MAX_PLAYERS][8];

typedef struct _SHIPDIEDINFO
{
    BYTE        WeaponType;
    BYTE        Weapon;

} SHIPDIEDINFO;

typedef struct _PICKUPINFO
{
    uint16      IDCount;
    int16       Type;
    uint16      Group;
    VECTOR      Pos;
    VECTOR      Dir;
    float       Speed;
    int16       RegenSlot;
    BOOL        Sparkle;
    float       LifeCount;
    uint16      TriggerMod;
}PICKUPINFO; // 46

typedef struct _VERYSHORTPICKUPINFO
{
    uint16      IDCount;
    BYTE        Type;
    BYTE        Group;
    BYTE        RegenSlot;
    BYTE        Sparkle;
    SHORTVECTOR Pos;
    SHORTVECTOR Dir;
    float       Speed;
    float       LifeCount;
    uint16      TriggerMod;
}VERYSHORTPICKUPINFO; // 28



typedef struct _KILLPICKUPINFO
{
    uint16      Owner;
    uint16      IDCount;
    int16       Style;
}KILLPICKUPINFO;

typedef struct _SERVERKILLPICKUPINFO
{
    uint16      Owner;
    uint16      IDCount;
    int16       Style;
    uint16      NewOwner;
}SERVERKILLPICKUPINFO;

typedef struct _EXPLODESHIPINFO
{
    uint16      Ship;
}EXPLODESHIPINFO;

typedef struct _EXPSECONDARYINFO
{
    uint16      OwnerType;
    uint16      Owner;
    uint16      IDCount;
    float       ShockwaveSize;
    VECTOR      Pos;
    uint16      Group;

}EXPSECONDARYINFO;

typedef struct _TEAMGOALSINFO
{
    uint16      TeamGoals[ MAX_TEAMS ];

}TEAMGOALSINFO;

typedef struct _SHOCKWAVEINFO
{
    uint16      Owner;
    uint16      Group;
    VECTOR      Pos;
    BYTE        Weapon;
    float       ShockwaveSize;
}SHOCKWAVEINFO;

typedef struct _BGOUPDATEINFO
{
    uint16      BGObject;
    int16       State;
    float       Time;
}BGOUPDATEINFO;

typedef struct _PRIMBULLPOSDIR
{
    uint16      OwnerType;
    uint16      OwnerID;
    uint16      BulletID;
    int8        Weapon;
    uint16      Group;
    VECTOR      Pos;
    VECTOR      Offset;
    VECTOR      Dir;
    VECTOR      Up;
    int16       PowerLevel;
    float       PLevel;

}PRIMBULLPOSDIR;

typedef struct _SECBULLPOSDIR
{
    uint16      OwnerType;
    uint16      Owner;
    uint16      BulletID;
    uint16      Group;
    VECTOR      Pos;
    VECTOR      Offset;
    VECTOR      Dir;
    VECTOR      UpVector;
    VECTOR      DropDir;
    int8        Weapon;

}SECBULLPOSDIR;

typedef struct _TITANBITS
{
    uint16      OwnerType;
    uint16      Owner;
    uint16      BulletID;
    uint16      Group;
    VECTOR      Pos;
    VECTOR      Offset;
    VECTOR      UpVector;
    VECTOR      DropDir;
    VECTOR      Directions[ NUMTITANBITS ];
    int8        Weapon;

}TITANBITS;

typedef struct _SHIPHIT
{
    float       Damage;
    VECTOR      Recoil;
    VECTOR      Point;
    VECTOR      Dir;
    BYTE        WeaponType;
    BYTE        Weapon;
    float       Force;
    BOOL        OneOffExternalForce;

}SHIPHIT;


typedef struct _SHORTSHIPHIT
{
    float       Damage;
    float       Force;
    SHORTVECTOR Recoil;
    SHORTVECTOR Point;
    SHORTVECTOR Dir;
    BYTE        WeaponType;
    BYTE        Weapon;
    uint16      OneOffExternalForce;
    uint16      Recoil_Scalar;
}SHORTSHIPHIT;



typedef struct _SETTIME
{
    float       Time;

}SETTIME;

typedef struct _GLOBALSHIP
{
    OBJECT              Object;     //
    
    BYTE                enable;     // is this ship active?
    BYTE                ShipThatLastKilledMe;       // the ship who killed me last...
    BYTE                ShipThatLastHitMe;      // the ship who killed me last...
    BYTE                NumMultiples;   // Number of multiples
    float               StealthTime; // Stealth Mode Time Limit
    float               Timer;      // General Purpose Mode Timer....How Long to stay dead ...etc..
    float               InvulTimer; // HowLong am I Invulnerable
    BOOL                Invul;      // Am I Invulnerable...
    VECTOR              LastAngle;  // what my last Step Turn Angles Were...
    int16               Kills;      // number of kills
    int16               Deaths;     // number of deaths
    uint16              PrimBullIdCount;// Id count for every bullet I fire....
    uint16              SecBullIdCount;// Id count for every bullet I fire....
    uint16              PickupIdCount;// Id count for every pickup I generate.....
    float               Damage;     // how much Damege I Have Taken...
    BYTE                Primary;    // which weapon is my primary....
    BYTE                Secondary;  // which wepaon is my secondary....
    uint16              ModelNum;   // which model to display for them...
    int16               BikeNum;    // which model to display for them...
    BYTE                Pickups;
    BYTE                RegenSlots;
    BYTE                Triggers;
    BYTE                TrigVars;
    BYTE                Mines;
    BOOL                JustRecievedPacket;//
    VECTOR              LastMove;   // last movement vector (framelagged)
    VECTOR              Move_Off;   // Last MoveMent...x , y , z
    DPID                dcoID;
    uint16              OrbModels[ MAXMULTIPLES ];  // Orbit Pulsar Model
    float               OrbAmmo[ MAXMULTIPLES ];    // Orbit Pulsar Ammo
    int8                LastPacketID;
    BOOL                FirstPacketRecieved;

    float               PrimPowerLevel; // Trojax Powerlevel
    uint16              PrimID;     // Bullet ID
    uint16              SecID;      // Missile ID
    BYTE                SecWeapon;  // Weapon


    BOOL                DemoInterpolate;

    VECTOR      OldPos;             //
    VECTOR      NextPos;            // what my next position will be
    QUAT        OldQuat;            //
    QUAT        NextQuat;           // what my next view angle will be
    float       OldBank;            //
    float       NextBank;           // what my next bank angle will be..
    LONGLONG    OldTime;            // how long before I am at those positions
    LONGLONG    NextTime;           // how long before I am at those positions

    float       SuperNashramTimer;  // HowLong have i left with the super nashram?
    uint16      TempLines[ 12 ];

    float       ShakeTimer;
    float       ShakeDirTimer;
    float       ShakeForce;

    float       PacketDelay;

    uint8       ShieldHullCount;

    VECTOR      RealPos;
    uint16      RealGroup;

} GLOBALSHIP, *LPGLOBALSHIP;



/*      this is all that really needs to be sent    */
typedef struct _SHORTGLOBALSHIP
{
    uint32              Flags;          // Flags Enable/Stealth/Turbo/PrimFire/SecFire/PrimToggle/SecToggle
    BYTE                Status;         // tells us constantly what this ship is doing...
    BYTE                GroupImIn;      // Group Im In

    VECTOR              Pos;            // x , y , z position
    VECTOR              Move_Off;       // Last MoveMent...x , y , z
    VECTOR              Angle;          // Last Rotation..
#ifdef  SHORTBANK
    int16               Bank;       // How much Am I banked....
#else
    float               Bank;       // How much Am I banked....
#endif
    QUAT                Quat;       // Final Quat...
//  int8                LastPacketID;   // should go in order.....
} SHORTGLOBALSHIP, *LPSHORTGLOBALSHIP;

typedef struct _VERYSHORTGLOBALSHIP
{
    uint32              Flags;          // Flags Enable/Stealth/Turbo/PrimFire/SecFire/PrimToggle/SecToggle
    BYTE                Status;         // tells us constantly what this ship is doing...
    BYTE                GroupImIn;      // Group Im In
    SHORTVECTOR         Pos;            // x , y , z position
    SHORTVECTOR         Move_Off;       // Last MoveMent...x , y , z
    SHORTVECTOR         Angle;          // Last Rotation..
    int16               Bank;       // How much Am I banked....
    uint16              Move_Off_Scalar;
    SHORTQUAT           Quat;       // Final Quat...
} VERYSHORTGLOBALSHIP, *LPVERYSHORTGLOBALSHIP;


typedef struct _FSHORTGLOBALSHIP
{
    uint32              Flags;          // Flags Enable/Stealth/Turbo/PrimFire/SecFire/PrimToggle/SecToggle
    BYTE                Primary;        // Primary weapon
    BYTE                Secondary;      // Secondary weapon
    BYTE                GroupImIn;      // Group Im In
    BYTE                PrimPowerLevel; // Trojax Powerlevel
    VECTOR              Pos;            // x , y , z position
    VECTOR              Move_Off;       // Last MoveMent...x , y , z
    VECTOR              Angle;          // Last Rotation..
#ifdef  SHORTBANK
    int16               Bank;       // How much Am I banked....
#else
    float               Bank;       // How much Am I banked....
#endif
    QUAT                Quat;       // Final Quat...
} FSHORTGLOBALSHIP, *LPFSHORTGLOBALSHIP;

typedef struct _FVERYSHORTGLOBALSHIP
{
    uint32              Flags;          // Flags Enable/Stealth/Turbo/PrimFire/SecFire/PrimToggle/SecToggle
    BYTE                Primary;        // Primary weapon
    BYTE                Secondary;      // Secondary weapon
    BYTE                GroupImIn;      // Group Im In
    BYTE                PrimPowerLevel; // Trojax Powerlevel
    SHORTVECTOR         Pos;            // x , y , z position
    SHORTVECTOR         Move_Off;       // Last MoveMent...x , y , z
    SHORTVECTOR         Angle;          // Last Rotation..
    int16               Bank;       // How much Am I banked....
    uint16              Move_Off_Scalar;
    SHORTQUAT           Quat;       // Final Quat...
} FVERYSHORTGLOBALSHIP, *LPFVERYSHORTGLOBALSHIP;

typedef struct _GROUPONLY_FVERYSHORTGLOBALSHIP
{
    uint32              Flags;          // Flags Enable/Stealth/Turbo/PrimFire/SecFire/PrimToggle/SecToggle
    BYTE                Primary;        // Primary weapon
    BYTE                Secondary;      // Secondary weapon
    BYTE                GroupImIn;      // Group Im In
    BYTE                PrimPowerLevel; // Trojax Powerlevel
    SHORTVECTOR         Pos;            // x , y , z position
    SHORTQUAT           Quat;       // Final Quat...
    int16               Bank;       // How much Am I banked....
} GROUPONLY_FVERYSHORTGLOBALSHIP, *LPGROUPONLY_FVERYSHORTGLOBALSHIP;


//----------------------------------------------------------
// Mask Defines for .Flags uint32
//----------------------------------------------------------

#define SHIP_Light_Bit          30
#define SHIP_CarryingFlag4_Bit  29
#define SHIP_CarryingFlag3_Bit  28
#define SHIP_CarryingFlag2_Bit  27
#define SHIP_CarryingFlag1_Bit  26
#define SHIP_CarryingFlag_Bit   26
#define SHIP_CarryingBounty_Bit 26
#define SHIP_Shield_Bit         25
#define SHIP_Scattered_Bit      24
#define SHIP_Litup_Bit          23
#define SHIP_InWater_Bit        22
#define SHIP_SuperNashram_Bit   21
#define SHIP_Invul_Bit          20
#define SHIP_MulFire_Bit        19
#define SHIP_Charging_Bit       18
#define SHIP_Turbo_Bit          17
#define SHIP_Stealth_Bit        16
#define SHIP_PrimFire_Bit       15
#define SHIP_PrimToggle_Bit     14
#define SHIP_SecFire_Bit        13
#define SHIP_SecToggle_Bit      12
#define SHIP_IsHost_Bit         11
#define SHIP_Enable_Bit         10
#define SHIP_Hull_Bit2          9
#define SHIP_Hull_Bit1          8
#define SHIP_Mode_Bit2          7
#define SHIP_Mode_Bit1          6
#define SHIP_PowerLevel_Bit2    5
#define SHIP_PowerLevel_Bit1    4
#define SHIP_NumMultiples_Bit4  3
#define SHIP_NumMultiples_Bit3  2
#define SHIP_NumMultiples_Bit2  1
#define SHIP_NumMultiples_Bit1  0

#define SHIP_Light          ( 1 << SHIP_Light_Bit )
#define SHIP_CarryingFlag4  ( 1 << SHIP_CarryingFlag4_Bit )
#define SHIP_CarryingFlag3  ( 1 << SHIP_CarryingFlag3_Bit )
#define SHIP_CarryingFlag2  ( 1 << SHIP_CarryingFlag2_Bit )
#define SHIP_CarryingFlag1  ( 1 << SHIP_CarryingFlag1_Bit )
#define SHIP_CarryingFlag   ( 1 << SHIP_CarryingFlag_Bit )
#define SHIP_CarryingFlags  ( SHIP_CarryingFlag1 \
                            | SHIP_CarryingFlag2 \
                            | SHIP_CarryingFlag3 \
                            | SHIP_CarryingFlag4 )
#define SHIP_NumMultiplesBit4   ( 1 << SHIP_NumMultiples_Bit4 )
#define SHIP_NumMultiplesBit3   ( 1 << SHIP_NumMultiples_Bit3 )
#define SHIP_NumMultiplesBit2   ( 1 << SHIP_NumMultiples_Bit2 )
#define SHIP_NumMultiplesBit1   ( 1 << SHIP_NumMultiples_Bit1 )
#define SHIP_Shield         ( 1 << SHIP_Shield_Bit )
#define SHIP_HullBit2       ( 1 << SHIP_Hull_Bit2 )
#define SHIP_HullBit1       ( 1 << SHIP_Hull_Bit1 )
#define SHIP_ModeBit2       ( 1 << SHIP_Mode_Bit2 )
#define SHIP_ModeBit1       ( 1 << SHIP_Mode_Bit1 )
#define SHIP_PowerLevelBit2 ( 1 << SHIP_PowerLevel_Bit2 )
#define SHIP_PowerLevelBit1 ( 1 << SHIP_PowerLevel_Bit1 )
#define SHIP_CarryingBounty ( 1 << SHIP_CarryingBounty_Bit )
#define SHIP_Scattered      ( 1 << SHIP_Scattered_Bit)
#define SHIP_Litup          ( 1 << SHIP_Litup_Bit )
#define SHIP_InWater        ( 1 << SHIP_InWater_Bit )
#define SHIP_SuperNashram   ( 1 << SHIP_SuperNashram_Bit )
#define SHIP_Invul          ( 1 << SHIP_Invul_Bit )
#define SHIP_MulFire        ( 1 << SHIP_MulFire_Bit )
#define SHIP_Multiple       ( ( 1 << SHIP_NumMultiples_Bit4 ) \
                            | ( 1 << SHIP_NumMultiples_Bit3 ) \
                            | ( 1 << SHIP_NumMultiples_Bit2 ) \
                            | ( 1 << SHIP_NumMultiples_Bit1 ) )
#define SHIP_Charging       ( 1 << SHIP_Charging_Bit )
#define SHIP_Turbo          ( 1 << SHIP_Turbo_Bit )
#define SHIP_Stealth        ( 1 << SHIP_Stealth_Bit )
#define SHIP_PrimFire       ( 1 << SHIP_PrimFire_Bit )
#define SHIP_PrimToggle     ( 1 << SHIP_PrimToggle_Bit )
#define SHIP_SecFire        ( 1 << SHIP_SecFire_Bit )
#define SHIP_SecToggle      ( 1 << SHIP_SecToggle_Bit )
#define SHIP_IsHost         ( 1 << SHIP_IsHost_Bit )
#define SHIP_Enable         ( 1 << SHIP_Enable_Bit )

//----------------------------------------------------------
// communication packet structures
//----------------------------------------------------------
#define MSG_UPDATE                  0x11
#define MSG_HEREIAM                 0x22
#define MSG_INIT                    0x33
#define MSG_SHIPHIT                 0x44
#define MSG_PRIMBULLPOSDIR          0x55
#define MSG_SECBULLPOSDIR           0x66
#define MSG_SHIPDIED                0x77
#define MSG_DROPPICKUP              0x88
#define MSG_KILLPICKUP              0x99
#define MSG_SHORTSTATS              0xaa
#define MSG_STATUS                  0xbb
#define MSG_EXPSECONDARY            0xcc
#define MSG_SHORTPICKUP             0xee
#define MSG_SHOCKWAVE               0xff
#define MSG_FUPDATE                 0x1f
#define MSG_SHORTMINE               0x2f
#define MSG_TEXTMSG                 0x3f
#define MSG_SHORTREGENSLOT          0x4f
#define MSG_SHORTTRIGGER            0x5f
#define MSG_SHORTTRIGVAR            0x6f
#define MSG_NAME                    0x7f
#define MSG_INTERPOLATE             0x8f
#define MSG_BOMB                    0x9f
#define MSG_BGOUPDATE               0xaf
#define MSG_PINGREQUEST             0xbf
#define MSG_PLAYERPINGS             0xbe
#define MSG_PINGREPLY               0xcf
#define MSG_LONGSTATUS              0xdf
#define MSG_SETTIME                 0xef
#define MSG_REQTIME                 0xf1
#define MSG_ACKMSG                  0xf2
#define MSG_GUARANTEEDMSG           0xf3
#define MSG_KILLSDEATHSBIKENUM      0xf4
#define MSG_VERYSHORTUPDATE         0xf5
#define MSG_VERYSHORTFUPDATE        0xf6
#define MSG_ALIVE                   0xf7        // short message to make sure people know im alive and still in the session....
#define MSG_VERYSHORTINTERPOLATE    0xf8
#define MSG_TEAMGOALS               0xf9
#define MSG_YOUQUIT                 0xfa
#define MSG_SENDKILLSDEATHSBIKENUM  0xfb
#define MSG_SHORTSHIPHIT            0xfc
#define MSG_TITANBITS               0xfd
#define MSG_BIGPACKET               0xfe
#define MSG_SERVERUPDATE            0xe1
#define MSG_GAMEPARAMETERS          0xe2        // pseudohost sends this to server to set game info
#ifdef MANUAL_SESSIONDESC_PROPAGATE
#define MSG_SESSIONDESC             0xe3        // message to maually propagate session desc
#endif
#define MSG_TOSERVER                0xe4        // client uses to send messages to server ( ie. start game, reset etc )
#define MSG_SERVERKILLPICKUP        0xe5
#define MSG_SERVERSAYSSHIPDIED      0xe6
#define MSG_LEVELNAMES              0xe7        // msg contining names of levels on server
#define MSG_EXPLODESHIP             0xe8
#define MSG_SHIELDHULL              0xe9
#define MSG_SERVERSCORED            0xea

#define MSG_TRACKERINFO             0xe0        // tracker info for if host migrates in peer-peer game
#define MSG_TOCLIENT                0xeb        // message to client ( server game )

#define MSG_GROUPONLY_VERYSHORTFUPDATE      0xec
#define MSG_VERYSHORTDROPPICKUP             0xed

typedef struct _SERVERSCOREDMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BYTE        WhoScored;
    BYTE        Score;
}SERVERSCOREDMSG, *LPSERVERSCOREDMSG;


typedef struct _SHIELDHULLMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BYTE        Shield;
    BYTE        Hull;
    BYTE        ValidChange;
    uint8       Count;
}SHIELDHULLMSG, *LPSHIELDHULLMSG;


typedef struct _ALIVEMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
}ALIVEMSG, *LPALIVEMSG;

typedef struct _SENDKILLSDEATHSBIKENUMMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
}SENDKILLSDEATHSBIKENUMMSG, *LPSENDKILLSDEATHSBIKENUMMSG;


typedef struct _YOUQUITMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BYTE        You;
}YOUQUITMSG, *LPYOUQUITMSG;



typedef struct GUARANTEEDMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    uint32      Ack;
    uint32      ID;
    BOOL        OverideOlderMessage;
    BOOL        AllPlayers;
    BYTE        Count;
    BYTE        StartOfMessage;
}GUARANTEEDMSG, *LPGUARANTEEDMSG;

typedef struct _ACKMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    uint32      ID;
    BYTE        AckTo;
}ACKMSG, *LPACKMSG;

typedef struct _KILLSDEATHSBIKENUMMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    int16       Kills;
    int16       Deaths;
    BYTE        BikeNum;        // which model to display for them...
}KILLSDEATHSBIKENUMMSG, *LPKILLSDEATHSBIKENUMMSG;

typedef struct _PINGMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BYTE        ToYou;      // 0 non-guarenteed...1 guarenteed..
    BYTE        Pad;
    LONGLONG    Time;
}PINGMSG, *LPPINGMSG;

typedef struct _PLAYERPINGSMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    uint16      Ping[ MAX_PLAYERS ];
}PLAYERPINGSMSG, *LPPLAYERPINGSMSG;

typedef struct _BOMBMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BYTE        WhoGotHit;
    BYTE        BombNum;
    float       BombTime;
} BOMBMSG, *LPBOMBMSG;


typedef struct _SHORTPICKUPMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BYTE        HowManyPickups;
    BYTE        Pickups;
    struct SHORTPICKUP  ShortPickup[MAXGENPICKUPCOUNT];
} SHORTPICKUPMSG, *LPSHORTPICKUPMSG;

typedef struct _SHORTREGENSLOTMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BYTE        HowManyRegenSlots;
    BYTE        RegenSlots;
    struct SHORTREGENSLOT  ShortRegenSlot[MAXGENREGENSLOTCOUNT];
} SHORTREGENSLOTMSG, *LPSHORTREGENSLOTMSG;

typedef struct _SHORTTRIGGERMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BYTE        HowManyTriggers;
    BYTE        Triggers;
    struct SHORTTRIGGER  ShortTrigger[MAXGENTRIGGERCOUNT];
} SHORTTRIGGERMSG, *LPSHORTTRIGGERMSG;

typedef struct _SHORTTRIGVARMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BYTE        HowManyTrigVars;
    BYTE        TrigVars;
    struct SHORTTRIGVAR  ShortTrigVar[MAXGENTRIGVARCOUNT];
} SHORTTRIGVARMSG, *LPSHORTTRIGVARMSG;

typedef struct _SHORTMINEMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BYTE        HowManyMines;
    BYTE        Mines;
    struct SHORTMINE  ShortMine[MAXGENMINECOUNT];
} SHORTMINEMSG, *LPSHORTMINEMSG;

typedef struct _UPDATEMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    SHORTGLOBALSHIP  ShortGlobalShip;
} UPDATEMSG, *LPUPDATEMSG;

typedef struct _VERYSHORTUPDATEMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    VERYSHORTGLOBALSHIP  ShortGlobalShip;
} VERYSHORTUPDATEMSG, *LPVERYSHORTUPDATEMSG;

typedef struct _FUPDATEMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    FSHORTGLOBALSHIP  ShortGlobalShip;
} FUPDATEMSG, *LPFUPDATEMSG;

typedef struct _VERYSHORTFUPDATEMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    FVERYSHORTGLOBALSHIP  ShortGlobalShip;
} VERYSHORTFUPDATEMSG, *LPVERYSHORTFUPDATEMSG;

typedef struct _GROUPONLY_VERYSHORTFUPDATEMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    GROUPONLY_FVERYSHORTGLOBALSHIP  ShortGlobalShip;
} GROUPONLY_VERYSHORTFUPDATEMSG, *LPGROUPONLY_VERYSHORTFUPDATEMSG;


typedef struct _HEREIAMMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BYTE        Old_WhoIAm;
    BYTE        Old_TeamNumber;
    DPID        ID;
    BOOL        Rejoining;
} HEREIAMMSG, *LPHEREIAMMSG;

typedef struct _INITMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BYTE        YouAre;
    BYTE        Status;
    BOOL        PlayerReady[MAX_PLAYERS];
    BYTE        TeamNumber[MAX_PLAYERS];
    //int16     MaxKills;
    float       PacketsPerSecond;
    char        LevelName[32];
    //BOOL      HarmTeamMates;
    //BOOL      BrightShips;
    //BOOL      BikeExhausts;
    //int32     Collisions;
    uint32      PickupFlags[ MAX_PICKUPFLAGS ];
    int16       GoalScore;
    //int16     CTF_Type;
    int16       BountyBonusInterval;
    BOOL        RandomPickups;
    uint16      Seed1;
    uint16      Seed2;
    DWORD       dwUser3;    // user field 3 of session desc ( used for server state )
    BOOL        ServerCollisions;
    int16       PrimaryPickups;
    DPID        FromDpid;
    BYTE        GameStatus[MAX_PLAYERS];
} INITMSG, *LPINITMSG;

typedef struct _SHIPHITMSG
{
    BYTE        MsgCode;
    BYTE        WhoHitYou;
    BYTE        You;
    SHIPHIT     ShipHit;
    int16       Deaths;         // number of deaths
} SHIPHITMSG, *LPSHIPHITMSG;

typedef struct _SHORTSHIPHITMSG
{
    BYTE        MsgCode;
    BYTE        WhoHitYou;
    BYTE        You;
    SHORTSHIPHIT    ShipHit;
    int16       Deaths;         // number of deaths
} SHORTSHIPHITMSG, *LPSHORTSHIPHITMSG;


typedef struct _SHIPDIEDMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BYTE        WhoKilledMe;
    BYTE        Type;
    BYTE        WeaponType;
    BYTE        Weapon;
    VECTOR      Pos;
} SHIPDIEDMSG, *LPSHIPDIEDMSG;

typedef struct _SERVERSAYSSHIPDIEDMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BYTE        WhoWasKilled;
    BYTE        WhoKilledThem;
    BYTE        Type;
    BYTE        WeaponType;
    BYTE        Weapon;
    VECTOR      Pos;
    int16       Deaths;
}SERVERSAYSSHIPDIEDMSG, *LPSERVERSAYSSHIPDIEDMSG;

typedef struct _KILLPICKUPMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    KILLPICKUPINFO  KillPickupInfo;

} KILLPICKUPMSG, *LPKILLPICKUPMSG;

typedef struct _SERVERKILLPICKUPMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    SERVERKILLPICKUPINFO    ServerKillPickupInfo;

} SERVERKILLPICKUPMSG, *LPSERVERKILLPICKUPMSG;

typedef struct _EXPLODESHIPMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    EXPLODESHIPINFO ExplodeShipInfo;

} EXPLODESHIPMSG, *LPEXPLODESHIPMSG;

typedef struct _EXPSECONDARYMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    EXPSECONDARYINFO    ExplodeSecondaryInfo;

} EXPSECONDARYMSG, *LPEXPSECONDARYMSG;

typedef struct _TEAMGOALSMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    TEAMGOALSINFO   TeamGoalsInfo;

} TEAMGOALSMSG, *LPTEAMGOALSMSG;

typedef struct _SHOCKWAVEMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    SHOCKWAVEINFO   ShockwaveInfo;

} SHOCKWAVEMSG, *LPSHOCKWAVEMSG;

typedef struct _BGOUPDATEMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BGOUPDATEINFO   BGOUpdateInfo;

} BGOUPDATEMSG, *LPBGOUPDATEMSG;

typedef struct _DROPPICKUPMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    PICKUPINFO  PickupInfo;

} DROPPICKUPMSG, *LPDROPPICKUPMSG;

typedef struct _VERYSHORTDROPPICKUPMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    VERYSHORTPICKUPINFO PickupInfo;

} VERYSHORTDROPPICKUPMSG, *LPVERYSHORTDROPPICKUPMSG;


typedef struct _PRIMBULLPOSDIRMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    PRIMBULLPOSDIR  PrimBullPosDir;
} PRIMBULLPOSDIRMSG, *LPPRIMBULLPOSDIRMSG;

typedef struct _SECBULLPOSDIRMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    SECBULLPOSDIR   SecBullPosDir;
} SECBULLPOSDIRMSG, *LPSECBULLPOSDIRMSG;

typedef struct _TITANBITSMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    TITANBITS   TitanBits;
} TITANBITSMSG, *LPTITANBITSMSG;

typedef int16       SHORTSTATSTYPE[MAX_PLAYERS];

typedef struct _SHORTSTATSMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BYTE        WhosStats;
    SHORTSTATSTYPE      ShortStats;
} SHORTSTATSMSG, *LPSHORTSTATSMSG;

typedef struct _STATUSMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BOOL        IsHost;         // from host ???
    BYTE        Status;
    BYTE        TeamNumber;
    uint16      TeamScore;      // if leaving game, used to propagate my score to another team member
    BOOL        IAmReady;       // used for team game - game cannot start until everyone is ready
    BYTE        Pickups;        // tells how much of the pickup list I have recieved..
    BYTE        RegenSlots;     // tells how much of the pickup regen slots list I have recieved..
    BYTE        Mines;          // tells how much of the mine list I have recieved..
    BYTE        Triggers;       // tells how much of the mine list I have recieved..
    BYTE        TrigVars;       // tells how much of the mine list I have recieved..
    float       PacketsPerSecond;
    LONGLONG    LevelCheckSum;
} STATUSMSG, *LPSTATUSMSG;

typedef struct _LONGSTATUSMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    STATUSMSG   Status;
    char        LevelName[32];
    uint16      RandomStartPosModify;
} LONGSTATUSMSG, *LPLONGSTATUSMSG;

enum{
    TEXTMSGTYPE_Taunt1,
    TEXTMSGTYPE_Taunt2,
    TEXTMSGTYPE_Taunt3,
    TEXTMSGTYPE_TitleMessage,
    TEXTMSGTYPE_JoiningTeamGame,
    TEXTMSGTYPE_QuickTaunt,
    TEXTMSGTYPE_CaptureFlagMessage,
    TEXTMSGTYPE_ScoredWithFlag,
    TEXTMSGTYPE_ReturningFlag,
    TEXTMSGTYPE_ReturnedFlag,
    TEXTMSGTYPE_FlagDriftedIn,
    TEXTMSGTYPE_FlagEscaped,
    TEXTMSGTYPE_BountyMessage,
    TEXTMSGTYPE_QuickTauntWhisper,
    TEXTMSGTYPE_SpeechTaunt,
};

typedef struct _TEXTMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    char        Text[MAXTEXTMSG];
    BYTE        TextMsgType;
} TEXTMSG, *LPTEXTMSG;

typedef struct _NAMEMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    char        Name[8];
} NAMEMSG, *LPNAMEMSG;

typedef struct _INTERPOLATEMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    VECTOR      NextPos;            // what my next position will be
    QUAT        NextQuat;           // what my next view angle will be
    float       NextBank;           // what my next bank angle will be..
    LONGLONG    NextTime;           // how long before I am at thos positions
} INTERPOLATEMSG, *LPINTERPOLATEMSG;

typedef struct _VERYSHORTINTERPOLATEMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    SHORTVECTOR NextPos;            // what my next position will be
    SHORTQUAT   NextQuat;           // what my next view angle will be
    int16       NextBank;           // what my next bank angle will be..
    LONGLONG    NextTime;           // how long before I am at thos positions
} VERYSHORTINTERPOLATEMSG, *LPVERYSHORTINTERPOLATEMSG;


typedef struct _SETTIMEMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    SETTIME     TimeInfo;

} SETTIMEMSG, *LPSETTIMEMSG;


typedef struct _REQTIMEMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;

} REQTIMEMSG, *LPREQTIMEMSG;


typedef struct _SERVERUPDATEMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    DWORD       Players;
    BYTE        Group[MAX_PLAYERS];
    BYTE        Status[MAX_PLAYERS];
}SERVERUPDATEMSG, *LPSERVERUPDATEMSG;


#define GAMEPARAM_GameTypeBits              0x7     // bits 0-2
#define GAMEPARAM_GameTypeBitShift          0x0
#define GAMEPARAM_CTFTypeBits               0x78    // bits 3-6
#define GAMEPARAM_CTFTypeBitShift           0x3
#define GAMEPARAM_BikeExhaustBit            0x80    // bit 7
#define GAMEPARAM_BrightBikesBit            0x100   // bit 8
#define GAMEPARAM_RandomisePickupsBit       0x200   // bit 9
#define GAMEPARAM_BountyBonusBit            0x400   // bit 10
#define GAMEPARAM_BountyBonusValueBits      0x3800  // bits 11 - 13 ( 5 second units )
#define GAMEPARAM_BountyBonusValueBitShift  0xb
#define GAMEPARAM_HarmTeamMatesBit          0x4000  // bit 14
#define GAMEPARAM_FlagCaptureScoreBits      0x78000 // bits 15 - 18
#define GAMEPARAM_FlagCaptureScoreBitShift  0xf
#define GAMEPARAM_ServerCollisionBit        0x80000 // bit 19
#define GAMEPARAM_ResetKillsPerLevelBit     0x100000 // bit 20 
#define GAMEPARAM_LagCompensationBits       0x600000 // bit 21 & 22
#define GAMEPARAM_LagCompensationBitShift   0x15 

typedef struct _GAMEPARAMETERSMSG
{
    BYTE                MsgCode;
    BYTE                WhoIAm;
    uint8               Level[ 8 ];     // level ( limited to 8 chars )
    uint8               ScoreLimit;         // score limit ( in units of 5 ) 
    uint8               TimeLimit;          // time limit ( 5 minute units )
    uint32              GameInfo;       // see above
    uint32              AllowedPickups[ MAX_PICKUPFLAGS ]; // allowed pickups
    int16               PrimaryPickups;
    uint16              MaxPlayers;
} GAMEPARAMETERSMSG, *LPGAMEPARAMETERSMSG;

#ifdef MANUAL_SESSIONDESC_PROPAGATE

typedef struct _SESSIONDESCMSG
{
    BYTE                MsgCode;
    BYTE                WhoIAm;
    DWORD               dwUser1;
    DWORD               dwUser2;
    DWORD               dwUser3;
    DWORD               dwUser4;
} SESSIONDESCMSG, *LPSESSIONDESCMSG;

#endif

#define TOSERVERMSG_StartGame 0
#define TOSERVERMSG_Reset 1
#define TOSERVERMSG_ChangeLevel 2
#define TOSERVERMSG_IAmPseudoHost 3

typedef struct _TOSERVERMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BYTE        Type;
    BYTE        Data;
}TOSERVERMSG, *LPTOSERVERMSG;

#define TOCLIENTMSG_YouArePseudoHost 0

typedef struct _TOCLIENTMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BYTE        Type;
    BYTE        Data;
}TOCLIENTMSG, *LPTOCLIENTMSG;


#define MAXLEVELSPERBATCH 8

typedef struct _LEVELNAMESMSG
{
    BYTE        MsgCode;
    BYTE        WhoIAm;
    BYTE        TotalLevels;
    BYTE        ThisBatch;
    BYTE        FirstLevel;
    char        Level[ MAXLEVELSPERBATCH ][ 8 ];    // only first 8 chars of leve names are used
}LEVELNAMESMSG, *LPLEVELNAMESMSG;

typedef struct _TRACKERINFOMSG
{
    BYTE    MsgCode;
    BYTE    WhoIAm;
    uint32  addr;
    u_short port;
    DWORD   freq;
    int     type;
    BOOL    shutdown;
    BOOL    gamespy;
}TRACKERINFOMSG, *LPTRACKERINFOMSG;

// globals needed in other modules
extern BOOL IsPseudoHost;
extern int GuaranteedMessagesActive;
extern GUID autojoin_session_guid;
extern float FindSessionTimeout;
extern BOOL ServerChoosesGameType;

#define SERVERLEVELS_Waiting    0
#define SERVERLEVELS_None       1
#define SERVERLEVELS_Got        2

/*
 * fn prototypes
 */
void    DestroyGame( void );
void    SendGameMessage( BYTE msg, DWORD to, BYTE row, BYTE col, BYTE mask );
void    EvaluateMessage( DWORD len , BYTE * MsgPnt );
void    ReceiveGameMessages( void );
void    initShip( uint16 i );
void    DplayGameUpdate();
void    SetupDplayGame();
void    PrimBullPosDirSend( uint16 OwnerType, uint16 OwnerID, uint16 BulletID, int8 Weapon,
                        uint16 Group, VECTOR * Pos, VECTOR * Offset, VECTOR * Dir, VECTOR * Up,
                        int16 PowerLevel, float PLevel );
void SecBullPosDirSend( uint16 OwnerType, uint16 Owner, uint16 BulletID, uint16 Group,
                        VECTOR * Pos, VECTOR * Offset, VECTOR * Dir, VECTOR * UpVector,
                        VECTOR * DropDir, int8 Weapon );
void TitanBitsSend( uint16 OwnerType, uint16 Owner, uint16 BulletID, uint16 Group,
                        VECTOR * Pos, VECTOR * Offset, VECTOR * UpVector,
                        VECTOR * DropDir, int8 Weapon, VECTOR * Directions );
void    DropPickupSend( VECTOR * Pos, uint16 Group, VECTOR * Dir, float Speed, int16 Type, uint16 IDCount, int16 RegenSlot, BOOL Sparkle, float LifeCount, uint16 TriggerMod);
void    KillPickupSend( uint16 Owner, uint16 IDCount, int16 Style );
void    ServerKillPickupSend( uint16 Owner, uint16 IDCount, int16 Style, uint16 NewOwner );
void    ExplodeShip( uint16 Ship );
void    ExplodeSecondarySend( VECTOR * Pos, uint16 Group, uint16 OwnerType, uint16 Owner, uint16 IDCount, float ShockwaveSize );
void    CreateShockwaveSend( uint16 OwnerType, uint16 Owner, VECTOR * Pos, uint16 Group, float ShockwaveSize, BYTE Weapon );
void    IHitYou( BYTE you, float Damage, VECTOR * Recoil, VECTOR * Point, VECTOR * Dir, float Force, BYTE WeaponType, BYTE Weapon, BOOL FramelagRecoil );
void    EvalSysMessage( DWORD len , BYTE * MsgPnt );
void    ShipDiedSend( BYTE WeaponType, BYTE Weapon );
void    UpdateBGObjectSend( uint16 BGObject, int16 State, float Time );

void    smallinitShip( uint16 i );
void DemoPlayingDplayGameUpdate(void);
void DemoClean( void );
void PingGuarenteed(void);
void PingNonGuarenteed(void);
int FindSameLevel( char * Name );
void    RequestTime( void  );
void    SetTime( float Time );
void Demo_fwrite( const void *buffer, size_t size, size_t count , FILE *stream );
void StopDemoRecording( void );

BOOL AddGuaranteedMessage( int MessageLength , void * Message , BYTE MsgType, BOOL OverideOlderMessage, BOOL AllPlayers );
void ProcessGuaranteedMessages( BOOL ReleaseMessages , BOOL IgnoreTime , BOOL SendGuaranteed );
void AcknowledgeMessage( uint32 ID , uint32 Player , BYTE PlayerNum );


void InitAcknowledgeMessageQue( void );
void FreeAllPlayersAcknowledgeMessageQue( BYTE Player );
void ProcessAcknowledgeMessageQue( void );
BOOL CompareAcknowledgeMessageQue( BYTE Player , uint32 ID);
BOOL AddAcknowledgeMessageQue( BYTE Player , uint32 ID );

void SendBigPacket( BOOL SendGuaranteed );
void ServiceBigPacket( BOOL OverideTime );
void AddToBigPacket( int MessageLength , void * Message , BYTE MsgType );


BOOL AddMessageToSeverQue( void * Message );
void ServiceServer( BOOL OverideTime );
void InitServerMessageQue( void );
void FreeServerMessageQue( void );

void ServerIHitYou( BYTE Owner , BYTE you, float Damage, VECTOR * Recoil, VECTOR * Point, VECTOR * Dir, float Force, BYTE WeaponType, BYTE Weapon, BOOL FramelagRecoil );
BOOL UpdateAmmoAndValidateMessage( void * Message );
BOOL CheckPlayersActive( void );
BOOL AutoJoinSession( void );
void AllocatePseudoHost( void );

#endif



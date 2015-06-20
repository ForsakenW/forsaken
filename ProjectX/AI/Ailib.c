/*
 * a i l i b . c
 *
 * AI Library (common) Routines
 *
 * Copyright (c) 1997 Probe Entertainment Limited
 * All Rights Reserved
 *
 * $Revision: 35 $
 *
 * $Header: /PcProjectX/Ai/Ailib.c 35    3/05/98 9:29a Phillipd $
 *
 * $Log: /PcProjectX/Ai/Ailib.c $
 * 
 * 35    3/05/98 9:29a Phillipd
 * added the OPT_ON stuff to all AI files....
 * 
 * 34    21/02/98 14:29 Collinsd
 * Added dan's new enemy code and fixed flashing of team in capture the
 * flag.
 * 
 * 33    1/22/98 12:06p Phillipd
 * 
 * 32    1/06/98 10:01a Phillipd
 * 
 * 31    1/03/98 1:35p Phillipd
 * 
 * 30    1/03/98 1:00p Phillipd
 * 
 * 29    12/04/97 4:55p Phillipd
 * 
 * 28    11/27/97 10:39a Phillipd
 * 
 * 27    11/20/97 11:44a Phillipd
 * 
 * 26    11/19/97 6:50p Phillipd
 * Clean up
 * 
 * 25    11/17/97 10:13a Phillipd
 * Trig area V2...
 * 
 * 24    11/12/97 5:00p Phillipd
 * 
 * 23    11/10/97 7:28p Phillipd
 * 
 * 22    10/24/97 5:05p Phillipd
 * Enemies version 2....
 * 
 * 21    10/21/97 5:07p Phillipd
 * 
 * 20    9/16/97 2:19p Phillipd
 * 
 * 19    9/12/97 11:12a Phillipd
 * 
 * 18    9/10/97 9:54a Phillipd
 * 
 * 17    9/01/97 12:17p Phillipd
 * 
 * 16    8/31/97 1:05p Phillipd
 * 
 * 15    8/22/97 10:16a Phillipd
 * 
 * 14    8/19/97 12:59p Phillipd
 * 
 * 13    8/19/97 12:01p Phillipd
 * 
 * 12    8/17/97 1:17p Phillipd
 * Enemies coming along....
 * 
 * 11    8/15/97 4:24p Phillipd
 * enemies coming along
 * 
 * 10    7/31/97 9:09a Phillipd
 * 
 * 9     17/07/97 15:38 Collinsd
 * BGObjects now use compobjs.
 * 
 * 8     7/12/97 3:34p Phillipd
 * 
 * 7     7/10/97 2:26p Phillipd
 * 
 * 6     7/09/97 9:23a Phillipd
 * 
 * 5     8/07/97 16:30 Collinsd
 * Dicked about with include files FUCK!
 * 
 * 4     8/07/97 14:06 Collinsd
 * Added componented objects to enemies.
 * 
 * 3     7/07/97 2:12p Phillipd
 * More Ai...Gun Stuff
 * 
 * 2     7/03/97 10:11a Phillipd
 * More Ai and node
 * 
 * 1     6/30/97 10:34a Phillipd
 * 
 * 1     6/30/97 10:33a Phillipd
 * 
 * 1     6/30/97 10:32a Phillipd
 * 
 * 1     6/30/97 10:29a Phillipd
 *
 */
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <dplay.h>
#include "typedefs.h"
#include "main.h"
#include "new3d.h"
#include "quat.h"
#include "mload.h"
#include "Node.h"
#include "CompObjects.h"
#include "bgobjects.h"
#include "Object.h"
#include "mydplay.h"
#include "ships.h"
#include "2dpolys.h"
#include "lights.h"
#include "models.h"
#include "text.h"
#include "primary.h"
#include "secondary.h"
#include "triggers.h"
#include "sphere.h"
#include "pickups.h"
#include "enemies.h"
#include "controls.h"
#include "AI.h"
#include "lines.h"

#ifdef OPT_ON
#pragma optimize( "gty", on )
#endif

//--------------------------------------------------------------------------
// Externals
//--------------------------------------------------------------------------

extern  float framelag;
extern  VECTOR  Forward;
extern  VECTOR  SlideRight;
extern  VECTOR  SlideUp;
extern  MLOADHEADER     Mloadheader;
extern  MCLOADHEADER    MCloadheader;
extern  MCLOADHEADER    MCloadheadert0;
extern  LINE            Lines[ MAXLINES ];
extern  NODENETWORKHEADER   NodeNetworkHeader;
extern  SECONDARYWEAPONBULLET   SecBulls[MAXSECONDARYWEAPONBULLETS];
extern  uint16      FirstSecBullUsed;
BOOL WouldObjectCollide( OBJECT *Obj, VECTOR *Move_Off, float radius, BGOBJECT **BGObject );

//--------------------------------------------------------------------------
// Global Data
//--------------------------------------------------------------------------

TARGETDATA          TargetInfo;

TARGETDATA *        Tinfo = & TargetInfo;   


AIMDATA         AimData;
/*-------------------------------------------------------------------
    Procedure   :   Find Closest Mine
    Input       :   void
    Output      :   void
-------------------------------------------------------------------*/
void AI_GetNearestMINETarget( void )
{
    uint16  i;
    float   dist;

    i = FirstSecBullUsed;
    while( i != (uint16) -1 )
    {
        if( SecBulls[ i ].SecType == SEC_MINE )
        {
            // can there groups see each other???
            if( !SoundInfo[ SecBulls[i].GroupImIn ][ Tinfo->Group ] )
            {
                // make sure its a Players mine
                if( SecBulls[i].OwnerType == OWNER_SHIP  )
                {
                    dist = DistanceVector2Vector( &SecBulls[i].Pos , &Tinfo->Pos );
                    if( dist < Tinfo->Nearest )
                    {
                        Tinfo->TObject = (void*) &SecBulls[i];
                        Tinfo->TFlags = _TARGET_MINES;
                        Tinfo->Nearest = dist;         
                    }
                }
            }
        }
        i = SecBulls[ i ].Prev;                                         /* Next SecBull */
    }                                                                               
}
/*-------------------------------------------------------------------
    Procedure   :   Find Nearest Ship in any group...
    Input       :   void
    Output      :   void
-------------------------------------------------------------------*/
void AI_GetNearestSHIPTargetInAnyGROUP( void )
{
#ifdef COOPERATIVE
    float   dist;
    int i;
    for( i = 0 ; i < MAX_PLAYERS ; i++ )
    {
        if( Ships[i].enable && (Ships[i].Object.Mode == NORMAL_MODE) && ( &Ships[i].Object != Tinfo->SObject ) && ( !(Ships[i].Object.Flags & SHIP_Stealth) || (Ships[i].Object.Flags & SHIP_Litup) ) )
        {
            if( !SoundInfo[Tinfo->Group][Ships[i].Object.Group] )
            {
                dist = DistanceVector2Vector( &Ships[i].Object.Pos , &Tinfo->Pos );
                if( Ships[i].Object.Noise != 0.0F )
                {
                    dist *= ( 1.0F * ( 0.2F * Ships[i].Object.Noise ) );
                }
                
                if( dist < Tinfo->Nearest )
                {
                    Tinfo->TObject = (void*) &Ships[i];
                    Tinfo->Nearest = dist;         
                }
            }
        }
    }
#else
    if( Ships[WhoIAm].enable && (Ships[WhoIAm].Object.Mode == NORMAL_MODE) && ( !(Ships[WhoIAm].Object.Flags & SHIP_Stealth) || (Ships[WhoIAm].Object.Flags & SHIP_Litup) ) )
    {
        Tinfo->TObject = (void*) &Ships[WhoIAm];
        Tinfo->Nearest = DistanceVector2Vector( &Ships[WhoIAm].Object.Pos , &Tinfo->Pos);         
    }
#endif
}
/*-------------------------------------------------------------------
    Procedure   :   AI Look Ahead and try and predict where someone will be...
    Output      :   float amount , VECTOR * Pos, OBJECT * TargetObject , VECTOR * NewPos , float BulletSpeed
    Output      :   Nothing
-------------------------------------------------------------------*/
void AI_LookAhead( float Accuracy, VECTOR * SPos ,OBJECT * TObject , VECTOR * NewPos , float SpeedOfBullet )
{
    VECTOR  Move_Off;
    VECTOR  Move_Dir;
    float   Speed;
    float   Time;
    float   Distance;
    
    if( Accuracy == 0.0F )
    {
        NewPos->x = TObject->Pos.x;
        NewPos->y = TObject->Pos.y;
        NewPos->z = TObject->Pos.z;
        return;
    }
#if 1
    Speed = TObject->Speed.x;
    ApplyMatrix( &TObject->Mat, &SlideRight, &Move_Dir );           /* Calc Direction Vector */
    Move_Off.x = ( Move_Dir.x * Speed );
    Move_Off.y = ( Move_Dir.y * Speed );
    Move_Off.z = ( Move_Dir.z * Speed );
    Speed = TObject->Speed.y;
    ApplyMatrix( &TObject->Mat, &SlideUp, &Move_Dir );          /* Calc Direction Vector */
    Move_Off.x += ( Move_Dir.x * Speed );
    Move_Off.y += ( Move_Dir.y * Speed );
    Move_Off.z += ( Move_Dir.z * Speed );
    Speed = TObject->Speed.z;
    ApplyMatrix( &TObject->Mat, &Forward, &Move_Dir );          /* Calc Direction Vector */
    Move_Off.x += ( Move_Dir.x * Speed );
    Move_Off.y += ( Move_Dir.y * Speed );
    Move_Off.z += ( Move_Dir.z * Speed );
#else
    Move_Off.x = ( TObject->Move_Off.x );
    Move_Off.y = ( TObject->Move_Off.y );
    Move_Off.z = ( TObject->Move_Off.z );
#endif
    
    Distance = DistanceVector2Vector( &TObject->Pos , SPos  );
    Time = ( Distance / SpeedOfBullet );
    
    Time *= Accuracy;
    NewPos->x = TObject->Pos.x + ( Move_Off.x * Time );
    NewPos->y = TObject->Pos.y + ( Move_Off.y * Time );
    NewPos->z = TObject->Pos.z + ( Move_Off.z * Time );
}



/*-------------------------------------------------------------------
    Procedure   :   AI Find the best least hassle free Next Node...
    Input       :   OBJECT  *   Object 
    Output      :   Nothing
-------------------------------------------------------------------*/
void AI_GetNearestNODETarget( OBJECT * Object )
{
    float Angle;
    int i;
    float TempAngle;
    NODE * Node;
    NODE * NodeLink;
    BOOL    FoundOne = FALSE;

    if( !NodeNetworkHeader.State )
        return;
    if( !Object->NearestNode )
        return;
    Node = (NODE *) Object->NearestNode;

    for( i = 0 ; i < Node->NumOfLinks ; i ++ )
    {
        NodeLink = Node->NodeLink[i];
        if( NodeLink->NetMask & Object->NodeNetwork )
        {
            AI_AimAtTarget( &Object->InvMat , &Object->Pos, &NodeLink->Pos );
            
            TempAngle = (AimData.Angle.x*AimData.Angle.x) + (AimData.Angle.y*AimData.Angle.y);
            
            if( !FoundOne || ( (TempAngle < Angle) && ( Random_Range(2) || !(NodeLink->Flags&NODE_DECISION) ) ) )
            {
                FoundOne = TRUE;
                Angle = TempAngle;
                Tinfo->TObject = (void*) NodeLink;
                
            }
        }

    }
}
/*-------------------------------------------------------------------
    Procedure   :   AI Aim At a target...
    Input       :   MATRIX * InvMat Inv mat of the thing thats aiming..
                :   VECTOR * Spos   Position of the thing thats aiming...
                :   VECTOR * Tpos   Position of the thing thats being aimed at...
    Output      :   void ..But Fills in the AimData Struct....
-------------------------------------------------------------------*/
void AI_AimAtTarget( MATRIX * InvMat , VECTOR * SPos, VECTOR * TPos )
{
    VECTOR WantedDir;
    VECTOR TempDir;
    float Angle;

    AimData.Flags = 0;
    AimData.Angle.x = 0.0F;
    AimData.Angle.y = 0.0F;
    AimData.Angle.z = 0.0F;

    WantedDir.x = ( TPos->x - SPos->x );
    WantedDir.y = ( TPos->y - SPos->y );
    WantedDir.z = ( TPos->z - SPos->z );
    ApplyMatrix( InvMat, &WantedDir, &TempDir );            /* Calc Direction Vector */

    NormaliseVector( &TempDir );
    Angle = (float) acos( TempDir.x );
    Angle = 90.0F - R2D( Angle );
    if( TempDir.z < 0.0F )
        Angle = 180.0F - Angle;
    if( Angle > 180.0F )
    {
        Angle -= 360.0F;
    }
    AimData.Angle.y =  Angle;

//  if( Angle > 3.0F || ( TempDir.z < 0.0F ) )
    if( Angle > 3.0F )
    {
        AimData.Flags |= AI_CONTROL_TURNRIGHT;
    }
    if( Angle < -3.0F )
    {
        AimData.Flags |= AI_CONTROL_TURNLEFT;
    }
    
    Angle = (float) acos( TempDir.y );
    Angle = 90.0F - R2D( Angle );
    Angle *= -1.0F;
    if( Angle > 180.0F )
    {
        Angle -= 360.0F;
    }
    AimData.Angle.x = Angle;

    if( Angle < -3.0F && ( TempDir.z > 0.0F ))
    {
        AimData.Flags |= AI_CONTROL_TURNUP;
    }
    if( Angle > 3.0F && ( TempDir.z > 0.0F ))
    {
        AimData.Flags |= AI_CONTROL_TURNDOWN;
    }

}

/*-------------------------------------------------------------------
    Procedure   :   Is a Vector Pos in a ViewCone
    Input       :   VECTOR *    Pos
                :   MATRIX *    Mat
                :   VECTOR *    TargetPos
                :   float       View Cone Cosine
    Output      :   BOOL TRUE/FALSE
-------------------------------------------------------------------*/
BOOL AI_InViewCone( VECTOR * Pos, MATRIX * Mat , VECTOR * TPos, float ViewConeCos )
{
    float   Cos;
    VECTOR  NormVector;
    VECTOR  Dir;

    if( ViewConeCos == 1.0F )
        return TRUE;
    
    Dir.x = ( TPos->x - Pos->x );
    Dir.y = ( TPos->y - Pos->y );
    Dir.z = ( TPos->z - Pos->z );
    NormVector = Dir;
    NormaliseVector( &NormVector );
            
    ApplyMatrix( Mat, &Forward, &Dir );         /* Calc Direction Vector */

    Cos = DotProduct( &NormVector, &Dir );
    
    if( Cos > ViewConeCos )
    {
        return TRUE;
    }
    return FALSE;
}
/*-------------------------------------------------------------------
    Procedure   :   Is a VECTOR * Pos in Clear LOS
    Input       :   VECTOR * Pos
                :   uint16 Group
                :   VECTOR * TargetPos
    Output      :   BOOL TRUE/FALSE
-------------------------------------------------------------------*/
BOOL AI_ClearLOS( VECTOR * SPos, uint16 Group , VECTOR * Pos )
{
    VECTOR  Dir;
    VECTOR  Int_Point;
    uint16  Int_Group;
    NORMAL  Int_Normal;
    VECTOR  TempVector;

    Dir.x = ( Pos->x - SPos->x );
    Dir.y = ( Pos->y - SPos->y );
    Dir.z = ( Pos->z - SPos->z );
    
    if( BackgroundCollide( &MCloadheadert0, &Mloadheader, SPos, Group, &Dir,
                        &Int_Point, &Int_Group, &Int_Normal, &TempVector, TRUE, NULL ) )
    {
        return FALSE;
    }
    
    return TRUE;
}
/*-------------------------------------------------------------------
    Procedure   :   Is a VECTOR * Pos in Clear LOS And will the SPos
                :   Be able to get to the TargetPos
    Input       :   OBJECT * SObject
                :   VECTOR * TargetPos
                :   float radius
    Output      :   BOOL TRUE/FALSE
-------------------------------------------------------------------*/
BOOL AI_ClearLOSNonZero( OBJECT * SObject, VECTOR * Pos , float radius )
{
    VECTOR  Dir;
    BGOBJECT * BGObject;

    Dir.x = ( Pos->x - SObject->Pos.x );
    Dir.y = ( Pos->y - SObject->Pos.y );
    Dir.z = ( Pos->z - SObject->Pos.z );

    if( WouldObjectCollide( SObject, &Dir, radius, &BGObject ) )
    {
        return FALSE;
    }
    return TRUE;
}
/*-------------------------------------------------------------------
    Procedure   :   Is a VECTOR * Pos in Clear LOS And will the SPos
                :   Be able to get to the TargetPos
    Input       :   OBJECT * SObject
                :   VECTOR * TargetPos
                :   float radius
    Output      :   BOOL TRUE/FALSE
-------------------------------------------------------------------*/
BOOL AI_ClearLOSNonZeroNonObject( VECTOR * SPos, uint16 Group , VECTOR * Pos , float radius )
{
    VECTOR  Dir;
    VECTOR Impact_Point;
    uint16 Impact_Group;
    NORMAL Impact_Normal;

    Dir.x = ( Pos->x - SPos->x );
    Dir.y = ( Pos->y - SPos->y );
    Dir.z = ( Pos->z - SPos->z );
    return !QCollide( SPos , Group , &Dir, radius , &Impact_Point, &Impact_Group, &Impact_Normal );
}
/*-------------------------------------------------------------------
    Procedure   :   Find a Target...
    Input       :   ENEMY * Enemy
    Output      :   Nothing..But Tinfo struct is filled in...
-------------------------------------------------------------------*/
void AI_GetDistToNearestTarget( register ENEMY * Enemy )
{
    register uint16 group = Enemy->Object.Group;
    OBJECT * TObject;
       
    // Initialise
    Tinfo->Pos.x    = Enemy->Object.Pos.x;
    Tinfo->Pos.y    = Enemy->Object.Pos.y;
    Tinfo->Pos.z    = Enemy->Object.Pos.z;
    Tinfo->Group    = Enemy->Object.Group;
    Tinfo->Nearest = BIGDISTANCE;
    Tinfo->TFlags = 0;

    Tinfo->SObject  = &Enemy->Object;

    Tinfo->TObject  = NULL;

    // What type of target are we looking for ...
   
    if ( TARGET_PLAYERS )
    {
        AI_GetNearestSHIPTargetInAnyGROUP();
       
        if ( TObject = (OBJECT*) Tinfo->TObject )
        {
            Enemy->LastDistance = Tinfo->Nearest + SoundInfo[Enemy->Object.Group][TObject->Group];
            //See if target is within think range....
            if( Enemy->LastDistance <= EnemyTypes[Enemy->Type].Behave.ThinkRange )
            {
                Tinfo->TFlags = _TARGET_PLAYERS;
                return;
            }
        }
    }      
    if( TARGET_NODES )
    {
        AI_GetNearestNODETarget( &Enemy->Object );
        if ( Tinfo->TObject )
        {
            Tinfo->TFlags = _TARGET_NODES;
            return;
        }
    }       
    if( TARGET_MINES )
    {
        AI_GetNearestMINETarget();

        if ( Tinfo->TObject )
        {
            Tinfo->TFlags = _TARGET_MINES;
            return;
        }
    }
}
/*-------------------------------------------------------------------
    Procedure   :   Set Enemy AI Mode to...
    Input       :   ENEMY * Enemy
    Output      :   Nothing
-------------------------------------------------------------------*/
void AI_SetRETREAT( ENEMY * Enemy )
{
    Enemy->Object.AI_Mode = AIMODE_RETREAT;
    Enemy->TNode = NULL;
    Enemy->Timer = EnemyTypes[Enemy->Type].Behave.RetreatTime;  // How long I Run for
}
/*-------------------------------------------------------------------
    Procedure   :   Set Enemy AI Mode to...
    Input       :   ENEMY * Enemy
    Output      :   Nothing
-------------------------------------------------------------------*/
void AI_SetMOVETOTARGET( ENEMY * Enemy )
{
    Enemy->AIFlags &= ~AI_IHAVESEENPLAYER;
    Enemy->Object.AI_Mode = AIMODE_MOVETOTARGET;
    Enemy->TNode = NULL;
}
/*-------------------------------------------------------------------
    Procedure   :   Set Enemy AI Mode to...
    Input       :   ENEMY * Enemy
    Output      :   Nothing
-------------------------------------------------------------------*/
void AI_SetMOVEFOLLOWPATH( ENEMY * Enemy )
{
    Enemy->Object.AI_Mode = AIMODE_FOLLOWPATH;
    Enemy->Timer  = RESET_VALIDATE_TIME + (float) Random_Range( (uint16) RESET_VALIDATE_TIME );
}
/*-------------------------------------------------------------------
    Procedure   :   Set Enemy AI Mode to...
    Input       :   ENEMY * Enemy
    Output      :   Nothing
-------------------------------------------------------------------*/
void AI_SetDOGFIGHT( ENEMY * Enemy )
{
    Enemy->TNode = NULL;
    Enemy->Object.AI_Mode = AIMODE_DOGFIGHT;
    Enemy->Timer  = RESET_VALIDATE_TIME + (float) Random_Range( (uint16) RESET_VALIDATE_TIME );
}
/*-------------------------------------------------------------------
    Procedure   :   Set Enemy AI Mode to...
    Input       :   ENEMY * Enemy
    Output      :   Nothing
-------------------------------------------------------------------*/
void AI_SetFORMATION( ENEMY * Enemy )
{
    Enemy->Object.AI_Mode = AIMODE_FORMATION;
    Enemy->Timer  = RESET_VALIDATE_TIME + (float) Random_Range( (uint16) RESET_VALIDATE_TIME );
}
/*-------------------------------------------------------------------
    Procedure   :   Set Enemy AI Mode to...
    Input       :   ENEMY * Enemy
    Output      :   Nothing
-------------------------------------------------------------------*/
void AI_SetKILLMINE( ENEMY * Enemy )
{
    Enemy->Object.AI_Mode = AIMODE_KILLMINE;
    Enemy->Timer  = RESET_VALIDATE_TIME + (float) Random_Range( (uint16) RESET_VALIDATE_TIME );
}
/*-------------------------------------------------------------------
    Procedure   :   Set Enemy AI Mode to...
    Input       :   ENEMY * Enemy
    Output      :   Nothing
-------------------------------------------------------------------*/
void AI_SetIDLE( register ENEMY * Enemy )
{
    Enemy->TShip = NULL;
    Enemy->Object.AI_Mode = AIMODE_IDLE;
    Enemy->Timer  = EnemyTypes[Enemy->Type].Behave.IdleTime + (float) Random_Range( (uint16) EnemyTypes[Enemy->Type].Behave.IdleTime);
}
/*-------------------------------------------------------------------
    Procedure   :   Set Enemy AI Mode to...
    Input       :   ENEMY * Enemy
    Output      :   Nothing
-------------------------------------------------------------------*/
void AI_SetSCAN( register ENEMY * Enemy )
{
    Enemy->TShip = NULL;
    Enemy->Object.AI_Mode = AIMODE_SCAN;
    Enemy->Timer  = RESET_SCAN_TIME + (float) Random_Range( (uint16) RESET_SCAN_TIME );
}
/*-------------------------------------------------------------------
    Procedure   :   Set Enemy AI Mode to...
    Input       :   ENEMY * Enemy
    Output      :   Nothing
-------------------------------------------------------------------*/
void AI_SetFOLLOWPATH( register ENEMY * Enemy )
{
    Enemy->TShip = NULL;
    Enemy->Object.AI_Mode = AIMODE_FOLLOWPATH;
    Enemy->Timer  = RESET_SCAN_TIME + (float) Random_Range( (uint16) RESET_SCAN_TIME );
}
/*-------------------------------------------------------------------
    Procedure   :   Set Enemy AI Mode to...
    Input       :   ENEMY * Enemy
    Output      :   Nothing
-------------------------------------------------------------------*/
void AI_SetFIREATTARGET( register ENEMY * Enemy )
{
    Enemy->Object.AI_Mode = AIMODE_FIRE;
    Enemy->Timer  = RESET_FIRE_TIME + (float) Random_Range( (uint16) RESET_FIRE_TIME );
}
#ifdef OPT_ON
#pragma optimize( "", off )
#endif


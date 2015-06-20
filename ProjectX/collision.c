/*
 * The X Men, June 1996
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * $Revision: 127 $
 *
 * $Header: /PcProjectX/collision.c 127   6/24/98 11:35a Phillipd $
 *
 * $Log: /PcProjectX/collision.c $
 * 
 * 127   6/24/98 11:35a Phillipd
 * Server no longer collides with BGObjects...
 * 
 * 126   18/05/98 17:05 Oliverc
 * Disabled BAD_BUMP collision code and replaced it with a better version
 * 
 * 125   13/05/98 10:52 Collinsd
 * Updated collision with bgobjects and pickups.  Also changed radius of
 * mine detection for regeneration of bikes.
 * 
 * 124   14/04/98 15:59 Collinsd
 * Check for / framelag when framelag  == 0
 * 
 * 123   3/04/98 18:09 Collinsd
 * Moved position of xmem.h
 * 
 * 122   3/04/98 15:16 Collinsd
 * 
 * 121   3/04/98 11:55 Collinsd
 * Tidy
 * 
 * 120   1/04/98 9:17 Collinsd
 * Extended collision
 * 
 * 119   29/03/98 17:13 Collinsd
 * BGObject to pickup now used colradius.  Generic Pickup SFX Added to all
 * pickups without sfx.
 * 
 * 118   28/03/98 20:50 Collinsd
 * BGObjects now use collision zone bounding box.
 * Also fixed spotfx playing when paused.
 * 
 * 117   28/03/98 12:09 Collinsd
 * Fixed bug in bgobject collision.
 * 
 * 116   21/03/98 13:44 Collinsd
 * Laser & BGObject collison fixed! 
 * 
 * 115   15/03/98 18:56 Philipy
 * fixed floating point divide by zero bug when in pause mode & dividing
 * by zero
 * 
 * 114   4/03/98 21:02 Collinsd
 * Added Quick out check to bgobject collision
 * 
 * 113   12/02/98 14:09 Collinsd
 * Fixed targeting of bosses by homing missiles.
 * 
 * 112   9/02/98 8:52 Collinsd
 * Fixed couple of bugs in enemy collision.
 * 
 * 111   7/02/98 13:23 Collinsd
 * Added polygonal collision to enemies.
 * 
 * 110   5/02/98 18:13 Collinsd
 * Added enemy component collision ( Disabled ).
 * 
 * 109   13/01/98 17:37 Collinsd
 * Added back pyrolite fuel,  Changes secondary to try to get rid of any
 * chance of any link list corruption.
 * 
 * 108   13/01/98 9:39 Collinsd
 * Added debug to show untriggered enemies.  Started Enemy Poly Colisions.
 * 
 * 107   31/12/97 11:34 Oliverc
 * Disabled POLYGONAL_COLLISIONS
 * 
 * 106   29/12/97 15:58 Oliverc
 * Added new version of ObjectCollide() which does no bouncing
 * 
 * 105   29/12/97 12:04 Collinsd
 * Fixed collision zones staying when component destroyed.
 * 
 * 104   29/12/97 11:00 Oliverc
 * Another attempt...
 * 
 * 103   29/12/97 10:44 Oliverc
 * Pickups now pass through portals OK when not colliding
 * 
 * 102   29/12/97 10:42 Collinsd
 * Pickups now use new collision
 * 
 * 101   29/12/97 9:27 Oliverc
 * Added cut-down collision routine QCollide() for use with miscellaneous
 * objects (eg pickups)
 * 
 * 100   18/12/97 11:31 Collinsd
 * Added Restart Points, Changed Oneoff anim to only activate if not
 * already animating.
 * 
 * 99    15/12/97 14:19 Oliverc
 * 2nd version of tidied BSP collisions
 * 
 * 98    11/12/97 17:07 Oliverc
 * Removed NumCollides++ bug from ObjectCollide*() functions that messed
 * up MULTI_RAY_SLIDE mode
 * 
 * 97    6/12/97 19:32 Oliverc
 * 1st attempt at multi-ray collisions with sliding (currently disabled)
 * 
 * 96    5/12/97 17:46 Oliverc
 * 1st version of tidied BSP collision routines
 * 
 * 95    2/12/97 15:44 Oliverc
 * Tweaked ObjectCollide() collision response code
 * 
 * 94    11/29/97 4:35p Phillipd
 * Xmem is now in effect...use it allways....
 * 
 * 93    22/11/97 14:27 Oliverc
 * Fixed bug in impact offset calculation that failed for rays parallel to
 * collision plane
 * 
 * 92    20/11/97 8:29 Collinsd
 * Pickups now effected by BGObjects.
 * 
 * 91    17/11/97 18:44 Oliverc
 * Added new BSP portal collision routines
 * 
 * 90    5/11/97 20:09 Collinsd
 * Added more crushing/pushing code.
 * 
 * 89    5/11/97 10:52 Collinsd
 * Started work on crushing bgobjects.
 * 
 * 88    5/11/97 9:59 Oliverc
 * Add new collision function WouldObjectCollide()
 * 
 * 87    4/11/97 14:11 Collinsd
 * Background collision pushing player ( 1st working version ).
 * 
 * 86    4/11/97 14:07 Oliverc
 * 1st attempt at collision routines adapted to handle sealed BSP groups
 * 
 * 85    10/30/97 9:30a Phillipd
 * Bikes with different mods started...
 * 
 * 84    24/10/97 14:16 Oliverc
 * Attempted to fix "sticky" bug when scraping along walls by only
 * reflecting external force if it is pushing towards the last plane you
 * hit
 * 
 * 83    24/10/97 9:50 Oliverc
 * External force now reflected about impact normal on collision to help
 * fix sticking problem
 * 
 * 82    16/10/97 17:11 Oliverc
 * 2nd attempt at fixing collision response where external forces are
 * involved
 * 
 * 81    16/10/97 15:14 Oliverc
 * Fixed bug in collision response (now clears external force when
 * bounces)
 * 
 * 80    10/14/97 4:46p Phillipd
 * 
 * 79    8/10/97 20:34 Collinsd
 * Added Header and Version Code.
 * 
 * 78    17/09/97 15:33 Oliverc
 * 2nd attempt at collision response code (disabled zebedee mode)
 * 
 * 77    16/09/97 16:22 Oliverc
 * 1st attempt at new multiple-ray/single bounce object collision system
 * 
 * 76    15/08/97 16:12 Collinsd
 * Started bgobjects moving ships.  External Forces bug now fixed.
 * 
 * 75    12/08/97 18:11 Collinsd
 * Conditional tom cruise
 * 
 * 74    6/08/97 16:54 Oliverc
 * Changed BackgroundCollide() to use "BSP-friendly" start and movement
 * vectors
 * 
 * 73    17/07/97 15:38 Collinsd
 * BGObjects now use compobjs.
 * 
 * 72    8/07/97 16:30 Collinsd
 * Dicked about with include files FUCK!
 * 
 * 71    5/07/97 16:31 Collinsd
 * Put OPT_ON's around opimisations off
 * 
 * 70    7/03/97 10:11a Phillipd
 * More Ai and node
 * 
 * 69    6/24/97 5:10p Phillipd
 * 
 * 68    6/24/97 11:12a Phillipd
 * 
 * 67    20/06/97 17:29 Collinsd
 * 
 * 66    13/06/97 16:04 Collinsd
 * Taken out old bgobjects
 * 
 * 65    10/06/97 9:01 Collinsd
 * Visible group only for collision to BGObjects
 * 
 * 64    8/06/97 17:06 Collinsd
 * Done more work on BGObjects/Doors
 * 
 * 63    4/06/97 11:11 Collinsd
 * Message sending added for doors.
 * 
 * 62    3/06/97 11:41 Collinsd
 * Done more work on BGObjects
 * 
 * 61    27/05/97 17:39 Collinsd
 * Animating backgrounds collision now works ( Ish )
 * 
 * 60    16/05/97 15:55 Oliverc
 * New BSP stuff
 * 
 * 59    4/26/97 4:18p Phillipd
 * 
 * 58    26/04/97 14:49 Collinsd
 * Optimisations now on def.
 * 
 * 57    23/04/97 15:07 Collinsd
 * changed optimisation to get it to comile on my pc
 * 
 * 56    4/19/97 1:23p Phillipd
 * Only Ships Dont collide when no_collisions is set...
 * Trigger areas work better.....
 * 
 * 55    4/15/97 4:43p Phillipd
 * 
 * 54    4/08/97 12:39p Phillipd
 * 
 * 53    4/08/97 9:58a Phillipd
 * 
 * 52    4/02/97 11:44a Phillipd
 * 
 * 51    4/02/97 8:51a Phillipd
 * Bsps enabled...
 * 
 * 50    3/10/97 11:37a Phillipd
 * 
 * 49    25/02/97 16:47 Oliverc
 * MCload is now outside the optimisation pragma
 * 
 * 48    12-02-97 12:03p Collinsd
 * Added error checking to readfiles();  Also added triggers to enemies.
 * 
 * 47    6/02/97 9:35 Oliverc
 * Restored COLLISION_FUDGE to original (large) value to stop getting
 * stuck on old-stylee expanded collision polys
 * 
 * 46    2/03/97 5:16p Phillipd
 * Translusceny is now controlled by global execute buffers.... which is
 * much better...
 * 
 * 45    1/23/97 11:36a Phillipd
 * now slide doesnt slide you less than the fudge factor..
 * 
 * 44    1/22/97 2:24p Phillipd
 * 
 * 43    21-01-97 5:34p Collinsd
 * Added the ability to delete bgobjects.
 * 
 * 42    20/01/97 14:46 Oliverc
 * Changed BSP RayCollide() to output normal and offset of plane hit
 * directly
 * 
 * 41    20/01/97 9:36 Oliverc
 * fixed 1 bug in BSP collision (but still not perfect)
 * 
 * 40    1/17/97 6:04p Phillipd
 * 
 * 39    13-01-97 12:19p Collinsd
 * Doors now cannot be opened by various rays.
 * 
 * 38    12-01-97 7:28p Collinsd
 * Added scaleable collision.
 * 
 * 37    12-01-97 6:20p Collinsd
 * Optimised BGObject collision.
 * 
 * 36    12-01-97 5:51p Collinsd
 * Fixed BGObject to ship collision.
 * 
 * 35    10-01-97 3:54p Collinsd
 * Missile/Primary weapons no longer open doors before collision.
 * 
 * 34    10-01-97 12:34p Collinsd
 * Added Doors, Chanded pickups/door/mine dropping.
 * 
 * 33    6-01-97 9:06a Collinsd
 * Added drop ammo/shield options.
 * Started working on titan start missile.
 * 
 * 32    21/12/96 19:43 Oliverc
 * Added collisionskin debug options (collide/display with backfacing
 * patch polys)
 * 
 * 31    6/12/96 16:42 Oliverc
 * Fixed bug with group transition in portal/background collision
 * 
 * 30    5/12/96 16:20 Oliverc
 * 
 * 29    5/12/96 16:17 Oliverc
 * Integrated new portal format (portalpolys grouped into logical portals
 * and converted into preprojected collisionpolys), BUT bug in portal
 * transition routine remains to be fixed
 * 
 * 28    11/26/96 4:32p Phillipd
 * 
 * 27    22/11/96 9:39 Oliverc
 * 
 * 26    11/22/96 9:20a Phillipd
 * 
 * 25    4/11/96 10:44 Oliverc
 * Changed display routines to clip to visible portal boundaries of each
 * group
 * 
 * 24    10/20/96 4:13p Phillipd
 * 
 * 23    16/10/96 12:35 Oliverc
 * Modified BackgroundCollide() to handle near-simultaneous collision with
 * both background and portals
 * 
 * 22    15/10/96 18:07 Oliverc
 * Tweaked portal collision (but left tweaks disabled as it didn't seem to
 * help!)
 * 
 * 21    15/10/96 11:39 Oliverc
 * Biased collision routines to favour background collisions
 * (BackgroundCollide) or portal collisions (BackgroundCollideOneGroup)
 * whenever there is any doubt over which was hit first
 * 
 * 20    10/10/96 21:24 Oliverc
 * Tweaked ray<->poly collision routine again
 * 
 * 19    10/10/96 16:36 Oliverc
 * Tweaked ray<->poly collision routine
 * 
 * 18    8/10/96 14:23 Collinsd
 * tuned portal polerance.
 * 
 * 17    7/10/96 22:55 Oliverc
 * 
 * 16    7/10/96 22:31 Oliverc
 * Added background-to-portal collision tolerance to prefer background
 * collisions where there is a certain degree of doubt over which occurred
 * first
 * 
 * 15    7/10/96 17:15 Oliverc
 * New background collision map now used
 * allowing use of new simplified ray<->poly intersection routine (using
 * pre-projected pre-expanded collision polys)
 * 
 * 14    10/04/96 5:01p Phillipd
 * 
 * 13    10/04/96 9:43a Phillipd
 * 
 * 12    29/09/96 16:29 Oliverc
 * "Fixed" ship judder by scaling COLLISION_FUDGE by GLOBAL_SCALE (as it
 * should have been all along)
 * 
 * 11    9/26/96 3:43p Phillipd
 * 
 * 10    18/09/96 10:41 Oliverc
 * Added alternate background collision routine which only checks one
 * group at a time
 * 
 * 9     16/09/96 15:20 Oliverc
 * Changed autolevelling to be properly framelagged
 * and added ship bobbing
 * 
 * 8     13/09/96 19:40 Oliverc
 * Fixed the last fix (!) to handle multiple transitions through portals
 * in and out of the same group
 * 
 * 7     13/09/96 17:37 Oliverc
 * Fixed bug in BackgroundCollide where cyclic portals produced infinite
 * loops
 * 
 * 6     5/09/96 9:27 Oliverc
 * Modified ship-to-background collision routines to work with new
 * collision skins
 * 
 * 5     7/22/96 5:49p Phillipd
 * 
 * 4     19/07/96 12:34 Oliverc
 * Changed ship <-> background collision routine
 * to track movement of ship through portals
 * 
 * 3     7/11/96 5:12p Phillipd
 * 
 * 2     6/25/96 11:37a Phillipd
 * First SS update
 * 
 */

/*�������������������������������������������������������������������
*	c o l l i s o n . c
*	All routines needed to load in a .mc file....
*	and do collision to any polygon in a specified group..
*	or to the nearest polygon..
�������������������������������������������������������������������*/
#include <stdio.h>
#include "typedefs.h"
#include <dplay.h>
#include "new3d.h"
#include "quat.h"
#include "CompObjects.h"
#include "bgobjects.h"
#include "Object.h"
#include "mydplay.h"
#include "collision.h"
#include "trigarea.h"
#include "bsp.h"
#include "lines.h"
#include "controls.h"
#include "triggers.h"
#include "enemies.h"
#include "magic.h"
#include "sphere.h"
#include "secondary.h"
#include "Restart.h"
#include "XMem.h"

//#undef COLLISION_FUDGE
//#define COLLISION_FUDGE	(0.065F)

#define	MC_VERSION_NUMBER	1

#define	BSP_ENABLE		1
#define BSP_ONLY
//#define BSP2
#undef BSP2

#define MAX_FEELER_RAYS		(9)
#define MAX_QFEELER_RAYS	(5)

#define BACKGROUND_PORTAL_TOLERANCE		(12.0F * GLOBAL_SCALE)

#define PORTAL_IMPACTOFFSET		(0.1F * GLOBAL_SCALE)

#define POINT_ON_PORTAL_TOLERANCE	(0.1)
#define OUTSIDE_GROUP_TOLERANCE		(25.0F)


extern BOOL PISDistRecursive( VECTOR *Pos, BSP_NODE *node);
extern void ObjForceExternalOneOff( OBJECT *Obj, VECTOR *force );
extern void DebugPrintf( const char * format, ... );

extern	float	MaxMoveSpeed;
extern	float	MoveAccell;
extern	float	MoveDecell;
extern	float	MaxTurboSpeed;
extern	float	TurboAccell;
extern	float	TurboDecell;
extern	float	MaxTurnSpeed;
extern	float	TurnAccell;
extern	float	TurnDecell;
extern	float	MaxRollSpeed;
extern	float	RollAccell;
extern	float	RollDecell;
extern	float	MaxBankAngle;
extern	float	BankAccell;
extern	float	BankDecell;


extern	VECTOR	SlideRight;
extern	VECTOR	SlideUp;
extern	VECTOR	Forward;
extern	float	framelag;  

extern MLOADHEADER Mloadheader;

extern	BGOBJECT	*	FirstBGObjectUsed;
extern	BGOBJECT		BGObjects[ MAXBGOBJECTS ];

extern	LINE			Lines[ MAXLINES ];
extern	ENEMY			Enemies[ MAXENEMIES ];

extern	MCLOADHEADER	MCloadheadert0;					//  0 thickness collision map...
extern	MCLOADHEADER	MCloadheader;					//  ship collision map...
extern	GLOBALSHIP		Ships[MAX_PLAYERS];
extern	uint16			IsGroupVisible[MAXGROUPS];

extern BOOL	DebugInfo;
int no_collision = 0;
int outside_group = 0;


static void CalcNormal( VERT *v0, VERT *v1, VERT *v2, NORMAL *normal );

	DWORD GroupPolyCol_timeMax = 0;

static VECTOR		ColPoint;
static ZONESIDE	*	ColSide;
static float		ColDist;
//static COMP_OBJ *	ColChild;
	COMP_OBJ	*	ColChild;
static int			ColCollided;
static float		ColRadius;
static VECTOR		ColDir;
static BGOBJECT *	ColParent;
static int16		ColZoneNum;

static	uint16		CompEnemyHit = (uint16) -1;
static	uint16		AnyCompEnemyHit = (uint16) -1;
static	VECTOR		CompEnemyHitPos;
static	NORMAL		CompEnemyHitNormal;
static	float		CompEnemyHitDist;

static	VECTOR	Origin;
static	VECTOR	ODir;
static	VECTOR	IPoint;
static	float	IDist;
static	float	*IPointp = (float *) &IPoint;

extern	float	CollisionRadius;
extern	float	SoundInfo[MAXGROUPS][MAXGROUPS];

extern	RESTART	*	FirstRestartUsed;
extern	float			SoundInfo[MAXGROUPS][MAXGROUPS];
extern	ENEMY	*		FirstEnemyUsed;

BOOL CheckRestartPointCol( uint16 Group, float Distance, VECTOR * ImpactPoint,
					  int collided, VECTOR * New_Pos, NORMAL * FaceNormal, BGOBJECT ** BGObject );

BOOL CheckEnemyPolyCol( uint16 Group, float Distance, VECTOR * ImpactPoint,
					  int collided, VECTOR * New_Pos, NORMAL * FaceNormal, BGOBJECT ** BGObject );

/*�������������������������������������������������������������������
	Procedure	:		Load .mc File Collision file..
	Input		:		char	*	Filename , MCLOADHEADER * MCloadheader
	Output		:		BOOL
�������������������������������������������������������������������*/
BOOL MCload( char * Filename , MCLOADHEADER * MCloadheader )
{
#ifdef POLYGONAL_COLLISIONS
	long			File_Size;
	long			Read_Size;
	char		*	Buffer;
	uint16		*	Uint16Pnt;
	uint32		*	Uint32Pnt;
	int				i;
	uint32			MagicNumber;
	uint32			VersionNumber;

	File_Size = Get_File_Size( Filename );	

	if( !File_Size )
		return ( FALSE );

	Buffer = malloc( File_Size );

	if( Buffer == NULL )
		return( FALSE );

	Read_Size = Read_File( Filename, Buffer, File_Size );

	if( Read_Size != File_Size )
		return( FALSE );
	
	MCloadheader->Buffer = Buffer;

	Uint32Pnt = (uint32 *) Buffer;
	MagicNumber = *Uint32Pnt++;
	VersionNumber = *Uint32Pnt++;
	Buffer = (char *) Uint32Pnt;

	if( ( MagicNumber != MAGIC_NUMBER ) || ( VersionNumber != MC_VERSION_NUMBER  ) )
	{
		Msg( "MCload() Incompatible collision ( .MC ) file %s", Filename );
		return( FALSE );
	}

	Uint16Pnt = (uint16 *) Buffer;
	/*	get the number of Groups	*/
	MCloadheader->num_of_groups = *Uint16Pnt++;
	Buffer = (char *) Uint16Pnt;		

	for( i=0 ; i<MCloadheader->num_of_groups;i++)
	{
		/* get the number of polys in the group	*/
		Uint16Pnt = (uint16 *) Buffer;
		MCloadheader->num_of_faces_in_group[i] = *Uint16Pnt++ ;
		Buffer = (char *) Uint16Pnt;		
		/* make a note of the address of the Faces	*/
		MCloadheader->GroupFacePnt[i] = (MCFACE *) Buffer;
		Buffer += ( MCloadheader->num_of_faces_in_group[i] * sizeof(MCFACE) );
	}
#endif // POLYGONAL_COLLISIONS

	return( TRUE );
}

#ifdef OPT_ON
#pragma optimize( "gty", on )
#endif

/*�������������������������������������������������������������������
	Procedure	:	Check Ray to Polygon intersection
	Input		:	D3DVECTOR	*	Point 0
				:	D3DVECTOR	*	Point 1
				:	D3DVECTOR	*	Point 2
				:	VECTOR	*	Origin
				:	VECTOR	*	Direction
				:	VECTOR	*	Intersect Point
	Output		:	int			TRUE/ FALSE
�������������������������������������������������������������������*/
#ifdef USEINLINE
_inline
#endif
BOOL RayPolyIntersect( float * P0 , float * P1 , float * P2 , float * P3 ,
	 				 VERT *  Point, NORMAL * FaceNormal , float D , float * TempDistance)
{
	float		t;
	float		Div, Num;
	int			i1, i2;
	int			ClockCount;
	int			AntiCount;
	float		Np0x;
	float		Np0y;
	float		Np1x;
	float		Np1y;
	float		Np2x;
	float		Np2y;
	float		Np3x;
	float		Np3y;
	float		Np4x;
	float		Np4y;
	float		Npcx;
	float		Npcy;
	float		*NP4;



/*�������������������������������������������������������������������
	Calculate D
�������������������������������������������������������������������*/
//	D =	( ( P0->x * FaceNormal->nx ) +
//		  ( P0->y * FaceNormal->ny ) +
//		  ( P0->z * FaceNormal->nz ) ); 

//	D = -ColDotProduct( P0 , FaceNormal  );

/*�������������������������������������������������������������������
	Calculate T
�������������������������������������������������������������������*/
	Div = ( ODir.x * FaceNormal->nx) + 
		  ( ODir.y * FaceNormal->ny) + 
		  ( ODir.z * FaceNormal->nz);
	
//	Div = ColDotProduct( &ODir , FaceNormal );
	
	if( Div >= 0.0F ) return FALSE;		/* Reject, Parallel */


	Num = ( ( Origin.x * FaceNormal->nx ) +
		    ( Origin.y * FaceNormal->ny ) +
		    ( Origin.z * FaceNormal->nz ) ) + D ; 
		
//	Num = ( D + ColDotProduct( &Origin , FaceNormal) );
	
	
	t = -( Num / Div );

	if( t < 0.0F ) return FALSE;		/* Intersection behind origin */
	if( t > 1.0F ) return FALSE;		/* Intersection Greater then ray length */

	*TempDistance = t;

/*�������������������������������������������������������������������
	Do Polygon collision
�������������������������������������������������������������������*/
	Point->x = ( Origin.x + ( ODir.x * t ) );
	Point->y = ( Origin.y + ( ODir.y * t ) );
	Point->z = ( Origin.z + ( ODir.z * t ) );


/*�������������������������������������������������������������������
	Work out best axis to cast polygon onto
�������������������������������������������������������������������*/
	if( fabs( FaceNormal->nx ) >= fabs( FaceNormal->ny ) &&
		fabs( FaceNormal->nx ) >= fabs( FaceNormal->nz ) )
	{
		i1 = Y;						/* Y Axis		*/
		i2 = Z;						/* and Z axis	*/
	}else{
 		i1 = X;					/* X Axis		*/
		if( fabs( FaceNormal->ny ) >= fabs( FaceNormal->nx ) &&
		    fabs( FaceNormal->ny ) >= fabs( FaceNormal->nz ) )
		{
			i2 = Z;					/* and Z axis	*/
		}else{
			i2 = Y;					/* and Y axis	*/
		}
	}


/*�������������������������������������������������������������������
	Check if point within triangles
�������������������������������������������������������������������*/
	AntiCount = 0;
	ClockCount = 0;

	NP4 = (float *) Point;
	Np4x = NP4[ i1 ];
	Np4y = NP4[ i2 ];

	Np0x = P0[ i1 ];
	Np0y = P0[ i2 ];
	Np1x = P1[ i1 ];
	Np1y = P1[ i2 ];
	Np2x = P2[ i1 ];
	Np2y = P2[ i2 ];

	if( P3 == (float*) -1)	//if -1 then only a tri....
	{
///*
		Npcx = ( Np0x + Np1x + Np2x) / 3.0F;
		Npcy = ( Np0y + Np1y + Np2y) / 3.0F;
//*/
	}else{
		Np3x = P3[ i1 ];
		Np3y = P3[ i2 ];
///*
		Npcx = ( Np0x + Np1x + Np2x + Np3x ) * 0.25F;	// same as divide by 4
		Npcy = ( Np0y + Np1y + Np2y + Np3y ) * 0.25F;	// same as divide by 4
		Np3x = (Np3x - Npcx ) * SCALE_FUDGE;
		Np3y = (Np3y - Npcy ) * SCALE_FUDGE;
//*/ 
   }
///*
	Np0x = (Np0x - Npcx ) * SCALE_FUDGE;
	Np0y = (Np0y - Npcy ) * SCALE_FUDGE;
	Np1x = (Np1x - Npcx ) * SCALE_FUDGE;
	Np1y = (Np1y - Npcy ) * SCALE_FUDGE;
	Np2x = (Np2x - Npcx ) * SCALE_FUDGE;
	Np2y = (Np2y - Npcy ) * SCALE_FUDGE;
	Np4x -= Npcx;
	Np4y -= Npcy;
//*/
	if( ( Np4x * ( Np0y - Np1y ) ) +
	    ( Np0x * ( Np1y - Np4y ) ) +
	    ( Np1x * ( Np4y - Np0y ) ) < 0.0F ) ClockCount++;
	else AntiCount++;

	if( ( Np4x * ( Np1y - Np2y ) ) +
	    ( Np1x * ( Np2y - Np4y ) ) +
	    ( Np2x * ( Np4y - Np1y ) ) < 0.0F )
	{
		if( AntiCount ) return FALSE;
	}else{
		if( ClockCount ) return FALSE;
	}

	if( P3 == (float*) -1)	//if -1 then only a tri....
	{

		if( ( Np4x * ( Np2y - Np0y ) ) +
		    ( Np2x * ( Np0y - Np4y ) ) +
		    ( Np0x * ( Np4y - Np2y ) ) < 0.0F )
		{
			if( AntiCount ) return FALSE;
		}else{
			if( ClockCount ) return FALSE;
		}
	}else{			// otherwise it must be a quad...
		if( ( Np4x * ( Np2y - Np3y ) ) +
		    ( Np2x * ( Np3y - Np4y ) ) +
		    ( Np3x * ( Np4y - Np2y ) ) < 0.0F )
		{
			if( AntiCount ) return FALSE;
		}else{
			if( ClockCount ) return FALSE;
		}
		if( ( Np4x * ( Np3y - Np0y ) ) +
		    ( Np3x * ( Np0y - Np4y ) ) +
		    ( Np0x * ( Np4y - Np3y ) ) < 0.0F )
		{
			if( AntiCount ) return FALSE;
		}else{
			if( ClockCount ) return FALSE;
		}
	}
	return TRUE;
}


typedef enum
{
	X_Axis = 0,
	Y_Axis = 1,
	Z_Axis = 2
} AxisIndex;

#ifdef USEINLINE
_inline
#endif
BOOL ColRayPolyIntersect( MCFACE *face )
{
	float		t;
	float		Div, Num;
	float		v0x;
	float		v0y;
	float		v1x;
	float		v1y;
	float		v2x;
	float		v2y;
	float		v3x;
	float		v3y;
	float		ix;
	float		iy;
	BOOL		Clockwise;

	if ( !DebugInfo && ( face->type & 0x800000L ) )
		return FALSE; // ignore backfacing patch collision polys unless debugging
/*�������������������������������������������������������������������
	Calculate T
�������������������������������������������������������������������*/
	Div = ( ODir.x * face->nx) + 
		  ( ODir.y * face->ny) + 
		  ( ODir.z * face->nz);
	
//	Div = ColDotProduct( &ODir , (NORMAL *) &face->nx );
	
	if( Div >= 0.0F ) return FALSE;		/* Reject, Parallel */


	Num = ( ( Origin.x * face->nx ) +
		    ( Origin.y * face->ny ) +
		    ( Origin.z * face->nz ) ) + face->D ; 
		
//	Num = ( D + ColDotProduct( &Origin , (NORMAL *) face->nx) );
	
	
	t = -( Num / Div );

/*�������������������������������������������������������������������
	Do Polygon collision
�������������������������������������������������������������������*/

	if( t < 0.0F ) return FALSE;		/* Intersection behind origin */
	if( t > 1.0F ) return FALSE;		/* Intersection Greater then ray length */

	IPoint.x = ( Origin.x + ( ODir.x * t ) );
	IPoint.y = ( Origin.y + ( ODir.y * t ) );
	IPoint.z = ( Origin.z + ( ODir.z * t ) );

/*�������������������������������������������������������������������
	Find projected 2D coords of vertices and intersection point
�������������������������������������������������������������������*/

	v0x = face->v[ 0 ].u;
	v0y = face->v[ 0 ].v;
	v1x = face->v[ 1 ].u;
	v1y = face->v[ 1 ].v;
	v2x = face->v[ 2 ].u;
	v2y = face->v[ 2 ].v;

	ix = IPointp[ ( face->type & 6 ) ? X_Axis : Y_Axis ];
	iy = IPointp[ ( face->type & 4 ) ? Y_Axis : Z_Axis ];


/*�������������������������������������������������������������������
	Check if point within triangle
�������������������������������������������������������������������*/

	if( ( ix * ( v0y - v1y ) ) +
	    ( v0x * ( v1y - iy ) ) +
	    ( v1x * ( iy - v0y ) ) < 0.0F )
	{
		Clockwise = TRUE;
	}
	else
	{
		Clockwise = FALSE;
	}

	if( ( ix * ( v1y - v2y ) ) +
	    ( v1x * ( v2y - iy ) ) +
	    ( v2x * ( iy - v1y ) ) < 0.0F )
	{
		if( !Clockwise )
			return FALSE;
	}
	else
	{
		if( Clockwise )
			return FALSE;
	}

	if( face->type & 1 ) // face is a quad
	{
		v3x = face->v[ 3 ].u;
		v3y = face->v[ 3 ].v;

		if( ( ix * ( v2y - v3y ) ) +
		    ( v2x * ( v3y - iy ) ) +
		    ( v3x * ( iy - v2y ) ) < 0.0F )
		{
			if( !Clockwise )
				return FALSE;
		}
		else
		{
			if( Clockwise )
				return FALSE;
		}
		if( ( ix * ( v3y - v0y ) ) +
		    ( v3x * ( v0y - iy ) ) +
		    ( v0x * ( iy - v3y ) ) < 0.0F )
		{
			if( !Clockwise )
				return FALSE;
		}
		else
		{
			if( Clockwise )
				return FALSE;
		}
	}
	else // face only a tri
	{
		if( ( ix * ( v2y - v0y ) ) +
		    ( v2x * ( v0y - iy ) ) +
		    ( v0x * ( iy - v2y ) ) < 0.0F )
		{
			if( !Clockwise )
				return FALSE;
		}
		else
		{
			if( Clockwise )
				return FALSE;
		}
	}
	IDist = t;
	return TRUE;
}



BOOL ColRayPlaneIntersect( VECTOR *normal, float offset )
{
	float		t;
	float		Div, Num;

/*�������������������������������������������������������������������
	Calculate T
�������������������������������������������������������������������*/
	Div = ( ODir.x * normal->x) + 
		  ( ODir.y * normal->y) + 
		  ( ODir.z * normal->z);
	
//	Div = ColDotProduct( &ODir , (NORMAL *) &normal->nx );
	
	if( Div >= 0.0F ) return FALSE;		/* Reject, Parallel */


	Num = ( ( Origin.x * normal->x ) +
		    ( Origin.y * normal->y ) +
		    ( Origin.z * normal->z ) ) + offset; 
		
//	Num = ( D + ColDotProduct( &Origin , (NORMAL *) face->nx) );
	
	
	t = -( Num / Div );

/*�������������������������������������������������������������������
	Do plane collision
�������������������������������������������������������������������*/

	if( t < 0.0F ) return FALSE;		/* Intersection behind origin */
	if( t > 1.0F ) return FALSE;		/* Intersection Greater then ray length */

	IPoint.x = ( Origin.x + ( ODir.x * t ) );
	IPoint.y = ( Origin.y + ( ODir.y * t ) );
	IPoint.z = ( Origin.z + ( ODir.z * t ) );

	IDist = t;
	return TRUE;
}




/*�������������������������������������������������������������������
	Procedure	:	Calculate the Dot product of a Vert and Normal
	Input		:	VERT	*	a
				:	NORMAL	*	b
	Output		:	float		Dot Product
�������������������������������������������������������������������*/
#if 1
#ifdef USEINLINE
_inline
#endif
float ColDotProduct( VECTOR * a , NORMAL * b ) 
{
	return( ( a->x * b->nx ) +
		    ( a->y * b->ny ) +
		    ( a->z * b->nz ) );
}
#else
#ifdef USEINLINE
_inline
#endif
float ColDotProduct( VECTOR * vec0 , NORMAL * vec1 ) 
{
	float	dot;
	__asm
	{
		fld		[vec0+0]
		fmul	[vec1+0]
		fld		[vec0+4]
		fmul	[vec1+4]
		fld		[vec0+8]
		fmul	[vec1+8]
		fxch	st(1)
		faddp	st(0),st(2)
		faddp	st(0),st(1)
		fstp	[dot]
	}
	return dot;
}
#endif






#define NIL ((uint16) -1)

static float hit_portal_offset = 0.0F;

// version 3...
/*
 * BackgroundCollide
 *
 * Description
 *	checks for background collisions of a point moving between two positions
 *
 * Inputs
 *	c			=	background collision model
 *	m			=	background display model
 *	StartPos	=	start position
 *	StartGroup	=	group start position is in
 *	MoveOffset	=	movement offset
 *	BGCol		=	BGObject Collision wanted
 *
 * Outputs
 *	EndPos		=	final position (either collision impact point or target)
 *	EndGroup	=	group final position is in
 *	FaceNormal	=	normal of face collided with (if collided at all)
 *	NewTarget	=	new target position after sliding along collision face (if collided at all)
 *
 * Returns
 *	TRUE if collided with background, FALSE if no collision
 */
#ifdef BSP_ONLY
BOOL BackgroundCollide( MCLOADHEADER *c, MLOADHEADER *m,
					  VECTOR *StartPos, uint16 StartGroup, VECTOR *MoveOffset, 
					  VECTOR *EndPos, uint16 *EndGroup,
					  NORMAL *FaceNormal, VECTOR *NewTarget, BOOL BGCol, BGOBJECT ** BGObject )
{
	float poffset, pdist;
	VECTOR ppos, pmove, epos, tpos;
	NORMAL fnorm, pnorm;
	uint16 group;
	uint16 next_group;
	uint16 last_group;
	BOOL hit_bg, hit_portal, hit_any_portal;
	float dist_bg;
	VECTOR dv;
	float impact_offset;
	VECTOR	OldPMove;
	VECTOR	OldPPos;
	float impact_dotp;

	CompEnemyHit = (uint16) -1;
	AnyCompEnemyHit = (uint16) -1;
	next_group = StartGroup;
	ppos = *StartPos;
	pmove = *MoveOffset;
	hit_any_portal = FALSE;
	do {
		group = next_group;
		hit_portal = FALSE;
		OldPMove = pmove;
		OldPPos = ppos;
		hit_bg = FALSE;
		if ( OneGroupPolyCol( c, m, group, &OldPPos, &OldPMove, &epos, &fnorm, &tpos, BGCol, BGObject ) )
		{
			BSP_PORTAL_GROUP	*pg;
			BSP_PORTAL			*bp;
			int					j;
			float				d;
			
			dv.x = epos.x - StartPos->x;
			dv.y = epos.y - StartPos->y;
			dv.z = epos.z - StartPos->z;
			dist_bg = (float) sqrt( dv.x * dv.x + dv.y * dv.y + dv.z * dv.z );
			
			pg = &Bsp_Portal_Header.group[ group ];
			for ( j = 0; j < pg->portals; j++ )
			{
				bp = &pg->portal[ j ];
				if ( DotProduct( &bp->normal, MoveOffset ) < 0.0F )
				{
					d = epos.x * bp->normal.x + epos.y * bp->normal.y + epos.z * bp->normal.z + bp->offset;
					if ( fabs( d ) < POINT_ON_PORTAL_TOLERANCE )
					{
						if ( PISDistRecursive( &epos, bp->bsp.Root ) )
						{
							hit_portal = TRUE;
							next_group = bp->group;
							pmove.x += ppos.x - epos.x;
							pmove.y += ppos.y - epos.y;
							pmove.z += ppos.z - epos.z;
							ppos = epos;
							hit_any_portal = TRUE;
							pnorm.nx = bp->normal.x;
							pnorm.ny = bp->normal.y;
							pnorm.nz = bp->normal.z;
							hit_portal_offset = bp->offset;
							last_group = group;
							break;
						}
					}
				}
			}
			if ( hit_portal )
			{
				hit_bg = FALSE;
			}
			else
			{
				hit_bg = TRUE;
				dv = *MoveOffset;
				NormaliseVector( &dv );
				impact_dotp = -( dv.x * fnorm.nx + dv.y * fnorm.ny + dv.z * fnorm.nz );
				impact_offset = ( impact_dotp ) ? COLLISION_FUDGE / impact_dotp : 2.0F * dist_bg;
				if ( dist_bg > impact_offset )
				{
					epos.x -= dv.x * impact_offset;
					epos.y -= dv.y * impact_offset;
					epos.z -= dv.z * impact_offset;
					if ( hit_any_portal )
					{
						// find distance of end point from portal plane
						poffset = hit_portal_offset;
						pdist = epos.x * pnorm.nx + epos.y * pnorm.ny + epos.z * pnorm.nz + poffset;
						// NB this test is NOT perfect -- ideally should fire ray from StartPos to epos to find EndGroup more reliably
						if ( pdist < 0.0F ) // end point still behind last portal plane -> collide in this group
							*EndGroup = group;
						else // end point now in front of portal plane -> collide in last group
							*EndGroup = last_group;
					}
					else
					{
	 					*EndGroup = group;
					}
				}
				else
				{
					epos = *StartPos;
					*EndGroup = StartGroup;
				}
				*EndPos = epos;
				*FaceNormal = fnorm;
				*NewTarget = tpos;
			}
		}
	} while ( !hit_bg && hit_portal );
	if ( !hit_bg )
	{
		*EndGroup = group;
		EndPos->x = StartPos->x + MoveOffset->x;
		EndPos->y = StartPos->y + MoveOffset->y;
		EndPos->z = StartPos->z + MoveOffset->z;
	}
	dv.x = (float) fabs( EndPos->x - m->Group[ *EndGroup ].center.x );
	dv.y = (float) fabs( EndPos->y - m->Group[ *EndGroup ].center.y );
	dv.z = (float) fabs( EndPos->z - m->Group[ *EndGroup ].center.z );
	outside_group = dv.x > m->Group[ *EndGroup ].half_size.x + OUTSIDE_GROUP_TOLERANCE ||
					dv.y > m->Group[ *EndGroup ].half_size.y + OUTSIDE_GROUP_TOLERANCE ||
					dv.z > m->Group[ *EndGroup ].half_size.z + OUTSIDE_GROUP_TOLERANCE;
	return hit_bg;
}

#else // !BSP_ONLY

BOOL BackgroundCollide( MCLOADHEADER *c, MLOADHEADER *m,
					  VECTOR *StartPos, uint16 StartGroup, VECTOR *MoveOffset, 
					  VECTOR *EndPos, uint16 *EndGroup,
					  NORMAL *FaceNormal, VECTOR *NewTarget, BOOL BGCol, BGOBJECT ** BGObject )
{
	float poffset, pdist;
	VECTOR ppos, pmove, epos, tpos;
	NORMAL fnorm, pnorm;
	uint16 group;
	uint16 next_group;
	uint16 last_group;
	BOOL hit_bg, hit_portal, hit_any_portal;
	float dist_bg, dist_portal;
	VECTOR dv;
	float impact_offset;
	VECTOR	OldPMove;
	VECTOR	OldPPos;
	float impact_dotp;

	CompEnemyHit = (uint16) -1;
	AnyCompEnemyHit = (uint16) -1;
	next_group = StartGroup;
	ppos = *StartPos;
	pmove = *MoveOffset;
	hit_any_portal = FALSE;
	do {
		group = next_group;
		hit_portal = FALSE;
		OldPMove = pmove;
		OldPPos = ppos;
		if ( !Bsp_Portal_Header.state && OneGroupPortalCol( m, group, &ppos, &pmove, &epos, &pnorm, &next_group, 0 ) )
		{
			hit_portal = TRUE;
			dv.x = epos.x - StartPos->x;
			dv.y = epos.y - StartPos->y;
			dv.z = epos.z - StartPos->z;
			dist_portal = (float) sqrt( dv.x * dv.x + dv.y * dv.y + dv.z * dv.z );
			pmove.x += ppos.x - epos.x;
			pmove.y += ppos.y - epos.y;
			pmove.z += ppos.z - epos.z;
			ppos = epos;
			hit_any_portal = TRUE;
			last_group = group;
		}
		hit_bg = FALSE;
		if ( OneGroupPolyCol( c, m, group, &OldPPos, &OldPMove, &epos, &fnorm, &tpos, BGCol, BGObject ) )
		{
			dv.x = epos.x - StartPos->x;
			dv.y = epos.y - StartPos->y;
			dv.z = epos.z - StartPos->z;
			dist_bg = (float) sqrt( dv.x * dv.x + dv.y * dv.y + dv.z * dv.z );
			if ( Bsp_Portal_Header.state )
			{
				BSP_PORTAL_GROUP	*pg;
				BSP_PORTAL			*bp;
				int					j;
				float				d;
				
				pg = &Bsp_Portal_Header.group[ group ];
				for ( j = 0; j < pg->portals; j++ )
				{
					bp = &pg->portal[ j ];
					if ( DotProduct( &bp->normal, MoveOffset ) < 0.0F )
					{
						d = epos.x * bp->normal.x + epos.y * bp->normal.y + epos.z * bp->normal.z + bp->offset;
						if ( fabs( d ) < POINT_ON_PORTAL_TOLERANCE )
						{
							if ( PISDistRecursive( &epos, bp->bsp.Root ) )
							{
								hit_portal = TRUE;
								next_group = bp->group;
								pmove.x += ppos.x - epos.x;
								pmove.y += ppos.y - epos.y;
								pmove.z += ppos.z - epos.z;
								ppos = epos;
								hit_any_portal = TRUE;
								last_group = group;
								break;
							}
						}
					}
				}
			}
			if ( hit_portal )
			{
				if ( Bsp_Portal_Header.state || (float) fabs( dist_bg - dist_portal ) < 0.1F )
				{
					hit_bg = FALSE;
				}
				else if ( dist_bg < dist_portal )
				{
					hit_bg = TRUE;
					hit_portal = FALSE;
					dv = *MoveOffset;
					NormaliseVector( &dv );
					impact_dotp = -( dv.x * fnorm.nx + dv.y * fnorm.ny + dv.z * fnorm.nz );
					impact_offset = ( impact_dotp ) ? COLLISION_FUDGE / impact_dotp : 2.0F * dist_bg;
					if ( dist_bg > impact_offset )
					{
						epos.x -= dv.x * impact_offset;
						epos.y -= dv.y * impact_offset;
						epos.z -= dv.z * impact_offset;
						// find distance of end point from portal plane
						poffset = hit_portal_offset;
						pdist = epos.x * pnorm.nx + epos.y * pnorm.ny + epos.z * pnorm.nz + poffset;
						// NB this test is NOT perfect -- ideally should fire ray from StartPos to epos to find EndGroup more reliably
						if ( pdist < 0.0F ) // end point still behind portal plane -> collide in adjacent group
							*EndGroup = next_group;
						else // end point now in front of portal plane -> collide in this group
							*EndGroup = group;
					}
					else
					{
						epos = *StartPos;
						*EndGroup = StartGroup;
					}
					*EndPos = epos;
					*FaceNormal = fnorm;
					*NewTarget = tpos;
				}
			}
			else
			{
				hit_bg = TRUE;
				dv = *MoveOffset;
				NormaliseVector( &dv );
				impact_dotp = -( dv.x * fnorm.nx + dv.y * fnorm.ny + dv.z * fnorm.nz );
				impact_offset = ( impact_dotp ) ? COLLISION_FUDGE / impact_dotp : 2.0F * dist_bg;
				if ( dist_bg > impact_offset )
				{
					epos.x -= dv.x * impact_offset;
					epos.y -= dv.y * impact_offset;
					epos.z -= dv.z * impact_offset;
					if ( hit_any_portal )
					{
						// find distance of end point from portal plane
						poffset = hit_portal_offset;
						pdist = epos.x * pnorm.nx + epos.y * pnorm.ny + epos.z * pnorm.nz + poffset;
						// NB this test is NOT perfect -- ideally should fire ray from StartPos to epos to find EndGroup more reliably
						if ( pdist < 0.0F ) // end point still behind last portal plane -> collide in this group
							*EndGroup = group;
						else // end point now in front of portal plane -> collide in last group
							*EndGroup = last_group;
					}
					else
					{
	 					*EndGroup = group;
					}
				}
				else
				{
					epos = *StartPos;
					*EndGroup = StartGroup;
				}
				*EndPos = epos;
				*FaceNormal = fnorm;
				*NewTarget = tpos;
			}
		}
	} while ( !hit_bg && hit_portal );
	if ( !hit_bg )
	{
		*EndGroup = group;
		EndPos->x = StartPos->x + MoveOffset->x;
		EndPos->y = StartPos->y + MoveOffset->y;
		EndPos->z = StartPos->z + MoveOffset->z;
	}
	dv.x = (float) fabs( EndPos->x - m->Group[ *EndGroup ].center.x );
	dv.y = (float) fabs( EndPos->y - m->Group[ *EndGroup ].center.y );
	dv.z = (float) fabs( EndPos->z - m->Group[ *EndGroup ].center.z );
	outside_group = dv.x > m->Group[ *EndGroup ].half_size.x + OUTSIDE_GROUP_TOLERANCE ||
					dv.y > m->Group[ *EndGroup ].half_size.y + OUTSIDE_GROUP_TOLERANCE ||
					dv.z > m->Group[ *EndGroup ].half_size.z + OUTSIDE_GROUP_TOLERANCE;
	return hit_bg;
}
#endif // !BSP_ONLY


/*
 * BackgroundCollideOneGroup
 *
 * Description
 *	checks for background collisions of a point moving between two positions
 *	only in the current group
 *
 * Inputs
 *	c			=	background collision model
 *	m			=	background display model
 *	StartPos	=	start position
 *	StartGroup	=	group start position is in
 *	MoveOffset	=	movement offset
 *	BGCol		=	BGObject Collision wanted
 *
 * Outputs
 *	EndPos		=	final position (either collision impact point, target, or group boundary)
 *	EndGroup	=	group final position is in (or next group if on boundary)
 *	FaceNormal	=	normal of face collided with (if collided at all)
 *	NewTarget	=	new target position after sliding along collision face (if collided at all)
 *
 * Returns
 *	TRUE if collided with background, FALSE if no collision
 */
#ifdef BSP_ONLY
BOOL BackgroundCollideOneGroup( MCLOADHEADER *c, MLOADHEADER *m,
					  VECTOR *StartPos, uint16 StartGroup, VECTOR *MoveOffset, 
					  VECTOR *EndPos, uint16 *EndGroup,
					  NORMAL *FaceNormal, VECTOR *NewTarget, BOOL BGCol, BGOBJECT ** BGObject )
{
	VECTOR ppos, pmove, epos, tpos;
	NORMAL fnorm;
	uint16 group;
	uint16 next_group;
	BOOL hit_bg, hit_portal;
	float dist_bg;
	VECTOR dv;
	float impact_offset;
	float impact_dotp;

	CompEnemyHit = (uint16) -1;
	AnyCompEnemyHit = (uint16) -1;
	next_group = StartGroup;
	ppos = *StartPos;
	pmove = *MoveOffset;
	group = next_group;
	hit_portal = FALSE;
	hit_bg = FALSE;
	if ( OneGroupPolyCol( c, m, group, StartPos, MoveOffset, &epos, &fnorm, &tpos, BGCol, BGObject ) )
	{
		BSP_PORTAL_GROUP	*pg;
		BSP_PORTAL			*bp;
		int					j;
		float				d;
		
		pg = &Bsp_Portal_Header.group[ group ];
		for ( j = 0; j < pg->portals; j++ )
		{
			bp = &pg->portal[ j ];
			if ( DotProduct( &bp->normal, MoveOffset ) < 0.0F )
			{
				d = epos.x * bp->normal.x + epos.y * bp->normal.y + epos.z * bp->normal.z + bp->offset;
				if ( fabs( d ) < POINT_ON_PORTAL_TOLERANCE )
				{
					if ( PISDistRecursive( &epos, bp->bsp.Root ) )
					{
						hit_portal = TRUE;
						next_group = bp->group;
						pmove.x += ppos.x - epos.x;
						pmove.y += ppos.y - epos.y;
						pmove.z += ppos.z - epos.z;
						ppos = epos;
						break;
					}
				}
			}
		}
		if ( hit_portal )
		{
			hit_bg = FALSE;
		}
		else
		{
			hit_bg = TRUE;
			dv.x = epos.x - StartPos->x;
			dv.y = epos.y - StartPos->y;
			dv.z = epos.z - StartPos->z;
			dist_bg = (float) sqrt( dv.x * dv.x + dv.y * dv.y + dv.z * dv.z );
			dv = *MoveOffset;
			NormaliseVector( &dv );
			impact_dotp = -( dv.x * fnorm.nx + dv.y * fnorm.ny + dv.z * fnorm.nz );
			impact_offset = ( impact_dotp ) ? COLLISION_FUDGE / impact_dotp : 2.0F * dist_bg;
			if ( dist_bg > impact_offset )
			{
				epos.x -= dv.x * impact_offset;
				epos.y -= dv.y * impact_offset;
				epos.z -= dv.z * impact_offset;
	 			*EndGroup = group;
			}
			else
			{
				epos = *StartPos;
				*EndGroup = StartGroup;
			}
 			*EndGroup = group;
			*EndPos = epos;
			*FaceNormal = fnorm;
			*NewTarget = tpos;
		}
	}
	if ( !hit_bg )
	{
		if ( hit_portal )
		{
			*EndGroup = next_group;
			*EndPos = ppos;
		}
		else
		{
			*EndGroup = group;
			EndPos->x = StartPos->x + MoveOffset->x;
			EndPos->y = StartPos->y + MoveOffset->y;
			EndPos->z = StartPos->z + MoveOffset->z;
		}
	}
	return hit_bg;
}


#else !BSP_ONLY


BOOL BackgroundCollideOneGroup( MCLOADHEADER *c, MLOADHEADER *m,
					  VECTOR *StartPos, uint16 StartGroup, VECTOR *MoveOffset, 
					  VECTOR *EndPos, uint16 *EndGroup,
					  NORMAL *FaceNormal, VECTOR *NewTarget, BOOL BGCol, BGOBJECT ** BGObject )
{
	VECTOR ppos, pmove, epos, tpos;
	NORMAL fnorm;
	uint16 group;
	uint16 next_group;
	BOOL hit_bg, hit_portal;
	float dist_bg, dist_portal;
	VECTOR dv;
	float impact_offset;
	float impact_dotp;

	CompEnemyHit = (uint16) -1;
	AnyCompEnemyHit = (uint16) -1;
	next_group = StartGroup;
	ppos = *StartPos;
	pmove = *MoveOffset;
	group = next_group;
	hit_portal = FALSE;
	if ( !Bsp_Portal_Header.state && OneGroupPortalCol( m, group, &ppos, &pmove, &epos, &fnorm, &next_group, 0 ) )
	{
		hit_portal = TRUE;
		dv.x = epos.x - StartPos->x;
		dv.y = epos.y - StartPos->y;
		dv.z = epos.z - StartPos->z;
		dist_portal = (float) sqrt( dv.x * dv.x + dv.y * dv.y + dv.z * dv.z );
		pmove.x += ppos.x - epos.x;
		pmove.y += ppos.y - epos.y;
		pmove.z += ppos.z - epos.z;
		ppos = epos;
	}
	hit_bg = FALSE;
	if ( OneGroupPolyCol( c, m, group, StartPos, MoveOffset, &epos, &fnorm, &tpos, BGCol, BGObject ) )
	{
		dv.x = epos.x - StartPos->x;
		dv.y = epos.y - StartPos->y;
		dv.z = epos.z - StartPos->z;
		dist_bg = (float) sqrt( dv.x * dv.x + dv.y * dv.y + dv.z * dv.z );
		if ( Bsp_Portal_Header.state )
		{
			BSP_PORTAL_GROUP	*pg;
			BSP_PORTAL			*bp;
			int					j;
			float				d;

			pg = &Bsp_Portal_Header.group[ group ];
			for ( j = 0; j < pg->portals; j++ )
			{
				bp = &pg->portal[ j ];
				if ( DotProduct( &bp->normal, MoveOffset ) < 0.0F )
				{
					d = epos.x * bp->normal.x + epos.y * bp->normal.y + epos.z * bp->normal.z + bp->offset;
					if ( fabs( d ) < POINT_ON_PORTAL_TOLERANCE )
					{
						if ( PISDistRecursive( &epos, bp->bsp.Root ) )
						{
							hit_portal = TRUE;
							next_group = bp->group;
							pmove.x += ppos.x - epos.x;
							pmove.y += ppos.y - epos.y;
							pmove.z += ppos.z - epos.z;
							ppos = epos;
							break;
						}
					}
				}
			}
		}
		if ( hit_portal )
		{
			if ( Bsp_Portal_Header.state || (float) fabs( dist_bg - dist_portal ) < 0.1F )
			{
				hit_bg = FALSE;
			}
			else if ( dist_bg < dist_portal )
			{
				hit_bg = TRUE;
				hit_portal = FALSE;
				dv = *MoveOffset;
				NormaliseVector( &dv );
				impact_dotp = -( dv.x * fnorm.nx + dv.y * fnorm.ny + dv.z * fnorm.nz );
				impact_offset = ( impact_dotp ) ? COLLISION_FUDGE / impact_dotp : 2.0F * dist_bg;
				if ( dist_bg > impact_offset )
				{
					epos.x -= dv.x * impact_offset;
					epos.y -= dv.y * impact_offset;
					epos.z -= dv.z * impact_offset;
					*EndGroup = group;
				}
				else
				{
					epos = *StartPos;
					*EndGroup = StartGroup;
				}
				*EndPos = epos;
				*FaceNormal = fnorm;
				*NewTarget = tpos;
			}
		}
		else
		{
			hit_bg = TRUE;
			dv = *MoveOffset;
			NormaliseVector( &dv );
			impact_dotp = -( dv.x * fnorm.nx + dv.y * fnorm.ny + dv.z * fnorm.nz );
			impact_offset = ( impact_dotp ) ? COLLISION_FUDGE / impact_dotp : 2.0F * dist_bg;
			if ( dist_bg > impact_offset )
			{
				epos.x -= dv.x * impact_offset;
				epos.y -= dv.y * impact_offset;
				epos.z -= dv.z * impact_offset;
	 			*EndGroup = group;
			}
			else
			{
				epos = *StartPos;
				*EndGroup = StartGroup;
			}
 			*EndGroup = group;
			*EndPos = epos;
			*FaceNormal = fnorm;
			*NewTarget = tpos;
		}
	}
//	if ( no_collision )
//		hit_bg = FALSE;
	if ( !hit_bg )
	{
		if ( hit_portal )
		{
			*EndGroup = next_group;
			*EndPos = ppos;
		}
		else
		{
			*EndGroup = group;
			EndPos->x = StartPos->x + MoveOffset->x;
			EndPos->y = StartPos->y + MoveOffset->y;
			EndPos->z = StartPos->z + MoveOffset->z;
		}
	}
	return hit_bg;
}

#endif // BSP_ONLY

/*
 * MoveGroup
 *
 * Description
 *	checks for portal collisions of a point moving between two positions
 *
 * Inputs
 *	m			=	background display model
 *	StartPos	=	start position
 *	StartGroup	=	group start position is in
 *	MoveOffset	=	movement offset
 *
 * Outputs
 *	None
 *
 * Returns
 *	EndGroup	=	group final position is in
 */
uint16 MoveGroup( MLOADHEADER *m, VECTOR *StartPos, uint16 StartGroup, VECTOR *MoveOffset )
#ifdef BSP_ONLY
{
	VECTOR ppos, pmove, epos;
	NORMAL pnorm;
	uint16 group;
	uint16 next_group;
	BOOL hit_portal;
	VECTOR dv;

	next_group = StartGroup;
	ppos = *StartPos;
	pmove = *MoveOffset;
	do {
		group = next_group;
		hit_portal = FALSE;
		if ( OneGroupPortalCol( m, group, &ppos, &pmove, &epos, &pnorm, &next_group, 0 ) )
		{
			hit_portal = TRUE;
			pmove.x += ppos.x - epos.x;
			pmove.y += ppos.y - epos.y;
			pmove.z += ppos.z - epos.z;
			ppos = epos;
		}
	} while ( hit_portal );

	dv.x = (float) fabs( StartPos->x + MoveOffset->x - m->Group[ group ].center.x );
	dv.y = (float) fabs( StartPos->y + MoveOffset->y - m->Group[ group ].center.y );
	dv.z = (float) fabs( StartPos->z + MoveOffset->z - m->Group[ group ].center.z );
	outside_group = dv.x > m->Group[ group ].half_size.x + OUTSIDE_GROUP_TOLERANCE ||
					dv.y > m->Group[ group ].half_size.y + OUTSIDE_GROUP_TOLERANCE ||
					dv.z > m->Group[ group ].half_size.z + OUTSIDE_GROUP_TOLERANCE;

	return group;
}
#else !BSP_ONLY
{
	VECTOR ppos, pmove, epos;
	NORMAL pnorm;
	uint16 group;
	uint16 next_group;
	BOOL hit_portal;
	VECTOR dv;

#ifdef NO_SEPARATE_BSP_PORTAL_COLLIDE
	if ( Bsp_Portal_Header.state )
	{
		BackgroundCollide( &MCloadheadert0, &Mloadheader, StartPos, StartGroup, MoveOffset,
			&epos, &group, &pnorm, &dv, FALSE, NULL );
	}
	else
#endif
	{
		next_group = StartGroup;
		ppos = *StartPos;
		pmove = *MoveOffset;
		do {
			group = next_group;
			hit_portal = FALSE;
			if ( OneGroupPortalCol( m, group, &ppos, &pmove, &epos, &pnorm, &next_group, 0 ) )
			{
				hit_portal = TRUE;
				pmove.x += ppos.x - epos.x;
				pmove.y += ppos.y - epos.y;
				pmove.z += ppos.z - epos.z;
				ppos = epos;
			}
		} while ( hit_portal );
	}

	dv.x = (float) fabs( StartPos->x + MoveOffset->x - m->Group[ group ].center.x );
	dv.y = (float) fabs( StartPos->y + MoveOffset->y - m->Group[ group ].center.y );
	dv.z = (float) fabs( StartPos->z + MoveOffset->z - m->Group[ group ].center.z );
	outside_group = dv.x > m->Group[ group ].half_size.x + OUTSIDE_GROUP_TOLERANCE ||
					dv.y > m->Group[ group ].half_size.y + OUTSIDE_GROUP_TOLERANCE ||
					dv.z > m->Group[ group ].half_size.z + OUTSIDE_GROUP_TOLERANCE;

	return group;
}
#endif !BSP_ONLY


/*�������������������������������������������������������������������
	Procedure	:	Does the collision between a specified group
	Input		:	MCLOADHEADER *
				:	MLOADHEADER *
				:	uint16 group
				:	VECTOR * Pos
				:	VECTOR * Dir
				:	VECTOR * ImpactPoint
				:	NORMAL * FaceNormal
				:	VECTOR * Pos_New
				:	BOOL	BGCol
  Output		:	BOOL
�������������������������������������������������������������������*/
BOOL OneGroupPolyCol( MCLOADHEADER * MCloadheaderp ,MLOADHEADER * Mloadheader , uint16 group ,
					 VECTOR * Pos, VECTOR * Dir  ,
					 VECTOR * ImpactPoint , NORMAL  * FaceNormal , VECTOR * Pos_New, BOOL BGCol, BGOBJECT ** BGColObject )
#ifdef BSP_ONLY
{
#ifdef POLYGONAL_COLLISIONS
	MCFACE	*	FacePnt;
	int			num_faces;
#endif
	MCFACE	*	CollFace;
	float		Distance;
	float		D;
	VECTOR		Dn;
	float		C;
	VECTOR		e;
	float		nDOTe;
	int			collided = 0;

	VECTOR		ImpactNormal;
	float		ImpactOffset;
	MCFACE		BSPFace;
	
	if( group == (uint16) -1)
		return FALSE;

	Origin.x = Pos->x;
	Origin.y = Pos->y;
	Origin.z = Pos->z;
	ODir.x = Dir->x;
	ODir.y = Dir->y;
	ODir.z = Dir->z;

	if( (MCloadheaderp == &MCloadheadert0) && Bsp_Header[ 0 ].State )
	{
		CollisionRadius = 0.0F;
		ImpactPoint->x = 0.0F;
		ImpactPoint->y = 0.0F;
		ImpactPoint->z = 0.0F;
		collided = RayCollide( &Bsp_Header[ 0 ], &Origin, &ODir, ImpactPoint, &ImpactNormal, &ImpactOffset , group );
		if ( collided )
		{
			e.x = ImpactPoint->x - Pos->x;
			e.y = ImpactPoint->y - Pos->y;
			e.z = ImpactPoint->z - Pos->z;
			Distance = VectorLength( &e );
			BSPFace.nx = ImpactNormal.x;
			BSPFace.ny = ImpactNormal.y;
			BSPFace.nz = ImpactNormal.z;
			BSPFace.D = ImpactOffset;
			CollFace = &BSPFace;
		}
	}
	else if( (MCloadheaderp == &MCloadheader) && Bsp_Header[ 1 ].State )
	{
		CollisionRadius = 0.0F;
		collided = RayCollide( &Bsp_Header[ 1 ], &Origin, &ODir, ImpactPoint, &ImpactNormal, &ImpactOffset , group );
		if ( collided )
		{
			e.x = ImpactPoint->x - Pos->x;
			e.y = ImpactPoint->y - Pos->y;
			e.z = ImpactPoint->z - Pos->z;
			Distance = VectorLength( &e );
			BSPFace.nx = ImpactNormal.x;
			BSPFace.ny = ImpactNormal.y;
			BSPFace.nz = ImpactNormal.z;
			BSPFace.D = ImpactOffset;
			CollFace = &BSPFace;
		}
	}
	else
	{
		static int not_bsp = 0;

		if ( !not_bsp++ )
		{
			Msg( "Polygonal collisions still being used -- THIS WILL FAIL!" );
		}

#ifdef POLYGONAL_COLLISIONS
		FacePnt = MCloadheaderp->GroupFacePnt[group];
		num_faces = MCloadheaderp->num_of_faces_in_group[group];
		
		while ( num_faces-- )
		{
			if( ColRayPolyIntersect( FacePnt ) )
			{
				if ( !collided )
				{
					Distance = IDist;
					*ImpactPoint = IPoint;
					CollFace = FacePnt;
				}
				else
				{
					if ( IDist < Distance )
					{
						Distance = IDist;
						*ImpactPoint = IPoint;
						CollFace = FacePnt;
					}
				}
				collided++;
			}
			FacePnt++;
		}

		if( collided )
			Distance *= VectorLength( &ODir );
#endif // POLYGONAL_COLLISIONS
	}

#if ENABLE_RESTART
	if( CheckRestartPointCol( group, Distance, ImpactPoint, collided, Pos_New, FaceNormal, BGColObject ) )
	{
		collided += ColCollided;
		e.x = ( ImpactPoint->x - Pos->x );
		e.y = ( ImpactPoint->y - Pos->y );
		e.z = ( ImpactPoint->z - Pos->z );
		Distance = VectorLength( &e );
		BSPFace.nx = FaceNormal->nx;
		BSPFace.ny = FaceNormal->ny;
		BSPFace.nz = FaceNormal->nz;
		BSPFace.D = -DotProduct( (VECTOR *) FaceNormal, ImpactPoint );
		CollFace = &BSPFace;
	}
#endif

	if( BGCol )
	{
		if( MCloadheaderp == &MCloadheadert0 ) ColRadius = 0.0F;
		if( MCloadheaderp == &MCloadheader ) ColRadius = ( 300.0F * GLOBAL_SCALE );

#if ENABLEENEMYCOLLISIONS
		if( CheckEnemyPolyCol( group, Distance, ImpactPoint, collided, Pos_New, FaceNormal, BGColObject ) )
		{
			collided += ColCollided;
			e.x = ( ImpactPoint->x - Pos->x );
			e.y = ( ImpactPoint->y - Pos->y );
			e.z = ( ImpactPoint->z - Pos->z );
			Distance = VectorLength( &e );
			BSPFace.nx = FaceNormal->nx;
			BSPFace.ny = FaceNormal->ny;
			BSPFace.nz = FaceNormal->nz;
			BSPFace.D = -DotProduct( (VECTOR *) FaceNormal, ImpactPoint );
			CollFace = &BSPFace;
		}
#endif

		if( CheckBGObjectsCol( group, Distance, ImpactPoint, collided, Pos_New, FaceNormal, BGColObject ) )
		{
			CompEnemyHit = (uint16) -1;
			AnyCompEnemyHit = (uint16) -1;
			collided += ColCollided;
			e.x = ( ImpactPoint->x - Pos->x );
			e.y = ( ImpactPoint->y - Pos->y );
			e.z = ( ImpactPoint->z - Pos->z );
			Distance = VectorLength( &e );
			BSPFace.nx = FaceNormal->nx;
			BSPFace.ny = FaceNormal->ny;
			BSPFace.nz = FaceNormal->nz;
			BSPFace.D = -DotProduct( (VECTOR *) FaceNormal, ImpactPoint );
			CollFace = &BSPFace;
		}
		else
		{
			if( !collided ) return (FALSE);
		   	
			FaceNormal->nx = CollFace->nx;
			FaceNormal->ny = CollFace->ny;
			FaceNormal->nz = CollFace->nz;
			C = CollFace->D;
		   	
			e.x = Pos->x + Dir->x;	
			e.y = Pos->y + Dir->y;	
			e.z = Pos->z + Dir->z;	
		   	
			nDOTe =	( ( e.x * FaceNormal->nx ) + ( e.y * FaceNormal->ny ) + ( e.z * FaceNormal->nz ) ) + C;
		   		
			D = ( (float) fabs(nDOTe) ) + COLLISION_FUDGE ; 
		   	
			Dn.x = D * FaceNormal->nx; 
			Dn.y = D * FaceNormal->ny; 
			Dn.z = D * FaceNormal->nz; 
		   	
			Pos_New->x = e.x + Dn.x;
			Pos_New->y = e.y + Dn.y;
			Pos_New->z = e.z + Dn.z;
		}
	}
	else
	{
		if( !collided ) return (FALSE);
	   	
		FaceNormal->nx = CollFace->nx;
		FaceNormal->ny = CollFace->ny;
		FaceNormal->nz = CollFace->nz;
		C = CollFace->D;
	   	
		e.x = Pos->x + Dir->x;	
		e.y = Pos->y + Dir->y;	
		e.z = Pos->z + Dir->z;	
	   	
		nDOTe =	( ( e.x * FaceNormal->nx ) + ( e.y * FaceNormal->ny ) + ( e.z * FaceNormal->nz ) ) + C;
	   		
		D = ( (float) fabs(nDOTe) ) + COLLISION_FUDGE ; 
	   	
		Dn.x = D * FaceNormal->nx; 
		Dn.y = D * FaceNormal->ny; 
		Dn.z = D * FaceNormal->nz; 
	   	
		Pos_New->x = e.x + Dn.x;
		Pos_New->y = e.y + Dn.y;
		Pos_New->z = e.z + Dn.z;
	}
	return(TRUE);
}
#else // !BSP_ONLY
{
	MCFACE	*	FacePnt;
	MCFACE	*	CollFace;
	int			num_faces;
	float		Distance;
	float		D;
	VECTOR		Dn;
	float		C;
	VECTOR		e;
	float		nDOTe;
	int			collided = 0;

#if BSP_ENABLE
	VECTOR		ImpactNormal;
	float		ImpactOffset;
	MCFACE		BSPFace;
#endif
	
	if( group == (uint16) -1)
		return FALSE;

	Origin.x = Pos->x;
	Origin.y = Pos->y;
	Origin.z = Pos->z;
	ODir.x = Dir->x;
	ODir.y = Dir->y;
	ODir.z = Dir->z;

#if BSP_ENABLE
	if( (MCloadheaderp == &MCloadheadert0) && Bsp_Header[ 0 ].State )
	{
		CollisionRadius = 0.0F;
		ImpactPoint->x = 0.0F;
		ImpactPoint->y = 0.0F;
		ImpactPoint->z = 0.0F;
		collided = RayCollide( &Bsp_Header[ 0 ], &Origin, &ODir, ImpactPoint, &ImpactNormal, &ImpactOffset , group );
		if ( collided )
		{
			e.x = ImpactPoint->x - Pos->x;
			e.y = ImpactPoint->y - Pos->y;
			e.z = ImpactPoint->z - Pos->z;
			Distance = VectorLength( &e );
			BSPFace.nx = ImpactNormal.x;
			BSPFace.ny = ImpactNormal.y;
			BSPFace.nz = ImpactNormal.z;
			BSPFace.D = ImpactOffset;
			CollFace = &BSPFace;
		}
	}
#ifdef BSP2
	else if( (MCloadheaderp == &MCloadheader) && Bsp_Header[ 0 ].State )
	{
		CollisionRadius = 75.0F;
		collided = RayCollide( &Bsp_Header[ 0 ], &Origin, &ODir, ImpactPoint, &ImpactNormal, &ImpactOffset , group );
#else
	else if( (MCloadheaderp == &MCloadheader) && Bsp_Header[ 1 ].State )
	{
		CollisionRadius = 0.0F;
		collided = RayCollide( &Bsp_Header[ 1 ], &Origin, &ODir, ImpactPoint, &ImpactNormal, &ImpactOffset , group );
#endif
		if ( collided )
		{
			e.x = ImpactPoint->x - Pos->x;
			e.y = ImpactPoint->y - Pos->y;
			e.z = ImpactPoint->z - Pos->z;
			Distance = VectorLength( &e );
			BSPFace.nx = ImpactNormal.x;
			BSPFace.ny = ImpactNormal.y;
			BSPFace.nz = ImpactNormal.z;
			BSPFace.D = ImpactOffset;
			CollFace = &BSPFace;
		}
	}
	else
#if 0
	{
		CollisionRadius = 0.0;
		collided = RayCollide( &Origin, &ODir, ImpactPoint, &ImpactNormal, &ImpactOffset , group );
		if ( collided )
		{
			e.x = ImpactPoint->x - Pos->x;
			e.y = ImpactPoint->y - Pos->y;
			e.z = ImpactPoint->z - Pos->z;
			Distance = VectorLength( &e );
			BSPFace.nx = ImpactNormal.x;
			BSPFace.ny = ImpactNormal.y;
			BSPFace.nz = ImpactNormal.z;
			BSPFace.D = ImpactOffset;
			CollFace = &BSPFace;
		}
	}
#endif
#endif

#if 1	
	{

		FacePnt = MCloadheaderp->GroupFacePnt[group];
		num_faces = MCloadheaderp->num_of_faces_in_group[group];
		
		while ( num_faces-- )
		{
			if( ColRayPolyIntersect( FacePnt ) )
			{
				if ( !collided )
				{
					Distance = IDist;
					*ImpactPoint = IPoint;
					CollFace = FacePnt;
				}
				else
				{
					if ( IDist < Distance )
					{
						Distance = IDist;
						*ImpactPoint = IPoint;
						CollFace = FacePnt;
					}
				}
				collided++;
			}
			FacePnt++;
		}

		if( collided )
			Distance *= VectorLength( &ODir );
	}
#endif

	if( BGCol )
	{
		if( MCloadheaderp == &MCloadheadert0 ) ColRadius = 0.0F;
		if( MCloadheaderp == &MCloadheader ) ColRadius = ( 300.0F * GLOBAL_SCALE );

		if( CheckBGObjectsCol( group, Distance, ImpactPoint, collided, Pos_New, FaceNormal, BGColObject ) )
		{
			collided += ColCollided;
			e.x = ( ImpactPoint->x - Pos->x );
			e.y = ( ImpactPoint->y - Pos->y );
			e.z = ( ImpactPoint->z - Pos->z );
			Distance = VectorLength( &e );
			BSPFace.nx = FaceNormal->nx;
			BSPFace.ny = FaceNormal->ny;
			BSPFace.nz = FaceNormal->nz;
			BSPFace.D = -DotProduct( (VECTOR *) FaceNormal, ImpactPoint );
			CollFace = &BSPFace;
		}
		else
		{
			if( !collided ) return (FALSE);
		   	
			FaceNormal->nx = CollFace->nx;
			FaceNormal->ny = CollFace->ny;
			FaceNormal->nz = CollFace->nz;
			C = CollFace->D;
		   	
			e.x = Pos->x + Dir->x;	
			e.y = Pos->y + Dir->y;	
			e.z = Pos->z + Dir->z;	
		   	
			nDOTe =	( ( e.x * FaceNormal->nx ) + ( e.y * FaceNormal->ny ) + ( e.z * FaceNormal->nz ) ) + C;
		   		
			D = ( (float) fabs(nDOTe) ) + COLLISION_FUDGE ; 
		   	
			Dn.x = D * FaceNormal->nx; 
			Dn.y = D * FaceNormal->ny; 
			Dn.z = D * FaceNormal->nz; 
		   	
			Pos_New->x = e.x + Dn.x;
			Pos_New->y = e.y + Dn.y;
			Pos_New->z = e.z + Dn.z;
		}
	}
	else
	{
		if( !collided ) return (FALSE);
	   	
		FaceNormal->nx = CollFace->nx;
		FaceNormal->ny = CollFace->ny;
		FaceNormal->nz = CollFace->nz;
		C = CollFace->D;
	   	
		e.x = Pos->x + Dir->x;	
		e.y = Pos->y + Dir->y;	
		e.z = Pos->z + Dir->z;	
	   	
		nDOTe =	( ( e.x * FaceNormal->nx ) + ( e.y * FaceNormal->ny ) + ( e.z * FaceNormal->nz ) ) + C;
	   		
		D = ( (float) fabs(nDOTe) ) + COLLISION_FUDGE ; 
	   	
		Dn.x = D * FaceNormal->nx; 
		Dn.y = D * FaceNormal->ny; 
		Dn.z = D * FaceNormal->nz; 
	   	
		Pos_New->x = e.x + Dn.x;
		Pos_New->y = e.y + Dn.y;
		Pos_New->z = e.z + Dn.z;
	}
	return(TRUE);
}
#endif // !BSP_ONLY


/*�������������������������������������������������������������������
	Procedure	:	Does the collision between the portals in a specified group
	Input		:	MLOADHEADER *
				:	uint16 group
				:	VECTOR * Pos
				:	VECTOR * Dir
				:	VECTOR * ImpactPoint
				:	NORMAL * FaceNormal
				:	uint16 * PortalHit
  Output		:	BOOL
�������������������������������������������������������������������*/
BOOL OneGroupPortalCol( MLOADHEADER * Mloadheader , uint16 group ,
						VECTOR * Pos, VECTOR * Dir  ,
						VECTOR * ImpactPoint , NORMAL * FaceNormal, uint16 *Next_Group,
						int collisionhint )
#ifdef BSP_ONLY
{
	float		Distance;
	uint16		flag = 0;	
	BOOL		res;
	float		SkinThickness = 300.0F * GLOBAL_SCALE;
	BSP_PORTAL_GROUP	*pg;
	BSP_PORTAL			*bp;
	int					j;
	
	if( group == (uint16) -1)
		return FALSE;

	Origin.x = Pos->x;
	Origin.y = Pos->y;
	Origin.z = Pos->z;
	ODir.x = Dir->x;
	ODir.y = Dir->y;
	ODir.z = Dir->z;

	pg = &Bsp_Portal_Header.group[ group ];
	for ( j = 0; j < pg->portals; j++ )
	{
		bp = &pg->portal[ j ];
		res = ColRayPlaneIntersect( &bp->normal, bp->offset );
		if( res == TRUE )
		{
			if ( PISDistRecursive( &IPoint, bp->bsp.Root ) )
			{
				if ( flag == 0 )
				{
					Distance = IDist;
					ImpactPoint->x = IPoint.x;
					ImpactPoint->y = IPoint.y;
					ImpactPoint->z = IPoint.z;
					FaceNormal->nx = bp->normal.x;
					FaceNormal->ny = bp->normal.y;
					FaceNormal->nz = bp->normal.z;
					hit_portal_offset = bp->offset;
					*Next_Group = bp->group;
					flag = 1;
				}else{
					if ( IDist < Distance )
					{
						Distance = IDist;
						ImpactPoint->x = IPoint.x;
						ImpactPoint->y = IPoint.y;
						ImpactPoint->z = IPoint.z;
						FaceNormal->nx = bp->normal.x;
						FaceNormal->ny = bp->normal.y;
						FaceNormal->nz = bp->normal.z;
						hit_portal_offset = bp->offset;
						*Next_Group = bp->group;
					}
				}
			}
		}
	}

	return ( flag ) ? TRUE : FALSE;
}
#else !BSP_ONLY
{
	PORTAL	*	PortalPnt;
	uint16		i;
	float		Distance;
	uint16		flag = 0;	
	BOOL		res;
	float		SkinThickness = 300.0F * GLOBAL_SCALE;
	int			k;
	
	Origin.x = Pos->x;
	Origin.y = Pos->y;
	Origin.z = Pos->z;
	ODir.x = Dir->x;
	ODir.y = Dir->y;
	ODir.z = Dir->z;

	if( group == (uint16) -1)
		return FALSE;

	if ( Bsp_Portal_Header.state )
	{
		BSP_PORTAL_GROUP	*pg;
		BSP_PORTAL			*bp;
		int					j;
		
		pg = &Bsp_Portal_Header.group[ group ];
		for ( j = 0; j < pg->portals; j++ )
		{
			bp = &pg->portal[ j ];
			res = ColRayPlaneIntersect( &bp->normal, bp->offset );
			if( res == TRUE )
			{
				if ( PISDistRecursive( &IPoint, bp->bsp.Root ) )
				{
					if ( flag == 0 )
					{
						Distance = IDist;
						ImpactPoint->x = IPoint.x;
						ImpactPoint->y = IPoint.y;
						ImpactPoint->z = IPoint.z;
						FaceNormal->nx = bp->normal.x;
						FaceNormal->ny = bp->normal.y;
						FaceNormal->nz = bp->normal.z;
						hit_portal_offset = bp->offset;
						*Next_Group = bp->group;
						flag = 1;
					}else{
						if ( IDist < Distance )
						{
							Distance = IDist;
							ImpactPoint->x = IPoint.x;
							ImpactPoint->y = IPoint.y;
							ImpactPoint->z = IPoint.z;
							FaceNormal->nx = bp->normal.x;
							FaceNormal->ny = bp->normal.y;
							FaceNormal->nz = bp->normal.z;
							hit_portal_offset = bp->offset;
							*Next_Group = bp->group;
						}
					}
				}
			}
		}
	}
	else
	{
		PortalPnt = Mloadheader->Group[group].Portal;
		
		for ( i = 0 ; i < Mloadheader->Group[group].num_portals ; i++ )
		{
			for ( k = 0; k < PortalPnt->num_polys_in_portal; k++ )
			{
				res = ColRayPolyIntersect( &PortalPnt->Poly[ k ] );
				if( res == TRUE )
				{
					if ( flag == 0 )
					{
						Distance = IDist;
						ImpactPoint->x = IPoint.x;
						ImpactPoint->y = IPoint.y;
						ImpactPoint->z = IPoint.z;
						FaceNormal->nx = PortalPnt->Poly[ k ].nx;
						FaceNormal->ny = PortalPnt->Poly[ k ].ny;
						FaceNormal->nz = PortalPnt->Poly[ k ].nz;
						hit_portal_offset = PortalPnt->Poly[ k ].D;
						*Next_Group = PortalPnt->visible.group;
						flag = 1;
					}else{
						if ( IDist < Distance )
						{
							Distance = IDist;
							ImpactPoint->x = IPoint.x;
							ImpactPoint->y = IPoint.y;
							ImpactPoint->z = IPoint.z;
							FaceNormal->nx = PortalPnt->Poly[ k ].nx;
							FaceNormal->ny = PortalPnt->Poly[ k ].ny;
							FaceNormal->nz = PortalPnt->Poly[ k ].nz;
							hit_portal_offset = PortalPnt->Poly[ k ].D;
							*Next_Group = PortalPnt->visible.group;
						}
					}
				}
			}
			
			PortalPnt++;
		}
	}
#ifdef A_BAD_IDEA_AND_DOESNT_WORK_ANYWAY
	if ( flag )
	{
		VECTOR		NDir;
		float		offset;

		NDir = *Dir;
		NormaliseVector( &NDir );
		offset = PORTAL_IMPACTOFFSET / -DotProduct( &NDir, (VECTOR *)FaceNormal ); // this gets bigger the narrower the angle between the portal and the ray
		ImpactPoint->x += NDir.x * offset;
		ImpactPoint->y += NDir.y * offset;
		ImpactPoint->z += NDir.z * offset;
	}
#endif

	return ( flag ) ? TRUE : FALSE;
}
#endif // !BSP_ONLY


static void
CalcNormal( VERT *v0, VERT *v1, VERT *v2, NORMAL *normal )
{
	VECTOR	d1;
	VECTOR	d2;

	d1.x = v2->x - v1->x;
	d1.y = v2->y - v1->y;
	d1.z = v2->z - v1->z;
	d2.x = v0->x - v1->x;
	d2.y = v0->y - v1->y;
	d2.z = v0->z - v1->z;
	CrossProduct( &d1, &d2, (VECTOR *) normal );
	NormaliseVector( (VECTOR *) normal );
}

BOOL AmIOutsideGroup( MLOADHEADER * m, VECTOR * EndPos, uint16 EndGroup )
{
	VECTOR	dv;

	dv.x = (float) fabs( EndPos->x - m->Group[ EndGroup ].center.x );
	dv.y = (float) fabs( EndPos->y - m->Group[ EndGroup ].center.y );
	dv.z = (float) fabs( EndPos->z - m->Group[ EndGroup ].center.z );
	return( dv.x > m->Group[ EndGroup ].half_size.x + OUTSIDE_GROUP_TOLERANCE ||
			dv.y > m->Group[ EndGroup ].half_size.y + OUTSIDE_GROUP_TOLERANCE ||
			dv.z > m->Group[ EndGroup ].half_size.z + OUTSIDE_GROUP_TOLERANCE );
}

static BGOBJECT	*	CurParent = NULL;

/*�������������������������������������������������������������������
	Procedure	:	Check Ship to Background Objects Collision
	Input		:	uint16	Group
	Output		:	Nothing
�������������������������������������������������������������������*/
BOOL CheckBGObjectsCol( uint16 Group, float Distance, VECTOR * ImpactPoint,
					  int collided, VECTOR * New_Pos, NORMAL * FaceNormal, BGOBJECT ** BGObject )
{
	float			D;
	VECTOR			Dn;
	float			C;
	VECTOR			e;
	float			nDOTe;
	BGOBJECT	*	Object;
	VECTOR			NormDir;
	float			RayLength;

	ColDist = Distance;
	ColChild = NULL;
	ColCollided = collided;
	NormDir = ODir;
	RayLength = VectorLength( &NormDir );
	NormaliseVector( &NormDir );

	Object = FirstBGObjectUsed;

	while( Object != NULL )
	{
		CurParent = Object;

		if( !SoundInfo[ Object->Group ][ Group ] )
		{
			if( Object->NumChildren && Object->Children )
			{
				if( RaytoSphereShort( &Object->ColCenter, ( Object->ColRadius + ( SHIP_RADIUS * 1.5F ) ), &Origin, &NormDir, RayLength ) )
				{
					CollideBGOChildren( Object->Children, Object->NumChildren );
				}
			}
		}

		Object = Object->NextUsed;
	}

	if( ColChild )
	{
		if( BGObject  )
		{
			if( ColChild->ColZones[ ColZoneNum ].Sensitive )
			{
				*BGObject = ColParent;
			}
			else
			{
				if( ColSide->Sensitive )
				{
					*BGObject = ColParent;
				}
				else
				{
					*BGObject = NULL;
				}
			}
		}

		ApplyMatrix( &ColChild->DisplayMatrix, &ColPoint, ImpactPoint );
		ImpactPoint->x += ColChild->DisplayPos.x;
		ImpactPoint->y += ColChild->DisplayPos.y;
		ImpactPoint->z += ColChild->DisplayPos.z;
		ApplyMatrix( &ColChild->DisplayMatrix, &ColSide->Normal, (VECTOR *) FaceNormal );

		C = -( ( FaceNormal->nx * ImpactPoint->x ) + ( FaceNormal->ny * ImpactPoint->y ) + ( FaceNormal->nz * ImpactPoint->z ) );

		e.x = Origin.x + ODir.x;	
		e.y = Origin.y + ODir.y;	
		e.z = Origin.z + ODir.z;	
	
		nDOTe =	( ( e.x * FaceNormal->nx ) + ( e.y * FaceNormal->ny ) + ( e.z * FaceNormal->nz ) ) + C;
		
		D = ( (float) fabs(nDOTe) ) + COLLISION_FUDGE ; 
	
		Dn.x = D * FaceNormal->nx; 
		Dn.y = D * FaceNormal->ny; 
		Dn.z = D * FaceNormal->nz; 
	
		New_Pos->x = e.x + Dn.x;
		New_Pos->y = e.y + Dn.y;
		New_Pos->z = e.z + Dn.z;
		return( TRUE );
	}
	else
	{
		if( BGObject )
		{
			*BGObject = NULL;
		}
	}

	return( FALSE );
}

/*�������������������������������������������������������������������
	Procedure	:	Check Ship to RestartPoints Collision
	Input		:	uint16		Group
				:	float		Distance to intersection
				:	VECTOR	*	ImpactPoint
				:	int			collided
				:	VECTOR	*	New_Pos
				:	NORMAL	*	Collision Normal
				:	BGOBJECT ** Bgobject
	Output		:	BOOL		True/False
�������������������������������������������������������������������*/
BOOL CheckRestartPointCol( uint16 Group, float Distance, VECTOR * ImpactPoint,
					  int collided, VECTOR * New_Pos, NORMAL * FaceNormal, BGOBJECT ** BGObject )
{
	float			D;
	VECTOR			Dn;
	float			C;
	VECTOR			e;
	float			nDOTe;

	RESTART		*	Object;

	ColDist = Distance;
	ColChild = NULL;
	ColCollided = collided;
	CurParent = NULL;

	Object = FirstRestartUsed;

	while( Object != NULL )
	{
		if( !SoundInfo[ Object->Group ][ Group ] )
		{
			if( Object->Components )
			{
				CollideBGOChildren( Object->Components, 1 );
			}
		}

		Object = Object->NextUsed;
	}

	if( ColChild )
	{
		ApplyMatrix( &ColChild->DisplayMatrix, &ColPoint, ImpactPoint );
		ImpactPoint->x += ColChild->DisplayPos.x;
		ImpactPoint->y += ColChild->DisplayPos.y;
		ImpactPoint->z += ColChild->DisplayPos.z;
		ApplyMatrix( &ColChild->DisplayMatrix, &ColSide->Normal, (VECTOR *) FaceNormal );

		C = -( ( FaceNormal->nx * ImpactPoint->x ) + ( FaceNormal->ny * ImpactPoint->y ) + ( FaceNormal->nz * ImpactPoint->z ) );

		e.x = Origin.x + ODir.x;	
		e.y = Origin.y + ODir.y;	
		e.z = Origin.z + ODir.z;	
	
		nDOTe =	( ( e.x * FaceNormal->nx ) + ( e.y * FaceNormal->ny ) + ( e.z * FaceNormal->nz ) ) + C;
		
		D = ( (float) fabs(nDOTe) ) + COLLISION_FUDGE ; 
	
		Dn.x = D * FaceNormal->nx; 
		Dn.y = D * FaceNormal->ny; 
		Dn.z = D * FaceNormal->nz; 
	
		New_Pos->x = e.x + Dn.x;
		New_Pos->y = e.y + Dn.y;
		New_Pos->z = e.z + Dn.z;
		return( TRUE );
	}

	if( BGObject )
	{
		*BGObject = NULL;
	}

	return( FALSE );
}

/*�������������������������������������������������������������������
	Procedure	:	Check Ray to Enemy Polygonal Collision
	Input		:	uint16		Group
				:	float		Distance to intersection
				:	VECTOR	*	ImpactPoint
				:	int			collided
				:	VECTOR	*	New_Pos
				:	NORMAL	*	Collision Normal
				:	BGOBJECT ** Bgobject
	Output		:	BOOL		True/False
�������������������������������������������������������������������*/
BOOL CheckEnemyPolyCol( uint16 Group, float Distance, VECTOR * ImpactPoint,
					  int collided, VECTOR * New_Pos, NORMAL * FaceNormal, BGOBJECT ** BGObject )
{
	float			D;
	VECTOR			Dn;
	float			C;
	VECTOR			e;
	float			nDOTe;
	ENEMY		*	Object;
	int				OldColCollided;
	uint16			EnemyHit = (uint16) -1;

	ColDist = Distance;
	ColChild = NULL;
	ColCollided = collided;
	CurParent = NULL;

	Object = FirstEnemyUsed;

	while( Object != NULL )
	{
		if( ( Object->Status & ENEMY_STATUS_Enable ) && ( Object->CompCollision == COMPONENTCOLLISION ) )
		{
			if( Object->Type == ENEMY_Boss_Avatar )
			{
				if( !IsAvatarActive() )
					goto SkipIt;
			}

			if( !SoundInfo[ Object->Object.Group ][ Group ] )
			{
				if( Object->Object.Components )
				{
					OldColCollided = ColCollided;

					CollideBGOChildren( Object->Object.Components, 1 );

					if( OldColCollided != ColCollided )
					{
						EnemyHit = Object->Index;
					}
				}
			}
		}

SkipIt:
		Object = Object->NextUsed;
	}

	if( ColChild )
	{
		ApplyMatrix( &ColChild->DisplayMatrix, &ColPoint, ImpactPoint );
		ImpactPoint->x += ColChild->DisplayPos.x;
		ImpactPoint->y += ColChild->DisplayPos.y;
		ImpactPoint->z += ColChild->DisplayPos.z;
		ApplyMatrix( &ColChild->DisplayMatrix, &ColSide->Normal, (VECTOR *) FaceNormal );

		C = -( ( FaceNormal->nx * ImpactPoint->x ) + ( FaceNormal->ny * ImpactPoint->y ) + ( FaceNormal->nz * ImpactPoint->z ) );

		e.x = Origin.x + ODir.x;	
		e.y = Origin.y + ODir.y;	
		e.z = Origin.z + ODir.z;	
	
		nDOTe =	( ( e.x * FaceNormal->nx ) + ( e.y * FaceNormal->ny ) + ( e.z * FaceNormal->nz ) ) + C;
		
		D = ( (float) fabs(nDOTe) ) + COLLISION_FUDGE ; 
	
		Dn.x = D * FaceNormal->nx; 
		Dn.y = D * FaceNormal->ny; 
		Dn.z = D * FaceNormal->nz; 
	
		New_Pos->x = e.x + Dn.x;
		New_Pos->y = e.y + Dn.y;
		New_Pos->z = e.z + Dn.z;

		AnyCompEnemyHit = EnemyHit;

		if( ( ColChild->ColZones[ ColZoneNum ].Sensitive ) ||
			( !( ColChild->ColZones[ ColZoneNum ].Sensitive ) && ( ColSide->Sensitive ) ) )
		{
			CompEnemyHit = EnemyHit;
			CompEnemyHitPos.x = ImpactPoint->x;
			CompEnemyHitPos.y = ImpactPoint->y;
			CompEnemyHitPos.z = ImpactPoint->z;
			CompEnemyHitNormal.nx = FaceNormal->nx;
			CompEnemyHitNormal.ny = FaceNormal->ny;
			CompEnemyHitNormal.nz = FaceNormal->nz;
			CompEnemyHitDist = ColDist;
		}
		return( TRUE );
	}

	return( FALSE );
}

/*�������������������������������������������������������������������
	Procedure	:	Process components of Background Object
	Input		:	COMP_OBJ	*	Children
				:	int16			NumChildren
	Output		:	Nothing
�������������������������������������������������������������������*/
void CollideBGOChildren( COMP_OBJ * Children, int16 NumChildren )
{
	int16					Zone;
	int16					Count;
	VECTOR					NewOrigin;
	VECTOR					NewDir;
	VECTOR					NewEnd;
	ANI_ZONES			*	ZonesPtr;
	ANI_ZONE_SPHERE		*	AniZoneSpherePtr;
	ANI_ZONE_BOX		*	AniZoneBoxPtr;
	ANI_ZONE_POLYGONAL	*	AniZonePolyPtr;
	VECTOR					IntPoint;
	ZONESIDE			*	IntSide;
	float					DistToInt;
	VECTOR					TempVector;

	if( Children )
	{
		for( Count = 0; Count < NumChildren; Count++ )
		{
			if( Children->NumColZones && ( Children->Flags & COMPFLAG_Enable ) )
			{
				ApplyMatrix( &Children->InvDisplayMatrix, &ODir, &NewDir );
				NewOrigin.x = ( Origin.x - Children->DisplayPos.x );
				NewOrigin.y = ( Origin.y - Children->DisplayPos.y );
				NewOrigin.z = ( Origin.z - Children->DisplayPos.z );
				ApplyMatrix( &Children->InvDisplayMatrix, &NewOrigin, &NewOrigin );

				NewEnd.x = ( NewOrigin.x + NewDir.x );
				NewEnd.y = ( NewOrigin.y + NewDir.y );
				NewEnd.z = ( NewOrigin.z + NewDir.z );

				ZonesPtr = Children->ColZones;

				for( Zone = 0; Zone < Children->NumColZones; Zone++ )
				{
					switch( ZonesPtr->Type )
					{
						case ZONE_Sphere:
							AniZoneSpherePtr = (ANI_ZONE_SPHERE *) ZonesPtr->Data;
							break;
	
						case ZONE_Box:
							AniZoneBoxPtr = (ANI_ZONE_BOX *) ZonesPtr->Data;

							if( RayToColZone( &NewOrigin, &NewEnd,
											  AniZoneBoxPtr->Sides, AniZoneBoxPtr->NumSides,
											  &IntPoint, &IntSide, ColRadius ) )
							{
								TempVector.x = ( IntPoint.x - NewOrigin.x );
								TempVector.y = ( IntPoint.y - NewOrigin.y );
								TempVector.z = ( IntPoint.z - NewOrigin.z );
								DistToInt = VectorLength( &TempVector );

								if( !ColCollided )
								{
									ColPoint = IntPoint;
									ColSide = IntSide;
									ColDist = DistToInt;
									ColChild = Children;
									ColParent = CurParent;
									ColZoneNum = Zone;
									ColCollided++;
								}
								else
								{
									if( DistToInt < ColDist )
									{
										ColPoint = IntPoint;
										ColSide = IntSide;
										ColDist = DistToInt;
										ColChild = Children;
										ColParent = CurParent;
										ColZoneNum = Zone;
										ColCollided++;
									}
								}

							}
							break;
	
						case ZONE_Polygonal:
							AniZonePolyPtr = (ANI_ZONE_POLYGONAL *) ZonesPtr->Data;

							if( RayToColZone( &NewOrigin, &NewEnd,
											  AniZonePolyPtr->Sides, AniZonePolyPtr->NumSides,
											  &IntPoint, &IntSide, ColRadius ) )
							{
								TempVector.x = ( IntPoint.x - NewOrigin.x );
								TempVector.y = ( IntPoint.y - NewOrigin.y );
								TempVector.z = ( IntPoint.z - NewOrigin.z );
								DistToInt = VectorLength( &TempVector );

								if( !ColCollided )
								{
									ColPoint = IntPoint;
									ColSide = IntSide;
									ColDist = DistToInt;
									ColChild = Children;
									ColParent = CurParent;
									ColZoneNum = Zone;
									ColCollided++;
								}
								else
								{
									if( DistToInt < ColDist )
									{
										ColPoint = IntPoint;
										ColSide = IntSide;
										ColDist = DistToInt;
										ColChild = Children;
										ColZoneNum = Zone;
										ColParent = CurParent;
										ColCollided++;
									}
								}
							}
							break;
					}

					ZonesPtr++;
				}
			}
					
			if( Children->NumChildren )
			{
				CollideBGOChildren( Children->Children, Children->NumChildren );
			}

			Children++;
		}
	}
}

/*�������������������������������������������������������������������
	Procedure	:	Does the collision between a specified group
	Input		:	float		Distance to int
				:	int16		Collided
				:	uint16		group
				:	VECTOR	*	Pos
				:	VECTOR	*	Dir
				:	VECTOR	*	ImpactPoint
				:	NORMAL	*	FaceNormal
				:	VECTOR	*	Pos_New
				:	BGOBJECT **	BGObject collided with
				:	float		Radius
  Output		:	BOOL
�������������������������������������������������������������������*/
BOOL OneGroupBGObjectCol( float Distance, int16 Collided, uint16 Group, VECTOR * Pos, VECTOR * Dir  ,
					 VECTOR * ImpactPoint , NORMAL  * FaceNormal , VECTOR * Pos_New, BGOBJECT ** BGObject, float Radius )
{
#if ENABLEENEMYCOLLISIONS

	int16	ColCount = 0;

	if( Group == (uint16) -1) return FALSE;

	Origin = *Pos;
	ODir = *Dir;
	ColRadius = Radius;
	AnyCompEnemyHit = (uint16) -1;
	CompEnemyHit = (uint16) -1;

	if(	CheckEnemyPolyCol( Group, Distance, ImpactPoint, Collided, Pos_New, FaceNormal, BGObject ) )
	{
		Distance = ColDist;
		ColCount++;
	}

	if( CheckBGObjectsCol( Group, Distance, ImpactPoint, ( Collided + ColCount ), Pos_New, FaceNormal, BGObject ) )
	{
		ColCount++;
	}

	if( !ColCount ) return( FALSE );

#else

	if( Group == (uint16) -1) return FALSE;

	Origin = *Pos;
	ODir = *Dir;
	ColRadius = Radius;

	if( !CheckBGObjectsCol( Group, Distance, ImpactPoint, Collided, Pos_New, FaceNormal, BGObject ) ) return (FALSE);

#endif

	return(TRUE);
}

/*�������������������������������������������������������������������
	Procedure	:	Check Background Objects To Object Collision
	Input		:	VECTOR	*	Pos
				:	BGOBJECT *	Object
				:	VECTOR	*	Push Vector ( TBFI )
				:	float	*	DamagePtr
				:	float		Radius
	Output		:	Nothing
�������������������������������������������������������������������*/
BOOL CheckBGObjectCollision( VECTOR * Pos, BGOBJECT * Object, VECTOR * PushVector, float * DamagePtr, float Radius )
{
	float	Speed;

	ColChild = NULL;
	ColCollided = 0;
	Origin = *Pos;
	ColRadius = Radius;

	if( !PointToSphere( (VERT *) &Object->ColCenter, ( Object->ColRadius +  ( SHIP_RADIUS * 1.5F ) ), (VERT *) Pos ) )
		return( FALSE );

	if( Object->NumChildren && Object->Children )
	{
		CollideBGOToCompObjChildren( Object->Children, Object->NumChildren );

		if( ColChild )
		{
			if( ColChild->ColZones[ ColZoneNum ].Damage )
			{
				*DamagePtr = ColChild->ColZones[ ColZoneNum ].Damage;
			}
			else
			{
				if( ColSide->Damage )
				{
					*DamagePtr = ColSide->Damage;
				}
				else
				{
					*DamagePtr = 0.0F;
				}
			}

			ApplyMatrix( &ColChild->DisplayMatrix, &ColDir, &ColDir );
			PushVector->x = ( ColDir.x * -1.0F );
			PushVector->y = ( ColDir.y * -1.0F );
			PushVector->z = ( ColDir.z * -1.0F );
			Speed = VectorLength( PushVector );
			Speed *= 0.5F;
			NormaliseVector( PushVector );
			PushVector->x *= Speed;
			PushVector->y *= Speed;
			PushVector->z *= Speed;
			return( TRUE );
		}
	}

	return( FALSE );
}

/*�������������������������������������������������������������������
	Procedure	:	Check Background Objects To Enemy Collision
	Input		:	VECTOR	*	Pos
				:	COMP_OBJ *	CompObjects
				:	VECTOR	*	Push Vector ( TBFI )
				:	float	*	DamagePtr
				:	float		Radius
	Output		:	Nothing
�������������������������������������������������������������������*/
BOOL CheckCompObjectCollision( VECTOR * Pos, COMP_OBJ * Comps, VECTOR * PushVector, float * DamagePtr, float Radius )
{
	float	Speed;

	ColChild = NULL;
	ColCollided = 0;
	Origin = *Pos;
	ColRadius = Radius;

	if( Comps )
	{
		CollideBGOToCompObjChildren( Comps, 1 );

		if( ColChild )
		{
			if( ColChild->ColZones[ ColZoneNum ].Damage )
			{
				*DamagePtr = ColChild->ColZones[ ColZoneNum ].Damage;
			}
			else
			{
				if( ColSide->Damage )
				{
					*DamagePtr = ColSide->Damage;
				}
				else
				{
					*DamagePtr = 0.0F;
				}
			}

			ApplyMatrix( &ColChild->DisplayMatrix, &ColDir, &ColDir );
			PushVector->x = ( ColDir.x * -1.0F );
			PushVector->y = ( ColDir.y * -1.0F );
			PushVector->z = ( ColDir.z * -1.0F );
			Speed = VectorLength( PushVector );
			Speed *= 0.5F;
			NormaliseVector( PushVector );
			PushVector->x *= Speed;
			PushVector->y *= Speed;
			PushVector->z *= Speed;
			return( TRUE );
		}
	}

	return( FALSE );
}

/*�������������������������������������������������������������������
	Procedure	:	Process components of Background Object
	Input		:	COMP_OBJ	*	Children
				:	int16			NumChildren
	Output		:	Nothing
�������������������������������������������������������������������*/
void CollideBGOToCompObjChildren( COMP_OBJ * Children, int16 NumChildren )
{
	int16					Zone;
	int16					Count;
	VECTOR					NewOrigin;
	VECTOR					NewDir;
	VECTOR					NewEnd;
	ANI_ZONES			*	ZonesPtr;
	ANI_ZONE_SPHERE		*	AniZoneSpherePtr;
	ANI_ZONE_BOX		*	AniZoneBoxPtr;
	ANI_ZONE_POLYGONAL	*	AniZonePolyPtr;
	VECTOR					IntPoint;
	ZONESIDE			*	IntSide;
	float					DistToInt;
	VECTOR					TempVector;
	VECTOR					OldOrigin;
	float					Length;

	if( Children )
	{
		for( Count = 0; Count < NumChildren; Count++ )
		{
			if( Children->NumColZones && ( Children->Flags & COMPFLAG_Enable ) )
			{
				OldOrigin.x = ( Origin.x - Children->OldDisplayPos.x );
				OldOrigin.y = ( Origin.y - Children->OldDisplayPos.y );
				OldOrigin.z = ( Origin.z - Children->OldDisplayPos.z );
				ApplyMatrix( &Children->OldInvDisplayMatrix, &OldOrigin, &OldOrigin );

				NewOrigin.x = ( Origin.x - Children->DisplayPos.x );
				NewOrigin.y = ( Origin.y - Children->DisplayPos.y );
				NewOrigin.z = ( Origin.z - Children->DisplayPos.z );
				ApplyMatrix( &Children->InvDisplayMatrix, &NewOrigin, &NewOrigin );

				NewDir.x = ( NewOrigin.x - OldOrigin.x );
				NewDir.y = ( NewOrigin.y - OldOrigin.y );
				NewDir.z = ( NewOrigin.z - OldOrigin.z );
	
				NewOrigin = OldOrigin;

				Length = VectorLength( &NewDir );
				if( Length < 0.065F )
				{
					Length = 0.065F;
					NormaliseVector( &NewDir );
					NewDir.x *= Length;
					NewDir.y *= Length;
					NewDir.z *= Length;
				}

				NewEnd.x = ( NewOrigin.x + NewDir.x );
				NewEnd.y = ( NewOrigin.y + NewDir.y );
				NewEnd.z = ( NewOrigin.z + NewDir.z );

				ZonesPtr = Children->ColZones;

				for( Zone = 0; Zone < Children->NumColZones; Zone++ )
				{
					switch( ZonesPtr->Type )
					{
						case ZONE_Sphere:
							AniZoneSpherePtr = (ANI_ZONE_SPHERE *) ZonesPtr->Data;
							break;
	
						case ZONE_Box:
							AniZoneBoxPtr = (ANI_ZONE_BOX *) ZonesPtr->Data;

							if( RayToColZone( &NewOrigin, &NewEnd,
											  AniZoneBoxPtr->Sides, AniZoneBoxPtr->NumSides,
											  &IntPoint, &IntSide, ColRadius ) )
							{
								TempVector.x = ( IntPoint.x - NewOrigin.x );
								TempVector.y = ( IntPoint.y - NewOrigin.y );
								TempVector.z = ( IntPoint.z - NewOrigin.z );
								DistToInt = VectorLength( &TempVector );

								if( !ColCollided )
								{
									ColPoint = IntPoint;
									ColSide = IntSide;
									ColDist = DistToInt;
									ColChild = Children;
									ColDir = NewDir;
									ColZoneNum = Zone;
									ColParent = CurParent;
									ColCollided++;
								}
								else
								{
									if( DistToInt < ColDist )
									{
										ColPoint = IntPoint;
										ColSide = IntSide;
										ColDist = DistToInt;
										ColChild = Children;
										ColDir = NewDir;
										ColParent = CurParent;
										ColZoneNum = Zone;
									}
								}

							}
							break;
	
						case ZONE_Polygonal:
							AniZonePolyPtr = (ANI_ZONE_POLYGONAL *) ZonesPtr->Data;

							if( RayToColZone( &NewOrigin, &NewEnd,
											  AniZonePolyPtr->Sides, AniZonePolyPtr->NumSides,
											  &IntPoint, &IntSide, ColRadius ) )
							{
								TempVector.x = ( IntPoint.x - NewOrigin.x );
								TempVector.y = ( IntPoint.y - NewOrigin.y );
								TempVector.z = ( IntPoint.z - NewOrigin.z );
								DistToInt = VectorLength( &TempVector );

								if( !ColCollided )
								{
									ColPoint = IntPoint;
									ColSide = IntSide;
									ColDist = DistToInt;
									ColChild = Children;
									ColDir = NewDir;
									ColParent = CurParent;
									ColZoneNum = Zone;
									ColCollided++;
								}
								else
								{
									if( DistToInt < ColDist )
									{
										ColPoint = IntPoint;
										ColSide = IntSide;
										ColDist = DistToInt;
										ColChild = Children;
										ColDir = NewDir;
										ColParent = CurParent;
										ColZoneNum = Zone;
									}
								}
							}
							break;
					}

					ZonesPtr++;
				}
			}
					
			if( Children->NumChildren )
			{
				CollideBGOToCompObjChildren( Children->Children, Children->NumChildren );
			}

			Children++;
		}
	}
}


static BOOL move_object = TRUE;
static BOOL bounce_object = TRUE;
static NoBGObject = TRUE;


#if 0

BOOL ObjectCollide( OBJECT *Obj, VECTOR *Move_Off, float radius, BGOBJECT **BGObject )
{
	VECTOR Up, Right;
	QUAT MoveQuat;
	MATRIX MoveMat;
	int f;
	float dx0, dy0;
	float dx1, dy1;
	VECTOR Feeler;
	static struct
	{
		struct {
			float dx, dy;
		} start, end;
		uint16 line;
	} FeelerOffset[ MAX_FEELER_RAYS ] =
	{
		{ 0.0F, 0.0F,  0.0F, 0.0F, -1 },
		{ 0.0F, 0.0F,  1.0F, 1.0F, -1 },
		{ 0.0F, 0.0F,  1.0F,-1.0F, -1 },
		{ 0.0F, 0.0F, -1.0F,-1.0F, -1 },
		{ 0.0F, 0.0F, -1.0F, 1.0F, -1 },
#if 1
		{ 0.0F, 1.0F,  0.0F,-1.0F, -1 },
		{ 0.0F,-1.0F,  0.0F, 1.0F, -1 },
		{ 1.0F, 0.0F, -1.0F, 0.0F, -1 },
		{-1.0F, 0.0F,  1.0F, 0.0F, -1 },
#else
		{ .70F, .70F, -1.0F,-1.0F, -1 },
		{ .70F,-.70F, -1.0F, 1.0F, -1 },
		{-.70F,-.70F,  1.0F, 1.0F, -1 },
		{-.70F, .70F,  1.0F,-1.0F, -1 }
#endif
	};
	VECTOR FeelerImpactPoint;
	uint16 FeelerImpactGroup;
	NORMAL FeelerFaceNormal;
	VECTOR FeelerPos_New;
	BGOBJECT *FeelerBGObject;
#if 0
	float FeelerImpactOffset;
#endif
	float FeelerImpactDist;
	float ImpactDist;
	VECTOR Move;
	float MoveDist;
	VECTOR Move_Dir;
	VECTOR New_Off;
	float FeelerPlane;
	float FeelerDist;
	VECTOR FeelerEndPoint;
	float Num, Div;
#ifdef DEBUG_MULTI_RAYS
	uint16 line;
#endif
	static uint16 target_line = -1;
	VECTOR FeelerStart;
	uint16 FeelerGroup;
	int truncated;
	NORMAL ImpactNormal;
	float ImpactPlane;
	float FeelerLength = 1.25F * radius;
	VECTOR StartPos;
	VECTOR Pos_New;
	BOOL hit;
	VECTOR ImpactPoint;
	
	hit = FALSE;
	StartPos = Obj->Pos;
	Move_Dir = *Move_Off;
	NormaliseVector( &Move_Dir );
	QuatFromVector2( &Move_Dir, &MoveQuat );
	QuatToMatrix( &MoveQuat, &MoveMat );
	ApplyMatrix( &MoveMat, &SlideUp, &Up );
	ApplyMatrix( &MoveMat, &SlideRight, &Right );
	MoveDist = VectorLength( Move_Off );
	ImpactDist = MoveDist;
	ImpactPoint.x = StartPos.x + Move_Off->x;
	ImpactPoint.y = StartPos.y + Move_Off->y;
	ImpactPoint.z = StartPos.z + Move_Off->z;
	for ( f = 0; f < MAX_FEELER_RAYS; f++ )
	{
		dx0 = FeelerOffset[ f ].start.dx;
		dy0 = FeelerOffset[ f ].start.dy;
		dx1 = FeelerOffset[ f ].end.dx;
		dy1 = FeelerOffset[ f ].end.dy;
		FeelerStart.x = radius * ( dx0 * Right.x + dy0 * Up.x );
		FeelerStart.y = radius * ( dx0 * Right.y + dy0 * Up.y );
		FeelerStart.z = radius * ( dx0 * Right.z + dy0 * Up.z );
		FeelerGroup = MoveGroup( &Mloadheader, &StartPos, Obj->Group, &FeelerStart );
		FeelerGroup = Obj->Group;
		FeelerStart.x += StartPos.x;
		FeelerStart.y += StartPos.y;
		FeelerStart.z += StartPos.z;
		Feeler = Move_Dir;
		Feeler.x *= ( MoveDist + FeelerLength );
		Feeler.y *= ( MoveDist + FeelerLength );
		Feeler.z *= ( MoveDist + FeelerLength );
		Feeler.x += radius * ( dx1 * Right.x + dy1 * Up.x );
		Feeler.y += radius * ( dx1 * Right.y + dy1 * Up.y );
		Feeler.z += radius * ( dx1 * Right.z + dy1 * Up.z );
#ifdef DEBUG_MULTI_RAYS
		if ( FeelerOffset[ f ].line == (uint16) -1 )
		{
			FeelerOffset[ f ].line = FindFreeLine();
		}
		line = FeelerOffset[ f ].line;
		if ( line != (uint16) -1 )
		{
			Lines[ line ].StartPos = FeelerStart;
			Lines[ line ].EndPos.x = FeelerStart.x + Feeler.x;
			Lines[ line ].EndPos.y = FeelerStart.y + Feeler.y;
			Lines[ line ].EndPos.z = FeelerStart.z + Feeler.z;
			Lines[ line ].StartCol.R = 255;
			Lines[ line ].StartCol.G = 255;
			Lines[ line ].StartCol.B = 255;
			Lines[ line ].EndCol.R = 128 + (int) (96 * (dx0 + dx1));
			Lines[ line ].EndCol.G = 128 + (int) (96 * (dy0 + dy1));
			Lines[ line ].EndCol.B = (!f) * 255;
			Lines[ line ].StartTrans = 255;
			Lines[ line ].EndTrans = 255;
			Lines[ line ].Group = Obj->Group;
		}
#endif
		if ( BackgroundCollide( &MCloadheadert0, &Mloadheader,
			&FeelerStart, FeelerGroup, &Feeler,
			&FeelerImpactPoint , &FeelerImpactGroup, &FeelerFaceNormal, &FeelerPos_New, TRUE, ( BGObject ) ? &FeelerBGObject : NULL ) )
		{
			FeelerPlane = -DotProduct( (VECTOR *)&FeelerFaceNormal, &FeelerImpactPoint ) - radius;
			Div = DotProduct( &Move_Dir , (VECTOR *)&FeelerFaceNormal );
			if( Div >= -0.001F )
			{
				//										DebugPrintf( "Errk! (Div = %f)\n", Div );		/* Reject, Parallel */
				continue;
			}
			Num = ( FeelerPlane + DotProduct( &StartPos, (VECTOR *)&FeelerFaceNormal) );
			FeelerImpactDist = -( Num / Div );
			if ( FeelerImpactDist > 0.1F )
			{
				FeelerImpactDist -= 0.1F;
				truncated = 0;
			}
#if 1
			else
			{
				FeelerImpactDist = 0.0F;
				truncated = 1;
			}
#else
			else if ( FeelerImpactDist > 0.0F || !f )
			{
				FeelerImpactDist = 0.0F;
				truncated = 1;
			}
			else
				continue;
#endif
			FeelerImpactPoint.x = StartPos.x + Move_Dir.x * FeelerImpactDist;
			FeelerImpactPoint.y = StartPos.y + Move_Dir.y * FeelerImpactDist;
			FeelerImpactPoint.z = StartPos.z + Move_Dir.z * FeelerImpactDist;
			if ( ImpactDist > FeelerImpactDist )
			{
				FeelerEndPoint.x = StartPos.x + Move_Off->x;
				FeelerEndPoint.y = StartPos.y + Move_Off->y;
				FeelerEndPoint.z = StartPos.z + Move_Off->z;
				FeelerDist = ( DotProduct( &FeelerEndPoint, (VECTOR *)&FeelerFaceNormal ) + FeelerPlane );// + 0.025F;// * MoveDist;
				if ( FeelerDist > 0.0F )
				{
					//											DebugPrintf( "FeelerDist = %f\n", FeelerDist );
				}
#if 0
				if ( truncated )
				{
					FeelerImpactOffset = ( DotProduct( &FeelerImpactPoint, (VECTOR *)&FeelerFaceNormal ) + FeelerPlane );
					DebugPrintf( "FeelerDist = %f   FeelerImpactOffset = %f\n",
						FeelerDist, FeelerImpactOffset );
					if ( FeelerImpactOffset < 0.0F )
						FeelerDist = FeelerImpactOffset - FeelerDist;
				}
#endif
				FeelerDist = -FeelerDist;// + 1.0F;
				//										DebugPrintf( "fd = %f\n", FeelerDist );
				FeelerPos_New.x = FeelerEndPoint.x + FeelerFaceNormal.nx * FeelerDist;
				FeelerPos_New.y = FeelerEndPoint.y + FeelerFaceNormal.ny * FeelerDist;
				FeelerPos_New.z = FeelerEndPoint.z + FeelerFaceNormal.nz * FeelerDist;
				NumCollides++;
				ImpactDist = FeelerImpactDist;
				ImpactPoint = FeelerImpactPoint;
				ImpactNormal = FeelerFaceNormal;
				ImpactPlane = FeelerPlane;
				Pos_New = FeelerPos_New;
				if( BGObject ) *BGObject = FeelerBGObject;
			}
		}
	}
	if ( ImpactDist < MoveDist )
	{
		static MATRIX InvMat;
		float MaxPerpendicularAccel;
		VECTOR BumpForce;

#if 1
		Move.x = Move_Off->x - Obj->ExternalForce.x * framelag;
		Move.y = Move_Off->y - Obj->ExternalForce.y * framelag;
		Move.z = Move_Off->z - Obj->ExternalForce.z * framelag;
		MoveDist = VectorLength( &Move );
#endif
#ifdef THIS_SHOULD_WORK_BUT_DOESNT		
		MaxPerpendicularAccel = (float) fabs( DotProduct( &Move_Dir, (VECTOR *)&ImpactNormal ) ) * TurboAccell * MaxTurboSpeed * framelag * framelag;
		//								DebugPrintf( "MaxPerpAccel = %f\n", MaxPerpendicularAccel );
#else
#if 1
		MaxPerpendicularAccel = TurboAccell * MoveDist;
#else
		MaxPerpendicularAccel = TurboAccell * MaxTurboSpeed * framelag;// * framelag;
#endif
#endif
#ifdef THIS_OR_SOMETHING_SIMILAR_MIGHT_BE_NEEDED
		if( framelag != 0.0F )
		{
			if ( MaxPerpendicularAccel > MoveDist / framelag )
				MaxPerpendicularAccel = MoveDist / framelag;
		}
		else
		{
			MaxPerpendicularAccel = 0.0F;
		}
#endif
		BumpForce.x = ImpactNormal.nx * MaxPerpendicularAccel;
		BumpForce.y = ImpactNormal.ny * MaxPerpendicularAccel;
		BumpForce.z = ImpactNormal.nz * MaxPerpendicularAccel;
#ifdef DEBUG_MULTI_RAYS
		if ( target_line == (uint16) -1 )
			target_line = FindFreeLine();
		if ( target_line != (uint16) -1 )
		{
			Lines[ target_line ].StartPos = ImpactPoint;
			Lines[ target_line ].EndPos = Pos_New;
			Lines[ target_line ].StartCol.R = 55;
			Lines[ target_line ].StartCol.G = 55;
			Lines[ target_line ].StartCol.B = 55;
			Lines[ target_line ].EndCol.R = 255;
			Lines[ target_line ].EndCol.G = 255;
			Lines[ target_line ].EndCol.B = 255;
			Lines[ target_line ].StartTrans = 255;
			Lines[ target_line ].EndTrans = 255;
			Lines[ target_line ].Group = Obj->Group;
		}
#endif
		New_Off.x = Pos_New.x - ImpactPoint.x;
		New_Off.y = Pos_New.y - ImpactPoint.y;
		New_Off.z = Pos_New.z - ImpactPoint.z;
		NormaliseVector( &New_Off );
		if ( framelag )
		{
			New_Off.x *= MoveDist / framelag;
			New_Off.y *= MoveDist / framelag;
			New_Off.z *= MoveDist / framelag;
		}
		else
		{
			New_Off.x = 0.0F;
			New_Off.y = 0.0F;
			New_Off.z = 0.0F;
		}

		MatrixTranspose( &Obj->Mat, &InvMat );
		ApplyMatrix( &InvMat, &New_Off, &Move ); // modify ship's speed
		//								DebugPrintf( "New move=%f  old=%f\n", VectorLength( &Move_Off ), MoveDist );
		if ( move_object )
		{
			if ( VectorLength( &Move ) < 10.0F * MoveDist )
			{
				Obj->Speed = Move;
				if ( DotProduct( &Obj->ExternalForce, (VECTOR *) &ImpactNormal ) < 0.0F )
					ReflectVector( &Obj->ExternalForce, &ImpactNormal, &Obj->ExternalForce );
#if FIX0
				Obj->ExternalForce.x = 0.0F;
				Obj->ExternalForce.y = 0.0F;
				Obj->ExternalForce.z = 0.0F;
#endif
			}
			else
			{
				DebugPrintf( "New move too big (%f > 10 * %f)...!\n", VectorLength( &Move ), MoveDist );
			}
			ObjForceExternalOneOff( Obj, &BumpForce );
			if ( ImpactDist < 0.0F )
			{
				ImpactPoint = StartPos;
				DebugPrintf( "impactdist = %f, no movement\n", ImpactDist );
			}
		}
		//								DebugPrintf( "Move (%f, %f, %f)\n",
		//									Move.x, Move., Move.z );
		hit = TRUE;
	}
	Move_Off->x = ImpactPoint.x - StartPos.x;
	Move_Off->y = ImpactPoint.y - StartPos.y;
	Move_Off->z = ImpactPoint.z - StartPos.z;
	if ( move_object )
	{
		Obj->Pos = ImpactPoint;
		Obj->Group = MoveGroup( &Mloadheader, &StartPos, Obj->Group, Move_Off );
	}

	return hit;
}


#else

#define BACKFACING_PLANE_TOLERANCE		(-0.001F)
#define IMPACT_OFFSET					(0.1F)
#define FEELER_LENGTH_TO_RADIUS_RATIO	(1.25F)


BOOL ObjectCollide( OBJECT *Obj, VECTOR *Move_Off, float radius, BGOBJECT **BGObject )
{
	VECTOR Up, Right;
	QUAT MoveQuat;
	MATRIX MoveMat;
	int f;
	float dx0, dy0;
	float dx1, dy1;
	VECTOR Feeler;
	static struct
	{
		struct {
			float dx, dy;
		} start, end;
	} FeelerOffset[ MAX_FEELER_RAYS ] =
	{
		{ 0.0F, 0.0F,  0.0F, 0.0F },
		{ 0.0F, 0.0F,  1.0F, 1.0F },
		{ 0.0F, 0.0F,  1.0F,-1.0F },
		{ 0.0F, 0.0F, -1.0F,-1.0F },
		{ 0.0F, 0.0F, -1.0F, 1.0F },
		{ 0.0F, 1.0F,  0.0F,-1.0F },
		{ 0.0F,-1.0F,  0.0F, 1.0F },
		{ 1.0F, 0.0F, -1.0F, 0.0F },
		{-1.0F, 0.0F,  1.0F, 0.0F },
	};
	VECTOR FeelerImpactPoint;
	uint16 FeelerImpactGroup;
	NORMAL FeelerFaceNormal;
	VECTOR FeelerPos_New;
	BGOBJECT *FeelerBGObject;
	float FeelerImpactDist;
	float ImpactDist;
	VECTOR Move;
	float MoveDist;
	VECTOR Move_Dir;
	VECTOR New_Off;
	float FeelerPlane;
	float FeelerDist;
	VECTOR FeelerEndPoint;
	float Num, Div;
	VECTOR FeelerStart;
	uint16 FeelerGroup;
	NORMAL ImpactNormal;
	float ImpactPlane;
	float FeelerLength = FEELER_LENGTH_TO_RADIUS_RATIO * radius;
	VECTOR StartPos;
	VECTOR Pos_New;
	BOOL hit;
	VECTOR ImpactPoint;
	
	hit = FALSE;
	StartPos = Obj->Pos;
	Move_Dir = *Move_Off;
	NormaliseVector( &Move_Dir );
	QuatFromVector2( &Move_Dir, &MoveQuat );
	QuatToMatrix( &MoveQuat, &MoveMat );
	ApplyMatrix( &MoveMat, &SlideUp, &Up );
	ApplyMatrix( &MoveMat, &SlideRight, &Right );
	MoveDist = VectorLength( Move_Off );
	ImpactDist = MoveDist;
	ImpactPoint.x = StartPos.x + Move_Off->x;
	ImpactPoint.y = StartPos.y + Move_Off->y;
	ImpactPoint.z = StartPos.z + Move_Off->z;
	for ( f = 0; f < MAX_FEELER_RAYS; f++ )
	{
		dx0 = FeelerOffset[ f ].start.dx;
		dy0 = FeelerOffset[ f ].start.dy;
		dx1 = FeelerOffset[ f ].end.dx;
		dy1 = FeelerOffset[ f ].end.dy;
		FeelerStart.x = radius * ( dx0 * Right.x + dy0 * Up.x );
		FeelerStart.y = radius * ( dx0 * Right.y + dy0 * Up.y );
		FeelerStart.z = radius * ( dx0 * Right.z + dy0 * Up.z );
#if 0
		FeelerGroup = MoveGroup( &Mloadheader, &StartPos, Obj->Group, &FeelerStart );
#else
		FeelerGroup = Obj->Group;
#endif
		FeelerStart.x += StartPos.x;
		FeelerStart.y += StartPos.y;
		FeelerStart.z += StartPos.z;
		Feeler = Move_Dir;
		Feeler.x *= ( MoveDist + FeelerLength );
		Feeler.y *= ( MoveDist + FeelerLength );
		Feeler.z *= ( MoveDist + FeelerLength );
		Feeler.x += radius * ( dx1 * Right.x + dy1 * Up.x );
		Feeler.y += radius * ( dx1 * Right.y + dy1 * Up.y );
		Feeler.z += radius * ( dx1 * Right.z + dy1 * Up.z );
		if ( BackgroundCollide( &MCloadheadert0, &Mloadheader,
			&FeelerStart, FeelerGroup, &Feeler,
			&FeelerImpactPoint , &FeelerImpactGroup, &FeelerFaceNormal, &FeelerPos_New, NoBGObject, ( BGObject ) ? &FeelerBGObject : NULL ) )
		{
			FeelerPlane = -DotProduct( (VECTOR *)&FeelerFaceNormal, &FeelerImpactPoint ) - radius;
			Div = DotProduct( &Move_Dir , (VECTOR *)&FeelerFaceNormal );
			if( Div >= BACKFACING_PLANE_TOLERANCE )
			{
				continue;
			}
			Num = ( FeelerPlane + DotProduct( &StartPos, (VECTOR *)&FeelerFaceNormal) );
			FeelerImpactDist = -( Num / Div );
			if ( FeelerImpactDist > IMPACT_OFFSET )
			{
				FeelerImpactDist -= IMPACT_OFFSET;
			}
			else
			{
				FeelerImpactDist = 0.0F;
			}
			FeelerImpactPoint.x = StartPos.x + Move_Dir.x * FeelerImpactDist;
			FeelerImpactPoint.y = StartPos.y + Move_Dir.y * FeelerImpactDist;
			FeelerImpactPoint.z = StartPos.z + Move_Dir.z * FeelerImpactDist;
			if ( ImpactDist > FeelerImpactDist )
			{
				FeelerEndPoint.x = StartPos.x + Move_Off->x;
				FeelerEndPoint.y = StartPos.y + Move_Off->y;
				FeelerEndPoint.z = StartPos.z + Move_Off->z;
				FeelerDist = ( DotProduct( &FeelerEndPoint, (VECTOR *)&FeelerFaceNormal ) + FeelerPlane );
				FeelerDist = -FeelerDist;
				FeelerPos_New.x = FeelerEndPoint.x + FeelerFaceNormal.nx * FeelerDist;
				FeelerPos_New.y = FeelerEndPoint.y + FeelerFaceNormal.ny * FeelerDist;
				FeelerPos_New.z = FeelerEndPoint.z + FeelerFaceNormal.nz * FeelerDist;
				ImpactDist = FeelerImpactDist;
				ImpactPoint = FeelerImpactPoint;
				ImpactNormal = FeelerFaceNormal;
				ImpactPlane = FeelerPlane;
				Pos_New = FeelerPos_New;
				if( BGObject )
					*BGObject = FeelerBGObject;
			}
		}
	}
	if ( ImpactDist < MoveDist )
	{
		if ( move_object && bounce_object )
		{
			static MATRIX InvMat;
			float MaxPerpendicularAccel;
			VECTOR BumpForce;

#if BAD_BUMP
			Move.x = Move_Off->x - Obj->ExternalForce.x * framelag;
			Move.y = Move_Off->y - Obj->ExternalForce.y * framelag;
			Move.z = Move_Off->z - Obj->ExternalForce.z * framelag;
			MoveDist = VectorLength( &Move );
#else // better, but not perfect...
			Move = Obj->Speed;
			MoveDist = VectorLength( &Move ) * framelag;
#endif
			MaxPerpendicularAccel = TurboAccell * MoveDist;
			BumpForce.x = ImpactNormal.nx * MaxPerpendicularAccel;
			BumpForce.y = ImpactNormal.ny * MaxPerpendicularAccel;
			BumpForce.z = ImpactNormal.nz * MaxPerpendicularAccel;
			New_Off.x = Pos_New.x - ImpactPoint.x;
			New_Off.y = Pos_New.y - ImpactPoint.y;
			New_Off.z = Pos_New.z - ImpactPoint.z;
			NormaliseVector( &New_Off );
			if( framelag )
			{
				MoveDist /= framelag;
			}
			else
			{
				MoveDist = 0.0F;
			}
			New_Off.x *= MoveDist;
			New_Off.y *= MoveDist;
			New_Off.z *= MoveDist;
			MatrixTranspose( &Obj->Mat, &InvMat );
			ApplyMatrix( &InvMat, &New_Off, &Move ); // modify ship's speed
			Obj->Speed = Move;
			if ( DotProduct( &Obj->ExternalForce, (VECTOR *) &ImpactNormal ) < 0.0F )
				ReflectVector( &Obj->ExternalForce, &ImpactNormal, &Obj->ExternalForce );
			ObjForceExternalOneOff( Obj, &BumpForce );
			if ( ImpactDist < 0.0F )
			{
				ImpactPoint = StartPos;
				DebugPrintf( "impactdist = %f, no movement\n", ImpactDist );
			}
		}
		hit = TRUE;
	}
	Move_Off->x = ImpactPoint.x - StartPos.x;
	Move_Off->y = ImpactPoint.y - StartPos.y;
	Move_Off->z = ImpactPoint.z - StartPos.z;
	if ( move_object )
	{
		Obj->Pos = ImpactPoint;
		Obj->Group = MoveGroup( &Mloadheader, &StartPos, Obj->Group, Move_Off );
	}

	return hit;
}

#endif


BOOL WouldObjectCollide( OBJECT *Obj, VECTOR *Move_Off, float radius, BGOBJECT **BGObject )
{
	BOOL collide;

	move_object = FALSE;
	collide = ObjectCollide( Obj, Move_Off, radius, BGObject );
	move_object = TRUE;

	return collide;
}


BOOL ObjectCollideNoBounce( OBJECT *Obj, VECTOR *Move_Off, float radius, BGOBJECT **BGObject )
{
	BOOL collide;

	bounce_object = FALSE;
	collide = ObjectCollide( Obj, Move_Off, radius, BGObject );
	bounce_object = TRUE;

	return collide;
}


BOOL ObjectCollideNoBGObject( OBJECT *Obj, VECTOR *Move_Off, float radius )
{
	BOOL collide;

	NoBGObject = FALSE;
	collide = ObjectCollide( Obj, Move_Off, radius, NULL );
	NoBGObject = TRUE;

	return collide;
}



BOOL ObjectCollideOnly( OBJECT *Obj, VECTOR *Move_Off, float radius, VECTOR *Target_Off, BGOBJECT **BGObject )
{
	VECTOR Up, Right;
	QUAT MoveQuat;
	MATRIX MoveMat;
	int f;
	float dx0, dy0;
	float dx1, dy1;
	VECTOR Feeler;
	static struct
	{
		struct {
			float dx, dy;
		} start, end;
	} FeelerOffset[ MAX_FEELER_RAYS ] =
	{
		{ 0.0F, 0.0F,  0.0F, 0.0F },
		{ 0.0F, 0.0F,  1.0F, 1.0F },
		{ 0.0F, 0.0F,  1.0F,-1.0F },
		{ 0.0F, 0.0F, -1.0F,-1.0F },
		{ 0.0F, 0.0F, -1.0F, 1.0F },
		{ 0.0F, 1.0F,  0.0F,-1.0F },
		{ 0.0F,-1.0F,  0.0F, 1.0F },
		{ 1.0F, 0.0F, -1.0F, 0.0F },
		{-1.0F, 0.0F,  1.0F, 0.0F },
	};
	VECTOR FeelerImpactPoint;
	uint16 FeelerImpactGroup;
	NORMAL FeelerFaceNormal;
	VECTOR FeelerPos_New;
	BGOBJECT *FeelerBGObject;
	float FeelerImpactDist;
	float ImpactDist;
	float MoveDist;
	VECTOR Move_Dir;
	float FeelerPlane;
	float FeelerDist;
	VECTOR FeelerEndPoint;
	float Num, Div;
	VECTOR FeelerStart;
	uint16 FeelerGroup;
	NORMAL ImpactNormal;
	float ImpactPlane;
	float FeelerLength = FEELER_LENGTH_TO_RADIUS_RATIO * radius;
	VECTOR StartPos;
	VECTOR Pos_New;
	BOOL hit;
	VECTOR ImpactPoint;
	
	hit = FALSE;
	StartPos = Obj->Pos;
	Move_Dir = *Move_Off;
	NormaliseVector( &Move_Dir );
	QuatFromVector2( &Move_Dir, &MoveQuat );
	QuatToMatrix( &MoveQuat, &MoveMat );
	ApplyMatrix( &MoveMat, &SlideUp, &Up );
	ApplyMatrix( &MoveMat, &SlideRight, &Right );
	MoveDist = VectorLength( Move_Off );
	ImpactDist = MoveDist;
	ImpactPoint.x = StartPos.x + Move_Off->x;
	ImpactPoint.y = StartPos.y + Move_Off->y;
	ImpactPoint.z = StartPos.z + Move_Off->z;
	for ( f = 0; f < MAX_FEELER_RAYS; f++ )
	{
		dx0 = FeelerOffset[ f ].start.dx;
		dy0 = FeelerOffset[ f ].start.dy;
		dx1 = FeelerOffset[ f ].end.dx;
		dy1 = FeelerOffset[ f ].end.dy;
		FeelerStart.x = radius * ( dx0 * Right.x + dy0 * Up.x );
		FeelerStart.y = radius * ( dx0 * Right.y + dy0 * Up.y );
		FeelerStart.z = radius * ( dx0 * Right.z + dy0 * Up.z );
#if 0
		FeelerGroup = MoveGroup( &Mloadheader, &StartPos, Obj->Group, &FeelerStart );
#else
		FeelerGroup = Obj->Group;
#endif
		FeelerStart.x += StartPos.x;
		FeelerStart.y += StartPos.y;
		FeelerStart.z += StartPos.z;
		Feeler = Move_Dir;
		Feeler.x *= ( MoveDist + FeelerLength );
		Feeler.y *= ( MoveDist + FeelerLength );
		Feeler.z *= ( MoveDist + FeelerLength );
		Feeler.x += radius * ( dx1 * Right.x + dy1 * Up.x );
		Feeler.y += radius * ( dx1 * Right.y + dy1 * Up.y );
		Feeler.z += radius * ( dx1 * Right.z + dy1 * Up.z );
		if ( BackgroundCollide( &MCloadheadert0, &Mloadheader,
			&FeelerStart, FeelerGroup, &Feeler,
			&FeelerImpactPoint , &FeelerImpactGroup, &FeelerFaceNormal, &FeelerPos_New, TRUE, ( BGObject ) ? &FeelerBGObject : NULL ) )
		{
			FeelerPlane = -DotProduct( (VECTOR *)&FeelerFaceNormal, &FeelerImpactPoint ) - radius;
			Div = DotProduct( &Move_Dir , (VECTOR *)&FeelerFaceNormal );
			if( Div >= BACKFACING_PLANE_TOLERANCE )
			{
				continue;
			}
			Num = ( FeelerPlane + DotProduct( &StartPos, (VECTOR *)&FeelerFaceNormal) );
			FeelerImpactDist = -( Num / Div );
			if ( FeelerImpactDist > IMPACT_OFFSET )
			{
				FeelerImpactDist -= IMPACT_OFFSET;
			}
			else
			{
				FeelerImpactDist = 0.0F;
			}
			FeelerImpactPoint.x = StartPos.x + Move_Dir.x * FeelerImpactDist;
			FeelerImpactPoint.y = StartPos.y + Move_Dir.y * FeelerImpactDist;
			FeelerImpactPoint.z = StartPos.z + Move_Dir.z * FeelerImpactDist;
			if ( ImpactDist > FeelerImpactDist )
			{
				FeelerEndPoint.x = StartPos.x + Move_Off->x;
				FeelerEndPoint.y = StartPos.y + Move_Off->y;
				FeelerEndPoint.z = StartPos.z + Move_Off->z;
				FeelerDist = ( DotProduct( &FeelerEndPoint, (VECTOR *)&FeelerFaceNormal ) + FeelerPlane );
				FeelerDist = -FeelerDist + COLLISION_FUDGE;
				FeelerPos_New.x = FeelerEndPoint.x + FeelerFaceNormal.nx * FeelerDist;
				FeelerPos_New.y = FeelerEndPoint.y + FeelerFaceNormal.ny * FeelerDist;
				FeelerPos_New.z = FeelerEndPoint.z + FeelerFaceNormal.nz * FeelerDist;
				ImpactDist = FeelerImpactDist;
				ImpactPoint = FeelerImpactPoint;
				ImpactNormal = FeelerFaceNormal;
				ImpactPlane = FeelerPlane;
				Pos_New = FeelerPos_New;
				if( BGObject )
					*BGObject = FeelerBGObject;
			}
		}
	}
	if ( ImpactDist < MoveDist )
	{
		hit = TRUE;
	}
	Move_Off->x = ImpactPoint.x - StartPos.x;
	Move_Off->y = ImpactPoint.y - StartPos.y;
	Move_Off->z = ImpactPoint.z - StartPos.z;
	Target_Off->x = Pos_New.x - ImpactPoint.x;
	Target_Off->y = Pos_New.y - ImpactPoint.y;
	Target_Off->z = Pos_New.z - ImpactPoint.z;
	if ( move_object )
	{
		Obj->Pos = ImpactPoint;
		Obj->Group = MoveGroup( &Mloadheader, &StartPos, Obj->Group, Move_Off );
	}

	return hit;
}


BOOL QCollide( VECTOR *Start_Pos, uint16 Start_Group, VECTOR *Move_Off, float radius, VECTOR *Impact_Point, uint16 *Impact_Group, NORMAL *Impact_Normal )
{
	VECTOR Up, Right;
	QUAT MoveQuat;
	MATRIX MoveMat;
	int f;
	float dx0, dy0;
	float dx1, dy1;
	VECTOR Feeler;
	static struct
	{
		struct {
			float dx, dy;
		} start, end;
	} FeelerOffset[ MAX_QFEELER_RAYS ] =
	{
		{ 0.0F, 0.0F,  0.0F, 0.0F },
		{ 0.0F, 0.0F,  1.0F, 1.0F },
		{ 0.0F, 0.0F,  1.0F,-1.0F },
		{ 0.0F, 0.0F, -1.0F,-1.0F },
		{ 0.0F, 0.0F, -1.0F, 1.0F },
	};
	VECTOR FeelerImpactPoint;
	uint16 FeelerImpactGroup;
	NORMAL FeelerFaceNormal;
	VECTOR FeelerPos_New;
	float FeelerImpactDist;
	float ImpactDist;
	VECTOR Move;
	float MoveDist;
	VECTOR Move_Dir;
	float FeelerPlane;
	float FeelerDist;
	VECTOR FeelerEndPoint;
	float Num, Div;
	VECTOR FeelerStart;
	uint16 FeelerGroup;
	NORMAL ImpactNormal;
	float FeelerLength = FEELER_LENGTH_TO_RADIUS_RATIO * radius;
	VECTOR StartPos;
	BOOL hit;
	VECTOR ImpactPoint;
	
	hit = FALSE;
	StartPos = *Start_Pos;
	Move_Dir = *Move_Off;
	NormaliseVector( &Move_Dir );
	QuatFromVector2( &Move_Dir, &MoveQuat );
	QuatToMatrix( &MoveQuat, &MoveMat );
	ApplyMatrix( &MoveMat, &SlideUp, &Up );
	ApplyMatrix( &MoveMat, &SlideRight, &Right );
	MoveDist = VectorLength( Move_Off );
	ImpactDist = MoveDist;
	ImpactPoint.x = StartPos.x + Move_Off->x;
	ImpactPoint.y = StartPos.y + Move_Off->y;
	ImpactPoint.z = StartPos.z + Move_Off->z;
	Move = *Move_Off;
	for ( f = 0; f < MAX_QFEELER_RAYS; f++ )
	{
		dx0 = FeelerOffset[ f ].start.dx;
		dy0 = FeelerOffset[ f ].start.dy;
		dx1 = FeelerOffset[ f ].end.dx;
		dy1 = FeelerOffset[ f ].end.dy;
		FeelerStart.x = radius * ( dx0 * Right.x + dy0 * Up.x );
		FeelerStart.y = radius * ( dx0 * Right.y + dy0 * Up.y );
		FeelerStart.z = radius * ( dx0 * Right.z + dy0 * Up.z );
#if 0
		FeelerGroup = MoveGroup( &Mloadheader, &StartPos, Start_Group, &FeelerStart );
#else
		FeelerGroup = Start_Group;
#endif
		FeelerStart.x += StartPos.x;
		FeelerStart.y += StartPos.y;
		FeelerStart.z += StartPos.z;
		Feeler = Move_Dir;
		Feeler.x *= ( MoveDist + FeelerLength );
		Feeler.y *= ( MoveDist + FeelerLength );
		Feeler.z *= ( MoveDist + FeelerLength );
		Feeler.x += radius * ( dx1 * Right.x + dy1 * Up.x );
		Feeler.y += radius * ( dx1 * Right.y + dy1 * Up.y );
		Feeler.z += radius * ( dx1 * Right.z + dy1 * Up.z );
		if ( BackgroundCollide( &MCloadheadert0, &Mloadheader,
			&FeelerStart, FeelerGroup, &Feeler,
			&FeelerImpactPoint , &FeelerImpactGroup, &FeelerFaceNormal, &FeelerPos_New, TRUE, NULL ) )
		{
			FeelerPlane = -DotProduct( (VECTOR *)&FeelerFaceNormal, &FeelerImpactPoint ) - radius;
			Div = DotProduct( &Move_Dir , (VECTOR *)&FeelerFaceNormal );
			if( Div >= BACKFACING_PLANE_TOLERANCE )
			{
				continue;
			}
			Num = ( FeelerPlane + DotProduct( &StartPos, (VECTOR *)&FeelerFaceNormal) );
			FeelerImpactDist = -( Num / Div );
			if ( FeelerImpactDist > IMPACT_OFFSET )
			{
				FeelerImpactDist -= IMPACT_OFFSET;
			}
			else
			{
				FeelerImpactDist = 0.0F;
			}
			FeelerImpactPoint.x = StartPos.x + Move_Dir.x * FeelerImpactDist;
			FeelerImpactPoint.y = StartPos.y + Move_Dir.y * FeelerImpactDist;
			FeelerImpactPoint.z = StartPos.z + Move_Dir.z * FeelerImpactDist;
			if ( ImpactDist > FeelerImpactDist )
			{
				FeelerEndPoint.x = StartPos.x + Move_Off->x;
				FeelerEndPoint.y = StartPos.y + Move_Off->y;
				FeelerEndPoint.z = StartPos.z + Move_Off->z;
				FeelerDist = ( DotProduct( &FeelerEndPoint, (VECTOR *)&FeelerFaceNormal ) + FeelerPlane );
				FeelerDist = -FeelerDist;
				FeelerPos_New.x = FeelerEndPoint.x + FeelerFaceNormal.nx * FeelerDist;
				FeelerPos_New.y = FeelerEndPoint.y + FeelerFaceNormal.ny * FeelerDist;
				FeelerPos_New.z = FeelerEndPoint.z + FeelerFaceNormal.nz * FeelerDist;
				ImpactDist = FeelerImpactDist;
				ImpactPoint = FeelerImpactPoint;
				ImpactNormal = FeelerFaceNormal;
			}
		}
	}
	if ( ImpactDist < MoveDist )
	{
		Move.x = ImpactPoint.x - StartPos.x;
		Move.y = ImpactPoint.y - StartPos.y;
		Move.z = ImpactPoint.z - StartPos.z;
		*Impact_Point = ImpactPoint;
		*Impact_Normal = ImpactNormal;
		hit = TRUE;
	}
	*Impact_Group = MoveGroup( &Mloadheader, &StartPos, Start_Group, &Move );
	return hit;
}

/*�������������������������������������������������������������������
	Procedure	:		Get CompEnemyHit Info
	Input		:		VECTOR	*	Collision Point (TBFI)
				:		NORMAL	*	Collision Normal (TBFI)
				:		float	*	Collision Distance (TBFI)
	Output		:		uint16		EnemyHit (0xffff) None
�������������������������������������������������������������������*/
uint16 GetComEnemyHitInfo( VECTOR * IntPoint, NORMAL * IntNormal, float * IntDistance )
{
	if( CompEnemyHit == (uint16) -1 )
	{
		return( CompEnemyHit );
	}
	
	IntPoint->x = CompEnemyHitPos.x;
	IntPoint->y = CompEnemyHitPos.y;
	IntPoint->z = CompEnemyHitPos.z;
	IntNormal->nx = CompEnemyHitNormal.nx;
	IntNormal->ny = CompEnemyHitNormal.ny;
	IntNormal->nz = CompEnemyHitNormal.nz;
	*IntDistance = CompEnemyHitDist;

	return( CompEnemyHit );
}

/*�������������������������������������������������������������������
	Procedure	:		Check if hit any enemy
	Input		:		Nothing
	Output		:		uint16		EnemyHit (0xffff) None
�������������������������������������������������������������������*/
uint16 CheckAnyEnemyHit( void )
{
	return( AnyCompEnemyHit );
}

#ifdef OPT_ON
#pragma optimize( "", off )
#endif

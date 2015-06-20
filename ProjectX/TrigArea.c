/*
 * The X Men, April 1997
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * $Revision: 33 $
 *
 * $Header: /PcProjectX/TrigArea.c 33    25/08/98 8:51 Collinsd $
 *
 * $Log: /PcProjectX/TrigArea.c $
 * 
 * 33    25/08/98 8:51 Collinsd
 * Added checksum call to all loaded files.
 * 
 * 32    16/03/98 12:19 Collinsd
 * Random Pickups option added.  Sphere dislpay of trigger areas
 * 
 * 31    23/02/98 12:02 Collinsd
 * 
 * 30    18/02/98 9:53 Collinsd
 * Added Save/load functions for Timer/Temp guage and trigger areas
 * 
 * 29    30/12/97 11:15 Collinsd
 * Unenabled trigger zones now appear purple.
 * 
 * 28    13/12/97 14:56 Collinsd
 * Temp fix for trigger areas default weapons bug.
 * 
 * 27    13/12/97 14:08 Collinsd
 * 
 * 26    12/01/97 11:16a Phillipd
 * 
 * 25    11/29/97 4:36p Phillipd
 * Xmem is now in effect...use it allways....
 * 
 * 24    26/11/97 19:25 Collinsd
 * Rays passing in and out of a trigger zone now should work.
 * 
 * 23    11/19/97 12:37p Phillipd
 * Trigger bug fixed...
 * Teleports now trigger on offable....
 * num of Secrets Are calculated
 * 
 * 22    11/17/97 10:13a Phillipd
 * Trig area V2...
 * 
 * 21    17/11/97 9:13 Oliverc
 * New format trigger areas
 * 
 * 20    15/11/97 18:21 Collinsd
 * Checking for -1 not 0 now ( Ooops ).
 * 
 * 19    12/11/97 18:17 Collinsd
 * Added what weapon activates trigger area code ( Disabled for now )
 * 
 * 18    11/11/97 15:39 Collinsd
 * Fixed lots of bugs. ( in deallocation of buffers ).
 * 
 * 17    10/30/97 9:30a Phillipd
 * Bikes with different mods started...
 * 
 * 16    24/10/97 12:07 Collinsd
 * zone display now works of menus.
 * 
 * 15    20/10/97 11:58 Oliverc
 * Trigger info now dynamically allocated on loading
 * 
 * 14    10/17/97 11:48a Phillipd
 * 
 * 13    10/14/97 4:48p Phillipd
 * 
 * 12    8/10/97 20:34 Collinsd
 * Added Header and Version Code.
 * 
 * 11    2/10/97 20:57 Collinsd
 * Fixed trigger zone collision.
 * 
 * 10    25/09/97 16:58 Collinsd
 * Added group link list to pickups/secondary added more code for
 * bgobjects.
 * 
 * 9     17/07/97 15:38 Collinsd
 * BGObjects now use compobjs.
 * 
 * 8     15/07/97 12:54 Collinsd
 * 
 * 7     15/07/97 10:11 Collinsd
 * Added display of triggerzones on Shift F10 in debug mode.
 * 
 * 6     8/07/97 16:30 Collinsd
 * Dicked about with include files FUCK!
 * 
 * 5     8/07/97 14:06 Collinsd
 * Added componented objects to enemies.
 * 
 * 4     1/07/97 10:57 Collinsd
 * Added playershoots trigger area code
 * 
 * 3     6/24/97 11:12a Phillipd
 * 
 * 2     4/19/97 1:23p Phillipd
 * Only Ships Dont collide when no_collisions is set...
 * Trigger areas work better.....
 * 
 * 1     4/17/97 10:54a Phillipd
 * 
 */
/*
Trigger zone format (*.zon):

num_zones : uint16
{
	group : uint16
	type : uint16 // 0 = ZONE_Sphere, 1 = ZONE_Box, 2 = ZONE_Polygonal
	pos( x, y, z ) : all float
	half_size( x, y, z ) : all float
	if type != ZONE_Sphere
	{
		num_sides : uint16
		{
			normal( x, y, z ) : all float
			offset : float
		}[ num_sides ]
	}
	when_player_isin : uint16 // index into action table
	when_player_enters : uint16 // index into action table
	when_player_exits : uint16 // index into action table
	when_player_shoots : uint16 // index into action table
	when_enemy_isin : uint16 // index into action table
	when_enemy_enters : uint16 // index into action table
	when_enemy_exits : uint16 // index into action table
	when_enemy_shoots : uint16 // index into action table
}[ num_zones ]
*/
 
 
/*�������������������������������������������������������������������
		Include Files...	
�������������������������������������������������������������������*/
#define WIN32_EXTRA_LEAN
#include "typedefs.h"
#include <stdio.h>
#include "main.h"
#include <windows.h>
#include "new3d.h"
#include "quat.h"
#include "main.h"
#include <dplay.h>
#include "CompObjects.h"
#include "bgobjects.h"
#include "Object.h"
#include "mydplay.h"
#include "file.h"
#include "Triggers.h"
#include "TrigArea.h"
#include "pickups.h"
#include "mload.h"
#include "bsp.h"
#include "enemies.h"
#include "skin.h"
#include "magic.h"
#include "primary.h"
#include "secondary.h"
#include "XMem.h"


/*�������������������������������������������������������������������
		Externals ...
�������������������������������������������������������������������*/
extern	BOOL			ShowTrigZones;
extern	BYTE			WhoIAm;
extern	GLOBALSHIP		Ships[ MAX_PLAYERS ];
void DebugPrintf( const char * format, ... );
BOOL ClassifyPointInHull( VECTOR * Pos, TRIGGER_ZONE * Sides, int16 NumSides, int16 Side );
BOOL RayToHull( TRIGGER_ZONE * StartSide , VECTOR * StartPos , VECTOR * EndPos , uint16 StartNumSides );
extern TRIGGERMOD	*	TrigMods;
void TriggerAreaProcess( VECTOR * OldPos , VECTOR * NewPos , TRIGGER_AREA * Area );
extern	float framelag;
/*�������������������������������������������������������������������
		Globals ...
�������������������������������������������������������������������*/
uint16	NumZones;
TRIGGER_AREA * Zones = NULL;

TRIGGER_AREA * GroupTriggerArea_player[MAXGROUPS];
TRIGGER_AREA * GroupTriggerArea_player_shoots[MAXGROUPS];
TRIGGER_AREA * GroupTriggerArea_enemy[MAXGROUPS];
TRIGGER_AREA * GroupTriggerArea_enemy_shoots[MAXGROUPS];

/*�������������������������������������������������������������������
		Defines
�������������������������������������������������������������������*/
#define	ZON_VERSION_NUMBER	2

/*�������������������������������������������������������������������
	Procedure	:		Load .zon File
	Input		:		char	*	Filename
	Output		:		BOOL	TRUE/FALSE
�������������������������������������������������������������������*/
BOOL TriggerAreaload( char * Filename )
{
	long			File_Size;
	long			Read_Size;
	char		*	Buffer;
	char		*	OrgBuffer;
	int16			*	int16pnt;
	uint16			*	uint16pnt;
	uint32			*	uint32pnt;
	int			i, j;
	TRIGGER_AREA * OldAreaPnt;
	TRIGGER_AREA * AreaPnt;
	TRIGGER_ZONE * ZonePnt;
	float * floatpnt;
	uint32	MagicNumber;
	uint32	VersionNumber;

	if( Zones != NULL )
	{
		free(Zones);
		Zones = NULL;
	}
	for( i = 0 ; i < MAXGROUPS ; i++ )
	{
		GroupTriggerArea_player[i] = NULL;      
		GroupTriggerArea_player_shoots[i] = NULL;
		GroupTriggerArea_enemy[i] = NULL;       
		GroupTriggerArea_enemy_shoots[i] = NULL;		
	}
	
	FileCheckSum( Filename );

	File_Size = Get_File_Size( Filename );	

	if( !File_Size ) return TRUE;

	Buffer = malloc( File_Size );
	OrgBuffer = Buffer;

	if( Buffer == NULL ) return FALSE;

	Read_Size = Read_File( Filename, Buffer, File_Size );

	if( Read_Size != File_Size ) return FALSE;

	uint32pnt = (uint32 *) Buffer;
	MagicNumber = *uint32pnt++;
	VersionNumber = *uint32pnt++;
	Buffer = (char *) uint32pnt;

	if( ( MagicNumber != MAGIC_NUMBER ) || ( VersionNumber != ZON_VERSION_NUMBER  ) )
	{
		Msg( "TriggerAreaLoad() Incompatible triggerzone( .ZON ) file %s", Filename );
		return( FALSE );
	}

	uint16pnt = (uint16 *) Buffer;
	NumZones = *uint16pnt++;
	Buffer = (char*) uint16pnt;
	Zones = (TRIGGER_AREA*) calloc( NumZones , sizeof(TRIGGER_AREA) );	
	AreaPnt = Zones;

	for( i = 0 ; i < NumZones ; i++ )
	{
		uint16pnt = (uint16 *) Buffer;
		AreaPnt->group = *uint16pnt++;
		AreaPnt->generation_type = *uint16pnt++;
		floatpnt = (float * ) uint16pnt;
		AreaPnt->generation_delay = *floatpnt++;
		uint16pnt = (uint16 *) floatpnt;

		if( AreaPnt->generation_type != TRIGGER_AREA_GENTYPE_Initialised )
		{
			AreaPnt->state = TRIGGER_AREA_STATE_Off;
		}else{
			AreaPnt->state = TRIGGER_AREA_STATE_On;
		}

		AreaPnt->type = *uint16pnt++;

		floatpnt = (float * ) uint16pnt;

		AreaPnt->pos.x = *floatpnt++;
		AreaPnt->pos.y = *floatpnt++;
		AreaPnt->pos.z = *floatpnt++;
		AreaPnt->half_size.x = *floatpnt++;
		AreaPnt->half_size.y = *floatpnt++;
		AreaPnt->half_size.z = *floatpnt++;

		Buffer = (char*) floatpnt;
		if( AreaPnt->type != ZONE_Sphere )
		{
			// convex hull...
			uint16pnt = (uint16*) Buffer;
			AreaPnt->num_sides = *uint16pnt++;
			Buffer = (char*) uint16pnt;
			AreaPnt->Zone = (TRIGGER_ZONE*) malloc( AreaPnt->num_sides * sizeof( TRIGGER_ZONE ) );
			ZonePnt = AreaPnt->Zone;

			floatpnt = (float * ) Buffer;
			
			for( j = 0 ; j < AreaPnt->num_sides ; j++ )
			{
				ZonePnt->normal.x = *floatpnt++;
				ZonePnt->normal.y = *floatpnt++;
				ZonePnt->normal.z = *floatpnt++;
				ZonePnt->offset   = *floatpnt++;
				ZonePnt++;
			}
			Buffer = (char*) floatpnt;
		}
		uint16pnt = (uint16 *) Buffer;

		AreaPnt->when_player_isin = *uint16pnt++;
		AreaPnt->when_player_enters = *uint16pnt++;
		AreaPnt->when_player_exits = *uint16pnt++;
		AreaPnt->when_player_shoots = *uint16pnt++;
		int16pnt = (int16 *) uint16pnt;
		AreaPnt->player_primary = *int16pnt++;
		AreaPnt->player_secondary = *int16pnt++;
		uint16pnt = (uint16 *) int16pnt;
		AreaPnt->when_enemy_isin = *uint16pnt++;
		AreaPnt->when_enemy_enters = *uint16pnt++;
		AreaPnt->when_enemy_exits = *uint16pnt++;
		AreaPnt->when_enemy_shoots = *uint16pnt++;
		int16pnt = (int16 *) uint16pnt;
		AreaPnt->enemy_primary = *int16pnt++;
		AreaPnt->enemy_secondary = *int16pnt++;
		Buffer = (char*) int16pnt;

		AreaPnt++;
	}
	
	free( OrgBuffer );

	// Make up Group Link List....

	for( i = 0 ; i < MAXGROUPS ; i++ )
	{
		AreaPnt = Zones;
		OldAreaPnt = NULL;
		for( j = 0 ; j < NumZones ; j++ )
		{
			if( ( AreaPnt->group == i ) &&( ( AreaPnt->when_player_isin != 0xffff ) ||
											( AreaPnt->when_player_enters != 0xffff ) ||
											( AreaPnt->when_player_exits != 0xffff ) ) )
			{
				if( !OldAreaPnt )
				{
					// found the first....
					GroupTriggerArea_player[i] = AreaPnt;
					OldAreaPnt = AreaPnt;
				}else{
					// found another
					OldAreaPnt->NextSameGroup_player = AreaPnt;
					OldAreaPnt = AreaPnt;
				}
			}
			AreaPnt++;
		}
	}
	for( i = 0 ; i < MAXGROUPS ; i++ )
	{
		AreaPnt = Zones;
		OldAreaPnt = NULL;
		for( j = 0 ; j < NumZones ; j++ )
		{
			if( ( AreaPnt->group == i ) &&( AreaPnt->when_player_shoots != 0xffff ) )
			{
				if( !OldAreaPnt )
				{
					// found the first....
					GroupTriggerArea_player_shoots[i] = AreaPnt;
					OldAreaPnt = AreaPnt;
				}else{
					// found another
					OldAreaPnt->NextSameGroup_player_shoots = AreaPnt;
					OldAreaPnt = AreaPnt;
				}
			}
			AreaPnt++;
		}
	}
	for( i = 0 ; i < MAXGROUPS ; i++ )
	{
		AreaPnt = Zones;
		OldAreaPnt = NULL;
		for( j = 0 ; j < NumZones ; j++ )
		{
			if( ( AreaPnt->group == i ) &&( ( AreaPnt->when_enemy_isin != 0xffff ) ||
											( AreaPnt->when_enemy_enters != 0xffff ) ||
											( AreaPnt->when_enemy_exits != 0xffff ) ) )
			{
				if( !OldAreaPnt )
				{
					// found the first....
					GroupTriggerArea_enemy[i] = AreaPnt;
					OldAreaPnt = AreaPnt;
				}else{
					// found another
					OldAreaPnt->NextSameGroup_enemy = AreaPnt;
					OldAreaPnt = AreaPnt;
				}
			}
			AreaPnt++;
		}
	}
	for( i = 0 ; i < MAXGROUPS ; i++ )
	{
		AreaPnt = Zones;
		OldAreaPnt = NULL;
		for( j = 0 ; j < NumZones ; j++ )
		{
			if( ( AreaPnt->group == i ) &&( AreaPnt->when_enemy_shoots != 0xffff ) )
			{
				if( !OldAreaPnt )
				{
					// found the first....
					GroupTriggerArea_enemy_shoots[i] = AreaPnt;
					OldAreaPnt = AreaPnt;
				}else{
					// found another
					OldAreaPnt->NextSameGroup_enemy_shoots = AreaPnt;
					OldAreaPnt = AreaPnt;
				}
			}
			AreaPnt++;
		}
	}
	return TRUE;
}

/*�������������������������������������������������������������������
 	Procedure	:		Free any memory taken up with zone loading..
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
void ReleaseTriggerArea( void )
{
	int			i;
	TRIGGER_AREA * AreaPnt;

	if( Zones )
	{
		AreaPnt = Zones;

		for( i = 0 ; i < NumZones ; i++ )
		{
			if( AreaPnt->Zone )
			{
				free( AreaPnt->Zone );
			}
			AreaPnt++;
		}
		free(Zones);
		Zones = NULL;
	}
}


BOOL	Entry;
BOOL	Exit;
BOOL	In;
/*�������������������������������������������������������������������
 	Procedure	:		Check Player...
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
BOOL	TriggerAreaPlayerCheck( VECTOR * OldPos , VECTOR * NewPos , uint16 Group )
{
	TRIGGER_AREA * Area;

	Area = GroupTriggerArea_player[Group];
	while( Area )
	{
		if( Area->state == TRIGGER_AREA_STATE_On )
		{
			TriggerAreaProcess( OldPos , NewPos , Area );
			
			if( Entry )
			{
				if( Area->when_player_enters != 0xffff )
					ApplyTriggerMod( &TrigMods[Area->when_player_enters] );
			}
			if( In )
			{
				if( Area->when_player_isin != 0xffff )
					ApplyTriggerMod( &TrigMods[Area->when_player_isin] );
			}
			if( Exit )
			{
				if( Area->when_player_exits != 0xffff )
					ApplyTriggerMod( &TrigMods[Area->when_player_exits] );
			}
		}

		Area = Area->NextSameGroup_player;
	}
	return TRUE;
}

/*�������������������������������������������������������������������
 	Procedure	:		Check Player's shot hits trigger area...
	Input		:		VECTOR	*	Old Position 
				:		VECTOR	*	New Position 
				:		uint16		Group
				:		uint8		Weapon Type
				:		uint8		Weapon
	Output		:		BOOL		TRUE
�������������������������������������������������������������������*/
BOOL	TriggerAreaPlayerShootsCheck( VECTOR * OldPos , VECTOR * NewPos , uint16 Group, uint8 WeaponType, uint8 Weapon )
{
	TRIGGER_AREA * Area;
	BOOL	CanActivate;

	Area = GroupTriggerArea_player_shoots[Group];
	while( Area )
	{
		if( Area->state == TRIGGER_AREA_STATE_On )
		{
			CanActivate = FALSE;
			
			if( ( ( Area->player_primary != -1 )|| ( Area->player_secondary != -1 ) ) &&
				( ( Area->player_primary != 0 ) || ( Area->player_secondary != 0 ) ) )
			{
				switch( WeaponType )
				{
				case WEPTYPE_Primary:
					if( Weapon == Area->player_primary )
					{
						CanActivate = TRUE;
					}
					break;
					
				case WEPTYPE_Secondary:
					if( Weapon == Area->player_secondary )
					{
						CanActivate = TRUE;
					}
					break;
				}
			}
			else
			{
				CanActivate = TRUE;
			}
			if( CanActivate )
			{
				TriggerAreaProcess( OldPos , NewPos , Area );
				
//				if( Entry || In || Exit )
				if( Entry )			/* Entry only, trigger will not activate if bullet starts in zone */
				{
					if( Area->when_player_shoots != 0xffff )
						ApplyTriggerMod( &TrigMods[Area->when_player_shoots] );
				}
			}
		}

		Area = Area->NextSameGroup_player_shoots;
	}
	return TRUE;
}
/*�������������������������������������������������������������������
 	Procedure	:		Check Enemy...
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
BOOL	TriggerAreaEnemyCheck( VECTOR * OldPos , VECTOR * NewPos , uint16 Group )
{
	TRIGGER_AREA * Area;

	Area = GroupTriggerArea_enemy[Group];
	while( Area )
	{
		if( Area->state == TRIGGER_AREA_STATE_On )
		{
			TriggerAreaProcess( OldPos , NewPos , Area );
			
			if( Entry )
			{
				if( Area->when_enemy_enters != 0xffff )
					ApplyTriggerMod( &TrigMods[Area->when_enemy_enters] );
			}
			if( In )
			{
				if( Area->when_enemy_isin != 0xffff )
					ApplyTriggerMod( &TrigMods[Area->when_enemy_isin] );
			}
			if( Exit )
			{
				if( Area->when_enemy_exits != 0xffff )
					ApplyTriggerMod( &TrigMods[Area->when_enemy_exits] );
			}
		}

		Area = Area->NextSameGroup_enemy;
	}
	return TRUE;
}

/*�������������������������������������������������������������������
 	Procedure	:		Check Enemy's shot hits trigger area...
	Input		:		VECTOR	*	Old Position 
				:		VECTOR	*	New Position 
				:		uint16		Group
				:		uint8		Weapon Type
				:		uint8		Weapon
	Output		:		BOOL		TRUE
�������������������������������������������������������������������*/
BOOL	TriggerAreaEnemyShootsCheck( VECTOR * OldPos , VECTOR * NewPos , uint16 Group, uint8 WeaponType, uint8 Weapon )
{
	TRIGGER_AREA * Area;
	BOOL	CanActivate;

	Area = GroupTriggerArea_enemy_shoots[Group];
	while( Area )
	{
		if( Area->state == TRIGGER_AREA_STATE_On )
		{
			CanActivate = FALSE;
			
			if( ( ( Area->enemy_primary != -1 )|| ( Area->enemy_secondary != -1 ) ) &&
				( ( Area->enemy_primary != 0 ) || ( Area->enemy_secondary != 0 ) ) )
			{
				switch( WeaponType )
				{
				case WEPTYPE_Primary:
					if( Weapon == Area->enemy_primary )
					{
						CanActivate = TRUE;
					}
					break;
					
				case WEPTYPE_Secondary:
					if( Weapon == Area->enemy_secondary )
					{
						CanActivate = TRUE;
					}
					break;
				}
			}
			else
			{
				CanActivate = TRUE;
			}
			if( CanActivate )
			{
				TriggerAreaProcess( OldPos , NewPos , Area );
				
//				if( Entry || In || Exit )
				if( Entry )			/* Entry only, trigger will not activate if bullet starts in zone */
				{
					if( Area->when_enemy_shoots != 0xffff )
						ApplyTriggerMod( &TrigMods[Area->when_enemy_shoots] );
				}
			}
		}

		Area = Area->NextSameGroup_enemy_shoots;
	}
	return TRUE;
}


/*�������������������������������������������������������������������
 	Procedure	:		Check Ray to Col Zone
	Input		:		VECTOR	*	StartPos
				:		VECTOR	*	EndPos
				:		ZONESIDE *	Sides
				:		int16		NumSides
				:		VECTOR	*	Intersection Point ( TBFI )
				:		ZONESIDE **	Intersection Side ( TBFI )
				:		float		Collision Radius
	Output		:		void
�������������������������������������������������������������������*/
BOOL RayToHull( TRIGGER_ZONE * StartSide , VECTOR * StartPos , VECTOR * EndPos , uint16 StartNumSides )
{
	float		d1, d2;
	float		DistToPlane;
	TRIGGER_ZONE *	Sides;
	int16		NumSides;
	VECTOR		TempInt;
	int16		InsideCount = 0;

	Sides = StartSide;
	NumSides = StartNumSides;

	while( NumSides-- )
	{
		d1 = DotProduct( StartPos, &Sides->normal ) + Sides->offset;
		d2 = DotProduct( EndPos, &Sides->normal ) + Sides->offset;

		if( ( d1 >= 0.0F ) && ( d2 >= 0.0F ) ) return( FALSE );

		if( ( ( d1 > 0.0F ) && ( d2 < 0.0F ) ) || ( ( d1 < 0.0F ) && ( d2 > 0.0F ) ) )
		{
			DistToPlane = ( d1 / ( d1 - d2 ) );
			TempInt.x = StartPos->x + ( DistToPlane * ( EndPos->x - StartPos->x ) );
			TempInt.y = StartPos->y + ( DistToPlane * ( EndPos->y - StartPos->y ) );
			TempInt.z = StartPos->z + ( DistToPlane * ( EndPos->z - StartPos->z ) );

			if( ClassifyPointInHull( &TempInt, StartSide, StartNumSides, NumSides ) )
			{
				if( ( d1 < 0.0F ) && ( d2 > 0.0F ) )
				{
					Exit = TRUE;
//					return( TRUE );
				}

				if( ( d1 > 0.0F ) && ( d2 < 0.0F ) )
				{
					Entry = TRUE;
//					return( TRUE );
				}
			}
		}
		else
		{
			InsideCount++;
		}

		Sides++;
	}

	if( InsideCount == StartNumSides )
	{
		In = TRUE;
//		return( TRUE );
	}

	if( Entry || Exit || In ) return( TRUE );

	return( FALSE );
}

/*�������������������������������������������������������������������
 	Procedure	:		Is point inside convex shape?
	Input		:		VECTOR	*	Pos
				:		ZONESIDE *	Sides
				:		int16		NumSides
	Output		:		BOOL		TRUE/FALSE
�������������������������������������������������������������������*/
BOOL ClassifyPointInHull( VECTOR * Pos, TRIGGER_ZONE * Sides, int16 NumSides, int16 Side )
{
	float		d1;

	while( NumSides-- )
	{
		if( NumSides != Side )
		{
			d1 = DotProduct( Pos, &Sides->normal ) + Sides->offset;
			if( d1 > 0.0F ) return FALSE;
		}
		Sides++;
	}

	return TRUE;
}

/*�������������������������������������������������������������������
 	Procedure	:		Process and clasify 2 positions with an area..
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/

void TriggerAreaProcess( VECTOR * OldPos , VECTOR * NewPos , TRIGGER_AREA * Area )
{
	BOOL	OldIn;
	BOOL	NewIn;

	Entry = FALSE;
	Exit = FALSE;
	In = FALSE;
	if( Area->type == ZONE_Sphere )
	{
   		OldIn = DistanceVector2Vector( &Area->pos , OldPos ) < Area->half_size.x;
   		NewIn = DistanceVector2Vector( &Area->pos , NewPos ) < Area->half_size.x;

   		if( !OldIn && NewIn )
   			Entry = TRUE;
   		if( OldIn && !NewIn )
   			Exit = TRUE;
   		if( OldIn && NewIn )
   		{
   			In = TRUE;
   		}
   	}else{
   		RayToHull( Area->Zone , OldPos , NewPos , Area->num_sides );
   	}
}

/*
		If Both on positive side .....Miss...

		If Both on negative go on to next....

		different sides...calc intersection point...if on negative of all remaining then
													if started on positive then an entry..
													otherwise an exit...
													if started on positive then carryon with intersection and endpoint

*/

/*�������������������������������������������������������������������
 	Procedure	:		Display all trigger areas in group
	Input		:		uint16	Group
	Output		:		Nothing
�������������������������������������������������������������������*/
void DispGroupTriggerAreas( uint16 Group )
{
	TRIGGER_AREA * Area;

	if( !ShowTrigZones ) return;

	Area = GroupTriggerArea_player[Group];
	while( Area )
	{
		if( Area->state == TRIGGER_AREA_STATE_On )
		{
			if( Area->type == ZONE_Sphere )
			{
				DisplaySphereZone( &Area->pos, Area->half_size.x, Group, 0, 64, 0, 128 );
			}
			else
			{
				DisplayTriggerZone( Area->Zone, Area->num_sides, Group, 0, 64, 0 ,128 );
			}
		}
		else
		{
			if( Area->type == ZONE_Sphere )
			{
				DisplaySphereZone( &Area->pos, Area->half_size.x, Group, 64, 0, 64, 128 );
			}
			else
			{
				DisplayTriggerZone( Area->Zone, Area->num_sides, Group, 64, 0, 64 ,128 );
			}
		}
		Area = Area->NextSameGroup_player;
	}

	Area = GroupTriggerArea_player_shoots[Group];
	while( Area )
	{
		if( Area->state == TRIGGER_AREA_STATE_On )
		{
			if( Area->type == ZONE_Sphere )
			{
				DisplaySphereZone( &Area->pos, Area->half_size.x, Group, 0, 128, 0, 128 );
			}
			else
			{
				DisplayTriggerZone( Area->Zone, Area->num_sides, Group, 0, 128, 0 ,128 );
			}
		}
		else
		{
			if( Area->type == ZONE_Sphere )
			{
				DisplaySphereZone( &Area->pos, Area->half_size.x, Group, 64, 0, 64, 128 );
			}
			else
			{
				DisplayTriggerZone( Area->Zone, Area->num_sides, Group, 64, 0, 64 ,128 );
			}
		}
		Area = Area->NextSameGroup_player;
	}

	Area = GroupTriggerArea_enemy[Group];
	while( Area )
	{
		if( Area->state == TRIGGER_AREA_STATE_On )
		{
			if( Area->type == ZONE_Sphere )
			{
				DisplaySphereZone( &Area->pos, Area->half_size.x, Group, 0, 64, 0, 128 );
			}
			else
			{
				DisplayTriggerZone( Area->Zone, Area->num_sides, Group, 0, 64, 0, 128 );
			}
		}
		else
		{
			if( Area->type == ZONE_Sphere )
			{
				DisplaySphereZone( &Area->pos, Area->half_size.x, Group, 64, 0, 64, 128 );
			}
			else
			{
				DisplayTriggerZone( Area->Zone, Area->num_sides, Group, 64, 0, 64 ,128 );
			}
		}
		Area = Area->NextSameGroup_player;
	}

	Area = GroupTriggerArea_enemy_shoots[Group];
	while( Area )
	{
		if( Area->state == TRIGGER_AREA_STATE_On )
		{
			if( Area->type == ZONE_Sphere )
			{
				DisplaySphereZone( &Area->pos, Area->half_size.x, Group, 128, 0, 0, 128 );
			}
			else
			{
				DisplayTriggerZone( Area->Zone, Area->num_sides, Group, 128, 0, 0 ,128 );
			}
		}
		else
		{
			if( Area->type == ZONE_Sphere )
			{
				DisplaySphereZone( &Area->pos, Area->half_size.x, Group, 64, 0, 64, 128 );
			}
			else
			{
				DisplayTriggerZone( Area->Zone, Area->num_sides, Group, 64, 0, 64 ,128 );
			}
		}
		Area = Area->NextSameGroup_player;
	}
}



/*�������������������������������������������������������������������
 	Procedure	:		Enable trigger area
	Input		:		uint16	* Data
	Output		:		Nothing
�������������������������������������������������������������������*/
void EnableTriggerArea( uint16 * Data )
{
	TRIGGER_AREA * AreaPnt;
	AreaPnt = Zones;
	if( !AreaPnt )
		return;
	AreaPnt += *Data;
	AreaPnt->state = TRIGGER_AREA_STATE_On;
}


/*�������������������������������������������������������������������
 	Procedure	:		Disable trigger area
	Input		:		uint16	* Data
	Output		:		Nothing
�������������������������������������������������������������������*/
void DisableTriggerArea( uint16 * Data )
{
	TRIGGER_AREA * AreaPnt;
	AreaPnt = Zones;
	if( !AreaPnt )
		return;
	AreaPnt += *Data;
	AreaPnt->state = TRIGGER_AREA_STATE_Off;
}
/*�������������������������������������������������������������������
 	Procedure	:		Check Enemy...
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
void ProcessTriggerAreas( void )
{
	TRIGGER_AREA * Area;
	int i;
	Area = Zones;
	if( !Area )
		return;

	for( i = 0 ; i < NumZones ; i++ )
	{
		if( ( Area->state == TRIGGER_AREA_STATE_Off ) && ( Area->generation_type == TRIGGER_AREA_GENTYPE_Time ) && ( Area->generation_delay > 0.0F ) )
		{
			Area->generation_delay -= framelag;
			if( Area->generation_delay <= 0.0F )
			{
				Area->state = TRIGGER_AREA_STATE_On;
			}
		}
		Area++;
	}
}

/*�������������������������������������������������������������������
	Procedure	:	Save TriggerAreas arrays & Connected Global Variables
	Input		:	FILE	*	File Pointer
	Output		:	FILE	*	Updated File Pointer
�������������������������������������������������������������������*/
FILE * SaveTriggerAreas( FILE * fp )
{
	int				i;
	TRIGGER_AREA *	TrigAreaPtr;

	if( fp )
	{
		fwrite( &NumZones, sizeof( uint16 ), 1, fp );

		TrigAreaPtr = Zones;

		for( i = 0; i < NumZones; i++ )
		{
			fwrite( &TrigAreaPtr->state, sizeof( uint16 ), 1, fp );
			TrigAreaPtr++;
		}
	}

	return( fp );
}

/*�������������������������������������������������������������������
	Procedure	:	Load TriggerAreas Arrays & Connected Global Variables
	Input		:	FILE	*	File Pointer
	Output		:	FILE	*	Updated File Pointer
�������������������������������������������������������������������*/
FILE * LoadTriggerAreas( FILE * fp )
{
	int				i;
	TRIGGER_AREA *	TrigAreaPtr;
	uint16			NumTrigAreas;

	if( fp )
	{
		fread( &NumTrigAreas, sizeof( uint16 ), 1, fp );

		if( NumTrigAreas != NumZones )
		{
			fclose( fp );
			return( NULL );
		}

		TrigAreaPtr = Zones;

		for( i = 0; i < NumZones; i++ )
		{
			fread( &TrigAreaPtr->state, sizeof( uint16 ), 1, fp );
			TrigAreaPtr++;
		}
	}

	return( fp );
}


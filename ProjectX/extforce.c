/*
 * The X Men, October 1997
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * $Revision: 15 $
 *
 * $Header: /PcProjectX/extforce.c 15    11/11/98 16:00 Philipy $
 *
 * $Log: /PcProjectX/extforce.c $
 * 
 * 15    11/11/98 16:00 Philipy
 * various fixes for warnings / errors when compiling under VC6
 * 
 * 14    25/08/98 8:50 Collinsd
 * Added checksum call to all loaded files.
 * 
 * 13    14/03/98 18:58 Collinsd
 * Added godmode and made debug mode work even when you change level.
 * 
 * 12    18/02/98 9:53 Collinsd
 * Added Save/load functions for Timer/Temp guage and trigger areas
 * 
 * 11    17/02/98 16:35 Collinsd
 * Added ExternalForce and Teleports load/save function.
 * 
 * 10    19/12/97 17:02 Collinsd
 * No damage if in debug mode
 * 
 * 9     12/12/97 17:45 Oliverc
 * 
 * 8     11/29/97 4:35p Phillipd
 * Xmem is now in effect...use it allways....
 * 
 * 7     18/11/97 12:40 Oliverc
 * Added origin, up, width, and height to external force, and changed
 * force calculation accordingly
 * 
 * 6     11/11/97 15:39 Collinsd
 * Fixed lots of bugs. ( in deallocation of buffers ).
 * 
 * 5     24/10/97 10:01 Collinsd
 * Added display of all zones/forces.
 * 
 * 4     10/17/97 11:48a Phillipd
 * 
 * 3     10/14/97 4:46p Phillipd
 * 
 * 2     10/09/97 3:29p Phillipd
 * External forces coming...
 * Shield and Hull now floats
 * 
 * 1     10/09/97 12:16p Phillipd
 * 
 */

/*�������������������������������������������������������������������
		Include Files...	
�������������������������������������������������������������������*/
#include <stdio.h>
#include "typedefs.h"
#include "main.h"
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
#include "pickups.h"
#include "enemies.h"
#include "mload.h"
#include "water.h"
#include "spotfx.h"
#include "Trigarea.h"
#include "ExtForce.h"
#include "magic.h"
#include "Ships.h"
#include "Skin.h"
#include "XMem.h"

/*�������������������������������������������������������������������
		Defines
�������������������������������������������������������������������*/
#define	EXTERNALFORCES_VERSION_NUMBER	2

																   
/*�������������������������������������������������������������������
		Externals ...
�������������������������������������������������������������������*/
extern	GLOBALSHIP		Ships[ MAX_PLAYERS ];
extern	float framelag;
void DebugPrintf( const char * format, ... );
extern	BOOL	Entry;
extern	BOOL	Exit;
extern	BOOL	In;
extern	BOOL	ShowEFZones;
extern	BOOL	DebugInfo;
extern	BOOL	GodMode;
BOOL RayToHull( TRIGGER_ZONE * StartSide , VECTOR * StartPos , VECTOR * EndPos , uint16 StartNumSides );

/*�������������������������������������������������������������������
		Globals ...
�������������������������������������������������������������������*/
int32	NumOfExternalForces = 0;

EXTERNALFORCE * ExternalForcesGroupLink[MAXGROUPS];

EXTERNALFORCE * ExternalForces = NULL;

/*�������������������������������������������������������������������
	Procedure	:	External Forces load...
	Input		:	char * filename....
	Output		:	BOOL
�������������������������������������������������������������������*/
BOOL ExternalForcesLoad( char * Filename )
{
	long			File_Size;
	long			Read_Size;
	char		*	Buffer;
	uint16		*	Uint16Pnt;
	EXTERNALFORCE * EFpnt;
	float * floatpnt;
	int i,j;
	TRIGGER_ZONE * ZonePnt;
	uint32			MagicNumber;
	uint32			VersionNumber;
	uint32		*	uint32Pnt;
	int32		*	int32Pnt;
	char		*	OrgBuffer;


	NumOfExternalForces = 0;
	for( i = 0 ; i < MAXGROUPS ; i++ )
	{
		ExternalForcesGroupLink[i] = NULL;
	}

	FileCheckSum( Filename );
	
	File_Size = Get_File_Size( Filename );	
	if( !File_Size )
	{
		// dont need External Forces..
		return TRUE;
	}
	Buffer = malloc( File_Size );
	OrgBuffer = Buffer;

	if( !Buffer )
	{
		Msg( "External Forces Load : Unable to allocate file buffer %s\n", Filename );
		return( FALSE );
	}
	Read_Size = Read_File( Filename, Buffer, File_Size );
	if( Read_Size != File_Size )
	{
		Msg( "External Forces Load Error reading %s\n", Filename );
		return( FALSE );
	}
	uint32Pnt = (int32 *) Buffer;
	MagicNumber = *uint32Pnt++;
	VersionNumber = *uint32Pnt++;
	Buffer = (char *) uint32Pnt;

	if( ( MagicNumber != MAGIC_NUMBER ) || ( VersionNumber != EXTERNALFORCES_VERSION_NUMBER  ) )
	{
		Msg( "ExternalForcesLoad() Incompatible ( .efc ) file %s", Filename );
		return( FALSE );
	}



	int32Pnt = (int32 *) Buffer;
	NumOfExternalForces = *int32Pnt++;
	Buffer = (char *) int32Pnt;

	ExternalForces	= (EXTERNALFORCE *) malloc( NumOfExternalForces * sizeof(EXTERNALFORCE) );
	EFpnt = ExternalForces;
	if( !EFpnt )
	{
		Msg( "External Forces : cant allocate buffer %s\n", Filename );
		return( FALSE );
	}
	

	for( i = 0 ; i < NumOfExternalForces ; i++ )
	{
		Uint16Pnt = (uint16 *) Buffer;
		EFpnt->Status = *Uint16Pnt++;
		EFpnt->ForceType = *Uint16Pnt++;
		EFpnt->Group = *Uint16Pnt++;
		Buffer = (char *) Uint16Pnt;

		if( ExternalForcesGroupLink[EFpnt->Group] )
		{
			EFpnt->NextInGroup = ExternalForcesGroupLink[EFpnt->Group];
			ExternalForcesGroupLink[EFpnt->Group] = EFpnt;
		}else{
			ExternalForcesGroupLink[EFpnt->Group] = EFpnt;
			EFpnt->NextInGroup = NULL;
		}

		floatpnt = (float *) Buffer;
		EFpnt->Origin.x = *floatpnt++;
		EFpnt->Origin.y = *floatpnt++;
		EFpnt->Origin.z = *floatpnt++;
		EFpnt->Dir.x = *floatpnt++;
		EFpnt->Dir.y = *floatpnt++;
		EFpnt->Dir.z = *floatpnt++;
		EFpnt->Up.x = *floatpnt++;
		EFpnt->Up.y = *floatpnt++;
		EFpnt->Up.z = *floatpnt++;
		EFpnt->MinForce = *floatpnt++;
		EFpnt->MaxForce = *floatpnt++;
		EFpnt->Width = *floatpnt++;
		EFpnt->Height = *floatpnt++;
		EFpnt->Range = 1.0F / *floatpnt++;
		Buffer = (char *) floatpnt;

		Uint16Pnt = (uint16 *) Buffer;
		EFpnt->Type = *Uint16Pnt++;
		Buffer = (char *) Uint16Pnt;
		floatpnt = (float *) Buffer;

		EFpnt->Pos.x = *floatpnt++;
		EFpnt->Pos.y = *floatpnt++;
		EFpnt->Pos.z = *floatpnt++;
		EFpnt->half_size.x = *floatpnt++;
		EFpnt->half_size.y = *floatpnt++;
		EFpnt->half_size.z = *floatpnt++;
		Buffer = (char *) floatpnt;
		
		if( EFpnt->Type != ZONE_Sphere )
		{
			// convex hull...
			Uint16Pnt = (uint16 *) Buffer;
			EFpnt->num_sides = *Uint16Pnt++;
			Buffer = (char *) Uint16Pnt;
			
			EFpnt->Zone = (TRIGGER_ZONE*) malloc( EFpnt->num_sides * sizeof( TRIGGER_ZONE ) );
			ZonePnt = EFpnt->Zone;
			
			if( !ZonePnt )
			{
				Msg( "External Forces maloc Error with %s\n", Filename );
				return( FALSE );
			}
			floatpnt = (float * ) Buffer;
			for( j = 0 ; j < EFpnt->num_sides ; j++ )
			{
				ZonePnt->normal.x = *floatpnt++;
				ZonePnt->normal.y = *floatpnt++;
				ZonePnt->normal.z = *floatpnt++;
				ZonePnt->offset   = *floatpnt++;
				ZonePnt++;
			}
			Buffer = (char*) floatpnt;
		}
		
		EFpnt++;
	}
	free( OrgBuffer );

	return TRUE;
}
/*�������������������������������������������������������������������
	Procedure	:	Release Forces load...
	Input		:	void
	Output		:	void
�������������������������������������������������������������������*/
void ReleaseExternalForces( void )
{
	int i;
	EXTERNALFORCE * EFpnt;
	EFpnt = ExternalForces;

	if( EFpnt )
	{
		for( i = 0 ; i < NumOfExternalForces ; i++ )
		{
			if( EFpnt->Zone )
			{
				free( EFpnt->Zone );
			}
			EFpnt++;
		}
		free(ExternalForces);
		ExternalForces = NULL;
	}
	NumOfExternalForces = 0;
}

/*�������������������������������������������������������������������
	Procedure	:	Check if im in an Active External Force....
	Input		:	void
	Output		:	TRUE/FALSE
�������������������������������������������������������������������*/
BOOL ExternalForcesAreaCheck( VECTOR * OldPos , VECTOR * NewPos , uint16 Group , VECTOR * ExtForce , float * Shield )
{
	EXTERNALFORCE * EFpnt;
	float	Distance;
	float	Power;
	float	Force;
	BOOL	OnehasEffectedMe = FALSE;

	EFpnt = ExternalForcesGroupLink[Group];
	
	while( EFpnt )
	{
		if( EFpnt->Status == EXTERNALFORCEACTIVE )
		{
			ExternalForcesZoneCheck( OldPos , NewPos , EFpnt );
			if( In | Entry | Exit )
			{
				// Were in the Zone....
				OnehasEffectedMe = TRUE;

				Distance = DistanceVector2Vector( &EFpnt->Origin , NewPos );
				Power =  1.0F - (Distance * EFpnt->Range );		// how much of the force is needed...
				if ( Power < 0.0F )
					Power = 0.0F;
				Force = EFpnt->MaxForce - EFpnt->MinForce;	// how much of the range of Force is needed
				Force *= Power;
				Force += EFpnt->MinForce;					// the minimum needs to be added back in...

				switch( EFpnt->ForceType )
				{
				case EXTERNALFORCETYPE_Shield:
					if( !GodMode )
					{
						*Shield += (Force * framelag);
					}
					break;
				case EXTERNALFORCETYPE_Move:
					ExtForce->x += (EFpnt->Dir.x * Force) * framelag;
					ExtForce->y += (EFpnt->Dir.y * Force) * framelag;
					ExtForce->z += (EFpnt->Dir.z * Force) * framelag;
					break;
				case EXTERNALFORCETYPE_Shake:
					StartShipScreenShake( Force );
					break;
				}
			}
		}
		EFpnt = EFpnt->NextInGroup;
	}
	return OnehasEffectedMe;

}

/*�������������������������������������������������������������������
	Procedure	:	Display External Forces
	Input		:	uint16	Group
	Output		:	Nothing
�������������������������������������������������������������������*/
void DisplayExternalForcesInGroup( uint16 Group )
{
	EXTERNALFORCE * EFpnt;

	if( !ShowEFZones ) return;

	EFpnt = ExternalForcesGroupLink[Group];
	
	while( EFpnt )
	{
		if( EFpnt->Status == EXTERNALFORCEACTIVE )
		{
			switch( EFpnt->ForceType )
			{
				case EXTERNALFORCETYPE_Shield:
				case EXTERNALFORCETYPE_Shake:
					break;
				case EXTERNALFORCETYPE_Move:
					DisplayZoneDirection( &EFpnt->Origin, &EFpnt->Dir, Group );
					break;
			}

			if( EFpnt->Type == ZONE_Sphere )
			{
				DisplaySphereZone( &EFpnt->Pos, EFpnt->half_size.x, Group, 0, 64, 0, 128 );
			}
			else
			{
				DisplayTriggerZone( EFpnt->Zone, EFpnt->num_sides, Group, 0, 64, 0, 128 );
			}
		}
		else
		{
			if( EFpnt->Type == ZONE_Sphere )
			{
				DisplaySphereZone( &EFpnt->Pos, EFpnt->half_size.x, Group, 0, 64, 0, 128 );
			}
			else
			{
				DisplayTriggerZone( EFpnt->Zone, EFpnt->num_sides, Group, 0, 64, 0, 128 );
			}
		}
		EFpnt = EFpnt->NextInGroup;
	}
}


/*�������������������������������������������������������������������
	Procedure	:	Check if im in a External Force Zone....
	Input		:	void
	Output		:	void
�������������������������������������������������������������������*/
void ExternalForcesZoneCheck( VECTOR * OldPos , VECTOR * NewPos , EXTERNALFORCE * EFpnt )
{

	BOOL	OldIn;
	BOOL	NewIn;
	Entry = FALSE;
	Exit = FALSE;
	In = FALSE;
	if( EFpnt->Type == ZONE_Sphere )
	{
   		OldIn = DistanceVector2Vector( &EFpnt->Pos , OldPos ) < EFpnt->half_size.x;
   		NewIn = DistanceVector2Vector( &EFpnt->Pos , NewPos ) < EFpnt->half_size.x;
   		if( !OldIn && NewIn )
   			Entry = TRUE;
   		if( OldIn && !NewIn )
   			Exit = TRUE;
   		if( OldIn && NewIn )
   		{
   			In = TRUE;
   		}
   	}else{
   		RayToHull( EFpnt->Zone , OldPos , NewPos , EFpnt->num_sides );
   	}
}


/*�������������������������������������������������������������������
	Procedure	:	Start an external force..
	Input		:	void
	Output		:	void
�������������������������������������������������������������������*/
void StartExternalForce( uint16 * Data )
{
	EXTERNALFORCE * EFpnt;
	EFpnt = ExternalForces;
	if( !EFpnt )
		return;
	EFpnt += *Data;
	EFpnt->Status = EXTERNALFORCEACTIVE;
}
/*�������������������������������������������������������������������
	Procedure	:	Stop an external force..
	Input		:	void
	Output		:	void
�������������������������������������������������������������������*/
void StopExternalForce( uint16 * Data )
{
	EXTERNALFORCE * EFpnt;
	EFpnt = ExternalForces;
	if( !EFpnt )
		return;
	EFpnt += *Data;
	EFpnt->Status = EXTERNALFORCEINACTIVE;
}

/*�������������������������������������������������������������������
	Procedure	:	Save ExtForses arrays & Connected Global Variables
	Input		:	FILE	*	File Pointer
	Output		:	FILE	*	Updated File Pointer
�������������������������������������������������������������������*/
FILE * SaveExternalForces( FILE * fp )
{
	int				i;
	EXTERNALFORCE *	ExtForcesPtr;

	if( fp )
	{
		fwrite( &NumOfExternalForces, sizeof( int16 ), 1, fp );

		ExtForcesPtr = ExternalForces;

		for( i = 0; i < NumOfExternalForces; i++ )
		{
			fwrite( &ExtForcesPtr->Status, sizeof( uint16 ), 1, fp );
			ExtForcesPtr++;
		}
	}

	return( fp );
}

/*�������������������������������������������������������������������
	Procedure	:	Load ExtForces Arrays & Connected Global Variables
	Input		:	FILE	*	File Pointer
	Output		:	FILE	*	Updated File Pointer
�������������������������������������������������������������������*/
FILE * LoadExternalForces( FILE * fp )
{
	int				i;
	EXTERNALFORCE *	ExtForcesPtr;
	int16			NumExtForces;

	if( fp )
	{
		fread( &NumExtForces, sizeof( int16 ), 1, fp );

		if( NumExtForces != NumOfExternalForces )
		{
			fclose( fp );
			return( NULL );
		}

		ExtForcesPtr = ExternalForces;

		for( i = 0; i < NumOfExternalForces; i++ )
		{
			fread( &ExtForcesPtr->Status, sizeof( uint16 ), 1, fp );
			ExtForcesPtr++;
		}
	}

	return( fp );
}


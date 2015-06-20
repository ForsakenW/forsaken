/*
 * The X Men, January 1997
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * $Revision: 57 $
 *
 * $Header: /PcProjectX/Bsp.c 57    22/10/98 12:02p Oliverc $
 *
 * $Log: /PcProjectX/Bsp.c $
 * 
 * 57    22/10/98 12:02p Oliverc
 * Added BSP corruption check code (temporary)
 * 
 * 56    25/08/98 8:50 Collinsd
 * Added checksum call to all loaded files.
 * 
 * 55    6/12/97 19:31 Oliverc
 * Level loading now fails if no BSP found in BSP_ONLY mode
 * 
 * 54    5/12/97 17:46 Oliverc
 * 1st version of tidied BSP collision routines
 * 
 * 53    11/29/97 4:35p Phillipd
 * Xmem is now in effect...use it allways....
 * 
 * 52    27/11/97 12:32 Oliverc
 * Fixed bug in PISDistRecursive() and added bounding box check to
 * PointInsideSkin() if no BSP available
 * 
 * 51    22/11/97 14:27 Oliverc
 * Fixed bug in FindCollision() for parallel rays
 * 
 * 50    17/11/97 18:41 Oliverc
 * Added loading/freeing of new portal BSP info
 * 
 * 49    11/13/97 2:10p Phillipd
 * 
 * 48    11/12/97 11:39a Phillipd
 * 
 * 47    11/06/97 5:39p Phillipd
 * 
 * 46    17/10/97 12:27 Oliverc
 * Added MAGIC+VERSION to BSP loading
 * 
 * 45    16/09/97 16:26 Oliverc
 * Aborted attempt at variable thickness BSP collision routine (disabled
 * at present -- define BSP2 in bsp.c & collision.c to re-enable if
 * desired)
 * 
 * 44    8/11/97 12:08p Phillipd
 * 
 * 43    7/08/97 9:03 Collinsd
 * Changed bsp collision to return valid point so far.
 * 
 * 42    5/07/97 16:31 Collinsd
 * Put OPT_ON's around opimisations off
 * 
 * 41    6/07/97 4:10p Phillipd
 * 
 * 40    2/06/97 15:45 Oliverc
 * Re-enabled accurate BSP plane collision point calculation
 * 
 * 39    16/05/97 15:54 Oliverc
 * New BSP stuff (should be compatible with old...)
 * 
 * 38    26/04/97 14:49 Collinsd
 * Optimisations now on def.
 * 
 * 37    4/17/97 10:12a Phillipd
 * 
 * 36    4/15/97 4:43p Phillipd
 * 
 * 35    4/09/97 10:00a Phillipd
 * 
 * 34    4/08/97 12:39p Phillipd
 * 
 * 33    4/08/97 9:58a Phillipd
 * 
 * 32    4/07/97 3:20p Phillipd
 * 
 * 31    4/07/97 2:38p Phillipd
 * 
 * 30    4/07/97 12:27p Phillipd
 * 
 * 29    4/04/97 9:30a Phillipd
 * 
 * 28    4/03/97 9:20a Phillipd
 * 
 * 27    4/02/97 11:44a Phillipd
 * 
 * 26    4/02/97 8:51a Phillipd
 * Bsps enabled...
 * 
 * 25    14/02/97 15:44 Oliverc
 * Made BSP code dependent on #define
 * 
 * 24    12-02-97 12:03p Collinsd
 * Added error checking to readfiles();  Also added triggers to enemies.
 * 
 * 23    5-02-97 3:00p Collinsd
 * Just got rid of warnings.
 * 
 * 22    30-01-97 3:47p Collinsd
 * 
 * 21    30/01/97 9:10 Oliverc
 * 
 * 20    29/01/97 11:08 Oliverc
 * 
 * 19    1/27/97 12:16p Phillipd
 * 
 * 18    1/27/97 12:01p Phillipd
 * 
 * 17    1/25/97 5:32p Phillipd
 * 
 * 16    1/25/97 10:45a Phillipd
 * 
 * 15    1/24/97 9:19a Phillipd
 * 
 * 14    1/23/97 3:55p Phillipd
 * 
 * 13    1/23/97 11:50a Phillipd
 * 
 * 12    1/23/97 11:36a Phillipd
 * now slide doesnt slide you less than the fudge factor..
 * 
 * 11    23-01-97 10:45a Collinsd
 * 
 * 10    1/23/97 9:37a Phillipd
 * New Bsp collsions v1.0
 * 
 * 9     1/22/97 2:43p Phillipd
 * 
 * 8     1/22/97 2:24p Phillipd
 * 
 * 7     21/01/97 9:12 Oliverc
 * 
 * 6     1/21/97 9:10a Phillipd
 * 
 * 5     20/01/97 14:46 Oliverc
 * Changed BSP RayCollide() to output normal and offset of plane hit
 * directly
 * 
 * 4     20/01/97 9:36 Oliverc
 * fixed 1 bug in BSP collision (but still not perfect)
 * 
 * 3     1/17/97 6:04p Phillipd
 * 
 * 2     1/15/97 5:58p Phillipd
 * 
 * 1     1/15/97 5:33p Phillipd
 */

/*�������������������������������������������������������������������
		Include Files...	
�������������������������������������������������������������������*/
#include "typedefs.h"
#include "main.h"
#include "new3d.h"
#include "quat.h"
#include "mload.h"
#include "bsp.h"
#include "file.h"
#include "magic.h"
#include "XMem.h"


#define BSP_VERSION_NUMBER	(1)
#define BSP_PORTAL_VERSION_NUMBER	(1)

#define BSP_ONLY

#ifdef OPT_ON
#pragma optimize( "gty", on )
#endif



/*�������������������������������������������������������������������
		Externals ...
�������������������������������������������������������������������*/
extern	int	Depth;
extern MLOADHEADER Mloadheader;

extern BOOL AmIOutsideGroup( MLOADHEADER * m, VECTOR * EndPos, uint16 EndGroup );

/*�������������������������������������������������������������������
		Globals ...
�������������������������������������������������������������������*/
BOOL FindCollision( BSP_NODE * node_ptr, VECTOR * start_point_ptr, VECTOR * end_point_ptr );
void DebugPrintf( const char * format, ... );

BSP_HEADER Bsp_Header[ 2 ];
float ColRad;
																   
BSP_NODE *	BSP_Nodes[256];
BSP_PORTAL_HEADER Bsp_Portal_Header = { FALSE, 0 };


BOOL Bsp_Duplicate( BSP_HEADER *src, BSP_HEADER *dup )
{
	int j;
	BSP_TREE *srctree, *duptree;

	dup->State = src->State;
	dup->NumGroups = src->NumGroups;
	for ( j = 0; j < src->NumGroups; j++ )
	{
		srctree = &src->Bsp_Tree[ j ];
		duptree = &dup->Bsp_Tree[ j ];
		duptree->NumNodes = srctree->NumNodes;
		duptree->Root = (BSP_NODE *) calloc( srctree->NumNodes, sizeof( BSP_NODE ) );
		if ( !duptree->Root )
			return FALSE;
		memcpy( duptree->Root, srctree->Root, srctree->NumNodes * sizeof( BSP_NODE ) );
	}
	return TRUE;
}


BOOL Bsp_Identical( BSP_HEADER *b1, BSP_HEADER *b2 )
{
	int j;
	BSP_TREE *b1tree, *b2tree;

	if ( b1->State != b2->State )
		return FALSE;
	if ( b1->NumGroups != b2->NumGroups )
		return FALSE;
	for ( j = 0; j < b1->NumGroups; j++ )
	{
		b1tree = &b1->Bsp_Tree[ j ];
		b2tree = &b2->Bsp_Tree[ j ];
		if ( b1tree->NumNodes != b2tree->NumNodes )
			return FALSE;
		if ( memcmp( b1tree->Root, b2tree->Root, b1tree->NumNodes * sizeof( BSP_NODE ) ) )
			return FALSE;
	}
	return TRUE;
}


static BOOL BSP_Loadtree( BSP_TREE *t, char **Buffer )
{
	BSP_RAWNODE * Raw;
	BSP_NODE * New;
	int16		*	int16pnt;
	int16		e;

	int16pnt = ( int16 * ) *Buffer;
	t->NumNodes = *int16pnt++;
	*Buffer = (char * ) int16pnt;
	
	t->Root = (BSP_NODE * ) calloc( t->NumNodes , sizeof( BSP_NODE ) );

	if ( !t->Root )
	{
		return FALSE;
	}
	
	Raw = (BSP_RAWNODE *) *Buffer;
	New = t->Root;
	
	New->Parent = NULL;
	
	for( e = 0 ; e < t->NumNodes ; e++ )
	{
		New->Normal = Raw->Normal;
		New->Offset = Raw->Offset;
		New->Colour = Raw->Colour;
		if( !Raw->Front ) New->Front = NULL;
		else{
			New->Front = t->Root + Raw->Front;
			New->Front->Parent = New;
		}
		if( !Raw->Back ) New->Back = NULL;
		else{
			New->Back  = t->Root + Raw->Back;
			New->Back->Parent = New;
		}
		New++;
		Raw++;
	}
	*Buffer = (char*) Raw;

	return TRUE;
}


static BOOL BSP_LoadPortal( BSP_PORTAL *p, char **Buffer )
{
	int16	*	int16pnt;
	float	*	floatpnt;

	int16pnt = (int16 *) *Buffer;
	p->group = *int16pnt++;
	floatpnt = (float *) int16pnt;
	p->normal.x = *floatpnt++;
	p->normal.y = *floatpnt++;
	p->normal.z = *floatpnt++;
	p->offset = *floatpnt++;
	*Buffer = (char *) floatpnt;

	return BSP_Loadtree( &p->bsp, Buffer );
}


static BOOL BSP_LoadPortalGroup( BSP_PORTAL_GROUP *pg, char **Buffer )
{
	int16		*	int16pnt;
	int				i;

	int16pnt = (int16 *) *Buffer;
	pg->portals = *int16pnt++;
	*Buffer = (char *) int16pnt;

	pg->portal = (BSP_PORTAL *) calloc( pg->portals, sizeof( BSP_PORTAL ) );
	for ( i = 0; i < pg->portals; i++ )
	{
		if ( !BSP_LoadPortal( &pg->portal[ i ], Buffer ) )
		{
			return FALSE;
		}
	}

	return TRUE;
}


static BOOL BSP_LoadPortals( char *fname )
{
	char	Filename[ 256 ];
	long			File_Size;
	long			Read_Size;
	char		*	Buffer;
	char		*	OrgBuffer;
	int16		*	int16pnt;
	int16			i;
	uint32		*	Uint32Pnt;
	uint32			MagicNumber;
	uint32			VersionNumber;

	Bsp_Portal_Header.state = FALSE;

	Change_Ext( fname, Filename, ".PBS" );

	FileCheckSum( Filename );

	File_Size = Get_File_Size( Filename );	
	if( !File_Size )
	{
		Msg( "Bsp_Portalload() no PBS file %s", Filename );
		return FALSE;
	}

	Buffer = malloc( File_Size );
	OrgBuffer = Buffer;

	if( Buffer == NULL ) return FALSE;

	Read_Size = Read_File( Filename, Buffer, File_Size );

	if( Read_Size != File_Size ) return FALSE;

	Uint32Pnt = (uint32 *) Buffer;
	MagicNumber = *Uint32Pnt++;
	VersionNumber = *Uint32Pnt++;
	Buffer = (char *) Uint32Pnt;

	if( ( MagicNumber != MAGIC_NUMBER ) || ( VersionNumber != BSP_PORTAL_VERSION_NUMBER  ) )
	{
		Msg( "Bsp_Portalload() Incompatible PBS file %s", Filename );
		return( FALSE );
	}
	int16pnt = ( int16 * ) Buffer;
	Bsp_Portal_Header.groups = *int16pnt++;
	Buffer = (char * ) int16pnt;

	for ( i = 0; i < Bsp_Portal_Header.groups; i++ )
	{
		if ( !BSP_LoadPortalGroup( &Bsp_Portal_Header.group[ i ], &Buffer ) )
		{
			return FALSE;
		}
	}

	free( OrgBuffer );

	Bsp_Portal_Header.state = TRUE;

	return TRUE;
}

/*�������������������������������������������������������������������
	Procedure	:		Load .Bsp File
	Input		:		char	*	Filename
	Output		:		BOOL	TRUE/FALSE
�������������������������������������������������������������������*/
BOOL Bspload( char * Filename, BSP_HEADER *Bsp_Header )
{
#ifdef BSP
	long			File_Size;
	long			Read_Size;
	char		*	Buffer;
	char		*	OrgBuffer;
	int16		*	int16pnt;
	int16			i;
	uint32		*	Uint32Pnt;
	uint32			MagicNumber;
	uint32			VersionNumber;

	Bsp_Header->State = FALSE;

	FileCheckSum( Filename );

	File_Size = Get_File_Size( Filename );	
	if( !File_Size )
	{
		Msg( "Bspload() no BSP file %s", Filename );
		return FALSE;
	}

	Buffer = malloc( File_Size );

	if( Buffer == NULL ) return FALSE;

	OrgBuffer = Buffer;

	Read_Size = Read_File( Filename, Buffer, File_Size );

	if( Read_Size != File_Size ) return FALSE;

	Uint32Pnt = (uint32 *) Buffer;
	MagicNumber = *Uint32Pnt++;
	VersionNumber = *Uint32Pnt++;
	Buffer = (char *) Uint32Pnt;

	if( ( MagicNumber != MAGIC_NUMBER ) || ( VersionNumber != BSP_VERSION_NUMBER  ) )
	{
		Msg( "Bspload() Incompatible BSP file %s", Filename );
		return( FALSE );
	}
	int16pnt = ( int16 * ) Buffer;
	Bsp_Header->NumGroups = *int16pnt++;
	Buffer = (char * ) int16pnt;

	for( i = 0 ; i < Bsp_Header->NumGroups ; i++ )
	{
		if ( !BSP_Loadtree( &Bsp_Header->Bsp_Tree[ i ], &Buffer ) )
		{
			return FALSE;
		}
	}
	free( OrgBuffer );

#endif
	Bsp_Header->State = TRUE;

#ifdef BSP_ONLY
	if ( !BSP_LoadPortals( Filename ) )
		return FALSE;
#else
	BSP_LoadPortals( Filename );
#endif

	return TRUE;
}
/*�������������������������������������������������������������������
	Procedure	:		Free up the memory calloced by bspload..
	Input		:		Nothing
	Output		:		BOOL	TRUE/FALSE
�������������������������������������������������������������������*/
void Bspfree( void )
{
#ifdef BSP
	int			i;
	int			bsp_num;

	for ( bsp_num = 0; bsp_num < MAX_BSP_MODELS; bsp_num++ )
	{
		if ( Bsp_Header[ bsp_num ].State )
		{
			for( i = 0 ; i < Bsp_Header[ bsp_num ].NumGroups ; i++ )
			{
				if( Bsp_Header[ bsp_num ].Bsp_Tree[i].Root )
				{
					free(Bsp_Header[ bsp_num ].Bsp_Tree[i].Root);
					Bsp_Header[ bsp_num ].Bsp_Tree[i].Root = NULL;
				}
			}
			Bsp_Header[ bsp_num ].NumGroups = 0;
			Bsp_Header[ bsp_num ].State = FALSE;
		}
	}

	if ( Bsp_Portal_Header.state )
	{
		int					j;
		BSP_PORTAL_GROUP	*pg;
		BSP_PORTAL			*bp;

		for ( i = 0; i < Bsp_Portal_Header.groups; i++ )
		{
			pg = &Bsp_Portal_Header.group[ i ];
			for ( j = 0; j < pg->portals; j++ )
			{
				bp = &pg->portal[ j ];
				if ( bp->bsp.Root )
					free( bp->bsp.Root );
				bp->bsp.Root = NULL;
			}
			if ( pg->portal )
				free( pg->portal );
			pg->portal = NULL;
			pg->portals = 0;
		}
		Bsp_Portal_Header.state = FALSE;
	}
#endif
}


#define POINT_TO_PLANE( P, N ) ( (P)->x * (N)->Normal.x + (P)->y * (N)->Normal.y + (P)->z * (N)->Normal.z + ( (N)->Offset) )

static VECTOR RayPos;
static VECTOR RayDir;
static float RayLength;
float	Trick;
BOOL Collided;
float CollideDist;
VECTOR CollidePoint;
BSP_NODE *CollideNode;
BSP_NODE *OldCollideNode;
VECTOR OldCollidePoint;
float CollisionRadius = 0.0F;

BOOL RayCollide( BSP_HEADER *Bsp_Header, VECTOR *StartPos, VECTOR *Dir, VECTOR *ImpactPoint, VECTOR *ImpactNormal, float *ImpactOffset , uint16 group)
{
	BOOL collided;
	VECTOR EndPos;

 	RayLength = VectorLength( Dir );
	CollideNode = NULL;
	RayPos = *StartPos;
	RayDir = *Dir;
	EndPos.x = StartPos->x + Dir->x;
	EndPos.y = StartPos->y + Dir->y;
	EndPos.z = StartPos->z + Dir->z;
	Depth = 0;

	collided = FindCollision( Bsp_Header->Bsp_Tree[ group % Bsp_Header->NumGroups ].Root, StartPos, &EndPos );
	
	if ( collided && CollideNode )
	{
		OldCollideNode = CollideNode;
		OldCollidePoint = CollidePoint;
		*ImpactPoint = CollidePoint;
   		*ImpactNormal = CollideNode->Normal;
   		*ImpactOffset = CollideNode->Offset - CollisionRadius;

#if 0	// Shouldnt need this if all opposite co-planear faces are not used as splitting planes...
		Trick = ( ImpactNormal->x * Dir->x + ImpactNormal->y * Dir->y + ImpactNormal->z * Dir->z ) / RayLength;
		if ( Trick > 0.001F )
   		{
   			ImpactNormal->x = -ImpactNormal->x;
   			ImpactNormal->y = -ImpactNormal->y;
   			ImpactNormal->z = -ImpactNormal->z;
   			*ImpactOffset = -*ImpactOffset;
   		}
#endif
   		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


/*�������������������������������������������������������������������
	Procedure	:		Define if a ray hits a solid..
	Input		:		BSP_NODE * Start node
						VECTOR * Start Position
						VECTOR * end Position
	Output		:		BOOL
�������������������������������������������������������������������*/
BOOL FindCollision( BSP_NODE * node_ptr, VECTOR * start_point_ptr, VECTOR * end_point_ptr )
{
	float		d1, d2;
	VECTOR		intersection_point;
	BSP_NODE	* near_node_ptr;
	BSP_NODE	* far_node_ptr;
	float div;
	float distance2plane;
	BOOL	side;

	Depth++;
start:
	d1 = POINT_TO_PLANE( start_point_ptr, node_ptr ) - CollisionRadius;
	d2 = POINT_TO_PLANE(   end_point_ptr, node_ptr ) - CollisionRadius;

    if( d1 < TOLER && d1 > -TOLER ) d1 = 0.0F;
    if( d2 < TOLER && d2 > -TOLER )
	{
		if( d1 == 0 )
		{
			// d1 + d2 = 0 Parallel ray....
			BSP_NODE *Back_CollideNode;
			VECTOR Back_CollidePoint;

			if ( node_ptr->Back && node_ptr->Front )
			{
				if ( FindCollision( node_ptr->Back, start_point_ptr, end_point_ptr ) )
				{
					Back_CollideNode = CollideNode;
					Back_CollidePoint = CollidePoint;
					if ( FindCollision( node_ptr->Front, start_point_ptr, end_point_ptr ) )
					{
						VECTOR dv;

						dv.x = Back_CollidePoint.x - start_point_ptr->x;
						dv.y = Back_CollidePoint.y - start_point_ptr->y;
						dv.z = Back_CollidePoint.z - start_point_ptr->z;
						d1 = VectorLength( &dv );
						dv.x = CollidePoint.x - start_point_ptr->x;
						dv.y = CollidePoint.y - start_point_ptr->y;
						dv.z = CollidePoint.z - start_point_ptr->z;
						d2 = VectorLength( &dv );
						if ( d1 < d2 )
						{
							CollideNode = Back_CollideNode;
							CollidePoint = Back_CollidePoint;
						}
					}
					else
					{
						CollideNode = Back_CollideNode;
						CollidePoint = Back_CollidePoint;
					}
					return TRUE;
				}
				else
				{
					return FindCollision( node_ptr->Front, start_point_ptr, end_point_ptr );
				}
			}
			else if ( node_ptr->Back )
			{
				return FindCollision( node_ptr->Back, start_point_ptr, end_point_ptr );
			}
			else if ( node_ptr->Front )
			{
				return FindCollision( node_ptr->Front, start_point_ptr, end_point_ptr );
			}
			else // oh shit...what do we do now???
			{
				return FALSE;
			}

			return TRUE;
		}
		d2 = 0.0F;
	}

	if( (d1 < -CollisionRadius) && (d2 < -CollisionRadius) )
	{
		if( node_ptr = node_ptr->Back )
		{
			goto start;
		}
		// Entire segment inside a solid.
		return TRUE;
	}
	if( (d1 >= CollisionRadius) && (d2 >= CollisionRadius) )
	{
		if( node_ptr = node_ptr->Front )
		{
			goto start;
		}
		return FALSE;
	}
   	// We intersect the Plane...


	div = ( RayDir.x * node_ptr->Normal.x) + 
   		  ( RayDir.y * node_ptr->Normal.y) + 
   		  ( RayDir.z * node_ptr->Normal.z);
	distance2plane = POINT_TO_PLANE( &RayPos , node_ptr ) - CollisionRadius;

   	distance2plane = distance2plane / div;
   	intersection_point.x = RayPos.x - ( RayDir.x * distance2plane );
   	intersection_point.y = RayPos.y - ( RayDir.y * distance2plane );
   	intersection_point.z = RayPos.z - ( RayDir.z * distance2plane );
   	
	if( side = d1 < 0 )
   	{
   		near_node_ptr = node_ptr->Back;
   		far_node_ptr = node_ptr->Front;
   	}else{
   		near_node_ptr = node_ptr->Front;
   		far_node_ptr = node_ptr->Back;
   	}

   	if( ( !near_node_ptr && ( side ) ) ||
   		( near_node_ptr && FindCollision( near_node_ptr, start_point_ptr, &intersection_point ) ) )
   	{
   		return TRUE;
   	}
	CollideNode = node_ptr;
	CollidePoint = intersection_point;
	if ( !far_node_ptr )
	{
		if ( side )
			return FALSE;
		return TRUE;
	}
	return FindCollision( far_node_ptr, &intersection_point, end_point_ptr );
}





/*�������������������������������������������������������������������
	Procedure	:		Define if a point is inside or outside
	Input		:		VECTOR * Pos , Node *node
	Output		:		BOOL
�������������������������������������������������������������������*/

BOOL PISDistRecursive( VECTOR *Pos, BSP_NODE *node)
{
	float d;

start:
	// go down the BSP tree
	d = node->Normal.x * Pos->x + node->Normal.y * Pos->y + node->Normal.z * Pos->z + node->Offset;
	if ( d > TOLER  )
	{ // definitely in front of plane
	 	if ( node = node->Front )
	 	{
	 		goto start;
	 	}
	 	else
	 	{
	 		return TRUE;
	 	}
	}
	if ( d < -TOLER )
	{ // definitely behind plane
		if ( node = node->Back )
		{
			goto start;
		}
		OldCollideNode = node;
		return FALSE;
	}
	// somewhere in between plane +/- TOLER (tricky case)
	if ( !node->Front || PISDistRecursive( Pos, node->Front ) )
		return TRUE;
	if ( node->Back && PISDistRecursive( Pos, node->Back ) )
		return TRUE;
	return FALSE;
}



BOOL PointInsideSkin( VECTOR *Pos, uint16 Group )
{
	if( Bsp_Header[ 0 ].State )
	{
		return PISDistRecursive( Pos, Bsp_Header[0].Bsp_Tree[ Group % Bsp_Header[0].NumGroups ].Root );
	}
	return !AmIOutsideGroup( &Mloadheader, Pos, Group );
 }




#ifdef OPT_ON
#pragma optimize( "", off )
#endif

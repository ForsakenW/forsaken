														   /*
 * The X Men, January 1997
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * $Revision: 13 $
 *
 * $Header: /PcProjectX/Include/Bsp.h 13    17/11/97 18:41 Oliverc $
 *
 * $Log: /PcProjectX/Include/Bsp.h $
 * 
 * 13    17/11/97 18:41 Oliverc
 * Added loading/freeing of new portal BSP info
 * 
 * 12    11/06/97 5:39p Phillipd
 * 
 * 11    16/05/97 15:54 Oliverc
 * New BSP stuff (should be compatible with old...)
 * 
 * 10    4/08/97 9:58a Phillipd
 * 
 * 9     4/02/97 11:44a Phillipd
 * 
 * 8     4/02/97 8:51a Phillipd
 * Bsps enabled...
 * 
 * 7     1/24/97 9:19a Phillipd
 * 
 * 6     1/23/97 3:55p Phillipd
 * 
 * 5     1/22/97 2:24p Phillipd
 * 
 * 4     1/21/97 9:10a Phillipd
 * 
 * 3     20/01/97 14:46 Oliverc
 * Changed BSP RayCollide() to output normal and offset of plane hit
 * directly
 * 
 * 2     1/17/97 6:04p Phillipd
 * 
 * 1     1/15/97 5:33p Phillipd
 * 
 */
#ifndef BSP_INCLUDED
#define BSP_INCLUDED

/*
 * Defines
 */
#define TOLER (0.03125)	//0.0000076F 
#define INSIDE 1
#define OUTSIDE -1
#define ONPLANE 0
 

#define MAX_BSP_MODELS	(2)
/*
 * Structures
 */
 typedef struct BSP_RAWNODE
 {
	VECTOR	Normal;
	float	Offset;
	int		Front;
	int		Back;
	int		Colour;
 }BSP_RAWNODE;

typedef struct BSP_NODE
{
    VECTOR	Normal;
    float	Offset;
	int		Colour;
struct	BSP_NODE * Parent;
struct	BSP_NODE * Front;
struct	BSP_NODE * Back;
}BSP_NODE;
 
typedef struct BSP_TREE
{
   int	NumNodes;
   BSP_NODE * Root;
}BSP_TREE;

typedef struct BSP_HEADER
{
	BOOL	State;
    int NumGroups;
    BSP_TREE Bsp_Tree[MAXGROUPS];
}BSP_HEADER;


typedef struct _BSP_PORTAL
{
	uint16		group;
	VECTOR		normal;
	float		offset;
	BSP_TREE	bsp;
} BSP_PORTAL;

typedef struct _BSP_PORTAL_GROUP
{
	int			portals;
	BSP_PORTAL	*portal;
} BSP_PORTAL_GROUP;


typedef struct _BSP_PORTAL_HEADER
{
	BOOL		state;
	int			groups;
	BSP_PORTAL_GROUP	group[ MAXGROUPS ];
} BSP_PORTAL_HEADER;


/*
 * global vars
 */
extern	BSP_HEADER Bsp_Header[];
extern	BSP_PORTAL_HEADER Bsp_Portal_Header;


 /*
 * fn prototypes
 */
void Bspfree( void );
BOOL Bspload( char * Filename,  BSP_HEADER *Bsp_Header );
BOOL InBSPGroup( uint16 group, VECTOR *pos );
BOOL RayCollide( BSP_HEADER *Bsp_Header, VECTOR *StartPos, VECTOR *Dir, VECTOR *ImpactPoint, VECTOR *ImpactNormal, float *ImpactOffset ,uint16 group );

BOOL PointInSpaceRecursive( VECTOR *Pos );

BOOL PointInsideSkin( VECTOR *Pos, uint16 Group );
#endif	// BSP_INCLUDED



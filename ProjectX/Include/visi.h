/*
 * v i s i .h
 *
 * visipoly Routines
 *
 * Project X, June 1996
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * Authors: Oliverc, Phillipd, Collinsd
 */

#ifndef VISI_INCLUDED
#define VISI_INCLUDED

#include "typedefs.h"
#include <math.h>
#include <time.h>
#include "New3D.h"
#include "Mload.h"
#include "ships.h"
#include "lights.h"
#include "skin.h"
#include "d3d.h"
#include "camera.h"

typedef struct _GROUPLIST
{
    int groups;
    uint16 *group;
} GROUPLIST;

// indirectly visible groups seen by any active camera
uint16 Num_IndirectVisible;
uint16 IndirectVisible[ MAXGROUPS ];

/*
 * fn prototypes
 */
BOOL LightGroupDispGroup( MLOADHEADER   * Mloadheader);

BOOL DispVisipolyModel( MLOADHEADER * Mloadheader) ;
void FindGroupImIn( MLOADHEADER * Mloadheader);
uint16 WhichGroupImIn( MLOADHEADER  * Mloadheader , VECTOR * Pos );
BOOL PortalTestTransformClip( MLOADHEADER * Mloadheader , uint16 group );
void FindVisiblePortals( MLOADHEADER * Mloadheader , uint16 group );
void BuildGroupList ( MLOADHEADER * Mloadheader , uint16 group );
void  OurVispolyTransformVertices( DWORD VertexCount, D3DTRANSFORMDATA * Data );
void FindVisible( CAMERA *cam, MLOADHEADER  * Mloadheader );
int ClipGroup( CAMERA *cam, uint16 group );
BOOL DisplayBackground( MLOADHEADER * Mloadheader, CAMERA *cam );
void InitVisiStats( MLOADHEADER *m );
BOOL OutputVisiStats( MLOADHEADER *m, char *lname );

BOOL FindGroupConnections( MLOADHEADER *m );
void FreeGroupConnections( void );
GROUPLIST *ConnectedGroups( uint16 g );
GROUPLIST *VisibleGroups( uint16 g );
GROUPLIST *IndirectVisibleGroups( uint16 g );
int VisibleOverlap( uint16 g1, uint16 g2, uint16 *overlapping_group );
BOOL GroupsAreVisible( uint16 g1, uint16 g2 );
BOOL GroupsAreConnected( uint16 g1, uint16 g2 );
BOOL GroupsAreIndirectVisible( uint16 g1, uint16 g2 );

uint16 FindClipGroup( CAMERA *cam, MLOADHEADER *m, VECTOR *min, VECTOR *max );
uint16 FindOverlappingVisibleGroups( CAMERA *cam, MLOADHEADER *m, VECTOR *min, VECTOR *max, uint16 * group );
BOOL PointInGroupBoundingBox( MLOADHEADER * Mloadheader, VECTOR * Pos, uint16 group );


#ifdef SOFTWARE_ENABLE
/*---------------------------------------------------------------------------
    Chris Walsh's code
---------------------------------------------------------------------------*/
void  MyVispolyTransformVertices( DWORD VertexCount, D3DTRANSFORMDATA * Data );
BOOL CWDisplayBackground( MLOADHEADER   * Mloadheader, CAMERA *cam );
void    CWExecute( D3DEXECUTEBUFFERDESC *debDesc, long NumVertsToXform);
void    CWExecute2( LPDIRECT3DDEVICE lpDev,
                    LPDIRECT3DEXECUTEBUFFER execbuf,
                    LPDIRECT3DVIEWPORT lpView,
                    WORD cwFlags);
/*-------------------------------------------------------------------------*/
#endif

#endif  // VISI_INCLUDED
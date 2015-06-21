/*
 * The X Men, June 1996
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * Authors: Phillipd, Collinsd
 */

/*==========================================================================
 *
 *
 *  File:       Lights.h
 *  Content:    Lights.c include file
 *
 *
 ***************************************************************************/

#ifndef LIGHTS_INCLUDED
#define LIGHTS_INCLUDED

#include <math.h>
#include "d3dmain.h"
#include "typedefs.h"
#include "New3D.h"
#include <time.h>
#include "Ships.h"
#include "exechand.h"
#include "Mload.h"
#include "Mxload.h"
#include "Mxaload.h"
#include "collision.h"
#include "ddutil.h"

/*
 * defines
 */
#define MAXXLIGHTS  256
#define POINT_LIGHT 0
#define SPOT_LIGHT  1
 
 
/*
 * structures
 */

 typedef struct XLIGHT{
    int     Type;
    BOOL    Visible;
    uint16  Index;
    float   r;
    float   g;
    float   b;
    float   Size;
    float   SizeCount;
    float   ColorCount;
    float   CosArc;         // how wide is my light.......
    uint16  Next;           // Next Free
    uint16  Prev;           // Previous used...
    VECTOR  Pos;
    VECTOR  Dir;            // Normalised....
    uint16  Group;
struct XLIGHT * NextVisible;
 }XLIGHT;

 /*
 * fn prototypes
 */

BOOL    ProcessXLights( MLOADHEADER * Mloadheader );
void    InitXLights();
uint16  FindFreeXLight();
void    KillUsedXLight(uint16);

//BOOL  DoIEffectThisGroup( MLOADHEADER * MloadHeader , VECTOR * Pos , float size , uint16 group);

void    SetLightDie ( uint16 light );
BOOL    XLight1Group( MLOADHEADER * Mloadheader, uint16 group );

BOOL    XLightMxloadHeader( MXLOADHEADER * MXloadheader , VECTOR * Pos , float Radius , MATRIX * Matrix );
BOOL    XLightMxaloadHeader( MXALOADHEADER * MXAloadheader , VECTOR * Pos , float Radius , MATRIX * Matrix );


void    CreateCellColours( MLOADHEADER * Mloadheader );
D3DCOLOR FindNearestCellColour( MLOADHEADER * Mloadheader,VECTOR * Pos, uint16 group );
void BuildVisibleLightList( uint16 Group );
FILE * SaveXLights( FILE * fp );
FILE * LoadXLights( FILE * fp );

#endif // LIGHTS_INCLUDED



/*�������������������������������������������������������������������
*	l i n e s . c
*	All routines to do with lines...
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

#include "lines.h"
#include "camera.h"

extern	CAMERA	CurrentCamera;
extern	BOOL	UsedStippledAlpha;
extern	BOOL	DebugInfo;

/*�������������������������������������������������������������������
	Globals
�������������������������������������������������������������������*/
LINE	Lines[ MAXLINES ];
uint16	FirstLineUsed;
uint16	FirstLineFree;

/*�������������������������������������������������������������������
	Procedure	:	Init Line Structures and Execute buffer
	Input		:	Nothing
	Output		:	Nothing
�������������������������������������������������������������������*/
void InitLines( void )
{
	int i;

	FirstLineUsed = (uint16) -1;
	FirstLineFree = 0;
	
	for( i=0; i < MAXLINES; i++ )
	{
		Lines[i].StartPos.x = 0.0F;
		Lines[i].StartPos.y = 0.0F;
		Lines[i].StartPos.z = 0.0F;
		Lines[i].EndPos.x = 0.0F;
    	Lines[i].EndPos.y = 0.0F;
		Lines[i].EndPos.z = 0.0F;
		Lines[i].StartCol.R = 0;
		Lines[i].StartCol.G = 0;
		Lines[i].StartCol.B = 0;
		Lines[i].EndCol.R = 0;
		Lines[i].EndCol.G = 0;
		Lines[i].EndCol.B = 0;
		Lines[i].Next = i + 1;
		Lines[i].Prev = (uint16) -1;
	}
	Lines[ MAXLINES-1 ].Next = (uint16) -1;
}

/*�������������������������������������������������������������������
	Procedure	:	Find a free Line and move it from the free list to
					the used list
	Input		:	Nothing
	Output		:	uint16	Number of the free Line
�������������������������������������������������������������������*/
uint16 FindFreeLine( void )
{
	uint16 i;

	i = FirstLineFree;
	if( i == (uint16) -1 ) return i;
 
	Lines[i].Prev = FirstLineUsed;

	if ( FirstLineUsed != (uint16) -1)
	{
		Lines[ FirstLineUsed ].Next = i;
	}

	FirstLineUsed = i;
	FirstLineFree = Lines[i].Next;

	return i ;
}

/*�������������������������������������������������������������������
	Procedure	:	Kill a used Line and move it from the used list
				:	to the free list
	Input		:	uint16		Number of Line to free....
	Output		:	Nothing
�������������������������������������������������������������������*/
void KillUsedLine( uint16 i )
{
	uint16	its_prev;
	uint16	its_next;
	
	its_prev = Lines[ i ].Prev;
	its_next = Lines[ i ].Next;

	if( i == FirstLineUsed ) FirstLineUsed = Lines[ i ].Prev;
	if( its_prev != (uint16) -1 ) Lines[ its_prev ].Next = its_next;
	if( its_next != (uint16) -1 ) Lines[ its_next ].Prev = its_prev;

	Lines[i].Prev = (uint16) -1;
	Lines[i].Next = FirstLineFree;
	FirstLineFree	= i;
}

/*�������������������������������������������������������������������
	Procedure	:	Display All Faceme Polygons in specific group
	Input		:	uint16	Group
				:	LPDIRECT3DEXECUTEBUFFER ExecBuffer
				:	uint16	* StartLine
	Output		:	Nothing
�������������������������������������������������������������������*/
BOOL LinesDispGroup( uint16 Group, LPDIRECT3DEXECUTEBUFFER ExecBuffer, uint16 * StartLine )
{
	D3DEXECUTEBUFFERDESC ExecBuffer_debdesc;
	D3DEXECUTEDATA	ExecBuffer_d3dexdata;
	LPD3DLVERTEX	Vert_Ptr;
	LPD3DLINE		Line_Ptr;
    LPVOID			lpBufStart, lpInsStart, lpPointer;
	D3DCOLOR		color;
	D3DCOLOR		specular;
	int16			Num_Lines;
	uint16			i;
	int16			Count;

	if ( !DebugInfo )
	{
		*StartLine = (uint16) -1;
		return FALSE; // don't display lines if not debugging
	}

	if(d3dapp->CurrDriver != 0)	specular = RGB_MAKE( 255, 255, 255 );
	else specular = RGB_MAKE( 128, 128, 128 );
		
	if( *StartLine != (uint16) -1 )
	{
		memset( &ExecBuffer_debdesc, 0, sizeof(D3DEXECUTEBUFFERDESC));
		ExecBuffer_debdesc.dwSize = sizeof(D3DEXECUTEBUFFERDESC);
		
		if( ExecBuffer->lpVtbl->Lock( ExecBuffer, &ExecBuffer_debdesc ) != D3D_OK) return FALSE;
		
		lpBufStart = ExecBuffer_debdesc.lpData;
		lpPointer = lpBufStart;
		
		Vert_Ptr = (LPD3DLVERTEX) lpPointer;

		Num_Lines = 0;

		i = *StartLine;

		while( i != (uint16) -1 )
		{
			if( Lines[ i ].Group == Group )
			{
				if(d3dapp->CurrDriver != 0)
				{
					if( UsedStippledAlpha != TRUE )
					{
						color = RGBA_MAKE( Lines[ i ].StartCol.R, Lines[ i ].StartCol.G,
										   Lines[ i ].StartCol.B, Lines[ i ].StartTrans );
					}
					else
					{
						color = RGBA_MAKE( Lines[ i ].StartCol.R, Lines[ i ].StartCol.G,
										   Lines[ i ].StartCol.B, Lines[ i ].StartTrans / 2 );
					}
				}
				else
				{
					color = RGBA_MAKE( 128, 128, 128, 255 );
				}
	
				Vert_Ptr->x = Lines[ i ].StartPos.x;
				Vert_Ptr->y = Lines[ i ].StartPos.y;
				Vert_Ptr->z = Lines[ i ].StartPos.z;
				Vert_Ptr->tu = 0.0F;
				Vert_Ptr->tv = 0.0F;
				Vert_Ptr->color = color;
				Vert_Ptr->specular = specular;
				Vert_Ptr->dwReserved = 0;
				Vert_Ptr++;
	
				if(d3dapp->CurrDriver != 0)
				{
					if( UsedStippledAlpha != TRUE )
					{
						color = RGBA_MAKE( Lines[ i ].EndCol.R, Lines[ i ].EndCol.G,
										   Lines[ i ].EndCol.B, Lines[ i ].EndTrans );
					}
					else
					{
						color = RGBA_MAKE( Lines[ i ].EndCol.R, Lines[ i ].EndCol.G,
										   Lines[ i ].EndCol.B, Lines[ i ].EndTrans / 2 );
					}
				}
				else
				{
					color = RGBA_MAKE( 128, 128, 128, 255 );
				}
	
				Vert_Ptr->x = Lines[ i ].EndPos.x;
				Vert_Ptr->y = Lines[ i ].EndPos.y;
				Vert_Ptr->z = Lines[ i ].EndPos.z;
				Vert_Ptr->tu = 0.0F;
				Vert_Ptr->tv = 0.0F;
				Vert_Ptr->color = color;
				Vert_Ptr->specular = specular;
				Vert_Ptr->dwReserved = 0;
				Vert_Ptr++;
	
				Num_Lines++;

				if( Num_Lines >= 400 ) break;
			}

			i = Lines[ i ].Prev;
		}

/*�������������������������������������������������������������������
		Create Execution buffer instructions
�������������������������������������������������������������������*/
		lpPointer = (LPVOID ) Vert_Ptr;
		lpInsStart = lpPointer;

		if( Num_Lines != 0 )
		{
			OP_STATE_RENDER( 2, lpPointer );
			    STATE_DATA( D3DRENDERSTATE_WRAPU, FALSE, lpPointer );
			    STATE_DATA( D3DRENDERSTATE_WRAPV, FALSE, lpPointer );
	   		OP_STATE_LIGHT( 1, lpPointer );
	   		    STATE_DATA( D3DLIGHTSTATE_MATERIAL, 0, lpPointer );
	   		OP_PROCESS_VERTICES( 1, lpPointer );
	   		    PROCESSVERTICES_DATA( D3DPROCESSVERTICES_TRANSFORM, 0, ( Num_Lines * 2 ), lpPointer );
	   		OP_STATE_RENDER( 1, lpPointer );
	   		    STATE_DATA( D3DRENDERSTATE_TEXTUREHANDLE, 0, lpPointer );
			OP_LINE_LIST( Num_Lines, lpPointer );
			
	   		Line_Ptr = (LPD3DLINE) lpPointer;
			
	   		for( Count = 0; Count < Num_Lines; Count++ )
	   		{
   				Line_Ptr->v1 = ( ( Count * 2 ) + 0 );
   				Line_Ptr->v2 = ( ( Count * 2 ) + 1 );
				Line_Ptr++;
			}
			
			lpPointer = ( LPVOID ) Line_Ptr;

			OP_EXIT( lpPointer );
		}

/*�������������������������������������������������������������������
		Finish off execution list
�������������������������������������������������������������������*/
		ExecBuffer->lpVtbl->Unlock( ExecBuffer );

		*StartLine = i;
		
		if( Num_Lines == 0 ) return FALSE;

		memset( &ExecBuffer_d3dexdata, 0, sizeof(D3DEXECUTEDATA) );
		ExecBuffer_d3dexdata.dwSize = sizeof(D3DEXECUTEDATA);
		ExecBuffer_d3dexdata.dwVertexCount = ( Num_Lines * 2 );
		ExecBuffer_d3dexdata.dwInstructionOffset = (ULONG) ( (char *) lpInsStart - (char *) lpBufStart );
		ExecBuffer_d3dexdata.dwInstructionLength = (ULONG) ( (char *) lpPointer - (char *) lpInsStart );
		if( ( ExecBuffer->lpVtbl->SetExecuteData( ExecBuffer, &ExecBuffer_d3dexdata ) ) != D3D_OK) return FALSE;
	}
	else
	{
		return FALSE;
	}

	return TRUE;
}

/*
 * The X Men, June 1996
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * $Revision: 5 $
 *
 * $Header: /PcProjectX/Exechand.c 5     28/01/98 12:56 Oliverc $
 *
 * $Log: /PcProjectX/Exechand.c $
 * 
 * 5     28/01/98 12:56 Oliverc
 * Changed allocation checking to working on DEBUG_ON flag instead of the
 * generic _DEBUG
 * 
 * 4     12/01/97 3:27p Phillipd
 * 
 * 3     1/10/97 4:25p Phillipd
 * 
 * 2     6/25/96 11:37a Phillipd
 * First SS update
 * 
 */

/*==========================================================================
 *
 *  File: exechand.c
***************************************************************************/

/*-------------------------------------------------------------------
        Include File... 
-------------------------------------------------------------------*/
#include <malloc.h>
#include "typedefs.h"
#include "d3ddemo.h"

size_t  ExecMemUsed = 0;
#ifdef DEBUG_ON
/*-------------------------------------------------------------------
        externs...  
-------------------------------------------------------------------*/
Msg( LPSTR fmt, ... );
void DebugPrintf( const char * format, ... );

/*-------------------------------------------------------------------
        Defines...  
-------------------------------------------------------------------*/
#define MAXEXECBLOCKS 2048

/*-------------------------------------------------------------------
        Globals...  
-------------------------------------------------------------------*/

BOOL    ExecBlockUsed[MAXEXECBLOCKS];
LPDIRECT3DEXECUTEBUFFER ExecBlockPnts[MAXEXECBLOCKS];
size_t  ExecBlockSize[MAXEXECBLOCKS];
char *  ExecBlockInFile[MAXEXECBLOCKS];
int     ExecBlockInLine[MAXEXECBLOCKS];
int ExecBlocksUsed = 0;
/*-------------------------------------------------------------------
    Procedure   :   X Exec Init...
    Input       :   void
    Output      :   void
-------------------------------------------------------------------*/
void XExec_Init( void )
{
    int i;
    ExecMemUsed =0;
    for( i = 0 ; i < MAXEXECBLOCKS ; i++ )
    {
        ExecBlockUsed[i] = FALSE;
        ExecBlockPnts[i] = NULL;
        ExecBlockSize[i] = 0;
    }
}

/*-------------------------------------------------------------------
    Procedure   :   X Exec Find Free...
    Input       :   void
    Output      :   int Free memblock -1 if none
-------------------------------------------------------------------*/
int XExec_FindFree( void )
{
    int i;
    for( i = 0 ; i < MAXEXECBLOCKS ; i++ )
    {
        if( !ExecBlockUsed[i] )
        {
            ExecBlocksUsed++;
            return i;
        }
    }
    return -1;
}
/*-------------------------------------------------------------------
    Procedure   :   X Exec Find Same Block...
    Input       :   void * Pnt
    Output      :   int Same memblock -1 if none
-------------------------------------------------------------------*/
int XExec_FindSame( LPDIRECT3DEXECUTEBUFFER Pnt )
{
    int i;
    for( i = 0 ; i < MAXEXECBLOCKS ; i++ )
    {
        if( ExecBlockUsed[i] && ( ExecBlockPnts[i] == Pnt ) )
            return i;
    }
    return -1;
}

/*-------------------------------------------------------------------
        Make Execute Buffer
-------------------------------------------------------------------*/

BOOL XMakeExecuteBuffer(  LPD3DEXECUTEBUFFERDESC    debDesc , LPDIRECT3DDEVICE lpDev , LPDIRECT3DEXECUTEBUFFER  * lpBuf , size_t size , char *in_file, int in_line )
{
    int i;
    i = XExec_FindFree();
    if( i == -1 )
    {
        Msg( "Ran out of free Exec Blocks");
        return FALSE;
    }
 
    memset(debDesc, 0, sizeof(D3DEXECUTEBUFFERDESC));
    debDesc->dwSize = sizeof(D3DEXECUTEBUFFERDESC);
    debDesc->dwFlags = D3DDEB_BUFSIZE;
    debDesc->dwBufferSize = size;
    if (lpDev->lpVtbl->CreateExecuteBuffer(lpDev, debDesc, lpBuf, NULL) != D3D_OK)
        return FALSE;

    ExecBlockUsed[i] = TRUE;
    ExecBlockPnts[i] = *lpBuf;
    ExecBlockSize[i] = size;
    ExecBlockInFile[i] = in_file;
    ExecBlockInLine[i] = in_line;
    ExecMemUsed += size;
    return TRUE;
}

/*-------------------------------------------------------------------
    Procedure   :   XRELEASE free some memory from an execute buffer...
    Input       :   void * Pnt
    Output      :   void
-------------------------------------------------------------------*/
void EXECRELEASE( LPDIRECT3DEXECUTEBUFFER Pnt, char *in_file, int in_line )
{
    int i;
    static char *last_file = NULL;
    static int last_line = -1;

    if ( !Pnt )
    {
        if ( in_file != last_file || in_line != last_line )
            Msg( "Tried to free NULL Exec block in %s line %d", in_file, in_line );
        last_file = in_file;
        last_line = in_line;
        return;
    }
    i = XExec_FindSame( Pnt );
    if( i == -1 )
    {
        if ( in_file != last_file || in_line != last_line )
            Msg( "Tried to free un-malloced Exec block in %s line %d", in_file, in_line );
        last_file = in_file;
        last_line = in_line;
        return;
    }

    Pnt->lpVtbl->Release(Pnt);
    ExecBlockUsed[i] = FALSE;
    ExecBlockPnts[i] = NULL;
    ExecBlockInFile[ i ] = NULL;
    ExecBlockInLine[ i ] = 0;

    ExecMemUsed -= ExecBlockSize[i];

    ExecBlockSize[i] = 0;
    ExecBlocksUsed--;
}

int UnMallocedExecBlocks( void )
{
    int i;

    if ( ExecBlocksUsed )
    {
        for ( i = 0; i < MAXEXECBLOCKS; i++ )
        {
            if ( ExecBlockUsed[ i ] )
            {
                DebugPrintf( "ExecBlock size %d allocated in %s line %d but not freed\n",
                    ExecBlockSize[ i ], ExecBlockInFile[ i ], ExecBlockInLine[ i ] );
            }
        }
    }
    DebugPrintf( "ExecMemUsed = %d   ExecBlocksUsed = %d\n",
        ExecMemUsed, ExecBlocksUsed );
    return ExecBlocksUsed;
}


#else // DEBUG_ON
/*-------------------------------------------------------------------
        Make Execute Buffer
-------------------------------------------------------------------*/

BOOL MakeExecuteBuffer(  LPD3DEXECUTEBUFFERDESC debDesc , LPDIRECT3DDEVICE lpDev , LPDIRECT3DEXECUTEBUFFER  * lpBuf , size_t size )
{
    memset(debDesc, 0, sizeof(D3DEXECUTEBUFFERDESC));
    debDesc->dwSize = sizeof(D3DEXECUTEBUFFERDESC);
    debDesc->dwFlags = D3DDEB_BUFSIZE;
    debDesc->dwBufferSize = size;
    if (lpDev->lpVtbl->CreateExecuteBuffer(lpDev, debDesc, lpBuf, NULL) != D3D_OK)
        return FALSE;

    return TRUE;
}
#endif // DEBUG_ON

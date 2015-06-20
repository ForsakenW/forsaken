/*
 * The X Men, June 1996
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * $Revision: 7 $
 *
 * $Header: /PcProjectX/SBufferHand.c 7     28/02/98 16:18 Philipy $
 *
 * $Log: /PcProjectX/SBufferHand.c $
 * 
 * 7     28/02/98 16:18 Philipy
 * fixed memory leak
 * sfx loader does not now try to load sfx into hw if it knows that there
 * are insufficient resources
 * added buffer valid check b4 modifying looping sfx
 * 
 * 6     17/02/98 17:12 Philipy
 * check for buffer in hw now fixed
 * 
 * 5     12/02/98 11:27 Philipy
 * releasing buffer now sets pointer to NULL to try and trap error
 * 
 * 4     11/02/98 12:57 Philipy
 * sbufferhand now gives call stack to 2 levels
 * 
 * 3     10/02/98 9:39 Philipy
 * fixed release build bug
 * 
 * 2     9/02/98 12:21 Philipy
 * added sound buffer memory managment
 * only one piece of bike computer speech can now play at a time
 * 
 * 1     5/02/98 17:31 Philipy
 * 
 * 
 */

/*==========================================================================
 *
 *  File: exechand.c
***************************************************************************/

/*�������������������������������������������������������������������
		Include File...	
�������������������������������������������������������������������*/
#include <malloc.h>
#include "typedefs.h"
#include "sbufferhand.h"
#include "dsutil.h"
#include "sfx.h"

size_t	SBufferMemUsedSW = 0;
size_t	SBufferMemUsedHW = 0;
size_t	MaxSBufferMemUsedHW = 0;
size_t	MaxSBufferMemUsedSW = 0;
/*�������������������������������������������������������������������
		externs...	
�������������������������������������������������������������������*/
//Msg( LPSTR fmt, ... );
void DebugPrintf( const char * format, ... );

/*�������������������������������������������������������������������
		Defines...	
�������������������������������������������������������������������*/
#define	MAXSBUFFERBLOCKS 512
#define MAXPTRSPERBUFFER ( ( MAX_COMPOUND_BUFFERS > MAX_DUP_BUFFERS ) ? MAX_COMPOUND_BUFFERS : MAX_DUP_BUFFERS )
/*�������������������������������������������������������������������
		Globals...	
�������������������������������������������������������������������*/

BOOL	SBufferBlockUsed[MAXSBUFFERBLOCKS];
BOOL	SBufferBlockHW[MAXSBUFFERBLOCKS];
LPDIRECTSOUNDBUFFER	SBufferBlockPnts[MAXSBUFFERBLOCKS][MAXPTRSPERBUFFER];
size_t	SBufferBlockSize[MAXSBUFFERBLOCKS];
char *	SBufferBlockInFile[MAXSBUFFERBLOCKS];
int		SBufferBlockInLine[MAXSBUFFERBLOCKS];
char *	SBufferBlockFromFile[MAXSBUFFERBLOCKS];
int		SBufferBlockFromLine[MAXSBUFFERBLOCKS];
int		SBufferNumInstances[MAXSBUFFERBLOCKS];
int SBufferBlocksUsed = 0;
CRITICAL_SECTION SBufferHandKey;
/*�������������������������������������������������������������������
	Procedure	:	S Buffer Init...
	Input		:	void
	Output		:	void
�������������������������������������������������������������������*/
void XSBuffer_Init( void )
{
	int i, j;
	SBufferMemUsedSW =0;
	SBufferMemUsedHW =0;
	for( i = 0 ; i < MAXSBUFFERBLOCKS ; i++ )
	{
		SBufferBlockUsed[i] = FALSE;
		for ( j = 0; j < MAXPTRSPERBUFFER; j++ )
			SBufferBlockPnts[i][j] = NULL;
		SBufferBlockSize[i] = 0;
		SBufferNumInstances[i] = 0;
	}

	InitializeCriticalSection ( &SBufferHandKey );
}

/*�������������������������������������������������������������������
	Procedure	:	SBuffer_FindFree...
	Input		:	void
	Output		:	int Free memblock -1 if none
�������������������������������������������������������������������*/
int SBuffer_FindFree( void )
{
	int i;
	for( i = 0 ; i < MAXSBUFFERBLOCKS ; i++ )
	{
		if( !SBufferBlockUsed[i] )
		{
			SBufferBlocksUsed++;
			return i;
		}
	}
	return -1;
}
/*�������������������������������������������������������������������
	Procedure	:	SBuffer_FindSame...
	Input		:	void * Pnt
	Output		:	int Same memblock -1 if none
�������������������������������������������������������������������*/
void SBuffer_FindSame( LPDIRECTSOUNDBUFFER Pnt, int *block, int *dup )
{
	int i, j;
	for( i = 0 ; i < MAXSBUFFERBLOCKS ; i++ )
	{
		for ( j = 0; j < MAXPTRSPERBUFFER; j++ )
		{
			if( SBufferBlockUsed[i] && ( SBufferBlockPnts[i][j] == Pnt ) )
			{
				*block = i;
				*dup = j;
				return;
			}
		}
	}
	
	*block = -1;
	*dup = -1;
}

#ifdef DEBUG_ON

BOOL CheckSBufferValid( LPDIRECTSOUNDBUFFER lpDirectSoundBuffer )
{
	int i, j;
	for( i = 0 ; i < MAXSBUFFERBLOCKS ; i++ )
	{
		for ( j = 0; j < MAXPTRSPERBUFFER; j++ )
		{
			if( SBufferBlockUsed[i] && ( SBufferBlockPnts[i][j] == lpDirectSoundBuffer ) )
			{
				return TRUE;
			}
		}
	}

	return FALSE;
}

#else

BOOL CheckSBufferValid( LPDIRECTSOUNDBUFFER lpDirectSoundBuffer )
{
	return TRUE;
}

#endif

/*�������������������������������������������������������������������
		Make Sound Buffer
�������������������������������������������������������������������*/

BOOL XMakeSoundBuffer( LPDIRECTSOUND pds, LPCDSBUFFERDESC lpcDSBufferDesc , LPLPDIRECTSOUNDBUFFER lplpDirectSoundBuffer , IUnknown FAR * pUnkOuter, char *in_file, int in_line, char *from_file, int from_line )
{
	int i;
	DSBCAPS caps;

	EnterCriticalSection( &SBufferHandKey );

	i = SBuffer_FindFree();
	if( i == -1 )
	{
		Msg( "Ran out of free SBuffer Blocks");
		LeaveCriticalSection( &SBufferHandKey );
		return FALSE;
	}
 
	// create sound buffer here
	if ( IDirectSound_CreateSoundBuffer(pds, lpcDSBufferDesc, lplpDirectSoundBuffer, pUnkOuter) != DS_OK )
	{
		LeaveCriticalSection( &SBufferHandKey );
		return FALSE;
	}

	// get caps of buffer to determine whether in HW of SW
	memset( &caps, 0, sizeof( DSBCAPS ) );
	caps.dwSize = sizeof( DSBCAPS );
	IDirectSoundBuffer_GetCaps( *lplpDirectSoundBuffer, &caps) ;

	if ( caps.dwFlags & DSBCAPS_LOCHARDWARE )
	{
		SBufferBlockHW[i] = TRUE;
		SBufferMemUsedHW += caps.dwBufferBytes;
		if ( SBufferMemUsedHW > MaxSBufferMemUsedHW )
			MaxSBufferMemUsedHW = SBufferMemUsedHW;
	}
	else
	{
		SBufferBlockHW[i] = FALSE;
		SBufferMemUsedSW += caps.dwBufferBytes;
		if ( SBufferMemUsedSW > MaxSBufferMemUsedSW )
			MaxSBufferMemUsedSW = SBufferMemUsedSW;
	}

	// calculate size of sound buffer here

	SBufferBlockUsed[i] = TRUE;
	SBufferBlockPnts[i][0] = *lplpDirectSoundBuffer;
	SBufferBlockSize[i] = caps.dwBufferBytes;
	SBufferBlockInFile[i] = in_file;
	SBufferBlockInLine[i] = in_line;
	SBufferBlockFromFile[i] = from_file;
	SBufferBlockFromLine[i] = from_line;
	SBufferNumInstances[i] = 1;
	
	LeaveCriticalSection( &SBufferHandKey );

	return TRUE;
}

BOOL XSoundBufferDuplicate( LPDIRECTSOUND pds, LPDIRECTSOUNDBUFFER lpDsbOriginal,  LPLPDIRECTSOUNDBUFFER lplpDsbDuplicate, char *in_file, int in_line )
{
	int block, dup, i;
	
	EnterCriticalSection( &SBufferHandKey );
   
	SBuffer_FindSame( lpDsbOriginal, &block, &dup );
	if ( ( block == -1 ) && ( dup == -1 ) )
	{
		Msg(" Tried to duplicate un-allocated SBuffer block in %s line %d", in_file, in_line );
		LeaveCriticalSection( &SBufferHandKey );
		return FALSE;
	}

	dup = -1;
	for( i = 0; i < MAXPTRSPERBUFFER; i++ )
	{
		if ( !SBufferBlockPnts[ block ][ i ] )
		{
			dup = i;
			break;
		}
	} 

	if ( dup < 0 )
	{
		Msg("Tried to duplicate more than MAXPTRSPERBUFFER buffers in %s line %d", in_file, in_line );
		LeaveCriticalSection( &SBufferHandKey );
		return FALSE;
	}

	if ( IDirectSound_DuplicateSoundBuffer( pds, lpDsbOriginal, lplpDsbDuplicate ) == DS_OK )
	{
			SBufferBlockPnts[ block ][ dup ] = *lplpDsbDuplicate;
			SBufferNumInstances[ block ]++;
			LeaveCriticalSection( &SBufferHandKey );
			return TRUE;
	}else
		LeaveCriticalSection( &SBufferHandKey );
		return FALSE;
}

/*�������������������������������������������������������������������
	Procedure	:	Release sound buffer...
	Input		:	void * Pnt
	Output		:	void
�������������������������������������������������������������������*/
void XSoundBufferRelease( LPDIRECTSOUNDBUFFER *Pnt, char *in_file, int in_line )
{
	int block, dup, i;
	static char *last_file = NULL;
	static int last_line = -1;

	EnterCriticalSection( &SBufferHandKey );

	if ( !(*Pnt) )
	{
		if ( in_file != last_file || in_line != last_line )
			Msg( "Tried to free NULL Exec block in %s line %d", in_file, in_line );
		last_file = in_file;
		last_line = in_line;
		LeaveCriticalSection( &SBufferHandKey );
		return;
	}
	SBuffer_FindSame( *Pnt, &block, &dup );
	if ( ( block == -1 ) && ( dup == -1 ) )
	{
		if ( in_file != last_file || in_line != last_line )
	 		Msg( "Tried to free un-allocated SBuffer block in %s line %d", in_file, in_line );
		last_file = in_file;
		last_line = in_line;
		LeaveCriticalSection( &SBufferHandKey );
		return;
	}

	IDirectSoundBuffer_Release(*Pnt);
	*Pnt = NULL;

	if ( SBufferNumInstances[ block ] > 1 )
	{
		SBufferNumInstances[ block ]--;
		SBufferBlockPnts[ block ][ dup ] = NULL;
	}
	else
	{
		if ( SBufferBlockHW[ block ] )
			SBufferMemUsedHW -= SBufferBlockSize[ block ];
		else
			SBufferMemUsedSW -= SBufferBlockSize[ block ];

		SBufferBlockUsed[ block ] = FALSE;
		for ( i = 0; i < MAXPTRSPERBUFFER; i++ )
			SBufferBlockPnts[ block ][ i ] = NULL;
		SBufferBlockInFile[ block ] = NULL;
		SBufferBlockInLine[ block ] = 0;


		SBufferBlockSize[ block ] = 0;
		SBufferBlocksUsed--;
	}

	LeaveCriticalSection( &SBufferHandKey );
}

int UnMallocedSBufferBlocks( void )
{
	int i;

	if ( SBufferBlocksUsed )
	{
		for ( i = 0; i < MAXSBUFFERBLOCKS; i++ )
		{
			if ( SBufferBlockUsed[ i ] )
			{
				DebugPrintf( "SBufferBlock size %d allocated in %s line %d but not freed ( with %d duplicates ) from %s line %d\n",
					SBufferBlockSize[ i ], SBufferBlockInFile[ i ], SBufferBlockInLine[ i ], SBufferNumInstances[ i ],
					SBufferBlockFromFile[ i ], SBufferBlockFromLine[ i ] );
			}
		}
	}
	DebugPrintf( "SBufferMemUsed (HW) = %d   SBufferMemUsed (SW) = %d	SBufferBlocksUsed = %d\n",
		SBufferMemUsedHW, SBufferMemUsedSW, SBufferBlocksUsed );
	DebugPrintf("MaxSBufferMemUsed ( HW ) = %d	MaxSBufferMemUsed ( SW ) = %d\n", MaxSBufferMemUsedHW, MaxSBufferMemUsedSW);
	return SBufferBlocksUsed;
}


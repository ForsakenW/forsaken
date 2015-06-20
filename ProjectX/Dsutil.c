/*
 * The X Men, June 1996
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * $Revision: 44 $
 *
 * $Header: /PcProjectX/Dsutil.c 44    11/11/98 16:00 Philipy $
 *
 * $Log: /PcProjectX/Dsutil.c $
 * 
 * 44    11/11/98 16:00 Philipy
 * various fixes for warnings / errors when compiling under VC6
 * 
 * 43    14/07/98 11:28 Philipy
 * removed unec. debug msgs
 * 
 * 42    21/04/98 18:36 Philipy
 * reverted local sound directories back to root
 * 
 * 41    20/04/98 17:12 Philipy
 * added localisation stuff
 * 
 * 40    8/04/98 20:47 Philipy
 * title text messages now properly initialised
 * holo-glaire removed for sw version
 * compound buffer size can now be set in command line and opt file
 * prevented "level select disabled" from appearing at start of
 * multiplayer game
 * 
 * 39    30/03/98 17:30 Philipy
 * added cd specific path stuff
 * added new bike computers
 * prevented File_Exists being called every time a dynamic sfx is played
 * 
 * 38    29/03/98 19:59 Philipy
 * cd path now verified earlier
 * sfx no longer reloaded when changing biker / bike computer
 * mouse sensitivity rounding error fixed
 * 
 * 37    28/03/98 13:35 Philipy
 * added all biker speech
 * 
 * 36    27/03/98 18:04 Philipy
 * fixed bug where mapped sfx did not play.
 * 
 * 35    24/03/98 16:20 Philipy
 * added new sfx
 * 
 * 34    18/03/98 17:24 Collinsd
 * Fixed function header
 * 
 * 33    18/03/98 16:25 Philipy
 * removed some debug msgs
 * 
 * 32    18/03/98 16:14 Philipy
 * messed about with stopping memory from being paged out
 * Stopped due to lack of time & information
 * 
 * 31    9/03/98 16:54 Philipy
 * added 'requested' flag to SfxLookup. ( At present all sfx requested )
 * 
 * 30    9/03/98 10:03 Philipy
 * added extra debug info for compound sfx
 * 
 * 29    7/03/98 18:57 Philipy
 * fixed bug where sfx with variant marked as compound sfx when not all
 * variants would fit into hw memory
 * 
 * 28    28/02/98 16:18 Philipy
 * fixed memory leak
 * sfx loader does not now try to load sfx into hw if it knows that there
 * are insufficient resources
 * added buffer valid check b4 modifying looping sfx
 * 
 * 27    25/02/98 18:15 Philipy
 * fixed optimesed sfx stuff
 * 
 * 26    25/02/98 15:44 Philipy
 * more efficient use of hw sound mixing buffers
 * 
 * 25    12/02/98 11:27 Philipy
 * releasing buffer now sets pointer to NULL to try and trap error
 * 
 * 24    11/02/98 12:57 Philipy
 * sbufferhand now gives call stack to 2 levels
 * 
 * 23    9/02/98 12:21 Philipy
 * added sound buffer memory managment
 * only one piece of bike computer speech can now play at a time
 * 
 * 22    3/02/98 15:38 Philipy
 * fixed sfx bug
 * 
 * 21    20/01/98 17:11 Philipy
 * fixed data path stuff
 * 
 * 20    20/01/98 16:33 Philipy
 * added new sfx fn: PlaySpotFixedSfx
 * -data option now reverts to working dir for sfx if no local sfx dir
 * exists
 * 
 * 19    15/01/98 17:01 Philipy
 * added spot sfx stuff.
 * PlayPannedSfx and PlaySpotSfx now return unique uint32 - use StopSfx to
 * stop sound
 * 
 * 18    13/01/98 12:06 Philipy
 * added looping spot sfx support, and changed looping sfx to use static
 * list rather than dynamic linked list
 * 
 * 17    5/01/98 10:37 Philipy
 * speech sfx implemented - currently defaults to 1 biker & computer only,
 * none selectable
 * 
 * 16    30/12/97 14:26 Philipy
 * Changed dynamic sfx linked list to static list
 * 
 * 15    5/12/97 21:52 Philipy
 * various changes to looping sfx stuff
 * 
 * 14    1/12/97 16:15 Philipy
 * fixed crash bug when quitting
 * 
 * 13    1/12/97 12:15 Philipy
 * fixed trojax bug
 * 
 * 12    11/29/97 4:35p Phillipd
 * Xmem is now in effect...use it allways....
 * 
 * 11    26/11/97 11:48 Philipy
 * implemented dynamic loading of SFX, dynamic allocation of mixing
 * channels.
 * 3D sound currently disabled.
 * 
 * 10    11/08/97 10:12 Collinsd
 * Added override data directory option. ( SFX don't work yet! )
 * 
 * 9     4/08/97 11:58 Collinsd
 * A3D:Sound stuff added
 * 
 * 8     5/15/97 11:42a Phillipd
 * 3d Sound fx added but suspended due to crap DirectSound Docs..
 * 
 * 7     12-02-97 12:03p Collinsd
 * Added error checking to readfiles();  Also added triggers to enemies.
 * 
 * 6     10/24/96 3:01p Phillipd
 * 
 * 5     7/29/96 11:24a Phillipd
 * 
 * 4     7/25/96 10:05a Phillipd
 * 
 * 3     7/24/96 2:42p Phillipd
 * 
 * 2     7/24/96 2:11p Phillipd
 * 
 */

/*==========================================================================
 *
 *  Copyright (C) 1995 Microsoft Corporation. All Rights Reserved.
 *
 *  File:       dsutil.cpp
 *  Content:    Routines for dealing with sounds from resources
 *
 *
 ***************************************************************************/

#define WIN32_EXTRA_LEAN
#include <stdio.h>
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include "typedefs.h"
#include <dsound.h>
#include "file.h"
#include "dsutil.h"
#include "sfx.h"
#include "XMem.h"

static const char c_szWAV[] = "WAV";

void DebugPrintf( const char * format, ... );
int AddToSBufferList( IDirectSoundBuffer* buffer, IDirectSound3DBuffer* buffer3D, int SfxHolderIndex );
void CheckSBufferList( void );

extern LPDIRECTSOUND lpDS;
extern BOOL    A3DCapable;
extern SNDLOOKUP SndLookup[];

extern int use_data_path;
extern char data_path[];
extern char normdata_path[];

BOOL UseSfxHardware = FALSE;
extern BOOL CompoundSfxAllocated[MAX_SFX];
extern BOOL FreeHWBuffers;

DWORD CompoundSfxDataRate;

DWORD UserTotalCompoundSfxBufferSize = 0;
BOOL CustomCompoundBufferSize = FALSE;

#define SFX_FOLDER "sound"

char *GenericSfxPath = {
	"sound\\generic\\",
};
char *BikeCompSfxPath = {
	"sound\\BikeComp\\",
};
char *BikerSfxPath = {
	"sound\\Biker\\",
};
char *LevelSpecSfxPath = {
	"sound\\Mapped\\",
};

// establish compound sample format...temporarily hard coded for now...
DWORD CompoundSfxBitDepth = 16;
DWORD CompoundSfxFrequency = 22050;
DWORD CompoundSfxChannels = 1;
float CompoundSfxGap = 0.1F;	// secs

extern SNDOBJ *SndObjs[];
extern SFXNAME Sfx_Filenames[MAX_SFX];
extern TEMPSFXINFO TempSfxInfo[];

///////////////////////////////////////////////////////////////////////////////
//
// DSLoadSoundBuffer
//
///////////////////////////////////////////////////////////////////////////////
#ifdef DEBUG_ON
IDirectSoundBuffer *DSLoadSoundBuffer(IDirectSound *pDS, char *lpName , DWORD dwFlags, char *from_file, int from_line )
#else
IDirectSoundBuffer *DSLoadSoundBuffer(IDirectSound *pDS, char *lpName , DWORD dwFlags )
#endif
{
    IDirectSoundBuffer *pDSB = NULL;
    DSBUFFERDESC dsBD = {0};
    BYTE *pbWaveData;
	void * Buffer = NULL;

    if (Buffer = DSGetWave(lpName, &dsBD.lpwfxFormat, &pbWaveData, &dsBD.dwBufferBytes))
    {
        dsBD.dwSize = sizeof(dsBD);
        dsBD.dwFlags = dwFlags ;

        if ( MakeSoundBuffer( pDS, &dsBD, &pDSB, NULL ) )
        {
            if (!DSFillSoundBuffer(pDSB, pbWaveData, dsBD.dwBufferBytes))
            {
                SoundBufferRelease(&pDSB);
                pDSB = NULL;
            }
        }
        else
        {
            pDSB = NULL;
        }
    }

	if( Buffer != NULL )
		free( Buffer );
    return pDSB;
}
#ifdef DEBUG_ON
IDirectSoundBuffer *DSLoadCompoundSoundBuffer(IDirectSound *pDS, DWORD dwFlags, int *num_allocated_ptr, char *from_file, int from_line )
#else
IDirectSoundBuffer *DSLoadCompoundSoundBuffer(IDirectSound *pDS, DWORD dwFlags, int *num_allocated_ptr )
#endif
{
	IDirectSoundBuffer *pDSB = NULL;
    DSBUFFERDESC dsBD = {0};
    BYTE *pbWaveData;
	void * Buffer = NULL;
	WAVEFORMATEX format;

    if (Buffer = DSGetMultiWave(&format, &pbWaveData, &dsBD.dwBufferBytes, dwFlags, num_allocated_ptr))
    {
        dsBD.dwSize = sizeof(dsBD);
        dsBD.dwFlags = dwFlags;

		dsBD.lpwfxFormat = &format;

		if ( MakeSoundBuffer( pDS, &dsBD, &pDSB, NULL ) )
        {
            if (!DSFillSoundBuffer(pDSB, Buffer, dsBD.dwBufferBytes))
            {
                SoundBufferRelease(&pDSB);
                pDSB = NULL;
            }
        }
    }

	if( Buffer != NULL )
		free( Buffer );
    return pDSB;
}
///////////////////////////////////////////////////////////////////////////////
//
// DSLoad3DSoundBuffer - Loads a .WAV into a 3D sound buffer and returns the sound buffer
//
///////////////////////////////////////////////////////////////////////////////

IDirectSoundBuffer *DSLoad3DSoundBuffer(IDirectSound *pDS, char *lpName, IDirectSound3DBuffer ** lpDirectSound3DBuffer, DWORD dwflags )
{
#if 0
	IDirectSoundBuffer *pDSB = NULL;
    DSBUFFERDESC dsBD = {0};
    BYTE *pbWaveData;
	void * Buffer = NULL;

    dsBD.dwSize = sizeof(dsBD);
    dsBD.dwFlags = dwflags;

	if ( Buffer = DSGetWave(lpName, &dsBD.lpwfxFormat, &pbWaveData,
                        &dsBD.dwBufferBytes))
    {
        if ( MakeSoundBuffer( pDS, &dsBD, &pDSB, NULL ) )
        {
			if (DS_OK==IDirectSoundBuffer_QueryInterface(pDSB, &IID_IDirectSound3DBuffer, (void **)lpDirectSound3DBuffer))        
			{
				if (!DSFillSoundBuffer(pDSB, pbWaveData, dsBD.dwBufferBytes))
				{
					SoundBufferRelease(&pDSB);
					pDSB = NULL;
				}
			}
        }
        else
        {
            pDSB = NULL;
			lpDirectSound3DBuffer = NULL;
        }
	}
	
	if( Buffer != NULL )
		free( Buffer );
    return pDSB;
#endif
	return NULL;
}


///////////////////////////////////////////////////////////////////////////////
//
// DSReloadSoundBuffer
//
///////////////////////////////////////////////////////////////////////////////

BOOL DSReloadSoundBuffer(IDirectSoundBuffer *pDSB, char *lpName)
{
    BOOL result=FALSE;
    BYTE *pbWaveData;
    DWORD cbWaveSize;
	void * Buffer = NULL;

    if (Buffer = DSGetWave( lpName, NULL, &pbWaveData, &cbWaveSize))
    {
        if (SUCCEEDED(IDirectSoundBuffer_Restore(pDSB)) &&
            DSFillSoundBuffer(pDSB, pbWaveData, cbWaveSize))
        {
            result = TRUE;
        }
    }
	if( Buffer != NULL )
		free( Buffer );

    return result;
}


///////////////////////////////////////////////////////////////////////////////
// SndObj fns
///////////////////////////////////////////////////////////////////////////////

void InvalidateBuffers( SNDOBJ *pSO )
{
	int j;

	for( j = 0; j < MAX_DUP_BUFFERS; j++ )
	{
		if (pSO->Dup_3DBuffer[ j ])
		{
			IDirectSound3DBuffer_Release(pSO->Dup_3DBuffer[ j ]);
			pSO->Dup_3DBuffer[ j ] = NULL;
		}
		if (pSO->Dup_Buffer[ j ])
		{
			SoundBufferRelease(&pSO->Dup_Buffer[ j ]);
			pSO->Dup_Buffer[ j ] = NULL;
		}
	}
}

#ifdef DEBUG_ON
#define DSLoadSoundBuffer(A, B, C) DSLoadSoundBuffer(A, B, C, __FILE__, __LINE__)
#endif

SNDOBJ *SndObjCreate(IDirectSound *pDS, char *lpName, int sfx_flags , DWORD buf_flags, int sfx)
{
    SNDOBJ *pSO = NULL;
	void * Buffer = NULL;
	int i;
	HRESULT hres;
	DSBCAPS dsbcaps;

#if 0
	// needed for locking sound buffer
	LPVOID lpvAudioPtr1;
	DWORD dwAudioBytes1;
	LPVOID lpvAudioPtr2;  
	DWORD dwAudioBytes2;  
	DWORD dwFlags = DSBLOCK_ENTIREBUFFER;
#endif

    pSO = (SNDOBJ *)malloc(sizeof(SNDOBJ));

	if ( !FreeHWBuffers )
		buf_flags |= DSBCAPS_LOCSOFTWARE;

    if (pSO != NULL)
    {
		memset( pSO, 0, sizeof(SNDOBJ) );

		pSO->Dup_Buffer[0] = NULL;
		pSO->CompoundBuffer = FALSE;
		pSO->looping_sfx_index[0] = -1;

		// if sound is already loaded into HW...
		if ( ( IS_COMPOUND( sfx_flags ) ) && CompoundSfxAllocated[sfx] ) 
		{				  
			pSO->CompoundBuffer = TRUE;
			for (i = 0; i < MAX_DUP_BUFFERS; i++)
			   pSO->CompoundBufferLookup[i] = -1;
		}else
		{
			if ( A3DCapable )
			{
				pSO->Dup_Buffer[0] = DSLoad3DSoundBuffer(pDS, lpName, &pSO->Dup_3DBuffer[0], buf_flags );
			}else
			{
				// create buffer. Will create in hw if available, since only 16 channels have been used for compound sfx
				if( buf_flags & DSBCAPS_CTRL3D )
				{
					pSO->Dup_Buffer[0] = DSLoad3DSoundBuffer(pDS, lpName, &pSO->Dup_3DBuffer[0], buf_flags );
				}else{
					pSO->Dup_Buffer[0] = DSLoadSoundBuffer(pDS, lpName, buf_flags );
				}
			}

			if( !pSO->Dup_Buffer[ 0 ] )
			{
				Msg("Unable to create sound buffer for %s\n", lpName );
				InvalidateBuffers( pSO );
				return pSO;
			}


			// get caps of buffer
			memset( &dsbcaps, 0, sizeof( DSBCAPS ) );
			dsbcaps.dwSize = sizeof( DSBCAPS );
			IDirectSoundBuffer_GetCaps( pSO->Dup_Buffer[ 0 ], &dsbcaps );

			if ( dsbcaps.dwFlags & DSBCAPS_LOCHARDWARE )
			{
				//DebugPrintf("creating %s in hardware\n", lpName );
			}else
			{
				//DebugPrintf("creating %s in software\n", lpName );
#if 0
				// lock buffer
				IDirectSoundBuffer_Lock( pSO->Dup_Buffer[ 0 ], 0, 0, &lpvAudioPtr1, &dwAudioBytes1,
				&lpvAudioPtr2, &dwAudioBytes2, dwFlags );

				// make non-volatile
				MakeRegionPresent( ( BYTE * )lpvAudioPtr1, (UINT)dwAudioBytes1 );

				// unlock buffer
				IDirectSoundBuffer_Unlock( pSO->Dup_Buffer[ 0 ], lpvAudioPtr1, 0, lpvAudioPtr2, 0 );
#endif
			}


			// if buffer in hw, should check free channels here, but Ensoniq driver always reports back 256
			// so we will just have to try duplicating until failure
			for (i = 1; i < MAX_DUP_BUFFERS; i++)
			{
				pSO->looping_sfx_index[i] = -1;
				// duplicate 2D buffer...
				if ( !SoundBufferDuplicate( pDS, pSO->Dup_Buffer[0], &pSO->Dup_Buffer[i]) )
				{
					DebugPrintf("unable to duplicate sound buffer\n");

					// invalidate buffer & all duplicates
					InvalidateBuffers( pSO );

					// was original buffer hw? if so, try to recreate in sw
					if ( dsbcaps.dwFlags & DSBCAPS_LOCHARDWARE )
					{
						DebugPrintf("trying to recreate in sw\n");
						FreeHWBuffers = FALSE;
						// recreate all buffers up to & including this one in software
						if( buf_flags & DSBCAPS_CTRL3D )
						{
							pSO->Dup_Buffer[ 0 ] = DSLoad3DSoundBuffer(pDS, lpName, &pSO->Dup_3DBuffer[ 0 ], buf_flags | DSBCAPS_LOCSOFTWARE );
						}else{
							pSO->Dup_Buffer[ 0 ] = DSLoadSoundBuffer(pDS, lpName, buf_flags | DSBCAPS_LOCSOFTWARE );
						}

						if( !pSO->Dup_Buffer[ 0 ] )
						{
							Msg("Unable to create sound buffer for %s\n", lpName );
							InvalidateBuffers( pSO );
							return pSO;
						}

						i = 0;
						continue;

					}else
					{
						// couldn't duplicate buffer in sw - just break out with buffer info still marked as invalid
						Msg("unable to duplicate buffers in sw\n");
						break;
					}
				}

				// query for 3D interface if we are using 3D...
				if ( pSO->Dup_3DBuffer[0] )
				{
					hres = IDirectSoundBuffer_QueryInterface(pSO->Dup_Buffer[i], &IID_IDirectSound3DBuffer, &pSO->Dup_3DBuffer[i]);        
				}

			}
		}
    }

    return pSO;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void SndObjDestroy(SNDOBJ *pSO)
{
    int i;

	if (pSO)
    {
		for (i = 0; i < MAX_DUP_BUFFERS; i++)
		{
			if (pSO->Dup_3DBuffer[i])
			{
	            IDirectSound3DBuffer_Release(pSO->Dup_3DBuffer[i]);
		        pSO->Dup_3DBuffer[i] = NULL;
			}
			if (pSO->Dup_Buffer[i])
			{
	            SoundBufferRelease(&pSO->Dup_Buffer[i]);
		        pSO->Dup_Buffer[i] = NULL;
			}
		}
        free(pSO);
    }
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

BOOL DSFillSoundBuffer(IDirectSoundBuffer *pDSB, BYTE *pbWaveData, DWORD cbWaveSize)
{
    if (pDSB && pbWaveData && cbWaveSize)
    {
        LPVOID pMem1, pMem2;
        DWORD dwSize1, dwSize2;

        if (SUCCEEDED(IDirectSoundBuffer_Lock(pDSB, 0, cbWaveSize,
            &pMem1, &dwSize1, &pMem2, &dwSize2, 0)))
        {
            CopyMemory(pMem1, pbWaveData, dwSize1);

            if ( 0 != dwSize2 )
                CopyMemory(pMem2, pbWaveData+dwSize1, dwSize2);

            IDirectSoundBuffer_Unlock(pDSB, pMem1, dwSize1, pMem2, dwSize2);
            return TRUE;
        }
    }

    return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
//
// DSGetWave
//
///////////////////////////////////////////////////////////////////////////////

void * DSGetWave( char *lpName , WAVEFORMATEX **ppWaveHeader, BYTE **ppbWaveData, DWORD *pcbWaveSize)
{
	long			File_Size;
	long			Read_Size;
	void		*	Buffer;
	void *End;
	
	File_Size = Get_File_Size( lpName );	// how big is the file...
	if( !File_Size ) return NULL;
	Buffer = malloc( File_Size );							// alloc enough space to load it...
	if( Buffer == NULL ) return( NULL );					// if couldnt then return
	Read_Size = Read_File( lpName, Buffer, File_Size ); // Read it in making a note of the Size returned
	if( Read_Size != File_Size ) return( NULL );			// if size read doesnt qual file size return

	DSParseWave( Buffer , ppWaveHeader, ppbWaveData, pcbWaveSize, &End);

	return Buffer;
}

void GetSfxPath( int sfxnum, char *path, char *data_path_to_use )
{
	char tempdir[256];

	strcpy( tempdir, data_path );
	strcat( tempdir, SFX_FOLDER );

	if ( sfxnum > SFX_LEVELSPEC_Start )
		sfxnum = SFX_LEVELSPEC_Start;
	
#ifndef CD_REQUIRED
	if ( use_data_path && File_Exists( tempdir ) )
		strcpy( path, data_path );
	else
		strcpy( path, normdata_path );
#else

	strcpy( path, data_path_to_use );

#endif


	if ( Sfx_Filenames[ sfxnum ].Flags & SFX_BikeComp )
	{
		strcat( path, BikeCompSfxPath );
		return;
	}

	if ( Sfx_Filenames[ sfxnum ].Flags & SFX_Biker )
	{
		strcat( path, BikerSfxPath );
		return;
	}

	if ( Sfx_Filenames[ sfxnum ].Flags & SFX_LevelSpec )
	{
		strcat( path, LevelSpecSfxPath );
		return;
	}

	strcat( path, GenericSfxPath );
}																	
void * DSGetMultiWave( WAVEFORMATEX *pWaveHeaderStore, BYTE **ppbWaveData, DWORD *pcbWaveSize, DWORD dwFlags, int *num_allocated_ptr )
{
	long File_Size;
	long Read_Size;
	void *Buffer;
	void *End;
	int i, min, index, variant;
	char *TempCompositeBuffer, *CompositeBuffer, *IntermediateBuffer;
	char TempFileName[256];
	WAVEFORMATEX TempWaveHeader;
	int temp_num_allocated;

	LPWAVEFORMATEX pWaveHeader;
	
	DWORD BytesPerSec, dwGapSize, total_size, dwBufferOffset;
	float gap_size; 
	
	DWORD BufferSizeSoFar, MaxBufferSize;
	BOOL SfxChecked[ MAX_SFX ];
	DSCAPS DSCaps;
	BOOL error;
	
	memset (&DSCaps, 0, sizeof (DSCAPS));
	DSCaps.dwSize = sizeof(DSCAPS);
	IDirectSound_GetCaps( lpDS, &DSCaps );
	
	memset (SfxChecked, 0, sizeof( BOOL ) * MAX_SFX);

	BytesPerSec = (CompoundSfxBitDepth * CompoundSfxChannels / 8) * CompoundSfxFrequency;
	gap_size = (float)BytesPerSec * CompoundSfxGap;
	dwGapSize = (DWORD)gap_size;

	total_size = 0;

	// for all compound sfx...
	for ( i = 0; Sfx_Filenames[ i ].Name; i++ )
	{
		if ( ( IS_COMPOUND( Sfx_Filenames[ i ].Flags ) ) && !CompoundSfxAllocated[ i ] && SndLookup[ i ].Requested )
		{
			// if sfx does not exist, ignore
			if ( !SndLookup[ i ].Num_Variants )
				continue;

			for ( variant = 0; variant < SndLookup[ i ].Num_Variants; variant++ )
			{
				GetFullSfxPath( TempFileName, i, variant, SndLookup[ i ].Num_Variants );

				if ( File_Exists( TempFileName ) )
				{
					File_Size = Get_File_Size( TempFileName );	// how big is the file...
					if( !File_Size ) return NULL;

					Buffer = malloc( File_Size );							// alloc enough space to load it...
					if( Buffer == NULL ) return( NULL );					// if couldnt then return

					Read_Size = Read_File( TempFileName, Buffer, File_Size ); // Read it in making a note of the Size returned
					if( Read_Size != File_Size ) return( NULL );			// if size read doesnt qual file size return

					DSParseWave( Buffer, &pWaveHeader, ppbWaveData, pcbWaveSize, &End);

					// get size of file...
					total_size += *pcbWaveSize;
						
					// add space for gap afterwards...
					total_size += dwGapSize;

					free ( Buffer );
				}
			}
		}
	}

	if ( dwFlags & DSBCAPS_LOCHARDWARE )
		MaxBufferSize = DSCaps.dwMaxContigFreeHwMemBytes;
	else
	{
		return NULL;
	}

	if ( total_size > MaxBufferSize )
		total_size = MaxBufferSize;

	if ( CustomCompoundBufferSize && ( total_size > UserTotalCompoundSfxBufferSize ) )
		total_size = UserTotalCompoundSfxBufferSize;

	CompositeBuffer = (char *)malloc( total_size );
	TempCompositeBuffer = CompositeBuffer;
	dwBufferOffset = 0;
	BufferSizeSoFar = 0;
	do
	{
		min = -1;
		index = -1;

		// find sfx with next highest priority...
		for ( i = 0; Sfx_Filenames[ i ].Name; i++ )
		{
			if ( IS_COMPOUND( Sfx_Filenames[ i ].Flags ) )
			{
				if ( ( min == -1 ) && !SfxChecked[ i ] && !CompoundSfxAllocated[ i ] && SndLookup[ i ].Num_Variants && SndLookup[ i ].Requested )
				{
					min = Sfx_Filenames[ i ].Priority;
					index = i;
				}else
				{
					if ( ( Sfx_Filenames[ i ].Priority < min ) && !SfxChecked[ i ] && !CompoundSfxAllocated[ i ] && SndLookup[ i ].Num_Variants && SndLookup[ i ].Requested )
					{
						min = Sfx_Filenames[ i ].Priority;
						index = i;
					}
				}
			}
		}

		if ( index != -1 )	// sfx has been found...
		{
			SfxChecked[ index ] = TRUE;

			error = FALSE;
			IntermediateBuffer = TempCompositeBuffer;
			temp_num_allocated = *num_allocated_ptr;

			for ( variant = 0; variant < SndLookup[ index ].Num_Variants; variant++ )
			{

				GetFullSfxPath( TempFileName, index, variant, SndLookup[ index ].Num_Variants );
			
				if ( File_Exists( TempFileName ) )
				{
					File_Size = Get_File_Size( TempFileName );	// how big is the file...
					if( !File_Size )
					{
						error = TRUE;
						DebugPrintf("DSGetMultiWave() File size returned was zero\n");
						break;
					}

					Buffer = malloc( File_Size );		 // alloc enough space to load it...

					if( Buffer == NULL )
					{
						error = TRUE;
						DebugPrintf("DSGetMultiWave() unable to malloc memory for temp buffer\n");
						break;
					}

					Read_Size = Read_File( TempFileName, Buffer, File_Size ); // Read it in making a note of the Size returned

					if( Read_Size != File_Size )
					{
						error = TRUE;
						DebugPrintf("DSGetMultiWave() read file size not equal to actual file size\n");
						break;
					}

					DSParseWave( Buffer, &pWaveHeader, ppbWaveData, pcbWaveSize, &End);

					if ( ( (pWaveHeader)->nChannels != CompoundSfxChannels ) ||
						( (pWaveHeader)->nSamplesPerSec != CompoundSfxFrequency ) ||
						( (pWaveHeader)->wBitsPerSample != CompoundSfxBitDepth ) )
					{
						DebugPrintf("Dsutil.c: DSGetMultiWave() - sfx %d variant %d not of correct type for composite buffer, ignoring\n", index, variant);
						*pWaveHeader = TempWaveHeader;
						error = TRUE;
						break;
					}else
					{
						TempWaveHeader = *pWaveHeader;

						// if pcbWaveSize < available mem left, and format is OK...
						if ( ( (*pcbWaveSize + dwGapSize) < ( total_size - BufferSizeSoFar ) ) || !total_size )
						{
							//DebugPrintf("sfx %d marked allocated\n", index);
						   
							BufferSizeSoFar += *pcbWaveSize + dwGapSize;

							TempSfxInfo[ *num_allocated_ptr ].SfxNum = index;
							TempSfxInfo[ *num_allocated_ptr ].StartPos = dwBufferOffset;
							TempSfxInfo[ *num_allocated_ptr ].Length = (*pcbWaveSize * 1000) / BytesPerSec;
							TempSfxInfo[ *num_allocated_ptr ].Bytes = *pcbWaveSize;
							TempSfxInfo[ *num_allocated_ptr ].Variant = variant;

							(*num_allocated_ptr)++;

							// check to see if max sfx allocated...
							if (*num_allocated_ptr == MAX_COMPOUND_SFX)
							{
								DebugPrintf("tried to allocate more than MAX_COMPOUND_SFX sfx\n");
								error = TRUE;
								break;
							}

							dwBufferOffset = dwBufferOffset + *pcbWaveSize + dwGapSize;

							// copy wave data to composite buffer...
							memcpy( TempCompositeBuffer, *ppbWaveData, *pcbWaveSize );
							TempCompositeBuffer += *pcbWaveSize;
							
							// add gap
							memset( TempCompositeBuffer, 0, dwGapSize );
							TempCompositeBuffer += dwGapSize;
						}else
						{
							DebugPrintf("Not enough HW mem for SFX %d\n", index);
							error = TRUE;
							break;
						}
					}

					*pWaveHeaderStore = *pWaveHeader;

					free ( Buffer );
				}
			}

			if ( error )
			{
				if ( Buffer )
					free ( Buffer );
				
				// move current buffer ptr back to position b4 this sfx
				TempCompositeBuffer = IntermediateBuffer;

				// invalidate compound sfx info for this sfx
				*num_allocated_ptr = temp_num_allocated;
			}else
			{
				CompoundSfxAllocated[ index ] = TRUE;
			}
		}
	}while ( index != -1 );

	*pcbWaveSize = BufferSizeSoFar;

	return (void *)CompositeBuffer;
}

///////////////////////////////////////////////////////////////////////////////
//
// DSParseWave
//
///////////////////////////////////////////////////////////////////////////////



BOOL DSParseWave(void *Buffer, WAVEFORMATEX **ppWaveHeader, BYTE **ppbWaveData,DWORD *pcbWaveSize, void **End)
{
    DWORD *pdw;
    DWORD *pdwEnd;
    DWORD dwRiff;
    DWORD dwType;
    DWORD dwLength;

    if (ppWaveHeader)
        *ppWaveHeader = NULL;

    if (ppbWaveData)
        *ppbWaveData = NULL;

    if (pcbWaveSize)
        *pcbWaveSize = 0;

    pdw = (DWORD *)Buffer;
    dwRiff = *pdw++;
    dwLength = *pdw++;
    dwType = *pdw++;

    if (dwRiff != mmioFOURCC('R', 'I', 'F', 'F'))
        goto exit;      // not even RIFF

    if (dwType != mmioFOURCC('W', 'A', 'V', 'E'))
        goto exit;      // not a WAV

    pdwEnd = (DWORD *)((BYTE *)pdw + dwLength-4);
	*End = (void *)pdwEnd;

    while (pdw < pdwEnd)
    {
        dwType = *pdw++;
        dwLength = *pdw++;

        switch (dwType)
        {
        case mmioFOURCC('f', 'm', 't', ' '):
            if (ppWaveHeader && !*ppWaveHeader)
            {
                if (dwLength < sizeof(WAVEFORMAT))
                    goto exit;      // not a WAV

                *ppWaveHeader = (WAVEFORMATEX *)pdw;

                if ((!ppbWaveData || *ppbWaveData) &&
                    (!pcbWaveSize || *pcbWaveSize))
                {
                    return TRUE;
                }
            }
            break;

        case mmioFOURCC('d', 'a', 't', 'a'):
            if ((ppbWaveData && !*ppbWaveData) ||
                (pcbWaveSize && !*pcbWaveSize))
            {
                if (ppbWaveData)
                    *ppbWaveData = (LPBYTE)pdw;

                if (pcbWaveSize)
                    *pcbWaveSize = dwLength;

                if (!ppWaveHeader || *ppWaveHeader)
                    return TRUE;
            }
            break;
        }

        pdw = (DWORD *)((BYTE *)pdw + ((dwLength+1)&~1));
    }

exit:
    return FALSE;
}

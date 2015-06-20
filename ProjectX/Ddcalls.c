/*
 * The X Men, June 1996
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * $Revision: 36 $
 *
 * $Header: /PcProjectX/Ddcalls.c 36    21/08/98 15:28 Philipy $
 *
 * $Log: /PcProjectX/Ddcalls.c $
 * 
 * 36    21/08/98 15:28 Philipy
 * modified free video memory check to account for frame buffer size
 * 
 * 35    18/08/98 18:14 Philipy
 * all pings in server game are now from server perspective
 * windowed mode re-enabled ( still needs some work )
 * 
 * 34    12/08/98 15:37 Philipy
 * removed mode limitaions
 * 
 * 33    6/19/98 10:57a Phillipd
 * 
 * 32    6/04/98 3:49p Phillipd
 * Shield and Hull Get saved and restored during minimizeation
 * 
 * 31    6/03/98 4:42p Phillipd
 * 
 * 30    4/27/98 4:01p Phillipd
 * 
 * 29    14/04/98 21:52 Oliverc
 * Fixed glitches in new device selection code
 * 
 * 28    4/14/98 7:15p Phillipd
 * 
 * 27    4/04/98 14:22 Philipy
 * mode scaling stuff is now calculated rather than based on fixed values
 * added -NoBlitTextScaling option to ReadIni and command line options
 * 
 * 26    3/29/98 6:45p Phillipd
 * 
 * 25    3/29/98 6:41p Phillipd
 * 
 * 24    29/03/98 17:49 Collinsd
 * 
 * 23    3/29/98 1:21p Phillipd
 * 
 * 22    26/03/98 9:22 Collinsd
 * SW Restricted to 640x480 or less
 * 
 * 21    17/03/98 20:29 Collinsd
 * Fixed pinemines targeting own team mates mines.
 * 
 * 20    3/17/98 4:14p Phillipd
 * 8 bit screenmodes enabled.....
 * 
 * 19    9/01/98 11:13 Philipy
 * CD nows plays last track
 * CD now replays current track from seperate  ( low priority ) thread -
 * but still causes pause
 * loading bar now displayed when loading
 * 
 * 18    1/08/98 4:18p Phillipd
 * 
 * 17    12/23/97 9:59a Phillipd
 * Unwanted Tetxure Formats commented out...
 * Unwanted ScreenModes out...
 * Pickup Generation Sfx added
 * 
 * 16    12/19/97 4:17p Phillipd
 * ScreenMemory switch added for 3dfx.....
 * 
 * 15    12/16/97 3:24p Phillipd
 * 
 * 14    7/11/97 14:25 Philipy
 * fixed bug when changing mode from title room: InitTitle was not being
 * called
 * 
 * 13    16/09/97 11:17 Oliverc
 * Prevented dodgy video modes being available
 * 
 * 12    31/07/97 15:57 Oliverc
 * Added special SELF_PLAY features, including disabling critical unused
 * code and setting default values appropriate to demo attract mode
 * 
 * 11    6/21/97 11:37a Phillipd
 * Left comments in for how to get a dd2 interface which can allow for
 * frequency stting of monitors when a display mode is set
 * 
 * 10    6/16/97 2:57p Phillipd
 * 
 * 9     10/29/96 2:52p Phillipd
 * 
 * 8     10/23/96 4:23p Phillipd
 * Lots of crap taken out of D3dapp and its associated functions and
 * files....
 * 
 * 7     14/10/96 15:02 Oliverc
 * Added command line options to select default DirectDraw device and
 * fullscreen video mode
 * 
 * 6     10/09/96 2:33p Phillipd
 * 
 * 5     9/15/96 11:49a Phillipd
 * 
 * 4     8/20/96 9:08a Phillipd
 * 
 * 3     7/11/96 2:55p Phillipd
 * added D3DAppFreeVideoMemory...returns total free..
 * 
 * 2     6/25/96 11:37a Phillipd
 * First SS update
 * 
 */

/*
 *  Copyright (C) 1995, 1996 Microsoft Corporation. All Rights Reserved.
 *
 *  File: ddcalls.c
 *
 *  Manages DirectDraw objects needed for rendering.  Part of D3DApp.
 *
 *  D3DApp is a collection of helper functions for Direct3D applications.
 *  D3DApp consists of the following files:
 *      d3dapp.h    Main D3DApp header to be included by application
 *      d3dappi.h   Internal header
 *      d3dapp.c    D3DApp functions seen by application.
 *      ddcalls.c   All calls to DirectDraw objects except textures
 *      d3dcalls.c  All calls to Direct3D objects except textures
 *      texture.c   Texture loading and managing texture list
 *      misc.c      Miscellaneous calls
 */

#include "d3dappi.h"
#include "ddutil.h"

extern int default_width;
extern int default_height;
extern int default_bpp;

extern	int		ScreenMemory;
extern	BOOL	Is3Dfx;
extern BOOL PreventFlips;

BOOL CanDoStrechBlt = TRUE;
BOOL	TripleBuffer = FALSE;
BOOL CanRenderWindowed;

#ifdef SOFTWARE_ENABLE
extern	BOOL	SoftwareVersion;
#endif
BOOL  IsEqualGuid(GUID *lpguid1, GUID *lpguid2);

extern	LPGUID	DeviceGuidPnt;
extern	GUID	DeviceGuid;

int ddcount3d = 0;	// number of 3D DD devices
int ddchosen3d = 0;	// currently selected one

/***************************************************************************/
/*                         Direct Draw Creation                            */
/***************************************************************************/
/*
 * D3DAppIDDEnumCallback
 * Callback function used during enumeration of DirectDraw drivers.
 * During enumeration, if a 3D capable hardware device is found, it is 
 * created and *(LPDIRECTDRAW*)lpContext is set to it.  Otherwise, does
 * nothing.
 */
BOOL FAR PASCAL D3DAppIDDEnumCallback(GUID FAR* lpGUID, LPSTR lpDriverDesc,
                                      LPSTR lpDriverName, LPVOID lpContext)
{
    LPDIRECTDRAW lpDD;
    DDCAPS DriverCaps, HELCaps;
#ifdef FINAL_RELEASE
	BOOL	ThisOne = FALSE;
#endif
    /*
     * A NULL GUID* indicates the DirectDraw HEL which we are not interested
     * in at the moment.
     */
//    if (lpGUID)
	{
        /*
         * Create the DirectDraw device using this driver.  If it fails,
         * just move on to the next driver.
         */
        if (FAILED(DirectDrawCreate(lpGUID, &lpDD, NULL))) {
            return DDENUMRET_OK;
        }
        /*
         * Get the capabilities of this DirectDraw driver.  If it fails,
         * just move on to the next driver.
         */
        memset(&DriverCaps, 0, sizeof(DDCAPS));
        DriverCaps.dwSize = sizeof(DDCAPS);
        memset(&HELCaps, 0, sizeof(DDCAPS));
        HELCaps.dwSize = sizeof(DDCAPS);
        if (FAILED(lpDD->lpVtbl->GetCaps(lpDD, &DriverCaps, &HELCaps))) {
            lpDD->lpVtbl->Release(lpDD);
            return DDENUMRET_OK;
        }
#ifdef FINAL_RELEASE
        if (DriverCaps.dwCaps & DDCAPS_3D )
		{
			if( !lpGUID && !DeviceGuidPnt)
			{
				ThisOne = TRUE;
			}
			if( DeviceGuidPnt && lpGUID )
			{
				if( IsEqualGuid( lpGUID, &DeviceGuid) )
				{
					ThisOne = TRUE;
				}
			}
			if( ThisOne )
			{
				/*
				 * We have found a 3d hardware device.  Return the DD object
				 * and stop enumeration.
				 */
				d3dappi.bIsPrimary = FALSE;
				*(LPDIRECTDRAW*)lpContext = lpDD;
				return DDENUMRET_CANCEL;
			}
		}
#else
        if (DriverCaps.dwCaps & DDCAPS_3D )
		{
			if( ddcount3d++ == ddchosen3d )
			{
				/*
				 * We have found a 3d hardware device.  Return the DD object
				 * and stop enumeration.
				 */
				d3dappi.bIsPrimary = FALSE;
				*(LPDIRECTDRAW*)lpContext = lpDD;
				return DDENUMRET_CANCEL;
			}
        }
#endif
        lpDD->lpVtbl->Release(lpDD);
    }
    return DDENUMRET_OK;
}

/*
 * D3DAppICreateDD
 * Creates the DirectDraw device and saves the current palette. If a 3D 
 * capable DD driver is available, use it as the DD device, otherwise, use
 * the HEL.  It is assumed that a 3D capable DD hardware driver is not the
 * primary device and hence cannot operate in a window (ie it's a fullscreen
 * only device displaying on a second monitor).  Valid flags:
 *     D3DAPP_ONLYDDEMULATION    Always use the DirectDraw HEL
 */
BOOL
D3DAppICreateDD(DWORD flags)
{
    HDC hdc;
    int i;
    LPDIRECTDRAW lpDD = NULL;
	DDCAPS DriverCaps, HELCaps, ddcaps;
	LPDIRECTDRAW4 pdd4 = NULL;

    /*
     * If we aren't forced to use the DirectDraw HEL, search for a 3D capable
     * DirectDraw hardware driver and create it.
     */
    if (!(flags & D3DAPP_ONLYDDEMULATION))
	{
		ddcount3d = 0;
        LastError = DirectDrawEnumerate(D3DAppIDDEnumCallback, &lpDD);
        if (LastError != DD_OK) 
		{
            D3DAppISetErrorString("DirectDrawEnumerate failed.\n%s",
                                  D3DAppErrorToString(LastError));
            return FALSE;
        }
    }
    if (!lpDD)
	{
        /*
         * If we haven't created a hardware DD device by now, resort to HEL
         */
        d3dappi.bIsPrimary = TRUE;
        LastError = DirectDrawCreate(NULL, &d3dappi.lpDD, NULL);
        if (LastError != DD_OK) 
		{
            D3DAppISetErrorString("DirectDrawCreate failed.\n%s",
                                  D3DAppErrorToString(LastError));
            return FALSE;
        }
    } else 
	{
        d3dappi.lpDD = lpDD;

	    memset (&DriverCaps, 0, sizeof(DDCAPS));
		DriverCaps.dwSize = sizeof(DDCAPS);
	    memset (&HELCaps, 0, sizeof(DDCAPS));
		HELCaps.dwSize = sizeof(DDCAPS);

		d3dappi.lpDD->lpVtbl->GetCaps(d3dappi.lpDD, &DriverCaps, &HELCaps);

		if (!((DriverCaps.dwCaps & DDCAPS_BLTSTRETCH) || (HELCaps.dwCaps & DDCAPS_BLTSTRETCH)))
		{
			CanDoStrechBlt = FALSE;
		}
    }

	// find out if current driver can do windowed mode ( need dx6 interface )

	// query for IDirectDraw4 ptr
	IDirectDraw_QueryInterface( d3dappi.lpDD, &IID_IDirectDraw4, (LPVOID *)&pdd4 );

	if ( pdd4 )
	{
		// get caps
		memset( &ddcaps, 0, sizeof( DDCAPS ) );
		ddcaps.dwSize = sizeof( DDCAPS );
		IDirectDraw4_GetCaps( pdd4, &ddcaps, NULL );

		// can do windowed??
		if( ddcaps.dwCaps2 & DDCAPS2_CANRENDERWINDOWED )
			CanRenderWindowed = TRUE;
		else
			CanRenderWindowed = FALSE;

		// release dd4 interface
		IDirectDraw4_Release( pdd4 );
	}

    /*
     * Save the original palette for when we are paused.  Just in case we
     * start in a fullscreen mode, put them in ppe.
     */
    hdc = GetDC(NULL);
    GetSystemPaletteEntries(hdc, 0, (1 << 8),
                            (LPPALETTEENTRY)(&Originalppe[0]));
    for (i = 0; i < 256; i++)
        ppe[i] = Originalppe[i];
    ReleaseDC(NULL, hdc);
    return TRUE;
}

/***************************************************************************/
/*                   Enumerating the display modes                         */
/***************************************************************************/
/*
 * EnumDisplayModesCallback
 * Callback to save the display mode information.
 */
static HRESULT
CALLBACK EnumDisplayModesCallback(LPDDSURFACEDESC pddsd, LPVOID lpContext)
{
	int ScreenMemoryUsed = 0;

    if( (pddsd->ddpfPixelFormat.dwFlags & DDPF_PALETTEINDEXED8) ||
		(pddsd->ddpfPixelFormat.dwFlags & DDPF_PALETTEINDEXED4) ||
		(pddsd->ddpfPixelFormat.dwRGBBitCount <= 8) )
        return DDENUMRET_OK;

    if(	(pddsd->ddpfPixelFormat.dwFlags & DDPF_PALETTEINDEXED4) ||
		(pddsd->ddpfPixelFormat.dwRGBBitCount < 8) )
        return DDENUMRET_OK;

	ScreenMemoryUsed = pddsd->dwWidth * pddsd->dwHeight * ( pddsd->ddpfPixelFormat.dwRGBBitCount / 8 );
	if( TripleBuffer )
	{
		ScreenMemoryUsed *= 4; // 3 screens + zbuffer
	}else{
		ScreenMemoryUsed *= 3; // 2 screens + zbuffer
	}
#ifdef SOFTWARE_ENABLE
	if ( ( SoftwareVersion ) && ( pddsd->dwWidth > 640 && pddsd->dwHeight > 480 ) )
        return DDENUMRET_OK;
#endif

#ifdef SOFTWARE_ENABLE
	if( SoftwareVersion )
	{
		if ( pddsd->ddpfPixelFormat.dwRGBBitCount > 16 )
			return DDENUMRET_OK; // hack to prevent colourkeying messing up
	}
#endif

	if( ScreenMemory )
	{
		if( ScreenMemoryUsed > (ScreenMemory * 1024 ) )
		{
//	        return DDENUMRET_OK; // There isnt enough screen memory for that display mode...
		}
	}
	if( pddsd->dwWidth < 1024 || pddsd->dwHeight < 768 || pddsd->ddpfPixelFormat.dwRGBBitCount < 32 )
		return DDENUMRET_OK;


	/*
		* Save this mode at the end of the mode array and increment mode count
		*/
	d3dappi.Mode[d3dappi.NumModes].w = pddsd->dwWidth;
	d3dappi.Mode[d3dappi.NumModes].h = pddsd->dwHeight;
	d3dappi.Mode[d3dappi.NumModes].bpp = pddsd->ddpfPixelFormat.dwRGBBitCount;
	d3dappi.Mode[d3dappi.NumModes].bThisDriverCanDo = TRUE;
	d3dappi.NumModes++;
	if (d3dappi.NumModes == D3DAPP_MAXMODES)
		return DDENUMRET_CANCEL;
	else
		return DDENUMRET_OK;
}

/*
 * CompareModes
 * Compare two display modes during sorting.  Modes are sorted by depth and
 * then resolution.
 */
static int
_cdecl CompareModes(const void* element1, const void* element2) {
    D3DAppMode *lpMode1, *lpMode2;

    lpMode1 = (D3DAppMode*)element1;
    lpMode2 = (D3DAppMode*)element2;

    if (lpMode1->bpp > lpMode2->bpp)
        return -1;
    else if (lpMode2->bpp > lpMode1->bpp)
        return 1;
    else if (lpMode1->w > lpMode2->w)
        return -1;
    else if (lpMode2->w > lpMode1->w)
        return 1;
    else if (lpMode1->h > lpMode2->h)
        return -1;
    else if (lpMode2->h > lpMode1->h)
        return 1;
    else
        return 0;
}

/*
 * EnumerateDisplayModes
 * Generates the list of available display modes.
 */
BOOL
D3DAppIEnumDisplayModes(void)
{
    int i;
	int mode;
#if 1
	int wmin, hmin, bppmin, default_mode;

	wmin = 1024;
	hmin = 768;
	bppmin = 32;
#endif
    /*
     * Get a list of available display modes from DirectDraw
     */
    d3dappi.NumModes = 0;

    LastError = d3dappi.lpDD->lpVtbl->EnumDisplayModes(d3dappi.lpDD, 0, NULL,
                                                0, EnumDisplayModesCallback);

    if(LastError != DD_OK ) {
        D3DAppISetErrorString("EnumDisplayModes failed.\n%s",
                              D3DAppErrorToString(LastError));
        d3dappi.NumModes = 0;
        return FALSE;
    }
    /*
     * Sort the list of display modes
     */
    qsort((void *)&d3dappi.Mode[0], (size_t)d3dappi.NumModes, sizeof(D3DAppMode),
          CompareModes);
    /*
     * Pick a default display mode.  640x480x16 is a very good mode for
     * rendering, so choose it over all others.  Otherwise, just take the
     * first one.  This selection may be overriden later if a driver is
     * created which cannot render in this mode.
     */
#if 1
	default_mode = 0;
    for (i = 0; i < d3dappi.NumModes; i++)
	{
		if ( d3dappi.Mode[i].bpp >= 32 && bppmin >= d3dappi.Mode[i].bpp && wmin >= d3dappi.Mode[i].w && hmin >= d3dappi.Mode[i].h )
		{
			wmin = d3dappi.Mode[i].w;
			hmin = d3dappi.Mode[i].h;
			bppmin = d3dappi.Mode[i].bpp;
			default_mode = i;
		}
	}
	wmin = hmin = bppmin = 9999;
#endif
    mode = -1;
    for (i = 0; i < d3dappi.NumModes; i++) {
#if 1
		if ( ( !default_bpp || d3dappi.Mode[i].bpp == default_bpp ) &&
			 ( !default_width ||d3dappi.Mode[i].w == default_width ) &&
			 ( !default_height || d3dappi.Mode[i].h == default_height ) )
		{
			if ( !default_width || !default_height || !default_bpp )
			{
				if ( ( default_width || wmin >= d3dappi.Mode[i].w ) &&
					 ( default_height || hmin >= d3dappi.Mode[i].h ) &&
					 ( default_bpp || bppmin >= d3dappi.Mode[i].bpp ) )
				{
					if ( !default_width )
						wmin = d3dappi.Mode[i].w;
					if ( !default_height )
						hmin = d3dappi.Mode[i].h;
					if ( !default_bpp )
						bppmin = d3dappi.Mode[i].bpp;
					mode = i;
				}
			}
			else
				mode = i;
		}
#else
        if (d3dappi.Mode[i].w == default_width && d3dappi.Mode[i].h == default_height &&
            d3dappi.Mode[i].bpp == default_bpp)
            d3dappi.CurrMode = i;
#endif
    }
#if 1
	d3dappi.CurrMode = ( mode >= 0 ) ? mode : default_mode;
#endif
    memcpy(&d3dappi.ThisMode, &d3dappi.Mode[d3dappi.CurrMode],
           sizeof(D3DAppMode));
    return TRUE;
}

/***************************************************************************/
/*               Creating Front and Back Buffers (and misc surf funcs)     */
/***************************************************************************/
/*
 * D3DAppICreateSurface
 * Create a DirectDraw Surface of the given description.  Using this function
 * ensures that all surfaces end up in system memory if that option was set.
 * Returns the result of the CreateSurface call.
 */
HRESULT
D3DAppICreateSurface(LPDDSURFACEDESC lpDDSurfDesc,
                LPDIRECTDRAWSURFACE FAR *lpDDSurface) {
    HRESULT result;

//    if( (d3dapp->CurrDriver == 1) || (d3dapp->CurrDriver == 2))
//        lpDDSurfDesc->ddsCaps.dwCaps |= DDSCAPS_SYSTEMMEMORY;
	if (d3dappi.bOnlySystemMemory)
        lpDDSurfDesc->ddsCaps.dwCaps |= DDSCAPS_SYSTEMMEMORY;
    result = d3dappi.lpDD->lpVtbl->CreateSurface(d3dappi.lpDD, lpDDSurfDesc,
                                                 lpDDSurface, NULL);
    return result;
}

/*
 * D3DAppIGetSurfDesc
 * Get the description of the given surface.  Returns the result of the
 * GetSurfaceDesc call.
 */
HRESULT
D3DAppIGetSurfDesc(LPDDSURFACEDESC lpDDSurfDesc,LPDIRECTDRAWSURFACE lpDDSurf)
{
    HRESULT result;
    memset(lpDDSurfDesc, 0, sizeof(DDSURFACEDESC));
    lpDDSurfDesc->dwSize = sizeof(DDSURFACEDESC);
    result = lpDDSurf->lpVtbl->GetSurfaceDesc(lpDDSurf, lpDDSurfDesc);
    return result;
}

/*
 * D3DAppICreateBuffers
 * Creates the front and back buffers for the window or fullscreen case
 * depending on the bFullscreen flag.  In the window case, bpp is ignored.
 */
BOOL
D3DAppICreateBuffers(HWND hwnd, int w, int h, int bpp, BOOL bFullscreen)
{
    DDSURFACEDESC ddsd;
    DDSCAPS ddscaps;

    /*
     * Release any old objects that might be lying around.  This should have
     * already been taken care of, but just in case...
     */
    RELEASE(lpClipper);
    RELEASE(d3dappi.lpBackBuffer);
    RELEASE(d3dappi.lpFrontBuffer);
    /*
     * The size of the buffers is going to be w x h, so record it now
     */
    if (w < D3DAPP_WINDOWMINIMUM)
        w = D3DAPP_WINDOWMINIMUM;
    if (h < D3DAPP_WINDOWMINIMUM)
        h = D3DAPP_WINDOWMINIMUM;
    szBuffers.cx = w;
    szBuffers.cy = h;

    if (bFullscreen) {
        /*
         * Create a complex flipping surface for fullscreen mode with one
         * back buffer.
         */
        memset(&ddsd,0,sizeof(DDSURFACEDESC));
        ddsd.dwSize = sizeof( ddsd );
        ddsd.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
        ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE | DDSCAPS_FLIP |
            DDSCAPS_3DDEVICE | DDSCAPS_COMPLEX;
		if( !TripleBuffer )
		{
			ddsd.dwBackBufferCount = 1;
		}else{
	        ddsd.dwBackBufferCount = 2;
		}
        LastError = D3DAppICreateSurface(&ddsd, &d3dappi.lpFrontBuffer);
        if(LastError != DD_OK) {
            D3DAppISetErrorString("CreateSurface for fullscreen flipping surface failed.\n%s",
                                  D3DAppErrorToString(LastError));
            goto exit_with_error;
        }
        /* 
         * Obtain a pointer to the back buffer surface created above so we
         * can use it later.  For now, just check to see if it ended up in
         * video memory (FYI).
         */
		if( TripleBuffer )
		{
			ddscaps.dwCaps = DDSCAPS_BACKBUFFER;
			LastError = d3dappi.lpFrontBuffer->lpVtbl->GetAttachedSurface(d3dappi.lpFrontBuffer, &ddscaps, &d3dappi.lpBackBuffer);
			if(LastError != DD_OK) {
				D3DAppISetErrorString("GetAttachedSurface failed to get middle buffer.\n%s",
									  D3DAppErrorToString(LastError));
				goto exit_with_error;
			}
		}
        ddscaps.dwCaps = DDSCAPS_BACKBUFFER;
        LastError = d3dappi.lpFrontBuffer->lpVtbl->GetAttachedSurface(d3dappi.lpFrontBuffer, &ddscaps, &d3dappi.lpBackBuffer);
        if(LastError != DD_OK) {
            D3DAppISetErrorString("GetAttachedSurface failed to get back buffer.\n%s",
                                  D3DAppErrorToString(LastError));
            goto exit_with_error;
        }
        LastError = D3DAppIGetSurfDesc(&ddsd, d3dappi.lpBackBuffer);
        if (LastError != DD_OK) {
            D3DAppISetErrorString("Failed to get surface description of back buffer.\n%s",
                                  D3DAppErrorToString(LastError));
            goto exit_with_error;
        }
        d3dappi.bBackBufferInVideo =
                  (ddsd.ddsCaps.dwCaps & DDSCAPS_VIDEOMEMORY) ? TRUE : FALSE;
    }
    else {
        /*
         * In the window case, create a front buffer which is the primary
         * surface and a back buffer which is an offscreen plane surface.
         */
        memset(&ddsd,0,sizeof(DDSURFACEDESC));
        ddsd.dwSize = sizeof(DDSURFACEDESC);
        ddsd.dwFlags = DDSD_CAPS;
        ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
        /*
         * If we specify system memory when creating a primary surface, we
         * won't get the actual primary surface in video memory.  So, don't
         * use D3DAppICreateSurface().
         */
        LastError = d3dappi.lpDD->lpVtbl->CreateSurface(d3dappi.lpDD,
                                        &ddsd, &d3dappi.lpFrontBuffer, NULL);
        if(LastError != DD_OK ) {
            D3DAppISetErrorString("CreateSurface for window front buffer failed.\n%s",
                                  D3DAppErrorToString(LastError));
            goto exit_with_error;
        }
        ddsd.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;
        ddsd.dwWidth = w;
        ddsd.dwHeight = h;
        ddsd.ddsCaps.dwCaps= DDSCAPS_OFFSCREENPLAIN | DDSCAPS_3DDEVICE;
        LastError = D3DAppICreateSurface(&ddsd, &d3dappi.lpBackBuffer);
        if (LastError != DD_OK) {
            D3DAppISetErrorString("CreateSurface for window back buffer failed.\n%s",
                                  D3DAppErrorToString(LastError));
            goto exit_with_error;
        }
        /*
         * Check to see if the back buffer is in video memory (FYI).
         */
        LastError = D3DAppIGetSurfDesc(&ddsd, d3dappi.lpBackBuffer);
        if (LastError != DD_OK) {
            D3DAppISetErrorString("Failed to get surface description for back buffer.\n%s",
                                  D3DAppErrorToString(LastError));
            goto exit_with_error;
        }
        d3dappi.bBackBufferInVideo =
                  (ddsd.ddsCaps.dwCaps & DDSCAPS_VIDEOMEMORY) ? TRUE : FALSE;
        /*
         * Create the DirectDraw Clipper object and attach it to the window
         * and front buffer.
         */
        LastError = d3dappi.lpDD->lpVtbl->CreateClipper(d3dappi.lpDD, 0,
                                                        &lpClipper, NULL);
        if(LastError != DD_OK ) {
            D3DAppISetErrorString("CreateClipper failed.\n%s",
                                  D3DAppErrorToString(LastError));
            goto exit_with_error;
        }
        LastError = lpClipper->lpVtbl->SetHWnd(lpClipper, 0, hwnd);
        if(LastError != DD_OK ) {
            D3DAppISetErrorString("Attaching clipper to window failed.\n%s",
                                  D3DAppErrorToString(LastError));
            goto exit_with_error;
        }
        LastError =
             d3dappi.lpFrontBuffer->lpVtbl->SetClipper(d3dappi.lpFrontBuffer,
                                                       lpClipper);
        if(LastError != DD_OK ) {
            D3DAppISetErrorString("Attaching clipper to front buffer failed.\n%s",
                                  D3DAppErrorToString(LastError));
            goto exit_with_error;
        }
    }

    D3DAppIClearBuffers();
    return TRUE;

exit_with_error:
    RELEASE(d3dappi.lpFrontBuffer);
    RELEASE(d3dappi.lpBackBuffer);
    RELEASE(lpClipper);
    return FALSE;
}

/*
 * D3DAppICheckForPalettized
 * If the front/back buffer is palettized, we need to create a palette.
 */
BOOL
D3DAppICheckForPalettized(void)
{
    DDSURFACEDESC ddsd;
    /*
     * Get the back buffer surface description and check to see if it's
     * palettized
     */
    LastError = D3DAppIGetSurfDesc(&ddsd, d3dappi.lpBackBuffer);
    if (LastError != DD_OK) {
        D3DAppISetErrorString("Failed to get surface description for back buffer for palettizing.\n%s",
                              D3DAppErrorToString(LastError));
        goto exit_with_error;
    }
    bPrimaryPalettized = 
        (ddsd.ddpfPixelFormat.dwFlags & DDPF_PALETTEINDEXED8) ? TRUE : FALSE;

    if (bPrimaryPalettized) {
        int i;
        /*
         * Get the current palette.
         */
        HDC hdc = GetDC(NULL);
        GetSystemPaletteEntries(hdc, 0, (1 << 8), ppe);
        ReleaseDC(NULL, hdc);

		lpPalette = DDLoadPalette( d3dappi.lpDD , ".\\data\\pictures\\pal.bmp");
		lpPalette->lpVtbl->GetEntries(lpPalette, 0, 0, 256,
	                                  &ppe[0]);

        
		/*
         * Change the flags on the palette entries to allow D3D to change
         * some of them.  In the window case, we must not change the top and
         * bottom ten (system colors), but in a fullscreen mode we can have
         * all but the first and last.
         */
#if 0
        if (!d3dappi.bFullscreen) {
            for (i = 0; i < 10; i++) ppe[i].peFlags = D3DPAL_READONLY;
            for (i = 10; i < 256 - 10; i++) ppe[i].peFlags = PC_RESERVED;
            for (i = 256 - 10; i < 256; i++) ppe[i].peFlags = D3DPAL_READONLY;
        } else {
            ppe[0].peFlags = D3DPAL_READONLY;
            for (i = 1; i < 255; i++) ppe[i].peFlags = PC_RESERVED;
            ppe[255].peFlags = D3DPAL_READONLY;
        }
#endif
       for (i = 0; i < 256; i++) ppe[i].peFlags = D3DPAL_READONLY;
        /*
         * Create a palette using the old colors and new flags
         */
        LastError = d3dappi.lpDD->lpVtbl->CreatePalette(d3dappi.lpDD,
                                           DDPCAPS_8BIT | DDPCAPS_INITIALIZE,
                                           ppe, &lpPalette, NULL);
        if (LastError != DD_OK) {
            D3DAppISetErrorString("CreatePalette failed.\n%s",
                                  D3DAppErrorToString(LastError));
            goto exit_with_error;
        }
        /*
         * Set this as the front and back buffers' palette
         */
        LastError =
               d3dappi.lpBackBuffer->lpVtbl->SetPalette(d3dappi.lpBackBuffer,
                                                        lpPalette);
        if(LastError != DD_OK ) {
            D3DAppISetErrorString("SetPalette failed on back buffer.\n%s",
                                  D3DAppErrorToString(LastError));
            goto exit_with_error;
        }
        LastError =
             d3dappi.lpFrontBuffer->lpVtbl->SetPalette(d3dappi.lpFrontBuffer,
                                                       lpPalette);
        if(LastError != DD_OK ) {
            D3DAppISetErrorString("SetPalette failed on front buffer.\n%s",
                                  D3DAppErrorToString(LastError));
            goto exit_with_error;
        }
        /*
         * The palette is now valid, so set it again on anyt WM_ACTIVATE
         */
        bPaletteActivate = TRUE;
    }
    return TRUE;
exit_with_error:
    RELEASE(lpPalette);
    return FALSE;
}

/***************************************************************************/
/*                           Creation of Z-Buffer                          */
/***************************************************************************/
/*
 * D3DAppICreateZBuffer
 * Create a Z-Buffer of the appropriate depth and attach it to the back
 * buffer.
 */
BOOL
D3DAppICreateZBuffer(int w, int h, int driver)
{
    DDSURFACEDESC ddsd;
    DWORD devDepth;
    /*
     * Release any Z-Buffer that might be around just in case.
     */
    RELEASE(d3dappi.lpZBuffer);
    
    /*
     * If this driver does not do z-buffering, don't create a z-buffer
     */
    if (!d3dappi.Driver[driver].bDoesZBuffer)
        return TRUE;

    memset(&ddsd, 0 ,sizeof(DDSURFACEDESC));
    ddsd.dwSize = sizeof( ddsd );
    ddsd.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS |
                   DDSD_ZBUFFERBITDEPTH;
    ddsd.ddsCaps.dwCaps = DDSCAPS_ZBUFFER;
    ddsd.dwHeight = h;
    ddsd.dwWidth = w;
    /*
     * If this is a hardware D3D driver, the Z-Buffer MUST end up in video
     * memory.  Otherwise, it MUST end up in system memory.
     */
    if (d3dappi.Driver[driver].bIsHardware)
        ddsd.ddsCaps.dwCaps |= DDSCAPS_VIDEOMEMORY;
    else
        ddsd.ddsCaps.dwCaps |= DDSCAPS_SYSTEMMEMORY;
    /*
     * Get the Z buffer bit depth from this driver's D3D device description
     */
    devDepth = d3dappi.Driver[driver].Desc.dwDeviceZBufferBitDepth;
    if (devDepth & DDBD_32)
        ddsd.dwZBufferBitDepth = 32;
    else if (devDepth & DDBD_24)
        ddsd.dwZBufferBitDepth = 24;
    else if (devDepth & DDBD_16)
        ddsd.dwZBufferBitDepth = 16;
    else if (devDepth & DDBD_8)
        ddsd.dwZBufferBitDepth = 8;
    else {
        D3DAppISetErrorString("Unsupported Z-buffer depth requested by device.\n");
        return FALSE;
    }
    LastError = d3dappi.lpDD->lpVtbl->CreateSurface(d3dappi.lpDD, &ddsd,
                                                    &d3dappi.lpZBuffer,
                                                    NULL);
    if(LastError != DD_OK) {
        D3DAppISetErrorString("CreateSurface for Z-buffer failed.\n%s",
                              D3DAppErrorToString(LastError));
        goto exit_with_error;
    }
    /*
     * Attach the Z-buffer to the back buffer so D3D will find it
     */
    LastError =
       d3dappi.lpBackBuffer->lpVtbl->AddAttachedSurface(d3dappi.lpBackBuffer,
                                                        d3dappi.lpZBuffer);
    if(LastError != DD_OK) {
        D3DAppISetErrorString("AddAttachedBuffer failed for Z-Buffer.\n%s",
                              D3DAppErrorToString(LastError));
        goto exit_with_error;
    }
    /*
     * Find out if it ended up in video memory.
     */
    LastError = D3DAppIGetSurfDesc(&ddsd, d3dappi.lpZBuffer);
    if (LastError != DD_OK) {
        D3DAppISetErrorString("Failed to get surface description of Z buffer.\n%s",
                              D3DAppErrorToString(LastError));
        goto exit_with_error;
    }
    d3dappi.bZBufferInVideo =
                  (ddsd.ddsCaps.dwCaps & DDSCAPS_VIDEOMEMORY) ? TRUE : FALSE;
    if (d3dappi.Driver[driver].bIsHardware && !d3dappi.bZBufferInVideo) {
        D3DAppISetErrorString("Could not fit the Z-buffer in video memory for this hardware device.\n");
        goto exit_with_error;
    }

    return TRUE;

exit_with_error:
    RELEASE(d3dappi.lpZBuffer);
    return FALSE;
}
void StoreMyShieldHull( void );
void ReStoreMyShieldHull( void );

/***************************************************************************/
/*                             WM_SIZE Handler                             */
/***************************************************************************/
/*
 * D3DAppIHandleWM_SIZE
 * Processes the WM_SIZE message.  Resizes all the buffers and re-creates
 * device if necessary.
 */
BOOL
D3DAppIHandleWM_SIZE(LRESULT* lresult, HWND hwnd, UINT message,
                     WPARAM wParam, LPARAM lParam)
{
    int w, h;
    /*
     * If we have minimzied, take note and call the default window proc
     */
    if (wParam == SIZE_MINIMIZED) {
		StoreMyShieldHull();

        d3dappi.bMinimized = TRUE;
        *lresult = DefWindowProc(hwnd, message, wParam, lParam);
        return TRUE;
    }
    /*
     * In fullscreen mode, restore our surfaces and let DDraw take
     * care of the rest.
     */
    if (d3dappi.bFullscreen) {
        D3DAppCheckForLostSurfaces();
        d3dappi.bMinimized = FALSE;
        *lresult = DefWindowProc(hwnd, message, wParam, lParam);
        return TRUE;
    }
    /*
     * If we are minimized, this is the un-minimized size message.
     */
    if (d3dappi.bMinimized) {
        /*
         * Restore our surfaces
         */
		ReStoreMyShieldHull();
        D3DAppCheckForLostSurfaces();
        d3dappi.bMinimized = FALSE;
        *lresult = DefWindowProc(hwnd, message, wParam, lParam);
        return TRUE;
    }
    /*
     * Since we are still here, this must be a regular, window resize
     * message.  A new viewport will definitely be needed, but the
     * device and buffers will only be re-created if they have gotten bigger
     * or change size by a very large amount.
     */
    D3DAppIGetClientWin(hwnd);
    w = LOWORD(lParam);
    h = HIWORD(lParam);
    /*
     * If w and h are under the minimum, create buffers of the minimum size
     */
    if (w < D3DAPP_WINDOWMINIMUM)
        w = D3DAPP_WINDOWMINIMUM;
    if (h < D3DAPP_WINDOWMINIMUM)
        h = D3DAPP_WINDOWMINIMUM;
    /*
     * Destroy the viewport and all execute buffers
     */
    d3dappi.bRenderingIsOK = FALSE;
    ATTEMPT(D3DAppICallDeviceDestroyCallback());
    /*
     * Only create a new device and buffers if they changed significantly,
     * otherwise just make sure the old buffers aren't lost.
     */
    if ((w > szBuffers.cx || h > szBuffers.cy) ||
        (w < szBuffers.cx / 2 || h < szBuffers.cy / 2)) {
        /*
         * Release the device
         */
        RELEASE(d3dappi.lpD3DDevice);
        /*
         * Release the old buffers
         */
        RELEASE(d3dappi.lpZBuffer);
        RELEASE(lpPalette);
        RELEASE(lpClipper);
        RELEASE(d3dappi.lpBackBuffer);
        RELEASE(d3dappi.lpFrontBuffer);
        /*
         * Create new ones
         */
        ATTEMPT(D3DAppICreateBuffers(hwnd, w, h, D3DAPP_BOGUS, FALSE));
        ATTEMPT(D3DAppICheckForPalettized());
        ATTEMPT(D3DAppICreateZBuffer(w, h, d3dappi.CurrDriver));
        /*
         * Create the driver
         */
        ATTEMPT(D3DAppICreateDevice(d3dappi.CurrDriver));
        /*
         * Since the driver did not change, the texture surfaces are still valid.
         * We just need to get new handles.
         */
        if (d3dappi.ThisDriver.bDoesTextures) {
        }
    } else {
        D3DAppCheckForLostSurfaces();
    }
    /*
     * Call the device create callback to create the viewport, set the render
     * state
     */
    ATTEMPT(D3DAppICallDeviceCreateCallback(w, h));
    ATTEMPT(D3DAppISetRenderState());
    d3dappi.bRenderingIsOK = TRUE;
    /*
     * Call the default window proc
     */
    *lresult = DefWindowProc(hwnd, message, wParam, lParam);
    return TRUE;
exit_with_error:
    D3DAppICallDeviceDestroyCallback();
    RELEASE(d3dappi.lpD3DDevice);
    RELEASE(d3dappi.lpZBuffer);
    RELEASE(lpPalette);
    RELEASE(lpClipper);
    RELEASE(d3dappi.lpBackBuffer);
    RELEASE(d3dappi.lpFrontBuffer);
    return FALSE;
}

/***************************************************************************/
/*              Setting the display mode and cooperative level             */
/***************************************************************************/
/*
 * D3DAppISetCoopLevel
 * Set the cooperative level to exclusive mode for fullscreen and normal for
 * a window.  Set the bIgnoreWM_SIZE flag because SetCooperativeLevel
 * generates a WM_SIZE message you do not have to resize the buffers on.
 */
BOOL
D3DAppISetCoopLevel(HWND hwnd, BOOL bFullscreen)
{
    if (bFullscreen) {
        bIgnoreWM_SIZE = TRUE;
        LastError = d3dappi.lpDD->lpVtbl->SetCooperativeLevel(d3dappi.lpDD,
                                   hwnd, DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN  );
        bIgnoreWM_SIZE = FALSE;
        if(LastError != DD_OK ) {
            D3DAppISetErrorString("SetCooperativeLevel to fullscreen failed.\n%s",
                                  D3DAppErrorToString(LastError));
            return FALSE;
        }
        d3dappi.bFullscreen = TRUE;
    } else {
        bIgnoreWM_SIZE = TRUE;
        LastError = d3dappi.lpDD->lpVtbl->SetCooperativeLevel(d3dappi.lpDD,
                                                         hwnd, DDSCL_NORMAL );
        bIgnoreWM_SIZE = FALSE;
        if(LastError != DD_OK ) {
            D3DAppISetErrorString("SetCooperativeLevel to normal failed.\n%s",
                                  D3DAppErrorToString(LastError));
            return FALSE;
        }
        d3dappi.bFullscreen = FALSE;
    }
    return TRUE;
}

/*
 * D3DAppISetDisplayMode
 * Set the display mode to the given dimensions and bits per pixel.  The
 * bIgnoreWM_SIZE message is set because the display change generates a
 * WM_SIZE message which we don't want to resize the buffers on.
 */
BOOL
D3DAppISetDisplayMode(int w, int h, int bpp)
{
//	LPDIRECTDRAW2	lpDD2;

    d3dappi.ThisMode.w = w; d3dappi.ThisMode.h = h;
    d3dappi.ThisMode.bpp = bpp;
    bIgnoreWM_SIZE = TRUE;

//	IDirectDraw_QueryInterface(d3dappi.lpDD , &IID_IDirectDraw2, (LPVOID *)&lpDD2); 


    LastError = d3dappi.lpDD->lpVtbl->SetDisplayMode(d3dappi.lpDD, w, h,
                                                     bpp);
//    LastError = IDirectDraw2_SetDisplayMode( lpDD2, w, h, bpp, 72000, 0 );
    bIgnoreWM_SIZE = FALSE;
    if(LastError != DD_OK ) {
        D3DAppISetErrorString("SetDisplayMode to %dx%dx%d failed\n%s",
                              w, h, bpp, D3DAppErrorToString(LastError));
        return FALSE;
    }
    return TRUE;
}

/*
 * D3DAppIRestoreDispMode
 * Restores the display mode to the current windows display mode.  The
 * bIgnoreWM_SIZE message is set because the display change generates a
 * WM_SIZE message which we don't want to resize the buffers on.
 */
BOOL
D3DAppIRestoreDispMode(void)
{
    bIgnoreWM_SIZE = TRUE;
    LastError = d3dappi.lpDD->lpVtbl->RestoreDisplayMode(d3dappi.lpDD);
    if (LastError != DD_OK) {
        D3DAppISetErrorString("RestoreDisplayMode failed.\n%s",
                              D3DAppErrorToString(LastError));
        return FALSE;
    }
    bIgnoreWM_SIZE = FALSE;
    return TRUE;
}

/*
 * D3DAppRememberWindowsMode
 * Record the current display mode in d3dappi.WindowsDisplay
 */
BOOL
D3DAppIRememberWindowsMode(void)
{
    DDSURFACEDESC ddsd;

    memset(&ddsd, 0, sizeof(DDSURFACEDESC));
    ddsd.dwSize = sizeof(DDSURFACEDESC);
    LastError = d3dappi.lpDD->lpVtbl->GetDisplayMode(d3dappi.lpDD, &ddsd);
    if (LastError != DD_OK) {
        D3DAppISetErrorString("Getting the current display mode failed.\n%s",
                              D3DAppErrorToString(LastError));
        return FALSE;
    }
    d3dappi.WindowsDisplay.w = ddsd.dwWidth;
    d3dappi.WindowsDisplay.h = ddsd.dwHeight;
    d3dappi.WindowsDisplay.bpp = ddsd.ddpfPixelFormat.dwRGBBitCount;
    return TRUE;
}

/***************************************************************************/
/*                          Misc DD Utilities                              */
/***************************************************************************/

/*
 * D3DAppIClearBuffers
 * Clear the front and back buffers to black
 */
BOOL
D3DAppIClearBuffers(void)
{
    DDSURFACEDESC ddsd;
    RECT dst;
    DDBLTFX ddbltfx;

	if ( PreventFlips )
		return TRUE;
    /*
     * Find the width and height of the front buffer by getting its
     * DDSURFACEDESC
     */
    if (d3dappi.lpFrontBuffer) {
        LastError = D3DAppIGetSurfDesc(&ddsd, d3dappi.lpFrontBuffer);
        if (LastError != DD_OK) {
            D3DAppISetErrorString("Failure getting the surface description of the front buffer before clearing.\n%s",
                                  D3DAppErrorToString(LastError));
            return FALSE;
        }
        /*
         * Clear the front buffer to black
         */
        memset(&ddbltfx, 0, sizeof(ddbltfx));
        ddbltfx.dwSize = sizeof(DDBLTFX);
        SetRect(&dst, 0, 0, ddsd.dwWidth, ddsd.dwHeight);
        LastError = d3dappi.lpFrontBuffer->lpVtbl->Blt(d3dappi.lpFrontBuffer,
                                                    &dst, NULL, NULL, 
                                                    DDBLT_COLORFILL | DDBLT_WAIT,
                                                    &ddbltfx);
        if (LastError != DD_OK) {
            D3DAppISetErrorString("Clearing the front buffer failed.\n%s",
                                  D3DAppErrorToString(LastError));
            return FALSE;
        }
    }
    if (d3dappi.lpBackBuffer) {
        /*
         * Find the width and height of the back buffer by getting its
         * DDSURFACEDESC
         */
        LastError = D3DAppIGetSurfDesc(&ddsd, d3dappi.lpBackBuffer);
        if (LastError != DD_OK) {
            D3DAppISetErrorString("Failure while getting the surface description of the back buffer before clearing.\n%s",
                                  D3DAppErrorToString(LastError));
            return FALSE;
        }
        /*
         * Clear the back buffer to black
         */
        memset(&ddbltfx, 0, sizeof(ddbltfx));
        ddbltfx.dwSize = sizeof(DDBLTFX);
        SetRect(&dst, 0, 0, ddsd.dwWidth, ddsd.dwHeight);
        LastError = d3dappi.lpBackBuffer->lpVtbl->Blt(d3dappi.lpBackBuffer, &dst,
                                                     NULL, NULL,
                                                     DDBLT_COLORFILL | DDBLT_WAIT,
                                                     &ddbltfx);
        if (LastError != DD_OK) {
            D3DAppISetErrorString("Clearing the back buffer failed.\n%s",
                                  D3DAppErrorToString(LastError));
            return FALSE;
        }
    }
    return TRUE;
}

/*
 * D3DAppIBPPToDDBD
 * Convert an integer bit per pixel number to a DirectDraw bit depth flag
 */
DWORD
D3DAppIBPPToDDBD(int bpp)
{
    switch(bpp) {
        case 1:
            return DDBD_1;
        case 2:
            return DDBD_2;
        case 4:
            return DDBD_4;
        case 8:
            return DDBD_8;
        case 16:
            return DDBD_16;
        case 24:
            return DDBD_24;
        case 32:
            return DDBD_32;
        default:
            return (DWORD)D3DAPP_BOGUS;
    }
}


/*
 * D3DAppTotalVideoMemory
 * Returns the amount of total video memory supported (not free)
 */
DWORD
D3DAppTotalVideoMemory(void)
{
#if 0
	DDCAPS DriverCaps, HELCaps;
    memset (&DriverCaps, 0, sizeof(DDCAPS));
    DriverCaps.dwSize = sizeof(DDCAPS);
    memset (&HELCaps, 0, sizeof(DDCAPS));
    HELCaps.dwSize = sizeof(DDCAPS);
    LastError = d3dappi.lpDD->lpVtbl->GetCaps(d3dappi.lpDD, &DriverCaps,
                                              &HELCaps);
    if (LastError != DD_OK) {
        D3DAppISetErrorString("Getting DD capabilities failed while checking total video memory.\n%s",
                              D3DAppErrorToString(LastError));
        return 0L;
    }
    if (DriverCaps.dwVidMemTotal)
        return DriverCaps.dwVidMemTotal;
    else
        return HELCaps.dwVidMemTotal;
#endif

	LPDIRECTDRAW4 lpdd4;
	DDSCAPS2      ddsCaps2;
	DWORD         dwTotal, dwFree;
	DDSURFACEDESC2 dds2;
	
	// get dd4 ptr...
	IDirectDraw4_QueryInterface( d3dappi.lpDD, &IID_IDirectDraw4, (LPVOID *)&lpdd4 );  

	memset( &ddsCaps2, 0, sizeof( DDSCAPS2 ) );
	ddsCaps2.dwCaps = DDSCAPS_LOCALVIDMEM;

	if ( IDirectDraw4_GetAvailableVidMem( lpdd4, &ddsCaps2, &dwTotal, &dwFree ) != DD_OK )
		dwTotal = 0;

	if ( dwTotal )
	{
		memset( &dds2, 0, sizeof( DDSURFACEDESC2 ) );
		dds2.dwSize = sizeof( DDSURFACEDESC2 );
		if ( IDirectDraw4_GetDisplayMode( lpdd4, &dds2  ) == DD_OK )
		{
			dwTotal += ( dds2.dwHeight * dds2.lPitch  );
		}
	}

	IDirectDraw4_Release( lpdd4 );

	return dwTotal;
}
/*
 * D3DAppFreeVideoMemory
 * Returns the amount of free video memory 
 */
DWORD
D3DAppFreeVideoMemory(void)
{
    DDCAPS DriverCaps, HELCaps;
    memset (&DriverCaps, 0, sizeof(DDCAPS));
    DriverCaps.dwSize = sizeof(DDCAPS);
    memset (&HELCaps, 0, sizeof(DDCAPS));
    HELCaps.dwSize = sizeof(DDCAPS);
    LastError = d3dappi.lpDD->lpVtbl->GetCaps(d3dappi.lpDD, &DriverCaps,
                                              &HELCaps);
    if (LastError != DD_OK) {
        D3DAppISetErrorString("Getting DD capabilities failed while getting free video memory.\n%s",
                              D3DAppErrorToString(LastError));
        return 0L;
    }
    if (DriverCaps.dwVidMemFree)
        return DriverCaps.dwVidMemFree;
    else
        return HELCaps.dwVidMemFree;
}

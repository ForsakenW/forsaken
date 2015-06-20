/*
 * The X Men, June 1996
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * $Revision: 12 $
 *
 * $Header: /PcProjectX/include/D3dappi.h 12    14/08/98 15:25 Philipy $
 *
 * $Log: /PcProjectX/include/D3dappi.h $
 * 
 * 12    14/08/98 15:25 Philipy
 * added trilinear option to menus
 * fixed level name / shutdown packet in heartbeat
 * 
 * 
 * 11    1/10/97 11:30a Phillipd
 * movies are now doable
 * 
 * 10    11/22/96 9:20a Phillipd
 * Put in c for asm flag and made a bit more watcom compatible
 * 
 * 9     10/24/96 3:01p Phillipd
 * 
 * 8     10/23/96 4:24p Phillipd
 * Lots of crap taken out of D3dapp and its associated functions and
 * files....
 * 
 * 7     10/23/96 9:56a Phillipd
 * 
 * 6     9/19/96 3:33p Phillipd
 * 
 * 4     7/22/96 11:16a Phillipd
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
 *  File: d3dappi.h
 *
 *  Internal header.  Part of D3DApp.
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

#ifndef __D3DAPPI_H__
#define __D3DAPPI_H__

/*
 * INCLUDED HEADERS
 */
#define WIN32_EXTRA_LEAN
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <search.h>
#include <ddraw.h>
#include <d3d.h>
#include "d3dapp.h"
#include "d3dmacs.h"
#include "d3dmain.h"
#include "lclib.h"  /* lclib is a override for standard string lib */

// ProjX 09438c20-e06a-11ce-8681-00aa006c5d58
//DEFINE_GUID(PROJX_GUID,0x09438c20,0xe06a,0x11CE,0x86,0x81,0x00,0xaa,0x00,0x6c,0x5d,0x58);

#ifdef __cplusplus
extern "C" {
#endif

#define TRILINEAR_MENU_OPTION

/*
 * MACROS
 */
#undef ATTEMPT
#define ATTEMPT(x) if (!(x)) goto exit_with_error
#undef RELEASE
#define RELEASE(x) if (x) { x->lpVtbl->Release(x); x = NULL; }
#undef MAX
#define MAX(x, y) ((x) > (y)) ? (x) : (y)
#undef MIN
#define MIN(x, y) ((x) > (y)) ? (y) : (x)
#undef ZEROMEM
#define ZEROMEM(x) memset(&x, 0, sizeof(x))

/*
 * GLOBAL VARIABLES
 *    see d3dapp.c for descriptions
 */
extern D3DAppInfo d3dappi;
extern D3DAppRenderState d3dapprs;
extern BOOL bD3DAppInitialized;
extern HRESULT LastError;
extern LPDIRECTDRAWCLIPPER lpClipper;
extern LPDIRECTDRAWPALETTE lpPalette;
extern BOOL(*D3DDeviceDestroyCallback)(LPVOID);
extern LPVOID D3DDeviceDestroyCallbackContext;
extern BOOL(*D3DDeviceCreateCallback)(int, int, LPDIRECT3DVIEWPORT*, LPVOID);
extern LPVOID D3DDeviceCreateCallbackContext;
extern BOOL bPrimaryPalettized;
extern BOOL bPaletteActivate;
extern BOOL bIgnoreWM_SIZE;
extern PALETTEENTRY ppe[256];
extern PALETTEENTRY Originalppe[256];
extern char LastErrorString[256];
extern SIZE szLastClient;
extern SIZE szBuffers;
extern int CallbackRefCount;

#ifdef __cplusplus
};
#endif

/*
 * INTERNAL FUNCTION PROTOTYPES
 */
BOOL D3DAppISetRenderState(void);
BOOL D3DAppIEnumDrivers(void);
BOOL D3DAppIPickDriver(int* driver, DWORD depths);
BOOL D3DAppICreateD3D(void);
BOOL D3DAppIEnumTextureFormats(void);
BOOL D3DAppICreateZBuffer(int w, int h, int driver);
BOOL D3DAppICreateDevice(int driver);
BOOL D3DAppISetCoopLevel(HWND hwnd, BOOL bFullscreen);
BOOL D3DAppISetDisplayMode(int w, int h, int bpp);
BOOL D3DAppICheckForPalettized(void);
BOOL D3DAppIRestoreDispMode(void);
BOOL D3DAppIVerifyDriverAndMode(int* lpdriver, int* lpmode);
BOOL D3DAppIFilterDrivers(int mode);
DWORD D3DAppTotalVideoMemory(void);
DWORD D3DAppFreeVideoMemory(void);
BOOL D3DAppIEnumDisplayModes(void);
BOOL D3DAppIPickDisplayMode(int* mode, DWORD depths);
BOOL D3DAppISetDispMode(int w, int h, int bpp);
BOOL D3DAppICreateDD(DWORD flags);
BOOL D3DAppIFilterDisplayModes(int driver);
HRESULT D3DAppICreateSurface(LPDDSURFACEDESC lpDDSurfDesc,
                LPDIRECTDRAWSURFACE FAR *lpDDSurface);
HRESULT D3DAppIGetSurfDesc(LPDDSURFACEDESC lpDDSurfDesc,
                           LPDIRECTDRAWSURFACE lpDDSurf);
BOOL D3DAppICreateBuffers(HWND hwnd, int w, int h, int bpp,BOOL bFullscreen);
BOOL D3DAppIRememberWindowsMode(void);
BOOL D3DAppIClearBuffers(void);
DWORD D3DAppIBPPToDDBD(int bpp);
void D3DAppIReleasePathList(void);
void D3DAppISetClientSize(HWND hwnd, int w,int h,BOOL bReturnFromFullscreen);
void D3DAppIGetClientWin(HWND hwnd);
void D3DAppISetDefaults(void);
BOOL D3DAppICallDeviceDestroyCallback(void);
BOOL D3DAppICallDeviceCreateCallback(int w, int h);
void D3DAppIMergeRectLists(int* dstnum, LPD3DRECT dst, int src1num,
                           LPD3DRECT src1, int src2num, LPD3DRECT src2);
void D3DAppICopyRectList(int* dstnum, LPD3DRECT dst, int srcnum,
                         LPD3DRECT src);
BOOL D3DAppIHandleWM_SIZE(LRESULT* lresult, HWND hwnd, UINT message,
                          WPARAM wParam, LPARAM lParam);
void __cdecl D3DAppISetErrorString( LPSTR fmt, ... );

void __cdecl dpf( LPSTR fmt, ... );

FILE * D3DAppIFindFile(const char *name, const char *mode);
#endif // __D3DAPPI_H__

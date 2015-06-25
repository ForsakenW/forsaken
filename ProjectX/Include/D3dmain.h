/*
 * The X Men, June 1996
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * Authors: Phillipd, Oliverc, Collinsd, Philipy
 */

/*
 *  Copyright (C) 1996 Microsoft Corporation. All Rights Reserved.
 *
 *  File: d3dmain.h
 *
 */
#ifndef __D3DMAIN_H__
#define __D3DMAIN_H__

#define WIN32_EXTRA_LEAN
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <search.h>
#include <ddraw.h>
#include <d3d.h>
#include "d3dapp.h"         /* prototypes for D3D helper functions */
#include "d3dres.h"         /* defines constants used in d3dmain.rc */
#include "d3ddemo.h"        /* prototypes for functions to communicate with
                               each sample */
#ifdef ORIGINAL
#define START_WIN_SIZE 320  /* initial size of the window */
#define START_WIN_SIZE_X 320+8  /* initial size of the window */
#define START_WIN_SIZE_Y 200+46  /* initial size of the window */
#else
#define START_WIN_SIZE 640  /* initial size of the window */
#define START_WIN_SIZE_X 640+8  /* initial size of the window */
#define START_WIN_SIZE_Y 400+46  /* initial size of the window */
#endif

#include "new3d.h"
#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct tagd3dmainglobals {
    HWND hWndMain;          /* application window handle */
    HINSTANCE hInstApp;     /* application instance for dialog boxes */

    D3DAppRenderState rstate; /* struct describing the current render state */

    BOOL bSingleStepMode;        /* render one frame at a time */
    BOOL bDrawAFrame;            /* render on this pass of the main loop */
    BOOL bClearsOn;              /* clear the back and z-buffer each frame */
    BOOL bShowFrameRate;         /* show the frame rate at the top */
    BOOL bShowInfo;              /* show window information at the bottom */
    BOOL bResizingDisabled;      /* do not allow resizing */

    BOOL bResized; /* the window has resized or some other drastic change, the
                      entire client area should be cleared */
    BOOL bQuit;    /* program is about to terminate */

    LPDIRECTDRAWSURFACE lpFrameRateBuffer; /* frame rate surface */
    LPDIRECTDRAWSURFACE lpInfoBuffer;      /* window info surface */
} d3dmainglobals;

#ifdef SUPER
    extern HANDLE AVIThreadControlEvent;
    extern  d3dmainglobals  myglobs;
    extern  VECTOR Camera_Pos;
    extern  uint16 NumGroupsVisible;
    extern  uint16 GroupImIn;
    extern  uint16 NumCollides;
    extern  float ticksperframe;
    extern  DWORD GroupPolyCol_timeMax;
    extern  long debug_long;
    extern  BOOL cursorclipped;
    extern  RECT cursorclip;
    extern  BYTE                    WhoIAm;

    extern  int16       NumLevels;
    extern  char    ShortLevelNames[MAXLEVELS][32];
    extern  int16       LevelNum;
    extern  int16       NewLevelNum;
    extern  BOOL        PrimaryLightDetail;
    extern  BOOL        SecondaryLightDetail;
    extern  BOOL        PickupLightDetail;

    extern  BYTE        MyGameStatus;
    
    void TestBlt();
    void SetCursorClip( void );
    void ReallyShowCursor( BOOL );
    void EnablePrimaryLights( void );
    void DisablePrimaryLights( void );
    void EnableSecondaryLights( void );
    void DisableSecondaryLights( void );
    void EnablePickupLights( void );
    void DisablePickupLights( void );

    extern  int     BikeDetail;

#endif
void __cdecl Msg( LPSTR fmt, ... );
int __cdecl RetryMsg( LPSTR fmt, ... );

#ifdef __cplusplus
};
#endif

#endif // __D3DMAIN_H__

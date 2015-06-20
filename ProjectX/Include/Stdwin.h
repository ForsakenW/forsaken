//==========================================================================;
//
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
//  PURPOSE.
//
//  Copyright (c) 1992 - 1996  Microsoft Corporation.  All Rights Reserved.
//
//--------------------------------------------------------------------------;

// Allows Visual C++ to precompile the standard header files

#ifndef STDWIN_INC
#define STDWIN_INC

#ifdef NDEBUG
  #define ASSERT( exp ) ((void)0)
#else
  void DbgAssert(const char *pCondition, const char *pFileName, int iLine);
  #define ASSERT(exp) if(!(exp)) DbgAssert( TEXT(#exp), TEXT(__FILE__), TEXT(__LINE__) );
#endif

#include <windows.h>
#include <commdlg.h>
#include <string.h>
#include <objbase.h>
//#include <strmif.h>
//#include <control.h>
//#include <uuids.h>

#ifdef USE_A3D
#include <a3dguid.h>
#endif

//DEFINE_GUID(PROJX_GUID,0x09438c20,0xe06a,0x11CE,0x86,0x81,0x00,0xaa,0x00,0x6c,0x5d,0x58);

/*

  Pre - win '98 demo version


// {27E96003-B1C3-11d1-B00C-080009C042E7}
DEFINE_GUID(PROJX_GUID, 
0x27e96003, 0xb1c3, 0x11d1, 0xb0, 0xc, 0x8, 0x0, 0x9, 0xc0, 0x42, 0xe7);

*/

// {E5DEE400-046A-11d2-B00C-080009C042E7}
DEFINE_GUID(PROJX_GUID, 
0xe5dee400, 0x46a, 0x11d2, 0xb0, 0xc, 0x8, 0x0, 0x9, 0xc0, 0x42, 0xe7);

#endif // STDWIN_INC
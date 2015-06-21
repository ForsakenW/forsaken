/*
 * The X Men, June 1996
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * Authors: Collinsd, Phillipd
 */

/*-------------------------------------------------------------------
    Define True/False and Data sizes
-------------------------------------------------------------------*/
#ifndef DATATYPES
#define DATATYPES

// These should either be defined at the project level, or the defaults
// should be used (as defined in DX headers). This is because they aren't
// just used within this code, but may also select header-level features.
// #define DIRECT3D_VERSION    0x0700 // Header default
// #define DIRECTSOUND_VERSION 0x0700 // Conditional depending on OS version
// #define DIRECTDRAW_VERSION  0x0700 // Header default
// #define DIRECTINPUT_VERSION 0x0700



#ifndef TRUE
#define TRUE                    (1==1)
#endif

#ifndef FALSE
#define FALSE                   (!TRUE)
#endif

#define GLOBAL_SCALE            (0.25F)

typedef unsigned char       uint8;          /* Unsigned 8 Bit Integer  */
typedef char                int8;           /* Signed 8 Bit Integer    */
typedef unsigned short int  uint16;         /* Unsigned 16 Bit Integer */
typedef short int           int16;          /* Signed 16 bit Integer   */
typedef unsigned long       uint32;         /* Unsigned 32 Bit Integer */
typedef long                int32;          /* Signed 32 Bit Integer   */

#endif


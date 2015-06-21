#ifndef FILE_H
#define FILE_H
/*
 * The X Men, June 1996
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * Authors: Collinsd, Oliverc, Philipy, Phillipd
 */

/*-------------------------------------------------------------------
    Define Prototypes for file.c
-------------------------------------------------------------------*/
long Get_File_Size( char * Filename );
long Read_File( char * Filename, char * File_Buffer, long Read_Size );
long Write_File( char * Filename, char * File_Buffer, long Write_Size );
void Add_Path( uint8 * Path, uint8 * Src, uint8 * Dest );
void Get_Ext( uint8 * Src, uint8 * Dest );
void GetFilename( uint8 * Src, uint8 * Dest );
void Change_Ext( uint8 * Src, uint8 * Dest, uint8 * Ext );
long DataPath_Get_File_Size( char * Filename );
long DataPath_Read_File( char * Filename, char * File_Buffer, long Read_Size );
FILE * DataPath_fopen( char * Filename, char * Rights );
void AddCommentToLog( const char * format, ... );
void AddCommentToBat( const char * format, ... );
void AddDataPathFileToBat( char * Filename );
void AddFileToBat( char * Filename );
void AddCommandToBat( const char * format, ... );
BOOL File_Exists( char * Filename );
void FileCheckSum( char *fname );
void DataPath_FileCheckSum( char *fname );
void InitCheckSum( LPGUID lpguid );

#endif // FILE_H

/*
 * The X Men, November 1997
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * Authors: Collinsd, Oliverc, Phillipd
 */
#ifndef LOADSAVE_INCLUDED
#define LOADSAVE_INCLUDED
/*
 * Defines
 */
#define SAVEGAME_SLOTS

#define SAVEGAME_FOLDER         "Savegame"
#define SNAPSHOT_FOLDER         "Screenshots"
#define FMVSNAPSHOT_FOLDER      "Screens"
#define SAVEGAME_EXTENSION      ".SAV"
#define SAVEGAME_FILESPEC       "save??"
#define SAVEGAMEPIC_EXTENSION   ".PPM"

#define LOADSAVE_VERSION_NUMBER 5

/*
 * fn prototypes
 */
void InGameLoad( MENUITEM * MenuItem );
BOOL InGameSave( MENUITEM * MenuItem );
BOOL PreInGameLoad( MENUITEM * MenuItem );
char *SaveGameFileName( int slot );
char *SaveGamePicFileName( int slot );
char *SavedGameInfo( int slot );
char *GetMissionName( char *levelname );
BOOL SaveGameSlotUsed( int slot );
#endif  // LOADSAVE_INCLUDED


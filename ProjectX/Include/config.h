#ifndef CONFIG_H
#define CONFIG_H


#define MAX_PLAYER_NAME_LENGTH	(16)

#define MAX_KEYS_PER_CONTROL	(8)

#define MAX_MOUSE_BUTTONS		(4)

#define MAX_PRIMARY_WEAPONS		(6)
#define MAX_SECONDARY_WEAPONS	(11)

#define MAX_JOYSTICKS			16
#define MAX_JOYSTICK_BUTTONS	128
#define MAX_JOYSTICK_POVS		4
#define MAX_JOYSTICK_AXIS		8
#define MAX_JOYSTICK_TEXT		128
#define MAX_JOYNAME				16	// length of joystick object description, ie. "X Axis"

#define DIK_MOUSE				(0x100)
#define DIK_LBUTTON				(0x100)
#define DIK_RBUTTON				(0x101)
#define DIK_MBUTTON				(0x102)
#define DIK_TBUTTON				(0x103)
#define DIK_WHEELUP				(0x104)
#define DIK_WHEELDOWN			(0x105)

#define DIK_JOYSTICK			(0x200)
#define DIK_JOYSTICK_POV		(0x080)

#define JOYSTICK_BUTTON_KEYCODE( J, B )		( DIK_JOYSTICK | ( ( (J) & 0x0F ) << 12 ) | ( (B) & 0x7F ) )
#define JOYSTICK_POVDIR_KEYCODE( J, P, D )	( DIK_JOYSTICK | DIK_JOYSTICK_POV | ( ( (J) & 0x0F ) << 12 ) | ( ( (P) & 0x03 ) << 2 ) | ( (D) & 0x03 ) )

#define KEY_ON_KEYBOARD( K )				( (K) < DIK_MOUSE )
#define KEY_ON_MOUSE( K )					( (K) & DIK_MOUSE )
#define KEY_ON_JOYSTICK( K )				( (K) & DIK_JOYSTICK )
#define KEY_ON_JOYSTICK_BUTTON( K )			!( (K) & DIK_JOYSTICK_POV )
#define KEY_ON_JOYSTICK_POV( K )			( (K) & DIK_JOYSTICK_POV )

#define KEY_JOYSTICK( K )					( ( (K) >> 12 ) & 0x0F )
#define KEY_JOYSTICK_BUTTON( K )			( (K) & 0x7F )
#define KEY_JOYSTICK_POV( K )				( ( (K) >> 2 ) & 0x03 )
#define KEY_JOYSTICK_POVDIR( K )			( (K) & 0x03 )


#include "typedefs.h"
#include "title.h"


typedef short VirtualKeycode;

#define MAX_KEYNAME_LENGTH 32
typedef struct {
	int keys;
	VirtualKeycode key[MAX_KEYS_PER_CONTROL];
} USERKEY;


typedef struct _DEFKEY
{
	USERKEY *def;
	int selected_key;
} DEFKEY;


typedef struct {
	char *keyword;
	VirtualKeycode keycode;
} VIRTUALKEYMAP;

typedef struct {
	char name[MAX_PLAYER_NAME_LENGTH];
	uint16 bike;
	uint16 bikecomp;
	float mouse_x_sensitivity; // 1.0 is normal
	float mouse_y_sensitivity; // 1.0 is normal
	int invert_pitch; // 0 = no, otherwise yes -> pitch controls reversed
	int invert_turn; // 0 = no, otherwise yes -> roll controls reversed
	float autolevel_rate; // 0 = no, otherwise yes -> ship autolevelling enabled
	USERKEY up;
	USERKEY down;
	USERKEY left;
	USERKEY right;
	USERKEY roll_left;
	USERKEY roll_right;
	USERKEY move_left;
	USERKEY move_right;
	USERKEY move_up;
	USERKEY move_down;
	USERKEY move_forward;
	USERKEY move_backward;
	USERKEY move;
	USERKEY roll;
	USERKEY turbo;
	USERKEY cruise_faster;
	USERKEY cruise_slower;
	USERKEY fire_primary;
	USERKEY fire_secondary;
	USERKEY fire_mine;
	USERKEY select_next_primary;
	USERKEY select_prev_primary;
	USERKEY select_next_secondary;
	USERKEY select_prev_secondary;
	USERKEY full_rear_view;
	USERKEY headlights;
	USERKEY select_primary[MAX_PRIMARY_WEAPONS];
	USERKEY select_secondary[MAX_SECONDARY_WEAPONS];
	USERKEY drop_primary;
	USERKEY drop_secondary;
	USERKEY drop_shield;
	USERKEY drop_ammo;
	USERKEY send_msg;
#ifdef PLAYER_SPEECH_TAUNTS
	USERKEY send_speech;
#endif
	int16 primary_priority[MAX_PRIMARY_WEAPONS];
	int16 primary_order[MAX_PRIMARY_WEAPONS];
	int16 secondary_priority[MAX_SECONDARY_WEAPONS];
	int16 secondary_order[MAX_SECONDARY_WEAPONS];
	char macro1[ MAXTEXTMSG ];
	char macro2[ MAXTEXTMSG ];
	char macro3[ MAXTEXTMSG ];
} USERCONFIG;



extern USERCONFIG default_config;

extern int
read_config( USERCONFIG *u, char *cfg_name );

extern int
write_config( USERCONFIG *u, char *cfg_name );

extern const char *
key_name( int keycode );

extern const char *
key_fullname( int keycode );

#endif // CONFIG_H

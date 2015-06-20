/*
 * The X Men, June 1996
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * $Revision: 422 $
 *
 * $Header: /PcProjectX/Ships.c 422   14/09/98 12:42 Phillipd $
 *
 * $Log: /PcProjectX/Ships.c $
 * 
 * 422   14/09/98 12:42 Phillipd
 * 
 * 421   14/08/98 9:13 Phillipd
 * DirectX6 is in effect.......
 * 
 * 420   7/15/98 9:53a Phillipd
 * 
 * 419   7/10/98 11:26a Phillipd
 * 
 * 418   8/07/98 9:32 Oliverc
 * Converted multiplayer bounty and flag games to server operation for
 * patch
 * 
 * 417   7/06/98 10:12a Phillipd
 * 
 * 416   7/06/98 10:12a Phillipd
 * Ships now convey there Headlights,,,,,,,,Ship_Light
 * 
 * 415   6/30/98 3:01p Phillipd
 * Headlights work....Doh
 * 
 * 414   6/26/98 2:06p Phillipd
 * Shield and hull are now checked by the server.....
 * 
 * 413   26/06/98 10:55 Collinsd
 * Server Pickups and weapons works pretty well, death mode pickups thrown
 * out, as well as scattered.  Quitting/Crash players throw out all
 * pickups.
 * 
 * 412   6/24/98 11:35a Phillipd
 * Server no longer collides with BGObjects...
 * 
 * 411   22/06/98 17:38 Oliverc
 * Removed CD checks in multiplayer games for patch
 * 
 * 410   6/22/98 4:24p Phillipd
 * 
 * 409   6/04/98 3:49p Phillipd
 * Shield and Hull Get saved and restored during minimizeation
 * 
 * 408   6/04/98 3:20p Phillipd
 * 
 * 407   6/04/98 12:29p Phillipd
 * 
 * 406   3/06/98 14:34 Collinsd
 * 
 * 405   3/06/98 14:24 Collinsd
 * 
 * 404   22/05/98 15:06 Collinsd
 * Server Pickup work
 * 
 * 403   21/05/98 9:10 Collinsd
 * Pickup server stuff started
 * 
 * 402   5/20/98 3:15p Phillipd
 * 
 * 401   5/14/98 5:52p Phillipd
 * Fixed a re-spawn bug....Doh
 * 
 * 400   5/14/98 9:53a Phillipd
 * 
 * 399   5/13/98 3:59p Phillipd
 * 
 * 398   5/13/98 11:57a Phillipd
 * 
 * 397   5/13/98 11:21a Phillipd
 * 
 * 396   5/13/98 10:32a Phillipd
 * 
 * 395   5/12/98 3:12p Phillipd
 * 
 * 394   5/12/98 2:59p Phillipd
 * 
 * 393   4/17/98 9:28a Phillipd
 * 
 * 392   15/04/98 12:31 Oliverc
 * In-game text substituted for localised definitions
 * 
 * 391   14/04/98 16:00 Collinsd
 * Check for / framelag when framelag  == 0
 * 
 * 390   11/04/98 17:18 Collinsd
 * Taken out lines
 * 
 * 389   10/04/98 14:34 Collinsd
 * 
 * 388   9/04/98 12:54 Oliverc
 * Fixed a number of glitches in cruise control
 * 
 * 387   4/09/98 11:30a Phillipd
 * 
 * 386   8/04/98 20:26 Collinsd
 * 
 * 385   8/04/98 10:18 Philipy
 * existing underwater ambience is now always killed off b4 starting a new
 * one
 * general phrases no longer played when respawning in multiplayer
 * 
 * 384   4/06/98 3:46p Phillipd
 * 
 * 383   6/04/98 12:45 Collinsd
 * Invul in demos now work
 * 
 * 382   6/04/98 11:29 Philipy
 * added big packets option
 * upped frequency of some speech sfx
 * re-implemented holo-scanline
 * 
 * 381   5/04/98 14:11 Collinsd
 * Harm teammates now harms yourself.
 * 
 * 380   3/04/98 18:10 Collinsd
 * Moved position of xmem.h
 * 
 * 379   2/04/98 21:07 Philipy
 * Added taunts ( single & multiplayer, plus enemy biker taunts )
 * added flygirl to front end.
 * sliders for biker, bike computer and taunt speech volume
 * added new sfx for title
 * 
 * 378   1/04/98 21:11 Oliverc
 * Doubled autolevel rotation tolerance to help SpaceOrb work better
 * 
 * 377   1/04/98 11:44 Collinsd
 * Invulnerability effect now no longer appears in demos. and god mode
 * works properly over multiple levels.
 * 
 * 376   30/03/98 23:39 Oliverc
 * Fixed minor bug in demo eyes select usage in demo playback
 * 
 * 375   27/03/98 17:09 Oliverc
 * replaced old "outside_map => bomb killed you" code with new version
 * that puts you back into your last valid restart position
 * 
 * 374   3/27/98 12:37p Phillipd
 * sfx added
 * 
 * 373   26/03/98 15:29 Oliverc
 * Increased autolevel roll tolerance to allow autoleveling to work with
 * SpaceOrb
 * 
 * 372   24/03/98 16:20 Philipy
 * added new sfx
 * 
 * 371   23/03/98 10:19 Oliverc
 * Added basic CD checking at startup and whenever player respawns
 * 
 * 370   21/03/98 16:19 Philipy
 * changed call to MakeScreenFlash slightly
 * 
 * 369   3/20/98 10:36a Phillipd
 * 
 * 368   19/03/98 14:22 Collinsd
 * Invulnerability effect no longer visible in demo.
 * 
 * 367   3/17/98 10:15a Phillipd
 * 
 * 366   16/03/98 17:19 Collinsd
 * Fixed Crystal & Gold bars
 * 
 * 365   15/03/98 18:56 Philipy
 * fixed floating point divide by zero bug when in pause mode & dividing
 * by zero
 * 
 * 364   14/03/98 18:59 Collinsd
 * Added godmode and made debug mode work even when you change level.
 * 
 * 363   11/03/98 12:04 Oliverc
 * Changed "wait for keypress" to "wait for key release" after death mode
 * Fixed multiple message bug in CTF
 * 
 * 362   3/11/98 11:21a Phillipd
 * 
 * 361   3/10/98 5:04p Phillipd
 * BikeMod now effects all singleplayer bike stats......
 * 
 * 360   3/10/98 12:18p Phillipd
 * 
 * 359   9/03/98 21:43 Oliverc
 * 
 * 358   9/03/98 20:13 Oliverc
 * Changed teleports to orient player's bike consistently using direction
 * and up vector
 * 
 * 357   7/03/98 16:27 Philipy
 * fixed water looping sfx stop bug
 * 
 * 356   6/03/98 15:27 Oliverc
 * Automatically switches to valid player when in demo playback
 * 
 * 355   5/03/98 17:05 Oliverc
 * Fixed 3D panel reappearing after loading game bug (only if not died
 * yet...!)
 * 
 * 354   4/03/98 12:33 Oliverc
 * CTF mode fully enabled
 * 
 * 353   3/03/98 21:00 Oliverc
 * Another CTF attempt
 * 
 * 352   3/03/98 20:34 Oliverc
 * More bug fixes for CTF
 * 
 * 351   3/03/98 17:00 Oliverc
 * New multiplayer CTF mode stuff (1st attempt)
 * 
 * 350   2/03/98 12:10 Oliverc
 * Hidden ".DMO" extension from demo file names
 * and added extra info to .DMO file to specify game type etc
 * 
 * 349   27/02/98 16:31 Oliverc
 * Fixed bug: firing while dieing (also affected FF joystick)
 * 
 * 348   26/02/98 20:52 Philipy
 * underwater looping sfx now stops if you die underwater & regenerate
 * above water
 * 
 * 347   26/02/98 17:33 Collinsd
 * Fixed pickup collision vector.
 * 
 * 346   24/02/98 22:00 Oliverc
 * Tweaks to multiplayer games
 * 
 * 345   24/02/98 16:56 Oliverc
 * 1st attempt at bounty hunt multiplayer game
 * 
 * 344   23/02/98 21:20 Collinsd
 * Optimised Load/Save Functions.
 * 
 * 343   23/02/98 15:31 Philipy
 * implemented single player level timer
 * 
 * 342   23/02/98 10:35 Collinsd
 * Added Ship Load/Save Functions
 * 
 * 341   21/02/98 16:25 Philipy
 * added text messages for capture flag
 * 
 * 340   21/02/98 15:56 Oliverc
 * Added user-definable goal score option and fixed bug in goal scoring
 * when flag appears in goal
 * 
 * 339   20/02/98 19:41 Oliverc
 * 2nd prototype of capture the flag game
 * 
 * 338   20/02/98 12:30 Oliverc
 * Prototype goal load/release/check/display for capture the flag
 * multiplayer
 * 
 * 337   19/02/98 22:00 Collinsd
 * Added flygirl biker.
 * 
 * 336   18/02/98 11:53 Oliverc
 * First feature-complete version of force feedback joystick code
 * 
 * 335   11/02/98 12:57 Philipy
 * Changed PlaySfx calls to use Vol instead of Dist
 * 
 * 334   10/02/98 19:40 Philipy
 * added looping underwater sfx
 * 
 * 333   9/02/98 18:29 Collinsd
 * Fixed damage after death, spinning caused by damage, and passing
 * through mines.
 * 
 * 332   2/02/98 14:41 Collinsd
 * Friendly fire on/off now works in team game.
 * 
 * 331   1/28/98 2:35p Phillipd
 * 
 * 330   1/28/98 2:29p Phillipd
 * 
 * 329   1/27/98 5:31p Phillipd
 * 
 * 328   1/27/98 2:58p Phillipd
 * 
 * 327   1/27/98 12:16p Phillipd
 * Death camera bugs fixed
 * 
 * 326   1/26/98 11:08a Phillipd
 * Couple of Viewport changes taken out...
 * RearView is now i the registry....And disabled for death mode
 * 
 * 325   22/01/98 11:57 Collinsd
 * Added DoDamage override invul.
 * 
 * 324   21/01/98 18:05 Philipy
 * speech now happens less
 * 
 * 323   1/21/98 12:01p Phillipd
 * 
 * 322   1/19/98 9:41a Phillipd
 * 
 * 321   18/01/98 23:43 Philipy
 * added sfx for pain cries, shield & hull critical
 * 
 * 320   1/17/98 4:02p Phillipd
 * 
 * 319   1/17/98 3:02p Phillipd
 * 
 * 318   15/01/98 12:51 Collinsd
 * Time now works when people join an existing timed game.  Crystals
 * reinitialised.  Damage Flash only in Normal_Mode.
 * 
 * 317   1/13/98 10:05a Phillipd
 * 
 * 316   1/12/98 11:59a Phillipd
 * 
 * 315   10/01/98 15:55 Collinsd
 * ScreenFlashed moved to dodamage.
 * 
 * 314   1/09/98 12:12p Phillipd
 * 
 * 313   8/01/98 17:15 Oliverc
 * Fixed potential bug in Nitrofuel check
 * 
 * 312   1/07/98 9:24a Phillipd
 * Lives now done the way Shawn wants.....
 * 
 * 311   1/06/98 10:01a Phillipd
 * 
 * 310   1/05/98 5:23p Phillipd
 * 
 * 309   1/05/98 3:18p Phillipd
 * More sfx...
 * 
 * 308   1/05/98 10:06a Phillipd
 * 
 * 307   1/02/98 11:13a Phillipd
 * 
 * 306   12/31/97 9:19a Phillipd
 * 
 * 305   12/30/97 10:44a Phillipd
 * Ship2Ship changed....
 * 
 * 304   12/29/97 11:18a Phillipd
 * 
 * 303   12/23/97 10:24a Phillipd
 * 
 * 302   12/22/97 2:01p Phillipd
 * 
 * 301   19/12/97 17:24 Collinsd
 * DoDamage does no damage in debug mode.
 * 
 * 300   12/19/97 12:36p Phillipd
 * 
 * 299   12/19/97 11:14a Phillipd
 * 
 * 298   12/18/97 5:37p Phillipd
 * 
 * 297   12/18/97 2:47p Phillipd
 * 
 * 296   18/12/97 11:31 Collinsd
 * Added Restart Points, Changed Oneoff anim to only activate if not
 * already animating.
 * 
 * 295   12/13/97 2:17p Phillipd
 * 
 * 294   11/12/97 17:08 Oliverc
 * 
 * 293   11/12/97 15:53 Collinsd
 * Fixed enemy mines that didn't hurt you.  Also fixed enemy homing
 * missile.
 * 
 * 292   12/09/97 3:59p Phillipd
 * Bug fixed for interpolation between groups and firing......caused
 * lines...
 * 
 * 291   9/12/97 10:45 Collinsd
 * Done ship burning and change body parts and pickups now explode in
 * direction of ship movement.
 * 
 * 290   6/12/97 19:32 Oliverc
 * 1st attempt at multi-ray collisions with sliding (currently disabled)
 * 
 * 289   6/12/97 19:22 Collinsd
 * Added burning effect on deathmode.
 * 
 * 288   12/06/97 2:53p Phillipd
 * Fixed Phils Sfx Crash Bug....Doh
 * 
 * 287   5/12/97 17:47 Oliverc
 * outside_map flag now uses BSP rather than bounding box check
 * 
 * 286   12/05/97 5:15p Phillipd
 * 
 * 285   12/05/97 2:16p Phillipd
 * 
 * 284   5/12/97 14:11 Collinsd
 * Allocated ships fixed.
 * 
 * 283   12/05/97 9:36a Phillipd
 * 
 * 282   12/04/97 4:55p Phillipd
 * 
 * 281   4/12/97 15:12 Collinsd
 * Ships are now allocated models.
 * 
 * 280   12/03/97 4:37p Phillipd
 * 
 * 279   27/11/97 12:35 Oliverc
 * Added check to put player's ship back inside the map when in debug mode
 * 
 * 278   11/27/97 10:39a Phillipd
 * 
 * 277   11/26/97 4:47p Phillipd
 * NodeArray now dynamically allocated....
 * 
 * 276   11/26/97 3:07p Phillipd
 * 
 * 275   26/11/97 11:48 Philipy
 * implemented dynamic loading of SFX, dynamic allocation of mixing
 * channels.
 * 3D sound currently disabled.
 * 
 * 274   10/11/97 19:20 Collinsd
 * Totally cloaked flag added
 * 
 * 273   11/06/97 2:08p Phillipd
 * 
 * 272   11/05/97 4:47p Phillipd
 * 
 * 271   11/04/97 5:15p Phillipd
 * 
 * 270   11/01/97 1:43p Phillipd
 * 
 * 269   10/31/97 12:28p Phillipd
 * 
 * 268   10/30/97 12:40p Phillipd
 * 
 * 267   10/30/97 9:30a Phillipd
 * Bikes with different mods started...
 * 
 * 266   10/24/97 5:05p Phillipd
 * Enemies version 2....
 * 
 * 265   10/21/97 5:07p Phillipd
 * 
 * 264   10/17/97 11:48a Phillipd
 * 
 * 263   10/14/97 4:48p Phillipd
 * 
 * 262   10/09/97 3:29p Phillipd
 * External forces coming...
 * Shield and Hull now floats
 * 
 * 261   10/07/97 10:18a Phillipd
 * 
 * 260   4/10/97 15:58 Collinsd
 * Added new spiraling missile and took out old morph code.
 * 
 * 259   10/04/97 12:10p Phillipd
 * 
 * 258   24/09/97 16:55 Collinsd
 * Added new bgobject stuff.  Added bounding box calc and display code.
 * and changes bgobject state changes.
 * 
 * 257   9/19/97 11:47a Phillipd
 * 
 * 256   9/19/97 9:48a Phillipd
 * Lives are now included in single player.....
 * 
 * 255   9/18/97 12:16p Phillipd
 * 
 * 254   9/18/97 9:42a Phillipd
 * Proper single player started..
 * 
 * 253   9/16/97 4:38p Phillipd
 * 
 * 252   16/09/97 16:25 Oliverc
 * 1st attempt at new multiple-ray/single bounce object collision system
 * 
 * 251   9/16/97 2:44p Phillipd
 * 
 * 250   2/09/97 10:31 Oliverc
 * Added first attempt at MULTI_RAY_COLLISION for ships (currently
 * disabled)
 * 
 * 249   8/27/97 2:14p Phillipd
 * 
 * 248   8/27/97 9:20a Phillipd
 * 
 * 247   6/08/97 19:21 Collinsd
 * Changed external/internal forces. Commented out some more A3D Sfx stuff
 * 
 * 246   8/06/97 3:48p Phillipd
 * 
 * 245   8/06/97 9:35a Phillipd
 * 
 * 244   28/07/97 16:44 Collinsd
 * Tracker uses ships to target, demo mode works again?
 * 
 * 243   25/07/97 12:10 Collinsd
 * Changed ships bike index, and changed skin for olly.
 * 
 * 242   17/07/97 16:06 Oliverc
 * Added ship cruise control keys
 * 
 * 241   17/07/97 15:38 Collinsd
 * BGObjects now use compobjs.
 * 
 * 240   7/14/97 5:07p Phillipd
 * 
 * 239   7/12/97 3:34p Phillipd
 * 
 * 238   7/10/97 11:35a Phillipd
 * 
 * 237   7/09/97 3:13p Phillipd
 * Ambient Light version 1
 * 
 * 236   8/07/97 16:30 Collinsd
 * Dicked about with include files FUCK!
 * 
 * 235   5/07/97 16:31 Collinsd
 * Put OPT_ON's around opimisations off
 * 
 * 234   7/03/97 5:27p Phillipd
 * 
 * 233   7/03/97 10:11a Phillipd
 * More Ai and node
 * 
 * 232   6/30/97 10:27a Phillipd
 * enemy ai started....
 * 
 * 231   6/24/97 5:11p Phillipd
 * 
 * 230   6/24/97 11:12a Phillipd
 * 
 * 229   6/18/97 12:15p Phillipd
 * 
 * 228   6/17/97 4:03p Phillipd
 * 
 * 227   6/17/97 9:20a Phillipd
 * 
 * 226   6/16/97 4:15p Phillipd
 * 
 * 225   6/07/97 10:52a Phillipd
 * 
 * 224   4/06/97 11:12 Collinsd
 * Added message sending for doors.
 * 
 * 223   6/03/97 10:47a Phillipd
 * 
 * 222   5/15/97 11:42a Phillipd
 * 
 * 221   26/04/97 14:49 Collinsd
 * Optimisations now on def.
 * 
 * 220   4/25/97 10:36a Phillipd
 * Better demo playback...which player eyes works again
 * 
 * 219   4/24/97 5:22p Phillipd
 * 
 * 218   22-04-97 3:25p Collinsd
 * Added player flying out of bilke.
 * 
 * 217   4/19/97 3:44p Phillipd
 * 
 * 216   4/19/97 1:44p Phillipd
 * 
 * 215   4/19/97 1:23p Phillipd
 * Only Ships Dont collide when no_collisions is set...
 * Trigger areas work better.....
 * 
 * 214   16-04-97 4:38p Collinsd
 * Added reflecting bullets for all weapons except laser.
 * Cheat mode now has invul effect.
 * 
 * 213   10-04-97 11:32a Collinsd
 * Invulnerability can now be seen from external view.
 * 
 * 212   9-04-97 8:51a Collinsd
 * Added invulnerability
 * 
 * 211   7-04-97 3:34p Collinsd
 * Added supernashram powerup.
 * 
 * 210   4/05/97 12:08p Phillipd
 * 
 * 209   4/02/97 8:51a Phillipd
 * Bsps enabled...
 * 
 * 208   24-03-97 3:55p Collinsd
 * Updated Lajay, Excop and added rhesus...
 * 
 * 207   3/21/97 4:19p Phillipd
 * 
 * 206   3/20/97 12:23p Phillipd
 * Init Sound is only called once as is destroysound...
 * 
 * 205   3/19/97 3:34p Phillipd
 * Added Invulnerable flag and timer....gets sent across network...
 * 
 * 204   3/13/97 11:28a Phillipd
 * Auto Detail level added..
 * Text all one colour unless printing own name...
 * 
 * 203   3/13/97 9:50a Phillipd
 * 
 * 202   3/12/97 4:42p Phillipd
 * 
 * 201   3/11/97 4:55p Phillipd
 * Demo Interpolate stuff is now working but not finished...
 * 
 * 200   3/10/97 9:53a Phillipd
 * 
 * 199   5-03-97 10:49a Collinsd
 * 
 * 198   2/27/97 3:06p Phillipd
 * 
 * 197   2/27/97 2:41p Phillipd
 * 
 * 196   27-02-97 2:08p Collinsd
 * Added optimisation to various files.
 * 
 * 195   2/25/97 12:32p Phillipd
 * rotation interpilation...
 * 
 * 194   2/24/97 5:05p Phillipd
 * 
 * 193   2/24/97 12:17p Phillipd
 * 
 * 192   24-02-97 11:21a Collinsd
 * Added gravgon check for restart. and added bounding on object selection
 * depending on mode.
 * 
 * 191   2/24/97 10:36a Phillipd
 * 
 * 190   2/24/97 10:00a Phillipd
 * Demo mode with multispeed has been added..
 * 
 * 189   13/02/97 18:00 Oliverc
 * Fixed bug in whole level display when outside map
 * 
 * 188   2/13/97 5:25p Phillipd
 * 
 * 187   2/13/97 3:29p Phillipd
 * 
 * 186   2/13/97 9:42a Phillipd
 * 
 * 185   7/02/97 9:42 Oliverc
 * Changed setting of initial ship start position to use group up vector
 * rather than ship up vector (to eliminate startup autolevelling roll)
 * 
 * 184   5-02-97 3:00p Collinsd
 * Just got rid of warnings.
 * 
 * 183   4-02-97 4:29p Collinsd
 * 
 * 182   2/03/97 5:16p Phillipd
 * Translusceny is now controlled by global execute buffers.... which is
 * much better...
 * 
 * 181   31/01/97 14:50 Oliverc
 * Added per-group gravity/up vector
 * 
 * 180   1/31/97 10:51a Phillipd
 * 
 * 179   1/31/97 9:10a Phillipd
 * 
 * 178   30-01-97 3:58p Collinsd
 * 
 * 177   1/24/97 9:19a Phillipd
 * 
 * 176   1/23/97 11:36a Phillipd
 * now slide doesnt slide you less than the fudge factor..
 * 
 * 175   1/23/97 10:03a Phillipd
 * debug remote camera no collide..
 * 
 * 174   1/23/97 9:37a Phillipd
 * New Bsp collsions v1.0
 * 
 * 173   1/22/97 2:24p Phillipd
 * 
 * 172   15-01-97 11:15a Collinsd
 * Crushing Doors now work properly.
 * 
 * 171   14-01-97 12:54p Collinsd
 * BGObject Type are now saved as well
 * 
 * 170   1/14/97 11:00a Phillipd
 * Changed internal and external forces....
 * 
 * 169   13-01-97 5:03p Collinsd
 * Added Temp Door SFX
 * 
 * 168   13-01-97 12:19p Collinsd
 * Doors now cannot be opened by various rays.
 * 
 * 167   10-01-97 3:54p Collinsd
 * Missile/Primary weapons no longer open doors before collision.
 * 
 * 166   3-01-97 3:28p Collinsd
 * Added xxx quantum/pine/purged mined xxx messages.
 * Trojax charging sfx on others pc's now fixed.
 * 
 * 165   31-12-96 12:35p Collinsd
 * Added multiple multiples.
 * 
 * 164   12/27/96 3:38p Phillipd
 * Primary.h Secondary.h pickups.h are now clean....
 * Still Lots to do though.....
 * 
 * 163   12/27/96 12:34p Phillipd
 * all files are not dependant on mydplay.h...just some..
 * including it several times in the same files didnt help..
 * 
 * 162   12/23/96 6:04p Phillipd
 * 
 * 161   20-12-96 5:06p Collinsd
 * Added debug weapon feature.
 * 
 * 160   20/12/96 15:19 Oliverc
 * Changed debug menu to be on SHIFT-F1
 * 
 * 159   20-12-96 8:34a Collinsd
 * Changed hilight of bike when charging.
 * 
 * 158   19/12/96 16:17 Oliverc
 * Added debug options menu with "go to room" function
 * 
 * 157   19-12-96 4:16p Collinsd
 * Ha ha
 * 
 * 156   19-12-96 3:19p Collinsd
 * Changed sfx funtion to allow frequency changing.
 * Added Trojax Charging SFX.
 * 
 * 155   12/17/96 12:55p Phillipd
 * 
 * 154   12/16/96 5:48p Collinsd
 * Uses various flags set in menus
 * 
 * 153   12/14/96 10:44p Collinsd
 * When someone quits the game all pickups scattered. and dissapear under
 * host control.
 * 
 * 152   12/13/96 10:57a Phillipd
 * Random startpos better....
 * 
 * 151   12/10/96 11:28a Collinsd
 * Added MAXCOLLISIONS #define at top of ships.c
 * 
 * 150   12/09/96 5:25p Collinsd
 * Started smoke when hull damaged ( still need positions )
 * 
 * 149   12/07/96 8:43p Collinsd
 * Added Jap Bird bike, Fixed mines being dropped and firing missile at
 * same time bug.  Added rotations when hit ( depending on damage ).
 * 
 * 148   12/06/96 9:13a Phillipd
 * More simplified panel stuff
 * 
 * 147   12/02/96 1:25p Collinsd
 * No longer use quatfromvector routines.  now use
 * quatfrom2vectors.
 * 
 * 146   2/12/96 11:21 Oliverc
 * Corrected twist angle for bike startpoints (but still some problems
 * with QuatFrom Vector(2) functions)
 * 
 * 145   29/11/96 14:20 Oliverc
 * Added ship rotation force functions
 * 
 * 144   29/11/96 12:24 Oliverc
 * 
 * 143   28/11/96 15:56 Oliverc
 * 
 * 142   11/28/96 3:39p Phillipd
 * Slight error when 2 ships are 0 length apart
 * 
 * 141   11/28/96 3:32p Phillipd
 * Better Multiplayer Starting...
 * 
 * 140   28/11/96 11:42 Oliverc
 * 
 * 139   27/11/96 14:07 Oliverc
 * 
 * 138   11/25/96 11:59a Phillipd
 * 
 * 137   11/22/96 5:10p Phillipd
 * 
 * 136   11/22/96 2:09p Phillipd
 * 
 * 135   11/22/96 12:54p Phillipd
 * 
 * 134   11/22/96 12:27p Phillipd
 * more stuff is checked to make sure someone joining cant be hurt..
 * 
 * 133   22/11/96 9:20 Collinsd
 * Changed max collides to 4.
 * 
 * 132   11/21/96 2:37p Phillipd
 * 
 * 131   11/13/96 9:08a Phillipd
 * All the Menus in the world....And then Some
 * 
 * 130   7/11/96 10:47 Collinsd
 * Shortened short ships structures.
 * 
 * 129   11/07/96 10:47a Phillipd
 * 
 * 128   5/11/96 17:16 Collinsd
 * hopefully fixed stealth from generating too many times.
 * 
 * 127   4/11/96 10:45 Oliverc
 * Changed display routines to clip to visible portal boundaries of each
 * group
 * 
 * 126   1/11/96 17:52 Collinsd
 * Reduced ship/shortship structure size by using bits.
 * 
 * 125   30/10/96 16:21 Collinsd
 * stealth sfx and regeneration
 * 
 * 124   30/10/96 14:34 Collinsd
 * Added stealthmode.
 * 
 * 123   10/29/96 5:38p Phillipd
 * Any key restarts after death..
 * 
 * 122   10/23/96 4:24p Phillipd
 * Lots of crap taken out of D3dapp and its associated functions and
 * files....
 * 
 * 121   22/10/96 12:08 Collinsd
 * Added body parts and blood splats.
 * 
 * 120   19/10/96 20:50 Collinsd
 * Changed scatter/thief to give more chance for enemy to pickup up
 * scattered weapons.
 * Reduced thief homing.  Increased Heatseaker.
 * Lights now can be enabled and disabled properly.
 * started on flying body parts.  Plus lots more..... 
 * 
 * 119   10/17/96 4:43p Phillipd
 * proper score sort....dont work on stats yet...
 * 
 * 118   10/16/96 3:11p Phillipd
 * 
 * 117   10/16/96 9:06a Phillipd
 * 
 * 116   10/15/96 3:33p Phillipd
 * camera have a void * to identify owner...
 * Ships now regenerate in a rendom but safe if possible pos..
 * 
 * 115   15/10/96 12:32 Collinsd
 * Added directional light to quantum fireball.  Changed ammo, so none are
 * generated if there are no weapons that use them.
 * 
 * 114   10/15/96 10:42a Phillipd
 * Added Spot Lights....
 * 
 * 113   10/14/96 2:41p Phillipd
 * Directional Lights are there...allmost
 * 
 * 112   8/10/96 14:34 Oliverc
 * New bob mechanism implemented (with anti-drift compensation...)
 * 
 * 111   6/10/96 17:04 Collinsd
 * Nitro regeneration better.
 * 
 * 110   10/04/96 3:35p Phillipd
 * ships now dont slip through the floor if no packet gets through
 * 
 * 109   10/04/96 2:53p Phillipd
 * 
 * 108   10/04/96 2:48p Phillipd
 * 
 * 107   10/04/96 10:56a Phillipd
 * 
 * 106   10/04/96 10:51a Phillipd
 * 
 * 105   4/10/96 10:23 Oliverc
 * Added LastMove vector to ship
 * 
 * 104   10/04/96 10:16a Phillipd
 * 
 * 103   10/04/96 9:43a Phillipd
 * 
 * 102   3/10/96 15:49 Collinsd
 * Added new sfx
 * 
 * 101   3/10/96 14:04 Collinsd
 * Added nitro limit.
 * 
 * 100   2/10/96 18:04 Collinsd
 * Fixed pickup messages when you already have something.  Collision now
 * uses ray to sphere 2.
 * 
 * 99    29/09/96 18:47 Collinsd
 * Added turbo to ship structure. Fixed pine mine firing pos.
 * 
 * 98    9/26/96 11:21a Phillipd
 * MX load is now operational...
 * 
 * 97    9/25/96 5:53p Phillipd
 * added Simplified Models......And Bike Detail Level now
 * works..
 * 
 * 96    20/09/96 17:13 Collinsd
 * Changed 2Dpolys and Polys to display only polys in visible groups.
 * Changed secondary ammo to use array.
 * Pickups now use correct index's.  You can now drop a mine using 'B'.
 * 
 * 95    9/18/96 3:59p Phillipd
 * 
 * 94    9/17/96 5:02p Phillipd
 * 
 * 93    9/17/96 4:40p Phillipd
 * 
 * 92    9/17/96 4:36p Phillipd
 * 
 * 91    9/17/96 4:18p Phillipd
 * Limbo Mode added.....Dont do anything to the ship...
 * 
 * 90    9/17/96 3:55p Phillipd
 * 
 * 89    9/17/96 3:37p Phillipd
 * 
 * 88    17/09/96 15:34 Collinsd
 * Shockwaves added. and fixed primary previous.
 * 
 * 87    16/09/96 18:57 Oliverc
 * Ships now start in different positions when changing level in
 * multiplayer game
 * 
 * 86    16/09/96 15:20 Oliverc
 * Changed autolevelling to be properly framelagged
 * and added ship bobbing
 * 
 * 85    16/09/96 9:25 Collinsd
 * Added regenerating pickups.
 * 
 * 84    9/15/96 3:43p Phillipd
 * 
 * 83    9/15/96 11:49a Phillipd
 * 
 * 82    14/09/96 21:28 Oliverc
 * Added basic ship auto-levelling (incl config file setting) but not made
 * it frame lagged properly
 * 
 * 81    9/14/96 4:35p Phillipd
 * Fixed death Cam for Suicide...
 * 
 * 80    9/14/96 4:31p Phillipd
 * 
 * 79    14/09/96 16:25 Collinsd
 * Added shockwave to ship death.
 * 
 * 78    14/09/96 15:40 Collinsd
 * Added shield to mines, and damage to missiles.
 * Also when you die your weapons and ammo are dropped
 * 
 * 77    9/13/96 4:46p Phillipd
 * 
 * 76    9/12/96 9:04a Phillipd
 * More Death, Remote Camera Stuff
 * 
 * 75    9/11/96 2:01p Phillipd
 * 
 * 74    9/11/96 10:30a Phillipd
 * 
 * 73    9/11/96 10:25a Phillipd
 * 
 * 72    10/09/96 16:33 Oliverc
 * Added external/internal force vector to ship movement
 * 
 * 71    9/10/96 3:39p Phillipd
 * 
 * 70    9/10/96 12:54p Phillipd
 * 
 * 69    9/10/96 9:00a Phillipd
 * 
 * 68    9/09/96 11:23a Phillipd
 * 
 * 67    9/09/96 9:14 Oliverc
 * 
 * 66    9/05/96 4:47p Phillipd
 * 
 * 65    5/09/96 9:33 Oliverc
 * 
 * 64    5/09/96 9:27 Oliverc
 * Modified ship-to-background collision routines to work with new
 * collision skins
 * 
 * 63    27/08/96 9:02 Collinsd
 * Added some new pickups and messages.
 * 
 * 62    8/23/96 2:54p Phillipd
 * 
 * 61    8/23/96 2:41p Phillipd
 * 
 * 60    8/23/96 11:10a Phillipd
 * 
 * 59    23/08/96 9:18 Collinsd
 * All weapons have limits. New pickups in but not correct.
 * 
 * 58    8/21/96 5:49p Phillipd
 * 
 * 57    8/21/96 10:12a Phillipd
 * fixed death view cam bug...
 * 
 * 56    8/15/96 4:46p Phillipd
 * 
 * 55    13/08/96 14:57 Collinsd
 * Now prints strings to tell you what you've  picked up.
 * 
 * 54    8/13/96 2:43p Phillipd
 * 
 * 53    13/08/96 12:49 Collinsd
 * Working on primary weapons
 * 
 * 52    8/13/96 10:15a Phillipd
 * Player name and score now given to everyone for printing....4x5 print
 * routine and uint16 printing
 * 
 * 51    8/08/96 5:39p Phillipd
 * 
 * 50    8/08/96 9:13 Collinsd
 * Added Sfx and pickups
 * 
 * 49    8/08/96 8:48a Phillipd
 * 
 * 48    8/07/96 10:59a Phillipd
 * 
 * 47    8/07/96 10:49a Phillipd
 * 
 * 46    7/08/96 10:32 Collinsd
 * Added pickup collision with background
 * 
 * 45    6/08/96 12:39 Collinsd
 * You can now pickup pickups. added 2 new models
 * 
 * 44    8/05/96 5:53p Phillipd
 * 
 * 43    5/08/96 12:52 Oliverc
 * 
 * 42    8/03/96 4:39p Phillipd
 * all Models can be env mapped..
 * Alpha texture formats are detected and reported...
 * But cant load a system Alpha texture into a Video Alpha Texture!!
 * 
 * 41    8/02/96 5:41p Phillipd
 * 
 * 40    7/31/96 4:05p Phillipd
 * 
 * 39    7/30/96 5:45p Phillipd
 * 
 * 38    7/29/96 4:43p Phillipd
 * 
 * 37    7/29/96 11:25a Phillipd
 * 
 * 36    26/07/96 18:08 Oliverc
 * Disabled ship speed clamping
 * 
 * 35    7/26/96 2:41p Phillipd
 * 
 * 34    7/26/96 11:46a Phillipd
 * 
 * 33    26/07/96 9:07 Oliverc
 * Added turbo boost to ship controls
 * 
 * 32    7/25/96 5:38p Phillipd
 * 
 * 31    7/24/96 5:05p Phillipd
 * 
 * 30    7/24/96 4:26p Phillipd
 * 
 * 29    7/24/96 9:51a Phillipd
 * 
 * 28    7/22/96 3:51p Phillipd
 * 
 * 27    19/07/96 12:34 Oliverc
 * Changed ship <-> background collision routine
 * to track movement of ship through portals
 * 
 * 26    7/16/96 11:11a Phillipd
 * moved all visipoly stuff to visi.c and visi.h..
 * 
 * 25    7/16/96 9:36a Phillipd
 * 
 * 24    7/11/96 4:27p Phillipd
 * 
 * 23    11/07/96 14:35 Oliverc
 * 
 * 22    11/07/96 14:35 Oliverc
 * 
 * 21    7/11/96 12:18p Phillipd
 * 
 * 20    7/10/96 5:10p Phillipd
 * 
 * 19    7/08/96 9:43a Phillipd
 * 
 * 18    6/07/96 16:36 Oliverc
 * 
 * 17    7/06/96 4:13p Phillipd
 * 
 * 16    7/06/96 2:58p Phillipd
 * Ships now use Quats...
 * 
 * 15    4/07/96 16:54 Collinsd
 * 
 * 14    4/07/96 16:42 Oliverc
 * Separated out keyboard and mouse control reading
 * from ship control; added user-defined controls
 * 
 * 13    4/07/96 16:11 Oliverc
 * 
 * 12    2/07/96 16:50 Oliverc
 * 
 * 11    2/07/96 15:45 Oliverc
 * 
 * 10    27/06/96 12:59 Oliverc
 * 
 * 9     6/27/96 12:27p Phillipd
 * 
 * 8     6/27/96 9:40a Phillipd
 * Major rearange of ships and oct2....
 * 
 * 7     6/26/96 3:55p Phillipd
 * 
 * 6     6/26/96 12:20p Phillipd
 * 
 * 5     6/25/96 5:13p Phillipd
 * 
 * 4     6/25/96 4:42p Phillipd
 * 
 * 3     6/25/96 3:15p Phillipd
 * 
 * 2     6/25/96 11:37a Phillipd
 * First SS update
 * 
 */

/*�������������������������������������������������������������������
		Include File...	
�������������������������������������������������������������������*/
#include <stdio.h>
#include "main.h"
#include "typedefs.h"
#include <dplay.h>
#include "new3d.h"
#include "quat.h"
#include "CompObjects.h"
#include "bgobjects.h"
#include "Object.h"
#include "mydplay.h"

#include "config.h"
#include "controls.h"

#include "Ships.h"

#include "triggers.h"
#include "pickups.h"
#include "primary.h"
#include "secondary.h"

#include "Mxaload.h"
#include "lights.h"

#include "sphere.h"

#include "title.h"
#include "TrigArea.h"

#include "Node.h"
#include "Models.h"
#include "Enemies.h"
#include "ExtForce.h"
#include "Teleport.h"
#include "water.h"
#include "spotfx.h"
#include "screenpolys.h"
#include "restart.h"

#include "feedback.h"
#include "goal.h"
#include "visi.h"
#include "text.h"
#include "xmem.h"

#include "local.h"


//#undef MULTI_RAY_COLLISION
//#define MULTI_RAY_SLIDE
#undef MULTI_RAY_SLIDE

#ifdef OPT_ON
#pragma optimize( "gty", on )
#endif


#define	RGENINVULTIME 60.0F

#define FRAMES_PER_SEC	(60.0F)

#define BOB_XSIZE		(30.0F * GLOBAL_SCALE)
#define BOB_YSIZE		(10.0F * GLOBAL_SCALE)
#define BOB_XPERIOD		(2.0F * FRAMES_PER_SEC)
#define BOB_YPERIOD		(1.0F * FRAMES_PER_SEC)
#define BOB_XFREQ		(2.0F * PI / BOB_XPERIOD)
#define BOB_YFREQ		(2.0F * PI / BOB_YPERIOD)


BOOL ObjectCollide( OBJECT *Obj, VECTOR *Move_Off, float radius, BGOBJECT **BGObject );
BOOL ObjectCollideOnly( OBJECT *Obj, VECTOR *Move_Off, float radius, VECTOR *Target_Off, BGOBJECT **BGObject );
BOOL Ship2ShipCollide( uint16 i , VECTOR * Move_Off );
BOOL CarryonDeathMove( GLOBALSHIP * ShipPnt,BYTE i);

BOOL	IsStartPosVacant( int16 i , uint16 startpos );
extern void DebugPrintf( const char * format, ... );
void AddMessageToQue( char * Text, ... );
void SpecialDestroyGame( void );
void MultiSfxHandle( void );

/*�������������������������������������������������������������������
		Externals ...
�������������������������������������������������������������������*/
extern	BOOL IsServerGame;
extern	BOOL IsServer;
extern SLIDER BikeCompSpeechSlider;
extern int ValidCD( void );
extern BOOL SeriousError;

extern float LevelTimeTaken;
extern	BOOL			CaptureTheFlag;
extern	BOOL			CTF;
extern	BOOL			BountyHunt;
extern BOOL	NeedFlagAtHome;
extern int8 TeamFlagPickup[ MAX_TEAMS ];
extern uint16	FlashScreenPoly;

BOOL TeamFlagAtHome[ MAX_TEAMS ];
uint32 TeamFlagMask[ MAX_TEAMS ] = {
	SHIP_CarryingFlag1,
	SHIP_CarryingFlag2,
	SHIP_CarryingFlag3,
	SHIP_CarryingFlag4,
};

extern int GoalScore;
extern int16 PickupsGot[ MAXPICKUPTYPES ];
extern int FlagsToGenerate;
extern char *TeamName[ MAX_TEAMS ];

extern BOOL	bSoundEnabled;

extern	BOOL ShowNode;
extern BOOL    A3DCapable;
extern	int16	SelectedBike;
extern uint16	num_start_positions;
extern uint16	last_start_position;
extern GAMESTARTPOS		StartPositions[MAXSTARTPOSITIONS];			// pos and group info...

extern	int16					Stats[MAX_PLAYERS+1][MAX_PLAYERS+1];

extern	int16					Lives;

extern	BOOL	BombTag;

extern int  no_collision;
extern	XLIGHT	XLights[MAXXLIGHTS];
extern	BOOL	flush_input;
extern BOOL	E3DemoHost;
extern BOOL	E3DemoClient;
extern	LONGLONG	Freq;


extern	MATRIX TempMatrix;
extern USERCONFIG *player_config;
extern char MyName[];
extern char NickName[];

extern	MLOADHEADER ModelHeaders[MAXMODELHEADERS];
extern	MXALOADHEADER MxaModelHeaders[MAXMXAMODELHEADERS];

extern	BOOL	DebugInfo;
extern	BOOL	GodMode;

extern MLOADHEADER Mloadheader;
extern MCLOADHEADER MCloadheader;
extern MCLOADHEADER MCloadheadert0;

extern	BYTE					Current_Camera_View;		// which object is currently using the camera view....
extern	BYTE                    WhoIAm;
extern	GLOBALSHIP              Ships[MAX_PLAYERS];

extern	D3DMATRIXHANDLE hView;
extern	D3DMATRIX view;
extern	D3DMATRIX identity;
extern	MATRIX	MATRIX_Identity;
extern	D3DMATRIXHANDLE hWorld;
extern	LPDIRECT3DDEVICE lpDev;
extern	VECTOR	SlideRight;
extern	VECTOR	SlideUp;
extern	VECTOR	Forward;
extern	float	framelag;  
extern	float	avgframelag;  
extern	BOOL	AutoDetail;  
extern	float	Oldframelag;  
extern	float	Demoframelag;  
extern	SLIDER	DemoEyesSelect;
extern	LONGLONG	GameElapsedTime;

extern	volatile DWORD	XTimer;

extern	PICKUP	Pickups[ MAXPICKUPS ];
extern	uint16	FirstPickupUsed;
extern	float	PickupMessageCount;
extern	int16	PickupMessageIndex;
extern	BOOL	RemoteCameraActive;
extern	uint16	RandomStartPosModify;

BOOL	ResizeViewport( float scale );
extern	float	CurrentViewportScale;
BOOL	FullScreenViewport();
extern	BOOL	DrawPanel;
extern	BOOL	OldDrawPanel;
extern	uint16 IsGroupVisible[MAXGROUPS];
extern	int16	NumStealths;
extern	int16	NumInvuls;
extern	BOOL	GoreGuts;
extern	float	GeneralAmmo;
extern	float	PowerLevel;

extern	BYTE	GameStatus[MAX_PLAYERS];	// Game Status for every Ship...
											// this tells the drones what status the host thinks hes in..

extern	int		outside_group;
extern	BOOL	DemoScreenGrab;
extern	BOOL	PickupInvulnerability;
extern	BOOL	Sound3D;

extern	int16	BikeModels[ MAXBIKETYPES ];

extern	BOOL	TeamGame;
extern	BYTE	TeamNumber[MAX_PLAYERS];
extern	BOOL	HarmTeamMates;
extern	int		CrystalsFound;
extern	int16	NumGoldBars;
extern	uint16	FirstStartPositionInGroup[MAXGROUPS];
extern	BOOL		JustGenerated;
extern	BOOL		JustPickedUpShield;


/*�������������������������������������������������������������������
		Bike Modifiers.....
�������������������������������������������������������������������*/
float	MaxMoveSpeed	=	MAXMOVESPEED;
float	MoveAccell		=	MOVEACCELL;		
float	MoveDecell		=	MOVEDECELL;		
float	MaxTurboSpeed   =	MAXTURBOSPEED;   
float	TurboAccell		=	TURBOACCELL;		
float	TurboDecell		=	TURBODECELL;		
float	MaxTurnSpeed	=	MAXTURNSPEED;	
float	TurnAccell		=	TURNACCELL;		
float	TurnDecell		=	TURNDECELL;		
float	MaxRollSpeed	=	MAXROLLSPEED;	
float	RollAccell		=	ROLLACCELL;		
float	RollDecell		=	ROLLDECELL;		
float	MaxBankAngle    =	MAXBANKANGLE;    
float	BankAccell		=	BANKACCELL;		
float	BankDecell		=	BANKDECELL;		
float	Start_Shield	=	START_SHIELD;
float	Start_Hull		=	START_HULL;
float	AutoLevel		=	1.0F;

#define	BikeMod  (2.0F)

BIKEMOD	BikeMods[MAXBIKETYPES+3] = {
	{	// Default
		MAXMOVESPEED, 
		MOVEACCELL,	
		MOVEDECELL,	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED,
		TURNACCELL,	
		TURNDECELL,	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,
		START_SHIELD,
		START_HULL,
		1.0F
	},
	{	// In The Water...
		MAXMOVESPEED * 0.75F, 
		MOVEACCELL * 0.50F,	
		MOVEDECELL * 0.5F,	
		MAXTURBOSPEED * 0.75F,
		TURBOACCELL * 0.5F,
		TURBODECELL * 0.5F,
		MAXTURNSPEED * 0.5F,
		TURNACCELL * 0.5F,	
		TURNDECELL * 0.5F,	
		MAXROLLSPEED * 0.5F,
		ROLLACCELL * 0.5F,	
		ROLLDECELL * 0.5F,	
		MAXBANKANGLE, 
		BANKACCELL * 1.0F,	
		BANKDECELL * 1.0F,
		START_SHIELD,
		START_HULL,
		0.5F
	},
	{	// Lokasenna
		MAXMOVESPEED * (1.0F - ( 0.01F * BikeMod )), 
		MOVEACCELL *1.0F,	
		MOVEDECELL,	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED * (1.0F + ( 0.01F * BikeMod )),
		TURNACCELL * (1.0F + ( 0.01F * BikeMod )),	
		TURNDECELL * (1.0F + ( 0.01F * BikeMod )),	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,	
		START_SHIELD * 1.0F,
		START_HULL *1.0F,
		1.0F
	},
	{	// Beard
		MAXMOVESPEED * 1.0F, 
		MOVEACCELL * 1.0F,	
		MOVEDECELL,	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED * 1.0F,
		TURNACCELL * 1.0F,	
		TURNDECELL * 1.0F,	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,	
		START_SHIELD * 1.0F,
		START_HULL * 1.0F,
		1.0F
	},
	{	// L.A. Jay
		MAXMOVESPEED * (1.0F + ( 0.03F * BikeMod )), 
		MOVEACCELL* (1.0F+ ( 0.03F * BikeMod )),	
		MOVEDECELL* (1.0F+ ( 0.03F * BikeMod )),	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED* (1.0F+ ( 0.03F * BikeMod )),
		TURNACCELL* (1.0F+ ( 0.03F * BikeMod )),	
		TURNDECELL* (1.0F+ ( 0.03F * BikeMod )),	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,	
		START_SHIELD * (1.0F - ( 0.02F * BikeMod )),
		START_HULL * (1.0F - ( 0.03F * BikeMod )),
		1.0F
	},
	{	// Ex-Cop
		MAXMOVESPEED * (1.0F + ( 0.01F * BikeMod )), 
		MOVEACCELL * (1.0F - ( 0.01F * BikeMod )),	
		MOVEDECELL,	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED * (1.0F + ( 0.01F * BikeMod )),
		TURNACCELL * (1.0F + ( 0.01F * BikeMod )),	
		TURNDECELL * (1.0F + ( 0.01F * BikeMod )),	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,	
		START_SHIELD * (1.0F + ( 0.01F * BikeMod )),
		START_HULL * (1.0F - ( 0.02F * BikeMod )),
		1.0F
	},
	{	// Rex Hardy
		MAXMOVESPEED * (1.0F - ( 0.03F * BikeMod )), 
		MOVEACCELL * (1.0F - ( 0.03F * BikeMod )),	
		MOVEDECELL,	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED * (1.0F - ( 0.01F * BikeMod )),
		TURNACCELL * (1.0F - ( 0.01F * BikeMod )),	
		TURNDECELL * (1.0F - ( 0.01F * BikeMod )),	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,	
		START_SHIELD * (1.0F + ( 0.05F * BikeMod )),
		START_HULL * 1.0F,
		1.0F
	},
	{	// Foetoid
		MAXMOVESPEED, 
		MOVEACCELL * (1.0F - ( 0.01F * BikeMod )),	
		MOVEDECELL,	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED * (1.0F - ( 0.01F * BikeMod )),
		TURNACCELL * (1.0F - ( 0.01F * BikeMod )),	
		TURNDECELL * (1.0F - ( 0.01F * BikeMod )),	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,	
		START_SHIELD * (1.0F + ( 0.02F * BikeMod )),
		START_HULL * 1.0F,
		1.0F
	},
	{	// Nim Soo
		MAXMOVESPEED * 1.0F, 
		MOVEACCELL * 1.0F,	
		MOVEDECELL,	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED * (1.0F - ( 0.01F * BikeMod )),
		TURNACCELL * (1.0F - ( 0.01F * BikeMod )),	
		TURNDECELL * (1.0F - ( 0.01F * BikeMod )),	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,	
		START_SHIELD * (1.0F+ ( 0.01F * BikeMod )),
		START_HULL * 1.0F,
		1.0F
	},
	{	// Nutta
		MAXMOVESPEED * (1.0F + ( 0.05F * BikeMod )), 
		MOVEACCELL * (1.0F + ( 0.01F * BikeMod )),	
		MOVEDECELL,	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED * (1.0F + ( 0.01F * BikeMod )),
		TURNACCELL * (1.0F + ( 0.01F * BikeMod )),	
		TURNDECELL * (1.0F + ( 0.01F * BikeMod )),	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,	
		START_SHIELD * (1.0F - ( 0.04F * BikeMod )),
		START_HULL * (1.0F - ( 0.03F * BikeMod )),
		1.0F
	},
	{	// Sceptre
		MAXMOVESPEED * (1.0F - ( 0.03F * BikeMod )), 
		MOVEACCELL * (1.0F - ( 0.03F * BikeMod )),	
		MOVEDECELL,	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED * (1.0F - ( 0.01F * BikeMod )),
		TURNACCELL * (1.0F - ( 0.01F * BikeMod )),	
		TURNDECELL * (1.0F - ( 0.01F * BikeMod )),	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,	
		START_SHIELD * (1.0F + ( 0.04F * BikeMod )),
		START_HULL * 1.0F,
		1.0F
	},
	{	// Jo
		MAXMOVESPEED * 1.0F, 
		MOVEACCELL * (1.0F + ( 0.04F * BikeMod )),	
		MOVEDECELL,	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED * (1.0F + ( 0.01F * BikeMod )),
		TURNACCELL * (1.0F + ( 0.01F * BikeMod )),	
		TURNDECELL * (1.0F + ( 0.01F * BikeMod )),	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,	
		START_SHIELD * (1.0F - ( 0.02F * BikeMod )),
		START_HULL * (1.0F - ( 0.02F * BikeMod )),
		1.0F
	},
	{	// Cuvel Clark
		MAXMOVESPEED * (1.0F + ( 0.05F * BikeMod )), 
		MOVEACCELL * (1.0F + ( 0.05F * BikeMod )),	
		MOVEDECELL,	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED * (1.0F + ( 0.05F * BikeMod )),
		TURNACCELL * (1.0F + ( 0.05F * BikeMod )),	
		TURNDECELL * (1.0F + ( 0.05F * BikeMod )),	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,	
		START_SHIELD * (1.0F - ( 0.05F * BikeMod )),
		START_HULL * (1.0F - ( 0.05F * BikeMod )),
		1.0F
	},
	{	// HK-5
		MAXMOVESPEED * (1.0F - ( 0.02F * BikeMod )), 
		MOVEACCELL * (1.0F - ( 0.02F * BikeMod )),	
		MOVEDECELL,	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED * (1.0F - ( 0.02F * BikeMod )),
		TURNACCELL * (1.0F - ( 0.02F * BikeMod )),	
		TURNDECELL * (1.0F - ( 0.02F * BikeMod )),	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,	
		START_SHIELD * (1.0F + ( 0.03F * BikeMod )),
		START_HULL * (1.0F - ( 0.01F * BikeMod )),
		1.0F
	},
	{	// Nubia
		MAXMOVESPEED * (1.0F + ( 0.01F * BikeMod )), 
		MOVEACCELL * (1.0F + ( 0.03F * BikeMod )),	
		MOVEDECELL,	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED * (1.0F + ( 0.01F * BikeMod )),
		TURNACCELL * (1.0F + ( 0.01F * BikeMod )),	
		TURNDECELL * (1.0F + ( 0.01F * BikeMod )),	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,	
		START_SHIELD * (1.0F - ( 0.02F * BikeMod )),
		START_HULL * (1.0F - ( 0.01F * BikeMod )),
		1.0F
	},
	{	// Mofisto
		MAXMOVESPEED * (1.0F - ( 0.02F * BikeMod )), 
		MOVEACCELL * (1.0F - ( 0.02F * BikeMod )),	
		MOVEDECELL,	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED * 1.0F,
		TURNACCELL * 1.0F,	
		TURNDECELL * 1.0F,	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,	
		START_SHIELD * 1.0F,
		START_HULL * 1.0F,
		1.0F
	},
	{	// Cerbero
		MAXMOVESPEED, 
		MOVEACCELL,	
		MOVEDECELL,	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED,
		TURNACCELL,	
		TURNDECELL,	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,	
		START_SHIELD,
		START_HULL,
		1.0F
	},
	{	// Slick
		MAXMOVESPEED, 
		MOVEACCELL * (1.0F + ( 0.01F * BikeMod )),	
		MOVEDECELL,	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED * (1.0F + ( 0.03F * BikeMod )),
		TURNACCELL * (1.0F + ( 0.03F * BikeMod )),	
		TURNDECELL * (1.0F + ( 0.03F * BikeMod )),	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,	
		START_SHIELD * (1.0F + ( 0.01F * BikeMod )),
		START_HULL * (1.0F - ( 0.01F * BikeMod )),
		1.0F
	},
	{	// FlyGirl
		MAXMOVESPEED, 
		MOVEACCELL * (1.0F + ( 0.01F * BikeMod )),	
		MOVEDECELL,	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED * (1.0F + ( 0.03F * BikeMod )),
		TURNACCELL * (1.0F + ( 0.03F * BikeMod )),	
		TURNDECELL * (1.0F + ( 0.03F * BikeMod )),	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,	
		START_SHIELD * (1.0F + ( 0.01F * BikeMod )),
		START_HULL * (1.0F - ( 0.01F * BikeMod )),
		1.0F
	},
	{	// Slow Default
		MAXMOVESPEED * 0.9F, 
		MOVEACCELL,	
		MOVEDECELL,	
		MAXTURBOSPEED,
		TURBOACCELL,
		TURBODECELL,
		MAXTURNSPEED,
		TURNACCELL,	
		TURNDECELL,	
		MAXROLLSPEED,
		ROLLACCELL,	
		ROLLDECELL,	
		MAXBANKANGLE, 
		BANKACCELL,	
		BANKDECELL,
		START_SHIELD,
		START_HULL,
		1.0F
	},
};


/*�������������������������������������������������������������������
		Detail Level Globals ...
�������������������������������������������������������������������*/
#define	MAXBIKEDETAIL	4.0F
#define	MAXCOLLISIONS	3


int		outside_map = 0;


int		BikeDetail	= 0;
int		HullHit = 0;
int		ShieldHit = 0;
/*�������������������������������������������������������������������
		Globals ...
�������������������������������������������������������������������*/
uint32 UnderwaterSfxID;
float BountyTime = 0.0F;
extern int BountyBonusInterval;

BOOL ShieldCritical = FALSE;
BOOL HullCritical = FALSE;

D3DMATRIX  TempWorld;	

float	WhiteOut = 0.0F;
float	RandomBubbleTimer = 0.0F;
long debug_long = 0;
long max_mouse_move = 0;
DWORD max_time;
uint16	NumCollides;

SHIPCONTROL control;
float	NitroFuel = 0.0F;
float	NitroFuelUsed = 0.0F;
extern	CAMERA			CurrentCamera;
extern	BOOL	PlayDemo;
extern	BOOL	PauseDemo;
float AutoLevelRot( uint16 ship, float autolevel_rate );
void BobShip( uint16 ship, VECTOR *bob );
void	UpdateStartPos( void );
void CreateSteam( VECTOR * Pos, VECTOR * Dir, uint16 Group );
float	SteamTime = 0.0F;
BOOL	IsStartPosVacantMutualyVisibleGroup( int16 i , uint16 startpos );
BOOL	IsStartPosVacantVisibleGroup( int16 i , uint16 startpos );
BOOL ObjectCollideNoBGObject( OBJECT *Obj, VECTOR *Move_Off, float radius );

extern	BOOL Headlights;

extern	int	RearCameraActive;
BOOL	RearCameraDisable = FALSE;

/*�������������������������������������������������������������������
	Function		:			Ship Control Mode Jump Table
�������������������������������������������������������������������*/
void (* ModeControl[ ])( GLOBALSHIP * ShipPnt , BYTE i ) = {
		ShipMode0,
		ShipMode1,
		ShipMode2,
		RemoteCameraMode3,			// needed for demo playback!!!!!!!!!
		ShipMode4,
};
/*�������������������������������������������������������������������
	Function		:			RemoteCamera Control Mode Jump Table
�������������������������������������������������������������������*/
void (* RemoteCameraModeControl[ ])( GLOBALSHIP * ShipPnt , BYTE i ) = {
		RemoteCameraMode0,
		RemoteCameraMode1,
		RemoteCameraMode1,		// there is no remote camera mode 2 so just use mode 1...
		RemoteCameraMode3
};

_inline
void AccellDecell(  float *  value ,  float  Decell ) 
{
	*value *= (float) (pow( 1.0 - Decell, framelag) );
//	*value *= 1.0F - ( Decell * framelag );
}

/*�������������������������������������������������������������������
		Init All Ships ...
�������������������������������������������������������������������*/

BOOL SetUpShips()
{
	sprintf( NickName, "%s", player_config->name );

	sprintf( MyName, "%s's game", player_config->name );

	return TRUE;
}
static	LONGLONG	TempTime;
static	LONGLONG	TempTime2;
static	float	Interp;	

BOOL ProcessShips()
{
	BYTE	i;
#if 0
	float	Impact_Off_Length;
	VECTOR	Impact_Off;
	float	M;
#endif
	VECTOR	ImpactPoint;
	float	Speed;
	VECTOR	Move_Off;	
#ifndef MULTI_RAY_COLLISION
	VECTOR	Pos_New;	
	NORMAL	FaceNormal;
#endif
	VECTOR	Move_Dir;
	QUAT	StepQuat;	
	uint16	ImpactGroup;
	VECTOR	Bob;
	VECTOR	StartPos;
	BGOBJECT * BGObject;
	uint16	NumToDo;
	uint16	OldGroup;
	VECTOR	ExtForce;
	BOOL HasBeenExternal;
	float	ShieldModifier;
	uint32	OldInWater;
	BOOL	Object2Object;
	NODE * NodePnt;
	OBJECT * ShipObjPnt;
	GLOBALSHIP * ShipPnt;
	int		goalcheck;
	BOOL OldWaterOneshot;

	if( !BombTag && IsServerGame && IsServer )
	{
		CheckPickupAllPlayers();
	}

	UpdateStartPos();
	MultiSfxHandle();

	RearCameraDisable = FALSE;

#if 0
	for( i = 0 ; i < 10 ; i ++ )
	{
		DebugPrintf( "pow( 0.9 ,framelag %f ) = %f \n", 1.0F - (i / 10.0F) , (float) pow( 0.9 , 1.0F - (i / 10.0F) ) );
	}
#endif

	if( PlayDemo )
	{
		NumToDo = MAX_PLAYERS+1;
	}else{
		NumToDo = MAX_PLAYERS;
	}
	for( i=0;i<NumToDo;i++)
	{
		ShipObjPnt = &Ships[i].Object;
		ShipPnt = &Ships[i];
		Ships[i].Object.ID = ShipPnt;

		if( ShipPnt->enable || (IsServer && i == 0) )
		{
			if( IsServer && i == 0 )
				ShipPnt->enable = 0;

			if( ShipPnt->Invul )
			{
				if( !PlayDemo )
				{
					if( Current_Camera_View != i )
					{
						if( i != WhoIAm )
						{
							CreateInvEffect( i, 5, 255, 64, 64 );
						}
						else
						{
							if( Current_Camera_View != WhoIAm )
							{
								CreateInvEffect( i, 5, 255, 64, 64 );
							}
						}
					}
				}
				else
				{
					if( Current_Camera_View != i )
					{
						CreateInvEffect( i, 5, 255, 64, 64 );
					}
				}
			}

			DoDamagedEffects( i );							// Do Effects when damaged



			// Special Noise Distance Modifier...
			if( ShipObjPnt->Noise > 0.0F )
			{
				ShipObjPnt->Noise -= NOISEFALLOFFFACTOR * framelag;
			}else{
				ShipObjPnt->Noise = 0.0F;
			}


			StartPos = ShipObjPnt->Pos;
			OldGroup = ShipObjPnt->Group;
			if( WhoIAm == i)
			{

#if 1
				if( Headlights )
				{
					if( ShipObjPnt->light == (uint16) -1 )
					{
						ShipObjPnt->light = FindFreeXLight();
					}
					if( ShipObjPnt->light != (uint16) -1 )
					{
						ShipObjPnt->Flags |= SHIP_Light;

						XLights[ShipObjPnt->light].Size = (4096.0F+2048.0F)*GLOBAL_SCALE;
						XLights[ShipObjPnt->light].CosArc = (float)cos(D2R(35));
						
						ApplyMatrix( &ShipObjPnt->FinalMat, &Forward, &XLights[ShipObjPnt->light].Dir );			/* Calc Direction Vector */
						XLights[ShipObjPnt->light].r = 192.0F;
						XLights[ShipObjPnt->light].g = 192.0F;
						XLights[ShipObjPnt->light].b = 192.0F;
						XLights[ShipObjPnt->light].Type = SPOT_LIGHT;
						XLights[ShipObjPnt->light].Pos = ShipObjPnt->Pos;
						XLights[ShipObjPnt->light].Group = ShipObjPnt->Group;
					}
				}else{
					ShipObjPnt->Flags &= ~SHIP_Light;
					if( ShipObjPnt->light != (uint16) -1 )
					{
						KillUsedXLight( ShipObjPnt->light );
						ShipObjPnt->light = (uint16) -1;
					}
				}
#endif




				ShipObjPnt->NodeNetwork = 1;
				if( !ShipObjPnt->NearestNode )
				{
					FindNearestNode( &ShipPnt->Object );
				}else{
					UpdateNearestNodeSpecial( &ShipPnt->Object );
				}
				NodePnt = ShipObjPnt->NearestNode;
				if( NodePnt && ShowNode)
				{
					SteamTime -= framelag;
					if( SteamTime < 0.0F )
					{
						CreateSteam( &NodePnt->Pos, &SlideUp, NodePnt->Group );
						SteamTime = 10.0F;
					}
				}
				
				
				if( !GodMode )
				{
					if( ShipPnt->InvulTimer != 0.0F )
					{
						ShipPnt->InvulTimer -= framelag;
						if( ShipPnt->InvulTimer < 0.0F )
						{
							ShipPnt->InvulTimer = 0.0F;
						}
						else
						{
							ShipPnt->Invul = TRUE;
						}
					}
					else
					{
						ShipPnt->Invul = FALSE;
						if( PickupInvulnerability )
						{
							NumInvuls++;
							PickupInvulnerability = FALSE;
						}
					}
					if ( BountyHunt && ShipObjPnt->Flags & SHIP_CarryingBounty )
					{
						BountyTime += framelag / 60.0F;
						if ( BountyBonusInterval > 0 && BountyTime >= BountyBonusInterval )
						{
							ShipPnt->Kills += (int16) floor( BountyTime / BountyBonusInterval );
							BountyTime = FMOD( BountyTime, BountyBonusInterval );
						}
					}
				}

				if( ShipPnt->ShakeTimer )
				{
					ShipPnt->ShakeTimer -= framelag;
					if( ShipPnt->ShakeTimer > 0.0F )
					{
						ShipPnt->ShakeDirTimer -= framelag;
						if( ShipPnt->ShakeDirTimer <= 0.0F )
						{
							ShipPnt->ShakeDirTimer = 2.0F + ( Random_Range(32) * ( 1.0F / 32.0F ) );
					
							ExtForce.x = -(ShipPnt->ShakeForce * 0.5F ) + (Random_Range(32) * ( ShipPnt->ShakeForce / 32.0F));
							ExtForce.y = -(ShipPnt->ShakeForce * 0.5F ) + (Random_Range(32) * ( ShipPnt->ShakeForce / 32.0F));
							ExtForce.z = 0.0F;
							RotateInternal( i, ExtForce.x, ExtForce.y, ExtForce.z );
							ExtForce.x *= 0.5F;
							ExtForce.y *= 0.5F;
							ForceInternalOneOff( i, &ExtForce );
						}
						ShipPnt->ShakeForce *= 0.02F * framelag;
					}else{
						ShipPnt->ShakeTimer = 0.0F;
					}
				}


				
				( * ModeControl[ ShipObjPnt->Mode ] )( ShipPnt , i );		//go off and do his thing...

				if( (i==MAX_PLAYERS) || (ShipObjPnt->Mode != DEATH_MODE && ShipObjPnt->Mode != LIMBO_MODE && ShipObjPnt->Mode != GAMEOVER_MODE) )
				{

					if( ( ShipObjPnt->Flags & SHIP_Stealth ) )
					{
						ShipPnt->StealthTime -= framelag;
						if( ShipPnt->StealthTime <= 0.0F )
						{
							PlaySfx( SFX_DeCloaking, 1.0F );
							ShipPnt->StealthTime = 0.0F;
							ShipObjPnt->Flags &= ~SHIP_Stealth;
							NumStealths++;
						}
					}



					AccellDecell( &ShipObjPnt->Angle.y , TurnDecell );
			 		AccellDecell( &ShipObjPnt->Angle.x , TurnDecell );
			 		AccellDecell( &ShipObjPnt->Angle.z , RollDecell );
					ShipObjPnt->Autolevel = AutoLevelRot( i, AutoLevel * player_config->autolevel_rate * framelag );
				
			 		AccellDecell( &ShipObjPnt->Bank , BankDecell );
				
					AccellDecell( &ShipObjPnt->Speed.x , MoveDecell );
					AccellDecell( &ShipObjPnt->Speed.y , MoveDecell );
					if ( ( control.turbo || ( !control.forward && ShipObjPnt->CruiseControl == CRUISE_NITRO ) ) && NitroFuel > 0.0F )
					{
						if( !GodMode && !( ShipObjPnt->Flags & SHIP_SuperNashram ) )
						{
							if( NitroFuel <= ( NITROLOSS * framelag ) )
							{
								NitroFuelUsed += NitroFuel;
								NitroFuel = 0.0F;
							}
							else
							{
								NitroFuel -= ( NITROLOSS * framelag );
								NitroFuelUsed += ( NITROLOSS * framelag );
							}
						}
						ShipObjPnt->Flags |= SHIP_Turbo;

						AccellDecell( &ShipObjPnt->Speed.z , TurboDecell );
					}
					else
					{
						ShipObjPnt->Flags &= ~SHIP_Turbo;
						AccellDecell( &ShipObjPnt->Speed.z , MoveDecell );
					}
				
					MakeQuat( ShipObjPnt->Angle.x * framelag, ShipObjPnt->Angle.y * framelag, ShipObjPnt->Angle.z * framelag + ShipObjPnt->Autolevel, &StepQuat );
					QuatMultiply(  &ShipObjPnt->Quat , &StepQuat , &ShipObjPnt->Quat );
					QuatMultiply(  &ShipObjPnt->RotationForce , &ShipObjPnt->Quat , &ShipObjPnt->Quat );
					QuatToMatrix( &ShipObjPnt->Quat, &ShipObjPnt->Mat );
					MakeQuat( 0.0F, 0.0F, 0.0F, &ShipObjPnt->RotationForce );
				
					// carry out movements
					BobShip( i, &Bob );
					Move_Off.x = Bob.x - ShipObjPnt->LastBob.x;
					Move_Off.y = Bob.y - ShipObjPnt->LastBob.y;
					Move_Off.z = Bob.z - ShipObjPnt->LastBob.z;
					ShipObjPnt->LastBob = Bob;
					
					if ( ShipObjPnt->Speed.x )
					{
						Speed = ShipObjPnt->Speed.x * framelag;
						ApplyMatrix( &ShipObjPnt->Mat, &SlideRight, &Move_Dir );			/* Calc Direction Vector */
				   		Move_Off.x += ( Move_Dir.x * Speed );
				   		Move_Off.y += ( Move_Dir.y * Speed );
				   		Move_Off.z += ( Move_Dir.z * Speed );
					}
					if ( ShipObjPnt->Speed.y )
					{
						Speed = ShipObjPnt->Speed.y * framelag;
						ApplyMatrix( &ShipObjPnt->Mat, &SlideUp, &Move_Dir );			/* Calc Direction Vector */
				   		Move_Off.x += ( Move_Dir.x * Speed );
				   		Move_Off.y += ( Move_Dir.y * Speed );
				   		Move_Off.z += ( Move_Dir.z * Speed );
					}
					if ( ShipObjPnt->Speed.z )
					{
						Speed = ShipObjPnt->Speed.z * framelag;
						ApplyMatrix( &ShipObjPnt->Mat, &Forward, &Move_Dir );			/* Calc Direction Vector */
				   		Move_Off.x += ( Move_Dir.x * Speed );
				   		Move_Off.y += ( Move_Dir.y * Speed );
				   		Move_Off.z += ( Move_Dir.z * Speed );
					}

					// apply external and internal force vectors to ship movement
					AccellDecell( &ShipObjPnt->ExternalForce.x , MoveDecell );
					AccellDecell( &ShipObjPnt->ExternalForce.y , MoveDecell );
					AccellDecell( &ShipObjPnt->ExternalForce.z , MoveDecell );

					Move_Off.x += ShipObjPnt->ExternalForce.x * framelag;
					Move_Off.y += ShipObjPnt->ExternalForce.y * framelag;
					Move_Off.z += ShipObjPnt->ExternalForce.z * framelag;

					Object2Object = FALSE;
					if( (i != MAX_PLAYERS) && (ShipObjPnt->Mode != LIMBO_MODE) )
					{
						Object2Object |= Ship2ShipCollide( i , &Move_Off );
					}
					// Collide with the enemies....
					Object2Object |= Ship2EnemyCollide( i , &Move_Off );
					// do collisions to background

					if( VectorLength( &Move_Off ) <= MoveAccell )
					{
						Move_Off.x = 0.0F; 
						Move_Off.y = 0.0F; 
						Move_Off.z = 0.0F;
						ImpactPoint = ShipObjPnt->Pos;
						ImpactGroup = ShipObjPnt->Group;
						
					}else{
						if( !no_collision )
						{
							NumCollides = 0;
							if ( ShipObjPnt->Group != (uint16) -1 )
#ifdef MULTI_RAY_COLLISION
							{
#ifdef MULTI_RAY_SLIDE
								VECTOR Target_Off;

								BGObject = NULL;
								while ( ObjectCollideOnly( &ShipPnt->Object, &Move_Off, SHIP_RADIUS, &Target_Off, &BGObject ) )
								{
									if ( BGObject )
										ChangeBGState( BGObject, OWNER_SHIP, WhoIAm, BUMP, 0.0F );
									BGObject = NULL;
									Move_Off = Target_Off;
									if ( ++NumCollides > MAXCOLLISIONS )
										break;
								}
#else
								BGObject = NULL;

								if( IsServer && i == WhoIAm )
								{
									ObjectCollideNoBGObject( &ShipPnt->Object, &Move_Off, SHIP_RADIUS);
								}else{

									if( !Object2Object )
									{
										ObjectCollide( &ShipPnt->Object, &Move_Off, SHIP_RADIUS, &BGObject );
										if( BGObject ) ChangeBGState( BGObject, OWNER_SHIP, WhoIAm, BUMP, 0.0F );
									}else{
										ObjectCollideNoBounce( &ShipPnt->Object, &Move_Off, SHIP_RADIUS, &BGObject );
										if( BGObject ) ChangeBGState( BGObject, OWNER_SHIP, WhoIAm, BUMP, 0.0F );
									}
								}
#endif
								outside_map = !PointInsideSkin( &ShipObjPnt->Pos, ShipObjPnt->Group );
								if ( outside_map )
								{
									if ( !DebugInfo )
									{
										// player has somehow managed to get outside the map
										// so we "teleport" him back to his last start position
										// (BiaS strikes again...!)
										InitShipStartPos( i, 0 );
										PlaySfx( SFX_Teleport, 1.0F );
									}
									else
									{
										uint16 g;
										
										for ( g = 0; g < Mloadheader.num_groups; g++ )
										{
											if ( PointInsideSkin( &ShipObjPnt->Pos, g ) )
											{
												ShipObjPnt->Group = g;
												AddMessageToQue( "You are now in %s", Mloadheader.Group[ g ].name );
												break;
											}
										}
									}
								}
							}
#else
							{
								while ( BackgroundCollide( &MCloadheader, &Mloadheader,
   															&ShipObjPnt->Pos, ShipObjPnt->Group, &Move_Off,
   															&ImpactPoint , &ImpactGroup, &FaceNormal, &Pos_New, TRUE, &BGObject ) )
								{
									if( BGObject ) ChangeBGState( BGObject, OWNER_SHIP, WhoIAm, BUMP, 0.0F );
							
									ShipObjPnt->Pos = ImpactPoint;
									ShipObjPnt->Group = ImpactGroup;
									Move_Off.x = Pos_New.x - ShipObjPnt->Pos.x; 
									Move_Off.y = Pos_New.y - ShipObjPnt->Pos.y; 
									Move_Off.z = Pos_New.z - ShipObjPnt->Pos.z;
									
									if( VectorLength( &Move_Off ) <= MoveAccell )
									{
										Move_Off.x = 0.0F; 
										Move_Off.y = 0.0F; 
										Move_Off.z = 0.0F;
										break;								
									}
									
									NumCollides += 1;
									if( NumCollides	> MAXCOLLISIONS )
										break;
								}
								outside_map = outside_group;
							}
							
	//						if( InBSPGroup( 0, &ImpactPoint )	)
							{
								// the end point is actually outside...
								ShipObjPnt->Pos = ImpactPoint;
								ShipObjPnt->Group = ImpactGroup;
							}
	#endif
						}else{
							ShipObjPnt->Group = MoveGroup( &Mloadheader, &ShipObjPnt->Pos, ShipObjPnt->Group, &Move_Off );
							ShipObjPnt->Pos.x += Move_Off.x;
							ShipObjPnt->Pos.y += Move_Off.y;
							ShipObjPnt->Pos.z += Move_Off.z;
						}

					}


					ExtForce.x = 0.0F;
					ExtForce.y = 0.0F;
					ExtForce.z = 0.0F;
					ShieldModifier = 0.0F;
					HasBeenExternal = ExternalForcesAreaCheck( &ShipObjPnt->Pos , &StartPos , ShipObjPnt->Group, &ExtForce , &ShieldModifier);
					TriggerAreaPlayerCheck( &StartPos , &ShipObjPnt->Pos , ShipObjPnt->Group);
					if( OldGroup != ShipObjPnt->Group )
					{
						TriggerAreaPlayerCheck( &StartPos , &ShipObjPnt->Pos , OldGroup);
					}

					if ( CaptureTheFlag && ShipObjPnt->Flags & SHIP_CarryingFlag )
					{
						goalcheck = GoalCheckTeam( &StartPos, &ShipObjPnt->Pos, ShipObjPnt->Group, TeamNumber[ i ] );
						if ( goalcheck == GOAL_SCORED )
						{
							if ( !IsServerGame )
							{
								PickupsGot[ PICKUP_Flag ] = 0;
								Ships[ i ].Object.Flags &= ~SHIP_CarryingFlag;
								FlagsToGenerate++;
								Ships[ i ].Kills += GoalScore;
								AddMessageToQue( TEAM_SCORED,
									TeamName[ TeamNumber[ i ] ] );

								SendGameMessage(MSG_TEXTMSG, 0, 0, TEXTMSGTYPE_ScoredWithFlag, 0);
							}
						}
						else if ( goalcheck == GOAL_WRONG )
						{
							AddMessageToQue( TAKE_FLAG_TO_GOAL,
								TeamName[ TeamNumber[ i ] ] );
						}
					}

					if ( CTF && ShipObjPnt->Flags & SHIP_CarryingFlags )
					{
						static BOOL IKnowINeedFlag = FALSE;

						goalcheck = GoalCheckTeam( &StartPos, &ShipObjPnt->Pos, ShipObjPnt->Group, TeamNumber[ i ] );
						if ( goalcheck == GOAL_SCORED )
						{
							if ( !NeedFlagAtHome
								|| TeamFlagAtHome[ TeamNumber[ i ] ]
								|| ShipObjPnt->Flags & TeamFlagMask[ TeamNumber[ i ] ] )
							{
								if ( !IsServerGame )
								{
									int team;
									int score;

									score = 0;
									for ( team = 0; team < MAX_TEAMS; team++ )
									{
										if ( ShipObjPnt->Flags & TeamFlagMask[ team ] )
										{
											PickupsGot[ TeamFlagPickup[ team ] ] = 0;
											Ships[ i ].Object.Flags &= ~TeamFlagMask[ team ];
											if ( team != TeamNumber[ i ] )
											{
												score += GoalScore;
											}
											GenerateFlagAtHome( team );
										}
									}
									if ( score )
									{
										Ships[ i ].Kills += score;
										AddMessageToQue( TEAM_SCORED,
											TeamName[ TeamNumber[ i ] ] );
										
										SendGameMessage(MSG_TEXTMSG, 0, 0, TEXTMSGTYPE_ScoredWithFlag, 0);
									}
									else
									{
										AddMessageToQue( OTHER_TEAM_FLAG_RETURNED,
											TeamName[ TeamNumber[ i ] ] );
										SendGameMessage(MSG_TEXTMSG, 0, 0, TEXTMSGTYPE_ReturnedFlag, 0);
									}
								}
								IKnowINeedFlag = FALSE;
							}
							else
							{
								if ( !IKnowINeedFlag )
								{
									AddMessageToQue( YOU_NEED_FLAG,
										TeamName[ TeamNumber[ i ] ] );
									IKnowINeedFlag = TRUE;
								}
							}
						}
						else
						{
							if ( goalcheck == GOAL_WRONG )
							{
								AddMessageToQue( TAKE_FLAG_TO_GOAL,
									TeamName[ TeamNumber[ i ] ] );
							}
							IKnowINeedFlag = FALSE;
						}
					}

					// this is where we go into and out of water

					OldInWater = ShipObjPnt->Flags & SHIP_InWater;
					ShipObjPnt->Flags &= ~SHIP_InWater;
					if( InWater( ShipObjPnt->Group , &ShipObjPnt->Pos , &ShieldModifier) )
					{
						ShipObjPnt->Flags |= SHIP_InWater;
					}else
					{
						// not in water, therefore stop underwater looping sfx if currently playing
						if ( UnderwaterSfxID )
						{
							StopSfx( UnderwaterSfxID );
						}
					}

					if( (ShipObjPnt->Flags&SHIP_InWater) )
					{
						SetBikeMods( 1 );
					}
					if( !(ShipObjPnt->Flags&SHIP_InWater) )
					{
						if( MyGameStatus == STATUS_SinglePlayer )
						{
							SetBikeMods( (uint16) (SelectedBike+2) );
						}else{
//							SetBikeMods( 0 );
							// Slow down the bike for Multiplayer games...
							SetBikeMods( MAXBIKETYPES+2 );
						}
					}

					// make a wake in any water....
					if( WaterObjectCollide( OldGroup , &StartPos, &Move_Off, &ImpactPoint , 4 ) )
					{
						// We hit the water....
						if( (ShipObjPnt->Flags&SHIP_InWater) )
						{
							// entered the water....
							PlaySfx( SFX_Submerge , 1.0F );
							// kill off any existing water sfx ( shouldn't be needed )
							if ( UnderwaterSfxID )
							{
								StopSfx( UnderwaterSfxID );
							}
							UnderwaterSfxID = PlaySfx( SFX_UnderWaterAmb , 1.0F );
						}else{
							// exited the water....
							PlaySfx( SFX_Surface , 1.0F );
						}
					}

					if( (ShipObjPnt->Flags&SHIP_InWater) )
					{
						// random Bubble noise.....
						OldWaterOneshot = RandomBubbleTimer >= (60.0F * 5.0F );
						RandomBubbleTimer -= framelag;

						if( OldWaterOneshot && RandomBubbleTimer < (60.0F * 5.0F ) )
						{
							PlaySfx( SFX_UnderwaterOneShot , 0.5F + Random_Range_Float( 0.5F ) );
						}
						if( RandomBubbleTimer < 0.0F )
						{
							RandomBubbleTimer = (60.0F * 5.0F ) + Random_Range_Float( 60.0F * 10.0F );
							PlaySfx( SFX_Bubbles , 0.5F + Random_Range_Float( 0.5F ) );
						}

					}


					
					if( HasBeenExternal )
					{
						ForceExternalOneOff( i, &ExtForce );

					}
					if( ShieldModifier )
					{
						ShipPnt->Damage = ShieldModifier;

						if( DoDamage( DONT_OVERRIDE_INVUL ) )
						{
							ShipPnt->ShipThatLastKilledMe = i;
							ShipObjPnt->Mode = DEATH_MODE;
							ShipPnt->Timer = 0.0F;
							// make a note of who killed who...
							Stats[i][i]++;
							// print up I killed Myself
							AddMessageToQue( YOU_KILLED_YOURSELF );
							PlaySfx( SFX_BIKECOMP_DY, 1.0F );

						}
					}


					if( TeleportsAreaCheck( &ShipObjPnt->Pos , &StartPos , OldGroup, ShipObjPnt ) )
					{
					}

					if ( framelag )
					{
						ShipPnt->Move_Off.x = Move_Off.x / framelag;
						ShipPnt->Move_Off.y = Move_Off.y / framelag;
						ShipPnt->Move_Off.z = Move_Off.z / framelag;
					}

					if( !BombTag )
					{
						if( !IsServerGame || ( IsServerGame && !IsServer ) )
						{
							CheckPickup();
						}
					}

					FB_Jolt();
					FB_Engine();
					FB_Damper();
					FB_Inertia();
				}

		
			}else{
// Start of Special Stuff for other players Ship Movement..Carries on even if no new packet arrives..

				if( !ShipPnt->JustRecievedPacket )
				{

					StartPos = ShipObjPnt->Pos;
					if( ShipObjPnt->Mode != LIMBO_MODE )
					{
						if( ( ( MyGameStatus == STATUS_SplashScreen ) || ( MyGameStatus == STATUS_PlayingDemo ) || ( MyGameStatus == STATUS_AttractMode ) ) && ShipPnt->DemoInterpolate && (ShipObjPnt->Mode != GAMEOVER_MODE) )
						{
							TempTime = ShipPnt->NextTime - ShipPnt->OldTime;
							TempTime2 = GameElapsedTime - ShipPnt->OldTime;

							if( TempTime <= 5 )
							{
								Interp = 0.0F;
							}
							
							Interp = (float) ( ( 1.0F / (float ) TempTime ) * (float) TempTime2);
							if( (Interp >= 0.0F) && (Interp <= 1.001F) )
							{
								Interp = -Interp;
								ShipObjPnt->Pos.x = ShipPnt->OldPos.x + ( ( ShipPnt->OldPos.x - ShipPnt->NextPos.x ) * Interp);
								ShipObjPnt->Pos.y = ShipPnt->OldPos.y + ( ( ShipPnt->OldPos.y - ShipPnt->NextPos.y ) * Interp);
								ShipObjPnt->Pos.z = ShipPnt->OldPos.z + ( ( ShipPnt->OldPos.z - ShipPnt->NextPos.z ) * Interp);
								
								Quaternion_Slerp( -Interp, &ShipPnt->OldQuat, &ShipPnt->NextQuat, &ShipObjPnt->Quat, 0 );
								
								ShipObjPnt->Bank = ShipPnt->OldBank + ( ( ShipPnt->OldBank - ShipPnt->NextBank ) * Interp);
							}else{
								Interp = 0.0F;
							}

						}else{
//							if( !IsServer )
							{

								// carry out movements
								Move_Off.x = ShipPnt->Move_Off.x * framelag;
								Move_Off.y = ShipPnt->Move_Off.y * framelag;
								Move_Off.z = ShipPnt->Move_Off.z * framelag;
								ShipObjPnt->Pos.x += Move_Off.x;		
								ShipObjPnt->Pos.y += Move_Off.y;		
								ShipObjPnt->Pos.z += Move_Off.z;
								MakeQuat( ShipPnt->LastAngle.x * framelag, ShipPnt->LastAngle.y * framelag, (ShipPnt->LastAngle.z * framelag) + ShipObjPnt->Autolevel, &StepQuat );
								QuatMultiply(  &ShipObjPnt->Quat , &StepQuat , &ShipObjPnt->Quat );

								ShipPnt->PacketDelay -= framelag;
								if( ShipPnt->PacketDelay <= 0.0F )
								{
									ShipPnt->PacketDelay = 0.0F;
									AccellDecell( &ShipPnt->Move_Off.x , MoveDecell );
									AccellDecell( &ShipPnt->Move_Off.y , MoveDecell );
									AccellDecell( &ShipPnt->Move_Off.z , MoveDecell );
									AccellDecell( &ShipPnt->LastAngle.y , TurnDecell );
				 					AccellDecell( &ShipPnt->LastAngle.x , TurnDecell );
				 					AccellDecell( &ShipPnt->LastAngle.z , RollDecell );
								}
							}
						}
						// Still need to update the group....
						Move_Off.x = ShipObjPnt->Pos.x - StartPos.x;
						Move_Off.y = ShipObjPnt->Pos.y - StartPos.y;
						Move_Off.z = ShipObjPnt->Pos.z - StartPos.z;
						ShipObjPnt->Group = MoveGroup( &Mloadheader, &StartPos, ShipObjPnt->Group, &Move_Off );
					}
				}else{
					ShipPnt->JustRecievedPacket = FALSE;
				}
			}
// End of Special Stuff for other players Ship Movement..Carries on even if no new packet arrives..
/*�����������������������������������������������������������������������
			Set the Banking Matrix
�����������������������������������������������������������������������*/
			MakeQuat( 0.0F , 0.0F , ShipObjPnt->Bank, &StepQuat );
			QuatMultiply(  &ShipObjPnt->Quat , &StepQuat , &ShipObjPnt->FinalQuat );
			QuatToMatrix( &ShipObjPnt->FinalQuat, &ShipObjPnt->FinalMat );
			MatrixTranspose( &ShipObjPnt->FinalMat, &ShipObjPnt->FinalInvMat );
#if 0
			if( ShipObjPnt->light == (uint16) -1 )
			{
				ShipObjPnt->light = FindFreeXLight();
			}
			if( ShipObjPnt->light != (uint16) -1 )
			{
				XLights[ShipObjPnt->light].Size = (4096.0F+2048.0F)*GLOBAL_SCALE;
				XLights[ShipObjPnt->light].CosArc = (float)cos(D2R(35));
				
				ApplyMatrix( &ShipObjPnt->FinalMat, &Forward, &XLights[ShipObjPnt->light].Dir );			/* Calc Direction Vector */
				XLights[ShipObjPnt->light].r = 255.0F;
				XLights[ShipObjPnt->light].g = 255.0F;
				XLights[ShipObjPnt->light].b = 255.0F;
				XLights[ShipObjPnt->light].Type = SPOT_LIGHT;
				XLights[ShipObjPnt->light].Pos = ShipObjPnt->Pos;
				XLights[ShipObjPnt->light].Group = ShipObjPnt->Group;
			}
#endif

#if 0
			if( ShipObjPnt->light == (uint16) -1 )
			{
				ShipObjPnt->light = FindFreeXLight();
			}
			if( ShipObjPnt->light != (uint16) -1 )
			{
				XLights[ShipObjPnt->light].Size = SHIP_RADIUS * 2;
				XLights[ShipObjPnt->light].r = 0.0F;
				XLights[ShipObjPnt->light].g = 0.0F;
				XLights[ShipObjPnt->light].b = 16.0F;
				XLights[ShipObjPnt->light].Pos = ShipObjPnt->Pos;
				XLights[ShipObjPnt->light].Group = ShipObjPnt->Group;
			}
#endif





			ShipPnt->LastMove.x = ShipObjPnt->Pos.x - StartPos.x;
			ShipPnt->LastMove.y = ShipObjPnt->Pos.y - StartPos.y;
			ShipPnt->LastMove.z = ShipObjPnt->Pos.z - StartPos.z;

		}

		if( PlayDemo && ( i == MAX_PLAYERS ) )
		{
			if( PauseDemo )
			{
				framelag = 0.0F;
			}else{
				if( DemoScreenGrab && !CurrentMenu )
				{
					framelag = 4.0F;
				}else{
					framelag = Oldframelag * Demoframelag;
				}
			}
		}

		UpdateShipModel( i );

	}

	if( !PlayDemo )
	{
		if( Ships[MAX_PLAYERS].enable != 0 )
		{
			// we have a remote Camera...
			Current_Camera_View = MAX_PLAYERS;		// which object is currently using the camera view....
			Process_Remote_Camera();
		}else{
			Current_Camera_View = WhoIAm;			// which object is currently using the camera view....
		}
	}

//	if( Sound3D )
	if( A3DCapable )
	{
		SetPosVelDir_Listner( &Ships[WhoIAm].Object.Pos , &Ships[WhoIAm].Move_Off , &Ships[WhoIAm].Object.Mat );
	}
	
	return TRUE;
}

void ForceExternal( uint16 ship, VECTOR *force )
{
	Ships[ ship ].Object.ExternalForce.x += ( force->x * framelag );
	Ships[ ship ].Object.ExternalForce.y += ( force->y * framelag );
	Ships[ ship ].Object.ExternalForce.z += ( force->z * framelag );
}


void ForceInternal( uint16 ship, VECTOR *force )
{
	VECTOR	NewForce;

	ApplyMatrix( &Ships[ ship ].Object.Mat, force, &NewForce );

	Ships[ ship ].Object.ExternalForce.x += ( NewForce.x * framelag );
	Ships[ ship ].Object.ExternalForce.y += ( NewForce.y * framelag );
	Ships[ ship ].Object.ExternalForce.z += ( NewForce.z * framelag );

}

void ForceExternalOneOff( uint16 ship, VECTOR *force )
{
	Ships[ ship ].Object.ExternalForce.x += force->x;
	Ships[ ship ].Object.ExternalForce.y += force->y;
	Ships[ ship ].Object.ExternalForce.z += force->z;
	if ( ship == WhoIAm )
		FB_JoltForce( force );
}


void ObjForceExternalOneOff( OBJECT *Obj, VECTOR *force )
{
	Obj->ExternalForce.x += force->x;
	Obj->ExternalForce.y += force->y;
	Obj->ExternalForce.z += force->z;
}



void ForceInternalOneOff( uint16 ship, VECTOR *force )
{
	VECTOR	NewForce;

	ApplyMatrix( &Ships[ ship ].Object.Mat, force, &NewForce );

	Ships[ ship ].Object.ExternalForce.x += NewForce.x;
	Ships[ ship ].Object.ExternalForce.y += NewForce.y;
	Ships[ ship ].Object.ExternalForce.z += NewForce.z;

}


void RotateExternal( uint16 ship, VECTOR *point, VECTOR *dir, float force )
{
	VECTOR to_ship;
	VECTOR axis;
	VECTOR near_ship;
	float t;
	float angle;
	QUAT rot;

	to_ship.x = Ships[ship].Object.Pos.x - point->x;
	to_ship.y = Ships[ship].Object.Pos.y - point->y;
	to_ship.z = Ships[ship].Object.Pos.z - point->z;
	CrossProduct( dir, &to_ship, &axis );
	NormaliseVector( &axis );
	t = DotProduct( dir, &to_ship ); // / DotProduct( dir, dir )  iff |dir| != 1
	near_ship.x = point->x + t * dir->x - Ships[ship].Object.Pos.x;
	near_ship.y = point->y + t * dir->y - Ships[ship].Object.Pos.y;
	near_ship.z = point->z + t * dir->z - Ships[ship].Object.Pos.z;
	angle = force * VectorLength( &near_ship ) / SHIP_RADIUS;
	QuatMake( &rot, axis.x, axis.y, axis.z, angle );
	QuatMultiply( &rot, &Ships[ship].Object.RotationForce, &Ships[ship].Object.RotationForce );
}


void RotateInternal( uint16 ship, float xrot, float yrot, float zrot )
{
	QUAT rot;

	MakeQuat( xrot, yrot, zrot, &rot );
	QuatMultiply( &Ships[ship].Object.RotationForce , &rot , &Ships[ship].Object.RotationForce );
}


// min/max autolevel pitch = +/-75 degrees from horizontal
#define MIN_AUTOLEVEL_PITCH	D2R(5.0F) 
#define MAX_AUTOLEVEL_PITCH	D2R(175.0F)

//#define MIN_AUTOLEVEL_ROLL_TOLERANCE	(0.01F)
#define MIN_AUTOLEVEL_ROLL_TOLERANCE	(0.2F)
#define AUTOLEVEL_RATE					(0.1F)


float AutoLevelRot( uint16 ship, float autolevel_rate )
{
	VECTOR up;
	VECTOR dir;
	VECTOR level;
	VECTOR ship_up;
	VECTOR side;
	float cos_pitch;
	float pitch;
	float cos_roll;
	float roll;
	float autolevel;
	float rot;

	if ( !autolevel_rate )
	{
		return 0.0F; // autolevelling disabled
	}
	if ( fabs( Ships[ ship ].Object.Angle.z ) > MIN_AUTOLEVEL_ROLL_TOLERANCE )
	{
		return 0.0F; // ship still rolling under player control
	}
	up = Mloadheader.Group[ Ships[ ship ].Object.Group ].up;
	ApplyMatrix( &Ships[ ship ].Object.Mat, &Forward, &dir );
	cos_pitch = up.x * dir.x + up.y * dir.y + up.z * dir.z;
	if ( cos_pitch < -1.0F )
		cos_pitch = -1.0F;
	else if ( cos_pitch > 1.0F )
		cos_pitch = 1.0F;
	pitch = (float) acos( cos_pitch );
	if ( pitch < MIN_AUTOLEVEL_PITCH || pitch > MAX_AUTOLEVEL_PITCH )
	{
		return 0.0F;
	}
	CrossProduct( &up, &dir, &level );
	CrossProduct( &dir, &level, &ship_up );
	ApplyMatrix( &Ships[ ship ].Object.Mat, &SlideRight, &side );
	cos_roll = ship_up.x * side.x + ship_up.y * side.y + ship_up.z * side.z;
	if ( cos_roll < -1.0F )
		cos_roll = -1.0F;
	else if ( cos_roll > 1.0F )
		cos_roll = 1.0F;
	roll = (float) acos( cos_roll );
	autolevel = ( R2D( roll ) - 90.0F );
	rot = autolevel_rate * autolevel;
	if ( fabs( rot ) > fabs( autolevel ) )
		rot = autolevel;
	return rot;
}


void BobShip( uint16 ship, VECTOR *bob )
{
	VECTOR move;
	float move_len;

	move = Ships[ ship ].Object.Speed;
	move_len = (float) sqrt( move.x * move.x + move.y * move.y + move.z * move.z );
	if ( move_len < MOVE_TOLERANCE && !DebugInfo && !IsServer )
	{
		move.x = BOB_XSIZE * (float) sin( Ships[ ship ].Object.BobCount * BOB_XFREQ );
		move.y = BOB_YSIZE * (float) sin( Ships[ ship ].Object.BobCount * BOB_YFREQ );
		move.z = 0.0F;
		ApplyMatrix( &Ships[ ship ].Object.Mat, &move, bob );
		Ships[ ship ].Object.BobCount += framelag;
	}
	else
	{
		bob->x = 0.0F;
		bob->y = 0.0F;
		bob->z = 0.0F;
		Ships[ ship ].Object.BobCount = 0.0F;
		Ships[ ship ].Object.LastBob = *bob;
	}
}

/*�������������������������������������������������������������������
		Display All Ships ...
�������������������������������������������������������������������*/
BOOL Mod_Ship_Exec_Buffer( uint16 group, LPDIRECT3DDEVICE lpDev, LPDIRECT3DVIEWPORT lpView )
{
	uint16	i;
	uint16	ModelNum;
	uint16	BikeModel;
	float	temp;
	float	RF, GF, BF, TF;
	D3DCOLOR Col;
	float	Red,Green,Blue,Speed;

	for( i=0;i<MAX_PLAYERS;i++)
	{

		
		if( Current_Camera_View != i)
		{
			if ( (Ships[i].enable != 0) && (Ships[i].Object.Mode != GAMEOVER_MODE) && (Ships[i].Object.Mode != LIMBO_MODE) && ((GameStatus[i] == STATUS_Normal )||(GameStatus[i] == STATUS_SinglePlayer ) ) )
			{
#if 1
			Col = FindNearestCellColour( &Mloadheader, &Ships[i].Object.Pos, Ships[i].Object.Group );
			Red = (float)RGBA_GETRED(Col);
			Green = (float)RGBA_GETGREEN(Col);
			Blue = (float)RGBA_GETBLUE(Col);

			Speed = VectorLength( &Ships[i].Object.Speed );
			Speed += VectorLength( &Ships[i].Object.ExternalForce );
			Speed *= framelag;
			Speed *= 0.1F;

			if( Ships[i].Object.Red < Red )
			{
				Ships[i].Object.Red+= 1.0F + Speed;
				if( Ships[i].Object.Red > Red )
					Ships[i].Object.Red = Red;
			}
			else if( Ships[i].Object.Red > Red )
			{
				Ships[i].Object.Red-= 1.0F + Speed;
				if( Ships[i].Object.Red < Red )
					Ships[i].Object.Red = Red;
			}
			if( Ships[i].Object.Red < 0.0F )
			{
				Ships[i].Object.Red = 0.0F;
			}
			else if( Ships[i].Object.Red > 255.0F )
			{
				Ships[i].Object.Red = 255.0F;
			}
			if( Ships[i].Object.Green < Green )
			{
				Ships[i].Object.Green+= 1.0F + Speed;
				if( Ships[i].Object.Green > Green )
					Ships[i].Object.Green = Green;
			}
			else if( Ships[i].Object.Green > Green )
			{
				Ships[i].Object.Green-= 1.0F + Speed;
				if( Ships[i].Object.Green < Green )
					Ships[i].Object.Green = Green;
			}
			if( Ships[i].Object.Green < 0.0F )
			{
				Ships[i].Object.Green = 0.0F;
			}
			else if( Ships[i].Object.Green > 255.0F )
			{
				Ships[i].Object.Green = 255.0F;
			}

			if( Ships[i].Object.Blue < Blue )
			{
				Ships[i].Object.Blue+= 1.0F + Speed;
				if( Ships[i].Object.Blue > Blue )
					Ships[i].Object.Blue = Blue;
			}
			else if( Ships[i].Object.Blue > Blue )
			{
				Ships[i].Object.Blue-= 1.0F + Speed;
				if( Ships[i].Object.Blue < Blue )
					Ships[i].Object.Blue = Blue;
			}
			if( Ships[i].Object.Blue < 0.0F )
			{
				Ships[i].Object.Blue = 0.0F;
			}
			else if( Ships[i].Object.Blue > 255.0F )
			{
				Ships[i].Object.Blue = 255.0F;
			}

#endif
				// If the group the ship is in is visible then the ship probably is to...
				if( Ships[i].Object.Group == group )
				{
					BikeModel = BikeModels[ ( Ships[i].BikeNum % MAXBIKETYPES ) ];

//					ENV( &ModelHeaders[ BikeModel ], &Ships[i].FinalMat , &Ships[i].Pos );
					
					TempWorld._11 = Ships[i].Object.FinalInvMat._11;
					TempWorld._12 = Ships[i].Object.FinalInvMat._12;
					TempWorld._13 = Ships[i].Object.FinalInvMat._13;
					TempWorld._14 = Ships[i].Object.FinalInvMat._14;
					TempWorld._21 = Ships[i].Object.FinalInvMat._21;
					TempWorld._22 = Ships[i].Object.FinalInvMat._22;
					TempWorld._23 = Ships[i].Object.FinalInvMat._23;
					TempWorld._24 = Ships[i].Object.FinalInvMat._24;
					TempWorld._31 = Ships[i].Object.FinalInvMat._31;
					TempWorld._32 = Ships[i].Object.FinalInvMat._32;
					TempWorld._33 = Ships[i].Object.FinalInvMat._33;
					TempWorld._34 = Ships[i].Object.FinalInvMat._34;
					TempWorld._41 = Ships[i].Object.Pos.x;
					TempWorld._42 = Ships[i].Object.Pos.y;
					TempWorld._43 = Ships[i].Object.Pos.z;
					TempWorld._44 = Ships[i].Object.FinalInvMat._44;
	
					if (lpDev->lpVtbl->SetMatrix(lpDev, hWorld, &TempWorld) != D3D_OK) return FALSE;
	
					/*	Execute it	*/
					if( CurrentCamera.UseLowestLOD )
					{	// Missile camera view always set detail lower...
						temp = (SHIP_RADIUS + (200.0F * GLOBAL_SCALE) + ( 3 * 2048.0F * GLOBAL_SCALE ));
					}else{
						temp = DistanceVector2Vector( &Ships[i].Object.Pos, &CurrentCamera.Pos ); 
					}
					if( temp >= SHIP_RADIUS + (200.0F * GLOBAL_SCALE) )
					{
						ModelNum = (uint16) ( temp / ( 2048.0F * GLOBAL_SCALE ) );

						if( AutoDetail )
						{
							if( avgframelag >= 2.0F )
							{
								// auto detail level....
								ModelNum += (uint16) (avgframelag - 1.0F);
							}
						}
						
						if( ModelNum < BikeDetail )
							ModelNum = BikeDetail;

						if(	ModelNum >= (uint16)MAXBIKEDETAIL )
							ModelNum = (uint16)MAXBIKEDETAIL;

						
						if( ( Ships[i].Object.Flags & SHIP_Stealth ) )
						{
							RF = 0.0F;
							GF = 0.0F;
							BF = 0.0F;
							TF = 0.0F;
						
							if( Ships[i].Object.Flags & SHIP_Charging )
							{
								RF = 0.0F;
								GF = 0.0F;
								BF = 128.0F;
								TF = 255.0F;
							}
						
							ModelNum += (uint16) ( MAXBIKEDETAIL + 1.0F );
							if( LightMxaModel( (uint16) ( BikeModel + ModelNum ), &Ships[i].Object.Pos, RF, GF, BF, TF ) )
							{
								Ships[i].Object.Flags |= SHIP_Litup;
#ifndef FINAL_RELEASE
								CreateMXABoundingBox( &MxaModelHeaders[ BikeModel + ModelNum ],
													&Ships[i].Object.FinalMat, &Ships[i].Object.Pos, &Ships[i].TempLines[ 0 ], Ships[i].Object.Group );
#endif
								if( ExecuteMxaloadHeader ( &MxaModelHeaders[ BikeModel + ModelNum ], Ships[i].Object.Group ) != TRUE )
									return FALSE;
							}
							else
							{
								Ships[i].Object.Flags &= ~SHIP_Litup;
							}
						}
						else
						{
#if 0
							AmbientLightMxaModel( &MxaModelHeaders[ BikeModel + ModelNum ],
											(int)Ships[i].Object.Red,
											(int)Ships[i].Object.Green,
											(int)Ships[i].Object.Blue, 0 );
#endif

#ifndef FINAL_RELEASE
							CreateMXABoundingBox( &MxaModelHeaders[ BikeModel + ModelNum ],
												&Ships[i].Object.FinalMat, &Ships[i].Object.Pos, &Ships[i].TempLines[ 0 ], Ships[i].Object.Group );
#endif
							if (ExecuteMxaloadHeader ( &MxaModelHeaders[ BikeModel + ModelNum ], Ships[i].Object.Group ) != TRUE)
								return FALSE;
						}
					}
				}
			}
		}

	}

	if (lpDev->lpVtbl->SetMatrix(lpDev, hWorld, &identity) != D3D_OK) return FALSE;
	return TRUE;
}





void	InitShipsChangeLevel( MLOADHEADER * Mloadheader )
{
	uint16	i;
	uint16	spos;
	int16	Count;
	JustGenerated = TRUE;

	for( i = 0 ; i < (MAX_PLAYERS+1) ; i++ )
	{
		if( i != WhoIAm )
		{
			Ships[i].enable = 0;
		}else{
			Ships[i].enable = TRUE;
		}
		if( E3DemoHost || E3DemoClient )
		{
			Ships[i].Kills = 0;
			Ships[i].Deaths = 0;
		}

		Ships[i].Object.NodeNetwork = 1;
		Ships[i].Object.NearestNode = NULL;
		Ships[i].Object.Type = OBJECT_TYPE_SHIP;

		Ships[i].Object.Flags = 0;		// Flags Enable/Stealth/Turbo/PrimFire/SecFire/PrimToggle/SecToggle
		Ships[i].StealthTime = 0.0F; // Stealth Mode Time Limit
		Ships[i].InvulTimer = 0.0F;	// HowLong am I Invulnerable
		Ships[i].Invul = FALSE;		// Am I Invulnerable...
		Ships[i].Object.Speed.x = 0.0F;
		Ships[i].Object.Speed.y = 0.0F;
		Ships[i].Object.Speed.z = 0.0F;
		Ships[i].Object.Angle.x = 0.0F;
		Ships[i].Object.Angle.y = 0.0F;
		Ships[i].Object.Angle.z = 0.0F;
		Ships[i].Damage = 0;		// how much Damege I Have Taken...
		Ships[i].PrimPowerLevel = 0.0F; // Trojax Powerlevel
		Ships[i].SuperNashramTimer = 0.0F;	// HowLong have i left with the super nashram?
		Ships[i].Object.PowerLevel = 0;
		Ships[i].Object.Mode = NORMAL_MODE;
		Ships[i].Object.Bank = 0.0F;
		Ships[i].PrimBullIdCount = 0;
		Ships[i].SecBullIdCount	= 0;
		Ships[i].Object.Shield	= Start_Shield;
		Ships[i].Object.Hull	= Start_Hull;
		Ships[i].Object.light = (uint16) -1;
		for( Count = 0; Count < MAXMULTIPLES; Count++ ) Ships[i].OrbModels[ Count ] = (uint16) -1;
		Ships[i].NumMultiples = 0;
		
		MakeQuat( 0.0F, 0.0F, 0.0F, &Ships[i].Object.Quat );
		
		if ( Mloadheader->state == TRUE)
		{
			spos = (i+RandomStartPosModify) % num_start_positions;
			InitShipStartPos( i, spos );
		}else{
			InitShipStartPos( i, 0 );
		}
		Ships[i].Object.Mat = MATRIX_Identity;
		Ships[i].Object.FinalMat = MATRIX_Identity;
		Ships[i].Object.FinalInvMat = MATRIX_Identity;

		// reset external and internal force vectors to ship movement
		Ships[i].Object.ExternalForce.x = 0.0F;
		Ships[i].Object.ExternalForce.y = 0.0F;
		Ships[i].Object.ExternalForce.z = 0.0F;
		Ships[i].Object.InternalForce.x = 0.0F;
		Ships[i].Object.InternalForce.y = 0.0F;
		Ships[i].Object.InternalForce.z = 0.0F;

		Ships[i].Object.Autolevel = 0.0F;
		Ships[i].Object.BobCount = 0.0F;

		RestoreWeapons();
		RestoreAmmo();
	}
}



/*�������������������������������������������������������������������
		True EnviroMent Mapping for an Mloadheader...
�������������������������������������������������������������������*/
BOOL	ENV( MXLOADHEADER * Mxloadheader , MATRIX * Mat ,VECTOR * Pos)
{
	VECTOR Temp;
	D3DEXECUTEBUFFERDESC	debDesc;
	uint16 group;
	uint16 vert;
	uint16 execbuf;
	LPD3DLVERTEX	lpD3DLVERTEX;
	float	u,v;

	for( group = 0 ; group < Mxloadheader->num_groups ; group ++ )
	{
		for( execbuf = 0 ; execbuf < Mxloadheader->Group[group].num_execbufs ; execbuf++ )
		{
			if( (Mxloadheader->Group[group].exec_type[execbuf]&HASENVIROMENTMAP) != 0 )
			{
				/*	lock the execute buffer	*/
				memset(&debDesc, 0, sizeof(D3DEXECUTEBUFFERDESC));
				debDesc.dwSize = sizeof(D3DEXECUTEBUFFERDESC);
				if ( Mxloadheader->Group[group].lpExBuf[execbuf]->lpVtbl->Lock( Mxloadheader->Group[group].lpExBuf[execbuf], &debDesc ) != D3D_OK)
					return FALSE ;
				lpD3DLVERTEX = ( LPD3DLVERTEX ) debDesc.lpData;
				for( vert = 0 ; vert < 	Mxloadheader->Group[group].num_verts_per_execbuf[execbuf] ; vert ++ )
				{
					ApplyMatrix( Mat , (VECTOR *) lpD3DLVERTEX,  &Temp);
					NormaliseVector( &Temp );

					u = (0.125f + (-0.125f * Temp.x) );
					v = (0.125f + (-0.125f * Temp.y) );

//					lpD3DLVERTEX->color = RGBA_MAKE( (long) (u * 255), (long) (v * 255), 0, 255 );
					lpD3DLVERTEX->tu = u;//+(Pos->x*0.001F)+(Pos->z*0.001F);
					lpD3DLVERTEX->tv = v;//+(Pos->y*0.001F);
					lpD3DLVERTEX++;
				}
				/*	unlock the execute buffer	*/
				if ( Mxloadheader->Group[group].lpExBuf[execbuf]->lpVtbl->Unlock( Mxloadheader->Group[group].lpExBuf[execbuf] ) != D3D_OK)
					return FALSE ;
			}
		}
	}
	return TRUE;
}



/*�����������������������������������������������������������������������
			Work Out How Much Damage Ive Taken
			Input : Nothing....Ships[WhoIAm].Damage must be set
			Output: 0 no kill...1 last hit killed me...
����������������������������������������������������������������������*/
int16 DoDamage( BOOL OverrideInvul )
{
	uint8	Message[ 128 ];
	int16	MessageSFX = -1;
	int16	TriggerSFX = -1;

	Message[ 0 ] = 0;
			
	if( GodMode ) return 0;
	if( Ships[ WhoIAm ].Invul && !OverrideInvul ) return 0;
	if( TeamGame && !HarmTeamMates )
	{
		if( Ships[ WhoIAm ].ShipThatLastHitMe != MAX_PLAYERS )
		{
			if( ( TeamNumber[ WhoIAm ] == TeamNumber[ Ships[ WhoIAm ].ShipThatLastHitMe ] ) &&
				( WhoIAm != Ships[ WhoIAm ].ShipThatLastHitMe ) )
			{
				return 0;
			}
		}
	}

	if( Ships[WhoIAm].Object.Mode == NORMAL_MODE )
	{
		if( Ships[WhoIAm].Damage )
		{
			Ships[WhoIAm].Damage *= -1.0F;
			Ships[WhoIAm].Object.Shield += Ships[WhoIAm].Damage;

			if( Ships[WhoIAm].Damage < 0.0F )
			{
				if( Ships[WhoIAm].Object.Mode == NORMAL_MODE )
				{
					MakeScreenFlash( 208, 0, 0, 128, &FlashScreenPoly, SCRSEQ_Fade );

					// play pain cry once in a while ( will be overwritten if shield / hull critical )
					// no speech will be played on death
					if ( !Random_Range( 10 ) )
					{
						MessageSFX = SFX_BikerPain;
					}

					if ( ( Ships[ WhoIAm].Object.Shield < SHIELD_CRITICAL_LEVEL ) && !ShieldCritical )
					{
						MessageSFX = SFX_BIKECOMP_SC;
						TriggerSFX = SFX_BIKER_LE;
						sprintf( &Message[0], SHIELD_CRITICAL );
						ShieldCritical = TRUE;
					}

					if ( ( Ships[ WhoIAm].Object.Hull < HULL_CRITICAL_LEVEL ) && !HullCritical )
					{
						MessageSFX = SFX_BIKECOMP_HC;
						sprintf( &Message[0], HULL_CRITICAL );
						HullCritical = TRUE;
					}
				}
			}

			if( Ships[WhoIAm].Object.Shield  >= MAX_SHIELD )
			{
				Ships[WhoIAm].Object.Shield  = MAX_SHIELD;
			}else{
				ShieldHit = 6*4;
				if( Ships[WhoIAm].Object.Shield  < 0.0F )
				{
					Ships[WhoIAm].Object.Hull += Ships[WhoIAm].Object.Shield;
					Ships[WhoIAm].Object.Shield = 0.0F;
					HullHit = 6*4;
					
					if( Ships[WhoIAm].Object.Hull <= 0 )
					{
						// reset shield & hull critical flags...
						ShieldCritical = FALSE;
						HullCritical = FALSE;

						PlaySfx( SFX_Die, 1.0F );
						Ships[WhoIAm].Object.Hull = 0.0F;
//						Ships[WhoIAm].Deaths++;
						if( Ships[WhoIAm].ShipThatLastHitMe == WhoIAm )
						{
							// killed myself....Doh
							Ships[WhoIAm].Kills--;
						}
						return 1;
					}
				}
			}
		}
	}

	if ( bSoundEnabled && BikeCompSpeechSlider.value && ( MessageSFX != -1 ) )
	{
		if ( ( TriggerSFX != -1 ) && !Random_Range( 4 ) )
			PlaySfxWithTrigger( MessageSFX, TriggerSFX );
		else
			PlaySfx( MessageSFX, 1.0F );
	}
	else
	{
		if ( Message[ 0 ] )
		{
			AddMessageToQue( &Message[ 0 ] );
		}
	}
	
	return 0;
}

/*�����������������������������������������������������������������������
	Procedure	:	InitShipRandomStartPos
	Input		:	int16 which Ship
	Output		:	Nothing
����������������������������������������������������������������������*/
void InitShipRandomPos( int16 i )
{
	int16	e;
	int16	Count;
	int16	orgtry;
	int16	trys;
	uint16	startpos;
	VECTOR	MineVec;

	Ships[i].Object.NodeNetwork = 1;
	Ships[i].Object.NearestNode = NULL;
	Ships[i].Object.Type = OBJECT_TYPE_SHIP;

	JustGenerated = TRUE;
	Ships[i].Object.Shield = Start_Shield;
	Ships[i].Object.Hull	= Start_Hull;
	Ships[i].Object.Angle.x = 0.0F;
	Ships[i].Object.Angle.y = 0.0F;
	Ships[i].Object.Angle.z = 0.0F;
	Ships[i].Object.Speed.x = 0.0F;
	Ships[i].Object.Speed.y = 0.0F;
	Ships[i].Object.Speed.z = 0.0F;
	Ships[i].Object.CruiseControl = CRUISE_NORMAL;
	Ships[i].Object.PowerLevel = 0;
	Ships[i].Object.Flags = 0;
	Ships[i].StealthTime = 0.0F;
	Ships[i].NumMultiples = 0;
	Ships[i].Primary = PULSAR;
	Ships[i].Secondary = MUGMISSILE;
	for( Count = 0; Count < MAXMULTIPLES; Count++ ) Ships[i].OrbModels[ Count ] = (uint16) -1;
	Ships[i].NumMultiples = 0;

	RestoreWeapons();
	RestoreAmmo();

	if( Mloadheader.state == TRUE )
	{
		if( num_start_positions >= 2 )
		{
			orgtry = Random_Range( num_start_positions );
			// pick a random startpos to try first then try all others..

			
#if 0
			for( e = 0 ; e < num_start_positions ; e++ )
			{
				trys = ( orgtry + e ) % num_start_positions;
				
				MineVec.x = StartPositions[trys].Pos.x;
				MineVec.y = StartPositions[trys].Pos.y;
				MineVec.z = StartPositions[trys].Pos.z;
				
				if(	!IsStartPosVacantMutualyVisibleGroup( i , trys ) &&
					!CheckForMines( &MineVec) &&
					!CheckForGravgons( &MineVec ) )
				{
					// Found a vacant one
					InitShipStartPos( i, trys );
					return;
				}

			}
#endif
			for( e = 0 ; e < num_start_positions ; e++ )
			{
				trys = ( orgtry + e ) % num_start_positions;

				MineVec.x = StartPositions[trys].Pos.x;
				MineVec.y = StartPositions[trys].Pos.y;
				MineVec.z = StartPositions[trys].Pos.z;
				
				if(	!IsStartPosVacantVisibleGroup( i , trys ) &&
					!CheckForMines( &MineVec) &&
					!CheckForGravgons( &MineVec ) )
				{
					// Found a vacant one
					InitShipStartPos( i, trys );
					return;
				}
			}
			for( e = 0 ; e < num_start_positions ; e++ )
			{
				trys = ( orgtry + e ) % num_start_positions;

				MineVec.x = StartPositions[trys].Pos.x;
				MineVec.y = StartPositions[trys].Pos.y;
				MineVec.z = StartPositions[trys].Pos.z;
				
				if( !IsStartPosVacant( i , trys ) &&
					!CheckForMines( &MineVec) &&
					!CheckForGravgons( &MineVec ) )
				{
					// Found a vacant one
					InitShipStartPos( i, trys );
					return;
				}
			}
		}
		
		// 1 last try...
		startpos = Random_Range( num_start_positions );
		InitShipStartPos( i, startpos );
	}
}


/*�����������������������������������������������������������������������
	Procedure	:	InitShipStartPos
	Input		:	int16 which Ship
					int16 which pos
	Output		:	Nothing
����������������������������������������������������������������������*/
void InitShipStartPos( int16 i, int16 pos )
{
	uint16 startpos;
	VECTOR	MineVec;
	VECTOR	Start_Dir;
	VECTOR	Start_Up;
	VECTOR	Start_Right;
	VECTOR	Ship_Up;
	QUAT	ZQuat;
#ifdef FUDGE_AUTOLEVEL
	QUAT	StepQuat;
	int		j;
	float	autolevel;
#endif
	JustGenerated = TRUE;

	// for patch, only single player requires CD
	if ( ( (MyGameStatus==STATUS_SinglePlayer) || (MyGameStatus==STATUS_StartingSinglePlayer) )
		&& !ValidCD() )
	{
		Msg( "Forsaken CD required" );
		SeriousError = TRUE;
	}

	if( (MyGameStatus==STATUS_SinglePlayer) || (MyGameStatus==STATUS_StartingSinglePlayer) )
	{
		// Were in a Single Player Game so We start from the last start point we visited....
		pos = last_start_position;
	}


#if 0
	Ships[i].Shield = Start_Shield;
	Ships[i].Hull	= Start_Hull;
	Ships[i].Angle.x = 0.0F;
	Ships[i].Angle.y = 0.0F;
	Ships[i].Angle.z = 0.0F;
	Ships[i].PowerLevel = 0;
	Ships[i].Flags = 0;
	Ships[i].NumMultiples = 0;
	Ships[i].StealthTime = 0.0F;
	Ships[i].Primary = PULSAR;
	Ships[i].Secondary = MUGMISSILE;
	Ships[i].light = (uint16) -1;
	RestoreWeapons();
	RestoreAmmo();
#endif
	MakeQuat( 0.0F, 0.0F, 0.0F, &Ships[i].Object.Quat );
	MakeQuat( 0.0F, 0.0F, 0.0F, &Ships[i].Object.RotationForce );
	Start_Dir.x = 0.0F;
	Start_Dir.y = 0.0F;
	Start_Dir.z = -1.0F;

	if( Mloadheader.state == TRUE )
	{
		startpos = pos % num_start_positions;
		MineVec.x = StartPositions[startpos].Pos.x;
		MineVec.y = StartPositions[startpos].Pos.y;
		MineVec.z = StartPositions[startpos].Pos.z;
		
		Ships[i].Object.Pos.x = StartPositions[startpos].Pos.x;
		Ships[i].Object.Pos.y = StartPositions[startpos].Pos.y;			
		Ships[i].Object.Pos.z = StartPositions[startpos].Pos.z;
		Start_Dir = StartPositions[ startpos ].Dir;
#if 0
		Start_Dir.x = -Start_Dir.x;
		Start_Dir.y = -Start_Dir.y;
		Start_Dir.z = -Start_Dir.z;
		QuatFromVector2( &Start_Dir, &Ships[i].Quat );
#else
		QuatFrom2Vectors( &Ships[i].Object.Quat, &Forward, &Start_Dir );
#endif
		Ships[i].Object.Group = StartPositions[startpos].Group;
	}else{
		Ships[i].Object.Pos.x = -1.0F;
		Ships[i].Object.Pos.y = -1.0F;
		Ships[i].Object.Pos.z = -1.0F;
		Ships[i].Object.Group = 0;
	}
	QuatToMatrix( &Ships[i].Object.Quat, &Ships[i].Object.Mat );
	ApplyMatrix( &Ships[i].Object.Mat, &SlideUp, &Ship_Up );
#ifdef USE_ORIGINAL_STARTPOS_UP
	CrossProduct( &Start_Dir, &StartPositions[ startpos ].Up, &Start_Right );
#else
	CrossProduct( &Start_Dir, &Mloadheader.Group[ Ships[i].Object.Group ].up, &Start_Right );
#endif
	CrossProduct( &Start_Right, &Start_Dir, &Start_Up );
	QuatFrom2Vectors( &ZQuat, &Ship_Up, &Start_Up );
	QuatMultiply( &ZQuat, &Ships[i].Object.Quat, &Ships[i].Object.Quat );
#ifdef FUDGE_AUTOLEVEL
	QuatToMatrix( &Ships[i].Quat, &Ships[i].Mat ); // needed for AutoLevelRot() below
	
	// autolevel initial ship position
	for ( j = 0; j < 30; j++ )
	{
		autolevel = AutoLevelRot( i, 1.0F );
		if ( fabs( autolevel ) < 0.01 )
			break;
		MakeQuat( 0.0F, 0.0F, autolevel, &StepQuat );
		QuatMultiply(  &Ships[i].Quat , &StepQuat , &Ships[i].Quat );
		QuatToMatrix( &Ships[i].Quat, &Ships[i].Mat );
	}
	DebugPrintf( "autolevel = %f after %d iterations\n", autolevel, j );
#endif
	// reset external and internal force vectors to ship movement
	
	Ships[i].Object.ExternalForce.x = 0.0F;
	Ships[i].Object.ExternalForce.y = 0.0F;
	Ships[i].Object.ExternalForce.z = 0.0F;
	Ships[i].Object.InternalForce.x = 0.0F;
	Ships[i].Object.InternalForce.y = 0.0F;
	Ships[i].Object.InternalForce.z = 0.0F;

	Ships[i].Object.Autolevel = 0.0F;
	Ships[i].Object.BobCount = 0.0F;

	FindNearestNode( &Ships[i].Object );

	if ( i == WhoIAm )
		FB_Start();
}



/*�����������������������������������������������������������������������
	Procedure	:	GotoRoom
	Input		:	int16	which ship
					char *	roomname
	Output		:	TRUE if room found, FALSE otherwise
����������������������������������������������������������������������*/
BOOL GotoRoom( int16 i, char *roomname )
{
	uint16 startpos;
	VECTOR	MineVec;
	VECTOR	Start_Pos;
	VECTOR	Start_Dir;
	VECTOR	Start_Up;
	VECTOR	Start_Right;
	VECTOR	Ship_Up;
	QUAT	ZQuat;
	int16	group;

	if( Mloadheader.state == TRUE )
	{
		for ( group = 0; group < Mloadheader.num_groups; group++ )
		{
			if ( !_stricmp( roomname, Mloadheader.Group[ ( Ships[i].Object.Group + group ) % Mloadheader.num_groups ].name ) )
				break;
		}
		if ( group >= Mloadheader.num_groups )
			return FALSE;
		group = ( Ships[i].Object.Group + group ) % Mloadheader.num_groups;
		for ( startpos = 0; startpos < num_start_positions; startpos++ )
		{
			if ( StartPositions[startpos].Group == group )
				break;
		}
		if ( startpos < num_start_positions )
		{
			Start_Pos = StartPositions[startpos].Pos;
			Start_Up = StartPositions[ startpos ].Up;
			Start_Dir = StartPositions[ startpos ].Dir;
		}
		else
		{
			Start_Pos.x = Mloadheader.Group[group].center.x;
			Start_Pos.y = Mloadheader.Group[group].center.y;
			Start_Pos.z = Mloadheader.Group[group].center.z;
			Start_Up.x = 0.0F;
			Start_Up.y = 1.0F;
			Start_Up.z = 0.0F;
			Start_Dir.x = 0.0F;
			Start_Dir.y = 0.0F;
			Start_Dir.z = -1.0F;
		}
		MakeQuat( 0.0F, 0.0F, 0.0F, &Ships[i].Object.Quat );
		MakeQuat( 0.0F, 0.0F, 0.0F, &Ships[i].Object.RotationForce );
#if 0
		Start_Dir.x = -Start_Dir.x;
		Start_Dir.y = -Start_Dir.y;
		Start_Dir.z = -Start_Dir.z;
		QuatFromVector2( &Start_Dir, &Ships[i].Quat );
#else
		QuatFrom2Vectors( &Ships[i].Object.Quat, &Forward, &Start_Dir );
#endif
		Ships[i].Object.Group = group;
	}else{
		return FALSE;
	}
	MineVec.x = Start_Pos.x;
	MineVec.y = Start_Pos.y;
	MineVec.z = Start_Pos.z;
	Ships[i].Object.Pos.x = Start_Pos.x;
	Ships[i].Object.Pos.y = Start_Pos.y;			
	Ships[i].Object.Pos.z = Start_Pos.z;
	QuatToMatrix( &Ships[i].Object.Quat, &Ships[i].Object.Mat );
	ApplyMatrix( &Ships[i].Object.Mat, &SlideUp, &Ship_Up );
	CrossProduct( &Start_Dir, &Start_Up, &Start_Right );
	CrossProduct( &Start_Right, &Start_Dir, &Start_Up );
	QuatFrom2Vectors( &ZQuat, &Ship_Up, &Start_Up );
	QuatMultiply( &ZQuat, &Ships[i].Object.Quat, &Ships[i].Object.Quat );
	
	// reset external and internal force vectors to ship movement
	
	Ships[i].Object.ExternalForce.x = 0.0F;
	Ships[i].Object.ExternalForce.y = 0.0F;
	Ships[i].Object.ExternalForce.z = 0.0F;
	Ships[i].Object.InternalForce.x = 0.0F;
	Ships[i].Object.InternalForce.y = 0.0F;
	Ships[i].Object.InternalForce.z = 0.0F;

	Ships[i].Object.Autolevel = 0.0F;
	Ships[i].Object.BobCount = 0.0F;

	return TRUE;
}



/*�����������������������������������������������������������������������
	Procedure	:	Ship Mode 0	Normal Ship...
	Input		:	int16 which Ship
	Output		:	Nothing
����������������������������������������������������������������������*/
void ShipMode0( GLOBALSHIP * ShipPnt , BYTE i )
{

	// make sure the white out stuff is reset..
	WhiteOut = 0.0F;
	
	//			Handle all the Input Stuff
	control_ship( player_config, &control );
	
	ShipPnt->Object.Angle.x += control.pitch;
	ShipPnt->Object.Angle.y += control.yaw;
	ShipPnt->Object.Angle.z += control.roll;
	
	ShipPnt->Object.Bank	 += control.bank;

	ShipPnt->Object.CruiseControl += control.cruise_control;
	if ( ShipPnt->Object.CruiseControl > CRUISE_NITRO )
		ShipPnt->Object.CruiseControl = CRUISE_NITRO;
	else if ( ShipPnt->Object.CruiseControl < CRUISE_REVERSE )
		ShipPnt->Object.CruiseControl = CRUISE_REVERSE;

	if ( control.forward )
	{
		ShipPnt->Object.Speed.z += control.forward;
	}
	else
	{
		switch( ShipPnt->Object.CruiseControl )
		{
		case CRUISE_NORMAL: // normal control
			ShipPnt->Object.Speed.z += control.forward;
			break;
		case CRUISE_FORWARD: // full speed ahead
			ShipPnt->Object.Speed.z += MoveAccell * MaxMoveSpeed * framelag;
			break;
		case CRUISE_NITRO: // nitro ahead
			if ( NitroFuel )
			{
				if ( control.cruise_control > 0 )
					PlaySfx( SFX_NitroStart, 0.66F );
				ShipPnt->Object.Speed.z += TurboAccell * MaxTurboSpeed * framelag;
			}
			else
			{
				ShipPnt->Object.Speed.z += MoveAccell * MaxMoveSpeed * framelag;
				ShipPnt->Object.CruiseControl = CRUISE_FORWARD;
			}
			break;
		case CRUISE_REVERSE: // full speed reverse
			ShipPnt->Object.Speed.z -= MoveAccell * MaxMoveSpeed * framelag;
			break;
		}
	}
	
	ShipPnt->Object.Speed.x += control.right;
	ShipPnt->Object.Speed.y += control.up;
}

/*�����������������������������������������������������������������������
	Procedure	:	Ship Mode 1	Death Mode...
	Input		:	int16 which Ship
	Output		:	Nothing
����������������������������������������������������������������������*/
void ShipMode1( GLOBALSHIP * ShipPnt , BYTE i )
{
	VECTOR	Move_Dir;
	VECTOR	Move_Off;
	VECTOR	ScatterDir;
	BOOL	Impact = FALSE;

	control_ship( NULL, &control );
	// fudge to stop you turboing while your dieing...
	control.turbo = 0;
	ShipPnt->Object.CruiseControl = CRUISE_NORMAL;

	// if timer is 0 then set up remote Camera....	
	if( ShipPnt->Timer == 0 )
	{
		Ships[MAX_PLAYERS].enable = 1;
		Ships[MAX_PLAYERS].Object.Angle.x = 0.0F;
		Ships[MAX_PLAYERS].Object.Angle.y = 0.0F;
		Ships[MAX_PLAYERS].Object.Angle.z = 0.0F;

		Move_Off = ShipPnt->Move_Off;

		if( Move_Off.x < 1.0F && Move_Off.x > -1.0F &&
			Move_Off.y < 1.0F && Move_Off.y > -1.0F &&
			Move_Off.z < 1.0F && Move_Off.z > -1.0F )
		{
			// The Camera cant end up in exactly the same position as the ship....
			Move_Off.z = 1.0F;
		}
		NormaliseVector(&Move_Off);

		Move_Off.x = Move_Off.x * -(512.0F*GLOBAL_SCALE);
		Move_Off.y = Move_Off.y * -(512.0F*GLOBAL_SCALE);
		Move_Off.z = Move_Off.z * -(512.0F*GLOBAL_SCALE);
		Ships[MAX_PLAYERS].Object.Pos = ShipPnt->Object.Pos;
		Ships[MAX_PLAYERS].Object.Group = ShipPnt->Object.Group;
		
		ObjectCollide( &Ships[ MAX_PLAYERS ].Object, &Move_Off, SHIP_RADIUS, NULL );
		Ships[MAX_PLAYERS].Object.Mode = DEATH_MODE;
		if( Ships[MAX_PLAYERS].Object.Pos.x == Ships[WhoIAm].Object.Pos.x &&
			Ships[MAX_PLAYERS].Object.Pos.y == Ships[WhoIAm].Object.Pos.y &&
			Ships[MAX_PLAYERS].Object.Pos.z == Ships[WhoIAm].Object.Pos.z )
		{
			// The Camera cant end up in exactly the same position as the ship....
			Ships[MAX_PLAYERS].Object.Pos.x += 1.0F;
			Ships[MAX_PLAYERS].Object.Pos.y += 1.0F;
			Ships[MAX_PLAYERS].Object.Pos.z += 1.0F;
		}


		ApplyMatrix( &Ships[WhoIAm].Object.Mat, &SlideUp, &Move_Dir );			/* Calc Direction Vector */
		MakeViewMatrix( &Ships[MAX_PLAYERS].Object.Pos, &Ships[WhoIAm].Object.Pos, &Move_Dir, &Ships[MAX_PLAYERS].Object.FinalMat);
		MatrixTranspose( &Ships[MAX_PLAYERS].Object.FinalMat, &Ships[MAX_PLAYERS].Object.FinalInvMat );


		ShipPnt->Object.ExternalForce.x = ShipPnt->Move_Off.x;
		ShipPnt->Object.ExternalForce.y = ShipPnt->Move_Off.y;
		ShipPnt->Object.ExternalForce.z = ShipPnt->Move_Off.z;

		Current_Camera_View = MAX_PLAYERS;
		OldDrawPanel = DrawPanel;
		DrawPanel = FALSE;
		RearCameraDisable = TRUE;
	}
	
	ShipPnt->Timer -= framelag;

	ShipPnt->Object.Angle.y += ( MaxTurnSpeed * 0.04F ) * framelag;
	ShipPnt->Object.Angle.x += ( MaxTurnSpeed * 0.03F ) * framelag;
	ShipPnt->Object.Angle.z += ( MaxTurnSpeed * 0.02F ) * framelag;
	Impact = CarryonDeathMove( ShipPnt , i );

	if( (ShipPnt->Timer < -120.0F) || Impact )
	{
		if( !IsServerGame )
		{
			ScatterDir = ShipPnt->LastMove;
			NormaliseVector( &ScatterDir );
			ScatterWeapons( &ScatterDir, MAXSCATTERED );		// Scatter weapons in all directions.
		}
		else
		{
			ShortScatterWeapons();
		}

		CreateShockwave( OWNER_SHIP, WhoIAm, &Ships[ WhoIAm ].Object.Pos, Ships[ WhoIAm ].Object.Group, 6.0F, (BYTE) -1 );
		CreateShockwaveSend( OWNER_SHIP, WhoIAm, &Ships[ WhoIAm ].Object.Pos, Ships[ WhoIAm ].Object.Group, 6.0F, (BYTE) -1 );

		ShipPnt->Object.Mode = LIMBO_MODE;
		FB_Stop();

		if( GoreGuts ) ThrowOutRider( i );
		PlayPannedSfx( SFX_BikeExplode, Ships[ WhoIAm ].Object.Group , &Ships[WhoIAm].Object.Pos, 0.0F );
		StopTaunt();
	}
	else
	{
		if( !Random_Range( 8 ) )
		{
			CreateSingleExplosion( &ShipPnt->Object.Pos, ShipPnt->Object.Group );
		}
	}
}
/*�����������������������������������������������������������������������
	Procedure	:	Ship Mode 2	Limbo Mode...
	Input		:	int16 which Ship
	Output		:	Nothing
����������������������������������������������������������������������*/
void ShipMode2( GLOBALSHIP * ShipPnt , BYTE i )
{
	if( GodMode )
	{
		Current_Camera_View = WhoIAm;		// set it back to me...
		Ships[MAX_PLAYERS].enable = 0;		// Turn Off the remote camera...
		ShipMode0( ShipPnt , i );
	}else{
		Current_Camera_View = MAX_PLAYERS;	// set it back to Remote Camera..
		Ships[MAX_PLAYERS].enable = 1;		// Turn Off the remote camera...
		ShipPnt->Timer -= framelag;
		WhiteOut += framelag;
		if( WhiteOut >= 512.0F )
			WhiteOut = 512.0F;
		if( ShipPnt->Timer < -250.0F )
			ShipPnt->Timer = -251.0F;

		if( ( ShipPnt->Timer < -250.0F ) && ( AnyKeyReleased() != 0 ) )
		{
			if( MyGameStatus == STATUS_SinglePlayer )
			{
				if( Lives == 0 )
				{
					AddMessageToQue( NO_LIVES_LEFT );
					ShipPnt->Timer = 0.0F;
					ShipPnt->Object.Mode = GAMEOVER_MODE;
					PlaySfx( SFX_BIKER_LP, 1.0F );
					return;
				}
				Lives--;
				if( Lives == 0 )
				{
					AddMessageToQue( LAST_LIFE );
				}else{
					if( Lives == 1 )
					{
						AddMessageToQue( ONE_LIFE_LEFT , Lives );
					}else{
						AddMessageToQue( LIVES_LEFT, Lives );
					}
				}
			}
			WhiteOut = 0.0F;
			InitShipRandomPos( i );
			JustGenerated = TRUE;
			ShipPnt->Object.Mode = NORMAL_MODE;
			ShipPnt->InvulTimer = RGENINVULTIME;		// approx 1 second of invulnerability...			
			ShipPnt->Invul = TRUE;
			ShipPnt->Deaths++;
			PlaySfx( SFX_PlayerGenerate, 1.0F );
			
			// play a general biker phrase on respawning, but only in single player
			if( MyGameStatus == STATUS_SinglePlayer )
			{
				PlaySfx( SFX_BIKER_GP, 1.0F );
			}

			Ships[MAX_PLAYERS].enable = 0;		// Turn Off the remote camera...
			Current_Camera_View = WhoIAm;		// set it back to me...
			flush_input = TRUE;
			control_ship( player_config, &control );
		}
		else
		{
			control_ship( NULL, &control ); // clear ship controls
		}
	}
}
/*�����������������������������������������������������������������������
	Procedure	:	Ship Mode 4	Game over mode...
	Input		:	int16 which Ship
	Output		:	Nothing
����������������������������������������������������������������������*/
void ShipMode4( GLOBALSHIP * ShipPnt , BYTE i )
{
	Current_Camera_View = MAX_PLAYERS;	// set it back to Remote Camera..
	Ships[MAX_PLAYERS].enable = 1;		// Turn On the remote camera...
	ShipPnt->Timer -= framelag;
	WhiteOut += framelag;
	if( WhiteOut >= 512.0F )
		WhiteOut = 512.0F;
	if( ( ShipPnt->Timer < -120.0F ) && ( AnyKeyReleased() != 0 ) )
	{
		ShipPnt->Timer = -121.0F;
		// All Lives have been lost.......
		SpecialDestroyGame();

		NumGoldBars = 0;
		CrystalsFound = 0;
	}
}


/*�����������������������������������������������������������������������
	Procedure	:	What the Remote Camera Does...
	Input		:	Nothing
	Output		:	Nothing
����������������������������������������������������������������������*/
void Process_Remote_Camera( void )
{
 	( * RemoteCameraModeControl[ Ships[MAX_PLAYERS].Object.Mode ] )( &Ships[MAX_PLAYERS] , MAX_PLAYERS );		//go off and do his thing...
}

/*�����������������������������������������������������������������������
	Procedure	:	Remote Camera Mode 0	Normal Ship...
	Input		:	int16 which Ship
	Output		:	Nothing
����������������������������������������������������������������������*/
void RemoteCameraMode0( GLOBALSHIP * ShipPnt , BYTE i )
{
	VECTOR	Move_Dir;
	VECTOR	Move_Dir2;
	VECTOR	temp;
	float	Speed;

	VECTOR	ImpactPoint;
	VECTOR	Move_Off;	
	VECTOR	Pos_New;	
	uint16	ImpactGroup;
	NORMAL	FaceNormal;

	if( !DebugInfo )
	{
		temp.x = ShipPnt->Object.Pos.x - Ships[WhoIAm].Object.Pos.x; 
		temp.y = ShipPnt->Object.Pos.y - Ships[WhoIAm].Object.Pos.y; 
		temp.z = ShipPnt->Object.Pos.z - Ships[WhoIAm].Object.Pos.z;
		if( (float) sqrt( (temp.x*temp.x) + (temp.y*temp.y) + (temp.z*temp.z) ) <= (SHIP_RADIUS+(SHIP_RADIUS*0.5F) ) )
		{
			Current_Camera_View = WhoIAm;
		}else{
			Current_Camera_View = i;
		}
		
		Move_Dir.x = ShipPnt->Object.Pos.x - Ships[WhoIAm].Object.Pos.x ;
		Move_Dir.y = ShipPnt->Object.Pos.y - Ships[WhoIAm].Object.Pos.y ;
		Move_Dir.z = ShipPnt->Object.Pos.z - Ships[WhoIAm].Object.Pos.z ;
		
		if ( Ships[WhoIAm].Object.Group != (uint16) -1 )
		{
			if( BackgroundCollide( &MCloadheadert0, &Mloadheader,
   										&Ships[WhoIAm].Object.Pos, Ships[WhoIAm].Object.Group, &Move_Dir,
										&ImpactPoint , &ImpactGroup, &FaceNormal, &Pos_New, TRUE, NULL ) == TRUE )
			{
				ShipPnt->Object.Pos.x = ImpactPoint.x;
				ShipPnt->Object.Pos.y = ImpactPoint.y;
				ShipPnt->Object.Pos.z = ImpactPoint.z;
				ShipPnt->Object.Group = ImpactGroup;
			}
		}
		
		ApplyMatrix( &Ships[WhoIAm].Object.Mat, &Forward, &Move_Dir );			/* Calc Direction Vector */
		ApplyMatrix( &Ships[WhoIAm].Object.Mat, &SlideUp, &Move_Dir2 );			/* Calc Direction Vector */
		
		Speed = 800.0F*GLOBAL_SCALE;
		Move_Dir.x = -( Move_Dir.x * Speed ) + ( Move_Dir2.x * 32.0F ) ;
		Move_Dir.y = -( Move_Dir.y * Speed ) + ( Move_Dir2.y * 32.0F );
		Move_Dir.z = -( Move_Dir.z * Speed ) + ( Move_Dir2.z * 32.0F );
		
		temp = Ships[WhoIAm].Object.Pos;
		NumCollides = 0;
		ImpactGroup = Ships[WhoIAm].Object.Group;
		if ( Ships[WhoIAm].Object.Group != (uint16) -1 )
		{
			while ( BackgroundCollide( &MCloadheader, &Mloadheader,
   										&temp, ImpactGroup, &Move_Dir,
   										&ImpactPoint , &ImpactGroup, &FaceNormal, &Pos_New, TRUE, NULL ) )
			{
				temp = ImpactPoint;
				Move_Dir.x = Pos_New.x - temp.x; 
				Move_Dir.y = Pos_New.y - temp.y; 
				Move_Dir.z = Pos_New.z - temp.z;
				NumCollides += 1;
				if( NumCollides	> MAXCOLLISIONS )
					break;
			}
		}
		temp = ImpactPoint;
		
		Move_Off.x = temp.x - ShipPnt->Object.Pos.x ;
		Move_Off.y = temp.y - ShipPnt->Object.Pos.y ;
		Move_Off.z = temp.z - ShipPnt->Object.Pos.z ;
		
		
		Speed = 0.15F;
		
		Move_Off.x = ( Move_Off.x * Speed )*framelag;
		Move_Off.y = ( Move_Off.y * Speed )*framelag;
		Move_Off.z = ( Move_Off.z * Speed )*framelag;
		// do collisions to background
		ObjectCollide( &ShipPnt->Object, &Move_Off, SHIP_RADIUS, NULL );
	}else{

		ApplyMatrix( &Ships[WhoIAm].Object.Mat, &Forward, &Move_Dir );			/* Calc Direction Vector */
		Speed = 800.0F*GLOBAL_SCALE;
		
		ShipPnt->Object.Group = Ships[WhoIAm].Object.Group;
		ShipPnt->Object.Pos.x = Ships[WhoIAm].Object.Pos.x - ( Move_Dir.x * Speed );
		ShipPnt->Object.Pos.y = Ships[WhoIAm].Object.Pos.y - ( Move_Dir.y * Speed );
		ShipPnt->Object.Pos.z = Ships[WhoIAm].Object.Pos.z - ( Move_Dir.z * Speed );

	}

	ApplyMatrix( &Ships[WhoIAm].Object.Mat, &SlideUp, &Move_Dir );			/* Calc Direction Vector */
	MakeViewMatrix( &ShipPnt->Object.Pos, &Ships[WhoIAm].Object.Pos, &Move_Dir, &ShipPnt->Object.FinalMat);
	MatrixTranspose( &ShipPnt->Object.FinalMat, &ShipPnt->Object.FinalInvMat );
}
/*�����������������������������������������������������������������������
	Procedure	:	Remote Camera Mode 1	Death Mode...
	Input		:	int16 which Ship
	Output		:	Nothing
����������������������������������������������������������������������*/
void RemoteCameraMode1( GLOBALSHIP * ShipPnt , BYTE i )
{
	VECTOR	Bob;
	VECTOR	Move_Off;
	VECTOR	NewPos;
	VECTOR	NewBob;
	VECTOR	Move_Dir;

	if( Ships[WhoIAm].Object.Mode != LIMBO_MODE )
	{
		ApplyMatrix( &ShipPnt->Object.FinalMat, &SlideUp, &Move_Dir );			/* Calc Direction Vector */
		MakeViewMatrix( &ShipPnt->Object.Pos, &Ships[WhoIAm].Object.Pos, &Move_Dir, &ShipPnt->Object.FinalMat);
		MatrixTranspose( &ShipPnt->Object.FinalMat, &ShipPnt->Object.FinalInvMat );
		return;
	}
	
	BobShip( i, &Bob );
	Move_Off.x = Bob.x - ShipPnt->Object.LastBob.x;
	Move_Off.y = Bob.y - ShipPnt->Object.LastBob.y;
	Move_Off.z = Bob.z - ShipPnt->Object.LastBob.z;
	ShipPnt->Object.LastBob = Bob;
	NewBob = Move_Off;
	NewPos.x = Ships[WhoIAm].Object.Pos.x + ( NewBob.x * (50.0F / framelag) );
	NewPos.y = Ships[WhoIAm].Object.Pos.y + ( NewBob.y * (50.0F / framelag) );
	NewPos.z = Ships[WhoIAm].Object.Pos.z + ( NewBob.z * (50.0F / framelag) );

	ApplyMatrix( &ShipPnt->Object.FinalMat, &SlideUp, &Move_Dir );			/* Calc Direction Vector */
	MakeViewMatrix( &ShipPnt->Object.Pos, &NewPos, &Move_Dir, &ShipPnt->Object.FinalMat);
	MatrixTranspose( &ShipPnt->Object.FinalMat, &ShipPnt->Object.FinalInvMat );

}




/*�������������������������������������������������������������������
	Procedure	:	Is there a Bike near this restart point...
	Input		:	nothing
	Output		:	FALSE/TRUE
�������������������������������������������������������������������*/
#ifdef USEINLINE
#ifdef FINAL_RELEASE
_inline
#endif
#endif
BOOL	IsStartPosVacant( int16 i , uint16 startpos )
{
	int	e;
	for( e = 0 ; e < MAX_PLAYERS ; e++ )
	{
		if( i != e )
		{
			if( GameStatus[e] == MyGameStatus )
			{
				if( DistanceVector2Vector( &StartPositions[startpos].Pos , &Ships[e].Object.Pos ) < ( BLOCKSIZE * 6.0F ) )
				{
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}
/*�������������������������������������������������������������������
	Procedure	:	Is there a Bike in a Mutually visible Group from this restart point...
	Input		:	nothing
	Output		:	FALSE/TRUE
�������������������������������������������������������������������*/
#ifdef USEINLINE
#ifdef FINAL_RELEASE
_inline
#endif
#endif
BOOL	IsStartPosVacantMutualyVisibleGroup( int16 i , uint16 startpos )
{
	int	e;
	for( e = 0 ; e < MAX_PLAYERS ; e++ )
	{
		if( i != e )
		{
			if( GameStatus[e] == MyGameStatus )
			{
				if( VisibleOverlap( Ships[ e ].Object.Group, StartPositions[startpos].Group , NULL ) )
				{
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}
/*�������������������������������������������������������������������
	Procedure	:	Is there a Bike in a visible group from this restart point...
	Input		:	nothing
	Output		:	FALSE/TRUE
�������������������������������������������������������������������*/
#ifdef USEINLINE
#ifdef FINAL_RELEASE
_inline
#endif
#endif
BOOL	IsStartPosVacantVisibleGroup( int16 i , uint16 startpos )
{
	int	e;
	for( e = 0 ; e < MAX_PLAYERS ; e++ )
	{
		if( i != e )
		{
			if( GameStatus[e] == MyGameStatus )
			{
				if( GroupsAreVisible( Ships[ e ].Object.Group, StartPositions[startpos].Group ) )
				{
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}


/*�����������������������������������������������������������������������
	Procedure	:	Remote Camera Mode 3	Demo Playback...
	Input		:	int16 which Ship
	Output		:	Nothing
����������������������������������������������������������������������*/
void RemoteCameraMode3( GLOBALSHIP * ShipPnt , BYTE i )
{
	framelag = Oldframelag;
	if ( DemoEyesSelect.value != MAX_PLAYERS )
	{
		int j, k;
		BOOL ok;

		// make sure we are looking through the eyes of a valid player in demo playback
		ok = FALSE;
		for ( j = 0; j < MAX_PLAYERS; j++ )
		{
			k = ( DemoEyesSelect.value + j ) % MAX_PLAYERS;
			if ( k != MAX_PLAYERS )
			{
				switch ( GameStatus[ k ] )
				{
				case STATUS_Joining:
				case STATUS_Left:
				case STATUS_LeftCrashed:
				case STATUS_Null:
					// skip players in invalid modes
					break;
				default:
					// any other mode is OK to use for demo playback
					DemoEyesSelect.value = k;
					ok = TRUE;
				}
				if ( ok )
					break;
			}
		}
	}
	Current_Camera_View = DemoEyesSelect.value;
	TeamNumber[ i ] = TeamNumber[ Current_Camera_View ];
	ShipMode0( ShipPnt , i );
}

/*�������������������������������������������������������������������
	Procedure	:	Update Nearest StartPos visited...
	Input		:	nothing
	Output		:	nothing
�������������������������������������������������������������������*/
void	UpdateStartPos( void )
{
	VECTOR	Temp;
	uint16	startpos;
	
	if( (MyGameStatus==STATUS_SinglePlayer) || (MyGameStatus==STATUS_StartingSinglePlayer) )
	{
		
		if( last_start_position >= num_start_positions )
		{
			last_start_position = 0;
		}

		startpos = FirstStartPositionInGroup[Ships[WhoIAm].Object.Group];
		
		while( startpos != (uint16) -1 )
		{
			if( ( startpos != last_start_position ) &&
				( StartPositions[startpos].Group != StartPositions[last_start_position].Group ) )
			{
				// There is a start position in the current group....Did I get close enough ??
				Temp.x = Ships[WhoIAm].Object.Pos.x - StartPositions[startpos].Pos.x;
				if( Temp.x < 0.0F )	Temp.x *= -1.0F;
				Temp.y =  Ships[WhoIAm].Object.Pos.y - StartPositions[startpos].Pos.y;
				if( Temp.y < 0.0F )	Temp.y *= -1.0F;
				Temp.z =  Ships[WhoIAm].Object.Pos.z - StartPositions[startpos].Pos.z;
				if( Temp.z < 0.0F )	Temp.z *= -1.0F;
				if ( (Temp.x <= SHIP_RADIUS * 4.0F ) &&
					(Temp.y <= SHIP_RADIUS * 4.0F ) &&
					(Temp.z <= SHIP_RADIUS * 4.0F ) )
				{
					ActivateRestartPoint( startpos, last_start_position );

					PlaySfx( SFX_RestartPointReached, 1.0F );
					AddMessageToQue( RESTART_ACTIVATED );
					last_start_position = startpos;
					return;
				}
			}
			startpos = StartPositions[startpos].NextInGroup;
		}
	}else{
		last_start_position = 0;
	}
}
/*�������������������������������������������������������������������
	Procedure	:	Start Screen Shake...
	Input		:	float Time;
	Output		:	nothing
�������������������������������������������������������������������*/
void StartShipScreenShake( float Force )
{
	Ships[WhoIAm].ShakeTimer = 2.0F * 60.0F;
	Ships[WhoIAm].ShakeForce = Force;
}
/*�������������������������������������������������������������������
	Procedure	:	Stop Screen Shake...
	Input		:	float Time;
	Output		:	nothing
�������������������������������������������������������������������*/
void StopShipScreenShake( void )
{
	Ships[WhoIAm].ShakeTimer = 0.0F;
}


/*�������������������������������������������������������������������
	Procedure	:	Set Bike Mods...
	Input		:	BikeNumber..
	Output		:	nothing
�������������������������������������������������������������������*/
void SetBikeMods( uint16 Bike )
{
	if( Bike >= MAXBIKETYPES+3 )
		return;
	MaxMoveSpeed	=	BikeMods[Bike].MaxMoveSpeed;
	MoveAccell		=	BikeMods[Bike].MoveAccell;	  
	MoveDecell		=	BikeMods[Bike].MoveDecell;	  
	MaxTurboSpeed   =	BikeMods[Bike].MaxTurboSpeed;   
	TurboAccell		=	BikeMods[Bike].TurboAccell;	  	
	TurboDecell		=	BikeMods[Bike].TurboDecell;	  	
	MaxTurnSpeed	=	BikeMods[Bike].MaxTurnSpeed; 
	TurnAccell		=	BikeMods[Bike].TurnAccell;	  
	TurnDecell		=	BikeMods[Bike].TurnDecell;	  
	MaxRollSpeed	=	BikeMods[Bike].MaxRollSpeed;  
	RollAccell		=	BikeMods[Bike].RollAccell;	  
	RollDecell		=	BikeMods[Bike].RollDecell;	  
	MaxBankAngle    =	BikeMods[Bike].MaxBankAngle;    
	BankAccell		=	BikeMods[Bike].BankAccell;	  
	BankDecell		=	BikeMods[Bike].BankDecell;	  
	Start_Shield	=	BikeMods[Bike].Start_Shield;
	Start_Hull		=	BikeMods[Bike].Start_Hull;	
	AutoLevel		=	BikeMods[Bike].AutoLevel;	
}

/*�������������������������������������������������������������������
	Procedure	:	Ship 2 Ship collide...
	Input		:	BikeNumber..
	Output		:	Move_Off filled in...
�������������������������������������������������������������������*/
BOOL Ship2ShipCollide( uint16 i , VECTOR * Move_Off )
{
	uint16 Count;
	float Move_Length;
	float Next_Move_Length;
	VECTOR Move_Dir;
	float OldMove;
	VECTOR	inter;
	VECTOR	inter2;
	VECTOR	Norm_Move_Off;
	VECTOR	Temp_Move_Off;
	VECTOR	NewPos;
	BOOL	HasBeen = FALSE;
	BOOL	ok;
	uint16	NewGroup;

	if( IsServer )
		return FALSE;
	
	Norm_Move_Off = *Move_Off;
	NormaliseVector( &Norm_Move_Off );
	OldMove = VectorLength( &Ships[i].Move_Off);
	
	for( Count = 0; Count < MAX_PLAYERS; Count++ )
	{
		
		if ( (Ships[Count].enable != 0) && (Ships[Count].Object.Mode != LIMBO_MODE) && (Ships[Count].Object.Mode != GAMEOVER_MODE) && ((GameStatus[Count] == STATUS_Normal )||(GameStatus[Count] == STATUS_SinglePlayer ) ) &&
			 ( Count != i ) )//&& ( VectorLength( &Ships[Count].Move_Off) <= OldMove) && !( ( OldMove == 0.0F ) && (VectorLength( &Ships[Count].Move_Off) == 0.0F ) ) )
		{
			ok = FALSE;
			if( Ships[Count].Object.Group != Ships[i].Object.Group )
			{
				// if ship are in different groups then we must do a move group to see if they end up in the same group...
				Move_Dir.x = Ships[Count].Object.Pos.x - Ships[i].Object.Pos.x;
				Move_Dir.y = Ships[Count].Object.Pos.y - Ships[i].Object.Pos.y;
				Move_Dir.z = Ships[Count].Object.Pos.z - Ships[i].Object.Pos.z;
				NewGroup = MoveGroup( &Mloadheader, &Ships[i].Object.Pos, Ships[i].Object.Group, &Move_Dir );
				if( NewGroup == Ships[Count].Object.Group )
					ok = TRUE;
			}else{
				ok = TRUE;
			}

			if( ok )
			{
				Move_Length = DistanceVector2Vector( &Ships[i].Object.Pos , &Ships[Count].Object.Pos );

				NewPos.x = Ships[i].Object.Pos.x + Move_Off->x;
				NewPos.y = Ships[i].Object.Pos.y + Move_Off->y;
				NewPos.z = Ships[i].Object.Pos.z + Move_Off->z;

				Next_Move_Length = DistanceVector2Vector( &NewPos , &Ships[Count].Object.Pos );
				
				if( (Move_Length < ( SHIP_RADIUS*2.0F ) ) && ( Next_Move_Length < Move_Length ) )
				{
					if( Move_Length < 1.0F )
						Move_Length = 1.0F;
		
					// the ships are to close....Move them apart...Guarenteed..
					Move_Dir.x = Ships[i].Object.Pos.x - Ships[Count].Object.Pos.x;
					Move_Dir.y = Ships[i].Object.Pos.y - Ships[Count].Object.Pos.y;
					Move_Dir.z = Ships[i].Object.Pos.z - Ships[Count].Object.Pos.z;
					NormaliseVector( &Move_Dir );

					Move_Length = ( (SHIP_RADIUS*2.0F)+1.0F ) - Move_Length;

	//				if( Move_Length >= (SHIP_RADIUS * 0.1F) )
	//					Move_Length = (SHIP_RADIUS * 0.1F);
					if( Move_Dir.x == 0.0F && Move_Dir.y == 0.0F && Move_Dir.z == 0.0F )
						return FALSE;
					Move_Off->x = Move_Dir.x * Move_Length;
					Move_Off->y = Move_Dir.y * Move_Length;
					Move_Off->z = Move_Dir.z * Move_Length;
	//				Ships[i].Object.Speed.x = 0.0F;
	//				Ships[i].Object.Speed.y = 0.0F;
	//				Ships[i].Object.Speed.z = 0.0F;


					return TRUE;
				}else{
	#if 1
					if( RaytoSphere2( &Ships[Count].Object.Pos, (SHIP_RADIUS*2.0F)-2.0F, &Ships[i].Object.Pos, &Norm_Move_Off, &inter, &inter2 ) )
					{
						Temp_Move_Off.x = inter.x - Ships[i].Object.Pos.x;
						Temp_Move_Off.y = inter.y - Ships[i].Object.Pos.y;
						Temp_Move_Off.z = inter.z - Ships[i].Object.Pos.z;
						if( VectorLength( &Temp_Move_Off) < VectorLength( Move_Off) )
						{
							*Move_Off = Temp_Move_Off;
							Norm_Move_Off = *Move_Off;
							NormaliseVector( &Norm_Move_Off );
							HasBeen = TRUE;
						}
					}
	#endif
				}
			}
		}
	}
	return HasBeen;
}
#if 1
BOOL CarryonDeathMove( GLOBALSHIP * ShipPnt,BYTE i)
{
	VECTOR	Move_Off;	
	QUAT	StepQuat;	
	BGOBJECT * BGObject;
	float	ShieldModifier;
	uint32	OldInWater;
	BOOL Impact = FALSE;

	AccellDecell( &ShipPnt->Object.Angle.y , TurnDecell );
	AccellDecell( &ShipPnt->Object.Angle.x , TurnDecell );
	AccellDecell( &ShipPnt->Object.Angle.z , RollDecell );

	MakeQuat( ShipPnt->Object.Angle.x * framelag, ShipPnt->Object.Angle.y * framelag, ShipPnt->Object.Angle.z * framelag + ShipPnt->Object.Autolevel, &StepQuat );
	QuatMultiply(  &ShipPnt->Object.Quat , &StepQuat , &ShipPnt->Object.Quat );
	QuatMultiply(  &ShipPnt->Object.RotationForce , &ShipPnt->Object.Quat , &ShipPnt->Object.Quat );
	QuatToMatrix( &ShipPnt->Object.Quat, &ShipPnt->Object.Mat );
	MakeQuat( 0.0F, 0.0F, 0.0F, &ShipPnt->Object.RotationForce );

	// apply external and internal force vectors to ship movement
	Move_Off.x = ShipPnt->Object.ExternalForce.x * framelag;
	Move_Off.y = ShipPnt->Object.ExternalForce.y * framelag;
	Move_Off.z = ShipPnt->Object.ExternalForce.z * framelag;

	ShipPnt->Object.ExternalForce.x -= Mloadheader.Group[ ShipPnt->Object.Group ].up.x * 0.01F * framelag;
	ShipPnt->Object.ExternalForce.y -= Mloadheader.Group[ ShipPnt->Object.Group ].up.y * 0.01F * framelag;
	ShipPnt->Object.ExternalForce.z -= Mloadheader.Group[ ShipPnt->Object.Group ].up.z * 0.01F * framelag;

	if( (i != MAX_PLAYERS) && (ShipPnt->Object.Mode != LIMBO_MODE) )
	{
		if( Ship2ShipCollide(  i , &Move_Off ) )
			Impact = TRUE;
	}
	// Collide with the enemies....
	if( Ship2EnemyCollide( i , &Move_Off ) )
	{
		Impact = TRUE;
	}
		
	BGObject = NULL;
	if( ObjectCollide( &ShipPnt->Object, &Move_Off, SHIP_RADIUS, &BGObject ) )
		Impact = TRUE;
	if( BGObject ) ChangeBGState( BGObject, OWNER_SHIP, WhoIAm, BUMP, 0.0F );

	OldInWater = ShipPnt->Object.Flags & SHIP_InWater;
	ShipPnt->Object.Flags &= ~SHIP_InWater;
	if( InWater( ShipPnt->Object.Group , &ShipPnt->Object.Pos , &ShieldModifier) )
	{
		ShipPnt->Object.Flags |= SHIP_InWater;
	}else
	{
		// not in water, therefore stop underwater looping sfx if currently playing
		if ( UnderwaterSfxID )
		{
			StopSfx( UnderwaterSfxID );
		}
	}

	if ( framelag )
	{
		ShipPnt->Move_Off.x = Move_Off.x / framelag;
		ShipPnt->Move_Off.y = Move_Off.y / framelag;
		ShipPnt->Move_Off.z = Move_Off.z / framelag;
	}
	else
	{
		ShipPnt->Move_Off.x = 0.0F;
		ShipPnt->Move_Off.y = 0.0F;
		ShipPnt->Move_Off.z = 0.0F;
	}

	return Impact;
}
#endif




/*�������������������������������������������������������������������
	Procedure	:	Multiplayer Sfx handler...
	Input		:	Nothing..
	Output		:	Nothing..
�������������������������������������������������������������������*/
#define MAXKILLMEMORY 8
#define KILLSOVERTIME 5			// Number of kills to get....
#define TIMEKILLSOVER 60		// Length of time on seconds over which the kills have to have been made...
#define BADTIMEKILLSOVER 50		// if you go without a kill for this amoutn of time you get a taunt for your trouble...
#define	CAMPINGTIME 45			// how long you have to stay in 1 approx position...
#define	CAMPINGRANGE ( 1024.0F * GLOBAL_SCALE * 4.0F )	// Range for camping

BOOL MultiSfxTaunt1Off = FALSE;

uint16 CurrentKillPos = 0;
LONGLONG	KillMemoryTime[MAXKILLMEMORY];
int16		KillMemory[MAXKILLMEMORY];

LONGLONG	CampingPosTime;
VECTOR		CampingPos;
BOOL	CampingPos1Off = FALSE;


int16 OldKills = 0;

void MultiSfxHandle( void )
{
	int16	KillIndex;
	LONGLONG TempTime;
	BOOL	NewKill;

	if( MyGameStatus != STATUS_Normal || WhoIAm >= MAX_PLAYERS )
		return;

	NewKill = FALSE;

	if( Ships[WhoIAm].Kills > OldKills )
	{
		NewKill = TRUE;
		OldKills = Ships[WhoIAm].Kills;

	}
	QueryPerformanceCounter((LARGE_INTEGER *) &TempTime );
	TempTime = TempTime * 1000 / Freq;

	KillIndex = (CurrentKillPos - KILLSOVERTIME) & ( MAXKILLMEMORY -1 );
	if( (KillMemory[KillIndex] != -1)  && NewKill )
	{
		if( ( TempTime - KillMemoryTime[KillIndex] ) < ( 1000 * TIMEKILLSOVER ) )
		{
			// play congrat gloat thing...
			PlaySfx( SFX_BIKECOMP_MK, 1.0F );

			// Clear stuff out so it doesnt get played again..
			while( KillIndex != CurrentKillPos )
			{
				KillMemory[KillIndex] = -1;
				KillIndex += 1;
				KillIndex &= ( MAXKILLMEMORY -1 );
			}
		}
	}

	KillIndex = (CurrentKillPos - 1) & ( MAXKILLMEMORY -1 );
	if( ( TempTime - KillMemoryTime[KillIndex] ) > ( 1000 * BADTIMEKILLSOVER ) )
	{
		// play taunt for not getting a kill....in a long time...
		if( MultiSfxTaunt1Off )
		{
			PlaySfx( SFX_BIKECOMP_NK, 1.0F );
			CampingPosTime += 1000 * 5;
		}else{
			MultiSfxTaunt1Off = TRUE;
		}
		KillMemoryTime[KillIndex] = TempTime;
	}


	if( !CampingPos1Off )
	{
		CampingPosTime = TempTime;
		CampingPos1Off = TRUE;
		CampingPos = Ships[WhoIAm].Object.Pos;
	}else{

		if( DistanceVector2Vector( &CampingPos , &Ships[WhoIAm].Object.Pos ) < CAMPINGRANGE )
		{
			if( (TempTime - CampingPosTime) > (CAMPINGTIME * 1000) )
			{
				PlaySfx( SFX_BIKECOMP_CA, 1.0F );
				CampingPosTime = TempTime;
			}
		}else{
			CampingPosTime = TempTime;
			CampingPos = Ships[WhoIAm].Object.Pos;
		}
	}

}

/*�������������������������������������������������������������������
	Procedure	:	Makes a note of when the last kill was made..
	Input		:	Nothing..
	Output		:	Nothing..
�������������������������������������������������������������������*/
void AddKill( void )
{
	KillMemory[CurrentKillPos] = Ships[WhoIAm].Kills;
	QueryPerformanceCounter((LARGE_INTEGER *) &KillMemoryTime[CurrentKillPos]  );
	KillMemoryTime[CurrentKillPos] = KillMemoryTime[CurrentKillPos] * 1000 / Freq;
	CurrentKillPos++;
	if( CurrentKillPos >= MAXKILLMEMORY )
		CurrentKillPos = 0;
}


void InitMultiSfxHandle( void )
{
	int i;
	for( i = 0 ; i < MAXKILLMEMORY ; i ++ )
	{
		KillMemory[i] = -1;
		KillMemoryTime[i] = 0;
	}
	CurrentKillPos = 0;
	MultiSfxTaunt1Off = FALSE;

	CampingPos1Off = FALSE;
}

/*�������������������������������������������������������������������
	Procedure	:	Release All Componeted Ships
	Input		:	Nothing..
	Output		:	Nothing..
�������������������������������������������������������������������*/
void ReleaseComponentedShips( void )
{
	int16	Count;

	for( Count = 0; Count < MAX_PLAYERS; Count++ )
	{
		if( Ships[ Count ].Object.Components )
		{
			FreeCompObjChildren( Ships[ Count ].Object.Components, 1 );
			free( Ships[ Count ].Object.Components );
			Ships[ Count ].Object.Components = NULL;
			Ships[ Count ].ModelNum = (uint16) -1;
		}
		else
		{
			Ships[ Count ].ModelNum = (uint16) -1;
		}
	}
}

/*�������������������������������������������������������������������
	Procedure	:	Save Ship Array & Connected Global Variables
	Input		:	FILE	*	File Pointer
	Output		:	FILE	*	Updated File Pointer
�������������������������������������������������������������������*/
FILE * SaveShips( FILE * fp )
{
	uint16			i;
	COMP_OBJ	*	TempPtr = NULL;

	if( fp )
	{
		i = WhoIAm;

		Ships[ i ].Object.ID = &Ships[ i ];
		Ships[ i ].Object.Type = OBJECT_TYPE_SHIP;

		if( Ships[ i ].Object.Components )
		{
			TempPtr = Ships[ i ].Object.Components;
			Ships[ i ].Object.Components = NULL;
		}

		if( !Object_Save( fp , &Ships[ i ].Object ) )
		{
			if( TempPtr )
			{
				Ships[ i ].Object.Components = TempPtr;
				TempPtr = NULL;
			}

			fclose( fp );
			return( NULL );
		}

		if( TempPtr )
		{
			Ships[ i ].Object.Components = TempPtr;
			TempPtr = NULL;
		}
			
		fwrite( &Ships[ i ].enable, sizeof( Ships[ i ].enable ), 1, fp );
		fwrite( &Ships[ i ].ShipThatLastKilledMe, sizeof( Ships[ i ].ShipThatLastKilledMe ), 1, fp );
		fwrite( &Ships[ i ].ShipThatLastHitMe, sizeof( Ships[ i ].ShipThatLastHitMe ), 1, fp );
		fwrite( &Ships[ i ].NumMultiples, sizeof( Ships[ i ].NumMultiples ), 1, fp );
		fwrite( &Ships[ i ].StealthTime, sizeof( Ships[ i ].StealthTime ), 1, fp );
		fwrite( &Ships[ i ].Timer, sizeof( Ships[ i ].Timer ), 1, fp );
		fwrite( &Ships[ i ].InvulTimer, sizeof( Ships[ i ].InvulTimer ), 1, fp );
		fwrite( &Ships[ i ].Invul, sizeof( Ships[ i ].Invul ), 1, fp );
		fwrite( &Ships[ i ].LastAngle, sizeof( Ships[ i ].LastAngle ), 1, fp );
		fwrite( &Ships[ i ].Kills, sizeof( Ships[ i ].Kills ), 1, fp );
		fwrite( &Ships[ i ].Deaths, sizeof( Ships[ i ].Deaths ), 1, fp );
		fwrite( &Ships[ i ].PrimBullIdCount, sizeof( Ships[ i ].PrimBullIdCount ), 1, fp );
		fwrite( &Ships[ i ].SecBullIdCount, sizeof( Ships[ i ].SecBullIdCount ), 1, fp );
		fwrite( &Ships[ i ].PickupIdCount, sizeof( Ships[ i ].PickupIdCount ), 1, fp );
		fwrite( &Ships[ i ].Damage, sizeof( Ships[ i ].Damage ), 1, fp );
		fwrite( &Ships[ i ].Primary, sizeof( Ships[ i ].Primary ), 1, fp );
		fwrite( &Ships[ i ].Secondary, sizeof( Ships[ i ].Secondary ), 1, fp );
		fwrite( &Ships[ i ].ModelNum, sizeof( Ships[ i ].ModelNum ), 1, fp );
		fwrite( &Ships[ i ].BikeNum, sizeof( Ships[ i ].BikeNum ), 1, fp );
		fwrite( &Ships[ i ].Pickups, sizeof( Ships[ i ].Pickups ), 1, fp );
		fwrite( &Ships[ i ].RegenSlots, sizeof( Ships[ i ].RegenSlots ), 1, fp );
		fwrite( &Ships[ i ].LastMove, sizeof( Ships[ i ].LastMove ), 1, fp );
		fwrite( &Ships[ i ].Move_Off, sizeof( Ships[ i ].Move_Off ), 1, fp );
		fwrite( &Ships[ i ].OrbModels, sizeof( Ships[ i ].OrbModels ), 1, fp );
		fwrite( &Ships[ i ].OrbAmmo, sizeof( Ships[ i ].OrbAmmo ), 1, fp );
		fwrite( &Ships[ i ].PrimPowerLevel, sizeof( Ships[ i ].PrimPowerLevel ), 1, fp );
		fwrite( &Ships[ i ].PrimID, sizeof( Ships[ i ].PrimID ), 1, fp );
		fwrite( &Ships[ i ].SecID, sizeof( Ships[ i ].SecID ), 1, fp );
		fwrite( &Ships[ i ].SecWeapon, sizeof( Ships[ i ].SecWeapon ), 1, fp );
		fwrite( &Ships[ i ].SuperNashramTimer, sizeof( Ships[ i ].SuperNashramTimer ), 1, fp );
		fwrite( &Ships[ i ].ShakeTimer, sizeof( Ships[ i ].ShakeTimer ), 1, fp );
		fwrite( &Ships[ i ].ShakeDirTimer, sizeof( Ships[ i ].ShakeDirTimer ), 1, fp );
		fwrite( &Ships[ i ].ShakeForce, sizeof( Ships[ i ].ShakeForce ), 1, fp );

		i = MAX_PLAYERS;

		Ships[ i ].Object.ID = &Ships[ i ];
		Ships[ i ].Object.Type = OBJECT_TYPE_SHIP;
		if( !Object_Save( fp , &Ships[ i ].Object ) )
		{
			fclose( fp );
			return( NULL );
		}
			
		fwrite( &Ships[ i ].enable, sizeof( Ships[ i ].enable ), 1, fp );
		fwrite( &Ships[ i ].ShipThatLastKilledMe, sizeof( Ships[ i ].ShipThatLastKilledMe ), 1, fp );
		fwrite( &Ships[ i ].ShipThatLastHitMe, sizeof( Ships[ i ].ShipThatLastHitMe ), 1, fp );
		fwrite( &Ships[ i ].NumMultiples, sizeof( Ships[ i ].NumMultiples ), 1, fp );
		fwrite( &Ships[ i ].StealthTime, sizeof( Ships[ i ].StealthTime ), 1, fp );
		fwrite( &Ships[ i ].Timer, sizeof( Ships[ i ].Timer ), 1, fp );
		fwrite( &Ships[ i ].InvulTimer, sizeof( Ships[ i ].InvulTimer ), 1, fp );
		fwrite( &Ships[ i ].Invul, sizeof( Ships[ i ].Invul ), 1, fp );
		fwrite( &Ships[ i ].LastAngle, sizeof( Ships[ i ].LastAngle ), 1, fp );
		fwrite( &Ships[ i ].Kills, sizeof( Ships[ i ].Kills ), 1, fp );
		fwrite( &Ships[ i ].Deaths, sizeof( Ships[ i ].Deaths ), 1, fp );
		fwrite( &Ships[ i ].PrimBullIdCount, sizeof( Ships[ i ].PrimBullIdCount ), 1, fp );
		fwrite( &Ships[ i ].SecBullIdCount, sizeof( Ships[ i ].SecBullIdCount ), 1, fp );
		fwrite( &Ships[ i ].PickupIdCount, sizeof( Ships[ i ].PickupIdCount ), 1, fp );
		fwrite( &Ships[ i ].Damage, sizeof( Ships[ i ].Damage ), 1, fp );
		fwrite( &Ships[ i ].Primary, sizeof( Ships[ i ].Primary ), 1, fp );
		fwrite( &Ships[ i ].Secondary, sizeof( Ships[ i ].Secondary ), 1, fp );
		fwrite( &Ships[ i ].ModelNum, sizeof( Ships[ i ].ModelNum ), 1, fp );
		fwrite( &Ships[ i ].BikeNum, sizeof( Ships[ i ].BikeNum ), 1, fp );
		fwrite( &Ships[ i ].Pickups, sizeof( Ships[ i ].Pickups ), 1, fp );
		fwrite( &Ships[ i ].RegenSlots, sizeof( Ships[ i ].RegenSlots ), 1, fp );
		fwrite( &Ships[ i ].LastMove, sizeof( Ships[ i ].LastMove ), 1, fp );
		fwrite( &Ships[ i ].Move_Off, sizeof( Ships[ i ].Move_Off ), 1, fp );
		fwrite( &Ships[ i ].OrbModels, sizeof( Ships[ i ].OrbModels ), 1, fp );
		fwrite( &Ships[ i ].OrbAmmo, sizeof( Ships[ i ].OrbAmmo ), 1, fp );
		fwrite( &Ships[ i ].PrimPowerLevel, sizeof( Ships[ i ].PrimPowerLevel ), 1, fp );
		fwrite( &Ships[ i ].PrimID, sizeof( Ships[ i ].PrimID ), 1, fp );
		fwrite( &Ships[ i ].SecID, sizeof( Ships[ i ].SecID ), 1, fp );
		fwrite( &Ships[ i ].SecWeapon, sizeof( Ships[ i ].SecWeapon ), 1, fp );
		fwrite( &Ships[ i ].SuperNashramTimer, sizeof( Ships[ i ].SuperNashramTimer ), 1, fp );
		fwrite( &Ships[ i ].ShakeTimer, sizeof( Ships[ i ].ShakeTimer ), 1, fp );
		fwrite( &Ships[ i ].ShakeDirTimer, sizeof( Ships[ i ].ShakeDirTimer ), 1, fp );
		fwrite( &Ships[ i ].ShakeForce, sizeof( Ships[ i ].ShakeForce ), 1, fp );

		fwrite( &LevelTimeTaken, sizeof( float ), 1, fp );
	}

	return( fp );
}

/*�������������������������������������������������������������������
	Procedure	:	Load Ship Array & Connected Global Variables
	Input		:	FILE	*	File Pointer
	Output		:	FILE	*	Updated File Pointer
�������������������������������������������������������������������*/
FILE * LoadShips( FILE * fp )
{
	uint16	i;

	if( fp )
	{
		i = WhoIAm;

		if( !Object_Load( fp , &Ships[ i ].Object ) )
		{
			fclose( fp );
			return( NULL );
		}
			
		fread( &Ships[ i ].enable, sizeof( Ships[ i ].enable ), 1, fp );
		fread( &Ships[ i ].ShipThatLastKilledMe, sizeof( Ships[ i ].ShipThatLastKilledMe ), 1, fp );
		fread( &Ships[ i ].ShipThatLastHitMe, sizeof( Ships[ i ].ShipThatLastHitMe ), 1, fp );
		fread( &Ships[ i ].NumMultiples, sizeof( Ships[ i ].NumMultiples ), 1, fp );
		fread( &Ships[ i ].StealthTime, sizeof( Ships[ i ].StealthTime ), 1, fp );
		fread( &Ships[ i ].Timer, sizeof( Ships[ i ].Timer ), 1, fp );
		fread( &Ships[ i ].InvulTimer, sizeof( Ships[ i ].InvulTimer ), 1, fp );
		fread( &Ships[ i ].Invul, sizeof( Ships[ i ].Invul ), 1, fp );
		fread( &Ships[ i ].LastAngle, sizeof( Ships[ i ].LastAngle ), 1, fp );
		fread( &Ships[ i ].Kills, sizeof( Ships[ i ].Kills ), 1, fp );
		fread( &Ships[ i ].Deaths, sizeof( Ships[ i ].Deaths ), 1, fp );
		fread( &Ships[ i ].PrimBullIdCount, sizeof( Ships[ i ].PrimBullIdCount ), 1, fp );
		fread( &Ships[ i ].SecBullIdCount, sizeof( Ships[ i ].SecBullIdCount ), 1, fp );
		fread( &Ships[ i ].PickupIdCount, sizeof( Ships[ i ].PickupIdCount ), 1, fp );
		fread( &Ships[ i ].Damage, sizeof( Ships[ i ].Damage ), 1, fp );
		fread( &Ships[ i ].Primary, sizeof( Ships[ i ].Primary ), 1, fp );
		fread( &Ships[ i ].Secondary, sizeof( Ships[ i ].Secondary ), 1, fp );
		fread( &Ships[ i ].ModelNum, sizeof( Ships[ i ].ModelNum ), 1, fp );
		fread( &Ships[ i ].BikeNum, sizeof( Ships[ i ].BikeNum ), 1, fp );
		fread( &Ships[ i ].Pickups, sizeof( Ships[ i ].Pickups ), 1, fp );
		fread( &Ships[ i ].RegenSlots, sizeof( Ships[ i ].RegenSlots ), 1, fp );
		fread( &Ships[ i ].LastMove, sizeof( Ships[ i ].LastMove ), 1, fp );
		fread( &Ships[ i ].Move_Off, sizeof( Ships[ i ].Move_Off ), 1, fp );
		fread( &Ships[ i ].OrbModels, sizeof( Ships[ i ].OrbModels ), 1, fp );
		fread( &Ships[ i ].OrbAmmo, sizeof( Ships[ i ].OrbAmmo ), 1, fp );
		fread( &Ships[ i ].PrimPowerLevel, sizeof( Ships[ i ].PrimPowerLevel ), 1, fp );
		fread( &Ships[ i ].PrimID, sizeof( Ships[ i ].PrimID ), 1, fp );
		fread( &Ships[ i ].SecID, sizeof( Ships[ i ].SecID ), 1, fp );
		fread( &Ships[ i ].SecWeapon, sizeof( Ships[ i ].SecWeapon ), 1, fp );
		fread( &Ships[ i ].SuperNashramTimer, sizeof( Ships[ i ].SuperNashramTimer ), 1, fp );
		fread( &Ships[ i ].ShakeTimer, sizeof( Ships[ i ].ShakeTimer ), 1, fp );
		fread( &Ships[ i ].ShakeDirTimer, sizeof( Ships[ i ].ShakeDirTimer ), 1, fp );
		fread( &Ships[ i ].ShakeForce, sizeof( Ships[ i ].ShakeForce ), 1, fp );

		i = MAX_PLAYERS;

		if( !Object_Load( fp , &Ships[ i ].Object ) )
		{
			fclose( fp );
			return( NULL );
		}
			
		fread( &Ships[ i ].enable, sizeof( Ships[ i ].enable ), 1, fp );
		fread( &Ships[ i ].ShipThatLastKilledMe, sizeof( Ships[ i ].ShipThatLastKilledMe ), 1, fp );
		fread( &Ships[ i ].ShipThatLastHitMe, sizeof( Ships[ i ].ShipThatLastHitMe ), 1, fp );
		fread( &Ships[ i ].NumMultiples, sizeof( Ships[ i ].NumMultiples ), 1, fp );
		fread( &Ships[ i ].StealthTime, sizeof( Ships[ i ].StealthTime ), 1, fp );
		fread( &Ships[ i ].Timer, sizeof( Ships[ i ].Timer ), 1, fp );
		fread( &Ships[ i ].InvulTimer, sizeof( Ships[ i ].InvulTimer ), 1, fp );
		fread( &Ships[ i ].Invul, sizeof( Ships[ i ].Invul ), 1, fp );
		fread( &Ships[ i ].LastAngle, sizeof( Ships[ i ].LastAngle ), 1, fp );
		fread( &Ships[ i ].Kills, sizeof( Ships[ i ].Kills ), 1, fp );
		fread( &Ships[ i ].Deaths, sizeof( Ships[ i ].Deaths ), 1, fp );
		fread( &Ships[ i ].PrimBullIdCount, sizeof( Ships[ i ].PrimBullIdCount ), 1, fp );
		fread( &Ships[ i ].SecBullIdCount, sizeof( Ships[ i ].SecBullIdCount ), 1, fp );
		fread( &Ships[ i ].PickupIdCount, sizeof( Ships[ i ].PickupIdCount ), 1, fp );
		fread( &Ships[ i ].Damage, sizeof( Ships[ i ].Damage ), 1, fp );
		fread( &Ships[ i ].Primary, sizeof( Ships[ i ].Primary ), 1, fp );
		fread( &Ships[ i ].Secondary, sizeof( Ships[ i ].Secondary ), 1, fp );
		fread( &Ships[ i ].ModelNum, sizeof( Ships[ i ].ModelNum ), 1, fp );
		fread( &Ships[ i ].BikeNum, sizeof( Ships[ i ].BikeNum ), 1, fp );
		fread( &Ships[ i ].Pickups, sizeof( Ships[ i ].Pickups ), 1, fp );
		fread( &Ships[ i ].RegenSlots, sizeof( Ships[ i ].RegenSlots ), 1, fp );
		fread( &Ships[ i ].LastMove, sizeof( Ships[ i ].LastMove ), 1, fp );
		fread( &Ships[ i ].Move_Off, sizeof( Ships[ i ].Move_Off ), 1, fp );
		fread( &Ships[ i ].OrbModels, sizeof( Ships[ i ].OrbModels ), 1, fp );
		fread( &Ships[ i ].OrbAmmo, sizeof( Ships[ i ].OrbAmmo ), 1, fp );
		fread( &Ships[ i ].PrimPowerLevel, sizeof( Ships[ i ].PrimPowerLevel ), 1, fp );
		fread( &Ships[ i ].PrimID, sizeof( Ships[ i ].PrimID ), 1, fp );
		fread( &Ships[ i ].SecID, sizeof( Ships[ i ].SecID ), 1, fp );
		fread( &Ships[ i ].SecWeapon, sizeof( Ships[ i ].SecWeapon ), 1, fp );
		fread( &Ships[ i ].SuperNashramTimer, sizeof( Ships[ i ].SuperNashramTimer ), 1, fp );
		fread( &Ships[ i ].ShakeTimer, sizeof( Ships[ i ].ShakeTimer ), 1, fp );
		fread( &Ships[ i ].ShakeDirTimer, sizeof( Ships[ i ].ShakeDirTimer ), 1, fp );
		fread( &Ships[ i ].ShakeForce, sizeof( Ships[ i ].ShakeForce ), 1, fp );

		fread( &LevelTimeTaken, sizeof( float ), 1, fp );
	}

	return( fp );
}

float	MyShield;
float	MyHull;

void StoreMyShieldHull( void )
{
	MyShield = Ships[WhoIAm].Object.Shield * 1234.0F;
	MyHull = Ships[WhoIAm].Object.Hull * 4321.0F;
}
void ReStoreMyShieldHull( void )
{
	Ships[WhoIAm].Object.Shield = MyShield / 1234.0F;
	Ships[WhoIAm].Object.Hull = MyHull / 4321.0F;
}


#ifdef OPT_ON
#pragma optimize( "", off )
#endif

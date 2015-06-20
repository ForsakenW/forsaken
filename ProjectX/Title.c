/* 
 * The X Men, October 1996
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * $Revision: 666 $
 * $Header: /PcProjectX/Title.c 666   11/11/98 16:00 Philipy $
 *
 * $Log: /PcProjectX/Title.c $
 * 
 * 666   11/11/98 16:00 Philipy
 * various fixes for warnings / errors when compiling under VC6
 * 
 * 665   5/11/98 3:34p Oliverc
 * Made Z_TRICK work as it should (but left disabled for patch beta 4 as
 * it messes up on translucent external views in certain levels)
 * 
 * 664   23/10/98 2:04p Oliverc
 * Patch 1.00a beta 3
 * 
 * 663   22/10/98 4:24p Oliverc
 * Added "beta" to patch release verison msg
 * 
 * 662   24/09/98 9:33a Oliverc
 * 
 * 661   15/09/98 11:11 Philipy
 * 
 * 660   15/09/98 9:57 Philipy
 * 
 * 659   14/09/98 15:35 Philipy
 * added facility for server based collisions
 * 
 * 658   9/09/98 16:11 Philipy
 * 
 * 657   9/09/98 15:31 Philipy
 * fixed crash bug when toggling group packets on/off
 * 
 * 656   3/09/98 10:23 Philipy
 * 
 * 655   2/09/98 9:50 Philipy
 * added throttle rate slider
 * some Gamespy changes
 * 
 * 654   1/09/98 9:52 Philipy
 * 
 * 653   28/08/98 9:19 Collinsd
 * 
 * 652   27/08/98 20:12 Philipy
 * manual / auto server mode now selectable from menus
 * text now displayed when server in game & not rendering
 * dynamic PPS setting re-enabled for server
 * 
 * 651   27/08/98 19:17 Philipy
 * no need to keep pressing return when trying to quit
 * 'waiting to quit...' now displayed until automatically quitting
 * 
 * 650   27/08/98 17:48 Philipy
 * 
 * 649   27/08/98 17:26 Philipy
 * Pseudohost can select level, & migrates on quitting
 * players booted to titles due to not having new level are now informed
 * 
 * 648   26/08/98 12:07 Philipy
 * message now displayed when server boots you out due to invalid CRC
 * 
 * 647   26/08/98 9:51 Philipy
 * 
 * 646   25/08/98 17:38 Philipy
 * added gamespy support
 * tracker config now selectable from start server game menu, & stored in
 * reg
 * 
 * 645   20/08/98 4:03p Oliverc
 * Added SetViewportError() debug function (enabled on DEBUG_VIEWPORT
 * build switch)
 * 
 * 644   18/08/98 10:11 Philipy
 * 
 * 643   17/08/98 18:00 Philipy
 * removed loads of unreferenced local variables
 * 
 * 642   17/08/98 17:13 Philipy
 * added -ServerChoosesGame & ServerAutoStart command line options
 * 
 * 641   14/08/98 15:25 Philipy
 * added trilinear option to menus
 * fixed level name / shutdown packet in heartbeat
 * 
 * 
 * 640   14/08/98 9:13 Phillipd
 * DirectX6 is in effect.......
 * 
 * 639   11/08/98 16:52 Philipy
 * fixed bug which caused max players to always be set to 32 if lobby
 * launched & lobby sets max players to 0.
 * status request codes now expected in hex format ( eg.
 * FFFFFFFFstatus\nfe<NULL> )
 * heartbeat frequencies less than 5000 mS can now be specified. If none (
 * or 0 ) specified, no heartbeat packets will be sent.
 * 
 * 638   7/08/98 12:45 Philipy
 * heartbeat now enabled for non tcp games ( if heartbeat.txt exists )
 * status type 0 now treated as status type 254
 * if lobby launched with max players set to 0, host is able to set max
 * players
 * shutdown udp packet now sent ( if specified in heartbeat.txt )
 * 
 * 637   6/08/98 9:31 Philipy
 * added 'beta' to patch version number
 * 
 * 636   5/08/98 16:38 Philipy
 * fixed single player patch bug
 * 
 * 635   5/08/98 11:04 Philipy
 * added AutoStart facility ( joins game based on GUID in registery )
 * upped patch version to 1.02
 * 
 * 634   31/07/98 16:17 Philipy
 * added PPS to session desc
 * 
 * 633   31/07/98 12:17 Philipy
 * 
 * 632   30/07/98 16:58 Philipy
 * 
 * 631   30/07/98 10:43a Oliverc
 * Fixed TCP/IP address saving
 * 
 * 630   28/07/98 15:25 Philipy
 * added patch version no - displayed when in menus
 * 
 * 629   28/07/98 14:44 Philipy
 * all server timeouts now configurable
 * 
 * 628   28/07/98 10:39 Philipy
 * Max players now works properly for server games
 * 
 * 627   27/07/98 12:59 Philipy
 * 
 * 626   24/07/98 14:22 Philipy
 * fixed auto-quit after error msg when quickjoining
 * 
 * 625   24/07/98 11:25 Philipy
 * you now cannot record demo if group packets set and/or it is a server
 * based game
 * 
 * 624   23/07/98 18:40 Philipy
 * server now properly resets after timing out ( no msgs recieved ) while
 * in game
 * 
 * 623   23/07/98 15:38 Philipy
 * server now resets if no packets recieved for 5 mins
 * 
 * 622   23/07/98 14:34 Phillipd
 * 
 * 621   22/07/98 3:36p Oliverc
 * Join game menu TCP address saved in registry
 * 
 * 620   22/07/98 14:06 Phillipd
 * 
 * 619   22/07/98 12:45 Phillipd
 * if a server game show 1 less players.....
 * 
 * 618   21/07/98 17:31 Philipy
 * added timeout stuff for titles
 * 
 * 617   21/07/98 12:10 Collinsd
 * MAX_PLAYERS increased to 24 and version number incremented.
 * 
 * 616   21/07/98 11:21 Philipy
 * 
 * 615   20/07/98 17:44 Philipy
 * various patch bugs
 * 
 * 614   20/07/98 12:27 Philipy
 * nicer handling of uninstalled levels
 * 
 * 613   7/16/98 11:27a Phillipd
 * 
 * 612   15/07/98 16:56 Philipy
 * removed superfluous menu from server pseudohost startup
 * 
 * 611   15/07/98 16:25 Philipy
 * now handles pseudohost quitting in titles & server quitting ( in
 * titiles or in game )
 * 
 * 610   14/07/98 17:18 Philipy
 * 
 * 609   14/07/98 16:41 Philipy
 * 
 * 608   14/07/98 11:15 Philipy
 * various patch bugs
 * pseudohost quitting in titles
 * 
 * 607   7/10/98 11:30a Phillipd
 * 
 * 606   7/10/98 11:29a Phillipd
 * 
 * 605   7/10/98 11:17a Phillipd
 * 
 * 604   9/07/98 12:43 Philipy
 * few minor fixes for patch release
 * 
 * 603   7/08/98 3:07p Phillipd
 * 
 * 602   8/07/98 10:42 Oliverc
 * Added "server" text to deathmatch menu for shortcut keypress purposes
 * 
 * 601   8/07/98 10:13 Philipy
 * 
 * 600   7/08/98 9:59a Phillipd
 * 
 * 599   7/07/98 18:05 Philipy
 * added lobby autostart code ( when all players have recieved init msg )
 * added num primary weapons menu option ( propergated to other players &|
 * server )
 * extracted new title text for localisation
 * 
 * 598   3/07/98 17:46 Philipy
 * added quit option when using quickstart
 * 
 * 597   3/07/98 12:56 Philipy
 * 
 * 596   3/07/98 11:54 Philipy
 * heartbeat & quickstart stuff
 * 
 * 595   24/06/98 11:04 Philipy
 * added gateway flag
 * 
 * 594   23/06/98 12:46 Philipy
 * 
 * 593   22/06/98 17:32 Philipy
 * move #includes around for localisations so that title text is available
 * in other files
 * 
 * 592   6/22/98 2:16p Phillipd
 * Option to reset the score for every level..............
 * 
 * 591   19/06/98 11:08 Oliverc
 * Added the record demo option back to multiplayer game start options
 * menu
 * 
 * 590   18/06/98 14:16 Philipy
 * fixed end of game gol bar bug
 * 
 * 589   17/06/98 19:33 Philipy
 * more win98 stuff
 * 
 * 588   16/06/98 16:33 Philipy
 * more lobby / join game stuff
 * 
 * 587   15/06/98 17:56 Philipy
 * 
 * 586   15/06/98 17:55 Philipy
 * max players now clamped after getting prefered value from reg
 * 
 * 585   13/06/98 20:46 Philipy
 * improved lobby support:
 * host now migrates properly
 * you can quit b4 starting game without screwing up session
 * 
 * 584   13/06/98 14:35 Philipy
 * only 1 bike computer available for win98 demo version
 * 
 * 583   11/06/98 16:57 Philipy
 * loads of win98 shareware version stuff
 * 
 * 582   6/11/98 12:43p Phillipd
 * 
 * 581   11/06/98 9:54 Philipy
 * files checked in prior to starting Win98 shareware version
 * 
 * 580   10/06/98 15:17 Philipy
 * put back more multiplayer options
 * 
 * 579   8/06/98 12:28 Philipy
 * server levels now sent across to pseudohost. Pseudohost can only pick
 * valid levels
 * 
 * 578   6/04/98 9:32a Phillipd
 * 
 * 577   6/03/98 4:33p Phillipd
 * 
 * 576   3/06/98 16:19 Philipy
 * 
 * 575   6/03/98 4:11p Phillipd
 * 
 * 574   3/06/98 15:30 Philipy
 * added server in game options for rendering on/off and selecting players
 * pseudohost can now select if server does collisions. This gets
 * propagated in MSG_GameParams and MSG_Init
 * 
 * 573   22/05/98 17:51 Philipy
 * more work on session info
 * 
 * 572   20/05/98 16:14 Philipy
 * added full screen rearview and headlight keys to in game menu
 * 
 * 571   20/05/98 9:39 Philipy
 * implemented front end server menus
 * removed ( invalid ) ping from sessions menu
 * changed EnumPlayers so that it solely uses MSG_NAME
 * 
 * 570   12/05/98 11:39 Philipy
 * fixed session name bug when hosting game
 * 
 * 569   11/05/98 15:15 Philipy
 * added session info stuff ( game type, ping etc )
 * 
 * 568   4/30/98 3:52p Phillipd
 * 
 * 567   4/30/98 3:48p Phillipd
 * 
 * 566   29/04/98 16:43 Philipy
 * added server mode cog
 * 
 * 565   4/27/98 4:01p Phillipd
 * 
 * 564   25/04/98 16:47 Collinsd
 * 
 * 563   25/04/98 16:40 Collinsd
 * 
 * 562   24/04/98 1:37 Philipy
 * weapon order text now comes from local files
 * 
 * 561   23/04/98 23:56 Oliverc
 * Hacked extra space for in-game key def label text for euro versions
 * 
 * 560   23/04/98 23:28 Oliverc
 * 
 * 559   23/04/98 22:05 Oliverc
 * 
 * 558   23/04/98 21:02 Philipy
 * 
 * 557   23/04/98 20:03 Philipy
 * 
 * 556   23/04/98 19:51 Philipy
 * 
 * 555   23/04/98 18:32 Philipy
 * 
 * 554   23/04/98 11:54 Philipy
 * 
 * 553   22/04/98 17:39 Philipy
 * 
 * 552   22/04/98 12:00 Philipy
 * 
 * 551   22/04/98 9:25 Philipy
 * 
 * 550   21/04/98 16:23 Philipy
 * more localisation stuff
 * 
 * 549   21/04/98 14:12 Philipy
 * added support for more foreign chars
 * 
 * 548   21/04/98 11:08 Philipy
 * slight localisation change
 * 
 * 547   21/04/98 9:27 Philipy
 * foreign char lookup table now indexed correctly
 * 
 * 546   20/04/98 17:12 Philipy
 * added localisation stuff
 * 
 * 545   17/04/98 9:22 Philipy
 * extracted all text for localisation
 * 
 * 544   15/04/98 11:46 Collinsd
 * Flygirl now stealths correctly
 * 
 * 543   4/14/98 7:15p Phillipd
 * 
 * 542   14/04/98 14:44 Philipy
 * selecting packet grouping ensures small packets are on
 * unselecting short packets ensures that packet grouping is off
 * 
 * 541   4/14/98 2:23p Phillipd
 * 
 * 540   13/04/98 23:38 Philipy
 * fixed inter-level crash bug
 * 
 * 539   12/04/98 23:50 Oliverc
 * Fixed bug with MyGameStatus following completing game after cheating
 * 
 * 538   11/04/98 20:06 Collinsd
 * 
 * 537   11/04/98 19:06 Philipy
 * fixed AVI bug
 * fixed stripping bug
 * lobby launched game now goes to next level after stats
 * 
 * 536   11/04/98 17:09 Collinsd
 * 
 * 535   11/04/98 12:52 Philipy
 * fixed attract mode glitch
 * 
 * 534   11/04/98 12:24 Oliverc
 * InitDemoList() only adds demos to list if level exists
 * Added demo playing option to show player names
 * 
 * 533   10/04/98 17:36 Philipy
 * 
 * 532   9/04/98 21:18 Collinsd
 * 
 * 531   9/04/98 20:21 Philipy
 * fixed inter-level holo-scan line & added software hack to scan all
 * bikes on entering titles
 * 
 * 530   9/04/98 18:28 Collinsd
 * 
 * 529   9/04/98 17:50 Philipy
 * added CWscan routine after loading each bike (sw)
 * 
 * 528   9/04/98 10:24 Philipy
 * 
 * 527   9/04/98 10:19 Philipy
 * added more debug info to textitem bounding box check
 * 
 * 526   8/04/98 20:47 Philipy
 * title text messages now properly initialised
 * holo-glaire removed for sw version
 * compound buffer size can now be set in command line and opt file
 * prevented "level select disabled" from appearing at start of
 * multiplayer game
 * 
 * 525   8/04/98 19:14 Collinsd
 * 
 * 524   8/04/98 18:44 Philipy
 * moved highlight box and slider stuff into processtextitems due to sw
 * version
 * 
 * 523   8/04/98 17:01 Oliverc
 * Last service provider now stored in registry
 * 
 * 522   8/04/98 15:02 Philipy
 * level picture size reduced
 * 
 * 521   8/04/98 12:48 Philipy
 * added bike engine toggle
 * 
 * 520   8/04/98 11:06 Philipy
 * fixed host not displaying player names bug
 * 
 * 519   8/04/98 10:19 Philipy
 * fixed multiple 'I' bug
 * 
 * 518   7/04/98 17:50 Philipy
 * removed multiplayer taunts
 * AVI thread now allowed to exit nicely rather than being terminated
 * fixed inter-level bug
 * fixed bug in enemy taunts
 * 
 * 517   7/04/98 11:01 Philipy
 * potentially fixed crash when going from AVI to titles
 * fixed CD audio looping
 * no CD audio in front end unless full install
 * bike features sliders now give correct values
 * 
 * 516   6/04/98 20:51 Oliverc
 * Added new help message to in-game control config screen to show
 * duplicate key definitions and unconnected devices
 * 
 * 515   6/04/98 14:56 Philipy
 * fixed bike scan line
 * 
 * 514   4/06/98 2:23p Phillipd
 * 
 * 513   4/06/98 12:52p Phillipd
 * 
 * 512   6/04/98 11:32 Collinsd
 * Added show restart zone to debug menu.
 * 
 * 511   6/04/98 11:29 Philipy
 * added big packets option
 * upped frequency of some speech sfx
 * re-implemented holo-scanline
 * 
 * 510   5/04/98 17:10 Collinsd
 * Hacked demos to work.
 * 
 * 509   5/04/98 16:58 Philipy
 * moved CD_OK flag from config to registry
 * cheats now disabled for multiplayer
 * sfx now paused for shortcut single player menus
 * 
 * 508   5/04/98 15:01 Philipy
 * started pre AVI CD accesss ( not yet implemented )
 * bike engine freq now done on 5 frame average
 * prevented CD track from playing in titles if set to off
 * NoDynamic SFX does not bike bike computer static anymore
 * water detail slider now only has two levels
 * 
 * 507   4/04/98 14:23 Philipy
 * mode scaling stuff is now calculated rather than based on fixed values
 * added -NoBlitTextScaling option to ReadIni and command line options
 * 
 * 506   4/04/98 13:44 Oliverc
 * Changed default collision perspective to Descent-stylee (boo-hoo!)
 * 
 * 505   4/04/98 11:19 Oliverc
 * Attract mode splash demo now plays from CD if not found installed
 * Software screen res now stored separately from HW in registry
 * Registry keys now opened in-game as creation done by installer
 * 
 * 504   3/04/98 19:15 Philipy
 * blitted text now scales properly
 * added -NoBlitTextScaling flag for cards that can't do a strech blit
 * properly ( Riva )
 * 
 * 503   3/04/98 18:23 Philipy
 * fixed placeholder memory problem
 * remove existing team scores from team join menu
 * 
 * 502   3/04/98 16:03 Philipy
 * fixed CD audio stuff
 * 
 * 501   3/04/98 14:04 Philipy
 * fixed credit toggle stuff
 * 
 * 500   3/04/98 13:13 Philipy
 * Taunts are now affected by biker volume slider ( taunt volume slider
 * removed )
 * Enemy bikers now give out death cry
 * fixed problem with speech ignoring volume settings
 * fixed end game sequences
 * 
 * 499   3/04/98 12:25 Collinsd
 * Fix for attract mode if no dmo.
 * 
 * 498   2/04/98 21:07 Philipy
 * Added taunts ( single & multiplayer, plus enemy biker taunts )
 * added flygirl to front end.
 * sliders for biker, bike computer and taunt speech volume
 * added new sfx for title
 * 
 * 497   2/04/98 14:29 Oliverc
 * Added default settings for joystick axes & buttons
 * 
 * 496   1/04/98 21:14 Oliverc
 * Changed joystick axis config to indicate position of joystick relative
 * to key points (middle+extreme left/right)
 * 
 * 495   1/04/98 16:27 Oliverc
 * Added player delete and rename options
 * Fixed bugs in player change option (bike & speech not in synch)
 * Added command-line option to allow SpaceOrb axes to be configured in
 * normal joystick screen
 * 
 * 494   31/03/98 16:04 Oliverc
 * Disabled toggle full screen option in visuals menu for software version
 * 
 * 493   30/03/98 23:42 Oliverc
 * Fixed minor glitch in PreferedMaxPlayer multiplayer game preference
 * settings
 * Fixed multiplayer start more options menus formatting
 * Improved list item selection and diplay for in-game load/save game menu
 * 
 * 492   3/30/98 7:35p Phillipd
 * 
 * 491   30/03/98 19:32 Philipy
 * fixed level timer fuck up
 * 
 * 490   3/30/98 7:11p Phillipd
 * 
 * 489   3/30/98 6:45p Phillipd
 * 
 * 488   30/03/98 17:31 Philipy
 * added cd specific path stuff
 * added new bike computers
 * prevented File_Exists being called every time a dynamic sfx is played
 * 
 * 487   30/03/98 12:32 Oliverc
 * Fixed potential bug with defining buttons on joysticks not flagging
 * joystick as assigned
 * 
 * 486   30/03/98 12:03 Oliverc
 * Attract mode now kicks in only when on start menu
 * 
 * 485   30/03/98 10:20 Collinsd
 * SOFTWARE_ENABLE # fixed.
 * 
 * 484   30/03/98 10:01 Collinsd
 * Gamma for software now works.
 * 
 * 483   29/03/98 20:00 Philipy
 * cd path now verified earlier
 * sfx no longer reloaded when changing biker / bike computer
 * mouse sensitivity rounding error fixed
 * 
 * 482   28/03/98 17:33 Philipy
 * corrected some sfx
 * added legal screen
 * fixed mission briefing text bug
 * 
 * 481   28/03/98 13:35 Philipy
 * added all biker speech
 * 
 * 480   27/03/98 21:06 Philipy
 * added end game sequence for completing the game with cheating
 * 
 * 479   27/03/98 19:06 Philipy
 * water always at max detail for splash screen
 * 
 * 478   3/27/98 5:49p Phillipd
 * 
 * 477   27/03/98 12:58 Philipy
 * changed cheat mode stuff
 * fixed bug that prevented individual variants of variant sfx to be
 * mapped
 * correct menutv now displayed between levels
 * 
 * 476   26/03/98 19:42 Philipy
 * 
 * 475   26/03/98 12:28 Philipy
 * added water detail & gamma sliders
 * fixed holo object swapping stuff
 * fixed crash bug when selecting room in debug mode
 * 
 * 474   26/03/98 9:21 Collinsd
 * SW ZBUFFER 
 * 
 * 473   24/03/98 21:42 Oliverc
 * Added sensitivity and fine control options to joystick axis config
 * screens
 * 
 * 472   24/03/98 21:07 Philipy
 * fixed quicktext stuff
 * sfx do not pause when in multiplayer mode
 * rear camera not shown for splash demos
 * 
 * 471   24/03/98 18:01 Collinsd
 * Added ZBuffer clear for title/splash
 * 
 * 470   24/03/98 16:20 Philipy
 * added new sfx
 * 
 * 469   3/23/98 3:23p Phillipd
 * 
 * 468   23/03/98 15:13 Oliverc
 * Fixed bugs introduced by Sourcesafe merge failing and deleting new axis
 * setup functions (hope this works...!)
 * 
 * 467   23/03/98 10:36 Oliverc
 * 
 * 466   21/03/98 16:18 Philipy
 * added gamma slider ( not yet operational)
 * fixed multiple copies of level in list bug
 * 
 * 465   3/20/98 2:52p Phillipd
 * fixed level select bug....
 * 
 * 464   3/20/98 10:36a Phillipd
 * 
 * 463   19/03/98 20:32 Philipy
 * added different end of game scenarios
 * code now written to config to indicate if secret biker is available
 * 
 * 462   18/03/98 17:46 Philipy
 * fixed quick text & buffered key flush bugs
 * 
 * 461   3/18/98 4:33p Phillipd
 * 
 * 460   3/18/98 4:32p Phillipd
 * 
 * 459   18/03/98 16:25 Philipy
 * removed some debug msgs
 * 
 * 458   16/03/98 21:55 Collinsd
 * Randomize Pickups now in multiplayer start menu
 * 
 * 457   16/03/98 17:24 Philipy
 * removed annoying debug message
 * 
 * 456   16/03/98 16:40 Philipy
 * fixed buffered key problem
 * added AVI to splash screens
 * 
 * 455   16/03/98 12:19 Collinsd
 * Random Pickups option added.  Sphere dislpay of trigger areas
 * 
 * 454   15/03/98 18:40 Philipy
 * added water effect splash screen
 * fixed bug with end game sequence
 * implemented attract mode
 * text macros now saved in config
 * 
 * 453   14/03/98 18:59 Collinsd
 * Added godmode and made debug mode work even when you change level.
 * 
 * 452   13/03/98 16:14 Collinsd
 * Added Magic and Version number to save game.
 * 
 * 451   11/03/98 10:55 Philipy
 * all sfx now stopped for pause mode
 * correct level info now displayed in briefing screen
 * correct level now entered after completing a previously saved level
 * level timer now accurate
 * 
 * 450   10/03/98 20:15 Collinsd
 * 
 * 449   10/03/98 14:51 Oliverc
 * Enabled options menu/extra info for Acclaim NY version as well
 * 
 * 448   9/03/98 22:03 Oliverc
 * Removed Options/Misc menu
 * Fixed crash bug in Controls/Restore defaults
 * 
 * 447   9/03/98 20:45 Oliverc
 * Allowed twice as much space per item to display joystick selection list
 * 
 * 446   9/03/98 16:57 Philipy
 * if selecting new player, displayed bike now defaults back to Beard
 * 
 * 445   9/03/98 14:18 Oliverc
 * 
 * 444   8/03/98 16:51 Philipy
 * prevent MenuBack from some menus when lobby launched
 * added team game support for lobby
 * 
 * 443   7/03/98 20:00 Oliverc
 * Changed BikeExhausts default to TRUE
 * 
 * 442   7/03/98 19:38 Oliverc
 * Added BikeExhausts display option to multiplayer start menu
 * Automatically advance selected game whenever game saved
 * 
 * 441   3/07/98 4:13p Phillipd
 * 
 * 440   3/07/98 3:48p Phillipd
 * 
 * 439   7/03/98 15:35 Philipy
 * 'quit' option on host setup menu now only appears when lobby launched
 * 
 * 438   7/03/98 14:27 Oliverc
 * Clean demo no longer needs different output name
 * 
 * 437   3/07/98 2:24p Phillipd
 * -PPS packets per second command line option added...1 to 30
 * 
 * 436   7/03/98 14:03 Philipy
 * removed annoying debug messages
 * 
 * 435   6/03/98 17:37 Philipy
 * implemented ability to run when launched by lobby
 * 
 * 434   6/03/98 15:29 Oliverc
 * Added GetMissionName() routine to convert short level name to full
 * mission name for use in load/save game info display (both in-game in in
 * front end)
 * 
 * 433   6/03/98 12:09 Collinsd
 * Taken out drop pickup code.
 * 
 * 432   6/03/98 10:29 Collinsd
 * Screen Saving now using my routine... and is on f8
 * 
 * 431   5/03/98 21:46 Oliverc
 * Changed save games to use fixed number of slots
 * Added option to delete items from any list (currently enabled only on
 * demos)
 * 
 * 430   4/03/98 12:33 Oliverc
 * CTF mode fully enabled
 * 
 * 429   3/03/98 14:08 Oliverc
 * 
 * 428   2/03/98 17:29 Oliverc
 * Added optional validation function to TEXT structure to filter
 * permitted characters for demo filenames
 * All .DMO files now kept in Demos folder
 * 
 * 427   2/03/98 12:10 Oliverc
 * Hidden ".DMO" extension from demo file names
 * and added extra info to .DMO file to specify game type etc
 * 
 * 426   28/02/98 20:07 Philipy
 * 
 * 425   28/02/98 18:56 Philipy
 * 
 * 424   27/02/98 20:00 Collinsd
 * SWMonoChrome & Last_SWMonoChrome moved outside chris's code.
 * 
 * 423   27/02/98 19:11 Philipy
 * fixed load game sfx bug
 * added pseudo dithering for 8 bit saved game pic
 * flygirl now selectable from front end ( no model displayed )
 * 
 * 422   27/02/98 18:54 Oliverc
 * Added monochrome model/level RGBs option to in-game detail levels menu
 * 
 * 421   27/02/98 16:30 Oliverc
 * Multiplayer game options always restored from registry on entering
 * "create multiplayer game" menu, and only saved back to registry when
 * multiplayer game started
 * 
 * 420   27/02/98 10:02 Collinsd
 * Fixed Trans
 * 
 * 419   26/02/98 20:41 Philipy
 * added front end for load game
 * 
 * 418   26/02/98 9:30 Oliverc
 * Disabled Bombtag
 * Fixed pickup flags bug
 * Disabled logos for EXTERNAL_DEMOs
 * 
 * 417   25/02/98 16:19 Oliverc
 * More multiplayer tweaks
 * 
 * 416   25/02/98 16:06 Collinsd
 * Save Picture for save game...
 * 
 * 415   25/02/98 15:44 Philipy
 * more efficient use of hw sound mixing buffers
 * 
 * 414   24/02/98 22:00 Oliverc
 * Tweaks to multiplayer games
 * 
 * 413   24/02/98 16:56 Oliverc
 * 1st attempt at bounty hunt multiplayer game
 * 
 * 412   23/02/98 15:31 Philipy
 * implemented single player level timer
 * 
 * 411   2/23/98 2:02p Phillipd
 * Load Save now works.
 * 
 * 410   23/02/98 13:00 Philipy
 * added scan lines for inter-level objects
 * added speech for bike selection in front end
 * 
 * 409   23/02/98 10:37 Philipy
 * added inter level stuff
 * 
 * 408   21/02/98 17:00 Oliverc
 * Fixed bug in goal score option (not initialised when entering menu)
 * 
 * 407   21/02/98 16:25 Philipy
 * added text messages for capture flag
 * 
 * 406   21/02/98 15:56 Oliverc
 * Added user-definable goal score option and fixed bug in goal scoring
 * when flag appears in goal
 * 
 * 405   21/02/98 13:04 Philipy
 * added in game load / save for sfx
 * 
 * 404   20/02/98 15:29 Philipy
 * re-implented AVI
 * splash screens can now play demos and AVIs
 * 
 * 403   19/02/98 22:01 Collinsd
 * Added flygirl biker.
 * 
 * 402   19/02/98 10:05 Oliverc
 * Added force feedback config saving (in-game) and auto-detection of
 * which joystick is to be used for force feedback
 * 
 * 401   18/02/98 11:53 Oliverc
 * First feature-complete version of force feedback joystick code
 * 
 * 400   17/02/98 17:15 Philipy
 * level.mis now used to store level name as well as mission briefing
 * if file not there, reverts back to old level name
 * 
 * 399   17/02/98 9:17 Philipy
 * added support for placeholder textures, which can be dynamically
 * updated
 * implemented mission briefing screens
 * 
 * 398   16/02/98 21:38 Collinsd
 * Started Save/Load BGObjects. 
 * 
 * 397   16/02/98 14:34 Collinsd
 * Started LoadSave
 * 
 * 396   13/02/98 14:18 Philipy
 * moved damage perspective options
 * 
 * 395   11/02/98 12:58 Philipy
 * Changed PlaySfx calls to use Vol instead of Dist
 * 
 * 394   10/02/98 11:51 Philipy
 * added collision type option
 * 
 * 393   7/02/98 19:35 Oliverc
 * Enabled standard debugging options for EXTERNAL_DEMO (but not for
 * SHAREWARE)
 * 
 * 392   5/02/98 10:45 Oliverc
 * GoreGuts off by default (including registry setting)
 * 
 * 391   2/02/98 20:08 Philipy
 * added configurable quick text message buttons
 * 
 * 390   2/02/98 14:20 Philipy
 * Harm Teammates, Disable Pickups front end stuff done
 * 
 * 389   2/02/98 10:07 Philipy
 * 
 * 388   1/31/98 1:22p Phillipd
 * 
 * 387   1/29/98 2:27p Phillipd
 * Demo can now be saved to ram....and can be saved if your not the
 * host...
 * 
 * 386   29/01/98 13:30 Philipy
 * fixed bright title screen bikes prob
 * 
 * 385   28/01/98 23:08 Oliverc
 * Fixed a few presentation glitches in the menus
 * 
 * 384   28/01/98 17:16 Philipy
 * lock out windows now disabled
 * 
 * 383   28/01/98 14:24 Oliverc
 * Moved REGISTRY key names to demo_id.h
 * 
 * 382   27/01/98 23:10 Philipy
 * joystick POV now deletable
 * 
 * 381   27/01/98 15:32 Oliverc
 * Made REGISTRY_GAME_KEY version 1.0 for SHAREWARE version ONLY (ie still
 * version 0.1 for compatibility with development settings)
 * 
 * 380   27/01/98 15:28 Oliverc
 * Updated REGISTRY_GAME_KEY version to 1.0 (VERY IMPORTANT for SHAREWARE
 * version)
 * 
 * 379   27/01/98 14:09 Oliverc
 * Added NO_GORE build option to disable switching gore on/off
 * 
 * 378   27/01/98 13:03 Philipy
 * fixe bike name arrow thing
 * 
 * 377   27/01/98 12:25 Philipy
 * level pic now never displayed for multiplayer game
 * 
 * 376   27/01/98 12:12 Philipy
 * demo settings now always restored b4 playing demo
 * drop primary / drop secondary removed
 * 
 * 375   1/27/98 12:08p Philipy
 * fixed mode changing bug
 * 
 * 374   27/01/98 11:14 Oliverc
 * Fixed demo playback speeds so only a single 100% appears
 * Eliminated intermediate "restore game" menu between "play demo" on
 * start screen and actual "play demo" menu
 * 
 * 373   27/01/98 11:05 Philipy
 * fixed team game stuff
 * 
 * 372   26/01/98 18:23 Philipy
 * fixed video memory leaks
 * splash screens now display after release view, and call InitScene,
 * InitView after  completion
 * 
 * 371   1/26/98 11:08a Phillipd
 * Couple of Viewport changes taken out...
 * RearView is now i the registry....And disabled for death mode
 * 
 * 370   24/01/98 18:38 Philipy
 * time limit max now 15 mins
 * impossible to have unlimited time
 * 
 * 369   24/01/98 17:38 Philipy
 * fixed multiplayer join-quit-join bug
 * fixed attract mode loading wrong level
 * 
 * 368   23/01/98 16:38 Philipy
 * CD audio now on/off toggle, saved to config file
 * triggered pickup sfx now 1 in 4 chance
 * Trojax sfx now only stopped once
 * 
 * 367   23/01/98 11:24 Collinsd
 * Added override for solid screen poly bilinear
 * 
 * 366   22/01/98 22:40 Oliverc
 * Force bike in SHAREWARE demo playback to use only those bikes (and
 * corresponding player names) allowed in SHAREWARE version
 * 
 * 365   22/01/98 19:14 Philipy
 * fixed re-loading looping sfx while in level
 * biker speech now switchable
 * 
 * 364   22/01/98 18:08 Oliverc
 * Fixed bug in demo playback menu (quit now just returns to main menu
 * instead of exiting program)
 * 
 * 363   22/01/98 9:48 Philipy
 * level change bug
 * joystick allocation bug
 * shareware time limit maximum is now 5
 * 
 * 362   21/01/98 17:27 Philipy
 * attract mode splash screen stuff
 * 
 * 361   21/01/98 14:54 Philipy
 * fixed level changing bug
 * 
 * 360   21/01/98 12:19 Philipy
 * Added attract mode for shareware
 * fixed looping sfx volume bug
 * 
 * 359   20/01/98 12:25 Philipy
 * Fixed level starting bug
 * 
 * 358   1/19/98 4:21p Phillipd
 * Bright Ships flag added.....
 * 
 * 357   1/19/98 2:40p Phillipd
 * 
 * 356   19/01/98 13:01 Philipy
 * fixed mission text not being displayed
 * possibly fixed stats bug ?
 * 
 * 355   19/01/98 11:15 Philipy
 * fixed menus locking up on choosing texture format
 * 
 * 354   19/01/98 10:08 Philipy
 * fixed lock up when pressing escape
 * 
 * 353   17/01/98 16:53 Philipy
 * You can now use delete key to un-assign joystick buttons
 * 
 * 352   16/01/98 18:01 Oliverc
 * Only disabled selected weapons for SHAREWARE instead of always...
 * 
 * 351   16/01/98 17:12 Philipy
 * fixed single player loading crash bug
 * 
 * 350   16/01/98 12:11 Philipy
 * added spaceorb auto configure stuff
 * splash screen now displays in highest res it can find
 * 
 * 349   16/01/98 9:22 Oliverc
 * Changed "load game" menu option to "play demo" for SHAREWARE
 * and changed front-end cruise control edit labels to match in-game speed
 * up/down
 * 
 * 348   15/01/98 18:55 Philipy
 * added new splash screens
 * 
 * 347   15/01/98 17:06 Philipy
 * changed PlayPannedSfx calls to use float for freq
 * 
 * 346   1/15/98 12:29p Phillipd
 * 
 * 345   15/01/98 11:14 Oliverc
 * hacked out level pic stuff temporarily
 * 
 * 344   14/01/98 17:17 Oliverc
 * Separate DEMO_LEVELS for SHAREWARE version
 * 
 * 343   13/01/98 10:58 Philipy
 * lives now carry over between levels as before
 * put #ifdefs around splash screens for shareware
 * 
 * 342   13/01/98 9:39 Collinsd
 * Added debug to show untriggered enemies.  Started Enemy Poly Colisions.
 * 
 * 341   12/01/98 20:01 Collinsd
 * Fixed warnings.
 * 
 * 340   12/01/98 16:36 Philipy
 * fixed level loading bug
 * 
 * 339   12/01/98 15:40 Philipy
 * added arrows to indicate selectable bikes
 * 
 * 338   12/01/98 12:19 Oliverc
 * Fixed bug: Lokasenna visible in SHAREWARE version
 * 
 * 337   12/01/98 0:08 Philipy
 * bug fixes
 * added inter-level mission briefing
 * changed splash screen code, + added splash screen on exit
 * 
 * 336   11/01/98 17:54 Philipy
 * inter level mission screen
 * 
 * 335   10/01/98 20:35 Philipy
 * fixed no speech option
 * 
 * 334   10/01/98 19:31 Philipy
 * bug fixes
 * 
 * 333   10/01/98 17:39 Oliverc
 * Fixed bug with font translation table for chars '[', ']', and '='
 * 
 * 332   10/01/98 15:14 Oliverc
 * Disabled logos by default for SHAREWARE except for demo playback
 * 
 * 331   9/01/98 17:26 Philipy
 * player is now forced to start on level 0
 * 
 * 330   9/01/98 16:59 Oliverc
 * Abbreviated labels in in-game keyboard config menus
 * 
 * 329   9/01/98 12:49 Oliverc
 * Disabled demo recording and cleaning from SHAREWARE version
 * 
 * 328   9/01/98 11:14 Philipy
 * 
 * 327   9/01/98 11:00 Oliverc
 * Made SHAREWARE bike selection work in non-SHAREWARE
 * 
 * 326   9/01/98 10:51 Oliverc
 * Fixed bug: shareware version now only has 4 bikers selectable in game
 * Fixed bug: in-game bike selection crashes if press left/right in list
 * Changed CreateVersion() to use MULTIPLAYER_VERSION instead of file
 * modified day
 * Tidied in-game options menus
 * 
 * 325   7/01/98 15:03 Oliverc
 * SHAREWARE versions now use built-in level lists instead of external
 * mission.dat and battle.dat files
 * 
 * 324   7/01/98 12:13 Philipy
 * fixed level spec sfx bug
 * 
 * 323   1/07/98 11:07a Phillipd
 * 
 * 322   7/01/98 11:01 Philipy
 * added extra level names
 * 
 * 321   7/01/98 9:34 Philipy
 * added title room sfx
 * added ability to select bike computer, biker with sfx loaded
 * 
 * 320   6/01/98 19:02 Oliverc
 * Disabled expiry date check if EXPIRE_DAYS not defined
 * 
 * 319   5/01/98 19:59 Oliverc
 * Current screen mode, texture format and sound volume settings now saved
 * to registry on exit and restored on startup
 * 
 * 318   5/01/98 16:41 Collinsd
 * 
 * 317   3/01/98 17:51 Oliverc
 * In-game screen mode changes only if mode selected different from
 * current used
 * Disabled in-game level changing for EXTERNAL_DEMOs
 * 
 * 316   3/01/98 15:01 Oliverc
 * Cut down bike controls menu to only that currently implemented
 * 
 * 315   31/12/97 12:19 Philipy
 * fixed screen res bug
 * 
 * 314   30/12/97 18:55 Philipy
 * new cogs
 * 
 * 313   30/12/97 12:23 Philipy
 * fixed difficulty setting text
 * 
 * 312   29/12/97 19:53 Philipy
 * various bug fixes
 * 
 * 311   29/12/97 9:16 Philipy
 * Shareware bug fixes
 * 
 * 310   24/12/97 9:17 Philipy
 * fixed a few minor spelling errors, plus 800x600 corruption
 * 
 * 309   12/23/97 9:59a Phillipd
 * Unwanted Tetxure Formats commented out...
 * Unwanted ScreenModes out...
 * Pickup Generation Sfx added
 * 
 * 308   19/12/97 10:32 Oliverc
 * Validate player bike after config file loaded
 * 
 * 307   18/12/97 23:07 Oliverc
 * Disabled debug mode etc from in-game menu for EXTERNAL_DEMOs
 * 
 * 306   18/12/97 22:07 Oliverc
 * Restricted selectable bikes in SHAREWARE version
 * 
 * 305   12/18/97 5:38p Phillipd
 * 
 * 304   12/18/97 5:37p Phillipd
 * 
 * 303   12/18/97 2:47p Phillipd
 * 
 * 302   12/17/97 5:19p Phillipd
 * 
 * 301   16/12/97 16:36 Oliverc
 * Level list now loaded from arbitrary file in Levels folder (mission.dat
 * for single player and battle.dat for multiplayer games), with existing
 * levels.dat used as a fallback for compatibility with existing levels
 * 
 * 300   12/16/97 2:44p Phillipd
 * 
 * 299   12/15/97 2:43p Phillipd
 * 
 * 298   12/12/97 15:36 Oliverc
 * Disabled cerain menu items for PCIDENT version
 * 
 * 297   12/12/97 10:22a Phillipd
 * Packets per second now dynamic
 * 
 * 296   11/12/97 16:45 Oliverc
 * Fixed 2nd "roll left" keydef to "roll right"
 * 
 * 295   12/11/97 2:09p Phillipd
 * Made a few changes.....SHAREWARE can now be defined to take out some
 * options..
 * 
 * 294   11/12/97 12:49 Oliverc
 * Changed registry key used to store game settings to be compatible with
 * InstallSheild3's automatic unInstall function
 * 
 * 293   12/10/97 10:39a Phillipd
 * Players names are now propergated across the network when changed...
 * Difficulty levels are functional....
 * 
 * 292   12/06/97 2:53p Phillipd
 * Fixed Phils Sfx Crash Bug....Doh
 * 
 * 291   5/12/97 21:55 Philipy
 * fixed sessions list bug
 * 
 * 290   3/12/97 16:28 Philipy
 * removed org_color from MX header group structure
 * 
 * 289   3/12/97 14:18 Philipy
 * added packets per second slider
 * 
 * 288   3/12/97 9:20 Philipy
 * VDU now pulsates on both sides, mode selection fixed ( although
 * choosing non-supported modes causes text to not be aligned properly )
 * 
 * 287   2/12/97 17:08 Oliverc
 * Removed total frame display from BOOT_DEMO SELF_PLAY mode
 * 
 * 286   2/12/97 14:52 Philipy
 * correct surface now restored after alt+tab
 * 
 * 285   2/12/97 11:52 Philipy
 * boot demo stuff
 * 
 * 284   1/12/97 17:07 Philipy
 * fixed no sound bug when in self play demo
 * 
 * 283   11/29/97 4:35p Phillipd
 * Xmem is now in effect...use it allways....
 * 
 * 282   27/11/97 12:35 Philipy
 * fixed sound bug on self play demo
 * demo playback speed now given as true percentage
 * 
 * 281   27/11/97 12:33 Oliverc
 * Added show node network option to debug menu
 * 
 * 280   11/27/97 10:39a Phillipd
 * 
 * 279   25/11/97 21:30 Oliverc
 * Phil fixed bug in level changing in-game
 * 
 * 278   21/11/97 11:21 Philipy
 * fxed releasing of splash screen
 * 
 * 277   11/21/97 10:56a Phillipd
 * Max Kills to end a level....
 * 
 * 276   17/11/97 17:45 Philipy
 * added average fps stuff
 * 
 * 275   14/11/97 17:36 Philipy
 * implemented mouse invert & sensitivity options.
 * You can now assign a key to more than one action (allows triple
 * chording)
 * 
 * 274   12/11/97 14:48 Philipy
 * fixed joining multiplayer bug
 * 
 * 273   7/11/97 14:25 Philipy
 * fixed bug when changing mode from title room: InitTitle was not being
 * called
 * 
 * 272   6/11/97 20:59 Philipy
 * fixed bug with joystick stuff
 * 
 * 271   6/11/97 10:26 Oliverc
 * 
 * 270   5/11/97 17:41 Philipy
 * fixed a couple of joystick bits
 * add invert mouse axis options
 * 
 * 269   5/11/97 10:54 Philipy
 * Fixed joystick button config stuff
 * 
 * 268   4/11/97 16:26 Philipy
 * AVI now plays for stats screens
 * implemented scrolling messages (not enabled)
 * 
 * 267   28/10/97 9:41 Philipy
 * Team member names now flash on team select screen when not ready
 * 
 * 266   27/10/97 15:35 Philipy
 * added in-game volume controls
 * 
 * 265   24/10/97 12:33 Philipy
 * more debug menu stuff
 * 
 * 264   24/10/97 12:07 Collinsd
 * zone display now works of menus.
 * 
 * 263   24/10/97 10:36 Philipy
 * Updated debug menus
 * 
 * 262   23/10/97 13:52 Collinsd
 * Added code to enable/disable compilation of software version.
 * SOFTWARE_ENABLE & softblit.lib.
 * 
 * 261   21/10/97 13:12 Philipy
 * added sound control options
 * 
 * 260   20/10/97 16:06 Oliverc
 * Enabled splash screen for EXTERNAL_DEMO mode
 * 
 * 259   16/10/97 18:08 Philipy
 * Implemented pre-game AVI player
 * 
 * 258   15/10/97 19:09 Oliverc
 * Last-minute bug fixes for SELF_PLAY demo version (done by Phil...not
 * Olly!)
 * 
 * 257   14/10/97 15:48 Oliverc
 * Fixed bug in list selection
 * 
 * 256   8/10/97 20:31 Philipy
 * 
 * 255   7/10/97 10:16 Philipy
 * fixed mouse look-up bug when starting subsequent games.
 * DInput() was being called every restart, with no corresponding
 * TermDInput().
 * DInput is now only ever done once (TitleOnceOnly)
 * 
 * 254   6-10-97 3:40p Philipy
 * Joystick info now loaded/saved for unconnected joysticks (prevents
 * information being lost from config file)
 * 
 * 253   3-10-97 12:17p Philipy
 * Joystick stuff almost done
 * 
 * 252   1-10-97 8:26p Philipy
 * IP address now only displayed when hosting IP game
 * 
 * 251   1-10-97 7:21p Philipy
 * more joystick stuff - writing to config, changed JOYSTICKINFO
 * structure, user interface for assigning buttons & axis.
 * Fixed bug that prevented you from going into wireframe mode - keyboard
 * buffer is now flushed in InitView, and TermDInput is not called from
 * ReleaseView (something needs to be done about releasing DirectX objects
 * when quitting from titles!)
 * 
 * 250   30-09-97 10:46a Philipy
 * "Create Game" screen now shows host IP Address
 * 
 * 249   30-09-97 9:49a Philipy
 * added in game ping options
 * 
 * 248   29-09-97 4:59p Philipy
 * fixed TCP address thing
 * some joystick btn config stuff
 * 
 * 247   29-09-97 4:04p Philipy
 * fixed menu select bug
 * 
 * 246   29-09-97 3:00p Philipy
 * added menu option for entering TCP address
 * 
 * 245   26-09-97 3:27p Philipy
 * config file can now store joystick info.
 * now only does InitDInput() at start of title screen, and TermDInput()
 * when quitting game
 * 
 * 244   18-09-97 4:45p Philipy
 * fixed single player level select and dynamic texture loading bugs
 * 
 * 243   18-09-97 11:07a Philipy
 * single player is f*cked
 * 
 * 242   17-09-97 4:10p Philipy
 * dynamic loading of bike chars and level pics, plus textures now not
 * loaded until after splash screen
 * 
 * 241   17/09/97 11:02 Collinsd
 * Hardware Text works again.
 * 
 * 240   16/09/97 17:52 Collinsd
 * More of Chris's stuff works.
 * 
 * 239   15-09-97 3:23p Philipy
 * message displayed, then correct menu displayed on new host machine if
 * host migrates.
 * Host can now start another game, having quit 'waiting to start' menu
 * 
 * 238   14-09-97 6:56p Philipy
 * joining existing team game - you can now select which team to go into,
 * and view current scores.
 * Set up VDU error message system
 * 
 * 237   12/09/97 18:00 Oliverc
 * Fixed crash bug in SELF_PLAY mode
 * 
 * 236   5-09-97 5:47p Philipy
 * Menus now use buffered keys
 * 
 * 235   5-09-97 4:12p Philipy
 * Changed menus to use buffered keys
 * 
 * 234   5/09/97 11:57 Collinsd
 * Reload same level added
 * 
 * 233   5-09-97 11:12a Philipy
 * demo playback stuff from new menus
 * 
 * 232   3/09/97 21:27 Oliverc
 * Disabled more menu keys for ECTS demo
 * 
 * 231   3/09/97 19:55 Oliverc
 * Forced player names & bike to match player slot number for ECTS demo
 * 
 * 230   3/09/97 17:05 Oliverc
 * More ECTS demo stuff
 * 
 * 229   3-09-97 3:52p Philipy
 * 
 * 228   3-09-97 3:42p Philipy
 * ECTS demo stuff
 * 
 * 227   3-09-97 12:33p Philipy
 * some text messaging stuff
 * started on ECTS demo
 * moved Our_CalculateFrameRate to above menu processing so that demos now
 * work.
 * 
 * 226   3/09/97 12:20 Oliverc
 * Added command-line options to set normal FOV and screen aspect ratio
 * for widescreen TVs
 * 
 * 225   2-09-97 2:45p Philipy
 * stopped menus from messing up when you press escape
 * 
 * 224   2-09-97 11:53a Philipy
 * fixed invalid bike no. problem
 * 
 * 223   2-09-97 10:14a Philipy
 * fixed level select bug
 * 
 * 221   1-09-97 5:35p Philipy
 * changes made for 3 & 4 player team game
 * 
 * 220   26-08-97 4:19p Philipy
 * most new menu versions of current menus now implemented
 * 
 * 219   22/08/97 11:49 Oliverc
 * Disabled first splash screen in SELF_PLAY mode unless
 * TWO_SPLASH_SCREENS is defined
 * 
 * 218   20/08/97 12:36 Oliverc
 * Changed (old) use_level_path to (new) use_local_data to indicate that a
 * player is testing a local copy of a level and doesn't want anyone else
 * to join his game
 * 
 * 217   14/08/97 17:56 Oliverc
 * 2nd splash screen now stays on for 10secs
 * 
 * 216   14-08-97 5:43p Philipy
 * added ability for any number of splash screens & properties
 * 
 * 215   14-08-97 4:37p Philipy
 * 
 * 214   14-08-97 3:54p Philipy
 * 
 * 213   11-08-97 5:01p Philipy
 * fixed problem of returning to title screen from main game
 * 
 * 212   11-08-97 3:17p Philipy
 * 
 * 211   9/08/97 14:56 Collinsd
 * Added ScreenPoly TPage Link list and flat shaded screen polys for phil
 * 
 * 210   8/08/97 14:18 Collinsd
 * Display of Polys has now been updated to use TPage link list.
 * 
 * 209   8-08-97 9:21a Philipy
 * Highlight box stuff
 * 
 * 208   7/08/97 21:25 Collinsd
 * Change FmPolys to use tpage link list.
 * 
 * 207   6-08-97 4:47p Philipy
 * finished new visuals menus
 * 
 * 206   6-08-97 11:35a Philipy
 * sliders and lists for VDU
 * 
 * 205   2/08/97 12:34 Oliverc
 * Added wireframe mode option for debugging group/portal visibility
 * 
 * 204   31/07/97 16:00 Oliverc
 * Added special SELF_PLAY features, including disabling critical unused
 * code and setting default values appropriate to demo attract mode
 * 
 * 203   31-07-97 3:47p Philipy
 * started detail level menus, plus additional stuff for self play mode
 * 
 * 202   29-07-97 11:02a Philipy
 * more SELF_PLAY stuff
 * 
 * 201   28-07-97 5:38p Philipy
 * SELF_PLAY stuff
 * 
 * 200   28-07-97 4:45p Philipy
 * SELF_PLAY option stuff
 * 
 * 199   28/07/97 16:44 Collinsd
 * Tracker uses ships to target, demo mode works again?
 * 
 * 198   28-07-97 12:12p Philipy
 * 
 * 197   28/07/97 11:59 Oliverc
 * Disabled selected menu items in SELF_PLAY mode
 * 
 * 196   25/07/97 12:10 Collinsd
 * Changed ships bike index, and changed skin for olly.
 * 
 * 195   24/07/97 17:46 Collinsd
 * 
 * 194   24-07-97 5:10p Philipy
 * 
 * 193   24/07/97 17:08 Collinsd
 * Added slick
 * 
 * 192   22-07-97 5:42p Philipy
 * loads of animation stuff switched over to new event system
 * 
 * 191   21/07/97 17:31 Collinsd
 * 
 * 190   17-07-97 3:49p Philipy
 * Started to create TITLE_EVENT structure and processes
 * 
 * 189   17/07/97 15:39 Oliverc
 * Added mouse wheel controls options to key configuration
 * as well as new cruise control keys
 * 
 * 188   17/07/97 15:38 Collinsd
 * BGObjects now use compobjs.
 * 
 * 187   16-07-97 4:36p Philipy
 * fixed selecting cerbero
 * 
 * 186   16-07-97 4:11p Philipy
 * added holo-bikes and scan lines
 * 
 * 185   16/07/97 12:34 Collinsd
 * Adder cerbero bike
 * 
 * 184   9-07-97 8:23p Philipy
 * changed so that only one VDU font is loaded at a time
 * 
 * 183   9-07-97 5:02p Philipy
 * added new font for 340x200
 * 
 * 182   9/07/97 16:59 Collinsd
 * Fixed MXA models in titles
 * 
 * 181   9-07-97 11:37a Philipy
 * changed all vdu text stuff, added a test bike
 * 
 * 180   8/07/97 16:30 Collinsd
 * Dicked about with include files FUCK!
 * 
 * 179   1/07/97 16:05 Collinsd
 * Added mofisto bike.
 * 
 * 178   25-06-97 9:20a Philipy
 * 
 * 177   25-06-97 9:14a Philipy
 * added 2nd VDU location, starting to use screen polys
 * 
 * 176   6/24/97 5:11p Phillipd
 * 
 * 175   6/24/97 11:12a Phillipd
 * 
 * 174   20-06-97 9:13a Philipy
 * added new models, room darkening effect and VDU pulsing effect
 * 
 * 173   20/06/97 8:51 Collinsd
 * Added more error messages to modeldisp.
 * 
 * 172   19/06/97 12:36 Collinsd
 * Added sprite text for menus
 * 
 * 171   6/19/97 10:25a Phillipd
 * 
 * 170   19/06/97 9:01 Collinsd
 * Added error checking to displaytitle()
 * 
 * 169   6/18/97 2:48p Phillipd
 * 
 * 168   17/06/97 17:18 Oliverc
 * Disabled debug mode and server mode menu items
 * 
 * 167   17/06/97 9:30 Oliverc
 * Made expiry period depend on EXPIRE_DAYS in demo_id.h
 * 
 * 166   17-06-97 9:23a Philipy
 * 
 * 165   16-06-97 2:12p Philipy
 * player select routine tidyed up
 * 
 * 164   16-06-97 9:17a Philipy
 * room darkens on panning to VDU
 * 
 * 163   6/14/97 2:27p Phillipd
 * 
 * 162   6/14/97 2:22p Phillipd
 * 
 * 161   13/06/97 16:03 Collinsd
 * Took out old bgobjects
 * 
 * 160   13/06/97 15:30 Collinsd
 * Taken out save BGObjects
 * 
 * 159   13-06-97 3:28p Philipy
 * new set up biker menus
 * 
 * 158   6/12/97 2:27p Phillipd
 * 
 * 157   10-06-97 9:00a Philipy
 * if'd out keys for moving around room
 * 
 * 156   9-06-97 9:04p Philipy
 * disabled some new menu commands for E3 demo
 * 
 * 155   9-06-97 6:45p Philipy
 * fixed vdu bug
 * 
 * 154   9-06-97 3:08p Philipy
 * 
 * 153   8-06-97 8:11p Philipy
 * set up menus for E3 Client demo
 * 
 * 152   7-06-97 9:13p Philipy
 * auto join a game
 * 
 * 151   7-06-97 4:50p Philipy
 * fixed more slider probs
 * 
 * 150   7-06-97 3:55p Philipy
 * fixed slider problem
 * 
 * 149   7-06-97 3:05p Philipy
 * control screens done
 * 
 * 148   6/07/97 1:20p Phillipd
 * 
 * 147   6/07/97 1:18p Phillipd
 * 
 * 146   6/07/97 10:52a Phillipd
 * 
 * 145   6/06/97 2:23p Phillipd
 * 
 * 144   6-06-97 2:19p Philipy
 * joining a game with new menus
 * 
 * 143   5/06/97 12:41 Collinsd
 * Reduced texture pages
 * 
 * 142   4-06-97 9:12p Philipy
 * coded all vdu processing functions
 * 
 * 141   21-05-97 10:27a Philipy
 * removed test numbers from menu
 * 
 * 140   5/21/97 10:18a Phillipd
 * 
 * 139   21-05-97 9:57a Philipy
 * set up status for camera
 * 
 * 138   19-05-97 8:21p Philipy
 * Texture animation stuff, plus correct disc stacks for new menu system
 * 
 * 137   12-05-97 6:13p Philipy
 * Disc animation stuff
 * 
 * 136   9-05-97 6:26p Philipy
 * positioned discs. Now highlights selected disc
 * 
 * 135   8-05-97 6:10p Philipy
 * Added functions to select appropriate disc
 * Modified MenuItemDrawCursor
 * 
 * 134   8-05-97 12:02p Philipy
 * started to place discs....
 * 
 * 133   7-05-97 6:13p Philipy
 * Implemented MenuFuncDraw (part of MENU structure)
 * Started to implement new menu system
 * 
 * 132   7-05-97 10:16a Philipy
 * Moved initialisation of camera, flags and rotation to LoadTitleModels
 * 
 * 131   7/05/97 9:57 Collinsd
 * Fixed reloading of title models.
 * 
 * 130   6-05-97 7:12p Philipy
 * 
 * 129   6-05-97 12:28p Philipy
 * 
 * 128   2-05-97 6:33p Philipy
 * 
 * 127   1-05-97 7:30p Philipy
 * Testing zooming in and out of menu room
 * 
 * 126   5/01/97 8:59a Phillipd
 * 
 * 125   4/30/97 5:35p Phillipd
 * 
 * 124   4/30/97 4:37p Phillipd
 * 
 * 123   30-04-97 3:22p Philipy
 * 
 * 122   4/30/97 12:28p Phillipd
 * 
 * 121   30/04/97 12:08 Oliverc
 * Removed "About" menu
 * 
 * 120   4/30/97 11:24a Phillipd
 * 
 * 119   29/04/97 17:36 Oliverc
 * Added "About" item to main menu
 * 
 * 118   4/28/97 4:14p Phillipd
 * 
 * 117   25/04/97 17:14 Collinsd
 * Added new bike
 * 
 * 116   4/25/97 5:12p Phillipd
 * 
 * 115   4/22/97 1:52p Phillipd
 * 
 * 114   16-04-97 4:38p Collinsd
 * Added reflecting bullets for all weapons except laser.
 * Cheat mode now has invul effect.
 * 
 * 113   4/15/97 10:57a Phillipd
 * 
 * 112   4/12/97 1:09p Phillipd
 * Detail levels are stored in the registry
 * 
 * 111   10-04-97 4:41p Collinsd
 * Added new bike models.
 * 
 * 110   4/08/97 12:39p Phillipd
 * 
 * 109   4/08/97 11:40a Phillipd
 * 
 * 108   4/05/97 12:08p Phillipd
 * 
 * 107   4/02/97 4:08p Phillipd
 * Added Weapon kill Stats..
 * 
 * 106   2-04-97 11:54a Collinsd
 * Added Jo bike
 * 
 * 105   4/02/97 11:01a Phillipd
 * 
 * 104   3/27/97 11:41a Phillipd
 * added texture format selection to the menus...
 * 
 * 103   3/25/97 9:21a Phillipd
 * current screen mode iis highlighted when you try and change it..
 * 
 * 102   24-03-97 3:55p Collinsd
 * Updated Lajay, Excop and added rhesus...
 * 
 * 101   3/20/97 2:34p Phillipd
 * Level Select is now in the menus....
 * 
 * 100   3/14/97 5:32p Phillipd
 * 
 * 99    3/13/97 11:28a Phillipd
 * Auto Detail level added..
 * Text all one colour unless printing own name...
 * 
 * 98    3/12/97 4:43p Phillipd
 * 
 * 97    3/11/97 5:41p Phillipd
 * 
 * 96    3/11/97 4:55p Phillipd
 * Demo Interpolate stuff is now working but not finished...
 * 
 * 95    10-03-97 7:49p Collinsd
 * Cheat mode no longer buggers up pickups.
 * 
 * 94    3/10/97 9:53a Phillipd
 * 
 * 93    2/26/97 3:10p Phillipd
 * 
 * 92    2/25/97 2:51p Phillipd
 * 
 * 91    2/24/97 4:47p Phillipd
 * GameElapsedTime is now relative to the demo not the
 * real world....so dynamic speed change is possible..
 * 
 * 90    2/24/97 12:21p Phillipd
 * 89    24-02-97 11:21a Collinsd
 * Added gravgon check for restart. and added bounding on object selection
 * depending on mode.
 * 
 * 88    2/24/97 10:00a Phillipd
 * Demo mode with multispeed has been added..
 * 
 * 87    2/14/97 3:21p Phillipd
 * 
 * 86    2/14/97 12:47p Phillipd
 * 
 * 85    13/02/97 13:48 Oliverc
 * Added genuine last compile time function and version fingerprinting
 * 
 * 84    12-02-97 3:27p Collinsd
 * 
 * 83    6/02/97 9:36 Oliverc
 * Added ENABLE_DEBUG_MENU #define flag
 * 
 * 82    2/05/97 12:01p Phillipd
 * nicer directplay bug handle..
 * 
 * 81    4-02-97 4:29p Collinsd
 * 
 * 80    2/03/97 5:16p Phillipd
 * Translusceny is now controlled by global execute buffers.... which is
 * much better...
 * 
 * 79    31-01-97 10:20a Collinsd
 * Light Details moved into detail menu.
 * 
 * 78    31-01-97 9:24a Collinsd
 * Added detail level for missile trails.
 * 
 * 77    30-01-97 3:47p Collinsd
 * 
 * 76    27-01-97 2:27p Collinsd
 * Added bsp volume display
 * 
 * 75    1/27/97 10:58a Phillipd
 * Textures enabled flag added to debug menu
 * 
 * 74    24-01-97 2:48p Collinsd
 * Added skin thickness to nodecube.
 * 
 * 73    22-01-97 6:00p Collinsd
 * Added debug node cube.
 * 
 * 72    1/22/97 3:17p Phillipd
 * moved toggle full screen
 * 
 * 71    20-01-97 11:21a Collinsd
 * Added time limit to multiplayer games.
 * 
 * 70    1/15/97 12:15p Phillipd
 * started work on the server mode
 * 
 * 69    1/13/97 5:40p Phillipd
 * added message macors to multiplayer....
 * 
 * 68    13/01/97 15:29 Oliverc
 * 
 * 67    10-01-97 3:54p Collinsd
 * Missile/Primary weapons no longer open doors before collision.
 * 
 * 66    10-01-97 12:51p Collinsd
 * Ooopss, Fixed Save Pickup/BGObject Menu.
 * 
 * 65    10-01-97 12:34p Collinsd
 * Added Doors, Chanded pickups/door/mine dropping.
 * 
 * 64    6-01-97 11:09a Collinsd
 * All references to timer now replaced with titanstar.
 * 
 * 63    6-01-97 9:06a Collinsd
 * Added drop ammo/shield options.
 * Started working on titan start missile.
 * 
 * 62    12/27/96 3:38p Phillipd
 * Primary.h Secondary.h pickups.h are now clean....
 * Still Lots to do though.....
 * 
 * 61    12/27/96 12:34p Phillipd
 * all files are not dependant on mydplay.h...just some..
 * including it several times in the same files didnt help..
 * 
 * 60    24/12/96 12:26 Oliverc
 * Added 14-day expiry date from time of last compilation of Title.c, as
 * well as saving current bike selection in player config file
 * 
 * 59    12/23/96 6:04p Phillipd
 * 
 * 58    12/23/96 8:50a Phillipd
 * 
 * 57    21/12/96 19:44 Oliverc
 * Changed bike select menu so that changes take effect immediately
 * 
 * 56    20-12-96 5:06p Collinsd
 * Added debug weapon feature.
 * 
 * 55    20/12/96 15:19 Oliverc
 * Changed debug menu to be on SHIFT-F1
 * 
 * 54    20/12/96 11:25 Oliverc
 * Fixed bug in menu searchkey processing
 * 
 * 53    19/12/96 16:20 Oliverc
 * 
 * 52    19/12/96 16:17 Oliverc
 * Added debug options menu with "go to room" function
 * 
 * 51    12/19/96 2:52p Phillipd
 * new 512x384/640x400 font added
 * 
 * 50    12/19/96 11:52a Phillipd
 * 
 * 49    12/19/96 11:43a Phillipd
 * 
 * 48    12/18/96 12:41p Phillipd
 * Copyright screen added..
 * 
 * 47    12/18/96 9:29a Phillipd
 * 
 * 46    12/18/96 9:22a Phillipd
 * 
 * 45    12/17/96 5:54p Phillipd
 * 
 * 44    12/17/96 4:57p Phillipd
 * Version Control Added..
 * 
 * 43    12/17/96 2:33p Phillipd
 * 
 * 42    12/17/96 9:20a Phillipd
 * 
 * 41    16/12/96 10:48 Oliverc
 * Added programmer-definable expiry date feature
 * 
 * 40    12/14/96 5:04p Phillipd
 * 
 * 39    13/12/96 14:22 Oliverc
 * Added debug help screen
 * 
 * 38    12/13/96 12:52p Phillipd
 * 
 * 37    12/13/96 11:19a Phillipd
 * 
 * 36    13/12/96 10:56 Oliverc
 * Added in-game help screen
 * 
 * 35    12/12/96 16:23 Oliverc
 * Changed game key reading to use DirectInput
 * 
 * 34    12/12/96 10:56a Phillipd
 * 
 * 33    11/12/96 17:59 Oliverc
 * Added weapon selection key definition menus
 * 
 * 32    12/11/96 5:25p Collinsd
 * Added nutter biker.
 * 
 * 31    12/10/96 3:54p Phillipd
 * 
 * 30    12/07/96 8:43p Collinsd
 * Added Jap Bird bike, Fixed mines being dropped and firing missile at
 * same time bug.  Added rotations when hit ( depending on damage ).
 * 
 * 29    12/04/96 4:55p Phillipd
 * 
 * 28    12/04/96 11:22a Collinsd
 * Added foetoid and new scaled bikes. Added sussgun richochet and sussgun
 * no ammo sfx, new load weapon sfx, and new transpulse/trojax sfx.
 * 
 * 27    12/04/96 11:20a Phillipd
 * Simplified Panel Started
 * 
 * 26    12/03/96 5:00p Phillipd
 * Quting if not host bug fixed...
 * game doesnt start if ya just quit the title screen...
 * 
 * 25    12/03/96 10:40a Phillipd
 * Multiplay can now back out
 * 
 * 24    12/02/96 11:22a Phillipd
 * 
 * 23    2/12/96 11:20 Oliverc
 * Made bike selection available in-game
 * 
 * 22    12/01/96 1:21p Phillipd
 * You can now quit a game go back to the title screen and start or join
 * another....
 * 
 * 21    11/29/96 3:10p Phillipd
 * Full screen from menu toggle...
 * Fixed the mouse lag problem again....
 * 
 * 20    11/28/96 11:28a Phillipd
 * You can see who is in a game and how many players
 * there should be...
 * 
 * 19    11/28/96 10:00a Phillipd
 * Multiplayer join changed beyond all recognition,,,
 * 
 * 18    11/26/96 5:23p Collinsd
 * Added trucker biker
 * 
 * 17    11/26/96 12:35p Collinsd
 * Should hopefully fix problem.
 * 
 * 16    11/25/96 11:59a Phillipd
 * 
 * 15    11/22/96 5:10p Phillipd
 * 
 * 14    11/22/96 9:20a Phillipd
 * Put in c for asm flag and made a bit more watcom compatible
 * 
 * 13    21/11/96 11:46 Collinsd
 * Added f6-f12 controlled by main menu dubug option.
 * 
 * 12    11/21/96 11:23a Phillipd
 * 
 * 11    11/20/96 2:42p Phillipd
 * players can now restart and keep there score...
 * 
 * 10    18/11/96 19:30 Oliverc
 * Changed menu toggle/back out key to ESC and stopped ESC from quitting
 * the program
 * 
 * 9     11/18/96 3:26p Phillipd
 * 
 * 8     11/18/96 12:23p Phillipd
 * New stuff..
 * 
 * 7     14/11/96 17:37 Oliverc
 * Added in-window in-game menus
 * 
 * 6     11/13/96 5:07p Phillipd
 * title pics name now 8 chars long...
 * 
 * 5     11/13/96 9:08a Phillipd
 * All the Menus in the world....And then Some
 * 
 * 4     7/11/96 10:47 Collinsd
 * Shortened short ships structures.
 * 
 * 3     10/29/96 4:02p Phillipd
 * 
 * 2     10/29/96 2:49p Phillipd
 * panning sfx and new panel....with lights...
 * 
 * 1     10/28/96 8:49a Phillipd
 */


/*�������������������������������������������������������������������
	Include Files...	
�������������������������������������������������������������������*/
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include "typedefs.h"
#include <dplay.h>
#include "new3d.h"
#include "quat.h"
#include "CompObjects.h"
#include "bgobjects.h"
#include "Object.h"
#include "mydplay.h"

#include "d3dmain.h"
#include "typedefs.h"
#include <time.h>
#include <dplay.h>
#include <dplobby.h>
#include "ddutil.h"
#include "sfx.h"
#include "Text.h"
#include "dinput.h"
#include "main.h"
#include "controls.h"
#include "config.h"
#include "title.h"
#include "MultiPlayer.h"
#include "2dtextures.h"
#include "mload.h"
#include "primary.h"
#include "secondary.h"
#include "triggers.h"
#include "pickups.h"
#include "models.h"
#include "lastcomp.h"
#include "camera.h"
#include "models.h"
#include "polysort.h"
#include "polys.h"
#include "2dpolys.h"
#include "screenpolys.h"
#include "demo_id.h"
#include "lines.h"
#include "cdaudio.h"
#include "loadsave.h"
#include "splash.h"
#include "magic.h"
#include "dpthread.h"
#include "XMem.h"
#include "ddsurfhand.h"

#include "force.h"
#include "feedback.h"
#include "comm.h"
#include "restart.h" 

#include "local.h"

#define MAX_SAVEGAME_SLOTS		16

#define MAX_DEMONAME_LENGTH		(60)
#define MAX_DEMOFILENAME_LENGTH	(80) // must be at least MAX_DEMONAME_LENGTH + strlen( DEMOFOLDER ) + strlen( DEMOFILE_EXTENSION ) + 1
#define MAX_PILOTNAME_LENGTH	(MAX_PLAYER_NAME_LENGTH - 1)

#define DEMOFOLDER				"Demos"
#define DEMOFILE_EXTENSION		".DMO"
#define DEMOFILE_SEARCHPATH		DEMOFOLDER"\\*"DEMOFILE_EXTENSION

//#pragma optimize( "gty", on )

#if 1
int total_malloced = 0;
void *mem;
#if 0
#define X_malloc( THINGAMAJIG )\
 ( DebugPrintf( "malloc( %s ) total_malloced = %d address %X\n", #THINGAMAJIG, ++total_malloced , (int) (mem = malloc( THINGAMAJIG ) ) ), mem)
#define X_free( THINGAMAJIG ) \
( DebugPrintf( "address %X free( %s )  total_malloced = %d\n", (int)THINGAMAJIG, #THINGAMAJIG, --total_malloced ), free( THINGAMAJIG ) )
#endif
#endif


#define HardClear TRUE

#define ENABLE_DEBUG_MENU
//#undef ENABLE_DEBUG_MENU

#define DEMO_MENUS

extern BOOL g_OddFrame;
extern BOOL ZClearsOn;
extern BOOL SetZProj( void );
extern BOOL SetZCompare();

extern void SetViewportError( char *where, D3DVIEWPORT *vp, HRESULT rval );

BOOL AllowServer = FALSE;

extern BOOL ShowNamesAnyway;
extern	BOOL ResetKillsPerLevel;

BOOL SpaceOrbSetup = FALSE;
BOOL LevelsOnCD = FALSE;
void DefaultJoystickSettings( USERCONFIG *u );
void ReInitJoysticks( void );

#define MAX_KEYDEF_PAGES	(4)
int CurrentPage = 0;
int MaxPage = 0;
void GetLevelName( char *buf, int bufsize, int level );
void MenuItemDrawPageName( MENUITEM *Item );
void InitKeyDef( MENU *Menu );
void InitKeyDefPage( MENU *Menu );
void DrawKeyDefPage( MENUITEM *item );
void DrawKeyDefHelp1( MENUITEM *item );
void DrawKeyDefHelp2( MENUITEM *item );
void DrawKeyDefHelp3( MENUITEM * Item );
void DrawFlatMenuKeyLeftArrowText( MENUITEM *Item );
void DrawFlatMenuKeyLeftArrow( MENUITEM *Item );
void DrawFlatMenuKeyRightArrowText( MENUITEM *Item );
void DrawFlatMenuKeyRightArrow( MENUITEM *Item );
void DrawFlatMenuKeyNum( MENUITEM *Item );
static void KeyDelete( DEFKEY *kdef, int key );
static void KeyDeleteRepeating( DEFKEY *key );
static void KeySelect( DEFKEY *kdef, int key );

BOOL DeletePilot( LIST *l, int item );
void MoveConfigFile( MENU *Menu );

extern void ShowNodeNetwork( uint32 NetMask );
void ProcessTextItems (void);

char cd_path[ 256 ] = "";


BOOL	SWMonoChrome = FALSE;
BOOL	Last_SWMonoChrome = FALSE;

#ifdef SOFTWARE_ENABLE
/*�������������������������������������������������������������������
		Chris's Code
�������������������������������������������������������������������*/
void	CWExecute2(	LPDIRECT3DDEVICE lpDev,
					LPDIRECT3DEXECUTEBUFFER execbuf,
					LPDIRECT3DVIEWPORT lpView,
					WORD cwFlags);
extern void CWScanExecuteBuffer( LPDIRECT3DEXECUTEBUFFER execbuf );
void CWClearZBuffer( void );

extern char CWInTitle;
extern	BOOL	SoftwareVersion;
void ScanAllBikes( void );

/*�����������������������������������������������������������������*/
#endif

/*�������������������������������������������������������������������
		Externals ...
�������������������������������������������������������������������*/
extern BOOL WaitingToQuit;
extern BOOL DoHeartbeat;
extern BOOL ServerHeartbeat;
extern BOOL PeerPeerHeartbeat;
extern DPID LobbyPlayerIDs[ MAX_PLAYERS ];
extern uint16 NumLobbyPlayers;
extern int16	NumPrimaryPickups;
extern BOOL ServiceProviderSet;
extern	BOOL IsServerGame;
extern BOOL ServerCollisions;
extern	BOOL IsServer;
extern BOOL ServerRendering;
extern GUID	ServiceProvidersGuids[];
extern char SessionNames[ MAXSESSIONS ][ 128 ];

extern DPSESSIONDESC2	Sessions[];
extern BOOL	BigPackets;
extern float FlashTextActive;
extern BOOL NoDynamicSfx;
extern float GlobalSoundAttenuation;
extern float WATER_CELLSIZE;
extern BOOL flush_input;
extern double	Gamma;
extern LPDIRECTINPUTDEVICE lpdiBufferedKeyboard;
extern uint16 CurrentAttractDemo;
extern LPDPLCONNECTION glpdplConnection;
extern BOOL UseShortPackets;
extern BOOL ResetKillsPerLevel;
extern BOOL IsLobbyLaunched;
extern BOOL LobbyAutoStart;
extern BOOL	Pal332;
extern char data_path[];
extern char normdata_path[];
extern int use_data_path;
extern SNDLOOKUP SndLookup[];
extern int CrystalsFound;
extern	int16	NumGoldBars;
extern int Secrets;
extern int TotalSecrets;
extern	int16		NumInitEnemies;
extern	int16		NumKilledEnemies;

extern MODELNAME *TitleModelSet;

int GameCompleted = GAMECOMPLETE_NotComplete;

#define NUM_TITLE_LOOPS 2
#define TITLE_LOOP_DiscAmbience 0
#define TITLE_LOOP_VduAmbience 1
uint32 TitleLoopId[ NUM_TITLE_LOOPS ];

BOOL MouseInput = TRUE;
BOOL JoystickInput = TRUE;

BOOL NoSplash = FALSE;

BOOL CTF = FALSE;
BOOL NeedFlagAtHome = TRUE;
BOOL CanCarryOwnFlag = FALSE;
BOOL OwnFlagTeleportsHome = TRUE;

int	DPlayUpdateIntervalCmdLine = 0;
int	GoalScore = 5;
int BountyBonusInterval = 10;

float LevelTimeTaken;

BOOL NoMenuBack = FALSE;

BOOL FeedbackEnable = TRUE;
SLIDER FeedbackGainSlider = {0, 100, 10, 100 };
SLIDER FeedbackXSlider = {-1, 1, 1, 1 };
SLIDER FeedbackYSlider = {-1, 1, 1, 1 };
BOOL FeedbackXEnable = TRUE;
BOOL FeedbackYEnable = TRUE;
BOOL FeedbackXInvert = FALSE;
BOOL FeedbackYInvert = FALSE;
BOOL FeedbackEffectEnable[ FF_EFFECT_MAX ];
SLIDER FeedbackEffectGainSlider[ FF_EFFECT_MAX ];

int16 DummyTextureIndex;
extern FRAME_INFO	*	Title_LevelPics_Header;
extern FRAME_INFO	*	Title_TVFrame_Header;
extern char MissionTextNames[MAXLEVELS][128];
extern char MissionTextPics[MAXLEVELS][128];
extern int32 ColPerspective;
extern BOOL	JustExitedMenu;
extern BOOL	PickupValid[ MAXPICKUPTYPES ];
extern	BOOL LockOutWindows;
extern SLIDER BikerSpeechSlider;
extern int16 Lives;
extern BYTE	GameStatus[];	// Game Status for every Ship...
extern BOOL LogosEnable;
extern BOOL PreventFlips;
extern BOOL bSoundEnabled;
extern float DemoAvgFps;
extern float DemoTotalTime;
extern int32 DemoGameLoops;

extern	BOOL ShowTrigZones;
extern	BOOL ShowEFZones;
extern	BOOL ShowTeleports;
extern  BOOL ShowBoundingBoxes;
extern  BOOL ShowColZones;

extern	CDSound		sound;
extern	CDInfo		cd_info;
extern	int16		actual_volume;
extern	BOOL		CD_Present;
extern	int	RearCameraActive;

	
char *ShipAxisSeperateText[NUM_SHIP_AXIS_ACTIONS * 2];
extern char *JoystickPOVDirections[];
extern BOOL IPAddressExists;
extern char *ShipAxisText[];
extern int ShipAxisLookup[];
extern uint16 new_input;
extern DIJOYSTATE2		js[ INPUT_BUFFERS ][ MAX_JOYSTICKS ];
extern char  IPAddressText[];
extern char *ShipActionText[];
extern JOYSTICKINFO	JoystickInfo[MAX_JOYSTICKS];	
extern int	Num_Joysticks;
extern TLOADHEADER	Tloadheader;
extern DIDEVICEOBJECTDATA rgod[DINPUT_BUFFERSIZE]; /* Receives buffered data */
extern DWORD BufferedKey[];
extern int16 NumKeysToProcess;
extern DPID	TeamIDs[MAX_TEAMS][MAX_PLAYERS];
extern int	TeamMembers[MAX_TEAMS];
extern	int16	ShowPortal;
extern BOOL	Is3Dfx;
extern BOOL	PolyText[255];
extern float VduScaleX, VduScaleY;

extern	FMPOLY			FmPolys[MAXNUMOF2DPOLYS];
extern	POLY   			Polys[MAXPOLYS];
extern  SCRPOLY			ScrPolys[ MAXNUMOFSCRPOLYS ];
extern	LINE			Lines[ MAXLINES ];
extern	MXALOADHEADER	MxaModelHeaders[ MAXMXAMODELHEADERS ];

extern	FRAME_INFO	*	Title_Fonts_Header;
extern	FRAME_INFO	*	Title_Chars1_Header;
extern	FRAME_INFO	*	Title_Chars2_Header;
extern	OFF_FILES Title_OffsetFiles[];

extern	CAMERA	CurrentCamera;

void Build_View();

extern	LPDIRECT3DEXECUTEBUFFER RenderBufs[ 2 ];

extern	int			use_local_data;
extern	int16		NumLevels;
extern	char		ShortLevelNames[MAXLEVELS][32];

extern	GLOBALSHIP              Ships[MAX_PLAYERS];

extern	SHORTNAMETYPE			Names;	// all the players short Names....


#define REGISTRY_EXPIRE_TIME	"ServiceID"

#define DEFAULT_CONFIG_FILE		DEFAULT_PLAYER_NAME".cfg"

char	*config_name = NULL;
char	old_config[256] = "";
char	biker_config[256] = DEFAULT_CONFIG_FILE;
char	biker_name[256] = DEFAULT_PLAYER_NAME;
char	bike_name[16];
char	biker_text[512];

BOOL	quitting = FALSE;
int16	SelectedBike = 0; //MODEL_Borg;
int16	NumTitleModelsToLoad;

HKEY                     ghCondemnedKey=NULL;     // Condemned registry key handle
DWORD                    gdwCondemnedDisp;        // key created or opened

float TriggerInitialAnimation = 0.0F;

BOOL	Our_CalculateFrameRate(void);

float	AttractModeCountDown;
extern	uint16			FirstFmPolyUsed;
extern	uint16			FirstPolyUsed;
extern	uint16			FirstLineUsed;
extern	uint16			FirstScrPolyUsed;
extern USERCONFIG *player_config;
extern	float framelag;
extern	BOOL	PowerVR;
extern	BOOL	bPolySort;
extern	BYTE	MyGameStatus;
extern	int		FontWidth;
extern	int		FontHeight;
extern	int		FontSourceWidth;
extern	int		FontSourceHeight;
BOOL	ShowWeaponKills = FALSE;
extern	LPDIRECTDRAWSURFACE     lpDDSTwo;
extern	DDCOLORKEY				ddcolorkey;
LPDIRECTDRAWSURFACE		lpDDSTitleFont;

extern	LPDIRECT3DMATERIAL lpBmat;		// a Material for the Background clearing
		
extern	int16	ModeCase;

extern	int16	ModesX[8];
extern	int16	ModesY[8];
extern	float	ModeScaleX[8];
extern	float	ModeScaleY[8];
extern BOOL	E3DemoHost;
extern BOOL	E3DemoClient;
extern BOOL E3DemoLoop;

extern	DWORD                   Old_WhoIAm;

extern	DPSESSIONDESC2			Old_Session;

extern	DWORD					Old_Kills;
extern	DWORD					Old_Deaths;
extern	DWORD					Old_TeamNumber;
extern	char					Old_Name[256];
extern	BOOL					Rejoining;

extern	BOOL					HostDuties;

extern	int16	BikeModels[ MAXBIKETYPES ];
extern	MLOADHEADER Mloadheader;
extern  LONGLONG GameStartedTime;


extern int16		LevelNum;
extern int16		NewLevelNum;
extern int16		NumLevels;
extern char	ShortLevelNames[MAXLEVELS][32];

extern	BOOL                    IsHost;
extern	D3DMATRIXHANDLE hView;
extern	D3DMATRIXHANDLE hWorld;
extern	D3DMATRIX view;
BOOL	ClearBuffers( BOOL ClearScreen, BOOL ClearZBuffer );
extern	LPDIRECT3DEXECUTEBUFFER lpD3DNormCmdBuf;
extern	LPDIRECT3DEXECUTEBUFFER lpD3DTransCmdBuf;
extern	LPDIRECT3DEXECUTEBUFFER lpD3DSpcFxTransCmdBuf;
extern	MATRIX	MATRIX_Identity;
extern	D3DVIEWPORT viewport;

extern	MODEL	Models[];
uint16	BackgroundModel[NUMOFTITLEMODELS];
extern	TLOADHEADER Tloadheader;
extern	float	LastDistance[];
extern	MXLOADHEADER ModelHeaders[];
extern	MODELNAME	TitleModelNames[]; 
extern	MODELNAME	InterLevelModelNames[];
extern	BOOL	bPolyText;
extern	char *PrimaryDescription[];
extern	char *SecondaryDescription[];
extern	BOOL	ShowUntriggeredNMEs;
extern	BOOL	BilinearSolidScrPolys;
extern	BOOL	RandomPickups;
extern	BOOL CreditsToggle;

#ifdef SOFTWARE_ENABLE

extern	long	GlBright;

#endif

/*�������������������������������������������������������������������
		Tracker stuff..
�������������������������������������������������������������������*/
LIST	TrackersList = { 0 };

/*�������������������������������������������������������������������
		Mode changing stuff..
�������������������������������������������������������������������*/
LIST	ModeList = { 0 };
int		WhichMode[ MAXLISTITEMS ];
int		ScreenWidth = 0;
int		ScreenHeight = 0;
int		ScreenBPP = 0;
/*�������������������������������������������������������������������
		Texture Format changing stuff..
�������������������������������������������������������������������*/
LIST	TextureList = { 0 };
int		TexturePalettized = -1;
int		TextureRedBPP = 0;
int		TextureGreenBPP = 0;
int		TextureBlueBPP = 0;
int		TextureAlphaBPP = 0;
int		TextureIndexBPP = 0;

SLIDER GammaSlider = {50, 200, 10, 100, 0, 0.0F, 0.0F, 0, FALSE, NULL, NULL, SetGamma };

/*�������������������������������������������������������������������
		Level changing stuff..
�������������������������������������������������������������������*/
LIST	LevelList = { 0 };
char SelectedLevel[128];
char SelectedLevelText[MAX_LEVEL_TEXT_LENGTH];

BOOL	ECTSDemo;

/*�������������������������������������������������������������������
		Joystick stuff..
�������������������������������������������������������������������*/
char	NoBtnText[] = "not currently assigned";
char	MultiBtnText[] = "multiple buttons assigned";
char	NoPOVText[] = "No POV selected";
char	JoyMode1[] = "use the cursor keys to select an action, then press enter";
char	JoyMode2[] = "Press a joystick button to assign to this action";
char	JoystickModeText[64];
LIST	JoystickList = { 0 };
char    JoystickBtnText[64];
char    JoystickPOVText[64];
char	AxisExtremeLeftText[64];
char	AxisExtremeRightText[64];
char    JoystickPOVDirectionText[64];
char	SelectedActionText[64];
LIST ShipActionList = { 0 };
typedef struct
{
	int type;
	int num;
	int dir;
}PSEUDOJOYBTN;
#define BTNTYPE_Button 0
#define BTNTYPE_POV 1
int CurrentJoyPOV;
int	CurrentJoyPOVDirection;
LIST JoystickAxisList = { 0 };
LIST AxisActionList = { 0 };
BOOL AxisInvert = FALSE;
BOOL FineControl = FALSE;
SLIDER DeadzoneSlider = {0, 100, 5, 30 };
SLIDER SensitivitySlider = {0, 100, 5, 50 };
SLIDER AxisSlider;
SLIDER AxisActionSlider;
int AxisMap[MAX_JOYSTICK_AXIS];
int JoystickMap[MAX_JOYSTICKS];
#define NUM_AXIS_TEST_SCRPOLYS 2
uint16 AxisTestScrPoly[NUM_AXIS_TEST_SCRPOLYS];
#define AXISTEST_XPos 20
#define AXISTEST_YPos 150
#define AXISTEST_Width 160
#define AXISTEST_Height 10
#define AXISTEST_PtrWidth 30
float AxisPtr_xmin, AxisPtr_xmax, AxisPtr_ymin, AxisPtr_ymax, AxisPtr_mid;
#define JOYCONFIG_SelectAction 0
#define JOYCONFIG_AssignButton 1
int JoystickConfigState;


BOOL InTitleRoom;


char DemoAvgFpsText[128];
char DemoTotalFramesText[128];

/*�������������������������������������������������������������������
		Error message stuff..
�������������������������������������������������������������������*/
char ErrorMessage[256];
char NotifyMessage[ 256 ];
int	ErrorMoveBackBy;
MENU * ErrorNewMenu;
BOOL IgnoreMenuFuncs = FALSE;

/*�������������������������������������������������������������������
		Fucntions without a header..
�������������������������������������������������������������������*/
void InitBattleMenu( MENU *Menu );
void StartAManualServer( MENUITEM *Item );
void StartAnAutoServer( MENUITEM *Item );
void InitInGameLevelSelect( MENU *menu );
void TestMenuFormat( void );
void CheckForRogueSfx( void );
void CheckCheats( VirtualKeycode key );

void JoystickChosen(MENUITEM *Item);

char *CTF_Type( SLIDER *s );

void InGameSaveASinglePlayerGame( MENUITEM *item );
int folder_exists( char *pathspec, ... );

char TypeFileName( TEXT *t, char c );
char *DemoFileName( char *demoname );
char *DemoName( char *demofilename );

void LoadLevelText( MENU *Menu );
BOOL InitDInput(void);
BOOL TermDInput( void );
int GetPOVDirection( DIJOYSTATE2 *data, int POVNum );
void ShowSplashScreen( int num );
void BigPacketsSelected( MENUITEM *Item );
void ShortPacketsSelected( MENUITEM *Item );
void ToggleBikeEngines( MENUITEM *Item );
void DrawHelpKey( MENUITEM * Item );
int GetFontInfo( MENUITEM * Item );
void DrawBikeLabel ( MENUITEM * Item );
void DrawNameVar( MENUITEM * Item );
void DrawCenteredNameVar( MENUITEM * Item );
void InitDetailLevels( MENU *Menu );
void ExitDetailLevels( MENU *Menu );
void NewInitBikeMenu ( MENU *Menu);
void InitBikerMenu( MENU *Menu );
void InitBikeComputerMenu( MENU *Menu );
void ExitBikerMenu( MENU *Menu );
void InitBikeListVDU( MENU *Menu );
void InitLevelSelectVDU( MENUITEM *Item );
void InitBikeList( MENU *Menu );
void InitControls( MENU *Menu );
void ExitControls( MENU *Menu );
void InitVDUPilotMenu ( MENU *Menu );
void InitPilotMenu( MENU *Menu );
void SelectPilot( MENUITEM *item );
void InitPilotName( MENU *menu );
void SetPilotName( MENUITEM *item );
void SetPilotNameInGame( MENUITEM *item );
void InitPilotReName( MENU *menu );
void RenamePilotName( MENUITEM *item );
void InitStartMenu( MENU *Menu );
void ExitInGameMenu( MENU *Menu );
void InitMultiplayerHostVDU( MENU *Menu );
void InitMultiplayerHostVDUServer( MENU *Menu );
void InitMultiplayerHostVDUPeerPeer( MENU *Menu );
void InitPseudoHostGameScreen( MENU *Menu );
void InitLobbyWaitingForHost( MENU *Menu );
void InitSinglePlayerGame( MENU *Menu );
void InitTitleLoad( MENU *Menu );
void ExitTitleLoad( MENU *Menu );
void InitBikerName( char *name );
void InitMultiplayerHost( MENU *Menu );
void InitMoreMultiplayerOptions( MENU *Menu );
void InitInGameOptions( MENU *Menu );
void ExitMoreMultiplayerOptions( MENU *Menu );
void SetAutolevel( MENUITEM *item );
void SelectQuitCurrentGame( MENUITEM *Item );
void ExitBikeSelection( MENUITEM * menu );
void InitShareWareBikeList( MENU *Menu );
void ExitShareWareBikeSelection( MENUITEM * menu );
void ExitBikeComputerSelection( MENUITEM * item );
void InitDebugMenu( MENU *Menu );
void InitDebugMode( MENU *Menu );
void InitRoomList( void );
void SetRoomName( MENUITEM *item );
void ChooseRoom( MENUITEM *item );
void DebugModeChanged( MENUITEM *item );
void DebugVisibleChanged( MENUITEM *item );
void SavePickups( MENUITEM *item );
void ShowNodeToggle( MENUITEM *item );
void ShowStartPointsToggle( MENUITEM *item );
void TexturesEnabledToggle( MENUITEM *item );
void SetLightStates( MENUITEM *item );
void InitDemoList( MENU * Menu );
void GetGamePrefs( void );
void SetGamePrefs( void );
void GetMultiplayerPrefs( void );
void SetMultiplayerPrefs( void );
void InitShareWareBikeList( MENU *Menu );
void ExitShareWareBikeSelection( MENUITEM * menu );
void InitFeedbackMenu( MENU *Menu );
void ExitFeedbackMenu( MENU *Menu );
void InitLoadSavedGameList( MENU * Menu );

char *SearchKey( char c );
void PauseDemoToggle( MENUITEM *Item );

BOOL InitLevels( char *levels_list );
void InitLevelSelect( MENU *Menu );
void ExitLevelSelect( MENU * Menu );
void GoToStats( MENUITEM *Item );
void MenuTextureMode( MENU *Menu );
void NewMenuTextureMode( MENU *Menu );
void MakeTextureList( MENU *Menu );
void GetSavedGameData( void );

SetFOV( float fov );
BOOL TintModelVertices( uint16 Model, float percent, EXCLUDEDVERTICES *Exclude );
BOOL MakeTranslucent( uint16 Model );
void GetExtremeOffsets( uint16 Model, PLANE *plane, float *minoffset, float *maxoffset );
BOOL TintOneVertex( uint16 Model, uint16 Group, uint16 ExecBuf, int VertexNo, float tr, float tg, float tb, float ta );

BOOL CompareVectors(VECTOR vector1, VECTOR vector2);
void SetDiscStatus(MENU *menu);
void PlaceObjects (void);
void HighlightDisc(int disc);
void ResetDisc(int disc);
void TintDisc(uint16 Model);
void ExpandDiscs(void);
void SetUpRotate(int disc);
void RotateDiscs(int disc, int DifficultyLevel);
void WiggleDiscs(void);
void SetTextures (MENU *menu);
void InitDifficultyLevel ( MENU *Menu );
void DifficultySet (MENUITEM *item);
void ProcessVduItems( MENU * Menu );
void KillTextInfo ( TEXTINFO *TextInfo );

void SetInitialTitleParams();
void RotateHoloLight(void);
void PlotBikeScanLine(void);
void PulsateVDU(void);
void MorphHoloLight(void);
BOOL IncreaseVertexY(uint16 Model, uint16 Group, uint16 ExecBuf, int VertexNo, float IncreaseBy);
BOOL MovePPMToVideoMemory( TLOADHEADER *Tloadheader, int16 n, LPDIRECTDRAWSURFACE lpSrcTextureSurf );

void DebugPrintf( const char * format, ... );

BOOL DeleteSavedGame( LIST *l, int item );
BOOL DeleteDemo( LIST *l, int item );
BOOL ListDelete( LIST *l, int item );

char *AxisName( SLIDER *s );
char *AxisActionName( SLIDER *s );
BOOL SetAxisSlider( SLIDER *s );
BOOL SetAxisActionSlider( SLIDER *s );

void InitServerMenu( MENU *Menu );
void ServerListPlayerSelected( MENUITEM *Item );

/**************************
new text functions
***************************/
BOOL DrawTextEditCursor( TEXTINFO *TextInfo, int font );
void GetTextPos(TEXTINFO *TextInfo, float *xpos, float *ypos, int line, float totalheight);
BOOL DisplayTextCharacter(TEXTINFO *TextInfo, int line, int pos, int font, float totalheight);
void Print3Dots(TEXTINFO *TextInfo, float totalheight);
void DisplayTextItem (TEXTINFO *TextInfo);
void GetFinalChars( TEXTINFO *TextInfo, int currentpos, int length);
void PrintTextItem (TEXTINFO *TextInfo);
BOOL FormatTextItem(int start, int end, TEXTINFO *TextInfo, BOOL *newline);
int GetScreenFont(int fontsize);
BOOL Plot2dBox (TEXTINFO *TextInfo);
void InitScreenFonts (void);
TEXTINFO *InitTextInfo( void );
void DrawFlatMenuListText ( MENUITEM *Item );
void DrawLeftArrow( MENUITEM *Item );
void DrawRightArrow( MENUITEM *Item );
void DrawFlatMenuList( MENUITEM *Item );
void DrawSplitMenuList( MENUITEM *Item );
void AddToFlatMenuList( MENUITEM *Item );
void RedrawFlatMenuList( MENUITEM *Item );
void DrawFlatMenuText( MENUITEM *Item );
void DrawFlatTextStatus( MENUITEM *Item );
void DrawFlatMenuItem( MENUITEM *Item );
void DrawSessionNameText( MENUITEM *Item );
void DrawConditionalText( MENUITEM *Item );
void DrawConditionalName( MENUITEM *Item );
TEXTINFO * DrawFlatToggleStatus( MENUITEM *Item );
void UpdateSlider (MENUITEM *Item);
void DrawFlatSliderStatus( MENUITEM *Item );
void SelectFlatRadioButton( MENUITEM *Item );
void SelectFlatMenuToggle( MENUITEM *Iem );
void SelectMultiToggle( MENUITEM *Item );
void DrawFlatMenuToggle( MENUITEM *Item );
void RedrawFlatMenuKey( MENUITEM *Item);
void SelectFlatMenuKey( MENUITEM *Item );
void CheckKeysForChanges( void );
void DrawFlatMenuKeyText( MENUITEM *Item );
void DrawFlatMenuKey( MENUITEM *Item );
void DrawFlatRadioButton( MENUITEM *Item );
void ProcessFlatSliders(void);
void RedrawFlatMenuSlider( MENUITEM *Item );
SLIDER *GetSlider( MENUITEM *Item, int *slidertype );
void DrawFlatMenuSlider( MENUITEM *Item );
void DrawFlatMenuName (MENUITEM *Item);
void DrawGeneralWeaponText( MENUITEM *Item );
void DrawGeneralWeapons( MENUITEM *Item );
void DrawSecondaryWeapons( MENUITEM *Item );
void StoreWeaponOrder( MENU *Menu );
void DrawPrimaryWeapons( MENUITEM *Item );
void GetBikeDetails(int Bike, MENUITEM *item);
void SelectFlatMenutext( MENUITEM *Item );
void SendTitleMessage(MENUITEM *Item);
void InitAttractMode( MENU *Menu );
void PrepareNextLevelStart( MENU *Menu );
void HostAboutToStart( MENUITEM *Item );
void PseudoHostAboutToStart( MENUITEM *Item );
void ToggleCDAudio( MENUITEM *Item );
void ToggleCDAudioTitles( MENUITEM *Item );
void ExitSoundMenu( MENU *Menu );
void MakeUnselectable( MENUITEM *Item );
void SendQuickText( MENUITEM *Item );
void SendQuickTextWhisper( MENUITEM *Item );
void InitCrystalsFoundText( MENU *Menu );
void SelectGoldBarModel( MENU *Menu );
void AfterSpecialMessage( MENUITEM *Item );
void NextLevelOrGameComplete( MENUITEM *Item );
BOOL SetUpLines (uint16 Model, PLANE plane, VECTOR *rot);
void KillLines(void);
void KillDerivedPlane(void);
void KillPlane(void);
void SwapBikes(void);
BOOL LoadBike(void);
void GetVduTextFormattingInfo (TEXT *t);
void RestoreDefaultControlSettings( MENUITEM *Item );
void PlayCursorSfx( void );
BOOL ChangeLevel( void );
void AddBikeArrow( char *name, int num );
void CheckMenuTimer( void );

/********************
Event Functions
*********************/
float GetEventCurrentTime(TITLE_EVENT *TitleEvent);
void InitEventGeneralPan(TITLE_EVENT *TitleEvent);
void InitEventDiscPan(TITLE_EVENT *TitleEvent);
void EventDiscPan(TITLE_EVENT *TitleEvent);
void ExitEventDiscPanFromRight(TITLE_EVENT *TitleEvent);
void ProcessEvents(void);
void ProcessTimers(void);
void SinPan2(VECTOR ViewFrom, VECTOR ViewTo, VECTOR *CurrentView,
			 VECTOR LookFrom, VECTOR LookTo, VECTOR *CurrentLook, float Time);
void InitEventRightVDUPan(TITLE_EVENT *TitleEvent);
void EventRightVDUPan(TITLE_EVENT *TitleEvent);
void ExitEventVDUPan(TITLE_EVENT *TitleEvent);
void InitEventLeftVDUPan(TITLE_EVENT *TitleEvent);
void EventLeftVDUPan(TITLE_EVENT *TitleEvent);
void ResetAllEvents(void);
void InitEventRotateOutRightVDU(TITLE_EVENT *TitleEvent);
void EventRotateOutRightVDU(TITLE_EVENT *TitleEvent);
void ExitEventRotateOutVDU(TITLE_EVENT *TitleEvent);
void RotateVDU2(float time, float start, float end);
void RotateBracket(float time, float start, float end);
void InitEventRotateInRightVDU(TITLE_EVENT *TitleEvent);
void EventRotateInRightVDU(TITLE_EVENT *TitleEvent);
void InitEventRotateOutLeftVDU(TITLE_EVENT *TitleEvent);
void EventRotateOutLeftVDU(TITLE_EVENT *TitleEvent);
void InitEventRotateInLeftVDU(TITLE_EVENT *TitleEvent);
void EventRotateInLeftVDU(TITLE_EVENT *TitleEvent);

void InitEventDarkenRoom(TITLE_EVENT *TitleEvent);
void EventDarkenRoom(TITLE_EVENT *TitleEvent);

void InitEventLightenRoom(TITLE_EVENT *TitleEvent);
void EventLightenRoom(TITLE_EVENT *TitleEvent);

void InitEventFadeOnHoloLight(TITLE_EVENT *TitleEvent);
void TriggerBikeSpeech( TITLE_EVENT *TitleEvent );
void EventFadeOnHoloLight(TITLE_EVENT *TitleEvent);

void InitEventFadeOffHoloLight(TITLE_EVENT *TitleEvent);
void ExitEventFadeOffHoloLight(TITLE_EVENT *TitleEvent);
void EventFadeOffHoloLight(TITLE_EVENT *TitleEvent);

void FadeHoloLight(float Brightness);

void InitEventRaiseHoloPad(TITLE_EVENT *TitleEvent);
void EventRaiseHoloPad(TITLE_EVENT *TitleEvent);
void InitEventLowerHoloPad(TITLE_EVENT *TitleEvent);
void EventLowerHoloPad(TITLE_EVENT *TitleEvent);
void InitEventJudderHoloPad(TITLE_EVENT *TitleEvent);
void ExitEventDiscPanInit( TITLE_EVENT *TitleEvent );
void InitEventLowerStack( TITLE_EVENT *TitleEvent );
void EventJudderHoloPad(TITLE_EVENT *TitleEvent);
void EventDiscPanInit(TITLE_EVENT *TitleEvent);
void InitEventDiscPanFromRightInit(TITLE_EVENT *TitleEvent);
void EventLowerStack(TITLE_EVENT *TitleEvent);
void ExitEventLowerStack(TITLE_EVENT *TitleEvent);
void InitEventJudderStack(TITLE_EVENT *TitleEvent);
void EventJudderStack(TITLE_EVENT *TitleEvent);
void InitEventExpandBike(TITLE_EVENT *TitleEvent);
void InitEventExpandCrystal(TITLE_EVENT *TitleEvent);
void ExitEventExpandBike(TITLE_EVENT *TitleEvent);
void DarkenRoom2(float darkness);
void DarkenRoomForStart( MENU *Menu );
void RotateDiscStack(float theta);

void InitEventShrinkBike(TITLE_EVENT *TitleEvent);
void ExitEventShrinkBike(TITLE_EVENT *TitleEvent);

void KillBikeChar(MENU *Menu);
void KillLevelPic( MENU *Menu );
void FadeBikeChar(float alpha);
void LoadBikeChar(MENUITEM *Item);
void LoadLevelPic(MENUITEM *Item);
void LoadBikeCharPic(MENUITEM *Item);
void KillBikeCharPic( MENU *Menu );
BOOL LoadGeneralPic(float xmin, float ymin, float xmax, float ymax, FRAME_INFO **header, int *frame, uint16 *scrpoly, BOOL *displayed);
BOOL DisplayPicOnTV( FRAME_INFO **header, int *frame, uint16 *poly, BOOL *displayed, float zoffset );
void LoadSavedGamePic( char *file );

void InitEventPlotBikeChar (TITLE_EVENT *TitleEvent);
void EventPlotBikeChar (TITLE_EVENT *TitleEvent);
void InitEventRemoveBikeChar (TITLE_EVENT *TitleEvent);
void EventRemoveBikeChar (TITLE_EVENT *TitleEvent);
void ExitEventRemoveBikeChar (TITLE_EVENT *TitleEvent);
void ExitEventRotateInRightVDU(TITLE_EVENT *TitleEvent);
void ExitEventRaiseHolopad(TITLE_EVENT *TitleEvent);
void ExitEventJudderHoloPad(TITLE_EVENT *TitleEvent);

#ifdef SELF_PLAY
void StartAttractModeForSelfPlay(MENUITEM *Item);
#endif

void InitStartDiscPanTimer (TITLE_EVENT_TIMER *TitleEventTimer);
void InitGeneralTimer( TITLE_EVENT_TIMER *TitleEventTimer );
void InitRightDiscPanTimer(TITLE_EVENT_TIMER *TitleEventTimer);
void InitLeftDiscPanTimer (TITLE_EVENT_TIMER *TitleEventTimer);
void InitRightVDUPanTimer (TITLE_EVENT_TIMER *TitleEventTimer);
void InitLeftVDUPanTimer (TITLE_EVENT_TIMER *TitleEventTimer);
void ChooseDiscTimer (TITLE_EVENT_TIMER *TitleEventTimer);
void InitVisualsTimer (TITLE_EVENT_TIMER *TitleEventTimer);
void NewMenuSelectMode( MENUITEM *Item );
BOOL ProcessSlider2( int Key );
void SelectConnectionToStart (MENUITEM *Item);
void SelectConnectionToStartServer (MENUITEM *Item);
void SelectConnectionToJoin (MENUITEM *Item);
void GetInitialSessions ( MENU *menu );

void InitMySessionsList(void);
void CopySessionsList(int *dummy);
void GetMyCurrentSessions(MENU *Menu);
BOOL ProcessPlaceTeamMember( int Key );
void DrawReadyStatus( MENUITEM *Item );
void InitJoystickList ( MENU *Menu );
void SelectConfigureAxisMenu ( MENUITEM *Item );
void InitJoystickButtonConfig ( MENU *Menu );
void InitJoystickPOVConfig ( MENU *Menu );
void InitJoystickAxisConfig ( MENU *Menu);
void SelectVDUList ( MENUITEM *Item );
void InitShipActionList( void );
void AssignShipActionToJoyBtn( MENUITEM *Item);
void AssignShipActionToJoyPOV( MENUITEM *Item);
void AssignShipActionToJoyAxis( MENUITEM *Item);
void CheckJoyBtns( int *dummy );
void CheckJoyPOVs( int *dummy );
void CheckJoyAxis( int *dummy );
void ExitJoySetup( MENU *Menu );
void ChooseJoyAxis( MENUITEM *Item );
void SetAxis( MENU *Menu );
void SetAxisInv( MENUITEM *Item );
void SetAxisFineControl( MENUITEM *Item );
void SetAxisDeadzone( MENUITEM *Item );
void SetAxisSensitivity( MENUITEM *Item );
void UpdateAxisPtr( float pos );
void InitModeCase(void);
void SetSoundLevels( int *dummy );
void SetSessionJoinFlag( MENUITEM *Item );
void ExitMouseSetup( MENU *Menu );
void InitAvgFrameRateGlobals( MENU *Menu );
void GoToNextLevel( MENUITEM *Item );
void TitleLoadGame( MENUITEM *Item );
void StartTimer( int timer );
void SaveMacros( MENUITEM *Item );
BOOL SetWaterDetail( SLIDER *slider );
BOOL SetNumPrimaryPickups( SLIDER *slider );
void UpdateSessionInfo( LIST *List );
void InitHostWaitingToStart( MENU *Menu );
void ResetServer( MENU *Menu );
void RestartServer( void );
void BackToJoinSession( MENUITEM *Item );
void InitServerWaitingForGameParameters( MENU *Menu );
void InitServerWaitingToStartGame( MENU *Menu );
void ServerCountDown( int *dummy );
void ServerCountDown2( int *dummy );
void InitPseudoHostWaitingForAck( MENU *Menu );
void PseudoHostWaitingForAckTimer( int *dummy );
void MenuReleaseDPlay( MENU *Menu );

/***********************************
Highlight box functions
***********************************/
uint16 PlotHighlightPoly (float xmin, float ymin, float xmax, float ymax, uint8 r, uint8 g, uint8 b);
void ProcessHighlightBox(void);
void DrawHighlightBox(TEXTINFO *TextInfo, uint8 r, uint8 g, uint8 b);
BOOL ProcessWeaponOrder ( int Key );

/***********************************
text messaging
***********************************/
void AddTitleMessage(LPTEXTMSG LpTextMsg);
void GetTitleMessage(void);

/*�������������������������������������������������������������������
	MultiPlayer Stuff...
�������������������������������������������������������������������*/
LIST	LoadSavedGameList = { 0 };
LIST	ServiceProvidersList = { 0 };
LIST	SessionsList = { 0 };
LIST	MySessionsList = { 0 };
//LIST	SessionPingList = { 0 };
BOOL	OKToJoinSession = FALSE;
LIST	PlayersList = { 0 };
LIST	TeamList[MAX_TEAMS];
BOOL	ShowTeamInfo = FALSE;
TEXT	MultiPlayerGameName = { 0, 0, "Default", NULL };
TEXT	DemoGameName = { 0, 0, "yourdemo", NULL, MAX_DEMONAME_LENGTH, TypeFileName };
TEXT	TitlePlayerMessage = { 0, 0, "", SendTitleMessage, MAXTEXTMSG, NULL };
extern	BOOL	SessionsRefresh[MAXSESSIONS];
extern	BOOL	SessionsRefreshActive;
extern	BYTE	TeamNumber[MAX_PLAYERS];
extern	BOOL	ShowStartPoints;

int Team1 = 0;
int Team2 = 1;
int Team3 = 2;
int Team4 = 3;

// Menu globals
BOOL OKToProcessKeys = FALSE;
int FramesIgnored = 0;

float Pulse = 0.0F;
BOOL MenuFrozen = FALSE;
BOOL NoTeamSelect = FALSE;

BOOL UseNewMenus = TRUE;

int16	PreferedMaxPlayers = MAX_PLAYERS;
int		DifficultyLevel = DIFF_Norm;
int		ControlMethod = CONTROL_Mouse;

int		GameType = GAME_Normal;
BOOL	GameRestricted = FALSE;

BOOL	Autoleveling = TRUE;
BOOL	BiLinearFiltering = TRUE;
extern BOOL	TriLinear;
extern BOOL	MipMap;
BOOL	PerspectiveCorrect = TRUE;
BOOL	EnhancedXHair = FALSE;
BOOL	LensFlare = TRUE;
BOOL	GoreGuts = FALSE;
BOOL	DebugInfo = FALSE;
BOOL	GodMode = FALSE;

#if defined ( EXTERNAL_DEMO ) || defined ( WIN98SHAREWARE ) || defined ( GATEWAY ) 
BOOL	LevelSelectMode = FALSE;
#else
BOOL	LevelSelectMode = TRUE;
#endif

BOOL	TexturesEnabled = TRUE;
BOOL	DebugVisible = FALSE;
BOOL	ShowPlaneRGB = FALSE;

BOOL	PlayDemo = FALSE;
BOOL	PauseDemo = FALSE;
BOOL	RecordDemo = FALSE;
BOOL	RecordDemoToRam = FALSE;//FALSE;
BOOL	BrightShips = FALSE;
BOOL	MyBrightShips = FALSE;
BOOL	BikeExhausts = TRUE;
BOOL	DemoScreenGrab = FALSE;

BOOL	ServerMode = FALSE;

BOOL	ScreenSaving = FALSE;

BOOL	ShowNode = FALSE;
BOOL	NodeCube = FALSE;
BOOL	OldNodeCube = FALSE;
BOOL	NodeCubeType = FALSE;
BOOL	TeamGame = FALSE;
BOOL	HarmTeamMates = TRUE;
BYTE	TeamNumber[MAX_PLAYERS];
WORD	Version= 0;

#if defined ( SHAREWARE ) || defined ( WIN98SHAREWARE )
BOOL	CanSelectBike[ MAXBIKETYPES ] =
{
	FALSE,	// Borg,
	TRUE,	// Beard,
	FALSE,	// LaJay,
	TRUE,	// Excop,
	TRUE,	// Trucker,
	FALSE,	// Foetoid,
	FALSE,	// JapBird,
	FALSE,	// Nutter,
	FALSE,	// Rhesus,
	FALSE,	// Joe,
	FALSE,	// Shark,
	FALSE,	// HK5,
	TRUE,	// Nubia,
	FALSE,	// Mofisto,
	FALSE,	// Cerbero,
	FALSE,	// Slick,
};
int		AllowedBike[ ALLOWED_BIKETYPES ] =
{
	1,		// Beard
	3,		// Excop
	4,		// Trucker
	12,		// Nubia
};
#else
BOOL	CanSelectBike[ MAXBIKETYPES ] =
{
	TRUE,	// Borg,
	TRUE,	// Beard,
	TRUE,	// LaJay,
	TRUE,	// Excop,
	TRUE,	// Trucker,
	TRUE,	// Foetoid,
	TRUE,	// JapBird,
	TRUE,	// Nutter,
	TRUE,	// Rhesus,
	TRUE,	// Joe,
	TRUE,	// Shark,
	TRUE,	// HK5,
	TRUE,	// Nubia,
	TRUE,	// Mofisto,
	TRUE,	// Cerbero,
	TRUE,	// Slick,
	TRUE,	// FlyGirl,
};
int		AllowedBike[ ALLOWED_BIKETYPES ] =
{
	0,	// Borg,
	1,	// Beard,
	2,	// LaJay,
	3,	// Excop,
	4,	// Trucker,
	5,	// Foetoid,
	6,	// JapBird,
	7,	// Nutter,
	8,	// Rhesus,
	9,	// Joe,
	10,	// Shark,
	11,	// HK5,
	12,	// Nubia,
	13,	// Mofisto,
	14,	// Cerbero,
	15,	// Slick,
	16,	// FlyGirl,
};
#endif


BOOL	PickupLightDetail = TRUE;
BOOL	PrimaryLightDetail = TRUE;
BOOL	SecondaryLightDetail = TRUE;
BOOL	AutoDetail = TRUE;
BOOL	ShowPing = FALSE;

SLIDER	SensitivityXSlider = { 1, 16, 1, 5, 0, 0.0F };
SLIDER	SensitivityYSlider = { 1, 16, 1, 5, 0, 0.0F };
SLIDER  PingFreqSlider = { 1, 30, 1, 10, 0, 0.0F }; 
SLIDER	BikeDetailSlider = { 0, 5, 1, 5, 0, 0.0F };
SLIDER	WaterDetailSlider = { 1, 2, 1, 2, 0, 0.0F, 0, 0, FALSE, NULL, SetWaterDetail };

SLIDER	NumPrimaryPickupsSlider = { 1, 3, 1, 1, 0, 0.0F, 0, 0, FALSE, NULL, SetNumPrimaryPickups };

SLIDER	TrailDetailSlider = { 0, 10, 1, 9, 0, 0.0F };
SLIDER  PacketsSlider = { 1, 30, 1, 6, 0, 0.0F };
SLIDER  ThrottleSlider = { 25, 1000, 25, 1000, 0, 0.0F };

SLIDER PseudoHostTimeoutSlider1 = { 1, 10, 1, 2, 0, 0.0F };
SLIDER PseudoHostTimeoutSlider2 = { 1, 20, 1, 5, 0, 0.0F };
SLIDER ServerTimeoutSlider = { 1, 20, 1, 5, 0, 0.0F };
BOOL PseudoHostCanSetMaxPlayers = TRUE;

#if defined	( SHAREWARE ) || defined ( WIN98SHAREWARE )
SLIDER	NumOfPlayersSlider = { 1, 4, 1, 1, 0, 0.0F };
#else
SLIDER	NumOfPlayersSlider = { 1, MAX_PLAYERS, 1, 1, 0, 0.0F };
#endif

#ifdef SHAREWARE
SLIDER	TimeLimit = { 1, 15, 1, 15, 0, 0.0F };
#else
SLIDER	TimeLimit = { 0, 30, 1, 0, 0, 0.0F };
#endif

SLIDER	MaxPlayersSlider = { 1, MAX_PLAYERS, 1, MAX_PLAYERS, 0, 0.0F };
SLIDER	MaxServerPlayersSlider = { 1, ( MAX_PLAYERS - 1 ), 1, ( MAX_PLAYERS - 1 ), 0, 0.0F };

SLIDER	MaxKillsSlider = { 0, 255, 1, 0, 0, 0.0F };
SLIDER	GoalScoreSlider = { 1, 10, 1, 5, 0, 0.0F };
SLIDER	BountyBonusSlider = { 1, 30, 1, 10, 0, 0.0F };
BOOL BountyBonus = TRUE;
SLIDER	CTFSlider = { 0, CTF_MAX - 1, 1, CTF_STANDARD, -1, 0.0F, 0.0F, 0, FALSE, CTF_Type };

#define BIKEFEATURESLIDER( VALUE1, VALUE2, VALUE3, VALUE4, VALUE5, VALUE6, VALUE7, VALUE8 ) \
	{ 0, 10, 1, (VALUE1), 0, 0.0F, 0.0F, 0, FALSE },\
	{ 0, 10, 1, (VALUE2), 0, 0.0F, 0.0F, 0, FALSE },\
	{ 0, 10, 1, (VALUE3), 0, 0.0F, 0.0F, 0, FALSE },\
	{ 0, 10, 1, (VALUE4), 0, 0.0F, 0.0F, 0, FALSE },\
	{ 0, 10, 1, (VALUE5), 0, 0.0F, 0.0F, 0, FALSE },\
	{ 0, 10, 1, (VALUE6), 0, 0.0F, 0.0F, 0, FALSE },\
	{ 0, 10, 1, (VALUE7), 0, 0.0F, 0.0F, 0, FALSE },\
	{ 0, 10, 1, (VALUE8), 0, 0.0F, 0.0F, 0, FALSE }

//#define HELPKEY( X, Y, KEY, MSG )\
//		{ (X), (Y), 0, 0, 0, (MSG), 0, 0, NULL, (KEY), NULL, DrawHelpKey, NULL, 0 }

SLIDER BikeFeatureSlider[MAXBIKETYPES][8] = {
	{BIKEFEATURESLIDER( 4,	5,	6, 10,	5,	5,	10, 10)},	// Lokasenna
	{BIKEFEATURESLIDER( 5,	5,	5, 10,	5,	5,	10, 10)},  // Beard
	{BIKEFEATURESLIDER( 8,	8,	8, 10,	3,	2,	10, 10)},  // L.A. Jay
	{BIKEFEATURESLIDER( 6,	4,	6, 10,	6,	3,	10, 10)},	// Ex-Cop
	{BIKEFEATURESLIDER( 2,	2,	4, 10,	10,	5,	10, 10)},	// Rex Hardy
	{BIKEFEATURESLIDER( 5,	4,	4, 10,	7,	5,	10, 10)},	// Foetoid
	{BIKEFEATURESLIDER( 5,	5,	4, 10,	6,	5,	10, 10)},	// Nim Soo
	{BIKEFEATURESLIDER( 10,	6,	6 ,10,	1,	2,	10, 10)},	// Nutta
	{BIKEFEATURESLIDER( 2,	2,	4, 10,	9,	5,	10, 10)},	// Sceptre
	{BIKEFEATURESLIDER( 5,	9,	6, 10,	3,	3,	10, 10)},	// Jo
	{BIKEFEATURESLIDER( 10,	10,	10, 10,	0,	0,	10, 10)},	// Cuvel Clark
	{BIKEFEATURESLIDER( 3,	3,	3, 10,	8,	4,	10, 10 )},	// HK-5
	{BIKEFEATURESLIDER( 6,	8,	6, 10,	3,	4,	10, 10)},	// Nubia
	{BIKEFEATURESLIDER( 3,	3,	5, 10,	5,	5,	10, 10)},	// Mofisto
	{BIKEFEATURESLIDER( 5,	5,	5, 10,	5,	5,	10, 10)},	// Cerbero
	{BIKEFEATURESLIDER( 5,	6,	8, 10,	6,	4,	10, 10)},	// Slick
	{BIKEFEATURESLIDER( 5,	6,	8,10,	6,	4,	10, 10 )},	// flygirl
};


LIST	PilotList = { 0 };
LIST ServerGamePlayersList = { 0 };
BYTE ServerGamePlayersWhoIAm[ MAX_PLAYERS ];

LIST	DemoList = { 0, 8 };	// list of all demo file in the current dir...


LIST	BikeList = { MAXBIKETYPES, 8, 0, 1, { "Lokasenna", "Beard", "L.A. Jay", "Ex-Cop", "Rex Hardy", "Foetoid", "Nim Soo Sun", "Nutta", "Sceptre", "Jo", "Cuvel Clark", "HK 5", "Nubia", "Mofisto", "Cerbero", "Slick", "FlyGirl" }, 0, 0 };
#if defined	( SHAREWARE ) || defined ( WIN98SHAREWARE )
LIST	ShareWareBikeList = { 4, 4, 0, 1, { "Beard", "Ex-Cop", "Rex Hardy", "Nubia" }, 0, 0 };
#endif

#ifdef WIN98SHAREWARE

LIST	BikeComputerList = { MAXBIKECOMPTYPES, 8, 0, 0, { "brenda" },  0, 0 };

#else

#if !defined( VERSION_SPANISH ) && !defined( VERSION_ITALIAN ) && !defined( VERSION_GERMAN ) && !defined( VERSION_FRENCH )
LIST	BikeComputerList = { MAXBIKECOMPTYPES, 8, 0, 1, { "phil 3b", "brenda", "lani-1", "Lepracom", "Roadster" },  0, 0 };
#elif defined( VERSION_SPANISH ) || defined( VERSION_ITALIAN ) || defined( VERSION_FRENCH )
LIST	BikeComputerList = { MAXBIKECOMPTYPES, 8, 0, 1, { "phil 3b", "brenda", "Roadster" },  0, 0 };
#elif defined( VERSION_GERMAN )
LIST	BikeComputerList = { MAXBIKECOMPTYPES, 8, 0, 1, { "linda 7", "l.u.l.u.", "razor", "thor" },  0, 0 };
#endif

#endif

LIST	TestList = { 2, 12, 0, 0, { "test1", "test2" }, 0, 0 };

LIST	RoomList = { 0, 10 };

TEXT	PilotNameInGame = { 0, 0, DEFAULT_PLAYER_NAME, SetPilotNameInGame, MAX_PILOTNAME_LENGTH, TypeFileName };

TEXT	PilotName = { 0, 0, DEFAULT_PLAYER_NAME, SetPilotName, MAX_PILOTNAME_LENGTH, TypeFileName };

TEXT	PilotReName = { 0, 0, DEFAULT_PLAYER_NAME, RenamePilotName, MAX_PILOTNAME_LENGTH, TypeFileName };

TEXT	RoomName = { 0, 0, "room", SetRoomName };

TEXT	MacroText1 = { 0, 0, LT_MacroText1/*"you ugly son of a bitch..."*/, SaveMacros };
TEXT	MacroText2 = { 0, 0, LT_MacroText2/*"Time to die..."*/, SaveMacros };
TEXT	MacroText3 = { 0, 0, LT_MacroText3/*"I will tear your soul apart..."*/, SaveMacros };
TEXT	MacroText4 = { 0, 0, "", NULL };

TEXT	QuickText = { 0, 0, "", SendQuickText };
TEXT	QuickTextWhisper = { 0, 0, "", SendQuickTextWhisper };

USERCONFIG	Config;

MENUSTATE MenuState = MENUSTATE_Select;

MENUITEM	*	KeyItem = NULL;

MENUITEM	*	SliderItem = NULL;
int		OriginalSliderValue;

LIST *	CurrentList = NULL;
MENUITEM *CurrentListItem = NULL;
MENUITEM *PreListItem;
MENU *PreListMenu;
int		OriginalSelection = 0;

MENUITEM	*	TextItem = NULL;
TEXT	OriginalText;

SLIDER	DemoSpeed = { 1, 16, 1, 8, 0, 0.0F };
SLIDER	FSBCompensation = { 1, 2048*4, 256, 2048, 0, 0.0F };
SLIDER  SfxSlider = { 0, 10, 1, 10, 0, 0.0F }; 
SLIDER  CDSlider = { 0, 10, 1, 10, 0, 0.0F }; 

#ifdef WIN98SHAREWARE
SLIDER BikerSpeechSlider = { 0, 10, 1, 0, 0, 0.0F };
#else
SLIDER BikerSpeechSlider = { 0, 10, 1, 8, 0, 0.0F };
#endif

SLIDER BikeCompSpeechSlider = { 0, 10, 1, 8, 0, 0.0F };
BOOL BikeEnginesOn = TRUE;

BOOL CD_OK = TRUE;

#if defined( SELF_PLAY ) || defined( EXTERNAL_DEMO )
SLIDER	DemoEyesSelect = { 0, MAX_PLAYERS, 1, 0, 0, 0.0F };
//SLIDER	DemoEyesSelect = { 0, MAX_PLAYERS - 1, 1, 0 };
#else
SLIDER	DemoEyesSelect = { 0, MAX_PLAYERS, 1, 0, 0, 0.0F };
#endif
float CharWidth;
BOOL ToggleTest;
TEXT TCPAddress = { 0, 0, "", NULL};

enum
{
	BIKE_FEATURE_Speed,
	BIKE_FEATURE_Accel,
	BIKE_FEATURE_Handling,
	BIKE_FEATURE_Power,
	BIKE_FEATURE_Shield,
	BIKE_FEATURE_Hull,
	BIKE_FEATURE_Missiles,
	BIKE_FEATURE_Ammo,
};

int SpeedFeat = BIKE_FEATURE_Speed;
int AccelFeat = BIKE_FEATURE_Accel;
int HandleFeat = BIKE_FEATURE_Handling;
int PowerFeat = BIKE_FEATURE_Power;
int ShieldFeat = BIKE_FEATURE_Shield;
int HullFeat = BIKE_FEATURE_Hull;
int MissileFeat = BIKE_FEATURE_Missiles;
int AmmoFeat = BIKE_FEATURE_Ammo;

#define TITLE_TEXT_MSGS_STORED 4
char TitleMessage[TITLE_TEXT_MSGS_STORED][MAXTEXTMSG];
char TeamCurrentScore[MAX_TEAMS][64];

void SelectKeyDef( MENUITEM *Item );
void DrawKeyDef( MENUITEM *Item );

/*�������������������������������������������������������������������
		Menus...
�������������������������������������������������������������������*/

DEFKEY KDleft = { &Config.left, 0 };
DEFKEY KDright = { &Config.right, 0 };
DEFKEY KDup = { &Config.up, 0 };
DEFKEY KDdown = { &Config.down, 0 };
DEFKEY KDmove_left = { &Config.move_left, 0 };
DEFKEY KDmove_right = { &Config.move_right, 0 };
DEFKEY KDmove_up = { &Config.move_up, 0 };
DEFKEY KDmove_down = { &Config.move_down, 0 };
DEFKEY KDroll_left = { &Config.roll_left, 0 };
DEFKEY KDroll_right = { &Config.roll_right, 0 };
DEFKEY KDmove = { &Config.move, 0 };
DEFKEY KDroll = { &Config.roll, 0 };
DEFKEY KDmove_forward = { &Config.move_forward, 0 };
DEFKEY KDmove_backward = { &Config.move_backward, 0 };
DEFKEY KDturbo = { &Config.turbo, 0 };
DEFKEY KDcruise_faster = { &Config.cruise_faster, 0 };
DEFKEY KDcruise_slower = { &Config.cruise_slower, 0 };
DEFKEY KDfire_primary = { &Config.fire_primary, 0 };
DEFKEY KDfire_secondary = { &Config.fire_secondary, 0 };
DEFKEY KDfire_mine = { &Config.fire_mine, 0 };
DEFKEY KDdrop_primary = { &Config.drop_primary, 0 };
DEFKEY KDdrop_secondary = { &Config.drop_secondary, 0 };
DEFKEY KDdrop_shield = { &Config.drop_shield, 0 };
DEFKEY KDdrop_ammo = { &Config.drop_ammo, 0 };
DEFKEY KDselect_primary[] = {
	{ &Config.select_primary[ PULSAR ], 0 },
	{ &Config.select_primary[ TROJAX ], 0 },
	{ &Config.select_primary[ SUSS_GUN ], 0 },
	{ &Config.select_primary[ TRANSPULSE_CANNON ], 0 },
	{ &Config.select_primary[ PYROLITE_RIFLE ], 0 },
	{ &Config.select_primary[ LASER ], 0 },
};
DEFKEY KDselect_next_primary = { &Config.select_next_primary, 0 };
DEFKEY KDselect_prev_primary = { &Config.select_prev_primary, 0 };
DEFKEY KDselect_next_secondary = { &Config.select_next_secondary, 0 };
DEFKEY KDselect_prev_secondary = { &Config.select_prev_secondary, 0 };
DEFKEY KDselect_secondary[] = {
	{ &Config.select_secondary[ MUGMISSILE ], 0 },
	{ &Config.select_secondary[ SOLARISMISSILE ], 0 },
	{ &Config.select_secondary[ THIEFMISSILE ], 0 },
	{ &Config.select_secondary[ SCATTERMISSILE ], 0 },
	{ &Config.select_secondary[ GRAVGONMISSILE ], 0 },
	{ &Config.select_secondary[ MULTIPLEMISSILE ], 0 },
	{ &Config.select_secondary[ TITANSTARMISSILE ], 0 },
	{ &Config.select_secondary[ PURGEMINE ], 0 },
	{ &Config.select_secondary[ PINEMINE ], 0 },
	{ &Config.select_secondary[ QUANTUMMINE ], 0 },
	{ &Config.select_secondary[ SPIDERMINE ], 0 },
};
DEFKEY KDsend_msg = { &Config.send_msg, 0 };
DEFKEY KDheadlights = { &Config.headlights, 0 };
DEFKEY KDfull_rearview = { &Config.full_rear_view, 0 };

#ifdef PLAYER_SPEECH_TAUNTS
DEFKEY KDsend_speech = { &Config.send_speech, 0 };
#endif

#define KDEF( PAGE, X, Y, LABEL, KEY )\
		{ (X) +-100, (Y),0, 0, 0, (LABEL), 0, 0, NULL, (void *)(PAGE), NULL, MenuItemDrawPageName, NULL, 0 },\
		{ (X) + 208, (Y), 0, 0, 0, (LABEL), 0, 0, (void *)&(KEY), (void *)(PAGE), SelectKeyDef, DrawKeyDef, NULL, 0 }

#define KEYDEF( X, Y, LABEL, KEY )\
		{ (X) +   0, (Y),0, 0, 0, (LABEL), 0, 0, NULL, NULL, NULL, MenuItemDrawName, NULL, 0 },\
		{ (X) + 128, (Y), 0, 0, 0, (LABEL), 0, 0, KEY.key[ 0 ], NULL, SelectKey, DrawKey, NULL, 0 },\
		{ (X) + 198, (Y), 0, 0, 0, (LABEL), 0, 0, KEY.key[ 1 ], NULL, SelectKey, DrawKey , NULL, 0}

#define VDUKDEF( XMIN, YMIN, XMAX, YMAX, LABEL, KEY )\
		{ XMIN, YMIN, XMAX, YMAX, 0 , (LABEL), FONT_Small, TEXTFLAG_CentreY, NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0 },\
		{ XMAX + 3, YMIN, XMAX + 25, YMAX, 0, (LABEL), FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_CentreY, (void *)&(KEY), NULL, NULL, DrawFlatMenuKeyNum, NULL, 0 },\
		{ XMAX + 30, YMIN, XMAX + 120, YMAX, 0, (LABEL), FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)&(KEY), NULL, SelectFlatMenuKey, DrawFlatMenuKey, NULL, 0 }

#define VDUKEYDEF( XMIN, YMIN, XMAX, YMAX, LABEL, KEY )\
		{ XMIN, YMIN, XMAX, YMAX, 0 , (LABEL), FONT_Small, TEXTFLAG_CentreY, NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0 },\
		{ XMAX + 5, YMIN, XMAX + 55, YMAX, 0, (LABEL), FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, KEY.key[ 0 ], NULL, SelectFlatMenuKey, DrawFlatMenuKey, NULL, 0 },\
		{ XMAX + 60, YMIN, XMAX + 110, YMAX, 0, (LABEL), FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, KEY.key[ 1 ], NULL, SelectFlatMenuKey, DrawFlatMenuKey, NULL, 0 }


#define HELPKEY( X, Y, KEY, MSG )\
		{ (X), (Y), 0, 0, 0, (MSG), 0, 0, NULL, (KEY), NULL, DrawHelpKey, NULL, 0 }

#define OLDMENUITEM( X, Y, STR, VAR, VAL, SELECTFUNC, DRAWFUNC )\
		{ (X), (Y), 0, 0, 0, (STR), 0, 0, (VAR), (VAL), (SELECTFUNC), (DRAWFUNC), NULL, 0 }

MENU	MENU_NotYet = {
	"Not Implemented Yet", NULL, NULL, NULL, 0,
	{
		{ 200, 144, 0, 0, 0, "Go Back", 0, 0, NULL, NULL, MenuItemBack, MenuItemDrawName, NULL, 0 },
		{ -1, -1, 0, 0, 0, "", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 }
	}
};


MENU	MENU_NEW_NotYet = {
	"Not Implemented Yet", NULL, NULL, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0, 0, 200, 20, 0, "Not Implemented", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};


MENU	MENU_NEW_NotAvailable = {
	"Not Available in Demo", NULL, NULL, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0, 0, 200, 20, 0, "Not Available in Demo", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 0, 30, 200, 50, 0, "Press ESC to return", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU MENU_NEW_BetweenLevels = {
	"", PrepareNextLevelStart, NULL, NULL, 0,
	{
		{ 0, 0, 200, 20, 0, "", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY | TEXTFLAG_ForceFit, (void *)SelectedLevel, NULL, NULL, DrawFlatMenuName, NULL, 0  },

		{ 36, 20, 164, 72, 0,"", 0, 0, NULL, NULL, NULL, LoadLevelPic, NULL, 0 },

		{ 10, 80, 190, 155, 0, "", FONT_Small, TEXTFLAG_ForceFit , (void *)SelectedLevelText, NULL, NULL, DrawFlatMenuName, NULL, 0  },
	 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

char CrystalsFoundText[ 64 ];
char GoldBarsFoundText[ 64 ];
char SecretsFoundText[ 64 ];
char EnemiesKilledText[ 64 ];
char TimeTakenText[ 64 ];
char GameCompleteText[ 256 ];
			       
char *GameCompleteWithoutCrystals = LT_GameCompleteWithoutCrystals/*"well done. You completed all the levels but you didn't get all the crystals. You'll have to do it all over again if you want to be properly rewarded."*/;
char *GameCompleteGotAllCrystalsSoFar = LT_GameCompleteGotAllCrystalsSoFar/*"well done, you got all the crystals. Take an extra life for the secret level. Find the crystal here for a special award."*/;
char *GameCompleteWithAllCrystals = LT_GameCompleteWithAllCrystals/*"well done, you got all the crystals. You get the secret biker."*/; 
char *GameCompleteWithAllCrystalsExceptLast = LT_GameCompleteWithAllCrystalsExceptLast/*"well you got through the secret level, but you didn't get the final crystal. Better luck next time."*/;
char *GameCompleteWithCheating = LT_GameCompleteWithCheating/*"well, you completed the game but you cheated, didn't you. If you want to see the secret level and have a chance to get a special reward, you'll have to do it properly!"*/;

char *GameCompleteWin98Shareware = LT_GameCompleteWin98Shareware/*"well done, you have completed the demo version of Forsaken. Now go and fucking well buy it!!!"*/;

char *GameCompleteAdditionalLevels = LT_GameCompleteAdditionalLevels/*"congratulations. You have completed all the currently installed additional levels. Look out for further mission packs!!"*/;

MENU MENU_NEW_SpecialMessage = {
	"", NULL, NULL, NULL, TITLE_TIMER_LowerHolopad,
	{
		{ 30, 0, 170, 150, 0, "", FONT_Medium, TEXTFLAG_CentreYBunched,  (void *)&GameCompleteText, NULL, NULL, DrawFlatMenuName, NULL, 0  },
		{ 0, 150, 200, 170, 0, LT_MENU_NEW_SpecialMessage0/*ok*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, AfterSpecialMessage, DrawFlatMenuItem, NULL, 0  },

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU MENU_NEW_NumberOfSecretsEnemys = {
	"", NULL, NULL, NULL, TITLE_TIMER_LowerHolopad,
	{
		{ 30, 0, 170, 50, 0, "", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreYBunched,  (void *)&SecretsFoundText, NULL, NULL, DrawFlatMenuName, NULL, 0  },
		{ 30, 50, 170, 100, 0, "", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreYBunched,  (void *)&EnemiesKilledText, NULL, NULL, DrawFlatMenuName, NULL, 0  },
		{ 30, 100, 170, 150, 0, "", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreYBunched,  (void *)&TimeTakenText, NULL, NULL, DrawFlatMenuName, NULL, 0  },
		{ 0, 150, 200, 170, 0, LT_MENU_NEW_NumberOfSecretsEnemys0/*ok*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NextLevelOrGameComplete, DrawFlatMenuItem, NULL, 0  },

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU MENU_NEW_NumberOfGoldBars = {
	"", SelectGoldBarModel, NULL, NULL, TITLE_TIMER_InterLevelPan,
	{
		{ 30, 0, 170, 150, 0, "", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreYBunched,  (void *)&GoldBarsFoundText, NULL, NULL, DrawFlatMenuName, NULL, 0  },
		{ 0, 150, 200, 170, 0, LT_MENU_NEW_NumberOfGoldBars0/*ok*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, &MENU_NEW_NumberOfSecretsEnemys, MenuChange, DrawFlatMenuItem, NULL, 0  },

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU MENU_NEW_NumberOfCrystals = {
	"", InitCrystalsFoundText, NULL, NULL, TITLE_TIMER_InterLevelPan,
	{
		{ 30, 0, 170, 150, 0, "", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreYBunched,  (void *)&CrystalsFoundText, NULL, NULL, DrawFlatMenuName, NULL, 0  },
		{ 0, 150, 200, 170, 0, LT_MENU_NEW_NumberOfCrystals0/*ok*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, &MENU_NEW_NumberOfGoldBars, MenuChange, DrawFlatMenuItem, NULL, 0  },

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_StartSinglePlayer = {
	"Not Implemented Yet", InitSinglePlayerGame, NULL, NULL, TITLE_TIMER_NormalPanToRightVDU,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_StartSinglePlayer0/*"single player Game"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 0, 30, 200, 50, 0, LT_MENU_NEW_StartSinglePlayer1/*"start"*/, FONT_Large, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, &MENU_NEW_BetweenLevels, MenuChange, DrawFlatMenuItem, NULL, 0 } ,

		{ 10, 60, 70, 80, 0, LT_MENU_NEW_StartSinglePlayer2/*"level"*/, FONT_Medium, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, NULL, NULL, InitLevelSelectVDU, DrawFlatMenuItem, NULL, 0 } ,

		{ 75, 58, 200, 82, 0, "", FONT_Medium, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY | TEXTFLAG_ForceFit, (void *)SelectedLevel, NULL, NULL, DrawFlatMenuName, NULL, 0 } ,

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_Error = {
	"", NULL, NULL, NULL, 0,
	{
		{ 0, 0, 200, 150, 0, "", FONT_Small, TEXTFLAG_BottomY | TEXTFLAG_CentreX | TEXTFLAG_CentreY, (void *)ErrorMessage, NULL, NULL, DrawFlatMenuName, NULL, 0  },
		{ 0, 150, 200, 170, 0, LT_MENU_NEW_Error0/*ok*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, MenuItemBackFromError, DrawFlatMenuItem, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_Notify = {
	"", NULL, NULL, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0, 0, 200, 150, 0, "", FONT_Small, TEXTFLAG_BottomY | TEXTFLAG_CentreX | TEXTFLAG_CentreY, (void *)NotifyMessage, NULL, NULL, DrawFlatMenuName, NULL, 0  },
		{ 0, 150, 200, 170, 0, LT_MENU_NEW_Error0/*ok*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, TitleReset, DrawFlatMenuItem, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};


MENU	MENU_NEW_GeneralLoading = {
	"", NULL, NULL, NULL, 0,
	{
		{ 0, 0, 200, 150, 0, LT_MENU_NEW_GeneralLoading0/*loading..."*/, FONT_Medium, TEXTFLAG_BottomY | TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};


MENU	MENU_NEW_StartAttractMode = {
	"", InitAttractMode, NULL, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0, 0, 200, 150, 0, LT_MENU_NEW_StartAttractMode0/*loading..."*/, FONT_Medium, TEXTFLAG_BottomY | TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_HostWaitingToStart = {
	"", InitHostWaitingToStart, BailMultiplayerFrontEnd, UpdateSessions, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0, 0, 200, 10, 0, LT_MENU_NEW_HostWaitingToStart0/*"waiting to start..."*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 5, 15, 90, 25, 0, LT_MENU_NEW_HostWaitingToStart1/*"start"*/, FONT_Medium, TEXTFLAG_CentreY,  NULL, &MENU_NEW_GeneralLoading, HostAboutToStart/*GoToSynchup*/, DrawFlatMenuItem, NULL, 0  },
		{ 90, 15, 105, 25, 0, LT_MENU_NEW_HostWaitingToStart2/*"IP:"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &IPAddressExists, NULL , DrawConditionalText, NULL, 0 } ,
		{ 105, 15, 200, 25, 0, "", FONT_Small, TEXTFLAG_CentreY, (void *)IPAddressText, &IPAddressExists, NULL , DrawConditionalName, NULL, 0 } ,

		{ 5, 27, 100, 37, SLIDER_Value, LT_MENU_NEW_HostWaitingToStart3/*"Num of Players"*/, FONT_Small, TEXTFLAG_CentreY, &NumOfPlayersSlider, NULL, NULL, DrawFlatMenuSlider, NULL, 0 },
		{ 5, 40, 100, 125, 0, "", FONT_Small, TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY , &PlayersList, NULL , NULL , DrawFlatMenuList, NULL, 0 } ,

		{ 5, 126, 200, 133, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[3], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 133, 200, 140, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[2], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 140, 200, 147, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[1], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 147, 200, 154, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[0], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 155, 25, 162, 0, LT_MENU_NEW_HostWaitingToStart4/*"msg:"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, &TitlePlayerMessage, NULL ,SelectFlatMenutext , DrawFlatMenuText, NULL, 0 } ,

		{ 5, 163, 25, 170, 0, LT_MENU_NEW_CreateGame17/*"quit"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, NULL, NULL , SelectQuit, DrawFlatMenuItem, NULL, 0 } ,
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_PseudoHostWaitingToStart = {
	"", GetInitialSessions, /*BailMultiplayerFrontEnd*/ChangeServiceProviderPseudoHost, UpdateSessions, 0,
	{
		{ 0, 0, 200, 10, 0, LT_MENU_NEW_HostWaitingToStart0/*"waiting to start..."*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 5, 15, 90, 25, 0, LT_MENU_NEW_HostWaitingToStart1/*"start"*/, FONT_Medium, TEXTFLAG_CentreY,  NULL, &MENU_NEW_GeneralLoading, PseudoHostAboutToStart, DrawFlatMenuItem, NULL, 0  },

		{ 5, 27, 100, 37, SLIDER_Value, LT_MENU_NEW_HostWaitingToStart3/*"Num of Players"*/, FONT_Small, TEXTFLAG_CentreY, &NumOfPlayersSlider, NULL, NULL, DrawFlatMenuSlider, NULL, 0 },
		{ 5, 40, 100, 125, 0, "", FONT_Small, TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY , &PlayersList, NULL , NULL , DrawFlatMenuList, NULL, 0 } ,

		{ 5, 126, 200, 133, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[3], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 133, 200, 140, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[2], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 140, 200, 147, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[1], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 147, 200, 154, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[0], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 155, 25, 162, 0, LT_MENU_NEW_HostWaitingToStart4/*"msg:"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, &TitlePlayerMessage, NULL ,SelectFlatMenutext , DrawFlatMenuText, NULL, 0 } ,
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

#if 0

MENU	MENU_NEW_HostWaitingToStartServer = {
	"", GetInitialSessions, BailMultiplayerFrontEnd, UpdateSessions, 0,
	{
		{ 0, 0, 200, 10, 0, LT_MENU_NEW_HostWaitingToStart0/*"waiting to start..."*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 5, 15, 90, 25, 0, LT_MENU_NEW_HostWaitingToStart1/*"start"*/, FONT_Medium, TEXTFLAG_CentreY,  NULL, &MENU_NEW_GeneralLoading, HostAboutToStart/*GoToSynchup*/, DrawFlatMenuItem, NULL, 0  },
		{ 90, 15, 105, 25, 0, LT_MENU_NEW_HostWaitingToStart2/*"IP:"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &IPAddressExists, NULL , DrawConditionalText, NULL, 0 } ,
		{ 105, 15, 200, 25, 0, "", FONT_Small, TEXTFLAG_CentreY, (void *)IPAddressText, &IPAddressExists, NULL , DrawConditionalName, NULL, 0 } ,

		{ 5, 27, 100, 37, SLIDER_Value, LT_MENU_NEW_HostWaitingToStart3/*"Num of Players"*/, FONT_Small, TEXTFLAG_CentreY, &NumOfPlayersSlider, NULL, NULL, DrawFlatMenuSlider, NULL, 0 },
		{ 5, 40, 100, 125, 0, "", FONT_Small, TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY , &PlayersList, NULL , NULL , DrawFlatMenuList, NULL, 0 } ,

		{ 5, 126, 200, 133, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[3], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 133, 200, 140, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[2], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 140, 200, 147, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[1], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 147, 200, 154, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[0], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 155, 25, 162, 0, LT_MENU_NEW_HostWaitingToStart4/*"msg:"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, &TitlePlayerMessage, NULL ,SelectFlatMenutext , DrawFlatMenuText, NULL, 0 } ,
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

#else

MENU	MENU_NEW_ServerHasQuit = {
	"", NULL, NULL, NULL, 0,
	{
		{ 10, 0, 200, 150, 0, LT_MENU_NEW_ServerHasQuit1/*"the server has quit"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreYBunched,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 10, 150, 200, 170, 0, LT_MENU_NEW_ServerHasQuit2/*"ok"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreYBunched,  NULL, NULL, BackToJoinSession, DrawFlatMenuItem, NULL, 0  },

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

// this menu can time out and go back to MENU_NEW_ServerWaitingForPseudoHost 
MENU	MENU_NEW_ServerWaitingToStartGame = {
	"", InitServerWaitingToStartGame, ResetServer, ServerCountDown2, TITLE_TIMER_PanToLeftVDU,
	{
		{ 10, 0, 200, 170, 0, LT_MENU_NEW_ServerWaitingToStartGame1/*"server - waiting for host to start game"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreYBunched,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

// this menu can time out and go back to MENU_NEW_ServerWaitingForPseudoHost 
MENU	MENU_NEW_ServerWaitingForGameParameters = {
	"", InitServerWaitingForGameParameters, ResetServer, ServerCountDown, TITLE_TIMER_PanToLeftVDU,
	{
		{ 10, 0, 200, 170, 0, LT_MENU_NEW_ServerWaitingForGameParameters1/*"server - waiting for host to select game type"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreYBunched,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_HostWaitingToStartServer = {
	"", NULL, ResetServer, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		{ 10, 0, 200, 170, 0, LT_MENU_NEW_HostWaitingToStartServer1/*"server - waiting to allocate host"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreYBunched,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

#endif




MENU	MENU_NEW_SelectLevel = {
	"", LoadLevelText, KillLevelPic, NULL, 0,
	{
		{ 0, 0, 200, 20, 0, "", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY | TEXTFLAG_ForceFit, (void *)SelectedLevel, NULL, NULL, DrawFlatMenuName, NULL, 0  },
		{ 30, 20, 168, 76, 0,"", 0, 0, NULL, NULL, NULL, LoadLevelPic, NULL, 0 },
		{ 10, 84, 190, 155, 0, "", FONT_Small, TEXTFLAG_ForceFit , (void *)SelectedLevelText, NULL, NULL, DrawFlatMenuName, NULL, 0  },
	 
		{ -1, -1, 0, 0, 0,"", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENUITEM SlowLevelSelectItem = { 0, 0, 0, 0, 0, "", 0, 0, NULL, &MENU_NEW_SelectLevel, NULL, NULL, NULL, 0 };

MENU	MENU_NEW_ValidPickups = {
	"", NULL, NULL, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_ValidPickups0/*"allowed pickups"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 10, 20, 120, 28, 0, LT_MENU_NEW_ValidPickups1/*"trojax"*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_Trojax ], NULL, SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 28, 120, 36, 0, LT_MENU_NEW_ValidPickups2/*"pyrolite"*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_Pyrolite ], NULL, SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 36, 120, 44, 0, LT_MENU_NEW_ValidPickups3/*"transpulse"*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_Transpulse ], NULL, SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 44, 120, 52, 0, LT_MENU_NEW_ValidPickups4/*"suss gun"*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_SussGun ], NULL, SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 52, 120, 60, 0, LT_MENU_NEW_ValidPickups5/*laser*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_Laser ], NULL, SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 60, 120, 68, 0, LT_MENU_NEW_ValidPickups6/*mug*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_Mug ], &PickupValid[ PICKUP_Mugs ], SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 68, 120, 76, 0, LT_MENU_NEW_ValidPickups7/*"solaris"*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_HeatseakerPickup ], &PickupValid[ PICKUP_Heatseaker ], SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 76, 120, 84, 0, LT_MENU_NEW_ValidPickups8/*"scatter"*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_Scatter ], NULL, SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 84, 120, 92, 0, LT_MENU_NEW_ValidPickups9/*"gravgon"*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_Gravgon ], NULL, SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 92, 120, 100, 0, LT_MENU_NEW_ValidPickups10/*"mfrl"*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_Launcher ], NULL, SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 100, 120, 108, 0, LT_MENU_NEW_ValidPickups11/*"titan"*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_TitanStar ], NULL, SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 108, 120, 116, 0, LT_MENU_NEW_ValidPickups12/*"purge mine"*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_PurgePickup ], NULL, SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 116, 120, 124, 0, LT_MENU_NEW_ValidPickups13/*"pine mine"*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_PinePickup ], NULL, SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 124, 120, 132, 0, LT_MENU_NEW_ValidPickups14/*"quantum mine"*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_QuantumPickup ], NULL, SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 132, 120, 140, 0, LT_MENU_NEW_ValidPickups15/*"invulnerability"*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_Inv ], NULL, SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 140, 120, 148, 0, LT_MENU_NEW_ValidPickups16/*"nitro"*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_Nitro ], NULL, SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 148, 120, 156, 0, LT_MENU_NEW_ValidPickups17/*"stealth mantle"*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_Mantle ], NULL, SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 156, 120, 164, 0, LT_MENU_NEW_ValidPickups18/*"orbit pulsar"*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_Orb ], NULL, SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 164, 120, 172, 0, LT_MENU_NEW_ValidPickups19/*"golden power pod"*/, FONT_Small, TEXTFLAG_CentreY, &PickupValid[ PICKUP_GoldenPowerPod ], NULL, SelectMultiToggle, DrawFlatMenuToggle, NULL, 0 } ,

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

uint32 ColPerspectivePeerPeer;
uint32 ColPerspectiveServer;

MENU	MENU_NEW_MoreMultiplayerOptions = {
	"", InitMoreMultiplayerOptions, ExitMoreMultiplayerOptions, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_MoreMultiplayerOptions0/*"Multiplayer options"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },

		{ 10, 15, 120, 22, 0, LT_MENU_NEW_MoreMultiplayerOptions3a/*"server collisions"*/, FONT_Small, TEXTFLAG_CentreY, &ColPerspective, (void *)COLPERS_Server, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 22, 120, 29, 0, LT_MENU_NEW_MoreMultiplayerOptions1a/*"lag tolerance on"*/, FONT_Small, TEXTFLAG_CentreY, &ColPerspective, (void *)COLPERS_Forsaken, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 29, 120, 36, 0, LT_MENU_NEW_MoreMultiplayerOptions2a/*"lag tolerance off"*/, FONT_Small, TEXTFLAG_CentreY, &ColPerspective, (void *)COLPERS_Descent, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,

		{ 10, 44, 100, 51, 0, LT_MENU_NEW_MoreMultiplayerOptions2/*"short packets"*/, FONT_Small, TEXTFLAG_CentreY, &UseShortPackets, ShortPacketsSelected, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 51, 100, 58, 0, LT_MENU_NEW_MoreMultiplayerOptions3/*"packet grouping"*/, FONT_Small, TEXTFLAG_CentreY, &BigPackets, BigPacketsSelected, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 58, 100, 65, SLIDER_Value, LT_MENU_NEW_MoreMultiplayerOptions4/*"packet rate"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &PacketsSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
		{ 10, 65, 100, 72, 0,LT_MENU_NEW_MoreMultiplayerOptions5/* "show ping"*/, FONT_Small, TEXTFLAG_CentreY, &ShowPing, NULL, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 72, 100, 79, SLIDER_Value, LT_MENU_NEW_MoreMultiplayerOptions6/*"ping interval"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &PingFreqSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,

		{ 10, 79, 100, 86, 0, "Reset Kills"/*"Reset Kills"*/, FONT_Small, TEXTFLAG_CentreY, &ResetKillsPerLevel, NULL, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 86, 100, 93, 0, LT_MENU_NEW_MoreMultiplayerOptions7/*"bike exhausts"*/, FONT_Small, TEXTFLAG_CentreY, &BikeExhausts, NULL, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 93, 100, 100, 0, LT_MENU_NEW_MoreMultiplayerOptions8/*"bright bikes"*/, FONT_Small, TEXTFLAG_CentreY, &MyBrightShips, NULL, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 100, 100, 107, 0, LT_MENU_NEW_MoreMultiplayerOptions9/*"harm teammates"*/, FONT_Small, TEXTFLAG_CentreY, &HarmTeamMates, NULL, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 107, 100, 114, 0, LT_MENU_NEW_MoreMultiplayerOptions10/*"Bounty bonus"*/, FONT_Small, TEXTFLAG_CentreY, &BountyBonus, NULL, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 114, 120, 121, SLIDER_Value, LT_MENU_NEW_MoreMultiplayerOptions11/*"flag capture score"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &GoalScoreSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
		{ 10, 121, 120, 128, SLIDER_Value, LT_MENU_NEW_MoreMultiplayerOptions12/*"bounty bonus interval"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &BountyBonusSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
		{ 10, 128, 120, 135, SLIDER_User, LT_MENU_NEW_MoreMultiplayerOptions13/*"own flag rule"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &CTFSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
#if !defined( PRESS_PREVIEW_DEMO ) && !defined( ACCLAIM_LANFEST )
		{ 10, 135, 100, 142, 0, LT_MENU_NEW_MoreMultiplayerOptions14/*"record demo"*/, FONT_Small, TEXTFLAG_CentreY, &RecordDemo, NULL, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 } ,
#endif
		{ 10, 142, 180, 149, 0, LT_MENU_NEW_MoreMultiplayerOptions19/*"change allowed pickups"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &MENU_NEW_ValidPickups, MenuChange, DrawFlatMenuItem, NULL, 0 } ,
		{ 10, 149, 120, 156, 0, LT_MENU_NEW_MoreMultiplayerOptions20/*"randomize pickups"*/, FONT_Small, TEXTFLAG_CentreY, &RandomPickups, NULL, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 } ,

		{ 10, 156, 120, 162, SLIDER_Value, LT_MENU_NEW_MoreMultiplayerOptions21/*"num primary weapons"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &NumPrimaryPickupsSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_SetUpTrackerPeerPeer = {
	"", InitTrackersList, ExitSetUpTracker, NULL, 0,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_CreateGame18/*"setup tracker"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },

		{ 5, 20, 100, 28, 0, LT_MENU_NEW_SetUpTracker1/*send tracker info*/, FONT_Small, TEXTFLAG_CentreY, &PeerPeerHeartbeat, NULL, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 } ,

		{ 5, 30, 200, 38, 0, LT_MENU_NEW_SetUpTracker2/*"Choose tracker config"*/, FONT_Small, TEXTFLAG_CentreY, &TrackersList, NULL, SelectVDUList, DrawFlatMenuItem, NULL, 0  },
		{ 10, 40, 200, 100, 0, "", FONT_Small,TEXTFLAG_Unselectable | TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY,  &TrackersList, NULL, SelectList, DrawFlatMenuList, NULL, 0  },

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};


MENU	MENU_NEW_CreateGame = {
	"", InitMultiplayerHostVDUPeerPeer, ChangeServiceProvider, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_CreateGame0/*"Create Multiplayer Game"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 10, 20, 90, 28, 0, LT_MENU_NEW_CreateGame1 /*"Start game"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &MENU_NEW_HostWaitingToStart, StartAHostSession , DrawFlatMenuItem, NULL, 0 } ,
		{ 90, 20, 105, 28, 0, LT_MENU_NEW_CreateGame2 /*"IP:"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &IPAddressExists, NULL , DrawConditionalText, NULL, 0 } ,
		{ 105, 20, 200, 28, 0, "", FONT_Small, TEXTFLAG_CentreY, (void *)IPAddressText, &IPAddressExists, NULL , DrawConditionalName, NULL, 0 } ,

		{ 10, 30, 85, 38, 0, LT_MENU_NEW_CreateGame3 /*"session name"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, &MultiPlayerGameName, NULL, SelectFlatMenutext, DrawSessionNameText, NULL, 0 } ,
		{ 10, 38, 50, 46, 0, LT_MENU_NEW_CreateGame4 /*"level"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, NULL, NULL, InitLevelSelectVDU, DrawFlatMenuItem, NULL, 0 } ,
		{ 90, 38, 200, 46, 0, "", FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)SelectedLevel, NULL, NULL, DrawFlatMenuName, NULL, 0 } ,
		{ 10, 46, 85, 54, SLIDER_Value, LT_MENU_NEW_CreateGame5 /*"player limit"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &MaxPlayersSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
		{ 10, 54, 85, 62, SLIDER_Value, LT_MENU_NEW_CreateGame6 /*"score limit"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &MaxKillsSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
		{ 10, 62, 85, 70, SLIDER_Time, LT_MENU_NEW_CreateGame7 /*"time limit"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &TimeLimit, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,

#ifndef SHAREWARE
		{ 0, 74, 200, 84, 0, LT_MENU_NEW_CreateGame8 /*"game type"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 10, 84, 200, 92, 0, LT_MENU_NEW_CreateGame9 /*"free for all"*/, FONT_Small, TEXTFLAG_CentreY, &GameType, (void *)GAME_Normal, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 92, 200, 100, 0, LT_MENU_NEW_CreateGame10 /*"team game"*/, FONT_Small, TEXTFLAG_CentreY, &GameType, (void *)GAME_Team, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 100, 200, 108, 0, LT_MENU_NEW_CreateGame11 /*"capture the flag"*/, FONT_Small,TEXTFLAG_CentreY, &GameType, (void *)GAME_CTF, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 108, 200, 116, 0, LT_MENU_NEW_CreateGame12 /*"flag chase"*/, FONT_Small,TEXTFLAG_CentreY, &GameType, (void *)GAME_CaptureFlag, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 116, 200, 124, 0, LT_MENU_NEW_CreateGame13 /*"bounty hunt"*/, FONT_Small,TEXTFLAG_CentreY, &GameType, (void *)GAME_BountyHunt, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 124, 200, 132, 0, LT_MENU_NEW_CreateGame14 /*"Team bounty hunt"*/, FONT_Small,TEXTFLAG_CentreY, &GameType, (void *)GAME_TeamBounty, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
#ifdef BOMBTAG_ENABLE
		{ 10, 130, 100, 138, 0, LT_MENU_NEW_CreateGame15 /*"tag"*/, FONT_Small, TEXTFLAG_CentreY, &GameType, (void *)GAME_Tag, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
#endif
#endif
		{ 10, 140, 100, 148, 0, LT_MENU_NEW_CreateGame18 /*"setup tracker"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &MENU_NEW_SetUpTrackerPeerPeer, MenuChange, DrawFlatMenuItem, NULL, 0 } ,

		{ 10, 148, 100, 156, 0, LT_MENU_NEW_CreateGame16 /*"more options"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &MENU_NEW_MoreMultiplayerOptions, MenuChange, DrawFlatMenuItem, NULL, 0 } ,
		{ 10, 160, 100, 170, 0, LT_MENU_NEW_CreateGame17 /*"quit"*/, FONT_Small, TEXTFLAG_CentreY,  NULL, NULL, SelectQuit, DrawFlatMenuItem, NULL, 0  },

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_SetUpTrackerServer = {
	"", InitTrackersList, ExitSetUpTracker, NULL, 0,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_CreateGame18/*"setup tracker"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },

		{ 5, 20, 100, 28, 0, LT_MENU_NEW_SetUpTracker1/*send tracker info*/, FONT_Small, TEXTFLAG_CentreY, &ServerHeartbeat, NULL, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 } ,

		{ 5, 30, 200, 38, 0, LT_MENU_NEW_SetUpTracker2/*"Choose tracker config"*/, FONT_Small, TEXTFLAG_CentreY, &TrackersList, NULL, SelectVDUList, DrawFlatMenuItem, NULL, 0  },
		{ 10, 40, 200, 100, 0, "", FONT_Small,TEXTFLAG_Unselectable | TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY,  &TrackersList, NULL, SelectList, DrawFlatMenuList, NULL, 0  },

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_CreateGameServerChooses = {
	"", InitMultiplayerHostVDUServer, ExitServerSetup, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_CreateGameServer5/*"Create a Server"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 10, 20, 90, 28, 0, LT_MENU_NEW_CreateGame1 /*"Start game"*/, FONT_Small, TEXTFLAG_CentreY, NULL, NULL, StartAHostSessionServer , DrawFlatMenuItem, NULL, 0 } ,
		{ 90, 20, 105, 28, 0, LT_MENU_NEW_CreateGame2 /*"IP:"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &IPAddressExists, NULL , DrawConditionalText, NULL, 0 } ,
		{ 105, 20, 200, 28, 0, "", FONT_Small, TEXTFLAG_CentreY, (void *)IPAddressText, &IPAddressExists, NULL , DrawConditionalName, NULL, 0 } ,

		//{ 10, 30, 85, 38, 0, LT_MENU_NEW_CreateGame3 /*"session name"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, &MultiPlayerGameName, NULL, SelectFlatMenutext, DrawSessionNameText, NULL, 0 } ,
		{ 10, 38, 50, 46, 0, LT_MENU_NEW_CreateGame4 /*"level"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, NULL, NULL, InitLevelSelectVDU, DrawFlatMenuItem, NULL, 0 } ,
		{ 90, 38, 200, 46, 0, "", FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)SelectedLevel, NULL, NULL, DrawFlatMenuName, NULL, 0 } ,
		{ 10, 46, 85, 54, SLIDER_Value, LT_MENU_NEW_CreateGame5 /*"player limit"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &MaxServerPlayersSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
		{ 10, 54, 85, 62, SLIDER_Value, LT_MENU_NEW_CreateGame6 /*"score limit"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &MaxKillsSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
		{ 10, 62, 85, 70, SLIDER_Time, LT_MENU_NEW_CreateGame7 /*"time limit"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &TimeLimit, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,

#ifndef SHAREWARE
		{ 0, 74, 200, 84, 0, LT_MENU_NEW_CreateGame8 /*"game type"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 10, 84, 200, 92, 0, LT_MENU_NEW_CreateGame9 /*"free for all"*/, FONT_Small, TEXTFLAG_CentreY, &GameType, (void *)GAME_Normal, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 92, 200, 100, 0, LT_MENU_NEW_CreateGame10 /*"team game"*/, FONT_Small, TEXTFLAG_CentreY, &GameType, (void *)GAME_Team, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 100, 200, 108, 0, LT_MENU_NEW_CreateGame11 /*"capture the flag"*/, FONT_Small,TEXTFLAG_CentreY, &GameType, (void *)GAME_CTF, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 108, 200, 116, 0, LT_MENU_NEW_CreateGame12 /*"flag chase"*/, FONT_Small,TEXTFLAG_CentreY, &GameType, (void *)GAME_CaptureFlag, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 116, 200, 124, 0, LT_MENU_NEW_CreateGame13 /*"bounty hunt"*/, FONT_Small,TEXTFLAG_CentreY, &GameType, (void *)GAME_BountyHunt, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 124, 200, 132, 0, LT_MENU_NEW_CreateGame14 /*"Team bounty hunt"*/, FONT_Small,TEXTFLAG_CentreY, &GameType, (void *)GAME_TeamBounty, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
#ifdef BOMBTAG_ENABLE
		{ 10, 130, 100, 138, 0, LT_MENU_NEW_CreateGame15 /*"tag"*/, FONT_Small, TEXTFLAG_CentreY, &GameType, (void *)GAME_Tag, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
#endif
#endif

		{ 10, 136, 100, 144, 0, LT_MENU_NEW_CreateGame18 /*"setup tracker"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &MENU_NEW_SetUpTrackerServer, MenuChange, DrawFlatMenuItem, NULL, 0 } ,
		
		{ 10, 148, 100, 156, 0, LT_MENU_NEW_CreateGame16 /*"more options"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &MENU_NEW_MoreMultiplayerOptions, MenuChange, DrawFlatMenuItem, NULL, 0 } ,

		{ 10, 160, 100, 170, 0, LT_MENU_NEW_CreateGame17 /*"quit"*/, FONT_Small, TEXTFLAG_CentreY,  NULL, NULL, SelectQuit, DrawFlatMenuItem, NULL, 0  },

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_CreateGameServer = {
	"", InitMultiplayerHostVDUServer, ExitServerSetup, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0,   0,   200, 20,  0, LT_MENU_NEW_CreateGameServer5/*"Create a Server"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 10,  20,  90,  28,  0, LT_MENU_NEW_CreateGame1 /*"Start game"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &MENU_NEW_HostWaitingToStartServer, StartAHostSessionServer , DrawFlatMenuItem, NULL, 0 } ,
		{ 90,  20,  105, 28,  0, LT_MENU_NEW_CreateGame2 /*"IP:"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &IPAddressExists, NULL , DrawConditionalText, NULL, 0 } ,
		{ 105, 20,  200, 28,  0, "", FONT_Small, TEXTFLAG_CentreY, (void *)IPAddressText, &IPAddressExists, NULL , DrawConditionalName, NULL, 0 } ,

//		{ 10,  30,  85,  38,  0, LT_MENU_NEW_CreateGame3 /*"session name"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, &MultiPlayerGameName, NULL, SelectFlatMenutext, DrawSessionNameText, NULL, 0 } ,

		{ 10, 40, 85, 48, SLIDER_Value, LT_MENU_NEW_CreateLobbyGame5 /*"player limit"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &MaxServerPlayersSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,

		{ 10, 50, 100, 58, 0, LT_MENU_NEW_MoreMultiplayerOptions2/*"short packets"*/, FONT_Small, TEXTFLAG_CentreY, &UseShortPackets, ShortPacketsSelected, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 60, 100, 68, 0, LT_MENU_NEW_MoreMultiplayerOptions3/*"packet grouping"*/, FONT_Small, TEXTFLAG_CentreY, &BigPackets, BigPacketsSelected, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 } ,
		{ 10, 70, 100, 78, SLIDER_Value, LT_MENU_NEW_MoreMultiplayerOptions4/*"packet rate"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &PacketsSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,

		// host can set max players
		{ 10, 86, 150, 94, 0, LT_MENU_NEW_CreateGameServer1/*"host can set max players"*/, FONT_Small, TEXTFLAG_CentreY, &PseudoHostCanSetMaxPlayers, NULL, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 } ,

		// host game setup timout
		{ 10, 94, 150, 102, SLIDER_Value, LT_MENU_NEW_CreateGameServer2/*"host game setup timout"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &PseudoHostTimeoutSlider1, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,

		// host game start timeout
		{ 10, 102, 150, 110, SLIDER_Value, LT_MENU_NEW_CreateGameServer3/*"host game start timout"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &PseudoHostTimeoutSlider2, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,

		// global server timeout
		{ 10, 110, 150, 118, SLIDER_Value, LT_MENU_NEW_CreateGameServer4/*"global server timout"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &ServerTimeoutSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,

		{ 10, 126, 100, 134, 0, LT_MENU_NEW_CreateGame18 /*"setup tracker"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &MENU_NEW_SetUpTrackerServer, MenuChange, DrawFlatMenuItem, NULL, 0 } ,

		{ 10, 150, 100, 160, 0, LT_MENU_NEW_CreateGame17 /*"quit"*/, FONT_Small, TEXTFLAG_CentreY,  NULL, NULL, SelectQuit, DrawFlatMenuItem, NULL, 0  },

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};														    

MENU MENU_NEW_PseudoHostWaitingForAck = {
	"", InitPseudoHostWaitingForAck, ChangeServiceProviderPseudoHost, PseudoHostWaitingForAckTimer, TITLE_TIMER_PanToLeftVDU,
	{
		{ 10, 0, 200, 170, 0, "waiting for server to acknowledge", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreYBunched,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU MENU_NEW_CreateGamePseudoHost = {
			"", InitPseudoHostGameScreen, ChangeServiceProviderPseudoHost, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_CreateGame0/*"Create Multiplayer Game"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 10, 20, 90, 28, 0, LT_MENU_NEW_CreateGame1 /*"Start game"*/, FONT_Small, TEXTFLAG_CentreY, NULL, NULL, StartAPseudoHostSession , DrawFlatMenuItem, NULL, 0 } ,

		{ 10, 30, 85, 38, 0, LT_MENU_NEW_CreateGame3 /*"session name"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, &MultiPlayerGameName, NULL, NULL, DrawSessionNameText, NULL, 0 } ,
		{ 10, 38, 50, 46, 0, LT_MENU_NEW_CreateGame4 /*"level"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, NULL, NULL, InitLevelSelectVDU, DrawFlatMenuItem, NULL, 0 } ,
		{ 90, 38, 200, 46, 0, "", FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)SelectedLevel, NULL, NULL, DrawFlatMenuName, NULL, 0 } ,
		{ 10, 46, 85, 54, SLIDER_Value, LT_MENU_NEW_CreateGame5 /*"player limit"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &MaxServerPlayersSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
		{ 10, 54, 85, 62, SLIDER_Value, LT_MENU_NEW_CreateGame6 /*"score limit"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &MaxKillsSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
		{ 10, 62, 85, 70, SLIDER_Time, LT_MENU_NEW_CreateGame7 /*"time limit"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &TimeLimit, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,

#ifndef SHAREWARE
		{ 0, 74, 200, 84, 0, LT_MENU_NEW_CreateGame8 /*"game type"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 10, 84, 200, 92, 0, LT_MENU_NEW_CreateGame9 /*"free for all"*/, FONT_Small, TEXTFLAG_CentreY, &GameType, (void *)GAME_Normal, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 92, 200, 100, 0, LT_MENU_NEW_CreateGame10 /*"team game"*/, FONT_Small, TEXTFLAG_CentreY, &GameType, (void *)GAME_Team, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 100, 200, 108, 0, LT_MENU_NEW_CreateGame11 /*"capture the flag"*/, FONT_Small,TEXTFLAG_CentreY, &GameType, (void *)GAME_CTF, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 108, 200, 116, 0, LT_MENU_NEW_CreateGame12 /*"flag chase"*/, FONT_Small,TEXTFLAG_CentreY, &GameType, (void *)GAME_CaptureFlag, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 116, 200, 124, 0, LT_MENU_NEW_CreateGame13 /*"bounty hunt"*/, FONT_Small,TEXTFLAG_CentreY, &GameType, (void *)GAME_BountyHunt, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 124, 200, 132, 0, LT_MENU_NEW_CreateGame14 /*"Team bounty hunt"*/, FONT_Small,TEXTFLAG_CentreY, &GameType, (void *)GAME_TeamBounty, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
#ifdef BOMBTAG_ENABLE
		{ 10, 130, 100, 138, 0, LT_MENU_NEW_CreateGame15 /*"tag"*/, FONT_Small, TEXTFLAG_CentreY, &GameType, (void *)GAME_Tag, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
#endif
#endif
		{ 10, 140, 100, 148, 0, LT_MENU_NEW_CreateGame16 /*"more options"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &MENU_NEW_MoreMultiplayerOptions, MenuChange, DrawFlatMenuItem, NULL, 0 } ,

//		{ 10, 150, 100, 160, 0, MENU_NEW_CreateGamePseudoHost0 /*"server does collisions"*/, FONT_Small, TEXTFLAG_CentreY, &ServerCollisions, NULL, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 } ,

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENUITEM StartLobbyGameItem = { 10, 20, 90, 28, 0, LT_MENU_NEW_CreateLobbyGame1 /*"Start game"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &MENU_NEW_HostWaitingToStart, StartAHostSession , DrawFlatMenuItem, NULL, 0 };

MENU	MENU_NEW_CreateLobbyGame = {
	"", InitMultiplayerHostVDUPeerPeer, ChangeServiceProvider, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_CreateLobbyGame0 /*"Create Multiplayer Game"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 10, 20, 90, 28, 0, LT_MENU_NEW_CreateLobbyGame1 /*"Start game"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &MENU_NEW_HostWaitingToStart, StartAHostSession , DrawFlatMenuItem, NULL, 0 } ,
		{ 90, 20, 105, 28, 0, LT_MENU_NEW_CreateLobbyGame2 /*"IP:"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &IPAddressExists, NULL , DrawConditionalText, NULL, 0 } ,
		{ 105, 20, 200, 28, 0, "", FONT_Small, TEXTFLAG_CentreY, (void *)IPAddressText, &IPAddressExists, NULL , DrawConditionalName, NULL, 0 } ,

		{ 10, 30, 85, 38, 0, LT_MENU_NEW_CreateLobbyGame3 /*"session name"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, &MultiPlayerGameName, NULL, NULL, DrawFlatMenuText, NULL, 0 } ,
		{ 10, 38, 50, 46, 0, LT_MENU_NEW_CreateLobbyGame4 /*"level"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, NULL, NULL, InitLevelSelectVDU, DrawFlatMenuItem, NULL, 0 } ,
		{ 90, 38, 200, 46, 0, "", FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)SelectedLevel, NULL, NULL, DrawFlatMenuName, NULL, 0 } ,
		{ 10, 46, 85, 54, SLIDER_Value, LT_MENU_NEW_CreateLobbyGame5 /*"player limit"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &MaxPlayersSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
		{ 10, 54, 85, 62, SLIDER_Value, LT_MENU_NEW_CreateLobbyGame6 /*"score limit"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &MaxKillsSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
		{ 10, 62, 85, 70, SLIDER_Time, LT_MENU_NEW_CreateLobbyGame7 /*"time limit"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &TimeLimit, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,

#ifndef SHAREWARE
		{ 0, 75, 200, 85, 0, LT_MENU_NEW_CreateLobbyGame8 /*"game type"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 10, 90, 100, 98, 0, LT_MENU_NEW_CreateLobbyGame9 /*"free for all"*/, FONT_Small, TEXTFLAG_CentreY, &GameType, (void *)GAME_Normal, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 98, 100, 106, 0, LT_MENU_NEW_CreateLobbyGame10 /*"team game"*/, FONT_Small, TEXTFLAG_CentreY, &GameType, (void *)GAME_Team, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 106, 110, 114, 0, LT_MENU_NEW_CreateLobbyGame11 /*"capture the flag"*/, FONT_Small,TEXTFLAG_CentreY, &GameType, (void *)GAME_CaptureFlag, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 114, 110, 122, 0, LT_MENU_NEW_CreateLobbyGame12 /*"bounty hunt"*/, FONT_Small,TEXTFLAG_CentreY, &GameType, (void *)GAME_BountyHunt, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
		{ 10, 122, 110, 130, 0, LT_MENU_NEW_CreateLobbyGame13 /*"Team bounty hunt"*/, FONT_Small,TEXTFLAG_CentreY, &GameType, (void *)GAME_TeamBounty, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
#ifdef BOMBTAG_ENABLE
		{ 10, 130, 100, 138, 0, LT_MENU_NEW_CreateLobbyGame14 /*"tag"*/, FONT_Small, TEXTFLAG_CentreY, &GameType, (void *)GAME_Tag, SelectFlatRadioButton, DrawFlatRadioButton, NULL, 0 } ,
#endif
#endif
		{ 10, 140, 100, 148, 0, LT_MENU_NEW_CreateLobbyGame15 /*"more options"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &MENU_NEW_MoreMultiplayerOptions, MenuChange, DrawFlatMenuItem, NULL, 0 } ,
		{ 10, 160, 100, 170, 0, LT_MENU_NEW_CreateLobbyGame16 /*"quit"*/, FONT_Small, TEXTFLAG_CentreY,  NULL, NULL, SelectQuit, DrawFlatMenuItem, NULL, 0  },

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};





MENUITEM MENU_ITEM_StartMultiplayer = 
		{ 0, 0, 0, 0, 0, "", 0, 0,  NULL, &MENU_NEW_CreateGame, MenuChange, NULL, NULL, 0  };

MENU	MENU_NEW_ChooseConnectionToStart = {
	"", GetServiceProviders, NULL, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_ChooseConnectionToStart0 /*"Choose connection type"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 5, 30, 195, 160, 0, "", FONT_Small,TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_AutoSelect | TEXTFLAG_CentreY,  &ServiceProvidersList, SelectConnectionToStart, SelectList, DrawFlatMenuList, NULL, 0  },
//		{ 0, 160, 200, 170, 0, LT_MENU_NEW_ChooseConnectionToStart1 /*"press 'q' to quit"*/, FONT_Small, TEXTFLAG_CentreY | TEXTFLAG_CentreX,  NULL, NULL, SelectQuit, DrawFlatMenuItem, NULL, 0  },

						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU MENU_NEW_ChooseServerGameType = {
	"", NULL, ChangeServiceProvider, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_ChooseServerGameType0 /*"Choose server type"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
			
		{ 10, 30, 100, 40, 0, LT_MENU_NEW_ChooseServerGameType1 /*"manual"*/, FONT_Medium, TEXTFLAG_CentreY, NULL, NULL, StartAManualServer , DrawFlatMenuItem, NULL, 0 } ,

		{ 10, 45, 100, 55, 0, LT_MENU_NEW_ChooseServerGameType2 /*"auto"*/, FONT_Medium, TEXTFLAG_CentreY, NULL, NULL, StartAnAutoServer , DrawFlatMenuItem, NULL, 0 } ,

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_ChooseConnectionToStartServer = {
	"", GetServiceProviders, NULL, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_ChooseConnectionToStart0 /*"Choose connection type"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 5, 30, 195, 170, 0, "", FONT_Small,TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_AutoSelect | TEXTFLAG_CentreY,  &ServiceProvidersList, SelectConnectionToStartServer, SelectList, DrawFlatMenuList, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};




MENUITEM MENU_ITEM_IdiotText = 
		{ 0, 150, 200, 170, 0, "", FONT_Small, TEXTFLAG_CentreY,  NULL, NULL, NULL, NULL, NULL, 0  };

MENU	MENU_NEW_PrimaryOrder = {
	"", NULL, StoreWeaponOrder, NULL, 0,
	{
		{ 10, 0, 190, 35, 0, LT_MENU_NEW_PrimaryOrder0 /*"primary weapon selection preferences"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 5, 50, 95, 180, 0, "", FONT_Small, TEXTFLAG_CentreY  | TEXTFLAG_ForceFit,  &Config.primary_order, NULL, NULL, DrawPrimaryWeapons, NULL, 0  },
		{ 5, 35, 95, 50, 0, LT_MENU_NEW_PrimaryOrder1 /*"auto"*/, FONT_Medium, TEXTFLAG_CentreY ,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 105, 35, 195, 50, 0, LT_MENU_NEW_PrimaryOrder2 /*"manual"*/, FONT_Medium, TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_SecondaryOrder = {
	"", NULL, StoreWeaponOrder, NULL, 0,
	{
		{ 10, 0, 190, 35, 0, LT_MENU_NEW_SecondaryOrder0 /*"secondary weapon selection preferences"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 5, 50, 95, 180, 0, "", FONT_Small, TEXTFLAG_CentreY | TEXTFLAG_ForceFit,  &Config.primary_order, NULL, NULL, DrawSecondaryWeapons, NULL, 0  },
		{ 5, 35, 95, 50, 0, LT_MENU_NEW_SecondaryOrder1 /*"auto"*/, FONT_Medium, TEXTFLAG_CentreY ,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 105, 35, 195, 50, 0, LT_MENU_NEW_SecondaryOrder2 /*"manual"*/, FONT_Medium, TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};



MENU	MENU_NEW_SecondaryWeaponKeys = {
#ifdef VDUKDEF
	"", InitKeyDef, NULL, NULL, 0,
#else
	"", InitControls, ExitControls, NULL, 0,
#endif
	{
		{ 0, 0, 200, 15, 0, LT_MENU_NEW_SecondaryWeaponKeys0 /*"secondary weapon"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },

#ifdef VDUKDEF
		VDUKDEF( 3, 20, 89, 28, LT_MENU_NEW_SecondaryWeaponKeys1 /*"fire secondary"*/, KDfire_secondary ),
		VDUKDEF( 3, 28, 89, 36, LT_MENU_NEW_SecondaryWeaponKeys2 /*"drop mine"*/, KDfire_mine ),

		VDUKDEF( 3, 42, 89, 50, LT_MENU_NEW_SecondaryWeaponKeys3 /*"mug missile"*/, KDselect_secondary[ MUGMISSILE ] ),
		VDUKDEF( 3, 50, 89, 58, LT_MENU_NEW_SecondaryWeaponKeys4 /*"solaris missile"*/, KDselect_secondary[ SOLARISMISSILE ] ),
#ifndef SHAREWARE
		VDUKDEF( 3, 58, 89, 66, LT_MENU_NEW_SecondaryWeaponKeys5 /*"scatter missile"*/, KDselect_secondary[ SCATTERMISSILE ] ),
#endif
		VDUKDEF( 3, 66, 89, 74, LT_MENU_NEW_SecondaryWeaponKeys6 /*"gravgon missile"*/, KDselect_secondary[ GRAVGONMISSILE ] ),
		VDUKDEF( 3, 74, 89, 82, LT_MENU_NEW_SecondaryWeaponKeys7 /*"mfrl"*/, KDselect_secondary[ MULTIPLEMISSILE ] ),
		VDUKDEF( 3, 82, 89, 90, LT_MENU_NEW_SecondaryWeaponKeys8 /*"Titan Missile"*/, KDselect_secondary[ TITANSTARMISSILE ] ),

		VDUKDEF( 3, 98, 89, 106, LT_MENU_NEW_SecondaryWeaponKeys9 /*"purge mine"*/, KDselect_secondary[ PURGEMINE ] ),
#ifndef SHAREWARE
		VDUKDEF( 3, 106, 89, 114, LT_MENU_NEW_SecondaryWeaponKeys10 /*"pine mine"*/, KDselect_secondary[ PINEMINE ] ),
		VDUKDEF( 3, 114, 89, 122, LT_MENU_NEW_SecondaryWeaponKeys11 /*"quantum mine"*/, KDselect_secondary[ QUANTUMMINE ] ),
#endif
		
		VDUKDEF( 3, 136, 89, 144, LT_MENU_NEW_SecondaryWeaponKeys12 /*"Next weapon"*/, KDselect_next_secondary ),
		VDUKDEF( 3, 144, 89, 152, LT_MENU_NEW_SecondaryWeaponKeys13 /*"Prev weapon"*/, KDselect_prev_secondary ),

		VDUKDEF( 3, 158, 89, 166, LT_MENU_NEW_SecondaryWeaponKeys14 /*"drop weapon"*/, KDdrop_secondary ),
#else
		VDUKEYDEF( 3, 20, 89, 28, LT_MENU_NEW_SecondaryWeaponKeys15 /*"fire secondary:"*/, (void *)&Config.fire_secondary ),
		VDUKEYDEF( 3, 28, 89, 36, LT_MENU_NEW_SecondaryWeaponKeys16 /*"drop mine:"*/, (void *)&Config.fire_mine ),

		VDUKEYDEF( 3, 42, 89, 50, LT_MENU_NEW_SecondaryWeaponKeys17 /*"mug missile:"*/, (void *)&Config.select_secondary[ MUGMISSILE ] ),
		VDUKEYDEF( 3, 50, 89, 58, LT_MENU_NEW_SecondaryWeaponKeys18 /*"solaris missile:"*/, (void *)&Config.select_secondary[ SOLARISMISSILE ] ),
#ifndef SHAREWARE
		VDUKEYDEF( 3, 58, 89, 66, LT_MENU_NEW_SecondaryWeaponKeys19 /*"scatter missile:"*/, (void *)&Config.select_secondary[ SCATTERMISSILE ] ),
#endif
		VDUKEYDEF( 3, 66, 89, 74, LT_MENU_NEW_SecondaryWeaponKeys20 /*"gravgon missile:"*/, (void *)&Config.select_secondary[ GRAVGONMISSILE ] ),
		VDUKEYDEF( 3, 74, 89, 82, LT_MENU_NEW_SecondaryWeaponKeys21 /*"mfrl:"*/, (void *)&Config.select_secondary[ MULTIPLEMISSILE ] ),
		VDUKEYDEF( 3, 82, 89, 90, LT_MENU_NEW_SecondaryWeaponKeys22 /*"Titan Missile:"*/, (void *)&Config.select_secondary[ TITANSTARMISSILE ] ),

		VDUKEYDEF( 3, 98, 89, 106, LT_MENU_NEW_SecondaryWeaponKeys23 /*"purge mine:"*/, (void *)&Config.select_secondary[ PURGEMINE ] ),
#ifndef SHAREWARE
		VDUKEYDEF( 3, 106, 89, 114, LT_MENU_NEW_SecondaryWeaponKeys24 /*"pine mine:"*/, (void *)&Config.select_secondary[ PINEMINE ] ),
		VDUKEYDEF( 3, 114, 89, 122, LT_MENU_NEW_SecondaryWeaponKeys25 /*"quantum mine:"*/, (void *)&Config.select_secondary[ QUANTUMMINE ] ),
#endif
		
		VDUKEYDEF( 3, 136, 89, 144, LT_MENU_NEW_SecondaryWeaponKeys26 /*"Next weapon:"*/, (void *)&Config.select_next_secondary ),
		VDUKEYDEF( 3, 144, 89, 152, LT_MENU_NEW_SecondaryWeaponKeys27 /*"Prev weapon:"*/, (void *)&Config.select_prev_secondary ),

		VDUKEYDEF( 3, 158, 89, 166, LT_MENU_NEW_SecondaryWeaponKeys28 /*"drop weapon:"*/, (void *)&Config.drop_secondary ),
#endif		
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_PrimaryWeaponKeys = {
#ifdef VDUKDEF
	"", InitKeyDef, NULL, NULL, 0,
#else
	"", InitControls, ExitControls, NULL, 0,
#endif
	{
		{ 0, 0, 200, 15, 0, LT_MENU_NEW_PrimaryWeaponKeys0 /*"primary weapon"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
#ifdef VDUKDEF
		VDUKDEF( 3, 20, 89, 28, LT_MENU_NEW_PrimaryWeaponKeys1 /*"fire primary"*/, KDfire_primary ),

		VDUKDEF( 3, 34, 89, 42, LT_MENU_NEW_PrimaryWeaponKeys2 /*"pulsar"*/, KDselect_primary[ PULSAR ] ),
		VDUKDEF( 3, 42, 89, 50, LT_MENU_NEW_PrimaryWeaponKeys3 /*"trojax"*/, KDselect_primary[ TROJAX ] ),
#ifndef SHAREWARE
		VDUKDEF( 3, 50, 89, 58, LT_MENU_NEW_PrimaryWeaponKeys4 /*"pyrolite"*/, KDselect_primary[ PYROLITE_RIFLE ] ),
		VDUKDEF( 3, 58, 89, 66, LT_MENU_NEW_PrimaryWeaponKeys5 /*"transpulse"*/, KDselect_primary[ TRANSPULSE_CANNON ] ),
#endif
		VDUKDEF( 3, 66, 89, 74, LT_MENU_NEW_PrimaryWeaponKeys6 /*"suss gun"*/, KDselect_primary[ SUSS_GUN ] ),
#ifndef SHAREWARE
		VDUKDEF( 3, 74, 89, 82, LT_MENU_NEW_PrimaryWeaponKeys7 /*"laser"*/, KDselect_primary[ LASER ] ),
#endif

		VDUKDEF( 3, 88, 89, 96, LT_MENU_NEW_PrimaryWeaponKeys8 /*"Next weapon"*/, KDselect_next_primary ),
		VDUKDEF( 3, 96, 89, 104, LT_MENU_NEW_PrimaryWeaponKeys9 /*"Prev weapon"*/, KDselect_prev_primary ),

		VDUKDEF( 3, 110, 89, 118, LT_MENU_NEW_PrimaryWeaponKeys10 /*"drop weapon"*/, KDdrop_primary ),

		VDUKDEF( 3, 124, 89, 132, LT_MENU_NEW_PrimaryWeaponKeys11 /*"send msg"*/, KDsend_msg ),
#else
		VDUKEYDEF( 3, 20, 89, 28, LT_MENU_NEW_PrimaryWeaponKeys12 /*"fire primary:"*/, (void *)&Config.fire_primary ),

		VDUKEYDEF( 3, 34, 89, 42, LT_MENU_NEW_PrimaryWeaponKeys13 /*"pulsar:"*/, (void *)&Config.select_primary[ PULSAR ] ),
		VDUKEYDEF( 3, 42, 89, 50, LT_MENU_NEW_PrimaryWeaponKeys14 /*"trojax:"*/, (void *)&Config.select_primary[ TROJAX ] ),
		VDUKEYDEF( 3, 50, 89, 58, LT_MENU_NEW_PrimaryWeaponKeys15 /*"suss gun:"*/, (void *)&Config.select_primary[ SUSS_GUN ] ),
#ifndef SHAREWARE
		VDUKEYDEF( 3, 58, 89, 66, LT_MENU_NEW_PrimaryWeaponKeys16 /*"pyrolite:"*/, (void *)&Config.select_primary[ TRANSPULSE_CANNON ] ),
		VDUKEYDEF( 3, 66, 89, 74, LT_MENU_NEW_PrimaryWeaponKeys17 /*"transpulse:"*/, (void *)&Config.select_primary[ PYROLITE_RIFLE ] ),
		VDUKEYDEF( 3, 74, 89, 82, LT_MENU_NEW_PrimaryWeaponKeys18 /*"laser:"*/, (void *)&Config.select_primary[ LASER ] ),
#endif

		VDUKEYDEF( 3, 88, 89, 96, LT_MENU_NEW_PrimaryWeaponKeys19 /*"Next weapon:"*/, (void *)&Config.select_next_primary ),
		VDUKEYDEF( 3, 96, 89, 104, LT_MENU_NEW_PrimaryWeaponKeys20 /*"Prev weapon:"*/, (void *)&Config.select_prev_primary ),

		VDUKEYDEF( 3, 110, 89, 118, LT_MENU_NEW_PrimaryWeaponKeys21 /*"drop weapon:"*/, (void *)&Config.drop_primary ),
#endif		
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_Weapons = {
	"", InitControls, ExitControls, NULL, TITLE_TIMER_NormalPanToRightVDU,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_Weapons0 /*"weapons"*/, FONT_Large, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 10, 45, 200, 65, 0, LT_MENU_NEW_Weapons1 /*"primary weapon keys"*/, FONT_Small, TEXTFLAG_CentreY,  NULL, &MENU_NEW_PrimaryWeaponKeys, MenuChange, DrawFlatMenuItem, NULL, 0  },
		{ 10, 70, 200, 90, 0, LT_MENU_NEW_Weapons2 /*"secondary weapon keys"*/, FONT_Small, TEXTFLAG_CentreY,  NULL, &MENU_NEW_SecondaryWeaponKeys, MenuChange, DrawFlatMenuItem, NULL, 0  },
		{ 10, 100, 200, 120, 0, LT_MENU_NEW_Weapons3 /*"primary weapon preferences"*/, FONT_Small, TEXTFLAG_CentreY,  NULL, &MENU_NEW_PrimaryOrder, MenuChange, DrawFlatMenuItem, NULL, 0  },
		{ 10, 125, 200, 145, 0, LT_MENU_NEW_Weapons4 /*"secondary weapon preferences"*/, FONT_Small, TEXTFLAG_CentreY,  NULL, &MENU_NEW_SecondaryOrder, MenuChange, DrawFlatMenuItem, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_ConfigureKeyboard = {
#ifdef VDUKDEF
	"", InitKeyDef, NULL, NULL, 0,
#else
	"", InitControls, ExitControls, NULL, 0,
#endif
	{
		{ 0, 0, 200, 15, 0, LT_MENU_NEW_ConfigureKeyboard0 /*"movement controls"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },

#ifdef VDUKDEF
		VDUKDEF( 3, 15, 80, 23, LT_MENU_NEW_ConfigureKeyboard1 /*"rotate left"*/, KDleft ),
		VDUKDEF( 3, 23, 80, 31, LT_MENU_NEW_ConfigureKeyboard2 /*"rotate right"*/, KDright ),
		VDUKDEF( 3, 31, 80, 39, LT_MENU_NEW_ConfigureKeyboard3  /*"rotate up"*/, KDup ),
		VDUKDEF( 3, 39, 80, 47, LT_MENU_NEW_ConfigureKeyboard4 /*"rotate down"*/, KDdown ),

		VDUKDEF( 3, 50, 80, 58, LT_MENU_NEW_ConfigureKeyboard5 /*"slide left"*/, KDmove_left ),
		VDUKDEF( 3, 58, 80, 66, LT_MENU_NEW_ConfigureKeyboard6 /*"slide right"*/, KDmove_right ),
		VDUKDEF( 3, 66, 80, 74, LT_MENU_NEW_ConfigureKeyboard7 /*"slide up"*/, KDmove_up ),
		VDUKDEF( 3, 74, 80, 82, LT_MENU_NEW_ConfigureKeyboard8 /*"slide down"*/, KDmove_down ),

		VDUKDEF( 3, 85, 80, 93, LT_MENU_NEW_ConfigureKeyboard9 /*"roll left"*/, KDroll_left ),
		VDUKDEF( 3, 93, 80, 101, LT_MENU_NEW_ConfigureKeyboard10 /*"roll right"*/, KDroll_right ),

		VDUKDEF( 3, 104, 80, 112, LT_MENU_NEW_ConfigureKeyboard11 /*"slide mode"*/, KDmove ),
		VDUKDEF( 3, 112, 80, 120, LT_MENU_NEW_ConfigureKeyboard12 /*"roll mode"*/, KDroll ),

		VDUKDEF( 3, 123, 80, 131, LT_MENU_NEW_ConfigureKeyboard13 /*"forward"*/, KDmove_forward ),
		VDUKDEF( 3, 131, 80, 139, LT_MENU_NEW_ConfigureKeyboard14 /*"reverse"*/, KDmove_backward ),
		VDUKDEF( 3, 139, 80, 147, LT_MENU_NEW_ConfigureKeyboard15 /*"nitro"*/, KDturbo ),

		VDUKDEF( 3, 150, 80, 158, LT_MENU_NEW_ConfigureKeyboard16 /*"cruise faster"*/, KDcruise_faster ),
		VDUKDEF( 3, 158, 80, 166, LT_MENU_NEW_ConfigureKeyboard17 /*"cruise slower"*/, KDcruise_slower ),
#else
		VDUKEYDEF( 3, 15, 80, 23, LT_MENU_NEW_ConfigureKeyboard18 /*"rotate left:"*/, (void *)&Config.left ),
		VDUKEYDEF( 3, 23, 80, 31, LT_MENU_NEW_ConfigureKeyboard19 /*"rotate right:"*/, (void *)&Config.right ),
		VDUKEYDEF( 3, 31, 80, 39, LT_MENU_NEW_ConfigureKeyboard20 /*"rotate up:"*/, (void *)&Config.up ),
		VDUKEYDEF( 3, 39, 80, 47, LT_MENU_NEW_ConfigureKeyboard21 /*"rotate down:"*/, (void *)&Config.down ),

		VDUKEYDEF( 3, 50, 80, 58, LT_MENU_NEW_ConfigureKeyboard22 /*"slide left:"*/, (void *)&Config.move_left ),
		VDUKEYDEF( 3, 58, 80, 66, LT_MENU_NEW_ConfigureKeyboard23 /*"slide right:"*/, (void *)&Config.move_right ),
		VDUKEYDEF( 3, 66, 80, 74, LT_MENU_NEW_ConfigureKeyboard24 /*"slide up"*/, (void *)&Config.move_up ),
		VDUKEYDEF( 3, 74, 80, 82, LT_MENU_NEW_ConfigureKeyboard25 /*"slide down:"*/, (void *)&Config.move_down ),

		VDUKEYDEF( 3, 85, 80, 93, LT_MENU_NEW_ConfigureKeyboard26 /*"roll left:"*/, (void *)&Config.roll_left ),
		VDUKEYDEF( 3, 93, 80, 101, LT_MENU_NEW_ConfigureKeyboard27 /*"roll right:"*/, (void *)&Config.roll_right ),

		VDUKEYDEF( 3, 104, 80, 112, LT_MENU_NEW_ConfigureKeyboard28 /*"slide mode:"*/, (void *)&Config.move ),
		VDUKEYDEF( 3, 112, 80, 120, LT_MENU_NEW_ConfigureKeyboard29 /*"roll mode:"*/, (void *)&Config.roll ),

		VDUKEYDEF( 3, 123, 80, 131, LT_MENU_NEW_ConfigureKeyboard30 /*"forward:"*/, (void *)&Config.move_forward ),
		VDUKEYDEF( 3, 131, 80, 139, LT_MENU_NEW_ConfigureKeyboard31 /*"reverse:"*/, (void *)&Config.move_backward ),
		VDUKEYDEF( 3, 139, 80, 147, LT_MENU_NEW_ConfigureKeyboard32 /*"nitro:"*/, (void *)&Config.turbo ),

		VDUKEYDEF( 3, 150, 80, 158, LT_MENU_NEW_ConfigureKeyboard33 /*"cruise faster:"*/, (void *)&Config.cruise_faster ),
		VDUKEYDEF( 3, 158, 80, 166, LT_MENU_NEW_ConfigureKeyboard34 /*"cruise slower:"*/, (void *)&Config.cruise_slower ),

		VDUKEYDEF( 3, 170, 80, 178, LT_MENU_NEW_ConfigureKeyboard35 /*"send msg:"*/, (void *)&Config.send_msg ),
#endif
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};


MENU	MENU_NEW_NotYetRight = {
	"Not Implemented Yet", NULL, NULL, NULL, TITLE_TIMER_PanToRightVDU,
	{
		{ 0, 0, 200, 20, 0, "Not Implemented", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU MENU_NEW_ConfigJoyAxis = {
	"", InitJoystickAxisConfig, SetAxis, CheckJoyAxis, 0,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_ConfigJoyAxis0 /*"setup axis"*/, FONT_Large, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },

		{ 0, 0, 20 , 20, 0, "", FONT_Large, TEXTFLAG_CentreX | TEXTFLAG_CentreY , &JoystickAxisList, NULL, NULL, DrawLeftArrow, NULL, 0 } ,
		{ 180, 0, 200 , 20, 0, "", FONT_Large, TEXTFLAG_CentreX | TEXTFLAG_CentreY , &JoystickAxisList, NULL, NULL, DrawRightArrow, NULL, 0 } ,

		{ 5, 25, 85, 45, SLIDER_User, LT_MENU_NEW_ConfigJoyAxis1 /*"select axis:"*/, FONT_Medium, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY,
						&AxisSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0  },

		{ 5, 50, 85, 65, SLIDER_User, LT_MENU_NEW_ConfigJoyAxis2 /*"select action:"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY | TEXTFLAG_ForceFit,
						&AxisActionSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0  },

		{ 5, 70, 85, 80, 0, LT_MENU_NEW_ConfigJoyAxis3 /*"invert axis"*/, FONT_Small, TEXTFLAG_CentreY, &AxisInvert, SetAxisInv, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0  },

		{ 5, 85, 85, 95, 0, LT_MENU_NEW_ConfigJoyAxis4 /*"sensitivity"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &SensitivitySlider, SetAxisSensitivity, SelectSlider, DrawFlatMenuSlider, NULL, 0  },

		{ 5, 100, 85, 110, 0, LT_MENU_NEW_ConfigJoyAxis5 /*"deadzone"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &DeadzoneSlider, SetAxisDeadzone, SelectSlider, DrawFlatMenuSlider, NULL, 0  },
		
		{ 5, 115, 85, 125, 0, LT_MENU_NEW_ConfigJoyAxis6 /*"fine control"*/, FONT_Small, TEXTFLAG_CentreY, &FineControl, SetAxisFineControl, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0  },

		{ 0, 130, 200, 140, 0, LT_MENU_NEW_ConfigJoyAxis7 /*"test:"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },

		{ 5, 140, 100, 150, 0, "", FONT_Small, TEXTFLAG_CentreY | TEXTFLAG_CheckForRefresh,  (void *)AxisExtremeLeftText, NULL, NULL, DrawFlatMenuName, NULL, 0  },
		{ 100, 140, 195, 150, 0, "", FONT_Small, TEXTFLAG_RightX | TEXTFLAG_CentreY | TEXTFLAG_CheckForRefresh,  (void *)AxisExtremeRightText, NULL, NULL, DrawFlatMenuName, NULL, 0  },

#if 0
		{ 10, 150, 30, 155, 0, ".", FONT_Small, TEXTFLAG_CentreX, NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 90, 150, 110, 155, 0, ".", FONT_Small, TEXTFLAG_CentreX, NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 170, 150, 190, 155, 0, ".", FONT_Small, TEXTFLAG_CentreX, NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
#endif

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU MENU_NEW_ConfigJoyBtns = {
	"", InitJoystickButtonConfig, NULL, CheckJoyBtns, 0,
	{
		{ 5, 0, 190, 25, 0, "", FONT_Medium, TEXTFLAG_CentreY | TEXTFLAG_CheckForRefresh,  (void *)JoystickModeText, NULL, NULL, DrawFlatMenuName, NULL, 0  },
		{ 5, 25, 190, 35, 0, "", FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY | TEXTFLAG_CheckForRefresh,  (void *)JoystickBtnText, NULL, NULL, DrawFlatMenuName, NULL, 0  },
		{ 5, 40, 100, 160, 0, "", FONT_Small, TEXTFLAG_ManualListHighlight | TEXTFLAG_ForceFit | TEXTFLAG_SuppressHighlight | TEXTFLAG_AutoSelect | TEXTFLAG_CentreY,  &ShipActionList, AssignShipActionToJoyBtn, SelectList, DrawSplitMenuList, NULL, 0  },

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU MENU_NEW_ConfigJoyPOVs = {
	"", InitJoystickPOVConfig, NULL, CheckJoyPOVs, 0,
	{
		{ 10, 0, 190, 20, 0, "press POV to configure, then select required action", FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 10, 30, 190, 40, 0, "", FONT_Small, TEXTFLAG_CentreY | TEXTFLAG_CheckForRefresh,  (void *)JoystickPOVText, NULL, NULL, DrawFlatMenuName, NULL, 0  },
		{ 10, 40, 190, 50, 0, "", FONT_Small, TEXTFLAG_CentreY | TEXTFLAG_CheckForRefresh,  (void *)JoystickPOVDirectionText, NULL, NULL, DrawFlatMenuName, NULL, 0  },
		{ 10, 50, 190, 60, 0, "", FONT_Small, TEXTFLAG_CentreY | TEXTFLAG_CheckForRefresh,  (void *)SelectedActionText, NULL, NULL, DrawFlatMenuName, NULL, 0  },
		{ 10, 60, 190, 170, 0, "", FONT_Small, TEXTFLAG_SuppressHighlight | TEXTFLAG_AutoSelect | TEXTFLAG_CentreY,  &ShipActionList, AssignShipActionToJoyPOV, SelectList, DrawFlatMenuList, NULL, 0  },

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_SetupJoystick2 = {
	"", NULL, NULL, NULL, 0,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_SetupJoystick20 /*"joystick setup"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 10, 30, 200, 40, 0, LT_MENU_NEW_SetupJoystick21 /*"configure buttons"*/, FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, &MENU_NEW_ConfigJoyBtns, MenuChange, DrawFlatMenuItem, NULL, 0  },
		{ 10, 50, 200, 60, 0, LT_MENU_NEW_SetupJoystick22 /*"configure Axis"*/, FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, SelectConfigureAxisMenu, DrawFlatMenuItem, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}

};

MENU	MENU_NEW_SetupJoystick = {
	"", InitJoystickList, ExitJoySetup, NULL, 0,
	{
#if 1
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_SetupJoystick0 /*"choose joystick"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 10, 30, 200, 100, 0, LT_MENU_NEW_SetupJoystick1 /*"joystick list"*/, FONT_Small, TEXTFLAG_SuppressHighlight | TEXTFLAG_CentreY | TEXTFLAG_ForceFit | TEXTFLAG_AutoSelect,
#ifdef VDUKDEF
							&JoystickList, SelectConfigureAxisMenu, SelectList, DrawFlatMenuList, NULL, 0  },
#else
							&JoystickList, JoystickChosen, SelectList, DrawFlatMenuList, NULL, 0  },
#endif
#else
		{ 0, 0, 200, 20, 0, "joystick setup", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 0, 20, 200, 30, 0, "select joystick", FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  &JoystickList, NULL, SelectVDUList, DrawFlatMenuItem, NULL, 0  },
		{ 10, 40, 200, 110, 0, "joystick list", FONT_Small, TEXTFLAG_SuppressHighlight | TEXTFLAG_CentreY | TEXTFLAG_ForceFit, &JoystickList, NULL, NULL, DrawFlatMenuList, NULL, 0  },
		{ 10, 110, 90, 130, 0, "configure buttons", FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, &MENU_NEW_ConfigJoyBtns, MenuChange, DrawFlatMenuItem, NULL, 0  },
		//{ 110, 110, 180, 130, 0, "configure POVs", FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, &MENU_NEW_ConfigJoyPOVs, MenuChange, DrawFlatMenuItem, NULL, 0  },
//		{ 100, 110, 180, 130, 0, "configure Axis", FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, &MENU_NEW_ConfigJoyAxis, MenuChange, DrawFlatMenuItem, NULL, 0  },
		{ 100, 110, 180, 130, 0, "configure Axis", FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, SelectConfigureAxisMenu, DrawFlatMenuItem, NULL, 0  },
#endif						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}

};

MENUITEM AxisScreenItem = { 100, 110, 180, 130, 0, LT_AxisScreenItem/*"configure Axis"*/, FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, &MENU_NEW_ConfigJoyAxis, MenuChange, DrawFlatMenuItem, NULL, 0  };

MENU	MENU_NEW_SetupMouse = {
	"", NULL, ExitMouseSetup, NULL, 0,
	{
		{ 10, 85, 100, 95, SLIDER_Sensitivity, LT_MENU_NEW_SetupMouse0 /*"X sensitivity"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY,  &SensitivityXSlider, NULL, SelectSlider,	DrawFlatMenuSlider, NULL, 0  },
		{ 10, 95, 100, 105, SLIDER_Sensitivity, LT_MENU_NEW_SetupMouse1 /*"Y sensitivity"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY,  &SensitivityYSlider, NULL, SelectSlider,	DrawFlatMenuSlider, NULL, 0  },
		{ 10, 115, 100, 125, 0, LT_MENU_NEW_SetupMouse2 /*"invert x"*/, FONT_Small, TEXTFLAG_CentreY,  &Config.invert_turn, NULL, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0  },
		{ 10, 125, 100, 135, 0, LT_MENU_NEW_SetupMouse3 /*"invert y"*/, FONT_Small, TEXTFLAG_CentreY,  &Config.invert_pitch, NULL, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0  },

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}

};

MENU	MENU_NEW_Controls = {
	"", InitControls, ExitControls, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		

		{ 0, 0, 200, 20, 0, LT_MENU_NEW_Controls0 /*"controls"*/, FONT_Large, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },

		{ 10, 30, 200, 40, 0, LT_MENU_NEW_Controls1 /*"configure mouse"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &MENU_NEW_SetupMouse, MenuChange,	DrawFlatMenuItem, NULL, 0  },

		{ 10, 45, 200, 55, 0, LT_MENU_NEW_Controls2 /*"configure joystick"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &MENU_NEW_SetupJoystick, MenuChange, DrawFlatMenuItem, NULL, 0  },
		{ 10, 60, 200, 70, 0, LT_MENU_NEW_Controls3 /*"configure keys and buttons"*/, FONT_Small, TEXTFLAG_CentreY, NULL, &MENU_NEW_ConfigureKeyboard, MenuChange, DrawFlatMenuItem, NULL, 0  },
#ifdef VERSION_GERMAN
		{ 10, 75, 120, 85, 0, LT_MENU_NEW_Controls4 /*"autoleveling"*/, FONT_Small, TEXTFLAG_CentreY,  &Autoleveling, SetAutolevel, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0  },
#else
		{ 10, 75, 100, 85, 0, LT_MENU_NEW_Controls4 /*"autoleveling"*/, FONT_Small, TEXTFLAG_CentreY,  &Autoleveling, SetAutolevel, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0  },
#endif
		{ 10, 90, 200, 100, 0, LT_MENU_NEW_Controls5 /*"restore defaults"*/, FONT_Small, TEXTFLAG_CentreY,  NULL, NULL, RestoreDefaultControlSettings, DrawFlatMenuItem, NULL, 0  },
		{ 10, 105, 200, 115, 0, LT_MENU_NEW_Controls6 /*"back"*/, FONT_Small, TEXTFLAG_CentreY,  NULL, NULL, MenuItemBack, DrawFlatMenuItem, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};


MENU	MENU_NEW_Lights = {
	"Lights", InitDetailLevels, ExitDetailLevels, NULL, 0,
	{

		{ 0, 0, 200, 20, 0, LT_MENU_NEW_Lights0 /*"LIGHTS"*/, FONT_Large, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 10, 40, 135, 50, 0, LT_MENU_NEW_Lights1 /*"Primary Lights"*/, FONT_Small, TEXTFLAG_CentreY,		&PrimaryLightDetail,	SetLightStates,	SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 },
		{ 10, 60, 135, 70, 0, LT_MENU_NEW_Lights2 /*"Secondary Lights"*/, FONT_Small, TEXTFLAG_CentreY,		&SecondaryLightDetail,	SetLightStates,	SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 },
		{ 10, 80, 135, 90, 0, LT_MENU_NEW_Lights3 /*"Pickup Lights"*/, FONT_Small, TEXTFLAG_CentreY,		&PickupLightDetail,		SetLightStates,	SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 },
		{ 10, 100, 135, 110, 0, LT_MENU_NEW_Lights4 /*"Back"*/, FONT_Small, TEXTFLAG_CentreY,		NULL,		NULL,	MenuItemBack, DrawFlatMenuItem, NULL, 0 },

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	 
	}
};

MENU MENU_NEW_Misc = {
	"", NULL, NULL, NULL, TITLE_TIMER_PanToLeftVDU,
	{

		{ 10, 100, 135, 110, 0, "Back", FONT_Small, TEXTFLAG_CentreY,		NULL,		NULL,	MenuItemBack, DrawFlatMenuItem, NULL, 0 },

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	 
	}
};


MENU	MENU_NEW_DetailLevels = {
	"", InitDetailLevels, ExitDetailLevels, NULL, 0,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_DetailLevels0/*"DETAIL LEVELS"*/, FONT_Large, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 10, 30, 140, 40, 0, LT_MENU_Detail1/*"Bi Linear Filtering"*/, FONT_Small, TEXTFLAG_CentreY,  &BiLinearFiltering, SetOurRenderStates,	SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0  },
		{ 10, 40, 140, 50, 0, LT_MENU_Detail1a/*"Tri Linear Filtering"*/, FONT_Small, TEXTFLAG_CentreY,  &TriLinear, SetOurRenderStates,	SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0  },
		{ 10, 50, 140, 60, 0, LT_MENU_NEW_DetailLevels2/*"Perspective Correct"*/, FONT_Small, TEXTFLAG_CentreY,		&PerspectiveCorrect,	SetOurRenderStates,	SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 },
		{ 10, 60, 140, 70, 0, LT_MENU_NEW_DetailLevels3/*"Lens Flare"*/, FONT_Small, TEXTFLAG_CentreY,		&LensFlare,				NULL,	SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 },
		{ 10, 70, 140, 80, 0, LT_MENU_NEW_DetailLevels4/*"Team Info"*/, FONT_Small, TEXTFLAG_CentreY,		&ShowTeamInfo,			NULL,	SelectFlatMenuToggle,	DrawFlatMenuToggle, NULL, 0 },
		{ 10, 80, 140, 90, 0, LT_MENU_NEW_DetailLevels5/*"Auto Detail"*/, FONT_Small, TEXTFLAG_CentreY,		&AutoDetail,			NULL,	SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 },
		{ 10, 90, 115, 100, 0, LT_MENU_NEW_DetailLevels6/*"Smoke Trail Detail"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY,		&TrailDetailSlider,		NULL,	SelectSlider,	DrawFlatMenuSlider, NULL, 0 },
		{ 10, 100, 115, 110, 0, LT_MENU_NEW_DetailLevels7/*"Bike Detail"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY,		&BikeDetailSlider,		NULL,	SelectSlider,	DrawFlatMenuSlider, NULL, 0 },
		{ 10, 110, 115, 120, 0, LT_MENU_NEW_DetailLevels8/*"Water Detail"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY,		&WaterDetailSlider,		NULL,	SelectSlider,	DrawFlatMenuSlider, NULL, 0 },
#ifndef NO_GORE
		{ 10, 120, 140, 130, 0, LT_MENU_NEW_DetailLevels9/*"mature content"*/, FONT_Small, TEXTFLAG_CentreY,		&GoreGuts,				NULL,	SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 },
#endif
#ifndef SEPARATE_PRE_GAME_LIGHTS_MENU
		{ 10, 130, 140, 140, 0, LT_MENU_NEW_DetailLevels10/*"Primary Lights"*/, FONT_Small, TEXTFLAG_CentreY,		&PrimaryLightDetail,	SetLightStates,	SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 },
		{ 10, 140, 140, 150, 0, LT_MENU_NEW_DetailLevels11/*"Secondary Lights"*/, FONT_Small, TEXTFLAG_CentreY,		&SecondaryLightDetail,	SetLightStates,	SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 },
		{ 10, 150, 140, 160, 0, LT_MENU_NEW_DetailLevels12/*"Pickup Lights"*/, FONT_Small, TEXTFLAG_CentreY,		&PickupLightDetail,		SetLightStates,	SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 },
#else
		{ 10, 130, 140, 140, 0, LT_MENU_NEW_DetailLevels13/*"Lights..."*/, FONT_Small, TEXTFLAG_CentreY,		NULL,		&MENU_NEW_Lights,	MenuChange,	DrawFlatMenuItem, NULL, 0 },
#if !defined( SHAREWARE ) && !defined( PCIDENT ) && !defined( EXTERNAL_DEMO ) && !defined ( FINAL_RELEASE )
		{ 10 ,140, 150, 140, 0, LT_MENU_NEW_DetailLevels14/*"Show Extra Info "*/, FONT_Small, TEXTFLAG_CentreY, &myglobs.bShowInfo, NULL, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 },
		{ 10 ,150, 160, 150, 0, LT_MENU_NEW_DetailLevels15/*"Show Weapon Kills"*/, FONT_Small, TEXTFLAG_CentreY, &ShowWeaponKills, NULL, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 },
#endif
#endif
		{ 10, 160, 135, 170, 0, LT_MENU_NEW_DetailLevels16/*"Back"*/, FONT_Small, TEXTFLAG_CentreY,		NULL,		NULL,	MenuItemBack, DrawFlatMenuItem, NULL, 0 },


		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	 
	}
};


MENU	MENU_NEW_ScreenRes = {
	"Select Screen Mode" , MakeModeList , NULL , NULL, 0,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_ScreenRes0 /*"Choose From..."*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,
		{ 15, 30, 100, 150, 0, "", FONT_Small, TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &ModeList, NewMenuSelectMode , SelectList , DrawFlatMenuList, NULL, 0 } ,
		{ 0, 155, 200, 165, 0, LT_MENU_NEW_ScreenRes1 /*"press escape to go back"*/, FONT_Small, TEXTFLAG_CentreY | TEXTFLAG_CentreX, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_TextureFormat = {
	"" , MakeTextureList , NULL , NULL, 0,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_TextureFormat0 /*"Choose From..."*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,
		{ 15, 30, 195, 150, 0, "", FONT_Small, TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &TextureList, NewMenuTextureMode , SelectList , DrawFlatMenuList, NULL, 0 } ,
		{ 0, 155, 200, 165, 0, LT_MENU_NEW_TextureFormat1 /*"press escape to go back"*/, FONT_Small, TEXTFLAG_CentreY | TEXTFLAG_CentreX, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_Visuals = {
	"", NULL, NULL, NULL, TITLE_TIMER_Visuals,
	{
#if 1
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_Visuals0 /*"Visuals"*/, FONT_Large, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 20, 40, 200, 50, 0, LT_MENU_NEW_Visuals1 /*"Change Detail Levels"*/, FONT_Small, TEXTFLAG_CentreY,  NULL, &MENU_NEW_DetailLevels , MenuChange, DrawFlatMenuItem, NULL, 0  },
		{ 20, 60, 200, 70, 0, LT_MENU_NEW_Visuals2 /*"Change Screen Res"*/, FONT_Small, TEXTFLAG_CentreY,  NULL, &MENU_NEW_ScreenRes , MenuChange, DrawFlatMenuItem, NULL, 0  },
		{ 20, 80, 200, 90, 0, LT_MENU_NEW_Visuals3 /*"Select Texture Format"*/, FONT_Small, TEXTFLAG_CentreY,  NULL, &MENU_NEW_TextureFormat , MenuChange, DrawFlatMenuItem, NULL, 0  },
		{ 20, 100, 50, 110, SLIDER_Percent, LT_MENU_NEW_Visuals4 /*"gamma"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &GammaSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 },
		{ 20, 120, 200, 130, 0, LT_MENU_NEW_Visuals5 /*"back"*/, FONT_Small, TEXTFLAG_CentreY,  NULL, NULL , MenuItemBack, DrawFlatMenuItem, NULL, 0  },
#else
  /*
  128  � ( 199 )  144  � ( 201 )  160  � ( 225 )   
  129  � ( 252 )  145  � ( 230 )  161  � ( 237 )  
  130  � ( 233 )  146  � ( 198 )  162  � ( 243 )  
  131  � ( 226 )  147  � ( 244 )  163  � ( 250 )  
  132  � ( 228 )  148  � ( 246 )  164  � ( 241 )  
  133  � ( 224 )  149  � ( 242 )  165  � ( 209 )  
  134  � ( 229 )  150  � ( 251 )  166  � ( 170 )  
  135  � ( 231 )  151  � ( 249 )  167  � ( 186 )
  136  � ( 234 )  152  � ( 255 )  168  � ( 191 )
  137  � ( 235 )  153  � ( 214 )  169  _ ( 095 )
  138  � ( 232 )  154  � ( 220 )  170  � ( 172 )  
  139  � ( 239 )  155  � ( 162 )  171  � ( 189 )  
  140  � ( 238 )  156  � ( 163 )  172  � ( 188 )  
  141  � ( 236 )  157  � ( 165 )  173  � ( 161 )  
  142  � ( 196 )  158  P ( 080 )  174  � ( 171 )  
  143  � ( 197 )  159  � ( 131 )  175  � ( 187 )  
  */
		
		{ 20, 140, 180, 170, 0, "���� ����� ����� ����� ����� ��ܢ� �P��� ���Ѫ ��_�� ����", FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
#endif				 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU MENU_NEW_LobbyWaitingForHost = {
	"", InitLobbyWaitingForHost, NULL, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		{ 20, 10, 200, 30, 0, LT_MENU_NEW_LobbyWaitingForHost0 /*"host is choosing game type, please wait"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },

		{ 0, 140, 200, 170, 0, LT_MENU_NEW_LobbyWaitingForHost1 /*"quit"*/, FONT_Small, TEXTFLAG_CentreY | TEXTFLAG_CentreX,  NULL, NULL, SelectQuit, DrawFlatMenuItem, NULL, 0  },
	
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL, NULL , NULL, NULL, 0 },
	}
};

MENU	MENU_NEW_JoinWaitingToStart = {
	"" , InitHostWaitingToStart, BailMultiplayerFrontEnd , UpdateSessions, TITLE_TIMER_PanToLeftVDU,
	{

		{ 0, 0, 200, 10, 0, LT_MENU_NEW_JoinWaitingToStart0 /*"waiting for host..."*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 5, 27, 100, 37, SLIDER_Value, LT_MENU_NEW_JoinWaitingToStart1 /*"Num of Players"*/, FONT_Small, TEXTFLAG_CentreY, &NumOfPlayersSlider, NULL, NULL, DrawFlatMenuSlider, NULL, 0 },
		{ 5, 40, 100, 125, 0, "", FONT_Small, TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY , &PlayersList, NULL , NULL , DrawFlatMenuList, NULL, 0 } ,

		{ 5, 126, 200, 133, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[3], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 133, 200, 140, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[2], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 140, 200, 147, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[1], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 147, 200, 154, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[0], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 155, 25, 162, 0, LT_MENU_NEW_JoinWaitingToStart2 /*"msg:"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, &TitlePlayerMessage, NULL ,SelectFlatMenutext , DrawFlatMenuText, NULL, 0 } ,

		{ 5, 163, 25, 170, 0, LT_MENU_NEW_CreateGame17/*"quit"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, NULL, NULL , SelectQuit, DrawFlatMenuItem, NULL, 0 } ,

		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL, NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_Dummy = {
	"" , NULL, NULL , NULL, TITLE_TIMER_PanToLeftVDU,
	{

		{ 0, 0, 200, 10, 0, "test...", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL, NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_GetTeamPlayers = {
	"" , GetInitialSessions, BailMultiplayer , CheckForMenuChange, 0,
	{

		{ 0, 0, 200, 10, 0, LT_MENU_NEW_GetTeamPlayers0 /*"waiting for host..."*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 5, 27, 100, 37, SLIDER_Value, LT_MENU_NEW_GetTeamPlayers1 /*"Num of Players"*/, FONT_Small, TEXTFLAG_CentreY, &NumOfPlayersSlider, NULL, NULL, DrawFlatMenuSlider, NULL, 0 },
		{ 5, 40, 100, 165, 0, "", FONT_Small, TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY , &PlayersList, NULL , NULL , DrawFlatMenuList, NULL, 0 } ,

		{ 5, 126, 200, 133, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[3], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 133, 200, 140, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[2], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 140, 200, 147, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[1], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 147, 200, 154, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[0], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 155, 25, 162, 0, LT_MENU_NEW_GetTeamPlayers2 /*"msg:"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, &TitlePlayerMessage, NULL ,SelectFlatMenutext , DrawFlatMenuText, NULL, 0 } ,

		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL, NULL , NULL, NULL, 0 }
	}
};

char Session_Info_Created[ 128 ];
char Session_Info_Level_Name[ 128 ];
char Session_Info_Num_Players[ 128 ];
char Session_Info_Game_Type[ 128 ];
char Session_Info_PacketInfo[ 128 ];
char Session_Info_PPS[ 128 ];
char Session_Info_LagTolerance[ 128 ];

char Session_Info_Server[ 128 ];
char Session_Info_HarmTeamMates[ 128 ];
char Session_Info_MaxKills[ 128 ];
char Session_Info_TimeLimit[ 128 ];
char Session_Info_BrightShips[ 128 ];
char Session_Info_BikeExhausts[ 128 ];

char Session_Info_Server_BigMsg[ 128 ];

#define SESSIONJOIN_EXTRAS_TOP_Y 128
#define SESSIONJOIN_EXTRAS_LINEHEIGHT 7

MENU	MENU_NEW_ChooseSessionToJoin = {

		"" , GetMyCurrentSessions , MenuReleaseDPlay , CopySessionsList, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_ChooseSessionToJoin0 /*"Choose session to join"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,

			// session list
		//{ 10, 22, 100, 30, 0, "name", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,
		{ 10, 30, 200, 85, 0, "", FONT_Small, TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &MySessionsList, SetSessionJoinFlag , SelectList , DrawFlatMenuList, NULL, 0 } ,

		// ping list
//		{ 100, 22, 200, 30, 0, "ping", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,
//		{ 100, 30, 200, 85, 0, "", FONT_Small, TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_Unselectable | TEXTFLAG_CentreY, &SessionPingList, SetSessionJoinFlag , SelectList , DrawFlatMenuList, NULL, 0 } ,

		{ 0, 15, 200, 30, 0, "( press F1 to refresh session info )", FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,

		// session created
		{ 10, 86, 200, 93, 0, NULL, FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)&Session_Info_Created, NULL ,NULL , DrawFlatMenuName, NULL, 0 } ,

		// level
		{ 10, 93, 200, 100, 0, NULL, FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)&Session_Info_Level_Name, NULL ,NULL , DrawFlatMenuName, NULL, 0 } ,

		// players
		{ 10, 100, 200, 107, 0, NULL, FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)&Session_Info_Num_Players, NULL ,NULL , DrawFlatMenuName, NULL, 0 } ,

		// game type 
		{ 10, 107, 200, 114, 0, NULL, FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)&Session_Info_Game_Type, NULL ,NULL , DrawFlatMenuName, NULL, 0 } ,

		// packet info
		{ 10, 114, 200, 121, 0, NULL, FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)&Session_Info_PacketInfo, NULL ,NULL , DrawFlatMenuName, NULL, 0 } ,

		// lag tolerence
		{ 10, 121, 200, 128, 0, NULL, FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)&Session_Info_LagTolerance, NULL ,NULL , DrawFlatMenuName, NULL, 0 } ,

		// extras
		{ 10, SESSIONJOIN_EXTRAS_TOP_Y, 200, 146, 0, NULL, FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)&Session_Info_PPS, NULL ,NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 10, 146, 200, 154, 0, NULL, FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)&Session_Info_Server, NULL ,NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 10, 154, 200, 162, 0, NULL, FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)&Session_Info_HarmTeamMates, NULL ,NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 10, 162, 200, 170, 0, NULL, FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)&Session_Info_MaxKills, NULL ,NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 10, 170, 200, 178, 0, NULL, FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)&Session_Info_TimeLimit, NULL ,NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 10, 178, 200, 186, 0, NULL, FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)&Session_Info_BrightShips, NULL ,NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 10, 186, 200, 194, 0, NULL, FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)&Session_Info_BikeExhausts, NULL ,NULL , DrawFlatMenuName, NULL, 0 } ,

		// server game message...
		{ 10, 146, 190, 186, 0, NULL, FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreYBunched | TEXTFLAG_CentreX, (void *)&Session_Info_Server_BigMsg, NULL ,NULL , DrawFlatMenuName, NULL, 0 } ,

		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENUITEM MENU_ITEM_JoinMultiplayer = 
		{ 0, 0, 0, 0, 0, "", 0, 0,  NULL, &MENU_NEW_ChooseSessionToJoin, MenuChange, NULL, NULL, 0  };


MENU	MENU_NEW_ChooseConnectionToJoin = {
	"", GetServiceProviders, NULL, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_ChooseConnectionToJoin0/*"start"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, SelectConnectionToJoin, DrawFlatMenuItem, NULL, 0  },
		{ 5, 20, 200, 30, 0, LT_MENU_NEW_ChooseConnectionToJoin1/*"Choose connection type:"*/, FONT_Small, TEXTFLAG_CentreY, &ServiceProvidersList, NULL, SelectVDUList, DrawFlatMenuItem, NULL, 0  },
		{ 10, 35, 200, 155, 0, "", FONT_Small,TEXTFLAG_Unselectable | TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY,  &ServiceProvidersList, NULL, SelectList, DrawFlatMenuList, NULL, 0  },

		{ 5, 150, 60, 160, 0, LT_MENU_NEW_ChooseConnectionToJoin2/*"tcp add:"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, &TCPAddress, NULL ,SelectFlatMenutext , DrawFlatMenuText, NULL, 0 } ,

//		{ 0, 160, 200, 170, 0, LT_MENU_NEW_ChooseConnectionToStart1 /*"press 'q' to quit"*/, FONT_Small, TEXTFLAG_CentreY | TEXTFLAG_CentreX,  NULL, NULL, SelectQuit, DrawFlatMenuItem, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};


MENU	MENU_NEW_ChangeBike = {
	"", InitBikeListVDU, KillBikeChar, NULL, 0,
	{
		{ 0, 0, 200 , 20, 0, "", FONT_Large, TEXTFLAG_CentreX | TEXTFLAG_CentreY , &bike_name, NULL, NULL, DrawFlatMenuName, NULL, 0 } ,
		{ 15, 20, 135 , 128, 0, "", FONT_Small, TEXTFLAG_ForceFit , &biker_text, NULL, NULL, DrawFlatMenuName, NULL, 0 } ,

		{ 27, 130, 72 , 137, SLIDER_Bike, LT_MENU_NEW_ChangeBike0 /*"speed"*/, FONT_Small, TEXTFLAG_CentreY , &SpeedFeat, NULL, NULL, DrawFlatMenuSlider, NULL, 0 } ,
		{ 27, 137, 72 , 144, SLIDER_Bike, LT_MENU_NEW_ChangeBike1 /*"accel"*/, FONT_Small, TEXTFLAG_CentreY , &AccelFeat, NULL, NULL, DrawFlatMenuSlider, NULL, 0 } ,
		{ 65, 144, 110 , 151, SLIDER_Bike, LT_MENU_NEW_ChangeBike2 /*"handling"*/, FONT_Small, TEXTFLAG_CentreY , &HandleFeat, NULL, NULL, DrawFlatMenuSlider, NULL, 0 } ,
		
		{ 114, 130, 157 , 137, SLIDER_Bike, LT_MENU_NEW_ChangeBike3 /*"shield"*/, FONT_Small, TEXTFLAG_CentreY , &ShieldFeat, NULL, NULL, DrawFlatMenuSlider, NULL, 0 } ,
		{ 114, 137, 157 , 144, SLIDER_Bike, LT_MENU_NEW_ChangeBike4 /*"hull"*/, FONT_Small, TEXTFLAG_CentreY , &HullFeat, NULL, NULL, DrawFlatMenuSlider, NULL, 0 } ,

		{ 125 , 20, 200, 130, 0, "" , FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY , NULL, NULL , NULL , LoadBikeChar, NULL, 0},

		{ -1, -1, 0, 0, 0,"", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 }

	}
};

MENU	MENU_NEW_ChoosePlayer = {
	"", InitVDUPilotMenu, KillBikeChar, NULL, 0,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_ChoosePlayer0 /*"Choose Player"*/, FONT_Large, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,
		{ 125 , 130, 200, 150, 0, "" , FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY | TEXTFLAG_CheckForRefresh, &bike_name, NULL , NULL , DrawFlatMenuName, NULL, 0},
		{ 15 , 30, 100, 150, 0, LT_MENU_NEW_ChoosePlayer1 /*"list..."*/ , FONT_Small, TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY , &PilotList, NULL , NULL , DrawFlatMenuList, NULL, 0},

		{ 125 , 20, 200, 130, 0, "" , FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY , NULL, NULL , NULL , LoadBikeChar, NULL, 0},
			
		{ -1, -1, 0, 0, 0,"", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 }

	}
};

MENU	MENU_NEW_NewPlayer = {
	"", InitPilotName, ExitBikerMenu, NULL, TITLE_TIMER_PanToRightVDU,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_NewPlayer0 /*"Enter Player Name"*/, FONT_Medium, TEXTFLAG_ForceFit | TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },

		{ 15 , 50, 15, 70, 0, "" , FONT_Medium, TEXTFLAG_SuppressHighlight | TEXTFLAG_AutoSelect | TEXTFLAG_ForceFit | TEXTFLAG_CentreY , &PilotName, NULL, SelectFlatMenutext, DrawFlatMenuText, NULL, 0},
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};										 

MENU MENU_NEW_ChangePlayerName = {
	"", InitPilotReName, MoveConfigFile, NULL, TITLE_TIMER_PanToRightVDU,
	{
		
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_ChangePlayerName0 /*"Enter new Name"*/, FONT_Medium, TEXTFLAG_ForceFit | TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },

		{ 15 , 50, 15, 70, 0, "" , FONT_Medium, TEXTFLAG_SuppressHighlight | TEXTFLAG_AutoSelect | TEXTFLAG_ForceFit | TEXTFLAG_CentreY , &PilotReName, NULL, SelectFlatMenutext, DrawFlatMenuText, NULL, 0},
		
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_ChangeBikeComputer;

MENU	MENU_NEW_SelectBiker = {
	"", NewInitBikeMenu, ExitBikerMenu, NULL, TITLE_TIMER_PanToRightVDU,
	{
		{ 5 , 0, 195, 20, 0, "" , FONT_Large, TEXTFLAG_ForceFit | TEXTFLAG_CentreX | TEXTFLAG_CentreY , (void *)biker_name, NULL , NULL , DrawFlatMenuName, NULL, 0},
		{ 15 , 25, 85, 45, 0, LT_MENU_NEW_SelectBiker0 /*"Choose Player"*/ , FONT_Small, TEXTFLAG_CentreY , NULL, &MENU_NEW_ChoosePlayer , MenuChange , DrawFlatMenuItem, NULL, 0},
		{ 15 , 45, 85, 65, 0, LT_MENU_NEW_SelectBiker1 /*"New Player"*/ , FONT_Small, TEXTFLAG_CentreY , NULL, &MENU_NEW_NewPlayer, MenuChange, DrawFlatMenuItem, NULL, 0},
		{ 15 , 65, 85, 85, 0, LT_MENU_NEW_SelectBiker2 /*"rename player"*/ , FONT_Small, TEXTFLAG_CentreY , NULL, &MENU_NEW_ChangePlayerName , MenuChange , DrawFlatMenuItem, NULL, 0},
		{ 15 , 85, 85, 105, 0, LT_MENU_NEW_SelectBiker3 /*"Change Bike"*/ , FONT_Small, TEXTFLAG_CentreY , NULL, &MENU_NEW_ChangeBike , MenuChange , DrawFlatMenuItem, NULL, 0},
		{ 15 , 105, 85, 125, 0, LT_MENU_NEW_SelectBiker4 /*"Change Bike computer"*/ , FONT_Small, TEXTFLAG_CentreY , NULL, &MENU_NEW_ChangeBikeComputer , MenuChange , DrawFlatMenuItem, NULL, 0},
		{ 15 , 125, 85, 145, 0, LT_MENU_NEW_SelectBiker5 /*"Exit"*/ , FONT_Small, TEXTFLAG_CentreY , NULL, NULL , MenuItemBack , DrawFlatMenuItem, NULL, 0},
		{ 125 , 130, 200, 150, 0, "" , FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY , &bike_name, NULL , NULL , DrawFlatMenuName, NULL, 0},

		{ 125 , 20, 200, 130, 0, "" , FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY , NULL, NULL , NULL , LoadBikeChar, NULL, 0},

		{ -1, -1, 0, 0, 0,  "",0, 0, NULL, NULL, NULL, NULL, NULL, 0 }
	}
};										 

MENUITEM BikeCharItem = 
		{ 125 , 20, 200, 130, 0, "" , FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY , NULL, NULL , NULL , LoadBikeChar, NULL, 0};

MENU	MENU_NEW_DemoPlayBack = {
	"Demo Playback" , InitDemoList, NULL, NULL, 0,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_DemoPlayBack0 /*"play back demo"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,
		{ 0, 20, 200, 30, 0, LT_MENU_NEW_DemoPlayBack1 /*"Start"*/, FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL, StartDemoPlayback , DrawFlatMenuItem, NULL, 0 } ,
		{ 10, 40, 100, 50, SLIDER_Demo, LT_MENU_NEW_DemoPlayBack2 /*"playback speed"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &DemoSpeed, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
		{ 10, 50, 100, 50, SLIDER_Value, "FSB Compensation", FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &FSBCompensation, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
		{ 10, 60, 90, 60, SLIDER_Value, LT_MENU_NEW_DemoPlayBack3 /*"watch player"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &DemoEyesSelect, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,

		{ 10, 75, 200, 75, 0, LT_MENU_NEW_DemoPlayBack4 /*"choose demo"*/, FONT_Small, TEXTFLAG_CentreY, &DemoList, NULL, SelectVDUList, DrawFlatMenuItem, NULL, 0 } ,
 		{ 20, 90, 200, 150, 0, "",  FONT_Small, TEXTFLAG_Unselectable | TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, &DemoList, NULL, SelectList, DrawFlatMenuList, NULL, 0 } ,
		
		{ 5, 160, 200, 160, 0, "", FONT_Small, TEXTFLAG_CentreY | TEXTFLAG_CheckForRefresh,  (void *)DemoAvgFpsText, NULL, NULL, DrawFlatMenuName, NULL, 0  },
		{ 5, 170, 200, 170, 0, "", FONT_Small, TEXTFLAG_CentreY | TEXTFLAG_CheckForRefresh,  (void *)DemoTotalFramesText, NULL, NULL, DrawFlatMenuName, NULL, 0  },
		
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_LoadSavedGame = {
	LT_MENU_LoadSavedGame0/*"Load Saved Game"*/, InitLoadSavedGameList, NULL, NULL, 0,
	{
		{ 100 , 128, 0, 0, 0, LT_MENU_LoadSavedGame1/*"Choose From..."*/, 0, 0, &LoadSavedGameList, InGameLoadASinglePlayerGame, SelectList , DrawList, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_Sound = {
	LT_MENU_NEW_Sound0 /*"sound"*/ , NULL, ExitSoundMenu, SetSoundLevels, TITLE_TIMER_NormalPanToRightVDU,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_Sound1 /*"sound options"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,
		{ 10, 40, 100, 50, 0, LT_MENU_NEW_Sound2 /*"sfx volume"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &SfxSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
#ifndef WIN98SHAREWARE
		{ 10, 50, 100, 60, 0, LT_MENU_NEW_Sound3 /*"cd audio"*/, FONT_Small, TEXTFLAG_CentreY, &CD_OK, ToggleCDAudioTitles, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 } ,
#endif
		{ 10, 60, 100, 70, 0, LT_MENU_NEW_Sound4 /*"bike engines"*/, FONT_Small, TEXTFLAG_CentreY, &BikeEnginesOn, NULL, SelectFlatMenuToggle, DrawFlatMenuToggle, NULL, 0 } ,

		{ 0, 80, 200, 100, 0, LT_MENU_NEW_Sound5 /*"speech options"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,
		{ 10, 100, 100, 110, 0, LT_MENU_NEW_Sound6 /*"biker speech"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &BikerSpeechSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
		{ 10, 110, 100, 120, 0, LT_MENU_NEW_Sound7 /*"bike computer"*/, FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &BikeCompSpeechSlider, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,


		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_InGameSound = {
	LT_MENU_NEW_InGameSound0 /*"sound"*/ , NULL, NULL, SetSoundLevels, 0,
	{
		{ 200, 128           , 0, 0, 0, LT_MENU_NEW_InGameSound1 /*"sfx volume    "*/, 0, 0, &SfxSlider, NULL, SelectSlider, DrawSlider, NULL, 0 },
#ifndef WIN98SHAREWARE
		{ 200, 128 + (1*16)  , 0, 0, 0, LT_MENU_NEW_InGameSound2 /*"cd audio      "*/, 0, 0, &CD_OK, ToggleCDAudio, SelectToggle, DrawToggle, NULL, 0 },
#endif
		{ 200, 128 + (2*16)	 , 0, 0, 0, LT_MENU_NEW_InGameSound3 /*"bike engines  "*/, 0, 0, &BikeEnginesOn, ToggleBikeEngines, SelectToggle, DrawToggle, NULL, 0 } ,
		{ 200, 128 + (3*16)  , 0, 0, 0, LT_MENU_NEW_InGameSound4 /*"biker volume  "*/, 0, 0, &BikerSpeechSlider, NULL, SelectSlider, DrawSlider, NULL, 0 },
		{ 200, 128 + (4*16)  , 0, 0, 0, LT_MENU_NEW_InGameSound5 /*"bike computer "*/, 0, 0, &BikeCompSpeechSlider, NULL, SelectSlider, DrawSlider, NULL, 0 },

		{	-1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};


MENU	MENU_NEW_DemoCleaning = {
	"" , InitDemoList, NULL, NULL, 0,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_DemoCleaning0 /*"clean a demo"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,
		{ 0 , 20, 200, 30, 0, LT_MENU_NEW_DemoCleaning1 /*"Start"*/ , FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, &MENU_NotYet , StartDemoCleaning , DrawFlatMenuItem, NULL, 0 } ,
		
		{ 10, 45, 200, 55, 0, LT_MENU_NEW_DemoCleaning2 /*"choose demo"*/, FONT_Small, TEXTFLAG_CentreY, &DemoList, NULL, SelectVDUList, DrawFlatMenuItem, NULL, 0 } ,
		{ 20 , 60, 200, 170, 0, "", FONT_Small,TEXTFLAG_Unselectable | TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY , &DemoList, NULL , SelectList , DrawFlatMenuList, NULL, 0 } ,

		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

#define MAX_SAVEDGAME_INFO_LENGTH 128

char CurrentSavedGameLevel[ MAX_SAVEDGAME_INFO_LENGTH ];
char CurrentSavedGameDate[ MAX_SAVEDGAME_INFO_LENGTH ];
char CurrentSavedGameTimeLevelPlayed[ MAX_SAVEDGAME_INFO_LENGTH ];
char CurrentSavedGameEnemiesKilled[ MAX_SAVEDGAME_INFO_LENGTH ];

MENU	MENU_NEW_LoadGame = {
	"" , InitTitleLoad , ExitTitleLoad, NULL, 0,
	{
		
		{ 0, 0, 200 , 30, 0, "", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY , &CurrentSavedGameLevel, NULL, NULL, DrawFlatMenuName, NULL, 0 } ,
		{ 0, 30, 200 , 60, 0, "", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY , &CurrentSavedGameDate, NULL, NULL, DrawFlatMenuName, NULL, 0 } ,
		{ 0, 60, 200 , 90, 0, "", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY , &CurrentSavedGameEnemiesKilled, NULL, NULL, DrawFlatMenuName, NULL, 0 } ,
		{ 0,90, 200 , 120, 0, "", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY , &CurrentSavedGameTimeLevelPlayed, NULL, NULL, DrawFlatMenuName, NULL, 0 } ,
		{ 0,120, 20 , 170, 0, "", FONT_Large, TEXTFLAG_CentreX | TEXTFLAG_CentreY , &LoadSavedGameList, NULL, NULL, DrawLeftArrow, NULL, 0 } ,
		{ 180,120, 200 , 170, 0, "", FONT_Large, TEXTFLAG_CentreX | TEXTFLAG_CentreY , &LoadSavedGameList, NULL, NULL, DrawRightArrow, NULL, 0 } ,

		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};


MENU	MENU_NEW_RestoreGame = {
	"", NULL, NULL, NULL, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_RestoreGame0 /*"Restore Game"*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, NULL, NULL, DrawFlatMenuItem, NULL, 0  },
		{ 5, 30, 100, 40, 0, LT_MENU_NEW_RestoreGame1 /*"Play Demo"*/, FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, &MENU_NEW_DemoPlayBack, MenuChange, DrawFlatMenuItem, NULL, 0  },
#if !defined( SHAREWARE ) && !defined( PRESS_PREVIEW_DEMO ) && !defined( ACCLAIM_LANFEST )
		{ 5, 50, 100, 60, 0, LT_MENU_NEW_RestoreGame2 /*"Clean Demo"*/, FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, &MENU_NEW_DemoCleaning, MenuChange, DrawFlatMenuItem, NULL, 0  },
#endif
		{ 5, 70, 100, 80, 0, LT_MENU_NEW_RestoreGame3 /*"load game"*/, FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY,  NULL, &MENU_NEW_LoadGame, MenuChange, DrawFlatMenuItem, NULL, 0  },
						 
		{ -1, -1, 0, 0, 0, "", 0, 0,  NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_Options = {
	"", SetDiscStatus, NULL, NULL, TITLE_TIMER_ChooseDiscPan, 
	{
		{ 0, TITLE_MODEL_Disc1, 0, 0, 5,LT_MENU_NEW_Options0 /*"Options"*/, 0, 0, NULL, NULL, NULL, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc2, 0, 0, 8, LT_MENU_NEW_Options1 /*"Sound"*/, 0, 0, NULL, &MENU_NEW_Sound, MenuChange, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc3, 0, 0, 14, LT_MENU_NEW_Options2 /*"Visuals"*/, 0, 0, NULL, &MENU_NEW_Visuals, MenuChange, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc4, 0, 0, 2, LT_MENU_NEW_Options3 /*"back"*/, 0, 0, NULL, NULL, MenuItemBack, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc5, 0, 0, 2, "blank", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc6, 0, 0, 2, "Blank", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 },

		{ -1, -1, 0, 0, 0, "", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 }
	}
};


MENU	MENU_NEW_Setup = {
	"", NULL, NULL, NULL, TITLE_TIMER_ChooseDiscPan,
	{
		{ 0, TITLE_MODEL_Disc1, 0, 0, 4,LT_MENU_NEW_Setup0 /*"Setup Biker"*/, 0, 0, NULL, NULL, NULL, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc2, 0, 0, 6, LT_MENU_NEW_Setup1 /*"Select Bike"*/, 0, 0, NULL, &MENU_NEW_SelectBiker, MenuChange, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc3, 0, 0, 12, LT_MENU_NEW_Setup2 /*"Controls"*/, 0, 0, NULL, &MENU_NEW_Controls, MenuChange, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc4, 0, 0, 4, LT_MENU_NEW_Setup3 /*"Weapons"*/, 0, 0, NULL, &MENU_NEW_Weapons, MenuChange , NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc5, 0, 0, 3, "back"/*"back"*/, 0, 0, NULL, NULL, MenuItemBack, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc6, 0, 0, 2, "Blank", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 },

		{ -1, -1, 0, 0, 0, "", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 }
	}
};  
MENUITEM ECTSStartGameItem = { 0, TITLE_MODEL_Disc2, 0, 0, 4, "Create Game", 0, 0, NULL, &MENU_NEW_ChooseConnectionToStart, MenuChange, NULL, NULL, 0 };
#ifdef ECTS
MENU	MENU_NEW_Battle = {
	"d", NULL, NULL, NULL, TITLE_TIMER_ChooseDiscPan, 
	{
		{ 0, TITLE_MODEL_Disc1, 0, 0, 3,"death match", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc2, 0, 0, 2, "Create Game", 0, 0, NULL, &MENU_NEW_ChooseConnectionToStart, NULL, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc3, 0, 0, 2, "Join Game", 0, 0, NULL, &MENU_NEW_ChooseConnectionToJoin, MenuChange, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc4, 0, 0, 6, "server", 0, 0, NULL, NULL, MenuItemBack, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc5, 0, 0, 2, "blank", 0, 0, NULL, NULL, MenuItemBack, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc6, 0, 0, 2, "Blank", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 },

		{ -1, -1, 0, 0, 0, "", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 }
	}
};
#else
MENU	MENU_NEW_Battle = {
	"", InitBattleMenu, NULL, NULL, TITLE_TIMER_ChooseDiscPan, 
	{
		{ 0, TITLE_MODEL_Disc1, 0, 0, 3,LT_MENU_NEW_Battle0 /*"death match"*/, 0, 0, NULL, NULL, NULL, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc2, 0, 0, 2, LT_MENU_NEW_Battle1 /*"Create Game"*/, 0, 0, NULL, &MENU_NEW_ChooseConnectionToStart, MenuChange, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc3, 0, 0, 2, LT_MENU_NEW_Battle2 /*"Join Game"*/, 0, 0, NULL, &MENU_NEW_ChooseConnectionToJoin, MenuChange, NULL, NULL, 0 },
#if defined ( WIN98SHAREWARE ) || defined ( GATEWAY )
		{ 0, TITLE_MODEL_Disc4, 0, 0, 2, LT_MENU_NEW_Battle3 /*"back"*/, 0, 0, NULL, NULL, MenuItemBack, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc5, 0, 0, 2, "Blank", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 },
#else
		{ 0, TITLE_MODEL_Disc4, 0, 0, 6, LT_MENU_NEW_Battle4 /*"Server"*/, 0, 0, NULL, &MENU_NEW_ChooseConnectionToStartServer, MenuChange, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc5, 0, 0, 3, LT_MENU_NEW_Battle3 /*"back"*/, 0, 0, NULL, NULL, MenuItemBack, NULL, NULL, 0 },
#endif
		{ 0, TITLE_MODEL_Disc6, 0, 0, 2, "Blank", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 },

		{ -1, -1, 0, 0, 0, "", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 }
	}
};
#endif

MENU	MENU_NEW_CoOp = {
	"", NULL, NULL, NULL, TITLE_TIMER_ChooseDiscPan, 
	{
		{ 0, TITLE_MODEL_Disc1, 0, 0, 0,LT_MENU_NEW_CoOp0 /*"Co Op"*/, 0, 0, NULL, NULL, NULL, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc2, 0, 0, 0, LT_MENU_NEW_CoOp1 /*"Join Game"*/, 0, 0, NULL, &MENU_NEW_NotYet, MenuChange, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc3, 0, 0, 0, LT_MENU_NEW_CoOp2 /*"Network Setup"*/, 0, 0, NULL, &MENU_NEW_NotYet, MenuChange, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc4, 0, 0, 0, LT_MENU_NEW_CoOp3 /*"Modem/Serial"*/, 0, 0, NULL, &MENU_NEW_NotYet, MenuChange, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc5, 0, 0, 0, LT_MENU_NEW_CoOp4 /*"Exit"*/, 0, 0, NULL, NULL, MenuItemBack, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc6, 0, 0, 0, "Null", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 },

		{ -1, -1, 0, 0, 0, "", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 }
	}
};



MENU	MENU_NEW_MissionMenu = {
	"", InitDifficultyLevel, NULL, NULL, TITLE_TIMER_ChooseDiscPan, 
	{
		{ 0, TITLE_MODEL_Disc1, 0, 0, 0,LT_MENU_NEW_MissionMenu0 /*"single player"*/, 0, 0, NULL, NULL, NULL, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc2, 0, 0, 4, LT_MENU_NEW_MissionMenu1 /*"Start Game"*/, 0, 0, NULL, &MENU_NEW_StartSinglePlayer, MenuChange, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc3, 0, 0, 6, "", 0, TEXTFLAG_AutoSelect, NULL, NULL, DifficultySet, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc4, 0, 0, 2, LT_MENU_NEW_MissionMenu2 /*"back"*/, 0, 0, NULL, NULL, MenuItemBack, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc5, 0, 0, 2, "Blank", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc6, 0, 0, 2, "Blank", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 },

		{ -1, -1, 0, 0, 0, "", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 }
	}
};
#ifdef ECTS
MENU	MENU_NEW_Start = {
	"", InitStartMenu, NULL, NULL, TITLE_TIMER_ChooseDiscPan,
	{
		{ 0, TITLE_MODEL_Disc1, 0, 0, 1, "single player", 0, 0, NULL, &MENU_NEW_MissionMenu, NULL, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc2, 0, 0, 0, "death match", 0, 0, NULL, &MENU_NEW_Battle, MenuChange, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc3, 0, 0, 0, "Setup Biker", 0, 0, NULL, &MENU_NEW_Setup, NULL, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc4, 0, 0, 0, "load game Game", 0, 0, NULL, &MENU_NEW_RestoreGame, NULL, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc5, 0, 0, 0, "options", 0, 0, NULL, &MENU_NEW_Options, NULL, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc6, 0, 0, 0, "exit game" , 0, 0, NULL, NULL, SelectQuit, NULL, NULL, 0 } ,

		{ -1, -1, 0, 0, 0, "", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 }
	}
};
#else
MENU	MENU_NEW_Start = {
	"", InitStartMenu, NULL, NULL, TITLE_TIMER_ChooseDiscPan,
	{
#ifdef PCIDENT
		{ 0, TITLE_MODEL_Disc1, 0, 0, 1, LT_MENU_NEW_Start0 /*"single player"*/, 0, 0, NULL, &MENU_NEW_NotAvailable, MenuChange, NULL, NULL, 0 },
#else
		{ 0, TITLE_MODEL_Disc1, 0, 0, 1, LT_MENU_NEW_Start1 /*"single player"*/, 0, 0, NULL, &MENU_NEW_MissionMenu, MenuChange, NULL, NULL, 0 },
#endif
		{ 0, TITLE_MODEL_Disc2, 0, 0, 0, LT_MENU_NEW_Start2 /*"death match"*/, 0, 0, NULL, &MENU_NEW_Battle, MenuChange, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc3, 0, 0, 0, LT_MENU_NEW_Start3 /*"Setup Biker"*/, 0, 0, NULL, &MENU_NEW_Setup, MenuChange, NULL, NULL, 0 },
#if defined( SHAREWARE ) || defined( PRESS_PREVIEW_DEMO ) || defined( ACCLAIM_LANFEST )
		{ 0, TITLE_MODEL_Disc4, 0, 0, 0, LT_MENU_NEW_Start4 /*"Play demo"*/, 0, 0, NULL, &MENU_NEW_DemoPlayBack, MenuChange, NULL, NULL, 0 },
#else
		{ 0, TITLE_MODEL_Disc4, 0, 0, 0, LT_MENU_NEW_Start5 /*"load Game"*/, 0, 0, NULL, &MENU_NEW_RestoreGame, MenuChange, NULL, NULL, 0 },
#endif
		{ 0, TITLE_MODEL_Disc5, 0, 0, 0, LT_MENU_NEW_Start6 /*"Options"*/, 0, 0, NULL, &MENU_NEW_Options, MenuChange, NULL, NULL, 0 },
		{ 0, TITLE_MODEL_Disc6, 0, 0, 0, LT_MENU_NEW_Start7 /*"Exit"*/ , 0, 0, NULL, NULL, SelectQuit, NULL, NULL, 0 } ,

		{ -1, -1, 0, 0, 0, "", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 }
	}
};
#endif

MENU	MENU_STATS_Start = {
	"a", InitStartMenu, NULL, NULL, TITLE_TIMER_NormalPanToRightVDU,
	{
		{ 0, 0, 200, 20, 0, "press enter", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL , GoToNextLevel , DrawFlatMenuItem, NULL, 0 } ,
		
		{ -1, -1, 0, 0, 0, "", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 }
	}
};

MENU	MENU_QuickTextSend = {
	"" , NULL, NULL, NULL, 0,
	{
		{ 48, 144, 0, 0, 0, "Message: "/*"Message: "*/, 0, TEXTFLAG_AutoSelect, &QuickText, NULL,  SelectText, DrawTextItem, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};
MENU	MENU_QuickTextSendWhisper = {
	"" , NULL, NULL, NULL, 0,
	{
		{ 48, 144, 0, 0, 0, LT_MENU_QuickTextSendWhisper0 /*"Whisper Message: "*/, 0, TEXTFLAG_AutoSelect, &QuickTextWhisper, NULL,  SelectText, DrawTextItem, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};


MENU	MENU_EditMacro1 = {
	LT_MENU_EditMacro10 /*"Edit Message 1"*/ , NULL, NULL, NULL, 0,
	{
		{ 48, 144, 0, 0, 0, LT_MENU_EditMacro11 /*"Enter Message 1 "*/, 0, 0, &MacroText1, NULL,  SelectText, DrawTextItem, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};
MENU	MENU_EditMacro2 = {
	LT_MENU_EditMacro20 /*"Edit Message 2"*/ , NULL, NULL, NULL, 0,
	{
		{ 48, 144, 0, 0, 0, LT_MENU_EditMacro21 /*"Enter Message 2 "*/, 0, 0, &MacroText2, NULL,  SelectText, DrawTextItem, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" ,0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_EditMacro3 = {
	LT_MENU_EditMacro30/*"Edit Message 1"*/ , NULL, NULL, NULL, 0,
	{
		{ 100, 144, 0, 0, 0, LT_MENU_EditMacro31/*"Enter Message 3 "*/, 0, 0, &MacroText3, NULL,  SelectText, DrawTextItem, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};


MENU	MENU_SinglePlayer = { "Select Difficulty Level" , NULL, NULL , NULL , 0,
					{ {	200 , 144, 0, 0, 0, "Easy" , 0, 0, NULL , (void*) DIFF_Easy , SetDifficulty , MenuItemDrawName, NULL, 0 } ,
					  {	200 , 160, 0, 0, 0, "Normal" , 0, 0, NULL , (void*) DIFF_Norm , SetDifficulty , MenuItemDrawName, NULL, 0 } ,
					  {	200 , 176, 0, 0, 0, "Hard" , 0, 0, NULL , (void*) DIFF_Hard , SetDifficulty , MenuItemDrawName, NULL, 0 } ,
					  {	200 , 192, 0, 0, 0, "Bronson Mode" , 0, 0, NULL , (void*) DIFF_Vhard , SetDifficulty , MenuItemDrawName, NULL, 0 } ,
					  {	-1 , -1, 0, 0, 0, "" , 0, 0, NULL , NULL , NULL , NULL, NULL, 0 } } };



MENU	MENU_Team = {
	"Select Teams" , InitTeamSelection , NULL , NULL, 0,
	{
		{ 200, 112, 0, 0, 0, "Start", 0, 0, NULL, &MENU_NotYet, TeamGoToSynchup , MenuItemDrawName, NULL, 0 } ,
		{ 200, 128, 0, 0, 0, "Red Team", 0, 0, &TeamList[0], NULL , SelectList , DrawList, NULL, 0 } ,
		{ 400, 128, 0, 0, 0, "Green Team", 0, 0, &TeamList[1], NULL , SelectList , DrawList, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" ,0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_NEW_Team = {
	
	"" , InitTeamSelection , BailMultiplayerFrontEnd , DistributeTeamsToLists, TITLE_TIMER_PanToLeftVDU,
	{
		{ 0, 0, 200, 15, 0, LT_MENU_NEW_Team0 /*"select teams"*/, FONT_Large, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,
		{ 0, 15, 200, 30, 0, "", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL, PlayerConfirm , DrawReadyButton, NULL, 0 } ,
		{ 5, 30, 50, 40, 0, LT_MENU_NEW_Team1 /*"Red"*/,  FONT_Small,TEXTFLAG_ForceFit | TEXTFLAG_CentreX | TEXTFLAG_CentreY | TEXTFLAG_TeamItem, &TeamList[0], &Team1 , SelectTeamList, DrawFlatMenuItem, NULL, 0 } ,
		{ 53, 30, 98, 40, 0, LT_MENU_NEW_Team2 /*"Green"*/,  FONT_Small,TEXTFLAG_ForceFit | TEXTFLAG_CentreX | TEXTFLAG_CentreY | TEXTFLAG_TeamItem, &TeamList[1], &Team2 , SelectTeamList, DrawFlatMenuItem, NULL, 0 } ,
		{ 101, 30, 146, 40, 0, LT_MENU_NEW_Team3 /*"Blue"*/,  FONT_Small,TEXTFLAG_ForceFit | TEXTFLAG_CentreX | TEXTFLAG_CentreY | TEXTFLAG_TeamItem, &TeamList[2], &Team3 , SelectTeamList, DrawFlatMenuItem, NULL, 0 } ,
		{ 149, 30, 194, 40, 0, LT_MENU_NEW_Team4 /*"Yellow"*/,  FONT_Small,TEXTFLAG_ForceFit | TEXTFLAG_CentreX | TEXTFLAG_CentreY | TEXTFLAG_TeamItem, &TeamList[3], &Team4 , SelectTeamList, DrawFlatMenuItem, NULL, 0 } ,
		{ 5, 45, 50, 126, 0, LT_MENU_NEW_Team5 /*"Red"*/,  FONT_Small, TEXTFLAG_Unselectable | TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY | TEXTFLAG_Instant, &TeamList[0], NULL , SelectList, DrawFlatMenuList, NULL, 0 } ,
		{ 53, 45, 98, 126, 0, LT_MENU_NEW_Team6 /*"Green"*/,  FONT_Small, TEXTFLAG_Unselectable | TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY | TEXTFLAG_Instant, &TeamList[1], NULL , SelectList, DrawFlatMenuList, NULL, 0 } ,
		{ 101, 45, 146, 126, 0, LT_MENU_NEW_Team7 /*"Blue"*/,  FONT_Small, TEXTFLAG_Unselectable | TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY | TEXTFLAG_Instant, &TeamList[2], NULL , SelectList, DrawFlatMenuList, NULL, 0 } ,
		{ 149, 45, 194, 126, 0, LT_MENU_NEW_Team8 /*"Yellow"*/,  FONT_Small, TEXTFLAG_Unselectable | TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY | TEXTFLAG_Instant, &TeamList[3], NULL , SelectList, DrawFlatMenuList, NULL, 0 } ,
		
		{ 0, 116, 200, 126, 0, LT_MENU_NEW_Team9 /*"waiting for team selection"*/, FONT_Small, TEXTFLAG_Instant | TEXTFLAG_CentreX | TEXTFLAG_CentreY | TEXTFLAG_Pulse, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,
		
		{ 5, 126, 200, 133, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[3], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 133, 200, 140, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[2], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 140, 200, 147, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[1], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 147, 200, 154, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[0], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 155, 25, 162, 0, LT_MENU_NEW_Team10 /*"msg:"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, &TitlePlayerMessage, NULL ,SelectFlatMenutext , DrawFlatMenuText, NULL, 0 } ,

		{ 5, 163, 25, 170, 0, LT_MENU_NEW_CreateGame17/*"quit"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, NULL, NULL , SelectQuit, DrawFlatMenuItem, NULL, 0 } ,

		{ -1 , -1, 0, 0, 0, "" ,0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENUITEM	NewTeamItem = { 0, 0, 0, 0, 0, "GoingToDoTeamGame", 0, 0,	NULL,	&MENU_NEW_Team,	MenuChange,	NULL, NULL, 0 };

MENU	MENU_NEW_WatchTeamSelect = {
	"" , InitTeamSelection , BailMultiplayerFrontEnd , DistributeTeamsToLists, 0,
	{
		{ 0, 0, 200, 15, 0, LT_MENU_NEW_WatchTeamSelect0 /*"select teams"*/, FONT_Large, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,
		{ 0, 15, 200, 30, 0, "", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL, PlayerConfirm , DrawReadyButton, NULL, 0 } ,
		{ 5, 30, 50, 40, 0, LT_MENU_NEW_WatchTeamSelect1 /*"Red"*/,  FONT_Small,TEXTFLAG_ForceFit | TEXTFLAG_CentreX | TEXTFLAG_CentreY | TEXTFLAG_TeamItem, &TeamList[0], &Team1 , SelectTeamList, DrawFlatMenuItem, NULL, 0 } ,
		{ 53, 30, 98, 40, 0, LT_MENU_NEW_WatchTeamSelect2 /*"Green"*/,  FONT_Small,TEXTFLAG_ForceFit | TEXTFLAG_CentreX | TEXTFLAG_CentreY | TEXTFLAG_TeamItem, &TeamList[1], &Team2 , SelectTeamList, DrawFlatMenuItem, NULL, 0 } ,
		{ 101, 30, 146, 40, 0, LT_MENU_NEW_WatchTeamSelect3 /*"Blue"*/,  FONT_Small,TEXTFLAG_ForceFit | TEXTFLAG_CentreX | TEXTFLAG_CentreY | TEXTFLAG_TeamItem, &TeamList[2], &Team3 , SelectTeamList, DrawFlatMenuItem, NULL, 0 } ,
		{ 149, 30, 194, 40, 0, LT_MENU_NEW_WatchTeamSelect4 /*"Yellow"*/,  FONT_Small,TEXTFLAG_ForceFit | TEXTFLAG_CentreX | TEXTFLAG_CentreY | TEXTFLAG_TeamItem, &TeamList[3], &Team4 , SelectTeamList, DrawFlatMenuItem, NULL, 0 } ,
		{ 5, 45, 50, 126, 0, LT_MENU_NEW_WatchTeamSelect5 /*"Red"*/,  FONT_Small, TEXTFLAG_Unselectable | TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY | TEXTFLAG_Instant, &TeamList[0], NULL , SelectList, DrawFlatMenuList, NULL, 0 } ,
		{ 53, 45, 98, 126, 0, LT_MENU_NEW_WatchTeamSelect6 /*"Green"*/,  FONT_Small, TEXTFLAG_Unselectable | TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY | TEXTFLAG_Instant, &TeamList[1], NULL , SelectList, DrawFlatMenuList, NULL, 0 } ,
		{ 101, 45, 146, 126, 0, LT_MENU_NEW_WatchTeamSelect7 /*"Blue"*/,  FONT_Small, TEXTFLAG_Unselectable | TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY | TEXTFLAG_Instant, &TeamList[2], NULL , SelectList, DrawFlatMenuList, NULL, 0 } ,
		{ 149, 45, 194, 126, 0, LT_MENU_NEW_WatchTeamSelect8 /*"Yellow"*/,  FONT_Small, TEXTFLAG_Unselectable | TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY | TEXTFLAG_Instant, &TeamList[3], NULL , SelectList, DrawFlatMenuList, NULL, 0 } ,

		{ 0, 116, 200, 126, 0, LT_MENU_NEW_WatchTeamSelect9 /*"waiting for team selection"*/, FONT_Small, TEXTFLAG_Instant | TEXTFLAG_CentreX | TEXTFLAG_CentreY | TEXTFLAG_Pulse, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,
		
		{ 5, 126, 200, 133, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[3], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 133, 200, 140, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[2], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 140, 200, 147, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[1], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 147, 200, 154, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[0], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 155, 25, 162, 0, LT_MENU_NEW_WatchTeamSelect10 /*"msg:"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, &TitlePlayerMessage, NULL ,SelectFlatMenutext , DrawFlatMenuText, NULL, 0 } ,

		{ 5, 163, 25, 170, 0, LT_MENU_NEW_CreateGame17/*"quit"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, NULL, NULL , SelectQuit, DrawFlatMenuItem, NULL, 0 } ,

		{ -1 , -1, 0, 0, 0, "" ,0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU  MENU_NEW_ChooseTeamForExistingGame = {
	"" , InitExistingGameJoin , BailMultiplayerFrontEnd , DistributeTeamsToLists, 0,
	{
		{ 0, 0, 200, 15, 0, LT_MENU_NEW_ChooseTeamForExistingGame0 /*"select teams"*/, FONT_Large, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,
		{ 0, 15, 200, 30, 0, "", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL, PlayerConfirm , DrawReadyButton, NULL, 0 } ,
		{ 5, 30, 50, 40, 0, LT_MENU_NEW_ChooseTeamForExistingGame1 /*"Red"*/,  FONT_Small,TEXTFLAG_ForceFit | TEXTFLAG_CentreX | TEXTFLAG_CentreY | TEXTFLAG_TeamItem, &TeamList[0], &Team1 , SelectTeamList, DrawFlatMenuItem, NULL, 0 } ,
		{ 53, 30, 98, 40, 0, LT_MENU_NEW_ChooseTeamForExistingGame2 /*"Green"*/,  FONT_Small,TEXTFLAG_ForceFit | TEXTFLAG_CentreX | TEXTFLAG_CentreY | TEXTFLAG_TeamItem, &TeamList[1], &Team2 , SelectTeamList, DrawFlatMenuItem, NULL, 0 } ,
		{ 101, 30, 146, 40, 0, LT_MENU_NEW_ChooseTeamForExistingGame3 /*"Blue"*/,  FONT_Small,TEXTFLAG_ForceFit | TEXTFLAG_CentreX | TEXTFLAG_CentreY | TEXTFLAG_TeamItem, &TeamList[2], &Team3 , SelectTeamList, DrawFlatMenuItem, NULL, 0 } ,
		{ 149, 30, 194, 40, 0, LT_MENU_NEW_ChooseTeamForExistingGame4 /*"Yellow"*/,  FONT_Small,TEXTFLAG_ForceFit | TEXTFLAG_CentreX | TEXTFLAG_CentreY | TEXTFLAG_TeamItem, &TeamList[3], &Team4 , SelectTeamList, DrawFlatMenuItem, NULL, 0 } ,
		{ 5, 45, 50, 126, 0, LT_MENU_NEW_ChooseTeamForExistingGame5 /*"Red"*/,  FONT_Small, TEXTFLAG_Unselectable | TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY | TEXTFLAG_Instant, &TeamList[0], NULL , SelectList, DrawFlatMenuList, NULL, 0 } ,
		{ 53, 45, 98, 126, 0, LT_MENU_NEW_ChooseTeamForExistingGame6 /*"Green"*/,  FONT_Small, TEXTFLAG_Unselectable | TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY | TEXTFLAG_Instant, &TeamList[1], NULL , SelectList, DrawFlatMenuList, NULL, 0 } ,
		{ 101, 45, 146, 126, 0, LT_MENU_NEW_ChooseTeamForExistingGame7 /*"Blue"*/,  FONT_Small, TEXTFLAG_Unselectable | TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY | TEXTFLAG_Instant, &TeamList[2], NULL , SelectList, DrawFlatMenuList, NULL, 0 } ,
		{ 149, 45, 194, 126, 0, LT_MENU_NEW_ChooseTeamForExistingGame8 /*"Yellow"*/,  FONT_Small, TEXTFLAG_Unselectable | TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY | TEXTFLAG_Instant, &TeamList[3], NULL , SelectList, DrawFlatMenuList, NULL, 0 } ,
#if 0
		{ 5, 118, 50, 125, 0, "", FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TeamCurrentScore[0], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 53, 118, 98, 125, 0, "", FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TeamCurrentScore[1], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 101, 118, 146, 125, 0, "", FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TeamCurrentScore[2], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 149, 118, 194, 125, 0, "", FONT_Small, TEXTFLAG_CheckForRefresh | TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TeamCurrentScore[3], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
#endif

		{ 5, 126, 200, 133, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[3], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 133, 200, 140, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[2], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 140, 200, 147, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[1], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,
		{ 5, 147, 200, 154, 0, "", FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, (void *)TitleMessage[0], NULL , NULL , DrawFlatMenuName, NULL, 0 } ,

		{ 5, 155, 25, 162, 0, LT_MENU_NEW_ChooseTeamForExistingGame9 /*"msg:"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, &TitlePlayerMessage, NULL ,SelectFlatMenutext , DrawFlatMenuText, NULL, 0 } ,

		{ 5, 163, 25, 170, 0, LT_MENU_NEW_CreateGame17/*"quit"*/, FONT_Small, TEXTFLAG_ForceFit | TEXTFLAG_CentreY, NULL, NULL , SelectQuit, DrawFlatMenuItem, NULL, 0 } ,

		{ -1 , -1, 0, 0, 0, "" ,0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};


MENUITEM	TeamItem = { 0, 0, 0, 0, 0, "GoingToDoTeamGame", 0, 0,	NULL,	&MENU_Team,	MenuChange,		MenuItemDrawName, NULL, 0 };

MENU	MENU_HostWaitingToStart = {
	"Hosting a session" , NULL , BailMultiplayer , NULL, 0,
	{
		{ 200, 112, 0, 0, 0, "Start", 0, 0, NULL, &MENU_NotYet, GoToSynchup , MenuItemDrawName, NULL, 0 } ,
		{ 200, 128, 0, 0, 0, "Num of Players ", 0, 0, &NumOfPlayersSlider, NULL, NULL, DrawSlider, NULL, 0 },
		{ 200, 128, 0, 0, 0, "", 0, 0, &PlayersList, NULL , NULL , GetPlayersInCurrentSession, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_JoinWaitingToStart = {
	"Waiting for Host" , NULL , BailMultiplayer , NULL, 0,
	{
		{ 200, 128, 0, 0, 0, "Num of Players ", 0, 0, &NumOfPlayersSlider, NULL, NULL, DrawSlider, NULL, 0 },
		{ 200, 128, 0, 0, 0, "", 0, 0, &PlayersList, NULL , NULL , GetPlayersInCurrentSession, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL, NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_Host = {
	"Hosting a MultiPlayer Game" , InitMultiplayerHost , NULL , NULL, 0,
	{
		{ 200, 112, 0, 0, 0, "Start", 0, 0, NULL, &MENU_HostWaitingToStart, StartAHostSession , MenuItemDrawName, NULL, 0 } ,
		{ 200, 128, 0, 0, 0, "Team Game", 0, 0, &TeamGame, NULL, SelectToggle, DrawToggle, NULL, 0 },
		{ 200, 144, 0, 0, 0, "Record Demo", 0, 0, &RecordDemo, NULL, SelectToggle, DrawToggle, NULL, 0 },
		{ 200, 160, 0, 0, 0, "Demo Name  ", 0, 0, &DemoGameName, NULL,  SelectText, DrawTextItem, NULL, 0 } ,
		{ 200, 176, 0, 0, 0, "Time Limit ", 0, 0, &TimeLimit, NULL, SelectSlider, DrawSlider, NULL, 0 },
		{ 200, 192, 0, 0, 0, "Max Players ", 0, 0, &MaxPlayersSlider, NULL, SelectSlider, DrawSlider, NULL, 0 },
		{ 200, 208, 0, 0, 0, "Session Name  ", 0, 0, &MultiPlayerGameName, NULL,  SelectText, DrawTextItem, NULL, 0 } ,
		{ 200, 224, 0, 0, 0, "Level...", 0, 0, &LevelList, NULL , SelectList , DrawList, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_LevelSelect = {
	LT_MENU_LevelSelect0 /*"Level Selection"*/ , InitInGameLevelSelect , ExitLevelSelect , NULL, 0,
	{
		{ 200, 112, 0, 0, 0, LT_MENU_LevelSelect1 /*"Ability To Change "*/, 0, 0, &IsHost, NULL, NULL, DrawToggle, NULL, 0 },
		{ 200, 128, 0, 0, 0, LT_MENU_LevelSelect2 /*"Level..."*/, 0, 0, &LevelList, NULL , SelectList , DrawList, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};


MENUITEM	JoinItem = { 0, 0, 0, 0, 0, "GoingToJoinASession", 0, 0,	NULL,	&MENU_JoinWaitingToStart,	MenuChange,		MenuItemDrawName, NULL, 0 };
MENUITEM	NewJoinItem = { 0, 0, 0, 0, 0, "GoingToJoinASession", 0, 0,	NULL,	&MENU_NEW_JoinWaitingToStart,	MenuChange,		DrawFlatMenuItem, NULL, 0 };
MENUITEM	WatchTeamSelectionItem = { 0, 0, 0, 0, 0, "GoingToJoinASession", 0, 0,	NULL,	&MENU_NEW_Team,	MenuChange,		DrawFlatMenuItem, NULL, 0 };

						
MENU	MENU_ChooseSessionToJoin = {
	"Joining a MultiPlayer Game" , GetCurrentSessions , NULL , NULL, 0,
	{
//		{ 200, 112, 0, 0, 0, "Join", 0, 0, NULL, &MENU_JoinWaitingToStart, JoinASession , MenuItemDrawName } ,
//		{ 200, 128, 0, 0, 0, "Re Scan", 0, 0,	NULL,	NULL, GetCurrentSessions_ReScan, MenuItemDrawName },
		{ 200, 112, 0, 0, 0, "Choose From...", 0, 0, &SessionsList, NULL , SelectList , DrawList, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_HostOrJoin = {
	"MultiPlayer" , NULL , ChangeServiceProvider , NULL, 0,
	{
		{ 200, 112, 0, 0, 0, "Start a Game", 0, 0,	NULL,	&MENU_Host,	MenuChange,		MenuItemDrawName, NULL, 0 },
		{ 200, 128, 0, 0, 0, "Join a Network Game", 0, 0,	NULL,	&MENU_ChooseSessionToJoin,	MenuChange,		MenuItemDrawName, NULL, 0 },
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_MultiPlayer = {
	"Choose Provider" , GetServiceProviders , NULL , NULL, 0,
	{
		{ 200, 112, 0, 0, 0, "Next", 0, 0,	NULL,	&MENU_HostOrJoin,	ExitProviderChosen,		MenuItemDrawName, NULL, 0 },
		{ 200, 128, 0, 0, 0, "Choose From...", 0, 0, &ServiceProvidersList, NULL , SelectList , DrawList, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_LoadGame;
MENU	MENU_SaveGame = {
	LT_MENU_SaveGame0 /*"Save Game"*/, InitLoadSavedGameList, NULL, NULL, 0,
	{
		{ 100 , 128, 0, 0, 0, LT_MENU_SaveGame1 /*"Choose From..."*/, 0, 0, &LoadSavedGameList, InGameSaveASinglePlayerGame, SelectList , DrawList, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_Joystick;

MENU	MENU_WeaponPriority =
{
	"Weapon Priority", NULL, NULL, NULL, 0,
	{
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_WeaponKeys =
{
	"Weapon Selection", NULL, NULL, NULL, 0,
	{
		KEYDEF( 32, 112,"Pulsar", (void *)&Config.select_primary[ PULSAR ] ),

		KEYDEF( 32, 128,"Trojax", (void *)&Config.select_primary[ TROJAX ] ),

		KEYDEF( 32, 144,"Suss Gun", (void *)&Config.select_primary[ SUSS_GUN ] ),
#ifndef SHAREWARE
		KEYDEF( 32, 160,"Transpulse", (void *)&Config.select_primary[ TRANSPULSE_CANNON ] ),
	  
		KEYDEF( 32, 176,"Pyrolite", (void *)&Config.select_primary[ PYROLITE_RIFLE ] ),
		
		KEYDEF( 32, 192,"Beam Laser", (void *)&Config.select_primary[ LASER ] ),

#endif
		
		KEYDEF( 32, 224,"Next Prim", (void *)&Config.select_next_primary ),

		KEYDEF( 32, 240,"Prev Prim", (void *)&Config.select_prev_primary ),

		
		KEYDEF( 32, 272,"Next Sec", (void *)&Config.select_next_secondary ),

		KEYDEF( 32, 288,"Prev Sec", (void *)&Config.select_prev_secondary ),

		
		KEYDEF( 352, 112, "Mug Missile", (void *)&Config.select_secondary[ MUGMISSILE ] ),

		KEYDEF( 352, 128,"Solaris", (void *)&Config.select_secondary[ SOLARISMISSILE ] ),

#ifndef SHAREWARE
		KEYDEF( 352, 160, "Scatter", (void *)&Config.select_secondary[ SCATTERMISSILE ] ),
#endif
		KEYDEF( 352, 176, "Gravgon", (void *)&Config.select_secondary[ GRAVGONMISSILE ] ),

		KEYDEF( 352, 192, "MFRL", (void *)&Config.select_secondary[ MULTIPLEMISSILE ] ),

		KEYDEF( 352, 208, "Titan Star", (void *)&Config.select_secondary[ TITANSTARMISSILE ] ),


		KEYDEF( 352, 240, "Purge Mine", (void *)&Config.select_secondary[ PURGEMINE ] ),
#ifndef SHAREWARE
		KEYDEF( 352, 256, "Pine Mine", (void *)&Config.select_secondary[ PINEMINE ] ),

		KEYDEF( 352, 272, "Quantum Mine", (void *)&Config.select_secondary[ QUANTUMMINE ] ),
#endif


		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

#if 1
MENU	MENU_Keyboard =
{
	LT_MENU_Keyboard0 /*"Configure controls"*/, InitKeyDefPage, NULL, NULL, 0,
	{
		KDEF( 0, 200, 112, LT_MENU_Keyboard1 /*"Rotate Left"*/, KDleft ),

		KDEF( 0, 200, 128, LT_MENU_Keyboard2 /*"Rotate Right"*/, KDright ),

		KDEF( 0, 200, 144, LT_MENU_Keyboard3 /*"Rotate Up"*/, KDup ),
			      
		KDEF( 0, 200, 160, LT_MENU_Keyboard4 /*"Rotate Down"*/, KDdown ),

			      
		KDEF( 0, 200, 184, LT_MENU_Keyboard5 /*"Slide Left"*/, KDmove_left ),
			         
		KDEF( 0, 200, 200, LT_MENU_Keyboard6 /*"Slide Right"*/, KDmove_right ),
			   
		KDEF( 0, 200, 216, LT_MENU_Keyboard7 /*"Slide Up"*/, KDmove_up ),
			         
		KDEF( 0, 200, 232, LT_MENU_Keyboard8 /*"Slide Down"*/, KDmove_down ),

			   
		KDEF( 0, 200, 256, LT_MENU_Keyboard9 /*"Roll Left"*/, KDroll_left ),
			      
		KDEF( 0, 200, 272, LT_MENU_Keyboard10 /*"Roll Right"*/, KDroll_right ),


		KDEF( 0, 200, 296, LT_MENU_Keyboard11 /*"Slide Mode"*/, KDmove ),

		KDEF( 0, 200, 312, LT_MENU_Keyboard12 /*"Roll Mode"*/, KDroll ),

		// 2nd page

		KDEF( 1, 200, 112, LT_MENU_Keyboard13 /*"Forward"*/, KDmove_forward ),

		KDEF( 1, 200, 128, LT_MENU_Keyboard14 /*"Reverse"*/, KDmove_backward ),
		
		KDEF( 1, 200, 144, LT_MENU_Keyboard15 /*"Nitro"*/, KDturbo ),


		KDEF( 1, 200, 168, LT_MENU_Keyboard16 /*"Speed Up"*/, KDcruise_faster ),

		KDEF( 1, 200, 184, LT_MENU_Keyboard17 /*"Slow Down"*/, KDcruise_slower ),


		KDEF( 1, 200, 208, LT_MENU_Keyboard18 /*"Fire Prim"*/, KDfire_primary ),

		KDEF( 1, 200, 224, LT_MENU_Keyboard19 /*"Fire Sec"*/, KDfire_secondary ),
		
		KDEF( 1, 200, 240, LT_MENU_Keyboard20 /*"Drop Mine"*/, KDfire_mine ),

#ifndef SHAREWARE
		KDEF( 1, 200, 264, LT_MENU_Keyboard21 /*"Drop Prim"*/, KDdrop_primary ),

		KDEF( 1, 200, 280, LT_MENU_Keyboard22 /*"Drop Sec"*/, KDdrop_secondary ),
#endif

		KDEF( 1, 200, 296, LT_MENU_Keyboard23 /*"Drop Shield"*/, KDdrop_shield ),

		KDEF( 1, 200, 312, LT_MENU_Keyboard24 /*"Drop Ammo"*/, KDdrop_ammo ),

		// 3rd page

		KDEF( 2, 200, 112,LT_MENU_Keyboard25 /*"Pulsar"*/, KDselect_primary[ PULSAR ] ),

		KDEF( 2, 200, 128,LT_MENU_Keyboard26 /*"Trojax"*/, KDselect_primary[ TROJAX ] ),
#ifndef SHAREWARE
		KDEF( 2, 200, 144,LT_MENU_Keyboard27 /*"Pyrolite"*/, KDselect_primary[ PYROLITE_RIFLE ] ),

		KDEF( 2, 200, 160,LT_MENU_Keyboard28 /*"Transpulse"*/, KDselect_primary[ TRANSPULSE_CANNON ] ),
#endif
		KDEF( 2, 200, 176,LT_MENU_Keyboard29 /*"Suss Gun"*/, KDselect_primary[ SUSS_GUN ] ),
#ifndef SHAREWARE
		KDEF( 2, 200, 192,LT_MENU_Keyboard30 /*"Beam Laser"*/, KDselect_primary[ LASER ] ),
#endif

		KDEF( 2, 200, 216,LT_MENU_Keyboard31 /*"Next Prim"*/, KDselect_next_primary ),

		KDEF( 2, 200, 232,LT_MENU_Keyboard32 /*"Prev Prim"*/, KDselect_prev_primary ),

		
		KDEF( 2, 200, 256,LT_MENU_Keyboard33 /*"Next Sec"*/, KDselect_next_secondary ),

		KDEF( 2, 200, 272,LT_MENU_Keyboard34 /*"Prev Sec"*/, KDselect_prev_secondary ),


		KDEF( 2, 200, 296,LT_MENU_Keyboard35 /*"Send Msg"*/, KDsend_msg),
#ifdef PLAYER_SPEECH_TAUNTS
		KDEF( 2, 200, 312,LT_MENU_Keyboard36 /*"speech taunt"*/, KDsend_speech),
#endif
		KDEF( 2, 200, 312,LT_MENU_Keyboard1a /*"headlights"*/, KDheadlights),
		
		KDEF( 2, 200, 328,LT_MENU_Keyboard1b /*"full rear view"*/, KDfull_rearview),

		// 4th page
		
		KDEF( 3, 200, 112, LT_MENU_Keyboard37 /*"Mug Missile"*/, KDselect_secondary[ MUGMISSILE ] ),

		KDEF( 3, 200, 128,LT_MENU_Keyboard38 /*"Solaris"*/, KDselect_secondary[ SOLARISMISSILE ] ),

#ifndef SHAREWARE
		KDEF( 3, 200, 144, LT_MENU_Keyboard39 /*"Scatter"*/, KDselect_secondary[ SCATTERMISSILE ] ),
#endif
		KDEF( 3, 200, 160, LT_MENU_Keyboard40 /*"Gravgon"*/, KDselect_secondary[ GRAVGONMISSILE ] ),

		KDEF( 3, 200, 176, LT_MENU_Keyboard41 /*"MFRL"*/, KDselect_secondary[ MULTIPLEMISSILE ] ),

		KDEF( 3, 200, 192, LT_MENU_Keyboard42 /*"Titan Star"*/, KDselect_secondary[ TITANSTARMISSILE ] ),


		KDEF( 3, 200, 216, LT_MENU_Keyboard43 /*"Purge Mine"*/, KDselect_secondary[ PURGEMINE ] ),
#ifndef SHAREWARE
		KDEF( 3, 200, 232, LT_MENU_Keyboard44 /*"Pine Mine"*/, KDselect_secondary[ PINEMINE ] ),

		KDEF( 3, 200, 248, LT_MENU_Keyboard45 /*"Quantum Mine"*/, KDselect_secondary[ QUANTUMMINE ] ),
#endif

		{ 200, 32, 0, 0, 0, "help3", 0, 0, NULL, NULL, NULL, DrawKeyDefHelp3, NULL, 0 },
		{ 200, 336, 0, 0, 0, "help1", 0, 0, NULL, NULL, NULL, DrawKeyDefHelp1, NULL, 0 },
		{ 200, 352, 0, 0, 0, "help2", 0, 0, NULL, NULL, NULL, DrawKeyDefHelp2, NULL, 0 },
		{ 200, 368, 0, 0, 0, "Page", 0, 0, NULL, NULL, NULL, DrawKeyDefPage, NULL, 0 },
//		{ 200, 368, 0, 0, 0,  "Weapon selection keys", 0, 0, NULL, &MENU_WeaponKeys, MenuChange, MenuItemDrawName, NULL, 0 },

		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};
#else
MENU	MENU_Keyboard =
{
	"Keyboard", NULL, NULL, NULL, 0,
	{
		KEYDEF( 32, 112, "Rotate Left", (void *)&Config.left ),

		KEYDEF( 32, 128, "Rotate Right", (void *)&Config.right ),

		KEYDEF( 32, 144, "Rotate Up", (void *)&Config.up ),
			      
		KEYDEF( 32, 160, "Rotate Down", (void *)&Config.down ),

			      
		KEYDEF( 32, 192, "Slide Left", (void *)&Config.move_left ),
			         
		KEYDEF( 32, 208, "Slide Right", (void *)&Config.move_right ),
			   
		KEYDEF( 32, 224, "Slide Up", (void *)&Config.move_up ),
			         
		KEYDEF( 32, 240, "Slide Down", (void *)&Config.move_down ),

			   
		KEYDEF( 32, 272, "Roll Left", (void *)&Config.roll_left ),
			      
		KEYDEF( 32, 288, "Roll Right", (void *)&Config.roll_right ),


		KEYDEF( 32, 320, "Slide Mode", (void *)&Config.move ),

		KEYDEF( 32, 336, "Roll Mode", (void *)&Config.roll ),

		// right column

		KEYDEF( 352, 112, "Forward", (void *)&Config.move_forward ),

		KEYDEF( 352, 128, "Reverse", (void *)&Config.move_backward ),
		
		KEYDEF( 352, 144, "Nitro", (void *)&Config.turbo ),


		KEYDEF( 352, 176, "Speed Up", (void *)&Config.cruise_faster ),

		KEYDEF( 352, 192, "Slow Down", (void *)&Config.cruise_slower ),


		KEYDEF( 352, 224, "Fire Prim", (void *)&Config.fire_primary ),

		KEYDEF( 352, 240, "Fire Sec", (void *)&Config.fire_secondary ),
		
		KEYDEF( 352, 256, "Drop Mine", (void *)&Config.fire_mine ),

#ifndef SHAREWARE
		KEYDEF( 352, 288, "Drop Prim", (void *)&Config.drop_primary ),

		KEYDEF( 352, 304, "Drop Sec", (void *)&Config.drop_secondary ),
#endif

		KEYDEF( 352, 320, "Drop Shield", (void *)&Config.drop_shield ),

		KEYDEF( 352, 336, "Drop Ammo", (void *)&Config.drop_ammo ),


		{ 200, 368, 0, 0, 0,  "Weapon selection keys", 0, 0, NULL, &MENU_WeaponKeys, MenuChange, MenuItemDrawName, NULL, 0 },

		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};
#endif

MENU	MENU_Feedback_Advanced = {
	LT_MENU_Feedback_Advanced0 /*"Advanced Feedback"*/, NULL, NULL, NULL, 0,
	{
		OLDMENUITEM(  200 , 128+0*16,	LT_MENU_Feedback_Advanced1 /*"Primary Feedback   "*/,	&FeedbackEffectEnable[ FF_EFFECT_PrimaryRecoil ], NULL, SelectToggle , DrawToggle),
		OLDMENUITEM(  200 , 128+1*16,	LT_MENU_Feedback_Advanced2 /*"Primary Strength   "*/,	(void*)&FeedbackEffectGainSlider[ FF_EFFECT_PrimaryRecoil ], NULL, SelectSlider, DrawSlider),
		OLDMENUITEM(  200 , 128+2*16,	LT_MENU_Feedback_Advanced3 /*"Secondary Feedback "*/,	&FeedbackEffectEnable[ FF_EFFECT_SecondaryRecoil ], NULL, SelectToggle , DrawToggle),
		OLDMENUITEM(  200 , 128+3*16,	LT_MENU_Feedback_Advanced4 /*"Secondary Strength "*/,	(void*)&FeedbackEffectGainSlider[ FF_EFFECT_SecondaryRecoil ], NULL, SelectSlider, DrawSlider),
		OLDMENUITEM(  200 , 128+4*16,	LT_MENU_Feedback_Advanced5 /*"Impact Feedback    "*/,	&FeedbackEffectEnable[ FF_EFFECT_Jolt ], NULL, SelectToggle , DrawToggle),
		OLDMENUITEM(  200 , 128+5*16,	LT_MENU_Feedback_Advanced6 /*"Impact Strength    "*/,	(void*)&FeedbackEffectGainSlider[ FF_EFFECT_Jolt ], NULL, SelectSlider, DrawSlider),
		OLDMENUITEM(  200 , 128+6*16,	LT_MENU_Feedback_Advanced7 /*"Engine Feedback    "*/,	&FeedbackEffectEnable[ FF_EFFECT_Engine ], NULL, SelectToggle , DrawToggle),
		OLDMENUITEM(  200 , 128+7*16,	LT_MENU_Feedback_Advanced8 /*"Engine Strength    "*/,	(void*)&FeedbackEffectGainSlider[ FF_EFFECT_Engine ], NULL, SelectSlider, DrawSlider),
		OLDMENUITEM(  200 , 128+8*16,	LT_MENU_Feedback_Advanced9 /*"Damper Feedback    "*/,	&FeedbackEffectEnable[ FF_EFFECT_Damper ], NULL, SelectToggle , DrawToggle),
		OLDMENUITEM(  200 , 128+9*16,	LT_MENU_Feedback_Advanced10 /*"Damper Strength    "*/,	(void*)&FeedbackEffectGainSlider[ FF_EFFECT_Damper ], NULL, SelectSlider, DrawSlider),
		OLDMENUITEM(  200 , 128+10*16,	LT_MENU_Feedback_Advanced11 /*"Inertia Feedback   "*/,	&FeedbackEffectEnable[ FF_EFFECT_Inertia ], NULL, SelectToggle , DrawToggle),
		OLDMENUITEM(  200 , 128+11*16,	LT_MENU_Feedback_Advanced12 /*"Inertia Strength   "*/,	(void*)&FeedbackEffectGainSlider[ FF_EFFECT_Inertia ], NULL, SelectSlider, DrawSlider),
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_Feedback = {
	LT_MENU_Feedback0 /*"Force Feedback"*/, InitFeedbackMenu, ExitFeedbackMenu, NULL, 0,
	{
		OLDMENUITEM(  200 , 128+0*16,	LT_MENU_Feedback1 /*"Force Feedback     "*/,	&FeedbackEnable, NULL, SelectToggle , DrawToggle),
		OLDMENUITEM(  200 , 128+1*16,	LT_MENU_Feedback2 /*"Feedback Strength  "*/,	(void*)&FeedbackGainSlider, NULL, SelectSlider, DrawSlider),
#ifdef FEEDBACK_XYSLIDER
		OLDMENUITEM(  200 , 128+2*16,	LT_MENU_Feedback3 /*"X axis             "*/,	(void*)&FeedbackXSlider, NULL, SelectSlider, DrawSlider),
		OLDMENUITEM(  200 , 128+3*16,	LT_MENU_Feedback4 /*"Y axis             "*/,	(void*)&FeedbackYSlider, NULL, SelectSlider, DrawSlider),
#else
		OLDMENUITEM(  200 , 128+2*16,	LT_MENU_Feedback5 /*"X axis "*/,	&FeedbackXEnable, NULL, SelectToggle, DrawToggle),
		OLDMENUITEM(  350 , 128+2*16,	LT_MENU_Feedback6 /*"invert "*/,	&FeedbackXInvert, NULL, SelectToggle, DrawToggle),
		OLDMENUITEM(  200 , 128+3*16,	LT_MENU_Feedback7 /*"Y axis "*/,	&FeedbackYEnable, NULL, SelectToggle, DrawToggle),
		OLDMENUITEM(  350 , 128+3*16,	LT_MENU_Feedback8 /*"invert "*/,	&FeedbackYInvert, NULL, SelectToggle, DrawToggle),
#endif
		OLDMENUITEM(  200 , 128+4*16,	LT_MENU_Feedback9 /*"Advanced options..."*/, NULL, &MENU_Feedback_Advanced , MenuChange , MenuItemDrawName ),
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_Primary;
MENU	MENU_Secondary;
MENU	MENU_Controls = {
	LT_MENU_Controls0 /*"Bike Controls"*/, InitControls, ExitControls, NULL, 0,
	{
#if 0
		{ 200, 144 - 32, 0, 0, 0, "Mouse", 0, 0,				(void *)&ControlMethod,	(void *)CONTROL_Mouse,		SelectRadioButton,	DrawRadioButton, NULL, 0 },
		{ 200, 160 - 32, 0, 0, 0, "Keyboard", 0, 0,				(void *)&ControlMethod,	(void *)CONTROL_Keyboard,	SelectRadioButton,	DrawRadioButton, NULL, 0 },
		{ 200, 176 - 32, 0, 0, 0, "Joystick", 0, 0,				(void *)&ControlMethod,	(void *)CONTROL_Joystick,	SelectRadioButton,	DrawRadioButton, NULL, 0 },
		{ 200, 192 - 32, 0, 0, 0, "Gamepad", 0, 0,				(void *)&ControlMethod,	(void *)CONTROL_Gamepad,	SelectRadioButton,	DrawRadioButton, NULL, 0 },
		
		{ 200, 176 + 16, 0, 0, 0, "Invert X",  0, 0,			&Config.invert_turn,			NULL,				SelectToggle,		DrawToggle, NULL, 0 },
		{ 200, 192 + 16, 0, 0, 0, "Invert Y",  0, 0,			&Config.invert_pitch,			NULL,				SelectToggle,		DrawToggle, NULL, 0 },
				
		{ 200, 224, 0, 0, 0, "X Sensitivity  ", 0, 0,		&SensitivityXSlider,		NULL,						SelectSlider,		DrawSlider, NULL, 0 },
		{ 200, 240, 0, 0, 0, "Y Sensitivity  ", 0, 0,		&SensitivityYSlider,		NULL,						SelectSlider,		DrawSlider, NULL, 0 },
		{ 200, 272, 0, 0, 0, "Autoleveling",  0, 0,			&Autoleveling,			SetAutolevel,				SelectToggle,		DrawToggle, NULL, 0 },
		{ 200, 288, 0, 0, 0, "Calibrate Joystick", 0, 0,	NULL,					&MENU_NotYet,				MenuChange,			MenuItemDrawName, NULL, 0 },
		{ 200, 320, 0, 0, 0, "Configure Keyboard", 0, 0,	NULL,					&MENU_Keyboard,				MenuChange,			MenuItemDrawName, NULL, 0 },
		{ 200, 336, 0, 0, 0, "Weapon Priority", 0, 0,		NULL,					&MENU_NotYet,				MenuChange,			MenuItemDrawName, NULL, 0 },
		{ 200, 352, 0, 0, 0, "Reorder Secondary", 0, 0,	NULL,					&MENU_NotYet,				MenuChange,			MenuItemDrawName, NULL, 0 },
#else
		{ 200, 112, 0, 0, 0, LT_MENU_Controls1 /*"Configure controls"*/, 0, 0,	NULL,					&MENU_Keyboard,				MenuChange,			MenuItemDrawName, NULL, 0 },
		{ 200, 144, 0, 0, 0, LT_MENU_Controls2 /*"Mouse             "*/, 0, 0,	&MouseInput,			NULL,						SelectToggle,		DrawToggle, NULL, 0 },
		{ 200, 160, 0, 0, 0, LT_MENU_Controls3 /*"Joystick          "*/, 0, 0,	&JoystickInput,			NULL,						SelectToggle,		DrawToggle, NULL, 0 },
		{ 200, 192, 0, 0, 0, LT_MENU_Controls4 /*"Autoleveling      "*/,  0, 0,			&Autoleveling,			SetAutolevel,				SelectToggle,		DrawToggle, NULL, 0 },
		{ 200, 224, 0, 0, 0, LT_MENU_Controls5 /*"Invert X          "*/,  0, 0,			&Config.invert_turn,			NULL,				SelectToggle,		DrawToggle, NULL, 0 },
		{ 200, 240, 0, 0, 0, LT_MENU_Controls6 /*"Invert Y          "*/,  0, 0,			&Config.invert_pitch,			NULL,				SelectToggle,		DrawToggle, NULL, 0 },
		{ 200, 272, 0, 0, 0, LT_MENU_Controls7 /*"X Sensitivity     "*/, 0, 0,		&SensitivityXSlider,		NULL,						SelectSlider,		DrawSlider, NULL, 0 },
		{ 200, 288, 0, 0, 0, LT_MENU_Controls8 /*"Y Sensitivity     "*/, 0, 0,		&SensitivityYSlider,		NULL,						SelectSlider,		DrawSlider, NULL, 0 },
		{ 200, 320, 0, 0, 0, LT_MENU_Controls9 /*"Force Feedback..."*/, 0, 0,		NULL,					&MENU_Feedback,				MenuChange,			MenuItemDrawName, NULL, 0 },
#endif
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}																					
};
MENU	MENU_Sound;
MENU	MENU_Detail = {
	LT_MENU_Detail0 /*"Detail Levels"*/, InitDetailLevels, ExitDetailLevels, NULL, 0,
	{
		{ 200, 100, 0, 0, 0, LT_MENU_Detail1 /*"Bi Linear Filtering"*/, 0, 0,		&BiLinearFiltering,		SetOurRenderStates,	SelectToggle,	DrawToggle, NULL, 0 },
		{ 200, 116, 0, 0, 0, LT_MENU_Detail1a /*"Tri Linear Filtering"*/, 0, 0,		&TriLinear,				SetOurRenderStates,	SelectToggle,	DrawToggle, NULL, 0 },
		{ 200, 148, 0, 0, 0, LT_MENU_Detail2 /*"Perspective Correct"*/, 0, 0,		&PerspectiveCorrect,	SetOurRenderStates,	SelectToggle,	DrawToggle, NULL, 0 },
		{ 200, 164, 0, 0, 0, LT_MENU_Detail3 /*"Lens Flare         "*/, 0, 0,		&LensFlare,				NULL,	SelectToggle,	DrawToggle, NULL, 0 },
		{ 200, 180, 0, 0, 0, LT_MENU_Detail4 /*"Team Info          "*/, 0, 0,		&ShowTeamInfo,			NULL,	SelectToggle,	DrawToggle, NULL, 0 },
		{ 200, 196, 0, 0, 0, LT_MENU_Detail5 /*"Primary Lights     "*/, 0, 0,		&PrimaryLightDetail,	SetLightStates,	SelectToggle,	DrawToggle, NULL, 0 },
		{ 200, 212, 0, 0, 0, LT_MENU_Detail6 /*"Secondary Lights   "*/, 0, 0,		&SecondaryLightDetail,	SetLightStates,	SelectToggle,	DrawToggle, NULL, 0 },
		{ 200, 228, 0, 0, 0, LT_MENU_Detail7 /*"Pickup Lights      "*/, 0, 0,		&PickupLightDetail,		SetLightStates,	SelectToggle,	DrawToggle, NULL, 0 },
		{ 200, 244, 0, 0, 0, LT_MENU_Detail8 /*"Mono Lighting      "*/, 0, 0,		&SWMonoChrome,			NULL,	SelectToggle,	DrawToggle, NULL, 0 },
		{ 200, 260, 0, 0, 0, LT_MENU_Detail9 /*"Smoke Trail Detail "*/, 0, 0,		&TrailDetailSlider,		NULL,	SelectSlider,	DrawSlider, NULL, 0 },
		{ 200, 276, 0, 0, 0, LT_MENU_Detail10 /*"Auto Detail       "*/, 0, 0,		&AutoDetail,			NULL,	SelectToggle,	DrawToggle, NULL, 0 },
		{ 200, 292, 0, 0, 0, LT_MENU_Detail11 /*"Bike Detail       "*/, 0, 0,		&BikeDetailSlider,		NULL,	SelectSlider,	DrawSlider, NULL, 0 },
#ifdef Z_TRICK
		{ 200, 308, 0, 0, 0, LT_MENU_Detail15 /*"Z Clears          "*/, 0, 0,		&ZClearsOn,		SetZCompare,	SelectToggle,	DrawToggle, NULL, 0 },
#endif
		//{ 200, 292, 0, 0, 0, LT_MENU_Detail12 /*"Water Detail       "*/, 0, 0,		&WaterDetailSlider,		NULL,	SelectSlider,	DrawSlider, NULL, 0 },
		//{ 200, 308, 0, 0, 0, LT_MENU_Detail13 /*"gamma              "*/, 0, 0,		&GammaSlider,			NULL,	SelectSlider,	DrawSlider, NULL, 0 },
#ifndef NO_GORE
		{ 200, 324, 0, 0, 0, LT_MENU_Detail14 /*"mature content     "*/, 0, 0,		&GoreGuts,				NULL,	SelectToggle,	DrawToggle, NULL, 0 },
#endif
		{	-1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_DebugMode = {
	"Select Debug Mode" , InitDebugMode , NULL , NULL, 0,
	{
		
		{ 200, 96, 0, 0, 0, "Show Plane RGB", 0, 0, &ShowPlaneRGB, NULL, SelectToggle, DrawToggle, NULL, 0 },
	    { 200, 112, 0, 0, 0,"Textures Enabled", 0, 0,	&TexturesEnabled,	TexturesEnabledToggle, SelectToggle, DrawToggle, NULL, 0 },
		
		{ 200, 144, 0, 0, 0, "external forces", 0, 0, &ShowEFZones, NULL, SelectToggle, DrawToggle, NULL, 0 },
		{ 200, 160, 0, 0, 0, "teleports", 0, 0, &ShowTeleports, NULL, SelectToggle, DrawToggle, NULL, 0 },
		{ 200, 176, 0, 0, 0, "trigger zones", 0, 0, &ShowTrigZones, NULL, SelectToggle, DrawToggle, NULL, 0 },
		{ 200, 192, 0, 0, 0, "bounding boxes", 0, 0, &ShowBoundingBoxes, NULL, SelectToggle, DrawToggle, NULL, 0 },
		{ 200, 208, 0, 0, 0, "collision zones", 0, 0, &ShowColZones, NULL, SelectToggle, DrawToggle, NULL, 0 },
		{ 200, 224, 0, 0, 0, "Untriggered Enemies", 0, 0, &ShowUntriggeredNMEs, NULL, SelectToggle, DrawToggle, NULL, 0 },

		{ 200, 256, 0, 0, 0, "Screen Capture Mode ...on F8 key", 0, 0,		&ScreenSaving,		NULL,	SelectToggle,	DrawToggle, NULL, 0 },
		{ 200, 272, 0, 0, 0, "Old BSP Cube", 0, 0, &OldNodeCube, NULL, SelectToggle, DrawToggle, NULL, 0 },
		{ 200, 288, 0, 0, 0, "BSP Node Cube", 0, 0, &NodeCube, NULL, SelectToggle, DrawToggle, NULL, 0 },
		{ 200, 304, 0, 0, 0, "BSP Nodes tested", 0, 0, &NodeCubeType, NULL, SelectToggle, DrawToggle, NULL, 0 },
		
		{ 200, 336, 0, 0, 0, "Show Nodes", 0, 0, &ShowNode, ShowNodeToggle, SelectToggle, DrawToggle, NULL, 0 },
		{ 200, 352, 0, 0, 0, "Show Startpoints", 0, 0, &ShowStartPoints, ShowStartPointsToggle, SelectToggle, DrawToggle, NULL, 0 },

		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_SelectBike = {
#if defined ( SHAREWARE ) || defined ( WIN98SHAREWARE ) 
	"Select Bike" , InitShareWareBikeList , NULL , NULL,	0,
	{
		{ 200, 128, 0, 0, 0, "Choose From...", 0, 0, &ShareWareBikeList, ExitShareWareBikeSelection , SelectList , DrawList, NULL, 0 } ,
#else
	LT_MENU_SelectBike0 /*"Select Bike"*/ , InitBikeList , NULL , NULL,	0,
	{
		{ 200, 128, 0, 0, 0, LT_MENU_SelectBike1 /*"Choose From..."*/, 0, 0, &BikeList, ExitBikeSelection , SelectList , DrawList, NULL, 0 } ,
#endif
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_SelectBikeComputer = {
	LT_MENU_SelectBikeComputer0 /*"Select Bike Computer"*/ , InitBikeComputerMenu , NULL , NULL,	0,
	{
		{ 200, 128, 0, 0, 0, LT_MENU_SelectBikeComputer1 /*"Choose From..."*/, 0, 0, &BikeComputerList, ExitBikeComputerSelection , SelectList , DrawList, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};
/*
MENU	MENU_NEW_ChoosePlayer = {
	"", InitVDUPilotMenu, KillBikeChar, NULL, 0,
	{
		{ 0, 0, 200, 20, 0, "Choose Player...", FONT_Large, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,
		{ 125 , 130, 200, 150, 0, "" , FONT_Small, TEXTFLAG_CentreX | TEXTFLAG_CentreY , &bike_name, NULL , NULL , DrawFlatBikeName, NULL, 0},
		{ 15 , 30, 100, 150, 0, "list..." , FONT_Small, TEXTFLAG_SuppressHighlight | TEXTFLAG_ForceFit | TEXTFLAG_CentreY , &PilotList, NULL , NULL , DrawFlatMenuList, NULL, 0},

		{ 125 , 20, 200, 130, 0, "" , FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY , NULL, NULL , NULL , LoadBikeChar, NULL, 0},
			
		{ -1, -1, 0, 0, 0,"", 0, 0, NULL, NULL, NULL, NULL, NULL, 0 }

	}
};
*/

MENU	MENU_NEW_ChangeBikeComputer = {
	LT_MENU_NEW_ChangeBikeComputer0 /*"Select Bike Computer"*/ , InitBikeComputerMenu , NULL , NULL,	0,
	{
		{ 0, 0, 200, 20, 0, LT_MENU_NEW_ChangeBikeComputer1 /*"Choose bike computer..."*/, FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY, NULL, NULL , NULL , DrawFlatMenuItem, NULL, 0 } ,
		{ 15 , 30, 100, 150, 0, LT_MENU_NEW_ChangeBikeComputer2 /*"list..."*/ , FONT_Small, TEXTFLAG_SuppressHighlight | TEXTFLAG_AutoSelect | TEXTFLAG_ForceFit | TEXTFLAG_CentreY , &BikeComputerList, ExitBikeComputerSelection , SelectList , DrawFlatMenuList, NULL, 0},

		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};


MENU	MENU_Bike;
MENU	MENU_Computer;
MENU	MENU_Restore;

MENU	MENU_SelectScreenMode = {
	LT_MENU_SelectScreenMode0 /*"Select Screen Mode"*/ , MakeModeList , MenuSelectMode , NULL, 0,
	{
		{ 200, 128, 0, 0, 0, LT_MENU_SelectScreenMode1 /*"Choose From..."*/, 0, 0, &ModeList, NULL , SelectList , DrawList, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};
MENU	MENU_SelectTextureFormat = {
	LT_MENU_SelectTextureFormat0 /*"Select Texture Format"*/ , MakeTextureList , MenuTextureMode , NULL, 0,
	{
		{ 200, 128, 0, 0, 0, LT_MENU_SelectTextureFormat1 /*"Choose From..."*/, 0, 0, &TextureList, NULL , SelectList , DrawList, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};


MENU	MENU_Visuals = {
	LT_MENU_Visuals0 /*"Visuals"*/, NULL, NULL, NULL, 0,
	{
		{ 200, 128 + ( 0*16 ), 0, 0, 0, LT_MENU_Visuals1 /*"Select Screen Mode"*/, 0, 0, NULL, &MENU_SelectScreenMode, MenuChange, MenuItemDrawName, NULL, 0 },
		{ 200, 128 + ( 1*16 ), 0, 0, 0, LT_MENU_Visuals2 /*"Select Texture Format"*/, 0, 0, NULL, &MENU_SelectTextureFormat, MenuChange, MenuItemDrawName, NULL, 0 },
#ifndef SOFTWARE_ENABLE
		OLDMENUITEM(  200 , 128+2*16,LT_MENU_Visuals3 /*"Toggle Full Screen"*/, NULL, NULL , MenuGoFullScreen , MenuItemDrawName),
#endif
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

BOOL ThrottleReset = TRUE;
extern void ResetThrottle( MENUITEM *item );
void StoreThrottleSettings( MENUITEM *item );

MENU	MENU_Options = {
	LT_MENU_Options0/*"Options"*/, InitInGameOptions, NULL, NULL, 0,
	{
		{ 200, 128 + ( 0*16 ), 0, 0, 0, LT_MENU_Options1/*"Visuals"*/, 0, 0, NULL, &MENU_Visuals, MenuChange, MenuItemDrawName, NULL, 0 },
		{ 200, 128 + ( 1*16 ), 0, 0, 0, LT_MENU_Options2/*"Sound FX and Music"*/, 0, 0, NULL, &MENU_NEW_InGameSound, MenuChange, MenuItemDrawName, NULL, 0 },
		{ 200, 128 + ( 2*16 ), 0, 0, 0, LT_MENU_Options3/*"Detail Levels"*/, 0, 0, NULL, &MENU_Detail, MenuChange, MenuItemDrawName, NULL, 0 },
		{ 200 ,128 + ( 3*16 ), 0, 0, 0, LT_MENU_Options4/*"Show Frame Rate "*/, 0, 0, &myglobs.bShowFrameRate, NULL, SelectToggle, DrawToggle, NULL, 0 },
		OLDMENUITEM(  200 , 128+4*16,LT_MENU_Options5/*"Packets Per Second "*/,(void*)&PacketsSlider, NULL, SelectSlider, DrawSlider),
		OLDMENUITEM(  200 , 128+5*16,LT_MENU_Options6/*"show ping"*/, &ShowPing, NULL, SelectToggle , DrawToggle),
		OLDMENUITEM(  200 , 128+6*16,LT_MENU_Options7/*"update (secs)"*/, &PingFreqSlider, NULL, SelectSlider , DrawSlider),
#if !defined( SHAREWARE ) && !defined( PCIDENT )
#if !defined( EXTERNAL_DEMO ) || defined( ACCLAIM_NY_UK_IGUANA_UK_US ) || defined( ACCLAIM_NY )
		{ 200 ,128 + ( 7*16 ), 0, 0, 0, LT_MENU_Options8/*"Show Extra Info "*/, 0, 0, &myglobs.bShowInfo, NULL, SelectToggle, DrawToggle, NULL, 0 },
#endif
		{ 200 ,128 + ( 8*16 ), 0, 0, 0, LT_MENU_Options9/*"Show Weapon Kills"*/, 0, 0, &ShowWeaponKills, NULL, SelectToggle, DrawToggle, NULL, 0 },
		//{ 200, 128 + ( 9*16 ), 0, 0, 0, LT_MENU_Options10/*"Restore Defaults"*/, 0, 0, NULL, &MENU_NotYet, MenuChange, MenuItemDrawName, NULL, 0 },
#endif
		OLDMENUITEM(  200 , 128+9*16,"throttle",(void*)&ThrottleSlider, StoreThrottleSettings, SelectSlider, DrawSlider),
		//OLDMENUITEM(  200 , 128+10*16,"throttle",(void*)&ThrottleReset, ResetThrottle, SelectToggle, DrawToggle),

		{	-1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_SelfPlayOptions = {
	"Options"/*"Options"*/, NULL, NULL, NULL, 0,
	{
		{ 200, 128           , 0, 0, 0, "Select Screen Mode"/*"Select Screen Mode"*/, 0, 0, NULL, &MENU_SelectScreenMode, MenuChange, MenuItemDrawName, NULL, 0 },
		{ 200, 128 + ( 1*16 ), 0, 0, 0, "Select Texture Format"/*"Select Texture Format"*/, 0, 0, NULL, &MENU_SelectTextureFormat, MenuChange, MenuItemDrawName, NULL, 0 },
		{ 200, 128 + ( 2*16 ), 0, 0, 0, "Detail Levels"/*"Detail Levels"*/, 0, 0, NULL, &MENU_Detail, MenuChange, MenuItemDrawName, NULL, 0 },
		{ 200 ,128 + ( 3*16 ), 0, 0, 0, "Show Player Names "/*"Show Player Names "*/, 0, 0, &ShowNamesAnyway, NULL, SelectToggle, DrawToggle, NULL, 0 },
		{ 200 ,128 + ( 4*16 ), 0, 0, 0, "Show Frame Rate "/*"Show Frame Rate "*/, 0, 0, &myglobs.bShowFrameRate, NULL, SelectToggle, DrawToggle, NULL, 0 },
		{	-1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};


MENU	MENU_DemoPlaying = {
	LT_MENU_DemoPlaying0 /*"Demo Playing"*/ , NULL, NULL, NULL, 0,
	{
		{ 200 , 128           , 0, 0, 0, LT_MENU_DemoPlaying1 /*"Pause Demo "*/, 0, 0,	&PauseDemo,	NULL, PauseDemoToggle,	DrawToggle, NULL, 0 },
#if defined( SELF_PLAY ) || defined( EXTERNAL_DEMO )
		{ 200 , 128 + ( 1*16 ), 0, 0, 0, LT_MENU_DemoPlaying2 /*"Playback Speed"*/, 0, 0,	&DemoSpeed,		NULL,	SelectSlider,	DrawSlider, NULL, 0 },
		{ 10, 128 + ( 2*16 ), 100, 50, SLIDER_Value, "FSB Compensation", FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &FSBCompensation, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
		{ 200 , 128 + ( 3*16 ), 0, 0, 0, LT_MENU_DemoPlaying3 /*"Watch Player"*/, 0, 0,		&DemoEyesSelect,		NULL,	SelectSlider,	DrawSlider, NULL, 0 },
		{ 200 , 128 + ( 4*16 ), 0, 0, 0, LT_MENU_DemoPlaying4 /*"Options"*/ , 0, 0, NULL, &MENU_SelfPlayOptions , MenuChange , MenuItemDrawName, NULL, 0 } ,
		OLDMENUITEM( 200 , 128 + ( 5 * 16), LT_MENU_DemoPlaying5 /*"Quit to Main Menu"*/, NULL, NULL, SelectQuitCurrentGame , MenuItemDrawName ),
#else
		{ 200 , 128 + ( 1*16 ), 0, 0, 0, LT_MENU_DemoPlaying6 /*"Grab 3dfx demo "*/, 0, 0,	&DemoScreenGrab,	NULL, PauseDemoToggle,	DrawToggle, NULL, 0 },
		{ 200 , 128 + ( 2*16 ), 0, 0, 0, LT_MENU_DemoPlaying7 /*"Playback Speed"*/, 0, 0,	&DemoSpeed,		NULL,	SelectSlider,	DrawSlider, NULL, 0 },
		{ 10, 128 + ( 3*16 ), 100, 50, SLIDER_Value, "FSB Compensation", FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &FSBCompensation, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
		{ 200 , 128 + ( 4*16 ), 0, 0, 0, LT_MENU_DemoPlaying8 /*"Watch Player"*/, 0, 0,		&DemoEyesSelect,		NULL,	SelectSlider,	DrawSlider, NULL, 0 },
		{ 200 , 128 + ( 5*16 ), 0, 0, 0, LT_MENU_DemoPlaying9 /*"Options"*/ , 0, 0, NULL, &MENU_Options , MenuChange , MenuItemDrawName, NULL, 0 } ,
		{ 200 , 128 + ( 6*16 ), 0, 0, 0, LT_MENU_DemoPlaying10 /*"Debugging"*/, 0, 0,	&DebugInfo,	DebugModeChanged, SelectToggle,	DrawToggle, NULL, 0 },
		{ 200 , 128 + ( 7*16 ), 0, 0, 0, LT_MENU_DemoPlaying11 /*"Quit to Title Screen"*/ , 0, 0, NULL, NULL, SelectQuitCurrentGame , MenuItemDrawName, NULL, 0 } ,
//		{ 200 , 128 + ( 8*16 ), 0, 0, 0, LT_MENU_DemoPlaying12 /*"Server Mode"*/, 0, 0, &ServerMode, NULL, SelectToggle, DrawToggle, NULL, 0 },
#endif
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};



MENU	MENU_DemoPlayBack = {
	"Demo Playback"/*"Demo Playback"*/ , InitDemoList, NULL, NULL, 0,
	{
		{ 200 , 128, 0, 0, 0, "Start"/*"Start"*/ , 0, 0, NULL, &MENU_NotYet , StartDemoPlayback , MenuItemDrawName, NULL, 0 } ,
		{ 200 , 144, 0, 0, 0, "Playback Speed"/*"Playback Speed"*/, 0, 0,	&DemoSpeed,		NULL,	SelectSlider,	DrawSlider, NULL, 0 },
		{ 10,	160, 100, 50, SLIDER_Value, "FSB Compensation", FONT_Small, TEXTFLAG_AutoSelect | TEXTFLAG_CentreY, &FSBCompensation, NULL, SelectSlider, DrawFlatMenuSlider, NULL, 0 } ,
		{ 200 , 176, 0, 0, 0, "Watch Player"/*"Watch Player"*/, 0, 0,		&DemoEyesSelect,		NULL,	SelectSlider,	DrawSlider, NULL, 0 },
		{ 200 , 192, 0, 0, 0, "Choose From..."/*"Choose From..."*/, 0, 0, &DemoList, NULL , SelectList , DrawList, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_DemoCleaning = {
	LT_MENU_DemoCleaning0 /*"Clean A Demo"*/ , InitDemoList, NULL, NULL, 0,
	{
		{ 200 , 128, 0, 0, 0, LT_MENU_DemoCleaning1 /*"Start"*/ , 0, 0, NULL, &MENU_NotYet , StartDemoCleaning , MenuItemDrawName, NULL, 0 } ,
		{ 200 , 144, 0, 0, 0, LT_MENU_DemoCleaning2 /*"Output Name  "*/, 0, 0, &DemoGameName, NULL,  SelectText, DrawTextItem, NULL, 0 } ,
		{ 200 , 160, 0, 0, 0, LT_MENU_DemoCleaning3 /*"Choose From..."*/, 0, 0, &DemoList, NULL , SelectList , DrawList, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};
MENU	MENU_SetUpBiker = {
	LT_MENU_SetUpBiker0 /*"Set Up Biker"*/ , InitBikerMenu, ExitBikerMenu, NULL, 0,
	{
		{ 200, 128, 0, 0, 0, LT_MENU_SetUpBiker1 /*"Create New Biker  "*/, 0, 0, &PilotNameInGame, NULL,  SelectText, DrawTextItem, NULL, 0 } ,
		{ 200, 144, 0, 0, 0, LT_MENU_SetUpBiker2 /*"Bike Controls"*/, 0, 0, NULL, &MENU_Controls, MenuChange, MenuItemDrawName, NULL, 0 },
		{ 200, 160, 0, 0, 0, LT_MENU_SetUpBiker3 /*"Select Bike"*/, 0, 0, NULL, &MENU_SelectBike, MenuChange, MenuItemDrawName, NULL, 0 },
		{ 200, 176, 0, 0, 0, LT_MENU_SetUpBiker4 /*"Select Bike Computer"*/, 0, 0, NULL, &MENU_SelectBikeComputer, MenuChange, MenuItemDrawName, NULL, 0 },
		{ 200, 192, 0, 0, 0, LT_MENU_SetUpBiker5 /*"Choose From..."*/, 0, 0, &PilotList, SelectPilot , SelectList , DrawList, NULL, 0 } ,
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};


MENU	MENU_Save = { LT_MENU_Save0 /*"Save Menu"*/ , NULL , NULL , NULL, 0,
					{ {	200 , 176, 0, 0, 0, LT_MENU_Save1 /*"Save Pickups"*/ , 0, 0, NULL, NULL , SavePickups , MenuItemDrawName, NULL, 0 } ,
					  {	-1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 } } };

MENU	MENU_Start = { "Forsaken" , InitStartMenu , NULL , NULL, 0,

					{ OLDMENUITEM( 200 , 112,  "Set Up Biker  ", (void *)biker_name, &MENU_SetUpBiker, MenuChange, DrawNameVar ),
#ifndef SOFTWARE_ENABLE
					  OLDMENUITEM( 200 , 128, "Toggle Full Screen", NULL, NULL , MenuGoFullScreen , MenuItemDrawName ),
#endif
					  OLDMENUITEM( 200 , 144, "Single Player", NULL, &MENU_SinglePlayer , MenuChange , MenuItemDrawName ),
					  OLDMENUITEM( 200 , 160, "Multi Player", NULL, &MENU_MultiPlayer , MenuChange , MenuItemDrawName ),
					  OLDMENUITEM( 200 , 176, "Load Game", NULL, &MENU_NotYet , MenuChange , MenuItemDrawName ),
					  OLDMENUITEM( 200 , 192, "Save Game", NULL, &MENU_NotYet , MenuChange , MenuItemDrawName ),
					  OLDMENUITEM( 200 , 208, "Play Demo", NULL, &MENU_DemoPlayBack , MenuChange , MenuItemDrawName ),
					  OLDMENUITEM( 200 , 224, "Clean Demo", NULL, &MENU_DemoCleaning , MenuChange , MenuItemDrawName ),
					  OLDMENUITEM( 200 , 240, "Options", NULL, &MENU_Options , MenuChange , MenuItemDrawName ),
					  OLDMENUITEM( 200 , 256, "Quit", NULL, NULL, SelectQuit , MenuItemDrawName ),
					{ 200 , 272, 0, 0, 0, "New Menu System" , 0, 0, NULL, &MENU_NEW_Start, MenuChange , MenuItemDrawName, NULL, 0, 0 } ,

					  {	-1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 } } };

MENU	MENU_ServerMenu = { LT_MENU_ServerMenu0 /*"server menu"*/, InitServerMenu, NULL, NULL, 0,
	{
		OLDMENUITEM( 200, 112, LT_MENU_ServerMenu1 /*"server rendering"*/, &ServerRendering,  NULL, SelectToggle, DrawToggle ),
		OLDMENUITEM( 200, 128, LT_MENU_ServerMenu2 /*"current players"*/, &ServerGamePlayersList, ServerListPlayerSelected, SelectList, DrawList ),

		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};


MENU	MENU_InGame = { LT_MENU_InGame0 /*"Forsaken"*/ , InitInGameMenu , ExitInGameMenu , NULL,	0,
			{
#if !defined( PCIDENT ) && !defined( SHAREWARE ) && !defined( PRESS_PREVIEW_DEMO ) && !defined( ACCLAIM_LANFEST )
					  OLDMENUITEM(	200 , 112,LT_MENU_InGame1 /*"Set Up Biker  "*/, (void *)biker_name, &MENU_SetUpBiker , MenuChange , DrawNameVar),
#ifndef SOFTWARE_ENABLE
					  OLDMENUITEM(  200 , 128,LT_MENU_InGame2 /*"Toggle Full Screen"*/, NULL, NULL , MenuGoFullScreen , MenuItemDrawName),
#endif
					  OLDMENUITEM(	200 , 144,LT_MENU_InGame3 /*"Load Game"*/, NULL, &MENU_LoadSavedGame , MenuChange, MenuItemDrawName),
					  OLDMENUITEM(	200 , 160,LT_MENU_InGame4 /*"Save Game"*/, NULL, &MENU_SaveGame, MenuChange , MenuItemDrawName),
					  OLDMENUITEM(	200 , 176,LT_MENU_InGame5 /*"Options"*/, NULL, &MENU_Options , MenuChange , MenuItemDrawName),
					  OLDMENUITEM(	200 , 192,LT_MENU_InGame6 /*"Level Select"*/, NULL, &MENU_LevelSelect , MenuChange , MenuItemDrawName),
					  OLDMENUITEM(	200 , 192,LT_MENU_InGame7 /*"End level and show stats"*/, NULL, NULL , GoToStats, MenuItemDrawName),
					  OLDMENUITEM(	200 , 208,LT_MENU_InGame8 /*"Quit to Main Menu"*/, NULL, NULL, SelectQuitCurrentGame , MenuItemDrawName),
					  OLDMENUITEM(	200 , 224,LT_MENU_InGame9 /*"show ping"*/, &ShowPing, NULL, SelectToggle , DrawToggle),
					  OLDMENUITEM(	200 , 240,LT_MENU_InGame10 /*"update (secs)"*/, &PingFreqSlider, NULL, SelectSlider , DrawSlider),
#ifndef EXTERNAL_DEMO
					  OLDMENUITEM(  200 , 256,LT_MENU_InGame11 /*"Debugging"*/,&DebugInfo,	DebugModeChanged, SelectToggle,	DrawToggle),
#endif
				  	  OLDMENUITEM(  200 , 272,LT_MENU_InGame1a /*"server menu"*/, NULL, &MENU_ServerMenu, MenuChange, MenuItemDrawName),
					  OLDMENUITEM(	200 , 288,LT_MENU_InGame13 /*"Wireframe Mode"*/ , &DebugVisible, DebugVisibleChanged, SelectToggle, DrawToggle),
					  OLDMENUITEM(	200 , 304,LT_MENU_InGame14 /*"Save Menu"*/ , NULL, &MENU_Save , MenuChange , MenuItemDrawName),
					  OLDMENUITEM(	200 , 320,LT_MENU_InGame15 /*"Debug Menu"*/, NULL, &MENU_DebugMode , MenuChange , MenuItemDrawName),
					  OLDMENUITEM(	200 , 336,LT_MENU_InGame16 /*"IP "*/, (void *)&IPAddressText[0], NULL , NULL , DrawNameVar),
//					  OLDMENUITEM(  200 , 352,LT_MENU_InGame17 /*"Packets Per Second "*/,(void*)&PacketsSlider, NULL, SelectSlider, DrawSlider),
#else
					  OLDMENUITEM(	200 , 112,LT_MENU_InGame18 /*"Set Up Biker  "*/, (void *)biker_name, &MENU_SetUpBiker , MenuChange , DrawNameVar),
					  OLDMENUITEM(	200 , 128,LT_MENU_InGame19 /*"Load Game"*/, NULL, &MENU_LoadSavedGame , MenuChange, MenuItemDrawName),
					  OLDMENUITEM(	200 , 144,LT_MENU_InGame20 /*"Save Game"*/, NULL, &MENU_SaveGame, MenuChange , MenuItemDrawName),
					  OLDMENUITEM(	200 , 160,LT_MENU_InGame21 /*"options"*/, NULL, &MENU_Options , MenuChange , MenuItemDrawName),
					  OLDMENUITEM(	200 , 176,LT_MENU_InGame22 /*"Quit to Main Menu"*/, NULL, NULL, SelectQuitCurrentGame , MenuItemDrawName),
#ifdef SHAREWARE_DEBUGGING
					  OLDMENUITEM(  200 , 256,LT_MENU_InGame23 /*"Debugging"*/,&DebugInfo,	DebugModeChanged, SelectToggle,	DrawToggle),
#endif
#endif
					  {	-1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 } } };

#ifdef SELF_PLAY
MENU	MENU_Copyright = { "" , InitAvgFrameRateGlobals, NULL , NULL, 0,

						{
#ifdef BOOT_DEMO
						OLDMENUITEM( 280 , 352, "", (void *)DemoAvgFpsText, NULL , NULL , DrawCenteredNameVar) ,
//						OLDMENUITEM( 280 , 368, "", (void *)DemoTotalFramesText, NULL , NULL , DrawCenteredNameVar) ,
#endif
						OLDMENUITEM( 280 , 384, "Press enter", NULL, NULL , ChangeStatus_Title , MenuItemDrawName) ,
						{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 } 
						}
 };

#else

MENU	MENU_Copyright = { "" , NULL, NULL , NULL, 0,
						{OLDMENUITEM( 280 , 384, "Press enter", NULL, &MENU_Start , ChangeStatus_Title , MenuItemDrawName) ,
					     {	-1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 } } };
#endif


MENU	MENU_ForceAbort = {
	"Sorry Directplay has forced you to quit due to 1 of its bugs" , NULL , NULL , NULL, 0,
	{
		 OLDMENUITEM(200, 112, "Restart",	NULL,	&MENU_Start,	MenuChange,		MenuItemDrawName),
		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};



MENU	MENU_GotoRoom = {
	"Go to Specific Room" , InitDebugMenu, NULL, NULL, 0,
	{
		{ 200, 128, 0, 0, 0, "Enter Room Name  ", 0, 0, &RoomName, NULL,  SelectText, DrawTextItem, NULL, 0 } ,
		{ 200, 144, 0, 0, 0, "Choose Room From...", 0, 0, &RoomList, ChooseRoom , SelectList , DrawList, NULL, 0 } ,

		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_DebugHelp =
{
	"Debug Help", NULL, NULL, NULL, 0,
	{
		HELPKEY( 200, 112, "S+F1",	"Toggle debug help screen" ),
		HELPKEY( 200, 128, "S+F2",	"Increase FOV" ),
		HELPKEY( 200, 144, "S+F3",	"Decrease FOV" ),
		HELPKEY( 200, 160, "C+S+F2","Reset FOV" ),
		HELPKEY( 200, 176, "S+F4",	"Go to specific room" ),
		HELPKEY( 200, 192, "S+F5",	"Go to next start position" ),
		HELPKEY( 200, 208, "S+F6",	"toggle object clipping" ),
		HELPKEY( 200, 224, "S+F7",	"show bounding boxes" ),
		HELPKEY( 200, 240, "S+F8",	"show external forces" ),
		HELPKEY( 200, 256, "S+F9",	"Cycle portal display" ),
		HELPKEY( 200, 272, "S+F10",	"show trigger zones" ),
		HELPKEY( 200, 288, "S+F11",	"Cycle collision skin" ),
		HELPKEY( 200, 304, "S+F12",	"Toggle collision detection" ),

		HELPKEY( 200, 320, "C+F1",	"show teleports" ),
		HELPKEY( 200, 336, "S+F2",	"show trigger zones" ),

		{ 200, 352, 0, 0, 0, "Return to game", 0, 0, NULL, NULL, MenuItemBack, MenuItemDrawName, NULL, 0 },

		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

MENU	MENU_Help =
{
	LT_MENU_Help0/*"In-Game Help"*/, NULL, NULL, NULL, 0,
	{							 
		HELPKEY( 200, 112, "ESC",LT_MENU_Help1	/*"Toggle menu"*/ ),
		HELPKEY( 200, 128, "F1", LT_MENU_Help2	/*"Toggle help screen" */),
		HELPKEY( 200, 144, "F2", LT_MENU_Help3	/*"Increase window size" */),
		HELPKEY( 200, 160, "F3", LT_MENU_Help4	/*"Decrease window size" */),
		HELPKEY( 200, 176, "F4", LT_MENU_Help5	/*"Toggle panel text" */),
		HELPKEY( 200, 192, "F5", LT_MENU_Help6	/*"Toggle remote camera"*/ ),
		HELPKEY( 200, 208, "F6", LT_MENU_Help7	/*"Toggle rear camera" */),
		HELPKEY( 200, 224, "F7", LT_MENU_Help8	/*"Toggle missile camera"*/ ),
		HELPKEY( 200, 240, "F8", LT_MENU_Help9	/*"Toggle player names" */),

		{ 200, 272, 0, 0, 0, LT_MENU_Help10/*"Return to game"*/, 0, 0, NULL, NULL, MenuItemBack, MenuItemDrawName, NULL, 0 },

		{ -1 , -1, 0, 0, 0, "" , 0, 0, NULL, NULL , NULL , NULL, NULL, 0 }
	}
};

char *BikerText[MAXBIKETYPES] =
{
	
	//BORG
	LT_BorgBikerText,

	//BEARD
	LT_BeardBikerText,

	//LAJAY
	LT_LAJayBikerText,

	//EXCOP
	LT_ExCopBikerText,

	//TRUCKER
	LT_TruckerBikerText,

	//FOETOED
	LT_FoetoedBikerText,

	//JAPG
	LT_JapBirdBikerText,

	//NUTTA
	LT_NuttaBikerText,

	//SEPTRE
	LT_SceptreBikerText,
		
	//JO
	LT_JoBikerText,

	//SHARK - CUVEL CLARK
	LT_SharkBikerText,

	//HK-5
	LT_HK5BikerText,

	//NUBIA
	LT_NubiaBikerText,

	//MEPHISTOFUN
	LT_MophistoBikerText,

	//CERBERO
	LT_CerberoBikerText,

	//SLEEK - EARL SLEEK
	LT_SleekBikerText,

	//FLYGIRL
	LT_FlygirlBikerText,
};


/*�������������������������������������������������������������������
		Globals ...
�������������������������������������������������������������������*/
#if 0
char	TitleNames[8][64] ={	
						   { "data\\pictures\\T320X200.bmp" } ,
						   { "data\\pictures\\T320X240.bmp" } ,
						   { "data\\pictures\\T320X400.bmp" } ,
						   { "data\\pictures\\T512X384.bmp" } ,
						   { "data\\pictures\\T640X400.bmp" } ,
						   { "data\\pictures\\T640X480.bmp" } ,
						   { "data\\pictures\\T800X600.bmp" } ,
						   { "" }
};
#endif
char	TitleNames[8][64] ={	
						   { "data\\pictures\\Ti320200.bmp" } ,
						   { "data\\pictures\\Ti320240.bmp" } ,
						   { "data\\pictures\\Ti320400.bmp" } ,
						   { "data\\pictures\\Ti512384.bmp" } ,
						   { "data\\pictures\\Ti640400.bmp" } ,
						   { "data\\pictures\\Ti640480.bmp" } ,
						   { "data\\pictures\\Ti800600.bmp" } ,
						   { "" }
};

char	CopyrightNames[8][64] ={	
						   { "data\\pictures\\C320X200.bmp" } ,
						   { "data\\pictures\\C320X240.bmp" } ,
						   { "data\\pictures\\C320X400.bmp" } ,
						   { "data\\pictures\\C512X384.bmp" } ,
						   { "data\\pictures\\C640X400.bmp" } ,
						   { "data\\pictures\\C640X480.bmp" } ,
						   { "data\\pictures\\C800X600.bmp" } ,
						   { "" }
};

#define NUMSPLASHSCREENS 2
#define INITIAL_SPLASH_SCREEN 0

char	SplashScreens[NUMSPLASHSCREENS][8][64] = {
						{  { "data\\pictures\\le320200.bmp" } ,
						   { "data\\pictures\\le320240.bmp" } ,
						   { "data\\pictures\\le320400.bmp" } ,
						   { "data\\pictures\\le512384.bmp" } ,
						   { "data\\pictures\\le640400.bmp" } ,
						   { "data\\pictures\\le640480.bmp" } ,
						   { "data\\pictures\\le800600.bmp" } ,
						   { "" },
						},

						{  { "data\\pictures\\Ti320200.bmp" } ,
						   { "data\\pictures\\Ti320240.bmp" } ,
						   { "data\\pictures\\Ti320400.bmp" } ,
						   { "data\\pictures\\Ti512384.bmp" } ,
						   { "data\\pictures\\Ti640400.bmp" } ,
						   { "data\\pictures\\Ti640480.bmp" } ,
						   { "data\\pictures\\Ti800600.bmp" } ,
						   { "" }
						},
};

#define SPLASH_FLAG_Timed		1
#define SPLASH_FLAG_PressReturn	2

#define FLAGS 0
#define SECS  1

#if defined( ECTS )
int SplashInfo[NUMSPLASHSCREENS][2] = {
	{ SPLASH_FLAG_Timed, 5 },		// flags, secs
	{ SPLASH_FLAG_PressReturn | SPLASH_FLAG_Timed, 120 },
};
#elif defined( SELF_PLAY ) || defined( EXTERNAL_DEMO )
int SplashInfo[NUMSPLASHSCREENS][2] = {
	{ SPLASH_FLAG_Timed, 10 },		// flags, secs
	{ SPLASH_FLAG_PressReturn 
#ifndef BOOT_DEMO
	| SPLASH_FLAG_Timed
#endif
	, 15 },
};
#else
int SplashInfo[NUMSPLASHSCREENS][2] = {
	{ SPLASH_FLAG_Timed, 0 },		// flags, secs
	{ SPLASH_FLAG_PressReturn, 0 },
};
#endif

int CurrentSplashScreen = INITIAL_SPLASH_SCREEN;						

#define MAXHIGHLIGHTITEMS 8
#define HIGHLIGHT_Pulsing	0
#define HIGHLIGHT_Static	1

MENU * CurrentMenu = NULL;
MENUITEM * CurrentMenuItem = NULL;
TEXTINFO * HighlightItem[MAXHIGHLIGHTITEMS];
int HighlightStatus[MAXHIGHLIGHTITEMS];
int CurrentHighlightItem;

MENU *MenuStack[ MAXMENULEVELS ];
MENUITEM *MenuItemStack[ MAXMENULEVELS ];
TEXTINFO *TextStack[ MAXTEXTITEMS ];
TEXTINFO *BikeNameTextPtr;
int MenuStackLevel = 0;
int TextStackLevel = 0;
BOOL ForceConfigSave = FALSE;

BOOL TitleOnceOnly = TRUE;

VECTOR View, Look, Up, PanFrom, PanTo, PanFrom2, PanTo2, VDULookPos, DiscLookPos, DiscViewPos, VDUViewPos, StartLookPos, StartViewPos;
float CurrentFOV;
float CurrentCameraPanTheta, CurrentCameraPanTheta2;
VECTOR OrigPos[NUMOFTITLEMODELS];

float rot[6], rotspeed[6], RotPause[6], StackY[7];

#define ROTATE_DISC_All 0
#define ROTATE_DISC_DifficultyForward 1
#define ROTATE_DISC_DifficultyBack 2

int DiscStatus, StackStatus, StackMode, RotWiggle[6], CurrentTextures[6], CurrentDiscHighlight, CurrentVDUHighlight, CameraStatus, DifficultyDir;

#define Judders 7

float JudderAngle[Judders] = {180.0F, 182.0F, 178.0F, 181.0F, 179.0F, 180.0F, 180.0F};

BOOL Turned[6], LastTurned[6], RotateSetup, DoHighlight, 
	 OnRotateVDU, OnVDUflip, RotVDU, PanDone, VDU_Active;


MXLOADHEADER ModelHeaders[MAXMODELHEADERS];	//as defined in models.c

POLYANIM *PolyAnim[6];
MXLOADHEADER * Mxloadheader[6];										

VECTOR FMPolyDirVector = {0.0F, 0.0F, -1.0F};

uint16 fmpoly[2];
uint16 scrpoly[MAXVDULINES][MAXVDULINELENGTH];
uint16 bikerfmpoly;
uint16 BikerScrPoly;
uint16 LevelScrPoly;
uint16 BoxPoly[32];
uint16 PlanePoly;
int CurrentPos[MAXVDULINELENGTH];
float NextX[MAXVDULINES][MAXVDULINELENGTH];
float WipeX[MAXVDULINES][MAXVDULINELENGTH];
float Text_Y_Pos[MAXVDULINES];
float Text_X_Pos[MAXVDULINES];
float TextHeight[MAXVDULINES];

typedef struct 
{
	VECTOR	Pos;
	VECTOR	Look;
	VECTOR	View;
	float	StartRot;
	float	EndRot;
	VECTOR BracketPos;
	float BracketStartRot;
	float BracketEndRot;
}VDUINFO;

#define Left	TRUE
#define	Right	FALSE

VECTOR CurrentVDUPos;
float VDUrot;
float VDU_Start_Rot = -43.0F;
float VDU_End_Rot = 20.0F;
float VDU_Rot_Speed = 3.0F;
float VDU_Theta;

VDUINFO	LeftVDU, RightVDU;

//offsets for vdu text
VECTOR CurrentTextOffset;


//offsets for biker character
VECTOR CharOffset = {-670.0F, 40.0F, 345.0F};


int KeyDefLines[MAXVDULINES];

int CurrentToggle, CurrentTextItem, NoOfLists, CurrentKeyDef;

BOOL VduProcessed, LineExists;
BOOL AutoSelectConnection = FALSE;
BOOL InitialTexturesSet;
BOOL LevelDisplayed;
BOOL BikerDisplayed;
int BikerSet;

BOOL DoNotRotateText;
int BikeChars[MAXBIKETYPES] = {0,7,11,10,6,15,14,12,4,8,2,9,13,5,1, 3, -1};
uint16 BikeModelLookup[MAXBIKETYPES] = {TITLE_MODEL_Lokasenna, TITLE_MODEL_Beard, TITLE_MODEL_LAJay, TITLE_MODEL_ExCop, TITLE_MODEL_RexHardy,
								TITLE_MODEL_Foetoid, TITLE_MODEL_NimSoo, TITLE_MODEL_Nutta, TITLE_MODEL_Sceptre, TITLE_MODEL_Jo,
								TITLE_MODEL_Shark, TITLE_MODEL_HK5, TITLE_MODEL_Nubia, TITLE_MODEL_Mofisto, TITLE_MODEL_Cerbero, TITLE_MODEL_Slick, TITLE_MODEL_ExtraModels};
float BikeModelScale[MAXBIKETYPES] = {0.73F, 0.8F, 0.85F, 0.74F, 0.6F, 0.61F, 0.71F, 0.65F, 0.7F, 0.64F, 0.57F, 0.66F, 0.84F, 0.66F, 0.66F, 0.66F, 1.0F};

float HoloModelScale;

uint16 InterLevelModelLookup[MAXBIKETYPES] = { TITLE_MODEL_Crystal, TITLE_MODEL_GoldBar };
float InterLevelModelScale[MAXBIKETYPES] = {0.41F, 0.6F };

float *HoloScaleLookupTable;
uint16 *HoloModelLookup;

#define NOT_ROTATED FALSE
#define ROTATED TRUE

float	DiscExpand;
float	DiscSpeed; 
float	DiscWiggleDistance;
BOOL	DiscExpandOut;
float	DiscPauseTime;
BOOL	DiscWiggleUp;
float WipeTime;
float VduDisplayTime = 0.5F;
float HoloRotx = 0.0F;
float HoloRoty = 0.0F;
float HoloRotz = 0.0F;

#define	WipeOut	TRUE
#define	WipeIn	FALSE
BOOL WipeStatus;

VECTOR Holopad = {-486.0F, -86.0F, 497.0F};
float HolopadRange = 150.0F;
int testvert;

EXCLUDEDVERTICES MenuTVExcluded = {0, 0, 4, {30, 31, 32, 33}};
EXCLUDEDVERTICES MenuTVDummyExcluded = {0, 0, 4, {36, 37, 38, 39}};
EXCLUDEDVERTICES RoomExcluded = {0, 0, 8, {457, 458, 459, 460, 461, 462, 463, 464}};
EXCLUDEDVERTICES VduScreenExcluded = {0, 1, EXCLUDE_ALL, {0}};
EXCLUDEDVERTICES VduFrameExcluded = {0, 0, EXCLUDE_ALL, {0}};
float rtintamount, gtintamount, btintamount, atintamount1, atintamount2, atintamount3, atintamount4, tinttheta;

//int HoloMorphVerts[24] = {8, 9, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54};
//int HoloMorphVerts[24] = {40, 9, 18, 14, 48, 16, 34, 8, 20, 44, 24, 42, 26, 50, 12, 28, 30, 54, 32, 38, 46, 36, 52, 22 };
int HoloMorphVerts[24] = {9, 14, 18, 22, 26, 30, 34, 38, 42, 46, 50, 54, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52};
int HoloTintVerts[24] = {10, 13, 17, 21, 25, 29, 33, 37, 41, 45, 49, 53, 11, 15, 19, 23, 27, 31, 35, 39, 43, 47, 51, 55};
/*float FlatXOffset = 176.0F;
float FlatYOffset = 44.0F;
float FlatXScale = 0.75F;
float FlatYScale = 0.62F;
float FlatTextScale = 0.79F;*/

float FlatXOffset = 0.0F;
float FlatYOffset = 0.0F;
float FlatXScale = 1.0F;
float FlatYScale = 1.0F;
float FlatTextScale = 1.0F;

float BikeAlpha = 1.0F;
float BikeCol = 0.5F;

/***************
new text globals
***************/
#define VDU_Width 200

TEXTINFO VDUTextItems[MAXTEXTITEMS];
int Current2dBox;
BOOL DrawTextItemBox;
uint16 BoxPoly2d[32];
float VDUoffsetX = 105.0F;
float VDUoffsetY = 15.0F;
char TestStr[256] = "This is a test for plotting text as two d polys within  a bounding box test test test test";
uint16 screenpoly[MAXNUMOFSCRPOLYS];
int CurrentScreenPoly;
float	TEXTINFO_currentx;					
float	TEXTINFO_currenty;					
float	TEXTINFO_currentheight;				
float	TEXTINFO_TextSpace;				
float	TEXTINFO_LineSpace;				
int		TEXTINFO_currentstartpoint;			
int		TEXTINFO_currentendpoint;
int CurrentTextItem;
uint16 testboxpoly;	
uint16 TextLookup[NUMSCREENFONTS][256];		
int character = 0;
int CurrentTeletype;
MENUITEM *LastMenuItem;
BOOL ScreenPolyCursorActive;
uint16 CursorScreenPoly;
BOOL NewCursorActive;
BOOL ForceNewLine;

/***************
holo-bike stuff
***************/
int SelectedBikeFrame;
uint16 SelectedBikeModel;
uint16 OldBikeModel;
float BikeRot = 0.0F;
uint16 BikeLine[MAXNUMOF2DPOLYS];
uint16 CurrentHoloModel = (uint16)-1;
BOOL LinesActive;
int CurrentLine;
VECTOR BikePos;
SCANLINES scanline[MAXNUMOF2DPOLYS];
BOOL KnowExtremeVerts, BikeLoaded;
float CurrentOffset;
BOOL BikeOnSwap, OnBikeShrink, LoadNewBike;
BOOL LightHolopad;

BOOL BikeExpanded = FALSE;

/**************
new event globals
***************/
VECTOR OldLookPos;
VECTOR OldViewPos;
float OldVDUrot;
float RoomDarkness, OldRoomDarkness;

BOOL VDU_Ready;

float HoloLightBrightness, OldHoloLightBrightness;

float OldHoloPadHeight;
float StackRot;

VECTOR stackpos[8];

BOOL StackDown;
float MinStackTheta = 0.0F;
float MaxStackTheta = 170.0F;

int		StackJudderNum;
float	StackRotAmount;
float	OldStackRotAmount;

float BikeSwapScale, OldBikeSwapScale;

float SelectedBikeScale, OldSelectedBikeScale;
int	OldSelectedBike;
float	OldBikeCharAlpha, BikeCharAlpha, LevelPicAlpha;
BOOL HolopadJudderReq;

float BracketRot, OldBracketRot;

float TeleTypeTimer;
int TeleTypeSkip;
BOOL NewTextCharDisplayed = FALSE;

BOOL ListRedrawReq;

int OldMenuStatus;

char *ToggleStatusOn = LT_ToggleStatusOn;
char *ToggleStatusOff = LT_ToggleStatusOff;
char *RadioBtnSelected = "*";
char *RadioBtnNotSelected = "";
char *EmptyString = "";
char *UndefinedKey = LT_Undef;
char *WeaponSelectFirst = "Use arrow keys to select weapon to move then press enter";
char *WeaponSelectSecond = "use right arrow to place item in unused list~"
					"use left arrow to place item in used list~"
					"or use up/down arrows to change position, then press enter to place";
char *WaitingForConfirm = LT_SelectWhenReady;
char *WaitingForReset = LT_WaitingForReset;
int MAXSLIDERINFOLENGTH = 32;
/**********************
new slider globals
***********************/
#define MAXSLIDERSPERMENU 8
#define NUMPOLYSPERSLIDER 1
#define SLIDERSPEED 1.0F
#define SLIDER_RefreshNeeded TRUE
#define SLIDER_RefreshNotNeeded FALSE

typedef struct
{
	MENUITEM *Item;
	BOOL	needs_refresh;
}ACTIVESLIDERINFO;

ACTIVESLIDERINFO ActiveSliderItem[MAXSLIDERSPERMENU];
uint16 SliderPoly[MAXSLIDERSPERMENU][NUMPOLYSPERSLIDER];
/**********************
highlight box globals
***********************/
#define MAXEDGEPOLYS 32

typedef struct
{
	float xmin;
	float xmax;
}HIGHLIGHTPOLYINFO;

HIGHLIGHTPOLYINFO HighlightPolyList[MAXEDGEPOLYS];
int HighlightPolyListStart;
int HighlightPolyListEnd;
#define HIGHLIGHT_SPEED			0.5F	// lowest res pixels per frame
#define HIGHLIGHT_POLY_WIDTH	10	// lowest res pixels
BOOL HighlightListEmpty;
BOOL TestPoly = FALSE;
BOOL WasteAFrame = FALSE;

/********************
weapon priority
*********************/
extern BOOL PrimaryValid[];
extern BOOL SecondaryValid[];
int WeaponList[ MAX( MAX_PRIMARY_WEAPONS, MAX_SECONDARY_WEAPONS ) ];
int16 SelectedWeapon;
uint16 Num_Unused_Weapons;
MENUITEM *WeaponItem;
#define WEAPON_ChoosingFirst	FALSE
#define WEAPON_ChoosingSecond	TRUE
BOOL WeaponOrderStatus;
uint16 MaxWeapons;
int16 *PriorityList;
int16 *OrderList;
char **DescriptionList;
TEXTINFO *IdiotText;
char *IdiotTextPtr;
BOOL *WeaponValid;

/*******************
text editing
********************/
float CursorTimer = 0.0F;
#define CursorInterval	1.0F


BOOL RescanLists = TRUE;
int oldlistitems;

BOOL TitleInitDone;
BOOL HostQuitting = FALSE;

/*******************
Team Select
*******************/
int TeamSelectStatus;
LIST *SourceTeamList;

/*********************
Multi-player messaging
*********************/
#define MAX_TITLE_MSGS 16
#define MAX_TITLE_MSG_SIZE 128
#define	MAX_TITLE_MSG_TIME 100.0F
typedef struct
{
	char text[MAX_TITLE_MSG_SIZE];
	float timer;
}TITLEMSG;
TITLEMSG TitleMsgQue[MAX_TITLE_MSGS];
int		TitleMsgQueStart, TitleMsgQueEnd, TotalTitleMsgs;
int TestMessage = 0;
float TitleMessageTimer;
int MessagesDisplayed;

#define MAX_TIMERS 16

/**************
event stuff
***************/
TITLE_EVENT Title_Events[MAXTITLEEVENTS] = {

	{InitEventDiscPanFromRightInit, EventDiscPanInit, ExitEventDiscPanInit,	TITLE_TIMER_PanToDiscsInit, 0.0F, 0.8F, TITLE_EVENT_STATUS_IDLE},
	{InitEventLowerStack, EventLowerStack, ExitEventLowerStack,			TITLE_TIMER_PanToDiscsInit, 0.2F, 0.8F, TITLE_EVENT_STATUS_IDLE},
	{InitEventJudderStack, EventJudderStack, NULL,			TITLE_TIMER_PanToDiscsInit, 0.8F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	{InitEventLightenRoom, EventLightenRoom, NULL,			TITLE_TIMER_PanToDiscsInit, 0.0F, 0.8F, TITLE_EVENT_STATUS_IDLE},

	{InitEventDiscPan, EventDiscPan, ExitEventDiscPanFromRight,				TITLE_TIMER_PanToDiscsFromRight, 0.3F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	{InitEventRotateInRightVDU, EventRotateInRightVDU, NULL,				TITLE_TIMER_PanToDiscsFromRight, 0.2F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	{InitEventLightenRoom, EventLightenRoom, NULL,							TITLE_TIMER_PanToDiscsFromRight, 0.3F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	{InitEventFadeOffHoloLight, EventFadeOffHoloLight, ExitEventFadeOffHoloLight,				TITLE_TIMER_PanToDiscsFromRight, 0.0F, 0.2F, TITLE_EVENT_STATUS_IDLE},
	{InitEventShrinkBike, NULL, NULL,				TITLE_TIMER_PanToDiscsFromRight, 0.0F, 0.2F, TITLE_EVENT_STATUS_IDLE},
	{InitEventLowerHoloPad, EventLowerHoloPad, NULL,						TITLE_TIMER_PanToDiscsFromRight, 0.2F, 0.5F, TITLE_EVENT_STATUS_IDLE},
	
	{InitEventDiscPan, EventDiscPan, NULL,	TITLE_TIMER_PanToDiscsFromLeft, 0.0F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	{InitEventRotateInLeftVDU, EventRotateInLeftVDU, NULL,		TITLE_TIMER_PanToDiscsFromLeft, 0.0F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	{InitEventLightenRoom, EventLightenRoom, NULL,				TITLE_TIMER_PanToDiscsFromLeft, 0.0F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	
	{InitEventRightVDUPan, EventRightVDUPan, ExitEventVDUPan,	TITLE_TIMER_PanToRightVDU, 0.0F, 0.6F, TITLE_EVENT_STATUS_IDLE},
	{InitEventRotateOutRightVDU, EventRotateOutRightVDU, ExitEventRotateOutVDU,	TITLE_TIMER_PanToRightVDU, 0.3F, 0.6F, TITLE_EVENT_STATUS_IDLE},
	{InitEventDarkenRoom, EventDarkenRoom, NULL,				TITLE_TIMER_PanToRightVDU, 0.0F, 0.6F, TITLE_EVENT_STATUS_IDLE},
	{InitEventFadeOnHoloLight, EventFadeOnHoloLight, NULL,		TITLE_TIMER_PanToRightVDU, 0.8F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	{InitEventRaiseHoloPad, EventRaiseHoloPad, ExitEventRaiseHolopad,			TITLE_TIMER_PanToRightVDU, 0.3F, 0.6F, TITLE_EVENT_STATUS_IDLE},
	{InitEventJudderHoloPad, EventJudderHoloPad, ExitEventJudderHoloPad,			TITLE_TIMER_PanToRightVDU, 0.6F, 0.8F, TITLE_EVENT_STATUS_IDLE},
	{InitEventExpandBike, NULL, NULL, TITLE_TIMER_PanToRightVDU, 0.8F, 1.0F, TITLE_EVENT_STATUS_IDLE},

	{InitEventRightVDUPan, EventRightVDUPan, ExitEventVDUPan,	TITLE_TIMER_InterLevelPan, 0.0F, 0.6F, TITLE_EVENT_STATUS_IDLE},
	{InitEventRotateOutRightVDU, EventRotateOutRightVDU, ExitEventRotateOutVDU,	TITLE_TIMER_InterLevelPan, 0.3F, 0.6F, TITLE_EVENT_STATUS_IDLE},
	{InitEventDarkenRoom, EventDarkenRoom, NULL,				TITLE_TIMER_InterLevelPan, 0.0F, 0.6F, TITLE_EVENT_STATUS_IDLE},
	{InitEventFadeOnHoloLight, EventFadeOnHoloLight, NULL,		TITLE_TIMER_InterLevelPan, 0.8F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	{InitEventRaiseHoloPad, EventRaiseHoloPad, ExitEventRaiseHolopad,			TITLE_TIMER_InterLevelPan, 0.3F, 0.6F, TITLE_EVENT_STATUS_IDLE},
	{InitEventJudderHoloPad, EventJudderHoloPad, ExitEventJudderHoloPad,			TITLE_TIMER_InterLevelPan, 0.6F, 0.8F, TITLE_EVENT_STATUS_IDLE},
	{InitEventExpandCrystal, NULL, NULL, TITLE_TIMER_InterLevelPan, 0.8F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	
	{InitEventLeftVDUPan, EventLeftVDUPan, ExitEventVDUPan,		TITLE_TIMER_PanToLeftVDU, 0.0F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	{InitEventRotateOutLeftVDU, EventRotateOutLeftVDU, ExitEventRotateOutVDU,	TITLE_TIMER_PanToLeftVDU, 0.0F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	{InitEventDarkenRoom, EventDarkenRoom, NULL,				TITLE_TIMER_PanToLeftVDU, 0.0F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	
	{InitEventFadeOffHoloLight, EventFadeOffHoloLight, ExitEventFadeOffHoloLight,				TITLE_TIMER_SwapBikes, 0.0F, 0.25F, TITLE_EVENT_STATUS_IDLE},
	{InitEventFadeOnHoloLight, EventFadeOnHoloLight, NULL,					TITLE_TIMER_SwapBikes, 0.25F, 0.5F, TITLE_EVENT_STATUS_IDLE},
	{TriggerBikeSpeech, NULL, NULL,					TITLE_TIMER_SwapBikes, 1.0F, 1.0F, TITLE_EVENT_STATUS_IDLE},

	{InitEventRightVDUPan, EventRightVDUPan, ExitEventVDUPan,	TITLE_TIMER_Visuals, 0.0F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	{InitEventRotateOutRightVDU, EventRotateOutRightVDU, ExitEventRotateOutVDU,	TITLE_TIMER_Visuals, 0.5F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	{InitEventDarkenRoom, EventDarkenRoom, NULL,				TITLE_TIMER_Visuals, 0.0F, 1.0F, TITLE_EVENT_STATUS_IDLE},

	{InitEventDiscPan, EventDiscPan, ExitEventDiscPanFromRight,				TITLE_TIMER_PanToDiscsFromVisuals, 0.0F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	{InitEventRotateInRightVDU, EventRotateInRightVDU, NULL,				TITLE_TIMER_PanToDiscsFromVisuals, 0.0F, 0.5F, TITLE_EVENT_STATUS_IDLE},
	{InitEventLightenRoom, EventLightenRoom, NULL,							TITLE_TIMER_PanToDiscsFromVisuals, 0.0F, 1.0F, TITLE_EVENT_STATUS_IDLE},

	{InitEventRightVDUPan, EventRightVDUPan, ExitEventVDUPan,	TITLE_TIMER_NormalPanToRightVDU, 0.0F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	{InitEventRotateOutRightVDU, EventRotateOutRightVDU, ExitEventRotateOutVDU,	TITLE_TIMER_NormalPanToRightVDU, 0.5F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	{InitEventDarkenRoom, EventDarkenRoom, NULL,				TITLE_TIMER_NormalPanToRightVDU, 0.0F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	
	{InitEventDiscPan, EventDiscPan, ExitEventDiscPanFromRight,				TITLE_TIMER_NormalPanToDiscsFromRight, 0.0F, 1.0F, TITLE_EVENT_STATUS_IDLE},
	{InitEventRotateInRightVDU, EventRotateInRightVDU, NULL,				TITLE_TIMER_NormalPanToDiscsFromRight, 0.0F, 0.5F, TITLE_EVENT_STATUS_IDLE},
	{InitEventLightenRoom, EventLightenRoom, NULL,							TITLE_TIMER_NormalPanToDiscsFromRight, 0.0F, 1.0F, TITLE_EVENT_STATUS_IDLE},

	{InitEventFadeOffHoloLight, EventFadeOffHoloLight, ExitEventFadeOffHoloLight,				TITLE_TIMER_LowerHolopad, 0.0F, 0.4F, TITLE_EVENT_STATUS_IDLE},
	{InitEventShrinkBike, NULL, NULL,				TITLE_TIMER_LowerHolopad, 0.0F, 0.4F, TITLE_EVENT_STATUS_IDLE},
	{InitEventLowerHoloPad, EventLowerHoloPad, NULL,						TITLE_TIMER_LowerHolopad, 0.4F, 1.0F, TITLE_EVENT_STATUS_IDLE},

//	{InitEventFadeOnHoloLight, EventFadeOnHoloLight, NULL,					TITLE_TIMER_ExpandObject, 0.0F, 1.0F, TITLE_EVENT_STATUS_IDLE},

	{NULL, NULL, NULL, -1, 0.0F, 0.0F, TITLE_EVENT_STATUS_IDLE},
};

TITLE_EVENT_TIMER Title_Timers[MAXTITLETIMERS] = {

	{0.0F,	0.0F, TITLE_EVENT_TIMER_IDLE, NULL},		//NULL timer
	{1.5F,	0.0F, TITLE_EVENT_TIMER_IDLE, InitStartDiscPanTimer},		//pan to discs initially
	{1.5F,	0.0F, TITLE_EVENT_TIMER_IDLE, InitRightDiscPanTimer},		//pan to discs from right
	{1.0F,	0.0F, TITLE_EVENT_TIMER_IDLE, InitLeftDiscPanTimer},		//pan to discs from left
	{1.5F,	0.0F, TITLE_EVENT_TIMER_IDLE, InitRightVDUPanTimer},		//pan to right VDU
	{1.5F,	0.0F, TITLE_EVENT_TIMER_IDLE, InitRightVDUPanTimer},		//inter level pan
	{1.0F,	0.0F, TITLE_EVENT_TIMER_IDLE, InitLeftVDUPanTimer},		//pan to left VDU
	{2.0F,	0.0F, TITLE_EVENT_TIMER_IDLE, NULL},		//swap bikes
	{0.0F,	0.0F, TITLE_EVENT_TIMER_IDLE, ChooseDiscTimer},		//disc choose dummy timer
	{1.0F,	0.0F, TITLE_EVENT_TIMER_IDLE, InitVisualsTimer},		//disc choose dummy timer
	{1.0F,	0.0F, TITLE_EVENT_TIMER_IDLE, ChooseDiscTimer},		//disc choose dummy timer
	{1.0F,	0.0F, TITLE_EVENT_TIMER_IDLE, InitRightVDUPanTimer},		//normal pan right
	{1.0F,	0.0F, TITLE_EVENT_TIMER_IDLE, InitRightDiscPanTimer},		//normal disc pan from right
//	{1.0F,	0.0F, TITLE_EVENT_TIMER_IDLE, InitGeneralTimer},		//swap inter level objects
	{0.75F,	0.0F, TITLE_EVENT_TIMER_IDLE, InitGeneralTimer},		//lower holopad
	{0.5F,	0.0F, TITLE_EVENT_TIMER_IDLE, InitGeneralTimer},		// shrink object
	{0.5F,	0.0F, TITLE_EVENT_TIMER_IDLE, InitGeneralTimer},		// expand object
	{-1.0F, -1.0F, TITLE_EVENT_TIMER_IDLE}
};

/*
 * RegSet
 *
 * Stores a data value in the registry
 */
LONG RegSet(LPCTSTR lptszName, CONST BYTE * lpData, DWORD dwSize)
{
#ifdef SELF_PLAY
	return ERROR_SUCCESS;
#else
#ifdef UNICODE
    dwSize *= 2; // calc number of bytes
#endif
	return RegSetValueEx(ghCondemnedKey, lptszName, 0, REG_BINARY, lpData, dwSize );
#endif
}

/*
 * RegSetA
 *
 * Stores data as an ascii string in the registry
 */
LONG RegSetA(LPCTSTR lptszName, CONST BYTE * lpData, DWORD dwSize)
{
#ifdef SELF_PLAY
	return ~ERROR_SUCCESS;
#else
    return RegSetValueEx(ghCondemnedKey, lptszName, 0, REG_SZ, lpData, dwSize);
#endif
}

/*
 * RegGet
 *
 * Queries a value from the registry
 */
LONG RegGet(LPCTSTR lptszName, LPBYTE lpData, LPDWORD lpdwDataSize)
{
#ifdef SELF_PLAY
	return ~ERROR_SUCCESS;
#else
    DWORD dwType;

    return RegQueryValueEx(ghCondemnedKey, lptszName, NULL, &dwType, lpData, lpdwDataSize);
#endif
}

/*�������������������������������������������������������������������
	Procedure	:		Init Title load in all graphics etc for Titles..
	Input		:		LPDIRECTDRAW lpDD, LPDIRECT3D lpD3D, LPDIRECT3DDEVICE lpDev, 
						LPDIRECT3DVIEWPORT lpView
	Output		:		BOOL TRUE/FALSE
�������������������������������������������������������������������*/
BOOL
InitTitle(LPDIRECTDRAW lpDD, LPDIRECT3D lpD3D, LPDIRECT3DDEVICE lpDev, 
           LPDIRECT3DVIEWPORT lpView )
{
    LPDIRECTDRAWPALETTE ddpal;
    D3DMATERIAL bmat;
    D3DMATERIALHANDLE hBmat;

	framelag = 0;

    if (bPrimaryPalettized)
	{
		lpPalette = DDLoadPalette( lpDD , "data\\pictures\\pal.bmp");
		ddpal =  DDLoadPalette( lpDD , "data\\pictures\\pal.bmp");
		d3dappi.lpFrontBuffer->lpVtbl->SetPalette( d3dappi.lpFrontBuffer, ddpal );
		d3dappi.lpBackBuffer->lpVtbl->SetPalette( d3dappi.lpBackBuffer, ddpal );
	}

	memset(&bmat, 0, sizeof(D3DMATERIAL));
    bmat.dwSize = sizeof(D3DMATERIAL);
    bmat.dwRampSize = 1;
    if (lpD3D->lpVtbl->CreateMaterial(lpD3D, &lpBmat, NULL) != D3D_OK)
	{
		Msg( "InitTitle() CreateMaterial() Failed\n" );
        return FALSE;
	}
    if (lpBmat->lpVtbl->SetMaterial(lpBmat, &bmat) != D3D_OK)
	{
		Msg( "InitTitle() SetMaterial() Failed\n" );
        return FALSE;
	}
    if (lpBmat->lpVtbl->GetHandle(lpBmat, lpDev, &hBmat) != D3D_OK)
	{
		Msg( "InitTitle() GetHangle() Failed\n" );
        return FALSE;
	}
    if (lpView->lpVtbl->SetBackground(lpView, hBmat) != D3D_OK)
	{
		Msg( "InitTitle() SetBackground() Failed\n" );
        return FALSE;
	}

	ticksperframe = 14.0F;
    
	InitModeCase();

	cursorclipped = TRUE;
	SetCursorClip();

    memset(&Names, 0, sizeof(SHORTNAMETYPE) );

	InitFont(FALSE);

	// init vdu font for blitting if used...
	if(!bPolyText)
		InitTitleFont();

	return TRUE;
}

void InitTitleFont(void)
{
    LPDIRECTDRAWPALETTE ddpal;
#if 0
	//init the title font for blitting...
	switch (ModeCase)
	{
	case Mode320X200:
		lpDDSTitleFont = DDLoadBitmap( d3dapp->lpDD, "data\\pictures\\f320X200.bmp", 0, 0 );
   		ddpal =  DDLoadPalette( d3dapp->lpDD , "data\\pictures\\f320X200.bmp");
		break;
	case Mode320X240:
		lpDDSTitleFont = DDLoadBitmap( d3dapp->lpDD, "data\\pictures\\f320X200.bmp", 0, 0 );
   		ddpal =  DDLoadPalette( d3dapp->lpDD , "data\\pictures\\f320X200.bmp");
		break;
	case Mode320X400:
		lpDDSTitleFont = DDLoadBitmap( d3dapp->lpDD, "data\\pictures\\f320X200.bmp", 0, 0 );
   		ddpal =  DDLoadPalette( d3dapp->lpDD , "data\\pictures\\f320X200.bmp");
		break;
	case Mode512X384:
		lpDDSTitleFont = DDLoadBitmap( d3dapp->lpDD, "data\\pictures\\f512X384.bmp", 0, 0 );
   		ddpal =  DDLoadPalette( d3dapp->lpDD , "data\\pictures\\f512X384.bmp");
		break;
	case Mode640X400:
		lpDDSTitleFont = DDLoadBitmap( d3dapp->lpDD, "data\\pictures\\f512X384.bmp", 0, 0 );
   		ddpal =  DDLoadPalette( d3dapp->lpDD , "data\\pictures\\f512X384.bmp");
		break;
	case Mode640X480:
		lpDDSTitleFont = DDLoadBitmap( d3dapp->lpDD, "data\\pictures\\f512X384.bmp", 0, 0 );
   		ddpal =  DDLoadPalette( d3dapp->lpDD , "data\\pictures\\f512X384.bmp");
		break;
	case Mode800X600:
		lpDDSTitleFont = DDLoadBitmap( d3dapp->lpDD, "data\\pictures\\f512X384.bmp", 0, 0 );
   		ddpal =  DDLoadPalette( d3dapp->lpDD , "data\\pictures\\f512X384.bmp");
		break;
	default:
		lpDDSTitleFont = DDLoadBitmap( d3dapp->lpDD, "data\\pictures\\f320X200.bmp", 0, 0 );
   		ddpal =  DDLoadPalette( d3dapp->lpDD , "data\\pictures\\f320X200.bmp");
		break;
	}
#endif
#if 1
	if( d3dappi.szClient.cx >= 512 && d3dappi.szClient.cy >= 384 )
	{
		lpDDSTitleFont = DDLoadBitmap( d3dapp->lpDD, "data\\pictures\\f512X384.bmp", 0, 0 );
   		ddpal =  DDLoadPalette( d3dapp->lpDD , "data\\pictures\\f512X384.bmp");
	}else
#endif
	{
		lpDDSTitleFont = DDLoadBitmap( d3dapp->lpDD, "data\\pictures\\f320X200.bmp", 0, 0 );
   		ddpal =  DDLoadPalette( d3dapp->lpDD , "data\\pictures\\f320X200.bmp");
	}


	lpDDSTitleFont->lpVtbl->SetPalette( lpDDSTitleFont , ddpal );
   	DDSetColorKey( lpDDSTitleFont, RGB_MAKE( 0 , 0 , 0 ) );

}

void ReInitTitleFont (void)
{
#if 0
	switch (ModeCase)
	{
	case Mode320X200:
		DDReLoadBitmap( lpDDSTitleFont , "data\\pictures\\f320X200.bmp" );
		break;
	case Mode320X240:
		DDReLoadBitmap( lpDDSTitleFont , "data\\pictures\\f320X200.bmp" );
		break;
	case Mode512X384:
		DDReLoadBitmap( lpDDSTitleFont , "data\\pictures\\f512X384.bmp" );
		break;
	case Mode640X400:
		DDReLoadBitmap( lpDDSTitleFont , "data\\pictures\\f512X384.bmp" );
		break;
	case Mode640X480:
		DDReLoadBitmap( lpDDSTitleFont , "data\\pictures\\f512X384.bmp" );
		break;
	case Mode800X600:
		DDReLoadBitmap( lpDDSTitleFont , "data\\pictures\\f512X384.bmp" );
		break;
	case Mode1024X768:
		DDReLoadBitmap( lpDDSTitleFont , "data\\pictures\\f512X384.bmp" );
		break;
	default:
		DDReLoadBitmap( lpDDSTitleFont , "data\\pictures\\f320X200.bmp" );
		break;
	}
#endif

	if( d3dappi.szClient.cx >= 512 && d3dappi.szClient.cy >= 384 )
	{
		DDReLoadBitmap( lpDDSTitleFont , "data\\pictures\\f512X384.bmp" );
	}else
	{
		DDReLoadBitmap( lpDDSTitleFont , "data\\pictures\\f320X200.bmp" );
	}
}

/*�������������������������������������������������������������������
	Procedure	:		Release Tile Screen Graphics etc...
	Input		:		nothing
	Output		:		nothing
�������������������������������������������������������������������*/
void
ReleaseTitle(void)
{
   	int i;
	
	// only release font if not showing loading bar...
	if ( !PreventFlips )
	{
		ReleaseDDSurf(lpDDSTwo);
		lpDDSTwo = NULL;
	}

	if(!bPolyText)
		ReleaseDDSurf(lpDDSTitleFont);

	for( i = 0; i < NUM_TITLE_LOOPS; i++ )
	{
		StopSfx( TitleLoopId[ i ] );
		TitleLoopId[ i ] = 0;
	}
}

/*�������������������������������������������������������������������
	Procedure	:		Set up initail parameters for title room...
	Input		:		nothing
	Output		:		nothing
�������������������������������������������������������������������*/
void SetInitialTitleParams()
{
	int i;

	/**********************************************************************************
	Positioning
	**********************************************************************************/
	
	// Position of point on VDU to home in on
	RightVDU.Look.x = -398.0F; RightVDU.Look.y = 58.0F; RightVDU.Look.z = -7.0F;
	RightVDU.View.x = -640.0F; RightVDU.View.y = 58.0F; RightVDU.View.z = 614.0F;
	RightVDU.Pos.x = -755.0F; RightVDU.Pos.y = -381.0F; RightVDU.Pos.z = 331.0F;
	RightVDU.StartRot = -43.0F;
	RightVDU.EndRot = 21.3F;
	RightVDU.BracketPos.x = -746.0F; RightVDU.BracketPos.y = -383; RightVDU.BracketPos.z = 335;
	RightVDU.BracketStartRot = -41.3F;
	RightVDU.BracketEndRot = 23.0F;

	LeftVDU.Look.x = 278.0F; LeftVDU.Look.y = 91.0F; LeftVDU.Look.z = 0.0F;
	LeftVDU.View.x = 453.0F; LeftVDU.View.y = 91.0F; LeftVDU.View.z = 401.0F;
	LeftVDU.Pos.x = 446.0F; LeftVDU.Pos.y = -348.0F; LeftVDU.Pos.z = 164.0F;
	LeftVDU.StartRot = 240.0F;
	LeftVDU.EndRot = 156.4F;
	LeftVDU.BracketPos.x = 440.0F; LeftVDU.BracketPos.y = -349.0F; LeftVDU.BracketPos.z = 165.0F;
	LeftVDU.BracketStartRot = 259.0F;
	LeftVDU.BracketEndRot = 175.0F;

				  
	//Position of point on discs to home in on
	DiscLookPos.x = 0.0F; DiscLookPos.y = 72.0F; DiscLookPos.z = 0.0F;

	// 'Home' position of camera
//	DiscViewPos.x = 131.0F; DiscViewPos.y = 121.0F; DiscViewPos.z = 142.0F;
	DiscViewPos.x = 131.0F; DiscViewPos.y = 121.0F; DiscViewPos.z = 200.0F;

	StartViewPos.x = 197.0F; StartViewPos.y = 97.0F; StartViewPos.z = 908.0F;
	StartLookPos.x = 57.0F; StartLookPos.y = 0.0F; StartLookPos.z = 0.0F;

	// Initial camera parameters
	View = StartViewPos;
	Look = StartLookPos;
	Up.x = 0.0F; Up.y = 1.0F; Up.z = 0.0F;
	CurrentFOV = 80.0F;
	

	/**********************************************************************************
	Disc Stack
	**********************************************************************************/
	DiscExpand = 3.0F;	// y distance that disc 1 will expand out by
	DiscSpeed = 0.2F; 	// multiplier for disc rotate fn
	DiscWiggleDistance = 4.0F;	// max y amount that discs wiggle by after expanding
	DiscExpandOut = TRUE;	 
	DiscPauseTime = 0.0F;
	DiscWiggleUp = TRUE;
	CurrentDiscHighlight = -1;
	RotateSetup = FALSE;
	StackStatus = DISC_NOTHING;
	InitialTexturesSet = FALSE;
					 
	for (i=0; i<6; i++)
		Turned[i] = TRUE;  
					 

	/**********************************************************************************
	VDU Screen
	**********************************************************************************/
	CurrentVDUHighlight = -1;


	VduProcessed = FALSE;


	/**********************************************************************************
	Viewpoint movement
	**********************************************************************************/
   	CameraStatus = CAMERA_AtStart;
	PanDone = FALSE;


	/***********************
	new text stuff
	************************/
	Current2dBox = 0;
	DrawTextItemBox = FALSE;	//draw the bounding box for VDU text items?
	CurrentScreenPoly = 0;
	CurrentTextItem = 0;
	CurrentTeletype = 0;
	LastMenuItem = CurrentMenuItem;
	ScreenPolyCursorActive = FALSE;


	/***********************
	holo-bike stuff
	************************/
	LinesActive = FALSE;
	BikeLoaded = FALSE;
	CurrentOffset = 0.0F;
	BikeOnSwap = FALSE;

	VDU_Ready = FALSE;
	StackRot = 0.0F;

	StackDown = FALSE;
	BikeSwapScale = 0.0F;

	OldSelectedBike = -1;

	HolopadJudderReq = TRUE;
	ListRedrawReq = TRUE;

	RoomDarkness = 1.0F;

	CurrentTextures[0] = 1;
	for (i = 1; i < 6; i++)
    	CurrentTextures[i] = 0;

	/***********************
	new slider stuff
	***********************/
	for (i=0; i<MAXSLIDERSPERMENU; i++)
		ActiveSliderItem[i].Item = NULL;


	/**********************
	new highlight stuff
	***********************/
	HighlightPolyListStart = 0;
	HighlightPolyListEnd = 0;
	HighlightListEmpty = TRUE;

	ResetAllEvents();

	CurrentHighlightItem = 0;

	for (i=0; i < MAXHIGHLIGHTITEMS; i++)
		HighlightItem[ i ] = NULL;

	LevelDisplayed = FALSE;
	BikerDisplayed = FALSE;

	InitTitleMessaging();

	TitleMessageTimer = 0.0F;
	MessagesDisplayed = 0;

	// team game stuff....
	memset( &PlayerReady, FALSE, sizeof(BOOL) * MAX_PLAYERS);
	memset( TitleMessage, 0, sizeof(char) * MAXTEXTMSG * TITLE_TEXT_MSGS_STORED);

}

/*�������������������������������������������������������������������
	Procedure	:		LoadTitleModels
	Input		:		nothing...
	Output		:		BOOL TRUE/FALSE
�������������������������������������������������������������������*/
BOOL LoadTitleModels(void)
{
	int i;
	uint16 CurrentModel;

   	// which set of models do we want to load?
	if ( MyGameStatus == STATUS_BetweenLevels )
	{
		TitleModelSet = InterLevelModelNames;
		HoloScaleLookupTable = InterLevelModelScale;
		HoloModelLookup = InterLevelModelLookup;
	}
	else
	{
		TitleModelSet = TitleModelNames;
		HoloScaleLookupTable = BikeModelScale;
		HoloModelLookup = BikeModelLookup;
	}

	NumTitleModelsToLoad = 15;

#ifndef SELF_PLAY
	for (i=0; i < NumTitleModelsToLoad; i++)
	{
		BackgroundModel[i] = FindFreeModel();
				
		if ( BackgroundModel[i] != (uint16) -1)
		{	CurrentModel = BackgroundModel[i];
			Models[CurrentModel].Flags = MODFLAG_Original;
			Models[CurrentModel].Pos.x = 0.0F;
			Models[CurrentModel].Pos.y = 0.0F;
			Models[CurrentModel].Pos.z = 0.0F;
			Models[CurrentModel].Mat = MATRIX_Identity;
			MatrixTranspose( &Models[CurrentModel].Mat, &Models[CurrentModel].InvMat );
			
			if ( (CurrentModel == TITLE_MODEL_HoloLight) || 
				(CurrentModel == TITLE_MODEL_Bracket) ||
				(CurrentModel == TITLE_MODEL_MenuTVDummy) )
				Models[CurrentModel].Visible = 0;
			else
				Models[CurrentModel].Visible = 1;

			Models[CurrentModel].Group	= 0;
			Models[CurrentModel].Func	= MODFUNC_Nothing;
			Models[CurrentModel].ModelNum	= i;
		}else
			return FALSE;

	}

	SetInitialTitleParams();

	PlaceObjects();

	TitleInitDone = FALSE;
#endif

	// init all holo-object stuff...
	
	// actual model...
	CurrentHoloModel = (uint16)-1;

	// scan lines...
	for ( i = 0; i < MAXNUMOF2DPOLYS; i++ )
	{
		BikeLine[ i ] = (uint16)-1;
	}

	return TRUE;
		
}

void KillLines(void)
{
	int i;
	
	if (LinesActive)
	{ 
		for (i=0; i<CurrentLine; i++)
		{
			if ( BikeLine[ i ] != (uint16)-1 )
			{
				KillUsedPoly( BikeLine[i] );
				BikeLine[ i ] = (uint16)-1;
			}
		}

		LinesActive = FALSE;
		CurrentLine = 0;	  
	}

}

#define POINT_TO_PLANE( P, N ) ( (P)->x * (N)->Normal.x + (P)->y * (N)->Normal.y + (P)->z * (N)->Normal.z + ( (N)->Offset) )

BOOL SetUpLines (uint16 Model, PLANE plane, VECTOR *rot)
{
	int num_polys;	
	int poly, edge;
	LPD3DTRIANGLE poly_ptr;
	LPD3DLVERTEX vertex_ptr;
	VECTOR tempv1, tempv2, tempv3;
	VECTOR start, end, IntPoint;
	float point1dist, point2dist, distance2plane;
	int intersection_points;
	VECTOR point[MAXLINES];
   	int i;
	float thickness = 3.0F;
	int font;
	int edgebits;
	int scanlinenum;
	BOOL startset, endset;
	MXALOADHEADER	* mxaheader;
	MXLOADHEADER	* mxheader;
	int Group, ExecBuf;
	MATRIX Mat_R;
	float scaleout = 1.01F;

#ifdef SOFTWARE_ENABLE
	return TRUE;
#endif

	font = GetScreenFont(FONT_Large);
	 
	BuildRotMatrix(rot->x, rot->y, rot->z, &Mat_R);

	if ( TitleModelSet[ Model ].DoIMorph )
	{
		mxaheader = &MxaModelHeaders[ Models[Model].ModelNum];

		for( Group = 0; Group < mxaheader->num_groups; Group++ )
		{
			for( ExecBuf = 0; ExecBuf < mxaheader->Group[ Group ].num_execbufs; ExecBuf++ )
			{   
  
				num_polys = mxaheader->Group[Group].num_polys_per_execbuf[ExecBuf];
				poly_ptr = mxaheader->Group[Group].poly_ptr[ExecBuf];
				vertex_ptr = mxaheader->Group[Group].org_vertpnt[ExecBuf];

				intersection_points = 0;
				scanlinenum = 0;


				for (poly=0; poly<num_polys; poly++)
				{
					tempv1.x = vertex_ptr[poly_ptr->v1].x;
					tempv1.y = vertex_ptr[poly_ptr->v1].y;
					tempv1.z = vertex_ptr[poly_ptr->v1].z;

					tempv2.x = vertex_ptr[poly_ptr->v2].x;
					tempv2.y = vertex_ptr[poly_ptr->v2].y;
					tempv2.z = vertex_ptr[poly_ptr->v2].z;

					tempv3.x = vertex_ptr[poly_ptr->v3].x;
					tempv3.y = vertex_ptr[poly_ptr->v3].y;
					tempv3.z = vertex_ptr[poly_ptr->v3].z;
					
					ApplyMatrix( &Mat_R, &tempv1, &tempv1 );
					ApplyMatrix( &Mat_R, &tempv2, &tempv2 );
					ApplyMatrix( &Mat_R, &tempv3, &tempv3 );
					/*
					tempv1.x *= SelectedBikeScale * scaleout; //* BikeSwapScale;
					tempv1.y *= SelectedBikeScale * scaleout; //* BikeSwapScale;
					tempv1.z *= SelectedBikeScale * scaleout; //* BikeSwapScale;
					tempv2.x *= SelectedBikeScale * scaleout; //* BikeSwapScale;
					tempv2.y *= SelectedBikeScale * scaleout; //* BikeSwapScale;
					tempv2.z *= SelectedBikeScale * scaleout; //* BikeSwapScale;
					tempv3.x *= SelectedBikeScale * scaleout; //* BikeSwapScale;
					tempv3.y *= SelectedBikeScale * scaleout; //* BikeSwapScale;
					tempv3.z *= SelectedBikeScale * scaleout; //* BikeSwapScale;
					*/
					tempv1.x *= HoloModelScale * scaleout; //* BikeSwapScale;
					tempv1.y *= HoloModelScale * scaleout; //* BikeSwapScale;
					tempv1.z *= HoloModelScale * scaleout; //* BikeSwapScale;
					tempv2.x *= HoloModelScale * scaleout; //* BikeSwapScale;
					tempv2.y *= HoloModelScale * scaleout; //* BikeSwapScale;
					tempv2.z *= HoloModelScale * scaleout; //* BikeSwapScale;
					tempv3.x *= HoloModelScale * scaleout; //* BikeSwapScale;
					tempv3.y *= HoloModelScale * scaleout; //* BikeSwapScale;
					tempv3.z *= HoloModelScale * scaleout; //* BikeSwapScale;
					
					startset = FALSE;
					endset = FALSE;

					for (edge = 0; edge < 3; edge++)
					{					 
						switch (edge)
						{
						case 0:
							start.x = tempv1.x;	  
							start.y = tempv1.y;
							start.z = tempv1.z;
							end.x = tempv2.x;
							end.y = tempv2.y;
							end.z = tempv2.z;
							edgebits = 1;
							break;
						case 1:
							start.x = tempv2.x;
							start.y = tempv2.y;
							start.z = tempv2.z;
							end.x = tempv3.x;
							end.y = tempv3.y;
							end.z = tempv3.z;
							edgebits = 4;
							break;
						case 2:
							start.x = tempv3.x;
							start.y = tempv3.y;
							start.z = tempv3.z;
							end.x = tempv1.x;
							end.y = tempv1.y;
							end.z = tempv1.z;
							edgebits = 2;
							break;
						}

						point1dist = POINT_TO_PLANE( &start, &plane );
						point2dist = POINT_TO_PLANE( &end, &plane );

						if (!(((point1dist > 0.0F) && (point2dist > 0.0F)) || ((point1dist < 0.0F) && (point2dist < 0.0F))))
						{	//store points of intersection here...
							distance2plane = (point1dist / (point1dist - point2dist));
							
							IntPoint.x = start.x + ( distance2plane * (end.x - start.x ) );
							IntPoint.y = start.y + ( distance2plane * (end.y - start.y ) );
							IntPoint.z = start.z + ( distance2plane * (end.z - start.z ) );

							point[intersection_points++] = IntPoint;

							if (!startset)
							{	scanline[scanlinenum].start = IntPoint;
								startset = TRUE;
							}else
							{
								scanline[scanlinenum].end = IntPoint;
								endset = TRUE;
							}

						}
					}
					
					scanline[scanlinenum].poly = *poly_ptr;
					
					if ((startset) && (endset))
						scanlinenum++;

					poly_ptr++;
				}
				for (i=0; i<scanlinenum; i++)
				{

					BikeLine[CurrentLine] = FindFreePoly();
						
   					if( BikeLine[CurrentLine] != (uint16) -1 )
					{
						LinesActive = TRUE;

						Polys[ BikeLine[CurrentLine] ].Col1.R = 255;
						Polys[ BikeLine[CurrentLine] ].Col1.G = 255;
						Polys[ BikeLine[CurrentLine] ].Col1.B = 255;
						Polys[ BikeLine[CurrentLine] ].Col2.R = 255;
						Polys[ BikeLine[CurrentLine] ].Col2.G = 255;
						Polys[ BikeLine[CurrentLine] ].Col2.B = 255;
	   					Polys[ BikeLine[CurrentLine] ].Col3.R = 255;
						Polys[ BikeLine[CurrentLine] ].Col3.G = 255;
   						Polys[ BikeLine[CurrentLine] ].Col3.B = 255;
   						Polys[ BikeLine[CurrentLine] ].Col4.R = 255;
						Polys[ BikeLine[CurrentLine] ].Col4.G = 255;
   						Polys[ BikeLine[CurrentLine] ].Col4.B = 255;
   						Polys[ BikeLine[CurrentLine] ].Trans1 = 255;
	   					Polys[ BikeLine[CurrentLine] ].Trans2 = 255;
	   					Polys[ BikeLine[CurrentLine] ].Trans3 = 255;
   						Polys[ BikeLine[CurrentLine] ].Trans4 = 255;
	   					Polys[ BikeLine[CurrentLine] ].Scale = 0.0F;
	   					Polys[ BikeLine[CurrentLine] ].Flags = POLY_FLAG_NOTHING;
   						Polys[ BikeLine[CurrentLine] ].Frm_Info = &Title_Fonts_Header;
	   					Polys[ BikeLine[CurrentLine] ].Frame = TextLookup[font][1];

						Polys[ BikeLine[CurrentLine] ].Pos1.x = Models[Model].Pos.x + (scanline[i].start.x - plane.Normal.x * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos1.y = Models[Model].Pos.y + (scanline[i].start.y - plane.Normal.y * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos1.z = Models[Model].Pos.z + (scanline[i].start.z - plane.Normal.z * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos4.x = Models[Model].Pos.x + (scanline[i].end.x - plane.Normal.x * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos4.y = Models[Model].Pos.y + (scanline[i].end.y - plane.Normal.y * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos4.z = Models[Model].Pos.z + (scanline[i].end.z - plane.Normal.z * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos3.x = Models[Model].Pos.x + (scanline[i].end.x + plane.Normal.x * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos3.y = Models[Model].Pos.y + (scanline[i].end.y + plane.Normal.y * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos3.z = Models[Model].Pos.z + (scanline[i].end.z + plane.Normal.z * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos2.x = Models[Model].Pos.x + (scanline[i].start.x + plane.Normal.x * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos2.y = Models[Model].Pos.y + (scanline[i].start.y + plane.Normal.y * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos2.z = Models[Model].Pos.z + (scanline[i].start.z + plane.Normal.z * (thickness / 2.0F));

						AddPolyToTPage( BikeLine[CurrentLine], GetTPage( *Polys[ BikeLine[CurrentLine] ].Frm_Info, (int16) Polys[ BikeLine[CurrentLine] ].Frame ) );

						CurrentLine++;
					}
					else
						return FALSE;
				}
			}

		}
	}else
	{
		mxheader = &ModelHeaders[ Models[Model].ModelNum];

		for( Group = 0; Group < mxheader->num_groups; Group++ )
		{
			for( ExecBuf = 0; ExecBuf < mxheader->Group[ Group ].num_execbufs; ExecBuf++ )
			{   
  
				num_polys = mxheader->Group[Group].num_polys_per_execbuf[ExecBuf];
				poly_ptr = mxheader->Group[Group].poly_ptr[ExecBuf];
				vertex_ptr = mxheader->Group[Group].org_vertpnt[ExecBuf];

				intersection_points = 0;
				scanlinenum = 0;


				for (poly=0; poly<num_polys; poly++)
				{
					tempv1.x = vertex_ptr[poly_ptr->v1].x;
					tempv1.y = vertex_ptr[poly_ptr->v1].y;
					tempv1.z = vertex_ptr[poly_ptr->v1].z;

					tempv2.x = vertex_ptr[poly_ptr->v2].x;
					tempv2.y = vertex_ptr[poly_ptr->v2].y;
					tempv2.z = vertex_ptr[poly_ptr->v2].z;

					tempv3.x = vertex_ptr[poly_ptr->v3].x;
					tempv3.y = vertex_ptr[poly_ptr->v3].y;
					tempv3.z = vertex_ptr[poly_ptr->v3].z;
					
					ApplyMatrix( &Mat_R, &tempv1, &tempv1 );
					ApplyMatrix( &Mat_R, &tempv2, &tempv2 );
					ApplyMatrix( &Mat_R, &tempv3, &tempv3 );

					/*
					tempv1.x *= SelectedBikeScale * scaleout; //* BikeSwapScale;
					tempv1.y *= SelectedBikeScale * scaleout; //* BikeSwapScale;
					tempv1.z *= SelectedBikeScale * scaleout; //* BikeSwapScale;
					tempv2.x *= SelectedBikeScale * scaleout; //* BikeSwapScale;
					tempv2.y *= SelectedBikeScale * scaleout; //* BikeSwapScale;
					tempv2.z *= SelectedBikeScale * scaleout; //* BikeSwapScale;
					tempv3.x *= SelectedBikeScale * scaleout; //* BikeSwapScale;
					tempv3.y *= SelectedBikeScale * scaleout; //* BikeSwapScale;
					tempv3.z *= SelectedBikeScale * scaleout; //* BikeSwapScale;
					*/

					tempv1.x *= HoloModelScale * scaleout; //* BikeSwapScale;
					tempv1.y *= HoloModelScale * scaleout; //* BikeSwapScale;
					tempv1.z *= HoloModelScale * scaleout; //* BikeSwapScale;
					tempv2.x *= HoloModelScale * scaleout; //* BikeSwapScale;
					tempv2.y *= HoloModelScale * scaleout; //* BikeSwapScale;
					tempv2.z *= HoloModelScale * scaleout; //* BikeSwapScale;
					tempv3.x *= HoloModelScale * scaleout; //* BikeSwapScale;
					tempv3.y *= HoloModelScale * scaleout; //* BikeSwapScale;
					tempv3.z *= HoloModelScale * scaleout; //* BikeSwapScale;
					
					startset = FALSE;
					endset = FALSE;

					for (edge = 0; edge < 3; edge++)
					{					 
						switch (edge)
						{
						case 0:
							start.x = tempv1.x;	  
							start.y = tempv1.y;
							start.z = tempv1.z;
							end.x = tempv2.x;
							end.y = tempv2.y;
							end.z = tempv2.z;
							edgebits = 1;
							break;
						case 1:
							start.x = tempv2.x;
							start.y = tempv2.y;
							start.z = tempv2.z;
							end.x = tempv3.x;
							end.y = tempv3.y;
							end.z = tempv3.z;
							edgebits = 4;
							break;
						case 2:
							start.x = tempv3.x;
							start.y = tempv3.y;
							start.z = tempv3.z;
							end.x = tempv1.x;
							end.y = tempv1.y;
							end.z = tempv1.z;
							edgebits = 2;
							break;
						}

						point1dist = POINT_TO_PLANE( &start, &plane );
						point2dist = POINT_TO_PLANE( &end, &plane );

						if (!(((point1dist > 0.0F) && (point2dist > 0.0F)) || ((point1dist < 0.0F) && (point2dist < 0.0F))))
						{	//store points of intersection here...
							distance2plane = (point1dist / (point1dist - point2dist));
							
							IntPoint.x = start.x + ( distance2plane * (end.x - start.x ) );
							IntPoint.y = start.y + ( distance2plane * (end.y - start.y ) );
							IntPoint.z = start.z + ( distance2plane * (end.z - start.z ) );

							point[intersection_points++] = IntPoint;

							if (!startset)
							{	scanline[scanlinenum].start = IntPoint;
								startset = TRUE;
							}else
							{
								scanline[scanlinenum].end = IntPoint;
								endset = TRUE;
							}

						}
					}
					
					scanline[scanlinenum].poly = *poly_ptr;
					
					if ((startset) && (endset))
						scanlinenum++;

					poly_ptr++;
				}
				for (i=0; i<scanlinenum; i++)
				{

					BikeLine[CurrentLine] = FindFreePoly();
						
   					if( BikeLine[CurrentLine] != (uint16) -1 )
					{
						LinesActive = TRUE;

						Polys[ BikeLine[CurrentLine] ].Col1.R = 255;
						Polys[ BikeLine[CurrentLine] ].Col1.G = 255;
						Polys[ BikeLine[CurrentLine] ].Col1.B = 255;
						Polys[ BikeLine[CurrentLine] ].Col2.R = 255;
						Polys[ BikeLine[CurrentLine] ].Col2.G = 255;
						Polys[ BikeLine[CurrentLine] ].Col2.B = 255;
	   					Polys[ BikeLine[CurrentLine] ].Col3.R = 255;
						Polys[ BikeLine[CurrentLine] ].Col3.G = 255;
   						Polys[ BikeLine[CurrentLine] ].Col3.B = 255;
   						Polys[ BikeLine[CurrentLine] ].Col4.R = 255;
						Polys[ BikeLine[CurrentLine] ].Col4.G = 255;
   						Polys[ BikeLine[CurrentLine] ].Col4.B = 255;
   						Polys[ BikeLine[CurrentLine] ].Trans1 = 255;
	   					Polys[ BikeLine[CurrentLine] ].Trans2 = 255;
	   					Polys[ BikeLine[CurrentLine] ].Trans3 = 255;
   						Polys[ BikeLine[CurrentLine] ].Trans4 = 255;
	   					Polys[ BikeLine[CurrentLine] ].Scale = 0.0F;
	   					Polys[ BikeLine[CurrentLine] ].Flags = POLY_FLAG_NOTHING;
   						Polys[ BikeLine[CurrentLine] ].Frm_Info = &Title_Fonts_Header;
	   					Polys[ BikeLine[CurrentLine] ].Frame = TextLookup[font][1];

						Polys[ BikeLine[CurrentLine] ].Pos1.x = Models[Model].Pos.x + (scanline[i].start.x - plane.Normal.x * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos1.y = Models[Model].Pos.y + (scanline[i].start.y - plane.Normal.y * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos1.z = Models[Model].Pos.z + (scanline[i].start.z - plane.Normal.z * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos4.x = Models[Model].Pos.x + (scanline[i].end.x - plane.Normal.x * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos4.y = Models[Model].Pos.y + (scanline[i].end.y - plane.Normal.y * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos4.z = Models[Model].Pos.z + (scanline[i].end.z - plane.Normal.z * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos3.x = Models[Model].Pos.x + (scanline[i].end.x + plane.Normal.x * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos3.y = Models[Model].Pos.y + (scanline[i].end.y + plane.Normal.y * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos3.z = Models[Model].Pos.z + (scanline[i].end.z + plane.Normal.z * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos2.x = Models[Model].Pos.x + (scanline[i].start.x + plane.Normal.x * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos2.y = Models[Model].Pos.y + (scanline[i].start.y + plane.Normal.y * (thickness / 2.0F));
						Polys[ BikeLine[CurrentLine] ].Pos2.z = Models[Model].Pos.z + (scanline[i].start.z + plane.Normal.z * (thickness / 2.0F));

						AddPolyToTPage( BikeLine[CurrentLine], GetTPage( *Polys[ BikeLine[CurrentLine] ].Frm_Info, (int16) Polys[ BikeLine[CurrentLine] ].Frame ) );

						CurrentLine++;
					}
					else
						return FALSE;
				}
			}

		}
	}
	
	return TRUE;
}

/*�������������������������������������������������������������������
	Procedure	:		Place title room objects into their correct positions
	Input		:		nothing
	Output		:		nothing
�������������������������������������������������������������������*/
void PlaceObjects(void)
{

	VECTOR Mtop, Mbot, Discs;
	int i;
	MATRIX Mat_R;

	Mtop.x = 0.0F; Mtop.y = 220.0F; Mtop.z = -158.0F;
	Mbot.x = 0.0F; Mbot.y = 35.0F; Mbot.z = -100.0F;
	CurrentVDUPos = RightVDU.Pos;
	VDUrot = RightVDU.StartRot;
									 
	Models[BackgroundModel[TITLE_MODEL_Mtop]].Pos = Mtop;
	Models[BackgroundModel[TITLE_MODEL_Mbot]].Pos = Mbot;
	Models[BackgroundModel[TITLE_MODEL_VDU]].Pos = CurrentVDUPos;
	Models[BackgroundModel[TITLE_MODEL_Bracket]].Pos = RightVDU.BracketPos;
	BracketRot = RightVDU.BracketStartRot;


	Models[BackgroundModel[TITLE_MODEL_Holopad]].Pos.x = Holopad.x;
	Models[BackgroundModel[TITLE_MODEL_Holopad]].Pos.y = Holopad.y - HolopadRange;
	Models[BackgroundModel[TITLE_MODEL_Holopad]].Pos.z = Holopad.z;

	BikePos.x = -501.0F;
	BikePos.y = Holopad.y + 100.0F;
	BikePos.z = Holopad.z;

  
	Models[BackgroundModel[TITLE_MODEL_HoloLight]].Pos.x = Holopad.x;
	Models[BackgroundModel[TITLE_MODEL_HoloLight]].Pos.y = Holopad.y - 2.0F;
	Models[BackgroundModel[TITLE_MODEL_HoloLight]].Pos.z = Holopad.z;


	OrigPos[TITLE_MODEL_Mtop] = Mtop;
	OrigPos[TITLE_MODEL_Mbot] = Mbot;

	for (i=0; i<=5; i++)
	{	Discs.x = 0.0F; Discs.y = (float)(i) * 28; Discs.z = -70.0F;
		Models[BackgroundModel[5 - i]].Pos = Discs;
		OrigPos[5 - i] = Discs;
	}

	stackpos[0] = Models[BackgroundModel[TITLE_MODEL_Mtop]].Pos;
	stackpos[1] = Models[BackgroundModel[TITLE_MODEL_Disc1]].Pos;
	stackpos[2] = Models[BackgroundModel[TITLE_MODEL_Disc2]].Pos;
	stackpos[3] = Models[BackgroundModel[TITLE_MODEL_Disc3]].Pos;
	stackpos[4] = Models[BackgroundModel[TITLE_MODEL_Disc4]].Pos;
	stackpos[5] = Models[BackgroundModel[TITLE_MODEL_Disc5]].Pos;
	stackpos[6] = Models[BackgroundModel[TITLE_MODEL_Disc6]].Pos;
	stackpos[7] = Models[BackgroundModel[TITLE_MODEL_Mbot]].Pos;
	
	// build rotate matrix...
	BuildRotMatrix(0.0F, VDUrot, 0.0F, &Mat_R);

	// rotate vdu...
	Models[BackgroundModel[TITLE_MODEL_VDU]].Mat = Mat_R;
	MatrixTranspose(&Mat_R, &Models[BackgroundModel[TITLE_MODEL_VDU]].InvMat);

	BuildRotMatrix(0.0F, BracketRot, 0.0F, &Mat_R);

	// rotate vdu...
	Models[BackgroundModel[TITLE_MODEL_Bracket]].Mat = Mat_R;
	MatrixTranspose(&Mat_R, &Models[BackgroundModel[TITLE_MODEL_Bracket]].InvMat);


	// build rotate matrix for holopad & light...
//	HoloRotx = 0.0F; HoloRoty = 0.0F; HoloRotz = 0.0F;
	HoloRotx = -6.0F; HoloRoty = 0.0F; HoloRotz = 3.0F;
	BuildRotMatrix(HoloRotx, HoloRoty, HoloRotz, &Mat_R);
	Models[BackgroundModel[TITLE_MODEL_Holopad]].Mat = Mat_R;
	MatrixTranspose(&Mat_R, &Models[BackgroundModel[TITLE_MODEL_Holopad]].InvMat);
	//Models[BackgroundModel[TITLE_MODEL_HoloLight]].Mat = Mat_R;
	//MatrixTranspose(&Mat_R, &Models[BackgroundModel[TITLE_MODEL_HoloLight]].InvMat);

	HoloLightBrightness = 0.0F;

	RotateDiscStack(MaxStackTheta);
}

/*�������������������������������������������������������������������
	Procedure	:		Expand / Contract discs, according to DiscExpandOut 
	Input		:		nothing...
	Output		:		nothing...
�������������������������������������������������������������������*/
void ExpandDiscs(void)
{

	int i, CurrentDisc;
	float dy;
	float *currentY;

	dy = 0.3F * framelag;
	
	for (i = 0; i <= 6; i++)
	{
		CurrentDisc = i;
		currentY = &Models[BackgroundModel[CurrentDisc]].Pos.y;
		if (DiscExpandOut)
			*currentY -= (dy * (i + 1) * 3.0F);
		else
			*currentY += (dy * (i + 1));
	}

	if ((DiscExpandOut) && (Models[BackgroundModel[TITLE_MODEL_Disc1]].Pos.y < (OrigPos[TITLE_MODEL_Disc1].y - DiscExpand)))
	{	for (i = 0; i <= 6; i++)
		{	CurrentDisc = i;
			Models[BackgroundModel[CurrentDisc]].Pos.y = (OrigPos[CurrentDisc].y - DiscExpand * (i + 1));
			StackY[i] = Models[BackgroundModel[CurrentDisc]].Pos.y;
		}
		DiscExpandOut = FALSE;
		StackStatus = DISC_WIGGLE;
	}

	if ((!DiscExpandOut) && (Models[BackgroundModel[TITLE_MODEL_Disc1]].Pos.y > OrigPos[TITLE_MODEL_Disc1].y))
	{	for (i = 0; i <= 6; i++)
		{	CurrentDisc = i;
			Models[BackgroundModel[CurrentDisc]].Pos.y = OrigPos[CurrentDisc].y;
		}
		StackStatus = DISC_NOTHING;
		DiscExpandOut = TRUE;
		RotateSetup = FALSE;
	}
}

/*�������������������������������������������������������������������
	Procedure	:		Wiggle all discs along the y axis after expanding...
	Input		:		nothing
	Output		:		nothing
�������������������������������������������������������������������*/
void WiggleDiscs(void)
{
	int i;

	DiscPauseTime += (framelag / (0.05F * 60.0F));

	if (DiscPauseTime >= 1.0F)
	{	DiscWiggleUp = (!DiscWiggleUp);
		DiscPauseTime = 0.0F;
		DiscWiggleDistance -= 1.0F;
		if (DiscWiggleDistance < 0.0F)
			DiscWiggleDistance = 0.0F;
	}

	for (i=0; i<=6; i++)
	{	if (DiscWiggleUp)
			Models[BackgroundModel[i]].Pos.y = StackY[i] + 0.143F * (i + 1) * DiscWiggleDistance;	//0.143 = 1/7
		else
			Models[BackgroundModel[i]].Pos.y = StackY[i];
	}

	if (DiscWiggleDistance <= 0.0F)
	{	DiscWiggleDistance = 0.0F;
		StackStatus = DISC_ROTATE;
	}

}


/*�������������������������������������������������������������������
	Procedure	:		Get a random speed for a disc
	Input		:		disc number...
	Output		:		nothing...
�������������������������������������������������������������������*/
void SetUpRotate(int disc)
{
	float rnd;

		rot[disc] = 0.0F; RotWiggle[disc] = 0; RotPause[disc] = 0.0F;
		Turned[disc] = !Turned[disc]; LastTurned[disc] = !Turned[disc];
		rnd	= (float)Random_Range(2000);
		if (rnd > 1000.0F)
		{	rnd = 1000.0F - rnd;
			rotspeed[disc] = rnd/1000.0F - 1.0F;
		}else{
			rotspeed[disc] = 1.0F + rnd/1000.0F;
		}
	
}

/*�������������������������������������������������������������������
	Procedure	:		Get next "judder" amount for a disc (after disc has rotated)
	Input		:		disc number
	Output		:		nothing
�������������������������������������������������������������������*/
void DiscJudder(int disc)
{
	float angle;
	float clockwise;;

	if (rot[disc] == 180)
		clockwise = 1.0F;
	else
		clockwise = -1.0F;

	RotPause[disc] += (framelag / (0.05F * 60.0F));

	if (RotPause[disc] >= 1.0F)
	{	RotWiggle[disc]++;
		if (RotWiggle[disc] > (Judders - 1))
			RotWiggle[disc] = (Judders - 1);
		RotPause[disc] = 0.0F;
	}

	angle = clockwise * JudderAngle[RotWiggle[disc]];

	if (Turned[disc])
		angle += 180.0F;

	BuildRotMatrix(0.0F, angle, 0.0F, &Models[BackgroundModel[disc]].Mat);
	MatrixTranspose(&Models[BackgroundModel[disc]].Mat, &Models[BackgroundModel[disc]].InvMat);

}

/*�������������������������������������������������������������������
	Procedure	:		RotateDiscs
	Input		:		disc number, OneOnly: ROTATE_DISC_All ( all discs )
											  ROTATE_DISC_DifficultyForward
											  ROTATE_DISC_DifficultyBack
	Output		:		nothing...
�������������������������������������������������������������������*/
void RotateDiscs(int disc, int OneOnly)
{
	float angleoffset, viewangle, x, y;

	x = View.x;
	y = -70.0F - View.z;

	viewangle = -(float)ATAND ( y, x);

		rot[disc] += ( (framelag/ (rotspeed[disc] * DiscSpeed * 60.0F)) * 180.0F);

		if (rot[disc] >= 180.0F)
			rot[disc] = 180.0F;
		if (rot[disc] <= -180.0F)
			rot[disc] = -180.0F;

		if (Turned[disc] != LastTurned[disc])
		{	if ( (rot[disc] >= viewangle) || (rot[disc] <= (viewangle - 180.0F)) )
			{  		
				switch ( OneOnly )
				{
				case ROTATE_DISC_All:
					PolyAnim[disc]->newframe = CurrentTextures[disc];
					break;
				case ROTATE_DISC_DifficultyForward:
					PolyAnim[disc]->newframe = PolyAnim[disc]->currentframe + 2;
					if (PolyAnim[disc]->newframe > 11)
						PolyAnim[disc]->newframe = 5;
					CurrentTextures[disc] = PolyAnim[disc]->newframe - 1;
					break;
				case ROTATE_DISC_DifficultyBack:
					PolyAnim[disc]->newframe = PolyAnim[disc]->currentframe - 2;
					if (PolyAnim[disc]->newframe < 5)
						PolyAnim[disc]->newframe = 11;
					CurrentTextures[disc] = PolyAnim[disc]->newframe - 1;
					break;
				}
				Turned[disc] = (!Turned[disc]);
			}
		}

		if ((rot[disc] != 180.0F) && (rot[disc] != -180.0F))
		{ 	if (Turned[disc])
				angleoffset = 180.0F;
			else
				angleoffset = 0.0F;
		  
			BuildRotMatrix(0.0F, rot[disc] + angleoffset, 0.0F, &Models[BackgroundModel[disc]].Mat);
			MatrixTranspose(&Models[BackgroundModel[disc]].Mat, &Models[BackgroundModel[disc]].InvMat);
		}else
		 	DiscJudder(disc);
}

/*�������������������������������������������������������������������
	Procedure	:		step through complete disc rotation sequence for all discs...
	Input		:		nothing
	Output		:		nothing
�������������������������������������������������������������������*/
void RotateAllDiscs(void)
{

	int i, count;
	static BOOL onceonly = FALSE;


	switch (StackStatus)
		{
		case DISC_EXPAND:
			if ( !onceonly )
			{
				PlaySfx( SFX_StakAnimates, 1.0F );
				onceonly = TRUE;
			}
			SetTextures(CurrentMenu);
		   	ExpandDiscs();
			break;
		case DISC_WIGGLE:
			WiggleDiscs();
			break;
		case DISC_ROTATE:
			if (!RotateSetup)
			{	for (i = 0; i <=5; i++)
					SetUpRotate(i);
				RotateSetup = TRUE;
			}

			for (i=0; i<=5; i++)
				RotateDiscs(i, ROTATE_DISC_All );

			count = 0;
			for (i = 0; i <= 5; i++)
			{	if (RotWiggle[i] == (Judders - 1))
				count++;
			}
			if (count == 6)
			{	StackStatus = DISC_RETRACT;
			}
			break;
		case DISC_RETRACT:
			ExpandDiscs();
			break;
		case DISC_NOTHING:
			StackMode = DISC_MODE_NONE;
			DiscWiggleDistance = 4.0F;
			onceonly = FALSE;
		}

}


/*�������������������������������������������������������������������
	Procedure	:		step through complete disc rotation sequence for one disc...
	Input		:		nothing
	Output		:		nothing
�������������������������������������������������������������������*/
void RotateOneDisc(int disc)
{

	static BOOL onceonly = FALSE;
	
	switch (StackStatus)
	{
	case DISC_EXPAND:
		if ( !onceonly )
		{
			PlaySfx( SFX_StakAnimates, 1.0F );
			onceonly = TRUE;
		}
		ExpandDiscs();
		break;
	case DISC_WIGGLE:
		WiggleDiscs();
		break;
	case DISC_ROTATE:
		if (!RotateSetup)
				SetUpRotate(disc);
			RotateSetup = TRUE;

		RotateDiscs(disc, DifficultyDir );

		if (RotWiggle[disc] == (Judders - 1))
		 	StackStatus = DISC_RETRACT;
		
		break;
	case DISC_RETRACT:
		ExpandDiscs();
		break;
	case DISC_NOTHING:
		StackMode = DISC_MODE_NONE;
		DiscWiggleDistance = 4.0F; 
		onceonly = FALSE;
		break;
	}
}


void MorphHoloLight(void)
{
	int i;
	uint16 Model = BackgroundModel[TITLE_MODEL_HoloLight];
	uint16 Group = 0;
	uint16 ExecBuf = 0;

	float maxY = 10.0F;
	float dy, intensity;

	static float theta = 0.0F;

	theta += (float)((framelag/(0.75F * 60.0F)) * 90.0F);

	if (theta > 360.0F)
		theta -= 360.0F;

	for (i=0; i<24; i++)
	{
	dy = (float)SIND(theta + (i * 15)) * maxY;
	IncreaseVertexY(Model, Group, ExecBuf, HoloMorphVerts[i], dy);
	intensity = 1.0F - (((float)SIND(theta + (i * 15)) + 1.0F)/2.0F * 0.4F);
	TintOneVertex( Model, Group, ExecBuf, HoloTintVerts[i], intensity, intensity, intensity, 1.0F );
	
	} 
}

BOOL IncreaseVertexY(uint16 Model, uint16 Group, uint16 ExecBuf, int VertexNo, float IncreaseBy)
{

	D3DEXECUTEBUFFERDESC	DstDebDesc;
	LPD3DLVERTEX			DstlpD3DLVERTEX;
	MXLOADHEADER	*		DstMloadheader;
	D3DLVERTEX		    *		VertPtr;
	DstMloadheader = &ModelHeaders[ Model ];

	memset( &DstDebDesc, 0, sizeof(D3DEXECUTEBUFFERDESC) );
	DstDebDesc.dwSize = sizeof(D3DEXECUTEBUFFERDESC);
	if( DstMloadheader->Group[ Group ].lpExBuf[ ExecBuf ]->lpVtbl->Lock(
					DstMloadheader->Group[ Group ].lpExBuf[ ExecBuf ], &DstDebDesc ) != D3D_OK ) return FALSE;

	DstlpD3DLVERTEX = &((LPD3DLVERTEX) DstDebDesc.lpData)[VertexNo];

	
	VertPtr = &(DstMloadheader->Group[Group].org_vertpnt[ExecBuf])[VertexNo];
	
	DstlpD3DLVERTEX->y = VertPtr->y + IncreaseBy;
	
	if( DstMloadheader->Group[ Group ].lpExBuf[ ExecBuf ]->lpVtbl->Unlock(
					DstMloadheader->Group[ Group ].lpExBuf[ ExecBuf] ) != D3D_OK )	return FALSE;
   	
	return TRUE;

}

void RotateHoloLight(void)
{
	MATRIX Mat_Rx, Mat_Ry, Mat_Rz, Mat_temp, Mat_res;

	HoloRoty += 0.75F * framelag;
	
	if (HoloRoty > 360.0F)
		HoloRoty -= 360.0F;

	BuildRotMatrix(HoloRotx, 0.0F, 0.0F, &Mat_Rx);
	BuildRotMatrix(0.0F, HoloRoty, 0.0F, &Mat_Ry);
	BuildRotMatrix(0.0F, 0.0F, HoloRotz, &Mat_Rz);

	MatrixMultiply(&Mat_Rz, &Mat_Ry, &Mat_temp);
	MatrixMultiply(&Mat_Rx, &Mat_temp, &Mat_res);

	
	Models[BackgroundModel[TITLE_MODEL_HoloLight]].Mat = Mat_res;
	MatrixTranspose(&Mat_res, &Models[BackgroundModel[TITLE_MODEL_HoloLight]].InvMat);

}

void PulsateVDU(void)
{
	static float theta = 0.0F;
	float tintamount;
	int RightVertices[4] = {12, 13, 14, 15};
	int LeftVertices[4] = {8, 9, 10, 11};
	int *UseThese;
	int i;

	if (CameraStatus == CAMERA_AtRightVDU)
		UseThese = RightVertices;
	else
		UseThese = LeftVertices;

	
	theta += (float)((framelag/(1.0 * 60.0F)) * 90.0F);

	if (theta > 360.0F)
		theta -= 360.0F;

	for (i=0; i<4; i++)
	{
	tintamount = 1.0F - (((float)SIND(theta + i * 90.0F) + 1.0F)/2.0F * 0.6F); 
	TintOneVertex( BackgroundModel[TITLE_MODEL_VDU], 0, 1, UseThese[i], tintamount,tintamount,tintamount, 1.0F );
	}

}

extern LPDPLCONNECTION glpdplConnection;
extern LPDPSESSIONDESC2 glpdpSD;            // current session description


void InitHoloPad( void );
void KillHoloModel( void );
void LoadHoloModel( uint16 model );
void ScaleHoloModel( float scale );
void ShowHoloModel( uint16 model );
void ProcessHoloModel( void );

uint8 QuickStart = QUICKSTART_None; 

/*�������������������������������������������������������������������
	Procedure	:		Title Display...

	Input		:		nothing...
	Output		:		BOOL TRUE/FALSE
�������������������������������������������������������������������*/
BOOL DisplayTitle(void)
{
	uint16 i;
	LPDIRECTDRAW lpDD = d3dapp->lpDD;
	LPDIRECT3D lpD3D = d3dapp->lpD3D;
	LPDIRECT3DDEVICE lpDev = d3dapp->lpD3DDevice;
    LPDIRECT3DVIEWPORT lpView = d3dapp->lpD3DViewport;
	uint16	group;
	MENUITEM *Item;
	LIST *l;

#ifdef SOFTWARE_ENABLE
/*-----------------------------------------------------------------------------
		Chris Walsh's Code
-----------------------------------------------------------------------------*/
	if( SoftwareVersion )
	{
		CWInTitle = 1;
		CWClearZBuffer();
	}

/*---------------------------------------------------------------------------*/
#endif
	
#ifndef SELF_PLAY
	if (!InitialTexturesSet && CameraStatus != CAMERA_AtStart)
	{
		InitialTexturesSet = TRUE;

	   	for (i=0; i<6; i++)
		{
			Mxloadheader[i] = &ModelHeaders[BackgroundModel[i]];
			PolyAnim[i] = Mxloadheader[i]->Group[0].polyanim[0];
			PolyAnim[i]->newframe = CurrentTextures[i];
			PolyAnim[i]->State = TEXTUREANIM_Stop;
		}

		if ((CurrentDiscHighlight >= 0) && (CurrentDiscHighlight < 6))
       			HighlightDisc(CurrentDiscHighlight);

	}
#endif

	NumOfTransExe = 0;

	if( TitleOnceOnly )
	{
		BikeList.items = MAXBIKETYPES - 1;
		
		InitShipActionList();

		AttractModeCountDown = ATTRACTMODECOUNTVALUE;
		
	// make a version number for this game
		CreateVersion();
	    // open/create Condemned registry key 
		if ( !ghCondemnedKey )
		{
#ifndef SELF_PLAY
#ifdef FINAL_RELEASE
			RegOpenKeyEx(REGISTRY_ROOT_KEY,
				REGISTRY_GAME_KEY,
				0,
				KEY_ALL_ACCESS,
				&ghCondemnedKey
				);
#else
			RegCreateKeyEx(REGISTRY_ROOT_KEY,
							REGISTRY_GAME_KEY,
							0,
							NULL,                   
							REG_OPTION_NON_VOLATILE,
							KEY_ALL_ACCESS,
							NULL,
							&ghCondemnedKey,
							&gdwCondemnedDisp
							);
#endif
#endif
			// init all levels to find out if any are on CD
			InitLevels( SINGLEPLAYER_LEVELS );
			InitLevels( MULTIPLAYER_LEVELS );
		}
		TitleOnceOnly = FALSE;
		WhoIAm = (uint8) -1;

		InitScreenFonts();

		if ( LaunchedByLobby() )
		{
			if ( !InitLevels( MULTIPLAYER_LEVELS )  )
			{
				//Msg( "No multiplayer levels" );
				PrintErrorMessage (LT_NoLevelsInstalled, 0, NULL, ERROR_QUIT );
			}

			GetMultiplayerPrefs();
			
			InitStartMenu( NULL );
			IsLobbyLaunched = TRUE;
			CameraStatus = CAMERA_AtLeftVDU;
			StackMode = DISC_MODE_NONE;
			StackStatus = DISC_NOTHING;
			if ( IsHost )
			{
				MenuRestart( &MENU_NEW_CreateLobbyGame );
				StackMode = DISC_MODE_NONE;
				StackStatus = DISC_NOTHING;

				if ( LobbyAutoStart )
				{
					StartAHostSession ( &StartLobbyGameItem );
				}
			}else
			{
				DebugPrintf("about to enter lobby game as client\n");
				MenuRestart( &MENU_NEW_LobbyWaitingForHost );
				StackMode = DISC_MODE_NONE;
				StackStatus = DISC_NOTHING;
				ContinueLobbyLaunch();
				DebugPrintf("ContinueLobbyLaunch OK\n");
			}
		}else
		{
			IsLobbyLaunched = FALSE;

			if ( CurrentMenu == &MENU_NEW_Error )
			{
				CameraStatus = CAMERA_AtLeftVDU;
				StackMode = DISC_MODE_NONE;
				StackStatus = DISC_NOTHING;
			}
		}
	}

	if (!TitleInitDone && (( MyGameStatus == STATUS_Title ) || ( MyGameStatus == STATUS_BetweenLevels )))
	{	DarkenRoomForStart( NULL );
		TitleInitDone = TRUE;
		NoTeamSelect = FALSE;
		SetFOV( START_FOV );	// in case player was using nitro when finishing level!
#ifdef SOFTWARE_ENABLE
		if( SoftwareVersion )
		{
			if( MyGameStatus == STATUS_Title )
				ScanAllBikes();
		}
#endif
		if (UseNewMenus)
			MENU_Start = MENU_NEW_Start;

		if ( !IsLobbyLaunched )
		{
			switch ( QuickStart )
			{
			case QUICKSTART_Start:

				InitStartMenu( NULL );
				CameraStatus = CAMERA_AtLeftVDU;
				StackMode = DISC_MODE_NONE;
				StackStatus = DISC_NOTHING;
				
				MENU_Start = MENU_NEW_ChooseConnectionToStart;
				
				MenuRestart( &MENU_Start );
				StackMode = DISC_MODE_NONE;
				StackStatus = DISC_NOTHING;

				if ( ServiceProviderSet )
					SelectConnectionToStart( NULL );
				break;
			case QUICKSTART_Join:
				InitStartMenu( NULL );
				CameraStatus = CAMERA_AtLeftVDU;
				StackMode = DISC_MODE_NONE;
				StackStatus = DISC_NOTHING;
				
				MENU_Start = MENU_NEW_ChooseConnectionToJoin;
				
				MenuRestart( &MENU_Start );
				StackMode = DISC_MODE_NONE;
				StackStatus = DISC_NOTHING;
				
				if ( ServiceProviderSet )
					SelectConnectionToJoin( NULL );
				break;
			case QUICKSTART_SelectSession:
				InitStartMenu( NULL );
				CameraStatus = CAMERA_AtLeftVDU;
				StackMode = DISC_MODE_NONE;
				StackStatus = DISC_NOTHING;
				
				MENU_Start = MENU_NEW_ChooseConnectionToJoin;
				
				MenuRestart( &MENU_Start );
				StackMode = DISC_MODE_NONE;
				StackStatus = DISC_NOTHING;
				
				if ( ServiceProviderSet )
					SelectConnectionToJoin( NULL );
				else
					PrintErrorMessage( UNABLE_TO_CONNECT_TO_SERVICE_PROVIDER, 0, NULL, ERROR_QUIT );  

				if ( !AutoJoinSession() )
					PrintErrorMessage( UNABLE_TO_JOIN_SESSION, 0, NULL, ERROR_QUIT );  

				break;
			case QUICKSTART_Server:
				InitStartMenu( NULL );
				CameraStatus = CAMERA_AtLeftVDU;
				StackMode = DISC_MODE_NONE;
				StackStatus = DISC_NOTHING;
				
				MENU_Start = MENU_NEW_ChooseConnectionToStartServer;
				
				MenuRestart( &MENU_Start );
				StackMode = DISC_MODE_NONE;
				StackStatus = DISC_NOTHING;

				if ( ServiceProviderSet )
				{
					SelectConnectionToStartServer( NULL );
					GetLastGameInfo();	// for level name
					StartAHostSessionServer( NULL );
				}

				return TRUE;
			case QUICKSTART_Notify:
   				InitStartMenu( NULL );
				CameraStatus = CAMERA_AtLeftVDU;
				StackMode = DISC_MODE_NONE;
				StackStatus = DISC_NOTHING;
				
				MENU_Start = MENU_NEW_Notify;
				
				MenuRestart( &MENU_Start );
				StackMode = DISC_MODE_NONE;
				StackStatus = DISC_NOTHING;
				break;
			default:
				if ( MyGameStatus != STATUS_BetweenLevels )
					MenuRestart( &MENU_Start );
			}
		}
	}

#if 0
	VduHeader = &ModelHeaders[BackgroundModel[TITLE_MODEL_VDU]];
	//VduAnim = VduHeader->Group[0].polyanim[0];
	//VertPtr = VduAnim->vert;

	for (i=0; i<4; i++)
	{
		TvVerts[i] = *VertPtr++;
	}
#endif

	// initialise sfx
	for( i = 0 ; i < MAX_SFX ; i++ )
	{
		LastDistance[i] = 100000.0F;
	}

	CheckForRogueSfx();

	if ( ModeCase != -1 )
	{
#ifdef Z_TRICK
		if ( !ZClearsOn )
		{
			g_OddFrame = !g_OddFrame;
			SetZProj();
			if( !SetZCompare() )
			{
				Msg("unable to set z compare\n");
				return FALSE;
			}
		}
#endif
		//Set up camera
		MakeViewMatrix(&View, &Look, &Up, &CurrentCamera.Mat);
		MatrixTranspose( &CurrentCamera.Mat, &CurrentCamera.InvMat );
		CurrentCamera.Pos = View;
		CurrentCamera.GroupImIn = -1;
		CurrentCamera.Viewport = viewport;	
		CurrentCamera.Viewport.dwX = 0;
		CurrentCamera.Viewport.dwY = 0;
		CurrentCamera.Viewport.dwWidth = d3dapp->szClient.cx;
		CurrentCamera.Viewport.dwHeight = d3dapp->szClient.cy;
		CurrentCamera.Viewport.dvScaleX = CurrentCamera.Viewport.dwWidth / (float)2.0;
		CurrentCamera.Viewport.dvScaleY = CurrentCamera.Viewport.dwHeight / (float)2.0;
		CurrentCamera.Viewport.dvMaxX = (float)D3DDivide(D3DVAL(CurrentCamera.Viewport.dwWidth),
										  D3DVAL(2 * CurrentCamera.Viewport.dvScaleX));
		CurrentCamera.Viewport.dvMaxY = (float)D3DDivide(D3DVAL(CurrentCamera.Viewport.dwHeight),
										   D3DVAL(2 * CurrentCamera.Viewport.dvScaleY));

		
		
		TloadCheckForLostSurfaces(&Tloadheader);

		
		Build_View();
		CurrentCamera.View = view;

		if (lpDev->lpVtbl->BeginScene(lpDev) != D3D_OK)
		{
			Msg( "DisplayTitle() : BeginScene failed\n" );
			return FALSE;
		}

		if (lpDev->lpVtbl->SetMatrix(lpDev, hView, &view) != D3D_OK)
		{
			Msg( "DisplayTitle() : SetMatrix failed\n" );
			return FALSE;
		}

		if( d3dapp->lpD3DViewport->lpVtbl->SetViewport(d3dapp->lpD3DViewport, &CurrentCamera.Viewport) != D3D_OK )
		{
#ifdef DEBUG_VIEWPORT
			SetViewportError( "DisplayTitle", &CurrentCamera.Viewport, D3D_OK );
#else
			Msg( "DisplayTitle() : SetViewport failed\n" );
#endif
			return FALSE;
		}

		if (ClearBuffers( TRUE, FALSE ) != TRUE )
		{
			Msg( "DisplayTitle() : ClearBuffers failed\n" );
			return FALSE;
		}

		// Translucent PolySort....
		if( !InitPolySort() )
		{
			Msg( "DisplayTitle() : InitPolySort failed\n" );
			return FALSE;
		}

		// reset all the normal execute status flags...
	#ifdef SOFTWARE_ENABLE
		if( SoftwareVersion )
		{
			CWExecute2( lpDev, lpD3DNormCmdBuf, lpView , D3DEXECUTE_CLIPPED );
		}
		else
	#endif
		{
			lpDev->lpVtbl->Execute(lpDev, lpD3DNormCmdBuf, lpView , D3DEXECUTE_CLIPPED);
		}

		if( !ModelDisp( 0, lpDev, TitleModelSet ) )
		{
			return FALSE;
		}

	/*
		Display 0 solid Clipped Non Faceme Transluecent Polys
	*/
			if( !bPolySort )
			{
				if( !DisplaySolidGroupClippedPolys( RenderBufs[ 1 ], 0, lpDev, lpView ) )
						return FALSE;
#if 0
	/*
		Display 0 solid Clipped Faceme Transluecent Polys
	*/
				if( !DisplaySolidGroupClippedFmPolys( RenderBufs[ 1 ], 0, lpDev, lpView ) )
						return FALSE;
#endif

//				ExecuteTransExe( 0 );
			}

		// set all the Translucent execute status flags...
	#ifdef SOFTWARE_ENABLE
		if( SoftwareVersion )
		{
			CWExecute2( lpDev, lpD3DTransCmdBuf, lpView , D3DEXECUTE_CLIPPED );
		}
		else
	#endif
		{
			lpDev->lpVtbl->Execute(lpDev, lpD3DTransCmdBuf, lpView , D3DEXECUTE_CLIPPED);
		}

//		ExecuteTransExe( 0 );
//		ExecuteTransExeUnclipped( 0 );
		

		// set all the Translucent execute status flags...
	#ifdef SOFTWARE_ENABLE
		if( SoftwareVersion )
		{
			CWExecute2( lpDev, lpD3DTransCmdBuf, lpView , D3DEXECUTE_CLIPPED);
		}
		else
	#endif
		{
			lpDev->lpVtbl->Execute(lpDev, lpD3DTransCmdBuf, lpView , D3DEXECUTE_CLIPPED);
		}

		// display clipped translucencies
		{
	/*�������������������������������������������������������������������
		Display 0 Clipped Non Faceme Transluecent Polys
	�������������������������������������������������������������������*/
			if( !bPolySort )
			{
				if( !DisplayGroupClippedPolys( RenderBufs[ 1 ], 0, lpDev, lpView ) )
						return FALSE;

	/*�������������������������������������������������������������������
		Display 0 Clipped Faceme Transluecent Polys
	�������������������������������������������������������������������*/
				if( !DisplayGroupClippedFmPolys( RenderBufs[ 1 ], 0, lpDev, lpView ) )
						return FALSE;

				ExecuteTransExe( 0 );
				ExecuteTransExeUnclipped( 0 );
			}
	
			
			
			else
			{
				i = FirstFmPolyUsed;
				while( i != (uint16) -1 )
				{
		 			PVR_FmPolyDispGroup( 0, &i );
				}

				i = FirstPolyUsed;
				while( i != (uint16) -1 )
				{
					PVR_PolyDispGroup( 0, &i );
				}
			}
		}
	/*�������������������������������������������������������������������
		Display Non 0 Clipped Faceme Transluecent Polys
	�������������������������������������������������������������������*/
		if( !bPolySort )
		{
			if( !DisplayGroupUnclippedFmPolys( RenderBufs[ 1 ], lpDev, lpView ) )
					return FALSE;

	/*�������������������������������������������������������������������
		Display Non 0 Clipped Non Faceme Transluecent Polys
	�������������������������������������������������������������������*/
			if( !DisplayGroupUnclippedPolys( RenderBufs[ 0 ], lpDev, lpView ) )
					return FALSE;
		}
		
		// Translucent Poly Sorted Display...
		if( !PolyListExecute() )
		{
			Msg( "DisplayTitle() : PolyListExecute failed\n" );
			return FALSE;
		}

	/*�������������������������������������������������������������������
		Display Transluecent Screen Polys
	�������������������������������������������������������������������*/
		if( !bPolySort )
		{
			if( !DisplayNonSolidScrPolys( RenderBufs[ 1 ], lpDev, lpView ) )
				return FALSE;
		}
		else
		{
			while( i != (uint16) -1 )
			{
				PVR_ScreenPolysDisp( &i );
			}
		}

	/*�������������������������������������������������������������������
	Display Opaque Lines
	�������������������������������������������������������������������*/
	#ifdef SOFTWARE_ENABLE
		if( !SoftwareVersion )
	#endif
		{
			group = (uint16)-1;

#ifndef FINAL_RELEASE
			i = FirstLineUsed;
			while( i != (uint16) -1 )
			{
				if( LinesDispGroup( group, RenderBufs[ 0 ], &i ) )
				{
					if( lpDev->lpVtbl->Execute(lpDev, RenderBufs[ 0 ], lpView, D3DEXECUTE_CLIPPED ) != D3D_OK )
						return FALSE;
				}
			}
#endif
		}

		// reset all the normal execute status flags...
	#ifdef SOFTWARE_ENABLE
		if( SoftwareVersion )
		{
			CWExecute2( lpDev, lpD3DNormCmdBuf, lpView , D3DEXECUTE_CLIPPED);
		}
		else
	#endif
		{
			lpDev->lpVtbl->Execute(lpDev, lpD3DNormCmdBuf, lpView , D3DEXECUTE_CLIPPED);
		}

	/*�������������������������������������������������������������������
		Display Solid Screen Polys
	�������������������������������������������������������������������*/
		BilinearSolidScrPolys = TRUE;

		if( !DisplaySolidScrPolys( RenderBufs[ 1 ], lpDev, lpView ) )
			return FALSE;

	/*�������������������������������������������������������������������
	Display Solid Lines
	�������������������������������������������������������������������*/
	#ifdef SOFTWARE_ENABLE
		if( !SoftwareVersion )
	#endif
		{
			group = (uint16)-1;

#ifndef FINAL_RELEASE
			i = FirstLineUsed;
			while( i != (uint16) -1 )
			{
				if( LinesDispGroup( group, RenderBufs[ 0 ], &i ) )
				{
					if( lpDev->lpVtbl->Execute(lpDev, RenderBufs[ 0 ], lpView, D3DEXECUTE_CLIPPED ) != D3D_OK )
						return FALSE;
				}
			}
#endif
		}

		if (lpDev->lpVtbl->EndScene(lpDev) != D3D_OK)
		{
			Msg( "DisplayTitle() : EndScene failed\n" );
			return FALSE;
		}

		ScreenPolyProcess();

		PulsateVDU();
		RotateHoloLight();

	}
	
	switch (StackMode)
	{
	case DISC_MODE_ALL:
		RotateAllDiscs();
		break;
	case DISC_MODE_ONE:
		RotateOneDisc(TITLE_MODEL_Disc3);
		break;
	}



#if 0
	if ( IsKeyPressed( DIK_NUMPAD0 ) )
	{
		TitleReset( NULL );
	}
#endif


	

/****************************************/
	ProcessHoloModel();
	GetTitleMessage();
/*******************
Event handling
*******************/
	ProcessTimers();
	ProcessEvents();

#ifdef MULTIPLE_READINPUTS
	ReadInput();
#endif
	
	//MorphHoloLight();
	
#ifdef SOFTWARE_ENABLE
	if( !SoftwareVersion ) ProcessTextItems();
#else
	ProcessTextItems();
#endif

	//Our_CalculateFrameRate();

	if( CurrentMenu && CurrentMenuItem )
	{
		if(( CurrentMenu == &MENU_ChooseSessionToJoin ) || (CurrentMenu == &MENU_NEW_ChooseSessionToJoin))
		{
			if( (SessionsList.selected_item != -1) && SessionsRefresh[SessionsList.selected_item] && OKToJoinSession)
			{
				SelectSession( NULL );
			}
			else
			{
				GetCurrentSessions_ReScan( NULL );
			}
		}
//#ifndef SELF_PLAY
  		if (MyGameStatus == STATUS_Copyright)
		{
			if (SplashInfo[CurrentSplashScreen][FLAGS] & SPLASH_FLAG_PressReturn)
				MenuDraw( CurrentMenu );
		}else
			MenuDraw( CurrentMenu );
//#else
//		if (SplashInfo[CurrentSplashScreen][FLAGS] & SPLASH_FLAG_PressReturn)
//			MenuDraw( CurrentMenu );
//#endif

		if (!WasteAFrame)
		{
			MenuItemDrawCursor( CurrentMenuItem );
		
			MenuProcess();
		}else
		{	NewMenuSelectMode(NULL);
			WasteAFrame = FALSE;
		}
	}else{
		if( MyGameStatus == STATUS_Copyright)
			MenuRestart( &MENU_Copyright );
		if( MyGameStatus == STATUS_Title )
			MenuRestart( &MENU_Start );
		
		SetFOV(START_FOV);
	}

	if (CurrentMenu)
	{
  		for( Item = CurrentMenu->Item ; Item->x >= 0 ; Item++ )
		{	
			//if( Item->highlightflags & TEXTFLAG_RefreshList)
			if ( (Item->FuncDraw == DrawFlatMenuList) || (Item->FuncDraw == DrawSplitMenuList) )
			{	
				l = (LIST *)(Item->Variable);

				if ( l->FuncInfo )
					l->FuncInfo( l );
				
				AddToFlatMenuList( Item );
			}
		}
	}

	return TRUE;
}

static int SelectionColour( void )
{
	static int colour_table[ 16 ] =
	{
		0, 1, 2, 3, 4, 5, 6, 7, 7, 6, 5, 4, 3, 2, 1, 0
	};
	return colour_table[ ( GetTickCount() / ( 14 * 4 ) ) & 15 ];
}

/*�������������������������������������������������������������������
	Procedure	:		Menu restart...
	Input		:		MENU * ...
	Output		:		Nothing
�������������������������������������������������������������������*/
void MenuRestart( MENU * Menu )
{
	if ( MyGameStatus == STATUS_SinglePlayer )
	{
		PauseAllSfx();
	}
	
	FramesIgnored = 0;
	memset( BufferedKey, 0, sizeof( DWORD ) * DINPUT_BUFFERSIZE );
	// flush the keyboard buffer...
	ReadBufferedKeyboard();
	NumKeysToProcess = 0;
	
	if ( !QuickStart )
	{
		if ((CameraStatus == CAMERA_AtDiscs) || (CameraStatus == CAMERA_AtLeftVDU) || (CameraStatus == CAMERA_AtRightVDU))
		{	StackMode = DISC_MODE_ALL;
	 		StackStatus = DISC_EXPAND;
			DoHighlight = TRUE;
		}
	}

	if (((CameraStatus == CAMERA_AtLeftVDU) || (CameraStatus == CAMERA_AtRightVDU)) && LastMenu )
	{
		VduClear();
	}

	MenuStackLevel = 0;
	LastMenu = CurrentMenu;
	CurrentMenu = Menu;
	CurrentMenuItem = CurrentMenu->Item;
	while ( !CurrentMenuItem->FuncSelect && (CurrentMenuItem->x >= 0 ) )
	{
		CurrentMenuItem++;
	}
	if ( CurrentMenu->FuncEntry )
	{
		CurrentMenu->FuncEntry( CurrentMenu );
	}
	MenuState = MENUSTATE_Select;
	
}


/*�������������������������������������������������������������������
	Procedure	:		Menu exit (backing out nicely)...
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void MenuExit( void )
{
	while ( MenuStackLevel >= 0 && CurrentMenu )
	{
		MenuBack();
	}
	MenuState = MENUSTATE_Select;
}

/*�������������������������������������������������������������������
	Procedure	:		Menu abort (immediately)...
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void MenuAbort( void )
{
	if ( (CameraStatus == CAMERA_AtLeftVDU || CameraStatus == CAMERA_AtRightVDU) && CurrentMenu )
	{
	   	LastMenu = CurrentMenu;
		VduClear();
	}

	CurrentMenu = NULL;			   
	CurrentMenuItem = NULL;
	MenuStackLevel = 0;
	MenuState = MENUSTATE_Select;
	OldMenuStatus = 0;
}

/*�������������������������������������������������������������������
	Procedure	:		Draw the Name in a menu item...
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void	MenuItemDrawName( MENUITEM * Item )
{
	int	x;
	int	y;
	static int col = 2;

#ifdef SELF_PLAY
	static float pause = 0.0F;

	if ( MyGameStatus == STATUS_Copyright )
	{
		pause += framelag;

		if ( pause >= 10.0F )
		{
			col++;
			pause -= 10.0F;
		}

		if ( col > 8 )
			col = 0;
	}else
		col = 2;

#endif

	if ( Item->StrPnt )
	{
		x = (int) ( ( Item->x >> 1 ) * ModeScaleX[ModeCase] );
		y = (int) ( ( Item->y >> 1 ) * ModeScaleY[ModeCase] );

		Print4x5Text( Item->StrPnt , x , y , col );
	}
}


/*�������������������������������������������������������������������
	Procedure	:		Draw the Name in a paged menu item...
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void	MenuItemDrawPageName( MENUITEM * Item )
{
	int	x;
	int	y;
	static int col = 2;
	int page;

#ifdef SELF_PLAY
	static float pause = 0.0F;

	if ( MyGameStatus == STATUS_Copyright )
	{
		pause += framelag;

		if ( pause >= 10.0F )
		{
			col++;
			pause -= 10.0F;
		}

		if ( col > 8 )
			col = 0;
	}else
		col = 2;

#endif

	page = (int) Item->Value;
	if ( Item->StrPnt && page == CurrentPage )
	{
		x = (int) ( ( Item->x >> 1 ) * ModeScaleX[ModeCase] );
		y = (int) ( ( Item->y >> 1 ) * ModeScaleY[ModeCase] );

		Print4x5Text( Item->StrPnt , x , y , col );
	}
}



void DrawKeyDefPage( MENUITEM * Item )
{
	static char page[ 80 ];
	int	x;
	int	y;
	static int col = 0;

	sprintf( page, LT_PageNo, CurrentPage + 1, MaxPage );
	x = (int) ( ( Item->x >> 1 ) * ModeScaleX[ModeCase] );
	y = (int) ( ( Item->y >> 1 ) * ModeScaleY[ModeCase] );
	if ( MaxPage > 1 )
	{
		if ( !CurrentPage )
			strcat( page, LT_PageDown );
		else if ( CurrentPage < MaxPage - 1 )
			strcat( page, LT_PageUpDown );
		else
			strcat( page, LT_PageUp );
	}
	Print4x5Text( page, x, y, col );
}



void DrawKeyDefHelp1( MENUITEM * Item )
{
	static char help[ 80 ];
	int	x;
	int	y;
	static int col = 0;
	char *keyname;

	if ( CurrentMenuItem && CurrentMenuItem->FuncSelect == SelectKeyDef )
	{
		keyname = (char *) CurrentMenuItem->StrPnt;
		if ( MenuState == MENUSTATE_Keydef )
		{
			sprintf( help, LT_PressKey/*"press key or button for %s"*/, keyname );
		}
		else
		{
			DEFKEY *kdef;

			kdef = (DEFKEY *) CurrentMenuItem->Variable;
			if ( kdef->def->keys > 1 )
			{
				if ( kdef->selected_key < 1 )
					sprintf( help, LT_ViewAlternateKeys, keyname );
				else if ( kdef->selected_key < kdef->def->keys - 1 )
					sprintf( help, LT_ViewAlternateKeys/*"[left/right]=view alternate keys for %s"*/, keyname );
				else
					sprintf( help, LT_ViewAlternateKeys2, keyname );
			}
			else
			{
				help[ 0 ] = 0;
			}
		}
	}
	else
	{
		sprintf( help, LT_SelectControl/*"[up/down]=select control"*/ );
	}
	x = (int) ( ( Item->x >> 1 ) * ModeScaleX[ModeCase] );
	y = (int) ( ( Item->y >> 1 ) * ModeScaleY[ModeCase] );
	CenterPrint4x5Text( help, y, col );
}



void DrawKeyDefHelp2( MENUITEM * Item )
{
	static char help[ 80 ];
	int	x;
	int	y;
	static int col = 0;
	char *keyname;

	if ( CurrentMenuItem && CurrentMenuItem->FuncSelect == SelectKeyDef )
	{
		keyname = (char *) CurrentMenuItem->StrPnt;
		if ( MenuState == MENUSTATE_Keydef )
		{
			sprintf( help, LT_Cancel/*"[esc]=cancel"*/ );
		}
		else
		{
#ifdef KEY_ENTER_AT_EMPTY_ADDS_KEYDEF
			sprintf( help, LT_Edit/*"[enter]=edit, [del]=remove key for %s"*/, keyname );
#else
			sprintf( help, LT_Add/*"[enter]=add, [del]=remove key for %s"*/, keyname );
#endif
		}
	}
	else
	{
		help[ 0 ] = 0;
	}
	x = (int) ( ( Item->x >> 1 ) * ModeScaleX[ModeCase] );
	y = (int) ( ( Item->y >> 1 ) * ModeScaleY[ModeCase] );
	CenterPrint4x5Text( help, y, col );
}


#define HELP_MAX	64

#define UNCONNECTED1 LT_Unconnected1/*" is not connected"*/
#define UNCONNECTED2 LT_Unconnected2/*" unconnected"*/
#define DUPLICATE_SEP	"+"
#define ABBREVIATED	"..."

void DrawKeyDefHelp3( MENUITEM * Item )
{
	static char help[ HELP_MAX * 2 ];
	int	x;
	int	y;
	static int col = 0;
	char *keyname;

	help[ 0 ] = 0;
	if ( CurrentMenuItem && CurrentMenuItem->FuncSelect == SelectKeyDef )
	{
		if ( MenuState != MENUSTATE_Keydef )
		{
			DEFKEY *kdef;
			int duplicates;
			VirtualKeycode keycode;
			char *keyword;
			MENUITEM *item;
			int help_length;
			int k;
			int joystick;

			kdef = (DEFKEY *) CurrentMenuItem->Variable;
			if ( kdef->def->keys )
			{
				keycode = kdef->def->key[ kdef->selected_key ];
				if ( keycode )
				{
					if ( KEY_ON_JOYSTICK( keycode )
						&& ( ( joystick = KEY_JOYSTICK( keycode ) ) >= 0 )
						&& ( joystick < Num_Joysticks )
						&& !JoystickInfo[ joystick ].connected )
					{
						strncpy( help, JoystickInfo[ KEY_JOYSTICK( keycode ) ].Name, HELP_MAX );
						help[ HELP_MAX - 1 ] = 0;
						if ( strlen( help ) + strlen( UNCONNECTED1 ) < HELP_MAX )
							strcat( help, UNCONNECTED1 );
						else if ( strlen( help ) + strlen( UNCONNECTED2 ) < HELP_MAX )
							strcat( help, UNCONNECTED2 );
					}
					else
					{
						keyword = (char *) key_name( keycode );
						if ( keyword )
						{
							duplicates = 0;
							sprintf( help, LT_AlsoControls/*"[%s] also controls "*/, keyword );
							for ( item = &MENU_Keyboard.Item[ 0 ]; item->x >= 0; item++ )
							{
								if ( item->FuncDraw == DrawKeyDef && item != CurrentMenuItem )
								{
									kdef = (DEFKEY *) item->Variable;
									for ( k = 0; k < kdef->def->keys; k++ )
									{
										if ( kdef->def->key[ k ] == keycode )
										{
											keyname = (char *) item->StrPnt;
											help_length = strlen( help ) + strlen( keyname );
											if ( duplicates )
												help_length += strlen( DUPLICATE_SEP );
											if ( help_length < HELP_MAX )
											{
												if ( duplicates++ )
													strcat( help, DUPLICATE_SEP );
												strcat( help, keyname );
											}
											else
											{
												help_length = strlen( help );
												if ( help_length + 1 < HELP_MAX  )
													strncat( help, "+"ABBREVIATED, HELP_MAX - 1 - help_length );
												else
													strcpy( help + HELP_MAX - 4, ABBREVIATED );
												help[ HELP_MAX - 1 ] = 0;
											}
											break;
										}
									}
								}
							}
							if ( !duplicates )
								help[ 0 ] = 0;
						}
					}
				}
			}
		}
	}
	if ( help[ 0 ] )
	{
		x = (int) ( ( Item->x >> 1 ) * ModeScaleX[ModeCase] );
		y = (int) ( ( Item->y >> 1 ) * ModeScaleY[ModeCase] );
		CenterPrint4x5Text( help, y, col );
	}
}



/*�������������������������������������������������������������������
	Procedure	:		Draw the Name and string variable in a menu item...
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void DrawNameVar( MENUITEM * Item )
{
	int	x;
	int	y;
	char *var;

	x = (int) ( ( Item->x >> 1 ) * ModeScaleX[ModeCase] );
	y = (int) ( ( Item->y >> 1 ) * ModeScaleY[ModeCase] );

	Print4x5Text( Item->StrPnt , x , y , 2 );
	var = (char *)(Item->Variable);
	Print4x5Text( var, -1 , y , 1 );

}

void DrawCenteredNameVar( MENUITEM * Item )
{
	int	x;
	int	y;
	char *var;

	x = (int) ( ( Item->x >> 1 ) * ModeScaleX[ModeCase] );
	y = (int) ( ( Item->y >> 1 ) * ModeScaleY[ModeCase] );

	var = (char *)(Item->Variable);
	CenterPrint4x5Text( var, y, 5 );
}



/*�������������������������������������������������������������������
	Procedure	:		Draw the help key and description in a menu item...
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void	DrawHelpKey( MENUITEM * Item )
{
	int	x;
	int	y;
	char *key;

	x = (int) ( ( Item->x >> 1 ) * ModeScaleX[ModeCase] );
	y = (int) ( ( Item->y >> 1 ) * ModeScaleY[ModeCase] );

	key = (char *)(Item->Value);
	if ( key )
		Print4x5Text( key, x , y , 1 );
	x = (int) ( ( ( Item->x + 64 ) >> 1 ) * ModeScaleX[ModeCase] );
	Print4x5Text( Item->StrPnt , x, y , 2 );
}



/*�������������������������������������������������������������������
	Procedure	:		Menu Draw..draws the title and all other text..
	Input		:		MENU * Menu...
	Output		:		Nothing
�������������������������������������������������������������������*/
void MenuDraw( MENU * Menu )
{
	MENUITEM * Item;
	int	y;

	y = (int) ( ( 80 >> 1 ) * ModeScaleY[ModeCase] );

	if ( Menu->MenuFuncDraw )
		Menu->MenuFuncDraw ( &DiscStatus);

	//if ( (CameraStatus != CAMERA_AtDiscs) && (CameraStatus != CAMERA_AtVDU))
	if (CameraStatus == CAMERA_AtStart)
		CenterPrint4x5Text( Menu->Name , y , 2 );

	// only use menu item draw functions if not at VDU
	if ((CameraStatus != CAMERA_AtLeftVDU) && (CameraStatus != CAMERA_AtRightVDU))
	{
		for( Item = Menu->Item ; Item->x >= 0 ; Item++ )
		{
			if( Item->FuncDraw )

			{
				Item->FuncDraw( Item );
			}
		}
	}


}


void MenuChangeEx( MENU *Menu )
{
	MENUITEM Item;

	memset( &Item, 0, sizeof( MENUITEM ) );
	Item.Value = ( void *)Menu;
	MenuChange( &Item );
}

/*�������������������������������������������������������������������
	Procedure	:		Menu Change...
	Input		:		MENUI
	TEM * ITEM...
	Output		:		Nothing
�������������������������������������������������������������������*/
void MenuChange( MENUITEM * Item )
{
	
	MenuState = MENUSTATE_Select;
	
	DoHighlight = TRUE;	//menu has changed, therefore ensure option is highlighted

	VduProcessed = FALSE;

	PanDone = FALSE;

	OldMenuStatus = CurrentMenu->MenuStatus;

	if ( MenuStackLevel < MAXMENULEVELS )
	{
		MenuStack[ MenuStackLevel ] = CurrentMenu;
		MenuItemStack[ MenuStackLevel ] = CurrentMenuItem;
		LastMenu = CurrentMenu;
		MenuStackLevel++;
		CurrentMenu = (MENU*) Item->Value;


		// Animate discs if neccesary
		if ((CurrentMenu->MenuStatus == TITLE_TIMER_ChooseDiscPan) && (OldMenuStatus == TITLE_TIMER_ChooseDiscPan))
																	      
		{	StackMode = DISC_MODE_ALL;
			StackStatus = DISC_EXPAND;
		}

				 
		CurrentMenuItem = CurrentMenu->Item;
		while ( !CurrentMenuItem->FuncSelect && (CurrentMenuItem->x >= 0 ) )
		{
			CurrentMenuItem++;
		}
		NoMenuBack = FALSE;
		if ( CurrentMenu->FuncEntry && !IgnoreMenuFuncs)
		{
			CurrentMenu->FuncEntry( CurrentMenu );
		}

		// Process VDU if neccessary
		if ( ((CameraStatus == CAMERA_AtLeftVDU) || (CameraStatus == CAMERA_AtRightVDU)) && VDU_Ready)
		{
			VduClear();
			ProcessVduItems(CurrentMenu);
			//VDU_Ready = FALSE;
			LastMenuItem = NULL;
		}
	}

}

/*�������������������������������������������������������������������
	Procedure	:		Menu Change back a level...
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void MenuBack()
{
	if ( MyGameStatus == STATUS_BetweenLevels )
		return;

	if ( NoMenuBack )
		return;
	
	if ( MenuStackLevel )
	{
	   	if ( !InTitleRoom )
			PlayCursorSfx();
			
		DoHighlight = TRUE;	//menu has changed, therefore ensure option is highlighted

		VduProcessed = FALSE;

		PanDone = FALSE;

		OldMenuStatus = CurrentMenu->MenuStatus;
	
		// if going back to old menu system...
		if ( CurrentMenu == &MENU_NEW_Start ) 
		{	CameraStatus = CAMERA_AtStart;
		}
	
			
		if ( CurrentMenu->FuncExit && !IgnoreMenuFuncs)
		{
			CurrentMenu->FuncExit( CurrentMenu );
			if (!CurrentMenu)
				return;
		}

		MenuStackLevel--;
		if ( MenuStackLevel < 0 )
		{
			MenuStackLevel = 0;
			return;
		}
		LastMenu = CurrentMenu;
		CurrentMenu = MenuStack[ MenuStackLevel ];
		CurrentMenuItem = MenuItemStack[ MenuStackLevel ];

		if (CurrentMenu == &MENU_Copyright)
			CameraStatus = CAMERA_AtStart;

		if (CameraStatus == CAMERA_AtDiscs)
			SetTextures(CurrentMenu);

		// Animate discs if neccesary
		if ((OldMenuStatus == TITLE_TIMER_ChooseDiscPan) && (CurrentMenu->MenuStatus == TITLE_TIMER_ChooseDiscPan))
		{	StackMode = DISC_MODE_ALL;
			StackStatus = DISC_EXPAND;
		}

 		// Process VDU if neccessary
		if ((CameraStatus == CAMERA_AtLeftVDU) || (CameraStatus == CAMERA_AtRightVDU))
		{
			VduClear();
			ProcessVduItems(CurrentMenu);
			//VDU_Ready = FALSE;
			LastMenuItem = NULL;
		}

	}
	else if ( CurrentMenu )
	{
		if ( CurrentMenu->FuncExit && !IgnoreMenuFuncs)
		{
			CurrentMenu->FuncExit( CurrentMenu );
		}

		LastMenu = CurrentMenu;
		VduClear();

		CurrentMenu = NULL;
		CurrentMenuItem = NULL;

		if ( ( MyGameStatus == STATUS_Title ) && ( QuickStart ) )
		{
			TitleReset( NULL );
		}

		if ( MyGameStatus == STATUS_SinglePlayer )
		{
			ReTriggerSfx();
		}

		// ensure cheat message is not displayed next time in menus
		FlashTextActive = 0.0F;
	}
}

void MenuBackSpecific( MENU *Menu, BOOL UseExitFuncs )
{
	IgnoreMenuFuncs = !UseExitFuncs;
	
	while( ( CurrentMenu != Menu ) && ( CurrentMenu != &MENU_Start ) )
		MenuBack();

	IgnoreMenuFuncs = FALSE;
}

/*�������������������������������������������������������������������
	Procedure	:		Menu item for Change back a level...
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void MenuItemBack( MENUITEM *item )
{
	MenuBack();
}


/*�������������������������������������������������������������������
	Procedure	:		Draw the Name in a menu item...
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void	SetDifficulty( MENUITEM * Item )
{
}



/*�������������������������������������������������������������������
	Procedure	:		Draw the Name in a menu item...
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void	MenuItemDrawCursor( MENUITEM * Item )
{
	int	x;
	int	y;
	
	switch (CameraStatus)
	{
	case CAMERA_AtDiscs:
		if (((CurrentDiscHighlight != Item->y) || DoHighlight) && (StackStatus == DISC_NOTHING))
		{	if (CurrentDiscHighlight != -1)
				ResetDisc(CurrentDiscHighlight);
			CurrentDiscHighlight = Item->y;
			HighlightDisc(CurrentDiscHighlight);
			DoHighlight = FALSE;
		} 
		break;
	case CAMERA_AtStart:
		if ( MenuState != MENUSTATE_Select && MenuState != MENUSTATE_SelectKeydef )
			return;
		x = (int) ( ( ( Item->x - 18 ) >> 1 ) * ModeScaleX[ModeCase] );
		y = (int) ( ( Item->y >> 1 ) * ModeScaleY[ModeCase] );
		
		if ( !( Item->highlightflags & TEXTFLAG_AutoSelect ) ) 
			Print4x5Text( "0" , x , y , 0 );
		break;
	}

		
}

/*�������������������������������������������������������������������
	Procedure	:		Cursor Movement Functions...
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void PlayCursorSfx( void )
{
	if ( InTitleRoom )
	{
		if ( CameraStatus == CAMERA_AtDiscs )
			PlaySfx( SFX_MoveStackOption, 1.0F );
		else
			PlaySfx( SFX_VidText, 1.0F );
	}else
		PlaySfx( SFX_VidText, 1.0F );
}

BOOL ItemSelectable( MENUITEM *item )
{
	if (item->highlightflags & TEXTFLAG_Unselectable)
		return FALSE;

	if ( NoTeamSelect && ( item->highlightflags & TEXTFLAG_TeamItem ) )
		return FALSE;

	return TRUE;
}

void CursorUp()
{
	int x;
	int y;
	MENUITEM *next;
	MENUITEM *wrap;
	MENUITEM *item;

	

	x = CurrentMenuItem->x;
	y = CurrentMenuItem->y;

	next = NULL;
	wrap = NULL;
	for ( item = CurrentMenu->Item; item->x >= 0; item++ )
	{
		if ( item->FuncSelect && ItemSelectable( item ) )
		{
			if ( ( item != CurrentMenuItem ) &&	( item->y < y ) &&
				( !next || ( ( abs( item->y - y ) + ( abs( item->x - x ) ) <= ( abs( next->y - y ) + abs( next->x - x ) ) ) ) ) )
			{
				next = item;
			}
			if ( !wrap || ( ( item->y >= wrap->y ) && ( abs( item->x - x ) <= abs( wrap->x - x ) ) ) )
			{
				wrap = item;
			}
		}
	}
	if ( next )
	{
		CurrentMenuItem = next;
		PlayCursorSfx();
	}
	else
	{
		if ( wrap )
		{
			CurrentMenuItem = wrap;
			PlayCursorSfx();

		}
	}
}

void CursorDown()
{
		int x;
		int y;
		MENUITEM *next;
		MENUITEM *wrap;
		MENUITEM *item;

		
	
		x = CurrentMenuItem->x;
		y = CurrentMenuItem->y;
		next = NULL;
		wrap = NULL;
		for ( item = CurrentMenu->Item; item->x >= 0; item++ )
		{
			if ( item->FuncSelect && ItemSelectable( item ) )
			{
				if ( ( item != CurrentMenuItem ) &&	( item->y > y ) &&
					( !next || ( ( abs( item->y - y ) + ( abs( item->x - x ) ) <= ( abs( next->y - y ) + abs( next->x - x ) ) ) ) ) )
				{
					next = item;
				}
				if ( !wrap || ( ( item->y <= wrap->y ) && ( abs( item->x - x ) <= abs( wrap->x - x ) ) ) )
				{
					wrap = item;
				}
			}
		}
		if ( next )
		{
			CurrentMenuItem = next;
			PlayCursorSfx();

		}
		else
		{
			if ( wrap )
			{
				CurrentMenuItem = wrap;
				PlayCursorSfx();
			}
		}
	
}


void CursorLeft()
{
	int x;
	int y;
	MENUITEM *next;
	MENUITEM *wrap;
	MENUITEM *item;

	

	x = CurrentMenuItem->x;
	y = CurrentMenuItem->y;
	next = NULL;
	wrap = NULL;
	for ( item = CurrentMenu->Item; item->x >= 0; item++ )
	{
		if ( item->FuncSelect && ItemSelectable( item ) )
		{
			if ( ( item != CurrentMenuItem ) &&	( item->x < x ) &&
				( !next || ( ( abs( item->y - y ) + ( abs( item->x - x ) ) <= ( abs( next->y - y ) + abs( next->x - x ) ) ) ) ) )
			{
				next = item;
			}
			if ( !wrap || ( ( item->x >= wrap->x ) && ( abs( item->y - y ) <= abs( wrap->y - y ) ) ) )
			{
				wrap = item;
			}
		}
	}
	if ( next )
	{
		CurrentMenuItem = next;
		PlayCursorSfx();

	}
	else
	{
		if ( wrap )
		{
			CurrentMenuItem = wrap;
		}
	}
}

void CursorRight()
{
	int x;
	int y;
	MENUITEM *next;
	MENUITEM *wrap;
	MENUITEM *item;

	

	x = CurrentMenuItem->x;
	y = CurrentMenuItem->y;
	next = NULL;
	wrap = NULL;
	for ( item = CurrentMenu->Item; item->x >= 0; item++ )
	{
		if ( item->FuncSelect && ItemSelectable( item ) )
		{
			if ( ( item != CurrentMenuItem ) &&	( item->x > x ) &&
				( !next || ( ( abs( item->y - y ) + ( abs( item->x - x ) ) <= ( abs( next->y - y ) + abs( next->x - x ) ) ) ) ) )
			{
				next = item;
			}
			if ( !wrap || ( ( item->x <= wrap->x ) && ( abs( item->y - y ) <= abs( wrap->y - y ) ) ) )
			{
				wrap = item;
			}
		}
	}
	if ( next )
	{
		CurrentMenuItem = next;
		PlayCursorSfx();

	}
	else
	{
		if ( wrap )
		{
			CurrentMenuItem = wrap;
		}
	}
}


void CursorHome()
{
	int x;
	int y;
	MENUITEM *next;
	MENUITEM *item;

	
	
	x = CurrentMenuItem->x;
	y = CurrentMenuItem->y;
	next = NULL;
	for ( item = CurrentMenu->Item; item->x >= 0; item++ )
	{
		if ( item->FuncSelect && ItemSelectable( item ) )
		{
			if ( !next || ( ( item->x <= next->x ) && ( item->y <= next->y ) ) )
			{
				next = item;
			}
		}
	}
	if ( next )
	{
		CurrentMenuItem = next;
		PlayCursorSfx();
	}
}


void CursorEnd()
{
	int x;
	int y;
	MENUITEM *next;
	MENUITEM *item;

	

	x = CurrentMenuItem->x;
	y = CurrentMenuItem->y;
	next = NULL;
	for ( item = CurrentMenu->Item; item->x >= 0; item++ )
	{
		if ( item->FuncSelect && ItemSelectable( item ) )
		{
			if ( !next || ( ( item->x >= next->x ) && ( item->y >= next->y ) ) )
			{
				next = item;
			}
		}
	}
	if ( next )
	{
		CurrentMenuItem = next;
		PlayCursorSfx();
	}
}


void CursorSearch( char *keyword )
{
	int x;
	int y;
	MENUITEM *next;
	MENUITEM *wrap;
	MENUITEM *item;
	int keyword_len;

	

	if ( !keyword )
		return;
	keyword_len = strlen( keyword );
	if ( !keyword_len )
		return;
	x = CurrentMenuItem->x;
	y = CurrentMenuItem->y;
	next = NULL;
	wrap = NULL;
	for ( item = CurrentMenu->Item; item->x >= 0; item++ )
	{
		if ( item->FuncSelect  && ItemSelectable( item ) )
		{
			if ( ( ( item->x > x ) || ( item->y > y ) )
				&& ( !next || ( ( abs( item->x - x ) + abs( item->y - y ) ) <= ( abs( next->x - x ) + abs( next->y - y ) ) ) )
				&& item->StrPnt && !_strnicmp( item->StrPnt, keyword, keyword_len ) )
			{
				next = item;
			}
			if ( ( ( item->x < x ) || ( item->y < y ) )
				&& ( !wrap || ( ( abs( item->x - x ) + abs( item->y - y ) ) >= ( abs( wrap->x - x ) + abs( wrap->y - y ) ) ) )
				&& item->StrPnt && !_strnicmp( item->StrPnt, keyword, keyword_len ) )
			{
				wrap = item;
			}
		}
	}
	if ( next )
	{
		CurrentMenuItem = next;
		PlayCursorSfx();

	}
	else if ( wrap )
	{
		CurrentMenuItem = wrap;
		PlayCursorSfx();
	}
	else
	{
		SearchKey( 0 );
	}
}


static VirtualKeycode *KeyDefined( USERCONFIG *cfg, VirtualKeycode key )
{
	USERKEY *keydef;
	int j;

	for ( keydef = &cfg->up; keydef < &cfg->select_secondary[ MAX_SECONDARY_WEAPONS ]; keydef++ )
	{
		for ( j = 0; j < keydef->keys; j++ )
		{
			if ( keydef->key[ j ] == key )
				return &keydef->key[ j ];
		}
	}

	return NULL;
}


static void
DefineKey( MENUITEM *item, VirtualKeycode key )
{
	VirtualKeycode *kdef;//, *other_kdef;

	kdef = (VirtualKeycode *)(item->Variable);
	//other_kdef = KeyDefined( &Config, key );
	//if ( other_kdef )
	//{
	//	*other_kdef = *kdef;
	//}
	*kdef = key;
}




BOOL ProcessKeydef( int Key )
{
	BOOL done;
	int KeyDefNo;
	MENUITEM *Item, *nextitem;

	done = FALSE;
	switch( Key )
	{
	case DIK_ESCAPE:
	case DIK_F1:
	case DIK_F2:
	case DIK_F3:
	case DIK_F4:
	case DIK_F5:
	case DIK_F6:
	case DIK_F7:
	case DIK_F8:
	case DIK_F9:
	case DIK_F10:
	case DIK_F11:
	case DIK_F12:
		done = TRUE; // back out of key definition mode if illegal key selected
		break;
	default:
		if ( Key )
		{
			if ( KeyItem->Variable )
			{
				DefineKey( KeyItem, (VirtualKeycode) Key );
			}
			done = TRUE;
		}
		break;
	}



	nextitem = CurrentMenu->Item;

	for ( KeyDefNo = 0; KeyDefNo <= CurrentKeyDef; KeyDefNo++)
	{
		for( Item = nextitem; Item->x >= 0; Item++ )
		{	
			if (Item->FrameNo == KeyDefLines[KeyDefNo])
			{
				CurrentKeyDef--;
				nextitem = Item;	
				break;
			}
		}
	}





	return !done;
}


static void KeySelect( DEFKEY *kdef, int key )
{
	int k;

	if ( !key )
		return;
	for ( k = 0; k < kdef->def->keys; k++ )
	{
		if ( kdef->def->key[ k ] == key )
			kdef->selected_key = k;
	}
}


static void
KeyDeleteRepeating( DEFKEY *kdef )
{
	int j, k;

	for ( j = 0; j < kdef->def->keys; )
	{
		if ( !kdef->def->key[ j ] )
			KeyDelete( kdef, j );
		else
		{
			for ( k = j + 1; k < kdef->def->keys; )
			{
				if ( kdef->def->key[ j ] == kdef->def->key[ k ] )
					KeyDelete( kdef, k );
				else
					k++;
			}
			j++;
		}
	}

	for ( k = kdef->def->keys; k < MAX_KEYS_PER_CONTROL; k++ )
	{
		kdef->def->key[ k ] = (VirtualKeycode) 0;
	}
}

static void
KeyDelete( DEFKEY *kdef, int key )
{
	int k;

	for ( k = key; k < kdef->def->keys - 1; k++ )
	{
		kdef->def->key[ k ] = kdef->def->key[ k + 1 ];
	}
	while ( k < MAX_KEYS_PER_CONTROL )
	{
		kdef->def->key[ k++ ] = (VirtualKeycode) 0;
	}
	if ( kdef->def->keys > 0 )
		kdef->def->keys--;
	if ( kdef->def->keys > 0 )
	{
		if ( kdef->selected_key >= kdef->def->keys )
			kdef->selected_key = kdef->def->keys - 1;
	}
	else
	{
		kdef->selected_key = 0;
	}
}


static void
KeyDefine( MENUITEM *item, VirtualKeycode key )
{
	DEFKEY *kdef;

	kdef = (DEFKEY *)(item->Variable);
	if ( kdef )
	{
		if ( key )
		{
			kdef->def->key[ kdef->selected_key ] = key;
			if ( KEY_ON_JOYSTICK( key ) )
			{
				int joystick;

				joystick = KEY_JOYSTICK( key );
				if ( joystick >= 0 && joystick < Num_Joysticks && JoystickInfo[ joystick ].connected )
				{
					JoystickInfo[ joystick ].assigned = TRUE;
				}
			};
			PlaySfx( SFX_InGameMenuSelect, 1.0F );
		}
		else
		{
			if ( !kdef->def->key[ kdef->selected_key ] )
			{
				KeyDelete( kdef, kdef->selected_key );
			}
			PlayCursorSfx();
		}
		KeyDeleteRepeating( kdef );
		KeySelect( kdef, key );
	}
}



BOOL ProcessDefKey( int Key )
{
	BOOL done;

	done = FALSE;
	switch( Key )
	{
	case DIK_ESCAPE:
	case DIK_F1:
	case DIK_F2:
	case DIK_F3:
	case DIK_F4:
	case DIK_F5:
	case DIK_F6:
	case DIK_F7:
	case DIK_F8:
	case DIK_F9:
	case DIK_F10:
	case DIK_F11:
	case DIK_F12:
		if ( KeyItem->Variable )
			KeyDefine( KeyItem, (VirtualKeycode) 0 );
		done = TRUE; // back out of key definition mode if illegal key selected
		break;
	default:
		if ( !Key )
			Key = WhichMousePressed();
		if ( !Key )
			Key = WhichJoystickPressed();
		if ( Key )
		{
			if ( KeyItem->Variable )
			{
				KeyDefine( KeyItem, (VirtualKeycode) Key );
			}
			done = TRUE;
		}
		break;
	}

	return !done;
}


void SetKeyDefPage( int page )
{
	MENUITEM *item;

	CurrentPage = page;
	MaxPage = MAX_KEYDEF_PAGES;
	for ( item = MENU_Keyboard.Item; item->x >= 0; item++ )
	{
		if ( item->FuncDraw == DrawKeyDef )
		{
			item->FuncSelect = ( (int) item->Value == CurrentPage ) ? SelectKeyDef : NULL;
		}
	}
	CurrentMenuItem = CurrentMenu->Item;
	while ( !CurrentMenuItem->FuncSelect && (CurrentMenuItem->x >= 0 ) )
	{
		CurrentMenuItem++;
	}
}

void InitKeyDefPage( MENU *Menu )
{
	SetKeyDefPage( 0 );
	MenuState = MENUSTATE_SelectKeydef;
}


void InitKeyDef( MENU *Menu )
{
	MenuState = MENUSTATE_SelectKeydef;
}


BOOL ProcessSlider( int Key )
{
	BOOL done, redraw;
	SLIDER *slider;
	MenuItemFunc set_fn;

	slider = (SLIDER *)SliderItem->Variable;
	
	done = FALSE;
	redraw = FALSE;
	switch( Key )
	{
	case DIK_LEFT:
		PlayCursorSfx();
		slider->oldvalue = slider->value;
		DecrementSlider( SliderItem );
		redraw = TRUE;
		break;
	case DIK_RIGHT:
		PlayCursorSfx();
		slider->oldvalue = slider->value;
		IncrementSlider( SliderItem );
		redraw = TRUE;
		break;
	case DIK_HOME:
		PlayCursorSfx();
		slider->oldvalue = slider->value;
		SliderHome( SliderItem );
		redraw = TRUE;
		break;
	case DIK_END:
		PlayCursorSfx();
		slider->oldvalue = slider->value;
		SliderEnd( SliderItem );
		redraw = TRUE;
		break;
	case DIK_RETURN:
		done = TRUE;
		break;
	case DIK_ESCAPE:
		slider->oldvalue = slider->value;
		SliderCancel( SliderItem );
		done = TRUE;
		redraw = TRUE;
		break;
	default:
		break;
	}

	if (done )
	{
		if ( SliderItem->Value )
		{
			set_fn = (MenuItemFunc)(SliderItem->Value);
			set_fn ( SliderItem );
		}
	}


	return !done;
}

BOOL ProcessSlider2( int Key )
{
	BOOL done, redraw, refresh;
	SLIDER *slider;
	MenuItemFunc set_fn;

	slider = (SLIDER *)SliderItem->Variable;
	
	done = FALSE;
	redraw = FALSE;
	refresh = FALSE;
	switch( Key )
	{
	case DIK_LEFT:
		PlayCursorSfx();
		slider->oldvalue = slider->value;
		DecrementSlider( SliderItem );
		SliderSet( SliderItem );
		redraw = TRUE;
		break;
	case DIK_RIGHT:
		PlayCursorSfx();
		slider->oldvalue = slider->value;
		IncrementSlider( SliderItem );
		SliderSet( SliderItem );
		redraw = TRUE;
		break;
/*
	case DIK_HOME:
		slider->oldvalue = slider->value;
		SliderHome( SliderItem );
		SliderSet( SliderItem );
		redraw = TRUE;
		break;
	case DIK_END:
		slider->oldvalue = slider->value;
		SliderEnd( SliderItem );
		SliderSet( SliderItem );
		redraw = TRUE;
		break;
*/
	case DIK_HOME:
		CursorHome();
		done = TRUE;
		break;
	case DIK_END:
		CursorEnd();
		done = TRUE;
		break;
	case DIK_UP:
		CursorUp();
		done = TRUE;
		break;
	case DIK_DOWN:
		CursorDown();
		done = TRUE;
		break;
	case DIK_ESCAPE:
		MenuBack();
		done = TRUE;
		break;
	case DIK_RETURN:
		refresh = TRUE;
		break;
	default:
		if ( Key )
		{
			char *c;
			c = (char *) key_name( Key );
			if ( c && strlen( c ) == 1 )
			{
				CursorSearch( SearchKey( *c ) );
				if (CurrentMenuItem != SliderItem)
				{
					done = TRUE;
				}
			}
		}
		break;
	}

	if ( ( refresh ) || ( CurrentMenuItem != SliderItem ) )
	{
		if ( slider->FuncRefresh )
		{
			slider->FuncRefresh( slider );
		}
	}


	if (redraw && ((CameraStatus == CAMERA_AtLeftVDU) || (CameraStatus == CAMERA_AtRightVDU)))
	{
		slider->redraw_req = TRUE;
	}

	if (done || redraw)
	{
		if ( SliderItem->Value )
		{
			set_fn = (MenuItemFunc)(SliderItem->Value);
			set_fn ( SliderItem );
		}
	}
	
	return !done;
}

BOOL ProcessLevelList ( int Key )
{
	BOOL done, redraw;
	int current;

	done = FALSE;
	redraw = FALSE;

	switch(Key)
	{
	case DIK_LEFT:
		PlayCursorSfx();
		//make selected item 1 to the left
		current = LevelList.selected_item;
		SelectListPrev( &LevelList );
		if (current != LevelList.selected_item)
			redraw = TRUE;
		break;
	case DIK_RIGHT:
		PlayCursorSfx();
		//make selected item 1 to the right
		current = LevelList.selected_item;
		SelectListNext( &LevelList );
		if (current != LevelList.selected_item)
			redraw = TRUE;
		break;
	case DIK_RETURN:
		if ( MenuState == MENUSTATE_SelectLevelQuick )
		{
			if ( ( CurrentMenu != &MENU_NEW_CreateGame ) &&
				 ( CurrentMenu != &MENU_NEW_CreateGameServerChooses ) &&
				 ( CurrentMenu != &MENU_NEW_CreateGamePseudoHost ) &&
				 ( CurrentMenu != &MENU_NEW_CreateLobbyGame ) )
			{
				MenuState = MENUSTATE_SelectLevelSlow;
				MenuChange ( &SlowLevelSelectItem );
			}
		}else
		{
			done = TRUE;
			MenuBack();
		}
		break;
	case DIK_ESCAPE:
		done = TRUE;
		MenuBack();
		break;
	case DIK_UP:
		if (MenuState == MENUSTATE_SelectLevelQuick)
		{
			CursorUp();
			done = TRUE; 
		}
		break;
	case DIK_DOWN:
		if (MenuState == MENUSTATE_SelectLevelQuick)
		{
			CursorDown();
			done = TRUE;
		}
		break;
	default:
		if ( Key )
		{
			char *c;

			current = LevelList.selected_item;
			c = (char *) key_name( Key );
			if ( c && strlen( c ) == 1 )
			{
				SelectListSearch( &LevelList, SearchKey( *c ) );
			}
			if (current != LevelList.selected_item)
			{
				PlayCursorSfx();
				redraw = TRUE;
			}
		}
		break;
	}

	if( MyGameStatus != STATUS_Normal && MyGameStatus != STATUS_SinglePlayer )
		NewLevelNum = LevelList.selected_item;

	if (redraw)
	{
		if (MenuState == MENUSTATE_SelectLevelSlow)
		{
			LastMenu = CurrentMenu;	// because we are not actually changing menus, 
									// but we still want to clear this menu
			LoadLevelText( NULL );
			VduClear();
			ProcessVduItems(CurrentMenu);
		}
		LoadLevelText( NULL );
	}

	return !done;
}



int ValidBikeSelected( int bike)
{
	int j;

	if ( CanSelectBike[ bike ] )
		return bike;
	for ( j = 0; j < MAXBIKETYPES; j++ )
	{
		if ( CanSelectBike[ j ] )
		{
			return j;
		}
	}
	return -1;
}


/*�������������������������������������������������������������������
	Procedure	:		Processes biker list, auto selects highlighted item and redraws biker char and text
	Input		:		key pressed
	Output		:		BOOL - indicates when biker list is no longer being used
�������������������������������������������������������������������*/
BOOL ProcessBikerList ( int Key )
{
	BOOL done, redraw;
	int current;

	done = FALSE;
	redraw = FALSE;

	switch(Key)
	{
	case DIK_LEFT:
		PlayCursorSfx();
		//make selected item 1 to the left
		current = BikeList.selected_item;
		do {
			SelectListPrev( &BikeList );
		} while ( BikeList.selected_item > 0 && !CanSelectBike[ BikeList.selected_item ] );
		if ( !CanSelectBike[ BikeList.selected_item ] )
			BikeList.selected_item = current;
		BikeList.selected_item = ValidBikeSelected( BikeList.selected_item );
		if (current != BikeList.selected_item)
		{
			ExitBikeSelection(NULL);
			redraw = TRUE;
		}
		break;
	case DIK_RIGHT:
		PlayCursorSfx();

		//make selected item 1 to the right
		current = BikeList.selected_item;
		do {
			SelectListNext( &BikeList );
		} while ( BikeList.selected_item < BikeList.items - 1 && !CanSelectBike[ BikeList.selected_item ] );
		if ( !CanSelectBike[ BikeList.selected_item ] )
			BikeList.selected_item = current;
		BikeList.selected_item = ValidBikeSelected( BikeList.selected_item );
		if (current != BikeList.selected_item)
		{
			ExitBikeSelection(NULL);
			redraw = TRUE;
		}
		break;
	case DIK_RETURN:
		done = TRUE;
		MenuBack();
		break;
	case DIK_ESCAPE:
		done = TRUE;
		MenuBack();
		break;
	}

	if (redraw)
	{
		LastMenu = CurrentMenu;	// because we are not actually changing menus, 
								// but we still want to clear this menu
		VduClear();
		OldSelectedBike = BikeList.selected_item;
		ProcessVduItems(CurrentMenu);
	}

	return !done;
}

BOOL ProcessSavedGameList( int Key )
{
	BOOL done, redraw;
	int current;

	done = FALSE;
	redraw = FALSE;

	switch(Key)
	{
	case DIK_LEFT:
		PlayCursorSfx();

		current = LoadSavedGameList.selected_item;
		SelectListPrev( &LoadSavedGameList );
		if (current != LoadSavedGameList.selected_item)
		{
			redraw = TRUE;
		}
		break;
	case DIK_RIGHT:
		PlayCursorSfx();

		current = LoadSavedGameList.selected_item;
		SelectListNext( &LoadSavedGameList );
		if (current != LoadSavedGameList.selected_item)
		{
			redraw = TRUE;
		}
		break;
	case DIK_RETURN:
		done = TRUE;
		TitleLoadGame( NULL );
		break;
	case DIK_ESCAPE:
		done = TRUE;
		MenuBack();
		break;
	}

	if (redraw)
	{
		GetSavedGameData();
		LastMenu = CurrentMenu;	// because we are not actually changing menus, 
								// but we still want to clear this menu
		VduClear();
		ProcessVduItems(CurrentMenu);
	}

	return !done;
}

/*�������������������������������������������������������������������
	Procedure	:		Processes the player list - auto selects highlighted item, 
						and draws corresponding biker character.
	Input		:		key pressed...
	Output		:		BOOL - indicates when player list is no longer being used.
�������������������������������������������������������������������*/
BOOL ProcessPlayerList ( int Key )
{
	BOOL done, redraw;
	char old_bike_name[16];

	done = FALSE;	 
	redraw = FALSE;

	strcpy(old_bike_name, bike_name);

	switch(Key)
	{
	case DIK_UP:
		//make selected item 1 up
		PlayCursorSfx();
		SelectListPrev( &PilotList );
		redraw = TRUE;
		break;
	case DIK_DOWN:
		//make selected item 1 down
		PlayCursorSfx();
		SelectListNext( &PilotList );
		redraw = TRUE;
		break;
	case DIK_RETURN:
		done = TRUE;
		redraw = TRUE;
		MenuBack();
		break;
	case DIK_ESCAPE:
		done = TRUE;
		redraw = TRUE;
		MenuBack();
		break;
	case DIK_NEXT:
		PlayCursorSfx();
		SelectListNextPage( &PilotList );
		redraw = TRUE;
		break;
	case DIK_PRIOR:
		PlayCursorSfx();
		SelectListPrevPage( &PilotList );
		redraw = TRUE;
		break;
	case DIK_HOME:
		PlayCursorSfx();
		SelectListHome( &PilotList );
		redraw = TRUE;
		break;
	case DIK_END:
		PlayCursorSfx();
		SelectListEnd( &PilotList );
		redraw = TRUE;
		break;
	case DIK_DELETE:
		if ( PilotList.FuncDelete )
		{
			if ( PilotList.selected_item >= 0 && PilotList.selected_item < PilotList.items 
				&& !PilotList.FuncDelete( &PilotList, PilotList.selected_item ) )
			{
				PlaySfx( SFX_Error, 1.0F );
			}
			redraw = TRUE;
		}
		break;
	default:
		if ( Key )
		{
			char *c;
			c = (char *) key_name( Key );
			if ( c && strlen( c ) == 1 )
			{
				SelectListSearch( &PilotList, SearchKey( *c ) );
				redraw = TRUE;
				PlayCursorSfx();
			}
		}
		break;
	}
  
	if (redraw)
	{	
		SelectPilot(CurrentMenuItem);
		if (strcmp(old_bike_name, bike_name))	// if bike name has changed....
		{

			ShowHoloModel( HoloModelLookup[ SelectedBike ] );

#if 0
			PrintTextItem(BikeNameTextPtr); 

			if ((Title_Timers[TITLE_TIMER_SwapBikes].Status != TITLE_EVENT_TIMER_ACTIVE) && (Title_Timers[TITLE_TIMER_SwapBikes].Status != TITLE_EVENT_TIMER_FINISHED))
			{
				Title_Timers[TITLE_TIMER_SwapBikes].Status = TITLE_EVENT_TIMER_ACTIVE;
 				Title_Timers[TITLE_TIMER_SwapBikes].CurrentTime = 0.0F;
				OldSelectedBikeScale = SelectedBikeScale;
			}else
			{	if (Title_Timers[TITLE_TIMER_SwapBikes].CurrentTime > 0.5F)
				{	for (Event = Title_Events; Event->TriggeredBy >= 0; Event++)
					{
						if (Event->TriggeredBy == TITLE_TIMER_SwapBikes)
						{
				
							if ((Event->Status == TITLE_EVENT_STATUS_ACTIVE) || (Event->Status == TITLE_EVENT_STATUS_FINISHED))
							{
								Event->Status = TITLE_EVENT_STATUS_IDLE;

								if (Event->Status == TITLE_EVENT_STATUS_ACTIVE)
								{
									if (Event->ExitFunc)
										Event->ExitFunc(Event);
								}

								Title_Timers[TITLE_TIMER_SwapBikes].Status = TITLE_EVENT_TIMER_ACTIVE;
			 					Title_Timers[TITLE_TIMER_SwapBikes].CurrentTime = 0.0F;
								OldSelectedBikeScale = BikeSwapScale;
							}

						}
					}
		
				}
			}
#endif
		}

		KillBikeChar( NULL );
		LoadBikeChar( &BikeCharItem );


//		RedrawFlatMenuList(CurrentMenuItem);
	}

	
	return !done;
}

BOOL ProcessWeaponOrder ( int Key )
{
	BOOL done, redraw;
	int highlighttype, temp, oldselectedweapon, i;

	done = FALSE;
	redraw = FALSE;
	
	switch(Key)
	{
	case DIK_DOWN:
		PlayCursorSfx();
		oldselectedweapon = SelectedWeapon;

		if (WeaponOrderStatus == WEAPON_ChoosingSecond)
		{
			// if currently at bottom of used list...
			if (SelectedWeapon == MaxWeapons - Num_Unused_Weapons - 1)
			{
				Num_Unused_Weapons++;
				redraw = TRUE;
			}else
			{
				// if last item...
				if (SelectedWeapon == MaxWeapons - 1)
				{
					// if no weapons in unused list...
					if (Num_Unused_Weapons == 0)
						Num_Unused_Weapons++;
						redraw = TRUE;
				}else
				{
					// swap current weapon with one below...
					temp = WeaponList[SelectedWeapon];
					WeaponList[SelectedWeapon] = WeaponList[SelectedWeapon + 1];
					WeaponList[SelectedWeapon + 1] = temp;
					redraw = TRUE;

					SelectedWeapon++;
				}
			}
		}else
		// choosing first weapon...
		{
			// if not last weapon...
			if (SelectedWeapon != MaxWeapons - 1)
				SelectedWeapon++;
		}

		// move cursor if necessary...
		if (oldselectedweapon != SelectedWeapon)
		{
			WeaponItem->TextInfo[oldselectedweapon]->highlight = FALSE;
			highlighttype = WeaponItem->TextInfo[oldselectedweapon]->highlighttype;
			WeaponItem->TextInfo[SelectedWeapon]->highlight = TRUE;
			WeaponItem->TextInfo[SelectedWeapon]->highlighttype = highlighttype;
		}
		break;
	case DIK_UP:
		PlayCursorSfx();
		oldselectedweapon = SelectedWeapon;

		if (WeaponOrderStatus == WEAPON_ChoosingSecond)
		{
			// if currently at top of unused list...
			if (SelectedWeapon == MaxWeapons - Num_Unused_Weapons)
			{
				Num_Unused_Weapons--;
				redraw = TRUE;
			}else
			{
				// if first item...
				if (SelectedWeapon == 0)
				{
					// if no weapons in used list...
					if (Num_Unused_Weapons == MaxWeapons)
						Num_Unused_Weapons--;
						redraw = TRUE;
				}else
				{
					// swap current weapon with one above...
					temp = WeaponList[SelectedWeapon];
					WeaponList[SelectedWeapon] = WeaponList[SelectedWeapon - 1];
					WeaponList[SelectedWeapon - 1] = temp;
					redraw = TRUE;

					SelectedWeapon--;
				}
			}
		}else
		// choosing first weapon...
		{
			// if not first weapon...
			if (SelectedWeapon != 0)
				SelectedWeapon--;
		}

		// move cursor if necessary...
		if (oldselectedweapon != SelectedWeapon)
		{
			WeaponItem->TextInfo[oldselectedweapon]->highlight = FALSE;
			highlighttype = WeaponItem->TextInfo[oldselectedweapon]->highlighttype;
			WeaponItem->TextInfo[SelectedWeapon]->highlight = TRUE;
			WeaponItem->TextInfo[SelectedWeapon]->highlighttype = highlighttype;
		}
		break;
	case DIK_LEFT:
		PlayCursorSfx();
		// if currently in unused list...
		if (SelectedWeapon >= MaxWeapons - Num_Unused_Weapons)
		{
			oldselectedweapon = SelectedWeapon;

			if (WeaponOrderStatus == WEAPON_ChoosingSecond)
			{
				// if at top of unused list...
				if (SelectedWeapon == MaxWeapons - Num_Unused_Weapons)
				{
					Num_Unused_Weapons--;
					redraw = TRUE;
					SelectedWeapon++;
					if (SelectedWeapon > MaxWeapons - 1)
						SelectedWeapon = MaxWeapons - 1;
				}else
				{
					temp = WeaponList[SelectedWeapon];
					for (i = SelectedWeapon; i > MaxWeapons - Num_Unused_Weapons; i--)
					{
						WeaponList[i] = WeaponList[i - 1];

					}
					WeaponList[i] = temp;
					Num_Unused_Weapons--;
					redraw = TRUE;
				}
				// return to choosing first weapon...
				WeaponItem->TextInfo[SelectedWeapon]->highlighttype = HIGHLIGHT_Pulsing;
				WeaponItem->TextInfo[oldselectedweapon]->highlighttype = HIGHLIGHT_Pulsing;
				WeaponOrderStatus = WEAPON_ChoosingFirst;
			}else
			{
				// if there are items in the used list...
				if (Num_Unused_Weapons < MaxWeapons)
					SelectedWeapon = MaxWeapons - Num_Unused_Weapons - 1;
			}

			// move cursor if necessary...
			if (oldselectedweapon != SelectedWeapon)
			{
				WeaponItem->TextInfo[oldselectedweapon]->highlight = FALSE;
				highlighttype = WeaponItem->TextInfo[oldselectedweapon]->highlighttype;
				WeaponItem->TextInfo[SelectedWeapon]->highlight = TRUE;
				WeaponItem->TextInfo[SelectedWeapon]->highlighttype = highlighttype;
			}
		}
		break;
	case DIK_RIGHT:
		PlayCursorSfx();
		// if currently in used list...
		if (SelectedWeapon < MaxWeapons - Num_Unused_Weapons)
		{
			oldselectedweapon = SelectedWeapon;

			if (WeaponOrderStatus == WEAPON_ChoosingSecond)
			{
				// if at bottom of used list...
				if (SelectedWeapon == MaxWeapons - Num_Unused_Weapons - 1)
				{
					Num_Unused_Weapons++;
					redraw = TRUE;
					SelectedWeapon--;
					if (SelectedWeapon < 0)
						SelectedWeapon = 0;
				}else
				{
					temp = WeaponList[SelectedWeapon];
					for (i = SelectedWeapon; i < MaxWeapons - 1 - Num_Unused_Weapons; i++)
					{
						WeaponList[i] = WeaponList[i + 1];

					}
					WeaponList[i] = temp;
					Num_Unused_Weapons++;
					redraw = TRUE;
				}
				// return to choosing first weapon...
				WeaponItem->TextInfo[SelectedWeapon]->highlighttype = HIGHLIGHT_Pulsing;
				WeaponItem->TextInfo[oldselectedweapon]->highlighttype = HIGHLIGHT_Pulsing;
				WeaponOrderStatus = WEAPON_ChoosingFirst;
			}else
			{
				// if there are items in the unused list...
				if (Num_Unused_Weapons > 0)
					SelectedWeapon = MaxWeapons - Num_Unused_Weapons;
			}

			// move cursor if necessary...
			if (oldselectedweapon != SelectedWeapon)
			{
				WeaponItem->TextInfo[oldselectedweapon]->highlight = FALSE;
				highlighttype = WeaponItem->TextInfo[oldselectedweapon]->highlighttype;
				WeaponItem->TextInfo[SelectedWeapon]->highlight = TRUE;
				WeaponItem->TextInfo[SelectedWeapon]->highlighttype = highlighttype;
			}
		}
		break;
	case DIK_RETURN:
		if (WeaponOrderStatus == WEAPON_ChoosingFirst)
		{
			WeaponItem->TextInfo[SelectedWeapon]->highlighttype = HIGHLIGHT_Static;
			WeaponOrderStatus = WEAPON_ChoosingSecond;
		}else
		{
			WeaponItem->TextInfo[SelectedWeapon]->highlighttype = HIGHLIGHT_Pulsing;
			WeaponOrderStatus = WEAPON_ChoosingFirst;
		}
		break;
	case DIK_ESCAPE:
		done = TRUE;
		MenuBack();
		break;
	}

	if (redraw)
		DrawGeneralWeaponText(WeaponItem);

	return !done;
}

BOOL ProcessPlaceTeamMember( int Key )
{
	BOOL done;
	MENUITEM *NextTeamItem;
	LIST *DestTeamList;
	int i;

	DestTeamList = (LIST *)(CurrentMenuItem->Variable);

	done = FALSE;

	NextTeamItem = CurrentMenuItem;

	switch( Key )
	{
	case DIK_LEFT:
		NextTeamItem--;
		if (NextTeamItem->FuncSelect == SelectTeamList)
		{
			CurrentMenuItem = NextTeamItem;
			PlayCursorSfx();
		}
		break;
	case DIK_RIGHT:
		NextTeamItem++;
		if (NextTeamItem->FuncSelect == SelectTeamList)
		{
			CurrentMenuItem = NextTeamItem;
			PlayCursorSfx();
		}
		break;
	case DIK_RETURN:
		if (SourceTeamList != DestTeamList)
		{
			SwapTeamIDs( SourceTeamList , DestTeamList );
//			SwapListItem( SourceTeamList , DestTeamList );
		}
		for (i = 0; i < TextStackLevel; i++)
		{
			TextStack[i]->highlight =  FALSE;
			TextStack[i]->highlighttype = HIGHLIGHT_Pulsing;
		}
		SourceTeamList->selected_item = -1;
		DestTeamList->selected_item = -1;
		done = TRUE;
		break;
	case DIK_ESCAPE:
		break;
	}
	
	return !done;

}

void DeleteJoyButton( void )
{
	int joystick_num, num_buttons, i, j, num_povs;
	
	if ( JoystickConfigState == JOYCONFIG_SelectAction )
	{
		joystick_num = JoystickMap[JoystickList.selected_item];
		num_buttons = JoystickInfo[joystick_num].NumButtons;
		num_povs = JoystickInfo[joystick_num].NumPOVs;

		for (i = 0; i < num_buttons; i++)
		{
			if ( JoystickInfo[ joystick_num ].Button[ i ].action == ShipActionList.selected_item )
				JoystickInfo[ joystick_num ].Button[ i ].action = SHIPACTION_Nothing;
		}

		for ( i = 0; i < num_povs; i++ )
		{
			for ( j = 0; j < MAX_POV_DIRECTIONS; j++ )
			{
			if ( JoystickInfo[ joystick_num ].POV[ i ].action[j] == ShipActionList.selected_item )
				JoystickInfo[ joystick_num ].POV[ i ].action[j] = SHIPACTION_Nothing;
			}
		}
	}
}

BOOL ProcessList( int Key )
{
	BOOL done;
	MenuItemFunc FuncSet;
	int i;

	if (CurrentList->Static)
	{
	 	if (Key == DIK_ESCAPE)
			CurrentList->Static = FALSE;

		return TRUE;
	}

	done = FALSE;

	if ( CurrentList->selected_item < 0 )
		SelectListHome( CurrentList );
	if ( CurrentList->selected_item > CurrentList->items )
		SelectListEnd( CurrentList );
	switch( Key )
	{
	case DIK_RIGHT:
		// if there is an item of the same height to the left, move to this item
		for (i = 0; i < CurrentList->items; i++)
		{
			if (i != CurrentList->selected_item && CurrentListItem->TextInfo[i] && CurrentListItem->TextInfo[CurrentList->selected_item])
			{
				if ((CurrentListItem->TextInfo[i]->ymin == CurrentListItem->TextInfo[CurrentList->selected_item]->ymin) &&
					(CurrentListItem->TextInfo[CurrentList->selected_item]->xmin < CurrentListItem->TextInfo[i]->xmin))
				{
					CurrentList->selected_item = i;
					PlayCursorSfx();
				}
			}
		}
		break;
	case DIK_LEFT:
		// if there is an item of the same height to the right, move to this item
		for (i = 0; i < CurrentList->items; i++)
		{
			if (i != CurrentList->selected_item && CurrentListItem->TextInfo[i] && CurrentListItem->TextInfo[CurrentList->selected_item])
			{
				if ((CurrentListItem->TextInfo[i]->ymin == CurrentListItem->TextInfo[CurrentList->selected_item]->ymin) &&
					(CurrentListItem->TextInfo[CurrentList->selected_item]->xmin > CurrentListItem->TextInfo[i]->xmin))
				{
					CurrentList->selected_item = i;
					PlayCursorSfx();
				}
			}
		}
		break;
	case DIK_UP:
		PlayCursorSfx();
		SelectListPrev( CurrentList );
		break;
	case DIK_DOWN:
		PlayCursorSfx();
		SelectListNext( CurrentList );
		break;
	case DIK_NEXT:
		PlayCursorSfx();
		SelectListNextPage( CurrentList );
		break;
	case DIK_PRIOR:
		PlayCursorSfx();
		SelectListPrevPage( CurrentList );
		break;
	case DIK_HOME:
		PlayCursorSfx();
		SelectListHome( CurrentList );
		break;
	case DIK_END:
		PlayCursorSfx();
		SelectListEnd( CurrentList );
		break;
	case DIK_RETURN:
			//SelectListItem( CurrentList );
			FuncSet = (MenuItemFunc) CurrentMenuItem->Value;
			if ( FuncSet )
			{
				FuncSet( CurrentMenuItem );
			}
			done = TRUE;
		break;
	case DIK_ESCAPE:
		CancelListSelection( CurrentList );
		done = TRUE;
		if (CurrentMenuItem->highlightflags & TEXTFLAG_AutoSelect)
			MenuBack();
		break;
	case DIK_DELETE:
		if ( CurrentMenu == &MENU_NEW_ConfigJoyBtns )
		{ 
			DeleteJoyButton();
		}
		if ( CurrentList->FuncDelete )
		{
			if ( CurrentList->selected_item >= 0 && CurrentList->selected_item < CurrentList->items 
				&& !CurrentList->FuncDelete( CurrentList, CurrentList->selected_item ) )
			{
				PlaySfx( SFX_Error, 1.0F );
			}
		}
		break;
	default:
		if ( Key )
		{
			char *c;
			c = (char *) key_name( Key );
			if ( c && strlen( c ) == 1 )
			{
				SelectListSearch( CurrentList, SearchKey( *c ) );
				PlayCursorSfx();
			}
		}
		break;
	}

	return !done;
}


BOOL ProcessText( int Key )
{
	BOOL done;
	TEXT *t;

	done = FALSE;
	t = (TEXT *)(TextItem->Variable);

	switch( Key )
	{
	case DIK_LEFT:
		TextLeft( (TEXT *)(TextItem->Variable) );
		break;
	case DIK_RIGHT:
		TextRight( (TEXT *)(TextItem->Variable) );
		break;
	case DIK_BACK:
		TextBackspace( (TEXT *)(TextItem->Variable) );
		break;
	case DIK_DELETE:
		TextDelete( (TEXT *)(TextItem->Variable) );
		break;
	case DIK_TAB:
		TextClear( (TEXT *)(TextItem->Variable) );
		break;
	case DIK_HOME:
		TextHome( (TEXT *)(TextItem->Variable) );
		break;
	case DIK_END:
		TextEnd( (TEXT *)(TextItem->Variable) );
		break;
	case DIK_RETURN:
	case DIK_UP:
	case DIK_DOWN:
		TextEnter( TextItem );
		done = TRUE;
		break;
	case DIK_ESCAPE:
		TextCancel( (TEXT *)(TextItem->Variable) );
		done = TRUE;
		break;
	case DIK_SPACE:
		TextType( (TEXT *)(TextItem->Variable), ' ' );
		break;
	default:
		if ( Key )
		{
			char *c;

			c = (char *) key_name( Key );
			if ( c && strlen( c ) == 1 )
			{
				TextType( (TEXT *)(TextItem->Variable), *c );
			}
		}
	}

	// if we are doing text editing on the VDU, reformat if any key was pressed (except return)
	if ((MenuState == MENUSTATE_Text2) && Key && !done)
	{
		GetVduTextFormattingInfo ( t );
	}

	return !done;
}

void ProcessSelect( int Key )
{
//#ifdef SELF_PLAY

	if (MyGameStatus == STATUS_Copyright)
	{
		if (Key != DIK_RETURN)
			return;
	}
//#endif
	
	if (StackStatus == DISC_NOTHING)
	{	switch(Key)
		{
		case DIK_UP:
			CursorUp();
			break;
	
		case DIK_DOWN:
			CursorDown();
			break;

		case DIK_LEFT:
			if (CurrentMenuItem->FuncSelect == SelectFlatMenuToggle)
			{
				if ( CurrentMenuItem->Variable && *(BOOL *)(CurrentMenuItem->Variable) )
				{
					if ( CurrentMenuItem->FuncSelect )
					{
						CurrentMenuItem->FuncSelect( CurrentMenuItem );
						PlayCursorSfx();
					}
				}
			}else
				CursorLeft();
			break;
		case DIK_RIGHT:
			if (CurrentMenuItem->FuncSelect == SelectFlatMenuToggle)
			{	
				if ( CurrentMenuItem->Variable && !*(BOOL *)(CurrentMenuItem->Variable) )
				{
					if ( CurrentMenuItem->FuncSelect )
					{
						CurrentMenuItem->FuncSelect( CurrentMenuItem );
						PlayCursorSfx();
					}
				}
			}else
				CursorRight();
			break;
		case DIK_HOME:
			CursorHome();
			break;

		case DIK_END:
			CursorEnd();
			break;
		case DIK_RETURN:
			if ( CurrentMenuItem->FuncSelect )
			{
				CurrentMenuItem->FuncSelect( CurrentMenuItem );
			}
			break;
		case DIK_DELETE:
			if ( ( ( CurrentMenuItem->FuncSelect == SelectKey ) || ( CurrentMenuItem->FuncSelect == SelectFlatMenuKey ) ) && CurrentMenuItem->Variable )
			{
				*(VirtualKeycode *)(CurrentMenuItem->Variable) = (VirtualKeycode) 0; // delete key def
			}
			
			if ( CurrentMenuItem->FuncSelect == SelectFlatMenuKey )
				CheckKeysForChanges();

			break;

		case DIK_ESCAPE:
			// bodge to stop you getting 'stuck' in between menus...
			if ( CurrentMenu == &MENU_NEW_WatchTeamSelect)
				MenuBack();	

			MenuBack();
			break;

		default:
			if ( Key )
			{
				char *c;

				c = (char *) key_name( Key );
				if ( c && strlen( c ) == 1 )
				{
					CursorSearch( SearchKey( *c ) );
				}
			}
			break;
		}
	}
}


BOOL ProcessSelectKeydef( int Key )
{
	BOOL done;

	done = FALSE;
	if (StackStatus == DISC_NOTHING)
	{
		switch(Key)
		{
		case DIK_UP:
			CursorUp();
			break;
			
		case DIK_DOWN:
			CursorDown();
			break;
			
		case DIK_LEFT:
			if ( CurrentMenuItem->FuncSelect == SelectKeyDef
				|| CurrentMenuItem->FuncSelect == SelectFlatMenuKey )
			{
				DEFKEY *kdef;
				
				kdef = (DEFKEY *)(CurrentMenuItem->Variable);
				if ( kdef->selected_key > 0 )
				{
					kdef->selected_key--;
					PlayCursorSfx();
					if ( CurrentMenuItem->FuncSelect == SelectFlatMenuKey )
						CheckKeysForChanges();
				}
			}else
				CursorLeft();
			break;
		case DIK_RIGHT:
			if ( CurrentMenuItem->FuncSelect == SelectKeyDef
				|| CurrentMenuItem->FuncSelect == SelectFlatMenuKey )
			{
				DEFKEY *kdef;
				
				kdef = (DEFKEY *)(CurrentMenuItem->Variable);
				if ( kdef->selected_key < kdef->def->keys - 1 )
				{
					kdef->selected_key++;
					PlayCursorSfx();
					if ( CurrentMenuItem->FuncSelect == SelectFlatMenuKey )
						CheckKeysForChanges();
				}
#ifdef KEY_RIGHT_AT_END_ADDS_KEYDEF
				else if ( kdef->def->keys < MAX_KEYS_PER_CONTROL )
				{
					kdef->selected_key = kdef->def->keys++;
					kdef->def->key[ kdef->selected_key ] = (VirtualKeycode) 0;
					CurrentMenuItem->FuncSelect( CurrentMenuItem );
					if ( CurrentMenuItem->FuncSelect == SelectFlatMenuKey )
						CheckKeysForChanges();
				}
#endif
			}else
				CursorRight();
			break;
		case DIK_HOME:
			CursorHome();
			break;
			
		case DIK_END:
			CursorEnd();
			break;
		case DIK_RETURN:
			if ( CurrentMenuItem->FuncSelect )
			{
				if ( CurrentMenuItem->FuncSelect == SelectKeyDef
					|| CurrentMenuItem->FuncSelect == SelectFlatMenuKey )
				{
					DEFKEY *kdef;
					
					kdef = (DEFKEY *)(CurrentMenuItem->Variable);
#ifdef KEY_ENTER_AT_EMPTY_ADDS_KEYDEF
					if ( !kdef->def->keys )
#else
						if ( kdef->def->keys < MAX_KEYS_PER_CONTROL )
#endif
						{
							kdef->selected_key = kdef->def->keys++;
							kdef->def->key[ kdef->selected_key ] = (VirtualKeycode) 0;
							CurrentMenuItem->FuncSelect( CurrentMenuItem );
							if ( CurrentMenuItem->FuncSelect == SelectFlatMenuKey )
								CheckKeysForChanges();
						}
						else
							PlaySfx( SFX_Error, 1.0F );
				}
				else
					CurrentMenuItem->FuncSelect( CurrentMenuItem );
			}
			break;
		case DIK_INSERT:
			if ( CurrentMenuItem->FuncSelect == SelectKeyDef
				|| CurrentMenuItem->FuncSelect == SelectFlatMenuKey )
			{
				DEFKEY *kdef;
				
				kdef = (DEFKEY *)(CurrentMenuItem->Variable);
				if ( kdef->def->keys < MAX_KEYS_PER_CONTROL )
				{
					kdef->selected_key = kdef->def->keys++;
					kdef->def->key[ kdef->selected_key ] = (VirtualKeycode) 0;
					CurrentMenuItem->FuncSelect( CurrentMenuItem );
					if ( CurrentMenuItem->FuncSelect == SelectFlatMenuKey )
						CheckKeysForChanges();
				}
				else
					PlaySfx( SFX_Error, 1.0F );
			}
			break;
		case DIK_DELETE:
			if ( CurrentMenuItem->FuncSelect == SelectKeyDef
				|| CurrentMenuItem->FuncSelect == SelectFlatMenuKey )
			{
				DEFKEY *kdef;
				
				kdef = (DEFKEY *)(CurrentMenuItem->Variable);
				KeyDelete( kdef, kdef->selected_key );
			}
			
			if ( CurrentMenuItem->FuncSelect == SelectFlatMenuKey )
				CheckKeysForChanges();
			
			break;
			
		case DIK_ESCAPE:
			MenuBack();
			done = TRUE;
			break;
			
		case DIK_PGUP:
			if ( CurrentMenu == &MENU_Keyboard )
			{
				if ( CurrentPage > 0 )
				{
					PlaySfx( SFX_InGameMenuSelect, 1.0F );
					SetKeyDefPage( CurrentPage - 1 );
				}
			}
			break;
			
		case DIK_PGDN:
			if ( CurrentMenu == &MENU_Keyboard )
			{
				if ( CurrentPage < MaxPage - 1 )
				{
					PlaySfx( SFX_InGameMenuSelect, 1.0F );
					SetKeyDefPage( CurrentPage + 1 );
				}
			}
			break;
			
		default:
			if ( Key )
			{
				char *c;
				
				c = (char *) key_name( Key );
				if ( c && strlen( c ) == 1 )
				{
					CursorSearch( SearchKey( *c ) );
				}
			}
			break;
		}
	}
	
	return !done;
}


BOOL ProcessDifficultySet ( int Key )
{
	BOOL done = FALSE;

	if ( StackStatus != DISC_NOTHING )
		return !done;

	switch(Key)
	{
	case DIK_UP:
		CursorUp();
		done = TRUE;
		break;

	case DIK_DOWN:
		CursorDown();
		done = TRUE;
		break;

	case DIK_LEFT:
		StackMode = DISC_MODE_ONE;
		StackStatus = DISC_EXPAND;
		DifficultyDir = ROTATE_DISC_DifficultyBack;
		DifficultyLevel--;
		if( DifficultyLevel < DIFF_Easy )
			DifficultyLevel = DIFF_Vhard;
		break;
	case DIK_RIGHT:
		StackMode = DISC_MODE_ONE;
		StackStatus = DISC_EXPAND;
		DifficultyDir = ROTATE_DISC_DifficultyForward;
		DifficultyLevel++;
		if( DifficultyLevel > DIFF_Vhard )
			DifficultyLevel = DIFF_Easy;
		break;
		break;
	case DIK_HOME:
		CursorHome();
		done = TRUE;
		break;
	case DIK_END:
		done = TRUE;
		CursorEnd();
		break;
	case DIK_ESCAPE:
		MenuBack();
		done = TRUE;
		break;
	default:
		if ( Key )
		{
			char *c;

			c = (char *) key_name( Key );
			if ( c && strlen( c ) == 1 )
			{
				CursorSearch( SearchKey( *c ) );
			}
			done = TRUE;
		}
		break;
	}

	return !done;
}

void StartTimer( int timer )
{
	if (Title_Timers[ timer ].Status == TITLE_EVENT_TIMER_IDLE)
	{
		if (Title_Timers[ timer ].InitFunc)
			Title_Timers[ timer ].InitFunc (&Title_Timers[ timer ]);
	}
}

void CheckMenuTimer( void )
{
	if ((CurrentMenu) && (CurrentMenu->MenuStatus))
	{
		if (CurrentMenu->MenuStatus)
		{
			StartTimer( CurrentMenu->MenuStatus );
		}
	}
}

void SetVolumeLevels( void )
{
	VECTOR	temp;
	float dist;

	temp.x = Models[BackgroundModel[TITLE_MODEL_VDU]].Pos.x - View.x;
	temp.y = Models[BackgroundModel[TITLE_MODEL_VDU]].Pos.y - View.y;
	temp.z = Models[BackgroundModel[TITLE_MODEL_VDU]].Pos.z - View.z;

	dist = (float) sqrt( ( temp.x * temp.x ) + ( temp.y * temp.y ) + ( temp.z * temp.z ) );
	if ( dist < 540.0F )
	{
		if ( !TitleLoopId[ TITLE_LOOP_VduAmbience ] )
		{
			TitleLoopId[ TITLE_LOOP_VduAmbience ] = PlaySfx( SFX_VDUAmbience, 0.3F );
		}
	}else
	{
		if ( TitleLoopId[ TITLE_LOOP_VduAmbience ] )
		{
			StopSfx( TitleLoopId[ TITLE_LOOP_VduAmbience ] );
			TitleLoopId[ TITLE_LOOP_VduAmbience ] = 0;
		}
	}

	if ( !TitleLoopId[ TITLE_LOOP_DiscAmbience ] )
	{
		TitleLoopId[ TITLE_LOOP_DiscAmbience ] = PlaySfx( SFX_TitleAmb, 0.3F );
	}

}

/*�������������������������������������������������������������������
	Procedure	:		Menu Process...
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/

void	MenuProcess()
{
	DWORD Key;
	BOOL KeyFound = FALSE;
	uint16 i;
	char str[256];

#if 0

	DPlayGetSessionDesc(); 
	if ( glpdpSD )
	{
		sprintf( str, "dw1 %x dw2 %x dw3 %x dw4 %x", glpdpSD->dwUser1, glpdpSD->dwUser2, glpdpSD->dwUser3, glpdpSD->dwUser4 );
		Print4x5Text( str, 10, 10, 2 );
		sprintf( str, "dwflags %x", glpdpSD->dwFlags );
		Print4x5Text( str, 10, 20, 2 );
		sprintf( str, "server state %d", ( glpdpSD->dwUser3 & ServerGameStateBits ) >> Server_State_BitShift );
		Print4x5Text( str, 10, 30, 2 );
		sprintf( str, "max players %d", ( glpdpSD->dwMaxPlayers ) );
		Print4x5Text( str, 10, 40, 2 );
	}

	sprintf( str, "MyGameStatus %x", MyGameStatus );
	Print4x5Text( str, 10, 50, 2 );

	for ( i = 0; i < MAX_PLAYERS; i++ )
	{
		sprintf( str, "player %d status %x", i, GameStatus[ i ] );
		Print4x5Text( str, 10, 60 + ( i * FontHeight ), 2 );
	}

#endif

	sprintf( str, "Dans Special patch release %1.2fa beta 5", PATCH_VERSION );
	CenterPrint4x5Text( str, d3dapp->szClient.cy - FontHeight * 3, 2 );

	//sprintf( str, "ColPerspective %d", ColPerspective );
	//CenterPrint4x5Text( str, d3dapp->szClient.cy - FontHeight * 4, 2 );

//#ifdef SHAREWARE
	if ( CameraStatus == CAMERA_AtDiscs && CurrentMenu == &MENU_Start )
	{
		AttractModeCountDown -= framelag;
		if ( AttractModeCountDown < 0.0F )
		{
			CreditsToggle = !CreditsToggle;
			AttractModeCountDown = ATTRACTMODECOUNTVALUE;
			
			if ( !CreditsToggle )
			{
				InitDemoList( NULL );
				if ( DemoList.items )
				{
					CurrentAttractDemo++;
					if ( CurrentAttractDemo >= DemoList.items )
					{
						CurrentAttractDemo = 0;
					}
					MenuChangeEx( &MENU_NEW_StartAttractMode );
				}
			}else
			{
				MenuChangeEx( &MENU_NEW_StartAttractMode );
			}
		}
	}else
	{
		AttractModeCountDown = ATTRACTMODECOUNTVALUE;
	}
//#endif

	Pulse += framelag/60.0F;
	if (Pulse > 1.0F)
		Pulse -= (float)floor((double)Pulse);

	if ( !CurrentMenu || !CurrentMenuItem )
	{
		return;
	}

	//DebugPrintf("Current Menu %s\n",CurrentMenu->Name);


 	if (ECTSDemo)
	{
		if  ((CurrentMenu == &MENU_NEW_Battle) && 
			(IsKeyPressed (DIK_NUMPAD0) && IsKeyHeld (DIK_LSHIFT) && IsKeyHeld (DIK_F12)))
		{
			MenuChange (&ECTSStartGameItem);
		}
	}
	
	//Key = WhichKeyPressed();
	ReadBufferedKeyboard();


	for ( i = 0; i < NumKeysToProcess + 2; i++ )
	{
		if ( !CurrentMenu )	// if last key pressed exited from menu system, do not process any more keys
		{
			break;
		}
	
		// force first key to be zero, so that any auto selection is done before any keys are processed
		if ( !i )
		{
			Key = 0;
		}
		
		// force last key to be whatever mouse input was ( for key defs )
		if ( i == NumKeysToProcess + 1 )
		{
			Key = CheckMouse();
		}
		 
		if ( ( i > 0 ) && ( i <= NumKeysToProcess ) )
		{
			Key = BufferedKey[ i - 1 ];
		}

		if (Key && (CurrentMenu == &MENU_Copyright))
		{
	 		if ( Key == DIK_ESCAPE )
			{
				SelectQuit( NULL );
			}
			else
			{
				Key = DIK_RETURN;
			}
		}

		CheckCheats( ( VirtualKeycode)Key );

		if (Key && (CurrentMenu == &MENU_NEW_Error))
		{
			Key = DIK_RETURN;
		}

		if (MenuFrozen)
		{
			if (!((Key == DIK_RETURN) || (Key == DIK_ESCAPE)))
			{
				return;
			}
			else
			{
				MenuFrozen = FALSE;
			}
		}

		// pressing any key resets attract mode timer
		if ( Key )
			AttractModeCountDown = ATTRACTMODECOUNTVALUE;

		switch ( MyGameStatus )
		{
			// in title room...
			case	STATUS_StartingMultiplayer:
			case	STATUS_GetPlayerNum:
			case	STATUS_Title:
			case	STATUS_BetweenLevels:
			case	STATUS_StartingSinglePlayer:
				InTitleRoom = TRUE;
				break;
			default:
				InTitleRoom = FALSE;
		}

		if ( !OKToProcessKeys )
		{
			Key = 0;
		}

		// no menu processing done while loading...
		switch ( MyGameStatus )
		{
		case STATUS_WaitingToStartSinglePlayer:
		case STATUS_WaitingToStartMultiPlayerHost:
		case STATUS_WaitingToStartMultiPlayerClient:
		case STATUS_WaitingToStartTeamGame:
		case STATUS_WaitingToStartDemo:
			Key = 0;
			break;
		}

		if ( Key == DIK_RETURN )
		{
			if ( InTitleRoom )
			{
				if ( CameraStatus == CAMERA_AtDiscs )
					PlaySfx( SFX_SelectStackOption, 1.0F );
				else
					PlaySfx( SFX_VidText, 1.0F );

			}else
				PlaySfx( SFX_VidText, 1.0F );
		}

		switch ( MenuState )
		{
			case MENUSTATE_SelectKeydef:
				if ( !ProcessSelectKeydef( Key ) )
					MenuState = MENUSTATE_Select;
				break;
			case MENUSTATE_Keydef:
#ifdef KDEF
				if ( !ProcessDefKey( Key ) )
					MenuState = MENUSTATE_SelectKeydef;
#else
				if ( !ProcessKeydef( Key ) )
					MenuState = MENUSTATE_Select;
#endif
				break;
			case MENUSTATE_Keydef2:
#ifdef VDUKDEF
				if ( !ProcessDefKey( Key ) )
				{	
					MenuState = MENUSTATE_SelectKeydef;
#else
				if ( !ProcessKeydef( Key ) )
				{	
					MenuState = MENUSTATE_Select;
#endif
	//				RedrawFlatMenuKey( KeyItem);
					CheckKeysForChanges();
					CurrentMenuItem->TextInfo[0]->highlighttype = HIGHLIGHT_Pulsing;
				}
				break;
			case MENUSTATE_Slider:
				if ( !ProcessSlider( Key ) )
					MenuState = MENUSTATE_Select;
				break;
			case MENUSTATE_Slider2:
				if ( !ProcessSlider2( Key ) )
					MenuState = MENUSTATE_Select;
				break;
			case MENUSTATE_List:
				if ( !ProcessList( Key ) )
				{
					if ( CurrentMenuItem && (!(CurrentMenuItem->highlightflags & TEXTFLAG_AutoSelect)) )
					{
						CurrentList = NULL;
						MenuState = MENUSTATE_Select;
						if (PreListMenu == CurrentMenu)
							CurrentMenuItem = PreListItem;
						CurrentListItem = NULL;
					}
				}
			break;
		case MENUSTATE_Text:
			if ( !ProcessText( Key ) )
			{
				MenuState = MENUSTATE_Select;
				if (CurrentMenu && (CurrentMenuItem->highlightflags & TEXTFLAG_AutoSelect))	// safe to assume only menu item if autoselected
				{
					MenuBack();
				}
			}
			break;
		case MENUSTATE_Text2:
			if ( !ProcessText( Key ) )
			{	MenuState = MENUSTATE_Select;
				CurrentMenuItem->TextInfo[0]->highlighttype = HIGHLIGHT_Pulsing;
				if (CurrentMenu && (CurrentMenuItem->highlightflags & TEXTFLAG_AutoSelect))	// safe to assume only menu item if autoselected
				{
					MenuBack();
				}
			}
			break;
		case MENUSTATE_SelectBiker:
			if ( !ProcessBikerList ( Key ) )
			{	MenuState = MENUSTATE_Select;
			}
			break;
		case MENUSTATE_SelectSavedGame:
			if ( !ProcessSavedGameList ( Key ) )
			{	MenuState = MENUSTATE_Select;
			}
			break;
		case MENUSTATE_SelectPlayer:
			if ( !ProcessPlayerList ( Key ) )
			{	MenuState = MENUSTATE_Select;
			}
			break;
		case MENUSTATE_WeaponOrder:
			if ( !ProcessWeaponOrder ( Key ) )
			{	MenuState = MENUSTATE_Select;
			}
			break;
		case MENUSTATE_SelectLevelQuick:
		case MENUSTATE_SelectLevelSlow:
			if ( !ProcessLevelList ( Key ) )
				MenuState = MENUSTATE_Select;
			break;
		case MENUSTATE_PlaceTeamMember:
			if ( !ProcessPlaceTeamMember ( Key ) )
				MenuState = MENUSTATE_Select;
			break;
		case MENUSTATE_DifficultySet:
			if ( !ProcessDifficultySet ( Key ) )
				MenuState = MENUSTATE_Select;
			break;
		default:
			if (CurrentMenuItem)
			{
				if (CurrentMenuItem->highlightflags & TEXTFLAG_AutoSelect)
				{
					if (CurrentMenuItem->highlightflags & TEXTFLAG_AutoSelect)
					{
						if (CurrentMenuItem->FuncSelect)
							CurrentMenuItem->FuncSelect(CurrentMenuItem);
					}
				}
				if (MenuState == MENUSTATE_Select)
					ProcessSelect( Key );

				break;
			}
		}
	}

	CheckMenuTimer();
	ProcessMenuFlashText();

	if( InTitleRoom )
		SetVolumeLevels();
}



/*�������������������������������������������������������������������
	Procedure	:		Select/operate a slider menuitem
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void SelectSlider( MENUITEM *Item )
{
	SLIDER *s;

	if (Item->highlightflags & TEXTFLAG_AutoSelect)
		MenuState = MENUSTATE_Slider2;
	else
		MenuState = MENUSTATE_Slider;

	SliderItem = Item;
	s = (SLIDER *)(Item->Variable);
	OriginalSliderValue = s->value;

}


/*�������������������������������������������������������������������
	Procedure	:		Decrement a slider value
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void DecrementSlider( MENUITEM *Item )
{
	SLIDER *s;

	s = (SLIDER *)(Item->Variable);
	s->value -= s->step;
	if ( s->value < s->min )
		s->value = s->min;
}


/*�������������������������������������������������������������������
	Procedure	:		Increment a slider value
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void IncrementSlider( MENUITEM *Item )
{
	SLIDER *s;

	s = (SLIDER *)(Item->Variable);
	s->value += s->step;
	if ( s->value > s->max )
		s->value = s->max;
}



/*�������������������������������������������������������������������
	Procedure	:		Minimise a slider value
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void SliderHome( MENUITEM *Item )
{
	SLIDER *s;

	s = (SLIDER *)(Item->Variable);
	s->value = s->min;
}


/*�������������������������������������������������������������������
	Procedure	:		Maximise a slider value
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void SliderEnd( MENUITEM *Item )
{
	SLIDER *s;

	s = (SLIDER *)(Item->Variable);
	s->value = s->max;
}


/*�������������������������������������������������������������������
	Procedure	:		Cancel a slider selection
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void SliderSet( MENUITEM *Item )
{
	SLIDER *s;

	s = (SLIDER *)(Item->Variable);
	if ( s->FuncSet )
	{
		s->FuncSet( s );
	}
}


/*�������������������������������������������������������������������
	Procedure	:		Cancel a slider selection
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void SliderCancel( MENUITEM *Item )
{
	SLIDER *s;

	s = (SLIDER *)(Item->Variable);
	s->value = OriginalSliderValue;
}



/*�������������������������������������������������������������������
	Procedure	:		Draw a slider menuitem
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void DrawSlider( MENUITEM *Item )
{
	int	x;
	int	y;
	int sx;
	int ex;
	char min[20], max[20], val[20];
	SLIDER *s;
	int colour;

	x = (int) ( ( Item->x >> 1 ) * ModeScaleX[ModeCase] );
	y = (int) ( ( Item->y >> 1 ) * ModeScaleY[ModeCase] );

	Print4x5Text( Item->StrPnt , x , y , 2 );
	sx = Print4x5Text( " ", -1, y, 2 );
	ex = sx + (int) floor( ( 128 >> 1 ) * ModeScaleX[ModeCase] );
	s = (SLIDER *) (Item->Variable);
	sprintf( min, "%d", s->min );
	sprintf( max, "%d", s->max );
	sprintf( val, "%d", s->value );
	Print4x5Text( min, sx, y, 8 );
	Print4x5Text( max, ex, y, 8 );
	colour = ( MenuState == MENUSTATE_Slider && SliderItem == Item ) ? 0 : 1;
	Print4x5Text( val, sx + ( ex - sx ) * ( s->value - s->min ) / ( s->max - s->min ), y, colour );
}


/*�������������������������������������������������������������������
	Procedure	:		Select a radio button item
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void SelectRadioButton( MENUITEM *Item )
{
	if ( Item->Variable )
	{
		*((int *)(Item->Variable)) = (int) Item->Value;
	}
}



/*�������������������������������������������������������������������
	Procedure	:		Draws a radio button item
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void DrawRadioButton( MENUITEM *Item )
{
	int	x;
	int	y;

	x = (int) ( ( Item->x >> 1 ) * ModeScaleX[ModeCase] );
	y = (int) ( ( Item->y >> 1 ) * ModeScaleY[ModeCase] );

	if ( Item->Variable )
	{
		if ( *((int *)(Item->Variable)) == (int) Item->Value )
		{
			// draw selected item
			Print4x5Text( Item->StrPnt , x , y , 1 );
		}
		else
		{
			// draw unselected item
			Print4x5Text( Item->StrPnt , x , y , 2 );
		}
	}
}


/*�������������������������������������������������������������������
	Procedure	:		Select a toggle menuitem
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void SelectToggle( MENUITEM *Item )
{

	MenuItemFunc set_toggle;

	if ( Item->Variable )
	{
		*(BOOL *)(Item->Variable) = !*(BOOL *)(Item->Variable);
		if ( Item->Value )
		{
			set_toggle = (MenuItemFunc)(Item->Value);
			set_toggle( Item );
		}
	}

}

/*�������������������������������������������������������������������
	Procedure	:		Draw a toggle menuitem
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void DrawToggle( MENUITEM *Item )
{
	int	x;
	int	y;

	x = (int) ( ( Item->x >> 1 ) * ModeScaleX[ModeCase] );
	y = (int) ( ( Item->y >> 1 ) * ModeScaleY[ModeCase] );

	Print4x5Text( Item->StrPnt , x , y , 2 );
	if ( Item->Variable )
	{
		if ( *(BOOL *)(Item->Variable ) )
		{
			Print4x5Text( LT_ToggleOn/*" ON"*/, -1 , y , 1 );
		}
		else
		{
			Print4x5Text( LT_ToggleOff/*" OFF"*/, -1 , y , 1 );
		}
	}
}





/*�������������������������������������������������������������������
	Procedure	:		Select a key menuitem
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void SelectKey( MENUITEM *Item )
{	
	MenuState = MENUSTATE_Keydef;
	KeyItem = Item;

}



/*�������������������������������������������������������������������
	Procedure	:		Draw a key menuitem
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void DrawKey( MENUITEM *Item )
{
	VirtualKeycode keycode;
	char *keyword;
	int	x;
	int	y;
	int colour;

	x = (int) ( ( Item->x >> 1 ) * ModeScaleX[ModeCase] );
	y = (int) ( ( Item->y >> 1 ) * ModeScaleY[ModeCase] );

	if ( Item->Variable )
	{
		keycode = *(VirtualKeycode *)(Item->Variable);
		if ( MenuState == MENUSTATE_Keydef && Item == KeyItem )
		{
			colour = SelectionColour();
		}
		else
		{
			colour = 1;
		}
		if ( keycode )
		{
			keyword = (char *) key_name( keycode );
			if ( keyword )
			{
				Print4x5Text( keyword, x , y , colour );
			}
		}
		else
		{
			if ( MenuState == MENUSTATE_Keydef && Item == KeyItem )
			{
				Print4x5Text( LT_Undef/*"undef"*/, x , y , colour );
			}
		}
	}
 
}



/*�������������������������������������������������������������������
	Procedure	:		Select a keydef menuitem
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void SelectKeyDef( MENUITEM *Item )
{	
	MenuState = MENUSTATE_Keydef;
	KeyItem = Item;
	PlaySfx( SFX_InGameMenuSelect, 1.0F );
}



/*�������������������������������������������������������������������
	Procedure	:		Draw a keydef menuitem
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void DrawKeyDef( MENUITEM *Item )
{
	DEFKEY *keydef;
	VirtualKeycode keycode;
	char *keyword;
	int	x;
	int	y;
	int colour;
	static char place[ 80 ];
	int page;

	x = (int) ( ( Item->x >> 1 ) * ModeScaleX[ModeCase] );
	y = (int) ( ( Item->y >> 1 ) * ModeScaleY[ModeCase] );

	page = (int) Item->Value;
	if ( Item->Variable && page == CurrentPage )
	{
		keydef = (DEFKEY *)(Item->Variable);
		keycode = keydef->def->key[ keydef->selected_key ];
		if ( MenuState == MENUSTATE_Keydef && Item == KeyItem )
		{
			colour = SelectionColour();
		}
		else
		{
			colour = 1;
		}
		if ( keydef->def->keys > 1 )
		{
			sprintf( place, "[%d/%d]", keydef->selected_key + 1, keydef->def->keys );
			Print4x5Text( place, x - 8 * FontWidth, y, colour );
		}
		if ( keycode )
		{
			keyword = (char *) key_name( keycode );
			if ( keyword )
			{
				Print4x5Text( keyword, x , y , colour );
			}
		}
		else
		{
			if ( MenuState == MENUSTATE_Keydef && Item == KeyItem )
			{
				Print4x5Text( LT_Undef, x , y , colour );
			}
		}
	}
 
}



/*�������������������������������������������������������������������
	Procedure	:		Set the Rendering States...
	Input		:		Nothing...
	Output		:		Nothing
�������������������������������������������������������������������*/
void SetOurRenderStates( MENUITEM *item )
{
	// Perspective Correct
	myglobs.rstate.bPerspCorrect = 0;
	if( PerspectiveCorrect )
		myglobs.rstate.bPerspCorrect = 1;

#ifdef TRILINEAR_MENU_OPTION

	if ( MipMap )
	{
		if ( !TriLinear && !BiLinearFiltering ) // mip map, no filter
		{
			myglobs.rstate.TextureFilter = D3DFILTER_MIPNEAREST;
		}else if ( TriLinear )	// mip map, tri-linear
		{
			myglobs.rstate.TextureFilter = D3DFILTER_LINEARMIPLINEAR;
		}else if ( BiLinearFiltering )	// mip map, bi-linear
		{
			myglobs.rstate.TextureFilter = D3DFILTER_MIPLINEAR;
		}
	}else
	{
		if ( BiLinearFiltering )	// bi-linear
		{
			myglobs.rstate.TextureFilter = D3DFILTER_LINEAR;
		}else	// no filter
		{
		   myglobs.rstate.TextureFilter = D3DFILTER_NEAREST;
		}	
	}
#else
	// Bi Linear Filtering
	myglobs.rstate.TextureFilter = D3DFILTER_NEAREST;
	if( BiLinearFiltering || MyGameStatus == STATUS_Title || MyGameStatus == STATUS_BetweenLevels)
		myglobs.rstate.TextureFilter = D3DFILTER_LINEAR;
#endif

	D3DAppSetRenderState(&myglobs.rstate);
}
/*�������������������������������������������������������������������
	Procedure	:		Set the Rendering States...
	Input		:		Nothing...
	Output		:		Nothing
�������������������������������������������������������������������*/
void GetOurRenderStates( MENUITEM *item )
{
	// Perspective Correct
//	PerspectiveCorrect = FALSE;
//	if( myglobs.rstate.bPerspCorrect )
//		PerspectiveCorrect = TRUE;

	// Bi Linear Filtering
//	BiLinearFiltering = FALSE;
//	if( myglobs.rstate.TextureFilter == D3DFILTER_LINEAR )
//		BiLinearFiltering = TRUE;
}




/*�������������������������������������������������������������������
	Procedure	:		Initialise the detail level menu items
	Input		:		pointer to menu
	Output		:		Nothing
�������������������������������������������������������������������*/
void InitDetailLevels( MENU *Menu )
{
	MENUITEM *item;

	for ( item = Menu->Item; item->x >= 0; item++ )
	{
		if ( item->Variable == &SWMonoChrome )
		{
			if ( !d3dapp->CurrDriver )
			{
				item->FuncSelect = SelectToggle;
				item->FuncDraw = DrawToggle;
			}
			else
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
		}

		if ( item->Variable == &TriLinear )
		{
			if ( MipMap )
			{
				item->FuncSelect = SelectToggle;
				item->FuncDraw = DrawToggle;
			}else
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
		}
	}
	GetOurRenderStates( NULL );
	Last_SWMonoChrome = SWMonoChrome;
//	BikeDetailSlider.value = 5 - BikeDetail;
}


/*�������������������������������������������������������������������
	Procedure	:		Save values from the detail level menu items
	Input		:		pointer to menu
	Output		:		Nothing
�������������������������������������������������������������������*/
void ExitDetailLevels( MENU *Menu )
{
	BikeDetail = 5 - BikeDetailSlider.value;
	SetGamePrefs();
	SetMultiplayerPrefs();
	if ( SWMonoChrome != Last_SWMonoChrome )
	{
		ReleaseView();
		if ( !InitView() )
		{
			Msg("InitView failed.\n");
			exit( 1 );
		}
	}
}

/*�������������������������������������������������������������������
	Procedure	:		Initialise the biker menu items
	Input		:		pointer to menu
	Output		:		Nothing
�������������������������������������������������������������������*/
void SetLightStates( MENUITEM *item )
{
	if( PrimaryLightDetail ) EnablePrimaryLights();
	else DisablePrimaryLights();
	if( SecondaryLightDetail ) EnableSecondaryLights();
	else DisableSecondaryLights();
	if( PickupLightDetail ) EnablePickupLights();
	else DisablePickupLights();
}


/*�������������������������������������������������������������������
	Procedure	:		Initialise the biker menu items
	Input		:		pointer to menu
	Output		:		Nothing
�������������������������������������������������������������������*/
void InitBikerMenu( MENU *Menu )
{
	Config = *player_config;
	Config.bike = ValidBikeSelected( Config.bike );
	SelectedBike = Config.bike;
	InitPilotMenu( Menu );
}

void InitBikeComputerMenu( MENU *Menu )
{
	BikeComputerList.selected_item = player_config->bikecomp;
	KillBikeChar( NULL );
	UpdateSfxForBikeComputer( player_config->bikecomp );
}

void NewInitBikeMenu ( MENU *Menu)
//same as above, but also stores biker name
{
	Config = *player_config;
	Config.bike = ValidBikeSelected( Config.bike );
	SelectedBike = Config.bike;
	UpdateSfxForBiker( SelectedBike );

	InitBikeList(NULL);

	SelectedBikeFrame = BikeChars[ BikeList.selected_item ];
	SelectedBikeModel = BikeModelLookup[ BikeList.selected_item ];
	SelectedBikeScale = BikeModelScale[ BikeList.selected_item ];
}

/*�������������������������������������������������������������������
	Procedure	:		Save values from the biker menu items
	Input		:		pointer to menu
	Output		:		Nothing
�������������������������������������������������������������������*/
void ExitBikerMenu( MENU *Menu )
{
//	if ( ( memcmp( &Config, player_config, sizeof( Config ) ) ) || ForceConfigSave )
	{
		ForceConfigSave = FALSE;
		*player_config = Config;
		write_config( player_config, biker_config );
	}

	KillBikeChar( Menu );
}


void MoveConfigFile( MENU *Menu )
{
	if ( !PilotReName.text[ 0 ] )
	{
		// new name is empty
		PlaySfx( SFX_Error, 1.0F );
		return;
	}
	if( !_stricmp( old_config, biker_config ) )
	{
		// name not changed
		return;
	}
	if ( !DeleteFile( old_config ) )
	{
		// error deleting old config
		PlaySfx( SFX_Error, 1.0F );
		return;
	}
}

/*�������������������������������������������������������������������
	Procedure	:		Initialise the bike list menu items
	Input		:		pointer to menu
	Output		:		Nothing
�������������������������������������������������������������������*/
void InitBikeList( MENU *Menu )
{
	BikeList.selected_item = ValidBikeSelected( SelectedBike );
	strcpy(bike_name,BikeList.item[BikeList.selected_item]);
}


#if defined ( SHAREWARE ) || defined ( WIN98SHAREWARE )
/*�������������������������������������������������������������������
	Procedure	:		Initialise the in-game bike list menu items
	Input		:		pointer to menu
	Output		:		Nothing
�������������������������������������������������������������������*/
void InitShareWareBikeList( MENU *Menu )
{
	int j;

	ShareWareBikeList.selected_item = -1;
	for ( j = 0; j < ShareWareBikeList.items; j++ )
	{
		if ( !strcmp( ShareWareBikeList.item[ j ], BikeList.item[ SelectedBike ] ) )
		{
			ShareWareBikeList.selected_item = j;
			strcpy(bike_name, ShareWareBikeList.item[ShareWareBikeList.selected_item]);
			break;
		}
	}

	ShareWareBikeList.top_item = 0;
	if (ShareWareBikeList.selected_item == -1)
		ShareWareBikeList.selected_item = 0;

}
#endif

// auto selects bike list and prevents box highlight.
void InitBikeListVDU( MENU *Menu )
{
	MenuState = MENUSTATE_SelectBiker;
	InitBikeList(Menu);

	AddBikeArrow( bike_name, BikeList.selected_item );

	OldSelectedBike = BikeList.selected_item;
	
	strcpy(biker_text,BikerText[BikeList.selected_item]);
	
}


void InitLevelSelectVDU( MENUITEM *Item )
{
	MenuState = MENUSTATE_SelectLevelQuick;
}
/*�������������������������������������������������������������������
	Procedure	:		Initialise the control menu items
	Input		:		pointer to menu
	Output		:		Nothing
�������������������������������������������������������������������*/
void InitControls( MENU *Menu )
{
	float sensi;
	MENUITEM *item;

	Autoleveling = ( Config.autolevel_rate != 0.0F ) ? TRUE : FALSE;

	sensi = Config.mouse_x_sensitivity;
	SensitivityXSlider.value = (int) (sensi / 0.12F);
	
	sensi = Config.mouse_y_sensitivity;
	SensitivityYSlider.value = (int)(sensi / 0.12F);
	
	if ( SensitivityXSlider.value < SensitivityXSlider.min )
		SensitivityXSlider.value = SensitivityXSlider.min;

	if ( SensitivityYSlider.value < SensitivityYSlider.min )
		SensitivityYSlider.value = SensitivityYSlider.min;

	if ( SensitivityXSlider.value > SensitivityXSlider.max )
		SensitivityXSlider.value = SensitivityXSlider.max;

	if ( SensitivityYSlider.value > SensitivityYSlider.max )
		SensitivityYSlider.value = SensitivityYSlider.max;

	if ( Menu )
	{
		for ( item = Menu->Item; item->x >= 0; item++ )
		{
			if ( item->Value == &MENU_Feedback )
			{
				if ( FF_Supported( FB_Joystick ) )
				{
					item->FuncSelect = MenuChange;
					item->FuncDraw = MenuItemDrawName;
				}
				else
				{
					item->FuncSelect = NULL;
					item->FuncDraw = NULL;
				}
			}
		}
	}
}

void SetAutolevel( MENUITEM *item )
{
	Config.autolevel_rate = ( Autoleveling ) ? 0.05F : 0.0F;
}


/*�������������������������������������������������������������������
	Procedure	:		Save values from the controls menu items
	Input		:		pointer to menu
	Output		:		Nothing
�������������������������������������������������������������������*/
void ExitControls( MENU *Menu )
{
	float sensiX, sensiY;
	float halfrange;

	halfrange = ( SensitivityXSlider.max - SensitivityXSlider.min + 1 ) * 0.5F;
	sensiX = 1.0F + ( SensitivityXSlider.value - halfrange ) / halfrange;

	halfrange = ( SensitivityYSlider.max - SensitivityYSlider.min + 1 ) * 0.5F;
	sensiY = 1.0F + ( SensitivityYSlider.value - halfrange ) / halfrange;
	
	Config.mouse_x_sensitivity = sensiX;
	Config.mouse_y_sensitivity = sensiY;

	ExitBikerMenu( NULL );
}




/*�������������������������������������������������������������������
	Procedure	:		compare string function for sorting pilot list
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
static int
_cdecl compare( const void *arg1, const void *arg2 )
{
   /* Compare all of both strings: */
   return _stricmp( ( char* ) arg1, ( char* ) arg2 );
}

static int
_cdecl CompareDemoDate( const void *arg1, const void *arg2 )
{
	FILETIME date;
	HANDLE hfile;
	char *demo;	 
	LONGLONG longdate1, longdate2;

	// get creation date of file 1
	demo = DemoFileName( (char *)arg1 );
	hfile = CreateFile( demo,	// pointer to name of the file 
						GENERIC_READ,	// read mode 
						FILE_SHARE_READ,	// share mode 
						NULL,	// pointer to security descriptor 
						OPEN_EXISTING,	// how to create 
						FILE_ATTRIBUTE_NORMAL,	// file attributes 
						NULL 	// handle to file with attributes to copy  
						);
	if ( hfile != INVALID_HANDLE_VALUE )
	{
		GetFileTime( hfile,	NULL,  NULL, &date );
		longdate1 = ( LONGLONG )date.dwHighDateTime;
		longdate1 <<= 32;
		longdate1 |= ( LONGLONG )date.dwLowDateTime;
	}else
	{
		return 0;
	}
	CloseHandle(hfile);

	// get creation date of file 1
	demo = DemoFileName( (char *)arg2 );
	hfile = CreateFile( demo,	// pointer to name of the file 
						GENERIC_READ,	// read mode 
						FILE_SHARE_READ,	// share mode 
						NULL,	// pointer to security descriptor 
						OPEN_EXISTING,	// how to create 
						FILE_ATTRIBUTE_NORMAL,	// file attributes 
						NULL 	// handle to file with attributes to copy  
						);
	if ( hfile != INVALID_HANDLE_VALUE )
	{
		GetFileTime( hfile,	NULL,  NULL, &date );
		longdate2 = ( LONGLONG )date.dwHighDateTime;
		longdate2 <<= 32;
		longdate2 |= ( LONGLONG )date.dwLowDateTime;
	}else
	{
		return 0;
	}
	CloseHandle(hfile);

	if ( longdate1 < longdate2 )
		return 1;

	if ( longdate1 > longdate2 )
		return -1;

	return 0;
}

/*�������������������������������������������������������������������
	Procedure	:		Initialise the pilot list
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void InitPilotList( void )
{
	HANDLE h;
	WIN32_FIND_DATA ConfigFiles;
	int j;
	char *fname, *bname;

	PilotList.items = 0;
	PilotList.top_item = 0;
	if ((CameraStatus == CAMERA_AtLeftVDU) || (CameraStatus == CAMERA_AtRightVDU))
		PilotList.display_items = 16;
	else
		PilotList.display_items = 8;

	PilotList.selected_item = -1;
	
	h = FindFirstFile( "*.cfg" ,	// pointer to name of file to search for  
						(LPWIN32_FIND_DATA) &ConfigFiles );	// pointer to returned information 

	if ( h == INVALID_HANDLE_VALUE )
		return;

	do{
		bname = PilotList.item[PilotList.items];
		fname = ConfigFiles.cFileName;
		j = strlen( fname ) - strlen( ".cfg" );
		if ( j > 0 && j < MAX_PLAYER_NAME_LENGTH )
		{
			strncpy( bname, fname, j );
			bname[ j ] = 0;
			PilotList.items++;
		}
	}while(	FindNextFile( h , (LPWIN32_FIND_DATA) &ConfigFiles ) );
	qsort( (void *)PilotList.item, (size_t) PilotList.items, sizeof( PilotList.item[ 0 ] ), compare );
	for ( j = 0; j < PilotList.items; j++ )
	{
		if ( !_stricmp( PilotList.item[ j ], biker_name ) )
			PilotList.selected_item = j;
	}
	if ( PilotList.selected_item >= PilotList.top_item + PilotList.display_items )
		PilotList.top_item = PilotList.selected_item - PilotList.display_items + 1;

	FindClose(h);

	PilotList.FuncDelete = DeletePilot;
}

/*�������������������������������������������������������������������
	Procedure	:		Initialise the pilot name
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void InitPilotName( MENU *menu )
{
	strcpy( old_config, biker_config );
	strcpy( PilotName.text, DEFAULT_NEWNAME );
	PilotName.insert_pos = strlen( PilotName.text );
	PilotName.limit_length = MAX_PLAYER_NAME_LENGTH - 1;

	KillBikeChar( NULL );
}


/*�������������������������������������������������������������������
	Procedure	:		Save values from the pilot name
	Input		:		pointer to pilot name menu item
	Output		:		Nothing
�������������������������������������������������������������������*/
void SetPilotName( MENUITEM *item )
{
	FILE *f;
	uint16 tempbike;
	static char fname[ MAX_PATH ];

	if ( !strlen( PilotName.text ) )
		return; // abort if pilot name empty
	sprintf( fname, "%s.cfg", PilotName.text );
	f = fopen( fname, "r" );
	if ( f )
	{
		fclose( f );
		PlaySfx( SFX_Error, 1.0F );
		return; // config file already exists with that name (should display error message)
	}
	InitBikerName( PilotName.text );
	*player_config = default_config;
	strcpy( player_config->name, PilotName.text );
	ReInitJoysticks();
	DefaultJoystickSettings( player_config );
	Config = *player_config;
	Config.bike = ValidBikeSelected( Config.bike );
	write_config( player_config, biker_config );
	tempbike = SelectedBike;
	SelectedBike = Config.bike;
	
	if ( tempbike != SelectedBike )
	{
		// need to swap displayed bike
		GetBikeDetails(SelectedBike, NULL );
		UpdateSfxForBiker( SelectedBike );
		ShowHoloModel( BikeModelLookup[ SelectedBike ] );
	}
	
	InitPilotList();

	if (CurrentMenu == &MENU_NEW_NewPlayer)
		MenuBack();
}


/*�������������������������������������������������������������������
	Procedure	:		Save values from the pilot name
	Input		:		pointer to pilot name menu item
	Output		:		Nothing
�������������������������������������������������������������������*/
void SetPilotNameInGame( MENUITEM *item )
{
	FILE *f;
	static char fname[ MAX_PATH ];

	if ( !strlen( PilotNameInGame.text ) )
		return; // abort if pilot name empty
	sprintf( fname, "%s.cfg", PilotNameInGame.text );
	f = fopen( fname, "r" );
	if ( f )
	{
		fclose( f );
		PlaySfx( SFX_Error, 1.0F );
		return; // config file already exists with that name (should display error message)
	}
	InitBikerName( PilotNameInGame.text );
	*player_config = default_config;
	strcpy( player_config->name, PilotNameInGame.text );
	ReInitJoysticks();
	DefaultJoystickSettings( player_config );
	Config = *player_config;
	Config.bike = ValidBikeSelected( Config.bike );
	write_config( player_config, biker_config );
	SelectedBike = Config.bike;
	
		GetBikeDetails(SelectedBike, NULL );
		UpdateSfxForBiker( SelectedBike );
	
	InitPilotList();
}


/*�������������������������������������������������������������������
	Procedure	:		Initialise the pilot name
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void InitPilotReName( MENU *menu )
{
	strcpy( old_config, biker_config );
	strcpy( PilotReName.text, DEFAULT_NEWNAME );
	PilotReName.insert_pos = strlen( PilotReName.text );
	PilotReName.limit_length = MAX_PLAYER_NAME_LENGTH - 1;

	KillBikeChar( NULL );
}


/*�������������������������������������������������������������������
	Procedure	:		Save values from the pilot name
	Input		:		pointer to pilot name menu item
	Output		:		Nothing
�������������������������������������������������������������������*/
void RenamePilotName( MENUITEM *item )
{
	FILE *f;
	uint16 tempbike;
	static char fname[ MAX_PATH ];

	if ( !strlen( PilotReName.text ) )
		return; // abort if pilot name empty
	sprintf( fname, "%s.cfg", PilotReName.text );
	f = fopen( fname, "r" );
	if ( f )
	{
		fclose( f );
		PlaySfx( SFX_Error, 1.0F );
		return; // config file already exists with that name (should display error message)
	}
	InitBikerName( PilotReName.text );
	strcpy( player_config->name, PilotReName.text );
	Config = *player_config;
	Config.bike = ValidBikeSelected( Config.bike );
	write_config( player_config, biker_config );
	tempbike = SelectedBike;
	SelectedBike = Config.bike;
	
	if ( tempbike != SelectedBike )
	{
		// need to swap displayed bike
		GetBikeDetails(SelectedBike, NULL );
		UpdateSfxForBiker( SelectedBike );
		ShowHoloModel( BikeModelLookup[ SelectedBike ] );
	}
	
	InitPilotList();

	if (CurrentMenu == &MENU_NEW_NewPlayer)
		MenuBack();
}


/*�������������������������������������������������������������������
	Procedure	:		Initialise the pilot menu items
	Input		:		pointer to menu
	Output		:		Nothing
�������������������������������������������������������������������*/
void InitPilotMenu( MENU *Menu )
{
	InitPilotName(NULL);
	InitPilotList();
}

// as above, but auto selects list and highlights current player.
void InitVDUPilotMenu ( MENU *Menu )
{
  
	MENUITEM *Item;
	

	for( Item = Menu->Item ; Item->x >= 0 ; Item++ )
	{	
		if (Item->Variable == &PilotList)
			CurrentMenuItem = Item;
	}
	
	MenuState = MENUSTATE_SelectPlayer;
	InitPilotList();
}

void GetBikeDetails(int Bike, MENUITEM *item)
{

	SelectedBikeFrame = BikeChars[ Bike ];
	SelectedBikeModel = BikeModelLookup[ Bike ];
	SelectedBikeScale = BikeModelScale[ Bike ];
	strcpy(bike_name,BikeList.item[ Bike ]);
	if ( WhoIAm != (uint8) -1 )
		Ships[ WhoIAm ].BikeNum = Bike;
}

/*�������������������������������������������������������������������
	Procedure	:		Save values from the pilot menu items
	Input		:		pointer to menu
	Output		:		Nothing
�������������������������������������������������������������������*/
void SelectPilot( MENUITEM *item )
{
	if ( PilotList.selected_item >= 0 && PilotList.selected_item < PilotList.items )
	{
		InitBikerName( PilotList.item[ PilotList.selected_item ] );
		read_config( player_config, biker_config );

		if ( player_config->bike > ( BikeList.items - 1 ) )
		{
			player_config->bike = 0;
		}		

		Config = *player_config;
		Config.bike = ValidBikeSelected( Config.bike );
		SelectedBike = Config.bike;
		if (SelectedBike > ( BikeList.items - 1 ) )
			SelectedBike = 0;
		UpdateSfxForBiker( SelectedBike );

   
		GetBikeDetails(SelectedBike, item);
	}
}

void SelectTeamList( MENUITEM *Item )
{
	MENUITEM *NewItem;
	
	TeamNumber[WhoIAm] = *((int *)Item->Value);

	// move cursor to ready button...
	for( NewItem = CurrentMenu->Item ; NewItem->x >= 0 ; NewItem++ )
	{	if( NewItem->FuncDraw == DrawReadyButton )
		{  
			CurrentMenuItem = NewItem;
			break;
		}
	}
}

/*�������������������������������������������������������������������
	Procedure	:		Selects a list menuitem
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void SelectList( MENUITEM *Item )
{
	PreListItem = Item;
	PreListMenu = CurrentMenu;
	CurrentList = (LIST *)(Item->Variable);
	CurrentList->Static = FALSE;
	CurrentListItem = Item;
	if( CurrentList->items == 0 )
	{
		CurrentList = NULL;
		return;
	}
	MenuState = MENUSTATE_List;
	OriginalSelection = CurrentList->selected_item;
	if ( CurrentList->selected_item >= 0 && CurrentList->selected_item < CurrentList->items )
	{
		if ( CurrentList->selected_item < CurrentList->top_item
			|| CurrentList->selected_item >= CurrentList->top_item + CurrentList->display_items )
		{
			if ( CurrentList->items <= CurrentList->display_items )
				CurrentList->top_item = 0;
			else if ( CurrentList->selected_item + CurrentList->display_items <= CurrentList->items )
				CurrentList->top_item = CurrentList->selected_item;
			else
				CurrentList->top_item = CurrentList->items - CurrentList->display_items + 1;
		}
	}
	SearchKey( 0 ); // empty search string

}


/*�������������������������������������������������������������������
	Procedure	:		Draw a list menuitem
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void DrawList( MENUITEM *Item )
{
	int x;
	int y;
	LIST *l;
	int j;
	int it;
	int colour;

	l = (LIST *)(Item->Variable);

	if ( l->FuncInfo )
		l->FuncInfo( l );

	x = (int) ( ( Item->x >> 1 ) * ModeScaleX[ModeCase] );
	y = (int) ( ( Item->y >> 1 ) * ModeScaleY[ModeCase] );

	if ( !l )
		return;

	Print4x5Text( Item->StrPnt, x , y , 2 );
	x += (int) ( ( 16 >> 1 ) * ModeScaleX[ModeCase] );
	for ( j = 0; j < l->display_items; j++ )
	{
		it = l->top_item + j;
		if ( it >= l->items )
			break;
		if ( it == l->selected_item )
			colour = ( MenuState == MENUSTATE_List && CurrentList == l ) ? ( SelectionColour() ) : 1;
		else
			colour = 2;
		y += (int) ( (16 >> 1) * ModeScaleY[ModeCase] );
		Print4x5Text( l->item[ it ], x , y , colour );
	}
}



/*�������������������������������������������������������������������
	Procedure	:		List navigation/selection routines
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void SelectListPrev( LIST *l )
{
	if ( l->selected_item > 0 )
		l->selected_item--;
	if ( l->selected_item < l->top_item )
		l->top_item = l->selected_item;
}

void SelectListNext( LIST *l )
{
	if ( l->selected_item < l->items - 1 )
		l->selected_item++;
	if ( l->selected_item >= l->top_item + l->display_items )
		l->top_item = l->selected_item - l->display_items + 1;
}

void SelectListNextPage( LIST *l )
{
	if ( l->selected_item + l->display_items - 1 < l->items - 1 )
	{
		l->selected_item += l->display_items - 1;
		if ( l->items <= l->display_items )
			l->top_item = 0;
		else if ( l->top_item + l->display_items - 1 < l->items - 1 )
			l->top_item += l->display_items - 1;
		else
			l->top_item = l->items - l->display_items + 1;
	}
	else
	{
		l->selected_item = l->items - 1;
		if ( l->selected_item >= l->top_item + l->display_items )
			l->top_item = l->selected_item - l->display_items + 1;
	}
}

void SelectListPrevPage( LIST *l )
{
	if ( l->selected_item - ( l->display_items - 1 ) > 0 )
	{
		l->selected_item -= l->display_items - 1;
		if ( l->items <= l->display_items )
			l->top_item = 0;
		else if ( l->top_item - ( l->display_items - 1 ) > 0 )
			l->top_item -= l->display_items - 1;
		else
			l->top_item = 0;
	}
	else
	{
		l->selected_item = 0;
		if ( l->selected_item < l->top_item )
			l->top_item = l->selected_item;
	}
}

void SelectListHome( LIST *l )
{
	l->selected_item = 0;
	if ( l->selected_item < l->top_item )
		l->top_item = l->selected_item;
}

void SelectListEnd( LIST *l )
{
	l->selected_item = l->items - 1;
	if ( l->selected_item >= l->top_item + l->display_items )
		l->top_item = l->selected_item - l->display_items + 1;
}


void SelectListSearch( LIST *l, char *keyword )
{
	int next;
	int wrap;
	int item;
	int keyword_len;

	if ( !keyword )
		return;
	keyword_len = strlen( keyword );
	if ( !keyword_len )
		return;
	next = -1;
	wrap = -1;
	for ( item = 0; item < l->items; item++ )
	{
		if ( ( item >= l->selected_item ) && ( next == -1 ) && !_strnicmp( l->item[ item ], keyword, keyword_len ) )
		{
			next = item;
		}
		if ( ( item < l->selected_item ) && ( wrap == -1 ) && !_strnicmp( l->item[ item ], keyword, keyword_len ) )
		{
			wrap = item;
		}
	}
	if ( next != -1 )
	{
		l->selected_item = next;
	}
	else if ( wrap != -1 )
	{
		l->selected_item = wrap;
	}
	else
	{
		SearchKey( 0 );
	}
	if ( l->items <= l->display_items )
		l->top_item = 0;
	else if ( l->selected_item < l->top_item )
		l->top_item = l->selected_item;
	else if ( l->selected_item >= l->top_item + l->display_items )
	{
		if ( l->selected_item + l->display_items < l->items )
			l->top_item = l->selected_item;
		else
			l->top_item = l->items - l->display_items + 1;
	}
}


void SelectListItem( LIST *l )
{
	// fill this in if selection function needs to be called...
	if( l == &TeamList[0] )
	{
		SwapTeamIDs( &TeamList[0] , &TeamList[1] );
		SwapListItem( &TeamList[0] , &TeamList[1] );
	}
	if( l == &TeamList[1] )
	{
		SwapTeamIDs( &TeamList[1] , &TeamList[0] );
		SwapListItem( &TeamList[1] , &TeamList[0] );
	}
}

void CancelListSelection( LIST *l )
{
//	MENUITEM *NewItem;

	l->selected_item = OriginalSelection;
	if ( l->selected_item > 0 && l->selected_item < l->items )
	{
		if ( l->selected_item < l->top_item )
			l->top_item = l->selected_item;
		if ( l->selected_item >= l->top_item + l->display_items )
			l->top_item = l->selected_item - l->display_items + 1;
	}
/*
	// dirty hack!!!
	if (CurrentMenu == &MENU_NEW_Team)
	{
		for( NewItem = CurrentMenu->Item ; NewItem->x >= 0 ; NewItem++ )
		{	if(( CurrentMenuItem->Variable == NewItem->Variable ) && (CurrentMenuItem != NewItem))
			{  
				CurrentMenuItem = NewItem;
				break;
			}
		}
	}
*/
}



/*�������������������������������������������������������������������
	Procedure	:		Selects a text menuitem
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void SelectText( MENUITEM *Item )
{
	TEXT *t;

	MenuState = MENUSTATE_Text;
	TextItem = Item;
	t = (TEXT *)(Item->Variable);
	OriginalText = *t;
	t->insert_pos = strlen( t->text );
}

void SelectFlatMenutext( MENUITEM *Item )
{
	TEXT *t;

	t = (TEXT *)(Item->Variable);
	SelectText ( Item );
	MenuState = MENUSTATE_Text2;
	t->VDU_insert_pos = 0;
	TextType (t, 0);	// ensures VDU cursor is placed in correct position

	Item->TextInfo[0]->highlighttype = HIGHLIGHT_Static;
}


/*�������������������������������������������������������������������
	Procedure	:		Draw a text menuitem
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void DrawTextItem( MENUITEM *Item )
{
	int x;
	int y;
	TEXT *t;
	int tx;
	int colour;

	x = (int) ( ( Item->x >> 1 ) * ModeScaleX[ModeCase] );
	y = (int) ( ( Item->y >> 1 ) * ModeScaleY[ModeCase] );

	tx = Print4x5Text( Item->StrPnt, x , y , 2 );
	t = (TEXT *)(Item->Variable);
	Print4x5Text( t->text, -1 , y , 1 );
	if ( MenuState == MENUSTATE_Text && TextItem == Item )
	{
		char hilite[2] = { 0, 0 };

		x = tx + t->insert_pos * FontWidth;
		hilite[ 0 ] = t->text[ t->insert_pos ];
		if ( !hilite[ 0 ] )
			hilite[ 0 ] = '0';
		colour = SelectionColour();
		Print4x5Text( hilite, x , y , colour );
	
	}
}


/*�������������������������������������������������������������������
	Procedure	:		Text editing routines
	Input		:		MENUITEM * Item...
	Output		:		Nothing
�������������������������������������������������������������������*/
void GetVduTextFormattingInfo (TEXT *t)
{
	t->VDU_insert_pos = 0;
	
	TextItem->TextInfo[1]->text = t->text;
	PrintTextItem( TextItem->TextInfo[1] );

	while ((TextItem->TextInfo[1]->endpoint[0] - TextItem->TextInfo[1]->startpoint[0]) < t->insert_pos - t->VDU_insert_pos - 1)
	{
		t->VDU_insert_pos++;
		TextItem->TextInfo[1]->text = &t->text[t->VDU_insert_pos];
		PrintTextItem( TextItem->TextInfo[1] );
	}

	// ensure text is displayed instantly...
	TextItem->TextInfo[1]->currentchar[0] = TextItem->TextInfo[1]->endpoint[0] - TextItem->TextInfo[1]->startpoint[0] + 1;
}


void TextLeft( TEXT *t )
{
	if ( t->insert_pos > 0 )
		t->insert_pos--;
}

void TextRight( TEXT *t )
{
	if ( t->insert_pos < (int) strlen( t->text ) )
		t->insert_pos++;
}

void TextType( TEXT *t, char c )
{
	int len;

	len = strlen( t->text );
	if ( t->FuncType )
		c = t->FuncType( t, c );
	if ( c && ( len < (sizeof( t->text )-2) )
		&& ( !t->limit_length || ( len < t->limit_length ) ) )
	{
		memmove( t->text + t->insert_pos + 1, t->text + t->insert_pos, strlen( t->text ) - t->insert_pos + 1);
		t->text[ t->insert_pos ] = c;
		t->insert_pos++;
	}
}

void TextBackspace( TEXT *t )
{
	if ( t->insert_pos > 0 )
	{
		memmove( t->text + t->insert_pos - 1, t->text + t->insert_pos, strlen( t->text ) - t->insert_pos + 1 );
		t->insert_pos--;
	}

}

void TextDelete( TEXT *t )
{
	memmove( t->text + t->insert_pos, t->text + t->insert_pos + 1, strlen( t->text ) - t->insert_pos );
}

void TextClear( TEXT *t )
{
	t->text[ 0 ] = 0;
	t->insert_pos = 0;

}

void TextHome( TEXT *t )
{
	t->insert_pos = 0;
}

void TextEnd( TEXT *t )
{
	t->insert_pos = strlen( t->text );
}

void TextEnter( MENUITEM *item )
{
	TEXT *t;

	t = (TEXT *)(TextItem->Variable);
	if ( t->FuncSet )
	{
		t->FuncSet( item );
	}
}

void TextCancel( TEXT *t )
{
	*t = OriginalText;

	if (MenuState == MENUSTATE_Text2)
	{
		TextItem->TextInfo[1]->text = t->text;
		PrintTextItem( TextItem->TextInfo[1] );
	}
}

void InitBikerName( char *name )
{
	strncpy( biker_name, name, sizeof( biker_name ) );
	biker_name[ sizeof( biker_name ) - 1 ] = 0;
	sprintf( biker_config, "%s.cfg", name );
    RegSetA("PlayerName", (CONST BYTE *)biker_name, sizeof(biker_name));
	SendGameMessage(MSG_NAME, 0, 0, 0, 0);
}


void InitStartMenu( MENU *Menu )
{
	char bname[256];
	DWORD bname_size = sizeof( bname );

	// ignore command-line CFG file option
#if 0
	char *bname, *fname;

	if ( config_name )
	{
		for ( bname = biker_name , fname = config_name; fname && *fname; bname++, fname++ )
		{
			if ( *fname == '.' )
				break;
			*bname = *fname;
		}
		*bname = 0;
		InitBikerName( biker_name );
		biker_config[ sizeof( biker_config ) - 1 ] = 0;
		config_name = NULL;
	}
#endif
	if ( ghCondemnedKey && (RegGet("PlayerName", (LPBYTE)bname,&bname_size) == ERROR_SUCCESS))  
	{
		InitBikerName( bname );
	}


#if 0 // this is now done in d3dmain.cpp
	if ( ghCondemnedKey )
	{
		GetGamePrefs();
	}
#endif
	read_config( player_config, biker_config );

	if ( player_config->bike > ( BikeList.items - 1 ) )
	{
		player_config->bike = 0;
	}		

	Config = *player_config;
	Config.bike = ValidBikeSelected( Config.bike );
	SelectedBike = Config.bike;
	if (SelectedBike > ( BikeList.items - 1 ) )
		SelectedBike = 0;

	if ( use_local_data )
		MaxPlayersSlider.value = 1; // default to private game when testing own levels

}


static int PlayerCanDebug( char *name )
{
	if ( !_stricmp( name, "Dan" ) )
		return 1;
	if ( !_stricmp( name, "Fodder" ) )
		return 1;
	if ( !_stricmp( name, "Super" ) )
		return 1;
	if ( !_stricmp( name, "Phil" ) )
		return 1;
	return 0;
}

void ExitInGameMenu( MENU *Menu )
{
}


void InitInGameMenu( MENU *Menu )
{
	MENUITEM *item;

	for ( item = Menu->Item; item->x >= 0; item++ )
	{
		if ( item->Value == &MENU_LoadSavedGame || item->Value == &MENU_SaveGame )
		{
			if ( MyGameStatus != STATUS_Normal ) // normal -> multiplayer game, so !normal -> single player
			{
				item->FuncSelect = MenuChange;
				item->FuncDraw = MenuItemDrawName;
			}
			else
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
		}

		if ( item->Value == &MENU_ServerMenu )
		{
			 if ( IsServer )
			 {
				item->FuncSelect = MenuChange;
				item->FuncDraw = MenuItemDrawName;
			 }else
			 {
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			 }
		}

		else if ( item->Value == &MENU_Save || item->Value == &MENU_DebugMode )
		{
			if ( DebugInfo ) // && PlayerCanDebug( biker_name ) )
			{
				item->FuncSelect = MenuChange;
				item->FuncDraw = MenuItemDrawName;
			}
			else
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
		}
		
		else if ( item->Value == DebugVisibleChanged )
		{
			if ( DebugInfo )
			{
				item->FuncSelect = SelectToggle;
				item->FuncDraw = DrawToggle;
			}
			else
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
		}

		if ( item->FuncSelect == SelectQuitCurrentGame )
		{
			if( IsLobbyLaunched )
			{
				item->StrPnt = LT_QuitToLobby/*"quit to lobby"*/;
			}else
			{
				item->StrPnt = LT_QuitToMainMenu/*"Quit to Main Menu"*/;
			}
		}

		if ( item->Value == &MENU_LevelSelect )
		{
			if (( IsLobbyLaunched ) || ( MyGameStatus == STATUS_SinglePlayer ) && !LevelSelectMode )
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}else
			{
				item->FuncSelect = MenuChange;
				item->FuncDraw = MenuItemDrawName;
			}
		}


		if ( item->FuncSelect == GoToStats )
		{
			if ( IsLobbyLaunched && IsHost )
			{
				item->FuncSelect = GoToStats;
				item->FuncDraw = MenuItemDrawName;
			}else
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
		}
	}
}


void InitFeedbackMenu( MENU *Menu )
{
	FeedbackInfo *feedback;
	FF_EffectID id;

	feedback = JoystickInfo[ FB_Joystick ].feedback;

	if ( feedback )
	{
		FeedbackEnable = feedback->enable;
		FeedbackGainSlider.value = (int) floor( 0.5F + (FeedbackGainSlider.min +
			( FeedbackGainSlider.max - FeedbackGainSlider.min ) * feedback->gain ) );
#ifdef FEEDBACK_XYSLIDER
		FeedbackXSlider.value =
			( feedback->xscale < 0.0F ) ? -1 : ( feedback->xscale > 0.0F ) ? 1 : 0;
		FeedbackYSlider.value =
			( feedback->yscale < 0.0F ) ? -1 : ( feedback->yscale > 0.0F ) ? 1 : 0;
#else
		FeedbackXEnable = ( feedback->xscale ) ? TRUE : FALSE;
		FeedbackYEnable = ( feedback->yscale ) ? TRUE : FALSE;
		FeedbackXInvert = ( feedback->xscale < 0.0F ) ? TRUE : FALSE;
		FeedbackYInvert = ( feedback->yscale < 0.0F ) ? TRUE : FALSE;
#endif
		for ( id = (FF_EffectID) 0; id < FF_EFFECT_MAX; id++ )
		{
			FeedbackEffectEnable[ id ] = feedback->effect_setting[ id ].enable;
			FeedbackEffectGainSlider[ id ].min = 0;
			FeedbackEffectGainSlider[ id ].max = 100;
			FeedbackEffectGainSlider[ id ].step = 10;
			FeedbackEffectGainSlider[ id ].value = (int) floor( 0.5F + (FeedbackEffectGainSlider[ id ].min +
				( FeedbackEffectGainSlider[ id ].max - FeedbackEffectGainSlider[ id ].min ) * feedback->effect_setting[ id ].gain ) );
		}
		ForceConfigSave = TRUE;
	}
	else
	{
		FeedbackEnable = FALSE;
	}
}


void ExitFeedbackMenu( MENU *Menu )
{
	FeedbackInfo *feedback;
	int start, stop;
	FF_EffectID id;

	feedback = JoystickInfo[ FB_Joystick ].feedback;
	start = 0;
	stop = 0;

	if ( feedback )
	{
		if ( FeedbackEnable )
		{
			if ( FeedbackGainSlider.value > FeedbackGainSlider.min )
			{
				if ( !feedback->enable )
					start = 1;
			}
			else
			{
				if ( feedback->gain )
					stop = 1;
			}
		}
		else
		{
			if ( feedback->enable )
				stop = 1;
		}
		feedback->enable = FeedbackEnable;
		feedback->gain = (float) ( FeedbackGainSlider.value - FeedbackGainSlider.min ) /
			( FeedbackGainSlider.max - FeedbackGainSlider.min );
#ifdef FEEDBACK_XYSLIDER
		feedback->xscale = ( FeedbackXSlider.value < 0 ) ? -1.0F : ( FeedbackXSlider.value > 0 ) ? 1.0F : 0.0F;
		feedback->yscale = ( FeedbackYSlider.value < 0 ) ? -1.0F : ( FeedbackYSlider.value > 0 ) ? 1.0F : 0.0F;
#else
		feedback->xscale = ( FeedbackXEnable ) ? ( ( FeedbackXInvert ) ? -1.0F : 1.0F ) : 0.0F;
		feedback->yscale = ( FeedbackYEnable ) ? ( ( FeedbackYInvert ) ? -1.0F : 1.0F ) : 0.0F;
#endif
		if ( stop )
			FB_Stop();
		if ( start )
			FB_Start();
		for ( id = (FF_EffectID) 0; id < FF_EFFECT_MAX; id++ )
		{
			feedback->effect_setting[ id ].enable = FeedbackEffectEnable[ id ];
			feedback->effect_setting[ id ].gain = (float) 
				( FeedbackEffectGainSlider[ id ].value - FeedbackEffectGainSlider[ id ].min ) /
				( FeedbackEffectGainSlider[ id ].max - FeedbackEffectGainSlider[ id ].min );
			if ( feedback->effect_setting[ id ].enable )
			{
				if ( feedback->effect_setting[ id ].gain > MIN_GAIN )
				{
					if ( !stop && !FF_EffectPlaying( FB_Joystick, id )
						&& ( id == FF_EFFECT_Damper || id == FF_EFFECT_Inertia ) )
						FF_StartEffect( FB_Joystick, id );
				}
				else
				{
					if ( FF_EffectPlaying( FB_Joystick, id ) )
						FF_StopEffect( FB_Joystick, id );
				}
			}
			else
			{
				if ( FF_EffectPlaying( FB_Joystick, id ) )
					FF_StopEffect( FB_Joystick, id );
			}
		}
	}
}


void InitDebugMode( MENU *Menu )
{
	MENUITEM *item;

	for ( item = Menu->Item; item->x >= 0; item++ )
	{
		if ( item->Value == &ScreenSaving ||
			 item->Value == &OldNodeCube ||
			 item->Value == &NodeCube ||
			 item->Value == &NodeCubeType )
		{
			if ( DebugInfo && PlayerCanDebug( biker_name ) )
			{
				item->FuncSelect = SelectToggle;
				item->FuncDraw = DrawToggle;
			}
			else
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
		}
	}
}



char *SearchKey( char c )
{
	static char search_key[ 256 ] = "";
	static int len = 0;
	static int last_time = 0;
	int this_time;

	this_time = GetTickCount();
	if ( this_time - last_time > 300 )
	{
		len = 0;
	}
	if ( c )
	{
		search_key[ len ] = c;
		search_key[ len + 1 ] = 0;
		len++;
	}
	else
	{
		len = 0;
		search_key[ 0 ] = 0; // kill search key
	}
	last_time = this_time;

	return ( search_key[ 0 ] ) ? search_key : NULL;
}


void SelectQuit( MENUITEM *Item )
{
	SetGamePrefs();
	MyGameStatus = STATUS_QuittingFromTitles;
	//MenuExit();
	MenuAbort();
//#ifdef SHAREWARE
	ShowSplashScreen( SPLASHSCREEN_Quitting );
//#endif
/*	
	SetGamePrefs();
	quitting = TRUE;
	MenuExit();
*/
}


void InitMultiplayerHost( MENU *Menu )
{
	int i;
#ifdef ECTS
	sprintf( MultiPlayerGameName.text, "%s's Game", BikeList.item[ 0 ] );
#else
	sprintf( MultiPlayerGameName.text, LT_PlayersGame/*"%s's Game"*/, biker_name );
#endif

	LevelList.items = 0;
	LevelList.top_item = 0;
	LevelList.display_items = 8;
	LevelList.selected_item = 0;
	NewLevelNum = 0;

    for (i = 0; i < NumLevels; i++)
	{
		strcpy( (char*) &LevelList.item[LevelList.items][0] , (char*) &ShortLevelNames[i][0] );
		LevelList.items++;
    }

}

void InitLobbyWaitingForHost( MENU *Menu )
{
	if ( IsLobbyLaunched )
		NoMenuBack = TRUE;
}

void InitPseudoHostGameScreen( MENU *Menu )
{

	MENUITEM *item;

	IsServerGame = TRUE;
	ColPerspective = ColPerspectiveServer;

	for ( item = Menu->Item; item->x >=0; item++ )
	{
		if ( item->Variable == &MaxServerPlayersSlider )
		{
			DPlayGetSessionDesc();
			if ( glpdpSD && ( glpdpSD->dwUser3 & EnableMaxPlayersChangeBit ) )
			{
				item->FuncSelect = SelectSlider;
			}else
			{
				item->FuncSelect = NULL;
			}
		}
	}
	
	// levels in list will ultimately only be levels that exist both on server and on users machine
	if ( !InitLevels( MULTIPLAYER_LEVELS ) && !InitLevels( DEFAULT_LEVELS ) )
	{
		//Msg( "No multiplayer levels" );
		PrintErrorMessage (LT_NoLevelsInstalled, 1, NULL, ERROR_USE_MENUFUNCS );
		return;
	}

	LoadLevelText( NULL );

	DPlayGetSessionDesc();

	if ( glpdpSD )
	{
		if ( glpdpSD->lpszSessionNameA )
			strncpy( MultiPlayerGameName.text, glpdpSD->lpszSessionNameA, MAXTEXTMSG );

		MaxServerPlayersSlider.max = ( ( glpdpSD->dwUser4 & MaxPlayerBits ) >> MaxPlayers_Shift ); 
	}

	if ( MaxServerPlayersSlider.value > MaxServerPlayersSlider.max )
		MaxServerPlayersSlider.value = MaxServerPlayersSlider.max;
}

void InitMultiplayerHostVDU( MENU *Menu )
{
	MENUITEM *item;
	uint16 selected_level;
	char *pCh;

	if ( IsLobbyLaunched )
		NoMenuBack = TRUE;

	for ( item = Menu->Item; item->x >= 0; item++ )
	{
		if ( item->FuncSelect == SelectQuit )
		{
			if ( !IsLobbyLaunched )
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
		}

		if ( item->Variable == &MaxPlayersSlider )
		{
			if ( IsLobbyLaunched )
			{
				DPlayGetSessionDesc();

				if ( glpdpSD )
				{
					if ( glpdpSD->dwMaxPlayers )
					{
						item->FuncSelect = NULL;
						item->FuncDraw = NULL;
					}else
					{
						glpdpSD->dwMaxPlayers = MAX_PLAYERS;
						DPlaySetSessionDesc( 0 );
						MaxPlayersSlider.value = MAX_PLAYERS;
					}
				}
			}
		}
	}
	
	selected_level = LevelList.selected_item;	// from reg, or zero
	if ( !InitLevels( MULTIPLAYER_LEVELS ) && !InitLevels( DEFAULT_LEVELS ) )
	{
		//Msg( "No multiplayer levels" );
		PrintErrorMessage (LT_NoLevelsInstalled, 1, NULL, ERROR_USE_MENUFUNCS );
		return;
	}
	LevelList.selected_item = selected_level;
	NewLevelNum = LevelList.selected_item;
	LoadLevelText( NULL );

	if ( !IsLobbyLaunched )
	{
#ifdef ECTS
		sprintf( MultiPlayerGameName.text, "%s's Game", BikeList.item[ 0 ] );
#else
		sprintf( MultiPlayerGameName.text, LT_PlayersGame2/*"%s's Game"*/, biker_name );
#endif
	}else
	{
		// if lobby launched, use given session name
		strncpy( MultiPlayerGameName.text, glpdplConnection->lpSessionDesc->lpszSessionNameA, MAXTEXTMSG );
		pCh = strchr( MultiPlayerGameName.text, '~' );
		if ( pCh )
			*pCh = 0;
	}

#ifdef SHAREWARE
	LogosEnable = 0;
#endif
}

void InitMultiplayerHostVDUServer( MENU *Menu )
{
	IsServerGame = TRUE;
	ColPerspective = ColPerspectiveServer;

	InitMultiplayerHostVDU( Menu );
}

void InitMultiplayerHostVDUPeerPeer( MENU *Menu )
{
	IsServerGame = FALSE;
	ColPerspective = ColPerspectivePeerPeer;

	InitMultiplayerHostVDU( Menu );
}

void LoadLevelText( MENU *Menu )
{
	FILE *f;
	char *newlinechar;

	f = fopen( MissionTextNames[ NewLevelNum ], "r" );

	if ( !f )
	{
	 	SelectedLevelText[ 0 ] = 0;
		strncpy( SelectedLevel, LevelList.item[ NewLevelNum ], MAX_TEXT_LENGTH );
		return;
	}

	// read level name
	if ( !fgets( SelectedLevel, MAX_LEVEL_NAME_LENGTH, f ) )
	{
	  	// if error ( as oposed to end of file )
		if ( ferror( f ) != 0 )
		{
		 	SelectedLevel[ 0 ] = 0;
			strncpy( SelectedLevel, LevelList.item[ NewLevelNum ], MAX_TEXT_LENGTH );
			fclose( f );
			return;
		}
	}

	// remove newline char, if any
	newlinechar = strchr( SelectedLevel, '\n' );
	if ( newlinechar )
		*newlinechar = 0;
		

	// read mission text
	if ( !fgets( SelectedLevelText, MAX_LEVEL_TEXT_LENGTH, f ) )
	{
	  	// if error ( as oposed to end of file )
	  	if ( ferror( f ) != 0 )
		{		
			SelectedLevelText[ 0 ] = 0;
			fclose( f );
			return;
		}
	}

	// remove newline char, if any
	newlinechar = strchr( SelectedLevelText, '\n' );
	if ( newlinechar )
		*newlinechar = 0;

	fclose( f );
}

void GetSavedGameData( void )
{
	HANDLE hfile;
	FILETIME Time;
	SYSTEMTIME systime;
	FILE	*	fp;
	int8		buf[ 256 ];
	int8		biker[ 256 ];
	int8		filename[ 256 ];
	int16		i;
	int16		Hours, Minutes, Seconds;
	int16		KilledEnemiesNum, InitEnemiesNum;
	char *ext;
	uint32		MagicNumber;
	uint32		VersionNumber;

	CurrentSavedGameDate[0] = 0;
	CurrentSavedGameLevel[0] = 0;
	CurrentSavedGameTimeLevelPlayed[0] = 0;
	CurrentSavedGameEnemiesKilled[0] = 0;

#ifdef SAVEGAME_SLOTS
	strcpy( filename, SaveGameFileName( LoadSavedGameList.selected_item ) );
#else
	sprintf(filename, "savegame\\%s", LoadSavedGameList.item[ LoadSavedGameList.selected_item ] ); 
#endif

	hfile = CreateFile( filename,	// pointer to name of the file 
						GENERIC_READ,	// read mode 
						FILE_SHARE_READ,	// share mode 
						NULL,	// pointer to security descriptor 
						OPEN_EXISTING,	// how to create 
						FILE_ATTRIBUTE_NORMAL,	// file attributes 
						NULL 	// handle to file with attributes to copy  
						);
	if ( hfile != INVALID_HANDLE_VALUE )
	{
		GetFileTime( hfile,	NULL,  NULL, &Time );
		FileTimeToSystemTime( &Time, &systime );
#ifdef MARKET_USA
		sprintf( CurrentSavedGameDate, "saved %d-%d-%d at %2d:%02d", systime.wMonth, systime.wDay, systime.wYear, systime.wHour, systime.wMinute );
#else
		sprintf( CurrentSavedGameDate, LT_SavedGameName/*"saved %d-%d-%d at %2d:%02d"*/, systime.wDay, systime.wMonth, systime.wYear, systime.wHour, systime.wMinute );
#endif
		CloseHandle(hfile);
	}
	else
	{
#ifdef SAVEGAME_SLOTS
		sprintf( CurrentSavedGameDate, SavedGameInfo( LoadSavedGameList.selected_item ) );
#else
		Msg("invalid saved game file\n");
		return;
#endif
	}

	fp = fopen( filename, "r" );

	if( fp )
	{
		fread( &MagicNumber, sizeof( uint32 ), 1, fp );
		fread( &VersionNumber, sizeof( uint32 ), 1, fp );

		if( ( MagicNumber != MAGIC_NUMBER ) || ( VersionNumber != LOADSAVE_VERSION_NUMBER  ) )
		{
			fclose( fp );
#ifdef SAVEGAME_SLOTS
			sprintf( CurrentSavedGameDate, SavedGameInfo( LoadSavedGameList.selected_item ) );
			Models[ BackgroundModel[ TITLE_MODEL_MenuTVDummy ] ].Visible = 0;
			Models[ BackgroundModel[ TITLE_MODEL_MenuTV ] ].Visible = 1;
			return;
#else
			Msg( "invalid saved game file\n" );
			return;
#endif
		}

		i = 0;
		do
		{
			fread( &buf[i], sizeof(char), 1, fp );
		}
		while( buf[ i++ ] != 0 );
		i = 0;
		do
		{
			fread( &biker[i], sizeof(char), 1, fp );
		}
		while( biker[ i++ ] != 0 );

		fread( &Hours, sizeof( Hours ), 1, fp );
		fread( &Minutes, sizeof( Minutes ), 1, fp );
		fread( &Seconds, sizeof( Seconds ), 1, fp );
		fread( &InitEnemiesNum, sizeof( InitEnemiesNum ), 1, fp );
		fread( &KilledEnemiesNum, sizeof( KilledEnemiesNum ), 1, fp );

		fclose( fp );

		sprintf( CurrentSavedGameLevel, LT_LevelName/*"level name: %s"*/, GetMissionName( buf ) );
		if ( _stricmp( biker, DEFAULT_PLAYER_NAME ) )
			sprintf( CurrentSavedGameTimeLevelPlayed, LT_LevelPlayedFor1/*"%s played for %hd mins %hd secs"*/, biker, Hours * 60 + Minutes, Seconds );
		else
			sprintf( CurrentSavedGameTimeLevelPlayed, LT_LevelPlayedFor2/*"played for %hd mins %hd secs"*/, Hours * 60 + Minutes, Seconds );
		sprintf( CurrentSavedGameEnemiesKilled, LT_EnemiesKilled/*"enemies killed: %hd of %hd"*/, KilledEnemiesNum, InitEnemiesNum );
	}else
	{
#ifndef SAVEGAME_SLOTS
		Msg("invalid saved game file\n");
		return;
#endif
	}

	ext = strstr( filename, SAVEGAME_EXTENSION );
	strcpy( ext, SAVEGAMEPIC_EXTENSION );

	if ( File_Exists( filename ) )
	{
		LoadSavedGamePic( filename );
	}else
	{
		// ensure normal tv is displayed
		Models[ BackgroundModel[ TITLE_MODEL_MenuTVDummy ] ].Visible = 0;
		Models[ BackgroundModel[ TITLE_MODEL_MenuTV ] ].Visible = 1;
	}
}

void InitTitleLoad( MENU *Menu )
{
	InitSinglePlayerGame( NULL );
	InitLoadSavedGameList( NULL );

	if ( LevelList.items ) 
	{
		// if no saved games, go to error screen
		if ( !LoadSavedGameList.items )
		{
			PrintErrorMessage (LT_NoSavedGamesFound/*"no saved games found"*/, 1, NULL, ERROR_DONTUSE_MENUFUNCS);
		}else
		{
			MenuState = MENUSTATE_SelectSavedGame;
			GetSavedGameData();
		}
	}
}

void ExitTitleLoad( MENU *Menu )
{
	// display proper tv
	Models[ BackgroundModel[ TITLE_MODEL_MenuTVDummy ] ].Visible = 0;
	Models[ BackgroundModel[ TITLE_MODEL_MenuTV ] ].Visible = 1;

}

void AllowLevelSelect( MENU *Menu )
{
	MENUITEM *item;

 	// make level selectable / unselectable in front end
	for ( item = Menu->Item; item->x >= 0; item++ )
	{
		if ( item->FuncSelect == InitLevelSelectVDU )
		{
			if ( LevelSelectMode )
			{
				item->highlightflags &= ~TEXTFLAG_Unselectable;
			}
			else
			{
				item->highlightflags |= TEXTFLAG_Unselectable;
			}
		}
	}
}

void InitSinglePlayerGame( MENU *Menu )
{
	if ( !InitLevels( SINGLEPLAYER_LEVELS ) && !InitLevels( DEFAULT_LEVELS ) )
	{
		//Msg( "No single player levels" );
		PrintErrorMessage (LT_NoSinglePlayerLevelsInstalled, 1, NULL, ERROR_USE_MENUFUNCS );
		return;
	}

#ifdef SHAREWARE
	LogosEnable = 0;
#endif

	Lives = 5;

	if( Menu )
		AllowLevelSelect( Menu );
}

void SelectQuitCurrentGame( MENUITEM *Item )
{
	// If the host is performing transfer of stuff to other players wait until hes finished before he quits..
	if( HostDuties && !IsServer )
	{
		if( IsHost )
		{
		 	WaitingToQuit = TRUE;
			return;
		}

		ProcessGuaranteedMessages( FALSE , TRUE , TRUE );
		ServiceBigPacket(TRUE);
	}

	// if lobby launched, we want to quit out completely, back to the lobby launcher
	if ( IsLobbyLaunched )
		MyGameStatus = STATUS_QuittingFromInGame;
	else
		MyGameStatus = STATUS_QuitCurrentGame;
	
	//OKToProcessKeys = FALSE;
}

/*�������������������������������������������������������������������
	Procedure	:		Get last game played info from the registry..
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void GetLastGameInfo( void )
{
#ifndef SELF_PLAY
	DWORD size;
	char templevelname[ 8 ];
	int i;

	Rejoining = FALSE;

    // open/create Condemned registry key 
	size = sizeof(Old_WhoIAm);
	if( RegGet( "OldWhoIAm", (LPBYTE)&Old_WhoIAm , &size ) != ERROR_SUCCESS)
	{
		Old_WhoIAm = (BYTE) -1;
	}
	size = sizeof(DPSESSIONDESC2);
	if( RegGet( "OldSession", (LPBYTE)&Old_Session , &size ) != ERROR_SUCCESS)
	{
		Old_Session.dwUser1 = 0;
	}

	size = sizeof(Old_Kills);
	if( RegGet( "OldKills", (LPBYTE)&Old_Kills , &size ) != ERROR_SUCCESS)
	{
		Old_Kills = 0;
	}
	size = sizeof(Old_Deaths);
	if( RegGet( "OldDeaths", (LPBYTE)&Old_Deaths , &size ) != ERROR_SUCCESS)
	{
		Old_Deaths = 0;
	}
	size = sizeof(Old_TeamNumber);
	if( RegGet( "OldTeamNumber", (LPBYTE)&Old_TeamNumber , &size ) != ERROR_SUCCESS)
	{
		Old_TeamNumber = 0;
	}
	size = sizeof(Old_Name);
	if( RegGet( "OldName", (LPBYTE)&Old_Name[0] , &size ) != ERROR_SUCCESS)
	{
		Old_Name[0] = 0;
	}

	LevelList.selected_item = 0;
	size = sizeof ( templevelname );
	if( RegGet( "LevelName", (LPBYTE)templevelname , &size ) == ERROR_SUCCESS)
	{
		templevelname[ 7 ] = 0;
		for ( i = 0; i < LevelList.items; i++ )
		{
			if ( !_strnicmp( LevelList.item[ i ], templevelname, 7 ) )
			{
				LevelList.selected_item = i;
				break;
			}
		}
	}
#endif
}
/*�������������������������������������������������������������������
	Procedure	:		Set last game played info from the registry..
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void SetLastGameInfo( void )
{
#ifndef SELF_PLAY
	if( RegSet( "OldWhoIAm",  (LPBYTE)&Old_WhoIAm ,  sizeof(Old_WhoIAm) ) != ERROR_SUCCESS )
	{
		return;
	}
	if( RegSet( "OldSession", (LPBYTE)&Old_Session , sizeof(DPSESSIONDESC2) ) != ERROR_SUCCESS )
	{
		return;
	}
	if( RegSet( "OldKills",   (LPBYTE)&Old_Kills ,   sizeof(Old_Kills) ) != ERROR_SUCCESS )
	{
		return;
	}					
	if( RegSet( "OldDeaths",  (LPBYTE)&Old_Deaths ,  sizeof(Old_Deaths) ) != ERROR_SUCCESS )
	{
		return;
	}
	if( RegSet( "OldTeamNumber",  (LPBYTE)&Old_TeamNumber ,  sizeof(Old_TeamNumber) ) != ERROR_SUCCESS )
	{
		return;
	}
	if( RegSetA( "OldName",  (LPBYTE)&Old_Name ,  sizeof(Old_Name) ) != ERROR_SUCCESS )
	{
		return;
	}
#endif
}


#if defined ( SHAREWARE ) || defined ( WIN98SHAREWARE )
void ExitShareWareBikeSelection( MENUITEM * item )
{
	int j;

	if ( ShareWareBikeList.selected_item >= 0 && ShareWareBikeList.selected_item < ShareWareBikeList.items )
	{
		for ( j = 0; j < BikeList.items; j++ )
		{
			if ( !strcmp( BikeList.item[ j ], ShareWareBikeList.item[ ShareWareBikeList.selected_item ] ) )
			{
				BikeList.selected_item = j;
				ExitBikeSelection( item );
				break;
			}
		}
	}
}
#endif

void AddBikeArrow( char *name, int num )
{
	int i;
	BOOL leftarrow = FALSE;
	BOOL rightarrow = FALSE;
	char tempbikename[16];
	char leftarrowchar[2];
	char rightarrowchar[2];

	leftarrowchar[0] = 17;
	leftarrowchar[1] = 0;
	rightarrowchar[0] = 16;
	rightarrowchar[1] = 0;

	for ( i = 0; i < BikeList.items; i++ )
	{
		if ( i < num )
		{
				leftarrow = TRUE;
		}

		if ( i > num )
		{
				rightarrow = TRUE;
		}
	}				   

	strcpy( tempbikename, name );

	if ( leftarrow )
	{
		strcpy( tempbikename, leftarrowchar );
		strcat( tempbikename, name );
	}

	if ( rightarrow )
	{
		strcat( tempbikename, rightarrowchar );
	}

	strcpy( name, tempbikename );
}

void ExitBikeSelection( MENUITEM * item )
{
	
#if 0
	if( ( BikeList.selected_item >= 0 ) && ( BikeList.selected_item < MAXBIKETYPES ) )
	{
		BikeList.selected_item = ValidBikeSelected( BikeList.selected_item );
		if ((CameraStatus != CAMERA_AtStart) && (OldSelectedBike != BikeList.selected_item))
		{
			if ((Title_Timers[TITLE_TIMER_SwapBikes].Status != TITLE_EVENT_TIMER_ACTIVE) && (Title_Timers[TITLE_TIMER_SwapBikes].Status != TITLE_EVENT_TIMER_FINISHED))
			{
				Title_Timers[TITLE_TIMER_SwapBikes].Status = TITLE_EVENT_TIMER_ACTIVE;
 				Title_Timers[TITLE_TIMER_SwapBikes].CurrentTime = 0.0F;
				OldSelectedBikeScale = SelectedBikeScale;
			}else
			{	if (Title_Timers[TITLE_TIMER_SwapBikes].CurrentTime > 0.5F)
				{	for (Event = Title_Events; Event->TriggeredBy >= 0; Event++)
					{
						if (Event->TriggeredBy == TITLE_TIMER_SwapBikes)
						{
				
							if ((Event->Status == TITLE_EVENT_STATUS_ACTIVE) || (Event->Status == TITLE_EVENT_STATUS_FINISHED))
							{
								Event->Status = TITLE_EVENT_STATUS_IDLE;

								if (Event->Status == TITLE_EVENT_STATUS_ACTIVE)
								{
									if (Event->ExitFunc)
										Event->ExitFunc(Event);
								}

								Title_Timers[TITLE_TIMER_SwapBikes].Status = TITLE_EVENT_TIMER_ACTIVE;
			 					Title_Timers[TITLE_TIMER_SwapBikes].CurrentTime = 0.0F;
								OldSelectedBikeScale = BikeSwapScale;
							}

						}
					}
		
				}
			}
		}
	}
#endif

	if( CameraStatus != CAMERA_AtStart )
		ShowHoloModel( HoloModelLookup[ BikeList.selected_item ] );

//		SelectedBike = BikeModels[ BikeList.selected_item ];
	SelectedBike = BikeList.selected_item;
	SelectedBikeFrame = BikeChars[ BikeList.selected_item ];
	SelectedBikeModel = BikeModelLookup[ BikeList.selected_item ];
	OldSelectedBikeScale = SelectedBikeScale;
	SelectedBikeScale = BikeModelScale[ BikeList.selected_item ];
	Config.bike = SelectedBike;
	player_config->bike = Config.bike;
	ForceConfigSave = FALSE;
	write_config( player_config, biker_config );
	strcpy(bike_name,BikeList.item[BikeList.selected_item]);
	AddBikeArrow( bike_name, SelectedBike );
	strcpy(biker_text,BikerText[BikeList.selected_item]);
	if ( WhoIAm != -1 )
	{
		Ships[ WhoIAm ].BikeNum = ( SelectedBike % MAXBIKETYPES );
	}

	UpdateSfxForBiker( SelectedBike );
}

void ExitBikeComputerSelection( MENUITEM * item )
{
	player_config->bikecomp = BikeComputerList.selected_item;
	Config.bikecomp = player_config->bikecomp;	// backward compatability
	
	UpdateSfxForBikeComputer( player_config->bikecomp );

	if( MyGameStatus == STATUS_Title )
		MenuBack();
}

void ExitMoreMultiplayerOptions( MENU *Menu )
{
	if ( IsLobbyLaunched )
		NoMenuBack = TRUE;
}

void InitInGameOptions( MENU *Menu )
{
	MENUITEM *item;

	for ( item = Menu->Item; item->x >= 0; item++ )
	{
		if ( item->Variable == &PacketsSlider )
		{
			if ( IsServerGame && !IsServer )
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
			else
			{
				item->FuncSelect = SelectSlider;
				item->FuncDraw = DrawSlider;
			}
		}							  
	}
}

void InitMoreMultiplayerOptions( MENU *Menu )
{
	MENUITEM *item;

	for ( item = Menu->Item; item->x >= 0; item++ )
	{
		if ( item->Value == (void *)COLPERS_Server )
		{
			if ( IsServerGame )
			{
				item->FuncSelect = SelectFlatRadioButton;
				item->FuncDraw = DrawFlatRadioButton;
			}else
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
		}
		
		if ( item->Variable == &BountyBonus )
		{
			if ( GameType == GAME_BountyHunt
				|| GameType == GAME_TeamBounty )
			{
				item->FuncSelect = SelectFlatMenuToggle;
				item->FuncDraw = DrawFlatMenuToggle;
			}
			else
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
		}
		else if ( item->Variable == &BountyBonusSlider )
		{
			if ( GameType == GAME_BountyHunt
				|| GameType == GAME_TeamBounty )
			{
				item->FuncSelect = SelectSlider;
				item->FuncDraw = DrawFlatMenuSlider;
			}
			else
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
		}
		else if ( item->Variable == &PacketsSlider )
		{
			if ( IsServerGame && !IsServer )
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
			else
			{
				item->FuncSelect = SelectSlider;
				item->FuncDraw = DrawFlatMenuSlider;
			}
		}
		else if ( item->Variable == &GoalScoreSlider )
		{
			if ( GameType == GAME_CaptureFlag
				|| GameType == GAME_CTF )
			{
				item->FuncSelect = SelectSlider;
				item->FuncDraw = DrawFlatMenuSlider;
			}
			else
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
		}
		else if ( item->Variable == &CTFSlider )
		{
			if ( GameType == GAME_CTF )
			{
				item->FuncSelect = SelectSlider;
				item->FuncDraw = DrawFlatMenuSlider;
			}
			else
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
		}
		else if ( item->Variable == &HarmTeamMates )
		{
			if ( GameType == GAME_Team
				|| GameType == GAME_CaptureFlag
				|| GameType == GAME_CTF 
				|| GameType == GAME_TeamBounty )
			{
				item->FuncSelect = SelectFlatMenuToggle;
				item->FuncDraw = DrawFlatMenuToggle;
			}
			else
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
		}
		/*
		else if ( item->Variable == &LagCompensation )
		{
			if ( !IsServerGame )
			{
				item->FuncSelect = SelectFlatMenuToggle;
				item->FuncDraw = DrawFlatMenuToggle;
			}
			else
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
		}
		*/
		else if ( item->Variable == &RecordDemo )
		{
			if ( !BigPackets && !IsServerGame )
			{
				item->FuncSelect = SelectFlatMenuToggle;
				item->FuncDraw = DrawFlatMenuToggle;
			}
			else
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
		}
		
		else if ( item->Variable == &UseShortPackets )
		{
			if ( !IsServerGame )
			{
				item->FuncSelect = SelectFlatMenuToggle;
				item->FuncDraw = DrawFlatMenuToggle;
			}
			else
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
		}
		else if ( item->Variable == &BigPackets )
		{
			if ( !IsServerGame )
			{
				item->FuncSelect = SelectFlatMenuToggle;
				item->FuncDraw = DrawFlatMenuToggle;
			}
			else
			{
				item->FuncSelect = NULL;
				item->FuncDraw = NULL;
			}
		}
	}
}

/*�������������������������������������������������������������������
	Procedure	:		Menu Go full Screen....or window....
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void MenuGoFullScreen( MENUITEM *Item )
{
	if (!d3dapp->bFullscreen)
	{
	    /*
	     * Enter the current fullscreen mode.  D3DApp may
	     * resort to another mode if this driver cannot do
	     * the currently selected mode.
	     */
	    D3DAppFullscreen(d3dapp->CurrMode);
	}else{
        D3DAppWindow(D3DAPP_YOUDECIDE, D3DAPP_YOUDECIDE);
	}
}
	


/*�������������������������������������������������������������������
		Mode changing stuff..
�������������������������������������������������������������������*/
void MakeModeList( MENU *Menu )
{
	int i;
	ModeList.items = 0;
	ModeList.top_item = 0;

	if ((CameraStatus == CAMERA_AtLeftVDU) || (CameraStatus == CAMERA_AtRightVDU))
		ModeList.display_items = 16;
	else
		ModeList.display_items = 8;

	ModeList.selected_item = 0;

	// read em backwards so low res modes come first...
	for( i = d3dapp->NumModes-1 ; i >= 0 ; i-- )
	{
		if( d3dapp->Mode[i].bThisDriverCanDo != 0 )
		{
			if( ModeList.items < MAXLISTITEMS )
			{
				if( d3dapp->Mode[i].bpp >= 32  )
				{
					WhichMode[ModeList.items] = i;
					sprintf( &ModeList.item[ModeList.items][0] , "%d x %d x %d" ,
						d3dapp->Mode[i].w , d3dapp->Mode[i].h , d3dapp->Mode[i].bpp );

					if( (d3dapp->Mode[i].w == d3dapp->ThisMode.w) &&				
						(d3dapp->Mode[i].h == d3dapp->ThisMode.h) &&
						(d3dapp->Mode[i].bpp == d3dapp->ThisMode.bpp) )
					{
						ModeList.selected_item = ModeList.items;
					}
					
					ModeList.items++;
				}
			}
		}
	}

}

/*�������������������������������������������������������������������
	Procedure	:		Menu Select a Mode...
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void MenuSelectMode( MENU *Menu )
{
     /*
	 * Enter the current fullscreen mode.  D3DApp may
	 * resort to another mode if this driver cannot do
	 * the currently selected mode.
	 */
	if ( d3dapp->CurrMode != WhichMode[ModeList.selected_item] )
		D3DAppFullscreen(WhichMode[ModeList.selected_item]);
}


void NewMenuSelectMode( MENUITEM *Item )
{

   	/*
	if (!WasteAFrame)
	{
		LastMenu = CurrentMenu;
   		VduClear();
		WasteAFrame = TRUE;
		return;
	}
	*/

	LastMenu = CurrentMenu;	
	VduClear();

     /*
	 * Enter the current fullscreen mode.  D3DApp may
	 * resort to another mode if this driver cannot do
	 * the currently selected mode.
	 */
	D3DAppFullscreen(WhichMode[ModeList.selected_item]);

	FadeHoloLight(HoloLightBrightness);
	DarkenRoom2(RoomDarkness);
	ProcessVduItems( CurrentMenu );

   	InitialTexturesSet = FALSE;
}
/*�������������������������������������������������������������������
		Texture Format changing stuff..
�������������������������������������������������������������������*/
void MakeTextureList( MENU *Menu )
{
	int i;
	TextureList.items = 0;
	TextureList.top_item = 0;

	if ((CameraStatus == CAMERA_AtLeftVDU) || (CameraStatus == CAMERA_AtRightVDU))
		TextureList.display_items = 16;
	else
		TextureList.display_items = 8;

	TextureList.selected_item = 0;

	TextureList.items = d3dapp->NumTextureFormats;
    for (i = 0; i < d3dapp->NumTextureFormats; i++)
	{
        if (d3dapp->TextureFormat[i].bPalettized) {
				sprintf( &TextureList.item[i][0] , "%d-bit Palettized" , d3dapp->TextureFormat[i].IndexBPP );
        } else {

            sprintf(&TextureList.item[i][0], "%d%d%d%d RGBA",
					 d3dapp->TextureFormat[i].RedBPP,
                     d3dapp->TextureFormat[i].GreenBPP,
                     d3dapp->TextureFormat[i].BlueBPP,
                     d3dapp->TextureFormat[i].AlphaBPP);
        }

		if( i == d3dapp->CurrTextureFormat )
			TextureList.selected_item = i;
	}
}

/*�������������������������������������������������������������������
	Procedure	:		Menu Select Texture Format..
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void MenuTextureMode( MENU *Menu )
{
	if( d3dapp->CurrTextureFormat != TextureList.selected_item )
	{
		ReleaseView();
		D3DAppChangeTextureFormat( TextureList.selected_item );

		if ( !InitView() )
			exit( 1 );
	}
}

void NewMenuTextureMode( MENU *Menu )
{
	if( d3dapp->CurrTextureFormat != TextureList.selected_item )
	{
		ReleaseView();
		D3DAppChangeTextureFormat( TextureList.selected_item );

		if ( !InitView() )
			exit( 1 );

		InitialTexturesSet = FALSE;
		FadeHoloLight(HoloLightBrightness);
		DarkenRoom2(RoomDarkness);
	}
}

int AllowGame( void )
{
#if !defined( SELF_PLAY ) && defined( EXTRA_IP ) && !defined( FINAL_RELEASE )
	time_t expire_time;
	time_t now;
	time_t expired;
	DWORD size;

    // open/create Condemned registry key 
	if ( !ghCondemnedKey )
	{
#ifdef FINAL_RELEASE
		RegOpenKeyEx(REGISTRY_ROOT_KEY,
			REGISTRY_GAME_KEY,
			0,
			KEY_ALL_ACCESS,
			&ghCondemnedKey
			);
#else
		RegCreateKeyEx(REGISTRY_ROOT_KEY,
						REGISTRY_GAME_KEY,
						0,
						NULL,                   
						REG_OPTION_NON_VOLATILE,
						KEY_ALL_ACCESS,
						NULL,
						&ghCondemnedKey,
						&gdwCondemnedDisp
						);
#endif
	}
	expire_time = compile_time() + EXPIRE_DAYS * 24 * 60 * 60; // expires 14 days after last compilation
	time( &now );
	if ( now >= expire_time )
	{
		if( RegSet( REGISTRY_EXPIRE_TIME,  (LPBYTE)&expire_time ,  sizeof(expire_time) ) != ERROR_SUCCESS )
		{
			return 0;
		}
		return 0;
	}

	size = sizeof( expired );
	if( RegGet( REGISTRY_EXPIRE_TIME, (LPBYTE)&expired, &size ) == ERROR_SUCCESS)
	{
		if ( expired >= expire_time )
			return 0;
	}
#endif
	return 1;
}



/*�������������������������������������������������������������������
	Procedure	:		Get Version of Current exe...
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void CreateVersion(void)
{
#ifdef MULTIPLAYER_VERSION
	Version = MULTIPLAYER_VERSION;
#else
	HANDLE hfile;
	FILETIME Time;
	WORD	date;
	WORD	time;

	hfile = CreateFile( "ProjectX.exe",	// pointer to name of the file 
						GENERIC_READ,	// access (read-write) mode 
						FILE_SHARE_READ,	// share mode 
						NULL,	// pointer to security descriptor 
						OPEN_EXISTING,	// how to create 
						FILE_ATTRIBUTE_NORMAL,	// file attributes 
						NULL 	// handle to file with attributes to copy  
						);

	GetFileTime( hfile,	// identifies the file 
			     NULL,	// address of creation time 
			     NULL,	// address of last access time  
			     &Time	// address of last write time 
				 );
	FileTimeToDosDateTime( &Time , &date , &time );

//	Version = 0;
	Version = date;
//	Version <<= 16;		
//	Version |=time;

	CloseHandle(hfile);
#endif
}

/*�������������������������������������������������������������������
	Procedure	:		finished viewing the copyright screen ...
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void ChangeStatus_Title ( MENUITEM * Item )
{
	ReleaseView();
	MyGameStatus = STATUS_Title;

#ifndef SELF_PLAY
	//MenuChange( Item );
	MenuRestart( &MENU_Start );
	CurrentSplashScreen = INITIAL_SPLASH_SCREEN;
	if (!InitView())
	{
       Msg("InitView failed.\n");
	   exit(1);
	}
#else
	StartAttractModeForSelfPlay(NULL);
	CurrentSplashScreen = INITIAL_SPLASH_SCREEN;
#endif

	//set initial texture frames for discs
	//SetTextures(&MENU_NEW_Start);

}


void InitDebugMenu( MENU *Menu )
{
	InitRoomList();
	if ( RoomList.selected_item >= 0 && RoomList.selected_item < RoomList.items )
		strncpy( RoomName.text, RoomList.item[ RoomList.selected_item ], sizeof( RoomName.text ) );
}


void InitRoomList( void )
{
	int j;

	if ( Mloadheader.state )
	{
		RoomList.items = Mloadheader.num_groups;
		RoomList.selected_item = -1;
		for ( j = 0; j < RoomList.items; j++ )
		{
			strncpy( RoomList.item[ j ], Mloadheader.Group[ j ].name, sizeof( RoomList.item[ j ] ) );
			if ( WhoIAm != (uint8) -1 && Ships[WhoIAm].Object.Group == j )
				RoomList.selected_item = j;
		}
	}
	else
	{
		RoomList.items = 0;
		RoomList.selected_item = -1;
	}
}


void SetRoomName( MENUITEM *item )
{
	if ( !strlen( RoomName.text ) )
		return; // abort if room name empty
	if ( GotoRoom( WhoIAm, RoomName.text ) )
	{
		RoomList.selected_item = Ships[WhoIAm].Object.Group;
		AddMessageToQue( "You are now in %s", RoomName.text );
	}
	else
	{
		AddMessageToQue( "Could not find %s", RoomName.text );
		AddMessageToQue( "You are still in %s", Mloadheader.Group[ Ships[WhoIAm].Object.Group ].name );
	}
	MenuExit();
}


void ChooseRoom( MENUITEM *item )
{
	if ( RoomList.selected_item < 0 || RoomList.selected_item >= Mloadheader.num_groups )
		return; // abort if invalid room
	if ( GotoRoom( WhoIAm, RoomList.item[ RoomList.selected_item ] ) )
	{
		strncpy( RoomName.text, RoomList.item[ RoomList.selected_item ], sizeof( RoomName.text ) );
		AddMessageToQue( "You are now in %s", RoomList.item[ RoomList.selected_item ] );
	}
	else
	{
		AddMessageToQue( "Could not find %s", RoomList.item[ RoomList.selected_item ] );
		AddMessageToQue( "You are still in %s", Mloadheader.Group[ Ships[WhoIAm].Object.Group ].name );
	}
	MenuExit();
}

int8	DebuggingString[] = "Cheating";
int8	NotDebuggingString[] = "No Longer Cheating";

void DebugModeChanged( MENUITEM *item )
{
	if( DebugInfo )
	{
		strcpy( &MacroText4.text[0], &DebuggingString[0] );
		SendGameMessage(MSG_TEXTMSG, 0, 0, TEXTMSGTYPE_Taunt1, 0);
		if( !GodMode ) ToggleGodMode( NULL );
	}
	else
	{
		strcpy( &MacroText4.text[0], &NotDebuggingString[0] );
		SendGameMessage(MSG_TEXTMSG, 0, 0, TEXTMSGTYPE_Taunt1, 0);
		if( GodMode ) ToggleGodMode( NULL );
	}
	InitInGameMenu( &MENU_InGame );
}

void DebugVisibleChanged( MENUITEM *item )
{
	int16 i;

	if ( DebugVisible )
	{
		ShowPortal = 1;
        myglobs.bClearsOn = TRUE;
		if (myglobs.rstate.FillMode != D3DFILL_WIREFRAME)
		{
			myglobs.rstate.FillMode = D3DFILL_WIREFRAME;
			D3DAppSetRenderState(&myglobs.rstate);
		}
		for ( i = 0; i < Mloadheader.num_texture_files; i++ )
		{
			TloadBlankTextureSurf( &Tloadheader, Mloadheader.TloadIndex[i] );
		}
		PolyText[STATUS_Normal]	= FALSE;
	}
	else
	{
		ShowPortal = 0;
        myglobs.bClearsOn = FALSE;
		if (myglobs.rstate.FillMode != D3DFILL_SOLID)
		{
			myglobs.rstate.FillMode = D3DFILL_SOLID;
			D3DAppSetRenderState(&myglobs.rstate);
		}
		for ( i = 0; i < Mloadheader.num_texture_files; i++ )
		{
			TloadReloadTextureSurf( &Tloadheader, Mloadheader.TloadIndex[i] );
		}
		PolyText[STATUS_Normal]	= TRUE;
	}
}

void SavePickups( MENUITEM *item )
{
	SavePickupsPositions();
}


void ShowNodeToggle( MENUITEM *item )
{
	ShowNodeNetwork( ( ShowNode ) ? 1 : 0 );
}

void ShowStartPointsToggle( MENUITEM *item )
{
	if( ShowStartPoints )
	{
		DisplayStartPoints();
	}
	else
	{
		InitLines();
	}
}


void TexturesEnabledToggle( MENUITEM *item )
{
	int i;

	for ( i = 0; i < Mloadheader.num_texture_files; i++ )
	{
		if ( TexturesEnabled )
			TloadReloadTextureSurf( &Tloadheader, Mloadheader.TloadIndex[i] );
		else
			TloadBlankTextureSurf( &Tloadheader, Mloadheader.TloadIndex[i] );
	}
}

void InitAvgFrameRateGlobals( MENU *Menu )
{
    sprintf( DemoAvgFpsText, "Avg %.2f FPS", DemoAvgFps );
	sprintf( DemoTotalFramesText, "%d frames %d.%02d",
		DemoGameLoops,
		(int) DemoTotalTime / 60, (int) DemoTotalTime % 60 );
}

void RestoreDemoSettings( void )
{
	PauseDemo = FALSE;
	DemoSpeed.value = 8;
	DemoEyesSelect.value = 0;
	ShowNamesAnyway = FALSE;
}

/*�������������������������������������������������������������������
	Procedure	:		Initialise Demo Name list
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void InitDemoList( MENU * Menu )
{
	HANDLE h;
	WIN32_FIND_DATA DemoFiles;
	int j;
//	char *fname, *bname;
	FILE *DemoFp;

	RestoreDemoSettings();

	if ( !InitLevels( DEMO_LEVELS ) && !InitLevels( DEFAULT_LEVELS ) )
	{
		//Msg( "No demo levels" );
		PrintErrorMessage (LT_NoSinglePlayerLevelsInstalled, 1, NULL, ERROR_USE_MENUFUNCS );
		return;
	}
	DemoList.items = 0;
	DemoList.top_item = 0;
	if (CameraStatus != CAMERA_AtStart)
		DemoList.display_items = 10;
	else
		DemoList.display_items = 8;

	DemoList.selected_item = 0;
	DemoList.item[0][0] = 0;
	h = FindFirstFile( DEMOFILE_SEARCHPATH,	// pointer to name of file to search for  
						(LPWIN32_FIND_DATA) &DemoFiles );	// pointer to returned information 

	if ( h == INVALID_HANDLE_VALUE )
	{
#ifdef FINAL_RELEASE
		static char demopath[ MAX_PATH ];

		sprintf( demopath, "%s" DEMOFILE_SEARCHPATH, cd_path );
		h = FindFirstFile( demopath,	// pointer to name of file to search for  
			(LPWIN32_FIND_DATA) &DemoFiles );	// pointer to returned information
#endif
		if ( h == INVALID_HANDLE_VALUE )
		{
#ifdef FINAL_RELEASE
			DebugPrintf( "No demo files found in %s or %s\n",
				DEMOFILE_SEARCHPATH, demopath );
#endif
			return;
		}
	}

	do{
#if 1
		strncpy( DemoList.item[ DemoList.items ], DemoName( DemoFiles.cFileName ), sizeof( DemoList.item[ 0 ] ) - 1 );
		DemoList.item[ DemoList.items ][ sizeof( DemoList.item[ 0 ] ) - 1 ] = 0;
#else
		for ( bname = DemoList.item[DemoList.items] , fname = DemoFiles.cFileName; fname && *fname; bname++, fname++ )
		{
			if ( *fname == 0 ) //'.' )
				break;
			*bname = *fname;
		}
		*bname = 0;
#endif
		DemoFp = fopen( DemoFileName( DemoList.item[ DemoList.items ] ), "rb" );
#ifdef FINAL_RELEASE
		if ( !DemoFp )
		{
			static char demopath[ MAX_PATH ];

			sprintf( demopath, "%s%s", cd_path, DemoFileName( DemoList.item[ DemoList.items ] ) );
			DemoFp = fopen( demopath, "rb" );
		}
#endif
		if ( DemoFp )
		{
			uint32 mp_version;

			mp_version = ~MULTIPLAYER_VERSION;
			fread( &mp_version, sizeof( mp_version ), 1, DemoFp );
			if ( (mp_version <= MULTIPLAYER_VERSION) && (mp_version >= DEMO_MULTIPLAYER_VERSION) )
			{
				uint16 CopyOfSeed1;
				uint16 CopyOfSeed2;
				BOOL RandomPickups;
				uint32 flags;
				uint32 PackedInfo[ MAX_PICKUPFLAGS ];
				uint16 RandomStartPosModify;
				static char buf[ 256 ];
				int i;

				fread( &CopyOfSeed1, sizeof( CopyOfSeed1 ), 1, DemoFp );
				fread( &CopyOfSeed2, sizeof( CopyOfSeed2 ), 1, DemoFp );
				fread( &RandomPickups, sizeof( RandomPickups ), 1, DemoFp );
				fread( &PackedInfo[ 0 ], sizeof( PackedInfo ), 1, DemoFp );
				
				fread( &flags, sizeof( flags ), 1, DemoFp );
				
				fread( &RandomStartPosModify, sizeof( RandomStartPosModify ), 1, DemoFp );
				
				for( i = 0 ; i < 256 ; i++ )
				{
					fread( &buf[i], sizeof(char), 1, DemoFp );
					if( buf[i] == 0 )
					{
						break;
					}
				}
				
				for (i = 0; i < NumLevels; i++)
				{
					
					if( _stricmp( (char*) &ShortLevelNames[i][0] , (char*) &buf[0] ) == 0 ) 
					{
						break;
					}
				}
				
				if( i < NumLevels )
				{
					DemoList.items++;
				}
			}
			fclose( DemoFp );
		}
	}while(	FindNextFile( h , (LPWIN32_FIND_DATA) &DemoFiles ) && DemoList.items < MAXLISTITEMS );

	qsort( (void *)DemoList.item, (size_t) DemoList.items, sizeof( DemoList.item[ 0 ] ), CompareDemoDate );

	for ( j = 0; j < DemoList.items; j++ )
	{
		if ( !strcmp( DemoList.item[ j ], biker_name ) )
			DemoList.selected_item = j;
	}
	if ( DemoList.selected_item >= DemoList.top_item + DemoList.display_items )
		DemoList.top_item = DemoList.selected_item - DemoList.display_items + 1;

	FindClose(h);

	InitAvgFrameRateGlobals( NULL );
#ifdef SHAREWARE
	LogosEnable = 1;
#endif
	DemoList.FuncDelete = ( DemoList.items > 0 ) ? DeleteDemo : NULL;
}


/*�������������������������������������������������������������������
	Procedure	:		Initialise Load Game Name list
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void InitLoadSavedGameList( MENU * Menu )
{
#ifndef SAVEGAME_SLOTS
	HANDLE h;
#endif
#ifndef SAVEGAME_SLOTS
	WIN32_FIND_DATA SavedFiles;
	char *fname, *bname;
#endif

	LoadSavedGameList.items = 0;

	if (CameraStatus != CAMERA_AtStart)	LoadSavedGameList.display_items = 10;
	else LoadSavedGameList.display_items = 8;

	LoadSavedGameList.item[0][0] = 0;
#ifdef SAVEGAME_SLOTS
	while ( LoadSavedGameList.items < MAX_SAVEGAME_SLOTS )
	{
		char *gameinfo;

		gameinfo = SavedGameInfo( LoadSavedGameList.items );
		strncpy( LoadSavedGameList.item[ LoadSavedGameList.items ], gameinfo, sizeof( LoadSavedGameList.item[ 0 ] ) - 1 );
		LoadSavedGameList.item[ LoadSavedGameList.items ][ sizeof( LoadSavedGameList.item[ 0 ] ) - 1 ] = 0;
		LoadSavedGameList.items++;
	}
	if ( LoadSavedGameList.selected_item < 0 || LoadSavedGameList.selected_item >= LoadSavedGameList.items )
		LoadSavedGameList.selected_item = 0;
	if ( Menu == &MENU_SaveGame )
	{
		int slot;

		for ( slot = 0; slot < LoadSavedGameList.items; slot++ )
		{
			if ( !SaveGameSlotUsed( ( LoadSavedGameList.selected_item + slot ) % LoadSavedGameList.items ) )
			{
				LoadSavedGameList.selected_item = ( LoadSavedGameList.selected_item + slot ) % LoadSavedGameList.items;
				break;
			}
		}
	}
	if ( LoadSavedGameList.selected_item < LoadSavedGameList.top_item )
	{
		if ( LoadSavedGameList.selected_item < LoadSavedGameList.display_items )
			LoadSavedGameList.top_item = 0;
		else
			LoadSavedGameList.top_item = LoadSavedGameList.selected_item;
	}
	else if ( LoadSavedGameList.selected_item >= LoadSavedGameList.top_item + LoadSavedGameList.display_items )
	{
		if ( LoadSavedGameList.selected_item + LoadSavedGameList.display_items > LoadSavedGameList.items )
			LoadSavedGameList.top_item = LoadSavedGameList.items - LoadSavedGameList.display_items + 1;
		else
			LoadSavedGameList.top_item = LoadSavedGameList.selected_item;
	}
#else
	h = FindFirstFile( SAVEGAME_FOLDER "\\" SAVEGAME_FILESPEC SAVEGAME_EXTENSION,	// pointer to name of file to search for  
						(LPWIN32_FIND_DATA) &SavedFiles );	// pointer to returned information 

	if ( h == INVALID_HANDLE_VALUE )
		return;

	do
	{
		for ( bname = LoadSavedGameList.item[ LoadSavedGameList.items ] , fname = SavedFiles.cFileName; fname && *fname; bname++, fname++ )
		{
			if ( *fname == 0 ) //'.' )
				break;
			*bname = *fname;
		}
		*bname = 0;
		LoadSavedGameList.items++;

	}while(	FindNextFile( h , (LPWIN32_FIND_DATA) &SavedFiles ) && LoadSavedGameList.items < MAX_SAVEGAME_SLOTS );

	qsort( (void *)LoadSavedGameList.item, (size_t) LoadSavedGameList.items, sizeof( LoadSavedGameList.item[ 0 ] ), compare );

	FindClose(h);
#endif
//	LoadSavedGameList.FuncDelete = ( LoadSavedGameList.items > 0 ) ? DeleteSavedGame : NULL;
}

/*�������������������������������������������������������������������
	Procedure	:		Demo Pause Compensate
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/

void PauseDemoToggle( MENUITEM *Item )
{
	SelectToggle( Item );
}


/*�������������������������������������������������������������������
	Procedure	:		Init the level select menu...
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/

void InitLevelSelect( MENU *Menu )
{
	int i;

    for (i = 0; i < NumLevels; i++)
	{
		strcpy( (char*) &LevelList.item[LevelList.items][0] , (char*) &ShortLevelNames[i][0] );
		LevelList.items++;
    }

}

void GoToStats( MENUITEM *Item )
{
	CurrentMenu = NULL;
	CurrentMenuItem = NULL;
	MenuStackLevel = 0;
	NewLevelNum++;
	if( NewLevelNum >= LevelList.items )
		NewLevelNum = 0;
	LevelNum = -1;			// Force Level change
}

/*�������������������������������������������������������������������
	Procedure	:	Level has been Changed...
	Input		:	MENU * Menu
	Output		:	nothing
�������������������������������������������������������������������*/
void ExitLevelSelect( MENU * Menu )
{
	CurrentMenu = NULL;
	CurrentMenuItem = NULL;
	MenuStackLevel = 0;
	NewLevelNum = LevelList.selected_item;
//	LevelNum = -1;			// Force Level change even if same level;

	if ( IsServerGame && IsPseudoHost )
	{
		if ( NewLevelNum >= 0 )
		{
			SendGameMessage(MSG_TOSERVER, 0, 0, TOSERVERMSG_ChangeLevel, ( BYTE )NewLevelNum );
		}
	}
}

/*�������������������������������������������������������������������
	Procedure	:		Get Game Prefs..
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void GetGamePrefs( void )
{
#ifndef SELF_PLAY
	DWORD size;
	DWORD temp;

	if ( !ghCondemnedKey )
	{
#ifndef SELF_PLAY
#ifdef FINAL_RELEASE
		RegOpenKeyEx(REGISTRY_ROOT_KEY,
			REGISTRY_GAME_KEY,
			0,
			KEY_ALL_ACCESS,
			&ghCondemnedKey
			);
#else
		RegCreateKeyEx(REGISTRY_ROOT_KEY,
			REGISTRY_GAME_KEY,
			0,
			NULL,                   
			REG_OPTION_NON_VOLATILE,
			KEY_ALL_ACCESS,
			NULL,
			&ghCondemnedKey,
			&gdwCondemnedDisp
			);
#endif
#endif
	}
	if ( !ghCondemnedKey )
		return;

	size = sizeof(temp);


	if( RegGet( "ResetKills", (LPBYTE)&temp , &size ) != ERROR_SUCCESS)
		ResetKillsPerLevel = FALSE;
	else
	{
		if( temp )
		{
			ResetKillsPerLevel = TRUE;
		}else{
			ResetKillsPerLevel = FALSE;
		}
	}


	if( RegGet( "RearCameraActive", (LPBYTE)&temp , &size ) != ERROR_SUCCESS)
		RearCameraActive = 0;
	else
		RearCameraActive = temp;

	if( RegGet( "AutoDetail", (LPBYTE)&temp , &size ) != ERROR_SUCCESS)
		AutoDetail = TRUE;
	else
		AutoDetail = temp;

	if( RegGet( "BikeDetail", (LPBYTE)&temp , &size ) != ERROR_SUCCESS)
		BikeDetailSlider.value = BikeDetailSlider.max;
	else
		BikeDetailSlider.value = temp;

	if( RegGet( "TrailDetail", (LPBYTE)&temp , &size ) != ERROR_SUCCESS)
		TrailDetailSlider.value = TrailDetailSlider.max;
	else
		TrailDetailSlider.value = temp;

	if( RegGet( "BiLinear", (LPBYTE)&temp , &size ) != ERROR_SUCCESS)
		BiLinearFiltering = TRUE;
	else
		BiLinearFiltering = temp;

	if( RegGet( "TriLinear", (LPBYTE)&temp , &size ) != ERROR_SUCCESS)
		TriLinear = FALSE;
	else
		TriLinear = temp;

	if( RegGet( "PerspectiveCorrect", (LPBYTE)&temp , &size ) != ERROR_SUCCESS)
		PerspectiveCorrect = TRUE;
	else
		PerspectiveCorrect = temp;

	if( RegGet( "EnhancedXHair", (LPBYTE)&temp , &size ) != ERROR_SUCCESS)
		EnhancedXHair = FALSE;
	else
		EnhancedXHair = temp;

	if( RegGet( "LensFlare", (LPBYTE)&temp , &size ) != ERROR_SUCCESS)
		LensFlare = TRUE;
	else
		LensFlare = temp;

	if( RegGet( "PickupLightDetail", (LPBYTE)&temp , &size ) != ERROR_SUCCESS)
		PickupLightDetail = TRUE;
	else
		PickupLightDetail = temp;

	if( RegGet( "PrimaryLightDetail", (LPBYTE)&temp , &size ) != ERROR_SUCCESS)
		PrimaryLightDetail = TRUE;
	else
		PrimaryLightDetail = temp;

	if( RegGet( "SecondaryLightDetail", (LPBYTE)&temp , &size ) != ERROR_SUCCESS)
		SecondaryLightDetail = TRUE;
	else
		SecondaryLightDetail = temp;

	if( RegGet( "GoreGuts", (LPBYTE)&temp , &size ) != ERROR_SUCCESS)
		GoreGuts = FALSE;
	else
		GoreGuts = temp;

	SWMonoChrome = ( RegGet( "SWMonoChrome", (LPBYTE)&temp , &size ) == ERROR_SUCCESS)
		? temp : FALSE;

#ifdef SOFTWARE_ENABLE
	if ( RegGet( "SWScreenWidth", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		ScreenWidth = temp;
	else
		ScreenWidth = 0;

	if ( RegGet( "SWScreenHeight", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		ScreenHeight = temp;
	else
		ScreenHeight = 0;

	if ( RegGet( "SWScreenBPP", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		ScreenBPP = temp;
	else
		ScreenBPP = 0;
#else
	if ( RegGet( "ScreenWidth", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		ScreenWidth = temp;
	else
		ScreenWidth = 0;

	if ( RegGet( "ScreenHeight", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		ScreenHeight = temp;
	else
		ScreenHeight = 0;

	if ( RegGet( "ScreenBPP", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		ScreenBPP = temp;
	else
		ScreenBPP = 0;
#endif
	if ( RegGet( "TexturePalettized", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		TexturePalettized = temp;
	else
		TexturePalettized = -1;

	if ( RegGet( "TextureRedBPP", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		TextureRedBPP = temp;
	else
		TextureRedBPP = 0;

	if ( RegGet( "TextureGreenBPP", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		TextureGreenBPP = temp;
	else
		TextureGreenBPP = 0;

	if ( RegGet( "TextureBlueBPP", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		TextureBlueBPP = temp;
	else
		TextureBlueBPP = 0;

	if ( RegGet( "TextureAlphaBPP", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		TextureAlphaBPP = temp;
	else
		TextureAlphaBPP = 0;

	if ( RegGet( "TextureIndexBPP", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		TextureIndexBPP = temp;
	else
		TextureIndexBPP = 0;

	if ( RegGet( "SfxVolume", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		SfxSlider.value = temp;

	if ( RegGet( "CDVolume", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		CDSlider.value = temp;

	if ( RegGet( "CDOn", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		CD_OK = (BOOL)temp;

	if ( RegGet( "BikeEngines", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		BikeEnginesOn = (BOOL)temp;

	if ( RegGet( "Gamma", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
	{
		GammaSlider.value = temp;
		Gamma = ( (double)GammaSlider.value ) / 100.0F;
#ifdef SOFTWARE_ENABLE
	if( SoftwareVersion )
		GlBright = (long) ( Gamma * 32.0F );
#endif
	}

	if ( RegGet( "water", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
	{
		WaterDetailSlider.value = temp;
		CLAMP( WaterDetailSlider.value, WaterDetailSlider.max )	
		SetWaterDetail( &WaterDetailSlider );
	}

	if ( RegGet( "BikerSpeechVolume", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
	{
		BikerSpeechSlider.value = temp;
	}
	if ( RegGet( "BikeCompSpeechVol", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
	{
		BikeCompSpeechSlider.value = temp;
	}
	
	if ( !AllowServer )
	{
		if( RegGet( "AllowServer", (LPBYTE)&temp , &size ) != ERROR_SUCCESS)
			AllowServer = FALSE;
		else
			AllowServer = temp;
	}

#ifdef Z_TRICK
	if ( ZClearsOn )
	{
		if ( RegGet( "ZClear", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
			ZClearsOn = (BOOL)temp;
	}
#endif

	// setting sliders to zero ensures text messages instead of speech
	if ( NoDynamicSfx )
	{
		BikerSpeechSlider.value = 0;
		BikeCompSpeechSlider.value = 0;
	}

	size = sizeof( cd_path );
	if ( RegGet( "IP", (LPBYTE)cd_path, &size) != ERROR_SUCCESS)
		cd_path[ 0 ] = 0;

	SetOurRenderStates( (MENUITEM *)NULL );
	SetSoundLevels( NULL );
#endif
}

/*�������������������������������������������������������������������
	Procedure	:		Set last game played info from the registry..
	Input		:		Nothing
	Output		:		Nothing
�������������������������������������������������������������������*/
void SetGamePrefs( void )
{
	DWORD temp;
	temp = ResetKillsPerLevel;
	RegSet( "ResetKills",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = RearCameraActive;
	RegSet( "RearCameraActive",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = AutoDetail;
	RegSet( "AutoDetail",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = BikeDetailSlider.value;
	RegSet( "BikeDetail",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = TrailDetailSlider.value;
	RegSet( "TrailDetail",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = BiLinearFiltering;
	RegSet( "BiLinear",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = TriLinear;
	RegSet( "TriLinear",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = PerspectiveCorrect;
	RegSet( "PerspectiveCorrect",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = EnhancedXHair;
	RegSet( "EnhancedXHair",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = LensFlare;
	RegSet( "LensFlare",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = PickupLightDetail;
	RegSet( "PickupLightDetail",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = PrimaryLightDetail;
	RegSet( "PrimaryLightDetail",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = SecondaryLightDetail;
	RegSet( "SecondaryLightDetail",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = GoreGuts;
	RegSet( "GoreGuts",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = SWMonoChrome;
	RegSet( "SWMonoChrome", (LPBYTE)&temp , sizeof( temp ) );

#ifdef SOFTWARE_ENABLE
	temp = d3dapp->Mode[ d3dapp->CurrMode ].w;
	RegSet( "SWScreenWidth",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = d3dapp->Mode[ d3dapp->CurrMode ].h;
	RegSet( "SWScreenHeight",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = d3dapp->Mode[ d3dapp->CurrMode ].bpp;
	RegSet( "SWScreenBPP",  (LPBYTE)&temp ,  sizeof(temp) );
#else
	temp = d3dapp->Mode[ d3dapp->CurrMode ].w;
	RegSet( "ScreenWidth",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = d3dapp->Mode[ d3dapp->CurrMode ].h;
	RegSet( "ScreenHeight",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = d3dapp->Mode[ d3dapp->CurrMode ].bpp;
	RegSet( "ScreenBPP",  (LPBYTE)&temp ,  sizeof(temp) );
#endif
	temp = d3dapp->TextureFormat[ d3dapp->CurrTextureFormat ].bPalettized;
	RegSet( "TexturePalettized",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = d3dapp->TextureFormat[ d3dapp->CurrTextureFormat ].RedBPP;
	RegSet( "TextureRedBPP",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = d3dapp->TextureFormat[ d3dapp->CurrTextureFormat ].GreenBPP;
	RegSet( "TextureGreenBPP",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = d3dapp->TextureFormat[ d3dapp->CurrTextureFormat ].BlueBPP;
	RegSet( "TextureBlueBPP",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = d3dapp->TextureFormat[ d3dapp->CurrTextureFormat ].AlphaBPP;
	RegSet( "TextureAlphaBPP",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = d3dapp->TextureFormat[ d3dapp->CurrTextureFormat ].IndexBPP;
	RegSet( "TextureIndexBPP",  (LPBYTE)&temp ,  sizeof(temp) );
	
	temp = SfxSlider.value;
	RegSet( "SfxVolume",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = CDSlider.value;
	RegSet( "CDVolume",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = (DWORD)CD_OK;
	RegSet( "CDOn",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = (DWORD)BikeEnginesOn;
	RegSet( "BikeEngines",  (LPBYTE)&temp ,  sizeof(temp) );
	
	temp = GammaSlider.value;
	RegSet( "Gamma",  (LPBYTE)&temp ,  sizeof(temp) );

	temp = WaterDetailSlider.value;
	RegSet( "water",  (LPBYTE)&temp ,  sizeof(temp) );

	temp = AllowServer;
	RegSet( "AllowServer",  (LPBYTE)&temp ,  sizeof(temp) );

#ifdef Z_TRICK
	temp = ZClearsOn;
	RegSet( "ZClear",  (LPBYTE)&temp ,  sizeof(temp) );
#endif

	if ( !NoDynamicSfx )
	{
		temp = BikerSpeechSlider.value;
		RegSet( "BikerSpeechVolume",  (LPBYTE)&temp ,  sizeof(temp) );
		temp = BikeCompSpeechSlider.value;
		RegSet( "BikeCompSpeechVol",  (LPBYTE)&temp ,  sizeof(temp) );
	}
}

void GetServerPrefs( void )
{
	DWORD size;
	DWORD temp;

	if ( !ghCondemnedKey )
		return;

	size = sizeof(temp);

	MaxServerPlayersSlider.value = ( RegGet( "MaxServerPlayers", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? (uint16) temp : MAX_PLAYERS - 1;
	CLAMP( MaxServerPlayersSlider.value, MaxServerPlayersSlider.max )	

	PseudoHostTimeoutSlider1.value = ( RegGet( "PHTimer1", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? (uint16) temp : 2;
	CLAMP( PseudoHostTimeoutSlider1.value, PseudoHostTimeoutSlider1.max )	

	PseudoHostTimeoutSlider2.value = ( RegGet( "PHTimer2", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? (uint16) temp : 5;
	CLAMP( PseudoHostTimeoutSlider2.value, PseudoHostTimeoutSlider2.max )	

	ServerTimeoutSlider.value = ( RegGet( "ServerTimeout", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? (uint16) temp : ServerTimeoutSlider.max;
	CLAMP( ServerTimeoutSlider.value, ServerTimeoutSlider.max )	

	PseudoHostCanSetMaxPlayers = ( RegGet( "PHCanSetMaxPlayers", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? (BOOL) temp : TRUE;
}

void GetMultiplayerPrefs( void )
{
	DWORD size;
	DWORD temp;
	uint32 pickupflags[ MAX_PICKUPFLAGS ];
	char file[ 256 ];
	int i;

	if ( !ghCondemnedKey )
		return;

	size = sizeof(temp);

	MyBrightShips = ( RegGet( "BrightShips", (LPBYTE)&temp , &size ) == ERROR_SUCCESS)
		? temp : FALSE;

	BikeExhausts = ( RegGet( "BikeExhausts", (LPBYTE)&temp , &size ) == ERROR_SUCCESS)
		? temp : TRUE;

	TimeLimit.value = ( RegGet( "TimeLimit", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? temp : 0;

	PreferedMaxPlayers = ( RegGet( "MaxPlayers", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? (uint16) temp : MAX_PLAYERS;

	MaxKillsSlider.value = ( RegGet( "MaxKills", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? temp : 0;

	UseShortPackets = ( RegGet( "ShortPackets", (LPBYTE)&temp , &size ) == ERROR_SUCCESS)
		? temp : TRUE;

	ResetKillsPerLevel = ( RegGet( "ResetKillsPerLevel", (LPBYTE)&temp , &size ) == ERROR_SUCCESS)
		? temp : FALSE;

	BigPackets = ( RegGet( "GroupPackets", (LPBYTE)&temp , &size ) == ERROR_SUCCESS)
		? temp : TRUE;

	if( DPlayUpdateIntervalCmdLine >= 1 && DPlayUpdateIntervalCmdLine <= 30 )
	{
		PacketsSlider.value	= DPlayUpdateIntervalCmdLine;
	}else{
		PacketsSlider.value = ( RegGet( "Packets", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
			? temp : 6;
	}

	GameType = ( RegGet( "GameType", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? temp : GAME_Normal;

	ColPerspectivePeerPeer = ( RegGet( "LagTolerancePeerPeer", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? temp : COLPERS_Descent;
	if ( ColPerspectivePeerPeer > COLPERS_Descent )
		ColPerspectivePeerPeer = COLPERS_Descent;

	ColPerspectiveServer = ( RegGet( "LagToleranceServer", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? temp : COLPERS_Descent;
	if ( ColPerspectiveServer > COLPERS_Server )
		ColPerspectivePeerPeer = COLPERS_Server;

	ShowPing = ( RegGet( "ShowPing", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? temp : FALSE;

	PingFreqSlider.value = ( RegGet( "PingFreq", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? temp : 10;

	HarmTeamMates = ( RegGet( "HarmTeamMates", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? temp : TRUE;

	CTFSlider.value = ( RegGet( "CTFrules", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? temp : CTF_STANDARD;

	BountyBonus = ( RegGet( "BountyBonus", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? temp : TRUE;

	GoalScoreSlider.value = ( RegGet( "FlagScore", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? temp : 5;

	BountyBonusSlider.value = ( RegGet( "BountyInterval", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? temp : 10;

	ShowTeamInfo = ( RegGet( "TeamInfo", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? temp : FALSE;

	RandomPickups = ( RegGet( "RandomPickups", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? temp : FALSE;

	size = sizeof( pickupflags );
	if ( RegGet( "PickupFlags", (LPBYTE)&pickupflags, &size ) == ERROR_SUCCESS )
	{
		UnpackPickupInfo( pickupflags );
	}

	if ( RegGet( "primarypickups", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
	{
		NumPrimaryPickupsSlider.value = temp;
		CLAMP( NumPrimaryPickupsSlider.value, NumPrimaryPickupsSlider.max )	
		NumPrimaryPickups = NumPrimaryPickupsSlider.value;
	}

	ServerHeartbeat = ( RegGet( "ServerHeartbeat", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? temp : FALSE;

	PeerPeerHeartbeat = ( RegGet( "PeerPeerHeartbeat", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? temp : FALSE;

	TrackersList.selected_item = -1;
	DoHeartbeat = FALSE;
	if ( GetTrackerFiles() )
	{
		TrackersList.selected_item = 0;
		size = sizeof( file );
		if ( RegGet( "TrackerFile", (LPBYTE)file, &size ) == ERROR_SUCCESS )
		{
			for ( i = 0; i < TrackersList.items; i++ )
			{
				if ( !_stricmp( TrackersList.item[ i ], file ) )
				{
					TrackersList.selected_item = i;
					sprintf( file, "tracker\\%s.trk", TrackersList.item[ TrackersList.selected_item ] );
					DoHeartbeat = read_heartbeat_info( file );
					break;
				}
			}
		}
	}

	ThrottleSlider.value = ( RegGet( "ThrottleSlider", (LPBYTE)&temp, &size ) == ERROR_SUCCESS )
		? temp : 1000;

}

void SetServerPrefs( void )
{
	DWORD temp;

	temp = (DWORD)MaxServerPlayersSlider.value;
	RegSet( "MaxServerPlayers", (LPBYTE)&temp, sizeof( temp ) );

	temp = (DWORD)PseudoHostTimeoutSlider1.value;
	RegSet( "PHTimer1", (LPBYTE)&temp, sizeof( temp ) );

	temp = (DWORD)PseudoHostTimeoutSlider2.value;
	RegSet( "PHTimer2", (LPBYTE)&temp, sizeof( temp ) );

	temp = (DWORD)ServerTimeoutSlider.value;
	RegSet( "ServerTimeout", (LPBYTE)&temp, sizeof( temp ) );

	temp = (DWORD)PseudoHostCanSetMaxPlayers;
	RegSet( "PHCanSetMaxPlayers", (LPBYTE)&temp, sizeof( temp ) );
}


void SetMultiplayerPrefs( void )
{			  
	DWORD temp;
	uint32 pickupflags[ MAX_PICKUPFLAGS ];
	char full_level_name[ MAX_LEVEL_NAME_LENGTH ];

	temp = MyBrightShips;
	RegSet( "BrightShips",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = BikeExhausts;
	RegSet( "BikeExhausts",  (LPBYTE)&temp ,  sizeof(temp) );
	temp = TimeLimit.value;
	RegSet( "TimeLimit", (LPBYTE)&temp, sizeof( temp ) );
	temp = PreferedMaxPlayers;
	RegSet( "MaxPlayers", (LPBYTE)&temp, sizeof( temp ) );
	temp = MaxKillsSlider.value;
	RegSet( "MaxKills", (LPBYTE)&temp, sizeof( temp ) );
	temp = UseShortPackets;
	RegSet( "ShortPackets", (LPBYTE)&temp , sizeof( temp ) );
	temp = ResetKillsPerLevel;
	RegSet( "ResetKillsPerLevel", (LPBYTE)&temp , sizeof( temp ) );

	temp = BigPackets;
	RegSet( "GroupPackets", (LPBYTE)&temp , sizeof( temp ) );
	if( !(DPlayUpdateIntervalCmdLine >= 1 && DPlayUpdateIntervalCmdLine <= 30 ))
	{
		temp = PacketsSlider.value;
		RegSet( "Packets", (LPBYTE)&temp, sizeof( temp ) );
	}
	temp = GameType;
	RegSet( "GameType", (LPBYTE)&temp, sizeof( temp ) );

	temp = ColPerspective;
	if ( IsServerGame )
		RegSet( "LagToleranceServer", (LPBYTE)&temp, sizeof( temp ) );
	else
		RegSet( "LagTolerancePeerPeer", (LPBYTE)&temp, sizeof( temp ) );

	temp =ShowPing;
	RegSet( "ShowPing", (LPBYTE)&temp, sizeof( temp ) );
	temp = PingFreqSlider.value;
	RegSet( "PingFreq", (LPBYTE)&temp, sizeof( temp ) );
	temp = HarmTeamMates;
	RegSet( "HarmTeamMates", (LPBYTE)&temp, sizeof( temp ) );
	temp = BountyBonus;
	RegSet( "BountyBonus", (LPBYTE)&temp, sizeof( temp ) );
	temp = GoalScoreSlider.value;
	RegSet( "FlagScore", (LPBYTE)&temp, sizeof( temp ) );
	temp = CTFSlider.value;
	RegSet( "CTFrules", (LPBYTE)&temp, sizeof( temp ) );
	temp = BountyBonusSlider.value;
	RegSet( "BountyInterval", (LPBYTE)&temp, sizeof( temp ) );
	temp = ShowTeamInfo;
	RegSet( "TeamInfo", (LPBYTE)&temp, sizeof ( temp ) );
	temp = RandomPickups;
	RegSet( "RandomPickups", (LPBYTE)&temp, sizeof ( temp ) );
	PackPickupInfo( pickupflags );
	RegSet( "PickupFlags", (LPBYTE)&pickupflags, sizeof( pickupflags ) );

	temp = NumPrimaryPickupsSlider.value;
	RegSet( "primarypickups",  (LPBYTE)&temp ,  sizeof(temp) );

	temp = ServerHeartbeat;
	RegSet( "ServerHeartbeat",  (LPBYTE)&temp ,  sizeof(temp) );

	temp = PeerPeerHeartbeat;
	RegSet( "PeerPeerHeartbeat",  (LPBYTE)&temp ,  sizeof(temp) );

	RegSetA( "TrackerFile",  (LPBYTE)TrackersList.item[ TrackersList.selected_item ] , sizeof( TrackersList.item[ TrackersList.selected_item ] ) );

	GoalScore = GoalScoreSlider.value;
	BountyBonusInterval = ( BountyBonus ) ? BountyBonusSlider.value : 0;

	// store chosen level name as part of session description
	GetLevelName( full_level_name, MAX_LEVEL_NAME_LENGTH, LevelList.selected_item );
	
	if ( strlen( MultiPlayerGameName.text ) > MAX_SESSION_DESC_LENGTH )
		MultiPlayerGameName.text[ MAX_SESSION_DESC_LENGTH - 1 ] = 0;

	// append '~' char to indicate end of session name ( if not already there )
	if ( !strchr( MultiPlayerGameName.text, '~' ) )
	{
		strcat( MultiPlayerGameName.text, "~" );
		// append level name...
		strncat( MultiPlayerGameName.text, full_level_name, MAX_LEVEL_NAME_LENGTH );
	}

	RegSetA( "LevelName",  (LPBYTE)LevelList.item[ LevelList.selected_item ] , sizeof( LevelList.item[ LevelList.selected_item ] ) );
}


BOOL CompareVectors(VECTOR vector1, VECTOR vector2)
{
	if ((vector1.x == vector2.x) && (vector1.y == vector2.y) && (vector1.z == vector2.z))
		return TRUE;
	else
		return FALSE;
}

void SetTextures (MENU *menu)
{
	int i;

	i = 0;

	while (menu->Item[i].x != -1)
	{	if (i>5)
			Msg("Too many textures to set");	// There should only ever be 6 textures set
		CurrentTextures[i] = menu->Item[i].FrameNo;
		i++;
	}
}

void SetDiscStatus(MENU *menu)
{
	DiscStatus = menu->MenuStatus;
}

/*�������������������������������������������������������������������
	Procedure	:		sets each vertex intensity of a model to a given fraction of the original
	Input		:		Model num, fraction of orig, intensity, ptr to Exclude - list of vertices
						that are to be left unchanged.
	Output		:		nothing

	Note		:		Only allows vertices to be excluded from one group & exec buffer at present.
�������������������������������������������������������������������*/
BOOL TintModelVertices( uint16 Model, float percent, EXCLUDEDVERTICES *Exclude )
{
	D3DEXECUTEBUFFERDESC	DstDebDesc;
	LPD3DLVERTEX			DstlpD3DLVERTEX;
	uint16					Group;
	uint16					Vert;
	uint16					ExecBuf;
	MXLOADHEADER	*		DstMloadheader;
	LPD3DLVERTEX			VertPtr;
	D3DCOLOR				Colour;
	uint8 red, green, blue, alpha;
	int i;
	int *CurrentExclude;
	int NumberToExclude;
	int ExcludedSoFar;

	DstMloadheader = &ModelHeaders[ Model ];

	for( Group = 0; Group < DstMloadheader->num_groups; Group++ )
	{
		for( ExecBuf = 0; ExecBuf < DstMloadheader->Group[ Group ].num_execbufs; ExecBuf++ )
		{   
			if ((Exclude) && (Exclude->ExecBuf == ExecBuf) && (Exclude->Group == Group))
			{	CurrentExclude = Exclude->VertexPtr;
				NumberToExclude = Exclude->NumVertices;
				ExcludedSoFar = 0;
			}
			else
			{
				CurrentExclude = NULL;
				NumberToExclude = 0;
			}
			if (NumberToExclude == EXCLUDE_ALL)
				continue;
		
			memset( &DstDebDesc, 0, sizeof(D3DEXECUTEBUFFERDESC) );
			DstDebDesc.dwSize = sizeof(D3DEXECUTEBUFFERDESC);
			if( DstMloadheader->Group[ Group ].lpExBuf[ ExecBuf ]->lpVtbl->Lock(
							DstMloadheader->Group[ Group ].lpExBuf[ ExecBuf ], &DstDebDesc ) != D3D_OK ) return FALSE;

			DstlpD3DLVERTEX = (LPD3DLVERTEX) DstDebDesc.lpData;

			Vert = DstMloadheader->Group[ Group ].num_verts_per_execbuf[ ExecBuf ];

			VertPtr = DstMloadheader->Group[Group].org_vertpnt[ExecBuf];
		
			for (i=0; i<Vert; i++)
			{
				red = (uint8)RGBA_GETRED(VertPtr->color);
				green = (uint8)RGBA_GETGREEN(VertPtr->color);
				blue = (uint8)RGBA_GETBLUE(VertPtr->color);
				alpha = (uint8)RGBA_GETALPHA(VertPtr->color);
			
			  	if ((CurrentExclude) && (*CurrentExclude == i))
			  	{
			  		ExcludedSoFar++;
			  		if (ExcludedSoFar == NumberToExclude)
			  			CurrentExclude = NULL;
			  		else
			  			CurrentExclude++;
			  	}else
			  	{
			  	red = (uint8)((float)red * percent);
			  	green = (uint8)((float)green * percent);
			  	blue = (uint8)((float)blue * percent);
			  	}
			  
				Colour = RGBA_MAKE( red, green, blue, alpha );
				if( !Colour ) 
					return FALSE;
				
				DstlpD3DLVERTEX->color = Colour;
				DstlpD3DLVERTEX++;

				VertPtr++;
			}

				if( DstMloadheader->Group[ Group ].lpExBuf[ ExecBuf ]->lpVtbl->Unlock(
								DstMloadheader->Group[ Group ].lpExBuf[ ExecBuf] ) != D3D_OK )	return FALSE;
			
		}
	}
	return TRUE;
}

void GetExtremeOffsets( uint16 Model, PLANE *plane, float *minoffset, float *maxoffset )
{
	uint16					Group;
	uint16					ExecBuf;
	MXALOADHEADER	*		ModelHeaderPtr;
	MXLOADHEADER	*		MxModelHeaderPtr;
	int i, TotalVerts;
	LPD3DLVERTEX			VertPtr;
	VECTOR tempvert;
	float dist;


	if ( TitleModelSet[ Model ].DoIMorph )
	{
		ModelHeaderPtr = &MxaModelHeaders[ Models[Model].ModelNum];

		*minoffset = 0.0F;
		*maxoffset = 0.0F;
						  
		for( Group = 0; Group < ModelHeaderPtr->num_groups; Group++ )
		{
			for( ExecBuf = 0; ExecBuf < ModelHeaderPtr->Group[ Group ].num_execbufs; ExecBuf++ )
			{   
				TotalVerts = ModelHeaderPtr->Group[ Group ].num_verts_per_execbuf[ ExecBuf ];
				VertPtr = ModelHeaderPtr->Group[Group].org_vertpnt[ExecBuf];

				for (i=8; i<TotalVerts; i++)	//ignore bounding box, so start at 8...
				{
				tempvert.x = VertPtr[i].x * Models[Model].Xscale;
				tempvert.y = VertPtr[i].y * Models[Model].Yscale;
				tempvert.z = VertPtr[i].z * Models[Model].Zscale;

				//dist = -(POINT_TO_PLANE( &tempvert, plane ));
				dist = tempvert.z;	// assumes z plane!!!

				if (dist > *maxoffset)
					*maxoffset = dist;

				if (dist < *minoffset)
					*minoffset = dist;
				}
			}
		}
	}else
	{
		MxModelHeaderPtr = &ModelHeaders[ Models[Model].ModelNum];

		*minoffset = 0.0F;
		*maxoffset = 0.0F;
						  
		for( Group = 0; Group < MxModelHeaderPtr->num_groups; Group++ )
		{
			for( ExecBuf = 0; ExecBuf < MxModelHeaderPtr->Group[ Group ].num_execbufs; ExecBuf++ )
			{   
				TotalVerts = MxModelHeaderPtr->Group[ Group ].num_verts_per_execbuf[ ExecBuf ];
				VertPtr = MxModelHeaderPtr->Group[Group].org_vertpnt[ExecBuf];

				for (i=8; i<TotalVerts; i++)	//ignore bounding box, so start at 8...
				{
				tempvert.x = VertPtr[i].x * Models[Model].Xscale;
				tempvert.y = VertPtr[i].y * Models[Model].Yscale;
				tempvert.z = VertPtr[i].z * Models[Model].Zscale;

				//dist = -(POINT_TO_PLANE( &tempvert, plane ));
				dist = tempvert.z;

				if (dist > *maxoffset)
					*maxoffset = dist;

				if (dist < *minoffset)
					*minoffset = dist;
				}
			}
		}
	}
}



BOOL MakeTranslucent( uint16 Model )
{
	D3DEXECUTEBUFFERDESC	DstDebDesc;
	LPD3DLVERTEX			DstlpD3DLVERTEX;
	uint16					Group;
	uint16					Vert;
	uint16					ExecBuf;
	MXALOADHEADER	*		DstMloadheader;
	MXLOADHEADER	*		DstMxloadheader;
	LPD3DLVERTEX			ColourPtr;
	D3DCOLOR				Colour;
	uint8 red, green, blue, alpha;
	int i;

	if ( TitleModelSet[ Model ].DoIMorph )
	{
		DstMloadheader = &MxaModelHeaders[ Models[Model].ModelNum];

		for( Group = 0; Group < DstMloadheader->num_groups; Group++ )
		{
			for( ExecBuf = 0; ExecBuf < DstMloadheader->Group[ Group ].num_execbufs; ExecBuf++ )
			{   
				memset( &DstDebDesc, 0, sizeof(D3DEXECUTEBUFFERDESC) );
				DstDebDesc.dwSize = sizeof(D3DEXECUTEBUFFERDESC);
				if( DstMloadheader->Group[ Group ].lpExBuf[ ExecBuf ]->lpVtbl->Lock(
								DstMloadheader->Group[ Group ].lpExBuf[ ExecBuf ], &DstDebDesc ) != D3D_OK ) return FALSE;

				DstlpD3DLVERTEX = (LPD3DLVERTEX) DstDebDesc.lpData;

				Vert = DstMloadheader->Group[ Group ].num_verts_per_execbuf[ ExecBuf ];

				ColourPtr = DstMloadheader->Group[Group].org_vertpnt[ExecBuf];


				for (i=0; i<Vert; i++)
				{
					red = (uint8)RGBA_GETRED(ColourPtr->color);
					green = (uint8)RGBA_GETGREEN(ColourPtr->color);
					blue = (uint8)RGBA_GETBLUE(ColourPtr->color);
					alpha = (uint8)RGBA_GETALPHA(ColourPtr->color);
					
					//red = (uint8)((float)red * BikeCol);
					//green = (uint8)((float)green * BikeCol);
					//blue = (uint8)((float)blue * BikeCol);
					//alpha = (uint8)((float)alpha * BikeAlpha);
					red = 255;
					green = 255;
					blue = 255;
					alpha = 255;
					
					Colour = RGBA_MAKE( red, green, blue, alpha );
					
					DstlpD3DLVERTEX->color = Colour;
					DstlpD3DLVERTEX++;

					ColourPtr++;
				}


				if( DstMloadheader->Group[ Group ].lpExBuf[ ExecBuf ]->lpVtbl->Unlock(
				DstMloadheader->Group[ Group ].lpExBuf[ ExecBuf] ) != D3D_OK )	return FALSE;
				
			}
		}
		return TRUE;
	}else
	{
		DstMxloadheader = &ModelHeaders[ Models[Model].ModelNum];

		for( Group = 0; Group < DstMxloadheader->num_groups; Group++ )
		{
			for( ExecBuf = 0; ExecBuf < DstMxloadheader->Group[ Group ].num_execbufs; ExecBuf++ )
			{   
			
				memset( &DstDebDesc, 0, sizeof(D3DEXECUTEBUFFERDESC) );
				DstDebDesc.dwSize = sizeof(D3DEXECUTEBUFFERDESC);
				if( DstMxloadheader->Group[ Group ].lpExBuf[ ExecBuf ]->lpVtbl->Lock(
								DstMxloadheader->Group[ Group ].lpExBuf[ ExecBuf ], &DstDebDesc ) != D3D_OK ) return FALSE;

				DstlpD3DLVERTEX = (LPD3DLVERTEX) DstDebDesc.lpData;

				Vert = DstMxloadheader->Group[ Group ].num_verts_per_execbuf[ ExecBuf ];

				DstMxloadheader->Group[ Group ].exec_type[ ExecBuf ] = 0;

				ColourPtr = DstMxloadheader->Group[Group].org_vertpnt[ExecBuf];


				for (i=0; i<Vert; i++)
				{
					red = (uint8)RGBA_GETRED(ColourPtr->color);
					green = (uint8)RGBA_GETGREEN(ColourPtr->color);
					blue = (uint8)RGBA_GETBLUE(ColourPtr->color);
					alpha = (uint8)RGBA_GETALPHA(ColourPtr->color);
					
					red = (uint8)((float)red * BikeCol);
					green = (uint8)((float)green * BikeCol);
					blue = (uint8)((float)blue * BikeCol);
					alpha = (uint8)((float)alpha * BikeAlpha);
					
					Colour = RGBA_MAKE( red, green, blue, alpha );
					
					DstlpD3DLVERTEX->color = Colour;
					DstlpD3DLVERTEX++;

					ColourPtr++;
				}


				if( DstMxloadheader->Group[ Group ].lpExBuf[ ExecBuf ]->lpVtbl->Unlock(
				DstMxloadheader->Group[ Group ].lpExBuf[ ExecBuf] ) != D3D_OK )	return FALSE;
				
			}
		}
		return TRUE;
	}
}


BOOL TintOneVertex( uint16 Model, uint16 Group, uint16 ExecBuf, int VertexNo, float tr, float tg, float tb, float ta )
{
	D3DEXECUTEBUFFERDESC	DstDebDesc;
	LPD3DLVERTEX			DstlpD3DLVERTEX;
	MXLOADHEADER	*		DstMloadheader;
	LPD3DLVERTEX			VertPtr;
	D3DCOLOR				Colour;
	uint8 red, green, blue, alpha;
	uint8 vred, vgreen, vblue, valpha;

	DstMloadheader = &ModelHeaders[ Model ];

	memset( &DstDebDesc, 0, sizeof(D3DEXECUTEBUFFERDESC) );
	DstDebDesc.dwSize = sizeof(D3DEXECUTEBUFFERDESC);
	if( DstMloadheader->Group[ Group ].lpExBuf[ ExecBuf ]->lpVtbl->Lock(
					DstMloadheader->Group[ Group ].lpExBuf[ ExecBuf ], &DstDebDesc ) != D3D_OK ) return FALSE;

	DstlpD3DLVERTEX = &((LPD3DLVERTEX) DstDebDesc.lpData)[VertexNo];

	
	VertPtr = &(DstMloadheader->Group[Group].org_vertpnt[ExecBuf])[VertexNo];
	  
	vred = (uint8)RGBA_GETRED(VertPtr->color);
	vgreen = (uint8)RGBA_GETGREEN(VertPtr->color);
	vblue = (uint8)RGBA_GETBLUE(VertPtr->color);
	valpha = (uint8)RGBA_GETALPHA(VertPtr->color);
	
 	red = (uint8)((float)vred * tr);
  	green = (uint8)((float)vgreen * tg);
  	blue = (uint8)((float)vblue * tb);
  	alpha = (uint8)((float)valpha * ta);
/*
	red = 255;
	green = 255;
	blue = 255;
	alpha = 255;
*/
	Colour = RGBA_MAKE( red, green, blue, alpha );
	if( !Colour ) 
		return FALSE;
			
	DstlpD3DLVERTEX->color = Colour;
	
	if( DstMloadheader->Group[ Group ].lpExBuf[ ExecBuf ]->lpVtbl->Unlock(
					DstMloadheader->Group[ Group ].lpExBuf[ ExecBuf] ) != D3D_OK )	return FALSE;
   	
	return TRUE;
}



/*�������������������������������������������������������������������
	Procedure	:		increases the texture frame no. of a disc by one
	Input		:		disc number
	Output		:		nothing
�������������������������������������������������������������������*/
void HighlightDisc(int disc)
{
	if( PolyAnim[disc] )
		PolyAnim[disc]->newframe = CurrentTextures[disc] + 1;

}

/*�������������������������������������������������������������������
	Procedure	:		restores original texture frame of disc
	Input		:		disc number
	Output		:		nothing
�������������������������������������������������������������������*/
void ResetDisc(int disc)
{
	PolyAnim[disc]->newframe = CurrentTextures[disc];
}

/*�������������������������������������������������������������������
	Procedure	:		initialises rotation sequence for difficulty level disc
	Input		:		menu item (not used)
	Output		:		nothing
�������������������������������������������������������������������*/

void DifficultySet (MENUITEM *item)
{
#if 0
	StackMode = DISC_MODE_ONE;
	StackStatus = DISC_EXPAND;
	DifficultyLevel++;
	if( DifficultyLevel > DIFF_Vhard )
		DifficultyLevel = DIFF_Easy;

	PlaySfx( SFX_Stakmove, 1.0F );
#endif

	MenuState = MENUSTATE_DifficultySet;
}

void InitDifficultyLevel ( MENU *Menu )
{
#if 1
	MENUITEM *Item;
	static int DifficultyLookup[ 4 ] = { 4, 6, 8, 10 };

	for ( Item = Menu->Item; Item->x >= 0 ; Item++ )
	{
		if ( Item->y == TITLE_MODEL_Disc3 )
		{
			Item->FrameNo = DifficultyLookup[ DifficultyLevel ];
			break;
		}
	}
#endif
}

TEXTINFO *InitTextInfo( void )
{
	TEXTINFO *TextInfo;

	TextInfo = (TEXTINFO*)malloc ( sizeof (TEXTINFO) );

	if (!TextInfo)
	{	Msg("Title.c   InitTextInfo:  unable to allocate memory\n");
		exit(1);
	}

	TextInfo->text = NULL;						// text string
	TextInfo->highlight = FALSE;					// item highlighted?
	TextInfo->highlighttype = HIGHLIGHT_Pulsing;
	TextInfo->xmin = 0;						// 
	TextInfo->ymin = 0;						// bounding box for text
	TextInfo->xmax = 0;						// (VDU co-ordinates)
	TextInfo->ymax = 0;						// 
	TextInfo->font = FONT_Small;						// font size (small, medium, large)
	TextInfo->flags = 0;						// formatting info
	TextInfo->num_lines = 0;					// number of lines once formatted
	TextInfo->boxdone = FALSE;					
	TextInfo->num_pointers_to_free = 0;		
	TextInfo->force_fit = FALSE;

	return TextInfo;
}

void RedrawFlatMenuList( MENUITEM *Item )
{
#if 1
	LIST *l;
	int i, current;
	TEXTINFO *TextInfo;
	
	l = (LIST *)(Item->Variable);

	if (l->old_top_item != l->top_item)
	{
		l->old_top_item = l->top_item;


		//redraw whole list
		for (i=0; i < l->display_items; i++)
		{
			current = l->top_item + i;

			if (i > (l->items - 1))
				break;

			//write relevent info into structure
			TextInfo = Item->TextInfo[i];

			TextInfo->xmin = Item->x;
			TextInfo->ymin = (((Item->ymax - Item->y)/l->display_items) * i) + Item->y;
			TextInfo->text = l->item[current];
			TextInfo->xmax = Item->xmax;
			TextInfo->ymax = (((Item->ymax - Item->y)/l->display_items) * (i + 1)) + Item->y;
			TextInfo->font = Item->font;
			TextInfo->flags = Item->highlightflags;
	
			if (current == l->selected_item)
				TextInfo->highlight = TRUE;
			else
				TextInfo->highlight = FALSE;

				//format text item...
			PrintTextItem(TextInfo);

		}
		
	}else
	{
	 	if (l->old_selected_item != l->selected_item)
		{
			l->old_selected_item = l->selected_item;


			for (i=0; i < l->display_items; i++)
			{
				if (i > (l->items - 1))
					break;

				current = l->top_item + i;

				if (current == l->selected_item)
					Item->TextInfo[i]->highlight = TRUE;
				else
					Item->TextInfo[i]->highlight = FALSE;
			}
		}
	}
#endif
}



void DrawFlatMenuListText ( MENUITEM *Item )
{
	LIST *l;
	TEXTINFO *TextInfo;
	int i, current;

	l = (LIST *)(Item->Variable);

	l->old_top_item = l->top_item;
	l->old_selected_item = l->selected_item;

	for (i=0; i < l->display_items; i++)
	{

		TextInfo = Item->TextInfo[i];

		if (current == l->selected_item)
			TextInfo->highlight = TRUE;
		else
			TextInfo->highlight = FALSE;

		current = l->top_item + i;
		if (current >= l->items)
		{	TextInfo->text = EmptyString;
			PrintTextItem(TextInfo);
			continue;
		}
	
		if 	(TextInfo->text == l->item[current])
			continue;
		
		TextInfo->text = l->item[current];

		//format text item...
		PrintTextItem(TextInfo);

	}

}

void AddToFlatMenuList( MENUITEM *Item )
{
	LIST *l;
	TEXTINFO *TextInfo;
	int i, current;

	l = (LIST *)(Item->Variable);

 	for (i=0; i < Item->numtextitems; i++)
	{

		TextInfo = Item->TextInfo[i];

		current = l->top_item + i;

		if (current >= l->items)
		{	if (TextInfo->text != EmptyString)
			{	
				TextInfo->text = EmptyString;
				PrintTextItem(TextInfo);
			}
		}else
		{
			if (!TextInfo->text)
			{
				strncpy( l->old_item[current] , l->item[current] , sizeof(l->item[0])  );
				TextInfo->text = l->old_item[current];
				PrintTextItem(TextInfo);
			}else
			{
				if (strcmp( TextInfo->text, l->item[current] ) != 0)		// if text has changed
				{
					strncpy( l->old_item[current] , l->item[current] , sizeof(l->item[0])  );

					TextInfo->text = l->old_item[current];
					PrintTextItem(TextInfo);
				}
			}
		}

		if (current == l->selected_item)
			TextInfo->highlight = TRUE;
		else
			TextInfo->highlight = FALSE;

		if (!(CurrentMenuItem->highlightflags & TEXTFLAG_ManualListHighlight))
		{
			if (CurrentMenuItem == Item)
				TextInfo->highlighttype = HIGHLIGHT_Pulsing;
			else
				TextInfo->highlighttype = HIGHLIGHT_Static;
		}
	}
}

void AddToTextStack( TEXTINFO *TextInfo )
{
	int i;
	
	for ( i = 0; i < TextStackLevel; i++ )
	{
		if ( !TextStack[ i ] )
		{
			TextStack[ i ] = TextInfo;
			return;
		}
	}

	TextStack[ TextStackLevel++ ] = TextInfo;
}

void DrawFlatMenuList( MENUITEM *Item )
{
	LIST *l;
	TEXTINFO *TextInfo;
	int i;

	l = (LIST *)(Item->Variable);
	l->old_top_item = l->top_item;
	l->old_selected_item = l->selected_item;
	l->Static = FALSE;

	Item->numtextitems = 0;

	for (i=0; i < l->display_items; i++)
	{

		strncpy( l->old_item[i] , EmptyString , sizeof(l->item[0])  );
		
		Item->TextInfo[i] = InitTextInfo();

		Item->numtextitems++;
		
		//write relevent info into structure
		TextInfo = Item->TextInfo[i];

		TextInfo->xmin = Item->x;
		TextInfo->ymin = (((Item->ymax - Item->y)/l->display_items) * i) + Item->y;
		TextInfo->xmax = Item->xmax;
		TextInfo->ymax = (((Item->ymax - Item->y)/l->display_items) * (i + 1)) + Item->y;
		TextInfo->font = Item->font;
		TextInfo->flags = Item->highlightflags;
	
		AddToTextStack( TextInfo );

	}
	oldlistitems = l->items;

	AddToFlatMenuList( Item );
}

void DrawSplitMenuList( MENUITEM *Item )
{
	LIST *l;
	TEXTINFO *TextInfo;
	int i, column;
	int border, width, newxmax, newxmin, columnoffset;

	l = (LIST *)(Item->Variable);
	l->old_top_item = l->top_item;
	l->old_selected_item = l->selected_item;

	border = Item->x;
	width = Item->xmax - Item->x;
	newxmax = VDU_Width - border;
	newxmin = newxmax - width;
	columnoffset = newxmin - Item->x;

	for (column = 0; column < 2; column++)
	{
		for (i=0; i < l->display_items / 2; i++)
		{

			strncpy( l->old_item[i + column * (l->display_items / 2)] , EmptyString , sizeof(l->item[0])  );
		
			Item->TextInfo[i + column * (l->display_items / 2)] = InitTextInfo();

			Item->numtextitems++;
		
			//write relevent info into structure
			TextInfo = Item->TextInfo[i + column * (l->display_items / 2)];

			TextInfo->xmin = Item->x + column * columnoffset;
			TextInfo->ymin = (((Item->ymax - Item->y)/l->display_items) * i * 2) + Item->y;
			TextInfo->xmax = Item->xmax + column * columnoffset;
			TextInfo->ymax = (((Item->ymax - Item->y)/l->display_items) * (i * 2 + 1)) + Item->y;
			TextInfo->ymax += TextInfo->ymax - TextInfo->ymin;
			TextInfo->font = Item->font;
			TextInfo->flags = Item->highlightflags;
	
			//add to text stack...
			AddToTextStack( TextInfo );

		}
	}
	oldlistitems = l->items;

	AddToFlatMenuList( Item );
}


void DrawFlatTextStatus( MENUITEM *Item )
{
	TEXTINFO *TextInfo;
	TEXT *t;

	t = (TEXT *)(Item->Variable);
	TextInfo = Item->TextInfo[1];

	TextInfo->xmin = Item->xmax + 5;
	TextInfo->ymin = Item->y;
	TextInfo->xmax = 195;
	TextInfo->ymax = Item->ymax;
	TextInfo->font = Item->font;
	TextInfo->flags = Item->highlightflags;

	TextInfo->text = t->text;
	
	//format text item...
	PrintTextItem(TextInfo);
}

void DrawFlatMenuText( MENUITEM *Item )
{
	// draw text in textinfo 0
	DrawFlatMenuItem(Item);

	//allocate space for text status
	Item->TextInfo[1] = InitTextInfo();

	Item->numtextitems++;

	//add to text stack...
	AddToTextStack( Item->TextInfo[1] );
	DrawFlatTextStatus( Item );
}
/*
		{ 0,160, 10 , 170, 0, "", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY , &LoadSavedGameList, NULL, NULL, DrawLeftArrow, NULL, 0 } ,
		{ 190,160, 200 , 170, 0, "", FONT_Medium, TEXTFLAG_CentreX | TEXTFLAG_CentreY , &LoadSavedGameList, NULL, NULL, DrawRightArrow, NULL, 0 } ,
*/

void DrawLeftArrow( MENUITEM *Item )
{
	LIST *l;
	TEXTINFO *TextInfo;

	l = (LIST *)Item->Variable;

	if ( l->selected_item > 0 )
	{
		//allocate space for textinfo
		Item->TextInfo[0] = InitTextInfo();

		Item->numtextitems++;
			
		//write relevent info into structure
		TextInfo = Item->TextInfo[0];

		TextInfo->text = (char *)malloc( sizeof( char ) * 2 );
		TextInfo->text[ 0 ] = 17;
		TextInfo->text[ 1 ] = 0;

		TextInfo->xmin = Item->x;
		TextInfo->ymin = Item->y;
		TextInfo->xmax = Item->xmax;
		TextInfo->ymax = Item->ymax;
		TextInfo->font = Item->font;
		TextInfo->flags = Item->highlightflags;
		TextInfo->pointer[ TextInfo->num_pointers_to_free++ ] = TextInfo->text;

		//add to text stack...
		AddToTextStack( TextInfo );

		//format text item...
		PrintTextItem(TextInfo);
	}
}

void DrawRightArrow( MENUITEM *Item )
{
	LIST *l;
	TEXTINFO *TextInfo;

	l = (LIST *)Item->Variable;

	if ( l->selected_item < ( l->items - 1 ) )
	{
		//allocate space for textinfo
		Item->TextInfo[0] = InitTextInfo();

		Item->numtextitems++;
			
		//write relevent info into structure
		TextInfo = Item->TextInfo[0];

		TextInfo->text = (char *)malloc( sizeof( char ) * 2);
		TextInfo->text[ 0 ] = 16;
		TextInfo->text[ 1 ] = 0;

		TextInfo->xmin = Item->x;
		TextInfo->ymin = Item->y;
		TextInfo->xmax = Item->xmax;
		TextInfo->ymax = Item->ymax;
		TextInfo->font = Item->font;
		TextInfo->flags = Item->highlightflags;
		TextInfo->pointer[ TextInfo->num_pointers_to_free++ ] = TextInfo->text;

		//add to text stack...
		AddToTextStack( TextInfo );

		//format text item...
		PrintTextItem(TextInfo);
	}
}

void DrawFlatMenuItem( MENUITEM *Item )
{
	TEXTINFO *TextInfo;

	//allocate space for textinfo
	Item->TextInfo[0] = InitTextInfo();

	Item->numtextitems++;
		
	//write relevent info into structure
	TextInfo = Item->TextInfo[0];

	TextInfo->text = Item->StrPnt;
	TextInfo->xmin = Item->x;
	TextInfo->ymin = Item->y;
	TextInfo->xmax = Item->xmax;
	TextInfo->ymax = Item->ymax;
	TextInfo->font = Item->font;
	TextInfo->flags = Item->highlightflags;

	//add to text stack...
	AddToTextStack( TextInfo );

	//format text item...
	PrintTextItem(TextInfo);
	
}

void DrawSessionNameText( MENUITEM *Item )
{
	char *pchLevelSeperator;
	
	// session name could contain level name info if we have just aborted a new game - this must be discarded
	// so it is not displayed
	pchLevelSeperator = strchr( MultiPlayerGameName.text, '~' );
	if ( pchLevelSeperator )
		*pchLevelSeperator = 0;

	DrawFlatMenuText( Item );	
}

void DrawConditionalText( MENUITEM *Item )
{
	if ( *(BOOL *)(Item->Value ) )
	{
	 	DrawFlatMenuItem( Item );
	}
}

void DrawConditionalName( MENUITEM *Item )
{
	if ( *(BOOL *)(Item->Value ) )
	{
	 	DrawFlatMenuName( Item );
	}
}

void DrawReadyStatus(MENUITEM *Item)
{
	Item->TextInfo[0]->text = (PlayerReady[WhoIAm]) ? WaitingForReset : WaitingForConfirm;
	PrintTextItem(Item->TextInfo[0]);
}

void DrawReadyButton( MENUITEM *Item )
{
	DrawFlatMenuItem( Item );
	DrawReadyStatus(Item);
}

void PlayerConfirm( MENUITEM *Item )
{
	PlayerReady[WhoIAm] = !PlayerReady[WhoIAm];
	DrawReadyStatus(Item);

	if (PlayerReady[WhoIAm])
		NoTeamSelect = TRUE;
	else
		NoTeamSelect = FALSE;
}

TEXTINFO * DrawFlatRadioBtnStatus( MENUITEM *Item )
{

	TEXTINFO *TextInfo;

	TextInfo = Item->TextInfo[1];

	if (TextInfo)
	{
		TextInfo->xmin = Item->x - 10;
		TextInfo->ymin = Item->y;
		TextInfo->xmax = Item->x - 2;
		TextInfo->ymax = Item->ymax;
		TextInfo->font = Item->font;
		TextInfo->flags = Item->highlightflags;

		if ( *((int *)(Item->Variable)) == (int) Item->Value )
		{
			TextInfo->text = RadioBtnSelected;
		}else
		{
			TextInfo->text = RadioBtnNotSelected;
		}
	
		//format text item...
		PrintTextItem(TextInfo);
	}
		
	return TextInfo;
}


TEXTINFO * DrawFlatToggleStatus( MENUITEM *Item )
{
	TEXTINFO *TextInfo;
	char *status;

	if ( *(BOOL *)(Item->Variable ) )
	{
		status = ToggleStatusOn;
	}
	else
	{
		status = ToggleStatusOff;
	}
		
	//write relevent info into structure
	TextInfo = Item->TextInfo[1];

	TextInfo->text = status;
	TextInfo->xmin = Item->xmax + 5;
	TextInfo->ymin = Item->y;
	TextInfo->xmax = Item->xmax + 45;
	TextInfo->ymax = Item->ymax;
	TextInfo->font = Item->font;
	TextInfo->flags = Item->highlightflags;

	//format text item...
	PrintTextItem(TextInfo);

	return TextInfo;
}

void SelectFlatRadioButton( MENUITEM *Item )
{
	MENUITEM *TempItem;
	
	SelectRadioButton(Item);

	for( TempItem = CurrentMenu->Item ; TempItem->x >= 0 ; TempItem++ )
	{
		if (TempItem->Variable == Item->Variable)
		{
			DrawFlatRadioBtnStatus(TempItem);
		}
	}
}

void SelectFlatMenuToggle( MENUITEM *Item )
{
	if (VDU_Ready)
	{
		SelectToggle(Item);
		DrawFlatToggleStatus(Item);
	}
	
}

void SelectMultiToggle( MENUITEM *Item )
{
	if (VDU_Ready)
	{
		if ( Item->Variable )
		{
			*(BOOL *)(Item->Variable) = !*(BOOL *)(Item->Variable);
			if ( Item->Value )
			{
				*(BOOL *)(Item->Value) = !*(BOOL *)(Item->Value);
			}
		}

		DrawFlatToggleStatus(Item);
	}
}

void DrawFlatMenuToggle( MENUITEM *Item )
{
	// draw text in textinfo 0
	DrawFlatMenuItem(Item);

	//allocate space for toggle status
	Item->TextInfo[1] = InitTextInfo();

	Item->numtextitems++;

	//add to text stack...
	AddToTextStack( DrawFlatToggleStatus(Item) );

}

void SelectFlatMenuKey( MENUITEM *Item )
{
	MenuState = MENUSTATE_Keydef2;
	Item->TextInfo[0]->highlighttype = HIGHLIGHT_Static;
	KeyItem = Item;
}

void RedrawFlatMenuKey( MENUITEM *Item)
{
	if (VDU_Ready)
	{
		DrawFlatMenuKeyText( Item );
	}
}

void CheckKeysForChanges( void )
{
	MENUITEM *Item;
	VirtualKeycode keycode;
	char *keyword;
	DEFKEY *kdef;
	
	for( Item = CurrentMenu->Item ; Item->x >= 0 ; Item++ )
	{
		if( Item->FuncDraw == DrawFlatMenuKey )
		{	
#ifdef VDUKDEF
			kdef = (DEFKEY *)(Item->Variable);
			keycode = kdef->def->key[ kdef->selected_key ];
#else
			keycode = *(VirtualKeycode *)(Item->Variable);
#endif
			if ( keycode )
			{
				keyword = (char *) key_name( keycode );
				if ( !keyword )
					keyword = EmptyString;
			}
			else
				keyword = UndefinedKey;
			
			Item->TextInfo[0]->text = keyword; 
		}
		else if ( Item->FuncDraw == DrawFlatMenuKeyLeftArrow )
		{
			char *arrow;

			arrow = EmptyString;
			if ( Item->Variable )
			{
				kdef = (DEFKEY *)(Item->Variable);
				if ( kdef->def->keys > 1 && kdef->selected_key > 0 )
				{
					arrow = "\021"; // = 17
				}
			}
			Item->TextInfo[ 0 ]->text = arrow;
		}
		else if ( Item->FuncDraw == DrawFlatMenuKeyRightArrow )
		{
			char *arrow;

			arrow = EmptyString;
			if ( Item->Variable )
			{
				kdef = (DEFKEY *)(Item->Variable);
				if ( kdef->def->keys > 1 && kdef->selected_key < kdef->def->keys - 1 )
				{
					arrow = "\020"; // = 16
				}
			}
			Item->TextInfo[ 0 ]->text = arrow;
		}
		else if ( Item->FuncDraw == DrawFlatMenuKeyNum )
		{
			Item->TextInfo[ 0 ]->text[ 0 ] = 0;
			if ( Item->Variable )
			{
				kdef = (DEFKEY *)(Item->Variable);
				if ( kdef->def->keys > 1 )
				{
					sprintf( Item->TextInfo[ 0 ]->text, "%d/%d", kdef->selected_key + 1, kdef->def->keys );
				}
			}
		}
	}
}

void DrawFlatMenuKeyText( MENUITEM *Item )
{
	DEFKEY *kdef;
	VirtualKeycode keycode;
	char *keyword;
  	TEXTINFO *TextInfo;

	if ( Item->Variable )
	{
#ifdef VDUKDEF
		kdef = (DEFKEY *)(Item->Variable);
		keycode = kdef->def->key[ kdef->selected_key ];
#else
		keycode = *(VirtualKeycode *)(Item->Variable);
#endif
		if ( keycode )
		{
			keyword = (char *) key_name( keycode );
			if ( !keyword )
				keyword = EmptyString;
		}
		else
			keyword = UndefinedKey;
	}

	//write relevent info into structure
	TextInfo = Item->TextInfo[0];

	TextInfo->text = keyword;
	TextInfo->xmin = Item->x;
	TextInfo->ymin = Item->y;
	TextInfo->xmax = Item->xmax;
	TextInfo->ymax = Item->ymax;
	TextInfo->font = Item->font;
	TextInfo->flags = Item->highlightflags;

	//format text item...
	PrintTextItem(TextInfo);

}

void DrawFlatMenuKey( MENUITEM *Item )
{

	//allocate space for textinfo
	Item->TextInfo[0] = InitTextInfo();

	Item->numtextitems++;
		
	//add to text stack...
	AddToTextStack( Item->TextInfo[0] );

	DrawFlatMenuKeyText(Item);
}

void DrawFlatMenuKeyNum( MENUITEM *Item )
{
	DEFKEY *kdef;
  	TEXTINFO *TextInfo;

	if ( Item->Variable )
	{
		kdef = (DEFKEY *)(Item->Variable);

		//allocate space for textinfo
		Item->TextInfo[0] = InitTextInfo();

		Item->numtextitems++;
			
		//write relevent info into structure
		TextInfo = Item->TextInfo[0];

		TextInfo->text = (char *)malloc( 16 );
		if ( kdef->def->keys > 1 )
		{
			sprintf( TextInfo->text, "%d/%d", kdef->selected_key + 1, kdef->def->keys );
		}
		else
			TextInfo->text[ 0 ] = 0;

		TextInfo->xmin = Item->x;
		TextInfo->ymin = Item->y;
		TextInfo->xmax = Item->xmax;
		TextInfo->ymax = Item->ymax;
		TextInfo->font = Item->font;
		TextInfo->flags = Item->highlightflags;
		TextInfo->pointer[ TextInfo->num_pointers_to_free++ ] = TextInfo->text;

		//add to text stack...
		AddToTextStack( TextInfo );

		//format text item...
		PrintTextItem(TextInfo);
	}
}

void DrawFlatMenuKeyLeftArrowText( MENUITEM *Item )
{
	DEFKEY *kdef;
	char *arrow;
  	TEXTINFO *TextInfo;

	arrow = EmptyString;
	if ( Item->Variable )
	{
		kdef = (DEFKEY *)(Item->Variable);
		if ( kdef->def->keys > 1 && kdef->selected_key > 0 )
		{
			arrow = "\021"; // = 17
		}
	}

	//write relevent info into structure
	TextInfo = Item->TextInfo[0];

	TextInfo->text = arrow;
	TextInfo->xmin = Item->x;
	TextInfo->ymin = Item->y;
	TextInfo->xmax = Item->xmax;
	TextInfo->ymax = Item->ymax;
	TextInfo->font = Item->font;
	TextInfo->flags = Item->highlightflags;

	//format text item...
	PrintTextItem(TextInfo);

}

void DrawFlatMenuKeyLeftArrow( MENUITEM *Item )
{

	//allocate space for textinfo
	Item->TextInfo[0] = InitTextInfo();

	Item->numtextitems++;
		
	//add to text stack...
	AddToTextStack( Item->TextInfo[0] );

	DrawFlatMenuKeyLeftArrowText(Item);
}


void DrawFlatMenuKeyRightArrowText( MENUITEM *Item )
{
	DEFKEY *kdef;
	char *arrow;
  	TEXTINFO *TextInfo;

	arrow = EmptyString;
	if ( Item->Variable )
	{
		kdef = (DEFKEY *)(Item->Variable);
		if ( kdef->def->keys > 1 && kdef->selected_key < kdef->def->keys - 1 )
		{
			arrow = "\020"; // = 16
		}
	}

	//write relevent info into structure
	TextInfo = Item->TextInfo[0];

	TextInfo->text = arrow;
	TextInfo->xmin = Item->x;
	TextInfo->ymin = Item->y;
	TextInfo->xmax = Item->xmax;
	TextInfo->ymax = Item->ymax;
	TextInfo->font = Item->font;
	TextInfo->flags = Item->highlightflags;

	//format text item...
	PrintTextItem(TextInfo);

}

void DrawFlatMenuKeyRightArrow( MENUITEM *Item )
{

	//allocate space for textinfo
	Item->TextInfo[0] = InitTextInfo();

	Item->numtextitems++;
		
	//add to text stack...
	AddToTextStack( Item->TextInfo[0] );

	DrawFlatMenuKeyRightArrowText(Item);
}


void DrawFlatRadioButton( MENUITEM *Item )
{

	// draw text in textinfo 0
	DrawFlatMenuItem(Item);

	//allocate space for toggle status
	Item->TextInfo[1] = InitTextInfo();

	Item->numtextitems++;

	//add to text stack...
	AddToTextStack( DrawFlatRadioBtnStatus(Item) );
}


void DrawFlatSliderStatus( MENUITEM *Item )
{
	TEXTINFO *TextInfo;
	SLIDER *slider;
	int num;
	int slidertype;
	int offset;
	float percentage;
	char *uservalue;

	slider = GetSlider ( Item, &slidertype );

	if (slider->value == slider->oldvalue)
		return;
	else
		slider->oldvalue = slider->value;

	TextInfo = Item->TextInfo[1];

	switch (slidertype)
	{
	case SLIDER_Time:
		switch (slider->value)
		{
		case 0:
			num = sprintf( TextInfo->text, LT_NoLimit/*"no limit"*/ );
			break;
		case 1:
			num = sprintf( TextInfo->text, LT_OneMinute/*"1 min"*/ );
			break;
		default:
			num = sprintf( TextInfo->text, LT_ManyMinutes/*"%d mins"*/, slider->value );
			break;
		}
		offset = 5;
		break;
	case SLIDER_Value:
		num = sprintf( TextInfo->text, "%d", slider->value );
		offset = 5;
		break;
	case SLIDER_Percent:
		num = sprintf( TextInfo->text, "%d %%", slider->value );
		offset = 58;
		break;
	case SLIDER_Sensitivity:
		num = sprintf( TextInfo->text, "%d", slider->value );
		offset = 58;
		break;
	case SLIDER_Bike:
		num = 0;
		TextInfo->text = EmptyString;
		offset = 0;
		break;
	case SLIDER_Demo:
		if( DemoSpeed.value > 8 )
		{
			// slower or normal playback speed...
			percentage = (1.0F / (float) ( DemoSpeed.value - 7 )) * 100.0F;
		}else{
			percentage = (1.0F * (float) ( 9 - DemoSpeed.value )) * 100.0F;
		}
		num = sprintf( TextInfo->text, "%3.1f%%", percentage );  
		offset = 58;
		break;
	case SLIDER_User:
		if ( slider->FuncUser )
		{
			uservalue = slider->FuncUser( slider );
			if ( uservalue )
			{
				strncpy( TextInfo->text, uservalue, MAXSLIDERINFOLENGTH - 1 );
				TextInfo->text[ MAXSLIDERINFOLENGTH - 1 ] = 0;
				num = strlen( TextInfo->text );
			}
			else
			{
				num = sprintf( TextInfo->text, LT_NoValue/*"no value" */);
			}
		}
		else
		{
			num = sprintf( TextInfo->text, "no func" );
		}
		offset = 5;
		break;
	default:
		num = sprintf( TextInfo->text, "%.0f%%", ((float)slider->value / (float)slider->max) * 100.0F );
		offset = 58;
		break;
	}
	if ( num >= MAXSLIDERINFOLENGTH)
	{
		Msg("Title.c: DrawFlatSliderStatus() sprintf trying to write too many chars\n");
		exit(1);
	}
	TextInfo->xmin = Item->xmax + offset;
	TextInfo->ymin = Item->y;
	TextInfo->xmax = Item->xmax + 100;
	TextInfo->ymax = Item->ymax;
	TextInfo->font = Item->font;
	TextInfo->flags = Item->highlightflags;

	//format text item...
	PrintTextItem(TextInfo);
}

void UpdateSlider (MENUITEM *Item)
{
	float xmin, xmax, ymin, ymax;
	SLIDER *Slider;
	int slidertype, space, decreaseY;
	float width, height;
	float frac;

	Slider = GetSlider ( Item, &slidertype );

	frac = Slider->timer * ((float)( Slider->max - Slider->min ) / (float)Slider->max);
	frac += 1.0F - ((float)( Slider->max - Slider->min ) / (float)Slider->max);
	
	if (slidertype == SLIDER_Bike)
	{
		space = 1;
		width = 40.0F;
		decreaseY = 1;
	}else
	{
		space = 3;
		width = 50.0F;
		decreaseY = 2;
	}

	xmin = (Item->xmax + space + VDUoffsetX) * ModeScaleX[ModeCase];
	xmax = (Item->xmax + space + frac * width + VDUoffsetX) * ModeScaleX[ModeCase];
  
	ymin = (Item->y + VDUoffsetY + decreaseY) * ModeScaleY[ModeCase];
	ymax = (Item->ymax + VDUoffsetY - decreaseY) * ModeScaleY[ModeCase];

	height = (float)floor(ymax - ymin);

	xmin = (float)ceil(xmin);
	xmax = (float)ceil(xmax);
	ymin = (float)floor(ymin);
	ymax = ymin + height;
	
	ScrPolys[Slider->poly].x1 = xmin;
	ScrPolys[Slider->poly].y1 = ymin;	
	ScrPolys[Slider->poly].x2 = xmin;
	ScrPolys[Slider->poly].y2 = ymax;
	ScrPolys[Slider->poly].x3 = xmax;	
	ScrPolys[Slider->poly].y3 = ymax;
	ScrPolys[Slider->poly].x4 = xmax;					
	ScrPolys[Slider->poly].y4 = ymin;					

	ScrPolys[Slider->poly].Col1.R = 0;
	ScrPolys[Slider->poly].Col1.G = 32;
	ScrPolys[Slider->poly].Col1.B = 0;
	ScrPolys[Slider->poly].Col1.Trans = 255;
	ScrPolys[Slider->poly].Col2.R = (uint8)(64.0F * frac);
	ScrPolys[Slider->poly].Col2.G = (uint8)(223.0F * frac + 32.0F);
	ScrPolys[Slider->poly].Col2.B = (uint8)(64.0F * frac);
	ScrPolys[Slider->poly].Col2.Trans = 255;
	ScrPolys[Slider->poly].Col3.R = (uint8)(64.0F * frac);
	ScrPolys[Slider->poly].Col3.G = (uint8)(223.0F * frac + 32.0F);
	ScrPolys[Slider->poly].Col3.B = (uint8)(64.0F * frac);
	ScrPolys[Slider->poly].Col3.Trans = 255;
	ScrPolys[Slider->poly].Col4.R = 0;
	ScrPolys[Slider->poly].Col4.G = 32;
	ScrPolys[Slider->poly].Col4.B = 0;
	ScrPolys[Slider->poly].Col4.Trans = 255;

}

SLIDER *GetSlider( MENUITEM *Item, int *slidertype )
{
	int feature;
	SLIDER *slider;

	if (Item->FrameNo)
		*slidertype = Item->FrameNo;
	else
		*slidertype = SLIDER_Normal;

	if (*slidertype == SLIDER_Bike)
	{	
		feature = *((int *) (Item->Variable));
		slider = &BikeFeatureSlider[OldSelectedBike][feature];
	}else
		slider = (SLIDER *) (Item->Variable);

	return slider;
}

void DrawFlatMenuSlider( MENUITEM *Item )
{
	SLIDER *slider;
	BOOL SliderStored;
	int i;
	int slidertype;

	slider = GetSlider ( Item, &slidertype );

	slider->timer = 0.0F;
	slider->dt = framelag/( SLIDERSPEED * 60.0F);
	slider->redraw_req = TRUE;
	slider->poly = (uint16) -1;
	slider->oldvalue = -1;

	SliderStored = FALSE;

	for (i=0; i<MAXSLIDERSPERMENU; i++)
	{
		if (!ActiveSliderItem[i].Item)
		{
			ActiveSliderItem[i].Item = Item;
			SliderStored = TRUE;
			break;
		}
	}
	if (!SliderStored)
	{
		Msg("Title.c: DrawFlatMenuSlider() unable to store slider (increase MAXSLIDERSPERMENU??)\n");
		exit(1);
	}

	if (slidertype == SLIDER_Normal || slidertype == SLIDER_Bike || slidertype == SLIDER_Demo || slidertype == SLIDER_Percent || slidertype == SLIDER_Sensitivity )
	{
		slider->poly = FindFreeScrPoly();

		if (slider->poly == (uint16)-1)
		{
			Msg("Title.c: DrawFlatMenuSlider() unable to allocate screen poly\n");
			exit(1);
		}
	
		ScrPolys[slider->poly].Type = SCRTYPE_Normal;
		ScrPolys[slider->poly].Flags = SCRFLAG_UseCoords;
		ScrPolys[slider->poly].Type = SCRTYPE_Normal;

		ScrPolys[slider->poly].Col1.R = 0;
		ScrPolys[slider->poly].Col1.G = 32;
		ScrPolys[slider->poly].Col1.B = 0;
		ScrPolys[slider->poly].Col1.Trans = 0;
		ScrPolys[slider->poly].Col2.R = 64;
		ScrPolys[slider->poly].Col2.G = 255;
		ScrPolys[slider->poly].Col2.B = 64;
		ScrPolys[slider->poly].Col2.Trans = 0;
		ScrPolys[slider->poly].Col3.R = 64;
		ScrPolys[slider->poly].Col3.G = 255;
		ScrPolys[slider->poly].Col3.B = 64;
		ScrPolys[slider->poly].Col3.Trans = 0;
		ScrPolys[slider->poly].Col4.R = 0;
		ScrPolys[slider->poly].Col4.G = 32;
		ScrPolys[slider->poly].Col4.B = 0;
		ScrPolys[slider->poly].Col4.Trans = 0;

		ScrPolys[slider->poly].Frame = 238.0F;
		ScrPolys[slider->poly].Frm_Info = NULL;
		AddScrPolyToTPage( slider->poly, GetTPage( NULL, 0 ) );

		UpdateSlider ( Item );
	}
	// draw text in textinfo 0
	DrawFlatMenuItem(Item);

	//allocate space for slider status
	Item->TextInfo[1] = InitTextInfo();

	//allocate space for slider info string
	Item->TextInfo[1]->text = (char*)malloc ( sizeof (char) * MAXSLIDERINFOLENGTH );

	if (!Item->TextInfo[1]->text)
	{	Msg("Title.c   DrawFlatMenuSlider:  unable to allocate memory\n");
		exit(1);
	}

	Item->TextInfo[1]->pointer[Item->TextInfo[1]->num_pointers_to_free++] = Item->TextInfo[1]->text;
	
	Item->numtextitems++;

	DrawFlatSliderStatus(Item);

	//add to text stack...
	AddToTextStack( Item->TextInfo[1] );

}

void ProcessFlatSliders(void)
{
	int i, slidertype;
	SLIDER *slider;
	float ReqFraction;
	
	for (i=0; i<MAXSLIDERSPERMENU; i++)
	{
		if (ActiveSliderItem[i].Item)
		{
			slider = GetSlider ( ActiveSliderItem[i].Item, &slidertype );
		 
			if (slider->redraw_req)
			{
				//DebugPrintf("slider redrawn\n");
				RedrawFlatMenuSlider(ActiveSliderItem[i].Item);
			}

			ReqFraction = (float)(slider->value - slider->min) / (float)(slider->max - slider->min);
			if (slider->timer < 0.0F)
				continue;
			slider->timer += slider->dt;
			if (( (slider->timer >= ReqFraction ) && ( slider->dt > 0.0F ) ) ||
				( (slider->timer <= ReqFraction ) && ( slider->dt < 0.0F ) ))
			{
			   	slider->timer = ReqFraction;
				if (slider->poly != (uint16) -1)
				   	UpdateSlider(ActiveSliderItem[i].Item);
				slider->timer = -1.0F;
			}else
			{
				if (slider->poly != (uint16) -1)
					UpdateSlider(ActiveSliderItem[i].Item);
			}

		}
	}
}
 
void RedrawFlatMenuSlider( MENUITEM *Item )
{
	SLIDER *slider;
	int slidertype;

	slider = GetSlider ( Item, &slidertype );

	slider->redraw_req = FALSE;

	DrawFlatSliderStatus(Item);

	if (slidertype == SLIDER_Normal || slidertype == SLIDER_Demo || slidertype == SLIDER_Percent || slidertype == SLIDER_Sensitivity )
	{

		if (slider->timer < 0.0F)
			slider->timer = (slider->oldvalue - (float)slider->min) / (float)(slider->max - slider->min);

		if (slider->value != slider->oldvalue)
		{
			if (slider->value > slider->oldvalue)
				slider->dt = (float)fabs(slider->dt);
			else
				slider->dt = 0.0F - (float)fabs(slider->dt);
		}
	}
}

void DrawFlatMenuName( MENUITEM *Item )
{
	char *var;
	TEXTINFO *TextInfo;

	//var = (char *)(Item->Variable);
	var = Item->Variable;
	  
	//allocate space for textinfo
	Item->TextInfo[0] = InitTextInfo();
	Item->numtextitems++;
		
	//write relevent info into structure
	TextInfo = Item->TextInfo[0];

	TextInfo->text = var;
	TextInfo->xmin = Item->x;
	TextInfo->ymin = Item->y;
	TextInfo->xmax = Item->xmax;
	TextInfo->ymax = Item->ymax;
	TextInfo->font = Item->font;
	TextInfo->flags = Item->highlightflags;

	if (Item->highlightflags & TEXTFLAG_CheckForRefresh)
	{
		//TextInfo->oldtext = (char*)malloc ( sizeof (char) * strlen(var) );
		//DebugPrintf("DrawFlatMenuName() allocated %d\n", strlen(var));
		//TextInfo->pointer[TextInfo->num_pointers_to_free++] = TextInfo->oldtext;
		strncpy(TextInfo->oldtext, TextInfo->text, MAX_TEXT_LENGTH);
	}

	//add to text stack...
	AddToTextStack( TextInfo );

	//format text item...
	PrintTextItem(TextInfo);
	
}

void DrawGeneralWeaponText( MENUITEM *Item )
{
	int i, offset, Total_Slots, line;
	TEXTINFO *TextInfo;

	Total_Slots = 12;

	for (i = 0; i < MaxWeapons; i++)
	{
		if (i < MaxWeapons - Num_Unused_Weapons)
		{
			offset = 0;
			line = i;
		}
		else
		{
			offset = Item->xmax + 5;
			line = i - (MaxWeapons - Num_Unused_Weapons);
		}

		TextInfo = Item->TextInfo[i];

		// if the same as existing item, no need to redraw...
		if ((TextInfo->xmin == Item->x + offset) &&
			(TextInfo->ymin == (((Item->ymax - Item->y)/Total_Slots) * line) + Item->y) &&
			(TextInfo->text == DescriptionList[WeaponList[i]]))
			continue;

		TextInfo->xmin = Item->x + offset;
		TextInfo->ymin = (((Item->ymax - Item->y)/Total_Slots) * line) + Item->y;

		TextInfo->text = DescriptionList[WeaponList[i]];
		
		TextInfo->xmax = Item->xmax + offset;
		TextInfo->ymax = (((Item->ymax - Item->y)/Total_Slots) * (line + 1)) + Item->y;
		TextInfo->font = Item->font;				  
		TextInfo->flags = Item->highlightflags;

		PrintTextItem(TextInfo);

	}


}

static uint16 GetNumUsed( int16 *priority, BOOL *valid, uint16 Max )
{
	uint16 i, unused;

	unused = 0;

	for ( i = 0; i < MaxWeapons; i++ )
	{
		if ( ( priority[ i ] < 0 ) && ( valid[ i ] ) )
		{
			 unused++;
		}
	}

	return unused;
}

void DrawPrimaryWeapons( MENUITEM *Item )
{
	MaxWeapons = MAX_PRIMARY_WEAPONS;
	PriorityList = Config.primary_priority;
	OrderList = Config.primary_order;
	DescriptionList = PrimaryDescription;
	WeaponValid = PrimaryValid;

	Num_Unused_Weapons = GetNumUsed( PriorityList, WeaponValid, MaxWeapons );
	DrawGeneralWeapons( Item );
}

void DrawSecondaryWeapons( MENUITEM *Item )
{
	MaxWeapons = MAX_SECONDARY_WEAPONS;
	PriorityList = Config.secondary_priority;
	OrderList = Config.secondary_order;
	DescriptionList = SecondaryDescription;
	WeaponValid = SecondaryValid;

	Num_Unused_Weapons = GetNumUsed( PriorityList, WeaponValid, MaxWeapons );
	DrawGeneralWeapons( Item );
}

void StoreWeaponOrder( MENU *Menu )
{
	int i;

	for (i = 0; i < MaxWeapons - Num_Unused_Weapons; i++)
	{
		OrderList[i] = WeaponList[i];
		PriorityList[WeaponList[i]] = i;
	}

	for ( ; i < MaxWeapons; i++ )
	{
		OrderList[i] = -1;
		PriorityList[WeaponList[i]] = -1;
	}
	
//	if ( memcmp( &Config, player_config, sizeof( Config ) ) )
	{
		*player_config = Config;
		write_config( player_config, biker_config );
	}
}

void DrawGeneralWeapons( MENUITEM *Item )
{
	int i, num_weapons;

	BOOL used[ MAX( MAX_PRIMARY_WEAPONS, MAX_SECONDARY_WEAPONS ) ];

	memset( used, FALSE, MAX( MAX_PRIMARY_WEAPONS, MAX_SECONDARY_WEAPONS ) * sizeof ( BOOL ) ); 

	SelectedWeapon = 0;
	WeaponItem = Item;
	WeaponOrderStatus = WEAPON_ChoosingFirst;
#if 0
	IdiotText = InitTextInfo();
	Item->numtextitems++;
	AddToTextStack( IdiotText );
	IdiotText->xmin = MENU_ITEM_IdiotText.x;
	IdiotText->ymin = MENU_ITEM_IdiotText.y;
	IdiotText->xmax = MENU_ITEM_IdiotText.xmax;
	IdiotText->ymax = MENU_ITEM_IdiotText.ymax;
	IdiotText->font = MENU_ITEM_IdiotText.font;
	IdiotText->text = WeaponSelectFirst;

	PrintTextItem(IdiotText);
#endif
	for (i = 0; i < MaxWeapons; i++)
	{
		Item->TextInfo[i] = InitTextInfo();
		Item->numtextitems++;
		AddToTextStack( Item->TextInfo[i] );
		Item->TextInfo[i]->highlight = FALSE;
		Item->TextInfo[i]->highlighttype = HIGHLIGHT_Pulsing;
	}

//	Num_Unused_Weapons, MaxWeapons, WeaponList[];
	//	if ( !PrimaryValid[ WeaponList[ weapon ] ] )

	num_weapons = 0;
	for ( i = 0; i < MaxWeapons; i++ )
	{
		if ( ( OrderList[ i ] != -1 ) && ( !used[ OrderList[ i ] ] ) )
		{
			if ( WeaponValid[ OrderList[ i ] ] )
			{
				WeaponList[ num_weapons++ ] = OrderList[ i ];
				used[ OrderList[ i ] ] = TRUE;
			}
		}
	}

	for ( i = num_weapons; i < MaxWeapons; i++ )
	{
		for ( i = 0; i < MaxWeapons; i++ )
		{
			if ( !used[ i ] && WeaponValid[ i ] )
				WeaponList[ num_weapons++ ] = i;
		}
	}

	MaxWeapons = num_weapons;

	DrawGeneralWeaponText( Item );
	Item->TextInfo[0]->highlight = TRUE;
	Item->TextInfo[0]->highlighttype = HIGHLIGHT_Pulsing;

	MenuState = MENUSTATE_WeaponOrder;
}

/*�������������������������������������������������������������������
	Procedure	:		Processes menu items for VDU menus
	Input		:		ptr to menu
	Output		:		nothing
�������������������������������������������������������������������*/
void ProcessVduItems( MENU *Menu )
{
	MENUITEM *Item;
	
	for( Item = Menu->Item ; Item->x >= 0 ; Item++ )
	{	if( Item->FuncDraw )
		{  
			Item->FuncDraw( Item );
		}
	}
}

void KillTextInfo ( TEXTINFO *TextInfo )
{
	int i;
	
	if ( TextInfo )
	{
		while(TextInfo->num_pointers_to_free)
		{	free(TextInfo->pointer[TextInfo->num_pointers_to_free - 1]);
			TextInfo->num_pointers_to_free--;
		}
		free (TextInfo);
		// remove ptr from stack...
		for ( i = 0; i < TextStackLevel; i++ )
		{
			if ( TextStack[ i ] == TextInfo )
			{
				TextStack[ i ] = NULL;
				break;
			}
		}
		TextInfo = NULL;
	}
}

/*�������������������������������������������������������������������
	Procedure	:		clears everything from the VDU
	Input		:		nothing
	Output		:		nothing
�������������������������������������������������������������������*/
void VduClear ( void )
{
	int i, tempstacklevel, slidertype;
	MENUITEM *Item;
	SLIDER *slider;

	NewTextCharDisplayed = FALSE;

	tempstacklevel = 0;

	for (i=0; i<TextStackLevel; i++)
	{
		if ( TextStack[ i ] )
		{
			TextStack[i]->boxdone = FALSE;
			KillTextInfo( TextStack[i] );
		}
	}

	TextStackLevel = 0;
	CurrentTeletype = 0;


	for( Item = LastMenu->Item ; Item->x >= 0 ; Item++ )
	{	
		Item->numtextitems = 0;
	}


		
	// kill all polys used for boxes...
	for (i=0; i<CurrentScreenPoly; i++)
	{	KillUsedScrPoly( screenpoly[i] );
		screenpoly[i] = (uint16)-1;
	}

	CurrentScreenPoly = 0;

	for (i=0; i<MAXSLIDERSPERMENU; i++)
	{	
		if (ActiveSliderItem[i].Item)
		{
			slider = GetSlider ( ActiveSliderItem[i].Item, &slidertype );
			if (slider->poly != (uint16) -1)
			{	KillUsedScrPoly( slider->poly );
				slider->poly = (uint16)-1;
			}
			ActiveSliderItem[i].Item = NULL;
		}
	}

	PlaySfx( SFX_VduClear, 0.4F );

}

/*********************************************************************************************************
start of VDU text routines
*********************************************************************************************************/

BOOL Plot2dBox (TEXTINFO *TextInfo)
{
	uint8 r, g, b;

	screenpoly[CurrentScreenPoly] = FindFreeScrPoly();					
	testboxpoly = screenpoly[CurrentScreenPoly];
	if( screenpoly[CurrentScreenPoly] != (uint16 ) -1 )
	{

		ScrPolys[screenpoly[CurrentScreenPoly]].Type = SCRTYPE_Normal;
		ScrPolys[screenpoly[CurrentScreenPoly]].Flags = SCRFLAG_UseCoords;
		ScrPolys[screenpoly[CurrentScreenPoly]].R = 255;					
		ScrPolys[screenpoly[CurrentScreenPoly]].G = 255;					
		ScrPolys[screenpoly[CurrentScreenPoly]].B = 255;				  
		ScrPolys[screenpoly[CurrentScreenPoly]].Trans = 255;				
		ScrPolys[screenpoly[CurrentScreenPoly]].Xscale = 1.0F;				
		ScrPolys[screenpoly[CurrentScreenPoly]].Yscale = 1.0F;			  
		ScrPolys[screenpoly[CurrentScreenPoly]].Frame = 11.0F;			 
		ScrPolys[screenpoly[CurrentScreenPoly]].Frm_Info = NULL;
		ScrPolys[screenpoly[CurrentScreenPoly]].x1 = ((float)TextInfo->xmin + VDUoffsetX) * ModeScaleX[ModeCase];
		ScrPolys[screenpoly[CurrentScreenPoly]].y1 = ((float)TextInfo->ymin + VDUoffsetY) * ModeScaleY[ModeCase];
		ScrPolys[screenpoly[CurrentScreenPoly]].x2 = ((float)TextInfo->xmax + VDUoffsetX) * ModeScaleX[ModeCase];
		ScrPolys[screenpoly[CurrentScreenPoly]].y2 = ((float)TextInfo->ymin + VDUoffsetY) * ModeScaleY[ModeCase];
		ScrPolys[screenpoly[CurrentScreenPoly]].x3 = ((float)TextInfo->xmax + VDUoffsetX) * ModeScaleX[ModeCase];
		ScrPolys[screenpoly[CurrentScreenPoly]].y3 = ((float)TextInfo->ymax + VDUoffsetY) * ModeScaleY[ModeCase];
		ScrPolys[screenpoly[CurrentScreenPoly]].x4 = ((float)TextInfo->xmin + VDUoffsetX) * ModeScaleX[ModeCase];
		ScrPolys[screenpoly[CurrentScreenPoly]].y4 = ((float)TextInfo->ymax + VDUoffsetY) * ModeScaleY[ModeCase];
		AddScrPolyToTPage(screenpoly[CurrentScreenPoly], GetTPage( NULL, 0 ) );
    	//AddScrPolyToTPage( screenpoly[CurrentScreenPoly], GetTPage( *ScrPolys[ screenpoly[CurrentScreenPoly] ].Frm_Info, 0 ) );
		
		r = 255; g = 255; b = 255;
		
		ScrPolys[screenpoly[CurrentScreenPoly]].Col1.R = r;
		ScrPolys[screenpoly[CurrentScreenPoly]].Col1.G = g;
		ScrPolys[screenpoly[CurrentScreenPoly]].Col1.B = b;
		ScrPolys[screenpoly[CurrentScreenPoly]].Col1.Trans = 255;
		ScrPolys[screenpoly[CurrentScreenPoly]].Col2.R = r;
		ScrPolys[screenpoly[CurrentScreenPoly]].Col2.G = g;
		ScrPolys[screenpoly[CurrentScreenPoly]].Col2.B = b;
		ScrPolys[screenpoly[CurrentScreenPoly]].Col2.Trans = 255;
		ScrPolys[screenpoly[CurrentScreenPoly]].Col3.R = r;
		ScrPolys[screenpoly[CurrentScreenPoly]].Col3.G = g;
		ScrPolys[screenpoly[CurrentScreenPoly]].Col3.B = b;
		ScrPolys[screenpoly[CurrentScreenPoly]].Col3.Trans = 255;
		ScrPolys[screenpoly[CurrentScreenPoly]].Col4.R = r;
		ScrPolys[screenpoly[CurrentScreenPoly]].Col4.G = g;
		ScrPolys[screenpoly[CurrentScreenPoly]].Col4.B = b;
		ScrPolys[screenpoly[CurrentScreenPoly]].Col4.Trans = 255;

		CurrentScreenPoly++;
	}
	else
		return FALSE;

	return TRUE;

}

int GetScreenFont(int fontsize)
{
	switch (ModeCase)
	{
	case Mode320X200:
		TEXTINFO_TextSpace = 1.0F;
		TEXTINFO_LineSpace = 2.0F * ModeScaleY[ModeCase];
		return FONT_320X200_Small + fontsize;
	case Mode320X240:
		TEXTINFO_TextSpace = 1.0F;
		TEXTINFO_LineSpace = 2.0F * ModeScaleY[ModeCase];
		return FONT_320X240_Small + fontsize;
	case Mode512X384:
		TEXTINFO_TextSpace = 2.0F;
		TEXTINFO_LineSpace = 2.0F * ModeScaleY[ModeCase];
		return FONT_320X200_Small + fontsize;
	default:
		TEXTINFO_TextSpace = ModeScaleX[ModeCase];
		TEXTINFO_LineSpace = 2.0F * ModeScaleY[ModeCase];
		return FONT_320X200_Small+ fontsize;	//default font is for 320X200 display.
	}
}

BOOL FormatTextItem(int start, int end, TEXTINFO *TextInfo, BOOL *newline)
{
	int i,font;
	float TotalWidth, RemainingWidth, WordWidth, TrailingSpaceWidth, TotalHeight, PreviousHeight;
	BOOL TrailingSpace, ForceNewLineNext;
	uint16 CurrentChar;
	float xmin, xmax, ymin, ymax;

	BIT_INFO	*	Bit_Ptr;
	BOX_INFO	*	Box_Ptr;
	OFF_INFO	*	Off_Ptr;
	
	*newline = FALSE;


	xmin = TextInfo->xmin * ModeScaleX[ModeCase];
	xmax = TextInfo->xmax * ModeScaleX[ModeCase];
	ymin = TextInfo->ymin * ModeScaleY[ModeCase];
	ymax = TextInfo->ymax * ModeScaleY[ModeCase];

	
	TotalWidth = (float)(xmax - xmin);
	TotalHeight = (float)(ymax - ymin);
	RemainingWidth = xmax - TEXTINFO_currentx - xmin;

	
	font = GetScreenFont(TextInfo->font);
	
	 //find total width of word...
	WordWidth = 0.0F;
	TrailingSpace = FALSE;
	ForceNewLineNext = FALSE;

	//store current height, as it will be needed if text wraps...
	PreviousHeight = TEXTINFO_currentheight;
	TEXTINFO_currentheight = 0.0F;

	for (i = start; i <= end; i++)
	{
		CurrentChar = TextLookup[font][TextInfo->text[i]];
					  
		if ((CurrentChar) || (TextInfo->text[i] == '~'))
		{
			Bit_Ptr = ( Title_Fonts_Header->Bit_Info + (int16)(CurrentChar) );
			Off_Ptr = ( Title_Fonts_Header->Off_Info + Bit_Ptr->startbit );
			Box_Ptr = ( Title_Fonts_Header->Box_Info + ( Off_Ptr->box & 0x0fff ) );

			WordWidth += Box_Ptr->xsize * VduScaleX;
		
		
			if ( i == end)
			{
				if (TextInfo->text[i] == ' ')
					TrailingSpace = TRUE;
				if (TextInfo->text[i] == '~')
					ForceNewLineNext = TRUE;
			
			}else
				WordWidth += TEXTINFO_TextSpace; //add a space between characters


			if (Box_Ptr->ysize * VduScaleY > TEXTINFO_currentheight)
				TEXTINFO_currentheight = Box_Ptr->ysize * VduScaleY;

		}
	}

	Bit_Ptr = ( Title_Fonts_Header->Bit_Info + (int16)(TextLookup[font][' ']) );
	Off_Ptr = ( Title_Fonts_Header->Off_Info + Bit_Ptr->startbit );
	Box_Ptr = ( Title_Fonts_Header->Box_Info + ( Off_Ptr->box & 0x0fff ) );

	TrailingSpaceWidth = Box_Ptr->xsize * VduScaleX;


	// if word is too long for bounding box...
	if (WordWidth > TotalWidth)
	{	
		if (TextInfo->flags & TEXTFLAG_ForceFit)
		{
			TextInfo->force_fit = TRUE;
			return FALSE;
		}

		if (TrailingSpace)
		{
			if (WordWidth - TrailingSpaceWidth > TotalWidth)
				return FALSE;
			else
			{	end--;	//word will fit without trailing space, so reduce end pointer
				WordWidth -= TrailingSpaceWidth;
			}
		}
		else
			return FALSE;
	}


	// if word will not fit on current line...
	if ((WordWidth > RemainingWidth) || ForceNewLine)
	{
		
		//try stripping trailing space if any...
		if (TrailingSpace && (RemainingWidth >= WordWidth - TrailingSpaceWidth) && !ForceNewLine)
		{	end--;
			WordWidth -= TrailingSpaceWidth;
		}
		else
		{
			if (TEXTINFO_currenty + PreviousHeight + TEXTINFO_currentheight + TEXTINFO_LineSpace > TotalHeight)
			{
		 		if (TextInfo->flags & TEXTFLAG_ForceFit)
				{
					TextInfo->force_fit = TRUE;
					return FALSE;
				}
		
				return FALSE;	//no room for new line
			}
			else
			{	
				//start new line...
				
				//remove trailing space if still there..
				if (TextInfo->text[TEXTINFO_currentendpoint] == ' ')
				{
					TEXTINFO_currentendpoint--;
					TEXTINFO_currentx -= TrailingSpaceWidth;
				}

				TextInfo->length[TextInfo->num_lines-1] = TEXTINFO_currentx;
				TextInfo->height[TextInfo->num_lines-1] = TEXTINFO_currentheight + TEXTINFO_LineSpace;
				TextInfo->endpoint[TextInfo->num_lines-1] = TEXTINFO_currentendpoint;
				TextInfo->startpoint[TextInfo->num_lines] = start;
				TextInfo->num_lines++;
				*newline = TRUE;
				
				TEXTINFO_currenty += PreviousHeight + TEXTINFO_LineSpace;
				TEXTINFO_currentx = 0.0F;
				//TEXTINFO_currentheight = 0.0F;

				ForceNewLine = FALSE;
			}
		}
	}

	if (!(*newline))	//if no new line was started, take previous height info into account
	{	if (PreviousHeight > TEXTINFO_currentheight)
			TEXTINFO_currentheight = PreviousHeight;
	}

	if (ForceNewLineNext)
	{	ForceNewLine = TRUE;
		end--;
	}

	TEXTINFO_currentendpoint = end;
	 
	TEXTINFO_currentx += WordWidth + TEXTINFO_TextSpace;

	for ( i = 0; i < TextInfo->num_lines; i++ )
		TextInfo->finished[ i ] = FALSE;

	return TRUE;
	
}


BOOL DrawTextEditCursor( TEXTINFO *TextInfo, int font )
{
	float xmin, ymin;
	char cursor = '!';
	int16 lookup;
	BIT_INFO	*	Bit_Ptr;
	BOX_INFO	*	Box_Ptr;
	OFF_INFO	*	Off_Ptr;
	uint16 TempPoly;
	uint8 i;
  	TEXT *t;

	t = (TEXT *)(TextItem->Variable);

	xmin = TextInfo->char1x;
	ymin = TextInfo->text_y_min;

	Bit_Ptr = ( Title_Fonts_Header->Bit_Info + (int16)(TextLookup[font][cursor]) );
	Off_Ptr = ( Title_Fonts_Header->Off_Info + Bit_Ptr->startbit );
	Box_Ptr = ( Title_Fonts_Header->Box_Info + ( Off_Ptr->box & 0x0fff ) );

	ymin += ( VduScaleY * Box_Ptr->ysize );

	for (i = t->VDU_insert_pos; i < t->insert_pos; i++)
	{
		lookup = TextLookup[font][TextInfo->text[TextInfo->startpoint[0] + i - t->VDU_insert_pos]];

		if (lookup != 0)
		{
			Bit_Ptr = ( Title_Fonts_Header->Bit_Info + lookup );
			Off_Ptr = ( Title_Fonts_Header->Off_Info + Bit_Ptr->startbit );
			Box_Ptr = ( Title_Fonts_Header->Box_Info + ( Off_Ptr->box & 0x0fff ) );

			xmin += VduScaleX * ( Box_Ptr->xsize + TEXTINFO_TextSpace );
		}
	}

	xmin -= (TEXTINFO_TextSpace / 2.0F);
	if (bPolyText && PolyText[MyGameStatus])
	{
		TempPoly = FindFreeScrPoly();					
		if( TempPoly != (uint16 ) -1 )
		{
					   	
		ScrPolys[TempPoly].Type = SCRTYPE_LastAFrame;
		ScrPolys[TempPoly].Flags = SCRFLAG_Nothing;

		ScrPolys[TempPoly].Pos.x = xmin;			  
		ScrPolys[TempPoly].Pos.y = ymin;
		ScrPolys[TempPoly].R = 255;					
		ScrPolys[TempPoly].G = 255;					
		ScrPolys[TempPoly].B = 255;				  
		ScrPolys[TempPoly].Trans = 255;				
		ScrPolys[TempPoly].Xscale = VduScaleX;				
		ScrPolys[TempPoly].Yscale = VduScaleY;			  
		ScrPolys[TempPoly].Frame = TextLookup[font][cursor];
		ScrPolys[TempPoly].Frm_Info = &Title_Fonts_Header;
					
		AddScrPolyToTPage( TempPoly, GetTPage( *ScrPolys[ TempPoly ].Frm_Info, 0 ) );

		}
			else
				return FALSE;
	}else
	{
		// TO DO!!!
		/****** fill in for blitted cursor ******/
	}
	return TRUE;
}
 
void GetTextPos(TEXTINFO *TextInfo, float *xpos, float *ypos, int line, float totalheight)
{

	float xmin, ymin, xmax, ymax, currentx, currenty;

	currentx = TextInfo->currentx[line];
	currenty = TextInfo->currenty;

	xmin = (TextInfo->xmin + VDUoffsetX) * ModeScaleX[ModeCase];
	xmax = (TextInfo->xmax + VDUoffsetX) * ModeScaleX[ModeCase];
	ymin = (TextInfo->ymin + VDUoffsetY) * ModeScaleY[ModeCase];
	ymax = (TextInfo->ymax + VDUoffsetY) * ModeScaleY[ModeCase];

	//default x, y pos...
	*xpos = (currentx + xmin);	
		  
	*ypos = (currenty + ymin + TextInfo->height[0] - TEXTINFO_LineSpace);

	if (TextInfo->flags)
	{
			 
		if (TextInfo->flags & TEXTFLAG_RightX)
			*xpos = (currentx + xmin) + xmax - xmin - TextInfo->length[line];

		if (TextInfo->flags & TEXTFLAG_CentreX)
			*xpos = (xmin + currentx + (int)((float)(xmax - xmin)/2.0F - TextInfo->length[line]/2.0F)) - TEXTINFO_TextSpace * 2.0F;			  

		if (TextInfo->flags & TEXTFLAG_CentreY)
			*ypos = ((ymax - ymin)/(TextInfo->num_lines + 1)) * (line + 1) + ymin + (TextInfo->height[0] - TEXTINFO_LineSpace) * ((line+1)/(float)(TextInfo->num_lines + 1));
		
		if (TextInfo->flags & TEXTFLAG_BottomY)
			*ypos = (ymax - totalheight + currenty);
		
		if (TextInfo->flags & TEXTFLAG_CentreYBunched)
			*ypos = ( TextInfo->height[0] - TEXTINFO_LineSpace + currenty + (ymax - ymin - totalheight) / 2.0F ) + ymin;

	}

}

BOOL DisplayTextCharacter(TEXTINFO *TextInfo, int line, int pos, int font, float totalheight)
{
   
	float xpos, ypos, currentx, currenty, xmin;
	BIT_INFO	*	Bit_Ptr;
	BOX_INFO	*	Box_Ptr;
	OFF_INFO	*	Off_Ptr;
    RECT    src, dest;
	HRESULT ddrval;
	BOOL	OKtoProcess;
	DDBLTFX fx;
	uint16 TempPoly;

	currentx = TextInfo->currentx[line];
	currenty = TextInfo->currenty;

	xmin = (TextInfo->xmin + VDUoffsetX) * ModeScaleX[ModeCase];

	OKtoProcess = FALSE;

	if ((pos != -1) && (pos != -2))
	{	if (TextLookup[font][TextInfo->text[pos]])
			OKtoProcess = TRUE;		
//		else
			//TextInfo->currentchar[line]++;
	}
	
	if ((OKtoProcess) || (pos == -1) || (pos == -2))
	{
	
		GetTextPos(TextInfo, &xpos, &ypos, line, totalheight);

		if (pos == TextInfo->startpoint[line])
		{
			if ( xpos < TextInfo->char1x )
				 TextInfo->char1x = xpos;

			if (line == 0)
				TextInfo->text_y_min = ypos - TextInfo->height[line] + TEXTINFO_LineSpace;
			if (line == TextInfo->num_lines - 1)
				TextInfo->text_y_max = ypos;
		}

		switch(pos)
		{
		case -1:
			Bit_Ptr = ( Title_Fonts_Header->Bit_Info + (int16)(TextLookup[font][71]) );	// right arrow character
			Off_Ptr = ( Title_Fonts_Header->Off_Info + Bit_Ptr->startbit );
			Box_Ptr = ( Title_Fonts_Header->Box_Info + ( Off_Ptr->box & 0x0fff ) );

			xpos = xmin - Box_Ptr->xsize * VduScaleX - TEXTINFO_TextSpace;

			break;
		case -2:
			break;
		default:
			Bit_Ptr = ( Title_Fonts_Header->Bit_Info + (int16)(TextLookup[font][TextInfo->text[pos]]) );
			Off_Ptr = ( Title_Fonts_Header->Off_Info + Bit_Ptr->startbit );
			Box_Ptr = ( Title_Fonts_Header->Box_Info + ( Off_Ptr->box & 0x0fff ) );

			TextInfo->currentx[line] += Box_Ptr->xsize * VduScaleX + TEXTINFO_TextSpace;
			break;
		}

		if (bPolyText && PolyText[MyGameStatus])
		{
			TempPoly = FindFreeScrPoly();					
			if( TempPoly != (uint16 ) -1 )
			{
						   	
				ScrPolys[TempPoly].Type = SCRTYPE_LastAFrame;
				ScrPolys[TempPoly].Flags = SCRFLAG_Nothing;

				ScrPolys[TempPoly].Pos.x = xpos;			  
				ScrPolys[TempPoly].Pos.y = ypos;
				if (TextInfo->flags & TEXTFLAG_NotImplemented)
				{
					ScrPolys[TempPoly].R = 100;					
					ScrPolys[TempPoly].G = 100;
					ScrPolys[TempPoly].B = 100;				  
				}
				else
				{
					ScrPolys[TempPoly].R = 255;					
					ScrPolys[TempPoly].G = 255;					
					ScrPolys[TempPoly].B = 255;				  
				}

				ScrPolys[TempPoly].Trans = 255;				
				ScrPolys[TempPoly].Xscale = VduScaleX;				
				ScrPolys[TempPoly].Yscale = VduScaleY;			  
				switch (pos)
				{
					case -1:
						ScrPolys[TempPoly].Frame = TextLookup[font][16];
						break;
					case -2:
						ScrPolys[TempPoly].Frame = TextLookup[font]['*'];
						ScrPolys[TempPoly].Type = SCRTYPE_LastAFrame;
						break;
					default:
						ScrPolys[TempPoly].Frame = TextLookup[font][TextInfo->text[pos]];
				}
									
				ScrPolys[TempPoly].Frm_Info = &Title_Fonts_Header;
					
				AddScrPolyToTPage( TempPoly, GetTPage( *ScrPolys[ TempPoly ].Frm_Info, 0 ) );

			}
			else
				return FALSE;
		}else
		{
			switch (pos)
			{
			case -1:
				Bit_Ptr = ( Title_Fonts_Header->Bit_Info + (int16)(TextLookup[font][16]) );
				break;
			case -2:
				Bit_Ptr = ( Title_Fonts_Header->Bit_Info + (int16)(TextLookup[font]['*']) );
				break;
			default:
				Bit_Ptr = ( Title_Fonts_Header->Bit_Info + (int16)(TextLookup[font][TextInfo->text[pos]]) );
			}

			Off_Ptr = ( Title_Fonts_Header->Off_Info + Bit_Ptr->startbit );
			Box_Ptr = ( Title_Fonts_Header->Box_Info + ( Off_Ptr->box & 0x0fff ) );

			src.top = (long)(Box_Ptr->v1 * 256.0F);
			src.bottom = (long)(Box_Ptr->v2 * 256.0F);
			src.left = (long)(Box_Ptr->u1 * 256.0F);
			src.right = (long)(Box_Ptr->u2 * 256.0F);
			memset(&fx, 0, sizeof(DDBLTFX));
			fx.dwSize = sizeof(DDBLTFX);

			dest.top = (long)ypos - (long)((float)Box_Ptr->ysize * VduScaleY);
			dest.bottom = (long)ypos;
			dest.left = (long)xpos;
			dest.right = (long)xpos + (long)((float)Box_Ptr->xsize * VduScaleX);

			while( 1 )
			{
				ddrval = d3dapp->lpBackBuffer->lpVtbl->Blt( d3dapp->lpBackBuffer, &dest, lpDDSTitleFont, &src, DDBLT_WAIT | DDBLT_KEYSRC, &fx );
				if( ddrval == DD_OK )
					break;
			    if( ddrval == DDERR_SURFACELOST )
				{
					d3dapp->lpFrontBuffer->lpVtbl->Restore(d3dapp->lpFrontBuffer);
					d3dapp->lpBackBuffer->lpVtbl->Restore(d3dapp->lpBackBuffer);
				
					ReInitTitleFont();
	
			        break;
				}
				if( ddrval != DDERR_WASSTILLDRAWING )
				{
					int dummy;

					switch( ddrval )
					{
					case DDERR_GENERIC :
						dummy = 1;
						break;
					case DDERR_INVALIDCLIPLIST :
						dummy = 2;
						break;
					case DDERR_INVALIDOBJECT :
						dummy = 3;
						break;
					case DDERR_INVALIDPARAMS :
						dummy = 4;
						break;
					case DDERR_INVALIDRECT :
						dummy = 5;
						break;
					case DDERR_NOALPHAHW :
						dummy = 6;
						break;
					case DDERR_NOBLTHW :
						dummy = 7;
						break;
					case DDERR_NOCLIPLIST :
						dummy = 8;
						break;
					case DDERR_NODDROPSHW :
						dummy = 9;
						break;
					case DDERR_NOMIRRORHW :
						dummy = 10;
						break;
					case DDERR_NORASTEROPHW :
						dummy = 11;
						break;
					case DDERR_NOROTATIONHW :
						dummy = 12;
						break;
					case DDERR_NOSTRETCHHW :
						dummy = 13;
						break;
					case DDERR_NOZBUFFERHW :
						dummy = 14;
						break;
					case DDERR_SURFACEBUSY :
						dummy = 15;
						break;
					case DDERR_SURFACELOST :
						dummy = 16;
						break;
					case DDERR_UNSUPPORTED :
						dummy = 17;
						break;
					}
					break;
				}
			}
		}
	}

	return TRUE;
}

void Print3Dots(TEXTINFO *TextInfo, float totalheight)
{
	int font, i;
	float xpos, ypos, width;
	BIT_INFO	*	Bit_Ptr;
	BOX_INFO	*	Box_Ptr;
	OFF_INFO	*	Off_Ptr;
    RECT    src, dest;
	HRESULT ddrval;
	DDBLTFX fx;
	uint16 TempPoly;
	
	font = GetScreenFont(TextInfo->font);

	GetTextPos(TextInfo, &xpos, &ypos, TextInfo->num_lines - 1, totalheight);
		
	
	Bit_Ptr = ( Title_Fonts_Header->Bit_Info + (int16)(TextLookup[font]['.']) );
	Off_Ptr = ( Title_Fonts_Header->Off_Info + Bit_Ptr->startbit );
	Box_Ptr = ( Title_Fonts_Header->Box_Info + ( Off_Ptr->box & 0x0fff ) );

	width = Box_Ptr->xsize;


	for (i = 0; i < 3; i++)
	{
		if (bPolyText && PolyText[MyGameStatus])
		{
			TempPoly = FindFreeScrPoly();					
			if( TempPoly != (uint16 ) -1 )
			{
							
				ScrPolys[TempPoly].Type = SCRTYPE_LastAFrame;
				ScrPolys[TempPoly].Flags = SCRFLAG_Nothing;

				ScrPolys[TempPoly].Pos.x = xpos;			  
				ScrPolys[TempPoly].Pos.y = ypos;
				ScrPolys[TempPoly].R = 255;					
				ScrPolys[TempPoly].G = 255;					
				ScrPolys[TempPoly].B = 255;				  
				ScrPolys[TempPoly].Trans = 255;				
				ScrPolys[TempPoly].Xscale = VduScaleX;				
				ScrPolys[TempPoly].Yscale = VduScaleY;			  
				ScrPolys[TempPoly].Frame = TextLookup[font]['.'];
				ScrPolys[TempPoly].Type = SCRTYPE_LastAFrame;
				ScrPolys[TempPoly].Frm_Info = &Title_Fonts_Header;
				AddScrPolyToTPage( TempPoly, GetTPage( *ScrPolys[ TempPoly ].Frm_Info, 0 ) );

			}
			else
			{
				Msg("Unable to allocate screen poly\n");
				exit(1);
			}
		}else
		{

			src.top = (long)(Box_Ptr->v1 * 256.0F);
			src.bottom = (long)(Box_Ptr->v2 * 256.0F);
			src.left = (long)(Box_Ptr->u1 * 256.0F);
			src.right = (long)(Box_Ptr->u2 * 256.0F);
			memset(&fx, 0, sizeof(DDBLTFX));
			fx.dwSize = sizeof(DDBLTFX);
			dest.top = (unsigned long)ypos - Box_Ptr->ysize * (long)VduScaleY;
			dest.bottom = (unsigned long)ypos;
			dest.left = (unsigned long)xpos;
			dest.right = (unsigned long)xpos + Box_Ptr->xsize * (long)VduScaleX;

			while( 1 )
			{
				ddrval = d3dapp->lpBackBuffer->lpVtbl->Blt( d3dapp->lpBackBuffer, &dest, lpDDSTitleFont, &src, DDBLT_WAIT | DDBLT_KEYSRC, &fx );
				if( ddrval == DD_OK )
					break;
				if( ddrval == DDERR_SURFACELOST )
				{
					d3dapp->lpFrontBuffer->lpVtbl->Restore(d3dapp->lpFrontBuffer);
					d3dapp->lpBackBuffer->lpVtbl->Restore(d3dapp->lpBackBuffer);
				
					ReInitTitleFont();

					break;
				}
				if( ddrval != DDERR_WASSTILLDRAWING )
					break;
			}
		}
		xpos += width + TEXTINFO_TextSpace;
	}
}

BOOL VduFinished( MENU *Menu )
{
	int i, j;
	BOOL eventsactive = FALSE;
	TITLE_EVENT *Event;

	if ( Menu && ( Menu != CurrentMenu ) )
		return FALSE;

	if ( !TextStackLevel )
		return FALSE;
	
	for (i=0; i<TextStackLevel; i++)
	{	
		for ( j = 0; j < TextStack[i]->num_lines; j++ )
		{
			if ( !TextStack[ i ]->finished[ j ] )
				return FALSE;
		}
	}



	for (Event = Title_Events; Event->TriggeredBy >= 0; Event++)
	{
		switch( Event->Status )
		{
		case TITLE_EVENT_STATUS_IDLE:
			break;
		default:
			eventsactive = TRUE;
		}
	}

	if ( !eventsactive )
		return TRUE;
	else
		return FALSE;
}

void DisplayTextItem (TEXTINFO *TextInfo)
{
	int i, j, font, num_invalid_chars, skip, UpToChar;
	float totalheight;
	TEXTINFO TempTextInfo;
  	TEXT *t;
	BOOL DoForceFit;

	if (MenuState == MENUSTATE_Text2)
		t = (TEXT *)(TextItem->Variable);
	
	font = GetScreenFont(TextInfo->font);

	num_invalid_chars = 0;

	for (i = 0; i < TextInfo->num_lines; i++)
	{
		totalheight += TextInfo->height[i];
	}


	TextInfo->currenty = 0.0F;
	DoForceFit = FALSE;

	for (i=0; i<TextInfo->num_lines; i++)
	{
		TextInfo->currentx[i] = 0.0F;
		skip = TeleTypeSkip;

		while (skip > 0)
		{
			if ((TextInfo->currentchar[i] + TextInfo->startpoint[i]) <= TextInfo->endpoint[i])
			{
				TextInfo->currentchar[i]++;
				NewTextCharDisplayed = TRUE;
			}
			skip--;
		}

		if ( !NewTextCharDisplayed )
			TextInfo->finished[ i ] = TRUE;
		
		if ( (i == TextInfo->num_lines - 1) && (TextInfo->currentchar[i] - 1 == TextInfo->endpoint[i] - TextInfo->startpoint[i]))
		{
			DoForceFit = TRUE;
		}

		if( TextInfo->flags & TEXTFLAG_Instant)
			UpToChar = TextInfo->endpoint[i] + 1;
		else
			UpToChar = TextInfo->currentchar[i] ;

		for (j=0; j <= UpToChar; j++)
		{
			if ((MenuState == MENUSTATE_Text2) && (t->insert_pos - t->VDU_insert_pos == j))
			{	
				if ((TextInfo == TextItem->TextInfo[1]) && CursorTimer > 1.0F)
					DrawTextEditCursor( TextItem->TextInfo[1], font );
			}

			if (j != UpToChar)
			{
				if (TextLookup[font][TextInfo->text[TextInfo->startpoint[i] + j]])
					DisplayTextCharacter(TextInfo, i,TextInfo->startpoint[i] + j, font, totalheight);
			}
		}
	
		if (i != TextInfo->num_lines - 1)
		{
			TextInfo->currenty += TextInfo->height[i];
		}
	}

	// if a force fit is required and necessary, and we have already printed the last
	// character of the last line...
	if ((TextInfo->flags & TEXTFLAG_ForceFit) && (TextInfo->force_fit) &&
		( DoForceFit ))
	{
		Print3Dots(TextInfo, totalheight);
	}

	TextInfo->currenty = 0.0F;
	TempTextInfo = *TextInfo;

	
	if (!(TempTextInfo.flags & TEXTFLAG_Instant))
	{
		for (i=0; i<TempTextInfo.num_lines; i++)
		{
			if (TempTextInfo.currentchar[i] <= (TempTextInfo.endpoint[i] - TempTextInfo.startpoint[i]))  
			{
				DisplayTextCharacter(&TempTextInfo, i, -2, font, totalheight);
				TextInfo->finished[ i ] = FALSE;
			}
			
			TempTextInfo.currenty += TempTextInfo.height[i];
		}
	}
}
 	
void GetFinalChars( TEXTINFO *TextInfo, int currentpos, int length)
{
	BIT_INFO	*	Bit_Ptr;
	BOX_INFO	*	Box_Ptr;
	OFF_INFO	*	Off_Ptr;
	int i;
	float width;
	int font;

	font = GetScreenFont(TextInfo->font);
	
	width = TextInfo->xmax * ModeScaleX[ModeCase] - TextInfo->xmin * ModeScaleX[ModeCase];

	for (i = currentpos; i < length; i++)
	{
		Bit_Ptr = ( Title_Fonts_Header->Bit_Info + (int16)(TextLookup[font][TextInfo->text[i]]) );	// right arrow character
		Off_Ptr = ( Title_Fonts_Header->Off_Info + Bit_Ptr->startbit );
		Box_Ptr = ( Title_Fonts_Header->Box_Info + ( Off_Ptr->box & 0x0fff ) );


		if (TEXTINFO_currentx + Box_Ptr->xsize + TEXTINFO_TextSpace < width)
		{
			TEXTINFO_currentx += Box_Ptr->xsize + TEXTINFO_TextSpace;
			TEXTINFO_currentendpoint++;
		}else
			break;
	}

	TEXTINFO_currentendpoint--;
	
}
						 
void PrintTextItem (TEXTINFO *TextInfo)
{
	int StartPos;
	int length;
	uint8 *str;
	int i;
	BOOL newline;

	str = TextInfo->text;

	if (!str)
		str = EmptyString;

	length = strlen(str);

	TEXTINFO_currentx = 0.0F;
	TEXTINFO_currenty = 0.0F;	
	TEXTINFO_currentheight = 0.0F;
	TextInfo->num_lines = 1;
	TextInfo->char1x = 999.0F;

	StartPos = 0;
	TEXTINFO_currentendpoint = 0;
	TextInfo->startpoint[0] = 0;
	TextInfo->endpoint[0] = 0;
	TextInfo->force_fit = FALSE;
	
	newline = TRUE;
	ForceNewLine = FALSE;

	if (length == 0)
	{
	 	TextInfo->num_lines = 0;
		return;	//do nothing if there is no text to process
	}
	
	for (i=0; i<length; i++)
	{
		if ((str[i] == ' ') || (str[i] == '~') || (i == length - 1))
		{
			if (newline)
				TEXTINFO_currentstartpoint = StartPos;
			if(!FormatTextItem(StartPos, i, TextInfo, &newline))
			{
			 	if (!(TextInfo->flags & TEXTFLAG_ForceFit))
				{
					//Msg( "FormatTextItem() : returned false\nbounding box for text ( %s ) too small??\n", TextInfo->text );
					DebugPrintf( "FormatTextItem() : returned false\tbounding box for text ( %s ) too small??\n", TextInfo->text );
				}else
				{
				  // need to find out how many chars of last word will fit...
					GetFinalChars( TextInfo, TEXTINFO_currentendpoint, length);
				}

				break;
			}
			else
				StartPos = i + 1;
		}


	}
	
	if (newline)
		TEXTINFO_currentstartpoint = StartPos;

	TextInfo->length[TextInfo->num_lines-1] = TEXTINFO_currentx;
	TextInfo->height[TextInfo->num_lines-1] = TEXTINFO_currentheight + TEXTINFO_LineSpace;
	TextInfo->endpoint[TextInfo->num_lines-1] = TEXTINFO_currentendpoint;

	for (i=0; i<TextInfo->num_lines; i++)
	{
		TextInfo->currentchar[i] = 0;
		TextInfo->currentx[i] = 0.0F;
	}

	TextInfo->currenty = 0.0F;

	//TeleTypeTimer = 0.0F;

	for (i = 0; i < TextInfo->num_lines; i++)
	{
		TextInfo->currentchar[i] = 0;
	
		TextInfo->currentx[i] = 0.0F;
		TextInfo->currenty = 0.0F;
	}

}

void ProcessTextItems (void)
{
	int i, teletypenum;
	char temptext[64];
	BOOL textstored;
	static float VidTextSfxPause = 0.0F;
	static float theta = 0.0F;
	uint8 r, g, b;
	float multiplier;

	teletypenum = 0;

	for (i = 0; i < MAXHIGHLIGHTITEMS; i++)
	{	HighlightItem[i] = NULL;
		HighlightStatus[i] = HIGHLIGHT_Pulsing;
	}
	CurrentHighlightItem = 0;

	TeleTypeTimer += framelag/(0.05F * 60.0F);
	TeleTypeSkip = (int)floor((float)TeleTypeTimer);

	TeleTypeTimer -= (float)TeleTypeSkip;

	NewTextCharDisplayed = FALSE;
	for (i=0; i<TextStackLevel; i++)
	{	
		if ( TextStack[ i ] )
		{
			textstored = FALSE;
			if (TextStack[i]->flags & TEXTFLAG_Pulse)
			{
				if (Pulse >= 0.5F)
				{
					strcpy( temptext, TextStack[i]->text );
					TextStack[i]->text[0] = 0;
					PrintTextItem(TextStack[i]);
					textstored = TRUE;
				}
			}
			if (TextStack[i]->flags & TEXTFLAG_CheckForRefresh)
			{
				if (strncmp(TextStack[i]->oldtext, TextStack[i]->text, MAX_TEXT_LENGTH) != 0)
				{
					strncpy(TextStack[i]->oldtext, TextStack[i]->text, MAX_TEXT_LENGTH);
					PrintTextItem(TextStack[i]);
				}
			}

			if (TextStack[i]->highlight)
			{ 
				HighlightItem[ CurrentHighlightItem ] = TextStack[i];
				HighlightStatus[ CurrentHighlightItem++ ] = TextStack[i]->highlighttype;
			}

			if (DrawTextItemBox && !TextStack[i]->boxdone)
			{
				TextStack[i]->boxdone = TRUE;

		  		if (!Plot2dBox (TextStack[i]))
		  			Msg( "Plot2dBox() : failed\n" );
			}
			
			DisplayTextItem (TextStack[i]);
			if ( TextStack[i]->flags & TEXTFLAG_Instant )
				NewTextCharDisplayed = FALSE;	// do not do sfx for instant text

			if (textstored)
			{	strcpy( TextStack[i]->text, temptext );
				PrintTextItem(TextStack[i]);
			}
		}
	}

	VidTextSfxPause += framelag;
	if ( NewTextCharDisplayed )
	{
		if ( VidTextSfxPause > 5.0F )
		{
			PlaySfx( SFX_VidText, 0.4F );
			VidTextSfxPause = 0.0F;
		}
	}

	if (VDU_Ready && ((CameraStatus == CAMERA_AtRightVDU) || (CameraStatus == CAMERA_AtLeftVDU)))
	{
		if ((LastMenuItem != CurrentMenuItem) || !(bPolyText && PolyText[MyGameStatus]))
		{
			LastMenuItem = CurrentMenuItem;
		}
	}
	
	if (CurrentMenuItem && VDU_Ready && TextStackLevel )
	{
		if (CurrentMenuItem->TextInfo[0])
		{
			if (!(CurrentMenuItem->TextInfo[0]->flags & TEXTFLAG_SuppressHighlight))
			{
				if (!CurrentMenuItem->TextInfo[0]->highlight)	// ensures item is not highlighted twice
				{
					HighlightItem[ CurrentHighlightItem ] = CurrentMenuItem->TextInfo[0];
					HighlightStatus[ CurrentHighlightItem++ ] = CurrentMenuItem->TextInfo[0]->highlighttype;
				}
			}
		}
	}

	CursorTimer += framelag/(CursorInterval * 60.0F) * 2.0F;
	if (CursorTimer >= 2.0F)
		CursorTimer -= 2.0F;


	ProcessFlatSliders();

/******************
Highlight box
*******************/	
	theta += 360.0F * framelag/(60.0F);
	if (theta > 360.0F)
		theta -= 360.0F;
	multiplier = (float)(SIND(theta) + 1.0F)/2.0F;
	r = (uint8)(64.0F * multiplier);
	b = r;
	g = (uint8)(255.0F * multiplier);
	
	for (i = 0; i < MAXHIGHLIGHTITEMS; i++)
	{
		if (HighlightItem[i] && VDU_Ready)
		{	
			switch (HighlightStatus[i])
			{
			case HIGHLIGHT_Static:
//					if (CurrentMenu == &MENU_NEW_JoinWaitingToStart)
				DrawHighlightBox(HighlightItem[i], 64, 255, 64);
				break;
			default:
				DrawHighlightBox(HighlightItem[i], r, g, b);
				break;
			}
		}
	}
}


void InitScreenFonts (void)
{

	int i, font, offset, space;

	for (font=0; font<NUMSCREENFONTS; font++)
	{

		switch (font)
		{
		case FONT_512X384_Small:
		case FONT_320X200_Small:
		case FONT_320X240_Small:
			offset = 148;
			space = 222;
			break;
		case FONT_512X384_Medium:
		case FONT_320X200_Medium:
		case FONT_320X240_Medium:
			offset = 74;
			space = 223;
			break;
		case FONT_512X384_Large:
		case FONT_320X200_Large:
		case FONT_320X240_Large:
			offset = 0;
			space = 224;
			break;
		default:
			offset = 148;
			space = 222;
			break;
		}

		TextLookup[font][0] = 0 + offset;	//ASCII 0 used for cursor
		
		for (i=1; i<= 15; i++)
			TextLookup[font][i] = 0;
		
		TextLookup[font][16] = 71 + offset;	//	right arrow
		TextLookup[font][17] = 70 + offset;	// left arrow

		for (i=18; i<=29; i++)
			TextLookup[font][i] = 0;

		TextLookup[font][30] = 72 + offset;	// up arrow
		TextLookup[font][31] = 73 + offset;	// down arrow

		TextLookup[font][32] = space; // space

		for (i=33; i<=37; i++)
			TextLookup[font][i] = i - 32 + offset;	// ! " # $ %

		for (i=38; i<=39; i++)
			TextLookup[font][i] = 0;

		for (i=40; i<=43; i++)
			TextLookup[font][i] = i - 34 + offset;	// ( ) * +

		for (i=45; i<=90; i++)
			TextLookup[font][i] = i - 35 + offset; // - . / 0-9 : ; < = > ? @ A-Z

		for (i=91; i<=96; i++)
			TextLookup[font][i] = 0;

		for (i=97; i<=122; i++)
			TextLookup[font][i] = i - 67 + offset; // a-z

		for (i=123; i<=255; i++)
			TextLookup[font][i] = 0;

		TextLookup[font]['='] = 27 + offset;
		TextLookup[font]['['] = 6 + offset;
		TextLookup[font][']'] = 7 + offset;

		// foreign characters...
		TextLookup[font][(uint8)'�'] = 56 + offset; 
		TextLookup[font][(uint8)'�'] = 56 + offset; 
		TextLookup[font][(uint8)'�'] = 56 + offset; 
		TextLookup[font][(uint8)'�'] = 57 + offset; 
		TextLookup[font][(uint8)'�'] = 57 + offset; 
		TextLookup[font][(uint8)'�'] = 58 + offset; 
		TextLookup[font][(uint8)'�'] = 58 + offset; 
		TextLookup[font][(uint8)'�'] = 59 + offset; 
		TextLookup[font][(uint8)'�'] = 59 + offset; 
		TextLookup[font][(uint8)'�'] = 60 + offset; 
		TextLookup[font][(uint8)'�'] = 60 + offset; 
		TextLookup[font][(uint8)'�'] = 61 + offset; 
		TextLookup[font][(uint8)'�'] = 62 + offset; 
		TextLookup[font][(uint8)'�'] = 63 + offset; 
		TextLookup[font][(uint8)'�'] = 63 + offset; 
		TextLookup[font][(uint8)'�'] = 64 + offset; 
		TextLookup[font][(uint8)'�'] = 64 + offset; 
		TextLookup[font][(uint8)'�'] = 65 + offset; 
		TextLookup[font][(uint8)'�'] = 65 + offset; 
		TextLookup[font][(uint8)'�'] = 66 + offset; 
		TextLookup[font][(uint8)'�'] = 66 + offset; 
		TextLookup[font][(uint8)'�'] = 67 + offset; 
		TextLookup[font][(uint8)'�'] = 67 + offset; 
		TextLookup[font][(uint8)'�'] = 68 + offset; 
		TextLookup[font][(uint8)'�'] = 68 + offset; 
		TextLookup[font][(uint8)'�'] = 69 + offset; 
		TextLookup[font][(uint8)'�'] = 69 + offset;
		TextLookup[font][(uint8)'�'] = TextLookup[font][(uint8)'B'];
		
/*
  128  � ( 199 )  144  � ( 201 )  160  � ( 225 )   
  129  � ( 252 )  145  � ( 230 )  161  � ( 237 )  
  130  � ( 233 )  146  � ( 198 )  162  � ( 243 )  
  131  � ( 226 )  147  � ( 244 )  163  � ( 250 )  
  132  � ( 228 )  148  � ( 246 )  164  � ( 241 )  
  133  � ( 224 )  149  � ( 242 )  165  � ( 209 )  
  134  � ( 229 )  150  � ( 251 )  166  � ( 170 )  
  135  � ( 231 )  151  � ( 249 )  167  � ( 186 )
  136  � ( 234 )  152  � ( 255 )  168  � ( 191 )
  137  � ( 235 )  153  � ( 214 )  169  _ ( 095 )
  138  � ( 232 )  154  � ( 220 )  170  � ( 172 )  
  139  � ( 239 )  155  � ( 162 )  171  � ( 189 )  
  140  � ( 238 )  156  � ( 163 )  172  � ( 188 )  
  141  � ( 236 )  157  � ( 165 )  173  � ( 161 )  
  142  � ( 196 )  158  P ( 080 )  174  � ( 171 )  
  143  � ( 197 )  159  � ( 131 )  175  � ( 187 )  
*/
		
		TextLookup[font][1] = 225;	// glowing effect for bike scan

		TextLookup[font]['_'] = space; // underscore prints as space

		switch (font)
		{
		case FONT_512X384_Small:
		case FONT_320X200_Small:
		case FONT_320X240_Small:
			TextLookup[font][39] = 228; // apostrophe
			TextLookup[font][96] = 228; // apostrophe
			TextLookup[font][','] = 231; // comma

			TextLookup[font][(uint8)'�'] = 234;
			TextLookup[font][(uint8)'�'] = 237;
			TextLookup[font][(uint8)'�'] = 240;
			TextLookup[font][(uint8)'�'] = 240;

			TextLookup[font][(uint8)'�'] = 243;
			TextLookup[font][(uint8)'�'] = 246;
			TextLookup[font][(uint8)'�'] = 249;
			TextLookup[font][(uint8)'�'] = 252;
			TextLookup[font][(uint8)'�'] = 255;
			TextLookup[font][(uint8)'�'] = 258;
			TextLookup[font][(uint8)'�'] = 258;
			TextLookup[font][(uint8)'�'] = 261;
			TextLookup[font][(uint8)'�'] = 264;
			break;
		case FONT_512X384_Medium:
		case FONT_320X200_Medium:
		case FONT_320X240_Medium:
			TextLookup[font][39] = 227; // apostrophe
			TextLookup[font][96] = 227; // apostrophe
			TextLookup[font][','] = 230; // comma

			TextLookup[font][(uint8)'�'] = 233;
			TextLookup[font][(uint8)'�'] = 236;
			TextLookup[font][(uint8)'�'] = 239;
			TextLookup[font][(uint8)'�'] = 239;

			TextLookup[font][(uint8)'�'] = 242;
			TextLookup[font][(uint8)'�'] = 245;
			TextLookup[font][(uint8)'�'] = 248;
			TextLookup[font][(uint8)'�'] = 251;
			TextLookup[font][(uint8)'�'] = 254;
			TextLookup[font][(uint8)'�'] = 257;
			TextLookup[font][(uint8)'�'] = 257;
			TextLookup[font][(uint8)'�'] = 260;
			TextLookup[font][(uint8)'�'] = 263;
			break;
		case FONT_512X384_Large:
		case FONT_320X200_Large:
		case FONT_320X240_Large:
			TextLookup[font][39] = 226; // apostrophe
			TextLookup[font][96] = 226; // apostrophe
			TextLookup[font][','] = 229; // comma

			TextLookup[font][(uint8)'�'] = 232;
			TextLookup[font][(uint8)'�'] = 235;
			TextLookup[font][(uint8)'�'] = 238;
			TextLookup[font][(uint8)'�'] = 238;

			TextLookup[font][(uint8)'�'] = 241;
			TextLookup[font][(uint8)'�'] = 244;
			TextLookup[font][(uint8)'�'] = 247;
			TextLookup[font][(uint8)'�'] = 250;
			TextLookup[font][(uint8)'�'] = 253;
			TextLookup[font][(uint8)'�'] = 256;
			TextLookup[font][(uint8)'�'] = 256;
			TextLookup[font][(uint8)'�'] = 259;
			TextLookup[font][(uint8)'�'] = 262;
			break;
		}
	}
}

/*********************************************************************************************************
end of VDU text routines
*********************************************************************************************************/



void SinPan2(VECTOR ViewFrom, VECTOR ViewTo, VECTOR *CurrentView,
			 VECTOR LookFrom, VECTOR LookTo, VECTOR *CurrentLook, float Time)
{
	float SinTheta, OneMinus, theta;

	theta = Time * 90.0F;

	SinTheta = (float)SIND(theta);
	OneMinus = 1 - SinTheta;	

	CurrentView->x = OneMinus * ViewFrom.x + SinTheta * ViewTo.x;
	CurrentView->y = OneMinus * ViewFrom.y + SinTheta * ViewTo.y;
	CurrentView->z = OneMinus * ViewFrom.z + SinTheta * ViewTo.z;

	CurrentLook->x = OneMinus * LookFrom.x + SinTheta * LookTo.x;
	CurrentLook->y = OneMinus * LookFrom.y + SinTheta * LookTo.y;
	CurrentLook->z = OneMinus * LookFrom.z + SinTheta * LookTo.z;
  
}

void RotateVDU2(float time, float start, float end)
{
	float SinTheta, OneMinus, theta;
	MATRIX Mat_R;

	theta = time * 90.0F;

	SinTheta = (float)SIND(theta);
	OneMinus = 1 - SinTheta;	

	VDUrot = OneMinus * start + SinTheta * end;
	
	// build rotate matrix...
	BuildRotMatrix(0.0F, VDUrot, 0.0F, &Mat_R);

	// rotate vdu...
	Models[BackgroundModel[TITLE_MODEL_VDU]].Mat = Mat_R;
	MatrixTranspose(&Mat_R, &Models[BackgroundModel[TITLE_MODEL_VDU]].InvMat);
}

void RotateBracket(float time, float start, float end)
{
	float SinTheta, OneMinus, theta;
	MATRIX Mat_R;

	theta = time * 90.0F;

	SinTheta = (float)SIND(theta);
	OneMinus = 1 - SinTheta;	

	BracketRot = OneMinus * start + SinTheta * end;
	
	// build rotate matrix...
	BuildRotMatrix(0.0F, BracketRot, 0.0F, &Mat_R);

	// rotate vdu...
	Models[BackgroundModel[TITLE_MODEL_Bracket]].Mat = Mat_R;
	MatrixTranspose(&Mat_R, &Models[BackgroundModel[TITLE_MODEL_Bracket]].InvMat);
}


void DarkenRoomForStart( MENU *Menu )
{
	RoomDarkness = 0.0F;
	DarkenRoom2(RoomDarkness);
}

void DarkenRoom2(float darkness)
{
	int model;
	float RoomDim;

	darkness = 1.0F - darkness;
	
	RoomDim = ((1.0F - darkness) * 0.6F) + 0.4F;	//1 - 0.4
	
	for (model = 0; model < NumTitleModelsToLoad; model++)
	{	
		switch (model)
		{
		case TITLE_MODEL_HoloLight:
			break;	//do not darken HoloLight
		case TITLE_MODEL_MenuTV:
			TintModelVertices( BackgroundModel[model], RoomDim, &MenuTVExcluded);
			break;
		case TITLE_MODEL_MenuTVDummy:
			TintModelVertices( BackgroundModel[model], RoomDim, &MenuTVDummyExcluded);
			break;
		case TITLE_MODEL_VDU:
			TintModelVertices( BackgroundModel[model], RoomDim, &VduScreenExcluded);
			break;
		case TITLE_MODEL_Room:
			TintModelVertices( BackgroundModel[model], RoomDim, &RoomExcluded);
			break;
		default:
			TintModelVertices( BackgroundModel[model], RoomDim, NULL );
			break;
		}
		
	}
}

void RotateDiscStack(float theta)
{
	MATRIX Mat_R;
	VECTOR rotpoint, stackoffset;
	int i;
	int modellookup [8] = {10, 0, 1, 2, 3, 4, 5, 6};

	rotpoint.x = stackpos[0].x;
	rotpoint.y = stackpos[0].y + 70.0F;
	rotpoint.z = stackpos[0].z - 60.0F;

	for (i=0; i<8; i++)
	{
		
		stackoffset.x = stackpos[i].x - rotpoint.x;
		stackoffset.y = stackpos[i].y - rotpoint.y;
		stackoffset.z = stackpos[i].z - rotpoint.z;

		BuildRotMatrix(theta, 0.0F, 0.0F, &Mat_R);

		ApplyMatrix(&Mat_R, &stackoffset, &stackoffset);

		Models[BackgroundModel[modellookup[i]]].Pos.x = rotpoint.x + stackoffset.x;
		Models[BackgroundModel[modellookup[i]]].Pos.y = rotpoint.y + stackoffset.y;
		Models[BackgroundModel[modellookup[i]]].Pos.z = rotpoint.z + stackoffset.z;
		
		Models[BackgroundModel[TITLE_MODEL_Mtop]].Mat = Mat_R;
		MatrixTranspose(&Mat_R, &Models[BackgroundModel[modellookup[i]]].InvMat);

	}

}

float GetEventCurrentTime(TITLE_EVENT *TitleEvent)
{
	float currenttime;

	if (Title_Timers[TitleEvent->TriggeredBy].CurrentTime >= TitleEvent->EndTime)
		currenttime = 1.0F;
	else
		currenttime = (Title_Timers[TitleEvent->TriggeredBy].CurrentTime - TitleEvent->StartTime) / (TitleEvent->EndTime - TitleEvent->StartTime);

	return currenttime;

}

void LoadBikeChar(MENUITEM *Item)
{

	
	BIT_INFO	*	Bit_Ptr;
	BOX_INFO	*	Box_Ptr;
	OFF_INFO	*	Off_Ptr;
	int Biker;
	float xmin, xmax, ymin, ymax, newxmax, newymax, xgap, ygap;
//	MENUITEM *Item;
	float BikeCharScale = 0.7F;
	FRAME_INFO **header;
	int systpageindex;
	
	xmin = (Item->x + VDUoffsetX) * ModeScaleX[ModeCase];
	xmax = (Item->xmax + VDUoffsetX) * ModeScaleX[ModeCase];
	ymin = (Item->y + VDUoffsetY) * ModeScaleY[ModeCase];
	ymax = (Item->ymax + VDUoffsetY) * ModeScaleY[ModeCase];
	

	Biker = SelectedBikeFrame;

	if( Biker < 0 )
	{
		KillBikeCharPic( NULL );
		return;
	}

	if ((Biker <= 7) && (Biker >= 0))
	{	
		header = &Title_Chars1_Header;
	}
	else
	{	
		if ((Biker >= 8) && (Biker <= 15))
		{
			header = &Title_Chars2_Header;
			Biker -= 8;
		}
		else
		{	
			Msg("Title.c: LoadBikeChar() invalid char no.");
			exit(1);
		}
	}

	systpageindex = (*header)->sys_tpage_index;
	MovePPMToVideoMemory( &Tloadheader, (*header)->vid_tpage_index, SystemMemTPages[ systpageindex ].lpSrcTextureSurf );
	
	if (!LoadGeneralPic(0, 0, 0, 0, header, &Biker, &BikerScrPoly, &BikerDisplayed))
	{
		Msg("Title.c LoadBikeChar() unable to allocate screen poly\n");
		exit(1);
	}

	Bit_Ptr = ( (*ScrPolys[ BikerScrPoly ].Frm_Info)->Bit_Info + (int16) ScrPolys[ BikerScrPoly ].Frame );
	Off_Ptr = ( (*ScrPolys[ BikerScrPoly ].Frm_Info)->Off_Info + Bit_Ptr->startbit );
	Box_Ptr = ( (*ScrPolys[ BikerScrPoly ].Frm_Info)->Box_Info + ( Off_Ptr->box & 0x0fff ) );

	newxmax = Box_Ptr->xsize * ModeScaleX[ModeCase] * BikeCharScale + xmin;
	newymax = Box_Ptr->ysize * ModeScaleY[ModeCase] * BikeCharScale + ymin;

	xgap = (xmax - newxmax) / 2.0F;
	ygap = (ymax - newymax) / 2.0F;

	xmin = xmin + xgap;
	ymin = ymin + ygap;	
	xmax = newxmax + xgap;					
	ymax = newymax + xgap;	

	ScrPolys[BikerScrPoly].x1 = xmin;
	ScrPolys[BikerScrPoly].y1 = ymin;	
	ScrPolys[BikerScrPoly].x3 = xmax;					
	ScrPolys[BikerScrPoly].y3 = ymax;					
}

void LoadBikeCharPic(MENUITEM *Item)
{
	int Biker;
	float xmin, xmax, ymin, ymax;
	FRAME_INFO **header;

	xmin = (Item->x + VDUoffsetX) * ModeScaleX[ModeCase];
	xmax = (Item->xmax + VDUoffsetX) * ModeScaleX[ModeCase];
	ymin = (Item->y + VDUoffsetY) * ModeScaleY[ModeCase];
	ymax = (Item->ymax + VDUoffsetY) * ModeScaleY[ModeCase];

	Biker = SelectedBikeFrame;

	if ((Biker <= 7) && (Biker >= 0))
		header = &Title_Chars1_Header;
	else
	{	if ((Biker >= 8) && (Biker <= 15))
		{
			Biker -= 8;
			header = &Title_Chars2_Header;
		}
		else
			return;
	}


	//LoadGeneralPic(Item, header, &Biker, &BikerScrPoly, &BikerDisplayed);
}

void KillBikeCharPic( MENU *Menu )
{
	if (BikerDisplayed)
	{	KillUsedScrPoly ( BikerScrPoly );
		BikerScrPoly = (uint16)-1;
		BikerDisplayed = FALSE;
	}
}


void LoadLevelPic(MENUITEM *Item)
{
    LPDIRECTDRAWSURFACE lpSrcTextureSurf = NULL;
    LPDIRECT3DTEXTURE lpSrcTexture = NULL;
	float xmin, xmax, ymin, ymax;
	FRAME_INFO **header;
	int frame = 0;

	strcpy( Tloadheader.PlaceHolderFile[ Title_LevelPics_Header->vid_tpage_index ], MissionTextPics[ NewLevelNum ] );

	if ( !TloadReloadPlaceHolder( &Tloadheader, Title_LevelPics_Header->vid_tpage_index ) )
		return;

	xmin = (Item->x + VDUoffsetX) * ModeScaleX[ModeCase];
	xmax = (Item->xmax + VDUoffsetX) * ModeScaleX[ModeCase];
	ymin = (Item->y + VDUoffsetY) * ModeScaleY[ModeCase];
	ymax = (Item->ymax + VDUoffsetY) * ModeScaleY[ModeCase];

	header = &Title_LevelPics_Header;
	if (!LoadGeneralPic(xmin, ymin, xmax, ymax, header, &frame, &LevelScrPoly, &LevelDisplayed))
	{
		Msg("Title.c LoadLevelPic() unable to allocate screen poly\n");
		exit(1);
	}

}

uint16 SavedGamePicPoly;
uint16 TVFramePoly;
BOOL SavedGamePicDisplayed = FALSE;
BOOL TVFrameDisplayed = FALSE;

void LoadSavedGamePic( char *file )
{
    LPDIRECTDRAWSURFACE lpSrcTextureSurf = NULL;
    LPDIRECT3DTEXTURE lpSrcTexture = NULL;
	int frame = 0;

	if ( DummyTextureIndex == -1 )
		return;
	
	strcpy( Tloadheader.PlaceHolderFile[ DummyTextureIndex ], file );

	Pal332 = TRUE;

	if ( !TloadReloadPlaceHolder( &Tloadheader, DummyTextureIndex ) )
		return;

	Pal332 = FALSE;

	// display dummy tv
	Models[ BackgroundModel[ TITLE_MODEL_MenuTVDummy ] ].Visible = 1;
	Models[ BackgroundModel[ TITLE_MODEL_MenuTV ] ].Visible = 0;

}


void KillLevelPic( MENU *Menu )
{
	if (LevelDisplayed)
	{	KillUsedScrPoly ( LevelScrPoly );
		LevelScrPoly = (uint16)-1;
		LevelDisplayed = FALSE;
	}
}

void GetTVCoords( POLY *poly, float zoffset )
{
	int g, e, vert;
	LPD3DLVERTEX VertPtr;

	for ( g = 0; g < ModelHeaders[ TITLE_MODEL_MenuTV ].num_groups; g++ )
	{
		for ( e = 0; e < ModelHeaders[ TITLE_MODEL_MenuTV ].Group[ g ].num_execbufs; e++ )
		{
			if ( ModelHeaders[ TITLE_MODEL_MenuTV ].Group[ g ].polyanim[ e ]->vertices )
			{
				for ( vert = 0; vert < ModelHeaders[ TITLE_MODEL_MenuTV ].Group[ g ].polyanim[ e ]->vertices; vert++ )
				{
					VertPtr = &ModelHeaders[ TITLE_MODEL_MenuTV ].Group[ g ].org_vertpnt[ e ][ ModelHeaders[ TITLE_MODEL_MenuTV ].Group[ g ].polyanim[ e ]->vert[ vert ] ];
					
					switch( vert )
					{
						case 0:
							poly->Pos1.x = VertPtr->x;
							poly->Pos1.y = VertPtr->y;
							poly->Pos1.z = VertPtr->z + zoffset;
							break;
						case 1:
							poly->Pos2.x = VertPtr->x;
							poly->Pos2.y = VertPtr->y;
							poly->Pos2.z = VertPtr->z + zoffset;
							break;
						case 2:
							poly->Pos3.x = VertPtr->x;
							poly->Pos3.y = VertPtr->y;
							poly->Pos3.z = VertPtr->z + zoffset;
							break;
						case 3:
							poly->Pos4.x = VertPtr->x;
							poly->Pos4.y = VertPtr->y;
							poly->Pos4.z = VertPtr->z + zoffset;
							break;
					}
				}
			}
		}
	}
}

BOOL DisplayPicOnTV( FRAME_INFO **header, int *frame, uint16 *poly, BOOL *displayed, float zoffset )
{
	if (*displayed)
	{	KillUsedPoly ( *poly );
		*poly = (uint16)-1;
		*displayed = FALSE;
	}

	if (!*displayed)
	{
		*poly = FindFreePoly();					
		if( *poly != (uint16 ) -1 )
		{	
			*displayed = TRUE;

			GetTVCoords( &Polys[ *poly ], zoffset );

			Polys[ *poly ].Col1.R = 255;
			Polys[ *poly ].Col1.G = 255;
			Polys[ *poly ].Col1.B = 255;
			Polys[ *poly ].Col2.R = 255;
			Polys[ *poly ].Col2.G = 255;
			Polys[ *poly ].Col2.B = 255;
	   		Polys[ *poly ].Col3.R = 255;
			Polys[ *poly ].Col3.G = 255;
   			Polys[ *poly ].Col3.B = 255;
   			Polys[ *poly ].Col4.R = 255;
			Polys[ *poly ].Col4.G = 255;
   			Polys[ *poly ].Col4.B = 255;
   			Polys[ *poly ].Trans1 = 255;
	   		Polys[ *poly ].Trans2 = 255;
	   		Polys[ *poly ].Trans3 = 255;
   			Polys[ *poly ].Trans4 = 255;
	   		Polys[ *poly ].Scale = 0.0F;
	   		Polys[ *poly ].Flags = POLY_FLAG_SOLID;
   		    Polys[ *poly ].Frm_Info = header;
			Polys[ BikeLine[CurrentLine] ].Frame = (float)(*frame);

			AddPolyToTPage( BikeLine[CurrentLine], GetTPage( *Polys[ *poly ].Frm_Info, (int16) Polys[ *poly ].Frame ) );

		}
		else
			return FALSE;


	}

	return TRUE;

}

BOOL LoadGeneralPic(float xmin, float ymin, float xmax, float ymax, FRAME_INFO **header, int *frame, uint16 *scrpoly, BOOL *displayed)
{
	if (*displayed)
	{	KillUsedScrPoly ( *scrpoly );
		*scrpoly = (uint16)-1;
		*displayed = FALSE;
	}

	if (!*displayed)
	{
		*scrpoly = FindFreeScrPoly();					
		if( *scrpoly != (uint16 ) -1 )
		{	
			*displayed = TRUE;

			ScrPolys[*scrpoly].Type = SCRTYPE_Normal;
			ScrPolys[*scrpoly].Flags = SCRFLAG_UseCoords;
			ScrPolys[*scrpoly].R = 255;	
			ScrPolys[*scrpoly].G = 255;					
			ScrPolys[*scrpoly].B = 255;				  
			ScrPolys[*scrpoly].Trans = 255;
			ScrPolys[ *scrpoly ].Frm_Info = header;

			AddScrPolyToTPage( *scrpoly, GetTPage( *ScrPolys[ *scrpoly ].Frm_Info, 0 ) );

			ScrPolys[*scrpoly].Xscale = 1.0F;				
			ScrPolys[*scrpoly].Yscale = 1.0F;
		}
		else
			return FALSE;
	}

	ScrPolys[*scrpoly].x1 = xmin;
	ScrPolys[*scrpoly].y1 = ymin;	
	ScrPolys[*scrpoly].x3 = xmax;					
	ScrPolys[*scrpoly].y3 = ymax;					
	ScrPolys[ *scrpoly ].Frame = (float)*frame;

	// load correct texture...
/*
	newimagefile = (*header)->tpage_name;
	strcpy (Tloadheader.ImageFile[(*header)->vid_tpage_index], newimagefile);
	TloadReloadTextureSurf( &Tloadheader, (*header)->vid_tpage_index );
*/
	return TRUE;
}

void KillBikeChar(MENU *Menu)
{
	if (BikerDisplayed)
	{	KillUsedScrPoly( BikerScrPoly );
		BikerScrPoly = (uint16)-1;
		BikerDisplayed = FALSE;
	}

	InitBikeList( Menu );
}

void FadeBikeChar(float alpha)
{
	float col;

	col = alpha * 150.0F;
	alpha *= 255.0F;

	ScrPolys[BikerScrPoly].Trans = (uint8)alpha;	
	ScrPolys[BikerScrPoly].R = (uint8)col;					
	ScrPolys[BikerScrPoly].G = (uint8)col;					
	ScrPolys[BikerScrPoly].B = (uint8)col;				  

}
	
void InitEventGeneralPan(TITLE_EVENT *TitleEvent)
{
	OldLookPos = Look;
	OldViewPos = View;

	ResetAllEvents();

	PlaySfx( SFX_TitlePan, 0.7F );
}

void InitEventDiscPan(TITLE_EVENT *TitleEvent)
{
//	InitEventGeneralPan(TitleEvent);

//	VduClear();
//	VDU_Ready = FALSE;
}



void EventDiscPan(TITLE_EVENT *TitleEvent)
{
	float currenttime;

	currenttime = GetEventCurrentTime(TitleEvent);

	SinPan2(OldLookPos, DiscLookPos ,&Look, OldViewPos, DiscViewPos, &View, currenttime);
}

void ExitEventDiscPanFromRight(TITLE_EVENT *TitleEvent)
{
	OldSelectedBike = -1;
}

void InitEventRightVDUPan(TITLE_EVENT *TitleEvent)
{
	MATRIX Mat_R;

	//InitEventGeneralPan(TitleEvent);
	
	if (!CompareVectors(Models[BackgroundModel[TITLE_MODEL_VDU]].Pos, RightVDU.Pos))
	{
		Models[BackgroundModel[TITLE_MODEL_VDU]].Pos = RightVDU.Pos;
		Models[BackgroundModel[TITLE_MODEL_Bracket]].Pos = RightVDU.BracketPos;
		VDUrot = RightVDU.StartRot;
		BracketRot = RightVDU.BracketStartRot;
	
		BuildRotMatrix(0.0F, BracketRot, 0.0F, &Mat_R);

		Models[BackgroundModel[TITLE_MODEL_Bracket]].Mat = Mat_R;
		MatrixTranspose(&Mat_R, &Models[BackgroundModel[TITLE_MODEL_Bracket]].InvMat);

		// build rotate matrix...
		BuildRotMatrix(0.0F, VDUrot, 0.0F, &Mat_R);

		// rotate vdu...
		Models[BackgroundModel[TITLE_MODEL_VDU]].Mat = Mat_R;
		MatrixTranspose(&Mat_R, &Models[BackgroundModel[TITLE_MODEL_VDU]].InvMat);

	}
}

void EventRightVDUPan(TITLE_EVENT *TitleEvent)
{
	float currenttime;

	currenttime = GetEventCurrentTime(TitleEvent);

	SinPan2(OldLookPos, RightVDU.Look ,&Look, OldViewPos, RightVDU.View, &View, currenttime);
}

void ExitEventVDUPan(TITLE_EVENT *TitleEvent)
{
	ProcessVduItems( CurrentMenu );
	VDU_Ready = TRUE;
	OKToProcessKeys = TRUE;
}

void InitEventLeftVDUPan(TITLE_EVENT *TitleEvent)
{
	MATRIX Mat_R;

	//InitEventGeneralPan(TitleEvent);

	if (!CompareVectors(Models[BackgroundModel[TITLE_MODEL_VDU]].Pos, LeftVDU.Pos))
	{
		Models[BackgroundModel[TITLE_MODEL_VDU]].Pos = LeftVDU.Pos;
		Models[BackgroundModel[TITLE_MODEL_Bracket]].Pos = LeftVDU.BracketPos;
		VDUrot = LeftVDU.StartRot;
	
		BracketRot = RightVDU.BracketStartRot;
	
		BuildRotMatrix(0.0F, BracketRot, 0.0F, &Mat_R);

		Models[BackgroundModel[TITLE_MODEL_Bracket]].Mat = Mat_R;
		MatrixTranspose(&Mat_R, &Models[BackgroundModel[TITLE_MODEL_Bracket]].InvMat);

		// build rotate matrix...
		BuildRotMatrix(0.0F, VDUrot, 0.0F, &Mat_R);

		// rotate vdu...
		Models[BackgroundModel[TITLE_MODEL_VDU]].Mat = Mat_R;
		MatrixTranspose(&Mat_R, &Models[BackgroundModel[TITLE_MODEL_VDU]].InvMat);
	}
}

void EventLeftVDUPan(TITLE_EVENT *TitleEvent)
{
 	float currenttime;

	currenttime = GetEventCurrentTime(TitleEvent);

	SinPan2(OldLookPos, LeftVDU.Look ,&Look, OldViewPos, LeftVDU.View, &View, currenttime);
}


void InitEventRotateOutRightVDU(TITLE_EVENT *TitleEvent)
{
	OldVDUrot = VDUrot;
	OldBracketRot = BracketRot;
}

void EventRotateOutRightVDU(TITLE_EVENT *TitleEvent)
{
	float currenttime;

	currenttime = GetEventCurrentTime(TitleEvent);

	RotateVDU2(currenttime, OldVDUrot, RightVDU.EndRot);
	RotateBracket(currenttime, OldBracketRot, RightVDU.BracketEndRot);

}

void ExitEventRotateOutVDU(TITLE_EVENT *TitleEvent)
{
	PlaySfx( SFX_VduOn, 0.8F );
}

void InitEventRotateInRightVDU(TITLE_EVENT *TitleEvent)
{
	OldVDUrot = VDUrot;
	OldBracketRot = BracketRot;

	PlaySfx( SFX_VduOff, 0.8F );

}

void EventRotateInRightVDU(TITLE_EVENT *TitleEvent)
{
	float currenttime;
	
	currenttime = GetEventCurrentTime(TitleEvent);

	RotateVDU2(currenttime, OldVDUrot, RightVDU.StartRot);
	RotateBracket(currenttime, OldBracketRot, RightVDU.BracketEndRot);
}

void ExitEventRotateInRightVDU(TITLE_EVENT *TitleEvent)
{
	int i;

	i = 0;
}

void InitEventRotateOutLeftVDU(TITLE_EVENT *TitleEvent)
{
	OldVDUrot = VDUrot;
	OldBracketRot = BracketRot;
}

void EventRotateOutLeftVDU(TITLE_EVENT *TitleEvent)
{
	float currenttime;

	currenttime = GetEventCurrentTime(TitleEvent);
	
	RotateVDU2(currenttime, OldVDUrot, LeftVDU.EndRot);
	RotateBracket(currenttime, OldBracketRot, LeftVDU.BracketEndRot);
}

void InitEventRotateInLeftVDU(TITLE_EVENT *TitleEvent)
{
	OldVDUrot = VDUrot;
	OldBracketRot = BracketRot;

	PlaySfx( SFX_VduOff, 0.8F );
}

void EventRotateInLeftVDU(TITLE_EVENT *TitleEvent)
{
	float currenttime;

	currenttime = GetEventCurrentTime(TitleEvent);

	RotateVDU2(currenttime, OldVDUrot, LeftVDU.StartRot);
	RotateBracket(currenttime, OldBracketRot, LeftVDU.BracketStartRot);
}


void InitEventDarkenRoom(TITLE_EVENT *TitleEvent)
{
	OldRoomDarkness = RoomDarkness;
}
void EventDarkenRoom(TITLE_EVENT *TitleEvent)
{
	float currenttime;

	currenttime = GetEventCurrentTime(TitleEvent);
	
	currenttime = 1.0F - currenttime;
	
	RoomDarkness = OldRoomDarkness * currenttime;
	
	DarkenRoom2(RoomDarkness);

}

void InitEventLightenRoom(TITLE_EVENT *TitleEvent)
{
	OldRoomDarkness = RoomDarkness;
}
void EventLightenRoom(TITLE_EVENT *TitleEvent)
{
	float currenttime;

	currenttime = GetEventCurrentTime(TitleEvent);
	
	RoomDarkness = ((1.0F - OldRoomDarkness) * currenttime) + OldRoomDarkness;
	
	DarkenRoom2(RoomDarkness);
}

void InitEventFadeOnHoloLight(TITLE_EVENT *TitleEvent)
{
	OldHoloLightBrightness = HoloLightBrightness;
#ifndef SOFTWARE_ENABLE
	Models[BackgroundModel[TITLE_MODEL_HoloLight]].Visible = 1;
#endif
}

void TriggerBikeSpeech( TITLE_EVENT *TitleEvent )
{
	static uint32 CurrentSpeechID = 0;

	if( MyGameStatus != STATUS_Title )
		return;

	if ( CurrentSpeechID )
		StopSfx( CurrentSpeechID );

	CurrentSpeechID = PlaySfx( SFX_BIKER_EX, 1.0F );
}

void FadeHoloLight(float Brightness )
{
	TintModelVertices( BackgroundModel[TITLE_MODEL_HoloLight], Brightness, NULL );
}

void EventFadeOnHoloLight(TITLE_EVENT *TitleEvent)
{
	float currenttime;

	currenttime = GetEventCurrentTime(TitleEvent);

	HoloLightBrightness = ((1.0F - OldHoloLightBrightness) * currenttime) + OldHoloLightBrightness;

	FadeHoloLight(HoloLightBrightness);
}

void ExitEventFadeOffHoloLight(TITLE_EVENT *TitleEvent)
{
}

void InitEventFadeOffHoloLight(TITLE_EVENT *TitleEvent)
{
	OldHoloLightBrightness = HoloLightBrightness;
	Models[BackgroundModel[TITLE_MODEL_HoloLight]].Visible = 0;
}

void EventFadeOffHoloLight(TITLE_EVENT *TitleEvent)
{
	float currenttime;

	currenttime = GetEventCurrentTime(TitleEvent);

	currenttime = 1.0F - currenttime;
	
	HoloLightBrightness = OldHoloLightBrightness * currenttime;

	FadeHoloLight(HoloLightBrightness);
}

void InitEventRaiseHoloPad(TITLE_EVENT *TitleEvent)
{
	OldHoloPadHeight = Models[BackgroundModel[TITLE_MODEL_Holopad]].Pos.y;
}

void EventRaiseHoloPad(TITLE_EVENT *TitleEvent)
{
	float currenttime, raiseby;

	currenttime = GetEventCurrentTime(TitleEvent);

	raiseby = ((Holopad.y - OldHoloPadHeight) * currenttime) + OldHoloPadHeight;
	
	Models[BackgroundModel[TITLE_MODEL_Holopad]].Pos.y = raiseby;


}

void ExitEventRaiseHolopad(TITLE_EVENT *TitleEvent)
{
}

void InitEventLowerHoloPad(TITLE_EVENT *TitleEvent)
{
	OldHoloPadHeight = Models[BackgroundModel[TITLE_MODEL_Holopad]].Pos.y;
	HolopadJudderReq = TRUE;
}

void EventLowerHoloPad(TITLE_EVENT *TitleEvent)
{
	float currenttime, raiseby;

	currenttime = GetEventCurrentTime(TitleEvent);

	currenttime = 1.0F - currenttime;
	
	raiseby = (currenttime * (OldHoloPadHeight - (Holopad.y - HolopadRange) ) ) + (Holopad.y - HolopadRange);
	
	Models[BackgroundModel[TITLE_MODEL_Holopad]].Pos.y = raiseby;
}

void InitEventJudderHoloPad(TITLE_EVENT *TitleEvent)
{
}

void EventJudderHoloPad(TITLE_EVENT *TitleEvent)
{
	float currenttime;

	
	if (HolopadJudderReq)
	{
		currenttime = GetEventCurrentTime(TitleEvent);

		if (currenttime <= 0.2F)
			Models[BackgroundModel[TITLE_MODEL_Holopad]].Pos.y = Holopad.y - 0.8F;

		if ((currenttime > 0.2F) && (currenttime <= 0.4F))
			Models[BackgroundModel[TITLE_MODEL_Holopad]].Pos.y = Holopad.y + 0.6F;

		if ((currenttime > 0.4F) && (currenttime <= 0.6F))
			Models[BackgroundModel[TITLE_MODEL_Holopad]].Pos.y = Holopad.y - 0.4F;

		if ((currenttime > 0.6F) && (currenttime <= 0.8F))
			Models[BackgroundModel[TITLE_MODEL_Holopad]].Pos.y = Holopad.y + 0.2F;

		if (currenttime > 0.8F)
			Models[BackgroundModel[TITLE_MODEL_Holopad]].Pos.y = Holopad.y;
	}

}

void ExitEventJudderHoloPad(TITLE_EVENT *TitleEvent)
{
	HolopadJudderReq = FALSE;
}


void InitEventDiscPanFromRightInit(TITLE_EVENT *TitleEvent)
{
	//InitEventGeneralPan(TitleEvent);
}

void EventDiscPanInit(TITLE_EVENT *TitleEvent)
{
	float currenttime;

	currenttime = GetEventCurrentTime(TitleEvent);

	SinPan2(OldLookPos, DiscLookPos ,&Look, OldViewPos, DiscViewPos, &View, currenttime);
}

void InitEventLowerStack( TITLE_EVENT *TitleEvent )
{
	PlaySfx( SFX_StackDown, 1.0F );
}

void EventLowerStack(TITLE_EVENT *TitleEvent)
{
	float currenttime;

	currenttime = GetEventCurrentTime(TitleEvent);

	currenttime = 1.0F - currenttime;

	currenttime = (float)SIND(currenttime * 90.0F);

	//RotateDiscStack((currenttime * (MaxStackTheta - MinStackTheta)) + MinStackTheta);
	RotateDiscStack (currenttime * MaxStackTheta);

}

void ExitEventLowerStack(TITLE_EVENT *TitleEvent)
{
}
 
void InitEventJudderStack(TITLE_EVENT *TitleEvent)
{
	StackJudderNum = 0;
	StackRotAmount = 0.0F;
	OldStackRotAmount = 0.0F;
}

void EventJudderStack(TITLE_EVENT *TitleEvent)
{
	int i;
	float currenttime, ReqRotAmount;
	float RotLookup[5] = {-2.0F, 2.0F, -1.0F, 1.0F, 0.0F};
	float start, end;

	currenttime = GetEventCurrentTime(TitleEvent);

	for (i=0; i<5; i++)
	{
		if ( (currenttime > (0.2F * (i + 1))) && (StackJudderNum == i))
		{
			OldStackRotAmount = StackRotAmount;
			StackJudderNum++;
		}
	}

	ReqRotAmount = RotLookup[StackJudderNum];

	start = 0.2F * StackJudderNum;
	end = 0.2F * (StackJudderNum + 1);
	
	currenttime = (currenttime - start) / (end - start);

	currenttime = (float)SIND(currenttime * 90.0F);

	StackRotAmount = ((ReqRotAmount - OldStackRotAmount) * currenttime) + OldStackRotAmount;

	RotateDiscStack(StackRotAmount);
}

void ExitEventDiscPanInit( TITLE_EVENT *TitleEvent )
{
	OKToProcessKeys = TRUE;
}

void InitEventExpandBike(TITLE_EVENT *TitleEvent)
{
	ShowHoloModel( HoloModelLookup[ BikeList.selected_item ] );
}

void InitEventExpandCrystal(TITLE_EVENT *TitleEvent)
{
	ShowHoloModel( TITLE_MODEL_Crystal );
}

void ExitEventExpandBike(TITLE_EVENT *TitleEvent)
{
	BikeExpanded = TRUE;
	
	if ( CurrentMenu != &MENU_NEW_ChangeBike )
		OldBikeSwapScale = BikeSwapScale;
}

void InitEventShrinkBike(TITLE_EVENT *TitleEvent)
{
	/*
	BikeExpanded = FALSE;
	
	KillLines();

	PlaySfx( SFX_HoloChange, 0.5F );
	*/

	ShowHoloModel( (uint16)-1 );
}

void ExitEventShrinkBike(TITLE_EVENT *TitleEvent)
{
	//KillBike();
	BikeRot += 180.0F;
}

void InitEventPlotBikeChar (TITLE_EVENT *TitleEvent)
{
#if 0
	LoadBikeChar();
	OldBikeCharAlpha = BikeCharAlpha;
#endif
}

void EventPlotBikeChar (TITLE_EVENT *TitleEvent)
{
	float currenttime;

	currenttime = GetEventCurrentTime(TitleEvent);
	BikeCharAlpha = ((1.0F - OldBikeCharAlpha) * currenttime) + OldBikeCharAlpha;
	FadeBikeChar(BikeCharAlpha);
}

void InitEventRemoveBikeChar (TITLE_EVENT *TitleEvent)
{
	OldBikeCharAlpha = BikeCharAlpha;
}

void EventRemoveBikeChar (TITLE_EVENT *TitleEvent)
{
	float currenttime;

	currenttime = GetEventCurrentTime(TitleEvent);

	currenttime = 1.0F - currenttime;

	BikeCharAlpha = OldBikeCharAlpha * currenttime;

	FadeBikeChar(BikeCharAlpha);
}

void ExitEventRemoveBikeChar (TITLE_EVENT *TitleEvent)
{
	KillBikeChar( NULL );
}

void InitStartDiscPanTimer (TITLE_EVENT_TIMER *TitleEventTimer)
{
	CameraStatus = CAMERA_AtDiscs;
	InitEventGeneralPan(NULL);
	
	TitleEventTimer->Status = TITLE_EVENT_TIMER_ACTIVE;
	TitleEventTimer->CurrentTime = 0.0F;
}

void InitGeneralTimer( TITLE_EVENT_TIMER *TitleEventTimer )
{
	TitleEventTimer->Status = TITLE_EVENT_TIMER_ACTIVE;
	TitleEventTimer->CurrentTime = 0.0F;
}

void InitRightDiscPanTimer(TITLE_EVENT_TIMER *TitleEventTimer)
{
	CameraStatus = CAMERA_AtDiscs;
	InitEventGeneralPan(NULL);

	TitleEventTimer->Status = TITLE_EVENT_TIMER_ACTIVE;
	TitleEventTimer->CurrentTime = 0.0F;

}

void InitLeftDiscPanTimer (TITLE_EVENT_TIMER *TitleEventTimer)
{
	CameraStatus = CAMERA_AtDiscs;
	InitEventGeneralPan(NULL);

	TitleEventTimer->Status = TITLE_EVENT_TIMER_ACTIVE;
	TitleEventTimer->CurrentTime = 0.0F;
}

void InitRightVDUPanTimer (TITLE_EVENT_TIMER *TitleEventTimer)
{
	CameraStatus = CAMERA_AtRightVDU;
	InitEventGeneralPan(NULL);
	VDU_Ready = FALSE;

	TitleEventTimer->Status = TITLE_EVENT_TIMER_ACTIVE;
	TitleEventTimer->CurrentTime = 0.0F;
}

void InitLeftVDUPanTimer (TITLE_EVENT_TIMER *TitleEventTimer)
{
	CameraStatus = CAMERA_AtLeftVDU;
	InitEventGeneralPan(NULL);
	VDU_Ready = FALSE;

	TitleEventTimer->Status = TITLE_EVENT_TIMER_ACTIVE;
	TitleEventTimer->CurrentTime = 0.0F;
}

void InitVisualsTimer (TITLE_EVENT_TIMER *TitleEventTimer)
{
	CameraStatus = CAMERA_AtRightVDU;
	InitEventGeneralPan(NULL);
	VDU_Ready = FALSE;
	PlaySfx( SFX_TitlePan, 1.0F );

	TitleEventTimer->Status = TITLE_EVENT_TIMER_ACTIVE;
	TitleEventTimer->CurrentTime = 0.0F;
}

void ChooseDiscTimer (TITLE_EVENT_TIMER *TitleEventTimer)
{
	switch (OldMenuStatus)
	{
	case TITLE_TIMER_NULL:
		InitStartDiscPanTimer(&Title_Timers[TITLE_TIMER_PanToDiscsInit]);
		break;
	case TITLE_TIMER_PanToRightVDU:
		InitRightDiscPanTimer(&Title_Timers[TITLE_TIMER_PanToDiscsFromRight]);
		break;
	case TITLE_TIMER_PanToLeftVDU:
		InitLeftDiscPanTimer(&Title_Timers[TITLE_TIMER_PanToDiscsFromLeft]);
		break;
	case TITLE_TIMER_Visuals:
		InitStartDiscPanTimer(&Title_Timers[TITLE_TIMER_PanToDiscsFromVisuals]);
		break;
	case TITLE_TIMER_NormalPanToRightVDU:
		InitStartDiscPanTimer(&Title_Timers[TITLE_TIMER_NormalPanToDiscsFromRight]);
		break;
	default:
		InitStartDiscPanTimer(&Title_Timers[TITLE_TIMER_PanToDiscsInit]);
		break;
	}

	TitleEventTimer->Status = TITLE_EVENT_TIMER_AWAITINGRESET;
}

void ResetAllEvents(void)
{
	TITLE_EVENT *Event;
	TITLE_EVENT_TIMER *Timer;

	for (Event = Title_Events; Event->TriggeredBy >= 0; Event++)
	{
		if ((Event->Status == TITLE_EVENT_STATUS_ACTIVE) || (Event->Status == TITLE_EVENT_STATUS_FINISHED))
		{
			if (Event->ExitFunc)
				Event->ExitFunc(Event);

			Event->Status = TITLE_EVENT_STATUS_IDLE;
		}
	}
	
	for (Timer = Title_Timers; Timer->Interval >= 0; Timer++)
	{
		Timer->Status = TITLE_EVENT_TIMER_IDLE;
	}

} 


void ProcessEvents(void)
{
	
	TITLE_EVENT *Event;
	TITLE_EVENT_TIMER Timer;

	for (Event = Title_Events; Event->TriggeredBy >= 0; Event++)
	{
		Timer = Title_Timers[Event->TriggeredBy];

		if (Event->Status == TITLE_EVENT_STATUS_IDLE)
		{
			if ((Timer.Status == TITLE_EVENT_TIMER_ACTIVE) || (Timer.Status == TITLE_EVENT_TIMER_FINISHED))
			{
				if (Timer.CurrentTime >= Event->StartTime)
				{
					if (Event->InitFunc)
						Event->InitFunc (Event);

					Event->Status = TITLE_EVENT_STATUS_ACTIVE;
				}
			}	
		}

		if (Event->Status == TITLE_EVENT_STATUS_ACTIVE)
		{
			if (Event->ProcessFunc)
				Event->ProcessFunc (Event);		// if timer is > than end time, process fn will take timer as exactly end time
			if (Timer.CurrentTime >= Event->EndTime)
			{
				if (Event->ExitFunc)
					Event->ExitFunc (Event);
				Event->Status = TITLE_EVENT_STATUS_FINISHED;
			}
		}

		if (Event->Status == TITLE_EVENT_STATUS_FINISHED)
		{
			if (Timer.Status == TITLE_EVENT_TIMER_FINISHED)
			{
				Event->Status = TITLE_EVENT_STATUS_IDLE;
			}
		}

	}

}

void ProcessTimers(void)
{
	TITLE_EVENT_TIMER *Timer;

	// ignore first few framelags - they are invariably huge
	if ( FramesIgnored < 3 )
	{
	 	FramesIgnored++;
		return;
	}

	for (Timer = Title_Timers; Timer->Interval >= 0; Timer++)
	{
		switch (Timer->Status)
		{
		case TITLE_EVENT_TIMER_ACTIVE:
			Timer->CurrentTime += framelag/(Timer->Interval * 60.0F);
			if (Timer->CurrentTime >= 1.0F)
				Timer->Status = TITLE_EVENT_TIMER_FINISHED;
			break;
		case TITLE_EVENT_TIMER_FINISHED:
			Timer->Status = TITLE_EVENT_TIMER_AWAITINGRESET;

		}
	}
}
							   
void DrawHighlightBox(TEXTINFO *TextInfo, uint8 r, uint8 g, uint8 b)
{
	float xmin, ymin, xmax, ymax, widthX, widthY, height, length, templength, actuallength;
	int i, font;
	font = GetScreenFont(TextInfo->font);

	widthX = (float)ceil(ModeScaleX[ModeCase]);
	widthY = (float)ceil(ModeScaleY[ModeCase]);

	height = 0.0F;
	length = 0.0F;
	actuallength = 0.0F;
	templength = 0.0F;
	for (i = 0; i < TextInfo->num_lines; i++)
	{
		height += TextInfo->height[i];
		
		if (TextInfo->currentx[i] > length)
			length = TextInfo->currentx[i];

		if (TextInfo->length[i] > actuallength)
			actuallength = TextInfo->length[i];
	}

	length += 2.0F * ModeScaleX[ModeCase];
	if (length > actuallength)
		length = actuallength;
	
	//xmin = (float)(TextInfo->xmin + VDUoffsetX) * ModeScaleX[ModeCase];
	xmin = TextInfo->char1x - widthX;
	xmax = xmin + length + widthX * 2.0F;
	ymin = TextInfo->text_y_min - widthY;
	ymax = TextInfo->text_y_max + widthY;

	PlotHighlightPoly (xmin, ymin - widthY, xmax, ymin, r, g, b); //top
	PlotHighlightPoly (xmin, ymax, xmax, ymax + widthY, r, g, b); //bottom
	PlotHighlightPoly (xmin - widthX, ymin - widthY, xmin, ymax + widthY, r, g, b); //left

	if (actuallength == length)
		PlotHighlightPoly (xmax, ymin - widthY, xmax + widthX, ymax + widthY, r, g, b); //right
}

uint16 PlotHighlightPoly (float xmin, float ymin, float xmax, float ymax, uint8 r, uint8 g, uint8 b)
{
	uint16 poly;
	
	poly =FindFreeScrPoly();

	ScrPolys[poly].Flags = SCRFLAG_UseCoords;
	ScrPolys[poly].Type = SCRTYPE_LastAFrame;
	ScrPolys[poly].Frm_Info = NULL;
	ScrPolys[poly].Frame = 238.0F;
	ScrPolys[poly].x1 = xmin;
	ScrPolys[poly].y1 = ymin;	
	ScrPolys[poly].x3 = xmax;					
	ScrPolys[poly].y3 = ymax;					

	ScrPolys[poly].Col1.R = r;
	ScrPolys[poly].Col1.G = g;
	ScrPolys[poly].Col1.B = b;
	ScrPolys[poly].Col1.Trans = 255;
	ScrPolys[poly].Col2.R = r;
	ScrPolys[poly].Col2.G = g;
	ScrPolys[poly].Col2.B = b;
	ScrPolys[poly].Col2.Trans = 255;
	ScrPolys[poly].Col3.R = r;
	ScrPolys[poly].Col3.G = g;
	ScrPolys[poly].Col3.B = b;
	ScrPolys[poly].Col3.Trans = 255;
	ScrPolys[poly].Col4.R = r;
	ScrPolys[poly].Col4.G = g;
	ScrPolys[poly].Col4.B = b;
	ScrPolys[poly].Col4.Trans = 255;

	AddScrPolyToTPage( poly, GetTPage( NULL, 0 ) );

	return poly;
}

void SelectConnectionToStart (MENUITEM *Item)
{
	if( !ExitProviderChosen( Item ) )
		return;
	MenuState = MENUSTATE_Select;
	MenuChange ( &MENU_ITEM_StartMultiplayer );
}

void SelectConnectionToStartServer (MENUITEM *Item)
{
	if( !ExitProviderChosen( Item ) )
		return;
	MenuState = MENUSTATE_Select;

	/*
	if ( ServerChoosesGameType )
		MenuChangeEx( &MENU_NEW_CreateGameServerChooses );
	else
		MenuChangeEx( &MENU_NEW_CreateGameServer );
	*/
	MenuChangeEx( &MENU_NEW_ChooseServerGameType );
}

void StartAManualServer( MENUITEM *Item )
{
	ServerChoosesGameType = TRUE;
	MenuChangeEx( &MENU_NEW_CreateGameServerChooses );
}

void StartAnAutoServer( MENUITEM *Item )
{
	ServerChoosesGameType = FALSE;
	MenuChangeEx( &MENU_NEW_CreateGameServer );
}


void SelectConnectionToJoin (MENUITEM *Item)
{
	if( !ExitProviderChosen( Item ) )
		return;
	MenuChange ( &MENU_ITEM_JoinMultiplayer );
}


void UpdateSessions ( int *dummy )
{
	/*
	BOOL found;
	int i, j;
	MENUITEM item;
	static float pause = 30.0F;
	*/
	
	GetPlayersInCurrentSession ( NULL );
/*
	// find out whether to start game if lobby launched....
	if ( IsLobbyLaunched && IsHost )
	{
		pause -= framelag;
		if ( pause < 0.0F )
		{
			pause = 30.0F ;

			// enumerate players
				  
			NumLobbyPlayers = 0;
			DPlayEnumPlayers( NULL, EnumLobbyPlayers, (LPVOID) NULL, 0);
			DebugPrintf("num players found %d\n", NumLobbyPlayers );
   			
			found = TRUE;
			for ( i = 0; i < MAX_PLAYERS; i++ )
			{
				if ( !LobbyPlayerIDs[ i ] )
				{
					continue;
				}

				found = FALSE;
				for ( j = 0; j < NumLobbyPlayers; j++ )
				{
					if ( LobbyPlayerIDs[ i ] == Ships[ j ].dcoID )
					{
						found = TRUE;
						DebugPrintf("player %x found\n", LobbyPlayerIDs[ i ] );
						break;
					}
				}

				if ( !found )
				{
					return;
				}
			}
			
			memset( &item, 0, sizeof( MENUITEM ) );
			item.Value = &MENU_NEW_GeneralLoading;

			HostAboutToStart( &item );
		}

	}
*/
}

void GetInitialSessions ( MENU *menu )
{
	if ( IsLobbyLaunched )
		NoMenuBack = TRUE;
	
	NumOfPlayersSlider.oldvalue = -1;
	PlayersList.display_items = 16;
	GetPlayersInCurrentSession ( NULL );

	InitTitleMessaging();
}

void SetSessionJoinFlag( MENUITEM *Item )
{
	OKToJoinSession = TRUE;
}

void InitMySessionsList(void)
{									
	
	MySessionsList.display_items = 8;

	MySessionsList.top_item = 0;
	MySessionsList.selected_item = -1;
	MySessionsList.old_top_item = 0;
	MySessionsList.old_selected_item = -1;

	MySessionsList.FuncInfo = UpdateSessionInfo;
		
	OKToJoinSession = FALSE;

	// init ping list...
//	SessionPingList = MySessionsList;
//	SessionPingList.FuncInfo = NULL;
}

void CopySessionsList(int *dummy)
{									
	int i;
	char *pchLevelNameSeperator;

	for (i = 0; i < SessionsList.items; i++)
	{
		strncpy( MySessionsList.item[ i ] , SessionsList.item[ i ] , sizeof( MySessionsList.item[ i ] )  );

		// truncate at '~' ( rest is level name )
		pchLevelNameSeperator = strchr( MySessionsList.item[ i ], '~' );
		if ( pchLevelNameSeperator )
		{
			*pchLevelNameSeperator = 0;
		}
	}

	MySessionsList.items = SessionsList.items;
//	SessionPingList.items = SessionsList.items;

	if ( MySessionsList.selected_item >= SessionsList.items )
		MySessionsList.selected_item = SessionsList.items - 1;

	SessionsList.selected_item = MySessionsList.selected_item;
}

void GetMyCurrentSessions(MENU *Menu)
{
	if ( !InitLevels( MULTIPLAYER_LEVELS ) && !InitLevels( DEFAULT_LEVELS ) )
	{
		//Msg( "No multiplayer levels" );
		PrintErrorMessage (LT_NoLevelsInstalled, 1, NULL, ERROR_USE_MENUFUNCS );
		return;
	}
	InitMySessionsList();
	GetCurrentSessions( Menu );
#ifdef SHAREWARE
	LogosEnable = 0;
#endif
}

void SendTitleMessage(MENUITEM *Item)
{
	TEXT *text;
	TEXTMSG TextMsg;

	text = (TEXT *)Item->Variable;
   	
	strncpy( &MacroText4.text[0], &text->text[0], MAXTEXTMSG );
	MacroText4.text[ MAXTEXTMSG - 1 ] = 0;
	SendGameMessage(MSG_TEXTMSG, 0, 0, TEXTMSGTYPE_TitleMessage, 0);

	strcpy ( &TextMsg.Text[0], &MacroText4.text[0] );
	TextMsg.WhoIAm = WhoIAm;
	AddTitleMessage(&TextMsg);

	TextClear( &TitlePlayerMessage );
	GetVduTextFormattingInfo ( &TitlePlayerMessage );
}

void AddTitleMessage(LPTEXTMSG lpTextMsg)
{
	char tempname[8];
	char tempbuf[ 256 ];
	
	if (TotalTitleMsgs != MAX_TITLE_MSGS)
	{
		if (WhoIAm == lpTextMsg->WhoIAm)
		{
		 	strncpy( tempname, &biker_name[0], 7 );
			tempname[7] = 0;
			sprintf( tempbuf ,"%s: %s", tempname,  &lpTextMsg->Text[0] );
			strncpy( TitleMsgQue[TitleMsgQueStart].text, tempbuf, MAX_TITLE_MSG_SIZE );
			TitleMsgQue[TitleMsgQueStart].text[ MAX_TITLE_MSG_SIZE - 1 ] = 0;
		}
		else
		{
			sprintf( tempbuf,"%s: %s", &Names[lpTextMsg->WhoIAm][0],  &lpTextMsg->Text[0] );
			strncpy( TitleMsgQue[TitleMsgQueStart].text, tempbuf, MAX_TITLE_MSG_SIZE );
			TitleMsgQue[TitleMsgQueStart].text[ MAX_TITLE_MSG_SIZE - 1 ] = 0;
		}
		TitleMsgQue[TitleMsgQueStart].timer = MAX_TITLE_MSG_TIME;
		TitleMsgQueStart++;
		TotalTitleMsgs++;
		if (TitleMsgQueStart == MAX_TITLE_MSGS)
			TitleMsgQueStart = 0;
	}
}

void GetTitleMessage(void)
{
 	MENUITEM *Item;
	TEXTINFO dummytext;
	int i, j;
	
	TitleMessageTimer -= framelag;
	if (TitleMessageTimer < 0.0F)
	{
		TitleMessageTimer = 0.0F;
		if (TotalTitleMsgs > 0)
		{
			dummytext.xmin = 5;
			dummytext.ymin = 0;						
			dummytext.xmax = 200;					  
			dummytext.ymax = 16;						
			dummytext.font = FONT_Small;				   
			dummytext.flags = TEXTFLAG_ForceFit;						
			dummytext.num_lines = 0;				
			dummytext.boxdone = FALSE;					
			dummytext.num_pointers_to_free = 0;		
			dummytext.force_fit = FALSE;
			dummytext.text = &TitleMsgQue[TitleMsgQueEnd].text[0];
			PrintTextItem( &dummytext );

			for (i = 0; i < dummytext.num_lines; i++)
			{

				j = TITLE_TEXT_MSGS_STORED;
				while (--j)
				{
					strcpy( TitleMessage[j], TitleMessage[j - 1] );
				}
				
				strncpy( &TitleMessage[0][0], &dummytext.text[dummytext.startpoint[i]], dummytext.endpoint[i] - dummytext.startpoint[i] + 1);
				TitleMessage[0][dummytext.endpoint[i] - dummytext.startpoint[i] + 1] = '\0';
			}
			TitleMsgQueEnd++;
			TitleMessageTimer = MAX_TITLE_MSG_TIME;

			TotalTitleMsgs--;
			if (TitleMsgQueEnd == MAX_TITLE_MSGS)
				TitleMsgQueEnd = 0;

			for( Item = CurrentMenu->Item ; Item->x >= 0 ; Item++ )
			{	
				if (Item->Variable)
				{
					for (i = 0; i < MAX_TITLE_MSG_TIME; i++)
					{
						if (Item->Variable == TitleMessage[i])
							PrintTextItem(Item->TextInfo[0]);
					}
				}
			}
		}
	}
}

// type - whether or not to execute exit/entry functions of menus passed through
// NewMenu - new menu to go into after stepping back (can be NULL)
void PrintErrorMessage (char *ErrorStr, int BackBy, MENU *NewMenu, int type)
{
	MENUITEM ChangeItem;

	MenuState = MENUSTATE_Select;

	// make sure message will be displayed on VDU...
	if ((CameraStatus != CAMERA_AtLeftVDU) && (CameraStatus != CAMERA_AtRightVDU))
		MENU_NEW_Error.MenuStatus = TITLE_TIMER_NormalPanToRightVDU;
	else
		MENU_NEW_Error.MenuStatus = CurrentMenu->MenuStatus;

	strcpy (ErrorMessage, ErrorStr);
	if ( !( type & ERROR_OVERIDE_LOBBY_QUIT ) && ( ( QuickStart == QUICKSTART_SelectSession ) || IsLobbyLaunched || ( type & ERROR_QUIT ) ) )
		ErrorMoveBackBy = -1;
	else
		ErrorMoveBackBy = BackBy;

	ErrorNewMenu = NewMenu;

	if (type & ERROR_DONTUSE_MENUFUNCS)
		IgnoreMenuFuncs = TRUE;
	else
		IgnoreMenuFuncs = TRUE;
	
	ChangeItem.Value = &MENU_NEW_Error;
	MenuChange( &ChangeItem );
}

void MenuItemBackFromError ( MENUITEM *Item )
{
	MENUITEM ChangeItem;
	int i;

	if ( ErrorMoveBackBy < 0 )
	{
		LastMenu = CurrentMenu;
		VduClear();
		MyGameStatus = STATUS_QuittingFromTitles;
		return;
	}

	MenuBack();
	CheckMenuTimer();
	for (i = 0; i < ErrorMoveBackBy; i++)
	{
		if ( CurrentMenu != &MENU_Start )
		{
			MenuBack();
			CheckMenuTimer();
		}
	}

	if (ErrorNewMenu)
	{
		ChangeItem.Value = ErrorNewMenu;
		MenuChange( &ChangeItem );
	}

	IgnoreMenuFuncs = FALSE;


}

void SelectConfigureAxisMenu ( MENUITEM *Item )
{
	if ( !_stricmp( JoystickList.item[ JoystickList.selected_item ], "Spacetec SpaceOrb 360" ) 
		&& !SpaceOrbSetup )
	{
		// do not allow axis setup
		PrintErrorMessage (LT_SpaceOrb/*"You must use spaceware to set up the spaceball axis"*/, 0, NULL, ERROR_DONTUSE_MENUFUNCS);
	}else
	{
		MenuChange( &AxisScreenItem );
	}
}

void InitJoystickList ( MENU *Menu )
{
	int i, j;
	BOOL jsfound = FALSE;

	// if no joysticks connected, display error message & return to last menu...
	for (i = 0; i < Num_Joysticks; i++)
	{
		if (JoystickInfo[i].connected)
		{
			jsfound = TRUE;
			break;
		}
	}

	if (!jsfound)
	{	PrintErrorMessage (LT_NoJoysticks/*"No Joysticks Connected~~(you cannot connect a joystick while the game is running)"*/, 1, NULL, ERROR_DONTUSE_MENUFUNCS);
		return;
	}

	JoystickList.items = 0;
	JoystickList.display_items = 3;
	JoystickList.top_item = 0;
	JoystickMap[JoystickList.selected_item] = 0;

	j = 0;
	for (i = 0; i < Num_Joysticks; i++)
	{
		if ( JoystickInfo[i].connected )
		{
			strncpy( JoystickList.item[j], JoystickInfo[i].Name, sizeof(JoystickList.item[0]));
			JoystickList.items++;
			JoystickMap[j] = i;
			j++;
		}
	}

}

void InitJoystickButtonConfig ( MENU *Menu )
{
	strncpy( JoystickBtnText, NoBtnText, sizeof(JoystickBtnText) );
	strncpy( JoystickModeText, JoyMode1, sizeof(JoystickModeText) );
	JoystickConfigState = JOYCONFIG_SelectAction;
}

void InitJoystickPOVConfig ( MENU *Menu )
{
	strncpy( JoystickPOVText, NoPOVText, sizeof(JoystickBtnText) );
	strcpy( JoystickPOVDirectionText, "" );
	strncpy( SelectedActionText, ShipActionList.item[0], sizeof(SelectedActionText) );
	CurrentJoyPOV = -1;
	CurrentJoyPOVDirection = -1;

	AxisExtremeLeftText[0] = 0;
	AxisExtremeRightText[0] = 0;
}


void InitJoystickAxisConfig ( MENU *Menu)
{
	int i, j;
//	float mid;
	SCRPOLY_RGB light, dark, polycol[NUM_SHIP_AXIS_ACTIONS][2];
	float sensitivity;

	light.R = 64;
	light.G = 255;
	light.B = 64;
	light.Trans = 0;
	dark.R = 0;
	dark.G = 0;
	dark.B = 0;
	dark.Trans = 0;

	polycol[0][0] = dark;
	polycol[0][1] = light;

	polycol[1][0] = light;
	polycol[1][1] = dark;


	JoystickAxisList.items = 0;
	JoystickAxisList.display_items = 1;
	JoystickAxisList.top_item = 0;
	JoystickAxisList.selected_item = 0;

	j = 0;
	for (i = 0; i < MAX_JOYSTICK_AXIS; i++)
	{
		if (JoystickInfo[JoystickMap[JoystickList.selected_item]].Axis[i].exists)
		{
			strncpy( JoystickAxisList.item[j], JoystickInfo[JoystickMap[JoystickList.selected_item]].Axis[i].name, sizeof(JoystickList.item[0]));
			JoystickAxisList.items++;
			AxisMap[j] = i;
			j++;
		}
	}

	for (i = 0; i < NUM_SHIP_AXIS_ACTIONS; i++)
	{
		if (JoystickInfo[JoystickMap[JoystickList.selected_item]].Axis[AxisMap[0]].action == ShipAxisLookup[i])
		{
			AxisActionList.selected_item = i;
			break;
		}
	}
	
	AxisSlider.min = 0;
	AxisSlider.max = JoystickAxisList.items - 1;
	AxisSlider.step = 1;
	AxisSlider.value = JoystickAxisList.selected_item;
	AxisSlider.FuncUser = AxisName;
	AxisSlider.FuncSet = SetAxisSlider;

	AxisActionSlider.min = 0;
	AxisActionSlider.max = AxisActionList.items - 1;
	AxisActionSlider.step = 1;
	AxisActionSlider.value = AxisActionList.selected_item;
	AxisActionSlider.FuncUser = AxisActionName;
	AxisActionSlider.FuncSet = SetAxisActionSlider;

	AxisInvert = JoystickInfo[JoystickMap[JoystickList.selected_item]].Axis[AxisMap[0]].inverted; 
	FineControl = JoystickInfo[JoystickMap[JoystickList.selected_item]].Axis[AxisMap[0]].fine; 
	DeadzoneSlider.value = JoystickInfo[JoystickMap[JoystickList.selected_item]].Axis[AxisMap[0]].deadzone; 
	sensitivity = JoystickInfo[JoystickMap[JoystickList.selected_item]].Axis[AxisMap[0]].sensitivity;
	SensitivitySlider.value =
		( sensitivity < 1.0F ) ? (int) floor( 0.49F + ( 100 * sensitivity - 1 ) / sensitivity ) : 100;

	// set up axis test scrpolys
	for (i = 0; i < NUM_AXIS_TEST_SCRPOLYS; i++)
	{
		AxisTestScrPoly[i] = FindFreeScrPoly();

		if (AxisTestScrPoly[i] == (uint16)-1)
		{
			Msg("Title.c: InitJoystickAxisConfig() unable to allocate screen poly\n");
			exit(1);
		}

		ScrPolys[AxisTestScrPoly[i]].Type = SCRTYPE_Normal;
		ScrPolys[AxisTestScrPoly[i]].Flags = SCRFLAG_UseCoords;
		ScrPolys[AxisTestScrPoly[i]].Type = SCRTYPE_Normal;

		ScrPolys[AxisTestScrPoly[i]].Col1 = polycol[i][0];
		ScrPolys[AxisTestScrPoly[i]].Col2 = polycol[i][1];
		ScrPolys[AxisTestScrPoly[i]].Col3 = polycol[i][1];
		ScrPolys[AxisTestScrPoly[i]].Col4 = polycol[i][0];

		ScrPolys[AxisTestScrPoly[i]].Frm_Info = NULL;
		AddScrPolyToTPage( AxisTestScrPoly[i], GetTPage( NULL, 0 ) );
	}

	AxisPtr_mid = (AXISTEST_XPos + AXISTEST_Width / 2.0F) + VDUoffsetX;
	AxisPtr_mid *= ModeScaleX[ModeCase];
//	mid = (AXISTEST_XPos + AXISTEST_Width / 2.0F); 
	
//	AxisPtr_xmin = mid - AXISTEST_PtrWidth / 2.0F + VDUoffsetX;
//	AxisPtr_xmax = mid + AXISTEST_PtrWidth / 2.0F + VDUoffsetX;
	AxisPtr_ymin = AXISTEST_YPos + VDUoffsetY;
	AxisPtr_ymax = AXISTEST_YPos + AXISTEST_Height + VDUoffsetY;

	AxisPtr_xmin *= ModeScaleX[ModeCase];
	AxisPtr_xmax *= ModeScaleX[ModeCase];
	AxisPtr_ymin *= ModeScaleY[ModeCase];
	AxisPtr_ymax *= ModeScaleY[ModeCase];
	
	UpdateAxisPtr( 0.0F );	// 0 = centered

}

// deltaX = -1 is fully left
// deltaX = +1 is fully right
void UpdateAxisPtr( float pos )
{
	float distance, dx, xmin[2], xmax[2];
	SCRPOLY_RGB light, dark, polycol[NUM_SHIP_AXIS_ACTIONS][2];
	int i;
	
	light.R = 64;
	light.G = 255;
	light.B = 64;
	light.Trans = 0;
	dark.R = 0;
	dark.G = 0;
	dark.B = 0;
	dark.Trans = 0;

	distance = (AXISTEST_Width / 2.0F) * ModeScaleX[ModeCase];
	
	if ( pos < -1.0F )
		pos = -1.0F;
	else if ( pos > 1.0F )
		pos = 1.0F;
	dx = pos * distance;

	if ( pos > 0.01F )
	{
		// right of centre
		polycol[0][0] = dark;
		polycol[0][1] = ( pos < 0.99F ) ? dark : light;
		polycol[1][0] = light;
		polycol[1][1] = dark;
	}
	else if ( pos < -0.01F )
	{
		// left of centre
		polycol[0][0] = dark;
		polycol[0][1] = light;
		polycol[1][0] = ( pos > -0.99F ) ? dark : light;
		polycol[1][1] = dark;
	}
	else
	{
		// in centre
		polycol[0][0] = dark;
		polycol[0][1] = light;
		polycol[1][0] = light;
		polycol[1][1] = dark;
	}

	xmin[0] = AxisPtr_mid - AXISTEST_PtrWidth;
	xmax[0] = AxisPtr_mid;
	xmin[1] = AxisPtr_mid;
	xmax[1] = AxisPtr_mid + AXISTEST_PtrWidth;

	for (i = 0; i < 2; i++)
	{
		ScrPolys[AxisTestScrPoly[i]].x1 = xmin[i] + dx;
		ScrPolys[AxisTestScrPoly[i]].y1 = AxisPtr_ymin;	
		ScrPolys[AxisTestScrPoly[i]].x2 = xmin[i] + dx;
		ScrPolys[AxisTestScrPoly[i]].y2 = AxisPtr_ymax;
		ScrPolys[AxisTestScrPoly[i]].x3 = xmax[i] + dx;	
		ScrPolys[AxisTestScrPoly[i]].y3 = AxisPtr_ymax;
		ScrPolys[AxisTestScrPoly[i]].x4 = xmax[i] + dx;					
		ScrPolys[AxisTestScrPoly[i]].y4 = AxisPtr_ymin;
		ScrPolys[AxisTestScrPoly[i]].Col1 = polycol[i][0];
		ScrPolys[AxisTestScrPoly[i]].Col2 = polycol[i][1];
		ScrPolys[AxisTestScrPoly[i]].Col3 = polycol[i][1];
		ScrPolys[AxisTestScrPoly[i]].Col4 = polycol[i][0];
	}
}

void ChooseJoyAxis( MENUITEM *Item )
{
	int i, joystick, axis, action;
	MENUITEM *ToggleItem, *SliderItem, *CheckItem, *AxisActionItem, *SensitivityItem, *FineItem;
	float sensitivity;

	joystick = JoystickMap[JoystickList.selected_item];
	axis = AxisMap[JoystickAxisList.selected_item];
	
	action = JoystickInfo[joystick].Axis[axis].action;

	AxisActionList.selected_item = 0;
	for (i = 0; i < NUM_SHIP_AXIS_ACTIONS; i++)
	{
		if (action == ShipAxisLookup[i])
		{
			AxisActionList.selected_item = i;
			break;
		}
	}
	AxisActionSlider.value = AxisActionList.selected_item;

	// find toggle & slider items...
	for( CheckItem = CurrentMenu->Item ; CheckItem->x >= 0 ; CheckItem++ )
	{  
		if ( CheckItem->Variable == &AxisInvert) 
			ToggleItem = CheckItem;

		if ( CheckItem->Variable == &DeadzoneSlider) 
			SliderItem = CheckItem;

		if ( CheckItem->Variable == &AxisActionSlider )
			AxisActionItem = CheckItem;

		if ( CheckItem->Variable == &SensitivitySlider) 
			SensitivityItem = CheckItem;

		if ( CheckItem->Variable == &FineControl )
			FineItem = CheckItem;
	}

	// set toggle...
	if (AxisInvert != JoystickInfo[JoystickMap[JoystickList.selected_item]].Axis[axis].inverted)
	{
		AxisInvert = !AxisInvert;
		DrawFlatToggleStatus( ToggleItem );
	}

	if ( FineControl != JoystickInfo[JoystickMap[JoystickList.selected_item]].Axis[axis].fine)
	{
		FineControl = !FineControl;
		DrawFlatToggleStatus( FineItem );
	}

	// set deadzone...
	DeadzoneSlider.oldvalue = DeadzoneSlider.value;
	DeadzoneSlider.value = JoystickInfo[JoystickMap[JoystickList.selected_item]].Axis[axis].deadzone; 
	RedrawFlatMenuSlider( SliderItem );

	RedrawFlatMenuSlider( AxisActionItem );

	sensitivity = JoystickInfo[JoystickMap[JoystickList.selected_item]].Axis[ axis ].sensitivity;
	SensitivitySlider.oldvalue = SensitivitySlider.value;
	SensitivitySlider.value =
		( sensitivity < 1.0F ) ? (int) floor( 0.49F + ( 100 * sensitivity - 1 ) / sensitivity ) : 100;
	RedrawFlatMenuSlider( SensitivityItem );

	LastMenu = CurrentMenu;
	VduClear();
	ProcessVduItems( &MENU_NEW_ConfigJoyAxis );
}

void InitShipActionList( void )
{
	int i;

	ShipActionList.items = 0;
	ShipActionList.display_items = 28;
	ShipActionList.top_item = 0;
	ShipActionList.selected_item = 0;
	for (i = 0; i < NUM_SHIP_ACTIONS; i++)
	{
		strncpy( ShipActionList.item[i], ShipActionText[i], sizeof( ShipActionList.item[0] ) );
		ShipActionList.items++;
	}

	AxisActionList.items = 0;
	AxisActionList.display_items = 7;
	AxisActionList.top_item = 0;
	AxisActionList.selected_item = 0;
	for (i = 0; i < NUM_SHIP_AXIS_ACTIONS; i++)
	{
		strncpy( AxisActionList.item[i], ShipAxisText[i], sizeof( AxisActionList.item[0] ) );
		AxisActionList.items++;
	}
}

void AssignShipActionToJoyBtn( MENUITEM *Item)
{
	JoystickConfigState = JOYCONFIG_AssignButton;
	// make highlight box static...
	CurrentListItem->TextInfo[ShipActionList.selected_item]->highlighttype = HIGHLIGHT_Static;
	CurrentList->Static = TRUE;

}

void AssignShipActionToJoyPOV( MENUITEM *Item)
{
	if ((CurrentJoyPOV != -1) && (CurrentJoyPOVDirection != -1))
	{
  		JoystickInfo[JoystickMap[JoystickList.selected_item]].POV[CurrentJoyPOV].action[CurrentJoyPOVDirection] = ShipActionList.selected_item;
  		strncpy( SelectedActionText, ShipActionList.item[ShipActionList.selected_item], sizeof(SelectedActionText) );
	}
}

void AssignShipActionToJoyAxis( MENUITEM *Item)
{
	int axis;
	
	axis = AxisMap[JoystickAxisList.selected_item];

	JoystickInfo[JoystickMap[JoystickList.selected_item]].Axis[axis].action = ShipAxisLookup[AxisActionList.selected_item];
}

void SetAxis( MENU *Menu )
{
	int i;
	
	SetUpJoystickAxis(JoystickMap[JoystickList.selected_item]);

	// remove axistest scrpoly...
	for( i = 0; i < NUM_AXIS_TEST_SCRPOLYS; i++ )
		KillUsedScrPoly(AxisTestScrPoly[i]);
}

void SetAxisInv( MENUITEM *Item )
{
	int axis;

	axis = AxisMap[JoystickAxisList.selected_item];
	JoystickInfo[JoystickMap[JoystickList.selected_item]].Axis[axis].inverted = !(JoystickInfo[JoystickMap[JoystickList.selected_item]].Axis[axis].inverted);
}

void SetAxisFineControl( MENUITEM *Item )
{
	int axis;

	axis = AxisMap[JoystickAxisList.selected_item];
	JoystickInfo[JoystickMap[JoystickList.selected_item]].Axis[axis].fine = !(JoystickInfo[JoystickMap[JoystickList.selected_item]].Axis[axis].fine);
}

void SetAxisDeadzone( MENUITEM *Item )
{
	int axis;

	axis = AxisMap[JoystickAxisList.selected_item];
	JoystickInfo[JoystickMap[JoystickList.selected_item]].Axis[axis].deadzone = DeadzoneSlider.value;

	SetUpJoystickAxis(JoystickMap[JoystickList.selected_item]);
}

void SetAxisSensitivity( MENUITEM *Item )
{
	int axis;

	axis = AxisMap[JoystickAxisList.selected_item];
	JoystickInfo[JoystickMap[JoystickList.selected_item]].Axis[axis].sensitivity =
		( SensitivitySlider.value < 100 ) ?	1.0F / ( 100 - SensitivitySlider.value ) : 1.0F;
}

void CheckJoyBtns( int *dummy )
{
	int i, j, num_buttons, num_POVs, joystick_num, multidir, dir;
	int button_found = 0;
	BOOL assigned = FALSE;

	if (!CurrentList || !CurrentListItem)
		return;

	if (CurrentList->Static == FALSE)
	{	JoystickConfigState = JOYCONFIG_SelectAction;
		CurrentListItem->TextInfo[CurrentList->selected_item]->highlighttype = HIGHLIGHT_Pulsing;		
	}

	joystick_num = JoystickMap[JoystickList.selected_item];
	num_buttons = JoystickInfo[joystick_num].NumButtons;
	num_POVs = JoystickInfo[joystick_num].NumPOVs;

	for (i = 0; i < num_buttons; i++)
	{
		if ( js[ new_input ][joystick_num].rgbButtons[i] & 0x80 )
		{
			assigned = TRUE;
			switch (JoystickConfigState)
			{
			case JOYCONFIG_SelectAction:
				ShipActionList.selected_item = JoystickInfo[joystick_num].Button[i].action;
				break;
			case JOYCONFIG_AssignButton:
	  			JoystickInfo[joystick_num].Button[i].action = ShipActionList.selected_item;
				// make highlight box pulsing...
				CurrentListItem->TextInfo[ShipActionList.selected_item]->highlighttype = HIGHLIGHT_Pulsing;
				JoystickConfigState = JOYCONFIG_SelectAction;
				CurrentList->Static = FALSE;
			break;
			}
		}
	}

	if (!assigned)
	{
		for (i = 0; i < JoystickInfo[JoystickMap[JoystickList.selected_item]].NumPOVs; i++)
		{
			dir = -1;
			multidir = GetPOVDirection( &js[ new_input ][JoystickMap[JoystickList.selected_item]], i);	
			if (multidir & POV_Up)
				dir = BitPos(POV_Up);

			if (multidir & POV_Down)
				dir = BitPos(POV_Down);

			if (multidir & POV_Left)
				dir = BitPos(POV_Left);

			if (multidir & POV_Right)
				dir = BitPos(POV_Right);

			if (dir != -1)
			{
				assigned = TRUE;
				switch (JoystickConfigState)
				{
				case JOYCONFIG_SelectAction:
					ShipActionList.selected_item = JoystickInfo[joystick_num].POV[i].action[dir];
					break;
				case JOYCONFIG_AssignButton:
	  				JoystickInfo[joystick_num].POV[i].action[dir] = ShipActionList.selected_item;
					// make highlight box pulsing...
					CurrentListItem->TextInfo[ShipActionList.selected_item]->highlighttype = HIGHLIGHT_Pulsing;
					JoystickConfigState = JOYCONFIG_SelectAction;
					CurrentList->Static = FALSE;
				break;
				}
			}
		}
	}

	for (i = 0; i < num_buttons; i++)
	{
		if (JoystickInfo[joystick_num].Button[i].action == ShipActionList.selected_item)
		{	
			sprintf( JoystickBtnText, "current: %s", JoystickInfo[joystick_num].Button[i].name );
			button_found++;
		}
	}

	for (i = 0; i < num_POVs; i++)
	{
		for (j = 0; j < MAX_POV_DIRECTIONS; j++)
		{
			if (JoystickInfo[joystick_num].POV[i].action[j] == ShipActionList.selected_item)
			{	
				sprintf( JoystickBtnText, "current: %s %s", JoystickInfo[joystick_num].POV[i].name, JoystickPOVDirections[j] );
				button_found++;
			}
		}
	}

	if (!button_found)
		strcpy( JoystickBtnText, NoBtnText );

	if (button_found > 1)
		strcpy( JoystickBtnText, MultiBtnText );

	if (CurrentList->selected_item == 0)
		JoystickBtnText[0] = 0;

	switch( JoystickConfigState )
	{
	case JOYCONFIG_SelectAction:
		strncpy( JoystickModeText, JoyMode1, sizeof(JoystickModeText) );
		break;
	case JOYCONFIG_AssignButton:
		strncpy( JoystickModeText, JoyMode2, sizeof(JoystickModeText) );
		break;
	}


}

void CheckJoyPOVs( int *dummy )
{
	int i, dir, multidir;

	for (i = 0; i < JoystickInfo[JoystickMap[JoystickList.selected_item]].NumPOVs; i++)
	{
		dir = -1;
		multidir = GetPOVDirection( &js[ new_input ][JoystickMap[JoystickList.selected_item]], i);	
		if (multidir & POV_Up)
			dir = BitPos(POV_Up);

		if (multidir & POV_Down)
			dir = BitPos(POV_Down);

		if (multidir & POV_Left)
			dir = BitPos(POV_Left);

		if (multidir & POV_Right)
			dir = BitPos(POV_Right);

		if (dir != -1)
		{
			CurrentJoyPOV = i;
			CurrentJoyPOVDirection = dir;
			strncpy(JoystickPOVText, JoystickInfo[JoystickMap[JoystickList.selected_item]].POV[CurrentJoyPOV].name, sizeof(JoystickPOVText));
			strncpy(JoystickPOVDirectionText, JoystickPOVDirections[CurrentJoyPOVDirection], sizeof(JoystickPOVText));
			strncpy ( SelectedActionText, ShipActionList.item[JoystickInfo[JoystickMap[JoystickList.selected_item]].POV[CurrentJoyPOV].action[CurrentJoyPOVDirection]], sizeof(SelectedActionText) );
			break;
		}
	}
}

void CheckJoyAxis( int *dummy )
{
	int joystick = JoystickMap[JoystickList.selected_item];
	int axis;
	float pos;
	LONG *axisptr[MAX_JOYSTICK_AXIS] = { &js[ new_input ][joystick].lX, &js[ new_input ][joystick].lY, &js[ new_input ][joystick].lZ, 
										&js[ new_input ][joystick].lRx, &js[ new_input ][joystick].lRy, &js[ new_input ][joystick].lRz,
										&js[ new_input ][joystick].rglSlider[0], &js[ new_input ][joystick].rglSlider[1] };
	char *left;
	char *right;

	axis = AxisMap[JoystickAxisList.selected_item];

	pos = *axisptr[axis] * JoystickInfo[ joystick ].Axis[ axis ].sensitivity;
	if ( JoystickInfo[ joystick ].Axis[ axis ].fine )
		pos *= (float) fabs( pos );
	UpdateAxisPtr( pos );

	if (JoystickInfo[joystick].Axis[axis].inverted)
	{
		left = ShipAxisSeperateText[AxisActionList.selected_item * 2 + 1];
		right = ShipAxisSeperateText[AxisActionList.selected_item * 2];
	}else
	{
		right = ShipAxisSeperateText[AxisActionList.selected_item * 2 + 1];
		left = ShipAxisSeperateText[AxisActionList.selected_item * 2];
	}

	strcpy(AxisExtremeLeftText, left);
	strcpy(AxisExtremeRightText, right);

	// if choosing axis, & selected item has changed...
	if (CurrentListItem)
	{
		if ((LIST *)CurrentListItem->Variable == &JoystickAxisList)
			ChooseJoyAxis( NULL );
	}
}

void ExitJoySetup( MENU *Menu )
{
   int joystick, i, j, k;
	
	for ( i = 0; i < JoystickList.items; i++ )
	{
		joystick = JoystickMap[ i ];
		
		// check all axis
		for (j = 0; j < MAX_JOYSTICK_AXIS; j++)
		{
			if ( JoystickInfo[ joystick ].Axis[ j ].exists &&  JoystickInfo[ joystick ].Axis[ j ].action )
			{
				JoystickInfo[ joystick ].assigned = TRUE;
			}
		}

		// check all povs
		for (j = 0; j < JoystickInfo[ joystick ].NumPOVs; j++)
		{
			for ( k = 0; k < MAX_POV_DIRECTIONS; k++ )
			{
				if ( JoystickInfo[ joystick ].POV[ j ].action[ k ] )
				{
					JoystickInfo[ joystick ].assigned = TRUE;
				}
			}
		}

		// check all buttons
		for (j = 0; j < JoystickInfo[ joystick ].NumButtons; j++)
		{
			if ( JoystickInfo[ joystick ].Button[ j ].action )
			{
			 	JoystickInfo[ joystick ].assigned = TRUE;
			}
		}
	}

	write_config( player_config, biker_config );
}

void ExitMouseSetup( MENU *Menu )
{
//	if ( memcmp( &Config, player_config, sizeof( Config ) ) )
	{
		*player_config = Config;
		write_config( player_config, biker_config );
	}
}


void SelectVDUList ( MENUITEM *Item )
{
	MENUITEM *NewItem;
	LIST *List;

	List = (LIST *)(Item->Variable);

	for( NewItem = CurrentMenu->Item ; NewItem->x >= 0 ; NewItem++ )
	{	
		if ( NewItem->Variable == List && (NewItem != Item))
		{	CurrentMenuItem = NewItem;
			SelectList( CurrentMenuItem );
			PreListItem = Item;
			break;
		}
	}
}

void GoToNextLevel( MENUITEM *Item )
{
	StartASinglePlayerGame( NULL );
}

void TitleLoadGame( MENUITEM *Item )
{
	LoadASinglePlayerGame( NULL );
}


void RestoreDefaultControlSettings( MENUITEM *Item )
{
	// replace config...
	Config = default_config;
	Config.bike = ValidBikeSelected( Config.bike );
	SelectedBike = Config.bike;
	ReInitJoysticks();
	DefaultJoystickSettings( &Config );

	// re-init controls...
	InitControls( NULL );

	LastMenu = CurrentMenu;	
	VduClear();
	ProcessVduItems( CurrentMenu );
}

void InitSelectedLevelText( MENU *Menu )
{
//	strcpy( SelectedLevelText, MissionBriefing[ CurrentLevel ] );
}

void InitAttractMode( MENU *Menu )
{
	MyGameStatus = STATUS_WaitingToStartDemo;
}

void PrepareNextLevelStart( MENU *Menu )
{
	if( cd_info.IsPlaying )
		CdStop();

	LoadLevelText( NULL );
	MyGameStatus = STATUS_WaitingToStartSinglePlayer; 
}

void HostAboutToStart( MENUITEM *Item )
{
	if( TeamGame )
	{
		MenuChange( &NewTeamItem );
	}else
	{
		MyGameStatus = STATUS_WaitingToStartMultiPlayerHost;
		MenuChange( Item );
	}
}
	
void PseudoHostAboutToStart( MENUITEM *Item )
{
	if( TeamGame )
	{
		MenuChange( &NewTeamItem );
	}else
	{
		DebugPrintf("about to send message to server to start game\n");

		SendGameMessage(MSG_TOSERVER, 0, 0, TOSERVERMSG_StartGame, 0);

		MyGameStatus = STATUS_StartingMultiplayer;
//		MenuChangeEx( &MENU_NEW_JoinWaitingToStart );
	}
}

void ToggleCDAudio( MENUITEM *Item )
{
	if ( CD_OK )
	{
		if ( !cd_info.IsPlaying  )
			PlayAudioTrack();
	}else
	{
		if ( cd_info.IsPlaying )
			CdStop();
	}
}

void ToggleCDAudioTitles( MENUITEM *Item )
{
	if ( !LevelsOnCD )
	{
		if ( CD_OK )
		{
			if ( !cd_info.IsPlaying  )
				PlayAudioTrack();
		}else
		{
			if ( cd_info.IsPlaying )
				CdStop();
		}
	}
}


void ExitSoundMenu( MENU *Menu )
{
	write_config( player_config, biker_config );
}

void MakeUnselectable( MENUITEM *Item )
{
	Item->highlightflags |= TEXTFLAG_Unselectable;
	CursorDown();
}

void SendQuickText( MENUITEM *Item )
{

	MenuExit();
	ReadInput();
	SendGameMessage(MSG_TEXTMSG, 0, 0, TEXTMSGTYPE_QuickTaunt, 0);
	QuickText.text[0] = 0;
	JustExitedMenu = FALSE;
	//flush_input = TRUE;
}
void SendQuickTextWhisper( MENUITEM *Item )
{

	MenuExit();
	ReadInput();
	SendGameMessage(MSG_TEXTMSG, 0, 0, TEXTMSGTYPE_QuickTauntWhisper, 0);
	QuickTextWhisper.text[0] = 0;
	JustExitedMenu = FALSE;
	//flush_input = TRUE;
}


void InitCrystalsFoundText( MENU *Menu )
{
	uint32 IntLevelTimeTaken;

	IntLevelTimeTaken = ( ( uint32 ) LevelTimeTaken ) / 100;

	if ( CrystalsFound == 1 )
	{
		sprintf( CrystalsFoundText, LT_OneCrystalFound, CrystalsFound );
	}else
	{
		sprintf( CrystalsFoundText, LT_CrystalsFound, CrystalsFound );
	}

	if ( NumGoldBars == 1 )
	{
		sprintf( GoldBarsFoundText, LT_OneGoldBarFound, NumGoldBars );
	}else
	{
		sprintf( GoldBarsFoundText, LT_GoldBarsFound, NumGoldBars );
	}
	
	if( Secrets == 1 )
	{
		sprintf( SecretsFoundText, LT_OneSecretFoundOutOf, Secrets, TotalSecrets );
	}else
	{
		sprintf( SecretsFoundText, LT_SecretsFoundOutOf, Secrets, TotalSecrets );
	}

	if( NumKilledEnemies == 1 )
	{
		sprintf( EnemiesKilledText, LT_OneEnemyKilled, NumKilledEnemies, NumInitEnemies );
	}else
	{
		sprintf( EnemiesKilledText, LT_EnemysKilled, NumKilledEnemies, NumInitEnemies );
	}

	/*
	sprintf( TimeTakenText, "time taken %d min%s %d sec%s", 
		IntLevelTimeTaken / 60,
		( ( IntLevelTimeTaken / 60 ) == 1 ) ? "" : "s",
		IntLevelTimeTaken % 60,
		( ( IntLevelTimeTaken % 60 ) == 1 ) ? "" : "s"); 
	*/
	if ( ( ( IntLevelTimeTaken / 60 ) == 1 ) && ( ( IntLevelTimeTaken % 60 ) == 1 ) )
	{
		sprintf( TimeTakenText, LT_TimeTaken1/*"time taken %d min %d sec"*/,	IntLevelTimeTaken / 60,	IntLevelTimeTaken % 60 ); 
	}
	if ( ( ( IntLevelTimeTaken / 60 ) != 1 ) && ( ( IntLevelTimeTaken % 60 ) == 1 ) )
	{
		sprintf( TimeTakenText, LT_TimeTaken2/*"time taken %d mins %d sec"*/,	IntLevelTimeTaken / 60,	IntLevelTimeTaken % 60 ); 
	}
	if ( ( ( IntLevelTimeTaken / 60 ) == 1 ) && ( ( IntLevelTimeTaken % 60 ) != 1 ) )
	{
		sprintf( TimeTakenText, LT_TimeTaken3/*"time taken %d min %d secs"*/,	IntLevelTimeTaken / 60,	IntLevelTimeTaken % 60 ); 
	}
	if ( ( ( IntLevelTimeTaken / 60 ) != 1 ) && ( ( IntLevelTimeTaken % 60 ) != 1 ) )
	{
		sprintf( TimeTakenText, LT_TimeTaken4/*"time taken %d mins %d secs"*/,	IntLevelTimeTaken / 60,	IntLevelTimeTaken % 60 ); 
	}
}

void SelectGoldBarModel( MENU *Menu )
{
	ShowHoloModel( TITLE_MODEL_GoldBar );
}

void AfterSpecialMessage( MENUITEM *Item )
{
	switch( GameCompleted )
	 {
	 case GAMECOMPLETE_GotAllCrystalsSoFar:
		 MenuChangeEx( &MENU_NEW_BetweenLevels );
		 return;
	 }

	ReleaseView();
	MyGameStatus = STATUS_Title;
	MenuRestart( &MENU_Start );
	TitleInitDone = FALSE;
	InitialTexturesSet = FALSE;
	InitScene();
	InitView();
}

void NextLevelOrGameComplete( MENUITEM *Item )
{
	// kill off hololight, holopad & holo-object
	KillHoloModel();
	Models[BackgroundModel[TITLE_MODEL_HoloLight]].Visible = 0;
	Models[BackgroundModel[TITLE_MODEL_Holopad]].Visible = 0;
	
	switch( GameCompleted )
	 {
	 case GAMECOMPLETE_NotComplete:
		 MenuChangeEx( &MENU_NEW_BetweenLevels );
		 return;
	 case GAMECOMPLETE_WithoutAllCrystals:
		 MenuChangeEx( &MENU_NEW_GeneralLoading );
		 MyGameStatus = STATUS_WaitingToStartEndGameSequence;
		 return;
	 case GAMECOMPLETE_Cheated:
		 strcpy( GameCompleteText, GameCompleteWithCheating );
		 break;
	 case GAMECOMPLETE_Win98Shareware:
		 strcpy( GameCompleteText, GameCompleteWin98Shareware );
		 break;
 	 case GAMECOMPLETE_GotAllCrystalsSoFar:
		 strcpy( GameCompleteText, GameCompleteGotAllCrystalsSoFar );
		 break;
	 case GAMECOMPLETE_WithAllCrystals:
		 MenuChangeEx( &MENU_NEW_GeneralLoading );
		 MyGameStatus = STATUS_WaitingToStartEndGameSequence;
		 return;
	 case GAMECOMPLETE_WithAllCrystalsExceptLast:
		 MenuChangeEx( &MENU_NEW_GeneralLoading );
		 MyGameStatus = STATUS_WaitingToStartEndGameSequence;
		 return;
	 case GAMECOMPLETE_AdditionalLevels:
		 strcpy( GameCompleteText, GameCompleteAdditionalLevels );
		 break;
	 }
	
	 MenuChangeEx( &MENU_NEW_SpecialMessage );
}


char *DemoFileName( char *demoname )
{
	static char filename[ MAX_DEMOFILENAME_LENGTH  ];
	char *dmo;

	folder_exists( DEMOFOLDER );
	strcpy( filename, DEMOFOLDER );
	strncat( filename, "\\", MAX_DEMONAME_LENGTH );
	strncat( filename, demoname, MAX_DEMONAME_LENGTH );
	filename[ strlen( DEMOFOLDER ) + 1 + MAX_DEMONAME_LENGTH ] = 0;
	_strupr( filename );
	dmo = strstr( filename, DEMOFILE_EXTENSION );
	if ( !dmo )
		strcat( filename, DEMOFILE_EXTENSION );

	return filename;
}


char *DemoName( char *demofilename )
{
	static char demoname[ MAX_DEMONAME_LENGTH + 4 ];
	char *dmo;
	int offset;

	offset = strstr( demofilename, DEMOFOLDER ) ? strlen( DEMOFOLDER ) + 1 : 0;
	strncpy( demoname, demofilename + offset, sizeof( demoname ) - 1 );
	demoname[ sizeof( demoname ) - 1 ] = 0;
	_strupr( demoname );
	dmo = strstr( demoname, DEMOFILE_EXTENSION );
	if ( dmo )
		*dmo = 0;

	return demoname;
}


char TypeFileName( TEXT *t, char c )
{
	switch ( c )
	{
	case '\\':
	case '/':
	case ':':
	case '*':
	case '?':
	case '"':
	case '<':
	case '>':
	case '|':
		return 0;
	default:
		return c;
	}
}


char *CTF_Type( SLIDER *s )
{
	switch ( s->value )
	{
	case CTF_STANDARD:
		return LT_CTF_Normal/*"normal"*/;
	case CTF_MUST_CARRY:
		return LT_CTF_MustCarry/*"carry it back"*/;
	case CTF_CAN_CARRY:
		return LT_CTF_CanCarry/*"can pick up"*/;
	case CTF_ONE_TOUCH:
		return LT_CTF_OneTouch/*"1 touch return"*/;
	case CTF_NO_RETURN:
		return LT_CTF_NoReturn/*"can't pick up"*/;
	default:
		return LT_CTF_Standard/*"standard"*/;
	}
}


BOOL ListDelete( LIST *l, int item )
{
	if ( item >= 0 && item < l->items )
	{
		while ( ++item < l->items )
		{
			strncpy( l->item[ item - 1 ], l->item[ item ], sizeof( l->item[ 0 ] ) );
		}
		l->items--;
		if ( l->selected_item >= l->items )
			l->selected_item = l->items - 1;
		if ( l->top_item >= l->items )
			l->top_item = l->items - 1;
		return TRUE;
	}
	else
		return FALSE;
}


BOOL DeleteDemo( LIST *l, int item )
{
	return DeleteFile( DemoFileName( l->item[ item ] ) ) ? ListDelete( l, item ) : FALSE;
}


void InGameSaveASinglePlayerGame( MENUITEM *item )
{
	if ( InGameSave( item ) )
	{
		strncpy( LoadSavedGameList.item[ LoadSavedGameList.selected_item ], SavedGameInfo( LoadSavedGameList.selected_item ), sizeof( LoadSavedGameList.item[ 0 ] ) - 1 );
		LoadSavedGameList.item[ LoadSavedGameList.selected_item ][ sizeof( LoadSavedGameList.item[ 0 ] ) - 1 ] = 0;
	}
}


void DebugLastError( void )
{
	DWORD err;
	LPVOID lpMsgBuf;

	err = GetLastError();

	FormatMessage( 
		  FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		  NULL,
		  err,
		  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		  (LPTSTR) &lpMsgBuf,
		  0,
		  NULL 
		  );
	DebugPrintf( "DeleteSavedGame failed: err=0x%08X msg=%s\n",
		err, lpMsgBuf );
	LocalFree( lpMsgBuf );
}


BOOL DeleteSavedGame( LIST *l, int item )
{
	if ( DeleteFile( SaveGameFileName( item ) )
		&& DeleteFile( SaveGamePicFileName( item ) ) )
	{
		strncpy( l->item[ item ], SavedGameInfo( item ), sizeof( l->item[ 0 ] ) - 1 );
		l->item[ item ][ sizeof( l->item[ 0 ] ) - 1 ] = 0;
		return TRUE;
	}
	DebugLastError();
	return FALSE;
}

void SaveMacros( MENUITEM *Item )
{
	strcpy( player_config->macro1, MacroText1.text ); 
	strcpy( player_config->macro2, MacroText2.text ); 
	strcpy( player_config->macro3, MacroText3.text ); 

	write_config( player_config, biker_config );
}

BOOL SetGamma( SLIDER *slider )
{
	double tempgamma;

	tempgamma = Gamma;
	
	Gamma = ( (double)slider->value ) / 100.0F;

#ifdef SOFTWARE_ENABLE
	if( SoftwareVersion )
		GlBright = (long) ( Gamma * 32.0F );
#endif

	if ( tempgamma == Gamma )
		return TRUE;

	ReleaseView();
	D3DAppChangeTextureFormat( TextureList.selected_item );

	if ( !InitView() )
		exit( 1 );

	InitialTexturesSet = FALSE;
	FadeHoloLight(HoloLightBrightness);
	DarkenRoom2(RoomDarkness);

	return TRUE;
}

BOOL SetWaterDetail( SLIDER *slider )
{
	switch( slider->value )
	{
	case 1:
		WATER_CELLSIZE = 128.0F;
		break;
	case 2:
		WATER_CELLSIZE = 64.0F;
		break;
	default:
		WATER_CELLSIZE = 64.0F;
	}

	return TRUE;
}

BOOL SetNumPrimaryPickups( SLIDER *slider )
{
	NumPrimaryPickups = slider->value;

	return TRUE;
}

char *AxisName( SLIDER *s )
{
	return ( s->value >= 0 && s->value < JoystickAxisList.items ) ? JoystickAxisList.item[ s->value ] : NULL;
}


char *AxisActionName( SLIDER *s )
{
	return ( s->value >= 0 && s->value < AxisActionList.items ) ? AxisActionList.item[ s->value ] : NULL;
}


BOOL SetAxisSlider( SLIDER *s )
{
	if ( s->value >= 0 && s->value < JoystickAxisList.items )
	{
		if ( JoystickAxisList.selected_item != s->value )
		{
			JoystickAxisList.selected_item = s->value;
			ChooseJoyAxis( NULL );
		}
		return TRUE;
	}
	else
		return FALSE;
}


BOOL SetAxisActionSlider( SLIDER *s )
{
	if ( s->value >= 0 && s->value < AxisActionList.items )
	{
		int joystick = JoystickMap[JoystickList.selected_item];
		int axis;

		AxisActionList.selected_item = s->value;
		axis = AxisMap[JoystickAxisList.selected_item];
		JoystickInfo[joystick].Axis[axis].action = ShipAxisLookup[ AxisActionList.selected_item ];
		CheckJoyAxis( NULL );
		return TRUE;
	}
	else
		return FALSE;
}
#if 1

#define HOLOMODEL_Done		0
#define HOLOMODEL_Expand	1
#define HOLOMODEL_Shrink	2

float HoloModelTimer;
int HoloModelMode;
uint16 NextHoloModel;

#define HOLOSCANSPEED 0.5F
#define NUM_HOLO_SCANPLANES 2
PLANE HoloPlane[ NUM_HOLO_SCANPLANES ] = {
	{ 0.0F, 0.0F, -1.0F, 0.0F },
	{ 0.0F, 0.0F, 1.0F, 0.0F },
};
float MinHoloPlaneOffset[ NUM_HOLO_SCANPLANES ];
float MaxHoloPlaneOffset[ NUM_HOLO_SCANPLANES ];
uint8 CurrentHoloPlane;
float CurrentHoloOffset;

void InitHoloScanLine( void )
{
	int i;
	
	CurrentHoloPlane = 0;

	for( i = 0; i < NUM_HOLO_SCANPLANES; i++ )
	{
		HoloPlane[ i ].Offset = 0.0F;
		GetExtremeOffsets( CurrentHoloModel, &HoloPlane[ i ], &MinHoloPlaneOffset[ i ], &MaxHoloPlaneOffset[ i ] );
	}

	CurrentHoloOffset = MinHoloPlaneOffset[ CurrentHoloPlane ];
}

VECTOR HoloRot = { 0.0F, 0.0F, 0.0F };

void PlotHoloScanLine( void )
{
	MATRIX Mat_R;
	VECTOR zerovec = { 0.0F, 0.0F, 0.0F };
	PLANE tempplane;

	if ( CurrentHoloOffset >= MaxHoloPlaneOffset[ CurrentHoloPlane ] )
	{	
		if (++CurrentHoloPlane == NUM_HOLO_SCANPLANES)
		{
			CurrentHoloPlane = 0;
		}

		CurrentHoloOffset = MinHoloPlaneOffset[ CurrentHoloPlane ];
	}

	KillLines();


	BuildRotMatrix(0.0F, HoloRot.y, 0.0F, &Mat_R);
	tempplane = HoloPlane[ CurrentHoloPlane ];
	tempplane.Offset = CurrentHoloOffset;
	ApplyMatrix( &Mat_R, &HoloPlane[ CurrentHoloPlane ].Normal, &tempplane.Normal);

   	if (!SetUpLines( CurrentHoloModel, tempplane, &HoloRot))
		Msg("SetUpLines() returned FALSE");

	Models[ CurrentHoloModel ].IntersectionPlane = HoloPlane[ CurrentHoloPlane ];
	
	CurrentHoloOffset += HOLOSCANSPEED * framelag;
}


void InitHoloPad( void )
{
	CurrentHoloModel = (uint16)-1;
	HoloModelScale = 1.0F;
	HoloModelTimer = 0.0F;
	HoloModelMode = HOLOMODEL_Done;
	NextHoloModel = (uint16)-1;
}

void KillHoloModel( void )
{

	if ( CurrentHoloModel != (uint16)-1 )
		KillUsedModel( CurrentHoloModel );

	CurrentHoloModel = (uint16)-1;

}			  

BOOL FlyGirlActive = FALSE;

void LoadHoloModel( uint16 model )
{
	int16 systpageindex, i;

	if ( CurrentHoloModel != ( uint16 ) -1 )
	{
		KillHoloModel();
	}

	if ( model == TITLE_MODEL_ExtraModels )
	{
		FlyGirlActive = TRUE;
		HoloModelScale = 1.0F;
		for( i = 0; i < MAXBIKETYPES; i++ )
		{
			if ( HoloModelLookup[ i ] == model )
			{
				HoloModelScale = HoloScaleLookupTable[ i ];
				break;
			}
		}
		return;
	}else
	{
		FlyGirlActive = FALSE;
	}
	
	CurrentHoloModel = FindFreeModel();

	if (CurrentHoloModel != (uint16) -1)
	{
		
		if ( TitleModelSet[ model ].DoIMorph )
		{
			systpageindex = MxaModelHeaders[ model ].SysTloadIndex[0];
			MovePPMToVideoMemory( &Tloadheader, MxaModelHeaders[ model ].TloadIndex[0], SystemMemTPages[ systpageindex ].lpSrcTextureSurf );
		}

		HoloModelScale = 1.0F;
		for( i = 0; i < MAXBIKETYPES; i++ )
		{
			if ( HoloModelLookup[ i ] == model )
			{
				HoloModelScale = HoloScaleLookupTable[ i ];
				break;
			}
		}
		
		Models[CurrentHoloModel].Pos = BikePos;
		Models[CurrentHoloModel].Mat = MATRIX_Identity;
		MatrixTranspose ( &Models[ CurrentHoloModel ].Mat, &Models[ CurrentHoloModel ].InvMat );
		Models[CurrentHoloModel].Visible = 1;
		Models[CurrentHoloModel].Group = 0;
		Models[CurrentHoloModel].Func = MODFUNC_ScaleXYZandRotate;
		Models[CurrentHoloModel].ModelNum = model;
		Models[CurrentHoloModel].Xscale = 0.0F;
		Models[CurrentHoloModel].Yscale = HoloModelScale;
		Models[CurrentHoloModel].Zscale = 0.0F;
		Models[CurrentHoloModel].Scale = 1.0F;
		Models[CurrentHoloModel].Visible = 1;
		Models[CurrentHoloModel].Frame = 0;
		Models[CurrentHoloModel].InterpFrame = 0;
		Models[CurrentHoloModel].InterpTime = 0;
		Models[CurrentHoloModel].Rot.x = 0.0F;
		Models[CurrentHoloModel].Rot.y = 0.0F;
		Models[CurrentHoloModel].Rot.z = 0.0F;
		Models[CurrentHoloModel].Flags = MODFLAG_Original;
	}
}

#ifdef SOFTWARE_ENABLE

void ScanAllBikes( void )
{
	int16 systpageindex, i;
	int				execbuf;
	int				group;
	int	model;

	for( model = TITLE_MODEL_Lokasenna; model <= TITLE_MODEL_Slick; model++ )
	{
		systpageindex = MxaModelHeaders[ model ].SysTloadIndex[0];
		MovePPMToVideoMemory( &Tloadheader, MxaModelHeaders[ model ].TloadIndex[0], SystemMemTPages[ systpageindex ].lpSrcTextureSurf );

		if ( SoftwareVersion )
		{
			for( group=0 ; group<MxaModelHeaders[ model ].num_groups; group++)
			{
				for( execbuf=0 ; execbuf<MxaModelHeaders[ model ].Group[ group ].num_execbufs; execbuf++)
				{
					CWScanExecuteBuffer( MxaModelHeaders[ model ].Group[ group ].lpExBuf[execbuf] );
				}
			}
		}
	}
}
#endif

void ScaleHoloModel( float scale )
{
   	if( CurrentHoloModel != (uint16)-1 )
	{
		Models[CurrentHoloModel].Xscale = scale * HoloModelScale;
		Models[CurrentHoloModel].Yscale = HoloModelScale;
		Models[CurrentHoloModel].Zscale = scale * HoloModelScale;
	}
}

#define HOLO_SPEECH_DELAY 60.0F
float HoloSpeechDelay;
BOOL HoloSpeechDone = FALSE;

// specify (uint16)-1 for no new model
void ShowHoloModel( uint16 model )
{
	HoloSpeechDelay = HOLO_SPEECH_DELAY;
	HoloSpeechDone = FALSE;
	
	if ( ( CurrentHoloModel == (uint16)-1 ) && !FlyGirlActive )
	{
		if ( model == (uint16)-1  )
			return;
		
		LoadHoloModel( model );
		HoloModelTimer = 0.0F;
		HoloModelMode = HOLOMODEL_Expand;

	}else
	{
		KillLines();
		
		switch( HoloModelMode )
		{
		case HOLOMODEL_Done:
			HoloModelMode = HOLOMODEL_Shrink;
			break;
		case HOLOMODEL_Expand:
			HoloModelMode = HOLOMODEL_Shrink;
			break;
		case HOLOMODEL_Shrink:
			break;
		}
	}

	NextHoloModel = model;
}

float flygirl_scale = 0.0F;
VECTOR flygirloffset = { 0.0F, 20.0F, 0.0F };

void ProcessFlyGirl( float scale )
{
	MATRIX TempMatrix, TempRotMatrix, TempTransMatrix;
	VECTOR flygirlpos;

	flygirlpos = BikePos;
	flygirlpos.y += flygirloffset.y;

	TempMatrix = MATRIX_Identity;
	TempMatrix._11 *= scale * HoloModelScale;
	TempMatrix._22 *= HoloModelScale;
	TempMatrix._33 *= scale * HoloModelScale;

	BuildRotMatrix(0.0F, HoloRot.y, 0.0F, &TempRotMatrix);

	MatrixMultiply( &TempMatrix, &TempRotMatrix, &TempTransMatrix );

	UpdateFlyGirl( &flygirlpos, &TempTransMatrix, TRUE );

}

void ProcessHoloModel( void )
{
	float oldtimer;
	BOOL reload = FALSE;

	HoloRot.y -= 0.5F * framelag;
	if (HoloRot.y < 0.0F)
		HoloRot.y += 360.0F;

	HoloRot.x = 0.0F;
	HoloRot.z = 0.0F;

	if ( ( CurrentHoloModel == (uint16)-1 ) && !FlyGirlActive )
	{
		return;
	}

	oldtimer = HoloModelTimer;
	
	switch( HoloModelMode )
	{
	case HOLOMODEL_Done:
		if( !FlyGirlActive )
		{
			PlotHoloScanLine();
		}
		if ( !HoloSpeechDone )
		{
			if ( HoloSpeechDelay < 0.0F )
			{
				TriggerBikeSpeech( NULL );
				HoloSpeechDone = TRUE;
			}

			HoloSpeechDelay -= framelag;
		}
		if( FlyGirlActive )
		{
			ProcessFlyGirl((float)fabs(HoloModelTimer));
		}
		return;
	case HOLOMODEL_Expand:
		HoloModelTimer += framelag / 18.0F;
		break;
	case HOLOMODEL_Shrink:
		HoloModelTimer -= framelag / 18.0F;
		if ( HoloModelTimer < 0.0F )
		{
			HoloModelMode = HOLOMODEL_Expand;
			HoloModelTimer = (float)fabs(HoloModelTimer);
			reload = TRUE;
		}
		break;
	}

	if ( HoloModelTimer > 1.0F )
	{
		HoloModelMode = HOLOMODEL_Done;
		HoloModelTimer = 1.0F;
	}
	
	if ( reload )
	{
		if ( NextHoloModel == (uint16)-1 )
		{
			if ( FlyGirlActive )
			{
				UpdateFlyGirl( &BikePos, &MATRIX_Identity, FALSE );
				FlyGirlActive = FALSE;
			}else
			{
				KillHoloModel();
			}
			HoloModelMode = HOLOMODEL_Done;
			return;
		}else
		{
			LoadHoloModel( NextHoloModel );
		}
	}

	if( FlyGirlActive )
	{
		ProcessFlyGirl((float)fabs(HoloModelTimer));
	}else
	{
		UpdateFlyGirl( &BikePos, &MATRIX_Identity, FALSE );
		ScaleHoloModel( (float)fabs(HoloModelTimer));
	}

	if( ( HoloModelMode == HOLOMODEL_Done ) && ( !FlyGirlActive ) )
	{
		InitHoloScanLine();
	}
}


BOOL DeletePilot( LIST *l, int item )
{
	static char fname[ MAX_PATH ];

	sprintf( fname, "%s.cfg", l->item[ item ] );
	if ( l->items > 1 && DeleteFile( fname ) && ListDelete( l, item ) )
	{
		SelectPilot( NULL );
		return TRUE;
	}
	else
		return FALSE;
}

void UnToggleOption( BOOL *toggle )
{
	MENUITEM *Item;
	BOOL toggled = FALSE;

	for( Item = CurrentMenu->Item ; Item->x >= 0 ; Item++ )
	{
		if( Item->Variable )
		{
			if ( (BOOL *)Item->Variable == toggle )
			{
				if( !toggled )
				{
					SelectFlatMenuToggle( Item );
					toggled = TRUE;
				}
			}
		}
	}

	if ( !toggled )
	{
		*toggle = !(*toggle);
	}
}

void BigPacketsSelected( MENUITEM *Item )
{
	MENUITEM *tempitem;
	int i;
	
	if( BigPackets )
	{
		if( !UseShortPackets )
		{
			FlashMenuText( LT_BigPacketsSelected/*"short packets have been automatically enabled"*/, 60.0F * 3.0F, (uint16) -1 );
			UnToggleOption( &UseShortPackets );
		}
	}

	if ( !IsServerGame )
	{
		for ( tempitem = CurrentMenu->Item; tempitem->x >= 0; tempitem++ )
		{
			if ( tempitem->Variable == &RecordDemo )
			{
				if ( !BigPackets )
				{
					tempitem->FuncSelect = SelectFlatMenuToggle;
					tempitem->FuncDraw = DrawFlatMenuToggle;
					DrawFlatMenuToggle( tempitem );
				}
				else
				{
					RecordDemo = FALSE;
					tempitem->FuncSelect = NULL;
					tempitem->FuncDraw = NULL;
					for ( i = 0; i < tempitem->numtextitems; i++ )
					{
						KillTextInfo( tempitem->TextInfo[ i ] );
						TextStackLevel--;
					}
					tempitem->numtextitems = 0;
				}
			}
		}
	}
}

void ShortPacketsSelected( MENUITEM *Item )
{
	if( !UseShortPackets )
	{
		if( BigPackets )
		{
			FlashMenuText( LT_ShortPacketsSelected/*"packet grouping has been automatically disabled"*/, 60.0F * 3.0F, (uint16) -1 );
			UnToggleOption( &BigPackets );
		}
	}
}

void ToggleBikeEngines( MENUITEM *Item )
{
	if ( !BikeEnginesOn )
	{
		// call to stop bike engines
	}
}

void InitTitleMessaging( void )
{
	int i;

	for( i = 0; i < TITLE_TEXT_MSGS_STORED; i++ )
	{
		TitleMessage[ i ][ 0 ] = 0;
	}

	TitlePlayerMessage.text[ 0 ] = 0;
}

#endif



LPGUID	DeviceGuidPnt = NULL;
GUID	DeviceGuid;

void	GetDeviceGuid( void )
{
	DWORD size;

	if ( !ghCondemnedKey )
	{
#ifndef SELF_PLAY
#ifdef FINAL_RELEASE
		RegOpenKeyEx(REGISTRY_ROOT_KEY,
			REGISTRY_GAME_KEY,
			0,
			KEY_ALL_ACCESS,
			&ghCondemnedKey
			);
#else
		RegCreateKeyEx(REGISTRY_ROOT_KEY,
						REGISTRY_GAME_KEY,
						0,
						NULL,                   
						REG_OPTION_NON_VOLATILE,
						KEY_ALL_ACCESS,
						NULL,
						&ghCondemnedKey,
						&gdwCondemnedDisp
						);
#endif
#endif
	}
	size = sizeof(GUID);
	if( RegGet("DeviceGuid", (LPBYTE)&DeviceGuid, &size ) == ERROR_SUCCESS )
	{


	}
	size = sizeof(LPGUID);

	if( RegGet("DeviceGuidPnt", (LPBYTE)&DeviceGuidPnt, &size ) != ERROR_SUCCESS )
	{
		DeviceGuidPnt = NULL;
	}
}

#ifdef MENU_FORMAT_DEBUG

void GetFormatInfo ( MENU *Menu )
{
	ProcessVduItems( Menu );
	VduClear();
}

void TestMenuFormat( void )
{
	DebugPrintf("MENU_NEW_SpecialMessage\n");
	strcpy( GameCompleteText, GameCompleteGotAllCrystalsSoFar );
	GetFormatInfo ( &MENU_NEW_SpecialMessage );
	strcpy( GameCompleteText, GameCompleteWithCheating );
	GetFormatInfo ( &MENU_NEW_SpecialMessage );
	strcpy( GameCompleteText, GameCompleteAdditionalLevels );
	GetFormatInfo ( &MENU_NEW_SpecialMessage );
	
	DebugPrintf("MENU_NEW_StartSinglePlayer\n");
	GetFormatInfo ( &MENU_NEW_StartSinglePlayer );

	DebugPrintf("MENU_NEW_GeneralLoading\n");
	GetFormatInfo ( &MENU_NEW_GeneralLoading );

	DebugPrintf("MENU_NEW_StartAttractMode\n");
	GetFormatInfo ( &MENU_NEW_StartAttractMode );

	DebugPrintf("MENU_NEW_HostWaitingToStart\n");
	GetFormatInfo ( &MENU_NEW_HostWaitingToStart );

	DebugPrintf("MENU_NEW_ValidPickups\n");
	GetFormatInfo ( &MENU_NEW_ValidPickups );

	DebugPrintf("MENU_NEW_MoreMultiplayerOptions\n");
	GetFormatInfo ( &MENU_NEW_MoreMultiplayerOptions );

	DebugPrintf("MENU_NEW_CreateGame\n");
	GetFormatInfo ( &MENU_NEW_CreateGame );

	DebugPrintf("MENU_NEW_CreateLobbyGame\n");
	GetFormatInfo ( &MENU_NEW_CreateLobbyGame );

	DebugPrintf("MENU_NEW_ChooseConnectionToStart\n");
	GetFormatInfo ( &MENU_NEW_ChooseConnectionToStart );

	DebugPrintf("MENU_NEW_PrimaryOrder\n");
	GetFormatInfo ( &MENU_NEW_PrimaryOrder );

	DebugPrintf("MENU_NEW_SecondaryOrder\n");
	GetFormatInfo ( &MENU_NEW_SecondaryOrder );

	DebugPrintf("MENU_NEW_SecondaryWeaponKeys\n");
	GetFormatInfo ( &MENU_NEW_SecondaryWeaponKeys );

	DebugPrintf("MENU_NEW_PrimaryWeaponKeys\n");
	GetFormatInfo ( &MENU_NEW_PrimaryWeaponKeys );

	DebugPrintf("MENU_NEW_Weapons\n");
	GetFormatInfo ( &MENU_NEW_Weapons );

	DebugPrintf("MENU_NEW_ConfigureKeyboard\n");
	GetFormatInfo ( &MENU_NEW_ConfigureKeyboard );

	DebugPrintf("MENU_NEW_ConfigJoyAxis\n");
	GetFormatInfo ( &MENU_NEW_ConfigureKeyboard );

	DebugPrintf("MENU_NEW_ConfigJoyBtns\n");
	GetFormatInfo ( &MENU_NEW_ConfigJoyBtns );

	DebugPrintf("MENU_NEW_ConfigJoyPOVs\n");
	GetFormatInfo ( &MENU_NEW_ConfigJoyPOVs );

	DebugPrintf("MENU_NEW_SetupJoystick2\n");  
	GetFormatInfo ( &MENU_NEW_SetupJoystick2 );

	DebugPrintf("MENU_NEW_SetupJoystick\n");  
	GetFormatInfo ( &MENU_NEW_SetupJoystick );

	DebugPrintf("MENU_NEW_SetupMouse\n");  
	GetFormatInfo ( &MENU_NEW_SetupMouse );

	DebugPrintf("MENU_NEW_Controls\n");  
	GetFormatInfo ( &MENU_NEW_Controls );

	DebugPrintf("MENU_NEW_Lights\n");  
	GetFormatInfo ( &MENU_NEW_Lights );

	DebugPrintf("MENU_NEW_DetailLevels\n");  
	GetFormatInfo ( &MENU_NEW_DetailLevels );

	DebugPrintf("MENU_NEW_ScreenRes\n");  
	GetFormatInfo ( &MENU_NEW_ScreenRes );

	DebugPrintf("MENU_NEW_TextureFormat\n");  
	GetFormatInfo ( &MENU_NEW_TextureFormat );

	DebugPrintf("MENU_NEW_Visuals\n");  
	GetFormatInfo ( &MENU_NEW_Visuals );

	DebugPrintf("MENU_NEW_LobbyWaitingForHost\n");  
	GetFormatInfo ( &MENU_NEW_LobbyWaitingForHost );

	DebugPrintf("MENU_NEW_JoinWaitingToStart\n");  
	GetFormatInfo ( &MENU_NEW_JoinWaitingToStart );

	DebugPrintf("MENU_NEW_GetTeamPlayers\n");  
	GetFormatInfo ( &MENU_NEW_GetTeamPlayers );

	DebugPrintf("MENU_NEW_ChooseSessionToJoin\n");  
	GetFormatInfo ( &MENU_NEW_ChooseSessionToJoin );

	DebugPrintf("MENU_NEW_ChooseConnectionToJoin\n");  
	GetFormatInfo ( &MENU_NEW_ChooseConnectionToJoin );

	DebugPrintf("MENU_NEW_ChooseConnectionToJoin\n");  
	GetFormatInfo ( &MENU_NEW_ChooseConnectionToJoin );

	//DebugPrintf("MENU_NEW_ChangeBike\n");  
	//GetFormatInfo ( &MENU_NEW_ChangeBike );

	DebugPrintf("MENU_NEW_ChoosePlayer\n");  
	GetFormatInfo ( &MENU_NEW_ChoosePlayer );

	DebugPrintf("MENU_NEW_NewPlayer\n");  
	GetFormatInfo ( &MENU_NEW_NewPlayer );

	DebugPrintf("MENU_NEW_ChangePlayerName\n");  
	GetFormatInfo ( &MENU_NEW_ChangePlayerName );

	DebugPrintf("MENU_NEW_SelectBiker\n");  
	GetFormatInfo ( &MENU_NEW_SelectBiker );

	DebugPrintf("MENU_NEW_DemoPlayBack\n");  
	GetFormatInfo ( &MENU_NEW_DemoPlayBack );

	DebugPrintf("MENU_LoadSavedGame\n");  
	GetFormatInfo ( &MENU_LoadSavedGame );

	DebugPrintf("MENU_NEW_Sound\n");  
	GetFormatInfo ( &MENU_NEW_Sound );

	DebugPrintf("MENU_NEW_DemoCleaning\n");  
	GetFormatInfo ( &MENU_NEW_DemoCleaning );

	DebugPrintf("MENU_NEW_LoadGame\n");  
	GetFormatInfo ( &MENU_NEW_LoadGame );

	DebugPrintf("MENU_NEW_RestoreGame\n");  
	GetFormatInfo ( &MENU_NEW_RestoreGame );

	DebugPrintf("MENU_NEW_Team\n");  
	GetFormatInfo ( &MENU_NEW_Team );

	DebugPrintf("MENU_NEW_WatchTeamSelect\n");  
	GetFormatInfo ( &MENU_NEW_WatchTeamSelect );

	DebugPrintf("MENU_NEW_ChooseTeamForExistingGame\n");  
	GetFormatInfo ( &MENU_NEW_ChooseTeamForExistingGame );

	DebugPrintf("MENU_NEW_ChangeBikeComputer\n");  
	GetFormatInfo ( &MENU_NEW_ChangeBikeComputer );
};

#endif

void Shuffle_Y ( MENU *Menu, void *ptr, int *y )
{
	MENUITEM *item;

	for ( item = Menu->Item; item->x >= 0; item++ )
	{
		if ( ptr == item->Variable )
		{
			if ( item->TextInfo[ 0 ] )
			{
				item->TextInfo[ 0 ]->ymin = *y;
				*y += SESSIONJOIN_EXTRAS_LINEHEIGHT;
				item->TextInfo[ 0 ]->ymax = *y;
			}
			return;
		}
	}
}


// get game info for highlighted session
void UpdateSessionInfo( LIST *List )
{
	LPDPSESSIONDESC2 session;
	FILETIME FileTime;
	FILETIME LocalFileTime;
	SYSTEMTIME SystemTime;
	char *pchLevelNameSeperator;
	char *pchGameType;
	char *pchCTFSubType;
	char buf[ 128 ];
	int current_y;
	char *pCh;

	if ( IsKeyPressed( DIK_F1 ) )
	{
		if ( !RefreshDPlay() )
			MyGameStatus = STATUS_Title;	// because we will have been thrown back a menu

		InitMySessionsList();
		GetCurrentSessions( NULL );
	}

	Session_Info_Created[ 0 ] = 0;
	Session_Info_Level_Name[ 0 ] = 0;
	Session_Info_Num_Players[ 0 ] = 0;
	Session_Info_Game_Type[ 0 ] = 0;
	Session_Info_PacketInfo[ 0 ] = 0;
	Session_Info_LagTolerance[ 0 ] = 0;
	Session_Info_Server_BigMsg[ 0 ] = 0;

    Session_Info_Server[ 0 ] = 0;
	Session_Info_HarmTeamMates[ 0 ] = 0;
	Session_Info_MaxKills[ 0 ] = 0;
	Session_Info_TimeLimit[ 0 ] = 0;
	Session_Info_BrightShips[ 0 ] = 0;
	Session_Info_BikeExhausts[ 0 ] = 0;
	Session_Info_PPS[ 0 ] = 0;

	if ( SessionsList.selected_item < 0 )
	{
		return;
	}

	session = &Sessions[ SessionsList.selected_item ];
#if 1
	switch( session->dwUser3 & ServerGameStateBits )
	{
	case SERVER_STATE_NoServer:		
		break;
	case SERVER_STATE_NeedHost:		
		strncpy( Session_Info_Server_BigMsg, LT_Extra1/*"empty server session - select to host session on this server"*/, sizeof( Session_Info_Server_BigMsg ) );
		return;
	case SERVER_STATE_HostChoosing:	
		strncpy( Session_Info_Server_BigMsg, LT_Extra2/*"server session - host is selecting game type"*/, sizeof( Session_Info_Server_BigMsg ) );
		return;
	}
#endif

	// creation date:time
	if ( DosDateTimeToFileTime( ( WORD )( session->dwUser1 & 0xffff ), ( WORD )( ( session->dwUser1 >> 16 ) & 0xffff ), &FileTime ) )
	{
		// convert to local time...
		if ( FileTimeToLocalFileTime( &FileTime, &LocalFileTime ) )
		{
			if ( FileTimeToSystemTime( &LocalFileTime, &SystemTime ) )
			{
				sprintf( Session_Info_Created, LT_Extra3/*"session created %d-%d-%d at %02d:%02d"*/,
#ifdef MARKET_USA
					SystemTime.wMonth,
					SystemTime.wDay,
#else
					SystemTime.wDay,
					SystemTime.wMonth,
#endif
					SystemTime.wYear,
					SystemTime.wHour,
					SystemTime.wMinute
					);
			}
		}
	}

	// copy level name ( only if stored )
	pchLevelNameSeperator = strchr( SessionNames[ SessionsList.selected_item ], '~' );
	if ( pchLevelNameSeperator )
	{
		_snprintf( Session_Info_Level_Name, sizeof( Session_Info_Level_Name ), LT_Extra4/*"level: %s"*/, ++pchLevelNameSeperator );
	}

	// number of players

	if ( ( session->dwUser3 & ServerGameStateBits ) == SERVER_STATE_Joinable )
	{
		// if its a server game list the number of players as 1 less than it is..
		_snprintf( Session_Info_Num_Players, sizeof( Session_Info_Num_Players ), LT_Extra5/*"players: %d / %d"*/, session->dwCurrentPlayers-1, session->dwMaxPlayers-1 ); 
	}else{
		_snprintf( Session_Info_Num_Players, sizeof( Session_Info_Num_Players ), LT_Extra5/*"players: %d / %d"*/, session->dwCurrentPlayers, session->dwMaxPlayers ); 
	}

	// game type
    if ( session->dwUser3 & BombGameBit ) {
		pchGameType = LT_MENU_NEW_CreateGame15/*"tag"*/;
	} else if ( session->dwUser3 & CTFGameBit ) {
		pchGameType = LT_MENU_NEW_CreateGame11 /*"capture the flag"*/;
    } else if ( session->dwUser3 & FlagGameBit ) {
		pchGameType = LT_MENU_NEW_CreateGame12 /*"flag chase"*/;
    } else if ( session->dwUser3 & BountyGameBit ) {
		if ( session->dwUser3 & TeamGameBit )
		{
			pchGameType = LT_MENU_NEW_CreateGame14 /*"Team bounty hunt"*/;
		}else
		{
			pchGameType = LT_MENU_NEW_CreateGame13 /*"bounty hunt"*/;
		}
	} else {
		if ( session->dwUser3 & TeamGameBit )
		{
			pchGameType = LT_MENU_NEW_CreateGame10 /*"team game"*/;
		}else
		{
			pchGameType = LT_MENU_NEW_CreateGame9 /*"free for all"*/;
		}
	}

	// CTF sub type
	if ( session->dwUser3 & CTFGameBit )
	{
		switch ( CTF_Type_Decode( session->dwUser3 ) )
		{
		case CTF_STANDARD:
			pchCTFSubType = LT_CTF_Normal/*"normal"*/;
			break;
		case CTF_MUST_CARRY:
			pchCTFSubType = LT_CTF_MustCarry/*"carry it back"*/;
			break;
		case CTF_CAN_CARRY:
			pchCTFSubType = LT_CTF_CanCarry/*"can pick up"*/;
			break;
		case CTF_ONE_TOUCH:
			pchCTFSubType = LT_CTF_OneTouch/*"1 touch return"*/;
			break;
		case CTF_NO_RETURN:
			pchCTFSubType = LT_CTF_NoReturn/*"can't pick up"*/;
			break;
		default:
			pchCTFSubType = LT_CTF_Standard/*"standard"*/;
		}
	   
		_snprintf( buf, sizeof( buf ), " ( %s )", pchCTFSubType ); 
	}else
	{
		buf[ 0 ] = 0;
	}

	_snprintf( Session_Info_Game_Type, sizeof( Session_Info_Game_Type ), LT_Extra6/*"game: %s%s"*/, pchGameType, buf ); 

	_snprintf( Session_Info_PacketInfo, sizeof( Session_Info_PacketInfo ), LT_Extra7/*"packets: short %s, grouped %s"*/, 
		( session->dwUser3 & ShortPacketsBit ) ? LT_ToggleOn : LT_ToggleOff,
		( session->dwUser3 & BigPacketsBit ) ? LT_ToggleOn : LT_ToggleOff );
	

	switch( ( session->dwUser3 & CollisionTypeBits ) >> Collision_Type_BitShift )
	{
	case COLPERS_Forsaken:
		pCh = LT_ToggleOn/*on*/;
		break;
	case COLPERS_Descent:
		pCh = LT_ToggleOff/*off*/;
		break;
	case COLPERS_Server:
		pCh = LT_Server/*server*/;
		break;
	}

	_snprintf( Session_Info_LagTolerance, sizeof( Session_Info_LagTolerance ),LT_Extra8/*"lag tolerance: %s"*/, pCh );

	// shuffle up extra values...
	current_y = SESSIONJOIN_EXTRAS_TOP_Y;
	
	_snprintf( Session_Info_PPS, sizeof( Session_Info_PPS ), LT_Extra1b/*"%d packets per second"*/, ( session->dwUser4 & PacketsPerSecondBits ) >> PacketsPerSecond_Shift );
	Shuffle_Y ( CurrentMenu, Session_Info_PPS, &current_y );
	
	// server game?
	if ( ( session->dwUser3 & ServerGameStateBits ) == SERVER_STATE_Joinable )
	{
//		strcpy( Session_Info_Server, LT_Extra9/*"server based game"*/ );
//		current_y += SESSIONJOIN_EXTRAS_LINEHEIGHT;
		_snprintf( Session_Info_Server, sizeof( Session_Info_Server ), LT_Extra9/*"server based game"*/, ( session->dwUser3 & HarmTeamMatesBit ) ? LT_ToggleOn : LT_ToggleOff );
		Shuffle_Y ( CurrentMenu, Session_Info_Server, &current_y );
	}
	
	// harm team mates?
	if ( session->dwUser3 & TeamGameBit )
	{
		_snprintf( Session_Info_HarmTeamMates, sizeof( Session_Info_HarmTeamMates ), LT_Extra10/*"Harm Team Mates %s"*/, ( session->dwUser3 & HarmTeamMatesBit ) ? LT_ToggleOn : LT_ToggleOff );
		Shuffle_Y ( CurrentMenu, Session_Info_HarmTeamMates, &current_y );
	}
									  
	// max kills
	if ( ( session->dwUser2 & MaxKillsBits ) >> MaxKills_Shift )
	{
		_snprintf( Session_Info_MaxKills, sizeof( Session_Info_MaxKills ), LT_Extra11/*"kills limit %d ( current top %d )"*/, ( ( session->dwUser2 & MaxKillsBits ) >> MaxKills_Shift ), ( ( session->dwUser2 & CurrentMaxKillsBits ) >> CurrentMaxKills_Shift ) );
		Shuffle_Y ( CurrentMenu, Session_Info_MaxKills, &current_y );
	}

	// time limit
	if ( ( session->dwUser3 & GameTimeBit ) >> GameTimeBit_Shift ) 
	{
		_snprintf( Session_Info_TimeLimit, sizeof( Session_Info_TimeLimit ), LT_Extra12/*"time limit %d mins ( %d left )"*/, 
			( session->dwUser3 & GameTimeBit ) >> GameTimeBit_Shift ,
			( ( session->dwUser3 & CurrentGameTimeBits ) >> CurrentGameTime_Shift ) +
			( ( ( session->dwUser3 & GameTimeBit ) >> GameTimeBit_Shift == ( session->dwUser3 & CurrentGameTimeBits ) >> CurrentGameTime_Shift ) ? 0 : 1 ) );
			
		Shuffle_Y ( CurrentMenu, Session_Info_TimeLimit, &current_y );
	}

	// bright ships?
//	_snprintf( Session_Info_BrightShips, sizeof( Session_Info_BrightShips ),LT_Extra13/*"bright bikes: %s"*/, ( session->dwUser3 & BrightShipsBit ) ? LT_ToggleOn : LT_ToggleOff );
//	Shuffle_Y ( CurrentMenu, Session_Info_BrightShips, &current_y );

	// bike exhausts
	_snprintf( Session_Info_BikeExhausts, sizeof( Session_Info_BikeExhausts ),LT_Extra14/*"bike exhausts: %s"*/, ( session->dwUser3 & BikeExhaustBit ) ? LT_ToggleOn : LT_ToggleOff );
	Shuffle_Y ( CurrentMenu, Session_Info_BikeExhausts, &current_y );
	
}

void RefreshServerPlayersList( LIST *List )
{
	BYTE i;

	ServerGamePlayersList.items = 0;
	
	for ( i = 1; i < MAX_PLAYERS; i++ )	// server is player 0
	{
		if ( GameStatus[ i ] == STATUS_Normal )
		{
			strncpy( ServerGamePlayersList.item[ ServerGamePlayersList.items ], Names[ i ], sizeof( ServerGamePlayersList.item[ 0 ] ) );
			ServerGamePlayersWhoIAm[ ServerGamePlayersList.items ] = i;
			ServerGamePlayersList.items++;
		}
	}
}

void InitServerMenu( MENU *Menu )
{
	ServerGamePlayersList.display_items = 16;
	ServerGamePlayersList.selected_item = -1;
	ServerGamePlayersList.FuncInfo = RefreshServerPlayersList;
}

void ServerListPlayerSelected( MENUITEM *Item )
{
	// this is called directly after a player is selected
	SendGameMessage(MSG_YOUQUIT, 0, (BYTE) ServerGamePlayersWhoIAm[ServerGamePlayersList.selected_item] , 0, 0);

}

void AllowQuitForLobby( MENU *Menu )
{
	MENUITEM *item;

	for ( item = Menu->Item; item->x >=0; item++ )
	{
		if ( item->FuncSelect == SelectQuit )
		{
			if ( IsLobbyLaunched )
			{
				item->FuncDraw = DrawFlatMenuItem;
				item->highlightflags &= ~TEXTFLAG_Unselectable;
			}else
			{
				item->FuncDraw = NULL;
				item->highlightflags |= TEXTFLAG_Unselectable;
			}
		}
	}
}

void InitHostWaitingToStart( MENU *Menu )
{
	//MENUITEM *item;
	
	AllowQuitForLobby( Menu );

	GetInitialSessions( Menu );
	/*
	for ( item = Menu->Item; item->x >=0; item++ )
	{
	   if ( item->Value == &MENU_NEW_GeneralLoading )
	   {
		   if ( IsLobbyLaunched )
		   {
			   item->FuncSelect = NULL;
			   item->FuncDraw = NULL;
		   }else
		   {
			   item->FuncSelect = HostAboutToStart;
			   item->FuncDraw = DrawFlatMenuItem;
		   }
	   }
	}
	*/
} 

void ServerCleanup( void )
{
	ProcessGuaranteedMessages( FALSE, TRUE, TRUE );
	ProcessGuaranteedMessages( TRUE, FALSE, FALSE );
	ServiceServer( TRUE );
}

// use if server quits
void ResetServer( MENU *Menu )
{
	ServerCleanup();
	
	//MenuBackSpecific( &MENU_NEW_ChooseConnectionToStartServer, FALSE );	// ignore exit menu funcs
	MenuBackSpecific( &MENU_NEW_CreateGameServer, FALSE );	// ignore exit menu funcs
	
	DPlayRelease();

	MyGameStatus = STATUS_Title;
}

// use if pseudohost times out b4 starting game
void RestartServer( void )
{
	GUID spguid;
	int i;
	
	ServerCleanup();

	// store old sp GUID
	spguid = ServiceProvidersGuids[ServiceProvidersList.selected_item];

	MenuBackSpecific( &MENU_NEW_ChooseConnectionToStartServer, FALSE );	// ignore exit menu funcs

	DPlayRelease();

	MyGameStatus = STATUS_Title;

	MenuChangeEx( &MENU_NEW_ChooseConnectionToStartServer );

	// match up old sp GUID with one from new list ( not guaranteed to be in same order )
	for ( i = 0; i < MAXSERVICEPROVIDERS; i++ )
	{
		if ( !memcmp( &ServiceProvidersGuids[ i ], &spguid , sizeof(GUID) ) )
		{
			ServiceProvidersList.selected_item = i;
			SelectConnectionToStartServer( NULL );
			StartAHostSessionServer( NULL );	// packet rate etc. used will be same as b4 since they were stored in reg.
			return;
		}
	}

	// fuck.. could not find service provider we were just using!
	PrintErrorMessage( SERVER_FUCKED, 0, NULL, ERROR_QUIT );  
}


extern	DPID					dcoID;    // player id

void BackToJoinSession( MENUITEM *Item )
{

	MenuBackSpecific( &MENU_NEW_ChooseSessionToJoin, FALSE );	// ignore exit menu funcs
	
	if( dcoID )
	{
		DPlayDestroyPlayer(dcoID);
		dcoID = 0;
	}
  
	DPlayRelease();
	
	MyGameStatus = STATUS_Title;

	RefreshDPlay();

	OKToJoinSession = FALSE;
}


BOOL GeneralTimeout( float *timer )
{
	char buf[ 64 ];

	*timer -= framelag;

	if ( *timer < 0.0F )
	{
		return TRUE;
	}else
	{
 		sprintf( buf, "%d", (int)( *timer / 60.0F ) );
		Print4x5Text( buf, 10, 10, 2 );
	}

	return FALSE;
}



float Server_Timeout;
//#define SERVER_WAIT_TIME 7200.0F	// 2 minutes ( sort of!! ) 
//#define SERVER_WAIT_TIME2 18000.0F	// 5 minutes ( sort of!! ) 

#define SERVER_TIMEOUT_Reset 0
#define SERVER_TIMEOUT_Start 1

uint8 ServerTimeoutAction = SERVER_TIMEOUT_Start;

void InitServerWaitingForGameParameters( MENU *Menu )
{
	//Server_Timeout = SERVER_WAIT_TIME;
	Server_Timeout = (float)PseudoHostTimeoutSlider1.value * 60.0F * 60.0F;
}

void ServerCountDown( int *dummy )
{
	if ( GeneralTimeout( &Server_Timeout ) )
	{
		RestartServer();
	}
}

void InitServerWaitingToStartGame( MENU *Menu )
{
	//Server_Timeout = SERVER_WAIT_TIME2;
	Server_Timeout = (float)PseudoHostTimeoutSlider2.value * 60.0F * 60.0F;
}

void ServerCountDown2( int *dummy )
{
	if ( GeneralTimeout( &Server_Timeout ) )
	{
		switch ( ServerTimeoutAction )
		{
		case SERVER_TIMEOUT_Start:
			// start game...
			MyGameStatus = STATUS_WaitingToStartMultiPlayerHost;
			MenuChangeEx( &MENU_NEW_GeneralLoading );
			break;
		case SERVER_TIMEOUT_Reset:
		default:
			RestartServer();
		}
	}
}

float PseudoHostAck_Timeout;

void InitPseudoHostWaitingForAck( MENU *Menu )
{
	PseudoHostAck_Timeout = PSEUDOHOST_WAIT_TIME;
}

void PseudoHostWaitingForAckTimer( int *dummy )
{
   	if ( GeneralTimeout( &PseudoHostAck_Timeout ) )
	{
		ChangeServiceProviderPseudoHost( NULL );
		MenuBack();
	}
}

void MenuReleaseDPlay( MENU *Menu )
{
	DPlayRelease();
}

void TitleReset( MENUITEM *item )
{
	MenuAbort();
	SetInitialTitleParams();
	PlaceObjects();
	TitleInitDone = FALSE;
	CameraStatus = CAMERA_AtStart;
	QuickStart = QUICKSTART_None;
}

void SetTitleNotify( char *str )
{
	strncpy( NotifyMessage, str, sizeof( NotifyMessage ) );
	QuickStart = QUICKSTART_Notify;
}

void InitInGameLevelSelect( MENU *menu )
{
	MENUITEM *item;

	for ( item = menu->Item; item->x >= 0; item++ )
	{
		if ( item->FuncDraw == DrawToggle )
		{
			if ( IsServerGame && !IsServer )
			{
				item->Variable = &IsPseudoHost;
			}else
			{
				item->Variable = &IsHost;
			}
		}
	}
}

extern DWORD MaxPacketsInQue;

void ResetThrottle( MENUITEM *item )
{
	MaxPacketsInQue = 0;	
}

void StoreThrottleSettings( MENUITEM *item )
{
	DWORD temp;

	temp = ( DWORD )ThrottleSlider.value;
	RegSet( "ThrottleSlider",  (LPBYTE)&temp ,  sizeof(temp) );
}

void InitBattleMenu( MENU *menu )
{
	MENUITEM *item;

	for ( item = menu->Item; item->x >= 0; item++ )
	{
		switch ( item->y  )
		{
		case TITLE_MODEL_Disc4:
			if ( AllowServer )
			{
				item->StrPnt = LT_MENU_NEW_Battle4;
				item->FrameNo = 6;
				item->Value = &MENU_NEW_ChooseConnectionToStartServer;
				item->FuncSelect = MenuChange;
			}
			else
			{
				item->StrPnt = LT_MENU_NEW_Battle3;
				item->FrameNo = 2;
				item->Value = NULL;
				item->FuncSelect = MenuItemBack;
			}
			break;
		case TITLE_MODEL_Disc5:
			if ( AllowServer )
			{
				item->StrPnt = LT_MENU_NEW_Battle3;
				item->FrameNo = 3;
				item->Value = NULL;
				item->FuncSelect = MenuItemBack;
			}
			else
			{
				item->StrPnt = "Blank";
				item->FrameNo = 2;
				item->Value = NULL;
				item->FuncSelect = NULL;
			}
			break;
		}
	}
}


//#pragma optimize( "", off )

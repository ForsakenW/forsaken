/*
 * The X Men, June 1996
 * Copyright (c) 1996 Probe Entertainment Limited
 * All Rights Reserved
 *
 * $Revision: 688 $
 *
 * $Header: /PcProjectX/Mydplay.c 688   11/11/98 16:00 Philipy $
 *
 * $Log: /PcProjectX/Mydplay.c $
 * 
 * 688   11/11/98 16:00 Philipy
 * various fixes for warnings / errors when compiling under VC6
 * 
 * 687   5/11/98 10:09 Phillipd
 * Ping frig for idiots......
 * 
 * 686   23/10/98 12:29 Phillipd
 * 
 * 685   23/10/98 9:34 Phillipd
 * 
 * 684   22/10/98 17:33 Phillipd
 * 
 * 683   22/10/98 14:35 Phillipd
 * 
 * 682   22/10/98 11:35 Phillipd
 * 
 * 681   21/10/98 17:27 Phillipd
 * 
 * 680   21/10/98 12:39 Phillipd
 * 
 * 679   21/10/98 11:06 Phillipd
 * 
 * 678   21/10/98 11:00 Phillipd
 * 
 * 677   21/10/98 10:58 Phillipd
 * 
 * 676   20/10/98 17:17 Phillipd
 * 
 * 675   20/10/98 10:39 Phillipd
 * 
 * 674   17/09/98 15:27 Phillipd
 * 
 * 673   17/09/98 10:39 Phillipd
 * 
 * 672   14/09/98 15:35 Philipy
 * added facility for server based collisions
 * 
 * 671   14/09/98 15:16 Phillipd
 * 
 * 670   14/09/98 12:42 Phillipd
 * 
 * 669   10/09/98 10:52 Philipy
 * fixed bug in ping stuff
 * changed checksum kicking out to use in game message ( now also works in
 * peer-peer )
 * 
 * 668   4/09/98 17:07 Philipy
 * 
 * 667   4/09/98 17:06 Philipy
 * 
 * 666   4/09/98 17:02 Philipy
 * 
 * 665   3/09/98 17:34 Philipy
 * fixed server lag tolerance bug
 * 
 * 664   3/09/98 9:31 Philipy
 * somw Gamespy fixes
 * added Session ( GUID ) and TCP command line flags
 * added TRACKER_NAME facility
 * 
 * 663   2/09/98 9:50 Philipy
 * added throttle rate slider
 * some Gamespy changes
 * 
 * 662   1/09/98 10:21 Phillipd
 * 
 * 661   28/08/98 11:45 Philipy
 * added auto throttle
 * 
 * 660   27/08/98 20:12 Philipy
 * manual / auto server mode now selectable from menus
 * text now displayed when server in game & not rendering
 * dynamic PPS setting re-enabled for server
 * 
 * 659   27/08/98 17:26 Philipy
 * Pseudohost can select level, & migrates on quitting
 * players booted to titles due to not having new level are now informed
 * 
 * 658   26/08/98 17:06 Philipy
 * tracker now migrates along with host
 * 
 * 657   26/08/98 12:07 Philipy
 * message now displayed when server boots you out due to invalid CRC
 * 
 * 656   25/08/98 15:44 Phillipd
 * 
 * 655   18/08/98 18:14 Philipy
 * all pings in server game are now from server perspective
 * windowed mode re-enabled ( still needs some work )
 * 
 * 654   18/08/98 16:19 Philipy
 * 
 * 653   18/08/98 15:48 Philipy
 * fixed bug where many MSG_STATUS were sent for obscure PPS values
 * 
 * 652   18/08/98 9:38 Phillipd
 * 
 * 651   17/08/98 18:00 Philipy
 * removed loads of unreferenced local variables
 * 
 * 650   17/08/98 17:13 Philipy
 * added -ServerChoosesGame & ServerAutoStart command line options
 * 
 * 649   14/08/98 16:15 Philipy
 * heartbeat now migrates with host
 * 
 * 648   14/08/98 15:29 Philipy
 * 
 * 647   14/08/98 15:25 Philipy
 * added trilinear option to menus
 * fixed level name / shutdown packet in heartbeat
 * 
 * 
 * 646   14/08/98 9:13 Phillipd
 * DirectX6 is in effect.......
 * 
 * 645   13/08/98 12:52p Oliverc
 * Fixed bounty bonus off bug
 * 
 * 644   11/08/98 17:22 Philipy
 * pings sent in heartbeat packet are now obtained from normal
 * MSG_PINGREQUEST.
 * pings requests are always sent even if not shown if you are the server,
 * or you are responding to UDP status requests, or if you are sending out
 * heartbeat packets.
 * 
 * 643   5/08/98 15:58 Philipy
 * 
 * 642   5/08/98 11:04 Philipy
 * added AutoStart facility ( joins game based on GUID in registery )
 * upped patch version to 1.02
 * 
 * 641   3/08/98 14:10 Phillipd
 * 
 * 640   31/07/98 16:17 Philipy
 * added PPS to session desc
 * 
 * 639   31/07/98 12:17 Philipy
 * 
 * 638   31/07/98 9:50 Phillipd
 * 
 * 637   30/07/98 17:08 Philipy
 * 
 * 636   30/07/98 16:40 Philipy
 * 
 * 635   30/07/98 16:39 Phillipd
 * 
 * 634   30/07/98 16:38 Phillipd
 * 
 * 633   30/07/98 16:16 Phillipd
 * 
 * 632   30/07/98 15:44 Phillipd
 * 
 * 631   30/07/98 14:17 Phillipd
 * 
 * 630   30/07/98 11:42 Phillipd
 * 
 * 629   30/07/98 11:21 Philipy
 * 
 * 628   30/07/98 10:52 Phillipd
 * 
 * 627   28/07/98 16:09 Philipy
 * last status msg sent is now guaranteed
 * 
 * 626   28/07/98 14:44 Philipy
 * all server timeouts now configurable
 * 
 * 625   28/07/98 10:39 Philipy
 * Max players now works properly for server games
 * 
 * 624   24/07/98 12:02 Philipy
 * fixed frag limit for server based games
 * 
 * 623   24/07/98 11:34 Collinsd
 * Fixed dropping of pickups and scattering them again
 * 
 * 622   23/07/98 15:51 Philipy
 * CTF subtype now set b4 calling SetUpGameType
 * 
 * 621   23/07/98 15:38 Philipy
 * server now resets if no packets recieved for 5 mins
 * 
 * 620   23/07/98 14:35 Phillipd
 * 
 * 619   23/07/98 14:20 Phillipd
 * all non specific sent messages get put in the big packet.....
 * 
 * 618   22/07/98 14:18 Phillipd
 * 
 * 617   22/07/98 12:34 Collinsd
 * Fixed player dropping pickups in server game.
 * 
 * 616   22/07/98 10:36 Phillipd
 * 
 * 615   21/07/98 17:31 Philipy
 * added timeout stuff for titles
 * 
 * 614   21/07/98 11:45 Philipy
 * 
 * 613   21/07/98 11:45 Philipy
 * 
 * 612   17/07/98 17:21 Phillipd
 * 
 * 611   7/16/98 12:25p Phillipd
 * 
 * 610   16/07/98 11:48 Philipy
 * 
 * 609   7/16/98 10:50a Phillipd
 * 
 * 608   7/16/98 10:16a Phillipd
 * 
 * 607   15/07/98 16:25 Philipy
 * now handles pseudohost quitting in titles & server quitting ( in
 * titiles or in game )
 * 
 * 606   7/15/98 4:24p Phillipd
 * 
 * 605   7/15/98 9:53a Phillipd
 * 
 * 604   7/15/98 9:13a Phillipd
 * 
 * 603   14/07/98 17:56 Philipy
 * fixed pseudohost quitting in titles bug ( if server recieves
 * MSG_GAMEPARAM after pseudohost has quit )
 * 
 * 602   7/14/98 5:07p Phillipd
 * 
 * 601   7/14/98 4:10p Phillipd
 * 
 * 600   7/14/98 4:05p Phillipd
 * 
 * 599   7/14/98 12:24p Phillipd
 * 
 * 598   14/07/98 12:16 Philipy
 * 
 * 597   14/07/98 11:15 Philipy
 * various patch bugs
 * pseudohost quitting in titles
 * 
 * 596   7/14/98 9:09a Phillipd
 * 
 * 595   7/13/98 5:45p Phillipd
 * 
 * 594   7/13/98 5:45p Phillipd
 * 
 * 593   7/13/98 5:36p Phillipd
 * 
 * 592   13/07/98 16:48 Oliverc
 * Fixed "no points for killing player without bounty" bug
 * 
 * 591   7/13/98 3:42p Phillipd
 * 
 * 590   7/13/98 2:24p Phillipd
 * 
 * 589   7/13/98 2:09p Phillipd
 * 
 * 588   7/13/98 12:31p Phillipd
 * 
 * 587   7/13/98 10:22a Phillipd
 * 
 * 586   13/07/98 9:55 Collinsd
 * 
 * 585   7/13/98 9:20a Phillipd
 * 
 * 584   7/10/98 10:54a Phillipd
 * 
 * 583   7/09/98 11:50a Phillipd
 * 
 * 582   7/08/98 2:46p Phillipd
 * 
 * 581   7/08/98 11:56a Phillipd
 * 
 * 580   8/07/98 9:31 Oliverc
 * Converted multiplayer bounty and flag games to server operation for
 * patch
 * 
 * 579   7/07/98 18:05 Philipy
 * added lobby autostart code ( when all players have recieved init msg )
 * added num primary weapons menu option ( propergated to other players &|
 * server )
 * extracted new title text for localisation
 * 
 * 578   7/07/98 14:14 Collinsd
 * Fixed missed serverkillpickup messages when dynamically joining.
 * 
 * 577   3/07/98 14:29 Collinsd
 * Moved HostRestoreAmmo and Weapons into scatterweaponsforship
 * 
 * 576   3/07/98 11:54 Philipy
 * heartbeat & quickstart stuff
 * 
 * 575   7/03/98 11:26a Phillipd
 * 
 * 574   7/03/98 11:23a Phillipd
 * 
 * 573   2/07/98 17:45 Collinsd
 * 
 * 572   7/02/98 5:42p Phillipd
 * 
 * 571   7/02/98 5:22p Phillipd
 * 
 * 570   7/02/98 5:11p Phillipd
 * 
 * 569   7/02/98 4:56p Phillipd
 * 
 * 568   7/02/98 4:54p Phillipd
 * 
 * 567   7/02/98 4:34p Phillipd
 * 
 * 566   7/02/98 4:34p Phillipd
 * 
 * 565   7/02/98 4:30p Phillipd
 * 
 * 564   7/02/98 3:53p Phillipd
 * 
 * 563   2/07/98 10:37 Collinsd
 * Correction code now in.
 * 
 * 562   7/01/98 4:37p Phillipd
 * 
 * 561   7/01/98 3:36p Phillipd
 * 
 * 560   7/01/98 3:35p Phillipd
 * 
 * 559   1/07/98 15:29 Collinsd
 * Hopefully fixed bug that lost pickups.
 * 
 * 558   30/06/98 10:38 Collinsd
 * Better
 * 
 * 557   6/30/98 10:38a Phillipd
 * 
 * 556   6/30/98 10:26a Phillipd
 * 
 * 555   26/06/98 17:45 Collinsd
 * Added server debug info.
 * 
 * 554   6/26/98 2:28p Phillipd
 * 
 * 553   6/26/98 2:06p Phillipd
 * Shield and hull are now checked by the server.....
 * 
 * 552   26/06/98 10:54 Collinsd
 * Server Pickups and weapons works pretty well, death mode pickups thrown
 * out, as well as scattered.  Quitting/Crash players throw out all
 * pickups.
 * 
 * 551   22/06/98 9:39 Collinsd
 * Added new message for ship exploding.
 * 
 * 550   6/19/98 2:39p Phillipd
 * 
 * 549   6/19/98 12:37p Phillipd
 * 
 * 548   17/06/98 19:33 Philipy
 * more win98 stuff
 * 
 * 547   13/06/98 20:46 Philipy
 * improved lobby support:
 * host now migrates properly
 * you can quit b4 starting game without screwing up session
 * 
 * 546   11/06/98 16:57 Philipy
 * loads of win98 shareware version stuff
 * 
 * 545   6/11/98 10:09a Phillipd
 * 
 * 544   11/06/98 9:54 Philipy
 * files checked in prior to starting Win98 shareware version
 * 
 * 543   11/06/98 9:48 Collinsd
 * Orbitals now work in server game.
 * 
 * 542   6/10/98 3:16p Phillipd
 * 
 * 541   6/10/98 9:55a Phillipd
 * server game  Guaranteed messages are now just sent to the server once
 * the
 * server then propagates them to everyone elese Guaranteed...
 * 
 * 540   9/06/98 16:35 Collinsd
 * Fixed Lumberjack bug 
 * 
 * 539   9/06/98 11:23 Philipy
 * server now reset if pseudohost does not have any valid levels
 * fixed timed game bug for server based games
 * 
 * 538   8/06/98 16:34 Collinsd
 * 
 * 537   8/06/98 15:45 Collinsd
 * Done more on Server mode and Fixed trojax ammo usage
 * 
 * 536   8/06/98 12:28 Philipy
 * server levels now sent across to pseudohost. Pseudohost can only pick
 * valid levels
 * 
 * 535   6/04/98 10:49a Phillipd
 * 
 * 534   3/06/98 15:30 Philipy
 * added server in game options for rendering on/off and selecting players
 * pseudohost can now select if server does collisions. This gets
 * propagated in MSG_GameParams and MSG_Init
 * 
 * 533   6/03/98 2:45p Phillipd
 * 
 * 532   6/03/98 2:28p Phillipd
 * 
 * 531   22/05/98 17:51 Philipy
 * more work on session info
 * 
 * 530   22/05/98 15:06 Collinsd
 * Server Pickup work
 * 
 * 529   21/05/98 16:52 Collinsd
 * Pickups controlled by host ( Sort of ).
 * 
 * 528   21/05/98 10:07 Philipy
 * fix to MSG_INIT for server game
 * 
 * 527   21/05/98 9:10 Collinsd
 * Pickup server stuff started
 * 
 * 526   20/05/98 9:39 Philipy
 * implemented front end server menus
 * removed ( invalid ) ping from sessions menu
 * changed EnumPlayers so that it solely uses MSG_NAME
 * 
 * 525   5/14/98 3:36p Phillipd
 * 
 * 524   5/14/98 2:37p Phillipd
 * 
 * 523   5/14/98 2:33p Phillipd
 * 
 * 522   5/13/98 3:17p Phillipd
 * 
 * 521   5/12/98 4:04p Phillipd
 * 
 * 520   5/11/98 4:59p Phillipd
 * 
 * 519   11/05/98 15:15 Philipy
 * added session info stuff ( game type, ping etc )
 * 
 * 518   5/11/98 2:40p Phillipd
 * 
 * 517   5/11/98 12:29p Phillipd
 * 
 * 516   5/11/98 10:16a Phillipd
 * 
 * 515   5/05/98 10:35a Phillipd
 * 
 * 514   5/05/98 9:05a Phillipd
 * Ship died messages are now guarenteed
 * 
 * 513   4/27/98 4:01p Phillipd
 * 
 * 512   4/17/98 11:26a Phillipd
 * 
 * 511   4/15/98 10:38a Phillipd
 * 
 * 510   4/15/98 9:27a Phillipd
 * 
 * 509   4/14/98 5:45p Phillipd
 * 
 * 508   4/14/98 3:54p Phillipd
 * 
 * 507   11/04/98 11:52 Collinsd
 * 
 * 506   4/10/98 10:17p Phillipd
 * 
 * 505   10/04/98 21:58 Collinsd
 * 
 * 504   10/04/98 21:35 Collinsd
 * 
 * 503   10/04/98 21:14 Collinsd
 * 
 * 502   10/04/98 17:07 Collinsd
 * 
 * 501   4/10/98 12:43p Phillipd
 * 
 * 500   4/09/98 4:37p Phillipd
 * 
 * 499   9/04/98 16:11 Philipy
 * team scores now propagate
 * 
 * 498   4/09/98 12:23p Phillipd
 * 
 * 497   4/08/98 2:45p Phillipd
 * 
 * 496   4/07/98 5:11p Phillipd
 * 
 * 495   4/07/98 4:42p Phillipd
 * 
 * 494   4/07/98 3:20p Phillipd
 * 
 * 493   4/06/98 7:24p Phillipd
 * 
 * 492   4/06/98 7:06p Phillipd
 * 
 * 491   4/06/98 5:02p Phillipd
 * 
 * 490   4/06/98 3:21p Phillipd
 * 
 * 489   4/06/98 2:50p Phillipd
 * 
 * 488   6/04/98 14:12 Collinsd
 * Quitting when in god mode no longer throws out all pickups
 * 
 * 487   4/06/98 12:43p Phillipd
 * 
 * 486   4/06/98 12:39p Phillipd
 * 
 * 485   4/06/98 10:09a Phillipd
 * 
 * 484   4/06/98 9:39a Phillipd
 * 
 * 483   5/04/98 17:10 Collinsd
 * Hacked demos to work.
 * 
 * 482   4/05/98 2:33p Phillipd
 * 
 * 481   4/04/98 10:18p Phillipd
 * 
 * 480   4/04/98 8:16p Phillipd
 * 
 * 479   4/04/98 8:01p Phillipd
 * 
 * 478   4/04/98 5:38p Phillipd
 * 
 * 477   4/04/98 1:06p Phillipd
 * 
 * 476   3/04/98 16:37 Collinsd
 * Done titan shrapnel as one message,
 * 
 * 475   4/03/98 3:33p Phillipd
 * Short hit message now in...
 * 
 * 474   3/04/98 13:13 Philipy
 * Taunts are now affected by biker volume slider ( taunt volume slider
 * removed )
 * Enemy bikers now give out death cry
 * fixed problem with speech ignoring volume settings
 * fixed end game sequences
 * 
 * 473   2/04/98 21:06 Philipy
 * Added taunts ( single & multiplayer, plus enemy biker taunts )
 * added flygirl to front end.
 * sliders for biker, bike computer and taunt speech volume
 * added new sfx for title
 * 
 * 472   4/02/98 4:57p Phillipd
 * 
 * 471   4/02/98 4:53p Phillipd
 * 
 * 470   4/02/98 4:53p Phillipd
 * 
 * 469   4/02/98 4:52p Phillipd
 * 
 * 468   4/02/98 4:47p Phillipd
 * 
 * 467   4/02/98 12:53p Phillipd
 * 
 * 466   4/02/98 11:50a Phillipd
 * 
 * 465   1/04/98 11:44 Collinsd
 * Invulnerability effect now no longer appears in demos. and god mode
 * works properly over multiple levels.
 * 
 * 464   3/31/98 3:48p Phillipd
 * 
 * 463   3/31/98 3:37p Phillipd
 * 
 * 462   3/28/98 2:06p Phillipd
 * 
 * 461   27/03/98 15:52 Collinsd
 * HarmTeamMates now sent accross.
 * 
 * 460   3/27/98 4:38p Phillipd
 * 
 * 459   3/27/98 4:20p Phillipd
 * 
 * 458   3/27/98 12:37p Phillipd
 * sfx added
 * 
 * 457   24/03/98 16:20 Philipy
 * added new sfx
 * 
 * 456   3/23/98 10:39a Phillipd
 * 
 * 455   3/21/98 2:42p Phillipd
 * 
 * 454   3/21/98 2:34p Phillipd
 * 
 * 453   3/18/98 4:32p Phillipd
 * 
 * 452   3/18/98 3:31p Phillipd
 * 
 * 451   3/17/98 4:05p Phillipd
 * 
 * 450   3/17/98 2:59p Phillipd
 * 
 * 449   3/17/98 12:31p Phillipd
 * Host crash when killing a phantom light attached to a player fixed
 * 
 * 448   17/03/98 12:11 Collinsd
 * 
 * 447   16/03/98 16:39 Collinsd
 * Random pickups now work ( honest ).
 * 
 * 446   16/03/98 12:19 Collinsd
 * Random Pickups option added.  Sphere dislpay of trigger areas
 * 
 * 445   14/03/98 18:58 Collinsd
 * Added godmode and made debug mode work even when you change level.
 * 
 * 444   3/14/98 3:32p Phillipd
 * bmp files for textures are now supported...
 * 
 * 443   14/03/98 14:06 Collinsd
 * Scatter works with Collision Perspective.
 * 
 * 442   12/03/98 21:52 Collinsd
 * Added cheatmodes for primary and seconadry weapons.
 * 
 * 441   3/11/98 5:11p Phillipd
 * 
 * 440   3/11/98 4:09p Phillipd
 * 
 * 439   11/03/98 12:07 Oliverc
 * Fixed bugs in CTF and bounty messages
 * 
 * 438   10/03/98 16:32 Collinsd
 * 
 * 437   10/03/98 16:29 Collinsd
 * 
 * 436   10/03/98 15:54 Collinsd
 * Qued Mines now work.
 * 
 * 435   9/03/98 20:44 Oliverc
 * Enabled team goal message
 * 
 * 434   3/09/98 4:31p Phillipd
 * 
 * 433   9/03/98 10:48 Collinsd
 * Timer for level now on triggers.
 * 
 * 432   7/03/98 19:37 Oliverc
 * Added BikeExhausts display option to multiplayer INITMSG
 * 
 * 431   7/03/98 15:56 Collinsd
 * Added new message for olly ( TeamGoals ) Also added pos and group to
 * explodesecondary.
 * 
 * 430   7/03/98 16:32 Oliverc
 * Fixed bug: CTF type now sent to joining players in INITMSG
 * 
 * 429   3/07/98 2:00p Phillipd
 * 
 * 428   3/07/98 12:09p Phillipd
 * Changing the lpDplayLobby pointer from version 2 to 1 was not a good
 * idead Phil
 * Hacking out our normal lobby code so it worked with this new pointer
 * was an even worse idea.....
 * Not checking it before checking it in was your worsed idea...
 * 
 * 427   6/03/98 19:38 Oliverc
 * Initialised BadConnection[] in SetupDplayGame()
 * 
 * 426   6/03/98 17:37 Philipy
 * implemented ability to run when launched by lobby
 * 
 * 425   3/06/98 5:29p Phillipd
 * 
 * 424   3/06/98 4:27p Phillipd
 * 
 * 423   3/06/98 4:06p Phillipd
 * 
 * 422   3/06/98 3:33p Phillipd
 * 
 * 421   3/06/98 3:16p Phillipd
 * 
 * 420   3/06/98 3:00p Phillipd
 * 
 * 419   3/05/98 12:47p Phillipd
 * 
 * 418   4/03/98 12:33 Oliverc
 * CTF mode fully enabled
 * 
 * 417   3/03/98 16:59 Oliverc
 * New multiplayer CTF mode stuff (1st attempt)
 * 
 * 416   3/03/98 3:12p Phillipd
 * 
 * 415   3/03/98 2:27p Phillipd
 * Clean now works for VeryShortPackets
 * 
 * 414   3/03/98 11:32a Phillipd
 * 
 * 413   2/03/98 21:13 Collinsd
 * No longer use multiple bit or secfire.
 * 
 * 412   3/02/98 5:17p Phillipd
 * 
 * 411   3/02/98 11:55a Phillipd
 * 
 * 410   2/28/98 1:18p Phillipd
 * 
 * 409   2/28/98 1:09p Phillipd
 * 
 * 408   2/28/98 12:57p Phillipd
 * 
 * 407   2/28/98 11:26a Phillipd
 * 
 * 406   27/02/98 16:35 Collinsd
 * Possible bug in message code.
 * 
 * 405   2/26/98 4:50p Phillipd
 * 
 * 404   26/02/98 9:29 Oliverc
 * Disabled Bombtag
 * Fixed pickup flags bug
 * Disabled logos for EXTERNAL_DEMOs
 * 
 * 403   2/25/98 5:25p Phillipd
 * 
 * 402   2/25/98 3:18p Phillipd
 * 
 * 401   2/25/98 2:34p Phillipd
 * Guaranteed message now much easier......
 * 
 * 400   2/25/98 11:13a Phillipd
 * 
 * 399   2/25/98 10:52a Phillipd
 * 
 * 398   2/25/98 10:50a Phillipd
 * 
 * 397   24/02/98 22:00 Oliverc
 * Tweaks to multiplayer games
 * 
 * 396   24/02/98 16:54 Oliverc
 * 1st attempt at bounty hunt multiplayer game
 * 
 * 395   23/02/98 21:20 Collinsd
 * Optimised Load/Save Functions.
 * 
 * 394   21/02/98 18:28 Philipy
 * 
 * 393   21/02/98 16:24 Philipy
 * added text messages for capture flag
 * 
 * 392   20/02/98 15:28 Philipy
 * re-implented AVI
 * splash screens can now play demos and AVIs
 * 
 * 391   19/02/98 22:00 Collinsd
 * Added flygirl biker.
 * 
 * 390   18/02/98 11:53 Oliverc
 * First feature-complete version of force feedback joystick code
 * 
 * 389   11/02/98 16:29 Collinsd
 * Added soundfx for bikes/enemies
 * 
 * 388   11/02/98 12:57 Philipy
 * Changed PlaySfx calls to use Vol instead of Dist
 * 
 * 387   10/02/98 12:13 Philipy
 * added collision type to MSG_INIT
 * 
 * 386   9/02/98 18:29 Collinsd
 * Fixed damage after death, spinning caused by damage, and passing
 * through mines.
 * 
 * 385   2/07/98 1:23p Phillipd
 * 
 * 384   2/02/98 20:08 Philipy
 * added configurable quick text message buttons
 * 
 * 383   2/02/98 4:11p Phillipd
 * 
 * 382   1/29/98 2:27p Phillipd
 * Demo can now be saved to ram....and can be saved if your not the
 * host...
 * 
 * 381   28/01/98 23:28 Oliverc
 * Fixed bug in SHAREWARE taunts
 * 
 * 380   27/01/98 11:05 Philipy
 * fixed team game stuff
 * 
 * 379   1/27/98 10:09a Phillipd
 * 
 * 378   27/01/98 9:55 Collinsd
 * Bodyparts created if player goes from normal mode to limbo mode in one
 * go.
 * 
 * 377   26/01/98 18:34 Philipy
 * Opps! - fixed bug with new splashscreen stuff
 * 
 * 376   26/01/98 18:23 Philipy
 * fixed video memory leaks
 * splash screens now display after release view, and call InitScene,
 * InitView after  completion
 * 
 * 375   23/01/98 15:15 Oliverc
 * Fixed bug (player bikes + names only changed when in demo playback)
 * 
 * 374   22/01/98 22:40 Oliverc
 * Force bike in SHAREWARE demo playback to use only those bikes (and
 * corresponding player names) allowed in SHAREWARE version
 * 
 * 373   22/01/98 19:15 Philipy
 * put #idef SHAREWARE around splash screen after demo
 * 
 * 372   22/01/98 11:57 Collinsd
 * Added DoDamage override invul.
 * 
 * 371   21/01/98 18:05 Philipy
 * speech now happens less
 * 
 * 370   21/01/98 17:27 Philipy
 * attract mode splash screen stuff
 * 
 * 369   21/01/98 12:19 Philipy
 * Added attract mode for shareware
 * fixed looping sfx volume bug
 * 
 * 368   1/19/98 4:21p Phillipd
 * Bright Ships flag added.....
 * 
 * 367   19/01/98 11:48 Collinsd
 * Fixed Mines dissapearing.
 * 
 * 366   18/01/98 23:38 Philipy
 * victory phrase played on killing a player. Phrase also played after
 * respawn sfx
 * 
 * 365   1/16/98 5:43p Phillipd
 * 
 * 364   15/01/98 17:03 Philipy
 * changed PlayPannedSfx calls to use float for freq
 * 
 * 363   15/01/98 16:38 Collinsd
 * Fixed qued mines/pickups bug when joining an existing game.
 * 
 * 362   1/15/98 4:06p Phillipd
 * 
 * 361   15/01/98 15:53 Collinsd
 * ????????
 * 
 * 360   15/01/98 12:51 Collinsd
 * Time now works when people join an existing timed game.  Crystals
 * reinitialised.  Damage Flash only in Normal_Mode.
 * 
 * 359   15/01/98 10:15 Collinsd
 * Hopefully fixed link list fuckup.  Pickups can only be generated once.
 * Started of fixing mine bug.  Updated MX, MXA and Spotfx formats.
 * 
 * 358   1/13/98 12:25p Phillipd
 * 
 * 357   10/01/98 15:55 Collinsd
 * ScreenFlashed moved to dodamage.
 * 
 * 356   1/10/98 1:44p Phillipd
 * Quick Fix
 * 
 * 355   1/09/98 10:43a Phillipd
 * 
 * 354   1/09/98 10:31a Phillipd
 * Bugs fixed......
 * 
 * 353   8/01/98 19:32 Philipy
 * removed debug message
 * 
 * 352   6/01/98 15:39 Collinsd
 * Taken out bike stuff for shareware
 * 
 * 351   1/05/98 3:18p Phillipd
 * More sfx...
 * 
 * 350   5/01/98 10:37 Philipy
 * speech sfx implemented - currently defaults to 1 biker & computer only,
 * none selectable
 * 
 * 349   12/20/97 5:03p Phillipd
 * 
 * 348   12/20/97 12:43p Phillipd
 * Levelname is now sent across for a level change in Multiplayer....
 * Enemies dont appear in Multiplayer Games....
 * 
 * 347   12/19/97 12:36p Phillipd
 * 
 * 346   12/19/97 11:14a Phillipd
 * 
 * 345   12/18/97 5:37p Phillipd
 * 
 * 344   12/18/97 2:46p Phillipd
 * 
 * 343   12/17/97 5:19p Phillipd
 * 
 * 342   12/12/97 10:22a Phillipd
 * Packets per second now dynamic
 * 
 * 341   11/12/97 15:53 Collinsd
 * Fixed enemy mines that didn't hurt you.  Also fixed enemy homing
 * missile.
 * 
 * 340   12/11/97 2:11p Phillipd
 * Taken out the comments for Guarenteed packets....
 * 
 * 339   12/10/97 10:39a Phillipd
 * Players names are now propergated across the network when changed...
 * Difficulty levels are functional....
 * 
 * 338   12/09/97 12:10p Phillipd
 * 
 * 337   12/08/97 3:49p Phillipd
 * 
 * 336   12/08/97 11:34a Phillipd
 * 
 * 335   12/08/97 11:10a Phillipd
 * 
 * 334   12/08/97 10:58a Phillipd
 * 
 * 333   5/12/97 14:11 Collinsd
 * Allocated ships fixed.
 * 
 * 332   4/12/97 15:11 Collinsd
 * Ships are now allocated models.
 * 
 * 331   12/03/97 4:37p Phillipd
 * 
 * 330   12/03/97 2:50p Phillipd
 * Packets per second functioning.....
 * 
 * 329   3/12/97 14:15 Oliverc
 * Prevented demo playback from showing Current_Camera_View until that
 * player's position has been updated from the DMO file
 * 
 * 328   12/02/97 5:38p Phillipd
 * 
 * 327   12/02/97 5:32p Phillipd
 * 
 * 326   11/29/97 4:35p Phillipd
 * Xmem is now in effect...use it allways....
 * 
 * 325   11/21/97 10:56a Phillipd
 * Max Kills to end a level....
 * 
 * 324   11/18/97 10:32a Phillipd
 * 
 * 323   11/17/97 7:10p Phillipd
 * 
 * 322   11/17/97 7:10p Phillipd
 * 
 * 321   11/17/97 6:00p Phillipd
 * 
 * 320   11/17/97 4:34p Phillipd
 * 
 * 319   12/11/97 14:48 Philipy
 * fixed joining multiplayer bug
 * 
 * 318   7/11/97 14:25 Philipy
 * fixed bug when changing mode from title room: InitTitle was not being
 * called
 * 
 * 317   11/05/97 2:38p Phillipd
 * 
 * 316   4/11/97 16:26 Philipy
 * AVI now plays for stats screens
 * implemented scrolling messages (not enabled)
 * 
 * 315   10/30/97 12:40p Phillipd
 * 
 * 314   10/14/97 4:46p Phillipd
 * 
 * 313   10/09/97 3:29p Phillipd
 * External forces coming...
 * Shield and Hull now floats
 * 
 * 312   4/10/97 15:58 Collinsd
 * Added new spiraling missile and took out old morph code.
 * 
 * 311   10/03/97 4:24p Phillipd
 * 
 * 310   10/01/97 4:25p Phillipd
 * 
 * 309   10/01/97 3:53p Phillipd
 * 
 * 308   10/01/97 2:48p Phillipd
 * 
 * 307   9/30/97 4:20p Phillipd
 * 
 * 306   9/30/97 8:46a Phillipd
 * 
 * 305   9/29/97 11:55a Phillipd
 * Dawn of a new age with directplay 3
 * 
 * 304   29/09/97 11:35 Collinsd
 * New bgobject stuff enabled. Pickups/Secondary and Enemies now have
 * group link lists.  Flags for secondary bullets being targeted and hit
 * now added.
 * 
 * 303   9/29/97 9:09a Phillipd
 * 
 * 302   9/29/97 9:08a Phillipd
 * 
 * 301   24/09/97 16:55 Collinsd
 * Added new bgobject stuff.  Added bounding box calc and display code.
 * and changes bgobject state changes.
 * 
 * 300   9/18/97 3:56p Phillipd
 * Fixed stats bug....
 * 
 * 299   9/18/97 12:16p Phillipd
 * 
 * 298   9/18/97 9:42a Phillipd
 * Proper single player started..
 * 
 * 297   15-09-97 3:23p Philipy
 * message displayed, then correct menu displayed on new host machine if
 * host migrates.
 * Host can now start another game, having quit 'waiting to start' menu
 * 
 * 296   14-09-97 6:53p Philipy
 * joining existing team game - you can now select which team to go into,
 * and view current scores.
 * Also if player becomes host during titles, error message displayed &
 * menus quit back to start
 * 
 * 295   3/09/97 19:55 Oliverc
 * Forced player names & bike to match player slot number for ECTS demo
 * 
 * 294   3-09-97 3:42p Philipy
 * ECTS demo stuff
 * 
 * 293   3-09-97 12:29p Philipy
 * changed some team game messages
 * 
 * 292   1-09-97 5:35p Philipy
 * changes made for 3 & 4 player team game
 * 
 * 291   27/08/97 15:38 Collinsd
 * Taken out old secondary weapon stuff
 * 
 * 290   27/08/97 15:02 Collinsd
 * 
 * 289   8/26/97 4:04p Phillipd
 * 
 * 288   8/19/97 12:59p Phillipd
 * 
 * 287   15/08/97 16:12 Collinsd
 * Started bgobjects moving ships.  External Forces bug now fixed.
 * 
 * 286   31-07-97 5:26p Philipy
 * switched off buffering for demo playback
 * 
 * 285   31/07/97 15:57 Oliverc
 * Added special SELF_PLAY features, including disabling critical unused
 * code and setting default values appropriate to demo attract mode
 * 
 * 284   25/07/97 12:10 Collinsd
 * Changed ships bike index, and changed skin for olly.
 * 
 * 283   24/07/97 17:08 Collinsd
 * Added slick
 * 
 * 282   21/07/97 15:39 Collinsd
 * Changed primary/Secondary bullets to work from enemies.
 * 
 * 281   17/07/97 15:38 Collinsd
 * BGObjects now use compobjs.
 * 
 * 280   16/07/97 12:34 Collinsd
 * Adder cerbero bike
 * 
 * 279   8/07/97 16:30 Collinsd
 * Dicked about with include files FUCK!
 * 
 * 278   5/07/97 16:31 Collinsd
 * Put OPT_ON's around opimisations off
 * 
 * 277   3/07/97 10:49 Collinsd
 * Merged MXA and MX models, and added morphing models.
 * 
 * 276   7/03/97 10:11a Phillipd
 * More Ai and node
 * 
 * 275   1/07/97 16:05 Collinsd
 * Added mofisto bike
 * 
 * 274   6/24/97 5:10p Phillipd
 * 
 * 273   6/24/97 11:12a Phillipd
 * 
 * 272   6/21/97 11:38a Phillipd
 * Added a partial filter to incoming messages which should stop a few
 * bugs...
 * 
 * 271   6/16/97 4:15p Phillipd
 * 
 * 270   6/14/97 1:11p Phillipd
 * 
 * 269   6/12/97 12:19p Phillipd
 * 
 * 268   6/11/97 3:48p Phillipd
 * 
 * 267   6/10/97 12:37p Phillipd
 * 
 * 266   6/10/97 11:11a Phillipd
 * 
 * 265   6/07/97 4:10p Phillipd
 * 
 * 264   6/06/97 3:32p Phillipd
 * 
 * 263   6/06/97 10:21a Phillipd
 * 
 * 262   6/05/97 4:22p Phillipd
 * 
 * 261   6/05/97 4:00p Phillipd
 * 
 * 260   5/06/97 12:40 Collinsd
 * Reduced texture pages.
 * 
 * 259   4/06/97 11:11 Collinsd
 * Message sending added for doors.
 * 
 * 258   6/04/97 9:40a Phillipd
 * Added error reporting to Tload
 * 
 * 257   6/03/97 10:46a Phillipd
 * 
 * 256   5/16/97 10:07a Phillipd
 * 
 * 255   5/09/97 5:48p Phillipd
 * Made the getting of a player number more robust....
 * 
 * 254   5/08/97 11:46a Phillipd
 * Demo Playback end crash bug fixed...
 * 
 * 253   5/07/97 5:44p Phillipd
 * 
 * 252   30/04/97 9:47 Collinsd
 * Fixed screenpoly crash bug.
 * 
 * 251   4/29/97 5:15p Phillipd
 * changed the status update....
 * 
 * 250   29/04/97 16:24 Oliverc
 * 
 * 249   29/04/97 15:05 Collinsd
 * Fixing bug in screenpolys.
 * 
 * 248   4/28/97 4:14p Phillipd
 * 
 * 247   26/04/97 14:49 Collinsd
 * Optimisations now on def.
 * 
 * 246   25/04/97 17:14 Collinsd
 * Added new bike
 * 
 * 245   4/25/97 2:51p Phillipd
 * 
 * 244   4/25/97 10:36a Phillipd
 * Better demo playback...which player eyes works again
 * 
 * 243   25/04/97 10:27 Collinsd
 * Change flash
 * 
 * 242   24/04/97 17:21 Collinsd
 * Added hit indicator.
 * 
 * 241   22-04-97 3:25p Collinsd
 * Added player flying out of bilke.
 * 
 * 240   17-04-97 6:00p Collinsd
 * Models now use processexecmodel()
 * 
 * 239   16-04-97 4:38p Collinsd
 * Added reflecting bullets for all weapons except laser.
 * Cheat mode now has invul effect.
 * 
 * 238   4/15/97 4:43p Phillipd
 * 
 * 237   10-04-97 4:41p Collinsd
 * Added new bike models.
 * 
 * 236   4/10/97 4:29p Phillipd
 * DirectPlay3 is here...
 * 
 * 235   4/07/97 12:27p Phillipd
 * 
 * 234   4/05/97 12:08p Phillipd
 * 
 * 233   4/02/97 4:08p Phillipd
 * Added Weapon kill Stats..
 * 
 * 232   2-04-97 11:54a Collinsd
 * Added Jo bike
 * 
 * 231   3/25/97 3:06p Phillipd
 * 
 * 230   25-03-97 9:07a Collinsd
 * When in debug mode and quit it restores the weapons you had before
 * scatter.
 * 
 * 229   24-03-97 3:55p Collinsd
 * Updated Lajay, Excop and added rhesus...
 * 
 * 228   3/19/97 3:34p Phillipd
 * Added Invulnerable flag and timer....gets sent across network...
 * 
 * 227   3/14/97 5:32p Phillipd
 * 
 * 226   3/14/97 9:52a Phillipd
 * 
 * 225   3/13/97 9:50a Phillipd
 * 
 * 224   3/12/97 6:01p Phillipd
 * 
 * 223   3/12/97 4:42p Phillipd
 * 
 * 222   12-03-97 12:40p Collinsd
 * Added new body parts.
 * 
 * 221   3/11/97 4:55p Phillipd
 * Demo Interpolate stuff is now working but not finished...
 * 
 * 220   10-03-97 7:49p Collinsd
 * Cheat mode no longer buggers up pickups.
 * 
 * 219   3/10/97 3:40p Phillipd
 * 
 * 218   3/10/97 9:53a Phillipd
 * 
 * 217   3/07/97 9:51a Phillipd
 * 
 * 216   3/05/97 4:36p Phillipd
 * 
 * 215   3/05/97 4:29p Phillipd
 * 
 * 214   3/05/97 10:31a Phillipd
 * 
 * 213   3/01/97 12:57p Phillipd
 * handles multiple join requests from 1 person,,,,
 * 
 * 212   2/27/97 8:58a Phillipd
 * 
 * 211   2/25/97 12:32p Phillipd
 * rotation interpilation...
 * 
 * 210   2/24/97 4:47p Phillipd
 * GameElapsedTime is now relative to the demo not the
 * real world....so dynamic speed change is possible..
 * 
 * 209   2/24/97 10:00a Phillipd
 * Demo mode with multispeed has been added..
 * 
 * 208   2/20/97 11:10a Phillipd
 * Changed the way a Player Get his Player Number...
 * Much more stable and friendly...
 * 
 * 207   15-02-97 2:45p Collinsd
 * Added error checking for most file loading.
 * 
 * 206   2/14/97 12:47p Phillipd
 * 
 * 205   2/12/97 9:31a Phillipd
 * 
 * 204   2/11/97 5:56p Phillipd
 * 
 * 203   2/11/97 5:26p Phillipd
 * 
 * 202   11-02-97 5:08p Collinsd
 * Triggers/RegenPoints and pickups now are sent across correctly.
 * 
 * 201   2/05/97 4:16p Phillipd
 * 
 * 200   2/04/97 5:11p Phillipd
 * new player joining brute force reject..
 * 
 * 199   4-02-97 4:11p Collinsd
 * 
 * 198   2/03/97 5:16p Phillipd
 * Translusceny is now controlled by global execute buffers.... which is
 * much better...
 * 
 * 197   1/30/97 9:09a Phillipd
 * 
 * 196   1/16/97 12:16p Phillipd
 * 
 * 195   1/14/97 11:00a Phillipd
 * Changed internal and external forces....
 * 
 * 194   1/13/97 5:40p Phillipd
 * added message macors to multiplayer....
 * 
 * 193   10-01-97 3:54p Collinsd
 * Missile/Primary weapons no longer open doors before collision.
 * 
 * 192   1/08/97 11:11a Phillipd
 * 
 * 191   6-01-97 9:06a Collinsd
 * Added drop ammo/shield options.
 * Started working on titan start missile.
 * 
 * 190   3-01-97 7:06p Collinsd
 * Fixed XXX killed you message.
 * 
 * 189   3/01/97 17:12 Oliverc
 * Fixed Dave's bug for him...
 * 
 * 188   3-01-97 3:28p Collinsd
 * Added xxx quantum/pine/purged mined xxx messages.
 * Trojax charging sfx on others pc's now fixed.
 * 
 * 187   2-01-97 4:22p Collinsd
 * Stealthed orbit pulsars now works.  Orbit pulsar and stealth mantle
 * regeneration bug fixed.
 * 
 * 186   2-01-97 12:19p Collinsd
 * Network game now works again.
 * Orbit pulsar now works over network game.
 * 
 * 185   31-12-96 12:35p Collinsd
 * Added multiple multiples.
 * 
 * 184   30-12-96 3:50p Collinsd
 * Added orbit pulsar.
 * 
 * 183   12/27/96 3:38p Phillipd
 * Primary.h Secondary.h pickups.h are now clean....
 * Still Lots to do though.....
 * 
 * 182   12/27/96 12:34p Phillipd
 * all files are not dependant on mydplay.h...just some..
 * including it several times in the same files didnt help..
 * 
 * 181   12/23/96 6:04p Phillipd
 * 
 * 180   12/23/96 8:50a Phillipd
 * 
 * 179   19-12-96 4:17p Collinsd
 * Added lighting when charging thr trojax.
 * 
 * 178   12/19/96 12:02p Phillipd
 * got rid of dpid from short ship packet
 * added location names to team members...
 * 
 * 177   12/18/96 11:10a Phillipd
 * 
 * 176   12/18/96 9:50a Phillipd
 * 
 * 175   12/17/96 2:56p Phillipd
 * 
 * 174   12/17/96 2:33p Phillipd
 * 
 * 173   12/17/96 12:55p Phillipd
 * 
 * 172   12/17/96 9:20a Phillipd
 * 
 * 171   12/16/96 5:48p Collinsd
 * Uses various flags set in menus
 * 
 * 170   12/16/96 10:07a Collinsd
 * Full shield and full now transfered in update.
 * 
 * 169   12/14/96 10:44p Collinsd
 * When someone quits the game all pickups scattered. and dissapear under
 * host control.
 * 
 * 168   12/14/96 5:04p Phillipd
 * 
 * 167   12/13/96 10:47a Phillipd
 * 
 * 166   12/12/96 10:56a Phillipd
 * 
 * 165   12/11/96 5:25p Collinsd
 * Added nutter biker.
 * 
 * 164   12/10/96 2:06p Phillipd
 * 
 * 163   12/07/96 9:42p Collinsd
 * Pickups sending on joining a game has been speeded up.
 * 
 * 162   12/07/96 8:42p Collinsd
 * Added Jap Bird bike, Fixed mines being dropped and firing missile at
 * same time bug.  Added rotations when hit ( depending on damage ).
 * 
 * 161   12/06/96 4:03p Collinsd
 * Changed timer
 * 
 * 160   12/04/96 2:22p Collinsd
 * Pine Mine missile now works.
 * 
 * 159   12/04/96 11:21a Collinsd
 * Added foetoid and new scaled bikes. Added sussgun richochet and sussgun
 * no ammo sfx, new load weapon sfx, and new transpulse/trojax sfx.
 * 
 * 158   12/03/96 5:00p Phillipd
 * Quting if not host bug fixed...
 * game doesnt start if ya just quit the title screen...
 * 
 * 157   12/03/96 10:40a Phillipd
 * Multiplay can now back out
 * 
 * 156   12/02/96 4:26p Phillipd
 * 
 * 155   28/11/96 16:03 Oliverc
 * 
 * 154   11/28/96 3:32p Phillipd
 * Better Multiplayer Starting...
 * 
 * 153   11/28/96 12:37p Phillipd
 * clear screen when starting multiplayer
 * 
 * 152   11/28/96 11:19a Collinsd
 * Added shield and hull sending across network
 * 
 * 151   11/28/96 10:00a Phillipd
 * Multiplayer join changed beyond all recognition,,,
 * 
 * 150   27/11/96 14:07 Oliverc
 * 
 * 149   11/26/96 5:23p Collinsd
 * Added trucker biker
 * 
 * 148   11/26/96 12:35p Collinsd
 * Should hopefully fix problem.
 * 
 * 147   11/22/96 3:01p Phillipd
 * Fire packet cut right down
 * 
 * 146   11/22/96 11:17a Phillipd
 * New frequency dplay stuff added..only sends a packet every n frames
 * unless fireing..
 * 
 * 145   11/21/96 12:32p Phillipd
 * 
 * 144   11/20/96 2:42p Phillipd
 * players can now restart and keep there score...
 * 
 * 143   11/19/96 9:31a Phillipd
 * 
 * 142   18/11/96 19:30 Oliverc
 * Changed menu toggle/back out key to ESC and stopped ESC from quitting
 * the program
 * 
 * 141   11/18/96 4:21p Phillipd
 * 
 * 140   11/18/96 12:23p Phillipd
 * New stuff..
 * 
 * 139   18/11/96 11:39 Collinsd
 * Added scattered weapons dissapearing and regenerating elsewhere after
 * 5-10 seconds.
 * 
 * 138   15/11/96 16:49 Collinsd
 * Mines now sent across when joining. Also fixed bug in pickup sending.
 * 
 * 137   13/11/96 17:00 Collinsd
 * Added Lajay
 * 
 * 136   13/11/96 15:46 Collinsd
 * Added golden powerpod and ljay.
 * 
 * 135   7/11/96 11:11 Collinsd
 * Got rid of quat in ship structures.
 * 
 * 134   7/11/96 10:47 Collinsd
 * Shortened short ships structures.
 * 
 * 133   7/11/96 9:03 Collinsd
 * Changed over to using new network firing.
 * 
 * 132   6/11/96 15:02 Collinsd
 * Added beard biker back in.
 * 
 * 131   5/11/96 17:19 Oliverc
 * Added calls to FlipToGDISurface() when in fullscreen mode and entering
 * DPlay Wizard or pausing game to use menus so that 3Dfx card works
 * 
 * 130   1/11/96 17:52 Collinsd
 * Reduced ship/shortship structure size by using bits.
 * 
 * 129   31/10/96 16:30 Collinsd
 * Primary/Secondary now included ship updates.  Stealth regeneration
 * fixed
 * 
 * 128   30/10/96 14:34 Collinsd
 * Added stealthmode.
 * 
 * 127   26/10/96 18:04 Collinsd
 * Added recoil vector to ihityou.
 * 
 * 126   10/25/96 2:07p Phillipd
 * 3d panel tested, test for lost packets
 * 
 * 125   10/25/96 10:15a Phillipd
 * 
 * 124   22/10/96 12:08 Collinsd
 * Added body parts and blood splats.
 * 
 * 123   10/18/96 11:57a Phillipd
 * 
 * 122   10/17/96 4:43p Phillipd
 * proper score sort....dont work on stats yet...
 * 
 * 121   10/16/96 3:11p Phillipd
 * 
 * 120   10/15/96 10:42a Phillipd
 * Added Spot Lights....
 * 
 * 119   14/10/96 14:40 Collinsd
 * You can now enable and disable pickup debugging by deleting
 * DEBUG_PICKUPS in pickups.h
 * 
 * 118   14/10/96 14:22 Collinsd
 * Added even more debug info in pickups.
 * Also speeded up target aquisition of homing missiles
 * 
 * 117   10/14/96 12:12p Phillipd
 * 
 * 116   10/12/96 5:54p Phillipd
 * 
 * 115   12/10/96 16:19 Collinsd
 * added more debug info
 * 
 * 114   10/11/96 5:30p Phillipd
 * New low Player...
 * detsroy message now looks for a clean break rather than
 * treating a crash leaving the same as a quit game..
 * 
 * 113   10/11/96 2:42p Phillipd
 * 
 * 112   10/11/96 2:34p Phillipd
 * Players who leave or who crash should now be greyed
 * out..
 * 
 * 111   10/11/96 12:51p Phillipd
 * Slight update...Destroy player is now handled as a system message..
 * 
 * 110   10/11/96 11:40a Phillipd
 * Now player names are gotten rather than given..
 * 
 * 109   10/10/96 3:09p Phillipd
 * 
 * 108   9/10/96 16:12 Collinsd
 * Added regeneration sparkle. And model display flag.
 * 
 * 107   10/09/96 2:33p Phillipd
 * 
 * 106   8/10/96 20:26 Collinsd
 * fixed pickup transfer for new player.
 * 
 * 105   7/10/96 16:31 Collinsd
 * Added execsize to mx and mxafiles. Also fixed colour keying on models.
 * 
 * 104   5/10/96 13:22 Collinsd
 * Fixed bug that caused pickups to do collision processing
 * even when stationary for the first few seconds after initialisation.
 * 
 * 103   10/04/96 3:35p Phillipd
 * ships now dont slip through the floor if no packet gets through
 * 
 * 102   10/04/96 11:37a Phillipd
 * 
 * 101   10/04/96 10:16a Phillipd
 * 
 * 100   3/10/96 15:49 Collinsd
 * Added new sfx
 * 
 * 99    29/09/96 18:47 Collinsd
 * Added turbo to ship structure. Fixed pine mine firing pos.
 * 
 * 98    9/19/96 2:33p Phillipd
 * 
 * 97    9/18/96 3:59p Phillipd
 * 
 * 96    17/09/96 16:30 Collinsd
 * No damage when in limbo mode.
 * 
 * 95    17/09/96 15:34 Collinsd
 * Shockwaves added. and fixed primary previous.
 * 
 * 94    16/09/96 18:57 Oliverc
 * Ships now start in different positions when changing level in
 * multiplayer game
 * 
 * 93    16/09/96 15:20 Oliverc
 * Changed autolevelling to be properly framelagged
 * and added ship bobbing
 * 
 * 92    9/16/96 12:56p Phillipd
 * 
 * 91    9/16/96 11:51a Phillipd
 * 
 * 90    9/16/96 11:39a Phillipd
 * 
 * 89    9/16/96 11:33a Phillipd
 * 
 * 88    9/16/96 11:30a Phillipd
 * 
 * 87    16/09/96 11:24 Collinsd
 * Added joining regeneration of pickups code.
 * 
 * 86    9/16/96 10:16a Phillipd
 * Big changes to Full screen display...
 * And Pickups being set to joining player
 * 
 * 85    16/09/96 9:25 Collinsd
 * Added regenerating pickups.
 * 
 * 84    9/15/96 3:43p Phillipd
 * 
 * 83    9/15/96 12:11p Phillipd
 * 
 * 82    14/09/96 21:27 Oliverc
 * Added basic ship auto-levelling (incl config file setting) but not made
 * it frame lagged properly
 * 
 * 81    12/09/96 17:52 Collinsd
 * You can now shoot mines ( Primary weapons only though
 * at the moment ).
 * 
 * 80    11/09/96 19:00 Collinsd
 * Added tests for RAMP emulation ( Although may not work)
 * Also fixed gravity effect to be dependent on GLOBAL_SCALE
 * 
 * 79    9/11/96 10:25a Phillipd
 * 
 * 78    10/09/96 16:33 Oliverc
 * Added external/internal force vector to ship movement
 * 
 * 77    10/09/96 12:54 Collinsd
 * Pickups now save and load groups
 * 
 * 76    9/10/96 11:57a Phillipd
 * 
 * 75    9/10/96 9:56a Phillipd
 * 
 * 74    9/09/96 20:42 Collinsd
 * No longer used GroupPolyCol or WhichGroupImIn.
 * 
 * 73    9/09/96 11:22 Oliverc
 * Fixed start pos bug when new player joins
 * 
 * 72    7/09/96 20:21 Collinsd
 * Collision with pine mine now added.  Trojax power
 * fixed, now does proper damage.  Transpulse speeded
 * up and made more lethal.
 * 
 * 71    9/06/96 12:56p Phillipd
 * 
 * 70    6/09/96 9:13 Collinsd
 * Timer missile works now.
 * 
 * 69    5/09/96 15:08 Collinsd
 * Added timer missile.
 * 
 * 68    9/05/96 1:59p Phillipd
 * 
 * 67    8/30/96 2:32p Phillipd
 * 
 * 66    8/28/96 12:41p Phillipd
 * 
 * 65    8/28/96 11:13a Phillipd
 * Game now works under a GameStatus flag...
 * So you can view scores load a new level and restart..
 * 
 * 64    8/23/96 2:54p Phillipd
 * 
 * 63    8/23/96 2:41p Phillipd
 * 
 * 62    8/23/96 2:19p Phillipd
 * 
 * 61    8/23/96 11:10a Phillipd
 * 
 * 60    8/22/96 5:13p Phillipd
 * The Stats Are coming
 * 
 * 59    8/21/96 3:57p Phillipd
 * 
 * 58    8/20/96 12:12p Phillipd
 * 
 * 57    8/20/96 12:06p Phillipd
 * lots of new panel / text stuff...new stats array...
 * 
 * 56    16/08/96 17:29 Collinsd
 * Damage variables now in..
 * 
 * 55    8/16/96 10:47a Phillipd
 * 
 * 54    8/15/96 5:18p Phillipd
 * 
 * 53    8/15/96 4:46p Phillipd
 * 
 * 52    8/14/96 5:48p Phillipd
 * 
 * 51    14/08/96 10:49 Collinsd
 * 
 * 50    14/08/96 9:27 Collinsd
 * 
 * 49    13/08/96 15:52 Collinsd
 * Added powerup pods
 * 
 * 48    8/13/96 10:15a Phillipd
 * Player name and score now given to everyone for printing....4x5 print
 * routine and uint16 printing
 * 
 * 46    8/08/96 8:48a Phillipd
 * 
 * 45    8/07/96 10:49a Phillipd
 * 
 * 44    5/08/96 20:04 Collinsd
 * Network for pickups now works,
 * 
 * 43    2/08/96 16:13 Collinsd
 * Fixed primary weapon net loop bug.  Oooops...
 * 
 * 42    8/02/96 3:26p Phillipd
 * 
 * 41    7/31/96 5:14p Phillipd
 * 
 * 40    31/07/96 16:07 Collinsd
 * Added new pyrolite weapon, added type into bullets/missiles. Fixed bug
 * with 2d polys
 * 
 * 39    7/29/96 4:43p Phillipd
 * 
 * 38    7/26/96 2:41p Phillipd
 * 
 * 37    25/07/96 9:43 Collinsd
 * 
 * 36    7/25/96 9:16a Phillipd
 * 
 * 35    7/24/96 5:56p Phillipd
 * 
 * 34    7/24/96 9:51a Phillipd
 * 
 * 33    7/23/96 11:27a Phillipd
 * 
 * 32    7/23/96 9:41a Phillipd
 * 
 * 31    21/07/96 14:21 Collinsd
 * Added drop vector to dplay and secondary weapons.
 * 
 * 30    7/16/96 9:36a Phillipd
 * 
 * 29    7/15/96 5:28p Phillipd
 * Finally got rid of WhoIAm = 0 problem....
 * 
 * 28    7/15/96 2:58p Phillipd
 * 
 * 27    7/15/96 2:10p Phillipd
 * 
 * 26    7/15/96 12:38p Phillipd
 * 
 * 25    7/15/96 12:37p Phillipd
 * 
 * 24    7/15/96 11:05a Phillipd
 * 
 * 23    7/15/96 11:05a Phillipd
 * 
 * 22    7/15/96 10:37a Phillipd
 * 
 * 21    7/15/96 9:09a Phillipd
 * 
 * 20    7/12/96 12:29p Phillipd
 * 
 * 19    7/11/96 5:12p Phillipd
 * 
 * 18    10/07/96 17:29 Collinsd
 * 
 * 17    7/08/96 10:12a Phillipd
 * 
 * 16    7/08/96 9:43a Phillipd
 * 
 * 15    7/06/96 4:19p Phillipd
 * 
 * 14    7/06/96 2:58p Phillipd
 * Ships now use Quats...
 * 
 * 13    7/05/96 3:21p Phillipd
 * 
 * 12    7/04/96 11:15a Phillipd
 * 
 * 11    7/04/96 9:49a Phillipd
 * 
 * 10    2/07/96 16:50 Oliverc
 * 
 * 9     7/02/96 11:05a Phillipd
 * 
 * 8     6/27/96 2:48p Phillipd
 * 
 * 7     6/27/96 2:13p Phillipd
 * 
 * 6     6/26/96 2:55p Phillipd
 * 
 * 5     6/26/96 12:27p Phillipd
 * 
 * 4     6/26/96 12:26p Phillipd
 * 
 * 3     25/06/96 15:15 Collinsd
 * 
 * 2     6/25/96 11:37a Phillipd
 * First SS update
 * 
 */

/*==========================================================================
 *  File:       mydplay.c
 *  Content:    Direct Play Multiplayer Stuff
 ***************************************************************************/

#define WIN32_EXTRA_LEAN

#include "main.h"
#include <stdio.h>
#include "typedefs.h"
#include <dplay.h>
#include "new3d.h"
#include "quat.h"
#include "CompObjects.h"
#include "bgobjects.h"
#include "Object.h"
#include "mydplay.h"
#include "2dtextures.h"
#include "mload.h"
#include "triggers.h"
#include "pickups.h"
#include "primary.h"
#include "secondary.h"
#include "mload.h"
#include "text.h"
#include "models.h"
#include "d3dmain.h"
#include "d3dappi.h"
#include "comm.h"
#include "Lights.h"
#include "title.h"
#include "multiplayer.h"
#include "controls.h"
#include "screenpolys.h"
#include "goal.h"
#include <stdio.h>
#include "dpthread.h"
#include "mydplay2.h"
#include "XMem.h"
#include "Local.h"


int average_server_packet_size = 0;

BOOL	UseSendAsync = FALSE;
BOOL	ServerChoosesGameType = FALSE;
BOOL	SessionGuidExists = FALSE;

#ifdef DEBUG_ON
int	PacketGot[256];
int	PacketSize[256];
#endif

#ifdef MANUAL_SESSIONDESC_PROPAGATE
extern LPDPSESSIONDESC2                    glpdpSD_copy;
#endif

uint32 BigPacketSize = 0;
uint32 MaxBigPacketSize = 0;

uint32 RecPacketSize = 0;
uint32 MaxRecPacketSize = 0;

uint32 BytesPerSecRec = 0;
uint32 BytesPerSecSent = 0;
uint32 CurrentBytesPerSecRec = 0;
uint32 CurrentBytesPerSecSent = 0;
uint32 MaxCurrentBytesPerSecRec = 0;
uint32 MaxCurrentBytesPerSecSent = 0;
float BytesPerSecTimer = 0.0F;

extern SLIDER	FSBCompensation;
#define FSB_COMPENSATION ((LONGLONG)FSBCompensation.value)


extern int FontHeight;
extern HKEY ghCondemnedKey;
extern LONG RegGet(LPCTSTR lptszName, LPBYTE lpData, LPDWORD lpdwDataSize);
extern SLIDER ServerTimeoutSlider;
extern SLIDER	MaxServerPlayersSlider;
extern LIST	SessionsList;

extern DPID	PlayerIDs[ MAX_PLAYERS ];

extern	int16	PickupsGot[ MAXPICKUPTYPES ];
extern	uint32	TeamFlagMask[ MAX_TEAMS ];
extern	int8	TeamFlagPickup[ MAX_TEAMS ];

extern int16	NumPrimaryPickups;

extern GUID	ServiceProvidersGuids[];
extern	LIST	ServiceProvidersList;

extern	BOOL	CountDownOn;
extern char	ServerLevelNames[MAXLEVELS][ 8 ];
extern	char LevelNames[MAXLEVELS][128];
extern uint8	ServerLevelsListState;

SERVERSAYSSHIPDIEDMSG	SSSDM;
GUID autojoin_session_guid;
float FindSessionTimeout;

extern int16 NumServerLevels;

extern	SLIDER	MaxPlayersSlider;
extern BOOL	ServerCollisions;


extern	LONGLONG	LargeTime;
extern SLIDER	GoalScoreSlider;

extern LIST	LevelList;
extern	SLIDER	TimeLimit;
extern	int		GameType;
extern	BOOL	MyBrightShips;
extern BOOL BountyBonus;
extern SLIDER	BountyBonusSlider;

extern	BOOL	DS;

#define	ONEOVER32767 (1.0F / 32767.0F)
#define	ONEOVER256 (1.0F / 256.0F)

#define	SHORTBANKMODIFIER (32767.0F / MAXBANKANGLE )
#define	SHORTANGLEMODIFIERPACK (32767.0F / 45.0F)
#define	SHORTANGLEMODIFIERUNPACK (45.0F / 32767.0F)

extern char CTFMessage[];
extern	BOOL IMustQuit;

extern BOOL NeedFlagAtHome;
extern BOOL OwnFlagTeleportsHome;
extern BOOL CanCarryOwnFlag;
extern SLIDER CTFSlider;

extern MENU MENU_NEW_CreateLobbyGame;

void SetTeamGoals( uint16 *TeamGoals );

uint32 BuildShipFlags( BYTE Player );
void UnPackShipFlags( BYTE Player , uint32 Flags );
BOOL	CheckIfPlayerCheats( BYTE player );

extern int FlagsToGenerate;
extern  uint32  Host_Flags[ MAX_PLAYERS ];

extern BOOL BountyHunt;
extern int BountyBonusInterval;

extern BOOL	CTF;
extern BOOL CaptureTheFlag;
extern int GoalScore;
extern int GameCompleted;
extern USERCONFIG	*player_config;

char *TeamName[];

extern int	AllowedBike[ ALLOWED_BIKETYPES ];
extern int32 ColPerspective;
extern BOOL Panel;
extern BOOL PreAttractModePanel;

extern BOOL	BrightShips;
extern BOOL	BikeExhausts;
extern	BOOL IllegalTime;
extern	float	Countdown_Float;
extern	SLIDER  PacketsSlider;

extern char CurrentTauntVariant;

float DPlayUpdateInterval = 4.0F;
int OldPPSValue;
float PacketDelay = 4.0F;					// How long before I start to Declerate him.....
float HostDutyTimer = 0.0F;
float DPlayUpdateIntervalHostDuties = 30.0F;
void SetShipBankAndMat( OBJECT * ShipObjPnt );

#ifdef OPT_ON
#pragma optimize( "gty", on )
#endif

#if defined (SELF_PLAY) || defined(ECTS) || defined( SHAREWARE )
extern	LIST	BikeList;
#endif

extern	SLIDER	MaxKillsSlider;
int16	MaxKills = 0;
extern	LONGLONG	DemoStartedTime;		// when the game started
extern	LONGLONG	DemoEndedTime;		// when the game started
extern	int32		DemoGameLoops;
extern	float	DemoAvgFps;
extern	LONGLONG	TimeDiff;
extern LONGLONG	LevelCheckSum;

extern	LONGLONG	Freq;
extern	BOOL	Buffer1InUse;
extern	int		Buffer1Count;
extern	DWORD	Buffer1Offset;
extern	BYTE *	Buffer1Pnt;

extern	BOOL	Buffer2InUse;
extern	int		Buffer2Count;
extern	DWORD	Buffer2Offset;
extern	BYTE *	Buffer2Pnt;
extern	BOOL	DplayRecieveThread;

extern	BOOL	RecordDemo;
extern	BOOL	PlayDemo;
extern	BOOL	RecordDemoToRam;
extern	FILE	*	DemoFp;
extern	FILE	*	DemoFpClean;
extern	LIST	DemoList;
extern	LONGLONG	GameCurrentTime;		// How long the game has been going...
extern	char	ShortLevelNames[MAXLEVELS][32];
extern BOOL	bSoundEnabled;

extern	BOOL BadConnection[ MAX_PLAYERS+1 ];

extern	DPSESSIONDESC2	Sessions[MAXSESSIONS];

extern float framelag;

extern	float	Start_Shield;
extern	float	Start_Hull;

LONGLONG PingRequestTime;					// used to reply the time it was sent...
uint16		PingTimes[MAX_PLAYERS];		// How long does it take for a ping???
extern BOOL		ShowPing;

void SpecialDestroyGame( void );
void GetLevelName( char *buf, int bufsize, int level );
void StoreLevelNameInSessionDesc( char *str );

BOOL	CanDoDamage[MAX_PLAYERS+1];

extern	MATRIX			MATRIX_Identity;

extern	TEXT	MacroText1;
extern	TEXT	MacroText2;
extern	TEXT	MacroText3;
extern	TEXT	MacroText4;
extern  TEXT	QuickText;
extern  TEXT	QuickTextWhisper;
extern	int8	PrimaryToFireLookup[ MAXPRIMARYWEAPONS ];
extern	int8	SecondaryToFireLookup[ MAXSECONDARYWEAPONS ];
extern	float	GlobalFramelagAddition;
extern	BOOL ResetKillsPerLevel;

BOOL		JustGenerated = FALSE;
BOOL		JustPickedUpShield = FALSE;



int16	NextworkOldKills = -1;
int16	NextworkOldDeaths = -1;
int16	NextworkOldBikeNum = -1;

float		Interval = 0.0F;

extern	LONGLONG	GameStartedTime;
extern	LONGLONG	GameElapsedTime;
LONGLONG	TempTime;

extern	uint16		Seed1;
extern	uint16		Seed2;
extern	uint16		CopyOfSeed1;
extern	uint16		CopyOfSeed2;
extern	BOOL		RandomPickups;
extern	BOOL		HarmTeamMates;


#if !defined ( SHAREWARE ) && !defined ( WIN98SHAREWARE )
int16	BikeModels[ MAXBIKETYPES ] = {

	MODEL_Borg,
	MODEL_Beard,
	MODEL_LaJay,
	MODEL_Excop,
	MODEL_Trucker,
	MODEL_Foetoid,
	MODEL_JapBird,
	MODEL_Nutter,
	MODEL_Rhesus,
	MODEL_Joe,
	MODEL_Shark,
	MODEL_HK5,
	MODEL_Nubia,
	MODEL_Mofisto,
	MODEL_Cerbero,
	MODEL_Slick,
	MODEL_Borg,

};
#else
int16	BikeModels[ MAXBIKETYPES ] = {

	MODEL_Beard,
	MODEL_Beard,
	MODEL_Beard,
	MODEL_Excop,
	MODEL_Trucker,
	MODEL_Beard,
	MODEL_Beard,
	MODEL_Beard,
	MODEL_Beard,
	MODEL_Beard,
	MODEL_Beard,
	MODEL_Beard,
	MODEL_Nubia,
	MODEL_Beard,
	MODEL_Cerbero,
	MODEL_Beard,
	MODEL_Beard,

};
#endif

char					MyName[ 32 ] = "Default game";
char					NickName[ 32 ] = "Default game";
char					tempstr[256];
int16					NamesAreLegal = 1;
SHORTNAMETYPE			Names;	// all the players short Names....
BYTE					MyGameStatus = STATUS_Normal;//
BYTE					PreDemoEndMyGameStatus = 0;
BYTE					OverallGameStatus = STATUS_Null;
BYTE					GameStatus[MAX_PLAYERS + 1];	// Game Status for every Ship...
													// this tells the drones what status the host thinks hes in..
BYTE					OldGameStatus[MAX_PLAYERS + 1];	// Game Status for every Ship...
int16					Lives = 3;
int16					StatsStatus = 0;
int16					Stats[MAX_PLAYERS+1][MAX_PLAYERS+1];
int16					StatsCount = -1;
uint16					PrimaryStats[TOTALPRIMARYWEAPONS*2];
uint16					SecondaryStats[TOTALSECONDARYWEAPONS*2];

DPID PseudoHostDPID;
DPID HostDPID;

void RequestPings( void );
void SfxForCollectPickup( uint16 Owner, uint16 ID );

extern	LPDPSESSIONDESC2                    glpdpSD;            // current session description

void CreateReGen( uint16 ship );
BOOL InitLevels( char *levels_list );
extern	MODEL	Models[MAXNUMOFMODELS];

extern	int	ScoreSortTab[MAX_PLAYERS];

BOOL	HostDuties = FALSE;

LPDIRECTPLAY4A                       glpDP=NULL;     // directplay object pointer

DPID                    dcoID=0;        // our DirectPlay ID
LPGUID                  g_lpGuid = NULL;
HANDLE                  dphEvent = NULL;
BOOL                    IsHost = TRUE;
BOOL					IsPseudoHost = FALSE;
BOOL                    IsServer = FALSE;
BYTE                    WhoIAm = 0;

BYTE					Current_Camera_View = 0;		// which object is currently using the camera view....
BOOL					RemoteCameraActive = FALSE;

PRIMBULLPOSDIR			TempPrimBullPosDir;
SECBULLPOSDIR			TempSecBullPosDir;
SHORTGLOBALSHIP			ShortGlobalShip;
VERYSHORTGLOBALSHIP		VeryShortGlobalShip;
SHIPDIEDINFO			TempDied;
SETTIME					TempTimeSet;
TITANBITS				TempTitanBits;

FSHORTGLOBALSHIP		FShortGlobalShip;
FVERYSHORTGLOBALSHIP	FVeryShortGlobalShip;
GROUPONLY_FVERYSHORTGLOBALSHIP	GroupOnly_FVeryShortGlobalShip;

PICKUPINFO				TempPickup;
VERYSHORTPICKUPINFO		VeryShortTempPickup;
KILLPICKUPINFO			TempKillPickup;
SERVERKILLPICKUPINFO	TempServerKillPickup;
EXPSECONDARYINFO		TempExplodeSecondary;
TEAMGOALSINFO			TempTeamGoals;
SHOCKWAVEINFO			TempShockwave;
BGOUPDATEINFO			TempBGOUpdate;
SHIPHIT					TempShipHit;
SHORTSHIPHIT			ShortTempShipHit;
EXPLODESHIPINFO				TempExplodeShip;


MISSEDPICKUPMSG			MissedPickups[ MAXMISSEDPICKUPS ];
SHORTPICKUP				MissedInitPickups[ MAXMISSEDPICKUPS ];
SHORTKILLPICKUP			MissedKillPickups[ MAXMISSEDPICKUPS ];
SHORTSERVERKILLPICKUP	MissedServerKillPickups[ MAXMISSEDPICKUPS ];
int16					NumMissedPickups = 0;
int16					NumMissedInitPickups = 0;
int16					NumMissedKillPickups = 0;

MISSEDMINEMSG			MissedMines[ MAXMISSEDMINES ];
SHORTMINE				MissedInitMines[ MAXMISSEDMINES ];
SHORTKILLMINE			MissedKillMines[ MAXMISSEDMINES ];
int16					NumMissedMines = 0;
int16					NumMissedInitMines = 0;
int16					NumMissedKillMines = 0;
BOOL DPlayTest = FALSE;

LONGLONG	DemoTimeSoFar = 0;

extern uint16	num_start_positions;

int LowestBombTime;
int	BombNumToSend;
float BombTimeToSend;
extern	BOOL BombTag;
extern	BOOL	BombActive[MAXBOMBS];
extern	float	BombTime[MAXBOMBS];

BYTE	Server_WhoHitYou;

GLOBALSHIP              Ships[MAX_PLAYERS+1];
BOOL	DemoShipInit[MAX_PLAYERS+1];

LONGLONG	LastPacketTime[MAX_PLAYERS+1];
BYTE		CommBuff[MAX_BUFFER_SIZE];


BOOL	BigPackets = TRUE;//FALSE;
uint32	BIGPACKETBUFFERSIZE = 1024;
BYTE	BigPacketCommBuff[MAXBIGPACKETBUFFERSIZE];
BYTE	ReceiveCommBuff[MAXBIGPACKETBUFFERSIZE];
int		RealPacketSize[256];

LONGLONG LastBigPacketSent = 0;
uint32	BigPacketOffset = 2;
uint32	NumOfPacketsInBigPacket = 0;
uint32	BigPacketOffsets[MAXPACKETSPERBIGPACKET];
uint32	BigPacketSizes[MAXPACKETSPERBIGPACKET];
LONGLONG	BigPacketTime[MAXPACKETSPERBIGPACKET];
int	BigPacketsSent = 0;

#ifdef	GUARANTEEDMESSAGES
typedef struct GUARANTEEDMSGHEADER
{
	uint32		Ack;
	uint32		ID;
	LONGLONG	OverallTime;
	LONGLONG	Time;
	BYTE		MsgType;
	BOOL		OverideOlderMessage;
	BOOL		AllPlayers;
	int			MessageLength;
	BYTE		Count;
struct GUARANTEEDMSGHEADER * Next;
struct GUARANTEEDMSGHEADER * Prev;
	BYTE		Message;
}GUARANTEEDMSGHEADER, *LPGUARANTEEDMSGHEADER;

GUARANTEEDMSGHEADER * GMs = NULL;
GUARANTEEDMSGHEADER * OldestGMs = NULL;
int GuaranteedMessagesActive = 0;
int GuaranteedMessagesActiveMax = 0;
uint32 GuaranteedMessagesID = 1234567890;
int GuaranteedMessagesTime = 1;					// How many seconds before sending the message again...
int GuaranteedMessagesOverallTime = 10;			// How long to keep the message around for...
BOOL AddGuaranteedToServersGuaranteedQue( LPGUARANTEEDMSG lpGM );
#endif



uint32	SERVERPACKETBUFFERSIZE = 1024;
BYTE	ServerPacketCommBuff[MAXBIGPACKETBUFFERSIZE];
uint32	ServerPacketOffset = 2;
uint32	NumOfPacketsInServerPacket = 0;
uint32	ServerPacketOffsets[MAXPACKETSPERSERVERPACKET];
uint32	ServerPacketSizes[MAXPACKETSPERSERVERPACKET];
float	ServerPacketTime[MAXPACKETSPERSERVERPACKET];
BOOL	ItsAGuranteed = FALSE;


extern	VECTOR			Forward;
extern	VECTOR			Backward;
extern	VECTOR			SlideUp;
extern	VECTOR			SlideDown;
extern	VECTOR			SlideLeft;
extern	VECTOR			SlideRight;
extern	VECTOR			NullVector;
extern	MLOADHEADER Mloadheader;
extern	int16 LevelNum;
extern	int16 NewLevelNum;
extern	float PowerLevel;
extern	SECONDARYWEAPONATTRIB SecondaryWeaponAttribs[ TOTALSECONDARYWEAPONS ];
extern	SECONDARYWEAPONBULLET SecBulls[MAXSECONDARYWEAPONBULLETS];
extern	SHIPCONTROL control;
extern	char * Messages[];
extern	int16	SelectedBike;
extern	BOOL	GodMode;

extern	BOOL	TeamGame;
extern	BYTE	TeamNumber[MAX_PLAYERS];
extern	uint16	RandomStartPosModify;

BOOL	ChAngleevel( void );
void	DebugPrintf( const char * format, ... );
void AddTitleMessage(LPTEXTMSG LpTextMsg);
void ShowSplashScreen( int num );
//void CheckServerDeathTimes( void );

MATRIX	TempMatrix = {
				1.0F, 0.0F, 0.0F, 0.0F,
				0.0F, 1.0F, 0.0F, 0.0F,
				0.0F, 0.0F, 1.0F, 0.0F,
				0.0F, 0.0F, 0.0F, 1.0F };

char	namebuf[256];
char	tempadd[1024];
DWORD	tempsize;

extern	char biker_name[256];
extern	DWORD                   Old_WhoIAm;
extern	DPSESSIONDESC2			Old_Session;
extern	DWORD					Old_Kills;
extern	DWORD					Old_Deaths;
extern	DWORD					Old_TeamNumber;
extern	char					Old_Name[256];
extern	BOOL					Rejoining;

extern	LONGLONG		Time_LastValue;
extern	BOOL			GoreGuts;
extern	int16			NumRegenPoints;
extern	int				NumOfTrigVars;
extern	int				NumOfTriggers;
extern	BOOL IsServerGame;
DPID	from_dcoID;
BOOL	UseShortPackets = TRUE;//FALSE;

extern	int16	NumOrbs;
extern	PRIMARYWEAPONATTRIB PrimaryWeaponAttribs[ TOTALPRIMARYWEAPONS ];
extern	char *SecondaryDescription[MAXSECONDARYWEAPONS];
extern	char *PrimaryDescription[];
extern	int16	Host_PrimaryWeaponsGot[ MAX_PLAYERS ][ MAXPRIMARYWEAPONS ];
extern	int16	Host_SecondaryWeaponsGot[ MAX_PLAYERS ][ MAXSECONDARYWEAPONS ];
extern	float	Host_GeneralAmmo[ MAX_PLAYERS ];
extern	float	Host_PyroliteAmmo[ MAX_PLAYERS ];
extern	float	Host_SussGunAmmo[ MAX_PLAYERS ];
//extern	float	Host_GeneralAmmoUsed[ MAX_PLAYERS ];
extern	float	Host_GeneralAmmoUsed; //[ MAX_PLAYERS ];
//extern	float	Host_PyroliteAmmoUsed[ MAX_PLAYERS ];
extern	float	Host_PyroliteAmmoUsed;
//extern	float	Host_SussGunAmmoUsed[ MAX_PLAYERS ];
extern	float	Host_SussGunAmmoUsed;
extern	int16	Host_SecondaryAmmo[ MAX_PLAYERS ][ MAXSECONDARYWEAPONS ];
//extern	int16	Host_SecAmmoUsed[ MAX_PLAYERS ][ MAXSECONDARYWEAPONS ];
extern	int16	Host_SecAmmoUsed[ MAXSECONDARYWEAPONS ];
extern	int8	Host_SecWeaponsGot[ MAX_PLAYERS ][ MAXPICKUPS ];
extern	float	Host_NitroFuel[ MAX_PLAYERS ];
//extern	float	Host_NitroFuelUsed[ MAX_PLAYERS ];
extern	float	Host_NitroFuelUsed;
extern	int16	Host_PowerLevel[ MAX_PLAYERS ];
extern	float	Host_OrbAmmo[ MAX_PLAYERS ][ MAXMULTIPLES ];
extern	BYTE	Host_NumOfOrbitals[ MAX_PLAYERS ];
extern	BYTE	Host_CopyOfNumOfOrbitals[ MAX_PLAYERS ];
extern	float	Host_CopyOfOrbAmmo[ MAX_PLAYERS ][ MAXMULTIPLES ];
extern	int16	Host_CopyOfPowerLevel[ MAX_PLAYERS ];
extern	float	Host_CopyOfNitroFuel[ MAX_PLAYERS ];
extern	float	Host_CopyOfGeneralAmmo[ MAX_PLAYERS ];
extern	float	Host_CopyOfSussGunAmmo[ MAX_PLAYERS ];
extern	float	Host_CopyOfPyroliteAmmo[ MAX_PLAYERS ];
extern	int16	Host_PickupsGot[ MAX_PLAYERS ][ MAXPICKUPTYPES ];
extern	PICKUP	Pickups[ MAXPICKUPS ];
extern	int16	SecondaryFromPickupTab[ MAXSECONDARYWEAPONS * 2 ];

BOOL CheckForName( BYTE Player )
{
	char	*			NamePnt;
	char	*			NamePnt2;
    HRESULT				hr;
	int					i;
	LPDPNAME			lpDpName;

	if( Names[Player][0] == 0 && !IsServerGame )
	{
		tempsize = 256;
		hr = IDirectPlayX_GetPlayerName( glpDP , from_dcoID , (LPVOID) &namebuf[0] , (LPDWORD) &tempsize );
	
		if( hr == DP_OK )
		{
			lpDpName = (LPDPNAME) &namebuf[0];
			lpDpName->dwSize = sizeof(DPNAME);
			NamePnt = (char*) &Names[Player][0];
#if defined (ECTS)
			// force player to use same name as his bike
			NamePnt2 = &BikeList.item[Player % MAXBIKETYPES][0];
#else
#ifdef UNICODE
			NamePnt2 = (char*) lpDpName->lpszShortName;
#else				
			NamePnt2 = (char*) lpDpName->lpszShortNameA;
#endif				
#endif
			for( i = 0 ; i < 7 ; i++ )
			{
				*NamePnt++ = *NamePnt2++;
			}
			Names[Player][7] = 0;
		}
		return TRUE;
	}
	return FALSE;
}

void SendANormalUpdate( void )
{
	VECTOR	Move_Off;

	if( IsServer )
		return;

	if( !UseShortPackets )
	{
		ShortGlobalShip.Flags = BuildShipFlags(WhoIAm);

		ShortGlobalShip.GroupImIn	= (BYTE) Ships[WhoIAm].Object.Group;    // 
		ShortGlobalShip.Pos			= Ships[WhoIAm].Object.Pos		;	  // x , y , z position
		ShortGlobalShip.Move_Off	= Ships[WhoIAm].Move_Off;	  // Last Movement..x , y , z
		ShortGlobalShip.Quat		= Ships[WhoIAm].Object.Quat;	  // Final inverse view Quat.......after banking.. 
		ShortGlobalShip.Status		= MyGameStatus;
		ShortGlobalShip.Angle		= Ships[WhoIAm].Object.Angle;
#ifdef	SHORTBANK
		ShortGlobalShip.Bank = (int16) (Ships[ WhoIAm ].Object.Bank * SHORTBANKMODIFIER);
#else
		ShortGlobalShip.Bank = Ships[ WhoIAm ].Object.Bank;
#endif
		SendGameMessage(MSG_UPDATE, 0, 0, 0, 0);
	}else{
		VeryShortGlobalShip.Flags = BuildShipFlags(WhoIAm);

		VeryShortGlobalShip.GroupImIn	= (BYTE) Ships[WhoIAm].Object.Group;    // 
		VeryShortGlobalShip.Pos.x		= (int16) Ships[WhoIAm].Object.Pos.x;
		VeryShortGlobalShip.Pos.y		= (int16) Ships[WhoIAm].Object.Pos.y;
		VeryShortGlobalShip.Pos.z		= (int16) Ships[WhoIAm].Object.Pos.z;
		Move_Off = Ships[WhoIAm].Move_Off;
		NormaliseVector( &Move_Off );
		VeryShortGlobalShip.Move_Off_Scalar = (uint16) ( 256.0F * VectorLength( &Ships[WhoIAm].Move_Off ) );
		VeryShortGlobalShip.Move_Off.x	= (int16) (Move_Off.x * 32767.0F);
		VeryShortGlobalShip.Move_Off.y	= (int16) (Move_Off.y * 32767.0F);
		VeryShortGlobalShip.Move_Off.z	= (int16) (Move_Off.z * 32767.0F);
		VeryShortGlobalShip.Quat.w		= (int16) (Ships[WhoIAm].Object.Quat.w * 32767.0F);
		VeryShortGlobalShip.Quat.x		= (int16) (Ships[WhoIAm].Object.Quat.x * 32767.0F);
		VeryShortGlobalShip.Quat.y		= (int16) (Ships[WhoIAm].Object.Quat.y * 32767.0F);
		VeryShortGlobalShip.Quat.z		= (int16) (Ships[WhoIAm].Object.Quat.z * 32767.0F);
		VeryShortGlobalShip.Status		= MyGameStatus;
		VeryShortGlobalShip.Angle.x		= (int16) (Ships[WhoIAm].Object.Angle.x * SHORTANGLEMODIFIERPACK );
		VeryShortGlobalShip.Angle.y		= (int16) (Ships[WhoIAm].Object.Angle.y * SHORTANGLEMODIFIERPACK );
		VeryShortGlobalShip.Angle.z		= (int16) (Ships[WhoIAm].Object.Angle.z * SHORTANGLEMODIFIERPACK );
		VeryShortGlobalShip.Bank = (int16) (Ships[ WhoIAm ].Object.Bank * SHORTBANKMODIFIER);
		SendGameMessage(MSG_VERYSHORTUPDATE, 0, 0, 0, 0);
	}
}

 
void DplayGameUpdate()
{
#ifndef SELF_PLAY
	int i;
	VECTOR	Move_Off;

	if( ( Ships[WhoIAm].Object.Flags & ( SHIP_PrimFire | SHIP_SecFire | SHIP_MulFire ) ) )
		Ships[WhoIAm].Object.Noise = 1.0F;

		
	if( dcoID == 0 )
	{
		// Has to be done to stop missiles getting stuck in walls....!!!!!!!!!!!!!
		Ships[ WhoIAm ].Object.Flags &=  ~( SHIP_PrimFire | SHIP_SecFire | SHIP_MulFire );
	}else{
		ReceiveGameMessages();
		
		if( ( Ships[WhoIAm].Object.Flags & ( SHIP_PrimFire | SHIP_SecFire | SHIP_MulFire ) ) )
		{
			if( !UseShortPackets )
			{
				FShortGlobalShip.Flags = BuildShipFlags(WhoIAm);
				FShortGlobalShip.GroupImIn	= (BYTE) Ships[WhoIAm].Object.Group;    // 
				FShortGlobalShip.Primary	= PrimaryToFireLookup[ Ships[WhoIAm].Primary ];
				FShortGlobalShip.Secondary	= SecondaryToFireLookup[ Ships[WhoIAm].Secondary ];
				FShortGlobalShip.Pos		= Ships[WhoIAm].Object.Pos		;	  // x , y , z position
				FShortGlobalShip.Move_Off	= Ships[WhoIAm].Move_Off;	  // Last Movement..x , y , z
				FShortGlobalShip.Quat	= Ships[WhoIAm].Object.Quat;// Final inverse view Quat.......after banking.. 
				FShortGlobalShip.PrimPowerLevel = (BYTE) Ships[ WhoIAm ].PrimPowerLevel;
				FShortGlobalShip.Angle = Ships[ WhoIAm ].Object.Angle;
#ifdef	SHORTBANK
				FShortGlobalShip.Bank = (int16) (Ships[ WhoIAm ].Object.Bank * SHORTBANKMODIFIER);
#else
				FShortGlobalShip.Bank = Ships[ WhoIAm ].Object.Bank;
#endif
				SendGameMessage(MSG_FUPDATE, 0, 0, 0, 0);
			}else{

				if( !BigPackets )
				{
					FVeryShortGlobalShip.Flags = BuildShipFlags(WhoIAm);
					FVeryShortGlobalShip.GroupImIn	= (BYTE) Ships[WhoIAm].Object.Group;    // 
					FVeryShortGlobalShip.Pos.x		= (int16) Ships[WhoIAm].Object.Pos.x;
					FVeryShortGlobalShip.Pos.y		= (int16) Ships[WhoIAm].Object.Pos.y;
					FVeryShortGlobalShip.Pos.z		= (int16) Ships[WhoIAm].Object.Pos.z;
					Move_Off = Ships[WhoIAm].Move_Off;
					NormaliseVector( &Move_Off );
					FVeryShortGlobalShip.Move_Off_Scalar = (uint16) ( 256.0F * VectorLength( &Ships[WhoIAm].Move_Off ) );
					FVeryShortGlobalShip.Move_Off.x	= (int16) (Move_Off.x * 32767.0F);
					FVeryShortGlobalShip.Move_Off.y	= (int16) (Move_Off.y * 32767.0F);
					FVeryShortGlobalShip.Move_Off.z	= (int16) (Move_Off.z * 32767.0F);
					FVeryShortGlobalShip.Quat.w		= (int16) (Ships[WhoIAm].Object.Quat.w * 32767.0F);
					FVeryShortGlobalShip.Quat.x		= (int16) (Ships[WhoIAm].Object.Quat.x * 32767.0F);
					FVeryShortGlobalShip.Quat.y		= (int16) (Ships[WhoIAm].Object.Quat.y * 32767.0F);
					FVeryShortGlobalShip.Quat.z		= (int16) (Ships[WhoIAm].Object.Quat.z * 32767.0F);
					FVeryShortGlobalShip.Angle.x	= (int16) (Ships[WhoIAm].Object.Angle.x * SHORTANGLEMODIFIERPACK );
					FVeryShortGlobalShip.Angle.y	= (int16) (Ships[WhoIAm].Object.Angle.y * SHORTANGLEMODIFIERPACK );
					FVeryShortGlobalShip.Angle.z	= (int16) (Ships[WhoIAm].Object.Angle.z * SHORTANGLEMODIFIERPACK );
					FVeryShortGlobalShip.Bank = (int16) (Ships[ WhoIAm ].Object.Bank * SHORTBANKMODIFIER);

					FVeryShortGlobalShip.Primary	= PrimaryToFireLookup[ Ships[WhoIAm].Primary ];
					FVeryShortGlobalShip.Secondary	= SecondaryToFireLookup[ Ships[WhoIAm].Secondary ];
					FVeryShortGlobalShip.PrimPowerLevel = (BYTE) Ships[ WhoIAm ].PrimPowerLevel;
					
					SendGameMessage(MSG_VERYSHORTFUPDATE, 0, 0, 0, 0);
				}else{
					GroupOnly_FVeryShortGlobalShip.Flags = BuildShipFlags(WhoIAm);
					GroupOnly_FVeryShortGlobalShip.GroupImIn	= (BYTE) Ships[WhoIAm].Object.Group;    // 
					GroupOnly_FVeryShortGlobalShip.Pos.x		= (int16) Ships[WhoIAm].Object.Pos.x;
					GroupOnly_FVeryShortGlobalShip.Pos.y		= (int16) Ships[WhoIAm].Object.Pos.y;
					GroupOnly_FVeryShortGlobalShip.Pos.z		= (int16) Ships[WhoIAm].Object.Pos.z;
					GroupOnly_FVeryShortGlobalShip.Quat.w		= (int16) (Ships[WhoIAm].Object.Quat.w * 32767.0F);
					GroupOnly_FVeryShortGlobalShip.Quat.x		= (int16) (Ships[WhoIAm].Object.Quat.x * 32767.0F);
					GroupOnly_FVeryShortGlobalShip.Quat.y		= (int16) (Ships[WhoIAm].Object.Quat.y * 32767.0F);
					GroupOnly_FVeryShortGlobalShip.Quat.z		= (int16) (Ships[WhoIAm].Object.Quat.z * 32767.0F);
					GroupOnly_FVeryShortGlobalShip.Bank = (int16) (Ships[ WhoIAm ].Object.Bank * SHORTBANKMODIFIER);
					GroupOnly_FVeryShortGlobalShip.Primary	= PrimaryToFireLookup[ Ships[WhoIAm].Primary ];
					GroupOnly_FVeryShortGlobalShip.Secondary	= SecondaryToFireLookup[ Ships[WhoIAm].Secondary ];
					GroupOnly_FVeryShortGlobalShip.PrimPowerLevel = (BYTE) Ships[ WhoIAm ].PrimPowerLevel;
					SendGameMessage(MSG_GROUPONLY_VERYSHORTFUPDATE, 0, 0, 0, 0);
				}

			}
			Ships[ WhoIAm ].Object.Flags &=  ~( SHIP_PrimFire | SHIP_SecFire | SHIP_MulFire );
			Interval = DPlayUpdateInterval;
		
		}
		else
		{
			if( !BigPackets )
			{
				Interval -= framelag;
				if( Interval <= 0.0F )
				{
					Interval = DPlayUpdateInterval;
					SendANormalUpdate();
				}
			}
		}

 		HostDutyTimer -= framelag;

		if( HostDutyTimer <= 0.0F )
		{
			HostDutyTimer = DPlayUpdateIntervalHostDuties;
			HostDuties = FALSE;
			// If someone has joined or somebody requests it then send everyone a stats update
			if( IsHost == TRUE )
			{
//				if( (StatsCount > -1) && (StatsCount <= MAX_PLAYERS) )
//				{
//					StatsCount -= 1;
//					SendGameMessage(MSG_SHORTSTATS, 0, (BYTE) StatsCount, 0, 0);
//					HostDuties = TRUE;
//				
//				}
				
				for( i = 0 ; i < MAX_PLAYERS ; i++ )
				{
					if( ( i != WhoIAm ) && (GameStatus[i] == STATUS_Joining ) ) 
					{
						if( Ships[i].RegenSlots != 0 )
						{
							SendGameMessage( MSG_SHORTREGENSLOT, 0, (BYTE) i, 0, 0 );
							HostDuties = TRUE;
							Ships[i].RegenSlots = 0;
						}
						else if( Ships[i].Triggers != 0 ) 
						{
							SendGameMessage( MSG_SHORTTRIGGER, 0, (BYTE) i, 0, 0 );
							HostDuties = TRUE;
							Ships[i].Triggers = 0;
						}
						else if( Ships[i].TrigVars != 0 )
						{
							SendGameMessage( MSG_SHORTTRIGVAR, 0, (BYTE) i, 0, 0 );
							HostDuties = TRUE;
							Ships[i].TrigVars = 0;
						}
						else if( Ships[i].Mines != 0 )
						{
							SendGameMessage( MSG_SHORTMINE, 0, (BYTE) i, 0, 0 );
							HostDuties = TRUE;
							Ships[i].Mines = 0;
						}
						else if(	Ships[i].Pickups != 0 )
						{
							SendGameMessage( MSG_SHORTPICKUP, 0, (BYTE) i, 0, 0 );
							HostDuties = TRUE;
							Ships[i].Pickups = 0;
						}
						// reset them untill we get another request.....
					}
				}
			}
		}
	}
	if( IsHost )
	{
		if( GMs )
		{
			// as the host you must wait for guarenteed message to finish....
			HostDuties = TRUE;
		}
	}else{
		if( GMs )
		{
			// Even if im not the host I should not quit if guarenteed messages have been qued...
			HostDuties = TRUE;
		}else{
			HostDuties = FALSE;
		}
	}

	// The Host can Dynamicaly change the Update interval.....
	if( IsHost && !CurrentMenu )
	{
		if ( OldPPSValue != PacketsSlider.value )
		{
			OldPPSValue = PacketsSlider.value;
			DPlayUpdateInterval	= (60.0F / PacketsSlider.value);
			SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
		}
	}
#endif
}


void PrimBullPosDirSend( uint16 OwnerType, uint16 OwnerID, uint16 BulletID, int8 Weapon,
						uint16 Group, VECTOR * Pos, VECTOR * Offset, VECTOR * Dir, VECTOR * Up,
						int16 PowerLevel, float PLevel )
{
	if( dcoID != 0 )
	{

		TempPrimBullPosDir.OwnerType = OwnerType;
		TempPrimBullPosDir.OwnerID = OwnerID;
		TempPrimBullPosDir.BulletID = BulletID;
		TempPrimBullPosDir.Weapon = Weapon;
		TempPrimBullPosDir.Group = Group;
		TempPrimBullPosDir.Pos = *Pos;
		TempPrimBullPosDir.Offset = *Offset;
		TempPrimBullPosDir.Dir = *Dir;
		TempPrimBullPosDir.Up = *Up;
		TempPrimBullPosDir.PowerLevel = PowerLevel;
		TempPrimBullPosDir.PLevel = PLevel;
		SendGameMessage(MSG_PRIMBULLPOSDIR, 0, 0, 0, 0);
	}
}

void SecBullPosDirSend( uint16 OwnerType, uint16 Owner, uint16 BulletID, uint16 Group,
					    VECTOR * Pos, VECTOR * Offset, VECTOR * Dir, VECTOR * UpVector,
						VECTOR * DropDir, int8 Weapon )
{
	if( dcoID != 0 )
	{
		TempSecBullPosDir.OwnerType = OwnerType;
		TempSecBullPosDir.Owner = Owner;
		TempSecBullPosDir.BulletID = BulletID;
		TempSecBullPosDir.Group = Group;
    	TempSecBullPosDir.Pos = *Pos;
		TempSecBullPosDir.Offset = *Offset;
		TempSecBullPosDir.Dir = *Dir;
		TempSecBullPosDir.UpVector = *UpVector;
		TempSecBullPosDir.DropDir = *DropDir;
		TempSecBullPosDir.Weapon = Weapon;
		SendGameMessage(MSG_SECBULLPOSDIR, 0, 0, 0, 0);
	}
}

void TitanBitsSend( uint16 OwnerType, uint16 Owner, uint16 BulletID, uint16 Group,
					    VECTOR * Pos, VECTOR * Offset, VECTOR * UpVector,
						VECTOR * DropDir, int8 Weapon, VECTOR * Directions )
{
	int16	Count;

	if( dcoID != 0 )
	{
		TempTitanBits.OwnerType = OwnerType;
		TempTitanBits.Owner = Owner;
		TempTitanBits.BulletID = BulletID;
		TempTitanBits.Group = Group;
    	TempTitanBits.Pos = *Pos;
		TempTitanBits.Offset = *Offset;
		TempTitanBits.UpVector = *UpVector;
		TempTitanBits.DropDir = *DropDir;
		TempTitanBits.Weapon = Weapon;
		for( Count = 0; Count < NUMTITANBITS; Count++ )
		{
			TempTitanBits.Directions[ Count ] = Directions[ Count ];
		}

		SendGameMessage(MSG_TITANBITS, 0, 0, 0, 0);
	}
}

void	IHitYou( BYTE you, float Damage, VECTOR * Recoil, VECTOR * Point, VECTOR * Dir, float Force, BYTE WeaponType, BYTE Weapon, BOOL FramelagRecoil )
{
	VECTOR	Recoil_Off;
	if( BombTag )
	{
		if( LowestBombTime != -1 )
		{
			BombNumToSend = LowestBombTime;
			BombTimeToSend = BombTime[LowestBombTime];
			SendGameMessage( MSG_BOMB , 0 , you , 0 , 0 );
			BombActive[LowestBombTime] = FALSE;
			LowestBombTime = -1;
		}
	}else{
		
		if( Ships[ you ].Object.Mode != LIMBO_MODE )
		{
			if( dcoID != 0 )
			{
				if( !UseShortPackets )
				{
					if( FramelagRecoil ) TempShipHit.OneOffExternalForce = TRUE;
					else TempShipHit.OneOffExternalForce = FALSE;
					TempShipHit.Damage = Damage;
					TempShipHit.Recoil = *Recoil;
					TempShipHit.Point = *Point;
					TempShipHit.Point.x -= Ships[ you ].Object.Pos.x;
					TempShipHit.Point.y -= Ships[ you ].Object.Pos.y;
					TempShipHit.Point.z -= Ships[ you ].Object.Pos.z;
					TempShipHit.Dir = *Dir;
					TempShipHit.Force = Force;
					TempShipHit.WeaponType = WeaponType;
					TempShipHit.Weapon = Weapon;
					SendGameMessage( MSG_SHIPHIT , Ships[you].dcoID , you , 0 , 0 );
				}else{
					if( FramelagRecoil ) ShortTempShipHit.OneOffExternalForce = 1;
					else ShortTempShipHit.OneOffExternalForce = 0;
					ShortTempShipHit.Damage = Damage;

					Recoil_Off = *Recoil;
					NormaliseVector( &Recoil_Off );
					ShortTempShipHit.Recoil_Scalar = (uint16) ( 256.0F * VectorLength( Recoil ) );
					ShortTempShipHit.Recoil.x = (int16) (Recoil_Off.x * 32767.0F);
					ShortTempShipHit.Recoil.y = (int16) (Recoil_Off.y * 32767.0F);
					ShortTempShipHit.Recoil.z = (int16) (Recoil_Off.z * 32767.0F);
					ShortTempShipHit.Point.x = (int16)(Point->x - Ships[ you ].Object.Pos.x);
					ShortTempShipHit.Point.y = (int16)(Point->y - Ships[ you ].Object.Pos.y);
					ShortTempShipHit.Point.z = (int16)(Point->z - Ships[ you ].Object.Pos.z);
					ShortTempShipHit.Dir.x = (int16) (Dir->x * 32767.0F);
					ShortTempShipHit.Dir.y = (int16) (Dir->y * 32767.0F);
					ShortTempShipHit.Dir.z = (int16) (Dir->z * 32767.0F);
					ShortTempShipHit.Force = Force;
					ShortTempShipHit.WeaponType = WeaponType;
					ShortTempShipHit.Weapon = Weapon;
					SendGameMessage( MSG_SHORTSHIPHIT , Ships[you].dcoID , you , 0 , 0 );

				}
			}
		}
	}
}


void	DropPickupSend( VECTOR * Pos, uint16 Group, VECTOR * Dir, float Speed, int16 Type, uint16 IDCount, int16 RegenSlot, BOOL Sparkle, float LifeCount, uint16 TriggerMod )
{
	if( dcoID != 0 )
	{
		if( !UseShortPackets )
		{
			TempPickup.IDCount = IDCount;
			TempPickup.Type = Type;
			TempPickup.Group = Group;
			TempPickup.Pos = *Pos;
			TempPickup.Dir = *Dir;
			TempPickup.Speed = Speed;
			TempPickup.RegenSlot = RegenSlot;
			TempPickup.Sparkle = Sparkle;
			TempPickup.LifeCount = LifeCount;
			TempPickup.TriggerMod = TriggerMod;
			SendGameMessage( MSG_DROPPICKUP, 0, 0, 0, 0 );
		}else{
			VeryShortTempPickup.IDCount = IDCount;
			VeryShortTempPickup.Type = (BYTE)Type;
			VeryShortTempPickup.Group = (BYTE) Group;
			VeryShortTempPickup.Pos.x = (int16) Pos->x;
			VeryShortTempPickup.Pos.y = (int16) Pos->y;
			VeryShortTempPickup.Pos.z = (int16) Pos->z;
			VeryShortTempPickup.Dir.x = (int16) (Dir->x * 32767.0F);
			VeryShortTempPickup.Dir.y = (int16) (Dir->y * 32767.0F);
			VeryShortTempPickup.Dir.z = (int16) (Dir->z * 32767.0F);
			VeryShortTempPickup.Speed = Speed;
			VeryShortTempPickup.RegenSlot = (BYTE) RegenSlot;
			VeryShortTempPickup.Sparkle = Sparkle;
			VeryShortTempPickup.LifeCount = LifeCount;
			VeryShortTempPickup.TriggerMod = TriggerMod;
			SendGameMessage( MSG_VERYSHORTDROPPICKUP, 0, 0, 0, 0 );
		}
	}
}

void	KillPickupSend( uint16 Owner, uint16 IDCount, int16 Style )
{
	if( dcoID != 0 )
	{
		TempKillPickup.Owner = Owner;
		TempKillPickup.IDCount = IDCount;
		TempKillPickup.Style = Style;
		SendGameMessage( MSG_KILLPICKUP, 0, 0, 0, 0 );
	}
}

void	ServerKillPickupSend( uint16 Owner, uint16 IDCount, int16 Style, uint16 NewOwner )
{
	if( dcoID != 0 )
	{
		TempServerKillPickup.Owner = Owner;
		TempServerKillPickup.IDCount = IDCount;
		TempServerKillPickup.Style = Style;
		TempServerKillPickup.NewOwner = NewOwner;
		SendGameMessage( MSG_SERVERKILLPICKUP, 0, 0, 0, 0 );
	}
}

void	ExplodeShip( uint16 Ship )
{
	if( dcoID != 0 )
	{
		TempExplodeShip.Ship = Ship;
		SendGameMessage( MSG_EXPLODESHIP, 0, 0, 0, 0 );
	}
}

void	ExplodeSecondarySend( VECTOR * Pos, uint16 Group, uint16 OwnerType, uint16 Owner, uint16 IDCount, float ShockwaveSize )
{
	if( dcoID != 0 )
	{
		TempExplodeSecondary.OwnerType = OwnerType;
		TempExplodeSecondary.Owner = Owner;
		TempExplodeSecondary.IDCount = IDCount;
		TempExplodeSecondary.ShockwaveSize = ShockwaveSize;
		TempExplodeSecondary.Pos = *Pos;
		TempExplodeSecondary.Group = Group;
		SendGameMessage( MSG_EXPSECONDARY, 0, 0, 0, 0 );
	}
}

void	TeamGoalsSend( uint16 * TeamGoals )
{
	if( dcoID != 0 )
	{
		int i;

		for( i = 0; i < MAX_TEAMS; i++ ) TempTeamGoals.TeamGoals[ i ] = TeamGoals[ i ];
		SendGameMessage( MSG_TEAMGOALS, 0, 0, 0, 0 );
	}
}

void	CreateShockwaveSend( uint16 OwnerShip, uint16 Owner, VECTOR * Pos, uint16 Group, float ShockwaveSize, BYTE Weapon )
{
	if( dcoID != 0 )
	{
		TempShockwave.Owner = Owner;
		TempShockwave.Pos = *Pos;
		TempShockwave.Group = Group;
		TempShockwave.Weapon = Weapon;
		TempShockwave.ShockwaveSize = ShockwaveSize;
		SendGameMessage( MSG_SHOCKWAVE, 0, 0, 0, 0 );
	}
}

void	UpdateBGObjectSend( uint16 BGObject, int16 State, float Time )
{
	if( dcoID != 0 )
	{
		TempBGOUpdate.BGObject = BGObject;
		TempBGOUpdate.State = State;
		TempBGOUpdate.Time = Time;
		SendGameMessage( MSG_BGOUPDATE, 0, 0, 0, 0 );
	}
}

void	ShipDiedSend( BYTE WeaponType, BYTE Weapon )
{
	if( dcoID != 0 )
	{
		TempDied.WeaponType = WeaponType;
		TempDied.Weapon = Weapon;
		SendGameMessage( MSG_SHIPDIED, 0, 0, 0, 0 );
	}
}

void	RequestTime( void  )
{
	if( dcoID != 0 )
	{
		SendGameMessage( MSG_REQTIME, 0, 0, 0, 0 );
	}
}

void	SetTime( float Time )
{
	if( dcoID != 0 )
	{
		TempTimeSet.Time = Time;
		SendGameMessage( MSG_SETTIME, 0, 0, 0, 0 );
	}
}


void SetupDplayGame()
{
	int16 i,Count;

	memset(&PlayerIP, 0, sizeof(PlayerIP));

	BigPacketOffset = 2;
	BigPacketCommBuff[2] = 0;
	LastBigPacketSent = 0;
	for( i = 0 ; i < 256 ; i++ )
	{
		RealPacketSize[i] = 0;
	}

	RealPacketSize[MSG_UPDATE				 ] = sizeof( UPDATEMSG				  );	
	RealPacketSize[MSG_HEREIAM				 ] = sizeof( HEREIAMMSG				  );	
	RealPacketSize[MSG_INIT					 ] = sizeof( INITMSG				  );	 
	RealPacketSize[MSG_SHIPHIT				 ] = sizeof( SHIPHITMSG				  );	
	RealPacketSize[MSG_PRIMBULLPOSDIR		 ] = sizeof( PRIMBULLPOSDIRMSG		  );	
	RealPacketSize[MSG_SECBULLPOSDIR		 ] = sizeof( SECBULLPOSDIRMSG		  );	
	RealPacketSize[MSG_SHIPDIED				 ] = sizeof( SHIPDIEDMSG			  );	 
	RealPacketSize[MSG_DROPPICKUP			 ] = sizeof( DROPPICKUPMSG			  );	
	RealPacketSize[MSG_KILLPICKUP			 ] = sizeof( KILLPICKUPMSG			  );	
	RealPacketSize[MSG_SHORTSTATS			 ] = sizeof( SHORTSTATSMSG			  );	
	RealPacketSize[MSG_STATUS				 ] = sizeof( STATUSMSG				  );	
	RealPacketSize[MSG_EXPSECONDARY			 ] = sizeof( EXPSECONDARYMSG		  );	 
	RealPacketSize[MSG_SHORTPICKUP			 ] = sizeof( SHORTPICKUPMSG			  );	
	RealPacketSize[MSG_SHOCKWAVE			 ] = sizeof( SHOCKWAVEMSG			  );	
	RealPacketSize[MSG_FUPDATE				 ] = sizeof( FUPDATEMSG				  );	
	RealPacketSize[MSG_SHORTMINE			 ] = sizeof( SHORTMINEMSG			  );	
	RealPacketSize[MSG_TEXTMSG				 ] = sizeof( TEXTMSG				  );	
	RealPacketSize[MSG_SHORTREGENSLOT		 ] = sizeof( SHORTREGENSLOTMSG		  );	
	RealPacketSize[MSG_SHORTTRIGGER			 ] = sizeof( SHORTTRIGGERMSG		  );	 
	RealPacketSize[MSG_SHORTTRIGVAR			 ] = sizeof( SHORTTRIGVARMSG		  );	 
	RealPacketSize[MSG_NAME					 ] = sizeof( NAMEMSG				  );	 
	RealPacketSize[MSG_INTERPOLATE			 ] = sizeof( INTERPOLATEMSG			  );	
	RealPacketSize[MSG_BOMB					 ] = sizeof( BOMBMSG				  );	 
	RealPacketSize[MSG_BGOUPDATE			 ] = sizeof( BGOUPDATEMSG			  );	
	RealPacketSize[MSG_PINGREQUEST			 ] = sizeof( PINGMSG				  );	
	RealPacketSize[MSG_PLAYERPINGS			 ] = sizeof( PLAYERPINGSMSG			  );	
	RealPacketSize[MSG_PINGREPLY			 ] = sizeof( PINGMSG				  );	
	RealPacketSize[MSG_LONGSTATUS			 ] = sizeof( LONGSTATUSMSG			  );	
	RealPacketSize[MSG_SETTIME				 ] = sizeof( SETTIMEMSG				  );	
	RealPacketSize[MSG_REQTIME				 ] = sizeof( REQTIMEMSG				  );	
	RealPacketSize[MSG_ACKMSG				 ] = sizeof( ACKMSG					  );	
	RealPacketSize[MSG_GUARANTEEDMSG		 ] = sizeof( GUARANTEEDMSG   		  );	
	RealPacketSize[MSG_KILLSDEATHSBIKENUM	 ] = sizeof( KILLSDEATHSBIKENUMMSG	  );	
	RealPacketSize[MSG_VERYSHORTUPDATE		 ] = sizeof( VERYSHORTUPDATEMSG		  );	
	RealPacketSize[MSG_VERYSHORTFUPDATE		 ] = sizeof( VERYSHORTFUPDATEMSG	  );	 
	RealPacketSize[MSG_ALIVE				 ] = sizeof( ALIVEMSG				  );	
	RealPacketSize[MSG_VERYSHORTINTERPOLATE	 ] = sizeof( VERYSHORTINTERPOLATEMSG  );	 
	RealPacketSize[MSG_TEAMGOALS			 ] = sizeof( TEAMGOALSMSG			  );	
	RealPacketSize[MSG_YOUQUIT				 ] = sizeof( YOUQUITMSG				  );	
	RealPacketSize[MSG_SENDKILLSDEATHSBIKENUM] = sizeof( SENDKILLSDEATHSBIKENUMMSG);	
	RealPacketSize[MSG_SHORTSHIPHIT			 ] = sizeof( SHORTSHIPHITMSG		  );	 
	RealPacketSize[MSG_TITANBITS			 ] = sizeof( TITANBITSMSG			  );	
	RealPacketSize[MSG_GAMEPARAMETERS		 ] = sizeof( GAMEPARAMETERSMSG		  );	
#ifdef MANUAL_SESSIONDESC_PROPAGATE
	RealPacketSize[MSG_SESSIONDESC			 ] = sizeof( SESSIONDESCMSG			  );	
#endif
	RealPacketSize[MSG_TOSERVER				 ] = sizeof( TOSERVERMSG			  );	
	RealPacketSize[MSG_TOCLIENT				 ] = sizeof( TOCLIENTMSG			  );	
	RealPacketSize[MSG_SERVERKILLPICKUP		 ] = sizeof( SERVERKILLPICKUPMSG	  );	
	RealPacketSize[MSG_LEVELNAMES			 ] = sizeof( LEVELNAMESMSG			  );	
	RealPacketSize[MSG_TRACKERINFO			 ] = sizeof( TRACKERINFOMSG			  );	
	
	RealPacketSize[MSG_SERVERUPDATE			 ] = sizeof( SERVERUPDATEMSG		  );	
	RealPacketSize[MSG_EXPLODESHIP			 ] = sizeof( EXPLODESHIPMSG			  );

	RealPacketSize[MSG_SHIELDHULL			 ] = sizeof( SHIELDHULLMSG			  );
	RealPacketSize[MSG_SERVERSCORED			 ] = sizeof( SERVERSCOREDMSG		  );
	RealPacketSize[MSG_GROUPONLY_VERYSHORTFUPDATE		 ] = sizeof( GROUPONLY_VERYSHORTFUPDATEMSG );	 
	RealPacketSize[MSG_VERYSHORTDROPPICKUP			 ] = sizeof( VERYSHORTDROPPICKUPMSG			  );	
	

#ifdef DEBUG_ON
	for( i = 0 ; i < 256 ; i++ )
	{
		PacketGot[i] = 0;
		PacketSize[i] = 0;

	}
#endif

	InitAcknowledgeMessageQue();
	InitServerMessageQue();

	memset(&Ships[0], 0, ( sizeof(GLOBALSHIP) * ( MAX_PLAYERS + 1 ) ) );
	memset(&Names, 0, sizeof(SHORTNAMETYPE) );

	memset(&Stats, 0, sizeof(int16) * MAX_PLAYERS * MAX_PLAYERS );

	memset(&PrimaryStats, 0, sizeof(uint16) * TOTALPRIMARYWEAPONS*2 );
	memset(&SecondaryStats, 0, sizeof(uint16) * TOTALSECONDARYWEAPONS*2 );

	AddCommentToLog( "SetupDPlayGame()\n ");
	

	for( i = 0 ; i < MAXBOMBS ; i++ )
	{
		BombActive[i] = FALSE;
		BombTime[i] = 100.0F * 30.0F;
	}
	JustGenerated = TRUE;
	
	for(i=0; i<(MAX_PLAYERS+1); i++)
	{
		// everyone starts off normal....
		GameStatus[i] = STATUS_Null;
		BadConnection[ i ] = FALSE;

		CanDoDamage[i] = TRUE;
	
		Ships[i].BikeNum = ( i % MAXBIKETYPES );
		Ships[i].ModelNum = (uint16) -1;
		ScoreSortTab[i] = (int) i;
	
		
		Ships[i].Object.Type = OBJECT_TYPE_SHIP;
		Ships[i].Object.Mode = NORMAL_MODE;
		Ships[i].Object.Bank = 0.0F;
		Ships[i].Object.Shield	= Start_Shield;
		Ships[i].Object.Hull	= Start_Hull;
		Ships[i].JustRecievedPacket = TRUE;
		Ships[i].Object.light = (uint16) -1;
		for( Count = 0; Count < MAXMULTIPLES; Count++ ) Ships[i].OrbModels[ Count ] = (uint16) -1;
		Ships[i].NumMultiples = 0;
		MakeQuat( 0.0F, 0.0F, 0.0F, &Ships[i].Object.Quat );
		
		Ships[i].Object.Pos.x = 0.0F;;
		Ships[i].Object.Pos.y = 0.0F;;
		Ships[i].Object.Pos.z = 0.0F;;
		Ships[i].Object.Group = 0;
		
		Ships[i].enable = 0;
	
		Ships[i].Object.Mat = TempMatrix;
		Ships[i].Object.FinalMat = TempMatrix;
		Ships[i].Object.FinalInvMat = TempMatrix;
	
		Ships[i].FirstPacketRecieved = TRUE;
		// reset external and internal force vectors to ship movement
		Ships[i].Object.ExternalForce.x = 0.0F;
		Ships[i].Object.ExternalForce.y = 0.0F;
		Ships[i].Object.ExternalForce.z = 0.0F;
		Ships[i].Object.InternalForce.x = 0.0F;
		Ships[i].Object.InternalForce.y = 0.0F;
		Ships[i].Object.InternalForce.z = 0.0F;
		Ships[i].Object.Autolevel = 0.0F;
		Ships[i].Object.BobCount = 0.0F;

		for( Count = 0; Count < 12; Count++ ) Ships[i].TempLines[ Count ] = (uint16) -1;
	}
}

void InitShipStructure( int i , BOOL ResetScore )
{
	int16 Count;


//	memset(&Ships[i], 0, sizeof(GLOBALSHIP) );

	CanDoDamage[i] = TRUE;
	BadConnection[ i ] = FALSE;

	Ships[i].BikeNum = ( i % MAXBIKETYPES );
	Ships[i].ShieldHullCount = 0;
	
	Ships[i].Object.Type = OBJECT_TYPE_SHIP;
	Ships[i].Object.Mode = NORMAL_MODE;
	Ships[i].Object.Bank = 0.0F;
	Ships[i].Object.Shield	= Start_Shield;
	Ships[i].Object.Hull	= Start_Hull;
	Ships[i].JustRecievedPacket = TRUE;
	Ships[i].Object.light = (uint16) -1;
	for( Count = 0; Count < MAXMULTIPLES; Count++ ) Ships[i].OrbModels[ Count ] = (uint16) -1;
	Ships[i].NumMultiples = 0;
	MakeQuat( 0.0F, 0.0F, 0.0F, &Ships[i].Object.Quat );
	
	Ships[i].Object.Pos.x = 0.0F;;
	Ships[i].Object.Pos.y = 0.0F;;
	Ships[i].Object.Pos.z = 0.0F;;
	Ships[i].Object.Group = 0;
	
	Ships[i].enable = 0;

	Ships[i].Object.Mat = TempMatrix;
	Ships[i].Object.FinalMat = TempMatrix;
	Ships[i].Object.FinalInvMat = TempMatrix;

	Ships[i].FirstPacketRecieved = TRUE;
	// reset external and internal force vectors to ship movement
	Ships[i].Object.ExternalForce.x = 0.0F;
	Ships[i].Object.ExternalForce.y = 0.0F;
	Ships[i].Object.ExternalForce.z = 0.0F;
	Ships[i].Object.InternalForce.x = 0.0F;
	Ships[i].Object.InternalForce.y = 0.0F;
	Ships[i].Object.InternalForce.z = 0.0F;
	Ships[i].Object.Autolevel = 0.0F;
	Ships[i].Object.BobCount = 0.0F;
	if( ResetScore )
	{
		Ships[i].Deaths = 0;
		Ships[i].Kills = 0;
	}


	for( Count = 0; Count < 12; Count++ ) Ships[i].TempLines[ Count ] = (uint16) -1;
}




void DestroyGame( void )
{
	int	i;
	VECTOR	DirVector = { 0.0F, 0.0F, 0.0F };

	if( PlayDemo )
		return;
	
	Ships[WhoIAm].enable = 0;
	MyGameStatus = STATUS_Left;
	IsHost = FALSE;

    if ( ( glpDP != NULL ) && ( dcoID != 0 ) && ( WhoIAm < MAX_PLAYERS ) )
    {
		DebugPrintf("Destroy game pos 1\n");

		if( !IsServerGame )
		{
			KillOwnersSecBulls( WhoIAm );

			if( GodMode ) LoseAllWeapons();

			ScatterWeapons( &DirVector, MAXPICKUPS );
			RegeneratePickups();
		}

		SendGameMessage(MSG_STATUS, 0, 0, 1, 0);	// 1 for type indicates "give someone else on my team my current score" ( if team game )
		if( TeamGame )
		{
			// kills would have been sent to somebody else on team, so reset
			Ships[WhoIAm].Kills = 0;
		}

		ProcessGuaranteedMessages( FALSE , TRUE , TRUE );
		ServiceBigPacket(TRUE);
		ServiceServer( TRUE );
		
		DPlayGetSessionDesc();
		DPlayDestroyPlayer(dcoID);
		DPlayRelease();
		dcoID = 0;

		Old_Session = *glpdpSD;
		Old_WhoIAm = WhoIAm;

		if( TeamGame || CTF || CaptureTheFlag || BountyHunt || MaxKills )
		{
			Old_Kills = 0;
			Old_TeamNumber = 0;
			Old_Deaths = 0;
		}else{
			Old_Kills = Ships[WhoIAm].Kills;
			Old_TeamNumber = TeamNumber[WhoIAm];
			Old_Deaths = Ships[WhoIAm].Deaths;
		}
		for( i = 0 ; i < 256 ; i++ )
		{
			Old_Name[i] = biker_name[i];
		}
		// Stores all the info needed in the registry...
		SetLastGameInfo();

		if (glpdpSD) 
		{
			DebugPrintf("Destroy game pos 2\n");
			free(glpdpSD);
			glpdpSD = NULL;
		}


	}else{

		DebugPrintf("Destroy game pos a\n");
		if( dcoID )
		{
			DebugPrintf("Destroy game pos b\n");
			DPlayDestroyPlayer(dcoID);
			DPlayRelease();
			dcoID = 0;
		}

		if (glpdpSD) 
		{
			DebugPrintf("Destroy game pos c\n");
			free(glpdpSD);
			glpdpSD = NULL;
		}
	}

#ifdef DEBUG_ON
				if( DS )
				{
					for( i = 0 ; i < 256 ; i++ )
					{
						if( PacketGot[i] )
						{
							DebugPrintf("num %3d quantity %12d size %12d\n", i, PacketGot[i] , PacketSize[i] );
						}
					}
				}

#endif

}



void initShip( uint16 i )
{
	uint16	spos;
	int16	Count;

	Ships[i].Object.NodeNetwork = 0;
	Ships[i].Object.NearestNode = NULL;
	Ships[i].Object.Type = OBJECT_TYPE_SHIP;

    Ships[i].enable = 1;
    Ships[i].Pickups = ( ( MAXPICKUPS + ( MAXGENPICKUPCOUNT - 1 ) ) / MAXGENPICKUPCOUNT	);
    Ships[i].RegenSlots = ( ( NumRegenPoints + ( MAXGENREGENSLOTCOUNT - 1 ) ) / MAXGENREGENSLOTCOUNT );
    Ships[i].Mines = ( ( MAXSECONDARYWEAPONBULLETS + ( MAXGENMINECOUNT - 1 ) ) / MAXGENMINECOUNT );
    Ships[i].Triggers = ( ( NumOfTriggers + ( MAXGENTRIGGERCOUNT - 1 ) ) / MAXGENTRIGGERCOUNT );
    Ships[i].TrigVars = ( ( NumOfTrigVars + ( MAXGENTRIGVARCOUNT - 1 ) ) / MAXGENTRIGVARCOUNT );

    Ships[i].NumMultiples = 0;
	for( Count = 0; Count < MAXMULTIPLES; Count++ ) Ships[i].OrbModels[ Count ] = (uint16) -1;

	if ( Mloadheader.state == TRUE)
	{
		spos = (i+RandomStartPosModify) % num_start_positions;
		InitShipStartPos( i, spos );
	}
	else
	{
		InitShipStartPos( i, 0 );
	}

	KillAllPickups();
}
void smallinitShip( uint16 i )
{
	uint16	spos;
	int16	Count;

	Ships[i].Object.NodeNetwork = 0;
	Ships[i].Object.NearestNode = NULL;
	Ships[i].Object.Type = OBJECT_TYPE_SHIP;

    Ships[i].enable = 1;
    Ships[i].Pickups = 0;
    Ships[i].RegenSlots = 0;
    Ships[i].Mines = 0;
    Ships[i].Triggers = 0;
    Ships[i].TrigVars = 0;
    Ships[i].NumMultiples = 0;
	for( Count = 0; Count < MAXMULTIPLES; Count++ ) Ships[i].OrbModels[ Count ] = (uint16) -1;

	NumMissedPickups = 0;
	NumMissedInitPickups = 0;
	NumMissedKillPickups = 0;

	NumMissedMines = 0;
	NumMissedInitMines = 0;
	NumMissedKillMines = 0;

	if ( Mloadheader.state == TRUE)
	{
		spos = (i+RandomStartPosModify) % num_start_positions;
		InitShipStartPos( i, spos );
	}
	else
	{
		InitShipStartPos( i, 0 );
	}
}


void ReceiveGameMessages( void )
{
#ifndef SELF_PLAY
	DPID	dcoReceiveID;
    DWORD               nBytes;
	BYTE * BufferPnt;
	DWORD * dwordpnt;
	DWORD offset = 0;
	LONGLONG * longpnt;
	HRESULT status;
	int i;

	for( i = 0 ; i < MAX_PLAYERS ; i++ )
	{
		OldGameStatus[i] = GameStatus[i];
	}

	if( MyGameStatus == STATUS_Normal )
	{

		BytesPerSecTimer -= framelag;
		if( BytesPerSecTimer < 0.0F )
		{
			BytesPerSecTimer = 71.0F;
			CurrentBytesPerSecRec = BytesPerSecRec;
			CurrentBytesPerSecSent = BytesPerSecSent;

			if( CurrentBytesPerSecRec > MaxCurrentBytesPerSecRec )
				MaxCurrentBytesPerSecRec = CurrentBytesPerSecRec;
			if( CurrentBytesPerSecSent > MaxCurrentBytesPerSecSent )
				MaxCurrentBytesPerSecSent = CurrentBytesPerSecSent;
			BytesPerSecRec = 0;
			BytesPerSecSent = 0;
		}
	}else{
		BytesPerSecRec = 0;
		BytesPerSecSent = 0;
		CurrentBytesPerSecRec = 0;
		CurrentBytesPerSecSent = 0;
		MaxCurrentBytesPerSecRec = 0;
		MaxCurrentBytesPerSecSent = 0;
		RecPacketSize = BigPacketSize = MaxRecPacketSize = MaxBigPacketSize = 0;

		BytesPerSecTimer = 71.0F;
	}



	// Stuff to handle Kills And deaths....
	if( MyGameStatus == STATUS_Normal )
	{
		if( (NextworkOldKills != Ships[WhoIAm].Kills) || (NextworkOldDeaths != Ships[WhoIAm].Deaths) || (NextworkOldBikeNum != Ships[WhoIAm].BikeNum) )
		{
			NextworkOldKills = Ships[WhoIAm].Kills;
			NextworkOldDeaths = Ships[WhoIAm].Deaths;
			NextworkOldBikeNum = Ships[WhoIAm].BikeNum;
			SendGameMessage( MSG_KILLSDEATHSBIKENUM, 0, 0, 0, 0 );
		}

	}
	ServiceBigPacket(FALSE);
	ProcessGuaranteedMessages( FALSE , FALSE , FALSE );
	ProcessAcknowledgeMessageQue();
	BuildReliabilityTab();
	ServiceServer( FALSE );
//	CheckServerDeathTimes();


	if( DplayRecieveThread )
	{
		if( Buffer2Count && !Buffer2InUse )
		{
			Buffer2InUse = TRUE;

			while( Buffer2Count )
			{

				longpnt = (LONGLONG*) (Buffer2Pnt+offset);
				TempTime = *longpnt++;
				dwordpnt = (DWORD*) longpnt;
				nBytes = *dwordpnt++;
				from_dcoID = *dwordpnt++;
				BufferPnt = (BYTE*) dwordpnt;

				if( RecordDemo && ( MyGameStatus == STATUS_Normal ) && ( from_dcoID != DPID_SYSMSG ) )
				{
					if( *BufferPnt != MSG_GUARANTEEDMSG && *BufferPnt != MSG_ACKMSG && *BufferPnt != MSG_BIGPACKET )
					{
						Demo_fwrite( (Buffer2Pnt+offset), nBytes + (sizeof(DWORD)*2) + sizeof(LONGLONG), 1, DemoFp );
					}
				}
				
				offset += sizeof(DWORD) + (sizeof(DPID)*1) + nBytes + sizeof(LONGLONG);
				if ( from_dcoID == DPID_SYSMSG )    EvalSysMessage( nBytes , BufferPnt );
				else EvaluateMessage( nBytes , BufferPnt );
				Buffer2Count-=1;

			}
			Buffer2Offset = 0;
			Buffer2InUse = FALSE;
		}
		offset = 0;
		if( Buffer1Count && !Buffer1InUse)
		{
			Buffer1InUse = TRUE;

			while( Buffer1Count )
			{

				longpnt = (LONGLONG*) (Buffer1Pnt+offset);
				TempTime = *longpnt++;
				dwordpnt = (DWORD*) longpnt;
				nBytes = *dwordpnt++;
				from_dcoID = *dwordpnt++;
				BufferPnt = (BYTE*) dwordpnt;

				if( RecordDemo && ( MyGameStatus == STATUS_Normal ) && ( from_dcoID != DPID_SYSMSG ) )
				{
					if( *BufferPnt != MSG_GUARANTEEDMSG && *BufferPnt != MSG_ACKMSG && *BufferPnt != MSG_BIGPACKET)
					{
						Demo_fwrite( (Buffer1Pnt+offset), nBytes + (sizeof(DWORD)*2) + sizeof(LONGLONG), 1, DemoFp );
					}
				}
				
				offset += sizeof(DWORD) + (sizeof(DPID)*1) + nBytes + sizeof(LONGLONG);

				if ( from_dcoID == DPID_SYSMSG )    EvalSysMessage( nBytes , BufferPnt );
				else EvaluateMessage( nBytes , BufferPnt );

				Buffer1Count-=1;
			}
			Buffer1Offset = 0;
			Buffer1InUse = FALSE;
		}
	}else{

		// The old non Thread method......
		if ( glpDP )
		{
			// read all messages in queue
			while(1)
			{
				nBytes = MAXBIGPACKETBUFFERSIZE;
				status = glpDP->lpVtbl->Receive( glpDP,
							&from_dcoID,
							&dcoReceiveID,
							DPRECEIVE_ALL,
							&ReceiveCommBuff[0],

							&nBytes);
				if( status == DP_OK )
				{
					QueryPerformanceCounter((LARGE_INTEGER *) &TempTime);
					if( RecordDemo && ( MyGameStatus == STATUS_Normal ) && ( from_dcoID != DPID_SYSMSG ) )
					{
						TempTime -= GameStartedTime;

						if( ReceiveCommBuff[0] != MSG_GUARANTEEDMSG && ReceiveCommBuff[0] != MSG_ACKMSG && ReceiveCommBuff[0] != MSG_BIGPACKET )
						{
							Demo_fwrite( &TempTime, sizeof(LONGLONG), 1, DemoFp );
							Demo_fwrite( &nBytes, sizeof(nBytes), 1, DemoFp );
							Demo_fwrite( &from_dcoID, sizeof(from_dcoID), 1, DemoFp );
							Demo_fwrite( &ReceiveCommBuff[0], nBytes , 1, DemoFp );
						}
					}
					RecPacketSize = nBytes;
					if ( RecPacketSize > MaxRecPacketSize )
						MaxRecPacketSize = RecPacketSize;

					BytesPerSecRec += nBytes;

					if ( from_dcoID == DPID_SYSMSG )    EvalSysMessage( nBytes , &ReceiveCommBuff[0] );
					else EvaluateMessage( nBytes , &ReceiveCommBuff[0]);
				}else{
					// Error condition of some kind - we just stop
					// checking for now
					return;
				}
			}
		}

	}

	for( i = 0 ; i < MAX_PLAYERS ; i++ )
	{
		if( OldGameStatus[i] == STATUS_Joining && GameStatus[i] != STATUS_Joining )
		{
			NextworkOldKills = -1;
			NextworkOldDeaths = -1;
			NextworkOldBikeNum = -1;
		}
	}



#endif
}


void AllocatePseudoHost( void )
{
	int i;
	
	for ( i = 1; i < MAX_PLAYERS; i++ )	// server is always player 0
	{
		if ( GameStatus[ i ] == STATUS_Normal )
		{
			SendGameMessage(MSG_TOCLIENT, Ships[ i ].dcoID, 0, TOCLIENTMSG_YouArePseudoHost, 0);
			break;
		}
	}
}

/*
 * EvalSysMessage
 *
 * Evaluates system messages and performs appropriate actions
 */
void EvalSysMessage( DWORD len , BYTE * MsgPnt)
{
	int i;
	LPDPMSG_GENERIC lpMsg = (LPDPMSG_GENERIC) MsgPnt;
	LPDPMSG_DESTROYPLAYERORGROUP lpDestroyMsg;
	LPDPMSG_CREATEPLAYERORGROUP lpAddMsg;
//	LPDPMSG_SETSESSIONDESC lpSetSessionMsg;
    
	if (!lpMsg)
		return;
    switch( lpMsg->dwType)
    {
	case DPSYS_CREATEPLAYERORGROUP:
		DebugPrintf("DPSYS_CREATEPLAYERORGROUP recieved\n");
		if( MyGameStatus == STATUS_Normal && !TeamGame)
		{
			lpAddMsg = (LPDPMSG_CREATEPLAYERORGROUP) lpMsg;
			sprintf( (char*) &tempstr[0] ,"%s %s", lpAddMsg->dpnName.lpszShortNameA , IS_JOINING_THE_GAME );
   			AddMessageToQue( (char*)&tempstr[0] );
		}
		for( i = 0 ; i < MAX_PLAYERS ; i++ )
		{
			if( ( i != WhoIAm ) && ( GameStatus[i] != MyGameStatus ) )
			{
				Names[i][0] = 0;
			}
		}

//			if( IsHost)
//			{
//			        SendGameMessage(MSG_INIT, lpAddMsg->dpId, 0, 0, 0);
//			}
		break;
	case DPSYS_SESSIONLOST:
		DebugPrintf("DPSYS_SESSIONLOST recieved\n");
		// The Whole Game has been Lost....Oops...
		AddMessageToQue( THE_SESSION_HAS_BEEN_LOST_PLEASE_QUIT );
		AddMessageToQue( THE_SESSION_HAS_BEEN_LOST_PLEASE_QUIT );
		AddMessageToQue( THE_SESSION_HAS_BEEN_LOST_PLEASE_QUIT );
		break;

    case DPSYS_HOST:
		DebugPrintf("DPSYS_HOST recieved\n");
		if( IsServerGame && !IsServer )
		{
			// The Whole Game has been Lost....Oops...
			AddMessageToQue( THE_SESSION_HAS_BEEN_LOST_PLEASE_QUIT );
			AddMessageToQue( THE_SESSION_HAS_BEEN_LOST_PLEASE_QUIT );
			AddMessageToQue( THE_SESSION_HAS_BEEN_LOST_PLEASE_QUIT );
			return;
		}

		/*
		if (MyGameStatus == STATUS_StartingMultiplayer)
		{
			if ( TeamGame )
				PrintErrorMessage ( YOU_HAVE_BECOME_THE_HOST , 0, NULL, ERROR_DONTUSE_MENUFUNCS );
			else
				PrintErrorMessage ( YOU_HAVE_BECOME_THE_HOST , 1, &MENU_NEW_HostWaitingToStart, ERROR_DONTUSE_MENUFUNCS );
			//PrintErrorMessage ( "the host has quit", 3, NULL );
			if ( DPlayGetSessionDesc() != DP_OK)
			{
				Msg("Mydplay.c: EvalSysMessage() unable to get new session description\n");
				exit(1);
			}
			DPlayTest = TRUE;
		}
		else
		{
			AddMessageToQue( YOU_HAVE_BECOME_THE_HOST );
		}
		*/

		switch ( MyGameStatus )
		{
		case STATUS_StartingMultiplayer:
			if ( TeamGame )
				PrintErrorMessage ( YOU_HAVE_BECOME_THE_HOST , 0, NULL, ERROR_DONTUSE_MENUFUNCS | ERROR_OVERIDE_LOBBY_QUIT );
			else
				PrintErrorMessage ( YOU_HAVE_BECOME_THE_HOST , 1, &MENU_NEW_HostWaitingToStart, ERROR_DONTUSE_MENUFUNCS | ERROR_OVERIDE_LOBBY_QUIT );
			//PrintErrorMessage ( "the host has quit", 3, NULL );
			if ( DPlayGetSessionDesc() != DP_OK)
			{
				Msg("Mydplay.c: EvalSysMessage() unable to get new session description\n");
				exit(1);
			}
			DPlayTest = TRUE;
			break;
		case STATUS_WaitingForLobbyConnect:
			PrintErrorMessage ( YOU_HAVE_BECOME_THE_HOST , 0, &MENU_NEW_CreateLobbyGame, ERROR_DONTUSE_MENUFUNCS | ERROR_OVERIDE_LOBBY_QUIT );
			break;
		default:
			AddMessageToQue( YOU_HAVE_BECOME_THE_HOST );
		}

		IsHost = TRUE;					// I have Become the host

		// if tracker information recieved, I will carry on sending heartbeats
		if( TrackerOveride )	
		{
			GetIPAdd();
			DPStartThread();
		}

		if( !RecordDemoToRam )
			RecordDemo = FALSE;				// But I cant record a demo cos none of the files are open...
		PacketsSlider.value = (int) (60.0F / DPlayUpdateInterval);
		for( i = 0 ; i < MAX_PLAYERS ; i++ )
		{
			if( ( i != WhoIAm ) && ( Ships[i].Object.Flags & SHIP_IsHost ) )
			{
				Ships[i].enable = 0;
				GameStatus[i] = STATUS_Left;
				FreeAllPlayersAcknowledgeMessageQue( (BYTE)i );
			}
		}

		// ensure that IP addresses are obtained in next ping request ( applies to TCP only )
		memset(&PlayerIP, 0, sizeof(PlayerIP));

		break;
	case DPSYS_DESTROYPLAYERORGROUP:
		DebugPrintf("DPSYS_DESTROYPLAYERORGROUP recieved\n");
		lpDestroyMsg = ( LPDPMSG_DESTROYPLAYERORGROUP ) lpMsg;
		if( lpDestroyMsg->dwPlayerType == DPPLAYERTYPE_PLAYER )
		{
#ifdef DIRECTPLAY_KICK_PLAYER
			if( lpDestroyMsg->dpId == dcoID )
			{
				SetTitleNotify( KICKED_OUT/*"you have been kicked out by the server"*/ );
				IMustQuit = TRUE;
			}
#endif
			// if server game & server has quit...
			if ( IsServerGame && ( lpDestroyMsg->dpId == HostDPID ) )
			{
				switch( MyGameStatus )
				{
				case STATUS_Title:
				case STATUS_StartingMultiplayer:
				case STATUS_PseudoHostWaitingForAck:
					MenuChangeEx( &MENU_NEW_ServerHasQuit );
					break;
				default:
					IMustQuit = TRUE;
					break;
				}

				return;
			}
			
			for( i = 0 ; i < MAX_PLAYERS ; i++ )
			{
				if( ( i != WhoIAm ) && (lpDestroyMsg->dpId == Ships[i].dcoID) )
				{
					
					if( MyGameStatus == STATUS_Normal )
					{
						
						if( IsServerGame && IsServer )
						{
							VECTOR	ScatterDir;

							KillOwnersSecBulls( (uint16) i );

							ScatterDir = Ships[ i ].LastMove;
							NormaliseVector( &ScatterDir );
							ScatterWeaponsForShip( (uint16) i, &ScatterDir, MAXPICKUPS ); // Scatter all weapons in direction.
						}

						sprintf( (char*) &tempstr[0] ,"%s %s", &Names[i][0] , HAS_LEFT_THE_GAME );
				   		AddMessageToQue( (char*)&tempstr[0] );
					}

					if( Ships[i].Object.light != (uint16) -1  )
					{
//						KillUsedXLight(Ships[i].Object.light);
						Ships[i].Object.light = (uint16) -1;
					}
//						KillOwnersSecBulls( (uint16) i );
					Ships[i].enable = 0;
					FreeAllPlayersAcknowledgeMessageQue( (BYTE)i );

					if ( GameStatus[ i ] == STATUS_StartingMultiplayer )
					{
						GameStatus[ i ] = STATUS_Null;	// ensure slot is freed up if player has quit from titles
					}else
					{
						if( GameStatus[i] != STATUS_Left )
						{
							GameStatus[i] = STATUS_LeftCrashed;
						}
					}

					InitShipStructure(i , FALSE );
					break;
				}
			}

			if( IsServer )
			{
				if ( PseudoHostDPID == lpDestroyMsg->dpId ) 
				{
					PseudoHostDPID = 0;
					switch( MyGameStatus )
					{
					case STATUS_StartingMultiplayer:
					case STATUS_Title:
						MenuBackSpecific( &MENU_NEW_HostWaitingToStartServer, FALSE );
	
						// reset server state
						DPlayGetSessionDesc();
						if ( glpdpSD )
						{
		 					glpdpSD->dwUser3 &= ~ServerGameStateBits;
							glpdpSD->dwUser3 |=	SERVER_STATE_NeedHost;
							DPlaySetSessionDesc( 0 );
						}else
						{
							Msg("Serious error - unable to get session description for server\n");
						}
						break;
					default:
						AllocatePseudoHost();
					}
				}
			}

		}
		break;
#if 1
	case DPSYS_SETSESSIONDESC:
		DebugPrintf("DPSYS_SETSESSIONDESC recieved\n");
		break;
#endif
	case DPSYS_ADDGROUPTOGROUP:
		DebugPrintf("DPSYS_ADDGROUPTOGROUP recieved\n");
		break;
	case DPSYS_ADDPLAYERTOGROUP:
		DebugPrintf("DPSYS_ADDPLAYERTOGROUP recieved\n");
		break;
	case DPSYS_CHAT:
		DebugPrintf("DPSYS_CHAT recieved\n");
		break;
	case DPSYS_DELETEGROUPFROMGROUP:
		DebugPrintf("DPSYS_DELETEGROUPFROMGROUP recieved\n");
		break;
	case DPSYS_DELETEPLAYERFROMGROUP:
		DebugPrintf("DPSYS_DELETEPLAYERFROMGROUP recieved\n");
		break;
	case DPSYS_SECUREMESSAGE:
		DebugPrintf("DPSYS_SECUREMESSAGE recieved\n");
		break;
	case DPSYS_SETPLAYERORGROUPDATA:
		DebugPrintf("DPSYS_SETPLAYERORGROUPDATA recieved\n");
		break;
	case DPSYS_SETPLAYERORGROUPNAME:
		DebugPrintf("DPSYS_SETPLAYERORGROUPNAME recieved\n");
		break;
	case DPSYS_STARTSESSION:
		DebugPrintf("DPSYS_STARTSESSION recieved\n");
		break;

	default:
		DebugPrintf("unknown DPlay sys message recieved ( %x )\n", *MsgPnt);
		break;
	}
}


//#define SERVER_MASTER_TIMEOUT 300	// 300s == 5 mins

BOOL CheckPlayersActive( void )
{
	uint16 i;

	if ( ServerChoosesGameType )
		return TRUE;
	
	for ( i = 1; i < MAX_PLAYERS; i++ )
	{
		//if ( ( LastPacketTime [ i ] + Freq * SERVER_MASTER_TIMEOUT ) > TempTime )
		if ( ( LastPacketTime [ i ] + Freq * ( ServerTimeoutSlider.value * 60 ) ) > TempTime )
		{
			return TRUE;
		}
	}

	return FALSE;
}


void EvaluateMessage( DWORD len , BYTE * MsgPnt )
{
    LPUPDATEMSG			lpUpdate;
    LPVERYSHORTUPDATEMSG lpVeryShortUpdate;
    LPFUPDATEMSG		lpFUpdate;
    LPVERYSHORTFUPDATEMSG		lpVeryShortFUpdate;
    LPGROUPONLY_VERYSHORTFUPDATEMSG		lpGroupOnly_VeryShortFUpdate;
    LPHEREIAMMSG		lpHereIAm;
    LPINITMSG			lpInit;
    LPSHIPHITMSG		lpShipHit;
    LPSHORTSHIPHITMSG	lpShortShipHit;
    LPSHIPDIEDMSG       lpShipDied;
    LPPRIMBULLPOSDIRMSG lpPrimBullPosDir;
    LPSECBULLPOSDIRMSG  lpSecBullPosDir;
    LPTITANBITSMSG		lpTitanBits;
    LPDROPPICKUPMSG     lpDropPickup;
    LPVERYSHORTDROPPICKUPMSG     lpVeryShortDropPickup;
    LPKILLPICKUPMSG     lpKillPickup;
    LPSERVERKILLPICKUPMSG lpServerKillPickup;
    LPEXPLODESHIPMSG	lpExplodeShip;
    LPEXPSECONDARYMSG	lpExplodeSecondary;
    LPTEAMGOALSMSG		lpTeamGoals;
    LPSHOCKWAVEMSG		lpShockwave;
    LPBGOUPDATEMSG		lpBGOUpdate;
    LPSHORTSTATSMSG		lpShortStats;
    LPSTATUSMSG			lpStatus;
    LPLONGSTATUSMSG		lpLongStatus;
    LPSHORTPICKUPMSG	lpShortPickup;
    LPSHORTREGENSLOTMSG	lpShortRegenSlot;
    LPSHORTTRIGGERMSG	lpShortTrigger;
    LPSHORTTRIGVARMSG	lpShortTrigVar;
    LPSHORTMINEMSG		lpShortMine;
    LPTEXTMSG			lpTextMsg;
	LPNAMEMSG			lpName;
	LPINTERPOLATEMSG	lpInterpolate;
	LPVERYSHORTINTERPOLATEMSG	lpVeryShortInterpolate;
	LPBOMBMSG			lpBomb;
	LPPINGMSG			lpPingMsg;
	LPPLAYERPINGSMSG	lpPlayerPingsMsg;
	LPACKMSG			lpAckMsg;
	LPGUARANTEEDMSG		lpGuaranteedMsg;
	LPKILLSDEATHSBIKENUMMSG	lpKillsDeathsMsg;
	LPYOUQUITMSG			lpYouQuitMsg;
    char				dBuf[256];
	char full_level_name[ MAX_LEVEL_NAME_LENGTH ];
	int					i;
	BYTE				OldMode;
	BYTE				OldStatus;
	int16				Count;
    char				methodstr[256];
	char				teamstr[256];
	int					size;				// special for demo recording
	BYTE				msg;				// special for demo recording
	LONGLONG			TempLongLong;
    LPSETTIMEMSG		lpSetTime;
    LPREQTIMEMSG		lpReqTime;
	uint32	ID;
	BYTE	AckWhoIAm;
	VECTOR	Point;
	VECTOR	Recoil;
	VECTOR	Dir;
	float	Force;
	float * FloatPnt;
	uint32	BigOffset = 2;
	LPSERVERUPDATEMSG ServerUpdateMsg;
	LPGAMEPARAMETERSMSG lpGameParamMsg;
	LPSERVERSAYSSHIPDIEDMSG lpServerSaysShipDiedMsg;
	LPTOSERVERMSG lpToServerMsg;
	LPTOCLIENTMSG lpToClientMsg;
	LPLEVELNAMESMSG	lpLevelNamesMsg;
	LPTRACKERINFOMSG	lpTrackerInfoMsg;
	VECTOR	ScatterDir;
	LPSHIELDHULLMSG	lpShieldHullMsg;
	LPSERVERSCOREDMSG	lpServerScoredMsg;
	VECTOR Int_Point;
	VECTOR Int_Point2;
	VECTOR TempVector;
	uint16	Pickup;
	LONGLONG	TimeFrig;


#ifdef MANUAL_SESSIONDESC_PROPAGATE
	LPSESSIONDESCMSG	lpSessionDescMsg;
#endif

	/*
	if ( *MsgPnt == 0xe0 )
	{
		Msg("tracker msg recieved ( gamestatus = %x)\n", MyGameStatus);
		Msg("test");
	}
	*/
	
	if( *(MsgPnt+1) < MAX_PLAYERS )
	{
		LastPacketTime[*(MsgPnt+1)] = TempTime;

#ifdef DEBUG_ON
		PacketGot[*MsgPnt]++;
		PacketSize[*MsgPnt]+=len;
#endif

	}

	if( *MsgPnt == MSG_SERVERUPDATE )
	{
		ServerUpdateMsg = (LPSERVERUPDATEMSG) MsgPnt;
		for( i = 0 ; i < MAX_PLAYERS ; i++ )
		{
			if( i != WhoIAm )
			{
				if( (ServerUpdateMsg->Players & (1 << i)) && i != 0 )
				{
					Ships[i].enable = TRUE;
				}else{
					Ships[i].enable = FALSE;
					Ships[i].Object.Group = (uint16) ServerUpdateMsg->Group[i];
				}
				GameStatus[i] = ServerUpdateMsg->Status[i];
				if( i == 0 )
					OverallGameStatus = ServerUpdateMsg->Status[i];


			}
		}
		return;
	}
	if( *MsgPnt == MSG_BIGPACKET )
	{
		while( MsgPnt[BigOffset] )
		{
			if( MsgPnt[BigOffset] == MSG_GUARANTEEDMSG )
			{
				lpGuaranteedMsg = (LPGUARANTEEDMSG)(&MsgPnt[BigOffset]);

				FloatPnt = (float*) ( &MsgPnt[ BigOffset + sizeof(GUARANTEEDMSG) + RealPacketSize[lpGuaranteedMsg->StartOfMessage] -1 ] );

				GlobalFramelagAddition = *FloatPnt;

				if( GlobalFramelagAddition < 0.0F || GlobalFramelagAddition > 300.0F  )
				{
					DebugPrintf("Got a messed up GlobalFramelagAddition\n");
					return;
				}

				ID = lpGuaranteedMsg->ID;
				AckWhoIAm = lpGuaranteedMsg->WhoIAm;
				if( AddAcknowledgeMessageQue( AckWhoIAm , ID ) )
				{
					Demo_fwrite( &TempTime, sizeof(LONGLONG), 1, DemoFp );
					len = RealPacketSize[lpGuaranteedMsg->StartOfMessage];
					Demo_fwrite( &len, sizeof(len), 1, DemoFp );
					Demo_fwrite( &from_dcoID, sizeof(from_dcoID), 1, DemoFp );
					Demo_fwrite( &lpGuaranteedMsg->StartOfMessage, len , 1, DemoFp );

					AddGuaranteedToServersGuaranteedQue( lpGuaranteedMsg );
					ItsAGuranteed = TRUE;
					EvaluateMessage( len , &lpGuaranteedMsg->StartOfMessage );
					ItsAGuranteed = FALSE;
				}
				SendGameMessage( MSG_ACKMSG, ID, AckWhoIAm, 0, 0 );
				BigOffset += sizeof(GUARANTEEDMSG) + sizeof(float) + RealPacketSize[lpGuaranteedMsg->StartOfMessage] -1;
			}else{
				FloatPnt = (float*) ( &MsgPnt[ BigOffset + RealPacketSize[MsgPnt[BigOffset] ] ]  );

				GlobalFramelagAddition = *FloatPnt;

				if( GlobalFramelagAddition < 0.0F || GlobalFramelagAddition > 300.0F )
				{
					DebugPrintf("Got a messed up GlobalFramelagAddition\n");
					return;
				}
				Demo_fwrite( &TempTime, sizeof(LONGLONG), 1, DemoFp );
				len = RealPacketSize[MsgPnt[BigOffset]];
				Demo_fwrite( &len, sizeof(len), 1, DemoFp );
				Demo_fwrite( &from_dcoID, sizeof(from_dcoID), 1, DemoFp );
				Demo_fwrite( &MsgPnt[BigOffset], len , 1, DemoFp );
				EvaluateMessage( len , &MsgPnt[BigOffset] );
				BigOffset += RealPacketSize[ MsgPnt[BigOffset] ] + sizeof(float);
			}
			GlobalFramelagAddition = 0.0F;
		}
		return;
	}

	if( *MsgPnt == MSG_GUARANTEEDMSG )
	{
		lpGuaranteedMsg = (LPGUARANTEEDMSG)MsgPnt;
		if( lpGuaranteedMsg->Ack & ( 1 << WhoIAm ) )
		{
			ID = lpGuaranteedMsg->ID;
			AckWhoIAm = lpGuaranteedMsg->WhoIAm;

			if( AddAcknowledgeMessageQue( AckWhoIAm , ID ) )
			{
				if( RecordDemo && ( MyGameStatus == STATUS_Normal ) )
				{
					Demo_fwrite( &TempTime, sizeof(LONGLONG), 1, DemoFp );
					len = RealPacketSize[lpGuaranteedMsg->StartOfMessage];
					Demo_fwrite( &len, sizeof(len), 1, DemoFp );
					Demo_fwrite( &from_dcoID, sizeof(from_dcoID), 1, DemoFp );
					Demo_fwrite( &lpGuaranteedMsg->StartOfMessage, len , 1, DemoFp );
				}

				AddGuaranteedToServersGuaranteedQue( lpGuaranteedMsg );

				ItsAGuranteed = TRUE;
				EvaluateMessage( len , &lpGuaranteedMsg->StartOfMessage );
				ItsAGuranteed = FALSE;

			}
			SendGameMessage( MSG_ACKMSG, ID, AckWhoIAm, 0, 0 );
		}
		return;
	}
	

	if( !ItsAGuranteed && *MsgPnt != MSG_HEREIAM )
		AddMessageToSeverQue( MsgPnt );
	
	if( MyGameStatus == STATUS_GetPlayerNum )
	{
 		if ( ( *MsgPnt != MSG_INIT ) && ( *MsgPnt != MSG_TRACKERINFO ) )
			return;
	}

	if  ( ( ( ( MyGameStatus >= STATUS_InitView_0 ) && ( MyGameStatus <= STATUS_InitView_9 ) ) ||
		( MyGameStatus == STATUS_Joining ) ||
		( MyGameStatus == STATUS_PreStartingMultiplayerSynch ) ||
		( MyGameStatus == STATUS_WaitingToStartMultiPlayerClient ) ||
		( MyGameStatus == STATUS_WaitingToStartTeamGame ) ) )
	{
		switch (*MsgPnt)
		{
		    case MSG_SECBULLPOSDIR:
				lpSecBullPosDir = (LPSECBULLPOSDIRMSG)MsgPnt;

				if( SecondaryWeaponAttribs[ lpSecBullPosDir->SecBullPosDir.Weapon ].SecType == SEC_MINE )
				{
					if( NumMissedMines != MAXMISSEDMINES )
					{
						DebugPrintf( "MissedInitMine() %d\n", NumMissedMines );

						MissedInitMines[ NumMissedInitMines ].OwnerType	= lpSecBullPosDir->SecBullPosDir.OwnerType;
						MissedInitMines[ NumMissedInitMines ].Owner		= lpSecBullPosDir->SecBullPosDir.Owner;
						MissedInitMines[ NumMissedInitMines ].BulletID	= lpSecBullPosDir->SecBullPosDir.BulletID;
						MissedInitMines[ NumMissedInitMines ].Group		= lpSecBullPosDir->SecBullPosDir.Group;
						MissedInitMines[ NumMissedInitMines ].Pos		= lpSecBullPosDir->SecBullPosDir.Pos;
						MissedInitMines[ NumMissedInitMines ].Offset	= lpSecBullPosDir->SecBullPosDir.Offset;
						MissedInitMines[ NumMissedInitMines ].Dir		= lpSecBullPosDir->SecBullPosDir.Dir;
						MissedInitMines[ NumMissedInitMines ].UpVector	= lpSecBullPosDir->SecBullPosDir.UpVector;
						MissedInitMines[ NumMissedInitMines ].DropDir	= lpSecBullPosDir->SecBullPosDir.DropDir;
						MissedInitMines[ NumMissedInitMines ].Weapon	= lpSecBullPosDir->SecBullPosDir.Weapon;
						MissedMines[ NumMissedMines ].Type = MM_TYPE_INIT;
						MissedMines[ NumMissedMines ].Struct = &MissedInitMines[ NumMissedInitMines ];
						NumMissedInitMines++;
						NumMissedMines++;
					}
					else
					{
			   			DebugPrintf( "Overflowed mine que ( INIT )\n" );
					}
				}
				return;
				break;

			case MSG_DROPPICKUP:
				lpDropPickup = (LPDROPPICKUPMSG)MsgPnt;

				if( NumMissedPickups != MAXMISSEDPICKUPS )
		 		{
		 			MissedInitPickups[ NumMissedInitPickups ].Pos = lpDropPickup->PickupInfo.Pos;
		 			MissedInitPickups[ NumMissedInitPickups ].Group = lpDropPickup->PickupInfo.Group;
		 			MissedInitPickups[ NumMissedInitPickups ].Dir = lpDropPickup->PickupInfo.Dir;
		 			MissedInitPickups[ NumMissedInitPickups ].Speed = lpDropPickup->PickupInfo.Speed;
		 			MissedInitPickups[ NumMissedInitPickups ].Type = lpDropPickup->PickupInfo.Type;
		 			MissedInitPickups[ NumMissedInitPickups ].Owner = lpDropPickup->WhoIAm;
		 			MissedInitPickups[ NumMissedInitPickups ].ID = lpDropPickup->PickupInfo.IDCount;
		 			MissedInitPickups[ NumMissedInitPickups ].RegenSlot = lpDropPickup->PickupInfo.RegenSlot;
		 			MissedInitPickups[ NumMissedInitPickups ].Sparkle = lpDropPickup->PickupInfo.Sparkle;
		 			MissedInitPickups[ NumMissedInitPickups ].LifeCount = lpDropPickup->PickupInfo.LifeCount;
		 			MissedInitPickups[ NumMissedInitPickups ].TriggerMod = lpDropPickup->PickupInfo.TriggerMod;
		 			MissedPickups[ NumMissedPickups ].Type = MPU_TYPE_INIT;
		 			MissedPickups[ NumMissedPickups ].Struct = &MissedInitPickups[ NumMissedInitPickups ];
#if DEBUG_PICKUPS
	   	 	   		DebugPrintf( "Added Init '%s' to Que\n", Messages[ lpDropPickup->PickupInfo.Type ] );
#endif
		 	   		NumMissedInitPickups++;
		 	   		NumMissedPickups++;

		 	   	}
		 	   	else
		 	   	{
#if DEBUG_PICKUPS
   	 				DebugPrintf( "Overflowed pickup que ( INIT )\n" );
#endif
	 			}
				return;
				break;

			case MSG_VERYSHORTDROPPICKUP:
				lpVeryShortDropPickup = (LPVERYSHORTDROPPICKUPMSG)MsgPnt;

				if( NumMissedPickups != MAXMISSEDPICKUPS )
		 		{
		 			MissedInitPickups[ NumMissedInitPickups ].Pos.x = (float)lpVeryShortDropPickup->PickupInfo.Pos.x;
		 			MissedInitPickups[ NumMissedInitPickups ].Pos.y = (float)lpVeryShortDropPickup->PickupInfo.Pos.y;
		 			MissedInitPickups[ NumMissedInitPickups ].Pos.z = (float)lpVeryShortDropPickup->PickupInfo.Pos.z;
		 			MissedInitPickups[ NumMissedInitPickups ].Dir.x = lpVeryShortDropPickup->PickupInfo.Dir.x * ONEOVER32767;
		 			MissedInitPickups[ NumMissedInitPickups ].Dir.y = lpVeryShortDropPickup->PickupInfo.Dir.y * ONEOVER32767;
		 			MissedInitPickups[ NumMissedInitPickups ].Dir.z = lpVeryShortDropPickup->PickupInfo.Dir.z * ONEOVER32767;
		 			MissedInitPickups[ NumMissedInitPickups ].Group = lpVeryShortDropPickup->PickupInfo.Group;
		 			MissedInitPickups[ NumMissedInitPickups ].Speed = lpVeryShortDropPickup->PickupInfo.Speed;
		 			MissedInitPickups[ NumMissedInitPickups ].Type = lpVeryShortDropPickup->PickupInfo.Type;
		 			MissedInitPickups[ NumMissedInitPickups ].Owner = lpVeryShortDropPickup->WhoIAm;
		 			MissedInitPickups[ NumMissedInitPickups ].ID = lpVeryShortDropPickup->PickupInfo.IDCount;
		 			MissedInitPickups[ NumMissedInitPickups ].RegenSlot = lpVeryShortDropPickup->PickupInfo.RegenSlot;
		 			MissedInitPickups[ NumMissedInitPickups ].Sparkle = lpVeryShortDropPickup->PickupInfo.Sparkle;
		 			MissedInitPickups[ NumMissedInitPickups ].LifeCount = lpVeryShortDropPickup->PickupInfo.LifeCount;
		 			MissedInitPickups[ NumMissedInitPickups ].TriggerMod = lpVeryShortDropPickup->PickupInfo.TriggerMod;
		 			MissedPickups[ NumMissedPickups ].Type = MPU_TYPE_INIT;
		 			MissedPickups[ NumMissedPickups ].Struct = &MissedInitPickups[ NumMissedInitPickups ];
#if DEBUG_PICKUPS
	   	 	   		DebugPrintf( "Added Init '%s' to Que\n", Messages[ lpVeryShortDropPickup->PickupInfo.Type ] );
#endif
		 	   		NumMissedInitPickups++;
		 	   		NumMissedPickups++;

		 	   	}
		 	   	else
		 	   	{
#if DEBUG_PICKUPS
   	 				DebugPrintf( "Overflowed pickup que ( INIT )\n" );
#endif
	 			}
				return;
				break;



			case MSG_EXPSECONDARY:
				lpExplodeSecondary = (LPEXPSECONDARYMSG)MsgPnt;

				if( NumMissedMines != MAXMISSEDMINES )
   				{
   					MissedKillMines[ NumMissedKillMines ].OwnerType		= lpExplodeSecondary->ExplodeSecondaryInfo.OwnerType;
   					MissedKillMines[ NumMissedKillMines ].Owner			= lpExplodeSecondary->ExplodeSecondaryInfo.Owner;
   					MissedKillMines[ NumMissedKillMines ].ID			= lpExplodeSecondary->ExplodeSecondaryInfo.IDCount;
   					MissedKillMines[ NumMissedKillMines ].ShockwaveSize	= lpExplodeSecondary->ExplodeSecondaryInfo.ShockwaveSize;
   					MissedMines[ NumMissedMines ].Type = MM_TYPE_KILL;
   					MissedMines[ NumMissedMines ].Struct = &MissedKillMines[ NumMissedKillMines ];
   					NumMissedKillMines++;
   					NumMissedMines++;
   				}
   				else
   				{
   					DebugPrintf( "Overflowed mine que ( KILL )\n" );
   				}
   				return;
				break;

			case MSG_KILLPICKUP:
   				lpKillPickup = (LPKILLPICKUPMSG)MsgPnt;
   				if( NumMissedPickups != MAXMISSEDPICKUPS )
   				{
   					MissedKillPickups[ NumMissedKillPickups ].Owner = lpKillPickup->KillPickupInfo.Owner;
   					MissedKillPickups[ NumMissedKillPickups ].ID = lpKillPickup->KillPickupInfo.IDCount;
   					MissedKillPickups[ NumMissedKillPickups ].Style = lpKillPickup->KillPickupInfo.Style;
   					MissedPickups[ NumMissedPickups ].Type = MPU_TYPE_KILL;
   					MissedPickups[ NumMissedPickups ].Struct = &MissedKillPickups[ NumMissedKillPickups ];
#if DEBUG_PICKUPS
					DebugPrintf( "Added Kill pickup of Owner '%s', ID %d, to que\n",
								&Names[ lpKillPickup->KillPickupInfo.Owner ][ 0 ],
								lpKillPickup->KillPickupInfo.IDCount );
#endif
   					NumMissedKillPickups++;
   					NumMissedPickups++;
   				}
   				else
   				{
#if DEBUG_PICKUPS
   					DebugPrintf( "Overflowed pickup que ( KILL )\n" );
#endif
				}


				return;
				break;

			case MSG_SERVERKILLPICKUP:
   				lpServerKillPickup = (LPSERVERKILLPICKUPMSG)MsgPnt;
   				if( NumMissedPickups != MAXMISSEDPICKUPS )
   				{
   					MissedServerKillPickups[ NumMissedKillPickups ].NewOwner = lpServerKillPickup->ServerKillPickupInfo.NewOwner;
   					MissedServerKillPickups[ NumMissedKillPickups ].Owner = lpServerKillPickup->ServerKillPickupInfo.Owner;
   					MissedServerKillPickups[ NumMissedKillPickups ].ID = lpServerKillPickup->ServerKillPickupInfo.IDCount;
   					MissedServerKillPickups[ NumMissedKillPickups ].Style = lpServerKillPickup->ServerKillPickupInfo.Style;
   					MissedPickups[ NumMissedPickups ].Type = MPU_TYPE_SERVERKILL;
   					MissedPickups[ NumMissedPickups ].Struct = &MissedServerKillPickups[ NumMissedKillPickups ];
#if DEBUG_PICKUPS
					DebugPrintf( "Added Kill pickup of Owner '%s', ID %d, to que\n",
								&Names[ lpServerKillPickup->ServerKillPickupInfo.Owner ][ 0 ],
								lpServerKillPickup->ServerKillPickupInfo.IDCount );
#endif
   					NumMissedKillPickups++;
   					NumMissedPickups++;
   				}
   				else
   				{
#if DEBUG_PICKUPS
   					DebugPrintf( "Overflowed pickup que ( KILL )\n" );
#endif
				}
				return;
				break;

			case MSG_SHORTREGENSLOT:
			case MSG_SHORTTRIGGER:
			case MSG_SHORTTRIGVAR:
			case MSG_SHORTMINE:
			case MSG_SHORTPICKUP:
			case MSG_YOUQUIT:
			case MSG_NAME:
			case MSG_ACKMSG:
			case MSG_SENDKILLSDEATHSBIKENUM:
			case MSG_KILLSDEATHSBIKENUM:
			case MSG_STATUS:
			case MSG_SERVERUPDATE:
			case MSG_LONGSTATUS:
			case MSG_TRACKERINFO:
			case MSG_TEAMGOALS:
				break;

			default:
				return;
		}
	}else{
		// Some messages should be ignored when im not in normal multiplayer mode
		if( MyGameStatus != STATUS_Normal && !( MyGameStatus == STATUS_PlayingDemo || MyGameStatus == STATUS_AttractMode || MyGameStatus == STATUS_SplashScreen) )
		{
			switch (*MsgPnt)
			{
		    case MSG_SECBULLPOSDIR:
			case MSG_EXPSECONDARY:
			case MSG_DROPPICKUP:
			case MSG_VERYSHORTDROPPICKUP:
			case MSG_KILLPICKUP:
			case MSG_SERVERKILLPICKUP:
			case MSG_VERYSHORTFUPDATE:
			case MSG_GROUPONLY_VERYSHORTFUPDATE:
			case MSG_FUPDATE:
			case MSG_TEAMGOALS:
				return;

			default:
				break;
			}
		}
	}


	if (MyGameStatus == STATUS_StartingMultiplayer)
	{
		switch (*MsgPnt)
		{
		case MSG_VERYSHORTUPDATE:
		case MSG_UPDATE:
		case MSG_INIT:
		case MSG_SERVERUPDATE:
		case MSG_STATUS:
		case MSG_LONGSTATUS:
		case MSG_HEREIAM:
		case MSG_TEXTMSG:
		case MSG_YOUQUIT:
		case MSG_NAME:
		case MSG_SENDKILLSDEATHSBIKENUM:
 		case MSG_KILLSDEATHSBIKENUM:
		case MSG_GAMEPARAMETERS:
#ifdef MANUAL_SESSIONDESC_PROPAGATE
		case MSG_SESSIONDESC:
#endif
		case MSG_TOSERVER:
		case MSG_TOCLIENT:
		case MSG_LEVELNAMES:
		case MSG_BIGPACKET:
		case MSG_ACKMSG:
		case MSG_TRACKERINFO:
			break;
		default:
			return;
		}
	}
    switch( *MsgPnt )
    {
	case MSG_SERVERSAYSSHIPDIED:
		lpServerSaysShipDiedMsg	= (LPSERVERSAYSSHIPDIEDMSG) MsgPnt;

		if( lpServerSaysShipDiedMsg->WhoWasKilled == WhoIAm && lpServerSaysShipDiedMsg->Deaths == Ships[WhoIAm].Deaths && Ships[WhoIAm].Object.Mode == NORMAL_MODE )
		{
			// I Must Die..
			Ships[WhoIAm].Damage = 512.0F;
   			DoDamage( OVERRIDE_INVUL );
			// if I died...
   			Ships[WhoIAm].ShipThatLastKilledMe = lpServerSaysShipDiedMsg->WhoKilledThem;
   			Ships[WhoIAm].Object.Mode = DEATH_MODE;
   			Ships[WhoIAm].Timer = 0.0F;
   			// make a note of who killed who...
			Stats[Ships[WhoIAm].ShipThatLastKilledMe][WhoIAm]++;
   			// print up who killed me

			GetDeathString( lpServerSaysShipDiedMsg->WeaponType, lpServerSaysShipDiedMsg->Weapon, &methodstr[0] );

			if (TeamGame && ( TeamNumber[Ships[WhoIAm].ShipThatLastKilledMe] == TeamNumber[WhoIAm]))
				strcpy(&teamstr[0], FROM_YOUR_OWN_TEAM );
			else
				strcpy(&teamstr[0], "");

   			sprintf( (char*)&tempstr[0] ,"%s %s %s %s", &Names[Ships[WhoIAm].ShipThatLastKilledMe][0], &methodstr[0], YOU ,&teamstr );
   			AddMessageToQue( (char*)&tempstr[0] );
			ShipDiedSend( lpServerSaysShipDiedMsg->WeaponType, lpServerSaysShipDiedMsg->Weapon );
		}
		return;
	case MSG_SENDKILLSDEATHSBIKENUM:
		NextworkOldKills = -1;
		NextworkOldDeaths = -1;
		NextworkOldBikeNum = -1;
		if( IsServerGame )
			SendGameMessage(MSG_NAME, 0, 0, 0, 0);
		return;
	case MSG_YOUQUIT:
		// I have been asked by the host to quit......
		lpYouQuitMsg = (LPYOUQUITMSG)MsgPnt;
		if( lpYouQuitMsg->You == WhoIAm )
			IMustQuit = TRUE;

		SetTitleNotify( IsServerGame ? KICKED_SERVER : KICKED_HOST );

		return;
    case MSG_VERYSHORTFUPDATE:

		lpVeryShortFUpdate = (LPVERYSHORTFUPDATEMSG)MsgPnt;
		if( lpVeryShortFUpdate->WhoIAm != WhoIAm )
		{
			OldMode = Ships[lpVeryShortFUpdate->WhoIAm].Object.Mode;

			Ships[lpVeryShortFUpdate->WhoIAm].PacketDelay = PacketDelay;
			CheckCharging( lpVeryShortFUpdate->WhoIAm, Ships[ lpVeryShortFUpdate->WhoIAm ].Object.Flags, lpVeryShortFUpdate->ShortGlobalShip.Flags );

			if( !( Ships[lpVeryShortFUpdate->WhoIAm].Object.Flags & SHIP_Multiple ) && ( lpVeryShortFUpdate->ShortGlobalShip.Flags & SHIP_Multiple ) )
			{
				for( Count = 0; Count < MAXMULTIPLES; Count++ ) Ships[ lpVeryShortFUpdate->WhoIAm ].OrbModels[ Count ] = (uint16) -1;
				Ships[lpVeryShortFUpdate->WhoIAm].NumMultiples = (BYTE)((lpVeryShortFUpdate->ShortGlobalShip.Flags >> SHIP_NumMultiples_Bit1 ) & 15);
				CreateOrbitPulsar( lpVeryShortFUpdate->WhoIAm );
			}
			else
			{
				if( ( Ships[ lpVeryShortFUpdate->WhoIAm ].Object.Flags & SHIP_Multiple ) &&
					( ((BYTE)((lpVeryShortFUpdate->ShortGlobalShip.Flags >> SHIP_NumMultiples_Bit1 ) & 15)) != Ships[lpVeryShortFUpdate->WhoIAm].NumMultiples ) )
				{
					Ships[lpVeryShortFUpdate->WhoIAm].NumMultiples = (BYTE)((lpVeryShortFUpdate->ShortGlobalShip.Flags >> SHIP_NumMultiples_Bit1 ) & 15);
					CreateOrbitPulsar( lpVeryShortFUpdate->WhoIAm );
				}
			}
			UnPackShipFlags( lpVeryShortFUpdate->WhoIAm , lpVeryShortFUpdate->ShortGlobalShip.Flags );

			Ships[lpVeryShortFUpdate->WhoIAm].Object.Pos.x	= (float) lpVeryShortFUpdate->ShortGlobalShip.Pos.x;
			Ships[lpVeryShortFUpdate->WhoIAm].Object.Pos.y	= (float) lpVeryShortFUpdate->ShortGlobalShip.Pos.y;
			Ships[lpVeryShortFUpdate->WhoIAm].Object.Pos.z	= (float) lpVeryShortFUpdate->ShortGlobalShip.Pos.z;
			Ships[lpVeryShortFUpdate->WhoIAm].Move_Off.x	= (lpVeryShortFUpdate->ShortGlobalShip.Move_Off.x * ONEOVER32767) * (lpVeryShortFUpdate->ShortGlobalShip.Move_Off_Scalar * ONEOVER256 );
			Ships[lpVeryShortFUpdate->WhoIAm].Move_Off.y	= (lpVeryShortFUpdate->ShortGlobalShip.Move_Off.y * ONEOVER32767) * (lpVeryShortFUpdate->ShortGlobalShip.Move_Off_Scalar * ONEOVER256 );
			Ships[lpVeryShortFUpdate->WhoIAm].Move_Off.z	= (lpVeryShortFUpdate->ShortGlobalShip.Move_Off.z * ONEOVER32767) * (lpVeryShortFUpdate->ShortGlobalShip.Move_Off_Scalar * ONEOVER256 ); 
			Ships[lpVeryShortFUpdate->WhoIAm].Object.Group= (int16) lpVeryShortFUpdate->ShortGlobalShip.GroupImIn;
			Ships[lpVeryShortFUpdate->WhoIAm].Object.Quat.w	= (float)(lpVeryShortFUpdate->ShortGlobalShip.Quat.w * ONEOVER32767 );
			Ships[lpVeryShortFUpdate->WhoIAm].Object.Quat.x	= (float)(lpVeryShortFUpdate->ShortGlobalShip.Quat.x * ONEOVER32767 );
			Ships[lpVeryShortFUpdate->WhoIAm].Object.Quat.y	= (float)(lpVeryShortFUpdate->ShortGlobalShip.Quat.y * ONEOVER32767 );
			Ships[lpVeryShortFUpdate->WhoIAm].Object.Quat.z	= (float)(lpVeryShortFUpdate->ShortGlobalShip.Quat.z * ONEOVER32767 );
			Ships[lpVeryShortFUpdate->WhoIAm].LastAngle.x	= (float)(lpVeryShortFUpdate->ShortGlobalShip.Angle.x * SHORTANGLEMODIFIERUNPACK );
			Ships[lpVeryShortFUpdate->WhoIAm].LastAngle.y	= (float)(lpVeryShortFUpdate->ShortGlobalShip.Angle.y * SHORTANGLEMODIFIERUNPACK );
			Ships[lpVeryShortFUpdate->WhoIAm].LastAngle.z	= (float)(lpVeryShortFUpdate->ShortGlobalShip.Angle.z * SHORTANGLEMODIFIERUNPACK );
			Ships[lpVeryShortFUpdate->WhoIAm].Object.Bank	= (float) (lpVeryShortFUpdate->ShortGlobalShip.Bank / SHORTBANKMODIFIER);


			Ships[lpVeryShortFUpdate->WhoIAm].Primary	= lpVeryShortFUpdate->ShortGlobalShip.Primary;
			Ships[lpVeryShortFUpdate->WhoIAm].Secondary	= lpVeryShortFUpdate->ShortGlobalShip.Secondary;
			Ships[lpVeryShortFUpdate->WhoIAm].PrimPowerLevel = (float) lpVeryShortFUpdate->ShortGlobalShip.PrimPowerLevel;

			Ships[lpVeryShortFUpdate->WhoIAm].JustRecievedPacket = TRUE;


			Ships[lpVeryShortFUpdate->WhoIAm].Object.Noise = 1.0F;
			

			// Need This for missiles to work....
			SetShipBankAndMat( &Ships[lpVeryShortFUpdate->WhoIAm].Object );
			
			if( ( Ships[ lpVeryShortFUpdate->WhoIAm ].Object.Flags & SHIP_PrimFire ) || ( Ships[ lpVeryShortFUpdate->WhoIAm ].Object.Flags & SHIP_MulFire ) )
			{
				FirePrimaryWeapons( lpVeryShortFUpdate->WhoIAm );					// Fire Primary Weapons	
			}
			if( ( Ships[ lpVeryShortFUpdate->WhoIAm ].Object.Flags & SHIP_SecFire ) )
			{
				FireSecondaryWeapons( lpVeryShortFUpdate->WhoIAm );					// Fire Secondary Weapons
			}

			Ships[ lpVeryShortFUpdate->WhoIAm ].Primary = ConvPrimToNormWeapon( Ships[ lpVeryShortFUpdate->WhoIAm ].Primary );
			Ships[ lpVeryShortFUpdate->WhoIAm ].Secondary = ConvSecToNormWeapon( Ships[ lpVeryShortFUpdate->WhoIAm ].Secondary );

/* Added by DC 30/6/98 */
			if( ( OldMode == DEATH_MODE ) && ( Ships[lpVeryShortFUpdate->WhoIAm].Object.Mode == LIMBO_MODE ) ||
				( OldMode == NORMAL_MODE ) && ( Ships[lpVeryShortFUpdate->WhoIAm].Object.Mode == LIMBO_MODE ) )
			{
				if( IsServerGame && IsServer )
				{
					VECTOR	ScatterDir;

					ScatterDir = Ships[ lpVeryShortFUpdate->WhoIAm ].LastMove;
					NormaliseVector( &ScatterDir );
					ScatterWeaponsForShip( lpVeryShortFUpdate->WhoIAm, &ScatterDir, MAXSCATTERED );	// Scatter weapons in all directions.
				}

				if( GoreGuts ) ThrowOutRider( lpVeryShortFUpdate->WhoIAm );
				PlayPannedSfx( SFX_BikeExplode, Ships[ lpVeryShortFUpdate->WhoIAm ].Object.Group , &Ships[lpVeryShortFUpdate->WhoIAm].Object.Pos, 0.0F );
				StopTaunt();
			}
/* ------------------- */

			DemoShipInit[ lpVeryShortFUpdate->WhoIAm ] = TRUE;
			if( IsServer )
			{
				Ships[lpVeryShortFUpdate->WhoIAm].RealPos = Ships[lpVeryShortFUpdate->WhoIAm].Object.Pos;
				Ships[lpVeryShortFUpdate->WhoIAm].RealGroup = Ships[lpVeryShortFUpdate->WhoIAm].Object.Group;
			}

			return;
		}else{
			wsprintf(dBuf, "someone else is in your slot..%d\n", lpVeryShortFUpdate->WhoIAm);
			OutputDebugString( dBuf );
			return;
		}

    case MSG_GROUPONLY_VERYSHORTFUPDATE:

		lpGroupOnly_VeryShortFUpdate = (LPGROUPONLY_VERYSHORTFUPDATEMSG)MsgPnt;
		if( lpGroupOnly_VeryShortFUpdate->WhoIAm != WhoIAm )
		{
			OldMode = Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Object.Mode;

			CheckCharging( lpGroupOnly_VeryShortFUpdate->WhoIAm, Ships[ lpGroupOnly_VeryShortFUpdate->WhoIAm ].Object.Flags, lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Flags );

			if( !( Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Object.Flags & SHIP_Multiple ) && ( lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Flags & SHIP_Multiple ) )
			{
				for( Count = 0; Count < MAXMULTIPLES; Count++ ) Ships[ lpGroupOnly_VeryShortFUpdate->WhoIAm ].OrbModels[ Count ] = (uint16) -1;
				Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].NumMultiples = (BYTE)((lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Flags >> SHIP_NumMultiples_Bit1 ) & 15);
				CreateOrbitPulsar( lpGroupOnly_VeryShortFUpdate->WhoIAm );
			}
			else
			{
				if( ( Ships[ lpGroupOnly_VeryShortFUpdate->WhoIAm ].Object.Flags & SHIP_Multiple ) &&
					( ((BYTE)((lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Flags >> SHIP_NumMultiples_Bit1 ) & 15)) != Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].NumMultiples ) )
				{
					Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].NumMultiples = (BYTE)((lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Flags >> SHIP_NumMultiples_Bit1 ) & 15);
					CreateOrbitPulsar( lpGroupOnly_VeryShortFUpdate->WhoIAm );
				}
			}
			UnPackShipFlags( lpGroupOnly_VeryShortFUpdate->WhoIAm , lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Flags );

			Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Object.Pos.x	= (float) lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Pos.x;
			Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Object.Pos.y	= (float) lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Pos.y;
			Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Object.Pos.z	= (float) lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Pos.z;
			Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Object.Group= (int16) lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.GroupImIn;
			Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Object.Quat.w	= (float)(lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Quat.w * ONEOVER32767 );
			Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Object.Quat.x	= (float)(lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Quat.x * ONEOVER32767 );
			Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Object.Quat.y	= (float)(lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Quat.y * ONEOVER32767 );
			Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Object.Quat.z	= (float)(lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Quat.z * ONEOVER32767 );
			Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Object.Bank	= (float) (lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Bank / SHORTBANKMODIFIER);

			Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Primary	= lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Primary;
			Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Secondary	= lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Secondary;
			Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].PrimPowerLevel = (float) lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.PrimPowerLevel;

			Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Object.Noise = 1.0F;
			
			// Need This for missiles to work....
			SetShipBankAndMat( &Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Object );
			
			if( ( Ships[ lpGroupOnly_VeryShortFUpdate->WhoIAm ].Object.Flags & SHIP_PrimFire ) || ( Ships[ lpGroupOnly_VeryShortFUpdate->WhoIAm ].Object.Flags & SHIP_MulFire ) )
			{
				FirePrimaryWeapons( lpGroupOnly_VeryShortFUpdate->WhoIAm );					// Fire Primary Weapons	
			}
			if( ( Ships[ lpGroupOnly_VeryShortFUpdate->WhoIAm ].Object.Flags & SHIP_SecFire ) )
			{
				FireSecondaryWeapons( lpGroupOnly_VeryShortFUpdate->WhoIAm );					// Fire Secondary Weapons
			}

			Ships[ lpGroupOnly_VeryShortFUpdate->WhoIAm ].Primary = ConvPrimToNormWeapon( Ships[ lpGroupOnly_VeryShortFUpdate->WhoIAm ].Primary );
			Ships[ lpGroupOnly_VeryShortFUpdate->WhoIAm ].Secondary = ConvSecToNormWeapon( Ships[ lpGroupOnly_VeryShortFUpdate->WhoIAm ].Secondary );

/* Added by DC 30/6/98 */
			if( ( OldMode == DEATH_MODE ) && ( Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Object.Mode == LIMBO_MODE ) ||
				( OldMode == NORMAL_MODE ) && ( Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Object.Mode == LIMBO_MODE ) )
			{
				if( IsServerGame && IsServer )
				{
					VECTOR	ScatterDir;

					ScatterDir = Ships[ lpGroupOnly_VeryShortFUpdate->WhoIAm ].LastMove;
					NormaliseVector( &ScatterDir );
					ScatterWeaponsForShip( lpGroupOnly_VeryShortFUpdate->WhoIAm, &ScatterDir, MAXSCATTERED );	// Scatter weapons in all directions.
				}

				if( GoreGuts ) ThrowOutRider( lpGroupOnly_VeryShortFUpdate->WhoIAm );
				PlayPannedSfx( SFX_BikeExplode, Ships[ lpGroupOnly_VeryShortFUpdate->WhoIAm ].Object.Group , &Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Object.Pos, 0.0F );
				StopTaunt();
			}
/* ------------------- */

			DemoShipInit[ lpGroupOnly_VeryShortFUpdate->WhoIAm ] = TRUE;
			return;
		}else{
			wsprintf(dBuf, "someone else is in your slot..%d\n", lpGroupOnly_VeryShortFUpdate->WhoIAm);
			OutputDebugString( dBuf );
			return;
		}



    case MSG_VERYSHORTUPDATE:
		if (MyGameStatus == STATUS_StartingMultiplayer)
		{
			// only need ship scores...
			lpVeryShortUpdate = (LPVERYSHORTUPDATEMSG) MsgPnt;

			// ...and need to get host game status...
			if( lpVeryShortUpdate->ShortGlobalShip.Flags & SHIP_IsHost  )
				OverallGameStatus = lpVeryShortUpdate->ShortGlobalShip.Status;

			// ...and need to get names...
			CheckForName( lpVeryShortUpdate->WhoIAm );

			// ...and fill out GameStatus
			GameStatus[lpVeryShortUpdate->WhoIAm] = lpVeryShortUpdate->ShortGlobalShip.Status;
 
			return;
		}
		else
		{
			lpVeryShortUpdate = (LPVERYSHORTUPDATEMSG) MsgPnt;
			if( lpVeryShortUpdate->WhoIAm != WhoIAm )
			{
				Ships[lpVeryShortUpdate->WhoIAm].PacketDelay = PacketDelay;

				CheckCharging( lpVeryShortUpdate->WhoIAm, Ships[ lpVeryShortUpdate->WhoIAm ].Object.Flags, lpVeryShortUpdate->ShortGlobalShip.Flags );

				OldMode = Ships[lpVeryShortUpdate->WhoIAm].Object.Mode;
				OldStatus = GameStatus[lpVeryShortUpdate->WhoIAm];

				if( !( Ships[lpVeryShortUpdate->WhoIAm].Object.Flags & SHIP_Multiple ) && ( lpVeryShortUpdate->ShortGlobalShip.Flags & SHIP_Multiple ) )
				{
					for( Count = 0; Count < MAXMULTIPLES; Count++ ) Ships[ lpVeryShortUpdate->WhoIAm ].OrbModels[ Count ] = (uint16) -1;
					Ships[lpVeryShortUpdate->WhoIAm].NumMultiples = (BYTE)((lpVeryShortUpdate->ShortGlobalShip.Flags >> SHIP_NumMultiples_Bit1 ) & 15);
					CreateOrbitPulsar( lpVeryShortUpdate->WhoIAm );
				}
				else
				{
					if( ( Ships[ lpVeryShortUpdate->WhoIAm ].Object.Flags & SHIP_Multiple ) &&
						( ((BYTE)((lpVeryShortUpdate->ShortGlobalShip.Flags >> SHIP_NumMultiples_Bit1 ) & 15)) != Ships[lpVeryShortUpdate->WhoIAm].NumMultiples ) )
					{
						Ships[lpVeryShortUpdate->WhoIAm].NumMultiples = (BYTE)((lpVeryShortUpdate->ShortGlobalShip.Flags >> SHIP_NumMultiples_Bit1 ) & 15);
						CreateOrbitPulsar( lpVeryShortUpdate->WhoIAm );
					}
				}
				UnPackShipFlags( lpVeryShortUpdate->WhoIAm , lpVeryShortUpdate->ShortGlobalShip.Flags );

				Ships[lpVeryShortUpdate->WhoIAm].Object.Pos.x	= (float) lpVeryShortUpdate->ShortGlobalShip.Pos.x;
				Ships[lpVeryShortUpdate->WhoIAm].Object.Pos.y	= (float) lpVeryShortUpdate->ShortGlobalShip.Pos.y;
				Ships[lpVeryShortUpdate->WhoIAm].Object.Pos.z	= (float) lpVeryShortUpdate->ShortGlobalShip.Pos.z;
				Ships[lpVeryShortUpdate->WhoIAm].Move_Off.x	= (lpVeryShortUpdate->ShortGlobalShip.Move_Off.x * ONEOVER32767) * (lpVeryShortUpdate->ShortGlobalShip.Move_Off_Scalar * ONEOVER256 );
				Ships[lpVeryShortUpdate->WhoIAm].Move_Off.y	= (lpVeryShortUpdate->ShortGlobalShip.Move_Off.y * ONEOVER32767) * (lpVeryShortUpdate->ShortGlobalShip.Move_Off_Scalar * ONEOVER256 );
				Ships[lpVeryShortUpdate->WhoIAm].Move_Off.z	= (lpVeryShortUpdate->ShortGlobalShip.Move_Off.z * ONEOVER32767) * (lpVeryShortUpdate->ShortGlobalShip.Move_Off_Scalar * ONEOVER256 ); 
				Ships[lpVeryShortUpdate->WhoIAm].Object.Group= (int16) lpVeryShortUpdate->ShortGlobalShip.GroupImIn;
				Ships[lpVeryShortUpdate->WhoIAm].Object.Quat.w	= (float)(lpVeryShortUpdate->ShortGlobalShip.Quat.w * ONEOVER32767 );
				Ships[lpVeryShortUpdate->WhoIAm].Object.Quat.x	= (float)(lpVeryShortUpdate->ShortGlobalShip.Quat.x * ONEOVER32767 );
				Ships[lpVeryShortUpdate->WhoIAm].Object.Quat.y	= (float)(lpVeryShortUpdate->ShortGlobalShip.Quat.y * ONEOVER32767 );
				Ships[lpVeryShortUpdate->WhoIAm].Object.Quat.z	= (float)(lpVeryShortUpdate->ShortGlobalShip.Quat.z * ONEOVER32767 );
				Ships[lpVeryShortUpdate->WhoIAm].LastAngle.x	= (float)(lpVeryShortUpdate->ShortGlobalShip.Angle.x * SHORTANGLEMODIFIERUNPACK );
				Ships[lpVeryShortUpdate->WhoIAm].LastAngle.y	= (float)(lpVeryShortUpdate->ShortGlobalShip.Angle.y * SHORTANGLEMODIFIERUNPACK );
				Ships[lpVeryShortUpdate->WhoIAm].LastAngle.z	= (float)(lpVeryShortUpdate->ShortGlobalShip.Angle.z * SHORTANGLEMODIFIERUNPACK );

				Ships[lpVeryShortUpdate->WhoIAm].Object.Bank	= (float) (lpVeryShortUpdate->ShortGlobalShip.Bank / SHORTBANKMODIFIER);

				Ships[lpVeryShortUpdate->WhoIAm].JustRecievedPacket = TRUE;

				GameStatus[lpVeryShortUpdate->WhoIAm] = lpVeryShortUpdate->ShortGlobalShip.Status;

				if( lpVeryShortUpdate->ShortGlobalShip.Flags & SHIP_IsHost  )
					OverallGameStatus = lpVeryShortUpdate->ShortGlobalShip.Status;
				
				Ships[lpVeryShortUpdate->WhoIAm].dcoID	= from_dcoID;
				
				if( glpDP )
				{
					if( CheckForName( lpVeryShortUpdate->WhoIAm ) )
					{
						if( RecordDemo )
						{
							// Best way I can Think of to send the names to the demo file...
							TempTime = 1;
							Demo_fwrite( &TempTime, sizeof(LONGLONG), 1, DemoFp );
							size = sizeof( NAMEMSG );
							Demo_fwrite( &size, sizeof(int), 1, DemoFp );
							Demo_fwrite( &dcoID, sizeof(DPID), 1, DemoFp );
							msg = MSG_NAME;
							Demo_fwrite( &msg, sizeof(BYTE), 1, DemoFp );
							Demo_fwrite( &lpVeryShortUpdate->WhoIAm, sizeof(BYTE), 1, DemoFp );
							Demo_fwrite( &Names[lpVeryShortUpdate->WhoIAm][0], 8, 1, DemoFp );
						}
					}
				}

				if( ( OldMode == DEATH_MODE ) && ( Ships[lpVeryShortUpdate->WhoIAm].Object.Mode == LIMBO_MODE ) ||
					( OldMode == NORMAL_MODE ) && ( Ships[lpVeryShortUpdate->WhoIAm].Object.Mode == LIMBO_MODE ) )
				{
					if( IsServerGame && IsServer )
					{
						VECTOR	ScatterDir;

						ScatterDir = Ships[ lpVeryShortUpdate->WhoIAm ].LastMove;
						NormaliseVector( &ScatterDir );
						ScatterWeaponsForShip( lpVeryShortUpdate->WhoIAm, &ScatterDir, MAXSCATTERED );	// Scatter weapons in all directions.
					}

					if( GoreGuts ) ThrowOutRider( lpVeryShortUpdate->WhoIAm );
					PlayPannedSfx( SFX_BikeExplode, Ships[ lpVeryShortUpdate->WhoIAm ].Object.Group , &Ships[lpVeryShortUpdate->WhoIAm].Object.Pos, 0.0F );
					StopTaunt();
				}

				
				if( ( ( OldMode == LIMBO_MODE ) && ( Ships[lpVeryShortUpdate->WhoIAm].Object.Mode == NORMAL_MODE ) )
					|| ( ( OldStatus != STATUS_Normal) && (GameStatus[lpVeryShortUpdate->WhoIAm] == STATUS_Normal ) ) )
				{
					CreateReGen( lpVeryShortUpdate->WhoIAm );
				}

				DemoShipInit[ lpVeryShortUpdate->WhoIAm ] = TRUE;
				if( IsServer )
				{
					Ships[lpVeryShortUpdate->WhoIAm].RealPos = Ships[lpVeryShortUpdate->WhoIAm].Object.Pos;
					Ships[lpVeryShortUpdate->WhoIAm].RealGroup = Ships[lpVeryShortUpdate->WhoIAm].Object.Group;
				}

				
				return;
			}else{
				wsprintf(dBuf, "someone else is in your slot..%d\n", lpVeryShortUpdate->WhoIAm);
				OutputDebugString( dBuf );
				return;
			}
		}
    case MSG_UPDATE:
		if (MyGameStatus == STATUS_StartingMultiplayer)
		{
			// only need ship scores...
			lpUpdate = (LPUPDATEMSG) MsgPnt;

			// ...and need to get host game status...
			if( lpUpdate->ShortGlobalShip.Flags & SHIP_IsHost  )
				OverallGameStatus = lpUpdate->ShortGlobalShip.Status;

			// ...and need to get names...
			CheckForName( lpUpdate->WhoIAm );
			return;
		}
		else
		{
			lpUpdate = (LPUPDATEMSG) MsgPnt;
			if( lpUpdate->WhoIAm != WhoIAm )
			{
				Ships[lpUpdate->WhoIAm].PacketDelay = PacketDelay;

				CheckCharging( lpUpdate->WhoIAm, Ships[ lpUpdate->WhoIAm ].Object.Flags, lpUpdate->ShortGlobalShip.Flags );

				OldMode = Ships[lpUpdate->WhoIAm].Object.Mode;
				OldStatus = GameStatus[lpUpdate->WhoIAm];

				if( !( Ships[lpUpdate->WhoIAm].Object.Flags & SHIP_Multiple ) && ( lpUpdate->ShortGlobalShip.Flags & SHIP_Multiple ) )
				{
					for( Count = 0; Count < MAXMULTIPLES; Count++ ) Ships[ lpUpdate->WhoIAm ].OrbModels[ Count ] = (uint16) -1;
					Ships[lpUpdate->WhoIAm].NumMultiples = (BYTE)((lpUpdate->ShortGlobalShip.Flags >> SHIP_NumMultiples_Bit1 ) & 15);
					CreateOrbitPulsar( lpUpdate->WhoIAm );
				}
				else
				{
					if( ( Ships[ lpUpdate->WhoIAm ].Object.Flags & SHIP_Multiple ) &&
						( ((BYTE)((lpUpdate->ShortGlobalShip.Flags >> SHIP_NumMultiples_Bit1 ) & 15)) != Ships[lpUpdate->WhoIAm].NumMultiples ) )
					{
						Ships[lpUpdate->WhoIAm].NumMultiples = (BYTE)((lpUpdate->ShortGlobalShip.Flags >> SHIP_NumMultiples_Bit1 ) & 15);
						CreateOrbitPulsar( lpUpdate->WhoIAm );
					}
				}

				UnPackShipFlags( lpUpdate->WhoIAm , lpUpdate->ShortGlobalShip.Flags );


				Ships[lpUpdate->WhoIAm].Object.Pos	= lpUpdate->ShortGlobalShip.Pos;
				Ships[lpUpdate->WhoIAm].Move_Off	= lpUpdate->ShortGlobalShip.Move_Off;
				Ships[lpUpdate->WhoIAm].Object.Group= (int16) lpUpdate->ShortGlobalShip.GroupImIn;
				Ships[lpUpdate->WhoIAm].Object.Quat	= lpUpdate->ShortGlobalShip.Quat;
				Ships[lpUpdate->WhoIAm].LastAngle	= lpUpdate->ShortGlobalShip.Angle;
#ifdef	SHORTBANK
				Ships[lpUpdate->WhoIAm].Object.Bank	= (float) (lpUpdate->ShortGlobalShip.Bank / SHORTBANKMODIFIER);
#else
				Ships[lpUpdate->WhoIAm].Object.Bank	= lpUpdate->ShortGlobalShip.Bank;
#endif

				Ships[lpUpdate->WhoIAm].JustRecievedPacket = TRUE;

				GameStatus[lpUpdate->WhoIAm] = lpUpdate->ShortGlobalShip.Status;

				if( lpUpdate->ShortGlobalShip.Flags & SHIP_IsHost  )
					OverallGameStatus = lpUpdate->ShortGlobalShip.Status;
				
				Ships[lpUpdate->WhoIAm].dcoID	= from_dcoID;

				if( !Ships[lpUpdate->WhoIAm].FirstPacketRecieved  )
				{
//					if( ((int8)( Ships[lpUpdate->WhoIAm].LastPacketID + 1)) != lpUpdate->ShortGlobalShip.LastPacketID )
//					{
//						wsprintf(dBuf, "Missed %d Packets From %s\n", (lpUpdate->ShortGlobalShip.LastPacketID + 1 - Ships[lpUpdate->WhoIAm].LastPacketID) ,
//													 &Names[lpUpdate->WhoIAm][0] );
//						OutputDebugString( dBuf );
//					}
//					Ships[lpUpdate->WhoIAm].LastPacketID  = lpUpdate->ShortGlobalShip.LastPacketID;
				}else{
					Ships[lpUpdate->WhoIAm].FirstPacketRecieved = FALSE;
//					Ships[lpUpdate->WhoIAm].LastPacketID  = lpUpdate->ShortGlobalShip.LastPacketID;
				}

				
				if( glpDP )
				{
					if( CheckForName( lpUpdate->WhoIAm ) )
					{
						if( RecordDemo )
						{
							// Best way I can Think of to send the names to the demo file...
							TempTime = 1;
							Demo_fwrite( &TempTime, sizeof(LONGLONG), 1, DemoFp );
							size = sizeof( NAMEMSG );
							Demo_fwrite( &size, sizeof(int), 1, DemoFp );
							Demo_fwrite( &dcoID, sizeof(DPID), 1, DemoFp );
							msg = MSG_NAME;
							Demo_fwrite( &msg, sizeof(BYTE), 1, DemoFp );
							Demo_fwrite( &lpUpdate->WhoIAm, sizeof(BYTE), 1, DemoFp );
							Demo_fwrite( &Names[lpUpdate->WhoIAm][0], 8, 1, DemoFp );
						}
					}
				}

				if( ( OldMode == DEATH_MODE ) && ( Ships[lpUpdate->WhoIAm].Object.Mode == LIMBO_MODE ) ||
					( OldMode == NORMAL_MODE ) && ( Ships[lpUpdate->WhoIAm].Object.Mode == LIMBO_MODE ) )
				{
					if( IsServerGame && IsServer )
					{
						VECTOR	ScatterDir;

						ScatterDir = Ships[ lpUpdate->WhoIAm ].LastMove;
						NormaliseVector( &ScatterDir );
						ScatterWeaponsForShip( lpUpdate->WhoIAm, &ScatterDir, MAXSCATTERED );	// Scatter weapons in all directions.
					}

					if( GoreGuts ) ThrowOutRider( lpUpdate->WhoIAm );
					PlayPannedSfx( SFX_BikeExplode, Ships[ lpUpdate->WhoIAm ].Object.Group , &Ships[lpUpdate->WhoIAm].Object.Pos, 0.0F );
					StopTaunt();
				}

				
				if( ( ( OldMode == LIMBO_MODE ) && ( Ships[lpUpdate->WhoIAm].Object.Mode == NORMAL_MODE ) )
					|| ( ( OldStatus != STATUS_Normal) && (GameStatus[lpUpdate->WhoIAm] == STATUS_Normal ) ) )
				{
					CreateReGen( lpUpdate->WhoIAm );
				}

				DemoShipInit[ lpUpdate->WhoIAm ] = TRUE;
				if( IsServer )
				{
					Ships[lpUpdate->WhoIAm].RealPos = Ships[lpUpdate->WhoIAm].Object.Pos;
					Ships[lpUpdate->WhoIAm].RealGroup = Ships[lpUpdate->WhoIAm].Object.Group;
				}

				
				return;
			}else{
				wsprintf(dBuf, "someone else is in your slot..%d\n", lpUpdate->WhoIAm);
				OutputDebugString( dBuf );
				return;
			}
		}
    case MSG_NAME:
		lpName = (LPNAMEMSG)MsgPnt;
		if( lpName->WhoIAm == WhoIAm )
			return;

		for( i = 0 ; i < 8 ; i++ )
		{
#if defined (SELF_PLAY) || defined (ECTS)
			// force player to use same name as his bike
			Names[lpName->WhoIAm][i] = BikeList.item[lpName->WhoIAm % MAXBIKETYPES][i];
#elif defined( SHAREWARE )
			if ( PlayDemo )
			{
				Names[lpName->WhoIAm][i] = BikeList.item[AllowedBike[lpName->WhoIAm % ALLOWED_BIKETYPES]][i];
			}
			else
			{
				Names[lpName->WhoIAm][i] = lpName->Name[i];
			}
#else
			Names[lpName->WhoIAm][i] = lpName->Name[i];
#endif
  
			if( WhoIAm < MAX_PLAYERS )
				Names[WhoIAm][i] = biker_name[i];

		
		}
		Names[lpName->WhoIAm][7] = 0;
		Names[WhoIAm][7] = 0;

		DebugPrintf("Recieved name %s from player %d\n" , &Names[lpName->WhoIAm][0] , lpName->WhoIAm );
		NextworkOldKills = -1;
		NextworkOldDeaths = -1;
		NextworkOldBikeNum = -1;
		return;

    case MSG_FUPDATE:

		lpFUpdate = (LPFUPDATEMSG)MsgPnt;
		if( lpFUpdate->WhoIAm != WhoIAm )
		{
			OldMode = Ships[lpFUpdate->WhoIAm].Object.Mode;

			Ships[lpFUpdate->WhoIAm].PacketDelay = PacketDelay;
			CheckCharging( lpFUpdate->WhoIAm, Ships[ lpFUpdate->WhoIAm ].Object.Flags, lpFUpdate->ShortGlobalShip.Flags );


			if( !( Ships[lpFUpdate->WhoIAm].Object.Flags & SHIP_Multiple ) && ( lpFUpdate->ShortGlobalShip.Flags & SHIP_Multiple ) )
			{
				for( Count = 0; Count < MAXMULTIPLES; Count++ ) Ships[ lpFUpdate->WhoIAm ].OrbModels[ Count ] = (uint16) -1;
				Ships[lpFUpdate->WhoIAm].NumMultiples = (BYTE)((lpFUpdate->ShortGlobalShip.Flags >> SHIP_NumMultiples_Bit1 ) & 15);
				CreateOrbitPulsar( lpFUpdate->WhoIAm );
			}
			else
			{
				if( ( Ships[ lpFUpdate->WhoIAm ].Object.Flags & SHIP_Multiple ) &&
					( ((BYTE)((lpFUpdate->ShortGlobalShip.Flags >> SHIP_NumMultiples_Bit1 ) & 15)) != Ships[lpFUpdate->WhoIAm].NumMultiples ) )
				{
					Ships[lpFUpdate->WhoIAm].NumMultiples = (BYTE)((lpFUpdate->ShortGlobalShip.Flags >> SHIP_NumMultiples_Bit1 ) & 15);
					CreateOrbitPulsar( lpFUpdate->WhoIAm );
				}
			}
			UnPackShipFlags( lpFUpdate->WhoIAm , lpFUpdate->ShortGlobalShip.Flags );

			Ships[lpFUpdate->WhoIAm].Object.Pos		= lpFUpdate->ShortGlobalShip.Pos;
			Ships[lpFUpdate->WhoIAm].Move_Off	= lpFUpdate->ShortGlobalShip.Move_Off;
			Ships[lpFUpdate->WhoIAm].Object.Group  = lpFUpdate->ShortGlobalShip.GroupImIn;
			Ships[lpFUpdate->WhoIAm].Primary	= lpFUpdate->ShortGlobalShip.Primary;
			Ships[lpFUpdate->WhoIAm].Secondary	= lpFUpdate->ShortGlobalShip.Secondary;
			Ships[lpFUpdate->WhoIAm].Object.Quat	= lpFUpdate->ShortGlobalShip.Quat;
			Ships[lpFUpdate->WhoIAm].PrimPowerLevel = (float) lpFUpdate->ShortGlobalShip.PrimPowerLevel;
			Ships[lpFUpdate->WhoIAm].LastAngle	= lpFUpdate->ShortGlobalShip.Angle;
#ifdef	SHORTBANK
			Ships[lpFUpdate->WhoIAm].Object.Bank	= (float) (lpFUpdate->ShortGlobalShip.Bank / SHORTBANKMODIFIER);
#else
			Ships[lpFUpdate->WhoIAm].Object.Bank	= lpFUpdate->ShortGlobalShip.Bank;
#endif

			Ships[lpFUpdate->WhoIAm].JustRecievedPacket = TRUE;

			// Need This for missiles to work....
			SetShipBankAndMat( &Ships[lpFUpdate->WhoIAm].Object );

			Ships[lpFUpdate->WhoIAm].Object.Noise = 1.0F;
			
			if( ( Ships[ lpFUpdate->WhoIAm ].Object.Flags & SHIP_PrimFire ) || ( Ships[ lpFUpdate->WhoIAm ].Object.Flags & SHIP_MulFire ) )
			{
				FirePrimaryWeapons( lpFUpdate->WhoIAm );					// Fire Primary Weapons	
			}
			if( ( Ships[ lpFUpdate->WhoIAm ].Object.Flags & SHIP_SecFire ) )
			{
				FireSecondaryWeapons( lpFUpdate->WhoIAm );					// Fire Secondary Weapons
			}

			Ships[ lpFUpdate->WhoIAm ].Primary = ConvPrimToNormWeapon( Ships[ lpFUpdate->WhoIAm ].Primary );
			Ships[ lpFUpdate->WhoIAm ].Secondary = ConvSecToNormWeapon( Ships[ lpFUpdate->WhoIAm ].Secondary );

/* Added by DC 30/6/98 */
			if( ( OldMode == DEATH_MODE ) && ( Ships[lpFUpdate->WhoIAm].Object.Mode == LIMBO_MODE ) ||
				( OldMode == NORMAL_MODE ) && ( Ships[lpFUpdate->WhoIAm].Object.Mode == LIMBO_MODE ) )
			{
				if( IsServerGame && IsServer )
				{
					VECTOR	ScatterDir;

					ScatterDir = Ships[ lpFUpdate->WhoIAm ].LastMove;
					NormaliseVector( &ScatterDir );
					ScatterWeaponsForShip( lpFUpdate->WhoIAm, &ScatterDir, MAXSCATTERED );	// Scatter weapons in all directions.
				}

				if( GoreGuts ) ThrowOutRider( lpFUpdate->WhoIAm );
				PlayPannedSfx( SFX_BikeExplode, Ships[ lpFUpdate->WhoIAm ].Object.Group , &Ships[lpFUpdate->WhoIAm].Object.Pos, 0.0F );
				StopTaunt();
			}
/* ------------------- */

			DemoShipInit[ lpFUpdate->WhoIAm ] = TRUE;
			if( IsServer )
			{
				Ships[lpFUpdate->WhoIAm].RealPos = Ships[lpFUpdate->WhoIAm].Object.Pos;
				Ships[lpFUpdate->WhoIAm].RealGroup = Ships[lpFUpdate->WhoIAm].Object.Group;
			}
			return;
		}else{
			wsprintf(dBuf, "someone else is in your slot..%d\n", lpFUpdate->WhoIAm);
			OutputDebugString( dBuf );
			return;
		}

	case MSG_HEREIAM:
		if( IsHost && !PlayDemo )
		{
			BOOL AllocatingPseudoHost = FALSE;
			BOOL Done = FALSE;
			lpHereIAm = (LPHEREIAMMSG)MsgPnt;

			// if host is server, need to move to relevent menu depending on current server status
			DPlayGetSessionDesc();
			switch( glpdpSD->dwUser3 & ServerGameStateBits )
			{
			case SERVER_STATE_NeedHost:
				// change to 'host is choosing' menu
				MenuChangeEx( &MENU_NEW_ServerWaitingForGameParameters );
				
				AllocatingPseudoHost = TRUE;

				/*
				// modify server state in session description
				DPlayGetSessionDesc();
				glpdpSD->dwUser3 &= ~ServerGameStateBits;	// mask out old server state
				glpdpSD->dwUser3 |=	SERVER_STATE_HostChoosing;
				DebugPrintf("server - about to change state to HostChoosing\n");
				DPlaySetSessionDesc(0);
				*/
				break;
			case SERVER_STATE_HostChoosing:
				// should never get here, as you will not be able to join a game if host is choosing game type
#ifdef DEBUG_ON
				// this could happen if packets recieved in wrong order

				//Msg("Error - client has requested player number for server based game before game parameters set ( %s %d )", __FILE__, __LINE__ );
#endif
				return;	// return without sending any messages back, thus joining player will never get player number
			case SERVER_STATE_Joinable:
				// allow joining as normal
				break;
			}

			for( i = 0 ; i < MAX_PLAYERS ; i++ )
			{
				// if we have allready heard from them then we have to send back a special message..
				if( ( Ships[i].dcoID == from_dcoID ) && ( GameStatus[i] == STATUS_GetPlayerNum ) )
				{
					SendGameMessage(MSG_INIT, lpHereIAm->ID, (BYTE) i , lpHereIAm->Old_TeamNumber, 1);
					SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
					if ( WSA_Active )	// if winsock active ( we are sending heartbeat info )
						SendGameMessage(MSG_TRACKERINFO, lpHereIAm->ID, 0, 0, 0);
					Done = TRUE;
				}										  
			}

			if ( !Done )		    
			{
				if( lpHereIAm->Rejoining )
				{
					SendGameMessage(MSG_INIT, lpHereIAm->ID, lpHereIAm->Old_WhoIAm, lpHereIAm->Old_TeamNumber, 0);
					SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
					if ( WSA_Active )	// if winsock active ( we are sending heartbeat info )
						SendGameMessage(MSG_TRACKERINFO, lpHereIAm->ID, 0, 0, 0);
				}else{
					SendGameMessage(MSG_INIT, lpHereIAm->ID, MAX_PLAYERS, 0, 0);
					SendGameMessage(MSG_STATUS, 0, 0, 0, 0);
					if ( WSA_Active )	// if winsock active ( we are sending heartbeat info )
						SendGameMessage(MSG_TRACKERINFO, lpHereIAm->ID, 0, 0, 0);
				}
			}
			if ( AllocatingPseudoHost )
			{
				// modify server state in session description
				DPlayGetSessionDesc();
				glpdpSD->dwUser3 &= ~ServerGameStateBits;	// mask out old server state
				glpdpSD->dwUser3 |=	SERVER_STATE_HostChoosing;
				DebugPrintf("server - about to change state to HostChoosing\n");
				DPlaySetSessionDesc(0);

				PseudoHostDPID = lpHereIAm->ID; 
			}
		}
		return;
    case MSG_INIT:
		lpInit = (LPINITMSG) MsgPnt;

		HostDPID = lpInit->FromDpid;

		IsPseudoHost = FALSE;
		// if we are getting a player number and this is a server game in the SERVER_NeedHost state, then we are the Pseudo Host
		switch( lpInit->dwUser3 & ServerGameStateBits )
		{
		case SERVER_STATE_NeedHost:
			IsPseudoHost = TRUE;
			break;
		case SERVER_STATE_HostChoosing:
#ifdef DEBUG_ON
			Msg("Error - Server is sending out MSG_INIT when in state SERVER_STATE_HostChoosing\n");
#endif
			return;	// ignore messsage
		case SERVER_STATE_Joinable:
			// just carry on as if normal game
			break;
		default:	// ie. not server game
			break;
		}

		//MaxKills = lpInit->MaxKills;

		ServerCollisions = lpInit->ServerCollisions;
		
		OverallGameStatus = lpInit->Status;
		DPlayUpdateInterval = lpInit->PacketsPerSecond;
		PacketsSlider.value = (int) (60.0F / DPlayUpdateInterval);

		for( i = 0 ; i < MAX_PLAYERS ; i++ )			
		{															
			PlayerReady[i] = lpInit->PlayerReady[i];
			if( i != WhoIAm && i != lpInit->YouAre )
				GameStatus[i] = lpInit->GameStatus[i];

		}															
		if ( WhoIAm == 0xff )
		{
			if( !IsHost )
			{
				WhoIAm = lpInit->YouAre;
				Current_Camera_View = WhoIAm;

				// no need to do any of this if pseudo host
				if ( !IsPseudoHost )
				{
					//HarmTeamMates = lpInit->HarmTeamMates;
					//BrightShips = lpInit->BrightShips;
					//BikeExhausts = lpInit->BikeExhausts;
					//ColPerspective = lpInit->Collisions;

					UnpackPickupInfo( lpInit->PickupFlags );

					DebugPrintf("host says level is %s\n", lpInit->LevelName );

					NewLevelNum = FindSameLevel( &lpInit->LevelName[0] );
					if( NewLevelNum == -1 )
					{
						DebugPrintf("client cannot find level %s\n", lpInit->LevelName );
						WhoIAm = MAX_PLAYERS+1;
						return;
					}
				}

				for( i = 0 ; i < MAX_PLAYERS ; i++ )
				{
					TeamNumber[i] = lpInit->TeamNumber[i];
				}
			}
		}else{
			// team selection order from the host..copies it for every one...
			memset (TeamNumber, 255, sizeof(BYTE) * MAX_PLAYERS);
			for( i = 0 ; i < MAX_PLAYERS ; i++ )
			{
				TeamNumber[i] = lpInit->TeamNumber[i];
			}
			TeamNumber[WhoIAm] = 0;
		}

		// if we are the pseudo host, we will be setting these ourseleves
		if ( !IsPseudoHost )
		{
			if ( BountyHunt )
				BountyBonusInterval = lpInit->BountyBonusInterval;
			if ( CaptureTheFlag || CTF )
				GoalScore = lpInit->GoalScore;

			NumPrimaryPickups = lpInit->PrimaryPickups;

			/*
			if ( CTF )
			{
				switch ( lpInit->CTF_Type )
				{
				case CTF_MUST_CARRY:
					NeedFlagAtHome			= TRUE;
					OwnFlagTeleportsHome	= FALSE;
					CanCarryOwnFlag			= TRUE;
					break;
				case CTF_CAN_CARRY:
					NeedFlagAtHome			= FALSE;
					OwnFlagTeleportsHome	= FALSE;
					CanCarryOwnFlag			= TRUE;
					break;
				case CTF_ONE_TOUCH:
					NeedFlagAtHome			= FALSE;
					OwnFlagTeleportsHome	= TRUE;
					CanCarryOwnFlag			= FALSE;
					break;
				case CTF_NO_RETURN:
					NeedFlagAtHome			= FALSE;
					OwnFlagTeleportsHome	= FALSE;
					CanCarryOwnFlag			= FALSE;
					break;
				case CTF_STANDARD:
				default:
					NeedFlagAtHome			= TRUE;
					OwnFlagTeleportsHome	= TRUE;
					CanCarryOwnFlag			= FALSE;
				}
			}
			*/
		}

		RandomPickups = lpInit->RandomPickups;
		CopyOfSeed1 = lpInit->Seed1;
		CopyOfSeed2 = lpInit->Seed2;
		return;

    case MSG_DROPPICKUP:
		lpDropPickup = (LPDROPPICKUPMSG)MsgPnt;
#if DEBUG_PICKUPS
		if( lpDropPickup->WhoIAm != (uint16) -1 ) DebugPrintf( "PACKET OWNER '%s' : Init '%s', Owner '%s', ID %d\n", &Names[ lpDropPickup->WhoIAm ][ 0 ], Messages[ lpDropPickup->PickupInfo.Type ], &Names[ lpDropPickup->WhoIAm ][ 0 ], lpDropPickup->PickupInfo.IDCount );
		else DebugPrintf( "PACKET OWNER '%s' : Init '%s', No Owner, ID %d\n", &Names[ lpDropPickup->WhoIAm ][ 0 ], Messages[ lpDropPickup->PickupInfo.Type ], lpDropPickup->PickupInfo.IDCount );
#endif
	 	Pickup = InitOnePickup( &lpDropPickup->PickupInfo.Pos, lpDropPickup->PickupInfo.Group,
		 				   &lpDropPickup->PickupInfo.Dir, lpDropPickup->PickupInfo.Speed,
		 				   lpDropPickup->PickupInfo.Type, lpDropPickup->WhoIAm,
	 					   lpDropPickup->PickupInfo.IDCount, lpDropPickup->PickupInfo.RegenSlot,
	 					   lpDropPickup->PickupInfo.Sparkle, lpDropPickup->PickupInfo.LifeCount,
						   lpDropPickup->PickupInfo.TriggerMod );

		if( ( Pickup != (uint16) -1 ) && ( Pickup != (uint16) -2 ) )
		{
			if( IsServerGame && IsServer )
			{
				Pickups[ Pickup ].ActualOwner = lpDropPickup->WhoIAm;
			}
		}
		return;

    case MSG_VERYSHORTDROPPICKUP:
		lpVeryShortDropPickup = (LPVERYSHORTDROPPICKUPMSG)MsgPnt;


		TempPickup.Pos.x = (float) lpVeryShortDropPickup->PickupInfo.Pos.x;
		TempPickup.Pos.y = (float) lpVeryShortDropPickup->PickupInfo.Pos.y;
		TempPickup.Pos.z = (float) lpVeryShortDropPickup->PickupInfo.Pos.z;
		TempPickup.Dir.x = lpVeryShortDropPickup->PickupInfo.Dir.x * ONEOVER32767;
		TempPickup.Dir.y = lpVeryShortDropPickup->PickupInfo.Dir.y * ONEOVER32767;
		TempPickup.Dir.z = lpVeryShortDropPickup->PickupInfo.Dir.z * ONEOVER32767;

		TempPickup.IDCount = lpVeryShortDropPickup->PickupInfo.IDCount;
		TempPickup.Type = lpVeryShortDropPickup->PickupInfo.Type;
		TempPickup.Group = lpVeryShortDropPickup->PickupInfo.Group;
		TempPickup.Speed = lpVeryShortDropPickup->PickupInfo.Speed;
		TempPickup.RegenSlot = lpVeryShortDropPickup->PickupInfo.RegenSlot;
		TempPickup.Sparkle = lpVeryShortDropPickup->PickupInfo.Sparkle;
		TempPickup.LifeCount = lpVeryShortDropPickup->PickupInfo.LifeCount;
		TempPickup.TriggerMod = lpVeryShortDropPickup->PickupInfo.TriggerMod;

#if DEBUG_PICKUPS
		if( lpDropPickup->WhoIAm != (uint16) -1 ) DebugPrintf( "PACKET OWNER '%s' : Init '%s', Owner '%s', ID %d\n", &Names[ lpDropPickup->WhoIAm ][ 0 ], Messages[ TempPickup.Type ], &Names[ lpDropPickup->WhoIAm ][ 0 ], TempPickup.IDCount );
		else DebugPrintf( "PACKET OWNER '%s' : Init '%s', No Owner, ID %d\n", &Names[ lpDropPickup->WhoIAm ][ 0 ], Messages[ TempPickup.Type ], TempPickup.IDCount );
#endif
	 	Pickup = InitOnePickup( &TempPickup.Pos, TempPickup.Group,
		 				   &TempPickup.Dir, TempPickup.Speed,
		 				   TempPickup.Type, lpVeryShortDropPickup->WhoIAm,
	 					   TempPickup.IDCount, TempPickup.RegenSlot,
	 					   TempPickup.Sparkle, TempPickup.LifeCount,
						   TempPickup.TriggerMod );

		if( ( Pickup != (uint16) -1 ) && ( Pickup != (uint16) -2 ) )
		{
			if( IsServerGame && IsServer )
			{
				Pickups[ Pickup ].ActualOwner = lpVeryShortDropPickup->WhoIAm;
			}
		}
		return;


    case MSG_KILLPICKUP:
   		lpKillPickup = (LPKILLPICKUPMSG)MsgPnt;
		if( PlayDemo && ( Current_Camera_View == lpKillPickup->WhoIAm ) && ( lpKillPickup->KillPickupInfo.Style == PICKUPKILL_Immediate ) )
		{
			SfxForCollectPickup( lpKillPickup->KillPickupInfo.Owner, lpKillPickup->KillPickupInfo.IDCount );
		}

#if DEBUG_PICKUPS
		if( lpKillPickup->KillPickupInfo.Owner != (uint16) -1 ) DebugPrintf( "PACKET OWNER '%s' : Kill Pickup Owner '%s', ID %d\n", &Names[ lpKillPickup->WhoIAm ][ 0 ], &Names[ lpKillPickup->KillPickupInfo.Owner ][ 0 ], lpKillPickup->KillPickupInfo.IDCount );
		else DebugPrintf( "PACKET OWNER '%s' : Kill Pickup No Owner, ID %d\n", &Names[ lpKillPickup->WhoIAm ][ 0 ], lpKillPickup->KillPickupInfo.IDCount );
#endif
		KillPickup( lpKillPickup->KillPickupInfo.Owner, lpKillPickup->KillPickupInfo.IDCount, lpKillPickup->KillPickupInfo.Style );
		return;

    case MSG_SERVERKILLPICKUP:
   		lpServerKillPickup = (LPSERVERKILLPICKUPMSG)MsgPnt;
		if( PlayDemo && ( Current_Camera_View == lpServerKillPickup->WhoIAm ) && ( lpServerKillPickup->ServerKillPickupInfo.Style == PICKUPKILL_Immediate ) )
		{
			SfxForCollectPickup( lpServerKillPickup->ServerKillPickupInfo.Owner, lpServerKillPickup->ServerKillPickupInfo.IDCount );
		}

#if DEBUG_PICKUPS
		if( lpServerKillPickup->ServerKillPickupInfo.Owner != (uint16) -1 ) DebugPrintf( "PACKET OWNER '%s' : Kill Pickup Owner '%s', ID %d\n", &Names[ lpServerKillPickup->WhoIAm ][ 0 ], &Names[ lpServerKillPickup->ServerKillPickupInfo.Owner ][ 0 ], lpServerKillPickup->ServerKillPickupInfo.IDCount );
		else DebugPrintf( "PACKET OWNER '%s' : Kill Pickup No Owner, ID %d\n", &Names[ lpServerKillPickup->WhoIAm ][ 0 ], lpServerKillPickup->ServerKillPickupInfo.IDCount );
#endif
		ServerKillPickup( lpServerKillPickup->ServerKillPickupInfo.Owner, lpServerKillPickup->ServerKillPickupInfo.IDCount, lpServerKillPickup->ServerKillPickupInfo.Style, lpServerKillPickup->ServerKillPickupInfo.NewOwner  );
		return;

    case MSG_EXPLODESHIP:
   		lpExplodeShip = (LPEXPLODESHIPMSG)MsgPnt;

		if( IsServerGame && IsServer )
		{
			ScatterDir = Ships[ lpExplodeShip->ExplodeShipInfo.Ship ].LastMove;
			NormaliseVector( &ScatterDir );
			ScatterWeaponsForShip( lpExplodeShip->ExplodeShipInfo.Ship, &ScatterDir, MAXSCATTERED );	// Scatter weapons in all directions.
		}
		return;

    case MSG_EXPSECONDARY:
		lpExplodeSecondary = (LPEXPSECONDARYMSG)MsgPnt;
		ExplodeSecondary( &lpExplodeSecondary->ExplodeSecondaryInfo.Pos,
						  lpExplodeSecondary->ExplodeSecondaryInfo.Group,
						  lpExplodeSecondary->ExplodeSecondaryInfo.OwnerType,
						  lpExplodeSecondary->ExplodeSecondaryInfo.Owner,
						  lpExplodeSecondary->ExplodeSecondaryInfo.IDCount,
						  lpExplodeSecondary->ExplodeSecondaryInfo.ShockwaveSize );
   		return;

    case MSG_TEAMGOALS:
		lpTeamGoals = (LPTEAMGOALSMSG)MsgPnt;
		SetTeamGoals( &lpTeamGoals->TeamGoalsInfo.TeamGoals[ 0 ] );
   		return;

    case MSG_SHOCKWAVE:
   		lpShockwave = (LPSHOCKWAVEMSG)MsgPnt;
   		CreateShockwave( OWNER_SHIP,
						 lpShockwave->ShockwaveInfo.Owner,
   						 &lpShockwave->ShockwaveInfo.Pos,
   						 lpShockwave->ShockwaveInfo.Group,
   						 lpShockwave->ShockwaveInfo.ShockwaveSize,
						 lpShockwave->ShockwaveInfo.Weapon );
   		return;

    case MSG_BGOUPDATE:
   		lpBGOUpdate = (LPBGOUPDATEMSG)MsgPnt;
   		UpdateBGObject( lpBGOUpdate->BGOUpdateInfo.BGObject,
						lpBGOUpdate->BGOUpdateInfo.State,
						lpBGOUpdate->BGOUpdateInfo.Time );
   		return;

    case MSG_PRIMBULLPOSDIR:
   		lpPrimBullPosDir = (LPPRIMBULLPOSDIRMSG)MsgPnt;
		InitOnePrimBull( lpPrimBullPosDir->PrimBullPosDir.OwnerType,
						lpPrimBullPosDir->PrimBullPosDir.OwnerID,
						lpPrimBullPosDir->PrimBullPosDir.BulletID,
						lpPrimBullPosDir->PrimBullPosDir.Weapon,
						lpPrimBullPosDir->PrimBullPosDir.Group,
						&lpPrimBullPosDir->PrimBullPosDir.Pos,
						&lpPrimBullPosDir->PrimBullPosDir.Offset,
						&lpPrimBullPosDir->PrimBullPosDir.Dir,
						&lpPrimBullPosDir->PrimBullPosDir.Up,
						lpPrimBullPosDir->PrimBullPosDir.PowerLevel,
						lpPrimBullPosDir->PrimBullPosDir.PLevel, FALSE );

   		return;
    case MSG_SECBULLPOSDIR:
   		lpSecBullPosDir = (LPSECBULLPOSDIRMSG)MsgPnt;
		InitOneSecBull( lpSecBullPosDir->SecBullPosDir.OwnerType,
						lpSecBullPosDir->SecBullPosDir.Owner,
						lpSecBullPosDir->SecBullPosDir.BulletID,
						lpSecBullPosDir->SecBullPosDir.Group,
						&lpSecBullPosDir->SecBullPosDir.Pos,
						&lpSecBullPosDir->SecBullPosDir.Offset,
						&lpSecBullPosDir->SecBullPosDir.Dir,
						&lpSecBullPosDir->SecBullPosDir.UpVector,
						&lpSecBullPosDir->SecBullPosDir.DropDir,
						lpSecBullPosDir->SecBullPosDir.Weapon, FALSE );
		return;

    case MSG_TITANBITS:
   		lpTitanBits = (LPTITANBITSMSG)MsgPnt;
		for( Count = 0; Count < NUMTITANBITS; Count++ )
		{
			 i = InitOneSecBull( lpTitanBits->TitanBits.OwnerType,
								lpTitanBits->TitanBits.Owner,
								(uint16) ( Count + lpTitanBits->TitanBits.BulletID ),
								lpTitanBits->TitanBits.Group,
								&lpTitanBits->TitanBits.Pos,
								&lpTitanBits->TitanBits.Offset,
								&lpTitanBits->TitanBits.Directions[ Count ],
								&lpTitanBits->TitanBits.UpVector,
								&lpTitanBits->TitanBits.DropDir,
								lpTitanBits->TitanBits.Weapon, FALSE );
			 if( i != (uint16) -1 )
			 {
				 SecBulls[i].FramelagAddition = GlobalFramelagAddition;
			 }
		}
		return;

	// Someone is claiming to have hit me...
    case MSG_SHIPHIT:

   		lpShipHit = (LPSHIPHITMSG)MsgPnt;

		if( ( lpShipHit->You == WhoIAm ) &&	( lpShipHit->Deaths == Ships[WhoIAm].Deaths ) )
   		{
			lpShipHit->ShipHit.Point.x += Ships[ WhoIAm ].Object.Pos.x;
			lpShipHit->ShipHit.Point.y += Ships[ WhoIAm ].Object.Pos.y;
			lpShipHit->ShipHit.Point.z += Ships[ WhoIAm ].Object.Pos.z;

			if( ( Ships[ WhoIAm ].Object.Mode == NORMAL_MODE ) || ( Ships[ WhoIAm ].Object.Mode == DEATH_MODE ) )
			{
				if( Ships[ WhoIAm ].Object.Mode == DEATH_MODE )
				{
					lpShipHit->ShipHit.Recoil.x *= 0.1F;
					lpShipHit->ShipHit.Recoil.y *= 0.1F;
					lpShipHit->ShipHit.Recoil.z *= 0.1F;
					lpShipHit->ShipHit.Force *= 0.1F;
				}
				if( lpShipHit->ShipHit.OneOffExternalForce ) ForceExternalOneOff( WhoIAm, &lpShipHit->ShipHit.Recoil );
				else ForceExternal( WhoIAm, &lpShipHit->ShipHit.Recoil );
				if( lpShipHit->ShipHit.Force )
				{
					RotateExternal( WhoIAm, &lpShipHit->ShipHit.Point, &lpShipHit->ShipHit.Dir, lpShipHit->ShipHit.Force );
				}
			}
			if( Ships[ WhoIAm ].Object.Mode == NORMAL_MODE )
			{
				if( ( lpShipHit->ShipHit.WeaponType == WEPTYPE_Secondary ) &&
					( lpShipHit->ShipHit.Weapon == SCATTERMISSILE ) )
				{
					switch( ColPerspective )
					{
						case COLPERS_Forsaken:
						case COLPERS_Server:
							if( !GodMode )
							{
								if( IsServerGame )
								{
									ExplodeShip( WhoIAm );
									ShortScatterWeapons();
								}
								else
								{
									ScatterWeapons( &NullVector, MAXSCATTERED );
								}
								PlayPannedSfx( SFX_Scattered, Ships[ WhoIAm ].Object.Group , &Ships[ WhoIAm ].Object.Pos, 0.0F );
								if( !bSoundEnabled ) AddMessageToQue( YOUVE_BEEN_SCATTERED );
							}
							break;

						case COLPERS_Descent:
							break;

					}
				}

   				if( Random_Range( 16 ) )
   				{
					PlayPannedSfx( SFX_ShipHit, Ships[ WhoIAm ].Object.Group , &lpShipHit->ShipHit.Point, 0.0F );
				}else{
   					PlaySfx( SFX_BikerPain , 1.0F );
   				}

				Ships[WhoIAm].ShipThatLastHitMe = lpShipHit->WhoHitYou;
   				Ships[WhoIAm].Damage = lpShipHit->ShipHit.Damage;

   				// do the damage...
   				if ( DoDamage( DONT_OVERRIDE_INVUL ) == 1 )
   				{
					// if I died...
   					Ships[WhoIAm].ShipThatLastKilledMe = lpShipHit->WhoHitYou;
   					Ships[WhoIAm].Object.Mode = DEATH_MODE;
   					Ships[WhoIAm].Timer = 0.0F;
   					// make a note of who killed who...
					Stats[Ships[WhoIAm].ShipThatLastKilledMe][WhoIAm]++;
   					// print up who killed me

					GetDeathString( lpShipHit->ShipHit.WeaponType, lpShipHit->ShipHit.Weapon, &methodstr[0] );

					if (TeamGame && ( TeamNumber[Ships[WhoIAm].ShipThatLastKilledMe] == TeamNumber[WhoIAm]))
						strcpy(&teamstr[0], FROM_YOUR_OWN_TEAM );
					else
						strcpy(&teamstr[0], "");

   					sprintf( (char*)&tempstr[0] ,"%s %s %s %s", &Names[Ships[WhoIAm].ShipThatLastKilledMe][0], &methodstr[0], YOU ,&teamstr );
   					AddMessageToQue( (char*)&tempstr[0] );
					ShipDiedSend( lpShipHit->ShipHit.WeaponType, lpShipHit->ShipHit.Weapon );
   				}
			}
   		}
   		return;

	// Someone is claiming to have hit me...
    case MSG_SHORTSHIPHIT:
		
   		lpShortShipHit = (LPSHORTSHIPHITMSG)MsgPnt;

		if( ( lpShortShipHit->You == WhoIAm ) &&	( lpShortShipHit->Deaths == Ships[WhoIAm].Deaths ) )
   		{
			Point.x = lpShortShipHit->ShipHit.Point.x + Ships[ WhoIAm ].Object.Pos.x;
			Point.y = lpShortShipHit->ShipHit.Point.y + Ships[ WhoIAm ].Object.Pos.y;
			Point.z = lpShortShipHit->ShipHit.Point.z + Ships[ WhoIAm ].Object.Pos.z;
			Recoil.x = (lpShortShipHit->ShipHit.Recoil.x * ONEOVER32767) * (lpShortShipHit->ShipHit.Recoil_Scalar * ONEOVER256 );
			Recoil.y = (lpShortShipHit->ShipHit.Recoil.y * ONEOVER32767) * (lpShortShipHit->ShipHit.Recoil_Scalar * ONEOVER256 );
			Recoil.z = (lpShortShipHit->ShipHit.Recoil.z * ONEOVER32767) * (lpShortShipHit->ShipHit.Recoil_Scalar * ONEOVER256 ); 
			Force = lpShortShipHit->ShipHit.Force;
			Dir.x = (float)(lpShortShipHit->ShipHit.Dir.x * ONEOVER32767);
			Dir.y = (float)(lpShortShipHit->ShipHit.Dir.y * ONEOVER32767);
			Dir.z = (float)(lpShortShipHit->ShipHit.Dir.z * ONEOVER32767);

			if( ( Ships[ WhoIAm ].Object.Mode == NORMAL_MODE ) || ( Ships[ WhoIAm ].Object.Mode == DEATH_MODE ) )
			{
				if( Ships[ WhoIAm ].Object.Mode == DEATH_MODE )
				{
					Recoil.x *= 0.1F;
					Recoil.y *= 0.1F;
					Recoil.z *= 0.1F;
					Force *= 0.1F;
				}
				if( lpShortShipHit->ShipHit.OneOffExternalForce != 0 ) ForceExternalOneOff( WhoIAm, &Recoil );
				else ForceExternal( WhoIAm, &Recoil );
				if( Force )
				{
					RotateExternal( WhoIAm, &Point, &Dir, Force );
				}
			}
			if( Ships[ WhoIAm ].Object.Mode == NORMAL_MODE )
			{
				if( ( lpShortShipHit->ShipHit.WeaponType == WEPTYPE_Secondary ) &&
					( lpShortShipHit->ShipHit.Weapon == SCATTERMISSILE ) )
				{
					switch( ColPerspective )
					{
						case COLPERS_Server:
						case COLPERS_Forsaken:
							if( !GodMode )
							{
								if( IsServerGame )
								{
									ExplodeShip( WhoIAm );
									ShortScatterWeapons();
								}
								else
								{
									ScatterWeapons( &NullVector, MAXSCATTERED );
								}

								PlayPannedSfx( SFX_Scattered, Ships[ WhoIAm ].Object.Group , &Ships[ WhoIAm ].Object.Pos, 0.0F );
								if( !bSoundEnabled ) AddMessageToQue( YOUVE_BEEN_SCATTERED );
							}
							break;

						case COLPERS_Descent:
							break;
					}
				}

   				if( Random_Range( 16 ) )
   				{
					PlayPannedSfx( SFX_ShipHit, Ships[ WhoIAm ].Object.Group , &Point, 0.0F );
				}else{
   					PlaySfx( SFX_BikerPain , 1.0F );
   				}

				Ships[WhoIAm].ShipThatLastHitMe = lpShortShipHit->WhoHitYou;
   				Ships[WhoIAm].Damage = lpShortShipHit->ShipHit.Damage;

   				// do the damage...
   				if ( DoDamage( DONT_OVERRIDE_INVUL ) == 1 )
   				{
					// if I died...
   					Ships[WhoIAm].ShipThatLastKilledMe = lpShortShipHit->WhoHitYou;
   					Ships[WhoIAm].Object.Mode = DEATH_MODE;
   					Ships[WhoIAm].Timer = 0.0F;
   					// make a note of who killed who...
					Stats[Ships[WhoIAm].ShipThatLastKilledMe][WhoIAm]++;
   					// print up who killed me

					GetDeathString( lpShortShipHit->ShipHit.WeaponType, lpShortShipHit->ShipHit.Weapon, &methodstr[0] );

					if (TeamGame && ( TeamNumber[Ships[WhoIAm].ShipThatLastKilledMe] == TeamNumber[WhoIAm]))
						strcpy(&teamstr[0], FROM_YOUR_OWN_TEAM );
					else
						strcpy(&teamstr[0], "");

   					sprintf( (char*)&tempstr[0] ,"%s %s %s %s", &Names[Ships[WhoIAm].ShipThatLastKilledMe][0], &methodstr[0], YOU ,&teamstr );
   					AddMessageToQue( (char*)&tempstr[0] );
					ShipDiedSend( lpShortShipHit->ShipHit.WeaponType, lpShortShipHit->ShipHit.Weapon );
   				}
			}
   		}
   		return;

	// Someone has Died....Did I kill Them ??
    case MSG_SHIPDIED:

		lpShipDied = (LPSHIPDIEDMSG)MsgPnt;

		if( IsServer )
		{
			CanDoDamage[lpShipDied->WhoIAm] = TRUE;
		}

   		// make a note of who killed who...
   		Stats[lpShipDied->WhoKilledMe][lpShipDied->WhoIAm]++;
#if 1
		if( lpShipDied->WeaponType == WEPTYPE_Primary )
		{
			PrimaryStats[lpShipDied->Weapon]++;
		}
		if( lpShipDied->WeaponType == WEPTYPE_Secondary )
		{
			SecondaryStats[lpShipDied->Weapon]++;
		}
#endif		

		if( BombTag )
		{
			sprintf( (char*) &tempstr[0] ,"%s %s", &Names[lpShipDied->WhoIAm][0] ,GOT_CAUGHT_WITH_A_BOMB);
			AddMessageToQue( (char*)&tempstr[0] );
			if( !GodMode )
				Ships[WhoIAm].Kills++;
		}else{
			
			GetDeathString( lpShipDied->WeaponType, lpShipDied->Weapon, &methodstr[0] );
			
   			if( WhoIAm == lpShipDied->WhoKilledMe )
   			{
   				// me I did it ha ha..
				if( TeamGame )
				{
					//if they were on my side
					if( TeamNumber[lpShipDied->WhoIAm] == TeamNumber[WhoIAm] )
					{
						if( !GodMode )
						{
							AddMessageToQue( "%s %s %s %s", YOU ,&methodstr[0], &Names[lpShipDied->WhoIAm][0] ,ON_YOUR_OWN_TEAM );
							Ships[WhoIAm].Deaths++;
						}
					}
					else
					{
						if ( BountyHunt )
						{
							if ( ( Ships[ WhoIAm ].Object.Flags | Ships[ lpShipDied->WhoIAm ].Object.Flags ) & SHIP_CarryingBounty )
							{
								if ( Ships[ lpShipDied->WhoIAm ].Object.Flags & SHIP_CarryingBounty )
									AddMessageToQue( "%s %s %s %s", YOU , &methodstr[0], &Names[lpShipDied->WhoIAm][0] , WITH_THE_BOUNTY );
								else
									AddMessageToQue( "%s %s %s", YOU , &methodstr[0] , &Names[lpShipDied->WhoIAm][0] );
								PlaySfx( SFX_BIKER_VP, 1.0F );
								Ships[WhoIAm].Kills++;
								AddKill();
							}
							else
							{
								AddMessageToQue( NO_POINTS_FOR_KILLING_PLAYER_WITHOUT_THE_BOUNTY,
									Names[ lpShipDied->WhoIAm ] );
							}
						}
						else if( !GodMode )
						{
							AddMessageToQue( "%s %s %s", YOU , &methodstr[0], &Names[lpShipDied->WhoIAm][0] );
							Ships[WhoIAm].Kills++;
							AddKill();
							if ( !Random_Range( 4 ) )
								PlaySfx( SFX_BIKER_VP, 1.0F );
						}
					}
				}
				else
				{
					if ( BountyHunt )
					{
						if ( ( Ships[ WhoIAm ].Object.Flags | Ships[ lpShipDied->WhoIAm ].Object.Flags ) & SHIP_CarryingBounty )
						{
							if ( Ships[ lpShipDied->WhoIAm ].Object.Flags & SHIP_CarryingBounty )
								AddMessageToQue( "%s %s %s %s", YOU , &methodstr[0], &Names[lpShipDied->WhoIAm][0], WITH_THE_BOUNTY );
							else
								AddMessageToQue( "%s %s %s", YOU , &methodstr[0], &Names[lpShipDied->WhoIAm][0] );
							PlaySfx( SFX_BIKER_VP, 1.0F );
							Ships[WhoIAm].Kills++;
							AddKill();
						}
						else
						{
							AddMessageToQue( NO_POINTS_FOR_KILLING_PLAYER_WITHOUT_THE_BOUNTY,
								Names[ lpShipDied->WhoIAm ] );
						}
					}
					else if( !GodMode )
					{
	   					AddMessageToQue( "%s %s %s", YOU , &methodstr[0], &Names[lpShipDied->WhoIAm][0] );
						Ships[WhoIAm].Kills++;
						AddKill();
						if ( !Random_Range( 4 ) )
							PlaySfx( SFX_BIKER_VP, 1.0F );
					}
				}
			
			}
			else
			{
// ships now keep check of their individual scores during team game, not team scores as before....
/*
				// is it a team game
				if( TeamGame )
				{

					//if they were on my side
					if( TeamNumber[lpShipDied->WhoIAm] == TeamNumber[WhoIAm] )
					{
						// one of us got killed...
						Ships[WhoIAm].Deaths++;
					}
					else{
						if( !GodMode )
							Ships[WhoIAm].Kills++;
					}

				}
*/
				
				if( lpShipDied->WhoIAm == lpShipDied->WhoKilledMe )
   				{
   					// gee someone killed themselves...
   					sprintf( (char*) &tempstr[0] ,"%s %s %s", &Names[lpShipDied->WhoIAm][0], &methodstr[0] , HIMSELF);
   					AddMessageToQue( (char*)&tempstr[0] );
			
   				}
				else
				{
   					if (TeamGame && (TeamNumber[lpShipDied->WhoIAm] == TeamNumber[lpShipDied->WhoKilledMe]))
						strcpy (&teamstr[0], ON_HIS_OWN_TEAM);
					else
						strcpy (&teamstr[0], "");

					// gee someone killed somebody...who cares...
   					sprintf( (char*) &tempstr[0] ,"%s %s %s %s", &Names[lpShipDied->WhoKilledMe][0], &methodstr[0], &Names[lpShipDied->WhoIAm][0], &teamstr );
   					AddMessageToQue( (char*)&tempstr[0] );
   				}
   			}
		}

		return;
    case MSG_SHORTSTATS:
   		lpShortStats = (LPSHORTSTATSMSG)MsgPnt;
   		memcpy( (void*) &Stats[lpShortStats->WhosStats][0] , (void*) lpShortStats->ShortStats , sizeof(SHORTSTATSTYPE) );
   		if( lpShortStats->WhosStats == 0 )
   		{
   			StatsStatus = 1;
   		}
   		return;
/*�������������������������������������������������������������������
	This is where the host gets told what state he thinks we are in
�������������������������������������������������������������������*/

    case MSG_STATUS:
   		lpStatus = (LPSTATUSMSG)MsgPnt;

		if( ( GameStatus[lpStatus->WhoIAm] != STATUS_Normal) && (lpStatus->Status == STATUS_Normal ) ) 
		{
			CreateReGen( lpStatus->WhoIAm );
		}

		//DebugPrintf("setting status for player %d to %x\n", lpStatus->WhoIAm, lpStatus->Status );

		GameStatus[lpStatus->WhoIAm] = lpStatus->Status;

		if( GameStatus[lpStatus->WhoIAm] == STATUS_Left )
		{
			// This player has quit...
			Ships[lpStatus->WhoIAm].enable = 0;
			Ships[lpStatus->WhoIAm].Pickups		= 0;
			Ships[lpStatus->WhoIAm].RegenSlots	= 0;
			Ships[lpStatus->WhoIAm].Mines		= 0;
			Ships[lpStatus->WhoIAm].Triggers	= 0;
			Ships[lpStatus->WhoIAm].TrigVars	= 0;
			FreeAllPlayersAcknowledgeMessageQue( lpStatus->WhoIAm );

			if ( lpStatus->TeamScore )
			{
				// give score to lowest player number on same team
	  			for( i = 0; i < MAX_PLAYERS; i++ )
				{
					if ( ( TeamNumber[ i ] < MAX_TEAMS ) && (( GameStatus[ i ] != STATUS_Left ) && ( GameStatus[ i ] != STATUS_LeftCrashed )) )	
					{
						if( TeamNumber[ i ] == TeamNumber[ lpStatus->WhoIAm ] )
						{
							Ships[ i ].Kills += lpStatus->TeamScore;
							break;
						}
					}
				}
			}

		}else{
	//		DebugPrintf("%s status = %d\n", Names[lpStatus->WhoIAm], GameStatus[lpStatus->WhoIAm] );

			Ships[lpStatus->WhoIAm].Pickups		= lpStatus->Pickups;
			Ships[lpStatus->WhoIAm].RegenSlots	= lpStatus->RegenSlots;
			Ships[lpStatus->WhoIAm].Mines		= lpStatus->Mines;
			Ships[lpStatus->WhoIAm].Triggers	= lpStatus->Triggers;
			Ships[lpStatus->WhoIAm].TrigVars	= lpStatus->TrigVars;

			if( !IsHost )
   			{
   				if( lpStatus->IsHost )
   				{
					BYTE tempstatus;
					Ships[lpStatus->WhoIAm].Object.Flags |= SHIP_IsHost;
					
					if( MyGameStatus == STATUS_Normal )
					{
						if( DPlayUpdateInterval != lpStatus->PacketsPerSecond )
						{
							AddMessageToQue( "%2.2f %s" , ( 60.0F / lpStatus->PacketsPerSecond ) , PACKETS_PER_SECOND_SET );
						}
					}
					DPlayUpdateInterval = lpStatus->PacketsPerSecond;
					PacketsSlider.value = (int) (60.0F / DPlayUpdateInterval);
					// its a status change from the Host...
					tempstatus = OverallGameStatus;
   					OverallGameStatus = lpStatus->Status;
					if ( tempstatus != OverallGameStatus )
					{
						DebugPrintf("Setting overall game status to %x\n", lpStatus->Status );
					}
				}
   			}

			TeamNumber[lpStatus->WhoIAm] = lpStatus->TeamNumber;
			PlayerReady[lpStatus->WhoIAm] = lpStatus->IAmReady;

			if( !PlayDemo )
			{
				if( CheckForName( lpStatus->WhoIAm ) )
				{
					if( RecordDemo )
					{
						// Best way I can Think of to send the names to the demo file...
						TempTime = 1;
						Demo_fwrite( &TempTime, sizeof(LONGLONG), 1, DemoFp );
						size = sizeof( NAMEMSG );
						Demo_fwrite( &size, sizeof(int), 1, DemoFp );
						Demo_fwrite( &dcoID, sizeof(DPID), 1, DemoFp );
						msg = MSG_NAME;
						Demo_fwrite( &msg, sizeof(BYTE), 1, DemoFp );
						Demo_fwrite( &lpStatus->WhoIAm, sizeof(BYTE), 1, DemoFp );
						Demo_fwrite( &Names[lpStatus->WhoIAm][0], 8, 1, DemoFp );
					}
				}
			}
		}
		if( IsHost )
		{
			// Check they are playing the same version of the level....
			if( ( MyGameStatus == STATUS_StartingMultiplayerSynch && lpStatus->Status == STATUS_StartingMultiplayerSynch ) || 
				( MyGameStatus == STATUS_Normal && lpStatus->Status == STATUS_Joining ) || 
				( MyGameStatus == STATUS_WaitingAfterScore && lpStatus->Status == STATUS_WaitingAfterScore ) )
			{

				if( lpStatus->LevelCheckSum	!= LevelCheckSum )
				{
					// They have the wrong version of the current level.....Kick em.....
#ifdef DIRECTPLAY_KICK_PLAYER
					IDirectPlayX_DestroyPlayer( glpDP , from_dcoID );
#else
					SendGameMessage(MSG_YOUQUIT, 0, lpStatus->WhoIAm, 0, 0);
#endif
				}
			}
		}



		return;
    case MSG_LONGSTATUS:
   		lpLongStatus = (LPLONGSTATUSMSG)MsgPnt;

		if( ( GameStatus[lpLongStatus->Status.WhoIAm] != STATUS_Normal) && (lpLongStatus->Status.Status == STATUS_Normal ) ) 
		{
			CreateReGen( lpLongStatus->Status.WhoIAm );
		}
		GameStatus[lpLongStatus->Status.WhoIAm] = lpLongStatus->Status.Status;
		DebugPrintf("%s LongStatus = %d\n", Names[lpLongStatus->Status.WhoIAm], GameStatus[lpLongStatus->Status.WhoIAm] );
		Ships[lpLongStatus->Status.WhoIAm].Pickups		= lpLongStatus->Status.Pickups;
		Ships[lpLongStatus->Status.WhoIAm].RegenSlots	= lpLongStatus->Status.RegenSlots;
		Ships[lpLongStatus->Status.WhoIAm].Mines		= lpLongStatus->Status.Mines;
		Ships[lpLongStatus->Status.WhoIAm].Triggers	= lpLongStatus->Status.Triggers;
		Ships[lpLongStatus->Status.WhoIAm].TrigVars	= lpLongStatus->Status.TrigVars;
		
		if( !IsHost )
   		{
   			if( lpLongStatus->Status.IsHost )
   			{
				RandomStartPosModify = lpLongStatus->RandomStartPosModify;
				Ships[lpLongStatus->WhoIAm].Object.Flags |= SHIP_IsHost;

		
				NewLevelNum = FindSameLevel( &lpLongStatus->LevelName[0] );
				if( NewLevelNum == -1 )
				{
					char buf[ 128 ];

					sprintf( buf, DID_NOT_HAVE_LEVEL /*"you did not have the level chosen by the host ( %s )"*/,
						lpLongStatus->LevelName );
					SetTitleNotify( buf );
					SpecialDestroyGame();
					return;
				}
				LevelList.selected_item = NewLevelNum;
				if( MyGameStatus == STATUS_Normal )
				{
					if( DPlayUpdateInterval != lpLongStatus->Status.PacketsPerSecond )
					{
						 AddMessageToQue( "%2.2f %s" , ( 60.0F / lpLongStatus->Status.PacketsPerSecond ) , PACKETS_PER_SECOND_SET );
					}
				}
				DPlayUpdateInterval = lpLongStatus->Status.PacketsPerSecond;
				PacketsSlider.value = (int) (60.0F / DPlayUpdateInterval);
				// its a status change from the Host...
   				OverallGameStatus = lpLongStatus->Status.Status;
			}
   		}
		TeamNumber[lpLongStatus->Status.WhoIAm] = lpLongStatus->Status.TeamNumber;
		PlayerReady[lpLongStatus->Status.WhoIAm] = lpLongStatus->Status.IAmReady;

		if( !PlayDemo )
		{
			if( CheckForName( lpLongStatus->Status.WhoIAm ) )
			{
				if( RecordDemo )
				{
					// Best way I can Think of to send the names to the demo file...
					TempTime = 1;
					Demo_fwrite( &TempTime, sizeof(LONGLONG), 1, DemoFp );
					size = sizeof( NAMEMSG );
					Demo_fwrite( &size, sizeof(int), 1, DemoFp );
					Demo_fwrite( &dcoID, sizeof(DPID), 1, DemoFp );
					msg = MSG_NAME;
					Demo_fwrite( &msg, sizeof(BYTE), 1, DemoFp );
					Demo_fwrite( &lpLongStatus->Status.WhoIAm, sizeof(BYTE), 1, DemoFp );
					Demo_fwrite( &Names[lpLongStatus->Status.WhoIAm][0], 8, 1, DemoFp );
				}
			}
		}
		return;
    case MSG_SHORTPICKUP:
   		lpShortPickup = (LPSHORTPICKUPMSG)MsgPnt;
   		if( lpShortPickup->Pickups == Ships[WhoIAm].Pickups )
   		{
#if DEBUG_PICKUPS
			DebugPrintf( "Message from host to init pickups\n" );
#endif

			if( lpShortPickup->HowManyPickups != 0 )
			{
				Ships[WhoIAm].Pickups -= 1;
				RegenPickupList( &lpShortPickup->ShortPickup[0] , lpShortPickup->HowManyPickups );
			}
			else
			{
				Ships[WhoIAm].Pickups = 0;
			}
		}
		return;

    case MSG_SHORTREGENSLOT:
		lpShortRegenSlot = (LPSHORTREGENSLOTMSG)MsgPnt;
   		if( lpShortRegenSlot->RegenSlots == Ships[WhoIAm].RegenSlots )
   		{
#if DEBUG_PICKUPS
			DebugPrintf( "Message from host to init regenslots\n" );
#endif
			if( lpShortRegenSlot->HowManyRegenSlots != 0 )
			{
				Ships[WhoIAm].RegenSlots -= 1;
				RegenRegenSlotList( &lpShortRegenSlot->ShortRegenSlot[0] , lpShortRegenSlot->HowManyRegenSlots );
			}
			else
			{
				Ships[WhoIAm].RegenSlots = 0;
			}
		}
		return;

    case MSG_SHORTTRIGGER:
		lpShortTrigger = (LPSHORTTRIGGERMSG)MsgPnt;
   		if( lpShortTrigger->Triggers == Ships[WhoIAm].Triggers )
   		{
			if( lpShortTrigger->HowManyTriggers != 0 )
			{
				Ships[WhoIAm].Triggers -= 1;
				RegenTriggerList( &lpShortTrigger->ShortTrigger[0] , lpShortTrigger->HowManyTriggers );
			}
			else
			{
				Ships[WhoIAm].Triggers -= 1;
			}
		}
		return;

    case MSG_SHORTTRIGVAR:
		lpShortTrigVar = (LPSHORTTRIGVARMSG)MsgPnt;
   		if( lpShortTrigVar->TrigVars == Ships[WhoIAm].TrigVars )
   		{
			if( lpShortTrigVar->HowManyTrigVars != 0 )
			{
				Ships[WhoIAm].TrigVars -= 1;
				RegenTrigVarList( &lpShortTrigVar->ShortTrigVar[0] , lpShortTrigVar->HowManyTrigVars );
			}
			else
			{
				Ships[WhoIAm].TrigVars -= 1;
			}
		}
		return;

    case MSG_SHORTMINE:
   		lpShortMine = (LPSHORTMINEMSG)MsgPnt;
   		if( lpShortMine->Mines == Ships[WhoIAm].Mines )
   		{
			if( Ships[WhoIAm].Mines == ( ( MAXSECONDARYWEAPONBULLETS / MAXGENMINECOUNT	) + 1 ) )
			{
				QueryPerformanceCounter( (LARGE_INTEGER *) &Time_LastValue );
			}

  			DebugPrintf( "Message from host to init mines\n" );

			if( lpShortMine->HowManyMines != 0 )
			{
	   			Ships[WhoIAm].Mines -= 1;
	   			RegenMineList( &lpShortMine->ShortMine[0] , lpShortMine->HowManyMines );
			}
			else
			{
				Ships[WhoIAm].Mines = 0;
			}
   		}
   		return;


    case MSG_TEXTMSG:
		lpTextMsg = (LPTEXTMSG)MsgPnt;
		switch (lpTextMsg->TextMsgType)
		{
		case TEXTMSGTYPE_QuickTauntWhisper:
			if( TeamNumber[WhoIAm] != TeamNumber[lpTextMsg->WhoIAm] )
				return;
		case TEXTMSGTYPE_Taunt1:
		case TEXTMSGTYPE_Taunt2:
		case TEXTMSGTYPE_Taunt3:
		case TEXTMSGTYPE_QuickTaunt:
			sprintf( (char*) &tempstr[0] ,"%s says %s", &Names[lpTextMsg->WhoIAm][0],  &lpTextMsg->Text[0] );
#if defined( SHAREWARE )
			if ( !PlayDemo )
				AddMessageToQue( (char*)&tempstr[0] );
#elif !defined( SELF_PLAY ) 
			AddMessageToQue( (char*)&tempstr[0] );
#endif
			return;
		case TEXTMSGTYPE_JoiningTeamGame:
			sprintf( (char*) &tempstr[0] ,"%s %s", &Names[lpTextMsg->WhoIAm][0] ,IS_JOINING_THE_GAME);
			AddMessageToQue( (char*)&tempstr[0] );
			return;
		case TEXTMSGTYPE_TitleMessage:
			AddTitleMessage(lpTextMsg);
			return;
		case TEXTMSGTYPE_CaptureFlagMessage:
//			sprintf( (char*) tempstr ,"%s on the %s team has got the flag", Names[ lpTextMsg->WhoIAm ], TeamName[ TeamNumber[ lpTextMsg->WhoIAm ] ] );
			AddMessageToQue( lpTextMsg->Text );
			if ( TeamNumber[ WhoIAm ] == TeamNumber[ lpTextMsg->WhoIAm ] )
				PlaySfx( SFX_MyTeamGotFlag, 1.0F );
			else
				PlaySfx( SFX_OtherTeamGotFlag , 1.0F );
			return;
		case TEXTMSGTYPE_ScoredWithFlag:
			sprintf( (char*) tempstr ,THE_COLOUR_TEAM_HAVE_SCORED, TeamName[ TeamNumber[ lpTextMsg->WhoIAm ] ] );
			AddMessageToQue( (char*)&tempstr[0] );
			if ( TeamNumber[ WhoIAm ] == TeamNumber[ lpTextMsg->WhoIAm ] )
				PlaySfx( SFX_MyTeamScored, 1.0F );
			else
				PlaySfx( SFX_OtherTeamScored , 1.0F );
			return;
		case TEXTMSGTYPE_ReturningFlag:
			if ( IsServerGame )
			{
				AddMessageToQue( lpTextMsg->Text );
			}
			else if ( lpTextMsg->WhoIAm != WhoIAm )
			{
				sprintf( (char*) tempstr ,THE_COLOUR_TEAM_ARE_RETURNING_THEIR_FLAG,TeamName[ TeamNumber[ lpTextMsg->WhoIAm ] ]);
				AddMessageToQue( (char*)&tempstr[0] );
			}
			return;
		case TEXTMSGTYPE_ReturnedFlag:
			if ( IsServerGame )
			{
				AddMessageToQue( lpTextMsg->Text );
			}
			else
			{
				sprintf( (char*) tempstr ,THE_COLOUR_TEAM_FLAG_HAS_BEEN_RETURNED,TeamName[ TeamNumber[ lpTextMsg->WhoIAm ] ] );
				AddMessageToQue( (char*)&tempstr[0] );
			}
			return;
		case TEXTMSGTYPE_FlagDriftedIn:
			sprintf( (char*) tempstr ,THE_COLOUR_TEAM_FLAG_HAS_DRIFTED_INTO_THEIR_GOAL,TeamName[ TeamNumber[ lpTextMsg->WhoIAm ] ] );
			AddMessageToQue( (char*)&tempstr[0] );
			return;
		case TEXTMSGTYPE_FlagEscaped:
			sprintf( (char*) tempstr ,THE_COLOUR_TEAM_FLAG_HAS_ESCAPED_FROM_THEIR_GOAL, TeamName[ TeamNumber[ lpTextMsg->WhoIAm ] ] );
			AddMessageToQue( (char*)&tempstr[0] );
			return;
		case TEXTMSGTYPE_BountyMessage:
			sprintf( (char*) tempstr ,"%s %s", Names[ lpTextMsg->WhoIAm ] , HAS_GOT_THE_BOUNTY);
			AddMessageToQue( (char*)&tempstr[0] );
			PlaySfx( SFX_OtherTeamGotFlag, 1.0F );
			return;
		case TEXTMSGTYPE_SpeechTaunt:
			PlayRecievedSpeechTaunt( lpTextMsg->WhoIAm, lpTextMsg->Text[ 0 ] );
			return;
		}
		return;
    case MSG_INTERPOLATE:
		lpInterpolate = (LPINTERPOLATEMSG)MsgPnt;
		Ships[lpInterpolate->WhoIAm].OldPos = Ships[lpInterpolate->WhoIAm].Object.Pos;
		Ships[lpInterpolate->WhoIAm].NextPos = lpInterpolate->NextPos;
		Ships[lpInterpolate->WhoIAm].OldQuat = Ships[lpInterpolate->WhoIAm].Object.Quat;
		Ships[lpInterpolate->WhoIAm].NextQuat = lpInterpolate->NextQuat;
		Ships[lpInterpolate->WhoIAm].OldBank = Ships[lpInterpolate->WhoIAm].Object.Bank;
		Ships[lpInterpolate->WhoIAm].NextBank = lpInterpolate->NextBank;
//		Ships[lpInterpolate->WhoIAm].OldTime = GameElapsedTime;
		Ships[lpInterpolate->WhoIAm].OldTime = DemoTimeSoFar* FSB_COMPENSATION;
		Ships[lpInterpolate->WhoIAm].NextTime = lpInterpolate->NextTime * FSB_COMPENSATION;
		Ships[lpInterpolate->WhoIAm].DemoInterpolate = TRUE;
		return;
    case MSG_VERYSHORTINTERPOLATE:
		lpVeryShortInterpolate = (LPVERYSHORTINTERPOLATEMSG)MsgPnt;

		Ships[lpVeryShortInterpolate->WhoIAm].NextPos.x = (float) lpVeryShortInterpolate->NextPos.x;
		Ships[lpVeryShortInterpolate->WhoIAm].NextPos.y = (float) lpVeryShortInterpolate->NextPos.y;
		Ships[lpVeryShortInterpolate->WhoIAm].NextPos.z = (float) lpVeryShortInterpolate->NextPos.z;
		
		Ships[lpVeryShortInterpolate->WhoIAm].NextQuat.w = (float)(lpVeryShortInterpolate->NextQuat.w * ONEOVER32767 );
		Ships[lpVeryShortInterpolate->WhoIAm].NextQuat.x = (float)(lpVeryShortInterpolate->NextQuat.x * ONEOVER32767 );
		Ships[lpVeryShortInterpolate->WhoIAm].NextQuat.y = (float)(lpVeryShortInterpolate->NextQuat.y * ONEOVER32767 );
		Ships[lpVeryShortInterpolate->WhoIAm].NextQuat.z = (float)(lpVeryShortInterpolate->NextQuat.z * ONEOVER32767 );
		Ships[lpVeryShortInterpolate->WhoIAm].NextBank = (float) (lpVeryShortInterpolate->NextBank / SHORTBANKMODIFIER);
		
		Ships[lpVeryShortInterpolate->WhoIAm].NextTime = lpVeryShortInterpolate->NextTime * FSB_COMPENSATION;
		Ships[lpVeryShortInterpolate->WhoIAm].DemoInterpolate = TRUE;
		Ships[lpVeryShortInterpolate->WhoIAm].OldPos = Ships[lpVeryShortInterpolate->WhoIAm].Object.Pos;
		Ships[lpVeryShortInterpolate->WhoIAm].OldQuat = Ships[lpVeryShortInterpolate->WhoIAm].Object.Quat;
		Ships[lpVeryShortInterpolate->WhoIAm].OldBank = Ships[lpVeryShortInterpolate->WhoIAm].Object.Bank;
		Ships[lpVeryShortInterpolate->WhoIAm].OldTime = DemoTimeSoFar* FSB_COMPENSATION;
		return;


    case MSG_BOMB:
		lpBomb = (LPBOMBMSG)MsgPnt;
		if( lpBomb->WhoGotHit == WhoIAm )
		{
			// ahhh Ive got a fresh bomb....
			AddMessageToQue( YOU_HAVE_GOT_A_NEW_BOMB );
			BombActive[lpBomb->BombNum] = TRUE;
			BombTime[lpBomb->BombNum] = lpBomb->BombTime;
		}
		return;
    case MSG_PINGREQUEST:
		lpPingMsg = (LPPINGMSG)MsgPnt;
		PingRequestTime = lpPingMsg->Time;
		if( BigPackets )
		{
			QueryPerformanceCounter((LARGE_INTEGER *) &TimeFrig);
			PingRequestTime += LastBigPacketSent - TimeFrig;
		}
		SendGameMessage(MSG_PINGREPLY, 0, 0 , lpPingMsg->WhoIAm , 0);
		return;
	case MSG_PLAYERPINGS:
		lpPlayerPingsMsg = (LPPLAYERPINGSMSG)MsgPnt;
		memcpy( PingTimes, lpPlayerPingsMsg->Ping, sizeof( PingTimes ) ); 
		return;
    case MSG_PINGREPLY:
		lpPingMsg = (LPPINGMSG)MsgPnt;
		if( lpPingMsg->ToYou == WhoIAm )
		{
			QueryPerformanceCounter( (LARGE_INTEGER *) &TempLongLong );
			PingTimes[lpPingMsg->WhoIAm] = (uint16) (((TempLongLong - lpPingMsg->Time) * 1000 ) / Freq);
		}
		return;

    case MSG_SETTIME:
		lpSetTime = (LPSETTIMEMSG)MsgPnt;
		if( IllegalTime )
		{
			Countdown_Float = lpSetTime->TimeInfo.Time;
			IllegalTime = FALSE;
		}
		return;
    case MSG_REQTIME:
		lpReqTime = (LPREQTIMEMSG)MsgPnt;
		if( IsHost )
		{
			SetTime( Countdown_Float );
		}
		return;
    case MSG_ACKMSG:
		lpAckMsg = (LPACKMSG)MsgPnt;
		if( lpAckMsg->AckTo == WhoIAm )
		{
//			if( IsServerGame && !IsServer )
//			{
//				sprintf( &dBuf[0] , "Recieved an ACKMSG from %d\n" , lpAckMsg->WhoIAm );
//				Msg( &dBuf[0] );
//			}

			AcknowledgeMessage( lpAckMsg->ID , 1 << lpAckMsg->WhoIAm , lpAckMsg->WhoIAm );
		}
		return;
    case MSG_KILLSDEATHSBIKENUM:
		lpKillsDeathsMsg = (LPKILLSDEATHSBIKENUMMSG)MsgPnt;
		Ships[lpKillsDeathsMsg->WhoIAm].Kills = lpKillsDeathsMsg->Kills;
		Ships[lpKillsDeathsMsg->WhoIAm].Deaths = lpKillsDeathsMsg->Deaths;

#if defined( SELF_PLAY ) || defined (ECTS)
		// force player to use different bike based on his player number
		Ships[lpKillsDeathsMsg->WhoIAm].BikeNum		= (int16) AllowedBike[ lpKillsDeathsMsg->WhoIAm % MAXBIKETYPES ];
#elif defined( SHAREWARE )
		if ( PlayDemo )
		{
			// force player to use different bike based on his player number
			Ships[lpKillsDeathsMsg->WhoIAm].BikeNum		= (int16) AllowedBike[ lpKillsDeathsMsg->WhoIAm % ALLOWED_BIKETYPES ];
		}
		else
		{
			Ships[lpKillsDeathsMsg->WhoIAm].BikeNum		= (int16) lpKillsDeathsMsg->BikeNum;
		}
#else
	  	if( PlayDemo )
		{
			// if we are playing end game demo, we want to substitute the displayed bike for the players bike
			switch( GameCompleted )
			{
			case GAMECOMPLETE_WithoutAllCrystals:
			case GAMECOMPLETE_WithAllCrystalsExceptLast:
				Ships[lpKillsDeathsMsg->WhoIAm].BikeNum = player_config->bike;
				break;
			default:
				Ships[lpKillsDeathsMsg->WhoIAm].BikeNum		= (int16) lpKillsDeathsMsg->BikeNum;
			}
		}else
		{
			Ships[lpKillsDeathsMsg->WhoIAm].BikeNum		= (int16) lpKillsDeathsMsg->BikeNum;
		}
#endif
		return;
	case MSG_GAMEPARAMETERS:
		lpGameParamMsg = ( LPGAMEPARAMETERSMSG )MsgPnt;
						 
		if ( IsHost )
		{
			DPlayGetSessionDesc();

			// if pseudohost has quit b4 game params recieved, ignore message
			for ( i = 0; i < MAX_PLAYERS; i++ )
			{
				if ( PseudoHostDPID == PlayerIDs[ i ] ) 
				{
					switch( GameStatus[ i ] )
					{
					case STATUS_Null:
					case STATUS_Left:
					case STATUS_LeftCrashed:
						return;
					}
				}
			}

			// set all relevent game variables

			LevelList.selected_item = -1;
			for( i = 0; i < LevelList.items; i++ )
			{
				if ( !_strnicmp( lpGameParamMsg->Level, LevelList.item[ i ], 7 ) ) 
				{
					LevelList.selected_item = i;
					NewLevelNum = i;
					break;
				}
			}
			if ( LevelList.selected_item < 0 )
			{
				// server does not have chosen level!!!
				Msg("invalid level!!\n");
				return;
			}

	 		// store full level name in session desc
			GetLevelName( full_level_name, MAX_LEVEL_NAME_LENGTH, LevelList.selected_item );
			StoreLevelNameInSessionDesc( full_level_name );

			MaxKillsSlider.value = lpGameParamMsg->ScoreLimit;
			MaxKills = lpGameParamMsg->ScoreLimit;
			TimeLimit.value = lpGameParamMsg->TimeLimit;
			if( TimeLimit.value )
			{
				CountDownOn = TRUE;
			}
			else
			{
				CountDownOn = FALSE;
			}

			GameType = ( ( lpGameParamMsg->GameInfo & GAMEPARAM_GameTypeBits ) >> GAMEPARAM_GameTypeBitShift );

			CTFSlider.value = ( ( lpGameParamMsg->GameInfo & GAMEPARAM_CTFTypeBits ) >> GAMEPARAM_CTFTypeBitShift );

			SetUpGameType( GameType );

			ResetKillsPerLevel = ( lpGameParamMsg->GameInfo & GAMEPARAM_ResetKillsPerLevelBit );

			BikeExhausts = ( lpGameParamMsg->GameInfo & GAMEPARAM_BikeExhaustBit );
			MyBrightShips = ( lpGameParamMsg->GameInfo & GAMEPARAM_BrightBikesBit );
			RandomPickups = ( lpGameParamMsg->GameInfo & GAMEPARAM_RandomisePickupsBit );
			BountyBonus = ( lpGameParamMsg->GameInfo & GAMEPARAM_BountyBonusBit );
			BountyBonusInterval = BountyBonusSlider.value = ( ( ( lpGameParamMsg->GameInfo & GAMEPARAM_BountyBonusValueBits ) >> GAMEPARAM_BountyBonusValueBitShift ) * 5 );
			HarmTeamMates = ( lpGameParamMsg->GameInfo & GAMEPARAM_HarmTeamMatesBit );

			ColPerspective = ( lpGameParamMsg->GameInfo & GAMEPARAM_LagCompensationBits ) >> GAMEPARAM_LagCompensationBitShift;

			GoalScoreSlider.value = ( ( lpGameParamMsg->GameInfo & GAMEPARAM_FlagCaptureScoreBits ) >> GAMEPARAM_FlagCaptureScoreBitShift );

			ServerCollisions = ( lpGameParamMsg->GameInfo & GAMEPARAM_ServerCollisionBit );

			UnpackPickupInfo( lpGameParamMsg->AllowedPickups );

			NumPrimaryPickups = lpGameParamMsg->PrimaryPickups;

			// update user fields in session desc
			StoreSessionUserFields( glpdpSD );

			// update server status in session description
			glpdpSD->dwUser3 &= ~ServerGameStateBits;	// mask out old server state
			glpdpSD->dwUser3 |=	SERVER_STATE_Joinable;

			/*
			// set max_players to true amount
			glpdpSD->dwMaxPlayers = MaxPlayersSlider.max;
			*/

			// set max_players to required amount
			glpdpSD->dwMaxPlayers = lpGameParamMsg->MaxPlayers + 1;	// extra player is server

			DPlaySetSessionDesc(0);

			if ( TeamGame )
			{
				// change menu ( viewing team selection )
				MenuChangeEx( &MENU_NEW_WatchTeamSelect );
			}else
			{
				// change menu ( 'waiting for host to start game' )
				MenuChangeEx( &MENU_NEW_ServerWaitingToStartGame );
			}
		}

		return;
#ifdef MANUAL_SESSIONDESC_PROPAGATE
	case MSG_SESSIONDESC:
		DebugPrintf("about to evaluate session desc packet\n");
		lpSessionDescMsg = ( LPSESSIONDESCMSG )MsgPnt;
		if ( !IsHost )
		{
            if ( glpdpSD_copy )
			{
				free ( glpdpSD_copy );
				glpdpSD_copy = NULL;
			}
			
			DPlayGetSessionDesc();

			glpdpSD_copy = (LPDPSESSIONDESC2) malloc( sizeof( *glpdpSD_copy ) );
			if ( glpdpSD_copy )
			{
				*glpdpSD_copy = *glpdpSD;
				glpdpSD_copy->dwUser1 = lpSessionDescMsg->dwUser1;
				glpdpSD_copy->dwUser2 = lpSessionDescMsg->dwUser2;
				glpdpSD_copy->dwUser3 = lpSessionDescMsg->dwUser3;
				glpdpSD_copy->dwUser4 = lpSessionDescMsg->dwUser4;
			}
		}
		return;
#endif
	case MSG_TOSERVER:
		if ( IsServer )
		{
			lpToServerMsg = ( LPTOSERVERMSG )MsgPnt;

			switch( lpToServerMsg->Type )
			{
			case TOSERVERMSG_StartGame:
				MyGameStatus = STATUS_WaitingToStartMultiPlayerHost;
				MenuChangeEx( &MENU_NEW_GeneralLoading );
				break;
			case TOSERVERMSG_Reset:
				// destroy session

				// go back to correct waiting state ( which will recreate session )

				DPlayGetSessionDesc();
				glpdpSD->dwUser3 &= ~ServerGameStateBits;	// mask out old server state
				glpdpSD->dwUser3 |=	SERVER_STATE_NeedHost;
				DebugPrintf("server - about to change state to HostChoosing\n");
				DPlaySetSessionDesc(0);

				MenuBackSpecific( &MENU_NEW_HostWaitingToStartServer, TRUE );

//				GetServiceProviders( NULL );

				break;
			case TOSERVERMSG_ChangeLevel:
				LevelList.selected_item = lpToServerMsg->Data;
				NewLevelNum = lpToServerMsg->Data;
				break;
			case TOSERVERMSG_IAmPseudoHost:
				PseudoHostDPID = from_dcoID;
				break;
			}
		}

		return;
	case MSG_TOCLIENT:
		if ( !IsHost )
		{
			lpToClientMsg = ( LPTOCLIENTMSG )MsgPnt;

			switch( lpToClientMsg->Type )
			{
			case TOCLIENTMSG_YouArePseudoHost:
				if ( !IsPseudoHost )
				{
					IsPseudoHost = TRUE;
					AddMessageToQue( YOU_HAVE_BECOME_THE_HOST );
				}
				SendGameMessage(MSG_TOSERVER, 0, 0, TOSERVERMSG_IAmPseudoHost, 0);
				break;
			}
		}
		return;
	case MSG_LEVELNAMES:

		if ( ( IsPseudoHost ) && ( MyGameStatus == STATUS_GetLevelNames ) )
		{
			lpLevelNamesMsg = ( LPLEVELNAMESMSG )MsgPnt;

			if ( !lpLevelNamesMsg->TotalLevels )
			{
				ServerLevelsListState = SERVERLEVELS_None;
			}

			// if we have not already recieved this batch...
			if ( !ServerLevelNames[ lpLevelNamesMsg->FirstLevel ][ 0 ] )
			{
				for( i = lpLevelNamesMsg->FirstLevel; i < ( lpLevelNamesMsg->ThisBatch + lpLevelNamesMsg->FirstLevel ); i++ )
				{
					strcpy( ServerLevelNames[ i ], lpLevelNamesMsg->Level[ i - lpLevelNamesMsg->FirstLevel ] );
					NumServerLevels++;
				}

				if ( NumServerLevels > lpLevelNamesMsg->TotalLevels )
				{
					NumServerLevels = lpLevelNamesMsg->TotalLevels;
#ifdef DEBUG_ON
					Msg("pseudohost has recieved too many levels from server!!!\n");
#endif
				}

				if ( NumServerLevels == lpLevelNamesMsg->TotalLevels )
				{
					if ( !InitLevels( MULTIPLAYER_LEVELS ) )
					{
						ServerLevelsListState = SERVERLEVELS_None;
					}else
					{
						ServerLevelsListState = SERVERLEVELS_Got;
					}
				}
			}
		}

		return;

	case MSG_TRACKERINFO:

		//Msg("tracker msg got through\n");

		lpTrackerInfoMsg = (LPTRACKERINFOMSG)MsgPnt;

		TrackerOveride = TRUE;

		tracker_addr = lpTrackerInfoMsg->addr;
		tracker_port = lpTrackerInfoMsg->port;
		heartbeat_freq = lpTrackerInfoMsg->freq;
		heartbeat_type = lpTrackerInfoMsg->type;
		SendShutdownPacket = lpTrackerInfoMsg->shutdown;
		bGameSpy = lpTrackerInfoMsg->gamespy;
		return;

	case MSG_SHIELDHULL:
		lpShieldHullMsg = (LPSHIELDHULLMSG)MsgPnt;
		if( !IsServer )
		{
			if( !lpShieldHullMsg->ValidChange && Ships[lpShieldHullMsg->WhoIAm].enable )
			{
				if ( ( ColPerspective == COLPERS_Descent || ColPerspective == COLPERS_Server ) && ( ( lpShieldHullMsg->Shield < Ships[lpShieldHullMsg->WhoIAm].Object.Shield ) ||
					( lpShieldHullMsg->Hull < Ships[lpShieldHullMsg->WhoIAm].Object.Hull ) ) )
				{
					Int_Point.x = Ships[lpShieldHullMsg->WhoIAm].Object.Pos.x - Ships[WhoIAm].Object.Pos.x;
					Int_Point.y = Ships[lpShieldHullMsg->WhoIAm].Object.Pos.y - Ships[WhoIAm].Object.Pos.y;
					Int_Point.z = Ships[lpShieldHullMsg->WhoIAm].Object.Pos.z - Ships[WhoIAm].Object.Pos.z;
					NormaliseVector( &Int_Point );

					Int_Point2.x = Ships[lpShieldHullMsg->WhoIAm].Object.Pos.x + ( Int_Point.x * SHIP_RADIUS );
					Int_Point2.y = Ships[lpShieldHullMsg->WhoIAm].Object.Pos.y + ( Int_Point.y * SHIP_RADIUS );
					Int_Point2.z = Ships[lpShieldHullMsg->WhoIAm].Object.Pos.z + ( Int_Point.z * SHIP_RADIUS );
					Int_Point.x = Ships[lpShieldHullMsg->WhoIAm].Object.Pos.x + ( Int_Point.x * -SHIP_RADIUS );
					Int_Point.y = Ships[lpShieldHullMsg->WhoIAm].Object.Pos.y + ( Int_Point.y * -SHIP_RADIUS );
					Int_Point.z = Ships[lpShieldHullMsg->WhoIAm].Object.Pos.z + ( Int_Point.z * -SHIP_RADIUS );

					PlayPannedSfx( SFX_ShipHit, Ships[ lpShieldHullMsg->WhoIAm ].Object.Group , &Int_Point, 0.0F );

					if( lpShieldHullMsg->Shield )
					{
						CreateShieldEffect( (VECTOR *) &Ships[lpShieldHullMsg->WhoIAm].Object.Pos, &Int_Point, &Int_Point2, lpShieldHullMsg->WhoIAm, 2, 128, 0, 128 );
					}else{
						TempVector.x = ( Int_Point.x - Ships[ lpShieldHullMsg->WhoIAm ].Object.Pos.x );
						TempVector.y = ( Int_Point.y - Ships[ lpShieldHullMsg->WhoIAm ].Object.Pos.y );
						TempVector.z = ( Int_Point.z - Ships[ lpShieldHullMsg->WhoIAm ].Object.Pos.z );
						NormaliseVector( &TempVector );
						CreateColSparks( &Int_Point, &TempVector, Ships[ lpShieldHullMsg->WhoIAm ].Object.Group );
					}
				}
			}
			
			Ships[lpShieldHullMsg->WhoIAm].Object.Shield = lpShieldHullMsg->Shield;
			Ships[lpShieldHullMsg->WhoIAm].Object.Hull = lpShieldHullMsg->Hull;
		}else{
			Ships[lpShieldHullMsg->WhoIAm].ShieldHullCount++;

			if( !lpShieldHullMsg->ValidChange &&
				( Ships[lpShieldHullMsg->WhoIAm].ShieldHullCount == lpShieldHullMsg->Count ) &&
				( MyGameStatus == STATUS_Normal ) &&
				( GameStatus[lpShieldHullMsg->WhoIAm] == STATUS_Normal ) )
			{
				if( ( ( lpShieldHullMsg->Hull - Ships[lpShieldHullMsg->WhoIAm].Object.Hull ) > 1.0F ) ||
					( ( lpShieldHullMsg->Shield - Ships[lpShieldHullMsg->WhoIAm].Object.Shield ) > 1.0F ) )
				{
					CanDoDamage[lpShieldHullMsg->WhoIAm] = FALSE;
				}
				if( ( lpShieldHullMsg->Hull - START_HULL ) > 1.0F )
				{
					CanDoDamage[lpShieldHullMsg->WhoIAm] = FALSE;
				}
			}
			Ships[lpShieldHullMsg->WhoIAm].Object.Shield = lpShieldHullMsg->Shield;
			Ships[lpShieldHullMsg->WhoIAm].Object.Hull = lpShieldHullMsg->Hull;
			Ships[lpShieldHullMsg->WhoIAm].ShieldHullCount = lpShieldHullMsg->Count;

		}
		return;

	case MSG_SERVERSCORED:
		lpServerScoredMsg = (LPSERVERSCOREDMSG)MsgPnt;
		if ( lpServerScoredMsg->WhoScored == WhoIAm )
		{
			int team;

			Ships[WhoIAm].Kills += (int16) lpServerScoredMsg->Score;
			if ( CTF )
			{
				for ( team = 0; team < MAX_TEAMS; team++ )
				{
					Ships[WhoIAm].Object.Flags &= ~TeamFlagMask[ team ];
					PickupsGot[ TeamFlagPickup[ team ] ] = 0;
				}
			}
			if ( CaptureTheFlag )
			{
				Ships[WhoIAm].Object.Flags &= ~SHIP_CarryingFlag;
				PickupsGot[ PICKUP_Flag ] = 0;
			}
		}
		sprintf( (char*) tempstr, THE_COLOUR_TEAM_HAVE_SCORED, TeamName[ TeamNumber[ lpServerScoredMsg->WhoScored ] ] );
		AddMessageToQue( (char*)&tempstr[0] );
		if ( TeamNumber[ WhoIAm ] == TeamNumber[ lpServerScoredMsg->WhoScored ] )
			PlaySfx( SFX_MyTeamScored, 1.0F );
		else
			PlaySfx( SFX_OtherTeamScored , 1.0F );
		return;
	}

	wsprintf(dBuf, "corrupt message: %d\n", *MsgPnt);
	OutputDebugString( dBuf );
}
 
/*�������������������������������������������������������������������
	Procedure	:		Send a message to all or just one..
	Input		:		BYTE msg ,
						DWORD to (DplayID) ,
						BYTE ShipNum ,
						BYTE Type,
						BYTE MASK
	Output		:		nothing
�������������������������������������������������������������������*/

void SendGameMessage( BYTE msg, DWORD to, BYTE ShipNum, BYTE Type, BYTE mask )
{
#ifndef SELF_PLAY
    LPVERYSHORTUPDATEMSG			lpVeryShortUpdate;
    LPUPDATEMSG			lpUpdate;
    LPFUPDATEMSG		lpFUpdate;
	LPVERYSHORTFUPDATEMSG lpVeryShortFUpdate;
	LPGROUPONLY_VERYSHORTFUPDATEMSG lpGroupOnly_VeryShortFUpdate;
    LPHEREIAMMSG		lpHereIAm;
    LPINITMSG			lpInit;
    LPPRIMBULLPOSDIRMSG lpPrimBullPosDir;
    LPSECBULLPOSDIRMSG  lpSecBullPosDir;
    LPTITANBITSMSG		lpTitanBits;
    LPSHIPHITMSG		lpShipHit;
    LPSHORTSHIPHITMSG	lpShortShipHit;
    LPSHIPDIEDMSG       lpShipDied;
    LPDROPPICKUPMSG		lpDropPickup;
    LPVERYSHORTDROPPICKUPMSG		lpVeryShortDropPickup;
    LPKILLPICKUPMSG		lpKillPickup;
    LPSERVERKILLPICKUPMSG lpServerKillPickup;
    LPEXPLODESHIPMSG	lpExplodeShip;
    LPEXPSECONDARYMSG	lpExplodeSecondary;
    LPTEAMGOALSMSG		lpTeamGoals;
    LPSHOCKWAVEMSG		lpShockwave;
    LPBGOUPDATEMSG		lpBGOUpdate;
    LPSHORTSTATSMSG		lpShortStats;
    LPSTATUSMSG			lpStatus;
    LPLONGSTATUSMSG		lpLongStatus;
    LPSHORTPICKUPMSG	lpShortPickup;
    LPSHORTREGENSLOTMSG	lpShortRegenSlot;
    LPSHORTTRIGGERMSG	lpShortTrigger;
    LPSHORTTRIGVARMSG	lpShortTrigVar;
    LPSHORTMINEMSG		lpShortMine;
    LPTEXTMSG			lpTextMsg;
    LPBOMBMSG			lpBomb;
    LPPINGMSG			lpPingMsg;
	LPPLAYERPINGSMSG	lpPlayerPingsMsg;
	LPNAMEMSG			lpName;
	LPACKMSG			lpAckMsg;
	LPKILLSDEATHSBIKENUMMSG	lpKillsDeathsMsg;
	LPYOUQUITMSG			lpYouQuitMsg;
	LPSENDKILLSDEATHSBIKENUMMSG			lpSendKillsDeathsBikenum;
	LPSERVERSAYSSHIPDIEDMSG lpServerSaysShipDiedMsg;
    int					nBytes;
    int					i;
    DWORD				send_to = 0;
	DWORD				Flags = 0;
	int					Count;
	HRESULT				hr;
	LPSETTIMEMSG		lpSetTime;
	LPREQTIMEMSG		lpReqTime;
	LPGAMEPARAMETERSMSG lpGameParamMsg;
#ifdef MANUAL_SESSIONDESC_PROPAGATE
	LPSESSIONDESCMSG	lpSessionDescMsg;
#endif
	LPTOSERVERMSG lpToServerMsg;
	LPTOCLIENTMSG lpToClientMsg;
	LPLEVELNAMESMSG	lpLevelNamesMsg;
	LPTRACKERINFOMSG	lpTrackerInfoMsg;
	LPSHIELDHULLMSG	lpShieldHullMsg;
	LPSERVERSCOREDMSG	lpServerScoredMsg;
	LONGLONG	TimeFrig;

	if( PlayDemo || !glpDP )
		return;
	
	//DebugPrintf("about to send msg %x\n",msg);	
	switch( msg )
    {
	case MSG_SERVERSCORED:
		lpServerScoredMsg = (LPSERVERSCOREDMSG)&CommBuff[0];

        lpServerScoredMsg->MsgCode = msg;
		lpServerScoredMsg->WhoIAm = WhoIAm;
		lpServerScoredMsg->WhoScored = ShipNum;
		lpServerScoredMsg->Score = Type;
		nBytes = sizeof( SERVERSCOREDMSG );
#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0] , MSG_SERVERSCORED , FALSE , FALSE);
		return;
#endif
		break;
	case MSG_SHIELDHULL:
		lpShieldHullMsg = (LPSHIELDHULLMSG)&CommBuff[0];

        lpShieldHullMsg->MsgCode = msg;
		lpShieldHullMsg->WhoIAm = WhoIAm;
		lpShieldHullMsg->Shield = (BYTE) Ships[WhoIAm].Object.Shield;
		lpShieldHullMsg->Hull = (BYTE) Ships[WhoIAm].Object.Hull;

		lpShieldHullMsg->ValidChange = JustGenerated | JustPickedUpShield;
		Ships[WhoIAm].ShieldHullCount++;
		lpShieldHullMsg->Count = Ships[WhoIAm].ShieldHullCount;

		JustPickedUpShield = FALSE;
		JustGenerated = FALSE;

		nBytes = sizeof( SHIELDHULLMSG );
		break;
	case MSG_SERVERSAYSSHIPDIED:
		lpServerSaysShipDiedMsg = (LPSERVERSAYSSHIPDIEDMSG)&CommBuff[0];
		*lpServerSaysShipDiedMsg = SSSDM;

		nBytes = sizeof( SERVERSAYSSHIPDIEDMSG );

#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0] , MSG_SERVERSAYSSHIPDIED , FALSE , FALSE);
		return;
#endif
		break;

    case MSG_SENDKILLSDEATHSBIKENUM:
		lpSendKillsDeathsBikenum = (LPSENDKILLSDEATHSBIKENUMMSG)&CommBuff[0];
        lpSendKillsDeathsBikenum->MsgCode = msg;
		lpSendKillsDeathsBikenum->WhoIAm = WhoIAm;
		nBytes = sizeof( SENDKILLSDEATHSBIKENUMMSG );

#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0] , MSG_SENDKILLSDEATHSBIKENUM , FALSE , TRUE);
		return;
#endif
		break;
    case MSG_YOUQUIT:
		lpYouQuitMsg = (LPYOUQUITMSG)&CommBuff[0];
        lpYouQuitMsg->MsgCode = msg;
		lpYouQuitMsg->WhoIAm = WhoIAm;
		lpYouQuitMsg->You = ShipNum;
		nBytes = sizeof( YOUQUITMSG );
#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0] , MSG_YOUQUIT , FALSE , FALSE);
		return;
#endif
		break;


    case MSG_KILLSDEATHSBIKENUM:
		lpKillsDeathsMsg = (LPKILLSDEATHSBIKENUMMSG)&CommBuff[0];
        lpKillsDeathsMsg->MsgCode = msg;
		lpKillsDeathsMsg->WhoIAm = WhoIAm;
		lpKillsDeathsMsg->Kills = Ships[WhoIAm].Kills;
		lpKillsDeathsMsg->Deaths = Ships[WhoIAm].Deaths;
		lpKillsDeathsMsg->BikeNum = (BYTE) Ships[WhoIAm].BikeNum;
		nBytes = sizeof( KILLSDEATHSBIKENUMMSG );
#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0] , MSG_KILLSDEATHSBIKENUM , FALSE , TRUE);
		return;
#endif
		break;
    case MSG_NAME:
		if( !IsServerGame )
			DPlaySetPlayerName(dcoID, &biker_name[0], 0);

		lpName = (LPNAMEMSG)&CommBuff[0];
        lpName->MsgCode = msg;
		lpName->WhoIAm = WhoIAm;
		for( i = 0 ; i < 8 ; i++ )
		{
#if defined (SELF_PLAY) || defined (ECTS)
			// force player to use same name as his bike
			lpName->Name[i] = BikeList.item[lpName->WhoIAm % MAXBIKETYPES][i];

			Names[WhoIAm][i] = BikeList.item[lpName->WhoIAm % MAXBIKETYPES][i];
#elif defined( SHAREWARE )
			if ( PlayDemo )
			{
				lpName->Name[i] = BikeList.item[AllowedBike[lpName->WhoIAm % ALLOWED_BIKETYPES]][i];
				Names[lpName->WhoIAm][i] = BikeList.item[AllowedBike[lpName->WhoIAm % ALLOWED_BIKETYPES]][i];
			}
			else
			{
				lpName->Name[i] = biker_name[i];
				Names[WhoIAm][i] = biker_name[i];
			}
#else
			lpName->Name[i] = biker_name[i];
			Names[WhoIAm][i] = biker_name[i];
#endif
		}
		lpName->Name[7] = 0;
		Names[WhoIAm][7] = 0;
		nBytes = sizeof( NAMEMSG );

#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0] , MSG_NAME , FALSE, TRUE );
		return;
#endif
		break;
	
	case MSG_HEREIAM:

		// only applicable if I am the first to join a server game, but no harm in doing this anyway
		memset( ServerLevelNames, 0, sizeof( ServerLevelNames ) );
		NumServerLevels = 0;
		ServerLevelsListState = SERVERLEVELS_Waiting;	

        lpHereIAm = (LPHEREIAMMSG)&CommBuff[0];
        lpHereIAm->MsgCode = msg;
        lpHereIAm->WhoIAm = WhoIAm;
        lpHereIAm->ID = (DWORD)dcoID;

        lpHereIAm->Rejoining = Rejoining;
        lpHereIAm->Old_WhoIAm = (BYTE) Old_WhoIAm;
        lpHereIAm->Old_TeamNumber = (BYTE) Old_TeamNumber;
        
		nBytes = sizeof( HEREIAMMSG );
        break;

    case MSG_INIT:
		if( !IsHost )
			return;

		lpInit = (LPINITMSG)&CommBuff[0];

		lpInit->FromDpid = dcoID;

        lpInit->MsgCode = msg;
        lpInit->WhoIAm = WhoIAm;

		DPlayGetSessionDesc();

		lpInit->dwUser3 = glpdpSD->dwUser3;

		if ( ( glpdpSD->dwUser3 & ServerGameStateBits ) == SERVER_STATE_HostChoosing )
		{
#ifdef DEBUG_ON
			Msg("error - server is about to send MSG_INIT before pseudohost has choosen game type\n");
#endif
			return;	// requesting player will not get player number
		}

        send_to = to;
		lpInit->RandomPickups = RandomPickups;
		lpInit->Seed1 = CopyOfSeed1;
		lpInit->Seed2 = CopyOfSeed2;
		//lpInit->HarmTeamMates = HarmTeamMates;
		//lpInit->BrightShips = BrightShips;
		//lpInit->BikeExhausts = BikeExhausts;
		//lpInit->Collisions = ColPerspective;
		//lpInit->MaxKills = MaxKills;
		lpInit->PacketsPerSecond = DPlayUpdateInterval;
		PackPickupInfo( lpInit->PickupFlags );
		lpInit->GoalScore = GoalScore;
		lpInit->BountyBonusInterval = BountyBonusInterval;
		//lpInit->CTF_Type = CTFSlider.value;

		lpInit->PrimaryPickups = NumPrimaryPickups;

		lpInit->ServerCollisions = ServerCollisions;

		for( Count = 0 ; Count < 32 ; Count++ )
		{
			lpInit->LevelName[Count] = ShortLevelNames[NewLevelNum][Count];
		}

		
		if( ( MyGameStatus == STATUS_StartingMultiplayer ) || ( MyGameStatus == STATUS_Normal ) )
		{
			// tell the player who is host thinks is ready.
			for( Count = 0 ; Count < MAX_PLAYERS ; Count++ )			
			{															
				lpInit->PlayerReady[Count] = PlayerReady[Count];
				
				lpInit->GameStatus[Count] = GameStatus[Count];

			}															
			if( (mask != 0) && (ShipNum < MAX_PLAYERS) && GameStatus[ShipNum] == STATUS_GetPlayerNum )
			{
				// this player has requested a number before....just send them the same one again...
				i = ShipNum;
//				memset(&Ships[i], 0, sizeof(GLOBALSHIP) );
				for( Count = 0; Count < MAXMULTIPLES; Count++ ) Ships[i].OrbModels[ Count ] = (uint16) -1;
				GameStatus[i] = STATUS_GetPlayerNum;
				lpInit->YouAre = (BYTE) i;
				DebugPrintf("YouAre set to %d at point 1\n", i);
				Names[i][0] = 0;

				if( Type == (BYTE) -1 )
				{
					TeamNumber[i] = 0;
				}else{
					TeamNumber[i] = Type;
				}
				for( Count = 0 ; Count < MAX_PLAYERS ; Count++ )			// Replaced i with Count
				{															// Replaced i with Count
					lpInit->TeamNumber[Count] = TeamNumber[Count];			// Replaced i with Count
				}															// Replaced i with Count
				lpInit->Status = MyGameStatus;
				// getplayer
				// over the next few frames send the current stats table...
				if(	MyGameStatus == STATUS_Normal )
				{
//					StatsCount = MAX_PLAYERS;
					memset(&Stats[i][0], 0, sizeof(int16) * MAX_PLAYERS);
					// not sure if I should do this again DAVE ???
					CopyPickups( (uint16) i );
					CopyRegenSlots( (uint16) i );
					CopyTriggers( (uint16) i );
					CopyTrigVars( (uint16) i );
					CopyMines( (uint16) i );
				}
			}else{
			
				// The game is currently ok to join......
				i = MAX_PLAYERS;
				if( ShipNum < MAX_PLAYERS )
				{
		    		if(  ( GameStatus[ShipNum] == STATUS_Left ) || ( GameStatus[ShipNum] == STATUS_LeftCrashed ) || ( GameStatus[ShipNum] == STATUS_Null ) )
						i = ShipNum;
				}
				if( i == MAX_PLAYERS )
				{
				    for( i = 0 ; i < MAX_PLAYERS ; i++ )
				    {
				    	if( i != WhoIAm )
				    	{
				    		// try and find a slot that hasnt been used at all...
				    		if(	( GameStatus[i] == STATUS_Left ) || ( GameStatus[i] == STATUS_LeftCrashed ) || ( GameStatus[i] == STATUS_Null ) )
				    			break;
				    	}
				    }
				}
		
				if( i != MAX_PLAYERS )
				{
					InitShipStructure(i , TRUE);
					GameStatus[i] = STATUS_GetPlayerNum;
					lpInit->YouAre = (BYTE) i;
					DebugPrintf("YouAre set to %d at point 2\n", i);
					Names[i][0] = 0;
					Ships[i].dcoID = to;
#if 0
					// if TCP game, store IP address of player
					if ( ! memcmp( &ServiceProvidersGuids[ServiceProvidersList.selected_item], &DPSPGUID_TCPIP , sizeof(GUID) ) )
					{
						char add[ 16 ];

						memset(&PlayerIP[ i ], 0, sizeof(PlayerIP[ i ]));
						if ( GetIPFromDP( add, to ) )
						{
							PlayerIP[ i ].sin_family = AF_INET;
							PlayerIP[ i ].sin_port = htons( DEF_PORT );
							PlayerIP[ i ].sin_addr.s_addr = inet_addr( add );
						}
					}
#endif

					if( Type == (BYTE) -1 )
					{
						TeamNumber[i] = 0;
					}else{
						TeamNumber[i] = Type;
					}
					
					for( Count = 0 ; Count < MAX_PLAYERS ; Count++ )			// Replaced i with Count
					{															// Replaced i with Count
						lpInit->TeamNumber[Count] = TeamNumber[Count];			// Replaced i with Count
					}															// Replaced i with Count
					
					lpInit->Status = MyGameStatus;
					// getplayer
					// over the next few frames send the current stats table...
	
					if(	MyGameStatus == STATUS_Normal )
					{
//						StatsCount = MAX_PLAYERS;
						memset(&Stats[i][0], 0, sizeof(int16) * MAX_PLAYERS);
						CopyPickups( (uint16) i );
						CopyRegenSlots( (uint16) i );
						CopyTriggers( (uint16) i );
						CopyTrigVars( (uint16) i );
						CopyMines( (uint16) i );
					}
				}else{
					// The game is currently full or nearly so dont let anyone else join...
					lpInit->YouAre = MAX_PLAYERS+2;
				}
			}
		}else{
			// The game is currently non joinable so dont let anyone else join...
			lpInit->YouAre = MAX_PLAYERS;
		}

		DebugPrintf("MSG_INIT being sent: lpInit->YouAre = %d\n", lpInit->YouAre);

		nBytes = sizeof( INITMSG );
		break;
    case MSG_VERYSHORTUPDATE:
        lpVeryShortUpdate = (LPVERYSHORTUPDATEMSG)&CommBuff[0];
        lpVeryShortUpdate->MsgCode = msg;
        lpVeryShortUpdate->WhoIAm = WhoIAm;
		lpVeryShortUpdate->ShortGlobalShip = VeryShortGlobalShip;
        nBytes = sizeof( VERYSHORTUPDATEMSG );
        break;

    case MSG_UPDATE:
        lpUpdate = (LPUPDATEMSG)&CommBuff[0];
        lpUpdate->MsgCode = msg;
        lpUpdate->WhoIAm = WhoIAm;
		lpUpdate->ShortGlobalShip = ShortGlobalShip;
        nBytes = sizeof( UPDATEMSG );
        break;

    case MSG_FUPDATE:
        lpFUpdate = (LPFUPDATEMSG)&CommBuff[0];
        lpFUpdate->MsgCode = msg;
        lpFUpdate->WhoIAm = WhoIAm;
		lpFUpdate->ShortGlobalShip = FShortGlobalShip;
        nBytes = sizeof( FUPDATEMSG );
        break;
    case MSG_VERYSHORTFUPDATE:
        lpVeryShortFUpdate = (LPVERYSHORTFUPDATEMSG)&CommBuff[0];
        lpVeryShortFUpdate->MsgCode = msg;
        lpVeryShortFUpdate->WhoIAm = WhoIAm;
		lpVeryShortFUpdate->ShortGlobalShip = FVeryShortGlobalShip;
        nBytes = sizeof( VERYSHORTFUPDATEMSG );
        break;

    case MSG_GROUPONLY_VERYSHORTFUPDATE:
        lpGroupOnly_VeryShortFUpdate = (LPGROUPONLY_VERYSHORTFUPDATEMSG)&CommBuff[0];
        lpGroupOnly_VeryShortFUpdate->MsgCode = msg;
        lpGroupOnly_VeryShortFUpdate->WhoIAm = WhoIAm;
		lpGroupOnly_VeryShortFUpdate->ShortGlobalShip = GroupOnly_FVeryShortGlobalShip;
        nBytes = sizeof( GROUPONLY_VERYSHORTFUPDATEMSG );
        break;



    case MSG_DROPPICKUP:
        lpDropPickup = (LPDROPPICKUPMSG) &CommBuff[0];
        lpDropPickup->MsgCode = msg;
        lpDropPickup->WhoIAm = WhoIAm;
        lpDropPickup->PickupInfo = TempPickup;
        nBytes = sizeof( DROPPICKUPMSG );
#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0] , MSG_DROPPICKUP , FALSE , FALSE);
		return;
#endif
        break;

    case MSG_VERYSHORTDROPPICKUP:
        lpVeryShortDropPickup = (LPVERYSHORTDROPPICKUPMSG) &CommBuff[0];
        lpVeryShortDropPickup->MsgCode = msg;
        lpVeryShortDropPickup->WhoIAm = WhoIAm;
        lpVeryShortDropPickup->PickupInfo = VeryShortTempPickup;
        nBytes = sizeof( VERYSHORTDROPPICKUPMSG );
#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0] , MSG_VERYSHORTDROPPICKUP , FALSE , FALSE);
		return;
#endif
        break;



    case MSG_KILLPICKUP:
        lpKillPickup = (LPKILLPICKUPMSG) &CommBuff[0];
        lpKillPickup->MsgCode = msg;
        lpKillPickup->WhoIAm = WhoIAm;
        lpKillPickup->KillPickupInfo = TempKillPickup;
        nBytes = sizeof( KILLPICKUPMSG );
#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0] , MSG_KILLPICKUP , FALSE , FALSE);
		return;
#endif
        break;

    case MSG_SERVERKILLPICKUP:
        lpServerKillPickup = (LPSERVERKILLPICKUPMSG) &CommBuff[0];
        lpServerKillPickup->MsgCode = msg;
        lpServerKillPickup->WhoIAm = WhoIAm;
        lpServerKillPickup->ServerKillPickupInfo = TempServerKillPickup;
        nBytes = sizeof( SERVERKILLPICKUPMSG );
#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0] , MSG_SERVERKILLPICKUP , FALSE , FALSE);
		return;
#endif
        break;

    case MSG_EXPLODESHIP:
        lpExplodeShip = (LPEXPLODESHIPMSG) &CommBuff[0];
        lpExplodeShip->MsgCode = msg;
        lpExplodeShip->WhoIAm = WhoIAm;
        lpExplodeShip->ExplodeShipInfo = TempExplodeShip;
        nBytes = sizeof( EXPLODESHIPMSG );
#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0] , MSG_EXPLODESHIP , FALSE , FALSE);
		return;
#endif
        break;

    case MSG_EXPSECONDARY:
        lpExplodeSecondary = (LPEXPSECONDARYMSG) &CommBuff[0];
        lpExplodeSecondary->MsgCode = msg;
        lpExplodeSecondary->WhoIAm = WhoIAm;
        lpExplodeSecondary->ExplodeSecondaryInfo = TempExplodeSecondary;
        nBytes = sizeof( EXPSECONDARYMSG );
#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0] , MSG_EXPSECONDARY , FALSE , FALSE);
		return;
#endif
        break;

    case MSG_TEAMGOALS:
        lpTeamGoals = (LPTEAMGOALSMSG) &CommBuff[0];
        lpTeamGoals->MsgCode = msg;
        lpTeamGoals->WhoIAm = WhoIAm;
        lpTeamGoals->TeamGoalsInfo = TempTeamGoals;
        nBytes = sizeof( TEAMGOALSMSG );
#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0] , MSG_TEAMGOALS, FALSE , FALSE);
		return;
#endif
        break;

    case MSG_SHOCKWAVE:
        lpShockwave = (LPSHOCKWAVEMSG) &CommBuff[0];
        lpShockwave->MsgCode = msg;
        lpShockwave->WhoIAm = WhoIAm;
        lpShockwave->ShockwaveInfo = TempShockwave;
        nBytes = sizeof( SHOCKWAVEMSG );
        break;

    case MSG_BGOUPDATE:
        lpBGOUpdate = (LPBGOUPDATEMSG) &CommBuff[0];
        lpBGOUpdate->MsgCode = msg;
        lpBGOUpdate->WhoIAm = WhoIAm;
        lpBGOUpdate->BGOUpdateInfo = TempBGOUpdate;
        nBytes = sizeof( BGOUPDATEMSG );
        break;

    case MSG_PRIMBULLPOSDIR:
        lpPrimBullPosDir = (LPPRIMBULLPOSDIRMSG)&CommBuff[0];
        lpPrimBullPosDir->MsgCode = msg;
        lpPrimBullPosDir->WhoIAm = WhoIAm;
        lpPrimBullPosDir->PrimBullPosDir = TempPrimBullPosDir;
        nBytes = sizeof( PRIMBULLPOSDIRMSG );
        break;

    case MSG_SECBULLPOSDIR:
        lpSecBullPosDir = (LPSECBULLPOSDIRMSG)&CommBuff[0];
        lpSecBullPosDir->MsgCode = msg;
        lpSecBullPosDir->WhoIAm = WhoIAm;
        lpSecBullPosDir->SecBullPosDir = TempSecBullPosDir;
        nBytes = sizeof( SECBULLPOSDIRMSG );
#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0], MSG_SECBULLPOSDIR, FALSE , FALSE);
		return;
#endif
        break;

    case MSG_TITANBITS:
        lpTitanBits = (LPTITANBITSMSG)&CommBuff[0];
        lpTitanBits->MsgCode = msg;
        lpTitanBits->WhoIAm = WhoIAm;
        lpTitanBits->TitanBits = TempTitanBits;
        nBytes = sizeof( TITANBITSMSG );
#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0], MSG_TITANBITS, FALSE , FALSE);
		return;
#endif
        break;

    case MSG_SHIPHIT:
		
        lpShipHit = (LPSHIPHITMSG)&CommBuff[0];
        lpShipHit->MsgCode = msg;
        lpShipHit->You = ShipNum;
		if( ColPerspective != COLPERS_Server )
		{
	        lpShipHit->WhoHitYou = WhoIAm;
		}else{
	        lpShipHit->WhoHitYou = Server_WhoHitYou;
		}
        lpShipHit->ShipHit = TempShipHit;
        lpShipHit->Deaths = Ships[ShipNum].Deaths;
        nBytes = sizeof( SHIPHITMSG );
        break;
    case MSG_SHORTSHIPHIT:

        lpShortShipHit = (LPSHORTSHIPHITMSG)&CommBuff[0];
        lpShortShipHit->MsgCode = msg;
        lpShortShipHit->You = ShipNum;
		if( ColPerspective != COLPERS_Server )
		{
	        lpShortShipHit->WhoHitYou = WhoIAm;
		}else{
	        lpShortShipHit->WhoHitYou = Server_WhoHitYou;
		}
        lpShortShipHit->ShipHit = ShortTempShipHit;
        lpShortShipHit->Deaths = Ships[ShipNum].Deaths;
        nBytes = sizeof( SHORTSHIPHITMSG );
        break;

    case MSG_SHIPDIED:
        lpShipDied = (LPSHIPDIEDMSG)&CommBuff[0];
        lpShipDied->MsgCode = msg;
        lpShipDied->WhoIAm = WhoIAm;
		lpShipDied->Pos = Ships[WhoIAm].Object.Pos;
		lpShipDied->WhoKilledMe = Ships[WhoIAm].ShipThatLastKilledMe;
		lpShipDied->Type	= Type;
		lpShipDied->WeaponType = TempDied.WeaponType;
		lpShipDied->Weapon = TempDied.Weapon;
		nBytes = sizeof( SHIPDIEDMSG );
#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0], MSG_SHIPDIED , FALSE , FALSE);
		return;
#endif
        break;

    case MSG_REQTIME:
        lpReqTime = (LPREQTIMEMSG)&CommBuff[0];
        lpReqTime->MsgCode = msg;
        lpReqTime->WhoIAm = WhoIAm;
		nBytes = sizeof( REQTIMEMSG );
        break;

    case MSG_SETTIME:
        lpSetTime = (LPSETTIMEMSG)&CommBuff[0];
        lpSetTime->MsgCode = msg;
        lpSetTime->WhoIAm = WhoIAm;
		lpSetTime->TimeInfo = TempTimeSet;
		nBytes = sizeof( SETTIMEMSG );
        break;

    case MSG_SHORTSTATS:
        lpShortStats = (LPSHORTSTATSMSG)&CommBuff[0];
        lpShortStats->MsgCode = msg;
        lpShortStats->WhoIAm = WhoIAm;
        lpShortStats->WhosStats = ShipNum;
		memcpy( (void*) lpShortStats->ShortStats , (void*) &Stats[ShipNum][0] , sizeof(SHORTSTATSTYPE) ) ;
        nBytes = sizeof( SHORTSTATSMSG );
        break;
    case MSG_STATUS:
		lpStatus = (LPSTATUSMSG)&CommBuff[0];
		lpStatus->TeamScore = 0;
		if ( TeamGame && Type == 1 )
		{
			lpStatus->TeamScore = Ships[ WhoIAm ].Kills;
		}
        lpStatus->MsgCode = msg;
        lpStatus->WhoIAm = WhoIAm;
        lpStatus->IsHost = IsHost;
		lpStatus->PacketsPerSecond = DPlayUpdateInterval;
		// telling everyone what I am currently doing....
		lpStatus->Status = MyGameStatus;
		lpStatus->TeamNumber = TeamNumber[WhoIAm];
		lpStatus->IAmReady = PlayerReady[WhoIAm];

		lpStatus->Pickups		= Ships[WhoIAm].Pickups;	 
		lpStatus->RegenSlots	= Ships[WhoIAm].RegenSlots;
		lpStatus->Mines			= Ships[WhoIAm].Mines;		 
		lpStatus->Triggers		= Ships[WhoIAm].Triggers;	 
		lpStatus->TrigVars		= Ships[WhoIAm].TrigVars;	 

		if( !IsHost && !IsServer )
		{
			lpStatus->LevelCheckSum	= LevelCheckSum;
		}else{
			lpStatus->LevelCheckSum	= 0;
		}


		nBytes = sizeof( STATUSMSG );

#ifdef	GUARANTEEDMESSAGES
		if ( MyGameStatus == STATUS_Left )	// send last status msg guaranteed
		{
			AddGuaranteedMessage( nBytes , (void*) &CommBuff[0] , MSG_STATUS , TRUE, TRUE);
			return;
		}
#endif
        break;
    case MSG_LONGSTATUS:
		lpLongStatus = (LPLONGSTATUSMSG)&CommBuff[0];
        lpLongStatus->MsgCode = msg;
        lpLongStatus->WhoIAm = WhoIAm;
        lpLongStatus->Status.MsgCode = msg;
        lpLongStatus->Status.WhoIAm = WhoIAm;
        lpLongStatus->Status.IsHost = IsHost;
		lpLongStatus->Status.PacketsPerSecond = DPlayUpdateInterval;
		// telling everyone what I am currently doing....
		lpLongStatus->Status.Status = MyGameStatus;
		lpLongStatus->Status.TeamNumber = TeamNumber[WhoIAm];
		lpLongStatus->Status.IAmReady = PlayerReady[WhoIAm];
		lpLongStatus->Status.Pickups		= Ships[WhoIAm].Pickups;	 
		lpLongStatus->Status.RegenSlots	= Ships[WhoIAm].RegenSlots;
		lpLongStatus->Status.Mines			= Ships[WhoIAm].Mines;		 
		lpLongStatus->Status.Triggers		= Ships[WhoIAm].Triggers;	 
		lpLongStatus->Status.TrigVars		= Ships[WhoIAm].TrigVars;	 
		if( !IsHost && !IsServer )
		{
			lpLongStatus->Status.LevelCheckSum = LevelCheckSum;
		}else{
			lpLongStatus->Status.LevelCheckSum = 0;
		}


		for( Count = 0 ; Count < 32 ; Count++ )
		{
			lpLongStatus->LevelName[Count] = ShortLevelNames[NewLevelNum][Count];
		}
		lpLongStatus->RandomStartPosModify = RandomStartPosModify;
		nBytes = sizeof( LONGSTATUSMSG );
        break;

    case MSG_SHORTPICKUP:
		lpShortPickup = (LPSHORTPICKUPMSG)&CommBuff[0];
        lpShortPickup->MsgCode = msg;
        lpShortPickup->WhoIAm = WhoIAm;
        lpShortPickup->Pickups = Ships[ShipNum].Pickups;

		GenPickupList( ShipNum, &lpShortPickup->ShortPickup[0] , &lpShortPickup->HowManyPickups , Ships[ShipNum].Pickups );
        
		nBytes = sizeof( SHORTPICKUPMSG );
		send_to = Ships[ShipNum].dcoID;
        break;

    case MSG_SHORTREGENSLOT:
		lpShortRegenSlot = (LPSHORTREGENSLOTMSG)&CommBuff[0];
        lpShortRegenSlot->MsgCode = msg;
        lpShortRegenSlot->WhoIAm = WhoIAm;
        lpShortRegenSlot->RegenSlots = Ships[ShipNum].RegenSlots;

		GenRegenSlotList( ShipNum, &lpShortRegenSlot->ShortRegenSlot[0] , &lpShortRegenSlot->HowManyRegenSlots , Ships[ShipNum].RegenSlots );
        
		nBytes = sizeof( SHORTREGENSLOTMSG );
		send_to = Ships[ShipNum].dcoID;
        break;

    case MSG_SHORTTRIGGER:
		lpShortTrigger = (LPSHORTTRIGGERMSG)&CommBuff[0];
        lpShortTrigger->MsgCode = msg;
        lpShortTrigger->WhoIAm = WhoIAm;
        lpShortTrigger->Triggers = Ships[ShipNum].Triggers;

		GenTriggerList( ShipNum, &lpShortTrigger->ShortTrigger[0] , &lpShortTrigger->HowManyTriggers, Ships[ShipNum].Triggers );
        
		nBytes = sizeof( SHORTTRIGGERMSG );
		send_to = Ships[ShipNum].dcoID;
        break;

    case MSG_SHORTTRIGVAR:
		lpShortTrigVar = (LPSHORTTRIGVARMSG)&CommBuff[0];
        lpShortTrigVar->MsgCode = msg;
        lpShortTrigVar->WhoIAm = WhoIAm;
        lpShortTrigVar->TrigVars = Ships[ShipNum].TrigVars;

		GenTrigVarList( ShipNum, &lpShortTrigVar->ShortTrigVar[0] , &lpShortTrigVar->HowManyTrigVars, Ships[ShipNum].TrigVars );
        
		nBytes = sizeof( SHORTTRIGVARMSG );
		send_to = Ships[ShipNum].dcoID;
        break;


    case MSG_SHORTMINE:
		lpShortMine = (LPSHORTMINEMSG)&CommBuff[0];
        lpShortMine->MsgCode = msg;
        lpShortMine->WhoIAm = WhoIAm;
        lpShortMine->Mines = Ships[ShipNum].Mines;

		GenMineList( ShipNum, &lpShortMine->ShortMine[0] , &lpShortMine->HowManyMines, Ships[ShipNum].Mines );
        
		nBytes = sizeof( SHORTMINEMSG );
		send_to = Ships[ShipNum].dcoID;
        break;

    case MSG_BOMB:
		lpBomb = (LPBOMBMSG)&CommBuff[0];
        lpBomb->MsgCode = msg;
        lpBomb->WhoIAm = WhoIAm;
		lpBomb->BombNum	= BombNumToSend;
		lpBomb->BombTime = BombTimeToSend;
		lpBomb->WhoGotHit = (BYTE) ShipNum;
		nBytes = sizeof( BOMBMSG );
        break;

    case MSG_TEXTMSG:
		lpTextMsg = (LPTEXTMSG)&CommBuff[0];
        lpTextMsg->MsgCode = msg;
        lpTextMsg->WhoIAm = WhoIAm;
        
		switch( Type )
		{
		case TEXTMSGTYPE_Taunt1:
			strncpy( &lpTextMsg->Text[0]	, &MacroText1.text[0] , MAXTEXTMSG );
			lpTextMsg->TextMsgType = Type;
			break;
		case TEXTMSGTYPE_Taunt2:
			strncpy( &lpTextMsg->Text[0]	, &MacroText2.text[0] , MAXTEXTMSG );
			lpTextMsg->TextMsgType = Type;
			break;
		case TEXTMSGTYPE_Taunt3:
			strncpy( &lpTextMsg->Text[0]	, &MacroText3.text[0] , MAXTEXTMSG );
			lpTextMsg->TextMsgType = Type;
			break;
		case TEXTMSGTYPE_TitleMessage:
			strncpy( &lpTextMsg->Text[0]	, &MacroText4.text[0] , MAXTEXTMSG );
			lpTextMsg->TextMsgType = Type;
			break;
		case TEXTMSGTYPE_JoiningTeamGame:
//			strncpy( &lpTextMsg->Text[0]	, "%s is joining the game" , MAXTEXTMSG );
			lpTextMsg->TextMsgType = Type;
			break;
		case TEXTMSGTYPE_QuickTaunt:
			strncpy( &lpTextMsg->Text[0]	, &QuickText.text[0] , MAXTEXTMSG );
			lpTextMsg->TextMsgType = Type;
			break;
		case TEXTMSGTYPE_QuickTauntWhisper:
			strncpy( &lpTextMsg->Text[0]	, &QuickTextWhisper.text[0] , MAXTEXTMSG );
			lpTextMsg->TextMsgType = Type;
			break;
		case TEXTMSGTYPE_CaptureFlagMessage:
			lpTextMsg->TextMsgType = Type;
			strncpy( &lpTextMsg->Text[0]	, CTFMessage , MAXTEXTMSG );
			PlaySfx( SFX_MyTeamGotFlag , 1.0F );
			break;
		case TEXTMSGTYPE_ScoredWithFlag:
			lpTextMsg->TextMsgType = Type;
			lpTextMsg->Text[0] = 0;
			PlaySfx( SFX_MyTeamScored, 1.0F );
			break;
		case TEXTMSGTYPE_ReturningFlag:
			lpTextMsg->TextMsgType = Type;
			if ( IsServerGame )
			{
				strncpy( &lpTextMsg->Text[0], CTFMessage , MAXTEXTMSG );
			}
			else
			{
				lpTextMsg->Text[0] = 0;
			}
			break;
		case TEXTMSGTYPE_ReturnedFlag:
			lpTextMsg->TextMsgType = Type;
			if ( IsServerGame )
			{
				strncpy( &lpTextMsg->Text[0], CTFMessage , MAXTEXTMSG );
			}
			else
			{
				lpTextMsg->Text[0] = 0;
			}
			break;
		case TEXTMSGTYPE_FlagDriftedIn:
			lpTextMsg->TextMsgType = Type;
			lpTextMsg->Text[0] = 0;
			break;
		case TEXTMSGTYPE_FlagEscaped:
			lpTextMsg->TextMsgType = Type;
			lpTextMsg->Text[0] = 0;
			break;
		case TEXTMSGTYPE_BountyMessage:
			lpTextMsg->TextMsgType = Type;
			lpTextMsg->Text[0] = 0;
			PlaySfx( SFX_MyTeamGotFlag , 1.0F );
			break;
		case TEXTMSGTYPE_SpeechTaunt:
			lpTextMsg->TextMsgType = Type;
			lpTextMsg->Text[0] = CurrentTauntVariant;
			break;
		default:
			lpTextMsg->TextMsgType = TEXTMSGTYPE_Taunt1;
		}
		// put a null at the end just in case...
		lpTextMsg->Text[MAXTEXTMSG-1] = 0;
		nBytes = sizeof( TEXTMSG );

		if (MyGameStatus != STATUS_StartingMultiplayer)
		{
			AddMessageToQue( (char*) &lpTextMsg->Text[0] );
		}
		break;

    case MSG_PINGREQUEST:

//		RequestPings();	// used for UDP pings

		lpPingMsg = (LPPINGMSG)&CommBuff[0];
        lpPingMsg->MsgCode = msg;
        lpPingMsg->WhoIAm = WhoIAm;
		QueryPerformanceCounter( (LARGE_INTEGER *) &lpPingMsg->Time);

		if( BigPackets )
		{
			QueryPerformanceCounter((LARGE_INTEGER *) &TimeFrig);
			lpPingMsg->Time += LastBigPacketSent - TimeFrig;
		}
		nBytes = sizeof( PINGMSG );
		break;
	case MSG_PLAYERPINGS:
		lpPlayerPingsMsg = (LPPLAYERPINGSMSG)&CommBuff[0];
		lpPlayerPingsMsg->MsgCode = msg;
		lpPlayerPingsMsg->WhoIAm = WhoIAm;
		memcpy( lpPlayerPingsMsg->Ping, PingTimes, sizeof( PingTimes ) );
		nBytes = sizeof( PLAYERPINGSMSG );
		break;
    case MSG_PINGREPLY:
		lpPingMsg = (LPPINGMSG)&CommBuff[0];
        lpPingMsg->MsgCode = msg;
        lpPingMsg->WhoIAm = WhoIAm;
        lpPingMsg->ToYou = Type;
        lpPingMsg->Time = PingRequestTime;
		nBytes = sizeof( PINGMSG );
		break;
    case MSG_ACKMSG:
		lpAckMsg = (LPACKMSG)&CommBuff[0];
        lpAckMsg->MsgCode = msg;
        lpAckMsg->WhoIAm = WhoIAm;
        lpAckMsg->ID = (uint32) to;
		lpAckMsg->AckTo = ShipNum;
		nBytes = sizeof( ACKMSG );
		break;
	case MSG_GAMEPARAMETERS:
		lpGameParamMsg = ( LPGAMEPARAMETERSMSG )&CommBuff[ 0 ];

        lpGameParamMsg->MsgCode = msg;
        lpGameParamMsg->WhoIAm = WhoIAm;

		lpGameParamMsg->MaxPlayers = MaxServerPlayersSlider.value; 

		strncpy( lpGameParamMsg->Level, LevelList.item[ LevelList.selected_item ], sizeof( lpGameParamMsg->Level ) );
		lpGameParamMsg->Level[ 7 ] = 0;
		lpGameParamMsg->ScoreLimit = ( uint8 )( MaxKillsSlider.value );
		MaxKills = MaxKillsSlider.value;

		lpGameParamMsg->TimeLimit =  ( uint8 )( TimeLimit.value );
		if( lpGameParamMsg->TimeLimit )
		{
			CountDownOn = TRUE;
		}
		else
		{
			CountDownOn = FALSE;
		}

		lpGameParamMsg->GameInfo = 0;
		lpGameParamMsg->GameInfo |= ( GameType << GAMEPARAM_GameTypeBitShift );
		lpGameParamMsg->GameInfo |= ( CTFSlider.value << GAMEPARAM_CTFTypeBitShift );
		if ( BikeExhausts )
		{
			lpGameParamMsg->GameInfo |= ( GAMEPARAM_BikeExhaustBit );
		}

		if( ResetKillsPerLevel )
		{
			lpGameParamMsg->GameInfo |= (GAMEPARAM_ResetKillsPerLevelBit );
		}
		if ( MyBrightShips )
		{
			lpGameParamMsg->GameInfo |= ( GAMEPARAM_BrightBikesBit );
		}
		if ( RandomPickups )
		{
			lpGameParamMsg->GameInfo |= ( GAMEPARAM_RandomisePickupsBit );
		}
		if ( BountyBonus )
		{
			lpGameParamMsg->GameInfo |= ( GAMEPARAM_BountyBonusBit );
			lpGameParamMsg->GameInfo |= ( ( BountyBonusSlider.value / 5 ) << GAMEPARAM_BountyBonusValueBitShift );
		}
		if ( HarmTeamMates )
		{
			lpGameParamMsg->GameInfo |= GAMEPARAM_HarmTeamMatesBit;
		}

		if ( ServerCollisions )
		{
			lpGameParamMsg->GameInfo |= GAMEPARAM_ServerCollisionBit;
		}

		lpGameParamMsg->GameInfo |= ( ColPerspective << GAMEPARAM_LagCompensationBitShift );

		lpGameParamMsg->GameInfo |= ( ( GoalScoreSlider.value ) << GAMEPARAM_FlagCaptureScoreBitShift );

		PackPickupInfo( lpGameParamMsg->AllowedPickups );

		lpGameParamMsg->PrimaryPickups = NumPrimaryPickups;

		nBytes = sizeof( GAMEPARAMETERSMSG );
#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0] , MSG_GAMEPARAMETERS , FALSE , TRUE);
		return;
#endif
		break;
#ifdef MANUAL_SESSIONDESC_PROPAGATE
	case MSG_SESSIONDESC:

		DebugPrintf("about to manually send session desc\n");

		lpSessionDescMsg = ( LPSESSIONDESCMSG )&CommBuff[ 0 ];

        lpSessionDescMsg->MsgCode = msg;
        lpSessionDescMsg->WhoIAm = WhoIAm;

		DPlayGetSessionDesc();

		if ( glpdpSD )
		{
			lpSessionDescMsg->dwUser1 = glpdpSD->dwUser1;
			lpSessionDescMsg->dwUser2 = glpdpSD->dwUser2;
			lpSessionDescMsg->dwUser3 = glpdpSD->dwUser3;
			lpSessionDescMsg->dwUser4 = glpdpSD->dwUser4;
		}else
		{
			return;	// no SD to send!!
		}
		nBytes = sizeof( SESSIONDESCMSG );
#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0] , MSG_SESSIONDESC , FALSE , TRUE);
		return;
#endif
		break;
#endif
	case MSG_TOSERVER:

		lpToServerMsg = ( LPTOSERVERMSG )&CommBuff[ 0 ];
		lpToServerMsg->MsgCode = msg;
		lpToServerMsg->WhoIAm = WhoIAm;
		lpToServerMsg->Type = Type;
		lpToServerMsg->Data = mask;

		nBytes = sizeof( TOSERVERMSG );
#ifdef	GUARANTEEDMESSAGES
		AddGuaranteedMessage( nBytes , (void*) &CommBuff[0] , MSG_TOSERVER , FALSE , TRUE);
		return;
#endif
		break;
	case MSG_TOCLIENT:

		send_to = to;

		lpToClientMsg = ( LPTOCLIENTMSG )&CommBuff[ 0 ];
		lpToClientMsg->MsgCode = msg;
		lpToClientMsg->WhoIAm = WhoIAm;
		lpToClientMsg->Type = Type;
		lpToClientMsg->Data = mask;

		nBytes = sizeof( TOCLIENTMSG );

		Flags |= DPSEND_GUARANTEED;

		break;
	case MSG_LEVELNAMES:

		lpLevelNamesMsg = ( LPLEVELNAMESMSG )&CommBuff[ 0 ];
		lpLevelNamesMsg->MsgCode = msg;
		lpLevelNamesMsg->WhoIAm = WhoIAm;

		lpLevelNamesMsg->TotalLevels =  LevelList.items;
		lpLevelNamesMsg->ThisBatch   = 0;

		lpLevelNamesMsg->FirstLevel = Type;

		for ( i = 0; i < MAXLEVELSPERBATCH; i++ )
		{
			if ( ( i + Type ) >= LevelList.items )	// type contains start level num for this batch
				break;

			strncpy( lpLevelNamesMsg->Level[ i ], ShortLevelNames[ i + Type ], 8 );
			lpLevelNamesMsg->Level[ i ][ 7 ] = 0;
			lpLevelNamesMsg->ThisBatch++;
		}

		nBytes = sizeof( LEVELNAMESMSG );
		break;
	case MSG_TRACKERINFO:

		lpTrackerInfoMsg = ( LPTRACKERINFOMSG )&CommBuff[ 0 ];
		lpTrackerInfoMsg->MsgCode = msg;
		lpTrackerInfoMsg->WhoIAm = WhoIAm;

        send_to = to;

		lpTrackerInfoMsg->addr = tracker_addr;
		lpTrackerInfoMsg->port = tracker_port;
		lpTrackerInfoMsg->freq = heartbeat_freq;
		lpTrackerInfoMsg->type = heartbeat_type;
		lpTrackerInfoMsg->shutdown = SendShutdownPacket;
		lpTrackerInfoMsg->gamespy = bGameSpy;

		nBytes = sizeof( TRACKERINFOMSG );

		Flags |= DPSEND_GUARANTEED;

		break;
	}

	// only record if message is sent to whole of the group....
	if( RecordDemo )
	{
		if( ( MyGameStatus == STATUS_Normal ) && !send_to
		&& ( msg != MSG_ACKMSG )
		&& ( msg != MSG_INIT ) 
		&& ( msg != MSG_HEREIAM ) 
		&& ( msg != MSG_SHORTSTATS     ) 
		&& ( msg != MSG_SHORTPICKUP    ) 
		&& ( msg != MSG_SHORTREGENSLOT ) 
		&& ( msg != MSG_SHORTTRIGGER   ) 
		&& ( msg != MSG_SHORTTRIGVAR   ) 
		&& ( msg != MSG_SHORTMINE      ) )
		{
			QueryPerformanceCounter((LARGE_INTEGER *) &TempTime);
			TempTime = TempTime - GameStartedTime;
		
			Demo_fwrite( &TempTime, sizeof(LONGLONG), 1, DemoFp );
		
			Demo_fwrite( &nBytes, sizeof(int), 1, DemoFp );
			Demo_fwrite( &dcoID, sizeof(DPID), 1, DemoFp );
			Demo_fwrite( &CommBuff[0], nBytes, 1, DemoFp );
		}
	}
	

	if( !send_to )
	{
		if( IsServer )
		{
			AddMessageToSeverQue( &CommBuff[0] );
			return;
		}else if( BigPackets )
		{
			AddToBigPacket( nBytes , &CommBuff[0] , msg );
			return;
		}
	}
	
	// Broadcast it to everyone in the group...

	if( !UseSendAsync && !IsServer )
	{
		
		hr = glpDP->lpVtbl->Send( glpDP,
								  dcoID,   // From
								  send_to, // send to everybody
								  Flags ,
								  (LPSTR)&CommBuff[0],
								  nBytes);
	}else{
		Flags |= DPSEND_ASYNC | DPSEND_NOSENDCOMPLETEMSG;
		hr = IDirectPlayX_SendEx( glpDP,
								  dcoID,   // From
								  send_to, // send to
								  Flags ,
								  (LPSTR)&CommBuff[0],
								  nBytes,
								  0,		// dwPriority
								  0,		// dwTimeout
								  NULL,		// lpContext
								  NULL		// lpdwMsgID
								  );
	}

		BytesPerSecSent += nBytes;



	if( hr != DP_OK && hr != DPERR_PENDING )
	{
		OutputDebugString( "Dplay Send Error" );
	}
#endif
}


/*�������������������������������������������������������������������
	Procedure	:		Read packet stuff from a file and pass it on..
	Input		:		nothing
	Output		:		nothing
�������������������������������������������������������������������*/

void DemoPlayingDplayGameUpdate()
{
    DWORD               nBytes;
	int i;
	size_t	size;

	while( 1 && DemoFp)
	{
		if( DemoTimeSoFar )
		{
			if( DemoTimeSoFar * FSB_COMPENSATION > GameElapsedTime )
			{
			 	if (ferror(DemoFp) || feof(DemoFp) )
				{
					fclose( DemoFp );
					DemoFp = NULL;
					SpecialDestroyGame();
					return;
				}
				return;
			}
		}else{
			size = fread( &DemoTimeSoFar , sizeof(LONGLONG), 1, DemoFp );
#ifndef SELF_PLAY
//			if( (MyGameStatus == STATUS_PlayingDemo ) && ( ( ( GameElapsedTime * 1000.0F ) / Freq ) >= (1000.0F * 60.0F * 1.0F ) ) )
			if( (MyGameStatus == STATUS_AttractMode ) && ( ( ( GameElapsedTime * 1000.0F ) / Freq ) >= (1000.0F * 60.0F * 5.0F ) ) )
				size = 0;
#endif
			if( size != 1 || ferror(DemoFp) || feof(DemoFp) ) 
			{
				PreDemoEndMyGameStatus = MyGameStatus;

#ifdef DEBUG_ON
				if( DS )
				{
					for( i = 0 ; i < 256 ; i++ )
					{
						if( PacketGot[i] )
						{
							DebugPrintf("num %3d quantity %12d size %12d\n", i, PacketGot[i] , PacketSize[i] );
						}
					}
				}

#endif
								
				QueryPerformanceCounter((LARGE_INTEGER *) &DemoEndedTime);

				fclose( DemoFp );
				DemoFp = NULL;

				SpecialDestroyGame();

				TimeDiff = DemoEndedTime - DemoStartedTime;
				DemoAvgFps = DemoGameLoops /  ( (float) TimeDiff / (float) Freq );
//				DebugPrintf("Average Demo Framrate %d.%02d\n",   (int)( DemoAvgFps * 100 ) / 100,
//															 	(int)( DemoAvgFps * 100 ) % 100 
//															 	);                       
//				DebugPrintf("In %d Gameloops\n",DemoGameLoops);
			
				
				return;
			}
	
			if( DemoTimeSoFar * FSB_COMPENSATION > GameElapsedTime )
				return;
		}
		
		fread( &nBytes , sizeof(DWORD), 1, DemoFp );
		fread( &from_dcoID , sizeof(DPID), 1, DemoFp );
		fread( &ReceiveCommBuff[0] , nBytes , 1, DemoFp );
		
		// During Demo Playback we dont want to interperate any System messages....
		if ( from_dcoID != DPID_SYSMSG ) EvaluateMessage( nBytes , &ReceiveCommBuff[0] );
		DemoTimeSoFar = 0;

  
	}
}


/*�������������������������������������������������������������������
	Procedure	:		Read packet stuff from a file if its a ship update..
						scan ahead to find the next one and write in a
						interpolate msg..
	Input		:		nothing
	Output		:		nothing
�������������������������������������������������������������������*/
void DemoClean( void )
{
    DWORD       nBytes;
	size_t		size;
	fpos_t		Currentpos; 
	LONGLONG	DemoTimeSoFar2;
	DPID		from_dcoID2;
    DWORD       nBytes2;
    LPUPDATEMSG			lpUpdate;
    LPFUPDATEMSG		lpFUpdate;
    LPVERYSHORTUPDATEMSG lpVeryShortUpdate;
    LPVERYSHORTFUPDATEMSG		lpVeryShortFUpdate;
	INTERPOLATEMSG Interpolate;
	VERYSHORTINTERPOLATEMSG VeryShortInterpolate;
	BOOL		IsShortPackets = FALSE;
	int			FoundOne;

	while(1)
	{
		size = fread( &DemoTimeSoFar , sizeof(LONGLONG), 1, DemoFp );
   		// check for end of file...
		if( !size )	return;
		fread( &nBytes , sizeof(DWORD), 1, DemoFp );
		fread( &from_dcoID , sizeof(DPID), 1, DemoFp );
		fread( &CommBuff[0] , nBytes , 1, DemoFp );

#if 0
		// Special model num correction stuff...And Power Level Stuff
		switch( CommBuff[0] )
		{
		case MSG_UPDATE:
			lpUpdate = (LPUPDATEMSG) &CommBuff[0];
			break;
		case MSG_FUPDATE:
			break;
		}
#endif
		
		// write out the message..
		fwrite( &DemoTimeSoFar, sizeof(LONGLONG), 1, DemoFpClean );
		fwrite( &nBytes, sizeof(int), 1, DemoFpClean );
		fwrite( &from_dcoID, sizeof(DPID), 1, DemoFpClean );
		fwrite( &CommBuff[0], nBytes, 1, DemoFpClean );

		if ( ( from_dcoID != DPID_SYSMSG ) && ( CommBuff[0] == MSG_INTERPOLATE ) )
		{
			// Has allready been cleaned...
			return;
		}

		// check if its an update message....
		if ( ( from_dcoID != DPID_SYSMSG ) && ( ( CommBuff[0] == MSG_UPDATE ) ||
												( CommBuff[0] == MSG_FUPDATE ) ||
												( CommBuff[0] == MSG_VERYSHORTUPDATE ) ||
												( CommBuff[0] == MSG_VERYSHORTFUPDATE ) ) )
		{
			// we have one update message we now have to search for another...
			Interpolate.MsgCode = MSG_INTERPOLATE;
			VeryShortInterpolate.MsgCode = MSG_VERYSHORTINTERPOLATE;
			switch( CommBuff[0] )
			{
			case MSG_UPDATE:
				lpUpdate = (LPUPDATEMSG) &CommBuff[0];
				Interpolate.WhoIAm = lpUpdate->WhoIAm;
				break;
			case MSG_FUPDATE:
				lpFUpdate = (LPFUPDATEMSG) &CommBuff[0];
				Interpolate.WhoIAm = lpFUpdate->WhoIAm;
				break;
			case MSG_VERYSHORTUPDATE:
				lpVeryShortUpdate = (LPVERYSHORTUPDATEMSG) &CommBuff[0];
				VeryShortInterpolate.WhoIAm = lpVeryShortUpdate->WhoIAm;
				IsShortPackets = TRUE;
				break;
			case MSG_VERYSHORTFUPDATE:
				lpVeryShortFUpdate = (LPVERYSHORTFUPDATEMSG) &CommBuff[0];
				VeryShortInterpolate.WhoIAm = lpVeryShortFUpdate->WhoIAm;
				IsShortPackets = TRUE;
				break;
			}
			fgetpos( DemoFp , &Currentpos );	// store the current position..so we can go back to it..

			FoundOne = 0;
			while( FoundOne == 0 )
			{
				size = fread( &DemoTimeSoFar2 , sizeof(LONGLONG), 1, DemoFp );
				// check for end of file...
				if( !size )
				{
					FoundOne = -1;
					break;
				}

				fread( &nBytes2 , sizeof(DWORD), 1, DemoFp );
				fread( &from_dcoID2 , sizeof(DPID), 1, DemoFp );
				fread( &CommBuff[0] , nBytes2 , 1, DemoFp );


				if ( ( from_dcoID2 != DPID_SYSMSG ) && ( ( CommBuff[0] == MSG_UPDATE ) ||
														( CommBuff[0] == MSG_FUPDATE ) ||
														( CommBuff[0] == MSG_VERYSHORTUPDATE ) ||
														( CommBuff[0] == MSG_VERYSHORTFUPDATE ) ) )
				{
					switch( CommBuff[0] )
					{
					case MSG_UPDATE:
						lpUpdate =(LPUPDATEMSG) &CommBuff[0];
						if( Interpolate.WhoIAm == lpUpdate->WhoIAm )
						{
							// found next update for this ship
							Interpolate.NextPos = lpUpdate->ShortGlobalShip.Pos;
							Interpolate.NextQuat = lpUpdate->ShortGlobalShip.Quat;
#ifdef	SHORTBANK
							Interpolate.NextBank	= (float) (lpUpdate->ShortGlobalShip.Bank / SHORTBANKMODIFIER);
#else
							Interpolate.NextBank	= lpUpdate->ShortGlobalShip.Bank;
#endif
							Interpolate.NextTime = DemoTimeSoFar2;
							FoundOne = 1;
						}
						break;
					case MSG_FUPDATE:
						lpFUpdate = (LPFUPDATEMSG) &CommBuff[0];
						if( Interpolate.WhoIAm == lpFUpdate->WhoIAm )
						{
							// found next update for this ship
							Interpolate.NextPos = lpFUpdate->ShortGlobalShip.Pos;
							Interpolate.NextQuat = lpFUpdate->ShortGlobalShip.Quat;
#ifdef	SHORTBANK
							Interpolate.NextBank	= (float) (lpFUpdate->ShortGlobalShip.Bank / SHORTBANKMODIFIER);
#else
							Interpolate.NextBank	= lpFUpdate->ShortGlobalShip.Bank;
#endif
							Interpolate.NextTime = DemoTimeSoFar2;
							FoundOne = 1;
						}
						break;
					case MSG_VERYSHORTUPDATE:
						lpVeryShortUpdate =(LPVERYSHORTUPDATEMSG) &CommBuff[0];
						if( VeryShortInterpolate.WhoIAm == lpVeryShortUpdate->WhoIAm )
						{
							// found next update for this ship
							VeryShortInterpolate.NextPos = lpVeryShortUpdate->ShortGlobalShip.Pos;
							VeryShortInterpolate.NextQuat	= lpVeryShortUpdate->ShortGlobalShip.Quat;
							VeryShortInterpolate.NextBank	= lpVeryShortUpdate->ShortGlobalShip.Bank;
							VeryShortInterpolate.NextTime = DemoTimeSoFar2;
							FoundOne = 1;
						}
						break;
					case MSG_VERYSHORTFUPDATE:
						lpVeryShortFUpdate = (LPVERYSHORTFUPDATEMSG) &CommBuff[0];
						if( VeryShortInterpolate.WhoIAm == lpVeryShortFUpdate->WhoIAm )
						{
							// found next update for this ship
							VeryShortInterpolate.NextPos = lpVeryShortFUpdate->ShortGlobalShip.Pos;
							VeryShortInterpolate.NextQuat	= lpVeryShortFUpdate->ShortGlobalShip.Quat;
							VeryShortInterpolate.NextBank	= lpVeryShortFUpdate->ShortGlobalShip.Bank;
							VeryShortInterpolate.NextTime = DemoTimeSoFar2;
							FoundOne = 1;
						}
						break;
					}
				}
			}
			if( FoundOne == 1 )
			{
				if( !IsShortPackets )
				{
					fwrite( &DemoTimeSoFar, sizeof(LONGLONG), 1, DemoFpClean );
					nBytes = sizeof( INTERPOLATEMSG );
					fwrite( &nBytes, sizeof(int), 1, DemoFpClean );
					fwrite( &from_dcoID, sizeof(DPID), 1, DemoFpClean );
					fwrite( &Interpolate, nBytes, 1, DemoFpClean );
				}else{
					fwrite( &DemoTimeSoFar, sizeof(LONGLONG), 1, DemoFpClean );
					nBytes = sizeof( VERYSHORTINTERPOLATEMSG );
					fwrite( &nBytes, sizeof(int), 1, DemoFpClean );
					fwrite( &from_dcoID, sizeof(DPID), 1, DemoFpClean );
					fwrite( &VeryShortInterpolate, nBytes, 1, DemoFpClean );
				}
			}
			// set the position of the file back...
			fsetpos( DemoFp , &Currentpos );
		}
	}
	
}

/*�������������������������������������������������������������������
	Procedure	:		Create a regen effect...
	Input		:		uint16 ship....
	Output		:		nothing
�������������������������������������������������������������������*/


void CreateReGen( uint16 ship )
{
	uint16	Model;

	if( ship == WhoIAm )
	{
		if ( !Random_Range( 4 ) )
			PlaySfxWithTrigger( SFX_PlayerGenerate, SFX_BIKER_GP );
		else
			PlaySfx( SFX_PlayerGenerate, 1.0F );
	}else{
		PlayPannedSfx( SFX_PlayerGenerate, Ships[ ship ].Object.Group , &Ships[ ship ].Object.Pos, 0.0F );
	}

	Model =	FindFreeModel();
	if( Model != (uint16 ) -1 )
	{
		Models[ Model ].OwnerType = OWNER_SHIP;
		Models[ Model ].Owner = ship;
		Models[ Model ].ModelNum = MODEL_Sphere;
		Models[ Model ].Type = MODTYPE_Field;
		Models[ Model ].Flags = MODFLAG_Nothing;
		Models[ Model ].Visible = TRUE;
		Models[ Model ].Pos = Ships[ship].Object.Pos;
		Models[ Model ].Mat = MATRIX_Identity;
		MatrixTranspose( &Models[ Model ].Mat, &Models[ Model ].InvMat );
		Models[ Model ].Func = MODFUNC_Regen;
		Models[ Model ].MaxScale = 2.0F;
		Models[ Model ].Scale = 1.0F;
		Models[ Model ].Group = Ships[ship].Object.Group;
		Models[ Model ].LifeCount = 600.0F;
	}
}
/*�������������������������������������������������������������������
	Procedure	:		Ping all other players guarenteed...
	Input		:		nothing
	Output		:		nothing
�������������������������������������������������������������������*/
void PingGuarenteed(void)
{
	if ( IsServerGame && !IsServer )	// server will send me ping times if server game
		return;

	SendGameMessage( MSG_PINGREQUEST , 0, 0, 1, 0 );
}
/*�������������������������������������������������������������������
	Procedure	:		Ping all other players non-guarenteed...
	Input		:		nothing
	Output		:		nothing
�������������������������������������������������������������������*/
void PingNonGuarenteed(void)
{
	if ( IsServerGame && !IsServer )	// server will send me ping times if server game
		return;

	SendGameMessage( MSG_PINGREQUEST , 0, 0, 0, 0 );
}



/*�������������������������������������������������������������������
	Procedure	:		FindSameLevel....
	Input		:		char * Name
	Output		:		int -1 no level....
�������������������������������������������������������������������*/
int FindSameLevel( char * Name )
{
	int i;
    for (i = 0; i < NumLevels; i++)
	{
		if( _stricmp( (char*) &ShortLevelNames[i][0] , Name ) == 0 ) 
		{
			return i;
		}
    }
	return -1;
}



#define DEMORAMBUFFERSIZE ( 1024 * 1024 * 6 )
char * DemoRamBuffer = NULL;
int		DemoRamBufferCurrentSize = 0;

/*�������������������������������������������������������������������
	Procedure	:		X_fwrite....Writes out some info to a predetermined place
				:		either to a file or ram.....
	Input		:		const void *buffer, size_t size, size_t count
	Output		:		int -1 no level....
�������������������������������������������������������������������*/
void Demo_fwrite( const void *buffer, size_t size, size_t count , FILE *stream )
{
	char * charpnt;
	char * charpnt2;
	size_t i,e;

	if( !RecordDemo || !DemoFp )
		return;

	if( RecordDemoToRam )
	{
		if( !DemoRamBuffer )
		{
			DemoRamBuffer = (char*) malloc(DEMORAMBUFFERSIZE);
			if( !DemoRamBuffer )
			{
				Msg( "Couldnt Malloc Demo Ram Buffer.\n" );
				RecordDemo = FALSE;
				return;
			}
			DemoRamBufferCurrentSize = 0;
		}
		if( (DemoRamBufferCurrentSize + (size * count) ) > DEMORAMBUFFERSIZE )
			return;
		charpnt = DemoRamBuffer + DemoRamBufferCurrentSize;
		charpnt2 = (char*) buffer;

		for( e = 0 ; e < count ; e++ )
		{
			for( i = 0 ; i < size ; i++ )
			{
				*charpnt++ = *charpnt2++;
			}
		}
		DemoRamBufferCurrentSize += (size * count);
	}else{
		fwrite( buffer, size , count , stream );
	}
}


/*�������������������������������������������������������������������
	Procedure	:		StopDemoRecording
	Input		:		char * Name
	Output		:		int -1 no level....
�������������������������������������������������������������������*/
void StopDemoRecording( void )
{

	if( DemoFp && RecordDemoToRam && DemoRamBuffer )
	{
		fwrite( DemoRamBuffer, DemoRamBufferCurrentSize, 1, DemoFp );
		RecordDemoToRam = FALSE;
	}
	if( DemoFp )	// make sure that changing level stop any demo from recording!!!!
	{
		fclose( DemoFp );
		DemoFp = NULL;
		RecordDemo = FALSE;
		PlayDemo = FALSE;
	}
	if( DemoRamBuffer )
	{
		free(DemoRamBuffer);
		DemoRamBuffer = NULL;
	}
}

/*�������������������������������������������������������������������
	Procedure	:		Add Guaranteed Message...
	Input		:		int MessageLength, void * Message
	Output		:		BOOL TRUE/FALSE
�������������������������������������������������������������������*/
BOOL AddGuaranteedMessage( int MessageLength , void * Message , BYTE MsgType, BOOL OverideOlderMessage, BOOL AllPlayers )
{
#ifdef	GUARANTEEDMESSAGES
	GUARANTEEDMSGHEADER * GM = NULL;
	GUARANTEEDMSGHEADER * GM2 = NULL;
	GUARANTEEDMSGHEADER * LastGM;
	GUARANTEEDMSG * GMm;
	DWORD send_to = 0;
	LPYOUQUITMSG			lpYouQuitMsg;


	uint32 Ack;
	int i;

	if( PlayDemo )
		return TRUE;

	// only record if message is sent to whole of the group....
	if( RecordDemo )
	{
		if( ( MyGameStatus == STATUS_Normal )
		&& ( MsgType != MSG_INIT ) 
		&& ( MsgType != MSG_HEREIAM ) 
		&& ( MsgType != MSG_SHORTSTATS     ) 
		&& ( MsgType != MSG_SHORTPICKUP    ) 
		&& ( MsgType != MSG_SHORTREGENSLOT ) 
		&& ( MsgType != MSG_SHORTTRIGGER   ) 
		&& ( MsgType != MSG_SHORTTRIGVAR   )  
		&& ( MsgType != MSG_LEVELNAMES     )  
		&& ( MsgType != MSG_TRACKERINFO    )  
		&& ( MsgType != MSG_SHORTMINE      ) )
		{
			QueryPerformanceCounter((LARGE_INTEGER *) &TempTime);
			TempTime = TempTime - GameStartedTime;
		
			Demo_fwrite( &TempTime, sizeof(LONGLONG), 1, DemoFp );
		
			Demo_fwrite( &MessageLength, sizeof(int), 1, DemoFp );
			Demo_fwrite( &dcoID, sizeof(DPID), 1, DemoFp );
			Demo_fwrite( Message, MessageLength, 1, DemoFp );
		}
	}

	if( OverideOlderMessage )
	{
		// Try and find a message of the same type that has allready been qued and overide it...
		GM2 = GMs;
		while( GM2 )
		{
			if( MsgType == GM2->MsgType )
			{
				GM = GM2;
				break;
			}
			GM2 = GM2->Next;
		}
	}

	if( !GM )
	{
		GM = (GUARANTEEDMSGHEADER*) malloc( sizeof(GUARANTEEDMSGHEADER) + MessageLength + sizeof( GUARANTEEDMSG ) -1 );
		if( !GM )
		{
			return FALSE;
		}

		GuaranteedMessagesActive++;
		if( GuaranteedMessagesActive > GuaranteedMessagesActiveMax )
			GuaranteedMessagesActiveMax = GuaranteedMessagesActive;

		LastGM = GMs;
		if( LastGM )
		{
			LastGM->Prev = GM;
		}
		GM->Next = LastGM;
		GM->Prev = NULL;

		GMs = GM;
		if( !OldestGMs )
			OldestGMs = GM;


	}


	GMm = (GUARANTEEDMSG*) &GM->Message;
	memcpy( &GMm->StartOfMessage, Message, MessageLength );

	GM->MsgType = MsgType;

	QueryPerformanceCounter((LARGE_INTEGER *) &GM->Time);
	QueryPerformanceCounter((LARGE_INTEGER *) &GM->OverallTime);

	GM->ID = GuaranteedMessagesID++;
	GM->OverideOlderMessage = OverideOlderMessage;
	GM->AllPlayers = AllPlayers;
	GM->Count = 0;


	if( MsgType == MSG_YOUQUIT )
	{
		lpYouQuitMsg = (LPYOUQUITMSG) Message;
		Ack = 1 << lpYouQuitMsg->You;
		GM->OverallTime += Freq * 60 * GuaranteedMessagesOverallTime;
	}else{
		GM->OverallTime += Freq * GuaranteedMessagesOverallTime;
		if( AllPlayers )
		{
			Ack = 0xffffffff;
			Ack &= ~(1<<WhoIAm);
		}else{
			Ack = 0;
			for( i = 0 ; i < MAX_PLAYERS ; i++ )
			{
				if(
				  ( (GameStatus[i]!=STATUS_GetPlayerNum)&& (GameStatus[i]!=STATUS_LeftCrashed) && (GameStatus[i]!=STATUS_Left) && (GameStatus[i]!=STATUS_Null) ) &&
				  (i!=WhoIAm) )
				{
					Ack |= 1<<i;
				}
			}
		}
	}
	GM->Ack = Ack;
	GM->MessageLength = MessageLength + sizeof( GUARANTEEDMSG ) -1;
#endif
	return TRUE;
}



/*�������������������������������������������������������������������
	Procedure	:		Process Qued Guaranteed Messages...
	Input		:		BOOL True == Flush all of them.....
	Output		:		void
�������������������������������������������������������������������*/
void ProcessGuaranteedMessages( BOOL ReleaseMessages , BOOL IgnoreTime , BOOL SendGuaranteed )
{
#ifdef	GUARANTEEDMESSAGES
	GUARANTEEDMSGHEADER * GM;
	GUARANTEEDMSGHEADER * OldGM;
	GUARANTEEDMSGHEADER * NextGM;
	GUARANTEEDMSGHEADER * PrevGM;
	GUARANTEEDMSG * GMm;
	HRESULT				hr;
    DWORD				send_to = 0;
	DWORD				Flags = 0;
	int i;

	if( SendGuaranteed )
	{
		Flags |= DPSEND_GUARANTEED;
	}

	QueryPerformanceCounter((LARGE_INTEGER *) &TempTime);
//	GM = GMs;
	GM = OldestGMs;
	while( GM )
	{
//		OldGM = GM->Next;
		OldGM = GM->Prev;

		if( !GM->Ack || ( (GM->OverallTime < TempTime) && (GM->Count >= GuaranteedMessagesOverallTime ) ) || !glpDP || PlayDemo || ReleaseMessages )
		{
			// This message is past it.....
			if( GM->Ack )
			{
				for( i = 0 ; i < MAX_PLAYERS ; i++ )
				{
					if( GM->Ack & ( 1 << i ) )
					{
						BadConnection[i] = TRUE;


						if( !ReleaseMessages )
						{
							if( IsServerGame && !IsServer )
							{
								DebugPrintf( "Guaranteed %x Message Didnt Get Through to the Server\n" , GM->MsgType );
							}else{
								if( IsServer )
								{
									if( ( (GameStatus[i]!=STATUS_GetPlayerNum)&& (GameStatus[i]!=STATUS_LeftCrashed) && (GameStatus[i]!=STATUS_Left) && (GameStatus[i]!=STATUS_Null) ) &&
										(i!=WhoIAm) )
									{
										DebugPrintf( "Legal %x Player didnt ack a Guaranteed %x Message\n" , i, GM->MsgType );
									}
								}
							}
						}

					}
				}
			}
			NextGM = GM->Next;
			PrevGM = GM->Prev;
			if( GM == GMs )
			{
				GMs = NextGM;
			}
			if( NextGM )
			{
				NextGM->Prev = PrevGM;
			}
			if( PrevGM )
			{
				PrevGM->Next = NextGM;
			}
			if( GM == OldestGMs )
				OldestGMs = PrevGM;

			free( GM );
			GuaranteedMessagesActive--;
		}else{
			if( GM->Time < TempTime || IgnoreTime )
			{
				//Time to re-send....
				GM->Time = TempTime + (GuaranteedMessagesTime*Freq);

				GMm = (GUARANTEEDMSG*) &GM->Message;
				GMm->MsgCode = MSG_GUARANTEEDMSG;
				GMm->WhoIAm = WhoIAm;
				GMm->Ack = GM->Ack;		// Tell Which players this message applies to...
				GMm->ID = GM->ID;		// Tell Them the ID of the message...
				GMm->AllPlayers = GM->AllPlayers;
				GMm->OverideOlderMessage = GM->OverideOlderMessage;
				GMm->Count = GM->Count++;


				if( IsServer && !SendGuaranteed)
				{
					GlobalFramelagAddition = 0.0F;
					AddMessageToSeverQue( &GM->Message );
				}else if( BigPackets && !SendGuaranteed )
				{
					AddToBigPacket( GM->MessageLength , &GM->Message , MSG_GUARANTEEDMSG);
				}else
				{


					if( !UseSendAsync || SendGuaranteed )
					{
						
						hr = glpDP->lpVtbl->Send( glpDP,
												  dcoID,   // From
												  send_to, // send to everybody
												  Flags ,
												  &GM->Message,
												  GM->MessageLength);
					}else{
						Flags |= DPSEND_ASYNC | DPSEND_NOSENDCOMPLETEMSG;
						hr = IDirectPlayX_SendEx( glpDP,
												  dcoID,   // From
												  send_to, // send to
												  Flags ,
												  &GM->Message,
												  GM->MessageLength,
												  0,		// dwPriority
												  0,		// dwTimeout
												  NULL,		// lpContext
												  NULL		// lpdwMsgID
												  );
					}


					if( hr != DP_OK && hr != DPERR_PENDING )
					{
						OutputDebugString( "Dplay Send Error" );
					}
				}

			}
		}
		GM = OldGM;
	}
#endif
}
/*�������������������������������������������������������������������
	Procedure	:		Remove 1 player from a qued Guaranteed message...
	Input		:		uint32 ID, uint32 Player
	Output		:		BOOL TRUE/FALSE
�������������������������������������������������������������������*/
void AcknowledgeMessage( uint32 ID , uint32 Player , BYTE PlayerNum )
{
#ifdef	GUARANTEEDMESSAGES
	GUARANTEEDMSGHEADER * GM;
	GM = GMs;
	while( GM )
	{
		if( ID == GM->ID )
		{
			if( IsServerGame && !IsServer )
			{
				GM->Ack = 0;
			}else{
				GM->Ack &= ~Player;
			}
			BadConnection[PlayerNum] = FALSE;
			return;
		}
		GM = GM->Next;
	}
#endif
}


#ifdef	GUARANTEEDMESSAGES
#define	MAXACKGUARANTEEDMSGS 4096
typedef struct ACKGUARANTEEDMSGHEADER
{
	uint32		ID;
struct ACKGUARANTEEDMSGHEADER * Next;
	LONGLONG	Time;
}ACKGUARANTEEDMSGHEADER, *LPACKGUARANTEEDMSGHEADER;

ACKGUARANTEEDMSGHEADER AckMsgs[MAXACKGUARANTEEDMSGS];
ACKGUARANTEEDMSGHEADER * FirstFreeAckMsg = NULL;
ACKGUARANTEEDMSGHEADER * FirstUsedAckMsg[MAX_PLAYERS];
int AckMsgsActive = 0;
int AckMsgsActiveMax = 0;
#endif

/*�������������������������������������������������������������������
	Procedure	:		InitAckMsgQue
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
void InitAcknowledgeMessageQue( void )
{
#ifdef	GUARANTEEDMESSAGES
	int i;
	for( i = 0 ; i < MAXACKGUARANTEEDMSGS ; i++ )
	{
		AckMsgs[i].Time = 0;
		AckMsgs[i].ID = 0;
		if( i < MAXACKGUARANTEEDMSGS-1 )
		{
			AckMsgs[i].Next = &AckMsgs[i+1];
		}else{
			AckMsgs[i].Next = NULL;
		}
	}
	FirstFreeAckMsg = &AckMsgs[0];
	for( i = 0 ; i < MAX_PLAYERS ; i++ )
	{
		FirstUsedAckMsg[i] = NULL;
	}
	AckMsgsActive = 0;
	AckMsgsActiveMax = 0;

#endif
}


/*�������������������������������������������������������������������
	Procedure	:		Free All players AckMsgQue
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
void FreeAllPlayersAcknowledgeMessageQue( BYTE Player )
{
#ifdef	GUARANTEEDMESSAGES
	ACKGUARANTEEDMSGHEADER * AckMsg;
	ACKGUARANTEEDMSGHEADER * NextAckMsg;
	AckMsg = FirstUsedAckMsg[Player];
	while( AckMsg )
	{
		AckMsgsActive--;

		NextAckMsg = AckMsg->Next;
		AckMsg->Next = FirstFreeAckMsg;
		FirstFreeAckMsg = AckMsg;
		AckMsg = NextAckMsg;
	}
	FirstUsedAckMsg[Player] = NULL;
#endif
}
/*�������������������������������������������������������������������
	Procedure	:		Free All players AckMsgQue Based on time..
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
void FreeTimedOutAllPlayersAcknowledgeMessageQue( BYTE Player , LONGLONG Time )
{
#ifdef	GUARANTEEDMESSAGES
	ACKGUARANTEEDMSGHEADER * AckMsg;
	ACKGUARANTEEDMSGHEADER * NextAckMsg;
	ACKGUARANTEEDMSGHEADER * LastAckMsg = NULL;
	AckMsg = FirstUsedAckMsg[Player];
	while( AckMsg )
	{
		NextAckMsg = AckMsg->Next;
		if( Time > AckMsg->Time )
		{
			// We found 1 that is out of time all the remaining will be out of time...
			break;
		}
		LastAckMsg = AckMsg;
		AckMsg = NextAckMsg;
	}

	if( AckMsg && LastAckMsg )
		// the last legal one doesnt have any more to follow...
		LastAckMsg->Next = NULL;
	
	while( AckMsg )
	{
		NextAckMsg = AckMsg->Next;
		AckMsgsActive--;
		AckMsg->Next = FirstFreeAckMsg;
		FirstFreeAckMsg = AckMsg;
		if( AckMsg == FirstUsedAckMsg[Player] )
		{
			FirstUsedAckMsg[Player] = NextAckMsg;
		}
		AckMsg = NextAckMsg;
	}


#endif
}
/*�������������������������������������������������������������������
	Procedure	:		ProcessAckMsgQue
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
void ProcessAcknowledgeMessageQue( void )
{
#ifdef	GUARANTEEDMESSAGES
	BYTE i;

	for( i = 0 ; i < MAX_PLAYERS ; i++ )
	{
		if( PlayDemo )
		{
			FreeTimedOutAllPlayersAcknowledgeMessageQue( i , GameElapsedTime );
		}else{
			QueryPerformanceCounter((LARGE_INTEGER *) &TempTime);
			FreeTimedOutAllPlayersAcknowledgeMessageQue( i , TempTime );
		}
	}
#endif
}

/*�������������������������������������������������������������������
	Procedure	:		Find Free players AckMsgQue
	Input		:		BYTE Player
	Output		:		ACKGUARANTEEDMSGHEADER *
�������������������������������������������������������������������*/
ACKGUARANTEEDMSGHEADER * FindFreeAcknowledgeMessageQue( BYTE Player )
{
#ifdef	GUARANTEEDMESSAGES
	ACKGUARANTEEDMSGHEADER * AckMsg;
	AckMsg = FirstFreeAckMsg;
	if( AckMsg )
	{
		FirstFreeAckMsg = AckMsg->Next;
		AckMsg->Next = FirstUsedAckMsg[Player];
		FirstUsedAckMsg[Player] = AckMsg;
		AckMsgsActive++;
	}
	return AckMsg;
#endif
}


/*�������������������������������������������������������������������
	Procedure	:		Compare AckMsgQue
	Input		:		BYTE Player , uint32 ID
	Output		:		void
�������������������������������������������������������������������*/
BOOL CompareAcknowledgeMessageQue( BYTE Player , uint32 ID)
{
#ifdef	GUARANTEEDMESSAGES
	ACKGUARANTEEDMSGHEADER * AckMsg;
	AckMsg = FirstUsedAckMsg[Player];
	while( AckMsg )
	{
		if( AckMsg->ID == ID )
			return TRUE;
		AckMsg = AckMsg->Next;
	}
#endif
	return FALSE;
}

/*�������������������������������������������������������������������
	Procedure	:		Add a Message To players AckMsgQue
	Input		:		BYTE Player
	Output		:		BOOL FALSE if we have got this message before or the Que is full...
�������������������������������������������������������������������*/
BOOL AddAcknowledgeMessageQue( BYTE Player , uint32 ID )
{
#ifdef	GUARANTEEDMESSAGES
	ACKGUARANTEEDMSGHEADER * AckMsg;

	if( CompareAcknowledgeMessageQue( Player , ID) )
		return FALSE;

	AckMsg = FindFreeAcknowledgeMessageQue( Player );

	if( AckMsg )
	{
		AckMsg->ID = ID;
		if( PlayDemo )
		{
			AckMsg->Time = GameElapsedTime + ( ((LONGLONG)(GuaranteedMessagesOverallTime) * 2) * Freq );
		}else{
			QueryPerformanceCounter((LARGE_INTEGER *) &TempTime);
			AckMsg->Time = TempTime + ( ((LONGLONG)(GuaranteedMessagesOverallTime) * 2) * Freq );
		}
		if( AckMsgsActive > AckMsgsActiveMax )
		{
			AckMsgsActiveMax = AckMsgsActive;
			if( AckMsgsActiveMax >= (MAXACKGUARANTEEDMSGS *0.95F) )
			{
	   			AddMessageToQue( "Ninety Five Percent of the AckMsgQue is full!" );
			}
		}
		return TRUE;
	}
#endif
	return FALSE;
}

/*�������������������������������������������������������������������
	Procedure	:		Build Ship Flags...
	Input		:		BYTE Player
	Output		:		uint32 Flags
�������������������������������������������������������������������*/
uint32 BuildShipFlags( BYTE Player )
{
	uint32 Flags;

	Flags = Ships[Player].Object.Flags;    // Flags

	Flags &= ~( SHIP_IsHost + SHIP_Enable + SHIP_Invul + SHIP_PowerLevelBit1+SHIP_PowerLevelBit2 + SHIP_ModeBit1 + SHIP_ModeBit2 +
				SHIP_Shield + SHIP_HullBit1+SHIP_HullBit2 + SHIP_NumMultiplesBit1 + SHIP_NumMultiplesBit2 + SHIP_NumMultiplesBit3 + SHIP_NumMultiplesBit4 );
	if( IsHost ) Flags |= SHIP_IsHost;
	if( Ships[ Player ].enable ) Flags |= SHIP_Enable;
	if( Ships[Player].InvulTimer ) Flags |= SHIP_Invul;
	Flags |= (Ships[Player].Object.PowerLevel&3) << SHIP_PowerLevel_Bit1;
	Flags |= (Ships[Player].Object.Mode&3) << SHIP_Mode_Bit1;
	if( Ships[Player].Object.Shield > 0.0F )
	{
		Flags |= SHIP_Shield;
	}
	if( Ships[Player].Object.Hull > 64.0F )
	{
		Flags |= SHIP_HullBit1+SHIP_HullBit2;
	}else{
		Flags |= ( (uint32) ( Ships[Player].Object.Hull * (1.0F/16.0F) ) ) << SHIP_Hull_Bit1;
	}
	Flags |= (Ships[ Player ].NumMultiples&15) << SHIP_NumMultiples_Bit1;
	return Flags;
}



/*�������������������������������������������������������������������
	Procedure	:		Build Ship Flags...
	Input		:		BYTE Player
	Output		:		uint32 Flags
�������������������������������������������������������������������*/
void UnPackShipFlags( BYTE Player , uint32 Flags )
{
	Ships[ Player ].Object.Flags = Flags;
	if( ( Flags & SHIP_Enable ) ) Ships[ Player ].enable = 1;
	else Ships[ Player ].enable = 0;
	if( ( Flags & SHIP_Invul ) ) Ships[ Player ].Invul = TRUE;
	else Ships[ Player ].Invul = FALSE;

	Ships[Player].Object.PowerLevel = (int16)((Flags >> SHIP_PowerLevel_Bit1 ) & 3);
	Ships[Player].Object.Mode = (BYTE)((Flags >> SHIP_Mode_Bit1 ) & 3);

	if( !IsServer && !IsServerGame )
	{
		if( ( Flags & SHIP_Shield ) ) Ships[ Player ].Object.Shield = 1.0F;
		else Ships[ Player ].Object.Shield = 0.0F;
	 	Ships[Player].Object.Hull = ( ( (Flags>>SHIP_Hull_Bit1) & 3 ) + 1 ) * 16.0F;
	}

	Ships[Player].NumMultiples = (BYTE)((Flags >> SHIP_NumMultiples_Bit1 ) & 15);
}


/*�������������������������������������������������������������������
	Procedure	:		Add a packet to the Big one...
	Input		:		BYTE Player
	Output		:		uint32 Flags
�������������������������������������������������������������������*/
void AddToBigPacket( int MessageLength , void * Message , BYTE MsgType)
{
    DWORD       nBytes;

	if( IsServer )
	{
		GlobalFramelagAddition = 0.0F;
		AddMessageToSeverQue( Message );
		return;
	}

	if( RecordDemo && MyGameStatus == STATUS_Normal && MsgType != MSG_GUARANTEEDMSG)
	{
		QueryPerformanceCounter((LARGE_INTEGER *) &TempTime);
		nBytes = MessageLength;
		TempTime = TempTime - GameStartedTime;
		Demo_fwrite( &TempTime, sizeof(LONGLONG), 1, DemoFp );
		Demo_fwrite( &nBytes, sizeof(int), 1, DemoFp );
		Demo_fwrite( &dcoID, sizeof(DPID), 1, DemoFp );
		Demo_fwrite( Message, nBytes, 1, DemoFp );
	}
	
	if( ( (BigPacketOffset+MessageLength+sizeof(float) ) >= (BIGPACKETBUFFERSIZE-1) ) ||
		(NumOfPacketsInBigPacket >= MAXPACKETSPERBIGPACKET-1) )
		SendBigPacket(FALSE);

	BigPacketOffsets[NumOfPacketsInBigPacket] = BigPacketOffset;
	BigPacketSizes[NumOfPacketsInBigPacket] = MessageLength;
	QueryPerformanceCounter((LARGE_INTEGER *) &BigPacketTime[NumOfPacketsInBigPacket]);
	NumOfPacketsInBigPacket++;
	
	memcpy( &BigPacketCommBuff[BigPacketOffset], Message, MessageLength );
	BigPacketOffset += MessageLength + sizeof(float);
	BigPacketCommBuff[BigPacketOffset] = 0;
}

/*�������������������������������������������������������������������
	Procedure	:		Service The Big Packet...
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
void ServiceBigPacket( BOOL OverideTime )
{
	if( !glpDP || !dcoID || !BigPackets || PlayDemo )
		return;

	QueryPerformanceCounter((LARGE_INTEGER *) &TempTime);
	if( TempTime > LastBigPacketSent || OverideTime )
	{
		// the time for Sending The Big packet
		if( MyGameStatus == STATUS_Normal )
		{
			SendANormalUpdate();
			if( !IsServer && IsServerGame )
			{
				SendGameMessage( MSG_SHIELDHULL, 0, 0, 0, 0 );
			}
		}
		SendBigPacket(OverideTime);
	}
}
/*�������������������������������������������������������������������
	Procedure	:		Send Big Packet...
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
void SendBigPacket( BOOL SendGuaranteed )
{
	HRESULT				hr;
    DWORD				send_to = 0;
	DWORD				Flags = 0;
	uint32 i;
	float * FloatPnt;
	DWORD dwNumMsgs;
	BOOL throttle = TRUE;

	if( SendGuaranteed )
		Flags |= DPSEND_GUARANTEED;


	BigPacketCommBuff[0] = MSG_BIGPACKET;
	BigPacketCommBuff[1] = WhoIAm;

	QueryPerformanceCounter((LARGE_INTEGER *) &TempTime);
	if( NumOfPacketsInBigPacket )
	{
		for( i = 0 ; i < NumOfPacketsInBigPacket ; i++ )
		{
			FloatPnt = (float*) &BigPacketCommBuff[ BigPacketOffsets[i] + BigPacketSizes[i] ];
			*FloatPnt = (float) ( ((TempTime - BigPacketTime[i]) * 71) / Freq );
		}


		
		if( !UseSendAsync && !SendGuaranteed && !IsServer )
		{
			
			hr = glpDP->lpVtbl->Send( glpDP,
									  dcoID,   // From
									  send_to, // send to everybody
									  Flags ,
									  &BigPacketCommBuff[0],
									  BigPacketOffset+1);
		}else{
		
			while( throttle )
			{
				hr = IDirectPlayX_GetMessageQueue( glpDP, 0, 0, DPMESSAGEQUEUE_SEND , &dwNumMsgs, NULL );
				switch ( hr )
				{
				case DP_OK:
					if ( dwNumMsgs < 2 )
					{
						throttle = FALSE;
					}
					break;
				case DPERR_UNSUPPORTED:
					CenterPrint4x5Text( UNSUPPORTED_MSG_QUE, d3dapp->szClient.cy - FontHeight * 2, 2 );
					throttle = FALSE;
					break;
				case DPERR_INVALIDFLAGS:
				case DPERR_INVALIDPARAMS:
				case DPERR_INVALIDPLAYER:
				default:
					Msg("serious error with IDirectPlayX_GetMessageQueue ( error = %d )\n", hr );
					throttle = FALSE;

				}
//				if( throttle && MyGameStatus == STATUS_Normal )
//				{
//					CenterPrint4x5Text( "Throttle On", d3dapp->szClient.cy - FontHeight * 3, 2 );
//					D3DAppShowBackBuffer(TRUE);
//				}

			}
			Flags |= DPSEND_ASYNC | DPSEND_NOSENDCOMPLETEMSG;
			hr = IDirectPlayX_SendEx( glpDP,
									  dcoID,   // From
									  send_to, // send to
									  Flags ,
									  &BigPacketCommBuff[0],
									  BigPacketOffset+1,
									  0,		// dwPriority
									  0,		// dwTimeout
									  NULL,		// lpContext
									  NULL		// lpdwMsgID
									  );
		}
		if( hr != DP_OK && hr != DPERR_PENDING )
		{
			OutputDebugString( "Dplay Send Error" );
		}
	}

	if( !IsServer )
	{
		BigPacketSize = BigPacketOffset+1;
		if( BigPacketSize > MaxBigPacketSize )
			MaxBigPacketSize = BigPacketSize;

		BytesPerSecSent += BigPacketOffset+1;
	
	}


	BigPacketsSent = NumOfPacketsInBigPacket;
	QueryPerformanceCounter((LARGE_INTEGER *) &LastBigPacketSent);

	if( MyGameStatus == STATUS_Normal )
	{
		if( IsServer )
		{
			LastBigPacketSent += Freq / 2;
		}else{
			LastBigPacketSent += Freq / PacketsSlider.value;
		}
	}else{
		LastBigPacketSent += Freq / 2;
	}

	BigPacketOffset = 2;
	BigPacketCommBuff[2] = 0;
	NumOfPacketsInBigPacket = 0;
}

/*�������������������������������������������������������������������
	Procedure	:		Set Ship Bank and Mat..
	Input		:		OBJECT *
	Output		:		void
�������������������������������������������������������������������*/
void SetShipBankAndMat( OBJECT * ShipObjPnt )
{
	QUAT	StepQuat;
	MakeQuat( 0.0F , 0.0F , ShipObjPnt->Bank, &StepQuat );
	QuatMultiply(  &ShipObjPnt->Quat , &StepQuat , &ShipObjPnt->FinalQuat );
	QuatToMatrix( &ShipObjPnt->FinalQuat, &ShipObjPnt->FinalMat );
	MatrixTranspose( &ShipObjPnt->FinalMat, &ShipObjPnt->FinalInvMat );
}


/*�������������������������������������������������������������������
	Procedure	:		Server Stuff...
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
typedef struct SERVERMSGHEADER
{
	int			MsgLength;
struct SERVERMSGHEADER * Next;
struct SERVERMSGHEADER * Prev;
	BYTE		MsgType;
	BYTE		WhoIAm;
	float		framelag;
	BYTE		Message;		// Must be last in structure!!!!!!!!!!!!
}SERVERMSGHEADER, *LPSERVERMSGHEADER;

SERVERMSGHEADER * SMHs;
SERVERMSGHEADER * OldestSMHs;
LONGLONG	ServerUpdateTimer = 0;
SERVERMSGHEADER * TempSMH = NULL;

int ServerMessagesActive = 0;
int ServerMessagesActiveMax = 0;
int	ServerPlayersActive = 0;

DWORDLONG CurrentServerAck = 0;

void AddToServicePacket( SERVERMSGHEADER * SMH, int i );
void SendServerPacket( int i );
void KillServiceMessageHeader( SERVERMSGHEADER * SMH );
void BuildCurrentServerAck( void );
BOOL CheckIfPacketRelevant( BYTE * Message , int Player );
BOOL MakeTempSMH( void * Message );

/*�������������������������������������������������������������������
	Procedure	:		InitServerMsgQue
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
void InitServerMessageQue( void )
{
	ServerUpdateTimer = 0;
	SMHs = NULL;
	OldestSMHs = NULL;

	ServerMessagesActive = 0;
	ServerMessagesActiveMax = 0;
}
/*�������������������������������������������������������������������
	Procedure	:		InitServerMsgQue
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
void FreeServerMessageQue( void )
{
	SERVERMSGHEADER * SMH;
	SERVERMSGHEADER * NextSMH;

	ServerUpdateTimer = 0;
	OldestSMHs = NULL;
	ServerMessagesActiveMax = 0;
	SMH = SMHs;
	while( SMH )
	{
		NextSMH = SMH->Next;
		KillServiceMessageHeader( SMH );
		SMH = NextSMH;
	}
}

/*�������������������������������������������������������������������
	Procedure	:		BuildCurrentServerAck
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
void BuildCurrentServerAck( void )
{
	LONGLONG	Ack = 0;
	int i;
	ServerPlayersActive = 0;
	for( i = 0 ; i < MAX_PLAYERS ; i++ )
	{
		if(
		  ( (GameStatus[i]!=STATUS_GetPlayerNum)&& (GameStatus[i]!=STATUS_LeftCrashed) && (GameStatus[i]!=STATUS_Left) && (GameStatus[i]!=STATUS_Null) ) &&
		  (i!=WhoIAm) )
		{
			Ack |= 1<<i;
			ServerPlayersActive++;
		}
	}
	CurrentServerAck = Ack;
}



/*�������������������������������������������������������������������
	Procedure	:		Add Mesage to Server Que...
	Input		:		void * Message
	Output		:		BOOL TRUE/FALSE
�������������������������������������������������������������������*/
BOOL AddMessageToSeverQue( void * Message )
{
	SERVERMSGHEADER * SMH;
	SERVERMSGHEADER * LastSMH;
	int MsgLength;
	BYTE MsgType;
	BYTE Player;
	BYTE * BytePnt;
	LPGUARANTEEDMSG		lpGuaranteedMsg;

	if( PlayDemo || !IsServer )
		return TRUE;
	BytePnt = (BYTE*) Message;

	MsgType = *BytePnt++;
	MsgLength = RealPacketSize[MsgType];
	Player = *BytePnt;

	if( MsgType == MSG_ACKMSG && Player != WhoIAm )
		return TRUE;

	if( MsgType == MSG_GUARANTEEDMSG )
	{
		lpGuaranteedMsg = (LPGUARANTEEDMSG)Message;

		if( lpGuaranteedMsg->Count == 0 )
		{
			if( !UpdateAmmoAndValidateMessage( Message ) )
				return FALSE;
		}
		if( lpGuaranteedMsg->Ack == (uint32) (1<<WhoIAm) )
		{
			lpGuaranteedMsg->Ack = 0;
			return TRUE;
		}
		MsgLength +=  RealPacketSize[lpGuaranteedMsg->StartOfMessage] -1 ;
	}else{
		if( !UpdateAmmoAndValidateMessage( Message ) )
			return FALSE;
	}
	
	if( Player >= MAX_PLAYERS )
		return TRUE;

	SMH = (SERVERMSGHEADER*) malloc( sizeof(SERVERMSGHEADER) + MsgLength -1 );
	if( !SMH )
	{
		return FALSE;
	}

	ServerMessagesActive++;
	if( ServerMessagesActive > ServerMessagesActiveMax )
		ServerMessagesActiveMax = ServerMessagesActive;

	LastSMH = SMHs;
	if( LastSMH )
	{
		LastSMH->Prev = SMH;
	}
	SMH->Next = LastSMH;
	SMH->Prev = NULL;
	SMHs = SMH;

	if( !OldestSMHs )
	{
		OldestSMHs = SMH;
	}
	memcpy( &SMH->Message, Message, MsgLength );

	SMH->MsgType = MsgType;
	SMH->MsgLength = MsgLength;
	SMH->WhoIAm = Player;
	SMH->framelag = GlobalFramelagAddition;
	return TRUE;
}

/*�������������������������������������������������������������������
	Procedure	:		Make Temp Smh Add Mesage to Server Que...
	Input		:		void * Message
	Output		:		BOOL TRUE/FALSE
�������������������������������������������������������������������*/
BOOL MakeTempSMH( void * Message )
{
	SERVERMSGHEADER * SMH;
	int MsgLength;
	BYTE MsgType;
	BYTE Player;
	BYTE * BytePnt;

	if( PlayDemo || !IsServer )
		return TRUE;
	BytePnt = (BYTE*) Message;

	MsgType = *BytePnt++;
	MsgLength = RealPacketSize[MsgType];
	Player = *BytePnt;

	if( Player >= MAX_PLAYERS )
		return TRUE;

	SMH = (SERVERMSGHEADER*) malloc( sizeof(SERVERMSGHEADER) + MsgLength -1 );
	if( !SMH )
	{
		return FALSE;
	}
	SMH->Next = NULL;
	SMH->Prev = NULL;
	TempSMH = SMH;
	memcpy( &SMH->Message, Message, MsgLength );
	SMH->MsgType = MsgType;
	SMH->MsgLength = MsgLength;
	SMH->WhoIAm = Player;
	SMH->framelag = 0.0F;
	return TRUE;
}

/*�������������������������������������������������������������������
	Procedure	:		Kill a Service header message...
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
void KillServiceMessageHeader( SERVERMSGHEADER * SMH )
{
	SERVERMSGHEADER * PrevSMH;
	SERVERMSGHEADER * NextSMH;

	NextSMH = SMH->Next;
	PrevSMH = SMH->Prev;

	if( SMH == SMHs )
	{
		SMHs = NextSMH;
	}
	if( SMH == OldestSMHs )
	{
		OldestSMHs = PrevSMH;
	}

	if( NextSMH )
	{
		NextSMH->Prev = PrevSMH;
	}
	if( PrevSMH )
	{
		PrevSMH->Next = NextSMH;
	}
	free( SMH );
	ServerMessagesActive--;
}

SERVERUPDATEMSG ServerUpdateMessage;

#define SERVER_MAX_MESSAGES_IN_QUE 1

extern SLIDER ThrottleSlider;
DWORD MaxPacketsInQue = 0;

/*�������������������������������������������������������������������
	Procedure	:		Service The Server...
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
void ServiceServer( BOOL OverideTime )
{
	int i,e;
	int ServerPlayersActiveTemp = 0;
	SERVERMSGHEADER * SMH;
	SERVERMSGHEADER * PrevSMH;
	//char buf[ 128 ];

	if( !glpDP || !dcoID || PlayDemo || !IsServer )
		return;
	BuildCurrentServerAck();

	ServerUpdateMessage.MsgCode = MSG_SERVERUPDATE;
	ServerUpdateMessage.WhoIAm = WhoIAm;

	GameStatus[WhoIAm] = MyGameStatus;

	QueryPerformanceCounter((LARGE_INTEGER *) &TempTime);

	if( ( TempTime > ServerUpdateTimer ) || OverideTime )
	{
		DWORD dwNumMsgs;
		HRESULT hr;
		BOOL throttle = FALSE;
		
		hr = IDirectPlayX_GetMessageQueue( glpDP, 0, 0, DPMESSAGEQUEUE_SEND , &dwNumMsgs, NULL );
		switch ( hr )
		{
		case DP_OK:
			if ( dwNumMsgs > (DWORD)ThrottleSlider.value )
			{
				if ( dwNumMsgs > MaxPacketsInQue )
				{
					MaxPacketsInQue = dwNumMsgs;
				}
				throttle = TRUE;
			}
			break;
		case DPERR_UNSUPPORTED:
			CenterPrint4x5Text( UNSUPPORTED_MSG_QUE, d3dapp->szClient.cy - FontHeight * 2, 2 );
			break;
		case DPERR_INVALIDFLAGS:
		case DPERR_INVALIDPARAMS:
		case DPERR_INVALIDPLAYER:
		default:
			Msg("serious error with IDirectPlayX_GetMessageQueue ( error = %d )\n", hr );
		}
		
		if ( !throttle )
		{
			for( i = 0 ; i < MAX_PLAYERS ; i ++ )
			{
				if( (GameStatus[i]!=STATUS_GetPlayerNum) &&
					(GameStatus[i]!=STATUS_LeftCrashed) &&
					(GameStatus[i]!=STATUS_Left) &&
					(GameStatus[i]!=STATUS_Null) )
				{

					// run through all the packets that have been sent to the server and check if player(i) has been sent it yet
					// if he hasnt add it to the bigpacket and send when necessary...
					// also check that the message still needs to be sent to someone...if it doesnt kill it off...
					ServerUpdateMessage.Players = 0;
					
					SMH = OldestSMHs;
					while( SMH )
					{
						PrevSMH = SMH->Prev;
						if( (SMH->WhoIAm != i) && (i!=WhoIAm) )
						{
							if( CheckIfPacketRelevant( &SMH->Message , i ) )
							{
								AddToServicePacket( SMH, i );
							}
						}
						SMH = PrevSMH;
					}
					if( i !=WhoIAm )
					{
						for( e = 0 ; e < MAX_PLAYERS ; e++ )
						{
							ServerUpdateMessage.Status[e] = GameStatus[e];

							if( (GameStatus[e]!=STATUS_GetPlayerNum) &&
								(GameStatus[e]!=STATUS_LeftCrashed) &&
								(GameStatus[e]!=STATUS_Left) &&
								(GameStatus[e]!=STATUS_Null) && Ships[e].enable )
							{
								if( (MyGameStatus != STATUS_Normal) || VisibleOverlap( Ships[ i ].Object.Group, Ships[ e ].Object.Group, NULL ) )
								{
										ServerUpdateMessage.Players |= 1 << e;
								}else{
									ServerUpdateMessage.Group[e] = (BYTE) Ships[e].RealGroup;
								}
							}
						}

						ServerUpdateMessage.Players &= ~1;
						MakeTempSMH( (void *) &ServerUpdateMessage );
						AddToServicePacket( TempSMH, i );
						SendServerPacket( i );
						free(TempSMH);
						TempSMH = NULL;
					}
					ServerPlayersActiveTemp++;
				}
			}
			if( MyGameStatus == STATUS_Normal )
			{
				ServerUpdateTimer = TempTime + ( Freq / PacketsSlider.value );
			}else{
				ServerUpdateTimer = TempTime + ( Freq / 2 );
			}
			// Clear out all message from the que as they have been sent to everyone...
			SMH = OldestSMHs;
			while( SMH )
			{
				PrevSMH = SMH->Prev;
				KillServiceMessageHeader( SMH );
				SMH = PrevSMH;
			}
		}else
		{
			CenterPrint4x5Text( THROTTLE, d3dapp->szClient.cy - FontHeight * 2, 2 );
		}
	}
	//sprintf( buf, "Max packets in que = %d", MaxPacketsInQue );
	//CenterPrint4x5Text( buf, d3dapp->szClient.cy - FontHeight * 4, 2 );

}
/*�������������������������������������������������������������������
	Procedure	:		Check if a packet is relevant to someone
	Input		:		BYTE Player
	Output		:		uint32 Flags
�������������������������������������������������������������������*/
BOOL CheckIfPacketRelevant( BYTE * MsgPnt , int Player )
{
    LPUPDATEMSG				lpUpdate;
    LPVERYSHORTUPDATEMSG	lpVeryShortUpdate;
    LPFUPDATEMSG			lpFUpdate;
    LPVERYSHORTFUPDATEMSG	lpVeryShortFUpdate;
    LPGROUPONLY_VERYSHORTFUPDATEMSG	lpGroupOnly_VeryShortFUpdate;
    LPSHIPHITMSG			lpShipHit;
    LPSHORTSHIPHITMSG		lpShortShipHit;
    LPSHIPDIEDMSG			lpShipDied;
    LPSECBULLPOSDIRMSG		lpSecBullPosDir;
    LPTITANBITSMSG			lpTitanBits;
    LPTEXTMSG				lpTextMsg;
	LPGUARANTEEDMSG			lpGuaranteedMsg;
	LPPINGMSG				lpPingMsg;
//	LPACKMSG				lpAckMsg;
	int16					Group;
	LPSHIELDHULLMSG	lpShieldHullMsg;

	switch( *MsgPnt )
    {
	case MSG_SHIELDHULL:
		if( MyGameStatus != STATUS_Normal )
			return FALSE;

		if( GameStatus[Player] != STATUS_Normal )
			return FALSE;

		lpShieldHullMsg = (LPSHIELDHULLMSG)&CommBuff[0];
		Group = Ships[ lpShieldHullMsg->WhoIAm ].RealGroup;
		
		if( !VisibleOverlap( Ships[ Player ].Object.Group, Group, NULL ) )
			return FALSE;
		break;
    case MSG_PINGREPLY:
		lpPingMsg = (LPPINGMSG)&CommBuff[0];
        if( lpPingMsg->ToYou != Player )
			return FALSE;
		break;

	case MSG_GUARANTEEDMSG:
		lpGuaranteedMsg = (LPGUARANTEEDMSG)MsgPnt;
		if( !(lpGuaranteedMsg->Ack & (1 << Player)) )
		{
			return FALSE;
		}
		break;
    case MSG_VERYSHORTFUPDATE:
		if( MyGameStatus != STATUS_Normal )
			return FALSE;
		if( GameStatus[Player] != STATUS_Normal )
			return FALSE;

		lpVeryShortFUpdate = (LPVERYSHORTFUPDATEMSG)MsgPnt;

		if( !CanDoDamage[lpVeryShortFUpdate->WhoIAm] || CheckIfPlayerCheats(lpVeryShortFUpdate->WhoIAm) )
			return FALSE;
		
		// They are mutually visible let it through...
		if( VisibleOverlap( Ships[ Player ].Object.Group, lpVeryShortFUpdate->ShortGlobalShip.GroupImIn, NULL ) )
			break;

		if( ( lpVeryShortFUpdate->ShortGlobalShip.Flags & SHIP_SecFire ) )
		{
			switch( ConvSecToNormWeapon( lpVeryShortFUpdate->ShortGlobalShip.Secondary ) )
			{

				case SOLARISMISSILE:
				case SCATTERMISSILE:
				case TITANSTARMISSILE:
				case GRAVGONMISSILE:
				case PURGEMINE:
				case PINEMINE:
				case QUANTUMMINE:
				case SPIDERMINE:
				case PINEMISSILE:
					break;

				default:
					return FALSE;
			}

		}else{
			return FALSE;
		}
		break;
    case MSG_GROUPONLY_VERYSHORTFUPDATE:
		if( MyGameStatus != STATUS_Normal )
			return FALSE;
		if( GameStatus[Player] != STATUS_Normal )
			return FALSE;

		lpGroupOnly_VeryShortFUpdate = (LPGROUPONLY_VERYSHORTFUPDATEMSG)MsgPnt;

		if( !CanDoDamage[lpGroupOnly_VeryShortFUpdate->WhoIAm] || CheckIfPlayerCheats(lpGroupOnly_VeryShortFUpdate->WhoIAm) )
			return FALSE;
		
		// They are mutually visible let it through...
		if( VisibleOverlap( Ships[ Player ].Object.Group, lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.GroupImIn, NULL ) )
			break;

		if( ( lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Flags & SHIP_SecFire ) )
		{
			switch( ConvSecToNormWeapon( lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Secondary ) )
			{

				case SOLARISMISSILE:
				case SCATTERMISSILE:
				case TITANSTARMISSILE:
				case GRAVGONMISSILE:
				case PURGEMINE:
				case PINEMINE:
				case QUANTUMMINE:
				case SPIDERMINE:
				case PINEMISSILE:
					break;

				default:
					return FALSE;
			}

		}else{
			return FALSE;
		}
		break;
	case MSG_FUPDATE:
		if( MyGameStatus != STATUS_Normal )
			return FALSE;

		lpFUpdate = (LPFUPDATEMSG)MsgPnt;

		if( GameStatus[Player] != STATUS_Normal )
			return FALSE;

		if( !CanDoDamage[lpFUpdate->WhoIAm] || CheckIfPlayerCheats(lpFUpdate->WhoIAm) )
			return FALSE;

		// They are mutually visible let it through...
		if( VisibleOverlap( Ships[ Player ].Object.Group, lpFUpdate->ShortGlobalShip.GroupImIn, NULL ) )
			break;

		if( lpFUpdate->ShortGlobalShip.Flags & SHIP_SecFire )
		{
			switch( ConvSecToNormWeapon( lpFUpdate->ShortGlobalShip.Secondary ) )
			{

				case SOLARISMISSILE:
				case SCATTERMISSILE:
				case TITANSTARMISSILE:
				case GRAVGONMISSILE:
				case PURGEMINE:
				case PINEMINE:
				case QUANTUMMINE:
				case SPIDERMINE:
				case PINEMISSILE:
					break;

				default:
					return FALSE;
			}

		}else{
			return FALSE;
		}
		break;
    case MSG_VERYSHORTUPDATE:
		if( MyGameStatus != STATUS_Normal )
			return FALSE;

		if( GameStatus[Player] != STATUS_Normal )
			return FALSE;

		lpVeryShortUpdate = (LPVERYSHORTUPDATEMSG) MsgPnt;
		Group = (int16)lpVeryShortUpdate->ShortGlobalShip.GroupImIn;

		if( !VisibleOverlap( Ships[ Player ].Object.Group, Group, NULL ) )
			return FALSE;
		break;
    case MSG_UPDATE:
		if( MyGameStatus != STATUS_Normal )
			return FALSE;

		if( GameStatus[Player] != STATUS_Normal )
			return FALSE;
		lpUpdate = (LPUPDATEMSG) MsgPnt;
		Group = (int16)lpUpdate->ShortGlobalShip.GroupImIn;
		if( !VisibleOverlap( Ships[ Player ].Object.Group, Group, NULL ) )
			return FALSE;
		break;

    case MSG_PRIMBULLPOSDIR:
		break;
    case MSG_SECBULLPOSDIR:
		if( MyGameStatus != STATUS_Normal )
			return FALSE;

   		lpSecBullPosDir = (LPSECBULLPOSDIRMSG)MsgPnt;
		if( !CanDoDamage[lpSecBullPosDir->WhoIAm] || CheckIfPlayerCheats(lpSecBullPosDir->WhoIAm))
			return FALSE;
		Group = (int16)lpSecBullPosDir->SecBullPosDir.Group;
		if( VisibleOverlap( Ships[ Player ].Object.Group, Group, NULL ) )
			break;
		switch( lpSecBullPosDir->SecBullPosDir.Weapon )
		{
			case SOLARISMISSILE:
			case SCATTERMISSILE:
			case TITANSTARMISSILE:
			case GRAVGONMISSILE:
			case PURGEMINE:
			case PINEMINE:
			case QUANTUMMINE:
			case SPIDERMINE:
			case PINEMISSILE:
				break;

			default:
				return FALSE;
		}
		break;

    case MSG_TITANBITS:
		if( MyGameStatus != STATUS_Normal )
			return FALSE;

   		lpTitanBits = (LPTITANBITSMSG)MsgPnt;
		Group = (int16)lpTitanBits->TitanBits.Group;
		if( !VisibleOverlap( Ships[ Player ].Object.Group, Group, NULL ) )
			return FALSE;
		break;
	// Someone is claiming to have hit me...
    case MSG_SHIPHIT:
		if( MyGameStatus != STATUS_Normal )
			return FALSE;

   		lpShipHit = (LPSHIPHITMSG)MsgPnt;
		if( ( lpShipHit->You != Player ) || ( lpShipHit->Deaths != Ships[Player].Deaths ) || ( ColPerspective == COLPERS_Descent ) )
			return FALSE;
		break;
	// Someone is claiming to have hit me...
    case MSG_SHORTSHIPHIT:
		if( MyGameStatus != STATUS_Normal )
			return FALSE;

   		lpShortShipHit = (LPSHORTSHIPHITMSG)MsgPnt;
		if( ( lpShortShipHit->You != Player ) || ( lpShortShipHit->Deaths != Ships[Player].Deaths ) || ( ColPerspective == COLPERS_Descent ) )
			return FALSE;
		break;
	// Someone has Died....Did I kill Them ??
    case MSG_SHIPDIED:
		if( MyGameStatus != STATUS_Normal )
			return FALSE;

		lpShipDied = (LPSHIPDIEDMSG)MsgPnt;

		if( Player != lpShipDied->WhoKilledMe )
		{
			if( !VisibleOverlap( Ships[ Player ].Object.Group, Ships[ lpShipDied->WhoIAm ].Object.Group , NULL ) )
				return FALSE;
		}
		break;
    case MSG_STATUS:
		break;
    case MSG_LONGSTATUS:
		break;

    case MSG_TEXTMSG:
		lpTextMsg = (LPTEXTMSG)MsgPnt;
		switch (lpTextMsg->TextMsgType)
		{
		case TEXTMSGTYPE_QuickTauntWhisper:
			if( TeamNumber[Player] != TeamNumber[lpTextMsg->WhoIAm] )
				return FALSE;
			break;
		case TEXTMSGTYPE_Taunt1:
		case TEXTMSGTYPE_Taunt2:
		case TEXTMSGTYPE_Taunt3:
		case TEXTMSGTYPE_QuickTaunt:

			if( MyGameStatus == STATUS_Normal )
			{
				if( !VisibleOverlap( Ships[ Player ].Object.Group, Ships[lpTextMsg->WhoIAm].Object.Group, NULL ) )
					return FALSE;
			}
			break;
		}
		break;
    case MSG_ACKMSG:
//		lpAckMsg = (LPACKMSG)MsgPnt;
//		if( lpAckMsg->WhoIAm != Player )
//			return FALSE;
		break;
	case MSG_GAMEPARAMETERS:
		return FALSE;
#ifdef MANUAL_SESSIONDESC_PROPAGATE
	case MSG_SESSIONDESC:
		return FALSE;
#endif
	case MSG_TOSERVER:
		return FALSE;
	case MSG_TOCLIENT:
		return TRUE;
	case MSG_LEVELNAMES:
		return TRUE;
	case MSG_TRACKERINFO:
		return TRUE;
	}

	return TRUE;
}

/*�������������������������������������������������������������������
	Procedure	:		Add a packet to the Service Packet
	Input		:		BYTE Player
	Output		:		uint32 Flags
�������������������������������������������������������������������*/
void AddToServicePacket( SERVERMSGHEADER * SMH, int Player )
{
	int MessageLength;
	void * Message;
	BYTE MsgType;
	uint32 TempSize;

	MessageLength = SMH->MsgLength;
	MsgType = SMH->MsgType;
	Message = &SMH->Message;

	TempSize = ServerPacketOffset+MessageLength+sizeof(float);

	if( ( TempSize >= (SERVERPACKETBUFFERSIZE-1) ) ||
		(NumOfPacketsInServerPacket >= MAXPACKETSPERSERVERPACKET-1) )
		SendServerPacket( Player );

	ServerPacketOffsets[NumOfPacketsInServerPacket] = ServerPacketOffset;
	ServerPacketSizes[NumOfPacketsInServerPacket] = MessageLength;
	ServerPacketTime[NumOfPacketsInServerPacket] = SMH->framelag;
	NumOfPacketsInServerPacket++;
	
	memcpy( &ServerPacketCommBuff[ServerPacketOffset], Message, MessageLength );
	ServerPacketOffset += MessageLength + sizeof(float);
	ServerPacketCommBuff[ServerPacketOffset] = 0;
}

/*�������������������������������������������������������������������
	Procedure	:		Send Server Packet...
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
void SendServerPacket( int Player )
{
	HRESULT				hr;
	DWORD				Flags = 0;
	uint32 i;
	DWORD send_to;
	float * FloatPnt;

	if( !NumOfPacketsInServerPacket )
		return;
	
	ServerPacketCommBuff[0] = MSG_BIGPACKET;
	ServerPacketCommBuff[1] = WhoIAm;
	send_to = Ships[Player].dcoID;

	for( i = 0 ; i < NumOfPacketsInServerPacket ; i++ )
	{
		FloatPnt = (float*) &ServerPacketCommBuff[ ServerPacketOffsets[i] + ServerPacketSizes[i] ];
		*FloatPnt = ServerPacketTime[i];
	}
	

	if( average_server_packet_size )
	{
		average_server_packet_size += ServerPacketOffset+1;
		average_server_packet_size /= 2;

	}else{
		average_server_packet_size = ServerPacketOffset+1;


	}



	if( !UseSendAsync && !IsServer )
//	if( 1 )
	{
		hr = glpDP->lpVtbl->Send( glpDP,
								  dcoID,   // From
								  send_to, // send to everybody
								  Flags ,
						  &ServerPacketCommBuff[0],
						  ServerPacketOffset+1);
	}else{
		Flags |= DPSEND_ASYNC | DPSEND_NOSENDCOMPLETEMSG;
		hr = IDirectPlayX_SendEx( glpDP,
								  dcoID,   // From
								  send_to, // send to
								  Flags ,
								  &ServerPacketCommBuff[0],
								  ServerPacketOffset+1,
								  0,		// dwPriority
								  0,		// dwTimeout
								  NULL,		// lpContext
								  NULL		// lpdwMsgID
								  );
	}

	if( hr != DP_OK && hr != DPERR_PENDING )
	{
		OutputDebugString( "Dplay Server Packet Send Error" );
	}

	BigPacketSize = ServerPacketOffset+1;
	if( BigPacketSize > MaxBigPacketSize )
		MaxBigPacketSize = BigPacketSize;

	BytesPerSecSent += ServerPacketOffset+1;

	ServerPacketOffset = 2;
	ServerPacketCommBuff[2] = 0;
	NumOfPacketsInServerPacket = 0;
}

#if 0
/*�������������������������������������������������������������������
	Procedure	:		Server Does Damage....
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
int16 ServerDoDamage( BYTE you );

void	ServerIHitYou( BYTE Owner , BYTE you, float Damage, VECTOR * Recoil, VECTOR * Point, VECTOR * Dir, float Force, BYTE WeaponType, BYTE Weapon, BOOL FramelagRecoil )
{
	// That player has Incremeted his shield or hull illegally...
	if( !CanDoDamage[Owner] )
		return;
	
	IHitYou( you, Damage, Recoil, Point, Dir, Force, WeaponType, Weapon, FramelagRecoil );

	Ships[you].Damage = Damage;
	Ships[you].ShipThatLastHitMe = Owner;


	if( ServerDoDamage( you ) )
	{
		// That Ship Should have died....
		Ships[you].Object.Hull = START_HULL;
		Ships[you].Object.Shield = START_SHIELD;

		SSSDM.MsgCode = MSG_SERVERSAYSSHIPDIED;
		SSSDM.WhoIAm = WhoIAm;
		SSSDM.WhoWasKilled = you;
		SSSDM.WhoKilledThem = Owner;
		SSSDM.Type = 0;
		SSSDM.WeaponType = WeaponType;
		SSSDM.Weapon = Weapon;
		SSSDM.Pos = *Point;
		SSSDM.Deaths = Ships[you].Deaths;
		SendGameMessage( MSG_SERVERSAYSSHIPDIED, 0, 0, 0, 0 );

		QueryPerformanceCounter((LARGE_INTEGER *) &TempTime);
		TimeSinceDeath[you] = TempTime + ( Freq * 10 );

//		Ships[ship].Deaths++;
	}
}

/*�������������������������������������������������������������������
	Procedure	:		Check Server Death times...
	Input		:		void
	Output		:		void
�������������������������������������������������������������������*/
void	CheckServerDeathTimes( void )
{
	int i;
	if( !IsServer )
		return;
	QueryPerformanceCounter((LARGE_INTEGER *) &TempTime);
	for( i = 1 ; i < MAX_PLAYERS ; i++ )
	{
		if( TimeSinceDeath[i] != 0 )
		{

			if( TimeSinceDeath[i] < TempTime )
			{
				CanDoDamage[i] = FALSE;
				TimeSinceDeath[i] = 0;
			}
		}
	}
}

/*�����������������������������������������������������������������������
			Work Out How Much Damage Ive Taken
			Input : Nothing....Ships[WhoIAm].Damage must be set
			Output: 0 no kill...1 last hit killed me...
����������������������������������������������������������������������*/
int16 ServerDoDamage( BYTE ship )
{
	if( Ships[ ship ].Invul ) return 0;
	if( TeamGame && !HarmTeamMates )
	{
		if( Ships[ ship ].ShipThatLastHitMe != MAX_PLAYERS )
		{
			if( ( TeamNumber[ ship ] == TeamNumber[ Ships[ ship ].ShipThatLastHitMe ] ) &&
				( ship != Ships[ ship ].ShipThatLastHitMe ) )
			{
				return 0;
			}
		}
	}

	if( Ships[ship].Object.Mode == NORMAL_MODE )
	{
		if( Ships[ship].Damage )
		{
			Ships[ship].Damage *= -1.0F;
			Ships[ship].Object.Shield += Ships[ship].Damage;

			if( Ships[ship].Object.Shield  >= MAX_SHIELD )
			{
				Ships[ship].Object.Shield  = MAX_SHIELD;
			}else{
				if( Ships[ship].Object.Shield  < 0.0F )
				{
					Ships[ship].Object.Hull += Ships[ship].Object.Shield;
					Ships[ship].Object.Shield = 0.0F;

					if( Ships[ship].Object.Hull <= 0 )
					{
						// reset shield & hull critical flags...

						if( Ships[ship].ShipThatLastHitMe == ship )
						{
							// killed myself....Doh
							Ships[ship].Kills--;
						}
						return 1;
					}
				}
			}
		}
	}
	return 0;
}
#endif
/*�������������������������������������������������������������������
	Procedure	:		Check Server Death times...
	Input		:		void	*	Message
	Output		:		BOOL		True/False ( Valid Message )
�������������������������������������������������������������������*/
BOOL UpdateAmmoAndValidateMessage( void * Message )
{
	BYTE					Weapon;
	BYTE					TempWeapon;
	BYTE					Player;
	BYTE		*			MsgPnt;
	BYTE					MsgType;
    LPDROPPICKUPMSG			lpDropPickup;
    LPVERYSHORTDROPPICKUPMSG lpVeryShortDropPickup;
    LPFUPDATEMSG			lpFUpdate;
    LPVERYSHORTFUPDATEMSG	lpVeryShortFUpdate;
    LPGROUPONLY_VERYSHORTFUPDATEMSG	lpGroupOnly_VeryShortFUpdate;
    LPPRIMBULLPOSDIRMSG		lpPrimBullPosDir;
    LPSECBULLPOSDIRMSG		lpSecBullPosDir;
	LPGUARANTEEDMSG			lpGuaranteedMsg;
	int16					PowerLevel;
	float					Ammo;
	int16					Count, Count2;
	float					TempFloat;
	BYTE					NumMultiples;

	MsgPnt = (BYTE *) Message;
	MsgType = MsgPnt[ 0 ];
	Player = MsgPnt[ 1 ];

	PowerLevel = Host_PowerLevel[ Player ]; //Ships[ Player ].Object.PowerLevel;

	switch( MsgType )
    {
		case MSG_DROPPICKUP:
			lpDropPickup = (LPDROPPICKUPMSG)MsgPnt;

			switch( lpDropPickup->PickupInfo.Type )
			{
				case PICKUP_GeneralAmmo:
					Host_GeneralAmmo[ lpDropPickup->WhoIAm ] -= GENERALAMMOPERPOD;
					if( Host_GeneralAmmo[ lpDropPickup->WhoIAm ] < 0.0F ) Host_GeneralAmmo[ lpDropPickup->WhoIAm ] = 0.0F;
					break;

				case PICKUP_PyroliteAmmo:
					Host_PyroliteAmmo[ lpDropPickup->WhoIAm ] -= PYROLITEAMMOPERPOD;
					if( Host_PyroliteAmmo[ lpDropPickup->WhoIAm ] < 0.0F ) Host_PyroliteAmmo[ lpDropPickup->WhoIAm ] = 0.0F;
					break;

				case PICKUP_SussGunAmmo:
					Host_SussGunAmmo[ lpDropPickup->WhoIAm ] -= SUSSGUNAMMOPERPOD;
					if( Host_SussGunAmmo[ lpDropPickup->WhoIAm ] < 0.0F ) Host_SussGunAmmo[ lpDropPickup->WhoIAm ] = 0.0F;
					break;

				case PICKUP_Trojax: 
				case PICKUP_Pyrolite:
				case PICKUP_Transpulse:
				case PICKUP_SussGun:
				case PICKUP_Laser:
					Host_PrimaryWeaponsGot[ Player ][ ( lpDropPickup->PickupInfo.Type - PICKUP_Trojax ) + 1 ] = 0;
					break;

				case PICKUP_Mugs:
				case PICKUP_HeatseakerPickup:
				case PICKUP_Thief:
				case PICKUP_Scatter:
				case PICKUP_Gravgon:
				case PICKUP_Launcher:
				case PICKUP_TitanStar:
				case PICKUP_PurgePickup:
				case PICKUP_PinePickup:
				case PICKUP_QuantumPickup:
				case PICKUP_SpiderPod:
				case PICKUP_Parasite:
					for( Count = 0; Count < MAXSECONDARYWEAPONS; Count++ )
					{
						if( SecondaryFromPickupTab[ ( Count * 2 ) ] == lpDropPickup->PickupInfo.Type )
						{
							Weapon = (BYTE) Count;
							break;
						}
					}

					if( Host_SecondaryAmmo[ Player ][ Weapon ] > SecondaryFromPickupTab[ ( Weapon * 2 ) + 1 ] )
					{
						Host_SecondaryAmmo[ Player ][ Weapon ] -= SecondaryFromPickupTab[ ( Weapon * 2 ) + 1 ];
					}
					else
					{
						Host_SecondaryAmmo[ Player ][ Weapon ] = 0;
						Host_SecondaryWeaponsGot[ Player ][ Weapon ] = 0;
					}
					break;

				default:
					break;
			}
			break;
		case MSG_VERYSHORTDROPPICKUP:
			lpVeryShortDropPickup = (LPVERYSHORTDROPPICKUPMSG)MsgPnt;

			switch( lpVeryShortDropPickup->PickupInfo.Type )
			{
				case PICKUP_GeneralAmmo:
					Host_GeneralAmmo[ lpVeryShortDropPickup->WhoIAm ] -= GENERALAMMOPERPOD;
					if( Host_GeneralAmmo[ lpVeryShortDropPickup->WhoIAm ] < 0.0F ) Host_GeneralAmmo[ lpVeryShortDropPickup->WhoIAm ] = 0.0F;
					break;

				case PICKUP_PyroliteAmmo:
					Host_PyroliteAmmo[ lpVeryShortDropPickup->WhoIAm ] -= PYROLITEAMMOPERPOD;
					if( Host_PyroliteAmmo[ lpVeryShortDropPickup->WhoIAm ] < 0.0F ) Host_PyroliteAmmo[ lpVeryShortDropPickup->WhoIAm ] = 0.0F;
					break;

				case PICKUP_SussGunAmmo:
					Host_SussGunAmmo[ lpVeryShortDropPickup->WhoIAm ] -= SUSSGUNAMMOPERPOD;
					if( Host_SussGunAmmo[ lpVeryShortDropPickup->WhoIAm ] < 0.0F ) Host_SussGunAmmo[ lpVeryShortDropPickup->WhoIAm ] = 0.0F;
					break;

				case PICKUP_Trojax: 
				case PICKUP_Pyrolite:
				case PICKUP_Transpulse:
				case PICKUP_SussGun:
				case PICKUP_Laser:
					Host_PrimaryWeaponsGot[ Player ][ ( lpVeryShortDropPickup->PickupInfo.Type - PICKUP_Trojax ) + 1 ] = 0;
					break;

				case PICKUP_Mugs:
				case PICKUP_HeatseakerPickup:
				case PICKUP_Thief:
				case PICKUP_Scatter:
				case PICKUP_Gravgon:
				case PICKUP_Launcher:
				case PICKUP_TitanStar:
				case PICKUP_PurgePickup:
				case PICKUP_PinePickup:
				case PICKUP_QuantumPickup:
				case PICKUP_SpiderPod:
				case PICKUP_Parasite:
					for( Count = 0; Count < MAXSECONDARYWEAPONS; Count++ )
					{
						if( SecondaryFromPickupTab[ ( Count * 2 ) ] == lpVeryShortDropPickup->PickupInfo.Type )
						{
							Weapon = (BYTE) Count;
							break;
						}
					}

					if( Host_SecondaryAmmo[ Player ][ Weapon ] > SecondaryFromPickupTab[ ( Weapon * 2 ) + 1 ] )
					{
						Host_SecondaryAmmo[ Player ][ Weapon ] -= SecondaryFromPickupTab[ ( Weapon * 2 ) + 1 ];
					}
					else
					{
						Host_SecondaryAmmo[ Player ][ Weapon ] = 0;
						Host_SecondaryWeaponsGot[ Player ][ Weapon ] = 0;
					}
					break;

				default:
					break;
			}
			break;


		case MSG_VERYSHORTFUPDATE:
			lpVeryShortFUpdate = (LPVERYSHORTFUPDATEMSG)MsgPnt;

			if( ( Ships[ Player ].SuperNashramTimer == 0.0F ) )
			{
				if( ( Ships[lpVeryShortFUpdate->WhoIAm].Object.Flags & SHIP_Multiple ) )
				{
					NumMultiples = (BYTE) ((lpVeryShortFUpdate->ShortGlobalShip.Flags >> SHIP_NumMultiples_Bit1 ) & 15);
				}
				else
				{
					NumMultiples = 0;
				}

				if( NumMultiples < Host_NumOfOrbitals[ Player ] )
				{
					if( Host_NumOfOrbitals[ Player ] > 1 )
					{
						for( Count = 0; Count < ( Host_NumOfOrbitals[ Player ] - 1 ); Count++ )
						{
							for( Count2 = ( Count + 1 ); Count2 < Host_NumOfOrbitals[ Player ]; Count2++ )
							{
								if( Host_OrbAmmo[ Player ][ Count ] < Host_OrbAmmo[ Player ][ Count2 ] )
								{
									TempFloat = Host_OrbAmmo[ Player ][ Count2 ];
									Host_OrbAmmo[ Player ][ Count2 ] = Host_OrbAmmo[ Player ][ Count ];
									Host_OrbAmmo[ Player ][ Count ] = TempFloat;
								}
							}
						}
					}

					NumOrbs += ( Host_NumOfOrbitals[ Player ] - NumMultiples );
					Host_NumOfOrbitals[ Player ] = NumMultiples;
				}
			}

			if( ( lpVeryShortFUpdate->ShortGlobalShip.Flags & SHIP_MulFire ) )
			{
				for( Count = 0; Count < Host_NumOfOrbitals[ Player ]; Count++ )
				{
//					if( !( Ships[ Player ].Object.Flags & SHIP_SuperNashram ) )
					if( Ships[ Player ].SuperNashramTimer == 0.0F )
					{
						Host_OrbAmmo[ Player ][ Count ] -= (float) PrimaryWeaponAttribs[ ORBITPULSAR ].AmmoUsage[ PowerLevel ];

						if( Host_OrbAmmo[ Player ][ Count ] < 0.0F )
						{
							if( Host_NumOfOrbitals[ Player ] )
							{
								Host_NumOfOrbitals[ Player ]--;
								Host_OrbAmmo[ Player ][ Count ] = Host_OrbAmmo[ Player ][ Host_NumOfOrbitals[ Player ] ]; 
								NumOrbs++;
							}
						}
					}
				}
			}

			if( ( lpVeryShortFUpdate->ShortGlobalShip.Flags & SHIP_SecFire ) )
			{
				Weapon = lpVeryShortFUpdate->ShortGlobalShip.Secondary;
				TempWeapon = ConvSecToNormWeapon( Weapon );

//				AddMessageToQue( "Update:FireSecondary : %s, Got = %d, Ammo = %d", SecondaryDescription[ TempWeapon ],
//																			Host_SecondaryWeaponsGot[ Player ][ TempWeapon ],
//																			Host_SecondaryAmmo[ Player ][ TempWeapon ] );

				if( !Host_SecondaryWeaponsGot[ Player ][ TempWeapon ] ) return( FALSE );
				if( !Host_SecondaryAmmo[ Player ][ TempWeapon ] ) return( FALSE );

				switch( Weapon )
				{
					case MUGMISSILE:
					case SOLARISMISSILE:
					case THIEFMISSILE:
					case SCATTERMISSILE:
					case GRAVGONMISSILE:
					case MULTIPLEMISSILE:
					case TITANSTARMISSILE:
					case PINEMISSILE:
					case TITANSTARSHRAPNEL:
					case ENEMYSPIRALMISSILE:
					case ENEMYHOMINGMISSILE:
					case ENEMYBLUEHOMINGMISSILE:
					case ENEMYFIREBALL:
					case ENEMYTENTACLE:
					case ENEMYDEPTHCHARGE:
						Host_SecAmmoUsed[ TempWeapon ]++;
						if( Host_SecondaryAmmo[ Player ][ TempWeapon ] ) Host_SecondaryAmmo[ Player ][ TempWeapon ]--;
						if( !Host_SecondaryAmmo[ Player ][ TempWeapon ] ) Host_SecondaryWeaponsGot[ Player ][ TempWeapon ] = 0;
						break;

					case PURGEMINE:
					case PINEMINE:
					case QUANTUMMINE:
					case SPIDERMINE:
						if( Host_SecondaryAmmo[ Player ][ TempWeapon ] ) Host_SecondaryAmmo[ Player ][ TempWeapon ]--;
						if( !Host_SecondaryAmmo[ Player ][ TempWeapon ] ) Host_SecondaryWeaponsGot[ Player ][ TempWeapon ] = 0;
						break;

					default:
						break;
				}
			}

			if( lpVeryShortFUpdate->ShortGlobalShip.Flags & SHIP_PrimFire )
			{
				Weapon = lpVeryShortFUpdate->ShortGlobalShip.Primary;

				if( Weapon >= MAXPRIMARYWEAPONS ) break;
				if( !Host_PrimaryWeaponsGot[ Player ][ Weapon ] ) return( FALSE );
				Ammo = GetPrimaryAmmoUsage( Player, Weapon );

				switch( Weapon )
				{
					case PULSAR:
					case TRANSPULSE_CANNON:
					case LASER:
					case NME_BULLET1:
					case NME_PULSAR:
					case NME_TRANSPULSE:
					case NME_LASER:
					case NME_LIGHTNING:
					case FLAMES:
					case NME_POWERLASER:
						if( ( Ships[ Player ].SuperNashramTimer == 0.0F ) && !BombTag )
						{
							if( Host_GeneralAmmo[ Player ] == 0.0F ) return( FALSE );
							Host_GeneralAmmoUsed += Ammo;
							Host_GeneralAmmo[ Player ] -= Ammo;
							if( Host_GeneralAmmo[ Player ] < 0.0F ) Host_GeneralAmmo[ Player ] = 0.0F;
						}

//						AddMessageToQue( "Update:FirePrimary : %s, Got = %hd, Ammo = %f", PrimaryDescription[ Weapon ],
//																	Host_PrimaryWeaponsGot[ Player ][ Weapon ],
//																	Host_GeneralAmmo[ Player ] );
						break;

					case TROJAX:
					case NME_TROJAX:
						if( ( Ships[ Player ].SuperNashramTimer == 0.0F ) && !BombTag )
						{
							if( Host_GeneralAmmo[ Player ] == 0.0F ) return( FALSE );
						}

//						AddMessageToQue( "Update:FirePrimary : %s, Got = %hd, Ammo = %f", PrimaryDescription[ Weapon ],
//																	Host_PrimaryWeaponsGot[ Player ][ Weapon ],
//																	Host_GeneralAmmo[ Player ] );
						break;

					case PYROLITE_RIFLE:
					case NME_PYROLITE:
						if( ( Ships[ Player ].SuperNashramTimer == 0.0F ) && !BombTag )
						{
							if( Host_PyroliteAmmo[ Player ] == 0.0F ) return( FALSE );
							Host_PyroliteAmmoUsed += Ammo;
							Host_PyroliteAmmo[ Player ] -= Ammo;
							if( Host_PyroliteAmmo[ Player ] < 0.0F ) Host_PyroliteAmmo[ Player ] = 0.0F;
						}

//						AddMessageToQue( "Update:FirePrimary : %s, Got = %hd, Ammo = %f", PrimaryDescription[ Weapon ],
//																	Host_PrimaryWeaponsGot[ Player ][ Weapon ],
//																	Host_PyroliteAmmo[ Player ] );
						break;

					case SUSS_GUN:
					case NME_SUSS_GUN:
						if( ( Ships[ Player ].SuperNashramTimer == 0.0F ) && !BombTag )
						{
							if( Host_SussGunAmmo[ Player ] == 0.0F ) return( FALSE );
							Host_SussGunAmmoUsed += Ammo;
							Host_SussGunAmmo[ Player ] -= Ammo;
							if( Host_SussGunAmmo[ Player ] < 0.0F ) Host_SussGunAmmo[ Player ] = 0.0F;
						}

//						AddMessageToQue( "Update:FirePrimary : %s, Got = %hd, Ammo = %f", PrimaryDescription[ Weapon ],
//																	Host_PrimaryWeaponsGot[ Player ][ Weapon ],
//																	Host_SussGunAmmo[ Player ] );
						break;

					case ORBITPULSAR:
						break;

					default:
						break;
				}
			}
			break;

		case MSG_GROUPONLY_VERYSHORTFUPDATE:
			lpGroupOnly_VeryShortFUpdate = (LPGROUPONLY_VERYSHORTFUPDATEMSG)MsgPnt;

			if( ( Ships[ Player ].SuperNashramTimer == 0.0F ) )
			{
				if( ( Ships[lpGroupOnly_VeryShortFUpdate->WhoIAm].Object.Flags & SHIP_Multiple ) )
				{
					NumMultiples = (BYTE) ((lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Flags >> SHIP_NumMultiples_Bit1 ) & 15);
				}
				else
				{
					NumMultiples = 0;
				}

				if( NumMultiples < Host_NumOfOrbitals[ Player ] )
				{
					if( Host_NumOfOrbitals[ Player ] > 1 )
					{
						for( Count = 0; Count < ( Host_NumOfOrbitals[ Player ] - 1 ); Count++ )
						{
							for( Count2 = ( Count + 1 ); Count2 < Host_NumOfOrbitals[ Player ]; Count2++ )
							{
								if( Host_OrbAmmo[ Player ][ Count ] < Host_OrbAmmo[ Player ][ Count2 ] )
								{
									TempFloat = Host_OrbAmmo[ Player ][ Count2 ];
									Host_OrbAmmo[ Player ][ Count2 ] = Host_OrbAmmo[ Player ][ Count ];
									Host_OrbAmmo[ Player ][ Count ] = TempFloat;
								}
							}
						}
					}

					NumOrbs += ( Host_NumOfOrbitals[ Player ] - NumMultiples );
					Host_NumOfOrbitals[ Player ] = NumMultiples;
				}
			}

			if( ( lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Flags & SHIP_MulFire ) )
			{
				for( Count = 0; Count < Host_NumOfOrbitals[ Player ]; Count++ )
				{
//					if( !( Ships[ Player ].Object.Flags & SHIP_SuperNashram ) )
					if( Ships[ Player ].SuperNashramTimer == 0.0F )
					{
						Host_OrbAmmo[ Player ][ Count ] -= (float) PrimaryWeaponAttribs[ ORBITPULSAR ].AmmoUsage[ PowerLevel ];

						if( Host_OrbAmmo[ Player ][ Count ] < 0.0F )
						{
							if( Host_NumOfOrbitals[ Player ] )
							{
								Host_NumOfOrbitals[ Player ]--;
								Host_OrbAmmo[ Player ][ Count ] = Host_OrbAmmo[ Player ][ Host_NumOfOrbitals[ Player ] ]; 
								NumOrbs++;
							}
						}
					}
				}
			}

			if( ( lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Flags & SHIP_SecFire ) )
			{
				Weapon = lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Secondary;
				TempWeapon = ConvSecToNormWeapon( Weapon );

//				AddMessageToQue( "Update:FireSecondary : %s, Got = %d, Ammo = %d", SecondaryDescription[ TempWeapon ],
//																			Host_SecondaryWeaponsGot[ Player ][ TempWeapon ],
//																			Host_SecondaryAmmo[ Player ][ TempWeapon ] );

				if( !Host_SecondaryWeaponsGot[ Player ][ TempWeapon ] ) return( FALSE );
				if( !Host_SecondaryAmmo[ Player ][ TempWeapon ] ) return( FALSE );

				switch( Weapon )
				{
					case MUGMISSILE:
					case SOLARISMISSILE:
					case THIEFMISSILE:
					case SCATTERMISSILE:
					case GRAVGONMISSILE:
					case MULTIPLEMISSILE:
					case TITANSTARMISSILE:
					case PINEMISSILE:
					case TITANSTARSHRAPNEL:
					case ENEMYSPIRALMISSILE:
					case ENEMYHOMINGMISSILE:
					case ENEMYBLUEHOMINGMISSILE:
					case ENEMYFIREBALL:
					case ENEMYTENTACLE:
					case ENEMYDEPTHCHARGE:
						Host_SecAmmoUsed[ TempWeapon ]++;
						if( Host_SecondaryAmmo[ Player ][ TempWeapon ] ) Host_SecondaryAmmo[ Player ][ TempWeapon ]--;
						if( !Host_SecondaryAmmo[ Player ][ TempWeapon ] ) Host_SecondaryWeaponsGot[ Player ][ TempWeapon ] = 0;
						break;

					case PURGEMINE:
					case PINEMINE:
					case QUANTUMMINE:
					case SPIDERMINE:
						if( Host_SecondaryAmmo[ Player ][ TempWeapon ] ) Host_SecondaryAmmo[ Player ][ TempWeapon ]--;
						if( !Host_SecondaryAmmo[ Player ][ TempWeapon ] ) Host_SecondaryWeaponsGot[ Player ][ TempWeapon ] = 0;
						break;

					default:
						break;
				}
			}

			if( lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Flags & SHIP_PrimFire )
			{
				Weapon = lpGroupOnly_VeryShortFUpdate->ShortGlobalShip.Primary;

				if( Weapon >= MAXPRIMARYWEAPONS ) break;
				if( !Host_PrimaryWeaponsGot[ Player ][ Weapon ] ) return( FALSE );
				Ammo = GetPrimaryAmmoUsage( Player, Weapon );

				switch( Weapon )
				{
					case PULSAR:
					case TRANSPULSE_CANNON:
					case LASER:
					case NME_BULLET1:
					case NME_PULSAR:
					case NME_TRANSPULSE:
					case NME_LASER:
					case NME_LIGHTNING:
					case FLAMES:
					case NME_POWERLASER:
						if( ( Ships[ Player ].SuperNashramTimer == 0.0F ) && !BombTag )
						{
							if( Host_GeneralAmmo[ Player ] == 0.0F ) return( FALSE );
							Host_GeneralAmmoUsed += Ammo;
							Host_GeneralAmmo[ Player ] -= Ammo;
							if( Host_GeneralAmmo[ Player ] < 0.0F ) Host_GeneralAmmo[ Player ] = 0.0F;
						}

//						AddMessageToQue( "Update:FirePrimary : %s, Got = %hd, Ammo = %f", PrimaryDescription[ Weapon ],
//																	Host_PrimaryWeaponsGot[ Player ][ Weapon ],
//																	Host_GeneralAmmo[ Player ] );
						break;

					case TROJAX:
					case NME_TROJAX:
						if( ( Ships[ Player ].SuperNashramTimer == 0.0F ) && !BombTag )
						{
							if( Host_GeneralAmmo[ Player ] == 0.0F ) return( FALSE );
						}

//						AddMessageToQue( "Update:FirePrimary : %s, Got = %hd, Ammo = %f", PrimaryDescription[ Weapon ],
//																	Host_PrimaryWeaponsGot[ Player ][ Weapon ],
//																	Host_GeneralAmmo[ Player ] );
						break;

					case PYROLITE_RIFLE:
					case NME_PYROLITE:
						if( ( Ships[ Player ].SuperNashramTimer == 0.0F ) && !BombTag )
						{
							if( Host_PyroliteAmmo[ Player ] == 0.0F ) return( FALSE );
							Host_PyroliteAmmoUsed += Ammo;
							Host_PyroliteAmmo[ Player ] -= Ammo;
							if( Host_PyroliteAmmo[ Player ] < 0.0F ) Host_PyroliteAmmo[ Player ] = 0.0F;
						}

//						AddMessageToQue( "Update:FirePrimary : %s, Got = %hd, Ammo = %f", PrimaryDescription[ Weapon ],
//																	Host_PrimaryWeaponsGot[ Player ][ Weapon ],
//																	Host_PyroliteAmmo[ Player ] );
						break;

					case SUSS_GUN:
					case NME_SUSS_GUN:
						if( ( Ships[ Player ].SuperNashramTimer == 0.0F ) && !BombTag )
						{
							if( Host_SussGunAmmo[ Player ] == 0.0F ) return( FALSE );
							Host_SussGunAmmoUsed += Ammo;
							Host_SussGunAmmo[ Player ] -= Ammo;
							if( Host_SussGunAmmo[ Player ] < 0.0F ) Host_SussGunAmmo[ Player ] = 0.0F;
						}

//						AddMessageToQue( "Update:FirePrimary : %s, Got = %hd, Ammo = %f", PrimaryDescription[ Weapon ],
//																	Host_PrimaryWeaponsGot[ Player ][ Weapon ],
//																	Host_SussGunAmmo[ Player ] );
						break;

					case ORBITPULSAR:
						break;

					default:
						break;
				}
			}
			break;

		case MSG_FUPDATE:
			lpFUpdate = (LPFUPDATEMSG)MsgPnt;

			if( ( Ships[ Player ].SuperNashramTimer == 0.0F ) )
			{
				if( ( Ships[lpFUpdate->WhoIAm].Object.Flags & SHIP_Multiple ) )
				{
					NumMultiples = (BYTE) ((lpFUpdate->ShortGlobalShip.Flags >> SHIP_NumMultiples_Bit1 ) & 15);
				}
				else
				{
					NumMultiples = 0;
				}

				if( NumMultiples < Host_NumOfOrbitals[ Player ] )
				{
					if( Host_NumOfOrbitals[ Player ] > 1 )
					{
						for( Count = 0; Count < ( Host_NumOfOrbitals[ Player ] - 1 ); Count++ )
						{
							for( Count2 = ( Count + 1 ); Count2 < Host_NumOfOrbitals[ Player ]; Count2++ )
							{
								if( Host_OrbAmmo[ Player ][ Count ] < Host_OrbAmmo[ Player ][ Count2 ] )
								{
									TempFloat = Host_OrbAmmo[ Player ][ Count2 ];
									Host_OrbAmmo[ Player ][ Count2 ] = Host_OrbAmmo[ Player ][ Count ];
									Host_OrbAmmo[ Player ][ Count ] = TempFloat;
								}
							}
						}
					}

					NumOrbs += ( Host_NumOfOrbitals[ Player ] - NumMultiples );
					Host_NumOfOrbitals[ Player ] = NumMultiples;
				}
			}

			if( lpFUpdate->ShortGlobalShip.Flags & SHIP_MulFire )
			{
				for( Count = 0; Count < Host_NumOfOrbitals[ Player ]; Count++ )
				{
//					if( !( Ships[ Player ].Object.Flags & SHIP_SuperNashram ) )
					if( ( Ships[ Player ].SuperNashramTimer == 0.0F ) )
					{
						Host_OrbAmmo[ Player ][ Count ] -= (float) PrimaryWeaponAttribs[ ORBITPULSAR ].AmmoUsage[ PowerLevel ];

						if( Host_OrbAmmo[ Player ][ Count ] < 0.0F )
						{
							if( Host_NumOfOrbitals[ Player ] )
							{
								Host_NumOfOrbitals[ Player ]--;
								Host_OrbAmmo[ Player ][ Count ] = Host_OrbAmmo[ Player ][ Host_NumOfOrbitals[ Player ] ]; 
								NumOrbs++;
							}
						}
					}
				}
			}

			if( lpFUpdate->ShortGlobalShip.Flags & SHIP_SecFire )
			{
				Weapon		= lpFUpdate->ShortGlobalShip.Secondary;
				TempWeapon	= ConvSecToNormWeapon( Weapon );

				if( !Host_SecondaryWeaponsGot[ Player ][ TempWeapon ] ) return( FALSE );
				if( !Host_SecondaryAmmo[ Player ][ TempWeapon ] ) return( FALSE );

//				AddMessageToQue( "Update:FireSecondary : %s, Got = %d, Ammo = %d", SecondaryDescription[ TempWeapon ],
//																			Host_SecondaryWeaponsGot[ Player ][ TempWeapon ],
//																			Host_SecondaryAmmo[ Player ][ TempWeapon ] );

				switch( Weapon )
				{
					case MUGMISSILE:
					case SOLARISMISSILE:
					case THIEFMISSILE:
					case SCATTERMISSILE:
					case GRAVGONMISSILE:
					case MULTIPLEMISSILE:
					case TITANSTARMISSILE:
					case PINEMISSILE:
					case TITANSTARSHRAPNEL:
					case ENEMYSPIRALMISSILE:
					case ENEMYHOMINGMISSILE:
					case ENEMYBLUEHOMINGMISSILE:
					case ENEMYFIREBALL:
					case ENEMYTENTACLE:
					case ENEMYDEPTHCHARGE:
						Host_SecAmmoUsed[ TempWeapon ]++;
						Host_SecondaryAmmo[ Player ][ TempWeapon ]--;
						if( !Host_SecondaryAmmo[ Player ][ TempWeapon ] ) Host_SecondaryWeaponsGot[ Player ][ TempWeapon ] = 0;
						break;

					case PURGEMINE:
					case PINEMINE:
					case QUANTUMMINE:
					case SPIDERMINE:
						Host_SecondaryAmmo[ Player ][ TempWeapon ]--;
						if( !Host_SecondaryAmmo[ Player ][ TempWeapon ] ) Host_SecondaryWeaponsGot[ Player ][ TempWeapon ] = 0;
						break;

					default:
						break;
				}
			}

			if( lpFUpdate->ShortGlobalShip.Flags & SHIP_PrimFire )
			{
				Weapon = lpFUpdate->ShortGlobalShip.Primary;

				if( Weapon >= MAXPRIMARYWEAPONS ) break;
				if( !Host_PrimaryWeaponsGot[ Player ][ Weapon ] ) return( FALSE );

				Ammo = GetPrimaryAmmoUsage( Player, Weapon );

				switch( Weapon )
				{
					case PULSAR:
					case TRANSPULSE_CANNON:
					case LASER:
					case NME_BULLET1:
					case NME_PULSAR:
					case NME_TRANSPULSE:
					case NME_LASER:
					case NME_LIGHTNING:
					case FLAMES:
					case NME_POWERLASER:
						if( ( Ships[ Player ].SuperNashramTimer == 0.0F ) && !BombTag )
						{
							if( Host_GeneralAmmo[ Player ] == 0.0F ) return( FALSE );
							Host_GeneralAmmoUsed += Ammo;
							Host_GeneralAmmo[ Player ] -= Ammo;
							if( Host_GeneralAmmo[ Player ] < 0.0F ) Host_GeneralAmmo[ Player ] = 0.0F;
						}

//						AddMessageToQue( "Update:FirePrimary : %s, Got = %hd, Ammo = %f", PrimaryDescription[ Weapon ],
//																	Host_PrimaryWeaponsGot[ Player ][ Weapon ],
//																	Host_GeneralAmmo[ Player ] );

						break;

					case TROJAX:
					case NME_TROJAX:
//						AddMessageToQue( "Update:FirePrimary : %s, Got = %hd, Ammo = %f", PrimaryDescription[ Weapon ],
//																	Host_PrimaryWeaponsGot[ Player ][ Weapon ],
//																	Host_GeneralAmmo[ Player ] );
						break;

					case PYROLITE_RIFLE:
					case NME_PYROLITE:
						if( ( Ships[ Player ].SuperNashramTimer == 0.0F ) && !BombTag )
						{
							if( Host_PyroliteAmmo[ Player ] == 0.0F ) return( FALSE );
							Host_PyroliteAmmoUsed += Ammo;
							Host_PyroliteAmmo[ Player ] -= Ammo;
							if( Host_PyroliteAmmo[ Player ] < 0.0F ) Host_PyroliteAmmo[ Player ] = 0.0F;
						}
		
//						AddMessageToQue( "Update:FirePrimary : %s, Got = %hd, Ammo = %f", PrimaryDescription[ Weapon ],
//																	Host_PrimaryWeaponsGot[ Player ][ Weapon ],
//																	Host_PyroliteAmmo[ Player ] );
						break;

					case SUSS_GUN:
					case NME_SUSS_GUN:
						if( ( Ships[ Player ].SuperNashramTimer == 0.0F ) && !BombTag )
						{
							if( Host_SussGunAmmo[ Player ] == 0.0F ) return( FALSE );
							Host_SussGunAmmoUsed += Ammo;
							Host_SussGunAmmo[ Player ] -= Ammo;
							if( Host_SussGunAmmo[ Player ] < 0.0F ) Host_SussGunAmmo[ Player ] = 0.0F;
						}

//						AddMessageToQue( "Update:FirePrimary : %s, Got = %hd, Ammo = %f", PrimaryDescription[ Weapon ],
//																	Host_PrimaryWeaponsGot[ Player ][ Weapon ],
//																	Host_SussGunAmmo[ Player ] );
						break;

					case ORBITPULSAR:
						break;

					default:
						break;
				}
			}
			break;

		case MSG_GUARANTEEDMSG:
			lpGuaranteedMsg = (LPGUARANTEEDMSG)MsgPnt;

			MsgPnt = &lpGuaranteedMsg->StartOfMessage;
			return( UpdateAmmoAndValidateMessage( MsgPnt ) );
			break;


		case MSG_PRIMBULLPOSDIR:
		    lpPrimBullPosDir = (LPPRIMBULLPOSDIRMSG)MsgPnt;
		
			if( lpPrimBullPosDir->PrimBullPosDir.OwnerType != OWNER_SHIP ) break;

			Weapon = lpPrimBullPosDir->PrimBullPosDir.Weapon; 

//			AddMessageToQue( "PrimBullPosDir : %s, Got = %d, Ammo = %d", PrimaryDescription[ Weapon ],
//																	Host_PrimaryWeaponsGot[ Player ][ Weapon ],
//																	Host_GeneralAmmo[ Player ] );

			switch( Weapon )
			{
				case PULSAR:
				case TRANSPULSE_CANNON:
				case LASER:
				case NME_BULLET1:
				case NME_PULSAR:
				case NME_TRANSPULSE:
				case NME_LASER:
				case NME_LIGHTNING:
				case FLAMES:
				case NME_POWERLASER:
						if( ( Ships[ Player ].SuperNashramTimer == 0.0F ) && !BombTag )
					{
						if( Host_GeneralAmmo[ Player ] == 0.0F ) return( FALSE );
						Host_GeneralAmmoUsed += PrimaryWeaponAttribs[ Weapon ].AmmoUsage[ PowerLevel ];
						Host_GeneralAmmo[ Player ] -= PrimaryWeaponAttribs[ Weapon ].AmmoUsage[ PowerLevel ];
						if( Host_GeneralAmmo[ Player ] < 0.0F ) Host_GeneralAmmo[ Player ] = 0.0F;
					}
					break;

				case TROJAX:
				case NME_TROJAX:
					break;

				case PYROLITE_RIFLE:
				case NME_PYROLITE:
					if( ( Ships[ Player ].SuperNashramTimer == 0.0F ) && !BombTag )
					{
						if( Host_PyroliteAmmo[ Player ] == 0.0F ) return( FALSE );
						Host_PyroliteAmmoUsed += PrimaryWeaponAttribs[ Weapon ].AmmoUsage[ PowerLevel ];
						Host_PyroliteAmmo[ Player ] -= PrimaryWeaponAttribs[ Weapon ].AmmoUsage[ PowerLevel ];
						if( Host_PyroliteAmmo[ Player ] < 0.0F ) Host_PyroliteAmmo[ Player ] = 0.0F;
					}
					break;

				case SUSS_GUN:
				case NME_SUSS_GUN:
					if( ( Ships[ Player ].SuperNashramTimer == 0.0F ) && !BombTag )
					{
						if( Host_SussGunAmmo[ Player ] == 0.0F ) return( FALSE );
						Host_SussGunAmmoUsed += PrimaryWeaponAttribs[ Weapon ].AmmoUsage[ PowerLevel ];
						Host_SussGunAmmo[ Player ] -= PrimaryWeaponAttribs[ Weapon ].AmmoUsage[ PowerLevel ];
						if( Host_SussGunAmmo[ Player ] < 0.0F ) Host_SussGunAmmo[ Player ] = 0.0F;
					}
					break;

				case ORBITPULSAR:
					break;

				default:
					break;
			}
			break;

		case MSG_SECBULLPOSDIR:
   			lpSecBullPosDir = (LPSECBULLPOSDIRMSG)MsgPnt;

			if( lpSecBullPosDir->SecBullPosDir.OwnerType != OWNER_SHIP ) break;

			Weapon		= lpSecBullPosDir->SecBullPosDir.Weapon;
			TempWeapon	= ConvSecToNormWeapon( Weapon );

//			AddMessageToQue( "SecBullPosDir : %s, Got = %d, Ammo = %d", SecondaryDescription[ TempWeapon ],
//																		Host_SecondaryWeaponsGot[ Player ][ TempWeapon ],
//																		Host_SecondaryAmmo[ Player ][ TempWeapon ] );

			switch( Weapon )
			{
				case MUGMISSILE:
				case SOLARISMISSILE:
				case THIEFMISSILE:
				case SCATTERMISSILE:
				case GRAVGONMISSILE:
				case MULTIPLEMISSILE:
				case TITANSTARMISSILE:
				case PINEMISSILE:
				case TITANSTARSHRAPNEL:
				case ENEMYSPIRALMISSILE:
				case ENEMYHOMINGMISSILE:
				case ENEMYBLUEHOMINGMISSILE:
				case ENEMYFIREBALL:
				case ENEMYTENTACLE:
				case ENEMYDEPTHCHARGE:
					break;

				case PURGEMINE:
				case PINEMINE:
				case QUANTUMMINE:
				case SPIDERMINE:
					if( !Host_SecondaryWeaponsGot[ Player ][ TempWeapon ] ) return( FALSE );
					if( !Host_SecondaryAmmo[ Player ][ TempWeapon ] ) return( FALSE );

					Host_SecondaryAmmo[ Player ][ TempWeapon ]--;
					if( !Host_SecondaryAmmo[ Player ][ TempWeapon ] ) Host_SecondaryWeaponsGot[ Player ][ TempWeapon ] = 0;
					break;

				default:
					break;
			}
			break;

		case MSG_TITANBITS:
			break;

		default:
			break;
	}

	return( TRUE );
}




/*�������������������������������������������������������������������
	Procedure	:		Add Guaranteed Message...
	Input		:		int MessageLength, void * Message
	Output		:		BOOL TRUE/FALSE
�������������������������������������������������������������������*/
BOOL AddGuaranteedToServersGuaranteedQue( LPGUARANTEEDMSG lpGM )
//BOOL AddGuaranteedMessage( int MessageLength , void * Message , BYTE MsgType, BOOL OverideOlderMessage, BOOL AllPlayers )
{
#ifdef	GUARANTEEDMESSAGES
	GUARANTEEDMSGHEADER * GM = NULL;
	GUARANTEEDMSGHEADER * GM2 = NULL;
	GUARANTEEDMSGHEADER * LastGM;
	GUARANTEEDMSG * GMm;
	DWORD send_to = 0;
	uint32 Ack;
	int i;
	int MessageLength;
	BYTE * Message;
	BYTE MsgType;
	BOOL OverideOlderMessage;
	BOOL AllPlayers;

	if( PlayDemo )
		return TRUE;
	if( !IsServer )
		return TRUE;

	Message = &lpGM->StartOfMessage;
	MsgType = *Message;
	MessageLength = RealPacketSize[MsgType];

	OverideOlderMessage = lpGM->OverideOlderMessage;
	AllPlayers = lpGM->AllPlayers;

	// only record if message is sent to whole of the group....
	if( RecordDemo && !BigPackets )
	{
		if( ( MyGameStatus == STATUS_Normal )
		&& ( MsgType != MSG_INIT ) 
		&& ( MsgType != MSG_HEREIAM ) 
		&& ( MsgType != MSG_SHORTSTATS     ) 
		&& ( MsgType != MSG_SHORTPICKUP    ) 
		&& ( MsgType != MSG_SHORTREGENSLOT ) 
		&& ( MsgType != MSG_SHORTTRIGGER   ) 
		&& ( MsgType != MSG_SHORTTRIGVAR   )  
		&& ( MsgType != MSG_LEVELNAMES     )  
		&& ( MsgType != MSG_TRACKERINFO    )  
		&& ( MsgType != MSG_SHORTMINE      ) )
		{
			QueryPerformanceCounter((LARGE_INTEGER *) &TempTime);
			TempTime = TempTime - GameStartedTime;
		
			Demo_fwrite( &TempTime, sizeof(LONGLONG), 1, DemoFp );
		
			Demo_fwrite( &MessageLength, sizeof(int), 1, DemoFp );
			Demo_fwrite( &dcoID, sizeof(DPID), 1, DemoFp );
			Demo_fwrite( Message, MessageLength, 1, DemoFp );
		}
	}

#if 0
	if( OverideOlderMessage )
	{
		// Try and find a message of the same type that has allready been qued and overide it...
		GM2 = GMs;
		while( GM2 )
		{
			if( ( MsgType == GM2->MsgType ) && ( lpGM->WhoIAm == *(Message+1) ) )
			{
				GM = GM2;
				break;
			}
			GM2 = GM2->Next;
		}
	}
#endif

	if( !GM )
	{
		GM = (GUARANTEEDMSGHEADER*) malloc( sizeof(GUARANTEEDMSGHEADER) + MessageLength + sizeof( GUARANTEEDMSG ) -1 );
		if( !GM )
		{
			return FALSE;
		}

		GuaranteedMessagesActive++;
		if( GuaranteedMessagesActive > GuaranteedMessagesActiveMax )
			GuaranteedMessagesActiveMax = GuaranteedMessagesActive;

		LastGM = GMs;
		if( LastGM )
		{
			LastGM->Prev = GM;
		}
		GM->Next = LastGM;
		GM->Prev = NULL;
		GMs = GM;
		if( !OldestGMs )
		{
			OldestGMs = GM;
		}
	}


	GMm = (GUARANTEEDMSG*) &GM->Message;

	
	memcpy( &GMm->StartOfMessage, Message, MessageLength );

	GM->MsgType = MsgType;
	QueryPerformanceCounter((LARGE_INTEGER *) &GM->Time);
	QueryPerformanceCounter((LARGE_INTEGER *) &GM->OverallTime);
	GM->OverallTime += GuaranteedMessagesOverallTime * Freq;
	GM->ID = GuaranteedMessagesID++;
	GM->OverideOlderMessage = OverideOlderMessage;
	GM->AllPlayers = AllPlayers;

	if( AllPlayers )
	{
		Ack = 0xffffffff;
//		Ack &= ~(1<<WhoIAm);
	}else{
		Ack = 0;
		for( i = 0 ; i < MAX_PLAYERS ; i++ )
		{
			if(
			  ( (GameStatus[i]!=STATUS_GetPlayerNum)&& (GameStatus[i]!=STATUS_LeftCrashed) && (GameStatus[i]!=STATUS_Left) && (GameStatus[i]!=STATUS_Null) ) &&
			  (i!=WhoIAm) )
			{
				Ack |= 1<<i;
			}
		}
	}
	Ack &= ~(1<<lpGM->WhoIAm);
	Ack |= 1;

	GM->Ack = Ack;
	GM->Count = 0;
	GM->MessageLength = MessageLength + sizeof( GUARANTEEDMSG ) -1;
#endif
	return TRUE;
}


/*�������������������������������������������������������������������
	Procedure	:		Check If A Player Is cheating...If he is Dont let him hurt anyone..
	Input		:		BYTE Player
	Output		:		BOOL TRUE/FALSE
�������������������������������������������������������������������*/

BOOL	CheckIfPlayerCheats( BYTE player )
{
	if( ( ( Ships[player].Object.Flags & SHIP_SuperNashram ) && !Ships[player].SuperNashramTimer ) ||
		( ( Ships[player].Object.Flags & SHIP_Invul ) && !Ships[player].InvulTimer ) ||
		( ( Ships[player].Object.Flags & SHIP_Stealth ) && !Ships[player].StealthTime ) )
		return TRUE;
	return FALSE;
}

BOOL AutoJoinSession( void )
{
	DWORD size;
	char session_guidtext[ 256 ];

	if ( !SessionGuidExists )
	{
		// get session GUID from reg
		if ( ghCondemnedKey )
		{
			size = sizeof( session_guidtext );
			if ( RegGet( "SessionGuid", (LPBYTE)&session_guidtext, &size ) != ERROR_SUCCESS)
			{
				DebugPrintf("unable to open reg key 'SessionGuid' ");
				return FALSE;
			}
		}else
		{
			DebugPrintf("no forsaken registery entries\n");
			return FALSE;
		}

		if ( GUIDFromString( session_guidtext, &autojoin_session_guid ) != S_OK )
		{
			DebugPrintf("unable to convert session guid from string\n");
			return FALSE;
		}
	}

	MyGameStatus = STATUS_TryingToFindSession;
	FindSessionTimeout = FIND_SESSION_TIMEOUT;

	return TRUE;
}

#ifdef OPT_ON
#pragma optimize( "", off )
#endif


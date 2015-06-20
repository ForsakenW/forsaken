// in the following text:
// <team name>=any one of LT_TEAM_??? defined below

// text.c
#define LT_TEAM_1       "Rouge"
#define LT_TEAM_2       "Verte"
#define LT_TEAM_3       "Bleue" 
#define LT_TEAM_4       "Jaune"

#define LIVES           "Vies"
#define TEAM            "Equipe"

// Mydplay.c
#define IS_JOINING_THE_GAME "rejoint la partie"     // player is joining the games
#define THE_SESSION_HAS_BEEN_LOST_PLEASE_QUIT "La session a �t� perdue ; veuillez quitter"
#define YOU_HAVE_BECOME_THE_HOST "Vous �tes maintenant l'h�te"
#define HAS_LEFT_THE_GAME "a quitt� la partie"
#define YOUVE_BEEN_SCATTERED "Vous avez �t� dispers�"
#define FROM_YOUR_OWN_TEAM "de votre �quipe"
#define YOU "vous"
#define GOT_CAUGHT_WITH_A_BOMB "avez �t� pris avec une bombe"
#define WITH_THE_BOUNTY "avec le tr�sor"
#define NO_POINTS_FOR_KILLING_PLAYER_WITHOUT_THE_BOUNTY "pas de points pour tuer %s sans le tr�sor" // %s= Name of Player
#define HIMSELF "lui-m�me"
#define ON_HIS_OWN_TEAM "dans son �quipe"
#define PACKETS_PER_SECOND_SET "Paquets par seconde"
#define THE_COLOUR_TEAM_HAVE_SCORED "l'�quipe %s a marqu�" // %s=<team name>
#define THE_COLOUR_TEAM_ARE_RETURNING_THEIR_FLAG "l'�quipe %s rapporte son drapeau "    // %s=<team name>
#define THE_COLOUR_TEAM_FLAG_HAS_BEEN_RETURNED "le drapeau de l'�quipe %s a �t� rapport� "  // %s=<team name>
#define THE_COLOUR_TEAM_FLAG_HAS_DRIFTED_INTO_THEIR_GOAL "le drapeau de l'�quipe %s est pass� dans son but" // %s=<team name>
#define THE_COLOUR_TEAM_FLAG_HAS_ESCAPED_FROM_THEIR_GOAL "le drapeau de l'�quipe %s a quitt� son but "  // %s=<team name>
#define HAS_GOT_THE_BOUNTY "d�tient le tr�sor"
#define YOU_HAVE_GOT_A_NEW_BOMB "Vous avez une nouvelle bombe"
#define ON_YOUR_OWN_TEAM "Dans votre �quipe"

// Multiplayer.c
#define YOU_NEED_TO_INSATLL_THE_DIRECT_PLAY_50A_UPDATE "Vous devez installer DirectX 6\n"
#define CONNECTION_INITIALIZATION_ERROR "Erreur initialisation connexion..."
#define COULDNT_GET_SERVICE_PROVIDER_CAPS "Imp. acc�der prestataire services"
#define COULDNT_OPEN_SESSION "Imp. ouvrir session"
#define COULDNT_CREATE_PLAYER "Imp. cr�er joueur"
#define NO_MULTIPLAYER_LEVELS "Pas de niveau multijoueur"


// Pickups.c
// in the following text:
// <player name>=any player's name (typed in by player)
// <pickup name>=any one of LT_PICKUP_??? defined below

#define LT_PICKUP_TROJAX                "Trojax"                        // Primary Weapons
#define LT_PICKUP_PYROLITE              "Fusil Pyrolite"
#define LT_PICKUP_TRANSPULSE            "Transpulseur "
#define LT_PICKUP_SUSSGUN               "Arme intel."
#define LT_PICKUP_LASER                 "Rayon laser"
#define LT_PICKUP_MUG                   "Missile Mug"                   // Secondary Weapons
#define LT_PICKUP_MUG_PACK              "Missiles Mug"
#define LT_PICKUP_SOLARIS               "Missile thermoguid�"
#define LT_PICKUP_SOLARIS_PACK          "Pack missile thermoguid�"
#define LT_PICKUP_THIEF                 "Missile Voleur"
#define LT_PICKUP_SCATTER               "Missile dispers�"
#define LT_PICKUP_GRAVGON               "Missile Gravgon"
#define LT_PICKUP_MFRL                  "Lance-roquettes"
#define LT_PICKUP_TITAN                 "Missile Titan"
#define LT_PICKUP_PURGE                 "Pack mine purgeante"
#define LT_PICKUP_PINE                  "Pack mine multi-t�te "
#define LT_PICKUP_QUANTUM               "Pack mine quantum"
#define LT_PICKUP_SPIDER                "Pack mine Araign�e"
#define LT_PICKUP_PARASITE              "Mine parasite"
#define LT_PICKUP_FLARE                 "Leurres IR"
#define LT_PICKUP_GENAMMO               "Munitions g�n."                    // Ammo
#define LT_PICKUP_PYROFUEL              "Carb. Pyrolite"
#define LT_PICKUP_SUSSAMMO              "Munitions intel."
#define LT_PICKUP_POWER_POD             "Pod �nerg."                    // Extras
#define LT_PICKUP_SHIELD                "Bouclier"
#define LT_PICKUP_INVULBERABILITY       "Invuln�rabilit�"
#define LT_PICKUP_EXTRA_LIFE            "Vie suppl."
#define LT_PICKUP_TARGETING_COMPUTER    "Ord. De vis�e"
#define LT_PICKUP_SMOKE                 "Traces fum�e"
#define LT_PICKUP_NITRO                 "Nitro"
#define LT_PICKUP_GOGGLES               "Lunettes"
#define LT_PICKUP_GOLD_BARS             "Lingots d'or"
#define LT_PICKUP_STEALTH               "Manteau invisible"
#define LT_PICKUP_CRYSTAL               "Cristal"
#define LT_PICKUP_ORBITAL               "Pulsar en orbite"
#define LT_PICKUP_GOLDEN_POWER_POD      "Pod �nerg. or"
#define LT_PICKUP_DNA                   "ADN"
#define LT_PICKUP_BOMB                  "Bombe"
#define LT_PICKUP_GOLDEN_IDOL           "Statuette or"

#define YOU_ALREADY_HAVE                "Vous avez d�j� un(e) %s" // %s=<pickup name>
#define YOU_ALREADY_HAVE_A              " Vous avez d�j� un(e) %s" // %s=<pickup name>
#define YOU_ALREADY_HAVE_MAX            "Vous avez d�j� le max de %s" // %s=<pickup name>
#define FULL_POWER_LEVEL                "Niv. puis. max"
#define POWER_POD_LEVEL                 "Niv. Pod �nerg. %d" // %d=1, 2 or 3
#define YOU_ALREADY_HAVE_MAX_POWER      "Vous avez atteint puis. max"
#define YOU_CANT_HANDLE_ANY_MORE        "Vous avez atteint votre limite"
#define YOUVE_EARNED_EXTRA_LIFE         "Vous avez gagn� une vie suppl�mentaire..."
#define YOU_HAVE_ONE_GOLD_BAR           "Vous avez %hd lingot d'or" // %hd=1
#define YOU_HAVE_GOLD_BARS              "Vous avez %hd lingots d'or" // %hd=2, 3, 4...
#define YOU_HAVE_ONE_CRYSTAL            "Vous avez %d cristal" // %hd=1
#define YOU_HAVE_CRYSTALS               "Vous avez %d cristaux" // %hd=2, 3, 4...

#define TAKE_FLAG_TO_GOAL               "apportez le drapeau au but de l'�quipe %s" // %s=<team name>
#define SOMEONE_HAS_GOT_THE_FLAG        "%s, de l'�quipe %s, a le drapeau" // %s1=<player name>, %s2=<team name>
#define YOU_HAVE_GOT_THE_BOUNTY         "vous avez trouv� le tr�sor" 
#define TEAM_FLAG_RETURNED              "le drapeau de l'�quipe %s a �t� rapport�" // %s=<team name>
#define RETURN_TEAM_FLAG                "rapportez le drapeau au but de l'�quipe %s" // %s=<team name>
#define CANNOT_PICKUP_OWN_FLAG          "vous ne pouvez pas prendre le drapeau de votre �quipe"
#define SOMEONE_HAS_OTHER_TEAM_FLAG     "%s, de l'�quipe %s, a le drapeau de l'�quipe %s" // %s1=<player name>, %s2=<team name>, %s3=<team name>
#define FLAG_DRIFTED_BACK               "le drapeau de l'�quipe %s est retourn� � son but" // %s=<team name>
#define FLAG_ESCAPED                    "le drapeau de l'�quipe %s a quitt� son but" // %s=<team name>

// oct2.c
#define A_BOMB_KILLED_YOU               "Vous avez �t� tu� par une bombe..."

// models.c
// in the following text:
// <death method>=any one of the LT_DEATHMETHOD_??? defined below
#define AN_ENEMY_KILLED_YOU             "vous avez �t� %s" // %s=<death method>
#define ENEMY_KILLED_YOU                "l'ennemi vous a %s" // %s=<death method>
#define YOU_KILLED_YOURSELF_HOW         "vous vous �tes %s" // %s=<death method>
#define SOMEONE_KILLED_YOU              "%s, %s, vous a %s" // %s1=<player name> %s2=<death method>, %s3=either FROM_YOUR_OWN_TEAM (see following line) or empty
#define FROM_YOUR_OWN_TEAM              "de votre �quipe"
#define YOU_DIED                        "vous �tes mort"

// primary.c
#define LT_DEATHMETHOD_KILLED           "tu�"
#define LT_DEATHMETHOD_PURGE_MINED      "tu� par mine purgeante"
#define LT_DEATHMETHOD_PINE_MINED       "tu� par mine multi-t�te"
#define LT_DEATHMETHOD_QUANTUM_MINED    "tu� par mine quantum"
#define LT_DEATHMETHOD_SPIDER_MINED     "tu� par mine araign�e"

#define YOU_DONT_HAVE_ANY_AMMO          "Vous n'avez pas de munitions"
#define YOU_DONT_HAVE_THAT_WEAPON       "Vous n'avez pas cette arme"
#define LASER_OVERHEATED                "Surchauffe du laser"

// secondary.c
#define INCOMING_MISSILE                "Missile en approche"
#define YOUVE_BEEN_SCATTERED            "Vous avez �t� dispers�"

// ships.c
#define TEAM_SCORED                     "l'�quipe %s a marqu�" // %s=<team name>
#define OTHER_TEAM_FLAG_RETURNED        "l'�quipe %s a rapport� son drapeau" // %s=<team name>
#define YOU_NEED_FLAG                   "il vous faut le drapeau de l'�quipe %s pour marquer" // %s=<team name>
#define YOU_KILLED_YOURSELF             "vous vous �tes suicid�"
#define NO_LIVES_LEFT                   "Plus de vie"
#define LAST_LIFE                       "Derni�re vie"
#define ONE_LIFE_LEFT                   "Plus qu'%d vie" // %d=1
#define LIVES_LEFT                      "Plus que %d vies" // %d=2, 3, 4...
#define RESTART_ACTIVATED               "Position de red�marrage activ�e"

#define SHIELD_CRITICAL                 "Bouclier �tat critique"
#define HULL_CRITICAL                   "Coque �tat critique"


// screenpolys.c
#define OUT_OF_TIME                     "Temps �coul�"
#define IF_YOU_CANT_TAKE_THE_HEAT       "Si la pression est trop forte"
#define GET_OUT_OF_THE_KITCHEN          "ne restez pas l�...."

// credits.c
#define GAME_COMPLETE1              "FELICITATIONS"
#define GAME_COMPLETE2              "Vous avez termin� tous les"
#define GAME_COMPLETE3              "niveaux."

#define COMPLETE_NOT_ALL_CRYSTALS1  "mais vous n'avez pas obtenu"
#define COMPLETE_NOT_ALL_CRYSTALS2  "tous les cristaux."
#define COMPLETE_NOT_ALL_CRYSTALS3  "Vous devez recommencer"
#define COMPLETE_NOT_ALL_CRYSTALS4  "si vous voulez �tre"
#define COMPLETE_NOT_ALL_CRYSTALS5  "correctement r�compens�."

#define COMPLETE_ALL_CRYSTALS1      "et ramass� tous les"
#define COMPLETE_ALL_CRYSTALS2      "cristaux."
#define COMPLETE_ALL_CRYSTALS3      "Vous avez re�u"
#define COMPLETE_ALL_CRYSTALS4      "le biker secret."

#define COMPLETE_ALLBUT1_CRYSTALS1  "vous avez termin� le"
#define COMPLETE_ALLBUT1_CRYSTALS2  "niveau secret."
#define COMPLETE_ALLBUT1_CRYSTALS3  "mais vous n'avez pas le"
#define COMPLETE_ALLBUT1_CRYSTALS4  "dernier cristal. Vous ferez"
#define COMPLETE_ALLBUT1_CRYSTALS5  "mieux la prochaine fois."

#define PRESS_ANY_KEY1              "App."
#define PRESS_ANY_KEY2              "sur une touche"

#define DEFAULT_NEWNAME "nom"

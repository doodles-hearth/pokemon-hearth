SunriseVillage_PlayersHouse_LR_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SunriseVillage_PlayersHouse_LR_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SunriseVillage_PlayersHouse_LR_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SunriseVillage_PlayersHouse_LR_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_unset FLAG_RECEIVED_STARTER, SunriseVillage_PlayersHouse_LR_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

SunriseVillage_PlayersHouse_LR_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setmetatile 4, 4, METATILE_HouseBeige_Scroll, TRUE
	return

SunriseVillage_PlayersHouse_LR_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_SUNRISE_VILLAGE_INTRO_STATE, 2, SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi
	.2byte 0


SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi::
	lock
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	turnobject 1, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	special GetPlayerBrotherSisterString
	setspeaker SP_NAME_BIG_SIS
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi_Text_0
	closemessage
	applymovement 1, SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi_Movement_0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	waitmovement 0
	playse SE_EXIT
	removeobject 1
	waitse
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 3
	setflag FLAG_HIDE_BIGSIS_HOME
	release
	end


SunriseVillage_PlayersHouse_LR_EventScript_BigSis::
	lock
	faceplayer
	setspeaker SP_NAME_BIG_SIS
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 4
	goto_if_le SunriseVillage_PlayersHouse_LR_EventScript_BigSis_2
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 6
	goto_if_le SunriseVillage_PlayersHouse_LR_EventScript_BigSis_3
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 7
	goto_if_eq SunriseVillage_PlayersHouse_LR_EventScript_BigSis_4
	special GetPlayerBroSisString
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_4
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	setspeaker SP_NAME_BIG_SIS
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_5
	closemessage
SunriseVillage_PlayersHouse_LR_EventScript_BigSis_1:
	release
	return

SunriseVillage_PlayersHouse_LR_EventScript_BigSis_2:
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_0
	closemessage
	goto SunriseVillage_PlayersHouse_LR_EventScript_BigSis_1

SunriseVillage_PlayersHouse_LR_EventScript_BigSis_3:
	special GetPlayerBrotherSisterString
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_1
	closemessage
	goto SunriseVillage_PlayersHouse_LR_EventScript_BigSis_1

SunriseVillage_PlayersHouse_LR_EventScript_BigSis_4:
	special GetPlayerBrotherSisterString
	bufferspeciesname STR_VAR_2, VAR_STARTER_MON
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_2
	closemessage
	giveitem ITEM_TOKU_MAP
	special GetPlayerBrotherSisterString
	setspeaker SP_NAME_BIG_SIS
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_3
	closemessage
	setnamedmon SPECIES_CHATOT
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 8
	goto SunriseVillage_PlayersHouse_LR_EventScript_BigSis_1


SunriseVillage_PlayersHouse_LR_EventScript_Eevee::
	lock
	faceplayer
	setseenmon SPECIES_EEVEE
	setspeakertomonname SPECIES_EEVEE
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_Eevee_Text_0
	waitmoncry
	release
	return


SunriseVillage_PlayersHouse_LR_EventScript_RivalsNote::
	lock
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_RivalsNote_Text_0
	closemessage
	release
	end


SunriseVillage_PlayersHouse_LR_EventScript_Gong::
	lock
	goto_if_set FLAG_HIDE_BIGSIS_HOME, SunriseVillage_PlayersHouse_LR_EventScript_Gong_2
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_Gong_Text_1
SunriseVillage_PlayersHouse_LR_EventScript_Gong_1:
	closemessage
	release
	return

SunriseVillage_PlayersHouse_LR_EventScript_Gong_2:
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_Gong_Text_0
	goto SunriseVillage_PlayersHouse_LR_EventScript_Gong_1


SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi_Movement_0:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_BIG_SIS EMOTE_NORMAL}Oh, {PLAYER}, you're up! Ready for\n"
	.string "the big event?\p"
	.string "Are you excited? I sure hope you are,\n"
	.string "because I'm VERY EXCITED!\p"
	.string "I have to head out! Don't be late, I\n"
	.string "know you, little {STR_VAR_1}!\p"
	.string "By the way, your friend Natsuki left\n"
	.string "you a note.\l"
	.string "Make sure you read it!$"

SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_BIG_SIS EMOTE_NORMAL}What are you still doing here? You're\n"
	.string "late for the distribution!\p"
	.string "Go to Kaba's house right now!$"

SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_BIG_SIS EMOTE_NORMAL}Hey little {STR_VAR_1}! See how\n"
	.string "cute my new Pokémon is?\p"
	.string "By the way, I heard Natsuki was\n"
	.string "waiting for you at Elder Kaba's house.\l"
	.string "You should probably go see them.$"

SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_BIG_SIS EMOTE_NORMAL}Hey little {STR_VAR_1}! See how\n"
	.string "cute my new Pokémon is?\p"
	.string "Oh, who is that lovely little thing\n"
	.string "with you?\l"
	.string "{STR_VAR_2}, huh?\p"
	.string "Looks like it already likes you a lot!\n"
	.string "You're going to make a great Wielder,\l"
	.string "I know it!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "So you're going on a journey…\p"
	.string "That's great! I'm proud of you,\n"
	.string "{PLAYER}.\p"
	.string "I know you'll get lost though, so I'll\n"
	.string "lend you my map of Toku!$"

SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_BIG_SIS EMOTE_NORMAL}Alrighty! You all set? Have a safe\njourney, little {STR_VAR_1}.\p"
	.string "Maybe I'll see you around!\p"
	.string "Come home sometimes though, will you?\nYou and your Pokémon can rest here!\p"
	.string "See you soon!\nI'll send you Chatot messages!$"

SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_BIG_SIS EMOTE_NORMAL}Hey {PLAYER}! How's it going?\p"
	.string "Here, rest for a bit.$"

SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_5:
	.string "{CREATE_MUGSHOT MUGSHOT_BIG_SIS EMOTE_NORMAL}See you around, little\n"
	.string "{STR_VAR_1}.$"

SunriseVillage_PlayersHouse_LR_EventScript_Eevee_Text_0:
	.string "Eee!$"

SunriseVillage_PlayersHouse_LR_EventScript_RivalsNote_Text_0:
	.string "“Hey {PLAYER},\n"
	.string "Going down to the beach before the\l"
	.string "giveaway, if you wanna hang out.\l"
	.string "-Natsuki”$"

SunriseVillage_PlayersHouse_LR_EventScript_Gong_Text_0:
	.string "It's a gong.\n"
	.string "GONG!… … …$"

SunriseVillage_PlayersHouse_LR_EventScript_Gong_Text_1:
	.string "It's a gong.\n"
	.string "GONG!… … …\p"
	.string "Let's not annoy Big Sis too much.$"

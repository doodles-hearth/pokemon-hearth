SunriseVillage_PlayersHouse_LR_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SunriseVillage_PlayersHouse_LR_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SunriseVillage_PlayersHouse_LR_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SunriseVillage_PlayersHouse_LR_MapScripts_MAP_SCRIPT_ON_LOAD:
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 4
	goto_if_lt SunriseVillage_PlayersHouse_LR_MapScripts_MAP_SCRIPT_ON_LOAD_1
	removeobject 2
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
	speakername SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi_Text_0
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi_Text_1
	closemessage
	applymovement 1, SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi_Movement_0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject 1
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 3
	setflag FLAG_HIDE_BIGSIS_HOME
	release
	end


SunriseVillage_PlayersHouse_LR_EventScript_BigSis::
	lock
	faceplayer
	speakername SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi_Text_0
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 4
	goto_if_le SunriseVillage_PlayersHouse_LR_EventScript_BigSis_2
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 6
	goto_if_le SunriseVillage_PlayersHouse_LR_EventScript_BigSis_3
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 7
	goto_if_eq SunriseVillage_PlayersHouse_LR_EventScript_BigSis_4
	special GetPlayerBroSisString
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_6
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	speakername SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi_Text_0
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_7
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
	giveitem ITEM_OINTMENT, 5
	giveitem ITEM_POKE_BALL, 5
	speakername SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi_Text_0
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_3
	closemessage
	giveitem ITEM_TOWN_MAP
	speakername SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi_Text_0
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_4
	closemessage
	giveitem ITEM_ENTEI_STATUETTE
	special GetPlayerBrotherSisterString
	speakername SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi_Text_0
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_5
	closemessage
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 8
	setflag FLAG_HIDE_GUARD_SUNRISE_VILLAGE
	goto SunriseVillage_PlayersHouse_LR_EventScript_BigSis_1


SunriseVillage_PlayersHouse_LR_EventScript_Eevee::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_EEVEE
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_Eevee_Text_0
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	waitmoncry
	release
	return


SunriseVillage_PlayersHouse_LR_EventScript_RivalsNote::
	lock
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_RivalsNote_Text_0
	closemessage
	release
	end


SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi_Movement_0:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi_Text_0:
	.string "Big sis$"

SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi_Text_1:
	.string "Oh, {PLAYER}, you're up! Ready for\n"
	.string "the big event?\p"
	.string "Are you excited? I sure hope you are,\n"
	.string "because I'm VERY EXCITED!\p"
	.string "I have to head out! Don't be late, I\n"
	.string "know you, little {STR_VAR_1}!\p"
	.string "By the way, your friend Natsuki left\n"
	.string "you a note.\p"
	.string "Make sure you read it!$"

SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_0:
	.string "What are you still doing here? You're\n"
	.string "late for the distribution!\p"
	.string "Go to Kaba's house right now!$"

SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_1:
	.string "Hey little {STR_VAR_1}! See how\n"
	.string "cute my new Pokémon is?\p"
	.string "By the way, I heard Natsuki was\n"
	.string "waiting for you at Elder Kaba's house.\l"
	.string "You should probably go see them.$"

SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_2:
	.string "Hey little {STR_VAR_1}! See how\n"
	.string "cute my new Pokémon is?\p"
	.string "Oh, who is that lovely little thing\n"
	.string "with you?\p"
	.string "{STR_VAR_2}, huh?\p"
	.string "Looks like it already likes you a lot!\n"
	.string "You're going to make a great wielder, I\l"
	.string "know it!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "So you're going on a journey…\p"
	.string "That's great! I'm proud of you,\n"
	.string "{PLAYER}.\p"
	.string "Here, take some medicine for your\n"
	.string "{STR_VAR_2} and some of these\l"
	.string "Poké Balls, in case you find any good\l"
	.string "Pokémon!$"

SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_3:
	.string "Oh, and I'm sure you're going to get\n"
	.string "lost, so I'll lend you my map of Toku!$"

SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_4:
	.string "I think that was all…\n"
	.string "Ah, one last thing! Take my good luck\l"
	.string "statuette with you.\p"
	.string "I like the tradition, so indulge me,\n"
	.string "alright? Please? Everyone carries\l"
	.string "one!$"

SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_5:
	.string "Alrighty! You all set? Have a safe\n"
	.string "journey, little {STR_VAR_1}.\p"
	.string "Maybe I'll see you around!\p"
	.string "Come back home sometimes though, will\n"
	.string "you?$"

SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_6:
	.string "Hey {PLAYER}! How's it going?\p"
	.string "Here, rest for a bit.$"

SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_7:
	.string "See you around, little\n"
	.string "{STR_VAR_1}.$"

SunriseVillage_PlayersHouse_LR_EventScript_Eevee_Text_0:
	.string "Eee!$"

SunriseVillage_PlayersHouse_LR_EventScript_RivalsNote_Text_0:
	.string "“Hey {PLAYER},\n"
	.string "I'm going down to the beach before\l"
	.string "the giveaway, meet me there if you\l"
	.string "wanna hang out.\p"
	.string "-Natsuki”$"

SunriseVillage_PlayersHouse_Bedroom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SunriseVillage_PlayersHouse_Bedroom_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_TRANSITION, SunriseVillage_PlayersHouse_Bedroom_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SunriseVillage_PlayersHouse_Bedroom_MapScripts_MAP_SCRIPT_ON_LOAD:
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 1
	goto_if_lt SunriseVillage_PlayersHouse_Bedroom_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

SunriseVillage_PlayersHouse_Bedroom_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setrespawn HEAL_LOCATION_SUNRISE_VILLAGE
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 1
	pausefakertc
	return

SunriseVillage_PlayersHouse_Bedroom_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call SecretBase_EventScript_SetDecorationFlags
	return


SunriseVillage_PlayersHouse_Bedroom_EventScript_Doll::
	lock
	setnamedmon SPECIES_MAREEP
	msgbox SunriseVillage_PlayersHouse_Bedroom_EventScript_Doll_Text_0
	release
	return


SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	speakername SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_0
	msgbox SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_1
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_2, SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_3, SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_4
	closemessage
	speakername SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_0
	compare VAR_RESULT, 0
	goto_if_eq SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_2
	delay 48
	msgbox SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_6
	dynmultichoice 16, 8, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_7, SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_8
	closemessage
	delay 30
	speakername SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_0
	msgbox SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_9
SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_1:
	closemessage
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 2
	setflag FLAG_HIDE_SUNRISE_VILLAGE_STANDARD_NPC_POSITIONS
	release
	end

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_2:
	delay 30
	msgbox SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_5
	goto SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_1


SunriseVillage_PlayersHouse_Bedroom_Stuff::
	goto_if_unset FLAG_SYS_QUEST_MENU_GET, SunriseVillage_PlayersHouse_Bedroom_Stuff_1
	playfanfare MUS_OBTAIN_ITEM
	msgbox SunriseVillage_PlayersHouse_Bedroom_Stuff_Text_2, MSGBOX_SIGN
	waitfanfare
	waitmessage
	closemessage
	return

SunriseVillage_PlayersHouse_Bedroom_Stuff_1:
	msgbox SunriseVillage_PlayersHouse_Bedroom_Stuff_Text_0, MSGBOX_SIGN
	waitmessage
	giveitem ITEM_OINTMENT, 5
	msgbox SunriseVillage_PlayersHouse_Bedroom_Stuff_Text_1, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_QUEST_MENU_GET
	removeobject 13
	return


SunriseVillage_EventScript_PlayerPc::
	lockall
	special BedroomPC
	waitstate
	return


SunriseVillage_TurnOffPlayerPC::
	releaseall
	return


SunriseVillage_PlayersHouse_Bedroom_EventScript_Doll_Text_0:
	.string "“100% real Mareep wool”!$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_0:
	.string "Big sis$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_1:
	.string "{PLAYER}! {PLAYER}!\n"
	.string "Are you still sleeping?$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_2:
	.string "…Yes?$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_3:
	.string "Coming!$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_4:
	.string "…$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_5:
	.string "Very funny! Now get up and get\n"
	.string "ready!$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_6:
	.string "… … … … … …\p"
	.string "…{PLAYER}!! ARE YOU UP?!$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_7:
	.string "COMIIIIING!!$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_8:
	.string "COMIIIIIIIIIIING!!!$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_9:
	.string "No need to yell, I can hear you\n"
	.string "just fine!\p"
	.string "Now get up and get ready!$"

SunriseVillage_PlayersHouse_Bedroom_Stuff_Text_0:
	.string "It's the Pokémon medicine your\n"
	.string "sister got for you.$"

SunriseVillage_PlayersHouse_Bedroom_Stuff_Text_1:
	.string "There is also your journal inside!\n"
	.string "It might come in handy.$"

SunriseVillage_PlayersHouse_Bedroom_Stuff_Text_2:
	.string "You got the lint from the bottom of\n"
	.string "the chest!$"

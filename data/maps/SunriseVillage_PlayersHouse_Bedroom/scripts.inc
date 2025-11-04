SunriseVillage_PlayersHouse_Bedroom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SunriseVillage_PlayersHouse_Bedroom_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_TRANSITION, SunriseVillage_PlayersHouse_Bedroom_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SunriseVillage_PlayersHouse_Bedroom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
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
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	return

SunriseVillage_PlayersHouse_Bedroom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, SecretBase_EventScript_InitDecorations
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
	setspeaker SP_NAME_BIG_SIS
	msgbox SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_0
	mcdialogue SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_1, SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_2, SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_3
	closemessage
	setspeaker SP_NAME_BIG_SIS
	compare VAR_RESULT, 0
	goto_if_eq SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_2
	delay 48
	msgbox SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_5
	mcdialogue SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_6, SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_7
	closemessage
	delay 30
	setspeaker SP_NAME_BIG_SIS
	msgbox SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_8
SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_1:
	closemessage
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 2
	setflag FLAG_HIDE_SUNRISE_VILLAGE_STANDARD_NPC_POSITIONS
	release
	end

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_2:
	delay 30
	msgbox SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_4
	goto SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_1


SunriseVillage_PlayersHouse_Bedroom_Stuff::
	msgbox SunriseVillage_PlayersHouse_Bedroom_Stuff_Text_0, MSGBOX_SIGN
	waitmessage
	giveitem ITEM_OINTMENT, 5
	giveitem ITEM_POKE_BALL, 5
	closemessage
	setflag FLAG_PICKED_UP_BAG
	removeobject 13
	return


SunriseVillage_PlayersHouse_Bedroom_Trigger_ForgotBag::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_PlayersHouse_Bedroom_Trigger_ForgotBag_Movement_0
	waitmovement 0
	waitse
	msgbox SunriseVillage_PlayersHouse_Bedroom_Trigger_ForgotBag_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_PlayersHouse_Bedroom_Trigger_ForgotBag_Movement_1
	waitmovement 0
	releaseall
	return


SunriseVillage_EventScript_PlayerPc::
	lockall
	special BedroomPC
	waitstate
	return


SunriseVillage_TurnOffPlayerPC::
	releaseall
	return


SunriseVillage_PlayersHouse_Bedroom_Trigger_ForgotBag_Movement_0:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

SunriseVillage_PlayersHouse_Bedroom_Trigger_ForgotBag_Movement_1:
	walk_up
	step_end

SunriseVillage_PlayersHouse_Bedroom_EventScript_Doll_Text_0:
	.string "“100% real Mareep wool”!$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_0:
	.string "{PLAYER}! {PLAYER}!\n"
	.string "Are you still sleeping?$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_1:
	.string "…Yes?$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_2:
	.string "Coming!$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_3:
	.string "…$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_4:
	.string "Very funny! Now get up and get ready!$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_5:
	.string "… … … … … …\p"
	.string "…{PLAYER}!! ARE YOU UP?!$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_6:
	.string "COMIIIIING!!$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_7:
	.string "COMIIIIIIIIIIING!!!$"

SunriseVillage_PlayersHouse_Bedroom_Event_BigSisCalling_Text_8:
	.string "No need to yell, I can hear you just\n"
	.string "fine!\p"
	.string "Now get up and get ready!$"

SunriseVillage_PlayersHouse_Bedroom_Stuff_Text_0:
	.string "It's the medicine and Pokéballs your\n"
	.string "sister got for you!$"

SunriseVillage_PlayersHouse_Bedroom_Trigger_ForgotBag_Text_0:
	.string "…You almost forgot to pick up your\n"
	.string "bag.$"

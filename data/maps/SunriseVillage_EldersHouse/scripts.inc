SunriseVillage_EldersHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 4
	goto_if_ge SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 7
	goto_if_ge SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	return

SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setflag FLAG_TEMP_1
	goto SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	setflag FLAG_TEMP_2
	return

SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_SUNRISE_VILLAGE_INTRO_STATE, 4, SunriseVillage_EldersHouse_EventScript_DistributionCutscene
	.2byte 0


SunriseVillage_EldersHouse_EventScript_DistributionCutscene::
	lock
	setseenmon SPECIES_CYNDAQUIL
	setnamedmon SPECIES_CYNDAQUIL
	setseenmon SPECIES_SNIVY
	setnamedmon SPECIES_SNIVY
	setseenmon SPECIES_FROAKIE
	setnamedmon SPECIES_FROAKIE
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_0
	waitmovement 0
	playse SE_ARENA_TIMEUP2
	applymovement 1, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_1
	delay 4
	playse SE_PIN
	applymovement 2, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_2
	waitmovement 2
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_3
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
	msgbox SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_1
	waitse
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
	msgbox SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_2
	closemessage
	applymovement 1, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_4
	waitmovement 0
	playse SE_ARENA_TIMEUP2
	applymovement 1, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_1
	applymovement 2, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_3
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_3
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
	msgbox SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
	closemessage
	clearflag FLAG_TEMP_1
	applymovement 1, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_5
	waitmovement 0
	playse SE_BALL_OPEN
	removeobject 3
	addobject 6
	waitse
	playmoncry SPECIES_SNIVY, CRY_MODE_NORMAL
	delay 30
	applymovement 1, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_5
	waitmovement 0
	playse SE_BALL_OPEN
	removeobject 4
	addobject 7
	waitse
	playmoncry SPECIES_FROAKIE, CRY_MODE_NORMAL
	delay 30
	applymovement 1, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_5
	waitmovement 0
	playse SE_BALL_OPEN
	removeobject 5
	addobject 8
	waitse
	playmoncry SPECIES_CYNDAQUIL, CRY_MODE_NORMAL
	delay 30
	applymovement 1, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_6
	waitmovement 0
	playse SE_LEDGE
	applymovement 2, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_7
	waitmovement 0
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_4
	msgbox SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_5
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement 2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_4
	msgbox SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_6
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 5
	release
	return


SunriseVillage_EldersHouse_Event_Elder::
	lock
	faceplayer
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 7
	goto_if_ge SunriseVillage_EldersHouse_Event_Elder_2
	msgbox SunriseVillage_EldersHouse_Event_Elder_Text_2
SunriseVillage_EldersHouse_Event_Elder_1:
	mcdialogue SunriseVillage_EldersHouse_Event_Elder_Text_3, SunriseVillage_EldersHouse_Event_Elder_Text_4
	closemessage
	switch VAR_RESULT
	case 0, SunriseVillage_EldersHouse_Event_Elder_7
	case 1, SunriseVillage_EldersHouse_Event_Elder_8
SunriseVillage_EldersHouse_Event_Elder_5:
	release
	return

SunriseVillage_EldersHouse_Event_Elder_2:
	compare VAR_DECAY_BEACHBOUND_ROUTE, 5
	goto_if_lt SunriseVillage_EldersHouse_Event_Elder_9
	msgbox SunriseVillage_EldersHouse_Event_Elder_Text_1
	goto SunriseVillage_EldersHouse_Event_Elder_1

SunriseVillage_EldersHouse_Event_Elder_7:
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
	msgbox SunriseVillage_EldersHouse_Event_Elder_Text_5
	call ProfBirch_EventScript_RatePokedex
	goto SunriseVillage_EldersHouse_Event_Elder_5

SunriseVillage_EldersHouse_Event_Elder_8:
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
	msgbox SunriseVillage_EldersHouse_Event_Elder_Text_6
	goto SunriseVillage_EldersHouse_Event_Elder_5

SunriseVillage_EldersHouse_Event_Elder_9:
	msgbox SunriseVillage_EldersHouse_Event_Elder_Text_0
	goto SunriseVillage_EldersHouse_Event_Elder_1


SunriseVillage_EldersHouse_EventScript_TryToLeave::
	lock
	turnobject 1, DIR_SOUTH
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
	msgbox SunriseVillage_EldersHouse_EventScript_TryToLeave_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	release
	return


SunriseVillage_EldersHouse_EventScript_TryToEnterOtherRoom::
	lock
	turnobject 1, DIR_NORTH
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
	msgbox SunriseVillage_EldersHouse_EventScript_TryToLeave_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_EventScript_TryToEnterOtherRoom_Movement_0
	waitmovement 0
	release
	return


SunriseVillage_EldersHouse_Event_Pokeball_Starter_Cyndaquil::
	lock
	setvar VAR_TEMP_1, SPECIES_CYNDAQUIL
	call SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter
	release
	return


SunriseVillage_EldersHouse_Event_Pokeball_Starter_Snivy::
	lock
	setvar VAR_TEMP_1, SPECIES_SNIVY
	call SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter
	release
	return


SunriseVillage_EldersHouse_Event_Pokeball_Starter_Froakie::
	lock
	setvar VAR_TEMP_1, SPECIES_FROAKIE
	call SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter
	release
	return


SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter::
	goto_if_set FLAG_RECEIVED_STARTER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_2
	playmoncry VAR_TEMP_1, CRY_MODE_NORMAL
	showmonpic VAR_TEMP_1, 10, 3
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	switch VAR_TEMP_1
	case SPECIES_FROAKIE, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_6
	case SPECIES_SNIVY, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_7
	case SPECIES_CYNDAQUIL, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_8
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_4:
	compare VAR_RESULT, NO
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_10
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_10
	compare VAR_RESULT, YES
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_11
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_9:
	hidemonpic
	setflag FLAG_RECEIVED_STARTER
	setflag FLAG_SYS_POKEMON_GET
	turnobject 2, DIR_NORTH
	switch VAR_STARTER_MON
	case SPECIES_FROAKIE, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_18
	case SPECIES_SNIVY, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_19
	case SPECIES_CYNDAQUIL, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_20
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16:
	waitmovement OBJ_EVENT_ID_PLAYER
	turnobject 1, DIR_SOUTH
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_4
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_6
	closemessage
	switch VAR_STARTER_MON
	case SPECIES_FROAKIE, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_28
	case SPECIES_SNIVY, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_29
	case SPECIES_CYNDAQUIL, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_30
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_26:
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_7
	closemessage
	applymovement 1, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_14
	waitmovement 0
	playfanfare MUS_OBTAIN_ITEM
	message SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_8
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	closemessage
	delay 20
	applymovement 2, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_15
	waitmovement 0
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_4
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_9
	closemessage
	delay 20
	applymovement 1, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_16
	waitmovement 0
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_10
	closemessage
	giveitem ITEM_LETTER
	waitfanfare
	closemessage
	applymovement 2, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_15
	waitmovement 0
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_4
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_11
	closemessage
	applymovement 2, Common_Movement_WalkInPlaceFasterLeft
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	waitmovement 2
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_4
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_12
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_13, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_14
	compare VAR_RESULT, 0
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_48
	applymovement 2, Common_Movement_WalkInPlaceFasterUp
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_4
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_55
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_17
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_54:
	closemessage
	applymovement 2, Common_Movement_WalkInPlaceFasterLeft
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_47:
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_4
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_18
	closemessage
	applymovement 2, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_18
	waitmovement 0
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 6
	goto SunriseVillage_EldersHouse_EventScript_RivalBattle
	return

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_2:
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_0
	closemessage
	return

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_6:
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_1, MSGBOX_YESNO
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_4

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_7:
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_2, MSGBOX_YESNO
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_4

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_8:
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_3, MSGBOX_YESNO
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_4

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_10:
	hidemonpic
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_4
	closemessage
	return

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_11:
	switch VAR_TEMP_1
	case SPECIES_FROAKIE, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_23
	case SPECIES_SNIVY, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_24
	case SPECIES_CYNDAQUIL, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_25
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_21:
	playfanfare MUS_OBTAIN_ITEM
	message SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_5
	waitmessage
	waitfanfare
	switch VAR_TEMP_1
	case SPECIES_FROAKIE, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_44
	case SPECIES_SNIVY, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_45
	case SPECIES_CYNDAQUIL, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_46
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_42:
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_52
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_51:
	closemessage
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_9

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_18:
	switch VAR_FACING
	case DIR_SOUTH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_32
	case DIR_NORTH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_33
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_19:
	switch VAR_FACING
	case DIR_SOUTH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_35
	case DIR_NORTH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_36
	case DIR_EAST, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_37
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_20:
	switch VAR_FACING
	case DIR_SOUTH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_39
	case DIR_NORTH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_40
	case DIR_WEST, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_41
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_23:
	givemon SPECIES_FROAKIE, 5, ITEM_ORAN_BERRY, move1 = MOVE_POUND, move2 = MOVE_GROWL, move3 = MOVE_NONE, move4 = MOVE_NONE
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_21

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_24:
	givemon SPECIES_SNIVY, 5, ITEM_ORAN_BERRY, move1 = MOVE_TACKLE, move2 = MOVE_LEER, move3 = MOVE_NONE, move4 = MOVE_NONE
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_21

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_25:
	givemon SPECIES_CYNDAQUIL, 5, ITEM_ORAN_BERRY, move1 = MOVE_TACKLE, move2 = MOVE_LEER, move3 = MOVE_NONE, move4 = MOVE_NONE
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_21

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_28:
	applymovement 2, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_8
	waitmovement 0
	playmoncry SPECIES_SNIVY, CRY_MODE_NORMAL
	removeobject 6
	removeobject 3
	applymovement 2, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_9
	waitmovement 0
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_26

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_29:
	applymovement 2, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_10
	waitmovement 0
	playmoncry SPECIES_CYNDAQUIL, CRY_MODE_NORMAL
	removeobject 8
	removeobject 5
	applymovement 2, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_11
	waitmovement 0
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_26

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_30:
	applymovement 2, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_12
	waitmovement 0
	playmoncry SPECIES_FROAKIE, CRY_MODE_NORMAL
	removeobject 7
	removeobject 4
	applymovement 2, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_13
	waitmovement 0
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_26

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_32:
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_0
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_33:
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_1
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_35:
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_2
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_36:
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_3
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_37:
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_4
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_39:
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_5
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_40:
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_6
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_41:
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_7
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_44:
	setvar VAR_STARTER_MON, SPECIES_FROAKIE
	removeobject 7
	removeobject 4
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_42

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_45:
	removeobject 6
	removeobject 3
	setvar VAR_STARTER_MON, SPECIES_SNIVY
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_42

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_46:
	removeobject 8
	removeobject 5
	setvar VAR_STARTER_MON, SPECIES_CYNDAQUIL
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_42

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_48:
	applymovement 2, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_17
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_15
	closemessage
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_47

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_52:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_51

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_55:
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_16
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_54


SunriseVillage_EldersHouse_Movement_RivalPreBattlePose:
	face_player
	step_end

SunriseVillage_EldersHouse_EventScript_Natsuki::
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_4
	msgbox SunriseVillage_EldersHouse_EventScript_Natsuki_Text_0, MSGBOX_NPC
	return


SunriseVillage_EldersHouse_EventScript_PostBattle::
	special HealPlayerParty
	applymovement 2, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_17
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SunriseVillage_EldersHouse_EventScript_PostBattle_2
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_4
	msgbox SunriseVillage_EldersHouse_EventScript_PostBattle_Text_1
	closemessage
SunriseVillage_EldersHouse_EventScript_PostBattle_1:
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 6
	goto_if_eq SunriseVillage_EldersHouse_EventScript_PostBattle_8
SunriseVillage_EldersHouse_EventScript_PostBattle_7:
	applymovement 2, SunriseVillage_EldersHouse_EventScript_PostBattle_Movement_1
SunriseVillage_EldersHouse_EventScript_PostBattle_5:
	waitmovement 2
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	removeobject 2
	playse SE_EXIT
	waitse
	delay 16
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 7
	resumefakertc
	updatequest QUEST_HEARTH_MAIN_CAMPAIGN, VAR_MAIN_CAMPAIGN_QUEST
	startquest QUEST_POKEDEX
	release
	return

SunriseVillage_EldersHouse_EventScript_PostBattle_2:
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_4
	msgbox SunriseVillage_EldersHouse_EventScript_PostBattle_Text_0
	closemessage
	goto SunriseVillage_EldersHouse_EventScript_PostBattle_1

SunriseVillage_EldersHouse_EventScript_PostBattle_6:
	applymovement 2, SunriseVillage_EldersHouse_EventScript_PostBattle_Movement_0
	goto SunriseVillage_EldersHouse_EventScript_PostBattle_5

SunriseVillage_EldersHouse_EventScript_PostBattle_8:
	compare VAR_TEMP_1, 7
	goto_if_eq SunriseVillage_EldersHouse_EventScript_PostBattle_6
	goto SunriseVillage_EldersHouse_EventScript_PostBattle_7


SunriseVillage_EldersHouse_EventScript_RivalBattle::
	switch VAR_STARTER_MON
	case SPECIES_FROAKIE, SunriseVillage_EldersHouse_EventScript_RivalBattle_3
	case SPECIES_SNIVY, SunriseVillage_EldersHouse_EventScript_RivalBattle_4
	case SPECIES_CYNDAQUIL, SunriseVillage_EldersHouse_EventScript_RivalBattle_5
SunriseVillage_EldersHouse_EventScript_RivalBattle_1:
	goto SunriseVillage_EldersHouse_EventScript_PostBattle
	return

SunriseVillage_EldersHouse_EventScript_RivalBattle_3:
	trainerbattle_no_intro_no_whiteout TRAINER_RIVAL_FIRST_BATTLE_FROAKIE, SunriseVillage_EldersHouse_EventScript_RivalBattle_Text_0
	goto SunriseVillage_EldersHouse_EventScript_RivalBattle_1

SunriseVillage_EldersHouse_EventScript_RivalBattle_4:
	trainerbattle_no_intro_no_whiteout TRAINER_RIVAL_FIRST_BATTLE_SNIVY, SunriseVillage_EldersHouse_EventScript_RivalBattle_Text_0
	goto SunriseVillage_EldersHouse_EventScript_RivalBattle_1

SunriseVillage_EldersHouse_EventScript_RivalBattle_5:
	trainerbattle_no_intro_no_whiteout TRAINER_RIVAL_FIRST_BATTLE_CYNDAQUIL, SunriseVillage_EldersHouse_EventScript_RivalBattle_Text_0
	goto SunriseVillage_EldersHouse_EventScript_RivalBattle_1


SunriseVillage_EldersHouse_EventScript_Joltik::
	lock
	faceplayer
	setseenmon SPECIES_JOLTIK
	playmoncry SPECIES_JOLTIK, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_JOLTIK
	msgbox SunriseVillage_EldersHouse_EventScript_Joltik_Text_0
	waitmoncry
	release
	end


SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_0:
	walk_up
	walk_left
	walk_up
	delay_16
	delay_16
	step_end

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_1:
	jump_in_place_down
	step_end

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_2:
	emote_exclamation_mark
	delay_4
	step_end

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_3:
	emote_exclamation_mark
	step_end

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_4:
	walk_in_place_faster_up
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_5:
	walk_right
	face_up
	delay_16
	step_end

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_6:
	walk_left
	walk_left
	walk_left
	face_down
	step_end

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_7:
	jump_in_place_up
	step_end

SunriseVillage_EldersHouse_EventScript_TryToEnterOtherRoom_Movement_0:
	walk_down
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_0:
	walk_down
	walk_down
	walk_left
	walk_down
	walk_in_place_faster_up
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_1:
	walk_left
	walk_down
	walk_in_place_faster_up
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_up
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_3:
	walk_down
	walk_in_place_faster_up
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_4:
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_up
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_5:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_up
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_6:
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_up
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_7:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_up
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_8:
	walk_up
	walk_left
	walk_in_place_faster_up
	delay_16
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_9:
	walk_right
	walk_down
	walk_in_place_faster_up
	delay_16
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_10:
	walk_up
	walk_right
	walk_in_place_faster_up
	delay_16
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_11:
	walk_left
	walk_down
	walk_in_place_faster_up
	delay_16
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_12:
	walk_up
	delay_16
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_13:
	walk_down
	walk_in_place_faster_up
	delay_16
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_14:
	walk_right
	walk_right
	walk_in_place_faster_down
	delay_16
	walk_left
	walk_in_place_faster_down
	delay_16
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_15:
	walk_in_place_fast_up
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_16:
	walk_in_place_fast_down
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_17:
	jump_in_place_left
	step_end

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_18:
	face_player
	step_end

SunriseVillage_EldersHouse_EventScript_PostBattle_Movement_0:
	walk_left
	walk_down
	walk_down
	step_end

SunriseVillage_EldersHouse_EventScript_PostBattle_Movement_1:
	walk_down
	walk_down
	step_end

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0:
	.string "Elder Kaba$"

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_1:
	.string "PAH!$"

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_2:
	.string "{PLAYER}, Natsuki.\nYou are late. Why am I surprised?\p"
	.string "I always have to run after you two!\nNow stay still for a minute and\llisten closely!\p"
	.string "As you have heard, the woods, and even\nthe roads, are no longer safe.\p"
	.string "We don't yet know why, but the wild\nPokémon that usually hide in the\ltall grass and live peacefully\lalongside men have started behaving\laggressively.\p"
	.string "There are reports of travelers being\nattacked from several nearby villages.\p"
	.string "This is all very worrying…$"

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3:
	.string "WHICH IS WHY!{PAUSE 15}\p"
	.string "The Toku council has decided that,\n"
	.string "for the time being, the best way to\l"
	.string "handle this is to use the Pokémon\l"
	.string "themselves as a means of protection!\p"
	.string "There were very few experienced\n"
	.string "Pokémon Wielders in Toku until now.\l"
	.string "This is about to change.\p"
	.string "With a trained Pokémon by your side,\n"
	.string "you'll be able to defend yourselves\l"
	.string "on your own.\p"
	.string "Without further ado, please carefully\n"
	.string "choose your new companion!$"

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_4:
	.string "Natsuki$"

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_5:
	.string "Woah! Cool.$"

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_6:
	.string "{PLAYER}, choose yours first!\n"
	.string "I don't mind being second pick.$"

SunriseVillage_EldersHouse_Event_Elder_Text_0:
	.string "Don't dilly-dally on the way! And keep\n"
	.string "an eye on your little friend Natsuki,\l"
	.string "make sure he doesn't get into\l"
	.string "trouble!$"

SunriseVillage_EldersHouse_Event_Elder_Text_1:
	.string "Oh! You delivered my letter. Good.\p"
	.string "You've been appointed to investigate\n"
	.string "Decaying areas? Well then, what are\l"
	.string "you still doing here? Off you go!$"

SunriseVillage_EldersHouse_Event_Elder_Text_2:
	.string "Choose your new partner wisely.\n"
	.string "No takebacks.$"

SunriseVillage_EldersHouse_Event_Elder_Text_3:
	.string "Evaluate my PokéDex!$"

SunriseVillage_EldersHouse_Event_Elder_Text_4:
	.string "See you!$"

SunriseVillage_EldersHouse_Event_Elder_Text_5:
	.string "Well, what are you waiting for? Hand it\n"
	.string "over!$"

SunriseVillage_EldersHouse_Event_Elder_Text_6:
	.string "Alright, alright.\n"
	.string "{FONT_SMALL}Damned children wasting my time.{FONT_NORMAL}$"

SunriseVillage_EldersHouse_EventScript_TryToLeave_Text_0:
	.string "Where do you think you're going?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_0:
	.string "You already got a Pokémon.\n"
	.string "Better leave this one here.$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_1:
	.string "Do you choose {STR_VAR_1},\n"
	.string "soul of the crashing sea waves?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_2:
	.string "Do you choose {STR_VAR_1},\n"
	.string "graceful storm of leaves?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_3:
	.string "Do you choose {STR_VAR_1},\n"
	.string "tender heart of the hearth?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_4:
	.string "Take the time you need.$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_5:
	.string "{PLAYER} received the Pokémon\n"
	.string "{STR_VAR_1}!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_6:
	.string "Alright. I'm taking this one!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_7:
	.string "Now that you have your own Pokémon,\n"
	.string "you two are officially\l"
	.string "Pokémon Wielders!\p"
	.string "The more Wielders there are,\n"
	.string "the deeper our understanding\l"
	.string "of Pokémon will be.\p"
	.string "We need to study these creatures\n"
	.string "from up close to find the root of\l"
	.string "this issue.\p"
	.string "Actually, there's something\n"
	.string "I wanted to ask you.$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_8:
	.string "{PLAYER} received the PokéDex!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_9:
	.string "What's this? A book?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_10:
	.string "I call this the “PokéDex”.\n"
	.string "It is an encyclopedia containing\l"
	.string "vital information about Pokémon\l"
	.string "from the whole region!\p"
	.string "Except it's, well, empty.\n"
	.string "That's where you come in!\p"
	.string "Explore Toku and fill its pages with\n"
	.string "your findings!\p"
	.string "You can start by going all the way to\n"
	.string "Silveridge, north of here in the\l"
	.string "mountains.\p"
	.string "Another Elder lives there and,\n"
	.string "hopefully, has more information\l"
	.string "as to why the Pokémon are lashing\l"
	.string "out.\p"
	.string "Could you deliver him this letter?\n"
	.string "I could send him a Chatot, but I need\l"
	.string "to make sure this doesn't get lost on\l"
	.string "the way.$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_11:
	.string "Understood, Grandma Kaba.\n"
	.string "We're going adventuring!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_12:
	.string "{PLAYER}… Are you ready?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_13:
	.string "Totally!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_14:
	.string "Absolutely not!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_15:
	.string "That's what I'm talking about!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_16:
	.string "Don't listen to him! He's so ready!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_17:
	.string "Don't listen to her! She's so ready!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_18:
	.string "{PLAYER}!\n"
	.string "Let's see what our brand-new Pokémon\l"
	.string "are capable of!\p"
	.string "I request an official Pokémon\n"
	.string "Wielder battle!$"

SunriseVillage_EldersHouse_EventScript_Natsuki_Text_0:
	.string "Hm, which one will I choose?…$"

SunriseVillage_EldersHouse_EventScript_PostBattle_Text_0:
	.string "Oh, man!\n"
	.string "That was the most fun I've ever had!\p"
	.string "{PLAYER}!\n"
	.string "We're now officially rivals!\p"
	.string "I went easy on you this time, but\n"
	.string "next time… You'll see!\p"
	.string "I'm going home to pack some things.\p"
	.string "See ya later, Feraligatr.$"

SunriseVillage_EldersHouse_EventScript_PostBattle_Text_1:
	.string "Oh, man!\n"
	.string "That was the most fun I've ever had!\p"
	.string "{PLAYER}!\n"
	.string "We're now officially rivals!\p"
	.string "You better work hard to keep up!\p"
	.string "I'm going home to pack some things.\p"
	.string "See ya later, Feraligatr.$"

SunriseVillage_EldersHouse_EventScript_RivalBattle_Text_0:
	.string "What? It's over already?$"

SunriseVillage_EldersHouse_EventScript_Joltik_Text_0:
	.string "Fss!$"

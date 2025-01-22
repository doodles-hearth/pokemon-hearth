SunriseVillage_EldersHouse_MapScripts::
# 17 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 14 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 18 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 4
	goto_if_ge SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 21 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 7
	goto_if_ge SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	return

SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 19 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setflag FLAG_TEMP_1
	goto SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 22 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setflag FLAG_TEMP_2
	return

SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 15 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	map_script_2 VAR_SUNRISE_VILLAGE_INTRO_STATE, 4, SunriseVillage_EldersHouse_EventScript_DistributionCutscene
	.2byte 0


SunriseVillage_EldersHouse_EventScript_DistributionCutscene::
# 28 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lock
# 30 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_0
# 31 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 32 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterDown
# 35 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
# 36 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_1
# 44 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 45 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 1, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_1
# 46 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 47 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
# 48 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_2
# 56 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 58 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	clearflag FLAG_TEMP_1
# 60 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 1, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_2
# 61 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 62 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playse SE_BALL_OPEN
# 63 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitse
# 64 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 3
# 65 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	addobject 6
# 66 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playmoncry SPECIES_SNIVY, CRY_MODE_NORMAL
# 67 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay 30
# 69 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 1, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_2
# 70 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 71 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playse SE_BALL_OPEN
# 72 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitse
# 73 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 4
# 74 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	addobject 7
# 75 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playmoncry SPECIES_FROAKIE, CRY_MODE_NORMAL
# 76 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay 30
# 78 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 1, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_2
# 79 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 80 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playse SE_BALL_OPEN
# 81 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitse
# 82 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 5
# 83 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	addobject 8
# 84 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playmoncry SPECIES_CYNDAQUIL, CRY_MODE_NORMAL
# 85 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay 30
# 87 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 1, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_3
# 88 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 90 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playse SE_LEDGE
# 91 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_4
# 92 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 93 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 94 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_4
# 97 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 98 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceFasterLeft
# 99 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 100 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 101 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_5
# 105 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 106 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 108 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 5
# 109 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	release
	return


SunriseVillage_EldersHouse_Event_Elder::
# 113 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lock
# 114 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	faceplayer
# 115 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
# 116 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 7
	goto_if_ge SunriseVillage_EldersHouse_Event_Elder_2
# 122 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Elder_Text_1
# 123 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
SunriseVillage_EldersHouse_Event_Elder_1:
# 125 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	release
	return

SunriseVillage_EldersHouse_Event_Elder_2:
# 118 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Elder_Text_0
# 119 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
	goto SunriseVillage_EldersHouse_Event_Elder_1


SunriseVillage_EldersHouse_EventScript_TryToLeave::
# 129 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lock
# 130 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	turnobject 1, DIR_SOUTH
# 131 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
# 132 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_TryToLeave_Text_0
# 135 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 136 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
# 137 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 138 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	release
	return


SunriseVillage_EldersHouse_EventScript_TryToEnterOtherRoom::
# 142 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lock
# 143 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	turnobject 1, DIR_NORTH
# 144 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
# 145 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_TryToLeave_Text_0
# 148 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 149 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_EventScript_TryToEnterOtherRoom_Movement_0
# 150 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 151 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	release
	return


SunriseVillage_EldersHouse_Event_Pokeball_Starter_Cyndaquil::
# 155 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lock
# 156 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_CYNDAQUIL
# 157 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	call SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter
# 158 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	release
	return


SunriseVillage_EldersHouse_Event_Pokeball_Starter_Snivy::
# 162 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lock
# 163 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_SNIVY
# 164 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	call SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter
# 165 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	release
	return


SunriseVillage_EldersHouse_Event_Pokeball_Starter_Froakie::
# 169 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lock
# 170 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_FROAKIE
# 171 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	call SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter
# 172 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	release
	return


SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter::
# 176 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_2
# 183 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playmoncry VAR_TEMP_1, CRY_MODE_NORMAL
# 184 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	showmonpic VAR_TEMP_1, 10, 3
# 185 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 186 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	switch VAR_TEMP_1
# 187 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_FROAKIE, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_6
# 189 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_SNIVY, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_7
# 191 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_CYNDAQUIL, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_8
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_4:
# 194 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_10
# 194 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_10
# 200 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_11
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_9:
# 236 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	hidemonpic
# 238 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setflag FLAG_RECEIVED_STARTER
# 239 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 241 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	turnobject 2, DIR_NORTH
# 244 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	switch VAR_STARTER_MON
# 245 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_FROAKIE, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_18
# 252 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_SNIVY, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_19
# 261 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_CYNDAQUIL, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_20
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16:
# 272 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 274 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	turnobject 1, DIR_SOUTH
# 276 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
# 279 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 280 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_6
# 281 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 283 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	switch VAR_STARTER_MON
# 284 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_FROAKIE, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_28
# 291 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_SNIVY, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_29
# 298 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_CYNDAQUIL, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_30
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_26:
# 308 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
# 309 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_7
# 315 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 317 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 1, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_14
# 318 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 320 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 321 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	message SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_8
# 322 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitfanfare
# 323 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 325 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 326 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 328 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay 20
# 330 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 331 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_9
# 334 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 336 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay 20
# 338 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
# 339 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_10
# 347 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 349 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 351 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	message SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_11
# 352 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitfanfare
# 353 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 355 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 356 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_12
# 357 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 359 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceFasterLeft
# 360 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 361 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 2
# 363 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 364 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_13
# 365 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	dynmultichoice 16, 6, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_14, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_15
# 376 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_48
# 382 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceFasterUp
# 384 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 385 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	checkplayergender
# 386 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_55
# 391 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_18
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_54:
# 395 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 397 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceFasterLeft
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_47:
# 400 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 401 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_19
# 405 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 408 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_15
# 409 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 411 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 6
# 414 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	goto SunriseVillage_EldersHouse_EventScript_RivalBattle
	return

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_2:
# 177 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_0
# 180 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
	return

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_6:
# 188 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_1, MSGBOX_YESNO
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_4

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_7:
# 190 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_2, MSGBOX_YESNO
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_4

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_8:
# 192 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_3, MSGBOX_YESNO
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_4

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_10:
# 195 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	hidemonpic
# 196 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
# 197 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_4
# 198 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
	return

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_11:
# 201 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	switch VAR_TEMP_1
# 202 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_FROAKIE, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_23
# 204 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_SNIVY, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_24
# 206 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_CYNDAQUIL, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_25
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_21:
# 209 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 210 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	message SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_5
# 211 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmessage
# 212 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitfanfare
# 214 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	switch VAR_TEMP_1
# 215 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_FROAKIE, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_44
# 219 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_SNIVY, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_45
# 223 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_CYNDAQUIL, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_46
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_42:
# 229 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 230 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_52
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_51:
# 234 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_9

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_18:
# 246 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	switch VAR_FACING
# 247 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case DIR_SOUTH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_32
# 249 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case DIR_NORTH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_33
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_19:
# 253 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	switch VAR_FACING
# 254 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case DIR_SOUTH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_35
# 256 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case DIR_NORTH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_36
# 258 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case DIR_EAST, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_37
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_20:
# 262 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	switch VAR_FACING
# 263 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case DIR_SOUTH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_39
# 265 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case DIR_NORTH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_40
# 267 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case DIR_WEST, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_41
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_23:
# 203 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	givemon SPECIES_FROAKIE, 5, ITEM_ORAN_BERRY
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_21

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_24:
# 205 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	givemon SPECIES_SNIVY, 5, ITEM_ORAN_BERRY
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_21

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_25:
# 207 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	givemon SPECIES_CYNDAQUIL, 5, ITEM_ORAN_BERRY
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_21

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_28:
# 285 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_8
# 286 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 287 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 6
# 288 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 3
# 289 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_9
# 290 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_26

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_29:
# 292 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_10
# 293 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 294 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 8
# 295 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 5
# 296 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_11
# 297 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_26

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_30:
# 299 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_12
# 300 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 301 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 7
# 302 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 4
# 303 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_13
# 304 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_26

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_32:
# 248 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_0
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_33:
# 250 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_1
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_35:
# 255 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_2
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_36:
# 257 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_3
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_37:
# 259 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_4
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_39:
# 264 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_5
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_40:
# 266 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_6
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_41:
# 268 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_7
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_44:
# 216 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_FROAKIE
# 217 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 7
# 218 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 4
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_42

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_45:
# 220 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 6
# 221 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 3
# 222 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SNIVY
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_42

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_46:
# 224 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 8
# 225 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 5
# 226 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_CYNDAQUIL
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_42

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_48:
# 377 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_16
# 380 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_47

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_52:
# 231 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 232 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_51

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_55:
# 387 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_17
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_54


# 417 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_RivalPreBattlePose:
# 420 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	face_player
	step_end

SunriseVillage_EldersHouse_EventScript_Natsuki::
# 424 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 425 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_Natsuki_Text_0, MSGBOX_NPC
	return


SunriseVillage_EldersHouse_EventScript_PostBattle::
# 429 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	special HealPlayerParty
# 430 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 431 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SunriseVillage_EldersHouse_EventScript_PostBattle_2
# 442 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 443 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_PostBattle_Text_1
# 450 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
SunriseVillage_EldersHouse_EventScript_PostBattle_1:
# 453 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 454 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_TEMP_0, 6
	goto_if_eq SunriseVillage_EldersHouse_EventScript_PostBattle_8
SunriseVillage_EldersHouse_EventScript_PostBattle_7:
# 457 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_EventScript_PostBattle_Movement_1
SunriseVillage_EldersHouse_EventScript_PostBattle_5:
# 460 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 2
# 461 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 462 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 2
# 463 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playse SE_EXIT
# 464 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitse
# 465 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay 16
# 467 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 7
# 470 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	resumefakertc
# 472 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	release
	return

SunriseVillage_EldersHouse_EventScript_PostBattle_2:
# 432 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 433 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_PostBattle_Text_0
# 440 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
	goto SunriseVillage_EldersHouse_EventScript_PostBattle_1

SunriseVillage_EldersHouse_EventScript_PostBattle_6:
# 455 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_EventScript_PostBattle_Movement_0
	goto SunriseVillage_EldersHouse_EventScript_PostBattle_5

SunriseVillage_EldersHouse_EventScript_PostBattle_8:
# 454 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_TEMP_1, 7
	goto_if_eq SunriseVillage_EldersHouse_EventScript_PostBattle_6
	goto SunriseVillage_EldersHouse_EventScript_PostBattle_7


SunriseVillage_EldersHouse_EventScript_RivalBattle::
# 476 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	switch VAR_STARTER_MON
# 477 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_FROAKIE, SunriseVillage_EldersHouse_EventScript_RivalBattle_3
# 479 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_SNIVY, SunriseVillage_EldersHouse_EventScript_RivalBattle_4
# 481 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_CYNDAQUIL, SunriseVillage_EldersHouse_EventScript_RivalBattle_5
SunriseVillage_EldersHouse_EventScript_RivalBattle_1:
# 485 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	goto SunriseVillage_EldersHouse_EventScript_PostBattle
	return

SunriseVillage_EldersHouse_EventScript_RivalBattle_3:
# 478 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	trainerbattle_no_intro_no_whiteout TRAINER_RIVAL_FIRST_BATTLE_FROAKIE, SunriseVillage_EldersHouse_EventScript_RivalBattle_Text_0
	goto SunriseVillage_EldersHouse_EventScript_RivalBattle_1

SunriseVillage_EldersHouse_EventScript_RivalBattle_4:
# 480 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	trainerbattle_no_intro_no_whiteout TRAINER_RIVAL_FIRST_BATTLE_SNIVY, SunriseVillage_EldersHouse_EventScript_RivalBattle_Text_0
	goto SunriseVillage_EldersHouse_EventScript_RivalBattle_1

SunriseVillage_EldersHouse_EventScript_RivalBattle_5:
# 482 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	trainerbattle_no_intro_no_whiteout TRAINER_RIVAL_FIRST_BATTLE_CYNDAQUIL, SunriseVillage_EldersHouse_EventScript_RivalBattle_Text_0
	goto SunriseVillage_EldersHouse_EventScript_RivalBattle_1


SunriseVillage_EldersHouse_EventScript_Joltik::
# 489 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lock
# 490 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	faceplayer
# 491 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitse
# 492 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playmoncry SPECIES_JOLTIK, CRY_MODE_NORMAL
# 493 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_Joltik_Text_0
# 496 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmoncry
# 497 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	release
	end


# 30 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_0:
# 30 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 30 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 30 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 30 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 45 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_1:
# 45 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 45 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 45 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 45 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 45 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 45 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_down
# 45 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 60 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_2:
# 60 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_right
# 60 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	face_up
# 60 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
	step_end

# 87 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_3:
# 87 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 87 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 87 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 87 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	face_down
	step_end

# 91 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Movement_4:
# 91 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	jump_in_place_up
	step_end

# 149 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_EventScript_TryToEnterOtherRoom_Movement_0:
# 149 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
	step_end

# 248 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_0:
# 248 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 248 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 248 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 248 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 248 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 248 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 250 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_1:
# 250 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 250 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 250 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 250 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 255 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_2:
# 255 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 255 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 255 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 255 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 255 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 257 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_3:
# 257 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 257 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 257 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 259 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_4:
# 259 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_right
# 259 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 259 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 259 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 259 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 264 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_5:
# 264 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 264 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 264 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 264 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 264 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 264 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 264 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 266 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_6:
# 266 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 266 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 266 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 266 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 266 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 268 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_7:
# 268 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 268 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 268 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 268 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 268 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 268 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 268 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 285 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_8:
# 285 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 285 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 285 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 285 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
	step_end

# 289 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_9:
# 289 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_right
# 289 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 289 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 289 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
	step_end

# 292 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_10:
# 292 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 292 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_right
# 292 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 292 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
	step_end

# 296 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_11:
# 296 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 296 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 296 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 296 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
	step_end

# 299 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_12:
# 299 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 299 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
	step_end

# 303 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_13:
# 303 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 303 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 303 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
	step_end

# 317 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_14:
# 317 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_right
# 317 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_right
# 317 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_down
# 317 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 317 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 317 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_down
# 317 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
	step_end

# 408 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Movement_15:
# 408 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	face_player
	step_end

# 455 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_EventScript_PostBattle_Movement_0:
# 455 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 455 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 455 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
	step_end

# 457 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_EventScript_PostBattle_Movement_1:
# 457 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 457 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
	step_end

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0:
# 35 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Elder Kaba$"

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_1:
# 37 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{PLAYER}, Natsuki.\nYou are late. Why am I surprised?\p"
	.string "I always have to run after you two!\nNow stay still for a minute and\llisten closely!\p"
	.string "As you have heard, the woods, and even\nthe roads, are no longer safe.\p"
	.string "We don't yet know why, but the wild\nPokémon that usually hide in the\ltall grass and live peacefully\lalongside men have started behaving\laggressively.\p"
	.string "There are reports of travelers being\nattacked from several nearby villages.\p"
	.string "This is all very worrying…$"

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_2:
# 49 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Which is why!\p"
	.string "The Toku council has decided that,\n"
	.string "for the time being, the best way to\l"
	.string "handle this is to use the Pokémon\l"
	.string "themselves as a means of protection!\p"
	.string "There were very few experienced\n"
	.string "Pokémon wielders in Toku until now.\l"
	.string "This is about to change.\p"
	.string "With a trained Pokémon by your side,\n"
	.string "you'll be able to defend yourselves\l"
	.string "on your own.\p"
	.string "Without further ado, please carefully\n"
	.string "choose your new companion!$"

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3:
# 93 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Natsuki$"

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_4:
# 94 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Woah! Cool.$"

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_5:
# 102 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{PLAYER}, choose yours first!\n"
	.string "I don't mind being second pick.$"

SunriseVillage_EldersHouse_Event_Elder_Text_0:
# 118 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "How is your Pokémon adventure going?$"

SunriseVillage_EldersHouse_Event_Elder_Text_1:
# 122 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Choose your new partner wisely.\n"
	.string "No takebacks.$"

SunriseVillage_EldersHouse_EventScript_TryToLeave_Text_0:
# 133 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Where do you think you're going?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_0:
# 178 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "You already got a Pokémon.\n"
	.string "Better leave this one here.$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_1:
# 188 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Do you choose {STR_VAR_1},\n"
	.string "soul of the crashing sea waves?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_2:
# 190 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Do you choose {STR_VAR_1},\n"
	.string "swift leafy dragon?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_3:
# 192 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Do you choose {STR_VAR_1},\n"
	.string "tender heart of the hearth?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_4:
# 197 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Take the time you need.$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_5:
# 210 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{PLAYER} received the Pokémon\n"
	.string "{STR_VAR_1}!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_6:
# 280 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Alright. I'm taking this one!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_7:
# 310 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Now that you have your own Pokémon,\n"
	.string "you two are officially\l"
	.string "Pokémon wielders!\p"
	.string "The more wielders there are,\n"
	.string "the deeper our understanding\l"
	.string "of Pokémon will be.\p"
	.string "We need to study these creatures\n"
	.string "from up close to find the root of\l"
	.string "this issue.\p"
	.string "Actually, there's something\n"
	.string "I wanted to ask you.$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_8:
# 321 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{PLAYER} received the Pokédex!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_9:
# 332 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "What's this? A book?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_10:
# 340 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
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
	.string "Could you deliver him this letter?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_11:
# 351 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{PLAYER} received the Letter!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_12:
# 356 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Understood, Grandma Kaba.\n"
	.string "We're going adventuring!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_13:
# 364 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{PLAYER}… Are you ready?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_14:
# 372 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Totally!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_15:
# 373 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Absolutely not!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_16:
# 378 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "That's what I'm talking about!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_17:
# 388 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Don't listen to him! He's so ready!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_18:
# 392 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Don't listen to her! She's so ready!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_19:
# 402 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{PLAYER}!\n"
	.string "Let's see what our brand-new Pokémon\l"
	.string "are capable of!\p"
	.string "I request an official Pokémon\n"
	.string "wielder battle!$"

SunriseVillage_EldersHouse_EventScript_Natsuki_Text_0:
# 425 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Hm, which one will I choose?…$"

SunriseVillage_EldersHouse_EventScript_PostBattle_Text_0:
# 434 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Oh, man!\n"
	.string "That was the most fun I've ever had!\p"
	.string "{PLAYER}!\n"
	.string "We're now officially rivals!\p"
	.string "I went easy on you this time, but\n"
	.string "next time… You'll see!\p"
	.string "I'm going home to pack some things.\p"
	.string "See ya later, Feraligatr.$"

SunriseVillage_EldersHouse_EventScript_PostBattle_Text_1:
# 444 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Oh, man!\n"
	.string "That was the most fun I've ever had!\p"
	.string "{PLAYER}!\n"
	.string "We're now officially rivals!\p"
	.string "You better work hard to keep up!\p"
	.string "I'm going home to pack some things.\p"
	.string "See ya later, Feraligatr.$"

SunriseVillage_EldersHouse_EventScript_RivalBattle_Text_0:
# 478 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Looks like I lost!$"

SunriseVillage_EldersHouse_EventScript_Joltik_Text_0:
# 494 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Fss!$"

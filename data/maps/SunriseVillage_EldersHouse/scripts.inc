SunriseVillage_EldersHouse_MapScripts::
# 17 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 14 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 18 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 4
	goto_if_gt SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
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
# 36 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lock
# 38 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Movement_PlayerWalkUpToElder
# 39 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 40 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterDown
# 43 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
# 44 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_1
# 52 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 53 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 1, SunriseVillage_EldersHouse_Movement_ElderTurnsToThink
# 54 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 55 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
# 56 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_2
# 64 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 66 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	clearflag FLAG_TEMP_1
# 68 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 1, SunriseVillage_EldersHouse_Movement_ElderOpensFirstBall
# 69 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 70 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playse SE_BALL_OPEN
# 71 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitse
# 72 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 3
# 73 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	addobject 6
# 74 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playmoncry SPECIES_ARON, CRY_MODE_NORMAL
# 75 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay 30
# 77 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 1, SunriseVillage_EldersHouse_Movement_ElderOpensSecondBall
# 78 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 79 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playse SE_BALL_OPEN
# 80 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitse
# 81 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 4
# 82 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	addobject 7
# 83 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playmoncry SPECIES_SPHEAL, CRY_MODE_NORMAL
# 84 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay 30
# 86 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 1, SunriseVillage_EldersHouse_Movement_ElderOpensThirdBall
# 87 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 88 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playse SE_BALL_OPEN
# 89 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitse
# 90 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 5
# 91 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	addobject 8
# 92 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playmoncry SPECIES_TRAPINCH, CRY_MODE_NORMAL
# 93 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay 30
# 95 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 1, SunriseVillage_EldersHouse_Movement_ElderReturnsToInitialPos
# 96 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 98 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playse SE_LEDGE
# 99 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_Movement_RivalIsDeslighted
# 100 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 101 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 102 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_4
# 105 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 106 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceFasterLeft
# 107 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 108 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 109 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_5
# 113 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 114 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 116 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 5
# 117 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	release
	return


# 120 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_ElderOpensFirstBall:
# 121 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_right
# 122 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	face_up
# 123 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
	step_end

# 126 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_ElderOpensSecondBall:
# 127 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_right
# 128 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	face_up
# 129 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
	step_end

# 132 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_ElderOpensThirdBall:
# 133 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_right
# 134 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	face_up
# 135 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
	step_end

# 138 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_ElderReturnsToInitialPos:
# 139 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 139 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 139 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 140 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	face_down
	step_end

# 143 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_RivalIsDeslighted:
# 144 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	jump_in_place_up
	step_end

SunriseVillage_EldersHouse_Event_Elder::
# 148 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lock
# 149 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	faceplayer
# 150 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
# 151 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 7
	goto_if_ge SunriseVillage_EldersHouse_Event_Elder_2
# 157 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Elder_Text_1
# 158 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
SunriseVillage_EldersHouse_Event_Elder_1:
# 160 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	release
	return

SunriseVillage_EldersHouse_Event_Elder_2:
# 153 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Elder_Text_0
# 154 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
	goto SunriseVillage_EldersHouse_Event_Elder_1


SunriseVillage_EldersHouse_EventScript_TryToLeave::
# 164 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lock
# 165 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	turnobject 1, DIR_SOUTH
# 166 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
# 167 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_TryToLeave_Text_0
# 170 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 171 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
# 172 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 173 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	release
	return


SunriseVillage_EldersHouse_EventScript_TryToEnterOtherRoom::
# 177 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lock
# 178 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	turnobject 1, DIR_NORTH
# 179 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
# 180 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_TryToLeave_Text_0
# 183 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 184 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
# 185 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 186 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	release
	return


# 189 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_PlayerGetAwayFromExit:
# 190 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 191 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 194 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_PlayerWalkUpToElder:
# 195 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 195 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 196 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 199 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_ElderTurnsToThink:
# 200 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 201 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 201 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 201 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 201 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 202 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_down
# 203 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

SunriseVillage_EldersHouse_Event_Pokeball_Starter_Trapinch::
# 207 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lock
# 208 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_TRAPINCH
# 209 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	call SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter
# 210 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	release
	return


SunriseVillage_EldersHouse_Event_Pokeball_Starter_Aron::
# 214 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lock
# 215 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_ARON
# 216 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	call SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter
# 217 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	release
	return


SunriseVillage_EldersHouse_Event_Pokeball_Starter_Spheal::
# 221 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lock
# 222 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_SPHEAL
# 223 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	call SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter
# 224 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	release
	return


SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter::
# 228 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_2
# 235 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playmoncry VAR_TEMP_1, CRY_MODE_NORMAL
# 236 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	showmonpic VAR_TEMP_1, 10, 3
# 237 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 238 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	switch VAR_TEMP_1
# 239 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_SPHEAL, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_6
# 241 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_ARON, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_7
# 243 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_TRAPINCH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_8
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_4:
# 246 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_10
# 246 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_10
# 252 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_11
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_9:
# 288 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	hidemonpic
# 290 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setflag FLAG_RECEIVED_STARTER
# 291 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 293 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	turnobject 2, DIR_NORTH
# 296 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	switch VAR_STARTER_MON
# 297 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_SPHEAL, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_18
# 304 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_ARON, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_19
# 313 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_TRAPINCH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_20
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16:
# 324 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 326 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	turnobject 1, DIR_SOUTH
# 328 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
# 331 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 332 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_6
# 333 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 335 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	switch VAR_STARTER_MON
# 336 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_SPHEAL, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_28
# 343 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_ARON, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_29
# 350 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_TRAPINCH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_30
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_26:
# 360 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
# 361 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_7
# 367 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 369 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 1, SunriseVillage_EldersHouse_Movement_ElderGivesDex
# 370 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 372 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 373 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	message SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_8
# 374 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitfanfare
# 375 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 377 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 378 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 380 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay 20
# 382 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 383 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_9
# 386 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 388 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay 20
# 390 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
# 391 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_10
# 399 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 401 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 403 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	message SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_11
# 404 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitfanfare
# 405 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 407 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 408 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_12
# 409 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 411 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceFasterLeft
# 412 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 413 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 2
# 415 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 416 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_13
# 417 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	dynmultichoice 16, 6, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_14, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_15
# 428 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_48
# 434 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceFasterUp
# 436 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 437 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	checkplayergender
# 438 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_55
# 443 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_18
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_54:
# 447 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 449 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceFasterLeft
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_47:
# 452 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 453 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_19
# 457 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 459 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_Movement_RivalPreBattlePose
# 460 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 462 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 6
# 465 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	goto SunriseVillage_EldersHouse_EventScript_RivalBattle
	return

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_2:
# 229 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_0
# 232 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
	return

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_6:
# 240 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_1, MSGBOX_YESNO
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_4

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_7:
# 242 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_2, MSGBOX_YESNO
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_4

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_8:
# 244 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_3, MSGBOX_YESNO
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_4

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_10:
# 247 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	hidemonpic
# 248 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0
# 249 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_4
# 250 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
	return

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_11:
# 253 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	switch VAR_TEMP_1
# 254 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_SPHEAL, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_23
# 256 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_ARON, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_24
# 258 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_TRAPINCH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_25
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_21:
# 261 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 262 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	message SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_5
# 263 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmessage
# 264 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitfanfare
# 266 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	switch VAR_TEMP_1
# 267 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_SPHEAL, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_44
# 271 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_ARON, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_45
# 275 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_TRAPINCH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_46
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_42:
# 281 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 282 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_52
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_51:
# 286 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_9

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_18:
# 298 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	switch VAR_FACING
# 299 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case DIR_SOUTH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_32
# 301 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case DIR_NORTH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_33
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_19:
# 305 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	switch VAR_FACING
# 306 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case DIR_SOUTH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_35
# 308 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case DIR_NORTH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_36
# 310 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case DIR_EAST, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_37
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_20:
# 314 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	switch VAR_FACING
# 315 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case DIR_SOUTH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_39
# 317 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case DIR_NORTH, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_40
# 319 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case DIR_WEST, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_41
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_23:
# 255 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	givemon SPECIES_SPHEAL, 5, ITEM_ORAN_BERRY, move1 = MOVE_FLIPPER_SPLASH, move2 = MOVE_TAIL_WHIP, move3 = MOVE_NONE, move4 = MOVE_NONE
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_21

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_24:
# 257 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	givemon SPECIES_ARON, 5, ITEM_ORAN_BERRY, move1 = MOVE_TACKLE, move2 = MOVE_HARDEN, move3 = MOVE_NONE, move4 = MOVE_NONE
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_21

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_25:
# 259 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	givemon SPECIES_TRAPINCH, 5, ITEM_ORAN_BERRY, move1 = MOVE_MUD_SLAP, move2 = MOVE_SAND_ATTACK, move3 = MOVE_NONE, move4 = MOVE_NONE
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_21

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_28:
# 337 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_Movement_RivalWalkUpToAron
# 338 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 339 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 6
# 340 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 3
# 341 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_Movement_RivalWalkAwayFromAron
# 342 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_26

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_29:
# 344 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_Movement_RivalWalkUpToTrapinch
# 345 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 346 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 8
# 347 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 5
# 348 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_Movement_RivalWalkAwayFromTrapinch
# 349 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_26

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_30:
# 351 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_Movement_RivalWalkUpToSpheal
# 352 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 353 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 7
# 354 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 4
# 355 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_Movement_RivalWalkAwayFromSpheal
# 356 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_26

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_32:
# 300 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Movement_PlayerGoesBackAfterPickingSphealFromTop
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_33:
# 302 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Movement_PlayerGoesBackAfterPickingSphealFromBottom
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_35:
# 307 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Movement_PlayerGoesBackAfterPickingAronFromTop
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_36:
# 309 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Movement_PlayerGoesBackAfterPickingAronFromBottom
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_37:
# 311 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Movement_PlayerGoesBackAfterPickingAronFromLeft
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_39:
# 316 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Movement_PlayerGoesBackAfterPickingTrapinchFromTop
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_40:
# 318 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Movement_PlayerGoesBackAfterPickingTrapinchFromBottom
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_41:
# 320 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Movement_PlayerGoesBackAfterPickingTrapinchFromRight
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_16

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_44:
# 268 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_SPHEAL
# 269 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 7
# 270 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 4
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_42

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_45:
# 272 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 6
# 273 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 3
# 274 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_ARON
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_42

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_46:
# 276 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 8
# 277 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 5
# 278 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_STARTER_MON, SPECIES_TRAPINCH
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_42

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_48:
# 429 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_16
# 432 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_47

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_52:
# 283 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 284 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_51

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_55:
# 439 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_17
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_54


# 468 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_RivalPreBattlePose:
# 471 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	face_player
	step_end

SunriseVillage_EldersHouse_EventScript_Natsuki::
# 475 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 476 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_Natsuki_Text_0, MSGBOX_NPC
	return


SunriseVillage_EldersHouse_EventScript_PostBattle::
# 480 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	special HealPlayerParty
# 481 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 482 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SunriseVillage_EldersHouse_EventScript_PostBattle_2
# 493 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 494 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_PostBattle_Text_1
# 501 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
SunriseVillage_EldersHouse_EventScript_PostBattle_1:
# 506 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 507 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_TEMP_0, 6
	goto_if_eq SunriseVillage_EldersHouse_EventScript_PostBattle_8
SunriseVillage_EldersHouse_EventScript_PostBattle_7:
# 510 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_Movement_RivalLeaves
SunriseVillage_EldersHouse_EventScript_PostBattle_5:
# 513 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 2
# 514 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 515 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 2
# 516 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playse SE_EXIT
# 517 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitse
# 518 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay 16
# 520 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 7
# 523 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	resumefakertc
# 525 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	release
	return

SunriseVillage_EldersHouse_EventScript_PostBattle_2:
# 483 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	speakername SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_3
# 484 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_PostBattle_Text_0
# 491 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
	goto SunriseVillage_EldersHouse_EventScript_PostBattle_1

SunriseVillage_EldersHouse_EventScript_PostBattle_6:
# 508 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 2, SunriseVillage_EldersHouse_Movement_RivalLeavesWhenPlayerIsBottom
	goto SunriseVillage_EldersHouse_EventScript_PostBattle_5

SunriseVillage_EldersHouse_EventScript_PostBattle_8:
# 507 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_TEMP_1, 7
	goto_if_eq SunriseVillage_EldersHouse_EventScript_PostBattle_6
	goto SunriseVillage_EldersHouse_EventScript_PostBattle_7


SunriseVillage_EldersHouse_EventScript_RivalBattle::
# 529 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	switch VAR_STARTER_MON
# 530 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_SPHEAL, SunriseVillage_EldersHouse_EventScript_RivalBattle_3
# 532 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_ARON, SunriseVillage_EldersHouse_EventScript_RivalBattle_4
# 534 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	case SPECIES_TRAPINCH, SunriseVillage_EldersHouse_EventScript_RivalBattle_5
SunriseVillage_EldersHouse_EventScript_RivalBattle_1:
# 538 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	goto SunriseVillage_EldersHouse_EventScript_PostBattle
	return

SunriseVillage_EldersHouse_EventScript_RivalBattle_3:
# 531 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	trainerbattle_no_intro_no_whiteout TRAINER_RIVAL_FIRST_BATTLE_SPHEAL, SunriseVillage_EldersHouse_EventScript_RivalBattle_Text_0
	goto SunriseVillage_EldersHouse_EventScript_RivalBattle_1

SunriseVillage_EldersHouse_EventScript_RivalBattle_4:
# 533 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	trainerbattle_no_intro_no_whiteout TRAINER_RIVAL_FIRST_BATTLE_ARON, SunriseVillage_EldersHouse_EventScript_RivalBattle_Text_0
	goto SunriseVillage_EldersHouse_EventScript_RivalBattle_1

SunriseVillage_EldersHouse_EventScript_RivalBattle_5:
# 535 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	trainerbattle_no_intro_no_whiteout TRAINER_RIVAL_FIRST_BATTLE_TRAPINCH, SunriseVillage_EldersHouse_EventScript_RivalBattle_Text_0
	goto SunriseVillage_EldersHouse_EventScript_RivalBattle_1


SunriseVillage_EldersHouse_EventScript_Joltik::
# 542 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lock
# 543 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	faceplayer
# 544 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitse
# 545 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playmoncry SPECIES_JOLTIK, CRY_MODE_NORMAL
# 546 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_EventScript_Joltik_Text_0
# 549 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmoncry
# 550 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	release
	end


# 554 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_RivalWalkUpToSpheal:
# 555 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 556 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 557 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 560 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_RivalWalkAwayFromSpheal:
# 561 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 562 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 563 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 564 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 567 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_RivalWalkUpToTrapinch:
# 568 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 569 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_right
# 570 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 571 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 572 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 575 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_RivalWalkAwayFromTrapinch:
# 576 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 577 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 578 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 579 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 580 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 584 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_RivalWalkUpToAron:
# 585 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 586 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 587 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 588 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 589 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 592 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_RivalWalkAwayFromAron:
# 593 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_right
# 594 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 595 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 596 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 597 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 600 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_ElderGivesDex:
# 601 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_right
# 601 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_right
# 602 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_down
# 603 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 604 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 605 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_down
# 606 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 607 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 610 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_RivalLeaves:
# 611 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 611 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 612 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 616 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_RivalLeavesWhenPlayerIsBottom:
# 617 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 618 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 618 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 619 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 622 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_PlayerGoesBackAfterPickingSphealFromTop:
# 623 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 623 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 624 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 625 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 626 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 627 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 630 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_PlayerGoesBackAfterPickingSphealFromBottom:
# 631 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 632 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 633 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 634 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 637 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_PlayerGoesBackAfterPickingAronFromTop:
# 638 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 638 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 638 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 639 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 640 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 643 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_PlayerGoesBackAfterPickingAronFromBottom:
# 644 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 645 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 646 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 649 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_PlayerGoesBackAfterPickingAronFromLeft:
# 650 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 651 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 651 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 652 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_right
# 652 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_right
# 653 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 654 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 657 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_PlayerGoesBackAfterPickingTrapinchFromTop:
# 658 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_right
# 659 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 659 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 660 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 660 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 661 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 662 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 663 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 666 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_PlayerGoesBackAfterPickingTrapinchFromBottom:
# 667 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 667 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 668 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 669 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 670 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 673 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_PlayerGoesBackAfterPickingTrapinchFromRight:
# 674 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 675 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 675 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 676 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 677 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_in_place_faster_up
# 678 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_0:
# 43 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Elder Kaba$"

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_1:
# 45 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{PLAYER}, Natsuki.\nYou are late. Why am I surprised?\p"
	.string "I always have to run after you two!\nNow stay still for a minute and\llisten closely!\p"
	.string "As you have heard, the woods, and even\nthe roads, are no longer safe.\p"
	.string "We don't yet know why, but the wild\nPokémon that usually hide in the\ltall grass and live peacefully\lalongside men have started behaving\laggressively.\p"
	.string "There are reports of travelers being\nattacked from several nearby villages.\p"
	.string "This is all very worrying…$"

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_2:
# 57 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
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
# 101 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Natsuki$"

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_4:
# 102 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Woah! Cool.$"

SunriseVillage_EldersHouse_EventScript_DistributionCutscene_Text_5:
# 110 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{PLAYER}, choose yours first!\n"
	.string "I don't mind being second pick.$"

SunriseVillage_EldersHouse_Event_Elder_Text_0:
# 153 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "How is your Pokémon adventure going?$"

SunriseVillage_EldersHouse_Event_Elder_Text_1:
# 157 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Choose your new partner wisely.\n"
	.string "No takebacks.$"

SunriseVillage_EldersHouse_EventScript_TryToLeave_Text_0:
# 168 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Where do you think you're going?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_0:
# 230 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "You already got a Pokémon.\n"
	.string "Better leave this one here.$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_1:
# 240 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Do you choose {STR_VAR_1},\n"
	.string "soul of the crashing sea waves?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_2:
# 242 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Do you choose {STR_VAR_1},\n"
	.string "noble warrior of iron?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_3:
# 244 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Do you choose {STR_VAR_1},\n"
	.string "swift dancer of sandstorms?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_4:
# 249 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Take the time you need.$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_5:
# 262 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{PLAYER} received the Pokémon\n"
	.string "{STR_VAR_1}!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_6:
# 332 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Alright. I'm taking this one!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_7:
# 362 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
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
# 373 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{PLAYER} received the Pokédex!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_9:
# 384 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "What's this? A book?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_10:
# 392 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
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
# 403 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{PLAYER} received the Letter!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_12:
# 408 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Understood, Grandma Kaba.\n"
	.string "We're going adventuring!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_13:
# 416 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{PLAYER}… Are you ready?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_14:
# 424 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Totally!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_15:
# 425 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Absolutely not!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_16:
# 430 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "That's what I'm talking about!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_17:
# 440 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Don't listen to him! He's so ready!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_18:
# 444 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Don't listen to her! She's so ready!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_19:
# 454 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{PLAYER}!\n"
	.string "Let's see what our brand-new Pokémon\l"
	.string "are capable of!\p"
	.string "I request an official Pokémon\n"
	.string "wielder battle!$"

SunriseVillage_EldersHouse_EventScript_Natsuki_Text_0:
# 476 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Hm, which one will I choose?…$"

SunriseVillage_EldersHouse_EventScript_PostBattle_Text_0:
# 485 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Oh, man!\n"
	.string "That was the most fun I've ever had!\p"
	.string "{PLAYER}!\n"
	.string "We're now officially rivals!\p"
	.string "I went easy on you this time, but\n"
	.string "next time… You'll see!\p"
	.string "I'm going home to pack some things.\p"
	.string "See ya later, Feraligatr.$"

SunriseVillage_EldersHouse_EventScript_PostBattle_Text_1:
# 495 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Oh, man!\n"
	.string "That was the most fun I've ever had!\p"
	.string "{PLAYER}!\n"
	.string "We're now officially rivals!\p"
	.string "You better work hard to keep up!\p"
	.string "I'm going home to pack some things.\p"
	.string "See ya later, Feraligatr.$"

SunriseVillage_EldersHouse_EventScript_RivalBattle_Text_0:
# 531 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Looks like I lost!$"

SunriseVillage_EldersHouse_EventScript_Joltik_Text_0:
# 547 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Fss!$"

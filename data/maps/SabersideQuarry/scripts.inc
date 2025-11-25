SabersideQuarry_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SabersideQuarry_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_TRANSITION, SabersideQuarry_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SabersideQuarry_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_SPOOKED_SABLEYE, SabersideQuarry_MapScripts_MAP_SCRIPT_ON_LOAD_1
	setmetatile 61, 48, METATILE_Quarry_Sand, FALSE
	setmetatile 63, 50, METATILE_Quarry_Sand, FALSE
	setmetatile 63, 51, METATILE_Quarry_Sand, FALSE
	setmetatile 63, 52, METATILE_Quarry_Sand, FALSE
	setmetatile 64, 52, METATILE_Quarry_Sand, FALSE
	setmetatile 65, 52, METATILE_Quarry_Sand, FALSE
	setmetatile 66, 51, METATILE_Quarry_Sand, FALSE
	setmetatile 67, 51, METATILE_Quarry_SandRightEdge, FALSE
	special DrawWholeMapView
	return

SabersideQuarry_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	call SabersideQuarry_DrawSableyePrints
	return

SabersideQuarry_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_ITEM_QUARRY_SHADOW_CLAW, SabersideQuarry_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	goto_if_unset FLAG_SPOOKED_SABLEYE, SabersideQuarry_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

SabersideQuarry_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_TEMP_1
	return


SabersideQuarry_DrawSableyePrints::
	setmetatile 64, 34, METATILE_Quarry_PawprintLeftDown, FALSE
	setmetatile 63, 34, METATILE_Quarry_PawprintLeftUp, FALSE
	setmetatile 62, 34, METATILE_Quarry_PawprintLeftDown, FALSE
	setmetatile 61, 34, METATILE_Quarry_PawprintLeftUp, FALSE
	return


SabersideQuarry_EventScript_ShadowClaw::
	lock
	finditem ITEM_TM_SHADOW_CLAW
	release
	return


SabersideQuarry_EventScript_SpookSableye::
	lockall
	setflag FLAG_SPOOKED_SABLEYE
	setseenmon SPECIES_SABLEYE
	playmoncry SPECIES_SABLEYE, CRY_MODE_NORMAL
	applymovement LOCALID_QUARRY_SABLEYE, SabersideQuarry_EventScript_SpookSableye_Movement_0
	waitmovement LOCALID_QUARRY_SABLEYE
	waitmoncry
	playse SE_FLEE
	applymovement LOCALID_QUARRY_SABLEYE, SabersideQuarry_EventScript_SpookSableye_Movement_1
	setmetatile 64, 34, METATILE_Quarry_PawprintLeftDownNotSand, FALSE
	special DrawWholeMapView
	waitmovement LOCALID_QUARRY_SABLEYE
	applymovement LOCALID_QUARRY_SABLEYE, SabersideQuarry_EventScript_SpookSableye_Movement_1
	setmetatile 63, 34, METATILE_Quarry_PawprintLeftUpNotSand, FALSE
	special DrawWholeMapView
	waitmovement LOCALID_QUARRY_SABLEYE
	applymovement LOCALID_QUARRY_SABLEYE, SabersideQuarry_EventScript_SpookSableye_Movement_1
	setmetatile 62, 34, METATILE_Quarry_PawprintLeftDownNotSand, FALSE
	special DrawWholeMapView
	waitmovement LOCALID_QUARRY_SABLEYE
	applymovement LOCALID_PLAYER, SabersideQuarry_EventScript_SpookSableye_Movement_2
	waitse
	playse SE_LEDGE
	applymovement LOCALID_QUARRY_SABLEYE, SabersideQuarry_EventScript_SpookSableye_Movement_3
	setmetatile 61, 34, METATILE_Quarry_PawprintLeftUpNotSand, FALSE
	special DrawWholeMapView
	waitmovement LOCALID_QUARRY_SABLEYE
	applymovement LOCALID_PLAYER, SabersideQuarry_EventScript_SpookSableye_Movement_4
	applymovement LOCALID_QUARRY_SABLEYE, SabersideQuarry_EventScript_SpookSableye_Movement_5
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	waitmovement LOCALID_QUARRY_SABLEYE
	removeobject LOCALID_QUARRY_SABLEYE
	call SabersideQuarry_DrawSableyePrints
	special DrawWholeMapView
	releaseall
	return


SabersideQuarry_EventScript_SpookSableye_Movement_0:
	face_down
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

SabersideQuarry_EventScript_SpookSableye_Movement_1:
	walk_fast_left
	step_end

SabersideQuarry_EventScript_SpookSableye_Movement_2:
	face_left
	step_end

SabersideQuarry_EventScript_SpookSableye_Movement_3:
	jump_2_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

SabersideQuarry_EventScript_SpookSableye_Movement_4:
	face_down
	step_end

SabersideQuarry_EventScript_SpookSableye_Movement_5:
	jump_down
	jump_down
	walk_fast_down
	walk_fast_down
	step_end

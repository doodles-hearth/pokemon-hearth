SunriseCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SunriseCave_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SunriseCave_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_TEMP_0, 0
	goto_if_ne SunriseCave_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

SunriseCave_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_TEMP_1
	return


SunriseCave_Trigger_ScaringKrabby::
	lockall
	setseenmon SPECIES_KRABBY
	setvar VAR_TEMP_0, 1
	playmoncry SPECIES_KRABBY, CRY_MODE_NORMAL
	applymovement LOCALID_SUNRISE_KRABBY_1, SunriseCave_Trigger_ScaringKrabby_Movement_0
	delay 16
	playmoncry SPECIES_KRABBY, CRY_MODE_NORMAL
	applymovement LOCALID_SUNRISE_KRABBY_2, SunriseCave_Trigger_ScaringKrabby_Movement_1
	waitmovement LOCALID_SUNRISE_KRABBY_1
	playse SE_LEDGE
	applymovement LOCALID_SUNRISE_KRABBY_1, SunriseCave_Trigger_ScaringKrabby_Movement_2
	waitse
	playse SE_BALL
	waitmovement LOCALID_SUNRISE_KRABBY_2
	playse SE_LEDGE
	applymovement LOCALID_SUNRISE_KRABBY_2, SunriseCave_Trigger_ScaringKrabby_Movement_2
	waitse
	playse SE_BALL
	waitmovement LOCALID_SUNRISE_KRABBY_1
	waitmovement LOCALID_SUNRISE_KRABBY_2
	removeobject LOCALID_SUNRISE_KRABBY_1
	removeobject LOCALID_SUNRISE_KRABBY_2
	setflag FLAG_TEMP_1
	releaseall
	return


SunriseCave_Trigger_ScaringKrabby_Movement_0:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	walk_fast_up
	step_end

SunriseCave_Trigger_ScaringKrabby_Movement_1:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	walk_fast_up
	walk_fast_up
	step_end

SunriseCave_Trigger_ScaringKrabby_Movement_2:
	jump_up
	set_invisible
	step_end

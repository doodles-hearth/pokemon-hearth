SabersideTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SabersideTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SabersideTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SabersideTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_SHIP_SABERSIDE_SOULKEEP, 0
	goto_if_eq SabersideTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	compare VAR_SHIP_SABERSIDE_SOULKEEP, 2
	goto_if_ne SabersideTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

SabersideTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setobjectxyperm LOCALID_SABERSIDE_BOAT_GUY, 8, 27
	setobjectxyperm LOCALID_SABERSIDE_WINGULL, 9, 26
	return

SabersideTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setflag FLAG_TEMP_1
	return

SabersideTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_SHIP_SABERSIDE_SOULKEEP, 0, SabersideTown_EventScript_AnchorBoat
	.2byte 0


SabersideTown_EventScript_AnchorBoat::
	lockall
	waitse
	playse SE_LEDGE
	applymovement LOCALID_PLAYER, SabersideTown_EventScript_AnchorBoat_Movement_0
	waitse
	delay 16
	playse SE_LEDGE
	applymovement LOCALID_SABERSIDE_BOAT_GUY, SabersideTown_EventScript_AnchorBoat_Movement_1
	waitmovement LOCALID_SABERSIDE_BOAT_GUY
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	applymovement LOCALID_SABERSIDE_WINGULL, SabersideTown_EventScript_AnchorBoat_Movement_2
	waitmoncry
	setvar VAR_SHIP_SABERSIDE_SOULKEEP, 2
	waitmovement 0
	releaseall
	return


SabersideTown_EventScript_Wingull::
	lock
	faceplayer
	setseenmon SPECIES_WINGULL
	setspeakertomonname SPECIES_WINGULL
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox SabersideTown_EventScript_Wingull_Text_0
	waitmoncry
	release
	return


SabersideTown_EventScript_BoatGuy::
	lock
	faceplayer
	msgbox SabersideTown_EventScript_BoatGuy_Text_0
	mcdialogueB SabersideTown_EventScript_BoatGuy_Text_1, SabersideTown_EventScript_BoatGuy_Text_2
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq SabersideTown_EventScript_BoatGuy_2
SabersideTown_EventScript_BoatGuy_1:
	release
	return

SabersideTown_EventScript_BoatGuy_2:
	waitse
	playse SE_LEDGE
	applymovement VAR_LAST_TALKED, SabersideTown_EventScript_BoatGuy_Movement_0
	waitmovement VAR_LAST_TALKED
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	applymovement LOCALID_SABERSIDE_WINGULL, SabersideTown_EventScript_BoatGuy_Movement_1
	waitmoncry
	hidefollower
	applymovement LOCALID_PLAYER, SabersideTown_EventScript_BoatGuy_Movement_2
	waitmovement LOCALID_PLAYER
	playse SE_LEDGE
	applymovement LOCALID_PLAYER, SabersideTown_EventScript_BoatGuy_Movement_3
	waitmovement LOCALID_PLAYER
	waitse
	setvar VAR_SHIP_SABERSIDE_SOULKEEP, 0
	playse SE_MUGSHOT
	warpsilent MAP_LONG_TIDE_CHANNEL_SOULKEEP, WARP_ID_SOULKEEP_BOAT
	goto SabersideTown_EventScript_BoatGuy_1


SabersideTown_EventScript_LoveSwords::
	lock
	msgbox SabersideTown_EventScript_LoveSwords_Text_0
	closemessage
	release
	return


SabersideTown_EventScript_TownSign::
	msgbox SabersideTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


SabersideTown_EventScript_AnchorBoat_Movement_0:
	jump_right
	walk_down
	delay_16
	face_up
	step_end

SabersideTown_EventScript_AnchorBoat_Movement_1:
	jump_2_right
	delay_16
	face_down
	step_end

SabersideTown_EventScript_AnchorBoat_Movement_2:
	walk_right
	walk_right
	walk_down
	step_end

SabersideTown_EventScript_BoatGuy_Movement_0:
	jump_2_left
	delay_16
	delay_16
	step_end

SabersideTown_EventScript_BoatGuy_Movement_1:
	walk_up
	walk_left
	walk_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	step_end

SabersideTown_EventScript_BoatGuy_Movement_2:
	walk_up
	step_end

SabersideTown_EventScript_BoatGuy_Movement_3:
	jump_left
	delay_16
	face_down
	delay_16
	step_end

SabersideTown_EventScript_Wingull_Text_0:
	.string "Eeeh!$"

SabersideTown_EventScript_BoatGuy_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_OLD_MAN EMOTE_NORMAL}{SPEAKER NAME_OLD_MAN}I'm on my way to Soulkeep.\n"
	.string "Want to hop along?$"

SabersideTown_EventScript_BoatGuy_Text_1:
	.string "All aboard!$"

SabersideTown_EventScript_BoatGuy_Text_2:
	.string "No need.$"

SabersideTown_EventScript_LoveSwords_Text_0:
	.string "{SPEAKER NAME_TRAVELER}People come from the whole region to\n"
	.string "get their hands on a Saberside blade.\p"
	.string "$"

SabersideTown_EventScript_TownSign_Text_0:
	.string "Saberside Town\n"
	.string "“A town where folks are strong as\l"
	.string "steel!”$"

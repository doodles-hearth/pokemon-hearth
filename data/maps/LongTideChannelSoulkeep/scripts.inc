LongTideChannelSoulkeep_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LongTideChannelSoulkeep_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LongTideChannelSoulkeep_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LongTideChannelSoulkeep_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_SHIP_SABERSIDE_SOULKEEP, 0
	goto_if_eq LongTideChannelSoulkeep_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	compare VAR_SHIP_SABERSIDE_SOULKEEP, 1
	goto_if_ne LongTideChannelSoulkeep_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

LongTideChannelSoulkeep_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setobjectxyperm LOCALID_LONGTIDE_BOAT_GUY, 57, 16
	setobjectxyperm LOCALID_LONGTIDE_WINGULL, 58, 15
	return

LongTideChannelSoulkeep_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setflag FLAG_TEMP_1
	return

LongTideChannelSoulkeep_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_SHIP_SABERSIDE_SOULKEEP, 0, LongTideChannelSoulkeep_EventScript_AnchorBoat
	.2byte 0


LongTideChannelSoulkeep_EventScript_AnchorBoat::
	lockall
	waitse
	playse SE_LEDGE
	applymovement LOCALID_PLAYER, LongTideChannelSoulkeep_EventScript_AnchorBoat_Movement_0
	waitse
	delay 16
	playse SE_LEDGE
	applymovement LOCALID_LONGTIDE_BOAT_GUY, LongTideChannelSoulkeep_EventScript_AnchorBoat_Movement_1
	waitmovement LOCALID_LONGTIDE_BOAT_GUY
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	applymovement LOCALID_LONGTIDE_WINGULL, LongTideChannelSoulkeep_EventScript_AnchorBoat_Movement_2
	waitmoncry
	setvar VAR_SHIP_SABERSIDE_SOULKEEP, 2
	waitmovement 0
	releaseall
	return


LongTideChannelSoulkeep_RouteSign::
	msgbox LongTideChannelSoulkeep_RouteSign_Text_0, MSGBOX_SIGN
	return


LongTideChannelSoulkeep_EventScript_Wingull::
	lock
	faceplayer
	setseenmon SPECIES_WINGULL
	setspeakertomonname SPECIES_WINGULL
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox LongTideChannelSoulkeep_EventScript_Wingull_Text_0
	waitmoncry
	release
	return


LongTideChannelSoulkeep_EventScript_BoatGuy::
	lock
	faceplayer
	msgbox LongTideChannelSoulkeep_EventScript_BoatGuy_Text_0
	mcdialogueB LongTideChannelSoulkeep_EventScript_BoatGuy_Text_1, LongTideChannelSoulkeep_EventScript_BoatGuy_Text_2
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq LongTideChannelSoulkeep_EventScript_BoatGuy_2
LongTideChannelSoulkeep_EventScript_BoatGuy_1:
	release
	return

LongTideChannelSoulkeep_EventScript_BoatGuy_2:
	waitse
	playse SE_LEDGE
	applymovement VAR_LAST_TALKED, LongTideChannelSoulkeep_EventScript_BoatGuy_Movement_0
	waitmovement VAR_LAST_TALKED
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	applymovement LOCALID_LONGTIDE_WINGULL, LongTideChannelSoulkeep_EventScript_BoatGuy_Movement_1
	waitmoncry
	hidefollower
	applymovement LOCALID_PLAYER, LongTideChannelSoulkeep_EventScript_BoatGuy_Movement_2
	waitmovement LOCALID_PLAYER
	playse SE_LEDGE
	applymovement LOCALID_PLAYER, LongTideChannelSoulkeep_EventScript_BoatGuy_Movement_3
	waitmovement LOCALID_PLAYER
	waitse
	setvar VAR_SHIP_SABERSIDE_SOULKEEP, 0
	playse SE_MUGSHOT
	warpsilent MAP_SABERSIDE_TOWN, WARP_ID_SABERSIDE_BOAT
	goto LongTideChannelSoulkeep_EventScript_BoatGuy_1


LongTideChannelSoulkeep_EventScripts_WhereChatot::
	lock
	faceplayer
	setnamedmon SPECIES_CHATOT
	goto_if_set FLAG_POST_CHATOT, LongTideChannelSoulkeep_EventScripts_WhereChatot_2
	msgbox LongTideChannelSoulkeep_EventScripts_WhereChatot_Text_1
	closemessage
	setdescribedmon SPECIES_CHATOT
LongTideChannelSoulkeep_EventScripts_WhereChatot_1:
	release
	return

LongTideChannelSoulkeep_EventScripts_WhereChatot_2:
	msgbox LongTideChannelSoulkeep_EventScripts_WhereChatot_Text_0
	closemessage
	goto LongTideChannelSoulkeep_EventScripts_WhereChatot_1


LongTideChannelSoulkeep_EventScript_AnchorBoat_Movement_0:
	jump_right
	walk_down
	delay_16
	face_up
	step_end

LongTideChannelSoulkeep_EventScript_AnchorBoat_Movement_1:
	jump_2_right
	delay_16
	face_down
	step_end

LongTideChannelSoulkeep_EventScript_AnchorBoat_Movement_2:
	walk_right
	walk_right
	walk_down
	step_end

LongTideChannelSoulkeep_EventScript_BoatGuy_Movement_0:
	jump_2_left
	delay_16
	delay_16
	step_end

LongTideChannelSoulkeep_EventScript_BoatGuy_Movement_1:
	walk_up
	walk_left
	walk_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	step_end

LongTideChannelSoulkeep_EventScript_BoatGuy_Movement_2:
	walk_up
	step_end

LongTideChannelSoulkeep_EventScript_BoatGuy_Movement_3:
	jump_left
	delay_16
	face_down
	delay_16
	step_end

LongTideChannelSoulkeep_RouteSign_Text_0:
	.string "{LEFT_ARROW} To the Open Sea$"

LongTideChannelSoulkeep_EventScript_Wingull_Text_0:
	.string "Eeeh!$"

LongTideChannelSoulkeep_EventScript_BoatGuy_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_OLD_MAN EMOTE_NORMAL}{SPEAKER NAME_OLD_MAN}I'm on my way to Saberside Town.\n"
	.string "Want to hop along?$"

LongTideChannelSoulkeep_EventScript_BoatGuy_Text_1:
	.string "All aboard!$"

LongTideChannelSoulkeep_EventScript_BoatGuy_Text_2:
	.string "No need.$"

LongTideChannelSoulkeep_EventScripts_WhereChatot_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_LITTLE_BOY EMOTE_NORMAL}{SPEAKER NAME_LITTLE_BOY}Where's Chatot? I wanna see Chatot!$"

LongTideChannelSoulkeep_EventScripts_WhereChatot_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_LITTLE_BOY EMOTE_NORMAL}{SPEAKER NAME_LITTLE_BOY}Oooh, Chatot's here!!\n"
	.string "I love Chatot!\p"
	.string "How would I talk to my friends in Yifu\n"
	.string "City without Chatot? We'd have to\l"
	.string "WRITE stuff to each other, YUCK!\p"
	.string "I love how it flicks its tail to keep a\n"
	.string "rhythm while it speaks!\l"
	.string "And it imitates any voice perfectly!$"

SakuTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_SAKU_TOWN
	goto_if_set FLAG_SAKU_KURA_REUNITED, SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 6
	goto_if_ne SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 6
	goto_if_eq SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_6
SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 7
	goto_if_lt SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_10
SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_9:
	returnqueststate QUEST_SAKURALOVERS
	copyvar VAR_TEMP_0, VAR_RESULT
	returnqueststate QUEST_SAKURAESPEON
	copyvar VAR_TEMP_1, VAR_RESULT
	returnqueststate QUEST_SAKURASCYTHER
	copyvar VAR_TEMP_2, VAR_RESULT
	compare VAR_TEMP_0, 4
	goto_if_eq SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_16
SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14:
	compare VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 7
	goto_if_eq SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_13
	return

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setmetatile 19, 2, METATILE_SakuKura_BoardGame, TRUE
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_RIGHT
	goto SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
	setflag FLAG_HIDE_TAMASDAD
	setflag FLAG_HIDE_DEADNIGHT_TAMA
	goto SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_6:
	clearflag FLAG_HIDE_TAMASDAD
	clearflag FLAG_HIDE_DEADNIGHT_TAMA
	goto SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_10:
	setflag FLAG_HIDE_DEADNIGHT_ASHII
	goto SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_9

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_12:
	setflag FLAG_HIDE_SAKU_FARMERS
	setvar VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 1
	return

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_13:
	clearflag FLAG_HIDE_SAKU_FARMERS
	return

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_15:
	compare VAR_TEMP_2, 1
	goto_if_eq SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_19
	goto SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_16:
	compare VAR_TEMP_1, 4
	goto_if_eq SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_15
	goto SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_19:
	compare VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 0
	goto_if_eq SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_12
	goto SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14

SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD:
	setflag FLAG_TEMP_1
	gettimeofday
	switch VAR_0x8000
	case TIME_DEAD_NIGHT, SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD_2
	case TIME_EARLY_MORNING, SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD_3
	case TIME_MORNING, SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD_3
	case TIME_LUNCHTIME, SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD_3
	case TIME_AFTERNOON, SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD_3
	case TIME_EVENING, SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD_3
	case TIME_NIGHT, SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD_3
SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD_3:
	end

SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	setmetatile 16, 19, METATILE_SakuKura_ClosedDoorTop, TRUE
	setmetatile 16, 20, METATILE_SakuKura_ClosedDoorBottom, TRUE
	return


SakuTown_EventScript_RivalAtSakuWall::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, SakuTown_EventScript_RivalAtSakuWall_Movement_0
	setspeaker SP_NAME_UNKNOWN
	msgbox SakuTown_EventScript_RivalAtSakuWall_Text_0
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
	clearflag FLAG_TEMP_1
	addobject 10
	compare VAR_TEMP_2, 16
	goto_if_eq SakuTown_EventScript_RivalAtSakuWall_2
	setobjectxy 10, 17, 10
SakuTown_EventScript_RivalAtSakuWall_1:
	applymovement 10, SakuTown_EventScript_RivalAtSakuWall_Movement_1
	waitmovement 0
	setspeaker SP_NAME_NATSUKI
	msgbox SakuTown_EventScript_RivalAtSakuWall_Text_1
	applymovement 10, SakuTown_EventScript_RivalAtSakuWall_Movement_2
	msgbox SakuTown_EventScript_RivalAtSakuWall_Text_2
	switch VAR_STARTER_MON
	case SPECIES_SNIVY, SakuTown_EventScript_RivalAtSakuWall_7
	case SPECIES_FROAKIE, SakuTown_EventScript_RivalAtSakuWall_8
	case SPECIES_CYNDAQUIL, SakuTown_EventScript_RivalAtSakuWall_9
SakuTown_EventScript_RivalAtSakuWall_5:
	applymovement LOCALID_NATSUKI_SAKU, SakuTown_EventScript_RivalAtSakuWall_Movement_3
	setspeaker SP_NAME_NATSUKI
	msgbox SakuTown_EventScript_RivalAtSakuWall_Text_3
	mcdialogue SakuTown_EventScript_RivalAtSakuWall_Text_4, SakuTown_EventScript_RivalAtSakuWall_Text_5
	closemessage
	switch VAR_RESULT
	case 0, SakuTown_EventScript_RivalAtSakuWall_12
	case 1, SakuTown_EventScript_RivalAtSakuWall_13
SakuTown_EventScript_RivalAtSakuWall_10:
	compare VAR_TEMP_2, 16
	goto_if_eq SakuTown_EventScript_RivalAtSakuWall_15
	applymovement 10, SakuTown_EventScript_RivalAtSakuWall_Movement_7
SakuTown_EventScript_RivalAtSakuWall_14:
	waitmovement 0
	removeobject 10
	setflag FLAG_TEMP_1
	setvar VAR_RIVAL_ENCOUNTER_STATE, 1
	release
	return

SakuTown_EventScript_RivalAtSakuWall_2:
	setobjectxy 10, 16, 10
	goto SakuTown_EventScript_RivalAtSakuWall_1

SakuTown_EventScript_RivalAtSakuWall_7:
	trainerbattle_no_intro TRAINER_RIVAL_SAKU_SNIVY, SakuTown_Text_RivalDefeat
	goto SakuTown_EventScript_RivalAtSakuWall_5

SakuTown_EventScript_RivalAtSakuWall_8:
	trainerbattle_no_intro TRAINER_RIVAL_SAKU_FROAKIE, SakuTown_Text_RivalDefeat
	goto SakuTown_EventScript_RivalAtSakuWall_5

SakuTown_EventScript_RivalAtSakuWall_9:
	trainerbattle_no_intro TRAINER_RIVAL_SAKU_CYNDAQUIL, SakuTown_Text_RivalDefeat
	goto SakuTown_EventScript_RivalAtSakuWall_5

SakuTown_EventScript_RivalAtSakuWall_12:
	applymovement LOCALID_NATSUKI_SAKU, SakuTown_EventScript_RivalAtSakuWall_Movement_4
	setspeaker SP_NAME_NATSUKI
	msgbox SakuTown_EventScript_RivalAtSakuWall_Text_6
	goto SakuTown_EventScript_RivalAtSakuWall_10

SakuTown_EventScript_RivalAtSakuWall_13:
	setspeaker SP_NAME_NATSUKI
	msgbox SakuTown_EventScript_RivalAtSakuWall_Text_7
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SakuTown_EventScript_RivalAtSakuWall_Movement_5
	waitmovement 0
	applymovement LOCALID_NATSUKI_SAKU, SakuTown_EventScript_RivalAtSakuWall_Movement_4
	setspeaker SP_NAME_NATSUKI
	msgbox SakuTown_EventScript_RivalAtSakuWall_Text_8
	closemessage
	goto SakuTown_EventScript_RivalAtSakuWall_10

SakuTown_EventScript_RivalAtSakuWall_15:
	applymovement 10, SakuTown_EventScript_RivalAtSakuWall_Movement_6
	goto SakuTown_EventScript_RivalAtSakuWall_14


SakuTown_EventScript_Farmer::
	lock
	faceplayer
	setspeaker SP_NAME_FARMER
	returnqueststate QUEST_SAKURASCYTHER
	compare VAR_RESULT, 3
	goto_if_eq SakuTown_EventScript_Farmer_2
	msgbox SakuTown_EventScript_Farmer_Text_1
SakuTown_EventScript_Farmer_1:
	release
	return

SakuTown_EventScript_Farmer_2:
	msgbox SakuTown_EventScript_Farmer_Text_0
	giveitem ITEM_CHERI_BERRY, 20
	completequest QUEST_SAKURASCYTHER
	goto SakuTown_EventScript_Farmer_1


SakuTown_EventScript_Farmer2::
	lock
	faceplayer
	applymovement VAR_LAST_TALKED, SakuTown_EventScript_Farmer2_Movement_0
	setspeaker SP_NAME_FARMER
	msgbox SakuTown_EventScript_Farmer2_Text_0
	release
	return


SakuTown_EventScript_Scyther::
	lock
	faceplayer
	setseenmon SPECIES_SCYTHER
	playmoncry SPECIES_SCYTHER, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_SCYTHER
	msgbox SakuTown_EventScript_Scyther_Text_0
	waitmoncry
	closemessage
	release
	return


SakuTown_EventScript_Woman::
	lock
	faceplayer
	applymovement VAR_LAST_TALKED, SakuTown_EventScript_Woman_Movement_0
	setspeaker SP_NAME_WOMAN
	msgbox SakuTown_EventScript_Woman_Text_0
	release
	return


SakuTown_EventScript_Karateka::
	lock
	faceplayer
	setspeaker SP_NAME_MAN
	msgbox SakuTown_EventScript_Karateka_Text_0
	closemessage
	playse SE_LEDGE
	applymovement 6, SakuTown_EventScript_Karateka_Movement_0
	waitmovement 0
	waitse
	applymovement VAR_LAST_TALKED, SakuTown_EventScript_RivalAtSakuWall_Movement_2
	setspeaker SP_NAME_MAN
	msgbox SakuTown_EventScript_Karateka_Text_1
	closemessage
	applymovement 1, Common_Movement_FaceDown
	applymovement 2, Common_Movement_FaceDown
	waitmovement 1
	waitmovement 2
	delay 24
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
	applymovement 1, SakuTown_EventScript_Karateka_Movement_1
	waitmovement 1
	waitmoncry
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
	applymovement 2, SakuTown_EventScript_Karateka_Movement_1
	waitmovement 2
	waitmoncry
	setseenmon SPECIES_MAKUHITA
	release
	return


SakuTown_EventScript_Guard::
	lock
	goto_if_set FLAG_SAKU_KURA_REUNITED, SakuTown_EventScript_Guard_2
	faceplayer
	setspeaker SP_NAME_GUARD
	msgbox SakuTown_EventScript_Guard_Text_1
	closemessage
	applymovement 8, Common_Movement_FaceOriginalDirection
	waitmovement 0
SakuTown_EventScript_Guard_1:
	release
	return

SakuTown_EventScript_Guard_2:
	setspeaker SP_NAME_GUARD
	msgbox SakuTown_EventScript_Guard_Text_0
	closemessage
	goto SakuTown_EventScript_Guard_1


SakuTown_EventScript_KuraGuard::
	lock
	setspeaker SP_NAME_GUARD
	msgbox SakuTown_EventScript_KuraGuard_Text_0
	closemessage
	release
	return


SakuTown_EventScript_GuardSeesYou::
	lock
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_SAKU_KURA_VILLAGES_STATE, 0
	goto_if_eq SakuTown_EventScript_GuardSeesYou_2
	compare VAR_SAKU_KURA_VILLAGES_STATE, 2
	goto_if_eq SakuTown_EventScript_GuardSeesYou_4
SakuTown_EventScript_GuardSeesYou_1:
	release
	return

SakuTown_EventScript_GuardSeesYou_2:
	call SakuTown_EventScript_GuardStopsYou
	goto SakuTown_EventScript_GuardSeesYou_1

SakuTown_EventScript_GuardSeesYou_3:
	call SakuTown_EventScript_GuardStopsYou
	goto SakuTown_EventScript_GuardSeesYou_1

SakuTown_EventScript_GuardSeesYou_4:
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq SakuTown_EventScript_GuardSeesYou_3
	goto SakuTown_EventScript_GuardSeesYou_1


SakuTown_EventScript_GuardStopsYou::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	applymovement 8, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 8
	setspeaker SP_NAME_GUARD
	msgbox SakuTown_EventScript_GuardStopsYou_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 20
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq SakuTown_EventScript_GuardStopsYou_2
	setspeaker SP_NAME_GUARD
	msgbox SakuTown_EventScript_GuardStopsYou_Text_2
	closemessage
	setvar VAR_SAKU_KURA_VILLAGES_STATE, 1
SakuTown_EventScript_GuardStopsYou_1:
	applymovement 8, Common_Movement_FaceDown
	return

SakuTown_EventScript_GuardStopsYou_2:
	setspeaker SP_NAME_GUARD
	msgbox SakuTown_EventScript_GuardStopsYou_Text_1
	closemessage
	setvar VAR_SAKU_KURA_VILLAGES_STATE, 3
	goto SakuTown_EventScript_GuardStopsYou_1


SakuTown_EventScript_TownSign::
	msgbox SakuTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_TrainerTips::
	msgbox SakuTown_EventScript_TrainerTips_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_TrainerTips2::
	msgbox SakuTown_EventScript_TrainerTips2_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_FloristSign::
	msgbox SakuTown_EventScript_FloristSign_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_BoardGame::
	goto_if_set FLAG_SAKU_KURA_REUNITED, SakuTown_EventScript_BoardGame_1
	return

SakuTown_EventScript_BoardGame_1:
	lock
	msgbox SakuTown_EventScript_BoardGame_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	return


SakuTown_EventScript_Mart::
	lock
	faceplayer
	setspeaker SP_NAME_SHOPKEEPER
	message SakuTown_EventScript_Mart_Text_0
	waitmessage
	pokemart SakuTown_Mart
	setspeaker SP_NAME_SHOPKEEPER
	msgbox SakuTown_EventScript_Mart_Text_1
	closemessage
	release
	return


	.align 2
SakuTown_Mart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_OINTMENT
	.2byte ITEM_REVIVAL_POWDER
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_NONE

SakuTown_EventScript_Makuhita::
	lock
	faceplayer
	waitse
	setseenmon SPECIES_MAKUHITA
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_MAKUHITA
	msgbox SakuTown_EventScript_Makuhita_Text_0
	waitmoncry
	release
	return


SakuTown_EventScript_MonHues::
	lock
	faceplayer
	setspeaker SP_NAME_MAN
	msgbox SakuTown_EventScript_MonHues_Text_0
	applymovement VAR_LAST_TALKED, SakuTown_EventScript_MonHues_Movement_0
	msgbox SakuTown_EventScript_MonHues_Text_1
	closemessage
	release
	return


SakuTown_EventScript_Cherrim::
	lock
	faceplayer
	setseenmon SPECIES_CHERRIM
	playmoncry SPECIES_CHERRIM, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_CHERRIM
	msgbox SakuTown_EventScript_Cherrim_Text_0
	waitmoncry
	release
	return


SakuTown_EventScript_TamaArgument::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, SakuTown_EventScript_TamaArgument_Movement_0
	waitmovement 0
	waitse
	setspeaker SP_NAME_UNKNOWN
	msgbox SakuTown_EventScript_TamaArgument_Text_0
	closemessage
	compare VAR_TEMP_0, 1
	goto_if_eq SakuTown_EventScript_TamaArgument_2
	applymovement OBJ_EVENT_ID_PLAYER, SakuTown_EventScript_TamaArgument_Movement_2
SakuTown_EventScript_TamaArgument_1:
	waitmovement 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SakuTown_EventScript_TamaArgument_Movement_3
	waitmovement 0
	playse SE_PIN
	applymovement 20, SakuTown_EventScript_TamaArgument_Movement_4
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_EventScript_TamaArgument_Text_1
	closemessage
	applymovement 21, SakuTown_EventScript_TamaArgument_Movement_5
	setspeaker SP_NAME_OLD_MAN
	msgbox SakuTown_EventScript_TamaArgument_Text_2
	closemessage
	playse SE_PIN
	applymovement 20, SakuTown_EventScript_TamaArgument_Movement_6
	applymovement 21, SakuTown_EventScript_TamaArgument_Movement_6
	waitmovement 20
	waitmovement 21
	delay 60
	playse SE_LEDGE
	applymovement 20, SakuTown_EventScript_Karateka_Movement_0
	waitmovement 20
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_EventScript_TamaArgument_Text_3
	waitmessage
	closemessage
	playse MUS_VS_RAYQUAZA
	delay 240
	applymovement 21, SakuTown_EventScript_TamaArgument_Movement_7
	waitmovement 21
	applymovement 21, SakuTown_EventScript_TamaArgument_Movement_8
	setspeaker SP_NAME_OLD_MAN
	msgbox SakuTown_EventScript_TamaArgument_Text_4
	closemessage
	playse MUS_DUMMY
	waitse
	applymovement 21, SakuTown_EventScript_TamaArgument_Movement_9
	applymovement OBJ_EVENT_ID_CAMERA, SakuTown_EventScript_TamaArgument_Movement_9
	waitmovement 21
	waitmovement OBJ_EVENT_ID_CAMERA
	setspeaker SP_NAME_OLD_MAN
	msgbox SakuTown_EventScript_TamaArgument_Text_5
	closemessage
	applymovement 21, SakuTown_EventScript_TamaArgument_Movement_9
	applymovement OBJ_EVENT_ID_CAMERA, SakuTown_EventScript_TamaArgument_Movement_10
	waitmovement 21
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	trainerbattle_no_intro_no_whiteout TRAINER_TAMAS_DAD, SakuTown_EventScript_TamaArgument_Text_6
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_ne SakuTown_EventScript_TamaArgument_6
SakuTown_EventScript_TamaArgument_5:
	applymovement 21, SakuTown_EventScript_TamaArgument_Movement_11
	waitmovement 21
	applymovement 21, SakuTown_EventScript_Woman_Movement_0
	setspeaker SP_NAME_TAMAS_DAD
	msgbox SakuTown_EventScript_TamaArgument_Text_8
	closemessage
	applymovement 20, SakuTown_EventScript_TamaArgument_Movement_12
	waitmovement 20
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_EventScript_TamaArgument_Text_9
	closemessage
	applymovement 21, SakuTown_EventScript_TamaArgument_Movement_13
	waitmovement 0
	applymovement 21, SakuTown_EventScript_RivalAtSakuWall_Movement_3
	setspeaker SP_NAME_TAMAS_DAD
	msgbox SakuTown_EventScript_TamaArgument_Text_10
	closemessage
	delay 60
	applymovement 21, SakuTown_EventScript_TamaArgument_Movement_14
	waitmovement 0
	delay 60
	setspeaker SP_NAME_TAMAS_DAD
	msgbox SakuTown_EventScript_TamaArgument_Text_11
	closemessage
	applymovement 21, SakuTown_EventScript_TamaArgument_Movement_15
	waitmovement 0
	removeobject 21
	applymovement 20, SakuTown_EventScript_TamaArgument_Movement_16
	applymovement OBJ_EVENT_ID_PLAYER, SakuTown_EventScript_TamaArgument_Movement_17
	waitmovement 20
	waitmovement OBJ_EVENT_ID_PLAYER
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_EventScript_TamaArgument_Text_12
	closemessage
	special HealPlayerParty
	playse SE_USE_ITEM
	setfollowernpc 20, 0
	clearflag FLAG_HIDE_DEADNIGHT_ASHII
	addobject 22
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 7
	return

SakuTown_EventScript_TamaArgument_2:
	applymovement OBJ_EVENT_ID_PLAYER, SakuTown_EventScript_TamaArgument_Movement_1
	goto SakuTown_EventScript_TamaArgument_1

SakuTown_EventScript_TamaArgument_6:
	setspeaker SP_NAME_TAMAS_DAD
	msgbox SakuTown_EventScript_TamaArgument_Text_7
	closemessage
	goto SakuTown_EventScript_TamaArgument_5


SakuTown_TopTamaTrigger::
	call SakuTown_EventScript_LoversSeeEachOther
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_TopTamaTrigger_Movement_0
	waitmovement 0
	setvar VAR_TEMP_0, 1
	call SakuTown_EventScript_LoversReunite
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_TopTamaTrigger_Movement_1
	applymovement OBJ_EVENT_ID_CAMERA, SakuTown_TopTamaTrigger_Movement_2
	applymovement OBJ_EVENT_ID_PLAYER, SakuTown_TopTamaTrigger_Movement_3
	waitmovement OBJ_EVENT_ID_NPC_FOLLOWER
	waitmovement OBJ_EVENT_ID_CAMERA
	waitmovement OBJ_EVENT_ID_PLAYER
	call SakuTown_EventScript_TamaTalksToPlayerFinal
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_TopTamaTrigger_Movement_4
	waitmovement 0
	destroyfollowernpc
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 8
	questmenu QUEST_MENU_SET_REWARD, QUEST_SAKURALOVERS
	return


SakuTown_BottomTamaTrigger::
	call SakuTown_EventScript_LoversSeeEachOther
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_BottomTamaTrigger_Movement_0
	waitmovement 0
	setvar VAR_TEMP_0, 2
	call SakuTown_EventScript_LoversReunite
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_BottomTamaTrigger_Movement_1
	applymovement OBJ_EVENT_ID_CAMERA, SakuTown_TopTamaTrigger_Movement_2
	applymovement OBJ_EVENT_ID_PLAYER, SakuTown_TopTamaTrigger_Movement_3
	waitmovement OBJ_EVENT_ID_NPC_FOLLOWER
	waitmovement OBJ_EVENT_ID_CAMERA
	waitmovement OBJ_EVENT_ID_PLAYER
	call SakuTown_EventScript_TamaTalksToPlayerFinal
	applymovement OBJ_EVENT_ID_PLAYER, SakuTown_BottomTamaTrigger_Movement_2
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_BottomTamaTrigger_Movement_3
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement OBJ_EVENT_ID_NPC_FOLLOWER
	destroyfollowernpc
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 8
	fadescreen FADE_TO_BLACK
	delay 48
	resumefakertc
	fadescreen FADE_FROM_BLACK
	questmenu QUEST_MENU_SET_REWARD, QUEST_SAKURALOVERS
	end


SakuTown_EventScript_LoversSeeEachOther::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_EventScript_LoversSeeEachOther_Movement_0
	applymovement 22, SakuTown_EventScript_RivalAtSakuWall_Movement_0
	waitmovement OBJ_EVENT_ID_NPC_FOLLOWER
	waitmovement 22
	setspeaker SP_NAME_ASHII
	msgbox SakuTown_EventScript_LoversSeeEachOther_Text_0
	closemessage
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_EventScript_LoversSeeEachOther_Text_1
	closemessage
	return


SakuTown_EventScript_LoversReunite::
	applymovement 22, SakuTown_EventScript_LoversReunite_Movement_0
	waitmovement 0
	setspeaker SP_NAME_ASHII
	msgbox SakuTown_EventScript_LoversReunite_Text_0
	special SpawnCameraObject
	switch VAR_TEMP_0
	case 1, SakuTown_EventScript_LoversReunite_3
	case 2, SakuTown_EventScript_LoversReunite_4
SakuTown_EventScript_LoversReunite_1:
	delay 60
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_EventScript_TamaArgument_Movement_5
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_EventScript_LoversReunite_Text_1
	closemessage
	applymovement 22, SakuTown_EventScript_TamaArgument_Movement_13
	setspeaker SP_NAME_ASHII
	msgbox SakuTown_EventScript_LoversReunite_Text_2
	closemessage
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, SakuTown_EventScript_TamaArgument_Movement_13
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_EventScript_TamaArgument_Movement_5
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_EventScript_LoversReunite_Text_3
	closemessage
	applymovement 22, SakuTown_EventScript_TamaArgument_Movement_13
	setspeaker SP_NAME_ASHII
	msgbox SakuTown_EventScript_LoversReunite_Text_4
	closemessage
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_EventScript_TamaArgument_Movement_5
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_EventScript_LoversReunite_Text_5
	waitmessage
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_EventScript_LoversReunite_Movement_3
	applymovement 22, SakuTown_EventScript_LoversReunite_Movement_3
	waitmovement OBJ_EVENT_ID_NPC_FOLLOWER
	waitmovement 22
	waitse
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_EventScript_TamaArgument_Movement_5
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_EventScript_LoversReunite_Text_6
	closemessage
	applymovement 22, SakuTown_EventScript_TamaArgument_Movement_13
	setspeaker SP_NAME_ASHII
	msgbox SakuTown_EventScript_LoversReunite_Text_7
	closemessage
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_EventScript_TamaArgument_Movement_5
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_EventScript_LoversReunite_Text_8
	closemessage
	applymovement 22, SakuTown_EventScript_TamaArgument_Movement_13
	setspeaker SP_NAME_ASHII
	msgbox SakuTown_EventScript_LoversReunite_Text_9
	closemessage
	delay 60
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_EventScript_LoversReunite_Movement_4
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_EventScript_LoversReunite_Text_10
	closemessage
	applymovement 22, SakuTown_EventScript_TamaArgument_Movement_13
	setspeaker SP_NAME_ASHII
	msgbox SakuTown_EventScript_LoversReunite_Text_11
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_EventScript_LoversReunite_Movement_5
	waitmovement 0
	waitse
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_EventScript_LoversReunite_Text_12
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_EventScript_LoversReunite_Movement_3
	applymovement 22, SakuTown_EventScript_LoversReunite_Movement_3
	waitmovement OBJ_EVENT_ID_NPC_FOLLOWER
	waitmovement 22
	waitse
	applymovement 22, SakuTown_EventScript_LoversReunite_Movement_6
	waitmovement 0
	removeobject 22
	setflag FLAG_HIDE_DEADNIGHT_ASHII
	return

SakuTown_EventScript_LoversReunite_3:
	applymovement OBJ_EVENT_ID_CAMERA, SakuTown_EventScript_LoversReunite_Movement_1
	waitmovement 0
	goto SakuTown_EventScript_LoversReunite_1

SakuTown_EventScript_LoversReunite_4:
	applymovement OBJ_EVENT_ID_CAMERA, SakuTown_EventScript_LoversReunite_Movement_2
	waitmovement 0
	goto SakuTown_EventScript_LoversReunite_1


SakuTown_EventScript_TamaTalksToPlayerFinal::
	special RemoveCameraObject
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_EventScript_RivalAtSakuWall_Movement_2
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_EventScript_TamaTalksToPlayerFinal_Text_0
	closemessage
	return


SakuTown_EventScript_TamaArgument_MoveDown1::
	setvar VAR_TEMP_0, 1
	goto SakuTown_EventScript_TamaArgument
	return


SakuTown_EventScript_TamaArgument_MoveDown2::
	setvar VAR_TEMP_0, 2
	goto SakuTown_EventScript_TamaArgument
	return


SakuTown_EventScript_TamasAnxious::
	faceplayer
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_EventScript_TamasAnxious_Text_0
	closemessage
	return


SakuTown_EventScript_NoLeavingAshii::
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_EventScript_NoLeavingAshii_Movement_0
	waitmovement 0
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, SakuTown_EventScript_NoLeavingAshii_Movement_1
	setspeaker SP_NAME_TAMA
	msgbox SakuTown_EventScript_NoLeavingAshii_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SakuTown_EventScript_NoLeavingAshii_Movement_2
	waitmovement 0
	return


SakuTown_EventScript_RivalAtSakuWall_Movement_0:
	emote_exclamation_mark
	step_end

SakuTown_EventScript_RivalAtSakuWall_Movement_1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SakuTown_EventScript_RivalAtSakuWall_Movement_2:
	emote_heart
	step_end

SakuTown_EventScript_RivalAtSakuWall_Movement_3:
	emote_pensive
	step_end

SakuTown_EventScript_RivalAtSakuWall_Movement_4:
	emote_happy
	step_end

SakuTown_EventScript_RivalAtSakuWall_Movement_5:
	face_up
	delay_16
	delay_16
	delay_16
	face_down
	emote_question_mark
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

SakuTown_EventScript_RivalAtSakuWall_Movement_6:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SakuTown_EventScript_RivalAtSakuWall_Movement_7:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SakuTown_EventScript_Farmer2_Movement_0:
	emote_sweat
	step_end

SakuTown_EventScript_Woman_Movement_0:
	emote_upset
	step_end

SakuTown_EventScript_Karateka_Movement_0:
	jump_in_place_up
	step_end

SakuTown_EventScript_Karateka_Movement_1:
	jump_in_place_down
	step_end

SakuTown_EventScript_MonHues_Movement_0:
	emote_music
	step_end

SakuTown_EventScript_TamaArgument_Movement_0:
	walk_in_place_fast_down
	emote_exclamation_mark
	step_end

SakuTown_EventScript_TamaArgument_Movement_1:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

SakuTown_EventScript_TamaArgument_Movement_2:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

SakuTown_EventScript_TamaArgument_Movement_3:
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

SakuTown_EventScript_TamaArgument_Movement_4:
	jump_in_place_right
	step_end

SakuTown_EventScript_TamaArgument_Movement_5:
	walk_in_place_fast_right
	step_end

SakuTown_EventScript_TamaArgument_Movement_6:
	emote_exclamation_mark
	face_up
	step_end

SakuTown_EventScript_TamaArgument_Movement_7:
	walk_in_place_fast_up
	step_end

SakuTown_EventScript_TamaArgument_Movement_8:
	emote_angry
	step_end

SakuTown_EventScript_TamaArgument_Movement_9:
	walk_slower_up
	step_end

SakuTown_EventScript_TamaArgument_Movement_10:
	walk_slow_up
	walk_slow_up
	step_end

SakuTown_EventScript_TamaArgument_Movement_11:
	walk_in_place_fast_down
	delay_16
	delay_16
	delay_16
	step_end

SakuTown_EventScript_TamaArgument_Movement_12:
	walk_up
	walk_up
	walk_in_place_fast_right
	step_end

SakuTown_EventScript_TamaArgument_Movement_13:
	walk_in_place_fast_left
	step_end

SakuTown_EventScript_TamaArgument_Movement_14:
	walk_in_place_fast_down
	step_end

SakuTown_EventScript_TamaArgument_Movement_15:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

SakuTown_EventScript_TamaArgument_Movement_16:
	walk_up
	face_player
	step_end

SakuTown_EventScript_TamaArgument_Movement_17:
	face_left
	step_end

SakuTown_TopTamaTrigger_Movement_0:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	face_right
	step_end

SakuTown_TopTamaTrigger_Movement_1:
	walk_down
	walk_left
	step_end

SakuTown_TopTamaTrigger_Movement_2:
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

SakuTown_TopTamaTrigger_Movement_3:
	face_right
	step_end

SakuTown_TopTamaTrigger_Movement_4:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

SakuTown_BottomTamaTrigger_Movement_0:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	face_right
	step_end

SakuTown_BottomTamaTrigger_Movement_1:
	walk_down
	walk_down
	walk_left
	step_end

SakuTown_BottomTamaTrigger_Movement_2:
	walk_fast_up
	face_down
	step_end

SakuTown_BottomTamaTrigger_Movement_3:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

SakuTown_EventScript_LoversSeeEachOther_Movement_0:
	face_right
	emote_exclamation_mark
	step_end

SakuTown_EventScript_LoversReunite_Movement_0:
	walk_slow_left
	walk_slow_down
	face_left
	step_end

SakuTown_EventScript_LoversReunite_Movement_1:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_up
	step_end

SakuTown_EventScript_LoversReunite_Movement_2:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_up
	walk_slow_up
	step_end

SakuTown_EventScript_LoversReunite_Movement_3:
	emote_heart
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

SakuTown_EventScript_LoversReunite_Movement_4:
	face_down
	delay_16
	delay_16
	delay_16
	face_right
	step_end

SakuTown_EventScript_LoversReunite_Movement_5:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

SakuTown_EventScript_LoversReunite_Movement_6:
	walk_slow_up
	walk_slow_right
	walk_slow_right
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

SakuTown_EventScript_NoLeavingAshii_Movement_0:
	face_player
	step_end

SakuTown_EventScript_NoLeavingAshii_Movement_1:
	emote_sad
	step_end

SakuTown_EventScript_NoLeavingAshii_Movement_2:
	walk_up
	step_end

SakuTown_EventScript_RivalAtSakuWall_Text_0:
	.string "Wait up, {PLAYER}!$"

SakuTown_EventScript_RivalAtSakuWall_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}I was wondering if you'd reached Saku\n"
	.string "Village by now. Looks like we almost\l"
	.string "missed each other!\p"
	.string "I saw several patrolling Samurai on my\n"
	.string "way here.$"

SakuTown_EventScript_RivalAtSakuWall_Text_2:
	.string "They look so cool, no wonder they're\n"
	.string "so admired!\p"
	.string "Oh, {PLAYER}, have you caught any\n"
	.string "Pokémon on your way here?\p"
	.string "Me?\n"
	.string "Boy, I'm so glad you asked…\p"
	.string "Let me show you!$"

SakuTown_EventScript_RivalAtSakuWall_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}Woah! I… I didn't think you'd go that\n"
	.string "hard, honestly!\p"
	.string "Clearly I underestimated you.\n"
	.string "That's alright.\l"
	.string "I won't make that mistake next time!\p"
	.string "I can see your Pokémon are really\n"
	.string "growing to like you, it's great!\p"
	.string "Are you doing the Dojo challenge?\n"
	.string "You might just stand a chance\l"
	.string "against the next village's Dojo!\p"
	.string "Me? Actually, I just got my first\n"
	.string "official Token!\p"
	.string "You'll have to hurry if you wanna\n"
	.string "catch up!\p"
	.string "It's fun to run into each other like\n"
	.string "this. Until next time then.\l"
	.string "I bet you I'll get to Silveridge first!\p"
	.string "See you later, Feraligatr!$"

SakuTown_EventScript_RivalAtSakuWall_Text_4:
	.string "In a while, Totodile?$"

SakuTown_EventScript_RivalAtSakuWall_Text_5:
	.string "Where's the Feraligatr?$"

SakuTown_EventScript_RivalAtSakuWall_Text_6:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}You got it!$"

SakuTown_EventScript_RivalAtSakuWall_Text_7:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}Right behind you!$"

SakuTown_EventScript_RivalAtSakuWall_Text_8:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}Bahaha! Got you!$"

SakuTown_EventScript_Farmer_Text_0:
	.string "Wielder! It's you!\n"
	.string "I can't thank ya enough for helping\l"
	.string "us heal our girl.\p"
	.string "Been doin' some thinkin' too, after\n"
	.string "you told us the one who helped 'er was\l"
	.string "from Kura.\p"
	.string "That ain't here nor there though.\n"
	.string "As thanks, ya can have these.$"

SakuTown_EventScript_Farmer_Text_1:
	.string "We're growin' Cheri berries.\n"
	.string "Saku Village exports its berries to\l"
	.string "many towns.$"

SakuTown_EventScript_Farmer2_Text_0:
	.string "Whew…\n"
	.string "Working in the fields sure is tirin'…$"

SakuTown_EventScript_Scyther_Text_0:
	.string "Gyooo!$"

SakuTown_EventScript_Woman_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_WOMAN_1 EMOTE_NORMAL}Those thugs in Kura Village may have\n"
	.string "their own Dojo, but their town is\l"
	.string "nothing but an ugly pile of rocks!\p"
	.string "They don't even have a Pokémon\n"
	.string "refuge!$"

SakuTown_EventScript_Karateka_Text_0:
	.string "I let the Toku Council borrow my\n"
	.string "super-strong Pokémon to help build\l"
	.string "the new Pokémon refuges throughout\l"
	.string "the region.$"

SakuTown_EventScript_Karateka_Text_1:
	.string "Come on, Mama, Kuku! Daddy loves you!!$"

SakuTown_EventScript_Guard_Text_0:
	.string "Damn, where did that Mareep come\n"
	.string "from?!$"

SakuTown_EventScript_Guard_Text_1:
	.string "One can never be too careful.\p"
	.string "The safety of the whole village rests\n"
	.string "on my shoulders.$"

SakuTown_EventScript_KuraGuard_Text_0:
	.string "Hah, got two of your Tauros in my\n"
	.string "herd!$"

SakuTown_EventScript_GuardStopsYou_Text_0:
	.string "Hey!$"

SakuTown_EventScript_GuardStopsYou_Text_1:
	.string "Are you trying to sneak in from Kura\n"
	.string "Village?\p"
	.string "…Oh, you're that traveler from before.\n"
	.string "You can go through.\p"
	.string "How was it? Awful, right? Welcome back\n"
	.string "to Saku Village!$"

SakuTown_EventScript_GuardStopsYou_Text_2:
	.string "Are you trying to sneak into Kura\n"
	.string "Village?\p"
	.string "…Oh, you're just a traveler.\n"
	.string "Nevermind then, you can go through.\p"
	.string "Though I wouldn't recommend visiting\n"
	.string "the next village, there's really\l"
	.string "nothing interesting there.$"

SakuTown_EventScript_TownSign_Text_0:
	.string "Saku Village\n"
	.string "“A village of tender flower petals.”$"

SakuTown_EventScript_TrainerTips_Text_0:
	.string "Did you know?\p"
	.string "Saku Village is in all ways superior to\n"
	.string "Kura Village!$"

SakuTown_EventScript_TrainerTips2_Text_0:
	.string "Did you know?\p"
	.string "The folks from Kura Village are a\n"
	.string "bunch of mean jerks!$"

SakuTown_EventScript_FloristSign_Text_0:
	.string "Humble Blossom\n"
	.string "Bonsai & flower shop$"

SakuTown_EventScript_BoardGame_Text_0:
	.string "They're playing Tauros Herder, a\n"
	.string "popular board game!$"

SakuTown_EventScript_Mart_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_CLERK EMOTE_NORMAL}Welcome to my humble shop!\n"
	.string "How can I help you?$"

SakuTown_EventScript_Mart_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_CLERK EMOTE_NORMAL}Hope to see you again!$"

SakuTown_EventScript_Makuhita_Text_0:
	.string "Kuhi!$"

SakuTown_EventScript_MonHues_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_BREEDER_M EMOTE_NORMAL}Pay close attention to the fur and\n"
	.string "feather colors of the wild Pokémon.\p"
	.string "They may all look the same at first…\n"
	.string "But each one has its own totally\l"
	.string "unique colors!$"

SakuTown_EventScript_MonHues_Text_1:
	.string "Doesn't noticing that make your heart\n"
	.string "sing?$"

SakuTown_EventScript_Cherrim_Text_0:
	.string "Weee!$"

SakuTown_EventScript_TamaArgument_Text_0:
	.string "NO! I forbid you from going!$"

SakuTown_EventScript_TamaArgument_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}The love of my life is waiting for me\n"
	.string "on the other side!\l"
	.string "You can't do this to me!$"

SakuTown_EventScript_TamaArgument_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_MAN EMOTE_NORMAL}Over my dead body will my son be in\n"
	.string "love with someone from Kura Village!$"

SakuTown_EventScript_TamaArgument_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}It's you!\n"
	.string "Help me get to Ashii, please!$"

SakuTown_EventScript_TamaArgument_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_MAN EMOTE_NORMAL}So you're the whippersnapper making\n"
	.string "my son collude with the enemy, eh.\p"
	.string "You ought to be taught a lesson in\n"
	.string "respect, kiddo!$"

SakuTown_EventScript_TamaArgument_Text_5:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_MAN EMOTE_NORMAL}{FONT_SMALL_NARROW}Huff… wheeze…$"

SakuTown_EventScript_TamaArgument_Text_6:
	.string "Dangnabit!$"

SakuTown_EventScript_TamaArgument_Text_7:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_MAN EMOTE_NORMAL}That'll teach you!!$"

SakuTown_EventScript_TamaArgument_Text_8:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_MAN EMOTE_NORMAL}{FONT_SMALL_NARROW}Huff… puff… Definitely not in as good\n"
	.string "a shape anymore…$"

SakuTown_EventScript_TamaArgument_Text_9:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}Father, I know you don't approve of\n"
	.string "us, but please understand.\p"
	.string "My mind is made up and you can't\n"
	.string "convince me otherwise.\p"
	.string "What would you have done if someone\n"
	.string "had come between you and Mother?$"

SakuTown_EventScript_TamaArgument_Text_10:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_MAN EMOTE_NORMAL}… … … … … …\n"
	.string "… … … … … …$"

SakuTown_EventScript_TamaArgument_Text_11:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_MAN EMOTE_NORMAL}If your love is as true as you say,\n"
	.string "neither I nor anyone can stop you.\p"
	.string "Do what you must… {PAUSE 48} son.$"

SakuTown_EventScript_TamaArgument_Text_12:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}I can't thank you enough.\n"
	.string "Now, let's make haste!\l"
	.string "Ashii must be waiting for us!\p"
	.string "Let me heal your Pokémon as thanks.$"

SakuTown_EventScript_LoversSeeEachOther_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}Tama!$"

SakuTown_EventScript_LoversSeeEachOther_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}Ashii!$"

SakuTown_EventScript_LoversReunite_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}… … … … … …\n"
	.string "… … … … … …$"

SakuTown_EventScript_LoversReunite_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}…Hi.$"

SakuTown_EventScript_LoversReunite_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}Hehehe… Hi.\p"
	.string "It's nice seeing you.$"

SakuTown_EventScript_LoversReunite_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}I didn't think I'd ever see you again.\p"
	.string "I… I have so much to say…$"

SakuTown_EventScript_LoversReunite_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}So do I.\n"
	.string "I felt as an insect that could do\l"
	.string "nothing but stare at the impossibly\l"
	.string "tall barricade between us.\p"
	.string "And yet… Even fierce separatism can't\n"
	.string "keep us apart.\p"
	.string "Tonight, we can have a midsummer\n"
	.string "dream of joy and mirth.$"

SakuTown_EventScript_LoversReunite_Text_5:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}You're always so poetic with your\n"
	.string "words.$"

SakuTown_EventScript_LoversReunite_Text_6:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}We can't stay here long, Ashii.\n"
	.string "My father begrundgingly let me go,\l"
	.string "but there's no telling the wrath our\l"
	.string "villages will wreak upon us if they see\l"
	.string "us here in the morning.$"

SakuTown_EventScript_LoversReunite_Text_7:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}I know. Even so, I'm glad to have\n"
	.string "spent this time with you.$"

SakuTown_EventScript_LoversReunite_Text_8:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}Will…\n"
	.string "Will we see each other again?\p"
	.string "Tomorrow?$"

SakuTown_EventScript_LoversReunite_Text_9:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}…Tomorrow and tomorrow and tomorrow…\p"
	.string "It creeps in a petty pace from day to\n"
	.string "day, but I would gladly wait a\l"
	.string "thousand of them to see you again.$"

SakuTown_EventScript_LoversReunite_Text_10:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}{FONT_SMALL_NARROW}What?$"

SakuTown_EventScript_LoversReunite_Text_11:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}Hehe…\n"
	.string "I'll see you tomorrow, my love.$"

SakuTown_EventScript_LoversReunite_Text_12:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}OH! Yes, haha!\n"
	.string "Well… See you tomorrow, then.$"

SakuTown_EventScript_TamaTalksToPlayerFinal_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}I can't believe it, it finally\n"
	.string "happened!\p"
	.string "Wielder… thank you…\n"
	.string "It's so good to see her again!$"

SakuTown_EventScript_TamasAnxious_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}My heart is about to burst out of my\n"
	.string "chest…$"

SakuTown_EventScript_NoLeavingAshii_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_1 EMOTE_NORMAL}W-where are you going?!\n"
	.string "Ashii's waiting for us!$"

SakuTown_Text_RivalDefeat::
	.string "Oh, wow!$"

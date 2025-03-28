YifuCity_Dojo_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_TRANSITION, YifuCity_Dojo_SetupNpcs
	.byte 0

YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD:
	compare VAR_YIFU_DOJO_STATE, 1
	goto_if_ge YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_2
YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	compare VAR_YIFU_DOJO_STATE, 2
	goto_if_ge YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_5
YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_4:
	compare VAR_YIFU_DOJO_STATE, 3
	goto_if_ge YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_7
	return

YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	call YifuCity_Dojo_SetDoor1Metatiles
	goto YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_1

YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_5:
	call YifuCity_Dojo_SetDoor2Metatiles
	goto YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_4

YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_7:
	call YifuCity_Dojo_SetDoor3Metatiles
	return


YifuCity_Dojo_SetupNpcs::
	compare VAR_YIFU_DOJO_STATE, 1
	goto_if_ge YifuCity_Dojo_SetupNpcs_2
YifuCity_Dojo_SetupNpcs_1:
	compare VAR_YIFU_DOJO_STATE, 2
	goto_if_ge YifuCity_Dojo_SetupNpcs_5
YifuCity_Dojo_SetupNpcs_4:
	compare VAR_YIFU_DOJO_STATE, 3
	goto_if_ge YifuCity_Dojo_SetupNpcs_7
	return

YifuCity_Dojo_SetupNpcs_2:
	setobjectxyperm 2, 15, 33
	setobjectxyperm 3, 18, 33
	removeobject 1
	goto YifuCity_Dojo_SetupNpcs_1

YifuCity_Dojo_SetupNpcs_5:
	setobjectxyperm 4, 42, 33
	setobjectxyperm 6, 45, 33
	goto YifuCity_Dojo_SetupNpcs_4

YifuCity_Dojo_SetupNpcs_7:
	setobjectxyperm 4, 42, 33
	setobjectxyperm 6, 45, 33
	return


YifuCity_Dojo_EventScript_Dance2_FromUp::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Dojo_EventScript_Dance2_FromUp_Movement_0
	waitmovement 0
	goto YifuCity_Dojo_EventScript_Dance2
	return


YifuCity_Dojo_EventScript_Dance2_FromDown::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Dojo_EventScript_Dance2_FromDown_Movement_0
	waitmovement 0
	goto YifuCity_Dojo_EventScript_Dance2
	return


YifuCity_Dojo_EventScript_Dance3_FromUp::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Dojo_EventScript_Dance3_FromUp_Movement_0
	waitmovement 0
	goto YifuCity_Dojo_EventScript_Dance3
	return


YifuCity_Dojo_EventScript_Dance3_FromDown::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Dojo_EventScript_Dance3_FromDown_Movement_0
	waitmovement 0
	goto YifuCity_Dojo_EventScript_Dance3
	return


YifuCity_Dojo_EventScript_Dance1_FromUp::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Dojo_EventScript_Dance2_FromUp_Movement_0
	waitmovement 0
	goto YifuCity_Dojo_EventScript_Dance1
	return


YifuCity_Dojo_EventScript_Dance1_FromDown::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Dojo_EventScript_Dance2_FromDown_Movement_0
	waitmovement 0
	goto YifuCity_Dojo_EventScript_Dance1
	return


YifuCity_Dojo_EventScript_Dance1::
	speakername YifuCity_Dojo_EventScript_Dance1_Text_0
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_1
	closemessage
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_0
	waitmovement 0
	call YifuCity_Dojo_Dance1
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_1
	waitmovement 0
	special RemoveCameraObject
	speakername YifuCity_Dojo_EventScript_Dance1_Text_0
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_2
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_Dojo_EventScript_Dance1_Text_3, YifuCity_Dojo_EventScript_Dance1_Text_4, YifuCity_Dojo_EventScript_Dance1_Text_5
	closemessage
	call YifuCity_Dojo_Dance1_Jump
	compare VAR_RESULT, 1
	goto_if_eq YifuCity_Dojo_EventScript_Dance1_2
	speakername YifuCity_Dojo_EventScript_Dance1_Text_0
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_7
	closemessage
	call YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle
	trainerbattle_two_trainers TRAINER_AKARI, YifuCity_Dojo_EventScript_Dance1_Text_8, TRAINER_YUKA, YifuCity_Dojo_EventScript_Dance1_Text_9
	setvar VAR_YIFU_DOJO_STATE, 1
	speakername YifuCity_Dojo_EventScript_Dance1_Text_0
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_10
	closemessage
	applymovement 2, YifuCity_Dojo_EventScript_Dance1_Movement_2
	applymovement 3, YifuCity_Dojo_EventScript_Dance1_Movement_3
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_4
	waitmovement 2
	waitmovement 3
	waitmovement OBJ_EVENT_ID_CAMERA
YifuCity_Dojo_EventScript_Dance1_1:
	delay 32
	call YifuCity_Dojo_SetDoor1Metatiles
	call YifuCity_Dojo_DoorAppears_Screenshake
	applymovement 2, Common_Movement_WalkInPlaceFasterDown
	applymovement 3, Common_Movement_WalkInPlaceFasterDown
	waitmovement 2
	waitmovement 3
	waitse
	delay 32
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_5
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	release
	return

YifuCity_Dojo_EventScript_Dance1_2:
	speakername YifuCity_Dojo_EventScript_Dance1_Text_0
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_6
	closemessage
	setvar VAR_YIFU_DOJO_STATE, 1
	call YifuCity_Dojo_Dance1_GeishasGoDirectlyToDoor
	goto YifuCity_Dojo_EventScript_Dance1_1


YifuCity_Dojo_EventScript_Dance2::
	speakername YifuCity_Dojo_EventScript_Dance1_Text_0
	msgbox YifuCity_Dojo_EventScript_Dance2_Text_0
	closemessage
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_0
	waitmovement 0
	call YifuCity_Dojo_Dance2
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_1
	waitmovement 0
	special RemoveCameraObject
	speakername YifuCity_Dojo_EventScript_Dance1_Text_0
	msgbox YifuCity_Dojo_EventScript_Dance2_Text_1
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_Dojo_EventScript_Dance2_Text_2, YifuCity_Dojo_EventScript_Dance2_Text_3, YifuCity_Dojo_EventScript_Dance2_Text_4
	closemessage
	call YifuCity_Dojo_Dance2_Jump
	compare VAR_RESULT, 0
	goto_if_eq YifuCity_Dojo_EventScript_Dance2_2
	speakername YifuCity_Dojo_EventScript_Dance1_Text_0
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_7
	closemessage
	call YifuCity_Dojo_Dance2_GeishasSurroundPlayerToBattle
	trainerbattle_two_trainers TRAINER_KARIN, YifuCity_Dojo_EventScript_Dance2_Text_5, TRAINER_MIIKA, YifuCity_Dojo_EventScript_Dance2_Text_6
	setvar VAR_YIFU_DOJO_STATE, 2
	speakername YifuCity_Dojo_EventScript_Dance1_Text_0
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_10
	closemessage
	applymovement 4, YifuCity_Dojo_EventScript_Dance1_Movement_2
	applymovement 6, YifuCity_Dojo_EventScript_Dance1_Movement_3
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_4
	waitmovement 4
	waitmovement 6
	waitmovement OBJ_EVENT_ID_CAMERA
YifuCity_Dojo_EventScript_Dance2_1:
	delay 32
	call YifuCity_Dojo_SetDoor2Metatiles
	call YifuCity_Dojo_DoorAppears_Screenshake
	applymovement 4, Common_Movement_WalkInPlaceFasterDown
	applymovement 6, Common_Movement_WalkInPlaceFasterDown
	waitmovement 4
	waitmovement 6
	waitse
	delay 32
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_5
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	release
	return

YifuCity_Dojo_EventScript_Dance2_2:
	speakername YifuCity_Dojo_EventScript_Dance1_Text_0
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_6
	closemessage
	setvar VAR_YIFU_DOJO_STATE, 2
	call YifuCity_Dojo_Dance2_GeishasGoDirectlyToDoor
	goto YifuCity_Dojo_EventScript_Dance2_1


YifuCity_Dojo_EventScript_Dance3::
	speakername YifuCity_Dojo_EventScript_Dance1_Text_0
	msgbox YifuCity_Dojo_EventScript_Dance3_Text_0
	closemessage
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_0
	waitmovement 0
	call YifuCity_Dojo_Dance3
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_1
	waitmovement 0
	special RemoveCameraObject
	speakername YifuCity_Dojo_EventScript_Dance1_Text_0
	msgbox YifuCity_Dojo_EventScript_Dance3_Text_1
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_Dojo_EventScript_Dance3_Text_2, YifuCity_Dojo_EventScript_Dance3_Text_3, YifuCity_Dojo_EventScript_Dance3_Text_4
	closemessage
	call YifuCity_Dojo_Dance3_Jump
	compare VAR_RESULT, 0
	goto_if_eq YifuCity_Dojo_EventScript_Dance3_2
	speakername YifuCity_Dojo_EventScript_Dance1_Text_0
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_7
	closemessage
	call YifuCity_Dojo_Dance3_GeishasSurroundPlayerToBattle
	trainerbattle_two_trainers TRAINER_NANAMI, YifuCity_Dojo_EventScript_Dance3_Text_6, TRAINER_KANAE, YifuCity_Dojo_EventScript_Dance3_Text_7
	setvar VAR_YIFU_DOJO_STATE, 3
	speakername YifuCity_Dojo_EventScript_Dance1_Text_0
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_10
	closemessage
	applymovement 7, YifuCity_Dojo_EventScript_Dance3_Movement_0
	applymovement 9, YifuCity_Dojo_EventScript_Dance3_Movement_1
	playse SE_LEDGE
	applymovement 8, YifuCity_Dojo_EventScript_Dance3_Movement_2
	applymovement 10, YifuCity_Dojo_EventScript_Dance3_Movement_3
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_4
	waitmovement 10
	waitmovement OBJ_EVENT_ID_CAMERA
YifuCity_Dojo_EventScript_Dance3_1:
	delay 32
	call YifuCity_Dojo_SetDoor3Metatiles
	call YifuCity_Dojo_DoorAppears_Screenshake
	applymovement 4, Common_Movement_WalkInPlaceFasterDown
	applymovement 6, Common_Movement_WalkInPlaceFasterDown
	waitmovement 4
	waitmovement 6
	waitse
	delay 32
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance3_Movement_4
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	release
	return

YifuCity_Dojo_EventScript_Dance3_2:
	speakername YifuCity_Dojo_EventScript_Dance1_Text_0
	msgbox YifuCity_Dojo_EventScript_Dance3_Text_5
	closemessage
	setvar VAR_YIFU_DOJO_STATE, 3
	call YifuCity_Dojo_Dance3_GeishasGoDirectlyToDoor
	goto YifuCity_Dojo_EventScript_Dance3_1


YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle::
	applymovement 1, Common_Movement_TeleportAway
	applymovement 2, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	applymovement 3, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	waitmovement 2
	waitmovement 3
	playse SE_LEDGE
	applymovement 2, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_1
	applymovement 3, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_2
	waitmovement 2
	waitmovement 3
	return


YifuCity_Dojo_Dance2_GeishasSurroundPlayerToBattle::
	applymovement 4, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	applymovement 6, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	waitmovement 4
	waitmovement 6
	playse SE_LEDGE
	applymovement 4, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_1
	applymovement 6, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_2
	waitmovement 4
	waitmovement 6
	return


YifuCity_Dojo_Dance3_GeishasSurroundPlayerToBattle::
	applymovement 7, YifuCity_Dojo_Dance3_GeishasSurroundPlayerToBattle_Movement_0
	applymovement 8, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	applymovement 9, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	applymovement 10, YifuCity_Dojo_Dance3_GeishasSurroundPlayerToBattle_Movement_1
	waitmovement 7
	waitmovement 8
	waitmovement 9
	waitmovement 10
	playse SE_LEDGE
	applymovement 8, YifuCity_Dojo_Dance3_GeishasSurroundPlayerToBattle_Movement_2
	applymovement 9, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_2
	waitmovement 8
	waitmovement 9
	return


YifuCity_Dojo_Dance1_GeishasGoDirectlyToDoor::
	applymovement 1, Common_Movement_TeleportAway
	applymovement 2, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	applymovement 3, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	waitmovement 2
	waitmovement 3
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_4
	playse SE_LEDGE
	applymovement 2, YifuCity_Dojo_Dance1_GeishasGoDirectlyToDoor_Movement_0
	applymovement 3, YifuCity_Dojo_Dance1_GeishasGoDirectlyToDoor_Movement_1
	waitmovement 2
	waitmovement 3
	waitmovement OBJ_EVENT_ID_CAMERA
	waitse
	return


YifuCity_Dojo_Dance2_GeishasGoDirectlyToDoor::
	applymovement 4, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	applymovement 6, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	waitmovement 4
	waitmovement 6
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_4
	playse SE_LEDGE
	applymovement 4, YifuCity_Dojo_Dance1_GeishasGoDirectlyToDoor_Movement_0
	applymovement 6, YifuCity_Dojo_Dance1_GeishasGoDirectlyToDoor_Movement_1
	waitmovement 4
	waitmovement 6
	waitmovement OBJ_EVENT_ID_CAMERA
	waitse
	return


YifuCity_Dojo_Dance3_GeishasGoDirectlyToDoor::
	applymovement 8, YifuCity_Dojo_EventScript_Dance3_Movement_0
	applymovement 9, YifuCity_Dojo_EventScript_Dance3_Movement_1
	applymovement 7, YifuCity_Dojo_Dance3_GeishasGoDirectlyToDoor_Movement_0
	applymovement 10, YifuCity_Dojo_Dance3_GeishasGoDirectlyToDoor_Movement_1
	waitmovement 7
	waitmovement 8
	waitmovement 9
	waitmovement 10
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_Dance3_GeishasGoDirectlyToDoor_Movement_2
	waitmovement OBJ_EVENT_ID_CAMERA
	waitse
	return


YifuCity_Dojo_DoorAppears_Screenshake::
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 2
	setvar VAR_0x8007, 4
	special ShakeCamera
	playse SE_UNLOCK
	return


YifuCity_Dojo_SetDoor1Metatiles::
	setmetatile 16, 31, METATILE_DojoYifu_DoorTopLeft, TRUE
	setmetatile 17, 31, METATILE_DojoYifu_DoorTopRight, TRUE
	setmetatile 16, 32, METATILE_DojoYifu_DoorBottomLeft, TRUE
	setmetatile 17, 32, METATILE_DojoYifu_DoorBottomRight, TRUE
	special DrawWholeMapView
	return


YifuCity_Dojo_SetDoor2Metatiles::
	setmetatile 43, 31, METATILE_DojoYifu_DoorTopLeft, TRUE
	setmetatile 44, 31, METATILE_DojoYifu_DoorTopRight, TRUE
	setmetatile 43, 32, METATILE_DojoYifu_DoorBottomLeft, TRUE
	setmetatile 44, 32, METATILE_DojoYifu_DoorBottomRight, TRUE
	special DrawWholeMapView
	return


YifuCity_Dojo_SetDoor3Metatiles::
	setmetatile 22, 13, METATILE_DojoYifu_PassageTopLeft, TRUE
	setmetatile 25, 13, METATILE_DojoYifu_PassageTopRight, TRUE
	setmetatile 22, 14, METATILE_DojoYifu_PassageBottomLeft, TRUE
	setmetatile 25, 14, METATILE_DojoYifu_PassageBottomRight, TRUE
	setmetatile 23, 10, METATILE_DojoYifu_WoodFloorDark, FALSE
	setmetatile 24, 10, METATILE_DojoYifu_WoodFloor, FALSE
	setmetatile 23, 11, METATILE_DojoYifu_WoodFloorDark, FALSE
	setmetatile 24, 11, METATILE_DojoYifu_WoodFloor, FALSE
	setmetatile 23, 12, METATILE_DojoYifu_WoodFloorDark, FALSE
	setmetatile 24, 12, METATILE_DojoYifu_WoodFloor, FALSE
	setmetatile 23, 13, METATILE_DojoYifu_WoodFloorDark, FALSE
	setmetatile 23, 14, METATILE_DojoYifu_WoodFloorDark, FALSE
	setmetatile 24, 13, METATILE_DojoYifu_WoodFloor, FALSE
	setmetatile 24, 14, METATILE_DojoYifu_WoodFloor, FALSE
	setmetatile 24, 15, METATILE_DojoYifu_WoodFloor, FALSE
	setmetatile 23, 18, METATILE_DojoYifu_Stairs, FALSE
	setmetatile 24, 18, METATILE_DojoYifu_Stairs, FALSE
	special DrawWholeMapView
	return


YifuCity_Dojo_Dance1_Jump::
	playse SE_BANG
	applymovement 1, YifuCity_Dojo_Movement_JumpInPlaceDown
	applymovement 2, YifuCity_Dojo_Movement_JumpInPlaceDown
	applymovement 3, YifuCity_Dojo_Movement_JumpInPlaceDown
	waitmovement 1
	waitmovement 2
	waitmovement 3
	waitse
	delay 16
	return


YifuCity_Dojo_Dance2_Jump::
	playse SE_BANG
	applymovement 4, YifuCity_Dojo_Movement_JumpInPlaceDown
	applymovement 5, YifuCity_Dojo_Movement_JumpInPlaceDown
	applymovement 6, YifuCity_Dojo_Movement_JumpInPlaceDown
	waitmovement 4
	waitmovement 5
	waitmovement 6
	waitse
	delay 16
	return


YifuCity_Dojo_Dance3_Jump::
	playse SE_BANG
	applymovement 7, YifuCity_Dojo_Movement_JumpInPlaceDown
	applymovement 8, YifuCity_Dojo_Movement_JumpInPlaceDown
	applymovement 9, YifuCity_Dojo_Movement_JumpInPlaceDown
	applymovement 10, YifuCity_Dojo_Movement_JumpInPlaceDown
	waitmovement 7
	waitmovement 8
	waitmovement 9
	waitmovement 10
	waitse
	delay 16
	return


YifuCity_Dojo_Movement_JumpInPlaceDown:
	jump_in_place_down
	step_end

YifuCity_Dojo_Dance1::
	applymovement 1, YifuCity_Dojo_Dance1_Movement_0
	applymovement 2, YifuCity_Dojo_Dance1_Movement_1
	applymovement 3, YifuCity_Dojo_Dance1_Movement_2
	waitmovement 1
	waitmovement 2
	waitmovement 3
	return


YifuCity_Dojo_Dance2::
	return


YifuCity_Dojo_Dance3::
	return


YifuCity_Dojo_EventScript_Advice::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, YifuCity_Dojo_EventScript_Advice_2
	msgbox YifuCity_Dojo_EventScript_Advice_Text_1
YifuCity_Dojo_EventScript_Advice_1:
	release
	return

YifuCity_Dojo_EventScript_Advice_2:
	msgbox YifuCity_Dojo_EventScript_Advice_Text_0
	goto YifuCity_Dojo_EventScript_Advice_1


YifuCity_Dojo_EventScript_DojoStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, YifuCity_Dojo_EventScript_DojoStatue_2
	msgbox YifuCity_Dojo_EventScript_DojoStatue_Text_1, MSGBOX_SIGN
YifuCity_Dojo_EventScript_DojoStatue_1:
	releaseall
	return

YifuCity_Dojo_EventScript_DojoStatue_2:
	msgbox YifuCity_Dojo_EventScript_DojoStatue_Text_0, MSGBOX_SIGN
	goto YifuCity_Dojo_EventScript_DojoStatue_1


YifuCity_Dojo_EventScript_Akari::
	trainerbattle_single TRAINER_AKARI, YifuCity_Dojo_EventScript_Akari_Text_0, YifuCity_Dojo_EventScript_Dance1_Text_8
	speakername YifuCity_Dojo_EventScript_Akari_Text_1
	msgbox YifuCity_Dojo_EventScript_Akari_Text_2, MSGBOX_AUTOCLOSE
	end


YifuCity_Dojo_EventScript_Yuka::
	trainerbattle_single TRAINER_YUKA, YifuCity_Dojo_EventScript_Yuka_Text_0, YifuCity_Dojo_EventScript_Yuka_Text_1
	speakername YifuCity_Dojo_EventScript_Yuka_Text_2
	msgbox YifuCity_Dojo_EventScript_Yuka_Text_3, MSGBOX_AUTOCLOSE
	end


YifuCity_Dojo_EventScript_Nanami::
	trainerbattle_single TRAINER_NANAMI, YifuCity_Dojo_EventScript_Nanami_Text_0, YifuCity_Dojo_EventScript_Dance3_Text_6
	speakername YifuCity_Dojo_EventScript_Nanami_Text_1
	msgbox YifuCity_Dojo_EventScript_Nanami_Text_2, MSGBOX_AUTOCLOSE
	end


YifuCity_Dojo_EventScript_Kanae::
	trainerbattle_single TRAINER_KANAE, YifuCity_Dojo_EventScript_Dance3_Text_7, YifuCity_Dojo_EventScript_Kanae_Text_0
	speakername YifuCity_Dojo_EventScript_Kanae_Text_1
	msgbox YifuCity_Dojo_EventScript_Kanae_Text_2, MSGBOX_AUTOCLOSE
	end


YifuCity_Dojo_EventScript_Karin::
	trainerbattle_single TRAINER_KARIN, YifuCity_Dojo_EventScript_Karin_Text_0, YifuCity_Dojo_EventScript_Karin_Text_1
	speakername YifuCity_Dojo_EventScript_Karin_Text_2
	msgbox YifuCity_Dojo_EventScript_Karin_Text_3, MSGBOX_AUTOCLOSE
	end


YifuCity_Dojo_EventScript_Miika::
	trainerbattle_single TRAINER_MIIKA, YifuCity_Dojo_EventScript_Miika_Text_0, YifuCity_Dojo_EventScript_Miika_Text_1
	speakername YifuCity_Dojo_EventScript_Miika_Text_2
	msgbox YifuCity_Dojo_EventScript_Miika_Text_3, MSGBOX_AUTOCLOSE
	end


YifuCity_Dojo_EventScript_Dancer::
	lock
	faceplayer
	speakername YifuCity_Dojo_EventScript_Dancer_Text_0
	msgbox YifuCity_Dojo_EventScript_Dancer_Text_1
	release
	return


YifuCity_Dojo_EventScript_Dancer2::
	lock
	faceplayer
	speakername YifuCity_Dojo_EventScript_Dancer_Text_0
	msgbox YifuCity_Dojo_EventScript_Dancer2_Text_0
	release
	return


YifuCity_Dojo_EventScript_ImpossibleDancer::
	lock
	faceplayer
	speakername YifuCity_Dojo_EventScript_Dancer_Text_0
	msgbox YifuCity_Dojo_EventScript_ImpossibleDancer_Text_0
	release
	return


YifuCity_Dojo_EventScript_Yutaka::
	lock
	faceplayer
	speakername YifuCity_Dojo_EventScript_Yutaka_Text_0
	msgbox YifuCity_Dojo_EventScript_Yutaka_Text_1
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	waitse
	delay 48
	trainerbattle_single TRAINER_YUTAKA_1, YifuCity_Dojo_EventScript_Yutaka_Text_2, YifuCity_Dojo_EventScript_Yutaka_Text_3, YifuCity_Dojo_EventScript_YutakaDefeated, NO_MUSIC
	msgbox YifuCity_Dojo_EventScript_Yutaka_Text_4
	release
	end


YifuCity_Dojo_EventScript_YutakaDefeated::
	message YifuCity_Dojo_EventScript_YutakaDefeated_Text_0
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	speakername YifuCity_Dojo_EventScript_Yutaka_Text_0
	msgbox YifuCity_Dojo_EventScript_YutakaDefeated_Text_1, MSGBOX_DEFAULT
	giveitem ITEM_TM_X_SCISSOR
	speakername YifuCity_Dojo_EventScript_Yutaka_Text_0
	msgbox YifuCity_Dojo_EventScript_YutakaDefeated_Text_2
	closemessage
	setflag FLAG_BADGE03_GET
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	addvar VAR_PLAYER_REPUTATION, 5
	release
	end


YifuCity_Dojo_EventScript_Dance2_FromUp_Movement_0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	delay_16
	step_end

YifuCity_Dojo_EventScript_Dance2_FromDown_Movement_0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	delay_16
	step_end

YifuCity_Dojo_EventScript_Dance3_FromUp_Movement_0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	delay_16
	step_end

YifuCity_Dojo_EventScript_Dance3_FromDown_Movement_0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	delay_16
	step_end

YifuCity_Dojo_EventScript_Dance1_Movement_0:
	walk_up
	walk_up
	delay_16
	delay_16
	step_end

YifuCity_Dojo_EventScript_Dance1_Movement_1:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

YifuCity_Dojo_EventScript_Dance1_Movement_2:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	face_right
	step_end

YifuCity_Dojo_EventScript_Dance1_Movement_3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_left
	step_end

YifuCity_Dojo_EventScript_Dance1_Movement_4:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

YifuCity_Dojo_EventScript_Dance1_Movement_5:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

YifuCity_Dojo_EventScript_Dance3_Movement_0:
	walk_up
	face_right
	step_end

YifuCity_Dojo_EventScript_Dance3_Movement_1:
	walk_up
	face_left
	step_end

YifuCity_Dojo_EventScript_Dance3_Movement_2:
	jump_2_up
	delay_16
	walk_right
	walk_up
	face_left
	step_end

YifuCity_Dojo_EventScript_Dance3_Movement_3:
	jump_2_up
	delay_16
	walk_up
	face_right
	step_end

YifuCity_Dojo_EventScript_Dance3_Movement_4:
	walk_down
	walk_down
	step_end

YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0:
	walk_down
	step_end

YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_1:
	jump_2_down
	delay_16
	walk_right
	step_end

YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_2:
	jump_2_down
	delay_16
	walk_left
	step_end

YifuCity_Dojo_Dance3_GeishasSurroundPlayerToBattle_Movement_0:
	walk_right
	walk_right
	face_down
	step_end

YifuCity_Dojo_Dance3_GeishasSurroundPlayerToBattle_Movement_1:
	walk_left
	walk_left
	face_down
	step_end

YifuCity_Dojo_Dance3_GeishasSurroundPlayerToBattle_Movement_2:
	jump_2_down
	delay_16
	face_right
	step_end

YifuCity_Dojo_Dance1_GeishasGoDirectlyToDoor_Movement_0:
	jump_2_down
	delay_16
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	face_right
	step_end

YifuCity_Dojo_Dance1_GeishasGoDirectlyToDoor_Movement_1:
	jump_2_down
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_left
	step_end

YifuCity_Dojo_Dance3_GeishasGoDirectlyToDoor_Movement_0:
	walk_right
	walk_right
	step_end

YifuCity_Dojo_Dance3_GeishasGoDirectlyToDoor_Movement_1:
	walk_left
	walk_left
	step_end

YifuCity_Dojo_Dance3_GeishasGoDirectlyToDoor_Movement_2:
	walk_up
	walk_up
	step_end

YifuCity_Dojo_Dance1_Movement_0:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_left
	jump_2_left
	walk_left
	walk_down
	walk_right
	walk_right
	walk_up
	face_down
	step_end

YifuCity_Dojo_Dance1_Movement_1:
	walk_left
	walk_left
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

YifuCity_Dojo_Dance1_Movement_2:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_up
	face_down
	step_end

YifuCity_Dojo_EventScript_Dance1_Text_0:
	.string "Kimono girls$"

YifuCity_Dojo_EventScript_Dance1_Text_1:
	.string "Welcome to the Yifu City Dojo.\n"
	.string "Here you will have the pleasure\l"
	.string "to watch three different dances,\l"
	.string "at the end of which you will be\l"
	.string "asked a different question.\p"
	.string "The first dance will soon commence!\n"
	.string "The real Miss Yutaka, the Dojo\l"
	.string "Master, is among us.\p"
	.string "She is the one on the left.\n"
	.string "If you haven't lost track of her\l"
	.string "by the end of our dance, we\l"
	.string "shall let you through.\p"
	.string "If you guess wrong, you shall have\n"
	.string "to battle us.\p"
	.string "Are you ready?$"

YifuCity_Dojo_EventScript_Dance1_Text_2:
	.string "Well? Can you remember which one\n"
	.string "is the real Yutaka?$"

YifuCity_Dojo_EventScript_Dance1_Text_3:
	.string "The left one.$"

YifuCity_Dojo_EventScript_Dance1_Text_4:
	.string "The middle one.$"

YifuCity_Dojo_EventScript_Dance1_Text_5:
	.string "The right one.$"

YifuCity_Dojo_EventScript_Dance1_Text_6:
	.string "You are correct!\p"
	.string "Very well. You may proceed to the\n"
	.string "next room.$"

YifuCity_Dojo_EventScript_Dance1_Text_7:
	.string "You are incorrect!\p"
	.string "We shall face you in battle before\n"
	.string "you proceed.$"

YifuCity_Dojo_EventScript_Dance1_Text_8:
	.string "Oh!$"

YifuCity_Dojo_EventScript_Dance1_Text_9:
	.string "I see.$"

YifuCity_Dojo_EventScript_Dance1_Text_10:
	.string "Very well! You may now proceed.$"

YifuCity_Dojo_EventScript_Dance2_Text_0:
	.string "Are you ready for a second dance?\n"
	.string "Follow each of our moves…$"

YifuCity_Dojo_EventScript_Dance2_Text_1:
	.string "Do you remember where the dancer\n"
	.string "on the right was placed originally?$"

YifuCity_Dojo_EventScript_Dance2_Text_2:
	.string "She was on the left.$"

YifuCity_Dojo_EventScript_Dance2_Text_3:
	.string "She was in the middle.$"

YifuCity_Dojo_EventScript_Dance2_Text_4:
	.string "She was on the right.$"

YifuCity_Dojo_EventScript_Dance2_Text_5:
	.string "I liked the dancing part better…$"

YifuCity_Dojo_EventScript_Dance2_Text_6:
	.string "Oh, well.$"

YifuCity_Dojo_EventScript_Dance3_Text_0:
	.string "Let the third dance begin! Pay\n"
	.string "close attention…$"

YifuCity_Dojo_EventScript_Dance3_Text_1:
	.string "Can you tell us how many jumps\n"
	.string "there were in this dance?$"

YifuCity_Dojo_EventScript_Dance3_Text_2:
	.string "Eight.$"

YifuCity_Dojo_EventScript_Dance3_Text_3:
	.string "Ten.$"

YifuCity_Dojo_EventScript_Dance3_Text_4:
	.string "Twelve.$"

YifuCity_Dojo_EventScript_Dance3_Text_5:
	.string "You are correct!\p"
	.string "Very well. You may proceed to the\n"
	.string "last room.$"

YifuCity_Dojo_EventScript_Dance3_Text_6:
	.string "Pant… Hey, let me catch my breath!$"

YifuCity_Dojo_EventScript_Dance3_Text_7:
	.string "You didn't see me trip over my own\n"
	.string "foot, did you?$"

YifuCity_Dojo_EventScript_Advice_Text_0:
	.string "Such grace! Such swiftness! I am\n"
	.string "wowed!\p"
	.string "{PLAYER}… That's a name to be\n"
	.string "remembered!$"

YifuCity_Dojo_EventScript_Advice_Text_1:
	.string "Hello, young challenger, and\n"
	.string "welcome to the Dance Hall Dojo!\l"
	.string "Think you've got what it takes to\l"
	.string "see through the dancer's\l"
	.string "intoxicating moves?\p"
	.string "Watch out though, Master Yutaka\n"
	.string "can be as critical as she is\l"
	.string "beautiful.\l"
	.string "She probably won't appreciate you\l"
	.string "walking around her Dojo with your\l"
	.string "clothes looking like… this…\p"
	.string "Uh, nevermind my babbling! Go get\n"
	.string "'em, champ!$"

YifuCity_Dojo_EventScript_DojoStatue_Text_0:
	.string "Dojo of Yifu City\p"
	.string "Certified wielders:\n"
	.string "Natsuki,\l"
	.string "{PLAYER}$"

YifuCity_Dojo_EventScript_DojoStatue_Text_1:
	.string "Dojo of Kura Village\p"
	.string "Certified wielders:\n"
	.string "Natsuki$"

YifuCity_Dojo_EventScript_Akari_Text_0:
	.string "You still wish to fight? Very well!$"

YifuCity_Dojo_EventScript_Akari_Text_1:
	.string "Akari$"

YifuCity_Dojo_EventScript_Akari_Text_2:
	.string "You are very graceful. Are you\n"
	.string "sure you're not a dancer?$"

YifuCity_Dojo_EventScript_Yuka_Text_0:
	.string "You have a good eye! Let's see if\n"
	.string "that applies to Pokémon, as well!$"

YifuCity_Dojo_EventScript_Yuka_Text_1:
	.string "You have many talents, I see!$"

YifuCity_Dojo_EventScript_Yuka_Text_2:
	.string "Yuka$"

YifuCity_Dojo_EventScript_Yuka_Text_3:
	.string "The next dance should be more of a\n"
	.string "challenge.$"

YifuCity_Dojo_EventScript_Nanami_Text_0:
	.string "Pant… I'm impressed… Pant… This last\n"
	.string "dance was… intense!$"

YifuCity_Dojo_EventScript_Nanami_Text_1:
	.string "Nanami$"

YifuCity_Dojo_EventScript_Nanami_Text_2:
	.string "I really need to exercise more…$"

YifuCity_Dojo_EventScript_Kanae_Text_0:
	.string "My dance wasn't perfect! I deserve\n"
	.string "this!$"

YifuCity_Dojo_EventScript_Kanae_Text_1:
	.string "Kanae$"

YifuCity_Dojo_EventScript_Kanae_Text_2:
	.string "Next time my dance will be perfect,\n"
	.string "you'll see!$"

YifuCity_Dojo_EventScript_Karin_Text_0:
	.string "Oh good! A battle! I was getting\n"
	.string "bored.$"

YifuCity_Dojo_EventScript_Karin_Text_1:
	.string "I am regretting this…$"

YifuCity_Dojo_EventScript_Karin_Text_2:
	.string "Karin$"

YifuCity_Dojo_EventScript_Karin_Text_3:
	.string "Miss Yutaka holds us to the highest\n"
	.string "standards, both in battle and\l"
	.string "onstage!$"

YifuCity_Dojo_EventScript_Miika_Text_0:
	.string "Please admire my brand-new designer\n"
	.string "kimono!$"

YifuCity_Dojo_EventScript_Miika_Text_1:
	.string "You don't look impressed at all!$"

YifuCity_Dojo_EventScript_Miika_Text_2:
	.string "Miika$"

YifuCity_Dojo_EventScript_Miika_Text_3:
	.string "Working here has its perks.\n"
	.string "We get the finest silk clothes for\l"
	.string "free!$"

YifuCity_Dojo_EventScript_Dancer_Text_0:
	.string "Kimono girl$"

YifuCity_Dojo_EventScript_Dancer_Text_1:
	.string "I have no Pokémon! I'm only a\n"
	.string "dancer.$"

YifuCity_Dojo_EventScript_Dancer2_Text_0:
	.string "Come back to watch us dance\n"
	.string "sometimes!$"

YifuCity_Dojo_EventScript_ImpossibleDancer_Text_0:
	.string "Hey! How did you get up here?!$"

YifuCity_Dojo_EventScript_Yutaka_Text_0:
	.string "Yutaka$"

YifuCity_Dojo_EventScript_Yutaka_Text_1:
	.string "Well done! Welcome to Yifu City's\n"
	.string "Doj-$"

YifuCity_Dojo_EventScript_Yutaka_Text_2:
	.string "Excuse me, what is this?\p"
	.string "Is there a reason for the\n"
	.string "accoutrement you're donning?\l"
	.string "A carnival, perhaps?\l"
	.string "Or have you lost a bet?\p"
	.string "Or do you simply lack a basic\n"
	.string "sense of style to such an\l"
	.string "extreme degree?\p"
	.string "Here you are, parading around\n"
	.string "in your peasant's clothes…\p"
	.string "(…Yutaka, you must not let this\n"
	.string "offend you so!\l"
	.string "You are stronger than that!)\p"
	.string "Ahem… Let us move on…\n"
	.string "You shall be fighting my exquisite\l"
	.string "assortment of Pokémon,\l"
	.string "in the hopes of obtaining\l"
	.string "an official Token from me.\p"
	.string "Please try not to be too\n"
	.string "overwhelmed by my strength and,\l"
	.string "most of all, by my impeccable\l"
	.string "sense of fashion.\p"
	.string "Let this battle begin!$"

YifuCity_Dojo_EventScript_Yutaka_Text_3:
	.string "How dare you!$"

YifuCity_Dojo_EventScript_Yutaka_Text_4:
	.string "You shall achieve great things. I\n"
	.string "hope we meet again.$"

YifuCity_Dojo_EventScript_YutakaDefeated_Text_0:
	.string "{PLAYER} received the Silk Token\n"
	.string "from Yutaka.$"

YifuCity_Dojo_EventScript_YutakaDefeated_Text_1:
	.string "I am outrée! Your techniques are\n"
	.string "rough and vulgar, yet…\l"
	.string "Victory is yours…\n"
	.string "That is undeniable.\p"
	.string "I guess what you lack in aesthetic\n"
	.string "values, you compensate in\l"
	.string "strength.\p"
	.string "Do accept this, as well.$"

YifuCity_Dojo_EventScript_YutakaDefeated_Text_2:
	.string "This scroll contains my famous\n"
	.string "X-Scissor technique.\p"
	.string "I perfected it back when I worked\n"
	.string "as a seamstress.\p"
	.string "About that, uh… We should go\n"
	.string "clothes-shopping together\l"
	.string "sometime.\p"
	.string "I cannot bear to see your image\n"
	.string "suffer so.$"

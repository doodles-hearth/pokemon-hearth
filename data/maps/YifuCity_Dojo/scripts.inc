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
	goto_if_ge YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_8
YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_7:
	goto_if_set FLAG_BADGE03_GET, YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_10
	return

YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	call YifuCity_Dojo_SetDoor1Metatiles
	goto YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_1

YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_5:
	call YifuCity_Dojo_SetDoor2Metatiles
	goto YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_4

YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_8:
	call YifuCity_Dojo_SetDoor3Metatiles
	goto YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_7

YifuCity_Dojo_MapScripts_MAP_SCRIPT_ON_LOAD_10:
	call YifuCity_Dojo_SetShortcutMetatiles
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
	setobjectxyperm LOCALID_YIFU_GEISHA_2, 15, 33
	setobjectxyperm LOCALID_YIFU_GEISHA_3, 18, 33
	removeobject LOCALID_YIFU_GEISHA_1
	goto YifuCity_Dojo_SetupNpcs_1

YifuCity_Dojo_SetupNpcs_5:
	setobjectxyperm LOCALID_YIFU_GEISHA_4, 42, 33
	setobjectxyperm LOCALID_YIFU_GEISHA_6, 45, 33
	goto YifuCity_Dojo_SetupNpcs_4

YifuCity_Dojo_SetupNpcs_7:
	setobjectxyperm LOCALID_YIFU_GEISHA_4, 42, 33
	setobjectxyperm LOCALID_YIFU_GEISHA_6, 45, 33
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
	setspeaker SP_NAME_KIMONO_GIRLS
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_0
	closemessage
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_0
	waitmovement 0
	call YifuCity_Dojo_Dance1
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_1
	waitmovement 0
	special RemoveCameraObject
	setspeaker SP_NAME_KIMONO_GIRLS
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_1
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_Dojo_EventScript_Dance1_Text_2, YifuCity_Dojo_EventScript_Dance1_Text_3, YifuCity_Dojo_EventScript_Dance1_Text_4
	closemessage
	call YifuCity_Dojo_Dance1_Jump
	compare VAR_RESULT, 1
	goto_if_eq YifuCity_Dojo_EventScript_Dance1_2
	playse SE_FAILURE
	setspeaker SP_NAME_KIMONO_GIRLS
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_6
	closemessage
	call YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle
	trainerbattle_two_trainers TRAINER_AKARI, YifuCity_Dojo_EventScript_Dance1_Text_7, TRAINER_YUKA, YifuCity_Dojo_EventScript_Dance1_Text_8
	setvar VAR_YIFU_DOJO_STATE, 1
	setspeaker SP_NAME_KIMONO_GIRLS
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_9
	closemessage
	applymovement LOCALID_YIFU_GEISHA_2, YifuCity_Dojo_EventScript_Dance1_Movement_2
	applymovement LOCALID_YIFU_GEISHA_3, YifuCity_Dojo_EventScript_Dance1_Movement_3
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_4
	waitmovement LOCALID_YIFU_GEISHA_2
	waitmovement LOCALID_YIFU_GEISHA_3
	waitmovement OBJ_EVENT_ID_CAMERA
YifuCity_Dojo_EventScript_Dance1_1:
	delay 32
	call YifuCity_Dojo_SetDoor1Metatiles
	call YifuCity_Dojo_DoorAppears_Screenshake
	applymovement LOCALID_YIFU_GEISHA_2, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_YIFU_GEISHA_3, Common_Movement_WalkInPlaceFasterDown
	waitmovement LOCALID_YIFU_GEISHA_2
	waitmovement LOCALID_YIFU_GEISHA_3
	waitse
	delay 32
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_5
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	release
	return

YifuCity_Dojo_EventScript_Dance1_2:
	playse SE_SUCCESS
	setspeaker SP_NAME_KIMONO_GIRLS
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_5
	closemessage
	setvar VAR_YIFU_DOJO_STATE, 1
	call YifuCity_Dojo_Dance1_GeishasGoDirectlyToDoor
	goto YifuCity_Dojo_EventScript_Dance1_1


YifuCity_Dojo_EventScript_Dance2::
	setspeaker SP_NAME_KIMONO_GIRLS
	msgbox YifuCity_Dojo_EventScript_Dance2_Text_0
	closemessage
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_0
	waitmovement 0
	call YifuCity_Dojo_Dance2
	delay 48
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_1
	waitmovement 0
	special RemoveCameraObject
	setspeaker SP_NAME_KIMONO_GIRLS
	msgbox YifuCity_Dojo_EventScript_Dance2_Text_1
	mcdialogue YifuCity_Dojo_EventScript_Dance2_Text_2, YifuCity_Dojo_EventScript_Dance2_Text_3, YifuCity_Dojo_EventScript_Dance2_Text_4
	closemessage
	call YifuCity_Dojo_Dance2_Jump
	compare VAR_RESULT, 2
	goto_if_eq YifuCity_Dojo_EventScript_Dance2_2
	playse SE_FAILURE
	setspeaker SP_NAME_KIMONO_GIRLS
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_6
	closemessage
	call YifuCity_Dojo_Dance2_GeishasSurroundPlayerToBattle
	trainerbattle_two_trainers TRAINER_KARIN, YifuCity_Dojo_EventScript_Dance2_Text_5, TRAINER_MIIKA, YifuCity_Dojo_EventScript_Dance2_Text_6
	setvar VAR_YIFU_DOJO_STATE, 2
	setspeaker SP_NAME_KIMONO_GIRLS
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_9
	closemessage
	applymovement LOCALID_YIFU_GEISHA_5, YifuCity_Dojo_EventScript_Dance1_Movement_2
	applymovement LOCALID_YIFU_GEISHA_6, YifuCity_Dojo_EventScript_Dance1_Movement_3
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_4
	waitmovement LOCALID_YIFU_GEISHA_5
	waitmovement LOCALID_YIFU_GEISHA_6
	waitmovement OBJ_EVENT_ID_CAMERA
YifuCity_Dojo_EventScript_Dance2_1:
	delay 32
	call YifuCity_Dojo_SetDoor2Metatiles
	call YifuCity_Dojo_DoorAppears_Screenshake
	applymovement LOCALID_YIFU_GEISHA_5, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_YIFU_GEISHA_6, Common_Movement_WalkInPlaceFasterDown
	waitmovement LOCALID_YIFU_GEISHA_5
	waitmovement LOCALID_YIFU_GEISHA_6
	waitse
	delay 32
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_5
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	release
	return

YifuCity_Dojo_EventScript_Dance2_2:
	playse SE_SUCCESS
	setspeaker SP_NAME_KIMONO_GIRLS
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_5
	closemessage
	setvar VAR_YIFU_DOJO_STATE, 2
	call YifuCity_Dojo_Dance2_GeishasGoDirectlyToDoor
	goto YifuCity_Dojo_EventScript_Dance2_1


YifuCity_Dojo_EventScript_Dance3::
	setspeaker SP_NAME_KIMONO_GIRLS
	msgbox YifuCity_Dojo_EventScript_Dance3_Text_0
	closemessage
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_0
	waitmovement 0
	call YifuCity_Dojo_Dance3
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_1
	waitmovement 0
	special RemoveCameraObject
	setspeaker SP_NAME_KIMONO_GIRLS
	msgbox YifuCity_Dojo_EventScript_Dance3_Text_1
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_Dojo_EventScript_Dance3_Text_2, YifuCity_Dojo_EventScript_Dance3_Text_3, YifuCity_Dojo_EventScript_Dance3_Text_4
	closemessage
	call YifuCity_Dojo_Dance3_Jump
	compare VAR_RESULT, 0
	goto_if_eq YifuCity_Dojo_EventScript_Dance3_2
	playse SE_FAILURE
	setspeaker SP_NAME_KIMONO_GIRLS
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_6
	closemessage
	call YifuCity_Dojo_Dance3_GeishasSurroundPlayerToBattle
	trainerbattle_two_trainers TRAINER_NANAMI, YifuCity_Dojo_EventScript_Dance3_Text_6, TRAINER_KANAE, YifuCity_Dojo_EventScript_Dance3_Text_7
	setvar VAR_YIFU_DOJO_STATE, 3
	setspeaker SP_NAME_KIMONO_GIRLS
	msgbox YifuCity_Dojo_EventScript_Dance1_Text_9
	closemessage
	applymovement LOCALID_YIFU_GEISHA_7, YifuCity_Dojo_EventScript_Dance3_Movement_0
	applymovement LOCALID_YIFU_GEISHA_10, YifuCity_Dojo_EventScript_Dance3_Movement_1
	playse SE_LEDGE
	applymovement LOCALID_YIFU_GEISHA_9, YifuCity_Dojo_EventScript_Dance3_Movement_2
	applymovement LOCALID_YIFU_GEISHA_8, YifuCity_Dojo_EventScript_Dance3_Movement_3
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance3_Movement_4
	waitmovement LOCALID_YIFU_GEISHA_10
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance3_Movement_5
	waitmovement OBJ_EVENT_ID_CAMERA
YifuCity_Dojo_EventScript_Dance3_1:
	delay 32
	call YifuCity_Dojo_SetDoor3Metatiles
	call YifuCity_Dojo_DoorAppears_Screenshake
	applymovement LOCALID_YIFU_GEISHA_4, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_YIFU_GEISHA_6, Common_Movement_WalkInPlaceFasterDown
	waitmovement LOCALID_YIFU_GEISHA_4
	waitmovement LOCALID_YIFU_GEISHA_6
	waitse
	delay 32
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance3_Movement_5
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	release
	return

YifuCity_Dojo_EventScript_Dance3_2:
	playse SE_SUCCESS
	setspeaker SP_NAME_KIMONO_GIRLS
	msgbox YifuCity_Dojo_EventScript_Dance3_Text_5
	closemessage
	setvar VAR_YIFU_DOJO_STATE, 3
	call YifuCity_Dojo_Dance3_GeishasGoDirectlyToDoor
	goto YifuCity_Dojo_EventScript_Dance3_1


YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle::
	applymovement LOCALID_YIFU_GEISHA_1, Common_Movement_TeleportAway
	applymovement LOCALID_YIFU_GEISHA_2, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	applymovement LOCALID_YIFU_GEISHA_3, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	waitmovement LOCALID_YIFU_GEISHA_2
	waitmovement LOCALID_YIFU_GEISHA_3
	playse SE_LEDGE
	applymovement LOCALID_YIFU_GEISHA_2, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_1
	applymovement LOCALID_YIFU_GEISHA_3, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_2
	waitmovement LOCALID_YIFU_GEISHA_2
	waitmovement LOCALID_YIFU_GEISHA_3
	return


YifuCity_Dojo_Dance2_GeishasSurroundPlayerToBattle::
	applymovement LOCALID_YIFU_GEISHA_5, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	applymovement LOCALID_YIFU_GEISHA_6, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	waitmovement LOCALID_YIFU_GEISHA_5
	waitmovement LOCALID_YIFU_GEISHA_6
	playse SE_LEDGE
	applymovement LOCALID_YIFU_GEISHA_5, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_1
	applymovement LOCALID_YIFU_GEISHA_6, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_2
	waitmovement LOCALID_YIFU_GEISHA_5
	waitmovement LOCALID_YIFU_GEISHA_6
	return


YifuCity_Dojo_Dance3_GeishasSurroundPlayerToBattle::
	applymovement LOCALID_YIFU_GEISHA_7, YifuCity_Dojo_Dance3_GeishasSurroundPlayerToBattle_Movement_0
	applymovement LOCALID_YIFU_GEISHA_8, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	applymovement LOCALID_YIFU_GEISHA_9, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	applymovement LOCALID_YIFU_GEISHA_10, YifuCity_Dojo_Dance3_GeishasSurroundPlayerToBattle_Movement_1
	waitmovement LOCALID_YIFU_GEISHA_7
	waitmovement LOCALID_YIFU_GEISHA_8
	waitmovement LOCALID_YIFU_GEISHA_9
	waitmovement LOCALID_YIFU_GEISHA_10
	playse SE_LEDGE
	applymovement LOCALID_YIFU_GEISHA_8, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_2
	applymovement LOCALID_YIFU_GEISHA_9, YifuCity_Dojo_Dance3_GeishasSurroundPlayerToBattle_Movement_2
	waitmovement LOCALID_YIFU_GEISHA_8
	waitmovement LOCALID_YIFU_GEISHA_9
	return


YifuCity_Dojo_Dance1_GeishasGoDirectlyToDoor::
	applymovement LOCALID_YIFU_GEISHA_1, Common_Movement_TeleportAway
	applymovement LOCALID_YIFU_GEISHA_2, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	applymovement LOCALID_YIFU_GEISHA_3, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	waitmovement LOCALID_YIFU_GEISHA_2
	waitmovement LOCALID_YIFU_GEISHA_3
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_4
	playse SE_LEDGE
	applymovement LOCALID_YIFU_GEISHA_2, YifuCity_Dojo_Dance1_GeishasGoDirectlyToDoor_Movement_0
	applymovement LOCALID_YIFU_GEISHA_3, YifuCity_Dojo_Dance1_GeishasGoDirectlyToDoor_Movement_1
	waitmovement LOCALID_YIFU_GEISHA_2
	waitmovement LOCALID_YIFU_GEISHA_3
	waitmovement OBJ_EVENT_ID_CAMERA
	waitse
	return


YifuCity_Dojo_Dance2_GeishasGoDirectlyToDoor::
	applymovement LOCALID_YIFU_GEISHA_5, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	applymovement LOCALID_YIFU_GEISHA_6, YifuCity_Dojo_Dance1_GeishasSurroundPlayerToBattle_Movement_0
	waitmovement LOCALID_YIFU_GEISHA_5
	waitmovement LOCALID_YIFU_GEISHA_6
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance1_Movement_4
	playse SE_LEDGE
	applymovement LOCALID_YIFU_GEISHA_5, YifuCity_Dojo_Dance1_GeishasGoDirectlyToDoor_Movement_0
	applymovement LOCALID_YIFU_GEISHA_6, YifuCity_Dojo_Dance1_GeishasGoDirectlyToDoor_Movement_1
	waitmovement LOCALID_YIFU_GEISHA_5
	waitmovement LOCALID_YIFU_GEISHA_6
	waitmovement OBJ_EVENT_ID_CAMERA
	waitse
	return


YifuCity_Dojo_Dance3_GeishasGoDirectlyToDoor::
	applymovement LOCALID_YIFU_GEISHA_8, YifuCity_Dojo_EventScript_Dance3_Movement_0
	applymovement LOCALID_YIFU_GEISHA_9, YifuCity_Dojo_EventScript_Dance3_Movement_1
	applymovement LOCALID_YIFU_GEISHA_7, YifuCity_Dojo_Dance3_GeishasGoDirectlyToDoor_Movement_0
	applymovement LOCALID_YIFU_GEISHA_10, YifuCity_Dojo_Dance3_GeishasGoDirectlyToDoor_Movement_1
	waitmovement LOCALID_YIFU_GEISHA_7
	waitmovement LOCALID_YIFU_GEISHA_8
	waitmovement LOCALID_YIFU_GEISHA_9
	waitmovement LOCALID_YIFU_GEISHA_10
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Dojo_EventScript_Dance3_Movement_4
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


YifuCity_Dojo_SetShortcutMetatiles::
	setmetatile 23, 0, METATILE_DojoYifu_DoorTopLeft, TRUE
	setmetatile 24, 0, METATILE_DojoYifu_DoorTopRight, TRUE
	setmetatile 23, 1, METATILE_DojoYifu_DoorBottomLeft, TRUE
	setmetatile 24, 1, METATILE_DojoYifu_DoorBottomRight, TRUE
	special DrawWholeMapView
	return


YifuCity_Dojo_Dance1_Jump::
	playse SE_BANG
	applymovement LOCALID_YIFU_GEISHA_1, YifuCity_Dojo_Movement_JumpInPlaceDown
	applymovement LOCALID_YIFU_GEISHA_2, YifuCity_Dojo_Movement_JumpInPlaceDown
	applymovement LOCALID_YIFU_GEISHA_3, YifuCity_Dojo_Movement_JumpInPlaceDown
	waitmovement LOCALID_YIFU_GEISHA_1
	waitmovement LOCALID_YIFU_GEISHA_2
	waitmovement LOCALID_YIFU_GEISHA_3
	waitse
	delay 16
	return


YifuCity_Dojo_Dance2_Jump::
	playse SE_BANG
	applymovement LOCALID_YIFU_GEISHA_4, YifuCity_Dojo_Movement_JumpInPlaceDown
	applymovement LOCALID_YIFU_GEISHA_5, YifuCity_Dojo_Movement_JumpInPlaceDown
	applymovement LOCALID_YIFU_GEISHA_6, YifuCity_Dojo_Movement_JumpInPlaceDown
	waitmovement LOCALID_YIFU_GEISHA_4
	waitmovement LOCALID_YIFU_GEISHA_5
	waitmovement LOCALID_YIFU_GEISHA_6
	waitse
	delay 16
	return


YifuCity_Dojo_Dance3_Jump::
	playse SE_BANG
	applymovement LOCALID_YIFU_GEISHA_7, YifuCity_Dojo_Movement_JumpInPlaceDown
	applymovement LOCALID_YIFU_GEISHA_8, YifuCity_Dojo_Movement_JumpInPlaceDown
	applymovement LOCALID_YIFU_GEISHA_9, YifuCity_Dojo_Movement_JumpInPlaceDown
	applymovement LOCALID_YIFU_GEISHA_10, YifuCity_Dojo_Movement_JumpInPlaceDown
	waitmovement LOCALID_YIFU_GEISHA_7
	waitmovement LOCALID_YIFU_GEISHA_8
	waitmovement LOCALID_YIFU_GEISHA_9
	waitmovement LOCALID_YIFU_GEISHA_10
	waitse
	delay 16
	return


YifuCity_Dojo_Movement_JumpInPlaceDown:
	jump_in_place_down
	step_end

YifuCity_Dojo_Dance1::
	playbgm MUS_LILYCOVE, FALSE
	applymovement LOCALID_YIFU_GEISHA_1, YifuCity_Dojo_Dance1_Movement_0
	applymovement LOCALID_YIFU_GEISHA_2, YifuCity_Dojo_Dance1_Movement_1
	applymovement LOCALID_YIFU_GEISHA_3, YifuCity_Dojo_Dance1_Movement_2
	delay 112
	playse SE_LEDGE
	waitmovement LOCALID_YIFU_GEISHA_1
	waitmovement LOCALID_YIFU_GEISHA_2
	waitmovement LOCALID_YIFU_GEISHA_3
	fadedefaultbgm
	return


YifuCity_Dojo_Dance2::
	playbgm MUS_LILYCOVE, FALSE
	applymovement LOCALID_YIFU_GEISHA_4, YifuCity_Dojo_Dance2_Movement_0
	applymovement LOCALID_YIFU_GEISHA_5, YifuCity_Dojo_Dance2_Movement_1
	applymovement LOCALID_YIFU_GEISHA_6, YifuCity_Dojo_Dance2_Movement_2
	delay 16
	playse SE_LEDGE
	delay 32
	playse SE_LEDGE
	delay 32
	playse SE_LEDGE
	delay 32
	playse SE_LEDGE
	waitmovement LOCALID_YIFU_GEISHA_4
	waitmovement LOCALID_YIFU_GEISHA_5
	waitmovement LOCALID_YIFU_GEISHA_6
	fadedefaultbgm
	return


YifuCity_Dojo_Dance3::
	playbgm MUS_LILYCOVE, FALSE
	applymovement LOCALID_YIFU_GEISHA_7, YifuCity_Dojo_Dance3_Movement_0
	applymovement LOCALID_YIFU_GEISHA_8, YifuCity_Dojo_Dance3_Movement_1
	applymovement LOCALID_YIFU_GEISHA_9, YifuCity_Dojo_Dance3_Movement_2
	applymovement LOCALID_YIFU_GEISHA_10, YifuCity_Dojo_Dance3_Movement_3
	delay 64
	playse SE_LEDGE
	delay 48
	playse SE_LEDGE
	delay 32
	playse SE_LEDGE
	waitmovement LOCALID_YIFU_GEISHA_7
	waitmovement LOCALID_YIFU_GEISHA_8
	waitmovement LOCALID_YIFU_GEISHA_9
	waitmovement LOCALID_YIFU_GEISHA_10
	fadedefaultbgm
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
	trainerbattle_single TRAINER_AKARI, YifuCity_Dojo_EventScript_Akari_Text_0, YifuCity_Dojo_EventScript_Dance1_Text_7
	setspeaker SP_NAME_KIMONO_GIRL
	msgbox YifuCity_Dojo_EventScript_Akari_Text_1, MSGBOX_AUTOCLOSE
	end


YifuCity_Dojo_EventScript_Yuka::
	trainerbattle_single TRAINER_YUKA, YifuCity_Dojo_EventScript_Yuka_Text_0, YifuCity_Dojo_EventScript_Yuka_Text_1
	setspeaker SP_NAME_KIMONO_GIRL
	msgbox YifuCity_Dojo_EventScript_Yuka_Text_2, MSGBOX_AUTOCLOSE
	end


YifuCity_Dojo_EventScript_Nanami::
	trainerbattle_single TRAINER_NANAMI, YifuCity_Dojo_EventScript_Nanami_Text_0, YifuCity_Dojo_EventScript_Dance3_Text_6
	setspeaker SP_NAME_KIMONO_GIRL
	msgbox YifuCity_Dojo_EventScript_Nanami_Text_1, MSGBOX_AUTOCLOSE
	end


YifuCity_Dojo_EventScript_Kanae::
	trainerbattle_single TRAINER_KANAE, YifuCity_Dojo_EventScript_Dance3_Text_7, YifuCity_Dojo_EventScript_Kanae_Text_0
	setspeaker SP_NAME_KIMONO_GIRL
	msgbox YifuCity_Dojo_EventScript_Kanae_Text_1, MSGBOX_AUTOCLOSE
	end


YifuCity_Dojo_EventScript_Karin::
	trainerbattle_single TRAINER_KARIN, YifuCity_Dojo_EventScript_Karin_Text_0, YifuCity_Dojo_EventScript_Karin_Text_1
	setspeaker SP_NAME_KIMONO_GIRL
	msgbox YifuCity_Dojo_EventScript_Karin_Text_2, MSGBOX_AUTOCLOSE
	end


YifuCity_Dojo_EventScript_Miika::
	trainerbattle_single TRAINER_MIIKA, YifuCity_Dojo_EventScript_Miika_Text_0, YifuCity_Dojo_EventScript_Miika_Text_1
	setspeaker SP_NAME_KIMONO_GIRL
	msgbox YifuCity_Dojo_EventScript_Miika_Text_2, MSGBOX_AUTOCLOSE
	end


YifuCity_Dojo_EventScript_Dancer::
	lock
	faceplayer
	setspeaker SP_NAME_KIMONO_GIRL
	msgbox YifuCity_Dojo_EventScript_Dancer_Text_0
	release
	return


YifuCity_Dojo_EventScript_Dancer2::
	lock
	faceplayer
	setspeaker SP_NAME_KIMONO_GIRL
	msgbox YifuCity_Dojo_EventScript_Dancer2_Text_0
	release
	return


YifuCity_Dojo_EventScript_ImpossibleDancer::
	lock
	faceplayer
	setspeaker SP_NAME_KIMONO_GIRL
	msgbox YifuCity_Dojo_EventScript_ImpossibleDancer_Text_0
	release
	return


YifuCity_Dojo_EventScript_Yutaka::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE03_GET, YifuCity_Dojo_EventScript_Yutaka_2
YifuCity_Dojo_EventScript_Yutaka_1:
	trainerbattle_single TRAINER_YUTAKA_1, YifuCity_Dojo_EventScript_Yutaka_Text_1, YifuCity_Dojo_EventScript_Yutaka_Text_2, YifuCity_Dojo_EventScript_YutakaDefeated, NO_MUSIC
	setspeaker SP_NAME_YUTAKA
	msgbox YifuCity_Dojo_EventScript_Yutaka_Text_3
	release
	end

YifuCity_Dojo_EventScript_Yutaka_2:
	setspeaker SP_NAME_YUTAKA
	msgbox YifuCity_Dojo_EventScript_Yutaka_Text_0
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	waitse
	delay 48
	goto YifuCity_Dojo_EventScript_Yutaka_1


YifuCity_Dojo_EventScript_YutakaDefeated::
	message YifuCity_Dojo_EventScript_YutakaDefeated_Text_0
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setspeaker SP_NAME_YUTAKA
	msgbox YifuCity_Dojo_EventScript_YutakaDefeated_Text_1, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM_X_SCISSOR
	setspeaker SP_NAME_YUTAKA
	msgbox YifuCity_Dojo_EventScript_YutakaDefeated_Text_2
	closemessage
	setflag FLAG_BADGE03_GET
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	addvar VAR_PLAYER_REPUTATION, 5
	call YifuCity_Dojo_SetShortcutMetatiles
	call YifuCity_Dojo_DoorAppears_Screenshake
	delay 48
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
	face_left
	step_end

YifuCity_Dojo_EventScript_Dance3_Movement_1:
	walk_up
	face_right
	step_end

YifuCity_Dojo_EventScript_Dance3_Movement_2:
	jump_2_up
	walk_up
	face_right
	step_end

YifuCity_Dojo_EventScript_Dance3_Movement_3:
	jump_2_up
	walk_right
	walk_up
	face_left
	step_end

YifuCity_Dojo_EventScript_Dance3_Movement_4:
	walk_up
	walk_up
	step_end

YifuCity_Dojo_EventScript_Dance3_Movement_5:
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
	walk_left
	walk_left
	face_down
	step_end

YifuCity_Dojo_Dance3_GeishasSurroundPlayerToBattle_Movement_1:
	walk_right
	walk_right
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
	walk_left
	walk_left
	step_end

YifuCity_Dojo_Dance3_GeishasGoDirectlyToDoor_Movement_1:
	walk_right
	walk_right
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

YifuCity_Dojo_Dance2_Movement_0:
	walk_right
	jump_2_right
	jump_2_left
	jump_2_right
	walk_right
	walk_left
	walk_left
	face_down
	step_end

YifuCity_Dojo_Dance2_Movement_1:
	face_left
	delay_16
	jump_2_left
	jump_2_right
	jump_2_left
	face_down
	step_end

YifuCity_Dojo_Dance2_Movement_2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	jump_2_right
	jump_2_right
	face_down
	step_end

YifuCity_Dojo_Dance3_Movement_0:
	face_left
	delay_16
	face_up
	delay_16
	face_right
	delay_16
	face_down
	delay_16
	jump_2_right
	walk_right
	jump_2_right
	walk_right
	walk_right
	face_left
	delay_16
	face_up
	delay_16
	face_right
	delay_16
	face_down
	delay_16
	step_end

YifuCity_Dojo_Dance3_Movement_1:
	face_left
	delay_16
	face_up
	delay_16
	face_right
	delay_16
	face_down
	delay_16
	walk_left
	walk_down
	walk_right
	walk_right
	walk_up
	jump_2_right
	face_left
	delay_16
	face_up
	delay_16
	face_right
	delay_16
	face_down
	delay_16
	step_end

YifuCity_Dojo_Dance3_Movement_2:
	face_left
	delay_16
	face_up
	delay_16
	face_right
	delay_16
	face_down
	delay_16
	walk_right
	walk_up
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	face_left
	delay_16
	face_up
	delay_16
	face_right
	delay_16
	face_down
	delay_16
	step_end

YifuCity_Dojo_Dance3_Movement_3:
	face_left
	delay_16
	face_up
	delay_16
	face_right
	delay_16
	face_down
	delay_16
	jump_2_left
	walk_left
	jump_2_left
	walk_left
	walk_left
	face_left
	delay_16
	face_up
	delay_16
	face_right
	delay_16
	face_down
	delay_16
	step_end

YifuCity_Dojo_EventScript_Dance1_Text_0:
	.string "Welcome to the Yifu City Dojo.\p"
	.string "You will have the pleasure to watch\nthree different dances, at the end of\lwhich you will be asked a question.\p"
	.string "The first dance will soon commence!\nSee the dancer on the left.\lKeep your eyes on her!\p"
	.string "If you know where she is by the end of\nour dance, we shall let you through.\p"
	.string "If you guess wrong, you will have to\nbattle us.\lAre you ready? One, two…$"

YifuCity_Dojo_EventScript_Dance1_Text_1:
	.string "Well? Which dancer is the one who was\n"
	.string "originally on the left?$"

YifuCity_Dojo_EventScript_Dance1_Text_2:
	.string "The left one.$"

YifuCity_Dojo_EventScript_Dance1_Text_3:
	.string "The middle one.$"

YifuCity_Dojo_EventScript_Dance1_Text_4:
	.string "The right one.$"

YifuCity_Dojo_EventScript_Dance1_Text_5:
	.string "You are correct!\p"
	.string "Very well.\n"
	.string "You may proceed to the next room.$"

YifuCity_Dojo_EventScript_Dance1_Text_6:
	.string "You are incorrect!\p"
	.string "We shall face you in battle before you\n"
	.string "proceed.$"

YifuCity_Dojo_EventScript_Dance1_Text_7:
	.string "Oh!$"

YifuCity_Dojo_EventScript_Dance1_Text_8:
	.string "I see.$"

YifuCity_Dojo_EventScript_Dance1_Text_9:
	.string "Very well! You may now proceed.$"

YifuCity_Dojo_EventScript_Dance2_Text_0:
	.string "This time, we won't tell you which\ndancer you need to keep track of.\p"
	.string "Are you ready for the second dance?\nFollow each of our moves…\lOne, two, three!$"

YifuCity_Dojo_EventScript_Dance2_Text_1:
	.string "The dancer on the right…\n"
	.string "Where was she originally?$"

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
	.string "For the third and final dance, we won't\nask you about a dancer's position.\l"
	.string "Just pay attention to our actions!\p"
	.string "One, two, three, four.$"

YifuCity_Dojo_EventScript_Dance3_Text_1:
	.string "Can you tell us how many jumps there\n"
	.string "were in this dance?$"

YifuCity_Dojo_EventScript_Dance3_Text_2:
	.string "Five.$"

YifuCity_Dojo_EventScript_Dance3_Text_3:
	.string "Six.$"

YifuCity_Dojo_EventScript_Dance3_Text_4:
	.string "Seven.$"

YifuCity_Dojo_EventScript_Dance3_Text_5:
	.string "You are correct!\p"
	.string "Very well.\n"
	.string "You may proceed to the last room.$"

YifuCity_Dojo_EventScript_Dance3_Text_6:
	.string "Pant… Hey, let me catch my breath!$"

YifuCity_Dojo_EventScript_Dance3_Text_7:
	.string "You didn't see me trip over my own\n"
	.string "foot, did you?$"

YifuCity_Dojo_EventScript_Advice_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_MAN_2 EMOTE_NORMAL}Such grace! Such swiftness!\n"
	.string "I am wowed!\p"
	.string "{PLAYER}…\n"
	.string "That's a name to be remembered!$"

YifuCity_Dojo_EventScript_Advice_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_MAN_2 EMOTE_NORMAL}Hello, young challenger, and welcome\nto the Dance Hall Dojo!\p"
	.string "Got what it takes to see through the\ndancers' intoxicating moves?\p"
	.string "Master Yutaka favors Dance Moves.\nA battle with her is like partaking in\la dizzying dancing showdown!\p"
	.string "Watch out though, she can be as\nabrasive as she is beautiful.\p"
	.string "She probably won't appreciate you\nwalking around her Dojo with your\nclothes looking like… this…\p"
	.string "Uh, nevermind my babbling!\nGo get 'em, champ!$"

YifuCity_Dojo_EventScript_DojoStatue_Text_0:
	.string "Dojo of Yifu City\p"
	.string "Certified Wielders:\n"
	.string "Natsuki,\l"
	.string "{PLAYER}$"

YifuCity_Dojo_EventScript_DojoStatue_Text_1:
	.string "Dojo of Kura Village\p"
	.string "Certified Wielders:\n"
	.string "Natsuki$"

YifuCity_Dojo_EventScript_Akari_Text_0:
	.string "You still wish to fight?\n"
	.string "Very well!$"

YifuCity_Dojo_EventScript_Akari_Text_1:
	.string "You are very graceful.\n"
	.string "Are you sure you're not a dancer?$"

YifuCity_Dojo_EventScript_Yuka_Text_0:
	.string "You have a good eye!\n"
	.string "Let's see if that applies to Pokémon,\l"
	.string "as well!$"

YifuCity_Dojo_EventScript_Yuka_Text_1:
	.string "You have many talents, I see!$"

YifuCity_Dojo_EventScript_Yuka_Text_2:
	.string "The next dance should be more of a\n"
	.string "challenge.$"

YifuCity_Dojo_EventScript_Nanami_Text_0:
	.string "Pant… I'm impressed… Pant…\n"
	.string "This last dance was… intense!$"

YifuCity_Dojo_EventScript_Nanami_Text_1:
	.string "I really need to exercise more…$"

YifuCity_Dojo_EventScript_Kanae_Text_0:
	.string "My dance wasn't perfect!\n"
	.string "I deserve this!$"

YifuCity_Dojo_EventScript_Kanae_Text_1:
	.string "Next time my dance will be perfect,\n"
	.string "you'll see!$"

YifuCity_Dojo_EventScript_Karin_Text_0:
	.string "Oh good! A battle!\n"
	.string "I was getting bored.$"

YifuCity_Dojo_EventScript_Karin_Text_1:
	.string "I am regretting this…$"

YifuCity_Dojo_EventScript_Karin_Text_2:
	.string "Miss Yutaka holds us to high standards\nboth in battle and onstage!$"

YifuCity_Dojo_EventScript_Miika_Text_0:
	.string "Please admire my brand new designer\n"
	.string "kimono!$"

YifuCity_Dojo_EventScript_Miika_Text_1:
	.string "You don't look impressed at all!$"

YifuCity_Dojo_EventScript_Miika_Text_2:
	.string "Working here has its perks.\n"
	.string "We get fine silk clothes for free!$"

YifuCity_Dojo_EventScript_Dancer_Text_0:
	.string "I have no Pokémon!\n"
	.string "I'm only a dancer.$"

YifuCity_Dojo_EventScript_Dancer2_Text_0:
	.string "Come back to watch us dance\n"
	.string "sometimes!$"

YifuCity_Dojo_EventScript_ImpossibleDancer_Text_0:
	.string "Hey! How did you get up here?!$"

YifuCity_Dojo_EventScript_Yutaka_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_YUTAKA EMOTE_NORMAL}Well done! Welcome to Yifu City's Doj-$"

YifuCity_Dojo_EventScript_Yutaka_Text_1:
	.string "Excuse me, what is this?\p"
	.string "Is there a reason for the\n"
	.string "accoutrement you're donning?\p"
	.string "A carnival, perhaps?\n"
	.string "Or have you lost a bet?\p"
	.string "Or do you just lack a basic sense of\n"
	.string "style to such an extreme degree?\p"
	.string "Here you are, parading around\n"
	.string "in your peasant's clothes…\p"
	.string "(…Yutaka, you must not let this\n"
	.string "offend you so!\l"
	.string "You are stronger than that!)\p"
	.string "Ahem… Let us move on…\p"
	.string "You shall be fighting my exquisite\n"
	.string "assortment of Pokémon,\l"
	.string "in the hopes of obtaining\l"
	.string "an official Token from me.\p"
	.string "Try not to be too overwhelmed by my\n"
	.string "strength and, most of all, by my\l"
	.string "impeccable sense of fashion.\p"
	.string "Let this battle begin!$"

YifuCity_Dojo_EventScript_Yutaka_Text_2:
	.string "How dare you!$"

YifuCity_Dojo_EventScript_Yutaka_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_YUTAKA EMOTE_NORMAL}You shall achieve great things,\n"
	.string "despite your fashion faux-pas.\p"
	.string "I hope to battle you again.$"

YifuCity_Dojo_EventScript_YutakaDefeated_Text_0:
	.string "{PLAYER} received the Silk Token\n"
	.string "from Yutaka.$"

YifuCity_Dojo_EventScript_YutakaDefeated_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_YUTAKA EMOTE_NORMAL}I am outrée! Your techniques are\n"
	.string "rough and vulgar, yet…\p"
	.string "Victory is yours…\n"
	.string "That is undeniable.\p"
	.string "I guess what you lack in aesthetic\n"
	.string "values, you compensate in strength.\p"
	.string "Do accept this, as well.$"

YifuCity_Dojo_EventScript_YutakaDefeated_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_YUTAKA EMOTE_NORMAL}This scroll contains my famous\n"
	.string "X-Scissor technique.\p"
	.string "I perfected it back when I worked as\n"
	.string "a seamstress.\p"
	.string "About that, uh… We should go\n"
	.string "clothes-shopping together sometime.\p"
	.string "I cannot bear to see your image\n"
	.string "suffer so.$"

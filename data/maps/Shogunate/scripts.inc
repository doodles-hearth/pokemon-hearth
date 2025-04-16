Shogunate_MapScripts::
	.byte 0


Shogunate_EventScript_LockedDoor::
	lock
	msgbox Shogunate_EventScript_LockedDoor_Text_0
	closemessage
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Shogunate_EventScript_LockedDoor_Movement_0
	waitmovement OBJ_EVENT_ID_CAMERA
	waitbuttonpress
	applymovement OBJ_EVENT_ID_CAMERA, Shogunate_EventScript_LockedDoor_Movement_1
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	release
	return


Shogunate_EventScript_Shuppet::
	lock
	setseenmon SPECIES_SHUPPET
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Shogunate_EventScript_Shuppet_Movement_0
	waitmovement 0
	waitse
	faceplayer
	playmoncry SPECIES_SHUPPET, CRY_MODE_NORMAL
	waitmoncry
	fadescreen FADE_TO_BLACK
	setflag FLAG_TEMP_1
	fadescreen FADE_FROM_BLACK
	release
	return


Shogunate_EventScript_LockedDoor_Movement_0:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Shogunate_EventScript_LockedDoor_Movement_1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Shogunate_EventScript_Shuppet_Movement_0:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

Shogunate_EventScript_LockedDoor_Text_0:
	.string "It's a huge bolted door.$"

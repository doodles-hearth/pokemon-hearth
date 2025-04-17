Beachbound_Route_Decay_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Beachbound_Route_Decay_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Beachbound_Route_Decay_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_DECAY_BEACHBOUND_ROUTE, 1, Beachbound_Route_Decay_SeeDecay
	.2byte 0


Beachbound_Route_Decay_SeeDecay::
	lock
	setvar VAR_DECAY_BEACHBOUND_ROUTE, 2
	setflag FLAG_TEMP_1
	removeobject 13
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	delay 48
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Beachbound_Route_Decay_SeeDecay_Movement_0
	waitmovement 0
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 73
	setvar VAR_0x8005, 17
	special TeleportCamera
	special RemoveCameraObject
	fadescreen FADE_FROM_BLACK
	release
	return


BeachboundRoute_Decay_EventScript_Shepherd::
	speakername BeachboundRoute_Decay_EventScript_Shepherd_Text_0
	msgbox BeachboundRoute_Decay_EventScript_Shepherd_Text_1, MSGBOX_NPC
	return


BeachboundRoute_Decay_EventScript_Karu::
	speakername BeachboundRoute_Decay_EventScript_Karu_Text_0
	msgbox BeachboundRoute_Decay_EventScript_Karu_Text_1, MSGBOX_NPC
	return


BeachboundRoute_Decay_EventScript_Kin::
	speakername BeachboundRoute_Decay_EventScript_Karu_Text_0
	msgbox BeachboundRoute_Decay_EventScript_Kin_Text_0, MSGBOX_NPC
	return


BeachboundRoute_Decay_EventScript_BeanDialogue::
	setvar VAR_DECAY_BEACHBOUND_ROUTE, 4
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_0
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_1
	closemessage
	setflag FLAG_TEMP_1
	addobject 13
	applymovement 13, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_0
	waitmovement 0
	playse SE_PIN
	applymovement 13, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	delay 48
	applymovement 13, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_1
	waitmovement 0
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_2
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_3
	closemessage
	applymovement 12, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_2
	waitmovement 0
	applymovement 8, Common_Movement_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 48
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_4
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_5
	closemessage
	applymovement 12, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_3
	waitmovement 0
	delay 48
	applymovement 8, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 8
	waitmovement OBJ_EVENT_ID_PLAYER
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_0
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_6
	closemessage
	applymovement 8, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_4
	waitmovement 0
	removeobject 8
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_2
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_7
	closemessage
	applymovement 13, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_5
	waitmovement 0
	removeobject 13
	release
	return


BeachboundRoute_Decay_EventScript_BeanTrigger2StepsAway::
	lock
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	delay 48
	applymovement 8, Common_Movement_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_Decay_EventScript_BeanTrigger2StepsAway_Movement_0
	waitmovement 0
	call BeachboundRoute_Decay_EventScript_BeanDialogue
	return


BeachboundRoute_Decay_EventScript_BeanTrigger1StepAway::
	lock
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	delay 48
	applymovement 8, Common_Movement_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_Decay_EventScript_BeanTrigger1StepAway_Movement_0
	waitmovement 0
	call BeachboundRoute_Decay_EventScript_BeanDialogue
	return


BeachboundRoute_Decay_EventScript_BeanTrigger::
	lock
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	delay 48
	applymovement 8, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 8
	waitmovement OBJ_EVENT_ID_PLAYER
	call BeachboundRoute_Decay_EventScript_BeanDialogue
	return


BeachboundRoute_Decay_EventScript_Bean::
	lock
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_0
	msgbox BeachboundRoute_Decay_EventScript_Bean_Text_0
	closemessage
	release
	return


BeachboundRoute_Decay_EventScript_Koishi::
	lock
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_4
	msgbox BeachboundRoute_Decay_EventScript_Koishi_Text_0
	closemessage
	release
	return


BeachboundRoute_Decay_EventScript_SamuraiBeCarefulTrigger::
	lock
	setvar VAR_DECAY_BEACHBOUND_ROUTE, 3
	applymovement 10, Common_Movement_WalkInPlaceFasterDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 10
	waitmovement OBJ_EVENT_ID_PLAYER
	speakername BeachboundRoute_Decay_EventScript_SamuraiBeCarefulTrigger_Text_0
	msgbox BeachboundRoute_Decay_EventScript_SamuraiBeCarefulTrigger_Text_1
	closemessage
	release
	return


BeachboundRoute_Decay_EventScript_SamuraiBeCareful::
	speakername BeachboundRoute_Decay_EventScript_SamuraiBeCarefulTrigger_Text_0
	msgbox BeachboundRoute_Decay_EventScript_SamuraiBeCareful_Text_0, MSGBOX_NPC
	return


BeachboundRoute_Decay_EventScript_Samurai::
	speakername BeachboundRoute_Decay_EventScript_SamuraiBeCarefulTrigger_Text_0
	msgbox BeachboundRoute_Decay_EventScript_Samurai_Text_0, MSGBOX_NPC
	return


BeachboundRoute_Decay_EventScript_SamuraiWhatCouldBe::
	speakername BeachboundRoute_Decay_EventScript_SamuraiBeCarefulTrigger_Text_0
	msgbox BeachboundRoute_Decay_EventScript_SamuraiWhatCouldBe_Text_0, MSGBOX_NPC
	return


Beachbound_Route_Decay_SeeDecay_Movement_0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_0:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_2:
	walk_down
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_3:
	walk_up
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_4:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_5:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BeachboundRoute_Decay_EventScript_BeanTrigger2StepsAway_Movement_0:
	walk_left
	walk_left
	step_end

BeachboundRoute_Decay_EventScript_BeanTrigger1StepAway_Movement_0:
	walk_left
	step_end

BeachboundRoute_Decay_EventScript_Shepherd_Text_0:
	.string "Shepherd$"

BeachboundRoute_Decay_EventScript_Shepherd_Text_1:
	.string "What's goin' on? Why are all the plants\n"
	.string "rotting?$"

BeachboundRoute_Decay_EventScript_Karu_Text_0:
	.string "Girl$"

BeachboundRoute_Decay_EventScript_Karu_Text_1:
	.string "I'm scared…$"

BeachboundRoute_Decay_EventScript_Kin_Text_0:
	.string "What's happening?$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_0:
	.string "Hariko$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_1:
	.string "Oh! Hello.\n"
	.string "{PLAYER}, right?\p"
	.string "I am Hariko, remember me? We had a\n"
	.string "chat in the Ginko Woods.$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_2:
	.string "Natsuki$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_3:
	.string "{PLAYER}! What's going on?\p"
	.string "Who is this, blah blah blah$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_4:
	.string "Koishi$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_5:
	.string "I heard you, do not get involved in\n"
	.string "this$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_6:
	.string "This is unfair! How are we supposed to\n"
	.string "investigate if we're not allowed to?\p"
	.string "Let's leave now.$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_7:
	.string "I'm leaving too$"

BeachboundRoute_Decay_EventScript_Bean_Text_0:
	.string "… …$"

BeachboundRoute_Decay_EventScript_Koishi_Text_0:
	.string "The situation is dire…\p"
	.string "Please move along, and I repeat, do\n"
	.string "NOT get into trouble!$"

BeachboundRoute_Decay_EventScript_SamuraiBeCarefulTrigger_Text_0:
	.string "Samurai$"

BeachboundRoute_Decay_EventScript_SamuraiBeCarefulTrigger_Text_1:
	.string "Please be careful if you're crossing\n"
	.string "over the {COLOR RED}decayed{COLOR DARK_GRAY} area.\p"
	.string "We don't want anyone getting hurt!$"

BeachboundRoute_Decay_EventScript_SamuraiBeCareful_Text_0:
	.string "Please be careful!$"

BeachboundRoute_Decay_EventScript_Samurai_Text_0:
	.string "Don't panic!\n"
	.string "Don't touch the {COLOR RED}decay{COLOR DARK_GRAY}!$"

BeachboundRoute_Decay_EventScript_SamuraiWhatCouldBe_Text_0:
	.string "What could be the cause of this?!$"

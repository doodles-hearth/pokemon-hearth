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
	fadescreenswapbuffers FADE_TO_BLACK
	setvar VAR_0x8004, 73
	setvar VAR_0x8005, 17
	special TeleportCamera
	special RemoveCameraObject
	fadescreenswapbuffers FADE_FROM_BLACK
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
	goto_if_set FLAG_TALKED_TO_HARIKO_IN_MAGURO_REFUGE, BeachboundRoute_Decay_EventScript_BeanDialogue_2
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_2
BeachboundRoute_Decay_EventScript_BeanDialogue_1:
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
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_2
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_3
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_4
	closemessage
	applymovement 13, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_3
	waitmovement 13
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_3
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_5
	applymovement 8, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_2
	waitmovement 8
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_4
	waitmovement OBJ_EVENT_ID_PLAYER
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_0
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_6
	mcdialogue BeachboundRoute_Decay_EventScript_BeanDialogue_Text_7, BeachboundRoute_Decay_EventScript_BeanDialogue_Text_8
	switch VAR_RESULT
	case 1, BeachboundRoute_Decay_EventScript_BeanDialogue_7
BeachboundRoute_Decay_EventScript_BeanDialogue_5:
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_0
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_10
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_3
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_11
	applymovement 12, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_6
	waitmovement 0
	applymovement 8, Common_Movement_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 48
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_12
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_13
	closemessage
	applymovement 12, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_7
	waitmovement 0
	delay 48
	applymovement 8, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_5
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_4
	waitmovement 8
	waitmovement OBJ_EVENT_ID_PLAYER
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_0
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_14
	closemessage
	applymovement 8, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_8
	waitmovement 0
	removeobject 8
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_3
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_15
	closemessage
	applymovement 13, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_9
	waitmovement 0
	removeobject 13
	release
	return

BeachboundRoute_Decay_EventScript_BeanDialogue_2:
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_1
	goto BeachboundRoute_Decay_EventScript_BeanDialogue_1

BeachboundRoute_Decay_EventScript_BeanDialogue_7:
	applymovement 8, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_5
	waitmovement 8
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_0
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_9
	applymovement 8, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_2
	waitmovement 8
	goto BeachboundRoute_Decay_EventScript_BeanDialogue_5


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
	applymovement 8, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_5
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_4
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
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_12
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
	walk_in_place_fast_down
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_2:
	walk_in_place_fast_up
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_3:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_4:
	walk_in_place_fast_left
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_5:
	walk_in_place_fast_right
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_6:
	walk_down
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_7:
	walk_up
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_8:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_9:
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
	.string "Oh! Hello again, {PLAYER}!\p"
	.string "What do you think is happening here?\n"
	.string "It looks like there is some sort of\l"
	.string "Decay affecting this whole area.\p"
	.string "The Samurai over there told me there\n"
	.string "are reports of this phenomenon\l"
	.string "hitting several areas over the last\l"
	.string "few days.\p"
	.string "That coincides with the start of the\n"
	.string "Volcano's rumbling spells, so both\l"
	.string "seem to be related.\p"
	.string "Whatever it is, it is not good. I want\n"
	.string "to learn as much as I can about this\l"
	.string "Decay.\p"
	.string "Did you also come here to investigate,\n"
	.string "{PLAYER}? We should team up!$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_2:
	.string "Oh! Hello.\n"
	.string "{PLAYER}, right?\p"
	.string "I am Hariko, remember me? We had a\n"
	.string "chat in the Ginko Woods. What do you\l"
	.string "think is happening here? It looks like\l"
	.string "there is some sort of Decay affecting\l"
	.string "this whole area.\p"
	.string "The Samurai over there told me there\n"
	.string "are reports of this phenomenon\l"
	.string "hitting several areas over the last\l"
	.string "few days.\p"
	.string "That coincides with the start of the\n"
	.string "Volcano's rumbling spells, so both\l"
	.string "seem to be related.\p"
	.string "Whatever it is, it is not good. I want\n"
	.string "to learn as much as I can about this\l"
	.string "Decay.\p"
	.string "Did you also come here to investigate,\n"
	.string "{PLAYER}? We should team up!$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_3:
	.string "Natsuki$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_4:
	.string "{PLAYER}! What the heck is going on\n"
	.string "here? Everything is rotting!\p"
	.string "My Pokémon stepped in that slimy\n"
	.string "black stuff and doesn't look well…\l"
	.string "I need to get to Maguro Harbor's\l"
	.string "Refuge quickly!$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_5:
	.string "Wait, who are you?$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_6:
	.string "I am Hariko. {PLAYER} and I are\n"
	.string "friends. Together, we are going to\l"
	.string "find the cause of this Decay!$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_7:
	.string "That's right!$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_8:
	.string "We are?$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_9:
	.string "I might… have gotten ahead of myself.\n"
	.string "You agree though, right?\l"
	.string "Great!$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_10:
	.string "Your name is Natsuki?\n"
	.string "You are a friend of {PLAYER}'s too…\l"
	.string "That makes us friends as well, then!$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_11:
	.string "Is… Is that so?$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_12:
	.string "Koishi$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_13:
	.string "I couldn't help but overhear your\n"
	.string "conversation. You kids are way too\l"
	.string "young and inexperienced to be\l"
	.string "getting involved in this!\p"
	.string "We know nothing about this Decay yet.\n"
	.string "We only know that it's dangerous.\p"
	.string "We're already stretched thin as it is\n"
	.string "and we don't want to have to rescue\l"
	.string "you, so please let the grownups\l"
	.string "handle the issue.$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_14:
	.string "This is unfair! How are we supposed to\n"
	.string "investigate if we're not allowed to?\p"
	.string "Let's leave now.$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_15:
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
	.string "Don't touch the Decay!$"

BeachboundRoute_Decay_EventScript_SamuraiWhatCouldBe_Text_0:
	.string "What could be the cause of this?!$"

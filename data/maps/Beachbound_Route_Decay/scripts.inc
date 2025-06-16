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
	removeobject LOCALID_BEACHBOUND_DECAY_NATSUKI
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
	special DrawWholeMapView
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_TEMP_1
	addobject LOCALID_BEACHBOUND_DECAY_NATSUKI
	addobject LOCALID_BEACHBOUND_DECAY_HARIKO
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
	mcdialogue BeachboundRoute_Decay_EventScript_Kin_Text_0, BeachboundRoute_Decay_EventScript_BeanDialogue_Text_3
	closemessage
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_0
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_4
	addobject LOCALID_BEACHBOUND_DECAY_NATSUKI
	applymovement LOCALID_BEACHBOUND_DECAY_NATSUKI, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_0
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_BEACHBOUND_DECAY_NATSUKI, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	delay 48
	applymovement LOCALID_BEACHBOUND_DECAY_NATSUKI, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_2
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_5
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_6
	closemessage
	playse SE_PIN
	applymovement LOCALID_BEACHBOUND_DECAY_NATSUKI, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_3
	waitmovement LOCALID_BEACHBOUND_DECAY_NATSUKI
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_5
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_7
	applymovement LOCALID_BEACHBOUND_DECAY_HARIKO, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_2
	waitmovement LOCALID_BEACHBOUND_DECAY_HARIKO
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_4
	waitmovement OBJ_EVENT_ID_PLAYER
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_0
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_8
	mcdialogue BeachboundRoute_Decay_EventScript_BeanDialogue_Text_9, BeachboundRoute_Decay_EventScript_BeanDialogue_Text_10
	delay 24
	switch VAR_RESULT
	case 1, BeachboundRoute_Decay_EventScript_BeanDialogue_7
BeachboundRoute_Decay_EventScript_BeanDialogue_5:
	applymovement LOCALID_BEACHBOUND_DECAY_HARIKO, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_2
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_6
	waitmovement OBJ_EVENT_ID_PLAYER
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_0
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_12
	applymovement LOCALID_BEACHBOUND_DECAY_NATSUKI, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_7
	waitmovement LOCALID_BEACHBOUND_DECAY_NATSUKI
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_5
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_13
	closemessage
	applymovement LOCALID_BEACHBOUND_DECAY_SAMURAI_COLLEAGUE, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_8
	waitmovement LOCALID_BEACHBOUND_DECAY_SAMURAI_COLLEAGUE
	playse SE_PIN
	applymovement LOCALID_BEACHBOUND_DECAY_SAMURAI, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_9
	waitmovement LOCALID_BEACHBOUND_DECAY_SAMURAI
	waitse
	applymovement LOCALID_BEACHBOUND_DECAY_HARIKO, Common_Movement_FaceUp
	applymovement LOCALID_BEACHBOUND_DECAY_NATSUKI, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_BEACHBOUND_DECAY_SAMURAI, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_10
	delay 16
	applymovement LOCALID_BEACHBOUND_DECAY_NATSUKI, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_11
	waitmovement LOCALID_BEACHBOUND_DECAY_SAMURAI
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_14
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_15
	mcdialogue BeachboundRoute_Decay_EventScript_BeanDialogue_Text_16, BeachboundRoute_Decay_EventScript_BeanDialogue_Text_17
	closemessage
	switch VAR_RESULT
	case 0, BeachboundRoute_Decay_EventScript_BeanDialogue_10
	case 1, BeachboundRoute_Decay_EventScript_BeanDialogue_11
BeachboundRoute_Decay_EventScript_BeanDialogue_8:
	applymovement LOCALID_BEACHBOUND_DECAY_SAMURAI, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_13
	waitmovement LOCALID_BEACHBOUND_DECAY_SAMURAI
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_14
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_22
	applymovement LOCALID_BEACHBOUND_DECAY_HARIKO, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_5
	applymovement LOCALID_BEACHBOUND_DECAY_NATSUKI, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_4
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_14
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 48
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_15
	applymovement LOCALID_BEACHBOUND_DECAY_HARIKO, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_15
	applymovement LOCALID_BEACHBOUND_DECAY_NATSUKI, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_15
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_14
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_23
	waitmovement 0
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_14
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_24
	closemessage
	playse SE_PIN
	applymovement LOCALID_BEACHBOUND_DECAY_SAMURAI, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_16
	waitmovement LOCALID_BEACHBOUND_DECAY_SAMURAI
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_14
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_25
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_6
	applymovement LOCALID_BEACHBOUND_DECAY_HARIKO, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_6
	applymovement LOCALID_BEACHBOUND_DECAY_NATSUKI, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_6
	waitmovement 0
	delay 32
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_14
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_26
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_17
	applymovement LOCALID_BEACHBOUND_DECAY_HARIKO, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_17
	applymovement LOCALID_BEACHBOUND_DECAY_NATSUKI, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_17
	delay 48
	warpsilent MAP_KURA_TOWN, 52, 14
	release
	return

BeachboundRoute_Decay_EventScript_BeanDialogue_2:
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_1
	goto BeachboundRoute_Decay_EventScript_BeanDialogue_1

BeachboundRoute_Decay_EventScript_BeanDialogue_7:
	applymovement LOCALID_BEACHBOUND_DECAY_HARIKO, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_5
	waitmovement LOCALID_BEACHBOUND_DECAY_HARIKO
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_0
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_11
	goto BeachboundRoute_Decay_EventScript_BeanDialogue_5

BeachboundRoute_Decay_EventScript_BeanDialogue_10:
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_14
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_18
	closemessage
	goto BeachboundRoute_Decay_EventScript_BeanDialogue_8

BeachboundRoute_Decay_EventScript_BeanDialogue_11:
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_14
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_19
	closemessage
	applymovement LOCALID_BEACHBOUND_DECAY_SAMURAI, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_2
	waitmovement LOCALID_BEACHBOUND_DECAY_SAMURAI
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_14
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_20
	closemessage
	applymovement LOCALID_BEACHBOUND_DECAY_SAMURAI, BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_12
	waitmovement LOCALID_BEACHBOUND_DECAY_SAMURAI
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_14
	msgbox BeachboundRoute_Decay_EventScript_BeanDialogue_Text_21
	closemessage
	goto BeachboundRoute_Decay_EventScript_BeanDialogue_8


BeachboundRoute_Decay_EventScript_BeanTrigger2StepsAway::
	lock
	playse SE_PIN
	applymovement LOCALID_BEACHBOUND_DECAY_HARIKO, BeachboundRoute_Decay_EventScript_BeanTrigger2StepsAway_Movement_0
	delay 24
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_Decay_EventScript_BeanTrigger2StepsAway_Movement_1
	waitse
	waitmovement LOCALID_BEACHBOUND_DECAY_HARIKO
	delay 48
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_Decay_EventScript_BeanTrigger2StepsAway_Movement_2
	waitmovement 0
	call BeachboundRoute_Decay_EventScript_BeanDialogue
	return


BeachboundRoute_Decay_EventScript_BeanTrigger1StepAway::
	lock
	playse SE_PIN
	applymovement LOCALID_BEACHBOUND_DECAY_HARIKO, BeachboundRoute_Decay_EventScript_BeanTrigger2StepsAway_Movement_0
	delay 24
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_Decay_EventScript_BeanTrigger2StepsAway_Movement_1
	waitse
	waitmovement LOCALID_BEACHBOUND_DECAY_HARIKO
	delay 48
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_Decay_EventScript_BeanTrigger1StepAway_Movement_0
	waitmovement 0
	call BeachboundRoute_Decay_EventScript_BeanDialogue
	return


BeachboundRoute_Decay_EventScript_BeanTrigger::
	lock
	playse SE_PIN
	applymovement LOCALID_BEACHBOUND_DECAY_HARIKO, BeachboundRoute_Decay_EventScript_BeanTrigger2StepsAway_Movement_0
	delay 24
	applymovement OBJ_EVENT_ID_PLAYER, BeachboundRoute_Decay_EventScript_BeanTrigger2StepsAway_Movement_1
	waitse
	waitmovement LOCALID_BEACHBOUND_DECAY_HARIKO
	delay 48
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
	speakername BeachboundRoute_Decay_EventScript_Koishi_Text_0
	msgbox BeachboundRoute_Decay_EventScript_Koishi_Text_1
	closemessage
	release
	return


BeachboundRoute_Decay_EventScript_SamuraiBeCarefulTrigger::
	lock
	setvar VAR_DECAY_BEACHBOUND_ROUTE, 3
	applymovement LOCALID_BEACHBOUND_DECAY_FIRST_SAMURAI, Common_Movement_WalkInPlaceFasterDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement LOCALID_BEACHBOUND_DECAY_FIRST_SAMURAI
	waitmovement OBJ_EVENT_ID_PLAYER
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_14
	msgbox BeachboundRoute_Decay_EventScript_SamuraiBeCarefulTrigger_Text_0
	closemessage
	release
	return


BeachboundRoute_Decay_EventScript_SamuraiBeCareful::
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_14
	msgbox BeachboundRoute_Decay_EventScript_SamuraiBeCareful_Text_0, MSGBOX_NPC
	return


BeachboundRoute_Decay_EventScript_Samurai::
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_14
	msgbox BeachboundRoute_Decay_EventScript_Samurai_Text_0, MSGBOX_NPC
	return


BeachboundRoute_Decay_EventScript_SamuraiWhatCouldBe::
	speakername BeachboundRoute_Decay_EventScript_BeanDialogue_Text_14
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
	face_up
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_7:
	walk_in_place_fast_down
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_8:
	face_down
	delay_16
	delay_16
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_9:
	face_down
	delay_16
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_10:
	walk_down
	walk_down
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_11:
	walk_right
	walk_down
	face_up
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_12:
	walk_in_place_fast_down
	delay_16
	delay_16
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_13:
	walk_up
	walk_up
	delay_16
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_14:
	walk_in_place_fast_left
	delay_16
	delay_16
	walk_in_place_fast_right
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_15:
	lock_facing_direction
	walk_up
	delay_16
	delay_16
	walk_up
	unlock_facing_direction
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_16:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	face_down
	step_end

BeachboundRoute_Decay_EventScript_BeanDialogue_Movement_17:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

BeachboundRoute_Decay_EventScript_BeanTrigger2StepsAway_Movement_0:
	face_right
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

BeachboundRoute_Decay_EventScript_BeanTrigger2StepsAway_Movement_1:
	face_left
	step_end

BeachboundRoute_Decay_EventScript_BeanTrigger2StepsAway_Movement_2:
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
	.string "Oh! Hello again, {PLAYER}!\n"
	.string "As you can see, I am investigating.$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_2:
	.string "Oh! Hello.\n"
	.string "{PLAYER}, right?\p"
	.string "I am Hariko, remember me? We had a\n"
	.string "chat in the Ginko Woods.\p"
	.string "As you can see, I am investigating.$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_3:
	.string "Investigating?$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_4:
	.string "Well, look around you! This whole area\n"
	.string "is decaying.\p"
	.string "Whatever this is, it is not good.\n"
	.string "I want to learn as much as I can about\l"
	.string "this decay.\p"
	.string "Did you also come here to investigate,\n"
	.string "{PLAYER}? We should team up!$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_5:
	.string "Natsuki$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_6:
	.string "{PLAYER}!\n"
	.string "What the heck is going on here?\l"
	.string "Everything is rotting!\p"
	.string "Stepping in that slimy black stuff\n"
	.string "made me awfully nauseous…$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_7:
	.string "Wait, who are you?$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_8:
	.string "I am Hariko.\n"
	.string "{PLAYER} and I are friends.\p"
	.string "Together, we are going to find the\n"
	.string "cause of this Decay!$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_9:
	.string "That's right!$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_10:
	.string "We are?$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_11:
	.string "I may… have gotten ahead of myself.\p"
	.string "You agree though, right?\n"
	.string "Great!$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_12:
	.string "Your name is Natsuki?\n"
	.string "You are a friend of {PLAYER}'s too…\p"
	.string "That makes us friends as well!$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_13:
	.string "Is… Is that so?$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_14:
	.string "Samurai$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_15:
	.string "What's a bunch of children doing\n"
	.string "here?\p"
	.string "You really shouldn't stay here.\n"
	.string "The situation is under control,\l"
	.string "but this is no place for you kids!$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_16:
	.string "What's going on?$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_17:
	.string "We can help!$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_18:
	.string "Nothing that concerns you!\n"
	.string "Let the grownups handle this!\p"
	.string "On you go!$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_19:
	.string "Help? That's adorable.$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_20:
	.string "Hear that?\n"
	.string "Kids here are saying they can help!\p"
	.string "Hahaha!$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_21:
	.string "In all seriousness though, move along\n"
	.string "and let the grownups handle this!\p"
	.string "On you go!$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_22:
	.string "{FONT_SMALL}Mumble mumble…{PAUSE 32}\n"
	.string "Psst psst…{PAUSE 32} Mumble mumble…{PAUSE 32}$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_23:
	.string "{FONT_SMALL}Mumble mumble…{PAUSE 32}\n"
	.string "Psst psst…{PAUSE 32}{FONT_NORMAL} Mumble mumble…{PAUSE 32}$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_24:
	.string "…need more Samurai to secure the\n"
	.string "perimeter…\p"
	.string "…started less than a week ago…\p"
	.string "…spreading over several areas…$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_25:
	.string "Are you kidding me?$"

BeachboundRoute_Decay_EventScript_BeanDialogue_Text_26:
	.string "Have your parents never taught you\n"
	.string "not to eavesdrop?\p"
	.string "Move along!$"

BeachboundRoute_Decay_EventScript_Bean_Text_0:
	.string "… …$"

BeachboundRoute_Decay_EventScript_Koishi_Text_0:
	.string "Koishi$"

BeachboundRoute_Decay_EventScript_Koishi_Text_1:
	.string "This is very worrying…\p"
	.string "Please don't get into trouble, we're\n"
	.string "already spread thin as it is!$"

BeachboundRoute_Decay_EventScript_SamuraiBeCarefulTrigger_Text_0:
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

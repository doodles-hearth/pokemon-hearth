Silveridge_EldersHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Silveridge_EldersHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Silveridge_EldersHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_DECAY_BEACHBOUND_ROUTE, 1, Silveridge_EldersHouse_EventScript_Conversation
	.2byte 0


Silveridge_EldersHouse_EventScript_Conversation::
	lock
	applymovement 2, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	speakername Silveridge_EldersHouse_EventScript_Conversation_Text_0
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_1
	closemessage
	applymovement 3, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	speakername Silveridge_EldersHouse_EventScript_Conversation_Text_2
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_3
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	speakername Silveridge_EldersHouse_EventScript_Conversation_Text_4
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_5
	closemessage
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	speakername Silveridge_EldersHouse_EventScript_Conversation_Text_4
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_6
	closemessage
	applymovement 3, Common_Movement_FaceDown
	applymovement 2, Common_Movement_FaceDown
	waitmovement 3
	waitmovement 2
	delay 48
	delay 48
	applymovement 3, Silveridge_EldersHouse_EventScript_Conversation_Movement_0
	applymovement 2, Silveridge_EldersHouse_EventScript_Conversation_Movement_1
	waitmovement 3
	removeobject 3
	playse SE_EXIT
	waitmovement 2
	playse SE_EXIT
	waitse
	setflag FLAG_GAVE_LETTER_ELDER_SILVERIDGE
	delay 48
	applymovement OBJ_EVENT_ID_PLAYER, Silveridge_EldersHouse_EventScript_Conversation_Movement_2
	waitmovement OBJ_EVENT_ID_PLAYER
	speakername Silveridge_EldersHouse_EventScript_Conversation_Text_4
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_7
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, Silveridge_EldersHouse_EventScript_Conversation_Text_8
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Silveridge_EldersHouse_EventScript_Conversation_Movement_3
	waitmovement OBJ_EVENT_ID_PLAYER
	speakername Silveridge_EldersHouse_EventScript_Conversation_Text_4
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_9
	clearflag FLAG_KURA_DOJO_CLOSED
	setflag FLAG_HIDE_BONSAI_SHOP_OWNER
	release
	return


Silveridge_EldersHouse_EventScript_Elder::
	lock
	faceplayer
	speakername Silveridge_EldersHouse_EventScript_Conversation_Text_4
	msgbox Silveridge_EldersHouse_EventScript_Elder_Text_0
	closemessage
	release
	return


Silveridge_EldersHouse_EventScript_Conversation_Movement_0:
	walk_down
	walk_down
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_1:
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_2:
	walk_up
	walk_up
	walk_right
	face_up
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_3:
	walk_up
	delay_16
	walk_down
	face_up
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Text_0:
	.string "Old man$"

Silveridge_EldersHouse_EventScript_Conversation_Text_1:
	.string "Yet another area is decaying on\n"
	.string "Beachbound Route…$"

Silveridge_EldersHouse_EventScript_Conversation_Text_2:
	.string "Old woman$"

Silveridge_EldersHouse_EventScript_Conversation_Text_3:
	.string "We have yet to receive tidings from\n"
	.string "the Elder in Sunrise Village…$"

Silveridge_EldersHouse_EventScript_Conversation_Text_4:
	.string "Elder Iwa$"

Silveridge_EldersHouse_EventScript_Conversation_Text_5:
	.string "Let us not surrender to panic.$"

Silveridge_EldersHouse_EventScript_Conversation_Text_6:
	.string "Excuse me… Can I help you?$"

Silveridge_EldersHouse_EventScript_Conversation_Text_7:
	.string "Yes? I am Iwa, the Elder of Silveridge.\n"
	.string "What brings you to me?$"

Silveridge_EldersHouse_EventScript_Conversation_Text_8:
	.string "Give the letter$"

Silveridge_EldersHouse_EventScript_Conversation_Text_9:
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "I see…\p"
	.string "blah blah shit's fucked everywhere\n"
	.string "then\p"
	.string "Could you go investigate the decayed\n"
	.string "area in Uume Forest near Yifu City for\l"
	.string "me plz kthx$"

Silveridge_EldersHouse_EventScript_Elder_Text_0:
	.string "Go forth, my child.$"

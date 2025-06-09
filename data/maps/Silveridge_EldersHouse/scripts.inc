Silveridge_EldersHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Silveridge_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Silveridge_EldersHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Silveridge_EldersHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_TEMP_1
	return

Silveridge_EldersHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_DECAY_BEACHBOUND_ROUTE, 5, Silveridge_EldersHouse_EventScript_Conversation
	.2byte 0


Silveridge_EldersHouse_EventScript_EldersMon::
	lock
	faceplayer
	setseenmon SPECIES_LAIRON
	playmoncry SPECIES_LAIRON, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_LAIRON
	msgbox Silveridge_EldersHouse_EventScript_EldersMon_Text_0
	waitmoncry
	release
	return


Silveridge_EldersHouse_EventScript_Conversation::
	lock
	setvar VAR_DECAY_BEACHBOUND_ROUTE, 6
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
	applymovement OBJ_EVENT_ID_PLAYER, Silveridge_EldersHouse_EventScript_Conversation_Movement_2
	waitmovement 3
	removeobject 3
	playse SE_EXIT
	waitmovement 2
	removeobject 2
	playse SE_EXIT
	waitse
	setflag FLAG_GAVE_LETTER_ELDER_SILVERIDGE
	delay 48
	applymovement OBJ_EVENT_ID_PLAYER, Silveridge_EldersHouse_EventScript_Conversation_Movement_3
	waitmovement OBJ_EVENT_ID_PLAYER
	speakername Silveridge_EldersHouse_EventScript_Conversation_Text_4
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_7
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, Silveridge_EldersHouse_EventScript_Conversation_Text_8
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Silveridge_EldersHouse_EventScript_Conversation_Movement_4
	waitmovement OBJ_EVENT_ID_PLAYER
	removeitem ITEM_LETTER
	speakername Silveridge_EldersHouse_EventScript_Conversation_Text_4
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_9
	closemessage
	applymovement 1, Silveridge_EldersHouse_EventScript_Conversation_Movement_5
	waitmovement 0
	playse SE_EXIT
	clearflag FLAG_TEMP_1
	addobject 4
	waitse
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Silveridge_EldersHouse_EventScript_Conversation_Movement_6
	applymovement 1, Silveridge_EldersHouse_EventScript_Conversation_Movement_7
	waitmovement 1
	waitse
	speakername Silveridge_EldersHouse_EventScript_Conversation_Text_10
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_11
	closemessage
	applymovement 4, Silveridge_EldersHouse_EventScript_Conversation_Movement_8
	waitmovement 4
	playse SE_EXIT
	waitse
	removeobject 4
	applymovement 1, Silveridge_EldersHouse_EventScript_Conversation_Movement_9
	waitmovement 1
	applymovement OBJ_EVENT_ID_PLAYER, Silveridge_EldersHouse_EventScript_Conversation_Movement_10
	speakername Silveridge_EldersHouse_EventScript_Conversation_Text_4
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_12
	closemessage
	applymovement 1, Silveridge_EldersHouse_EventScript_Conversation_Movement_11
	waitmovement 1
	applymovement OBJ_EVENT_ID_PLAYER, Silveridge_EldersHouse_EventScript_Conversation_Movement_12
	waitmovement OBJ_EVENT_ID_PLAYER
	giveitem ITEM_EXP_SHARE
	applymovement 1, Silveridge_EldersHouse_EventScript_Conversation_Movement_9
	waitmovement 1
	speakername Silveridge_EldersHouse_EventScript_Conversation_Text_4
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_13
	closemessage
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
	delay_16
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_3:
	walk_right
	walk_up
	walk_up
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_4:
	walk_up
	delay_16
	walk_down
	face_up
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_5:
	walk_slow_left
	walk_slow_right
	walk_slow_right
	walk_slow_left
	delay_16
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_6:
	face_down
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_7:
	face_down
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_8:
	delay_16
	walk_in_place_fast_down
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_9:
	walk_in_place_fast_down
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_10:
	walk_in_place_fast_up
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_11:
	walk_slow_right
	walk_slow_right
	walk_in_place_fast_up
	delay_16
	delay_16
	walk_slow_left
	walk_slow_left
	walk_in_place_fast_down
	delay_16
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_12:
	walk_up
	step_end

Silveridge_EldersHouse_EventScript_EldersMon_Text_0:
	.string "Ghurrr!$"

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
	.string "Ah! The letter I was expecting from\n"
	.string "Kaba…\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "I see…\p"
	.string "The wild Pokémon are in a frenzy all\n"
	.string "the way down to the Ginko Woods as\l"
	.string "well…\p"
	.string "The phenomenon has thus been\n"
	.string "confirmed to be happening across the\l"
	.string "whole Toku region!\p"
	.string "It must be somehow connected to the\n"
	.string "spreading Decay - and to the rumbling\l"
	.string "of Mt Kazan!\p"
	.string "The situation is more dire than we\n"
	.string "thought, and our strongest Wielders\l"
	.string "are already stretched thin.\p"
	.string "What to do, what to do…$"

Silveridge_EldersHouse_EventScript_Conversation_Text_10:
	.string "Girl$"

Silveridge_EldersHouse_EventScript_Conversation_Text_11:
	.string "Elder Iwa! Elder Iwa!\p"
	.string "A Chatot just got in! Some Decay was\n"
	.string "discovered in Uume Forest!$"

Silveridge_EldersHouse_EventScript_Conversation_Text_12:
	.string "We cannot lose a second! We need\n"
	.string "someone to go investigate Uume\l"
	.string "Forest right now!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Young one from Sunrise Village.\n"
	.string "What is your name? {PLAYER}?\p"
	.string "You came all the way up here\n"
	.string "on foot…\l"
	.string "You already have a team of capable\l"
	.string "Pokémon…\l"
	.string "Kaba has trusted you with this\l"
	.string "delivery…\p"
	.string "It is decided! You shall travel to\n"
	.string "Uume Forest, southeast of Tranquil\l"
	.string "Route!\p"
	.string "Our fate may well be in your hands,\n"
	.string "{PLAYER}.\p"
	.string "Before you leave, let me give you\n"
	.string "something to make your journey\l"
	.string "easier.$"

Silveridge_EldersHouse_EventScript_Conversation_Text_13:
	.string "I have been keeping this mysterious\n"
	.string "ancient relic for years.\p"
	.string "We aren't sure where nor when it\n"
	.string "originated, but it lets one Pokémon\l"
	.string "mirror the experience of another.\p"
	.string "It should be immensely useful in the\n"
	.string "hands of a promising young Wielder\l"
	.string "such as yourself.\p"
	.string "Now go, and be quick!$"

Silveridge_EldersHouse_EventScript_Elder_Text_0:
	.string "Go forth, young one.$"

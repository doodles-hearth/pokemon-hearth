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
	setspeaker SP_NAME_OLD_MAN
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_0
	closemessage
	applymovement 3, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	setspeaker SP_NAME_OLD_LADY
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_1
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setspeaker SP_NAME_ELDER_IWA
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_2
	closemessage
	playse SE_PIN
	applymovement 1, Silveridge_EldersHouse_EventScript_Conversation_Movement_0
	waitse
	waitmovement 0
	setspeaker SP_NAME_ELDER_IWA
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_3
	closemessage
	applymovement 3, Common_Movement_FaceDown
	applymovement 2, Common_Movement_FaceDown
	waitmovement 3
	waitmovement 2
	delay 48
	delay 48
	applymovement 3, Silveridge_EldersHouse_EventScript_Conversation_Movement_1
	applymovement 2, Silveridge_EldersHouse_EventScript_Conversation_Movement_2
	applymovement OBJ_EVENT_ID_PLAYER, Silveridge_EldersHouse_EventScript_Conversation_Movement_3
	waitmovement 3
	removeobject 3
	playse SE_EXIT
	waitmovement 2
	removeobject 2
	playse SE_EXIT
	waitse
	setflag FLAG_GAVE_LETTER_ELDER_SILVERIDGE
	delay 48
	applymovement OBJ_EVENT_ID_PLAYER, Silveridge_EldersHouse_EventScript_Conversation_Movement_4
	waitmovement OBJ_EVENT_ID_PLAYER
	setspeaker SP_NAME_ELDER_IWA
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_4
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, Silveridge_EldersHouse_EventScript_Conversation_Text_5
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Silveridge_EldersHouse_EventScript_Conversation_Movement_5
	waitmovement OBJ_EVENT_ID_PLAYER
	removeitem ITEM_LETTER
	setspeaker SP_NAME_ELDER_IWA
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_6
	playse SE_PIN
	applymovement 1, Silveridge_EldersHouse_EventScript_Conversation_Movement_6
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_7
	closemessage
	applymovement 1, Silveridge_EldersHouse_EventScript_Conversation_Movement_7
	waitmovement 0
	applymovement 1, Silveridge_EldersHouse_EventScript_Conversation_Movement_8
	waitmovement 0
	clearflag FLAG_TEMP_1
	addobject 4
	playse SE_EXIT
	waitse
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Silveridge_EldersHouse_EventScript_Conversation_Movement_9
	applymovement 1, Silveridge_EldersHouse_EventScript_Conversation_Movement_10
	waitmovement 1
	waitse
	playse SE_PIN
	applymovement 4, Silveridge_EldersHouse_EventScript_Conversation_Movement_11
	setspeaker SP_NAME_GIRL
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_8
	closemessage
	applymovement 4, Silveridge_EldersHouse_EventScript_Conversation_Movement_12
	waitmovement 4
	removeobject 4
	playse SE_EXIT
	waitse
	delay 48
	applymovement 1, Silveridge_EldersHouse_EventScript_Conversation_Movement_13
	waitmovement 1
	applymovement OBJ_EVENT_ID_PLAYER, Silveridge_EldersHouse_EventScript_Conversation_Movement_14
	setspeaker SP_NAME_ELDER_IWA
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_9
	playse SE_PIN
	applymovement 1, Silveridge_EldersHouse_EventScript_Conversation_Movement_6
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_10
	closemessage
	applymovement 1, Silveridge_EldersHouse_EventScript_Conversation_Movement_15
	waitmovement 1
	applymovement OBJ_EVENT_ID_PLAYER, Silveridge_EldersHouse_EventScript_Conversation_Movement_16
	waitmovement OBJ_EVENT_ID_PLAYER
	giveitem ITEM_EXP_SHARE
	applymovement 1, Silveridge_EldersHouse_EventScript_Conversation_Movement_13
	waitmovement 1
	setspeaker SP_NAME_ELDER_IWA
	msgbox Silveridge_EldersHouse_EventScript_Conversation_Text_11
	closemessage
	clearflag FLAG_KURA_DOJO_CLOSED
	setflag FLAG_HIDE_BONSAI_SHOP_OWNER
	release
	return


Silveridge_EldersHouse_EventScript_Elder::
	lock
	faceplayer
	setspeaker SP_NAME_ELDER_IWA
	msgbox Silveridge_EldersHouse_EventScript_Elder_Text_0
	closemessage
	release
	return


Silveridge_EldersHouse_EventScript_Conversation_Movement_0:
	emote_question_mark
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_1:
	walk_down
	walk_down
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_2:
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_3:
	delay_16
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_4:
	walk_right
	walk_up
	walk_up
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_5:
	walk_up
	delay_16
	walk_down
	face_up
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_6:
	emote_pensive
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_7:
	walk_slow_left
	walk_slow_right
	walk_slow_right
	walk_slow_left
	delay_16
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_8:
	emote_pensive
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_9:
	face_down
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_10:
	face_down
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_11:
	emote_sad
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_12:
	delay_16
	walk_in_place_fast_down
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_13:
	walk_in_place_fast_down
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_14:
	walk_in_place_fast_up
	step_end

Silveridge_EldersHouse_EventScript_Conversation_Movement_15:
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

Silveridge_EldersHouse_EventScript_Conversation_Movement_16:
	walk_up
	step_end

Silveridge_EldersHouse_EventScript_EldersMon_Text_0:
	.string "Ghurrr!$"

Silveridge_EldersHouse_EventScript_Conversation_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_MOUNTAIN_OLD_MAN EMOTE_NORMAL}Yet another area is decaying on\n"
	.string "Beachbound Route…$"

Silveridge_EldersHouse_EventScript_Conversation_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_MOUNTAIN_OLD_WOMAN EMOTE_NORMAL}We have yet to receive tidings from\n"
	.string "the Elder in Sunrise Village…$"

Silveridge_EldersHouse_EventScript_Conversation_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_IWA EMOTE_NORMAL}Let us not surrender to panic.$"

Silveridge_EldersHouse_EventScript_Conversation_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_IWA EMOTE_NORMAL}Excuse me… Can I help you?$"

Silveridge_EldersHouse_EventScript_Conversation_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_IWA EMOTE_NORMAL}Yes? I am Iwa, the Elder of Silveridge.\n"
	.string "What brings you to me?$"

Silveridge_EldersHouse_EventScript_Conversation_Text_5:
	.string "Give the letter$"

Silveridge_EldersHouse_EventScript_Conversation_Text_6:
	.string "{CREATE_MUGSHOT MUGSHOT_IWA EMOTE_NORMAL}Ah! The letter I was expecting from\n"
	.string "Kaba…!$"

Silveridge_EldersHouse_EventScript_Conversation_Text_7:
	.string "{CREATE_MUGSHOT MUGSHOT_IWA EMOTE_NORMAL}… … … … … …\n"
	.string "… … … … … …\p"
	.string "I see…\p"
	.string "Wild Pokémon are in a frenzy all the\n"
	.string "way down to Ginko Woods as well…\p"
	.string "So the phenomenon is happening\n"
	.string "across the whole Toku region!\p"
	.string "It must be linked to the spreading\n"
	.string "Decay - and to Mt Kazan's fits!\p"
	.string "The situation is more dire than we\n"
	.string "thought, and our strongest Wielders\l"
	.string "are already stretched thin.\p"
	.string "What to do, what to do…$"

Silveridge_EldersHouse_EventScript_Conversation_Text_8:
	.string "{CREATE_MUGSHOT MUGSHOT_MOUNTAIN_GIRL_2 EMOTE_NORMAL}Elder Iwa! Elder Iwa!\p"
	.string "A Chatot just got in! Some Decay was\n"
	.string "discovered in Uume Forest!$"

Silveridge_EldersHouse_EventScript_Conversation_Text_9:
	.string "{CREATE_MUGSHOT MUGSHOT_IWA EMOTE_NORMAL}We cannot lose a second! We need to\n"
	.string "investigate Uume Forest right now!$"

Silveridge_EldersHouse_EventScript_Conversation_Text_10:
	.string "{CREATE_MUGSHOT MUGSHOT_IWA EMOTE_NORMAL}… … … … … …\n"
	.string "… … … … … …\p"
	.string "Young one from Sunrise Village.\n"
	.string "What is your name? {PLAYER}?\p"
	.string "You came all the way up here\n"
	.string "on foot…\l"
	.string "You have a team of capable Pokémon…\l"
	.string "Kaba seems to trust you…\p"
	.string "It is decided! Travel to Uume Forest,\n"
	.string "southeast of Tranquil Route!\p"
	.string "Our fate may well be in your hands,\n"
	.string "{PLAYER}.\p"
	.string "Before you leave, I have something\n"
	.string "that will make your journey easier.$"

Silveridge_EldersHouse_EventScript_Conversation_Text_11:
	.string "{CREATE_MUGSHOT MUGSHOT_IWA EMOTE_NORMAL}I have been keeping this mysterious\n"
	.string "ancient relic for years.\p"
	.string "We aren't sure where nor when it\n"
	.string "originated, but it lets one Pokémon\l"
	.string "mirror the experience of another.\p"
	.string "It should be useful in the hands of\n"
	.string "such a promising young Wielder.\p"
	.string "Now go, and be swift!$"

Silveridge_EldersHouse_EventScript_Elder_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_IWA EMOTE_NORMAL}Go forth, young one. To Uume Forest,\n"
	.string "southeast of Tranquil Route!$"

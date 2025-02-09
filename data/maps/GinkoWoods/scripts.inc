GinkoWoods_MapScripts::
	.byte 0


GinkoWoods_EventScript_Toshiki::
	trainerbattle_single TRAINER_TOSHIKI, GinkoWoods_EventScript_Toshiki_Text_0, GinkoWoods_EventScript_Toshiki_Text_1
	speakername GinkoWoods_EventScript_Toshiki_Text_2
	msgbox GinkoWoods_EventScript_Toshiki_Text_3
	closemessage
	release
	end


GinkoWoods_EventScript_Toshio::
	trainerbattle_single TRAINER_TOSHIO_1, GinkoWoods_EventScript_Toshio_Text_0, GinkoWoods_EventScript_Toshio_Text_1
	speakername GinkoWoods_EventScript_Toshio_Text_2
	msgbox GinkoWoods_EventScript_Toshio_Text_3
	release
	end


GinkoWoods_EventScript_Eiji::
	trainerbattle_single TRAINER_EIJI, GinkoWoods_EventScript_Eiji_Text_0, GinkoWoods_EventScript_Eiji_Text_1
	speakername GinkoWoods_EventScript_Eiji_Text_2
	msgbox GinkoWoods_EventScript_Eiji_Text_3
	release
	end


GinkoWoods_EventScript_OldMan::
	lock
	faceplayer
	speakername GinkoWoods_EventScript_OldMan_Text_0
	msgbox GinkoWoods_EventScript_OldMan_Text_1
	release
	end


GinkoWoods_EventScript_Bean::
	lock
	faceplayer
	speakername GinkoWoods_EventScript_Bean_Text_0
	msgbox GinkoWoods_EventScript_Bean_Text_1
	closemessage
	delay 48
	turnobject 7, DIR_EAST
	speakername GinkoWoods_EventScript_Bean_Text_0
	msgbox GinkoWoods_EventScript_Bean_Text_2
	closemessage
	turnobject 7, DIR_SOUTH
	delay 48
	speakername GinkoWoods_EventScript_Bean_Text_0
	msgbox GinkoWoods_EventScript_Bean_Text_3
	closemessage
	fadescreen FADE_TO_BLACK
	addtime 0, 1, 30
	delay 60
	fadescreen FADE_FROM_BLACK
	delay 48
	speakername GinkoWoods_EventScript_Bean_Text_0
	msgbox GinkoWoods_EventScript_Bean_Text_4
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, GinkoWoods_EventScript_Bean_Text_5, GinkoWoods_EventScript_Bean_Text_6, GinkoWoods_EventScript_Bean_Text_7
	closemessage
	speakername GinkoWoods_EventScript_Bean_Text_8
	switch VAR_RESULT
	case 0, GinkoWoods_EventScript_Bean_3
	case 1, GinkoWoods_EventScript_Bean_4
	case 2, GinkoWoods_EventScript_Bean_5
GinkoWoods_EventScript_Bean_1:
	closemessage
	applymovement 7, GinkoWoods_Movement_BeanWalksAway
	waitmovement 0
	removeobject 7
	setflag FLAG_HIDE_BEAN_GINKO_WOODS
	release
	return

GinkoWoods_EventScript_Bean_3:
	msgbox GinkoWoods_EventScript_Bean_Text_9
	goto GinkoWoods_EventScript_Bean_1

GinkoWoods_EventScript_Bean_4:
	msgbox GinkoWoods_EventScript_Bean_Text_10
	goto GinkoWoods_EventScript_Bean_1

GinkoWoods_EventScript_Bean_5:
	msgbox GinkoWoods_EventScript_Bean_Text_11
	goto GinkoWoods_EventScript_Bean_1


GinkoWoods_Movement_BeanWalksAway:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

GinkoWoods_EventScript_Tracks::
	lock
	playse SE_PIN
	applymovement 7, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	delay 48
	applymovement 7, Common_Movement_WalkInPlaceFasterRight
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox GinkoWoods_EventScript_Tracks_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, GinkoWoods_Movement_PlayerWalkDown
	waitmovement 0
	release
	return


GinkoWoods_Movement_PlayerWalkDown:
	walk_down
	step_end

GinkoWoods_EventScript_TrainerTips1::
	msgbox GinkoWoods_EventScript_TrainerTips1_Text_0, MSGBOX_SIGN
	return


GinkoWoods_EventScript_TrainerTips2::
	msgbox GinkoWoods_EventScript_TrainerTips2_Text_0, MSGBOX_SIGN
	return


GinkoWoods_EventScript_Toshiki_Text_0:
	.string "These bugs are electrifying!$"

GinkoWoods_EventScript_Toshiki_Text_1:
	.string "Ouch! How did you do that?$"

GinkoWoods_EventScript_Toshiki_Text_2:
	.string "Toshiki$"

GinkoWoods_EventScript_Toshiki_Text_3:
	.string "Isn't Sewaddle cute, all wrapped up in\n"
	.string "its leaf?$"

GinkoWoods_EventScript_Toshio_Text_0:
	.string "Our eyes met! Therefore we must\n"
	.string "battle!$"

GinkoWoods_EventScript_Toshio_Text_1:
	.string "Should have kept my mouth shut…$"

GinkoWoods_EventScript_Toshio_Text_2:
	.string "Toshio$"

GinkoWoods_EventScript_Toshio_Text_3:
	.string "Real wielders fight when they spot\n"
	.string "each other!\p"
	.string "At least that's what my dad told me…$"

GinkoWoods_EventScript_Eiji_Text_0:
	.string "With the help of my brand-new\n"
	.string "Pokémon, I'm catching all sort of\l"
	.string "bugs!$"

GinkoWoods_EventScript_Eiji_Text_1:
	.string "My bugs!$"

GinkoWoods_EventScript_Eiji_Text_2:
	.string "Eiji$"

GinkoWoods_EventScript_Eiji_Text_3:
	.string "I asked Elder Kaba for a bird Pokémon,\n"
	.string "because they're strong against bugs!$"

GinkoWoods_EventScript_OldMan_Text_0:
	.string "Old man$"

GinkoWoods_EventScript_OldMan_Text_1:
	.string "These woods are fascinating.\p"
	.string "There seem to be a lot of yellow\n"
	.string "Pokémon here.$"

GinkoWoods_EventScript_Bean_Text_0:
	.string "Odd girl$"

GinkoWoods_EventScript_Bean_Text_1:
	.string "Hello!$"

GinkoWoods_EventScript_Bean_Text_2:
	.string "I just noticed there are some neat\n"
	.string "tracks in the dirt here.$"

GinkoWoods_EventScript_Bean_Text_3:
	.string "It looks like a small mammal's\n"
	.string "footprints, see?\p"
	.string "Studying Pokémon tracks is so\n"
	.string "fascinating. One can find out about a\l"
	.string "Pokémon's nesting place, their\l"
	.string "hunting habits, at what time they\l"
	.string "sleep, what they eat… Interesting,\l"
	.string "isn't it?\p"
	.string "These woods host a lot of yellow\n"
	.string "Pokémon, so I'd bet these are a\l"
	.string "Pikachu's, or a Kotora's. Do you know\l"
	.string "why there's a lot of yellow Pokémon\l"
	.string "here? Well, that's because smaller\l"
	.string "Pokémon can easily hide from\l"
	.string "predators in the foliage, and said\l"
	.string "predators can stalk their prey\l"
	.string "without being seen. Additionally, the\l"
	.string "high concentration of electric-type\l"
	.string "Pokémon, which seems to have\l"
	.string "happened fortuitously, explains the\l"
	.string "unnaturally high static electricity in\l"
	.string "the air here. Some of the non-electric\l"
	.string "Pokémon that live here have adapted\l"
	.string "by developing specific traits, like\l"
	.string "the Sewaddle you've probably seen on\l"
	.string "your way here that blah, blah blah\l"
	.string "blah blah, blah blah…$"

GinkoWoods_EventScript_Bean_Text_4:
	.string "…And that's all that is currently\n"
	.string "known about Joltik's habitat during\l"
	.string "the winter.\p"
	.string "Neat, isn't it?$"

GinkoWoods_EventScript_Bean_Text_5:
	.string "… …Yes?$"

GinkoWoods_EventScript_Bean_Text_6:
	.string "Do I know you?$"

GinkoWoods_EventScript_Bean_Text_7:
	.string "I was just passing through…$"

GinkoWoods_EventScript_Bean_Text_8:
	.string "Hariko$"

GinkoWoods_EventScript_Bean_Text_9:
	.string "Right! I am glad you share my interest\n"
	.string "in Pokémon habitat.\p"
	.string "I am Hariko. And what is your name?\p"
	.string "{PLAYER}. It has been nice chatting\n"
	.string "with you. I will see you around, then.\p"
	.string "Okay, bye!$"

GinkoWoods_EventScript_Bean_Text_10:
	.string "Right! I haven't introduced myself\n"
	.string "yet.\p"
	.string "I am Hariko. And what is your name?\p"
	.string "{PLAYER}. It has been nice chatting\n"
	.string "with you. I will see you around, then.\p"
	.string "Okay, bye!$"

GinkoWoods_EventScript_Bean_Text_11:
	.string "…Oh. I am blocking your path. I see.\p"
	.string "I guess I got carried away, have I\n"
	.string "not? That… tends to happen.\p"
	.string "I am Hariko. And what is your name?\p"
	.string "{PLAYER}. It has been nice chatting\n"
	.string "with you. I am moving now, so that you\l"
	.string "can go through.\p"
	.string "I will see you around, then.\p"
	.string "Okay, bye!$"

GinkoWoods_EventScript_Tracks_Text_0:
	.string "THE TRACKS!! YOU'RE STEPPING ON\n"
	.string "THEM!!!$"

GinkoWoods_EventScript_TrainerTips1_Text_0:
	.string "Did you know?\p"
	.string "Some items can be hidden under the\n"
	.string "forest's thick canopy. Look around!$"

GinkoWoods_EventScript_TrainerTips2_Text_0:
	.string "Did you know?\p"
	.string "You can sort the contents of your\n"
	.string "bag by pressing START.$"

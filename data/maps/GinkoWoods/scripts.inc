GinkoWoods_MapScripts::
	.byte 0


GinkoWoods_EventScript_Toshiki::
	trainerbattle_single TRAINER_TOSHIKI, GinkoWoods_EventScript_Toshiki_Text_0, GinkoWoods_EventScript_Toshiki_Text_1
	setspeaker SP_NAME_BUGCATCHER
	msgbox GinkoWoods_EventScript_Toshiki_Text_2
	closemessage
	setnamedmon SPECIES_SEWADDLE_TOKUAN
	release
	end


GinkoWoods_EventScript_Toshio::
	trainerbattle_single TRAINER_TOSHIO_1, GinkoWoods_EventScript_Toshio_Text_0, GinkoWoods_EventScript_Toshio_Text_1, GinkoWoods_EventScript_Toshio_Register
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 0
	goto_if_ne GinkoWoods_EventScript_Toshio_2
GinkoWoods_EventScript_Toshio_1:
	msgbox GinkoWoods_EventScript_Toshio_Text_4
	closemessage
	release
	return

GinkoWoods_EventScript_Toshio_2:
	trainerbattle_rematch TRAINER_TOSHIO_1, GinkoWoods_EventScript_Toshio_Text_2, GinkoWoods_EventScript_Toshio_Text_3
	goto GinkoWoods_EventScript_Toshio_1


GinkoWoods_EventScript_Toshio_Register:
	msgbox GinkoWoods_EventScript_Toshio_Register_Text_0
	closemessage
	register_matchcall TRAINER_TOSHIO_1
	return


GinkoWoods_EventScript_Eiji::
	trainerbattle_single TRAINER_EIJI, GinkoWoods_EventScript_Eiji_Text_0, GinkoWoods_EventScript_Eiji_Text_1
	setspeaker SP_NAME_BUGCATCHER
	msgbox GinkoWoods_EventScript_Eiji_Text_2
	release
	end


GinkoWoods_EventScript_OldMan::
	lock
	faceplayer
	playse SE_PIN
	applymovement VAR_LAST_TALKED, GinkoWoods_EventScript_OldMan_Movement_0
	setspeaker SP_NAME_OLD_MAN
	msgbox GinkoWoods_EventScript_OldMan_Text_0
	release
	end


GinkoWoods_EventScript_Bean::
	lock
	waitse
	playse SE_PIN
	applymovement VAR_LAST_TALKED, GinkoWoods_EventScript_Bean_Movement_0
	waitmovement VAR_LAST_TALKED
	faceplayer
	setspeaker GinkoWoods_EventScript_Bean_Text_0
	msgbox GinkoWoods_EventScript_Bean_Text_1
	closemessage
	delay 48
	turnobject 7, DIR_EAST
	setspeaker GinkoWoods_EventScript_Bean_Text_0
	msgbox GinkoWoods_EventScript_Bean_Text_2
	closemessage
	turnobject 7, DIR_SOUTH
	delay 48
	setspeaker GinkoWoods_EventScript_Bean_Text_0
	msgbox GinkoWoods_EventScript_Bean_Text_3
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	addtime 0, 1, 30
	delay 60
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 48
	setspeaker GinkoWoods_EventScript_Bean_Text_0
	msgbox GinkoWoods_EventScript_Bean_Text_4
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, GinkoWoods_EventScript_Bean_Text_5, GinkoWoods_EventScript_Bean_Text_6, GinkoWoods_EventScript_Bean_Text_7
	closemessage
	setspeaker SP_NAME_HARIKO
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
	setnamedmon SPECIES_JOLTIK
	setnamedmon SPECIES_KOTORA
	setnamedmon SPECIES_SEWADDLE
	setdescribedmon SPECIES_SEWADDLE_TOKUAN
	release
	return

GinkoWoods_EventScript_Bean_3:
	msgbox GinkoWoods_EventScript_Bean_Text_8
	goto GinkoWoods_EventScript_Bean_1

GinkoWoods_EventScript_Bean_4:
	msgbox GinkoWoods_EventScript_Bean_Text_9
	goto GinkoWoods_EventScript_Bean_1

GinkoWoods_EventScript_Bean_5:
	playse SE_PIN
	applymovement VAR_LAST_TALKED, GinkoWoods_EventScript_OldMan_Movement_0
	msgbox GinkoWoods_EventScript_Bean_Text_10
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
	applymovement VAR_LAST_TALKED, GinkoWoods_EventScript_Tracks_Movement_0
	setspeaker GinkoWoods_EventScript_Bean_Text_0
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


GinkoWoods_EventScript_OldMan_Movement_0:
	emote_pensive
	step_end

GinkoWoods_EventScript_Bean_Movement_0:
	emote_music
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

GinkoWoods_EventScript_Tracks_Movement_0:
	emote_upset
	step_end

GinkoWoods_EventScript_Toshiki_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_BUG_CATCHER EMOTE_NORMAL}These bugs are electrifying!$"

GinkoWoods_EventScript_Toshiki_Text_1:
	.string "Ouch! How did you do that?$"

GinkoWoods_EventScript_Toshiki_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_BUG_CATCHER EMOTE_NORMAL}Isn't Sewaddle cute, all wrapped up in\n"
	.string "its leaf?$"

GinkoWoods_EventScript_Toshio_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_YOUNGSTER EMOTE_NORMAL}Our eyes met! Therefore we must\n"
	.string "battle!$"

GinkoWoods_EventScript_Toshio_Text_1:
	.string "Should have kept my mouth shut…$"

GinkoWoods_EventScript_Toshio_Text_2:
	.string "Let's fight again!$"

GinkoWoods_EventScript_Toshio_Text_3:
	.string "I lost again?!$"

GinkoWoods_EventScript_Toshio_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_YOUNGSTER EMOTE_NORMAL}{SPEAKER NAME_YOUNGSTER}Real Wielders fight when they spot\n"
	.string "each other!\p"
	.string "At least that's what my dad told me…$"

GinkoWoods_EventScript_Toshio_Register_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_YOUNGSTER EMOTE_NORMAL}{SPEAKER NAME_YOUNGSTER}Hey, let's be friends!\n"
	.string "We'll send each other Chatot mail,\l"
	.string "and battle again sometime!$"

GinkoWoods_EventScript_Eiji_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_BUG_CATCHER EMOTE_NORMAL}With my brand new Pokémon, I'm\n"
	.string "catching all sorts of bugs!$"

GinkoWoods_EventScript_Eiji_Text_1:
	.string "My bugs!$"

GinkoWoods_EventScript_Eiji_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_BUG_CATCHER EMOTE_NORMAL}I asked Elder Kaba for a bird Pokémon,\n"
	.string "because they're strong against bugs!$"

GinkoWoods_EventScript_OldMan_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_OLD_MAN EMOTE_NORMAL}These woods are fascinating.\p"
	.string "There seem to be a lot of yellow\n"
	.string "Pokémon here.$"

GinkoWoods_EventScript_Bean_Text_0:
	.string "Odd Girl$"

GinkoWoods_EventScript_Bean_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}Hello!$"

GinkoWoods_EventScript_Bean_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}I just noticed there are some neat\n"
	.string "tracks in the dirt here.$"

GinkoWoods_EventScript_Bean_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}It looks like a small mammal's\n"
	.string "footprints, see?\p"
	.string "Studying Pokémon tracks is so\n"
	.string "fascinating. One can find out about a\l"
	.string "Pokémon's nesting place, their\l"
	.string "hunting habits, at what time they\l"
	.string "sleep, what they eat… Interesting,\l"
	.string "isn't it?\p"
	.string "These woods host a lot of yellow\n"
	.string "Pokémon, so I'd bet these are a\l"
	.string "Kotora's. Do you know why there's a\l"
	.string "lot of yellow Pokémon here? Well,\l"
	.string "that's because smaller Pokémon can\l"
	.string "easily hide from predators in the\l"
	.string "foliage, and said predators can stalk\l"
	.string "their prey without being seen.\l"
	.string "Additionally, the high concentration\l"
	.string "of electric-type Pokémon, which\l"
	.string "seems to have happened fortuitously,\l"
	.string "explains the unnaturally high static\l"
	.string "electricity in the air here. Some of\l"
	.string "the non-electric Pokémon that live\l"
	.string "here have adapted by developing\l"
	.string "specific traits, like the Sewaddle\l"
	.string "you've probably seen on your way here\l"
	.string "that blah, blah blah blah blah, blah\l"
	.string "blah…$"

GinkoWoods_EventScript_Bean_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}…And that's all that is currently\n"
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
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}Right! I am glad you share my interest\n"
	.string "in Pokémon habitats.\p"
	.string "I am Hariko. And what is your name?\p"
	.string "{PLAYER}.\n"
	.string "It has been nice chatting with you.\l"
	.string "I will see you around, then.\p"
	.string "Okay. Bye!$"

GinkoWoods_EventScript_Bean_Text_9:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}Right!\n"
	.string "I haven't introduced myself yet.\p"
	.string "I am Hariko. And what is your name?\p"
	.string "{PLAYER}.\n"
	.string "It has been nice chatting with you.\l"
	.string "I will see you around, then.\p"
	.string "Okay. Bye!$"

GinkoWoods_EventScript_Bean_Text_10:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}…Oh. I am blocking your path. I see.\p"
	.string "I got carried away, have I not?\n"
	.string "That… tends to happen.\p"
	.string "I am Hariko. And what is your name?\p"
	.string "{PLAYER}.\n"
	.string "It has been nice chatting with you.\l"
	.string "I am moving now, so that you can go\l"
	.string "through.\p"
	.string "I will see you around.{PAUSE 8}\n"
	.string "Okay. Bye!$"

GinkoWoods_EventScript_Tracks_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}THE TRACKS!!\n"
	.string "YOU'RE STEPPING ON THEM!!!$"

GinkoWoods_EventScript_TrainerTips1_Text_0:
	.string "Did you know?\p"
	.string "Some items can be hidden under the\n"
	.string "forest's thick canopy.\l"
	.string "Look around!$"

GinkoWoods_EventScript_TrainerTips2_Text_0:
	.string "Did you know?\p"
	.string "You can sort the contents of your\n"
	.string "bag by pressing {START_BUTTON}.$"

SunriseVillage_Beach_MapScripts::
	.byte 0


SunriseVillage_Beach_EventScript_RivalSpeech::
	lock
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	faceplayer
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_1
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, SunriseVillage_Beach_EventScript_RivalSpeech_3
	case DIR_NORTH, SunriseVillage_Beach_EventScript_RivalSpeech_4
	case DIR_WEST, SunriseVillage_Beach_EventScript_RivalSpeech_5
	case DIR_EAST, SunriseVillage_Beach_EventScript_RivalSpeech_6
SunriseVillage_Beach_EventScript_RivalSpeech_1:
	waitmovement 0
	applymovement 1, SunriseVillage_Beach_Movement_RivalSitsOnBench
	waitmovement 0
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_2
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SunriseVillage_Beach_EventScript_RivalSpeech_Text_3, SunriseVillage_Beach_EventScript_RivalSpeech_Text_4
	closemessage
	switch VAR_RESULT
	case 0, SunriseVillage_Beach_EventScript_RivalSpeech_9
	case 1, SunriseVillage_Beach_EventScript_RivalSpeech_10
SunriseVillage_Beach_EventScript_RivalSpeech_7:
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SunriseVillage_Beach_EventScript_RivalSpeech_Text_10, SunriseVillage_Beach_EventScript_RivalSpeech_Text_11, SunriseVillage_Beach_EventScript_RivalSpeech_Text_12
	closemessage
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
	switch VAR_RESULT
	case 0, SunriseVillage_Beach_EventScript_RivalSpeech_13
	case 1, SunriseVillage_Beach_EventScript_RivalSpeech_14
	case 2, SunriseVillage_Beach_EventScript_RivalSpeech_15
SunriseVillage_Beach_EventScript_RivalSpeech_11:
	closemessage
	delay 48
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 20
	setvar VAR_0x8007, 5
	special ShakeCamera
	delay 16
	playse SE_PIN
	applymovement 1, SunriseVillage_Beach_Movement_RivalSurprisedByQuake
	delay 16
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Beach_Movement_PlayerSurprisedByQuake
	waitstate
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement 1
	delay 48
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement 1, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_16
	closemessage
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	applymovement 1, SunriseVillage_Beach_Movement_RivalSeesDistribution
	waitmovement 0
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_17
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement 1, SunriseVillage_Beach_Movement_RivalRaces
	waitmovement 0
	setflag FLAG_HIDE_SUNRISE_BEACH_RIVAL
	clearflag FLAG_HIDE_SUNRISE_VILLAGE_STANDARD_NPC_POSITIONS
	clearflag FLAG_HIDE_BIGSIS_HOME
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 4
	removeobject 1
	release
	end

SunriseVillage_Beach_EventScript_RivalSpeech_3:
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Beach_Movement_GoNextToRivalFromTop
	goto SunriseVillage_Beach_EventScript_RivalSpeech_1

SunriseVillage_Beach_EventScript_RivalSpeech_4:
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Beach_Movement_GoNextToRivalFromBottom
	goto SunriseVillage_Beach_EventScript_RivalSpeech_1

SunriseVillage_Beach_EventScript_RivalSpeech_5:
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Beach_Movement_GoNextToRivalFromRight
	goto SunriseVillage_Beach_EventScript_RivalSpeech_1

SunriseVillage_Beach_EventScript_RivalSpeech_6:
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Beach_Movement_GoNextToRivalFromLeft
	goto SunriseVillage_Beach_EventScript_RivalSpeech_1

SunriseVillage_Beach_EventScript_RivalSpeech_9:
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_5
	closemessage
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_6
	closemessage
	delay 48
	applymovement 1, Common_Movement_WalkInPlaceFasterUp
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_7
	goto SunriseVillage_Beach_EventScript_RivalSpeech_7

SunriseVillage_Beach_EventScript_RivalSpeech_10:
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_8
	closemessage
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_6
	closemessage
	delay 48
	applymovement 1, Common_Movement_WalkInPlaceFasterUp
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	speakername SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_9
	goto SunriseVillage_Beach_EventScript_RivalSpeech_7

SunriseVillage_Beach_EventScript_RivalSpeech_13:
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_13
	goto SunriseVillage_Beach_EventScript_RivalSpeech_11

SunriseVillage_Beach_EventScript_RivalSpeech_14:
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_14
	goto SunriseVillage_Beach_EventScript_RivalSpeech_11

SunriseVillage_Beach_EventScript_RivalSpeech_15:
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_15
	goto SunriseVillage_Beach_EventScript_RivalSpeech_11


SunriseVillage_Beach_Movement_PlayerSurprisedByQuake:
	emote_exclamation_mark
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	face_right
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	face_up
	step_end

SunriseVillage_Beach_Movement_RivalSurprisedByQuake:
	emote_exclamation_mark
	delay_16
	face_down
	delay_16
	face_up
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	face_down
	step_end

SunriseVillage_Beach_EventScript_Corsola::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CORSOLA, CRY_MODE_NORMAL
	msgbox SunriseVillage_Beach_EventScript_Corsola_Text_0
	waitmoncry
	release
	end


SunriseVillage_Beach_EventScript_Corsola2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CORSOLA, CRY_MODE_WEAK
	msgbox SunriseVillage_Beach_EventScript_Corsola2_Text_0
	waitmoncry
	release
	end


SunriseVillage_Beach_Movement_RivalSitsOnBench:
	walk_in_place_faster_left
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

SunriseVillage_Beach_Movement_GoNextToRivalFromLeft:
	walk_up
	walk_right
	walk_in_place_faster_left
	step_end

SunriseVillage_Beach_Movement_GoNextToRivalFromTop:
	walk_in_place_faster_left
	step_end

SunriseVillage_Beach_Movement_GoNextToRivalFromRight:
	walk_up
	walk_left
	step_end

SunriseVillage_Beach_Movement_GoNextToRivalFromBottom:
	walk_right
	walk_up
	walk_up
	walk_left
	step_end

SunriseVillage_Beach_Movement_RivalSeesDistribution:
	face_right
	delay_16
	delay_16
	delay_16
	face_player
	step_end

SunriseVillage_Beach_Movement_RivalRaces:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SunriseVillage_Beach_EventScript_RivalSpeech_Text_0:
	.string "Natsuki$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_1:
	.string "Hey, {PLAYER}! Come on, sit down\n"
	.string "next to me.$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_2:
	.string "It's been crazy lately, huh?\p"
	.string "With the Pokémon in Ginko Woods,\n"
	.string "and the volcano…\p"
	.string "It feels like everything's\n"
	.string "about to change.\p"
	.string "Everyone is so anxious.\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_3:
	.string "Are you worried?$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_4:
	.string "What are you thinking about?$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_5:
	.string "Nah, you know me.\n"
	.string "We'll figure it out when we get there.\p"
	.string "That's what I've always done,\n"
	.string "everything turns out fine eventually.$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_6:
	.string "Hey, look.\p"
	.string "You can see Yifu City very clearly\n"
	.string "today, it's gorgeous!\p"
	.string "…$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_7:
	.string "You okay there, {PLAYER}?\n"
	.string "You look troubled.\p"
	.string "Aren't you excited to become\n"
	.string "a Pokémon wielder?$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_8:
	.string "Huh?…\p"
	.string "…Oh, sorry, I was just wondering\n"
	.string "which Pokémon I'm gonna be getting.$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_9:
	.string "What about you, {PLAYER}?\n"
	.string "You excited about getting\l"
	.string "your own Pokémon?$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_10:
	.string "I'm thrilled!$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_11:
	.string "I'm terrified!$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_12:
	.string "It's whatever.$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_13:
	.string "Hell yeah!\p"
	.string "We're going to make awesome wielders,\n"
	.string "I can already tell.\p"
	.string "Maybe you'll even be second best\n"
	.string "one day…\p"
	.string "Behind me, of course!$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_14:
	.string "Uh, you're kidding, right?\p"
	.string "It's going to be awesome.\n"
	.string "Just chill.\p"
	.string "Once we get our Pokémon, we'll do\n"
	.string "whatever we want!$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_15:
	.string "Oh c'mon, you're just pretending\n"
	.string "not to be excited.\p"
	.string "Look at you, acting all tough\n"
	.string "and silent…\l"
	.string "But I see right through you!\p"
	.string "I bet you'll be a great wielder.\n"
	.string "Maybe even as good as me…\p"
	.string "Probably not though!$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_16:
	.string "Woah, there it goes again!\n"
	.string "You good, {PLAYER}?\p"
	.string "Whew! Those quakes are no joke, huh?\p"
	.string "Maybe the volcano's telling us\n"
	.string "to get to Elder Kaba's house already.$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_17:
	.string "Aw Shuckles, the distribution's\n"
	.string "already started!\p"
	.string "Let's go, {PLAYER}!!$"

SunriseVillage_Beach_EventScript_Corsola_Text_0:
	.string "Krr!$"

SunriseVillage_Beach_EventScript_Corsola2_Text_0:
	.string "Laaa!$"

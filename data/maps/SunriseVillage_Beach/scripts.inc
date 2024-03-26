SunriseVillage_Beach_MapScripts::
	.byte 0


SunriseVillage_Beach_EventScript_RivalSpeech::
# 8 "data/maps/SunriseVillage_Beach/scripts.pory"
	lock
# 9 "data/maps/SunriseVillage_Beach/scripts.pory"
	faceplayer
# 10 "data/maps/SunriseVillage_Beach/scripts.pory"
	playse SE_PIN
# 11 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 12 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitmovement 0
# 13 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement 1, Common_Movement_Delay48
# 14 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitmovement 0
# 15 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_0
# 20 "data/maps/SunriseVillage_Beach/scripts.pory"
	closemessage
# 22 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_1
# 30 "data/maps/SunriseVillage_Beach/scripts.pory"
	closemessage
# 32 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement 1, Common_Movement_Delay48
# 33 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitmovement 0
# 35 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_2
# 48 "data/maps/SunriseVillage_Beach/scripts.pory"
	closemessage
# 50 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement 1, Common_Movement_Delay48
# 51 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitmovement 0
# 53 "data/maps/SunriseVillage_Beach/scripts.pory"
	msgbox SunriseVillage_Beach_EventScript_RivalSpeech_Text_3
# 62 "data/maps/SunriseVillage_Beach/scripts.pory"
	closemessage
# 65 "data/maps/SunriseVillage_Beach/scripts.pory"
	applymovement 1, SunriseVillage_Beach_Movement_RivalRaces
# 66 "data/maps/SunriseVillage_Beach/scripts.pory"
	waitmovement 0
# 68 "data/maps/SunriseVillage_Beach/scripts.pory"
	setflag FLAG_HIDE_SUNRISE_BEACH_RIVAL
# 69 "data/maps/SunriseVillage_Beach/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 4
# 71 "data/maps/SunriseVillage_Beach/scripts.pory"
	removeobject 1
# 72 "data/maps/SunriseVillage_Beach/scripts.pory"
	release
	end


# 76 "data/maps/SunriseVillage_Beach/scripts.pory"
SunriseVillage_Beach_Movement_RivalRaces:
# 77 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 78 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 79 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 80 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 81 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 82 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 83 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 84 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 85 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 86 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_up
# 87 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_up
# 88 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_up
# 89 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_up
# 90 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 91 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 92 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 93 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 94 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 95 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 96 "data/maps/SunriseVillage_Beach/scripts.pory"
	walk_fast_right
# 97 "data/maps/SunriseVillage_Beach/scripts.pory"
	step_end

SunriseVillage_Beach_EventScript_RivalSpeech_Text_0:
# 16 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "{PLAYER}{KUN}! Ya made it!\p"
	.string "Come on, sit down next to me!$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_1:
# 23 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "Remember when we were little and we\n"
	.string "used to fight each other to be the\l"
	.string "first to sit on this bench?\p"
	.string "Good times. Even though you always won,\n"
	.string "hehe.\p"
	.string "…$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_2:
# 36 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "Hey, look!\p"
	.string "You can see YIFU CITY very clearly\n"
	.string "today, it's gorgeous!\p"
	.string "…\p"
	.string "I guess I'm feeling a little nervous\n"
	.string "about all this.\p"
	.string "The POKéMON getting restless in the\n"
	.string "GINKO WOODS…\p"
	.string "Having my own POKéMON to care for…\p"
	.string "It feels like everything's about to\n"
	.string "change, though I'm not sure how yet.$"

SunriseVillage_Beach_EventScript_RivalSpeech_Text_3:
# 54 "data/maps/SunriseVillage_Beach/scripts.pory"
	.string "Look at me rambling! I'm sure everything\n"
	.string "is going to be just fine.\p"
	.string "Are you excited to become a POKéMON\n"
	.string "trainer?\p"
	.string "Come on, it's almost time! Let's go to\n"
	.string "Elder KABA's house!\p"
	.string "Race ya there!!$"

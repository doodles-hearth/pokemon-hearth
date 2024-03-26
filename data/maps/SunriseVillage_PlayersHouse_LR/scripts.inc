SunriseVillage_PlayersHouse_LR_MapScripts::
	.byte 0


SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi::
# 5 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	lock
# 6 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	playse SE_PIN
# 7 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 8 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	waitmovement 0
# 9 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	applymovement 1, Common_Movement_Delay48
# 10 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	waitmovement 0
# 11 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi_Text_0
# 18 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	closemessage
# 19 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	setflag FLAG_BIGSIS_OUT
# 20 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 3
# 21 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	applymovement 1, SunriseVillage_PlayersHouse_LR_Movement_BigSisExits
# 22 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	waitmovement 0
# 23 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	playse SE_EXIT
# 24 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	waitse
# 25 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	removeobject 1
# 26 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	release
	end


# 30 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
SunriseVillage_PlayersHouse_LR_Movement_BigSisExits:
# 31 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	walk_down
# 32 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	walk_down
# 33 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	walk_left
# 34 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	walk_left
# 35 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	walk_left
# 36 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	walk_left
# 37 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	walk_left
# 38 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	walk_left
# 39 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	walk_in_place_faster_down
# 40 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	step_end

SunriseVillage_PlayersHouse_LR_EventScript_BigSis::
# 44 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	lock
# 45 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	faceplayer
# 46 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	special GetPlayerBroSisString
# 47 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_0
# 50 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	release
	return


SunriseVillage_PlayersHouse_LR_EventScript_ReadRivalsNote::
# 54 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	lock
# 55 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_ReadRivalsNote_Text_0
# 60 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	release
	end


SunriseVillage_PlayersHouse_LR_EventScript_RunningShoesBox::
# 65 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	lock
# 66 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	msgbox SunriseVillage_PlayersHouse_LR_EventScript_RunningShoesBox_Text_0
# 72 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 73 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	message SunriseVillage_PlayersHouse_LR_EventScript_RunningShoesBox_Text_1
# 74 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	waitfanfare
# 75 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	removeobject 2
# 76 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 77 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 78 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	closemessage
# 79 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	delay 30
# 80 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	release
	end


SunriseVillage_PlayersHouse_LR_EventScript_BigSisSaysHi_Text_0:
# 12 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	.string "Oh, hi {PLAYER}{KUN}, you're up! Ready for\n"
	.string "the big event?\p"
	.string "Are you excited? I sure hope you are,\n"
	.string "because I'm VERY EXCITED!\p"
	.string "I have to head out, but I'll meet you\n"
	.string "there, okay?\p"
	.string "Oh, by the way, your friend {RIVAL}\n"
	.string "left you a note.\p"
	.string "Make sure you read it!$"

SunriseVillage_PlayersHouse_LR_EventScript_BigSis_Text_0:
# 48 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	.string "Hey {STR_VAR_1}.$"

SunriseVillage_PlayersHouse_LR_EventScript_ReadRivalsNote_Text_0:
# 56 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	.string "“Hey {PLAYER}{KUN},\p"
	.string "“I'm going down to the beach before the\n"
	.string "giveaway, meet me there if you wanna\l"
	.string "hang out.\p"
	.string "“-{RIVAL}”$"

SunriseVillage_PlayersHouse_LR_EventScript_RunningShoesBox_Text_0:
# 67 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	.string "A parcel with a note on it.\p"
	.string "“Dear {PLAYER},\p"
	.string "“Here are the SWIFT GETA shoes you\n"
	.string "have ordered.\p"
	.string "“Press B to run and fly like the wind!”$"

SunriseVillage_PlayersHouse_LR_EventScript_RunningShoesBox_Text_1:
# 73 "data/maps/SunriseVillage_PlayersHouse_LR/scripts.pory"
	.string "{PLAYER} switched shoes with the\n"
	.string "SWIFT GETA.$"

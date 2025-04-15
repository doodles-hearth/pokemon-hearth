LittlerootTown_MaysHouse_1F_MapScripts::
	.byte 0


LittlerootTown_MaysHouse_1F_EventScript_BigSisSaysHi::
	lock
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	msgbox LittlerootTown_MaysHouse_1F_EventScript_BigSisSaysHi_Text_0
	closemessage
	setflag FLAG_HIDE_BIGSIS_HOME
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 3
	applymovement 1, LittlerootTown_MaysHouse_1F_Movement_BigSisExits
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject 1
	release
	end


LittlerootTown_MaysHouse_1F_Movement_BigSisExits:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

LittlerootTown_MaysHouse_1F_EventScript_BigSis::
	lock
	faceplayer
	special GetPlayerBroSisString
	msgbox LittlerootTown_MaysHouse_1F_EventScript_BigSis_Text_0
	release
	return


LittlerootTown_MaysHouse_1F_EventScript_ReadRivalsNote::
	lock
	msgbox LittlerootTown_MaysHouse_1F_EventScript_ReadRivalsNote_Text_0
	release
	end


LittlerootTown_MaysHouse_1F_EventScript_RunningShoesBox::
	lock
	msgbox LittlerootTown_MaysHouse_1F_EventScript_RunningShoesBox_Text_0
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_MaysHouse_1F_EventScript_RunningShoesBox_Text_1
	waitfanfare
	removeobject 2
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	closemessage
	delay 30
	release
	end


LittlerootTown_MaysHouse_1F_EventScript_BigSisSaysHi_Text_0:
	.string "Oh, hi {PLAYER}{KUN}, you're up! Ready for\n"
	.string "the big event?\p"
	.string "Are you excited? I sure hope you are,\n"
	.string "because I'm VERY EXCITED!\p"
	.string "I have to head out, but I'll meet you\n"
	.string "there, okay?\p"
	.string "Oh, by the way, your friend Natsuki\n"
	.string "left you a note.\p"
	.string "Make sure you read it!$"

LittlerootTown_MaysHouse_1F_EventScript_BigSis_Text_0:
	.string "Hey {STR_VAR_1}.$"

LittlerootTown_MaysHouse_1F_EventScript_ReadRivalsNote_Text_0:
	.string "“Hey {PLAYER}{KUN},\p"
	.string "“I'm going down to the beach before\n"
	.string "the giveaway, meet me there if you\l"
	.string "wanna hang out.\p"
	.string "“-Natsuki”$"

LittlerootTown_MaysHouse_1F_EventScript_RunningShoesBox_Text_0:
	.string "A box with a note on it.\p"
	.string "“Dear {PLAYER},\p"
	.string "“Here are the SWIFT GETA shoes you\n"
	.string "have ordered.\p"
	.string "“Press B to run and fly like the wind!”$"

LittlerootTown_MaysHouse_1F_EventScript_RunningShoesBox_Text_1:
	.string "{PLAYER} switched shoes with the\n"
	.string "SWIFT GETA.$"

TranquilRoute_CutHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TranquilRoute_CutHouse_EventScript_CheckCutGrassQuestComplete
	map_script MAP_SCRIPT_ON_TRANSITION, TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_CUT_QUEST_COMPLETED, TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	gettime
	compare VAR_0x8000, 7
	goto_if_ge TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	return

TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
	setflag FLAG_TEMP_1
	return

TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	compare VAR_0x8000, 19
	goto_if_le TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	return

TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 1, TranquilRoute_CutHouse_EventScript_CutGrassCutscene
	.2byte 0


TranquilRoute_CutHouse_EventScript_CheckCutGrassQuestComplete::
	goto_if_set FLAG_CUT_QUEST_CUT_ALL_GRASS, TranquilRoute_CutHouse_EventScript_CheckCutGrassQuestComplete_2
	return

TranquilRoute_CutHouse_EventScript_CheckCutGrassQuestComplete_1:
	setvar VAR_TEMP_0, 1
	return

TranquilRoute_CutHouse_EventScript_CheckCutGrassQuestComplete_2:
	goto_if_unset FLAG_CUT_QUEST_COMPLETED, TranquilRoute_CutHouse_EventScript_CheckCutGrassQuestComplete_1
	return


TranquilRoute_CutHouse_EventScript_CutGrassCutscene::
	lock
	setvar VAR_TEMP_0, 0
	playse SE_PIN
	applymovement 1, TranquilRoute_CutHouse_Movement_CutMasterSurprise
	waitmovement 0
	delay 48
	msgbox TranquilRoute_CutHouse_EventScript_CutGrassCutscene_Text_0
	closemessage
	delay 48
	warp MAP_TRANQUIL_ROUTE, 43, 33
	release
	return


TranquilRoute_CutHouse_Movement_CutMasterSurprise:
	face_down
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

TranquilRoute_CutHouse_EventScript_CutMaster::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, TranquilRoute_CutHouse_EventScript_CutMaster_2
	speakername TranquilRoute_CutHouse_EventScript_CutMaster_Text_0
	msgbox TranquilRoute_CutHouse_EventScript_CutMaster_Text_3
	closemessage
	giveitem ITEM_SECRET_CUT
	speakername TranquilRoute_CutHouse_EventScript_CutMaster_Text_0
	msgbox TranquilRoute_CutHouse_EventScript_CutMaster_Text_4
	closemessage
	giveitem ITEM_TM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	speakername TranquilRoute_CutHouse_EventScript_CutMaster_Text_0
	msgbox TranquilRoute_CutHouse_EventScript_CutMaster_Text_5
	closemessage
TranquilRoute_CutHouse_EventScript_CutMaster_1:
	release
	return

TranquilRoute_CutHouse_EventScript_CutMaster_2:
	goto_if_set FLAG_CUT_QUEST_CUT_ALL_GRASS, TranquilRoute_CutHouse_EventScript_CutMaster_5
	speakername TranquilRoute_CutHouse_EventScript_CutMaster_Text_0
	msgbox TranquilRoute_CutHouse_EventScript_CutMaster_Text_2
	closemessage
	goto TranquilRoute_CutHouse_EventScript_CutMaster_1

TranquilRoute_CutHouse_EventScript_CutMaster_5:
	speakername TranquilRoute_CutHouse_EventScript_CutMaster_Text_0
	msgbox TranquilRoute_CutHouse_EventScript_CutMaster_Text_1
	closemessage
	goto TranquilRoute_CutHouse_EventScript_CutMaster_1


TranquilRoute_CutHouse_EventScript_RandomCryGuy::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_MON_CRY_RIDDLE, TranquilRoute_CutHouse_EventScript_RandomCryGuy_2
	goto_if_set FLAG_MON_CRY_NPC, TranquilRoute_CutHouse_EventScript_RandomCryGuy_5
	special AssignRandomMonCryVars
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_2
	waitse
	playmoncry VAR_0x8008, CRY_MODE_NORMAL
	waitmoncry
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_3
	bufferspeciesname STR_VAR_1, VAR_0x8004
	dynmultipush TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_4, VAR_0x8004
	bufferspeciesname STR_VAR_1, VAR_0x8005
	dynmultipush TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_4, VAR_0x8005
	bufferspeciesname STR_VAR_1, VAR_0x8006
	dynmultipush TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_4, VAR_0x8006
	bufferspeciesname STR_VAR_1, VAR_0x8007
	dynmultipush TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_4, VAR_0x8007
	dynmultistack 0, 0, FALSE, 6, TRUE, 3, DYN_MULTICHOICE_CB_NONE
	compare VAR_RESULT, VAR_0x8008
	goto_if_eq TranquilRoute_CutHouse_EventScript_RandomCryGuy_8
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_7
TranquilRoute_CutHouse_EventScript_RandomCryGuy_7:
	setflag FLAG_MON_CRY_NPC
	release
	end

TranquilRoute_CutHouse_EventScript_RandomCryGuy_2:
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_0
	release
	end

TranquilRoute_CutHouse_EventScript_RandomCryGuy_5:
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_1
	release
	end

TranquilRoute_CutHouse_EventScript_RandomCryGuy_8:
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_5
	giveitem ITEM_MEWTWONITE_X
	setflag FLAG_DAILY_MON_CRY_RIDDLE
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_6
	goto TranquilRoute_CutHouse_EventScript_RandomCryGuy_7


TranquilRoute_CutHouse_EventScript_CutGrassCutscene_Text_0:
	.string "You actually cut ALL the tall grass?\p"
	.string "Wait, let us go outside. I want to see\n"
	.string "it for myself.$"

TranquilRoute_CutHouse_EventScript_CutMaster_Text_0:
	.string "Old Man$"

TranquilRoute_CutHouse_EventScript_CutMaster_Text_1:
	.string "The sun is setting on another day.\p"
	.string "Life is good.$"

TranquilRoute_CutHouse_EventScript_CutMaster_Text_2:
	.string "Are you finding the Secret of Blade\n"
	.string "useful?\p"
	.string "No, I still haven't trimmed my garden.\n"
	.string "I really should get to it…$"

TranquilRoute_CutHouse_EventScript_CutMaster_Text_3:
	.string "Hello, there. I don't get many\n"
	.string "visitors, so sit down, have some tea!\p"
	.string "What? My garden is overrun by weeds?\p"
	.string "Ho ho ho…\p"
	.string "You're right, I have been neglecting\n"
	.string "it lately. You see, my old back isn't as\l"
	.string "strong as it used to be.\p"
	.string "I'm going to let you in on a secret…\p"
	.string "Long ago, a powerful swordmaster\n"
	.string "came up with a secret cutting\l"
	.string "technique.\p"
	.string "I just so happen to have it written\n"
	.string "down right here!\p"
	.string "You don't look much like a\n"
	.string "swordmaster… But surely a Wielder\l"
	.string "like you could teach their Pokémon\l"
	.string "the Secret of Blade!$"

TranquilRoute_CutHouse_EventScript_CutMaster_Text_4:
	.string "There is a variety of slicing moves\n"
	.string "that your Pokémon can use.\p"
	.string "They will now be able to use those\n"
	.string "moves to cut tall grass and little\l"
	.string "trees that block your path.\p"
	.string "You will need at least one official\n"
	.string "Dojo Token for that, though.\p"
	.string "We can't be going around cutting\n"
	.string "trees irresponsibly, now can we?\p"
	.string "You can also have this scroll, in case\n"
	.string "your Pokémon don't know any slicing\l"
	.string "moves yet.$"

TranquilRoute_CutHouse_EventScript_CutMaster_Text_5:
	.string "Want to know another secret?\p"
	.string "That powerful swordmaster I\n"
	.string "mentioned…\p"
	.string "That was me in my youthful days,\n"
	.string "ho ho ho…$"

TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_0:
	.string "you already got it right\ncome back tomorrow dingus$"

TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_1:
	.string "you guessed wrong\ncome back tomorrow dingus$"

TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_2:
	.string "yo dingus listen to this$"

TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_3:
	.string "now tell me, whomst was it$"

TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_4:
	.string "{STR_VAR_1}$"

TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_5:
	.string "correct dingus, here take this$"

TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_6:
	.string "come back tomorrow$"

TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_7:
	.string "wrong dingus, try again tomorrow$"

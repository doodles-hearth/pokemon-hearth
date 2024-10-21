TranquilRoute_CutHouse_MapScripts::
# 6 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, TranquilRoute_CutHouse_EventScript_CheckCutGrassQuestComplete
# 7 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 15 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 8 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	goto_if_set FLAG_CUT_QUEST_COMPLETED, TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 9 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	gettime
# 10 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	compare VAR_0x8000, 7
	goto_if_ge TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	return

TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 11 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	setflag FLAG_TEMP_1
	return

TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 10 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	compare VAR_0x8000, 19
	goto_if_le TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	return

TranquilRoute_CutHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 16 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	map_script_2 VAR_TEMP_0, 1, TranquilRoute_CutHouse_EventScript_CutGrassCutscene
	.2byte 0


TranquilRoute_CutHouse_EventScript_CheckCutGrassQuestComplete::
# 21 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	goto_if_set FLAG_CUT_QUEST_CUT_ALL_GRASS, TranquilRoute_CutHouse_EventScript_CheckCutGrassQuestComplete_2
	return

TranquilRoute_CutHouse_EventScript_CheckCutGrassQuestComplete_1:
# 22 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	setvar VAR_TEMP_0, 1
	return

TranquilRoute_CutHouse_EventScript_CheckCutGrassQuestComplete_2:
# 21 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	goto_if_unset FLAG_CUT_QUEST_COMPLETED, TranquilRoute_CutHouse_EventScript_CheckCutGrassQuestComplete_1
	return


TranquilRoute_CutHouse_EventScript_CutGrassCutscene::
# 27 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	lock
# 28 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	setvar VAR_TEMP_0, 0
# 29 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	playse SE_PIN
# 30 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	applymovement 1, TranquilRoute_CutHouse_Movement_CutMasterSurprise
# 31 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	waitmovement 0
# 32 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	delay 48
# 34 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_CutGrassCutscene_Text_0
# 38 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	closemessage
# 40 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	delay 48
# 42 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	warp MAP_TRANQUIL_ROUTE, 53, 33
# 43 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	release
	return


# 46 "data/maps/TranquilRoute_CutHouse/scripts.pory"
TranquilRoute_CutHouse_Movement_CutMasterSurprise:
# 47 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	face_down
# 48 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	emote_exclamation_mark
# 49 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	delay_16
# 49 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	delay_16
# 49 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	delay_16
	step_end

TranquilRoute_CutHouse_EventScript_CutMaster::
# 53 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	lock
# 54 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	faceplayer
# 57 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_CUT, TranquilRoute_CutHouse_EventScript_CutMaster_2
# 76 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_CutMaster_Text_2
# 83 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	closemessage
# 85 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	giveitem ITEM_HM_CUT
# 86 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	setflag FLAG_RECEIVED_HM_CUT
# 87 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_CutMaster_Text_3
# 94 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	closemessage
TranquilRoute_CutHouse_EventScript_CutMaster_1:
# 97 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	release
	return

TranquilRoute_CutHouse_EventScript_CutMaster_2:
# 59 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	goto_if_set FLAG_CUT_QUEST_CUT_ALL_GRASS, TranquilRoute_CutHouse_EventScript_CutMaster_5
# 67 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_CutMaster_Text_1
# 71 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	closemessage
	goto TranquilRoute_CutHouse_EventScript_CutMaster_1

TranquilRoute_CutHouse_EventScript_CutMaster_5:
# 60 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_CutMaster_Text_0
# 64 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	closemessage
	goto TranquilRoute_CutHouse_EventScript_CutMaster_1


TranquilRoute_CutHouse_EventScript_RandomCryGuy::
# 104 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	lock
# 105 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	faceplayer
# 106 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	goto_if_set FLAG_MON_CRY_NPC_GIVE_ITEM, TranquilRoute_CutHouse_EventScript_RandomCryGuy_2
# 113 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	goto_if_set FLAG_MON_CRY_NPC, TranquilRoute_CutHouse_EventScript_RandomCryGuy_5
# 120 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	special AssignRandomMonCryVars
# 121 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_2
# 122 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	waitse
# 123 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	playmoncry VAR_0x8008, CRY_MODE_NORMAL
# 124 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	waitmoncry
# 125 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_3
# 127 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 128 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	dynmultipush TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_4, VAR_0x8004
# 130 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 131 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	dynmultipush TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_4, VAR_0x8005
# 133 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8006
# 134 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	dynmultipush TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_4, VAR_0x8006
# 136 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8007
# 137 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	dynmultipush TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_4, VAR_0x8007
# 139 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, TRUE, 3, DYN_MULTICHOICE_CB_NONE
# 141 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	compare VAR_RESULT, VAR_0x8008
	goto_if_eq TranquilRoute_CutHouse_EventScript_RandomCryGuy_8
# 150 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_7
TranquilRoute_CutHouse_EventScript_RandomCryGuy_7:
# 152 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	setflag FLAG_MON_CRY_NPC
# 153 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	release
	end

TranquilRoute_CutHouse_EventScript_RandomCryGuy_2:
# 108 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_0
# 109 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	release
	end

TranquilRoute_CutHouse_EventScript_RandomCryGuy_5:
# 115 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_1
# 116 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	release
	end

TranquilRoute_CutHouse_EventScript_RandomCryGuy_8:
# 143 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_5
# 144 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	giveitem ITEM_MEWTWONITE_X
# 145 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	setflag FLAG_MON_CRY_NPC_GIVE_ITEM
# 146 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_6
	goto TranquilRoute_CutHouse_EventScript_RandomCryGuy_7


TranquilRoute_CutHouse_EventScript_RandomDexGuy::
# 160 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	lock
# 161 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	faceplayer
# 162 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	goto_if_set FLAG_DEX_RIDDLE_NPC_GIVE_ITEM, TranquilRoute_CutHouse_EventScript_RandomDexGuy_2
# 169 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	goto_if_set FLAG_DEX_RIDDLE_NPC, TranquilRoute_CutHouse_EventScript_RandomDexGuy_5
# 176 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_RandomDexGuy_Text_0
# 177 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	closemessage
# 178 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	randomdexmsgbox
# 179 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_RandomDexGuy_Text_1
# 180 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	special EnterDexRiddleGuess
# 181 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	waitstate
# 182 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	special GetDexRiddleFeedback
# 184 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq TranquilRoute_CutHouse_EventScript_RandomDexGuy_8
# 193 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_7
TranquilRoute_CutHouse_EventScript_RandomDexGuy_7:
# 195 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	setflag FLAG_DEX_RIDDLE_NPC
# 196 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	release
	end

TranquilRoute_CutHouse_EventScript_RandomDexGuy_2:
# 164 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_0
# 165 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	release
	end

TranquilRoute_CutHouse_EventScript_RandomDexGuy_5:
# 171 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_1
# 172 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	release
	end

TranquilRoute_CutHouse_EventScript_RandomDexGuy_8:
# 186 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_5
# 187 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	giveitem ITEM_MEWTWONITE_Y
# 188 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	setflag FLAG_DEX_RIDDLE_NPC_GIVE_ITEM
# 189 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_6
	goto TranquilRoute_CutHouse_EventScript_RandomDexGuy_7


TranquilRoute_CutHouse_EventScript_CutGrassCutscene_Text_0:
# 35 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	.string "You actually cut ALL the tall grass?\p"
	.string "Wait, let us go outside. I want to see\n"
	.string "it for myself.$"

TranquilRoute_CutHouse_EventScript_CutMaster_Text_0:
# 61 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	.string "The sun is setting on another day.\p"
	.string "Life is good.$"

TranquilRoute_CutHouse_EventScript_CutMaster_Text_1:
# 68 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	.string "Are you finding the Cut technique\n"
	.string "useful?\p"
	.string "No, I still haven't trimmed my garden.\n"
	.string "I really should get to it…$"

TranquilRoute_CutHouse_EventScript_CutMaster_Text_2:
# 77 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	.string "Hello, there. I don't get many\n"
	.string "visitors, so sit down, have some tea!\p"
	.string "What? My garden is overrun by weeds?\p"
	.string "Ho ho ho…\p"
	.string "You're right, I have been neglecting\n"
	.string "it lately. You see, my old back isn't as\l"
	.string "strong as it used to be.\p"
	.string "Here, your Pokémon can trim them\n"
	.string "using this.$"

TranquilRoute_CutHouse_EventScript_CutMaster_Text_3:
# 88 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	.string "This scroll contains an ancient\n"
	.string "technique created by the most\l"
	.string "talented samurai. Pokémon can learn\l"
	.string "that technique too.\p"
	.string "If you have a Pokémon capable of\n"
	.string "learning this move, it will be able to\l"
	.string "cut tall grass as well as little trees\l"
	.string "that block your path.\p"
	.string "In fact, now that you have read the\n"
	.string "scroll, you don't even need to teach\l"
	.string "them the actual move!\p"
	.string "Don't ask me how this works, it just\n"
	.string "does!\p"
	.string "Oh, you will need at least one official\n"
	.string "dojo badge to be able to cut trees\l"
	.string "and grass, though.$"

TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_0:
# 108 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	.string "you already got it right\ncome back tomorrow dingus$"

TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_1:
# 115 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	.string "you guessed wrong\ncome back tomorrow dingus$"

TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_2:
# 121 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	.string "yo dingus listen to this$"

TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_3:
# 125 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	.string "now tell me, whomst was it$"

TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_4:
# 128 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	.string "{STR_VAR_1}$"

TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_5:
# 143 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	.string "correct dingus, here take this$"

TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_6:
# 146 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	.string "come back tomorrow$"

TranquilRoute_CutHouse_EventScript_RandomCryGuy_Text_7:
# 150 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	.string "wrong dingus, try again tomorrow$"

TranquilRoute_CutHouse_EventScript_RandomDexGuy_Text_0:
# 176 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	.string "alright dingus, ima give you a dex\ndescription, you give me the mon\pand remember, you only get to see\nthis once because im lazy$"

TranquilRoute_CutHouse_EventScript_RandomDexGuy_Text_1:
# 179 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	.string "now whomst was that about$"

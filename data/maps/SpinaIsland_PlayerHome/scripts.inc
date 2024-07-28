SpinaIsland_PlayerHome_MapScripts::
# 5 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SpinaIsland_PlayerHome_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

SpinaIsland_PlayerHome_MapScripts_MAP_SCRIPT_ON_LOAD:
# 6 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_SPINDA_ISLAND_INTRO_STATE, 1
	goto_if_lt SpinaIsland_PlayerHome_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

SpinaIsland_PlayerHome_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 7 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 1
	return


SpinaIsland_PlayerHome_EventScript_Mom::
# 13 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 15 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	faceplayer
# 17 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_SPINDA_ISLAND_INTRO_STATE, 2
	goto_if_ge SpinaIsland_PlayerHome_EventScript_Mom_2
SpinaIsland_PlayerHome_EventScript_Mom_1:
# 23 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 25 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return

SpinaIsland_PlayerHome_EventScript_Mom_2:
# 18 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_0
	goto SpinaIsland_PlayerHome_EventScript_Mom_1


SpindaIsland_PlayerHome_EventScript_Diary::
# 29 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 30 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Diary_Text_0
# 35 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpindaIsland_PlayerHome_EventScript_Poem::
# 39 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 40 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Poem_Text_0, MSGBOX_DEFAULT
# 46 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 48 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 49 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative DrawMugshot
# 50 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 51 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Poem_Text_2
# 54 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 55 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative ClearMugshot
# 57 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_Window::
# 61 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 63 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 64 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative DrawMugshot
# 65 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 66 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Window_Text_0
# 69 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 70 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative ClearMugshot
# 72 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_EnterLivingRoom::
# 76 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 78 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 79 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 80 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 81 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 82 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterLeft
# 83 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 84 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 88 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0
# 89 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_1
# 93 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 94 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative ClearMugshot
# 96 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE_HAPPY
# 97 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative DrawMugshot
# 98 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 99 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_2
# 102 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative ClearMugshot
# 103 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 104 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative DrawMugshot
# 105 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_3
# 108 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 109 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative ClearMugshot
# 113 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0
# 114 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_4
# 119 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 120 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative ClearMugshot
# 122 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_NORTH
# 123 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 40
# 124 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 125 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 126 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 127 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 128 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 132 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0
# 133 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_5
# 136 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_WEST
# 137 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_6
# 140 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 141 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative ClearMugshot
# 142 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_NORTH
# 144 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 145 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative DrawMugshot
# 146 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 147 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_7
# 150 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 151 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative ClearMugshot
# 153 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 2
# 155 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_GetSpinda::
# 159 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 161 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removeobject 2
# 162 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	givemon SPECIES_SPINDA, 20
# 163 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setflag FLAG_RECEIVED_STARTER
# 166 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE_HAPPY
# 167 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative DrawMugshot
# 168 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 169 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_GetSpinda_Text_0
# 172 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 173 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative ClearMugshot
# 175 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_WailmerDoll::
# 179 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 181 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE_HAPPY
# 182 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative DrawMugshot
# 183 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 184 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_WailmerDoll_Text_0
# 187 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 188 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative ClearMugshot
# 190 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_Mom_Text_0:
# 19 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Hurry up and turn the big faucet back\n"
	.string "on!\p"
	.string "I'll give you your thing when the tap's\n"
	.string "running.$"

SpindaIsland_PlayerHome_EventScript_Diary_Text_0:
# 31 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "“Dear diarry,\n"
	.string "The ship is almost finished.\n"
	.string "It is gonna be awsome.\p"
	.string "It will be even more beautifull then\n"
	.string "dad's.”$"

SpindaIsland_PlayerHome_EventScript_Poem_Text_0:
# 41 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "“A POEM BY ARCHIE\p"
	.string "Roses are blue\l"
	.string "Violetts are blue\l"
	.string "Everything is blue because its my\l"
	.string "favorite color.”$"

SpindaIsland_PlayerHome_EventScript_Poem_Text_1:
# 50 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Little Archie$"

SpindaIsland_PlayerHome_EventScript_Poem_Text_2:
# 52 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I am such a poet.$"

SpinaIsland_PlayerHome_EventScript_Window_Text_0:
# 67 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Something's moving outside.$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0:
# 88 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Mom$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_1:
# 90 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Morning, little Archie!\p"
	.string "You're quite the early bird today!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_2:
# 100 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "That's cause today's the big day!!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_3:
# 106 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "You haven't forgotten about my super\n"
	.string "secret thing, right?$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_4:
# 115 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Of course not, darling! Your super\n"
	.string "secret thing is almost finished.\p"
	.string "I'll give it to you as soon as I'm done.\p"
	.string "But first, I sure could go for a nice,\n"
	.string "big, tall glass of icy {COLOR BLUE}WATER{COLOR DARK_GRAY}…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_5:
# 134 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Look at that, I forgot to turn the\n"
	.string "{COLOR BLUE}WATER{COLOR DARK_GRAY} back on…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_6:
# 138 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Archie, would you be a dear and go\n"
	.string "round the house to turn the big\l"
	.string "faucet on?$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_7:
# 148 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Ughhhhhh, alright…$"

SpinaIsland_PlayerHome_EventScript_GetSpinda_Text_0:
# 170 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I could never forget you, Spinda!$"

SpinaIsland_PlayerHome_EventScript_WailmerDoll_Text_0:
# 185 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "How you doing, Wailmy?$"

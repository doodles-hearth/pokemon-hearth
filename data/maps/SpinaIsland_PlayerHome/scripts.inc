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
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 64 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 65 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Window_Text_0
# 68 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 69 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 71 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_EnterLivingRoom::
# 75 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 77 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 78 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 79 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 80 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 81 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterLeft
# 82 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 83 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 87 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0
# 88 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_1
# 92 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 93 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative ClearMugshot
# 95 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE_HAPPY
# 96 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative DrawMugshot
# 97 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 98 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_2
# 101 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative ClearMugshot
# 102 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 103 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative DrawMugshot
# 104 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_3
# 107 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 108 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative ClearMugshot
# 112 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0
# 113 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_4
# 118 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 119 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative ClearMugshot
# 121 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_NORTH
# 122 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 40
# 123 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 124 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 125 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 126 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 127 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 131 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0
# 132 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_5
# 135 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_WEST
# 136 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_6
# 139 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 140 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative ClearMugshot
# 141 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_NORTH
# 143 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 144 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative DrawMugshot
# 145 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 146 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_7
# 149 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 150 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative ClearMugshot
# 152 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 2
# 154 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_GetSpinda::
# 158 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 160 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removeobject 2
# 161 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	givemon SPECIES_SPINDA, 20
# 162 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setflag FLAG_RECEIVED_STARTER
# 165 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE_HAPPY
# 166 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative DrawMugshot
# 167 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 168 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_GetSpinda_Text_0
# 171 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 172 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative ClearMugshot
# 174 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_WailmerDoll::
# 178 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 180 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE_HAPPY
# 181 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative DrawMugshot
# 182 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 183 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_WailmerDoll_Text_0
# 186 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 187 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	callnative ClearMugshot
# 189 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
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
# 66 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Something's moving outside.$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0:
# 87 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Mom$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_1:
# 89 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Morning, little Archie!\p"
	.string "You're quite the early bird today!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_2:
# 99 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "That's cause today's the big day!!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_3:
# 105 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "You haven't forgotten about my super\n"
	.string "secret thing, right?$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_4:
# 114 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Of course not, darling! Your super\n"
	.string "secret thing is almost finished.\p"
	.string "I'll give it to you as soon as I'm done.\p"
	.string "But first, I sure could go for a nice,\n"
	.string "big, tall glass of icy {COLOR BLUE}WATER{COLOR DARK_GRAY}…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_5:
# 133 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Look at that, I forgot to turn the\n"
	.string "{COLOR BLUE}WATER{COLOR DARK_GRAY} back on…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_6:
# 137 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Archie, would you be a dear and go\n"
	.string "round the house to turn the big\l"
	.string "faucet on?$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_7:
# 147 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Ughhhhhh, alright…$"

SpinaIsland_PlayerHome_EventScript_GetSpinda_Text_0:
# 169 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I could never forget you, Spinda!$"

SpinaIsland_PlayerHome_EventScript_WailmerDoll_Text_0:
# 184 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "How you doing, Wailmy?$"

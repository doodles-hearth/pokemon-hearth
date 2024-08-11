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
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 49 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 50 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Poem_Text_2
# 53 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 54 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 56 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpindaIsland_PlayerHome_EventScript_Map::
# 60 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 62 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 63 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 64 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Map_Text_0
# 67 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 68 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 70 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_Window::
# 74 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 76 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 77 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 78 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Window_Text_0
# 81 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 82 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 84 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_Window_Front::
# 88 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 90 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 91 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 92 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Window_Front_Text_0
# 95 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 96 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 98 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_EnterLivingRoom::
# 102 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 104 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 105 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 106 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 107 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 108 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterLeft
# 109 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 110 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 112 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0
# 113 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_1
# 117 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 118 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 120 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 121 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 122 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_2
# 125 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 126 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 127 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_3
# 130 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 131 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 133 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0
# 134 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_4
# 139 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 140 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 142 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_NORTH
# 143 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 40
# 144 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 145 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 146 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 147 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 148 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 150 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0
# 151 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_5
# 154 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_WEST
# 155 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_6
# 158 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 159 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 160 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_NORTH
# 162 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 163 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 164 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_7
# 167 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 168 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 170 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 2
# 172 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_GetSpinda::
# 176 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 178 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removeobject 2
# 179 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	givemon SPECIES_SPINDA, 20
# 180 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setflag FLAG_RECEIVED_STARTER
# 183 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 184 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 185 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_GetSpinda_Text_0
# 188 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 189 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 191 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_WailmerDoll::
# 195 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 197 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 198 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 199 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_WailmerDoll_Text_0
# 202 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 203 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 205 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
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
# 49 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Little Archie$"

SpindaIsland_PlayerHome_EventScript_Poem_Text_2:
# 51 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I am such a poet.$"

SpindaIsland_PlayerHome_EventScript_Map_Text_0:
# 65 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "It's a map of the island!$"

SpinaIsland_PlayerHome_EventScript_Window_Text_0:
# 79 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Something's moving outside.$"

SpinaIsland_PlayerHome_EventScript_Window_Front_Text_0:
# 93 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I can see the beach!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0:
# 112 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Mom$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_1:
# 114 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Morning, little Archie!\p"
	.string "You're quite the early bird today!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_2:
# 123 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "That's cause today's the big day!!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_3:
# 128 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "You haven't forgotten about my super\n"
	.string "secret thing, right?$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_4:
# 135 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Of course not, darling! Your super\n"
	.string "secret thing is almost finished.\p"
	.string "I'll give it to you as soon as I'm done.\p"
	.string "But first, I sure could go for a nice,\n"
	.string "big, tall glass of icy {COLOR BLUE}WATER{COLOR DARK_GRAY}…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_5:
# 152 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Look at that, I forgot to turn the\n"
	.string "{COLOR BLUE}WATER{COLOR DARK_GRAY} back on…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_6:
# 156 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Archie, would you be a dear and go\n"
	.string "round the house to turn the big\l"
	.string "faucet on?$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_7:
# 165 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Ughhhhhh, fine…$"

SpinaIsland_PlayerHome_EventScript_GetSpinda_Text_0:
# 186 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I could never forget you, Spinda!$"

SpinaIsland_PlayerHome_EventScript_WailmerDoll_Text_0:
# 200 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "How you doing, Wailmy?$"

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
	goto_if_set FLAG_RECEIVED_SLOWPOKE_REWARD, SpinaIsland_PlayerHome_EventScript_Mom_1
# 115 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 116 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_10
# 120 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 121 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return

SpinaIsland_PlayerHome_EventScript_Mom_1:
# 18 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	checkitem ITEM_SALTY_LEMONADE
# 19 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SpinaIsland_PlayerHome_EventScript_Mom_6
SpinaIsland_PlayerHome_EventScript_Mom_5:
# 77 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	checkitem ITEM_WATER_STONE_2
# 79 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SpinaIsland_PlayerHome_EventScript_Mom_11
	return

SpinaIsland_PlayerHome_EventScript_Mom_4:
# 20 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_0
# 24 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpinaIsland_PlayerHome_EventScript_Mom_Text_1, SpinaIsland_PlayerHome_EventScript_Mom_Text_2
# 34 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 36 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SpinaIsland_PlayerHome_EventScript_Mom_9
	return

SpinaIsland_PlayerHome_EventScript_Mom_6:
# 19 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	goto_if_unset FLAG_GAVE_MOM_LEMONADE, SpinaIsland_PlayerHome_EventScript_Mom_4
	goto SpinaIsland_PlayerHome_EventScript_Mom_5

SpinaIsland_PlayerHome_EventScript_Mom_9:
# 37 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 38 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 39 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_4
# 42 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 43 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 45 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 46 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_6
# 50 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 52 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 10
# 53 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_BALL
# 54 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitse
# 55 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_BALL
# 56 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitse
# 57 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_BALL
# 58 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitse
# 59 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 20
# 61 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 62 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 63 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 64 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 66 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 67 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_7
# 71 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 73 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setflag FLAG_GAVE_MOM_LEMONADE
	return

SpinaIsland_PlayerHome_EventScript_Mom_11:
# 80 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_8
# 84 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpinaIsland_PlayerHome_EventScript_Mom_Text_1, SpinaIsland_PlayerHome_EventScript_Mom_Text_2
# 94 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 96 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SpinaIsland_PlayerHome_EventScript_Mom_13
	return

SpinaIsland_PlayerHome_EventScript_Mom_13:
# 97 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 98 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 99 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_4
# 102 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 103 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 105 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 106 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_9
# 110 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
	return


SpindaIsland_PlayerHome_EventScript_Diary::
# 128 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 129 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Diary_Text_0
# 134 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_SpindaManual::
# 138 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_SpindaManual_Text_0, MSGBOX_DEFAULT
	return


SpindaIsland_PlayerHome_EventScript_Poem::
# 145 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 146 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Poem_Text_0, MSGBOX_DEFAULT
# 153 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 155 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 156 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 157 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 160 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 161 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 163 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpindaIsland_PlayerHome_EventScript_Map::
# 167 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 169 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 170 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 171 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Map_Text_0
# 174 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 175 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 177 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_Window::
# 181 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 183 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 184 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 185 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Window_Text_0
# 188 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 189 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 191 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_Window_Front::
# 195 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 197 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 198 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 199 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Window_Front_Text_0
# 202 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 203 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 205 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_EnterLivingRoom::
# 209 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 211 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 212 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 213 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 214 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 215 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterLeft
# 216 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 217 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 219 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 220 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0
# 224 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 225 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 227 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 228 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 229 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_1
# 232 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 233 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 234 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_2
# 237 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 238 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 240 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 241 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_3
# 246 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 247 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 249 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_NORTH
# 250 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 40
# 251 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 252 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 253 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 254 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 255 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 257 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 258 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_4
# 261 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_WEST
# 262 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_5
# 266 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 267 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 268 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_NORTH
# 270 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 271 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 272 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_6
# 275 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 276 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 278 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	goto_if_unset FLAG_TOOK_SPINDA, SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_2
SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_1:
# 285 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 2
# 287 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_2:
# 279 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 280 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_7
	goto SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_1


SpinaIsland_PlayerHome_EventScript_GetSpinda::
# 291 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 293 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removeobject 2
# 294 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	givemon SPECIES_SPINDA, 20
# 295 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setflag FLAG_RECEIVED_STARTER
# 297 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 298 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 299 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_GetSpinda_Text_0
# 302 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 303 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 305 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_WailmerDoll::
# 309 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 311 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 312 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 313 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_WailmerDoll_Text_0
# 316 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 317 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 319 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_Mom_Text_0:
# 21 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Give mom the Salty Lemonade?$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_1:
# 31 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Give$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_2:
# 32 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Don't give$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_3:
# 38 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Little Archie$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_4:
# 40 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Here, mom!$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_5:
# 45 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Mom$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_6:
# 47 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Oh, good, some fresh lemonade! I'm so\n"
	.string "thirsty!\p"
	.string "Thanks, honey!$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_7:
# 68 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "What is wrong with you? This is super\n"
	.string "salty!\p"
	.string "Please take this away and don't do\n"
	.string "that again.$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_8:
# 81 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Give mom the {COLOR BLUE}WATER{COLOR DARK_GRAY} stone?$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_9:
# 107 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "What am I supposed to do with this?\n"
	.string "Lick it?\p"
	.string "Please turn the faucet on so I can\n"
	.string "drink some actual {COLOR BLUE}WATER{COLOR DARK_GRAY}!$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_10:
# 117 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Hurry up and turn the big faucet back\n"
	.string "on, please!\p"
	.string "I'll give you your sail when the tap's\n"
	.string "running.$"

SpindaIsland_PlayerHome_EventScript_Diary_Text_0:
# 130 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "“Dear diarry,\n"
	.string "The ship is almost finished.\n"
	.string "It is gonna be awsome.\p"
	.string "It will be even more beautiful then\n"
	.string "dad's.”$"

SpinaIsland_PlayerHome_EventScript_SpindaManual_Text_0:
# 139 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "“Super cool trick i taught spinda:\n"
	.string "using L and R makes her {COLOR RED}spin{COLOR DARK_GRAY}!\l"
	.string "i love my spinda, shes so awsome”$"

SpindaIsland_PlayerHome_EventScript_Poem_Text_0:
# 147 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "“A POEM BY ARCHIE\p"
	.string "Roses are blue\l"
	.string "Violetts are blue\l"
	.string "Everything is blue\l"
	.string "because its my favorite color.”$"

SpindaIsland_PlayerHome_EventScript_Poem_Text_1:
# 158 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I am such a poet.$"

SpindaIsland_PlayerHome_EventScript_Map_Text_0:
# 172 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "It's a map of the island!$"

SpinaIsland_PlayerHome_EventScript_Window_Text_0:
# 186 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Something's moving outside.$"

SpinaIsland_PlayerHome_EventScript_Window_Front_Text_0:
# 200 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I can see the beach!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0:
# 221 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Morning, little Archie!\p"
	.string "You're quite the early bird today!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_1:
# 230 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "That's cause today's the big day!!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_2:
# 235 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "You haven't forgotten about my super\n"
	.string "secret thing, right?$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_3:
# 242 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Of course not, darling! Your super\n"
	.string "secret thing is almost finished.\p"
	.string "I'll give it to you as soon as I'm done.\p"
	.string "But first, I sure could go for a nice,\n"
	.string "big, tall glass of icy {COLOR BLUE}WATER{COLOR DARK_GRAY}…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_4:
# 259 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Look at that, I forgot to turn the\n"
	.string "{COLOR BLUE}WATER{COLOR DARK_GRAY} back on…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_5:
# 263 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Archie, would you be a dear and go\n"
	.string "round the house to turn the big\l"
	.string "faucet on?\p"
	.string "And then I'll give it to you, I promise!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_6:
# 273 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Ughhhhhh, fine…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_7:
# 281 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Oh, and where's your Spinda? Take her\n"
	.string "for a little walk, will you?$"

SpinaIsland_PlayerHome_EventScript_GetSpinda_Text_0:
# 300 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I could never forget you, Spinda!$"

SpinaIsland_PlayerHome_EventScript_WailmerDoll_Text_0:
# 314 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "How you doing, Wailmy?$"

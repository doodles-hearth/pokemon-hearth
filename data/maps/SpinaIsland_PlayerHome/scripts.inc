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
# 14 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	faceplayer
# 16 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	goto_if_set FLAG_RECEIVED_SLOWPOKE_REWARD, SpinaIsland_PlayerHome_EventScript_Mom_2
# 120 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 121 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 122 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_10
# 126 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 127 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
SpinaIsland_PlayerHome_EventScript_Mom_1:
# 130 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 131 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 133 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return

SpinaIsland_PlayerHome_EventScript_Mom_2:
# 17 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	checkitem ITEM_SALTY_LEMONADE
# 18 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SpinaIsland_PlayerHome_EventScript_Mom_7
SpinaIsland_PlayerHome_EventScript_Mom_6:
# 80 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	checkitem ITEM_WATER_STONE_2
# 82 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SpinaIsland_PlayerHome_EventScript_Mom_12
	goto SpinaIsland_PlayerHome_EventScript_Mom_1

SpinaIsland_PlayerHome_EventScript_Mom_5:
# 19 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_0
# 23 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpinaIsland_PlayerHome_EventScript_Mom_Text_1, SpinaIsland_PlayerHome_EventScript_Mom_Text_2
# 33 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 35 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SpinaIsland_PlayerHome_EventScript_Mom_10
	goto SpinaIsland_PlayerHome_EventScript_Mom_1

SpinaIsland_PlayerHome_EventScript_Mom_7:
# 18 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	goto_if_unset FLAG_GAVE_MOM_LEMONADE, SpinaIsland_PlayerHome_EventScript_Mom_5
	goto SpinaIsland_PlayerHome_EventScript_Mom_6

SpinaIsland_PlayerHome_EventScript_Mom_10:
# 36 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 37 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 38 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_4
# 41 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 42 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 44 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 45 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 46 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_6
# 50 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 51 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 53 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 10
# 54 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_BALL
# 55 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitse
# 56 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_BALL
# 57 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitse
# 58 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_BALL
# 59 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitse
# 60 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 20
# 62 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 63 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 64 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 65 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 67 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_ANGRY
# 68 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 69 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_7
# 73 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 74 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 76 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setflag FLAG_GAVE_MOM_LEMONADE
	goto SpinaIsland_PlayerHome_EventScript_Mom_1

SpinaIsland_PlayerHome_EventScript_Mom_12:
# 83 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_8
# 87 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpinaIsland_PlayerHome_EventScript_Mom_Text_1, SpinaIsland_PlayerHome_EventScript_Mom_Text_2
# 97 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 99 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SpinaIsland_PlayerHome_EventScript_Mom_14
	goto SpinaIsland_PlayerHome_EventScript_Mom_1

SpinaIsland_PlayerHome_EventScript_Mom_14:
# 100 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 101 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 102 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_4
# 105 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 106 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 108 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 109 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 110 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_9
# 114 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 115 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
	goto SpinaIsland_PlayerHome_EventScript_Mom_1


SpindaIsland_PlayerHome_EventScript_Diary::
# 138 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 139 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Diary_Text_0
# 144 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_SpindaManual::
# 148 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_SpindaManual_Text_0, MSGBOX_SIGN
	return


SpindaIsland_PlayerHome_EventScript_Poem::
# 157 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 158 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Poem_Text_0, MSGBOX_DEFAULT
# 165 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 167 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 168 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 169 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 172 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 173 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 175 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpindaIsland_PlayerHome_EventScript_Map::
# 179 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 181 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 182 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 183 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Map_Text_0
# 186 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 187 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 189 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_Window::
# 193 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 195 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 196 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 197 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Window_Text_0
# 200 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 201 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 203 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_Window_Front::
# 207 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 209 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 210 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 211 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Window_Front_Text_0
# 214 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 215 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 217 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_EnterLivingRoom::
# 221 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 223 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 224 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 225 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 226 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 227 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterLeft
# 228 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 229 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 231 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 232 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 233 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0
# 237 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 238 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 239 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 241 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 242 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 243 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_1
# 246 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 247 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 248 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_2
# 251 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 252 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 254 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 255 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 256 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_3
# 261 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 262 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 263 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 265 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_NORTH
# 266 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 40
# 267 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 268 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 269 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 270 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 271 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 273 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 274 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 275 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_4
# 278 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_WEST
# 279 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 280 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 281 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_5
# 285 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 286 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 287 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_NORTH
# 289 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 290 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 291 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_6
# 294 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 295 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 297 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	goto_if_unset FLAG_TOOK_SPINDA, SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_2
SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_1:
# 307 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 2
# 309 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_2:
# 298 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 299 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 300 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_7
# 303 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 304 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
	goto SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_1


SpinaIsland_PlayerHome_EventScript_GetSpinda::
# 313 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 315 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removeobject 2
# 316 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	givemon SPECIES_SPINDA, 20
# 317 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setflag FLAG_RECEIVED_STARTER
# 319 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 320 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 321 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_GetSpinda_Text_0
# 324 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 325 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 327 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_WailmerDoll::
# 331 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 333 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 334 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 335 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_WailmerDoll_Text_0
# 338 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 339 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 341 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_Mom_Text_0:
# 20 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Give mom the Salty Lemonade?$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_1:
# 30 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Give$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_2:
# 31 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Don't give$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_3:
# 37 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Little Archie$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_4:
# 39 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
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
# 70 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "What is wrong with you? This is super\n"
	.string "salty!\p"
	.string "Please take this away and don't do\n"
	.string "that again.$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_8:
# 84 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Give mom the {COLOR BLUE}WATER{COLOR DARK_GRAY} stone?$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_9:
# 111 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "What am I supposed to do with this?\n"
	.string "Lick it?\p"
	.string "Please turn the faucet on so I can\n"
	.string "drink some actual {COLOR BLUE}WATER{COLOR DARK_GRAY}!$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_10:
# 123 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Hurry up and turn the big faucet back\n"
	.string "on, please!\p"
	.string "I'll give you your sail when the tap's\n"
	.string "running.$"

SpindaIsland_PlayerHome_EventScript_Diary_Text_0:
# 140 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "“Dear diarry,\n"
	.string "The ship is almost finished.\n"
	.string "It is gonna be awsome.\p"
	.string "It will be even more beautiful then\n"
	.string "dad's.”$"

SpinaIsland_PlayerHome_EventScript_SpindaManual_Text_0:
# 149 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "“Super cool trick i taught spinda:\n"
	.string "using L and R makes her {COLOR RED}spin{COLOR DARK_GRAY}!\l"
	.string "i love my spinda, shes so awsome”$"

SpindaIsland_PlayerHome_EventScript_Poem_Text_0:
# 159 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "“A POEM BY ARCHIE\p"
	.string "Roses are blue\l"
	.string "Violetts are blue\l"
	.string "Everything is blue\l"
	.string "because its my favorite color.”$"

SpindaIsland_PlayerHome_EventScript_Poem_Text_1:
# 170 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I am such a poet.$"

SpindaIsland_PlayerHome_EventScript_Map_Text_0:
# 184 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "It's a map of the island!$"

SpinaIsland_PlayerHome_EventScript_Window_Text_0:
# 198 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Something's moving outside.$"

SpinaIsland_PlayerHome_EventScript_Window_Front_Text_0:
# 212 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I can see the beach!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0:
# 234 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Morning, little Archie!\p"
	.string "You're quite the early bird today!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_1:
# 244 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "That's cause today's the big day!!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_2:
# 249 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "You haven't forgotten about my super\n"
	.string "secret thing, right?$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_3:
# 257 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Of course not, darling! Your super\n"
	.string "secret thing is almost finished.\p"
	.string "I'll give it to you as soon as I'm done.\p"
	.string "But first, I sure could go for a nice,\n"
	.string "big, tall glass of icy {COLOR BLUE}WATER{COLOR DARK_GRAY}…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_4:
# 276 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Look at that, I forgot to turn the\n"
	.string "{COLOR BLUE}WATER{COLOR DARK_GRAY} back on…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_5:
# 282 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Archie, would you be a dear and go\n"
	.string "round the house to turn the big\l"
	.string "faucet on?\p"
	.string "And then I'll give it to you, I promise!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_6:
# 292 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Ughhhhhh, fine…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_7:
# 301 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Oh, and where's Spinda? Take her for a\n"
	.string "little walk, will you?$"

SpinaIsland_PlayerHome_EventScript_GetSpinda_Text_0:
# 322 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I could never forget you, Spinda!$"

SpinaIsland_PlayerHome_EventScript_WailmerDoll_Text_0:
# 336 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "How you doing, Wailmy?$"

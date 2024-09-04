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
# 121 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 122 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 123 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_10
# 127 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 128 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 129 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return

SpinaIsland_PlayerHome_EventScript_Mom_1:
# 18 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	checkitem ITEM_SALTY_LEMONADE
# 19 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SpinaIsland_PlayerHome_EventScript_Mom_6
SpinaIsland_PlayerHome_EventScript_Mom_5:
# 81 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	checkitem ITEM_WATER_STONE_2
# 83 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
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
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 46 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 47 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_6
# 51 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 52 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 54 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 10
# 55 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_BALL
# 56 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitse
# 57 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_BALL
# 58 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitse
# 59 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_BALL
# 60 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitse
# 61 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 20
# 63 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 64 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 65 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 66 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 68 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_ANGRY
# 69 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 70 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_7
# 74 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 75 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 77 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setflag FLAG_GAVE_MOM_LEMONADE
	return

SpinaIsland_PlayerHome_EventScript_Mom_11:
# 84 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_8
# 88 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpinaIsland_PlayerHome_EventScript_Mom_Text_1, SpinaIsland_PlayerHome_EventScript_Mom_Text_2
# 98 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 100 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SpinaIsland_PlayerHome_EventScript_Mom_13
	return

SpinaIsland_PlayerHome_EventScript_Mom_13:
# 101 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 102 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 103 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_4
# 106 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 107 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 109 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 110 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 111 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_9
# 115 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 116 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
	return


SpindaIsland_PlayerHome_EventScript_Diary::
# 136 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 137 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Diary_Text_0
# 142 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_SpindaManual::
# 146 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_SpindaManual_Text_0, MSGBOX_DEFAULT
	return


SpindaIsland_PlayerHome_EventScript_Poem::
# 153 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 154 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Poem_Text_0, MSGBOX_DEFAULT
# 161 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 163 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 164 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 165 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 168 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 169 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 171 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpindaIsland_PlayerHome_EventScript_Map::
# 175 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 177 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 178 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 179 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Map_Text_0
# 182 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 183 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 185 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_Window::
# 189 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 191 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 192 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 193 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Window_Text_0
# 196 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 197 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 199 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_Window_Front::
# 203 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 205 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 206 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 207 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Window_Front_Text_0
# 210 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 211 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 213 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_EnterLivingRoom::
# 217 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 219 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 220 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 221 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 222 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 223 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterLeft
# 224 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 225 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 227 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 228 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 229 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0
# 233 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 234 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 235 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 237 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 238 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 239 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_1
# 242 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 243 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 244 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_2
# 247 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 248 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 250 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 251 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 252 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_3
# 257 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 258 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 259 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 261 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_NORTH
# 262 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 40
# 263 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 264 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 265 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 266 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 267 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 269 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 270 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 271 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_4
# 274 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_WEST
# 275 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 276 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 277 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_5
# 281 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 282 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 283 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_NORTH
# 285 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 286 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 287 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_6
# 290 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 291 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 293 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	goto_if_unset FLAG_TOOK_SPINDA, SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_2
SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_1:
# 303 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 2
# 305 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_2:
# 294 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 295 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 296 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_7
# 299 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 300 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
	goto SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_1


SpinaIsland_PlayerHome_EventScript_GetSpinda::
# 309 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 311 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removeobject 2
# 312 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	givemon SPECIES_SPINDA, 20
# 313 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setflag FLAG_RECEIVED_STARTER
# 315 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 316 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 317 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_GetSpinda_Text_0
# 320 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 321 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 323 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_WailmerDoll::
# 327 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 329 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 330 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 331 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_WailmerDoll_Text_0
# 334 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 335 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 337 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
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
# 46 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Mom$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_6:
# 48 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Oh, good, some fresh lemonade! I'm so\n"
	.string "thirsty!\p"
	.string "Thanks, honey!$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_7:
# 71 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "What is wrong with you? This is super\n"
	.string "salty!\p"
	.string "Please take this away and don't do\n"
	.string "that again.$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_8:
# 85 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Give mom the {COLOR BLUE}WATER{COLOR DARK_GRAY} stone?$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_9:
# 112 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "What am I supposed to do with this?\n"
	.string "Lick it?\p"
	.string "Please turn the faucet on so I can\n"
	.string "drink some actual {COLOR BLUE}WATER{COLOR DARK_GRAY}!$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_10:
# 124 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Hurry up and turn the big faucet back\n"
	.string "on, please!\p"
	.string "I'll give you your sail when the tap's\n"
	.string "running.$"

SpindaIsland_PlayerHome_EventScript_Diary_Text_0:
# 138 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "“Dear diarry,\n"
	.string "The ship is almost finished.\n"
	.string "It is gonna be awsome.\p"
	.string "It will be even more beautiful then\n"
	.string "dad's.”$"

SpinaIsland_PlayerHome_EventScript_SpindaManual_Text_0:
# 147 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "“Super cool trick i taught spinda:\n"
	.string "using L and R makes her {COLOR RED}spin{COLOR DARK_GRAY}!\l"
	.string "i love my spinda, shes so awsome”$"

SpindaIsland_PlayerHome_EventScript_Poem_Text_0:
# 155 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "“A POEM BY ARCHIE\p"
	.string "Roses are blue\l"
	.string "Violetts are blue\l"
	.string "Everything is blue\l"
	.string "because its my favorite color.”$"

SpindaIsland_PlayerHome_EventScript_Poem_Text_1:
# 166 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I am such a poet.$"

SpindaIsland_PlayerHome_EventScript_Map_Text_0:
# 180 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "It's a map of the island!$"

SpinaIsland_PlayerHome_EventScript_Window_Text_0:
# 194 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Something's moving outside.$"

SpinaIsland_PlayerHome_EventScript_Window_Front_Text_0:
# 208 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I can see the beach!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0:
# 230 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Morning, little Archie!\p"
	.string "You're quite the early bird today!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_1:
# 240 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "That's cause today's the big day!!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_2:
# 245 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "You haven't forgotten about my super\n"
	.string "secret thing, right?$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_3:
# 253 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Of course not, darling! Your super\n"
	.string "secret thing is almost finished.\p"
	.string "I'll give it to you as soon as I'm done.\p"
	.string "But first, I sure could go for a nice,\n"
	.string "big, tall glass of icy {COLOR BLUE}WATER{COLOR DARK_GRAY}…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_4:
# 272 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Look at that, I forgot to turn the\n"
	.string "{COLOR BLUE}WATER{COLOR DARK_GRAY} back on…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_5:
# 278 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Archie, would you be a dear and go\n"
	.string "round the house to turn the big\l"
	.string "faucet on?\p"
	.string "And then I'll give it to you, I promise!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_6:
# 288 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Ughhhhhh, fine…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_7:
# 297 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Oh, and where's Spinda? Take her for a\n"
	.string "little walk, will you?$"

SpinaIsland_PlayerHome_EventScript_GetSpinda_Text_0:
# 318 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I could never forget you, Spinda!$"

SpinaIsland_PlayerHome_EventScript_WailmerDoll_Text_0:
# 332 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "How you doing, Wailmy?$"

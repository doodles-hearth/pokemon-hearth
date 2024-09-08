SpinaIsland_PlayerHome_MapScripts::
# 4 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SpinaIsland_PlayerHome_MapScripts_MAP_SCRIPT_ON_LOAD
# 10 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SpinaIsland_PlayerHome_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SpinaIsland_PlayerHome_MapScripts_MAP_SCRIPT_ON_LOAD:
# 5 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_SPINDA_ISLAND_INTRO_STATE, 1
	goto_if_lt SpinaIsland_PlayerHome_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

SpinaIsland_PlayerHome_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 6 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 1
	return

SpinaIsland_PlayerHome_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 11 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	map_script_2 VAR_REPAIRED_FAUCET, 1, SpinaIsland_PlayerHome_EventScript_FixedFaucet
	.2byte 0


SpinaIsland_PlayerHome_EventScript_FixedFaucet::
# 16 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 17 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpinaIsland_PlayerHome_Movement_ArchieWalksUp
# 18 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 19 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_REPAIRED_FAUCET, 2
# 20 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 21 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 22 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_1
# 25 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 26 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 28 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_SOUTH
# 30 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpinaIsland_PlayerHome_Movement_ArchieWalksUpToMom
# 31 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 33 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_WEST
# 35 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 36 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 37 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_2
# 40 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 41 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 42 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_4
# 46 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 47 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 49 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_NORTH
# 50 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 51 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 52 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 53 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_5
# 57 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 58 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 60 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 20
# 61 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_WEST
# 63 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 64 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 65 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_6
# 68 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 69 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 71 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	giveitem ITEM_BADASS_SAIL
# 73 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 74 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 75 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_7
# 79 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 80 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 82 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpinaIsland_PlayerHome_Movement_ArchieWalksUpToMom
# 83 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 85 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	warp MAP_SPINDA_ISLAND_HOME, 10, 43
# 87 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


# 90 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
SpinaIsland_PlayerHome_Movement_ArchieWalksUp:
# 91 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	walk_up
	step_end

# 94 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
SpinaIsland_PlayerHome_Movement_ArchieExits:
# 95 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	walk_faster_left
# 95 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	walk_faster_left
# 96 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	walk_faster_down
# 96 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	walk_faster_down
# 96 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	walk_faster_down
# 96 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	walk_faster_down
# 97 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	walk_faster_right
# 97 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	walk_faster_right
# 98 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	walk_faster_down
	step_end

# 101 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
SpinaIsland_PlayerHome_Movement_ArchieWalksUpToMom:
# 102 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	walk_left
# 102 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	walk_left
# 103 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	walk_up
# 103 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	walk_up
# 103 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	walk_up
# 103 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	walk_up
# 104 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	walk_right
# 104 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	walk_right
	step_end

SpinaIsland_PlayerHome_EventScript_Mom::
# 108 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 109 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	faceplayer
# 111 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	goto_if_set FLAG_REPAIRED_FAUCET, SpinaIsland_PlayerHome_EventScript_Mom_2
	checkitem ITEM_SALTY_LEMONADE
# 0 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpinaIsland_PlayerHome_EventScript_Mom_5
SpinaIsland_PlayerHome_EventScript_Mom_4:
# 225 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 226 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 227 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_9
# 231 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 232 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
SpinaIsland_PlayerHome_EventScript_Mom_1:
# 235 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 236 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 238 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return

SpinaIsland_PlayerHome_EventScript_Mom_2:
# 112 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 113 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_0
# 116 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 117 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
	goto SpinaIsland_PlayerHome_EventScript_Mom_1

SpinaIsland_PlayerHome_EventScript_Mom_3:
# 119 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_1
# 123 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpinaIsland_PlayerHome_EventScript_Mom_Text_2, SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 133 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 135 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SpinaIsland_PlayerHome_EventScript_Mom_9
	checkitem ITEM_WATER_STONE_2
# 0 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SpinaIsland_PlayerHome_EventScript_Mom_12
SpinaIsland_PlayerHome_EventScript_Mom_11:
# 215 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 216 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 217 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_9
# 221 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 222 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
	goto SpinaIsland_PlayerHome_EventScript_Mom_1

SpinaIsland_PlayerHome_EventScript_Mom_5:
# 118 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	goto_if_unset FLAG_GAVE_MOM_LEMONADE, SpinaIsland_PlayerHome_EventScript_Mom_3
	goto SpinaIsland_PlayerHome_EventScript_Mom_4

SpinaIsland_PlayerHome_EventScript_Mom_9:
# 136 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 137 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 138 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_4
# 141 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 142 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 144 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 145 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 146 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 150 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 151 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 153 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 10
# 154 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_BALL
# 155 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitse
# 156 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_BALL
# 157 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitse
# 158 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_BALL
# 159 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitse
# 160 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 20
# 162 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 163 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 164 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 165 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 167 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_ANGRY
# 168 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 169 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_6
# 173 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 174 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 176 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setflag FLAG_GAVE_MOM_LEMONADE
	goto SpinaIsland_PlayerHome_EventScript_Mom_1

SpinaIsland_PlayerHome_EventScript_Mom_10:
# 178 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_7
# 182 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpinaIsland_PlayerHome_EventScript_Mom_Text_2, SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 192 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 194 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SpinaIsland_PlayerHome_EventScript_Mom_16
	goto SpinaIsland_PlayerHome_EventScript_Mom_1

SpinaIsland_PlayerHome_EventScript_Mom_12:
# 177 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	goto_if_unset FLAG_GAVE_MOM_WATER_STONE, SpinaIsland_PlayerHome_EventScript_Mom_10
	goto SpinaIsland_PlayerHome_EventScript_Mom_11

SpinaIsland_PlayerHome_EventScript_Mom_16:
# 195 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 196 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 197 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_4
# 200 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 201 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 203 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 204 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 205 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_8
# 209 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 210 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 212 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setflag FLAG_GAVE_MOM_WATER_STONE
	goto SpinaIsland_PlayerHome_EventScript_Mom_1


SpindaIsland_PlayerHome_EventScript_Diary::
# 243 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 244 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Diary_Text_0
# 249 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_SpindaManual::
# 253 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_SpindaManual_Text_0, MSGBOX_SIGN
	return


SpindaIsland_PlayerHome_EventScript_Poem::
# 262 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 263 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Poem_Text_0, MSGBOX_DEFAULT
# 270 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 272 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 273 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 274 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 277 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 278 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 280 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpindaIsland_PlayerHome_EventScript_Map::
# 284 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 286 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 287 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 288 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Map_Text_0
# 291 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 292 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 294 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_Window::
# 298 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 300 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 301 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 302 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Window_Text_0
# 305 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 306 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 308 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_Window_Front::
# 312 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 314 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 315 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 316 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Window_Front_Text_0
# 319 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 320 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 322 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_EnterLivingRoom::
# 326 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 328 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 329 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 330 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 331 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 332 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterLeft
# 333 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 334 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 336 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 337 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 338 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0
# 342 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 343 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 344 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 346 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 347 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 348 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_1
# 351 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 352 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 353 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_2
# 356 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 357 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 359 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 360 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 361 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_3
# 366 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 367 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 368 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 370 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_NORTH
# 371 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 40
# 372 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 373 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 374 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 375 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 376 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 378 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 379 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 380 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_4
# 383 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_WEST
# 384 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 385 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 386 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_5
# 390 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 391 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 392 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_NORTH
# 394 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 395 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 396 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_6
# 399 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 400 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 402 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	goto_if_unset FLAG_TOOK_SPINDA, SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_2
SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_1:
# 412 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 2
# 414 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_2:
# 403 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 404 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 405 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_7
# 408 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 409 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
	goto SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_1


SpinaIsland_PlayerHome_EventScript_GetSpinda::
# 418 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 420 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removeobject VAR_LAST_TALKED
# 421 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	givemon SPECIES_SPINDA, 20
# 422 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setflag FLAG_RECEIVED_STARTER
# 424 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 425 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 426 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_GetSpinda_Text_0
# 429 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 431 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_WailmerDoll::
# 435 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 437 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 438 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 439 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_WailmerDoll_Text_0
# 442 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 443 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 445 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0:
# 21 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Little Archie$"

SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_1:
# 23 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "MOM! MOM!$"

SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_2:
# 38 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Open the tap!! The {COLOR BLUE}WATER{COLOR DARK_GRAY}'s running!!!$"

SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3:
# 41 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Mom$"

SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_4:
# 43 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Sure, honey! Thank you!\p"
	.string "(You sure took your sweet time!)$"

SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_5:
# 54 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "… … …\p"
	.string "Aahhhhhhh, finally…$"

SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_6:
# 66 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Alright, Archie, as promised, here's\n"
	.string "the {COLOR RED}sail{COLOR DARK_GRAY} I've sewn for you!$"

SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_7:
# 76 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Yay!!! It looks so COOL!\p"
	.string "Thanks mom kaybye!!!!$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_0:
# 114 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Have fun, sweetie! Don't drown,\n"
	.string "please!$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_1:
# 120 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Give mom the Salty Lemonade?$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_2:
# 130 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Give$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_3:
# 131 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Don't give$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_4:
# 139 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Here, mom!$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_5:
# 147 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Oh, good, some fresh lemonade! I'm so\n"
	.string "thirsty!\p"
	.string "Thanks, honey!$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_6:
# 170 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "What is wrong with you? This is super\n"
	.string "salty!\p"
	.string "Please take this away and don't do\n"
	.string "that again.$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_7:
# 179 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Give mom the {COLOR BLUE}WATER{COLOR DARK_GRAY} stone?$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_8:
# 206 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "What am I supposed to do with this?\n"
	.string "Lick it?\p"
	.string "Please turn the faucet on so I can\n"
	.string "drink some actual {COLOR BLUE}WATER{COLOR DARK_GRAY}!$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_9:
# 218 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Hurry up and turn the big faucet back\n"
	.string "on, please!\p"
	.string "I'll give you your {COLOR RED}sail{COLOR DARK_GRAY} when the tap's\n"
	.string "running.$"

SpindaIsland_PlayerHome_EventScript_Diary_Text_0:
# 245 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "“Dear diarry,\n"
	.string "The ship is almost finished.\n"
	.string "It is gonna be awsome.\p"
	.string "It will be even more beautiful then\n"
	.string "dad's.”$"

SpinaIsland_PlayerHome_EventScript_SpindaManual_Text_0:
# 254 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "“Super cool trick i taught spinda:\n"
	.string "using L and R makes her {COLOR RED}spin{COLOR DARK_GRAY}!\l"
	.string "i love my spinda, shes so awsome”$"

SpindaIsland_PlayerHome_EventScript_Poem_Text_0:
# 264 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "“A POEM BY ARCHIE\p"
	.string "Roses are blue\l"
	.string "Violetts are blue\l"
	.string "Everything is blue\l"
	.string "because its my favorite color.”$"

SpindaIsland_PlayerHome_EventScript_Poem_Text_1:
# 275 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I am such a poet.$"

SpindaIsland_PlayerHome_EventScript_Map_Text_0:
# 289 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "It's a map of the island!$"

SpinaIsland_PlayerHome_EventScript_Window_Text_0:
# 303 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Something's moving outside.$"

SpinaIsland_PlayerHome_EventScript_Window_Front_Text_0:
# 317 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I can see the beach!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0:
# 339 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Morning, little Archie!\p"
	.string "You're quite the early bird today!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_1:
# 349 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "That's cause today's the big day!!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_2:
# 354 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "You haven't forgotten about my super\n"
	.string "secret thing, right?$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_3:
# 362 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Of course not, darling! Your super\n"
	.string "secret thing is almost finished.\p"
	.string "I'll give it to you as soon as I'm done.\p"
	.string "But first, I sure could go for a nice,\n"
	.string "big, tall glass of icy {COLOR BLUE}WATER{COLOR DARK_GRAY}…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_4:
# 381 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Look at that, I forgot to turn the\n"
	.string "{COLOR BLUE}WATER{COLOR DARK_GRAY} back on…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_5:
# 387 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Archie, would you be a dear and go\n"
	.string "round the house to turn the big\l"
	.string "faucet on?\p"
	.string "And then I'll give it to you, I promise!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_6:
# 397 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Ughhhhhh, fine…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_7:
# 406 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Oh, and where's Spinda? Take her for a\n"
	.string "little walk, will you?$"

SpinaIsland_PlayerHome_EventScript_GetSpinda_Text_0:
# 427 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I could never forget you, Spinda!$"

SpinaIsland_PlayerHome_EventScript_WailmerDoll_Text_0:
# 440 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "How you doing, Wailmy?$"

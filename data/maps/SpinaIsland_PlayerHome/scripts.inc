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
	applymovement OBJ_EVENT_ID_PLAYER, SpinaIsland_PlayerHome_Movement_ArchieExits
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
	checkitem ITEM_SALTY_LEMONADE
# 0 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpinaIsland_PlayerHome_EventScript_Mom_5
SpinaIsland_PlayerHome_EventScript_Mom_4:
	checkitem ITEM_WATER_STONE_2
# 0 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpinaIsland_PlayerHome_EventScript_Mom_8
SpinaIsland_PlayerHome_EventScript_Mom_3:
# 178 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 179 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 180 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_6
# 184 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 185 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
SpinaIsland_PlayerHome_EventScript_Mom_1:
# 188 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 189 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 191 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return

SpinaIsland_PlayerHome_EventScript_Mom_2:
	checkitem ITEM_SALTY_LEMONADE
# 0 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpinaIsland_PlayerHome_EventScript_Mom_13
SpinaIsland_PlayerHome_EventScript_Mom_11:
	checkitem ITEM_WATER_STONE_2
# 0 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpinaIsland_PlayerHome_EventScript_Mom_18
SpinaIsland_PlayerHome_EventScript_Mom_16:
# 122 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 123 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 124 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_2
# 128 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	dynmultistack 0, 0, TRUE, 10, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 129 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 130 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 132 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SpinaIsland_PlayerHome_EventScript_Mom_21
# 174 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SpinaIsland_PlayerHome_EventScript_Mom_22
	goto SpinaIsland_PlayerHome_EventScript_Mom_1

SpinaIsland_PlayerHome_EventScript_Mom_5:
# 112 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	goto_if_unset FLAG_GAVE_MOM_LEMONADE, SpinaIsland_PlayerHome_EventScript_Mom_2
	goto SpinaIsland_PlayerHome_EventScript_Mom_4

SpinaIsland_PlayerHome_EventScript_Mom_8:
# 113 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	goto_if_unset FLAG_GAVE_MOM_WATER_STONE, SpinaIsland_PlayerHome_EventScript_Mom_2
	goto SpinaIsland_PlayerHome_EventScript_Mom_3

SpinaIsland_PlayerHome_EventScript_Mom_12:
# 116 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	dynmultipush SpinaIsland_PlayerHome_EventScript_Mom_Text_0, 0
	goto SpinaIsland_PlayerHome_EventScript_Mom_11

SpinaIsland_PlayerHome_EventScript_Mom_13:
# 115 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	goto_if_unset FLAG_GAVE_MOM_LEMONADE, SpinaIsland_PlayerHome_EventScript_Mom_12
	goto SpinaIsland_PlayerHome_EventScript_Mom_11

SpinaIsland_PlayerHome_EventScript_Mom_17:
# 120 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	dynmultipush SpinaIsland_PlayerHome_EventScript_Mom_Text_1, 0
	goto SpinaIsland_PlayerHome_EventScript_Mom_16

SpinaIsland_PlayerHome_EventScript_Mom_18:
# 119 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	goto_if_unset FLAG_GAVE_MOM_WATER_STONE, SpinaIsland_PlayerHome_EventScript_Mom_17
	goto SpinaIsland_PlayerHome_EventScript_Mom_16

SpinaIsland_PlayerHome_EventScript_Mom_21:
# 133 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 134 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 135 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_3
# 138 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 139 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 141 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 142 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 143 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_4
# 147 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 148 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 150 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 10
# 151 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_BALL
# 152 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitse
# 153 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_BALL
# 154 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitse
# 155 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_BALL
# 156 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitse
# 157 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 20
# 159 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 160 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 161 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 162 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 164 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_ANGRY
# 165 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 166 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Mom_Text_5
# 170 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 171 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 173 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setflag FLAG_GAVE_MOM_LEMONADE
	goto SpinaIsland_PlayerHome_EventScript_Mom_1

SpinaIsland_PlayerHome_EventScript_Mom_22:
# 175 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	call SpindaIsland_PlayerHome_EventScript_GiveWaterStoneToMom
	goto SpinaIsland_PlayerHome_EventScript_Mom_1


SpinaIsland_PlayerHome_EventScript_Fridge::
# 195 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 197 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpinaIsland_PlayerHome_EventScript_Fridge_2
# 206 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 207 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 208 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Fridge_Text_1
# 211 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 212 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
SpinaIsland_PlayerHome_EventScript_Fridge_1:
# 215 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return

SpinaIsland_PlayerHome_EventScript_Fridge_2:
# 198 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 199 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 200 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Fridge_Text_0
# 203 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 204 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
	goto SpinaIsland_PlayerHome_EventScript_Fridge_1


SpindaIsland_PlayerHome_EventScript_Bed::
# 219 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 221 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 222 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 223 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Bed_Text_0
# 226 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 227 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 229 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpindaIsland_PlayerHome_EventScript_GiveWaterStoneToMom::
# 233 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 235 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 236 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 237 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_GiveWaterStoneToMom_Text_0
# 240 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 241 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 243 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 244 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 245 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_GiveWaterStoneToMom_Text_1
# 249 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 250 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 252 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setflag FLAG_GAVE_MOM_WATER_STONE
# 254 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpindaIsland_PlayerHome_EventScript_Diary::
# 259 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 260 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Diary_Text_0
# 265 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_SpindaManual::
# 269 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 270 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_SpindaManual_Text_0
# 275 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 276 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setflag FLAG_READ_SPINDA_INSTRUCTIONS
# 277 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpindaIsland_PlayerHome_EventScript_Poem::
# 281 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 282 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Poem_Text_0, MSGBOX_DEFAULT
# 289 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 291 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 292 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 293 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Poem_Text_1
# 296 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 297 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 299 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpindaIsland_PlayerHome_EventScript_Map::
# 303 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 305 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 306 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 307 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpindaIsland_PlayerHome_EventScript_Map_Text_0
# 310 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 311 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 313 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_Window::
# 317 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 319 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 320 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 321 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Window_Text_0
# 324 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 325 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 327 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_Window_Front::
# 331 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 333 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 334 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 335 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_Window_Front_Text_0
# 338 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 339 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 341 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_EnterLivingRoom::
# 345 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 347 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 348 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 349 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 350 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 351 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterLeft
# 352 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 353 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 355 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 356 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 357 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0
# 361 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 362 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 363 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 365 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 366 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 367 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_1
# 370 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 371 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 372 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_2
# 375 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 376 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 378 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 379 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 380 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_3
# 385 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 386 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 387 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 389 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_NORTH
# 390 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 40
# 391 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	playse SE_PIN
# 392 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 393 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 394 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	delay 48
# 395 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	waitmovement 0
# 397 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_NORMAL
# 398 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 399 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_4
# 402 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_WEST
# 403 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 404 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 405 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_5
# 409 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 410 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 411 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	turnobject 1, DIR_NORTH
# 413 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 414 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 415 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_6
# 418 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 419 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 421 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	goto_if_unset FLAG_TOOK_SPINDA, SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_2
SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_1:
# 431 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 2
# 433 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_2:
# 422 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_MOM, EMOTE_HAPPY
# 423 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_3
# 424 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_7
# 427 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 428 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
	goto SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_1


SpinaIsland_PlayerHome_EventScript_GetSpinda::
# 437 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 439 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removeobject VAR_LAST_TALKED
# 440 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	givemon SPECIES_SPINDA, 20
# 441 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	setflag FLAG_RECEIVED_STARTER
# 443 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 444 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 445 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_GetSpinda_Text_0
# 448 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 450 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	release
	return


SpinaIsland_PlayerHome_EventScript_WailmerDoll::
# 454 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	lock
# 456 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 457 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	speakername SpinaIsland_PlayerHome_EventScript_FixedFaucet_Text_0
# 458 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	msgbox SpinaIsland_PlayerHome_EventScript_WailmerDoll_Text_0
# 461 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	closemessage
# 462 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	removefieldmugshot
# 464 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
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
# 116 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Give the Salty Lemonade$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_1:
# 120 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Give the {COLOR BLUE}WATER{COLOR DARK_GRAY} Stone$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_2:
# 125 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Hey mom!$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_3:
# 136 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Here you go, mom!$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_4:
# 144 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Oh, good, some fresh lemonade! I'm so\n"
	.string "thirsty!\p"
	.string "Thanks, honey!$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_5:
# 167 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "What is wrong with you? This is super\n"
	.string "salty!\p"
	.string "Please take this away and don't do\n"
	.string "that again.$"

SpinaIsland_PlayerHome_EventScript_Mom_Text_6:
# 181 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Go round the house and turn the big\n"
	.string "faucet back on, please!\p"
	.string "I'll give you your {COLOR RED}sail{COLOR DARK_GRAY} when the tap's\n"
	.string "running.$"

SpinaIsland_PlayerHome_EventScript_Fridge_Text_0:
# 201 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "If there'd been a sandwich in there, I\n"
	.string "would have eaten it.$"

SpinaIsland_PlayerHome_EventScript_Fridge_Text_1:
# 209 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I'm not hungry yet!$"

SpindaIsland_PlayerHome_EventScript_Bed_Text_0:
# 224 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "No time for naptime!$"

SpindaIsland_PlayerHome_EventScript_GiveWaterStoneToMom_Text_0:
# 238 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Here, mom!$"

SpindaIsland_PlayerHome_EventScript_GiveWaterStoneToMom_Text_1:
# 246 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "What am I supposed to do with this?\n"
	.string "Lick it?\p"
	.string "Please turn the faucet on so I can\n"
	.string "drink some actual {COLOR BLUE}WATER{COLOR DARK_GRAY}!$"

SpindaIsland_PlayerHome_EventScript_Diary_Text_0:
# 261 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "“Dear diarry,\n"
	.string "The ship is almost finished.\n"
	.string "It is gonna be awsome.\p"
	.string "It will be even more beautiful then\n"
	.string "dad's.”$"

SpinaIsland_PlayerHome_EventScript_SpindaManual_Text_0:
# 271 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "“Super cool trick i taught spinda:\n"
	.string "using L and R makes her {COLOR RED}spin{COLOR DARK_GRAY}!\l"
	.string "i love my spinda, shes so awsome”$"

SpindaIsland_PlayerHome_EventScript_Poem_Text_0:
# 283 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "“A POEM BY ARCHIE\p"
	.string "Roses are blue\l"
	.string "Violetts are blue\l"
	.string "Everything is blue\l"
	.string "because its my favorite color.”$"

SpindaIsland_PlayerHome_EventScript_Poem_Text_1:
# 294 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I am such a poet.$"

SpindaIsland_PlayerHome_EventScript_Map_Text_0:
# 308 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "It's a map of the island!$"

SpinaIsland_PlayerHome_EventScript_Window_Text_0:
# 322 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Something's moving outside.$"

SpinaIsland_PlayerHome_EventScript_Window_Front_Text_0:
# 336 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I can see the beach!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_0:
# 358 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Morning, little Archie!\p"
	.string "You're quite the early bird today!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_1:
# 368 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "That's cause today's the big day!!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_2:
# 373 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "You haven't forgotten about my super\n"
	.string "secret thing, right?$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_3:
# 381 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Of course not, darling! Your super\n"
	.string "secret thing is almost finished.\p"
	.string "I'll give it to you as soon as I'm done.\p"
	.string "But first, I sure could go for a nice,\n"
	.string "big, tall glass of icy {COLOR BLUE}WATER{COLOR DARK_GRAY}…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_4:
# 400 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Look at that, I forgot to turn the\n"
	.string "{COLOR BLUE}WATER{COLOR DARK_GRAY} back on…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_5:
# 406 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Archie, would you be a dear and go\n"
	.string "round the house to turn the big\l"
	.string "faucet on?\p"
	.string "And then I'll give it to you, I promise!$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_6:
# 416 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Ughhhhhh, fine…$"

SpinaIsland_PlayerHome_EventScript_EnterLivingRoom_Text_7:
# 425 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "Oh, and where's Spinda? Take her for a\n"
	.string "little walk, will you?$"

SpinaIsland_PlayerHome_EventScript_GetSpinda_Text_0:
# 446 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "I could never forget you, Spinda!$"

SpinaIsland_PlayerHome_EventScript_WailmerDoll_Text_0:
# 459 "data/maps/SpinaIsland_PlayerHome/scripts.pory"
	.string "How you doing, Wailmy?$"

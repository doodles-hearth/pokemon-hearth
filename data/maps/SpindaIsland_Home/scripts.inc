SpindaIsland_Home_MapScripts::
# 7 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 14 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD
# 29 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 8 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 11 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWPOKE )
	return

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 9 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWBRO )
	return

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD:
# 16 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_REPLACED_WHEEL, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_2
SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 20 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_5
SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_4:
# 25 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OPENED_CHEST, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_7
	return

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 17 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 27, 50, METATILE_SpindaIslandSecondary_FaucetWheel, TRUE
	goto SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_1

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_5:
# 21 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 14, 27, METATILE_SpindaIsland_Grass, FALSE
# 22 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 14, 28, METATILE_SpindaIslandSecondary_RoofProfileTopRightCorner, FALSE
	goto SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_4

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_7:
# 26 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 53, 27, METATILE_SpindaIsland_EmptyChest, TRUE
	return

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 30 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script_2 VAR_SPINDA_ISLAND_INTRO_STATE, 2, SpindaIsland_Home_EventScript_MainQuestRecap
# 31 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script_2 VAR_REPAIRED_FAUCET, 2, SpindaIsland_Home_EventScript_GoToSail
	.2byte 0


SpindaIsland_Home_EventScript_GoToSail::
# 36 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 37 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_REPAIRED_FAUCET, 3
# 38 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Movement_GoToSail
# 39 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 41 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 42 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 43 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_GoToSail_Text_1
# 46 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 47 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 49 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_FU_ZAKU
# 50 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 21, DIR_SOUTH
# 51 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_BADASS_SAIL
# 52 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 54 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 56 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 57 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 58 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_GoToSail_Text_2
# 61 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 62 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_GoToSail_Text_3
# 66 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 67 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 69 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Movement_PlayerEntersRaft
# 70 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 72 "data/maps/SpindaIsland_Home/scripts.pory"
	special SpawnCameraObject
# 73 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement 21, SpindaIsland_Home_Movement_RaftGoesToIsland
# 74 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SpindaIsland_Home_Movement_RaftGoesToIsland
# 75 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 100
# 76 "data/maps/SpindaIsland_Home/scripts.pory"
	warpsilent MAP_SPINDA_ISLAND_SHUPPET_HOUSE_ATTIC, 5, 0
# 78 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


# 81 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_GoToSail:
# 82 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_down
# 82 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_down
# 82 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_down
# 82 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_down
# 82 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_down
# 83 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_right
# 83 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_right
# 83 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_right
# 83 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_right
# 83 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_right
# 84 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_down
# 84 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_down
# 84 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_down
	step_end

SpindaIsland_Home_EventScript_MainQuestRecap::
# 88 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 89 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 90 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 91 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 95 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 96 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 97 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 3
# 98 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodOtherSide::
# 102 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 103 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_METAPOD_OTHER_SIDE, 1
# 104 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_ArchiesHouseSign::
# 110 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ArchiesHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_TryToBlindZiggy::
# 116 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 117 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_SWITCH
# 118 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 119 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_LEER
# 120 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, 0
# 121 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, 0
# 122 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 123 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 30
# 125 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_TryToBlindZiggy_Text_0
# 126 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_TryToBlindZiggy_Text_1
# 127 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 128 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_TryToBlindZiggy_Text_2
# 129 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 130 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 131 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_BobsHouseSign::
# 135 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_CynthiasHouseSign::
# 139 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_CynthiasHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_SadManHome_Back::
# 143 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 144 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_HIDE_MAN_CANT_GO_HOME, SpindaIsland_Home_EventScript_SadManHome_Back_2
# 153 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_RUSTY_BOLT, SpindaIsland_Home_EventScript_SadManHome_Back_5
# 162 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 163 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 164 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_2
# 167 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 168 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 170 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_SadManHome_Back_Text_3
# 171 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_4
# 175 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 177 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 179 "data/maps/SpindaIsland_Home/scripts.pory"
	clearflag FLAG_HIDE_MAN_CANT_GO_HOME
# 180 "data/maps/SpindaIsland_Home/scripts.pory"
	setobjectxyperm 6, 42, 24
# 181 "data/maps/SpindaIsland_Home/scripts.pory"
	addobject 6
# 182 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement 6, SpindaIsland_Home_Movement_SadManExitsHouse
# 183 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Movement_PlayerMakesWay
# 184 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 185 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 6
# 186 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 187 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 188 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 189 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_SadManHome_Back_Text_3
# 190 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_5
# 193 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 194 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 195 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_RUSTY_BOLT
# 196 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_RUSTY_BOLT
# 197 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement 6, SpindaIsland_Home_Movement_SadManReEntersHouse
# 198 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 199 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 200 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 6
# 201 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_MAN_CANT_GO_HOME
# 202 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 204 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 206 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_SadManHome_Back_8
# 239 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 240 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 241 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_9
# 246 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 247 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_SadManHome_Back_1:
# 251 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_SadManHome_Back_2:
# 145 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 146 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 147 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_0
# 150 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 151 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1

SpindaIsland_Home_EventScript_SadManHome_Back_5:
# 154 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 155 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 156 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_1
# 159 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 160 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1

SpindaIsland_Home_EventScript_SadManHome_Back_8:
# 207 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 208 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 209 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_6
# 212 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 213 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 215 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 217 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 218 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 219 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 220 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 221 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 223 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 224 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 225 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_7
# 229 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 230 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 231 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_8
# 234 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 235 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 237 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1


SpindaIsland_Home_EventScript_ICanNeverGoHome::
# 255 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 256 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 257 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SAD
# 258 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_0
# 259 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_1, MSGBOX_NPC
# 263 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 264 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_Dad::
# 268 "data/maps/SpindaIsland_Home/scripts.pory"
	lockall
# 269 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 7, DIR_SOUTH
# 270 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OBTAINED_LEMONADE, SpindaIsland_Home_EventScript_Dad_2
# 280 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SPOKE_TO_DAD, SpindaIsland_Home_EventScript_Dad_6
# 289 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 290 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 291 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_3
# 295 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 296 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Dad_5:
# 299 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_SALTY_LEMONADE
# 301 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 302 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 303 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 304 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_4
# 308 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 309 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 311 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 10
# 312 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 313 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 314 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 315 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 316 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 317 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 318 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 20
# 320 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 321 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 322 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 323 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 324 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 326 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_DISGUSTED
# 327 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 328 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_5
# 332 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 333 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 335 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_GRINNING
# 336 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 337 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_6
# 340 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 341 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 342 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_7
# 345 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 346 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_EMBARRASSED
# 347 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_8
# 350 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 351 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 352 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_9
# 356 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 357 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 359 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_OBTAINED_LEMONADE
# 360 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SPOKE_TO_DAD
SpindaIsland_Home_EventScript_Dad_1:
# 362 "data/maps/SpindaIsland_Home/scripts.pory"
	releaseall
	return

SpindaIsland_Home_EventScript_Dad_2:
# 271 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_EMBARRASSED
# 272 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 273 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_1
# 277 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 278 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_1

SpindaIsland_Home_EventScript_Dad_6:
# 281 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 282 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 283 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_2
# 286 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 287 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_5


SpindaIsland_Home_EventScript_Dad_FromSide::
# 366 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 367 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 368 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OBTAINED_LEMONADE, SpindaIsland_Home_EventScript_Dad_FromSide_2
# 378 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SPOKE_TO_DAD, SpindaIsland_Home_EventScript_Dad_FromSide_6
# 387 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 388 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 389 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_FromSide_Text_1
# 394 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 395 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Dad_FromSide_5:
# 397 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SPOKE_TO_DAD
SpindaIsland_Home_EventScript_Dad_FromSide_1:
# 399 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Dad_FromSide_2:
# 369 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_EMBARRASSED
# 370 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 371 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_1
# 375 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 376 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_FromSide_1

SpindaIsland_Home_EventScript_Dad_FromSide_6:
# 379 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_NORMAL
# 380 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 381 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_FromSide_Text_0
# 384 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 385 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_FromSide_5


SpindaIsland_Home_EventScript_LemonadeStandSign::
# 403 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_LemonadeStandSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_MainStreetSign::
# 410 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MainStreetSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_MadelineSign::
# 416 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MadelineSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_PoemGirl::
# 422 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 424 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_POEM_GIRL, SpindaIsland_Home_EventScript_PoemGirl_2
# 438 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
# 439 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 441 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 443 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 444 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 445 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_2
# 450 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 451 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 453 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_3, SpindaIsland_Home_EventScript_PoemGirl_Text_4, SpindaIsland_Home_EventScript_PoemGirl_Text_5
# 465 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 466 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_6
# 511 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_7
# 606 "data/maps/SpindaIsland_Home/scripts.pory"
	case 2, SpindaIsland_Home_EventScript_PoemGirl_8
SpindaIsland_Home_EventScript_PoemGirl_1:
# 704 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 705 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 706 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_PoemGirl_2:
# 425 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 426 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 427 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 428 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_1
# 431 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 432 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 434 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 435 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 436 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_6:
# 467 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_6, SpindaIsland_Home_EventScript_PoemGirl_Text_7
# 478 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 479 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_11
# 490 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_12
SpindaIsland_Home_EventScript_PoemGirl_9:
# 503 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 504 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 505 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_12
# 509 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 510 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_7:
# 512 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_13, SpindaIsland_Home_EventScript_PoemGirl_Text_14
# 522 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 524 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_14
# 583 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_15
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_8:
# 607 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_24, SpindaIsland_Home_EventScript_PoemGirl_Text_13
# 618 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 620 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_17
# 643 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_18
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_11:
# 480 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_8, SpindaIsland_Home_EventScript_PoemGirl_Text_9
	goto SpindaIsland_Home_EventScript_PoemGirl_9

SpindaIsland_Home_EventScript_PoemGirl_12:
# 491 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_10, SpindaIsland_Home_EventScript_PoemGirl_Text_11
	goto SpindaIsland_Home_EventScript_PoemGirl_9

SpindaIsland_Home_EventScript_PoemGirl_14:
# 525 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_15, SpindaIsland_Home_EventScript_PoemGirl_Text_16
# 536 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 538 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_20
# 560 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_21
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_15:
# 584 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_21, SpindaIsland_Home_EventScript_PoemGirl_Text_22
# 595 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 596 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 597 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_23
# 603 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 604 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_17:
# 621 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_25, SpindaIsland_Home_EventScript_PoemGirl_Text_26
# 632 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 633 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 634 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_27
# 639 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 640 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_18:
# 644 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_28, SpindaIsland_Home_EventScript_PoemGirl_Text_29
# 655 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 656 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_23
# 666 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_24
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_20:
# 539 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_17, SpindaIsland_Home_EventScript_PoemGirl_Text_18
# 550 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 551 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 552 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_19
# 556 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 557 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_21:
# 561 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_17, SpindaIsland_Home_EventScript_PoemGirl_Text_18
# 572 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 573 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 574 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_20
# 578 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 579 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_23:
# 657 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 658 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 659 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_27
# 664 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 665 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_24:
# 667 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_30
# 676 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 677 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 678 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_31
# 685 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 686 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 688 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_GRASS_BLADE
# 690 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 691 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 692 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_32
# 696 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 697 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 699 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_POEM_GIRL
	goto SpindaIsland_Home_EventScript_PoemGirl_1


SpindaIsland_Home_EventScript_Sunbather::
# 710 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 711 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_SUNBATHER, EMOTE_NORMAL
# 712 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Sunbather_Text_0
# 713 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Sunbather_Text_1
# 717 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 718 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 719 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 720 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 722 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_SUNBATHER, EMOTE_PENSIVE
# 723 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Sunbather_Text_0
# 724 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Sunbather_Text_2
# 727 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 728 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 729 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 730 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 731 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_Slowpoke::
# 735 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 736 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_Slowpoke_2
# 747 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 748 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
# 749 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_2
# 750 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_3
# 753 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 754 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	checkitem ITEM_WHITE_SEASHELL
# 0 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SpindaIsland_Home_Slowpoke_5
SpindaIsland_Home_Slowpoke_1:
# 837 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_Slowpoke_2:
# 737 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 738 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
# 739 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_0
# 740 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_1
# 743 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 744 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_5:
# 757 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 758 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 759 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_4
# 764 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Slowpoke_Text_5, SpindaIsland_Home_Slowpoke_Text_6
# 774 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 775 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 777 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 778 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_Slowpoke_8
# 824 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_Slowpoke_9
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_8:
# 779 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 780 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 781 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_7
# 785 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 786 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 788 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_WHITE_SEASHELL
# 790 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWBRO )
# 791 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SHELLDER, CRY_MODE_NORMAL
# 792 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 793 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject VAR_LAST_TALKED
# 794 "data/maps/SpindaIsland_Home/scripts.pory"
	addobject VAR_LAST_TALKED
# 795 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_BITE
# 796 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, SpindaIsland_Home_Movement_Slowpoke
# 797 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 798 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement VAR_LAST_TALKED
# 799 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 801 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
# 802 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_0
# 803 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_8
# 806 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 807 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 809 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SHOCKED
# 810 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 811 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_9
# 815 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 816 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 817 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_10
# 820 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 821 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 823 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SLOWPOKE_EVOLVED
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_9:
# 825 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_FAINT
# 826 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_2
# 827 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_11
# 831 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 832 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Slowpoke_1


SpindaIsland_Home_EventScript_Metapod::
# 841 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 842 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Metapod_Text_0
# 843 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_METAPOD, CRY_MODE_NORMAL
# 844 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Metapod_Text_1
# 847 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 848 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 849 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoysFuckOff::
# 853 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 854 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 855 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 856 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_1
# 860 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_NORMAL
# 861 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_2
# 865 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 867 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_TO_BLACK
# 868 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_METAPOD_BATTLE
# 869 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 1
# 870 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 2
# 871 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 3
# 872 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 4
# 873 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 60
# 874 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 875 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 40
# 876 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin::
# 880 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 881 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 882 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 883 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_0
# 887 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_NORMAL
# 888 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_1
# 892 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 893 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 895 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_TO_BLACK
# 896 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_METAPOD_BATTLE
# 897 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 1
# 898 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 2
# 899 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 3
# 900 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 4
# 901 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 60
# 902 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 903 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 40
# 904 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoy::
# 908 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 909 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_METAPOD_OTHER_SIDE, 1
	goto_if_eq SpindaIsland_Home_EventScript_MetapodBoy_2
SpindaIsland_Home_EventScript_MetapodBoy_1:
# 912 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 913 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 914 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Text_0
# 917 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 918 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 920 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 922 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_FINGER
# 923 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 924 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Text_1
# 927 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 928 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 930 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 932 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 933 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 934 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Text_2
# 937 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 938 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 940 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 941 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 942 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 943 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 944 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 945 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MetapodBoy_2:
# 910 "data/maps/SpindaIsland_Home/scripts.pory"
	goto SpindaIsland_Home_EventScript_MetapodBoysFuckOff
	goto SpindaIsland_Home_EventScript_MetapodBoy_1


SpindaIsland_Home_EventScript_MetapodBoy_Bussin::
# 949 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 950 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_METAPOD_OTHER_SIDE, 1
	goto_if_eq SpindaIsland_Home_EventScript_MetapodBoy_Bussin_2
SpindaIsland_Home_EventScript_MetapodBoy_Bussin_1:
# 953 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 954 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 955 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_0
# 958 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 959 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 961 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 963 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_FINGER
# 964 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 965 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_1
# 968 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 969 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 971 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 973 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 974 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 975 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_2
# 978 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 979 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 981 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 982 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 983 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 984 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 985 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 986 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_2:
# 951 "data/maps/SpindaIsland_Home/scripts.pory"
	goto SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin
	goto SpindaIsland_Home_EventScript_MetapodBoy_Bussin_1


SpindaIsland_Home_PhotoCameraWrongDir::
# 990 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 991 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 992 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 993 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_PhotoCameraWrongDir_Text_0
# 996 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 997 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 998 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_FaucetShopSign::
# 1002 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_FaucetShopSign_Text_0, MSGBOX_SIGN
	return


# 1009 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_SadManExitsHouse:
# 1010 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
	step_end

# 1013 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_SadManReEntersHouse:
# 1014 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 1015 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1016 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
	step_end

# 1019 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_PlayerMakesWay:
# 1020 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 1021 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1022 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
	step_end

# 1025 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_Slowpoke:
# 1026 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 1027 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 1028 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
# 1029 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1029 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1029 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1030 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 1031 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1032 "data/maps/SpindaIsland_Home/scripts.pory"
	face_down
# 1033 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1034 "data/maps/SpindaIsland_Home/scripts.pory"
	face_left
# 1035 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1036 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 1037 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1038 "data/maps/SpindaIsland_Home/scripts.pory"
	face_player
# 1039 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1039 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1039 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1040 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 1041 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 1042 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 1043 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
# 1044 "data/maps/SpindaIsland_Home/scripts.pory"
	emote_heart
# 1045 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1045 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1045 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
	step_end

SpindaIsland_Home_SlowpokeMistress::
# 1049 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1050 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1051 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_SLOWPOKE_REWARD, SpindaIsland_Home_SlowpokeMistress_2
# 1060 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_SlowpokeMistress_3
# 1104 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_SWEAT
# 1105 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 1106 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_7
# 1109 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1110 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 1111 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_8
# 1115 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1116 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_SlowpokeMistress_1:
# 1118 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_SlowpokeMistress_2:
# 1052 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_HAPPY
# 1053 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 1054 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_1
# 1058 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1059 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_SlowpokeMistress_1

SpindaIsland_Home_SlowpokeMistress_3:
# 1061 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 1062 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 1063 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1064 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1065 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1067 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_SURPRISED
# 1068 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 1069 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_2
# 1073 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1074 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 1075 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_3
# 1078 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1079 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_HAPPY
# 1080 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_4
# 1083 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1084 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 1085 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_5
# 1088 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1089 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1091 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_WATER_STONE_2
# 1093 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 1094 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1095 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_6
# 1099 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1100 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1102 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_SLOWPOKE_REWARD
	goto SpindaIsland_Home_SlowpokeMistress_1


SpindaIsland_Home_EventScript_Juan::
# 1122 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1123 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1124 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 1125 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Juan_Text_0
# 1126 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_TALKED_TO_JUAN_ABOUT_PUBES, SpindaIsland_Home_EventScript_Juan_2
# 1150 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_5
# 1161 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SURPRISED
# 1162 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_6
# 1165 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1166 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1167 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_TALKED_TO_JUAN_ABOUT_PUBES
SpindaIsland_Home_EventScript_Juan_1:
# 1170 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Juan_2:
# 1127 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_1
# 1131 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_Juan_Text_2, SpindaIsland_Home_EventScript_Juan_Text_3
# 1142 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 1143 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_4
# 1147 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1148 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Juan_1


SpindaIsland_Home_EventScript_Machoke::
# 1174 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1175 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1176 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
# 1177 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_TALKED_TO_JUAN_ABOUT_PUBES, SpindaIsland_Home_EventScript_Machoke_2
# 1180 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Machoke_Text_1
SpindaIsland_Home_EventScript_Machoke_1:
# 1182 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Machoke_Text_2
# 1185 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1186 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1187 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Machoke_2:
# 1178 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Machoke_Text_0
	goto SpindaIsland_Home_EventScript_Machoke_1


SpindaIsland_Home_EventScript_Lisa::
# 1191 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1192 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1193 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL_BLACK, EMOTE_NORMAL
# 1194 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Lisa_Text_0
# 1195 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Lisa_Text_1
# 1198 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1199 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1200 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_OldWoman::
# 1204 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1205 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1206 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_SHUPPET_QUEST_STARTED, SpindaIsland_Home_EventScript_OldWoman_2
# 1217 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_HIDE_SHUPPETS, SpindaIsland_Home_EventScript_OldWoman_3
SpindaIsland_Home_EventScript_OldWoman_1:
# 1228 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_HIDE_SHUPPETS, SpindaIsland_Home_EventScript_OldWoman_7
SpindaIsland_Home_EventScript_OldWoman_6:
# 1285 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_OldWoman_2:
# 1207 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1208 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1209 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1210 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_1
# 1214 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1215 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1216 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SHUPPET_QUEST_STARTED
	goto SpindaIsland_Home_EventScript_OldWoman_1

SpindaIsland_Home_EventScript_OldWoman_3:
# 1218 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1219 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1220 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1221 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_2
# 1224 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1225 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_OldWoman_1

SpindaIsland_Home_EventScript_OldWoman_7:
# 1229 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1230 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1231 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_2
# 1234 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1235 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1237 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1238 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1239 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_3
# 1242 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1243 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1245 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1246 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1247 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_4
# 1250 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 1251 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_5
# 1256 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1257 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1259 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_PB_AND_J
# 1261 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 1262 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_6
# 1265 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1266 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1268 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 1269 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject VAR_LAST_TALKED
# 1270 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 1271 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1272 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_OLD_WOMAN
# 1274 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1275 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1276 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_7
# 1280 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1281 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1283 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_OldWoman_6


SpindaIsland_Home_EventScript_OldWomansDoor::
# 1289 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1291 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1292 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1293 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWomansDoor_Text_0
# 1296 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1297 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1299 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_Chest::
# 1303 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1304 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OPENED_CHEST, SpindaIsland_Home_EventScript_Chest_2
# 1313 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1314 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1315 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Chest_Text_1
# 1319 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1320 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1322 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 53, 27, METATILE_SpindaIsland_EmptyChest, TRUE
# 1323 "data/maps/SpindaIsland_Home/scripts.pory"
	special DrawWholeMapView
# 1325 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_OPENED_CHEST
# 1326 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_PRECIOUS_BOLT
# 1328 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_Chest_5
# 1341 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1342 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1343 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Chest_Text_3
# 1346 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1347 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Chest_Text_4
# 1351 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1352 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
SpindaIsland_Home_EventScript_Chest_1:
# 1355 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Chest_2:
# 1305 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1306 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1307 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Chest_Text_0
# 1310 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1311 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
	goto SpindaIsland_Home_EventScript_Chest_1

SpindaIsland_Home_EventScript_Chest_5:
# 1329 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1330 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1331 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Chest_Text_2
# 1336 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1337 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1339 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_Chest_1


SpindaIsland_Home_CarBoy::
# 1359 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1360 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1361 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_BOY, EMOTE_NORMAL
# 1362 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarBoy_Text_0
# 1363 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarBoy_Text_1
# 1366 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1367 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1368 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1369 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1370 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_CarGirl::
# 1374 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1375 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_NICKEL, SpindaIsland_Home_CarGirl_2
# 1385 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_REPLACED_WHEEL, SpindaIsland_Home_CarGirl_3
# 1402 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_LOOKING_FOR_WHEEL_REPLACEMENT, SpindaIsland_Home_CarGirl_4
# 1412 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1413 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1414 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1415 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_4
# 1422 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1423 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1425 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_LOOKING_FOR_WHEEL_REPLACEMENT
SpindaIsland_Home_CarGirl_1:
# 1428 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1429 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1431 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_CarGirl_2:
# 1376 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1377 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1378 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1379 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_1
# 1382 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1383 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_CarGirl_1

SpindaIsland_Home_CarGirl_3:
# 1386 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1387 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1388 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1389 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_2
# 1397 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1398 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1400 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_RUSTY_NICKEL
# 1401 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_NICKEL
	goto SpindaIsland_Home_CarGirl_1

SpindaIsland_Home_CarGirl_4:
# 1403 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1404 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 1405 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1406 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_3
# 1409 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1410 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_CarGirl_1


SpindaIsland_Home_EventScript_MissingWheel::
# 1435 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1436 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_REPLACED_WHEEL, SpindaIsland_Home_EventScript_MissingWheel_2
# 1445 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1446 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1447 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MissingWheel_Text_1
# 1451 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1452 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_MissingWheel_1:
# 1454 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MissingWheel_2:
# 1437 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1438 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1439 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MissingWheel_Text_0
# 1442 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1443 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_MissingWheel_1


SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet::
# 1458 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1460 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_1
# 1491 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1492 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1493 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_2
# 1496 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1497 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	return

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_1:
# 1461 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1462 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1463 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_0
# 1466 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1467 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1469 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1471 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_CLICK
# 1472 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 27, 50, METATILE_SpindaIslandSecondary_FaucetWheel, TRUE
# 1473 "data/maps/SpindaIsland_Home/scripts.pory"
	special DrawWholeMapView
# 1474 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1476 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1478 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1479 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1480 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_1
# 1483 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1484 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1486 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_BROKEN_FAUCET
# 1487 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_REPLACED_WHEEL
# 1489 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_SurveyedWheel::
# 1502 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1503 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_SurveyedWheel_4
SpindaIsland_Home_EventScript_SurveyedWheel_3:
# 1561 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1562 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1563 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_0
# 1566 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1567 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_SurveyedWheel_1:
# 1569 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_SurveyedWheel_2:
# 1504 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1505 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1506 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_0
# 1509 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1510 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1511 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_1
# 1515 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
	checkitem ITEM_BORROWED_PLIERS
# 0 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_EventScript_SurveyedWheel_7
# 1553 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1554 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_6
# 1557 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1558 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SurveyedWheel_1

SpindaIsland_Home_EventScript_SurveyedWheel_4:
# 1503 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_FOUND_TOUGH_BOLT, SpindaIsland_Home_EventScript_SurveyedWheel_2
	goto SpindaIsland_Home_EventScript_SurveyedWheel_3

SpindaIsland_Home_EventScript_SurveyedWheel_7:
# 1518 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1519 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_2
# 1522 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1523 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1525 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 15, DIR_EAST
# 1526 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1527 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1528 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_3
# 1531 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1532 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1534 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1535 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1536 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_4
# 1539 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1540 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1542 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 15, DIR_NORTH
# 1543 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1545 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1546 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1547 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_5
# 1550 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1551 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SurveyedWheel_1


SpindaIsland_Home_EventScript_Raft::
# 1573 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1574 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1575 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1576 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Raft_Text_0
# 1580 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1581 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1582 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_ThisIsConvenient::
# 1586 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1588 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_BROKE, SpindaIsland_Home_EventScript_ThisIsConvenient_2
SpindaIsland_Home_EventScript_ThisIsConvenient_1:
# 1603 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_ThisIsConvenient_2:
# 1589 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 1590 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 20
# 1592 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1593 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1594 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ThisIsConvenient_Text_0
# 1597 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1598 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1600 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_PASSED_IN_FRONT_OF_FAUCET_SHOP, 1
	goto SpindaIsland_Home_EventScript_ThisIsConvenient_1


SpindaIsland_Home_EventScript_Pot::
# 1607 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1608 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SALTED_DISH, SpindaIsland_Home_EventScript_Pot_2
# 1617 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1618 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1619 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pot_Text_1
# 1622 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_DISGUSTED
# 1623 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pot_Text_2
# 1627 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1628 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Pot_1:
# 1630 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Pot_2:
# 1609 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1610 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1611 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pot_Text_0
# 1614 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1615 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Pot_1


SpindaIsland_Home_EventScript_SaltDish::
# 1634 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1635 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_SALTY_LEMONADE
# 1636 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SALTED_DISH
# 1637 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1638 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1639 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SaltDish_Text_0
# 1642 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1643 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1645 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_POISON_POWDER
# 1646 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1647 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_POISON_POWDER
# 1648 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1649 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_POISON_POWDER
# 1650 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1652 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1653 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1654 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SaltDish_Text_1
# 1657 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1658 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1660 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_FeedZiggy::
# 1664 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1665 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1666 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1667 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_FeedZiggy_2
# 1672 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_FeedZiggy_Text_1
SpindaIsland_Home_EventScript_FeedZiggy_1:
# 1676 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1677 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1678 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_FeedZiggy_2:
# 1668 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_FeedZiggy_Text_0
	goto SpindaIsland_Home_EventScript_FeedZiggy_1


SpindaIsland_Home_EventScript_Cook::
# 1682 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1683 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1685 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_GOT_OIL, SpindaIsland_Home_EventScript_Cook_2
# 1695 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SALTED_DISH, SpindaIsland_Home_EventScript_Cook_3
# 1747 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_SAD
# 1748 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1749 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_5
# 1755 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1756 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1758 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_COOK_SAD
SpindaIsland_Home_EventScript_Cook_1:
# 1761 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Cook_2:
# 1686 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_NORMAL
# 1687 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1688 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_1
# 1692 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1693 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Cook_1

SpindaIsland_Home_EventScript_Cook_3:
# 1696 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1697 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1698 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_2
# 1701 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1702 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1704 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_SAD
# 1705 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1706 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_3
# 1709 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1710 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1713 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 20
# 1715 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_SAD
# 1716 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1717 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pot_Text_1
# 1720 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1721 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1723 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 1724 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 1725 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1726 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1727 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1729 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_NORMAL
# 1730 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1731 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_4
# 1738 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1739 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1741 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_COOK_SAD
# 1742 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_GOT_OIL
# 1743 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_COOKING_OIL
# 1745 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_Cook_1


SpindaIsland_Home_EventScript_Zigzagoon::
# 1765 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1766 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_ZIGGY_ASLEEP, SpindaIsland_Home_EventScript_Zigzagoon_2
# 1775 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_ENCOUNTER
# 1776 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_TryToBlindZiggy_Text_0
# 1777 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Zigzagoon_Text_2
# 1780 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 1781 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Zigzagoon_1:
# 1783 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Zigzagoon_2:
# 1767 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_SNORE
# 1768 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Zigzagoon_Text_0
# 1769 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Zigzagoon_Text_1
# 1772 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1773 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Zigzagoon_1


SpindaIsland_Home_EventScript_Pliers::
# 1787 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1788 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_ZIGGY_ASLEEP, SpindaIsland_Home_EventScript_Pliers_2
# 1802 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SAW_PLIERS, SpindaIsland_Home_EventScript_Pliers_5
# 1812 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_Pliers_8
# 1842 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1843 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1844 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_5
SpindaIsland_Home_EventScript_Pliers_1:
# 1852 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Pliers_2:
# 1789 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject VAR_LAST_TALKED
# 1790 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_BORROWED_PLIERS
# 1791 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_PICKED_UP_PLIERS
# 1793 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_DISGUSTED
# 1794 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1795 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_0
# 1799 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1800 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Pliers_1

SpindaIsland_Home_EventScript_Pliers_5:
# 1803 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1804 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1805 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_1
# 1809 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1810 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Pliers_1

SpindaIsland_Home_EventScript_Pliers_8:
# 1813 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1814 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1815 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_2
# 1819 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1820 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_3
# 1823 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1824 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1826 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_ENCOUNTER
# 1827 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_TryToBlindZiggy_Text_0
# 1828 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Zigzagoon_Text_2
# 1831 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 1832 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1833 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1834 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_4
# 1837 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1838 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1840 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SAW_PLIERS
	goto SpindaIsland_Home_EventScript_Pliers_1


SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy::
# 1856 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1857 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
# 1858 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1860 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_ENCOUNTER
# 1861 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_TryToBlindZiggy_Text_0
# 1862 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_0
# 1865 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 1866 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1868 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 30
# 1870 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_FAINT
# 1871 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Zigzagoon_Text_0
# 1872 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_1
# 1875 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 1876 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_SNORE
# 1877 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_2
# 1880 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1882 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1883 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1884 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_3
# 1888 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1889 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1891 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_ZIGGY_ASLEEP
# 1892 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_UseGrassBlade::
# 1896 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1897 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
# 1898 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1899 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_BobsDoor::
# 1903 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1904 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_BobsHouseSign_Text_0
# 1905 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsDoor_Text_0
# 1908 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1909 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1910 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsDoor_Text_1
# 1913 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 1914 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsDoor_Text_2
# 1917 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1918 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1919 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_CynthiasDoor::
# 1923 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1924 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1925 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1926 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_CynthiasDoor_Text_0
# 1930 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1931 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1932 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


# 1936 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_RaftGoesToIsland:
# 1937 "data/maps/SpindaIsland_Home/scripts.pory"
	face_left
# 1938 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 1939 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_anim
# 1940 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1940 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1940 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1940 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1940 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1940 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1940 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
	step_end

# 1943 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_PlayerEntersRaft:
# 1944 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1945 "data/maps/SpindaIsland_Home/scripts.pory"
	set_invisible
	step_end

SpindaIsland_Home_EventScript_GoToSail_Text_0:
# 42 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_EventScript_GoToSail_Text_1:
# 44 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "At last! I can finally set sail!!$"

SpindaIsland_Home_EventScript_GoToSail_Text_2:
# 59 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And voilà!$"

SpindaIsland_Home_EventScript_GoToSail_Text_3:
# 63 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Goodbye, Spinda Island…\p"
	.string "Hello, adventure!$"

SpindaIsland_Home_EventScript_MainQuestRecap_Text_0:
# 92 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Alright! The quicker mom gets her\n"
	.string "glass of {COLOR BLUE}WATER{COLOR DARK_GRAY}, the quicker Archie\l"
	.string "gets his super badass pirate {COLOR RED}sail{COLOR DARK_GRAY}!\p"
	.string "Let's get moving!$"

SpindaIsland_Home_EventScript_ArchiesHouseSign_Text_0:
# 110 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The Hoenns$"

SpindaIsland_TryToBlindZiggy_Text_0:
# 125 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Rabid Zigzagoon$"

SpindaIsland_TryToBlindZiggy_Text_1:
# 126 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "GrrrRRRRRHHH!!!!$"

SpindaIsland_TryToBlindZiggy_Text_2:
# 128 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "He looks even angrier now!$"

SpindaIsland_Home_EventScript_BobsHouseSign_Text_0:
# 135 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Mindy$"

SpindaIsland_Home_EventScript_CynthiasHouseSign_Text_0:
# 139 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Cynthia$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_0:
# 148 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Door's locked.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_1:
# 157 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I guess I should leave him alone now.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_2:
# 165 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hello? Are you there?$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_3:
# 170 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Stingy man$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_4:
# 172 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…\p"
	.string "My GOD you're annoying.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_5:
# 191 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here's your reward. I hope you're\n"
	.string "happy.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_6:
# 210 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "An old and rusty bolt? What am I\n"
	.string "supposed to do with this?$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_7:
# 226 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A {COLOR RED}bolt{COLOR DARK_GRAY}! Of course! Lucky me!\p"
	.string "I'm one step closer to getting that\n"
	.string "sweet sweet faucet replacement!!$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_8:
# 232 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(Did I really say that? Is this how\n"
	.string "being a grownup feels like?)$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_9:
# 242 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A bolt?\p"
	.string "It's all rusty…\p"
	.string "Guess it'll join my useless trash\n"
	.string "collection!$"

SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_0:
# 258 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sad man$"

SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_1:
# 260 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Curse the architect that built my\n"
	.string "house facing the wrong direction!!\p"
	.string "I can never go home!$"

SpindaIsland_Home_EventScript_Dad_Text_0:
# 272 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Dad$"

SpindaIsland_Home_EventScript_Dad_Text_1:
# 274 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't uh, pour that lemonade I gave\n"
	.string "you on the ground or anything.\p"
	.string "It'd probably kill all the grass and\n"
	.string "flowers.$"

SpindaIsland_Home_EventScript_Dad_Text_2:
# 284 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here, have some lemonade!$"

SpindaIsland_Home_EventScript_Dad_Text_3:
# 292 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hiya, sonny! going adventuring today,\n"
	.string "are we?\p"
	.string "Want some lemonade?$"

SpindaIsland_Home_EventScript_Dad_Text_4:
# 305 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Now we're talkin'!! I can bring this to\n"
	.string "mom, that should do it!\p"
	.string "Let's take a sip first, I am PARCHED!$"

SpindaIsland_Home_EventScript_Dad_Text_5:
# 329 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "BLEARGH!\p"
	.string "Why is it… so salty?!$"

SpindaIsland_Home_EventScript_Dad_Text_6:
# 338 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Why, because it's seawater, obviously!$"

SpindaIsland_Home_EventScript_Dad_Text_7:
# 343 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I take it you're not a fan of my\n"
	.string "recipe?$"

SpindaIsland_Home_EventScript_Dad_Text_8:
# 348 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(You wouldn't be the only one…)$"

SpindaIsland_Home_EventScript_Dad_Text_9:
# 353 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "In any case, it's nice of you to come\n"
	.string "visit me at the office, haha!\p"
	.string "See you around, little Archie! Don't\n"
	.string "get into trouble!$"

SpindaIsland_Home_EventScript_Dad_FromSide_Text_0:
# 382 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Come round to the front of the\n"
	.string "lemonade stand!$"

SpindaIsland_Home_EventScript_Dad_FromSide_Text_1:
# 390 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hiya, sonny! going adventuring today,\n"
	.string "are we?\p"
	.string "Want some lemonade?\p"
	.string "Come round to the front of the\n"
	.string "lemonade stand!$"

SpindaIsland_Home_EventScript_LemonadeStandSign_Text_0:
# 404 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "“ARCHIE'S LEMONADE\n"
	.string "A taste of the seaside!”$"

SpindaIsland_Home_EventScript_MainStreetSign_Text_0:
# 411 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "{UP_ARROW} Main street$"

SpindaIsland_Home_EventScript_MadelineSign_Text_0:
# 417 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bertha$"

SpindaIsland_Home_EventScript_PoemGirl_Text_0:
# 427 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Maggie$"

SpindaIsland_Home_EventScript_PoemGirl_Text_1:
# 429 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "See you around, Archie…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_2:
# 446 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Archie…\p"
	.string "I want to hear a poem…\p"
	.string "I want you to reveal your heart to me.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_3:
# 460 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ocean waves swimming…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_4:
# 461 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Roses are red…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_5:
# 462 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Roses are blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_6:
# 474 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "From the center of the sea…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_7:
# 475 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "They are calling to my heart…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_8:
# 487 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "With faith to reach land.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_9:
# 488 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Only to go back.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_10:
# 498 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And my heart to theirs.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_11:
# 499 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yearning for a touch.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_12:
# 506 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "That was very beautiful.\p"
	.string "I'm not really into haiku, though.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_13:
# 519 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Violets are blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_14:
# 520 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Just like our love…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_15:
# 532 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The sky is pretty…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_16:
# 533 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The Pincurchin are spiky…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_17:
# 546 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And so are you.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_18:
# 547 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And so are you!$"

SpindaIsland_Home_EventScript_PoemGirl_Text_19:
# 553 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, that's nice.\p"
	.string "You're not truly revealing your poet's\n"
	.string "heart, though.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_20:
# 575 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "That's… a weird comparison.\p"
	.string "I thought you were a better poet\n"
	.string "than that.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_21:
# 591 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Which blooms like they do.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_22:
# 592 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wait, I didn't mean to say that.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_23:
# 598 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wow, Archie, uh…\p"
	.string "That's not really what I meant when I\n"
	.string "said you should reveal your heart.\p"
	.string "(Well, this is awkward.)\p"
	.string "(Let's pretend this never happened.)$"

SpindaIsland_Home_EventScript_PoemGirl_Text_24:
# 614 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Violets are red…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_25:
# 628 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The sky isn't blue, it's purple instead.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_26:
# 629 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Doesn't make sense, but fun to be said.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_27:
# 635 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmm…\p"
	.string "You're not revealing your heart right\n"
	.string "now.\p"
	.string "Plus, that didn't make any sense.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_28:
# 651 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Orchids are blue, too.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_29:
# 652 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Everything is blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_30:
# 674 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Because it's my favorite color.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_31:
# 679 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "… … … … …\p"
	.string "Wow, Archie, I…\p"
	.string "This was so touching…\p"
	.string "Thank you for revealing your heart to\n"
	.string "me like this.\p"
	.string "Here, take this.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_32:
# 693 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "It's a blade of grass large enough to\n"
	.string "whistle with.\p"
	.string "Just don't listen to it too\n"
	.string "attentively, you might get sleepy.$"

SpindaIsland_Home_EventScript_Sunbather_Text_0:
# 712 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sunbather$"

SpindaIsland_Home_EventScript_Sunbather_Text_1:
# 714 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ahh, it sure feels good to be sitting\n"
	.string "in the sun surrounded by all this\l"
	.string "{COLOR BLUE}WATER{COLOR DARK_GRAY}…\p"
	.string "…$"

SpindaIsland_Home_EventScript_Sunbather_Text_2:
# 725 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Could you leave? You're blocking the\n"
	.string "sun.$"

SpindaIsland_Home_Slowpoke_Text_0:
# 739 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slowbro$"

SpindaIsland_Home_Slowpoke_Text_1:
# 741 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bruh…$"

SpindaIsland_Home_Slowpoke_Text_2:
# 749 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slowpoke$"

SpindaIsland_Home_Slowpoke_Text_3:
# 751 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slo…$"

SpindaIsland_Home_Slowpoke_Text_4:
# 760 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "… … …?\p"
	.string "He's looking at the white seashell I\n"
	.string "found…$"

SpindaIsland_Home_Slowpoke_Text_5:
# 771 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Give the seashell$"

SpindaIsland_Home_Slowpoke_Text_6:
# 772 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't give the seashell$"

SpindaIsland_Home_Slowpoke_Text_7:
# 782 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sure, why the hell not!\p"
	.string "Here you go, buddy.$"

SpindaIsland_Home_Slowpoke_Text_8:
# 804 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bruh!!$"

SpindaIsland_Home_Slowpoke_Text_9:
# 812 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The heck?!\p"
	.string "My seashell bit him!$"

SpindaIsland_Home_Slowpoke_Text_10:
# 818 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Guess it was a Shellder all this time!$"

SpindaIsland_Home_Slowpoke_Text_11:
# 828 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…Slo…\p"
	.string ":($"

SpindaIsland_Home_EventScript_Metapod_Text_0:
# 842 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod$"

SpindaIsland_Home_EventScript_Metapod_Text_1:
# 845 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0:
# 855 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Twin$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_1:
# 857 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "What is it?!$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_2:
# 862 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, I guess we are blocking the stairs\n"
	.string "a little…\p"
	.string "Fine, we'll take our epic battle\n"
	.string "somewhere else.$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_0:
# 884 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "On god why you gotta bust my balls\n"
	.string "like that fr?!$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_1:
# 889 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yikes, we lowkey do be blockin the\n"
	.string "stairs rn no cap…\p"
	.string "Aight word word, we gon vibe\n"
	.string "somewhere else.$"

SpindaIsland_Home_EventScript_MetapodBoy_Text_0:
# 915 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm SO CLOSE to tasting that sweet,\n"
	.string "sweet victory!$"

SpindaIsland_Home_EventScript_MetapodBoy_Text_1:
# 925 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't you see we're in the midst of a\n"
	.string "fiery battle?$"

SpindaIsland_Home_EventScript_MetapodBoy_Text_2:
# 935 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod, use harden!!$"

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_0:
# 956 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm deadass SO CLOSE to catchin that\n"
	.string "bussin drip fr!$"

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_1:
# 966 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't you see we tryna catch some\n"
	.string "real heat rn bro? Sheesh!$"

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_2:
# 976 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod, keep hittin that mid boi with\n"
	.string "harden, chief!!$"

SpindaIsland_Home_PhotoCameraWrongDir_Text_0:
# 994 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't use that from this side.$"

SpindaIsland_Home_EventScript_FaucetShopSign_Text_0:
# 1003 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "“FAUCET WORKSHOP\n"
	.string "For all your faucet needs!\l"
	.string "WE ARE OPEN!!”$"

SpindaIsland_Home_SlowpokeMistress_Text_0:
# 1053 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Girl$"

SpindaIsland_Home_SlowpokeMistress_Text_1:
# 1055 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Look at my super cool Slowbro!\p"
	.string "He just looks so happy!$"

SpindaIsland_Home_SlowpokeMistress_Text_2:
# 1070 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "By Arceus!!\p"
	.string "How on earth did you convince him to\n"
	.string "evolve?$"

SpindaIsland_Home_SlowpokeMistress_Text_3:
# 1076 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…A cool-looking seashell? What are\n"
	.string "you talking about?$"

SpindaIsland_Home_SlowpokeMistress_Text_4:
# 1081 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Well, thank you anyway! You can have\n"
	.string "this!$"

SpindaIsland_Home_SlowpokeMistress_Text_5:
# 1086 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I no longer need it.$"

SpindaIsland_Home_SlowpokeMistress_Text_6:
# 1096 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmm… A {COLOR BLUE}WATER{COLOR DARK_GRAY} Stone…\p"
	.string "Maybe I could try giving this to mom?$"

SpindaIsland_Home_SlowpokeMistress_Text_7:
# 1107 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I wish my Pokémon would evolve…$"

SpindaIsland_Home_SlowpokeMistress_Text_8:
# 1112 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I keep trying to give him this {COLOR BLUE}WATER{COLOR DARK_GRAY}\n"
	.string "Stone, but it just does nothing.\p"
	.string "Perhaps there's another way…$"

SpindaIsland_Home_EventScript_Juan_Text_0:
# 1125 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Juan$"

SpindaIsland_Home_EventScript_Juan_Text_1:
# 1128 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey, wanna hear more interesting\n"
	.string "facts about Pokémon?$"

SpindaIsland_Home_EventScript_Juan_Text_2:
# 1138 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Nope$"

SpindaIsland_Home_EventScript_Juan_Text_3:
# 1139 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "No thanks$"

SpindaIsland_Home_EventScript_Juan_Text_4:
# 1144 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bummer! Come back whenever, I have\n"
	.string "plenty!$"

SpindaIsland_Home_EventScript_Juan_Text_5:
# 1151 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm just taking my friend Machoke for\n"
	.string "a stroll!\p"
	.string "You know, I've always wondered where\n"
	.string "the cute little thong and belt come\l"
	.string "from.\p"
	.string "My Machoke was already wearing it\n"
	.string "when I caught him!\p"
	.string "Do they have like a Machoke thong\n"
	.string "shop somewhere and all the Machoke\l"
	.string "go there to get their thong?\p"
	.string "Is there a Machoke censor who\n"
	.string "travels across all lands, putting\l"
	.string "thongs on wild Machoke?\p"
	.string "Do they actually just grow their own\n"
	.string "thong naturally?\p"
	.string "Is it… {PAUSE 20}Is it their…\p"
	.string "… … …\p"
	.string "… …It is, isn't it?$"

SpindaIsland_Home_EventScript_Juan_Text_6:
# 1163 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh boy, what a find! I need to write\n"
	.string "this discovery down in my PokéDex!!$"

SpindaIsland_Home_EventScript_Machoke_Text_0:
# 1178 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sexy Machoke$"

SpindaIsland_Home_EventScript_Machoke_Text_1:
# 1180 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Machoke$"

SpindaIsland_Home_EventScript_Machoke_Text_2:
# 1183 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmmm…$"

SpindaIsland_Home_EventScript_Lisa_Text_0:
# 1194 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Lisa$"

SpindaIsland_Home_EventScript_Lisa_Text_1:
# 1196 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey Archie! Heard you were building a\n"
	.string "sick pirate ship!$"

SpindaIsland_Home_EventScript_OldWoman_Text_0:
# 1209 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Old woman$"

SpindaIsland_Home_EventScript_OldWoman_Text_1:
# 1211 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I think my house is haunted. There's\n"
	.string "something living in my attic.\p"
	.string "I don't know what to do…$"

SpindaIsland_Home_EventScript_OldWoman_Text_2:
# 1222 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, I'm too scared to go back inside…$"

SpindaIsland_Home_EventScript_OldWoman_Text_3:
# 1240 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't worry granny! There were some\n"
	.string "Shuppet in your attic, but I chased\l"
	.string "them away!$"

SpindaIsland_Home_EventScript_OldWoman_Text_4:
# 1248 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Shuppet, you say?$"

SpindaIsland_Home_EventScript_OldWoman_Text_5:
# 1252 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "How adorable of you to help out a poor\n"
	.string "old lady…\p"
	.string "How can I repay you?\p"
	.string "You look like you're hungry… Let me\n"
	.string "fix you a little snack!$"

SpindaIsland_Home_EventScript_OldWoman_Text_6:
# 1263 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Have a good day, child.$"

SpindaIsland_Home_EventScript_OldWoman_Text_7:
# 1277 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Cool! Lemme pack this up for later.\p"
	.string "Let's hope it doesn't taste like old\n"
	.string "people or something.$"

SpindaIsland_Home_EventScript_OldWomansDoor_Text_0:
# 1294 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm glad I was able to help!$"

SpindaIsland_Home_EventScript_Chest_Text_0:
# 1308 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Already opened it!$"

SpindaIsland_Home_EventScript_Chest_Text_1:
# 1316 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Woah, a treasure chest?!\p"
	.string "Wonder who put it here!$"

SpindaIsland_Home_EventScript_Chest_Text_2:
# 1332 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A {COLOR RED}bolt{COLOR DARK_GRAY}!!\p"
	.string "And it's gold, too!\p"
	.string "How lucky!$"

SpindaIsland_Home_EventScript_Chest_Text_3:
# 1344 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A gold coin?!$"

SpindaIsland_Home_EventScript_Chest_Text_4:
# 1348 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ah, no, it's a {COLOR RED}bolt{COLOR DARK_GRAY}.\p"
	.string "Weird, I wonder who put it here.$"

SpindaIsland_Home_CarBoy_Text_0:
# 1362 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Rudy$"

SpindaIsland_Home_CarBoy_Text_1:
# 1364 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Vrrrbbbbbmmmmmmm!!!!!$"

SpindaIsland_Home_CarGirl_Text_0:
# 1378 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Katie$"

SpindaIsland_Home_CarGirl_Text_1:
# 1380 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Thanks a bunch!$"

SpindaIsland_Home_CarGirl_Text_2:
# 1390 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh!\p"
	.string "You've got this super cool {COLOR RED}metal\n"
	.string "wheel{COLOR DARK_GRAY}…\p"
	.string "And you're just giving it to us?\p"
	.string "You're the best, Archie!!\p"
	.string "We don't have much, but please take\n"
	.string "this.\p"
	.string "It's my lucky coin! I hope it'll be\n"
	.string "lucky for you, too!$"

SpindaIsland_Home_CarGirl_Text_3:
# 1407 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Now what could we use as a wheel…$"

SpindaIsland_Home_CarGirl_Text_4:
# 1416 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey Archie!\p"
	.string "As you can see we're almost done with\n"
	.string "our monster car.\p"
	.string "We're just missing one last wheel!\p"
	.string "We don't really need it to be an actual\n"
	.string "wheel, either.\p"
	.string "Anything round and spinny would do!$"

SpindaIsland_Home_EventScript_MissingWheel_Text_0:
# 1440 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A shiny new wheel!$"

SpindaIsland_Home_EventScript_MissingWheel_Text_1:
# 1448 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A wheel is missing.\p"
	.string "I'm sure I could find a replacement.$"

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_0:
# 1464 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "What if…$"

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_1:
# 1481 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Fits perfectly! There ya go!$"

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_2:
# 1494 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "This'd be perfect, but I need to\n"
	.string "repair it!$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_0:
# 1507 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Just a regular wheel.$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_1:
# 1512 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wait, it's stuck to the car with bolts!\p"
	.string "If I could just take one…$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_2:
# 1520 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here, let me just…$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_3:
# 1529 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Whatcha doing, Archie?$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_4:
# 1537 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ah, uh, nothing!$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_5:
# 1548 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(Darn, can't do this right under her\n"
	.string "nose.)$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_6:
# 1555 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'd need some pliers to get it out.$"

SpindaIsland_Home_EventScript_Raft_Text_0:
# 1577 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "My super-awesome pirate ship!\p"
	.string "Only thing missing is the sail.$"

SpindaIsland_Home_EventScript_ThisIsConvenient_Text_0:
# 1595 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Well, this is eerily convenient!$"

SpindaIsland_Home_EventScript_Pot_Text_0:
# 1612 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Much better!$"

SpindaIsland_Home_EventScript_Pot_Text_1:
# 1620 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slurp…$"

SpindaIsland_Home_EventScript_Pot_Text_2:
# 1624 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ugh, it's tasteless…\p"
	.string "Have people never heard of salt?$"

SpindaIsland_Home_EventScript_SaltDish_Text_0:
# 1640 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Needs some salt, so maybe…$"

SpindaIsland_Home_EventScript_SaltDish_Text_1:
# 1655 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "There, fixed, probably!$"

SpindaIsland_Home_EventScript_FeedZiggy_Text_0:
# 1669 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Good idea, except I need this\n"
	.string "sandwich for the faucet salesman!$"

SpindaIsland_Home_EventScript_FeedZiggy_Text_1:
# 1673 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'd be afraid of this one biting off my\n"
	.string "hand!$"

SpindaIsland_Home_EventScript_Cook_Text_0:
# 1687 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Cook$"

SpindaIsland_Home_EventScript_Cook_Text_1:
# 1689 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Thank you again.\p"
	.string "You will become a great chef when you\n"
	.string "grow up, I can feel it!$"

SpindaIsland_Home_EventScript_Cook_Text_2:
# 1699 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can you try your dish now?$"

SpindaIsland_Home_EventScript_Cook_Text_3:
# 1707 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "It's not like it's gotten any tastier\n"
	.string "on its own, but sure.$"

SpindaIsland_Home_EventScript_Cook_Text_4:
# 1732 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, wow! It's… It's remarkable!!\p"
	.string "What arcane sorcery…\p"
	.string "What? You added some lemonade in the\n"
	.string "pot?\p"
	.string "Who would have thought!!\p"
	.string "I don't have much to thank you, but\n"
	.string "here is a bottle of my finest cooking\l"
	.string "oil!$"

SpindaIsland_Home_EventScript_Cook_Text_5:
# 1750 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I am distraught.\p"
	.string "My dish isn't turning out how I wanted\n"
	.string "at all…\p"
	.string "How can I make it less… flavorless?\p"
	.string "Is there any hope at all?$"

SpindaIsland_Home_EventScript_Zigzagoon_Text_0:
# 1768 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sleepy Zigzagoon$"

SpindaIsland_Home_EventScript_Zigzagoon_Text_1:
# 1770 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "ZzzzzZzZz…$"

SpindaIsland_Home_EventScript_Zigzagoon_Text_2:
# 1778 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "GRRRRRRRR…$"

SpindaIsland_Home_EventScript_Pliers_Text_0:
# 1796 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yuck, the Zigzagoon drooled all over\n"
	.string "them!\p"
	.string "At least I hope it's drool…$"

SpindaIsland_Home_EventScript_Pliers_Text_1:
# 1806 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't get to those {COLOR RED}pliers{COLOR DARK_GRAY} with that\n"
	.string "Zigzagoon guarding them…\p"
	.string "If only there was a way to distract or\n"
	.string "incapacitate it…$"

SpindaIsland_Home_EventScript_Pliers_Text_2:
# 1816 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "These must be the {COLOR RED}pliers{COLOR DARK_GRAY} the faucet\n"
	.string "salesman was talking about!$"

SpindaIsland_Home_EventScript_Pliers_Text_3:
# 1821 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "You're gonna give them to me, right\n"
	.string "little Ziggy?$"

SpindaIsland_Home_EventScript_Pliers_Text_4:
# 1835 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Nope, not gonna risk a hand just to\n"
	.string "get these!$"

SpindaIsland_Home_EventScript_Pliers_Text_5:
# 1845 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Is this… a pair of {COLOR RED}pliers{COLOR DARK_GRAY}?\p"
	.string "I wonder what a Zigzagoon would use\n"
	.string "these for.$"

SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_0:
# 1863 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "GRRRRRRRR!!$"

SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_1:
# 1873 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…GrrrzzZZzzzzZz…$"

SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_2:
# 1878 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "ZzzzZzZzzZZzzz…$"

SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_3:
# 1885 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Awesome! It fell asleep!\p"
	.string "Let's get those {COLOR RED}pliers{COLOR DARK_GRAY}!$"

SpindaIsland_Home_EventScript_BobsDoor_Text_0:
# 1906 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey Archie! Wanna come in for a\n"
	.string "Pokémon trade?$"

SpindaIsland_Home_EventScript_BobsDoor_Text_1:
# 1911 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't today, I'm busy!$"

SpindaIsland_Home_EventScript_BobsDoor_Text_2:
# 1915 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(Never again.)$"

SpindaIsland_Home_EventScript_CynthiasDoor_Text_0:
# 1927 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I ain't going in there unprepared.\p"
	.string "Or at all.$"

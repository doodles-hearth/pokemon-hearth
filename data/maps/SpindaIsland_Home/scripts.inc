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
# 108 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 109 "data/maps/SpindaIsland_Home/scripts.pory"
	callnative StartCredits
# 111 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_BobsHouseSign::
# 116 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_CynthiasHouseSign::
# 120 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_CynthiasHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_SadManHome_Back::
# 124 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 125 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_HIDE_MAN_CANT_GO_HOME, SpindaIsland_Home_EventScript_SadManHome_Back_2
# 134 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_RUSTY_BOLT, SpindaIsland_Home_EventScript_SadManHome_Back_5
# 143 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 144 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 145 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_2
# 148 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 149 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 151 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_SadManHome_Back_Text_3
# 152 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_4
# 156 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 158 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 160 "data/maps/SpindaIsland_Home/scripts.pory"
	clearflag FLAG_HIDE_MAN_CANT_GO_HOME
# 161 "data/maps/SpindaIsland_Home/scripts.pory"
	setobjectxyperm 6, 42, 24
# 162 "data/maps/SpindaIsland_Home/scripts.pory"
	addobject 6
# 163 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement 6, SpindaIsland_Home_Movement_SadManExitsHouse
# 164 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Movement_PlayerMakesWay
# 165 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 166 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 6
# 167 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 168 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 169 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 170 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_SadManHome_Back_Text_3
# 171 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_5
# 174 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 175 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 176 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_RUSTY_BOLT
# 177 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_RUSTY_BOLT
# 178 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement 6, SpindaIsland_Home_Movement_SadManReEntersHouse
# 179 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 180 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 181 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 6
# 182 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_MAN_CANT_GO_HOME
# 183 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 185 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 187 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_SadManHome_Back_8
# 220 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 221 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 222 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_9
# 227 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 228 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_SadManHome_Back_1:
# 232 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_SadManHome_Back_2:
# 126 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 127 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 128 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_0
# 131 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 132 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1

SpindaIsland_Home_EventScript_SadManHome_Back_5:
# 135 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 136 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 137 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_1
# 140 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 141 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1

SpindaIsland_Home_EventScript_SadManHome_Back_8:
# 188 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 189 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 190 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_6
# 193 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 194 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 196 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 198 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 199 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 200 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 201 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 202 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 204 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 205 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 206 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_7
# 210 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 211 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 212 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_8
# 215 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 216 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 218 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1


SpindaIsland_Home_EventScript_ICanNeverGoHome::
# 236 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 237 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 238 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SAD
# 239 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_0
# 240 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_1, MSGBOX_NPC
# 244 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 245 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_Dad::
# 249 "data/maps/SpindaIsland_Home/scripts.pory"
	lockall
# 250 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 7, DIR_SOUTH
# 251 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OBTAINED_LEMONADE, SpindaIsland_Home_EventScript_Dad_2
# 261 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SPOKE_TO_DAD, SpindaIsland_Home_EventScript_Dad_6
# 270 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 271 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 272 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_3
# 276 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 277 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Dad_5:
# 280 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_SALTY_LEMONADE
# 282 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 283 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 284 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 285 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_4
# 289 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 290 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 292 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 10
# 293 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 294 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 295 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 296 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 297 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 298 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 299 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 20
# 301 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 302 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 303 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 304 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 305 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 307 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_DISGUSTED
# 308 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 309 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_5
# 313 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 314 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 316 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_GRINNING
# 317 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 318 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_6
# 321 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 322 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 323 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_7
# 326 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 327 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_EMBARRASSED
# 328 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_8
# 331 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 332 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 333 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_9
# 337 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 338 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 340 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_OBTAINED_LEMONADE
# 341 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SPOKE_TO_DAD
SpindaIsland_Home_EventScript_Dad_1:
# 343 "data/maps/SpindaIsland_Home/scripts.pory"
	releaseall
	return

SpindaIsland_Home_EventScript_Dad_2:
# 252 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_EMBARRASSED
# 253 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 254 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_1
# 258 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 259 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_1

SpindaIsland_Home_EventScript_Dad_6:
# 262 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 263 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 264 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_2
# 267 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 268 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_5


SpindaIsland_Home_EventScript_Dad_FromSide::
# 347 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 348 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 349 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OBTAINED_LEMONADE, SpindaIsland_Home_EventScript_Dad_FromSide_2
# 359 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SPOKE_TO_DAD, SpindaIsland_Home_EventScript_Dad_FromSide_6
# 368 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 369 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 370 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_FromSide_Text_1
# 375 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 376 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Dad_FromSide_5:
# 378 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SPOKE_TO_DAD
SpindaIsland_Home_EventScript_Dad_FromSide_1:
# 380 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Dad_FromSide_2:
# 350 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_EMBARRASSED
# 351 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 352 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_1
# 356 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 357 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_FromSide_1

SpindaIsland_Home_EventScript_Dad_FromSide_6:
# 360 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_NORMAL
# 361 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 362 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_FromSide_Text_0
# 365 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 366 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_FromSide_5


SpindaIsland_Home_EventScript_LemonadeStandSign::
# 384 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_LemonadeStandSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_MainStreetSign::
# 391 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MainStreetSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_MadelineSign::
# 397 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MadelineSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_PoemGirl::
# 403 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 405 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_POEM_GIRL, SpindaIsland_Home_EventScript_PoemGirl_2
# 419 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
# 420 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 422 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 424 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 425 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 426 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_2
# 431 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 432 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 434 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_3, SpindaIsland_Home_EventScript_PoemGirl_Text_4, SpindaIsland_Home_EventScript_PoemGirl_Text_5
# 446 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 447 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_6
# 492 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_7
# 587 "data/maps/SpindaIsland_Home/scripts.pory"
	case 2, SpindaIsland_Home_EventScript_PoemGirl_8
SpindaIsland_Home_EventScript_PoemGirl_1:
# 685 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 686 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 687 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_PoemGirl_2:
# 406 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 407 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 408 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 409 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_1
# 412 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 413 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 415 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 416 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 417 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_6:
# 448 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_6, SpindaIsland_Home_EventScript_PoemGirl_Text_7
# 459 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 460 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_11
# 471 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_12
SpindaIsland_Home_EventScript_PoemGirl_9:
# 484 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 485 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 486 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_12
# 490 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 491 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_7:
# 493 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_13, SpindaIsland_Home_EventScript_PoemGirl_Text_14
# 503 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 505 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_14
# 564 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_15
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_8:
# 588 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_24, SpindaIsland_Home_EventScript_PoemGirl_Text_13
# 599 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 601 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_17
# 624 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_18
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_11:
# 461 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_8, SpindaIsland_Home_EventScript_PoemGirl_Text_9
	goto SpindaIsland_Home_EventScript_PoemGirl_9

SpindaIsland_Home_EventScript_PoemGirl_12:
# 472 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_10, SpindaIsland_Home_EventScript_PoemGirl_Text_11
	goto SpindaIsland_Home_EventScript_PoemGirl_9

SpindaIsland_Home_EventScript_PoemGirl_14:
# 506 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_15, SpindaIsland_Home_EventScript_PoemGirl_Text_16
# 517 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 519 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_20
# 541 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_21
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_15:
# 565 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_21, SpindaIsland_Home_EventScript_PoemGirl_Text_22
# 576 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 577 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 578 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_23
# 584 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 585 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_17:
# 602 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_25, SpindaIsland_Home_EventScript_PoemGirl_Text_26
# 613 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 614 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 615 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_27
# 620 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 621 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_18:
# 625 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_28, SpindaIsland_Home_EventScript_PoemGirl_Text_29
# 636 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 637 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_23
# 647 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_24
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_20:
# 520 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_17, SpindaIsland_Home_EventScript_PoemGirl_Text_18
# 531 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 532 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 533 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_19
# 537 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 538 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_21:
# 542 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_17, SpindaIsland_Home_EventScript_PoemGirl_Text_18
# 553 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 554 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 555 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_20
# 559 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 560 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_23:
# 638 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 639 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 640 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_27
# 645 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 646 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_24:
# 648 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_30
# 657 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 658 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 659 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_31
# 666 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 667 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 669 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_GRASS_BLADE
# 671 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 672 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 673 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_32
# 677 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 678 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 680 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_POEM_GIRL
	goto SpindaIsland_Home_EventScript_PoemGirl_1


SpindaIsland_Home_EventScript_Sunbather::
# 691 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 692 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_SUNBATHER, EMOTE_NORMAL
# 693 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Sunbather_Text_0
# 694 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Sunbather_Text_1
# 698 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 699 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 700 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 701 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 703 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_SUNBATHER, EMOTE_PENSIVE
# 704 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Sunbather_Text_0
# 705 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Sunbather_Text_2
# 708 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 709 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 710 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 711 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 712 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_Slowpoke::
# 716 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 717 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_Slowpoke_2
# 728 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 729 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
# 730 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_2
# 731 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_3
# 734 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 735 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	checkitem ITEM_WHITE_SEASHELL
# 0 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SpindaIsland_Home_Slowpoke_5
SpindaIsland_Home_Slowpoke_1:
# 818 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_Slowpoke_2:
# 718 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 719 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
# 720 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_0
# 721 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_1
# 724 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 725 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_5:
# 738 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 739 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 740 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_4
# 745 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Slowpoke_Text_5, SpindaIsland_Home_Slowpoke_Text_6
# 755 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 756 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 758 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 759 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_Slowpoke_8
# 805 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_Slowpoke_9
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_8:
# 760 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 761 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 762 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_7
# 766 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 767 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 769 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_WHITE_SEASHELL
# 771 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWBRO )
# 772 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SHELLDER, CRY_MODE_NORMAL
# 773 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 774 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject VAR_LAST_TALKED
# 775 "data/maps/SpindaIsland_Home/scripts.pory"
	addobject VAR_LAST_TALKED
# 776 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_BITE
# 777 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, SpindaIsland_Home_Movement_Slowpoke
# 778 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 779 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement VAR_LAST_TALKED
# 780 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 782 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
# 783 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_0
# 784 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_8
# 787 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 788 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 790 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SHOCKED
# 791 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 792 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_9
# 796 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 797 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 798 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_10
# 801 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 802 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 804 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SLOWPOKE_EVOLVED
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_9:
# 806 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_FAINT
# 807 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_2
# 808 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_11
# 812 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 813 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Slowpoke_1


SpindaIsland_Home_EventScript_Metapod::
# 822 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 823 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Metapod_Text_0
# 824 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_METAPOD, CRY_MODE_NORMAL
# 825 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Metapod_Text_1
# 828 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 829 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 830 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoysFuckOff::
# 834 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 835 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 836 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 837 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_1
# 841 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_NORMAL
# 842 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_2
# 846 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 848 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_TO_BLACK
# 849 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_METAPOD_BATTLE
# 850 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 1
# 851 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 2
# 852 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 3
# 853 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 4
# 854 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 60
# 855 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 856 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 40
# 857 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin::
# 861 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 862 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 863 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 864 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_0
# 868 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_NORMAL
# 869 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_1
# 873 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 874 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 876 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_TO_BLACK
# 877 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_METAPOD_BATTLE
# 878 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 1
# 879 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 2
# 880 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 3
# 881 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 4
# 882 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 60
# 883 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 884 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 40
# 885 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoy::
# 889 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 890 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_METAPOD_OTHER_SIDE, 1
	goto_if_eq SpindaIsland_Home_EventScript_MetapodBoy_2
SpindaIsland_Home_EventScript_MetapodBoy_1:
# 893 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 894 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 895 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Text_0
# 898 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 899 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 901 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 903 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_FINGER
# 904 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 905 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Text_1
# 908 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 909 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 911 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 913 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 914 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 915 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Text_2
# 918 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 919 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 921 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 922 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 923 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 924 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 925 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 926 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MetapodBoy_2:
# 891 "data/maps/SpindaIsland_Home/scripts.pory"
	goto SpindaIsland_Home_EventScript_MetapodBoysFuckOff
	goto SpindaIsland_Home_EventScript_MetapodBoy_1


SpindaIsland_Home_EventScript_MetapodBoy_Bussin::
# 930 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 931 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_METAPOD_OTHER_SIDE, 1
	goto_if_eq SpindaIsland_Home_EventScript_MetapodBoy_Bussin_2
SpindaIsland_Home_EventScript_MetapodBoy_Bussin_1:
# 934 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 935 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 936 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_0
# 939 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 940 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 942 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 944 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_FINGER
# 945 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 946 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_1
# 949 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 950 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 952 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 954 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 955 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 956 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_2
# 959 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 960 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 962 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 963 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 964 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 965 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 966 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 967 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_2:
# 932 "data/maps/SpindaIsland_Home/scripts.pory"
	goto SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin
	goto SpindaIsland_Home_EventScript_MetapodBoy_Bussin_1


SpindaIsland_Home_PhotoCameraWrongDir::
# 971 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 972 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 973 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 974 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_PhotoCameraWrongDir_Text_0
# 977 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 978 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 979 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_FaucetShopSign::
# 983 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_FaucetShopSign_Text_0, MSGBOX_SIGN
	return


# 990 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_SadManExitsHouse:
# 991 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
	step_end

# 994 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_SadManReEntersHouse:
# 995 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 996 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 997 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
	step_end

# 1000 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_PlayerMakesWay:
# 1001 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 1002 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1003 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
	step_end

# 1006 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_Slowpoke:
# 1007 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 1008 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 1009 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
# 1010 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1010 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1010 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1011 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 1012 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1013 "data/maps/SpindaIsland_Home/scripts.pory"
	face_down
# 1014 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1015 "data/maps/SpindaIsland_Home/scripts.pory"
	face_left
# 1016 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1017 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 1018 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1019 "data/maps/SpindaIsland_Home/scripts.pory"
	face_player
# 1020 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1020 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1020 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1021 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 1022 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 1023 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 1024 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
# 1025 "data/maps/SpindaIsland_Home/scripts.pory"
	emote_heart
# 1026 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1026 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1026 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
	step_end

SpindaIsland_Home_SlowpokeMistress::
# 1030 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1031 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1032 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_SLOWPOKE_REWARD, SpindaIsland_Home_SlowpokeMistress_2
# 1041 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_SlowpokeMistress_3
# 1085 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_SWEAT
# 1086 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 1087 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_7
# 1090 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1091 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 1092 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_8
# 1096 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1097 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_SlowpokeMistress_1:
# 1099 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_SlowpokeMistress_2:
# 1033 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_HAPPY
# 1034 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 1035 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_1
# 1039 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1040 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_SlowpokeMistress_1

SpindaIsland_Home_SlowpokeMistress_3:
# 1042 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 1043 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 1044 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1045 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1046 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1048 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_SURPRISED
# 1049 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 1050 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_2
# 1054 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1055 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 1056 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_3
# 1059 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1060 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_HAPPY
# 1061 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_4
# 1064 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1065 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 1066 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_5
# 1069 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1070 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1072 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_WATER_STONE_2
# 1074 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 1075 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1076 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_6
# 1080 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1081 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1083 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_SLOWPOKE_REWARD
	goto SpindaIsland_Home_SlowpokeMistress_1


SpindaIsland_Home_EventScript_Juan::
# 1103 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1104 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1105 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 1106 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Juan_Text_0
# 1107 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_TALKED_TO_JUAN_ABOUT_PUBES, SpindaIsland_Home_EventScript_Juan_2
# 1131 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_5
# 1142 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SURPRISED
# 1143 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_6
# 1146 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1147 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1148 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_TALKED_TO_JUAN_ABOUT_PUBES
SpindaIsland_Home_EventScript_Juan_1:
# 1151 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Juan_2:
# 1108 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_1
# 1112 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_Juan_Text_2, SpindaIsland_Home_EventScript_Juan_Text_3
# 1123 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 1124 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_4
# 1128 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1129 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Juan_1


SpindaIsland_Home_EventScript_Machoke::
# 1155 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1156 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1157 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
# 1158 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_TALKED_TO_JUAN_ABOUT_PUBES, SpindaIsland_Home_EventScript_Machoke_2
# 1161 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Machoke_Text_1
SpindaIsland_Home_EventScript_Machoke_1:
# 1163 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Machoke_Text_2
# 1166 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1167 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1168 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Machoke_2:
# 1159 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Machoke_Text_0
	goto SpindaIsland_Home_EventScript_Machoke_1


SpindaIsland_Home_EventScript_Lisa::
# 1172 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1173 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1174 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL_BLACK, EMOTE_NORMAL
# 1175 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Lisa_Text_0
# 1176 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Lisa_Text_1
# 1179 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1180 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1181 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_OldWoman::
# 1185 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1186 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1187 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_SHUPPET_QUEST_STARTED, SpindaIsland_Home_EventScript_OldWoman_2
# 1198 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_HIDE_SHUPPETS, SpindaIsland_Home_EventScript_OldWoman_3
SpindaIsland_Home_EventScript_OldWoman_1:
# 1209 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_HIDE_SHUPPETS, SpindaIsland_Home_EventScript_OldWoman_7
SpindaIsland_Home_EventScript_OldWoman_6:
# 1266 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_OldWoman_2:
# 1188 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1189 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1190 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1191 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_1
# 1195 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1196 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1197 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SHUPPET_QUEST_STARTED
	goto SpindaIsland_Home_EventScript_OldWoman_1

SpindaIsland_Home_EventScript_OldWoman_3:
# 1199 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1200 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1201 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1202 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_2
# 1205 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1206 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_OldWoman_1

SpindaIsland_Home_EventScript_OldWoman_7:
# 1210 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1211 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1212 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_2
# 1215 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1216 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1218 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1219 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1220 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_3
# 1223 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1224 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1226 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1227 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1228 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_4
# 1231 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 1232 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_5
# 1237 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1238 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1240 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_PB_AND_J
# 1242 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 1243 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_6
# 1246 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1247 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1249 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 1250 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject VAR_LAST_TALKED
# 1251 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 1252 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1253 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_OLD_WOMAN
# 1255 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1256 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1257 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_7
# 1261 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1262 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1264 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_OldWoman_6


SpindaIsland_Home_EventScript_OldWomansDoor::
# 1270 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1272 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1273 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1274 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWomansDoor_Text_0
# 1277 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1278 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1280 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_Chest::
# 1284 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1285 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OPENED_CHEST, SpindaIsland_Home_EventScript_Chest_2
# 1294 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1295 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1296 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Chest_Text_1
# 1300 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1301 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1303 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 53, 27, METATILE_SpindaIsland_EmptyChest, TRUE
# 1304 "data/maps/SpindaIsland_Home/scripts.pory"
	special DrawWholeMapView
# 1306 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_OPENED_CHEST
# 1307 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_PRECIOUS_BOLT
# 1309 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_Chest_5
# 1322 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1323 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1324 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Chest_Text_3
# 1327 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1328 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Chest_Text_4
# 1332 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1333 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
SpindaIsland_Home_EventScript_Chest_1:
# 1336 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Chest_2:
# 1286 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1287 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1288 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Chest_Text_0
# 1291 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1292 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
	goto SpindaIsland_Home_EventScript_Chest_1

SpindaIsland_Home_EventScript_Chest_5:
# 1310 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1311 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1312 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Chest_Text_2
# 1317 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1318 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1320 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_Chest_1


SpindaIsland_Home_CarBoy::
# 1340 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1341 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1342 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_BOY, EMOTE_NORMAL
# 1343 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarBoy_Text_0
# 1344 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarBoy_Text_1
# 1347 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1348 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1349 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1350 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1351 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_CarGirl::
# 1355 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1356 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_NICKEL, SpindaIsland_Home_CarGirl_2
# 1366 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_REPLACED_WHEEL, SpindaIsland_Home_CarGirl_3
# 1383 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_LOOKING_FOR_WHEEL_REPLACEMENT, SpindaIsland_Home_CarGirl_4
# 1393 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1394 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1395 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1396 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_4
# 1403 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1404 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1406 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_LOOKING_FOR_WHEEL_REPLACEMENT
SpindaIsland_Home_CarGirl_1:
# 1409 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1410 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1412 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_CarGirl_2:
# 1357 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1358 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1359 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1360 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_1
# 1363 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1364 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_CarGirl_1

SpindaIsland_Home_CarGirl_3:
# 1367 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1368 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1369 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1370 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_2
# 1378 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1379 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1381 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_RUSTY_NICKEL
# 1382 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_NICKEL
	goto SpindaIsland_Home_CarGirl_1

SpindaIsland_Home_CarGirl_4:
# 1384 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1385 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 1386 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1387 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_3
# 1390 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1391 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_CarGirl_1


SpindaIsland_Home_EventScript_MissingWheel::
# 1416 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1417 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_REPLACED_WHEEL, SpindaIsland_Home_EventScript_MissingWheel_2
# 1426 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1427 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1428 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MissingWheel_Text_1
# 1432 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1433 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_MissingWheel_1:
# 1435 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MissingWheel_2:
# 1418 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1419 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1420 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MissingWheel_Text_0
# 1423 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1424 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_MissingWheel_1


SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet::
# 1439 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1441 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_1
# 1472 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1473 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1474 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_2
# 1477 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1478 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	return

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_1:
# 1442 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1443 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1444 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_0
# 1447 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1448 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1450 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1452 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_CLICK
# 1453 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 27, 50, METATILE_SpindaIslandSecondary_FaucetWheel, TRUE
# 1454 "data/maps/SpindaIsland_Home/scripts.pory"
	special DrawWholeMapView
# 1455 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1457 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1459 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1460 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1461 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_1
# 1464 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1465 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1467 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_BROKEN_FAUCET
# 1468 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_REPLACED_WHEEL
# 1470 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_SurveyedWheel::
# 1483 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1484 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_SurveyedWheel_4
SpindaIsland_Home_EventScript_SurveyedWheel_3:
# 1542 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1543 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1544 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_0
# 1547 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1548 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_SurveyedWheel_1:
# 1550 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_SurveyedWheel_2:
# 1485 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1486 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1487 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_0
# 1490 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1491 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1492 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_1
# 1496 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
	checkitem ITEM_BORROWED_PLIERS
# 0 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_EventScript_SurveyedWheel_7
# 1534 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1535 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_6
# 1538 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1539 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SurveyedWheel_1

SpindaIsland_Home_EventScript_SurveyedWheel_4:
# 1484 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_FOUND_TOUGH_BOLT, SpindaIsland_Home_EventScript_SurveyedWheel_2
	goto SpindaIsland_Home_EventScript_SurveyedWheel_3

SpindaIsland_Home_EventScript_SurveyedWheel_7:
# 1499 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1500 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_2
# 1503 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1504 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1506 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 15, DIR_EAST
# 1507 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1508 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1509 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_3
# 1512 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1513 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1515 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1516 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1517 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_4
# 1520 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1521 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1523 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 15, DIR_NORTH
# 1524 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1526 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1527 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1528 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_5
# 1531 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1532 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SurveyedWheel_1


SpindaIsland_Home_EventScript_Raft::
# 1554 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1555 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1556 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1557 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Raft_Text_0
# 1561 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1562 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1563 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_ThisIsConvenient::
# 1567 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1569 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_BROKE, SpindaIsland_Home_EventScript_ThisIsConvenient_2
SpindaIsland_Home_EventScript_ThisIsConvenient_1:
# 1584 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_ThisIsConvenient_2:
# 1570 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 1571 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 20
# 1573 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1574 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1575 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ThisIsConvenient_Text_0
# 1578 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1579 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1581 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_PASSED_IN_FRONT_OF_FAUCET_SHOP, 1
	goto SpindaIsland_Home_EventScript_ThisIsConvenient_1


SpindaIsland_Home_EventScript_Pot::
# 1588 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1589 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SALTED_DISH, SpindaIsland_Home_EventScript_Pot_2
# 1598 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1599 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1600 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pot_Text_1
# 1603 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_DISGUSTED
# 1604 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pot_Text_2
# 1608 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1609 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Pot_1:
# 1611 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Pot_2:
# 1590 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1591 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1592 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pot_Text_0
# 1595 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1596 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Pot_1


SpindaIsland_Home_EventScript_SaltDish::
# 1615 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1616 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_SALTY_LEMONADE
# 1617 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SALTED_DISH
# 1618 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1619 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1620 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SaltDish_Text_0
# 1623 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1624 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1626 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_POISON_POWDER
# 1627 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1628 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_POISON_POWDER
# 1629 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1630 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_POISON_POWDER
# 1631 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1633 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1634 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1635 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SaltDish_Text_1
# 1638 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1639 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1641 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_FeedZiggy::
# 1645 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1646 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1647 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1648 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_FeedZiggy_2
# 1653 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_FeedZiggy_Text_1
SpindaIsland_Home_EventScript_FeedZiggy_1:
# 1657 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1658 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1659 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_FeedZiggy_2:
# 1649 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_FeedZiggy_Text_0
	goto SpindaIsland_Home_EventScript_FeedZiggy_1


SpindaIsland_Home_EventScript_Cook::
# 1663 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1664 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1666 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_GOT_OIL, SpindaIsland_Home_EventScript_Cook_2
# 1676 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SALTED_DISH, SpindaIsland_Home_EventScript_Cook_3
# 1728 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_SAD
# 1729 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1730 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_5
# 1736 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1737 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1739 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_COOK_SAD
SpindaIsland_Home_EventScript_Cook_1:
# 1742 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Cook_2:
# 1667 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_NORMAL
# 1668 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1669 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_1
# 1673 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1674 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Cook_1

SpindaIsland_Home_EventScript_Cook_3:
# 1677 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1678 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1679 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_2
# 1682 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1683 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1685 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_SAD
# 1686 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1687 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_3
# 1690 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1691 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1694 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 20
# 1696 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_SAD
# 1697 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1698 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pot_Text_1
# 1701 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1702 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1704 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 1705 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 1706 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1707 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1708 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1710 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_NORMAL
# 1711 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1712 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_4
# 1719 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1720 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1722 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_COOK_SAD
# 1723 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_GOT_OIL
# 1724 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_COOKING_OIL
# 1726 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_Cook_1


SpindaIsland_Home_EventScript_Zigzagoon::
# 1746 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1747 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_ZIGGY_ASLEEP, SpindaIsland_Home_EventScript_Zigzagoon_2
# 1756 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_ENCOUNTER
# 1757 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Zigzagoon_Text_2
# 1758 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Zigzagoon_Text_3
# 1761 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 1762 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Zigzagoon_1:
# 1764 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Zigzagoon_2:
# 1748 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_SNORE
# 1749 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Zigzagoon_Text_0
# 1750 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Zigzagoon_Text_1
# 1753 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1754 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Zigzagoon_1


SpindaIsland_Home_EventScript_Pliers::
# 1768 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1769 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_ZIGGY_ASLEEP, SpindaIsland_Home_EventScript_Pliers_2
# 1783 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SAW_PLIERS, SpindaIsland_Home_EventScript_Pliers_5
# 1793 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_Pliers_8
# 1823 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1824 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1825 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_5
SpindaIsland_Home_EventScript_Pliers_1:
# 1833 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Pliers_2:
# 1770 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject VAR_LAST_TALKED
# 1771 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_BORROWED_PLIERS
# 1772 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_PICKED_UP_PLIERS
# 1774 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_DISGUSTED
# 1775 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1776 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_0
# 1780 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1781 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Pliers_1

SpindaIsland_Home_EventScript_Pliers_5:
# 1784 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1785 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1786 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_1
# 1790 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1791 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Pliers_1

SpindaIsland_Home_EventScript_Pliers_8:
# 1794 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1795 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1796 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_2
# 1800 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1801 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_3
# 1804 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1805 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1807 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_ENCOUNTER
# 1808 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Zigzagoon_Text_2
# 1809 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Zigzagoon_Text_3
# 1812 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 1813 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1814 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1815 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_4
# 1818 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1819 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1821 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SAW_PLIERS
	goto SpindaIsland_Home_EventScript_Pliers_1


SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy::
# 1837 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1838 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
# 1839 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1841 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_ENCOUNTER
# 1842 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Zigzagoon_Text_2
# 1843 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_0
# 1846 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 1847 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1849 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 30
# 1851 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_FAINT
# 1852 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Zigzagoon_Text_0
# 1853 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_1
# 1856 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 1857 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_SNORE
# 1858 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_2
# 1861 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1863 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1864 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1865 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_3
# 1869 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1870 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1872 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_ZIGGY_ASLEEP
# 1873 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_UseGrassBlade::
# 1877 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1878 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
# 1879 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1880 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_BobsDoor::
# 1884 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1885 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_BobsHouseSign_Text_0
# 1886 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsDoor_Text_0
# 1889 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1890 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1891 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsDoor_Text_1
# 1894 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 1895 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsDoor_Text_2
# 1898 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1899 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1900 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_CynthiasDoor::
# 1904 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1905 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1906 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1907 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_CynthiasDoor_Text_0
# 1911 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1912 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1913 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


# 1917 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_RaftGoesToIsland:
# 1918 "data/maps/SpindaIsland_Home/scripts.pory"
	face_left
# 1919 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 1920 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_anim
# 1921 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1921 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1921 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1921 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1921 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1921 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1921 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
	step_end

# 1924 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_PlayerEntersRaft:
# 1925 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1926 "data/maps/SpindaIsland_Home/scripts.pory"
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

SpindaIsland_Home_EventScript_BobsHouseSign_Text_0:
# 116 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Mindy$"

SpindaIsland_Home_EventScript_CynthiasHouseSign_Text_0:
# 120 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Cynthia$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_0:
# 129 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Door's locked.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_1:
# 138 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I guess I should leave him alone now.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_2:
# 146 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hello? Are you there?$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_3:
# 151 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Stingy man$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_4:
# 153 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…\p"
	.string "My GOD you're annoying.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_5:
# 172 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here's your reward. I hope you're\n"
	.string "happy.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_6:
# 191 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "An old and rusty bolt? What am I\n"
	.string "supposed to do with this?$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_7:
# 207 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A {COLOR RED}bolt{COLOR DARK_GRAY}! Of course! Lucky me!\p"
	.string "I'm one step closer to getting that\n"
	.string "sweet sweet faucet replacement!!$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_8:
# 213 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(Did I really say that? Is this how\n"
	.string "being a grownup feels like?)$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_9:
# 223 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A bolt?\p"
	.string "It's all rusty…\p"
	.string "Guess it'll join my useless trash\n"
	.string "collection!$"

SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_0:
# 239 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sad man$"

SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_1:
# 241 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Curse the architect that built my\n"
	.string "house facing the wrong direction!!\p"
	.string "I can never go home!$"

SpindaIsland_Home_EventScript_Dad_Text_0:
# 253 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Dad$"

SpindaIsland_Home_EventScript_Dad_Text_1:
# 255 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't uh, pour that lemonade I gave\n"
	.string "you on the ground or anything.\p"
	.string "It'd probably kill all the grass and\n"
	.string "flowers.$"

SpindaIsland_Home_EventScript_Dad_Text_2:
# 265 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here, have some lemonade!$"

SpindaIsland_Home_EventScript_Dad_Text_3:
# 273 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hiya, sonny! going adventuring today,\n"
	.string "are we?\p"
	.string "Want some lemonade?$"

SpindaIsland_Home_EventScript_Dad_Text_4:
# 286 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Now we're talkin'!! I can bring this to\n"
	.string "mom, that should do it!\p"
	.string "Let's take a sip first, I am PARCHED!$"

SpindaIsland_Home_EventScript_Dad_Text_5:
# 310 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "BLEARGH!\p"
	.string "Why is it… so salty?!$"

SpindaIsland_Home_EventScript_Dad_Text_6:
# 319 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Why, because it's seawater, obviously!$"

SpindaIsland_Home_EventScript_Dad_Text_7:
# 324 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I take it you're not a fan of my\n"
	.string "recipe?$"

SpindaIsland_Home_EventScript_Dad_Text_8:
# 329 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(You wouldn't be the only one…)$"

SpindaIsland_Home_EventScript_Dad_Text_9:
# 334 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "In any case, it's nice of you to come\n"
	.string "visit me at the office, haha!\p"
	.string "See you around, little Archie! Don't\n"
	.string "get into trouble!$"

SpindaIsland_Home_EventScript_Dad_FromSide_Text_0:
# 363 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Come round to the front of the\n"
	.string "lemonade stand!$"

SpindaIsland_Home_EventScript_Dad_FromSide_Text_1:
# 371 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hiya, sonny! going adventuring today,\n"
	.string "are we?\p"
	.string "Want some lemonade?\p"
	.string "Come round to the front of the\n"
	.string "lemonade stand!$"

SpindaIsland_Home_EventScript_LemonadeStandSign_Text_0:
# 385 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "“ARCHIE'S LEMONADE\n"
	.string "A taste of the seaside!”$"

SpindaIsland_Home_EventScript_MainStreetSign_Text_0:
# 392 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "{UP_ARROW} Main street$"

SpindaIsland_Home_EventScript_MadelineSign_Text_0:
# 398 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bertha$"

SpindaIsland_Home_EventScript_PoemGirl_Text_0:
# 408 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Maggie$"

SpindaIsland_Home_EventScript_PoemGirl_Text_1:
# 410 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "See you around, Archie…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_2:
# 427 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Archie…\p"
	.string "I want to hear a poem…\p"
	.string "I want you to reveal your heart to me.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_3:
# 441 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ocean waves swimming…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_4:
# 442 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Roses are red…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_5:
# 443 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Roses are blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_6:
# 455 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "From the center of the sea…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_7:
# 456 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "They are calling to my heart…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_8:
# 468 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "With faith to reach land.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_9:
# 469 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Only to go back.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_10:
# 479 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And my heart to theirs.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_11:
# 480 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yearning for a touch.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_12:
# 487 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "That was very beautiful.\p"
	.string "I'm not really into haiku, though.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_13:
# 500 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Violets are blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_14:
# 501 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Just like our love…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_15:
# 513 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The sky is pretty…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_16:
# 514 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The Pincurchin are spiky…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_17:
# 527 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And so are you.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_18:
# 528 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And so are you!$"

SpindaIsland_Home_EventScript_PoemGirl_Text_19:
# 534 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, that's nice.\p"
	.string "You're not truly revealing your poet's\n"
	.string "heart, though.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_20:
# 556 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "That's… a weird comparison.\p"
	.string "I thought you were a better poet\n"
	.string "than that.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_21:
# 572 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Which blooms like they do.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_22:
# 573 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wait, I didn't mean to say that.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_23:
# 579 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wow, Archie, uh…\p"
	.string "That's not really what I meant when I\n"
	.string "said you should reveal your heart.\p"
	.string "(Well, this is awkward.)\p"
	.string "(Let's pretend this never happened.)$"

SpindaIsland_Home_EventScript_PoemGirl_Text_24:
# 595 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Violets are red…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_25:
# 609 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The sky isn't blue, it's purple instead.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_26:
# 610 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Doesn't make sense, but fun to be said.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_27:
# 616 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmm…\p"
	.string "You're not revealing your heart right\n"
	.string "now.\p"
	.string "Plus, that didn't make any sense.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_28:
# 632 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Orchids are blue, too.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_29:
# 633 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Everything is blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_30:
# 655 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Because it's my favorite color.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_31:
# 660 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "… … … … …\p"
	.string "Wow, Archie, I…\p"
	.string "This was so touching…\p"
	.string "Thank you for revealing your heart to\n"
	.string "me like this.\p"
	.string "Here, take this.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_32:
# 674 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "It's a blade of grass large enough to\n"
	.string "whistle with.\p"
	.string "Just don't listen to it too\n"
	.string "attentively, you might get sleepy.$"

SpindaIsland_Home_EventScript_Sunbather_Text_0:
# 693 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sunbather$"

SpindaIsland_Home_EventScript_Sunbather_Text_1:
# 695 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ahh, it sure feels good to be sitting\n"
	.string "in the sun surrounded by all this\l"
	.string "{COLOR BLUE}WATER{COLOR DARK_GRAY}…\p"
	.string "…$"

SpindaIsland_Home_EventScript_Sunbather_Text_2:
# 706 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Could you leave? You're blocking the\n"
	.string "sun.$"

SpindaIsland_Home_Slowpoke_Text_0:
# 720 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slowbro$"

SpindaIsland_Home_Slowpoke_Text_1:
# 722 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bruh…$"

SpindaIsland_Home_Slowpoke_Text_2:
# 730 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slowpoke$"

SpindaIsland_Home_Slowpoke_Text_3:
# 732 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slo…$"

SpindaIsland_Home_Slowpoke_Text_4:
# 741 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "… … …?\p"
	.string "He's looking at the white seashell I\n"
	.string "found…$"

SpindaIsland_Home_Slowpoke_Text_5:
# 752 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Give the seashell$"

SpindaIsland_Home_Slowpoke_Text_6:
# 753 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't give the seashell$"

SpindaIsland_Home_Slowpoke_Text_7:
# 763 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sure, why the hell not!\p"
	.string "Here you go, buddy.$"

SpindaIsland_Home_Slowpoke_Text_8:
# 785 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bruh!!$"

SpindaIsland_Home_Slowpoke_Text_9:
# 793 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The heck?!\p"
	.string "My seashell bit him!$"

SpindaIsland_Home_Slowpoke_Text_10:
# 799 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Guess it was a Shellder all this time!$"

SpindaIsland_Home_Slowpoke_Text_11:
# 809 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…Slo…\p"
	.string ":($"

SpindaIsland_Home_EventScript_Metapod_Text_0:
# 823 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod$"

SpindaIsland_Home_EventScript_Metapod_Text_1:
# 826 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0:
# 836 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Twin$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_1:
# 838 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "What is it?!$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_2:
# 843 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, I guess we are blocking the stairs\n"
	.string "a little…\p"
	.string "Fine, we'll take our epic battle\n"
	.string "somewhere else.$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_0:
# 865 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "On god why you gotta bust my balls\n"
	.string "like that fr?!$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_1:
# 870 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yikes, we lowkey do be blockin the\n"
	.string "stairs rn no cap…\p"
	.string "Aight word word, we gon vibe\n"
	.string "somewhere else.$"

SpindaIsland_Home_EventScript_MetapodBoy_Text_0:
# 896 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm SO CLOSE to tasting that sweet,\n"
	.string "sweet victory!$"

SpindaIsland_Home_EventScript_MetapodBoy_Text_1:
# 906 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't you see we're in the midst of a\n"
	.string "fiery battle?$"

SpindaIsland_Home_EventScript_MetapodBoy_Text_2:
# 916 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod, use harden!!$"

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_0:
# 937 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm deadass SO CLOSE to catchin that\n"
	.string "bussin drip fr!$"

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_1:
# 947 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't you see we tryna catch some\n"
	.string "real heat rn bro? Sheesh!$"

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_2:
# 957 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod, keep hittin that mid boi with\n"
	.string "harden, chief!!$"

SpindaIsland_Home_PhotoCameraWrongDir_Text_0:
# 975 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't use that from this side.$"

SpindaIsland_Home_EventScript_FaucetShopSign_Text_0:
# 984 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "“FAUCET WORKSHOP\n"
	.string "For all your faucet needs!\l"
	.string "WE ARE OPEN!!”$"

SpindaIsland_Home_SlowpokeMistress_Text_0:
# 1034 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Girl$"

SpindaIsland_Home_SlowpokeMistress_Text_1:
# 1036 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Look at my super cool Slowbro!\p"
	.string "He just looks so happy!$"

SpindaIsland_Home_SlowpokeMistress_Text_2:
# 1051 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "By Arceus!!\p"
	.string "How on earth did you convince him to\n"
	.string "evolve?$"

SpindaIsland_Home_SlowpokeMistress_Text_3:
# 1057 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…A cool-looking seashell? What are\n"
	.string "you talking about?$"

SpindaIsland_Home_SlowpokeMistress_Text_4:
# 1062 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Well, thank you anyway! You can have\n"
	.string "this!$"

SpindaIsland_Home_SlowpokeMistress_Text_5:
# 1067 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I no longer need it.$"

SpindaIsland_Home_SlowpokeMistress_Text_6:
# 1077 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmm… A {COLOR BLUE}WATER{COLOR DARK_GRAY} Stone…\p"
	.string "Maybe I could try giving this to mom?$"

SpindaIsland_Home_SlowpokeMistress_Text_7:
# 1088 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I wish my Pokémon would evolve…$"

SpindaIsland_Home_SlowpokeMistress_Text_8:
# 1093 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I keep trying to give him this {COLOR BLUE}WATER{COLOR DARK_GRAY}\n"
	.string "Stone, but it just does nothing.\p"
	.string "Perhaps there's another way…$"

SpindaIsland_Home_EventScript_Juan_Text_0:
# 1106 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Juan$"

SpindaIsland_Home_EventScript_Juan_Text_1:
# 1109 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey, wanna hear more interesting\n"
	.string "facts about Pokémon?$"

SpindaIsland_Home_EventScript_Juan_Text_2:
# 1119 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Nope$"

SpindaIsland_Home_EventScript_Juan_Text_3:
# 1120 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "No thanks$"

SpindaIsland_Home_EventScript_Juan_Text_4:
# 1125 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bummer! Come back whenever, I have\n"
	.string "plenty!$"

SpindaIsland_Home_EventScript_Juan_Text_5:
# 1132 "data/maps/SpindaIsland_Home/scripts.pory"
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
# 1144 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh boy, what a find! I need to write\n"
	.string "this discovery down in my PokéDex!!$"

SpindaIsland_Home_EventScript_Machoke_Text_0:
# 1159 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sexy Machoke$"

SpindaIsland_Home_EventScript_Machoke_Text_1:
# 1161 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Machoke$"

SpindaIsland_Home_EventScript_Machoke_Text_2:
# 1164 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmmm…$"

SpindaIsland_Home_EventScript_Lisa_Text_0:
# 1175 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Lisa$"

SpindaIsland_Home_EventScript_Lisa_Text_1:
# 1177 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey Archie! Heard you were building a\n"
	.string "sick pirate ship!$"

SpindaIsland_Home_EventScript_OldWoman_Text_0:
# 1190 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Old woman$"

SpindaIsland_Home_EventScript_OldWoman_Text_1:
# 1192 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I think my house is haunted. There's\n"
	.string "something living in my attic.\p"
	.string "I don't know what to do…$"

SpindaIsland_Home_EventScript_OldWoman_Text_2:
# 1203 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, I'm too scared to go back inside…$"

SpindaIsland_Home_EventScript_OldWoman_Text_3:
# 1221 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't worry granny! There were some\n"
	.string "Shuppet in your attic, but I chased\l"
	.string "them away!$"

SpindaIsland_Home_EventScript_OldWoman_Text_4:
# 1229 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Shuppet, you say?$"

SpindaIsland_Home_EventScript_OldWoman_Text_5:
# 1233 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "How adorable of you to help out a poor\n"
	.string "old lady…\p"
	.string "How can I repay you?\p"
	.string "You look like you're hungry… Let me\n"
	.string "fix you a little snack!$"

SpindaIsland_Home_EventScript_OldWoman_Text_6:
# 1244 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Have a good day, child.$"

SpindaIsland_Home_EventScript_OldWoman_Text_7:
# 1258 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Cool! Lemme pack this up for later.\p"
	.string "Let's hope it doesn't taste like old\n"
	.string "people or something.$"

SpindaIsland_Home_EventScript_OldWomansDoor_Text_0:
# 1275 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm glad I was able to help!$"

SpindaIsland_Home_EventScript_Chest_Text_0:
# 1289 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Already opened it!$"

SpindaIsland_Home_EventScript_Chest_Text_1:
# 1297 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Woah, a treasure chest?!\p"
	.string "Wonder who put it here!$"

SpindaIsland_Home_EventScript_Chest_Text_2:
# 1313 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A {COLOR RED}bolt{COLOR DARK_GRAY}!!\p"
	.string "And it's gold, too!\p"
	.string "How lucky!$"

SpindaIsland_Home_EventScript_Chest_Text_3:
# 1325 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A gold coin?!$"

SpindaIsland_Home_EventScript_Chest_Text_4:
# 1329 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ah, no, it's a {COLOR RED}bolt{COLOR DARK_GRAY}.\p"
	.string "Weird, I wonder who put it here.$"

SpindaIsland_Home_CarBoy_Text_0:
# 1343 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Rudy$"

SpindaIsland_Home_CarBoy_Text_1:
# 1345 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Vrrrbbbbbmmmmmmm!!!!!$"

SpindaIsland_Home_CarGirl_Text_0:
# 1359 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Katie$"

SpindaIsland_Home_CarGirl_Text_1:
# 1361 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Thanks a bunch!$"

SpindaIsland_Home_CarGirl_Text_2:
# 1371 "data/maps/SpindaIsland_Home/scripts.pory"
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
# 1388 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Now what could we use as a wheel…$"

SpindaIsland_Home_CarGirl_Text_4:
# 1397 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey Archie!\p"
	.string "As you can see we're almost done with\n"
	.string "our monster car.\p"
	.string "We're just missing one last wheel!\p"
	.string "We don't really need it to be an actual\n"
	.string "wheel, either.\p"
	.string "Anything round and spinny would do!$"

SpindaIsland_Home_EventScript_MissingWheel_Text_0:
# 1421 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A shiny new wheel!$"

SpindaIsland_Home_EventScript_MissingWheel_Text_1:
# 1429 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A wheel is missing.\p"
	.string "I'm sure I could find a replacement.$"

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_0:
# 1445 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "What if…$"

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_1:
# 1462 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Fits perfectly! There ya go!$"

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_2:
# 1475 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "This'd be perfect, but I need to\n"
	.string "repair it!$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_0:
# 1488 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Just a regular wheel.$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_1:
# 1493 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wait, it's stuck to the car with bolts!\p"
	.string "If I could just take one…$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_2:
# 1501 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here, let me just…$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_3:
# 1510 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Whatcha doing, Archie?$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_4:
# 1518 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ah, uh, nothing!$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_5:
# 1529 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(Darn, can't do this right under her\n"
	.string "nose.)$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_6:
# 1536 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'd need some pliers to get it out.$"

SpindaIsland_Home_EventScript_Raft_Text_0:
# 1558 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "My super-awesome pirate ship!\p"
	.string "Only thing missing is the sail.$"

SpindaIsland_Home_EventScript_ThisIsConvenient_Text_0:
# 1576 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Well, this is eerily convenient!$"

SpindaIsland_Home_EventScript_Pot_Text_0:
# 1593 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Much better!$"

SpindaIsland_Home_EventScript_Pot_Text_1:
# 1601 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slurp…$"

SpindaIsland_Home_EventScript_Pot_Text_2:
# 1605 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ugh, it's tasteless…\p"
	.string "Have people never heard of salt?$"

SpindaIsland_Home_EventScript_SaltDish_Text_0:
# 1621 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Needs some salt, so maybe…$"

SpindaIsland_Home_EventScript_SaltDish_Text_1:
# 1636 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "There, fixed, probably!$"

SpindaIsland_Home_EventScript_FeedZiggy_Text_0:
# 1650 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Good idea, except I need this\n"
	.string "sandwich for the faucet salesman!$"

SpindaIsland_Home_EventScript_FeedZiggy_Text_1:
# 1654 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'd be afraid of this one biting off my\n"
	.string "hand!$"

SpindaIsland_Home_EventScript_Cook_Text_0:
# 1668 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Cook$"

SpindaIsland_Home_EventScript_Cook_Text_1:
# 1670 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Thank you again.\p"
	.string "You will become a great chef when you\n"
	.string "grow up, I can feel it!$"

SpindaIsland_Home_EventScript_Cook_Text_2:
# 1680 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can you try your dish now?$"

SpindaIsland_Home_EventScript_Cook_Text_3:
# 1688 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "It's not like it's gotten any tastier\n"
	.string "on its own, but sure.$"

SpindaIsland_Home_EventScript_Cook_Text_4:
# 1713 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, wow! It's… It's remarkable!!\p"
	.string "What arcane sorcery…\p"
	.string "What? You added some lemonade in the\n"
	.string "pot?\p"
	.string "Who would have thought!!\p"
	.string "I don't have much to thank you, but\n"
	.string "here is a bottle of my finest cooking\l"
	.string "oil!$"

SpindaIsland_Home_EventScript_Cook_Text_5:
# 1731 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I am distraught.\p"
	.string "My dish isn't turning out how I wanted\n"
	.string "at all…\p"
	.string "How can I make it less… flavorless?\p"
	.string "Is there any hope at all?$"

SpindaIsland_Home_EventScript_Zigzagoon_Text_0:
# 1749 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sleepy Zigzagoon$"

SpindaIsland_Home_EventScript_Zigzagoon_Text_1:
# 1751 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "ZzzzzZzZz…$"

SpindaIsland_Home_EventScript_Zigzagoon_Text_2:
# 1757 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Rabid Zigzagoon$"

SpindaIsland_Home_EventScript_Zigzagoon_Text_3:
# 1759 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "GRRRRRRRR…$"

SpindaIsland_Home_EventScript_Pliers_Text_0:
# 1777 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yuck, the Zigzagoon drooled all over\n"
	.string "them!\p"
	.string "At least I hope it's drool…$"

SpindaIsland_Home_EventScript_Pliers_Text_1:
# 1787 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't get to those {COLOR RED}pliers{COLOR DARK_GRAY} with that\n"
	.string "Zigzagoon guarding them…\p"
	.string "If only there was a way to distract or\n"
	.string "incapacitate it…$"

SpindaIsland_Home_EventScript_Pliers_Text_2:
# 1797 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "These must be the {COLOR RED}pliers{COLOR DARK_GRAY} the faucet\n"
	.string "salesman was talking about!$"

SpindaIsland_Home_EventScript_Pliers_Text_3:
# 1802 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "You're gonna give them to me, right\n"
	.string "little Ziggy?$"

SpindaIsland_Home_EventScript_Pliers_Text_4:
# 1816 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Nope, not gonna risk a hand just to\n"
	.string "get these!$"

SpindaIsland_Home_EventScript_Pliers_Text_5:
# 1826 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Is this… a pair of {COLOR RED}pliers{COLOR DARK_GRAY}?\p"
	.string "I wonder what a Zigzagoon would use\n"
	.string "these for.$"

SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_0:
# 1844 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "GRRRRRRRR!!$"

SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_1:
# 1854 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…GrrrzzZZzzzzZz…$"

SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_2:
# 1859 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "ZzzzZzZzzZZzzz…$"

SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_3:
# 1866 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Awesome! It fell asleep!\p"
	.string "Let's get those {COLOR RED}pliers{COLOR DARK_GRAY}!$"

SpindaIsland_Home_EventScript_BobsDoor_Text_0:
# 1887 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey Archie! Wanna come in for a\n"
	.string "Pokémon trade?$"

SpindaIsland_Home_EventScript_BobsDoor_Text_1:
# 1892 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't today, I'm busy!$"

SpindaIsland_Home_EventScript_BobsDoor_Text_2:
# 1896 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(Never again.)$"

SpindaIsland_Home_EventScript_CynthiasDoor_Text_0:
# 1908 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I ain't going in there unprepared.\p"
	.string "Or at all.$"

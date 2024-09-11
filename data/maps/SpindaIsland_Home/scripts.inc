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
	goto_if_set FLAG_TOOK_SPINDA, SpindaIsland_Home_EventScript_MainQuestRecap_2
# 105 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MainQuestRecap_Text_2
# 108 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 109 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MainQuestRecap_Text_3
SpindaIsland_Home_EventScript_MainQuestRecap_1:
# 115 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 116 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 117 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 3
# 118 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MainQuestRecap_2:
# 92 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_READ_SPINDA_INSTRUCTIONS, SpindaIsland_Home_EventScript_MainQuestRecap_5
# 98 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MainQuestRecap_Text_1
	goto SpindaIsland_Home_EventScript_MainQuestRecap_1

SpindaIsland_Home_EventScript_MainQuestRecap_5:
# 93 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
	goto SpindaIsland_Home_EventScript_MainQuestRecap_1


SpindaIsland_Home_EventScript_MetapodOtherSide::
# 122 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 123 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_METAPOD_OTHER_SIDE, 1
# 124 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_ArchiesHouseSign::
# 130 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ArchiesHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_TryToBlindZiggy::
# 136 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 137 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_SWITCH
# 138 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 139 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_LEER
# 140 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, 0
# 141 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, 0
# 142 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 143 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 30
# 145 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_ENCOUNTER
# 146 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_TryToBlindZiggy_Text_0
# 147 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_TryToBlindZiggy_Text_1
# 148 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 149 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 150 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 151 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_TryToBlindZiggy_Text_2
# 152 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 153 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 154 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_BobsHouseSign::
# 158 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_CynthiasHouseSign::
# 162 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_CynthiasHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_SadManHome_Back::
# 166 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 167 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_HIDE_MAN_CANT_GO_HOME, SpindaIsland_Home_EventScript_SadManHome_Back_2
# 176 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_RUSTY_BOLT, SpindaIsland_Home_EventScript_SadManHome_Back_5
# 185 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 186 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 187 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_2
# 190 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 191 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 193 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_SadManHome_Back_Text_3
# 194 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_4
# 198 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 200 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 202 "data/maps/SpindaIsland_Home/scripts.pory"
	clearflag FLAG_HIDE_MAN_CANT_GO_HOME
# 203 "data/maps/SpindaIsland_Home/scripts.pory"
	setobjectxyperm 6, 42, 24
# 204 "data/maps/SpindaIsland_Home/scripts.pory"
	addobject 6
# 205 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement 6, SpindaIsland_Home_Movement_SadManExitsHouse
# 206 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Movement_PlayerMakesWay
# 207 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 208 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 6
# 209 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 210 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 211 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 212 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_SadManHome_Back_Text_3
# 213 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_5
# 216 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 217 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 218 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_RUSTY_BOLT
# 219 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_RUSTY_BOLT
# 220 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement 6, SpindaIsland_Home_Movement_SadManReEntersHouse
# 221 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 222 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 223 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 6
# 224 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_MAN_CANT_GO_HOME
# 225 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 227 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 229 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_SadManHome_Back_8
# 262 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 263 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 264 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_9
# 269 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 270 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_SadManHome_Back_1:
# 274 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_SadManHome_Back_2:
# 168 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 169 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 170 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_0
# 173 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 174 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1

SpindaIsland_Home_EventScript_SadManHome_Back_5:
# 177 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 178 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 179 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_1
# 182 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 183 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1

SpindaIsland_Home_EventScript_SadManHome_Back_8:
# 230 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 231 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 232 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_6
# 235 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 236 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 238 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 240 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 241 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 242 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 243 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 244 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 246 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 247 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 248 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_7
# 252 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 253 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 254 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_8
# 257 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 258 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 260 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1


SpindaIsland_Home_EventScript_ICanNeverGoHome::
# 278 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 279 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 280 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SAD
# 281 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_0
# 282 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_1, MSGBOX_NPC
# 286 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 287 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_Dad::
# 291 "data/maps/SpindaIsland_Home/scripts.pory"
	lockall
# 292 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 7, DIR_SOUTH
# 293 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OBTAINED_LEMONADE, SpindaIsland_Home_EventScript_Dad_2
# 303 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SPOKE_TO_DAD, SpindaIsland_Home_EventScript_Dad_6
# 312 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 313 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 314 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_3
# 318 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 319 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Dad_5:
# 322 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_SALTY_LEMONADE
# 324 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 325 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 326 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 327 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_4
# 331 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 332 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 334 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 10
# 335 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 336 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 337 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 338 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 339 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 340 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 341 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 20
# 343 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 344 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 345 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 346 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 347 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 349 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_DISGUSTED
# 350 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 351 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_5
# 355 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 356 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 358 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_GRINNING
# 359 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 360 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_6
# 363 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 364 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 365 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_7
# 368 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 369 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_EMBARRASSED
# 370 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_8
# 373 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 374 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 375 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_9
# 379 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 380 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 382 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_OBTAINED_LEMONADE
# 383 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SPOKE_TO_DAD
SpindaIsland_Home_EventScript_Dad_1:
# 385 "data/maps/SpindaIsland_Home/scripts.pory"
	releaseall
	return

SpindaIsland_Home_EventScript_Dad_2:
# 294 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_EMBARRASSED
# 295 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 296 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_1
# 300 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 301 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_1

SpindaIsland_Home_EventScript_Dad_6:
# 304 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 305 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 306 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_2
# 309 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 310 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_5


SpindaIsland_Home_EventScript_Dad_FromSide::
# 389 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 390 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 391 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OBTAINED_LEMONADE, SpindaIsland_Home_EventScript_Dad_FromSide_2
# 401 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SPOKE_TO_DAD, SpindaIsland_Home_EventScript_Dad_FromSide_6
# 410 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 411 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 412 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_FromSide_Text_1
# 417 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 418 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Dad_FromSide_5:
# 420 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SPOKE_TO_DAD
SpindaIsland_Home_EventScript_Dad_FromSide_1:
# 422 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Dad_FromSide_2:
# 392 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_EMBARRASSED
# 393 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 394 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_1
# 398 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 399 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_FromSide_1

SpindaIsland_Home_EventScript_Dad_FromSide_6:
# 402 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_NORMAL
# 403 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 404 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_FromSide_Text_0
# 407 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 408 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_FromSide_5


SpindaIsland_Home_EventScript_LemonadeStandSign::
# 426 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_LemonadeStandSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_MainStreetSign::
# 433 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MainStreetSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_MadelineSign::
# 439 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MadelineSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_PoemGirl::
# 445 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 447 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_POEM_GIRL, SpindaIsland_Home_EventScript_PoemGirl_2
# 461 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
# 462 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 464 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 466 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 467 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 468 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_2
# 473 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 474 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 476 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_3, SpindaIsland_Home_EventScript_PoemGirl_Text_4, SpindaIsland_Home_EventScript_PoemGirl_Text_5
# 488 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 489 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_6
# 534 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_7
# 629 "data/maps/SpindaIsland_Home/scripts.pory"
	case 2, SpindaIsland_Home_EventScript_PoemGirl_8
SpindaIsland_Home_EventScript_PoemGirl_1:
# 727 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 728 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 729 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_PoemGirl_2:
# 448 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 449 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 450 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 451 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_1
# 454 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 455 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 457 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 458 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 459 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_6:
# 490 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_6, SpindaIsland_Home_EventScript_PoemGirl_Text_7
# 501 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 502 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_11
# 513 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_12
SpindaIsland_Home_EventScript_PoemGirl_9:
# 526 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 527 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 528 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_12
# 532 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 533 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_7:
# 535 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_13, SpindaIsland_Home_EventScript_PoemGirl_Text_14
# 545 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 547 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_14
# 606 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_15
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_8:
# 630 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_24, SpindaIsland_Home_EventScript_PoemGirl_Text_13
# 641 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 643 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_17
# 666 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_18
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_11:
# 503 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_8, SpindaIsland_Home_EventScript_PoemGirl_Text_9
	goto SpindaIsland_Home_EventScript_PoemGirl_9

SpindaIsland_Home_EventScript_PoemGirl_12:
# 514 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_10, SpindaIsland_Home_EventScript_PoemGirl_Text_11
	goto SpindaIsland_Home_EventScript_PoemGirl_9

SpindaIsland_Home_EventScript_PoemGirl_14:
# 548 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_15, SpindaIsland_Home_EventScript_PoemGirl_Text_16
# 559 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 561 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_20
# 583 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_21
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_15:
# 607 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_21, SpindaIsland_Home_EventScript_PoemGirl_Text_22
# 618 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 619 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 620 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_23
# 626 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 627 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_17:
# 644 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_25, SpindaIsland_Home_EventScript_PoemGirl_Text_26
# 655 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 656 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 657 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_27
# 662 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 663 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_18:
# 667 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_28, SpindaIsland_Home_EventScript_PoemGirl_Text_29
# 678 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 679 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_23
# 689 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_24
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_20:
# 562 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_17, SpindaIsland_Home_EventScript_PoemGirl_Text_18
# 573 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 574 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 575 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_19
# 579 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 580 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_21:
# 584 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_17, SpindaIsland_Home_EventScript_PoemGirl_Text_18
# 595 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 596 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 597 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_20
# 601 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 602 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_23:
# 680 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 681 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 682 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_27
# 687 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 688 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_24:
# 690 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_30
# 699 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 700 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 701 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_31
# 708 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 709 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 711 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_GRASS_BLADE
# 713 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 714 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 715 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_32
# 719 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 720 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 722 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_POEM_GIRL
	goto SpindaIsland_Home_EventScript_PoemGirl_1


SpindaIsland_Home_EventScript_Sunbather::
# 733 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 734 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Home_Sunbather
# 735 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_FACING
# 736 "data/maps/SpindaIsland_Home/scripts.pory"
	case DIR_NORTH, SpindaIsland_Home_EventScript_Sunbather_3
# 738 "data/maps/SpindaIsland_Home/scripts.pory"
	case DIR_SOUTH, SpindaIsland_Home_EventScript_Sunbather_4
# 740 "data/maps/SpindaIsland_Home/scripts.pory"
	case DIR_WEST, SpindaIsland_Home_EventScript_Sunbather_5
# 742 "data/maps/SpindaIsland_Home/scripts.pory"
	case DIR_EAST, SpindaIsland_Home_EventScript_Sunbather_6
SpindaIsland_Home_EventScript_Sunbather_1:
# 745 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Home_CheckSunbatherFlags
# 746 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Sunbather_3:
# 737 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_TALKED_TO_SUNBATHER
	goto SpindaIsland_Home_EventScript_Sunbather_1

SpindaIsland_Home_EventScript_Sunbather_4:
# 739 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_TALKED_TO_SUNBATHER_CLOCK1
	goto SpindaIsland_Home_EventScript_Sunbather_1

SpindaIsland_Home_EventScript_Sunbather_5:
# 741 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_TALKED_TO_SUNBATHER_CLOCK2
	goto SpindaIsland_Home_EventScript_Sunbather_1

SpindaIsland_Home_EventScript_Sunbather_6:
# 743 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_TALKED_TO_SUNBATHER_CLOCK3
	goto SpindaIsland_Home_EventScript_Sunbather_1


SpindaIsland_Home_CheckSunbatherFlags::
# 751 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_TALKED_TO_SUNBATHER, SpindaIsland_Home_CheckSunbatherFlags_3
	return

SpindaIsland_Home_CheckSunbatherFlags_1:
# 758 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SUNBATHER_ALL_DIR
# 759 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 760 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 761 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CheckSunbatherFlags_Text_0
# 764 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 765 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	return

SpindaIsland_Home_CheckSunbatherFlags_2:
# 753 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_TALKED_TO_SUNBATHER_CLOCK2, SpindaIsland_Home_CheckSunbatherFlags_7
	return

SpindaIsland_Home_CheckSunbatherFlags_3:
# 752 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_TALKED_TO_SUNBATHER_CLOCK1, SpindaIsland_Home_CheckSunbatherFlags_2
	return

SpindaIsland_Home_CheckSunbatherFlags_6:
# 756 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_SUNBATHER_ALL_DIR, SpindaIsland_Home_CheckSunbatherFlags_1
	return

SpindaIsland_Home_CheckSunbatherFlags_7:
# 754 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_TALKED_TO_SUNBATHER_CLOCK3, SpindaIsland_Home_CheckSunbatherFlags_6
	return


SpindaIsland_Home_Sunbather::
# 771 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_TALKED_TO_SUNBATHER, SpindaIsland_Home_Sunbather_4
SpindaIsland_Home_Sunbather_1:
# 787 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 789 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_SUNBATHER, EMOTE_PENSIVE
# 790 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Sunbather_Text_0
# 791 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Sunbather_Text_2
# 794 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 795 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 796 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 797 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
	return

SpindaIsland_Home_Sunbather_2:
# 776 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_SUNBATHER, EMOTE_NORMAL
# 777 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Sunbather_Text_0
# 778 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Sunbather_Text_1
# 782 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 783 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 784 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
	goto SpindaIsland_Home_Sunbather_1

SpindaIsland_Home_Sunbather_3:
# 773 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_TALKED_TO_SUNBATHER_CLOCK2, SpindaIsland_Home_Sunbather_7
	goto SpindaIsland_Home_Sunbather_1

SpindaIsland_Home_Sunbather_4:
# 772 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_TALKED_TO_SUNBATHER_CLOCK1, SpindaIsland_Home_Sunbather_3
	goto SpindaIsland_Home_Sunbather_1

SpindaIsland_Home_Sunbather_7:
# 774 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_TALKED_TO_SUNBATHER_CLOCK3, SpindaIsland_Home_Sunbather_2
	goto SpindaIsland_Home_Sunbather_1


SpindaIsland_Home_EventScript_HearTheSea::
# 801 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 802 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 803 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 804 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_HearTheSea_Text_0
# 807 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 808 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_HearTheSea_Text_1
# 811 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 812 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 813 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_Slowpoke::
# 817 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 818 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_Slowpoke_2
# 829 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 830 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
# 831 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_2
# 832 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_3
# 835 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 836 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	checkitem ITEM_WHITE_SEASHELL
# 0 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SpindaIsland_Home_Slowpoke_5
SpindaIsland_Home_Slowpoke_1:
# 919 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_Slowpoke_2:
# 819 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 820 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
# 821 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_0
# 822 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_1
# 825 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 826 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_5:
# 839 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 840 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 841 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_4
# 846 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Slowpoke_Text_5, SpindaIsland_Home_Slowpoke_Text_6
# 856 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 857 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 859 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 860 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_Slowpoke_8
# 906 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_Slowpoke_9
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_8:
# 861 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 862 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 863 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_7
# 867 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 868 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 870 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_WHITE_SEASHELL
# 872 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWBRO )
# 873 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SHELLDER, CRY_MODE_NORMAL
# 874 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 875 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject VAR_LAST_TALKED
# 876 "data/maps/SpindaIsland_Home/scripts.pory"
	addobject VAR_LAST_TALKED
# 877 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_BITE
# 878 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, SpindaIsland_Home_Movement_Slowpoke
# 879 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 880 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement VAR_LAST_TALKED
# 881 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 883 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
# 884 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_0
# 885 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_8
# 888 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 889 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 891 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SHOCKED
# 892 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 893 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_9
# 897 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 898 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 899 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_10
# 902 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 903 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 905 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SLOWPOKE_EVOLVED
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_9:
# 907 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_FAINT
# 908 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_2
# 909 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_11
# 913 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 914 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Slowpoke_1


SpindaIsland_Home_EventScript_Metapod::
# 923 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 924 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Metapod_Text_0
# 925 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_METAPOD, CRY_MODE_NORMAL
# 926 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Metapod_Text_1
# 929 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 930 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 931 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoysFuckOff::
# 935 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 936 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 937 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 938 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_1
# 942 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_NORMAL
# 943 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_2
# 947 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 949 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_TO_BLACK
# 950 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_METAPOD_BATTLE
# 951 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 1
# 952 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 2
# 953 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 3
# 954 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 4
# 955 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 60
# 956 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 957 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 40
# 958 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin::
# 962 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 963 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 964 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 965 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_0
# 969 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_NORMAL
# 970 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_1
# 974 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 975 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 977 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_TO_BLACK
# 978 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_METAPOD_BATTLE
# 979 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 1
# 980 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 2
# 981 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 3
# 982 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 4
# 983 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 60
# 984 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 985 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 40
# 986 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoy::
# 990 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 991 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_METAPOD_OTHER_SIDE, 1
	goto_if_eq SpindaIsland_Home_EventScript_MetapodBoy_2
SpindaIsland_Home_EventScript_MetapodBoy_1:
# 994 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 995 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 996 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Text_0
# 999 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1000 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1002 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1004 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_FINGER
# 1005 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 1006 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Text_1
# 1009 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1010 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1012 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1014 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 1015 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 1016 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Text_2
# 1019 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1020 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1022 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 1023 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1024 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 1025 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1026 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1027 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MetapodBoy_2:
# 992 "data/maps/SpindaIsland_Home/scripts.pory"
	goto SpindaIsland_Home_EventScript_MetapodBoysFuckOff
	goto SpindaIsland_Home_EventScript_MetapodBoy_1


SpindaIsland_Home_EventScript_MetapodBoy_Bussin::
# 1031 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1032 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_METAPOD_OTHER_SIDE, 1
	goto_if_eq SpindaIsland_Home_EventScript_MetapodBoy_Bussin_2
SpindaIsland_Home_EventScript_MetapodBoy_Bussin_1:
# 1035 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 1036 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 1037 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_0
# 1040 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1041 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1043 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1045 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_FINGER
# 1046 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 1047 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_1
# 1050 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1051 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1053 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1055 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 1056 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 1057 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_2
# 1060 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1061 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1063 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 1064 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1065 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 1066 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1067 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1068 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_2:
# 1033 "data/maps/SpindaIsland_Home/scripts.pory"
	goto SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin
	goto SpindaIsland_Home_EventScript_MetapodBoy_Bussin_1


SpindaIsland_Home_PhotoCameraWrongDir::
# 1072 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1073 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1074 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1075 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_PhotoCameraWrongDir_Text_0
# 1078 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1079 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1080 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_FaucetShopSign::
# 1084 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_FaucetShopSign_Text_0, MSGBOX_SIGN
	return


# 1091 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_SadManExitsHouse:
# 1092 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
	step_end

# 1095 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_SadManReEntersHouse:
# 1096 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 1097 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1098 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
	step_end

# 1101 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_PlayerMakesWay:
# 1102 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 1103 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1104 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
	step_end

# 1107 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_Slowpoke:
# 1108 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 1109 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 1110 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
# 1111 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1111 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1111 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1112 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 1113 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1114 "data/maps/SpindaIsland_Home/scripts.pory"
	face_down
# 1115 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1116 "data/maps/SpindaIsland_Home/scripts.pory"
	face_left
# 1117 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1118 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 1119 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1120 "data/maps/SpindaIsland_Home/scripts.pory"
	face_player
# 1121 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1121 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1121 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1122 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 1123 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 1124 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 1125 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
# 1126 "data/maps/SpindaIsland_Home/scripts.pory"
	emote_heart
# 1127 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1127 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1127 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
	step_end

SpindaIsland_Home_SlowpokeMistress::
# 1131 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1132 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1133 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_SLOWPOKE_REWARD, SpindaIsland_Home_SlowpokeMistress_2
# 1142 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_SlowpokeMistress_3
# 1188 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_SWEAT
# 1189 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 1190 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_7
# 1193 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1194 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 1195 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_8
# 1199 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1200 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_SlowpokeMistress_1:
# 1202 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_SlowpokeMistress_2:
# 1134 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_HAPPY
# 1135 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 1136 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_1
# 1140 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1141 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_SlowpokeMistress_1

SpindaIsland_Home_SlowpokeMistress_3:
# 1143 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 1144 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 1145 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1146 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1147 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1149 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_SURPRISED
# 1150 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 1151 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_2
# 1155 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1156 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 1157 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_3
# 1160 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1161 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_HAPPY
# 1162 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_4
# 1165 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1166 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 1167 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_5
# 1170 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1171 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1173 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_WATER_STONE_2
# 1175 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 1176 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1177 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_6
# 1183 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1184 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1186 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_SLOWPOKE_REWARD
	goto SpindaIsland_Home_SlowpokeMistress_1


SpindaIsland_Home_EventScript_Juan::
# 1206 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1207 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1208 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 1209 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Juan_Text_0
# 1210 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_TALKED_TO_JUAN_ABOUT_PUBES, SpindaIsland_Home_EventScript_Juan_2
# 1234 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_5
# 1245 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SURPRISED
# 1246 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_6
# 1249 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1250 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1251 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_TALKED_TO_JUAN_ABOUT_PUBES
SpindaIsland_Home_EventScript_Juan_1:
# 1254 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Juan_2:
# 1211 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_1
# 1215 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_Juan_Text_2, SpindaIsland_Home_EventScript_Juan_Text_3
# 1226 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 1227 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_4
# 1231 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1232 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Juan_1


SpindaIsland_Home_EventScript_Machoke::
# 1258 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1259 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1260 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
# 1261 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_TALKED_TO_JUAN_ABOUT_PUBES, SpindaIsland_Home_EventScript_Machoke_2
# 1264 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Machoke_Text_1
SpindaIsland_Home_EventScript_Machoke_1:
# 1266 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Machoke_Text_2
# 1269 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1270 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1271 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Machoke_2:
# 1262 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Machoke_Text_0
	goto SpindaIsland_Home_EventScript_Machoke_1


SpindaIsland_Home_EventScript_Lisa::
# 1275 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1276 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1277 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL_BLACK, EMOTE_NORMAL
# 1278 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Lisa_Text_0
# 1279 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Lisa_Text_1
# 1283 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1284 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1285 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_OldWoman::
# 1289 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1290 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1291 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_SHUPPET_QUEST_STARTED, SpindaIsland_Home_EventScript_OldWoman_2
# 1302 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_HIDE_SHUPPETS, SpindaIsland_Home_EventScript_OldWoman_3
SpindaIsland_Home_EventScript_OldWoman_1:
# 1313 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_HIDE_SHUPPETS, SpindaIsland_Home_EventScript_OldWoman_7
SpindaIsland_Home_EventScript_OldWoman_6:
# 1370 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_OldWoman_2:
# 1292 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1293 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1294 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1295 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_1
# 1299 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1300 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1301 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SHUPPET_QUEST_STARTED
	goto SpindaIsland_Home_EventScript_OldWoman_1

SpindaIsland_Home_EventScript_OldWoman_3:
# 1303 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1304 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1305 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1306 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_2
# 1309 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1310 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_OldWoman_1

SpindaIsland_Home_EventScript_OldWoman_7:
# 1314 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1315 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1316 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_2
# 1319 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1320 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1322 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1323 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1324 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_3
# 1327 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1328 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1330 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1331 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1332 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_4
# 1335 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 1336 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_5
# 1341 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1342 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1344 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_PB_AND_J
# 1346 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 1347 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_6
# 1350 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1351 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1353 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 1354 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject VAR_LAST_TALKED
# 1355 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 1356 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1357 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_OLD_WOMAN
# 1359 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1360 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1361 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_7
# 1365 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1366 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1368 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_OldWoman_6


SpindaIsland_Home_EventScript_OldWomansDoor::
# 1374 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1376 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1377 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1378 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWomansDoor_Text_0
# 1381 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1382 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1384 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_Chest::
# 1388 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1389 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OPENED_CHEST, SpindaIsland_Home_EventScript_Chest_2
# 1398 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1399 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1400 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Chest_Text_1
# 1404 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1405 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1407 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 53, 27, METATILE_SpindaIsland_EmptyChest, TRUE
# 1408 "data/maps/SpindaIsland_Home/scripts.pory"
	special DrawWholeMapView
# 1410 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_OPENED_CHEST
# 1411 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_PRECIOUS_BOLT
# 1413 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_Chest_5
# 1426 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1427 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1428 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Chest_Text_3
# 1431 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1432 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Chest_Text_4
# 1436 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1437 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
SpindaIsland_Home_EventScript_Chest_1:
# 1440 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Chest_2:
# 1390 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1391 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1392 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Chest_Text_0
# 1395 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1396 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
	goto SpindaIsland_Home_EventScript_Chest_1

SpindaIsland_Home_EventScript_Chest_5:
# 1414 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1415 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1416 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Chest_Text_2
# 1421 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1422 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1424 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_Chest_1


SpindaIsland_Home_CarBoy::
# 1444 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1445 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1446 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_BOY, EMOTE_NORMAL
# 1447 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarBoy_Text_0
# 1448 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarBoy_Text_1
# 1452 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1453 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1454 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1455 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1456 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_CarGirl::
# 1460 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1461 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_NICKEL, SpindaIsland_Home_CarGirl_2
# 1471 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_REPLACED_WHEEL, SpindaIsland_Home_CarGirl_3
# 1488 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_LOOKING_FOR_WHEEL_REPLACEMENT, SpindaIsland_Home_CarGirl_4
# 1498 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1499 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1500 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1501 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_4
# 1508 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1509 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1511 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_LOOKING_FOR_WHEEL_REPLACEMENT
SpindaIsland_Home_CarGirl_1:
# 1514 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1515 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1517 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_CarGirl_2:
# 1462 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1463 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1464 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1465 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_1
# 1468 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1469 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_CarGirl_1

SpindaIsland_Home_CarGirl_3:
# 1472 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1473 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1474 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1475 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_2
# 1483 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1484 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1486 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_RUSTY_NICKEL
# 1487 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_NICKEL
	goto SpindaIsland_Home_CarGirl_1

SpindaIsland_Home_CarGirl_4:
# 1489 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1490 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 1491 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1492 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_3
# 1495 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1496 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_CarGirl_1


SpindaIsland_Home_EventScript_MissingWheel::
# 1521 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1522 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_REPLACED_WHEEL, SpindaIsland_Home_EventScript_MissingWheel_2
# 1531 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1532 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1533 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MissingWheel_Text_1
# 1537 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1538 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_MissingWheel_1:
# 1540 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MissingWheel_2:
# 1523 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1524 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1525 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MissingWheel_Text_0
# 1528 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1529 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_MissingWheel_1


SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet::
# 1544 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1546 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_1
# 1577 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1578 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1579 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_2
# 1582 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1583 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	return

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_1:
# 1547 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1548 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1549 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_0
# 1552 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1553 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1555 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1557 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_CLICK
# 1558 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 27, 50, METATILE_SpindaIslandSecondary_FaucetWheel, TRUE
# 1559 "data/maps/SpindaIsland_Home/scripts.pory"
	special DrawWholeMapView
# 1560 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1562 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1564 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1565 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1566 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_1
# 1569 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1570 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1572 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_BROKEN_FAUCET
# 1573 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_REPLACED_WHEEL
# 1575 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_SurveyedWheel::
# 1588 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1589 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_SurveyedWheel_4
SpindaIsland_Home_EventScript_SurveyedWheel_3:
# 1647 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1648 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1649 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_0
# 1652 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1653 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_SurveyedWheel_1:
# 1655 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_SurveyedWheel_2:
# 1590 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1591 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1592 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_0
# 1595 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1596 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1597 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_1
# 1601 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
	checkitem ITEM_BORROWED_PLIERS
# 0 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_EventScript_SurveyedWheel_7
# 1639 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1640 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_6
# 1643 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1644 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SurveyedWheel_1

SpindaIsland_Home_EventScript_SurveyedWheel_4:
# 1589 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_FOUND_TOUGH_BOLT, SpindaIsland_Home_EventScript_SurveyedWheel_2
	goto SpindaIsland_Home_EventScript_SurveyedWheel_3

SpindaIsland_Home_EventScript_SurveyedWheel_7:
# 1604 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1605 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_2
# 1608 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1609 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1611 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 15, DIR_EAST
# 1612 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1613 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1614 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_3
# 1617 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1618 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1620 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1621 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1622 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_4
# 1625 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1626 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1628 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 15, DIR_NORTH
# 1629 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1631 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1632 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1633 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_5
# 1636 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1637 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SurveyedWheel_1


SpindaIsland_Home_EventScript_Raft::
# 1659 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1660 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1661 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1662 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Raft_Text_0
# 1666 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1667 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1668 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_ThisIsConvenient::
# 1672 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1674 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_BROKE, SpindaIsland_Home_EventScript_ThisIsConvenient_2
SpindaIsland_Home_EventScript_ThisIsConvenient_1:
# 1689 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_ThisIsConvenient_2:
# 1675 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 1676 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 20
# 1678 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1679 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1680 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ThisIsConvenient_Text_0
# 1683 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1684 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1686 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_PASSED_IN_FRONT_OF_FAUCET_SHOP, 1
	goto SpindaIsland_Home_EventScript_ThisIsConvenient_1


SpindaIsland_Home_EventScript_Pot::
# 1693 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1694 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SALTED_DISH, SpindaIsland_Home_EventScript_Pot_2
# 1703 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1704 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1705 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pot_Text_1
# 1708 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_DISGUSTED
# 1709 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pot_Text_2
# 1713 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1714 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Pot_1:
# 1716 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Pot_2:
# 1695 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1696 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1697 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pot_Text_0
# 1700 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1701 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Pot_1


SpindaIsland_Home_EventScript_SaltDish::
# 1720 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1721 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_SALTY_LEMONADE
# 1722 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SALTED_DISH
# 1723 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1724 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1725 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SaltDish_Text_0
# 1728 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1729 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1731 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_POISON_POWDER
# 1732 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1733 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_POISON_POWDER
# 1734 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1735 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_POISON_POWDER
# 1736 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1738 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1739 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1740 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SaltDish_Text_1
# 1743 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1744 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1746 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_FeedZiggy::
# 1750 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1751 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1752 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1753 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_FeedZiggy_2
# 1758 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_FeedZiggy_Text_1
SpindaIsland_Home_EventScript_FeedZiggy_1:
# 1762 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1763 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1764 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_FeedZiggy_2:
# 1754 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_FeedZiggy_Text_0
	goto SpindaIsland_Home_EventScript_FeedZiggy_1


SpindaIsland_Home_EventScript_Cook::
# 1768 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1769 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1771 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_GOT_OIL, SpindaIsland_Home_EventScript_Cook_2
# 1781 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SALTED_DISH, SpindaIsland_Home_EventScript_Cook_3
# 1833 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_SAD
# 1834 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1835 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_5
# 1841 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1842 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1844 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_COOK_SAD
SpindaIsland_Home_EventScript_Cook_1:
# 1847 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Cook_2:
# 1772 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_NORMAL
# 1773 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1774 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_1
# 1778 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1779 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Cook_1

SpindaIsland_Home_EventScript_Cook_3:
# 1782 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1783 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1784 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_2
# 1787 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1788 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1790 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_SAD
# 1791 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1792 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_3
# 1795 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1796 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1799 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 20
# 1801 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_SAD
# 1802 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1803 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pot_Text_1
# 1806 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1807 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1809 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 1810 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 1811 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1812 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1813 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1815 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_NORMAL
# 1816 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1817 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_4
# 1824 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1825 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1827 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_COOK_SAD
# 1828 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_GOT_OIL
# 1829 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_COOKING_OIL
# 1831 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_Cook_1


SpindaIsland_Home_EventScript_Zigzagoon::
# 1851 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1852 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_ZIGGY_ASLEEP, SpindaIsland_Home_EventScript_Zigzagoon_2
# 1861 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_ENCOUNTER
# 1862 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_TryToBlindZiggy_Text_0
# 1863 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Zigzagoon_Text_2
# 1866 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 1867 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Zigzagoon_1:
# 1869 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Zigzagoon_2:
# 1853 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_SNORE
# 1854 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Zigzagoon_Text_0
# 1855 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Zigzagoon_Text_1
# 1858 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1859 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Zigzagoon_1


SpindaIsland_Home_EventScript_Pliers::
# 1873 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1874 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_ZIGGY_ASLEEP, SpindaIsland_Home_EventScript_Pliers_2
# 1888 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SAW_PLIERS, SpindaIsland_Home_EventScript_Pliers_5
# 1898 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_Pliers_8
# 1928 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1929 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1930 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_5
SpindaIsland_Home_EventScript_Pliers_1:
# 1938 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Pliers_2:
# 1875 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject VAR_LAST_TALKED
# 1876 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_BORROWED_PLIERS
# 1877 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_PICKED_UP_PLIERS
# 1879 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_DISGUSTED
# 1880 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1881 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_0
# 1885 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1886 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Pliers_1

SpindaIsland_Home_EventScript_Pliers_5:
# 1889 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1890 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1891 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_1
# 1895 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1896 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Pliers_1

SpindaIsland_Home_EventScript_Pliers_8:
# 1899 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1900 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1901 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_2
# 1905 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1906 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_3
# 1909 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1910 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1912 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_ENCOUNTER
# 1913 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_TryToBlindZiggy_Text_0
# 1914 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Zigzagoon_Text_2
# 1917 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 1918 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1919 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1920 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_4
# 1923 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1924 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1926 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SAW_PLIERS
	goto SpindaIsland_Home_EventScript_Pliers_1


SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy::
# 1942 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1943 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
# 1944 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1946 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_ENCOUNTER
# 1947 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_TryToBlindZiggy_Text_0
# 1948 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_0
# 1951 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 1952 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1954 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 30
# 1956 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_FAINT
# 1957 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Zigzagoon_Text_0
# 1958 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_1
# 1961 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 1962 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_SNORE
# 1963 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_2
# 1966 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1968 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1969 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1970 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_3
# 1974 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1975 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1977 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_ZIGGY_ASLEEP
# 1978 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_UseGrassBladeWithMetapodBattle::
# 1982 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1983 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
# 1984 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1985 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1986 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1987 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1988 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_UseGrassBladeWithMetapodBattle_Text_0
# 1991 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1992 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1993 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_UseGrassBlade::
# 1997 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1998 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
# 1999 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 2000 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_BobsDoor::
# 2004 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 2005 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_BobsHouseSign_Text_0
# 2006 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsDoor_Text_0
# 2009 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 2010 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 2011 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsDoor_Text_1
# 2014 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 2015 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsDoor_Text_2
# 2018 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 2019 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 2020 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_CynthiasDoor::
# 2024 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 2025 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 2026 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 2027 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_CynthiasDoor_Text_0
# 2031 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 2032 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 2033 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_GiveWaterStoneToSlowbro::
# 2037 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 2038 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 2039 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 2040 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_GiveWaterStoneToSlowbro_Text_0
# 2043 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 2044 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 2045 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_TryToPhotographSunbather::
# 2049 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 2050 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_SUNBATHER, EMOTE_PENSIVE
# 2051 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Sunbather_Text_0
# 2052 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_TryToPhotographSunbather_Text_0
# 2056 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 2057 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 2058 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_TryToPhotographMetapod::
# 2062 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Common_UseToyCamera
# 2064 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 2066 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 2067 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 2068 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_TryToPhotographMetapod_Text_0
# 2071 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 2072 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 2074 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


# 2078 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_RaftGoesToIsland:
# 2079 "data/maps/SpindaIsland_Home/scripts.pory"
	face_left
# 2080 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 2081 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_anim
# 2082 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 2082 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 2082 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 2082 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 2082 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 2082 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 2082 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
	step_end

# 2085 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_PlayerEntersRaft:
# 2086 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 2087 "data/maps/SpindaIsland_Home/scripts.pory"
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
# 94 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Alright! The quicker mom gets her\n"
	.string "glass of {COLOR BLUE}WATER{COLOR DARK_GRAY}, the quicker Archie\l"
	.string "gets his super badass pirate {COLOR RED}sail{COLOR DARK_GRAY}!\p"
	.string "Let's get moving!$"

SpindaIsland_Home_EventScript_MainQuestRecap_Text_1:
# 99 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Alright! The quicker mom gets her\n"
	.string "glass of {COLOR BLUE}WATER{COLOR DARK_GRAY}, the quicker Archie\l"
	.string "gets his super badass pirate {COLOR RED}sail{COLOR DARK_GRAY}!\p"
	.string "It's the perfect occasion for Spinda\n"
	.string "and I to practice her new trick with L\l"
	.string "and R!\p"
	.string "Let's get moving!$"

SpindaIsland_Home_EventScript_MainQuestRecap_Text_2:
# 106 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Alright! The quicker mom gets her\n"
	.string "glass of {COLOR BLUE}WATER{COLOR DARK_GRAY}, the quicker Archie\l"
	.string "gets his super badass pirate {COLOR RED}sail{COLOR DARK_GRAY}!$"

SpindaIsland_Home_EventScript_MainQuestRecap_Text_3:
# 110 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ah, shoot, I forgot to take Spinda's\n"
	.string "Pokéball!\p"
	.string "I should take her for a walk so we can\n"
	.string "practice her new trick with L and R!$"

SpindaIsland_Home_EventScript_ArchiesHouseSign_Text_0:
# 130 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The Hoenns$"

SpindaIsland_TryToBlindZiggy_Text_0:
# 146 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Rabid Zigzagoon$"

SpindaIsland_TryToBlindZiggy_Text_1:
# 147 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "GrrrRRRRRHHH!!!!$"

SpindaIsland_TryToBlindZiggy_Text_2:
# 151 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "He looks even angrier now!$"

SpindaIsland_Home_EventScript_BobsHouseSign_Text_0:
# 158 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Mindy$"

SpindaIsland_Home_EventScript_CynthiasHouseSign_Text_0:
# 162 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Cynthia$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_0:
# 171 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Door's locked.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_1:
# 180 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I guess I should leave him alone now.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_2:
# 188 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hello? Are you there?$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_3:
# 193 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Stingy man$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_4:
# 195 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…\p"
	.string "My GOD you're annoying.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_5:
# 214 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here's your reward. I hope you're\n"
	.string "happy.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_6:
# 233 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "An old and rusty bolt? What am I\n"
	.string "supposed to do with this?$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_7:
# 249 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A {COLOR RED}bolt{COLOR DARK_GRAY}! Of course! Lucky me!\p"
	.string "I'm one step closer to getting that\n"
	.string "sweet sweet faucet replacement!!$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_8:
# 255 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(Did I really say that? Is this how\n"
	.string "being a grownup feels like?)$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_9:
# 265 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A bolt?\p"
	.string "It's all rusty…\p"
	.string "Guess it'll join my useless trash\n"
	.string "collection!$"

SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_0:
# 281 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sad man$"

SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_1:
# 283 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Curse the architect that built my\n"
	.string "house facing the wrong direction!!\p"
	.string "I can never go home!$"

SpindaIsland_Home_EventScript_Dad_Text_0:
# 295 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Dad$"

SpindaIsland_Home_EventScript_Dad_Text_1:
# 297 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't uh, pour that lemonade I gave\n"
	.string "you on the ground or anything.\p"
	.string "It'd probably kill all the grass and\n"
	.string "flowers.$"

SpindaIsland_Home_EventScript_Dad_Text_2:
# 307 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here, have some lemonade!$"

SpindaIsland_Home_EventScript_Dad_Text_3:
# 315 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hiya, sonny! going adventuring today,\n"
	.string "are we?\p"
	.string "Want some lemonade?$"

SpindaIsland_Home_EventScript_Dad_Text_4:
# 328 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Now we're talkin'!! I can bring this to\n"
	.string "mom, that should do it!\p"
	.string "Let's take a sip first, I am PARCHED!$"

SpindaIsland_Home_EventScript_Dad_Text_5:
# 352 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "BLEARGH!\p"
	.string "Why is it… so salty?!$"

SpindaIsland_Home_EventScript_Dad_Text_6:
# 361 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Why, because it's seawater, obviously!$"

SpindaIsland_Home_EventScript_Dad_Text_7:
# 366 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I take it you're not a fan of my\n"
	.string "recipe?$"

SpindaIsland_Home_EventScript_Dad_Text_8:
# 371 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(You wouldn't be the only one…)$"

SpindaIsland_Home_EventScript_Dad_Text_9:
# 376 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "In any case, it's nice of you to come\n"
	.string "visit me at the office, haha!\p"
	.string "See you around, little Archie! Don't\n"
	.string "get into trouble!$"

SpindaIsland_Home_EventScript_Dad_FromSide_Text_0:
# 405 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Come round to the front of the\n"
	.string "lemonade stand!$"

SpindaIsland_Home_EventScript_Dad_FromSide_Text_1:
# 413 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hiya, sonny! going adventuring today,\n"
	.string "are we?\p"
	.string "Want some lemonade?\p"
	.string "Come round to the front of the\n"
	.string "lemonade stand!$"

SpindaIsland_Home_EventScript_LemonadeStandSign_Text_0:
# 427 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "“ARCHIE'S LEMONADE\n"
	.string "A taste of the seaside!”$"

SpindaIsland_Home_EventScript_MainStreetSign_Text_0:
# 434 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "{UP_ARROW} Main street$"

SpindaIsland_Home_EventScript_MadelineSign_Text_0:
# 440 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bertha$"

SpindaIsland_Home_EventScript_PoemGirl_Text_0:
# 450 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Maggie$"

SpindaIsland_Home_EventScript_PoemGirl_Text_1:
# 452 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "See you around, Archie…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_2:
# 469 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Archie…\p"
	.string "I want to hear a poem…\p"
	.string "I want you to reveal your heart to me.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_3:
# 483 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ocean waves swimming…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_4:
# 484 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Roses are red…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_5:
# 485 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Roses are blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_6:
# 497 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "From the center of the sea…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_7:
# 498 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "They are calling to my heart…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_8:
# 510 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "With faith to reach land.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_9:
# 511 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Only to go back.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_10:
# 521 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And my heart to theirs.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_11:
# 522 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yearning for a touch.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_12:
# 529 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "That was very beautiful.\p"
	.string "I'm not really into haiku, though.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_13:
# 542 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Violets are blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_14:
# 543 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Just like our love…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_15:
# 555 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The sky is pretty…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_16:
# 556 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The Pincurchin are spiky…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_17:
# 569 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And so are you.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_18:
# 570 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And so are you!$"

SpindaIsland_Home_EventScript_PoemGirl_Text_19:
# 576 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, that's nice.\p"
	.string "You're not truly revealing your poet's\n"
	.string "heart, though.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_20:
# 598 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "That's… a weird comparison.\p"
	.string "I thought you were a better poet\n"
	.string "than that.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_21:
# 614 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Which blooms like they do.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_22:
# 615 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wait, I didn't mean to say that.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_23:
# 621 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wow, Archie, uh…\p"
	.string "That's not really what I meant when I\n"
	.string "said you should reveal your heart.\p"
	.string "(Well, this is awkward.)\p"
	.string "(Let's pretend this never happened.)$"

SpindaIsland_Home_EventScript_PoemGirl_Text_24:
# 637 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Violets are red…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_25:
# 651 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The sky isn't blue, it's purple instead.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_26:
# 652 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Doesn't make sense, but fun to be said.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_27:
# 658 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmm…\p"
	.string "You're not revealing your heart right\n"
	.string "now.\p"
	.string "Plus, that didn't make any sense.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_28:
# 674 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Orchids are blue, too.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_29:
# 675 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Everything is blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_30:
# 697 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Because it's my favorite color.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_31:
# 702 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "… … … … …\p"
	.string "Wow, Archie, I…\p"
	.string "This was so touching…\p"
	.string "Thank you for revealing your heart to\n"
	.string "me like this.\p"
	.string "Here, take this.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_32:
# 716 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "It's a blade of grass large enough to\n"
	.string "whistle with.\p"
	.string "Just don't listen to it too\n"
	.string "attentively, you might get sleepy.$"

SpindaIsland_Home_CheckSunbatherFlags_Text_0:
# 762 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(How am I blocking the sun from all\n"
	.string "four directions at once…?)$"

SpindaIsland_Home_Sunbather_Text_0:
# 777 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sunbather$"

SpindaIsland_Home_Sunbather_Text_1:
# 779 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ahh, it sure feels good to be sitting\n"
	.string "in the sun surrounded by all this\l"
	.string "{COLOR BLUE}WATER{COLOR DARK_GRAY}…\p"
	.string "…$"

SpindaIsland_Home_Sunbather_Text_2:
# 792 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Could you leave? You're blocking the\n"
	.string "sun.$"

SpindaIsland_Home_EventScript_HearTheSea_Text_0:
# 805 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "… … … …$"

SpindaIsland_Home_EventScript_HearTheSea_Text_1:
# 809 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I can hear the sea!$"

SpindaIsland_Home_Slowpoke_Text_0:
# 821 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slowbro$"

SpindaIsland_Home_Slowpoke_Text_1:
# 823 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bruh…$"

SpindaIsland_Home_Slowpoke_Text_2:
# 831 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slowpoke$"

SpindaIsland_Home_Slowpoke_Text_3:
# 833 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slo…$"

SpindaIsland_Home_Slowpoke_Text_4:
# 842 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "… … …?\p"
	.string "He's looking at the white seashell I\n"
	.string "found…$"

SpindaIsland_Home_Slowpoke_Text_5:
# 853 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Give the seashell$"

SpindaIsland_Home_Slowpoke_Text_6:
# 854 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't give the seashell$"

SpindaIsland_Home_Slowpoke_Text_7:
# 864 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sure, why the hell not!\p"
	.string "Here you go, buddy.$"

SpindaIsland_Home_Slowpoke_Text_8:
# 886 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bruh!!$"

SpindaIsland_Home_Slowpoke_Text_9:
# 894 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The heck?!\p"
	.string "My seashell bit him!$"

SpindaIsland_Home_Slowpoke_Text_10:
# 900 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Guess it was a Shellder all this time!$"

SpindaIsland_Home_Slowpoke_Text_11:
# 910 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…Slo…\p"
	.string ":($"

SpindaIsland_Home_EventScript_Metapod_Text_0:
# 924 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod$"

SpindaIsland_Home_EventScript_Metapod_Text_1:
# 927 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0:
# 937 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Twin$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_1:
# 939 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "What is it?!$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_2:
# 944 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, I guess we are blocking the stairs\n"
	.string "a little…\p"
	.string "Fine, we'll take our epic battle\n"
	.string "somewhere else.$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_0:
# 966 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "On god why you gotta bust my balls\n"
	.string "like that fr?!$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_1:
# 971 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yikes, we lowkey do be blockin the\n"
	.string "stairs rn no cap…\p"
	.string "Aight word word, we gon vibe\n"
	.string "somewhere else.$"

SpindaIsland_Home_EventScript_MetapodBoy_Text_0:
# 997 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm SO CLOSE to tasting that sweet,\n"
	.string "sweet victory!$"

SpindaIsland_Home_EventScript_MetapodBoy_Text_1:
# 1007 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't you see we're in the midst of a\n"
	.string "fiery battle?$"

SpindaIsland_Home_EventScript_MetapodBoy_Text_2:
# 1017 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod, use harden!!$"

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_0:
# 1038 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm deadass SO CLOSE to catchin that\n"
	.string "bussin drip fr!$"

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_1:
# 1048 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't you see we tryna catch some\n"
	.string "real heat rn bro? Sheesh!$"

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_2:
# 1058 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod, keep hittin that mid boi with\n"
	.string "harden, chief!!$"

SpindaIsland_Home_PhotoCameraWrongDir_Text_0:
# 1076 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't use that from this side.$"

SpindaIsland_Home_EventScript_FaucetShopSign_Text_0:
# 1085 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "“FAUCET WORKSHOP\n"
	.string "For all your faucet needs!\l"
	.string "WE ARE OPEN!!”$"

SpindaIsland_Home_SlowpokeMistress_Text_0:
# 1135 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Girl$"

SpindaIsland_Home_SlowpokeMistress_Text_1:
# 1137 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Look at my super cool Slowbro!\p"
	.string "He just looks so happy!$"

SpindaIsland_Home_SlowpokeMistress_Text_2:
# 1152 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "By Arceus!!\p"
	.string "How on earth did you convince my\n"
	.string "Slowpoke to evolve?$"

SpindaIsland_Home_SlowpokeMistress_Text_3:
# 1158 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…A cool-looking seashell? What are\n"
	.string "you talking about?$"

SpindaIsland_Home_SlowpokeMistress_Text_4:
# 1163 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Well, thank you anyway! You can have\n"
	.string "this!$"

SpindaIsland_Home_SlowpokeMistress_Text_5:
# 1168 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I no longer need it.$"

SpindaIsland_Home_SlowpokeMistress_Text_6:
# 1178 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmm… A {COLOR BLUE}WATER{COLOR DARK_GRAY} Stone…\p"
	.string "There's {COLOR BLUE}WATER{COLOR DARK_GRAY} in the name!\p"
	.string "Maybe I could try giving this to mom?\p"
	.string "(Flawless logic.)$"

SpindaIsland_Home_SlowpokeMistress_Text_7:
# 1191 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I wish my Pokémon would evolve…$"

SpindaIsland_Home_SlowpokeMistress_Text_8:
# 1196 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I keep trying to give him this {COLOR BLUE}WATER{COLOR DARK_GRAY}\n"
	.string "Stone, but it just does nothing.\p"
	.string "Perhaps there's another way…$"

SpindaIsland_Home_EventScript_Juan_Text_0:
# 1209 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Juan$"

SpindaIsland_Home_EventScript_Juan_Text_1:
# 1212 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey, wanna hear more interesting\n"
	.string "facts about Pokémon?$"

SpindaIsland_Home_EventScript_Juan_Text_2:
# 1222 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Nope$"

SpindaIsland_Home_EventScript_Juan_Text_3:
# 1223 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "No thanks$"

SpindaIsland_Home_EventScript_Juan_Text_4:
# 1228 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bummer! Come back whenever, I have\n"
	.string "plenty!$"

SpindaIsland_Home_EventScript_Juan_Text_5:
# 1235 "data/maps/SpindaIsland_Home/scripts.pory"
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
# 1247 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh boy, what a find! I need to write\n"
	.string "this discovery down in my PokéDex!!$"

SpindaIsland_Home_EventScript_Machoke_Text_0:
# 1262 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sexy Machoke$"

SpindaIsland_Home_EventScript_Machoke_Text_1:
# 1264 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Machoke$"

SpindaIsland_Home_EventScript_Machoke_Text_2:
# 1267 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmmm…$"

SpindaIsland_Home_EventScript_Lisa_Text_0:
# 1278 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Lisa$"

SpindaIsland_Home_EventScript_Lisa_Text_1:
# 1280 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey Archie! Cool Spinda!\p"
	.string "Heard you were building a sick pirate\n"
	.string "ship!$"

SpindaIsland_Home_EventScript_OldWoman_Text_0:
# 1294 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Old woman$"

SpindaIsland_Home_EventScript_OldWoman_Text_1:
# 1296 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I think my house is haunted. There's\n"
	.string "something living in my attic.\p"
	.string "I don't know what to do…$"

SpindaIsland_Home_EventScript_OldWoman_Text_2:
# 1307 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, I'm too scared to go back inside…$"

SpindaIsland_Home_EventScript_OldWoman_Text_3:
# 1325 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't worry granny! There were some\n"
	.string "Shuppet in your attic, but I chased\l"
	.string "them away!$"

SpindaIsland_Home_EventScript_OldWoman_Text_4:
# 1333 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Shuppet, you say?$"

SpindaIsland_Home_EventScript_OldWoman_Text_5:
# 1337 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "How adorable of you to help out a poor\n"
	.string "old lady…\p"
	.string "How can I repay you?\p"
	.string "You look like you're hungry… Let me\n"
	.string "fix you a little snack!$"

SpindaIsland_Home_EventScript_OldWoman_Text_6:
# 1348 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Have a good day, child.$"

SpindaIsland_Home_EventScript_OldWoman_Text_7:
# 1362 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Cool! Lemme pack this up for later.\p"
	.string "Let's hope it doesn't taste like old\n"
	.string "people or something.$"

SpindaIsland_Home_EventScript_OldWomansDoor_Text_0:
# 1379 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm glad I was able to help!$"

SpindaIsland_Home_EventScript_Chest_Text_0:
# 1393 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Already opened it!$"

SpindaIsland_Home_EventScript_Chest_Text_1:
# 1401 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Woah, a treasure chest?!\p"
	.string "Wonder who put it here!$"

SpindaIsland_Home_EventScript_Chest_Text_2:
# 1417 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A {COLOR RED}bolt{COLOR DARK_GRAY}!!\p"
	.string "And it's gold, too!\p"
	.string "How lucky!$"

SpindaIsland_Home_EventScript_Chest_Text_3:
# 1429 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A gold coin?!$"

SpindaIsland_Home_EventScript_Chest_Text_4:
# 1433 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ah, no, it's a {COLOR RED}bolt{COLOR DARK_GRAY}.\p"
	.string "Weird, I wonder who put it here.$"

SpindaIsland_Home_CarBoy_Text_0:
# 1447 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Rudy$"

SpindaIsland_Home_CarBoy_Text_1:
# 1449 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "MY role is to TIGHTEN the bolts on\n"
	.string "EACH AND EVERY WHEEL!!\p"
	.string "Vrrrbbbbbmmmmmmm!!!!!$"

SpindaIsland_Home_CarGirl_Text_0:
# 1464 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Katie$"

SpindaIsland_Home_CarGirl_Text_1:
# 1466 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Thanks a bunch!$"

SpindaIsland_Home_CarGirl_Text_2:
# 1476 "data/maps/SpindaIsland_Home/scripts.pory"
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
# 1493 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Now what could we use as a wheel…$"

SpindaIsland_Home_CarGirl_Text_4:
# 1502 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey Archie!\p"
	.string "As you can see we're almost done with\n"
	.string "our monster car.\p"
	.string "We're just missing one last wheel!\p"
	.string "We don't really need it to be an actual\n"
	.string "wheel, either.\p"
	.string "Anything round and spinny would do!$"

SpindaIsland_Home_EventScript_MissingWheel_Text_0:
# 1526 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A shiny new wheel!$"

SpindaIsland_Home_EventScript_MissingWheel_Text_1:
# 1534 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A wheel is missing.\p"
	.string "I'm sure I could find a replacement.$"

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_0:
# 1550 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "What if…$"

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_1:
# 1567 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Fits perfectly! There ya go!$"

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_2:
# 1580 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "This'd be perfect, but I need to\n"
	.string "repair it!$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_0:
# 1593 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Just a regular wheel.$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_1:
# 1598 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wait, it's stuck to the car with bolts!\p"
	.string "If I could just take one…$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_2:
# 1606 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here, let me just…$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_3:
# 1615 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Whatcha doing, Archie?$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_4:
# 1623 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ah, uh, nothing!$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_5:
# 1634 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(Darn, can't do this right under her\n"
	.string "nose.)$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_6:
# 1641 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'd need some pliers to get it out.$"

SpindaIsland_Home_EventScript_Raft_Text_0:
# 1663 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "My super-awesome pirate ship!\p"
	.string "Only thing missing is the sail.$"

SpindaIsland_Home_EventScript_ThisIsConvenient_Text_0:
# 1681 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Well, this is eerily convenient!$"

SpindaIsland_Home_EventScript_Pot_Text_0:
# 1698 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Much better!$"

SpindaIsland_Home_EventScript_Pot_Text_1:
# 1706 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slurp…$"

SpindaIsland_Home_EventScript_Pot_Text_2:
# 1710 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ugh, it's tasteless…\p"
	.string "Have people never heard of salt?$"

SpindaIsland_Home_EventScript_SaltDish_Text_0:
# 1726 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Needs some salt, so maybe…$"

SpindaIsland_Home_EventScript_SaltDish_Text_1:
# 1741 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "There, fixed, probably!$"

SpindaIsland_Home_EventScript_FeedZiggy_Text_0:
# 1755 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Good idea, except I need this\n"
	.string "sandwich for the faucet salesman!$"

SpindaIsland_Home_EventScript_FeedZiggy_Text_1:
# 1759 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'd be afraid of this one biting off my\n"
	.string "hand!$"

SpindaIsland_Home_EventScript_Cook_Text_0:
# 1773 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Cook$"

SpindaIsland_Home_EventScript_Cook_Text_1:
# 1775 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Thank you again.\p"
	.string "You will become a great chef when you\n"
	.string "grow up, I can feel it!$"

SpindaIsland_Home_EventScript_Cook_Text_2:
# 1785 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can you try your dish now?$"

SpindaIsland_Home_EventScript_Cook_Text_3:
# 1793 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "It's not like it's gotten any tastier\n"
	.string "on its own, but sure.$"

SpindaIsland_Home_EventScript_Cook_Text_4:
# 1818 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, wow! It's… It's remarkable!!\p"
	.string "What arcane sorcery…\p"
	.string "What? You added some lemonade in the\n"
	.string "pot?\p"
	.string "Who would have thought!!\p"
	.string "I don't have much to thank you, but\n"
	.string "here is a bottle of my finest cooking\l"
	.string "oil!$"

SpindaIsland_Home_EventScript_Cook_Text_5:
# 1836 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I am distraught.\p"
	.string "My dish isn't turning out how I wanted\n"
	.string "at all…\p"
	.string "How can I make it less… flavorless?\p"
	.string "Is there any hope at all?$"

SpindaIsland_Home_EventScript_Zigzagoon_Text_0:
# 1854 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sleepy Zigzagoon$"

SpindaIsland_Home_EventScript_Zigzagoon_Text_1:
# 1856 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "ZzzzzZzZz…$"

SpindaIsland_Home_EventScript_Zigzagoon_Text_2:
# 1864 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "GRRRRRRRR…$"

SpindaIsland_Home_EventScript_Pliers_Text_0:
# 1882 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yuck, the Zigzagoon drooled all over\n"
	.string "them!\p"
	.string "At least I hope it's drool…$"

SpindaIsland_Home_EventScript_Pliers_Text_1:
# 1892 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't get to those {COLOR RED}pliers{COLOR DARK_GRAY} with that\n"
	.string "Zigzagoon guarding them…\p"
	.string "If only there was a way to distract or\n"
	.string "incapacitate it…$"

SpindaIsland_Home_EventScript_Pliers_Text_2:
# 1902 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "These must be the {COLOR RED}pliers{COLOR DARK_GRAY} the faucet\n"
	.string "salesman was talking about!$"

SpindaIsland_Home_EventScript_Pliers_Text_3:
# 1907 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "You're gonna give them to me, right\n"
	.string "little Ziggy?$"

SpindaIsland_Home_EventScript_Pliers_Text_4:
# 1921 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Nope, not gonna risk a hand just to\n"
	.string "get these!$"

SpindaIsland_Home_EventScript_Pliers_Text_5:
# 1931 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Is this… a pair of {COLOR RED}pliers{COLOR DARK_GRAY}?\p"
	.string "I wonder what a Zigzagoon would use\n"
	.string "these for.$"

SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_0:
# 1949 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "GRRRRRRRR!!$"

SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_1:
# 1959 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…GrrrzzZZzzzzZz…$"

SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_2:
# 1964 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "ZzzzZzZzzZZzzz…$"

SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_3:
# 1971 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Awesome! It fell asleep!\p"
	.string "Let's get those {COLOR RED}pliers{COLOR DARK_GRAY}!$"

SpindaIsland_Home_EventScript_UseGrassBladeWithMetapodBattle_Text_0:
# 1989 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "They're too focused on their battle\n"
	.string "to even listen!$"

SpindaIsland_Home_EventScript_BobsDoor_Text_0:
# 2007 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey Archie! Wanna come in for a\n"
	.string "Pokémon trade?$"

SpindaIsland_Home_EventScript_BobsDoor_Text_1:
# 2012 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't today, I'm busy!$"

SpindaIsland_Home_EventScript_BobsDoor_Text_2:
# 2016 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(Never again.)$"

SpindaIsland_Home_EventScript_CynthiasDoor_Text_0:
# 2028 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I ain't going in there unprepared.\p"
	.string "Or at all.$"

SpindaIsland_Home_EventScript_GiveWaterStoneToSlowbro_Text_0:
# 2041 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "He's already evolved!$"

SpindaIsland_TryToPhotographSunbather_Text_0:
# 2053 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Are you kidding me?\p"
	.string "Stop taking pictures, you little\n"
	.string "creep!$"

SpindaIsland_TryToPhotographMetapod_Text_0:
# 2069 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Go away!!$"

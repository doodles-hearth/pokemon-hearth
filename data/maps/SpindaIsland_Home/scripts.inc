SpindaIsland_Home_MapScripts::
# 7 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 14 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD
# 25 "data/maps/SpindaIsland_Home/scripts.pory"
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
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_4
	return

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 17 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 27, 50, METATILE_SpindaIslandSecondary_FaucetWheel, TRUE
	goto SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_1

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_LOAD_4:
# 21 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 14, 27, METATILE_SpindaIsland_Grass, FALSE
# 22 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 14, 28, METATILE_SpindaIslandSecondary_RoofProfileTopRightCorner, FALSE
	return

SpindaIsland_Home_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 26 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script_2 VAR_SPINDA_ISLAND_INTRO_STATE, 2, SpindaIsland_Home_EventScript_MainQuestRecap
# 27 "data/maps/SpindaIsland_Home/scripts.pory"
	map_script_2 VAR_REPAIRED_FAUCET, 2, SpindaIsland_Home_EventScript_GoToSail
	.2byte 0


SpindaIsland_Home_EventScript_GoToSail::
# 32 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 33 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_REPAIRED_FAUCET, 3
# 34 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Movement_GoToSail
# 35 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 37 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 38 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 39 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_GoToSail_Text_1
# 42 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 43 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 45 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_FU_ZAKU
# 46 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 21, DIR_SOUTH
# 47 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_BADASS_SAIL
# 48 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 50 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 52 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 53 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 54 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_GoToSail_Text_2
# 57 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 58 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_GoToSail_Text_3
# 62 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 63 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 65 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Movement_PlayerEntersRaft
# 66 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 68 "data/maps/SpindaIsland_Home/scripts.pory"
	special SpawnCameraObject
# 69 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, SpindaIsland_Home_Movement_RaftGoesToIsland
# 70 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SpindaIsland_Home_Movement_RaftGoesToIsland
# 71 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 100
# 72 "data/maps/SpindaIsland_Home/scripts.pory"
	warpsilent MAP_SPINDA_ISLAND_SHUPPET_HOUSE_ATTIC, 5, 0
# 74 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


# 77 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_GoToSail:
# 78 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_down
# 78 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_down
# 78 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_down
# 78 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_down
# 78 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_down
# 79 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_right
# 79 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_right
# 79 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_right
# 79 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_right
# 79 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_right
# 80 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_down
# 80 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_down
# 80 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_fast_down
	step_end

SpindaIsland_Home_EventScript_MainQuestRecap::
# 84 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 85 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 86 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 87 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MainQuestRecap_Text_0
# 91 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 92 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 93 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 3
# 94 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodOtherSide::
# 98 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 99 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_METAPOD_OTHER_SIDE, 1
# 100 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_ArchiesHouseSign::
# 104 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ArchiesHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_BobsHouseSign::
# 108 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_CynthiasHouseSign::
# 112 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_CynthiasHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_SadManHome_Back::
# 116 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 117 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_HIDE_MAN_CANT_GO_HOME, SpindaIsland_Home_EventScript_SadManHome_Back_2
# 126 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_RUSTY_BOLT, SpindaIsland_Home_EventScript_SadManHome_Back_5
# 135 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 136 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 137 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_2
# 140 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 141 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 143 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_SadManHome_Back_Text_3
# 144 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_4
# 148 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 150 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 152 "data/maps/SpindaIsland_Home/scripts.pory"
	clearflag FLAG_HIDE_MAN_CANT_GO_HOME
# 153 "data/maps/SpindaIsland_Home/scripts.pory"
	setobjectxyperm 6, 42, 24
# 154 "data/maps/SpindaIsland_Home/scripts.pory"
	addobject 6
# 155 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement 6, SpindaIsland_Home_Movement_SadManExitsHouse
# 156 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Movement_PlayerMakesWay
# 157 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 158 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 6
# 159 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 160 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 161 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 162 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_SadManHome_Back_Text_3
# 163 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_5
# 166 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 167 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 168 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_RUSTY_BOLT
# 169 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_RUSTY_BOLT
# 170 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement 6, SpindaIsland_Home_Movement_SadManReEntersHouse
# 171 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 172 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 173 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 6
# 174 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_MAN_CANT_GO_HOME
# 175 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 177 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 179 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_SadManHome_Back_8
# 212 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 213 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 214 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_9
# 219 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 220 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_SadManHome_Back_1:
# 224 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_SadManHome_Back_2:
# 118 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 119 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 120 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_0
# 123 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 124 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1

SpindaIsland_Home_EventScript_SadManHome_Back_5:
# 127 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 128 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 129 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_1
# 132 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 133 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1

SpindaIsland_Home_EventScript_SadManHome_Back_8:
# 180 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 181 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 182 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_6
# 185 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 186 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 188 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 190 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 191 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 192 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 193 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 194 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 196 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 197 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 198 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_7
# 202 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 203 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 204 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SadManHome_Back_Text_8
# 207 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 208 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 210 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_SadManHome_Back_1


SpindaIsland_Home_EventScript_ICanNeverGoHome::
# 228 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 229 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 230 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SAD
# 231 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_0
# 232 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_1, MSGBOX_NPC
# 236 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 237 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_Dad::
# 241 "data/maps/SpindaIsland_Home/scripts.pory"
	lockall
# 242 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 7, DIR_SOUTH
# 243 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OBTAINED_LEMONADE, SpindaIsland_Home_EventScript_Dad_2
# 253 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SPOKE_TO_DAD, SpindaIsland_Home_EventScript_Dad_6
# 262 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 263 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 264 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_3
# 268 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 269 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Dad_5:
# 272 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_SALTY_LEMONADE
# 274 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 275 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 276 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 277 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_4
# 281 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 282 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 284 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 10
# 285 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 286 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 287 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 288 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 289 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_BALL
# 290 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 291 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 20
# 293 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 294 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 295 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 296 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 297 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 299 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_DISGUSTED
# 300 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 301 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_5
# 305 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 306 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 308 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_GRINNING
# 309 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 310 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_6
# 313 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 314 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 315 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_7
# 318 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 319 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_EMBARRASSED
# 320 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_8
# 323 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 324 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 325 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_9
# 329 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 330 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 332 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_OBTAINED_LEMONADE
# 333 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SPOKE_TO_DAD
SpindaIsland_Home_EventScript_Dad_1:
# 335 "data/maps/SpindaIsland_Home/scripts.pory"
	releaseall
	return

SpindaIsland_Home_EventScript_Dad_2:
# 244 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_EMBARRASSED
# 245 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 246 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_1
# 250 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 251 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_1

SpindaIsland_Home_EventScript_Dad_6:
# 254 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 255 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 256 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_2
# 259 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 260 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_5


SpindaIsland_Home_EventScript_Dad_FromSide::
# 339 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 340 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 341 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OBTAINED_LEMONADE, SpindaIsland_Home_EventScript_Dad_FromSide_2
# 351 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SPOKE_TO_DAD, SpindaIsland_Home_EventScript_Dad_FromSide_6
# 360 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_HAPPY
# 361 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 362 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_FromSide_Text_1
# 367 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 368 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Dad_FromSide_5:
# 370 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SPOKE_TO_DAD
SpindaIsland_Home_EventScript_Dad_FromSide_1:
# 372 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Dad_FromSide_2:
# 342 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_EMBARRASSED
# 343 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 344 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_1
# 348 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 349 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_FromSide_1

SpindaIsland_Home_EventScript_Dad_FromSide_6:
# 352 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_DAD, EMOTE_NORMAL
# 353 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 354 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_FromSide_Text_0
# 357 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 358 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_FromSide_5


SpindaIsland_Home_EventScript_LemonadeStandSign::
# 376 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_LemonadeStandSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_MainStreetSign::
# 383 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MainStreetSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_MadelineSign::
# 389 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MadelineSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_PoemGirl::
# 395 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 397 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_POEM_GIRL, SpindaIsland_Home_EventScript_PoemGirl_2
# 411 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
# 412 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 414 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 416 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 417 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 418 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_2
# 423 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 424 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 426 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_3, SpindaIsland_Home_EventScript_PoemGirl_Text_4, SpindaIsland_Home_EventScript_PoemGirl_Text_5
# 438 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 439 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_6
# 484 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_7
# 579 "data/maps/SpindaIsland_Home/scripts.pory"
	case 2, SpindaIsland_Home_EventScript_PoemGirl_8
SpindaIsland_Home_EventScript_PoemGirl_1:
# 677 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 678 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 679 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_PoemGirl_2:
# 398 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 399 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 400 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 401 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_1
# 404 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 405 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 407 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 408 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 409 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_6:
# 440 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_6, SpindaIsland_Home_EventScript_PoemGirl_Text_7
# 451 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 452 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_11
# 463 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_12
SpindaIsland_Home_EventScript_PoemGirl_9:
# 476 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 477 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 478 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_12
# 482 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 483 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_7:
# 485 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_13, SpindaIsland_Home_EventScript_PoemGirl_Text_14
# 495 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 497 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_14
# 556 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_15
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_8:
# 580 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_24, SpindaIsland_Home_EventScript_PoemGirl_Text_13
# 591 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 593 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_17
# 616 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_18
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_11:
# 453 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_8, SpindaIsland_Home_EventScript_PoemGirl_Text_9
	goto SpindaIsland_Home_EventScript_PoemGirl_9

SpindaIsland_Home_EventScript_PoemGirl_12:
# 464 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_10, SpindaIsland_Home_EventScript_PoemGirl_Text_11
	goto SpindaIsland_Home_EventScript_PoemGirl_9

SpindaIsland_Home_EventScript_PoemGirl_14:
# 498 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_15, SpindaIsland_Home_EventScript_PoemGirl_Text_16
# 509 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 511 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_20
# 533 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_21
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_15:
# 557 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_21, SpindaIsland_Home_EventScript_PoemGirl_Text_22
# 568 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 569 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 570 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_23
# 576 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 577 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_17:
# 594 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_25, SpindaIsland_Home_EventScript_PoemGirl_Text_26
# 605 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 606 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 607 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_27
# 612 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 613 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_18:
# 617 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_28, SpindaIsland_Home_EventScript_PoemGirl_Text_29
# 628 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 629 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_23
# 639 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_24
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_20:
# 512 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_17, SpindaIsland_Home_EventScript_PoemGirl_Text_18
# 523 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 524 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 525 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_19
# 529 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 530 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_21:
# 534 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_17, SpindaIsland_Home_EventScript_PoemGirl_Text_18
# 545 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 546 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 547 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_20
# 551 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 552 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_23:
# 630 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 631 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 632 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_27
# 637 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 638 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_24:
# 640 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_30
# 649 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 650 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 651 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_31
# 658 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 659 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 661 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_GRASS_BLADE
# 663 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 664 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 665 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_32
# 669 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 670 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 672 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_POEM_GIRL
	goto SpindaIsland_Home_EventScript_PoemGirl_1


SpindaIsland_Home_EventScript_Sunbather::
# 683 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 684 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_SUNBATHER, EMOTE_NORMAL
# 685 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Sunbather_Text_0
# 686 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Sunbather_Text_1
# 690 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 691 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 692 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 693 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 695 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_SUNBATHER, EMOTE_PENSIVE
# 696 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Sunbather_Text_0
# 697 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Sunbather_Text_2
# 700 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 701 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 702 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 703 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 704 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_Slowpoke::
# 708 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 709 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_Slowpoke_2
# 720 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 721 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
# 722 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_2
# 723 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_3
# 726 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 727 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	checkitem ITEM_WHITE_SEASHELL
# 0 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq SpindaIsland_Home_Slowpoke_5
SpindaIsland_Home_Slowpoke_1:
# 810 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_Slowpoke_2:
# 710 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 711 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
# 712 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_0
# 713 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_1
# 716 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 717 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_5:
# 730 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 731 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 732 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_4
# 737 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Slowpoke_Text_5, SpindaIsland_Home_Slowpoke_Text_6
# 747 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 748 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 750 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 751 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_Slowpoke_8
# 797 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_Slowpoke_9
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_8:
# 752 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 753 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 754 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_7
# 758 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 759 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 761 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_WHITE_SEASHELL
# 763 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWBRO )
# 764 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SHELLDER, CRY_MODE_NORMAL
# 765 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 766 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject VAR_LAST_TALKED
# 767 "data/maps/SpindaIsland_Home/scripts.pory"
	addobject VAR_LAST_TALKED
# 768 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_BITE
# 769 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, SpindaIsland_Home_Movement_Slowpoke
# 770 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 771 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement VAR_LAST_TALKED
# 772 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 774 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
# 775 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_0
# 776 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_8
# 779 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 780 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 782 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SHOCKED
# 783 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 784 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_9
# 788 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 789 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 790 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_10
# 793 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 794 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 796 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SLOWPOKE_EVOLVED
	goto SpindaIsland_Home_Slowpoke_1

SpindaIsland_Home_Slowpoke_9:
# 798 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_FAINT
# 799 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_Slowpoke_Text_2
# 800 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_Slowpoke_Text_11
# 804 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 805 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Slowpoke_1


SpindaIsland_Home_EventScript_Metapod::
# 814 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 815 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Metapod_Text_0
# 816 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_METAPOD, CRY_MODE_NORMAL
# 817 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Metapod_Text_1
# 820 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 821 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 822 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoysFuckOff::
# 826 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 827 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 828 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 829 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_1
# 833 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_NORMAL
# 834 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_2
# 838 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 840 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_TO_BLACK
# 841 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_METAPOD_BATTLE
# 842 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 1
# 843 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 2
# 844 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 3
# 845 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 4
# 846 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 60
# 847 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 848 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 40
# 849 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin::
# 853 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 854 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 855 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 856 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_0
# 860 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_NORMAL
# 861 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_1
# 865 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 866 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 868 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_TO_BLACK
# 869 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_METAPOD_BATTLE
# 870 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 1
# 871 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 2
# 872 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 3
# 873 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject 4
# 874 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 60
# 875 "data/maps/SpindaIsland_Home/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 876 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 40
# 877 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_MetapodBoy::
# 881 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 882 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_METAPOD_OTHER_SIDE, 1
	goto_if_eq SpindaIsland_Home_EventScript_MetapodBoy_2
SpindaIsland_Home_EventScript_MetapodBoy_1:
# 885 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 886 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 887 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Text_0
# 890 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 891 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 893 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 895 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_FINGER
# 896 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 897 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Text_1
# 900 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 901 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 903 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 905 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 906 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 907 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Text_2
# 910 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 911 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 913 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 914 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 915 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 916 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 917 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 918 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MetapodBoy_2:
# 883 "data/maps/SpindaIsland_Home/scripts.pory"
	goto SpindaIsland_Home_EventScript_MetapodBoysFuckOff
	goto SpindaIsland_Home_EventScript_MetapodBoy_1


SpindaIsland_Home_EventScript_MetapodBoy_Bussin::
# 922 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 923 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_METAPOD_OTHER_SIDE, 1
	goto_if_eq SpindaIsland_Home_EventScript_MetapodBoy_Bussin_2
SpindaIsland_Home_EventScript_MetapodBoy_Bussin_1:
# 926 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 927 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 928 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_0
# 931 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 932 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 934 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 936 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_FINGER
# 937 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 938 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_1
# 941 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 942 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 944 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 946 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_TWIN, EMOTE_ANGRY
# 947 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0
# 948 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_2
# 951 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 952 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 954 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 955 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 956 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_HARDEN
# 957 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 958 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 959 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_2:
# 924 "data/maps/SpindaIsland_Home/scripts.pory"
	goto SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin
	goto SpindaIsland_Home_EventScript_MetapodBoy_Bussin_1


SpindaIsland_Home_PhotoCameraWrongDir::
# 963 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 964 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 965 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 966 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_PhotoCameraWrongDir_Text_0
# 969 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 970 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 971 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_FaucetShopSign::
# 975 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_FaucetShopSign_Text_0, MSGBOX_SIGN
	return


# 982 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_SadManExitsHouse:
# 983 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
	step_end

# 986 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_SadManReEntersHouse:
# 987 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 988 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 989 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
	step_end

# 992 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_PlayerMakesWay:
# 993 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 994 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 995 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
	step_end

# 998 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_Slowpoke:
# 999 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 1000 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 1001 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
# 1002 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1002 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1002 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1003 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 1004 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1005 "data/maps/SpindaIsland_Home/scripts.pory"
	face_down
# 1006 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1007 "data/maps/SpindaIsland_Home/scripts.pory"
	face_left
# 1008 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1009 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
# 1010 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1011 "data/maps/SpindaIsland_Home/scripts.pory"
	face_player
# 1012 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1012 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1012 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1013 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 1014 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 1015 "data/maps/SpindaIsland_Home/scripts.pory"
	jump_in_place_down
# 1016 "data/maps/SpindaIsland_Home/scripts.pory"
	unlock_facing_direction
# 1017 "data/maps/SpindaIsland_Home/scripts.pory"
	emote_heart
# 1018 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1018 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
# 1018 "data/maps/SpindaIsland_Home/scripts.pory"
	delay_16
	step_end

SpindaIsland_Home_SlowpokeMistress::
# 1022 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1023 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1024 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_SLOWPOKE_REWARD, SpindaIsland_Home_SlowpokeMistress_2
# 1033 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_SlowpokeMistress_3
# 1077 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_SWEAT
# 1078 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 1079 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_7
# 1082 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1083 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 1084 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_8
# 1088 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1089 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_SlowpokeMistress_1:
# 1091 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_SlowpokeMistress_2:
# 1025 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_HAPPY
# 1026 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 1027 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_1
# 1031 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1032 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_SlowpokeMistress_1

SpindaIsland_Home_SlowpokeMistress_3:
# 1034 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 1035 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 1036 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1037 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1038 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1040 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_SURPRISED
# 1041 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_SlowpokeMistress_Text_0
# 1042 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_2
# 1046 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1047 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 1048 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_3
# 1051 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1052 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_HAPPY
# 1053 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_4
# 1056 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1057 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LASS, EMOTE_NORMAL
# 1058 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_5
# 1061 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1062 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1064 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_WATER_STONE_2
# 1066 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 1067 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1068 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_SlowpokeMistress_Text_6
# 1072 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1073 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1075 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_SLOWPOKE_REWARD
	goto SpindaIsland_Home_SlowpokeMistress_1


SpindaIsland_Home_EventScript_Juan::
# 1095 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1096 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1097 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 1098 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Juan_Text_0
# 1099 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_TALKED_TO_JUAN_ABOUT_PUBES, SpindaIsland_Home_EventScript_Juan_2
# 1123 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_5
# 1134 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SURPRISED
# 1135 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_6
# 1138 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1139 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1140 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_TALKED_TO_JUAN_ABOUT_PUBES
SpindaIsland_Home_EventScript_Juan_1:
# 1143 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Juan_2:
# 1100 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_1
# 1104 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_Juan_Text_2, SpindaIsland_Home_EventScript_Juan_Text_3
# 1115 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 1116 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Juan_Text_4
# 1120 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1121 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Juan_1


SpindaIsland_Home_EventScript_Machoke::
# 1147 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1148 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1149 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
# 1150 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_TALKED_TO_JUAN_ABOUT_PUBES, SpindaIsland_Home_EventScript_Machoke_2
# 1153 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Machoke_Text_1
SpindaIsland_Home_EventScript_Machoke_1:
# 1155 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Machoke_Text_2
# 1158 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1159 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1160 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Machoke_2:
# 1151 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Machoke_Text_0
	goto SpindaIsland_Home_EventScript_Machoke_1


SpindaIsland_Home_EventScript_Lisa::
# 1164 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1165 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1166 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL_BLACK, EMOTE_NORMAL
# 1167 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Lisa_Text_0
# 1168 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Lisa_Text_1
# 1171 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1172 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1173 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_OldWoman::
# 1177 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1178 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1179 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_SHUPPET_QUEST_STARTED, SpindaIsland_Home_EventScript_OldWoman_2
# 1190 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_HIDE_SHUPPETS, SpindaIsland_Home_EventScript_OldWoman_3
SpindaIsland_Home_EventScript_OldWoman_1:
# 1201 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_HIDE_SHUPPETS, SpindaIsland_Home_EventScript_OldWoman_7
SpindaIsland_Home_EventScript_OldWoman_6:
# 1259 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_OldWoman_2:
# 1180 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1181 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1182 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1183 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_1
# 1187 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1188 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1189 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SHUPPET_QUEST_STARTED
	goto SpindaIsland_Home_EventScript_OldWoman_1

SpindaIsland_Home_EventScript_OldWoman_3:
# 1191 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1192 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1193 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1194 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_2
# 1197 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1198 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_OldWoman_1

SpindaIsland_Home_EventScript_OldWoman_7:
# 1202 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1203 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1204 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_2
# 1207 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1208 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1210 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1211 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1212 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_3
# 1215 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1216 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1218 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 1219 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_OldWoman_Text_0
# 1220 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_4
# 1223 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 1224 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_5
# 1229 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1230 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1232 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_PB_AND_J
# 1234 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 1235 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_6
# 1238 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1239 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1241 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, SpindaIsland_Home_Movement_GrandmaEntersHome
# 1242 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1243 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject VAR_LAST_TALKED
# 1244 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_EXIT
# 1245 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1246 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_HIDE_OLD_WOMAN
# 1248 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1249 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1250 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWoman_Text_7
# 1254 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1255 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1257 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_OldWoman_6


# 1262 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_GrandmaEntersHome:
# 1263 "data/maps/SpindaIsland_Home/scripts.pory"
	face_up
	step_end

SpindaIsland_Home_EventScript_Boat::
	return


SpindaIsland_Home_EventScript_OldWomansDoor::
# 1271 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1273 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1274 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1275 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_OldWomansDoor_Text_0
# 1278 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1279 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1281 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_CarBoy::
# 1285 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1286 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1287 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_BOY, EMOTE_NORMAL
# 1288 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarBoy_Text_0
# 1289 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarBoy_Text_1
# 1292 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1293 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1294 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1295 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1296 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_CarGirl::
# 1300 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1301 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_RECEIVED_NICKEL, SpindaIsland_Home_CarGirl_2
# 1311 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_REPLACED_WHEEL, SpindaIsland_Home_CarGirl_3
# 1328 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_LOOKING_FOR_WHEEL_REPLACEMENT, SpindaIsland_Home_CarGirl_4
# 1338 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1339 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1340 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1341 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_4
# 1348 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1349 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1351 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_LOOKING_FOR_WHEEL_REPLACEMENT
SpindaIsland_Home_CarGirl_1:
# 1354 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 1355 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1357 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_CarGirl_2:
# 1302 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1303 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1304 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1305 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_1
# 1308 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1309 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_CarGirl_1

SpindaIsland_Home_CarGirl_3:
# 1312 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1313 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1314 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1315 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_2
# 1323 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1324 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1326 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_RUSTY_NICKEL
# 1327 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_RECEIVED_NICKEL
	goto SpindaIsland_Home_CarGirl_1

SpindaIsland_Home_CarGirl_4:
# 1329 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1330 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_PENSIVE
# 1331 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1332 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_CarGirl_Text_3
# 1335 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1336 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_CarGirl_1


SpindaIsland_Home_EventScript_MissingWheel::
# 1361 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1362 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_REPLACED_WHEEL, SpindaIsland_Home_EventScript_MissingWheel_2
# 1371 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1372 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1373 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MissingWheel_Text_1
# 1377 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1378 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_MissingWheel_1:
# 1380 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_MissingWheel_2:
# 1363 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1364 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1365 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_MissingWheel_Text_0
# 1368 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1369 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_MissingWheel_1


SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet::
# 1384 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1386 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_1
# 1417 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1418 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1419 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_2
# 1422 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1423 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	return

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_1:
# 1387 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1388 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1389 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_0
# 1392 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1393 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1395 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1397 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_CLICK
# 1398 "data/maps/SpindaIsland_Home/scripts.pory"
	setmetatile 27, 50, METATILE_SpindaIslandSecondary_FaucetWheel, TRUE
# 1399 "data/maps/SpindaIsland_Home/scripts.pory"
	special DrawWholeMapView
# 1400 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1402 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1404 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1405 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1406 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_1
# 1409 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1410 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1412 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_BROKEN_FAUCET
# 1413 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_REPLACED_WHEEL
# 1415 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_SurveyedWheel::
# 1428 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1429 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_SurveyedWheel_4
SpindaIsland_Home_EventScript_SurveyedWheel_3:
# 1487 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1488 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1489 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_0
# 1492 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1493 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_SurveyedWheel_1:
# 1495 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_SurveyedWheel_2:
# 1430 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1431 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1432 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_0
# 1435 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1436 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1437 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_1
# 1441 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
	checkitem ITEM_BORROWED_PLIERS
# 0 "data/maps/SpindaIsland_Home/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_EventScript_SurveyedWheel_7
# 1479 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1480 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_6
# 1483 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1484 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SurveyedWheel_1

SpindaIsland_Home_EventScript_SurveyedWheel_4:
# 1429 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_unset FLAG_FOUND_TOUGH_BOLT, SpindaIsland_Home_EventScript_SurveyedWheel_2
	goto SpindaIsland_Home_EventScript_SurveyedWheel_3

SpindaIsland_Home_EventScript_SurveyedWheel_7:
# 1444 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1445 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_2
# 1448 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1449 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1451 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 15, DIR_EAST
# 1452 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_GIRL, EMOTE_NORMAL
# 1453 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_CarGirl_Text_0
# 1454 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_3
# 1457 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1458 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1460 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1461 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1462 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_4
# 1465 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1466 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1468 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 15, DIR_NORTH
# 1469 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1471 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1472 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1473 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SurveyedWheel_Text_5
# 1476 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1477 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_SurveyedWheel_1


SpindaIsland_Home_EventScript_Raft::
# 1499 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1500 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1501 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1502 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Raft_Text_0
# 1506 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1507 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1508 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_ThisIsConvenient::
# 1512 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1514 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_BROKE, SpindaIsland_Home_EventScript_ThisIsConvenient_2
SpindaIsland_Home_EventScript_ThisIsConvenient_1:
# 1529 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_ThisIsConvenient_2:
# 1515 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 1516 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 20
# 1518 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1519 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1520 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ThisIsConvenient_Text_0
# 1523 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1524 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1526 "data/maps/SpindaIsland_Home/scripts.pory"
	setvar VAR_PASSED_IN_FRONT_OF_FAUCET_SHOP, 1
	goto SpindaIsland_Home_EventScript_ThisIsConvenient_1


SpindaIsland_Home_EventScript_Pot::
# 1533 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1534 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SALTED_DISH, SpindaIsland_Home_EventScript_Pot_2
# 1543 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1544 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1545 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pot_Text_1
# 1548 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_DISGUSTED
# 1549 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pot_Text_2
# 1553 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1554 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Pot_1:
# 1556 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Pot_2:
# 1535 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1536 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1537 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pot_Text_0
# 1540 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1541 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Pot_1


SpindaIsland_Home_EventScript_SaltDish::
# 1560 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1561 "data/maps/SpindaIsland_Home/scripts.pory"
	removeitem ITEM_SALTY_LEMONADE
# 1562 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SALTED_DISH
# 1563 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1564 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1565 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SaltDish_Text_0
# 1568 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1569 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1571 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_POISON_POWDER
# 1572 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1573 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_POISON_POWDER
# 1574 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1575 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_POISON_POWDER
# 1576 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1578 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1579 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1580 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_SaltDish_Text_1
# 1583 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1584 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1586 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_FeedZiggy::
# 1590 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1591 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1592 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1593 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_FeedZiggy_2
# 1598 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_FeedZiggy_Text_1
SpindaIsland_Home_EventScript_FeedZiggy_1:
# 1602 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1603 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1604 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_FeedZiggy_2:
# 1594 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_FeedZiggy_Text_0
	goto SpindaIsland_Home_EventScript_FeedZiggy_1


SpindaIsland_Home_EventScript_Cook::
# 1608 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1609 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 1611 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_GOT_OIL, SpindaIsland_Home_EventScript_Cook_2
# 1621 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SALTED_DISH, SpindaIsland_Home_EventScript_Cook_3
# 1673 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_SAD
# 1674 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1675 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_5
# 1681 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1682 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1684 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_COOK_SAD
SpindaIsland_Home_EventScript_Cook_1:
# 1687 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Cook_2:
# 1612 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_NORMAL
# 1613 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1614 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_1
# 1618 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1619 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Cook_1

SpindaIsland_Home_EventScript_Cook_3:
# 1622 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1623 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1624 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_2
# 1627 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1628 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1630 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_SAD
# 1631 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1632 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_3
# 1635 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1636 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1639 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 20
# 1641 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_SAD
# 1642 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1643 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pot_Text_1
# 1646 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1647 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1649 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_PIN
# 1650 "data/maps/SpindaIsland_Home/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 1651 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmovement 0
# 1652 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1653 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 48
# 1655 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_COOK, EMOTE_NORMAL
# 1656 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Cook_Text_0
# 1657 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Cook_Text_4
# 1664 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1665 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1667 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_COOK_SAD
# 1668 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_GOT_OIL
# 1669 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_COOKING_OIL
# 1671 "data/maps/SpindaIsland_Home/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_EventScript_Cook_1


SpindaIsland_Home_EventScript_Zigzagoon::
# 1691 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1692 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_ZIGGY_ASLEEP, SpindaIsland_Home_EventScript_Zigzagoon_2
# 1701 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_ENCOUNTER
# 1702 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Zigzagoon_Text_2
# 1703 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Zigzagoon_Text_3
# 1706 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 1707 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Zigzagoon_1:
# 1709 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Zigzagoon_2:
# 1693 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_SNORE
# 1694 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Zigzagoon_Text_0
# 1695 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Zigzagoon_Text_1
# 1698 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1699 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Zigzagoon_1


SpindaIsland_Home_EventScript_Pliers::
# 1713 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1714 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_ZIGGY_ASLEEP, SpindaIsland_Home_EventScript_Pliers_2
# 1728 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SAW_PLIERS, SpindaIsland_Home_EventScript_Pliers_5
# 1738 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, SpindaIsland_Home_EventScript_Pliers_8
# 1768 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1769 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1770 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_5
SpindaIsland_Home_EventScript_Pliers_1:
# 1778 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Pliers_2:
# 1715 "data/maps/SpindaIsland_Home/scripts.pory"
	removeobject VAR_LAST_TALKED
# 1716 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_BORROWED_PLIERS
# 1717 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_PICKED_UP_PLIERS
# 1719 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_DISGUSTED
# 1720 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1721 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_0
# 1725 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1726 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Pliers_1

SpindaIsland_Home_EventScript_Pliers_5:
# 1729 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1730 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1731 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_1
# 1735 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1736 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Pliers_1

SpindaIsland_Home_EventScript_Pliers_8:
# 1739 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1740 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1741 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_2
# 1745 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 1746 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_3
# 1749 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1750 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1752 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_ENCOUNTER
# 1753 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Zigzagoon_Text_2
# 1754 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Zigzagoon_Text_3
# 1757 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 1758 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1759 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1760 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Pliers_Text_4
# 1763 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1764 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1766 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SAW_PLIERS
	goto SpindaIsland_Home_EventScript_Pliers_1


SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy::
# 1782 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1783 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
# 1784 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1786 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_ENCOUNTER
# 1787 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Zigzagoon_Text_2
# 1788 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_0
# 1791 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 1792 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1794 "data/maps/SpindaIsland_Home/scripts.pory"
	delay 30
# 1796 "data/maps/SpindaIsland_Home/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_FAINT
# 1797 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Zigzagoon_Text_0
# 1798 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_1
# 1801 "data/maps/SpindaIsland_Home/scripts.pory"
	waitmoncry
# 1802 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_SNORE
# 1803 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_2
# 1806 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1808 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 1809 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1810 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_3
# 1814 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1815 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1817 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_ZIGGY_ASLEEP
# 1818 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_UseGrassBlade::
# 1822 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1823 "data/maps/SpindaIsland_Home/scripts.pory"
	playse SE_M_GRASSWHISTLE
# 1824 "data/maps/SpindaIsland_Home/scripts.pory"
	waitse
# 1825 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_BobsDoor::
# 1829 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1830 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_BobsHouseSign_Text_0
# 1831 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsDoor_Text_0
# 1834 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1835 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1836 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsDoor_Text_1
# 1839 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 1840 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsDoor_Text_2
# 1843 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1844 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1845 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_CynthiasDoor::
# 1849 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 1850 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 1851 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_GoToSail_Text_0
# 1852 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_CynthiasDoor_Text_0
# 1856 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 1857 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 1858 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


# 1862 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_RaftGoesToIsland:
# 1863 "data/maps/SpindaIsland_Home/scripts.pory"
	face_left
# 1864 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_facing_direction
# 1865 "data/maps/SpindaIsland_Home/scripts.pory"
	lock_anim
# 1866 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1866 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1866 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1866 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1866 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1866 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1866 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
	step_end

# 1869 "data/maps/SpindaIsland_Home/scripts.pory"
SpindaIsland_Home_Movement_PlayerEntersRaft:
# 1870 "data/maps/SpindaIsland_Home/scripts.pory"
	walk_down
# 1871 "data/maps/SpindaIsland_Home/scripts.pory"
	set_invisible
	step_end

SpindaIsland_Home_EventScript_GoToSail_Text_0:
# 38 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_EventScript_GoToSail_Text_1:
# 40 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "At last! I can finally set sail!!$"

SpindaIsland_Home_EventScript_GoToSail_Text_2:
# 55 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And voilà!$"

SpindaIsland_Home_EventScript_GoToSail_Text_3:
# 59 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Goodbye, Spinda Island…\p"
	.string "Hello, adventure!$"

SpindaIsland_Home_EventScript_MainQuestRecap_Text_0:
# 88 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Alright! The quicker mom gets her\n"
	.string "glass of {COLOR BLUE}WATER{COLOR DARK_GRAY}, the quicker Archie\l"
	.string "gets his super badass pirate {COLOR RED}sail{COLOR DARK_GRAY}!\p"
	.string "Let's get moving!$"

SpindaIsland_Home_EventScript_ArchiesHouseSign_Text_0:
# 104 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The Hoenns$"

SpindaIsland_Home_EventScript_BobsHouseSign_Text_0:
# 108 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Mindy$"

SpindaIsland_Home_EventScript_CynthiasHouseSign_Text_0:
# 112 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Cynthia$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_0:
# 121 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Door's locked.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_1:
# 130 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I guess I should leave him alone now.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_2:
# 138 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hello? Are you there?$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_3:
# 143 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Stingy man$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_4:
# 145 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…\p"
	.string "My GOD you're annoying.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_5:
# 164 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here's your reward. I hope you're\n"
	.string "happy.$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_6:
# 183 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "An old and rusty bolt? What am I\n"
	.string "supposed to do with this?$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_7:
# 199 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A {COLOR RED}bolt{COLOR DARK_GRAY}! Of course! Lucky me!\p"
	.string "I'm one step closer to getting that\n"
	.string "sweet sweet faucet replacement!!$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_8:
# 205 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(Did I really say that? Is this how\n"
	.string "being a grownup feels like?)$"

SpindaIsland_Home_EventScript_SadManHome_Back_Text_9:
# 215 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A bolt?\p"
	.string "It's all rusty…\p"
	.string "Guess it'll join my useless trash\n"
	.string "collection!$"

SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_0:
# 231 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sad man$"

SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_1:
# 233 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Curse the architect that built my\n"
	.string "house facing the wrong direction!!\p"
	.string "I can never go home!$"

SpindaIsland_Home_EventScript_Dad_Text_0:
# 245 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Dad$"

SpindaIsland_Home_EventScript_Dad_Text_1:
# 247 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't uh, pour that lemonade I gave\n"
	.string "you on the ground or anything.\p"
	.string "It'd probably kill all the grass and\n"
	.string "flowers.$"

SpindaIsland_Home_EventScript_Dad_Text_2:
# 257 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here, have some lemonade!$"

SpindaIsland_Home_EventScript_Dad_Text_3:
# 265 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hiya, sonny! going adventuring today,\n"
	.string "are we?\p"
	.string "Want some lemonade?$"

SpindaIsland_Home_EventScript_Dad_Text_4:
# 278 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Now we're talkin'!! I can bring this to\n"
	.string "mom, that should do it!\p"
	.string "Let's take a sip first, I am PARCHED!$"

SpindaIsland_Home_EventScript_Dad_Text_5:
# 302 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "BLEARGH!\p"
	.string "Why is it… so salty?!$"

SpindaIsland_Home_EventScript_Dad_Text_6:
# 311 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Why, because it's seawater, obviously!$"

SpindaIsland_Home_EventScript_Dad_Text_7:
# 316 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I take it you're not a fan of my\n"
	.string "recipe?$"

SpindaIsland_Home_EventScript_Dad_Text_8:
# 321 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(You wouldn't be the only one…)$"

SpindaIsland_Home_EventScript_Dad_Text_9:
# 326 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "In any case, it's nice of you to come\n"
	.string "visit me at the office, haha!\p"
	.string "See you around, little Archie! Don't\n"
	.string "get into trouble!$"

SpindaIsland_Home_EventScript_Dad_FromSide_Text_0:
# 355 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Come round to the front of the\n"
	.string "lemonade stand!$"

SpindaIsland_Home_EventScript_Dad_FromSide_Text_1:
# 363 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hiya, sonny! going adventuring today,\n"
	.string "are we?\p"
	.string "Want some lemonade?\p"
	.string "Come round to the front of the\n"
	.string "lemonade stand!$"

SpindaIsland_Home_EventScript_LemonadeStandSign_Text_0:
# 377 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "“ARCHIE'S LEMONADE\n"
	.string "A taste of the seaside!”$"

SpindaIsland_Home_EventScript_MainStreetSign_Text_0:
# 384 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "{UP_ARROW} Main street$"

SpindaIsland_Home_EventScript_MadelineSign_Text_0:
# 390 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bertha$"

SpindaIsland_Home_EventScript_PoemGirl_Text_0:
# 400 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Maggie$"

SpindaIsland_Home_EventScript_PoemGirl_Text_1:
# 402 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "See you around, Archie…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_2:
# 419 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Archie…\p"
	.string "I want to hear a poem…\p"
	.string "I want you to reveal your heart to me.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_3:
# 433 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ocean waves swimming…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_4:
# 434 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Roses are red…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_5:
# 435 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Roses are blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_6:
# 447 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "From the center of the sea…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_7:
# 448 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "They are calling to my heart…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_8:
# 460 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "With faith to reach land.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_9:
# 461 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Only to go back.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_10:
# 471 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And my heart to theirs.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_11:
# 472 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yearning for a touch.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_12:
# 479 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "That was very beautiful.\p"
	.string "I'm not really into haiku, though.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_13:
# 492 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Violets are blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_14:
# 493 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Just like our love…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_15:
# 505 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The sky is pretty…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_16:
# 506 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The Pincurchin are spiky…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_17:
# 519 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And so are you.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_18:
# 520 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And so are you!$"

SpindaIsland_Home_EventScript_PoemGirl_Text_19:
# 526 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, that's nice.\p"
	.string "You're not truly revealing your poet's\n"
	.string "heart, though.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_20:
# 548 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "That's… a weird comparison.\p"
	.string "I thought you were a better poet\n"
	.string "than that.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_21:
# 564 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Which blooms like they do.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_22:
# 565 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wait, I didn't mean to say that.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_23:
# 571 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wow, Archie, uh…\p"
	.string "That's not really what I meant when I\n"
	.string "said you should reveal your heart.\p"
	.string "(Well, this is awkward.)\p"
	.string "(Let's pretend this never happened.)$"

SpindaIsland_Home_EventScript_PoemGirl_Text_24:
# 587 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Violets are red…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_25:
# 601 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The sky isn't blue, it's purple instead.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_26:
# 602 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Doesn't make sense, but fun to be said.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_27:
# 608 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmm…\p"
	.string "You're not revealing your heart right\n"
	.string "now.\p"
	.string "Plus, that didn't make any sense.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_28:
# 624 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Orchids are blue, too.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_29:
# 625 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Everything is blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_30:
# 647 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Because it's my favorite color.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_31:
# 652 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "… … … … …\p"
	.string "Wow, Archie, I…\p"
	.string "This was so touching…\p"
	.string "Thank you for revealing your heart to\n"
	.string "me like this.\p"
	.string "Here, take this.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_32:
# 666 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "It's a blade of grass large enough to\n"
	.string "whistle with.\p"
	.string "Just don't listen to it too\n"
	.string "attentively, you might get sleepy.$"

SpindaIsland_Home_EventScript_Sunbather_Text_0:
# 685 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sunbather$"

SpindaIsland_Home_EventScript_Sunbather_Text_1:
# 687 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ahh, it sure feels good to be sitting\n"
	.string "in the sun surrounded by all this\l"
	.string "{COLOR BLUE}WATER{COLOR DARK_GRAY}…\p"
	.string "…$"

SpindaIsland_Home_EventScript_Sunbather_Text_2:
# 698 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Could you leave? You're blocking the\n"
	.string "sun.$"

SpindaIsland_Home_Slowpoke_Text_0:
# 712 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slowbro$"

SpindaIsland_Home_Slowpoke_Text_1:
# 714 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bruh…$"

SpindaIsland_Home_Slowpoke_Text_2:
# 722 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slowpoke$"

SpindaIsland_Home_Slowpoke_Text_3:
# 724 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slo…$"

SpindaIsland_Home_Slowpoke_Text_4:
# 733 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "… … …?\p"
	.string "He's looking at the white seashell I\n"
	.string "found…$"

SpindaIsland_Home_Slowpoke_Text_5:
# 744 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Give the seashell$"

SpindaIsland_Home_Slowpoke_Text_6:
# 745 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't give the seashell$"

SpindaIsland_Home_Slowpoke_Text_7:
# 755 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sure, why the hell not!\p"
	.string "Here you go, buddy.$"

SpindaIsland_Home_Slowpoke_Text_8:
# 777 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bruh!!$"

SpindaIsland_Home_Slowpoke_Text_9:
# 785 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The heck?!\p"
	.string "My seashell bit him!$"

SpindaIsland_Home_Slowpoke_Text_10:
# 791 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Guess it was a Shellder all this time!$"

SpindaIsland_Home_Slowpoke_Text_11:
# 801 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…Slo…\p"
	.string ":($"

SpindaIsland_Home_EventScript_Metapod_Text_0:
# 815 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod$"

SpindaIsland_Home_EventScript_Metapod_Text_1:
# 818 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_0:
# 828 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Twin$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_1:
# 830 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "What is it?!$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Text_2:
# 835 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, I guess we are blocking the stairs\n"
	.string "a little…\p"
	.string "Fine, we'll take our epic battle\n"
	.string "somewhere else.$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_0:
# 857 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "On god why you gotta bust my balls\n"
	.string "like that fr?!$"

SpindaIsland_Home_EventScript_MetapodBoysFuckOff_Bussin_Text_1:
# 862 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yikes, we lowkey do be blockin the\n"
	.string "stairs rn no cap…\p"
	.string "Aight word word, we gon vibe\n"
	.string "somewhere else.$"

SpindaIsland_Home_EventScript_MetapodBoy_Text_0:
# 888 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm SO CLOSE to tasting that sweet,\n"
	.string "sweet victory!$"

SpindaIsland_Home_EventScript_MetapodBoy_Text_1:
# 898 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't you see we're in the midst of a\n"
	.string "fiery battle?$"

SpindaIsland_Home_EventScript_MetapodBoy_Text_2:
# 908 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod, use harden!!$"

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_0:
# 929 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm deadass SO CLOSE to catchin that\n"
	.string "bussin drip fr!$"

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_1:
# 939 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't you see we tryna catch some\n"
	.string "real heat rn bro? Sheesh!$"

SpindaIsland_Home_EventScript_MetapodBoy_Bussin_Text_2:
# 949 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Metapod, keep hittin that mid boi with\n"
	.string "harden, chief!!$"

SpindaIsland_Home_PhotoCameraWrongDir_Text_0:
# 967 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't use that from this side.$"

SpindaIsland_Home_EventScript_FaucetShopSign_Text_0:
# 976 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "“FAUCET WORKSHOP\n"
	.string "For all your faucet needs!\l"
	.string "WE ARE OPEN!!”$"

SpindaIsland_Home_SlowpokeMistress_Text_0:
# 1026 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Girl$"

SpindaIsland_Home_SlowpokeMistress_Text_1:
# 1028 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Look at my super cool Slowbro!\p"
	.string "He just looks so happy!$"

SpindaIsland_Home_SlowpokeMistress_Text_2:
# 1043 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "By Arceus!!\p"
	.string "How on earth did you convince him to\n"
	.string "evolve?$"

SpindaIsland_Home_SlowpokeMistress_Text_3:
# 1049 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…A cool-looking seashell? What are\n"
	.string "you talking about?$"

SpindaIsland_Home_SlowpokeMistress_Text_4:
# 1054 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Well, thank you anyway! You can have\n"
	.string "this!$"

SpindaIsland_Home_SlowpokeMistress_Text_5:
# 1059 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I no longer need it.$"

SpindaIsland_Home_SlowpokeMistress_Text_6:
# 1069 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmm… A {COLOR BLUE}WATER{COLOR DARK_GRAY} Stone…\p"
	.string "Maybe I could try giving this to mom?$"

SpindaIsland_Home_SlowpokeMistress_Text_7:
# 1080 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I wish my Pokémon would evolve…$"

SpindaIsland_Home_SlowpokeMistress_Text_8:
# 1085 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I keep trying to give him this {COLOR BLUE}WATER{COLOR DARK_GRAY}\n"
	.string "Stone, but it just does nothing.\p"
	.string "Perhaps there's another way…$"

SpindaIsland_Home_EventScript_Juan_Text_0:
# 1098 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Juan$"

SpindaIsland_Home_EventScript_Juan_Text_1:
# 1101 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey, wanna hear more interesting\n"
	.string "facts about Pokémon?$"

SpindaIsland_Home_EventScript_Juan_Text_2:
# 1111 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Nope$"

SpindaIsland_Home_EventScript_Juan_Text_3:
# 1112 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "No thanks$"

SpindaIsland_Home_EventScript_Juan_Text_4:
# 1117 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bummer! Come back whenever, I have\n"
	.string "plenty!$"

SpindaIsland_Home_EventScript_Juan_Text_5:
# 1124 "data/maps/SpindaIsland_Home/scripts.pory"
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
# 1136 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh boy, what a find! I need to write\n"
	.string "this discovery down in my PokéDex!!$"

SpindaIsland_Home_EventScript_Machoke_Text_0:
# 1151 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sexy Machoke$"

SpindaIsland_Home_EventScript_Machoke_Text_1:
# 1153 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Machoke$"

SpindaIsland_Home_EventScript_Machoke_Text_2:
# 1156 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmmm…$"

SpindaIsland_Home_EventScript_Lisa_Text_0:
# 1167 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Lisa$"

SpindaIsland_Home_EventScript_Lisa_Text_1:
# 1169 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey Archie! Heard you were building a\n"
	.string "sick pirate ship!$"

SpindaIsland_Home_EventScript_OldWoman_Text_0:
# 1182 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Old woman$"

SpindaIsland_Home_EventScript_OldWoman_Text_1:
# 1184 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I think my house is haunted. There's\n"
	.string "something living in my attic.\p"
	.string "I don't know what to do…$"

SpindaIsland_Home_EventScript_OldWoman_Text_2:
# 1195 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, I'm too scared to go back inside…$"

SpindaIsland_Home_EventScript_OldWoman_Text_3:
# 1213 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't worry granny! There were some\n"
	.string "Shuppet in your attic, but I chased\l"
	.string "them away!$"

SpindaIsland_Home_EventScript_OldWoman_Text_4:
# 1221 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Shuppet, you say?$"

SpindaIsland_Home_EventScript_OldWoman_Text_5:
# 1225 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "How adorable of you to help out a poor\n"
	.string "old lady…\p"
	.string "How can I repay you?\p"
	.string "You look like you're hungry… Let me\n"
	.string "fix you a little snack!$"

SpindaIsland_Home_EventScript_OldWoman_Text_6:
# 1236 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Have a good day, child.$"

SpindaIsland_Home_EventScript_OldWoman_Text_7:
# 1251 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Cool! Lemme pack this up for later.\p"
	.string "Let's hope it doesn't taste like old\n"
	.string "people or something.$"

SpindaIsland_Home_EventScript_OldWomansDoor_Text_0:
# 1276 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'm glad I was able to help!$"

SpindaIsland_Home_CarBoy_Text_0:
# 1288 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Rudy$"

SpindaIsland_Home_CarBoy_Text_1:
# 1290 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Vrrrbbbbbmmmmmmm!!!!!$"

SpindaIsland_Home_CarGirl_Text_0:
# 1304 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Katie$"

SpindaIsland_Home_CarGirl_Text_1:
# 1306 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Thanks a bunch!$"

SpindaIsland_Home_CarGirl_Text_2:
# 1316 "data/maps/SpindaIsland_Home/scripts.pory"
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
# 1333 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Now what could we use as a wheel…$"

SpindaIsland_Home_CarGirl_Text_4:
# 1342 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey Archie!\p"
	.string "As you can see we're almost done with\n"
	.string "our monster car.\p"
	.string "We're just missing one last wheel!\p"
	.string "We don't really need it to be an actual\n"
	.string "wheel, either.\p"
	.string "Anything round and spinny would do!$"

SpindaIsland_Home_EventScript_MissingWheel_Text_0:
# 1366 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A shiny new wheel!$"

SpindaIsland_Home_EventScript_MissingWheel_Text_1:
# 1374 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "A wheel is missing.\p"
	.string "I'm sure I could find a replacement.$"

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_0:
# 1390 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "What if…$"

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_1:
# 1407 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Fits perfectly! There ya go!$"

SpindaIsland_Home_EventScript_ReplaceWheelWithBrokenFaucet_Text_2:
# 1420 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "This'd be perfect, but I need to\n"
	.string "repair it!$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_0:
# 1433 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Just a regular wheel.$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_1:
# 1438 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wait, it's stuck to the car with bolts!\p"
	.string "If I could just take one…$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_2:
# 1446 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here, let me just…$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_3:
# 1455 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Whatcha doing, Archie?$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_4:
# 1463 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ah, uh, nothing!$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_5:
# 1474 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(Darn, can't do this right under her\n"
	.string "nose.)$"

SpindaIsland_Home_EventScript_SurveyedWheel_Text_6:
# 1481 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'd need some pliers to get it out.$"

SpindaIsland_Home_EventScript_Raft_Text_0:
# 1503 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "My super-awesome pirate ship!\p"
	.string "Only thing missing is the sail.$"

SpindaIsland_Home_EventScript_ThisIsConvenient_Text_0:
# 1521 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Well, this is eerily convenient!$"

SpindaIsland_Home_EventScript_Pot_Text_0:
# 1538 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Much better!$"

SpindaIsland_Home_EventScript_Pot_Text_1:
# 1546 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Slurp…$"

SpindaIsland_Home_EventScript_Pot_Text_2:
# 1550 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ugh, it's tasteless…\p"
	.string "Have people never heard of salt?$"

SpindaIsland_Home_EventScript_SaltDish_Text_0:
# 1566 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Needs some salt, so maybe…$"

SpindaIsland_Home_EventScript_SaltDish_Text_1:
# 1581 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "There, fixed, probably!$"

SpindaIsland_Home_EventScript_FeedZiggy_Text_0:
# 1595 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Good idea, except I need this\n"
	.string "sandwich for the faucet salesman!$"

SpindaIsland_Home_EventScript_FeedZiggy_Text_1:
# 1599 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I'd be afraid of this one biting off my\n"
	.string "hand!$"

SpindaIsland_Home_EventScript_Cook_Text_0:
# 1613 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Cook$"

SpindaIsland_Home_EventScript_Cook_Text_1:
# 1615 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Thank you again.\p"
	.string "You will become a great chef when you\n"
	.string "grow up, I can feel it!$"

SpindaIsland_Home_EventScript_Cook_Text_2:
# 1625 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can you try your dish now?$"

SpindaIsland_Home_EventScript_Cook_Text_3:
# 1633 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "It's not like it's gotten any tastier\n"
	.string "on its own, but sure.$"

SpindaIsland_Home_EventScript_Cook_Text_4:
# 1658 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, wow! It's… It's remarkable!!\p"
	.string "What arcane sorcery…\p"
	.string "What? You added some lemonade in the\n"
	.string "pot?\p"
	.string "Who would have thought!!\p"
	.string "I don't have much to thank you, but\n"
	.string "here is a bottle of my finest cooking\l"
	.string "oil!$"

SpindaIsland_Home_EventScript_Cook_Text_5:
# 1676 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I am distraught.\p"
	.string "My dish isn't turning out how I wanted\n"
	.string "at all…\p"
	.string "How can I make it less… flavorless?\p"
	.string "Is there any hope at all?$"

SpindaIsland_Home_EventScript_Zigzagoon_Text_0:
# 1694 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sleepy Zigzagoon$"

SpindaIsland_Home_EventScript_Zigzagoon_Text_1:
# 1696 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "ZzzzzZzZz…$"

SpindaIsland_Home_EventScript_Zigzagoon_Text_2:
# 1702 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Rabid Zigzagoon$"

SpindaIsland_Home_EventScript_Zigzagoon_Text_3:
# 1704 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "GRRRRRRRR…$"

SpindaIsland_Home_EventScript_Pliers_Text_0:
# 1722 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yuck, the Zigzagoon drooled all over\n"
	.string "them!\p"
	.string "At least I hope it's drool…$"

SpindaIsland_Home_EventScript_Pliers_Text_1:
# 1732 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't get to those {COLOR RED}pliers{COLOR DARK_GRAY} with that\n"
	.string "Zigzagoon guarding them…\p"
	.string "If only there was a way to distract or\n"
	.string "incapacitate it…$"

SpindaIsland_Home_EventScript_Pliers_Text_2:
# 1742 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "These must be the {COLOR RED}pliers{COLOR DARK_GRAY} the faucet\n"
	.string "salesman was talking about!$"

SpindaIsland_Home_EventScript_Pliers_Text_3:
# 1747 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "You're gonna give them to me, right\n"
	.string "little Ziggy?$"

SpindaIsland_Home_EventScript_Pliers_Text_4:
# 1761 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Nope, not gonna risk a hand just to\n"
	.string "get these!$"

SpindaIsland_Home_EventScript_Pliers_Text_5:
# 1771 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Is this… a pair of {COLOR RED}pliers{COLOR DARK_GRAY}?\p"
	.string "I wonder what a Zigzagoon would use\n"
	.string "these for.$"

SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_0:
# 1789 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "GRRRRRRRR!!$"

SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_1:
# 1799 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "…GrrrzzZZzzzzZz…$"

SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_2:
# 1804 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "ZzzzZzZzzZZzzz…$"

SpindaIsland_Home_EventScript_UseGrassBladeWithZiggy_Text_3:
# 1811 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Awesome! It fell asleep!\p"
	.string "Let's get those {COLOR RED}pliers{COLOR DARK_GRAY}!$"

SpindaIsland_Home_EventScript_BobsDoor_Text_0:
# 1832 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hey Archie! Wanna come in for a\n"
	.string "Pokémon trade?$"

SpindaIsland_Home_EventScript_BobsDoor_Text_1:
# 1837 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Can't today, I'm busy!$"

SpindaIsland_Home_EventScript_BobsDoor_Text_2:
# 1841 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "(Never again.)$"

SpindaIsland_Home_EventScript_CynthiasDoor_Text_0:
# 1853 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "I ain't going in there unprepared.\p"
	.string "Or at all.$"

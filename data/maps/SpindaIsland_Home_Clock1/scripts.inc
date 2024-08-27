SpindaIsland_Home_Clock1_MapScripts::
# 4 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 11 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 5 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_EVOLVED, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 8 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWPOKE )
	return

SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 6 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( SLOWBRO )
	return

SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD:
# 13 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_FAUCET_BROKE, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 14 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 20, 8, METATILE_SpindaIslandSecondary_BrokenFaucetWall, TRUE
	return


SpindaIsland_Home_Clock1_HidingBoy::
# 20 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 22 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	faceplayer
# 23 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 24 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_HidingBoy_Text_1, MSGBOX_AUTOCLOSE
# 28 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 29 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 30 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_HidingBoy_Text_3
# 33 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 34 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 36 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_Faucet::
# 41 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_SPINDA_ISLAND_INTRO_STATE, 2
	goto_if_gt SpindaIsland_Home_Clock1_Faucet_1
# 51 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_SPINDA_ISLAND_INTRO_STATE, 2
	goto_if_eq SpindaIsland_Home_Clock1_Faucet_2
	return

SpindaIsland_Home_Clock1_Faucet_1:
# 42 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 43 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 44 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 45 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_0
# 48 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 49 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 50 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_Faucet_2:
# 52 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	hidefollower
# 53 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 54 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 55 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 56 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_1
# 61 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 62 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 64 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 66 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 13, METATILE_SpindaIslandSecondary_BrokenFaucetWall, TRUE
# 67 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 14, METATILE_SpindaIslandSecondary_BrokenFaucetGround, FALSE
# 68 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 70 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Clock1_FaucetBreaks
# 72 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_BRICK_BREAK
# 76 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 77 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 79 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 80 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 81 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_2
# 87 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 88 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 90 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 14, METATILE_SpindaIsland_Grass, FALSE
# 91 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 92 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	giveitem ITEM_BROKEN_FAUCET
# 94 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 3
# 95 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_FAUCET_BROKE
# 97 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_PhotoCamera::
# 102 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 104 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_Clock1_PhotoCamera_2
# 115 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_FACING, DIR_NORTH
	goto_if_ne SpindaIsland_Home_Clock1_PhotoCamera_5
# 124 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_2
# 128 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 129 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 130 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_3
# 133 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 134 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	checkitem ITEM_RUSTY_NICKEL
# 0 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_Clock1_PhotoCamera_9
SpindaIsland_Home_Clock1_PhotoCamera_8:
# 335 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
SpindaIsland_Home_Clock1_PhotoCamera_4:
# 338 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_PhotoCamera_2:
# 105 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 106 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 107 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_0
# 110 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 111 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	return

SpindaIsland_Home_Clock1_PhotoCamera_5:
# 116 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 117 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 118 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_1
# 121 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 122 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock1_PhotoCamera_4

SpindaIsland_Home_Clock1_PhotoCamera_9:
# 137 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_REALIZED_I_HAVE_NICKEL, SpindaIsland_Home_Clock1_PhotoCamera_12
# 144 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_PIN
# 145 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 146 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 147 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 149 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 150 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SURPRISED
# 151 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_5
SpindaIsland_Home_Clock1_PhotoCamera_11:
# 158 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Clock1_PhotoCamera_Text_6, SpindaIsland_Home_Clock1_PhotoCamera_Text_7
# 169 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 170 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 172 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SpindaIsland_Home_Clock1_PhotoCamera_15
	goto SpindaIsland_Home_Clock1_PhotoCamera_8

SpindaIsland_Home_Clock1_PhotoCamera_12:
# 138 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 139 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 140 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_4
	goto SpindaIsland_Home_Clock1_PhotoCamera_11

SpindaIsland_Home_Clock1_PhotoCamera_15:
# 173 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_CAMERA_EXPLODED
# 175 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 176 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 177 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_8
# 182 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 183 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 185 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_VEND
# 186 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_9
# 189 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 190 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 192 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 193 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 194 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_10
# 197 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 198 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 200 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 202 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 203 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 204 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 205 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 206 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 207 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 208 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 20
# 209 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_FAILURE
# 210 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 211 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 20
# 212 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_BANG
# 214 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 31, 13, METATILE_SpindaIsland_Grass, FALSE
# 215 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 31, 14, METATILE_SpindaIsland_Grass, FALSE
# 217 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Clock1_Movement_ArchieJumps
# 218 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 0
# 219 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 221 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 222 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SURPRISED
# 223 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_11
# 227 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 228 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 230 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_EXIT
# 231 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	clearflag FLAG_HIDE_PHOTO_MAN
# 232 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	addobject 14
# 233 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 235 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 236 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 14, SpindaIsland_Home_Clock1_Movement_PhotoManNotice
# 237 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 14
# 239 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 14, SpindaIsland_Home_Clock1_Movement_PhotoManJump
# 240 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_BIKE_HOP
# 241 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 14
# 242 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 244 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_12
# 245 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_13
# 250 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Clock1_PhotoCamera_Text_14, SpindaIsland_Home_Clock1_PhotoCamera_Text_15
# 260 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 262 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	switch VAR_RESULT
# 263 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	case 0, SpindaIsland_Home_Clock1_PhotoCamera_19
SpindaIsland_Home_Clock1_PhotoCamera_17:
# 272 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 274 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_12
# 275 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_17
# 282 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 284 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	giveitem ITEM_TOY_CAMERA
# 286 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_12
# 287 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_18
# 291 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 293 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 14, SpindaIsland_Home_Clock1_Movement_PhotoManLeave
# 294 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 0
# 295 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_EXIT
# 296 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removeobject 14
# 297 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_HIDE_PHOTO_MAN
# 298 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 300 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 60
# 301 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 303 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 304 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 305 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_19
# 309 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 310 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 311 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_20
# 314 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 315 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 317 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 318 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 319 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_LEER
# 320 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, 0
# 321 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, 0
# 322 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 324 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 325 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_BLIND
# 326 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_21
# 330 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 331 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock1_PhotoCamera_8

SpindaIsland_Home_Clock1_PhotoCamera_19:
# 264 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_12
# 265 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_16
	goto SpindaIsland_Home_Clock1_PhotoCamera_17


SpindaIsland_Home_Clock1_PhotoHouseDoor::
# 342 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 343 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 344 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 345 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoHouseDoor_Text_0
# 346 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 347 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


# 350 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_PhotoManLeave:
# 351 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_left
# 351 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_left
# 351 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_left
# 352 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_up
	step_end

# 355 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_PhotoManNotice:
# 356 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_down
# 357 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	face_right
# 358 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay_16
# 359 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_right
# 359 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_right
# 359 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_right
# 360 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay_16
	step_end

# 363 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_ArchieJumps:
# 364 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 365 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	jump_in_place_up
# 366 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	unlock_facing_direction
# 367 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	emote_exclamation_mark
	step_end

# 370 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_FaucetBreaks:
# 371 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 372 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	player_run_down
	step_end

SpindaIsland_Home_Clock1_HidingBoy_Text_0:
# 23 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Timmy$"

SpindaIsland_Home_Clock1_HidingBoy_Text_1:
# 25 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Darnit! You found me!$"

SpindaIsland_Home_Clock1_HidingBoy_Text_2:
# 29 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock1_HidingBoy_Text_3:
# 31 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Wazzup, Timmy?$"

SpindaIsland_Home_Clock1_Faucet_Text_0:
# 46 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Faucet's broken…$"

SpindaIsland_Home_Clock1_Faucet_Text_1:
# 57 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Alrighty, time to turn the big old\n"
	.string "faucet back on!\p"
	.string "Hnng…\p"
	.string "… … … … …$"

SpindaIsland_Home_Clock1_Faucet_Text_2:
# 82 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Aw, Shuckles! It broke!\p"
	.string "Mom is totally gonna kill me!!\p"
	.string "Let's, uh, not tell her anything and\n"
	.string "fix this ourselves!\p"
	.string "I better pocket this, too.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_0:
# 108 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Nothing's left but a pile of ashes…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_1:
# 119 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I should probably face the lens if I\n"
	.string "want to take a picture of myself.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_2:
# 125 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "“GET A PHOTO FOR A NICKEL!”$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_3:
# 131 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Ugh, rattatas… Don't they know kids\n"
	.string "don't have money?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_4:
# 141 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I still have that nickel from earlier.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_5:
# 152 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Wait! I do have a nickel, don't I?\p"
	.string "Those kids gave it to me earlier!\p"
	.string "I'm basically rich!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_6:
# 165 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Use nickel$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_7:
# 166 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Save nickel$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_8:
# 178 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "It's kinda rusty and misshapen…\p"
	.string "Oh well, what's the worst that can\n"
	.string "happen?\p"
	.string "A coin's a coin, right?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_9:
# 187 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "…clunk!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_10:
# 195 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "…Cheese!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_11:
# 224 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "The hell?!\p"
	.string "The camera… exploded?!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_12:
# 244 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Camera owner$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_13:
# 246 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "What the hell did you do?\p"
	.string "Why did you destroy my automatic\n"
	.string "camera?!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_14:
# 257 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Where's my photograph?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_15:
# 258 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "It didn't like my nickel!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_16:
# 266 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "What the hell happened?\p"
	.string "Why did you destroy my automatic\n"
	.string "camera?!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_17:
# 276 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "… …You were just trying to have your\n"
	.string "photograph taken?\p"
	.string "Hmm…\p"
	.string "I guess maybe using Voltorb as\n"
	.string "electrical components wasn't such a\l"
	.string "great idea after all…\p"
	.string "Alright, alright, I'm sorry about this\n"
	.string "whole exploding business.\p"
	.string "Let me give you a brand-new camera as\n"
	.string "an apology.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_18:
# 288 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "You're welcome, kid.\p"
	.string "Please uh, don't tell your parents\n"
	.string "about this, alright?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_19:
# 306 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Hey, at least I got a free camera out\n"
	.string "of this!\p"
	.string "…Wait a minute…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_20:
# 312 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Oh, man, this is just a toy! It doesn't\n"
	.string "take any pictures!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_21:
# 327 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Ugh, the flash works though…\p"
	.string "My eyes… I'm blind…$"

SpindaIsland_Home_Clock1_PhotoHouseDoor_Text_0:
# 345 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "…I can hear tiny explosions through\n"
	.string "the door…$"

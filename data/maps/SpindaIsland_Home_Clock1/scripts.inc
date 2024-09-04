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
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SHOCKED
# 80 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 81 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_2
# 85 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 86 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 87 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_3
# 91 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 92 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 94 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 14, METATILE_SpindaIsland_Grass, FALSE
# 95 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 96 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	giveitem ITEM_BROKEN_FAUCET
# 98 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 3
# 99 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_FAUCET_BROKE
# 101 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_PhotoCamera::
# 106 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 108 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_Clock1_PhotoCamera_2
# 119 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_FACING, DIR_NORTH
	goto_if_ne SpindaIsland_Home_Clock1_PhotoCamera_5
	checkitem ITEM_RUSTY_NICKEL
# 0 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_Clock1_PhotoCamera_9
# 352 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_3
# 356 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 357 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 358 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_4
# 361 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 362 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
SpindaIsland_Home_Clock1_PhotoCamera_8:
# 365 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
SpindaIsland_Home_Clock1_PhotoCamera_4:
# 368 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_PhotoCamera_2:
# 109 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 110 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 111 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_0
# 114 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 115 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	return

SpindaIsland_Home_Clock1_PhotoCamera_5:
# 120 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 121 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 122 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_1
# 125 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 126 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock1_PhotoCamera_4

SpindaIsland_Home_Clock1_PhotoCamera_9:
# 129 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_REALIZED_I_HAVE_NICKEL, SpindaIsland_Home_Clock1_PhotoCamera_13
# 136 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_3
# 140 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 141 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 142 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_4
# 145 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 146 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 148 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_PIN
# 149 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 150 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 151 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 153 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 154 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 155 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_5
# 161 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_REALIZED_I_HAVE_NICKEL
SpindaIsland_Home_Clock1_PhotoCamera_12:
# 164 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Clock1_PhotoCamera_Text_6, SpindaIsland_Home_Clock1_PhotoCamera_Text_7
# 175 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 176 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 178 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SpindaIsland_Home_Clock1_PhotoCamera_16
	goto SpindaIsland_Home_Clock1_PhotoCamera_8

SpindaIsland_Home_Clock1_PhotoCamera_13:
# 130 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 131 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 132 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_2
	goto SpindaIsland_Home_Clock1_PhotoCamera_12

SpindaIsland_Home_Clock1_PhotoCamera_16:
# 179 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_CAMERA_EXPLODED
# 181 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 182 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 183 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_8
# 186 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 187 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 188 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_9
# 192 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 193 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 195 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_VEND
# 196 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_10
# 199 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 200 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 202 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 203 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 204 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_11
# 207 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 208 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 210 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 212 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 213 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 214 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 215 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 216 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 217 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 218 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 20
# 219 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_FAILURE
# 220 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 221 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 20
# 222 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_MEGA_KICK
# 223 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 224 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_EXPLOSION
# 226 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 31, 13, METATILE_SpindaIsland_Grass, FALSE
# 227 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 31, 14, METATILE_SpindaIsland_Grass, FALSE
# 228 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 230 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8004, 1
# 231 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8005, 1
# 232 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8006, 8
# 233 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8007, 5
# 234 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special ShakeCamera
# 236 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Clock1_Movement_ArchieJumps
# 238 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	dofieldeffect FLDEFF_EXPLOSION
# 240 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitfieldeffect FLDEFF_EXPLOSION
# 241 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 0
# 242 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 243 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitstate
# 245 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 246 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SHOCKED
# 247 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_12
# 251 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 252 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 254 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_EXIT
# 255 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	clearflag FLAG_HIDE_PHOTO_MAN
# 256 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	addobject 13
# 257 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 259 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 260 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, SpindaIsland_Home_Clock1_Movement_PhotoManNotice
# 261 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 13
# 263 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, SpindaIsland_Home_Clock1_Movement_PhotoManJump
# 264 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_BIKE_HOP
# 265 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 13
# 266 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 268 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_13
# 269 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_14
# 274 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Clock1_PhotoCamera_Text_15, SpindaIsland_Home_Clock1_PhotoCamera_Text_16
# 284 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 286 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_13
# 287 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_17
# 291 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject 13, DIR_NORTH
# 292 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_18
# 295 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	faceplayer
# 296 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_19
# 300 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 302 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	giveitem ITEM_TOY_CAMERA
# 304 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_13
# 305 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_20
# 309 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 311 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, SpindaIsland_Home_Clock1_Movement_PhotoManLeave
# 312 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 0
# 313 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_EXIT
# 314 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removeobject 13
# 315 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_HIDE_PHOTO_MAN
# 316 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 318 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 60
# 319 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 321 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 322 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 323 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_21
# 327 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 328 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 329 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_22
# 332 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 333 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 335 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 336 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 337 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_LEER
# 338 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, 0
# 339 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, 0
# 340 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 342 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 343 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_BLIND
# 344 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_23
# 348 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 349 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock1_PhotoCamera_8


SpindaIsland_Home_Clock1_PhotoHouseDoor::
# 372 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 373 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 374 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 375 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoHouseDoor_Text_0
# 376 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 377 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_PhotoHouseSign::
# 381 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoHouseSign_Text_0, MSGBOX_SIGN
	return


# 384 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_PhotoManLeave:
# 385 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_left
# 385 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_left
# 385 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_left
# 386 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_up
	step_end

# 389 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_PhotoManNotice:
# 390 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_down
# 391 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	face_right
# 392 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay_16
# 393 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_right
# 393 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_right
# 393 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_right
# 394 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay_16
	step_end

# 397 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_PhotoManJump:
# 398 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 399 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	jump_in_place_down
# 400 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	unlock_facing_direction
	step_end

# 403 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_ArchieJumps:
# 404 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 405 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	jump_in_place_up
# 406 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	unlock_facing_direction
# 407 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	emote_exclamation_mark
	step_end

# 410 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_FaucetBreaks:
# 411 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 412 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
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
	.string "Mom is totally gonna kill me!!$"

SpindaIsland_Home_Clock1_Faucet_Text_3:
# 88 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Let's, uh, not tell her anything and\n"
	.string "fix this ourselves!\p"
	.string "I better pocket this, too.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_0:
# 112 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Nothing left but a pile of ashes…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_1:
# 123 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I should probably face the lens if I\n"
	.string "want to take a picture of myself.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_2:
# 133 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I still have that nickel from earlier.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_3:
# 137 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "“GET A PHOTO FOR A NICKEL!”$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_4:
# 143 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Ugh, Rattatas… Don't they know kids\n"
	.string "don't have money?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_5:
# 156 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Wait! I do have a nickel, don't I?\p"
	.string "Those kids gave it to me earlier!\p"
	.string "I'm basically rich!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_6:
# 171 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Use nickel$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_7:
# 172 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Save nickel$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_8:
# 184 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "It's kinda rusty and misshapen…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_9:
# 189 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Oh well, what's the worst that can\n"
	.string "happen?\p"
	.string "A coin's a coin, right?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_10:
# 197 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "…clunk!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_11:
# 205 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Cheese!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_12:
# 248 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "The hell?!\p"
	.string "The camera… exploded?!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_13:
# 268 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Camera owner$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_14:
# 270 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "What the hell happened?\p"
	.string "Why did you destroy my automatic\n"
	.string "camera?!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_15:
# 281 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Where's my photograph?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_16:
# 282 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "It didn't like my nickel!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_17:
# 288 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "… …You were just trying to have your\n"
	.string "photograph taken?\p"
	.string "Hmm…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_18:
# 293 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I guess maybe using Voltorb as\n"
	.string "electrical components wasn't such a\l"
	.string "great idea after all…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_19:
# 297 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Alright, alright, I'm sorry about this\n"
	.string "whole exploding business.\p"
	.string "Let me give you a brand-new camera as\n"
	.string "an apology.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_20:
# 306 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "You're welcome, kid.\p"
	.string "Please uh, don't tell your parents\n"
	.string "about this, alright?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_21:
# 324 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Hey, at least I got a free camera out\n"
	.string "of this!\p"
	.string "…Wait a minute…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_22:
# 330 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Oh, man, this is just a toy! It doesn't\n"
	.string "take any pictures!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_23:
# 345 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Ugh, the flash works though…\p"
	.string "My eyes… I'm blind…$"

SpindaIsland_Home_Clock1_PhotoHouseDoor_Text_0:
# 375 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "…I can hear tiny explosions through\n"
	.string "the door…$"

SpindaIsland_Home_Clock1_PhotoHouseSign_Text_0:
# 381 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Louis$"

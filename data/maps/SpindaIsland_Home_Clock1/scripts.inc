SpindaIsland_Home_Clock1_MapScripts::
# 4 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 15 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD
# 21 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
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
# 17 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_FAUCET_BROKE, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 18 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 13, METATILE_SpindaIslandSecondary_BrokenFaucetWall, TRUE
	return

SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 22 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	map_script_2 VAR_SPINDA_ISLAND_INTRO_STATE, 2, SpindaIsland_Home_EventScript_MainQuestRecap
	.2byte 0


SpindaIsland_Home_Clock1_HidingBoy::
# 27 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 29 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	faceplayer
# 30 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 31 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_HidingBoy_Text_1, MSGBOX_AUTOCLOSE
# 35 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 36 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 37 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_HidingBoy_Text_3
# 40 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 41 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 43 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_Faucet::
# 47 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 49 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_FAUCET_BROKE, SpindaIsland_Home_Clock1_Faucet_1
# 59 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	hidefollower
# 60 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_TEMP_HIDE_FOLLOWER
# 61 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative UpdateFollowingPokemon
# 62 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 63 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 64 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_1
# 69 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 70 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 72 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 74 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 13, METATILE_SpindaIslandSecondary_BrokenFaucetWall, TRUE
# 75 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 14, METATILE_SpindaIsland_BrokenFaucetGround, FALSE
# 76 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 78 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Clock1_FaucetBreaks
# 80 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_BRICK_BREAK
# 81 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 82 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 84 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SHOCKED
# 85 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 86 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_2
# 90 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 91 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 92 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_3
# 96 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 97 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 99 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 14, METATILE_SpindaIsland_Grass, FALSE
# 100 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 101 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	giveitem ITEM_BROKEN_FAUCET
# 103 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_FAUCET_BROKE
# 104 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	clearflag FLAG_TEMP_HIDE_FOLLOWER
# 105 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative UpdateFollowingPokemon
# 107 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_Faucet_1:
# 50 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 51 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 52 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_0
# 55 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 56 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 57 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_PhotoCamera::
# 112 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 114 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_Clock1_PhotoCamera_2
# 125 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_FACING, DIR_NORTH
	goto_if_ne SpindaIsland_Home_Clock1_PhotoCamera_5
	checkitem ITEM_RUSTY_NICKEL
# 0 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_Clock1_PhotoCamera_9
# 359 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_3
# 363 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 364 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 365 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_4
# 368 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 369 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
SpindaIsland_Home_Clock1_PhotoCamera_8:
# 372 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
SpindaIsland_Home_Clock1_PhotoCamera_4:
# 375 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_PhotoCamera_2:
# 115 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 116 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 117 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_0
# 120 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 121 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	return

SpindaIsland_Home_Clock1_PhotoCamera_5:
# 126 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 127 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 128 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_1
# 131 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 132 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock1_PhotoCamera_4

SpindaIsland_Home_Clock1_PhotoCamera_9:
# 135 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_REALIZED_I_HAVE_NICKEL, SpindaIsland_Home_Clock1_PhotoCamera_13
# 142 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_3
# 146 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 147 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 148 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_4
# 151 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 152 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 154 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_PIN
# 155 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 156 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 157 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 159 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 160 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 161 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_5
# 167 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_REALIZED_I_HAVE_NICKEL
SpindaIsland_Home_Clock1_PhotoCamera_12:
# 170 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Clock1_PhotoCamera_Text_6, SpindaIsland_Home_Clock1_PhotoCamera_Text_7
# 181 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 182 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 184 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SpindaIsland_Home_Clock1_PhotoCamera_16
	goto SpindaIsland_Home_Clock1_PhotoCamera_8

SpindaIsland_Home_Clock1_PhotoCamera_13:
# 136 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 137 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 138 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_2
	goto SpindaIsland_Home_Clock1_PhotoCamera_12

SpindaIsland_Home_Clock1_PhotoCamera_16:
# 185 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_CAMERA_EXPLODED
# 187 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 188 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 189 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_8
# 192 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 193 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 194 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_9
# 198 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 199 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 201 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_VEND
# 202 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_10
# 205 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 206 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 208 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 209 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 210 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_11
# 213 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 214 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 216 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 218 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 219 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 220 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 221 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 222 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 223 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 224 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 20
# 225 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_FAILURE
# 226 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 227 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 20
# 228 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_MEGA_KICK
# 229 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 230 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_EXPLOSION
# 232 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 31, 13, METATILE_SpindaIsland_Grass, FALSE
# 233 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 31, 14, METATILE_SpindaIsland_Grass, FALSE
# 234 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 236 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8004, 1
# 237 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8005, 1
# 238 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8006, 8
# 239 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8007, 5
# 240 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special ShakeCamera
# 242 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Clock1_Movement_ArchieJumps
# 244 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	dofieldeffect FLDEFF_EXPLOSION
# 246 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitfieldeffect FLDEFF_EXPLOSION
# 247 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 0
# 248 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 249 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitstate
# 251 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 252 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SHOCKED
# 253 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_12
# 257 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 258 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 260 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_EXIT
# 261 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	clearflag FLAG_HIDE_PHOTO_MAN
# 262 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	addobject 13
# 263 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 265 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 266 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, SpindaIsland_Home_Clock1_Movement_PhotoManNotice
# 267 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 13
# 269 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, SpindaIsland_Home_Clock1_Movement_PhotoManJump
# 270 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_BIKE_HOP
# 271 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 13
# 272 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 274 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_13
# 275 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_14
# 280 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Clock1_PhotoCamera_Text_15, SpindaIsland_Home_Clock1_PhotoCamera_Text_16
# 290 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 292 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_13
# 293 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_17
# 297 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject 13, DIR_NORTH
# 298 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_18
# 301 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, Common_Movement_FacePlayer
# 302 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 0
# 303 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_19
# 307 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 309 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	giveitem ITEM_TOY_CAMERA
# 311 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_13
# 312 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_20
# 316 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 318 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, SpindaIsland_Home_Clock1_Movement_PhotoManLeave
# 319 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 0
# 320 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_EXIT
# 321 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removeobject 13
# 322 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_HIDE_PHOTO_MAN
# 323 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 325 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 60
# 326 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 328 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 329 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 330 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_21
# 334 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 335 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 336 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_22
# 339 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 340 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 342 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 343 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 344 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_LEER
# 345 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, 0
# 346 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, 0
# 347 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 349 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 350 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_BLIND
# 351 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_23
# 355 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 356 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock1_PhotoCamera_8


SpindaIsland_Home_Clock1_PhotoHouseDoor::
# 379 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 380 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 381 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 382 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoHouseDoor_Text_0
# 383 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 384 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_PhotoHouseSign::
# 388 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoHouseSign_Text_0, MSGBOX_SIGN
	return


# 391 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_PhotoManLeave:
# 392 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_left
# 392 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_left
# 392 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_left
# 393 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	face_up
	step_end

# 396 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_PhotoManNotice:
# 397 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	face_right
# 398 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay_16
# 399 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_right
# 399 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_right
# 399 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_right
# 400 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay_16
	step_end

# 403 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_PhotoManJump:
# 404 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 405 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	jump_in_place_down
# 406 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	unlock_facing_direction
	step_end

# 409 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_ArchieJumps:
# 410 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 411 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	jump_in_place_up
# 412 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	unlock_facing_direction
# 413 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	emote_exclamation_mark
	step_end

# 416 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_FaucetBreaks:
# 417 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 418 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	player_run_down
	step_end

SpindaIsland_Home_Clock1_HidingBoy_Text_0:
# 30 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Timmy$"

SpindaIsland_Home_Clock1_HidingBoy_Text_1:
# 32 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Darnit! You found me!$"

SpindaIsland_Home_Clock1_HidingBoy_Text_2:
# 36 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock1_HidingBoy_Text_3:
# 38 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Wazzup, Timmy?$"

SpindaIsland_Home_Clock1_Faucet_Text_0:
# 53 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Faucet's broken…$"

SpindaIsland_Home_Clock1_Faucet_Text_1:
# 65 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Alrighty, time to turn the big old\n"
	.string "faucet back on!\p"
	.string "Hnng…\p"
	.string "… … … … …$"

SpindaIsland_Home_Clock1_Faucet_Text_2:
# 87 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Aw, Shuckles! It broke!\p"
	.string "Mom is totally gonna kill me!!$"

SpindaIsland_Home_Clock1_Faucet_Text_3:
# 93 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Let's, uh, not tell her anything and\n"
	.string "fix this ourselves!\p"
	.string "I better pocket this, too.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_0:
# 118 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Nothing left but a pile of ashes…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_1:
# 129 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I should probably face the lens if I\n"
	.string "want to take a picture of myself.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_2:
# 139 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I still have that nickel from earlier.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_3:
# 143 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "“GET A PHOTO FOR A NICKEL!”$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_4:
# 149 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Ugh, Rattatas… Don't they know kids\n"
	.string "don't have money?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_5:
# 162 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Wait! I do have a nickel, don't I?\p"
	.string "Those kids gave it to me earlier!\p"
	.string "I'm basically rich!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_6:
# 177 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Use nickel$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_7:
# 178 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Save nickel$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_8:
# 190 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "It's kinda rusty and misshapen…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_9:
# 195 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Oh well, what's the worst that can\n"
	.string "happen?\p"
	.string "A coin's a coin, right?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_10:
# 203 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "…clunk!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_11:
# 211 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Cheese!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_12:
# 254 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "The hell?!\p"
	.string "The camera… exploded?!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_13:
# 274 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Camera owner$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_14:
# 276 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "What the hell happened?\p"
	.string "Why did you destroy my automatic\n"
	.string "camera?!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_15:
# 287 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Where's my photograph?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_16:
# 288 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "It didn't like my nickel!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_17:
# 294 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "… …You were just trying to have your\n"
	.string "photograph taken?\p"
	.string "Hmm…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_18:
# 299 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I guess maybe using Voltorb as\n"
	.string "electrical components wasn't such a\l"
	.string "great idea after all…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_19:
# 304 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Alright, alright, I'm sorry about this\n"
	.string "whole exploding business.\p"
	.string "Let me give you a brand-new camera as\n"
	.string "an apology.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_20:
# 313 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "You're welcome, kid.\p"
	.string "Please uh, don't tell your parents\n"
	.string "about this, alright?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_21:
# 331 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Hey, at least I got a free camera out\n"
	.string "of this!\p"
	.string "…Wait a minute…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_22:
# 337 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Oh, man, this is just a toy! It doesn't\n"
	.string "take any pictures!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_23:
# 352 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Ugh, the flash works though…\p"
	.string "My eyes… I'm blind…$"

SpindaIsland_Home_Clock1_PhotoHouseDoor_Text_0:
# 382 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "…I can hear tiny explosions through\n"
	.string "the door…$"

SpindaIsland_Home_Clock1_PhotoHouseSign_Text_0:
# 388 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Louis$"

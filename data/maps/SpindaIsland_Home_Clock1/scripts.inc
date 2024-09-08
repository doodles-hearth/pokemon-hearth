SpindaIsland_Home_Clock1_MapScripts::
# 4 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 11 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD
# 24 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
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
# 13 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_FAUCET_BROKE, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_2
# 15 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_REPAIRED_FAUCET, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_3
SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 19 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_6
	return

SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 14 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 13, METATILE_SpindaIslandSecondary_BrokenFaucetWall, TRUE
	goto SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_1

SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_3:
# 16 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 13, METATILE_SpindaIslandSecondary_NewFaucetWall, TRUE
	goto SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_1

SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_6:
# 20 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 31, 13, METATILE_SpindaIsland_Grass, FALSE
# 21 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 31, 14, METATILE_SpindaIsland_Grass, FALSE
	return

SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 25 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	map_script_2 VAR_SPINDA_ISLAND_INTRO_STATE, 2, SpindaIsland_Home_EventScript_MainQuestRecap
	.2byte 0


SpindaIsland_Home_Clock1_HidingBoy::
# 30 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 32 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	faceplayer
# 34 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_BOY, EMOTE_NORMAL
# 35 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 36 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_HidingBoy_Text_1, MSGBOX_AUTOCLOSE
# 40 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 41 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 42 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_HidingBoy_Text_3
# 45 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 46 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 48 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_Faucet::
# 52 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 54 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_FAUCET_BROKE, SpindaIsland_Home_Clock1_Faucet_1
# 124 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	hidefollower
# 125 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_TEMP_HIDE_FOLLOWER
# 126 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative UpdateFollowingPokemon
# 127 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 128 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 129 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_5
# 134 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 135 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 137 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 139 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 13, METATILE_SpindaIslandSecondary_BrokenFaucetWall, TRUE
# 140 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 14, METATILE_SpindaIsland_BrokenFaucetGround, FALSE
# 141 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 143 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Clock1_FaucetBreaks
# 145 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_BRICK_BREAK
# 146 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 147 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 149 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SHOCKED
# 150 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 151 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_6
# 155 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 156 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 157 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_7
# 161 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 162 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 164 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 14, METATILE_SpindaIsland_Grass, FALSE
# 165 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 166 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	giveitem ITEM_BROKEN_FAUCET
# 168 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_FAUCET_BROKE
# 169 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	clearflag FLAG_TEMP_HIDE_FOLLOWER
# 170 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative UpdateFollowingPokemon
# 172 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_Faucet_1:
# 55 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_REPAIRED_FAUCET, SpindaIsland_Home_Clock1_Faucet_4
# 63 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_FINISHED, SpindaIsland_Home_Clock1_Faucet_5
# 114 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 115 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 116 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_4
# 119 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 120 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 121 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_Faucet_4:
# 56 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 57 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 58 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_0
# 61 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 62 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
	return

SpindaIsland_Home_Clock1_Faucet_5:
# 64 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 65 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 66 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_1
# 69 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 70 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 72 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removeitem ITEM_NEW_FAUCET
# 74 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 76 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_CLICK
# 77 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 13, METATILE_SpindaIslandSecondary_NewFaucetWall, TRUE
# 78 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 79 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 81 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 83 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 84 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 85 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_2
# 88 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 89 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 91 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_CLICK
# 92 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 93 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 20
# 94 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_CLICK
# 95 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 96 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 20
# 97 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_CLICK
# 98 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 99 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 40
# 101 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 102 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 103 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_3
# 106 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 107 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 109 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_REPAIRED_FAUCET
# 110 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_REPAIRED_FAUCET, 1
# 112 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_PhotoCamera::
# 177 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 179 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_Clock1_PhotoCamera_2
# 190 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_FACING, DIR_NORTH
	goto_if_ne SpindaIsland_Home_Clock1_PhotoCamera_5
	checkitem ITEM_RUSTY_NICKEL
# 0 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_Clock1_PhotoCamera_9
# 430 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_3
# 434 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 435 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 436 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_4
# 439 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 440 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
SpindaIsland_Home_Clock1_PhotoCamera_8:
# 443 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
SpindaIsland_Home_Clock1_PhotoCamera_4:
# 446 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_PhotoCamera_2:
# 180 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 181 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 182 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_0
# 185 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 186 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	return

SpindaIsland_Home_Clock1_PhotoCamera_5:
# 191 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 192 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 193 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_1
# 196 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 197 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock1_PhotoCamera_4

SpindaIsland_Home_Clock1_PhotoCamera_9:
# 200 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_REALIZED_I_HAVE_NICKEL, SpindaIsland_Home_Clock1_PhotoCamera_13
# 207 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_3
# 211 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 212 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 213 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_4
# 216 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 217 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 219 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_PIN
# 220 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 221 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 222 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 224 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 225 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 226 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_5
# 232 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_REALIZED_I_HAVE_NICKEL
SpindaIsland_Home_Clock1_PhotoCamera_12:
# 235 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Clock1_PhotoCamera_Text_6, SpindaIsland_Home_Clock1_PhotoCamera_Text_7
# 246 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 247 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 249 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SpindaIsland_Home_Clock1_PhotoCamera_16
	goto SpindaIsland_Home_Clock1_PhotoCamera_8

SpindaIsland_Home_Clock1_PhotoCamera_13:
# 201 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 202 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 203 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_2
	goto SpindaIsland_Home_Clock1_PhotoCamera_12

SpindaIsland_Home_Clock1_PhotoCamera_16:
# 250 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removeitem ITEM_RUSTY_NICKEL
# 251 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_CAMERA_EXPLODED
# 253 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 254 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 255 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_8
# 258 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 259 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 260 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_9
# 264 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 265 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 267 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_VEND
# 268 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_10
# 271 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 272 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 274 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 275 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 276 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_11
# 279 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 280 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 282 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 284 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 285 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 286 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 287 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 288 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 289 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 290 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 20
# 291 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_FAILURE
# 292 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 293 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 20
# 294 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_MEGA_KICK
# 295 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 296 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_EXPLOSION
# 298 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 31, 13, METATILE_SpindaIsland_Grass, FALSE
# 299 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 31, 14, METATILE_SpindaIsland_Grass, FALSE
# 300 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 302 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8004, 1
# 303 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8005, 1
# 304 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8006, 8
# 305 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8007, 5
# 306 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special ShakeCamera
# 308 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Clock1_Movement_ArchieJumps
# 310 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	dofieldeffect FLDEFF_EXPLOSION
# 312 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitfieldeffect FLDEFF_EXPLOSION
# 313 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 0
# 314 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 315 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitstate
# 317 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 318 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SHOCKED
# 319 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_12
# 323 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 324 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 326 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_EXIT
# 327 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	clearflag FLAG_HIDE_PHOTO_MAN
# 328 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	addobject 13
# 329 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 331 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 332 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, SpindaIsland_Home_Clock1_Movement_PhotoManNotice
# 333 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 13
# 335 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, SpindaIsland_Home_Clock1_Movement_PhotoManJump
# 336 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_BIKE_HOP
# 337 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 13
# 338 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 340 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SAD
# 341 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_13
# 342 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_14
# 347 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Clock1_PhotoCamera_Text_15, SpindaIsland_Home_Clock1_PhotoCamera_Text_16
# 357 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 358 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 360 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 361 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_13
# 362 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_17
# 366 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject 13, DIR_WEST
# 367 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_18
# 370 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, Common_Movement_FacePlayer
# 371 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 0
# 372 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_19
# 376 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 377 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 379 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	giveitem ITEM_TOY_CAMERA
# 381 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 382 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_13
# 383 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_20
# 387 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 388 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 390 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, SpindaIsland_Home_Clock1_Movement_PhotoManLeave
# 391 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 0
# 392 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_EXIT
# 393 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removeobject 13
# 394 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_HIDE_PHOTO_MAN
# 395 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 397 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 60
# 398 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 400 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 401 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 402 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_21
# 406 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 407 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_22
# 410 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 411 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 413 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 414 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 415 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_LEER
# 416 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, 0
# 417 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, 0
# 418 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 420 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 421 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_BLIND
# 422 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_23
# 426 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 427 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock1_PhotoCamera_8


SpindaIsland_Home_Clock1_PhotoHouseDoor::
# 450 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 451 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 452 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 453 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoHouseDoor_Text_0
# 454 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 455 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_PhotoHouseSign::
# 459 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoHouseSign_Text_0, MSGBOX_SIGN
	return


# 462 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_PhotoManLeave:
# 463 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_left
# 463 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_left
# 463 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_left
# 464 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	face_up
	step_end

# 467 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_PhotoManNotice:
# 468 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	face_right
# 469 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay_16
# 470 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_right
# 470 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_right
# 470 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_right
# 471 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay_16
	step_end

# 474 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_PhotoManJump:
# 475 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 476 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	jump_in_place_down
# 477 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	unlock_facing_direction
	step_end

# 480 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_ArchieJumps:
# 481 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 482 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	jump_in_place_up
# 483 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	unlock_facing_direction
# 484 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	emote_exclamation_mark
	step_end

# 487 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_FaucetBreaks:
# 488 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 489 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	player_run_down
	step_end

SpindaIsland_Home_Clock1_EventScript_OldWoman::
# 493 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 494 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	faceplayer
# 495 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_unset FLAG_SHUPPET_QUEST_STARTED, SpindaIsland_Home_Clock1_EventScript_OldWoman_2
# 506 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_unset FLAG_HIDE_SHUPPETS, SpindaIsland_Home_Clock1_EventScript_OldWoman_3
SpindaIsland_Home_Clock1_EventScript_OldWoman_1:
# 517 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_HIDE_SHUPPETS, SpindaIsland_Home_Clock1_EventScript_OldWoman_7
SpindaIsland_Home_Clock1_EventScript_OldWoman_6:
# 574 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_EventScript_OldWoman_2:
# 496 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	faceplayer
# 497 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 498 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_0
# 499 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_1
# 503 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 504 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 505 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_SHUPPET_QUEST_STARTED
	goto SpindaIsland_Home_Clock1_EventScript_OldWoman_1

SpindaIsland_Home_Clock1_EventScript_OldWoman_3:
# 507 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	faceplayer
# 508 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 509 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_0
# 510 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_2
# 513 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 514 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock1_EventScript_OldWoman_1

SpindaIsland_Home_Clock1_EventScript_OldWoman_7:
# 518 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 519 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_0
# 520 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_2
# 523 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 524 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 526 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 527 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 528 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_3
# 531 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 532 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 534 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 535 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_0
# 536 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_4
# 539 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 540 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_5
# 545 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 546 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 548 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	giveitem ITEM_PB_AND_J
# 550 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 551 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_6
# 554 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 555 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 557 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 558 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removeobject VAR_LAST_TALKED
# 559 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_EXIT
# 560 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 561 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_HIDE_OLD_WOMAN
# 563 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 564 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 565 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_7
# 569 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 570 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 572 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_Clock1_EventScript_OldWoman_6


SpindaIsland_Home_Clock1_HidingBoy_Text_0:
# 35 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Timmy$"

SpindaIsland_Home_Clock1_HidingBoy_Text_1:
# 37 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Darnit! You found me!$"

SpindaIsland_Home_Clock1_HidingBoy_Text_2:
# 41 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock1_HidingBoy_Text_3:
# 43 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Wazzup, Timmy?$"

SpindaIsland_Home_Clock1_Faucet_Text_0:
# 59 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Looks even nicer in blue!$"

SpindaIsland_Home_Clock1_Faucet_Text_1:
# 67 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Just need to plug the new faucet in…$"

SpindaIsland_Home_Clock1_Faucet_Text_2:
# 86 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Amazing! Now to turn the water back\n"
	.string "on…$"

SpindaIsland_Home_Clock1_Faucet_Text_3:
# 104 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "All done!! Let's go see mom!$"

SpindaIsland_Home_Clock1_Faucet_Text_4:
# 117 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Faucet's broken…$"

SpindaIsland_Home_Clock1_Faucet_Text_5:
# 130 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Alrighty, time to turn the big old\n"
	.string "faucet back on!\p"
	.string "Hnng…\p"
	.string "… … … … …$"

SpindaIsland_Home_Clock1_Faucet_Text_6:
# 152 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Aw, Shuckles! It broke!\p"
	.string "Mom is totally gonna kill me!!$"

SpindaIsland_Home_Clock1_Faucet_Text_7:
# 158 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Let's, uh, not tell her anything and\n"
	.string "fix this ourselves!\p"
	.string "I better pocket this, too.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_0:
# 183 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Nothing left but a pile of ashes…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_1:
# 194 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I should probably face the lens if I\n"
	.string "want to take a picture of myself.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_2:
# 204 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I still have that nickel from earlier.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_3:
# 208 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "“GET A PHOTO FOR A NICKEL!”$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_4:
# 214 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Ugh, Rattatas… Don't they know kids\n"
	.string "don't have money?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_5:
# 227 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Wait! I do have a nickel, don't I?\p"
	.string "Those kids gave it to me earlier!\p"
	.string "I'm basically rich!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_6:
# 242 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Use nickel$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_7:
# 243 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Save nickel$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_8:
# 256 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "It's kinda rusty and misshapen…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_9:
# 261 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Oh well, what's the worst that can\n"
	.string "happen?\p"
	.string "A coin's a coin, right?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_10:
# 269 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "…clunk!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_11:
# 277 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Cheese!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_12:
# 320 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "The hell?!\p"
	.string "The camera… exploded?!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_13:
# 341 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Camera owner$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_14:
# 343 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "What the hell happened?\p"
	.string "Why did you destroy my automatic\n"
	.string "camera?!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_15:
# 354 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Where's my photograph?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_16:
# 355 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "It didn't like my nickel!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_17:
# 363 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "… …You were just trying to have your\n"
	.string "photograph taken?\p"
	.string "Hmm…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_18:
# 368 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I guess maybe using Voltorb as\n"
	.string "electrical components wasn't such a\l"
	.string "great idea after all…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_19:
# 373 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Alright, alright, I'm sorry about this\n"
	.string "whole exploding business.\p"
	.string "Let me give you a brand-new camera as\n"
	.string "an apology.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_20:
# 384 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "You're welcome, kid.\p"
	.string "Please uh, don't tell your parents\n"
	.string "about this, alright?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_21:
# 403 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Hey, at least I got a free camera out\n"
	.string "of this!\p"
	.string "…Wait a minute…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_22:
# 408 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Oh, man, this is just a toy! It doesn't\n"
	.string "take any pictures!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_23:
# 423 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Ugh, the flash works though…\p"
	.string "My eyes… I'm blind…$"

SpindaIsland_Home_Clock1_PhotoHouseDoor_Text_0:
# 453 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "…I can hear tiny explosions through\n"
	.string "the door…$"

SpindaIsland_Home_Clock1_PhotoHouseSign_Text_0:
# 459 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Louis$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_0:
# 498 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Old woman$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_1:
# 500 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I think my house is haunted. There's\n"
	.string "something living in my attic.\p"
	.string "I don't know what to do…$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_2:
# 511 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Oh, I'm too scared to go back inside…$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_3:
# 529 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Don't worry granny! There were some\n"
	.string "Shuppet in your attic, but I chased\l"
	.string "them away!$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_4:
# 537 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Shuppet, you say?$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_5:
# 541 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "How adorable of you to help out a poor\n"
	.string "old lady…\p"
	.string "How can I repay you?\p"
	.string "You look like you're hungry… Let me\n"
	.string "fix you a little snack!$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_6:
# 552 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Have a good day, child.$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_7:
# 566 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Cool! Lemme pack this up for later.\p"
	.string "Let's hope it doesn't taste like old\n"
	.string "people or something.$"

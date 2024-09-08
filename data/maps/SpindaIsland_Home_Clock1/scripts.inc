SpindaIsland_Home_Clock1_MapScripts::
# 4 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 11 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD
# 28 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
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
	goto_if_set FLAG_REPAIRED_FAUCET, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_2
# 15 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_FAUCET_BROKE, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_3
SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 19 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_7
SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_6:
# 24 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_OPENED_CHEST, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_9
	return

SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 14 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 13, METATILE_SpindaIslandSecondary_NewFaucetWall, TRUE
	goto SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_1

SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_3:
# 16 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 13, METATILE_SpindaIslandSecondary_BrokenFaucetWall, TRUE
	goto SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_1

SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_7:
# 20 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 31, 13, METATILE_SpindaIsland_Grass, FALSE
# 21 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 31, 14, METATILE_SpindaIsland_Grass, FALSE
	goto SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_6

SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_9:
# 25 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 32, 53, METATILE_SpindaIsland_EmptyChestSide, TRUE
	return

SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 29 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	map_script_2 VAR_SPINDA_ISLAND_INTRO_STATE, 2, SpindaIsland_Home_EventScript_MainQuestRecap
	.2byte 0


SpindaIsland_Home_Clock1_HidingBoy::
# 34 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 36 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	faceplayer
# 38 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_BOY, EMOTE_NORMAL
# 39 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 40 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_HidingBoy_Text_1, MSGBOX_AUTOCLOSE
# 44 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 45 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 46 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_HidingBoy_Text_3
# 49 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 50 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 52 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_Faucet::
# 56 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 58 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_FAUCET_BROKE, SpindaIsland_Home_Clock1_Faucet_1
# 128 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	hidefollower
# 129 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_TEMP_HIDE_FOLLOWER
# 130 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative UpdateFollowingPokemon
# 131 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 132 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 133 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_5
# 138 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 139 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 141 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 143 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 13, METATILE_SpindaIslandSecondary_BrokenFaucetWall, TRUE
# 144 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 14, METATILE_SpindaIsland_BrokenFaucetGround, FALSE
# 145 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 147 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Clock1_FaucetBreaks
# 149 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_BRICK_BREAK
# 150 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 151 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 153 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SHOCKED
# 154 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 155 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_6
# 159 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 160 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 161 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_7
# 165 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 166 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 168 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 14, METATILE_SpindaIsland_Grass, FALSE
# 169 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 170 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	giveitem ITEM_BROKEN_FAUCET
# 172 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_FAUCET_BROKE
# 173 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	clearflag FLAG_TEMP_HIDE_FOLLOWER
# 174 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative UpdateFollowingPokemon
# 176 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_Faucet_1:
# 59 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_REPAIRED_FAUCET, SpindaIsland_Home_Clock1_Faucet_4
# 67 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_FINISHED, SpindaIsland_Home_Clock1_Faucet_5
# 118 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 119 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 120 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_4
# 123 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 124 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 125 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_Faucet_4:
# 60 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 61 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 62 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_0
# 65 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 66 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
	return

SpindaIsland_Home_Clock1_Faucet_5:
# 68 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 69 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 70 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_1
# 73 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 74 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 76 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removeitem ITEM_NEW_FAUCET
# 78 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 80 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_CLICK
# 81 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 13, METATILE_SpindaIslandSecondary_NewFaucetWall, TRUE
# 82 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 83 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 85 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 87 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 88 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 89 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_2
# 92 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 93 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 95 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_CLICK
# 96 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 97 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 20
# 98 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_CLICK
# 99 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 100 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 20
# 101 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_CLICK
# 102 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 103 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 40
# 105 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 106 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 107 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_3
# 110 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 111 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 113 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_REPAIRED_FAUCET
# 114 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_REPAIRED_FAUCET, 1
# 116 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_PhotoCamera::
# 181 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 183 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_Clock1_PhotoCamera_2
# 194 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_FACING, DIR_NORTH
	goto_if_ne SpindaIsland_Home_Clock1_PhotoCamera_5
	checkitem ITEM_RUSTY_NICKEL
# 0 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_Clock1_PhotoCamera_9
# 434 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_3
# 438 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 439 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 440 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_4
# 443 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 444 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
SpindaIsland_Home_Clock1_PhotoCamera_8:
# 447 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
SpindaIsland_Home_Clock1_PhotoCamera_4:
# 450 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_PhotoCamera_2:
# 184 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 185 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 186 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_0
# 189 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 190 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	return

SpindaIsland_Home_Clock1_PhotoCamera_5:
# 195 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 196 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 197 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_1
# 200 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 201 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock1_PhotoCamera_4

SpindaIsland_Home_Clock1_PhotoCamera_9:
# 204 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_REALIZED_I_HAVE_NICKEL, SpindaIsland_Home_Clock1_PhotoCamera_13
# 211 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_3
# 215 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 216 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 217 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_4
# 220 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 221 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 223 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_PIN
# 224 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 225 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 226 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 228 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 229 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 230 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_5
# 236 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_REALIZED_I_HAVE_NICKEL
SpindaIsland_Home_Clock1_PhotoCamera_12:
# 239 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Clock1_PhotoCamera_Text_6, SpindaIsland_Home_Clock1_PhotoCamera_Text_7
# 250 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 251 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 253 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SpindaIsland_Home_Clock1_PhotoCamera_16
	goto SpindaIsland_Home_Clock1_PhotoCamera_8

SpindaIsland_Home_Clock1_PhotoCamera_13:
# 205 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 206 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 207 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_2
	goto SpindaIsland_Home_Clock1_PhotoCamera_12

SpindaIsland_Home_Clock1_PhotoCamera_16:
# 254 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removeitem ITEM_RUSTY_NICKEL
# 255 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_CAMERA_EXPLODED
# 257 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 258 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 259 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_8
# 262 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 263 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 264 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_9
# 268 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 269 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 271 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_VEND
# 272 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_10
# 275 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 276 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 278 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 279 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 280 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_11
# 283 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 284 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 286 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 288 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 289 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 290 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 291 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 292 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 293 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 294 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 20
# 295 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_FAILURE
# 296 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 297 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 20
# 298 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_MEGA_KICK
# 299 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 300 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_EXPLOSION
# 302 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 31, 13, METATILE_SpindaIsland_Grass, FALSE
# 303 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 31, 14, METATILE_SpindaIsland_Grass, FALSE
# 304 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 306 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8004, 1
# 307 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8005, 1
# 308 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8006, 8
# 309 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8007, 5
# 310 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special ShakeCamera
# 312 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Clock1_Movement_ArchieJumps
# 314 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	dofieldeffect FLDEFF_EXPLOSION
# 316 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitfieldeffect FLDEFF_EXPLOSION
# 317 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 0
# 318 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 319 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitstate
# 321 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 322 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SHOCKED
# 323 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_12
# 327 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 328 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 330 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_EXIT
# 331 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	clearflag FLAG_HIDE_PHOTO_MAN
# 332 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	addobject 13
# 333 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 335 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 336 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, SpindaIsland_Home_Clock1_Movement_PhotoManNotice
# 337 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 13
# 339 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, SpindaIsland_Home_Clock1_Movement_PhotoManJump
# 340 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_BIKE_HOP
# 341 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 13
# 342 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 344 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SAD
# 345 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_13
# 346 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_14
# 351 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Clock1_PhotoCamera_Text_15, SpindaIsland_Home_Clock1_PhotoCamera_Text_16
# 361 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 362 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 364 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 365 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_13
# 366 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_17
# 370 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject 13, DIR_WEST
# 371 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_18
# 374 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, Common_Movement_FacePlayer
# 375 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 0
# 376 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_19
# 380 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 381 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 383 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	giveitem ITEM_TOY_CAMERA
# 385 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 386 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_13
# 387 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_20
# 391 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 392 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 394 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, SpindaIsland_Home_Clock1_Movement_PhotoManLeave
# 395 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 0
# 396 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_EXIT
# 397 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removeobject 13
# 398 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_HIDE_PHOTO_MAN
# 399 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 401 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 60
# 402 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 404 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 405 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 406 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_21
# 410 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 411 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_22
# 414 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 415 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 417 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 418 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 419 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_LEER
# 420 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, 0
# 421 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, 0
# 422 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 424 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 425 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_BLIND
# 426 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_23
# 430 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 431 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock1_PhotoCamera_8


SpindaIsland_Home_Clock1_PhotoHouseDoor::
# 454 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 455 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 456 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 457 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoHouseDoor_Text_0
# 458 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 459 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_PhotoHouseSign::
# 463 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoHouseSign_Text_0, MSGBOX_SIGN
	return


# 466 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_PhotoManLeave:
# 467 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_left
# 467 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_left
# 467 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_left
# 468 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	face_up
	step_end

# 471 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_PhotoManNotice:
# 472 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	face_right
# 473 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay_16
# 474 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_right
# 474 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_right
# 474 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_right
# 475 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay_16
	step_end

# 478 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_PhotoManJump:
# 479 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 480 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	jump_in_place_down
# 481 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	unlock_facing_direction
	step_end

# 484 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_ArchieJumps:
# 485 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 486 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	jump_in_place_up
# 487 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	unlock_facing_direction
# 488 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	emote_exclamation_mark
	step_end

# 491 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_FaucetBreaks:
# 492 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 493 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	player_run_down
	step_end

SpindaIsland_Home_Clock1_EventScript_OldWoman::
# 497 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 498 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	faceplayer
# 499 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_unset FLAG_SHUPPET_QUEST_STARTED, SpindaIsland_Home_Clock1_EventScript_OldWoman_2
# 510 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_unset FLAG_HIDE_SHUPPETS, SpindaIsland_Home_Clock1_EventScript_OldWoman_3
SpindaIsland_Home_Clock1_EventScript_OldWoman_1:
# 521 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_HIDE_SHUPPETS, SpindaIsland_Home_Clock1_EventScript_OldWoman_7
SpindaIsland_Home_Clock1_EventScript_OldWoman_6:
# 578 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_EventScript_OldWoman_2:
# 500 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	faceplayer
# 501 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 502 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_0
# 503 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_1
# 507 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 508 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 509 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_SHUPPET_QUEST_STARTED
	goto SpindaIsland_Home_Clock1_EventScript_OldWoman_1

SpindaIsland_Home_Clock1_EventScript_OldWoman_3:
# 511 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	faceplayer
# 512 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 513 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_0
# 514 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_2
# 517 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 518 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock1_EventScript_OldWoman_1

SpindaIsland_Home_Clock1_EventScript_OldWoman_7:
# 522 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 523 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_0
# 524 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_2
# 527 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 528 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 530 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 531 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 532 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_3
# 535 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 536 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 538 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 539 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_0
# 540 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_4
# 543 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 544 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_5
# 549 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 550 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 552 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	giveitem ITEM_PB_AND_J
# 554 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 555 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_6
# 558 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 559 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 561 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 562 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removeobject VAR_LAST_TALKED
# 563 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_EXIT
# 564 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 565 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_HIDE_OLD_WOMAN
# 567 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 568 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 569 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_7
# 573 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 574 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 576 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_Clock1_EventScript_OldWoman_6


SpindaIsland_Home_Clock1_HidingBoy_Text_0:
# 39 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Timmy$"

SpindaIsland_Home_Clock1_HidingBoy_Text_1:
# 41 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Darnit! You found me!$"

SpindaIsland_Home_Clock1_HidingBoy_Text_2:
# 45 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock1_HidingBoy_Text_3:
# 47 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Wazzup, Timmy?$"

SpindaIsland_Home_Clock1_Faucet_Text_0:
# 63 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Looks even nicer in blue!$"

SpindaIsland_Home_Clock1_Faucet_Text_1:
# 71 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Just need to plug the new faucet in…$"

SpindaIsland_Home_Clock1_Faucet_Text_2:
# 90 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Amazing! Now to turn the water back\n"
	.string "on…$"

SpindaIsland_Home_Clock1_Faucet_Text_3:
# 108 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "All done!! Let's go see mom!$"

SpindaIsland_Home_Clock1_Faucet_Text_4:
# 121 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Faucet's broken…$"

SpindaIsland_Home_Clock1_Faucet_Text_5:
# 134 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Alrighty, time to turn the big old\n"
	.string "faucet back on!\p"
	.string "Hnng…\p"
	.string "… … … … …$"

SpindaIsland_Home_Clock1_Faucet_Text_6:
# 156 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Aw, Shuckles! It broke!\p"
	.string "Mom is totally gonna kill me!!$"

SpindaIsland_Home_Clock1_Faucet_Text_7:
# 162 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Let's, uh, not tell her anything and\n"
	.string "fix this ourselves!\p"
	.string "I better pocket this, too.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_0:
# 187 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Nothing left but a pile of ashes…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_1:
# 198 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I should probably face the lens if I\n"
	.string "want to take a picture of myself.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_2:
# 208 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I still have that nickel from earlier.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_3:
# 212 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "“GET A PHOTO FOR A NICKEL!”$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_4:
# 218 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Ugh, Rattatas… Don't they know kids\n"
	.string "don't have money?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_5:
# 231 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Wait! I do have a nickel, don't I?\p"
	.string "Those kids gave it to me earlier!\p"
	.string "I'm basically rich!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_6:
# 246 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Use nickel$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_7:
# 247 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Save nickel$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_8:
# 260 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "It's kinda rusty and misshapen…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_9:
# 265 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Oh well, what's the worst that can\n"
	.string "happen?\p"
	.string "A coin's a coin, right?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_10:
# 273 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "…clunk!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_11:
# 281 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Cheese!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_12:
# 324 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "The hell?!\p"
	.string "The camera… exploded?!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_13:
# 345 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Camera owner$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_14:
# 347 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "What the hell happened?\p"
	.string "Why did you destroy my automatic\n"
	.string "camera?!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_15:
# 358 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Where's my photograph?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_16:
# 359 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "It didn't like my nickel!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_17:
# 367 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "… …You were just trying to have your\n"
	.string "photograph taken?\p"
	.string "Hmm…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_18:
# 372 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I guess maybe using Voltorb as\n"
	.string "electrical components wasn't such a\l"
	.string "great idea after all…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_19:
# 377 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Alright, alright, I'm sorry about this\n"
	.string "whole exploding business.\p"
	.string "Let me give you a brand-new camera as\n"
	.string "an apology.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_20:
# 388 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "You're welcome, kid.\p"
	.string "Please uh, don't tell your parents\n"
	.string "about this, alright?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_21:
# 407 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Hey, at least I got a free camera out\n"
	.string "of this!\p"
	.string "…Wait a minute…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_22:
# 412 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Oh, man, this is just a toy! It doesn't\n"
	.string "take any pictures!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_23:
# 427 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Ugh, the flash works though…\p"
	.string "My eyes… I'm blind…$"

SpindaIsland_Home_Clock1_PhotoHouseDoor_Text_0:
# 457 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "…I can hear tiny explosions through\n"
	.string "the door…$"

SpindaIsland_Home_Clock1_PhotoHouseSign_Text_0:
# 463 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Louis$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_0:
# 502 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Old woman$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_1:
# 504 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I think my house is haunted. There's\n"
	.string "something living in my attic.\p"
	.string "I don't know what to do…$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_2:
# 515 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Oh, I'm too scared to go back inside…$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_3:
# 533 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Don't worry granny! There were some\n"
	.string "Shuppet in your attic, but I chased\l"
	.string "them away!$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_4:
# 541 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Shuppet, you say?$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_5:
# 545 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "How adorable of you to help out a poor\n"
	.string "old lady…\p"
	.string "How can I repay you?\p"
	.string "You look like you're hungry… Let me\n"
	.string "fix you a little snack!$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_6:
# 556 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Have a good day, child.$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_7:
# 570 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Cool! Lemme pack this up for later.\p"
	.string "Let's hope it doesn't taste like old\n"
	.string "people or something.$"

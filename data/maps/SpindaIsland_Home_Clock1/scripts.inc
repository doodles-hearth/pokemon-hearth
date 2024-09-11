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
# 35 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	faceplayer
# 37 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 38 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 39 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_HidingBoy_Text_1
# 42 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 43 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 45 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_unset FLAG_TIMMY, SpindaIsland_Home_Clock1_HidingBoy_2
SpindaIsland_Home_Clock1_HidingBoy_1:
# 55 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_HidingBoy_2:
# 46 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_TIMMY
# 47 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_LITTLE_BOY, EMOTE_NORMAL
# 48 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 49 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_HidingBoy_Text_3, MSGBOX_AUTOCLOSE
	goto SpindaIsland_Home_Clock1_HidingBoy_1


SpindaIsland_Home_Clock1_Faucet::
# 59 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 61 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_FAUCET_BROKE, SpindaIsland_Home_Clock1_Faucet_1
# 131 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	hidefollower
# 132 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_TEMP_HIDE_FOLLOWER
# 133 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative UpdateFollowingPokemon
# 134 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 135 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 136 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_5
# 141 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 142 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 144 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 146 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 13, METATILE_SpindaIslandSecondary_BrokenFaucetWall, TRUE
# 147 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 14, METATILE_SpindaIsland_BrokenFaucetGround, FALSE
# 148 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 150 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Clock1_FaucetBreaks
# 152 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_BRICK_BREAK
# 153 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 154 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 156 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SHOCKED
# 157 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 158 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_6
# 162 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 163 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 164 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_7
# 168 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 169 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 171 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 14, METATILE_SpindaIsland_Grass, FALSE
# 172 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 173 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	giveitem ITEM_BROKEN_FAUCET
# 175 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_FAUCET_BROKE
# 176 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	clearflag FLAG_TEMP_HIDE_FOLLOWER
# 177 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative UpdateFollowingPokemon
# 179 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_Faucet_1:
# 62 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_REPAIRED_FAUCET, SpindaIsland_Home_Clock1_Faucet_4
# 70 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_FINISHED, SpindaIsland_Home_Clock1_Faucet_5
# 121 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 122 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 123 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_4
# 126 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 127 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 128 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_Faucet_4:
# 63 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 64 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 65 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_0
# 68 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 69 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
	return

SpindaIsland_Home_Clock1_Faucet_5:
# 71 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 72 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 73 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_1
# 76 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 77 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 79 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removeitem ITEM_NEW_FAUCET
# 81 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 83 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_CLICK
# 84 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 13, METATILE_SpindaIslandSecondary_NewFaucetWall, TRUE
# 85 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 86 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 88 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 90 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 91 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 92 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_2
# 95 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 96 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
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
	delay 20
# 104 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_CLICK
# 105 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 106 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 40
# 108 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 109 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 110 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_3
# 113 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 114 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 116 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_REPAIRED_FAUCET
# 117 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_REPAIRED_FAUCET, 1
# 119 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_PhotoCamera::
# 184 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 186 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_CAMERA_EXPLODED, SpindaIsland_Home_Clock1_PhotoCamera_2
# 197 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_FACING, DIR_NORTH
	goto_if_ne SpindaIsland_Home_Clock1_PhotoCamera_5
	checkitem ITEM_RUSTY_NICKEL
# 0 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne SpindaIsland_Home_Clock1_PhotoCamera_9
# 437 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_3
# 441 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 442 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 443 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_4
# 446 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 447 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
SpindaIsland_Home_Clock1_PhotoCamera_8:
# 450 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
SpindaIsland_Home_Clock1_PhotoCamera_4:
# 453 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_PhotoCamera_2:
# 187 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 188 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 189 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_0
# 192 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 193 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	return

SpindaIsland_Home_Clock1_PhotoCamera_5:
# 198 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 199 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 200 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_1
# 203 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 204 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock1_PhotoCamera_4

SpindaIsland_Home_Clock1_PhotoCamera_9:
# 207 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_REALIZED_I_HAVE_NICKEL, SpindaIsland_Home_Clock1_PhotoCamera_13
# 214 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_3
# 218 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 219 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 220 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_4
# 223 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 224 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 226 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_PIN
# 227 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 228 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 229 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 231 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 232 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 233 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_5
# 239 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_REALIZED_I_HAVE_NICKEL
SpindaIsland_Home_Clock1_PhotoCamera_12:
# 242 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Clock1_PhotoCamera_Text_6, SpindaIsland_Home_Clock1_PhotoCamera_Text_7
# 253 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 254 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 256 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SpindaIsland_Home_Clock1_PhotoCamera_16
	goto SpindaIsland_Home_Clock1_PhotoCamera_8

SpindaIsland_Home_Clock1_PhotoCamera_13:
# 208 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 209 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 210 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_2
	goto SpindaIsland_Home_Clock1_PhotoCamera_12

SpindaIsland_Home_Clock1_PhotoCamera_16:
# 257 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removeitem ITEM_RUSTY_NICKEL
# 258 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_CAMERA_EXPLODED
# 260 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 261 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 262 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_8
# 265 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 266 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 267 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_9
# 271 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 272 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 274 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_VEND
# 275 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_10
# 278 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 279 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 281 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 282 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 283 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_11
# 286 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 287 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 289 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 291 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 292 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 293 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 294 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 295 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 296 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 297 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 20
# 298 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_FAILURE
# 299 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 300 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 20
# 301 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_MEGA_KICK
# 302 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 303 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_EXPLOSION
# 305 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 31, 13, METATILE_SpindaIsland_Grass, FALSE
# 306 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 31, 14, METATILE_SpindaIsland_Grass, FALSE
# 307 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 309 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8004, 1
# 310 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8005, 1
# 311 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8006, 8
# 312 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8007, 5
# 313 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special ShakeCamera
# 315 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Clock1_Movement_ArchieJumps
# 317 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	dofieldeffect FLDEFF_EXPLOSION
# 319 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitfieldeffect FLDEFF_EXPLOSION
# 320 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 0
# 321 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 322 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitstate
# 324 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 325 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SHOCKED
# 326 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_12
# 330 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 331 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 333 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_EXIT
# 334 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	clearflag FLAG_HIDE_PHOTO_MAN
# 335 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	addobject 13
# 336 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 338 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 339 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, SpindaIsland_Home_Clock1_Movement_PhotoManNotice
# 340 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 13
# 342 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, SpindaIsland_Home_Clock1_Movement_PhotoManJump
# 343 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_BIKE_HOP
# 344 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 13
# 345 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 347 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_SAD
# 348 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_13
# 349 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_14
# 354 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_Clock1_PhotoCamera_Text_15, SpindaIsland_Home_Clock1_PhotoCamera_Text_16
# 364 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 365 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 367 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 368 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_13
# 369 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_17
# 373 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject 13, DIR_WEST
# 374 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_18
# 377 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, Common_Movement_FacePlayer
# 378 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 0
# 379 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_19
# 383 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 384 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 386 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	giveitem ITEM_TOY_CAMERA
# 388 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 389 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_PhotoCamera_Text_13
# 390 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_20
# 394 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 395 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 397 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement 13, SpindaIsland_Home_Clock1_Movement_PhotoManLeave
# 398 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement 0
# 399 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_EXIT
# 400 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removeobject 13
# 401 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_HIDE_PHOTO_MAN
# 402 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 404 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 60
# 405 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 407 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 408 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 409 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_21
# 413 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 414 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_22
# 417 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 418 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 420 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_SWITCH
# 421 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 422 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_LEER
# 423 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, 0
# 424 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, 0
# 425 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 427 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 428 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_BLIND
# 429 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoCamera_Text_23
# 433 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 434 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock1_PhotoCamera_8


SpindaIsland_Home_Clock1_PhotoHouseDoor::
# 457 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 458 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 459 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_THINKING
# 460 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoHouseDoor_Text_0
# 461 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 462 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_PhotoHouseSign::
# 466 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_PhotoHouseSign_Text_0, MSGBOX_SIGN
	return


# 469 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_PhotoManLeave:
# 470 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_left
# 470 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_left
# 470 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_left
# 471 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	face_up
	step_end

# 474 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_PhotoManNotice:
# 475 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	face_right
# 476 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay_16
# 477 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_right
# 477 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_right
# 477 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	walk_right
# 478 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay_16
	step_end

# 481 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_PhotoManJump:
# 482 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 483 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	jump_in_place_down
# 484 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	unlock_facing_direction
	step_end

# 487 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_Movement_ArchieJumps:
# 488 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 489 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	jump_in_place_up
# 490 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	unlock_facing_direction
# 491 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	emote_exclamation_mark
	step_end

# 494 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_FaucetBreaks:
# 495 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 496 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	player_run_down
	step_end

SpindaIsland_Home_Clock1_EventScript_OldWoman::
# 500 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 501 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	faceplayer
# 502 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_unset FLAG_SHUPPET_QUEST_STARTED, SpindaIsland_Home_Clock1_EventScript_OldWoman_2
# 513 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_unset FLAG_HIDE_SHUPPETS, SpindaIsland_Home_Clock1_EventScript_OldWoman_3
SpindaIsland_Home_Clock1_EventScript_OldWoman_1:
# 524 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_HIDE_SHUPPETS, SpindaIsland_Home_Clock1_EventScript_OldWoman_7
SpindaIsland_Home_Clock1_EventScript_OldWoman_6:
# 581 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_EventScript_OldWoman_2:
# 503 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	faceplayer
# 504 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 505 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_0
# 506 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_1
# 510 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 511 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 512 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_SHUPPET_QUEST_STARTED
	goto SpindaIsland_Home_Clock1_EventScript_OldWoman_1

SpindaIsland_Home_Clock1_EventScript_OldWoman_3:
# 514 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	faceplayer
# 515 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 516 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_0
# 517 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_2
# 520 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 521 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
	goto SpindaIsland_Home_Clock1_EventScript_OldWoman_1

SpindaIsland_Home_Clock1_EventScript_OldWoman_7:
# 525 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 526 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_0
# 527 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_2
# 530 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 531 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 533 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 534 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 535 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_3
# 538 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 539 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 541 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_NORMAL
# 542 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_0
# 543 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_4
# 546 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 547 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_5
# 552 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 553 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 555 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	giveitem ITEM_PB_AND_J
# 557 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_GRANDMA, EMOTE_HAPPY
# 558 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_6
# 561 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 562 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 564 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 565 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removeobject VAR_LAST_TALKED
# 566 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_EXIT
# 567 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 568 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_HIDE_OLD_WOMAN
# 570 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 571 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 572 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_7
# 576 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 577 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 579 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	call SpindaIsland_Common_CheckGotAllItemsForNewFaucet
	goto SpindaIsland_Home_Clock1_EventScript_OldWoman_6


SpindaIsland_Home_Clock1_HidingBoy_Text_0:
# 38 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock1_HidingBoy_Text_1:
# 40 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Wazzup, Timmy?$"

SpindaIsland_Home_Clock1_HidingBoy_Text_2:
# 48 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Timmy$"

SpindaIsland_Home_Clock1_HidingBoy_Text_3:
# 50 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Darnit! You found me!\p"
	.string "Didn't expect you to spin around like\n"
	.string "this!$"

SpindaIsland_Home_Clock1_Faucet_Text_0:
# 66 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Looks even nicer in blue!$"

SpindaIsland_Home_Clock1_Faucet_Text_1:
# 74 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Just need to plug the new faucet in…$"

SpindaIsland_Home_Clock1_Faucet_Text_2:
# 93 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Amazing! Now to turn the water back\n"
	.string "on…$"

SpindaIsland_Home_Clock1_Faucet_Text_3:
# 111 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "All done!! Let's go see mom!$"

SpindaIsland_Home_Clock1_Faucet_Text_4:
# 124 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Faucet's broken…$"

SpindaIsland_Home_Clock1_Faucet_Text_5:
# 137 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Alrighty, time to turn the big old\n"
	.string "faucet back on!\p"
	.string "Hnng…\p"
	.string "… … … … …$"

SpindaIsland_Home_Clock1_Faucet_Text_6:
# 159 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Aw, Shuckles! It broke!\p"
	.string "Mom is totally gonna kill me!!$"

SpindaIsland_Home_Clock1_Faucet_Text_7:
# 165 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Let's, uh, not tell her anything and\n"
	.string "fix this ourselves!\p"
	.string "I better pocket this, too.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_0:
# 190 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Nothing left but a pile of ashes…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_1:
# 201 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I should probably face the lens if I\n"
	.string "want to take a picture of myself.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_2:
# 211 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I still have that nickel from earlier.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_3:
# 215 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "“GET A PHOTO FOR A NICKEL!”$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_4:
# 221 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Ugh, Rattatas… Don't they know kids\n"
	.string "don't have money?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_5:
# 234 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Wait! I do have a nickel, don't I?\p"
	.string "Those kids gave it to me earlier!\p"
	.string "I'm basically rich!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_6:
# 249 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Use nickel$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_7:
# 250 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Save nickel$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_8:
# 263 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "It's kinda rusty and misshapen…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_9:
# 268 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Oh well, what's the worst that can\n"
	.string "happen?\p"
	.string "A coin's a coin, right?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_10:
# 276 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "…clunk!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_11:
# 284 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Cheese!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_12:
# 327 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "The hell?!\p"
	.string "The camera… exploded?!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_13:
# 348 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Camera owner$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_14:
# 350 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "What the hell happened?\p"
	.string "Why did you destroy my automatic\n"
	.string "camera?!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_15:
# 361 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Where's my photograph?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_16:
# 362 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "It didn't like my nickel!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_17:
# 370 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "… …You were just trying to have your\n"
	.string "photograph taken?\p"
	.string "Hmm…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_18:
# 375 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I guess maybe using Voltorb as\n"
	.string "electrical components wasn't such a\l"
	.string "great idea after all…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_19:
# 380 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Alright, alright, I'm sorry about this\n"
	.string "whole exploding business.\p"
	.string "Let me give you a brand-new camera as\n"
	.string "an apology.$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_20:
# 391 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "You're welcome, kid.\p"
	.string "Please uh, don't tell your parents\n"
	.string "about this, alright?$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_21:
# 410 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Hey, at least I got a free camera out\n"
	.string "of this!\p"
	.string "…Wait a minute…$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_22:
# 415 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Oh, man, this is just a toy! It doesn't\n"
	.string "take any pictures!$"

SpindaIsland_Home_Clock1_PhotoCamera_Text_23:
# 430 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Ugh, the flash works though…\p"
	.string "My eyes… I'm blind…$"

SpindaIsland_Home_Clock1_PhotoHouseDoor_Text_0:
# 460 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "…I can hear tiny explosions through\n"
	.string "the door…$"

SpindaIsland_Home_Clock1_PhotoHouseSign_Text_0:
# 466 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Louis$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_0:
# 505 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Old woman$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_1:
# 507 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "I think my house is haunted. There's\n"
	.string "something living in my attic.\p"
	.string "I don't know what to do…$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_2:
# 518 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Oh, I'm too scared to go back inside…$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_3:
# 536 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Don't worry granny! There were some\n"
	.string "Shuppet in your attic, but I chased\l"
	.string "them away!$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_4:
# 544 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Shuppet, you say?$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_5:
# 548 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "How adorable of you to help out a poor\n"
	.string "old lady…\p"
	.string "How can I repay you?\p"
	.string "You look like you're hungry… Let me\n"
	.string "fix you a little snack!$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_6:
# 559 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Have a good day, child.$"

SpindaIsland_Home_Clock1_EventScript_OldWoman_Text_7:
# 573 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Cool! Lemme pack this up for later.\p"
	.string "Let's hope it doesn't taste like old\n"
	.string "people or something.$"

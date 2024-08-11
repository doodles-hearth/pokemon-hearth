SpindaIsland_Home_Clock1_MapScripts::
# 2 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD:
# 4 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	goto_if_set FLAG_FAUCET_BROKE, SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

SpindaIsland_Home_Clock1_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 5 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 20, 8, METATILE_SpindaIslandSecondary_BrokenFaucetWall, TRUE
	return


SpindaIsland_Home_Clock1_HidingBoy::
# 11 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 13 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	faceplayer
# 14 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 15 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_HidingBoy_Text_1, MSGBOX_AUTOCLOSE
# 19 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 20 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 21 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_HidingBoy_Text_3
# 24 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 25 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 27 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_Faucet::
# 32 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_SPINDA_ISLAND_INTRO_STATE, 2
	goto_if_gt SpindaIsland_Home_Clock1_Faucet_1
# 42 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_SPINDA_ISLAND_INTRO_STATE, 2
	goto_if_eq SpindaIsland_Home_Clock1_Faucet_2
	return

SpindaIsland_Home_Clock1_Faucet_1:
# 33 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 34 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 35 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 36 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_0
# 39 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 40 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 41 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_Faucet_2:
# 43 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	hidefollower
# 44 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 45 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 46 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 47 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_1
# 52 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 53 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 55 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 57 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 13, METATILE_SpindaIslandSecondary_BrokenFaucetWall, TRUE
# 58 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 14, METATILE_SpindaIslandSecondary_BrokenFaucetGround, FALSE
# 59 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 61 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Clock1_FaucetBreaks
# 63 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_BRICK_BREAK
# 67 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 68 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 70 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 71 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 72 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_2
# 78 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 79 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	removefieldmugshot
# 81 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 18, 14, METATILE_SpindaIsland_Grass, FALSE
# 82 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 83 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	giveitem ITEM_BROKEN_FAUCET
# 85 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 3
# 86 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_FAUCET_BROKE
# 88 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


# 92 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_FaucetBreaks:
# 93 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 94 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	player_run_down
	step_end

SpindaIsland_Home_Clock1_HidingBoy_Text_0:
# 14 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Timmy$"

SpindaIsland_Home_Clock1_HidingBoy_Text_1:
# 16 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Darnit! You found me!$"

SpindaIsland_Home_Clock1_HidingBoy_Text_2:
# 20 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock1_HidingBoy_Text_3:
# 22 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Wazzup, Timmy?$"

SpindaIsland_Home_Clock1_Faucet_Text_0:
# 37 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Faucet's broken…$"

SpindaIsland_Home_Clock1_Faucet_Text_1:
# 48 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Alrighty, time to turn the big old\n"
	.string "faucet back on!\p"
	.string "Hnng…\p"
	.string "… … … … …$"

SpindaIsland_Home_Clock1_Faucet_Text_2:
# 73 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Aw, Shuckles! It broke!\p"
	.string "Mom is totally gonna kill me!!\p"
	.string "Let's, uh, not tell her anything and\n"
	.string "fix this ourselves!\p"
	.string "I better pocket this, too.$"

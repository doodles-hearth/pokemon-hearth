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
	setvar VAR_0x8000, MUGSHOT_ARCHIE_HAPPY
# 20 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative DrawMugshot
# 21 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 22 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_HidingBoy_Text_3
# 25 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 26 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative ClearMugshot
# 28 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_Faucet::
# 33 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_SPINDA_ISLAND_INTRO_STATE, 2
	goto_if_gt SpindaIsland_Home_Clock1_Faucet_1
# 44 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_SPINDA_ISLAND_INTRO_STATE, 2
	goto_if_eq SpindaIsland_Home_Clock1_Faucet_2
	return

SpindaIsland_Home_Clock1_Faucet_1:
# 34 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 35 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 36 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative DrawMugshot
# 37 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 38 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_0
# 41 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 42 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative ClearMugshot
# 43 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_Faucet_2:
# 45 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	hidefollower
# 46 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 47 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 48 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative DrawMugshot
# 49 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 50 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_1
# 55 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 56 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative ClearMugshot
# 58 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 60 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 20, 8, METATILE_SpindaIslandSecondary_BrokenFaucetWall, TRUE
# 61 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 20, 9, METATILE_SpindaIslandSecondary_BrokenFaucetGround, FALSE
# 62 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 64 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Clock1_FaucetBreaks
# 66 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_BRICK_BREAK
# 70 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 71 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 73 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 74 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative DrawMugshot
# 75 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 76 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_2
# 82 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 83 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative ClearMugshot
# 85 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 20, 9, METATILE_SpindaIsland_Grass, FALSE
# 86 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 87 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	giveitem ITEM_BROKEN_FAUCET
# 89 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 3
# 90 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_FAUCET_BROKE
# 92 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


# 96 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_FaucetBreaks:
# 97 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 98 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	player_run_down
	step_end

SpindaIsland_Home_Clock1_HidingBoy_Text_0:
# 14 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Timmy$"

SpindaIsland_Home_Clock1_HidingBoy_Text_1:
# 16 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Darnit! You found me!$"

SpindaIsland_Home_Clock1_HidingBoy_Text_2:
# 21 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock1_HidingBoy_Text_3:
# 23 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Wazzup, Timmy?$"

SpindaIsland_Home_Clock1_Faucet_Text_0:
# 39 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Faucet's broken…$"

SpindaIsland_Home_Clock1_Faucet_Text_1:
# 51 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Alrighty, time to turn the big old\n"
	.string "faucet back on!\p"
	.string "Hnng…\p"
	.string "… … … … …$"

SpindaIsland_Home_Clock1_Faucet_Text_2:
# 77 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Aw, Shuckles! It broke!\p"
	.string "Mom is totally gonna kill me!!\p"
	.string "Let's, uh, not tell her anything and\n"
	.string "fix this ourselves!\p"
	.string "I better pocket this, too.$"

SpindaIsland_Home_Clock1_MapScripts::
	.byte 0


SpindaIsland_Home_Clock1_HidingBoy::
# 6 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 8 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	faceplayer
# 9 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 10 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_HidingBoy_Text_1, MSGBOX_AUTOCLOSE
# 14 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE_HAPPY
# 15 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative DrawMugshot
# 16 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 17 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_HidingBoy_Text_3
# 20 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 21 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative ClearMugshot
# 23 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_Faucet::
# 28 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_SPINDA_ISLAND_INTRO_STATE, 2
	goto_if_gt SpindaIsland_Home_Clock1_Faucet_1
# 39 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	compare VAR_SPINDA_ISLAND_INTRO_STATE, 2
	goto_if_eq SpindaIsland_Home_Clock1_Faucet_2
	return

SpindaIsland_Home_Clock1_Faucet_1:
# 29 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 30 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 31 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative DrawMugshot
# 32 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 33 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_0
# 36 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 37 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative ClearMugshot
# 38 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return

SpindaIsland_Home_Clock1_Faucet_2:
# 40 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	hidefollower
# 41 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 42 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 43 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative DrawMugshot
# 44 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 45 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_1
# 50 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 51 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative ClearMugshot
# 53 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 55 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 20, 8, METATILE_SpindaIslandSecondary_BrokenFaucetWall, TRUE
# 56 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 20, 9, METATILE_SpindaIslandSecondary_BrokenFaucetGround, FALSE
# 57 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 59 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SpindaIsland_Home_Clock1_FaucetBreaks
# 61 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_M_BRICK_BREAK
# 65 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 66 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 68 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 69 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative DrawMugshot
# 70 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 71 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_2
# 77 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 78 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative ClearMugshot
# 80 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setmetatile 20, 9, METATILE_SpindaIsland_Grass, FALSE
# 81 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	special DrawWholeMapView
# 82 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	giveitem ITEM_BROKEN_FAUCET
# 84 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_SPINDA_ISLAND_INTRO_STATE, 3
# 85 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setflag FLAG_FAUCET_BROKE
# 87 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


# 91 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
SpindaIsland_Home_Clock1_FaucetBreaks:
# 92 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock_facing_direction
# 93 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	player_run_down
	step_end

SpindaIsland_Home_Clock1_HidingBoy_Text_0:
# 9 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Timmy$"

SpindaIsland_Home_Clock1_HidingBoy_Text_1:
# 11 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Darnit! You found me!$"

SpindaIsland_Home_Clock1_HidingBoy_Text_2:
# 16 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock1_HidingBoy_Text_3:
# 18 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Wazzup, Timmy?$"

SpindaIsland_Home_Clock1_Faucet_Text_0:
# 34 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Faucet's broken…$"

SpindaIsland_Home_Clock1_Faucet_Text_1:
# 46 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Alrighty, time to turn the big old\n"
	.string "faucet back on!\p"
	.string "Hnng…\p"
	.string "… … … … …$"

SpindaIsland_Home_Clock1_Faucet_Text_2:
# 72 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Aw, Shuckles! It broke!\p"
	.string "Mom is totally gonna kill me!!\p"
	.string "Let's, uh, not tell her anything and\n"
	.string "fix this ourselves!\p"
	.string "I better pocket this, too.$"

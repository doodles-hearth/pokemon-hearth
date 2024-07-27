SpindaIsland_Home_Clock1_MapScripts::
	.byte 0


SpindaIsland_Home_Clock1_HidingBoy::
# 6 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 8 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 9 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_HidingBoy_Text_1, MSGBOX_AUTOCLOSE
# 13 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 14 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative DrawMugshot
# 15 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 16 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_HidingBoy_Text_3
# 19 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 20 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative ClearMugshot
# 22 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_Faucet::
# 26 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	lock
# 28 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 29 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative DrawMugshot
# 30 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 31 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_0
# 36 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 37 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative ClearMugshot
# 39 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 40 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_ICE_BREAK
# 41 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 43 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	setvar VAR_0x8000, MUGSHOT_ARCHIE
# 44 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative DrawMugshot
# 45 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_2
# 46 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_1
# 52 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	closemessage
# 53 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	callnative ClearMugshot
# 55 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	release
	return


SpindaIsland_Home_Clock1_HidingBoy_Text_0:
# 8 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Timmy$"

SpindaIsland_Home_Clock1_HidingBoy_Text_1:
# 10 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Darnit! You found me!$"

SpindaIsland_Home_Clock1_HidingBoy_Text_2:
# 15 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock1_HidingBoy_Text_3:
# 17 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Wazzup, Timmy?$"

SpindaIsland_Home_Clock1_Faucet_Text_0:
# 32 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Alrighty, time to turn the big old\n"
	.string "faucet back on!\p"
	.string "Hnng…\p"
	.string "… … … … …$"

SpindaIsland_Home_Clock1_Faucet_Text_1:
# 47 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Aw, Shuckles! It broke!\p"
	.string "Mom is totally gonna kill me!\p"
	.string "Let's, uh, not tell her anything and\n"
	.string "fix this ourselves!\p"
	.string "I better pocket this, too.$"

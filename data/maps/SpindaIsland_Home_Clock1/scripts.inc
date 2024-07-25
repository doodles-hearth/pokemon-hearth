SpindaIsland_Home_Clock1_MapScripts::
	.byte 0


SpindaIsland_Home_Clock1_HidingBoy::
# 6 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_HidingBoy_Text_0
# 7 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_HidingBoy_Text_1, MSGBOX_AUTOCLOSE
	return


SpindaIsland_Home_Clock1_Faucet::
# 13 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_Faucet_Text_0
# 14 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_1, MSGBOX_AUTOCLOSE
# 19 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	delay 48
# 20 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	playse SE_ICE_BREAK
# 21 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	waitse
# 23 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	speakername SpindaIsland_Home_Clock1_Faucet_Text_0
# 24 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	msgbox SpindaIsland_Home_Clock1_Faucet_Text_2, MSGBOX_AUTOCLOSE
	return


SpindaIsland_Home_Clock1_HidingBoy_Text_0:
# 6 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Timmy$"

SpindaIsland_Home_Clock1_HidingBoy_Text_1:
# 8 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Darnit! You found me!$"

SpindaIsland_Home_Clock1_Faucet_Text_0:
# 13 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_Clock1_Faucet_Text_1:
# 15 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Alrighty, time to turn the big old\n"
	.string "faucet back on!\p"
	.string "Hnng…\p"
	.string "… … … … …\p"
	.string "$"

SpindaIsland_Home_Clock1_Faucet_Text_2:
# 25 "data/maps/SpindaIsland_Home_Clock1/scripts.pory"
	.string "Aw, Shuckles! It broke!\p"
	.string "Mom is totally gonna kill me!\p"
	.string "Let's, uh, not tell her anything and\n"
	.string "fix this ourselves!\p"
	.string "I better pocket this, too.$"

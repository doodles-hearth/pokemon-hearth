Silveridge_MapScripts::
	.byte 0


Silveridge_EventScript_LotOfRocks::
# 6 "data/maps/Silveridge/scripts.pory"
	lock
# 7 "data/maps/Silveridge/scripts.pory"
	faceplayer
# 8 "data/maps/Silveridge/scripts.pory"
	msgbox Silveridge_EventScript_LotOfRocks_Text_0
# 16 "data/maps/Silveridge/scripts.pory"
	release
	return


Silveridge_EventScript_HousesMadeOfSilverTunnelStone::
# 20 "data/maps/Silveridge/scripts.pory"
	lock
# 21 "data/maps/Silveridge/scripts.pory"
	faceplayer
# 22 "data/maps/Silveridge/scripts.pory"
	msgbox Silveridge_EventScript_HousesMadeOfSilverTunnelStone_Text_0
# 25 "data/maps/Silveridge/scripts.pory"
	release
	return


Silveridge_EventScript_MissingStatue::
# 29 "data/maps/Silveridge/scripts.pory"
	lock
# 30 "data/maps/Silveridge/scripts.pory"
	faceplayer
# 31 "data/maps/Silveridge/scripts.pory"
	msgbox Silveridge_EventScript_MissingStatue_Text_0
# 37 "data/maps/Silveridge/scripts.pory"
	release
	return


Silveridge_EventScript_Wildflowers::
# 41 "data/maps/Silveridge/scripts.pory"
	lock
# 43 "data/maps/Silveridge/scripts.pory"
	faceplayer
# 44 "data/maps/Silveridge/scripts.pory"
	msgbox Silveridge_EventScript_Wildflowers_Text_0
# 50 "data/maps/Silveridge/scripts.pory"
	release
	return


Silveridge_EventScript_TownSign::
# 54 "data/maps/Silveridge/scripts.pory"
	msgbox Silveridge_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


Silveridge_EventScript_TownSculptureSignTBD::
# 58 "data/maps/Silveridge/scripts.pory"
	msgbox Silveridge_EventScript_TownSculptureSignTBD_Text_0, MSGBOX_SIGN
	return


Silveridge_EventScript_SculptorsHouseSign::
# 62 "data/maps/Silveridge/scripts.pory"
	msgbox Silveridge_EventScript_SculptorsHouseSign_Text_0, MSGBOX_SIGN
	return


Silveridge_EventScript_EldersHouseSign::
# 66 "data/maps/Silveridge/scripts.pory"
	msgbox Silveridge_EventScript_EldersHouseSign_Text_0, MSGBOX_SIGN
	return


Silveridge_EventScript_LotOfRocks_Text_0:
# 9 "data/maps/Silveridge/scripts.pory"
	.string "We don't have a lot of natural\n"
	.string "resources here in Silveridge.\p"
	.string "We don't have a lot of wood…\p"
	.string "Or steel…\p"
	.string "Or freshwater…\p"
	.string "Or crops…\p"
	.string "What we do have in abundance is rocks.\n"
	.string "We have a LOT of rocks.$"

Silveridge_EventScript_HousesMadeOfSilverTunnelStone_Text_0:
# 23 "data/maps/Silveridge/scripts.pory"
	.string "See the houses around here? They were\n"
	.string "all built using the stones we got from\l"
	.string "digging the Silver tunnel.$"

Silveridge_EventScript_MissingStatue_Text_0:
# 32 "data/maps/Silveridge/scripts.pory"
	.string "Hello, traveler. Have you looked at this\n"
	.string "stunning statue that makes the pride\l"
	.string "of our town?\p"
	.string "…Is what I would say if we had one.\p"
	.string "There used to be a statue, but an\n"
	.string "earthquake destroyed it long ago, so\l"
	.string "now we're left with this empty pedestal.\p"
	.string "There's an excentric man that lives\n"
	.string "nearby and that calls himself “The\l"
	.string "Sculptor”. I wish he'd make a\l"
	.string "replacement, but he hasn't been making\l"
	.string "anything for a while now.$"

Silveridge_EventScript_Wildflowers_Text_0:
# 45 "data/maps/Silveridge/scripts.pory"
	.string "I loved gardening back when I lived on\n"
	.string "Havenisle. When I first moved here, the\l"
	.string "barren landscape made me very\l"
	.string "homesick.\p"
	.string "So I started planting little patches of\n"
	.string "these native wildflowers around the\l"
	.string "town.\p"
	.string "I was told they symbolize eternal love.\n"
	.string "I don't know about that, but they make\l"
	.string "me happy! I wish I had brought some\l"
	.string "seeds with me when I left Havenisle,\l"
	.string "though. The flowers there are so\l"
	.string "colorful!$"

Silveridge_EventScript_TownSign_Text_0:
# 54 "data/maps/Silveridge/scripts.pory"
	.string "Silveridge\n"
	.string "“A rocky town in shades of grey.”$"

Silveridge_EventScript_TownSculptureSignTBD_Text_0:
# 58 "data/maps/Silveridge/scripts.pory"
	.string "“{FIXED_CASE}TO BE DETERMINED{UNFIX_CASE}”\n"
	.string "A beautiful statue by {FIXED_CASE}PLACEHOLDER{UNFIX_CASE}$"

Silveridge_EventScript_SculptorsHouseSign_Text_0:
# 62 "data/maps/Silveridge/scripts.pory"
	.string "The sculptor's atelier$"

Silveridge_EventScript_EldersHouseSign_Text_0:
# 66 "data/maps/Silveridge/scripts.pory"
	.string "Elder Iwa's house$"

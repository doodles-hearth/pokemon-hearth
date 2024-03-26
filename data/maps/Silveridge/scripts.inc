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


Silveridge_EventScript_TownSign::
# 29 "data/maps/Silveridge/scripts.pory"
	msgbox Silveridge_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


Silveridge_EventScript_TownSculptureSignTBD::
# 33 "data/maps/Silveridge/scripts.pory"
	msgbox Silveridge_EventScript_TownSculptureSignTBD_Text_0, MSGBOX_SIGN
	return


Silveridge_EventScript_SculptorsHouseSign::
# 37 "data/maps/Silveridge/scripts.pory"
	msgbox Silveridge_EventScript_SculptorsHouseSign_Text_0, MSGBOX_SIGN
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

Silveridge_EventScript_TownSign_Text_0:
# 29 "data/maps/Silveridge/scripts.pory"
	.string "Silveridge\n"
	.string "“A rocky town in shades of grey.”$"

Silveridge_EventScript_TownSculptureSignTBD_Text_0:
# 33 "data/maps/Silveridge/scripts.pory"
	.string "“{FIXED_CASE}TO BE DETERMINED{UNFIX_CASE}”\n"
	.string "A beautiful sculpture by {FIXED_CASE}PLACEHOLDER{UNFIX_CASE}$"

Silveridge_EventScript_SculptorsHouseSign_Text_0:
# 37 "data/maps/Silveridge/scripts.pory"
	.string "The sculptor's atelier$"

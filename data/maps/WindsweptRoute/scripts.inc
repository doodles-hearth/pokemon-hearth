WindsweptRoute_MapScripts::
	.byte 0


WindsweptRoute_EventScript_OvergrownTrees::
# 7 "data/maps/WindsweptRoute/scripts.pory"
	lock
# 8 "data/maps/WindsweptRoute/scripts.pory"
	faceplayer
# 9 "data/maps/WindsweptRoute/scripts.pory"
	goto_if_set FLAG_CUT_TREE_SILVER_TUNNEL, WindsweptRoute_EventScript_OvergrownTrees_2
# 14 "data/maps/WindsweptRoute/scripts.pory"
	msgbox WindsweptRoute_EventScript_OvergrownTrees_Text_1
WindsweptRoute_EventScript_OvergrownTrees_1:
# 19 "data/maps/WindsweptRoute/scripts.pory"
	release
	return

WindsweptRoute_EventScript_OvergrownTrees_2:
# 10 "data/maps/WindsweptRoute/scripts.pory"
	msgbox WindsweptRoute_EventScript_OvergrownTrees_Text_0
	goto WindsweptRoute_EventScript_OvergrownTrees_1


WindsweptRoute_EventScript_OvergrownTrees_Text_0:
# 11 "data/maps/WindsweptRoute/scripts.pory"
	.string "Thank you for cutting down that\n"
	.string "annoying tree! We can go to Silveridge\l"
	.string "again now!$"

WindsweptRoute_EventScript_OvergrownTrees_Text_1:
# 15 "data/maps/WindsweptRoute/scripts.pory"
	.string "The weeds got out of control here, and\n"
	.string "some trees now block the way to Silver\l"
	.string "Tunnel…\p"
	.string "Someone'll eventually have to ask for\n"
	.string "help from the old Cut master on Tranquil\l"
	.string "route…$"

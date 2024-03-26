TranquilRoute_CutHouse_MapScripts::
	.byte 0


TranquilRoute_CutHouse_EventScript_CutMaster::
# 6 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	lock
# 7 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	faceplayer
# 9 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_CUT, TranquilRoute_CutHouse_EventScript_CutMaster_2
# 16 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_CutMaster_Text_1
# 23 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	closemessage
# 25 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	giveitem ITEM_HM_CUT
# 26 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	setflag FLAG_RECEIVED_HM_CUT
# 27 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_CutMaster_Text_2
TranquilRoute_CutHouse_EventScript_CutMaster_1:
# 35 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	release
	return

TranquilRoute_CutHouse_EventScript_CutMaster_2:
# 10 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	msgbox TranquilRoute_CutHouse_EventScript_CutMaster_Text_0
	goto TranquilRoute_CutHouse_EventScript_CutMaster_1


TranquilRoute_CutHouse_EventScript_CutMaster_Text_0:
# 11 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	.string "Are you finding the Cut technique\n"
	.string "useful?\p"
	.string "No, I still haven't trimmed my garden. I\n"
	.string "really should get to it…$"

TranquilRoute_CutHouse_EventScript_CutMaster_Text_1:
# 17 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	.string "Hello, there. I don't get many visitors,\n"
	.string "so sit down, have some tea!\p"
	.string "What? The weeds are growing all over\n"
	.string "the place in my garden?\p"
	.string "Ho ho ho…\p"
	.string "You're right, I have been neglecting it\n"
	.string "lately. You see, my old back isn't as\l"
	.string "strong as it used to be.\p"
	.string "Here, your Pokémon can trim them using\n"
	.string "this.$"

TranquilRoute_CutHouse_EventScript_CutMaster_Text_2:
# 28 "data/maps/TranquilRoute_CutHouse/scripts.pory"
	.string "This scroll contains an ancient\n"
	.string "technique created by the most talented\l"
	.string "samurai. Pokémon can learn that\l"
	.string "technique too.\p"
	.string "If you have a Pokémon capable of\n"
	.string "learning this move, it will be able to cut\l"
	.string "tall grass as well as little trees that\l"
	.string "block your path.\p"
	.string "In fact, now that you have read the\n"
	.string "scroll, you don't even need to teach\l"
	.string "them the actual move! Oh, you will need\l"
	.string "at least one official dojo badge to be\l"
	.string "able to cut trees and grass, though.$"

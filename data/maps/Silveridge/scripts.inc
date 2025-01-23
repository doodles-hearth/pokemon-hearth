Silveridge_MapScripts::
	.byte 0


Silveridge_EventScript_LotOfRocks::
	lock
	faceplayer
	msgbox Silveridge_EventScript_LotOfRocks_Text_0
	release
	return


Silveridge_EventScript_HousesMadeOfSilverTunnelStone::
	lock
	faceplayer
	msgbox Silveridge_EventScript_HousesMadeOfSilverTunnelStone_Text_0
	release
	return


Silveridge_EventScript_MissingStatue::
	lock
	faceplayer
	msgbox Silveridge_EventScript_MissingStatue_Text_0
	release
	return


Silveridge_EventScript_Wildflowers::
	lock
	faceplayer
	msgbox Silveridge_EventScript_Wildflowers_Text_0
	release
	return


Silveridge_EventScript_TownSign::
	msgbox Silveridge_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


Silveridge_EventScript_TownSculptureSignTBD::
	msgbox Silveridge_EventScript_TownSculptureSignTBD_Text_0, MSGBOX_SIGN
	return


Silveridge_EventScript_SculptorsHouseSign::
	msgbox Silveridge_EventScript_SculptorsHouseSign_Text_0, MSGBOX_SIGN
	return


Silveridge_EventScript_EldersHouseSign::
	msgbox Silveridge_EventScript_EldersHouseSign_Text_0, MSGBOX_SIGN
	return


Silveridge_EventScript_LotOfRocks_Text_0:
	.string "We don't have a lot of natural\n"
	.string "resources here in Silveridge.\p"
	.string "We don't have a lot of wood…\p"
	.string "Or steel…\p"
	.string "Or freshwater…\p"
	.string "Or crops…\p"
	.string "What we do have in abundance is\n"
	.string "rocks. We have a LOT of rocks.$"

Silveridge_EventScript_HousesMadeOfSilverTunnelStone_Text_0:
	.string "See the houses around here? They\n"
	.string "were all built using the stones\l"
	.string "leftover from digging the Silver\l"
	.string "tunnel.$"

Silveridge_EventScript_MissingStatue_Text_0:
	.string "Hello, traveler. Have you looked at\n"
	.string "this stunning statue that makes the\l"
	.string "pride of our town?\p"
	.string "…Is what I would say if we had one.\p"
	.string "There used to be a statue, but a\n"
	.string "quake destroyed it long ago, so now\l"
	.string "we're left with this empty pedestal.\p"
	.string "There's an excentric man that lives\n"
	.string "nearby and that calls himself “The\l"
	.string "Sculptor”.\p"
	.string "I wish he'd make a replacement, but he\n"
	.string "hasn't been making anything for a\l"
	.string "while now.$"

Silveridge_EventScript_Wildflowers_Text_0:
	.string "I loved gardening back when I lived on\n"
	.string "Havenisle.\p"
	.string "When I first moved here, the barren\n"
	.string "landscape made me very homesick.\p"
	.string "So I started planting little patches\n"
	.string "of these native wildflowers around\l"
	.string "the town.\p"
	.string "I was told they symbolize eternal\n"
	.string "love. I don't know about that, but\l"
	.string "they make me happy! I wish I had\l"
	.string "brought some seeds with me when I\l"
	.string "left Havenisle, though. The flowers\l"
	.string "there are so colorful!$"

Silveridge_EventScript_TownSign_Text_0:
	.string "Silveridge\n"
	.string "“A rocky town in shades of grey.”$"

Silveridge_EventScript_TownSculptureSignTBD_Text_0:
	.string "“TO BE DETERMINED”\n"
	.string "A beautiful statue by PLACEHOLDER$"

Silveridge_EventScript_SculptorsHouseSign_Text_0:
	.string "The Sculptor's atelier$"

Silveridge_EventScript_EldersHouseSign_Text_0:
	.string "Elder Iwa's house$"

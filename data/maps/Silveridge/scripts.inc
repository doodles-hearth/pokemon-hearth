Silveridge_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Silveridge_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

Silveridge_MapScripts_MAP_SCRIPT_ON_LOAD:
	call Silveridge_DrawMetatiles
	return


Silveridge_DrawMetatiles::
	gettimeofday
	switch VAR_0x8000
	case TIME_DEAD_NIGHT, Silveridge_DrawMetatiles_2
	case TIME_EARLY_MORNING, Silveridge_DrawMetatiles_3
	case TIME_MORNING, Silveridge_DrawMetatiles_3
	case TIME_LUNCHTIME, Silveridge_DrawMetatiles_3
	case TIME_AFTERNOON, Silveridge_DrawMetatiles_3
	case TIME_EVENING, Silveridge_DrawMetatiles_3
	case TIME_NIGHT, Silveridge_DrawMetatiles_3
Silveridge_DrawMetatiles_3:
	end

Silveridge_DrawMetatiles_2:
	setmetatile 12, 10, METATILE_Silveridge_SilveridgeDoor, TRUE
	setmetatile 18, 18, METATILE_Silveridge_SilveridgeDoor, TRUE
	setmetatile 23, 6, METATILE_Silveridge_SilveridgeDoor, TRUE
	setmetatile 24, 6, METATILE_Silveridge_SilveridgeDoor, TRUE
	setmetatile 34, 6, METATILE_Silveridge_SilveridgeDoor, TRUE
	setmetatile 20, 26, METATILE_Silveridge_SilveridgeDoor, TRUE
	setmetatile 28, 26, METATILE_Silveridge_SilveridgeDoor, TRUE
	return


Silveridge_EventScript_LotOfRocks::
	lock
	faceplayer
	speakername Silveridge_EventScript_LotOfRocks_Text_0
	msgbox Silveridge_EventScript_LotOfRocks_Text_1
	release
	return


Silveridge_EventScript_HousesMadeOfSilverTunnelStone::
	lock
	faceplayer
	speakername Silveridge_EventScript_HousesMadeOfSilverTunnelStone_Text_0
	msgbox Silveridge_EventScript_HousesMadeOfSilverTunnelStone_Text_1
	release
	return


Silveridge_EventScript_MissingStatue::
	lock
	faceplayer
	speakername Silveridge_EventScript_MissingStatue_Text_0
	msgbox Silveridge_EventScript_MissingStatue_Text_1
	release
	return


Silveridge_EventScript_Wildflowers::
	lock
	faceplayer
	speakername Silveridge_EventScript_Wildflowers_Text_0
	msgbox Silveridge_EventScript_Wildflowers_Text_1
	release
	return


Silveridge_EventScript_Mart::
	lock
	faceplayer
	speakername Silveridge_EventScript_Mart_Text_0
	message Silveridge_EventScript_Mart_Text_1
	waitmessage
	pokemart Silveridge_Mart
	speakername Silveridge_EventScript_Mart_Text_0
	msgbox Silveridge_EventScript_Mart_Text_2, MSGBOX_DEFAULT
	release
	return


	.align 2
Silveridge_Mart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_OINTMENT
	.2byte ITEM_REVIVAL_POWDER
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_NONE

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
	.string "Guy$"

Silveridge_EventScript_LotOfRocks_Text_1:
	.string "We don't have a lot of natural\n"
	.string "resources here in Silveridge.\p"
	.string "We don't have a lot of wood…\p"
	.string "Or steel…\p"
	.string "Or freshwater…\p"
	.string "Or crops…\p"
	.string "What we do have in abundance is\n"
	.string "rocks. We have a LOT of rocks.$"

Silveridge_EventScript_HousesMadeOfSilverTunnelStone_Text_0:
	.string "Woman$"

Silveridge_EventScript_HousesMadeOfSilverTunnelStone_Text_1:
	.string "See the houses around here? They\n"
	.string "were all built using the stones\l"
	.string "leftover from digging the Silver\l"
	.string "tunnel.$"

Silveridge_EventScript_MissingStatue_Text_0:
	.string "Man$"

Silveridge_EventScript_MissingStatue_Text_1:
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
	.string "Boy$"

Silveridge_EventScript_Wildflowers_Text_1:
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

Silveridge_EventScript_Mart_Text_0:
	.string "Shopkeeper$"

Silveridge_EventScript_Mart_Text_1:
	.string "Welcome to Silveridge's market!\n"
	.string "Sorry, we're fresh out of rocks!$"

Silveridge_EventScript_Mart_Text_2:
	.string "I hope you found what you were\n"
	.string "looking for!$"

Silveridge_EventScript_TownSign_Text_0:
	.string "Silveridge\n"
	.string "“A rocky town in shades of grey.”$"

Silveridge_EventScript_TownSculptureSignTBD_Text_0:
	.string "“TO BE DETERMINED”\n"
	.string "A beautiful statue by PLACEHOLDER$"

Silveridge_EventScript_SculptorsHouseSign_Text_0:
	.string "The Sculptor's atelier$"

Silveridge_EventScript_EldersHouseSign_Text_0:
	.string "{UP_ARROW} Elder Iwa's house$"

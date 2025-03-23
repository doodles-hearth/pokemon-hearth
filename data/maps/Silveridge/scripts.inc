Silveridge_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Silveridge_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

Silveridge_MapScripts_MAP_SCRIPT_ON_LOAD:
	call Silveridge_DrawMetatiles
	return


Silveridge_DrawMetatiles::
	gettimeofday
	switch VAR_RESULT
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
	speakername Silveridge_EventScript_Wildflowers_Text_0
	msgbox Silveridge_EventScript_Wildflowers_Text_1
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
	.string "Hello, traveler. Have you looked\n"
	.string "at this stunning statue that makes\l"
	.string "the pride of our town?\p"
	.string "…Is what I would say if we had\n"
	.string "one.\p"
	.string "There used to be a statue, but a\n"
	.string "quake destroyed it long ago, so\l"
	.string "now we're left with this empty\l"
	.string "pedestal.\p"
	.string "There's an excentric man that lives\n"
	.string "nearby and that calls himself\l"
	.string "“The Sculptor”.\p"
	.string "I wish he'd make a replacement, but\n"
	.string "he hasn't been making anything for\l"
	.string "a while now.$"

Silveridge_EventScript_Wildflowers_Text_0:
	.string "Boy$"

Silveridge_EventScript_Wildflowers_Text_1:
	.string "I loved gardening back when I\n"
	.string "lived on Havenisle.\p"
	.string "When I first moved here, the barren\n"
	.string "landscape made me very homesick.\p"
	.string "So I started planting little patches\n"
	.string "of these native wildflowers around\l"
	.string "the town.\p"
	.string "I was told they symbolize eternal\n"
	.string "love. I don't know about that,\l"
	.string "but they make me happy! I wish I\l"
	.string "had brought some seeds with me\l"
	.string "when I left Havenisle, though.\l"
	.string "The flowers there are so colorful!$"

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

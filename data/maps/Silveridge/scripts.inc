Silveridge_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Silveridge_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_TRANSITION, Silveridge_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Silveridge_MapScripts_MAP_SCRIPT_ON_LOAD:
	call Silveridge_DrawMetatiles
	return

Silveridge_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_SILVERIDGE
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
	setmetatile 20, 26, METATILE_Silveridge_SilveridgeDoor, TRUE
	return


Silveridge_EventScript_LotOfRocks::
	lock
	faceplayer
	setspeaker SP_NAME_GUY
	msgbox Silveridge_EventScript_LotOfRocks_Text_0
	release
	return


Silveridge_EventScript_HousesMadeOfSilverTunnelStone::
	lock
	faceplayer
	setspeaker SP_NAME_WOMAN
	msgbox Silveridge_EventScript_HousesMadeOfSilverTunnelStone_Text_0
	release
	return


Silveridge_EventScript_MissingStatue::
	lock
	faceplayer
	setspeaker SP_NAME_MAN
	msgbox Silveridge_EventScript_MissingStatue_Text_0
	release
	return


Silveridge_EventScript_Wildflowers::
	lock
	faceplayer
	setspeaker SP_NAME_BOY
	msgbox Silveridge_EventScript_Wildflowers_Text_0
	release
	return


Silveridge_EventScript_Mart::
	lock
	faceplayer
	setspeaker SP_NAME_SHOPKEEPER
	message Silveridge_EventScript_Mart_Text_0
	waitmessage
	pokemart Silveridge_Mart
	setspeaker SP_NAME_SHOPKEEPER
	msgbox Silveridge_EventScript_Mart_Text_1, MSGBOX_DEFAULT
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


Silveridge_EventScript_AronGuy::
	lock
	faceplayer
	setnamedmon SPECIES_ARON
	msgbox Silveridge_EventScript_AronGuy_Text_0
	closemessage
	release
	return


Silveridge_EventScript_Aron::
	lock
	playmoncry SPECIES_ARON, CRY_MODE_NORMAL
	setseenmon SPECIES_ARON
	setspeakertomonname SPECIES_ARON
	msgbox Silveridge_EventScript_Aron_Text_0
	waitmoncry
	closemessage
	release
	return


Silveridge_EventScript_LotOfRocks_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_MOUNTAIN_FAT_GUY EMOTE_NORMAL}We don't have a lot of natural\n"
	.string "resources here in Silveridge.\p"
	.string "We don't have a lot of wood…\p"
	.string "Or steel…\p"
	.string "Or freshwater…\p"
	.string "Or crops…\p"
	.string "What we do have in abundance is\n"
	.string "rocks. We have a LOT of rocks.$"

Silveridge_EventScript_HousesMadeOfSilverTunnelStone_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_MOUNTAIN_WOMAN_2 EMOTE_NORMAL}See the houses around here? They\n"
	.string "were all built using the stones\l"
	.string "leftover from digging the Silver\l"
	.string "tunnel.$"

Silveridge_EventScript_MissingStatue_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_MOUNTAIN_MAN_2 EMOTE_NORMAL}Hello, traveler. Have you looked at\n"
	.string "this stunning statue that makes the\l"
	.string "pride of our town?\p"
	.string "…Is what I would say if we had one.\p"
	.string "There used to be a statue, but a\n"
	.string "quake destroyed it long ago, so now\l"
	.string "we're left with this empty pedestal.\p"
	.string "An excentric man lives nearby, calls\n"
	.string "himself “The Sculptor”.\p"
	.string "I wish he'd make a replacement, but he\n"
	.string "hasn't been making anything in\l"
	.string "forever.$"

Silveridge_EventScript_Wildflowers_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_BOY_2 EMOTE_NORMAL}I loved gardening back when I lived on\n"
	.string "Havenisle.\p"
	.string "When I first moved here, the barren\n"
	.string "landscape made me very homesick.\p"
	.string "So I started planting these native\n"
	.string "wildflowers around the town!$"

Silveridge_EventScript_Mart_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_CLERK EMOTE_NORMAL}Welcome to Silveridge's market!\n"
	.string "Sorry, we're fresh out of rocks!$"

Silveridge_EventScript_Mart_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_CLERK EMOTE_NORMAL}I hope you found what you were\n"
	.string "looking for!$"

Silveridge_EventScript_TownSign_Text_0:
	.string "Silveridge\n"
	.string "“A rocky town in shades of grey.”$"

Silveridge_EventScript_TownSculptureSignTBD_Text_0:
	.string "“TO BE DETERMINED”\n"
	.string "A beautiful statue by PLACEHOLDER$"

Silveridge_EventScript_SculptorsHouseSign_Text_0:
	.string "The Sculptor's Atelier$"

Silveridge_EventScript_EldersHouseSign_Text_0:
	.string "{UP_ARROW} Elder Iwa's house$"

Silveridge_EventScript_AronGuy_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_MOUNTAIN_MAN_1 EMOTE_NORMAL}{SPEAKER NAME_MAN}Found this little guy in Silver Tunnel.\n"
	.string "He's been munching on rocks ever\l"
	.string "since!$"

Silveridge_EventScript_Aron_Text_0:
	.string "Chomp, chomp…$"

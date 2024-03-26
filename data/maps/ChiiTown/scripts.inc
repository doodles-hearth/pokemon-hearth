ChiiTown_MapScripts::
# 2 "data/maps/ChiiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChiiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

ChiiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/ChiiTown/scripts.pory"
	map_script_2 VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 2, ChiiTown_EventScript_SetTrespassVar
	.2byte 0


ChiiTown_EventScript_PlantingFlowers::
# 8 "data/maps/ChiiTown/scripts.pory"
	lock
# 9 "data/maps/ChiiTown/scripts.pory"
	faceplayer
# 10 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_PlantingFlowers_Text_0
# 13 "data/maps/ChiiTown/scripts.pory"
	release
	return


ChiiTown_EventScript_Mart::
# 17 "data/maps/ChiiTown/scripts.pory"
	lock
# 18 "data/maps/ChiiTown/scripts.pory"
	faceplayer
# 19 "data/maps/ChiiTown/scripts.pory"
	message ChiiTown_EventScript_Mart_Text_0
# 20 "data/maps/ChiiTown/scripts.pory"
	waitmessage
# 21 "data/maps/ChiiTown/scripts.pory"
	pokemart ChiiTown_Mart
# 22 "data/maps/ChiiTown/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 23 "data/maps/ChiiTown/scripts.pory"
	release
	return


	.align 2
# 26 "data/maps/ChiiTown/scripts.pory"
ChiiTown_Mart:
# 27 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_POKE_BALL
# 28 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_BERRY_JUICE
# 29 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 30 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 31 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_AWAKENING
# 32 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 33 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

ChiiTown_EventScript_TownSign::
# 37 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


ChiiTown_EventScript_SetTrespassVar::
# 41 "data/maps/ChiiTown/scripts.pory"
	setvar VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 1
	return


ChiiTown_EventScript_PlantingFlowers_Text_0:
# 11 "data/maps/ChiiTown/scripts.pory"
	.string "I'm planting flowers so that the\n"
	.string "Pokémon become happy again!$"

ChiiTown_EventScript_Mart_Text_0:
# 19 "data/maps/ChiiTown/scripts.pory"
	.string "Welcome to Chii Town's market! How may I\n"
	.string "help you?$"

ChiiTown_EventScript_TownSign_Text_0:
# 37 "data/maps/ChiiTown/scripts.pory"
	.string "Chii Town\n"
	.string "“The smallest town, with the biggest\l"
	.string "heart.”$"

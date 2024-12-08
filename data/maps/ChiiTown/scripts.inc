ChiiTown_MapScripts::
# 18 "data/maps/ChiiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ChiiTown_MapScripts_MAP_SCRIPT_ON_LOAD
# 22 "data/maps/ChiiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChiiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

ChiiTown_MapScripts_MAP_SCRIPT_ON_LOAD:
# 19 "data/maps/ChiiTown/scripts.pory"
	call ChiiTown_EventScript_SpawnBirds
# 20 "data/maps/ChiiTown/scripts.pory"
	call ChiiTown_NPCSchedules
	return

ChiiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 23 "data/maps/ChiiTown/scripts.pory"
	map_script_2 VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 2, ChiiTown_EventScript_SetTrespassVar
	.2byte 0


ChiiTown_EventScript_MomWaiting::
# 28 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_MomWaiting_Text_0
# 29 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_MomWaiting_Text_1, MSGBOX_NPC
	return


ChiiTown_EventScript_SpawnBirds::
# 38 "data/maps/ChiiTown/scripts.pory"
	setflag FLAG_TEMP_1
# 39 "data/maps/ChiiTown/scripts.pory"
	setflag FLAG_TEMP_2
# 41 "data/maps/ChiiTown/scripts.pory"
	setflag FLAG_TEMP_3
# 42 "data/maps/ChiiTown/scripts.pory"
	setflag FLAG_TEMP_4
# 44 "data/maps/ChiiTown/scripts.pory"
	gettime
# 46 "data/maps/ChiiTown/scripts.pory"
	compare VAR_0x8000, 5
	goto_if_ge ChiiTown_EventScript_SpawnBirds_6
ChiiTown_EventScript_SpawnBirds_4:
# 55 "data/maps/ChiiTown/scripts.pory"
	compare VAR_0x8000, 9
	goto_if_ge ChiiTown_EventScript_SpawnBirds_3
	return

ChiiTown_EventScript_SpawnBirds_1:
# 47 "data/maps/ChiiTown/scripts.pory"
	random 2
# 48 "data/maps/ChiiTown/scripts.pory"
	switch VAR_RESULT
# 49 "data/maps/ChiiTown/scripts.pory"
	case 0, ChiiTown_EventScript_SpawnBirds_10
# 51 "data/maps/ChiiTown/scripts.pory"
	case 1, ChiiTown_EventScript_SpawnBirds_11
	return

ChiiTown_EventScript_SpawnBirds_2:
# 56 "data/maps/ChiiTown/scripts.pory"
	random 2
# 57 "data/maps/ChiiTown/scripts.pory"
	switch VAR_RESULT
# 58 "data/maps/ChiiTown/scripts.pory"
	case 0, ChiiTown_EventScript_SpawnBirds_13
# 60 "data/maps/ChiiTown/scripts.pory"
	case 1, ChiiTown_EventScript_SpawnBirds_14
	return

ChiiTown_EventScript_SpawnBirds_3:
# 55 "data/maps/ChiiTown/scripts.pory"
	compare VAR_0x8000, 17
	goto_if_le ChiiTown_EventScript_SpawnBirds_2
	return

ChiiTown_EventScript_SpawnBirds_6:
# 46 "data/maps/ChiiTown/scripts.pory"
	compare VAR_0x8000, 8
	goto_if_le ChiiTown_EventScript_SpawnBirds_1
	goto ChiiTown_EventScript_SpawnBirds_4

ChiiTown_EventScript_SpawnBirds_10:
# 50 "data/maps/ChiiTown/scripts.pory"
	clearflag FLAG_TEMP_1
	return

ChiiTown_EventScript_SpawnBirds_11:
# 52 "data/maps/ChiiTown/scripts.pory"
	clearflag FLAG_TEMP_2
	return

ChiiTown_EventScript_SpawnBirds_13:
# 59 "data/maps/ChiiTown/scripts.pory"
	clearflag FLAG_TEMP_3
	return

ChiiTown_EventScript_SpawnBirds_14:
# 61 "data/maps/ChiiTown/scripts.pory"
	clearflag FLAG_TEMP_4
	return


ChiiTown_EventScript_Shopper::
# 67 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_MomWaiting_Text_0
# 68 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_Shopper_Text_0, MSGBOX_NPC
	return


ChiiTown_EventScript_Kecleon::
# 75 "data/maps/ChiiTown/scripts.pory"
	lock
# 76 "data/maps/ChiiTown/scripts.pory"
	faceplayer
# 77 "data/maps/ChiiTown/scripts.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
# 78 "data/maps/ChiiTown/scripts.pory"
	ismonseen SPECIES_KECLEON
# 79 "data/maps/ChiiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne ChiiTown_EventScript_Kecleon_2
# 82 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Kecleon_Text_1
ChiiTown_EventScript_Kecleon_1:
# 84 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_Kecleon_Text_2
# 85 "data/maps/ChiiTown/scripts.pory"
	waitmoncry
# 86 "data/maps/ChiiTown/scripts.pory"
	closemessage
# 87 "data/maps/ChiiTown/scripts.pory"
	release
	return

ChiiTown_EventScript_Kecleon_2:
# 80 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Kecleon_Text_0
	goto ChiiTown_EventScript_Kecleon_1


ChiiTown_EventScript_PlantingFlowers::
# 91 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_PlantingFlowers_Text_0
# 92 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_PlantingFlowers_Text_1, MSGBOX_NPC
	return


ChiiTown_EventScript_Mart::
# 98 "data/maps/ChiiTown/scripts.pory"
	lock
# 99 "data/maps/ChiiTown/scripts.pory"
	faceplayer
# 100 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Mart_Text_0
# 101 "data/maps/ChiiTown/scripts.pory"
	message ChiiTown_EventScript_Mart_Text_1
# 102 "data/maps/ChiiTown/scripts.pory"
	waitmessage
# 103 "data/maps/ChiiTown/scripts.pory"
	pokemart ChiiTown_Mart
# 104 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Mart_Text_0
# 105 "data/maps/ChiiTown/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 106 "data/maps/ChiiTown/scripts.pory"
	release
	return


	.align 2
# 109 "data/maps/ChiiTown/scripts.pory"
ChiiTown_Mart:
# 110 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_POKE_BALL
# 111 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_BERRY_JUICE
# 112 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 113 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 114 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_AWAKENING
# 115 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 116 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

ChiiTown_EventScript_Samurai::
# 120 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Samurai_Text_0
# 121 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_Samurai_Text_1, MSGBOX_NPC
	return


ChiiTown_EventScript_TownSign::
# 127 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


ChiiTown_EventScript_SetTrespassVar::
# 131 "data/maps/ChiiTown/scripts.pory"
	setvar VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 1
	return


ChiiTown_EventScript_MomWaiting_Text_0:
# 28 "data/maps/ChiiTown/scripts.pory"
	.string "Woman$"

ChiiTown_EventScript_MomWaiting_Text_1:
# 30 "data/maps/ChiiTown/scripts.pory"
	.string "I'm waiting to pick up my children\n"
	.string "after school.\p"
	.string "With all the recent Pokémon attacks,\n"
	.string "I will not let them leave my sight!$"

ChiiTown_EventScript_Shopper_Text_0:
# 69 "data/maps/ChiiTown/scripts.pory"
	.string "The lady who keeps the town's market\n"
	.string "has started selling Pokémon medicine\l"
	.string "and Pokéballs!\p"
	.string "Be careful, though: the ointments she\n"
	.string "sells can't be used in the middle of a\l"
	.string "battle.$"

ChiiTown_EventScript_Kecleon_Text_0:
# 80 "data/maps/ChiiTown/scripts.pory"
	.string "Kecleon$"

ChiiTown_EventScript_Kecleon_Text_1:
# 82 "data/maps/ChiiTown/scripts.pory"
	.string "Weird lizard$"

ChiiTown_EventScript_Kecleon_Text_2:
# 84 "data/maps/ChiiTown/scripts.pory"
	.string "Kleeeeh!$"

ChiiTown_EventScript_PlantingFlowers_Text_0:
# 91 "data/maps/ChiiTown/scripts.pory"
	.string "Little girl$"

ChiiTown_EventScript_PlantingFlowers_Text_1:
# 93 "data/maps/ChiiTown/scripts.pory"
	.string "I'm planting flowers so that the wild\n"
	.string "Pokémon become happy again!$"

ChiiTown_EventScript_Mart_Text_0:
# 100 "data/maps/ChiiTown/scripts.pory"
	.string "Saleswoman$"

ChiiTown_EventScript_Mart_Text_1:
# 101 "data/maps/ChiiTown/scripts.pory"
	.string "Welcome to Chii Town's market! How may\n"
	.string "I help you?$"

ChiiTown_EventScript_Samurai_Text_0:
# 120 "data/maps/ChiiTown/scripts.pory"
	.string "Samurai$"

ChiiTown_EventScript_Samurai_Text_1:
# 122 "data/maps/ChiiTown/scripts.pory"
	.string "There's been reports of some shady\n"
	.string "men dressed in blue loitering around\l"
	.string "the area.\p"
	.string "Be careful when traveling!$"

ChiiTown_EventScript_TownSign_Text_0:
# 127 "data/maps/ChiiTown/scripts.pory"
	.string "Chii Town\n"
	.string "“The smallest town, with the biggest\l"
	.string "heart.”$"

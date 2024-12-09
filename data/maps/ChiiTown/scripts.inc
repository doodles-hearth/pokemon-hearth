ChiiTown_MapScripts::
# 8 "data/maps/ChiiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ChiiTown_MapScripts_MAP_SCRIPT_ON_LOAD
# 11 "data/maps/ChiiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChiiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

ChiiTown_MapScripts_MAP_SCRIPT_ON_LOAD:
# 9 "data/maps/ChiiTown/scripts.pory"
	call ChiiTown_EventScript_SpawnBirds
	return

ChiiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/ChiiTown/scripts.pory"
	map_script_2 VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 2, ChiiTown_EventScript_SetTrespassVar
	.2byte 0


ChiiTown_EventScript_MomWaiting::
# 17 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_MomWaiting_Text_0
# 18 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_MomWaiting_Text_1, MSGBOX_NPC
	return


ChiiTown_EventScript_SpawnBirds::
# 27 "data/maps/ChiiTown/scripts.pory"
	setflag FLAG_TEMP_1
# 28 "data/maps/ChiiTown/scripts.pory"
	setflag FLAG_TEMP_2
# 30 "data/maps/ChiiTown/scripts.pory"
	setflag FLAG_TEMP_3
# 31 "data/maps/ChiiTown/scripts.pory"
	setflag FLAG_TEMP_4
# 33 "data/maps/ChiiTown/scripts.pory"
	gettime
# 35 "data/maps/ChiiTown/scripts.pory"
	compare VAR_0x8000, 5
	goto_if_ge ChiiTown_EventScript_SpawnBirds_6
ChiiTown_EventScript_SpawnBirds_4:
# 44 "data/maps/ChiiTown/scripts.pory"
	compare VAR_0x8000, 9
	goto_if_ge ChiiTown_EventScript_SpawnBirds_3
	return

ChiiTown_EventScript_SpawnBirds_1:
# 36 "data/maps/ChiiTown/scripts.pory"
	random 2
# 37 "data/maps/ChiiTown/scripts.pory"
	switch VAR_RESULT
# 38 "data/maps/ChiiTown/scripts.pory"
	case 0, ChiiTown_EventScript_SpawnBirds_10
# 40 "data/maps/ChiiTown/scripts.pory"
	case 1, ChiiTown_EventScript_SpawnBirds_11
	return

ChiiTown_EventScript_SpawnBirds_2:
# 45 "data/maps/ChiiTown/scripts.pory"
	random 2
# 46 "data/maps/ChiiTown/scripts.pory"
	switch VAR_RESULT
# 47 "data/maps/ChiiTown/scripts.pory"
	case 0, ChiiTown_EventScript_SpawnBirds_13
# 49 "data/maps/ChiiTown/scripts.pory"
	case 1, ChiiTown_EventScript_SpawnBirds_14
	return

ChiiTown_EventScript_SpawnBirds_3:
# 44 "data/maps/ChiiTown/scripts.pory"
	compare VAR_0x8000, 17
	goto_if_le ChiiTown_EventScript_SpawnBirds_2
	return

ChiiTown_EventScript_SpawnBirds_6:
# 35 "data/maps/ChiiTown/scripts.pory"
	compare VAR_0x8000, 8
	goto_if_le ChiiTown_EventScript_SpawnBirds_1
	goto ChiiTown_EventScript_SpawnBirds_4

ChiiTown_EventScript_SpawnBirds_10:
# 39 "data/maps/ChiiTown/scripts.pory"
	clearflag FLAG_TEMP_1
	return

ChiiTown_EventScript_SpawnBirds_11:
# 41 "data/maps/ChiiTown/scripts.pory"
	clearflag FLAG_TEMP_2
	return

ChiiTown_EventScript_SpawnBirds_13:
# 48 "data/maps/ChiiTown/scripts.pory"
	clearflag FLAG_TEMP_3
	return

ChiiTown_EventScript_SpawnBirds_14:
# 50 "data/maps/ChiiTown/scripts.pory"
	clearflag FLAG_TEMP_4
	return


ChiiTown_EventScript_Shopper::
# 56 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_MomWaiting_Text_0
# 57 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_Shopper_Text_0, MSGBOX_NPC
	return


ChiiTown_EventScript_Kecleon::
# 64 "data/maps/ChiiTown/scripts.pory"
	lock
# 65 "data/maps/ChiiTown/scripts.pory"
	faceplayer
# 66 "data/maps/ChiiTown/scripts.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
# 67 "data/maps/ChiiTown/scripts.pory"
	ismonseen SPECIES_KECLEON
# 68 "data/maps/ChiiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne ChiiTown_EventScript_Kecleon_2
# 71 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Kecleon_Text_1
ChiiTown_EventScript_Kecleon_1:
# 73 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_Kecleon_Text_2
# 74 "data/maps/ChiiTown/scripts.pory"
	waitmoncry
# 75 "data/maps/ChiiTown/scripts.pory"
	closemessage
# 76 "data/maps/ChiiTown/scripts.pory"
	release
	return

ChiiTown_EventScript_Kecleon_2:
# 69 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Kecleon_Text_0
	goto ChiiTown_EventScript_Kecleon_1


ChiiTown_EventScript_PlantingFlowers::
# 80 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_PlantingFlowers_Text_0
# 81 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_PlantingFlowers_Text_1, MSGBOX_NPC
	return


ChiiTown_EventScript_Mart::
# 87 "data/maps/ChiiTown/scripts.pory"
	lock
# 88 "data/maps/ChiiTown/scripts.pory"
	faceplayer
# 89 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Mart_Text_0
# 90 "data/maps/ChiiTown/scripts.pory"
	message ChiiTown_EventScript_Mart_Text_1
# 91 "data/maps/ChiiTown/scripts.pory"
	waitmessage
# 92 "data/maps/ChiiTown/scripts.pory"
	pokemart ChiiTown_Mart
# 93 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Mart_Text_0
# 94 "data/maps/ChiiTown/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 95 "data/maps/ChiiTown/scripts.pory"
	release
	return


	.align 2
# 98 "data/maps/ChiiTown/scripts.pory"
ChiiTown_Mart:
# 99 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_POKE_BALL
# 100 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_BERRY_JUICE
# 101 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 102 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 103 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_AWAKENING
# 104 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 105 "data/maps/ChiiTown/scripts.pory"
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

ChiiTown_EventScript_Samurai::
# 109 "data/maps/ChiiTown/scripts.pory"
	speakername ChiiTown_EventScript_Samurai_Text_0
# 110 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_Samurai_Text_1, MSGBOX_NPC
	return


ChiiTown_EventScript_TownSign::
# 116 "data/maps/ChiiTown/scripts.pory"
	msgbox ChiiTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


ChiiTown_EventScript_SetTrespassVar::
# 120 "data/maps/ChiiTown/scripts.pory"
	setvar VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 1
	return


ChiiTown_EventScript_MomWaiting_Text_0:
# 17 "data/maps/ChiiTown/scripts.pory"
	.string "Woman$"

ChiiTown_EventScript_MomWaiting_Text_1:
# 19 "data/maps/ChiiTown/scripts.pory"
	.string "I'm waiting to pick up my children\n"
	.string "after school.\p"
	.string "With all the recent Pokémon attacks,\n"
	.string "I will not let them leave my sight!$"

ChiiTown_EventScript_Shopper_Text_0:
# 58 "data/maps/ChiiTown/scripts.pory"
	.string "The lady who keeps the town's market\n"
	.string "has started selling Pokémon medicine\l"
	.string "and Pokéballs!\p"
	.string "Be careful, though: the ointments she\n"
	.string "sells can't be used in the middle of a\l"
	.string "battle.$"

ChiiTown_EventScript_Kecleon_Text_0:
# 69 "data/maps/ChiiTown/scripts.pory"
	.string "Kecleon$"

ChiiTown_EventScript_Kecleon_Text_1:
# 71 "data/maps/ChiiTown/scripts.pory"
	.string "Weird lizard$"

ChiiTown_EventScript_Kecleon_Text_2:
# 73 "data/maps/ChiiTown/scripts.pory"
	.string "Kleeeeh!$"

ChiiTown_EventScript_PlantingFlowers_Text_0:
# 80 "data/maps/ChiiTown/scripts.pory"
	.string "Little girl$"

ChiiTown_EventScript_PlantingFlowers_Text_1:
# 82 "data/maps/ChiiTown/scripts.pory"
	.string "I'm planting flowers so that the wild\n"
	.string "Pokémon become happy again!$"

ChiiTown_EventScript_Mart_Text_0:
# 89 "data/maps/ChiiTown/scripts.pory"
	.string "Saleswoman$"

ChiiTown_EventScript_Mart_Text_1:
# 90 "data/maps/ChiiTown/scripts.pory"
	.string "Welcome to Chii Town's market! How may\n"
	.string "I help you?$"

ChiiTown_EventScript_Samurai_Text_0:
# 109 "data/maps/ChiiTown/scripts.pory"
	.string "Samurai$"

ChiiTown_EventScript_Samurai_Text_1:
# 111 "data/maps/ChiiTown/scripts.pory"
	.string "There's been reports of some shady\n"
	.string "men dressed in blue loitering around\l"
	.string "the area.\p"
	.string "Be careful when traveling!$"

ChiiTown_EventScript_TownSign_Text_0:
# 116 "data/maps/ChiiTown/scripts.pory"
	.string "Chii Town\n"
	.string "“The smallest town, with the biggest\l"
	.string "heart.”$"

ChiiTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ChiiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, ChiiTown_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChiiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

ChiiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	return

ChiiTown_MapScripts_MAP_SCRIPT_ON_LOAD:
	call ChiiTown_EventScript_SpawnBirds
	return

ChiiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 2, ChiiTown_EventScript_SetTrespassVar
	.2byte 0


ChiiTown_DrawMetatiles::
	gettimeofday
	switch VAR_RESULT
	case TIME_DEAD_NIGHT, ChiiTown_DrawMetatiles_2
	case TIME_EARLY_MORNING, ChiiTown_DrawMetatiles_3
	case TIME_MORNING, ChiiTown_DrawMetatiles_3
	case TIME_LUNCHTIME, ChiiTown_DrawMetatiles_3
	case TIME_NOONTIME, ChiiTown_DrawMetatiles_3
	case TIME_EVENING, ChiiTown_DrawMetatiles_3
	case TIME_NIGHT, ChiiTown_DrawMetatiles_3
ChiiTown_DrawMetatiles_3:
	end

ChiiTown_DrawMetatiles_2:
	setmetatile 14, 6, METATILE_PorytilesPrimaryTutorial_DoorPlaceholder, TRUE
	setmetatile 24, 20, METATILE_PorytilesPrimaryTutorial_DoorPlaceholder, TRUE
	return


ChiiTown_EventScript_SpawnBirds::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_4
	gettime
	compare VAR_0x8000, 5
	goto_if_ge ChiiTown_EventScript_SpawnBirds_6
ChiiTown_EventScript_SpawnBirds_4:
	compare VAR_0x8000, 9
	goto_if_ge ChiiTown_EventScript_SpawnBirds_3
	return

ChiiTown_EventScript_SpawnBirds_1:
	random 2
	switch VAR_RESULT
	case 0, ChiiTown_EventScript_SpawnBirds_10
	case 1, ChiiTown_EventScript_SpawnBirds_11
	return

ChiiTown_EventScript_SpawnBirds_2:
	random 2
	switch VAR_RESULT
	case 0, ChiiTown_EventScript_SpawnBirds_13
	case 1, ChiiTown_EventScript_SpawnBirds_14
	return

ChiiTown_EventScript_SpawnBirds_3:
	compare VAR_0x8000, 17
	goto_if_le ChiiTown_EventScript_SpawnBirds_2
	return

ChiiTown_EventScript_SpawnBirds_6:
	compare VAR_0x8000, 8
	goto_if_le ChiiTown_EventScript_SpawnBirds_1
	goto ChiiTown_EventScript_SpawnBirds_4

ChiiTown_EventScript_SpawnBirds_10:
	clearflag FLAG_TEMP_1
	return

ChiiTown_EventScript_SpawnBirds_11:
	clearflag FLAG_TEMP_2
	return

ChiiTown_EventScript_SpawnBirds_13:
	clearflag FLAG_TEMP_3
	return

ChiiTown_EventScript_SpawnBirds_14:
	clearflag FLAG_TEMP_4
	return


ChiiTown_EventScript_WatchfulMom::
	gettimeofday
	speakername ChiiTown_EventScript_WatchfulMom_Text_0
	switch VAR_RESULT
	case TIME_MORNING, ChiiTown_EventScript_WatchfulMom_3
	case TIME_NOONTIME, ChiiTown_EventScript_WatchfulMom_4
ChiiTown_EventScript_WatchfulMom_1:
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	return

ChiiTown_EventScript_WatchfulMom_3:
	msgbox ChiiTown_EventScript_WatchfulMom_Text_1, MSGBOX_NPC
	goto ChiiTown_EventScript_WatchfulMom_1

ChiiTown_EventScript_WatchfulMom_4:
	msgbox ChiiTown_EventScript_WatchfulMom_Text_2, MSGBOX_NPC
	goto ChiiTown_EventScript_WatchfulMom_1


ChiiTown_EventScript_Shopper::
	speakername ChiiTown_EventScript_WatchfulMom_Text_0
	msgbox ChiiTown_EventScript_Shopper_Text_0, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	return


ChiiTown_EventScript_Kecleon::
	lock
	faceplayer
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	ismonseen SPECIES_KECLEON
	compare VAR_RESULT, 0
	goto_if_ne ChiiTown_EventScript_Kecleon_2
	speakername ChiiTown_EventScript_Kecleon_Text_1
ChiiTown_EventScript_Kecleon_1:
	msgbox ChiiTown_EventScript_Kecleon_Text_2
	waitmoncry
	closemessage
	release
	return

ChiiTown_EventScript_Kecleon_2:
	speakername ChiiTown_EventScript_Kecleon_Text_0
	goto ChiiTown_EventScript_Kecleon_1


ChiiTown_EventScript_PlantingFlowers::
	speakername ChiiTown_EventScript_PlantingFlowers_Text_0
	msgbox ChiiTown_EventScript_PlantingFlowers_Text_1, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	return


ChiiTown_EventScript_AlsoPlantingFlowers::
	speakername ChiiTown_EventScript_AlsoPlantingFlowers_Text_0
	msgbox ChiiTown_EventScript_AlsoPlantingFlowers_Text_1, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	return


ChiiTown_EventScript_WatchingTheChildren::
	speakername ChiiTown_EventScript_WatchingTheChildren_Text_0
	msgbox ChiiTown_EventScript_WatchingTheChildren_Text_1, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	return


ChiiTown_EventScript_EatingBerries::
	lock
	faceplayer
	speakername ChiiTown_EventScript_EatingBerries_Text_0
	msgbox ChiiTown_EventScript_EatingBerries_Text_1, MSGBOX_DEFAULT
	closemessage
	checkitem 520, 1
	compare VAR_RESULT, TRUE
	goto_if_eq ChiiTown_EventScript_EatingBerries_2
ChiiTown_EventScript_EatingBerries_1:
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return

ChiiTown_EventScript_EatingBerries_2:
	msgbox ChiiTown_EventScript_EatingBerries_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ChiiTown_EventScript_EatingBerries_4
	goto ChiiTown_EventScript_EatingBerries_1

ChiiTown_EventScript_EatingBerries_4:
	removeitem 520, 1
	speakername ChiiTown_EventScript_EatingBerries_Text_0
	msgbox ChiiTown_EventScript_EatingBerries_Text_3, MSGBOX_DEFAULT
	goto ChiiTown_EventScript_EatingBerries_1


ChiiTown_EventScript_BerryEnthusiast::
	speakername ChiiTown_EventScript_BerryEnthusiast_Text_0
	msgbox ChiiTown_EventScript_BerryEnthusiast_Text_1, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	return


ChiiTown_EventScript_Mart::
	lock
	faceplayer
	speakername ChiiTown_EventScript_Mart_Text_0
	message ChiiTown_EventScript_Mart_Text_1
	waitmessage
	pokemart ChiiTown_Mart
	speakername ChiiTown_EventScript_Mart_Text_0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	return


	.align 2
ChiiTown_Mart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_BERRY_JUICE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

ChiiTown_EventScript_Samurai::
	speakername ChiiTown_EventScript_Samurai_Text_0
	msgbox ChiiTown_EventScript_Samurai_Text_1, MSGBOX_NPC
	return


ChiiTown_EventScript_TownSign::
	msgbox ChiiTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


ChiiTown_EventScript_SetTrespassVar::
	setvar VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 1
	return


ChiiTown_EventScript_WatchfulMom_Text_0:
	.string "Woman$"

ChiiTown_EventScript_WatchfulMom_Text_1:
	.string "I'm dropping off my children to\n"
	.string "school.\p"
	.string "With all the recent Pokémon attacks,\n"
	.string "I will not let them leave my sight!$"

ChiiTown_EventScript_WatchfulMom_Text_2:
	.string "I'm waiting to pick up my children\n"
	.string "after school.\p"
	.string "With all the recent Pokémon attacks,\n"
	.string "I will not let them leave my sight!$"

ChiiTown_EventScript_Shopper_Text_0:
	.string "The lady who keeps the town's market\n"
	.string "has started selling Pokémon medicine\l"
	.string "and Poké Balls!\p"
	.string "Be careful, though: the ointments she\n"
	.string "sells can't be used in the middle of a\l"
	.string "battle.$"

ChiiTown_EventScript_Kecleon_Text_0:
	.string "Kecleon$"

ChiiTown_EventScript_Kecleon_Text_1:
	.string "Weird lizard$"

ChiiTown_EventScript_Kecleon_Text_2:
	.string "Kleeeeh!$"

ChiiTown_EventScript_PlantingFlowers_Text_0:
	.string "Little girl$"

ChiiTown_EventScript_PlantingFlowers_Text_1:
	.string "I'm planting flowers so that the wild\n"
	.string "Pokémon become happy again!$"

ChiiTown_EventScript_AlsoPlantingFlowers_Text_0:
	.string "Little boy$"

ChiiTown_EventScript_AlsoPlantingFlowers_Text_1:
	.string "She's making me plant flowers so that\n"
	.string "the wild Pokémon become happy again.\p"
	.string "I'm not though…$"

ChiiTown_EventScript_WatchingTheChildren_Text_0:
	.string "Sensei$"

ChiiTown_EventScript_WatchingTheChildren_Text_1:
	.string "To make sure the children's energy\n"
	.string "isn't pent up too much, I bring them\l"
	.string "out for recess.$"

ChiiTown_EventScript_EatingBerries_Text_0:
	.string "Twin girl$"

ChiiTown_EventScript_EatingBerries_Text_1:
	.string "Sensei said that we should eat\n"
	.string "berries to grow big and strong!\p"
	.string "But how are we supposed to get them\n"
	.string "if we aren't big and strong yet?$"

ChiiTown_EventScript_EatingBerries_Text_2:
	.string "Give the girl an Oran Berry?$"

ChiiTown_EventScript_EatingBerries_Text_3:
	.string "Oh my gosh, thank you!$"

ChiiTown_EventScript_BerryEnthusiast_Text_0:
	.string "Twin boy$"

ChiiTown_EventScript_BerryEnthusiast_Text_1:
	.string "I've been eating berries just like\n"
	.string "Sensei said, but I haven't grown yet.\p"
	.string "I don't care though. They're\n"
	.string "delicious!$"

ChiiTown_EventScript_Mart_Text_0:
	.string "Saleswoman$"

ChiiTown_EventScript_Mart_Text_1:
	.string "Welcome to Chii Town's market! How may\n"
	.string "I help you?$"

ChiiTown_EventScript_Samurai_Text_0:
	.string "Samurai$"

ChiiTown_EventScript_Samurai_Text_1:
	.string "There's been reports of some shady\n"
	.string "men dressed in blue loitering around\l"
	.string "the area.\p"
	.string "Be careful when traveling!$"

ChiiTown_EventScript_TownSign_Text_0:
	.string "Chii Town\n"
	.string "“The smallest town, with the biggest\l"
	.string "heart.”$"

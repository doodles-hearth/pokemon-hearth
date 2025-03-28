ChiiTown_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ChiiTown_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChiiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

ChiiTown_MapScripts_MAP_SCRIPT_ON_LOAD:
	call ChiiTown_DrawMetatiles
	return

ChiiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 2, ChiiTown_EventScript_SetTrespassVar
	.2byte 0


ChiiTown_DrawMetatiles::
	goto_if_set FLAG_BADGE01_GET, ChiiTown_DrawMetatiles_2
ChiiTown_DrawMetatiles_1:
	goto_if_set FLAG_BADGE03_GET, ChiiTown_DrawMetatiles_5
ChiiTown_DrawMetatiles_4:
	goto_if_set FLAG_BADGE04_GET, ChiiTown_DrawMetatiles_8
ChiiTown_DrawMetatiles_7:
	goto_if_set FLAG_BADGE05_GET, ChiiTown_DrawMetatiles_11
ChiiTown_DrawMetatiles_10:
	goto_if_set FLAG_BADGE06_GET, ChiiTown_DrawMetatiles_14
ChiiTown_DrawMetatiles_13:
	goto_if_set FLAG_BADGE08_GET, ChiiTown_DrawMetatiles_17
ChiiTown_DrawMetatiles_16:
	gettimeofday
	switch VAR_RESULT
	case TIME_DEAD_NIGHT, ChiiTown_DrawMetatiles_20
	case TIME_EARLY_MORNING, ChiiTown_DrawMetatiles_21
	case TIME_MORNING, ChiiTown_DrawMetatiles_21
	case TIME_LUNCHTIME, ChiiTown_DrawMetatiles_21
	case TIME_AFTERNOON, ChiiTown_DrawMetatiles_21
	case TIME_EVENING, ChiiTown_DrawMetatiles_21
	case TIME_NIGHT, ChiiTown_DrawMetatiles_21
ChiiTown_DrawMetatiles_21:
	end

ChiiTown_DrawMetatiles_2:
	setmetatile 17, 18, METATILE_PorytilesPrimaryTutorial_RedFlowers, FALSE
	setmetatile 17, 19, METATILE_PorytilesPrimaryTutorial_RedFlowers, FALSE
	goto ChiiTown_DrawMetatiles_1

ChiiTown_DrawMetatiles_5:
	setmetatile 16, 16, METATILE_PorytilesPrimaryTutorial_RedFlowers, FALSE
	goto ChiiTown_DrawMetatiles_4

ChiiTown_DrawMetatiles_8:
	setmetatile 11, 20, METATILE_PorytilesPrimaryTutorial_RedFlowers, FALSE
	setmetatile 15, 22, METATILE_PorytilesPrimaryTutorial_RedFlowers, FALSE
	goto ChiiTown_DrawMetatiles_7

ChiiTown_DrawMetatiles_11:
	setmetatile 16, 22, METATILE_PorytilesPrimaryTutorial_RedFlowers, FALSE
	goto ChiiTown_DrawMetatiles_10

ChiiTown_DrawMetatiles_14:
	setmetatile 18, 23, METATILE_PorytilesPrimaryTutorial_RedFlowers, FALSE
	setmetatile 17, 16, METATILE_PorytilesPrimaryTutorial_RedFlowers, FALSE
	goto ChiiTown_DrawMetatiles_13

ChiiTown_DrawMetatiles_17:
	setmetatile 10, 21, METATILE_PorytilesPrimaryTutorial_RedFlowers, FALSE
	setmetatile 16, 19, METATILE_PorytilesPrimaryTutorial_RedFlowers, FALSE
	setmetatile 21, 23, METATILE_PorytilesPrimaryTutorial_RedFlowers, FALSE
	goto ChiiTown_DrawMetatiles_16

ChiiTown_DrawMetatiles_20:
	setmetatile 14, 5, METATILE_PorytilesPrimaryTutorial_ClosedDoorTop, TRUE
	setmetatile 14, 6, METATILE_PorytilesPrimaryTutorial_ClosedDoorBottom, TRUE
	return


ChiiTown_EventScript_WatchfulMom::
	gettimeofday
	speakername ChiiTown_EventScript_WatchfulMom_Text_0
	switch VAR_RESULT
	case TIME_MORNING, ChiiTown_EventScript_WatchfulMom_3
	case TIME_AFTERNOON, ChiiTown_EventScript_WatchfulMom_4
	msgbox ChiiTown_EventScript_WatchfulMom_Text_3, MSGBOX_NPC
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
	setseenmon SPECIES_KECLEON
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_KECLEON
	msgbox ChiiTown_EventScript_Kecleon_Text_0
	waitmoncry
	closemessage
	release
	return


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
	checkitem ITEM_ORAN_BERRY, 1
	compare VAR_RESULT, 0
	goto_if_ne ChiiTown_EventScript_EatingBerries_2
ChiiTown_EventScript_EatingBerries_1:
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return

ChiiTown_EventScript_EatingBerries_2:
	msgbox ChiiTown_EventScript_EatingBerries_Text_2
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, ChiiTown_EventScript_EatingBerries_Text_3, ChiiTown_EventScript_EatingBerries_Text_4
	compare VAR_RESULT, 0
	goto_if_eq ChiiTown_EventScript_EatingBerries_4
	goto ChiiTown_EventScript_EatingBerries_1

ChiiTown_EventScript_EatingBerries_4:
	removeitem ITEM_ORAN_BERRY
	speakername ChiiTown_EventScript_EatingBerries_Text_0
	msgbox ChiiTown_EventScript_EatingBerries_Text_5, MSGBOX_DEFAULT
	closemessage
	addvar VAR_PLAYER_REPUTATION, 1
	goto ChiiTown_EventScript_EatingBerries_1


ChiiTown_EventScript_BerryEnthusiast::
	lock
	faceplayer
	speakername ChiiTown_EventScript_BerryEnthusiast_Text_0
	msgbox ChiiTown_EventScript_BerryEnthusiast_Text_1
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return


ChiiTown_EventScript_BattlingGirl::
	lock
	faceplayer
	goto_if_set FLAG_BEAT_CHII_TOWN_KIDS, ChiiTown_EventScript_BattlingGirl_2
	compare VAR_FACING, DIR_NORTH
	goto_if_eq ChiiTown_EventScript_BattlingGirl_6
	applymovement 16, ChiiTown_EventScript_BattlingGirl_Movement_1
ChiiTown_EventScript_BattlingGirl_5:
	waitmovement 0
	special GetPlayerMrMrsString
	speakername ChiiTown_EventScript_PlantingFlowers_Text_0
	msgbox ChiiTown_EventScript_BattlingGirl_Text_1
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, ChiiTown_EventScript_BattlingGirl_Text_2, ChiiTown_EventScript_BattlingGirl_Text_3
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq ChiiTown_EventScript_BattlingGirl_10
	speakername ChiiTown_EventScript_PlantingFlowers_Text_0
	msgbox ChiiTown_EventScript_BattlingGirl_Text_6
	closemessage
ChiiTown_EventScript_BattlingGirl_9:
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	applymovement 16, ChiiTown_EventScript_BattlingGirl_Movement_1
	waitmovement 0
ChiiTown_EventScript_BattlingGirl_1:
	release
	return

ChiiTown_EventScript_BattlingGirl_2:
	special GetPlayerMrMrsString
	speakername ChiiTown_EventScript_PlantingFlowers_Text_0
	msgbox ChiiTown_EventScript_BattlingGirl_Text_0
	closemessage
	goto ChiiTown_EventScript_BattlingGirl_1

ChiiTown_EventScript_BattlingGirl_6:
	applymovement 16, ChiiTown_EventScript_BattlingGirl_Movement_0
	goto ChiiTown_EventScript_BattlingGirl_5

ChiiTown_EventScript_BattlingGirl_10:
	trainerbattle_two_trainers TRAINER_MINORI, ChiiTown_EventScript_BattlingGirl_Text_4, TRAINER_KAITO, ChiiTown_EventScript_BattlingGirl_Text_5
	setflag FLAG_BEAT_CHII_TOWN_KIDS
	special GetPlayerMrMrsString
	speakername ChiiTown_EventScript_PlantingFlowers_Text_0
	msgbox ChiiTown_EventScript_BattlingGirl_Text_0
	closemessage
	goto ChiiTown_EventScript_BattlingGirl_9


ChiiTown_EventScript_BattlingBoy::
	lock
	faceplayer
	goto_if_set FLAG_BEAT_CHII_TOWN_KIDS, ChiiTown_EventScript_BattlingBoy_2
	applymovement 15, ChiiTown_EventScript_BattlingGirl_Movement_0
	waitmovement 0
	special GetPlayerMrMrsString
	speakername ChiiTown_EventScript_AlsoPlantingFlowers_Text_0
	msgbox ChiiTown_EventScript_BattlingBoy_Text_1
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, ChiiTown_EventScript_BattlingGirl_Text_2, ChiiTown_EventScript_BattlingGirl_Text_3
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq ChiiTown_EventScript_BattlingBoy_6
	speakername ChiiTown_EventScript_AlsoPlantingFlowers_Text_0
	msgbox ChiiTown_EventScript_BattlingBoy_Text_2
	closemessage
ChiiTown_EventScript_BattlingBoy_5:
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	applymovement 15, ChiiTown_EventScript_BattlingBoy_Movement_0
	waitmovement 0
ChiiTown_EventScript_BattlingBoy_1:
	release
	return

ChiiTown_EventScript_BattlingBoy_2:
	special GetPlayerMrMrsString
	speakername ChiiTown_EventScript_AlsoPlantingFlowers_Text_0
	msgbox ChiiTown_EventScript_BattlingBoy_Text_0
	closemessage
	goto ChiiTown_EventScript_BattlingBoy_1

ChiiTown_EventScript_BattlingBoy_6:
	trainerbattle_two_trainers TRAINER_MINORI, ChiiTown_EventScript_BattlingGirl_Text_4, TRAINER_KAITO, ChiiTown_EventScript_BattlingGirl_Text_5
	setflag FLAG_BEAT_CHII_TOWN_KIDS
	special GetPlayerMrMrsString
	speakername ChiiTown_EventScript_AlsoPlantingFlowers_Text_0
	msgbox ChiiTown_EventScript_BattlingBoy_Text_0
	closemessage
	goto ChiiTown_EventScript_BattlingBoy_5


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
	.2byte ITEM_OINTMENT
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_NONE

ChiiTown_EventScript_Samurai::
	speakername ChiiTown_EventScript_Samurai_Text_0
	msgbox ChiiTown_EventScript_Samurai_Text_1, MSGBOX_NPC
	return


ChiiTown_EventScript_TownSign::
	msgbox ChiiTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


ChiiTown_EventScript_SchoolSign::
	msgbox ChiiTown_EventScript_SchoolSign_Text_0, MSGBOX_SIGN
	return


ChiiTown_EventScript_SetTrespassVar::
	setvar VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 1
	return


ChiiTown_EventScript_BattlingGirl_Movement_0:
	face_down
	step_end

ChiiTown_EventScript_BattlingGirl_Movement_1:
	face_left
	step_end

ChiiTown_EventScript_BattlingBoy_Movement_0:
	face_right
	step_end

ChiiTown_EventScript_WatchfulMom_Text_0:
	.string "Woman$"

ChiiTown_EventScript_WatchfulMom_Text_1:
	.string "I'm dropping off my children to\n"
	.string "school.\p"
	.string "With all the recent Pokémon\n"
	.string "attacks, I will not let them\l"
	.string "leave my sight!$"

ChiiTown_EventScript_WatchfulMom_Text_2:
	.string "I'm waiting to pick up my children\n"
	.string "after school.\p"
	.string "With all the recent Pokémon\n"
	.string "attacks, I will not let them\l"
	.string "leave my sight!$"

ChiiTown_EventScript_WatchfulMom_Text_3:
	.string "Phew… Being a full-time mom is\n"
	.string "exhausting…$"

ChiiTown_EventScript_Shopper_Text_0:
	.string "The lady who keeps the town's\n"
	.string "market has started selling Pokémon\l"
	.string "medicine and Poké Balls!\p"
	.string "Be careful, though: the ointments\n"
	.string "she sells can't be used in the\l"
	.string "middle of a battle.\p"
	.string "They are super cheap though, so\n"
	.string "don't be afraid to use them so\l"
	.string "you don't always have to run to\l"
	.string "the nearest refuge!$"

ChiiTown_EventScript_Kecleon_Text_0:
	.string "Kleeeeh!$"

ChiiTown_EventScript_PlantingFlowers_Text_0:
	.string "Little girl$"

ChiiTown_EventScript_PlantingFlowers_Text_1:
	.string "I'm planting flowers so that the\n"
	.string "wild Pokémon become happy again!$"

ChiiTown_EventScript_AlsoPlantingFlowers_Text_0:
	.string "Little boy$"

ChiiTown_EventScript_AlsoPlantingFlowers_Text_1:
	.string "She's making me plant flowers so\n"
	.string "that the wild Pokémon become\l"
	.string "happy again.\p"
	.string "I'm not though…$"

ChiiTown_EventScript_WatchingTheChildren_Text_0:
	.string "Sensei$"

ChiiTown_EventScript_WatchingTheChildren_Text_1:
	.string "To make sure the children's energy\n"
	.string "isn't pent up too much, I bring\l"
	.string "them out for recess.$"

ChiiTown_EventScript_EatingBerries_Text_0:
	.string "Twin girl$"

ChiiTown_EventScript_EatingBerries_Text_1:
	.string "Sensei said that we should eat\n"
	.string "berries to grow big and strong!\p"
	.string "But how are we supposed to get\n"
	.string "them if we aren't big and strong\l"
	.string "yet?$"

ChiiTown_EventScript_EatingBerries_Text_2:
	.string "Give the girl an Oran Berry?$"

ChiiTown_EventScript_EatingBerries_Text_3:
	.string "Give$"

ChiiTown_EventScript_EatingBerries_Text_4:
	.string "Don't give$"

ChiiTown_EventScript_EatingBerries_Text_5:
	.string "Oh my gosh, thank you!$"

ChiiTown_EventScript_BerryEnthusiast_Text_0:
	.string "Twin boy$"

ChiiTown_EventScript_BerryEnthusiast_Text_1:
	.string "I've been eating berries just like\n"
	.string "Sensei said, but I haven't grown\l"
	.string "yet.\p"
	.string "I don't care though. They're\n"
	.string "delicious!$"

ChiiTown_EventScript_BattlingGirl_Text_0:
	.string "Wow, {STR_VAR_1}! You're super\n"
	.string "strong!!\p"
	.string "I'll have to train Snuggles a whole\n"
	.string "lot more!$"

ChiiTown_EventScript_BattlingGirl_Text_1:
	.string "Hey {STR_VAR_1}! We've been\n"
	.string "studying Pokémon battles in class.\l"
	.string "Wanna fight with us?$"

ChiiTown_EventScript_BattlingGirl_Text_2:
	.string "Sure!$"

ChiiTown_EventScript_BattlingGirl_Text_3:
	.string "I don't want to.$"

ChiiTown_EventScript_BattlingGirl_Text_4:
	.string "Whaaaat?!$"

ChiiTown_EventScript_BattlingGirl_Text_5:
	.string "Well I never learned about THAT!$"

ChiiTown_EventScript_BattlingGirl_Text_6:
	.string "Ughhhh, older kids are so boooring!$"

ChiiTown_EventScript_BattlingBoy_Text_0:
	.string "Wow, {STR_VAR_1}! Can you be\n"
	.string "our sensei?\p"
	.string "That way, Destroyer will be\n"
	.string "invincible!$"

ChiiTown_EventScript_BattlingBoy_Text_1:
	.string "Hello {STR_VAR_1}! We're top of\n"
	.string "our class! That means we're\l"
	.string "strong! Wanna battle us?$"

ChiiTown_EventScript_BattlingBoy_Text_2:
	.string "Fine! Go do grownup stuff!$"

ChiiTown_EventScript_Mart_Text_0:
	.string "Shopkeeper$"

ChiiTown_EventScript_Mart_Text_1:
	.string "Welcome to Chii Town's market! How\n"
	.string "may I help you?$"

ChiiTown_EventScript_Samurai_Text_0:
	.string "Samurai$"

ChiiTown_EventScript_Samurai_Text_1:
	.string "There's been reports of some shady\n"
	.string "men dressed in blue loitering\l"
	.string "around the area.\p"
	.string "Be careful when traveling!$"

ChiiTown_EventScript_TownSign_Text_0:
	.string "Chii Town\n"
	.string "“The smallest town, with the\l"
	.string "biggest heart.”$"

ChiiTown_EventScript_SchoolSign_Text_0:
	.string "“Little Deerling elementary school”$"

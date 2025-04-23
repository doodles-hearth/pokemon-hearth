TranquilRoute_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TranquilRoute_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_TRANSITION, TranquilRoute_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TranquilRoute_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

TranquilRoute_MapScripts_MAP_SCRIPT_ON_LOAD:
	call TranquilRoute_EventScript_CheckCutGrass
	call TranquilRoute_EventScript_FlowerCutMastersGarden
	call TranquilRoute_EventScript_SpawnBirds
	return

TranquilRoute_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call TranquilRoute_EventScript_SetupCutGrassCutscene
	goto_if_set FLAG_BADGE02_GET, TranquilRoute_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

TranquilRoute_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setvar VAR_TEMP_1, 1
	return

TranquilRoute_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 1, TranquilRoute_EventScript_GrassCutscene
	.2byte 0


TranquilRoute_EventScript_SpawnBirds::
	setflag FLAG_TEMP_2
	gettime
	compare VAR_0x8000, 9
	goto_if_ge TranquilRoute_EventScript_SpawnBirds_2
	return

TranquilRoute_EventScript_SpawnBirds_1:
	clearflag FLAG_TEMP_2
	return

TranquilRoute_EventScript_SpawnBirds_2:
	compare VAR_0x8000, 17
	goto_if_le TranquilRoute_EventScript_SpawnBirds_1
	return


TranquilRoute_EventScript_GrassCutscene::
	lock
	applymovement 19, TranquilRoute_EventScript_GrassCutscene_Movement_0
	applymovement OBJ_EVENT_ID_PLAYER, TranquilRoute_EventScript_GrassCutscene_Movement_1
	waitmovement 19
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 24
	speakername TranquilRoute_EventScript_GrassCutscene_Text_0
	msgbox TranquilRoute_EventScript_GrassCutscene_Text_1
	closemessage
	delay 16
	applymovement 19, TranquilRoute_EventScript_GrassCutscene_Movement_2
	waitmovement 0
	delay 24
	speakername TranquilRoute_EventScript_GrassCutscene_Text_0
	msgbox TranquilRoute_EventScript_GrassCutscene_Text_2
	closemessage
	applymovement 19, TranquilRoute_EventScript_GrassCutscene_Movement_3
	waitmovement 0
	delay 24
	delay 24
	speakername TranquilRoute_EventScript_GrassCutscene_Text_0
	msgbox TranquilRoute_EventScript_GrassCutscene_Text_3
	closemessage
	applymovement 19, TranquilRoute_EventScript_GrassCutscene_Movement_4
	waitmovement 0
	delay 48
	speakername TranquilRoute_EventScript_GrassCutscene_Text_0
	msgbox TranquilRoute_EventScript_GrassCutscene_Text_4
	closemessage
	giveitem ITEM_LEAF_STONE
	setobjectmovementtype 19, MOVEMENT_TYPE_WANDER_AROUND
	setflag FLAG_CUT_QUEST_COMPLETED
	setflag FLAG_TEMP_3
	setvar VAR_TEMP_0, 0
	release
	return


TranquilRoute_EventScript_SetupCutGrassCutscene::
	goto_if_unset FLAG_CUT_QUEST_COMPLETED, TranquilRoute_EventScript_SetupCutGrassCutscene_1
	gettimeofday
	switch VAR_RESULT
	case TIME_EVENING, TranquilRoute_EventScript_SetupCutGrassCutscene_8
	case TIME_NIGHT, TranquilRoute_EventScript_SetupCutGrassCutscene_8
	case TIME_DEAD_NIGHT, TranquilRoute_EventScript_SetupCutGrassCutscene_8
	return

TranquilRoute_EventScript_SetupCutGrassCutscene_1:
	goto_if_set FLAG_CUT_QUEST_CUT_ALL_GRASS, TranquilRoute_EventScript_SetupCutGrassCutscene_4
	setflag FLAG_TEMP_1
	return

TranquilRoute_EventScript_SetupCutGrassCutscene_4:
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
	compare VAR_TEMP_2, 43
	goto_if_eq TranquilRoute_EventScript_SetupCutGrassCutscene_10
	return

TranquilRoute_EventScript_SetupCutGrassCutscene_8:
	setflag FLAG_TEMP_1
	return

TranquilRoute_EventScript_SetupCutGrassCutscene_9:
	setobjectmovementtype 19, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm 19, 44, 33
	setvar VAR_TEMP_0, 1
	return

TranquilRoute_EventScript_SetupCutGrassCutscene_10:
	compare VAR_TEMP_3, 33
	goto_if_eq TranquilRoute_EventScript_SetupCutGrassCutscene_9
	return


TranquilRoute_EventScript_CutMaster::
	speakername TranquilRoute_EventScript_GrassCutscene_Text_0
	msgbox TranquilRoute_EventScript_CutMaster_Text_0, MSGBOX_NPC
	return


TranquilRoute_EventScript_FlowerCutMastersGarden::
	goto_if_set FLAG_CUT_QUEST_COMPLETED, TranquilRoute_EventScript_FlowerCutMastersGarden_2
	return

TranquilRoute_EventScript_FlowerCutMastersGarden_1:
	goto_if_set FLAG_BADGE02_GET, TranquilRoute_EventScript_FlowerCutMastersGarden_6
TranquilRoute_EventScript_FlowerCutMastersGarden_5:
	goto_if_set FLAG_BADGE03_GET, TranquilRoute_EventScript_FlowerCutMastersGarden_8
	return

TranquilRoute_EventScript_FlowerCutMastersGarden_2:
	goto_if_unset FLAG_TEMP_3, TranquilRoute_EventScript_FlowerCutMastersGarden_1
	return

TranquilRoute_EventScript_FlowerCutMastersGarden_6:
	setmetatile 39, 33, METATILE_SunriseVillage_RedFlowers, FALSE
	setmetatile 40, 34, METATILE_SunriseVillage_RedFlowers, FALSE
	setmetatile 41, 33, METATILE_SunriseVillage_RedFlowers, FALSE
	setmetatile 42, 34, METATILE_SunriseVillage_RedFlowers, FALSE
	goto TranquilRoute_EventScript_FlowerCutMastersGarden_5

TranquilRoute_EventScript_FlowerCutMastersGarden_8:
	setmetatile 35, 29, METATILE_SunriseVillage_RedFlowers, FALSE
	setmetatile 34, 30, METATILE_SunriseVillage_RedFlowers, FALSE
	setmetatile 35, 31, METATILE_SunriseVillage_RedFlowers, FALSE
	setmetatile 34, 32, METATILE_SunriseVillage_RedFlowers, FALSE
	return


TranquilRoute_EventScript_CheckCutGrass::
	call_if_set FLAG_CUT_QUEST_CUT_ALL_GRASS, TranquilRoute_EventScript_CutGrass
	return


TranquilRoute_EventScript_CutGrass::
	setmetatile 32, 18, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
	setmetatile 34, 18, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 35, 18, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 36, 18, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	setmetatile 37, 18, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 38, 18, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
	setmetatile 31, 19, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 33, 19, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	setmetatile 34, 19, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	setmetatile 35, 19, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 36, 19, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
	setmetatile 37, 19, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 38, 19, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	setmetatile 39, 19, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 32, 20, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 33, 20, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	setmetatile 34, 20, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	setmetatile 35, 20, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 36, 20, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 37, 20, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
	setmetatile 38, 20, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	setmetatile 39, 20, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 31, 21, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 32, 21, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 33, 21, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	setmetatile 34, 21, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
	setmetatile 36, 21, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	setmetatile 37, 21, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
	setmetatile 38, 21, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 39, 21, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	setmetatile 33, 22, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 37, 22, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	setmetatile 38, 22, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 37, 23, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	setmetatile 38, 23, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	setmetatile 38, 24, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 38, 25, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
	setmetatile 38, 26, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
	setmetatile 39, 26, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 37, 27, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	setmetatile 38, 27, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 39, 27, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	setmetatile 37, 28, METATILE_PorytilesPrimaryTutorial_Grass3, FALSE
	setmetatile 38, 28, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	setmetatile 39, 28, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	setmetatile 37, 29, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	setmetatile 38, 29, METATILE_PorytilesPrimaryTutorial_Grass, FALSE
	setmetatile 38, 30, METATILE_PorytilesPrimaryTutorial_Grass2, FALSE
	return


TranquilRoute_EventScript_Chikao::
	trainerbattle_single TRAINER_CHIKAO, TranquilRoute_EventScript_Chikao_Text_0, TranquilRoute_EventScript_Chikao_Text_1
	speakername TranquilRoute_EventScript_Chikao_Text_2
	msgbox TranquilRoute_EventScript_Chikao_Text_3
	closemessage
	end


TranquilRoute_EventScript_Kodomo::
	trainerbattle_single TRAINER_KODOMO, TranquilRoute_EventScript_Kodomo_Text_0, TranquilRoute_EventScript_Kodomo_Text_1
	speakername TranquilRoute_EventScript_Kodomo_Text_2
	msgbox TranquilRoute_EventScript_Kodomo_Text_3
	closemessage
	end


TranquilRoute_EventScript_Takeshi::
	trainerbattle_single TRAINER_TAKESHI, TranquilRoute_EventScript_Takeshi_Text_0, TranquilRoute_EventScript_Takeshi_Text_1
	speakername TranquilRoute_EventScript_Takeshi_Text_2
	msgbox TranquilRoute_EventScript_Takeshi_Text_3, MSGBOX_AUTOCLOSE
	end


TranquilRoute_EventScript_Hana::
	trainerbattle_single TRAINER_HIINA, TranquilRoute_EventScript_Hana_Text_0, TranquilRoute_EventScript_Hana_Text_1
	speakername TranquilRoute_EventScript_Hana_Text_2
	msgbox TranquilRoute_EventScript_Hana_Text_3, MSGBOX_AUTOCLOSE
	end


TranquilRoute_EventScript_Kenji::
	trainerbattle_single TRAINER_KENJI, TranquilRoute_EventScript_Kenji_Text_0, TranquilRoute_EventScript_Kenji_Text_1
	speakername TranquilRoute_EventScript_Kenji_Text_2
	msgbox TranquilRoute_EventScript_Kenji_Text_3, MSGBOX_AUTOCLOSE
	end


TranquilRoute_Movement_MysteriousSamuraiWalksAway:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

TranquilRoute_EventScript_Girl::
	speakername TranquilRoute_EventScript_Girl_Text_0
	msgbox TranquilRoute_EventScript_Girl_Text_1, MSGBOX_NPC
	return


TranquilRoute_EventScript_WhiteslateRoadblock::
	lock
	applymovement 21, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	speakername TranquilRoute_EventScript_WhiteslateRoadblock_Text_0
	msgbox TranquilRoute_EventScript_WhiteslateRoadblock_Text_1
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TranquilRoute_EventScript_WhiteslateRoadblock_Movement_0
	waitmovement 0
	release
	return


TranquilRoute_EventScript_Shellos::
	lock
	faceplayer
	setseenmon SPECIES_SHELLOS
	playmoncry SPECIES_SHELLOS, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_SHELLOS
	msgbox TranquilRoute_EventScript_Shellos_Text_0
	waitmoncry
	closemessage
	release
	end


TranquilRoute_EventScript_BerryWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_PAIL, TranquilRoute_EventScript_BerryWoman_2
	speakername TranquilRoute_EventScript_BerryWoman_Text_0
	msgbox TranquilRoute_EventScript_BerryWoman_Text_2
	closemessage
	applymovement 5, Common_Movement_FaceRight
	waitmovement 0
	delay 48
	applymovement 5, Common_Movement_FacePlayer
	waitmovement 0
	speakername TranquilRoute_EventScript_BerryWoman_Text_0
	msgbox TranquilRoute_EventScript_BerryWoman_Text_3
	closemessage
	giveitem ITEM_ORAN_BERRY, 3
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	speakername TranquilRoute_EventScript_BerryWoman_Text_0
	msgbox TranquilRoute_EventScript_BerryWoman_Text_4
	closemessage
	giveitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	speakername TranquilRoute_EventScript_BerryWoman_Text_0
	msgbox TranquilRoute_EventScript_BerryWoman_Text_5
	closemessage
	setflag FLAG_RECEIVED_WAILMER_PAIL
TranquilRoute_EventScript_BerryWoman_1:
	release
	end

TranquilRoute_EventScript_BerryWoman_2:
	speakername TranquilRoute_EventScript_BerryWoman_Text_0
	msgbox TranquilRoute_EventScript_BerryWoman_Text_1
	closemessage
	goto TranquilRoute_EventScript_BerryWoman_1


TranquilRoute_EventScript_Mareep::
	lock
	setseenmon SPECIES_MAREEP
	playmoncry SPECIES_MAREEP, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_MAREEP
	msgbox TranquilRoute_EventScript_Mareep_Text_0
	waitmoncry
	release
	return


TranquilRoute_EventScript_Mareep2::
	lock
	setseenmon SPECIES_MAREEP
	playmoncry SPECIES_MAREEP, CRY_MODE_WEAK
	setspeakertomonname SPECIES_MAREEP
	msgbox TranquilRoute_EventScript_Mareep2_Text_0
	waitmoncry
	release
	return


TranquilRoute_TrainerTips1::
	msgbox TranquilRoute_TrainerTips1_Text_0, MSGBOX_SIGN
	return


TranquilRoute_EventScript_CrobatShadows_Camera::
	lock
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, TranquilRoute_EventScript_CrobatShadows_Camera_Movement_0
	waitmovement 0
	call TranquilRoute_EventScript_CrobatShadows_Cutscene
	applymovement OBJ_EVENT_ID_CAMERA, TranquilRoute_EventScript_CrobatShadows_Camera_Movement_1
	waitmovement 0
	special RemoveCameraObject
	release
	return


TranquilRoute_EventScript_CrobatShadows::
	lock
	call TranquilRoute_EventScript_CrobatShadows_Cutscene
	release
	return


TranquilRoute_EventScript_CrobatShadows_Cutscene::
	setvar VAR_CROBAT_SHADOWS_FIRST_ENCOUNTERS_STATE, 1
	speakername TranquilRoute_EventScript_CrobatShadows_Cutscene_Text_0
	msgbox TranquilRoute_EventScript_CrobatShadows_Cutscene_Text_1
	closemessage
	delay 20
	applymovement 24, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	speakername TranquilRoute_EventScript_CrobatShadows_Cutscene_Text_2
	msgbox TranquilRoute_EventScript_CrobatShadows_Cutscene_Text_3
	closemessage
	applymovement 25, TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_0
	applymovement 23, TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_0
	waitmovement 22
	waitmovement 25
	applymovement 23, TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_1
	applymovement 22, TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_1
	applymovement 25, TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_1
	waitmovement 23
	waitmovement 22
	waitmovement 25
	waitse
	applymovement 22, TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_2
	applymovement 23, TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_2
	applymovement 25, TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_2
	applymovement 24, TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_3
	waitmovement 22
	waitmovement 23
	waitmovement 25
	waitmovement 24
	removeobject 22
	removeobject 23
	removeobject 25
	removeobject 24
	setflag FLAG_HIDE_CROBAT_SHADOWS_TRANQUIL_RT
	return


TranquilRoute_EventScript_TravelingMerchantFirstTime::
	lock
	speakername TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_0
	msgbox TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_1
	closemessage
	delay 24
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	delay 48
	faceplayer
	speakername TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_0
	msgbox TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_2
	closemessage
	turnobject VAR_LAST_TALKED, DIR_EAST
	speakername TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_0
	msgbox TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_3
	closemessage
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	waitmoncry
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_EAST
	goto_if_eq TranquilRoute_EventScript_TravelingMerchantFirstTime_2
	applymovement VAR_LAST_TALKED, TranquilRoute_EventScript_TravelingMerchantFirstTime_Movement_2
	applymovement 27, TranquilRoute_EventScript_TravelingMerchantFirstTime_Movement_3
TranquilRoute_EventScript_TravelingMerchantFirstTime_1:
	waitmovement VAR_LAST_TALKED
	waitmovement 27
	removeobject VAR_LAST_TALKED
	removeobject 27
	setflag FLAG_MET_TRAVELING_MERCHANT
	release
	return

TranquilRoute_EventScript_TravelingMerchantFirstTime_2:
	applymovement VAR_LAST_TALKED, TranquilRoute_EventScript_TravelingMerchantFirstTime_Movement_0
	applymovement 27, TranquilRoute_EventScript_TravelingMerchantFirstTime_Movement_1
	goto TranquilRoute_EventScript_TravelingMerchantFirstTime_1


TranquilRoute_EventScript_WaitingForChatot::
	lock
	faceplayer
	speakername TranquilRoute_EventScript_Girl_Text_0
	msgbox TranquilRoute_EventScript_WaitingForChatot_Text_0
	closemessage
	release
	return


TranquilRoute_TrainerTips2::
	msgbox TranquilRoute_TrainerTips2_Text_0, MSGBOX_SIGN
	return


TranquilRoute_DirectionSign::
	goto_if_set FLAG_SAKU_KURA_REUNITED, TranquilRoute_DirectionSign_1
	msgbox TranquilRoute_DirectionSign_Text_1, MSGBOX_SIGN
	return

TranquilRoute_DirectionSign_1:
	msgbox TranquilRoute_DirectionSign_Text_0, MSGBOX_SIGN
	return


TranquilRoute_EventScript_GrassCutscene_Movement_0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	face_up
	step_end

TranquilRoute_EventScript_GrassCutscene_Movement_1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

TranquilRoute_EventScript_GrassCutscene_Movement_2:
	walk_left
	walk_left
	step_end

TranquilRoute_EventScript_GrassCutscene_Movement_3:
	walk_right
	walk_right
	step_end

TranquilRoute_EventScript_GrassCutscene_Movement_4:
	walk_left
	walk_in_place_faster_down
	step_end

TranquilRoute_EventScript_WhiteslateRoadblock_Movement_0:
	walk_right
	step_end

TranquilRoute_EventScript_CrobatShadows_Camera_Movement_0:
	walk_up
	walk_up
	step_end

TranquilRoute_EventScript_CrobatShadows_Camera_Movement_1:
	walk_down
	walk_down
	step_end

TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_0:
	walk_up
	face_down
	step_end

TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_1:
	face_down
	zubats_align
	delay_16
	delay_16
	step_end

TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_16
	step_end

TranquilRoute_EventScript_CrobatShadows_Cutscene_Movement_3:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

TranquilRoute_EventScript_TravelingMerchantFirstTime_Movement_0:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TranquilRoute_EventScript_TravelingMerchantFirstTime_Movement_1:
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TranquilRoute_EventScript_TravelingMerchantFirstTime_Movement_2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TranquilRoute_EventScript_TravelingMerchantFirstTime_Movement_3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TranquilRoute_EventScript_GrassCutscene_Text_0:
	.string "Cut Master$"

TranquilRoute_EventScript_GrassCutscene_Text_1:
	.string "… … … … … …\n"
	.string "… … … … … …$"

TranquilRoute_EventScript_GrassCutscene_Text_2:
	.string "Was it always this big?$"

TranquilRoute_EventScript_GrassCutscene_Text_3:
	.string "It doesn't even look like the same\n"
	.string "garden…$"

TranquilRoute_EventScript_GrassCutscene_Text_4:
	.string "I cannot thank you enough for this.\p"
	.string "I shall tend to my garden again,\n"
	.string "thanks to you.$"

TranquilRoute_EventScript_CutMaster_Text_0:
	.string "I'm enjoying tending my garden again.\p"
	.string "I like watching it slowly blossom into\n"
	.string "something beautiful.$"

TranquilRoute_EventScript_Chikao_Text_0:
	.string "I've been studying Pokémon at school!\n"
	.string "I can't lose!$"

TranquilRoute_EventScript_Chikao_Text_1:
	.string "I should have listened in class…$"

TranquilRoute_EventScript_Chikao_Text_2:
	.string "Chikao$"

TranquilRoute_EventScript_Chikao_Text_3:
	.string "Some Pokémon have more attack, and\n"
	.string "some have more special attack!\p"
	.string "What's the difference? Uhh… It's too\n"
	.string "complicated to explain.$"

TranquilRoute_EventScript_Kodomo_Text_0:
	.string "Ha! Are you trying to avoid the tall\n"
	.string "grass?$"

TranquilRoute_EventScript_Kodomo_Text_1:
	.string "Go back to the grass, you animal!$"

TranquilRoute_EventScript_Kodomo_Text_2:
	.string "Kodomo$"

TranquilRoute_EventScript_Kodomo_Text_3:
	.string "I should look for stronger Pokémon in\n"
	.string "the tall grass, but I'm a little scared\l"
	.string "of getting jumped by surprise!$"

TranquilRoute_EventScript_Takeshi_Text_0:
	.string "Stay right there! I'll defeat you with\n"
	.string "my ninja skills!$"

TranquilRoute_EventScript_Takeshi_Text_1:
	.string "I had the sun in my eyes!$"

TranquilRoute_EventScript_Takeshi_Text_2:
	.string "Takeshi$"

TranquilRoute_EventScript_Takeshi_Text_3:
	.string "I must hone my ninja skills!$"

TranquilRoute_EventScript_Hana_Text_0:
	.string "Ugh, how can Kenji paint a portrait of\n"
	.string "me if people keep walking between us?$"

TranquilRoute_EventScript_Hana_Text_1:
	.string "Great, now my hair is all messed up.$"

TranquilRoute_EventScript_Hana_Text_2:
	.string "Hiina$"

TranquilRoute_EventScript_Hana_Text_3:
	.string "Kenji really is an amazing artist. I\n"
	.string "feel very lucky.$"

TranquilRoute_EventScript_Kenji_Text_0:
	.string "You're interrupting my creative flow!!$"

TranquilRoute_EventScript_Kenji_Text_1:
	.string "Such beauty! What an artistic fight\n"
	.string "this was!$"

TranquilRoute_EventScript_Kenji_Text_2:
	.string "Kenji$"

TranquilRoute_EventScript_Kenji_Text_3:
	.string "Hiina is the best subject I could\n"
	.string "dream of.\p"
	.string "…Hey, uh, please don't tell her I said\n"
	.string "that.$"

TranquilRoute_EventScript_Girl_Text_0:
	.string "Girl$"

TranquilRoute_EventScript_Girl_Text_1:
	.string "What? Oh, I don't fight.\p"
	.string "My Pokémon and I are just strolling.$"

TranquilRoute_EventScript_WhiteslateRoadblock_Text_0:
	.string "Samurai$"

TranquilRoute_EventScript_WhiteslateRoadblock_Text_1:
	.string "Sorry, you can't go through. The road\n"
	.string "ahead is blocked.$"

TranquilRoute_EventScript_Shellos_Text_0:
	.string "Clelel!$"

TranquilRoute_EventScript_BerryWoman_Text_0:
	.string "Woman$"

TranquilRoute_EventScript_BerryWoman_Text_1:
	.string "Enjoy gardening!$"

TranquilRoute_EventScript_BerryWoman_Text_2:
	.string "Hi, young one! See this?$"

TranquilRoute_EventScript_BerryWoman_Text_3:
	.string "You can plant berries in the ground in\n"
	.string "fertile spots like this.\p"
	.string "The seeds will eventually grow into a\n"
	.string "healthy berry tree, ready to be\l"
	.string "harvested!\p"
	.string "I see you're a wielder. Well, different\n"
	.string "berries have different effects when\l"
	.string "they're fed to Pokémon.\p"
	.string "I love berries, hopefully you'll soon\n"
	.string "learn to love them too!\p"
	.string "Here, try planting a few!$"

TranquilRoute_EventScript_BerryWoman_Text_4:
	.string "Oh, right, I was almost forgetting!\p"
	.string "You must remember to water them\n"
	.string "regularly, or they won't grow!\p"
	.string "I like you. Take this!$"

TranquilRoute_EventScript_BerryWoman_Text_5:
	.string "Isn't it cute? It's friend-shaped!\p"
	.string "Don't worry about it, I have a spare\n"
	.string "one.\p"
	.string "Have fun gardening!$"

TranquilRoute_EventScript_Mareep_Text_0:
	.string "Beeeeeh…$"

TranquilRoute_EventScript_Mareep2_Text_0:
	.string "Baaaaah…$"

TranquilRoute_TrainerTips1_Text_0:
	.string "Did you know?\p"
	.string "Some Pokémon only come out at night.\p"
	.string "Visit the same spot at different\n"
	.string "times of day to have a chance of\l"
	.string "seeing rare Pokémon!$"

TranquilRoute_EventScript_CrobatShadows_Cutscene_Text_0:
	.string "Shady men$"

TranquilRoute_EventScript_CrobatShadows_Cutscene_Text_1:
	.string "…Excellent idea…\p"
	.string "…Yeah, and then…\p"
	.string "… … …$"

TranquilRoute_EventScript_CrobatShadows_Cutscene_Text_2:
	.string "Shady man$"

TranquilRoute_EventScript_CrobatShadows_Cutscene_Text_3:
	.string "Alright boys, let's move.$"

TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_0:
	.string "Man$"

TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_1:
	.string "Mumble mumble… Should restock on\n"
	.string "ointment… Damn, where did I put my\l"
	.string "purse?…$"

TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_2:
	.string "Oh, hello! Sorry, shop's closed at the\n"
	.string "moment!\p"
	.string "… …Oh, sorry, we haven't met, have we?\n"
	.string "I'm not good with faces…\p"
	.string "I'm Okada, the traveling merchant! I\n"
	.string "travel through all of Toku on foot,\l"
	.string "selling useful goods and rare finds!\p"
	.string "I'm sold out on, well, pretty much\n"
	.string "everything right now… But you're\l"
	.string "definitely going to see me around!\p"
	.string "What's your name? {PLAYER}? It's\n"
	.string "nice to meet you, {PLAYER}! I see\l"
	.string "you're a young wielder, eh? Maybe we\l"
	.string "can even have a friendly battle\l"
	.string "sometime!\p"
	.string "Now if you'll excuse me, I'm running\n"
	.string "late! See you around, {PLAYER}!$"

TranquilRoute_EventScript_TravelingMerchantFirstTime_Text_3:
	.string "Come on, Keke.$"

TranquilRoute_EventScript_WaitingForChatot_Text_0:
	.string "Sigh… Maybe if I hang around the\n"
	.string "Chatot Post, my boyfriend's message\l"
	.string "will arrive sooner…$"

TranquilRoute_TrainerTips2_Text_0:
	.string "Did you know?\p"
	.string "You can swap the Pokémon in your\n"
	.string "party using {R_BUTTON}.\p"
	.string "Set the lead Pokémon with {SELECT_BUTTON}.$"

TranquilRoute_DirectionSign_Text_0:
	.string "{UP_ARROW} Sakura Village\n"
	.string "{LEFT_ARROW} Whiteslate route\p"
	.string "It looks like the sign has been\n"
	.string "written over recently…$"

TranquilRoute_DirectionSign_Text_1:
	.string "{UP_ARROW} Saku and Kura Villages\n"
	.string "{LEFT_ARROW} Whiteslate route$"

CrobatHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CrobatHideout_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CrobatHideout_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

CrobatHideout_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_CROBAT_HIDEOUT_SEEN_BY_GRUNT, CrobatHideout_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
CrobatHideout_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_4
	return

CrobatHideout_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setflag FLAG_TEMP_5
	goto CrobatHideout_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

CrobatHideout_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_CROBAT_HIDEOUT_STATE, 0, CrobatHideout_1F_SeenByGrunt
	.2byte 0


CrobatHideout_1F_SeenByGrunt::
	lockall
	delay 24
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_SeenByGrunt_Movement_0
	waitmovement OBJ_EVENT_ID_PLAYER
	playse SE_PIN
	applymovement 2, CrobatHideout_1F_SeenByGrunt_Movement_1
	waitmovement 2
	waitse
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
	msgbox CrobatHideout_1F_SeenByGrunt_Text_1
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, CrobatHideout_1F_SeenByGrunt_Text_2, CrobatHideout_1F_SeenByGrunt_Text_3, CrobatHideout_1F_SeenByGrunt_Text_4
	closemessage
	switch VAR_RESULT
	case 0, CrobatHideout_1F_SeenByGrunt_3
	case 1, CrobatHideout_1F_SeenByGrunt_4
	case 2, CrobatHideout_1F_SeenByGrunt_5
CrobatHideout_1F_SeenByGrunt_1:
	closemessage
	playse SE_PIN
	applymovement 2, CrobatHideout_1F_SeenByGrunt_Movement_2
	waitmovement 0
	waitse
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
	msgbox CrobatHideout_1F_SeenByGrunt_Text_8
	closemessage
	applymovement 2, CrobatHideout_1F_SeenByGrunt_Movement_3
	waitmovement 2
	removeobject 2
	setflag FLAG_CROBAT_HIDEOUT_SEEN_BY_GRUNT
	setvar VAR_CROBAT_HIDEOUT_STATE, 1
	releaseall
	return

CrobatHideout_1F_SeenByGrunt_3:
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
	msgbox CrobatHideout_1F_SeenByGrunt_Text_5
	goto CrobatHideout_1F_SeenByGrunt_1

CrobatHideout_1F_SeenByGrunt_4:
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
	msgbox CrobatHideout_1F_SeenByGrunt_Text_6
	goto CrobatHideout_1F_SeenByGrunt_1

CrobatHideout_1F_SeenByGrunt_5:
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
	msgbox CrobatHideout_1F_SeenByGrunt_Text_7
	goto CrobatHideout_1F_SeenByGrunt_1


CrobatHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_CROBAT_HIDEOUT_1, CrobatHideout_1F_EventScript_Grunt1_Text_0, CrobatHideout_1F_EventScript_Grunt1_Text_1
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
	msgbox CrobatHideout_1F_EventScript_Grunt1_Text_2
	closemessage
	end


CrobatHideout_1F_EventScript_GruntPaintingPokeballs::
	trainerbattle_single TRAINER_GRUNT_CROBAT_HIDEOUT_2, CrobatHideout_1F_EventScript_GruntPaintingPokeballs_Text_0, CrobatHideout_1F_EventScript_GruntPaintingPokeballs_Text_1
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
	msgbox CrobatHideout_1F_EventScript_GruntPaintingPokeballs_Text_2
	closemessage
	end


CrobatHideout_1F_EventScript_GruntLaundryRoom::
	trainerbattle_single TRAINER_GRUNT_CROBAT_HIDEOUT_3, CrobatHideout_1F_EventScript_GruntLaundryRoom_Text_0, CrobatHideout_1F_EventScript_GruntLaundryRoom_Text_1
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
	msgbox CrobatHideout_1F_EventScript_GruntLaundryRoom_Text_2
	closemessage
	end


CrobatHideout_1F_EventScript_GruntDoubleGirl::
	trainerbattle_single TRAINER_GRUNT_CROBAT_HIDEOUT_4, CrobatHideout_1F_EventScript_GruntDoubleGirl_Text_0, CrobatHideout_1F_EventScript_GruntDoubleGirl_Text_1
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
	msgbox CrobatHideout_1F_EventScript_GruntDoubleGirl_Text_2
	closemessage
	end


CrobatHideout_1F_EventScript_GruntDoubleGuy::
	trainerbattle_single TRAINER_GRUNT_CROBAT_HIDEOUT_5, CrobatHideout_1F_EventScript_GruntDoubleGuy_Text_0, CrobatHideout_1F_EventScript_GruntDoubleGuy_Text_1
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
	msgbox CrobatHideout_1F_EventScript_GruntDoubleGuy_Text_2
	closemessage
	end


CrobatHideout_1F_EventScript_GruntNearReunionRoom::
	trainerbattle_single TRAINER_GRUNT_CROBAT_HIDEOUT_6, CrobatHideout_1F_EventScript_GruntNearReunionRoom_Text_0, CrobatHideout_1F_EventScript_GruntNearReunionRoom_Text_1
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
	msgbox CrobatHideout_1F_EventScript_GruntNearReunionRoom_Text_2
	closemessage
	end


CrobatHideout_1F_EventScript_Samurai::
	lock
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
	msgbox CrobatHideout_1F_EventScript_Samurai_Text_1
	closemessage
	setflag FLAG_TEMP_3
	release
	end


CrobatHideout_1F_EventScript_LaundrySchedule::
	msgbox CrobatHideout_1F_EventScript_LaundrySchedule_Text_0, MSGBOX_SIGN
	return


CrobatHideout_1F_EventScript_MessPoster::
	msgbox CrobatHideout_1F_EventScript_MessPoster_Text_0, MSGBOX_SIGN
	return


CrobatHideout_1F_EventScript_FirstPoster::
	msgbox CrobatHideout_1F_EventScript_FirstPoster_Text_0, MSGBOX_SIGN
	return


CrobatHideout_1F_EventScript_Pots::
	msgbox CrobatHideout_1F_EventScript_Pots_Text_0, MSGBOX_SIGN
	return


CrobatHideout_1F_EventScript_EmptyBowl::
	msgbox CrobatHideout_1F_EventScript_EmptyBowl_Text_0, MSGBOX_SIGN
	return


CrobatHideout_1F_EventScript_EmptyBowlLeftover::
	msgbox CrobatHideout_1F_EventScript_EmptyBowlLeftover_Text_0, MSGBOX_SIGN
	return


CrobatHideout_1F_EventScript_WantedPosterMustache::
	msgbox CrobatHideout_1F_EventScript_WantedPosterMustache_Text_0, MSGBOX_SIGN
	return


CrobatHideout_1F_EventScript_WantedPosterNose::
	msgbox CrobatHideout_1F_EventScript_WantedPosterNose_Text_0, MSGBOX_SIGN
	return


CrobatHideout_1F_EventScript_WantedPosterHanddrawn::
	msgbox CrobatHideout_1F_EventScript_WantedPosterHanddrawn_Text_0, MSGBOX_SIGN
	return


CrobatHideout_1F_EventScript_WantedPosterBoss::
	msgbox CrobatHideout_1F_EventScript_WantedPosterBoss_Text_0, MSGBOX_SIGN
	return


CrobatHideout_1F_EventScript_PosterFeedPoochyena::
	msgbox CrobatHideout_1F_EventScript_PosterFeedPoochyena_Text_0, MSGBOX_SIGN
	return


CrobatHideout_1F_EventScript_PosterReunionRoom::
	msgbox CrobatHideout_1F_EventScript_PosterReunionRoom_Text_0, MSGBOX_SIGN
	return


CrobatHideout_1F_EventScript_Plan::
	msgbox CrobatHideout_1F_EventScript_Plan_Text_0, MSGBOX_SIGN
	return


CrobatHideout_1F_EventScript_Nickit::
	lock
	playmoncry SPECIES_NICKIT, CRY_MODE_NORMAL
	msgbox CrobatHideout_1F_EventScript_Nickit_Text_0
	waitmoncry
	closemessage
	release
	return


CrobatHideout_1F_Trigger_4V1_FromLeft::
	lockall
	clearflag FLAG_TEMP_4
	addobject 15
	addobject 16
	addobject 17
	addobject 18
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement 15, CrobatHideout_1F_Trigger_4V1_FromLeft_Movement_0
	applymovement 16, CrobatHideout_1F_Trigger_4V1_FromLeft_Movement_1
	applymovement 17, CrobatHideout_1F_Trigger_4V1_FromLeft_Movement_2
	applymovement 18, CrobatHideout_1F_Trigger_4V1_FromLeft_Movement_3
	waitmovement 15
	waitmovement 16
	waitmovement 17
	waitmovement 18
	call CrobatHideout_1F_Trigger_4V1
	return


CrobatHideout_1F_Trigger_4V1_FromRight::
	lockall
	clearflag FLAG_TEMP_4
	addobject 15
	addobject 16
	addobject 17
	addobject 18
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement 17, CrobatHideout_1F_Trigger_4V1_FromRight_Movement_0
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_Trigger_4V1_FromRight_Movement_1
	delay 128
	playse SE_WALL_HIT
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 18, CrobatHideout_1F_Trigger_4V1_FromRight_Movement_2
	waitmovement 0
	applymovement 15, CrobatHideout_1F_Trigger_4V1_FromLeft_Movement_0
	applymovement 16, CrobatHideout_1F_Trigger_4V1_FromLeft_Movement_1
	waitmovement 15
	waitmovement 16
	waitmovement 17
	waitmovement 18
	call CrobatHideout_1F_Trigger_4V1
	return


CrobatHideout_1F_Trigger_4V1::
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_Trigger_4V1_Movement_0
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 15, CrobatHideout_1F_Trigger_4V1_Movement_1
	waitmovement 15
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
	msgbox CrobatHideout_1F_Trigger_4V1_Text_0
	applymovement 16, CrobatHideout_1F_Trigger_4V1_Movement_2
	waitmovement 16
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
	msgbox CrobatHideout_1F_Trigger_4V1_Text_1
	addobject 14
	applymovement 14, CrobatHideout_1F_Trigger_4V1_Movement_3
	waitmovement 14
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_Trigger_4V1_Movement_4
	playse SE_WALL_HIT
	applymovement 18, CrobatHideout_1F_Trigger_4V1_Movement_5
	applymovement 14, CrobatHideout_1F_Trigger_4V1_Movement_6
	waitmovement 0
	call CrobatHideout_1F_SamuraiOffersHelp
	applymovement 14, CrobatHideout_1F_Trigger_4V1_Movement_7
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_Trigger_4V1_Movement_8
	waitmovement 0
	delay 24
	call CrobatHideout_1F_BattleSamuraiBackToBack
	applymovement 14, CrobatHideout_1F_Trigger_4V1_Movement_2
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_Trigger_4V1_Movement_2
	waitmovement 0
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
	msgbox CrobatHideout_1F_Trigger_4V1_Text_2
	closemessage
	applymovement 17, CrobatHideout_1F_Trigger_4V1_Movement_9
	applymovement 18, CrobatHideout_1F_Trigger_4V1_Movement_10
	applymovement 14, CrobatHideout_1F_Trigger_4V1_Movement_11
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_Trigger_4V1_Movement_11
	waitmovement 0
	call CrobatHideout_1F_EnteredBossRoomWithSamurai
	releaseall
	return


CrobatHideout_1F_SamuraiOffersHelp::
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
	msgbox CrobatHideout_1F_SamuraiOffersHelp_Text_0
	closemessage
	applymovement 14, CrobatHideout_1F_SamuraiOffersHelp_Movement_0
	waitmovement 14
	playse SE_PIN
	applymovement 14, CrobatHideout_1F_SamuraiOffersHelp_Movement_1
	waitmovement 14
	waitse
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
	msgbox CrobatHideout_1F_SamuraiOffersHelp_Text_1
	closemessage
	applymovement 18, CrobatHideout_1F_SamuraiOffersHelp_Movement_2
	waitmovement 18
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
	msgbox CrobatHideout_1F_SamuraiOffersHelp_Text_2
	closemessage
	return


CrobatHideout_1F_BattleSamuraiBackToBack::
	trainerbattle_two_trainers TRAINER_GRUNT_CROBAT_HIDEOUT_7, CrobatHideout_1F_BattleSamuraiBackToBack_Text_0, TRAINER_GRUNT_CROBAT_HIDEOUT_8, CrobatHideout_1F_BattleSamuraiBackToBack_Text_1
	applymovement 15, CrobatHideout_1F_Trigger_4V1_Movement_1
	waitmovement 15
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
	msgbox CrobatHideout_1F_BattleSamuraiBackToBack_Text_2
	closemessage
	applymovement 15, CrobatHideout_1F_Trigger_4V1_Movement_3
	applymovement 16, CrobatHideout_1F_BattleSamuraiBackToBack_Movement_0
	applymovement 17, CrobatHideout_1F_BattleSamuraiBackToBack_Movement_1
	applymovement 18, CrobatHideout_1F_BattleSamuraiBackToBack_Movement_2
	waitmovement 16
	removeobject 15
	removeobject 16
	applymovement 14, CrobatHideout_1F_BattleSamuraiBackToBack_Movement_3
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_Trigger_4V1_Movement_1
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
	msgbox CrobatHideout_1F_BattleSamuraiBackToBack_Text_3
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	fadescreenswapbuffers FADE_FROM_BLACK
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
	msgbox CrobatHideout_1F_BattleSamuraiBackToBack_Text_4
	closemessage
	setvar VAR_CROBAT_HIDEOUT_STATE, 2
	return


CrobatHideout_1F_EnteredBossRoomWithSamurai::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_0
	waitmovement OBJ_EVENT_ID_CAMERA
	playse SE_PIN
	applymovement 8, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_1
	delay 16
	playse SE_PIN
	applymovement 7, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_1
	delay 16
	playse SE_PIN
	applymovement 6, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_1
	waitmovement 6
	delay 48
	applymovement 7, CrobatHideout_1F_Trigger_4V1_Movement_2
	waitmovement 7
	speakername CrobatHideout_1F_SeenByGrunt_Text_0
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_0
	closemessage
	applymovement 7, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
	waitmovement 9
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_2
	closemessage
	delay 48
	playse SE_LEDGE
	applymovement 9, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_3
	applymovement 7, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_4
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_3
	closemessage
	applymovement 14, Common_Movement_WalkInPlaceFasterUp
	waitmovement 14
	applymovement 7, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
	applymovement 8, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
	applymovement 6, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
	applymovement 17, CrobatHideout_1F_Trigger_4V1_Movement_4
	applymovement 18, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_5
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_4
	closemessage
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
	waitmovement 9
	applymovement 7, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_4
	applymovement 8, CrobatHideout_1F_Trigger_4V1_Movement_4
	applymovement 6, CrobatHideout_1F_Trigger_4V1_Movement_4
	applymovement 17, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_4
	applymovement 18, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_4
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_5
	closemessage
	playse SE_PIN
	applymovement 9, CrobatHideout_1F_SamuraiOffersHelp_Movement_1
	waitmovement 0
	waitse
	waitmovement 9
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_6
	closemessage
	playse SE_PIN
	applymovement 8, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_6
	applymovement 6, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_7
	waitmovement 0
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_7
	closemessage
	playse SE_LEDGE
	applymovement 14, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_8
	waitmovement 14
	applymovement 7, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
	applymovement 8, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
	applymovement 6, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
	applymovement 17, CrobatHideout_1F_Trigger_4V1_Movement_4
	applymovement 18, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_5
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_8
	closemessage
	playse SE_LEDGE
	applymovement 9, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_3
	applymovement 7, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_4
	applymovement 8, CrobatHideout_1F_Trigger_4V1_Movement_4
	applymovement 6, CrobatHideout_1F_Trigger_4V1_Movement_4
	applymovement 17, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_4
	applymovement 18, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_4
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_9
	closemessage
	addobject 13
	addobject 19
	applymovement 13, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_9
	applymovement 19, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_9
	waitmovement 0
	applymovement 7, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
	applymovement 8, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
	applymovement 6, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
	applymovement 17, CrobatHideout_1F_Trigger_4V1_Movement_4
	applymovement 18, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_5
	playse SE_PIN
	applymovement 14, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_10
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
	waitmovement 14
	applymovement 9, CrobatHideout_1F_SamuraiOffersHelp_Movement_2
	waitmovement 9
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_10
	closemessage
	playse SE_LEDGE
	applymovement 13, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_8
	applymovement 19, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_8
	waitmovement 0
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_11
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_12
	closemessage
	applymovement 14, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_4
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_4
	waitmovement 0
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
	waitmovement 9
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_13
	closemessage
	playse SE_LEDGE
	applymovement 9, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_3
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_14
	closemessage
	applymovement 6, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_11
	applymovement 8, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_11
	applymovement 17, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_12
	applymovement 18, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_13
	applymovement 7, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
	waitmovement 6
	waitmovement 8
	waitmovement 17
	waitmovement 18
	delay 48
	playse SE_PIN
	applymovement 7, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_14
	waitmovement 0
	applymovement 6, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_15
	applymovement 8, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_15
	applymovement 17, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_15
	applymovement 18, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_15
	applymovement 7, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_15
	waitmovement 0
	applymovement 9, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_16
	playse SE_M_DIVE
	fadescreenswapbuffers FADE_TO_WHITE
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	removeobject 6
	removeobject 8
	removeobject 17
	removeobject 18
	removeobject 7
	removeobject 9
	delay 80
	fadescreenswapbuffers FADE_FROM_WHITE
	delay 48
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_15
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, CrobatHideout_1F_SeenByGrunt_Movement_0
	waitmovement OBJ_EVENT_ID_CAMERA
	applymovement 13, CrobatHideout_1F_Trigger_4V1_Movement_2
	applymovement 14, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2
	waitmovement 13
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_16
	msgbox CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_17
	setweather WEATHER_NONE
	closemessage
	special RemoveCameraObject
	applymovement 14, CrobatHideout_1F_BattleSamuraiBackToBack_Movement_3
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_Trigger_4V1_Movement_1
	call CrobatHideout_1F_LetsFight2v2
	return


CrobatHideout_1F_LetsFight2v2::
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
	msgbox CrobatHideout_1F_LetsFight2v2_Text_0
	closemessage
	special SavePlayerParty
	fadescreenswapbuffers FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq CrobatHideout_1F_LetsFight2v2_2
	applymovement 14, CrobatHideout_1F_SamuraiOffersHelp_Movement_2
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_SamuraiOffersHelp_Movement_2
	multi_2_vs_2 TRAINER_GOLBAT_ADMIN_1, CrobatHideout_1F_LetsFight2v2_Text_1, TRAINER_GOLBAT_ADMIN_2, CrobatHideout_1F_LetsFight2v2_Text_2, PARTNER_SAMURAI
	compare VAR_RESULT, 0
	goto_if_ne CrobatHideout_1F_LetsFight2v2_5
	fadescreenswapbuffers FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate
CrobatHideout_1F_LetsFight2v2_1:
	applymovement 13, CrobatHideout_1F_Trigger_4V1_Movement_2
	waitmovement 0
	return

CrobatHideout_1F_LetsFight2v2_2:
	special LoadPlayerParty
	goto CrobatHideout_1F_LetsFight2v2
	goto CrobatHideout_1F_LetsFight2v2_1

CrobatHideout_1F_LetsFight2v2_5:
	playse SE_LEDGE
	applymovement 19, CrobatHideout_1F_LetsFight2v2_Movement_0
	waitmovement 0
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_16
	msgbox CrobatHideout_1F_LetsFight2v2_Text_3
	closemessage
	playse SE_LEDGE
	applymovement 13, CrobatHideout_1F_LetsFight2v2_Movement_1
	waitmovement 0
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_16
	msgbox CrobatHideout_1F_LetsFight2v2_Text_4
	closemessage
	applymovement 19, CrobatHideout_1F_LetsFight2v2_Movement_2
	applymovement 13, CrobatHideout_1F_LetsFight2v2_Movement_3
	waitmovement 0
	speakername CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_16
	msgbox CrobatHideout_1F_LetsFight2v2_Text_5
	closemessage
	playse SE_M_DIVE
	fadescreenswapbuffers FADE_TO_WHITE
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	removeobject 19
	removeobject 13
	delay 80
	fadescreenswapbuffers FADE_FROM_WHITE
	delay 48
	applymovement 14, CrobatHideout_1F_BattleSamuraiBackToBack_Movement_3
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_Trigger_4V1_Movement_1
	waitmovement 0
	speakername CrobatHideout_1F_EventScript_Samurai_Text_0
	msgbox CrobatHideout_1F_LetsFight2v2_Text_6
	closemessage
	setvar VAR_CROBAT_HIDEOUT_STATE, 3
	setflag FLAG_CLEARED_CROBAT_HIDEOUT
	setflag FLAG_BOUGHT_FAKE_SHINY
	warp MAP_YIFU_CITY, 33, 13
	goto CrobatHideout_1F_LetsFight2v2_1


CrobatHideout_1F_Trigger_Poochyena::
	lockall
	playmoncry SPECIES_POOCHYENA, CRY_MODE_ENCOUNTER
	applymovement 27, CrobatHideout_1F_Trigger_Poochyena_Movement_0
	waitmoncry
	playmoncry SPECIES_POOCHYENA, CRY_MODE_NORMAL
	applymovement 28, CrobatHideout_1F_Trigger_Poochyena_Movement_0
	delay 48
	waitmoncry
	playmoncry SPECIES_POOCHYENA, CRY_MODE_NORMAL
	applymovement 27, CrobatHideout_1F_Trigger_Poochyena_Movement_1
	waitmovement 27
	applymovement 26, CrobatHideout_1F_Trigger_Poochyena_Movement_1
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_Trigger_Poochyena_Movement_2
	waitmovement 26
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, CrobatHideout_1F_Trigger_Poochyena_Movement_3
	applymovement 27, CrobatHideout_1F_Trigger_Poochyena_Movement_4
	applymovement 28, CrobatHideout_1F_Trigger_Poochyena_Movement_5
	delay 16
	playmoncry SPECIES_POOCHYENA, CRY_MODE_ENCOUNTER
	delay 32
	playmoncry SPECIES_POOCHYENA, CRY_MODE_ENCOUNTER
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement 28
	setobjectxy 26, 55, 14
	setobjectxy 27, 56, 14
	setobjectxy 28, 57, 14
	turnobject 26, DIR_SOUTH
	turnobject 27, DIR_SOUTH
	turnobject 28, DIR_SOUTH
	delay 1
	releaseall
	return


CrobatHideout_1F_SeenByGrunt_Movement_0:
	walk_down
	step_end

CrobatHideout_1F_SeenByGrunt_Movement_1:
	face_up
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

CrobatHideout_1F_SeenByGrunt_Movement_2:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

CrobatHideout_1F_SeenByGrunt_Movement_3:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_16
	delay_16
	delay_16
	step_end

CrobatHideout_1F_Trigger_4V1_FromLeft_Movement_0:
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	step_end

CrobatHideout_1F_Trigger_4V1_FromLeft_Movement_1:
	delay_16
	delay_16
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	face_up
	step_end

CrobatHideout_1F_Trigger_4V1_FromLeft_Movement_2:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_left
	face_down
	step_end

CrobatHideout_1F_Trigger_4V1_FromLeft_Movement_3:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	face_left
	step_end

CrobatHideout_1F_Trigger_4V1_FromRight_Movement_0:
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	delay_16
	walk_faster_up
	walk_faster_left
	face_down
	step_end

CrobatHideout_1F_Trigger_4V1_FromRight_Movement_1:
	delay_16
	delay_16
	face_right
	lock_facing_direction
	walk_faster_left
	unlock_facing_direction
	delay_16
	face_up
	step_end

CrobatHideout_1F_Trigger_4V1_FromRight_Movement_2:
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	face_left
	step_end

CrobatHideout_1F_Trigger_4V1_Movement_0:
	face_down
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_down
	step_end

CrobatHideout_1F_Trigger_4V1_Movement_1:
	walk_in_place_fast_right
	step_end

CrobatHideout_1F_Trigger_4V1_Movement_2:
	walk_in_place_fast_up
	step_end

CrobatHideout_1F_Trigger_4V1_Movement_3:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CrobatHideout_1F_Trigger_4V1_Movement_4:
	face_right
	step_end

CrobatHideout_1F_Trigger_4V1_Movement_5:
	face_down
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

CrobatHideout_1F_Trigger_4V1_Movement_6:
	walk_fast_left
	step_end

CrobatHideout_1F_Trigger_4V1_Movement_7:
	walk_in_place_faster_up
	step_end

CrobatHideout_1F_Trigger_4V1_Movement_8:
	walk_in_place_faster_left
	step_end

CrobatHideout_1F_Trigger_4V1_Movement_9:
	lock_facing_direction
	walk_up
	walk_up
	walk_up
	unlock_facing_direction
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

CrobatHideout_1F_Trigger_4V1_Movement_10:
	lock_facing_direction
	walk_up
	walk_up
	walk_up
	unlock_facing_direction
	face_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

CrobatHideout_1F_Trigger_4V1_Movement_11:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CrobatHideout_1F_SamuraiOffersHelp_Movement_0:
	face_up
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	face_left
	step_end

CrobatHideout_1F_SamuraiOffersHelp_Movement_1:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

CrobatHideout_1F_SamuraiOffersHelp_Movement_2:
	walk_in_place_fast_down
	step_end

CrobatHideout_1F_BattleSamuraiBackToBack_Movement_0:
	delay_8
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CrobatHideout_1F_BattleSamuraiBackToBack_Movement_1:
	delay_8
	walk_in_place_fast_left
	delay_16
	delay_16
	walk_in_place_fast_down
	step_end

CrobatHideout_1F_BattleSamuraiBackToBack_Movement_2:
	delay_8
	walk_in_place_fast_left
	delay_16
	delay_16
	delay_16
	walk_in_place_fast_down
	step_end

CrobatHideout_1F_BattleSamuraiBackToBack_Movement_3:
	walk_in_place_fast_left
	step_end

CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_0:
	walk_up
	step_end

CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_1:
	face_down
	emote_exclamation_mark
	step_end

CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_2:
	face_down
	step_end

CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_3:
	jump_in_place_down
	step_end

CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_4:
	face_up
	step_end

CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_5:
	face_left
	step_end

CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_6:
	emote_exclamation_mark
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	step_end

CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_7:
	emote_exclamation_mark
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	step_end

CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_8:
	jump_in_place_up
	step_end

CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_9:
	walk_up
	walk_up
	step_end

CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_10:
	emote_exclamation_mark
	face_down
	delay_16
	delay_16
	delay_16
	step_end

CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_11:
	walk_right
	walk_right
	face_down
	step_end

CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_12:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_down
	step_end

CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_13:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	face_down
	step_end

CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_14:
	face_up
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	face_down
	delay_16
	delay_16
	delay_16
	step_end

CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_15:
	zubats_align
	delay_16
	delay_16
	step_end

CrobatHideout_1F_EnteredBossRoomWithSamurai_Movement_16:
	crobat_cape
	step_end

CrobatHideout_1F_LetsFight2v2_Movement_0:
	jump_in_place_left
	step_end

CrobatHideout_1F_LetsFight2v2_Movement_1:
	jump_in_place_right
	step_end

CrobatHideout_1F_LetsFight2v2_Movement_2:
	walk_in_place_fast_up
	delay_16
	delay_16
	walk_in_place_fast_left
	delay_16
	step_end

CrobatHideout_1F_LetsFight2v2_Movement_3:
	walk_in_place_fast_up
	delay_16
	delay_16
	walk_in_place_fast_right
	delay_16
	step_end

CrobatHideout_1F_Trigger_Poochyena_Movement_0:
	emote_exclamation_mark
	step_end

CrobatHideout_1F_Trigger_Poochyena_Movement_1:
	walk_fast_down
	step_end

CrobatHideout_1F_Trigger_Poochyena_Movement_2:
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

CrobatHideout_1F_Trigger_Poochyena_Movement_3:
	emote_exclamation_mark
	delay_16
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_left
	step_end

CrobatHideout_1F_Trigger_Poochyena_Movement_4:
	walk_fast_down
	walk_fast_down
	face_left
	delay_16
	delay_16
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_left
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

CrobatHideout_1F_Trigger_Poochyena_Movement_5:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	face_left
	delay_16
	delay_16
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_left
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

CrobatHideout_1F_SeenByGrunt_Text_0:
	.string "Zubat Grunt$"

CrobatHideout_1F_SeenByGrunt_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}Who the heck're you?!$"

CrobatHideout_1F_SeenByGrunt_Text_2:
	.string "{PLAYER}, nice to meet you!$"

CrobatHideout_1F_SeenByGrunt_Text_3:
	.string "I'm the new recruit!$"

CrobatHideout_1F_SeenByGrunt_Text_4:
	.string "Are you a criminal?$"

CrobatHideout_1F_SeenByGrunt_Text_5:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}I don' know no {PLAYER}!\n"
	.string "This ain't no tea party!\p"
	.string "You a spy? Ya don' work with the\n"
	.string "Samurai or somethin', do ya?$"

CrobatHideout_1F_SeenByGrunt_Text_6:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}Oh, right, 'course, the new recruit!\p"
	.string "(Why am I never in the loop?…)\p"
	.string "Wait… Where's yer uniform?$"

CrobatHideout_1F_SeenByGrunt_Text_7:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}Duh, what dum' question is that?\p"
	.string "…Wait…\n"
	.string "You're not a Crobat Shadow, are ya?$"

CrobatHideout_1F_SeenByGrunt_Text_8:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}Ah, crappers! Hideout's compromised!\p"
	.string "We've got an intruder!\n"
	.string "BOSS!! BOOOSSSS!!!$"

CrobatHideout_1F_EventScript_Grunt1_Text_0:
	.string "I bet yer the intruder!\n"
	.string "Yeah, I'm smart like that!$"

CrobatHideout_1F_EventScript_Grunt1_Text_1:
	.string "Boss, help us!$"

CrobatHideout_1F_EventScript_Grunt1_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}Whaddyawant? Ya got nothin' on us!\n"
	.string "Err I mean, we done nothin' wrong!$"

CrobatHideout_1F_EventScript_GruntPaintingPokeballs_Text_0:
	.string "What? I'm not paintin' Poké Balls to\n"
	.string "look like Ultra Balls!$"

CrobatHideout_1F_EventScript_GruntPaintingPokeballs_Text_1:
	.string "Alright alright, ya got me!$"

CrobatHideout_1F_EventScript_GruntPaintingPokeballs_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}I'm sure this is all super legal, but\n"
	.string "dontcha dare say a thing!$"

CrobatHideout_1F_EventScript_GruntLaundryRoom_Text_0:
	.string "Yer not here to help with the laundry,\n"
	.string "are ya?$"

CrobatHideout_1F_EventScript_GruntLaundryRoom_Text_1:
	.string "Hung me out to dry…$"

CrobatHideout_1F_EventScript_GruntLaundryRoom_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}I always end up on laundry duty, even\n"
	.string "when it's someone else's turn…$"

CrobatHideout_1F_EventScript_GruntDoubleGirl_Text_0:
	.string "Where d'ya think yer goin', cutie pie?$"

CrobatHideout_1F_EventScript_GruntDoubleGirl_Text_1:
	.string "Fine, go where ya want then, sheesh!$"

CrobatHideout_1F_EventScript_GruntDoubleGirl_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}Yer laughin' now, but our boss is\n"
	.string "gonna stomp on ya real good!$"

CrobatHideout_1F_EventScript_GruntDoubleGuy_Text_0:
	.string "Trespassin's against the law, ya\n"
	.string "know?$"

CrobatHideout_1F_EventScript_GruntDoubleGuy_Text_1:
	.string "Kids these days, I swear!$"

CrobatHideout_1F_EventScript_GruntDoubleGuy_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}We ain't gon' take this invasion of our\n"
	.string "privacy lyin' down!$"

CrobatHideout_1F_EventScript_GruntNearReunionRoom_Text_0:
	.string "This is our super secret hideout! Yer\n"
	.string "not wanted 'ere!$"

CrobatHideout_1F_EventScript_GruntNearReunionRoom_Text_1:
	.string "Yer ruinin' everythin'!$"

CrobatHideout_1F_EventScript_GruntNearReunionRoom_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}Our boss takes good care of us!\n"
	.string "Everythin' was fine an' dandy 'til you\l"
	.string "showed up!$"

CrobatHideout_1F_EventScript_Samurai_Text_0:
	.string "Samurai$"

CrobatHideout_1F_EventScript_Samurai_Text_1:
	.string "Quiet! The leader of the Crobat\n"
	.string "Shadows is in the next room!\p"
	.string "You're a trainer, yes? You have a wild\n"
	.string "look in your eyes… Like you're itching\l"
	.string "for a fight!\p"
	.string "Shall we join forces for the\n"
	.string "inevitable confrontation?$"

CrobatHideout_1F_EventScript_LaundrySchedule_Text_0:
	.string "WEEKLY LAUNDRY SCHEDULE\n"
	.string "MON - Hiro\l"
	.string "TUE - Hiro\l"
	.string "WED - Mei\l"
	.string "THU - Kevin\l"
	.string "FRI - Hiro\l"
	.string "SAT - Saki\l"
	.string "SUN - Hiro$"

CrobatHideout_1F_EventScript_MessPoster_Text_0:
	.string "KITCHEN RULES:\n"
	.string "1. DO clean up after yourself!\l"
	.string "2. DO NOT steal food from other\l"
	.string "grunts!\l"
	.string "3. But more importantly, DO NOT let\l"
	.string "your food be stolen!\l"
	.string "4. Seriously though, next one who\l"
	.string "leaves a mess, I WILL bite them in\l"
	.string "their sleep.\l"
	.string "- The Boss$"

CrobatHideout_1F_EventScript_FirstPoster_Text_0:
	.string "Welcome to the Super Secret Crobat\n"
	.string "Hideout!\l"
	.string "Keep it down, we don't want to attract\l"
	.string "attention.\l"
	.string "- The Boss$"

CrobatHideout_1F_EventScript_Pots_Text_0:
	.string "An assortment of mismatched pots and\n"
	.string "pans.$"

CrobatHideout_1F_EventScript_EmptyBowl_Text_0:
	.string "An empty bowl.$"

CrobatHideout_1F_EventScript_EmptyBowlLeftover_Text_0:
	.string "A bowl containing some leftover Mifan\n"
	.string "Berry soup.$"

CrobatHideout_1F_EventScript_WantedPosterMustache_Text_0:
	.string "WANTED: Crobat Shadows Grunt\n"
	.string "3000¥\p"
	.string "Someone has doodled glasses\n"
	.string "and a mustache on the poster.$"

CrobatHideout_1F_EventScript_WantedPosterNose_Text_0:
	.string "WANTED: Crobat Shadows Grunt\n"
	.string "4500¥\p"
	.string "It looks like the nose was\n"
	.string "drawn over with a different nose.$"

CrobatHideout_1F_EventScript_WantedPosterHanddrawn_Text_0:
	.string "WANTED: KEVIN\n"
	.string "10 000 000 000 000¥\p"
	.string "This poster looks handdrawn…$"

CrobatHideout_1F_EventScript_WantedPosterBoss_Text_0:
	.string "WANTED: Crobat Shadows Leader\n"
	.string "100 000¥\p"
	.string "There are various messages\n"
	.string "scribbled on the poster:\l"
	.string "“Happy birthday boss”,\l"
	.string "“U are worthe 999 999¥ in our harts”,\l"
	.string "“Gogettem boss”…\l"
	.string "… … …\l"
	.string "It's time to go.$"

CrobatHideout_1F_EventScript_PosterFeedPoochyena_Text_0:
	.string "REMEMBER TO FEED THE POOCHYENA$"

CrobatHideout_1F_EventScript_PosterReunionRoom_Text_0:
	.string "BELIEVE IN YOURSELF\n"
	.string "“Be the kind of criminal you want to\l"
	.string "be!”\p"
	.string "There is a doodle of a Woobat in a\n"
	.string "corner.$"

CrobatHideout_1F_EventScript_Plan_Text_0:
	.string "Looks like a brainstorming session\n"
	.string "was interrupted.\p"
	.string "“How to steal more efficiently”…$"

CrobatHideout_1F_EventScript_Nickit_Text_0:
	.string "Whewrr…$"

CrobatHideout_1F_Trigger_4V1_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}Dontcha take another step!$"

CrobatHideout_1F_Trigger_4V1_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}We're 'ere to end ya!$"

CrobatHideout_1F_Trigger_4V1_Text_2:
	.string "Excuse me!$"

CrobatHideout_1F_SamuraiOffersHelp_Text_0:
	.string "You sure are elusive! I finally caught\n"
	.string "up with your trail!\p"
	.string "Good work finding the Crobat Shadows'\n"
	.string "lair, we'd been on the lookout for a\l"
	.string "while!$"

CrobatHideout_1F_SamuraiOffersHelp_Text_1:
	.string "Oh, you were in the midst of getting\n"
	.string "attacked by these four delinquents,\l"
	.string "were you not?\p"
	.string "Let me help!\n"
	.string "I can handle two at a time!$"

CrobatHideout_1F_SamuraiOffersHelp_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}Hey, no fair! This was s'posed to be a\n"
	.string "four on one situation!$"

CrobatHideout_1F_BattleSamuraiBackToBack_Text_0:
	.string "No more!$"

CrobatHideout_1F_BattleSamuraiBackToBack_Text_1:
	.string "Please let me live!$"

CrobatHideout_1F_BattleSamuraiBackToBack_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}Ayayaya! Jus' wait til the Boss hears\n"
	.string "of this!$"

CrobatHideout_1F_BattleSamuraiBackToBack_Text_3:
	.string "Nicely done!\n"
	.string "What is your name, child?\p"
	.string "… … …{PLAYER}!\n"
	.string "I see you have skill!\p"
	.string "We have to take their leader down!\n"
	.string "But first, let me heal your\l"
	.string "companions!$"

CrobatHideout_1F_BattleSamuraiBackToBack_Text_4:
	.string "Right! Follow me, {PLAYER}!$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_ZUBAT EMOTE_NORMAL}Boss, uh, the intruder's 'ere!$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_1:
	.string "Crobat Boss$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_2:
	.string "Yeah - I can see that, Kevin…\p"
	.string "As always, thank you for your\n"
	.string "precious input!\p"
	.string "Did one man and a puny lil' brat jus'\n"
	.string "wipe through our whole squad like it\l"
	.string "was nothin'? Is that what happened?$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_3:
	.string "Wait a second… I know this kid!\p"
	.string "Yer the annoyin' brat that ruined us a\n"
	.string "good muggin' back in Beachbound\l"
	.string "Route!\p"
	.string "What the hell, kid? Why're ya always\n"
	.string "all up in our business? D'ya think yer\l"
	.string "the law or somethin'?$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_4:
	.string "I make the law here!\n"
	.string "You're under arrest, you thug!\p"
	.string "I'm taking you in for the Pokémon\n"
	.string "Refuge robbery!$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_5:
	.string "Bahaha! Don't make me laugh! Ya'll\n"
	.string "never get m-$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_6:
	.string "Wait, a robbery? Which one of ya goons\n"
	.string "did this?$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_7:
	.string "Well bravaw! You've jus' blown our\n"
	.string "cover, ya bumblin' idjets!\p"
	.string "A robbery right here in Yifu City?\n"
	.string "Jus' what were ya thinkin'?\p"
	.string "I told y'all to lay low!\n"
	.string "We can't deal with this much heat!$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_8:
	.string "Cut the chatter, you lowlife crook!\p"
	.string "Your reign of terror has been going on\n"
	.string "for too long!\p"
	.string "You are under arrest, I said!$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_9:
	.string "Nope, ya ain't arrestin' me, nor my\n"
	.string "gang!\p"
	.string "Golbat, to me!!$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_10:
	.string "I trust ya two to cover our backs,\n"
	.string "yeah?$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_11:
	.string "Golbat Admins$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_12:
	.string "Yes boss!$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_13:
	.string "No fancy Samurai and no lil' privileged\n"
	.string "scrub are ever gonna stop us!\p"
	.string "We're the Crobat Shadows, and we're\n"
	.string "always one step ahead of ya!\p"
	.string "Kid… Careful who ya team up with.$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_14:
	.string "Zubat! Align!$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_15:
	.string "Cough… cough…\n"
	.string "They're gone!$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_16:
	.string "Golbat Admin$"

CrobatHideout_1F_EnteredBossRoomWithSamurai_Text_17:
	.string "Prepare to be crushed!$"

CrobatHideout_1F_LetsFight2v2_Text_0:
	.string "Let us join forces, {PLAYER}!$"

CrobatHideout_1F_LetsFight2v2_Text_1:
	.string "H-how'd that happen?!$"

CrobatHideout_1F_LetsFight2v2_Text_2:
	.string "Ugh, that's humiliatin'…$"

CrobatHideout_1F_LetsFight2v2_Text_3:
	.string "Ya dumball, ya made us lose!$"

CrobatHideout_1F_LetsFight2v2_Text_4:
	.string "Naw I didn't! 'Twas yer fault!$"

CrobatHideout_1F_LetsFight2v2_Text_5:
	.string "Nevermind that! Let's scram!$"

CrobatHideout_1F_LetsFight2v2_Text_6:
	.string "Cough… Let's get out of here!$"

YifuCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, YifuCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, YifuCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

YifuCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_CROBAT_HIDEOUT_STATE, 3
	goto_if_ne YifuCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
YifuCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	compare VAR_CROBAT_HIDEOUT_STATE, 4
	goto_if_ge YifuCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	return

YifuCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setflag FLAG_TEMP_2
	goto YifuCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

YifuCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	setflag FLAG_TEMP_2
	return

YifuCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_CROBAT_HIDEOUT_STATE, 3, YifuCity_EscapedCrobatHideoutWithSamurai
	.2byte 0


YifuCity_EscapedCrobatHideoutWithSamurai::
	lockall
	setvar VAR_CROBAT_HIDEOUT_STATE, 4
	applymovement 38, YifuCity_EscapedCrobatHideoutWithSamurai_Movement_0
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_EscapedCrobatHideoutWithSamurai_Movement_1
	speakername YifuCity_EscapedCrobatHideoutWithSamurai_Text_0
	msgbox YifuCity_EscapedCrobatHideoutWithSamurai_Text_1
	releaseall
	return


YifuCity_EventScript_StoleMyMon::
	lock
	faceplayer
	speakername YifuCity_EventScript_StoleMyMon_Text_0
	msgbox YifuCity_EventScript_StoleMyMon_Text_1
	closemessage
	release
	return


YifuCity_EventScript_LostMyDoll::
	lock
	faceplayer
	speakername YifuCity_EventScript_LostMyDoll_Text_0
	msgbox YifuCity_EventScript_LostMyDoll_Text_1
	closemessage
	release
	return


YifuCity_EventScript_Cleffa::
	lock
	faceplayer
	setspeakertomonname SPECIES_CLEFFA
	msgbox YifuCity_EventScript_Cleffa_Text_0
	setseenmon SPECIES_CLEFFA
	playmoncry SPECIES_CLEFFA, CRY_MODE_NORMAL
	waitmoncry
	release
	end


YifuCity_EventScript_IDontFeelSafe::
	lock
	faceplayer
	speakername YifuCity_EventScript_StoleMyMon_Text_0
	goto_if_set FLAG_CLEARED_CROBAT_HIDEOUT, YifuCity_EventScript_IDontFeelSafe_2
	msgbox YifuCity_EventScript_IDontFeelSafe_Text_1
YifuCity_EventScript_IDontFeelSafe_1:
	closemessage
	release
	return

YifuCity_EventScript_IDontFeelSafe_2:
	msgbox YifuCity_EventScript_IDontFeelSafe_Text_0
	goto YifuCity_EventScript_IDontFeelSafe_1


YifuCity_EventScript_Samurai::
	lock
	faceplayer
	speakername YifuCity_EscapedCrobatHideoutWithSamurai_Text_0
	msgbox YifuCity_EventScript_Samurai_Text_0
	closemessage
	release
	return


YifuCity_EventScript_Samurai2::
	lock
	faceplayer
	speakername YifuCity_EscapedCrobatHideoutWithSamurai_Text_0
	msgbox YifuCity_EventScript_Samurai2_Text_0
	closemessage
	release
	return


YifuCity_EventScript_SamuraiTalkToRobberyVictim::
	lock
	applymovement VAR_LAST_TALKED, YifuCity_EscapedCrobatHideoutWithSamurai_Movement_1
	waitmovement 0
	speakername YifuCity_EscapedCrobatHideoutWithSamurai_Text_0
	msgbox YifuCity_EventScript_SamuraiTalkToRobberyVictim_Text_0
	closemessage
	release
	return


YifuCity_EventScript_RobberyVictim::
	lock
	speakername YifuCity_EventScript_RobberyVictim_Text_0
	goto_if_set FLAG_CLEARED_CROBAT_HIDEOUT, YifuCity_EventScript_RobberyVictim_2
	applymovement VAR_LAST_TALKED, YifuCity_EscapedCrobatHideoutWithSamurai_Movement_0
	waitmovement 0
	msgbox YifuCity_EventScript_RobberyVictim_Text_7
YifuCity_EventScript_RobberyVictim_1:
	closemessage
	release
	return

YifuCity_EventScript_RobberyVictim_2:
	faceplayer
	msgbox YifuCity_EventScript_RobberyVictim_Text_1
	checkitem ITEM_STOLEN_MONS
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_EventScript_RobberyVictim_5
	goto YifuCity_EventScript_RobberyVictim_1

YifuCity_EventScript_RobberyVictim_5:
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_EventScript_RobberyVictim_Text_2, YifuCity_EventScript_RobberyVictim_Text_3
	closemessage
	switch VAR_RESULT
	case 0, YifuCity_EventScript_RobberyVictim_8
	case 1, YifuCity_EventScript_RobberyVictim_9
	goto YifuCity_EventScript_RobberyVictim_1

YifuCity_EventScript_RobberyVictim_8:
	playfanfare MUS_OBTAIN_TMHM
	message YifuCity_EventScript_RobberyVictim_Text_4
	waitmessage
	waitfanfare
	removeitem ITEM_STOLEN_MONS
	playse SE_PIN
	applymovement VAR_LAST_TALKED, YifuCity_EventScript_RobberyVictim_Movement_0
	waitmovement 0
	waitse
	speakername YifuCity_EventScript_RobberyVictim_Text_0
	msgbox YifuCity_EventScript_RobberyVictim_Text_5
	closemessage
	giveitem ITEM_TM_CALM_MIND
	waitmessage
	setflag FLAG_RECEIVED_TM_CALM_MIND
	addvar VAR_PLAYER_REPUTATION, 1
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	delay 48
	fadescreen FADE_FROM_BLACK
	goto YifuCity_EventScript_RobberyVictim_1

YifuCity_EventScript_RobberyVictim_9:
	speakername YifuCity_EventScript_RobberyVictim_Text_0
	msgbox YifuCity_EventScript_RobberyVictim_Text_6
	closemessage
	goto YifuCity_EventScript_RobberyVictim_1


YifuCity_EventScript_ShinySeller::
	lock
	faceplayer
	speakername YifuCity_EventScript_ShinySeller_Text_0
	msgbox YifuCity_EventScript_ShinySeller_Text_1
	setseenmon SPECIES_CATERPIE
	showmonpic SPECIES_CATERPIE, 10, 3, TRUE
	playmoncry SPECIES_CATERPIE, CRY_MODE_NORMAL
	waitmoncry
	waitbuttonpress
	hidemonpic
	speakername YifuCity_EventScript_ShinySeller_Text_0
	msgbox YifuCity_EventScript_ShinySeller_Text_2
	goto YifuCity_ShinySellerChoice
	release
	return


YifuCity_ShinySellerChoice::
	showmoneybox 18, 0
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_ShinySellerChoice_Text_0, YifuCity_ShinySellerChoice_Text_1, YifuCity_ShinySellerChoice_Text_2
	closemessage
	switch VAR_RESULT
	case 0, YifuCity_ShinySellerChoice_3
	case 1, YifuCity_ShinySellerChoice_4
	case 2, YifuCity_ShinySellerChoice_5
YifuCity_ShinySellerChoice_1:
	hidemoneybox
	release
	return

YifuCity_ShinySellerChoice_3:
	checkmoney 10000
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_ShinySellerChoice_6
	speakername YifuCity_EventScript_ShinySeller_Text_0
	msgbox YifuCity_ShinySellerChoice_Text_8
	closemessage
	goto YifuCity_ShinySellerChoice_1

YifuCity_ShinySellerChoice_4:
	hidemoneybox
	speakername YifuCity_EventScript_ShinySeller_Text_0
	msgbox YifuCity_ShinySellerChoice_Text_9
	closemessage
	goto YifuCity_ShinySellerChoice_1

YifuCity_ShinySellerChoice_5:
	hidemoneybox
	speakername YifuCity_EventScript_ShinySeller_Text_0
	msgbox YifuCity_ShinySellerChoice_Text_10
	goto YifuCity_ShinySellerChoice
	goto YifuCity_ShinySellerChoice_1

YifuCity_ShinySellerChoice_6:
	speakername YifuCity_EventScript_ShinySeller_Text_0
	msgbox YifuCity_ShinySellerChoice_Text_3
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CATERPIE
	givemon SPECIES_CATERPIE, 5, isShiny = FALSE
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq YifuCity_ShinySellerChoice_10
YifuCity_ShinySellerChoice_9:
	removemoney 10000
	updatemoneybox
	playse SE_SHOP
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	message YifuCity_ShinySellerChoice_Text_4
	waitmessage
	waitfanfare
	hidemoneybox
	bufferspeciesname STR_VAR_1, SPECIES_CATERPIE
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq YifuCity_ShinySellerChoice_13
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq YifuCity_ShinySellerChoice_14
YifuCity_ShinySellerChoice_12:
	speakername YifuCity_EventScript_ShinySeller_Text_0
	msgbox YifuCity_ShinySellerChoice_Text_5
	closemessage
	compare VAR_FACING, DIR_EAST
	goto_if_eq YifuCity_ShinySellerChoice_18
	applymovement VAR_LAST_TALKED, YifuCity_ShinySellerChoice_Movement_1
YifuCity_ShinySellerChoice_17:
	delay 24
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement VAR_LAST_TALKED
	removeobject VAR_LAST_TALKED
	delay 48
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox YifuCity_ShinySellerChoice_Text_6
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	delay 48
	showmonpic SPECIES_CATERPIE, 10, 3, TRUE
	playmoncry SPECIES_CATERPIE, CRY_MODE_NORMAL
	waitmoncry
	msgbox YifuCity_ShinySellerChoice_Text_7
	playse SE_M_MIST
	hidemonpic
	showmonpic SPECIES_CATERPIE, 10, 3
	waitse
	waitbuttonpress
	closemessage
	hidemonpic
	goto_if_set FLAG_TEMP_1, YifuCity_ShinySellerChoice_27
YifuCity_ShinySellerChoice_26:
	setflag FLAG_BOUGHT_FAKE_SHINY
	goto YifuCity_ShinySellerChoice_1

YifuCity_ShinySellerChoice_10:
	goto Common_EventScript_NoMoreRoomForPokemon
	goto YifuCity_ShinySellerChoice_9

YifuCity_ShinySellerChoice_13:
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_ne YifuCity_ShinySellerChoice_21
	goto YifuCity_ShinySellerChoice_12

YifuCity_ShinySellerChoice_14:
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_ne YifuCity_ShinySellerChoice_24
YifuCity_ShinySellerChoice_23:
	setflag FLAG_TEMP_1
	goto YifuCity_ShinySellerChoice_12

YifuCity_ShinySellerChoice_18:
	applymovement VAR_LAST_TALKED, YifuCity_ShinySellerChoice_Movement_0
	goto YifuCity_ShinySellerChoice_17

YifuCity_ShinySellerChoice_21:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto YifuCity_ShinySellerChoice_12

YifuCity_ShinySellerChoice_24:
	call Common_EventScript_NameReceivedBoxMon
	goto YifuCity_ShinySellerChoice_23

YifuCity_ShinySellerChoice_27:
	call Common_EventScript_TransferredToPC
	goto YifuCity_ShinySellerChoice_26


YifuCity_Trigger_CrobatGruntsScram::
	lockall
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	speakername YifuCity_EventScript_ShinySeller_Text_0
	msgbox YifuCity_Trigger_CrobatGruntsScram_Text_0
	closemessage
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	delay 16
	playse SE_PIN
	applymovement 10, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	delay 48
	turnobject 9, DIR_WEST
	turnobject 10, DIR_WEST
	delay 48
	playse SE_LEDGE
	applymovement 9, YifuCity_Trigger_CrobatGruntsScram_Movement_0
	waitmovement 0
	waitse
	speakername YifuCity_EventScript_ShinySeller_Text_0
	msgbox YifuCity_Trigger_CrobatGruntsScram_Text_1
	closemessage
	playse SE_BALL_OPEN
	addobject 11
	playmoncry SPECIES_ZUBAT, CRY_MODE_NORMAL
	setseenmon SPECIES_ZUBAT
	applymovement 11, YifuCity_Trigger_CrobatGruntsScram_Movement_1
	waitmoncry
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Trigger_CrobatGruntsScram_Movement_2
	waitmovement 0
	speakername YifuCity_EventScript_ShinySeller_Text_0
	msgbox YifuCity_Trigger_CrobatGruntsScram_Text_2
	closemessage
	delay 24
	addobject 11
	applymovement 11, YifuCity_Trigger_CrobatGruntsScram_Movement_3
	waitmovement 0
	turnobject 9, DIR_SOUTH
	turnobject 10, DIR_NORTH
	releaseall
	return


YifuCity_Trigger_CrobatGruntsEavesdropPassword::
	lockall
	speakername YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_0
	msgbox YifuCity_Trigger_CrobatGruntsScram_Text_0
	closemessage
	delay 24
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_0
	waitmovement 0
	delay 48
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	speakername YifuCity_EventScript_ShinySeller_Text_0
	msgbox YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_1
	closemessage
	applymovement 10, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	speakername YifuCity_EventScript_ShinySeller_Text_0
	msgbox YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_2
	closemessage
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	speakername YifuCity_EventScript_ShinySeller_Text_0
	msgbox YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_3
	closemessage
	applymovement 10, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	speakername YifuCity_EventScript_ShinySeller_Text_0
	msgbox YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_4
	playse SE_LEDGE
	applymovement 10, YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_1
	speakername YifuCity_EventScript_ShinySeller_Text_0
	msgbox YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_5
	waitmovement 0
	waitse
	closemessage
	playse SE_LEDGE
	applymovement 9, YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_2
	speakername YifuCity_EventScript_ShinySeller_Text_0
	msgbox YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_6
	waitmovement 0
	waitse
	closemessage
	applymovement 9, YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_3
	applymovement 10, YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_4
	waitmovement 0
	removeobject 9
	removeobject 10
	removeobject 11
	setflag FLAG_GOT_CROBAT_PASSWORD_FIRST_HALF
	applymovement OBJ_EVENT_ID_CAMERA, YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_5
	waitmovement 0
	special RemoveCameraObject
	releaseall
	return


YifuCity_EventScript_HearEcho::
	lock
	faceplayer
	speakername YifuCity_EventScript_HearEcho_Text_0
	msgbox YifuCity_EventScript_HearEcho_Text_1
	closemessage
	release
	return


YifuCity_Trigger_CrobatGruntStuckInHole::
	lockall
	goto_if_set FLAG_GOT_CROBAT_PASSWORD_SECOND_HALF, YifuCity_Trigger_CrobatGruntStuckInHole_2
	speakername YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_0
	msgbox YifuCity_Trigger_CrobatGruntStuckInHole_Text_4
	closemessage
	delay 24
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Trigger_CrobatGruntStuckInHole_Movement_0
	waitmovement 0
	delay 24
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Trigger_CrobatGruntStuckInHole_Movement_1
	speakername YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_0
	msgbox YifuCity_Trigger_CrobatGruntStuckInHole_Text_5
	waitmovement 0
	waitse
	closemessage
	setflag FLAG_GOT_CROBAT_PASSWORD_SECOND_HALF
YifuCity_Trigger_CrobatGruntStuckInHole_1:
	releaseall
	return

YifuCity_Trigger_CrobatGruntStuckInHole_2:
	speakername YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_0
	random 5
	switch VAR_RESULT
	case 0, YifuCity_Trigger_CrobatGruntStuckInHole_7
	case 1, YifuCity_Trigger_CrobatGruntStuckInHole_8
	case 2, YifuCity_Trigger_CrobatGruntStuckInHole_9
	case 3, YifuCity_Trigger_CrobatGruntStuckInHole_9
	case 4, YifuCity_Trigger_CrobatGruntStuckInHole_10
YifuCity_Trigger_CrobatGruntStuckInHole_5:
	closemessage
	goto YifuCity_Trigger_CrobatGruntStuckInHole_1

YifuCity_Trigger_CrobatGruntStuckInHole_7:
	msgbox YifuCity_Trigger_CrobatGruntStuckInHole_Text_0
	goto YifuCity_Trigger_CrobatGruntStuckInHole_5

YifuCity_Trigger_CrobatGruntStuckInHole_8:
	setnamedmon SPECIES_SHARPEDO
	msgbox YifuCity_Trigger_CrobatGruntStuckInHole_Text_1
	goto YifuCity_Trigger_CrobatGruntStuckInHole_5

YifuCity_Trigger_CrobatGruntStuckInHole_9:
	msgbox YifuCity_Trigger_CrobatGruntStuckInHole_Text_2
	goto YifuCity_Trigger_CrobatGruntStuckInHole_5

YifuCity_Trigger_CrobatGruntStuckInHole_10:
	msgbox YifuCity_Trigger_CrobatGruntStuckInHole_Text_3
	goto YifuCity_Trigger_CrobatGruntStuckInHole_5


YifuCity_EventScript_Surskit::
	lock
	faceplayer
	setspeakertomonname SPECIES_SURSKIT
	msgbox YifuCity_EventScript_Surskit_Text_0
	setseenmon SPECIES_SURSKIT
	playmoncry SPECIES_SURSKIT, CRY_MODE_NORMAL
	waitmoncry
	release
	end


YifuCity_EventScript_CrobatShopSign::
	msgbox YifuCity_EventScript_CrobatShopSign_Text_0, MSGBOX_SIGN
	return


YifuCity_Trigger_Lockdown::
	lockall
	goto_if_set FLAG_HIDE_LOCKDOWN_SAMURAI, YifuCity_Trigger_Lockdown_2
	applymovement 33, YifuCity_EscapedCrobatHideoutWithSamurai_Movement_0
	waitmovement 0
	special GetPlayerSirMissString
	speakername YifuCity_EscapedCrobatHideoutWithSamurai_Text_0
	msgbox YifuCity_Trigger_Lockdown_Text_5
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Trigger_Lockdown_Movement_8
	waitmovement OBJ_EVENT_ID_PLAYER
YifuCity_Trigger_Lockdown_1:
	releaseall
	return

YifuCity_Trigger_Lockdown_2:
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	msgbox YifuCity_Trigger_Lockdown_Text_0
	closemessage
	delay 48
	waitmovement 0
	waitse
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
	clearflag FLAG_HIDE_LOCKDOWN_SAMURAI
	setobjectxyperm 33, 13, 39
	addobject 33
	applymovement 33, YifuCity_Trigger_Lockdown_Movement_0
	switch VAR_TEMP_3
	case 36, YifuCity_Trigger_Lockdown_7
	case 37, YifuCity_Trigger_Lockdown_8
	case 38, YifuCity_Trigger_Lockdown_9
	case 40, YifuCity_Trigger_Lockdown_10
	case 41, YifuCity_Trigger_Lockdown_11
	case 42, YifuCity_Trigger_Lockdown_12
	case 43, YifuCity_Trigger_Lockdown_13
YifuCity_Trigger_Lockdown_5:
	waitmovement 33
	waitmovement OBJ_EVENT_ID_PLAYER
	special GetPlayerSirMissString
	speakername YifuCity_EscapedCrobatHideoutWithSamurai_Text_0
	msgbox YifuCity_Trigger_Lockdown_Text_1
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_Trigger_Lockdown_Text_2, YifuCity_Trigger_Lockdown_Text_3
	closemessage
	speakername YifuCity_EscapedCrobatHideoutWithSamurai_Text_0
	msgbox YifuCity_Trigger_Lockdown_Text_4
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Trigger_Lockdown_Movement_8
	waitmovement OBJ_EVENT_ID_PLAYER
	goto YifuCity_Trigger_Lockdown_1

YifuCity_Trigger_Lockdown_7:
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Trigger_Lockdown_Movement_1
	goto YifuCity_Trigger_Lockdown_5

YifuCity_Trigger_Lockdown_8:
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Trigger_Lockdown_Movement_2
	goto YifuCity_Trigger_Lockdown_5

YifuCity_Trigger_Lockdown_9:
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Trigger_Lockdown_Movement_3
	goto YifuCity_Trigger_Lockdown_5

YifuCity_Trigger_Lockdown_10:
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Trigger_Lockdown_Movement_4
	goto YifuCity_Trigger_Lockdown_5

YifuCity_Trigger_Lockdown_11:
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Trigger_Lockdown_Movement_5
	goto YifuCity_Trigger_Lockdown_5

YifuCity_Trigger_Lockdown_12:
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Trigger_Lockdown_Movement_6
	goto YifuCity_Trigger_Lockdown_5

YifuCity_Trigger_Lockdown_13:
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Trigger_Lockdown_Movement_7
	goto YifuCity_Trigger_Lockdown_5


YifuCity_Trigger_CantGoThruNorth::
	lockall
	applymovement 34, YifuCity_Trigger_CantGoThruNorth_Movement_0
	waitmovement 0
	special GetPlayerSirMissString
	speakername YifuCity_EscapedCrobatHideoutWithSamurai_Text_0
	msgbox YifuCity_Trigger_Lockdown_Text_5
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, YifuCity_Trigger_CantGoThruNorth_Movement_1
	waitmovement OBJ_EVENT_ID_PLAYER
	releaseall
	return


YifuCity_Trigger_HarikoCriminals::
	lockall
	playse SE_PIN
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
	switch VAR_TEMP_2
	case 38, YifuCity_Trigger_HarikoCriminals_3
	case 39, YifuCity_Trigger_HarikoCriminals_4
	case 40, YifuCity_Trigger_HarikoCriminals_5
YifuCity_Trigger_HarikoCriminals_1:
	waitmovement 0
	speakername YifuCity_Trigger_HarikoCriminals_Text_0
	msgbox YifuCity_Trigger_HarikoCriminals_Text_1
	applymovement 35, YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_3
	waitmovement 35
	removeobject 35
	setflag FLAG_HIDE_HARIKO_YIFU_CITY
	releaseall
	return

YifuCity_Trigger_HarikoCriminals_3:
	applymovement 35, YifuCity_Trigger_HarikoCriminals_Movement_0
	goto YifuCity_Trigger_HarikoCriminals_1

YifuCity_Trigger_HarikoCriminals_4:
	applymovement 35, YifuCity_Trigger_HarikoCriminals_Movement_1
	goto YifuCity_Trigger_HarikoCriminals_1

YifuCity_Trigger_HarikoCriminals_5:
	applymovement 35, YifuCity_Trigger_HarikoCriminals_Movement_2
	goto YifuCity_Trigger_HarikoCriminals_1


YifuCity_EscapedCrobatHideoutWithSamurai_Movement_0:
	walk_in_place_fast_right
	step_end

YifuCity_EscapedCrobatHideoutWithSamurai_Movement_1:
	walk_in_place_fast_left
	step_end

YifuCity_EventScript_RobberyVictim_Movement_0:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

YifuCity_ShinySellerChoice_Movement_0:
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

YifuCity_ShinySellerChoice_Movement_1:
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

YifuCity_Trigger_CrobatGruntsScram_Movement_0:
	jump_in_place_left
	step_end

YifuCity_Trigger_CrobatGruntsScram_Movement_1:
	exit_pokeball
	face_left
	lock_anim
	lock_facing_direction
	walk_faster_left
	walk_faster_right
	unlock_anim
	unlock_facing_direction
	step_end

YifuCity_Trigger_CrobatGruntsScram_Movement_2:
	lock_facing_direction
	walk_left
	walk_left
	unlock_facing_direction
	step_end

YifuCity_Trigger_CrobatGruntsScram_Movement_3:
	enter_pokeball
	step_end

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_0:
	walk_up
	walk_up
	walk_up
	step_end

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_1:
	jump_in_place_up
	step_end

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_2:
	jump_in_place_down
	step_end

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_4:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Movement_5:
	walk_down
	walk_down
	walk_down
	step_end

YifuCity_Trigger_CrobatGruntStuckInHole_Movement_0:
	face_left
	delay_16
	face_up
	delay_16
	face_down
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	delay_16
	step_end

YifuCity_Trigger_CrobatGruntStuckInHole_Movement_1:
	emote_exclamation_mark
	face_down
	step_end

YifuCity_Trigger_Lockdown_Movement_0:
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
	walk_in_place_fast_right
	step_end

YifuCity_Trigger_Lockdown_Movement_1:
	walk_down
	walk_down
	walk_down
	face_left
	step_end

YifuCity_Trigger_Lockdown_Movement_2:
	walk_down
	walk_down
	face_left
	step_end

YifuCity_Trigger_Lockdown_Movement_3:
	walk_down
	face_left
	step_end

YifuCity_Trigger_Lockdown_Movement_4:
	walk_up
	face_left
	step_end

YifuCity_Trigger_Lockdown_Movement_5:
	walk_up
	walk_up
	face_left
	step_end

YifuCity_Trigger_Lockdown_Movement_6:
	walk_up
	walk_up
	walk_up
	face_left
	step_end

YifuCity_Trigger_Lockdown_Movement_7:
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

YifuCity_Trigger_Lockdown_Movement_8:
	walk_right
	step_end

YifuCity_Trigger_CantGoThruNorth_Movement_0:
	walk_in_place_fast_down
	step_end

YifuCity_Trigger_CantGoThruNorth_Movement_1:
	walk_down
	step_end

YifuCity_Trigger_HarikoCriminals_Movement_0:
	face_right
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	face_up
	step_end

YifuCity_Trigger_HarikoCriminals_Movement_1:
	face_right
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	face_up
	step_end

YifuCity_Trigger_HarikoCriminals_Movement_2:
	face_right
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

YifuCity_EscapedCrobatHideoutWithSamurai_Text_0:
	.string "Samurai$"

YifuCity_EscapedCrobatHideoutWithSamurai_Text_1:
	.string "Well, well… They slipped through\n"
	.string "our fingers, but they fled the\l"
	.string "city!$"

YifuCity_EventScript_StoleMyMon_Text_0:
	.string "Man$"

YifuCity_EventScript_StoleMyMon_Text_1:
	.string "When I got my Shiftry back from\n"
	.string "the nurse, it had somehow changed\l"
	.string "into a Pidgey…\p"
	.string "Each day, Pokémon never cease to\n"
	.string "amaze me!$"

YifuCity_EventScript_LostMyDoll_Text_0:
	.string "Little Girl$"

YifuCity_EventScript_LostMyDoll_Text_1:
	.string "I lost my doll while I was busy\n"
	.string "playing!$"

YifuCity_EventScript_Cleffa_Text_0:
	.string "Faa!$"

YifuCity_EventScript_IDontFeelSafe_Text_0:
	.string "I heard a young wielder made those\n"
	.string "weird Crobat dudes go away!\p"
	.string "They must be a very brave young\n"
	.string "person.$"

YifuCity_EventScript_IDontFeelSafe_Text_1:
	.string "I don't feel safe with those Crobat\n"
	.string "weirdos creeping around the city…\p"
	.string "I can't imagine how much worse it'd\n"
	.string "be were it not for the patrolling\l"
	.string "Samurai!$"

YifuCity_EventScript_Samurai_Text_0:
	.string "The Crobat Shadows' reign of terror\n"
	.string "will cease!$"

YifuCity_EventScript_Samurai2_Text_0:
	.string "Please be vigilant! Should you\n"
	.string "witness any suspicious situation,\l"
	.string "report it immediately!$"

YifuCity_EventScript_SamuraiTalkToRobberyVictim_Text_0:
	.string "Ma'am, can you describe what the\n"
	.string "thiefs looked like?$"

YifuCity_EventScript_RobberyVictim_Text_0:
	.string "Woman$"

YifuCity_EventScript_RobberyVictim_Text_1:
	.string "You and the Samurai scared those\n"
	.string "crooks off? That's good…\p"
	.string "Although I wonder where my stolen\n"
	.string "Pokémon can be…$"

YifuCity_EventScript_RobberyVictim_Text_2:
	.string "Here are your Pokémon!$"

YifuCity_EventScript_RobberyVictim_Text_3:
	.string "…$"

YifuCity_EventScript_RobberyVictim_Text_4:
	.string "{PLAYER} returned the stolen\n"
	.string "Pokémon to their rightful owner.$"

YifuCity_EventScript_RobberyVictim_Text_5:
	.string "Oh my! You even got my precious\n"
	.string "Pokémon back!\p"
	.string "You're a true hero, you know\n"
	.string "that?\p"
	.string "I'm finally at peace again! Here,\n"
	.string "take this, as a thanks!$"

YifuCity_EventScript_RobberyVictim_Text_6:
	.string "Sigh… I hope they're okay…$"

YifuCity_EventScript_RobberyVictim_Text_7:
	.string "A couple of crooks threatened me\n"
	.string "and stole all my Pokémon, right in\l"
	.string "front of the Refuge!\p"
	.string "Oh, what am I ever going to do…?$"

YifuCity_EventScript_ShinySeller_Text_0:
	.string "Shady man$"

YifuCity_EventScript_ShinySeller_Text_1:
	.string "Hey, uh… Wanna buy this Pokémon\n"
	.string "'ere?\n"
	.string "'Parently it's super rare or\l"
	.string "somethin', but I don't really need\l"
	.string "it, so…$"

YifuCity_EventScript_ShinySeller_Text_2:
	.string "So whaddyasay?\n"
	.string "It's yours for only 10 000¥.$"

YifuCity_ShinySellerChoice_Text_0:
	.string "I'll buy it!$"

YifuCity_ShinySellerChoice_Text_1:
	.string "No, thanks.$"

YifuCity_ShinySellerChoice_Text_2:
	.string "Are you a criminal?$"

YifuCity_ShinySellerChoice_Text_3:
	.string "Alright yeah, gimme the cash.$"

YifuCity_ShinySellerChoice_Text_4:
	.string "{PLAYER} received the Pokémon\n"
	.string "Caterpie!$"

YifuCity_ShinySellerChoice_Text_5:
	.string "Heheheehe… I'm rich! Finally rich!$"

YifuCity_ShinySellerChoice_Text_6:
	.string "… … … … … …\n"
	.string "… … … … … …$"

YifuCity_ShinySellerChoice_Text_7:
	.string "Some gold paint came off the\n"
	.string "Caterpie…$"

YifuCity_ShinySellerChoice_Text_8:
	.string "You, uh… You don't got enough\n"
	.string "cash, kid.$"

YifuCity_ShinySellerChoice_Text_9:
	.string "Then why are ya botherin' me?\n"
	.string "Scram, kid!$"

YifuCity_ShinySellerChoice_Text_10:
	.string "What? No! Why woudja even say\n"
	.string "that? Do I not look respectable\l"
	.string "to ya?\p"
	.string "So uh… You gonna buy it or not?$"

YifuCity_Trigger_CrobatGruntsScram_Text_0:
	.string "I tell ya man, damn password keeps\n"
	.string "changin'…$"

YifuCity_Trigger_CrobatGruntsScram_Text_1:
	.string "Are ya kiddin' me? Lookaddis\n"
	.string "eavesdroppin' moron!\p"
	.string "Want a taste of this?$"

YifuCity_Trigger_CrobatGruntsScram_Text_2:
	.string "Yeah, that's right, hightail it\n"
	.string "outta here!$"

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_0:
	.string "???$"

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_1:
	.string "Last time, I got it wrong and he\n"
	.string "didn' let me through!\p"
	.string "Like, brother, why I gotta tell ya\n"
	.string "some password for ya to let me\l"
	.string "in, we wen' to school together!$"

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_2:
	.string "Wait, ya didn't go to school\n"
	.string "though, didja?$"

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_3:
	.string "Who cares! It's a figger of speech!\n"
	.string "What's the newest password anyway?$"

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_4:
	.string "It's uh…\n"
	.string "Somethin' with Crobat…\l"
	.string "“{COLOR RED}Crobat is{COLOR DARK_GRAY}”… Uh…$"

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_5:
	.string "Aw man! I forgot it too!$"

YifuCity_Trigger_CrobatGruntsEavesdropPassword_Text_6:
	.string "Ya idjet! How're we gunna get back\n"
	.string "in now??\p"
	.string "Now we gotta find another Zubat an'\n"
	.string "hope he's got enough brains to\l"
	.string "remember the full sent'nce!\p"
	.string "C'mon, lessgo!$"

YifuCity_EventScript_HearEcho_Text_0:
	.string "Boy$"

YifuCity_EventScript_HearEcho_Text_1:
	.string "There's a ghost haunting the\n"
	.string "sewers!\p"
	.string "I swear I heard a voice calling\n"
	.string "when I was walking along the canal!$"

YifuCity_Trigger_CrobatGruntStuckInHole_Text_0:
	.string "Yawn… I'm bored…$"

YifuCity_Trigger_CrobatGruntStuckInHole_Text_1:
	.string "Sure hope there ain't no Sharpedo\n"
	.string "in here…$"

YifuCity_Trigger_CrobatGruntStuckInHole_Text_2:
	.string "Echo! … … …\n"
	.string "… … …{FONT_SMALL}echo{FONT_NORMAL}…\p"
	.string "Hehe…\p"
	.string "…Sigh…$"

YifuCity_Trigger_CrobatGruntStuckInHole_Text_3:
	.string "“{COLOR RED}Crime is awesome{COLOR DARK_GRAY}”!\n"
	.string "Hmm…\p"
	.string "“{COLOR RED}Stealing is awesome{COLOR DARK_GRAY}”?\n"
	.string "Nah… That's not it.$"

YifuCity_Trigger_CrobatGruntStuckInHole_Text_4:
	.string "Heyyy!! Help!$"

YifuCity_Trigger_CrobatGruntStuckInHole_Text_5:
	.string "I fell down the canal! I'm stuck\n"
	.string "down 'ere!\p"
	.string "Damn me, couldn't remember the\n"
	.string "first half of the damn password…\l"
	.string "“Something something… {COLOR RED}is\l"
	.string "awesome{COLOR DARK_GRAY}”! But what?!\l"
	.string "And why'd I think it was a good\l"
	.string "idea to try gettin' in through the\l"
	.string "canal?\l"
	.string "I can't swim! It's a dead end!$"

YifuCity_EventScript_Surskit_Text_0:
	.string "Sksksksk…$"

YifuCity_EventScript_CrobatShopSign_Text_0:
	.string "The sign has been written over.\p"
	.string "“Crobat Shop\n"
	.string "Come peruse our totally legal\l"
	.string "stuff!”$"

YifuCity_Trigger_Lockdown_Text_0:
	.string "ATTENTION! ATTENTION!\p"
	.string "THE CITY IS NOW UNDER LOCKDOWN!$"

YifuCity_Trigger_Lockdown_Text_1:
	.string "I'm sorry, {STR_VAR_1}, all exits\n"
	.string "are temporarily blocked. You are\l"
	.string "asked to remain inside the city\l"
	.string "until further notice.$"

YifuCity_Trigger_Lockdown_Text_2:
	.string "Why?$"

YifuCity_Trigger_Lockdown_Text_3:
	.string "What's happening?$"

YifuCity_Trigger_Lockdown_Text_4:
	.string "A robbery has taken place near the\n"
	.string "Pokémon Refuge!\p"
	.string "We Samurai are on the cusp of\n"
	.string "cracking down on the infamous\l"
	.string "Crobat Shadows!\p"
	.string "We cannot risk this operation to go\n"
	.string "awry, so we've locked down the\l"
	.string "premises for the time being!\p"
	.string "Please remain calm, I'm sure\n"
	.string "everything will be over before\l"
	.string "you know it.$"

YifuCity_Trigger_Lockdown_Text_5:
	.string "I'm sorry, {STR_VAR_1}, all exits\n"
	.string "are temporarily blocked. Nobody\l"
	.string "in or out.\p"
	.string "You are asked to remain inside the\n"
	.string "city until further notice.$"

YifuCity_Trigger_HarikoCriminals_Text_0:
	.string "Hariko$"

YifuCity_Trigger_HarikoCriminals_Text_1:
	.string "Hello, {PLAYER}.\n"
	.string "Are you well, since last time?\p"
	.string "Did you hear?\n"
	.string "There was a robbery right here in\l"
	.string "Yifu City! Some people's Pokémon\l"
	.string "were stolen!\p"
	.string "I heard there was a second\n"
	.string "decaying area west of here.\l"
	.string "I was planning on going there,\l"
	.string "but a Samurai was blocking the\l"
	.string "way, so I am waiting here.\p"
	.string "I am going for a stroll now. Let us\n"
	.string "have lunch together before you\l"
	.string "leave!$"

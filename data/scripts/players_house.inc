@LittlerootTown_BrendansHouse_2F_EventScript_WallClock::
@	lockall
@	setvar VAR_0x8004, MALE
@	goto PlayersHouse_2F_EventScript_WallClock
@	end
@
@LittlerootTown_MaysHouse_2F_EventScript_WallClock::
@	lockall
@	setvar VAR_0x8004, FEMALE
@	goto PlayersHouse_2F_EventScript_WallClock
@	end
@
@PlayersHouse_2F_EventScript_WallClock::
@	goto_if_set FLAG_SET_WALL_CLOCK, PlayersHouse_2F_EventScript_CheckWallClock
@	msgbox PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
@	call PlayersHouse_2F_EventScript_SetWallClock
@	delay 30
@	setvar VAR_LITTLEROOT_INTRO_STATE, 6
@	setflag FLAG_SET_WALL_CLOCK
@	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
@	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2
@	checkplayergender
@	@ call_if_eq VAR_RESULT, MALE, PlayersHouse_2F_EventScript_MomComesUpstairsMale
@	@ call_if_eq VAR_RESULT, FEMALE, PlayersHouse_2F_EventScript_MomComesUpstairsFemale
@	playse SE_EXIT
@	removeobject VAR_0x8008
@	releaseall
@	end
@
@PlayersHouse_2F_EventScript_CheckWallClock::
@	incrementgamestat GAME_STAT_CHECKED_CLOCK
@	fadescreen FADE_TO_BLACK
@	special Special_ViewWallClock
@	waitstate
@	releaseall
@	end
@
@PlayersHouse_2F_EventScript_SetWallClock::
@	fadescreen FADE_TO_BLACK
@	special StartWallClock
@	waitstate
@	return
@
@PlayersHouse_1F_EventScript_PetalburgGymReportFemale::
@	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFasterLeft
@	waitmovement 0
@	call PlayersHouse_1F_EventScript_MomNoticeGymBroadcast
@	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForGymFemale
@	waitmovement 0
@	playbgm MUS_ENCOUNTER_INTERVIEWER, FALSE
@	msgbox PlayersHouse_1F_Text_MaybeDadWillBeOn, MSGBOX_DEFAULT
@	closemessage
@	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomMakeRoomToSeeTVFemale
@	waitmovement 0
@	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerMoveToTVFemale
@	waitmovement 0
@	call PlayersHouse_1F_EventScript_WatchGymBroadcast
@	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
@	waitmovement 0
@	msgbox PlayersHouse_1F_Text_ItsOverWeMissedHim, MSGBOX_DEFAULT
@	msgbox PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor, MSGBOX_DEFAULT
@	closemessage
@	setvar VAR_TEMP_1, 1
@	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomReturnToSeatFemale
@	waitmovement 0
@	goto PlayersHouse_1F_EventScript_SetWatchedBroadcast
@	end
@
@PlayersHouse_1F_EventScript_TryRegisterMom::
@	goto_if_set FLAG_ENABLE_MOM_MATCH_CALL, PlayersHouse_1F_EventScript_CheckGiveAmuletCoin
@	msgbox PlayersHouse_1F_Text_IsThatAPokenav, MSGBOX_DEFAULT
@	closemessage
@	delay 30
@	playfanfare MUS_REGISTER_MATCH_CALL
@	msgbox PlayersHouse_1F_Text_RegisteredMom, MSGBOX_DEFAULT
@	waitfanfare
@	closemessage
@	delay 30
@	setflag FLAG_ENABLE_MOM_MATCH_CALL
@	release
@	end
@
@PlayersHouse_1F_EventScript_TryGiveAmuletCoin::
@	goto_if_set FLAG_RECEIVED_AMULET_COIN, PlayersHouse_1F_EventScript_MomHealsParty
@	msgbox PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom, MSGBOX_DEFAULT
@	giveitem ITEM_AMULET_COIN
@	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
@	msgbox PlayersHouse_1F_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
@	setflag FLAG_RECEIVED_AMULET_COIN
@	release
@	end
@
@PlayersHouse_1F_EventScript_MomHealsParty::
@	msgbox PlayersHouse_1F_Text_YouShouldRestABit, MSGBOX_DEFAULT
@	goto PlayersHouse_1F_EventScript_HealParty
@	end
@
@PlayersHouse_1F_EventScript_HealParty::
@	closemessage
@	call Common_EventScript_OutOfCenterPartyHeal
@	incrementgamestat GAME_STAT_RESTED_AT_HOME
@	msgbox PlayersHouse_1F_Text_TakeCareHoney, MSGBOX_DEFAULT
@	release
@	end
@
@PlayersHouse_1F_EventScript_Vigoroth2::
@	lock
@	faceplayer
@	waitse
@	playmoncry SPECIES_VIGOROTH, CRY_MODE_NORMAL
@	msgbox PlayersHouse_1F_Text_Vigoroth2, MSGBOX_DEFAULT
@	waitmoncry
@	release
@	end
@

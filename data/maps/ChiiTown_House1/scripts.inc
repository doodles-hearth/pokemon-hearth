ChiiTown_House1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, ChiiTown_House1_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChiiTown_House1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

ChiiTown_House1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 1, ChiiTown_House1_EventScript_GrowlitheBarks
	.2byte 0


ChiiTown_House1_EventScript_OldManTrespassing::
	lock
	playse SE_PIN
	applymovement 1, Common_Movement_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	speakername ChiiTown_House1_EventScript_OldManTrespassing_Text_0
	msgbox ChiiTown_House1_EventScript_OldManTrespassing_Text_1
	closemessage
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	setvar VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 2
	warp MAP_CHII_TOWN, 24, 21
	waitstate
	return


ChiiTown_House1_EventScript_GrowlitheGrrr::
	lock
	applymovement 2, Common_Movement_FaceRight
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	speakername ChiiTown_House1_EventScript_GrowlitheGrrr_Text_0
	msgbox ChiiTown_House1_EventScript_GrowlitheGrrr_Text_1
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, ChiiTown_House1_Movement_PlayerStepsAwayFromGrowlithe
	waitmovement 0
	release
	return


ChiiTown_House1_EventScript_GrowlitheBarks::
	lock
	playse SE_PIN
	applymovement 2, Common_Movement_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, ChiiTown_House1_Movement_GrowlitheRunsUpToPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
	speakername ChiiTown_House1_EventScript_GrowlitheGrrr_Text_0
	msgbox ChiiTown_House1_EventScript_GrowlitheBarks_Text_0
	waitmoncry
	closemessage
	applymovement 1, ChiiTown_House1_Movement_OldManWalksUpToGrowlithe
	waitmovement 0
	applymovement 2, Common_Movement_FaceRight
	waitmovement 0
	speakername ChiiTown_House1_EventScript_GrowlitheBarks_Text_1
	msgbox ChiiTown_House1_EventScript_GrowlitheBarks_Text_2
	closemessage
	applymovement 1, Common_Movement_FaceDown
	waitmovement 0
	applymovement 2, Common_Movement_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	speakername ChiiTown_House1_EventScript_GrowlitheBarks_Text_1
	msgbox ChiiTown_House1_EventScript_GrowlitheBarks_Text_3
	closemessage
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 2
	warp MAP_CHII_TOWN, 24, 21
	waitstate
	return


ChiiTown_House1_EventScript_Cheater::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 100
	waitse
	speakername ChiiTown_House1_EventScript_Cheater_Text_0
	msgbox ChiiTown_House1_EventScript_Cheater_Text_1
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ChiiTown_House1_EventScript_CheaterDefeatedElectrode
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ChiiTown_House1_EventScript_CheaterDefeatedElectrode
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ChiiTown_House1_EventScript_CheaterDefeatedElectrode
	setflag FLAG_DEFEATED_ELECTRODE_CHII_TOWN_HOUSE
	release
	return


ChiiTown_House1_EventScript_CheaterDefeatedElectrode::
	setflag FLAG_DEFEATED_ELECTRODE_CHII_TOWN_HOUSE
	goto Common_EventScript_RemoveStaticPokemon
	end


ChiiTown_House1_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ChiiTown_House1_EventScript_TryRemoveElectrode
	end


ChiiTown_House1_EventScript_TryRemoveElectrode::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return


ChiiTown_House1_Movement_GrowlitheRunsUpToPlayer:
	walk_faster_right
	walk_faster_right
	walk_faster_up
	walk_faster_right
	face_down
	step_end

ChiiTown_House1_Movement_OldManWalksUpToGrowlithe:
	walk_down
	walk_down
	walk_down
	face_right
	step_end

ChiiTown_House1_Movement_PlayerStepsAwayFromGrowlithe:
	walk_right
	step_end

ChiiTown_House1_EventScript_OldManTrespassing_Text_0:
	.string "Old man$"

ChiiTown_House1_EventScript_OldManTrespassing_Text_1:
	.string "Do you often barge into people's\n"
	.string "houses uninvited without even taking\l"
	.string "off your shoes?\p"
	.string "Want to break a couple of pots while\n"
	.string "you're at it?\p"
	.string "Kids these days, I swear…\p"
	.string "Now get out of my house.$"

ChiiTown_House1_EventScript_GrowlitheGrrr_Text_0:
	.string "Growlithe$"

ChiiTown_House1_EventScript_GrowlitheGrrr_Text_1:
	.string "Grrrrrrr…$"

ChiiTown_House1_EventScript_GrowlitheBarks_Text_0:
	.string "BARK!\p"
	.string "BARKBARKBARKBARKBARK!$"

ChiiTown_House1_EventScript_GrowlitheBarks_Text_1:
	.string "Mean old man$"

ChiiTown_House1_EventScript_GrowlitheBarks_Text_2:
	.string "Good girl, Growlithe, good girl.$"

ChiiTown_House1_EventScript_GrowlitheBarks_Text_3:
	.string "She keeps intruders out.$"

ChiiTown_House1_EventScript_Cheater_Text_0:
	.string "Voice of God$"

ChiiTown_House1_EventScript_Cheater_Text_1:
	.string "Cheater!$"

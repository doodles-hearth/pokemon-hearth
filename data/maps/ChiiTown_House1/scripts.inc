ChiiTown_House1_MapScripts::
# 5 "data/maps/ChiiTown_House1/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, ChiiTown_House1_OnResume
# 6 "data/maps/ChiiTown_House1/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChiiTown_House1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

ChiiTown_House1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 7 "data/maps/ChiiTown_House1/scripts.pory"
	map_script_2 VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 1, ChiiTown_House1_EventScript_GrowlitheBarks
	.2byte 0


ChiiTown_House1_EventScript_OldManTrespassing::
# 12 "data/maps/ChiiTown_House1/scripts.pory"
	lock
# 13 "data/maps/ChiiTown_House1/scripts.pory"
	playse SE_PIN
# 14 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement 1, Common_Movement_FaceDown
# 15 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 16 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 17 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 18 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement 1, Common_Movement_Delay48
# 19 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 20 "data/maps/ChiiTown_House1/scripts.pory"
	msgbox ChiiTown_House1_EventScript_OldManTrespassing_Text_0
# 26 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement 1, Common_Movement_Delay48
# 27 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 28 "data/maps/ChiiTown_House1/scripts.pory"
	setvar VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 2
# 29 "data/maps/ChiiTown_House1/scripts.pory"
	warp MAP_CHII_TOWN, 24, 21
# 30 "data/maps/ChiiTown_House1/scripts.pory"
	release
	return


ChiiTown_House1_EventScript_GrowlitheGrrr::
# 34 "data/maps/ChiiTown_House1/scripts.pory"
	lock
# 35 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement 2, Common_Movement_FaceRight
# 36 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 37 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement 2, Common_Movement_Delay48
# 38 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 39 "data/maps/ChiiTown_House1/scripts.pory"
	msgbox ChiiTown_House1_EventScript_GrowlitheGrrr_Text_0
# 40 "data/maps/ChiiTown_House1/scripts.pory"
	closemessage
# 41 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, ChiiTown_House1_Movement_PlayerStepsAwayFromGrowlithe
# 42 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 43 "data/maps/ChiiTown_House1/scripts.pory"
	release
	return


ChiiTown_House1_EventScript_GrowlitheBarks::
# 47 "data/maps/ChiiTown_House1/scripts.pory"
	lock
# 48 "data/maps/ChiiTown_House1/scripts.pory"
	playse SE_PIN
# 49 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement 2, Common_Movement_FaceRight
# 50 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 51 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 52 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 53 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement 2, Common_Movement_ExclamationMark
# 54 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 55 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement 2, Common_Movement_Delay48
# 56 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 57 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement 2, ChiiTown_House1_Movement_GrowlitheRunsUpToPlayer
# 58 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 59 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 60 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 61 "data/maps/ChiiTown_House1/scripts.pory"
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
# 62 "data/maps/ChiiTown_House1/scripts.pory"
	msgbox ChiiTown_House1_EventScript_GrowlitheBarks_Text_0
# 63 "data/maps/ChiiTown_House1/scripts.pory"
	waitmoncry
# 65 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement 1, ChiiTown_House1_Movement_OldManWalksUpToGrowlithe
# 66 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 67 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement 2, Common_Movement_FaceRight
# 68 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 69 "data/maps/ChiiTown_House1/scripts.pory"
	msgbox ChiiTown_House1_EventScript_GrowlitheBarks_Text_1
# 70 "data/maps/ChiiTown_House1/scripts.pory"
	closemessage
# 72 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement 1, Common_Movement_FaceDown
# 73 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 74 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement 2, Common_Movement_FaceDown
# 75 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 76 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement 1, Common_Movement_Delay48
# 77 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 78 "data/maps/ChiiTown_House1/scripts.pory"
	msgbox ChiiTown_House1_EventScript_GrowlitheBarks_Text_2
# 80 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement 1, Common_Movement_Delay48
# 81 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 83 "data/maps/ChiiTown_House1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 84 "data/maps/ChiiTown_House1/scripts.pory"
	waitmovement 0
# 86 "data/maps/ChiiTown_House1/scripts.pory"
	setvar VAR_CHII_TOWN_OLD_MAN_TRESPASS_STATE, 2
# 87 "data/maps/ChiiTown_House1/scripts.pory"
	warp MAP_CHII_TOWN, 24, 21
# 88 "data/maps/ChiiTown_House1/scripts.pory"
	release
	return


ChiiTown_House1_EventScript_Cheater::
# 92 "data/maps/ChiiTown_House1/scripts.pory"
	lock
# 93 "data/maps/ChiiTown_House1/scripts.pory"
	faceplayer
# 94 "data/maps/ChiiTown_House1/scripts.pory"
	setwildbattle SPECIES_ELECTRODE, 100
# 95 "data/maps/ChiiTown_House1/scripts.pory"
	waitse
# 96 "data/maps/ChiiTown_House1/scripts.pory"
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
# 97 "data/maps/ChiiTown_House1/scripts.pory"
	delay 40
# 98 "data/maps/ChiiTown_House1/scripts.pory"
	waitmoncry
# 99 "data/maps/ChiiTown_House1/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 100 "data/maps/ChiiTown_House1/scripts.pory"
	dowildbattle
# 101 "data/maps/ChiiTown_House1/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 102 "data/maps/ChiiTown_House1/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 103 "data/maps/ChiiTown_House1/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ChiiTown_House1_EventScript_CheaterDefeatedElectrode
# 104 "data/maps/ChiiTown_House1/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ChiiTown_House1_EventScript_CheaterDefeatedElectrode
# 105 "data/maps/ChiiTown_House1/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ChiiTown_House1_EventScript_CheaterDefeatedElectrode
# 106 "data/maps/ChiiTown_House1/scripts.pory"
	setflag FLAG_DEFEATED_ELECTRODE_CHII_TOWN_HOUSE
# 107 "data/maps/ChiiTown_House1/scripts.pory"
	release
	return


ChiiTown_House1_EventScript_CheaterDefeatedElectrode::
# 111 "data/maps/ChiiTown_House1/scripts.pory"
	setflag FLAG_DEFEATED_ELECTRODE_CHII_TOWN_HOUSE
# 112 "data/maps/ChiiTown_House1/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
	end


ChiiTown_House1_OnResume::
# 117 "data/maps/ChiiTown_House1/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ChiiTown_House1_EventScript_TryRemoveElectrode
	end


ChiiTown_House1_EventScript_TryRemoveElectrode::
# 122 "data/maps/ChiiTown_House1/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 123 "data/maps/ChiiTown_House1/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 124 "data/maps/ChiiTown_House1/scripts.pory"
	removeobject VAR_LAST_TALKED
	return


# 128 "data/maps/ChiiTown_House1/scripts.pory"
ChiiTown_House1_Movement_GrowlitheRunsUpToPlayer:
# 129 "data/maps/ChiiTown_House1/scripts.pory"
	walk_faster_right
# 130 "data/maps/ChiiTown_House1/scripts.pory"
	walk_faster_right
# 131 "data/maps/ChiiTown_House1/scripts.pory"
	walk_faster_up
# 132 "data/maps/ChiiTown_House1/scripts.pory"
	walk_faster_right
# 133 "data/maps/ChiiTown_House1/scripts.pory"
	face_down
	step_end

# 136 "data/maps/ChiiTown_House1/scripts.pory"
ChiiTown_House1_Movement_OldManWalksUpToGrowlithe:
# 137 "data/maps/ChiiTown_House1/scripts.pory"
	walk_down
# 138 "data/maps/ChiiTown_House1/scripts.pory"
	walk_down
# 139 "data/maps/ChiiTown_House1/scripts.pory"
	walk_down
# 140 "data/maps/ChiiTown_House1/scripts.pory"
	face_right
	step_end

# 143 "data/maps/ChiiTown_House1/scripts.pory"
ChiiTown_House1_Movement_PlayerStepsAwayFromGrowlithe:
# 144 "data/maps/ChiiTown_House1/scripts.pory"
	walk_right
	step_end

ChiiTown_House1_EventScript_OldManTrespassing_Text_0:
# 21 "data/maps/ChiiTown_House1/scripts.pory"
	.string "Do you often barge into people's houses\n"
	.string "uninvited without even taking off your\l"
	.string "shoes?\p"
	.string "Want to break a couple of pots while\n"
	.string "you're at it?\p"
	.string "Kids these days, I swear…\p"
	.string "Now get out of my house.$"

ChiiTown_House1_EventScript_GrowlitheGrrr_Text_0:
# 39 "data/maps/ChiiTown_House1/scripts.pory"
	.string "Grrrrrrr…$"

ChiiTown_House1_EventScript_GrowlitheBarks_Text_0:
# 62 "data/maps/ChiiTown_House1/scripts.pory"
	.string "{FIXED_CASE}BARK!\p"
	.string "BARKBARKBARKBARKBARK!{UNFIX_CASE}$"

ChiiTown_House1_EventScript_GrowlitheBarks_Text_1:
# 69 "data/maps/ChiiTown_House1/scripts.pory"
	.string "Good girl, Growlithe, good girl.$"

ChiiTown_House1_EventScript_GrowlitheBarks_Text_2:
# 78 "data/maps/ChiiTown_House1/scripts.pory"
	.string "She keeps intruders out.$"

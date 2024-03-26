LittlerootTown_ProfessorBirchsLab_MapScripts::
# 9 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_ProfessorBirchsLab_MapScripts_MAP_SCRIPT_ON_LOAD
# 12 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LittlerootTown_ProfessorBirchsLab_MapScripts_MAP_SCRIPT_ON_LOAD:
# 10 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 4
	return

LittlerootTown_ProfessorBirchsLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 13 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_SUNRISE_VILLAGE_INTRO_STATE, 4, LittlerootTown_ProfessorBirchsLab_Event_DistributionCutscene
	.2byte 0


LittlerootTown_ProfessorBirchsLab_Event_DistributionCutscene::
# 18 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 20 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerWalkUpToElder
# 21 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 23 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Event_DistributionCutscene_Text_0
# 26 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 28 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement 6, Common_Movement_FacePlayer
# 29 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 30 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Event_DistributionCutscene_Text_1
# 31 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement 6, Common_Movement_FaceUp
# 32 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 33 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 5
# 34 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	return


# 37 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_PlayerWalkUpToElder:
# 38 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 39 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 40 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 41 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 42 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 43 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 44 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end

LittlerootTown_ProfessorBirchsLab_Event_Pokeball_Starter_Trapinch::
# 48 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 49 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_TRAPINCH
# 50 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter
	return


LittlerootTown_ProfessorBirchsLab_Event_Pokeball_Starter_Aron::
# 54 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 55 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_ARON
# 56 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter
	return


LittlerootTown_ProfessorBirchsLab_Event_Pokeball_Starter_Spheal::
# 60 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 61 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_SPHEAL
# 62 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter
	return


LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter::
# 66 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER, LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_2
# 72 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	showmonpic VAR_TEMP_1, 10, 3
# 73 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 74 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_1, MSGBOX_YESNO
# 75 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_5
# 75 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_5
# 77 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_6
LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_4:
# 96 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 99 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_4
# 100 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 101 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_TEMP_1, SPECIES_TRAPINCH
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_12
# 105 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_TEMP_1, SPECIES_ARON
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_13
# 109 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_TEMP_1, SPECIES_SPHEAL
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_14
LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_11:
# 116 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement 6, Common_Movement_FaceLeft
# 117 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 118 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement 2, Common_Movement_FaceRight
# 119 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 120 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_5
# 121 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 122 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_6
# 123 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 124 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 126 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 127 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 130 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_7
# 131 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 132 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 133 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement 6, LittlerootTown_ProfessorBirchsLab_Movement_RivalWalksAway
# 134 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 135 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject 6
# 137 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 6
# 138 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_RECEIVED_STARTER
# 139 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 141 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	return

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_2:
# 67 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_0
	return

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_5:
# 76 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_2
	goto LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_4

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_6:
# 78 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	givemon VAR_TEMP_1, 5
# 79 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 80 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_3
# 81 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 82 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 83 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_TEMP_1, SPECIES_TRAPINCH
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_19
# 85 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_TEMP_1, SPECIES_ARON
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_20
# 87 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_TEMP_1, SPECIES_SPHEAL
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_21
LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_18:
# 90 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 91 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 92 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_25
	goto LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_4

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_12:
# 102 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement 6, LittlerootTown_ProfessorBirchsLab_Movement_RivalWalkUpToSpheal
# 103 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 104 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject 5
	goto LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_11

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_13:
# 106 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement 6, LittlerootTown_ProfessorBirchsLab_Movement_RivalWalkUpToTrapinch
# 107 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 108 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject 3
	goto LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_11

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_14:
# 110 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement 6, LittlerootTown_ProfessorBirchsLab_Movement_RivalWalkUpToAron
# 111 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 112 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject 4
	goto LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_11

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_19:
# 84 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject 3
	goto LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_18

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_20:
# 86 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject 4
	goto LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_18

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_21:
# 88 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject 5
	goto LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_18

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_25:
# 93 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_4


# 144 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_RivalWalkUpToSpheal:
# 145 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 146 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 147 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 148 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end

# 151 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_RivalWalkUpToTrapinch:
# 152 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 153 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 154 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 155 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end

# 158 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_RivalWalkUpToAron:
# 159 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 160 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 161 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end

# 164 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_RivalWalksAway:
# 165 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 166 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 167 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 168 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 169 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 170 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 171 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 172 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 173 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end

# 176 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 177 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .set LOCALID_AIDE, 1
# 178 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .set LOCALID_BIRCH, 2
# 179 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .set LOCALID_RIVAL, 3
# 180 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .set LOCALID_BALL_CYNDAQUIL, 4
# 181 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .set LOCALID_BALL_TOTODILE, 5
# 182 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .set LOCALID_BALL_CHIKORITA, 6
# 183 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 184 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_MapScripts::
# 185 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_OnTransition
# 186 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_OnWarp
# 187 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_OnFrame
# 188 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .byte 0
# 189 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 190 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ State descriptions for VAR_DEX_UPGRADE_JOHTO_STARTER_STATE
# 191 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 1: Beat Elite Four, Dex upgrade ready
# 192 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 2: Received National Dex
# 193 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 3: Left lab after receiving National Dex
# 194 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 4: Entered lab after catching all Hoenn mons
# 195 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 5: Birch told player to choose Johto starter
# 196 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 6: Chose Johto starter
# 197 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 198 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ State descriptions for VAR_BIRCH_LAB_STATE
# 199 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 1: Never occurs
# 200 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 2: Chose starter
# 201 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 3: Received starter in lab
# 202 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 4: Defeated rival on Route 103
# 203 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 5: Received pokedex
# 204 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 205 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_OnTransition:
# 206 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_SetupRivalGfxId
# 207 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call ProfBirch_EventScript_UpdateLocation
# 208 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout
# 209 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
# 210 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter
# 211 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 212 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 213 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter::
# 214 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ specialvar VAR_RESULT, HasAllHoennMons
# 215 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter
# 216 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 217 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxyperm LOCALID_RIVAL, 5, 10
# 218 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 219 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 220 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter::
# 221 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
# 222 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
# 223 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 224 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout::
# 225 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
# 226 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 227 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 228 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout::
# 229 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
# 230 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 231 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxyperm LOCALID_RIVAL, 5, 10
# 232 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 233 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 234 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_OnWarp:
# 235 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter
# 236 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
# 237 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
# 238 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
# 239 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
# 240 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
# 241 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
# 242 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .2byte 0
# 243 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 244 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter::
# 245 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 246 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 247 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 248 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade::
# 249 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 250 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ addobject LOCALID_BIRCH
# 251 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ addobject LOCALID_RIVAL
# 252 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject LOCALID_RIVAL, DIR_NORTH
# 253 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxy LOCALID_RIVAL, 5, 5
# 254 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject LOCALID_BIRCH, DIR_SOUTH
# 255 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxy LOCALID_BIRCH, 6, 4
# 256 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject LOCALID_AIDE, DIR_EAST
# 257 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxy LOCALID_AIDE, 10, 10
# 258 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 259 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 260 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject::
# 261 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ addobject LOCALID_RIVAL
# 262 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 263 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 264 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters::
# 265 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ addobject LOCALID_BALL_CYNDAQUIL
# 266 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ addobject LOCALID_BALL_TOTODILE
# 267 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ addobject LOCALID_BALL_CHIKORITA
# 268 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ addobject LOCALID_RIVAL
# 269 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject LOCALID_BALL_CYNDAQUIL, DIR_SOUTH
# 270 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxy LOCALID_BALL_CYNDAQUIL, 8, 4
# 271 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject LOCALID_BALL_TOTODILE, DIR_SOUTH
# 272 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxy LOCALID_BALL_TOTODILE, 9, 4
# 273 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject LOCALID_BALL_CHIKORITA, DIR_SOUTH
# 274 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxy LOCALID_BALL_CHIKORITA, 10, 4
# 275 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject LOCALID_BIRCH, DIR_SOUTH
# 276 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxy LOCALID_BIRCH, 6, 4
# 277 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject LOCALID_RIVAL, DIR_EAST
# 278 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxy LOCALID_RIVAL, 5, 5
# 279 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 280 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 281 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_OnFrame:
# 282 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent
# 283 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_BIRCH_LAB_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent
# 284 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex
# 285 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter
# 286 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .2byte 0
# 287 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 288 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ The starter is technically given prior to this on Route 101 by special ChooseStarter
# 289 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ This is just where the game tells you its yours and lets you nickname it
# 290 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent::
# 291 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ lockall
# 292 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ bufferleadmonspeciesname STR_VAR_1
# 293 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ message LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon
# 294 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmessage
# 295 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ playfanfare MUS_OBTAIN_ITEM
# 296 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitfanfare
# 297 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
# 298 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter
# 299 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
# 300 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 301 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 302 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter::
# 303 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_0x8004, 0
# 304 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_NameReceivedPartyMon
# 305 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
# 306 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 307 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 308 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival::
# 309 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival, MSGBOX_YESNO
# 310 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
# 311 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
# 312 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 313 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 314 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival::
# 315 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou, MSGBOX_DEFAULT
# 316 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ clearflag FLAG_HIDE_ROUTE_101_BOY
# 317 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_BIRCH_LAB_STATE, 3
# 318 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 319 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 320 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 321 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival::
# 322 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay, MSGBOX_YESNO
# 323 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
# 324 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
# 325 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 326 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 327 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent::
# 328 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ lockall
# 329 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
# 330 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 331 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex
# 332 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 333 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 334 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex:
# 335 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 336 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 337 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 338 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 339 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 340 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 341 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 342 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ step_end
# 343 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 344 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex::
# 345 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ lockall
# 346 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay 30
# 347 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational, MSGBOX_DEFAULT
# 348 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ closemessage
# 349 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement LOCALID_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes
# 350 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 351 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay 20
# 352 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ playse SE_CLICK
# 353 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay 10
# 354 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ playse SE_CLICK
# 355 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay 10
# 356 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ playse SE_CLICK
# 357 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay 10
# 358 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ playse SE_CLICK
# 359 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay 20
# 360 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterRight
# 361 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 362 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 363 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ checkplayergender
# 364 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment
# 365 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment
# 366 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ playse SE_PC_ON
# 367 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitse
# 368 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay 20
# 369 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement LOCALID_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex
# 370 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 371 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 372 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 373 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 374 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone, MSGBOX_DEFAULT
# 375 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ playfanfare MUS_OBTAIN_ITEM
# 376 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ message LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational
# 377 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmessage
# 378 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitfanfare
# 379 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setflag FLAG_SYS_NATIONAL_DEX
# 380 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ special EnableNationalPokedex
# 381 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
# 382 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ closemessage
# 383 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 384 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 385 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
# 386 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0
# 387 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
# 388 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 389 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 390 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 391 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment::
# 392 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool, MSGBOX_DEFAULT
# 393 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ closemessage
# 394 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 395 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 396 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment::
# 397 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe, MSGBOX_DEFAULT
# 398 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ closemessage
# 399 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 400 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 401 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes:
# 402 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_left
# 403 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_in_place_faster_down
# 404 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay_16
# 405 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay_16
# 406 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_right
# 407 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_in_place_faster_down
# 408 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay_16
# 409 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay_16
# 410 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_right
# 411 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_down
# 412 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_down
# 413 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_down
# 414 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_down
# 415 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_right
# 416 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_right
# 417 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_right
# 418 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_in_place_faster_up
# 419 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ step_end
# 420 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 421 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex:
# 422 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_left
# 423 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_left
# 424 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_left
# 425 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 426 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 427 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 428 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 429 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_left
# 430 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_in_place_faster_down
# 431 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ step_end
# 432 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 433 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter::
# 434 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ lockall
# 435 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter
# 436 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 437 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon, MSGBOX_DEFAULT
# 438 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
# 439 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 440 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 441 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 442 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter:
# 443 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 444 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 445 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 446 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 447 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 448 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 449 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 450 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ step_end
# 451 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 452 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Aide::
# 453 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 454 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 455 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter
# 456 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_set FLAG_BIRCH_AIDE_MET, LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet
# 457 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork, MSGBOX_DEFAULT
# 458 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_BIRCH_AIDE_MET
# 459 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 460 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 461 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 462 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet::
# 463 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork, MSGBOX_DEFAULT
# 464 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 465 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 466 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 467 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter::
# 468 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo, MSGBOX_DEFAULT
# 469 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 470 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 471 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 472 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_Cyndaquil::
# 473 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 474 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 475 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 476 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 477 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ showmonpic SPECIES_CYNDAQUIL, 10, 3
# 478 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil, MSGBOX_YESNO
# 479 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 480 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil
# 481 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 482 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 483 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_Totodile::
# 484 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 485 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 486 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 487 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 488 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ showmonpic SPECIES_TOTODILE, 10, 3
# 489 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile, MSGBOX_YESNO
# 490 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 491 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile
# 492 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 493 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 494 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_Chikorita::
# 495 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 496 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 497 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 498 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 499 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ showmonpic SPECIES_CHIKORITA, 10, 3
# 500 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita, MSGBOX_YESNO
# 501 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 502 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita
# 503 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 504 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 505 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter::
# 506 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone, MSGBOX_DEFAULT
# 507 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 508 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 509 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 510 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime::
# 511 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ hidemonpic
# 512 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
# 513 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 514 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 515 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 516 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil::
# 517 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ bufferspeciesname STR_VAR_1, SPECIES_CYNDAQUIL
# 518 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CYNDAQUIL
# 519 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ givemon SPECIES_CYNDAQUIL, 5
# 520 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty
# 521 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC
# 522 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ hidemonpic
# 523 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto Common_EventScript_NoMoreRoomForPokemon
# 524 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 525 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 526 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty::
# 527 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 528 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ removeobject LOCALID_BALL_CYNDAQUIL
# 529 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 530 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 531 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_GetGiftMonPartySlot
# 532 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_NameReceivedPartyMon
# 533 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 534 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 535 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 536 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC::
# 537 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 538 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ removeobject LOCALID_BALL_CYNDAQUIL
# 539 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 540 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
# 541 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_NameReceivedBoxMon
# 542 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
# 543 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 544 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 545 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC::
# 546 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_TransferredToPC
# 547 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 548 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 549 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 550 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil::
# 551 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ hidemonpic
# 552 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 553 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 554 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 555 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 556 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 557 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile::
# 558 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ bufferspeciesname STR_VAR_1, SPECIES_TOTODILE
# 559 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TOTODILE
# 560 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ givemon SPECIES_TOTODILE, 5
# 561 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty
# 562 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC
# 563 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ hidemonpic
# 564 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto Common_EventScript_NoMoreRoomForPokemon
# 565 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 566 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 567 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty::
# 568 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 569 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ removeobject LOCALID_BALL_TOTODILE
# 570 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 571 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 572 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_GetGiftMonPartySlot
# 573 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_NameReceivedPartyMon
# 574 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 575 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 576 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 577 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC::
# 578 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 579 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ removeobject LOCALID_BALL_TOTODILE
# 580 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 581 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
# 582 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_NameReceivedBoxMon
# 583 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
# 584 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 585 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 586 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC::
# 587 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_TransferredToPC
# 588 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 589 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 590 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 591 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile::
# 592 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ hidemonpic
# 593 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 594 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 595 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 596 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 597 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 598 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita::
# 599 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ bufferspeciesname STR_VAR_1, SPECIES_CHIKORITA
# 600 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHIKORITA
# 601 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ givemon SPECIES_CHIKORITA, 5
# 602 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty
# 603 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC
# 604 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ hidemonpic
# 605 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto Common_EventScript_NoMoreRoomForPokemon
# 606 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 607 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 608 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty::
# 609 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 610 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ removeobject LOCALID_BALL_CHIKORITA
# 611 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 612 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 613 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_GetGiftMonPartySlot
# 614 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_NameReceivedPartyMon
# 615 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 616 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 617 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 618 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC::
# 619 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 620 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ removeobject LOCALID_BALL_CHIKORITA
# 621 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 622 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
# 623 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_NameReceivedBoxMon
# 624 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
# 625 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 626 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 627 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC::
# 628 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_TransferredToPC
# 629 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 630 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 631 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 632 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita::
# 633 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ hidemonpic
# 634 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 635 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 636 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 637 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 638 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 639 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter::
# 640 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ playfanfare MUS_OBTAIN_ITEM
# 641 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ message LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter
# 642 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmessage
# 643 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitfanfare
# 644 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 645 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 646 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_Birch::
# 647 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ lock
# 648 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ faceplayer
# 649 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon
# 650 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting
# 651 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
# 652 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
# 653 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
# 654 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 655 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 656 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon::
# 657 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon, MSGBOX_DEFAULT
# 658 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 659 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 660 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 661 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting::
# 662 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
# 663 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 664 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 665 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 666 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister::
# 667 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
# 668 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, ProfBirch_EventScript_RatePokedexOrRegister
# 669 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, ProfBirch_EventScript_RatePokedexOrRegister
# 670 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_BIRCH_LAB_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait
# 671 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome, MSGBOX_DEFAULT
# 672 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 673 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 674 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 675 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ EventScript_RegisterProfBirch::
# 676 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
# 677 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ closemessage
# 678 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay 30
# 679 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ playfanfare MUS_REGISTER_MATCH_CALL
# 680 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
# 681 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitfanfare
# 682 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ closemessage
# 683 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay 30
# 684 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 685 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_REGISTER_BIRCH_STATE, 2
# 686 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 687 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 688 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 689 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex::
# 690 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
# 691 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex
# 692 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
# 693 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ closemessage
# 694 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement LOCALID_RIVAL, LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer
# 695 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 696 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 697 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 698 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ checkplayergender
# 699 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls
# 700 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls
# 701 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_BIRCH_LAB_STATE, 5
# 702 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setflag FLAG_ADVENTURE_STARTED
# 703 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_OLDALE_TOWN_STATE, 1
# 704 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_LITTLEROOT_RIVAL_STATE, 4
# 705 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_LITTLEROOT_TOWN_STATE, 3
# 706 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 707 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 708 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 709 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls::
# 710 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese, MSGBOX_DEFAULT
# 711 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ giveitem ITEM_POKE_BALL, 5
# 712 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls
# 713 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls, MSGBOX_DEFAULT
# 714 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_RESULT, 0
# 715 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 716 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 717 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls::
# 718 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese, MSGBOX_DEFAULT
# 719 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ giveitem ITEM_POKE_BALL, 5
# 720 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls
# 721 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls, MSGBOX_DEFAULT
# 722 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_RESULT, 1
# 723 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 724 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 725 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex::
# 726 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ playfanfare MUS_OBTAIN_ITEM
# 727 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
# 728 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitfanfare
# 729 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setflag FLAG_SYS_POKEDEX_GET
# 730 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ special SetUnlockedPokedexFlags
# 731 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 732 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
# 733 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 734 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 735 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait::
# 736 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
# 737 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 738 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 739 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 740 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls::
# 741 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
# 742 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 743 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 744 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls::
# 745 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull, MSGBOX_DEFAULT
# 746 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 747 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 748 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer:
# 749 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_down
# 750 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_in_place_faster_left
# 751 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ step_end
# 752 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 753 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_Machine::
# 754 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
# 755 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 756 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 757 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_Rival::
# 758 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ lock
# 759 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ faceplayer
# 760 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans
# 761 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier
# 762 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork
# 763 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ checkplayergender
# 764 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext
# 765 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext
# 766 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 767 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 768 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 769 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext::
# 770 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
# 771 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 772 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 773 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext::
# 774 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
# 775 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 776 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 777 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans::
# 778 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ checkplayergender
# 779 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere
# 780 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly
# 781 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 782 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 783 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 784 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere::
# 785 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere, MSGBOX_DEFAULT
# 786 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 787 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 788 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly:
# 789 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly, MSGBOX_DEFAULT
# 790 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 791 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 792 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier::
# 793 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ checkplayergender
# 794 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier
# 795 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier
# 796 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 797 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 798 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 799 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier::
# 800 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
# 801 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 802 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 803 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier::
# 804 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
# 805 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 806 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 807 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork::
# 808 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ checkplayergender
# 809 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork
# 810 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork
# 811 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 812 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 813 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 814 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork::
# 815 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork, MSGBOX_DEFAULT
# 816 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 817 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 818 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork::
# 819 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork, MSGBOX_DEFAULT
# 820 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 821 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 822 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_PC::
# 823 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch, MSGBOX_SIGN
# 824 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 825 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 826 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf::
# 827 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
# 828 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 829 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 830 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_Book::
# 831 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead, MSGBOX_SIGN
# 832 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 833 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 834 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall::
# 835 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ lockall
# 836 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ pokenavcall LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall
# 837 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmessage
# 838 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ clearflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
# 839 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 840 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 841 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 842 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork:
# 843 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Hunh? PROF. BIRCH?\p"
# 844 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF's away on fieldwork.\n"
# 845 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Ergo, he isn't here.\p"
# 846 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh, let me explain what fieldwork is.\p"
# 847 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It is to study things in the natural\n"
# 848 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "environment, like fields and mountains,\l"
# 849 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "instead of a laboratory.\p"
# 850 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF isn't one for doing desk work.\n"
# 851 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "He's the type of person who would\l"
# 852 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "rather go outside and experience\l"
# 853 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "things than read about them here.$"
# 854 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 855 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork:
# 856 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF isn't one for doing desk work.\n"
# 857 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "He's the type of person who would\l"
# 858 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "rather go outside and experience\l"
# 859 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "things than read about them here.$"
# 860 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 861 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo:
# 862 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH is studying the habitats\n"
# 863 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and distribution of POKéMON.\p"
# 864 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF enjoys {RIVAL}'s help, too.\n"
# 865 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "There's a lot of love there.$"
# 866 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 867 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon:
# 868 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: So, {PLAYER}{KUN}.\p"
# 869 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I've heard so much about you from\n"
# 870 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "your father.\p"
# 871 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I've heard that you don't have your\n"
# 872 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "own POKéMON yet.\p"
# 873 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "But the way you battled earlier,\n"
# 874 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "you pulled it off with aplomb!\p"
# 875 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I guess you have your father's blood\n"
# 876 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "in your veins after all!\p"
# 877 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Oh, yes. As thanks for rescuing me,\n"
# 878 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'd like you to have the POKéMON you\l"
# 879 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "used earlier.\p"
# 880 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "{PLAYER} received the {STR_VAR_1}!$"
# 881 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 882 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon:
# 883 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: While you're at it, why not\n"
# 884 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "give a nickname to that {STR_VAR_1}?$"
# 885 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 886 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival:
# 887 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: If you work at POKéMON\n"
# 888 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "and gain experience, I think you'll make\l"
# 889 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "an extremely good TRAINER.\p"
# 890 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "My kid, {RIVAL}, is also studying\n"
# 891 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "POKéMON while helping me out.\p"
# 892 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "{PLAYER}{KUN}, don't you think it might be\n"
# 893 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "a good idea to go see {RIVAL}?$"
# 894 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 895 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou:
# 896 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Great!\n"
# 897 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "{RIVAL} should be happy, too.\p"
# 898 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Get {RIVAL} to teach you what it\n"
# 899 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "means to be a TRAINER.$"
# 900 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 901 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay:
# 902 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Oh, don't be that way.\n"
# 903 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You should go meet my kid.$"
# 904 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 905 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome:
# 906 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: {RIVAL}?\n"
# 907 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Gone home, I think.\p"
# 908 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Or maybe that kid's scrabbling around\n"
# 909 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "in tall grass again somewhere…\p"
# 910 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "If you or your POKéMON get tired,\n"
# 911 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "you should get some rest at home.$"
# 912 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 913 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex:
# 914 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Oh, hi, {PLAYER}{KUN}!\p"
# 915 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I heard you beat {RIVAL} on\n"
# 916 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "your first try. That's excellent!\p"
# 917 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "{RIVAL}'s been helping with my research\n"
# 918 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "for a long time.\p"
# 919 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "{RIVAL} has an extensive history as\n"
# 920 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "a TRAINER already.\p"
# 921 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Here, {PLAYER}{KUN}, I ordered this for my\n"
# 922 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "research, but I think you should have\l"
# 923 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "this POKéDEX.$"
# 924 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 925 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex:
# 926 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "{PLAYER} received the POKéDEX!$"
# 927 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 928 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex:
# 929 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: The POKéDEX is a high-tech\n"
# 930 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "tool that automatically makes a record\l"
# 931 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "of any POKéMON you meet or catch.\p"
# 932 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "My kid, {RIVAL}, goes everywhere\n"
# 933 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "with it.\p"
# 934 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Whenever my kid catches a rare POKéMON\n"
# 935 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "and records its data in the POKéDEX,\l"
# 936 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "why, {RIVAL} looks for me while I'm out\l"
# 937 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "doing fieldwork, and shows me.$"
# 938 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 939 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait:
# 940 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Countless POKéMON\n"
# 941 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "await you!\p"
# 942 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Argh, I'm getting the itch to get out\n"
# 943 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "and do fieldwork again!$"
# 944 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 945 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese:
# 946 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "MAY: Oh, wow, {PLAYER}{KUN}!\n"
# 947 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You got a POKéDEX, too!\p"
# 948 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "That's great! Just like me!\n"
# 949 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I've got something for you, too!$"
# 950 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 951 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls:
# 952 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "MAY: It's fun if you can get a lot of\n"
# 953 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "POKéMON!\p"
# 954 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'm going to look all over the place\n"
# 955 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "because I want different POKéMON.\p"
# 956 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "If I find any cute POKéMON, I'll catch\n"
# 957 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "them with POKé BALLS!$"
# 958 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 959 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull:
# 960 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Oh? Your BAG's full.$"
# 961 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 962 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext:
# 963 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "MAY: I wonder where I should go look\n"
# 964 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "for POKéMON next?$"
# 965 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 966 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese:
# 967 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "BRENDAN: Huh…\n"
# 968 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "So you got a POKéDEX, too.\p"
# 969 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Well then, here.\n"
# 970 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'll give you these.$"
# 971 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 972 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls:
# 973 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "BRENDAN: You know it's more fun to\n"
# 974 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "have a whole bunch of POKéMON.\p"
# 975 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'm going to explore all over the place\n"
# 976 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "to find different POKéMON.\p"
# 977 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "If I find any cool POKéMON, you bet\n"
# 978 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'll try to get them with POKé BALLS.$"
# 979 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 980 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull:
# 981 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Hey, your BAG's full.$"
# 982 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 983 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext:
# 984 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "BRENDAN: Where should I look for\n"
# 985 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "POKéMON next…$"
# 986 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 987 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine:
# 988 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It's a serious-looking machine.\n"
# 989 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "The PROF must use this for research.$"
# 990 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 991 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch:
# 992 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It's a PC used for research.\n"
# 993 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Better not mess around with it.$"
# 994 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 995 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon:
# 996 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It's crammed with books on POKéMON.$"
# 997 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 998 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead:
# 999 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It's a book that's too hard to read.$"
# 1000 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1001 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational:
# 1002 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Now…\p"
# 1003 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "{PLAYER}{KUN} and {RIVAL}, I've had the two\n"
# 1004 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "of you help me study POKéMON.\p"
# 1005 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Thanks to your help, new facts\n"
# 1006 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "are coming to light.\p"
# 1007 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It appears that in the HOENN region,\n"
# 1008 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "there are also POKéMON from other\l"
# 1009 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "regions.\p"
# 1010 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It goes to show how rich and varied\n"
# 1011 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "the natural environments of HOENN\l"
# 1012 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "happen to be.\p"
# 1013 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "That's why I think it's necessary for\n"
# 1014 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "me to upgrade your POKéDEX to\l"
# 1015 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "the NATIONAL Mode.\p"
# 1016 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Here, let me see your POKéDEX units.$"
# 1017 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1018 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool:
# 1019 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "MAY: Eheheh!\p"
# 1020 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It's so cool that even my POKéDEX\n"
# 1021 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "is getting updated!\p"
# 1022 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It's because you went out and caught\n"
# 1023 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "so many POKéMON, {PLAYER}{KUN}!$"
# 1024 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1025 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe:
# 1026 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "BRENDAN: I went out all over HOENN\n"
# 1027 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "and checked out POKéMON.\p"
# 1028 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You can thank me for getting\n"
# 1029 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "the NATIONAL Mode POKéDEX.\p"
# 1030 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Yep, you're lucky, {PLAYER}!$"
# 1031 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1032 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone:
# 1033 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Okay, all done!$"
# 1034 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1035 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational:
# 1036 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "{PLAYER}'s POKéDEX was upgraded\n"
# 1037 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "to the NATIONAL Mode!$"
# 1038 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1039 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2:
# 1040 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: But listen.\n"
# 1041 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You've become the CHAMPION,\l"
# 1042 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "but your POKéMON journey isn't over.\p"
# 1043 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "There is no end to the road\n"
# 1044 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "that is POKéMON.\p"
# 1045 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Somewhere, there is a grassy patch\n"
# 1046 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "that's waiting for you!$"
# 1047 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1048 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork:
# 1049 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "MAY: I think I'll take a short break\n"
# 1050 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "from fieldwork.\p"
# 1051 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I think I'll help the PROF here for\n"
# 1052 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "a while.$"
# 1053 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1054 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork:
# 1055 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "BRENDAN: For the time being,\n"
# 1056 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'm taking a break from fieldwork.\p"
# 1057 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'll be helping out the PROF here\n"
# 1058 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "for a while.$"
# 1059 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1060 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon:
# 1061 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
# 1062 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Let's have a look at your POKéDEX.\p"
# 1063 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "… … … … … …\n"
# 1064 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "… … … … … …\p"
# 1065 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Yes, there's no doubt about it.\p"
# 1066 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You really have completed the HOENN\n"
# 1067 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "region's POKéDEX.\p"
# 1068 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "That's more than just impressive.\p"
# 1069 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I have a gift for you.\p"
# 1070 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Consider it my show of appreciation\n"
# 1071 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "for the fantastic work you've done.\p"
# 1072 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "My gift is a rare POKéMON only found\n"
# 1073 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "in another region!\p"
# 1074 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You can have any one of these\n"
# 1075 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "three POKéMON!$"
# 1076 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1077 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon:
# 1078 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: These are rare POKéMON\n"
# 1079 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "only found in another region!\p"
# 1080 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You can have any one of these\n"
# 1081 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "three POKéMON!$"
# 1082 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1083 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil:
# 1084 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: The FIRE POKéMON\n"
# 1085 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "CYNDAQUIL caught your eye!\p"
# 1086 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You're as sharp as ever!\p"
# 1087 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "So the CYNDAQUIL is your choice?$"
# 1088 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1089 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile:
# 1090 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: The WATER POKéMON\n"
# 1091 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "TOTODILE is your choice!\p"
# 1092 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You know how to pick a good one.\p"
# 1093 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "So, you'll take the TOTODILE?$"
# 1094 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1095 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita:
# 1096 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: The GRASS POKéMON\n"
# 1097 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "CHIKORITA is your choice!\p"
# 1098 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You sure know what you're doing.\p"
# 1099 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "So, you'll take the CHIKORITA?$"
# 1100 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1101 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable:
# 1102 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Take your time before\n"
# 1103 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "you decide.\p"
# 1104 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "They're all invaluable POKéMON.$"
# 1105 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1106 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ Unused
# 1107 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_PickedFinePokemon:
# 1108 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: I see!\n"
# 1109 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You picked a fine POKéMON!$"
# 1110 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1111 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter:
# 1112 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "{PLAYER} received the {STR_VAR_1}\n"
# 1113 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "from PROF. BIRCH!$"
# 1114 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1115 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ Unused
# 1116 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_NicknameJohtoStarter:
# 1117 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Want to give a nickname to\n"
# 1118 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "the {STR_VAR_1} you received?$"
# 1119 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1120 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting:
# 1121 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Listen, {PLAYER}{KUN}.\n"
# 1122 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You've completed the HOENN POKéDEX,\l"
# 1123 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "but your POKéMON journey isn't over.\p"
# 1124 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "There is no end to the road\n"
# 1125 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "that is POKéMON.\p"
# 1126 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Somewhere, there is a grassy patch\n"
# 1127 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "that's waiting for you!$"
# 1128 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1129 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone:
# 1130 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You received the promised POKéMON.\n"
# 1131 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Better leave the others alone.$"
# 1132 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1133 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ Unused
# 1134 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_DontHaveAnyRoomForPokemon:
# 1135 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Oh, you don't have any room for\n"
# 1136 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "this POKéMON.$"
# 1137 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1138 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere:
# 1139 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "MAY: {PLAYER}{KUN}, after this…\n"
# 1140 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "What are you going to do?\p"
# 1141 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Are you going to keep battling\n"
# 1142 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "and sharpening your skills?\p"
# 1143 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Or are you going to try filling\n"
# 1144 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "the NATIONAL POKéDEX?\p"
# 1145 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'm staying here to help the PROF.$"
# 1146 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1147 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly:
# 1148 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "BRENDAN: Rather than collecting\n"
# 1149 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "POKéMON, I prefer slowly and \l"
# 1150 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "steadily raising the one I chose.$"
# 1151 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1152 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier:
# 1153 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "MAY: Oh, hi, {PLAYER}{KUN}!\n"
# 1154 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Have you gone to that place,\l"
# 1155 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "the BATTLE FRONTIER?$"
# 1156 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1157 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier:
# 1158 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "BRENDAN: Hey, {PLAYER}!\n"
# 1159 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Have you gone out to that place,\l"
# 1160 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "the BATTLE FRONTIER?$"
# 1161 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1162 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall:
# 1163 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "… … … … … …\n"
# 1164 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "… … … … … Beep!\p"
# 1165 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "SCOTT: Hi, hi, {PLAYER}!\n"
# 1166 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It's me, SCOTT.\p"
# 1167 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'm aboard the S.S. TIDAL now.\n"
# 1168 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It feels great to be on the sea!\p"
# 1169 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "By the way…\p"
# 1170 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "There's this place that I'd like to\n"
# 1171 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "invite you to for a visit.\p"
# 1172 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "If you're interested, board a ferry\n"
# 1173 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "at either SLATEPORT or LILYCOVE.\p"
# 1174 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'll fill you in on the details when\n"
# 1175 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "we meet. I'll be waiting!\p"
# 1176 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "… … … … … …\n"
# 1177 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "… … … … … Click!$"

LittlerootTown_ProfessorBirchsLab_Event_DistributionCutscene_Text_0:
# 24 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Elder IWA: {PLAYER}, {RIVAL}, take\n"
	.string "one of these Pokémon.$"

LittlerootTown_ProfessorBirchsLab_Event_DistributionCutscene_Text_1:
# 30 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL}: C'mon {PLAYER}, pick\n"
	.string "yours!$"

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_0:
# 68 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You already got a Pokémon. Better leave\n"
	.string "this one here.$"

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_1:
# 74 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Do you want {STR_VAR_1}?$"

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_2:
# 76 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Take your time.$"

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_3:
# 80 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the Pokémon\n"
	.string "{STR_VAR_1}!$"

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_4:
# 99 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL}: I'm choosing this one then!$"

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_5:
# 120 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "ELDER: Great! Take these Pokédex and\n"
	.string "go.$"

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_6:
# 122 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the Pokédex!$"

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_7:
# 130 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL}: Catch ya later, {PLAYER}!$"

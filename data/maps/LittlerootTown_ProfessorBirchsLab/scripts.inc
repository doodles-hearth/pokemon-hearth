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
	closemessage
# 32 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement 6, Common_Movement_FaceUp
# 33 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 34 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 5
# 35 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	return


# 38 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_PlayerWalkUpToElder:
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
	walk_up
# 45 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end

LittlerootTown_ProfessorBirchsLab_Event_Pokeball_Starter_Trapinch::
# 49 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 50 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_CYNDAQUIL
# 51 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter
	return


LittlerootTown_ProfessorBirchsLab_Event_Pokeball_Starter_Aron::
# 55 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 56 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_FROAKIE
# 57 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter
	return


LittlerootTown_ProfessorBirchsLab_Event_Pokeball_Starter_Spheal::
# 61 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 62 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_SNIVY
# 63 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter
	return


LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter::
# 67 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER, LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_2
# 74 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	showmonpic VAR_TEMP_1, 10, 3
# 75 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 76 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_1, MSGBOX_YESNO
# 77 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_5
# 77 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_5
# 79 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_6
LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_4:
# 98 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 101 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_4
# 102 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 103 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_TEMP_1, SPECIES_CYNDAQUIL
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_12
# 107 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_TEMP_1, SPECIES_FROAKIE
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_13
# 111 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_TEMP_1, SPECIES_SNIVY
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_14
LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_11:
# 118 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement 6, Common_Movement_FaceLeft
# 119 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 120 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement 2, Common_Movement_FaceRight
# 121 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 122 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_5
# 123 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 124 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_6
# 125 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 126 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 128 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 129 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 132 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_7
# 133 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 134 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 135 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement 6, LittlerootTown_ProfessorBirchsLab_Movement_RivalWalksAway
# 136 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 137 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject 6
# 139 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 6
# 140 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_RECEIVED_STARTER
# 141 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 143 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	return

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_2:
# 68 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_0
# 71 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_5:
# 78 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_2
	goto LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_4

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_6:
# 80 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	givemon VAR_TEMP_1, 5
# 81 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 82 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	message LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_3
# 83 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 84 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 85 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_TEMP_1, SPECIES_CYNDAQUIL
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_19
# 87 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_TEMP_1, SPECIES_FROAKIE
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_20
# 89 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_TEMP_1, SPECIES_SNIVY
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_21
LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_18:
# 92 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 93 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 94 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_25
	goto LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_4

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_12:
# 104 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement 6, LittlerootTown_ProfessorBirchsLab_Movement_RivalWalkUpToSpheal
# 105 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 106 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject 5
	goto LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_11

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_13:
# 108 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement 6, LittlerootTown_ProfessorBirchsLab_Movement_RivalWalkUpToTrapinch
# 109 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 110 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject 3
	goto LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_11

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_14:
# 112 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	applymovement 6, LittlerootTown_ProfessorBirchsLab_Movement_RivalWalkUpToAron
# 113 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 114 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject 4
	goto LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_11

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_19:
# 86 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject 3
	goto LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_18

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_20:
# 88 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject 4
	goto LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_18

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_21:
# 90 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	removeobject 5
	goto LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_18

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_25:
# 95 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_4


# 146 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_RivalWalkUpToSpheal:
# 147 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 148 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 149 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 150 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end

# 153 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_RivalWalkUpToTrapinch:
# 154 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 155 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 156 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 157 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end

# 160 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_RivalWalkUpToAron:
# 161 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 162 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 163 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end

# 166 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Movement_RivalWalksAway:
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
	walk_down
# 174 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 175 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	step_end

# 178 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 179 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .set LOCALID_AIDE, 1
# 180 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .set LOCALID_BIRCH, 2
# 181 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .set LOCALID_RIVAL, 3
# 182 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .set LOCALID_BALL_CYNDAQUIL, 4
# 183 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .set LOCALID_BALL_TOTODILE, 5
# 184 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .set LOCALID_BALL_CHIKORITA, 6
# 185 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 186 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_MapScripts::
# 187 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_OnTransition
# 188 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_OnWarp
# 189 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_OnFrame
# 190 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .byte 0
# 191 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 192 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ State descriptions for VAR_DEX_UPGRADE_JOHTO_STARTER_STATE
# 193 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 1: Beat Elite Four, Dex upgrade ready
# 194 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 2: Received National Dex
# 195 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 3: Left lab after receiving National Dex
# 196 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 4: Entered lab after catching all Hoenn mons
# 197 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 5: Birch told player to choose Johto starter
# 198 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 6: Chose Johto starter
# 199 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 200 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ State descriptions for VAR_BIRCH_LAB_STATE
# 201 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 1: Never occurs
# 202 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 2: Chose starter
# 203 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 3: Received starter in lab
# 204 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 4: Defeated rival on Route 103
# 205 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ 5: Received pokedex
# 206 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 207 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_OnTransition:
# 208 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_SetupRivalGfxId
# 209 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call ProfBirch_EventScript_UpdateLocation
# 210 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout
# 211 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
# 212 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter
# 213 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 214 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 215 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter::
# 216 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ specialvar VAR_RESULT, HasAllHoennMons
# 217 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter
# 218 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 219 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxyperm LOCALID_RIVAL, 5, 10
# 220 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 221 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 222 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter::
# 223 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
# 224 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
# 225 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 226 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout::
# 227 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
# 228 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 229 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 230 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout::
# 231 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
# 232 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 233 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxyperm LOCALID_RIVAL, 5, 10
# 234 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 235 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 236 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_OnWarp:
# 237 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter
# 238 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
# 239 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
# 240 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
# 241 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
# 242 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
# 243 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
# 244 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .2byte 0
# 245 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 246 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter::
# 247 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 248 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 249 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 250 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade::
# 251 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 252 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ addobject LOCALID_BIRCH
# 253 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ addobject LOCALID_RIVAL
# 254 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject LOCALID_RIVAL, DIR_NORTH
# 255 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxy LOCALID_RIVAL, 5, 5
# 256 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject LOCALID_BIRCH, DIR_SOUTH
# 257 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxy LOCALID_BIRCH, 6, 4
# 258 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject LOCALID_AIDE, DIR_EAST
# 259 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxy LOCALID_AIDE, 10, 10
# 260 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 261 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 262 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject::
# 263 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ addobject LOCALID_RIVAL
# 264 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 265 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 266 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters::
# 267 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ addobject LOCALID_BALL_CYNDAQUIL
# 268 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ addobject LOCALID_BALL_TOTODILE
# 269 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ addobject LOCALID_BALL_CHIKORITA
# 270 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ addobject LOCALID_RIVAL
# 271 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject LOCALID_BALL_CYNDAQUIL, DIR_SOUTH
# 272 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxy LOCALID_BALL_CYNDAQUIL, 8, 4
# 273 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject LOCALID_BALL_TOTODILE, DIR_SOUTH
# 274 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxy LOCALID_BALL_TOTODILE, 9, 4
# 275 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject LOCALID_BALL_CHIKORITA, DIR_SOUTH
# 276 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxy LOCALID_BALL_CHIKORITA, 10, 4
# 277 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject LOCALID_BIRCH, DIR_SOUTH
# 278 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxy LOCALID_BIRCH, 6, 4
# 279 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ turnobject LOCALID_RIVAL, DIR_EAST
# 280 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setobjectxy LOCALID_RIVAL, 5, 5
# 281 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 282 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 283 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_OnFrame:
# 284 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent
# 285 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_BIRCH_LAB_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent
# 286 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex
# 287 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter
# 288 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .2byte 0
# 289 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 290 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ The starter is technically given prior to this on Route 101 by special ChooseStarter
# 291 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ This is just where the game tells you its yours and lets you nickname it
# 292 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent::
# 293 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ lockall
# 294 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ bufferleadmonspeciesname STR_VAR_1
# 295 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ message LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon
# 296 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmessage
# 297 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ playfanfare MUS_OBTAIN_ITEM
# 298 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitfanfare
# 299 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
# 300 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter
# 301 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
# 302 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 303 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 304 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter::
# 305 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_0x8004, 0
# 306 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_NameReceivedPartyMon
# 307 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
# 308 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 309 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 310 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival::
# 311 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival, MSGBOX_YESNO
# 312 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
# 313 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
# 314 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 315 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 316 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival::
# 317 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou, MSGBOX_DEFAULT
# 318 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ clearflag FLAG_HIDE_ROUTE_101_BOY
# 319 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_BIRCH_LAB_STATE, 3
# 320 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 321 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 322 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 323 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival::
# 324 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay, MSGBOX_YESNO
# 325 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
# 326 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
# 327 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 328 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 329 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent::
# 330 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ lockall
# 331 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
# 332 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 333 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex
# 334 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 335 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 336 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex:
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
@ walk_up
# 343 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 344 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ step_end
# 345 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 346 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex::
# 347 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ lockall
# 348 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay 30
# 349 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational, MSGBOX_DEFAULT
# 350 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ closemessage
# 351 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement LOCALID_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes
# 352 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 353 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay 20
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
@ delay 10
# 360 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ playse SE_CLICK
# 361 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay 20
# 362 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterRight
# 363 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 364 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 365 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ checkplayergender
# 366 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment
# 367 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment
# 368 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ playse SE_PC_ON
# 369 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitse
# 370 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay 20
# 371 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement LOCALID_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex
# 372 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 373 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 374 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 375 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 376 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone, MSGBOX_DEFAULT
# 377 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ playfanfare MUS_OBTAIN_ITEM
# 378 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ message LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational
# 379 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmessage
# 380 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitfanfare
# 381 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setflag FLAG_SYS_NATIONAL_DEX
# 382 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ special EnableNationalPokedex
# 383 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
# 384 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ closemessage
# 385 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 386 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 387 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
# 388 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0
# 389 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
# 390 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 391 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 392 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 393 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment::
# 394 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool, MSGBOX_DEFAULT
# 395 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ closemessage
# 396 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 397 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 398 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment::
# 399 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe, MSGBOX_DEFAULT
# 400 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ closemessage
# 401 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 402 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 403 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes:
# 404 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_left
# 405 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_in_place_faster_down
# 406 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay_16
# 407 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay_16
# 408 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_right
# 409 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_in_place_faster_down
# 410 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay_16
# 411 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay_16
# 412 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_right
# 413 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_down
# 414 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_down
# 415 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_down
# 416 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_down
# 417 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_right
# 418 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_right
# 419 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_right
# 420 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_in_place_faster_up
# 421 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ step_end
# 422 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 423 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex:
# 424 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_left
# 425 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_left
# 426 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_left
# 427 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 428 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 429 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 430 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 431 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_left
# 432 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_in_place_faster_down
# 433 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ step_end
# 434 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 435 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter::
# 436 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ lockall
# 437 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter
# 438 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 439 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon, MSGBOX_DEFAULT
# 440 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
# 441 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 442 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 443 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 444 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter:
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
@ walk_up
# 451 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_up
# 452 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ step_end
# 453 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 454 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_Aide::
# 455 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	lock
# 456 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 457 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter
# 458 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	goto_if_set FLAG_BIRCH_AIDE_MET, LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet
# 459 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork, MSGBOX_DEFAULT
# 460 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_BIRCH_AIDE_MET
# 461 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 462 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 463 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 464 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet::
# 465 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork, MSGBOX_DEFAULT
# 466 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 467 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 468 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 469 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter::
# 470 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo, MSGBOX_DEFAULT
# 471 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	release
# 472 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	end
# 473 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 474 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_Cyndaquil::
# 475 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 476 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 477 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 478 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 479 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ showmonpic SPECIES_CYNDAQUIL, 10, 3
# 480 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil, MSGBOX_YESNO
# 481 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 482 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil
# 483 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 484 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 485 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_Totodile::
# 486 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 487 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 488 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 489 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 490 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ showmonpic SPECIES_TOTODILE, 10, 3
# 491 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile, MSGBOX_YESNO
# 492 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 493 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile
# 494 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 495 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 496 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_Chikorita::
# 497 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 498 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 499 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 500 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 501 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ showmonpic SPECIES_CHIKORITA, 10, 3
# 502 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita, MSGBOX_YESNO
# 503 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 504 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita
# 505 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 506 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 507 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter::
# 508 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone, MSGBOX_DEFAULT
# 509 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 510 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 511 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 512 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime::
# 513 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ hidemonpic
# 514 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
# 515 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 516 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 517 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 518 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil::
# 519 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ bufferspeciesname STR_VAR_1, SPECIES_CYNDAQUIL
# 520 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CYNDAQUIL
# 521 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ givemon SPECIES_CYNDAQUIL, 5
# 522 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty
# 523 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC
# 524 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ hidemonpic
# 525 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto Common_EventScript_NoMoreRoomForPokemon
# 526 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 527 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 528 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty::
# 529 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 530 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ removeobject LOCALID_BALL_CYNDAQUIL
# 531 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 532 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 533 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_GetGiftMonPartySlot
# 534 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_NameReceivedPartyMon
# 535 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 536 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 537 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 538 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC::
# 539 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 540 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ removeobject LOCALID_BALL_CYNDAQUIL
# 541 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 542 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
# 543 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_NameReceivedBoxMon
# 544 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
# 545 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 546 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 547 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC::
# 548 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_TransferredToPC
# 549 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 550 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 551 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 552 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil::
# 553 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ hidemonpic
# 554 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 555 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 556 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 557 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 558 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 559 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile::
# 560 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ bufferspeciesname STR_VAR_1, SPECIES_TOTODILE
# 561 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TOTODILE
# 562 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ givemon SPECIES_TOTODILE, 5
# 563 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty
# 564 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC
# 565 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ hidemonpic
# 566 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto Common_EventScript_NoMoreRoomForPokemon
# 567 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 568 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 569 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty::
# 570 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 571 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ removeobject LOCALID_BALL_TOTODILE
# 572 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 573 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 574 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_GetGiftMonPartySlot
# 575 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_NameReceivedPartyMon
# 576 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 577 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 578 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 579 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC::
# 580 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 581 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ removeobject LOCALID_BALL_TOTODILE
# 582 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 583 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
# 584 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_NameReceivedBoxMon
# 585 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
# 586 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 587 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 588 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC::
# 589 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_TransferredToPC
# 590 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 591 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 592 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 593 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile::
# 594 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ hidemonpic
# 595 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 596 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 597 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 598 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 599 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 600 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita::
# 601 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ bufferspeciesname STR_VAR_1, SPECIES_CHIKORITA
# 602 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHIKORITA
# 603 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ givemon SPECIES_CHIKORITA, 5
# 604 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty
# 605 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC
# 606 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ hidemonpic
# 607 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto Common_EventScript_NoMoreRoomForPokemon
# 608 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 609 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 610 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty::
# 611 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 612 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ removeobject LOCALID_BALL_CHIKORITA
# 613 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 614 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 615 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_GetGiftMonPartySlot
# 616 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_NameReceivedPartyMon
# 617 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 618 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 619 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 620 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC::
# 621 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 622 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ removeobject LOCALID_BALL_CHIKORITA
# 623 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 624 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
# 625 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_NameReceivedBoxMon
# 626 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
# 627 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 628 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 629 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC::
# 630 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call Common_EventScript_TransferredToPC
# 631 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 632 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 633 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 634 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita::
# 635 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ hidemonpic
# 636 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 637 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 638 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 639 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 640 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 641 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter::
# 642 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ playfanfare MUS_OBTAIN_ITEM
# 643 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ message LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter
# 644 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmessage
# 645 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitfanfare
# 646 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 647 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 648 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_Birch::
# 649 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ lock
# 650 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ faceplayer
# 651 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon
# 652 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting
# 653 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
# 654 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
# 655 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
# 656 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 657 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 658 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon::
# 659 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon, MSGBOX_DEFAULT
# 660 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 661 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 662 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 663 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting::
# 664 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
# 665 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 666 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 667 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 668 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister::
# 669 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
# 670 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, ProfBirch_EventScript_RatePokedexOrRegister
# 671 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, ProfBirch_EventScript_RatePokedexOrRegister
# 672 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_BIRCH_LAB_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait
# 673 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome, MSGBOX_DEFAULT
# 674 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 675 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 676 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 677 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ EventScript_RegisterProfBirch::
# 678 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
# 679 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ closemessage
# 680 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay 30
# 681 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ playfanfare MUS_REGISTER_MATCH_CALL
# 682 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
# 683 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitfanfare
# 684 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ closemessage
# 685 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ delay 30
# 686 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 687 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_REGISTER_BIRCH_STATE, 2
# 688 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 689 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 690 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 691 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex::
# 692 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
# 693 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex
# 694 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
# 695 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ closemessage
# 696 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement LOCALID_RIVAL, LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer
# 697 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 698 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 699 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmovement 0
# 700 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ checkplayergender
# 701 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls
# 702 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls
# 703 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_BIRCH_LAB_STATE, 5
# 704 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setflag FLAG_ADVENTURE_STARTED
# 705 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_OLDALE_TOWN_STATE, 1
# 706 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_LITTLEROOT_RIVAL_STATE, 4
# 707 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_LITTLEROOT_TOWN_STATE, 3
# 708 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 709 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 710 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 711 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls::
# 712 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese, MSGBOX_DEFAULT
# 713 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ giveitem ITEM_POKE_BALL, 5
# 714 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls
# 715 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls, MSGBOX_DEFAULT
# 716 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_RESULT, 0
# 717 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 718 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 719 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls::
# 720 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese, MSGBOX_DEFAULT
# 721 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ giveitem ITEM_POKE_BALL, 5
# 722 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls
# 723 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls, MSGBOX_DEFAULT
# 724 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_RESULT, 1
# 725 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 726 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 727 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex::
# 728 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ playfanfare MUS_OBTAIN_ITEM
# 729 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
# 730 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitfanfare
# 731 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setflag FLAG_SYS_POKEDEX_GET
# 732 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ special SetUnlockedPokedexFlags
# 733 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 734 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
# 735 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 736 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 737 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait::
# 738 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
# 739 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 740 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 741 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 742 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls::
# 743 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
# 744 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 745 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 746 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls::
# 747 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull, MSGBOX_DEFAULT
# 748 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 749 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 750 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer:
# 751 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_down
# 752 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ walk_in_place_faster_left
# 753 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ step_end
# 754 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 755 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_Machine::
# 756 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
# 757 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 758 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 759 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_Rival::
# 760 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ lock
# 761 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ faceplayer
# 762 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans
# 763 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier
# 764 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork
# 765 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ checkplayergender
# 766 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext
# 767 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext
# 768 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 769 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 770 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 771 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext::
# 772 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
# 773 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 774 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 775 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext::
# 776 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
# 777 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 778 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 779 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans::
# 780 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ checkplayergender
# 781 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere
# 782 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly
# 783 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 784 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 785 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 786 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere::
# 787 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere, MSGBOX_DEFAULT
# 788 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 789 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 790 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly:
# 791 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly, MSGBOX_DEFAULT
# 792 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 793 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 794 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier::
# 795 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ checkplayergender
# 796 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier
# 797 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier
# 798 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 799 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 800 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 801 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier::
# 802 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
# 803 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 804 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 805 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier::
# 806 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
# 807 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 808 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 809 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork::
# 810 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ checkplayergender
# 811 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork
# 812 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork
# 813 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ release
# 814 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 815 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 816 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork::
# 817 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork, MSGBOX_DEFAULT
# 818 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 819 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 820 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork::
# 821 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork, MSGBOX_DEFAULT
# 822 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ return
# 823 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 824 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_PC::
# 825 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch, MSGBOX_SIGN
# 826 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 827 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 828 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf::
# 829 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
# 830 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 831 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 832 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_Book::
# 833 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ msgbox LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead, MSGBOX_SIGN
# 834 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 835 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 836 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall::
# 837 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ lockall
# 838 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ pokenavcall LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall
# 839 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ waitmessage
# 840 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ clearflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
# 841 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ releaseall
# 842 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ end
# 843 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 844 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork:
# 845 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Hunh? PROF. BIRCH?\p"
# 846 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF's away on fieldwork.\n"
# 847 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Ergo, he isn't here.\p"
# 848 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh, let me explain what fieldwork is.\p"
# 849 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "It is to study things in the natural\n"
# 850 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "environment, like fields and mountains,\l"
# 851 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "instead of a laboratory.\p"
# 852 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF isn't one for doing desk work.\n"
# 853 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "He's the type of person who would\l"
# 854 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "rather go outside and experience\l"
# 855 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "things than read about them here.$"
# 856 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 857 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork:
# 858 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF isn't one for doing desk work.\n"
# 859 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "He's the type of person who would\l"
# 860 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "rather go outside and experience\l"
# 861 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "things than read about them here.$"
# 862 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 863 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo:
# 864 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH is studying the habitats\n"
# 865 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "and distribution of POKéMON.\p"
# 866 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF enjoys Natsuki's help, too.\n"
# 867 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "There's a lot of love there.$"
# 868 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 869 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon:
# 870 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: So, {PLAYER}{KUN}.\p"
# 871 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I've heard so much about you from\n"
# 872 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "your father.\p"
# 873 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I've heard that you don't have your\n"
# 874 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "own POKéMON yet.\p"
# 875 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "But the way you battled earlier,\n"
# 876 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "you pulled it off with aplomb!\p"
# 877 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I guess you have your father's blood\n"
# 878 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "in your veins after all!\p"
# 879 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Oh, yes. As thanks for rescuing me,\n"
# 880 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'd like you to have the POKéMON you\l"
# 881 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "used earlier.\p"
# 882 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "{PLAYER} received the {STR_VAR_1}!$"
# 883 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 884 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon:
# 885 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: While you're at it, why not\n"
# 886 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "give a nickname to that {STR_VAR_1}?$"
# 887 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 888 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival:
# 889 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: If you work at POKéMON\n"
# 890 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "and gain experience, I think you'll make\l"
# 891 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "an extremely good TRAINER.\p"
# 892 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "My kid, Natsuki, is also studying\n"
# 893 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "POKéMON while helping me out.\p"
# 894 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "{PLAYER}{KUN}, don't you think it might be\n"
# 895 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "a good idea to go see Natsuki?$"
# 896 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 897 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou:
# 898 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Great!\n"
# 899 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Natsuki should be happy, too.\p"
# 900 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Get Natsuki to teach you what it\n"
# 901 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "means to be a TRAINER.$"
# 902 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 903 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay:
# 904 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Oh, don't be that way.\n"
# 905 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You should go meet my kid.$"
# 906 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 907 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome:
# 908 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Natsuki?\n"
# 909 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Gone home, I think.\p"
# 910 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Or maybe that kid's scrabbling around\n"
# 911 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "in tall grass again somewhere…\p"
# 912 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "If you or your POKéMON get tired,\n"
# 913 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "you should get some rest at home.$"
# 914 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 915 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex:
# 916 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Oh, hi, {PLAYER}{KUN}!\p"
# 917 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I heard you beat Natsuki on\n"
# 918 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "your first try. That's excellent!\p"
# 919 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Natsuki's been helping with my research\n"
# 920 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "for a long time.\p"
# 921 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Natsuki has an extensive history as\n"
# 922 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "a TRAINER already.\p"
# 923 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Here, {PLAYER}{KUN}, I ordered this for my\n"
# 924 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "research, but I think you should have\l"
# 925 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "this POKéDEX.$"
# 926 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 927 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex:
# 928 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "{PLAYER} received the POKéDEX!$"
# 929 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 930 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex:
# 931 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: The POKéDEX is a high-tech\n"
# 932 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "tool that automatically makes a record\l"
# 933 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "of any POKéMON you meet or catch.\p"
# 934 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "My kid, Natsuki, goes everywhere\n"
# 935 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "with it.\p"
# 936 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Whenever my kid catches a rare POKéMON\n"
# 937 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "and records its data in the POKéDEX,\l"
# 938 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "why, Natsuki looks for me while I'm out\l"
# 939 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "doing fieldwork, and shows me.$"
# 940 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 941 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait:
# 942 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Countless POKéMON\n"
# 943 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "await you!\p"
# 944 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Argh, I'm getting the itch to get out\n"
# 945 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "and do fieldwork again!$"
# 946 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 947 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese:
# 948 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "MAY: Oh, wow, {PLAYER}{KUN}!\n"
# 949 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You got a POKéDEX, too!\p"
# 950 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "That's great! Just like me!\n"
# 951 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I've got something for you, too!$"
# 952 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 953 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls:
# 954 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "MAY: It's fun if you can get a lot of\n"
# 955 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "POKéMON!\p"
# 956 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'm going to look all over the place\n"
# 957 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "because I want different POKéMON.\p"
# 958 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "If I find any cute POKéMON, I'll catch\n"
# 959 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "them with POKé BALLS!$"
# 960 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 961 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull:
# 962 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Oh? Your BAG's full.$"
# 963 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 964 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext:
# 965 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "MAY: I wonder where I should go look\n"
# 966 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "for POKéMON next?$"
# 967 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 968 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese:
# 969 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "BRENDAN: Huh…\n"
# 970 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "So you got a POKéDEX, too.\p"
# 971 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Well then, here.\n"
# 972 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'll give you these.$"
# 973 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 974 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls:
# 975 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "BRENDAN: You know it's more fun to\n"
# 976 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "have a whole bunch of POKéMON.\p"
# 977 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'm going to explore all over the place\n"
# 978 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "to find different POKéMON.\p"
# 979 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "If I find any cool POKéMON, you bet\n"
# 980 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'll try to get them with POKé BALLS.$"
# 981 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 982 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull:
# 983 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Hey, your BAG's full.$"
# 984 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 985 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext:
# 986 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "BRENDAN: Where should I look for\n"
# 987 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "POKéMON next…$"
# 988 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 989 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine:
# 990 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It's a serious-looking machine.\n"
# 991 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "The PROF must use this for research.$"
# 992 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 993 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch:
# 994 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It's a PC used for research.\n"
# 995 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Better not mess around with it.$"
# 996 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 997 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon:
# 998 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It's crammed with books on POKéMON.$"
# 999 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1000 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead:
# 1001 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It's a book that's too hard to read.$"
# 1002 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1003 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational:
# 1004 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Now…\p"
# 1005 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "{PLAYER}{KUN} and Natsuki, I've had the two\n"
# 1006 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "of you help me study POKéMON.\p"
# 1007 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Thanks to your help, new facts\n"
# 1008 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "are coming to light.\p"
# 1009 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It appears that in the HOENN region,\n"
# 1010 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "there are also POKéMON from other\l"
# 1011 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "regions.\p"
# 1012 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It goes to show how rich and varied\n"
# 1013 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "the natural environments of HOENN\l"
# 1014 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "happen to be.\p"
# 1015 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "That's why I think it's necessary for\n"
# 1016 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "me to upgrade your POKéDEX to\l"
# 1017 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "the NATIONAL Mode.\p"
# 1018 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Here, let me see your POKéDEX units.$"
# 1019 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1020 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool:
# 1021 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "MAY: Eheheh!\p"
# 1022 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It's so cool that even my POKéDEX\n"
# 1023 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "is getting updated!\p"
# 1024 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It's because you went out and caught\n"
# 1025 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "so many POKéMON, {PLAYER}{KUN}!$"
# 1026 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1027 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe:
# 1028 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "BRENDAN: I went out all over HOENN\n"
# 1029 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "and checked out POKéMON.\p"
# 1030 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You can thank me for getting\n"
# 1031 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "the NATIONAL Mode POKéDEX.\p"
# 1032 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Yep, you're lucky, {PLAYER}!$"
# 1033 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1034 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone:
# 1035 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Okay, all done!$"
# 1036 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1037 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational:
# 1038 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "{PLAYER}'s POKéDEX was upgraded\n"
# 1039 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "to the NATIONAL Mode!$"
# 1040 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1041 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2:
# 1042 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: But listen.\n"
# 1043 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You've become the CHAMPION,\l"
# 1044 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "but your POKéMON journey isn't over.\p"
# 1045 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "There is no end to the road\n"
# 1046 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "that is POKéMON.\p"
# 1047 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Somewhere, there is a grassy patch\n"
# 1048 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "that's waiting for you!$"
# 1049 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1050 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork:
# 1051 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "MAY: I think I'll take a short break\n"
# 1052 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "from fieldwork.\p"
# 1053 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I think I'll help the PROF here for\n"
# 1054 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "a while.$"
# 1055 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1056 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork:
# 1057 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "BRENDAN: For the time being,\n"
# 1058 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'm taking a break from fieldwork.\p"
# 1059 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'll be helping out the PROF here\n"
# 1060 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "for a while.$"
# 1061 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1062 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon:
# 1063 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
# 1064 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Let's have a look at your POKéDEX.\p"
# 1065 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "… … … … … …\n"
# 1066 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "… … … … … …\p"
# 1067 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Yes, there's no doubt about it.\p"
# 1068 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You really have completed the HOENN\n"
# 1069 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "region's POKéDEX.\p"
# 1070 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "That's more than just impressive.\p"
# 1071 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I have a gift for you.\p"
# 1072 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Consider it my show of appreciation\n"
# 1073 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "for the fantastic work you've done.\p"
# 1074 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "My gift is a rare POKéMON only found\n"
# 1075 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "in another region!\p"
# 1076 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You can have any one of these\n"
# 1077 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "three POKéMON!$"
# 1078 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1079 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon:
# 1080 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: These are rare POKéMON\n"
# 1081 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "only found in another region!\p"
# 1082 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You can have any one of these\n"
# 1083 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "three POKéMON!$"
# 1084 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1085 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil:
# 1086 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: The FIRE POKéMON\n"
# 1087 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "CYNDAQUIL caught your eye!\p"
# 1088 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You're as sharp as ever!\p"
# 1089 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "So the CYNDAQUIL is your choice?$"
# 1090 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1091 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile:
# 1092 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: The WATER POKéMON\n"
# 1093 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "TOTODILE is your choice!\p"
# 1094 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You know how to pick a good one.\p"
# 1095 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "So, you'll take the TOTODILE?$"
# 1096 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1097 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita:
# 1098 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: The GRASS POKéMON\n"
# 1099 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "CHIKORITA is your choice!\p"
# 1100 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You sure know what you're doing.\p"
# 1101 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "So, you'll take the CHIKORITA?$"
# 1102 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1103 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable:
# 1104 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Take your time before\n"
# 1105 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "you decide.\p"
# 1106 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "They're all invaluable POKéMON.$"
# 1107 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1108 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ Unused
# 1109 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_PickedFinePokemon:
# 1110 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: I see!\n"
# 1111 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You picked a fine POKéMON!$"
# 1112 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1113 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter:
# 1114 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "{PLAYER} received the {STR_VAR_1}\n"
# 1115 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "from PROF. BIRCH!$"
# 1116 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1117 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ Unused
# 1118 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_NicknameJohtoStarter:
# 1119 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Want to give a nickname to\n"
# 1120 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "the {STR_VAR_1} you received?$"
# 1121 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1122 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting:
# 1123 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "PROF. BIRCH: Listen, {PLAYER}{KUN}.\n"
# 1124 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You've completed the HOENN POKéDEX,\l"
# 1125 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "but your POKéMON journey isn't over.\p"
# 1126 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "There is no end to the road\n"
# 1127 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "that is POKéMON.\p"
# 1128 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Somewhere, there is a grassy patch\n"
# 1129 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "that's waiting for you!$"
# 1130 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1131 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone:
# 1132 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "You received the promised POKéMON.\n"
# 1133 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Better leave the others alone.$"
# 1134 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1135 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ @ Unused
# 1136 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_DontHaveAnyRoomForPokemon:
# 1137 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Oh, you don't have any room for\n"
# 1138 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "this POKéMON.$"
# 1139 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1140 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere:
# 1141 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "MAY: {PLAYER}{KUN}, after this…\n"
# 1142 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "What are you going to do?\p"
# 1143 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Are you going to keep battling\n"
# 1144 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "and sharpening your skills?\p"
# 1145 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Or are you going to try filling\n"
# 1146 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "the NATIONAL POKéDEX?\p"
# 1147 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'm staying here to help the PROF.$"
# 1148 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1149 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly:
# 1150 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "BRENDAN: Rather than collecting\n"
# 1151 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "POKéMON, I prefer slowly and \l"
# 1152 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "steadily raising the one I chose.$"
# 1153 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1154 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier:
# 1155 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "MAY: Oh, hi, {PLAYER}{KUN}!\n"
# 1156 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Have you gone to that place,\l"
# 1157 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "the BATTLE FRONTIER?$"
# 1158 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1159 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier:
# 1160 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "BRENDAN: Hey, {PLAYER}!\n"
# 1161 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "Have you gone out to that place,\l"
# 1162 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "the BATTLE FRONTIER?$"
# 1163 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"

# 1164 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall:
# 1165 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "… … … … … …\n"
# 1166 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "… … … … … Beep!\p"
# 1167 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "SCOTT: Hi, hi, {PLAYER}!\n"
# 1168 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It's me, SCOTT.\p"
# 1169 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'm aboard the S.S. TIDAL now.\n"
# 1170 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "It feels great to be on the sea!\p"
# 1171 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "By the way…\p"
# 1172 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "There's this place that I'd like to\n"
# 1173 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "invite you to for a visit.\p"
# 1174 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "If you're interested, board a ferry\n"
# 1175 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "at either SLATEPORT or LILYCOVE.\p"
# 1176 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "I'll fill you in on the details when\n"
# 1177 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "we meet. I'll be waiting!\p"
# 1178 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "… … … … … …\n"
# 1179 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
@ .string "… … … … … Click!$"

LittlerootTown_ProfessorBirchsLab_Event_DistributionCutscene_Text_0:
# 24 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Elder IWA: {PLAYER}, Natsuki, take\n"
	.string "one of these Pokémon.$"

LittlerootTown_ProfessorBirchsLab_Event_DistributionCutscene_Text_1:
# 30 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Natsuki: C'mon {PLAYER}, pick yours!$"

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_0:
# 69 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "You already got a Pokémon. Better\n"
	.string "leave this one here.$"

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_1:
# 76 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Do you want {STR_VAR_1}?$"

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_2:
# 78 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Take your time.$"

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_3:
# 82 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the Pokémon\n"
	.string "{STR_VAR_1}!$"

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_4:
# 101 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Natsuki: I'm choosing this one then!$"

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_5:
# 122 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "ELDER: Great! Take these Pokédex and\n"
	.string "go.$"

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_6:
# 124 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the Pokédex!$"

LittlerootTown_ProfessorBirchsLab_Event_Common_Pokeball_Starter_Text_7:
# 132 "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.pory"
	.string "Natsuki: Catch ya later, {PLAYER}!$"

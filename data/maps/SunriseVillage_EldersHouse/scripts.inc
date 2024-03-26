SunriseVillage_EldersHouse_MapScripts::
# 9 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_LOAD
# 12 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_LOAD:
# 10 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 4
	return

SunriseVillage_EldersHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 13 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	map_script_2 VAR_SUNRISE_VILLAGE_INTRO_STATE, 4, SunriseVillage_EldersHouse_Event_DistributionCutscene
	.2byte 0


SunriseVillage_EldersHouse_Event_DistributionCutscene::
# 18 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lockall
# 20 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_EldersHouse_Movement_PlayerWalkUpToElder
# 21 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 23 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_DistributionCutscene_Text_0
# 26 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 28 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 6, Common_Movement_FacePlayer
# 29 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 30 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_DistributionCutscene_Text_1
# 31 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 6, Common_Movement_FaceUp
# 32 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 33 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 5
# 34 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	releaseall
	return


# 37 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_PlayerWalkUpToElder:
# 38 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 39 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 40 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 41 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 42 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 43 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 44 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

SunriseVillage_EldersHouse_Event_Pokeball_Starter_Trapinch::
# 48 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lockall
# 49 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_TRAPINCH
# 50 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	call SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter
	return


SunriseVillage_EldersHouse_Event_Pokeball_Starter_Aron::
# 54 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lockall
# 55 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_ARON
# 56 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	call SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter
	return


SunriseVillage_EldersHouse_Event_Pokeball_Starter_Spheal::
# 60 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	lockall
# 61 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_SPHEAL
# 62 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	call SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter
	return


SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter::
# 66 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER, SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_2
# 72 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	showmonpic VAR_TEMP_1, 10, 3
# 73 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 74 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_1, MSGBOX_YESNO
# 75 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_5
# 75 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_5
# 77 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_6
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_4:
# 96 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	hidemonpic
# 99 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_4
# 100 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 101 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_TEMP_1, SPECIES_TRAPINCH
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_12
# 105 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_TEMP_1, SPECIES_ARON
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_13
# 109 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_TEMP_1, SPECIES_SPHEAL
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_14
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_11:
# 116 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 6, Common_Movement_FaceLeft
# 117 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 118 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 1, Common_Movement_FaceRight
# 119 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 120 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_5
# 121 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 122 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	message SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_6
# 123 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitfanfare
# 124 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 126 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 127 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 130 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_7
# 131 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	closemessage
# 132 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 133 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 6, SunriseVillage_EldersHouse_Movement_RivalWalksAway
# 134 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 135 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 6
# 137 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setvar VAR_SUNRISE_VILLAGE_INTRO_STATE, 6
# 138 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setflag FLAG_RECEIVED_STARTER
# 139 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 141 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	releaseall
	return

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_2:
# 67 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_0
	return

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_5:
# 76 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_2
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_4

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_6:
# 78 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	givemon VAR_TEMP_1, 5
# 79 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 80 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	message SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_3
# 81 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmessage
# 82 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitfanfare
# 83 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_TEMP_1, SPECIES_TRAPINCH
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_19
# 85 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_TEMP_1, SPECIES_ARON
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_20
# 87 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_TEMP_1, SPECIES_SPHEAL
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_21
SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_18:
# 90 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 91 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 92 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_25
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_4

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_12:
# 102 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 6, SunriseVillage_EldersHouse_Movement_RivalWalkUpToSpheal
# 103 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 104 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 5
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_11

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_13:
# 106 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 6, SunriseVillage_EldersHouse_Movement_RivalWalkUpToTrapinch
# 107 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 108 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 3
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_11

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_14:
# 110 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	applymovement 6, SunriseVillage_EldersHouse_Movement_RivalWalkUpToAron
# 111 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	waitmovement 0
# 112 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 4
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_11

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_19:
# 84 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 3
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_18

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_20:
# 86 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 4
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_18

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_21:
# 88 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	removeobject 5
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_18

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_25:
# 93 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_4


# 144 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_RivalWalkUpToSpheal:
# 145 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_right
# 146 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 147 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 148 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 151 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_RivalWalkUpToTrapinch:
# 152 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_left
# 153 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 154 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 155 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 158 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_RivalWalkUpToAron:
# 159 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_up
# 160 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	delay_16
# 161 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

# 164 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
SunriseVillage_EldersHouse_Movement_RivalWalksAway:
# 165 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 166 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 167 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 168 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 169 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 170 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 171 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 172 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	walk_down
# 173 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	step_end

SunriseVillage_EldersHouse_Event_DistributionCutscene_Text_0:
# 24 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Elder Kaba: {PLAYER}, {RIVAL},\n"
	.string "take one of these Pokémon.$"

SunriseVillage_EldersHouse_Event_DistributionCutscene_Text_1:
# 30 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{RIVAL}: C'mon {PLAYER}, pick\n"
	.string "yours!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_0:
# 68 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "You already got a Pokémon. Better leave\n"
	.string "this one here.$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_1:
# 74 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Do you want {STR_VAR_1}?$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_2:
# 76 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "Take your time.$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_3:
# 80 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{PLAYER} received the Pokémon\n"
	.string "{STR_VAR_1}!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_4:
# 99 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{RIVAL}: I'm choosing this one then!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_5:
# 120 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "ELDER: Great! Take these Pokédex and\n"
	.string "go.$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_6:
# 122 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{PLAYER} received the Pokédex!$"

SunriseVillage_EldersHouse_Event_Common_Pokeball_Starter_Text_7:
# 130 "data/maps/SunriseVillage_EldersHouse/scripts.pory"
	.string "{RIVAL}: Catch ya later, {PLAYER}!$"

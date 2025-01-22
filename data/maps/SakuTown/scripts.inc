SakuTown_MapScripts::
# 8 "data/maps/SakuTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 17 "data/maps/SakuTown/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 9 "data/maps/SakuTown/scripts.pory"
	call SakuVillage_NPCSchedules
# 10 "data/maps/SakuTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 11 "data/maps/SakuTown/scripts.pory"
	goto_if_set FLAG_SAKU_KURA_REUNITED, SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 13 "data/maps/SakuTown/scripts.pory"
	setmetatile 19, 2, METATILE_SakuKura_BoardGame, TRUE
# 14 "data/maps/SakuTown/scripts.pory"
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_RIGHT
	return

SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD:
# 18 "data/maps/SakuTown/scripts.pory"
	call SakuVillage_DrawMetatiles
	return


SakuTown_EventScript_RivalAtSakuWall::
# 24 "data/maps/SakuTown/scripts.pory"
	lock
# 25 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_RivalAtSakuWall_Text_0
# 26 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_RivalAtSakuWall_Text_1
# 27 "data/maps/SakuTown/scripts.pory"
	closemessage
# 29 "data/maps/SakuTown/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 30 "data/maps/SakuTown/scripts.pory"
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
# 32 "data/maps/SakuTown/scripts.pory"
	clearflag FLAG_HIDE_RIVAL_SAKU
# 33 "data/maps/SakuTown/scripts.pory"
	addobject 10
# 34 "data/maps/SakuTown/scripts.pory"
	compare VAR_TEMP_2, 16
	goto_if_eq SakuTown_EventScript_RivalAtSakuWall_2
# 37 "data/maps/SakuTown/scripts.pory"
	setobjectxy 10, 17, 10
SakuTown_EventScript_RivalAtSakuWall_1:
# 39 "data/maps/SakuTown/scripts.pory"
	applymovement 10, SakuTown_Movement_WalkUp
# 40 "data/maps/SakuTown/scripts.pory"
	waitmovement 0
# 42 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_RivalAtSakuWall_Text_2
# 43 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_RivalAtSakuWall_Text_3
# 50 "data/maps/SakuTown/scripts.pory"
	switch VAR_STARTER_MON
# 51 "data/maps/SakuTown/scripts.pory"
	case SPECIES_ARON, SakuTown_EventScript_RivalAtSakuWall_7
# 53 "data/maps/SakuTown/scripts.pory"
	case SPECIES_SPHEAL, SakuTown_EventScript_RivalAtSakuWall_8
# 55 "data/maps/SakuTown/scripts.pory"
	case SPECIES_TRAPINCH, SakuTown_EventScript_RivalAtSakuWall_9
SakuTown_EventScript_RivalAtSakuWall_5:
# 59 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_RivalAtSakuWall_Text_2
# 60 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_RivalAtSakuWall_Text_4
# 72 "data/maps/SakuTown/scripts.pory"
	closemessage
# 75 "data/maps/SakuTown/scripts.pory"
	compare VAR_TEMP_2, 16
	goto_if_eq SakuTown_EventScript_RivalAtSakuWall_11
# 79 "data/maps/SakuTown/scripts.pory"
	applymovement 10, SakuTown_Movement_GoToKuraFromLeft
SakuTown_EventScript_RivalAtSakuWall_10:
# 81 "data/maps/SakuTown/scripts.pory"
	waitmovement 0
# 83 "data/maps/SakuTown/scripts.pory"
	removeobject 10
# 84 "data/maps/SakuTown/scripts.pory"
	setflag FLAG_HIDE_RIVAL_SAKU
# 86 "data/maps/SakuTown/scripts.pory"
	setvar VAR_RIVAL_ENCOUNTER_STATE, 1
# 88 "data/maps/SakuTown/scripts.pory"
	release
	return

SakuTown_EventScript_RivalAtSakuWall_2:
# 35 "data/maps/SakuTown/scripts.pory"
	setobjectxy 10, 16, 10
	goto SakuTown_EventScript_RivalAtSakuWall_1

SakuTown_EventScript_RivalAtSakuWall_7:
# 52 "data/maps/SakuTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_SAKU_SNIVY, SakuTown_Text_RivalDefeat
	goto SakuTown_EventScript_RivalAtSakuWall_5

SakuTown_EventScript_RivalAtSakuWall_8:
# 54 "data/maps/SakuTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_SAKU_FROAKIE, SakuTown_Text_RivalDefeat
	goto SakuTown_EventScript_RivalAtSakuWall_5

SakuTown_EventScript_RivalAtSakuWall_9:
# 56 "data/maps/SakuTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_SAKU_CYNDAQUIL, SakuTown_Text_RivalDefeat
	goto SakuTown_EventScript_RivalAtSakuWall_5

SakuTown_EventScript_RivalAtSakuWall_11:
# 76 "data/maps/SakuTown/scripts.pory"
	applymovement 10, SakuTown_Movement_GoToKuraFromRight
	goto SakuTown_EventScript_RivalAtSakuWall_10


blabla::
# 93 "data/maps/SakuTown/scripts.pory"
	lock
# 94 "data/maps/SakuTown/scripts.pory"
	setvar VAR_RIVAL_ENCOUNTER_STATE, 0
# 95 "data/maps/SakuTown/scripts.pory"
	gettime
# 96 "data/maps/SakuTown/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8000
# 97 "data/maps/SakuTown/scripts.pory"
	msgbox blabla_Text_0
# 98 "data/maps/SakuTown/scripts.pory"
	release
	return


# 105 "data/maps/SakuTown/scripts.pory"
SakuTown_Movement_GoToKuraFromLeft:
# 106 "data/maps/SakuTown/scripts.pory"
	walk_faster_left
# 107 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
# 107 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
# 107 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
# 107 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
# 107 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
	step_end

# 110 "data/maps/SakuTown/scripts.pory"
SakuTown_Movement_GoToKuraFromRight:
# 111 "data/maps/SakuTown/scripts.pory"
	walk_faster_right
# 112 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
# 112 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
# 112 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
# 112 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
# 112 "data/maps/SakuTown/scripts.pory"
	walk_faster_up
	step_end

# 115 "data/maps/SakuTown/scripts.pory"
SakuTown_Movement_WalkUp:
# 116 "data/maps/SakuTown/scripts.pory"
	walk_up
# 116 "data/maps/SakuTown/scripts.pory"
	walk_up
# 116 "data/maps/SakuTown/scripts.pory"
	walk_up
# 116 "data/maps/SakuTown/scripts.pory"
	walk_up
# 116 "data/maps/SakuTown/scripts.pory"
	walk_up
	step_end

# 119 "data/maps/SakuTown/scripts.pory"
SakuTown_Movement_WalkFastUp:
# 120 "data/maps/SakuTown/scripts.pory"
	walk_fast_up
	step_end

# 123 "data/maps/SakuTown/scripts.pory"
SakuTown_Movement_WalkAway:
# 124 "data/maps/SakuTown/scripts.pory"
	walk_fast_down
# 124 "data/maps/SakuTown/scripts.pory"
	walk_fast_down
# 124 "data/maps/SakuTown/scripts.pory"
	walk_fast_down
# 124 "data/maps/SakuTown/scripts.pory"
	walk_fast_down
# 124 "data/maps/SakuTown/scripts.pory"
	walk_fast_down
# 124 "data/maps/SakuTown/scripts.pory"
	walk_fast_down
	step_end

SakuTown_EventScript_Farmer::
# 128 "data/maps/SakuTown/scripts.pory"
	lock
# 129 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 130 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Farmer_Text_0
# 131 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Farmer_Text_1
# 134 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Farmer2::
# 138 "data/maps/SakuTown/scripts.pory"
	lock
# 139 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Farmer_Text_0
# 140 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Farmer2_Text_0
# 144 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Woman::
# 148 "data/maps/SakuTown/scripts.pory"
	lock
# 149 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 150 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Woman_Text_0
# 151 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Woman_Text_1
# 155 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Karateka::
# 159 "data/maps/SakuTown/scripts.pory"
	lock
# 160 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 161 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Karateka_Text_0
# 162 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Karateka_Text_1
# 165 "data/maps/SakuTown/scripts.pory"
	closemessage
# 166 "data/maps/SakuTown/scripts.pory"
	applymovement 6, Common_Movement_FaceUp
# 167 "data/maps/SakuTown/scripts.pory"
	waitmovement 0
# 168 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Karateka_Text_0
# 169 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Karateka_Text_2
# 172 "data/maps/SakuTown/scripts.pory"
	closemessage
# 174 "data/maps/SakuTown/scripts.pory"
	applymovement 1, Common_Movement_FaceDown
# 175 "data/maps/SakuTown/scripts.pory"
	applymovement 2, Common_Movement_FaceDown
# 176 "data/maps/SakuTown/scripts.pory"
	waitmovement 1
# 177 "data/maps/SakuTown/scripts.pory"
	waitmovement 2
# 179 "data/maps/SakuTown/scripts.pory"
	delay 24
# 181 "data/maps/SakuTown/scripts.pory"
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
# 182 "data/maps/SakuTown/scripts.pory"
	applymovement 1, SakuTown_EventScript_Karateka_Movement_0
# 183 "data/maps/SakuTown/scripts.pory"
	waitmovement 1
# 184 "data/maps/SakuTown/scripts.pory"
	waitmoncry
# 185 "data/maps/SakuTown/scripts.pory"
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
# 186 "data/maps/SakuTown/scripts.pory"
	applymovement 2, SakuTown_EventScript_Karateka_Movement_0
# 187 "data/maps/SakuTown/scripts.pory"
	waitmovement 2
# 188 "data/maps/SakuTown/scripts.pory"
	waitmoncry
# 190 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Guard::
# 194 "data/maps/SakuTown/scripts.pory"
	lock
# 195 "data/maps/SakuTown/scripts.pory"
	goto_if_set FLAG_SAKU_KURA_REUNITED, SakuTown_EventScript_Guard_2
# 202 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 203 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Guard_Text_0
# 204 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Guard_Text_2
# 208 "data/maps/SakuTown/scripts.pory"
	closemessage
# 209 "data/maps/SakuTown/scripts.pory"
	applymovement 8, Common_Movement_FaceOriginalDirection
# 210 "data/maps/SakuTown/scripts.pory"
	waitmovement 0
SakuTown_EventScript_Guard_1:
# 212 "data/maps/SakuTown/scripts.pory"
	release
	return

SakuTown_EventScript_Guard_2:
# 196 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Guard_Text_0
# 197 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Guard_Text_1
# 200 "data/maps/SakuTown/scripts.pory"
	closemessage
	goto SakuTown_EventScript_Guard_1


SakuTown_EventScript_KuraGuard::
# 216 "data/maps/SakuTown/scripts.pory"
	lock
# 217 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Guard_Text_0
# 218 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_KuraGuard_Text_0
# 221 "data/maps/SakuTown/scripts.pory"
	closemessage
# 222 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_GuardSeesYou::
# 226 "data/maps/SakuTown/scripts.pory"
	lock
# 228 "data/maps/SakuTown/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 231 "data/maps/SakuTown/scripts.pory"
	compare VAR_SAKU_KURA_VILLAGES_STATE, 0
	goto_if_eq SakuTown_EventScript_GuardSeesYou_2
# 234 "data/maps/SakuTown/scripts.pory"
	compare VAR_SAKU_KURA_VILLAGES_STATE, 2
	goto_if_eq SakuTown_EventScript_GuardSeesYou_4
SakuTown_EventScript_GuardSeesYou_1:
# 238 "data/maps/SakuTown/scripts.pory"
	release
	return

SakuTown_EventScript_GuardSeesYou_2:
# 232 "data/maps/SakuTown/scripts.pory"
	call SakuTown_EventScript_GuardStopsYou
	goto SakuTown_EventScript_GuardSeesYou_1

SakuTown_EventScript_GuardSeesYou_3:
# 235 "data/maps/SakuTown/scripts.pory"
	call SakuTown_EventScript_GuardStopsYou
	goto SakuTown_EventScript_GuardSeesYou_1

SakuTown_EventScript_GuardSeesYou_4:
# 234 "data/maps/SakuTown/scripts.pory"
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq SakuTown_EventScript_GuardSeesYou_3
	goto SakuTown_EventScript_GuardSeesYou_1


SakuTown_EventScript_GuardStopsYou::
# 242 "data/maps/SakuTown/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 243 "data/maps/SakuTown/scripts.pory"
	applymovement 8, Common_Movement_WalkInPlaceFasterLeft
# 244 "data/maps/SakuTown/scripts.pory"
	waitmovement 8
# 245 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Guard_Text_0
# 246 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_GuardStopsYou_Text_0
# 247 "data/maps/SakuTown/scripts.pory"
	closemessage
# 248 "data/maps/SakuTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 249 "data/maps/SakuTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 250 "data/maps/SakuTown/scripts.pory"
	delay 20
# 252 "data/maps/SakuTown/scripts.pory"
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq SakuTown_EventScript_GuardStopsYou_2
# 262 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Guard_Text_0
# 263 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_GuardStopsYou_Text_2
# 268 "data/maps/SakuTown/scripts.pory"
	closemessage
# 269 "data/maps/SakuTown/scripts.pory"
	setvar VAR_SAKU_KURA_VILLAGES_STATE, 1
SakuTown_EventScript_GuardStopsYou_1:
# 272 "data/maps/SakuTown/scripts.pory"
	applymovement 8, Common_Movement_FaceDown
	return

SakuTown_EventScript_GuardStopsYou_2:
# 253 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Guard_Text_0
# 254 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_GuardStopsYou_Text_1
# 259 "data/maps/SakuTown/scripts.pory"
	closemessage
# 260 "data/maps/SakuTown/scripts.pory"
	setvar VAR_SAKU_KURA_VILLAGES_STATE, 3
	goto SakuTown_EventScript_GuardStopsYou_1


SakuTown_EventScript_TownSign::
# 277 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_TrainerTips::
# 281 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_TrainerTips_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_TrainerTips2::
# 285 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_TrainerTips2_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_FloristSign::
# 289 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_FloristSign_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_BoardGame::
# 293 "data/maps/SakuTown/scripts.pory"
	goto_if_set FLAG_SAKU_KURA_REUNITED, SakuTown_EventScript_BoardGame_1
	return

SakuTown_EventScript_BoardGame_1:
# 294 "data/maps/SakuTown/scripts.pory"
	lock
# 295 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_BoardGame_Text_0, MSGBOX_DEFAULT
# 296 "data/maps/SakuTown/scripts.pory"
	closemessage
# 297 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Mart::
# 302 "data/maps/SakuTown/scripts.pory"
	lock
# 303 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 304 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Mart_Text_0
# 305 "data/maps/SakuTown/scripts.pory"
	message gText_HowMayIServeYou
# 306 "data/maps/SakuTown/scripts.pory"
	waitmessage
# 307 "data/maps/SakuTown/scripts.pory"
	pokemart SakuTown_Mart
# 308 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Mart_Text_0
# 309 "data/maps/SakuTown/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 310 "data/maps/SakuTown/scripts.pory"
	release
	return


	.align 2
# 313 "data/maps/SakuTown/scripts.pory"
SakuTown_Mart:
# 314 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_POKE_BALL
# 315 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_BERRY_JUICE
# 316 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 317 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 318 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_AWAKENING
# 319 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 320 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

SakuTown_EventScript_Makuhita::
# 324 "data/maps/SakuTown/scripts.pory"
	lock
# 325 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 326 "data/maps/SakuTown/scripts.pory"
	waitse
# 327 "data/maps/SakuTown/scripts.pory"
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
# 328 "data/maps/SakuTown/scripts.pory"
	speakername SakuTown_EventScript_Makuhita_Text_0
# 329 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Makuhita_Text_1
# 330 "data/maps/SakuTown/scripts.pory"
	waitmoncry
# 331 "data/maps/SakuTown/scripts.pory"
	release
	return


# 182 "data/maps/SakuTown/scripts.pory"
SakuTown_EventScript_Karateka_Movement_0:
# 182 "data/maps/SakuTown/scripts.pory"
	jump_in_place_down
	step_end

SakuTown_EventScript_RivalAtSakuWall_Text_0:
# 25 "data/maps/SakuTown/scripts.pory"
	.string "???$"

SakuTown_EventScript_RivalAtSakuWall_Text_1:
# 26 "data/maps/SakuTown/scripts.pory"
	.string "Wait up, {PLAYER}!$"

SakuTown_EventScript_RivalAtSakuWall_Text_2:
# 42 "data/maps/SakuTown/scripts.pory"
	.string "Natsuki$"

SakuTown_EventScript_RivalAtSakuWall_Text_3:
# 44 "data/maps/SakuTown/scripts.pory"
	.string "I was wondering if you'd already\n"
	.string "reached Saku Village by now. Looks\l"
	.string "like we almost missed each other!\p"
	.string "Have you caught any Pokémon on your\n"
	.string "way here?\p"
	.string "Me? Oh, I can show you my Pokémon\n"
	.string "alright!$"

SakuTown_EventScript_RivalAtSakuWall_Text_4:
# 61 "data/maps/SakuTown/scripts.pory"
	.string "Okay, I… I didn't think you'd go that\n"
	.string "hard, honestly!\p"
	.string "Hahaha…\p"
	.string "Clearly I underestimated you. That's\n"
	.string "alright. I won't make that mistake\l"
	.string "next time!\p"
	.string "I can see your Pokémon are really\n"
	.string "growing to like you, it's great!\p"
	.string "You definitely stand a chance\n"
	.string "against the Dojo that's in the next\l"
	.string "village.\p"
	.string "Me? Actually, I just fought the Dojo's\n"
	.string "master and got a token from her!\p"
	.string "You'll have to hurry up if you wanna\n"
	.string "catch up!\p"
	.string "Well, it was good to see you. Until\n"
	.string "next time then.\p"
	.string "I bet you I'll get to Silveridge first!\p"
	.string "Race ya there!!!$"

blabla_Text_0:
# 97 "data/maps/SakuTown/scripts.pory"
	.string "{STR_VAR_1}$"

SakuTown_EventScript_Farmer_Text_0:
# 130 "data/maps/SakuTown/scripts.pory"
	.string "Farmer$"

SakuTown_EventScript_Farmer_Text_1:
# 132 "data/maps/SakuTown/scripts.pory"
	.string "We're cultivatin' Mifan berries. Saku\n"
	.string "Village exports its berries to many\l"
	.string "towns.$"

SakuTown_EventScript_Farmer2_Text_0:
# 141 "data/maps/SakuTown/scripts.pory"
	.string "Whew…\p"
	.string "Working in the fields sure is tiring…$"

SakuTown_EventScript_Woman_Text_0:
# 150 "data/maps/SakuTown/scripts.pory"
	.string "Woman$"

SakuTown_EventScript_Woman_Text_1:
# 152 "data/maps/SakuTown/scripts.pory"
	.string "Those thugs in Kura Village may have\n"
	.string "their own Dojo, but their town is\l"
	.string "nothing but an ugly pile of rocks!\p"
	.string "They don't even have a Pokémon\n"
	.string "refuge!$"

SakuTown_EventScript_Karateka_Text_0:
# 161 "data/maps/SakuTown/scripts.pory"
	.string "Man$"

SakuTown_EventScript_Karateka_Text_1:
# 163 "data/maps/SakuTown/scripts.pory"
	.string "I let the Pokémon League borrow my\n"
	.string "super-strong Pokémon to help build\l"
	.string "the new Pokémon refuges throughout\l"
	.string "the region.$"

SakuTown_EventScript_Karateka_Text_2:
# 170 "data/maps/SakuTown/scripts.pory"
	.string "Come on, Mama, Kuku! Daddy loves you!!$"

SakuTown_EventScript_Guard_Text_0:
# 196 "data/maps/SakuTown/scripts.pory"
	.string "Guard$"

SakuTown_EventScript_Guard_Text_1:
# 198 "data/maps/SakuTown/scripts.pory"
	.string "Damn, where did that Mareep come\n"
	.string "from?!$"

SakuTown_EventScript_Guard_Text_2:
# 205 "data/maps/SakuTown/scripts.pory"
	.string "One can never be too careful.\p"
	.string "The safety of the whole village rests\n"
	.string "on my shoulders.$"

SakuTown_EventScript_KuraGuard_Text_0:
# 219 "data/maps/SakuTown/scripts.pory"
	.string "Hah, got two of your Tauros in my\n"
	.string "herd!$"

SakuTown_EventScript_GuardStopsYou_Text_0:
# 246 "data/maps/SakuTown/scripts.pory"
	.string "Hey!$"

SakuTown_EventScript_GuardStopsYou_Text_1:
# 255 "data/maps/SakuTown/scripts.pory"
	.string "Are you trying to sneak in from Kura\n"
	.string "Village?\p"
	.string "…Oh, you're that traveler from before.\n"
	.string "You can go through.\p"
	.string "How was it? Awful, right? Welcome back\n"
	.string "to Saku Village!$"

SakuTown_EventScript_GuardStopsYou_Text_2:
# 264 "data/maps/SakuTown/scripts.pory"
	.string "Are you trying to sneak into Kura\n"
	.string "Village?\p"
	.string "…Oh, you're just a traveler. Nevermind\n"
	.string "then, you can go through.\p"
	.string "Though I wouldn't recommend visiting\n"
	.string "the next village, there's really\l"
	.string "nothing interesting there.$"

SakuTown_EventScript_TownSign_Text_0:
# 277 "data/maps/SakuTown/scripts.pory"
	.string "Saku Village\n"
	.string "“A village of tender flower petals.”$"

SakuTown_EventScript_TrainerTips_Text_0:
# 281 "data/maps/SakuTown/scripts.pory"
	.string "Did you know?\p"
	.string "Saku Village is in all ways superior to\n"
	.string "Kura Village!$"

SakuTown_EventScript_TrainerTips2_Text_0:
# 285 "data/maps/SakuTown/scripts.pory"
	.string "Did you know?\p"
	.string "The folks from Kura Village are a\n"
	.string "bunch of mean jerks!$"

SakuTown_EventScript_FloristSign_Text_0:
# 289 "data/maps/SakuTown/scripts.pory"
	.string "Humble Blossom\n"
	.string "Bonsai & flower shop$"

SakuTown_EventScript_BoardGame_Text_0:
# 295 "data/maps/SakuTown/scripts.pory"
	.string "They're playing Tauros Herder, a\n"
	.string "popular board game!$"

SakuTown_EventScript_Mart_Text_0:
# 304 "data/maps/SakuTown/scripts.pory"
	.string "Saleswoman$"

SakuTown_EventScript_Makuhita_Text_0:
# 328 "data/maps/SakuTown/scripts.pory"
	.string "Makuhita$"

SakuTown_EventScript_Makuhita_Text_1:
# 329 "data/maps/SakuTown/scripts.pory"
	.string "Kuhi!$"

SakuTown_Text_RivalDefeat::
# 101 "data/maps/SakuTown/scripts.pory"
	.string "Oh, wow, okay.$"

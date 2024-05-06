SakuTown_MapScripts::
# 6 "data/maps/SakuTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 19 "data/maps/SakuTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SakuTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 7 "data/maps/SakuTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 9 "data/maps/SakuTown/scripts.pory"
	compare VAR_RIVAL_ENCOUNTER_STATE, 1
	goto_if_eq SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 13 "data/maps/SakuTown/scripts.pory"
	goto_if_set FLAG_SAKU_KURA_REUNITED, SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	return

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 10 "data/maps/SakuTown/scripts.pory"
	clearflag FLAG_HIDE_RIVAL_SAKU
	goto SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 15 "data/maps/SakuTown/scripts.pory"
	setmetatile 19, 3, METATILE_SakuKura_BoardGame, TRUE
# 16 "data/maps/SakuTown/scripts.pory"
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_RIGHT
	return

SakuTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 20 "data/maps/SakuTown/scripts.pory"
	map_script_2 VAR_RIVAL_ENCOUNTER_STATE, 1, SakuTown_EventScript_Rival
	.2byte 0


SakuTown_EventScript_Rival::
# 26 "data/maps/SakuTown/scripts.pory"
	lock
# 28 "data/maps/SakuTown/scripts.pory"
	applymovement 10, SakuTown_Movement_WalkFastUp
# 29 "data/maps/SakuTown/scripts.pory"
	playse SE_PIN
# 30 "data/maps/SakuTown/scripts.pory"
	applymovement 10, Common_Movement_ExclamationMark
# 31 "data/maps/SakuTown/scripts.pory"
	delay 48
# 33 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Rival_Text_0
# 41 "data/maps/SakuTown/scripts.pory"
	call SakuTown_EventScript_RivalFight
# 43 "data/maps/SakuTown/scripts.pory"
	applymovement 10, SakuTown_Movement_WalkAway
# 44 "data/maps/SakuTown/scripts.pory"
	waitmovement 0
# 46 "data/maps/SakuTown/scripts.pory"
	removeobject 10
# 47 "data/maps/SakuTown/scripts.pory"
	setflag FLAG_HIDE_RIVAL_SAKU
# 49 "data/maps/SakuTown/scripts.pory"
	setvar VAR_RIVAL_ENCOUNTER_STATE, 2
# 51 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_RivalAtSakuWall::
# 56 "data/maps/SakuTown/scripts.pory"
	lock
# 57 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_RivalAtSakuWall_Text_0, MSGBOX_AUTOCLOSE
# 59 "data/maps/SakuTown/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 60 "data/maps/SakuTown/scripts.pory"
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
# 62 "data/maps/SakuTown/scripts.pory"
	addobject 10
# 63 "data/maps/SakuTown/scripts.pory"
	compare VAR_TEMP_2, 16
	goto_if_eq SakuTown_EventScript_RivalAtSakuWall_2
# 66 "data/maps/SakuTown/scripts.pory"
	setobjectxy 10, 17, 10
SakuTown_EventScript_RivalAtSakuWall_1:
# 68 "data/maps/SakuTown/scripts.pory"
	applymovement 10, SakuTown_Movement_WalkUp
# 69 "data/maps/SakuTown/scripts.pory"
	waitmovement 0
# 71 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_RivalAtSakuWall_Text_1
# 77 "data/maps/SakuTown/scripts.pory"
	call SakuTown_EventScript_RivalFight
# 80 "data/maps/SakuTown/scripts.pory"
	compare VAR_TEMP_2, 16
	goto_if_eq SakuTown_EventScript_RivalAtSakuWall_6
# 84 "data/maps/SakuTown/scripts.pory"
	applymovement 10, SakuTown_Movement_GoToKuraFromLeft
SakuTown_EventScript_RivalAtSakuWall_5:
# 86 "data/maps/SakuTown/scripts.pory"
	waitmovement 0
# 88 "data/maps/SakuTown/scripts.pory"
	removeobject 10
# 89 "data/maps/SakuTown/scripts.pory"
	setflag FLAG_HIDE_RIVAL_SAKU
# 91 "data/maps/SakuTown/scripts.pory"
	setvar VAR_RIVAL_ENCOUNTER_STATE, 2
# 93 "data/maps/SakuTown/scripts.pory"
	release
	return

SakuTown_EventScript_RivalAtSakuWall_2:
# 64 "data/maps/SakuTown/scripts.pory"
	setobjectxy 10, 16, 10
	goto SakuTown_EventScript_RivalAtSakuWall_1

SakuTown_EventScript_RivalAtSakuWall_6:
# 81 "data/maps/SakuTown/scripts.pory"
	applymovement 10, SakuTown_Movement_GoToKuraFromRight
	goto SakuTown_EventScript_RivalAtSakuWall_5


SakuTown_EventScript_RivalFight::
# 97 "data/maps/SakuTown/scripts.pory"
	switch VAR_STARTER_MON
# 98 "data/maps/SakuTown/scripts.pory"
	case SPECIES_ARON, SakuTown_EventScript_RivalFight_3
# 101 "data/maps/SakuTown/scripts.pory"
	case SPECIES_SPHEAL, SakuTown_EventScript_RivalFight_4
# 104 "data/maps/SakuTown/scripts.pory"
	case SPECIES_TRAPINCH, SakuTown_EventScript_RivalFight_5
SakuTown_EventScript_RivalFight_1:
# 109 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_RivalFight_Text_0
# 119 "data/maps/SakuTown/scripts.pory"
	closemessage
	return

SakuTown_EventScript_RivalFight_3:
# 99 "data/maps/SakuTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_SAKU_ARON, SakuTown_Text_RivalDefeat
	goto SakuTown_EventScript_RivalFight_1

SakuTown_EventScript_RivalFight_4:
# 102 "data/maps/SakuTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_SAKU_SPHEAL, SakuTown_Text_RivalDefeat
	goto SakuTown_EventScript_RivalFight_1

SakuTown_EventScript_RivalFight_5:
# 105 "data/maps/SakuTown/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_SAKU_TRAPINCH, SakuTown_Text_RivalDefeat
	goto SakuTown_EventScript_RivalFight_1


# 126 "data/maps/SakuTown/scripts.pory"
SakuTown_Movement_GoToKuraFromLeft:
# 127 "data/maps/SakuTown/scripts.pory"
	walk_left
# 128 "data/maps/SakuTown/scripts.pory"
	walk_up
# 128 "data/maps/SakuTown/scripts.pory"
	walk_up
# 128 "data/maps/SakuTown/scripts.pory"
	walk_up
# 128 "data/maps/SakuTown/scripts.pory"
	walk_up
# 128 "data/maps/SakuTown/scripts.pory"
	walk_up
	step_end

# 131 "data/maps/SakuTown/scripts.pory"
SakuTown_Movement_GoToKuraFromRight:
# 132 "data/maps/SakuTown/scripts.pory"
	walk_right
# 133 "data/maps/SakuTown/scripts.pory"
	walk_up
# 133 "data/maps/SakuTown/scripts.pory"
	walk_up
# 133 "data/maps/SakuTown/scripts.pory"
	walk_up
# 133 "data/maps/SakuTown/scripts.pory"
	walk_up
# 133 "data/maps/SakuTown/scripts.pory"
	walk_up
	step_end

# 136 "data/maps/SakuTown/scripts.pory"
SakuTown_Movement_WalkUp:
# 137 "data/maps/SakuTown/scripts.pory"
	walk_up
# 137 "data/maps/SakuTown/scripts.pory"
	walk_up
# 137 "data/maps/SakuTown/scripts.pory"
	walk_up
# 137 "data/maps/SakuTown/scripts.pory"
	walk_up
# 137 "data/maps/SakuTown/scripts.pory"
	walk_up
	step_end

# 140 "data/maps/SakuTown/scripts.pory"
SakuTown_Movement_WalkFastUp:
# 141 "data/maps/SakuTown/scripts.pory"
	walk_fast_up
	step_end

# 144 "data/maps/SakuTown/scripts.pory"
SakuTown_Movement_WalkAway:
# 145 "data/maps/SakuTown/scripts.pory"
	walk_fast_down
# 145 "data/maps/SakuTown/scripts.pory"
	walk_fast_down
# 145 "data/maps/SakuTown/scripts.pory"
	walk_fast_down
# 145 "data/maps/SakuTown/scripts.pory"
	walk_fast_down
# 145 "data/maps/SakuTown/scripts.pory"
	walk_fast_down
# 145 "data/maps/SakuTown/scripts.pory"
	walk_fast_down
	step_end

SakuTown_EventScript_Farmer::
# 149 "data/maps/SakuTown/scripts.pory"
	lock
# 150 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 151 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Farmer_Text_0
# 154 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Farmer2::
# 158 "data/maps/SakuTown/scripts.pory"
	lock
# 159 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Farmer2_Text_0
# 163 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Woman::
# 167 "data/maps/SakuTown/scripts.pory"
	lock
# 168 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 169 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Woman_Text_0
# 173 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Karateka::
# 177 "data/maps/SakuTown/scripts.pory"
	lock
# 178 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 179 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Karateka_Text_0
# 182 "data/maps/SakuTown/scripts.pory"
	applymovement 6, Common_Movement_FaceUp
# 183 "data/maps/SakuTown/scripts.pory"
	waitmovement 0
# 184 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Karateka_Text_1
# 187 "data/maps/SakuTown/scripts.pory"
	closemessage
# 188 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Guard::
# 192 "data/maps/SakuTown/scripts.pory"
	lock
# 193 "data/maps/SakuTown/scripts.pory"
	goto_if_set FLAG_SAKU_KURA_REUNITED, SakuTown_EventScript_Guard_2
# 198 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 199 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Woman_Text_0
SakuTown_EventScript_Guard_1:
# 204 "data/maps/SakuTown/scripts.pory"
	release
	return

SakuTown_EventScript_Guard_2:
# 194 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Guard_Text_0
	goto SakuTown_EventScript_Guard_1


SakuTown_EventScript_KuraGuard::
# 208 "data/maps/SakuTown/scripts.pory"
	lock
# 209 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_KuraGuard_Text_0
# 212 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_GuardSeesYou::
# 216 "data/maps/SakuTown/scripts.pory"
	lock
# 218 "data/maps/SakuTown/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 221 "data/maps/SakuTown/scripts.pory"
	compare VAR_SAKU_KURA_VILLAGES_STATE, 0
	goto_if_eq SakuTown_EventScript_GuardSeesYou_2
# 224 "data/maps/SakuTown/scripts.pory"
	compare VAR_SAKU_KURA_VILLAGES_STATE, 1
	goto_if_eq SakuTown_EventScript_GuardSeesYou_4
SakuTown_EventScript_GuardSeesYou_1:
# 228 "data/maps/SakuTown/scripts.pory"
	release
	return

SakuTown_EventScript_GuardSeesYou_2:
# 222 "data/maps/SakuTown/scripts.pory"
	call SakuTown_EventScript_GuardStopsYou
	goto SakuTown_EventScript_GuardSeesYou_1

SakuTown_EventScript_GuardSeesYou_3:
# 225 "data/maps/SakuTown/scripts.pory"
	call SakuTown_EventScript_GuardStopsYou
	goto SakuTown_EventScript_GuardSeesYou_1

SakuTown_EventScript_GuardSeesYou_4:
# 224 "data/maps/SakuTown/scripts.pory"
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq SakuTown_EventScript_GuardSeesYou_3
	goto SakuTown_EventScript_GuardSeesYou_1


SakuTown_EventScript_GuardStopsYou::
# 232 "data/maps/SakuTown/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 233 "data/maps/SakuTown/scripts.pory"
	applymovement 8, Common_Movement_FaceLeft
# 234 "data/maps/SakuTown/scripts.pory"
	waitmovement 8
# 235 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_GuardStopsYou_Text_0
# 236 "data/maps/SakuTown/scripts.pory"
	closemessage
# 237 "data/maps/SakuTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 238 "data/maps/SakuTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 240 "data/maps/SakuTown/scripts.pory"
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq SakuTown_EventScript_GuardStopsYou_2
# 247 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_GuardStopsYou_Text_2
SakuTown_EventScript_GuardStopsYou_1:
# 254 "data/maps/SakuTown/scripts.pory"
	applymovement 8, Common_Movement_FaceDown
# 256 "data/maps/SakuTown/scripts.pory"
	addvar VAR_SAKU_KURA_VILLAGES_STATE, 1
	return

SakuTown_EventScript_GuardStopsYou_2:
# 241 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_GuardStopsYou_Text_1
	goto SakuTown_EventScript_GuardStopsYou_1


SakuTown_EventScript_TownSign::
# 260 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_TrainerTips::
# 264 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_TrainerTips_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_TrainerTips2::
# 268 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_TrainerTips2_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_FloristSign::
# 272 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_FloristSign_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_BoardGame::
# 276 "data/maps/SakuTown/scripts.pory"
	goto_if_set FLAG_SAKU_KURA_REUNITED, SakuTown_EventScript_BoardGame_1
	return

SakuTown_EventScript_BoardGame_1:
# 277 "data/maps/SakuTown/scripts.pory"
	lock
# 278 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_BoardGame_Text_0, MSGBOX_DEFAULT
# 279 "data/maps/SakuTown/scripts.pory"
	closemessage
# 280 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Mart::
# 285 "data/maps/SakuTown/scripts.pory"
	lock
# 286 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 287 "data/maps/SakuTown/scripts.pory"
	message gText_HowMayIServeYou
# 288 "data/maps/SakuTown/scripts.pory"
	waitmessage
# 289 "data/maps/SakuTown/scripts.pory"
	pokemart SakuTown_Mart
# 290 "data/maps/SakuTown/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 291 "data/maps/SakuTown/scripts.pory"
	release
	return


	.align 2
# 294 "data/maps/SakuTown/scripts.pory"
SakuTown_Mart:
# 295 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_POKE_BALL
# 296 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_BERRY_JUICE
# 297 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 298 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 299 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_AWAKENING
# 300 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 301 "data/maps/SakuTown/scripts.pory"
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

SakuTown_EventScript_Makuhita::
# 305 "data/maps/SakuTown/scripts.pory"
	lock
# 306 "data/maps/SakuTown/scripts.pory"
	faceplayer
# 307 "data/maps/SakuTown/scripts.pory"
	waitse
# 308 "data/maps/SakuTown/scripts.pory"
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
# 309 "data/maps/SakuTown/scripts.pory"
	msgbox SakuTown_EventScript_Makuhita_Text_0
# 310 "data/maps/SakuTown/scripts.pory"
	waitmoncry
# 311 "data/maps/SakuTown/scripts.pory"
	release
	return


SakuTown_EventScript_Rival_Text_0:
# 34 "data/maps/SakuTown/scripts.pory"
	.string "Excuse me-\p"
	.string "… …\p"
	.string "Hey! {PLAYER}!! I was wondering if\n"
	.string "you'd already reached Saku Village by\l"
	.string "now.\p"
	.string "Have you caught any Pokémon on your\n"
	.string "way here?\p"
	.string "Me? Oh, I can show you my Pokémon\n"
	.string "alright!$"

SakuTown_EventScript_RivalAtSakuWall_Text_0:
# 57 "data/maps/SakuTown/scripts.pory"
	.string "Wait up, {PLAYER}!$"

SakuTown_EventScript_RivalAtSakuWall_Text_1:
# 72 "data/maps/SakuTown/scripts.pory"
	.string "I was wondering if you'd already\n"
	.string "reached Saku Village by now. Looks like\l"
	.string "we almost missed each other!\p"
	.string "Have you caught any Pokémon on your\n"
	.string "way here?\p"
	.string "Me? Oh, I can show you my Pokémon\n"
	.string "alright!$"

SakuTown_EventScript_RivalFight_Text_0:
# 110 "data/maps/SakuTown/scripts.pory"
	.string "Okay, I… I didn't think you'd go that\n"
	.string "hard, honestly! Hahaha…\p"
	.string "Clearly I underestimated you. That's\n"
	.string "alright. I won't make that mistake next\l"
	.string "time!\p"
	.string "I can see your Pokémon are really\n"
	.string "growing to like you, it's great!\p"
	.string "You definitely stand a chance against\n"
	.string "the Dojo that's in the next village.\p"
	.string "Me? Actually, I just fought the Dojo's\n"
	.string "master and gotten a token from her!\p"
	.string "You'll have to hurry up if you wanna\n"
	.string "catch up!\p"
	.string "Well, it was good to see you. Until next\n"
	.string "time then.\p"
	.string "I bet you I'll get to Silveridge first!$"

SakuTown_EventScript_Farmer_Text_0:
# 152 "data/maps/SakuTown/scripts.pory"
	.string "We're cultivatin' Ryss berries. Saku\n"
	.string "Village exports its berries to many\l"
	.string "towns.$"

SakuTown_EventScript_Farmer2_Text_0:
# 160 "data/maps/SakuTown/scripts.pory"
	.string "Whew…\p"
	.string "Working in the fields sure is tiring…$"

SakuTown_EventScript_Woman_Text_0:
# 170 "data/maps/SakuTown/scripts.pory"
	.string "Those thugs in Kura Village may have\n"
	.string "their own dojo, but their town is\l"
	.string "nothing but an ugly pile of rocks!\p"
	.string "They don't even have a Pokémon refuge!$"

SakuTown_EventScript_Karateka_Text_0:
# 180 "data/maps/SakuTown/scripts.pory"
	.string "I let the Pokémon League borrow my\n"
	.string "super-strong Pokémon to help build the\l"
	.string "new Pokémon refuges throughout the\l"
	.string "region.$"

SakuTown_EventScript_Karateka_Text_1:
# 185 "data/maps/SakuTown/scripts.pory"
	.string "Come on, Mama, Kuku! Daddy loves you!!$"

SakuTown_EventScript_Guard_Text_0:
# 195 "data/maps/SakuTown/scripts.pory"
	.string "Damn, where did that Mareep come from?!$"

SakuTown_EventScript_KuraGuard_Text_0:
# 210 "data/maps/SakuTown/scripts.pory"
	.string "Hah, got two of your Tauros in my herd!$"

SakuTown_EventScript_GuardStopsYou_Text_0:
# 235 "data/maps/SakuTown/scripts.pory"
	.string "Hey!$"

SakuTown_EventScript_GuardStopsYou_Text_1:
# 242 "data/maps/SakuTown/scripts.pory"
	.string "Are you trying to sneak in from Kura\n"
	.string "Village?\p"
	.string "…Oh, you're that traveler from before.\n"
	.string "You can go through.\p"
	.string "How was it? Awful, right? Welcome back\n"
	.string "to Saku Village!$"

SakuTown_EventScript_GuardStopsYou_Text_2:
# 248 "data/maps/SakuTown/scripts.pory"
	.string "Are you trying to sneak into Kura\n"
	.string "Village?\p"
	.string "…Oh, you're just a traveler. Nevermind\n"
	.string "then, you can go through.\p"
	.string "Though I wouldn't recommend visiting\n"
	.string "the next village, there's really nothing\l"
	.string "interesting there.$"

SakuTown_EventScript_TownSign_Text_0:
# 260 "data/maps/SakuTown/scripts.pory"
	.string "Saku Village\n"
	.string "“A village of tender flower petals.”$"

SakuTown_EventScript_TrainerTips_Text_0:
# 264 "data/maps/SakuTown/scripts.pory"
	.string "Did you know? Saku Village is in all ways\n"
	.string "superior to Kura Village!$"

SakuTown_EventScript_TrainerTips2_Text_0:
# 268 "data/maps/SakuTown/scripts.pory"
	.string "Did you know? The folks from Kura\n"
	.string "Village are a bunch of mean jerks!$"

SakuTown_EventScript_FloristSign_Text_0:
# 272 "data/maps/SakuTown/scripts.pory"
	.string "Humble Blossom\n"
	.string "Bonsai & flower shop$"

SakuTown_EventScript_BoardGame_Text_0:
# 278 "data/maps/SakuTown/scripts.pory"
	.string "They're playing Tauros Herder, a popular\n"
	.string "board game!$"

SakuTown_EventScript_Makuhita_Text_0:
# 309 "data/maps/SakuTown/scripts.pory"
	.string "Kuhi!$"

SakuTown_Text_RivalDefeat::
# 122 "data/maps/SakuTown/scripts.pory"
	.string "Oh, wow, okay.$"

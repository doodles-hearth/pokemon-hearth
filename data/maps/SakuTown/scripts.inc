SakuTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Common_EventScript_SetupRivalGfxId
	goto_if_set FLAG_SAKU_KURA_REUNITED, SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 4
	goto_if_eq SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	returnqueststate QUEST_KURALOVERS
	copyvar VAR_TEMP_0, VAR_RESULT
	returnqueststate QUEST_KURAESPEON
	copyvar VAR_TEMP_1, VAR_RESULT
	returnqueststate QUEST_KURASCYTHER
	copyvar VAR_TEMP_2, VAR_RESULT
	compare VAR_TEMP_0, 4
	goto_if_eq SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11
SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_9:
	compare VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 7
	goto_if_eq SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
	return

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setmetatile 19, 2, METATILE_SakuKura_BoardGame, TRUE
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_RIGHT
	goto SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	goto SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7:
	setflag FLAG_HIDE_SAKU_FARMERS
	setvar VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 1
	return

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
	clearflag FLAG_HIDE_SAKU_FARMERS
	return

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_10:
	compare VAR_TEMP_2, 1
	goto_if_eq SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14
	goto SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_9

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11:
	compare VAR_TEMP_1, 4
	goto_if_eq SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_10
	goto SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_9

SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14:
	compare VAR_SAKU_KURA_QUEST_SCYTHER_STATE, 0
	goto_if_eq SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7
	goto SakuTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_9

SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD:
	setflag FLAG_TEMP_1
	gettimeofday
	switch VAR_RESULT
	case TIME_DEAD_NIGHT, SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD_2
	case TIME_EARLY_MORNING, SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD_3
	case TIME_MORNING, SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD_3
	case TIME_LUNCHTIME, SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD_3
	case TIME_AFTERNOON, SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD_3
	case TIME_EVENING, SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD_3
	case TIME_NIGHT, SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD_3
SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD_3:
	end

SakuTown_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	setmetatile 35, 31, METATILE_SakuKura_ClosedDoorBottom, TRUE
	setmetatile 18, 32, METATILE_SakuKura_ClosedDoorTop, TRUE
	setmetatile 18, 33, METATILE_SakuKura_ClosedDoorBottom, TRUE
	return


SakuTown_EventScript_RivalAtSakuWall::
	lock
	speakername SakuTown_EventScript_RivalAtSakuWall_Text_0
	msgbox SakuTown_EventScript_RivalAtSakuWall_Text_1
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
	clearflag FLAG_TEMP_1
	addobject 10
	compare VAR_TEMP_2, 16
	goto_if_eq SakuTown_EventScript_RivalAtSakuWall_2
	setobjectxy 10, 17, 10
SakuTown_EventScript_RivalAtSakuWall_1:
	applymovement 10, SakuTown_EventScript_RivalAtSakuWall_Movement_0
	waitmovement 0
	speakername SakuTown_EventScript_RivalAtSakuWall_Text_2
	msgbox SakuTown_EventScript_RivalAtSakuWall_Text_3
	switch VAR_STARTER_MON
	case SPECIES_SNIVY, SakuTown_EventScript_RivalAtSakuWall_7
	case SPECIES_FROAKIE, SakuTown_EventScript_RivalAtSakuWall_8
	case SPECIES_CYNDAQUIL, SakuTown_EventScript_RivalAtSakuWall_9
SakuTown_EventScript_RivalAtSakuWall_5:
	speakername SakuTown_EventScript_RivalAtSakuWall_Text_2
	msgbox SakuTown_EventScript_RivalAtSakuWall_Text_4
	closemessage
	compare VAR_TEMP_2, 16
	goto_if_eq SakuTown_EventScript_RivalAtSakuWall_11
	applymovement 10, SakuTown_EventScript_RivalAtSakuWall_Movement_2
SakuTown_EventScript_RivalAtSakuWall_10:
	waitmovement 0
	removeobject 10
	setflag FLAG_TEMP_1
	setvar VAR_RIVAL_ENCOUNTER_STATE, 1
	release
	return

SakuTown_EventScript_RivalAtSakuWall_2:
	setobjectxy 10, 16, 10
	goto SakuTown_EventScript_RivalAtSakuWall_1

SakuTown_EventScript_RivalAtSakuWall_7:
	trainerbattle_no_intro TRAINER_RIVAL_SAKU_SNIVY, SakuTown_Text_RivalDefeat
	goto SakuTown_EventScript_RivalAtSakuWall_5

SakuTown_EventScript_RivalAtSakuWall_8:
	trainerbattle_no_intro TRAINER_RIVAL_SAKU_FROAKIE, SakuTown_Text_RivalDefeat
	goto SakuTown_EventScript_RivalAtSakuWall_5

SakuTown_EventScript_RivalAtSakuWall_9:
	trainerbattle_no_intro TRAINER_RIVAL_SAKU_CYNDAQUIL, SakuTown_Text_RivalDefeat
	goto SakuTown_EventScript_RivalAtSakuWall_5

SakuTown_EventScript_RivalAtSakuWall_11:
	applymovement 10, SakuTown_EventScript_RivalAtSakuWall_Movement_1
	goto SakuTown_EventScript_RivalAtSakuWall_10


SakuTown_EventScript_Farmer::
	lock
	faceplayer
	speakername SakuTown_EventScript_Farmer_Text_0
	returnqueststate QUEST_KURASCYTHER
	compare VAR_RESULT, 3
	goto_if_eq SakuTown_EventScript_Farmer_2
	msgbox SakuTown_EventScript_Farmer_Text_2
SakuTown_EventScript_Farmer_1:
	release
	return

SakuTown_EventScript_Farmer_2:
	msgbox SakuTown_EventScript_Farmer_Text_1
	giveitem ITEM_CHERI_BERRY, 20
	completequest QUEST_KURASCYTHER
	goto SakuTown_EventScript_Farmer_1


SakuTown_EventScript_Farmer2::
	lock
	speakername SakuTown_EventScript_Farmer_Text_0
	msgbox SakuTown_EventScript_Farmer2_Text_0
	release
	return


SakuTown_EventScript_Scyther::
	lock
	faceplayer
	setseenmon SPECIES_SCYTHER
	playmoncry SPECIES_SCYTHER, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_SCYTHER
	msgbox SakuTown_EventScript_Scyther_Text_0
	waitmoncry
	closemessage
	release
	return


SakuTown_EventScript_Woman::
	lock
	faceplayer
	speakername SakuTown_EventScript_Woman_Text_0
	msgbox SakuTown_EventScript_Woman_Text_1
	release
	return


SakuTown_EventScript_Karateka::
	lock
	faceplayer
	speakername SakuTown_EventScript_Karateka_Text_0
	msgbox SakuTown_EventScript_Karateka_Text_1
	closemessage
	playse SE_LEDGE
	applymovement 6, SakuTown_EventScript_Karateka_Movement_0
	waitmovement 0
	waitse
	speakername SakuTown_EventScript_Karateka_Text_0
	msgbox SakuTown_EventScript_Karateka_Text_2
	closemessage
	applymovement 1, Common_Movement_FaceDown
	applymovement 2, Common_Movement_FaceDown
	waitmovement 1
	waitmovement 2
	delay 24
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
	applymovement 1, SakuTown_EventScript_Karateka_Movement_1
	waitmovement 1
	waitmoncry
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
	applymovement 2, SakuTown_EventScript_Karateka_Movement_1
	waitmovement 2
	waitmoncry
	setseenmon SPECIES_MAKUHITA
	release
	return


SakuTown_EventScript_Guard::
	lock
	goto_if_set FLAG_SAKU_KURA_REUNITED, SakuTown_EventScript_Guard_2
	faceplayer
	speakername SakuTown_EventScript_Guard_Text_0
	msgbox SakuTown_EventScript_Guard_Text_2
	closemessage
	applymovement 8, Common_Movement_FaceOriginalDirection
	waitmovement 0
SakuTown_EventScript_Guard_1:
	release
	return

SakuTown_EventScript_Guard_2:
	speakername SakuTown_EventScript_Guard_Text_0
	msgbox SakuTown_EventScript_Guard_Text_1
	closemessage
	goto SakuTown_EventScript_Guard_1


SakuTown_EventScript_KuraGuard::
	lock
	speakername SakuTown_EventScript_Guard_Text_0
	msgbox SakuTown_EventScript_KuraGuard_Text_0
	closemessage
	release
	return


SakuTown_EventScript_GuardSeesYou::
	lock
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_SAKU_KURA_VILLAGES_STATE, 0
	goto_if_eq SakuTown_EventScript_GuardSeesYou_2
	compare VAR_SAKU_KURA_VILLAGES_STATE, 2
	goto_if_eq SakuTown_EventScript_GuardSeesYou_4
SakuTown_EventScript_GuardSeesYou_1:
	release
	return

SakuTown_EventScript_GuardSeesYou_2:
	call SakuTown_EventScript_GuardStopsYou
	goto SakuTown_EventScript_GuardSeesYou_1

SakuTown_EventScript_GuardSeesYou_3:
	call SakuTown_EventScript_GuardStopsYou
	goto SakuTown_EventScript_GuardSeesYou_1

SakuTown_EventScript_GuardSeesYou_4:
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq SakuTown_EventScript_GuardSeesYou_3
	goto SakuTown_EventScript_GuardSeesYou_1


SakuTown_EventScript_GuardStopsYou::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	applymovement 8, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 8
	speakername SakuTown_EventScript_Guard_Text_0
	msgbox SakuTown_EventScript_GuardStopsYou_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 20
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq SakuTown_EventScript_GuardStopsYou_2
	speakername SakuTown_EventScript_Guard_Text_0
	msgbox SakuTown_EventScript_GuardStopsYou_Text_2
	closemessage
	setvar VAR_SAKU_KURA_VILLAGES_STATE, 1
SakuTown_EventScript_GuardStopsYou_1:
	applymovement 8, Common_Movement_FaceDown
	return

SakuTown_EventScript_GuardStopsYou_2:
	speakername SakuTown_EventScript_Guard_Text_0
	msgbox SakuTown_EventScript_GuardStopsYou_Text_1
	closemessage
	setvar VAR_SAKU_KURA_VILLAGES_STATE, 3
	goto SakuTown_EventScript_GuardStopsYou_1


SakuTown_EventScript_TownSign::
	msgbox SakuTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_TrainerTips::
	msgbox SakuTown_EventScript_TrainerTips_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_TrainerTips2::
	msgbox SakuTown_EventScript_TrainerTips2_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_FloristSign::
	msgbox SakuTown_EventScript_FloristSign_Text_0, MSGBOX_SIGN
	return


SakuTown_EventScript_BoardGame::
	goto_if_set FLAG_SAKU_KURA_REUNITED, SakuTown_EventScript_BoardGame_1
	return

SakuTown_EventScript_BoardGame_1:
	lock
	msgbox SakuTown_EventScript_BoardGame_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	return


SakuTown_EventScript_Mart::
	lock
	faceplayer
	speakername SakuTown_EventScript_Mart_Text_0
	message gText_HowMayIServeYou
	waitmessage
	pokemart SakuTown_Mart
	speakername SakuTown_EventScript_Mart_Text_0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	return


	.align 2
SakuTown_Mart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_OINTMENT
	.2byte ITEM_REVIVAL_POWDER
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_NONE

SakuTown_EventScript_Makuhita::
	lock
	faceplayer
	waitse
	setseenmon SPECIES_MAKUHITA
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_MAKUHITA
	msgbox SakuTown_EventScript_Makuhita_Text_0
	waitmoncry
	release
	return


SakuTown_EventScript_MonHues::
	lock
	faceplayer
	speakername SakuTown_EventScript_Karateka_Text_0
	msgbox SakuTown_EventScript_MonHues_Text_0
	closemessage
	release
	return


SakuTown_EventScript_Cherrim::
	lock
	faceplayer
	setseenmon SPECIES_CHERRIM
	playmoncry SPECIES_CHERRIM, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_CHERRIM
	msgbox SakuTown_EventScript_Cherrim_Text_0
	waitmoncry
	release
	return


SakuTown_EventScript_TamaArgument::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, SakuTown_EventScript_TamaArgument_Movement_0
	waitmovement 0
	playse SE_PIN
	speakername SakuTown_EventScript_RivalAtSakuWall_Text_0
	msgbox SakuTown_EventScript_TamaArgument_Text_0
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SakuTown_EventScript_TamaArgument_Movement_1
	waitmovement 0
	speakername SakuTown_EventScript_TamaArgument_Text_1
	msgbox SakuTown_EventScript_TamaArgument_Text_2
	waitmessage
	closemessage
	return


SakuTown_EventScript_RivalAtSakuWall_Movement_0:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SakuTown_EventScript_RivalAtSakuWall_Movement_1:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SakuTown_EventScript_RivalAtSakuWall_Movement_2:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SakuTown_EventScript_Karateka_Movement_0:
	jump_in_place_up
	step_end

SakuTown_EventScript_Karateka_Movement_1:
	jump_in_place_down
	step_end

SakuTown_EventScript_TamaArgument_Movement_0:
	emote_exclamation_mark
	step_end

SakuTown_EventScript_TamaArgument_Movement_1:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

SakuTown_EventScript_RivalAtSakuWall_Text_0:
	.string "???$"

SakuTown_EventScript_RivalAtSakuWall_Text_1:
	.string "Wait up, {PLAYER}!$"

SakuTown_EventScript_RivalAtSakuWall_Text_2:
	.string "Natsuki$"

SakuTown_EventScript_RivalAtSakuWall_Text_3:
	.string "I was wondering if you'd already\n"
	.string "reached Saku Village by now. Looks\l"
	.string "like we almost missed each other!\p"
	.string "I saw several patrolling Samurai on my\n"
	.string "way here. They look so cool, no wonder\l"
	.string "they're so admired!\p"
	.string "Oh, {PLAYER}, have you caught any\n"
	.string "Pokémon on your way here?\p"
	.string "Me?\n"
	.string "Boy, I'm so glad you asked…\p"
	.string "Let me show you!$"

SakuTown_EventScript_RivalAtSakuWall_Text_4:
	.string "Woah! I… I didn't think you'd go that\n"
	.string "hard, honestly!\p"
	.string "Clearly I underestimated you. That's\n"
	.string "alright. I won't make that mistake\l"
	.string "next time!\p"
	.string "I can see your Pokémon are really\n"
	.string "growing to like you, it's great!\p"
	.string "Are you doing the Dojo challenge?\n"
	.string "You might just stand a chance\l"
	.string "against the Dojo that's in the next\l"
	.string "village!\p"
	.string "Me? Actually, I just got my first\n"
	.string "official Token!\p"
	.string "You'll have to hurry if you wanna\n"
	.string "catch up!\p"
	.string "It's fun to run into each other like\n"
	.string "this. Until next time then.\p"
	.string "I bet you I'll get to Silveridge first!\p"
	.string "See you later, Feraligatr!$"

SakuTown_EventScript_Farmer_Text_0:
	.string "Farmer$"

SakuTown_EventScript_Farmer_Text_1:
	.string "Weilder! It's you! I can't thank ya\n"
	.string "enough for helping us heal our girl.\p"
	.string "I've been doin' a lot of thinkin' too,\n"
	.string "after you told us the one who helped\l"
	.string "'er get better was someone from Kura.\l"
	.string "That ain't here nor there though. As\l"
	.string "thanks, ya can have these.$"

SakuTown_EventScript_Farmer_Text_2:
	.string "We're growin' Cheri berries. Saku\n"
	.string "Village exports its berries to many\l"
	.string "towns.$"

SakuTown_EventScript_Farmer2_Text_0:
	.string "Whew…\p"
	.string "Working in the fields sure is tiring…$"

SakuTown_EventScript_Scyther_Text_0:
	.string "Gyooo!$"

SakuTown_EventScript_Woman_Text_0:
	.string "Woman$"

SakuTown_EventScript_Woman_Text_1:
	.string "Those thugs in Kura Village may have\n"
	.string "their own Dojo, but their town is\l"
	.string "nothing but an ugly pile of rocks!\p"
	.string "They don't even have a Pokémon\n"
	.string "refuge!$"

SakuTown_EventScript_Karateka_Text_0:
	.string "Man$"

SakuTown_EventScript_Karateka_Text_1:
	.string "I let the Toku Council borrow my\n"
	.string "super-strong Pokémon to help build\l"
	.string "the new Pokémon refuges throughout\l"
	.string "the region.$"

SakuTown_EventScript_Karateka_Text_2:
	.string "Come on, Mama, Kuku! Daddy loves you!!$"

SakuTown_EventScript_Guard_Text_0:
	.string "Guard$"

SakuTown_EventScript_Guard_Text_1:
	.string "Damn, where did that Mareep come\n"
	.string "from?!$"

SakuTown_EventScript_Guard_Text_2:
	.string "One can never be too careful.\p"
	.string "The safety of the whole village rests\n"
	.string "on my shoulders.$"

SakuTown_EventScript_KuraGuard_Text_0:
	.string "Hah, got two of your Tauros in my\n"
	.string "herd!$"

SakuTown_EventScript_GuardStopsYou_Text_0:
	.string "Hey!$"

SakuTown_EventScript_GuardStopsYou_Text_1:
	.string "Are you trying to sneak in from Kura\n"
	.string "Village?\p"
	.string "…Oh, you're that traveler from before.\n"
	.string "You can go through.\p"
	.string "How was it? Awful, right? Welcome back\n"
	.string "to Saku Village!$"

SakuTown_EventScript_GuardStopsYou_Text_2:
	.string "Are you trying to sneak into Kura\n"
	.string "Village?\p"
	.string "…Oh, you're just a traveler. Nevermind\n"
	.string "then, you can go through.\p"
	.string "Though I wouldn't recommend visiting\n"
	.string "the next village, there's really\l"
	.string "nothing interesting there.$"

SakuTown_EventScript_TownSign_Text_0:
	.string "Saku Village\n"
	.string "“A village of tender flower petals.”$"

SakuTown_EventScript_TrainerTips_Text_0:
	.string "Did you know?\p"
	.string "Saku Village is in all ways superior to\n"
	.string "Kura Village!$"

SakuTown_EventScript_TrainerTips2_Text_0:
	.string "Did you know?\p"
	.string "The folks from Kura Village are a\n"
	.string "bunch of mean jerks!$"

SakuTown_EventScript_FloristSign_Text_0:
	.string "Humble Blossom\n"
	.string "Bonsai & flower shop$"

SakuTown_EventScript_BoardGame_Text_0:
	.string "They're playing Tauros Herder, a\n"
	.string "popular board game!$"

SakuTown_EventScript_Mart_Text_0:
	.string "Shopkeeper$"

SakuTown_EventScript_Makuhita_Text_0:
	.string "Kuhi!$"

SakuTown_EventScript_MonHues_Text_0:
	.string "Have you ever paid close attention to\n"
	.string "the fur and feather colors of the wild\l"
	.string "Pokémon?\p"
	.string "They may all look the same at first…\n"
	.string "But each one has its own totally\l"
	.string "unique colors!\p"
	.string "Doesn't noticing that make your heart\n"
	.string "sing?$"

SakuTown_EventScript_Cherrim_Text_0:
	.string "Weee!$"

SakuTown_EventScript_TamaArgument_Text_0:
	.string "NO! I forbid you from going!$"

SakuTown_EventScript_TamaArgument_Text_1:
	.string "Tama$"

SakuTown_EventScript_TamaArgument_Text_2:
	.string "The love of my life is waiting for me\n"
	.string "on the other side! You can't do this\l"
	.string "to me!$"

SakuTown_Text_RivalDefeat::
	.string "Oh, wow!$"

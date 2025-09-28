KuraTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KuraTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, KuraTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

KuraTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_KURA_TOWN
	returnqueststate QUEST_SAKURALOVERS
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 5
	goto_if_lt KuraTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	compare VAR_RESULT, 3
	goto_if_ge KuraTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 5
	goto_if_ge KuraTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
KuraTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	compare VAR_DECAY_BEACHBOUND_ROUTE, 4
	goto_if_ne KuraTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_9
KuraTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
	goto_if_unset FLAG_BADGE01_GET, KuraTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11
	return

KuraTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setflag FLAG_HIDE_DEADNIGHT_ASHII
	goto KuraTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

KuraTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
	clearflag FLAG_HIDE_DEADNIGHT_ASHII
	goto KuraTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

KuraTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_9:
	setflag FLAG_TEMP_1
	goto KuraTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8

KuraTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11:
	setflag FLAG_TEMP_2
	return

KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_KURA_DOJO_CLOSED, KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_2
KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	gettimeofday
	switch VAR_0x8000
	case TIME_DEAD_NIGHT, KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_5
	case TIME_EARLY_MORNING, KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_6
	case TIME_MORNING, KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_6
	case TIME_LUNCHTIME, KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_6
	case TIME_AFTERNOON, KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_6
	case TIME_EVENING, KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_6
	case TIME_NIGHT, KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_6
KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_6:
	end

KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	setmetatile 40, 16, METATILE_SakuKura_ClosedDojoDoor, TRUE
	goto KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_1

KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_5:
	setmetatile 18, 6, METATILE_SakuKura_ClosedDoorTop, TRUE
	setmetatile 18, 7, METATILE_SakuKura_ClosedDoorBottom, TRUE
	return

KuraTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 5, KuraTown_EventScript_AnxiousAshii
	map_script_2 VAR_DECAY_BEACHBOUND_ROUTE, 4, KuraTown_EventScript_PostDecayNatsukiHariko
	.2byte 0


KuraTown_EventScript_GuardStopsYou::
	lockall
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 14
	goto_if_le KuraTown_EventScript_GuardStopsYou_2
	applymovement 2, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox KuraTown_EventScript_GuardStopsYou_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
KuraTown_EventScript_GuardStopsYou_1:
	delay 20
	compare VAR_SAKU_KURA_VILLAGES_STATE, 1
	goto_if_eq KuraTown_EventScript_GuardStopsYou_6
	compare VAR_SAKU_KURA_VILLAGES_STATE, 2
	goto_if_eq KuraTown_EventScript_GuardStopsYou_7
KuraTown_EventScript_GuardStopsYou_5:
	releaseall
	return

KuraTown_EventScript_GuardStopsYou_2:
	applymovement 2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox KuraTown_EventScript_GuardStopsYou_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	goto KuraTown_EventScript_GuardStopsYou_1

KuraTown_EventScript_GuardStopsYou_6:
	msgbox KuraTown_EventScript_GuardStopsYou_Text_1
	closemessage
	setvar VAR_SAKU_KURA_VILLAGES_STATE, 2
	goto KuraTown_EventScript_GuardStopsYou_5

KuraTown_EventScript_GuardStopsYou_7:
	msgbox KuraTown_EventScript_GuardStopsYou_Text_2
	closemessage
	setvar VAR_SAKU_KURA_VILLAGES_STATE, 3
	goto KuraTown_EventScript_GuardStopsYou_5


KuraTown_EventScript_DojoChallenger::
	lock
	faceplayer
	goto_if_set FLAG_KURA_DOJO_CLOSED, KuraTown_EventScript_DojoChallenger_2
	setspeaker KuraTown_EventScript_DojoChallenger_Text_2
	msgbox KuraTown_EventScript_DojoChallenger_Text_3
	applymovement VAR_LAST_TALKED, KuraTown_EventScript_DojoChallenger_Movement_1
	msgbox KuraTown_EventScript_DojoChallenger_Text_4
KuraTown_EventScript_DojoChallenger_1:
	closemessage
	release
	return

KuraTown_EventScript_DojoChallenger_2:
	applymovement VAR_LAST_TALKED, KuraTown_EventScript_DojoChallenger_Movement_0
	setspeaker KuraTown_EventScript_DojoChallenger_Text_0
	msgbox KuraTown_EventScript_DojoChallenger_Text_1
	goto KuraTown_EventScript_DojoChallenger_1


KuraTown_EventScript_Farmer::
	lock
	faceplayer
	setspeaker KuraTown_EventScript_Farmer_Text_0
	msgbox KuraTown_EventScript_Farmer_Text_1
	closemessage
	applymovement VAR_LAST_TALKED, KuraTown_EventScript_Farmer_Movement_0
	waitmovement 0
	setspeaker KuraTown_EventScript_Farmer_Text_0
	msgbox KuraTown_EventScript_Farmer_Text_2
	release
	return


KuraTown_EventScript_SilkScarf::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, KuraTown_EventScript_SilkScarf_2
	setspeaker KuraTown_EventScript_SilkScarf_Text_0
	msgbox KuraTown_EventScript_SilkScarf_Text_2
	applymovement VAR_LAST_TALKED, KuraTown_EventScript_DojoChallenger_Movement_1
	msgbox KuraTown_EventScript_SilkScarf_Text_3
	closemessage
	giveitem ITEM_SILK_SCARF
	setflag FLAG_RECEIVED_SILK_SCARF
KuraTown_EventScript_SilkScarf_1:
	release
	return

KuraTown_EventScript_SilkScarf_2:
	setspeaker KuraTown_EventScript_SilkScarf_Text_0
	msgbox KuraTown_EventScript_SilkScarf_Text_1
	closemessage
	goto KuraTown_EventScript_SilkScarf_1


KuraTown_EventScript_FarmerScyther::
	lock
	faceplayer
	setspeaker KuraTown_EventScript_Farmer_Text_0
	msgbox KuraTown_EventScript_FarmerScyther_Text_0, MSGBOX_DEFAULT
	release
	return


KuraTown_EventScript_Scyther::
	lock
	faceplayer
	setseenmon SPECIES_SCYTHER
	playmoncry SPECIES_SCYTHER, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_SCYTHER
	msgbox KuraTown_EventScript_Scyther_Text_0
	waitmoncry
	closemessage
	release
	return


KuraTown_EventScript_Guard::
	lock
	faceplayer
	setspeaker KuraTown_EventScript_Guard_Text_0
	msgbox KuraTown_EventScript_Guard_Text_1, MSGBOX_DEFAULT
	release
	return


SakuTown_EventScript_ClosedGymDoor::
	goto_if_set FLAG_KURA_DOJO_CLOSED, SakuTown_EventScript_ClosedGymDoor_1
	return

SakuTown_EventScript_ClosedGymDoor_1:
	msgbox SakuTown_EventScript_ClosedGymDoor_Text_0, MSGBOX_SIGN
	return


KuraTown_EventScript_LovestruckGuy::
	lock
	faceplayer
	setspeaker KuraTown_EventScript_LovestruckGuy_Text_0
	msgbox KuraTown_EventScript_LovestruckGuy_Text_1, MSGBOX_DEFAULT
	release
	return


KuraTown_EventScript_PokemonCouncil::
	lock
	faceplayer
	setspeaker KuraTown_EventScript_PokemonCouncil_Text_0
	msgbox KuraTown_EventScript_PokemonCouncil_Text_1
	closemessage
	release
	return


KuraTown_EventScript_TownSign::
	msgbox KuraTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


KuraTown_EventScript_TrainerTips::
	msgbox KuraTown_EventScript_TrainerTips_Text_0, MSGBOX_SIGN
	return


KuraTown_EventScript_DirectionsSign::
	msgbox KuraTown_EventScript_DirectionsSign_Text_0, MSGBOX_SIGN
	return


KuraTown_EventScript_GymSign::
	msgbox KuraTown_EventScript_GymSign_Text_0, MSGBOX_SIGN
	return


KuraTown_EventScript_PostDecayNatsukiHariko::
	lockall
	setvar VAR_DECAY_BEACHBOUND_ROUTE, 5
	delay 48
	applymovement LOCALID_KURA_HARIKO, KuraTown_EventScript_PostDecayNatsukiHariko_Movement_0
	setspeaker KuraTown_EventScript_PostDecayNatsukiHariko_Text_0
	msgbox KuraTown_EventScript_PostDecayNatsukiHariko_Text_1
	applymovement LOCALID_KURA_HARIKO, KuraTown_EventScript_PostDecayNatsukiHariko_Movement_1
	msgbox KuraTown_EventScript_PostDecayNatsukiHariko_Text_2
	closemessage
	delay 60
	applymovement LOCALID_KURA_HARIKO, KuraTown_EventScript_PostDecayNatsukiHariko_Movement_0
	setspeaker KuraTown_EventScript_PostDecayNatsukiHariko_Text_0
	msgbox KuraTown_EventScript_PostDecayNatsukiHariko_Text_3
	closemessage
	applymovement LOCALID_KURA_HARIKO, KuraTown_EventScript_PostDecayNatsukiHariko_Movement_2
	delay 32
	applymovement LOCALID_KURA_NATSUKI, KuraTown_EventScript_PostDecayNatsukiHariko_Movement_3
	waitmovement LOCALID_KURA_HARIKO
	delay 24
	applymovement LOCALID_KURA_NATSUKI, KuraTown_EventScript_PostDecayNatsukiHariko_Movement_4
	waitmovement LOCALID_KURA_NATSUKI
	applymovement LOCALID_KURA_NATSUKI, KuraTown_EventScript_PostDecayNatsukiHariko_Movement_5
	applymovement OBJ_EVENT_ID_PLAYER, KuraTown_EventScript_PostDecayNatsukiHariko_Movement_0
	waitmovement 0
	setspeaker KuraTown_EventScript_PostDecayNatsukiHariko_Text_4
	msgbox KuraTown_EventScript_PostDecayNatsukiHariko_Text_5
	applymovement LOCALID_KURA_NATSUKI, KuraTown_EventScript_PostDecayNatsukiHariko_Movement_6
	setspeaker KuraTown_EventScript_PostDecayNatsukiHariko_Text_4
	msgbox KuraTown_EventScript_PostDecayNatsukiHariko_Text_6
	closemessage
	applymovement LOCALID_KURA_NATSUKI, KuraTown_EventScript_PostDecayNatsukiHariko_Movement_7
	delay 32
	applymovement OBJ_EVENT_ID_PLAYER, KuraTown_EventScript_PostDecayNatsukiHariko_Movement_3
	waitmovement LOCALID_KURA_NATSUKI
	removeobject LOCALID_KURA_NATSUKI
	removeobject LOCALID_KURA_HARIKO
	setflag FLAG_TEMP_1
	releaseall
	return


KuraTown_EventScript_AnxiousAshii::
	lock
	delay 48
	applymovement 16, KuraTown_EventScript_PostDecayNatsukiHariko_Movement_0
	applymovement OBJ_EVENT_ID_PLAYER, KuraTown_EventScript_PostDecayNatsukiHariko_Movement_5
	setspeaker KuraTown_EventScript_AnxiousAshii_Text_0
	msgbox KuraTown_EventScript_AnxiousAshii_Text_1
	applymovement 16, KuraTown_EventScript_DojoChallenger_Movement_1
	msgbox KuraTown_EventScript_AnxiousAshii_Text_2
	closemessage
	applymovement 16, KuraTown_EventScript_PostDecayNatsukiHariko_Movement_3
	waitmovement 16
	setvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 6
	release
	return


KuraTown_EventScript_AnxiousAshiiWaiting::
	lock
	faceplayer
	applymovement 16, KuraTown_EventScript_DojoChallenger_Movement_1
	setspeaker KuraTown_EventScript_AnxiousAshii_Text_0
	msgbox KuraTown_EventScript_AnxiousAshiiWaiting_Text_0
	closemessage
	applymovement 16, KuraTown_EventScript_PostDecayNatsukiHariko_Movement_3
	release
	return


KuraTown_EventScript_PreventEscape::
	lock
	applymovement 16, KuraTown_EventScript_PreventEscape_Movement_0
	applymovement OBJ_EVENT_ID_PLAYER, KuraTown_EventScript_PreventEscape_Movement_1
	waitmovement 16
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 16, KuraTown_EventScript_DojoChallenger_Movement_1
	setspeaker KuraTown_EventScript_AnxiousAshii_Text_0
	msgbox KuraTown_EventScript_PreventEscape_Text_0
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, KuraTown_EventScript_PreventEscape_Movement_2
	waitmovement 0
	end


KuraTown_EventScript_Abra::
	lock
	setseenmon SPECIES_ABRA
	setspeakertomonname SPECIES_ABRA
	msgbox KuraTown_EventScript_Abra_Text_0
	closemessage
	playse SE_M_SNORE
	applymovement VAR_LAST_TALKED, KuraTown_EventScript_Abra_Movement_0
	waitmovement 0
	release
	return


KuraTown_EventScript_TeachingScrolls::
	lock
	setnamedmon SPECIES_ABRA
	getdescribedmon SPECIES_ABRA
	compare VAR_RESULT, 0
	goto_if_ne KuraTown_EventScript_TeachingScrolls_2
	checkitem ITEM_TM_PSYBEAM
	compare VAR_RESULT, 0
	goto_if_ne KuraTown_EventScript_TeachingScrolls_3
	faceplayer
	setspeaker KuraTown_EventScript_TeachingScrolls_Text_0
	msgbox KuraTown_EventScript_TeachingScrolls_Text_5
	closemessage
	giveitem ITEM_TM_PSYBEAM
	applymovement VAR_LAST_TALKED, KuraTown_EventScript_TeachingScrolls_Movement_0
	waitmovement VAR_LAST_TALKED
KuraTown_EventScript_TeachingScrolls_1:
	release
	return

KuraTown_EventScript_TeachingScrolls_2:
	faceplayer
	setspeaker KuraTown_EventScript_TeachingScrolls_Text_0
	msgbox KuraTown_EventScript_TeachingScrolls_Text_1
	closemessage
	applymovement VAR_LAST_TALKED, KuraTown_EventScript_TeachingScrolls_Movement_0
	waitmovement VAR_LAST_TALKED
	goto KuraTown_EventScript_TeachingScrolls_1

KuraTown_EventScript_TeachingScrolls_3:
	setspeaker KuraTown_EventScript_TeachingScrolls_Text_0
	msgbox KuraTown_EventScript_TeachingScrolls_Text_2
	closemessage
	setseenmon SPECIES_ABRA
	playse SE_M_SNORE
	applymovement LOCALID_SAKU_ABRA, KuraTown_EventScript_TeachingScrolls_Movement_1
	waitmovement 0
	applymovement VAR_LAST_TALKED, KuraTown_EventScript_TeachingScrolls_Movement_2
	playse SE_M_PSYBEAM
	waitse
	playse SE_M_PSYBEAM
	waitse
	playse SE_M_PSYBEAM
	waitse
	playse SE_M_PSYBEAM2
	waitse
	waitmovement VAR_LAST_TALKED
	faceplayer
	setspeaker KuraTown_EventScript_TeachingScrolls_Text_0
	msgbox KuraTown_EventScript_TeachingScrolls_Text_3
	closemessage
	applymovement VAR_LAST_TALKED, KuraTown_EventScript_TeachingScrolls_Movement_3
	waitmovement VAR_LAST_TALKED
	playse SE_M_SNORE
	applymovement LOCALID_SAKU_ABRA, KuraTown_EventScript_Abra_Movement_0
	waitmovement LOCALID_SAKU_ABRA
	waitse
	applymovement VAR_LAST_TALKED, KuraTown_EventScript_TeachingScrolls_Movement_4
	setspeaker KuraTown_EventScript_TeachingScrolls_Text_0
	msgbox KuraTown_EventScript_TeachingScrolls_Text_4
	closemessage
	setdescribedmon SPECIES_ABRA
	goto KuraTown_EventScript_TeachingScrolls_1


KuraTown_EventScript_DojoChallenger_Movement_0:
	emote_upset
	step_end

KuraTown_EventScript_DojoChallenger_Movement_1:
	emote_sad
	step_end

KuraTown_EventScript_Farmer_Movement_0:
	emote_pensive
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

KuraTown_EventScript_PostDecayNatsukiHariko_Movement_0:
	walk_in_place_fast_left
	step_end

KuraTown_EventScript_PostDecayNatsukiHariko_Movement_1:
	emote_angry
	step_end

KuraTown_EventScript_PostDecayNatsukiHariko_Movement_2:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

KuraTown_EventScript_PostDecayNatsukiHariko_Movement_3:
	walk_in_place_fast_down
	step_end

KuraTown_EventScript_PostDecayNatsukiHariko_Movement_4:
	walk_up
	step_end

KuraTown_EventScript_PostDecayNatsukiHariko_Movement_5:
	walk_in_place_fast_right
	step_end

KuraTown_EventScript_PostDecayNatsukiHariko_Movement_6:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	step_end

KuraTown_EventScript_PostDecayNatsukiHariko_Movement_7:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

KuraTown_EventScript_PreventEscape_Movement_0:
	face_up
	step_end

KuraTown_EventScript_PreventEscape_Movement_1:
	face_down
	step_end

KuraTown_EventScript_PreventEscape_Movement_2:
	walk_down
	walk_down
	step_end

KuraTown_EventScript_Abra_Movement_0:
	emote_sleep
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

KuraTown_EventScript_TeachingScrolls_Movement_0:
	face_left
	step_end

KuraTown_EventScript_TeachingScrolls_Movement_1:
	emote_sleep
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	step_end

KuraTown_EventScript_TeachingScrolls_Movement_2:
	face_down
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fast_down
	walk_in_place_fast_down
	lock_facing_direction
	lock_anim
	walk_slow_up
	walk_slow_down
	walk_slow_up
	walk_slow_down
	unlock_facing_direction
	unlock_anim
	delay_16
	delay_16
	delay_16
	step_end

KuraTown_EventScript_TeachingScrolls_Movement_3:
	face_left
	delay_16
	delay_16
	delay_16
	step_end

KuraTown_EventScript_TeachingScrolls_Movement_4:
	emote_sweat
	step_end

KuraTown_EventScript_GuardStopsYou_Text_0:
	.string "Hey!$"

KuraTown_EventScript_GuardStopsYou_Text_1:
	.string "You think I don't see you trying to\n"
	.string "sneak in from Saku Village?\p"
	.string "…Wait, you're a regular traveler,\n"
	.string "aren't you…\p"
	.string "Welcome to Kura Village then!$"

KuraTown_EventScript_GuardStopsYou_Text_2:
	.string "You're not trying to sneak into Saku\n"
	.string "Village, are you?\p"
	.string "…My bad, you're that traveler again.\n"
	.string "Didn't recognize ya.\p"
	.string "You can go through, though I'm not\n"
	.string "sure why you'd want to.$"

KuraTown_EventScript_DojoChallenger_Text_0:
	.string "Bold Man$"

KuraTown_EventScript_DojoChallenger_Text_1:
	.string "Looks like the Dojo is closed again…\p"
	.string "Gah, when will I get a chance to crush\n"
	.string "Hana in a fiery battle?\p"
	.string "Could it be that she is scared of me?$"

KuraTown_EventScript_DojoChallenger_Text_2:
	.string "Cowardly Man$"

KuraTown_EventScript_DojoChallenger_Text_3:
	.string "The Dojo is open! I can finally defeat\n"
	.string "its leader in a fiery battle!\p"
	.string "…Hm? When, you ask?\p"
	.string "In… In a minute…$"

KuraTown_EventScript_DojoChallenger_Text_4:
	.string "No, go right ahead, I'm just…\n"
	.string "preparing…$"

KuraTown_EventScript_Farmer_Text_0:
	.string "Farmer$"

KuraTown_EventScript_Farmer_Text_1:
	.string "Why do we hate the Saku Village folks,\n"
	.string "y'ask?$"

KuraTown_EventScript_Farmer_Text_2:
	.string "To be honest, I don't quite rememb'r.\n"
	.string "But who needs a reas'n, right?$"

KuraTown_EventScript_SilkScarf_Text_0:
	.string "Girl$"

KuraTown_EventScript_SilkScarf_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_1 EMOTE_NORMAL}Sigh… Now I'm scarfless…\p"
	.string "At least I'm not committing any more\n"
	.string "crimes against fashion…$"

KuraTown_EventScript_SilkScarf_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_1 EMOTE_NORMAL}Hey, you! Yes, you! I need some\n"
	.string "super-urgent fashion advice!\p"
	.string "I bought myself this scarf in Yifu\n"
	.string "City… But now I'm worried the white\l"
	.string "clashes with my complexion!\p"
	.string "Is it awful?\n"
	.string "Does it make my skin look grey?$"

KuraTown_EventScript_SilkScarf_Text_3:
	.string "Oh gosh, it does, doesn't it? I knew\n"
	.string "it! I have to get rid of it right this\l"
	.string "moment!\p"
	.string "Take it! Take it! I can't even look at\n"
	.string "it!$"

KuraTown_EventScript_FarmerScyther_Text_0:
	.string "We started taming Scyther recently\n"
	.string "to help with harvestin' the crops.\l"
	.string "They've been a tremendous help!$"

KuraTown_EventScript_Scyther_Text_0:
	.string "Gyooo!$"

KuraTown_EventScript_Guard_Text_0:
	.string "Guard$"

KuraTown_EventScript_Guard_Text_1:
	.string "Hope you didn't have too much trouble\n"
	.string "passing the gate.\p"
	.string "That Saku Village guard is such a\n"
	.string "jerk, he won't let anyone from our\l"
	.string "village cross to theirs.\p"
	.string "So of course we're not gonna let\n"
	.string "anyone from theirs in ours! Hah!$"

SakuTown_EventScript_ClosedGymDoor_Text_0:
	.string "“BE BACK SOON\n"
	.string "- Hana”$"

KuraTown_EventScript_LovestruckGuy_Text_0:
	.string "Lovestruck Boy$"

KuraTown_EventScript_LovestruckGuy_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_BOY_1 EMOTE_NORMAL}I just got back home after spending\n"
	.string "time with my love, and yet I already\l"
	.string "want the day to pass by and let me\l"
	.string "see her again…$"

KuraTown_EventScript_PokemonCouncil_Text_0:
	.string "Woman$"

KuraTown_EventScript_PokemonCouncil_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_WOMAN_2 EMOTE_NORMAL}The Elders of the Toku Council may\n"
	.string "look like a bunch of frail old people,\l"
	.string "but each of them was once a\l"
	.string "formidable Wielder!\p"
	.string "They paved the way for what Pokémon\n"
	.string "Wielding is today, and will be\l"
	.string "tomorrow.$"

KuraTown_EventScript_TownSign_Text_0:
	.string "Kura Village\n"
	.string "“A village where the mountains meet\l"
	.string "the woods.”$"

KuraTown_EventScript_TrainerTips_Text_0:
	.string "Did you know?\p"
	.string "The people from Saku Village can and\n"
	.string "will eat your children!$"

KuraTown_EventScript_DirectionsSign_Text_0:
	.string "{UP_ARROW} Silver Tunnel\n"
	.string "This way for Silveridge$"

KuraTown_EventScript_GymSign_Text_0:
	.string "Kura Village Pokémon Dojo\n"
	.string "Leader: Hana\p"
	.string "“Resilient as a maple rooted in\n"
	.string "wisdom.”$"

KuraTown_EventScript_PostDecayNatsukiHariko_Text_0:
	.string "Hariko$"

KuraTown_EventScript_PostDecayNatsukiHariko_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}Did you hear? They said this Decay\n"
	.string "has started less than a week ago.\p"
	.string "That coincides with the beginning of\n"
	.string "the Volcano's rumbling spells,\l"
	.string "so there probably is a correlation.\p"
	.string "We need to get to the bottom of this.$"

KuraTown_EventScript_PostDecayNatsukiHariko_Text_2:
	.string "But how are we supposed to if the\n"
	.string "grownups don't let us?$"

KuraTown_EventScript_PostDecayNatsukiHariko_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_HARIKO EMOTE_NORMAL}… …{PLAYER}, Natsuki.\n"
	.string "I am heading home, in Yifu City.\p"
	.string "We should meet up later to talk about\n"
	.string "this some more.\p"
	.string "Well, I am leaving now.\p"
	.string "Goodbye!$"

KuraTown_EventScript_PostDecayNatsukiHariko_Text_4:
	.string "Natsuki$"

KuraTown_EventScript_PostDecayNatsukiHariko_Text_5:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}Boy, your friend sure talks a lot, huh?\p"
	.string "D'you think this whole Decay business\n"
	.string "is linked to the wild Pokémon attacks\l"
	.string "Elder Kaba told us about?\p"
	.string "I'm glad the Samurai are on it.\n"
	.string "I'm sure they'll fix whatever this is.\p"
	.string "You're going up to Silveridge to\n"
	.string "deliver that letter, huh, {PLAYER}?\p"
	.string "Me? I'm heading to Yifu City.\n"
	.string "There's a Dojo there, and I'll need\l"
	.string "to collect a heckload of Tokens\l"
	.string "if I ever want to join the New Moon\l"
	.string "order.\p"
	.string "When I'm a Samurai, I'll be able to\n"
	.string "protect everyone from danger!\p"
	.string "Don't worry, I'll protect you, too!{PAUSE_UNTIL_PRESS}\n"
	.string "…Mostly from yourself, though!$"

KuraTown_EventScript_PostDecayNatsukiHariko_Text_6:
	.string "{CREATE_MUGSHOT MUGSHOT_NATSUKI EMOTE_NORMAL}Don't hit me! Don't hit me!\n"
	.string "I'm gone!\p"
	.string "See ya later, Feraligatr!$"

KuraTown_EventScript_AnxiousAshii_Text_0:
	.string "Ashii$"

KuraTown_EventScript_AnxiousAshii_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}My heart is racing… Where is he?\n"
	.string "I hope he's alright…$"

KuraTown_EventScript_AnxiousAshii_Text_2:
	.string "I'm worried…\n"
	.string "Can you check down south for me?$"

KuraTown_EventScript_AnxiousAshiiWaiting_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}I'm worried…\n"
	.string "Can you check down south for me?$"

KuraTown_EventScript_PreventEscape_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_GIRL_2 EMOTE_NORMAL}Where on earth are you going,\n"
	.string "{PLAYER}?!\p"
	.string "{FONT_SMALL_NARROW}Please don't leave me here alone…$"

KuraTown_EventScript_Abra_Text_0:
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

KuraTown_EventScript_TeachingScrolls_Text_0:
	.string "Guy$"

KuraTown_EventScript_TeachingScrolls_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_FAT_GUY EMOTE_NORMAL}Abra is the best!\n"
	.string "He can use attacks in his sleep!$"

KuraTown_EventScript_TeachingScrolls_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_FAT_GUY EMOTE_NORMAL}C'mon Abra, wakey wakey…$"

KuraTown_EventScript_TeachingScrolls_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_FAT_GUY EMOTE_NORMAL}Did… Did you see that?!\p"
	.string "Abra made me float in the air with his\n"
	.string "Psybeam!!$"

KuraTown_EventScript_TeachingScrolls_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_FAT_GUY EMOTE_NORMAL}He didn't even wake up…$"

KuraTown_EventScript_TeachingScrolls_Text_5:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_FAT_GUY EMOTE_NORMAL}I taught Abra a sick Psychic move\n"
	.string "using a Technique Scroll, but…\p"
	.string "Guess even the sickest move is\n"
	.string "useless if all he does is sleep, huh…\p"
	.string "You can have my Scroll.\n"
	.string "Use it as many times as you want.$"

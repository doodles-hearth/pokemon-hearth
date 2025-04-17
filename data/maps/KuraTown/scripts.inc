KuraTown_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, KuraTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_KURA_DOJO_CLOSED, KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_2
KuraTown_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	gettimeofday
	switch VAR_RESULT
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
	speakername KuraTown_EventScript_DojoChallenger_Text_2
	msgbox KuraTown_EventScript_DojoChallenger_Text_3
KuraTown_EventScript_DojoChallenger_1:
	closemessage
	release
	return

KuraTown_EventScript_DojoChallenger_2:
	speakername KuraTown_EventScript_DojoChallenger_Text_0
	msgbox KuraTown_EventScript_DojoChallenger_Text_1
	goto KuraTown_EventScript_DojoChallenger_1


KuraTown_EventScript_Farmer::
	lock
	faceplayer
	speakername KuraTown_EventScript_Farmer_Text_0
	msgbox KuraTown_EventScript_Farmer_Text_1, MSGBOX_DEFAULT
	release
	return


KuraTown_EventScript_SilkScarf::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, KuraTown_EventScript_SilkScarf_2
	speakername KuraTown_EventScript_SilkScarf_Text_0
	msgbox KuraTown_EventScript_SilkScarf_Text_2
	closemessage
	giveitem ITEM_SILK_SCARF
	setflag FLAG_RECEIVED_SILK_SCARF
KuraTown_EventScript_SilkScarf_1:
	release
	return

KuraTown_EventScript_SilkScarf_2:
	speakername KuraTown_EventScript_SilkScarf_Text_0
	msgbox KuraTown_EventScript_SilkScarf_Text_1
	closemessage
	goto KuraTown_EventScript_SilkScarf_1


KuraTown_EventScript_FarmerScyther::
	lock
	faceplayer
	speakername KuraTown_EventScript_Farmer_Text_0
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
	msgbox KuraTown_EventScript_Guard_Text_0, MSGBOX_DEFAULT
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
	speakername KuraTown_EventScript_LovestruckGuy_Text_0
	msgbox KuraTown_EventScript_LovestruckGuy_Text_1, MSGBOX_DEFAULT
	release
	return


KuraTown_EventScript_PokemonCouncil::
	lock
	faceplayer
	speakername KuraTown_EventScript_PokemonCouncil_Text_0
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
	.string "In… In a minute…\p"
	.string "No, go right ahead, I'm just…\n"
	.string "preparing…$"

KuraTown_EventScript_Farmer_Text_0:
	.string "Farmer$"

KuraTown_EventScript_Farmer_Text_1:
	.string "Why do we hate the Saku Village folks,\n"
	.string "y'ask?\p"
	.string "To be honest, I don't quite rememb'r.\n"
	.string "But who needs a reas'n, right?$"

KuraTown_EventScript_SilkScarf_Text_0:
	.string "Girl$"

KuraTown_EventScript_SilkScarf_Text_1:
	.string "Sigh… Now I'm scarfless…\p"
	.string "Well, at least I'm not committing any\n"
	.string "more crimes against fashion…$"

KuraTown_EventScript_SilkScarf_Text_2:
	.string "Hey, you! Yes, you! I need some\n"
	.string "super-urgent fashion advice!\p"
	.string "I bought myself this scarf in Yifu\n"
	.string "City… But now I'm worried the white\l"
	.string "clashes with my complexion!\p"
	.string "Is it awful?\n"
	.string "Does it make my skin look grey?\p"
	.string "Oh gosh, it does, doesn't it? I knew\n"
	.string "it! I have to get rid of it right this\l"
	.string "moment!\p"
	.string "Take it! Take it! I can't even look at\n"
	.string "it!$"

KuraTown_EventScript_FarmerScyther_Text_0:
	.string "We started taming Scyther recently\n"
	.string "to help us with harvestin' the crops.\l"
	.string "They've been a tremendous help!$"

KuraTown_EventScript_Scyther_Text_0:
	.string "Gyooo!$"

KuraTown_EventScript_Guard_Text_0:
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
	.string "I just got back home after spending\n"
	.string "time with my love, and yet I already\l"
	.string "want the day to pass by and let me\l"
	.string "see her again…$"

KuraTown_EventScript_PokemonCouncil_Text_0:
	.string "Woman$"

KuraTown_EventScript_PokemonCouncil_Text_1:
	.string "The Elders of the Toku Council may\n"
	.string "look like a bunch of old people, but\l"
	.string "each of them was once a formidable\l"
	.string "Wielder!\p"
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

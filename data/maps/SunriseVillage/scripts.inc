SunriseVillage_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD:
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_4
	gettime
	compare VAR_0x8000, 5
	goto_if_ge SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_2
	return

SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	random 4
	switch VAR_RESULT
	case 0, SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_6
	case 1, SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_7
	case 2, SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_8
	case 3, SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_9
	return

SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	compare VAR_0x8000, 17
	goto_if_le SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_6:
	clearflag FLAG_TEMP_1
	return

SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_7:
	clearflag FLAG_TEMP_2
	return

SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_8:
	clearflag FLAG_TEMP_4
	return

SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD_9:
	clearflag FLAG_TEMP_1
	clearflag FLAG_TEMP_3
	return


SunriseVillage_Event_FatGuy::
	lock
	faceplayer
	speakername SunriseVillage_Event_FatGuy_Text_0
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 4
	goto_if_ge SunriseVillage_Event_FatGuy_2
	msgbox SunriseVillage_Event_FatGuy_Text_2
	closemessage
SunriseVillage_Event_FatGuy_1:
	release
	end

SunriseVillage_Event_FatGuy_2:
	msgbox SunriseVillage_Event_FatGuy_Text_1
	closemessage
	applymovement 3, Common_Movement_FaceOriginalDirection
	goto SunriseVillage_Event_FatGuy_1


SunriseVillage_Event_GuardForest::
	lock
	applymovement 6, Common_Movement_WalkInPlaceFasterLeft
	goto_if_set FLAG_RECEIVED_STARTER, SunriseVillage_Event_GuardForest_2
	speakername SunriseVillage_Event_FatGuy_Text_0
	msgbox SunriseVillage_Event_GuardForest_Text_3
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	speakername SunriseVillage_Event_FatGuy_Text_0
	msgbox SunriseVillage_Event_GuardForest_Text_4
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Event_GuardForest_Movement_0
	waitmovement 0
SunriseVillage_Event_GuardForest_1:
	release
	end

SunriseVillage_Event_GuardForest_2:
	speakername SunriseVillage_Event_FatGuy_Text_0
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 8
	goto_if_ge SunriseVillage_Event_GuardForest_5
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 7
	goto_if_eq SunriseVillage_Event_GuardForest_6
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox SunriseVillage_Event_GuardForest_Text_2
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Event_GuardForest_Movement_0
	waitmovement 0
	goto SunriseVillage_Event_GuardForest_1

SunriseVillage_Event_GuardForest_5:
	msgbox SunriseVillage_Event_GuardForest_Text_0
	closemessage
	goto SunriseVillage_Event_GuardForest_1

SunriseVillage_Event_GuardForest_6:
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox SunriseVillage_Event_GuardForest_Text_1
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Event_GuardForest_Movement_0
	waitmovement 0
	goto SunriseVillage_Event_GuardForest_1


SunriseVillage_Event_GuardForest_Interact::
	lock
	faceplayer
	speakername SunriseVillage_Event_FatGuy_Text_0
	goto_if_set FLAG_RECEIVED_STARTER, SunriseVillage_Event_GuardForest_Interact_2
	msgbox SunriseVillage_Event_GuardForest_Interact_Text_0
	closemessage
SunriseVillage_Event_GuardForest_Interact_1:
	release
	end

SunriseVillage_Event_GuardForest_Interact_2:
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 8
	goto_if_ge SunriseVillage_Event_GuardForest_Interact_5
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 7
	goto_if_eq SunriseVillage_Event_GuardForest_Interact_6
	msgbox SunriseVillage_Event_GuardForest_Text_2
	closemessage
	goto SunriseVillage_Event_GuardForest_Interact_1

SunriseVillage_Event_GuardForest_Interact_5:
	msgbox SunriseVillage_Event_GuardForest_Text_0
	closemessage
	goto SunriseVillage_Event_GuardForest_Interact_1

SunriseVillage_Event_GuardForest_Interact_6:
	msgbox SunriseVillage_Event_GuardForest_Text_1
	closemessage
	goto SunriseVillage_Event_GuardForest_Interact_1


SunriseVillage_Event_LittleGirl::
	speakername SunriseVillage_Event_LittleGirl_Text_0
	msgbox SunriseVillage_Event_LittleGirl_Text_1, MSGBOX_NPC
	return


SunriseVillage_Event_Boy::
	lockall
	faceplayer
	speakername SunriseVillage_Event_Boy_Text_0
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 4
	goto_if_ge SunriseVillage_Event_Boy_2
	msgbox SunriseVillage_Event_Boy_Text_2
	closemessage
SunriseVillage_Event_Boy_1:
	releaseall
	end

SunriseVillage_Event_Boy_2:
	msgbox SunriseVillage_Event_Boy_Text_1
	closemessage
	goto SunriseVillage_Event_Boy_1


SunriseVillage_Event_Woman::
	lockall
	speakername SunriseVillage_Event_FatGuy_Text_0
	msgbox SunriseVillage_Event_Woman_Text_0
	releaseall
	end


SunriseVillage_Event_Farmer::
	lockall
	faceplayer
	speakername SunriseVillage_Event_FatGuy_Text_0
	msgbox SunriseVillage_Event_Farmer_Text_0
	releaseall
	end


SunriseVillage_Event_OldMan::
	lockall
	faceplayer
	speakername SunriseVillage_Event_FatGuy_Text_0
	msgbox SunriseVillage_Event_OldMan_Text_0
	releaseall
	end


SunriseVillage_Event_OldWoman::
	speakername SunriseVillage_Event_FatGuy_Text_0
	msgbox SunriseVillage_Event_OldWoman_Text_0, MSGBOX_NPC
	return


SunriseVillage_Event_Happiny::
	lock
	faceplayer
	ismonseen SPECIES_HAPPINY
	compare VAR_RESULT, 0
	goto_if_ne SunriseVillage_Event_Happiny_2
	speakername SunriseVillage_Event_Happiny_Text_1
SunriseVillage_Event_Happiny_1:
	msgbox SunriseVillage_Event_Happiny_Text_2
	playmoncry SPECIES_HAPPINY, CRY_MODE_NORMAL
	waitmoncry
	release
	end

SunriseVillage_Event_Happiny_2:
	speakername SunriseVillage_Event_Happiny_Text_0
	goto SunriseVillage_Event_Happiny_1


SunriseVillage_Event_Munchlax::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_NORMAL
	ismonseen SPECIES_MUNCHLAX
	compare VAR_RESULT, 0
	goto_if_ne SunriseVillage_Event_Munchlax_2
	speakername SunriseVillage_Event_Munchlax_Text_1
SunriseVillage_Event_Munchlax_1:
	msgbox SunriseVillage_Event_Munchlax_Text_2
	waitmoncry
	release
	end

SunriseVillage_Event_Munchlax_2:
	speakername SunriseVillage_Event_Munchlax_Text_0
	goto SunriseVillage_Event_Munchlax_1


SunriseVillage_Event_Kirlia::
	lock
	faceplayer
	ismonseen SPECIES_KIRLIA
	compare VAR_RESULT, 0
	goto_if_ne SunriseVillage_Event_Kirlia_2
	speakername SunriseVillage_Event_Kirlia_Text_1
SunriseVillage_Event_Kirlia_1:
	msgbox SunriseVillage_Event_Kirlia_Text_2
	release
	end

SunriseVillage_Event_Kirlia_2:
	speakername SunriseVillage_Event_Kirlia_Text_0
	goto SunriseVillage_Event_Kirlia_1


SunriseVillage_Event_TestGyarados::
	lock
	givemon SPECIES_SPHEAL, 100
	setwildbattle SPECIES_KOTORA, 5
	dowildbattle
	release
	end


SunriseVillage_Event_TownSign::
	msgbox SunriseVillage_Event_TownSign_Text_0, MSGBOX_SIGN
	return


SunriseVillage_Event_PlayersHouseSign::
	msgbox SunriseVillage_Event_PlayersHouseSign_Text_0, MSGBOX_SIGN
	return


SunriseVillage_Event_RivalsHouseSign::
	msgbox SunriseVillage_Event_RivalsHouseSign_Text_0, MSGBOX_SIGN
	return


SunriseVillage_Event_EldersHouseSign::
	msgbox SunriseVillage_Event_EldersHouseSign_Text_0, MSGBOX_SIGN
	return


SunriseVillage_Event_GuardForest_Movement_0:
	walk_down
	step_end

SunriseVillage_Event_FatGuy_Text_0:
	.string "Neighbour$"

SunriseVillage_Event_FatGuy_Text_1:
	.string "My new Pokémon is so cute, I don't\n"
	.string "feel like leaving it in its Pokéball!$"

SunriseVillage_Event_FatGuy_Text_2:
	.string "Someone managed to fit entire\n"
	.string "Pokémon inside these tiny balls.\p"
	.string "The power of science is staggering!$"

SunriseVillage_Event_GuardForest_Text_0:
	.string "Oh, I see you received a Pokémon!\p"
	.string "You'll probably be able to manage the\n"
	.string "woods on your own, then.\p"
	.string "Be careful!$"

SunriseVillage_Event_GuardForest_Text_1:
	.string "Hey, kid, heard you were going off on\n"
	.string "an adventure!\p"
	.string "Did you say bye to your sister?\p"
	.string "No? Thought so. Go see her before you\n"
	.string "run off, you ungrateful sibling!$"

SunriseVillage_Event_GuardForest_Text_2:
	.string "Hey, kid, a friend of yours was looking\n"
	.string "for you.$"

SunriseVillage_Event_GuardForest_Text_3:
	.string "Stop right there, kid!$"

SunriseVillage_Event_GuardForest_Text_4:
	.string "Wild POKéMON have been lashing out\n"
	.string "recently.\p"
	.string "I know you're used to walking around\n"
	.string "on your own, but the woods have\l"
	.string "become a dangerous place lately!\p"
	.string "I wouldn't go alone if I were you.\p"
	.string "Or, you know, if I were me.$"

SunriseVillage_Event_GuardForest_Interact_Text_0:
	.string "Wild POKéMON have been lashing out\n"
	.string "recently.\p"
	.string "Even the Ginko woods have become a\n"
	.string "dangerous place lately!$"

SunriseVillage_Event_LittleGirl_Text_0:
	.string "Little girl$"

SunriseVillage_Event_LittleGirl_Text_1:
	.string "I can't wait I can't wait I can't\n"
	.string "wait!!!\p"
	.string "AHHHHH I CAN'T WAIT!!!!$"

SunriseVillage_Event_Boy_Text_0:
	.string "Kid$"

SunriseVillage_Event_Boy_Text_1:
	.string "My Happiny is the strongest of all!\n"
	.string "See how fierce it looks?$"

SunriseVillage_Event_Boy_Text_2:
	.string "Hey {PLAYER}{KUN}!\p"
	.string "So, d'you think we'll get to choose the\n"
	.string "one we want?$"

SunriseVillage_Event_Woman_Text_0:
	.string "I can see the Poké Balls from here…\n"
	.string "I've never seen so many in my life!$"

SunriseVillage_Event_Farmer_Text_0:
	.string "I've been waiting for hours!$"

SunriseVillage_Event_OldMan_Text_0:
	.string "The distribution is about to start.$"

SunriseVillage_Event_OldWoman_Text_0:
	.string "I'm tired of waiting!$"

SunriseVillage_Event_Happiny_Text_0:
	.string "Happiny$"

SunriseVillage_Event_Happiny_Text_1:
	.string "Noisy egg$"

SunriseVillage_Event_Happiny_Text_2:
	.string "Happi!$"

SunriseVillage_Event_Munchlax_Text_0:
	.string "Munchlax$"

SunriseVillage_Event_Munchlax_Text_1:
	.string "Big nom$"

SunriseVillage_Event_Munchlax_Text_2:
	.string "Munch munch munch…$"

SunriseVillage_Event_Kirlia_Text_0:
	.string "Kirlia$"

SunriseVillage_Event_Kirlia_Text_1:
	.string "Posh dancer$"

SunriseVillage_Event_Kirlia_Text_2:
	.string "…$"

SunriseVillage_Event_TownSign_Text_0:
	.string "Sunrise Village\n"
	.string "“A village bathing in soft light.”$"

SunriseVillage_Event_PlayersHouseSign_Text_0:
	.string "{PLAYER}'s house$"

SunriseVillage_Event_RivalsHouseSign_Text_0:
	.string "Natsuki's house$"

SunriseVillage_Event_EldersHouseSign_Text_0:
	.string "Elder Kaba's house$"

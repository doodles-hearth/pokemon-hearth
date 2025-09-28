SunriseVillage_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SunriseVillage_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_TRANSITION, SunriseVillage_MapScripts_MAP_SCRIPT_ON_TRANSITION
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

SunriseVillage_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_SUNRISE_VILLAGE
	return


SunriseVillage_Event_FatGuy::
	lock
	faceplayer
	setspeaker SunriseVillage_Event_FatGuy_Text_0
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 4
	goto_if_ge SunriseVillage_Event_FatGuy_2
	msgbox SunriseVillage_Event_FatGuy_Text_2
	closemessage
SunriseVillage_Event_FatGuy_1:
	release
	end

SunriseVillage_Event_FatGuy_2:
	applymovement VAR_LAST_TALKED, SunriseVillage_Event_FatGuy_Movement_0
	msgbox SunriseVillage_Event_FatGuy_Text_1
	closemessage
	waitmovement VAR_LAST_TALKED
	applymovement 3, Common_Movement_FaceOriginalDirection
	goto SunriseVillage_Event_FatGuy_1


SunriseVillage_Event_GuardForest::
	lockall
	applymovement 6, Common_Movement_WalkInPlaceFasterLeft
	goto_if_set FLAG_RECEIVED_STARTER, SunriseVillage_Event_GuardForest_2
	setspeaker SunriseVillage_Event_FatGuy_Text_0
	msgbox SunriseVillage_Event_GuardForest_Text_4
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	setspeaker SunriseVillage_Event_FatGuy_Text_0
	msgbox SunriseVillage_Event_GuardForest_Text_5
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Event_GuardForest_Movement_1
	waitmovement 0
SunriseVillage_Event_GuardForest_1:
	releaseall
	end

SunriseVillage_Event_GuardForest_2:
	setspeaker SunriseVillage_Event_FatGuy_Text_0
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 8
	goto_if_ge SunriseVillage_Event_GuardForest_5
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 7
	goto_if_eq SunriseVillage_Event_GuardForest_6
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox SunriseVillage_Event_GuardForest_Text_3
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Event_GuardForest_Movement_1
	waitmovement 0
	goto SunriseVillage_Event_GuardForest_1

SunriseVillage_Event_GuardForest_5:
	msgbox SunriseVillage_Event_GuardForest_Text_0
	closemessage
	goto SunriseVillage_Event_GuardForest_1

SunriseVillage_Event_GuardForest_6:
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox SunriseVillage_Event_GuardForest_Text_1
	applymovement 6, SunriseVillage_Event_GuardForest_Movement_0
	msgbox SunriseVillage_Event_GuardForest_Text_2
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SunriseVillage_Event_GuardForest_Movement_1
	waitmovement 0
	goto SunriseVillage_Event_GuardForest_1


SunriseVillage_Event_GuardForest_Interact::
	lock
	faceplayer
	setspeaker SunriseVillage_Event_FatGuy_Text_0
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
	msgbox SunriseVillage_Event_GuardForest_Text_3
	closemessage
	goto SunriseVillage_Event_GuardForest_Interact_1

SunriseVillage_Event_GuardForest_Interact_5:
	msgbox SunriseVillage_Event_GuardForest_Text_0
	closemessage
	goto SunriseVillage_Event_GuardForest_Interact_1

SunriseVillage_Event_GuardForest_Interact_6:
	msgbox SunriseVillage_Event_GuardForest_Text_1
	applymovement 6, SunriseVillage_Event_GuardForest_Movement_0
	msgbox SunriseVillage_Event_GuardForest_Text_2
	closemessage
	goto SunriseVillage_Event_GuardForest_Interact_1


SunriseVillage_Event_LittleGirl::
	lock
	faceplayer
	applymovement VAR_LAST_TALKED, SunriseVillage_Event_LittleGirl_Movement_0
	setspeaker SunriseVillage_Event_LittleGirl_Text_0
	msgbox SunriseVillage_Event_LittleGirl_Text_1
	closemessage
	release
	return


SunriseVillage_Event_Boy::
	lock
	faceplayer
	setspeaker SunriseVillage_Event_Boy_Text_0
	compare VAR_SUNRISE_VILLAGE_INTRO_STATE, 4
	goto_if_ge SunriseVillage_Event_Boy_2
	msgbox SunriseVillage_Event_Boy_Text_2
	closemessage
SunriseVillage_Event_Boy_1:
	release
	end

SunriseVillage_Event_Boy_2:
	msgbox SunriseVillage_Event_Boy_Text_1
	closemessage
	setnamedmon SPECIES_HAPPINY
	goto SunriseVillage_Event_Boy_1


SunriseVillage_Event_Woman::
	lock
	faceplayer
	setspeaker SunriseVillage_Event_FatGuy_Text_0
	msgbox SunriseVillage_Event_Woman_Text_0
	release
	end


SunriseVillage_Event_Farmer::
	lock
	faceplayer
	applymovement VAR_LAST_TALKED, SunriseVillage_Event_Farmer_Movement_0
	setspeaker SunriseVillage_Event_FatGuy_Text_0
	msgbox SunriseVillage_Event_Farmer_Text_0
	release
	end


SunriseVillage_Event_OldMan::
	lock
	faceplayer
	setspeaker SunriseVillage_Event_FatGuy_Text_0
	msgbox SunriseVillage_Event_OldMan_Text_0
	release
	return


SunriseVillage_Event_OldWoman::
	lock
	faceplayer
	applymovement VAR_LAST_TALKED, SunriseVillage_Event_GuardForest_Movement_0
	setspeaker SunriseVillage_Event_FatGuy_Text_0
	msgbox SunriseVillage_Event_OldWoman_Text_0
	release
	return


SunriseVillage_Event_Happiny::
	lock
	faceplayer
	playmoncry SPECIES_HAPPINY, CRY_MODE_NORMAL
	setseenmon SPECIES_HAPPINY
	applymovement VAR_LAST_TALKED, SunriseVillage_Event_Happiny_Movement_0
	setspeakertomonname SPECIES_HAPPINY
	msgbox SunriseVillage_Event_Happiny_Text_0
	waitmoncry
	release
	end


SunriseVillage_Event_Munchlax::
	lock
	faceplayer
	setseenmon SPECIES_MUNCHLAX
	playmoncry SPECIES_MUNCHLAX, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_MUNCHLAX
	msgbox SunriseVillage_Event_Munchlax_Text_0
	waitmoncry
	release
	end


SunriseVillage_Event_Kirlia::
	lock
	faceplayer
	applymovement VAR_LAST_TALKED, SunriseVillage_Event_Kirlia_Movement_0
	setspeakertomonname SPECIES_KIRLIA
	msgbox SunriseVillage_Event_Kirlia_Text_0
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


SunriseVillage_Event_FatGuy_Movement_0:
	emote_heart
	step_end

SunriseVillage_Event_GuardForest_Movement_0:
	emote_angry
	step_end

SunriseVillage_Event_GuardForest_Movement_1:
	walk_down
	step_end

SunriseVillage_Event_LittleGirl_Movement_0:
	emote_happy
	step_end

SunriseVillage_Event_Farmer_Movement_0:
	emote_upset
	step_end

SunriseVillage_Event_Happiny_Movement_0:
	emote_music
	step_end

SunriseVillage_Event_Kirlia_Movement_0:
	emote_pensive
	step_end

SunriseVillage_Event_FatGuy_Text_0:
	.string "Neighbour$"

SunriseVillage_Event_FatGuy_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_FAT_GUY EMOTE_NORMAL}My new Pokémon is so cute, I don't\n"
	.string "feel like leaving it in its Pokéball!$"

SunriseVillage_Event_FatGuy_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_FAT_GUY EMOTE_NORMAL}Someone managed to fit entire\n"
	.string "Pokémon inside these tiny balls.\p"
	.string "The power of science is staggering!$"

SunriseVillage_Event_GuardForest_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_MAN_2 EMOTE_NORMAL}Oh, I see you received a Pokémon!\p"
	.string "You'll probably be able to manage the\n"
	.string "woods on your own, then.\p"
	.string "Be careful!$"

SunriseVillage_Event_GuardForest_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_MAN_2 EMOTE_NORMAL}Hey, kid, heard you were going off on\n"
	.string "an adventure!\p"
	.string "Did you say bye to your sister?$"

SunriseVillage_Event_GuardForest_Text_2:
	.string "No? Thought so. Go see her before you\n"
	.string "run off, you ungrateful sibling!$"

SunriseVillage_Event_GuardForest_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_MAN_2 EMOTE_NORMAL}Hey, kid, a friend of yours was looking\n"
	.string "for you.$"

SunriseVillage_Event_GuardForest_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_MAN_2 EMOTE_NORMAL}Stop right there, kid!$"

SunriseVillage_Event_GuardForest_Text_5:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_MAN_2 EMOTE_NORMAL}Wild Pokémon have been lashing out\n"
	.string "recently.\p"
	.string "I know you're used to walking around\n"
	.string "on your own, but the woods have\l"
	.string "become a dangerous place lately!\p"
	.string "I wouldn't go alone if I were you.\p"
	.string "Or, you know, if I were me.$"

SunriseVillage_Event_GuardForest_Interact_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_MAN_2 EMOTE_NORMAL}Wild Pokémon have been lashing out\n"
	.string "recently.\p"
	.string "Even the Ginko woods have become a\n"
	.string "dangerous place lately!$"

SunriseVillage_Event_LittleGirl_Text_0:
	.string "Little girl$"

SunriseVillage_Event_LittleGirl_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_LITTLE_GIRL EMOTE_NORMAL}I can't wait I can't wait I can't\n"
	.string "wait!!!\p"
	.string "AHHHHH I CAN'T WAIT!!!!$"

SunriseVillage_Event_Boy_Text_0:
	.string "Kid$"

SunriseVillage_Event_Boy_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_BOY_1 EMOTE_NORMAL}My Happiny is the strongest of all!\n"
	.string "See how fierce it looks?$"

SunriseVillage_Event_Boy_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_BOY_1 EMOTE_NORMAL}Hey {PLAYER}!\p"
	.string "So, d'you think we'll get to choose the\n"
	.string "one we want?$"

SunriseVillage_Event_Woman_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_WOMAN_2 EMOTE_NORMAL}I can see the Poké Balls from here…\n"
	.string "I've never seen so many in my life!$"

SunriseVillage_Event_Farmer_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_MAN_1 EMOTE_NORMAL}I've been waiting for hours!$"

SunriseVillage_Event_OldMan_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_OLD_MAN EMOTE_NORMAL}The distribution is about to start.$"

SunriseVillage_Event_OldWoman_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_OLD_WOMAN EMOTE_NORMAL}I'm tired of waiting!$"

SunriseVillage_Event_Happiny_Text_0:
	.string "Happi!$"

SunriseVillage_Event_Munchlax_Text_0:
	.string "Munch munch munch…$"

SunriseVillage_Event_Kirlia_Text_0:
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

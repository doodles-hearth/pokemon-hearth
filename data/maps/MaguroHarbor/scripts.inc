MaguroHarbor_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MaguroHarbor_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_TRANSITION, MaguroHarbor_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

MaguroHarbor_MapScripts_MAP_SCRIPT_ON_LOAD:
	call MaguroHarbor_DrawMetatiles
	return

MaguroHarbor_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_TEMP_1
	getweekday
	compare VAR_RESULT, 0
	goto_if_eq MaguroHarbor_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	compare VAR_RESULT, 3
	goto_if_eq MaguroHarbor_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	compare VAR_RESULT, 6
	goto_if_eq MaguroHarbor_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

MaguroHarbor_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	clearflag FLAG_TEMP_1
	return


MaguroHarbor_DrawMetatiles::
	gettimeofday
	switch VAR_RESULT
	case TIME_DEAD_NIGHT, MaguroHarbor_DrawMetatiles_2
	case TIME_EARLY_MORNING, MaguroHarbor_DrawMetatiles_3
	case TIME_MORNING, MaguroHarbor_DrawMetatiles_3
	case TIME_LUNCHTIME, MaguroHarbor_DrawMetatiles_3
	case TIME_AFTERNOON, MaguroHarbor_DrawMetatiles_3
	case TIME_EVENING, MaguroHarbor_DrawMetatiles_3
	case TIME_NIGHT, MaguroHarbor_DrawMetatiles_3
MaguroHarbor_DrawMetatiles_3:
	end

MaguroHarbor_DrawMetatiles_2:
	setmetatile 30, 23, METATILE_Maguro_MaguroClosedWindows, TRUE
	setmetatile 32, 22, METATILE_PorytilesPrimaryTutorial_ClosedDoorTop, TRUE
	setmetatile 32, 23, METATILE_PorytilesPrimaryTutorial_ClosedDoorBottom, TRUE
	return


MaguroHarbor_EventScript_TownSign::
	msgbox MaguroHarbor_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


MaguroHarbor_EventScript_DojoSign::
	msgbox MaguroHarbor_EventScript_DojoSign_Text_0, MSGBOX_SIGN
	return


MaguroHarbor_EventScript_PokemonNerdSign::
	msgbox MaguroHarbor_EventScript_PokemonNerdSign_Text_0, MSGBOX_SIGN
	return


MaguroHarbor_EventScript_LovestruckGirl::
	lock
	faceplayer
	speakername MaguroHarbor_EventScript_LovestruckGirl_Text_0
	msgbox MaguroHarbor_EventScript_LovestruckGirl_Text_1, MSGBOX_DEFAULT
	release
	return


MaguroHarbor_EventScript_FishcakeSalesman::
	gettimeofday
	switch VAR_RESULT
	case TIME_EARLY_MORNING, MaguroHarbor_EventScript_FishcakeSalesman_2
	case TIME_MORNING, MaguroHarbor_EventScript_FishcakeSalesman_3
	case TIME_LUNCHTIME, MaguroHarbor_EventScript_FishcakeSalesman_3
	case TIME_AFTERNOON, MaguroHarbor_EventScript_FishcakeSalesman_3
	case TIME_EVENING, MaguroHarbor_EventScript_FishcakeSalesman_3
	case TIME_NIGHT, MaguroHarbor_EventScript_FishcakeSalesman_4
	return

MaguroHarbor_EventScript_FishcakeSalesman_2:
	goto MaguroHarbor_EventScript_FishcakeSalesmanSettingUp
	return

MaguroHarbor_EventScript_FishcakeSalesman_3:
	goto MaguroHarbor_EventScript_FishcakeSalesmanSelling
	return

MaguroHarbor_EventScript_FishcakeSalesman_4:
	call StringVarSetter
	goto MaguroHarbor_EventScript_FishcakeSalesmanClosingUp
	return


MaguroHarbor_EventScript_FishcakeSalesmanSettingUp::
	lock
	faceplayer
	speakername MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_1, MSGBOX_DEFAULT
	closemessage
	release
	return


MaguroHarbor_EventScript_FishcakeSalesmanSelling::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_FISHCAKE, MaguroHarbor_EventScript_FishcakeSalesmanSelling_2
	speakername MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_1, MSGBOX_DEFAULT
	showmoneybox 18, 0
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_2, MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_3, MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_4
	closemessage
	switch VAR_RESULT
	case 0, MaguroHarbor_EventScript_FishcakeSalesmanSelling_6
	case 1, MaguroHarbor_EventScript_FishcakeSalesmanSelling_7
	case 2, MaguroHarbor_EventScript_FishcakeSalesmanSelling_8
MaguroHarbor_EventScript_FishcakeSalesmanSelling_1:
	release
	return

MaguroHarbor_EventScript_FishcakeSalesmanSelling_2:
	speakername MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_0, MSGBOX_DEFAULT
	goto MaguroHarbor_EventScript_FishcakeSalesmanSelling_1

MaguroHarbor_EventScript_FishcakeSalesmanSelling_6:
	checkmoney 500
	compare VAR_RESULT, 0
	goto_if_ne MaguroHarbor_EventScript_FishcakeSalesmanSelling_9
	speakername MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_6
	closemessage
	hidemoneybox
	goto MaguroHarbor_EventScript_FishcakeSalesmanSelling_1

MaguroHarbor_EventScript_FishcakeSalesmanSelling_7:
	hidemoneybox
	goto MaguroHarbor_EventScript_FishcakeSalesmanSelling_1

MaguroHarbor_EventScript_FishcakeSalesmanSelling_8:
	hidemoneybox
	speakername MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_7
	closemessage
	goto MaguroHarbor_EventScript_FishcakeSalesmanSelling_1

MaguroHarbor_EventScript_FishcakeSalesmanSelling_9:
	removemoney 500
	updatemoneybox
	speakername MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_5
	closemessage
	hidemoneybox
	giveitem ITEM_FISHCAKE
	goto MaguroHarbor_EventScript_FishcakeSalesmanSelling_1


MaguroHarbor_EventScript_FishcakeSalesmanClosingUp::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_FISHCAKE, MaguroHarbor_EventScript_FishcakeSalesmanClosingUp_2
	speakername MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishcakeSalesmanClosingUp_Text_1, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_FISHCAKE
	setflag FLAG_DAILY_FISHCAKE
MaguroHarbor_EventScript_FishcakeSalesmanClosingUp_1:
	release
	return

MaguroHarbor_EventScript_FishcakeSalesmanClosingUp_2:
	speakername MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishcakeSalesmanClosingUp_Text_0, MSGBOX_DEFAULT
	closemessage
	goto MaguroHarbor_EventScript_FishcakeSalesmanClosingUp_1


MaguroHarbor_EventScript_FishPokemonSalesman::
	gettimeofday
	switch VAR_RESULT
	case TIME_EARLY_MORNING, MaguroHarbor_EventScript_FishPokemonSalesman_2
	case TIME_MORNING, MaguroHarbor_EventScript_FishPokemonSalesman_3
	case TIME_LUNCHTIME, MaguroHarbor_EventScript_FishPokemonSalesman_3
	case TIME_AFTERNOON, MaguroHarbor_EventScript_FishPokemonSalesman_3
	case TIME_EVENING, MaguroHarbor_EventScript_FishPokemonSalesman_3
	case TIME_NIGHT, MaguroHarbor_EventScript_FishPokemonSalesman_4
	return

MaguroHarbor_EventScript_FishPokemonSalesman_2:
	goto MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp
	return

MaguroHarbor_EventScript_FishPokemonSalesman_3:
	goto MaguroHarbor_EventScript_FishPokemonSalesmanSelling
	return

MaguroHarbor_EventScript_FishPokemonSalesman_4:
	checkplayergender
	compare VAR_RESULT, 0
	goto_if_eq MaguroHarbor_EventScript_FishPokemonSalesman_6
	bufferstring STR_VAR_2, MaguroHarbor_EventScript_FishPokemonSalesman_Text_1
MaguroHarbor_EventScript_FishPokemonSalesman_5:
	call StringVarSetter
	goto MaguroHarbor_EventScript_FishPokemonSalesmanClosingUp
	return

MaguroHarbor_EventScript_FishPokemonSalesman_6:
	bufferstring STR_VAR_2, MaguroHarbor_EventScript_FishPokemonSalesman_Text_0
	goto MaguroHarbor_EventScript_FishPokemonSalesman_5


MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp::
	lock
	faceplayer
	speakername MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_1, MSGBOX_DEFAULT
	closemessage
	release
	return


MaguroHarbor_EventScript_FishPokemonSalesmanSelling::
	lock
	faceplayer
	speakername MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	return


MaguroHarbor_EventScript_FishPokemonSalesmanClosingUp::
	lock
	faceplayer
	speakername MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanClosingUp_Text_0
	closemessage
	release
	return


MaguroHarbor_EventScript_FishermanInBoat::
	lock
	faceplayer
	speakername MaguroHarbor_EventScript_FishermanInBoat_Text_0
	msgbox MaguroHarbor_EventScript_FishermanInBoat_Text_1, MSGBOX_DEFAULT
	closemessage
	release
	return


MaguroHarbor_EventScript_Cramorant::
	lock
	faceplayer
	setseenmon SPECIES_CRAMORANT
	playmoncry SPECIES_CRAMORANT, CRY_MODE_NORMAL
	speakername MaguroHarbor_EventScript_Cramorant_Text_0
	msgbox MaguroHarbor_EventScript_Cramorant_Text_1, MSGBOX_DEFAULT
	closemessage
	release
	return


MaguroHarbor_EventScript_FishermanOldRod::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, MaguroHarbor_EventScript_FishermanOldRod_2
	speakername MaguroHarbor_EventScript_FishermanInBoat_Text_0
	msgbox MaguroHarbor_EventScript_FishermanOldRod_Text_1
	closemessage
	giveitem ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	speakername MaguroHarbor_EventScript_FishermanInBoat_Text_0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq MaguroHarbor_EventScript_FishermanOldRod_5
	msgbox MaguroHarbor_EventScript_FishermanOldRod_Text_3
MaguroHarbor_EventScript_FishermanOldRod_4:
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return

MaguroHarbor_EventScript_FishermanOldRod_2:
	speakername MaguroHarbor_EventScript_FishermanInBoat_Text_0
	msgbox MaguroHarbor_EventScript_FishermanOldRod_Text_0
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MaguroHarbor_EventScript_FishermanOldRod_5:
	msgbox MaguroHarbor_EventScript_FishermanOldRod_Text_2
	goto MaguroHarbor_EventScript_FishermanOldRod_4


MaguroHarbor_EventScript_Man::
	lock
	faceplayer
	speakername MaguroHarbor_EventScript_Man_Text_0
	msgbox MaguroHarbor_EventScript_Man_Text_1
	closemessage
	release
	return


MaguroHarbor_EventScript_Mart::
	gettimeofday
	switch VAR_RESULT
	case TIME_EARLY_MORNING, MaguroHarbor_EventScript_Mart_2
	case TIME_MORNING, MaguroHarbor_EventScript_Mart_3
	case TIME_LUNCHTIME, MaguroHarbor_EventScript_Mart_3
	case TIME_AFTERNOON, MaguroHarbor_EventScript_Mart_3
	case TIME_EVENING, MaguroHarbor_EventScript_Mart_3
	case TIME_NIGHT, MaguroHarbor_EventScript_Mart_3
	return

MaguroHarbor_EventScript_Mart_2:
	goto MaguroHarbor_EventScript_MartSettingUp
	return

MaguroHarbor_EventScript_Mart_3:
	goto MaguroHarbor_EventScript_MartSelling
	return


MaguroHarbor_EventScript_MartSelling::
	lock
	faceplayer
	speakername MaguroHarbor_EventScript_MartSelling_Text_0
	message gText_HowMayIServeYou
	waitmessage
	pokemart MaguroHarbor_Mart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	return


MaguroHarbor_EventScript_MartSettingUp::
	lock
	faceplayer
	speakername MaguroHarbor_EventScript_MartSelling_Text_0
	msgbox MaguroHarbor_EventScript_MartSettingUp_Text_0, MSGBOX_DEFAULT
	waitmessage
	release
	return


MaguroHarbor_EventScript_MartClosingUp::
	lock
	faceplayer
	speakername MaguroHarbor_EventScript_MartSelling_Text_0
	msgbox MaguroHarbor_EventScript_MartClosingUp_Text_0, MSGBOX_DEFAULT
	waitmessage
	release
	return


StringVarSetter:
	getweekday
	switch VAR_RESULT
	case WEEKDAY_WED, StringVarSetter_2
	case WEEKDAY_SAT, StringVarSetter_3
	case WEEKDAY_SUN, StringVarSetter_4
	return

StringVarSetter_2:
	bufferstring STR_VAR_1, StringVarSetter_Text_0
	return

StringVarSetter_3:
	bufferstring STR_VAR_1, StringVarSetter_Text_1
	return

StringVarSetter_4:
	bufferstring STR_VAR_1, StringVarSetter_Text_2
	return


	.align 2
MaguroHarbor_Mart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_OINTMENT
	.2byte ITEM_SUPER_OINTMENT
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_NONE

MaguroHarbor_EventScript_TownSign_Text_0:
	.string "Maguro Harbor\n"
	.string "“A town that lives hand in hand\l"
	.string "with the sea.”$"

MaguroHarbor_EventScript_DojoSign_Text_0:
	.string "Maguro Harbor Pokémon Dojo\n"
	.string "Leader: Koishi\l"
	.string "“Smooth as a still pond,\l"
	.string "passionate as a storm!”$"

MaguroHarbor_EventScript_PokemonNerdSign_Text_0:
	.string "“Pokémon Nerd”$"

MaguroHarbor_EventScript_LovestruckGirl_Text_0:
	.string "Lovestruck Girl$"

MaguroHarbor_EventScript_LovestruckGirl_Text_1:
	.string "It's only been an hour since I saw\n"
	.string "my love, and yet I already want\l"
	.string "tomorrow to come just so I can\l"
	.string "see him again…$"

MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_0:
	.string "Old woman$"

MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_1:
	.string "Oh I'm so sorry, dearie. We haven't\n"
	.string "opened yet. Come back later!$"

MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_0:
	.string "Come back tomorrow if you'd like\n"
	.string "another fishcake!$"

MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_1:
	.string "Hello dear, want to try a\n"
	.string "fishcake?\p"
	.string "They're the town's specialty! Only\n"
	.string "500¥!$"

MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_2:
	.string "One please!$"

MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_3:
	.string "No, thanks.$"

MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_4:
	.string "Fishcakes?$"

MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_5:
	.string "One fishcake, coming right up!$"

MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_6:
	.string "Oh dear! It appears you're a little\n"
	.string "short on pocket money.$"

MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_7:
	.string "What's in the Fishcakes, you ask?\p"
	.string "Uhh… Cake!$"

MaguroHarbor_EventScript_FishcakeSalesmanClosingUp_Text_0:
	.string "I'm sorry but we've closed shop\n"
	.string "now, dearie.\p"
	.string "We'll be open again {STR_VAR_1}!$"

MaguroHarbor_EventScript_FishcakeSalesmanClosingUp_Text_1:
	.string "Oh my! I'm sorry but we've closed\n"
	.string "shop now, dearie.\p"
	.string "We'll be open again\n"
	.string "{STR_VAR_1}!\p"
	.string "Did you want to buy one of my\n"
	.string "Fishcakes?\p"
	.string "Here, you can have the leftovers\n"
	.string "from today!$"

MaguroHarbor_EventScript_FishPokemonSalesman_Text_0:
	.string "laddie$"

MaguroHarbor_EventScript_FishPokemonSalesman_Text_1:
	.string "lassie$"

MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_0:
	.string "Salesman$"

MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_1:
	.string "Aye! We're not open yet. Come back\n"
	.string "later for the fresh catch of the\l"
	.string "day.$"

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_0:
	.string "Fresh fish! Come get yer fish!$"

MaguroHarbor_EventScript_FishPokemonSalesmanClosingUp_Text_0:
	.string "Ah! You're a bit too late {STR_VAR_2}. We're\nclosed for th' day.\p"
	.string "We'll be open again\l{STR_VAR_1}.$"

MaguroHarbor_EventScript_FishermanInBoat_Text_0:
	.string "Fisherman$"

MaguroHarbor_EventScript_FishermanInBoat_Text_1:
	.string "I'm letting my fishing partner\n"
	.string "Cramorant rest for a while.$"

MaguroHarbor_EventScript_Cramorant_Text_0:
	.string "Cramorant$"

MaguroHarbor_EventScript_Cramorant_Text_1:
	.string "Craaah!$"

MaguroHarbor_EventScript_FishermanOldRod_Text_0:
	.string "Heyo, wee fisherm'n! Hope ye be\n"
	.string "enjoyin' yer fishing rod!$"

MaguroHarbor_EventScript_FishermanOldRod_Text_1:
	.string "Shush, ye fool child! You're scarin'\n"
	.string "tha wee fishes!\p"
	.string "… … … …\p"
	.string "Yer eyes… They be sparklin' with\n"
	.string "passion… Are ye by any chance an\l"
	.string "aspirin' fisherm'n?\p"
	.string "Ye are! I can feel it! I can see\n"
	.string "ye be dyin' to try it fer yerself!\p"
	.string "Now, I can't be givin' ye me loyal\n"
	.string "Cramorant here…\p"
	.string "But I can give ye this ol' rud o'\n"
	.string "mine!$"

MaguroHarbor_EventScript_FishermanOldRod_Text_2:
	.string "It be a wee bit used, but I reckon\n"
	.string "it will serve ye mighty fine!\p"
	.string "Farewell, lad! May ye become a\n"
	.string "great fisherm'n!$"

MaguroHarbor_EventScript_FishermanOldRod_Text_3:
	.string "It be a wee bit used, but I reckon\n"
	.string "it will serve ye mighty fine!\p"
	.string "Farewell, lass! May ye become a\n"
	.string "great fisherm'n!$"

MaguroHarbor_EventScript_Man_Text_0:
	.string "Man$"

MaguroHarbor_EventScript_Man_Text_1:
	.string "I wish I swam as gracefully as the\n"
	.string "Dojo's Magikarp…$"

MaguroHarbor_EventScript_MartSelling_Text_0:
	.string "Shopkeeper$"

MaguroHarbor_EventScript_MartSettingUp_Text_0:
	.string "Oh, uh, the shop isn't open yet.\n"
	.string "Come back later.$"

MaguroHarbor_EventScript_MartClosingUp_Text_0:
	.string "The shop's closed for today. Come\n"
	.string "back {STR_VAR_1}.$"

StringVarSetter_Text_0:
	.string "on Saturday$"

StringVarSetter_Text_1:
	.string "tomorrow$"

StringVarSetter_Text_2:
	.string "on Wednesday$"

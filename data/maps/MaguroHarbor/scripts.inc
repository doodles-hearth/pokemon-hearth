MaguroHarbor_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MaguroHarbor_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_TRANSITION, MaguroHarbor_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

MaguroHarbor_MapScripts_MAP_SCRIPT_ON_LOAD:
	call MaguroHarbor_DrawMetatiles
	return

MaguroHarbor_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_MAGURO_HARBOR
	getweekday
	compare VAR_RESULT, WEEKDAY_MON
	goto_if_ne MaguroHarbor_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	return

MaguroHarbor_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_TEMP_1
	return

MaguroHarbor_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	compare VAR_RESULT, WEEKDAY_FRI
	goto_if_ne MaguroHarbor_MapScripts_MAP_SCRIPT_ON_TRANSITION_6
	return

MaguroHarbor_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
	compare VAR_RESULT, WEEKDAY_WED
	goto_if_ne MaguroHarbor_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

MaguroHarbor_MapScripts_MAP_SCRIPT_ON_TRANSITION_6:
	compare VAR_RESULT, WEEKDAY_SUN
	goto_if_ne MaguroHarbor_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return


MaguroHarbor_DrawMetatiles::
	gettimeofday
	switch VAR_0x8000
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
	compare VAR_DECAY_BEACHBOUND_ROUTE, 1
	goto_if_eq MaguroHarbor_EventScript_LovestruckGirl_2
	setspeaker MaguroHarbor_EventScript_LovestruckGirl_Text_2
	msgbox MaguroHarbor_EventScript_LovestruckGirl_Text_3, MSGBOX_DEFAULT
MaguroHarbor_EventScript_LovestruckGirl_1:
	release
	return

MaguroHarbor_EventScript_LovestruckGirl_2:
	setspeaker MaguroHarbor_EventScript_LovestruckGirl_Text_0
	msgbox MaguroHarbor_EventScript_LovestruckGirl_Text_1, MSGBOX_DEFAULT
	goto MaguroHarbor_EventScript_LovestruckGirl_1


MaguroHarbor_EventScript_FishcakeSalesman::
	gettimeofday
	switch VAR_0x8000
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
	goto MaguroHarbor_EventScript_FishcakeSalesmanClosingUp
	return


MaguroHarbor_EventScript_FishcakeSalesmanSettingUp::
	lock
	faceplayer
	setspeaker MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_1, MSGBOX_DEFAULT
	closemessage
	release
	return


MaguroHarbor_EventScript_FishcakeSalesmanSelling::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_FISHCAKE, MaguroHarbor_EventScript_FishcakeSalesmanSelling_2
	setspeaker MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_1, MSGBOX_DEFAULT
	showmoneybox 18, 0
	mcdialogue MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_2, MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_3, MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_4
	closemessage
	switch VAR_RESULT
	case 0, MaguroHarbor_EventScript_FishcakeSalesmanSelling_6
	case 1, MaguroHarbor_EventScript_FishcakeSalesmanSelling_7
	case 2, MaguroHarbor_EventScript_FishcakeSalesmanSelling_8
MaguroHarbor_EventScript_FishcakeSalesmanSelling_1:
	release
	return

MaguroHarbor_EventScript_FishcakeSalesmanSelling_2:
	setspeaker MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_0, MSGBOX_DEFAULT
	goto MaguroHarbor_EventScript_FishcakeSalesmanSelling_1

MaguroHarbor_EventScript_FishcakeSalesmanSelling_6:
	checkmoney 500
	compare VAR_RESULT, 0
	goto_if_ne MaguroHarbor_EventScript_FishcakeSalesmanSelling_9
	setspeaker MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_6
	closemessage
	hidemoneybox
	goto MaguroHarbor_EventScript_FishcakeSalesmanSelling_1

MaguroHarbor_EventScript_FishcakeSalesmanSelling_7:
	hidemoneybox
	goto MaguroHarbor_EventScript_FishcakeSalesmanSelling_1

MaguroHarbor_EventScript_FishcakeSalesmanSelling_8:
	hidemoneybox
	setspeaker MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_7
	closemessage
	goto MaguroHarbor_EventScript_FishcakeSalesmanSelling_1

MaguroHarbor_EventScript_FishcakeSalesmanSelling_9:
	removemoney 500
	updatemoneybox
	setspeaker MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_5
	closemessage
	hidemoneybox
	giveitem ITEM_FISHCAKE
	goto MaguroHarbor_EventScript_FishcakeSalesmanSelling_1


MaguroHarbor_EventScript_FishcakeSalesmanClosingUp::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_FISHCAKE, MaguroHarbor_EventScript_FishcakeSalesmanClosingUp_2
	setspeaker MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishcakeSalesmanClosingUp_Text_1, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_FISHCAKE
	setflag FLAG_DAILY_FISHCAKE
MaguroHarbor_EventScript_FishcakeSalesmanClosingUp_1:
	release
	return

MaguroHarbor_EventScript_FishcakeSalesmanClosingUp_2:
	setspeaker MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishcakeSalesmanClosingUp_Text_0, MSGBOX_DEFAULT
	closemessage
	goto MaguroHarbor_EventScript_FishcakeSalesmanClosingUp_1


MaguroHarbor_EventScript_FishPokemonSalesman::
	gettimeofday
	switch VAR_0x8000
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
	call StringVarSetterFishSalesman
	goto MaguroHarbor_EventScript_FishPokemonSalesmanClosingUp
	return

MaguroHarbor_EventScript_FishPokemonSalesman_6:
	bufferstring STR_VAR_2, MaguroHarbor_EventScript_FishPokemonSalesman_Text_0
	goto MaguroHarbor_EventScript_FishPokemonSalesman_5


MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp::
	lock
	faceplayer
	setspeaker MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_0
	compare VAR_DECAY_BEACHBOUND_ROUTE, 1
	goto_if_eq MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_2
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_2, MSGBOX_DEFAULT
MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_1:
	closemessage
	release
	return

MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_2:
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_1, MSGBOX_DEFAULT
	goto MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_1


MaguroHarbor_EventScript_FishPokemonSalesmanSelling::
	lock
	faceplayer
	compare VAR_DECAY_BEACHBOUND_ROUTE, 1
	goto_if_eq MaguroHarbor_EventScript_FishPokemonSalesmanSelling_2
	setspeaker MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_0
	goto_if_set FLAG_TEMP_2, MaguroHarbor_EventScript_FishPokemonSalesmanSelling_6
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_1
MaguroHarbor_EventScript_FishPokemonSalesmanSelling_5:
	mcdialogue MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_2, MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_3
	closemessage
	switch VAR_RESULT
	case 0, MaguroHarbor_EventScript_FishPokemonSalesmanSelling_10
	case 1, MaguroHarbor_EventScript_FishPokemonSalesmanSelling_11
MaguroHarbor_EventScript_FishPokemonSalesmanSelling_1:
	setflag FLAG_TEMP_2
	release
	return

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_2:
	setspeaker MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_1
	closemessage
	goto MaguroHarbor_EventScript_FishPokemonSalesmanSelling_1

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_6:
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_0
	goto MaguroHarbor_EventScript_FishPokemonSalesmanSelling_5

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_10:
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq MaguroHarbor_EventScript_FishPokemonSalesmanSelling_12
	getpartysize
	compare VAR_RESULT, 1
	goto_if_eq MaguroHarbor_EventScript_FishPokemonSalesmanSelling_15
	callnative Native_GiveFish
	compare VAR_0x8000, 0
	goto_if_gt MaguroHarbor_EventScript_FishPokemonSalesmanSelling_18
	setspeaker MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_13
	closemessage
	goto MaguroHarbor_EventScript_FishPokemonSalesmanSelling_1

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_11:
	setspeaker MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_14
	closemessage
	goto MaguroHarbor_EventScript_FishPokemonSalesmanSelling_1

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_12:
	setspeaker MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_4
	closemessage
	goto MaguroHarbor_EventScript_FishPokemonSalesmanSelling_1

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_15:
	setspeaker MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_5
	closemessage
	goto MaguroHarbor_EventScript_FishPokemonSalesmanSelling_1

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_18:
	buffernumberstring STR_VAR_1, VAR_0x8000
	setspeaker MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_6
	mcdialogue MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_7, MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_8
	switch VAR_RESULT
	case 0, MaguroHarbor_EventScript_FishPokemonSalesmanSelling_23
	case 1, MaguroHarbor_EventScript_FishPokemonSalesmanSelling_24
MaguroHarbor_EventScript_FishPokemonSalesmanSelling_21:
	closemessage
	goto MaguroHarbor_EventScript_FishPokemonSalesmanSelling_1

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_23:
	addmoney VAR_0x8000
	special DestroySelectedPartyMon
	compare VAR_0x8001, ITEM_NONE
	goto_if_ne MaguroHarbor_EventScript_FishPokemonSalesmanSelling_25
	setspeaker MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_11
	closemessage
	goto MaguroHarbor_EventScript_FishPokemonSalesmanSelling_21

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_24:
	setspeaker MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_12
	closemessage
	goto MaguroHarbor_EventScript_FishPokemonSalesmanSelling_21

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_25:
	setspeaker MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_9
	closemessage
	giveitem VAR_0x8001
	setspeaker MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_10
	closemessage
	goto MaguroHarbor_EventScript_FishPokemonSalesmanSelling_21


MaguroHarbor_EventScript_FishPokemonSalesmanClosingUp::
	lock
	faceplayer
	setspeaker MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_0
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanClosingUp_Text_0
	closemessage
	release
	return


MaguroHarbor_EventScript_FishermanInBoat::
	lock
	faceplayer
	setspeaker MaguroHarbor_EventScript_FishermanInBoat_Text_0
	msgbox MaguroHarbor_EventScript_FishermanInBoat_Text_1, MSGBOX_DEFAULT
	closemessage
	release
	return


MaguroHarbor_EventScript_Cramorant::
	lock
	faceplayer
	setseenmon SPECIES_CRAMORANT
	playmoncry SPECIES_CRAMORANT, CRY_MODE_NORMAL
	setspeaker MaguroHarbor_EventScript_Cramorant_Text_0
	msgbox MaguroHarbor_EventScript_Cramorant_Text_1, MSGBOX_DEFAULT
	closemessage
	release
	return


MaguroHarbor_EventScript_FishermanOldRod::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, MaguroHarbor_EventScript_FishermanOldRod_2
	setspeaker MaguroHarbor_EventScript_FishermanInBoat_Text_0
	msgbox MaguroHarbor_EventScript_FishermanOldRod_Text_2
	closemessage
	giveitem ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	setspeaker MaguroHarbor_EventScript_FishermanInBoat_Text_0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq MaguroHarbor_EventScript_FishermanOldRod_5
	msgbox MaguroHarbor_EventScript_FishermanOldRod_Text_4
MaguroHarbor_EventScript_FishermanOldRod_4:
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return

MaguroHarbor_EventScript_FishermanOldRod_2:
	setspeaker MaguroHarbor_EventScript_FishermanInBoat_Text_0
	compare VAR_DECAY_BEACHBOUND_ROUTE, 1
	goto_if_eq MaguroHarbor_EventScript_FishermanOldRod_9
	msgbox MaguroHarbor_EventScript_FishermanOldRod_Text_1
MaguroHarbor_EventScript_FishermanOldRod_8:
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MaguroHarbor_EventScript_FishermanOldRod_5:
	msgbox MaguroHarbor_EventScript_FishermanOldRod_Text_3
	goto MaguroHarbor_EventScript_FishermanOldRod_4

MaguroHarbor_EventScript_FishermanOldRod_9:
	msgbox MaguroHarbor_EventScript_FishermanOldRod_Text_0, MSGBOX_AUTOCLOSE
	goto MaguroHarbor_EventScript_FishermanOldRod_8


MaguroHarbor_EventScript_Man::
	lock
	faceplayer
	setspeaker MaguroHarbor_EventScript_Man_Text_0
	compare VAR_DECAY_BEACHBOUND_ROUTE, 1
	goto_if_eq MaguroHarbor_EventScript_Man_2
	msgbox MaguroHarbor_EventScript_Man_Text_2
MaguroHarbor_EventScript_Man_1:
	closemessage
	release
	return

MaguroHarbor_EventScript_Man_2:
	applymovement VAR_LAST_TALKED, MaguroHarbor_EventScript_Man_Movement_0
	msgbox MaguroHarbor_EventScript_Man_Text_1, MSGBOX_AUTOCLOSE
	goto MaguroHarbor_EventScript_Man_1


MaguroHarbor_EventScript_Mart::
	gettimeofday
	switch VAR_0x8000
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
	setspeaker MaguroHarbor_EventScript_MartSelling_Text_0
	message MaguroHarbor_EventScript_MartSelling_Text_1
	waitmessage
	pokemart MaguroHarbor_Mart
	applymovement VAR_LAST_TALKED, MaguroHarbor_EventScript_MartSelling_Movement_0
	message MaguroHarbor_EventScript_MartSelling_Text_2
	release
	return


MaguroHarbor_EventScript_MartSettingUp::
	lock
	faceplayer
	setspeaker MaguroHarbor_EventScript_MartSelling_Text_0
	msgbox MaguroHarbor_EventScript_MartSettingUp_Text_0, MSGBOX_DEFAULT
	waitmessage
	release
	return


MaguroHarbor_EventScript_MartClosingUp::
	lock
	faceplayer
	setspeaker MaguroHarbor_EventScript_MartSelling_Text_0
	msgbox MaguroHarbor_EventScript_MartClosingUp_Text_0, MSGBOX_DEFAULT
	waitmessage
	release
	return


StringVarSetterFishSalesman:
	getweekday
	switch VAR_RESULT
	case WEEKDAY_WED, StringVarSetterFishSalesman_2
	case WEEKDAY_FRI, StringVarSetterFishSalesman_3
	case WEEKDAY_SUN, StringVarSetterFishSalesman_4
	case WEEKDAY_MON, StringVarSetterFishSalesman_5
	return

StringVarSetterFishSalesman_2:
	bufferstring STR_VAR_1, StringVarSetterFishSalesman_Text_0
	return

StringVarSetterFishSalesman_3:
	bufferstring STR_VAR_1, StringVarSetterFishSalesman_Text_1
	return

StringVarSetterFishSalesman_4:
	bufferstring STR_VAR_1, StringVarSetterFishSalesman_Text_2
	return

StringVarSetterFishSalesman_5:
	bufferstring STR_VAR_1, StringVarSetterFishSalesman_Text_3
	return


MaguroHarbor_EventScript_FishPokemonSalesmanSign::
	msgbox MaguroHarbor_EventScript_FishPokemonSalesmanSign_Text_0, MSGBOX_SIGN
	return


	.align 2
MaguroHarbor_Mart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_OINTMENT
	.2byte ITEM_SUPER_OINTMENT
	.2byte ITEM_REVIVAL_POWDER
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_NONE

MaguroHarbor_EventScript_Man_Movement_0:
	emote_sad
	step_end

MaguroHarbor_EventScript_MartSelling_Movement_0:
	emote_happy
	step_end

MaguroHarbor_EventScript_TownSign_Text_0:
	.string "Maguro Harbor\n"
	.string "“A town that lives hand in hand with\l"
	.string "the sea.”$"

MaguroHarbor_EventScript_DojoSign_Text_0:
	.string "Maguro Harbor Pokémon Dojo\n"
	.string "Leader: Koishi\l"
	.string "“Calm as a still pond,\l"
	.string "passionate as a storm!”$"

MaguroHarbor_EventScript_PokemonNerdSign_Text_0:
	.string "Pokémon Nerd$"

MaguroHarbor_EventScript_LovestruckGirl_Text_0:
	.string "Girl$"

MaguroHarbor_EventScript_LovestruckGirl_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_GIRL_1 EMOTE_NORMAL}What was that? Oh, I hope my\n"
	.string "boyfriend's okay…$"

MaguroHarbor_EventScript_LovestruckGirl_Text_2:
	.string "Lovestruck Girl$"

MaguroHarbor_EventScript_LovestruckGirl_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_GIRL_1 EMOTE_NORMAL}It's only been an hour since I saw my\n"
	.string "love, and yet I already want tomorrow\l"
	.string "to come just so I can see him again…$"

MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_0:
	.string "Old woman$"

MaguroHarbor_EventScript_FishcakeSalesmanSettingUp_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_OLD_WOMAN EMOTE_NORMAL}Oh I'm so sorry, dearie. We haven't\n"
	.string "opened yet. Come back later!$"

MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_OLD_WOMAN EMOTE_NORMAL}Come back tomorrow if you'd like\n"
	.string "another fishcake!$"

MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_OLD_WOMAN EMOTE_NORMAL}Hello dear, want to try a fishcake?\p"
	.string "They're the town's specialty! Only\n"
	.string "500¥!$"

MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_2:
	.string "One please!$"

MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_3:
	.string "No, thanks.$"

MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_4:
	.string "Fishcakes?$"

MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_5:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_OLD_WOMAN EMOTE_NORMAL}One fishcake, coming right up!$"

MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_6:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_OLD_WOMAN EMOTE_NORMAL}Oh dear! It appears you're a little\n"
	.string "short on pocket money.$"

MaguroHarbor_EventScript_FishcakeSalesmanSelling_Text_7:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_OLD_WOMAN EMOTE_NORMAL}What's in the Fishcakes, you ask?\p"
	.string "Uhh… Cake!$"

MaguroHarbor_EventScript_FishcakeSalesmanClosingUp_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_OLD_WOMAN EMOTE_NORMAL}I'm sorry but we've closed shop now,\n"
	.string "dearie.\l"
	.string "Come back tomorrow!$"

MaguroHarbor_EventScript_FishcakeSalesmanClosingUp_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_OLD_WOMAN EMOTE_NORMAL}Oh my! I'm sorry but we've closed shop\n"
	.string "now, dearie.\l"
	.string "Come back tomorrow!\p"
	.string "Did you want to buy one of my\n"
	.string "Fishcakes?\p"
	.string "Here, you can have the leftovers from\n"
	.string "today!$"

MaguroHarbor_EventScript_FishPokemonSalesman_Text_0:
	.string "laddie$"

MaguroHarbor_EventScript_FishPokemonSalesman_Text_1:
	.string "lassie$"

MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_0:
	.string "Salesman$"

MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_1:
	.string "Just saw Master Koishi run toward\n"
	.string "Beachbound Route!\p"
	.string "She's so concerned with the safety of\n"
	.string "the village!$"

MaguroHarbor_EventScript_FishPokemonSalesmanSettingUp_Text_2:
	.string "Aye! We're not open yet. Come back\n"
	.string "later for the fresh catch of the day.$"

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_0:
	.string "Fresh fish! Come get yer fish!\p"
	.string "Have any fresh fish for me?$"

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_1:
	.string "Fresh fish! Come get yer fish!\p"
	.string "Hullo there, kid.\n"
	.string "I buy and sell fish for a livin'.\p"
	.string "Wanna make a quick buck?\n"
	.string "Bring me any fish Pokémon you find!\p"
	.string "I'll give you a fair price.\n"
	.string "And if they happen to be holdin'\l"
	.string "something in their mouth, it's all\l"
	.string "yours!\p"
	.string "What do you say?\n"
	.string "Have any fresh fish for me?$"

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_2:
	.string "Here's a fish!$"

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_3:
	.string "Sorry, no fish.$"

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_4:
	.string "Ah c'mon, don't waste my time!$"

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_5:
	.string "I'd feel bad leaving a Wielder with no\n"
	.string "Pokémon!$"

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_6:
	.string "I can offer you {STR_VAR_1}¥.\n"
	.string "That reasonable?$"

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_7:
	.string "Yes!$"

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_8:
	.string "Actually, no.$"

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_9:
	.string "Great! Here you go.\p"
	.string "…Oh?\p"
	.string "Look what we found in its mouth!\n"
	.string "Take it, it's yours!$"

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_10:
	.string "Pleasure doin' business.\p"
	.string "Come back tomorrow to trade some\n"
	.string "more!$"

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_11:
	.string "Great! Here you go.\n"
	.string "Pleasure doin' business!$"

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_12:
	.string "Nevermind then. Have yer fish back.$"

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_13:
	.string "Nuh-huh, can't buy that.\n"
	.string "I only deal in fish.$"

MaguroHarbor_EventScript_FishPokemonSalesmanSelling_Text_14:
	.string "If you find any good fish, you know\n"
	.string "where to find me!$"

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
	.string "That tremblin' nearly made me wee me\n"
	.string "pants!$"

MaguroHarbor_EventScript_FishermanOldRod_Text_1:
	.string "Heyo, wee fisherm'n! Hope ye be\n"
	.string "enjoyin' yer fishing rod!$"

MaguroHarbor_EventScript_FishermanOldRod_Text_2:
	.string "Shush, ye fool child! You're scarin'\n"
	.string "tha wee fishes!\p"
	.string "… … … …\p"
	.string "Yer eyes… They be sparklin' with\n"
	.string "passion… Are ye by any chance an\l"
	.string "aspirin' fisherm'n?\p"
	.string "Ye are! I can feel it! I can see ye be\n"
	.string "dyin' to try it fer yerself!\p"
	.string "Now, I can't be givin' ye me loyal\n"
	.string "Cramorant here…\p"
	.string "But I can give ye this ol' rud o' mine!$"

MaguroHarbor_EventScript_FishermanOldRod_Text_3:
	.string "It be a wee bit used, but I reckon it\n"
	.string "will serve ye mighty fine!\p"
	.string "Farewell, lad! May ye become a great\n"
	.string "fisherm'n!$"

MaguroHarbor_EventScript_FishermanOldRod_Text_4:
	.string "It be a wee bit used, but I reckon it\n"
	.string "will serve ye mighty fine!\p"
	.string "Farewell, lass! May ye become a great\n"
	.string "fisherm'n!$"

MaguroHarbor_EventScript_Man_Text_0:
	.string "Man$"

MaguroHarbor_EventScript_Man_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_MAN_2 EMOTE_NORMAL}T-This was the biggest quake we've\n"
	.string "felt yet!$"

MaguroHarbor_EventScript_Man_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_MAN_2 EMOTE_NORMAL}I wish I swam as gracefully as the\n"
	.string "Dojo's Magikarp…$"

MaguroHarbor_EventScript_MartSelling_Text_0:
	.string "Shopkeeper$"

MaguroHarbor_EventScript_MartSelling_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_CLERK EMOTE_NORMAL}Hello, welcome to the Maguro Harbor\n"
	.string "market!$"

MaguroHarbor_EventScript_MartSelling_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_CLERK EMOTE_NORMAL}Come back soon!$"

MaguroHarbor_EventScript_MartSettingUp_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_CLERK EMOTE_NORMAL}Oh, uh, the shop isn't open yet. Come\n"
	.string "back later!$"

MaguroHarbor_EventScript_MartClosingUp_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_CLERK EMOTE_NORMAL}The shop's closed for today. Come\n"
	.string "back {STR_VAR_1}!$"

StringVarSetterFishSalesman_Text_0:
	.string "on Friday$"

StringVarSetterFishSalesman_Text_1:
	.string "on Sunday$"

StringVarSetterFishSalesman_Text_2:
	.string "tomorrow$"

StringVarSetterFishSalesman_Text_3:
	.string "on Wednesday$"

MaguroHarbor_EventScript_FishPokemonSalesmanSign_Text_0:
	.string "We buy Fish Pokémon!\n"
	.string "Monday, Wednesday, Friday, Sunday\n"
	.string "$"

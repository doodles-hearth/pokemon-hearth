YifuCity_Refuge_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, YifuCity_Refuge_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

YifuCity_Refuge_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_TRADE_NUMEL_COMPLETED, YifuCity_Refuge_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	setflag FLAG_TEMP_1
YifuCity_Refuge_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	goto_if_unset FLAG_CLEARED_CROBAT_HIDEOUT, YifuCity_Refuge_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_6
YifuCity_Refuge_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
	goto_if_unset FLAG_MET_TRAVELING_MERCHANT_2ND_TIME, YifuCity_Refuge_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
	return

YifuCity_Refuge_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setflag FLAG_TEMP_3
	goto YifuCity_Refuge_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

YifuCity_Refuge_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_6:
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_3
	goto YifuCity_Refuge_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_5

YifuCity_Refuge_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
	setflag FLAG_TEMP_2
	return


YifuCity_Refuge_2F_EventScript_Sleep::
	lockall
	msgbox YifuCity_Refuge_2F_EventScript_Sleep_Text_0
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_Refuge_2F_EventScript_Sleep_Text_1, YifuCity_Refuge_2F_EventScript_Sleep_Text_2, YifuCity_Refuge_2F_EventScript_Sleep_Text_3
	closemessage
	switch VAR_RESULT
	case 0, YifuCity_Refuge_2F_EventScript_Sleep_3
	case 1, YifuCity_Refuge_2F_EventScript_Sleep_4
YifuCity_Refuge_2F_EventScript_Sleep_1:
	releaseall
	return

YifuCity_Refuge_2F_EventScript_Sleep_3:
	fadescreenswapbuffers FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	fwdtime 8, 0
	fadescreenswapbuffers FADE_FROM_BLACK
	goto YifuCity_Refuge_2F_EventScript_Sleep_1

YifuCity_Refuge_2F_EventScript_Sleep_4:
	fadescreenswapbuffers FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	fwdtime 22, 0
	fadescreenswapbuffers FADE_FROM_BLACK
	goto YifuCity_Refuge_2F_EventScript_Sleep_1


YifuCity_Refuge_2F_EventScript_NumelTrade::
	lock
	faceplayer
	goto_if_set FLAG_TRADE_NUMEL_COMPLETED, YifuCity_Refuge_2F_EventScript_NumelTrade_2
	setvar VAR_0x8008, INGAME_TRADE_NUMEL
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox YifuCity_Refuge_2F_EventScript_NumelTrade_Text_1
	mcdialogue YifuCity_Refuge_2F_EventScript_NumelTrade_Text_2, YifuCity_Refuge_2F_EventScript_NumelTrade_Text_3
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_Refuge_2F_EventScript_NumelTrade_5
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq YifuCity_Refuge_2F_EventScript_NumelTrade_8
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne YifuCity_Refuge_2F_EventScript_NumelTrade_11
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	setflag FLAG_TRADE_NUMEL_COMPLETED
	clearflag FLAG_TEMP_1
	removeobject LOCALID_TRADE_NUMEL
	waitstate
	addobject LOCALID_TRADE_HERACROSS
	playse SE_PIN
	applymovement VAR_LAST_TALKED, YifuCity_Refuge_2F_EventScript_NumelTrade_Movement_0
	msgbox YifuCity_Refuge_2F_EventScript_NumelTrade_Text_6, MSGBOX_DEFAULT
	closemessage
YifuCity_Refuge_2F_EventScript_NumelTrade_1:
	release
	return

YifuCity_Refuge_2F_EventScript_NumelTrade_2:
	setspeaker SP_NAME_GIRL
	msgbox YifuCity_Refuge_2F_EventScript_NumelTrade_Text_0
	closemessage
	goto YifuCity_Refuge_2F_EventScript_NumelTrade_1

YifuCity_Refuge_2F_EventScript_NumelTrade_5:
	playse SE_PIN
	applymovement VAR_LAST_TALKED, YifuCity_Refuge_2F_EventScript_NumelTrade_Movement_0
	msgbox YifuCity_Refuge_2F_EventScript_NumelTrade_Text_4
	closemessage
	goto YifuCity_Refuge_2F_EventScript_NumelTrade_1

YifuCity_Refuge_2F_EventScript_NumelTrade_8:
	playse SE_PIN
	applymovement VAR_LAST_TALKED, YifuCity_Refuge_2F_EventScript_NumelTrade_Movement_0
	msgbox YifuCity_Refuge_2F_EventScript_NumelTrade_Text_4
	closemessage
	goto YifuCity_Refuge_2F_EventScript_NumelTrade_1

YifuCity_Refuge_2F_EventScript_NumelTrade_11:
	msgbox YifuCity_Refuge_2F_EventScript_NumelTrade_Text_5
	closemessage
	goto YifuCity_Refuge_2F_EventScript_NumelTrade_1


YifuCity_Refuge_2F_EventScript_Numel::
	lock
	faceplayer
	setseenmon SPECIES_NUMEL
	setspeakertomonname SPECIES_NUMEL
	playmoncry SPECIES_NUMEL, CRY_MODE_NORMAL
	msgbox YifuCity_Refuge_2F_EventScript_Numel_Text_0
	waitmoncry
	release
	return


YifuCity_Refuge_2F_EventScript_Heracross::
	lock
	faceplayer
	setseenmon SPECIES_HERACROSS
	setspeakertomonname SPECIES_HERACROSS
	playmoncry SPECIES_HERACROSS, CRY_MODE_NORMAL
	msgbox YifuCity_Refuge_2F_EventScript_Heracross_Text_0
	waitmoncry
	release
	return


YifuCity_Refuge_2F_EventScript_TravelingMerchant::
	lock
	faceplayer
	setspeaker SP_NAME_OKADA
	msgbox YifuCity_Refuge_2F_EventScript_TravelingMerchant_Text_0
	closemessage
	release
	return


YifuCity_Refuge_2F_EventScript_Tourist::
	lock
	faceplayer
	setspeaker SP_NAME_WOMAN
	msgbox YifuCity_Refuge_2F_EventScript_Tourist_Text_0
	closemessage
	release
	return


YifuCity_Refuge_2F_EventScript_TouristKid::
	lock
	faceplayer
	setspeaker SP_NAME_LITTLE_BOY
	msgbox YifuCity_Refuge_2F_EventScript_TouristKid_Text_0
	closemessage
	release
	return


YifuCity_Refuge_2F_EventScript_TouristGirl::
	lock
	faceplayer
	waitse
	playse SE_PIN
	applymovement VAR_LAST_TALKED, YifuCity_Refuge_2F_EventScript_TouristGirl_Movement_0
	setspeaker SP_NAME_GIRL
	msgbox YifuCity_Refuge_2F_EventScript_TouristGirl_Text_0
	closemessage
	release
	return


YifuCity_Refuge_2F_EventScript_Castform::
	lock
	faceplayer
	setseenmon SPECIES_CASTFORM
	setspeakertomonname SPECIES_CASTFORM
	playmoncry SPECIES_CASTFORM, CRY_MODE_NORMAL
	msgbox YifuCity_Refuge_2F_EventScript_Castform_Text_0
	waitmoncry
	release
	return


YifuCity_Refuge_2F_EventScript_NumelTrade_Movement_0:
	emote_happy
	step_end

YifuCity_Refuge_2F_EventScript_TouristGirl_Movement_0:
	emote_angry
	step_end

YifuCity_Refuge_2F_EventScript_Sleep_Text_0:
	.string "It's a soft feather bed…\n"
	.string "Rest a while?$"

YifuCity_Refuge_2F_EventScript_Sleep_Text_1:
	.string "Sleep until morning.$"

YifuCity_Refuge_2F_EventScript_Sleep_Text_2:
	.string "Sleep until nighttime.$"

YifuCity_Refuge_2F_EventScript_Sleep_Text_3:
	.string "I'm not tired.$"

YifuCity_Refuge_2F_EventScript_NumelTrade_Text_0:
	.string "Heracross is so fascinating!$"

YifuCity_Refuge_2F_EventScript_NumelTrade_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_HOT_GIRL_2 EMOTE_NORMAL}{SPEAKER NAME_GIRL} A visitor, hi, pleased to meet you!!\n"
	.string "You have such pretty Pokémon!\p"
	.string "I brought Numel from my home, hoping\n"
	.string "to trade it for a local Heracross.\p"
	.string "What do you say? Want to trade a\n"
	.string "Heracross for my Numel?$"

YifuCity_Refuge_2F_EventScript_NumelTrade_Text_2:
	.string "With pleasure!$"

YifuCity_Refuge_2F_EventScript_NumelTrade_Text_3:
	.string "Not interested.$"

YifuCity_Refuge_2F_EventScript_NumelTrade_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_HOT_GIRL_2 EMOTE_NORMAL}{SPEAKER NAME_GIRL} It's okay. I'll hang out with Numel for\n"
	.string "a while!$"

YifuCity_Refuge_2F_EventScript_NumelTrade_Text_5:
	.string "{CREATE_MUGSHOT MUGSHOT_HOT_GIRL_2 EMOTE_NORMAL}{SPEAKER NAME_GIRL} I'm sure your Pokémon is very nice,\n"
	.string "but I'm looking for a Heracross!$"

YifuCity_Refuge_2F_EventScript_NumelTrade_Text_6:
	.string "{CREATE_MUGSHOT MUGSHOT_HOT_GIRL_2 EMOTE_NORMAL}{SPEAKER NAME_GIRL} Woah!\n"
	.string "It's bigger than I thought! Amazing!!\p"
	.string "Please, take good care of my girl Luo\n"
	.string "Luo, okay?$"

YifuCity_Refuge_2F_EventScript_Numel_Text_0:
	.string "Whoop!$"

YifuCity_Refuge_2F_EventScript_Heracross_Text_0:
	.string "Aaay!$"

YifuCity_Refuge_2F_EventScript_TravelingMerchant_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_OKADA EMOTE_NORMAL}Oh, good evening, {PLAYER}! I'm\n"
	.string "exhausted! I've been walking since\l"
	.string "morning, I'm calling it a day.\p"
	.string "Never underestimate a good night's\n"
	.string "sleep!$"

YifuCity_Refuge_2F_EventScript_Tourist_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_WOMAN_1 EMOTE_NORMAL}I'm so glad we're able to spend our\n"
	.string "vacation here.$"

YifuCity_Refuge_2F_EventScript_TouristKid_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_LITTLE_BOY EMOTE_NORMAL}We went to see the Dojo's dancers\n"
	.string "today!$"

YifuCity_Refuge_2F_EventScript_TouristGirl_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_GIRL_1 EMOTE_NORMAL}Ughh, I have to share the bed with my\n"
	.string "baby brother…\p"
	.string "Life is SO unfair!$"

YifuCity_Refuge_2F_EventScript_Castform_Text_0:
	.string "Blrblblbl…$"

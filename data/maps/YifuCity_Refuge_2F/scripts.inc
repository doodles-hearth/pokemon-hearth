YifuCity_Refuge_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, YifuCity_Refuge_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

YifuCity_Refuge_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_unset FLAG_TRADE_NUMEL_COMPLETED, YifuCity_Refuge_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

YifuCity_Refuge_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_TEMP_1
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
	speakername YifuCity_Refuge_2F_EventScript_NumelTrade_Text_0
	msgbox YifuCity_Refuge_2F_EventScript_NumelTrade_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq YifuCity_Refuge_2F_EventScript_NumelTrade_5
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq YifuCity_Refuge_2F_EventScript_NumelTrade_5
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq YifuCity_Refuge_2F_EventScript_NumelTrade_10
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne YifuCity_Refuge_2F_EventScript_NumelTrade_13
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	setflag FLAG_TRADE_NUMEL_COMPLETED
	clearflag FLAG_TEMP_1
	removeobject LOCALID_TRADE_NUMEL
	waitstate
	addobject LOCALID_TRADE_HERACROSS
	msgbox YifuCity_Refuge_2F_EventScript_NumelTrade_Text_5, MSGBOX_DEFAULT
	closemessage
YifuCity_Refuge_2F_EventScript_NumelTrade_1:
	release
	return

YifuCity_Refuge_2F_EventScript_NumelTrade_2:
	speakername YifuCity_Refuge_2F_EventScript_NumelTrade_Text_0
	msgbox YifuCity_Refuge_2F_EventScript_NumelTrade_Text_1
	closemessage
	goto YifuCity_Refuge_2F_EventScript_NumelTrade_1

YifuCity_Refuge_2F_EventScript_NumelTrade_5:
	speakername YifuCity_Refuge_2F_EventScript_NumelTrade_Text_0
	msgbox YifuCity_Refuge_2F_EventScript_NumelTrade_Text_3
	closemessage
	goto YifuCity_Refuge_2F_EventScript_NumelTrade_1

YifuCity_Refuge_2F_EventScript_NumelTrade_10:
	speakername YifuCity_Refuge_2F_EventScript_NumelTrade_Text_0
	msgbox YifuCity_Refuge_2F_EventScript_NumelTrade_Text_3
	closemessage
	goto YifuCity_Refuge_2F_EventScript_NumelTrade_1

YifuCity_Refuge_2F_EventScript_NumelTrade_13:
	speakername YifuCity_Refuge_2F_EventScript_NumelTrade_Text_0
	msgbox YifuCity_Refuge_2F_EventScript_NumelTrade_Text_4
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
	speakername YifuCity_Refuge_2F_EventScript_TravelingMerchant_Text_0
	msgbox YifuCity_Refuge_2F_EventScript_TravelingMerchant_Text_1
	closemessage
	release
	return


YifuCity_Refuge_2F_EventScript_Tourist::
	lock
	faceplayer
	speakername YifuCity_Refuge_2F_EventScript_Tourist_Text_0
	msgbox YifuCity_Refuge_2F_EventScript_Tourist_Text_1
	closemessage
	release
	return


YifuCity_Refuge_2F_EventScript_TouristKid::
	lock
	faceplayer
	speakername YifuCity_Refuge_2F_EventScript_TouristKid_Text_0
	msgbox YifuCity_Refuge_2F_EventScript_TouristKid_Text_1
	closemessage
	release
	return


YifuCity_Refuge_2F_EventScript_TouristGirl::
	lock
	faceplayer
	speakername YifuCity_Refuge_2F_EventScript_NumelTrade_Text_0
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
	.string "Girl$"

YifuCity_Refuge_2F_EventScript_NumelTrade_Text_1:
	.string "Heracross is so fascinating!$"

YifuCity_Refuge_2F_EventScript_NumelTrade_Text_2:
	.string "A visitor, hi, pleased to meet you!!\p"
	.string "You have such pretty Pokémon!\n"
	.string "I brought a Numel from my home, hoping\l"
	.string "to trade it for a local Heracross.\p"
	.string "What do you say? Want to trade a\n"
	.string "Heracross for my Numel?$"

YifuCity_Refuge_2F_EventScript_NumelTrade_Text_3:
	.string "It's okay. I'll hang out with my Numel\n"
	.string "for a while!$"

YifuCity_Refuge_2F_EventScript_NumelTrade_Text_4:
	.string "I'm sure your Pokémon is very nice,\n"
	.string "but I'm looking for a Heracross!$"

YifuCity_Refuge_2F_EventScript_NumelTrade_Text_5:
	.string "Woah!\n"
	.string "It's bigger than I thought! Amazing!!\p"
	.string "Please, take good care of my girl Luo\n"
	.string "Luo, okay?$"

YifuCity_Refuge_2F_EventScript_Numel_Text_0:
	.string "Whoop!$"

YifuCity_Refuge_2F_EventScript_Heracross_Text_0:
	.string "Aaay!$"

YifuCity_Refuge_2F_EventScript_TravelingMerchant_Text_0:
	.string "Okada$"

YifuCity_Refuge_2F_EventScript_TravelingMerchant_Text_1:
	.string "Oh, good evening, {PLAYER}! I'm\n"
	.string "exhausted! I've been walking since\l"
	.string "morning, I'm calling it a day.\p"
	.string "Never underestimate a good night's\n"
	.string "sleep!$"

YifuCity_Refuge_2F_EventScript_Tourist_Text_0:
	.string "Woman$"

YifuCity_Refuge_2F_EventScript_Tourist_Text_1:
	.string "I'm so glad we're able to spend our\n"
	.string "vacation here.$"

YifuCity_Refuge_2F_EventScript_TouristKid_Text_0:
	.string "Little Boy$"

YifuCity_Refuge_2F_EventScript_TouristKid_Text_1:
	.string "We went to see the Dojo's dancers\n"
	.string "today!$"

YifuCity_Refuge_2F_EventScript_TouristGirl_Text_0:
	.string "Ughh, I have to share the bed with my\n"
	.string "baby brother…\p"
	.string "Life is SO unfair!$"

YifuCity_Refuge_2F_EventScript_Castform_Text_0:
	.string "Blrblblbl…$"

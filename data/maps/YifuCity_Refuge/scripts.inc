YifuCity_Refuge_MapScripts::
	.byte 0


YifuCity_Refuge_EventScript_FakeNurse::
	setvar VAR_0x800B, 1
	lock
	faceplayer
	setvar VAR_0x8004, 0
	speakername YifuCity_Refuge_EventScript_FakeNurse_Text_0
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_1
	closemessage
	incrementgamestat GAME_STAT_USED_POKECENTER
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	speakername YifuCity_Refuge_EventScript_FakeNurse_Text_0
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_2
	closemessage
	end


YifuCity_Refuge_EventScript_Woobat::
	lock
	setseenmon SPECIES_WOOBAT
	playmoncry SPECIES_WOOBAT, CRY_MODE_NORMAL
	speakername YifuCity_Refuge_EventScript_Woobat_Text_0
	msgbox YifuCity_Refuge_EventScript_Woobat_Text_1
	waitse
	closemessage
	release
	return


YifuCity_Refuge_EventScript_Shamisen::
	lock
	faceplayer
	speakername YifuCity_Refuge_EventScript_Shamisen_Text_0
	msgbox YifuCity_Refuge_EventScript_Shamisen_Text_1
	closemessage
	release
	end


YifuCity_Refuge_EventScript_HotelValet::
	lock
	faceplayer
	special GetPlayerSirMissString
	speakername YifuCity_Refuge_EventScript_HotelValet_Text_0
	msgbox YifuCity_Refuge_EventScript_HotelValet_Text_1
	showmoneybox 18, 0
	checkmoney 500
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_Refuge_EventScript_HotelValet_2
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_Refuge_EventScript_HotelValet_Text_7
	closemessage
	speakername YifuCity_Refuge_EventScript_HotelValet_Text_0
	msgbox YifuCity_Refuge_EventScript_HotelValet_Text_8
	closemessage
YifuCity_Refuge_EventScript_HotelValet_1:
	release
	return

YifuCity_Refuge_EventScript_HotelValet_2:
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_Refuge_EventScript_HotelValet_Text_2, YifuCity_Refuge_EventScript_HotelValet_Text_3
	closemessage
	switch VAR_RESULT
	case 0, YifuCity_Refuge_EventScript_HotelValet_6
	case 1, YifuCity_Refuge_EventScript_HotelValet_7
	goto YifuCity_Refuge_EventScript_HotelValet_1

YifuCity_Refuge_EventScript_HotelValet_6:
	speakername YifuCity_Refuge_EventScript_HotelValet_Text_0
	msgbox YifuCity_Refuge_EventScript_HotelValet_Text_4
	removemoney 500
	updatemoneybox
	closemessage
	giveitem ITEM_REFUGE_ROOM_KEY
	hidemoneybox
	msgbox YifuCity_Refuge_EventScript_HotelValet_Text_5
	closemessage
	goto YifuCity_Refuge_EventScript_HotelValet_1

YifuCity_Refuge_EventScript_HotelValet_7:
	speakername YifuCity_Refuge_EventScript_HotelValet_Text_0
	msgbox YifuCity_Refuge_EventScript_HotelValet_Text_6
	closemessage
	goto YifuCity_Refuge_EventScript_HotelValet_1


YifuCity_Refuge_EventScript_ListenToShamisen::
	return


YifuCity_Refuge_EventScript_Traveler::
	lock
	faceplayer
	speakername YifuCity_Refuge_EventScript_Traveler_Text_0
	msgbox YifuCity_Refuge_EventScript_Traveler_Text_1
	closemessage
	release
	end


YifuCity_Refuge_EventScript_Bisharp::
	lock
	faceplayer
	setseenmon SPECIES_BISHARP
	playmoncry SPECIES_BISHARP, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_BISHARP
	msgbox YifuCity_Refuge_EventScript_Bisharp_Text_0
	waitmoncry
	closemessage
	release
	return


YifuCity_Refuge_EventScript_FakeNurse_Text_0:
	.string "Nurse$"

YifuCity_Refuge_EventScript_FakeNurse_Text_1:
	.string "Gimme yer Pokémon, I'mma heal 'em\n"
	.string "good.$"

YifuCity_Refuge_EventScript_FakeNurse_Text_2:
	.string "Yep, uh, good as new, probably!\p"
	.string "C'magain, or whatever.$"

YifuCity_Refuge_EventScript_Woobat_Text_0:
	.string "Chansey?$"

YifuCity_Refuge_EventScript_Woobat_Text_1:
	.string "Rrrrr!$"

YifuCity_Refuge_EventScript_Shamisen_Text_0:
	.string "Shamisen player$"

YifuCity_Refuge_EventScript_Shamisen_Text_1:
	.string "Good evening, traveler.\p"
	.string "I hope my song will soothe your spirit,\n"
	.string "should it be troubled.$"

YifuCity_Refuge_EventScript_HotelValet_Text_0:
	.string "Valet$"

YifuCity_Refuge_EventScript_HotelValet_Text_1:
	.string "Good morning, {STR_VAR_1}! There's\n"
	.string "a room available for ¥500, if you need\l"
	.string "a place to spend the night!$"

YifuCity_Refuge_EventScript_HotelValet_Text_2:
	.string "One room, please.$"

YifuCity_Refuge_EventScript_HotelValet_Text_3:
	.string "No, thanks.$"

YifuCity_Refuge_EventScript_HotelValet_Text_4:
	.string "For sure. That'll be ¥500!$"

YifuCity_Refuge_EventScript_HotelValet_Text_5:
	.string "Your room is the first one down the\n"
	.string "corridor! We hope you have a pleasant\l"
	.string "stay!$"

YifuCity_Refuge_EventScript_HotelValet_Text_6:
	.string "Have a nice day!$"

YifuCity_Refuge_EventScript_HotelValet_Text_7:
	.string "I'm poor…$"

YifuCity_Refuge_EventScript_HotelValet_Text_8:
	.string "Oh my, it appears you don't have\n"
	.string "enough money…\p"
	.string "I'm sorry!$"

YifuCity_Refuge_EventScript_Traveler_Text_0:
	.string "Traveler$"

YifuCity_Refuge_EventScript_Traveler_Text_1:
	.string "I come from a place high up in the\n"
	.string "mountains, where the Pokémon are as\l"
	.string "tough as the rocky landscape.$"

YifuCity_Refuge_EventScript_Bisharp_Text_0:
	.string "Kshhh.$"

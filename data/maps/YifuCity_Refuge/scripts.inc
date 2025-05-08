YifuCity_Refuge_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, YifuCity_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

YifuCity_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_YIFU_CITY
	goto_if_unset FLAG_CLEARED_CROBAT_HIDEOUT, YifuCity_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

YifuCity_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_TEMP_1
	return


YifuCity_Refuge_EventScript_Nurse::
	setvar VAR_0x800B, 10
	call Common_EventScript_PkmnCenterNurse_CutTheBullshit
	waitmessage
	waitbuttonpress
	release
	end


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
	goto_if_set FLAG_GOT_SCAMMED_YIFU_REFUGE, YifuCity_Refuge_EventScript_FakeNurse_2
	setflag FLAG_GOT_SCAMMED_YIFU_REFUGE
	speakername YifuCity_Refuge_EventScript_FakeNurse_Text_0
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_5
	showmoneybox 18, 0
	mcdialogue YifuCity_Refuge_EventScript_FakeNurse_Text_6, YifuCity_Refuge_EventScript_FakeNurse_Text_7, YifuCity_Refuge_EventScript_FakeNurse_Text_8
	closemessage
	switch VAR_RESULT
	case 0, YifuCity_Refuge_EventScript_FakeNurse_9
	case 1, YifuCity_Refuge_EventScript_FakeNurse_9
	case 2, YifuCity_Refuge_EventScript_FakeNurse_10
YifuCity_Refuge_EventScript_FakeNurse_1:
	hidemoneybox
	closemessage
	return

YifuCity_Refuge_EventScript_FakeNurse_2:
	showmoneybox 18, 0
	checkmoney 500
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_Refuge_EventScript_FakeNurse_5
	speakername YifuCity_Refuge_EventScript_FakeNurse_Text_0
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_4
	goto YifuCity_Refuge_EventScript_FakeNurse_1

YifuCity_Refuge_EventScript_FakeNurse_5:
	speakername YifuCity_Refuge_EventScript_FakeNurse_Text_0
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_2
	playse SE_SHOP
	removemoney 500
	updatemoneybox
	speakername YifuCity_Refuge_EventScript_FakeNurse_Text_0
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_3
	goto YifuCity_Refuge_EventScript_FakeNurse_1

YifuCity_Refuge_EventScript_FakeNurse_9:
	checkmoney 500
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_Refuge_EventScript_FakeNurse_11
	speakername YifuCity_Refuge_EventScript_FakeNurse_Text_0
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_10
	goto YifuCity_Refuge_EventScript_FakeNurse_1

YifuCity_Refuge_EventScript_FakeNurse_10:
	checkmoney 500
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_Refuge_EventScript_FakeNurse_14
	speakername YifuCity_Refuge_EventScript_FakeNurse_Text_0
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_12
	goto YifuCity_Refuge_EventScript_FakeNurse_1

YifuCity_Refuge_EventScript_FakeNurse_11:
	speakername YifuCity_Refuge_EventScript_FakeNurse_Text_0
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_9
	playse SE_SHOP
	removemoney 500
	updatemoneybox
	speakername YifuCity_Refuge_EventScript_FakeNurse_Text_0
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_3
	goto YifuCity_Refuge_EventScript_FakeNurse_1

YifuCity_Refuge_EventScript_FakeNurse_14:
	speakername YifuCity_Refuge_EventScript_FakeNurse_Text_0
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_11
	playse SE_SHOP
	removemoney 500
	updatemoneybox
	speakername YifuCity_Refuge_EventScript_FakeNurse_Text_0
	msgbox YifuCity_Refuge_EventScript_FakeNurse_Text_3
	goto YifuCity_Refuge_EventScript_FakeNurse_1


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
	mcdialogue YifuCity_Refuge_EventScript_HotelValet_Text_7
	closemessage
	hidemoneybox
	speakername YifuCity_Refuge_EventScript_HotelValet_Text_0
	msgbox YifuCity_Refuge_EventScript_HotelValet_Text_8
	closemessage
YifuCity_Refuge_EventScript_HotelValet_1:
	release
	return

YifuCity_Refuge_EventScript_HotelValet_2:
	mcdialogue YifuCity_Refuge_EventScript_HotelValet_Text_2, YifuCity_Refuge_EventScript_HotelValet_Text_3
	closemessage
	switch VAR_RESULT
	case 0, YifuCity_Refuge_EventScript_HotelValet_6
	case 1, YifuCity_Refuge_EventScript_HotelValet_7
	goto YifuCity_Refuge_EventScript_HotelValet_1

YifuCity_Refuge_EventScript_HotelValet_6:
	speakername YifuCity_Refuge_EventScript_HotelValet_Text_0
	msgbox YifuCity_Refuge_EventScript_HotelValet_Text_4
	playse SE_SHOP
	removemoney 500
	updatemoneybox
	closemessage
	giveitem ITEM_REFUGE_ROOM_KEY
	hidemoneybox
	speakername YifuCity_Refuge_EventScript_HotelValet_Text_0
	msgbox YifuCity_Refuge_EventScript_HotelValet_Text_5
	closemessage
	goto YifuCity_Refuge_EventScript_HotelValet_1

YifuCity_Refuge_EventScript_HotelValet_7:
	hidemoneybox
	speakername YifuCity_Refuge_EventScript_HotelValet_Text_0
	msgbox YifuCity_Refuge_EventScript_HotelValet_Text_6
	closemessage
	goto YifuCity_Refuge_EventScript_HotelValet_1


YifuCity_Refuge_EventScript_ListenToShamisen::
	lock
	faceplayer
	speakername YifuCity_Refuge_EventScript_ListenToShamisen_Text_0
	msgbox YifuCity_Refuge_EventScript_ListenToShamisen_Text_1
	closemessage
	release
	end


YifuCity_Refuge_EventScript_Traveler::
	lock
	faceplayer
	speakername YifuCity_Refuge_EventScript_Traveler_Text_0
	msgbox YifuCity_Refuge_EventScript_Traveler_Text_1
	closemessage
	setnamedmon SPECIES_PAWNIARD
	setdescribedmon SPECIES_PAWNIARD
	release
	end


YifuCity_Refuge_EventScript_Bisharp::
	lock
	faceplayer
	setseenmon SPECIES_PAWNIARD
	playmoncry SPECIES_PAWNIARD, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_PAWNIARD
	msgbox YifuCity_Refuge_EventScript_Bisharp_Text_0
	waitmoncry
	closemessage
	release
	return


YifuCity_Refuge_EventScript_Samurai::
	lock
	faceplayer
	speakername YifuCity_Refuge_EventScript_Samurai_Text_0
	msgbox YifuCity_Refuge_EventScript_Samurai_Text_1
	closemessage
	release
	end


YifuCity_Refuge_EventScript_GotTrashedByDojo::
	lock
	faceplayer
	speakername YifuCity_Refuge_EventScript_GotTrashedByDojo_Text_0
	msgbox YifuCity_Refuge_EventScript_GotTrashedByDojo_Text_1
	closemessage
	release
	end


YifuCity_Refuge_EventScript_FakeNurse_Text_0:
	.string "Nurse$"

YifuCity_Refuge_EventScript_FakeNurse_Text_1:
	.string "Gimme yer Pokémon, I'mma heal 'em\n"
	.string "good.$"

YifuCity_Refuge_EventScript_FakeNurse_Text_2:
	.string "Yep, uh, good as new, probably!\p"
	.string "Ya know the drill, 500¥ please!$"

YifuCity_Refuge_EventScript_FakeNurse_Text_3:
	.string "C'magain, or whatever.$"

YifuCity_Refuge_EventScript_FakeNurse_Text_4:
	.string "Yep, uh, good as new, probably!\p"
	.string "Ya know the drill, 500¥ please!\p"
	.string "… … …\n"
	.string "… … …What? Yer THAT poor?\p"
	.string "I feel almost bad for ya, buddy…\p"
	.string "I guess, uh… I guess we're good then,\n"
	.string "don' worry 'bout it.\p"
	.string "Now make like a Treecko 'n leave!$"

YifuCity_Refuge_EventScript_FakeNurse_Text_5:
	.string "Yep, uh, good as new, probably!\p"
	.string "By the way, that'll be 500¥, wow, so\n"
	.string "cheap!$"

YifuCity_Refuge_EventScript_FakeNurse_Text_6:
	.string "What?!$"

YifuCity_Refuge_EventScript_FakeNurse_Text_7:
	.string "No way!$"

YifuCity_Refuge_EventScript_FakeNurse_Text_8:
	.string "Okay, I guess…$"

YifuCity_Refuge_EventScript_FakeNurse_Text_9:
	.string "No whinin'! Fork over the cash before\n"
	.string "I call security!$"

YifuCity_Refuge_EventScript_FakeNurse_Text_10:
	.string "No whinin'! Fork over the cash before\n"
	.string "I call security!\p"
	.string "… … …\n"
	.string "… … …What? Yer THAT poor?\p"
	.string "I feel almost bad for ya, buddy…\p"
	.string "I guess, uh… I guess we're good then,\n"
	.string "don' worry 'bout it.\p"
	.string "Now make like a Treecko 'n leave!$"

YifuCity_Refuge_EventScript_FakeNurse_Text_11:
	.string "…Really? Jus' like that?\p"
	.string "(Wow, this one's really dumb, huh?)\p"
	.string "I mean, yeah, you better!$"

YifuCity_Refuge_EventScript_FakeNurse_Text_12:
	.string "…Really? Jus' like that?\p"
	.string "(Wow, this one's really dumb, huh?)\p"
	.string "… … …\n"
	.string "… … …What? Ya don't have 'nuff cash?!\p"
	.string "I can't believe it! I've been had!\p"
	.string "Get outta here, ya scammer!$"

YifuCity_Refuge_EventScript_Woobat_Text_0:
	.string "Chansey?$"

YifuCity_Refuge_EventScript_Woobat_Text_1:
	.string "Rrrrr!$"

YifuCity_Refuge_EventScript_Shamisen_Text_0:
	.string "Shamisen Player$"

YifuCity_Refuge_EventScript_Shamisen_Text_1:
	.string "Good evening, traveler.\p"
	.string "I hope my song will soothe your spirit,\n"
	.string "should it be troubled.$"

YifuCity_Refuge_EventScript_HotelValet_Text_0:
	.string "Valet$"

YifuCity_Refuge_EventScript_HotelValet_Text_1:
	.string "Good day, {STR_VAR_1}! There's a\n"
	.string "room available for 500¥, if you need a\l"
	.string "place to spend the night!$"

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

YifuCity_Refuge_EventScript_ListenToShamisen_Text_0:
	.string "Boy$"

YifuCity_Refuge_EventScript_ListenToShamisen_Text_1:
	.string "Whew… I've walked all day…\n"
	.string "I am spent!$"

YifuCity_Refuge_EventScript_Traveler_Text_0:
	.string "Traveler$"

YifuCity_Refuge_EventScript_Traveler_Text_1:
	.string "I come from a place high up in the\n"
	.string "mountains, where the Pokémon are as\l"
	.string "tough as the rocky landscape.\p"
	.string "My Pawniard hones its saberlike claws\n"
	.string "on the hardest stones to keep them\l"
	.string "sharp.$"

YifuCity_Refuge_EventScript_Bisharp_Text_0:
	.string "Kshhh.$"

YifuCity_Refuge_EventScript_Samurai_Text_0:
	.string "Samurai$"

YifuCity_Refuge_EventScript_Samurai_Text_1:
	.string "The Crobat Shadows must be operating\n"
	.string "from somewhere… But where?$"

YifuCity_Refuge_EventScript_GotTrashedByDojo_Text_0:
	.string "Man$"

YifuCity_Refuge_EventScript_GotTrashedByDojo_Text_1:
	.string "Arrgh… this city's Dojo is all girls, so\n"
	.string "I thought it was going to be super\l"
	.string "easy…\p"
	.string "I got obliterated…$"

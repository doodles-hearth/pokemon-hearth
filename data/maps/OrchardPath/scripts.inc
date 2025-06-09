OrchardPath_MapScripts::
	.byte 0


OrchardPath_EventScript_UumeForestSoulkeepSign::
	msgbox OrchardPath_EventScript_UumeForestSoulkeepSign_Text_0, MSGBOX_SIGN
	return


OrchardPath_EventScript_GuardHouseSign::
	msgbox OrchardPath_EventScript_GuardHouseSign_Text_0, MSGBOX_SIGN
	return


OrchardPath_EventScript_Junko::
	trainerbattle_single TRAINER_JUNKO, OrchardPath_EventScript_Junko_Text_0, OrchardPath_EventScript_Junko_Text_1
	speakername OrchardPath_EventScript_Junko_Text_2
	msgbox OrchardPath_EventScript_Junko_Text_3, MSGBOX_AUTOCLOSE
	return


OrchardPath_EventScript_Mami::
	trainerbattle_single TRAINER_MAMI, OrchardPath_EventScript_Mami_Text_0, OrchardPath_EventScript_Mami_Text_1
	speakername OrchardPath_EventScript_Mami_Text_2
	msgbox OrchardPath_EventScript_Mami_Text_3, MSGBOX_AUTOCLOSE
	return


OrchardPath_EventScript_Samurai::
	lock
	faceplayer
	speakername OrchardPath_EventScript_Samurai_Text_0
	msgbox OrchardPath_EventScript_Samurai_Text_1
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, OrchardPath_EventScript_Samurai_Text_2, OrchardPath_EventScript_Samurai_Text_3, OrchardPath_EventScript_Samurai_Text_4
	closemessage
	switch VAR_RESULT
	case 0, OrchardPath_EventScript_Samurai_3
	case 1, OrchardPath_EventScript_Samurai_4
	case 2, OrchardPath_EventScript_Samurai_5
OrchardPath_EventScript_Samurai_1:
	release
	return

OrchardPath_EventScript_Samurai_3:
	call OrchardPath_Samurai_WhatIsHappening
	goto OrchardPath_EventScript_Samurai_1

OrchardPath_EventScript_Samurai_4:
	call OrchardPath_Samurai_KnowAboutDecay
	goto OrchardPath_EventScript_Samurai_1

OrchardPath_EventScript_Samurai_5:
	call OrchardPath_Samurai_LetMeThrough
	goto OrchardPath_EventScript_Samurai_1


OrchardPath_Samurai_WhatIsHappening::
	special GetPlayerSirMissString
	speakername OrchardPath_EventScript_Samurai_Text_0
	msgbox OrchardPath_Samurai_WhatIsHappening_Text_0
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, OrchardPath_EventScript_Samurai_Text_3, OrchardPath_EventScript_Samurai_Text_4
	closemessage
	switch VAR_RESULT
	case 0, OrchardPath_Samurai_WhatIsHappening_2
	case 1, OrchardPath_Samurai_WhatIsHappening_3
	return

OrchardPath_Samurai_WhatIsHappening_2:
	call OrchardPath_Samurai_KnowAboutDecay
	return

OrchardPath_Samurai_WhatIsHappening_3:
	call OrchardPath_Samurai_LetMeThrough
	return


OrchardPath_Samurai_LetMeThrough::
	speakername OrchardPath_EventScript_Samurai_Text_0
	msgbox OrchardPath_Samurai_LetMeThrough_Text_0
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, OrchardPath_EventScript_Samurai_Text_3
	closemessage
	call OrchardPath_Samurai_KnowAboutDecay
	return


OrchardPath_Samurai_KnowAboutDecay::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, OrchardPath_Samurai_KnowAboutDecay_Movement_0
	waitmovement 0
	waitse
	speakername OrchardPath_EventScript_Samurai_Text_0
	msgbox OrchardPath_Samurai_KnowAboutDecay_Text_0
	setvar VAR_DECAY_BEACHBOUND_ROUTE, 7
	return


OrchardPath_EventScript_Umbreon::
	lock
	faceplayer
	setseenmon SPECIES_UMBREON
	setspeakertomonname SPECIES_UMBREON
	playmoncry SPECIES_UMBREON, CRY_MODE_NORMAL
	msgbox OrchardPath_EventScript_Umbreon_Text_0
	waitmoncry
	release
	end


OrchardPath_EventScript_RockSmash::
	lock
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, OrchardPath_EventScript_RockSmash_2
	call OrchardPath_EventScript_RockSmashRegular
OrchardPath_EventScript_RockSmash_1:
	release
	return

OrchardPath_EventScript_RockSmash_2:
	goto_if_set FLAG_BEAT_ROCK_SMASHER, OrchardPath_EventScript_RockSmash_5
	goto_if_unset FLAG_BEAT_ROCK_SMASHER, OrchardPath_EventScript_RockSmash_9
OrchardPath_EventScript_RockSmash_7:
	speakername OrchardPath_EventScript_RockSmash_Text_0
	msgbox OrchardPath_EventScript_RockSmash_Text_2
	closemessage
	goto OrchardPath_EventScript_RockSmash_1

OrchardPath_EventScript_RockSmash_5:
	speakername OrchardPath_EventScript_RockSmash_Text_0
	msgbox OrchardPath_EventScript_RockSmash_Text_1
	closemessage
	goto OrchardPath_EventScript_RockSmash_1

OrchardPath_EventScript_RockSmash_6:
	call OrchardPath_EventScript_RockSmashBrokeMyRocks
	goto OrchardPath_EventScript_RockSmash_1

OrchardPath_EventScript_RockSmash_8:
	goto_if_set FLAG_TEMP_1, OrchardPath_EventScript_RockSmash_6
	goto_if_set FLAG_TEMP_2, OrchardPath_EventScript_RockSmash_6
	goto_if_set FLAG_TEMP_3, OrchardPath_EventScript_RockSmash_6
	goto OrchardPath_EventScript_RockSmash_7

OrchardPath_EventScript_RockSmash_9:
	goto_if_unset FLAG_TEMP_4, OrchardPath_EventScript_RockSmash_8
	goto OrchardPath_EventScript_RockSmash_7


OrchardPath_EventScript_RockSmashBrokeMyRocks::
	speakername OrchardPath_EventScript_RockSmash_Text_0
	msgbox OrchardPath_EventScript_RockSmashBrokeMyRocks_Text_0
	closemessage
	playse SE_PIN
	applymovement VAR_LAST_TALKED, OrchardPath_EventScript_RockSmashBrokeMyRocks_Movement_0
	waitmovement 0
	waitse
	speakername OrchardPath_EventScript_RockSmash_Text_0
	msgbox OrchardPath_EventScript_RockSmashBrokeMyRocks_Text_1
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, OrchardPath_EventScript_RockSmashBrokeMyRocks_Text_2, OrchardPath_EventScript_RockSmashBrokeMyRocks_Text_3
	closemessage
	switch VAR_RESULT
	case 0, OrchardPath_EventScript_RockSmashBrokeMyRocks_3
	case 1, OrchardPath_EventScript_RockSmashBrokeMyRocks_4
OrchardPath_EventScript_RockSmashBrokeMyRocks_1:
	trainerbattle_no_intro TRAINER_ROCK_SMASH_GUY, OrchardPath_EventScript_RockSmashBrokeMyRocks_Text_6
	setflag FLAG_BEAT_ROCK_SMASHER
	speakername OrchardPath_EventScript_RockSmash_Text_0
	msgbox OrchardPath_EventScript_RockSmashBrokeMyRocks_Text_7
	closemessage
	return

OrchardPath_EventScript_RockSmashBrokeMyRocks_3:
	speakername OrchardPath_EventScript_RockSmash_Text_0
	msgbox OrchardPath_EventScript_RockSmashBrokeMyRocks_Text_4
	closemessage
	goto OrchardPath_EventScript_RockSmashBrokeMyRocks_1

OrchardPath_EventScript_RockSmashBrokeMyRocks_4:
	speakername OrchardPath_EventScript_RockSmash_Text_0
	msgbox OrchardPath_EventScript_RockSmashBrokeMyRocks_Text_5
	closemessage
	goto OrchardPath_EventScript_RockSmashBrokeMyRocks_1


OrchardPath_EventScript_RockSmashRegular::
	speakername OrchardPath_EventScript_RockSmashRegular_Text_0
	msgbox OrchardPath_EventScript_RockSmashRegular_Text_1
	showmoneybox 18, 0
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, OrchardPath_EventScript_RockSmashRegular_Text_2, OrchardPath_EventScript_RockSmashRegular_Text_3, OrchardPath_EventScript_RockSmashRegular_Text_4
	closemessage
	switch VAR_RESULT
	case 0, OrchardPath_EventScript_RockSmashRegular_2
	case 1, OrchardPath_EventScript_RockSmashRegular_3
	case 2, OrchardPath_EventScript_RockSmashRegular_4
	return

OrchardPath_EventScript_RockSmashRegular_2:
	checkmoney 100
	compare VAR_RESULT, 0
	goto_if_ne OrchardPath_EventScript_RockSmashRegular_5
	hidemoneybox
	speakername OrchardPath_EventScript_RockSmash_Text_0
	msgbox OrchardPath_EventScript_RockSmashRegular_Text_10
	closemessage
	return

OrchardPath_EventScript_RockSmashRegular_3:
	hidemoneybox
	speakername OrchardPath_EventScript_RockSmash_Text_0
	msgbox OrchardPath_EventScript_RockSmashRegular_Text_11
	closemessage
	return

OrchardPath_EventScript_RockSmashRegular_4:
	hidemoneybox
	speakername OrchardPath_EventScript_RockSmash_Text_0
	msgbox OrchardPath_EventScript_RockSmashRegular_Text_12
	closemessage
	return

OrchardPath_EventScript_RockSmashRegular_5:
	removemoney 100
	updatemoneybox
	speakername OrchardPath_EventScript_RockSmash_Text_0
	msgbox OrchardPath_EventScript_RockSmashRegular_Text_5
	closemessage
	hidemoneybox
	speakername OrchardPath_EventScript_RockSmash_Text_0
	msgbox OrchardPath_EventScript_RockSmashRegular_Text_6
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, OrchardPath_EventScript_RockSmashRegular_Movement_0
	waitmovement 0
	applymovement VAR_LAST_TALKED, OrchardPath_EventScript_RockSmashRegular_Movement_1
	waitmovement 0
	speakername OrchardPath_EventScript_RockSmash_Text_0
	msgbox OrchardPath_EventScript_RockSmashRegular_Text_7
	closemessage
	playse SE_LEDGE
	applymovement VAR_LAST_TALKED, OrchardPath_EventScript_RockSmashRegular_Movement_2
	waitmovement 0
	waitse
	playse SE_M_ROCK_THROW
	applymovement 16, Movement_SmashRock
	waitmovement 16
	removeobject 16
	waitse
	delay 48
	applymovement VAR_LAST_TALKED, OrchardPath_EventScript_RockSmashRegular_Movement_3
	speakername OrchardPath_EventScript_RockSmash_Text_0
	msgbox OrchardPath_EventScript_RockSmashRegular_Text_8
	closemessage
	giveitem ITEM_SECRET_SMASH
	speakername OrchardPath_EventScript_RockSmash_Text_0
	msgbox OrchardPath_EventScript_RockSmashRegular_Text_9
	closemessage
	giveitem ITEM_TM_PEBBLE_CRUSH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_TEMP_4
	return


OrchardPath_EventScript_SignRockSmash::
	msgbox OrchardPath_EventScript_SignRockSmash_Text_0, MSGBOX_SIGN
	return


OrchardPath_EventScript_Samurai2::
	lock
	faceplayer
	speakername OrchardPath_EventScript_Samurai_Text_0
	msgbox OrchardPath_EventScript_Samurai2_Text_0
	closemessage
	release
	return


OrchardPath_Samurai_KnowAboutDecay_Movement_0:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

OrchardPath_EventScript_RockSmashBrokeMyRocks_Movement_0:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	walk_in_place_fast_left
	delay_16
	walk_in_place_fast_right
	delay_16
	walk_in_place_fast_down
	step_end

OrchardPath_EventScript_RockSmashRegular_Movement_0:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	delay_16
	step_end

OrchardPath_EventScript_RockSmashRegular_Movement_1:
	walk_in_place_fast_right
	step_end

OrchardPath_EventScript_RockSmashRegular_Movement_2:
	jump_in_place_right
	lock_anim
	walk_faster_right
	walk_faster_left
	unlock_anim
	step_end

OrchardPath_EventScript_RockSmashRegular_Movement_3:
	walk_in_place_fast_down
	step_end

OrchardPath_EventScript_UumeForestSoulkeepSign_Text_0:
	.string "{UP_ARROW} Samurai Palace\n"
	.string "{LEFT_ARROW}{UP_ARROW} Uume Forest\l"
	.string "{LEFT_ARROW} Soulkeep$"

OrchardPath_EventScript_GuardHouseSign_Text_0:
	.string "Guard House$"

OrchardPath_EventScript_Junko_Text_0:
	.string "I'm gathering ripe Berries to feed my\n"
	.string "Pokémon!$"

OrchardPath_EventScript_Junko_Text_1:
	.string "He ought to eat more Berries…$"

OrchardPath_EventScript_Junko_Text_2:
	.string "Junko$"

OrchardPath_EventScript_Junko_Text_3:
	.string "My Pokémon is insatiable!\n"
	.string "I need to scour my local Library for\l"
	.string "more Berry recipes!$"

OrchardPath_EventScript_Mami_Text_0:
	.string "Hehehehe… This place is haunted at\n"
	.string "night! Are you scared?$"

OrchardPath_EventScript_Mami_Text_1:
	.string "H-how could my ghosts lose to a mere\n"
	.string "mortal?$"

OrchardPath_EventScript_Mami_Text_2:
	.string "Mami$"

OrchardPath_EventScript_Mami_Text_3:
	.string "I wanted to catch some more ghosts\n"
	.string "at the Graveyard, but…\l"
	.string "It's a little TOO scary…$"

OrchardPath_EventScript_Samurai_Text_0:
	.string "Samurai$"

OrchardPath_EventScript_Samurai_Text_1:
	.string "Please stand back. Everything is\n"
	.string "under control.$"

OrchardPath_EventScript_Samurai_Text_2:
	.string "What is happening?$"

OrchardPath_EventScript_Samurai_Text_3:
	.string "I know about the Decay!$"

OrchardPath_EventScript_Samurai_Text_4:
	.string "I'd like to go through.$"

OrchardPath_Samurai_WhatIsHappening_Text_0:
	.string "Nothing that concerns you,\n"
	.string "{STR_VAR_1}.\p"
	.string "This is just your regular,\n"
	.string "run-of-the-mill, top secret yet\l"
	.string "unimportant stuff.$"

OrchardPath_Samurai_LetMeThrough_Text_0:
	.string "We cannot let you through, so please\n"
	.string "be on your way.$"

OrchardPath_Samurai_KnowAboutDecay_Text_0:
	.string "You- what-\p"
	.string "Ahem! I do not know of this Decay you\n"
	.string "speak of.\p"
	.string "We cannot let you through though, so\n"
	.string "please be on your way.\p"
	.string "Now now, move along!$"

OrchardPath_EventScript_Umbreon_Text_0:
	.string "Uwooo!$"

OrchardPath_EventScript_RockSmash_Text_0:
	.string "Rock Smasher$"

OrchardPath_EventScript_RockSmash_Text_1:
	.string "Hello, disciple! Or should I say…\n"
	.string "Master!$"

OrchardPath_EventScript_RockSmash_Text_2:
	.string "Now you too can make a living\n"
	.string "smashing rocks impressively!\p"
	.string "{FONT_SMALL}Just do it far from here, don't put me\n"
	.string "out of business!{FONT_NORMAL}$"

OrchardPath_EventScript_RockSmashBrokeMyRocks_Text_0:
	.string "If it isn't my disciple! Smash any good\n"
	.string "rocks lately?\p"
	.string "… … …Wait a minute…$"

OrchardPath_EventScript_RockSmashBrokeMyRocks_Text_1:
	.string "Have you… Have you been breaking my\n"
	.string "rocks?!$"

OrchardPath_EventScript_RockSmashBrokeMyRocks_Text_2:
	.string "Oops!$"

OrchardPath_EventScript_RockSmashBrokeMyRocks_Text_3:
	.string "It wasn't me!$"

OrchardPath_EventScript_RockSmashBrokeMyRocks_Text_4:
	.string "I can't believe this! My own disciple,\n"
	.string "of all people!\p"
	.string "I'll teach you to break other people's\n"
	.string "rocks!$"

OrchardPath_EventScript_RockSmashBrokeMyRocks_Text_5:
	.string "You're lying! Think I can't tell?\p"
	.string "I can't believe this! My own disciple,\n"
	.string "of all people!\p"
	.string "I'll teach you to break other people's\n"
	.string "rocks!$"

OrchardPath_EventScript_RockSmashBrokeMyRocks_Text_6:
	.string "I take it back!$"

OrchardPath_EventScript_RockSmashBrokeMyRocks_Text_7:
	.string "Your fighting style is incredible! I…\p"
	.string "I forgive you! The pupil has\n"
	.string "surpassed the master!\p"
	.string "Break all the rocks you want!$"

OrchardPath_EventScript_RockSmashRegular_Text_0:
	.string "Man$"

OrchardPath_EventScript_RockSmashRegular_Text_1:
	.string "Gather round, folks, gather round!\p"
	.string "Hey, kid! Do you want your mind to be\n"
	.string "BLOWN?\p"
	.string "I am the world-renowned ROCK\n"
	.string "SMASHER! I kid you not!\p"
	.string "For as little as 100¥, you will have\n"
	.string "the privilege of watching me\l"
	.string "ABSOLUTELY DESTROY a rock, using my\l"
	.string "BARE HANDS!\p"
	.string "So what do you say?$"

OrchardPath_EventScript_RockSmashRegular_Text_2:
	.string "Yes please!$"

OrchardPath_EventScript_RockSmashRegular_Text_3:
	.string "I'm not interested.$"

OrchardPath_EventScript_RockSmashRegular_Text_4:
	.string "But why?$"

OrchardPath_EventScript_RockSmashRegular_Text_5:
	.string "Wise decision!\n"
	.string "{FONT_SMALL}Yes! I get to eat today!{FONT_NORMAL}$"

OrchardPath_EventScript_RockSmashRegular_Text_6:
	.string "Stand back, for your own safety!$"

OrchardPath_EventScript_RockSmashRegular_Text_7:
	.string "Very well! Brace yourself and open\n"
	.string "your eyes…\p"
	.string "Hnng…\p"
	.string "Hnnnngh…\p"
	.string "HNNNNNNGHYAAAAH!!$"

OrchardPath_EventScript_RockSmashRegular_Text_8:
	.string "Huff… Puff…\p"
	.string "Tadaaah!\p"
	.string "I do hope you're thoroughly\n"
	.string "impressed!\p"
	.string "Thanks for stopping by. Truth be told,\n"
	.string "I rarely have an audience these days…\p"
	.string "You're so young and scrawny, yet…\n"
	.string "I can feel a ROCK SMASHING PASSION\l"
	.string "burning behind those eyes!\p"
	.string "Would you… ahem… Become my rock\n"
	.string "smashing disciple?$"

OrchardPath_EventScript_RockSmashRegular_Text_9:
	.string "This is a secret technique of my own\n"
	.string "invention.\p"
	.string "It lets you PULVERIZE any of those\n"
	.string "pesky rocks standing in your way!\p"
	.string "If you're not strong enough, a\n"
	.string "Pokémon can even do it for you, using\l"
	.string "a variety of SMASHING moves, such as\l"
	.string "this one!\p"
	.string "{FONT_SMALL}Even though this one really sucks in\n"
	.string "battle!{FONT_NORMAL}$"

OrchardPath_EventScript_RockSmashRegular_Text_10:
	.string "Very well!…\n"
	.string "… Wait, you don't have enough!\p"
	.string "Come on, kid, this is a once in a\n"
	.string "lifetime opportunity!\p"
	.string "Go ask your parents for an advance on\n"
	.string "your pocket money or something!$"

OrchardPath_EventScript_RockSmashRegular_Text_11:
	.string "{FONT_SMALL}Come on, kid, I'm financially\n"
	.string "struggling here{FONT_NORMAL}…$"

OrchardPath_EventScript_RockSmashRegular_Text_12:
	.string "Smashing rocks is my passion! I have\n"
	.string "fought tooth and nail… Or rather,\l"
	.string "foot and fist… To acquire the title of\l"
	.string "ROCK SMASHER!\p"
	.string "{FONT_SMALL}Also, a man's gotta eat…{FONT_NORMAL}$"

OrchardPath_EventScript_SignRockSmash_Text_0:
	.string "WITNESS AN INCREDIBLE DISPLAY\n"
	.string "OF STRENGTH FOR ONLY 100¥$"

OrchardPath_EventScript_Samurai2_Text_0:
	.string "Move along, please, nothing to see\n"
	.string "here!$"

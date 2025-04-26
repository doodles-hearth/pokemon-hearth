KuraTown_Dojo_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KuraTown_Dojo_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

KuraTown_Dojo_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_BADGE02_GET, KuraTown_Dojo_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

KuraTown_Dojo_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_8
	setflag FLAG_TEMP_9
	return


KuraTown_Dojo_EventScript_Matsu::
	trainerbattle_single TRAINER_MATSU, KuraTown_Dojo_EventScript_Matsu_Text_0, KuraTown_Dojo_EventScript_Matsu_Text_1
	speakername KuraTown_Dojo_EventScript_Matsu_Text_2
	msgbox KuraTown_Dojo_EventScript_Matsu_Text_3, MSGBOX_AUTOCLOSE
	end


KuraTown_Dojo_EventScript_Kiku::
	trainerbattle_single TRAINER_KIKU, KuraTown_Dojo_EventScript_Kiku_Text_0, KuraTown_Dojo_EventScript_Kiku_Text_1
	speakername KuraTown_Dojo_EventScript_Kiku_Text_2
	msgbox KuraTown_Dojo_EventScript_Kiku_Text_3, MSGBOX_AUTOCLOSE
	end


KuraTown_Dojo_EventScript_Laura::
	trainerbattle_single TRAINER_AYAME, KuraTown_Dojo_EventScript_Laura_Text_0, KuraTown_Dojo_EventScript_Laura_Text_1
	msgbox KuraTown_Dojo_EventScript_Laura_Text_2, MSGBOX_AUTOCLOSE
	end


KuraTown_Dojo_EventScript_Brenden::
	trainerbattle_single TRAINER_TSUBAKI, KuraTown_Dojo_EventScript_Brenden_Text_0, KuraTown_Dojo_EventScript_Brenden_Text_1
	speakername KuraTown_Dojo_EventScript_Brenden_Text_2
	msgbox KuraTown_Dojo_EventScript_Brenden_Text_3, MSGBOX_AUTOCLOSE
	end


KuraTown_Dojo_EventScript_Cristian::
	trainerbattle_single TRAINER_AJISAI, KuraTown_Dojo_EventScript_Cristian_Text_0, KuraTown_Dojo_EventScript_Cristian_Text_1
	msgbox KuraTown_Dojo_EventScript_Cristian_Text_2, MSGBOX_AUTOCLOSE
	end


KuraTown_Dojo_EventScript_Lilith::
	trainerbattle_single TRAINER_SUMIRE, KuraTown_Dojo_EventScript_Lilith_Text_0, KuraTown_Dojo_EventScript_Lilith_Text_1
	speakername KuraTown_Dojo_EventScript_Lilith_Text_2
	goto_if_set FLAG_BADGE02_GET, KuraTown_Dojo_EventScript_Lilith_2
	msgbox KuraTown_Dojo_EventScript_Lilith_Text_4, MSGBOX_AUTOCLOSE
KuraTown_Dojo_EventScript_Lilith_1:
	end

KuraTown_Dojo_EventScript_Lilith_2:
	msgbox KuraTown_Dojo_EventScript_Lilith_Text_3
	closemessage
	addvar VAR_PLAYER_REPUTATION, 1
	goto KuraTown_Dojo_EventScript_Lilith_1


KuraTown_Dojo_EventScript_Hana::
	speakername KuraTown_Dojo_EventScript_Hana_Text_0
	trainerbattle_single TRAINER_HANA_1, KuraTown_Dojo_EventScript_Hana_Text_1, KuraTown_Dojo_EventScript_Hana_Text_2, KuraTown_Dojo_EventScript_HanaDefeated, NO_MUSIC
	speakername KuraTown_Dojo_EventScript_Hana_Text_0
	msgbox KuraTown_Dojo_EventScript_Hana_Text_3, MSGBOX_DEFAULT
	release
	end


KuraTown_Dojo_EventScript_HanaDefeated::
	message KuraTown_Dojo_EventScript_HanaDefeated_Text_0
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	speakername KuraTown_Dojo_EventScript_Hana_Text_0
	msgbox KuraTown_Dojo_EventScript_HanaDefeated_Text_1, MSGBOX_DEFAULT
	setflag FLAG_BADGE02_GET
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call KuraTown_Dojo_EventScript_GiveBulldoze
	closemessage
	release
	end


KuraTown_Dojo_EventScript_GiveBulldoze::
	giveitem ITEM_TM_WEATHER_BALL
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	speakername KuraTown_Dojo_EventScript_Hana_Text_0
	msgbox KuraTown_Dojo_EventScript_GiveBulldoze_Text_0, MSGBOX_DEFAULT
	return


KuraTown_Dojo_EventScript_Advice::
	lock
	faceplayer
	goto_if_set FLAG_BADGE02_GET, KuraTown_Dojo_EventScript_Advice_2
	speakername KuraTown_Dojo_EventScript_Advice_Text_0
	goto_if_set FLAG_RECEIVED_HM_CUT, KuraTown_Dojo_EventScript_Advice_7
KuraTown_Dojo_EventScript_Advice_6:
	speakername KuraTown_Dojo_EventScript_Advice_Text_0
	goto_if_set FLAG_BADGE01_GET, KuraTown_Dojo_EventScript_Advice_10
	speakername KuraTown_Dojo_EventScript_Advice_Text_0
	msgbox KuraTown_Dojo_EventScript_Advice_Text_4
KuraTown_Dojo_EventScript_Advice_1:
	release
	return

KuraTown_Dojo_EventScript_Advice_2:
	speakername KuraTown_Dojo_EventScript_Advice_Text_0
	msgbox KuraTown_Dojo_EventScript_Advice_Text_1
	goto KuraTown_Dojo_EventScript_Advice_1

KuraTown_Dojo_EventScript_Advice_5:
	msgbox KuraTown_Dojo_EventScript_Advice_Text_2
	goto KuraTown_Dojo_EventScript_Advice_1

KuraTown_Dojo_EventScript_Advice_7:
	goto_if_set FLAG_BADGE01_GET, KuraTown_Dojo_EventScript_Advice_5
	goto KuraTown_Dojo_EventScript_Advice_6

KuraTown_Dojo_EventScript_Advice_10:
	msgbox KuraTown_Dojo_EventScript_Advice_Text_3
	goto KuraTown_Dojo_EventScript_Advice_1


KuraTown_Dojo_EventScript_DojoStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, KuraTown_Dojo_EventScript_DojoStatue_2
	msgbox KuraTown_Dojo_EventScript_DojoStatue_Text_1, MSGBOX_SIGN
KuraTown_Dojo_EventScript_DojoStatue_1:
	releaseall
	return

KuraTown_Dojo_EventScript_DojoStatue_2:
	msgbox KuraTown_Dojo_EventScript_DojoStatue_Text_0, MSGBOX_SIGN
	goto KuraTown_Dojo_EventScript_DojoStatue_1


KuraTown_Dojo_EventScript_KuraDojoTree_CanCut::
	lock
	goto_if_set FLAG_RECEIVED_HM_CUT, KuraTown_Dojo_EventScript_KuraDojoTree_CanCut_4
KuraTown_Dojo_EventScript_KuraDojoTree_CanCut_3:
	call KuraTown_Dojo_EventScript_KuraDojoTree_CantCut
KuraTown_Dojo_EventScript_KuraDojoTree_CanCut_1:
	release
	return

KuraTown_Dojo_EventScript_KuraDojoTree_CanCut_2:
	msgbox KuraTown_Dojo_EventScript_KuraDojoTree_CanCut_Text_0, MSGBOX_DEFAULT
	closemessage
	playse SE_M_CUT
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitse
	waitmovement 0
	removeobject VAR_LAST_TALKED
	goto KuraTown_Dojo_EventScript_KuraDojoTree_CanCut_1

KuraTown_Dojo_EventScript_KuraDojoTree_CanCut_4:
	goto_if_set FLAG_BADGE01_GET, KuraTown_Dojo_EventScript_KuraDojoTree_CanCut_2
	goto KuraTown_Dojo_EventScript_KuraDojoTree_CanCut_3


KuraTown_Dojo_EventScript_KuraDojoTree_CantCut::
	msgbox KuraTown_Dojo_EventScript_KuraDojoTree_CantCut_Text_0, MSGBOX_SIGN
	return


KuraTown_Dojo_EventScript_Matsu_Text_0:
	.string "Ho ho ho… It seems you have taken a\n"
	.string "wrong turn…$"

KuraTown_Dojo_EventScript_Matsu_Text_1:
	.string "Very impressive skills!$"

KuraTown_Dojo_EventScript_Matsu_Text_2:
	.string "Matsu$"

KuraTown_Dojo_EventScript_Matsu_Text_3:
	.string "Not all paths lead to the master.$"

KuraTown_Dojo_EventScript_Kiku_Text_0:
	.string "Is the maze giving you trouble?$"

KuraTown_Dojo_EventScript_Kiku_Text_1:
	.string "At least I didn't give you any\n"
	.string "trouble…$"

KuraTown_Dojo_EventScript_Kiku_Text_2:
	.string "Kiku$"

KuraTown_Dojo_EventScript_Kiku_Text_3:
	.string "You're wondering why you can't just\n"
	.string "cut down all the trees?\p"
	.string "Uhhh… It's a secret!$"

KuraTown_Dojo_EventScript_Laura_Text_0:
	.string "No! Don't cut down that tree! It's my\n"
	.string "favorite tree!$"

KuraTown_Dojo_EventScript_Laura_Text_1:
	.string "Sniffle…$"

KuraTown_Dojo_EventScript_Laura_Text_2:
	.string "It's okay, go ahead. They're all my\n"
	.string "favorite tree anyway.$"

KuraTown_Dojo_EventScript_Brenden_Text_0:
	.string "Take a deep breath! The air is so rich\n"
	.string "and flowery here!$"

KuraTown_Dojo_EventScript_Brenden_Text_1:
	.string "A-tchoo!$"

KuraTown_Dojo_EventScript_Brenden_Text_2:
	.string "Tsubaki$"

KuraTown_Dojo_EventScript_Brenden_Text_3:
	.string "Sniff… By zeazonal allergiez are\n"
	.string "agdig up agaid…$"

KuraTown_Dojo_EventScript_Cristian_Text_0:
	.string "Did you know any tree can be\n"
	.string "bonsaified by pruning its leaves\l"
	.string "regularly?$"

KuraTown_Dojo_EventScript_Cristian_Text_1:
	.string "You're not here because you're\n"
	.string "particularly interested in bonsai, are\l"
	.string "you?$"

KuraTown_Dojo_EventScript_Cristian_Text_2:
	.string "I feel bad sometimes, not letting the\n"
	.string "tree grow the way it wants.$"

KuraTown_Dojo_EventScript_Lilith_Text_0:
	.string "Hana may look frail, but she's\n"
	.string "actually way tougher than you!$"

KuraTown_Dojo_EventScript_Lilith_Text_1:
	.string "Stop it! I'm a delicate flower!$"

KuraTown_Dojo_EventScript_Lilith_Text_2:
	.string "Sumire$"

KuraTown_Dojo_EventScript_Lilith_Text_3:
	.string "I saw your fight peeking through the\n"
	.string "leaves! That was amazing!\p"
	.string "I'm officially a fan!$"

KuraTown_Dojo_EventScript_Lilith_Text_4:
	.string "I wish I could see you two fight! Good\n"
	.string "luck!$"

KuraTown_Dojo_EventScript_Hana_Text_0:
	.string "Hana$"

KuraTown_Dojo_EventScript_Hana_Text_1:
	.string "Welcome to my humble Dojo. I am Hana.\n"
	.string "Did you enjoy my little maze?\p"
	.string "Tending to my bonsai and fighting\n"
	.string "alongside my Pokémon are my favorite\l"
	.string "pastimes. With this Dojo, I can do\l"
	.string "both!\p"
	.string "A Pokémon battle can be graceful like\n"
	.string "a budding flower, strong like the\l"
	.string "deepest roots, powerful like a\l"
	.string "windswept pine tree, all at once.\p"
	.string "I want you to show me all the grace,\n"
	.string "strength and power you are capable\l"
	.string "of!$"

KuraTown_Dojo_EventScript_Hana_Text_2:
	.string "Ho ho ho…$"

KuraTown_Dojo_EventScript_Hana_Text_3:
	.string "The slow-growing tree becomes the\n"
	.string "sturdiest. Take your time on your\l"
	.string "journey, {PLAYER}.$"

KuraTown_Dojo_EventScript_HanaDefeated_Text_0:
	.string "{PLAYER} received the Carved Token\n"
	.string "from Hana.$"

KuraTown_Dojo_EventScript_HanaDefeated_Text_1:
	.string "Thanks to this Token, your Pokémon\n"
	.string "will obey you without question, even\l"
	.string "those you trade with others.\p"
	.string "If you are interested in submitting\n"
	.string "to the Toku Council challenge, you\l"
	.string "will need to collect a Token from each\l"
	.string "of the eight Dojos scattered\l"
	.string "throughout the region.\p"
	.string "It is not an easy task, but I can feel\n"
	.string "determination taking root in your\l"
	.string "heart.\p"
	.string "Here, let me also give you this.$"

KuraTown_Dojo_EventScript_GiveBulldoze_Text_0:
	.string "This scroll contains Weather Ball.\n"
	.string "Just like a tree, this technique is as\l"
	.string "strong as it is weather-dependent.$"

KuraTown_Dojo_EventScript_Advice_Text_0:
	.string "Man$"

KuraTown_Dojo_EventScript_Advice_Text_1:
	.string "That was a beautiful fight! You're\n"
	.string "going to blossom into an excellent\l"
	.string "Pokémon Wielder, I can just feel it!$"

KuraTown_Dojo_EventScript_Advice_Text_2:
	.string "Hello, young challenger, and welcome\n"
	.string "to the official Dojo of Kura Village!\p"
	.string "Lady Hana, the Dojo Master, is an\n"
	.string "expert in all things bonsai. She\l"
	.string "designed this place and grew these\l"
	.string "trees, of course!\p"
	.string "She tends to favor grass-type\n"
	.string "Pokémon, but she's got other tricks\l"
	.string "up her sleeve, too. Be on your guard!\p"
	.string "Now, pay attention: only some of\n"
	.string "these pretty trees can be cut down.\p"
	.string "Figure out which, and you'll reach the\n"
	.string "Master!$"

KuraTown_Dojo_EventScript_Advice_Text_3:
	.string "Hello, young challenger, and welcome\n"
	.string "to the official Dojo of Kura Village!\p"
	.string "All these trees are blocking your way,\n"
	.string "aren't they?\p"
	.string "You should come back once you've\n"
	.string "figured out a way to cut them!$"

KuraTown_Dojo_EventScript_Advice_Text_4:
	.string "Hello, young challenger, and welcome\n"
	.string "to the official Dojo of Kura Village!\p"
	.string "All these trees are blocking your way,\n"
	.string "aren't they?\p"
	.string "You should come back once you've\n"
	.string "figured out a way to cut them!\p"
	.string "If you're itching for a challenge, why\n"
	.string "not try your skills at the Dojo in\l"
	.string "Maguro Harbor first?\p"
	.string "It's not very far east from here!$"

KuraTown_Dojo_EventScript_DojoStatue_Text_0:
	.string "Dojo of Kura Village\p"
	.string "Certified Wielder:\n"
	.string "Natsuki,\l"
	.string "{PLAYER}$"

KuraTown_Dojo_EventScript_DojoStatue_Text_1:
	.string "Dojo of Kura Village\p"
	.string "Certified Wielder:\n"
	.string "Natsuki$"

KuraTown_Dojo_EventScript_KuraDojoTree_CanCut_Text_0:
	.string "…Oh? This tree can be cut down!$"

KuraTown_Dojo_EventScript_KuraDojoTree_CantCut_Text_0:
	.string "A gorgeous and well-nurtured tree.$"

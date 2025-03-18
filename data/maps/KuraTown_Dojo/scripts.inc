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
	trainerbattle_single TRAINER_HANA_1, KuraTown_Dojo_EventScript_Hana_Text_0, KuraTown_Dojo_EventScript_Hana_Text_1, KuraTown_Dojo_EventScript_HanaDefeated, NO_MUSIC
	msgbox KuraTown_Dojo_EventScript_Hana_Text_2, MSGBOX_DEFAULT
	release
	end


KuraTown_Dojo_EventScript_HanaDefeated::
	message KuraTown_Dojo_EventScript_HanaDefeated_Text_0
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox KuraTown_Dojo_EventScript_HanaDefeated_Text_1, MSGBOX_DEFAULT
	setflag FLAG_BADGE02_GET
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call KuraTown_Dojo_EventScript_GiveBulldoze
	closemessage
	release
	end


KuraTown_Dojo_EventScript_GiveBulldoze::
	giveitem ITEM_TM_BULLDOZE
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox KuraTown_Dojo_EventScript_GiveBulldoze_Text_0, MSGBOX_DEFAULT
	return


KuraTown_Dojo_EventScript_Advice::
	lock
	faceplayer
	goto_if_set FLAG_BADGE02_GET, KuraTown_Dojo_EventScript_Advice_2
	goto_if_set FLAG_RECEIVED_HM_CUT, KuraTown_Dojo_EventScript_Advice_7
KuraTown_Dojo_EventScript_Advice_6:
	goto_if_set FLAG_BADGE01_GET, KuraTown_Dojo_EventScript_Advice_10
	msgbox KuraTown_Dojo_EventScript_Advice_Text_3
KuraTown_Dojo_EventScript_Advice_1:
	release
	return

KuraTown_Dojo_EventScript_Advice_2:
	msgbox KuraTown_Dojo_EventScript_Advice_Text_0
	goto KuraTown_Dojo_EventScript_Advice_1

KuraTown_Dojo_EventScript_Advice_5:
	msgbox KuraTown_Dojo_EventScript_Advice_Text_1
	goto KuraTown_Dojo_EventScript_Advice_1

KuraTown_Dojo_EventScript_Advice_7:
	goto_if_set FLAG_BADGE01_GET, KuraTown_Dojo_EventScript_Advice_5
	goto KuraTown_Dojo_EventScript_Advice_6

KuraTown_Dojo_EventScript_Advice_10:
	msgbox KuraTown_Dojo_EventScript_Advice_Text_2
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
	.string "Ho ho ho… It seems you have taken\n"
	.string "a wrong turn…$"

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
	.string "No! Don't cut down that tree! It's\n"
	.string "my favorite tree!$"

KuraTown_Dojo_EventScript_Laura_Text_1:
	.string "Sniffle…$"

KuraTown_Dojo_EventScript_Laura_Text_2:
	.string "It's okay, go ahead. They're all my\n"
	.string "favorite tree anyway.$"

KuraTown_Dojo_EventScript_Brenden_Text_0:
	.string "Take a deep breath! The air is so\n"
	.string "rich and flowery here!$"

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
	.string "particularly interested in bonsai,\l"
	.string "are you?$"

KuraTown_Dojo_EventScript_Cristian_Text_2:
	.string "I feel bad sometimes, not letting\n"
	.string "the tree grow the way it wants.$"

KuraTown_Dojo_EventScript_Lilith_Text_0:
	.string "Hana may look frail, but she's\n"
	.string "actually way tougher than you!$"

KuraTown_Dojo_EventScript_Lilith_Text_1:
	.string "Stop it! I'm a delicate flower!$"

KuraTown_Dojo_EventScript_Lilith_Text_2:
	.string "Sumire$"

KuraTown_Dojo_EventScript_Lilith_Text_3:
	.string "I saw your fight peeking through\n"
	.string "the leaves! That was amazing!\p"
	.string "I'm officially a fan!$"

KuraTown_Dojo_EventScript_Lilith_Text_4:
	.string "I wish I could see you two fight!\n"
	.string "Good luck!$"

KuraTown_Dojo_EventScript_Hana_Text_0:
	.string "Welcome to my humble Dojo. I am\n"
	.string "Hana. Did you enjoy my little\l"
	.string "maze?\p"
	.string "Tending to my bonsai and fighting\n"
	.string "alongside my Pokémon are my\l"
	.string "favorite pastimes. With this Dojo,\l"
	.string "I can do both!\p"
	.string "A Pokémon battle can be graceful\n"
	.string "like a budding flower, strong like\l"
	.string "the deepest roots, powerful like\l"
	.string "a windswept pine tree, all at\l"
	.string "once.\p"
	.string "I want you to show me all the\n"
	.string "grace, strength and power you are\l"
	.string "capable of!$"

KuraTown_Dojo_EventScript_Hana_Text_1:
	.string "Amazing.$"

KuraTown_Dojo_EventScript_Hana_Text_2:
	.string "The slow-growing tree becomes the\n"
	.string "sturdiest. Take your time on your\l"
	.string "journey, {PLAYER}.$"

KuraTown_Dojo_EventScript_HanaDefeated_Text_0:
	.string "{PLAYER} received the Carved\n"
	.string "Token\n"
	.string "from Hana.$"

KuraTown_Dojo_EventScript_HanaDefeated_Text_1:
	.string "Thanks to this Token, your Pokémon\n"
	.string "will obey you without question,\l"
	.string "even those you trade with others.\p"
	.string "If you are interested in submitting\n"
	.string "to the Pokémon Council challenge,\l"
	.string "you will need to collect a Token\l"
	.string "from each of the eight Dojos\l"
	.string "scattered throughout the region.\p"
	.string "It is not an easy task, but I can\n"
	.string "feel determination taking root in\l"
	.string "your heart.\p"
	.string "Here, let me also give you this.$"

KuraTown_Dojo_EventScript_GiveBulldoze_Text_0:
	.string "This scroll contains Bulldoze, a\n"
	.string "powerful ground-type move that\l"
	.string "slows down the enemy.\p"
	.string "I invented that technique myself! I\n"
	.string "needed a way to soften the\l"
	.string "ground when repotting bonsai, heh\l"
	.string "heh.\p"
	.string "$"

KuraTown_Dojo_EventScript_Advice_Text_0:
	.string "That was a beautiful fight! You're\n"
	.string "going to blossom into an excellent\l"
	.string "Pokémon wielder, I can just feel\l"
	.string "it!$"

KuraTown_Dojo_EventScript_Advice_Text_1:
	.string "Hello, young challenger, and\n"
	.string "welcome to the official Dojo of\l"
	.string "Kura Village!\p"
	.string "Lady Hana, the Dojo master, is an\n"
	.string "expert in all things bonsai. She\l"
	.string "designed this place and grew\l"
	.string "these trees, of course!\p"
	.string "She tends to favor ground-type\n"
	.string "moves, but she's got other tricks\l"
	.string "up her sleeve, too. Be on your\l"
	.string "guard!\p"
	.string "Now, pay attention: only some of\n"
	.string "these pretty trees can be cut\l"
	.string "down.\p"
	.string "Figure out which, and you'll reach\n"
	.string "the master!$"

KuraTown_Dojo_EventScript_Advice_Text_2:
	.string "Hello, young challenger, and\n"
	.string "welcome to the official Dojo of\l"
	.string "Kura Village!\p"
	.string "All these trees are blocking your\n"
	.string "way, aren't they?\p"
	.string "You should come back once you've\n"
	.string "figured out a way to cut them!$"

KuraTown_Dojo_EventScript_Advice_Text_3:
	.string "Hello, young challenger, and\n"
	.string "welcome to the official Dojo of\l"
	.string "Kura Village!\p"
	.string "All these trees are blocking your\n"
	.string "way, aren't they?\p"
	.string "You should come back once you've\n"
	.string "figured out a way to cut them!\p"
	.string "If you're itching for a challenge,\n"
	.string "why not try your skills at the\l"
	.string "Dojo in Maguro Harbor first?\p"
	.string "It's not very far east from here!$"

KuraTown_Dojo_EventScript_DojoStatue_Text_0:
	.string "Dojo of Kura Village\p"
	.string "Certified wielders:\n"
	.string "Natsuki,\l"
	.string "{PLAYER}$"

KuraTown_Dojo_EventScript_DojoStatue_Text_1:
	.string "Dojo of Kura Village\p"
	.string "Certified wielders:\n"
	.string "Natsuki$"

KuraTown_Dojo_EventScript_KuraDojoTree_CanCut_Text_0:
	.string "…Oh? This tree can be cut down!$"

KuraTown_Dojo_EventScript_KuraDojoTree_CantCut_Text_0:
	.string "A gorgeous and well-nurtured tree.$"

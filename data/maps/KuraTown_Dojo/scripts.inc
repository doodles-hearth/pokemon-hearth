KuraTown_Dojo_MapScripts::
	.byte 0


KuraTown_Dojo_EventScript_Takao::
# 6 "data/maps/KuraTown_Dojo/scripts.pory"
	trainerbattle_single TRAINER_TAKAO, KuraTown_Dojo_EventScript_Takao_Text_0, KuraTown_Dojo_EventScript_Takao_Text_1
# 11 "data/maps/KuraTown_Dojo/scripts.pory"
	msgbox KuraTown_Dojo_EventScript_Takao_Text_2, MSGBOX_AUTOCLOSE
	end


KuraTown_Dojo_EventScript_Jocelyn::
# 19 "data/maps/KuraTown_Dojo/scripts.pory"
	trainerbattle_single TRAINER_JOCELYN, KuraTown_Dojo_EventScript_Jocelyn_Text_0, KuraTown_Dojo_EventScript_Jocelyn_Text_1
# 24 "data/maps/KuraTown_Dojo/scripts.pory"
	msgbox KuraTown_Dojo_EventScript_Jocelyn_Text_2, MSGBOX_AUTOCLOSE
	end


KuraTown_Dojo_EventScript_Laura::
# 32 "data/maps/KuraTown_Dojo/scripts.pory"
	trainerbattle_single TRAINER_LAURA, KuraTown_Dojo_EventScript_Laura_Text_0, KuraTown_Dojo_EventScript_Laura_Text_1
# 37 "data/maps/KuraTown_Dojo/scripts.pory"
	msgbox KuraTown_Dojo_EventScript_Laura_Text_2, MSGBOX_AUTOCLOSE
	end


KuraTown_Dojo_EventScript_Brenden::
# 42 "data/maps/KuraTown_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BRENDEN, KuraTown_Dojo_EventScript_Brenden_Text_0, KuraTown_Dojo_EventScript_Brenden_Text_1
# 47 "data/maps/KuraTown_Dojo/scripts.pory"
	msgbox KuraTown_Dojo_EventScript_Brenden_Text_2, MSGBOX_AUTOCLOSE
	end


KuraTown_Dojo_EventScript_Cristian::
# 52 "data/maps/KuraTown_Dojo/scripts.pory"
	trainerbattle_single TRAINER_CRISTIAN, KuraTown_Dojo_EventScript_Cristian_Text_0, KuraTown_Dojo_EventScript_Cristian_Text_1
# 57 "data/maps/KuraTown_Dojo/scripts.pory"
	msgbox KuraTown_Dojo_EventScript_Cristian_Text_2, MSGBOX_AUTOCLOSE
	end


KuraTown_Dojo_EventScript_Lilith::
# 62 "data/maps/KuraTown_Dojo/scripts.pory"
	trainerbattle_single TRAINER_LILITH, KuraTown_Dojo_EventScript_Lilith_Text_0, KuraTown_Dojo_EventScript_Lilith_Text_1
# 67 "data/maps/KuraTown_Dojo/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, KuraTown_Dojo_EventScript_Lilith_2
# 73 "data/maps/KuraTown_Dojo/scripts.pory"
	msgbox KuraTown_Dojo_EventScript_Lilith_Text_3, MSGBOX_AUTOCLOSE
KuraTown_Dojo_EventScript_Lilith_1:
	end

KuraTown_Dojo_EventScript_Lilith_2:
# 68 "data/maps/KuraTown_Dojo/scripts.pory"
	msgbox KuraTown_Dojo_EventScript_Lilith_Text_2, MSGBOX_AUTOCLOSE
	goto KuraTown_Dojo_EventScript_Lilith_1


KuraTown_Dojo_EventScript_Hana::
# 79 "data/maps/KuraTown_Dojo/scripts.pory"
	trainerbattle_single TRAINER_HANA_1, KuraTown_Dojo_EventScript_Hana_Text_0, KuraTown_Dojo_EventScript_Hana_Text_1, KuraTown_Dojo_EventScript_HanaDefeated, NO_MUSIC
# 92 "data/maps/KuraTown_Dojo/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_BULLDOZE, KuraTown_Dojo_EventScript_Hana_2
# 95 "data/maps/KuraTown_Dojo/scripts.pory"
	msgbox KuraTown_Dojo_EventScript_Hana_Text_2, MSGBOX_DEFAULT
KuraTown_Dojo_EventScript_Hana_1:
# 102 "data/maps/KuraTown_Dojo/scripts.pory"
	release
	end

KuraTown_Dojo_EventScript_Hana_2:
# 93 "data/maps/KuraTown_Dojo/scripts.pory"
	call KuraTown_Dojo_EventScript_GiveBulldoze
	goto KuraTown_Dojo_EventScript_Hana_1


KuraTown_Dojo_EventScript_HanaDefeated::
# 107 "data/maps/KuraTown_Dojo/scripts.pory"
	message KuraTown_Dojo_EventScript_HanaDefeated_Text_0
# 111 "data/maps/KuraTown_Dojo/scripts.pory"
	waitmessage
# 112 "data/maps/KuraTown_Dojo/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 113 "data/maps/KuraTown_Dojo/scripts.pory"
	msgbox KuraTown_Dojo_EventScript_HanaDefeated_Text_1, MSGBOX_DEFAULT
# 120 "data/maps/KuraTown_Dojo/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 121 "data/maps/KuraTown_Dojo/scripts.pory"
	setflag FLAG_BADGE02_GET
# 122 "data/maps/KuraTown_Dojo/scripts.pory"
	setvar VAR_0x8008, 2
# 123 "data/maps/KuraTown_Dojo/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 124 "data/maps/KuraTown_Dojo/scripts.pory"
	call KuraTown_Dojo_EventScript_GiveBulldoze
# 125 "data/maps/KuraTown_Dojo/scripts.pory"
	closemessage
# 132 "data/maps/KuraTown_Dojo/scripts.pory"
	release
	end


KuraTown_Dojo_EventScript_GiveBulldoze::
# 137 "data/maps/KuraTown_Dojo/scripts.pory"
	giveitem ITEM_TM_BULLDOZE
# 138 "data/maps/KuraTown_Dojo/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 139 "data/maps/KuraTown_Dojo/scripts.pory"
	msgbox KuraTown_Dojo_EventScript_GiveBulldoze_Text_0, MSGBOX_DEFAULT
# 146 "data/maps/KuraTown_Dojo/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULLDOZE
	return


KuraTown_Dojo_EventScript_Advice::
# 151 "data/maps/KuraTown_Dojo/scripts.pory"
	lock
# 152 "data/maps/KuraTown_Dojo/scripts.pory"
	faceplayer
# 153 "data/maps/KuraTown_Dojo/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, KuraTown_Dojo_EventScript_Advice_2
# 158 "data/maps/KuraTown_Dojo/scripts.pory"
	msgbox KuraTown_Dojo_EventScript_Advice_Text_1
KuraTown_Dojo_EventScript_Advice_1:
# 166 "data/maps/KuraTown_Dojo/scripts.pory"
	release
	return

KuraTown_Dojo_EventScript_Advice_2:
# 154 "data/maps/KuraTown_Dojo/scripts.pory"
	msgbox KuraTown_Dojo_EventScript_Advice_Text_0
	goto KuraTown_Dojo_EventScript_Advice_1


KuraTown_Dojo_EventScript_DojoStatue::
# 170 "data/maps/KuraTown_Dojo/scripts.pory"
	lockall
# 171 "data/maps/KuraTown_Dojo/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, KuraTown_Dojo_EventScript_DojoStatue_2
# 179 "data/maps/KuraTown_Dojo/scripts.pory"
	msgbox KuraTown_Dojo_EventScript_DojoStatue_Text_1, MSGBOX_DEFAULT
KuraTown_Dojo_EventScript_DojoStatue_1:
# 181 "data/maps/KuraTown_Dojo/scripts.pory"
	releaseall
	return

KuraTown_Dojo_EventScript_DojoStatue_2:
# 172 "data/maps/KuraTown_Dojo/scripts.pory"
	msgbox KuraTown_Dojo_EventScript_DojoStatue_Text_0, MSGBOX_DEFAULT
	goto KuraTown_Dojo_EventScript_DojoStatue_1


KuraTown_Dojo_EventScript_KuraDojoTree_CanCut::
# 185 "data/maps/KuraTown_Dojo/scripts.pory"
	lock
# 186 "data/maps/KuraTown_Dojo/scripts.pory"
	msgbox KuraTown_Dojo_EventScript_KuraDojoTree_CanCut_Text_0, MSGBOX_DEFAULT
# 187 "data/maps/KuraTown_Dojo/scripts.pory"
	closemessage
# 188 "data/maps/KuraTown_Dojo/scripts.pory"
	playse SE_M_CUT
# 189 "data/maps/KuraTown_Dojo/scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
# 190 "data/maps/KuraTown_Dojo/scripts.pory"
	waitse
# 191 "data/maps/KuraTown_Dojo/scripts.pory"
	waitmovement 0
# 192 "data/maps/KuraTown_Dojo/scripts.pory"
	removeobject VAR_LAST_TALKED
# 193 "data/maps/KuraTown_Dojo/scripts.pory"
	release
	return


KuraTown_Dojo_EventScript_KuraDojoTree_CantCut::
# 197 "data/maps/KuraTown_Dojo/scripts.pory"
	msgbox KuraTown_Dojo_EventScript_KuraDojoTree_CantCut_Text_0, MSGBOX_SIGN
	return


KuraTown_Dojo_EventScript_Takao_Text_0:
# 8 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "Ho ho ho… It seems you have taken a\n"
	.string "wrong turn…$"

KuraTown_Dojo_EventScript_Takao_Text_1:
# 9 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "Very impressive skills!$"

KuraTown_Dojo_EventScript_Takao_Text_2:
# 12 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "Not all paths lead to the master.$"

KuraTown_Dojo_EventScript_Jocelyn_Text_0:
# 21 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "Is the maze giving you trouble?$"

KuraTown_Dojo_EventScript_Jocelyn_Text_1:
# 22 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "At least I didn't give you any trouble…$"

KuraTown_Dojo_EventScript_Jocelyn_Text_2:
# 25 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "You're wondering why you can't just cut\n"
	.string "down all the trees?\p"
	.string "Uhhh… It's a secret!$"

KuraTown_Dojo_EventScript_Laura_Text_0:
# 34 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "No! Don't cut down that tree! It's my\n"
	.string "favorite tree!$"

KuraTown_Dojo_EventScript_Laura_Text_1:
# 35 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "Sniffle…$"

KuraTown_Dojo_EventScript_Laura_Text_2:
# 37 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "It's okay, go ahead. They're all my\n"
	.string "favorite tree anyway.$"

KuraTown_Dojo_EventScript_Brenden_Text_0:
# 44 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "Take a deep breath! The air is so rich\n"
	.string "and flowery here!$"

KuraTown_Dojo_EventScript_Brenden_Text_1:
# 45 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "A-tchoo!$"

KuraTown_Dojo_EventScript_Brenden_Text_2:
# 47 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "Sniff… By zeazonal allergiez are agdig\n"
	.string "up agaid…$"

KuraTown_Dojo_EventScript_Cristian_Text_0:
# 54 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "Did you know any tree can be bonsaified\n"
	.string "by pruning its leaves regularly?$"

KuraTown_Dojo_EventScript_Cristian_Text_1:
# 55 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "You're not here because you're\n"
	.string "particularly interested in bonsai, are\l"
	.string "you?$"

KuraTown_Dojo_EventScript_Cristian_Text_2:
# 57 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "I feel bad sometimes, not letting the\n"
	.string "tree grow like it wants.$"

KuraTown_Dojo_EventScript_Lilith_Text_0:
# 64 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "Hana may look delicate, but she's\n"
	.string "actually way tougher than you!$"

KuraTown_Dojo_EventScript_Lilith_Text_1:
# 65 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "Stop it! I'm a delicate flower!$"

KuraTown_Dojo_EventScript_Lilith_Text_2:
# 69 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "I saw your fight peeking through the\n"
	.string "leaves! That was amazing!\p"
	.string "I'm officially a fan!$"

KuraTown_Dojo_EventScript_Lilith_Text_3:
# 73 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "I wish I could see you two fight! Good\n"
	.string "luck!$"

KuraTown_Dojo_EventScript_Hana_Text_0:
# 82 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "Welcome to my humble Dojo. I am Hana.\n"
	.string "Did you enjoy my little maze?\p"
	.string "Tending to my bonsai and fighting\n"
	.string "alongside my Pokémon are my favorite\l"
	.string "pastimes. With the Dojo, I can do both!\p"
	.string "A Pokémon battle can be graceful like a\n"
	.string "budding flower and strong like a\l"
	.string "windswept pine tree, all at once.\p"
	.string "I want you to show me all the grace and\n"
	.string "strength you are capable of!$"

KuraTown_Dojo_EventScript_Hana_Text_1:
# 86 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "Amazing!$"

KuraTown_Dojo_EventScript_Hana_Text_2:
# 97 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "The slow-growing trees become the\n"
	.string "sturdiest. Take your time on your\l"
	.string "journey, {PLAYER}.$"

KuraTown_Dojo_EventScript_HanaDefeated_Text_0:
# 108 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "{PLAYER} received the Bonsai badge\n"
	.string "from Hana.$"

KuraTown_Dojo_EventScript_HanaDefeated_Text_1:
# 115 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "Thanks to the Bonsai badge, your\n"
	.string "Pokémon will obey you without question,\l"
	.string "even those you trade with others.\p"
	.string "Here, let me also give you this.$"

KuraTown_Dojo_EventScript_GiveBulldoze_Text_0:
# 141 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "This scroll contains Bulldoze, a\n"
	.string "powerful ground-type move that slows\l"
	.string "down the enemy.\p"
	.string "I invented that technique myself! I\n"
	.string "needed a way to soften the ground when\l"
	.string "repotting bonsai, heh heh.\p"
	.string "$"

KuraTown_Dojo_EventScript_Advice_Text_0:
# 155 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "That was a beautiful fight! You're going\n"
	.string "to blossom into an excellent Pokémon\l"
	.string "wielder, I can just feel it!$"

KuraTown_Dojo_EventScript_Advice_Text_1:
# 159 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "Hello, young challenger, and welcome to\n"
	.string "the official Dojo of Kura Village!\p"
	.string "Lady Hana, the Dojo master, is an expert\n"
	.string "in all things bonsai. She designed this\l"
	.string "place and grew these trees, of course!\p"
	.string "She tends to favor ground-type moves,\n"
	.string "but she's got other tricks up her\l"
	.string "sleeve, too. Be on your guard!\p"
	.string "Now, pay attention: only some of these\n"
	.string "pretty trees can be cut down.\p"
	.string "Figure out which, and you'll reach the\n"
	.string "master!$"

KuraTown_Dojo_EventScript_DojoStatue_Text_0:
# 173 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "Dojo of Kura Village\p"
	.string "Certified wielders:\n"
	.string "{PLAYER}$"

KuraTown_Dojo_EventScript_DojoStatue_Text_1:
# 179 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "Dojo of Kura Village$"

KuraTown_Dojo_EventScript_KuraDojoTree_CanCut_Text_0:
# 186 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "…Oh? This tree can be cut down!$"

KuraTown_Dojo_EventScript_KuraDojoTree_CantCut_Text_0:
# 197 "data/maps/KuraTown_Dojo/scripts.pory"
	.string "A gorgeous and well-nurtured tree.$"

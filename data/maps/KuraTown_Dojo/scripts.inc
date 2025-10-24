KuraTown_Dojo_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KuraTown_Dojo_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

KuraTown_Dojo_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_MET_HANA_GYM, KuraTown_Dojo_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
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
	setspeaker SP_NAME_OLD_MAN
	msgbox KuraTown_Dojo_EventScript_Matsu_Text_2, MSGBOX_AUTOCLOSE
	end


KuraTown_Dojo_EventScript_Kiku::
	trainerbattle_single TRAINER_KIKU, KuraTown_Dojo_EventScript_Kiku_Text_0, KuraTown_Dojo_EventScript_Kiku_Text_1
	setspeaker SP_NAME_AROMA_LADY
	msgbox KuraTown_Dojo_EventScript_Kiku_Text_2, MSGBOX_AUTOCLOSE
	end


KuraTown_Dojo_EventScript_Laura::
	trainerbattle_single TRAINER_AYAME, KuraTown_Dojo_EventScript_Laura_Text_0, KuraTown_Dojo_EventScript_Laura_Text_1
	setspeaker SP_NAME_GARDENER
	msgbox KuraTown_Dojo_EventScript_Laura_Text_2, MSGBOX_AUTOCLOSE
	end


KuraTown_Dojo_EventScript_Brenden::
	trainerbattle_single TRAINER_TSUBAKI, KuraTown_Dojo_EventScript_Brenden_Text_0, KuraTown_Dojo_EventScript_Brenden_Text_1
	setspeaker SP_NAME_LASS
	msgbox KuraTown_Dojo_EventScript_Brenden_Text_2, MSGBOX_AUTOCLOSE
	end


KuraTown_Dojo_EventScript_Cristian::
	trainerbattle_single TRAINER_AJISAI, KuraTown_Dojo_EventScript_Cristian_Text_0, KuraTown_Dojo_EventScript_Cristian_Text_1
	setspeaker SP_NAME_OLD_LADY
	msgbox KuraTown_Dojo_EventScript_Cristian_Text_2, MSGBOX_AUTOCLOSE
	end


KuraTown_Dojo_EventScript_Lilith::
	trainerbattle_single TRAINER_SUMIRE, KuraTown_Dojo_EventScript_Lilith_Text_0, KuraTown_Dojo_EventScript_Lilith_Text_1
	setspeaker SP_NAME_GARDENER
	goto_if_set FLAG_BADGE02_GET, KuraTown_Dojo_EventScript_Lilith_2
	msgbox KuraTown_Dojo_EventScript_Lilith_Text_3, MSGBOX_AUTOCLOSE
KuraTown_Dojo_EventScript_Lilith_1:
	end

KuraTown_Dojo_EventScript_Lilith_2:
	msgbox KuraTown_Dojo_EventScript_Lilith_Text_2
	closemessage
	addvar VAR_PLAYER_REPUTATION, 1
	goto KuraTown_Dojo_EventScript_Lilith_1


KuraTown_Dojo_EventScript_Hana::
	setflag FLAG_MET_HANA_GYM
	trysetchatotpostactive POST_NATSUKI_RARE_CANDY
	goto_if_set FLAG_MET_HANA_BONSAI_SHOP, KuraTown_Dojo_EventScript_Hana_2
	setspeaker SP_NAME_HANA
	trainerbattle_single TRAINER_HANA_1, KuraTown_Dojo_EventScript_Hana_Text_2, KuraTown_Dojo_EventScript_Hana_Text_1, KuraTown_Dojo_EventScript_HanaDefeated, NO_MUSIC
KuraTown_Dojo_EventScript_Hana_1:
	setspeaker SP_NAME_HANA
	msgbox KuraTown_Dojo_EventScript_Hana_Text_3, MSGBOX_DEFAULT
	release
	end

KuraTown_Dojo_EventScript_Hana_2:
	setspeaker SP_NAME_HANA
	trainerbattle_single TRAINER_HANA_1, KuraTown_Dojo_EventScript_Hana_Text_0, KuraTown_Dojo_EventScript_Hana_Text_1, KuraTown_Dojo_EventScript_HanaDefeated, NO_MUSIC
	goto KuraTown_Dojo_EventScript_Hana_1


KuraTown_Dojo_EventScript_HanaDefeated::
	message KuraTown_Dojo_EventScript_HanaDefeated_Text_0
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setspeaker SP_NAME_HANA
	msgbox KuraTown_Dojo_EventScript_HanaDefeated_Text_1, MSGBOX_DEFAULT
	setflag FLAG_BADGE02_GET
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call KuraTown_Dojo_EventScript_GiveTm
	closemessage
	release
	end


KuraTown_Dojo_EventScript_GiveTm:
	giveitem ITEM_TM_WEATHER_BALL
	setspeaker SP_NAME_HANA
	msgbox KuraTown_Dojo_EventScript_GiveTm_Text_0, MSGBOX_DEFAULT
	return


KuraTown_Dojo_EventScript_Advice::
	lock
	faceplayer
	goto_if_set FLAG_BADGE02_GET, KuraTown_Dojo_EventScript_Advice_2
	setspeaker SP_NAME_MAN
	isfieldmoveunlocked FIELD_MOVE_CUT
	compare VAR_RESULT, 0
	goto_if_ne KuraTown_Dojo_EventScript_Advice_5
	setspeaker SP_NAME_MAN
	goto_if_set FLAG_BADGE01_GET, KuraTown_Dojo_EventScript_Advice_8
	msgbox KuraTown_Dojo_EventScript_Advice_Text_3
KuraTown_Dojo_EventScript_Advice_1:
	release
	return

KuraTown_Dojo_EventScript_Advice_2:
	setspeaker SP_NAME_MAN
	msgbox KuraTown_Dojo_EventScript_Advice_Text_0
	goto KuraTown_Dojo_EventScript_Advice_1

KuraTown_Dojo_EventScript_Advice_5:
	msgbox KuraTown_Dojo_EventScript_Advice_Text_1
	goto KuraTown_Dojo_EventScript_Advice_1

KuraTown_Dojo_EventScript_Advice_8:
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
	checkfieldmove FIELD_MOVE_CUT, TRUE
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne KuraTown_Dojo_EventScript_KuraDojoTree_CanCut_2
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


KuraTown_Dojo_EventScript_KuraDojoTree_CantCut::
	msgbox KuraTown_Dojo_EventScript_KuraDojoTree_CantCut_Text_0, MSGBOX_SIGN
	return


KuraTown_Dojo_EventScript_Matsu_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_MAN EMOTE_NORMAL}Ho ho ho… It seems you have taken a\n"
	.string "wrong turn…$"

KuraTown_Dojo_EventScript_Matsu_Text_1:
	.string "Very impressive skills!$"

KuraTown_Dojo_EventScript_Matsu_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_MAN EMOTE_NORMAL}Not all paths lead to the master.$"

KuraTown_Dojo_EventScript_Kiku_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_AROMA_LADY EMOTE_NORMAL}Is the maze giving you trouble?$"

KuraTown_Dojo_EventScript_Kiku_Text_1:
	.string "At least I didn't give you any\n"
	.string "trouble…$"

KuraTown_Dojo_EventScript_Kiku_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_AROMA_LADY EMOTE_NORMAL}You're wondering why you can't just\n"
	.string "cut down all the trees?\l"
	.string "Uhhh… It's a secret!$"

KuraTown_Dojo_EventScript_Laura_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_GARDENER EMOTE_NORMAL}No! Don't cut down that tree! It's my\n"
	.string "favorite tree!$"

KuraTown_Dojo_EventScript_Laura_Text_1:
	.string "Sniffle…$"

KuraTown_Dojo_EventScript_Laura_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_GARDENER EMOTE_NORMAL}It's okay, go ahead. They're all my\n"
	.string "favorite tree anyway.$"

KuraTown_Dojo_EventScript_Brenden_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_LASS EMOTE_NORMAL}Take a deep breath! The air is so rich\n"
	.string "and flowery here!$"

KuraTown_Dojo_EventScript_Brenden_Text_1:
	.string "A-tchoo!$"

KuraTown_Dojo_EventScript_Brenden_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_LASS EMOTE_NORMAL}Sniff… By zeazonal allergiez are\n"
	.string "agdig up agaid…$"

KuraTown_Dojo_EventScript_Cristian_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_WOMAN EMOTE_NORMAL}Did you know any tree can be\n"
	.string "bonsaified by pruning its leaves\l"
	.string "regularly?$"

KuraTown_Dojo_EventScript_Cristian_Text_1:
	.string "You're not here because you're\n"
	.string "interested in bonsai, are you?$"

KuraTown_Dojo_EventScript_Cristian_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_OLD_WOMAN EMOTE_NORMAL} I feel bad sometimes, not letting the\n"
	.string "tree grow the way it wants.$"

KuraTown_Dojo_EventScript_Lilith_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_GARDENER EMOTE_NORMAL}Hana may look frail, but she's\n"
	.string "actually way tougher than you!$"

KuraTown_Dojo_EventScript_Lilith_Text_1:
	.string "Stop it! I'm a delicate flower!$"

KuraTown_Dojo_EventScript_Lilith_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_GARDENER EMOTE_NORMAL}I saw your fight peeking through the\n"
	.string "leaves! That was amazing!\l"
	.string "I'm officially a fan!$"

KuraTown_Dojo_EventScript_Lilith_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_GARDENER EMOTE_NORMAL}I wish I could see you two fight!\n"
	.string "Good luck!$"

KuraTown_Dojo_EventScript_Hana_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_HANA EMOTE_NORMAL}Welcome to my humble Dojo. I am Hana.\n"
	.string "Did you enjoy my little maze?\p"
	.string "You must be wondering what a Bonsai\n"
	.string "seller from Saku Village is doing in\l"
	.string "the Kura Village Dojo.\p"
	.string "I'd prefer you don't tell anyone.\n"
	.string "See, the two towns have a beef with\l"
	.string "one another.\p"
	.string "A Pokémon battle can be graceful like\n"
	.string "a budding flower, strong like the\l"
	.string "deepest roots, powerful like a\l"
	.string "windswept pine tree, all at once.\p"
	.string "Show me all the grace, strength and\n"
	.string "power you are capable of!$"

KuraTown_Dojo_EventScript_Hana_Text_1:
	.string "Ho ho ho…$"

KuraTown_Dojo_EventScript_Hana_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_HANA EMOTE_NORMAL}Welcome to my humble Dojo. I am Hana.\nDid you enjoy my little maze?\p"
	.string "Growing bonsai and battling with my\nPokémon are my favorite pastimes.\lWith this Dojo, I can do both!\p"
	.string "A Pokémon battle can be graceful like a\nbudding flower, strong like the\ldeepest roots, powerful like a\lwindswept pine tree, all at once.\p"
	.string "Show me all the grace, strength and\npower you are capable of!$"

KuraTown_Dojo_EventScript_Hana_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_HANA EMOTE_NORMAL}The slow-growing tree becomes the\n"
	.string "sturdiest.\p"
	.string "Take your time on your journey,\n"
	.string "{PLAYER}.$"

KuraTown_Dojo_EventScript_HanaDefeated_Text_0:
	.string "{PLAYER} received the Carved Token\n"
	.string "from Hana.$"

KuraTown_Dojo_EventScript_HanaDefeated_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_HANA EMOTE_NORMAL}If you want to submit to the Toku\nCouncil challenge, you will need a Token\lfrom the region's eight Dojos.\p"
	.string "Arduous task! But I feel determination\ntaking root in your heart.\p"
	.string "Here, let me also give you this.$"

KuraTown_Dojo_EventScript_GiveTm_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_HANA EMOTE_NORMAL}This scroll contains Weather Ball.\p"
	.string "Just like a tree, this technique is as\n"
	.string "strong as it is weather-dependent.$"

KuraTown_Dojo_EventScript_Advice_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_2 EMOTE_NORMAL} That was a beautiful fight!\n"
	.string "You'll blossom into an excellent\l"
	.string "Pokémon Wielder, I can just feel it!$"

KuraTown_Dojo_EventScript_Advice_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_2 EMOTE_NORMAL} Hello, young challenger, and welcome\n"
	.string "to the Kura Village Dojo!\p"
	.string "Lady Hana, the Dojo Master, is an\n"
	.string "expert in all things bonsai.\p"
	.string "She designed this place and, of\n"
	.string "course, grew these trees herself!\p"
	.string "Now, pay attention: only some of\n"
	.string "these noble trees can be cut down.\p"
	.string "Figure out which, and you'll reach the\n"
	.string "Master!\p"
	.string "By the way - Hana's a weather expert,\n"
	.string "and a formidable adversary.\p"
	.string "Be on your guard!\n"
	.string "Maybe get an umbrella, I don't know!$"

KuraTown_Dojo_EventScript_Advice_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_2 EMOTE_NORMAL} Hello, young challenger, and welcome\n"
	.string "to the Kura Village Dojo!\p"
	.string "All these trees are blocking your way,\n"
	.string "aren't they?\p"
	.string "You should come back once you've\n"
	.string "figured out a way to cut them!$"

KuraTown_Dojo_EventScript_Advice_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_2 EMOTE_NORMAL} Hello, young challenger, and welcome\n"
	.string "to the Kura Village Dojo!\p"
	.string "All these trees are blocking your way,\n"
	.string "aren't they?\p"
	.string "You should come back once you've\n"
	.string "figured out a way to cut them!\p"
	.string "If you're itching for a challenge, why\n"
	.string "not try your skills at the Dojo in\l"
	.string "Maguro Harbor first?\p"
	.string "It's not very far east from here!$"

KuraTown_Dojo_EventScript_DojoStatue_Text_0:
	.string "Kura Village Dojo\p"
	.string "certified Wielders:\n"
	.string "Natsuki,\l"
	.string "{PLAYER}$"

KuraTown_Dojo_EventScript_DojoStatue_Text_1:
	.string "Kura Village Dojo\p"
	.string "certified Wielders:\n"
	.string "Natsuki$"

KuraTown_Dojo_EventScript_KuraDojoTree_CanCut_Text_0:
	.string "…Oh? This tree can be cut down!$"

KuraTown_Dojo_EventScript_KuraDojoTree_CantCut_Text_0:
	.string "A gorgeous and well-nurtured tree.$"

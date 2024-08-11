SpindaIsland_Home_MapScripts::
	.byte 0


SpindaIsland_Home_EventScript_ArchiesHouseSign::
# 8 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ArchiesHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_BobsHouseSign::
# 12 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_BobsHouseSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_ICanNeverGoHome::
# 16 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 17 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 18 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_0
# 19 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_1, MSGBOX_NPC
# 23 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return


SpindaIsland_Home_EventScript_Dad::
# 27 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 28 "data/maps/SpindaIsland_Home/scripts.pory"
	turnobject 2, DIR_SOUTH
# 29 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OBTAINED_LEMONADE, SpindaIsland_Home_EventScript_Dad_2
# 37 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SPOKE_TO_DAD, SpindaIsland_Home_EventScript_Dad_6
# 44 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 45 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_3
# 49 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Dad_5:
# 52 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_SALTY_LEMONADE
# 54 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 55 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 56 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_4
# 57 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_5
# 61 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 62 "data/maps/SpindaIsland_Home/scripts.pory"
	removefieldmugshot
# 64 "data/maps/SpindaIsland_Home/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_DISGUSTED
# 65 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_4
# 66 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_6
# 70 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 72 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 73 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_7
# 80 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 82 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_OBTAINED_LEMONADE
# 83 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SPOKE_TO_DAD
SpindaIsland_Home_EventScript_Dad_1:
# 85 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Dad_2:
# 30 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 31 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_1
# 35 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_1

SpindaIsland_Home_EventScript_Dad_6:
# 38 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 39 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_2
# 42 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_5


SpindaIsland_Home_EventScript_Dad_FromSide::
# 89 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 90 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 91 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_OBTAINED_LEMONADE, SpindaIsland_Home_EventScript_Dad_FromSide_2
# 99 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_SPOKE_TO_DAD, SpindaIsland_Home_EventScript_Dad_FromSide_6
# 106 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 107 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_FromSide_Text_1
# 112 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
SpindaIsland_Home_EventScript_Dad_FromSide_5:
# 114 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_SPOKE_TO_DAD
SpindaIsland_Home_EventScript_Dad_FromSide_1:
# 116 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_Dad_FromSide_2:
# 92 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 93 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_Text_1
# 97 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_FromSide_1

SpindaIsland_Home_EventScript_Dad_FromSide_6:
# 100 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_Dad_Text_0
# 101 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_Dad_FromSide_Text_0
# 104 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_Dad_FromSide_5


SpindaIsland_Home_EventScript_LemonadeStandSign::
# 120 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_LemonadeStandSign_Text_0, MSGBOX_SIGN
	return


SpindaIsland_Home_EventScript_PoemGirl::
# 127 "data/maps/SpindaIsland_Home/scripts.pory"
	lock
# 128 "data/maps/SpindaIsland_Home/scripts.pory"
	faceplayer
# 130 "data/maps/SpindaIsland_Home/scripts.pory"
	goto_if_set FLAG_POEM_GIRL, SpindaIsland_Home_EventScript_PoemGirl_2
# 137 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 138 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_2
# 143 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 145 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 6, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_3, SpindaIsland_Home_EventScript_PoemGirl_Text_4, SpindaIsland_Home_EventScript_PoemGirl_Text_5
# 157 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 158 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_6
# 201 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_7
# 290 "data/maps/SpindaIsland_Home/scripts.pory"
	case 2, SpindaIsland_Home_EventScript_PoemGirl_8
SpindaIsland_Home_EventScript_PoemGirl_1:
# 370 "data/maps/SpindaIsland_Home/scripts.pory"
	release
	return

SpindaIsland_Home_EventScript_PoemGirl_2:
# 131 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 132 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_1
# 135 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_6:
# 159 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_6, SpindaIsland_Home_EventScript_PoemGirl_Text_7
# 170 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 171 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_11
# 182 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_12
SpindaIsland_Home_EventScript_PoemGirl_9:
# 195 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 196 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_12
# 200 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_7:
# 202 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_13, SpindaIsland_Home_EventScript_PoemGirl_Text_14
# 212 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 214 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_14
# 269 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_15
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_8:
# 291 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_24, SpindaIsland_Home_EventScript_PoemGirl_Text_13
# 302 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 304 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_17
# 325 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_18
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_11:
# 172 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_8, SpindaIsland_Home_EventScript_PoemGirl_Text_9
	goto SpindaIsland_Home_EventScript_PoemGirl_9

SpindaIsland_Home_EventScript_PoemGirl_12:
# 183 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_10, SpindaIsland_Home_EventScript_PoemGirl_Text_11
	goto SpindaIsland_Home_EventScript_PoemGirl_9

SpindaIsland_Home_EventScript_PoemGirl_14:
# 215 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_15, SpindaIsland_Home_EventScript_PoemGirl_Text_16
# 226 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 228 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_20
# 248 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_21
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_15:
# 270 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_21, SpindaIsland_Home_EventScript_PoemGirl_Text_22
# 281 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 282 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_23
# 288 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_17:
# 305 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_25, SpindaIsland_Home_EventScript_PoemGirl_Text_26
# 316 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 317 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_27
# 322 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_18:
# 326 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_28, SpindaIsland_Home_EventScript_PoemGirl_Text_29
# 337 "data/maps/SpindaIsland_Home/scripts.pory"
	switch VAR_RESULT
# 338 "data/maps/SpindaIsland_Home/scripts.pory"
	case 0, SpindaIsland_Home_EventScript_PoemGirl_23
# 346 "data/maps/SpindaIsland_Home/scripts.pory"
	case 1, SpindaIsland_Home_EventScript_PoemGirl_24
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_20:
# 229 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_17, SpindaIsland_Home_EventScript_PoemGirl_Text_18
# 240 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 241 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_19
# 245 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_21:
# 249 "data/maps/SpindaIsland_Home/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SpindaIsland_Home_EventScript_PoemGirl_Text_17, SpindaIsland_Home_EventScript_PoemGirl_Text_18
# 260 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 261 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_20
# 265 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_23:
# 339 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 340 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_27
# 345 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
	goto SpindaIsland_Home_EventScript_PoemGirl_1

SpindaIsland_Home_EventScript_PoemGirl_24:
# 347 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 348 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_30
# 355 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 357 "data/maps/SpindaIsland_Home/scripts.pory"
	giveitem ITEM_GRASS_BLADE
# 359 "data/maps/SpindaIsland_Home/scripts.pory"
	speakername SpindaIsland_Home_EventScript_PoemGirl_Text_0
# 360 "data/maps/SpindaIsland_Home/scripts.pory"
	msgbox SpindaIsland_Home_EventScript_PoemGirl_Text_31
# 363 "data/maps/SpindaIsland_Home/scripts.pory"
	closemessage
# 365 "data/maps/SpindaIsland_Home/scripts.pory"
	setflag FLAG_POEM_GIRL
	goto SpindaIsland_Home_EventScript_PoemGirl_1


SpindaIsland_Home_EventScript_ArchiesHouseSign_Text_0:
# 8 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The Aquas$"

SpindaIsland_Home_EventScript_BobsHouseSign_Text_0:
# 12 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Bob$"

SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_0:
# 18 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Sad man$"

SpindaIsland_Home_EventScript_ICanNeverGoHome_Text_1:
# 20 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Curse the architect that built my\n"
	.string "house facing the wrong direction!!\p"
	.string "I can never go home!$"

SpindaIsland_Home_EventScript_Dad_Text_0:
# 30 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Dad$"

SpindaIsland_Home_EventScript_Dad_Text_1:
# 32 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Don't uh, pour that lemonade I gave\n"
	.string "you on the ground or anything.\p"
	.string "It'd probably kill all the grass and\n"
	.string "flowers.$"

SpindaIsland_Home_EventScript_Dad_Text_2:
# 40 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Here, have some lemonade!$"

SpindaIsland_Home_EventScript_Dad_Text_3:
# 46 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hiya, sonny! going adventuring today,\n"
	.string "are we?\p"
	.string "Want some lemonade?$"

SpindaIsland_Home_EventScript_Dad_Text_4:
# 56 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Little Archie$"

SpindaIsland_Home_EventScript_Dad_Text_5:
# 58 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Now we're talkin'!! I can bring it to\n"
	.string "mom, that should do it!\p"
	.string "Let's take a sip first, I am PARCHED!$"

SpindaIsland_Home_EventScript_Dad_Text_6:
# 67 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "BLEARGH!\p"
	.string "Why is it… so salty?!$"

SpindaIsland_Home_EventScript_Dad_Text_7:
# 74 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Why, because it's seawater, obviously!\p"
	.string "I take it you're not a fan of my\n"
	.string "recipe?\p"
	.string "(You wouldn't be the only one…)\p"
	.string "In any case, it's nice of you to come\n"
	.string "visit me at the office, haha!\p"
	.string "See you around, little Archie! Don't\n"
	.string "get into trouble!$"

SpindaIsland_Home_EventScript_Dad_FromSide_Text_0:
# 102 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Come round to the front of the\n"
	.string "lemonade stand!$"

SpindaIsland_Home_EventScript_Dad_FromSide_Text_1:
# 108 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hiya, sonny! going adventuring today,\n"
	.string "are we?\p"
	.string "Want some lemonade?\p"
	.string "Come round to the front of the\n"
	.string "lemonade stand!$"

SpindaIsland_Home_EventScript_LemonadeStandSign_Text_0:
# 121 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "“ARCHIE'S LEMONADE\n"
	.string "A taste of the seaside!”$"

SpindaIsland_Home_EventScript_PoemGirl_Text_0:
# 131 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Maggie$"

SpindaIsland_Home_EventScript_PoemGirl_Text_1:
# 133 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "See you around, Archie…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_2:
# 139 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Archie…\p"
	.string "I want to hear a poem…\p"
	.string "I want you to reveal your heart to me.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_3:
# 152 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Ocean waves swimming…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_4:
# 153 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Roses are red…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_5:
# 154 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Roses are blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_6:
# 166 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "From the center of the sea…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_7:
# 167 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "They are calling to my heart…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_8:
# 179 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "With faith to reach land.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_9:
# 180 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Only to go back.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_10:
# 190 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And my heart to theirs.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_11:
# 191 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Yearning for a touch.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_12:
# 197 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "That was very beautiful.\p"
	.string "I'm not really into haiku, though.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_13:
# 209 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Violets are blue…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_14:
# 210 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Just like our love…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_15:
# 222 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The sky is pretty…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_16:
# 223 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The Pincurchin are spiky…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_17:
# 236 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And so are you.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_18:
# 237 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "And so are you!$"

SpindaIsland_Home_EventScript_PoemGirl_Text_19:
# 242 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Oh, that's nice.\p"
	.string "You're not truly revealing your poet's\n"
	.string "heart, though.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_20:
# 262 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "That's… a weird comparison.\p"
	.string "I thought you were a better poet\n"
	.string "than that.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_21:
# 277 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Which blooms like they do.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_22:
# 278 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wait, I didn't mean to say that.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_23:
# 283 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Wow, Archie, uh…\p"
	.string "That's not really what I meant when I\n"
	.string "said you should reveal your heart.\p"
	.string "(Well, this is awkward.)\p"
	.string "(Let's pretend this never happened.)$"

SpindaIsland_Home_EventScript_PoemGirl_Text_24:
# 298 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Violets are red…$"

SpindaIsland_Home_EventScript_PoemGirl_Text_25:
# 312 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "The sky isn't blue, it's purple instead.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_26:
# 313 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "It doesn't make sense, but it's fun to be said.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_27:
# 318 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Hmm…\p"
	.string "You're not revealing your heart right\n"
	.string "now.\p"
	.string "Plus, this didn't make any sense.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_28:
# 333 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Orchids are blue, too.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_29:
# 334 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "Everything is blue because it's my favorite color.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_30:
# 349 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "… … … … …\p"
	.string "Wow, Archie, I…\p"
	.string "This was so touching…\p"
	.string "Thank you for revealing your heart to\n"
	.string "me like this.\p"
	.string "Here, take this.$"

SpindaIsland_Home_EventScript_PoemGirl_Text_31:
# 361 "data/maps/SpindaIsland_Home/scripts.pory"
	.string "It's a blade of grass large enough to\n"
	.string "whistle with.$"

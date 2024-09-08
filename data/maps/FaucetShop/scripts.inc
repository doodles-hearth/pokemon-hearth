FaucetShop_MapScripts::
	.byte 0


FaucetShop_EventScript_Owner::
# 6 "data/maps/FaucetShop/scripts.pory"
	lock
# 7 "data/maps/FaucetShop/scripts.pory"
	faceplayer
# 9 "data/maps/FaucetShop/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, FaucetShop_EventScript_Owner_2
# 67 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 68 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 69 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_7
# 74 "data/maps/FaucetShop/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, FaucetShop_EventScript_Owner_Text_8, FaucetShop_EventScript_Owner_Text_9
# 84 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 85 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 87 "data/maps/FaucetShop/scripts.pory"
	switch VAR_RESULT
# 88 "data/maps/FaucetShop/scripts.pory"
	case 0, FaucetShop_EventScript_Owner_16
# 99 "data/maps/FaucetShop/scripts.pory"
	case 1, FaucetShop_EventScript_Owner_17
FaucetShop_EventScript_Owner_1:
# 194 "data/maps/FaucetShop/scripts.pory"
	release
	return

FaucetShop_EventScript_Owner_2:
# 10 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 11 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 12 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_1
# 15 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 16 "data/maps/FaucetShop/scripts.pory"
	closemessage
	checkitem ITEM_TOUGH_BOLT
# 0 "data/maps/FaucetShop/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne FaucetShop_EventScript_Owner_7
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_5:
# 19 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 20 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_2
# 21 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_3
# 24 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 25 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 27 "data/maps/FaucetShop/scripts.pory"
	removeitem ITEM_TOUGH_BOLT
# 28 "data/maps/FaucetShop/scripts.pory"
	removeitem ITEM_PRECIOUS_BOLT
# 29 "data/maps/FaucetShop/scripts.pory"
	removeitem ITEM_RUSTY_BOLT
# 30 "data/maps/FaucetShop/scripts.pory"
	removeitem ITEM_BORROWED_PLIERS
# 31 "data/maps/FaucetShop/scripts.pory"
	removeitem ITEM_COOKING_OIL
# 33 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 34 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 35 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_4
# 38 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 39 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 41 "data/maps/FaucetShop/scripts.pory"
	playse SE_SWITCH
# 42 "data/maps/FaucetShop/scripts.pory"
	waitse
# 43 "data/maps/FaucetShop/scripts.pory"
	playse SE_SWITCH
# 44 "data/maps/FaucetShop/scripts.pory"
	waitse
# 46 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 47 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 48 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_5
# 51 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 52 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 54 "data/maps/FaucetShop/scripts.pory"
	giveitem ITEM_NEW_FAUCET
# 56 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 57 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_2
# 58 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_6
# 61 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 62 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 64 "data/maps/FaucetShop/scripts.pory"
	setflag FLAG_FAUCET_QUEST_FINISHED
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_6:
	checkitem ITEM_RUSTY_BOLT
# 0 "data/maps/FaucetShop/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne FaucetShop_EventScript_Owner_11
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_7:
	checkitem ITEM_PRECIOUS_BOLT
# 0 "data/maps/FaucetShop/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne FaucetShop_EventScript_Owner_6
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_10:
	checkitem ITEM_COOKING_OIL
# 0 "data/maps/FaucetShop/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne FaucetShop_EventScript_Owner_5
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_11:
	checkitem ITEM_BORROWED_PLIERS
# 0 "data/maps/FaucetShop/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne FaucetShop_EventScript_Owner_10
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_16:
# 89 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 90 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 91 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_10
# 97 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 98 "data/maps/FaucetShop/scripts.pory"
	closemessage
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_17:
# 100 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 101 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 102 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_11
# 107 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 108 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 109 "data/maps/FaucetShop/scripts.pory"
	goto_if_set FLAG_FAUCET_BROKE, FaucetShop_EventScript_Owner_18
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_18:
# 110 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 111 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_2
# 112 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_12
# 116 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 117 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 119 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 120 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 121 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_13
# 125 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 126 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 128 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 129 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_2
# 130 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_14
# 133 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 134 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 136 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 137 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 138 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_15
# 145 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 146 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 148 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 149 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_2
# 150 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_16
# 153 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 154 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 156 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 157 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 158 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_17
# 163 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 164 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 165 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_18
# 169 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 170 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 171 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_19
# 178 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 179 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 181 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 182 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_2
# 183 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_20
# 186 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 187 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 189 "data/maps/FaucetShop/scripts.pory"
	setflag FLAG_FAUCET_QUEST_STARTED
	goto FaucetShop_EventScript_Owner_1


FaucetShop_EventScript_Note::
# 198 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Note_Text_0, MSGBOX_SIGN
	return


FaucetShop_EventScript_Faucet_LooksLikeMine::
# 207 "data/maps/FaucetShop/scripts.pory"
	lock
# 208 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 209 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_2
# 210 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Faucet_LooksLikeMine_Text_0
# 214 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 215 "data/maps/FaucetShop/scripts.pory"
	release
	return


FaucetShop_EventScript_Faucet_Gold::
# 219 "data/maps/FaucetShop/scripts.pory"
	lock
# 220 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 221 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_2
# 222 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Faucet_Gold_Text_0
# 225 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 226 "data/maps/FaucetShop/scripts.pory"
	release
	return


FaucetShop_EventScript_Faucet_Regular::
# 230 "data/maps/FaucetShop/scripts.pory"
	lock
# 231 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 232 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_2
# 233 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Faucet_Regular_Text_0
# 237 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 238 "data/maps/FaucetShop/scripts.pory"
	release
	return


FaucetShop_EventScript_Owner_Text_0:
# 11 "data/maps/FaucetShop/scripts.pory"
	.string "Salesman$"

FaucetShop_EventScript_Owner_Text_1:
# 13 "data/maps/FaucetShop/scripts.pory"
	.string "I need {COLOR RED}three bolts{COLOR DARK_GRAY}, some {COLOR RED}oil{COLOR DARK_GRAY}, and a\n"
	.string "pair of {COLOR RED}pliers{COLOR DARK_GRAY}.$"

FaucetShop_EventScript_Owner_Text_2:
# 20 "data/maps/FaucetShop/scripts.pory"
	.string "Little Archie$"

FaucetShop_EventScript_Owner_Text_3:
# 22 "data/maps/FaucetShop/scripts.pory"
	.string "Here's all the stuff you asked for!$"

FaucetShop_EventScript_Owner_Text_4:
# 36 "data/maps/FaucetShop/scripts.pory"
	.string "Great! Let me just…$"

FaucetShop_EventScript_Owner_Text_5:
# 49 "data/maps/FaucetShop/scripts.pory"
	.string "Here it is! A brand-new plug'n'play\n"
	.string "{COLOR RED}faucet{COLOR DARK_GRAY}!$"

FaucetShop_EventScript_Owner_Text_6:
# 59 "data/maps/FaucetShop/scripts.pory"
	.string "Thanks so much, mister!!$"

FaucetShop_EventScript_Owner_Text_7:
# 70 "data/maps/FaucetShop/scripts.pory"
	.string "Good morning, my friend! Welcome to\n"
	.string "the one and only Faucet Workshop!\p"
	.string "How may I help you today?$"

FaucetShop_EventScript_Owner_Text_8:
# 81 "data/maps/FaucetShop/scripts.pory"
	.string "What is this place?$"

FaucetShop_EventScript_Owner_Text_9:
# 82 "data/maps/FaucetShop/scripts.pory"
	.string "Can I have a faucet?$"

FaucetShop_EventScript_Owner_Text_10:
# 92 "data/maps/FaucetShop/scripts.pory"
	.string "We sell faucets!\p"
	.string "Big faucets, small faucets, new\n"
	.string "faucets, vintage faucets,\l"
	.string "gold-plated faucets, edible faucets,\l"
	.string "explosive faucets, flying faucets,\l"
	.string "four-dimensional faucets, French\l"
	.string "faucets, hot-dog faucets…\p"
	.string "We have everything your heart could\n"
	.string "desire!\p"
	.string "As long as it's a faucet, of course.$"

FaucetShop_EventScript_Owner_Text_11:
# 103 "data/maps/FaucetShop/scripts.pory"
	.string "Now, why would a little boy like you\n"
	.string "need a faucet?\p"
	.string "This is important, grownup business!\p"
	.string "Why don't you go and play somewhere\n"
	.string "else, hm?$"

FaucetShop_EventScript_Owner_Text_12:
# 113 "data/maps/FaucetShop/scripts.pory"
	.string "But I broke the main faucet outside\n"
	.string "our house, and the water's out!\p"
	.string "I need to repair it, or my mom's gonna\n"
	.string "be super mad at me!$"

FaucetShop_EventScript_Owner_Text_13:
# 122 "data/maps/FaucetShop/scripts.pory"
	.string "Hmm, it broke, you say?\p"
	.string "Can I take a look?$"

FaucetShop_EventScript_Owner_Text_14:
# 131 "data/maps/FaucetShop/scripts.pory"
	.string "Here it is!$"

FaucetShop_EventScript_Owner_Text_15:
# 139 "data/maps/FaucetShop/scripts.pory"
	.string "Hmmm…\p"
	.string "… … …\p"
	.string "Well, this is quite the pickle!\p"
	.string "This is a very old model, I can't repair\n"
	.string "it.\p"
	.string "You'll need to buy a new one!$"

FaucetShop_EventScript_Owner_Text_16:
# 151 "data/maps/FaucetShop/scripts.pory"
	.string "Oh man, I don't have any money!$"

FaucetShop_EventScript_Owner_Text_17:
# 159 "data/maps/FaucetShop/scripts.pory"
	.string "… … …\p"
	.string "Well… Sounds like you're a nice boy\n"
	.string "who's just made a mistake.\p"
	.string "To replace this, you'll need the\n"
	.string "{COLOR RED}FAUCETOR-XX3060 SUPER\l"
	.string "2XOC-SERIES9000{COLOR DARK_GRAY}.$"

FaucetShop_EventScript_Owner_Text_18:
# 166 "data/maps/FaucetShop/scripts.pory"
	.string "Normally it costs a pretty penny, but\n"
	.string "what the hell, I'll give you a hefty\l"
	.string "discount!\p"
	.string "(And put it on your mom's tab!)$"

FaucetShop_EventScript_Owner_Text_19:
# 172 "data/maps/FaucetShop/scripts.pory"
	.string "To fit the new faucet to the older\n"
	.string "model's attachment, I'll need a couple\l"
	.string "things…\p"
	.string "I need {COLOR RED}three big bolts{COLOR DARK_GRAY},\l"
	.string "some {COLOR RED}oil{COLOR DARK_GRAY},\l"
	.string "and my only pair of {COLOR RED}pliers{COLOR DARK_GRAY} was stolen\l"
	.string "from me, so I'll need a new pair.\p"
	.string "If you bring me these things, I'll fix\n"
	.string "it up for ya.$"

FaucetShop_EventScript_Owner_Text_20:
# 184 "data/maps/FaucetShop/scripts.pory"
	.string "Oh, thank you sir!! I'll go get\n"
	.string "everything right away!$"

FaucetShop_EventScript_Note_Text_0:
# 199 "data/maps/FaucetShop/scripts.pory"
	.string "The three pillars of our business:\n"
	.string "I. Sell faucets\l"
	.string "II. Aim for greatness\l"
	.string "III. But mainly, sell faucets$"

FaucetShop_EventScript_Faucet_LooksLikeMine_Text_0:
# 211 "data/maps/FaucetShop/scripts.pory"
	.string "A round, spinny faucet.\n"
	.string "Looks just like the one that broke!$"

FaucetShop_EventScript_Faucet_Gold_Text_0:
# 223 "data/maps/FaucetShop/scripts.pory"
	.string "Woah! This one is gold!$"

FaucetShop_EventScript_Faucet_Regular_Text_0:
# 234 "data/maps/FaucetShop/scripts.pory"
	.string "A metal faucet.\n"
	.string "Looks good.$"

FaucetShop_MapScripts::
	.byte 0


FaucetShop_EventScript_Owner::
# 6 "data/maps/FaucetShop/scripts.pory"
	lock
# 7 "data/maps/FaucetShop/scripts.pory"
	faceplayer
# 9 "data/maps/FaucetShop/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_FINISHED, FaucetShop_EventScript_Owner_2
# 18 "data/maps/FaucetShop/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, FaucetShop_EventScript_Owner_3
# 92 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 93 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 94 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_9
# 99 "data/maps/FaucetShop/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, FaucetShop_EventScript_Owner_Text_10, FaucetShop_EventScript_Owner_Text_11
# 109 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 110 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 112 "data/maps/FaucetShop/scripts.pory"
	switch VAR_RESULT
# 113 "data/maps/FaucetShop/scripts.pory"
	case 0, FaucetShop_EventScript_Owner_20
# 124 "data/maps/FaucetShop/scripts.pory"
	case 1, FaucetShop_EventScript_Owner_21
FaucetShop_EventScript_Owner_1:
# 220 "data/maps/FaucetShop/scripts.pory"
	release
	return

FaucetShop_EventScript_Owner_2:
# 10 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 11 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 12 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_1
# 16 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 17 "data/maps/FaucetShop/scripts.pory"
	closemessage
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_3:
# 19 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 20 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 21 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_2
# 24 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 25 "data/maps/FaucetShop/scripts.pory"
	closemessage
	checkitem ITEM_TOUGH_BOLT
# 0 "data/maps/FaucetShop/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne FaucetShop_EventScript_Owner_9
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_7:
# 35 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_GRINNING
# 36 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_3
# 37 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_4
# 40 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 41 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 43 "data/maps/FaucetShop/scripts.pory"
	removeitem ITEM_TOUGH_BOLT
# 44 "data/maps/FaucetShop/scripts.pory"
	removeitem ITEM_PRECIOUS_BOLT
# 45 "data/maps/FaucetShop/scripts.pory"
	removeitem ITEM_RUSTY_BOLT
# 46 "data/maps/FaucetShop/scripts.pory"
	removeitem ITEM_BORROWED_PLIERS
# 47 "data/maps/FaucetShop/scripts.pory"
	removeitem ITEM_COOKING_OIL
# 48 "data/maps/FaucetShop/scripts.pory"
	removeitem ITEM_PB_AND_J
# 50 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 51 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 52 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_5
# 55 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 56 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 58 "data/maps/FaucetShop/scripts.pory"
	playse SE_SWITCH
# 59 "data/maps/FaucetShop/scripts.pory"
	waitse
# 60 "data/maps/FaucetShop/scripts.pory"
	playse SE_SWITCH
# 61 "data/maps/FaucetShop/scripts.pory"
	waitse
# 63 "data/maps/FaucetShop/scripts.pory"
	delay 48
# 65 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 66 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 67 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_6
# 70 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 71 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 73 "data/maps/FaucetShop/scripts.pory"
	giveitem ITEM_NEW_FAUCET
# 75 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 76 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_3
# 77 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_7
# 81 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 82 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 83 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_8
# 86 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 87 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 89 "data/maps/FaucetShop/scripts.pory"
	setflag FLAG_FAUCET_QUEST_FINISHED
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_8:
	checkitem ITEM_RUSTY_BOLT
# 0 "data/maps/FaucetShop/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne FaucetShop_EventScript_Owner_13
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_9:
	checkitem ITEM_PRECIOUS_BOLT
# 0 "data/maps/FaucetShop/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne FaucetShop_EventScript_Owner_8
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_12:
	checkitem ITEM_COOKING_OIL
# 0 "data/maps/FaucetShop/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne FaucetShop_EventScript_Owner_16
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_13:
	checkitem ITEM_BORROWED_PLIERS
# 0 "data/maps/FaucetShop/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne FaucetShop_EventScript_Owner_12
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_16:
	checkitem ITEM_PB_AND_J
# 0 "data/maps/FaucetShop/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne FaucetShop_EventScript_Owner_7
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_20:
# 114 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 115 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 116 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_12
# 122 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 123 "data/maps/FaucetShop/scripts.pory"
	closemessage
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_21:
# 125 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 126 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 127 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_13
# 132 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 133 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 134 "data/maps/FaucetShop/scripts.pory"
	goto_if_set FLAG_FAUCET_BROKE, FaucetShop_EventScript_Owner_22
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_22:
# 135 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 136 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_3
# 137 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_14
# 141 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 142 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 144 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 145 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 146 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_15
# 150 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 151 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 153 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 154 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_3
# 155 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_16
# 158 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 159 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 161 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 162 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 163 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_17
# 170 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 171 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 173 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 174 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_3
# 175 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_18
# 178 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 179 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 181 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 182 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 183 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_19
# 188 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 189 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 190 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_20
# 194 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 195 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 196 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_21
# 204 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 205 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 207 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 208 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_3
# 209 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_22
# 212 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 213 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 215 "data/maps/FaucetShop/scripts.pory"
	setflag FLAG_FAUCET_QUEST_STARTED
	goto FaucetShop_EventScript_Owner_1


FaucetShop_EventScript_Note::
# 224 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Note_Text_0, MSGBOX_SIGN
	return


FaucetShop_EventScript_Faucet_LooksLikeMine::
# 233 "data/maps/FaucetShop/scripts.pory"
	lock
# 234 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 235 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_3
# 236 "data/maps/FaucetShop/scripts.pory"
	goto_if_set FLAG_FAUCET_BROKE, FaucetShop_EventScript_Faucet_LooksLikeMine_2
# 242 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Faucet_LooksLikeMine_Text_1
FaucetShop_EventScript_Faucet_LooksLikeMine_1:
# 247 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 248 "data/maps/FaucetShop/scripts.pory"
	release
	return

FaucetShop_EventScript_Faucet_LooksLikeMine_2:
# 237 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Faucet_LooksLikeMine_Text_0
	goto FaucetShop_EventScript_Faucet_LooksLikeMine_1


FaucetShop_EventScript_Faucet_Gold::
# 252 "data/maps/FaucetShop/scripts.pory"
	lock
# 253 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 254 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_3
# 255 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Faucet_Gold_Text_0
# 258 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 259 "data/maps/FaucetShop/scripts.pory"
	release
	return


FaucetShop_EventScript_Faucet_Regular::
# 263 "data/maps/FaucetShop/scripts.pory"
	lock
# 264 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 265 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_3
# 266 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Faucet_Regular_Text_0
# 270 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 271 "data/maps/FaucetShop/scripts.pory"
	release
	return


FaucetShop_EventScript_Owner_Text_0:
# 11 "data/maps/FaucetShop/scripts.pory"
	.string "Salesman$"

FaucetShop_EventScript_Owner_Text_1:
# 13 "data/maps/FaucetShop/scripts.pory"
	.string "Remember this shop when you grow up\n"
	.string "and need faucets of your own!\p"
	.string "Tell your friends!$"

FaucetShop_EventScript_Owner_Text_2:
# 22 "data/maps/FaucetShop/scripts.pory"
	.string "I need {COLOR RED}three bolts{COLOR DARK_GRAY}, some {COLOR RED}oil{COLOR DARK_GRAY}, a\n"
	.string "{COLOR RED}sandwich{COLOR DARK_GRAY} and a pair of {COLOR RED}pliers{COLOR DARK_GRAY}.$"

FaucetShop_EventScript_Owner_Text_3:
# 36 "data/maps/FaucetShop/scripts.pory"
	.string "Little Archie$"

FaucetShop_EventScript_Owner_Text_4:
# 38 "data/maps/FaucetShop/scripts.pory"
	.string "Here's all the stuff you asked for!$"

FaucetShop_EventScript_Owner_Text_5:
# 53 "data/maps/FaucetShop/scripts.pory"
	.string "Great! Let me just…$"

FaucetShop_EventScript_Owner_Text_6:
# 68 "data/maps/FaucetShop/scripts.pory"
	.string "Here it is! A brand-new plug'n'play\n"
	.string "{COLOR RED}faucet{COLOR DARK_GRAY}!$"

FaucetShop_EventScript_Owner_Text_7:
# 78 "data/maps/FaucetShop/scripts.pory"
	.string "Thanks so much, mister!!\p"
	.string "I gotta ask though, what was the\n"
	.string "{COLOR RED}sandwich{COLOR DARK_GRAY} for?$"

FaucetShop_EventScript_Owner_Text_8:
# 84 "data/maps/FaucetShop/scripts.pory"
	.string "I was hungry.$"

FaucetShop_EventScript_Owner_Text_9:
# 95 "data/maps/FaucetShop/scripts.pory"
	.string "Good morning, my friend! Welcome to\n"
	.string "the one and only Faucet Workshop!\p"
	.string "How may I help you today?$"

FaucetShop_EventScript_Owner_Text_10:
# 106 "data/maps/FaucetShop/scripts.pory"
	.string "What is this place?$"

FaucetShop_EventScript_Owner_Text_11:
# 107 "data/maps/FaucetShop/scripts.pory"
	.string "Can I have a faucet?$"

FaucetShop_EventScript_Owner_Text_12:
# 117 "data/maps/FaucetShop/scripts.pory"
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

FaucetShop_EventScript_Owner_Text_13:
# 128 "data/maps/FaucetShop/scripts.pory"
	.string "Now, why would a little boy like you\n"
	.string "need a faucet?\p"
	.string "This is important, grownup business!\p"
	.string "Why don't you go and play somewhere\n"
	.string "else, hm?$"

FaucetShop_EventScript_Owner_Text_14:
# 138 "data/maps/FaucetShop/scripts.pory"
	.string "But I broke the main faucet outside\n"
	.string "our house, and the water's out!\p"
	.string "I need to repair it, or my mom's gonna\n"
	.string "be super mad at me!$"

FaucetShop_EventScript_Owner_Text_15:
# 147 "data/maps/FaucetShop/scripts.pory"
	.string "Hmm, it broke, you say?\p"
	.string "Can I take a look?$"

FaucetShop_EventScript_Owner_Text_16:
# 156 "data/maps/FaucetShop/scripts.pory"
	.string "Here it is!$"

FaucetShop_EventScript_Owner_Text_17:
# 164 "data/maps/FaucetShop/scripts.pory"
	.string "Hmmm…\p"
	.string "… … …\p"
	.string "Well, this is quite the pickle!\p"
	.string "This is a very old model, I can't repair\n"
	.string "it.\p"
	.string "You'll need to buy a new one!$"

FaucetShop_EventScript_Owner_Text_18:
# 176 "data/maps/FaucetShop/scripts.pory"
	.string "Oh man, I don't have any money!$"

FaucetShop_EventScript_Owner_Text_19:
# 184 "data/maps/FaucetShop/scripts.pory"
	.string "… … …\p"
	.string "Well… Sounds like you're a nice boy\n"
	.string "who's just made a mistake.\p"
	.string "To replace this, you'll need the\n"
	.string "{COLOR RED}FAUCETOR-XX3060 SUPER\l"
	.string "2XOC-SERIES9000{COLOR DARK_GRAY}.$"

FaucetShop_EventScript_Owner_Text_20:
# 191 "data/maps/FaucetShop/scripts.pory"
	.string "Normally it costs a pretty penny, but\n"
	.string "what the hell, I'll give you a hefty\l"
	.string "discount!\p"
	.string "(And put it on your mom's tab!)$"

FaucetShop_EventScript_Owner_Text_21:
# 197 "data/maps/FaucetShop/scripts.pory"
	.string "To fit the new faucet to the older\n"
	.string "model's attachment, I'll need a couple\l"
	.string "things…\p"
	.string "I need {COLOR RED}three big bolts{COLOR DARK_GRAY},\p"
	.string "some {COLOR RED}oil{COLOR DARK_GRAY},\p"
	.string "a {COLOR RED}sandwich{COLOR DARK_GRAY},\p"
	.string "and my only pair of {COLOR RED}pliers{COLOR DARK_GRAY} was stolen\n"
	.string "by some raccoon, so I'll need a new\l"
	.string "pair.\p"
	.string "If you bring me these things, I'll fix\n"
	.string "it up for ya.$"

FaucetShop_EventScript_Owner_Text_22:
# 210 "data/maps/FaucetShop/scripts.pory"
	.string "Oh, thank you sir!! I'll go get\n"
	.string "everything right away!$"

FaucetShop_EventScript_Note_Text_0:
# 225 "data/maps/FaucetShop/scripts.pory"
	.string "The three pillars of our business:\n"
	.string "I. Sell faucets\l"
	.string "II. Aim for greatness\l"
	.string "III. But mainly, sell faucets$"

FaucetShop_EventScript_Faucet_LooksLikeMine_Text_0:
# 238 "data/maps/FaucetShop/scripts.pory"
	.string "A round, spinny faucet.\n"
	.string "Looks just like the one that broke!$"

FaucetShop_EventScript_Faucet_LooksLikeMine_Text_1:
# 243 "data/maps/FaucetShop/scripts.pory"
	.string "A round, spinny faucet.\n"
	.string "Looks just like the one at home!$"

FaucetShop_EventScript_Faucet_Gold_Text_0:
# 256 "data/maps/FaucetShop/scripts.pory"
	.string "Woah! This one is gold!$"

FaucetShop_EventScript_Faucet_Regular_Text_0:
# 267 "data/maps/FaucetShop/scripts.pory"
	.string "A metal faucet.\n"
	.string "Looks good.$"

FaucetShop_MapScripts::
	.byte 0


FaucetShop_EventScript_Owner::
# 6 "data/maps/FaucetShop/scripts.pory"
	lock
# 7 "data/maps/FaucetShop/scripts.pory"
	faceplayer
# 9 "data/maps/FaucetShop/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, FaucetShop_EventScript_Owner_2
# 21 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 22 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 23 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_2
# 28 "data/maps/FaucetShop/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, FaucetShop_EventScript_Owner_Text_3, FaucetShop_EventScript_Owner_Text_4
# 38 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 39 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 41 "data/maps/FaucetShop/scripts.pory"
	switch VAR_RESULT
# 42 "data/maps/FaucetShop/scripts.pory"
	case 0, FaucetShop_EventScript_Owner_6
# 53 "data/maps/FaucetShop/scripts.pory"
	case 1, FaucetShop_EventScript_Owner_7
FaucetShop_EventScript_Owner_1:
# 145 "data/maps/FaucetShop/scripts.pory"
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
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_6:
# 43 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 44 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 45 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_5
# 51 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 52 "data/maps/FaucetShop/scripts.pory"
	closemessage
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_7:
# 54 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 55 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 56 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_6
# 61 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 62 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 63 "data/maps/FaucetShop/scripts.pory"
	goto_if_set FLAG_FAUCET_BROKE, FaucetShop_EventScript_Owner_8
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_8:
# 64 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 65 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_7
# 66 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_8
# 70 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 71 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 73 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 74 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 75 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_9
# 79 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 80 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 82 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 83 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_7
# 84 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_10
# 87 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 88 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 90 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 91 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 92 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_11
# 99 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 100 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 102 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 103 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_7
# 104 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_12
# 107 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 108 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 110 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 111 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 112 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_13
# 117 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 118 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_GRINNING
# 119 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_14
# 123 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 124 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_MAN, EMOTE_NORMAL
# 125 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_15
# 129 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 130 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 132 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 133 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_7
# 134 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_16
# 137 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 138 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 140 "data/maps/FaucetShop/scripts.pory"
	setflag FLAG_FAUCET_QUEST_STARTED
	goto FaucetShop_EventScript_Owner_1


FaucetShop_EventScript_Note::
# 149 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Note_Text_0, MSGBOX_SIGN
	return


FaucetShop_EventScript_Faucet_LooksLikeMine::
# 158 "data/maps/FaucetShop/scripts.pory"
	lock
# 159 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 160 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_7
# 161 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Faucet_LooksLikeMine_Text_0
# 165 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 166 "data/maps/FaucetShop/scripts.pory"
	release
	return


FaucetShop_EventScript_Faucet_Gold::
# 170 "data/maps/FaucetShop/scripts.pory"
	lock
# 171 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 172 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_7
# 173 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Faucet_Gold_Text_0
# 176 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 177 "data/maps/FaucetShop/scripts.pory"
	release
	return


FaucetShop_EventScript_Faucet_Regular::
# 181 "data/maps/FaucetShop/scripts.pory"
	lock
# 182 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 183 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_7
# 184 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Faucet_Regular_Text_0
# 188 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 189 "data/maps/FaucetShop/scripts.pory"
	release
	return


FaucetShop_EventScript_Owner_Text_0:
# 11 "data/maps/FaucetShop/scripts.pory"
	.string "Salesman$"

FaucetShop_EventScript_Owner_Text_1:
# 13 "data/maps/FaucetShop/scripts.pory"
	.string "I need {COLOR RED}three screws{COLOR DARK_GRAY} and a pair of\n"
	.string "{COLOR RED}pliers{COLOR DARK_GRAY}.$"

FaucetShop_EventScript_Owner_Text_2:
# 24 "data/maps/FaucetShop/scripts.pory"
	.string "Good morning, my friend! Welcome to\n"
	.string "the one and only Faucet Workshop!\p"
	.string "How may I help you today?$"

FaucetShop_EventScript_Owner_Text_3:
# 35 "data/maps/FaucetShop/scripts.pory"
	.string "What is this place?$"

FaucetShop_EventScript_Owner_Text_4:
# 36 "data/maps/FaucetShop/scripts.pory"
	.string "Can I have a faucet?$"

FaucetShop_EventScript_Owner_Text_5:
# 46 "data/maps/FaucetShop/scripts.pory"
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

FaucetShop_EventScript_Owner_Text_6:
# 57 "data/maps/FaucetShop/scripts.pory"
	.string "Now, why would a little boy like you\n"
	.string "need a faucet?\p"
	.string "This is important, grownup business!\p"
	.string "Why don't you go and play somewhere\n"
	.string "else, hm?$"

FaucetShop_EventScript_Owner_Text_7:
# 65 "data/maps/FaucetShop/scripts.pory"
	.string "Little Archie$"

FaucetShop_EventScript_Owner_Text_8:
# 67 "data/maps/FaucetShop/scripts.pory"
	.string "But I broke the main faucet outside\n"
	.string "our house, and the water's out!\p"
	.string "I need to repair it, or my mom's gonna\n"
	.string "be super mad at me!$"

FaucetShop_EventScript_Owner_Text_9:
# 76 "data/maps/FaucetShop/scripts.pory"
	.string "Hmm, it broke, you say?\p"
	.string "Can I take a look?$"

FaucetShop_EventScript_Owner_Text_10:
# 85 "data/maps/FaucetShop/scripts.pory"
	.string "Here it is!$"

FaucetShop_EventScript_Owner_Text_11:
# 93 "data/maps/FaucetShop/scripts.pory"
	.string "Hmmm…\p"
	.string "… … …\p"
	.string "Well, this is quite the pickle!\p"
	.string "This is a very old model, I can't repair\n"
	.string "it.\p"
	.string "You'll need to buy a new one!$"

FaucetShop_EventScript_Owner_Text_12:
# 105 "data/maps/FaucetShop/scripts.pory"
	.string "Oh man, I don't have any money!$"

FaucetShop_EventScript_Owner_Text_13:
# 113 "data/maps/FaucetShop/scripts.pory"
	.string "… … …\p"
	.string "Well… Sounds like you're a nice boy\n"
	.string "who's just made a mistake.\p"
	.string "To replace this, you'll need the\n"
	.string "{COLOR RED}FAUCETOR-XX3060 SUPER\l"
	.string "2XOC-SERIES9000{COLOR DARK_GRAY}.$"

FaucetShop_EventScript_Owner_Text_14:
# 120 "data/maps/FaucetShop/scripts.pory"
	.string "Normally it costs a pretty penny, but\n"
	.string "what the hell, I'll give you a hefty\l"
	.string "discount!\p"
	.string "(And put it on your mom's tab!)$"

FaucetShop_EventScript_Owner_Text_15:
# 126 "data/maps/FaucetShop/scripts.pory"
	.string "To fit the new faucet to the older\n"
	.string "model's attachment, I'll need {COLOR RED}three\l"
	.string "big screws{COLOR DARK_GRAY}, and I just broke my only\l"
	.string "pair of {COLOR RED}pliers{COLOR DARK_GRAY}, so I'll need a new pair.\p"
	.string "If you bring me these things, I'll fix\n"
	.string "it up for ya.$"

FaucetShop_EventScript_Owner_Text_16:
# 135 "data/maps/FaucetShop/scripts.pory"
	.string "Oh, thank you sir!! I'll go get\n"
	.string "everything right away!$"

FaucetShop_EventScript_Note_Text_0:
# 150 "data/maps/FaucetShop/scripts.pory"
	.string "The three pillars of our business:\n"
	.string "I. Sell faucets\l"
	.string "II. Aim for greatness\l"
	.string "III. But mainly, sell faucets$"

FaucetShop_EventScript_Faucet_LooksLikeMine_Text_0:
# 162 "data/maps/FaucetShop/scripts.pory"
	.string "A round, spinny faucet.\n"
	.string "Looks just like the one that broke!$"

FaucetShop_EventScript_Faucet_Gold_Text_0:
# 174 "data/maps/FaucetShop/scripts.pory"
	.string "Woah! This one is gold!$"

FaucetShop_EventScript_Faucet_Regular_Text_0:
# 185 "data/maps/FaucetShop/scripts.pory"
	.string "A metal faucet.\n"
	.string "Looks good.$"

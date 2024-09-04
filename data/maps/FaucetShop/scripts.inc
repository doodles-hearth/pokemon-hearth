FaucetShop_MapScripts::
	.byte 0


FaucetShop_EventScript_Owner::
# 6 "data/maps/FaucetShop/scripts.pory"
	lock
# 7 "data/maps/FaucetShop/scripts.pory"
	faceplayer
# 9 "data/maps/FaucetShop/scripts.pory"
	goto_if_set FLAG_FAUCET_QUEST_STARTED, FaucetShop_EventScript_Owner_2
# 18 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 19 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_2
# 24 "data/maps/FaucetShop/scripts.pory"
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, FaucetShop_EventScript_Owner_Text_3, FaucetShop_EventScript_Owner_Text_4
# 34 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 36 "data/maps/FaucetShop/scripts.pory"
	switch VAR_RESULT
# 37 "data/maps/FaucetShop/scripts.pory"
	case 0, FaucetShop_EventScript_Owner_6
# 46 "data/maps/FaucetShop/scripts.pory"
	case 1, FaucetShop_EventScript_Owner_7
FaucetShop_EventScript_Owner_1:
# 121 "data/maps/FaucetShop/scripts.pory"
	release
	return

FaucetShop_EventScript_Owner_2:
# 10 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 11 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_1
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_6:
# 38 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 39 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_5
# 45 "data/maps/FaucetShop/scripts.pory"
	closemessage
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_7:
# 47 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 48 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_6
# 53 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 54 "data/maps/FaucetShop/scripts.pory"
	goto_if_set FLAG_FAUCET_BROKE, FaucetShop_EventScript_Owner_8
	goto FaucetShop_EventScript_Owner_1

FaucetShop_EventScript_Owner_8:
# 55 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 56 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_7
# 57 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_8
# 61 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 62 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 64 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 65 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_9
# 69 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 71 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_NORMAL
# 72 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_7
# 73 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_10
# 76 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 77 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 79 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 80 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_11
# 87 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 89 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_SAD
# 90 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_7
# 91 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_12
# 94 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 95 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 97 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_0
# 98 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_13
# 106 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 108 "data/maps/FaucetShop/scripts.pory"
	createfieldmugshot MUGSHOT_ARCHIE, EMOTE_EXCITED
# 109 "data/maps/FaucetShop/scripts.pory"
	speakername FaucetShop_EventScript_Owner_Text_7
# 110 "data/maps/FaucetShop/scripts.pory"
	msgbox FaucetShop_EventScript_Owner_Text_14
# 113 "data/maps/FaucetShop/scripts.pory"
	removefieldmugshot
# 114 "data/maps/FaucetShop/scripts.pory"
	closemessage
# 116 "data/maps/FaucetShop/scripts.pory"
	setflag FLAG_FAUCET_QUEST_STARTED
	goto FaucetShop_EventScript_Owner_1


FaucetShop_EventScript_Owner_Text_0:
# 10 "data/maps/FaucetShop/scripts.pory"
	.string "Salesman$"

FaucetShop_EventScript_Owner_Text_1:
# 12 "data/maps/FaucetShop/scripts.pory"
	.string "I need {COLOR RED}three screws{COLOR DARK_GRAY} and a pair of\n"
	.string "{COLOR RED}pliers{COLOR DARK_GRAY}.$"

FaucetShop_EventScript_Owner_Text_2:
# 20 "data/maps/FaucetShop/scripts.pory"
	.string "G'day, little dude! Welcome to the one\n"
	.string "and only Faucet Workshop!\p"
	.string "How may I help you today?$"

FaucetShop_EventScript_Owner_Text_3:
# 31 "data/maps/FaucetShop/scripts.pory"
	.string "What is this place?$"

FaucetShop_EventScript_Owner_Text_4:
# 32 "data/maps/FaucetShop/scripts.pory"
	.string "Can I have a faucet?$"

FaucetShop_EventScript_Owner_Text_5:
# 40 "data/maps/FaucetShop/scripts.pory"
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
# 49 "data/maps/FaucetShop/scripts.pory"
	.string "Now, why would a little boy like you\n"
	.string "need a faucet?\p"
	.string "This is important, grownup business!\p"
	.string "Why don't you go and play somewhere\n"
	.string "else, hm?$"

FaucetShop_EventScript_Owner_Text_7:
# 56 "data/maps/FaucetShop/scripts.pory"
	.string "Little Archie$"

FaucetShop_EventScript_Owner_Text_8:
# 58 "data/maps/FaucetShop/scripts.pory"
	.string "But I broke the main faucet outside\n"
	.string "our house, and the water's out!\p"
	.string "I need to repair it, or my mom's gonna\n"
	.string "be super mad at me!$"

FaucetShop_EventScript_Owner_Text_9:
# 66 "data/maps/FaucetShop/scripts.pory"
	.string "Hmm, it broke, you say?\p"
	.string "Can I take a look?$"

FaucetShop_EventScript_Owner_Text_10:
# 74 "data/maps/FaucetShop/scripts.pory"
	.string "Here it is!$"

FaucetShop_EventScript_Owner_Text_11:
# 81 "data/maps/FaucetShop/scripts.pory"
	.string "Hmmm…\p"
	.string "… … …\p"
	.string "Well, this is quite the pickle!\p"
	.string "This is a very old model, I can't repair\n"
	.string "it.\p"
	.string "You'll need to buy a new one!$"

FaucetShop_EventScript_Owner_Text_12:
# 92 "data/maps/FaucetShop/scripts.pory"
	.string "Oh man, I don't have any money!$"

FaucetShop_EventScript_Owner_Text_13:
# 99 "data/maps/FaucetShop/scripts.pory"
	.string "Well… Sounds like you're a nice boy\n"
	.string "who's just made a mistake.\p"
	.string "To replace this, you'll need the\n"
	.string "{COLOR RED}FAUCETOR-XX3060 SUPER\l"
	.string "2XOC-SERIES9000{COLOR DARK_GRAY}.\p"
	.string "Normally it costs a pretty penny, but\n"
	.string "what the hell, I'll give you a hefty\l"
	.string "discount!\p"
	.string "(And put it on your mom's tab!)\p"
	.string "To fit the new faucet to the older\n"
	.string "model's attachment, I'll need {COLOR RED}three\l"
	.string "big screws{COLOR DARK_GRAY}, and I just broke my only\l"
	.string "pair of {COLOR RED}pliers{COLOR DARK_GRAY}, so I'll need a new pair.\p"
	.string "If you bring me these things, I'll fix\n"
	.string "it up for ya.$"

FaucetShop_EventScript_Owner_Text_14:
# 111 "data/maps/FaucetShop/scripts.pory"
	.string "Oh, thank you sir!! I'll go get\n"
	.string "everything right away!$"

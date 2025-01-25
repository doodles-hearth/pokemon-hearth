MaguroHarbor_MapScripts::
	.byte 0


MaguroHarbor_EventScript_TownSign::
	msgbox MaguroHarbor_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


MaguroHarbor_EventScript_LovestruckGirl::
	lock
	faceplayer
	speakername MaguroHarbor_EventScript_LovestruckGirl_Text_0
	msgbox MaguroHarbor_EventScript_LovestruckGirl_Text_1, MSGBOX_DEFAULT
	release
	return


MaguroHarbor_EventScript_FishcakeSalesman::
	lock
	faceplayer
	speakername MaguroHarbor_EventScript_FishcakeSalesman_Text_0
	msgbox MaguroHarbor_EventScript_FishcakeSalesman_Text_1, MSGBOX_DEFAULT
	giveitem ITEM_FISHCAKE
	closemessage
	release
	return


MaguroHarbor_EventScript_FishPokemonSalesman::
	lock
	faceplayer
	speakername MaguroHarbor_EventScript_FishPokemonSalesman_Text_0
	msgbox MaguroHarbor_EventScript_FishPokemonSalesman_Text_1, MSGBOX_DEFAULT
	closemessage
	release
	return


MaguroHarbor_EventScript_FishermanInBoat::
	lock
	faceplayer
	speakername MaguroHarbor_EventScript_FishermanInBoat_Text_0
	msgbox MaguroHarbor_EventScript_FishermanInBoat_Text_1, MSGBOX_DEFAULT
	closemessage
	release
	return


MaguroHarbor_EventScript_Cramorant::
	lock
	faceplayer
	playmoncry SPECIES_CRAMORANT, CRY_MODE_NORMAL
	speakername MaguroHarbor_EventScript_Cramorant_Text_0
	msgbox MaguroHarbor_EventScript_Cramorant_Text_1, MSGBOX_DEFAULT
	closemessage
	release
	return


MaguroHarbor_EventScript_FishermanOldRod::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, MaguroHarbor_EventScript_FishermanOldRod_2
	speakername MaguroHarbor_EventScript_FishermanInBoat_Text_0
	msgbox MaguroHarbor_EventScript_FishermanOldRod_Text_1
	closemessage
	giveitem ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	speakername MaguroHarbor_EventScript_FishermanInBoat_Text_0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq MaguroHarbor_EventScript_FishermanOldRod_5
	msgbox MaguroHarbor_EventScript_FishermanOldRod_Text_3
MaguroHarbor_EventScript_FishermanOldRod_4:
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return

MaguroHarbor_EventScript_FishermanOldRod_2:
	speakername MaguroHarbor_EventScript_FishermanInBoat_Text_0
	msgbox MaguroHarbor_EventScript_FishermanOldRod_Text_0
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MaguroHarbor_EventScript_FishermanOldRod_5:
	msgbox MaguroHarbor_EventScript_FishermanOldRod_Text_2
	goto MaguroHarbor_EventScript_FishermanOldRod_4


MaguroHarbor_EventScript_Man::
	lock
	faceplayer
	speakername MaguroHarbor_EventScript_Man_Text_0
	msgbox MaguroHarbor_EventScript_Man_Text_1
	closemessage
	release
	return


MaguroHarbor_EventScript_Mart::
	lock
	faceplayer
	speakername MaguroHarbor_EventScript_Mart_Text_0
	message gText_HowMayIServeYou
	waitmessage
	pokemart MaguroHarbor_Mart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	return


	.align 2
MaguroHarbor_Mart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_BERRY_JUICE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

MaguroHarbor_EventScript_TownSign_Text_0:
	.string "Maguro Harbor\n"
	.string "“A town that lives hand in hand with\l"
	.string "the sea.”$"

MaguroHarbor_EventScript_LovestruckGirl_Text_0:
	.string "Lovestruck Girl$"

MaguroHarbor_EventScript_LovestruckGirl_Text_1:
	.string "It's only been an hour since I saw my\n"
	.string "love, and yet I already want tomorrow\l"
	.string "to come just so I see him again…$"

MaguroHarbor_EventScript_FishcakeSalesman_Text_0:
	.string "Old woman$"

MaguroHarbor_EventScript_FishcakeSalesman_Text_1:
	.string "Hello dear, want to try a fishcake?\p"
	.string "They're the town's specialty!$"

MaguroHarbor_EventScript_FishPokemonSalesman_Text_0:
	.string "Salesman$"

MaguroHarbor_EventScript_FishPokemonSalesman_Text_1:
	.string "Fresh fish! Come get yer fish!$"

MaguroHarbor_EventScript_FishermanInBoat_Text_0:
	.string "Fisherman$"

MaguroHarbor_EventScript_FishermanInBoat_Text_1:
	.string "I'm letting my fishing partner\n"
	.string "Cramorant rest for a while.$"

MaguroHarbor_EventScript_Cramorant_Text_0:
	.string "Cramorant$"

MaguroHarbor_EventScript_Cramorant_Text_1:
	.string "Craaah!$"

MaguroHarbor_EventScript_FishermanOldRod_Text_0:
	.string "Heyo, wee fisherm'n! Hope ye be\n"
	.string "enjoyin' yer fishing rod!$"

MaguroHarbor_EventScript_FishermanOldRod_Text_1:
	.string "Shush, ye fool child! You're scarin'\n"
	.string "tha wee fishes!\p"
	.string "… … … …\p"
	.string "Yer eyes… They be sparklin' with\n"
	.string "passion… Are ye by any chance an\l"
	.string "aspirin' fisherm'n?\p"
	.string "Ye are! I can feel it! I can see ye be\n"
	.string "dyin' to try it fer yerself!\p"
	.string "Now, I can't be givin' ye me loyal\n"
	.string "Cramorant here…\p"
	.string "But I can give ye this ol' rud o' mine!$"

MaguroHarbor_EventScript_FishermanOldRod_Text_2:
	.string "It be a wee bit used, but I reckon it\n"
	.string "will serve ye mighty fine!\p"
	.string "Farewell, lad! May ye become a great\n"
	.string "fisherm'n!$"

MaguroHarbor_EventScript_FishermanOldRod_Text_3:
	.string "It be a wee bit used, but I reckon it\n"
	.string "will serve ye mighty fine!\p"
	.string "Farewell, lass! May ye become a great\n"
	.string "fisherm'n!$"

MaguroHarbor_EventScript_Man_Text_0:
	.string "Man$"

MaguroHarbor_EventScript_Man_Text_1:
	.string "I wish I swam as gracefully as the\n"
	.string "Dojo's Magikarp…$"

MaguroHarbor_EventScript_Mart_Text_0:
	.string "Clerk$"

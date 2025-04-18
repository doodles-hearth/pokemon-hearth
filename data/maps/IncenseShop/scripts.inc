IncenseShop_MapScripts::
	.byte 0


IncenseShop_EventScript_Drowzee::
	lock
	faceplayer
	setseenmon SPECIES_DROWZEE
	setspeakertomonname SPECIES_DROWZEE
	playmoncry SPECIES_DROWZEE, CRY_MODE_NORMAL
	msgbox IncenseShop_EventScript_Drowzee_Text_0
	waitmoncry
	closemessage
	release
	return


IncenseShop_EventScript_BlueIncense::
	lock
	msgbox IncenseShop_EventScript_BlueIncense_Text_0
	closemessage
	release
	return


IncenseShop_EventScript_GreenIncense::
	lock
	msgbox IncenseShop_EventScript_GreenIncense_Text_0
	closemessage
	release
	return


IncenseShop_EventScript_RedIncense::
	lock
	msgbox IncenseShop_EventScript_RedIncense_Text_0
	closemessage
	release
	return


IncenseShop_EventScript_PurpleIncense::
	lock
	msgbox IncenseShop_EventScript_PurpleIncense_Text_0
	closemessage
	release
	return


IncenseShop_EventScript_Shopkeeper::
	lock
	goto_if_set FLAG_TALKED_TO_INCENSE_SHOP_KEEPER, IncenseShop_EventScript_Shopkeeper_2
	speakername IncenseShop_EventScript_Shopkeeper_Text_0
	msgbox IncenseShop_EventScript_Shopkeeper_Text_3
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, IncenseShop_EventScript_Shopkeeper_Text_4, IncenseShop_EventScript_Shopkeeper_Text_5, IncenseShop_EventScript_Shopkeeper_Text_6
	closemessage
	switch VAR_RESULT
	case 0, IncenseShop_EventScript_Shopkeeper_6
	case 1, IncenseShop_EventScript_Shopkeeper_6
IncenseShop_EventScript_Shopkeeper_1:
	release
	return

IncenseShop_EventScript_Shopkeeper_2:
	speakername IncenseShop_EventScript_Shopkeeper_Text_0
	msgbox IncenseShop_EventScript_Shopkeeper_Text_1
	closemessage
	delay 30
	faceplayer
	msgbox IncenseShop_EventScript_Shopkeeper_Text_2
	closemessage
	call IncenseShop_EventScript_OpenMart
	goto IncenseShop_EventScript_Shopkeeper_1

IncenseShop_EventScript_Shopkeeper_6:
	speakername IncenseShop_EventScript_Shopkeeper_Text_0
	msgbox IncenseShop_EventScript_Shopkeeper_Text_7
	closemessage
	faceplayer
	delay 30
	speakername IncenseShop_EventScript_Shopkeeper_Text_0
	msgbox IncenseShop_EventScript_Shopkeeper_Text_8
	closemessage
	setflag FLAG_TALKED_TO_INCENSE_SHOP_KEEPER
	call IncenseShop_EventScript_OpenMart
	goto IncenseShop_EventScript_Shopkeeper_1


IncenseShop_EventScript_OpenMart::
	goto_if_set FLAG_BADGE06_GET, IncenseShop_EventScript_OpenMart_2
	goto_if_set FLAG_BADGE05_GET, IncenseShop_EventScript_OpenMart_3
	goto_if_set FLAG_BADGE04_GET, IncenseShop_EventScript_OpenMart_4
	pokemart IncenseShop_Mart_1
IncenseShop_EventScript_OpenMart_1:
	speakername IncenseShop_EventScript_Shopkeeper_Text_0
	msgbox IncenseShop_EventScript_OpenMart_Text_0, MSGBOX_DEFAULT
	return

IncenseShop_EventScript_OpenMart_2:
	pokemart IncenseShop_Mart_4
	goto IncenseShop_EventScript_OpenMart_1

IncenseShop_EventScript_OpenMart_3:
	pokemart IncenseShop_Mart_3
	goto IncenseShop_EventScript_OpenMart_1

IncenseShop_EventScript_OpenMart_4:
	pokemart IncenseShop_Mart_2
	goto IncenseShop_EventScript_OpenMart_1


	.align 2
IncenseShop_Mart_1:
	.2byte ITEM_ROSE_INCENSE
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_ROCK_INCENSE
	.2byte ITEM_NONE

	.align 2
IncenseShop_Mart_2:
	.2byte ITEM_ROSE_INCENSE
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_ROCK_INCENSE
	.2byte ITEM_PURE_INCENSE
	.2byte ITEM_LUCK_INCENSE
	.2byte ITEM_NONE

	.align 2
IncenseShop_Mart_3:
	.2byte ITEM_ROSE_INCENSE
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_ROCK_INCENSE
	.2byte ITEM_PURE_INCENSE
	.2byte ITEM_LUCK_INCENSE
	.2byte ITEM_ODD_INCENSE
	.2byte ITEM_NONE

	.align 2
IncenseShop_Mart_4:
	.2byte ITEM_ROSE_INCENSE
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_ROCK_INCENSE
	.2byte ITEM_PURE_INCENSE
	.2byte ITEM_LUCK_INCENSE
	.2byte ITEM_ODD_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_FULL_INCENSE
	.2byte ITEM_NONE

IncenseShop_EventScript_Drowzee_Text_0:
	.string "Hrmmm…$"

IncenseShop_EventScript_BlueIncense_Text_0:
	.string "An incense that smells like salt and\n"
	.string "sun-baked seaweed.$"

IncenseShop_EventScript_GreenIncense_Text_0:
	.string "An incense that smells like ripe\n"
	.string "Berries and roses.$"

IncenseShop_EventScript_RedIncense_Text_0:
	.string "An incense that smells like smoked\n"
	.string "maple and charcoal.$"

IncenseShop_EventScript_PurpleIncense_Text_0:
	.string "An incense that smells like myrrh and\n"
	.string "hot oil.$"

IncenseShop_EventScript_Shopkeeper_Text_0:
	.string "Shopkeeper$"

IncenseShop_EventScript_Shopkeeper_Text_1:
	.string "… … … … … …\n"
	.string "… … … ZzzZz…$"

IncenseShop_EventScript_Shopkeeper_Text_2:
	.string "… … …I'm awake! I'm awake!\p"
	.string "{FONT_SMALL}Yawn{FONT_NORMAL}… Welcome to the Incense Shop…$"

IncenseShop_EventScript_Shopkeeper_Text_3:
	.string "… … … … … …\n"
	.string "… … … … … …$"

IncenseShop_EventScript_Shopkeeper_Text_4:
	.string "Excuse me!$"

IncenseShop_EventScript_Shopkeeper_Text_5:
	.string "Hello?$"

IncenseShop_EventScript_Shopkeeper_Text_6:
	.string "… … …$"

IncenseShop_EventScript_Shopkeeper_Text_7:
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "… … …ZzzZZz…\p"
	.string "… … … … … …\n"
	.string "… … … Huh?$"

IncenseShop_EventScript_Shopkeeper_Text_8:
	.string "…Oh, yes hello, welcome…\n"
	.string "{FONT_SMALL}Yawn{FONT_NORMAL}… …to the Incense Shop…\p"
	.string "I'm sorry, the Incense in the air\n"
	.string "makes me a little sleepy…\p"
	.string "We sell a variety of Incenses each\n"
	.string "with its unique effects…\p"
	.string "Feel free to {FONT_SMALL}-yawn-{FONT_NORMAL} peruse…$"

IncenseShop_EventScript_OpenMart_Text_0:
	.string "Please come again…\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "…ZzzZZzzzZZZZzzZZZz…$"

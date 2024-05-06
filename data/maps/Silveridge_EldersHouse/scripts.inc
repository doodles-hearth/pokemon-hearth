Silveridge_EldersHouse_MapScripts::
	.byte 0


Silveridge_EldersHouse_EventScript_Elder::
# 7 "data/maps/Silveridge_EldersHouse/scripts.pory"
	lock
# 8 "data/maps/Silveridge_EldersHouse/scripts.pory"
	faceplayer
# 10 "data/maps/Silveridge_EldersHouse/scripts.pory"
	checkitem ITEM_SKY_PLATE
# 11 "data/maps/Silveridge_EldersHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Silveridge_EldersHouse_EventScript_Elder_2
# 17 "data/maps/Silveridge_EldersHouse/scripts.pory"
	msgbox Silveridge_EldersHouse_EventScript_Elder_Text_1
# 26 "data/maps/Silveridge_EldersHouse/scripts.pory"
	giveitem ITEM_SKY_PLATE
# 27 "data/maps/Silveridge_EldersHouse/scripts.pory"
	msgbox Silveridge_EldersHouse_EventScript_Elder_Text_2
Silveridge_EldersHouse_EventScript_Elder_1:
# 33 "data/maps/Silveridge_EldersHouse/scripts.pory"
	release
	return

Silveridge_EldersHouse_EventScript_Elder_2:
# 12 "data/maps/Silveridge_EldersHouse/scripts.pory"
	msgbox Silveridge_EldersHouse_EventScript_Elder_Text_0
	goto Silveridge_EldersHouse_EventScript_Elder_1


Silveridge_EldersHouse_EventScript_Elder_Text_0:
# 13 "data/maps/Silveridge_EldersHouse/scripts.pory"
	.string "Go forth, my child.$"

Silveridge_EldersHouse_EventScript_Elder_Text_1:
# 18 "data/maps/Silveridge_EldersHouse/scripts.pory"
	.string "Hello, child. I am Iwa, the elder of\n"
	.string "Silveridge. What brings you to me?\p"
	.string "……………\p"
	.string "Oh, I see! So Kaba sent you! Insert\n"
	.string "interesting dialog about the Pokémon\l"
	.string "attacking people here\p"
	.string "……………Yes… I can see why Kaba has\n"
	.string "trusted you with coming to see me.\p"
	.string "Perhaps you've seen or heard about\n"
	.string "bigger, stronger Pokémon that have\l"
	.string "gone mad; we call them the TODO EVA.\l"
	.string "They are very difficult to stop.\p"
	.string "That is, unless you have this in your\n"
	.string "posession.$"

Silveridge_EldersHouse_EventScript_Elder_Text_2:
# 28 "data/maps/Silveridge_EldersHouse/scripts.pory"
	.string "This is a copy of one of the very\n"
	.string "ancient Tablets of Power. It is said\l"
	.string "that to possess all the Tablets of\l"
	.string "Power grants one with absolute power\l"
	.string "over Pokémon.\p"
	.string "I am entrusting this one to you. It\n"
	.string "should grant you enough power to be\l"
	.string "able to battle a TODO EVA.\p"
	.string "I am convinced that by gathering these\n"
	.string "Tablets of Power, we will find the\l"
	.string "answer to why the Pokémon are\l"
	.string "attacking us.\p"
	.string "$"

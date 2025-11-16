Soulkeep_Library_1F_MapScripts::
	.byte 0


Soulkeep_Library_1F_EventScript_Employee::
	lock
	faceplayer
	setspeaker Soulkeep_Library_1F_EventScript_Employee_Text_0
	msgbox Soulkeep_Library_1F_EventScript_Employee_Text_1
	closemessage
	release
	return


Soulkeep_Library_1F_EventScript_Man::
	lock
	faceplayer
	msgbox Soulkeep_Library_1F_EventScript_Man_Text_0
	closemessage
	release
	return


Soulkeep_Library_1F_EventScript_Book_Recipe::
	lock
	msgbox Soulkeep_Library_1F_EventScript_Book_Recipe_Text_0
	dynmultichoice 0, 0, FALSE, 10, 0, DYN_MULTICHOICE_CB_NONE, Soulkeep_Library_1F_EventScript_Book_Recipe_Text_1, Soulkeep_Library_1F_EventScript_Book_Recipe_Text_2
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq Soulkeep_Library_1F_EventScript_Book_Recipe_2
Soulkeep_Library_1F_EventScript_Book_Recipe_1:
	release
	return

Soulkeep_Library_1F_EventScript_Book_Recipe_2:
	msgbox Soulkeep_Library_1F_EventScript_Book_Recipe_Text_3
	closemessage
	setnamedmon SPECIES_SHIFTRY
	goto Soulkeep_Library_1F_EventScript_Book_Recipe_1


Soulkeep_Library_1F_EventScript_Book_CameruptsBack::
	lock
	msgbox Soulkeep_Library_1F_EventScript_Book_CameruptsBack_Text_0
	dynmultichoice 0, 0, FALSE, 10, 0, DYN_MULTICHOICE_CB_NONE, Soulkeep_Library_1F_EventScript_Book_Recipe_Text_1, Soulkeep_Library_1F_EventScript_Book_Recipe_Text_2
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq Soulkeep_Library_1F_EventScript_Book_CameruptsBack_2
Soulkeep_Library_1F_EventScript_Book_CameruptsBack_1:
	setnamedmon SPECIES_CAMERUPT
	release
	return

Soulkeep_Library_1F_EventScript_Book_CameruptsBack_2:
	msgbox Soulkeep_Library_1F_EventScript_Book_CameruptsBack_Text_1
	closemessage
	goto Soulkeep_Library_1F_EventScript_Book_CameruptsBack_1


Soulkeep_Library_1F_EventScript_Book_SpinHaiku::
	lock
	msgbox Soulkeep_Library_1F_EventScript_Book_SpinHaiku_Text_0
	dynmultichoice 0, 0, FALSE, 10, 0, DYN_MULTICHOICE_CB_NONE, Soulkeep_Library_1F_EventScript_Book_Recipe_Text_1, Soulkeep_Library_1F_EventScript_Book_Recipe_Text_2
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq Soulkeep_Library_1F_EventScript_Book_SpinHaiku_2
Soulkeep_Library_1F_EventScript_Book_SpinHaiku_1:
	release
	return

Soulkeep_Library_1F_EventScript_Book_SpinHaiku_2:
	random 2
	switch VAR_RESULT
	case 0, Soulkeep_Library_1F_EventScript_Book_SpinHaiku_6
	case 1, Soulkeep_Library_1F_EventScript_Book_SpinHaiku_7
Soulkeep_Library_1F_EventScript_Book_SpinHaiku_4:
	closemessage
	goto Soulkeep_Library_1F_EventScript_Book_SpinHaiku_1

Soulkeep_Library_1F_EventScript_Book_SpinHaiku_6:
	msgbox Soulkeep_Library_1F_EventScript_Book_SpinHaiku_Text_1
	goto Soulkeep_Library_1F_EventScript_Book_SpinHaiku_4

Soulkeep_Library_1F_EventScript_Book_SpinHaiku_7:
	msgbox Soulkeep_Library_1F_EventScript_Book_SpinHaiku_Text_2
	goto Soulkeep_Library_1F_EventScript_Book_SpinHaiku_4


Soulkeep_Library_1F_EventScript_Book_Ditto::
	lock
	setnamedmon SPECIES_DITTO
	msgbox Soulkeep_Library_1F_EventScript_Book_Ditto_Text_0
	dynmultichoice 0, 0, FALSE, 10, 0, DYN_MULTICHOICE_CB_NONE, Soulkeep_Library_1F_EventScript_Book_Recipe_Text_1, Soulkeep_Library_1F_EventScript_Book_Recipe_Text_2
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq Soulkeep_Library_1F_EventScript_Book_Ditto_2
Soulkeep_Library_1F_EventScript_Book_Ditto_1:
	release
	return

Soulkeep_Library_1F_EventScript_Book_Ditto_2:
	msgbox Soulkeep_Library_1F_EventScript_Book_Ditto_Text_1
	closemessage
	setnamedmon SPECIES_JOLTIK
	setnamedmon SPECIES_NIDORINA
	goto Soulkeep_Library_1F_EventScript_Book_Ditto_1


Soulkeep_Library_1F_EventScript_Book_Dragonite::
	lock
	setnamedmon SPECIES_DRAGONITE
	msgbox Soulkeep_Library_1F_EventScript_Book_Dragonite_Text_0
	dynmultichoice 0, 0, FALSE, 10, 0, DYN_MULTICHOICE_CB_NONE, Soulkeep_Library_1F_EventScript_Book_Recipe_Text_1, Soulkeep_Library_1F_EventScript_Book_Recipe_Text_2
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq Soulkeep_Library_1F_EventScript_Book_Dragonite_2
Soulkeep_Library_1F_EventScript_Book_Dragonite_1:
	release
	return

Soulkeep_Library_1F_EventScript_Book_Dragonite_2:
	msgbox Soulkeep_Library_1F_EventScript_Book_Dragonite_Text_1
	closemessage
	setnamedmon SPECIES_NUZLEAF
	goto Soulkeep_Library_1F_EventScript_Book_Dragonite_1


Soulkeep_Library_1F_EventScript_Book_SpicyNovel::
	lock
	msgbox Soulkeep_Library_1F_EventScript_Book_SpicyNovel_Text_0
	closemessage
	release
	return


Soulkeep_Library_1F_EventScript_SignNovels::
	msgbox Soulkeep_Library_1F_EventScript_SignNovels_Text_0, MSGBOX_SIGN
	return


Soulkeep_Library_1F_EventScript_SignKidlit::
	msgbox Soulkeep_Library_1F_EventScript_SignKidlit_Text_0, MSGBOX_SIGN
	return


Soulkeep_Library_1F_EventScript_SignRecipes::
	msgbox Soulkeep_Library_1F_EventScript_SignRecipes_Text_0, MSGBOX_SIGN
	return


Soulkeep_Library_1F_EventScript_SignPokemon::
	msgbox Soulkeep_Library_1F_EventScript_SignPokemon_Text_0, MSGBOX_SIGN
	return


Soulkeep_Library_1F_EventScript_SignMyths::
	msgbox Soulkeep_Library_1F_EventScript_SignMyths_Text_0, MSGBOX_SIGN
	return


Soulkeep_Library_1F_EventScript_SignPoetry::
	msgbox Soulkeep_Library_1F_EventScript_SignPoetry_Text_0, MSGBOX_SIGN
	return


Soulkeep_Library_1F_EventScript_Employee_Text_0:
	.string "Librarian$"

Soulkeep_Library_1F_EventScript_Employee_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_VALET EMOTE_NORMAL}{FONT_SMALL}Hello, welcome to the library.\n"
	.string "Please don't speak too loud.{FONT_NORMAL}$"

Soulkeep_Library_1F_EventScript_Man_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_COOK EMOTE_NORMAL}{SPEAKER NAME_COOK}{FONT_SMALL}There are tons of good recipes here!{FONT_NORMAL}$"

Soulkeep_Library_1F_EventScript_Book_Recipe_Text_0:
	.string "“Traditional Berry Recipes”.\nRead this?$"

Soulkeep_Library_1F_EventScript_Book_Recipe_Text_1:
	.string "Read$"

Soulkeep_Library_1F_EventScript_Book_Recipe_Text_2:
	.string "Put back$"

Soulkeep_Library_1F_EventScript_Book_Recipe_Text_3:
	.string "“Shiftry Leaf-wrapped Uume Berry\n"
	.string "1. Rub Uume Berries with a Salt Cube.\p"
	.string "2. Sun-dry for two to three days.\n"
	.string "3. Carefully wrap in Shiftry Leaves.\p"
	.string "4. Steam for ten minutes.\n"
	.string "5. Serve warm or room-temperature.”\p"
	.string "{PLAYER} is getting hungry…$"

Soulkeep_Library_1F_EventScript_Book_CameruptsBack_Text_0:
	.string "“The Unstable World”.\nRead this?$"

Soulkeep_Library_1F_EventScript_Book_CameruptsBack_Text_1:
	.string "“Our world rests precariously onto a\nCamerupt's back.\p"
	.string "That Camerupt rests on another\n"
	.string "Camerupt, which rests on another\l"
	.string "Camerupt, which rests on another\l"
	.string "Camerupt, which rests on another\l"
	.string "Camerupt, which rests on another\l"
	.string "Camerupt, which rests on another…”\p"
	.string "… … …{PLAYER} is getting sleepy.\nBetter put the book back.$"

Soulkeep_Library_1F_EventScript_Book_SpinHaiku_Text_0:
	.string "“Spiraling Haiku”.\nRead a haiku?$"

Soulkeep_Library_1F_EventScript_Book_SpinHaiku_Text_1:
	.string "“Ocean waves swimming{PAUSE_UNTIL_PRESS}\n"
	.string "From the center of the sea\l"
	.string "With faith to reach land.”$"

Soulkeep_Library_1F_EventScript_Book_SpinHaiku_Text_2:
	.string "“The rustling leaves{PAUSE_UNTIL_PRESS}\n"
	.string "They are calling to my heart\l"
	.string "Yearning for a touch.”$"

Soulkeep_Library_1F_EventScript_Book_Ditto_Text_0:
	.string "“The Lonely Ditto”.\nRead this?$"

Soulkeep_Library_1F_EventScript_Book_Ditto_Text_1:
	.string "“There once was a lonely Ditto, who\ndesperately seeked a friend.\p"
	.string "It met a Joltik and became tiny and\n"
	.string "yellow, but the Joltik got spooked\l"
	.string "and scurried away.\p"
	.string "It met a Nidorina and became spiky\n"
	.string "and blue, but the Nidorina got angry\l"
	.string "and rammed it with its horn.\p"
	.string "Finally it met a little girl, who said:\n"
	.string "You need not change to look like me,\l"
	.string "for I like you just the way you are!\p"
	.string "The Ditto's heart overflowed with\n"
	.string "happiness, and they remained together\lforever.”$"

Soulkeep_Library_1F_EventScript_Book_Dragonite_Text_0:
	.string "“The Boy And The Dragonite Gay”.\nRead this?$"

Soulkeep_Library_1F_EventScript_Book_Dragonite_Text_1:
	.string "“There once was a free-spirited boy,\n"
	.string "who loved to play in the woods.\p"
	.string "The woods were fraught with peril,\nand one day, a band of Nuzleaf\lambushed the boy.\p"
	.string "Yet there be Dragonite there, and as\nthey flew through the woods, one\lcame swooping down.\p"
	.string "The Dragon spit forth a burst of\nflames, saving the boy's life.\p"
	.string "With what half seemed a smile, the\nDragon approached the wounded child\land gently raised him upon his back.\p"
	.string "And the two flew off, to gods know\nwhere.”$"

Soulkeep_Library_1F_EventScript_Book_SpicyNovel_Text_0:
	.string "“The Lusty Dryuugonian Maiden”.\n… … …Better put this back.$"

Soulkeep_Library_1F_EventScript_SignNovels_Text_0:
	.string "“Novels”$"

Soulkeep_Library_1F_EventScript_SignKidlit_Text_0:
	.string "“Children's books & Fairytales”$"

Soulkeep_Library_1F_EventScript_SignRecipes_Text_0:
	.string "“Food & Recipes”$"

Soulkeep_Library_1F_EventScript_SignPokemon_Text_0:
	.string "“Pokémon”$"

Soulkeep_Library_1F_EventScript_SignMyths_Text_0:
	.string "“Myths & Legends”$"

Soulkeep_Library_1F_EventScript_SignPoetry_Text_0:
	.string "“Poetry”$"

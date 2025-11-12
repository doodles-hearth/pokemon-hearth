Soulkeep_Library_1F_MapScripts::
	.byte 0


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


Soulkeep_Library_1F_EventScript_Book_Recipe_Text_0:
	.string "“Traditional Recipes”.\nRead this?$"

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

Soulkeep_Library_1F_EventScript_Book_Ditto_Text_0:
	.string "“The Lonely Ditto”.\nRead this?$"

Soulkeep_Library_1F_EventScript_Book_Ditto_Text_1:
	.string "“There once was a lonely Ditto, who\ndesperatly seeked a friend.\p"
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

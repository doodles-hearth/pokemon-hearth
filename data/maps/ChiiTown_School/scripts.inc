ChiiTown_School_MapScripts::
	.byte 0


ChiiTown_School_EventScript_Teacher::
# 6 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 7 "data/maps/ChiiTown_School/scripts.pory"
	faceplayer
# 9 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_Teacher_Text_0
# 10 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_Teacher_Text_1
# 15 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 17 "data/maps/ChiiTown_School/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 18 "data/maps/ChiiTown_School/scripts.pory"
	waitmovement 0
# 19 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_BoardLegend::
# 23 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 24 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_BoardLegend_Text_0
# 30 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 31 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_Board::
# 35 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 36 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_Board_Text_0
# 39 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 40 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_ChildImBored::
# 44 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 45 "data/maps/ChiiTown_School/scripts.pory"
	faceplayer
# 47 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
# 48 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_ChildImBored_Text_1
# 51 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 53 "data/maps/ChiiTown_School/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 54 "data/maps/ChiiTown_School/scripts.pory"
	waitmovement 0
# 55 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_ChildAlreadyKnowLegend::
# 59 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 60 "data/maps/ChiiTown_School/scripts.pory"
	faceplayer
# 62 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
# 63 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_ChildAlreadyKnowLegend_Text_0
# 66 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 68 "data/maps/ChiiTown_School/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 69 "data/maps/ChiiTown_School/scripts.pory"
	waitmovement 0
# 70 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_ChildPokemonInsideVolcano::
# 74 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 75 "data/maps/ChiiTown_School/scripts.pory"
	faceplayer
# 77 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
# 78 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_ChildPokemonInsideVolcano_Text_0
# 81 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 83 "data/maps/ChiiTown_School/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 84 "data/maps/ChiiTown_School/scripts.pory"
	waitmovement 0
# 85 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_ChildTellsStory::
# 89 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 90 "data/maps/ChiiTown_School/scripts.pory"
	faceplayer
# 92 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
# 93 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_ChildTellsStory_Text_0
# 97 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 99 "data/maps/ChiiTown_School/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 100 "data/maps/ChiiTown_School/scripts.pory"
	waitmovement 0
# 101 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_IsThePokemonWakingUp::
# 105 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 106 "data/maps/ChiiTown_School/scripts.pory"
	faceplayer
# 108 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
# 109 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_IsThePokemonWakingUp_Text_0
# 114 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 116 "data/maps/ChiiTown_School/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 117 "data/maps/ChiiTown_School/scripts.pory"
	waitmovement 0
# 118 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_ChildWiseGlasses::
# 122 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 123 "data/maps/ChiiTown_School/scripts.pory"
	faceplayer
# 125 "data/maps/ChiiTown_School/scripts.pory"
	goto_if_unset FLAG_SMART_GLASSES, ChiiTown_School_EventScript_ChildWiseGlasses_2
ChiiTown_School_EventScript_ChildWiseGlasses_1:
# 137 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
# 138 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_ChildWiseGlasses_Text_1
# 141 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 143 "data/maps/ChiiTown_School/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 144 "data/maps/ChiiTown_School/scripts.pory"
	waitmovement 0
# 145 "data/maps/ChiiTown_School/scripts.pory"
	release
	return

ChiiTown_School_EventScript_ChildWiseGlasses_2:
# 126 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
# 127 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_ChildWiseGlasses_Text_0
# 131 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 133 "data/maps/ChiiTown_School/scripts.pory"
	giveitem ITEM_WISE_GLASSES
# 134 "data/maps/ChiiTown_School/scripts.pory"
	setflag FLAG_SMART_GLASSES
	goto ChiiTown_School_EventScript_ChildWiseGlasses_1


ChiiTown_School_EventScript_ChildLikeSensei::
# 149 "data/maps/ChiiTown_School/scripts.pory"
	lock
# 150 "data/maps/ChiiTown_School/scripts.pory"
	faceplayer
# 152 "data/maps/ChiiTown_School/scripts.pory"
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
# 153 "data/maps/ChiiTown_School/scripts.pory"
	msgbox ChiiTown_School_EventScript_ChildLikeSensei_Text_0
# 156 "data/maps/ChiiTown_School/scripts.pory"
	closemessage
# 158 "data/maps/ChiiTown_School/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 159 "data/maps/ChiiTown_School/scripts.pory"
	waitmovement 0
# 160 "data/maps/ChiiTown_School/scripts.pory"
	release
	return


ChiiTown_School_EventScript_Teacher_Text_0:
# 9 "data/maps/ChiiTown_School/scripts.pory"
	.string "Sensei$"

ChiiTown_School_EventScript_Teacher_Text_1:
# 11 "data/maps/ChiiTown_School/scripts.pory"
	.string "Um… Aren't you a little old for\n"
	.string "this class?\p"
	.string "It's alright, you can stay!\p"
	.string "Today we're doing some creative\n"
	.string "writing about the Toku legends.$"

ChiiTown_School_EventScript_BoardLegend_Text_0:
# 25 "data/maps/ChiiTown_School/scripts.pory"
	.string "A detailed print depicts\n"
	.string "an old legend.\p"
	.string "“A very long time ago, the Volcano\n"
	.string "erupted terribly.\p"
	.string "Four awakened Treasures fought\n"
	.string "the fiery Pokémon that lived\l"
	.string "inside it.\p"
	.string "At last, the four Treasures and\n"
	.string "the fiery Pokémon slumbered again.”$"

ChiiTown_School_EventScript_Board_Text_0:
# 37 "data/maps/ChiiTown_School/scripts.pory"
	.string "A wide sheet of paper with lots of\n"
	.string "tiny squiggles on it.$"

ChiiTown_School_EventScript_ChildImBored_Text_0:
# 47 "data/maps/ChiiTown_School/scripts.pory"
	.string "Child$"

ChiiTown_School_EventScript_ChildImBored_Text_1:
# 49 "data/maps/ChiiTown_School/scripts.pory"
	.string "I'm bored! Why won't recess start\n"
	.string "already!$"

ChiiTown_School_EventScript_ChildAlreadyKnowLegend_Text_0:
# 64 "data/maps/ChiiTown_School/scripts.pory"
	.string "I already knew all of this! My gramma\n"
	.string "told me about the legend a bajillion\l"
	.string "times!$"

ChiiTown_School_EventScript_ChildPokemonInsideVolcano_Text_0:
# 79 "data/maps/ChiiTown_School/scripts.pory"
	.string "There's a Pokémon inside the\n"
	.string "volcano?! That's AWESOME!$"

ChiiTown_School_EventScript_ChildTellsStory_Text_0:
# 94 "data/maps/ChiiTown_School/scripts.pory"
	.string "I know the story, I know the story!\p"
	.string "Once upon a time, the Volcano Pokémon\n"
	.string "woke up, and then there was fire\l"
	.string "everywhere, and then four Pokémon\l"
	.string "were fighting the Volcano one, and\l"
	.string "then the Volcano stopped spitting\l"
	.string "fire because the Pokémon went back\l"
	.string "to sleep!$"

ChiiTown_School_EventScript_IsThePokemonWakingUp_Text_0:
# 110 "data/maps/ChiiTown_School/scripts.pory"
	.string "When the Volcano Pokémon went to\n"
	.string "bed, the Volcano stopped erupting!\p"
	.string "But the Volcano has been rumbling for\n"
	.string "days now…\p"
	.string "Does that mean the Pokémon's waking\n"
	.string "up again?$"

ChiiTown_School_EventScript_ChildWiseGlasses_Text_0:
# 128 "data/maps/ChiiTown_School/scripts.pory"
	.string "Ugh, I missed a class so I have to\n"
	.string "catch up on Pokémon's attack and\l"
	.string "special attack…\p"
	.string "I'm almost done though! I don't even\n"
	.string "need these anymore!$"

ChiiTown_School_EventScript_ChildWiseGlasses_Text_1:
# 139 "data/maps/ChiiTown_School/scripts.pory"
	.string "These are my smart glasses. You\n"
	.string "looked like you needed them!$"

ChiiTown_School_EventScript_ChildLikeSensei_Text_0:
# 154 "data/maps/ChiiTown_School/scripts.pory"
	.string "I like our Sensei. She's pretty and\n"
	.string "she smells nice.$"

ChiiTown_School_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ChiiTown_School_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

ChiiTown_School_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	return


ChiiTown_School_EventScript_Teacher::
	gettimeofday
	switch VAR_0x8000
	case TIME_EARLY_MORNING, ChiiTown_School_EventScript_Teacher_2
	case TIME_MORNING, ChiiTown_School_EventScript_Teacher_3
	case TIME_EVENING, ChiiTown_School_EventScript_Teacher_4
	return

ChiiTown_School_EventScript_Teacher_2:
	goto ChiiTown_School_EventScript_PreparingDay
	return

ChiiTown_School_EventScript_Teacher_3:
	goto ChiiTown_School_EventScript_Teaching
	return

ChiiTown_School_EventScript_Teacher_4:
	goto ChiiTown_School_EventScript_EndingDay
	return


ChiiTown_School_EventScript_PreparingDay::
	lock
	faceplayer
	speakername ChiiTown_School_EventScript_PreparingDay_Text_0
	msgbox ChiiTown_School_EventScript_PreparingDay_Text_1
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return


ChiiTown_School_EventScript_Teaching::
	lock
	faceplayer
	speakername ChiiTown_School_EventScript_PreparingDay_Text_0
	msgbox ChiiTown_School_EventScript_Teaching_Text_0
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return


ChiiTown_School_EventScript_EndingDay::
	lock
	faceplayer
	speakername ChiiTown_School_EventScript_PreparingDay_Text_0
	msgbox ChiiTown_School_EventScript_EndingDay_Text_0
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return


ChiiTown_School_EventScript_BoardLegend::
	lock
	msgbox ChiiTown_School_EventScript_BoardLegend_Text_0
	closemessage
	release
	return


ChiiTown_School_EventScript_Board::
	lock
	msgbox ChiiTown_School_EventScript_Board_Text_0
	closemessage
	release
	return


ChiiTown_School_EventScript_ChildImBored::
	lock
	faceplayer
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
	msgbox ChiiTown_School_EventScript_ChildImBored_Text_1
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return


ChiiTown_School_EventScript_ChildAlreadyKnowLegend::
	lock
	faceplayer
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
	msgbox ChiiTown_School_EventScript_ChildAlreadyKnowLegend_Text_0
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return


ChiiTown_School_EventScript_ChildPokemonInsideVolcano::
	lock
	faceplayer
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
	msgbox ChiiTown_School_EventScript_ChildPokemonInsideVolcano_Text_0
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return


ChiiTown_School_EventScript_ChildTellsStory::
	lock
	faceplayer
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
	msgbox ChiiTown_School_EventScript_ChildTellsStory_Text_0
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return


ChiiTown_School_EventScript_IsThePokemonWakingUp::
	lock
	faceplayer
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
	msgbox ChiiTown_School_EventScript_IsThePokemonWakingUp_Text_0
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return


ChiiTown_School_EventScript_ChildWiseGlasses::
	lock
	faceplayer
	goto_if_unset FLAG_SMART_GLASSES, ChiiTown_School_EventScript_ChildWiseGlasses_2
ChiiTown_School_EventScript_ChildWiseGlasses_1:
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
	msgbox ChiiTown_School_EventScript_ChildWiseGlasses_Text_1
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return

ChiiTown_School_EventScript_ChildWiseGlasses_2:
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
	msgbox ChiiTown_School_EventScript_ChildWiseGlasses_Text_0
	closemessage
	giveitem ITEM_WISE_GLASSES
	setflag FLAG_SMART_GLASSES
	goto ChiiTown_School_EventScript_ChildWiseGlasses_1


ChiiTown_School_EventScript_ChildLikeSensei::
	lock
	faceplayer
	speakername ChiiTown_School_EventScript_ChildImBored_Text_0
	msgbox ChiiTown_School_EventScript_ChildLikeSensei_Text_0
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return


ChiiTown_School_EventScript_PreparingDay_Text_0:
	.string "Sensei$"

ChiiTown_School_EventScript_PreparingDay_Text_1:
	.string "Um… The school isn't open yet, I'm\n"
	.string "afraid. Come back later with your\l"
	.string "little brother or sister!$"

ChiiTown_School_EventScript_Teaching_Text_0:
	.string "Um… Aren't you a little old for\n"
	.string "this class?\p"
	.string "It's alright, you can stay!\p"
	.string "Today we're doing some creative\n"
	.string "writing about the Toku legends.$"

ChiiTown_School_EventScript_EndingDay_Text_0:
	.string "Oh! I'm afraid classes are done for\n"
	.string "the day. You'll have to come back\l"
	.string "tomorrow.$"

ChiiTown_School_EventScript_BoardLegend_Text_0:
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
	.string "A wide sheet of paper with lots of\n"
	.string "tiny squiggles on it.$"

ChiiTown_School_EventScript_ChildImBored_Text_0:
	.string "Child$"

ChiiTown_School_EventScript_ChildImBored_Text_1:
	.string "I'm bored! Why won't recess start\n"
	.string "already!$"

ChiiTown_School_EventScript_ChildAlreadyKnowLegend_Text_0:
	.string "I already knew all of this! My gramma\n"
	.string "told me about the legend a bajillion\l"
	.string "times!$"

ChiiTown_School_EventScript_ChildPokemonInsideVolcano_Text_0:
	.string "There's a Pokémon inside the\n"
	.string "volcano?! That's AWESOME!$"

ChiiTown_School_EventScript_ChildTellsStory_Text_0:
	.string "I know the story, I know the story!\p"
	.string "Once upon a time, the Volcano Pokémon\n"
	.string "woke up, and then there was fire\l"
	.string "everywhere, and then four Pokémon\l"
	.string "were fighting the Volcano one, and\l"
	.string "then the Volcano stopped spitting\l"
	.string "fire because the Pokémon went back\l"
	.string "to sleep!$"

ChiiTown_School_EventScript_IsThePokemonWakingUp_Text_0:
	.string "When the Volcano Pokémon went to\n"
	.string "bed, the Volcano stopped erupting!\p"
	.string "But the Volcano has been rumbling for\n"
	.string "days now…\p"
	.string "Does that mean the Pokémon's waking\n"
	.string "up again?$"

ChiiTown_School_EventScript_ChildWiseGlasses_Text_0:
	.string "Ugh, I missed a class so I have to\n"
	.string "catch up on Pokémon's attack and\l"
	.string "special attack…\p"
	.string "I'm almost done though! I don't even\n"
	.string "need these anymore!$"

ChiiTown_School_EventScript_ChildWiseGlasses_Text_1:
	.string "These are my smart glasses. You\n"
	.string "looked like you needed them!$"

ChiiTown_School_EventScript_ChildLikeSensei_Text_0:
	.string "I like our Sensei. She's pretty and\n"
	.string "she smells nice.$"

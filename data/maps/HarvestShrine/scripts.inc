HarvestShrine_MapScripts::
	.byte 0


HarvestShrine_EventScript_MonkBronzong::
	lock
	faceplayer
	speakername HarvestShrine_EventScript_MonkBronzong_Text_0
	msgbox HarvestShrine_EventScript_MonkBronzong_Text_1
	closemessage
	setseenmon SPECIES_BRONZONG
	setnamedmon SPECIES_BRONZONG
	setdescribedmon SPECIES_BRONZONG
	release
	return


HarvestShrine_EventScript_Kouga::
	trainerbattle_single TRAINER_KOUGA, HarvestShrine_EventScript_Kouga_Text_0, HarvestShrine_EventScript_Kouga_Text_1, HarvestShrine_EventScript_SetMonFlags
	speakername HarvestShrine_EventScript_Kouga_Text_2
	msgbox HarvestShrine_EventScript_Kouga_Text_3
	closemessage
	end


HarvestShrine_EventScript_SetMonFlags::
	setnamedmon SPECIES_BRONZONG
	return


HarvestShrine_EventScript_MonkRain::
	lock
	faceplayer
	speakername HarvestShrine_EventScript_MonkBronzong_Text_0
	checkitem ITEM_TM_RAIN_DANCE
	compare VAR_RESULT, 0
	goto_if_ne HarvestShrine_EventScript_MonkRain_2
	goto_if_set FLAG_TEMP_1, HarvestShrine_EventScript_MonkRain_3
	msgbox HarvestShrine_EventScript_MonkRain_Text_2
HarvestShrine_EventScript_MonkRain_1:
	release
	return

HarvestShrine_EventScript_MonkRain_2:
	msgbox HarvestShrine_EventScript_MonkRain_Text_0
	goto HarvestShrine_EventScript_MonkRain_1

HarvestShrine_EventScript_MonkRain_3:
	setnamedmon SPECIES_BRONZONG
	msgbox HarvestShrine_EventScript_MonkRain_Text_1
	giveitem ITEM_TM_RAIN_DANCE
	goto HarvestShrine_EventScript_MonkRain_1


HarvestShrine_EventScript_Bronzong::
	lock
	goto_if_set FLAG_TEMP_1, HarvestShrine_EventScript_Bronzong_2
	setseenmon SPECIES_BRONZONG
	delay 24
	fadeoutbgm 1
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 100
	setvar VAR_0x8007, 1
	special ShakeCamera
	playmoncry SPECIES_BRONZONG, CRY_MODE_GROWL_1
	waitmoncry
	playmoncry SPECIES_BRONZONG, CRY_MODE_GROWL_2
	delay 16
	playmoncry SPECIES_BRONZONG, CRY_MODE_GROWL_2
	waitmoncry
	delay 48
	setweather WEATHER_RAIN
	doweather
	delay 64
	applymovement OBJ_EVENT_ID_PLAYER, HarvestShrine_EventScript_Bronzong_Movement_0
	waitmovement 0
	delay 48
	msgbox HarvestShrine_EventScript_Bronzong_Text_1
	closemessage
	fadeinbgm 1
	setflag FLAG_TEMP_1
HarvestShrine_EventScript_Bronzong_1:
	release
	return

HarvestShrine_EventScript_Bronzong_2:
	msgbox HarvestShrine_EventScript_Bronzong_Text_0
	goto HarvestShrine_EventScript_Bronzong_1


HarvestShrine_EventScript_Bronzong_Movement_0:
	face_down
	step_end

HarvestShrine_EventScript_MonkBronzong_Text_0:
	.string "Monk$"

HarvestShrine_EventScript_MonkBronzong_Text_1:
	.string "The Bronzong you have before your\n"
	.string "eyes is a thousand years old.\p"
	.string "It has been bringing us rain and\n"
	.string "plentiful harvests for generations.\p"
	.string "Can you believe this magnificent\n"
	.string "statue is actually a living, breathing\l"
	.string "Pokémon?\p"
	.string "Actually, I'm not sure Bronzong\n"
	.string "breathe, but you get the idea.$"

HarvestShrine_EventScript_Kouga_Text_0:
	.string "Have you come here to honor the\n"
	.string "venerable Bronzong? Or are you here\l"
	.string "to stir trouble?$"

HarvestShrine_EventScript_Kouga_Text_1:
	.string "By a thousand gods!$"

HarvestShrine_EventScript_Kouga_Text_2:
	.string "Kouga$"

HarvestShrine_EventScript_Kouga_Text_3:
	.string "Fine, you may approach the ancient\n"
	.string "Bronzong. Please be respectful.$"

HarvestShrine_EventScript_MonkRain_Text_0:
	.string "I do enjoy the sounds of the rain…$"

HarvestShrine_EventScript_MonkRain_Text_1:
	.string "You prayed to the venerable Bronzong\n"
	.string "for rain, and He heeded your prayer!\p"
	.string "He doesn't listen to just anyone,\n"
	.string "you know?\l"
	.string "There's something about you, kid…\l"
	.string "Take this! I insist!$"

HarvestShrine_EventScript_MonkRain_Text_2:
	.string "Impressive, isn't He?$"

HarvestShrine_EventScript_Bronzong_Text_0:
	.string "… … …The statue is back to silence.$"

HarvestShrine_EventScript_Bronzong_Text_1:
	.string "… … …It started to rain.$"

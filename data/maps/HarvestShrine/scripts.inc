HarvestShrine_MapScripts::
	.byte 0


HarvestShrine_EventScript_MonkBronzong::
	lock
	faceplayer
	speakername HarvestShrine_EventScript_MonkBronzong_Text_0
	msgbox HarvestShrine_EventScript_MonkBronzong_Text_1
	closemessage
	release
	return


HarvestShrine_EventScript_Kouga::
	trainerbattle_single TRAINER_KOUGA, HarvestShrine_EventScript_Kouga_Text_0, HarvestShrine_EventScript_Kouga_Text_1
	speakername HarvestShrine_EventScript_Kouga_Text_2
	msgbox HarvestShrine_EventScript_Kouga_Text_3
	closemessage
	end


HarvestShrine_EventScript_MonkBronzong_Text_0:
	.string "Monk$"

HarvestShrine_EventScript_MonkBronzong_Text_1:
	.string "The Bronzong you have before your\n"
	.string "eyes is a thousand years old.\p"
	.string "It has been bringing us rain and\n"
	.string "plentiful harvests for\l"
	.string "generations.\p"
	.string "Can you believe this magnificent\n"
	.string "statue is actually a living,\l"
	.string "breathing Pokémon?\p"
	.string "Actually, I'm not sure Bronzong\n"
	.string "breathe, but you get the idea.$"

HarvestShrine_EventScript_Kouga_Text_0:
	.string "Have you come here to honor the\n"
	.string "venerable Bronzong? Or are you\l"
	.string "here to stir trouble?$"

HarvestShrine_EventScript_Kouga_Text_1:
	.string "By a thousand gods!$"

HarvestShrine_EventScript_Kouga_Text_2:
	.string "Kouga$"

HarvestShrine_EventScript_Kouga_Text_3:
	.string "Fine, you may approach the ancient\n"
	.string "Bronzong. Please be respectful.$"

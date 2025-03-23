Silveridge_House1_MapScripts::
	.byte 0


Silveridge_House1_EventScript_Woman::
	lock
	faceplayer
	speakername Silveridge_House1_EventScript_Woman_Text_0
	msgbox Silveridge_House1_EventScript_Woman_Text_1
	closemessage
	release
	return


Silveridge_House1_EventScript_FirebringerFangirl::
	lock
	faceplayer
	speakername Silveridge_House1_EventScript_FirebringerFangirl_Text_0
	msgbox Silveridge_House1_EventScript_FirebringerFangirl_Text_1
	closemessage
	setnamedmon SPECIES_SLUGMA
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return


Silveridge_House1_EventScript_Sandslash::
	lock
	faceplayer
	setseenmon SPECIES_SANDSLASH
	playmoncry SPECIES_SANDSLASH, CRY_MODE_NORMAL
	speakername Silveridge_House1_EventScript_Sandslash_Text_0
	msgbox Silveridge_House1_EventScript_Sandslash_Text_1
	waitmoncry
	closemessage
	release
	return


Silveridge_House1_EventScript_Man::
	lock
	faceplayer
	speakername Silveridge_House1_EventScript_Man_Text_0
	goto_if_set FLAG_OBTAINED_EVERSTONE, Silveridge_House1_EventScript_Man_2
	msgbox Silveridge_House1_EventScript_Man_Text_2
	closemessage
	giveitem ITEM_EVERSTONE
	setflag FLAG_OBTAINED_EVERSTONE
	speakername Silveridge_House1_EventScript_Man_Text_0
	msgbox Silveridge_House1_EventScript_Man_Text_3
	closemessage
	setnamedmon SPECIES_SANDSLASH
Silveridge_House1_EventScript_Man_1:
	release
	return

Silveridge_House1_EventScript_Man_2:
	msgbox Silveridge_House1_EventScript_Man_Text_1
	closemessage
	goto Silveridge_House1_EventScript_Man_1


Silveridge_House1_EventScript_Woman_Text_0:
	.string "Woman$"

Silveridge_House1_EventScript_Woman_Text_1:
	.string "Oh, you came all the way from Kura\n"
	.string "Village? You have good legs!$"

Silveridge_House1_EventScript_FirebringerFangirl_Text_0:
	.string "Girl$"

Silveridge_House1_EventScript_FirebringerFangirl_Text_1:
	.string "This place gets pretty cold,\n"
	.string "especially when the winds blow\l"
	.string "strong into the valley.\p"
	.string "I don't know what we would do\n"
	.string "without those brave Firebringers.\p"
	.string "They bring us live Slugma, carrying\n"
	.string "them on their back all the way\l"
	.string "down Mt Kazan! I could never!\p"
	.string "Sigh… I hope a handsome Firebringer\n"
	.string "notices me one day…$"

Silveridge_House1_EventScript_Sandslash_Text_0:
	.string "Sandslash$"

Silveridge_House1_EventScript_Sandslash_Text_1:
	.string "Sahaaah!$"

Silveridge_House1_EventScript_Man_Text_0:
	.string "Miner$"

Silveridge_House1_EventScript_Man_Text_1:
	.string "You think some Pokémon prefer to\n"
	.string "remain small forever?$"

Silveridge_House1_EventScript_Man_Text_2:
	.string "My job is to mine ore in Silver\n"
	.string "Tunnel, all day long.\p"
	.string "I love it! I wouldn't trade it for\n"
	.string "the world. I'm fine with being a\l"
	.string "simple miner forever.\p"
	.string "Speaking of… I often find\n"
	.string "interesting rocks in there. Look\l"
	.string "at this!$"

Silveridge_House1_EventScript_Man_Text_3:
	.string "Apparently as long as a Pokémon\n"
	.string "holds on to this stone, it'll stop\l"
	.string "growing.\p"
	.string "My helper Sandslash is already\n"
	.string "fully grown, so I don't need it.$"

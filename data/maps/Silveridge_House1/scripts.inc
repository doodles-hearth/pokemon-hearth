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
	.string "especially when the winds blow strong\l"
	.string "into the valley.\p"
	.string "I don't know what we would do without\n"
	.string "those brave Firebringers.\p"
	.string "They carry live Slugma on their back\n"
	.string "all the way down Mt Kazan! I could\l"
	.string "never!\p"
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
	.string "My job is to mine ore in Silver Tunnel,\n"
	.string "all day long.\p"
	.string "I love it! I wouldn't trade it for the\n"
	.string "world. I'm fine with being a simple\l"
	.string "miner forever.\p"
	.string "Speaking of… I often find interesting\n"
	.string "rocks in there. Look at this!$"

Silveridge_House1_EventScript_Man_Text_3:
	.string "Apparently as long as a Pokémon holds\n"
	.string "on to this stone, it'll stop growing.\p"
	.string "My helper Sandslash is already fully\n"
	.string "grown, so I don't need it.$"

Soulkeep_House1_MapScripts::
	.byte 0


Soulkeep_House1_EventScript_Girl::
	lock
	faceplayer
	speakername Soulkeep_House1_EventScript_Girl_Text_0
	msgbox Soulkeep_House1_EventScript_Girl_Text_1
	closemessage
	release
	return


Soulkeep_House1_EventScript_EnGarde::
	lock
	faceplayer
	speakername Soulkeep_House1_EventScript_EnGarde_Text_0
	msgbox Soulkeep_House1_EventScript_EnGarde_Text_1
	closemessage
	release
	return


Soulkeep_House1_EventScript_Farmer::
	lock
	faceplayer
	speakername Soulkeep_House1_EventScript_EnGarde_Text_0
	msgbox Soulkeep_House1_EventScript_Farmer_Text_0
	closemessage
	release
	return


Soulkeep_House1_EventScript_LittleGirl::
	lock
	faceplayer
	speakername Soulkeep_House1_EventScript_LittleGirl_Text_0
	setnamedmon SPECIES_FENNEKIN
	msgbox Soulkeep_House1_EventScript_LittleGirl_Text_1
	closemessage
	release
	return


Soulkeep_House1_EventScript_Fennekin::
	lock
	faceplayer
	setseenmon SPECIES_FENNEKIN
	setspeakertomonname SPECIES_FENNEKIN
	msgbox Soulkeep_House1_EventScript_Fennekin_Text_0
	playmoncry SPECIES_FENNEKIN, CRY_MODE_NORMAL
	waitmoncry
	closemessage
	release
	end


Soulkeep_House1_EventScript_Girl_Text_0:
	.string "Girl$"

Soulkeep_House1_EventScript_Girl_Text_1:
	.string "Were… Were you outside just now?\p"
	.string "Oh, I'm too scared to leave…\n"
	.string "Those ghost Pokémon do bad things\l"
	.string "to people…$"

Soulkeep_House1_EventScript_EnGarde_Text_0:
	.string "Farmer$"

Soulkeep_House1_EventScript_EnGarde_Text_1:
	.string "En garde, puny ghosts!!\n"
	.string "… … … …\p"
	.string "What? I'm practicing!$"

Soulkeep_House1_EventScript_Farmer_Text_0:
	.string "Our crops are being neglected…\p"
	.string "None dare till the field and turn\n"
	.string "their back on the ghosts!$"

Soulkeep_House1_EventScript_LittleGirl_Text_0:
	.string "Little Girl$"

Soulkeep_House1_EventScript_LittleGirl_Text_1:
	.string "Nothing bad can happen to us so\n"
	.string "long as Fennekin keeps us safe!\p"
	.string "I feed him lots of twigs for him to\n"
	.string "keep us warm!$"

Soulkeep_House1_EventScript_Fennekin_Text_0:
	.string "Growr…$"

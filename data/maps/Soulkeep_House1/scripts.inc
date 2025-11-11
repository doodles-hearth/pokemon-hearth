Soulkeep_House1_MapScripts::
	.byte 0


Soulkeep_House1_EventScript_Girl::
	lock
	faceplayer
	setspeaker SP_NAME_GIRL
	msgbox Soulkeep_House1_EventScript_Girl_Text_0
	closemessage
	release
	return


Soulkeep_House1_EventScript_EnGarde::
	lock
	faceplayer
	setspeaker SP_NAME_FARMER
	msgbox Soulkeep_House1_EventScript_EnGarde_Text_0
	closemessage
	release
	return


Soulkeep_House1_EventScript_Farmer::
	lock
	faceplayer
	setspeaker SP_NAME_FARMER
	msgbox Soulkeep_House1_EventScript_Farmer_Text_0
	closemessage
	release
	return


Soulkeep_House1_EventScript_LittleGirl::
	lock
	faceplayer
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox Soulkeep_House1_EventScript_LittleGirl_Text_0
	closemessage
	setnamedmon SPECIES_FENNEKIN
	setdescribedmon SPECIES_FENNEKIN
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
	.string "Were… Were you outside just now?\p"
	.string "Oh, I'm too scared to leave…\n"
	.string "Those ghost Pokémon do bad things to\l"
	.string "people…$"

Soulkeep_House1_EventScript_EnGarde_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_FARMER EMOTE_NORMAL}En garde, puny ghosts!!\n"
	.string "… … … …\p"
	.string "What? I'm practicing!$"

Soulkeep_House1_EventScript_Farmer_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_FARMER EMOTE_NORMAL}Our crops are being neglected…\p"
	.string "None dare till the field and turn their\n"
	.string "back on the ghosts!$"

Soulkeep_House1_EventScript_LittleGirl_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_LITTLE_GIRL EMOTE_NORMAL}Nothing bad can happen to us so long\n"
	.string "as Fennekin keeps us safe!\p"
	.string "I feed him lots of twigs for him to\n"
	.string "keep us warm!$"

Soulkeep_House1_EventScript_Fennekin_Text_0:
	.string "Growr…$"

SoulkeepGraveyard_MapScripts::
	.byte 0


SoulkeepGraveyard_EventScript_Guard::
	lock
	faceplayer
	setspeaker SP_NAME_MAN
	msgbox SoulkeepGraveyard_EventScript_Guard_Text_0
	closemessage
	release
	end


SoulkeepGraveyard_EventScript_Banette::
	lock
	faceplayer
	setspeakertomonname SPECIES_BANETTE
	playmoncry SPECIES_BANETTE, CRY_MODE_NORMAL
	msgbox SoulkeepGraveyard_EventScript_Banette_Text_0
	waitmoncry
	closemessage
	release
	end


SoulkeepGraveyard_EventScript_Guard_Text_0:
	.string "Oooh boy, you scared me!\p"
	.string "I'm s-standing guard f-for today…$"

SoulkeepGraveyard_EventScript_Banette_Text_0:
	.string "…$"

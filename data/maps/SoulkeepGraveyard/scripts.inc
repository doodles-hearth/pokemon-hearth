SoulkeepGraveyard_MapScripts::
	.byte 0


SoulkeepGraveyard_EventScript_Guard::
	lock
	faceplayer
	speakername SoulkeepGraveyard_EventScript_Guard_Text_0
	msgbox SoulkeepGraveyard_EventScript_Guard_Text_1
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
	.string "Man$"

SoulkeepGraveyard_EventScript_Guard_Text_1:
	.string "Oooh boy, you scared me!\p"
	.string "I'm s-standing guard f-for today…$"

SoulkeepGraveyard_EventScript_Banette_Text_0:
	.string "…$"

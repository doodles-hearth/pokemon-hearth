Silveridge_House3_MapScripts::
	.byte 0


Silveridge_House3_EventScript_DreamingPokemon::
	lock
	faceplayer
	setspeaker SP_NAME_GIRL
	msgbox Silveridge_House3_EventScript_DreamingPokemon_Text_0
	closemessage
	release
	return


Silveridge_House3_EventScript_SleepingMon::
	lock
	waitse
	playse SE_M_SNORE
	setseenmon SPECIES_SEEDOT
	setspeakertomonname SPECIES_SEEDOT
	applymovement VAR_LAST_TALKED, Silveridge_House3_EventScript_SleepingMon_Movement_0
	msgbox Silveridge_House3_EventScript_SleepingMon_Text_0
	closemessage
	release
	return


Silveridge_House3_EventScript_SleepingMon_Movement_0:
	emote_sleep
	step_end

Silveridge_House3_EventScript_DreamingPokemon_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_MOUNTAIN_GIRL_1 EMOTE_NORMAL}My Pokémon fell asleep during a battle,\nand it started dreaming!\l"
	.string "It was so cute!$"

Silveridge_House3_EventScript_SleepingMon_Text_0:
	.string "Zzzzz…$"

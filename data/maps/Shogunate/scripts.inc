Shogunate_MapScripts::
	.byte 0


Shogunate_EventScript_Shuppet::
	lock
	setseenmon SPECIES_SHUPPET
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Shogunate_EventScript_Shuppet_Movement_0
	waitmovement 0
	waitse
	faceplayer
	playmoncry SPECIES_SHUPPET, CRY_MODE_NORMAL
	waitmoncry
	fadescreen FADE_TO_BLACK
	setflag FLAG_TEMP_1
	fadescreen FADE_FROM_BLACK
	release
	return


Shogunate_EventScript_Shuppet_Movement_0:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

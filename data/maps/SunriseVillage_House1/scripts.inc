SunriseVillage_House1_MapScripts::
	.byte 0


SunriseVillage_House1_EventScript_Ralts::
	lock
	setseenmon SPECIES_RALTS
	setspeakertomonname SPECIES_RALTS
	playmoncry SPECIES_RALTS, CRY_MODE_NORMAL
	applymovement VAR_LAST_TALKED, SunriseVillage_House1_EventScript_Ralts_Movement_0
	msgbox SunriseVillage_House1_EventScript_Ralts_Text_0
	waitmoncry
	closemessage
	release
	return


SunriseVillage_House1_EventScript_OldWoman::
	setnamedmon SPECIES_RALTS
	setspeaker SP_NAME_NEIGHBOR
	msgbox SunriseVillage_House1_EventScript_OldWoman_Text_0, MSGBOX_NPC
	return


SunriseVillage_House1_EventScript_OldMan::
	setspeaker SP_NAME_NEIGHBOR
	msgbox SunriseVillage_House1_EventScript_OldMan_Text_0, MSGBOX_NPC
	return


SunriseVillage_House1_EventScript_LittleGirl::
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox SunriseVillage_House1_EventScript_LittleGirl_Text_0, MSGBOX_NPC
	return


SunriseVillage_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	setseenmon SPECIES_ZIGZAGOON
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	setspeaker SunriseVillage_House1_EventScript_Zigzagoon_Text_0
	msgbox SunriseVillage_House1_EventScript_Zigzagoon_Text_1
	waitmoncry
	release
	end


SunriseVillage_House1_EventScript_Ralts_Movement_0:
	emote_pensive
	step_end

SunriseVillage_House1_EventScript_Ralts_Text_0:
	.string "…$"

SunriseVillage_House1_EventScript_OldWoman_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_OLD_WOMAN EMOTE_NORMAL}Ralts here is quite the silent type.\n"
	.string "I'm fine with that.$"

SunriseVillage_House1_EventScript_OldMan_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_OLD_MAN EMOTE_NORMAL}My granddaughter's Pokémon has\n"
	.string "already scratched all the furniture…$"

SunriseVillage_House1_EventScript_LittleGirl_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SUNRISE_LITTLE_GIRL EMOTE_NORMAL}Ahhh I'm so happy!! Look how cute my\n"
	.string "Ziggy is!!!$"

SunriseVillage_House1_EventScript_Zigzagoon_Text_0:
	.string "Ziggy$"

SunriseVillage_House1_EventScript_Zigzagoon_Text_1:
	.string "Rawr!$"

SunriseVillage_House1_MapScripts::
	.byte 0


SunriseVillage_House1_EventScript_Ralts::
	setseenmon SPECIES_RALTS
	setspeakertomonname SPECIES_RALTS
	msgbox SunriseVillage_House1_EventScript_Ralts_Text_0, MSGBOX_NPC
	return


SunriseVillage_House1_EventScript_OldWoman::
	setnamedmon SPECIES_RALTS
	speakername SunriseVillage_House1_EventScript_OldWoman_Text_0
	msgbox SunriseVillage_House1_EventScript_OldWoman_Text_1, MSGBOX_NPC
	return


SunriseVillage_House1_EventScript_OldMan::
	speakername SunriseVillage_House1_EventScript_OldWoman_Text_0
	msgbox SunriseVillage_House1_EventScript_OldMan_Text_0, MSGBOX_NPC
	return


SunriseVillage_House1_EventScript_LittleGirl::
	speakername SunriseVillage_House1_EventScript_LittleGirl_Text_0
	msgbox SunriseVillage_House1_EventScript_LittleGirl_Text_1, MSGBOX_NPC
	return


SunriseVillage_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	setseenmon SPECIES_ZIGZAGOON
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	speakername SunriseVillage_House1_EventScript_Zigzagoon_Text_0
	msgbox SunriseVillage_House1_EventScript_Zigzagoon_Text_1
	waitmoncry
	release
	end


SunriseVillage_House1_EventScript_Ralts_Text_0:
	.string "…$"

SunriseVillage_House1_EventScript_OldWoman_Text_0:
	.string "Neighbour$"

SunriseVillage_House1_EventScript_OldWoman_Text_1:
	.string "Ralts here is quite the silent type.\n"
	.string "I'm fine with that.$"

SunriseVillage_House1_EventScript_OldMan_Text_0:
	.string "My granddaughter's Pokémon has\n"
	.string "already scratched all the furniture…$"

SunriseVillage_House1_EventScript_LittleGirl_Text_0:
	.string "Little girl$"

SunriseVillage_House1_EventScript_LittleGirl_Text_1:
	.string "Ahhh I'm so happy!! Look how cute my\n"
	.string "Ziggy is!!!$"

SunriseVillage_House1_EventScript_Zigzagoon_Text_0:
	.string "Ziggy$"

SunriseVillage_House1_EventScript_Zigzagoon_Text_1:
	.string "Rawr!$"

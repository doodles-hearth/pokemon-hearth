SunriseVillage_EldersHouse_PrivateQuarters_MapScripts::
	.byte 0


SunriseVillage_EldersHouse_PrivateQuarters_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	speakername SunriseVillage_EldersHouse_PrivateQuarters_EventScript_Meowth_Text_0
	msgbox SunriseVillage_EldersHouse_PrivateQuarters_EventScript_Meowth_Text_1
	waitmoncry
	release
	end


SunriseVillage_EldersHouse_PrivateQuarters_EventScript_Meowth_Text_0:
	.string "Meowth$"

SunriseVillage_EldersHouse_PrivateQuarters_EventScript_Meowth_Text_1:
	.string "Fss!$"

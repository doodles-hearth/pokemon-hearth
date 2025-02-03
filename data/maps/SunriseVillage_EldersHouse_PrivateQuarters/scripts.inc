SunriseVillage_EldersHouse_PrivateQuarters_MapScripts::
	.byte 0


SunriseVillage_EldersHouse_PrivateQuarters_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GALVANTULA, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_GALVANTULA
	msgbox SunriseVillage_EldersHouse_PrivateQuarters_EventScript_Meowth_Text_0
	waitmoncry
	release
	end


SunriseVillage_EldersHouse_PrivateQuarters_EventScript_Meowth_Text_0:
	.string "FSSS!$"

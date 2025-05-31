Soulkeep_Refuge_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Soulkeep_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Soulkeep_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_SOULKEEP
	return


Soulkeep_Refuge_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse_CutTheBullshit
	waitmessage
	waitbuttonpress
	release
	end


Soulkeep_Refuge_EventScript_Man::
	lock
	faceplayer
	speakername Soulkeep_Refuge_EventScript_Man_Text_0
	msgbox Soulkeep_Refuge_EventScript_Man_Text_1
	closemessage
	release
	return


Soulkeep_Refuge_EventScript_NewDojo::
	lock
	faceplayer
	speakername Soulkeep_Refuge_EventScript_Man_Text_0
	msgbox Soulkeep_Refuge_EventScript_NewDojo_Text_0
	closemessage
	release
	return


Soulkeep_Refuge_EventScript_Man_Text_0:
	.string "Farmer$"

Soulkeep_Refuge_EventScript_Man_Text_1:
	.string "We sure don't see a lot of trav'lers\n"
	.string "'round these parts…\p"
	.string "You here for the Dojo challenge?\n"
	.string "Dojo's closed, unfortunately.$"

Soulkeep_Refuge_EventScript_NewDojo_Text_0:
	.string "Some of the town's farmers got\n"
	.string "together with Guang and said they\l"
	.string "were going to open the old Dojo.\p"
	.string "Guang says he's tired of us “living in\n"
	.string "the shadows”, whatever that means.$"

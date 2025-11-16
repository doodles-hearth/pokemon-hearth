Soulkeep_Refuge_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Soulkeep_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Soulkeep_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_SOULKEEP
	return


Soulkeep_Refuge_EventScript_NurseSleep::
	createfieldmugshot MUGSHOT_UUME_NURSE
	setvar VAR_0x8009, MUGSHOT_UUME_NURSE
	call Common_EventScript_PkmnCenterNurse_Sleep
	waitmessage
	waitbuttonpress
	release
	end


Soulkeep_Refuge_EventScript_Nurse::
	createfieldmugshot MUGSHOT_UUME_NURSE
	setvar VAR_0x8009, MUGSHOT_UUME_NURSE
	setvar VAR_0x800B, LOCALID_NURSE_SOULKEEP
	setvar VAR_0x800A, LOCALID_CHANSEY_SOULKEEP
	call Common_EventScript_PkmnCenterNurse_CutTheBullshit
	waitmessage
	waitbuttonpress
	release
	end


Soulkeep_Refuge_EventScript_Pasture::
	createfieldmugshot MUGSHOT_UUME_MAN_2
	setvar VAR_0x8009, MUGSHOT_UUME_MAN_2
	call Common_EventScript_PcGuy
	release
	end


Soulkeep_Refuge_EventScript_Man::
	lock
	faceplayer
	setspeaker SP_NAME_FARMER
	msgbox Soulkeep_Refuge_EventScript_Man_Text_0
	closemessage
	release
	return


Soulkeep_Refuge_EventScript_NewDojo::
	lock
	faceplayer
	setspeaker SP_NAME_FARMER
	msgbox Soulkeep_Refuge_EventScript_NewDojo_Text_0
	closemessage
	release
	return


Soulkeep_Refuge_EventScript_Man_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_FARMER EMOTE_NORMAL}We sure don't see a lot of trav'lers\n"
	.string "'round these parts…\p"
	.string "You here for the Dojo challenge?\n"
	.string "Dojo's closed, unfortunately.$"

Soulkeep_Refuge_EventScript_NewDojo_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_FARMER EMOTE_NORMAL}Some of the town's farmers got\n"
	.string "together with Guang and said they\l"
	.string "were going to reopen the old Dojo.\p"
	.string "Guang says he's tired o “living in the\n"
	.string "shadows”, whatever that means.$"

SabersideTown_Refuge_MapScripts::
	.byte 0


SabersideTown_Refuge_EventScript_NurseSleep::
	createfieldmugshot MUGSHOT_SEASIDE_NURSE
	setvar VAR_0x8009, MUGSHOT_SEASIDE_NURSE
	call Common_EventScript_PkmnCenterNurse_Sleep
	waitmessage
	waitbuttonpress
	release
	end


SabersideTown_Refuge_EventScript_Nurse::
	createfieldmugshot MUGSHOT_SEASIDE_NURSE
	setvar VAR_0x800B, LOCALID_NURSE_SILVERIDGE
	setvar VAR_0x800A, LOCALID_CHANSEY_SILVERIDGE
	setvar VAR_0x8009, MUGSHOT_SEASIDE_NURSE
	call Common_EventScript_PkmnCenterNurse_CutTheBullshit
	waitmessage
	waitbuttonpress
	removefieldmugshot
	release
	end


SabersideTown_Refuge_EventScript_Pasture::
	createfieldmugshot MUGSHOT_SEASIDE_MAN_2
	setvar VAR_0x8009, MUGSHOT_SEASIDE_MAN_2
	call Common_EventScript_PcGuy
	release
	end


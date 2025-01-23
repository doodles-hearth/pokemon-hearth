MaguroHarbor_Refuge_MapScripts::
# 2 "data/maps/MaguroHarbor_Refuge/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MaguroHarbor_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

MaguroHarbor_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/MaguroHarbor_Refuge/scripts.pory"
	setrespawn HEAL_LOCATION_MAGURO_HARBOR
	return


MaguroHarbor_Refuge_EventScript_Nurse::
# 8 "data/maps/MaguroHarbor_Refuge/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 9 "data/maps/MaguroHarbor_Refuge/scripts.pory"
	call Common_EventScript_PkmnCenterNurse_CutTheBullshit
# 10 "data/maps/MaguroHarbor_Refuge/scripts.pory"
	waitmessage
# 11 "data/maps/MaguroHarbor_Refuge/scripts.pory"
	waitbuttonpress
# 12 "data/maps/MaguroHarbor_Refuge/scripts.pory"
	release
	end


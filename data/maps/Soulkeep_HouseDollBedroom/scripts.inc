Soulkeep_HouseDollBedroom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Soulkeep_HouseDollBedroom_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Soulkeep_HouseDollBedroom_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	random 3
	compare VAR_RESULT, 0
	goto_if_eq Soulkeep_HouseDollBedroom_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

Soulkeep_HouseDollBedroom_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setobjectxyperm 2, 5, 4
	return


Soulkeep_HouseDollBedroom_EventScript_Girl::
	lock
	faceplayer
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox Soulkeep_HouseDollBedroom_EventScript_Girl_Text_0
	closemessage
	release
	return


Soulkeep_HouseDollBedroom_EventScript_Doll::
	lock
	msgbox Soulkeep_HouseDollBedroom_EventScript_Doll_Text_0
	closemessage
	release
	return


Soulkeep_HouseDollBedroom_EventScript_Girl_Text_0:
	.string "My doll moves when I sleep!$"

Soulkeep_HouseDollBedroom_EventScript_Doll_Text_0:
	.string "A rather uncanny doll.\p"
	.string "…The way it seems to be looking at you\n"
	.string "creeps you out.$"

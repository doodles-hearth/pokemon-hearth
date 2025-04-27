Kura_Beachbound_Gate_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Kura_Beachbound_Gate_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Kura_Beachbound_Gate_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_DECAY_BEACHBOUND_ROUTE, 0
	goto_if_gt Kura_Beachbound_Gate_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setdynamicwarp MAP_BEACHBOUND_ROUTE, 1
	return

Kura_Beachbound_Gate_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setdynamicwarp MAP_BEACHBOUND_ROUTE_DECAY, 1
	return


Kura_Beachbound_Gate_EventScript_Guard::
	lock
	speakername Kura_Beachbound_Gate_EventScript_Guard_Text_0
	msgbox Kura_Beachbound_Gate_EventScript_Guard_Text_1
	release
	return


Kura_Beachbound_Gate_EventScript_Guard_Text_0:
	.string "Samurai$"

Kura_Beachbound_Gate_EventScript_Guard_Text_1:
	.string "Zzzzzz…$"

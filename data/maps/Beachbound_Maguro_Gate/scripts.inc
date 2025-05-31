Beachbound_Maguro_Gate_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Beachbound_Maguro_Gate_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Beachbound_Maguro_Gate_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_DECAY_BEACHBOUND_ROUTE, 0
	goto_if_gt Beachbound_Maguro_Gate_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setdynamicwarp MAP_BEACHBOUND_ROUTE, 0
	return

Beachbound_Maguro_Gate_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setdynamicwarp MAP_BEACHBOUND_ROUTE_DECAY, 0
	return


Beachbound_Maguro_Gate_EventScript_Guard::
	lock
	speakername Beachbound_Maguro_Gate_EventScript_Guard_Text_0
	compare VAR_DECAY_BEACHBOUND_ROUTE, 1
	goto_if_eq Beachbound_Maguro_Gate_EventScript_Guard_2
	msgbox Beachbound_Maguro_Gate_EventScript_Guard_Text_2
Beachbound_Maguro_Gate_EventScript_Guard_1:
	closemessage
	release
	return

Beachbound_Maguro_Gate_EventScript_Guard_2:
	msgbox Beachbound_Maguro_Gate_EventScript_Guard_Text_1
	goto Beachbound_Maguro_Gate_EventScript_Guard_1


Beachbound_Maguro_Gate_EventScript_Guard_Text_0:
	.string "Samurai$"

Beachbound_Maguro_Gate_EventScript_Guard_Text_1:
	.string "Are you going to Beachbound Route?\n"
	.string "Uh, be careful, kid!$"

Beachbound_Maguro_Gate_EventScript_Guard_Text_2:
	.string "Ugh, I hate guard duty…\n"
	.string "We're not even allowed a book…$"

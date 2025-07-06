SakuTown_House2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SakuTown_House2_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SakuTown_House2_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 0
	goto_if_eq SakuTown_House2_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 4
	goto_if_eq SakuTown_House2_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	setflag FLAG_SAKU_KURA_HIDE_ESPEON_MASTERS_HOME
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( EEVEE )
	return

SakuTown_House2_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	clearflag FLAG_SAKU_KURA_HIDE_ESPEON_MASTERS_HOME
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( EEVEE )
	return

SakuTown_House2_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( ESPEON )
	clearflag FLAG_SAKU_KURA_HIDE_ESPEON_MASTERS_HOME
	return


SakuTown_House2_EventScript_EspeonsMaster::
	lock
	faceplayer
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 0
	goto_if_eq SakuTown_House2_EventScript_EspeonsMaster_2
SakuTown_House2_EventScript_EspeonsMaster_1:
	release
	return

SakuTown_House2_EventScript_EspeonsMaster_2:
	speakername SakuTown_House2_EventScript_EspeonsMaster_Text_0
	msgbox SakuTown_House2_EventScript_EspeonsMaster_Text_1
	closemessage
	goto SakuTown_House2_EventScript_EspeonsMaster_1


SakuTown_House2_EventScript_Sister::
	lock
	faceplayer
	speakername SakuTown_House2_EventScript_Sister_Text_0
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 0
	goto_if_eq SakuTown_House2_EventScript_Sister_2
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 4
	goto_if_eq SakuTown_House2_EventScript_Sister_3
	msgbox SakuTown_House2_EventScript_Sister_Text_3
SakuTown_House2_EventScript_Sister_1:
	closemessage
	release
	return

SakuTown_House2_EventScript_Sister_2:
	msgbox SakuTown_House2_EventScript_Sister_Text_1
	goto SakuTown_House2_EventScript_Sister_1

SakuTown_House2_EventScript_Sister_3:
	msgbox SakuTown_House2_EventScript_Sister_Text_2
	goto SakuTown_House2_EventScript_Sister_1


SakuTown_House2_EventScript_EeveeEspeon::
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 0
	goto_if_eq SakuTown_House2_EventScript_EeveeEspeon_1
	return

SakuTown_House2_EventScript_EeveeEspeon_1:
	setseenmon SPECIES_EEVEE
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_EEVEE
	msgbox SakuTown_House2_EventScript_EeveeEspeon_Text_0
	return


SakuTown_House2_EventScript_EspeonsMaster_Text_0:
	.string "Boy$"

SakuTown_House2_EventScript_EspeonsMaster_Text_1:
	.string "Hey there! Hope you've been having a\n"
	.string "nice day so far in Saku Village.\p"
	.string "It really has a vibe that perks you\n"
	.string "right up!$"

SakuTown_House2_EventScript_Sister_Text_0:
	.string "Girl$"

SakuTown_House2_EventScript_Sister_Text_1:
	.string "It's been lonely since our parents\n"
	.string "have\l"
	.string "passed.\p"
	.string "We're adults now though, so at least\n"
	.string "we\l"
	.string "can support ourselves.\p"
	.string "Even then, my brother didn't take it\n"
	.string "lightly.\p"
	.string "It was like fate, then, when an Eevee\n"
	.string "came up to him and became his partner.$"

SakuTown_House2_EventScript_Sister_Text_2:
	.string "Thank you for your kindness! It's\n"
	.string "nice to see my brother smiling again.\p"
	.string "I wish I could thank whoever took\n"
	.string "such good care of Eevee, too!$"

SakuTown_House2_EventScript_Sister_Text_3:
	.string "My brother's been feeling really down\n"
	.string "lately.\p"
	.string "His precious Pokémon disappeared\n"
	.string "during the big storm we had a while\l"
	.string "ago.$"

SakuTown_House2_EventScript_EeveeEspeon_Text_0:
	.string "Kyaaa!$"

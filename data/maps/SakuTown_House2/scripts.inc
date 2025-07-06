SakuTown_House2_MapScripts::
# 6 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SakuTown_House2_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SakuTown_House2_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 7 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 0
	goto_if_eq SakuTown_House2_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 10 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 4
	goto_if_eq SakuTown_House2_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 14 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	setflag FLAG_SAKU_KURA_HIDE_ESPEON_MASTERS_HOME
# 15 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( EEVEE )
	return

SakuTown_House2_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 8 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	clearflag FLAG_SAKU_KURA_HIDE_ESPEON_MASTERS_HOME
# 9 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( EEVEE )
	return

SakuTown_House2_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 11 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( ESPEON )
# 12 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	clearflag FLAG_SAKU_KURA_HIDE_ESPEON_MASTERS_HOME
	return


SakuTown_House2_EventScript_EspeonsMaster::
# 21 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	lock
# 22 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	faceplayer
# 25 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 0
	goto_if_eq SakuTown_House2_EventScript_EspeonsMaster_2
SakuTown_House2_EventScript_EspeonsMaster_1:
# 33 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	release
	return

SakuTown_House2_EventScript_EspeonsMaster_2:
# 26 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	setnamedmon SPECIES_EEVEE
# 27 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	speakername SakuTown_House2_EventScript_EspeonsMaster_Text_0
# 28 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	msgbox SakuTown_House2_EventScript_EspeonsMaster_Text_1
# 31 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	closemessage
	goto SakuTown_House2_EventScript_EspeonsMaster_1


SakuTown_House2_EventScript_Sister::
# 38 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	lock
# 39 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	faceplayer
# 40 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	speakername SakuTown_House2_EventScript_Sister_Text_0
# 41 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 0
	goto_if_eq SakuTown_House2_EventScript_Sister_2
# 48 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	compare VAR_SAKU_KURA_QUEST_ESPEON_STATE, 4
	goto_if_eq SakuTown_House2_EventScript_Sister_3
# 54 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	msgbox SakuTown_House2_EventScript_Sister_Text_3
SakuTown_House2_EventScript_Sister_1:
# 59 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	closemessage
# 60 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	release
	return

SakuTown_House2_EventScript_Sister_2:
# 42 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	msgbox SakuTown_House2_EventScript_Sister_Text_1
	goto SakuTown_House2_EventScript_Sister_1

SakuTown_House2_EventScript_Sister_3:
# 49 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	msgbox SakuTown_House2_EventScript_Sister_Text_2
	goto SakuTown_House2_EventScript_Sister_1


SakuTown_House2_EventScript_EeveeEspeon::
	return


SakuTown_House2_EventScript_EspeonsMaster_Text_0:
# 27 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	.string "Boy$"

SakuTown_House2_EventScript_EspeonsMaster_Text_1:
# 29 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	.string "Hey there! Hope you've been having a\n"
	.string "nice day so far in Saku Village.\p"
	.string "It really has the vibe that perks you\n"
	.string "right up!$"

SakuTown_House2_EventScript_Sister_Text_0:
# 40 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	.string "Girl$"

SakuTown_House2_EventScript_Sister_Text_1:
# 43 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	.string "It's been lonely since our parents have\n"
	.string "passed.\p"
	.string "We're adults now though, so at least we\n"
	.string "can support ourselves.\p"
	.string "Even then, my brother didn't take it\n"
	.string "lightly.\p"
	.string "It was almost fate, then, when an Eevee\n"
	.string "came up to him and became his partner.$"

SakuTown_House2_EventScript_Sister_Text_2:
# 50 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	.string "Thank you for your kindness! It's nice\n"
	.string "to see my brother smiling again.\p"
	.string "I wish I could thank whoever took such\n"
	.string "good care of Eevee, too!$"

SakuTown_House2_EventScript_Sister_Text_3:
# 55 "/Users/rubyraven/Desktop/raven/decomps/pokemon-hearth/data/maps/SakuTown_House2/scripts.pory"
	.string "My brother's been feeling really down\n"
	.string "lately.\p"
	.string "His precious Pokémon disappeared\n"
	.string "during the big storm we had a while ago.$"

Silveridge_Refuge_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Silveridge_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Silveridge_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_TEMP_1
	getweekday
	switch VAR_RESULT
	case WEEKDAY_TUE, Silveridge_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	case WEEKDAY_THU, Silveridge_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	case WEEKDAY_SAT, Silveridge_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

Silveridge_Refuge_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	clearflag FLAG_TEMP_1
	return


Silveridge_Refuge_EventScript_ImWorried::
	speakername Silveridge_Refuge_EventScript_ImWorried_Text_0
	msgbox Silveridge_Refuge_EventScript_ImWorried_Text_1, MSGBOX_NPC
	return


Silveridge_Refuge_EventScript_Firebringer::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARCOAL, Silveridge_Refuge_EventScript_Firebringer_2
	special GetPlayerBoyLassString
	speakername Silveridge_Refuge_EventScript_Firebringer_Text_0
	msgbox Silveridge_Refuge_EventScript_Firebringer_Text_2
	closemessage
	giveitem ITEM_CHARCOAL
	setflag FLAG_RECEIVED_CHARCOAL
Silveridge_Refuge_EventScript_Firebringer_1:
	release
	return

Silveridge_Refuge_EventScript_Firebringer_2:
	speakername Silveridge_Refuge_EventScript_Firebringer_Text_0
	msgbox Silveridge_Refuge_EventScript_Firebringer_Text_1
	closemessage
	goto Silveridge_Refuge_EventScript_Firebringer_1


Silveridge_Refuge_EventScript_FirebringerFangirl::
	gettimeofday
	compare VAR_0x8000, TIME_EARLY_MORNING
	goto_if_eq Silveridge_Refuge_EventScript_FirebringerFangirl_1
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq Silveridge_Refuge_EventScript_FirebringerFangirl_1
	speakername Silveridge_Refuge_EventScript_FirebringerFangirl_Text_0
	msgbox Silveridge_Refuge_EventScript_FirebringerFangirl_Text_2, MSGBOX_NPC
	return

Silveridge_Refuge_EventScript_FirebringerFangirl_1:
	speakername Silveridge_Refuge_EventScript_FirebringerFangirl_Text_0
	msgbox Silveridge_Refuge_EventScript_FirebringerFangirl_Text_1, MSGBOX_NPC
	return


Silveridge_Refuge_EventScript_Artist::
	speakername Silveridge_Refuge_EventScript_Artist_Text_0
	msgbox Silveridge_Refuge_EventScript_Artist_Text_1, MSGBOX_NPC
	return


Silveridge_Refuge_EventScript_Kricketune::
	lock
	faceplayer
	setseenmon SPECIES_KRICKETUNE
	setspeakertomonname SPECIES_KRICKETUNE
	playmoncry SPECIES_KRICKETUNE, CRY_MODE_NORMAL
	msgbox Silveridge_Refuge_EventScript_Kricketune_Text_0
	waitmoncry
	closemessage
	release
	return


Silveridge_Refuge_EventScript_Shamisen::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_SHAMISEN_BATTLE_IN_POKECENTER, Silveridge_Refuge_EventScript_Shamisen_2
	special GetPlayerBoyGirlString
	speakername Silveridge_Refuge_EventScript_Shamisen_Text_0
	msgbox Silveridge_Refuge_EventScript_Shamisen_Text_2
	closemessage
	trainerbattle_no_intro TRAINER_SHAMISEN, Silveridge_Refuge_EventScript_Shamisen_Text_3
	speakername Silveridge_Refuge_EventScript_Shamisen_Text_0
	msgbox Silveridge_Refuge_EventScript_Shamisen_Text_4
	closemessage
	setflag FLAG_DAILY_SHAMISEN_BATTLE_IN_POKECENTER
Silveridge_Refuge_EventScript_Shamisen_1:
	release
	end

Silveridge_Refuge_EventScript_Shamisen_2:
	speakername Silveridge_Refuge_EventScript_Shamisen_Text_0
	msgbox Silveridge_Refuge_EventScript_Shamisen_Text_1
	closemessage
	goto Silveridge_Refuge_EventScript_Shamisen_1


Silveridge_Refuge_EventScript_ImWorried_Text_0:
	.string "Woman$"

Silveridge_Refuge_EventScript_ImWorried_Text_1:
	.string "The whole town trembles from the\n"
	.string "Volcano's quakes…\p"
	.string "I'm so worried…$"

Silveridge_Refuge_EventScript_Firebringer_Text_0:
	.string "Firebringer$"

Silveridge_Refuge_EventScript_Firebringer_Text_1:
	.string "I'm bringin' down some Slugma today,\n"
	.string "freshly caught on Burnfoot Pass this\l"
	.string "mornin'.\p"
	.string "Tomorrow I'll be back up there,\n"
	.string "catching some more of 'em.$"

Silveridge_Refuge_EventScript_Firebringer_Text_2:
	.string "Hm? You askin' why I smell like smoke?\p"
	.string "Prob'ly 'cause I just got down from Mt\n"
	.string "Kazan, and lemme tell ya,\l"
	.string "{STR_VAR_1}, it is no piece o' cake!\p"
	.string "There's molten lava, aggressive\n"
	.string "Pokémon, chambers filled to the brim\l"
	.string "with explosive smoke!\p"
	.string "Firebringers risk their life to\n"
	.string "capture fresh Slugma an' carry 'em to\l"
	.string "towns an' cities!\p"
	.string "… …Wait, there's a piece of Charcoal\n"
	.string "stuck in my pocket.\l"
	.string "The smell actually probably comes\l"
	.string "from there…\p"
	.string "Here, you can keep it as a souvenir\n"
	.string "from Mt Kazan!$"

Silveridge_Refuge_EventScript_FirebringerFangirl_Text_0:
	.string "Girl$"

Silveridge_Refuge_EventScript_FirebringerFangirl_Text_1:
	.string "The Firebringer is coming to\n"
	.string "Silveridge today! Gosh, I can't wait!$"

Silveridge_Refuge_EventScript_FirebringerFangirl_Text_2:
	.string "Oh gosh, look at him…\n"
	.string "He's so…\l"
	.string "Rough-looking…\l"
	.string "And handsome…And he smells like\l"
	.string "smoke…\p"
	.string "Sigh…$"

Silveridge_Refuge_EventScript_Artist_Text_0:
	.string "Artist$"

Silveridge_Refuge_EventScript_Artist_Text_1:
	.string "Listening to the musician's sweet\n"
	.string "song inspires me so!$"

Silveridge_Refuge_EventScript_Kricketune_Text_0:
	.string "Delelelele…$"

Silveridge_Refuge_EventScript_Shamisen_Text_0:
	.string "Shamisen player$"

Silveridge_Refuge_EventScript_Shamisen_Text_1:
	.string "Are you resting here for the night as\n"
	.string "well?$"

Silveridge_Refuge_EventScript_Shamisen_Text_2:
	.string "Good evening to you, {STR_VAR_1}.\p"
	.string "Are you here to listen to my music?\p"
	.string "Or are you here to battle?$"

Silveridge_Refuge_EventScript_Shamisen_Text_3:
	.string "Such fun!$"

Silveridge_Refuge_EventScript_Shamisen_Text_4:
	.string "That was just the thing I needed to\n"
	.string "pass the time.$"

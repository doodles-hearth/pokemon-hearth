Silveridge_Refuge_MapScripts::
	.byte 0


Silveridge_Refuge_EventScript_ImWorried::
	speakername Silveridge_Refuge_EventScript_ImWorried_Text_0
	msgbox Silveridge_Refuge_EventScript_ImWorried_Text_1, MSGBOX_NPC
	return


Silveridge_Refuge_EventScript_Firebringer::
	speakername Silveridge_Refuge_EventScript_Firebringer_Text_0
	msgbox Silveridge_Refuge_EventScript_Firebringer_Text_1, MSGBOX_NPC
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
	.string "freshly caught on Burnfoot Pass\l"
	.string "this mornin'.\p"
	.string "Tomorrow I'll be back up there,\n"
	.string "catching some more of 'em.$"

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
	.string "Are you resting here for the night\n"
	.string "as well?$"

Silveridge_Refuge_EventScript_Shamisen_Text_2:
	.string "Good evening to you,\n"
	.string "{STR_VAR_1}.\p"
	.string "Are you here to listen to my\n"
	.string "music?\p"
	.string "Or are you here to battle?$"

Silveridge_Refuge_EventScript_Shamisen_Text_3:
	.string "Such fun!$"

Silveridge_Refuge_EventScript_Shamisen_Text_4:
	.string "That was just the thing I needed\n"
	.string "to pass the time.$"

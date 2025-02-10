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

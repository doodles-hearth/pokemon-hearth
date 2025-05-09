SakuTown_House1_MapScripts::
	.byte 0


SakuTown_House1_EventScript_Tama::
	lock
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 0
	goto_if_eq SakuTown_House1_EventScript_Tama_2
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 1
	goto_if_eq SakuTown_House1_EventScript_Tama_3
	speakername SakuTown_House1_EventScript_Tama_Text_1
	msgbox SakuTown_House1_EventScript_Tama_Text_9
	closemessage
SakuTown_House1_EventScript_Tama_1:
	release
	return

SakuTown_House1_EventScript_Tama_2:
	call TamaScript1
	goto SakuTown_House1_EventScript_Tama_1

SakuTown_House1_EventScript_Tama_3:
	call TamaScript1
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SakuTown_House1_EventScript_Tama_Text_0
	speakername SakuTown_House1_EventScript_Tama_Text_1
	msgbox SakuTown_House1_EventScript_Tama_Text_2
	closemessage
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SakuTown_House1_EventScript_Tama_Text_3
	delay 32
	speakername SakuTown_House1_EventScript_Tama_Text_1
	msgbox SakuTown_House1_EventScript_Tama_Text_4
	closemessage
	delay 32
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SakuTown_House1_EventScript_Tama_Text_5
	playse SE_PIN
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	speakername SakuTown_House1_EventScript_Tama_Text_1
	msgbox SakuTown_House1_EventScript_Tama_Text_6
	closemessage
	playse SE_SELECT
	removeitem ITEM_ASHIIS_SCARF, 1
	msgbox SakuTown_House1_EventScript_Tama_Text_7
	waitse
	closemessage
	speakername SakuTown_House1_EventScript_Tama_Text_1
	msgbox SakuTown_House1_EventScript_Tama_Text_8
	closemessage
	applymovement 1, Common_Movement_FaceAwayPlayer
	waitmovement 0
	delay 60
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	speakername SakuTown_House1_EventScript_Tama_Text_1
	msgbox SakuTown_House1_EventScript_Tama_Text_9
	closemessage
	addvar VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 1
	goto SakuTown_House1_EventScript_Tama_1


TamaScript1:
	speakername TamaScript1_Text_0
	msgbox TamaScript1_Text_1
	closemessage
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 1
	goto_if_eq TamaScript1_1
	return

TamaScript1_1:
	return


SakuTown_House1_EventScript_Tama_Text_0:
	.string "Hey, are you Tama?$"

SakuTown_House1_EventScript_Tama_Text_1:
	.string "Tama$"

SakuTown_House1_EventScript_Tama_Text_2:
	.string "…So?$"

SakuTown_House1_EventScript_Tama_Text_3:
	.string "I have something for you.$"

SakuTown_House1_EventScript_Tama_Text_4:
	.string "…$"

SakuTown_House1_EventScript_Tama_Text_5:
	.string "It's from Ashii in Kura.$"

SakuTown_House1_EventScript_Tama_Text_6:
	.string "WHAT?! Let me see!$"

SakuTown_House1_EventScript_Tama_Text_7:
	.string "Gave Tama the scarf.$"

SakuTown_House1_EventScript_Tama_Text_8:
	.string "I… I can't believe it! She really does\nlove me! Thank you for this!\p Eh? There's a letter inside!\n Whatever for?\p “My dear Tama. It pains me that you're\n not by my side each night. The sweet\l chirping of birds pales in comparison\l to your hearty laugh. I would move\l heaven and earth if it meant we could\l be together. If your heart still rings\l true for mine, will you meet me under\l pale moonlight, in the vale lying\l betwixt our homes?”\p The vale… she must be talking about\n the small valley to the east of here!\l And pale moonlight… that must be\l tonight! Yes, that has to be it! Why\l else ask you to deliver this now?$"

SakuTown_House1_EventScript_Tama_Text_9:
	.string "Wielder, I owe you my thanks. Please,\n"
	.string "tell her that I'll meet her tonight!\l"
	.string "I'll be waiting for her!$"

TamaScript1_Text_0:
	.string "Boy$"

TamaScript1_Text_1:
	.string "Please go away. Leave me alone.$"

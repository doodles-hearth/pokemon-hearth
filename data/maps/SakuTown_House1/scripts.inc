SakuTown_House1_MapScripts::
	.byte 0


SakuTown_House1_EventScript_Tama::
	lock
	speakername SakuTown_House1_EventScript_Tama_Text_0
	msgbox SakuTown_House1_EventScript_Tama_Text_1
	closemessage
	compare VAR_SAKU_KURA_QUEST_TAMA_ASHII_STATE, 1
	goto_if_eq SakuTown_House1_EventScript_Tama_2
SakuTown_House1_EventScript_Tama_1:
	release
	return

SakuTown_House1_EventScript_Tama_2:
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SakuTown_House1_EventScript_Tama_Text_2
	speakername SakuTown_House1_EventScript_Tama_Text_3
	msgbox SakuTown_House1_EventScript_Tama_Text_4
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SakuTown_House1_EventScript_Tama_Text_5
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, SakuTown_House1_EventScript_Tama_Text_6
	playse SE_PIN
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	msgbox SakuTown_House1_EventScript_Tama_Text_7
	closemessage
	removeitem ITEM_ASHIIS_SCARF, 1
	playse SE_SELECT
	msgbox SakuTown_House1_EventScript_Tama_Text_8
	closemessage
	speakername SakuTown_House1_EventScript_Tama_Text_3
	msgbox SakuTown_House1_EventScript_Tama_Text_9
	goto SakuTown_House1_EventScript_Tama_1


SakuTown_House1_EventScript_Tama_Text_0:
	.string "Boy$"

SakuTown_House1_EventScript_Tama_Text_1:
	.string "Please go away. Leave me alone.$"

SakuTown_House1_EventScript_Tama_Text_2:
	.string "Hey, are you Tama?$"

SakuTown_House1_EventScript_Tama_Text_3:
	.string "Tama$"

SakuTown_House1_EventScript_Tama_Text_4:
	.string "…So?$"

SakuTown_House1_EventScript_Tama_Text_5:
	.string "I have something for you.$"

SakuTown_House1_EventScript_Tama_Text_6:
	.string "It's from Ashii in Kura.$"

SakuTown_House1_EventScript_Tama_Text_7:
	.string "WHAT?! Let me see!$"

SakuTown_House1_EventScript_Tama_Text_8:
	.string "Gave Tama the scarf.$"

SakuTown_House1_EventScript_Tama_Text_9:
	.string "I… I can't believe it! She really does\nlove me! Thank you for this!\p Eh? There's a letter inside!\n Whatever for?\p “My dear Tama. It pains me that you're\n not by my side each night. The sweet\l chirping of birds pales in comparison\l to your hearthy laugh. I would move\l heaven and earth if it meant we could\l be together. If your heart still rings\l true for mine, will you meet me under\l pale moonlight, in the scissure lying\l betwixt our homes?”\p The scissure… she must be talking\n about the small valley to the east of\l here! And pale moonlight… she must be\l talking about tonight! Yes, that has\l to be it! Why else ask you to deliver\l this now?$"

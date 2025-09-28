YifuCity_Onsen_MapScripts::
	.byte 0


YifuCity_Onsen_EventScript_Owner::
	lock
	faceplayer
	setspeaker YifuCity_Onsen_EventScript_Owner_Text_0
	msgbox YifuCity_Onsen_EventScript_Owner_Text_1
	release
	return


YifuCity_Onsen_EventScript_Owner_Text_0:
	.string "Owner$"

YifuCity_Onsen_EventScript_Owner_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_HOT_OLD_WOMAN EMOTE_NORMAL}The hot springs are closed for the\n"
	.string "moment.$"

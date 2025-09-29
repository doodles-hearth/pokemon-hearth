YifuCity_Onsen_MapScripts::
	.byte 0


YifuCity_Onsen_EventScript_Owner::
	lock
	faceplayer
	setspeaker SP_NAME_OWNER
	msgbox YifuCity_Onsen_EventScript_Owner_Text_0
	release
	return


YifuCity_Onsen_EventScript_Owner_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_HOT_OLD_WOMAN EMOTE_NORMAL}The hot springs are closed for the\n"
	.string "moment.$"

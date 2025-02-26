YifuCity_House1_2F_MapScripts::
	.byte 0


YifuCity_House1_2F_EventScript_ChildGiveDoll::
	lock
	goto_if_set FLAG_RECEIVED_DOLL_FROM_CHILD, YifuCity_House1_2F_EventScript_ChildGiveDoll_2
	goto_if_set FLAG_RECEIVED_SECRET_POWER, YifuCity_House1_2F_EventScript_ChildGiveDoll_5
	speakername YifuCity_House1_2F_EventScript_ChildGiveDoll_Text_0
	msgbox YifuCity_House1_2F_EventScript_ChildGiveDoll_Text_4
	closemessage
YifuCity_House1_2F_EventScript_ChildGiveDoll_1:
	release
	return

YifuCity_House1_2F_EventScript_ChildGiveDoll_2:
	faceplayer
	speakername YifuCity_House1_2F_EventScript_ChildGiveDoll_Text_0
	msgbox YifuCity_House1_2F_EventScript_ChildGiveDoll_Text_1
	closemessage
	goto YifuCity_House1_2F_EventScript_ChildGiveDoll_1

YifuCity_House1_2F_EventScript_ChildGiveDoll_5:
	faceplayer
	speakername YifuCity_House1_2F_EventScript_ChildGiveDoll_Text_0
	msgbox YifuCity_House1_2F_EventScript_ChildGiveDoll_Text_2
	closemessage
	givedecoration DECOR_LOTAD_DOLL
	speakername YifuCity_House1_2F_EventScript_ChildGiveDoll_Text_0
	msgbox YifuCity_House1_2F_EventScript_ChildGiveDoll_Text_3
	closemessage
	goto YifuCity_House1_2F_EventScript_ChildGiveDoll_1


YifuCity_House1_2F_EventScript_ChildStolenDoll::
	lock
	faceplayer
	speakername YifuCity_House1_2F_EventScript_ChildStolenDoll_Text_0
	msgbox YifuCity_House1_2F_EventScript_ChildStolenDoll_Text_1
	closemessage
	release
	return


YifuCity_House1_2F_EventScript_Vulpix::
	lock
	faceplayer
	setseenmon SPECIES_VULPIX
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
	speakername YifuCity_House1_2F_EventScript_Vulpix_Text_0
	msgbox YifuCity_House1_2F_EventScript_Vulpix_Text_1
	waitmoncry
	closemessage
	release
	return


YifuCity_House1_2F_EventScript_ChildGiveDoll_Text_0:
	.string "Little boy$"

YifuCity_House1_2F_EventScript_ChildGiveDoll_Text_1:
	.string "Keep your mouth shut about it!$"

YifuCity_House1_2F_EventScript_ChildGiveDoll_Text_2:
	.string "Quick, take this!$"

YifuCity_House1_2F_EventScript_ChildGiveDoll_Text_3:
	.string "Tell no one! I was never here!$"

YifuCity_House1_2F_EventScript_ChildGiveDoll_Text_4:
	.string "Quit following me around!!$"

YifuCity_House1_2F_EventScript_ChildStolenDoll_Text_0:
	.string "Little girl$"

YifuCity_House1_2F_EventScript_ChildStolenDoll_Text_1:
	.string "My brother is meaaannnn!\n"
	.string "He won't give me my doll back!!$"

YifuCity_House1_2F_EventScript_Vulpix_Text_0:
	.string "Vulpix$"

YifuCity_House1_2F_EventScript_Vulpix_Text_1:
	.string "Yap!$"

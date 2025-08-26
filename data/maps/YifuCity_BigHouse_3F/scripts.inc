YifuCity_BigHouse_3F_MapScripts::
	.byte 0


YifuCity_BigHouse_3F_EventScript_HarikosGrandma::
	lock
	faceplayer
	speakername YifuCity_BigHouse_3F_EventScript_HarikosGrandma_Text_0
	msgbox YifuCity_BigHouse_3F_EventScript_HarikosGrandma_Text_1
	closemessage
	release
	return


YifuCity_BigHouse_3F_EventScript_HarikosGrandpa::
	lock
	faceplayer
	speakername YifuCity_BigHouse_3F_EventScript_HarikosGrandpa_Text_0
	msgbox YifuCity_BigHouse_3F_EventScript_HarikosGrandpa_Text_1
	setnamedmon SPECIES_SNOM
	closemessage
	release
	return


YifuCity_BigHouse_3F_EventScript_HarikosSister::
	lock
	faceplayer
	speakername YifuCity_BigHouse_3F_EventScript_HarikosSister_Text_0
	msgbox YifuCity_BigHouse_3F_EventScript_HarikosSister_Text_1
	closemessage
	release
	return


YifuCity_BigHouse_3F_EventScript_HarikosBrother::
	lock
	faceplayer
	speakername YifuCity_BigHouse_3F_EventScript_HarikosBrother_Text_0
	msgbox YifuCity_BigHouse_3F_EventScript_HarikosBrother_Text_1
	closemessage
	release
	return


YifuCity_BigHouse_3F_EventScript_Snom::
	lock
	faceplayer
	setseenmon SPECIES_SNOM
	setspeakertomonname SPECIES_SNOM
	msgbox YifuCity_BigHouse_3F_EventScript_Snom_Text_0
	playmoncry SPECIES_SNOM, CRY_MODE_NORMAL
	waitmoncry
	release
	end


YifuCity_BigHouse_3F_EventScript_HarikosGrandma_Text_0:
	.string "Old Woman$"

YifuCity_BigHouse_3F_EventScript_HarikosGrandma_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_COLD_OLD_WOMAN EMOTE_NORMAL}I'm so proud of my grandchildren!\p"
	.string "My eldest is always out and about\n"
	.string "with her head in the clouds.\p"
	.string "She's quite the oddball, but she's\n"
	.string "probably the brightest of the bunch!$"

YifuCity_BigHouse_3F_EventScript_HarikosGrandpa_Text_0:
	.string "Old Man$"

YifuCity_BigHouse_3F_EventScript_HarikosGrandpa_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_COLD_OLD_MAN EMOTE_NORMAL}The climate here is a lot warmer than\n"
	.string "the Icy Isles.\p"
	.string "That's why we brought Snom with us!$"

YifuCity_BigHouse_3F_EventScript_HarikosSister_Text_0:
	.string "Little Girl$"

YifuCity_BigHouse_3F_EventScript_HarikosSister_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_COLD_LITTLE_GIRL EMOTE_NORMAL}My big sister brings us food from the\n"
	.string "places she visits!\p"
	.string "I miss her…$"

YifuCity_BigHouse_3F_EventScript_HarikosBrother_Text_0:
	.string "Boy$"

YifuCity_BigHouse_3F_EventScript_HarikosBrother_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_COLD_BOY_2 EMOTE_NORMAL}Where are you from? I haven't seen\n"
	.string "anyone with your hair color around\l"
	.string "here.$"

YifuCity_BigHouse_3F_EventScript_Snom_Text_0:
	.string "Mrmr…$"

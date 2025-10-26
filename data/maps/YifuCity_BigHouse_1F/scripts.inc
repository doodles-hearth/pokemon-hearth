YifuCity_BigHouse_1F_MapScripts::
	.byte 0


YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight::
	lock
	faceplayer
	setspeaker SP_NAME_GIRL
	goto_if_set FLAG_CLEARED_CROBAT_HIDEOUT, YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_2
	msgbox YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_Text_1
YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_1:
	release
	return

YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_2:
	msgbox YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_Text_0
	goto YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_1


YifuCity_BigHouse_1F_EventScript_Man::
	lock
	faceplayer
	setspeaker SP_NAME_GUY
	msgbox YifuCity_BigHouse_1F_EventScript_Man_Text_0
	release
	return


YifuCity_BigHouse_1F_EventScript_Pokemon::
	lock
	faceplayer
	setseenmon SPECIES_NIDORINA
	setspeakertomonname SPECIES_NIDORINA
	msgbox YifuCity_BigHouse_1F_EventScript_Pokemon_Text_0
	playmoncry SPECIES_NIDORINA, CRY_MODE_NORMAL
	waitmoncry
	release
	end


YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_GIRL_1 EMOTE_NORMAL}I'm happy Yifu City is safe again!$"

YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_GIRL_1 EMOTE_NORMAL}I stopped going out at night.\p"
	.string "Those fishy Crobat people loiter at\n"
	.string "the docks right next to our building,\l"
	.string "speaking in hush tones…$"

YifuCity_BigHouse_1F_EventScript_Man_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_FAT_GUY EMOTE_NORMAL}The Samurai aren't actually\n"
	.string "affiliated with the Toku Council.\l"
	.string "That's a common misconception!\p"
	.string "They're their own organization, which\n"
	.string "mostly deals in protecting the\l"
	.string "population and fighting crime.$"

YifuCity_BigHouse_1F_EventScript_Pokemon_Text_0:
	.string "Gyooh!$"

YifuCity_BigHouse_1F_MapScripts::
	.byte 0


YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight::
	lock
	faceplayer
	speakername YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_Text_0
	goto_if_set FLAG_CLEARED_CROBAT_HIDEOUT, YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_2
	msgbox YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_Text_2
YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_1:
	release
	return

YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_2:
	msgbox YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_Text_1
	goto YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_1


YifuCity_BigHouse_1F_EventScript_Man::
	lock
	faceplayer
	speakername YifuCity_BigHouse_1F_EventScript_Man_Text_0
	msgbox YifuCity_BigHouse_1F_EventScript_Man_Text_1
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
	.string "Girl$"

YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_Text_1:
	.string "I'm happy Yifu City is safe again!$"

YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_Text_2:
	.string "I stopped going out at night.\n"
	.string "Those fishy Crobat people roam the\l"
	.string "streets, loiter at the docks,\l"
	.string "speaking in hush tones…$"

YifuCity_BigHouse_1F_EventScript_Man_Text_0:
	.string "Guy$"

YifuCity_BigHouse_1F_EventScript_Man_Text_1:
	.string "Did you know? The Samurai aren't\n"
	.string "actually affiliated with the Toku\l"
	.string "Council. That's a common\l"
	.string "misconception!\p"
	.string "They're their own organization, which\n"
	.string "mostly deals in protecting the\l"
	.string "population and fighting crime.$"

YifuCity_BigHouse_1F_EventScript_Pokemon_Text_0:
	.string "Gyooh!$"

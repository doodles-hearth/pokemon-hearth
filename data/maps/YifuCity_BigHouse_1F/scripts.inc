YifuCity_BigHouse_1F_MapScripts::
	.byte 0


YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight::
	lock
	faceplayer
	speakername YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_Text_0
	msgbox YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_Text_1
	release
	return


YifuCity_BigHouse_1F_EventScript_Man::
	lock
	faceplayer
	speakername YifuCity_BigHouse_1F_EventScript_Man_Text_0
	msgbox YifuCity_BigHouse_1F_EventScript_Man_Text_1
	release
	return


YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_Text_0:
	.string "Girl$"

YifuCity_BigHouse_1F_EventScript_GirlCrobatAtNight_Text_1:
	.string "I stopped going out at night.\n"
	.string "Those fishy Crobat people roam\l"
	.string "the streets, speaking in hush tones…$"

YifuCity_BigHouse_1F_EventScript_Man_Text_0:
	.string "Guy$"

YifuCity_BigHouse_1F_EventScript_Man_Text_1:
	.string "Did you know? The Samurai aren't\n"
	.string "actually affiliated with the Elder\l"
	.string "council of Toku. That's a common\l"
	.string "misconception!\p"
	.string "They're their own organization,\n"
	.string "which mostly deals in protecting\l"
	.string "the population and fighting crime.$"

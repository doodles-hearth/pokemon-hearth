KuraTown_MapScripts::
	.byte 0


KuraTown_EventScript_TownSign::
# 6 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


KuraTown_EventScript_DirectionsSign::
# 10 "data/maps/KuraTown/scripts.pory"
	msgbox KuraTown_EventScript_DirectionsSign_Text_0, MSGBOX_SIGN
	return


KuraTown_EventScript_TownSign_Text_0:
# 6 "data/maps/KuraTown/scripts.pory"
	.string "Kura Village\n"
	.string "“A village where the mountains meet the\l"
	.string "woods.”$"

KuraTown_EventScript_DirectionsSign_Text_0:
# 10 "data/maps/KuraTown/scripts.pory"
	.string "{UP_ARROW} Silver Tunnel\n"
	.string "This way for Silveridge$"

YifuCity_Refuge_2F_MapScripts::
	.byte 0


YifuCity_Refuge_2F_OricorioTrade::
	return


YifuCity_Refuge_2F_TravelingMerchant::
	lock
	faceplayer
	speakername YifuCity_Refuge_2F_TravelingMerchant_Text_0
	msgbox YifuCity_Refuge_2F_TravelingMerchant_Text_1
	closemessage
	release
	return


YifuCity_Refuge_2F_CoupleMan::
	return


YifuCity_Refuge_2F_CoupleWoman::
	return


YifuCity_Refuge_2F_TravelingMerchant_Text_0:
	.string "Okada$"

YifuCity_Refuge_2F_TravelingMerchant_Text_1:
	.string "Oh, good evening, {PLAYER}! I'm\n"
	.string "exhausted! I've been walking\l"
	.string "since morning, I'm calling it a\l"
	.string "day.\p"
	.string "Never underestimate a good night's\n"
	.string "sleep!$"

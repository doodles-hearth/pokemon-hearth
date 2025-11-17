LongTideChannelSoulkeep_MapScripts::
	.byte 0


LongTideChannelSoulkeep_RouteSign::
	msgbox LongTideChannelSoulkeep_RouteSign_Text_0, MSGBOX_SIGN
	return


LongTideChannelSoulkeep_EventScripts_BoatGuy::
	lock
	msgbox LongTideChannelSoulkeep_EventScripts_BoatGuy_Text_0
	release
	return


LongTideChannelSoulkeep_RouteSign_Text_0:
	.string "{LEFT_ARROW} Havenisle$"

LongTideChannelSoulkeep_EventScripts_BoatGuy_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_MAN EMOTE_NORMAL}{SPEAKER NAME_OLD_MAN}I'm prepping my boat.$"

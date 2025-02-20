TravelingMerchant_EventScript_Keke::
	lock
	faceplayer
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	goto_if_set FLAG_MET_TRAVELING_MERCHANT, TravelingMerchant_EventScript_Keke_2
	setspeakertomonname SPECIES_KECLEON
TravelingMerchant_EventScript_Keke_1:
	random 3
	switch VAR_RESULT
	case 0, TravelingMerchant_EventScript_Keke_7
	case 1, TravelingMerchant_EventScript_Keke_8
	case 2, TravelingMerchant_EventScript_Keke_9
TravelingMerchant_EventScript_Keke_5:
	waitmoncry
	closemessage
	release
	return

TravelingMerchant_EventScript_Keke_2:
	speakername TravelingMerchant_EventScript_Keke_Text_0
	goto TravelingMerchant_EventScript_Keke_1

TravelingMerchant_EventScript_Keke_7:
	msgbox TravelingMerchant_EventScript_Keke_Text_1
	goto TravelingMerchant_EventScript_Keke_5

TravelingMerchant_EventScript_Keke_8:
	msgbox TravelingMerchant_EventScript_Keke_Text_2
	goto TravelingMerchant_EventScript_Keke_5

TravelingMerchant_EventScript_Keke_9:
	msgbox TravelingMerchant_EventScript_Keke_Text_3
	goto TravelingMerchant_EventScript_Keke_5


TravelingMerchant_EventScript_Keke_Text_0:
	.string "Keke$"

TravelingMerchant_EventScript_Keke_Text_1:
	.string "Keckecke!$"

TravelingMerchant_EventScript_Keke_Text_2:
	.string "Klehhh!$"

TravelingMerchant_EventScript_Keke_Text_3:
	.string "…$"

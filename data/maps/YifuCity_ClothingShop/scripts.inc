YifuCity_ClothingShop_MapScripts::
	.byte 0


YifuCity_ClothingShop_EventScript_Yutaka::
	return


YifuCity_ClothingShop_EventScript_Cashier::
	lock
	faceplayer
	speakername YifuCity_ClothingShop_EventScript_Cashier_Text_0
	msgbox YifuCity_ClothingShop_EventScript_Cashier_Text_1
	release
	return


YifuCity_ClothingShop_EventScript_Customer::
	lock
	faceplayer
	speakername YifuCity_ClothingShop_EventScript_Customer_Text_0
	msgbox YifuCity_ClothingShop_EventScript_Customer_Text_1
	release
	return


YifuCity_ClothingShop_EventScript_Cashier_Text_0:
	.string "Cashier$"

YifuCity_ClothingShop_EventScript_Cashier_Text_1:
	.string "Sorry, everything's sold out at the\n"
	.string "moment!\p"
	.string "We'll be restocking soon.$"

YifuCity_ClothingShop_EventScript_Customer_Text_0:
	.string "Girl$"

YifuCity_ClothingShop_EventScript_Customer_Text_1:
	.string "Ohmigosh ohmigosh ohmigosh!!\n"
	.string "Master Yutaka is here!!\p"
	.string "She's sooo beautiful, and her clothes\n"
	.string "are amazing!\p"
	.string "Did you know she's a designer, too?\n"
	.string "There's a whole clothing line to her\l"
	.string "name!$"

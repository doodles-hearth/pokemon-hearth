YifuCity_BigHouse_3F_MapScripts::
	.byte 0


YifuCity_BigHouse_3F_EventScript_TradingActOfLove::
	lock
	faceplayer
	speakername YifuCity_BigHouse_3F_EventScript_TradingActOfLove_Text_0
	msgbox YifuCity_BigHouse_3F_EventScript_TradingActOfLove_Text_1
	closemessage
	release
	return


YifuCity_BigHouse_3F_EventScript_Butterfree::
	lock
	faceplayer
	setseenmon SPECIES_BUTTERFREE
	setspeakertomonname SPECIES_BUTTERFREE
	msgbox YifuCity_BigHouse_3F_EventScript_Butterfree_Text_0
	playmoncry SPECIES_BUTTERFREE, CRY_MODE_NORMAL
	waitmoncry
	release
	end


YifuCity_BigHouse_3F_EventScript_TradingActOfLove_Text_0:
	.string "Woman$"

YifuCity_BigHouse_3F_EventScript_TradingActOfLove_Text_1:
	.string "Trading Pokémon has long been seen\n"
	.string "as an act of true love and trust\l"
	.string "between wielders.\p"
	.string "Now that I've become a wielder, I\n"
	.string "can't wait to find my soulmate so\l"
	.string "she can trade me all her rare\l"
	.string "Pokémon!$"

YifuCity_BigHouse_3F_EventScript_Butterfree_Text_0:
	.string "E-e-e-eee!$"

YifuCity_BigHouse_2F_MapScripts::
	.byte 0


YifuCity_BigHouse_2F_EventScript_OldManScaredOfPokemon::
	lock
	faceplayer
	speakername YifuCity_BigHouse_2F_EventScript_OldManScaredOfPokemon_Text_0
	msgbox YifuCity_BigHouse_2F_EventScript_OldManScaredOfPokemon_Text_1
	release
	return


YifuCity_BigHouse_2F_EventScript_TradingActOfLove::
	lock
	faceplayer
	speakername YifuCity_BigHouse_2F_EventScript_TradingActOfLove_Text_0
	msgbox YifuCity_BigHouse_2F_EventScript_TradingActOfLove_Text_1
	closemessage
	release
	return


YifuCity_BigHouse_2F_EventScript_RunningBoy::
	lock
	faceplayer
	speakername YifuCity_BigHouse_2F_EventScript_RunningBoy_Text_0
	msgbox YifuCity_BigHouse_2F_EventScript_RunningBoy_Text_1
	release
	return


YifuCity_BigHouse_2F_EventScript_OldManScaredOfPokemon_Text_0:
	.string "Old man$"

YifuCity_BigHouse_2F_EventScript_OldManScaredOfPokemon_Text_1:
	.string "I was told I needed to raise a\n"
	.string "Pokémon of my own. No sir!\p"
	.string "Back in my day, we didn't need no\n"
	.string "Pokémon!\l"
	.string "A fire Pokémon burned my hand, a good\l"
	.string "many years ago…\l"
	.string "Now I'm scared! I don't want anything\l"
	.string "to do with them!$"

YifuCity_BigHouse_2F_EventScript_TradingActOfLove_Text_0:
	.string "Woman$"

YifuCity_BigHouse_2F_EventScript_TradingActOfLove_Text_1:
	.string "Trading Pokémon has long been seen\n"
	.string "as an act of true love and trust\l"
	.string "between Wielders.\p"
	.string "Now that I've become a Wielder, I\n"
	.string "can't wait to find my soulmate so she\l"
	.string "can trade me all her rare Pokémon!$"

YifuCity_BigHouse_2F_EventScript_RunningBoy_Text_0:
	.string "Boy$"

YifuCity_BigHouse_2F_EventScript_RunningBoy_Text_1:
	.string "My grandpa won't let me have a\n"
	.string "Pokémon!\p"
	.string "I'm bored! I want Pokémon too!$"

YifuCity_BigHouse_2F_MapScripts::
	.byte 0


YifuCity_BigHouse_2F_EventScript_OldManScaredOfPokemon::
	lock
	faceplayer
	speakername YifuCity_BigHouse_2F_EventScript_OldManScaredOfPokemon_Text_0
	msgbox YifuCity_BigHouse_2F_EventScript_OldManScaredOfPokemon_Text_1
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

YifuCity_BigHouse_2F_EventScript_RunningBoy_Text_0:
	.string "Boy$"

YifuCity_BigHouse_2F_EventScript_RunningBoy_Text_1:
	.string "My grandpa won't let me have a\n"
	.string "Pokémon!\p"
	.string "I'm bored! I want Pokémon too!$"

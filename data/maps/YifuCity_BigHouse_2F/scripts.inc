YifuCity_BigHouse_2F_MapScripts::
	.byte 0


YifuCity_BigHouse_2F_EventScript_OldManScaredOfPokemon::
	lock
	faceplayer
	setspeaker SP_NAME_OLD_MAN
	msgbox YifuCity_BigHouse_2F_EventScript_OldManScaredOfPokemon_Text_0
	release
	return


YifuCity_BigHouse_2F_EventScript_TradingActOfLove::
	lock
	faceplayer
	setspeaker SP_NAME_WOMAN
	msgbox YifuCity_BigHouse_2F_EventScript_TradingActOfLove_Text_0
	closemessage
	release
	return


YifuCity_BigHouse_2F_EventScript_RunningBoy::
	lock
	faceplayer
	applymovement VAR_LAST_TALKED, YifuCity_BigHouse_2F_EventScript_RunningBoy_Movement_0
	setspeaker SP_NAME_BOY
	msgbox YifuCity_BigHouse_2F_EventScript_RunningBoy_Text_0
	release
	return


YifuCity_BigHouse_2F_EventScript_RunningBoy_Movement_0:
	emote_angry
	step_end

YifuCity_BigHouse_2F_EventScript_OldManScaredOfPokemon_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_MAN EMOTE_NORMAL}I was told I needed to raise a Pokémon\nof my own. No sir!\p"
	.string "Didn't need no Pokémon back in my day!\nA fire Pokémon burned my hand, a good\lmany years ago…\p"
	.string "Now I'm scared!\nI don't want nothing to do with them!$"

YifuCity_BigHouse_2F_EventScript_TradingActOfLove_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_GIRL_2 EMOTE_NORMAL}Trading Pokémon is an act of true\n"
	.string "love and trust between Wielders.\p"
	.string "Now that I've become a Wielder, I\n"
	.string "can't wait to find my soulmate!\l"
	.string "She'll trade me all her rare Pokémon!$"

YifuCity_BigHouse_2F_EventScript_RunningBoy_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_BOY_1 EMOTE_NORMAL}My grandpa won't let me have a\n"
	.string "Pokémon!\p"
	.string "I'm bored! I want Pokémon too!$"

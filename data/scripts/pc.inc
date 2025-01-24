Common_EventScript_PcGuy::
	lock
	faceplayer
	goto_if_set FLAG_PC_EXPLAINED, Common_EventScript_PcGuy_2
	msgbox Common_EventScript_PcGuy_Text_1
Common_EventScript_PcGuy_1:
	call EventScript_AccessPokemonStorage
	special ShowPokemonStorageSystemPC
	waitstate
	goto_if_set FLAG_PC_EXPLAINED, Common_EventScript_PcGuy_6
	msgbox Common_EventScript_PcGuy_Text_3
	fadescreen FADE_TO_BLACK
	delay 120
	fadescreen FADE_FROM_BLACK
	msgbox Common_EventScript_PcGuy_Text_4
	setflag FLAG_PC_EXPLAINED
Common_EventScript_PcGuy_5:
	release
	end

Common_EventScript_PcGuy_2:
	msgbox Common_EventScript_PcGuy_Text_0
	goto Common_EventScript_PcGuy_1

Common_EventScript_PcGuy_6:
	msgbox Common_EventScript_PcGuy_Text_2
	goto Common_EventScript_PcGuy_5


EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_OTHER
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
	goto EventScript_PCMainMenu
	end

EventScript_PCMainMenu::
	message gText_WhichPCShouldBeAccessed
	waitmessage
	special ScriptMenu_CreatePCMultichoice
	waitstate
	goto EventScript_AccessPC
	end

EventScript_AccessPC::
	switch VAR_RESULT
	case 0, EventScript_AccessPokemonStorage
	case 1, EventScript_AccessPlayersPC
	case 2, EventScript_AccessHallOfFame
	case 3, EventScript_TurnOffPC
	case MULTI_B_PRESSED, EventScript_TurnOffPC
	end

EventScript_AccessPlayersPC::
	playse SE_PC_LOGIN
	msgbox gText_AccessedPlayersPC, MSGBOX_DEFAULT
	special PlayerPC
	waitstate
	goto EventScript_PCMainMenu
	end

EventScript_AccessPokemonStorage::
	playse SE_PC_LOGIN
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_AccessSomeonesPC
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_AccessLanettesPC
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	waitstate
	goto EventScript_PCMainMenu
	end

EventScript_AccessSomeonesPC::
	msgbox gText_AccessedSomeonesPC, MSGBOX_DEFAULT
	return

EventScript_AccessLanettesPC::
	msgbox gText_AccessedLanettesPC, MSGBOX_DEFAULT
	return

EventScript_TurnOffPC::
	setvar VAR_0x8004, PC_LOCATION_OTHER
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

EventScript_AccessHallOfFame::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_TurnOffPC
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	waitstate
	goto EventScript_AccessPC
	end

EventScript_AccessPokemonBoxLink::
	playse SE_PC_LOGIN
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	waitstate
	goto EventScript_TurnOffPC
	end

Common_EventScript_PcGuy_Text_0:
	.string "Need me to carry some Pokémon around\n"
	.string "for you? Sure thing!$"

Common_EventScript_PcGuy_Text_1:
	.string "Hey there, Pokémon wielder!\p"
	.string "Have you ever thought, “Darn, I wish I\n"
	.string "could catch this seventh Pokémon,\l"
	.string "but I only have room for six?”\p"
	.string "Today's your lucky day!\p"
	.string "I've been appointed by the Toku\n"
	.string "council to store wielders' Pokémon\l"
	.string "for them while they travel around.\p"
	.string "We bring your Pokémon to a ranch\n"
	.string "where they live happily while waiting\l"
	.string "for you to get them back!\p"
	.string "So if you ever want to store or\n"
	.string "retrieve your Pokémon, come talk to\l"
	.string "me!$"

Common_EventScript_PcGuy_Text_2:
	.string "Pant… pant… Thanks for using our\n"
	.string "Pokémon storage!$"

Common_EventScript_PcGuy_Text_3:
	.string "Oh, you want to store these Pokémon?\p"
	.string "Alright, I'll just carry them over to\n"
	.string "the ranch!\p"
	.string "Just a minute!$"

Common_EventScript_PcGuy_Text_4:
	.string "PANT… PANT…\p"
	.string "Your… pant… Pokémon… pant… are all\n"
	.string "set!\p"
	.string "Whew, the ranch is a little far from\n"
	.string "here! Pant…\p"
	.string "Come… pant… Come again!$"

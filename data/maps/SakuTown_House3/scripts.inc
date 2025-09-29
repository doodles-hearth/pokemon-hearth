SakuTown_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SakuTown_House3_EventScript_SetUpPokemon
	.byte 0


SakuTown_House3_EventScript_SetUpPokemon::
	goto_if_unset FLAG_FORTREE_NPC_TRADE_COMPLETED, SakuTown_House3_EventScript_SetUpPokemon_1
	return

SakuTown_House3_EventScript_SetUpPokemon_1:
	setflag FLAG_TEMP_1
	return


SakuTown_House3_EventScript_Psyduck::
	lock
	faceplayer
	setseenmon SPECIES_PSYDUCK_TOKUAN
	setspeakertomonname SPECIES_PSYDUCK
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
	msgbox SakuTown_House3_EventScript_Psyduck_Text_0
	waitmoncry
	release
	end


SakuTown_House3_EventScript_Hoothoot::
	lock
	faceplayer
	setspeakertomonname SPECIES_HOOTHOOT
	msgbox SakuTown_House3_EventScript_Hoothoot_Text_0
	playmoncry SPECIES_HOOTHOOT, CRY_MODE_NORMAL
	waitmoncry
	release
	end


SakuTown_House3_EventScript_TradeMe::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, SakuTown_House3_EventScript_TradeMe_2
	setvar VAR_0x8008, INGAME_TRADE_PSYDUCK
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	setspeaker SP_NAME_LITTLE_BOY
	msgbox SakuTown_House3_EventScript_TradeMe_Text_1
	mcdialogue SakuTown_House3_EventScript_TradeMe_Text_2, SakuTown_House3_EventScript_TradeMe_Text_3
	compare VAR_RESULT, 0
	goto_if_ne SakuTown_House3_EventScript_TradeMe_5
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq SakuTown_House3_EventScript_TradeMe_8
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne SakuTown_House3_EventScript_TradeMe_11
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	applymovement VAR_LAST_TALKED, SakuTown_House3_EventScript_TradeMe_Movement_0
	waitmovement 0
	applymovement 3, SakuTown_House3_EventScript_TradeMe_Movement_1
	waitmovement 0
	applymovement VAR_LAST_TALKED, SakuTown_House3_EventScript_TradeMe_Movement_2
	waitmovement 0
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	clearflag FLAG_TEMP_1
	removeobject 3
	waitstate
	addobject 4
	applymovement 4, SakuTown_House3_EventScript_TradeMe_Movement_3
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox SakuTown_House3_EventScript_TradeMe_Text_6, MSGBOX_DEFAULT
	closemessage
SakuTown_House3_EventScript_TradeMe_1:
	release
	return

SakuTown_House3_EventScript_TradeMe_2:
	setspeaker SP_NAME_LITTLE_BOY
	msgbox SakuTown_House3_EventScript_TradeMe_Text_0
	closemessage
	goto SakuTown_House3_EventScript_TradeMe_1

SakuTown_House3_EventScript_TradeMe_5:
	setspeaker SP_NAME_LITTLE_BOY
	msgbox SakuTown_House3_EventScript_TradeMe_Text_4
	closemessage
	goto SakuTown_House3_EventScript_TradeMe_1

SakuTown_House3_EventScript_TradeMe_8:
	setspeaker SP_NAME_LITTLE_BOY
	msgbox SakuTown_House3_EventScript_TradeMe_Text_4
	closemessage
	goto SakuTown_House3_EventScript_TradeMe_1

SakuTown_House3_EventScript_TradeMe_11:
	setspeaker SP_NAME_LITTLE_BOY
	msgbox SakuTown_House3_EventScript_TradeMe_Text_5
	closemessage
	goto SakuTown_House3_EventScript_TradeMe_1


SakuTown_House3_EventScript_Man::
	lock
	faceplayer
	setspeaker SP_NAME_MAN
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, SakuTown_House3_EventScript_Man_2
	msgbox SakuTown_House3_EventScript_Man_Text_1
SakuTown_House3_EventScript_Man_1:
	closemessage
	release
	return

SakuTown_House3_EventScript_Man_2:
	msgbox SakuTown_House3_EventScript_Man_Text_0
	goto SakuTown_House3_EventScript_Man_1


SakuTown_House3_EventScript_TradeMe_Movement_0:
	face_left
	step_end

SakuTown_House3_EventScript_TradeMe_Movement_1:
	enter_pokeball
	delay_16
	delay_16
	step_end

SakuTown_House3_EventScript_TradeMe_Movement_2:
	face_down
	delay_16
	delay_16
	step_end

SakuTown_House3_EventScript_TradeMe_Movement_3:
	exit_pokeball
	set_visible
	delay_16
	delay_16
	delay_16
	step_end

SakuTown_House3_EventScript_Psyduck_Text_0:
	.string "Psaïaïaï…$"

SakuTown_House3_EventScript_Hoothoot_Text_0:
	.string "Hooo…$"

SakuTown_House3_EventScript_TradeMe_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_LITTLE_BOY EMOTE_NORMAL}How's Bread doing?$"

SakuTown_House3_EventScript_TradeMe_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_LITTLE_BOY EMOTE_NORMAL}The best thing about Pokémon is\n"
	.string "trading them around!\p"
	.string "I want a Hoothoot, but my pa doesn't\n"
	.string "let me go out at night.\p"
	.string "I'll trade you a super dope Psyduck\n"
	.string "for it!$"

SakuTown_House3_EventScript_TradeMe_Text_2:
	.string "Yes!$"

SakuTown_House3_EventScript_TradeMe_Text_3:
	.string "No thanks.$"

SakuTown_House3_EventScript_TradeMe_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_LITTLE_BOY EMOTE_NORMAL}Keep your Hoothoot, I don't want it\n"
	.string "anyway…$"

SakuTown_House3_EventScript_TradeMe_Text_5:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_LITTLE_BOY EMOTE_NORMAL}I don't want your weird Pokémon! I\n"
	.string "want a Hoothoot!$"

SakuTown_House3_EventScript_TradeMe_Text_6:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_LITTLE_BOY EMOTE_NORMAL}Yeahhh!! I have a {STR_VAR_1} now!\p"
	.string "Take good care of Bread for me, okay?$"

SakuTown_House3_EventScript_Man_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_2 EMOTE_NORMAL}Oh great, he's got yet another\n"
	.string "Pokémon…$"

SakuTown_House3_EventScript_Man_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_2 EMOTE_NORMAL}My son is really into this whole\n"
	.string "Pokémon trading business, huh…$"

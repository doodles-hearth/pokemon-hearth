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
	msgbox SakuTown_House3_EventScript_Psyduck_Text_0
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
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
	speakername SakuTown_House3_EventScript_TradeMe_Text_0
	msgbox SakuTown_House3_EventScript_TradeMe_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SakuTown_House3_EventScript_TradeMe_5
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq SakuTown_House3_EventScript_TradeMe_5
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq SakuTown_House3_EventScript_TradeMe_10
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne SakuTown_House3_EventScript_TradeMe_13
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	clearflag FLAG_TEMP_1
	removeobject 3
	waitstate
	addobject 4
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox SakuTown_House3_EventScript_TradeMe_Text_5, MSGBOX_DEFAULT
	closemessage
SakuTown_House3_EventScript_TradeMe_1:
	release
	return

SakuTown_House3_EventScript_TradeMe_2:
	speakername SakuTown_House3_EventScript_TradeMe_Text_0
	msgbox SakuTown_House3_EventScript_TradeMe_Text_1
	closemessage
	goto SakuTown_House3_EventScript_TradeMe_1

SakuTown_House3_EventScript_TradeMe_5:
	speakername SakuTown_House3_EventScript_TradeMe_Text_0
	msgbox SakuTown_House3_EventScript_TradeMe_Text_3
	closemessage
	goto SakuTown_House3_EventScript_TradeMe_1

SakuTown_House3_EventScript_TradeMe_10:
	speakername SakuTown_House3_EventScript_TradeMe_Text_0
	msgbox SakuTown_House3_EventScript_TradeMe_Text_3
	closemessage
	goto SakuTown_House3_EventScript_TradeMe_1

SakuTown_House3_EventScript_TradeMe_13:
	speakername SakuTown_House3_EventScript_TradeMe_Text_0
	msgbox SakuTown_House3_EventScript_TradeMe_Text_4
	closemessage
	goto SakuTown_House3_EventScript_TradeMe_1


SakuTown_House3_EventScript_Man::
	lock
	faceplayer
	speakername SakuTown_House3_EventScript_Man_Text_0
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, SakuTown_House3_EventScript_Man_2
	msgbox SakuTown_House3_EventScript_Man_Text_2
SakuTown_House3_EventScript_Man_1:
	closemessage
	release
	return

SakuTown_House3_EventScript_Man_2:
	msgbox SakuTown_House3_EventScript_Man_Text_1
	goto SakuTown_House3_EventScript_Man_1


SakuTown_House3_EventScript_Psyduck_Text_0:
	.string "Psaïaïaï…$"

SakuTown_House3_EventScript_Hoothoot_Text_0:
	.string "Hooo…$"

SakuTown_House3_EventScript_TradeMe_Text_0:
	.string "Little boy$"

SakuTown_House3_EventScript_TradeMe_Text_1:
	.string "Thank you!$"

SakuTown_House3_EventScript_TradeMe_Text_2:
	.string "The best thing about Pokémon is\n"
	.string "trading them around!\p"
	.string "I want a Hoothoot, but my pa\n"
	.string "doesn't let me go out at night.\p"
	.string "I'll trade you a super dope\n"
	.string "Psyduck for it!$"

SakuTown_House3_EventScript_TradeMe_Text_3:
	.string "Keep your Hoothoot, I don't want it\n"
	.string "anyway…$"

SakuTown_House3_EventScript_TradeMe_Text_4:
	.string "I don't want your weird Pokémon! I\n"
	.string "want a Hoothoot!$"

SakuTown_House3_EventScript_TradeMe_Text_5:
	.string "Yeahhh!! I have a {STR_VAR_1}\n"
	.string "now!\p"
	.string "Take good care of Bread for me,\n"
	.string "okay?$"

SakuTown_House3_EventScript_Man_Text_0:
	.string "Man$"

SakuTown_House3_EventScript_Man_Text_1:
	.string "Oh great, he's got yet another\n"
	.string "Pokémon…$"

SakuTown_House3_EventScript_Man_Text_2:
	.string "My son is really into this whole\n"
	.string "Pokémon trading business, huh…$"

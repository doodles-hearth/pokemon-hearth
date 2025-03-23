YifuCity_House3_MapScripts::
	.byte 0


YifuCity_House3_EggGirlsMom::
	lock
	faceplayer
	speakername YifuCity_House3_EggGirlsMom_Text_0
	msgbox YifuCity_House3_EggGirlsMom_Text_1
	release
	return


YifuCity_House3_EventScript_Togepi::
	lock
	faceplayer
	setseenmon SPECIES_TOGEPI
	setspeakertomonname SPECIES_TOGEPI
	msgbox YifuCity_House3_EventScript_Togepi_Text_0
	playmoncry SPECIES_TOGEPI, CRY_MODE_NORMAL
	waitmoncry
	release
	end


YifuCity_House3_EventScript_EggGirl::
	lock
	faceplayer
	compare VAR_EGG_SPECIES_GIVEN_TO_EGG_GIRL, SPECIES_NONE
	goto_if_eq YifuCity_House3_EventScript_EggGirl_2
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
	msgbox YifuCity_House3_EventScript_EggGirl_Text_1
YifuCity_House3_EventScript_EggGirl_1:
	release
	return

YifuCity_House3_EventScript_EggGirl_2:
	call YifuCity_House3_NotTradedYet
	goto YifuCity_House3_EventScript_EggGirl_1


YifuCity_House3_NotTradedYet::
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
	special GetPlayerSirMissString
	msgbox YifuCity_House3_NotTradedYet_Text_0
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_House3_NotTradedYet_Text_1, YifuCity_House3_NotTradedYet_Text_2, YifuCity_House3_NotTradedYet_Text_3, YifuCity_House3_NotTradedYet_Text_4
	closemessage
	switch VAR_RESULT
	case 0, YifuCity_House3_NotTradedYet_3
	case 1, YifuCity_House3_NotTradedYet_4
	case 2, YifuCity_House3_NotTradedYet_5
	case 3, YifuCity_House3_NotTradedYet_6
YifuCity_House3_NotTradedYet_1:
	dynmultichoice 0, 0, TRUE, 10, 0, DYN_MULTICHOICE_CB_NONE, YifuCity_House3_NotTradedYet_Text_9, YifuCity_House3_NotTradedYet_Text_10
	closemessage
	switch VAR_RESULT
	case 0, YifuCity_House3_NotTradedYet_9
	case 1, YifuCity_House3_NotTradedYet_10
YifuCity_House3_NotTradedYet_7:
	release
	return

YifuCity_House3_NotTradedYet_3:
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
	msgbox YifuCity_House3_NotTradedYet_Text_5
	goto YifuCity_House3_NotTradedYet_1

YifuCity_House3_NotTradedYet_4:
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
	msgbox YifuCity_House3_NotTradedYet_Text_6
	goto YifuCity_House3_NotTradedYet_1

YifuCity_House3_NotTradedYet_5:
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
	msgbox YifuCity_House3_NotTradedYet_Text_7
	release
	end

YifuCity_House3_NotTradedYet_6:
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
	msgbox YifuCity_House3_NotTradedYet_Text_8
	goto YifuCity_House3_NotTradedYet_1

YifuCity_House3_NotTradedYet_9:
	call YifuCity_House3_TradeEgg
	goto YifuCity_House3_NotTradedYet_7

YifuCity_House3_NotTradedYet_10:
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
	msgbox YifuCity_House3_NotTradedYet_Text_7
	goto YifuCity_House3_NotTradedYet_7


YifuCity_House3_TradeEgg::
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq YifuCity_House3_TradeEgg_1
	special IsSelectedMonEgg
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_House3_TradeEgg_4
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
	msgbox YifuCity_House3_TradeEgg_Text_3
	closemessage
	return

YifuCity_House3_TradeEgg_1:
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
	msgbox YifuCity_House3_TradeEgg_Text_0
	closemessage
	return

YifuCity_House3_TradeEgg_4:
	specialvar VAR_EGG_SPECIES_GIVEN_TO_EGG_GIRL, ScriptGetPartyMonSpeciesEvenIfEgg
	special DestroySelectedPartyMon
	giveegg SPECIES_WYNAUT
	playfanfare MUS_OBTAIN_ITEM
	message YifuCity_House3_TradeEgg_Text_1
	waitmessage
	waitfanfare
	speakername YifuCity_House3_EventScript_EggGirl_Text_0
	msgbox YifuCity_House3_TradeEgg_Text_2
	closemessage
	return


YifuCity_House3_EggGirlsMom_Text_0:
	.string "Woman$"

YifuCity_House3_EggGirlsMom_Text_1:
	.string "I help out at the Pokémon daycare\n"
	.string "west of Windycape on tuesdays.\l"
	.string "Sometimes they'll let me bring\l"
	.string "back an egg for my daughter!$"

YifuCity_House3_EventScript_Togepi_Text_0:
	.string "Preee!$"

YifuCity_House3_EventScript_EggGirl_Text_0:
	.string "Little girl$"

YifuCity_House3_EventScript_EggGirl_Text_1:
	.string "Can't wait for my egg to hatch!$"

YifuCity_House3_NotTradedYet_Text_0:
	.string "Hello {STR_VAR_1}! Do you like\n"
	.string "eggs?$"

YifuCity_House3_NotTradedYet_Text_1:
	.string "Yes!$"

YifuCity_House3_NotTradedYet_Text_2:
	.string "Yes, they're delicious!$"

YifuCity_House3_NotTradedYet_Text_3:
	.string "Not really.$"

YifuCity_House3_NotTradedYet_Text_4:
	.string "Eggs?$"

YifuCity_House3_NotTradedYet_Text_5:
	.string "Really?! Me too!! Pokémon eggs are\n"
	.string "so cool!\l"
	.string "I love not knowing what will jump\l"
	.string "out of the egg!\p"
	.string "Wanna trade me a mystery egg for a\n"
	.string "mystery egg?\l"
	.string "That way we'll both have a\l"
	.string "surprise!$"

YifuCity_House3_NotTradedYet_Text_6:
	.string "WHAT? Ewww, gross! I don't mean\n"
	.string "EATING them!\p"
	.string "I just love waiting for a Pokémon\n"
	.string "to jump of of its egg, especially\l"
	.string "when I have no idea what it's\l"
	.string "gonna be!\p"
	.string "Wanna trade me a mystery egg for a\n"
	.string "mystery egg?\l"
	.string "That way we'll both have a\l"
	.string "surprise!$"

YifuCity_House3_NotTradedYet_Text_7:
	.string "Oh… Alright…$"

YifuCity_House3_NotTradedYet_Text_8:
	.string "Eggs! Pokémon eggs! I just love\n"
	.string "waiting for a Pokémon to jump of\l"
	.string "of its egg, especially when I\l"
	.string "have no idea what it's gonna be!\p"
	.string "Wanna trade me a mystery egg for a\n"
	.string "mystery egg?\l"
	.string "That way we'll both have a\l"
	.string "surprise!$"

YifuCity_House3_NotTradedYet_Text_9:
	.string "Sure!$"

YifuCity_House3_NotTradedYet_Text_10:
	.string "No.$"

YifuCity_House3_TradeEgg_Text_0:
	.string "Have you changed your mind?$"

YifuCity_House3_TradeEgg_Text_1:
	.string "{PLAYER} received the mysterious\n"
	.string "egg!$"

YifuCity_House3_TradeEgg_Text_2:
	.string "Yay!!! I can't wait for my egg to\n"
	.string "hatch!\p"
	.string "Aren't you wondering what you're\n"
	.string "gonna get?$"

YifuCity_House3_TradeEgg_Text_3:
	.string "That's not an egg, you silly!$"

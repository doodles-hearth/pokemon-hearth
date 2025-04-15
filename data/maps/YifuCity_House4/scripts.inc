YifuCity_House4_MapScripts::
	.byte 0


YifuCity_House4_EventScript_NameRater::
	lock
	faceplayer
	msgbox YifuCity_House4_EventScript_NameRater_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq YifuCity_House4_EventScript_NameRater_2
	msgbox YifuCity_House4_EventScript_NameRater_Text_7
YifuCity_House4_EventScript_NameRater_1:
	release
	return

YifuCity_House4_EventScript_NameRater_2:
	msgbox YifuCity_House4_EventScript_NameRater_Text_1
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq YifuCity_House4_EventScript_NameRater_5
	goto YifuCity_House4_EventScript_NameRater_1

YifuCity_House4_EventScript_NameRater_5:
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq YifuCity_House4_EventScript_NameRater_7
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_House4_EventScript_NameRater_10
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_House4_EventScript_NameRater_13
	msgbox YifuCity_House4_EventScript_NameRater_Text_4
	call Common_EventScript_NameReceivedPartyMon
	special BufferMonNickname
	specialvar VAR_RESULT, WasNicknameChanged
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_House4_EventScript_NameRater_16
	msgbox YifuCity_House4_EventScript_NameRater_Text_6
	goto YifuCity_House4_EventScript_NameRater_1

YifuCity_House4_EventScript_NameRater_7:
	msgbox YifuCity_House4_EventScript_NameRater_Text_2
	goto YifuCity_House4_EventScript_NameRater_1

YifuCity_House4_EventScript_NameRater_10:
	msgbox YifuCity_House4_EventScript_NameRater_Text_3
	goto YifuCity_House4_EventScript_NameRater_1

YifuCity_House4_EventScript_NameRater_13:
	msgbox YifuCity_House4_EventScript_NameRater_Text_3
	goto YifuCity_House4_EventScript_NameRater_1

YifuCity_House4_EventScript_NameRater_16:
	msgbox YifuCity_House4_EventScript_NameRater_Text_5
	goto YifuCity_House4_EventScript_NameRater_1


YifuCity_House4_EventScript_NameRater_Text_0:
	.string "Names are the mirror of the soul!\p"
	.string "{FONT_SMALL}Or was that the eyes? Bah…{FONT_NORMAL}\p"
	.string "I have been told I have a way\n"
	.string "with names.\l"
	.string "Young wielder…\l"
	.string "Would you like me\l"
	.string "to counsel you on the naming of\l"
	.string "your Pokémon?$"

YifuCity_House4_EventScript_NameRater_Text_1:
	.string "Which Pokémon should receive my\n"
	.string "attention?$"

YifuCity_House4_EventScript_NameRater_Text_2:
	.string "Bah! An Egg is yet unborn…\n"
	.string "Its name yet unchosen!$"

YifuCity_House4_EventScript_NameRater_Text_3:
	.string "This creature… It was named by\n"
	.string "someone else, was it not?\p"
	.string "I couldn't ever strip this Pokémon\n"
	.string "from its original name, no no!$"

YifuCity_House4_EventScript_NameRater_Text_4:
	.string "{STR_VAR_1}…\n"
	.string "I see what you were going for…\p"
	.string "{FONT_SMALL}Yikes…{FONT_NORMAL} I don't see this Pokémon's soul\n"
	.string "in this name…\p"
	.string "Are you inspired to bestow a new name\n"
	.string "on it?\p"
	.string "Go ahead! Speak from your heart!$"

YifuCity_House4_EventScript_NameRater_Text_5:
	.string "{STR_VAR_1}… I see…\n"
	.string "This name rings with truth!\p"
	.string "Look… Your Pokémon seems happy\n"
	.string "about its new name!\p"
	.string "Goodbye! May wisdom guide your steps!\p"
	.string "{FONT_SMALL}Bah! I should ask money for this…{FONT_NORMAL}$"

YifuCity_House4_EventScript_NameRater_Text_6:
	.string "This new name… It sounds a little like\n"
	.string "its old name…\p"
	.string "{FONT_SMALL}Wait, what was the old name again?{FONT_NORMAL}\p"
	.string "Bah… You're confusing me!$"

YifuCity_House4_EventScript_NameRater_Text_7:
	.string "Nevermind, then.$"

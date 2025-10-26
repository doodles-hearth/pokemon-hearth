YifuCity_House4_MapScripts::
	.byte 0


YifuCity_House4_EventScript_NameRater::
	lock
	faceplayer
	setspeaker SP_NAME_NAME_RATER
	msgbox YifuCity_House4_EventScript_NameRater_Text_0
	mcdialogue YifuCity_House4_EventScript_NameRater_Text_1, YifuCity_House4_EventScript_NameRater_Text_2
	compare VAR_RESULT, 0
	goto_if_eq YifuCity_House4_EventScript_NameRater_2
	setspeaker SP_NAME_NAME_RATER
	msgbox YifuCity_House4_EventScript_NameRater_Text_9
YifuCity_House4_EventScript_NameRater_1:
	release
	return

YifuCity_House4_EventScript_NameRater_2:
	setspeaker SP_NAME_NAME_RATER
	msgbox YifuCity_House4_EventScript_NameRater_Text_3
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_ne YifuCity_House4_EventScript_NameRater_5
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
	setspeaker SP_NAME_NAME_RATER
	msgbox YifuCity_House4_EventScript_NameRater_Text_6
	call Common_EventScript_NameReceivedPartyMon
	special BufferMonNickname
	specialvar VAR_RESULT, WasNicknameChanged
	compare VAR_RESULT, 0
	goto_if_ne YifuCity_House4_EventScript_NameRater_16
	setspeaker SP_NAME_NAME_RATER
	msgbox YifuCity_House4_EventScript_NameRater_Text_8
	goto YifuCity_House4_EventScript_NameRater_1

YifuCity_House4_EventScript_NameRater_7:
	setspeaker SP_NAME_NAME_RATER
	msgbox YifuCity_House4_EventScript_NameRater_Text_4
	goto YifuCity_House4_EventScript_NameRater_1

YifuCity_House4_EventScript_NameRater_10:
	setspeaker SP_NAME_NAME_RATER
	msgbox YifuCity_House4_EventScript_NameRater_Text_5
	goto YifuCity_House4_EventScript_NameRater_1

YifuCity_House4_EventScript_NameRater_13:
	setspeaker SP_NAME_NAME_RATER
	msgbox YifuCity_House4_EventScript_NameRater_Text_5
	goto YifuCity_House4_EventScript_NameRater_1

YifuCity_House4_EventScript_NameRater_16:
	setspeaker SP_NAME_NAME_RATER
	msgbox YifuCity_House4_EventScript_NameRater_Text_7
	goto YifuCity_House4_EventScript_NameRater_1


YifuCity_House4_EventScript_NameRater_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_WOMAN EMOTE_NORMAL}Names are the mirror of the soul!\p"
	.string "{FONT_SMALL}Or was that the eyes? Bah…{FONT_NORMAL}\p"
	.string "I have been told I have a way\n"
	.string "with names.\p"
	.string "Young Wielder… Would you like me to\n"
	.string "counsel you on the naming of your\l"
	.string "Pokémon?$"

YifuCity_House4_EventScript_NameRater_Text_1:
	.string "Counsel me!$"

YifuCity_House4_EventScript_NameRater_Text_2:
	.string "No thanks.$"

YifuCity_House4_EventScript_NameRater_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_WOMAN EMOTE_NORMAL}Which Pokémon should receive my\n"
	.string "attention?$"

YifuCity_House4_EventScript_NameRater_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_WOMAN EMOTE_NORMAL}Bah! An Egg is yet unborn…\n"
	.string "Its name yet unchosen!$"

YifuCity_House4_EventScript_NameRater_Text_5:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_WOMAN EMOTE_NORMAL}This creature… It was named by\n"
	.string "someone else, was it not?\p"
	.string "I couldn't ever strip this Pokémon\n"
	.string "from its original name, no no!$"

YifuCity_House4_EventScript_NameRater_Text_6:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_WOMAN EMOTE_NORMAL}{STR_VAR_1}…\n"
	.string "I see what you were going for…\p"
	.string "{FONT_SMALL}Yikes…{FONT_NORMAL}\p"
	.string "But I don't see this Pokémon's soul in\n"
	.string "this name…\p"
	.string "Are you inspired to bestow a new name\n"
	.string "on it?\l"
	.string "Go ahead! Speak from your heart!$"

YifuCity_House4_EventScript_NameRater_Text_7:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_WOMAN EMOTE_NORMAL}{STR_VAR_1}… I see…\n"
	.string "This name rings with truth!\p"
	.string "Look… Your Pokémon seems happy\n"
	.string "about its new name!\p"
	.string "Goodbye!\n"
	.string "May wisdom guide your steps!\l"
	.string "{FONT_SMALL}Bah! I should charge for this…{FONT_NORMAL}$"

YifuCity_House4_EventScript_NameRater_Text_8:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_WOMAN EMOTE_NORMAL}This new name… It sounds a little like\n"
	.string "its old name…\p"
	.string "{FONT_SMALL}Wait, what was the old name again?{FONT_NORMAL}\p"
	.string "Bah… You're confusing me!$"

YifuCity_House4_EventScript_NameRater_Text_9:
	.string "{CREATE_MUGSHOT MUGSHOT_UUME_OLD_WOMAN EMOTE_NORMAL}Nevermind, then.$"

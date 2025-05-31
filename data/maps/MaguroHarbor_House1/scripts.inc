MaguroHarbor_House1_MapScripts::
	.byte 0


MaguroHarbor_House1_EventScript_PokedexRiddler::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_MON_DEX_RIDDLE, MaguroHarbor_House1_EventScript_PokedexRiddler_2
	speakername MaguroHarbor_House1_EventScript_PokedexRiddler_Text_0
	msgbox MaguroHarbor_House1_EventScript_PokedexRiddler_Text_2
	closemessage
	randomdexmsgbox
	speakername MaguroHarbor_House1_EventScript_PokedexRiddler_Text_0
	msgbox MaguroHarbor_House1_EventScript_PokedexRiddler_Text_3
	closemessage
	special EnterDexRiddleGuess
	waitstate
	special GetDexRiddleFeedback
	compare VAR_RESULT, 1
	goto_if_eq MaguroHarbor_House1_EventScript_PokedexRiddler_5
	speakername MaguroHarbor_House1_EventScript_PokedexRiddler_Text_0
	msgbox MaguroHarbor_House1_EventScript_PokedexRiddler_Text_5
MaguroHarbor_House1_EventScript_PokedexRiddler_4:
	setflag FLAG_DAILY_MON_DEX_RIDDLE
	release
	end

MaguroHarbor_House1_EventScript_PokedexRiddler_2:
	speakername MaguroHarbor_House1_EventScript_PokedexRiddler_Text_0
	msgbox MaguroHarbor_House1_EventScript_PokedexRiddler_Text_1
	closemessage
	release
	end

MaguroHarbor_House1_EventScript_PokedexRiddler_5:
	speakername MaguroHarbor_House1_EventScript_PokedexRiddler_Text_0
	msgbox MaguroHarbor_House1_EventScript_PokedexRiddler_Text_4
	closemessage
	setflag FLAG_DAILY_MON_DEX_RIDDLE_WON
	goto MaguroHarbor_House1_EventScript_PokedexRiddler_4


MaguroHarbor_House1_EventScript_Clefairy::
	lock
	faceplayer
	setseenmon SPECIES_CLEFAIRY
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_CLEFAIRY
	msgbox MaguroHarbor_House1_EventScript_Clefairy_Text_0
	waitmoncry
	release
	return


MaguroHarbor_House1_EventScript_PokedexRiddler_Text_0:
	.string "Pokémon Nerd$"

MaguroHarbor_House1_EventScript_PokedexRiddler_Text_1:
	.string "Come back tomorrow for more Pokémon\n"
	.string "riddles… Hehe…$"

MaguroHarbor_House1_EventScript_PokedexRiddler_Text_2:
	.string "Hehe… Hullo, kid…\n"
	.string "People call me the Pokémon Nerd.\p"
	.string "(They're just jealous…)\p"
	.string "I know a whole lot about Pokémon…\n"
	.string "Wanna play a game?\p"
	.string "If you can guess what Pokémon I'm\n"
	.string "describing, I'll share my knowledge\l"
	.string "with you.\p"
	.string "Hehe… Think you can solve my riddle?\n"
	.string "Ahem…$"

MaguroHarbor_House1_EventScript_PokedexRiddler_Text_3:
	.string "Well? What Pokémon am I talking about?$"

MaguroHarbor_House1_EventScript_PokedexRiddler_Text_4:
	.string "Woah, you… You solved my riddle!\p"
	.string "Could you… be a true Pokémon Nerd?\p"
	.string "You have bested me today. Can you\n"
	.string "feel the rush of pure knowledge\l"
	.string "that's coursing through your veins?\p"
	.string "Your Pokémon… They will gain more\n"
	.string "experience today.\p"
	.string "Knowledge is power, after all, hehe…\p"
	.string "Come back another time for another\n"
	.string "riddle…$"

MaguroHarbor_House1_EventScript_PokedexRiddler_Text_5:
	.string "Wrong, wrong, WRONG!\n"
	.string "You are wrong!\p"
	.string "I'm honestly disappointed.\p"
	.string "Come back tomorrow, or when you've\n"
	.string "accumulated more Pokémon knowledge.$"

MaguroHarbor_House1_EventScript_Clefairy_Text_0:
	.string "Teehee!$"

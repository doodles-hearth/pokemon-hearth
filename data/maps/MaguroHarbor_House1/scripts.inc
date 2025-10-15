MaguroHarbor_House1_MapScripts::
	.byte 0


MaguroHarbor_House1_EventScript_PokedexRiddler::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_MON_DEX_RIDDLE, MaguroHarbor_House1_EventScript_PokedexRiddler_2
	setspeaker SP_NAME_PKMN_NERD
	msgbox MaguroHarbor_House1_EventScript_PokedexRiddler_Text_1
	closemessage
	randomdexmsgbox
	setspeaker SP_NAME_PKMN_NERD
	msgbox MaguroHarbor_House1_EventScript_PokedexRiddler_Text_2
	closemessage
	special EnterDexRiddleGuess
	waitstate
	special GetDexRiddleFeedback
	compare VAR_RESULT, 1
	goto_if_eq MaguroHarbor_House1_EventScript_PokedexRiddler_5
	applymovement VAR_LAST_TALKED, MaguroHarbor_House1_EventScript_PokedexRiddler_Movement_1
	setspeaker SP_NAME_PKMN_NERD
	msgbox MaguroHarbor_House1_EventScript_PokedexRiddler_Text_4
MaguroHarbor_House1_EventScript_PokedexRiddler_4:
	setflag FLAG_DAILY_MON_DEX_RIDDLE
	release
	end

MaguroHarbor_House1_EventScript_PokedexRiddler_2:
	setspeaker SP_NAME_PKMN_NERD
	msgbox MaguroHarbor_House1_EventScript_PokedexRiddler_Text_0
	closemessage
	release
	end

MaguroHarbor_House1_EventScript_PokedexRiddler_5:
	playse SE_PIN
	applymovement LOCALID_MAGURO_NERD, MaguroHarbor_House1_EventScript_PokedexRiddler_Movement_0
	waitse
	waitmovement 0
	setspeaker SP_NAME_PKMN_NERD
	msgbox MaguroHarbor_House1_EventScript_PokedexRiddler_Text_3
	closemessage
	setflag FLAG_DAILY_MON_DEX_RIDDLE_WON
	goto MaguroHarbor_House1_EventScript_PokedexRiddler_4


MaguroHarbor_House1_EventScript_Clefairy::
	lock
	faceplayer
	setseenmon SPECIES_CLEFAIRY
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_CLEFAIRY
	applymovement VAR_LAST_TALKED, MaguroHarbor_House1_EventScript_Clefairy_Movement_0
	msgbox MaguroHarbor_House1_EventScript_Clefairy_Text_0
	waitmoncry
	release
	return


MaguroHarbor_House1_EventScript_PokedexRiddler_Movement_0:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

MaguroHarbor_House1_EventScript_PokedexRiddler_Movement_1:
	emote_upset
	step_end

MaguroHarbor_House1_EventScript_Clefairy_Movement_0:
	emote_music
	step_end

MaguroHarbor_House1_EventScript_PokedexRiddler_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_FAT_GUY EMOTE_NORMAL}Come back tomorrow for more Pokémon\n"
	.string "riddles… Hehe…$"

MaguroHarbor_House1_EventScript_PokedexRiddler_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_FAT_GUY EMOTE_NORMAL}Hehe… Hullo, kid…\n"
	.string "They call me the Pokémon Nerd.\p"
	.string "(They're just jealous…)\p"
	.string "I know a whole lot about Pokémon…\n"
	.string "Wanna play a game?\p"
	.string "Guess what Pokémon I'm describing,\n"
	.string "and I'll share my knowledge with you.\p"
	.string "Hehe… Think you can solve my riddle?\n"
	.string "Ahem…$"

MaguroHarbor_House1_EventScript_PokedexRiddler_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_FAT_GUY EMOTE_NORMAL}Well? What Pokémon am I talking about?$"

MaguroHarbor_House1_EventScript_PokedexRiddler_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_FAT_GUY EMOTE_NORMAL}Woah, you… You solved my riddle!\p"
	.string "Could you… be a true Pokémon Nerd?\p"
	.string "You have bested me today. Feel the\n"
	.string "rush of pure knowledge coursing\l"
	.string "through your veins?\p"
	.string "Your Pokémon… They will gain more\n"
	.string "experience today.\p"
	.string "Knowledge is power, after all, hehe…\p"
	.string "Come back another time for another\n"
	.string "riddle…$"

MaguroHarbor_House1_EventScript_PokedexRiddler_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_SEASIDE_FAT_GUY EMOTE_NORMAL}Wrong, wrong, WRONG!\n"
	.string "You are wrong!\p"
	.string "I'm honestly disappointed.\p"
	.string "Come back tomorrow, or when you've\n"
	.string "accumulated more Pokémon knowledge.$"

MaguroHarbor_House1_EventScript_Clefairy_Text_0:
	.string "Teehee!$"

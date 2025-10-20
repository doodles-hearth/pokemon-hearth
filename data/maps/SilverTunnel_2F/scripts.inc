SilverTunnel_2F_MapScripts::
	.byte 0


SilverTunnel_2F_EventScript_Tama::
	trainerbattle_double TRAINER_TAMA, SilverTunnel_2F_EventScript_Tama_Text_0, SilverTunnel_2F_EventScript_Tama_Text_1, SilverTunnel_2F_EventScript_Tama_Text_2
	setspeaker SP_NAME_GEM_MANIAC
	msgbox SilverTunnel_2F_EventScript_Tama_Text_3, MSGBOX_AUTOCLOSE
	end


SilverTunnel_2F_EventScript_Kansaku::
	trainerbattle_single TRAINER_IKUTO, SilverTunnel_2F_EventScript_Kansaku_Text_0, SilverTunnel_2F_EventScript_Kansaku_Text_1
	setspeaker SP_NAME_MINER
	setnamedmon SPECIES_ONIX
	msgbox SilverTunnel_2F_EventScript_Kansaku_Text_2, MSGBOX_AUTOCLOSE
	end


SilverTunnel_2F_EventScript_Sandslash::
	lock
	faceplayer
	setseenmon SPECIES_SANDSLASH
	playmoncry SPECIES_SANDSLASH, CRY_MODE_NORMAL
	setspeakertomonname SPECIES_SANDSLASH
	msgbox SilverTunnel_2F_EventScript_Sandslash_Text_0
	waitmoncry
	closemessage
	release
	return


SilverTunnel_2F_EventScript_Miner::
	lock
	faceplayer
	setspeaker SP_NAME_MINER
	msgbox SilverTunnel_2F_EventScript_Miner_Text_0
	closemessage
	turnobject VAR_LAST_TALKED, DIR_WEST
	setnamedmon SPECIES_SANDSLASH
	setseenmon SPECIES_SANDSLASH
	playmoncry SPECIES_SANDSLASH, CRY_MODE_NORMAL
	applymovement 5, SilverTunnel_2F_EventScript_Miner_Movement_0
	waitmoncry
	waitmovement 0
	setdescribedmon SPECIES_SANDSLASH
	release
	return


SilverTunnel_2F_EventScript_Miner_Movement_0:
	jump_in_place_right
	step_end

SilverTunnel_2F_EventScript_Tama_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_GEM_MANIAC EMOTE_NORMAL}The lack of precious gemstones here\n"
	.string "is disappointing!$"

SilverTunnel_2F_EventScript_Tama_Text_1:
	.string "You shine like a diamond!$"

SilverTunnel_2F_EventScript_Tama_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_GEM_MANIAC EMOTE_NORMAL}My two Pokémon like to fight side by\n"
	.string "side. Come back with at least two\l"
	.string "Pokémon.$"

SilverTunnel_2F_EventScript_Tama_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_GEM_MANIAC EMOTE_NORMAL} I came all the way from Saberside\n"
	.string "Town looking for precious gemstones.\l"
	.string "But there's only sad, grey rocks here…$"

SilverTunnel_2F_EventScript_Kansaku_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_MINER EMOTE_NORMAL}You scared me! I'll break your head!$"

SilverTunnel_2F_EventScript_Kansaku_Text_1:
	.string "What a headache!$"

SilverTunnel_2F_EventScript_Kansaku_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_MINER EMOTE_NORMAL}Onix is the best!\n"
	.string "Sure, she causes cave-ins sometimes,\l"
	.string "but that's not important!$"

SilverTunnel_2F_EventScript_Sandslash_Text_0:
	.string "Sahaaah!$"

SilverTunnel_2F_EventScript_Miner_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_MINER EMOTE_NORMAL} Sandslash is such a good partner for\n"
	.string "Miners!\p"
	.string "It curls into a ball and rolls into\n"
	.string "walls to break 'em, then it burrows in\l"
	.string "there with its claws.\p"
	.string "Ain't that right, Sandy?$"

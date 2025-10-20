SilverTunnel_1F_MapScripts::
	.byte 0


SilverTunnel_1F_EventScript_Kento::
	trainerbattle_single TRAINER_KENTO, SilverTunnel_1F_EventScript_Kento_Text_0, SilverTunnel_1F_EventScript_Kento_Text_1
	setnamedmon SPECIES_MAKUHITA
	setspeaker SP_NAME_MINER
	msgbox SilverTunnel_1F_EventScript_Kento_Text_2, MSGBOX_AUTOCLOSE
	end


SilverTunnel_1F_EventScript_Shuya::
	trainerbattle_single TRAINER_SHUYA, SilverTunnel_1F_EventScript_Shuya_Text_0, SilverTunnel_1F_EventScript_Shuya_Text_1
	setnamedmon SPECIES_MAKUHITA
	setspeaker SP_NAME_MINER
	msgbox SilverTunnel_1F_EventScript_Shuya_Text_2, MSGBOX_AUTOCLOSE
	end


SilverTunnel_1F_EventScript_Yoru::
	trainerbattle_single TRAINER_YORU, SilverTunnel_1F_EventScript_Yoru_Text_0, SilverTunnel_1F_EventScript_Yoru_Text_1
	setspeaker SP_NAME_HEX_MANIAC
	msgbox SilverTunnel_1F_EventScript_Yoru_Text_2, MSGBOX_AUTOCLOSE
	end


SilverTunnel_1F_EventScript_Nerd::
	setspeaker SP_NAME_MAN
	msgbox SilverTunnel_1F_EventScript_Nerd_Text_0, MSGBOX_NPC
	return


SilverTunnel_1F_TrainerTips::
	msgbox SilverTunnel_1F_TrainerTips_Text_0, MSGBOX_SIGN
	return


SilverTunnel_1F_EventScript_Kento_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_MINER EMOTE_NORMAL}You ain't no miner, are ya?$"

SilverTunnel_1F_EventScript_Kento_Text_1:
	.string "How am I gonna get any work done now?$"

SilverTunnel_1F_EventScript_Kento_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_MINER EMOTE_NORMAL}My Makuhita breaks rocks for me!$"

SilverTunnel_1F_EventScript_Shuya_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_MINER EMOTE_NORMAL}D'ya know how tough we miners are?$"

SilverTunnel_1F_EventScript_Shuya_Text_1:
	.string "I gotta say, yer not bad either!$"

SilverTunnel_1F_EventScript_Shuya_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_MINER EMOTE_NORMAL}Sometimes we armwrestle with our\n"
	.string "Makuhita just for kicks!$"

SilverTunnel_1F_EventScript_Yoru_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_HEX_MANIAC EMOTE_NORMAL}This place sucks!$"

SilverTunnel_1F_EventScript_Yoru_Text_1:
	.string "This battle sucked as well!$"

SilverTunnel_1F_EventScript_Yoru_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_HEX_MANIAC EMOTE_NORMAL}I thought caves were spooky places\n"
	.string "with lots of Ghost Pokémon…\p"
	.string "All I see are dumb rocks and bats!$"

SilverTunnel_1F_EventScript_Nerd_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_FAT_GUY EMOTE_NORMAL}Ugh…\p"
	.string "I forgot to bring my fighting\n"
	.string "Pokémon, so I got whooped by those\l"
	.string "miners' rock Pokémon…$"

SilverTunnel_1F_TrainerTips_Text_0:
	.string "Warning!\p"
	.string "Wild Pokémon burrow in the sand!\p"
	.string "Cross at your own risk!$"

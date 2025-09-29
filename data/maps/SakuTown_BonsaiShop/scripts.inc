SakuTown_BonsaiShop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SakuTown_EventScript_SetupNpcs
	.byte 0


SakuTown_EventScript_SetupNpcs::
	goto_if_unset FLAG_HIDE_BONSAI_SHOP_OWNER, SakuTown_EventScript_SetupNpcs_1
	return

SakuTown_EventScript_SetupNpcs_1:
	setobjectmovementtype 1, MOVEMENT_TYPE_WANDER_AROUND
	setobjectxyperm 1, 9, 3
	return


SakuTown_BonsaiShop_EventScript_ClayPots::
	msgbox SakuTown_BonsaiShop_EventScript_ClayPots_Text_0, MSGBOX_AUTOCLOSE
	return


SakuTown_BonsaiShop_EventScript_Bonsai::
	msgbox SakuTown_BonsaiShop_EventScript_Bonsai_Text_0, MSGBOX_AUTOCLOSE
	return


SakuTown_BonsaiShop_EventScript_Water::
	msgbox SakuTown_BonsaiShop_EventScript_Water_Text_0, MSGBOX_AUTOCLOSE
	return


SakuTown_BonsaiShop_EventScript_FlowerBasket::
	msgbox SakuTown_BonsaiShop_EventScript_FlowerBasket_Text_0, MSGBOX_AUTOCLOSE
	return


SakuTown_BonsaiShop_EventScript_WateringCan::
	goto_if_set FLAG_RECEIVED_WAILMER_PAIL, SakuTown_BonsaiShop_EventScript_WateringCan_1
	msgbox SakuTown_BonsaiShop_EventScript_WateringCan_Text_1, MSGBOX_AUTOCLOSE
	return

SakuTown_BonsaiShop_EventScript_WateringCan_1:
	msgbox SakuTown_BonsaiShop_EventScript_WateringCan_Text_0, MSGBOX_AUTOCLOSE
	return


SakuTown_BonsaiShop_EventScript_Painting::
	msgbox SakuTown_BonsaiShop_EventScript_Painting_Text_0, MSGBOX_AUTOCLOSE
	return


SakuTown_BonsaiShop_EventScript_LittleSisterGiveBerry::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY, SakuTown_BonsaiShop_EventScript_LittleSisterGiveBerry_2
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox SakuTown_BonsaiShop_EventScript_LittleSisterGiveBerry_Text_1
	closemessage
	random 8
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	setflag FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox SakuTown_BonsaiShop_EventScript_LittleSisterGiveBerry_Text_2
	closemessage
SakuTown_BonsaiShop_EventScript_LittleSisterGiveBerry_1:
	release
	return

SakuTown_BonsaiShop_EventScript_LittleSisterGiveBerry_2:
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox SakuTown_BonsaiShop_EventScript_LittleSisterGiveBerry_Text_0
	closemessage
	goto SakuTown_BonsaiShop_EventScript_LittleSisterGiveBerry_1


SakuTown_BonsaiShop_EventScript_LittleSister::
	lock
	faceplayer
	getgamestat GAME_STAT_PLANTED_BERRIES
	goto_if_set FLAG_RECEIVED_TM_ACROBATICS, SakuTown_BonsaiShop_EventScript_LittleSister_2
	special GetPlayerMrMrsString
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_1
	compare VAR_RESULT, 10
	goto_if_lt SakuTown_BonsaiShop_EventScript_LittleSister_5
	compare VAR_RESULT, 20
	goto_if_lt SakuTown_BonsaiShop_EventScript_LittleSister_6
	compare VAR_RESULT, 30
	goto_if_lt SakuTown_BonsaiShop_EventScript_LittleSister_7
	compare VAR_RESULT, 40
	goto_if_lt SakuTown_BonsaiShop_EventScript_LittleSister_8
	compare VAR_RESULT, 40
	goto_if_ge SakuTown_BonsaiShop_EventScript_LittleSister_9
SakuTown_BonsaiShop_EventScript_LittleSister_1:
	release
	return

SakuTown_BonsaiShop_EventScript_LittleSister_2:
	buffernumberstring STR_VAR_2, VAR_RESULT
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_0
	goto SakuTown_BonsaiShop_EventScript_LittleSister_1

SakuTown_BonsaiShop_EventScript_LittleSister_5:
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_2
	closemessage
	goto SakuTown_BonsaiShop_EventScript_LittleSister_1

SakuTown_BonsaiShop_EventScript_LittleSister_6:
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_3
	closemessage
	goto SakuTown_BonsaiShop_EventScript_LittleSister_1

SakuTown_BonsaiShop_EventScript_LittleSister_7:
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_4
	closemessage
	goto SakuTown_BonsaiShop_EventScript_LittleSister_1

SakuTown_BonsaiShop_EventScript_LittleSister_8:
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_5
	closemessage
	goto SakuTown_BonsaiShop_EventScript_LittleSister_1

SakuTown_BonsaiShop_EventScript_LittleSister_9:
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_6
	closemessage
	giveitem ITEM_TM_ACROBATICS
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	setspeaker SP_NAME_LITTLE_GIRL
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_7
	closemessage
	setflag FLAG_RECEIVED_TM_ACROBATICS
	goto SakuTown_BonsaiShop_EventScript_LittleSister_1


SakuTown_BonsaiShop_EventScript_Assistant::
	lock
	faceplayer
	compare VAR_BONSAI_SHOP_STATE, 1
	goto_if_eq SakuTown_BonsaiShop_EventScript_Assistant_2
	goto_if_set FLAG_RECEIVED_WAILMER_PAIL, SakuTown_BonsaiShop_EventScript_Assistant_9
	setspeaker SP_NAME_WOMAN
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_4
	closemessage
	giveitem ITEM_ORAN_BERRY, 3
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setspeaker SP_NAME_WOMAN
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_5
	closemessage
	giveitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setspeaker SP_NAME_WOMAN
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_6
	setflag FLAG_RECEIVED_WAILMER_PAIL
SakuTown_BonsaiShop_EventScript_Assistant_8:
	setvar VAR_BONSAI_SHOP_STATE, 1
SakuTown_BonsaiShop_EventScript_Assistant_1:
	release
	return

SakuTown_BonsaiShop_EventScript_Assistant_2:
	goto_if_set FLAG_HIDE_BONSAI_SHOP_OWNER, SakuTown_BonsaiShop_EventScript_Assistant_5
	setspeaker SP_NAME_WOMAN
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_1
	closemessage
	goto SakuTown_BonsaiShop_EventScript_Assistant_1

SakuTown_BonsaiShop_EventScript_Assistant_5:
	setspeaker SP_NAME_WOMAN
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_0
	closemessage
	goto SakuTown_BonsaiShop_EventScript_Assistant_1

SakuTown_BonsaiShop_EventScript_Assistant_9:
	setspeaker SP_NAME_WOMAN
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_2
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	setspeaker SP_NAME_WOMAN
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_3
	closemessage
	goto SakuTown_BonsaiShop_EventScript_Assistant_8


SakuTown_BonsaiShop_EventScript_Owner_RegularDialogue:
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SakuTown_BonsaiShop_EventScript_Owner_RegularDialogue_1
	setspeaker SP_NAME_HANA
	msgbox SakuTown_BonsaiShop_EventScript_Owner_RegularDialogue_Text_2
	closemessage
	return

SakuTown_BonsaiShop_EventScript_Owner_RegularDialogue_1:
	setspeaker SP_NAME_HANA
	msgbox SakuTown_BonsaiShop_EventScript_Owner_RegularDialogue_Text_0
	closemessage
	pokemartdecoration BonsaiShop
	setspeaker SP_NAME_HANA
	msgbox SakuTown_BonsaiShop_EventScript_Owner_RegularDialogue_Text_1, MSGBOX_DEFAULT
	closemessage
	return


SakuTown_BonsaiShop_EventScript_Owner_DiscoverGymLeader:
	setflag FLAG_MET_HANA_BONSAI_SHOP
	setspeaker SP_NAME_HANA
	msgbox SakuTown_BonsaiShop_EventScript_Owner_DiscoverGymLeader_Text_0
	mcdialogue SakuTown_BonsaiShop_EventScript_Owner_DiscoverGymLeader_Text_1
	closemessage
	setspeaker SP_NAME_HANA
	msgbox SakuTown_BonsaiShop_EventScript_Owner_DiscoverGymLeader_Text_2
	closemessage
	return


SakuTown_BonsaiShop_EventScript_Owner::
	lock
	faceplayer
	goto_if_unset FLAG_MET_HANA_GYM, SakuTown_BonsaiShop_EventScript_Owner_2
	goto_if_set FLAG_MET_HANA_BONSAI_SHOP, SakuTown_BonsaiShop_EventScript_Owner_5
	call SakuTown_BonsaiShop_EventScript_Owner_DiscoverGymLeader
SakuTown_BonsaiShop_EventScript_Owner_1:
	release
	return

SakuTown_BonsaiShop_EventScript_Owner_2:
	setflag FLAG_MET_HANA_BONSAI_SHOP
	special GetPlayerBoyGirlString
	setspeaker SP_NAME_SHOP_OWNER
	msgbox SakuTown_BonsaiShop_EventScript_Owner_Text_0
	closemessage
	goto SakuTown_BonsaiShop_EventScript_Owner_1

SakuTown_BonsaiShop_EventScript_Owner_5:
	call SakuTown_BonsaiShop_EventScript_Owner_RegularDialogue
	goto SakuTown_BonsaiShop_EventScript_Owner_1


	.align 2
BonsaiShop:
	.2byte DECOR_RED_PLANT
	.2byte DECOR_BIG_PLANT
	.2byte DECOR_GORGEOUS_PLANT
	.2byte ITEM_NONE

SakuTown_EventScript_Man::
	lock
	faceplayer
	setspeaker SP_NAME_CUSTOMER
	msgbox SakuTown_EventScript_Man_Text_0
	closemessage
	release
	return


SakuTown_BonsaiShop_EventScript_ClayPots_Text_0:
	.string "Some clay pots, neatly stacked.$"

SakuTown_BonsaiShop_EventScript_Bonsai_Text_0:
	.string "It's a bonsai. It has obviously been\n"
	.string "nurtured with love.$"

SakuTown_BonsaiShop_EventScript_Water_Text_0:
	.string "It's filled to the brim with rainwater.$"

SakuTown_BonsaiShop_EventScript_FlowerBasket_Text_0:
	.string "A small basket of freshly picked\n"
	.string "flowers.$"

SakuTown_BonsaiShop_EventScript_WateringCan_Text_0:
	.string "A cute Wailmer-shaped watering can.\n"
	.string "You have one exactly like it!$"

SakuTown_BonsaiShop_EventScript_WateringCan_Text_1:
	.string "A cute Wailmer-shaped watering can.$"

SakuTown_BonsaiShop_EventScript_Painting_Text_0:
	.string "A dainty painting of a flower.$"

SakuTown_BonsaiShop_EventScript_LittleSisterGiveBerry_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_LITTLE_GIRL EMOTE_NORMAL}Go plant the berry I gave you!$"

SakuTown_BonsaiShop_EventScript_LittleSisterGiveBerry_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_LITTLE_GIRL EMOTE_NORMAL}Have you met my twin sister?\n"
	.string "Very “Type A”, right?\p"
	.string "You should try beating her at her own\n"
	.string "game!\p"
	.string "Here, start by planting this!$"

SakuTown_BonsaiShop_EventScript_LittleSisterGiveBerry_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_LITTLE_GIRL EMOTE_NORMAL}Go for them berries!\n"
	.string "Eyes on the prize!$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_LITTLE_GIRL EMOTE_NORMAL}What's up, berry master?\p"
	.string "Didja know you've planted\n"
	.string "{STR_VAR_2} berries so far?$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_LITTLE_GIRL EMOTE_NORMAL}Hi there {STR_VAR_1} Grownup!\p"
	.string "Have you planted many berries on your\n"
	.string "travels?$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_LITTLE_GIRL EMOTE_NORMAL}Hmm…\p"
	.string "Your face still has “berry amateur”\n"
	.string "written all over it.\p"
	.string "Come back when you're less of an\n"
	.string "embarrassment.$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_LITTLE_GIRL EMOTE_NORMAL}Hmm…\p"
	.string "I'd say it's less terrible than before.\p"
	.string "Still not great though. You need to\n"
	.string "plant way more berries.$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_LITTLE_GIRL EMOTE_NORMAL}Hmm…\p"
	.string "Hey, I'm actually impressed at the\n"
	.string "berry skills I'm sensing!\p"
	.string "… … Kidding!\p"
	.string "You're getting better at it though.$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_5:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_LITTLE_GIRL EMOTE_NORMAL}Hmm…\p"
	.string "I'd say you're almost there…\p"
	.string "There's a fine line between being\n"
	.string "“almost good” at berries, and being\l"
	.string "“actually good” at berries.\p"
	.string "So, you know, keep it up, or whatever.$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_6:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_LITTLE_GIRL EMOTE_NORMAL}Hmm…\p"
	.string "Oh?\p"
	.string "Now that's what I'm talking about!\p"
	.string "Congrats, {STR_VAR_1} Grownup. By\n"
	.string "achieving berry mastery, you have\l"
	.string "earned my respect.\p"
	.string "Take this!$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_7:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_LITTLE_GIRL EMOTE_NORMAL}This scroll contains Acrobatics.\p"
	.string "Your Pokémon will strike harder if he\n"
	.string "isn't holding an item.\p"
	.string "Good match for a Pokémon holding a\n"
	.string "berry, right?\p"
	.string "First eat a little snack, then\n"
	.string "mercilessly crush your opponent!$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_AROMA_LADY EMOTE_NORMAL}Hi, {PLAYER}!\p"
	.string "The shop owner is currently away.\n"
	.string "She's very busy.\p"
	.string "Busy with what, you ask?\p"
	.string "Um, I'm actually not sure.$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_AROMA_LADY EMOTE_NORMAL}Hi, {PLAYER}! Don't mind my sisters.\n"
	.string "They're quite the handful!$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_AROMA_LADY EMOTE_NORMAL}Hello, welcome to our bonsai shop…$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_3:
	.string "{CREATE_MUGSHOT MUGSHOT_AROMA_LADY EMOTE_NORMAL}Oh, but I know you! We met on Tranquil\n"
	.string "route, remember?\p"
	.string "Have you used the watering can I gave\n"
	.string "you yet?\p"
	.string "Oh, yes, I work here. We sell bonsai\n"
	.string "and other potted flowers!\p"
	.string "I'm the owner's assistant! I also\n"
	.string "manage the shop whenever she's away.$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_4:
	.string "{CREATE_MUGSHOT MUGSHOT_AROMA_LADY EMOTE_NORMAL}Hello, welcome to our bonsai shop! I'm\n"
	.string "the owner's assistant.\p"
	.string "We sell bonsai and other potted\n"
	.string "flowers! Are you interested in\l"
	.string "plants?\p"
	.string "Have you ever seen strange patches\n"
	.string "of soil while on your journey?\p"
	.string "Those soil patches are incredibly\n"
	.string "fertile, which means any berry you\l"
	.string "plant in that soil will thrive and grow\l"
	.string "into a tree, ready to be harvested!\p"
	.string "I see you're a Wielder. Well, different\n"
	.string "berries have different effects when\l"
	.string "they're fed to Pokémon.\p"
	.string "I love berries, hopefully you'll soon\n"
	.string "learn to love them too!\p"
	.string "Here, try planting a few!$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_5:
	.string "{CREATE_MUGSHOT MUGSHOT_AROMA_LADY EMOTE_NORMAL}Oh, right, I was almost forgetting!\p"
	.string "You must remember to water them\n"
	.string "regularly, or they won't grow!\p"
	.string "I like you. Take this!$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_6:
	.string "{CREATE_MUGSHOT MUGSHOT_AROMA_LADY EMOTE_NORMAL}Isn't it cute? It's friend-shaped!\p"
	.string "Don't worry about it, I have a spare\n"
	.string "one.\p"
	.string "Have fun gardening!$"

SakuTown_BonsaiShop_EventScript_Owner_RegularDialogue_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_HANA EMOTE_NORMAL}Hello, {PLAYER}. Can I interest you\n"
	.string "in a little greenery?$"

SakuTown_BonsaiShop_EventScript_Owner_RegularDialogue_Text_1:
	.string "{CREATE_MUGSHOT MUGSHOT_HANA EMOTE_NORMAL}Thank you for your business!$"

SakuTown_BonsaiShop_EventScript_Owner_RegularDialogue_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_HANA EMOTE_NORMAL}Hello, {PLAYER}. Can I interest you\n"
	.string "in a little greenery?\p"
	.string "Hmm… It looks like you wouldn't have\n"
	.string "anywhere to put bonsai. Come back\l"
	.string "when you do.$"

SakuTown_BonsaiShop_EventScript_Owner_DiscoverGymLeader_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_HANA EMOTE_NORMAL}Hello, young {STR_VAR_1}. Can I\n"
	.string "interest you in a little greenery?$"

SakuTown_BonsaiShop_EventScript_Owner_DiscoverGymLeader_Text_1:
	.string "Hana?"
	.string "Have we met?$"

SakuTown_BonsaiShop_EventScript_Owner_DiscoverGymLeader_Text_2:
	.string "{CREATE_MUGSHOT MUGSHOT_HANA EMOTE_NORMAL}Ho ho, I have been discovered…\p"
	.string "You must be wondering what the Kura\n"
	.string "Village Dojo Master is doing in a\l"
	.string "Bonsai shop in Saku Village.\p"
	.string "I'd prefer you don't tell anyone.\n"
	.string "See, the two towns have a beef with\l"
	.string "one another.\p"
	.string "This senseless enmity pains me.\n"
	.string "I wish something could be done.\p"
	.string "If only the villagers saw they are\n"
	.string "more similar than they are different…$"

SakuTown_BonsaiShop_EventScript_Owner_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_HANA EMOTE_NORMAL}Hello, young {STR_VAR_1}. Can I\n"
	.string "interest you in a little greenery?\p"
	.string "Hmm… It looks like you wouldn't have\n"
	.string "anywhere to put bonsai. Come back\l"
	.string "when you do.$"

SakuTown_EventScript_Man_Text_0:
	.string "{CREATE_MUGSHOT MUGSHOT_SAKURA_MAN_2 EMOTE_NORMAL}I'm choosing flowers for my wife.\p"
	.string "I, uh… I didn't realize there'd be so\n"
	.string "many different types.\p"
	.string "Guess I'll be here a while…$"

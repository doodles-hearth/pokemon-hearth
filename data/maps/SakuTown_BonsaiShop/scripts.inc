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


SakuTown_BonsaiShop_EventScript_LittleSister::
	lock
	faceplayer
	getgamestat GAME_STAT_PLANTED_BERRIES
	goto_if_set FLAG_RECEIVED_TM_ACROBATICS, SakuTown_BonsaiShop_EventScript_LittleSister_2
	special GetPlayerMrMrsString
	speakername SakuTown_BonsaiShop_EventScript_LittleSister_Text_0
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_2
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
	speakername SakuTown_BonsaiShop_EventScript_LittleSister_Text_0
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_1
	goto SakuTown_BonsaiShop_EventScript_LittleSister_1

SakuTown_BonsaiShop_EventScript_LittleSister_5:
	speakername SakuTown_BonsaiShop_EventScript_LittleSister_Text_0
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_3
	closemessage
	goto SakuTown_BonsaiShop_EventScript_LittleSister_1

SakuTown_BonsaiShop_EventScript_LittleSister_6:
	speakername SakuTown_BonsaiShop_EventScript_LittleSister_Text_0
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_4
	closemessage
	goto SakuTown_BonsaiShop_EventScript_LittleSister_1

SakuTown_BonsaiShop_EventScript_LittleSister_7:
	speakername SakuTown_BonsaiShop_EventScript_LittleSister_Text_0
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_5
	closemessage
	goto SakuTown_BonsaiShop_EventScript_LittleSister_1

SakuTown_BonsaiShop_EventScript_LittleSister_8:
	speakername SakuTown_BonsaiShop_EventScript_LittleSister_Text_0
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_6
	closemessage
	goto SakuTown_BonsaiShop_EventScript_LittleSister_1

SakuTown_BonsaiShop_EventScript_LittleSister_9:
	speakername SakuTown_BonsaiShop_EventScript_LittleSister_Text_0
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_7
	closemessage
	giveitem ITEM_TM_ACROBATICS
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	speakername SakuTown_BonsaiShop_EventScript_LittleSister_Text_0
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_8
	closemessage
	setflag FLAG_RECEIVED_TM_ACROBATICS
	goto SakuTown_BonsaiShop_EventScript_LittleSister_1


SakuTown_BonsaiShop_EventScript_Assistant::
	lock
	faceplayer
	compare VAR_BONSAI_SHOP_STATE, 1
	goto_if_eq SakuTown_BonsaiShop_EventScript_Assistant_2
	goto_if_set FLAG_RECEIVED_WAILMER_PAIL, SakuTown_BonsaiShop_EventScript_Assistant_9
	speakername SakuTown_BonsaiShop_EventScript_Assistant_Text_0
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_5
	closemessage
	giveitem ITEM_ORAN_BERRY, 3
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	speakername SakuTown_BonsaiShop_EventScript_Assistant_Text_0
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_6
	closemessage
	giveitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	speakername SakuTown_BonsaiShop_EventScript_Assistant_Text_0
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_7
	setflag FLAG_RECEIVED_WAILMER_PAIL
SakuTown_BonsaiShop_EventScript_Assistant_8:
	setvar VAR_BONSAI_SHOP_STATE, 1
SakuTown_BonsaiShop_EventScript_Assistant_1:
	release
	return

SakuTown_BonsaiShop_EventScript_Assistant_2:
	goto_if_set FLAG_HIDE_BONSAI_SHOP_OWNER, SakuTown_BonsaiShop_EventScript_Assistant_5
	speakername SakuTown_BonsaiShop_EventScript_Assistant_Text_0
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_2
	closemessage
	goto SakuTown_BonsaiShop_EventScript_Assistant_1

SakuTown_BonsaiShop_EventScript_Assistant_5:
	speakername SakuTown_BonsaiShop_EventScript_Assistant_Text_0
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_1
	closemessage
	goto SakuTown_BonsaiShop_EventScript_Assistant_1

SakuTown_BonsaiShop_EventScript_Assistant_9:
	speakername SakuTown_BonsaiShop_EventScript_Assistant_Text_0
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_3
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	speakername SakuTown_BonsaiShop_EventScript_Assistant_Text_0
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_4
	closemessage
	goto SakuTown_BonsaiShop_EventScript_Assistant_8


SakuTown_BonsaiShop_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_BADGE02_GET, SakuTown_BonsaiShop_EventScript_Owner_2
	special GetPlayerBoyGirlString
	speakername SakuTown_BonsaiShop_EventScript_Owner_Text_4
	msgbox SakuTown_BonsaiShop_EventScript_Owner_Text_5
	closemessage
SakuTown_BonsaiShop_EventScript_Owner_1:
	release
	return

SakuTown_BonsaiShop_EventScript_Owner_2:
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SakuTown_BonsaiShop_EventScript_Owner_5
	speakername SakuTown_BonsaiShop_EventScript_Owner_Text_0
	msgbox SakuTown_BonsaiShop_EventScript_Owner_Text_3
	closemessage
	goto SakuTown_BonsaiShop_EventScript_Owner_1

SakuTown_BonsaiShop_EventScript_Owner_5:
	speakername SakuTown_BonsaiShop_EventScript_Owner_Text_0
	msgbox SakuTown_BonsaiShop_EventScript_Owner_Text_1
	closemessage
	pokemartdecoration BonsaiShop
	speakername SakuTown_BonsaiShop_EventScript_Owner_Text_0
	msgbox SakuTown_BonsaiShop_EventScript_Owner_Text_2, MSGBOX_DEFAULT
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
	speakername SakuTown_EventScript_Man_Text_0
	msgbox SakuTown_EventScript_Man_Text_1
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

SakuTown_BonsaiShop_EventScript_LittleSister_Text_0:
	.string "Little Girl$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_1:
	.string "What's up, berry master?\p"
	.string "Didja know you've planted\n"
	.string "{STR_VAR_2} berries so far?$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_2:
	.string "Hi there {STR_VAR_1} Grownup!\p"
	.string "Have you planted many berries on your\n"
	.string "travels?$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_3:
	.string "Hmm…\p"
	.string "Your face still has “berry amateur”\n"
	.string "written all over it.\p"
	.string "Come back when you're less of an\n"
	.string "embarrassment.$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_4:
	.string "Hmm…\p"
	.string "I'd say it's less terrible than before.\p"
	.string "Still not great though. You need to\n"
	.string "plant way more berries.$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_5:
	.string "Hmm…\p"
	.string "Hey, I'm actually impressed at the\n"
	.string "berry skills I'm sensing!\p"
	.string "… … Kidding!\p"
	.string "You're getting better at it though.$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_6:
	.string "Hmm…\p"
	.string "I'd say you're almost there…\p"
	.string "There's a fine line between being\n"
	.string "“almost good” at berries, and being\l"
	.string "“actually good” at berries.\p"
	.string "So, you know, keep it up, or whatever.$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_7:
	.string "Hmm…\p"
	.string "Oh?\p"
	.string "Now that's what I'm talking about!\p"
	.string "Congrats, {STR_VAR_1} Grownup. By\n"
	.string "achieving berry mastery, you have\l"
	.string "earned my respect.\p"
	.string "Take this!$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_8:
	.string "This scroll contains Acrobatics.\p"
	.string "Your Pokémon will strike harder if he\n"
	.string "isn't holding an item.\p"
	.string "Good match for a Pokémon holding a\n"
	.string "berry, right?\p"
	.string "First eat a little snack, then\n"
	.string "mercilessly crush your opponent!$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_0:
	.string "Woman$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_1:
	.string "Hi, {PLAYER}!\p"
	.string "The shop owner is currently away.\n"
	.string "She's very busy.\p"
	.string "Busy with what, you ask?\p"
	.string "Um, I'm actually not sure.$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_2:
	.string "Hi, {PLAYER}! Don't mind my sister.\n"
	.string "She's not as nice as she looks!$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_3:
	.string "Hello, welcome to our bonsai shop…$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_4:
	.string "Oh, but I know you! We met on Tranquil\n"
	.string "route, remember?\p"
	.string "Have you used the watering can I gave\n"
	.string "you yet?\p"
	.string "Oh, yes, I work here. We sell bonsai\n"
	.string "and other potted flowers!\p"
	.string "I'm the owner's assistant! I also\n"
	.string "manage the shop whenever she's away.$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_5:
	.string "Hello, welcome to our bonsai shop! I'm\n"
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
	.string "I see you're a wielder. Well, different\n"
	.string "berries have different effects when\l"
	.string "they're fed to Pokémon.\p"
	.string "I love berries, hopefully you'll soon\n"
	.string "learn to love them too!\p"
	.string "Here, try planting a few!$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_6:
	.string "Oh, right, I was almost forgetting!\p"
	.string "You must remember to water them\n"
	.string "regularly, or they won't grow!\p"
	.string "I like you. Take this!$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_7:
	.string "Isn't it cute? It's friend-shaped!\p"
	.string "Don't worry about it, I have a spare\n"
	.string "one.\p"
	.string "Have fun gardening!$"

SakuTown_BonsaiShop_EventScript_Owner_Text_0:
	.string "Hana$"

SakuTown_BonsaiShop_EventScript_Owner_Text_1:
	.string "Hello, {PLAYER}. Can I interest you\n"
	.string "in a little greenery?$"

SakuTown_BonsaiShop_EventScript_Owner_Text_2:
	.string "Thank you for your business!$"

SakuTown_BonsaiShop_EventScript_Owner_Text_3:
	.string "Hello, {PLAYER}. Can I interest you\n"
	.string "in a little greenery?\p"
	.string "Hmm… It looks like you wouldn't have\n"
	.string "anywhere to put bonsai. Come back\l"
	.string "when you do.$"

SakuTown_BonsaiShop_EventScript_Owner_Text_4:
	.string "Shop Owner$"

SakuTown_BonsaiShop_EventScript_Owner_Text_5:
	.string "Hello, young {STR_VAR_1}. Can I\n"
	.string "interest you in a little greenery?\p"
	.string "Hmm… It looks like you wouldn't have\n"
	.string "anywhere to put bonsai. Come back\l"
	.string "when you do.$"

SakuTown_EventScript_Man_Text_0:
	.string "Customer$"

SakuTown_EventScript_Man_Text_1:
	.string "I'm choosing flowers for my wife.\p"
	.string "I, uh… I didn't realize there'd be so\n"
	.string "many different types.\p"
	.string "Guess I'll be here for a while…$"

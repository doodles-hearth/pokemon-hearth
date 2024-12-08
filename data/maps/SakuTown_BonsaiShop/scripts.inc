SakuTown_BonsaiShop_MapScripts::
# 4 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SakuTown_EventScript_SetupNpcs
	.byte 0


SakuTown_EventScript_SetupNpcs::
# 9 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	goto_if_unset FLAG_HIDE_BONSAI_SHOP_OWNER, SakuTown_EventScript_SetupNpcs_1
	return

SakuTown_EventScript_SetupNpcs_1:
# 10 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_WANDER_AROUND
# 11 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	setobjectxyperm 1, 9, 3
	return


SakuTown_BonsaiShop_EventScript_ClayPots::
# 16 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_ClayPots_Text_0, MSGBOX_AUTOCLOSE
	return


SakuTown_BonsaiShop_EventScript_Bonsai::
# 22 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_Bonsai_Text_0, MSGBOX_AUTOCLOSE
	return


SakuTown_BonsaiShop_EventScript_Water::
# 28 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_Water_Text_0, MSGBOX_AUTOCLOSE
	return


SakuTown_BonsaiShop_EventScript_FlowerBasket::
# 34 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_FlowerBasket_Text_0, MSGBOX_AUTOCLOSE
	return


SakuTown_BonsaiShop_EventScript_WateringCan::
# 40 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	goto_if_set FLAG_RECEIVED_WAILMER_PAIL, SakuTown_BonsaiShop_EventScript_WateringCan_1
# 45 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_WateringCan_Text_1, MSGBOX_AUTOCLOSE
	return

SakuTown_BonsaiShop_EventScript_WateringCan_1:
# 41 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_WateringCan_Text_0, MSGBOX_AUTOCLOSE
	return


SakuTown_BonsaiShop_EventScript_Painting::
# 52 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_Painting_Text_0, MSGBOX_AUTOCLOSE
	return


SakuTown_BonsaiShop_EventScript_LittleSister::
# 58 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	lock
# 59 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	faceplayer
# 61 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	getgamestat GAME_STAT_PLANTED_BERRIES
# 63 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_ACROBATICS, SakuTown_BonsaiShop_EventScript_LittleSister_2
# 70 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	special GetPlayerMrMrsString
# 71 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_1
# 75 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	compare VAR_RESULT, 10
	goto_if_lt SakuTown_BonsaiShop_EventScript_LittleSister_5
# 82 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	compare VAR_RESULT, 20
	goto_if_lt SakuTown_BonsaiShop_EventScript_LittleSister_6
# 89 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	compare VAR_RESULT, 30
	goto_if_lt SakuTown_BonsaiShop_EventScript_LittleSister_7
# 98 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	compare VAR_RESULT, 40
	goto_if_lt SakuTown_BonsaiShop_EventScript_LittleSister_8
# 106 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	compare VAR_RESULT, 40
	goto_if_ge SakuTown_BonsaiShop_EventScript_LittleSister_9
SakuTown_BonsaiShop_EventScript_LittleSister_1:
# 131 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	release
	return

SakuTown_BonsaiShop_EventScript_LittleSister_2:
# 64 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_RESULT
# 65 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_0
	goto SakuTown_BonsaiShop_EventScript_LittleSister_1

SakuTown_BonsaiShop_EventScript_LittleSister_5:
# 76 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_2
# 81 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	closemessage
	goto SakuTown_BonsaiShop_EventScript_LittleSister_1

SakuTown_BonsaiShop_EventScript_LittleSister_6:
# 83 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_3
# 88 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	closemessage
	goto SakuTown_BonsaiShop_EventScript_LittleSister_1

SakuTown_BonsaiShop_EventScript_LittleSister_7:
# 90 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_4
# 97 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	closemessage
	goto SakuTown_BonsaiShop_EventScript_LittleSister_1

SakuTown_BonsaiShop_EventScript_LittleSister_8:
# 99 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_5
# 105 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	closemessage
	goto SakuTown_BonsaiShop_EventScript_LittleSister_1

SakuTown_BonsaiShop_EventScript_LittleSister_9:
# 107 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_6
# 114 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	closemessage
# 116 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	giveitem ITEM_TM_ACROBATICS
# 117 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 118 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_LittleSister_Text_7
# 126 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	closemessage
# 127 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	setflag FLAG_RECEIVED_TM_ACROBATICS
	goto SakuTown_BonsaiShop_EventScript_LittleSister_1


SakuTown_BonsaiShop_EventScript_Assistant::
# 135 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	lock
# 136 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	faceplayer
# 139 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	compare VAR_BONSAI_SHOP_STATE, 1
	goto_if_eq SakuTown_BonsaiShop_EventScript_Assistant_2
# 160 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	goto_if_set FLAG_RECEIVED_WAILMER_PAIL, SakuTown_BonsaiShop_EventScript_Assistant_9
# 179 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_4
# 188 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	closemessage
# 189 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	giveitem ITEM_ORAN_BERRY, 3
# 190 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 192 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_5
# 197 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	closemessage
# 198 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	giveitem ITEM_WAILMER_PAIL
# 199 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 201 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_6
# 206 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	setflag FLAG_RECEIVED_WAILMER_PAIL
SakuTown_BonsaiShop_EventScript_Assistant_8:
# 208 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	setvar VAR_BONSAI_SHOP_STATE, 1
SakuTown_BonsaiShop_EventScript_Assistant_1:
# 211 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	release
	return

SakuTown_BonsaiShop_EventScript_Assistant_2:
# 141 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	goto_if_set FLAG_HIDE_BONSAI_SHOP_OWNER, SakuTown_BonsaiShop_EventScript_Assistant_5
# 151 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_1
# 154 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	closemessage
	goto SakuTown_BonsaiShop_EventScript_Assistant_1

SakuTown_BonsaiShop_EventScript_Assistant_5:
# 142 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_0
# 148 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	closemessage
	goto SakuTown_BonsaiShop_EventScript_Assistant_1

SakuTown_BonsaiShop_EventScript_Assistant_9:
# 161 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_2
# 164 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	playse SE_PIN
# 165 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	applymovement 1, Common_Movement_ExclamationMark
# 166 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	waitmovement 0
# 167 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	applymovement 1, Common_Movement_Delay48
# 168 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	waitmovement 0
# 169 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_Assistant_Text_3
# 175 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	closemessage
	goto SakuTown_BonsaiShop_EventScript_Assistant_8


SakuTown_BonsaiShop_EventScript_Owner::
# 215 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	lock
# 216 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	faceplayer
# 217 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, SakuTown_BonsaiShop_EventScript_Owner_2
# 233 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	special GetPlayerBoyGirlString
# 234 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_Owner_Text_2
# 238 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	closemessage
SakuTown_BonsaiShop_EventScript_Owner_1:
# 240 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	release
	return

SakuTown_BonsaiShop_EventScript_Owner_2:
# 219 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SakuTown_BonsaiShop_EventScript_Owner_5
# 226 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_Owner_Text_1
# 230 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	closemessage
	goto SakuTown_BonsaiShop_EventScript_Owner_1

SakuTown_BonsaiShop_EventScript_Owner_5:
# 220 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_BonsaiShop_EventScript_Owner_Text_0
# 223 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	closemessage
	goto SakuTown_BonsaiShop_EventScript_Owner_1


SakuTown_EventScript_Man::
# 244 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	lock
# 245 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	faceplayer
# 246 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	msgbox SakuTown_EventScript_Man_Text_0
# 251 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	closemessage
# 252 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	release
	return


SakuTown_BonsaiShop_EventScript_ClayPots_Text_0:
# 17 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Some clay pots, neatly stacked.$"

SakuTown_BonsaiShop_EventScript_Bonsai_Text_0:
# 23 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "It's a bonsai. It has obviously been\n"
	.string "nurtured with love.$"

SakuTown_BonsaiShop_EventScript_Water_Text_0:
# 29 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "It's filled to the brim with rainwater.$"

SakuTown_BonsaiShop_EventScript_FlowerBasket_Text_0:
# 35 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "A small basket of freshly picked\n"
	.string "flowers.$"

SakuTown_BonsaiShop_EventScript_WateringCan_Text_0:
# 42 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "A cute Wailmer-shaped watering can.\n"
	.string "You have one exactly like it!$"

SakuTown_BonsaiShop_EventScript_WateringCan_Text_1:
# 46 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "A cute Wailmer-shaped watering can.$"

SakuTown_BonsaiShop_EventScript_Painting_Text_0:
# 53 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "A dainty painting of a flower.$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_0:
# 66 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "What's up, berry master?\p"
	.string "Didja know you've planted\n"
	.string "{STR_VAR_2} berries so far?$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_1:
# 72 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Hi there {STR_VAR_1} Grownup!\p"
	.string "Have you planted many berries on your\n"
	.string "travels?$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_2:
# 77 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Hmm…\p"
	.string "Your face still has “berry amateur”\n"
	.string "written all over it.\p"
	.string "Come back when you're less of an\n"
	.string "embarrassment.$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_3:
# 84 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Hmm…\p"
	.string "I'd say it's less terrible than before.\p"
	.string "Still not great though. You need to\n"
	.string "plant way more berries.$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_4:
# 91 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Hmm…\p"
	.string "Hey, I'm actually impressed at the\n"
	.string "berry skills I'm sensing!\p"
	.string "… … Kidding!\p"
	.string "You're getting better at it though.$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_5:
# 100 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Hmm…\p"
	.string "I'd say you're almost there…\p"
	.string "There's a fine line between being\n"
	.string "“almost good” at berries, and being\l"
	.string "“actually good” at berries.\p"
	.string "So, you know, keep it up, or whatever.$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_6:
# 108 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Hmm…\p"
	.string "Oh?\p"
	.string "Now that's what I'm talking about!\p"
	.string "Congrats, {STR_VAR_1} Grownup. By\n"
	.string "achieving berry mastery, you have\l"
	.string "earned my respect.\p"
	.string "Take this!$"

SakuTown_BonsaiShop_EventScript_LittleSister_Text_7:
# 120 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "This scroll contains Acrobatics.\p"
	.string "Your Pokémon will strike harder if he\n"
	.string "isn't holding an item.\p"
	.string "Sounds like a good match for a\n"
	.string "Pokémon holding a berry, right?\p"
	.string "First eat a little snack, then\n"
	.string "mercilessly crush your opponent!$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_0:
# 143 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Hi, {PLAYER}!\p"
	.string "The shop owner is currently away.\n"
	.string "She's very busy.\p"
	.string "Busy with what, you ask?\p"
	.string "Um, I'm actually not sure.$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_1:
# 152 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Hi, {PLAYER}! Don't mind my sister.\n"
	.string "She's not as nice as she looks!$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_2:
# 162 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Hello, welcome to our bonsai shop…$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_3:
# 170 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Oh, but I know you! We met on Tranquil\n"
	.string "route, remember?\p"
	.string "Have you used the watering can I gave\n"
	.string "you yet?\p"
	.string "Oh, yes, I work here. We sell bonsai\n"
	.string "and other potted flowers!\p"
	.string "I'm the owner's assistant! I also\n"
	.string "manage the shop whenever she's away.$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_4:
# 180 "data/maps/SakuTown_BonsaiShop/scripts.pory"
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

SakuTown_BonsaiShop_EventScript_Assistant_Text_5:
# 193 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Oh, right, I was almost forgetting!\p"
	.string "You must remember to water them\n"
	.string "regularly, or they won't grow!\p"
	.string "I like you. Take this!$"

SakuTown_BonsaiShop_EventScript_Assistant_Text_6:
# 202 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Isn't it cute? It's friend-shaped!\p"
	.string "Don't worry about it, I have a spare\n"
	.string "one.\p"
	.string "Have fun gardening!$"

SakuTown_BonsaiShop_EventScript_Owner_Text_0:
# 221 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Hello, {PLAYER}. Can I interest you\n"
	.string "in a little greenery?$"

SakuTown_BonsaiShop_EventScript_Owner_Text_1:
# 227 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Hello, {PLAYER}. Can I interest you\n"
	.string "in a little greenery?\p"
	.string "Hmm… It looks like you wouldn't have\n"
	.string "anywhere to put bonsai. Come back\l"
	.string "when you do.$"

SakuTown_BonsaiShop_EventScript_Owner_Text_2:
# 235 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "Hello, young {STR_VAR_1}. Can I\n"
	.string "interest you in a little greenery?\p"
	.string "Hmm… It looks like you wouldn't have\n"
	.string "anywhere to put bonsai. Come back\l"
	.string "when you do.$"

SakuTown_EventScript_Man_Text_0:
# 247 "data/maps/SakuTown_BonsaiShop/scripts.pory"
	.string "I'm choosing flowers for my wife.\p"
	.string "I, uh… I didn't realize there'd be so\n"
	.string "many different types.\p"
	.string "Guess I'll be here for a while…$"

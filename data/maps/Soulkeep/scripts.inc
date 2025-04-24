Soulkeep_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Soulkeep_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Soulkeep_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	callnative TrySetSoulkeepAmbiance
	return


Soulkeep_EventScript_TownSign::
	msgbox Soulkeep_EventScript_TownSign_Text_0, MSGBOX_SIGN
	return


Soulkeep_EventScript_IncenseShopSign::
	msgbox Soulkeep_EventScript_IncenseShopSign_Text_0, MSGBOX_SIGN
	return


Soulkeep_EventScript_GraveyardSign::
	msgbox Soulkeep_EventScript_GraveyardSign_Text_0, MSGBOX_SIGN
	return


Soulkeep_EventScript_Man::
	lock
	faceplayer
	speakername Soulkeep_EventScript_Man_Text_0
	msgbox Soulkeep_EventScript_Man_Text_1
	closemessage
	release
	return


Soulkeep_EventScript_Misdreavus::
	lock
	faceplayer
	setseenmon SPECIES_MISDREAVUS
	playmoncry SPECIES_MISDREAVUS, CRY_MODE_FAINT
	random 30
	compare VAR_RESULT, 4
	goto_if_eq Soulkeep_EventScript_Misdreavus_2
Soulkeep_EventScript_Misdreavus_1:
	random 5
	setstatus1 STATUS1_FREEZE, VAR_RESULT
	waitmoncry
	release
	return

Soulkeep_EventScript_Misdreavus_2:
	msgbox Soulkeep_EventScript_Misdreavus_Text_0
	closemessage
	goto Soulkeep_EventScript_Misdreavus_1


Soulkeep_EventScript_Lampent::
	lock
	faceplayer
	setseenmon SPECIES_LAMPENT
	playmoncry SPECIES_LAMPENT, CRY_MODE_FAINT
	random 30
	compare VAR_RESULT, 4
	goto_if_eq Soulkeep_EventScript_Lampent_2
Soulkeep_EventScript_Lampent_1:
	random 5
	setstatus1 STATUS1_BURN, VAR_RESULT
	waitmoncry
	release
	return

Soulkeep_EventScript_Lampent_2:
	msgbox Soulkeep_EventScript_Misdreavus_Text_0
	closemessage
	goto Soulkeep_EventScript_Lampent_1


Soulkeep_EventScript_Gastly::
	lock
	faceplayer
	setseenmon SPECIES_GASTLY
	playmoncry SPECIES_GASTLY, CRY_MODE_FAINT
	random 30
	compare VAR_RESULT, 4
	goto_if_eq Soulkeep_EventScript_Gastly_2
Soulkeep_EventScript_Gastly_1:
	random 5
	setstatus1 STATUS1_SLEEP, VAR_RESULT
	waitmoncry
	release
	return

Soulkeep_EventScript_Gastly_2:
	msgbox Soulkeep_EventScript_Misdreavus_Text_0
	closemessage
	goto Soulkeep_EventScript_Gastly_1


Soulkeep_EventScript_Mart::
	lock
	faceplayer
	speakername Soulkeep_EventScript_Mart_Text_0
	message Soulkeep_EventScript_Mart_Text_1
	waitmessage
	pokemart Soulkeep_Mart
	speakername Soulkeep_EventScript_Mart_Text_0
	msgbox Soulkeep_EventScript_Mart_Text_2, MSGBOX_DEFAULT
	release
	return


	.align 2
Soulkeep_Mart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_OINTMENT
	.2byte ITEM_SUPER_OINTMENT
	.2byte ITEM_REVIVAL_POWDER
	.2byte ITEM_REVIVAL_BALM
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_NONE

Soulkeep_EventScript_TownSign_Text_0:
	.string "Soulkeep\n"
	.string "“A town where souls are laid to rest.”$"

Soulkeep_EventScript_IncenseShopSign_Text_0:
	.string "Incense Shop$"

Soulkeep_EventScript_GraveyardSign_Text_0:
	.string "{UP_ARROW} Graveyard\n"
	.string "“Please be respectful.”$"

Soulkeep_EventScript_Man_Text_0:
	.string "Man$"

Soulkeep_EventScript_Man_Text_1:
	.string "Can you believe this place used to be\n"
	.string "a quaint little farmers' town?\p"
	.string "Ever since the ghosts have started\n"
	.string "roaming the streets, the townsfolk\l"
	.string "are afraid of leaving their homes.\p"
	.string "I wish something could be done…$"

Soulkeep_EventScript_Misdreavus_Text_0:
	.string "G i v e u s\p"
	.string "y o u r s o u l$"

Soulkeep_EventScript_Mart_Text_0:
	.string "Shopkeeper$"

Soulkeep_EventScript_Mart_Text_1:
	.string "Welcome to Soulkeep's market,\n"
	.string "traveler!\p"
	.string "Are you looking to buy?$"

Soulkeep_EventScript_Mart_Text_2:
	.string "Do come again!$"

WindyCape2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WindyCape2_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

WindyCape2_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_WINDYCAPE
	return


WindyCape_EventScript_WindThroughHoles::
	lock
	speakername WindyCape_EventScript_WindThroughHoles_Text_0
	msgbox WindyCape_EventScript_WindThroughHoles_Text_1
	closemessage
	release
	return


WindyCape_EventScript_Mart::
	lock
	faceplayer
	speakername WindyCape_EventScript_Mart_Text_0
	message WindyCape_EventScript_Mart_Text_1
	waitmessage
	pokemart Soulkeep_Mart
	speakername WindyCape_EventScript_Mart_Text_0
	msgbox WindyCape_EventScript_Mart_Text_2, MSGBOX_DEFAULT
	release
	return


	.align 2
WindyCape_Mart:
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

WindyCape_EventScript_SignApricorn::
	msgbox WindyCape_EventScript_SignApricorn_Text_0, MSGBOX_SIGN
	return


WindyCape_EventScript_WindThroughHoles_Text_0:
	.string "Little Boy$"

WindyCape_EventScript_WindThroughHoles_Text_1:
	.string "When the wind blows through the holes\n"
	.string "in the rock, it makes strange noises.\p"
	.string "It's like it's singing a song!$"

WindyCape_EventScript_Mart_Text_0:
	.string "Shopkeeper$"

WindyCape_EventScript_Mart_Text_1:
	.string "Good day, welcome to Windycape's\n"
	.string "market!$"

WindyCape_EventScript_Mart_Text_2:
	.string "Thank you for your business!$"

WindyCape_EventScript_SignApricorn_Text_0:
	.string "Apricorn Workshop$"

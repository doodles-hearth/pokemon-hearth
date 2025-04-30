Silveridge_SculptorsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Silveridge_SculptorsHouse_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

Silveridge_SculptorsHouse_MapScripts_MAP_SCRIPT_ON_LOAD:
	compare VAR_STATE_SCULPTOR, 2
	goto_if_ge Silveridge_SculptorsHouse_MapScripts_MAP_SCRIPT_ON_LOAD_2
Silveridge_SculptorsHouse_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	compare VAR_STATE_SCULPTOR, 3
	goto_if_ge Silveridge_SculptorsHouse_MapScripts_MAP_SCRIPT_ON_LOAD_5
Silveridge_SculptorsHouse_MapScripts_MAP_SCRIPT_ON_LOAD_4:
	compare VAR_STATE_SCULPTOR, 4
	goto_if_ge Silveridge_SculptorsHouse_MapScripts_MAP_SCRIPT_ON_LOAD_8
Silveridge_SculptorsHouse_MapScripts_MAP_SCRIPT_ON_LOAD_7:
	special DrawWholeMapView
	return

Silveridge_SculptorsHouse_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	call Silveridge_SculptorsHouse_EventScript_DrawPonyta
	goto Silveridge_SculptorsHouse_MapScripts_MAP_SCRIPT_ON_LOAD_1

Silveridge_SculptorsHouse_MapScripts_MAP_SCRIPT_ON_LOAD_5:
	call Silveridge_SculptorsHouse_EventScript_DrawOnix
	goto Silveridge_SculptorsHouse_MapScripts_MAP_SCRIPT_ON_LOAD_4

Silveridge_SculptorsHouse_MapScripts_MAP_SCRIPT_ON_LOAD_8:
	call Silveridge_SculptorsHouse_EventScript_DrawClefable
	goto Silveridge_SculptorsHouse_MapScripts_MAP_SCRIPT_ON_LOAD_7


Silveridge_House1_EventScript_Sculptor::
	switch VAR_STATE_SCULPTOR
	case 0, Silveridge_House1_EventScript_Sculptor_2
	case 1, Silveridge_House1_EventScript_Sculptor_3
	case 2, Silveridge_House1_EventScript_Sculptor_4
	case 3, Silveridge_House1_EventScript_Sculptor_5
	return

Silveridge_House1_EventScript_Sculptor_2:
	call Silveridge_House1_EventScript_Sculptor_FirstTime
	return

Silveridge_House1_EventScript_Sculptor_3:
	setvar VAR_TEMP_1, SPECIES_PONYTA
	setvar VAR_TEMP_2, SPECIES_ONIX
	setvar VAR_TEMP_3, ITEM_TM_ANCIENT_POWER
	call Silveridge_House1_EventScript_Sculptor_BringMeMon
	return

Silveridge_House1_EventScript_Sculptor_4:
	setvar VAR_TEMP_1, SPECIES_ONIX
	setvar VAR_TEMP_2, SPECIES_CLEFABLE
	setvar VAR_TEMP_3, ITEM_TM_ROCK_BLAST
	call Silveridge_House1_EventScript_Sculptor_BringMeMon
	return

Silveridge_House1_EventScript_Sculptor_5:
	setvar VAR_TEMP_1, SPECIES_CLEFABLE
	setvar VAR_TEMP_2, SPECIES_DRAGONAIR
	setvar VAR_TEMP_3, ITEM_TM_ROCK_BLAST
	call Silveridge_House1_EventScript_Sculptor_BringMeMon
	return


Silveridge_SculptorsHouse_EventScript_DrawCurrentMon::
	switch VAR_TEMP_1
	case SPECIES_PONYTA, Silveridge_SculptorsHouse_EventScript_DrawCurrentMon_3
	case SPECIES_ONIX, Silveridge_SculptorsHouse_EventScript_DrawCurrentMon_4
	case SPECIES_CLEFABLE, Silveridge_SculptorsHouse_EventScript_DrawCurrentMon_5
Silveridge_SculptorsHouse_EventScript_DrawCurrentMon_1:
	special DrawWholeMapView
	return

Silveridge_SculptorsHouse_EventScript_DrawCurrentMon_3:
	call Silveridge_SculptorsHouse_EventScript_DrawPonyta
	goto Silveridge_SculptorsHouse_EventScript_DrawCurrentMon_1

Silveridge_SculptorsHouse_EventScript_DrawCurrentMon_4:
	call Silveridge_SculptorsHouse_EventScript_DrawOnix
	goto Silveridge_SculptorsHouse_EventScript_DrawCurrentMon_1

Silveridge_SculptorsHouse_EventScript_DrawCurrentMon_5:
	call Silveridge_SculptorsHouse_EventScript_DrawClefable
	goto Silveridge_SculptorsHouse_EventScript_DrawCurrentMon_1


Silveridge_SculptorsHouse_EventScript_DrawPonyta::
	setmetatile 13, 3, METATILE_HouseStone_StatuePonytaTopLeft, FALSE
	setmetatile 13, 4, METATILE_HouseStone_StatuePonytaBottomLeft, TRUE
	setmetatile 14, 4, METATILE_HouseStone_StatuePonytaBottomRight, TRUE
	return


Silveridge_SculptorsHouse_EventScript_DrawOnix::
	setmetatile 11, 1, METATILE_HouseStone_StatueOnixTopLeft, FALSE
	setmetatile 12, 1, METATILE_HouseStone_StatueOnixTopRight, FALSE
	setmetatile 11, 2, METATILE_HouseStone_StatueOnixBottomLeft, TRUE
	setmetatile 12, 2, METATILE_HouseStone_StatueOnixBottomRight, TRUE
	return


Silveridge_SculptorsHouse_EventScript_DrawClefable::
	setmetatile 9, 2, METATILE_HouseStone_StatueClefableTopLeft, FALSE
	setmetatile 10, 2, METATILE_HouseStone_StatueClefableTopRight, FALSE
	setmetatile 9, 3, METATILE_HouseStone_StatueClefableBottomLeft, TRUE
	setmetatile 10, 3, METATILE_HouseStone_StatueClefableBottomRight, TRUE
	return


Silveridge_House1_EventScript_Sculptor_BringMeMon::
	lock
	faceplayer
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	speakername Silveridge_House1_EventScript_Sculptor_BringMeMon_Text_0
	msgbox Silveridge_House1_EventScript_Sculptor_BringMeMon_Text_1
	checkspecies_choose VAR_TEMP_1
	compare VAR_RESULT, 0
	goto_if_ne Silveridge_House1_EventScript_Sculptor_BringMeMon_2
	speakername Silveridge_House1_EventScript_Sculptor_BringMeMon_Text_0
	msgbox Silveridge_House1_EventScript_Sculptor_BringMeMon_Text_4
Silveridge_House1_EventScript_Sculptor_BringMeMon_1:
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	return

Silveridge_House1_EventScript_Sculptor_BringMeMon_2:
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Silveridge_House1_EventScript_Sculptor_BringMeMon_Movement_0
	waitse
	waitmovement 0
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	speakername Silveridge_House1_EventScript_Sculptor_BringMeMon_Text_0
	msgbox Silveridge_House1_EventScript_Sculptor_BringMeMon_Text_2
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	playse SE_M_FLATTER
	delay 24
	playse SE_M_FLATTER
	delay 24
	playse SE_M_FLATTER
	delay 24
	playse SE_M_FLATTER
	call Silveridge_SculptorsHouse_EventScript_DrawCurrentMon
	delay 48
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 24
	bufferspeciesname STR_VAR_2, VAR_TEMP_2
	speakername Silveridge_House1_EventScript_Sculptor_BringMeMon_Text_0
	msgbox Silveridge_House1_EventScript_Sculptor_BringMeMon_Text_3
	closemessage
	giveitem VAR_TEMP_3
	setnamedmon VAR_TEMP_2
	addvar VAR_STATE_SCULPTOR, 1
	goto Silveridge_House1_EventScript_Sculptor_BringMeMon_1


Silveridge_House1_EventScript_Sculptor_FirstTime::
	lock
	faceplayer
	speakername Silveridge_House1_EventScript_Sculptor_BringMeMon_Text_0
	msgbox Silveridge_House1_EventScript_Sculptor_FirstTime_Text_0
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 60
	playse SE_PIN
	faceplayer
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	speakername Silveridge_House1_EventScript_Sculptor_BringMeMon_Text_0
	msgbox Silveridge_House1_EventScript_Sculptor_FirstTime_Text_1
	closemessage
	setnamedmon SPECIES_PONYTA
	setvar VAR_STATE_SCULPTOR, 1
	release
	return


Silveridge_House1_EventScript_Sculptor_BringMeMon_Movement_0:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

Silveridge_House1_EventScript_Sculptor_BringMeMon_Text_0:
	.string "Sculptor$"

Silveridge_House1_EventScript_Sculptor_BringMeMon_Text_1:
	.string "Please show me {STR_VAR_1}. My\n"
	.string "soul aches for it!$"

Silveridge_House1_EventScript_Sculptor_BringMeMon_Text_2:
	.string "Oh… … … …\n"
	.string "… … …Oh!!\p"
	.string "This is is… I can feel the raw\n"
	.string "inspiration coursing through my\l"
	.string "veins!\p"
	.string "Hello, {STR_VAR_1}!\n"
	.string "Stand still just a moment…$"

Silveridge_House1_EventScript_Sculptor_BringMeMon_Text_3:
	.string "There it is! My best work yet!\p"
	.string "… … …And yet…\p"
	.string "It still feels like something is\n"
	.string "missing.\p"
	.string "I think… I think…\n"
	.string "This wasn't the Pokémon my destiny\l"
	.string "was telling me about.\p"
	.string "I am seeing {STR_VAR_2} in my\n"
	.string "mind's eye…\p"
	.string "Yes! Please show me {STR_VAR_2}\n"
	.string "to help me achieve my magnum opus.\p"
	.string "Still, I must reward you for your\n"
	.string "assistance. Take this rock technique!$"

Silveridge_House1_EventScript_Sculptor_BringMeMon_Text_4:
	.string "Why must you toy with me so?$"

Silveridge_House1_EventScript_Sculptor_FirstTime_Text_0:
	.string "Please do not talk to me. I am\n"
	.string "creating.$"

Silveridge_House1_EventScript_Sculptor_FirstTime_Text_1:
	.string "…Oh? Could it be? Another noble soul\n"
	.string "moved by the ancestral art of\l"
	.string "sculpture?\p"
	.string "Am I no longer utterly alone? Oh, my\n"
	.string "heart swells up at the idea!\p"
	.string "As a fellow connoisseur of sculpture,\n"
	.string "you must know how difficult it is to\l"
	.string "find a proper model, one that will stir\l"
	.string "in its beholder the most violent\l"
	.string "passions.\p"
	.string "To transform a raw slab of stone into\n"
	.string "the pinnacle of beauty… That is my\l"
	.string "aspiration.\p"
	.string "To satisfy this need, I must lay my\n"
	.string "eyes on a Ponyta.\p"
	.string "I see that you are a Wielder. Please\n"
	.string "show me a Ponyta to help me achieve\l"
	.string "my magnum opus.$"

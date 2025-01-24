Silveridge_SculptorsHouse_MapScripts::
	.byte 0


Silveridge_House1_EventScript_Sculptor::
	lock
	faceplayer
	msgbox Silveridge_House1_EventScript_Sculptor_Text_0
	closemessage
	applymovement 0, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 60
	playse SE_PIN
	faceplayer
	applymovement 0, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 0, Common_Movement_Delay48
	waitmovement 0
	msgbox Silveridge_House1_EventScript_Sculptor_Text_1
	closemessage
	release
	return


Silveridge_House1_EventScript_Sculptor_Text_0:
	.string "Please do not talk to me. I am\n"
	.string "creating.$"

Silveridge_House1_EventScript_Sculptor_Text_1:
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
	.string "eyes on a XXX.\p"
	.string "I see that you are a trainer. Please\n"
	.string "bring me a XXX to help me achieve my\l"
	.string "magnum opus.$"

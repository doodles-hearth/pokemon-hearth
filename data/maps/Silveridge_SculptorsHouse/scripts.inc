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
	.string "…Oh? Could it be? Another noble\n"
	.string "soul moved by the ancestral art\l"
	.string "of sculpture?\p"
	.string "Am I no longer utterly alone? Oh,\n"
	.string "my heart swells up at the idea!\p"
	.string "As a fellow connoisseur of\n"
	.string "sculpture, you must know how\l"
	.string "difficult it is to find a proper\l"
	.string "model, one that will stir in its\l"
	.string "beholder the most violent\l"
	.string "passions.\p"
	.string "To transform a raw slab of stone\n"
	.string "into the pinnacle of beauty… That\l"
	.string "is my aspiration.\p"
	.string "To satisfy this need, I must lay my\n"
	.string "eyes on a XXX.\p"
	.string "I see that you are a trainer.\n"
	.string "Please bring me a XXX to help me\l"
	.string "achieve my magnum opus.$"

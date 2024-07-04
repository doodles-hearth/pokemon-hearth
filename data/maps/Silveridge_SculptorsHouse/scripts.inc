Silveridge_SculptorsHouse_MapScripts::
	.byte 0


Silveridge_House1_EventScript_Sculptor::
# 9 "data/maps/Silveridge_SculptorsHouse/scripts.pory"
	lock
# 10 "data/maps/Silveridge_SculptorsHouse/scripts.pory"
	faceplayer
# 11 "data/maps/Silveridge_SculptorsHouse/scripts.pory"
	msgbox Silveridge_House1_EventScript_Sculptor_Text_0
# 14 "data/maps/Silveridge_SculptorsHouse/scripts.pory"
	closemessage
# 15 "data/maps/Silveridge_SculptorsHouse/scripts.pory"
	applymovement 0, Common_Movement_FaceOriginalDirection
# 16 "data/maps/Silveridge_SculptorsHouse/scripts.pory"
	waitmovement 0
# 17 "data/maps/Silveridge_SculptorsHouse/scripts.pory"
	delay 60
# 19 "data/maps/Silveridge_SculptorsHouse/scripts.pory"
	playse SE_PIN
# 20 "data/maps/Silveridge_SculptorsHouse/scripts.pory"
	faceplayer
# 21 "data/maps/Silveridge_SculptorsHouse/scripts.pory"
	applymovement 0, Common_Movement_ExclamationMark
# 22 "data/maps/Silveridge_SculptorsHouse/scripts.pory"
	waitmovement 0
# 23 "data/maps/Silveridge_SculptorsHouse/scripts.pory"
	applymovement 0, Common_Movement_Delay48
# 24 "data/maps/Silveridge_SculptorsHouse/scripts.pory"
	waitmovement 0
# 31 "data/maps/Silveridge_SculptorsHouse/scripts.pory"
	msgbox Silveridge_House1_EventScript_Sculptor_Text_1
# 39 "data/maps/Silveridge_SculptorsHouse/scripts.pory"
	closemessage
# 41 "data/maps/Silveridge_SculptorsHouse/scripts.pory"
	release
	return


Silveridge_House1_EventScript_Sculptor_Text_0:
# 12 "data/maps/Silveridge_SculptorsHouse/scripts.pory"
	.string "Please do not talk to me. I am\n"
	.string "creating.$"

Silveridge_House1_EventScript_Sculptor_Text_1:
# 32 "data/maps/Silveridge_SculptorsHouse/scripts.pory"
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

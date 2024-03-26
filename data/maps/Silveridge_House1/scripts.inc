Silveridge_House1_MapScripts::
	.byte 0


Silveridge_House1_EventScript_SculptorFirstEncounter::
# 8 "data/maps/Silveridge_House1/scripts.pory"
	lock
# 9 "data/maps/Silveridge_House1/scripts.pory"
	faceplayer
# 10 "data/maps/Silveridge_House1/scripts.pory"
	msgbox Silveridge_House1_EventScript_SculptorFirstEncounter_Text_0
# 13 "data/maps/Silveridge_House1/scripts.pory"
	closemessage
# 14 "data/maps/Silveridge_House1/scripts.pory"
	applymovement 0, Common_Movement_FaceOriginalDirection
# 15 "data/maps/Silveridge_House1/scripts.pory"
	waitmovement 0
# 16 "data/maps/Silveridge_House1/scripts.pory"
	delay 60
# 18 "data/maps/Silveridge_House1/scripts.pory"
	playse SE_PIN
# 19 "data/maps/Silveridge_House1/scripts.pory"
	faceplayer
# 20 "data/maps/Silveridge_House1/scripts.pory"
	applymovement 0, Common_Movement_ExclamationMark
# 21 "data/maps/Silveridge_House1/scripts.pory"
	waitmovement 0
# 22 "data/maps/Silveridge_House1/scripts.pory"
	applymovement 0, Common_Movement_Delay48
# 23 "data/maps/Silveridge_House1/scripts.pory"
	waitmovement 0
# 25 "data/maps/Silveridge_House1/scripts.pory"
	msgbox Silveridge_House1_EventScript_SculptorFirstEncounter_Text_1
# 34 "data/maps/Silveridge_House1/scripts.pory"
	release
	return


Silveridge_House1_EventScript_SculptorFirstEncounter_Text_0:
# 11 "data/maps/Silveridge_House1/scripts.pory"
	.string "Please do not talk to me. I am creating.$"

Silveridge_House1_EventScript_SculptorFirstEncounter_Text_1:
# 26 "data/maps/Silveridge_House1/scripts.pory"
	.string "…Oh? Could it be? Another noble soul\n"
	.string "moved by the ancestral art of\l"
	.string "sculpture?\p"
	.string "Am I no longer utterly alone? Oh, my\n"
	.string "heart swells up at the idea! As a fellow\l"
	.string "connoisseur of sculpture, you must\l"
	.string "know how difficult it is to find a proper\l"
	.string "model, one that will stir in its beholder\l"
	.string "the most violent passions.\p"
	.string "To transform a raw slab of stone into\n"
	.string "the pinnacle of beauty… That is my\l"
	.string "aspiration.\p"
	.string "To satisfy this need, I must lay my eyes\n"
	.string "on a XXX.\p"
	.string "I see that you are a trainer. Please\n"
	.string "bring me a XXX to help me achieve my\l"
	.string "magnum opus.$"

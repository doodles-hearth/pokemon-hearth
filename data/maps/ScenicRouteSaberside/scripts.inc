ScenicRouteSaberside_MapScripts::
	.byte 0


ScenicRoute_Trigger_EnterZoneUnderBridge::
	lockall
	setmetatile 26, 12, METATILE_ScenicRoute_BridgePassUnder_TopLeft, FALSE
	setmetatile 26, 13, METATILE_ScenicRoute_BridgePassUnder_MiddleLeft, FALSE
	setmetatile 26, 14, METATILE_ScenicRoute_BridgePassUnder_BottomLeft, FALSE
	setmetatile 27, 12, METATILE_ScenicRoute_BridgePassUnder_TopMiddle, FALSE
	setmetatile 27, 13, METATILE_ScenicRoute_BridgePassUnder_MiddleMiddle, FALSE
	setmetatile 27, 14, METATILE_ScenicRoute_BridgePassUnder_BottomMiddle, FALSE
	setmetatile 28, 12, METATILE_ScenicRoute_BridgePassUnder_TopRight, FALSE
	setmetatile 28, 13, METATILE_ScenicRoute_BridgePassUnder_MiddleRight, FALSE
	setmetatile 28, 14, METATILE_ScenicRoute_BridgePassUnder_BottomRight, FALSE
	special DrawWholeMapView
	setvar VAR_TEMP_0, 1
	releaseall
	return


ScenicRoute_Trigger_ExitZoneUnderBridge::
	lockall
	setmetatile 26, 12, METATILE_ScenicRoute_BridgeWalkOver_TopLeft, FALSE
	setmetatile 26, 13, METATILE_ScenicRoute_BridgeWalkOver_MiddleLeft, FALSE
	setmetatile 26, 14, METATILE_ScenicRoute_BridgeWalkOver_BottomLeft, FALSE
	setmetatile 27, 12, METATILE_ScenicRoute_BridgeWalkOver_TopMiddle, FALSE
	setmetatile 27, 13, METATILE_ScenicRoute_BridgeWalkOver_MiddleMiddle, FALSE
	setmetatile 27, 14, METATILE_ScenicRoute_BridgeWalkOver_BottomMiddle, FALSE
	setmetatile 28, 12, METATILE_ScenicRoute_BridgeWalkOver_TopRight, FALSE
	setmetatile 28, 13, METATILE_ScenicRoute_BridgeWalkOver_MiddleRight, FALSE
	setmetatile 28, 14, METATILE_ScenicRoute_BridgeWalkOver_BottomRight, FALSE
	special DrawWholeMapView
	setvar VAR_TEMP_0, 0
	releaseall
	return


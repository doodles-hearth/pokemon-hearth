EventScript_ShamisenPlayer::
    callnative StartShamisenPlayerScript
    end

EventScript_ShamisenPlayerBlue::
    setshamisenplayerflag SHAMISEN_PLAYER_FLAG_TALKED_TODAY, TRUE
    getshamisenplayerflag SHAMISEN_PLAYER_FLAG_TALKED_BEFORE
    call_if_eq VAR_RESULT, 0, ShamisenTestFirstEncounter
    call ShamisenTestSecondEncounter
    end

EventScript_ShamisenPlayerRed::
    setshamisenplayerflag SHAMISEN_PLAYER_FLAG_TALKED_TODAY, TRUE
    getshamisenplayerflag SHAMISEN_PLAYER_FLAG_TALKED_BEFORE
    call_if_eq VAR_RESULT, 0, ShamisenTestFirstEncounter
    call ShamisenTestSecondEncounter
    end

EventScript_ShamisenPlayerGreen::
    setshamisenplayerflag SHAMISEN_PLAYER_FLAG_TALKED_TODAY, TRUE
    getshamisenplayerflag SHAMISEN_PLAYER_FLAG_TALKED_BEFORE
    call_if_eq VAR_RESULT, 0, ShamisenTestFirstEncounter
    call ShamisenTestSecondEncounter
    end

ShamisenTestFirstEncounter:
    msgbox FirstEncounter, MSGBOX_NPC
    end

ShamisenTestSecondEncounter:
    msgbox SecondEncounter, MSGBOX_NPC
    end

FirstEncounter:
    .string "First Encounter$"

SecondEncounter:
    .string "Second Encounter$"

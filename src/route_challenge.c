#include "global.h"

#include "event_data.h"
#include "route_challenge.h"
#include "script.h"

// Fails any started route challenges
void FailActiveRouteChallenges(void)
{
    for (enum RouteChallenge routeChallenge = ROUTE_CHALLENGE_WHITESLATE_YIFU; routeChallenge < ROUTE_CHALLENGE_COUNT; routeChallenge += 1)
    {
        if (gSaveBlock1Ptr->routeChallengeStates[routeChallenge] == ROUTE_CHALLENGE_STATE_STARTED)
        {
            gSaveBlock1Ptr->routeChallengeStates[routeChallenge] = ROUTE_CHALLENGE_STATE_FAILURE;
        }
    }
}

void Native_GetRouteChallengeState(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1);
    
    u32 routeChallenge = ScriptReadHalfword(ctx);
    
    gSpecialVar_Result = gSaveBlock1Ptr->routeChallengeStates[routeChallenge];
}

void Native_SetRouteChallengeState(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1);

    u32 routeChallenge = ScriptReadHalfword(ctx);
    u32 newState = ScriptReadHalfword(ctx);

    gSaveBlock1Ptr->routeChallengeStates[routeChallenge] = newState;
}

#ifndef GUARD_CONSTANTS_ROUTE_CHALLENGE_H
#define GUARD_CONSTANTS_ROUTE_CHALLENGE_H

enum RouteChallenge {
    ROUTE_CHALLENGE_WHITESLATE_YIFU,
    ROUTE_CHALLENGE_SCENIC_SABERSIDE,
    ROUTE_CHALLENGE_COUNT
};

enum RouteChallengeState {
    // Initial state
    ROUTE_CHALLENGE_STATE_INITIAL,
    // Player has met the corresponding NPC, but has not yet started the challenge
    ROUTE_CHALLENGE_STATE_EXPLAINED,
    // Challenge has started
    ROUTE_CHALLENGE_STATE_STARTED,
    // Player has reached the end of the route challenge, but hasn't talked to the NPC yet
    // (This prevents the challenge being failed if the player heals at the pokécenter and THEN speaks to the NPC)
    ROUTE_CHALLENGE_STATE_SUCCESS,
    // Player has talked to the NPC after the route challenge, without having failed the challenge
    ROUTE_CHALLENGE_STATE_SUCCESS_CONFIRMED,
    // Player has failed the challenge
    ROUTE_CHALLENGE_STATE_FAILURE,
    // Player has failed the challenge and talked to the corresponding NPC at the end of the challenge
    ROUTE_CHALLENGE_STATE_FAILURE_CONFIRMED
};

#endif // GUARD_CONSTANTS_POKEMON_H

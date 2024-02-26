#ifndef GUARD_CONSTANTS_FIELD_WEATHER_H
#define GUARD_CONSTANTS_FIELD_WEATHER_H

#define MAX_RAIN_SPRITES             24
#define NUM_CLOUD_SPRITES            3
#define MAX_BIRD_SPRITES             20
#define NUM_FOG_HORIZONTAL_SPRITES   20
#define NUM_ASH_SPRITES              20
#define NUM_FOG_DIAGONAL_SPRITES     20
#define NUM_SANDSTORM_SPRITES        20
#define NUM_SWIRL_SANDSTORM_SPRITES  5

// Controls how the weather should be changing the screen palettes.
#define WEATHER_PAL_STATE_CHANGING_WEATHER   0
#define WEATHER_PAL_STATE_SCREEN_FADING_IN   1
#define WEATHER_PAL_STATE_SCREEN_FADING_OUT  2
#define WEATHER_PAL_STATE_IDLE               3

// Modes for FadeScreen
#define FADE_FROM_BLACK  0
#define FADE_TO_BLACK    1
#define FADE_FROM_WHITE  2
#define FADE_TO_WHITE    3

// birds weather
#define BIRD_DESTROY_PIXEL_BUFFER       32  // how many pixels off screen to wait before destroying birds
#define BIRD_X_SPAWN_DISTANCE           16  // how many pixels outside the edge of the screen to create sprites
#define BIRD_Y_SPAWN_RANGE              64  // range of how many pixels above/below the center of the screen to create sprites
#define BIRD_X_FLOCK_RANGE              8   // how many horizontal pixels apart birds in a flock should be
#define BIRD_Y_FLOCK_RANGE              8   // how many vertical pixels apart birds in a flock should be

#endif // GUARD_CONSTANTS_FIELD_WEATHER_H

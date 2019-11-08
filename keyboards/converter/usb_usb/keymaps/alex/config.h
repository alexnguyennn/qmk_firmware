#pragma once

// place overrides here
#define IGNORE_MOD_TAP_INTERRUPT

#undef LEADER_TIMEOUT
#define LEADER_TIMEOUT 350

// memory saving disables
/* disable debug print */
#undef NO_DEBUG
#define NO_DEBUG

/* disable print */
#undef NO_PRINT
#define NO_PRINT

/* disable action features */
// #undef NO_ACTION_LAYER
// #define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
#undef NO_ACTION_ONESHOT
#define NO_ACTION_ONESHOT
// deprecated macro code - process_record_user + send_string different?
#undef NO_ACTION_MACRO
#define NO_ACTION_MACRO
#undef NO_ACTION_FUNCTION
#define NO_ACTION_FUNCTION
// #undef DEBUG_MATRIX_SCAN_RATE
// #define DEBUG_MATRIX_SCAN_RATE
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16 // 1/60 = 16

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 5

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 0

#define MK_MOMENTARY_ACCEL


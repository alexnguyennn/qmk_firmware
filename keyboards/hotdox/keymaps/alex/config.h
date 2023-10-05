#pragma once

// place overrides here
// override this value if run into typing speed limitations

// used dynamic tap term to find
// ; 415 start modifying too much; 425 capitalising starts to fail
#undef TAPPING_TERM
// #define TAPPING_TERM    425
#define TAPPING_TERM 200

#define TAPPING_TERM_PER_KEY

#undef LEADER_TIMEOUT
#define LEADER_TIMEOUT 350

#define LEADER_PER_KEY_TIMING

#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16 // 1/60 = 16

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 5

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 0

#define MK_MOMENTARY_ACCEL
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

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
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 3000 // 5 seconds is the default.

// define how many combos are in our map
#define COMBO_COUNT 4
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_TERM_PER_COMBO

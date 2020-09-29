#pragma once
/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define FIRMWARE_VERSION u8"9QwVj/A0wp6"
#define RGB_MATRIX_STARTUP_SPD 60

#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#undef TAPPING_TERM
#define TAPPING_TERM    180

#define TAPPING_TERM_PER_KEY

// #undef TAP_CODE_DELAY 
// #define TAP_CODE_DELAY 50


#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16 // 1/60 = 16

#undef MOUSEKEY_DELAY          
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_WHEEL_DELAY    
#define MOUSEKEY_WHEEL_DELAY    0

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 5

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 0

#define MK_MOMENTARY_ACCEL
#pragma once
/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define FIRMWARE_VERSION u8"9QwVj/A0wp6"
#define RGB_MATRIX_STARTUP_SPD 60

#undef TAPPING_TERM
#define TAPPING_TERM 200

#define TAPPING_TERM_PER_KEY

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

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 3000 // 5 seconds is the default.

// define how many combos are in our map
#define COMBO_COUNT 2
// configure combo parameters
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_TERM_PER_COMBO

// clang-format off
// NOTE: should not need this, other layouts don't
// but currently complains about LAYOUT_moonlander not being found
// related gh suggests avr-gcc version..
// https://github.com/qmk/qmk_firmware/issues/3251
#define LAYOUT_moonlander( \
    k00, k01, k02, k03, k04, k05, k06,   k60, k61, k62, k63, k64, k65, k66, \
    k10, k11, k12, k13, k14, k15, k16,   k70, k71, k72, k73, k74, k75, k76, \
    k20, k21, k22, k23, k24, k25, k26,   k80, k81, k82, k83, k84, k85, k86, \
    k30, k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, k96, \
    k40, k41, k42, k43, k44,      k53,   kb3,      ka2, ka3, ka4, ka5, ka6, \
                        k50, k51, k52,   kb4, kb5, kb6 \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06 }, \
    { k10, k11, k12, k13, k14, k15, k16 }, \
    { k20, k21, k22, k23, k24, k25, k26 }, \
    { k30, k31, k32, k33, k34, k35, KC_NO }, \
    { k40, k41, k42, k43, k44, KC_NO, KC_NO }, \
    { k50, k51, k52, k53, KC_NO, KC_NO, KC_NO }, \
\
    { k60, k61, k62, k63, k64, k65, k66 }, \
    { k70, k71, k72, k73, k74, k75, k76 }, \
    { k80, k81, k82, k83, k84, k85, k86 }, \
    { KC_NO, k91, k92, k93, k94, k95, k96 }, \
    { KC_NO, KC_NO, ka2, ka3, ka4, ka5, ka6 }, \
    { KC_NO, KC_NO, KC_NO, kb3, kb4, kb5, kb6 } \
}
// clang-format on

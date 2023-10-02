#include QMK_KEYBOARD_H
#include "version.h"
// #include "keymap_german.h"
// #include "keymap_nordic.h"
// #include "keymap_french.h"
// #include "keymap_spanish.h"
// #include "keymap_hungarian.h"
// #include "keymap_swedish.h"
// #include "keymap_br_abnt2.h"
// #include "keymap_canadian_multilingual.h"
// #include "keymap_german_ch.h"
// #include "keymap_jp.h"
// #include "keymap_bepo.h"
// #include "keymap_italian.h"
// #include "keymap_slovenian.h"
// #include "keymap_danish.h"
// #include "keymap_norwegian.h"
// #include "keymap_portuguese.h"

#define KC_PC_CUT LCTL(KC_X)
/*
#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
*/

enum custom_keycodes { RGB_SLD = ML_SAFE_RANGE, HSV_0_255_255, HSV_86_255_128, HSV_172_255_255, EASYMOTION };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_moonlander(
        KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           TG(1),                                        TG(4),       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
        KC_TAB,         MT(MOD_LCTL|MOD_LGUI|MOD_LSFT,KC_Q),           LCAG_T(KC_W),           MT(MOD_LALT|MOD_LGUI|MOD_LSFT,KC_E),           MEH_T(KC_R),LT(2,KC_T),     TG(1),                                          TG(1),          LT(2,KC_Y),     MEH_T(KC_U),MT(MOD_LALT|MOD_LGUI|MOD_LSFT,KC_I),           LCAG_T(KC_O),           MT(MOD_LCTL|MOD_LGUI|MOD_LSFT,KC_P),           KC_BSLS,
        HYPR_T(KC_ESCAPE),MT(MOD_LCTL|MOD_LGUI,KC_A),           MT(MOD_LALT|MOD_LGUI,KC_S),           SGUI_T(KC_D),   C_S_T(KC_F),    LCA_T(KC_G),    C(KC_UNDERSCORE),                                                                        C(KC_UNDERSCORE),         LCA_T(KC_H),    C_S_T(KC_J),    SGUI_T(KC_K),   MT(MOD_LALT|MOD_LGUI,KC_L),           MT(MOD_LCTL|MOD_LGUI,KC_SCLN),LGUI_T(KC_QUOTE),
        KC_LSPO,        CTL_T(KC_Z),   GUI_T(KC_X),   ALT_T(KC_C),   LSA_T(KC_V),    KC_B,                                           KC_N,           LSA_T(KC_M),    ALT_T(KC_COMMA),GUI_T(KC_DOT), CTL_T(KC_SLSH),KC_RSPC,
        LT(1,KC_EQUAL), KC_UNDERSCORE,    KC_KP_PLUS,KC_LBRC,        LT(1,KC_RBRC),       LALT_T(KC_APPLICATION),                                                                                                LCTL_T(KC_ESCAPE),LT(1,KC_BSLS),          C(KC_B),        S(KC_INSERT),    CAPS_WORD,    LCTL(LSFT(KC_F12)),
        LT(3,KC_SPACE), LT(1,KC_BSPC),EASYMOTION,                         EASYMOTION,        LT(1,KC_DELETE),LT(3,KC_ENTER)
    ),
    [1] = LAYOUT_moonlander(
        KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
        CAPS_WORD, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_UNDERSCORE, KC_KP_PLUS,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
        KC_GRAVE, KC_HASH,        KC_DLR,         KC_LEFT_ANGLE_BRACKET,        KC_RIGHT_ANGLE_BRACKET,        KC_MINUS,       KC_EQUAL,                                                                 KC_TRANSPARENT, KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_KP_PLUS,     KC_TRANSPARENT,
        KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRC,    KC_RBRC,    KC_TRANSPARENT,                                        KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLS,      KC_TRANSPARENT,
        KC_TRANSPARENT, KC_COMMA,       HSV_0_255_255,  HSV_86_255_128, HSV_172_255_255,RGB_MOD,                                                                                                        RGB_TOG,        KC_0, KC_DOT,         KC_0,           KC_EQUAL,       KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, TOGGLE_LAYER_COLOR,                RGB_SLD,        KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [2] = LAYOUT_moonlander(
        AU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,
        MU_TOG,         KC_TRANSPARENT, KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_MS_ACCEL0,   KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_WH_LEFT, KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT,
        MU_MOD,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_BRMU, KC_BRMD,
        KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_WWW_BACK
    ),
    [3] = LAYOUT_moonlander(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_PGUP,        KC_HOME,        KC_END,         KC_TRANSPARENT, KC_EQUAL,
        KC_CAPS_LOCK,    KC_TRANSPARENT, KC_TRANSPARENT, KC_PGDN,      KC_FIND,        KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_BSPC,      KC_DELETE,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PC_CUT,      LSFT(KC_INSERT),KC_PSCR,                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, WEBUSB_PAIR, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
    [4] = LAYOUT_moonlander(
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, TG(4),                                 TG(4), KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, TG(1),                                 TG(1), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        KC_ESCAPE, KC_A, KC_S, KC_D, KC_F, KC_G, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOTE,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                                 KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_LBRC, KC_RBRC, KC_APPLICATION,                                                                                                 KC_TRANSPARENT, KC_TRNS, KC_TRANSPARENT, KC_RALT, KC_RGUI, KC_RCTL,
        KC_SPACE, LT(1,KC_BSPC), LT(3,KC_ESCAPE),                 KC_EQUAL, LT(1,KC_DELETE), LT(3,KC_ENTER)
    ),
};
// clang-format on

// extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {146, 224, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

    [2] = {{82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175},
           {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}, {82, 163, 175}},

    [3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {15, 166, 195}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {15, 166, 195}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {15, 166, 195}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {15, 166, 195}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

};

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return false;
    }
    switch (biton32(layer_state)) {
        case 0:
            set_layer_color(0);
            break;
        case 2:
            set_layer_color(2);
            break;
        case 3:
            set_layer_color(3);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
        case HSV_0_255_255:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(0, 255, 255);
            }
            return false;
        case HSV_86_255_128:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(86, 255, 128);
            }
            return false;
        case HSV_172_255_255:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(172, 255, 255);
            }
            return false;
        case EASYMOTION:
            if (record->event.pressed) {
                tap_code(KC_G);
                tap_code(KC_S);
            }
    }
    return true;
}

// #region combos
const uint16_t PROGMEM tmux_prefix_left_combo[]  = {SGUI_T(KC_D), C_S_T(KC_F), COMBO_END};
const uint16_t PROGMEM tmux_prefix_right_combo[] = {C_S_T(KC_J), SGUI_T(KC_K), COMBO_END};
combo_t                key_combos[COMBO_COUNT]   = {
                     COMBO(tmux_prefix_left_combo, C(KC_UNDERSCORE)),
                     COMBO(tmux_prefix_right_combo, C(KC_UNDERSCORE)),
};

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // decide by combo->keycode
    // NOTE: pick a combo low enough to stop skipping characters during typing but
    // high enough that we can still trigger it
    switch (combo->keycode) {
        // tmux prefix: mkdir is a good test string
        case C(KC_UNDERSCORE):
            return 15; // use a short prefix; combo should be pressed at same time
    }

    // // or with combo index, i.e. its name from enum.
    // switch (index) {
    //     case COMBO_NAME_HERE:
    //         return 9001;
    // }

    // And if you're feeling adventurous, you can even decide by the keys in the chord,
    // i.e. the exact array of keys you defined for the combo.
    // This can be useful if your combos have a common key and you want to apply the
    // same combo term for all of them.
    // if (combo->keys[0] == KC_ENT) { // if first key in the array is Enter
    //     return 150;
    // }

    return COMBO_TERM;
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    // If you want all combos to be tap-only, just uncomment the next line
    // return true

    // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be tap-only, this is for you:
    uint16_t key;
    uint8_t  idx = 0;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
                return true;
        }
        idx += 1;
    }
    return false;
}

// #endregion

/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
enum charybdis_keymap_layers {
    BASE = 0,
    SYMB,
    CUSTOM,
    POINTER,
};

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define PT_Z LT(POINTER, KC_Z)
#define PT_SLSH LT(POINTER, KC_SLSH)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

enum custom_keycodes { EASYMOTION = SAFE_RANGE };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_GRAVE,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        HYPR_T(KC_TAB),    MT(MOD_LCTL|MOD_LGUI|MOD_LSFT,KC_Q),    LCAG_T(KC_W),    MT(MOD_LALT|MOD_LGUI|MOD_LSFT,KC_E),    MEH_T(KC_R),    LT(POINTER, KC_T),       LT(POINTER, KC_Y),    MEH_T(KC_U),    MT(MOD_RALT|MOD_RGUI|MOD_RSFT,KC_I),    LCAG_T(KC_O),    MT(MOD_RCTL|MOD_RGUI|MOD_RSFT,KC_P), KC_BSLS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       HYPR_T(KC_ESCAPE),    MT(MOD_LCTL|MOD_LGUI,KC_A),    MT(MOD_LALT|MOD_LGUI,KC_S),    SGUI_T(KC_D),    C_S_T(KC_F),    LCA_T(KC_G),       LCA_T(KC_H),    C_S_T(KC_J),    SGUI_T(KC_K),    MT(MOD_RALT|MOD_RGUI,KC_L), MT(MOD_RCTL|MOD_RGUI,KC_SEMICOLON), HYPR_T(KC_QUOTE),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       SC_LSPO,    CTL_T(KC_Z),    GUI_T(KC_X),    ALT_T(KC_C),    MT(MOD_LSFT|MOD_LALT,KC_V),    LT(SYMB, KC_B),       LT(SYMB, KC_N),    MT(MOD_RSFT|MOD_RALT,KC_M), ALT_T(KC_COMMA),  GUI_T(KC_DOT), CTL_T(KC_SLASH), SC_RSPC,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                   LT(CUSTOM,KC_SPC), LT(SYMB,KC_BACKSPACE),   KC_UNDERSCORE,      LT(SYMB,KC_DELETE),  LT(CUSTOM,KC_ENT),
                                           EASYMOTION, KC_MINUS,     EASYMOTION
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [SYMB] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TILD, KC_F1,   KC_F2, KC_F3,  KC_F4, KC_F5,    KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       QK_CAPS_WORD_TOGGLE, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PLUS,    KC_PLUS,   KC_7,   KC_8,   KC_9, KC_RBRC, KC_F12,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_GRAVE, KC_TILD, KC_GRAVE, S(KC_COMMA), S(KC_DOT), KC_MINUS,    KC_MINUS,   KC_4,   KC_5,   KC_6, KC_PMNS, KC_PEQL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      RGB_RMOD, XXXXXXX, XXXXXXX, ALT_T(KC_LBRC), KC_RBRC, KC_EQUAL,    KC_EQUAL,   KC_1,   KC_2,   KC_3, KC_PSLS, KC_PDOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, _______,    XXXXXXX, KC_0,
                                           KC_UNDERSCORE, XXXXXXX,      _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [CUSTOM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_INSERT, KC_PGUP, KC_HOME, KC_END, KC_VOLU, KC_F12,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPLY, XXXXXXX,   XXXXXXX, KC_PGDN, KC_FIND, XXXXXXX,    KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_MUTE, KC_BRMU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPRV, KC_UNDERSCORE, XXXXXXX, KC_CUT,  XXXXXXX, KC_PSCR,    XXXXXXX, XXXXXXX, XXXXXXX, QK_CAPS_WORD_TOGGLE, KC_VOLD, KC_BRMD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_LBRC, S(KC_COMMA), XXXXXXX,    S(KC_DOT), KC_RBRC,
                                           KC_LCBR, KC_PLUS,    KC_RCBR
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, DRGSCRL, SNIPING, DRGSCRL, SNIPING, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RALT, SNIPING, DRGSCRL, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, DRGSCRL, SNIPING, EE_CLR,  QK_BOOT,    QK_BOOT, EE_CLR,  SNIPING, DRGSCRL, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_BTN3, KC_BTN1,
                                           XXXXXXX, KC_BTN2,    KC_BTN2
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

void shutdown_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(1);
    rgblight_setrgb(RGB_RED);
#endif // RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_color_all(RGB_RED);
    rgb_matrix_update_pwm_buffers();
#endif // RGB_MATRIX_ENABLE
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EASYMOTION:
            if (record->event.pressed) {
                tap_code(KC_G);
                tap_code(KC_S);
            }
            break;
    }
    return true;
}

// #region combos
const uint16_t PROGMEM grave_combo[]             = {LT(CUSTOM, KC_SPC), EASYMOTION, COMBO_END};
const uint16_t PROGMEM minus_combo[]             = {LT(CUSTOM, KC_ENT), EASYMOTION, COMBO_END};
const uint16_t PROGMEM tmux_prefix_left_combo[]  = {LT(SYMB, KC_BSPC), EASYMOTION, COMBO_END};
const uint16_t PROGMEM tmux_prefix_right_combo[] = {LT(SYMB, KC_DELETE), EASYMOTION, COMBO_END};
const uint16_t PROGMEM backslash_left_combo[]    = {SGUI_T(KC_D), C_S_T(KC_F), COMBO_END};
const uint16_t PROGMEM backslash_right_combo[]   = {C_S_T(KC_J), SGUI_T(KC_K), COMBO_END};
const uint16_t PROGMEM equals_combo[]            = {KC_UNDERSCORE, KC_MINUS, COMBO_END};
const uint16_t PROGMEM caps_combo[]              = {LT(CUSTOM, KC_SPC), LT(CUSTOM, KC_ENT), COMBO_END};
const uint16_t PROGMEM angle_left_combo[]        = {SGUI_T(KC_D), MT(MOD_LALT | MOD_LGUI, KC_S), COMBO_END};
const uint16_t PROGMEM angle_right_combo[]       = {SGUI_T(KC_K), MT(MOD_RALT | MOD_RGUI, KC_L), COMBO_END};
const uint16_t PROGMEM brace_left_combo[]        = {MT(MOD_LALT | MOD_LGUI | MOD_LSFT, KC_E), LCAG_T(KC_W), COMBO_END};
const uint16_t PROGMEM brace_right_combo[]       = {MT(MOD_LALT | MOD_LGUI | MOD_LSFT, KC_I), LCAG_T(KC_O), COMBO_END};
const uint16_t PROGMEM easymotion_left_combo[]   = {ALT_T(KC_C), MT(MOD_LSFT | MOD_LALT, KC_V), COMBO_END};
const uint16_t PROGMEM easymotion_right_combo[]  = {ALT_T(KC_COMMA), MT(MOD_RSFT | MOD_RALT, KC_M), COMBO_END};

// clang-format off
// TODO: rename variables
// TODO: inroduce left 2 button combo // put scroll there, put snipe in existing scroll
// put -/_/=/+ on space layer
combo_t key_combos[COMBO_COUNT] = {
    COMBO(tmux_prefix_left_combo, KC_BTN1),
    COMBO(tmux_prefix_right_combo, LT(SYMB, KC_GRAVE)),
    COMBO(backslash_left_combo, LT(SYMB, KC_BACKSLASH)),
    COMBO(backslash_right_combo, LT(SYMB, KC_BACKSLASH)),
    COMBO(equals_combo, LT(SYMB, KC_EQUAL)),
    COMBO(caps_combo, QK_CAPS_WORD_TOGGLE),
    COMBO(angle_left_combo, C(KC_UNDERSCORE)),
    COMBO(angle_right_combo, C(KC_UNDERSCORE)),
    COMBO(brace_left_combo, SNIPING),
    COMBO(brace_right_combo, KC_RCBR),
    COMBO(easymotion_left_combo, DRGSCRL),
    COMBO(easymotion_right_combo, SNIPING),
    COMBO(grave_combo, LT(SYMB, KC_BTN2)),
    COMBO(minus_combo, LT(SYMB, KC_MINUS)),
    };
// clang-format on

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // decide by combo->keycode
    // NOTE: pick a combo low enough to stop skipping characters during typing but
    // high enough that we can still trigger it
    switch (combo->keycode) {
        // tmux prefix: mkdir is a good test string
        case C(KC_UNDERSCORE):
            return 15; // use a short prefix; combo should be pressed at same time
                       // case LT(1, KC_BACKSLASH):
                       // return 15;
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
    switch (combo->keycode) {
        // tmux prefix: make it tap only
        case C(KC_UNDERSCORE):
            return true;
    }

    // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be tap-only, this is for you:
    // uint16_t key;
    // uint8_t  idx = 0;
    // while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
    //     switch (key) {
    //         case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    //         case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
    //         case QK_MOMENTARY ... QK_MOMENTARY_MAX:
    //             return true;
    //     }
    //     idx += 1;
    // }

    // everything else doesn't require a tap
    return false;
}
// #endregion

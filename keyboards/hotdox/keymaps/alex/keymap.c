#include QMK_KEYBOARD_H
#include "version.h"
#include "programmable_button.h"

// #region #defines
#define BASE 0     // default layer
#define SYMB 1     // symbols
#define MDIA 2     // media keys
#define TG_4 TG(4) // keymapceditor bug?
// #endregion

typedef struct {
    bool is_active;
} toggle;

// #endregion

// #region Tapdance definitions
// Tap Dance keycodes
enum td_keycodes {
    SYMB_TAP,     //
    SYMB_TAP_RBRK // same as above, just enters ] on tap
};

// Define a type containing as many tapdance states as you need
typedef enum { TD_NONE, TD_UNKNOWN, TD_SINGLE_TAP, TD_SINGLE_HOLD, TD_DOUBLE_SINGLE_TAP } td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
td_state_t cur_dance(tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void symbtap_finished(tap_dance_state_t *state, void *user_data);
void symbtap_reset(tap_dance_state_t *state, void *user_data);

void symbtaprbrk_finished(tap_dance_state_t *state, void *user_data);
void symbtaprbrk_reset(tap_dance_state_t *state, void *user_data);

//#endregion

enum custom_keycodes { VRSN = SAFE_RANGE, EASYMOTION };

// #region keymap
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*

    [BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRAVE,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_TAB,        MT(MOD_LCTL|MOD_LGUI|MOD_LSFT,KC_Q),         LCAG_T(KC_W),   MT(MOD_LALT|MOD_LGUI|MOD_LSFT,KC_E),   MEH_T(KC_R),   LT(MDIA,KC_T),   TG(SYMB),
        HYPR_T(KC_ESCAPE),        MT(MOD_LCTL|MOD_LGUI,KC_A),         MT(MOD_LALT|MOD_LGUI,KC_S),   SGUI_T(KC_D),   C_S_T(KC_F),   LCA_T(KC_G),
        SC_LSPO,        CTL_T(KC_Z),  GUI_T(KC_X),   ALT_T(KC_C),   MT(MOD_LSFT|MOD_LALT,KC_V),   LCA_T(KC_B),   C(KC_UNDERSCORE),
        LT(SYMB,KC_EQUAL), KC_UNDERSCORE,      EASYMOTION,  KC_LBRC, LT(1,KC_RBRC),
                                                ALT_T(KC_APP),      LT(MDIA,KC_LGUI),
                                                                    DT_UP,
                                LT(3,KC_SPC),   LT(SYMB,KC_BSPC),   EASYMOTION,
         // right hand
        KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
        QK_LEAD,    LT(MDIA,KC_Y),   MEH_T(KC_U),  MT(MOD_RALT|MOD_RGUI|MOD_RSFT,KC_I),   LCAG_T(KC_O),   MT(MOD_RCTL|MOD_RGUI|MOD_RSFT,KC_P),             KC_BSLS,
        LCA_T(KC_H),   C_S_T(KC_J),  SGUI_T(KC_K),   MT(MOD_RALT|MOD_RGUI,KC_L),   MT(MOD_RCTL|MOD_RGUI,KC_SEMICOLON),KC_QUOTE,
        C(KC_UNDERSCORE),LCA_T(KC_N),   MT(MOD_RSFT|MOD_RALT,KC_M),  ALT_T(KC_COMM),GUI_T(KC_DOT), CTL_T(KC_SLSH),   SC_RSPC,
        LT(1,KC_BACKSLASH), C(KC_B),S(KC_INSERT),QK_CAPS_WORD_TOGGLE,          C(S(KC_F12)),
                                                TG_4,                   DT_PRNT,
                                                                        DT_DOWN,
                                    EASYMOTION, LT(SYMB,KC_DELETE),     LT(3,KC_ENT)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * | EEP_RST  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
    [SYMB] = LAYOUT_ergodox(
       // left hand
        KC_CAPS_LOCK,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
        QK_CAPS_WORD_TOGGLE,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PLUS,KC_TRNS,
        KC_GRAVE,KC_HASH,KC_DLR, S(KC_COMMA),S(KC_DOT),KC_MINUS,
        KC_TRNS,CTL_T(KC_PERC),GUI_T(KC_CIRC),ALT_T(KC_LBRC),KC_RBRC,KC_EQUAL,KC_TRNS,
        EE_CLR,KC_TRNS,KC_TRNS,KC_GRV,KC_TILD,
                                        KC_TRNS,KC_TRNS,
                                                KC_TRNS,
                                KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
        KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TRNS, KC_PIPE,   KC_7,   KC_8,    KC_9,    KC_EQUAL, KC_F12,
                KC_EQUAL, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_ENTER,
        KC_TRNS, KC_AMPR, KC_1,   ALT_T(KC_2),    GUI_T(KC_3),    CTL_T(KC_BSLS), KC_TRNS,
                            KC_0,KC_DOT,  KC_0,    KC_ASTR,  KC_TRNS,
                                        KC_TRNS,KC_TRNS,
                                                KC_TRNS,
                                KC_TRNS,KC_TRNS,KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
    [MDIA] = LAYOUT_ergodox(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL2, KC_ACL1, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL2,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                            KC_BTN3, KC_BTN4,
                                                    KC_TRNS,
                                    KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, KC_TRNS, KC_TRNS,
                    KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_TRNS, KC_MPLY,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_MUTE,
                            KC_VOLU, KC_VOLD, KC_MUTE, KC_BRMU, KC_BRMD,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_WBAK
),
    [3] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,QK_CAPS_WORD_TOGGLE,KC_TRANSPARENT,KC_TRANSPARENT,KC_PGDN,KC_FIND,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_CUT,KC_INSERT,KC_PSCR,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_SPACE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_INSERT,KC_PGUP,KC_HOME,KC_END,KC_TRNS,KC_EQUAL,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_BSPC,KC_DELETE,KC_TRANSPARENT,KC_TRNS,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRNS,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

    [4] = LAYOUT_ergodox(KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_LEFT,KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_TRANSPARENT,KC_LCTL,KC_A,KC_S,KC_D,KC_F,KC_G,KC_LSFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_TRANSPARENT,KC_EQUAL,KC_LCTL,KC_LGUI,KC_LALT,KC_ESCAPE,KC_CAPS_LOCK,KC_TRANSPARENT,KC_TRANSPARENT,KC_SPACE,KC_BSPC,KC_TRANSPARENT,KC_RIGHT,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,KC_TRANSPARENT,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BACKSLASH,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOTE,KC_TRNS,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSFT,KC_TRANSPARENT,KC_RALT,KC_RGUI,KC_RCTL,KC_RCTL,TG_4,KC_TRANSPARENT,KC_UP,KC_DOWN,KC_DELETE,KC_ENT),
    [5] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),
    [6] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),
};
// clang-format on
// #endregion

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_C, KC_C)) {
        // copy w/ ctrl+shift+c
        tap_code16(C(S(KC_C)));
    } else if (leader_sequence_two_keys(KC_C, KC_V)) {
        // paste w/ ctrl+shift+v
        tap_code16(C(S(KC_V)));
    } else if (leader_sequence_one_key(KC_ESC)) {
        // capslock key is mapped to esc
        //  shift+caps needed to enable at os level (ahk config on win, xcape on linux)
        tap_code16(S(KC_CAPS_LOCK));
    } else if (leader_sequence_one_key(KC_E)) {
        tap_code16(KC_LBRC);
        tap_code16(S(KC_LBRC));
    } else if (leader_sequence_one_key(KC_R)) {
        tap_code16(KC_RBRC);
        tap_code16(S(KC_RBRC));
    } else if (leader_sequence_one_key(KC_V)) {
        // paste w/ shift+ins
        tap_code16(S(KC_INS));
    }
    // #region fkey sequences
    else if (leader_sequence_one_key(KC_1)) {
        tap_code(KC_F1);
    }

    else if (leader_sequence_one_key(KC_2)) {
        tap_code(KC_F2);
    }

    else if (leader_sequence_one_key(KC_3)) {
        tap_code(KC_F3);
    }

    else if (leader_sequence_one_key(KC_4)) {
        tap_code(KC_F4);
    }

    else if (leader_sequence_one_key(KC_5)) {
        tap_code(KC_F5);
    }

    else if (leader_sequence_one_key(KC_6)) {
        tap_code(KC_F6);
    }

    else if (leader_sequence_one_key(KC_7)) {
        tap_code(KC_F7);
    }

    else if (leader_sequence_one_key(KC_8)) {
        tap_code(KC_F8);
    }

    else if (leader_sequence_one_key(KC_9)) {
        tap_code(KC_F9);
    }

    else if (leader_sequence_one_key(KC_0)) {
        tap_code(KC_F10);
    }

    else if (leader_sequence_one_key(KC_MINS)) {
        tap_code(KC_F11);
    }

    else if (leader_sequence_one_key(KC_BACKSLASH)) {
        tap_code(KC_F12);
    }
    // #endregion
}

// #endregion

// #region process_record_user
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // dynamically generate these.
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
        case EASYMOTION:
            if (record->event.pressed) {
                tap_code(KC_G);
                tap_code(KC_S);
            }
            break;
        case LCTL_T(KC_PERC): // workaround to put mod tap on higher layer
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PERC); // Send KC_DQUO on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case LGUI_T(KC_CIRC): // workaround to put mod tap on higher layer
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_CIRC); // Send KC_DQUO on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
    }
    return true;
}

// #region layer change code
layer_state_t layer_state_set_user(layer_state_t state) {
    // programmable buttons - PG_14 maps to F24 on windows; highest mappable fkey
    // everything else above doesn't get mapped on win
    // toggle until linux compat is figured out
    // switch (get_highest_layer(state)) {
    //   case 4:
    //     // win: F24
    //     tap_code16(PB_14);
    //     break;
    //   case 3:
    //     // win: F23
    //     tap_code16(PB_13);
    //     break;
    //   case MDIA:
    //     // win: F22
    //     tap_code16(PB_12);
    //     break;
    //   case SYMB:
    //     // win: F21
    //     tap_code16(PB_11);
    //     break;
    //   default: //  for any other layers, or the default layer
    //     // win: F20
    //     tap_code16(PB_10);
    //     break;
    // }

    return state;
}

// #region custom tapping termination time implementation
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
            // shift easier to reach, reduce misinterpreting shift+x as (x taps
        case SC_LSPO || SC_RSPC:
            return g_tapping_term - 170;
        case TD(SYMB_TAP): // here just to demo can modify tapdance term too
            return g_tapping_term - 65;
        case TD(SYMB_TAP_RBRK): // here just to demo can modify tapdance term too
            return g_tapping_term - 65;
        default:
            return g_tapping_term;
    }
}
// #endregion

// #region tapdance implementations
// Determine the tapdance state to return
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return TD_SINGLE_TAP;
        else
            return TD_SINGLE_HOLD;
    }

    if (state->count == 2)
        return TD_DOUBLE_SINGLE_TAP;
    else
        return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:

void symbtap_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code(KC_BACKSLASH);
            break;
        case TD_SINGLE_HOLD:
            layer_on(SYMB);
            break;
        case TD_DOUBLE_SINGLE_TAP: // Ctrl+B: tmux prefix
            register_mods(MOD_BIT(KC_LCTL));
            register_code(KC_B);
            break;
        default:
            break;
    }
}

void symbtap_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_BACKSLASH);
            break;
        case TD_SINGLE_HOLD:
            layer_off(SYMB);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_mods(MOD_BIT(KC_LCTL));
            unregister_code(KC_B);
            break;
        default:
            break;
    }
}

void symbtaprbrk_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code(KC_RIGHT_BRACKET);
            break;
        case TD_SINGLE_HOLD:
            layer_on(SYMB);
            break;
        case TD_DOUBLE_SINGLE_TAP: // Ctrl+B: tmux prefix
            register_mods(MOD_BIT(KC_LCTL));
            register_code(KC_B);
            break;
        default:
            break;
    }
}

void symbtaprbrk_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_RIGHT_BRACKET);
            break;
        case TD_SINGLE_HOLD:
            layer_off(SYMB);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_mods(MOD_BIT(KC_LCTL));
            unregister_code(KC_B);
            break;
        default:
            break;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
tap_dance_action_t tap_dance_actions[] = {
    [SYMB_TAP]      = ACTION_TAP_DANCE_FN_ADVANCED(NULL, symbtap_finished, symbtap_reset),
    [SYMB_TAP_RBRK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, symbtaprbrk_finished, symbtaprbrk_reset),
};

//#endregion

// #region combos
const uint16_t PROGMEM tmux_prefix_left_combo[]  = {SGUI_T(KC_D), C_S_T(KC_F), COMBO_END};
const uint16_t PROGMEM tmux_prefix_right_combo[] = {C_S_T(KC_J), SGUI_T(KC_K), COMBO_END};
const uint16_t PROGMEM backslash_left_combo[]    = {SGUI_T(KC_D), C_S_T(KC_F), MT(MOD_LALT | MOD_LGUI, KC_S), COMBO_END};
const uint16_t PROGMEM backslash_right_combo[]   = {C_S_T(KC_J), SGUI_T(KC_K), MT(MOD_RALT | MOD_RGUI, KC_L), COMBO_END};
combo_t                key_combos[COMBO_COUNT]   = {
                     COMBO(tmux_prefix_left_combo, C(KC_UNDERSCORE)),
                     COMBO(tmux_prefix_right_combo, C(KC_UNDERSCORE)),
                     COMBO(backslash_left_combo, LT(1, KC_BACKSLASH)),
                     COMBO(backslash_right_combo, LT(1, KC_BACKSLASH)),
};

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

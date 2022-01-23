#include QMK_KEYBOARD_H
#include "version.h"

// #region #defines
#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define TG_4 TG(4) //keymapceditor bug?
// #endregion

// #region Split Toggle macro definitions
void split_toggle(void);
void split_left(void);
void split_right(void);

typedef struct {
  bool is_active;
} toggle;

// #endregion

// #region Tapdance definitions
typedef struct {
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7,
};

//Tap dance enums
enum {
  CT_CLN = 0,
  CT_QUOT = 1,
};

int cur_dance (qk_tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void ct_cln_finished (qk_tap_dance_state_t *state, void *user_data);
void ct_cln_reset (qk_tap_dance_state_t *state, void *user_data);
void ct_quot_finished (qk_tap_dance_state_t *state, void *user_data);
void ct_quot_reset (qk_tap_dance_state_t *state, void *user_data);

//#endregion

enum custom_keycodes {
  VRSN = SAFE_RANGE,
  SPLIT_TOGGLE,
  SPLIT_LEFT,
  SPLIT_RIGHT,
  EASYMOTION
};

// #region keymap 
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
        KC_TAB,        ALL_T(KC_Q),         LCAG_T(KC_W),   MT(MOD_LCTL|MOD_LGUI|MOD_LSFT,KC_E),   MEH_T(KC_R),   LT(MDIA,KC_T),   TG(SYMB),
        HYPR_T(KC_ESCAPE),        MT(MOD_LCTL|MOD_LGUI,KC_A),         MT(MOD_LALT|MOD_LGUI,KC_S),   SGUI_T(KC_D),   C_S_T(KC_F),   LCA_T(KC_G),
        KC_LSPO,        CTL_T(KC_Z),  GUI_T(KC_X),   ALT_T(KC_C),   MT(MOD_LSFT|MOD_LALT,KC_V),   LCA_T(KC_B),   SPLIT_LEFT,
        LT(SYMB,KC_EQUAL), KC_UNDERSCORE,      KC_LBRACKET,  KC_RBRACKET, LT(SYMB,KC_KP_PLUS),
                                              ALT_T(KC_APP),  LT(MDIA,KC_LGUI),
                                                              KC_HOME,
                                               LT(3,KC_SPC),LT(SYMB,KC_BSPC),EASYMOTION,
         // right hand
             KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(SYMB),    LT(MDIA,KC_Y),   MEH_T(KC_U),  MT(MOD_LCTL|MOD_LGUI|MOD_LSFT,KC_I),   LCAG_T(KC_O),   ALL_T(KC_P),             KC_BSLS,
                          LCA_T(KC_H),   C_S_T(KC_J),  SGUI_T(KC_K),   MT(MOD_LALT|MOD_LGUI,KC_L),   MT(MOD_LCTL|MOD_LGUI,KC_SCOLON),KC_QUOTE,
             SPLIT_RIGHT,LCA_T(KC_N),   MT(MOD_LSFT|MOD_LALT,KC_M),  RALT_T(KC_COMM),RGUI_T(KC_DOT), CTL_T(KC_SLSH),   KC_RSPC,
                                  LT(SYMB,KC_BSLASH), KC_LEAD,S(KC_INSERT),S(KC_CAPSLOCK),          C(S(KC_F12)),
             TG_4,        CTL_T(KC_ESC),
             KC_PGUP,
             EASYMOTION,LT(SYMB,KC_DELETE),LT(3,KC_ENT)
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
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_GRAVE,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_CAPSLOCK,KC_HASH,KC_DLR, S(KC_COMMA),S(KC_DOT),KC_MINUS,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_EQUAL,KC_TRNS,
       EEP_RST,KC_TRNS,KC_TRNS,KC_GRV,KC_TILD,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_EQUAL, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_ENTER,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_ASTR,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
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
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
 [3] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_CAPSLOCK,KC_TRANSPARENT,KC_TRANSPARENT,KC_PGDOWN,KC_FIND,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_CUT,KC_INSERT,KC_PSCREEN,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_SPACE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_INSERT,KC_PGUP,KC_HOME,KC_END,KC_TRNS,KC_EQUAL,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_BSPACE,KC_DELETE,KC_TRANSPARENT,KC_TRNS,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRNS,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

 [4] = LAYOUT_ergodox(KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_LEFT,KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_TRANSPARENT,KC_LCTRL,KC_A,KC_S,KC_D,KC_F,KC_G,KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_TRANSPARENT,KC_EQUAL,KC_LCTRL,KC_LGUI,KC_LALT,KC_ESCAPE,KC_CAPSLOCK,KC_TRANSPARENT,KC_TRANSPARENT,KC_SPACE,KC_BSPC,KC_TRANSPARENT,KC_RIGHT,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,KC_TRANSPARENT,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_QUOTE,KC_TRNS,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSHIFT,KC_TRANSPARENT,KC_RALT,KC_RGUI,KC_RCTRL,KC_RCTRL,TG_4,KC_TRANSPARENT,KC_UP,KC_DOWN,KC_DELETE,KC_ENT),
 [5] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),
 [6] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),
};

// #endregion

// #region matrix methods (incl leader key config)
// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

LEADER_EXTERNS();
// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  LEADER_DICTIONARY() {
    leading = false;

    SEQ_ONE_KEY(KC_ESC) {
      //capslock key is mapped to esc
      // shift+caps needed to enable at os level (ahk config on win, xcape on linux)
        tap_code16(S(KC_CAPSLOCK));
    }

    SEQ_ONE_KEY(KC_E) {
        tap_code16(KC_LBRC);
        tap_code16(S(KC_LBRC));
    }
    SEQ_ONE_KEY(KC_R) {
        tap_code16(KC_RBRC);
        tap_code16(S(KC_RBRC));
    }

    SEQ_ONE_KEY(KC_V) {
      //paste w/ shift+ins
        tap_code16(S(KC_INS));
    }

    SEQ_TWO_KEYS(KC_C, KC_C) {
      //copy w/ ctrl+shift+c
        tap_code16(C(S(KC_C)));
    }

    SEQ_TWO_KEYS(KC_C, KC_V) {
      //paste w/ ctrl+shift+v
        tap_code16(C(S(KC_V)));
    }

    // #region fkey sequences
    SEQ_ONE_KEY(KC_1) {
        tap_code(KC_F1);
    }

    SEQ_ONE_KEY(KC_2) {
        tap_code(KC_F2);
    }

    SEQ_ONE_KEY(KC_3) {
        tap_code(KC_F3);
    }

    SEQ_ONE_KEY(KC_4) {
        tap_code(KC_F4);
    }

    SEQ_ONE_KEY(KC_5) {
        tap_code(KC_F5);
    }

    SEQ_ONE_KEY(KC_6) {
        tap_code(KC_F6);
    }

    SEQ_ONE_KEY(KC_7) {
        tap_code(KC_F7);
    }

    SEQ_ONE_KEY(KC_8) {
        tap_code(KC_F8);
    }

    SEQ_ONE_KEY(KC_9) {
        tap_code(KC_F9);
    }

    SEQ_ONE_KEY(KC_0) {
        tap_code(KC_F10);
    }

    SEQ_ONE_KEY(KC_MINS) {
        tap_code(KC_F11);
    }

    SEQ_ONE_KEY(KC_BSLASH) {
        tap_code(KC_F12);
    }
    // #endregion

    leader_end();
  }
};

// #endregion

// #region process_record_user

static toggle split_toggle_state = {
  .is_active = false,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case SPLIT_TOGGLE:
      if (record->event.pressed) {
        split_toggle_state.is_active = split_toggle_state.is_active ? false : true;

        split_toggle();
      }
      return false;
      break;
    case SPLIT_LEFT:
      if (record->event.pressed) {
        split_left();
      }
      return false;
      break;
    case SPLIT_RIGHT:
      if (record->event.pressed) {
        split_right();
      }
      return false;
      break;
    case EASYMOTION:
      if (record->event.pressed) {
        tap_code(KC_G);
        tap_code(KC_S);
      }
      break;

  }
  return true;
}

// #endregion

// #region layer change code
layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case 4:
      tap_code16(KC_F24);
      break;
    case 3:
      tap_code16(KC_F23);
      break;
    case MDIA:
      tap_code16(KC_F22);
      break;
    case SYMB:
      tap_code16(KC_F21);
      break;
    default: //  for any other layers, or the default layer
      tap_code16(KC_F20);
      break;
  }

  return state;
}


// #region custom tapping termination time implementation
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // shift easier to reach, reduce misinterpreting shift+x as (x taps
    case KC_LSPO || KC_RSPC:
      return TAPPING_TERM - 90;
    default:
      return TAPPING_TERM;
  }
}
// #endregion

// #region tapdance implementations
/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currently not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

// #region ct_cln fns : single, ; double
//instantiate an instance of 'tap' for the 'x' tap dance.
static tap cln_tap = {
  .state = 0
};

void ct_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
  cln_tap.state = cur_dance(state);
  switch (cln_tap.state) {
    case SINGLE_TAP: register_code(KC_SCLN); break;
    case SINGLE_HOLD: register_mods(MOD_LCTL | MOD_LGUI); break;
    case DOUBLE_TAP: register_code16(S(KC_SCLN)); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_SCLN); unregister_code(KC_SCLN); register_code(KC_SCLN);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
    }
}

void ct_cln_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (cln_tap.state) {
    case SINGLE_TAP: unregister_code(KC_SCLN); break;
    case SINGLE_HOLD: unregister_mods(MOD_LCTL | MOD_LGUI); break;
    case DOUBLE_TAP: unregister_code16(S(KC_SCLN)); break;
    case DOUBLE_SINGLE_TAP: unregister_code(KC_SCLN);
  }
  cln_tap.state = 0;
}
// #endregion

// #region ct_quot fns(; ' single, "" double
void ct_quot_finished (qk_tap_dance_state_t *state, void *user_data) {
  switch (cur_dance(state)) {
    case SINGLE_TAP: register_code(KC_QUOTE); break;
    case DOUBLE_TAP: register_code16(S(KC_QUOTE)); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_QUOTE); unregister_code(KC_QUOTE); register_code(KC_QUOTE);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void ct_quot_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (cur_dance(state)) {
    case SINGLE_TAP: unregister_code(KC_QUOTE); break;
    case DOUBLE_TAP: unregister_code16(S(KC_QUOTE)); break;
    case DOUBLE_SINGLE_TAP: unregister_code(KC_QUOTE);
  }
}


// #endregion

qk_tap_dance_action_t tap_dance_actions[] = {
  [CT_CLN]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,ct_cln_finished, ct_cln_reset),
  [CT_QUOT]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,ct_quot_finished, ct_quot_reset),
};
//#endregion


// #region macro helpers

// #region Split toggle macro helpers
void split_toggle() {
  if (split_toggle_state.is_active) {
      tap_code16(G(KC_UP));
      tap_code16(G(KC_UP));
      tap_code16(G(KC_LEFT));
      tap_code16(C(G(KC_L)));
      tap_code16(G(KC_UP));
      tap_code16(G(KC_UP));
      tap_code16(G(KC_RIGHT));
      tap_code16(C(G(KC_H)));
  } else {
      tap_code16(G(KC_UP));
      tap_code16(G(KC_UP));
      tap_code16(C(G(KC_L)));
      tap_code16(G(KC_UP));
      tap_code16(G(KC_UP));
      tap_code16(C(G(KC_H)));
  }
}

void split_left() {
  if (split_toggle_state.is_active) {
      tap_code16(G(KC_UP));
      tap_code16(G(KC_UP));
      tap_code16(C(G(KC_L)));
      tap_code16(G(KC_UP));
      tap_code16(G(KC_UP));
      tap_code16(C(G(KC_H)));
      tap_code16(G(KC_RIGHT));
      tap_code16(C(G(KC_H)));
      tap_code16(G(KC_LEFT));
  } else {
      tap_code16(C(G(KC_H)));
  }
}

void split_right() {
  if (split_toggle_state.is_active) {
      tap_code16(G(KC_UP));
      tap_code16(G(KC_UP));
      tap_code16(C(G(KC_L)));
      tap_code16(G(KC_UP));
      tap_code16(G(KC_UP));
      tap_code16(G(KC_LEFT));
      tap_code16(C(G(KC_L)));
      tap_code16(G(KC_RIGHT));
      tap_code16(C(G(KC_H)));
  } else {
      tap_code16(C(G(KC_L)));
  }
}

// #endregion 

// #endregion 
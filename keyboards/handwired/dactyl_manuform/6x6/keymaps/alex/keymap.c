
#include QMK_KEYBOARD_H

#define BASE 0   // default layer
#define SYMB 1   // symbols
#define CUSTOM 2 // symbols
#define MOUSE 3  // mouse keys
#define FNUM 4  // mouse keys

enum custom_keycodes { EASYMOTION = SAFE_RANGE };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_6x6(
     KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
     KC_GRAVE , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
     HYPR_T(KC_TAB) , MT(MOD_LCTL|MOD_LGUI|MOD_LSFT,KC_Q)  , LCAG_T(KC_W)  , MT(MOD_LALT|MOD_LGUI|MOD_LSFT,KC_E)  , MEH_T(KC_R)  , LT(MOUSE, KC_T)  ,                         LT(MOUSE, KC_Y)  , MEH_T(KC_U)  , MT(MOD_RALT|MOD_RGUI|MOD_RSFT,KC_I)  , LCAG_T(KC_O)  , MT(MOD_RCTL|MOD_RGUI|MOD_RSFT,KC_P)  ,KC_BSLS,
     HYPR_T(KC_ESCAPE), MT(MOD_LCTL|MOD_LGUI,KC_A)  , MT(MOD_LALT|MOD_LGUI,KC_S)  , SGUI_T(KC_D)  , C_S_T(KC_F)  , LCA_T(KC_G)  ,                         LCA_T(KC_H)  , C_S_T(KC_J)  , SGUI_T(KC_K)  , MT(MOD_RALT|MOD_RGUI,KC_L)  ,MT(MOD_RCTL|MOD_RGUI,KC_SEMICOLON),HYPR_T(KC_QUOTE),
     SC_LSPO, CTL_T(KC_Z)  , GUI_T(KC_X)  , ALT_T(KC_C)  , SFT_T(KC_V)  , MT(MOD_LSFT|MOD_LALT,KC_B)  ,                         MT(MOD_RSFT|MOD_RALT,KC_N)  , SFT_T(KC_M)  ,ALT_T(KC_COMMA),GUI_T(KC_DOT) ,CTL_T(KC_SLASH),SC_RSPC,
                      KC_LBRC,LT(MOUSE, KC_RBRC),                                                       KC_PLUS, KC_EQL,
                                      LT(CUSTOM,KC_SPC),LT(SYMB,KC_BSPC),                        LT(SYMB,KC_DELETE), LT(CUSTOM,KC_ENT),
                                      EASYMOTION,KC_UNDERSCORE,                         KC_END,  EASYMOTION,
                                      KC_GRAVE, KC_MINUS,                        KC_LGUI, KC_LALT
  ),

  [SYMB] = LAYOUT_6x6(
     KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
     KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
     QK_CAPS_WORD_TOGGLE,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PLUS,                        KC_PLUS, KC_7 , KC_8 , KC_9 ,_______,KC_PLUS,
     KC_GRAVE,KC_GRAVE,KC_TILD,S(KC_COMMA),S(KC_DOT) ,KC_MINUS,                        KC_MINUS, KC_4 , KC_5 , KC_6 ,KC_MINS,KC_PIPE,
     _______,S(KC_9),S(KC_0),ALT_T(KC_LBRC),KC_RBRC,KC_EQUAL,                        KC_EQUAL, KC_1 , KC_2 , KC_3 ,KC_EQL ,KC_UNDS,
                                        QK_BOOT,  KC_PSCR,                            _______, KC_P0,
                                             _______,_______,            _______,KC_0,
                                             _______,_______,            _______,_______,
                                             QK_BOOT,_______,            QK_BOOT,_______
  ),

  [CUSTOM] = LAYOUT_6x6(

       KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       KC_F12,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,                        KC_F6,KC_F7,KC_F8,KC_F9 ,KC_F10,KC_F11,
       KC_MNXT,KC_TAB,_______  ,_______,_______,_______,                        KC_INSERT,KC_PGUP,KC_HOME,KC_END,KC_VOLU,KC_F12,
       KC_MPLY,KC_ESCAPE,_______,KC_PGDN,KC_FIND,_______,                        KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,KC_MUTE,KC_BRMU,
       KC_MPRV,_______,_______,KC_CUT,_______,KC_PSCR,                        _______,_______,_______,QK_CAPS_WORD_TOGGLE,KC_VOLD,KC_BRMD,

                                               QK_BOOT,  EE_CLR,            KC_EQL ,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______,
                                               QK_BOOT,_______,            QK_BOOT,_______
  ),
 [MOUSE] = LAYOUT_6x6(
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_ACL0,KC_ACL1,KC_ACL2,KC_TRANSPARENT,KC_TRANSPARENT,         KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,      KC_MS_WH_LEFT,KC_MS_WH_DOWN,KC_MS_WH_UP,KC_MS_WH_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,      KC_MS_LEFT,KC_MS_DOWN,KC_MS_UP,KC_MS_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,
        KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT, KC_ACL2      ,KC_TRANSPARENT,      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
                                KC_ACL0,KC_TRANSPARENT,                             KC_TRANSPARENT,QK_BOOT,
                                            KC_BTN2,KC_BTN1,                     KC_ACL0,KC_ACL2,
                                                KC_ACL2,KC_BTN3,               KC_TRANSPARENT,KC_ACL1,
                                                KC_TRANSPARENT,KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT
  ),
 [FNUM] = LAYOUT_6x6(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_TRANSPARENT,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_F12,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

};
// clang-format on

// https://docs.qmk.fm/#/feature_advanced_keycodes?id=shift-backspace-for-delete
#define SBSPC LT(SYMB,KC_BSPC)
// Variable to track the key state and timing
static uint16_t gs_toggle_timer;
static bool is_held_with_other = false;
static bool kc_key_held = false;  // To track if the key was held or not
// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {
        case SBSPC: {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
            if (record->tap.count > 0) { // only act on tap
                static bool delkey_registered;
                if (record->event.pressed) {
                    // Detect the activation of either shift keys
                    if (mod_state & MOD_MASK_SHIFT) {
                        // First temporarily canceling both shifts so that
                        // shift isn't applied to the KC_DEL keycode
                        del_mods(MOD_MASK_SHIFT);
                        register_code(KC_DEL);
                        // Update the boolean variable to reflect the status of KC_DEL
                        delkey_registered = true;
                        // Reapplying modifier state so that the held shift key(s)
                        // still work even after having tapped the Backspace/Delete key.
                        set_mods(mod_state);
                        return false;
                    }
                } else { // on release of KC_BSPC
                    // In case KC_DEL is still being sent even after the release of KC_BSPC
                    if (delkey_registered) {
                        unregister_code(KC_DEL);
                        delkey_registered = false;
                        return false;
                    }
                }
            }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
        }
        case EASYMOTION:
            if (record->event.pressed) {
                // Key is pressed, start the timer and reset the flag
                gs_toggle_timer = timer_read();
                is_held_with_other = false;
                kc_key_held = true;
            } else {
                // Key is released, check how long it was held and if it was combined with another key
                if (timer_elapsed(gs_toggle_timer) < TAPPING_TERM && !is_held_with_other) {
                    // It was a tap, send 'g' and 's'
                    tap_code(KC_G);
                    tap_code(KC_S);
                } else if (is_held_with_other) {
                    // Key was held with another key, so toggle off the layer 4
                    layer_off(FNUM);
                } else {
                    // It was held without other keys, activate one-shot layer
                    set_oneshot_layer(FNUM, ONESHOT_START);
                }
                kc_key_held = false;
            }
            return false; // Skip all further processing for this key
        default:
            if (record->event.pressed) {
                if (keycode != EASYMOTION && kc_key_held) {
                    // Another key was pressed while EASYMOTION was held
                    is_held_with_other = true;
                    // Toggle on layer FNUM
                    layer_on(FNUM);
                }
            } else if (keycode != EASYMOTION) {
                // Another key was released, possibly clear the one-shot layer if needed
                // clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
            return true; // Process all other keys normally
    }
    return true;
}


// TODO: adapt macro keys
// TODO: add boot button on both sides (test one sided right hand can flash with boot button)
// TODO; consider snippets/macros for combos

// #region combos
// left thumb left most 2 buttons sideways
const uint16_t PROGMEM thumb_side_l[]             = {LT(CUSTOM, KC_SPC), LT(SYMB, KC_BSPC), COMBO_END};
// right thumb right most 2 buttons sideways
const uint16_t PROGMEM thumb_side_r[]             = {LT(CUSTOM, KC_ENT), LT(SYMB, KC_DELETE), COMBO_END};
// left thumb vert
const uint16_t PROGMEM thumb_vert_l[]  = {LT(SYMB, KC_BSPC), EASYMOTION, COMBO_END};
// right thumb vert
const uint16_t PROGMEM thumb_vert_r[] = {LT(SYMB, KC_DELETE), EASYMOTION, COMBO_END};
const uint16_t PROGMEM backslash_left_combo[]    = {SGUI_T(KC_D), C_S_T(KC_F), COMBO_END};
const uint16_t PROGMEM backslash_right_combo[]   = {C_S_T(KC_J), SGUI_T(KC_K), COMBO_END};
// index finger left + right key
const uint16_t PROGMEM index_l_r[]            = {C_S_T(KC_F), C_S_T(KC_J), COMBO_END};
const uint16_t PROGMEM thumb_closest_l_r[]              = {LT(CUSTOM, KC_SPC), LT(CUSTOM, KC_ENT), COMBO_END};
const uint16_t PROGMEM middle_l_r[]        = {SGUI_T(KC_D), SGUI_T(KC_K), COMBO_END};
const uint16_t PROGMEM angle_right_combo[]       = {SGUI_T(KC_K), MT(MOD_RALT | MOD_RGUI, KC_L), COMBO_END};
const uint16_t PROGMEM brace_left_combo[]        = {MT(MOD_LALT | MOD_LGUI | MOD_LSFT, KC_E), LCAG_T(KC_W), COMBO_END};
const uint16_t PROGMEM brace_right_combo[]       = {MT(MOD_LALT | MOD_LGUI | MOD_LSFT, KC_I), LCAG_T(KC_O), COMBO_END};
const uint16_t PROGMEM easymotion_left_combo[]   = {ALT_T(KC_C), SFT_T(KC_V), COMBO_END};
const uint16_t PROGMEM index_lower_l_r[]  = {SFT_T(KC_V), SFT_T(KC_M), COMBO_END};

// clang-format off
// TODO: rename variables
// TODO: inroduce left 2 button combo // put scroll there, put snipe in existing scroll
// put -/_/=/+ on space layer
combo_t key_combos[COMBO_COUNT] = {
    COMBO(thumb_vert_l, KC_BTN1),
    COMBO(thumb_vert_r, LT(SYMB, KC_QUOTE)),
    COMBO(backslash_left_combo, LT(SYMB, KC_BACKSLASH)),
    COMBO(backslash_right_combo, LT(SYMB, KC_BACKSLASH)),
    COMBO(index_l_r, LT(SYMB, KC_ESCAPE)),
    COMBO(thumb_closest_l_r, QK_CAPS_WORD_TOGGLE),
    COMBO(middle_l_r, C(KC_UNDERSCORE)),
    COMBO(angle_right_combo, C(KC_UNDERSCORE)),
    COMBO(brace_left_combo, KC_MINUS),
    COMBO(brace_right_combo, KC_RCBR),
    COMBO(easymotion_left_combo, KC_BTN3),
    COMBO(index_lower_l_r, HYPR_T(KC_TAB)),
    COMBO(thumb_side_l, HYPR_T(KC_UNDERSCORE)),
    COMBO(thumb_side_r, HYPR_T(KC_MINUS)),
    };
// clang-format on


uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // decide by combo->keycode
    // NOTE: pick a combo low enough to stop skipping characters during typing but
    // high enough that we can still trigger it
    // switch (combo->keycode) {
    //     // tmux prefix: mkdir is a good test string
    //     case C(KC_UNDERSCORE):
    //         return 15; // use a short prefix; combo should be pressed at same time
    //                    // case LT(1, KC_BACKSLASH):
    //                    // return 15;
    // }

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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
            // shift easier to reach, reduce misinterpreting shift+x as (x taps
        case SC_LSPO || SC_RSPC:
            return TAPPING_TERM - 170;
        default:
            return TAPPING_TERM;
    }
}


// hit keys that should be configured on OS level to change a key indicator
layer_state_t layer_state_set_user(layer_state_t state) {
    // F14/F15 are brightup/down on macos
    switch (get_highest_layer(state)) {
    case BASE:
        SEND_STRING(SS_TAP(X_F16));
        break;
    case CUSTOM:
        SEND_STRING(SS_TAP(X_F17));
        break;
    case SYMB:
        SEND_STRING(SS_TAP(X_F18));
        break;
    case MOUSE:
        SEND_STRING(SS_TAP(X_F19));
        break;
    default: //  for any other layers, or the default layer
        // F14/F15 are brightup/down on macos
        SEND_STRING(SS_TAP(X_F13));
        break;
    }
    return state;
}

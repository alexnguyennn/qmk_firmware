/*
Copyright 2017 Balz Guenat <balz.guenat@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// #region keymap 
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /* 0: plain Qwerty without layer switching
     *         ,---------------. ,---------------. ,---------------.
     *         |F13|F14|F15|F16| |F17|F18|F19|F20| |F21|F22|F23|F24|
     * ,---.   |---------------| |---------------| |---------------| ,-----------. ,---------------. ,-------.
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau| |VDn|VUp|Mut|Pwr| | Help  |
     * `---'   `---------------' `---------------' `---------------' `-----------' `---------------' `-------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------. ,-------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -| |Stp|Agn|
     * |-----------------------------------------------------------| |-----------| |---------------| |-------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +| |Mnu|Und|
     * |-----------------------------------------------------------| `-----------' |---------------| |-------|
     * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  #|Retn|               |  4|  5|  6|KP,| |Sel|Cpy|
     * |-----------------------------------------------------------|     ,---.     |---------------| |-------|
     * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /| RO|Shift |     |Up |     |  1|  2|  3|KP=| |Exe|Pst|
     * |-----------------------------------------------------------| ,-----------. |---------------| |-------|
     * |Ctl|Gui|Alt|MHEN|HNJ| Space  |H/E|HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |  0    |  .|Ent| |Fnd|Cut|
     * `-----------------------------------------------------------' `-----------' `---------------' `-------'
     */
    [0] = LAYOUT_all(
                      KC_F13,  KC_F14,  KC_F15,  KC_F16, KC_F17, KC_F18, KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,               KC_PSCR, KC_SLCK, KC_PAUS,    KC_VOLD, KC_VOLU, KC_MUTE, KC_PWR,     KC_HELP,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_JYEN, KC_BSPC,     KC_INS,  KC_HOME, KC_PGUP,    KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,    KC_STOP, KC_AGIN,
    KC_TAB,  LCAG_T(KC_Q),    MEH_T(KC_W),    ALL_T(KC_E),    KC_R,    KC_T,   KC_Y,   KC_U,   ALL_T(KC_I),    MEH_T(KC_O),    LCAG_T(KC_P),    KC_LBRC, KC_RBRC,          KC_BSLS,     KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,    KC_MENU, KC_UNDO,
    HYPR_T(KC_ESCAPE), MT(MOD_LCTL|MOD_LGUI,KC_A),    MT(MOD_LALT|MOD_LGUI,KC_S),    SGUI_T(KC_D),    C_S_T(KC_F),    LCA_T(KC_G),   LCA_T(KC_H),   C_S_T(KC_J),   SGUI_T(KC_K),    MT(MOD_LALT|MOD_LGUI,KC_L),    MT(MOD_LCTL|MOD_LGUI,KC_SCLN), KC_QUOT,          KC_NUHS, KC_SFTENT,                                    KC_P4,   KC_P5,   KC_P6,   KC_PCMM,    KC_SLCT, KC_COPY,
    KC_LSPO, KC_NUBS, MT(MOD_LCTL, KC_Z),    MT(MOD_LGUI, KC_X),    MT(MOD_LALT, KC_C),    MT(MOD_LSFT|MOD_LALT,KC_V),   MT(MOD_LSFT|MOD_LALT,KC_B),   LCA_T(KC_N),   MT(MOD_LSFT|MOD_LALT,KC_M),    MT(MOD_RALT, KC_COMM), MT(MOD_RGUI, KC_DOT),  MT(MOD_RCTL, KC_SLSH),          KC_RO,   KC_RSPC,              KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PEQL,    KC_EXEC, KC_PSTE,
    MT(MOD_LCTL, KC_EQL), KC_LGUI, MT(MOD_LALT, KC_BSPC), KC_MHEN, KC_HANJ,         LT(1, KC_SPC),         KC_HAEN, KC_HENK, KC_KANA, MT(MOD_RALT, KC_DELETE), MT(MOD_RGUI, KC_LEAD), KC_APP,  KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT, KC_PENT,    KC_FIND, KC_CUT
    ),

    /* 1: SpaceFN edited
     * ,-----------------------------------------------------------.
     * |`  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Delete |
     * |-----------------------------------------------------------|
     * |Caps |   |   |Esc|   |   |   |PgU|Hom|End|   |   |Pau|Ins  |
     * |-----------------------------------------------------------|
     * |      |   |   |PgD|   |   |Lef|Dow|Up|Righ|   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |Spc|   |`  |~  |   |Men|          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     */
    [1] = LAYOUT_all(
              KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,          KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,
    KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_TRNS,KC_DEL,      KC_MPRV,KC_MNXT,KC_MPLY,    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_ESC, KC_TRNS,KC_TRNS,KC_TRNS,KC_PGUP,KC_HOME,  KC_END, KC_TRNS,KC_TRNS,KC_PAUS,     KC_INS,      KC_VOLD,KC_VOLU,KC_MUTE,    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,
    S(KC_CAPS),KC_MS_BTN1,KC_MS_BTN2,KC_PGDN,KC_TRNS,KC_TRNS,KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,KC_TRNS,KC_BSPACE,     KC_TRNS,KC_DELETE,                        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,
    KC_TRNS,KC_MS_WH_LEFT,KC_MS_WH_DOWN,KC_MS_WH_UP,KC_MS_WH_RIGHT,KC_ACL1,KC_SPC,KC_MS_LEFT,KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT,KC_APP,      KC_TRNS,KC_TRNS,          KC_TRNS,         KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,     KC_TRNS,KC_TRNS,    KC_TRNS, KC_TRNS
    ),

};
// #endregion

// #region matrix methods (incl leader key config)
void matrix_init_user(void) {

}

// leader is pretty expensive on memory..
LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;

    SEQ_ONE_KEY(KC_ESC) {
      //capslock key is mapped to esc
      // shift+caps needed to enable at os level (ahk config on win, xcape on linux)
        tap_code16(S(KC_CAPSLOCK));
    }

    SEQ_ONE_KEY(KC_V) {
      //paste w/ shift+ins
        tap_code16(S(KC_INS));
    }
    leader_end();
  } 

}

// #endregion

// #region user callbacks
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}

// #endregion

// #region layer change code
// Assumes gui layer visualisation are hooked up to these keycodes
layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case 1:
      tap_code16(KC_F23);
      break;
    default: //  for any other layers, or the default layer
      tap_code16(KC_F20);
      break;
  }

  return state;
}


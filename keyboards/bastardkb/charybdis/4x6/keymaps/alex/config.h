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
#pragma once

#ifdef VIA_ENABLE
/* VIA configuration. */
#    define DYNAMIC_KEYMAP_LAYER_COUNT 4
#endif // VIA_ENABLE

/* Disable unused features. */
#define NO_ACTION_ONESHOT

/* Charybdis-specific features. */

#ifdef POINTING_DEVICE_ENABLE
// Automatically enable the pointer layer when moving the trackball.  See also:
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif // POINTING_DEVICE_ENABLE

// define how many combos are in our map
#define COMBO_COUNT 14
#define COMBO_MUST_TAP_PER_COMBO

#define COMBO_TERM_PER_COMBO
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 500
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 0
#define CHARYBDIS_MINIMUM_DEFAULT_DPI 750
#define CHARYBDIS_MINIMUM_SNIPING_DPI 400
#define CHARYBDIS_SNIPING_DPI_CONFIG_STEP 100

#define CHARYBDIS_DRAGSCROLL_REVERSE_Y

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 3000 // 5 seconds is the default.

#undef TAPPING_TERM
// #define TAPPING_TERM    425
#define TAPPING_TERM 200

#define TAPPING_TERM_PER_KEY

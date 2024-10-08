/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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


#pragma once


#define USE_SERIAL

#define MASTER_LEFT
// #define MASTER_RIGHT
//#define EE_HANDS
// Rows are doubled-up

/* Disable unused features. */
// #define NO_ACTION_ONESHOT

#define COMBO_COUNT 14
#define COMBO_MUST_TAP_PER_COMBO

#define COMBO_TERM_PER_COMBO

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 3000 // 5 seconds is the default.

#undef TAPPING_TERM
// #define TAPPING_TERM    425
#define TAPPING_TERM 200

#define TAPPING_TERM_PER_KEY

// constant speed ]config
#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
// start accel, buttons constant
// #define MK_COMBINED

#define ONESHOT_TAP_TOGGLE 4  /* Tapping this number of times holds the key until tapped once again. */

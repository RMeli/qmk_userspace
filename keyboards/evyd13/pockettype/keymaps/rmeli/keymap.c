/* Copyright 2019 Evy Dekkers
 * Copyright 2022 Rocco Meli
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

#include "rmeli.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _MA 0 //Main layer
#define _LO 1 //Low
#define _HI 2 //High

// clang-format off
#define ____________________BOTTOM_L_x6_____________________ XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, MO(_LO),  KC_SPC
#define ____________________BOTTOM_R_x6_____________________  KC_ENT, MO(_HI), KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT
// clang-format on

#define LAYOUT_wrapper(...) LAYOUT_ortho_4x12(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MA] = LAYOUT_wrapper(
    ___________________QWERTY_L1_x6_____________________, ___________________QWERTY_R1_x6_____________________,
    ___________________QWERTY_L2_x6_____________________, ___________________QWERTY_R2_x6_____________________,
    ___________________QWERTY_L3_x6_____________________, ___________________QWERTY_R3_x6_____________________,
    ____________________BOTTOM_L_x6_____________________, ____________________BOTTOM_R_x6_____________________
  ),

  [_LO] = LAYOUT_wrapper(
    ___________________NUMBER_LEFT_x6___________________, ___________________NUMBER_RIGHT_x6__________________,
    _______, ______________UNICODE_L2_x5________________, ________________NAV_R2_x5__________________, XXXXXXX,
    _______, ______________UNICODE_L3_x5________________, ________________NAV_R3_x5__________________, _______,
    ______________________BLANK_6x______________________, ______________________BLANK_6x______________________
  ),

  [_HI] = LAYOUT_wrapper(
    ___________________SYMBOL_LEFT_x6___________________, ___________________SYMBOL_RIGHT_x6__________________,
    _______, ____________NAV_VIM_x4____________, XXXXXXX, ____________________SYMBOL_R2_x6____________________,
    QK_BOOT, _________________NONE_5x___________________, ____________________SYMBOL_R3_x6____________________,
    ______________________BLANK_6x______________________, ______________________BLANK_6x______________________
  ),
};
// clang-format on
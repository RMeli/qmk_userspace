/* Copyright 2020 gtips
 * Copyright 2022 Rocco Meli <@RMeli>
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

enum layer_names { _QWERTY, _COLEMAK_DH, _LOWER, _RAISE, _ADJUST };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

// Layer names shortcuts
#define _QWY 0
#define _CMK 1

#define ________________THUMB_CLUSTER______________ KC_LGUI, LOWER, TD_SE, RAISE, KC_RCTL

// LAYOUT
//
// |-----------------------------|        |-----------------------------|
// |    |    |    |    |    |    |        |    |    |    |    |    |    |
// |----+----+----+----+----+----|        |----+----+----+----+----+----|
// |    |    |    |    |    |    |        |    |    |    |    |    |    |
// |----+----+----+----+----+----|        |----+----+----+----+----+----|
// |    |    |    |    |    |    |        |    |    |    |    |    |    |
// |----+----+----+----+----+----+--------+----+----+----+----+----+----|
//                     |    |    |        |    |    |
//                     |----------------------------|

#define LAYOUT_wrapper(...) LAYOUT_reviung41(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    ___________________QWERTY_L1_x6_____________________,                 ___________________QWERTY_R1_x6_____________________,
    ___________________QWERTY_L2_x6_____________________,                 ___________________QWERTY_R2_x6_____________________,
    ___________________QWERTY_L3_x6_____________________,                 ___________________QWERTY_R3_x6_____________________,
                                           ________________THUMB_CLUSTER______________
  ),

  [_COLEMAK_DH] = LAYOUT_wrapper(
    ________________COLEMAK_MOD_DH_L1_x6________________,                 ________________COLEMAK_MOD_DH_R1_x6________________,
    ________________COLEMAK_MOD_DH_L2_x6________________,                 ________________COLEMAK_MOD_DH_R2_x6________________,
    ________________COLEMAK_MOD_DH_L3_x6________________,                 ________________COLEMAK_MOD_DH_R3_x6________________,
                                           ________________THUMB_CLUSTER______________
  ),

  [_LOWER] = LAYOUT_wrapper(
    _______, ______________NUMBER_LEFT_x5_______________,                 ______________NUMBER_RIGHT_x5______________, _______,
    _______, ______________UNICODE_L2_x5________________,                 ________________NAV_R2_x5__________________, XXXXXXX,
    _______, ______________UNICODE_L3_x5________________,                 ________________NAV_R3_x5__________________, _______,
                                           _______, _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT_wrapper(
    ___________________SYMBOL_LEFT_x6___________________,                 ___________________SYMBOL_RIGHT_x6__________________,
    _______, ____________NAV_VIM_x4____________, XXXXXXX,                 ____________________SYMBOL_R2_x6____________________,
    _______, _________________NONE_5x___________________,                 ____________________SYMBOL_R3_x6____________________,
                                           _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_wrapper(
    QK_BOOT, _________________NONE_5x___________________,                 _______________CONFIG_R1_x5________________,DF(_QWY),
    RGB_TOG, ________________RGB_L2_x5__________________,                 _______________CONFIG_R2_x5________________, XXXXXXX,
    XXXXXXX, ________________RGB_L3_x5__________________,                 _______________CONFIG_R3_x5________________,DF(_CMK),
                                           _______, _______, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

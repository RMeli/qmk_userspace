/* Copyright 2022 Rocco Meli <@RMeli>
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

#include QMK_KEYBOARD_H

#include "wrappers.h" // Home Row Mods

enum combos {
  QW_TAB,
  AS_ESC,
  OP_BSPC,
  PTR_PTR,
  COMBO_LENGTH, // Must be last
};
uint16_t COMBO_LEN = COMBO_LENGTH; // Avoids need to define COMBO_COUNT

// https://precondition.github.io/home-row-mods#using-mod-taps-in-combos
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
#ifdef HOME_ROW_MODS_ENABLED
// FIXME: Add support for Colemak
const uint16_t PROGMEM as_combo[] = {HM_A, HM_S, COMBO_END};
#else
const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
#endif
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM pt_combo[] = {KC_P, KC_T, KC_R, COMBO_END};

combo_t key_combos[] = {
  [QW_TAB] = COMBO(qw_combo, KC_TAB),
  [AS_ESC] = COMBO(as_combo, KC_ESC),
  [OP_BSPC] = COMBO(op_combo, KC_BSPC),
  [PTR_PTR] = COMBO_ACTION(pt_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case PTR_PTR:
      if (pressed) {
        SEND_STRING("->");
      }
      break;
  }
}

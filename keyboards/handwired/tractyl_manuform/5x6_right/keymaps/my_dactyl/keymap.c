/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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

enum my_keycodes {
  DRAG_SCROLL = SAFE_RANGE,
};

enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
};


#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_5x6_right(
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
     KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_BSLS,
                      KC_LBRC,KC_RBRC,                                                       KC_BTN1,KC_BTN2,
                                     KC_LALT,                                         KC_ENT,
                                      RAISE , KC_SPC,                                 LOWER ,
                                      KC_EQL, KC_GRV,                        KC_LGUI, KC_DEL
  ),

  [_LOWER] = LAYOUT_5x6_right(
     KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL ,
     _______,KC_HOME,KC_PGUP,_______,_______,KC_LBRC,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,KC_MINS,KC_SLSH,
     _______,KC_END ,KC_PGDN,_______,_______,KC_LPRN,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_PLUS,KC_ASTR,
     _______,_______,_______,_______,_______,_______,                        _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_ENT ,
                     _______,KC_PSCR,                                                        _______, KC_P0,
                                     _______,                                        _______,
                                     _______,_______,                                _______,
                                     _______,_______,                        _______,_______

  ),

  [_RAISE] = LAYOUT_5x6_right(
       KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       _______,_______,KC_UP  ,_______,_______,KC_LBRC,                        KC_RBRC,_______, KC_NUM,KC_INS ,KC_SCRL,KC_MUTE,
       _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,KC_LPRN,                        KC_RPRN,_______,_______,_______,_______,KC_VOLU,
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD,
                       _______,_______,                                                        DRAG_SCROLL,DRAG_SCROLL,
                                       _______,                                        _______,
                                       _______,_______,                                _______,
                                       _______,_______,                        _______,_______
  ),
};

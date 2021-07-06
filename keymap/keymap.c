/* Copyright 2015-2017 Jack Humbert
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


enum planck_layers {
    _QWERTY,
    _COLEMAK,
    _NUMBER,
    _SYMBOL,
    _ADJUST,
    _NAVIGATE,
};

enum planck_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
};


#define CTRL_ESC   LCTL_T(KC_ESC)
#define MACOS_LCK  LCTL(LSFT(KC_POWER))
#define CTRL_LEFT  LCTL(KC_LEFT)
#define CTRL_RGHT  LCTL(KC_RIGHT)
#define CTRL_UP    LCTL(KC_UP)
#define CTRL_DOWN  LCTL(KC_DOWN)
#define NUMBER     MO(_NUMBER)
#define SYMBOL     MO(_SYMBOL)
#define NAVIGATE   MO(_NAVIGATE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty base layer
 * ,-----------------------------------------------------------------------------------------------------------------------.
 * |   Tab   |    Q    |    W    |    E    |    R    |    T    |    Y    |    U    |    I    |    O    |    P    |  Bksp   |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * | Ctr/Esc |    A    |    S    |    D    |    F    |    G    |    H    |    J    |    K    |    L    |    ;    | Ctrl/'  |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * | Shift/( |    Z    |    X    |    C    |    V    |    B    |    N    |    M    |    ,    |    .    |    /    | Shift/) |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |    [    |   Alt   |   Win   |   Nav   |   Num   |  Space  |  Enter  | Symbol  |   Nav   |   Win   |   Alt   |    ]    |
 * `-----------------------------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    CTRL_ESC, KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSPO,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSPC,
    KC_LBRC,  KC_LALT,  KC_LGUI,  NAVIGATE, NUMBER,   KC_SPC,   KC_ENTER, SYMBOL,   NAVIGATE, KC_RGUI,  KC_RALT,  KC_RBRC
),

/* Colemak base layer
 * ,-----------------------------------------------------------------------------------------------------------------------.
 * |   Tab   |    Q    |    W    |    F    |    P    |    G    |    J    |    L    |    U    |    Y    |    ;    |  Bksp   |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * | Ctr/Esc |    A    |    R    |    S    |    T    |    D    |    H    |    N    |    E    |    I    |    O    | Ctrl/'  |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * | Shift/( |    Z    |    X    |    C    |    V    |    B    |    K    |    M    |    ,    |    .    |    /    | Shift/) |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |    [    |   Alt   |   Win   |   Nav   |   Num   |  Space  |  Enter  | Symbol  |   Nav   |   Win   |   Alt   |    ]    |
 * `-----------------------------------------------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSPC,
    CTRL_ESC, KC_A,     KC_R,     KC_S,     KC_T,     KC_D,     KC_H,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,
    KC_LSPO,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSPC,
    KC_LBRC,  KC_LALT,  KC_LGUI,  NAVIGATE, NUMBER,   KC_SPC,   KC_ENTER, SYMBOL,   NAVIGATE, KC_RGUI,  KC_RALT,  KC_RBRC
),

/* Number layer: number row replacement & F keys
 * ,-----------------------------------------------------------------------------------------------------------------------.
 * |         |   F1    |   F2    |   F3    |   F4    |   F5    |   F6    |   F7    |   F8    |   F9    |   F10   |   Del   |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |    0    |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |    -    |    =    |    `    |    \    |         |         |         |         |         |         |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |         |         |         |  Held   |         |         |         |         |         |         |         |
 * `-----------------------------------------------------------------------------------------------------------------------'
 */
[_NUMBER] = LAYOUT_planck_grid(
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_DEL,
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    _______,  KC_MINUS, KC_EQUAL, KC_GRAVE, KC_BSLS,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),

/* Symbol layer: shifted versions of number layer & extended F keys
 * ,-----------------------------------------------------------------------------------------------------------------------.
 * |         |   F11   |   F12   |   F13   |   F14   |   F15   |   F16   |   F17   |   F18   |   F19   |   F20   |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |    !    |    @    |    #    |    $    |    %    |    ^    |    &    |    *    |    (    |    )    |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |    _    |    +    |    ~    |    |    |         |         |         |         |         |         |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |         |         |         |         |         |         |  Held   |         |         |         |         |
 * `-----------------------------------------------------------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_planck_grid(
    _______,  KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,   _______,
    _______,  S(KC_1),  S(KC_2),  S(KC_3),  S(KC_4),  S(KC_5),  S(KC_6),  S(KC_7),  S(KC_8),  S(KC_9),  S(KC_0),  _______,
    _______,  KC_UNDS,  KC_PLUS,  KC_TILDE, KC_PIPE,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),

/* Adjust (Number + Symbol): keyboard settings and other keys that should not accidentally be hit
 * ,-----------------------------------------------------------------------------------------------------------------------.
 * |         |  Reset  |         |         |         |         |         | LockScr |         |         |         |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |         |         |         |         |         |         | Light-  | Light+  | Colemak | Qwerty  |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |         |         |         |         |         |         |         |         |         |         |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |         |         |         |  Held   |         |         |  Held   |         |         |         |         |
 * `-----------------------------------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______,  RESET,    _______,  _______,  _______,  _______,  _______,  MACOS_LCK,_______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  BL_DEC,   BL_INC,   COLEMAK,  QWERTY,   _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),

/* Navigate: arrow keys and other navigation, including media controls
 * ,-----------------------------------------------------------------------------------------------------------------------.
 * |         |   <<    |         |   >|    |   >>    |         |         |  Home   | PgDown  |  PgUp   |   End   |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         | Ctrl ←  | Ctrl ↓  | Ctrl ↑  | Ctrl →  |         |         |    ←    |    ↓    |    ↑    |    →    |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |         |         |         |         |         |         |         |         |         |         |         |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |         |         |         |         |         |         |         |         |         |         |         |         |
 * `-----------------------------------------------------------------------------------------------------------------------'
 */
[_NAVIGATE] = LAYOUT_planck_grid(
    _______,  KC_MPRV,  _______,  KC_MPLY,  KC_MNXT,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,
    _______,  CTRL_LEFT,CTRL_DOWN,CTRL_UP,  CTRL_RGHT,_______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUMBER, _SYMBOL, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }

            return false;

        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }

            return false;
    }

    return true;
}

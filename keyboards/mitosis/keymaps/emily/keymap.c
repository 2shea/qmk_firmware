// This is the Dvorak-friendly layout for the Mitosis by CarVac (/u/CarVac)
// It features space on the left thumb, shift on the right thumb, a
//  number layer with all the numbers on the home row, and a function layer
//  that provides mouse keys among other things.

#include "mitosis.h"

enum mitosis_layers
{
  _STD,
  _NUM,
  _SYM,
  _FUN
};

//Mousekeys
#define MOUSEKEY_DELAY 50
#define MOUSEKEY_INTERNAL 50
#define MOUSEKEY_MAX_SPEED 10
#define MOUSEKEY_TIME_TO_MAX 5
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

// Fillers to make layering more clear
#define _______ KC_TRNS
#define ___M___ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------..--------------------------------------------.
 * | Q      | W      | E      | R      | T      || Y      | U      | I      | O      | P      |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * | A      | S      | D      | F      | G      || J      | H      | K      | L      | ;      |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * | Z      | X      | C      | V      | B      || N      | M      | ,      | .      | /      |
 * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
 *          | ALT    | CTRL   | NUM    | LSHIFT || RSHIFT | NUM    | CTRL   | ALT    |
 *          |--------+--------+--------+--------||--------+--------+--------+--------|
 *          | TAB    | SUPER  | FUNC   | BACKS  || SPACE  | FUNC   | SUPER  | TAB    |
 *          '-----------------------------------''-----------------------------------'
 */

[_STD] = { /* Standard; as compatible with dvorak and qwerty as possible */
  {KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    },
  {KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN },
  {KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH },
  {XXXXXXX, KC_LALT, KC_LCTL, MO(_NUM),KC_LSFT,        KC_RSFT, MO(_NUM),KC_RCTL, KC_RALT, XXXXXXX},
  {XXXXXXX, KC_TAB,  KC_LGUI, MO(_SYM),KC_BSPC,        KC_SPC,  MO(_SYM),KC_RGUI, KC_TAB,  XXXXXXX}
},

/* Number layout
 * .--------------------------------------------..--------------------------------------------.
 * |        | WH_U   |        |  CMD+[ |  CMD+] || /      | 7      | 8      | 9      | 0      |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * |        | WH_D   | MS_U   |CMD+LEFT|CMD+RGHT|| *      | 4      | 5      | 6      | +      |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * |  BTN2  | MS_L   | MS_D   | MS_R   | BTN1   || -      | 1      | 2      | 3      | =      |
 * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
 *          |        |        |        |        ||        |        |        |        |
 *          |--------+--------+--------+--------||--------+--------+--------+--------|
 *          |        |        |        |        ||        |        |        |        |
 *          '-----------------------------------''-----------------------------------'
 */

[_NUM] = {
  {_______, KC_WH_U, _______, LGUI(KC_LBRC), LGUI(KC_RBRC),       KC_PSLS, KC_7,    KC_8,    KC_9,    KC_0},
  {_______, KC_WH_D, KC_MS_U, LGUI(KC_LEFT), LGUI(KC_RGHT),       KC_PAST, KC_4,    KC_5,    KC_6,    KC_PPLS},
  {KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R,       KC_BTN1,             KC_MINS, KC_1,    KC_2,    KC_3,    KC_EQL},
  {XXXXXXX, _______, _______, ___M___,       _______,             _______, ___M___, _______, _______, XXXXXXX},
  {XXXXXXX, _______, _______, MO(_FUN),      LGUI(KC_ENT),        KC_PENT, MO(_FUN),_______, _______, XXXXXXX},
},

/* Symbols layer
 * .--------------------------------------------..--------------------------------------------.
 * | ESC    |        | UP     |        | ` ~    || !      | @      | #      | $      | %      |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * | TAB    | LEFT   | DOWN   | RIGHT  | ' "    || ^      | &      | *      | |      | _      |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * | \      | (      | {      | [      | <      || >      | ]      | }      | )      | /      |
 * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
 *          |        |        |        |        ||        |        |        |        |
 *          |--------+--------+--------+--------||--------+--------+--------+--------|
 *          |        |        |        | DELETE || ENTER  |        |        |        |
 *          '-----------------------------------''-----------------------------------'
 */

[_SYM] = {
  {KC_ESC,  _______, KC_UP,   _______, KC_GRV,        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC},
  {KC_TAB,  KC_LEFT, KC_DOWN, KC_RGHT, KC_QUOT,       KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_UNDS},
  {KC_BSLS, KC_LPRN, KC_LCBR, KC_LBRC, KC_LABK,       KC_RABK, KC_RBRC, KC_RCBR, KC_RPRN, KC_SLSH},
  {XXXXXXX, _______, _______, MO(_FUN),_______,       _______, MO(_FUN),_______, _______, XXXXXXX},
  {XXXXXXX, _______, _______, ___M___, KC_DEL,        KC_ENT,  ___M___, _______, _______, XXXXXXX},
},

/* Fn layout
 * .--------------------------------------------..--------------------------------------------.
 * |        |        | PGUP   |        | VOLUP  || F13    | F7     | F8     | F9     | F10    |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * |        | HOME   | PGDWN  | END    | VOLDN  || F14    | F4     | F5     | F6     | F11    |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * |        | PREV   | PLAY   | NEXT   | MUTE   || F15    | F1     | F2     | F3     | F12    |
 * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
 *          |        |        |        |        ||        |        |        |        |
 *          |--------+--------+--------+--------||--------+--------+--------+--------|
 *          |        |        |        |        ||        |        |        |        |
 *          '-----------------------------------''-----------------------------------'
 */

[_FUN] = {
  {_______, _______, KC_PGUP, _______, KC_VOLU,       KC_F13,  KC_F7,   KC_F8,   KC_F9,   KC_F10},
  {_______, KC_HOME, KC_PGDN, KC_END,  KC_VOLD,       KC_F14,  KC_F4,   KC_F5,   KC_F6,   KC_F11},
  {_______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,       KC_F15,  KC_F1,   KC_F2,   KC_F3,   KC_F12},
  {XXXXXXX, _______, _______, ___M___, _______,       _______, ___M___, _______, _______, XXXXXXX},
  {XXXXXXX, _______, _______, _______, ___M___,       ___M___, _______, _______, _______, XXXXXXX},
},

/* blank key layout template
 * .--------------------------------------------..--------------------------------------------.
 * |        |        |        |        |        ||        |        |        |        |        |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * |        |        |        |        |        ||        |        |        |        |        |
 * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
 * |        |        |        |        |        ||        |        |        |        |        |
 * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
 *          |        |        |        |        ||        |        |        |        |
 *          |--------+--------+--------+--------||--------+--------+--------+--------|
 *          |        |        |        |        ||        |        |        |        |
 *          '-----------------------------------''-----------------------------------'
 */
};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
      case _STD:
        set_led_off;
        break;
        case _FUN:
            set_led_blue;
            break;
        case _NUM:
            set_led_green;
            break;
        case _SYM:
            set_led_red;
            break;
        default:
            break;
    }
};


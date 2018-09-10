#include QMK_KEYBOARD_H

#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  HSV_88_172_249,
  PHP_ARROW
};

//Tap Dance Declarations
enum {
  TD_ESC_CAPS = 0,
  TD_LEFT_HOME,
  TD_DOWN_PGDN,
  TD_UP_PGUP,
  TD_RIGHT_END,
};

#define MK_LCSHFT LCTL(KC_LSHIFT)
#define MK_AGRV   ALT_T(KC_GRAVE)
#define TD_LFTHM  TD(TD_LEFT_HOME)
#define TD_DNPGDN TD(TD_DOWN_PGDN)
#define TD_UPPGUP TD(TD_UP_PGUP)
#define TD_RTEND  TD(TD_RIGHT_END)

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
  [TD_LEFT_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_HOME),
  [TD_DOWN_PGDN] = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_PGDN),
  [TD_UP_PGUP] = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_PGUP),
  [TD_RIGHT_END] = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT, KC_END),
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,--------------------------------------------------.         ,--------------------------------------------------.
   * |   F12  |   1  |   2  |   3  |   4  |   5  |  [   |         |   ]  |   6  |   7  |   8  |   9  |   0  |   -    |
   * |--------+------+------+------+------+-------------|         |------+------+------+------+------+------+--------|
   * | Tab    |   Q  |   W  |   E  |   R  |   T  |  {   |         |  }   |   Y  |   U  |   I  |   O  |   P  |   \    |
   * |--------+------+------+------+------+------|      |         |      |------+------+------+------+------+--------|
   * |CtrlShft|   A  |   S  |   D  |   F  |   G  |------|         |------|   H  |   J  |   K  |   L  |   ;  |   '    |
   * |--------+------+------+------+------+------|  (   |         |  )   |------+------+------+------+------+--------|
   * | LShift |   Z  |   X  |   C  |   V  |   B  |      |         |      |   N  |   M  |   ,  |   .  |   /  | RShift |
   * `--------+------+------+------+------+-------------'         `-------------+------+------+------+------+--------'
   *   | Ctrl |  Gui |  Alt |   "  |   =  |                                     |   $  | Left | Down |  Up  | Right|
   *   `----------------------------------'                                     `----------------------------------'
   *                                        ,-------------.     ,-------------.
   *                                        |  -   | Esc  |     | Del  |  ->  |
   *                                 ,------|------|------|     |------+------+------.
   *                                 |      |      | TT1  |     | TT2  |      |      |
   *                                 | Space|Enter |------|     |------|  ;   |Space |
   *                                 |      |      |      |     |      |      |      |
   *                                 `--------------------'     `--------------------'
   */
  [0] = LAYOUT_ergodox(
          KC_F12,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5, KC_LBRC,
          KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T, KC_LCBR,
          MK_LCSHFT,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
          KC_LSHIFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B, KC_LPRN,
          KC_LCTL,    KC_LGUI,  MK_AGRV,  KC_DQUO,  KC_EQUAL,
                      KC_MINUS, KC_ESCAPE,
                                TT(1),
          KC_SPACE,   KC_ENTER, KC_TRNS,

          KC_RBRC,    KC_6,     KC_7,       KC_8,       KC_9,     KC_0,     KC_BSPACE,
          KC_RCBR,    KC_Y,     KC_U,       KC_I,       KC_O,     KC_P,     KC_BSLASH,
          KC_H,       KC_J,     KC_K,       KC_L,       KC_SCLN,  KC_QUOTE,
          KC_RPRN,    KC_N,     KC_M,       KC_COMMA,   KC_DOT,   KC_SLASH, KC_RSHIFT,
          KC_DLR,     TD_LFTHM, TD_DNPGDN,  TD_UPPGUP,  TD_RTEND,
          KC_DELETE,  PHP_ARROW,
          TT(2),
          KC_TRNS,    KC_SCLN,  KC_SPACE
   ),

  /* Keymap 1: Symbols & Numbers
   *
   * ,--------------------------------------------------.         ,--------------------------------------------------.
   * |   F12  |  F1  |  F2  |  F3  |  F4  |  F5  |      |         |  /   |  F6  |  F7  |  F8  |  F9  |  F0  |  F11   |
   * |--------+------+------+------+------+-------------|         |------+------+------+------+------+------+--------|
   * |        |   !  |   @  |   {  |   }  |   |  |      |         |  *   |   7  |   8  |   9  |      |      |  F12   |
   * |--------+------+------+------+------+------|      |         |      |------+------+------+------+------+--------|
   * |        |   #  |   $  |   (  |   )  |   `  |------|         |------|   4  |   5  |   6  |      |      |        |
   * |--------+------+------+------+------+------|      |         |  -   |------+------+------+------+------+--------|
   * |        |   %  |   ^  |   [  |   ]  |   ~  |      |         |      |   1  |   2  |   3  |      |      |        |
   * `--------+------+------+------+------+-------------'         `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                     |   0  | .    |   =  |      |      |
   *   `----------------------------------'                                     `----------------------------------'
   *                                        ,-------------.     ,-------------.
   *                                        |Animat| Esc  |     |On/Off| Pause|
   *                                 ,------|------|------|     |------+------+------.
   *                                 |      |      |      |     | Hue+ |      |      |
   *                                 | Dim  |Bright|------|     |------|  +   |Enter |
   *                                 |      |      | Green|     | Hue- |      |      |
   *                                 `--------------------'     `--------------------'
   */
  [1] = LAYOUT_ergodox(
          KC_F12,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
          KC_TRNS,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,  KC_PIPE,  KC_TRNS,
          KC_TRNS,  KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,  KC_GRAVE,
          KC_TRNS,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILD,  KC_TRNS,
          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                    RGB_MOD,  KC_ESCAPE,
                              KC_TRNS,
          RGB_VAD,  RGB_VAI,  HSV_88_172_249,

          KC_PSLS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
          KC_PAST,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_TRNS,  KC_TRNS,  KC_F12,
          KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_TRNS,  KC_TRNS,  KC_TRNS,
          KC_PMNS,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_TRNS,  KC_TRNS,  KC_TRNS,
          KC_KP_0,  KC_DOT,   KC_EQUAL, KC_TRNS,  KC_TRNS,
          RGB_TOG,  RGB_SLD,
          RGB_HUI,
          RGB_HUD,  KC_PPLS,  KC_PENT
        ),

    /* Keymap BLANK:
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |      |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    [2] = LAYOUT_ergodox(
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS,
                             KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS,

           // right hand
           KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS,
           KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS
    ),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
      switch (keycode) {
        // dynamically generate these.
        case EPRM:
          eeconfig_init();
          return false;
        case VRSN:
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
          return false;
        case RGB_SLD:
          rgblight_mode(1);
          return false;
        case HSV_88_172_249:
          #ifdef RGBLIGHT_ENABLE
            rgblight_enable();
            rgblight_mode(1);
            rgblight_sethsv(88,172,249);
          #endif
          return false;
        case PHP_ARROW:
          SEND_STRING("->");
          return false;
        }
    }
    return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};

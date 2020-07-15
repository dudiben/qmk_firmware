#include QMK_KEYBOARD_H

enum custom_keycodes {
  UP_URL = SAFE_RANGE
};

#define _BASE 0
#define _MY_LAYER 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_3x4
  (
    KC_MNXT, KC_MPLY, KC_MPRV,
    KC_4, KC_5, KC_MUTE,
    KC_7, MT(MOD_LCTL | MOD_LSFT, KC_V), MT(MOD_LCTL | MOD_LSFT, KC_C),
    KC_SLEP, TG(_MY_LAYER), KC_WAKE
  ),
    [_MY_LAYER] = LAYOUT_ortho_3x4
  (
    KC_1, KC_2, KC_3,
    KC_4, KC_5, KC_6,
    KC_7, KC_8, KC_9,
    KC_0, KC_TRANSPARENT, KC_WAKE
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case UP_URL:
      if (record->event.pressed) {
        SEND_STRING("http://1upkeyboards.com");
      }
      return false;
      break;
  }
  return true;
}

#include QMK_KEYBOARD_H

#include "keymap_norwegian.h"

enum layers { 
  _BASE, 
  _TYPE,
  _RAISE, 
  _LOWER, 
  _ADJUST, 
  _SYM1, 
  _SYM2 
};

enum keycodes {
  ___ARNG = SAFE_RANGE,
  ___AE,
  ___OSTR
};

#define SFT_A LSFT_T(KC_A)
#define CTL_S LCTL_T(KC_S)
#define ALT_D LALT_T(KC_D)
#define GUI_F LGUI_T(KC_F)
#define GUI_J RGUI_T(KC_J)
#define ALT_K RALT_T(KC_K)
#define CTL_L RCTL_T(KC_L)
#define SFT_SCL RSFT_T(KC_SCLN)
#define SFT_0 RSFT_T(KC_0)
#define DSK_1 LGUI(KC_1)
#define DSK_2 LGUI(KC_2)
#define DSK_3 LGUI(KC_3)
#define DSK_4 LGUI(KC_4)
#define LANG LGUI(KC_SPACE)
#define MO_SYM1 MO(_SYM1)
#define MO_SYM2 MO(_SYM2)
#define DF_BASE DF(_BASE)
#define DF_TYPE DF(_TYPE)
#define LT_ENT LT(_LOWER, KC_ENT)
#define LT_SPC LT(_RAISE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    SFT_A,   CTL_S,   ALT_D,   GUI_F,   KC_G,    _______, _______, KC_H,    GUI_J,   ALT_K,   CTL_L,   SFT_SCL,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    MO_SYM1, _______, _______, LT_ENT,  KC_TAB,  KC_ESC,  KC_ESC,  KC_BSPC, LT_SPC,  _______, _______, MO_SYM2 
  ),

  [_TYPE] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    MO_SYM1, _______, _______, LT_ENT,  KC_TAB,  KC_ESC,  KC_ESC,  KC_BSPC, LT_SPC,  _______, KC_QUOT, MO_SYM2 
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    SFT_0,
    KC_GRV,  KC_QUOT, KC_BSLS, KC_MINS, KC_EQL,  _______, _______, XXXXXXX, _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, DSK_1,   DSK_2,   XXXXXXX, XXXXXXX, DSK_3,   DSK_4,   XXXXXXX, XXXXXXX, XXXXXXX,
    DF_BASE, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  RESET,   RESET,   KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, DF_TYPE
  ),

  [_SYM1] = LAYOUT_planck_grid(
    _______, _______, NO_AE,   _______, _______, _______, _______, _______, _______, _______, NO_OSTR, _______,
    NO_ARNG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, LANG,    LANG,    _______, _______, _______, _______, _______
  ),

  [_SYM2] = LAYOUT_planck_grid(
    _______, _______, ___AE,   _______, _______, _______, _______, _______, _______, _______, ___OSTR, _______,
    ___ARNG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};

void keyboard_post_init_user(void) {
  rgb_matrix_disable();
}

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    default:
      return TAPPING_TERM;
  }
}

void led_levels(int left, int right) {
  planck_ez_left_led_level(left);
  planck_ez_right_led_level(right);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

  switch (get_highest_layer(state)) {
    case _RAISE: led_levels(0, 32); break;
    case _LOWER: led_levels(32, 0); break;
    case _ADJUST: led_levels(32, 32); break;
    default: led_levels(0, 0); break;
  }

  return state;
}

void register_sym(uint16_t keycode) {
  register_code16(LGUI(KC_SPACE));
  unregister_code16(LGUI(KC_SPACE));

  register_code(keycode);
}

void unregister_sym(uint16_t keycode) {
    unregister_code(keycode);

    register_code16(LGUI(KC_SPACE));
    unregister_code16(LGUI(KC_SPACE));
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case ___ARNG: register_sym(NO_ARNG); break;
      case ___AE: register_sym(NO_AE); break;
      case ___OSTR: register_sym(NO_OSTR); break;
    }
  } else {
    switch (keycode) {
      case ___ARNG: unregister_sym(NO_ARNG); break;
      case ___AE: unregister_sym(NO_AE); break;
      case ___OSTR: unregister_sym(NO_OSTR); break;
    }
  }

  return true;
}

#include QMK_KEYBOARD_H

#include "keymap_norwegian.h"

enum layers { 
  _BASE, 
  _RAISE, 
  _LOWER,
  _ADJUST, 
  _MOUSE,
  _SELECT,
  _SYMBOL, 
};

enum keycodes {
  XK_SYM = SAFE_RANGE,
  XK_SEL
};

enum dances {
  _TD_SYM = 0,
};

void td_sym_finished(qk_tap_dance_state_t *state, void *user_data);
void td_sym_reset(qk_tap_dance_state_t *state, void *user_data);

qk_tap_dance_action_t tap_dance_actions[] = {
  [_TD_SYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_sym_finished, td_sym_reset),
};

#define SFT_Z LSFT_T(KC_Z)
#define SFT_SLS RSFT_T(KC_SLSH)
#define DSK_1 LGUI(KC_1)
#define DSK_2 LGUI(KC_2)
#define DSK_3 LGUI(KC_3)
#define DSK_4 LGUI(KC_4)
#define LANG LGUI(KC_SPACE)
#define MOUSE TG(_MOUSE)
#define LT_ENT LT(_LOWER, KC_ENT)
#define LT_SPC LT(_RAISE, KC_SPC)
#define TD_SYM TD(_TD_SYM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, 
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    SFT_Z,   KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  SFT_SLS,
    TD_SYM,  KC_LALT, KC_LCTL, LT_ENT,  KC_TAB,  KC_ESC,  KC_ESC,  KC_BSPC, LT_SPC,  KC_RCTL, KC_LALT, KC_LGUI
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_GRV,  KC_QUOT, KC_BSLS, KC_MINS, KC_EQL,  _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______,
    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    XK_SEL,  DSK_1,   DSK_2,   DSK_3,   XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______,
    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, MOUSE,   XXXXXXX, XXXXXXX, KC_RSFT,
    XXXXXXX, _______, _______, _______, _______, RESET,   RESET,   _______, _______, _______, _______, _______
  ),

  [_MOUSE] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, KC_Q,    KC_W,    KC_E,    XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, KC_MS_U, KC_WH_U, XXXXXXX,
    KC_LSFT, KC_LCTL, KC_A,    KC_S,    KC_D,    XXXXXXX, XXXXXXX, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,
    XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, XXXXXXX, XXXXXXX, MOUSE,   XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, _______, _______, KC_BTN2, KC_SPC,  _______, _______, KC_BTN3, KC_BTN1, _______, _______, _______
  ),

  [_SELECT] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_SYMBOL] = LAYOUT_planck_grid(
    _______, _______, NO_AE,   _______, _______, _______, _______, _______, _______, _______, NO_OSTR, _______,
    NO_ARNG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, LANG,    LANG,    _______, _______, _______, _______, _______
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

void sym_on(void) {
  tap_code16(LGUI(KC_SPACE));
  layer_on(_SYMBOL);
}

void sym_off(void) {
  tap_code16(LGUI(KC_SPACE));
  layer_off(_SYMBOL);
}

void set_led_levels(int left, int right) {
  planck_ez_left_led_level(left);
  planck_ez_right_led_level(right);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

  switch (get_highest_layer(state)) {
    case _RAISE: set_led_levels(0, 32); break;
    case _LOWER: set_led_levels(32, 0); break;
    case _ADJUST: set_led_levels(32, 32); break;
    case _MOUSE: set_led_levels(32, 32); break;
    default: set_led_levels(0, 0); break;
  }

  return state;
}

bool xk_sel = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case XK_SYM:
        if (record->event.pressed) {
          sym_on();
        } else { 
          sym_off();
        }

        break;

      case XK_SEL:
        if (record->event.pressed) {
          layer_on(_SELECT);
          register_code(KC_LGUI);
          tap_code(KC_GRV);
          xk_sel = true;
        }

        break;

      case LT_ENT:
        if (!record->event.pressed) {
          if (xk_sel) {
            layer_off(_SELECT);
            unregister_code(KC_LGUI);
            xk_sel = false;
          }
        }

        break;
  }

  return true;
}

bool sym_hold = false;

void td_sym_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) { 
    if (state->interrupted || !state->pressed) {
      if (IS_LAYER_ON(_SYMBOL)) { 
        sym_off();
      } else { 
        sym_on();
      }
    } else {
      sym_hold = true;
      sym_on();
    }
  }
}

void td_sym_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (sym_hold) {
    sym_hold = false;
    tap_code16(LGUI(KC_SPACE));
    layer_off(_SYMBOL);
  }
}
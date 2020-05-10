#include QMK_KEYBOARD_H
#include "keymap_norwegian.h"
#include "spektroskop.h"

enum layers { 
  _BASE_ENT_SPC, _BASE_SPC, _BASE_Z_SLSH, _BASE_F_J,
  _SHIFT, _SHIFT_SYM1, _SHIFT_SYM2,
  _SYM1, _SYM2,
  _FUNC, _LANG, _MOUSE, _SELECT,
};

enum keycodes {
  XK_LANG = SAFE_RANGE,
  XK_SEL,
};

enum dances {
  _TD_LANG = 0,
};

void td_lang_finished(qk_tap_dance_state_t *state, void *user_data);
void td_lang_reset(qk_tap_dance_state_t *state, void *user_data);

qk_tap_dance_action_t tap_dance_actions[] = {
  [_TD_LANG] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_lang_finished, td_lang_reset),
};

#define SFT_F LSFT_T(KC_F)
#define SFT_J RSFT_T(KC_J)
#define SFT_Z LSFT_T(KC_Z)
#define SFT_SLS RSFT_T(KC_SLSH)
#define SFT_4 LSFT_T(KC_4)
#define SFT_7 RSFT_T(KC_7)
#define SFT_SPC RSFT_T(KC_SPC)
#define GUI_ESC LGUI_T(KC_ESC)

#define DSK_1 LGUI(KC_1)
#define DSK_2 LGUI(KC_2)
#define DSK_3 LGUI(KC_3)
#define DSK_4 LGUI(KC_4)
#define LANG LGUI(KC_SPACE)

#define MOUSE TG(_MOUSE)

#define ENT_SFT LT(_SHIFT_SYM2, KC_ENT)
#define ENT_SF3 LT(_SHIFT, KC_ENT)
#define SPC_SFT LT(_SHIFT_SYM1, KC_SPC)
#define SPC_SF3 LT(_SHIFT, KC_SPC)

#define TAB_FUN LT(_FUNC, KC_TAB)

#define TAB_SYM LT(_SYM1, KC_TAB)
#define BSP_SYM LT(_SYM2, KC_BSPC)
#define SYM1 MO(_SYM1)
#define SYM2 MO(_SYM2)
#define CTL_TAB LCTL_T(KC_TAB)
#define CTL_BSP RCTL_T(KC_BSPC)

#define ENT_SYM LT(_SYM1, KC_ENT)
#define SPC_SYM LT(_SYM2, KC_SPC)

#define TD_LANG TD(_TD_LANG)

#define OS_SYM1 OSL(_SYM1)
#define OS_SYM2 OSL(_SYM2)

#define DF_1 DF(_BASE_ENT_SPC)
#define DF_2 DF(_BASE_SPC)
#define DF_3 DF(_BASE_Z_SLSH)
#define DF_4 DF(_BASE_F_J)

#define BASE_R1 KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define BASE_R2 KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    DF_1,    DF_2,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define BASE_R3 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    DF_3,    DF_4,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define SYM_R1  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define SYM_R2  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    SFT_7,   KC_8,    KC_9,    KC_0
#define SYM_R3  KC_GRV,  KC_QUOT, KC_BSLS, KC_MINS, KC_EQL,  _______, _______, KC_TILD, KC_DQUO, _______, _______, _______
#define SYM_R4  XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE, KC_UNDS, KC_PLUS

#define SFT_R1  S_Q,     S_W,     S_E,     S_R,     S_T,     KC_LCBR, KC_RCBR, S_Y,     S_U,     S_I,     S_O,     S_P
#define SFT_R2  S_A,     S_S,     S_D,     S_F,     S_G,     _______, _______, S_H,     S_J,     S_K,     S_L,     KC_COLN
#define SFT_R3  S_Z,     S_X,     S_C,     S_V,     S_B,     _______, _______, S_N,     S_M,     KC_LT,   KC_GT,   KC_QUES

#define ______________ARROWS______________ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT

#define F_KEYS KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,


#define LAYOUT_planck_grid_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE_ENT_SPC] = LAYOUT_planck_grid_wrapper(
    BASE_R1, BASE_R2, BASE_R3,
    TD_LANG, KC_LALT, KC_LCTL, ENT_SFT, TAB_FUN, GUI_ESC, GUI_ESC, KC_BSPC, SPC_SFT, KC_RCTL, KC_LALT, KC_LGUI
  ),

  [_BASE_SPC] = LAYOUT_planck_grid_wrapper(
    BASE_R1, BASE_R2, BASE_R3,
    TD_LANG, KC_LALT, SYM1,    ENT_SF3, CTL_TAB, GUI_ESC, GUI_ESC, CTL_BSP, SPC_SF3, SYM2,    KC_LALT, KC_LGUI
  ),

  [_BASE_Z_SLSH] = LAYOUT_planck_grid_wrapper(
    BASE_R1, BASE_R2, 
    SFT_Z,   KC_X,    KC_C,    KC_V,    KC_B,    DF_2,    _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  SFT_SLS,
    TD_LANG, KC_LALT, KC_LCTL, ENT_SYM, TAB_FUN, GUI_ESC, GUI_ESC, KC_BSPC, SPC_SYM, KC_RCTL, KC_LALT, KC_LGUI
  ),

  [_BASE_F_J] = LAYOUT_planck_grid_wrapper(
    BASE_R1, 
    KC_A,    KC_S,    KC_D,    SFT_F,   KC_G,    DF_1,    DF_2,    KC_H,    SFT_J,   KC_K,    KC_L,    KC_SCLN,
    BASE_R3,
    TD_LANG, KC_LALT, KC_LCTL, ENT_SYM, TAB_FUN, GUI_ESC, GUI_ESC, KC_BSPC, SPC_SYM, KC_RCTL, KC_LALT, KC_LGUI
  ),

  [_SHIFT] = LAYOUT_planck_grid_wrapper(
    SFT_R1, SFT_R2, SFT_R3,
    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______
  ),

  [_SHIFT_SYM1] = LAYOUT_planck_grid_wrapper(
    SFT_R1, SFT_R2, SFT_R3,
    XXXXXXX, _______, _______, OS_SYM1, _______, _______, _______, _______, _______, _______, _______,  _______
  ),

  [_SHIFT_SYM2] = LAYOUT_planck_grid_wrapper(
    SFT_R1, SFT_R2, SFT_R3,
    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, OS_SYM2, _______, _______, _______
  ),

  [_SYM1] = LAYOUT_planck_grid_wrapper(
    SYM_R1, SYM_R2, SYM_R3, SYM_R4
  ),

  [_SYM2] = LAYOUT_planck_grid_wrapper(
    SYM_R1, SYM_R2, SYM_R3, SYM_R4
  ),

  [_FUNC] = LAYOUT_planck_grid(
    F_KEYS,
    XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______, ______________ARROWS______________, XXXXXXX,
    XK_SEL,  XXXXXXX, DSK_1,   DSK_2,   DSK_3,   _______, _______, XXXXXXX, MOUSE,   XXXXXXX, XXXXXXX, KC_RSFT,
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
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ______________ARROWS______________, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_LANG] = LAYOUT_planck_grid(
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

void lang_on(void) {
  tap_code16(LGUI(KC_SPACE));
  layer_on(_LANG);
}

void lang_off(void) {
  tap_code16(LGUI(KC_SPACE));
  layer_off(_LANG);
}

void set_led_levels(int left, int right) {
  planck_ez_left_led_level(left);
  planck_ez_right_led_level(right);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case _SYM1: set_led_levels(32, 0); break;
    case _SYM2: set_led_levels(0, 32); break;
    case _FUNC: set_led_levels(32, 32); break;
    case _MOUSE: set_led_levels(32, 32); break;
    default: set_led_levels(0, 0); break;
  }

  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case XK_LANG:
      if (record->event.pressed) {
        lang_on();
      } else {
        lang_off();
      }

      break;

    case XK_SEL:
      if (record->event.pressed) {
        layer_move(_SELECT);
        register_code(KC_LGUI);
        tap_code(KC_GRV);
      }

      break;

    case TAB_FUN:
      if (!record->event.pressed) {
        if (layer_state_is(_SELECT)) {
          layer_off(_SELECT);
          unregister_code(KC_LGUI);
        }
      }

      break;

    case ENT_SFT:
      if (!record->event.pressed) {
        if (layer_state_is(_SYM1) || layer_state_is(_SYM2)) {
          layer_move(_BASE_ENT_SPC);
        }
      }

      break;

    case SPC_SFT:
      if (!record->event.pressed) {
        if (layer_state_is(_SYM1) || layer_state_is(_SYM2)) {
          layer_move(_BASE_ENT_SPC);
        }
      }

      break;
  }

  return true;
}

bool lang_hold = false;

void td_lang_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) { 
    if (state->interrupted || !state->pressed) {
      if (layer_state_is(_LANG)) {
        lang_off();
      } else { 
        lang_on();
      }
    } else {
      lang_hold = true;
      lang_on();
    }
  }
}

void td_lang_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (lang_hold) {
    lang_hold = false;
    tap_code16(LGUI(KC_SPACE));
    layer_off(_LANG);
  }
}
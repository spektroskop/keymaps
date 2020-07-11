#include QMK_KEYBOARD_H
#include "spektroskop.h"

enum layers { _BASE, _LSFT, _RSFT, _LSYM, _RSYM, _FUN };

enum keycodes { GUI_TAB = SAFE_RANGE, ALT_TAB, CTL_TAB };

#define FUN_SLS LT(_FUN, KC_SLSH)
#define FUN_Z LT(_FUN, KC_Z)
#define GUI_1 LGUI(KC_1)
#define GUI_2 LGUI(KC_2)
#define GUI_3 LGUI(KC_3)
#define S_TAB S(KC_TAB)
#define SFT_ENT LT(_LSFT, KC_ENT)
#define SFT_SPC LT(_RSFT, KC_SPC)
#define TT_LSYM TT(_LSYM)
#define TT_RSYM TT(_RSYM)

#include "make_combos.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL, FUN_Z,   KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  FUN_SLS, KC_RCTL,
                               KC_LGUI, KC_LALT, SFT_ENT,       SFT_SPC, KC_LALT, KC_RGUI
  ),

  [_LSFT] = LAYOUT(
    S_TAB,   S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T),       S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), _______,
    _______, S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G),       S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_COLN, KC_DQUO,
    _______, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B),       S(KC_N), S(KC_M), KC_COMM, KC_DOT,  KC_QUES, _______,
                               _______, _______, _______,       TT_RSYM, _______, _______
  ),

  [_RSFT] = LAYOUT(
    S_TAB,   S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T),       S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), _______,
    _______, S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G),       S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_COLN, KC_DQUO,
    _______, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B),       S(KC_N), S(KC_M), KC_COMM, KC_DOT,  KC_QUES, _______,
                               _______, _______, TT_LSYM,       _______, _______, _______
  ),

  [_LSYM] = LAYOUT_wrapper(
    KC_TAB,  __________________SYM__L1__________________,       __________________SYM__R1__________________, _______,
    XXXXXXX, __________________SYM__L2__________________,       __________________SYM__R2__________________, XXXXXXX,
    _______, __________________SYM__L2__________________,       __________________SYM__R2__________________, _______,
                               _______, _______, _______,       _______, _______, _______
  ),

  [_RSYM] = LAYOUT_wrapper(
    KC_TAB,  __________________SYM__L1__________________,       __________________SYM__R1__________________, _______,
    XXXXXXX, __________________SYM__L2__________________,       __________________SYM__R2__________________, XXXXXXX,
    _______, __________________SYM__L2__________________,       __________________SYM__R2__________________, _______,
                               _______, _______, _______,       _______, _______, _______
  ),

  [_FUN] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    _______, _______, GUI_1,   GUI_2,   GUI_3,   XXXXXXX,        XXXXXXX, GUI_TAB, ALT_TAB, CTL_TAB, _______, _______,
                               _______, _______, KC_LSFT,        KC_RSFT, _______, _______
  ),
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case FUN_Z: case FUN_SLS:
    case SFT_ENT: case SFT_SPC:
      return false;
    default:
        return true;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case SFT_ENT: case SFT_SPC: case TT_LSYM: case TT_RSYM:
    handle_sft_sym(.record=record, .keycode=keycode,
      .lsft_code=SFT_ENT, .rsft_code=SFT_SPC,
      .lsym_code=TT_LSYM, .rsym_code=TT_RSYM,
      .lsym_layer=_LSYM,  .rsym_layer=_RSYM
    )
    break;

  case GUI_TAB: case ALT_TAB: case CTL_TAB:
    activate_tabs(.record=record, .keycode=keycode,
      .gui_tab_code=GUI_TAB,
      .alt_tab_code=ALT_TAB,
      .ctl_tab_code=CTL_TAB
    );
    break;

  case FUN_Z: case FUN_SLS:
    deactivate_tabs(record);
    break;
  }

  return true;
}

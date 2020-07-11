#include QMK_KEYBOARD_H
#include "spektroskop.h"
#include "make_combos.h"

#define BSP_GUI LGUI_T(KC_BSPC)
#define ESC_ALT LALT_T(KC_ESC)
#define TAB_CTL LCTL_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_gergoplex(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,
    FUN_Z,   KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM, KC_DOT,  FUN_SLS,
                      TAB_CTL, ESC_ALT, SFT_ENT,        SFT_SPC, BSP_GUI, TAB_CTL
  ),

  [_LSFT] = LAYOUT_gergoplex(
    S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T),        S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P),
    S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G),        S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_DQUO,
    S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B),        S(KC_N), S(KC_M), KC_COMM, KC_DOT,  KC_QUES,
                      _______, _______, _______,        TT_RSYM, _______, _______
  ),

  [_RSFT] = LAYOUT_gergoplex(
    S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T),        S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P),
    S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G),        S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_DQUO,
    S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B),        S(KC_N), S(KC_M), KC_COMM, KC_DOT,  KC_QUES,
                      _______, _______, TT_LSYM,        _______, _______, _______
  ),

  [_LSYM] = LAYOUT_gergoplex_wrapper(
    __________________SYM__L1__________________,        __________________SYM__R1__________________,
    __________________SYM__L2__________________,        __________________SYM__R2__________________,
    __________________SYM__L3__________________,        __________________SYM__R3__________________,
                      _______, _______, _______,        _______, _______, _______
  ),

  [_RSYM] = LAYOUT_gergoplex_wrapper(
    __________________SYM__L1__________________,        __________________SYM__R1__________________,
    __________________SYM__L2__________________,        __________________SYM__R2__________________,
    __________________SYM__L3__________________,        __________________SYM__R3__________________,
                      _______, _______, _______,        _______, _______, _______
  ),

  [_FUN] = LAYOUT_gergoplex(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_F11,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F12,
    _______, GUI_1,   GUI_2,   GUI_3,   XXXXXXX,        XXXXXXX, GUI_TAB, ALT_TAB, CTL_TAB, _______,
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

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case BSP_GUI:
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

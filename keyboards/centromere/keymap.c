#include QMK_KEYBOARD_H
#include "spektroskop.h"
#include "make_combos.h"

#define BSP_GUI LGUI_T(KC_BSPC)
#define ESC_ALT LALT_T(KC_ESC)
#define TAB_CTL LCTL_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x5_3_wrapper(
    __________________BASE_L1__________________,        __________________BASE_R1__________________,
    __________________BASE_L2__________________,        __________________BASE_R2______________QUOT,
    FUN_______________BASE_L3__________________,        __________________BASE_R3_______________FUN,
                      TAB_CTL, ESC_ALT, LT_LSFT,        LT_RSFT, BSP_GUI, TAB_CTL
  ),

  [_LSFT] = LAYOUT_split_3x5_3_wrapper(
    __________________SFT_L1___________________,        __________________SFT_R1___________________,
    __________________SFT_L2___________________,        __________________SFT_R2_______________DQUO,
    __________________SFT_L3___________________,        __________________SFT_R3___________________,
                      _______, _______, __via__,        TT_RSYM, _______, _______
  ),

  [_RSFT] = LAYOUT_split_3x5_3_wrapper(
    __________________SFT_L1___________________,        __________________SFT_R1___________________,
    __________________SFT_L2___________________,        __________________SFT_R2_______________DQUO,
    __________________SFT_L3___________________,        __________________SFT_R3___________________,
                      _______, _______, TT_LSYM,        __via__, _______, _______
  ),

  [_LSYM] = LAYOUT_split_3x5_3_wrapper(
    __________________SYM_L1___________________,        __________________SYM_R1___________________,
    __________________SYM_L2___________________,        __________________SYM_R2___________________,
    __________________SYM_L3___________________,        __________________SYM_R3___________________,
                      _______, _______, __via__,        _______, _______, _______
  ),

  [_RSYM] = LAYOUT_split_3x5_3_wrapper(
    __________________SYM_L1___________________,        __________________SYM_R1___________________,
    __________________SYM_L2___________________,        __________________SYM_R2___________________,
    __________________SYM_L3___________________,        __________________SYM_R3___________________,
                      _______, _______, _______,        __via__, _______, _______
  ),

  [_FUN] = LAYOUT_split_3x5_3_wrapper(
    __________________FUN_L1___________________,        __________________FUN_R1___________________,
    __________________FUN_L2___________________,        __________________FUN_R2___________________,
    __________________FUN_L3___________________,        __________________FUN_R3___________________,
                      _______, _______, KC_LSFT,        KC_RSFT, _______, _______
  ),
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case BSP_GUI: return false;
  default: return true;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case LT_LSFT: case LT_RSFT: case TT_LSYM: case TT_RSYM:
    handle_sft_sym(keycode, record);
    break;

  case GUI_TAB: case ALT_TAB: case CTL_TAB:
    activate_tabs(keycode, record);
    break;

  case FUN_Z: case FUN_SLS:
    deactivate_tabs(record);
    break;
  }

  return true;
}

#include QMK_KEYBOARD_H
#include "spektroskop.h"
#include "make_combos.h"

#define OS_SYM OSL(_SYM)
#define ESC_CTL LCTL_T(KC_ESC)
#define QUOT_CTL RCTL_T(KC_QUOT)
#define DQUO_CTL RCTL_T(KC_DQUO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  __________________BASE_L1__________________, __________________BASE_R1__________________, KC_BSPC,
    ESC_CTL, __________________BASE_L2__________________, __________________BASE_R2______________SCLN, QUOT_CTL,
    KC_LGUI, FUN_______________BASE_L3__________________, __________________BASE_R3_______________FUN, KC_RGUI,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, LT_LSFT, OS_SYM,  OS_SYM,  LT_RSFT, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_LSFT] = LAYOUT_planck_grid_wrapper(
    S_TAB,   __________________SFT_L1___________________, __________________SFT_R1___________________, KC_BSPC,
    _______, __________________SFT_L2___________________, __________________SFT_R2_______________COLN, DQUO_CTL,
    _______, __________________SFT_L3___________________, __________________SFT_R3___________________, _______,
    _______, _______, _______, _______, __via__, XXXXXXX, XXXXXXX, TT_RSYM, _______, _______, _______, _______
  ),

  [_RSFT] = LAYOUT_planck_grid_wrapper(
    S_TAB,   __________________SFT_L1___________________, __________________SFT_R1___________________, _______,
    _______, __________________SFT_L2___________________, __________________SFT_R2_______________COLN, DQUO_CTL,
    _______, __________________SFT_L3___________________, __________________SFT_R3___________________, _______,
    _______, _______, _______, _______, TT_LSYM, XXXXXXX, XXXXXXX, __via__, _______, _______, _______, _______
  ),

  [_SYM] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  __________________SYM_L1___________________, __________________SYM_R1___________________, _______,
    _______, __________________SYM_L2___________________, __________________SYM_R2___________________, KC_RCTL,
    _______, __________________SYM_L3___________________, __________________SYM_R3___________________, _______,
    _______, _______, _______, _______, XXXXXXX, __via__, __via__, XXXXXXX, _______, _______, _______, _______
  ),

  [_LSYM] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  __________________SYM_L1___________________, __________________SYM_R1___________________, _______,
    _______, __________________SYM_L2___________________, __________________SYM_R2___________________, KC_RCTL,
    _______, __________________SYM_L3___________________, __________________SYM_R3___________________, _______,
    _______, _______, _______, _______, __via__, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______
  ),

  [_RSYM] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  __________________SYM_L1___________________, __________________SYM_R1___________________, _______,
    _______, __________________SYM_L2___________________, __________________SYM_R2___________________, KC_RCTL,
    _______, __________________SYM_L3___________________, __________________SYM_R3___________________, _______,
    _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, __via__, _______, _______, _______, _______
  ),

  [_FUN] = LAYOUT_planck_grid_wrapper(
    _______, __________________FUN_L1___________________, __________________FUN_R1___________________, _______,
    _______, __________________FUN_L2___________________, __________________FUN_R2___________________, KC_RCTL,
    _______, __________________FUN_L3___________________, __________________FUN_R3___________________, _______,
    _______, _______, _______, _______, KC_LSFT, XXXXXXX, XXXXXXX, KC_RSFT, _______, _______, _______, _______
  ),
};

void set_led_levels(int left, int right) {
  planck_ez_left_led_level(left);
  planck_ez_right_led_level(right);
}

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
  case RESET_COMBO:
    if (pressed) {
      set_led_levels(16, 16);
      reset_keyboard();
    }

    break;
  }
}

void keyboard_post_init_user(void) {
  rgb_matrix_disable();
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
  case _SYM: set_led_levels(16, 16); break;
  case _LSYM: set_led_levels(16, 0); break;
  case _RSYM:set_led_levels(0, 16); break;
  case _FUN:set_led_levels(16, 16); break;
  default: set_led_levels(0, 0);
  }

  return state;
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

  case KC_ESC:
    return clear_oneshots(record);
  }

  return true;
}


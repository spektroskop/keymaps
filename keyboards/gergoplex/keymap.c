#include QMK_KEYBOARD_H
#include "spektroskop.h"
#include "make_combos.h"

#define BSP_GUI LGUI_T(KC_BSPC)
#define ESC_ALT LALT_T(KC_ESC)
#define TAB_CTL LCTL_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_gergoplex_wrapper(
    __________________BASE_L1__________________,        __________________BASE_R1__________________,
    __________________BASE_L2__________________,        __________________BASE_R2______________QUOT,
    FUN_______________BASE_L3__________________,        __________________BASE_R3_______________FUN,
                      TAB_CTL, ESC_ALT, SFT_ENT,        SFT_SPC, BSP_GUI, TAB_CTL
  ),

  [_LSFT] = LAYOUT_gergoplex_wrapper(
    __________________SFT_L1___________________,        __________________SFT_R1___________________,
    __________________SFT_L2___________________,        __________________SFT_R2_______________DQUO,
    __________________SFT_L3___________________,        __________________SFT_R3___________________,
                      _______, _______, _______,        TT_RSYM, _______, _______
  ),

  [_RSFT] = LAYOUT_gergoplex_wrapper(
    __________________SFT_L1___________________,        __________________SFT_R1___________________,
    __________________SFT_L2___________________,        __________________SFT_R2_______________DQUO,
    __________________SFT_L3___________________,        __________________SFT_R3___________________,
                      _______, _______, TT_LSYM,        _______, _______, _______
  ),

  [_LSYM] = LAYOUT_gergoplex_wrapper(
    __________________SYM_L1___________________,        __________________SYM_R1___________________,
    __________________SYM_L2___________________,        __________________SYM_R2___________________,
    __________________SYM_L3___________________,        __________________SYM_R3___________________,
                      _______, _______, _______,        _______, _______, _______
  ),

  [_RSYM] = LAYOUT_gergoplex_wrapper(
    __________________SYM_L1___________________,        __________________SYM_R1___________________,
    __________________SYM_L2___________________,        __________________SYM_R2___________________,
    __________________SYM_L3___________________,        __________________SYM_R3___________________,
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

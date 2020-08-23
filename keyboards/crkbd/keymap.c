#include QMK_KEYBOARD_H
#include "spektroskop.h"
#include "make_combos.h"

#define ESC_CTL LCTL_T(KC_ESC)
#define QUOT_CTL RCTL_T(KC_QUOT)
#define MO_FUN MO(_FUN)

/*
 |  tab  |   q   `   w   ø   e   æ   r   |   t   |     |   y   |   u   -   i   =   o   \   P   |  bsp  |
 |esc-ctl|   a   å   s   |   d   |   f   |   g   |     |   h   |   j   (   k   )   l   |   ;   | ' ctl |
 |   gui | z-fun |   x   |   c   |   v   |   b   |     |   n   |   m   |   ,   |   .   |   /   |  gui  |
                         |  alt  |  fun  |ent-sft|     |spc-sft|  fun  |  alt  |
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_wrapper(
    KC_TAB,  __________________BASE_L1__________________,       __________________BASE_R1__________________, KC_BSPC,
    ESC_CTL, __________________BASE_L2__________________,       __________________BASE_R2______________SCLN, QUOT_CTL,
    KC_LGUI, FUN_______________BASE_L3__________________,       __________________BASE_R3_______________FUN, KC_RGUI,
                               KC_LALT, MO_FUN,  LT_LSFT,       LT_RSFT, MO_FUN,  KC_LALT
  ),

  [_LSFT] = LAYOUT_wrapper(
    S_TAB,   __________________SFT_L1___________________,       __________________SFT_R1___________________, _______,
    _______, __________________SFT_L2___________________,       __________________SFT_R2_______________COLN, KC_DQUO,
    _______, __________________SFT_L3___________________,       __________________SFT_R3___________________, _______,
                               _______, KC_ENT,  __via__,       TT_RSYM, KC_SPC,  _______
  ),

  [_RSFT] = LAYOUT_wrapper(
    S_TAB,   __________________SFT_L1___________________,       __________________SFT_R1___________________, _______,
    _______, __________________SFT_L2___________________,       __________________SFT_R2_______________COLN, KC_DQUO,
    _______, __________________SFT_L3___________________,       __________________SFT_R3___________________, _______,
                               _______, KC_ENT,  TT_LSYM,       __via__, KC_SPC,  _______
  ),

  [_SYM] = LAYOUT_wrapper(
    KC_TAB,  __________________SYM_L1___________________,       __________________SYM_R1___________________, _______,
    _______, __________________SYM_L2___________________,       __________________SYM_R2___________________, KC_RCTL,
    _______, __________________SYM_L3___________________,       __________________SYM_R3___________________, _______,
                               _______, _______, __via__,       __via__, _______, _______
  ),

  [_LSYM] = LAYOUT_wrapper(
    KC_TAB,  __________________SYM_L1___________________,       __________________SYM_R1___________________, _______,
    _______, __________________SYM_L2___________________,       __________________SYM_R2___________________, KC_RCTL,
    _______, __________________SYM_L3___________________,       __________________SYM_R3___________________, _______,
                               _______, KC_ENT, _______,        __via__, KC_SPC,  _______
  ),

  [_RSYM] = LAYOUT_wrapper(
    KC_TAB,  __________________SYM_L1___________________,       __________________SYM_R1___________________, _______,
    _______, __________________SYM_L2___________________,       __________________SYM_R2___________________, KC_RCTL,
    _______, __________________SYM_L3___________________,       __________________SYM_R3___________________, _______,
                               _______, KC_ENT,  __via__,       _______, KC_SPC,  _______
  ),

  [_FUN] = LAYOUT_wrapper(
    _______, __________________FUN_L1___________________,        __________________FUN_R1___________________, _______,
    _______, __________________FUN_L2___________________,        __________________FUN_R2___________________, KC_RCTL,
    _______, __________________FUN_L3___________________,        __________________FUN_R3___________________, _______,
                               _______, KC_ENT,  KC_LSFT,        KC_RSFT, KC_SPC,  _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case LT_LSFT: case LT_RSFT: case TT_LSYM: case TT_RSYM:
    handle_sft_sym(keycode, record);
    break;

  case GUI_TAB: case ALT_TAB: case CTL_TAB:
    activate_tabs(keycode, record);
    break;

  case MO_FUN: case FUN_Z: case FUN_SLS:
    deactivate_tabs(record);
    break;
  }

  return true;
}

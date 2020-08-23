#pragma once

#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _LSFT, _RSFT,
  _SYM, _LSYM, _RSYM,
  _FUN,
};

enum keycodes {
  DUMMY = SAFE_RANGE,
  GUI_TAB, ALT_TAB, CTL_TAB,
};


#define __via__ _______

#define FUN_SLS LT(_FUN, KC_SLSH)
#define FUN_Z LT(_FUN, KC_Z)
#define GUI_1 LGUI(KC_1)
#define GUI_2 LGUI(KC_2)
#define GUI_3 LGUI(KC_3)
#define S_TAB S(KC_TAB)
#define LT_LSFT LT(_LSFT, KC_ENT)
#define LT_RSFT LT(_RSFT, KC_SPC)
#define TT_LSYM TT(_LSYM)
#define TT_RSYM TT(_RSYM)

#define LAYOUT_planck_grid_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_gergoplex_wrapper(...) LAYOUT_gergoplex(__VA_ARGS__)
#define LAYOUT_split_3x5_3_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

#define __________________BASE_L1__________________ KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define __________________BASE_R1__________________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define __________________BASE_L2__________________ KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define __________________BASE_R2______________SCLN KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define __________________BASE_R2______________QUOT KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT
#define FUN_______________BASE_L3__________________ FUN_Z,   KC_X,    KC_C,    KC_V,    KC_B
#define __________________BASE_L3__________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B
#define __________________BASE_R3_______________FUN KC_N,    KC_M,    KC_COMM, KC_DOT,  FUN_SLS
#define __________________BASE_R3__________________ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define __________________SFT_L1___________________ S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T)
#define __________________SFT_R1___________________ S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P)
#define __________________SFT_L2___________________ S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G)
#define __________________SFT_R2_______________COLN S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_COLN
#define __________________SFT_R2_______________DQUO S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_DQUO
#define __________________SFT_L3___________________ S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B)
#define __________________SFT_R3___________________ S(KC_N), S(KC_M), KC_COMM, KC_DOT,  KC_QUES

#define __________________SYM_L1___________________ KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define __________________SYM_R1___________________ KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR
#define __________________SYM_L2___________________ KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define __________________SYM_R2___________________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define __________________SYM_L3___________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________SYM_R3___________________ XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  XXXXXXX

#define __________________FUN_L1___________________ KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define __________________FUN_R1___________________ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define __________________FUN_L2___________________ KC_F11,  KC_HOME, KC_PGUP, KC_PGDN, KC_END
#define __________________FUN_R2___________________ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F12
#define __________________FUN_L3___________________ __via__, GUI_1,   GUI_2,   GUI_3,   XXXXXXX
#define __________________FUN_R3___________________ XXXXXXX, GUI_TAB, ALT_TAB, CTL_TAB, __via__

bool is_release(keyrecord_t *record);
bool is_press(keyrecord_t *record);
void handle_sft_sym(uint16_t keycode, keyrecord_t *record);
void activate_tabs(uint16_t keycode, keyrecord_t *record);
void deactivate_tabs(keyrecord_t *record);
bool clear_oneshots(keyrecord_t *record);

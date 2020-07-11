#pragma once

#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _LSFT,
  _RSFT,
  _SYM,
  _LSYM,
  _RSYM,
  _FUN,
};

enum keycodes {
  GUI_TAB = SAFE_RANGE,
  ALT_TAB,
  CTL_TAB,
};

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

#define LAYOUT_planck_grid_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)
#define LAYOUT_wrapper(...)             LAYOUT(__VA_ARGS__)
#define LAYOUT_gergoplex_wrapper(...)   LAYOUT_gergoplex(__VA_ARGS__)

#define __________________BASE_L1__________________ KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define __________________BASE_R1__________________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define __________________BASE_L2__________________ KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define __________________BASE_R2______________SCLN KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define __________________BASE_R2______________QUOT KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT
#define FUN_______________BASE_L3__________________ FUN_Z,   KC_X,    KC_C,    KC_V,    KC_B
#define __________________BASE_R3_______________FUN KC_N,    KC_M,    KC_COMM, KC_DOT,  FUN_SLS

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

bool is_release(keyrecord_t *record);
bool is_press(keyrecord_t *record);

struct sft_sym {
  keyrecord_t *record;
  uint16_t keycode;
  uint16_t lsft_code;
  uint16_t rsft_code;
  uint16_t lsym_code;
  uint16_t rsym_code;
  int lsym_layer;
  int rsym_layer;
};

void handle_sft_sym_base(struct sft_sym args);
#define handle_sft_sym(...) handle_sft_sym_base((struct sft_sym){__VA_ARGS__});

struct tabs {
  keyrecord_t *record;
  uint16_t keycode;
  uint16_t gui_tab_code;
  uint16_t alt_tab_code;
  uint16_t ctl_tab_code;
};

void activate_tabs_base(struct tabs args);
#define activate_tabs(...) activate_tabs_base((struct tabs){__VA_ARGS__});
void deactivate_tabs(keyrecord_t *record);

bool clear_oneshots(keyrecord_t *record);

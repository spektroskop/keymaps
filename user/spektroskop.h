#pragma once

#include QMK_KEYBOARD_H

#define LAYOUT_planck_grid_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)
#define LAYOUT_wrapper(...)             LAYOUT(__VA_ARGS__)
#define LAYOUT_gergoplex_wrapper(...)   LAYOUT_gergoplex(__VA_ARGS__)

#define __________________SYM__L1__________________ KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define __________________SYM__R1__________________ KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR
#define __________________SYM__L2__________________ KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define __________________SYM__R2__________________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define __________________SYM__L3__________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________SYM__R3__________________ XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  XXXXXXX

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
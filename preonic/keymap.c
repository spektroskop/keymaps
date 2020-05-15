#include QMK_KEYBOARD_H

#define SFT_Z MT(MOD_LSFT, KC_Z)
#define CTL_X MT(MOD_LCTL, KC_X)
#define CTL_DOT MT(MOD_RCTL, KC_DOT)
#define SFT_SLS MT(MOD_RSFT, KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_preonic_grid( \
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    _______, _______, KC_LALT, KC_ENT,  KC_LCTL, KC_TAB,  KC_BSPC, KC_RCTL, KC_SPC,  KC_LALT, _______, _______
  )
};

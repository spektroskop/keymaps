#include QMK_KEYBOARD_H

#define SFT_Z MT(MOD_LSFT, KC_Z)
#define CTL_X MT(MOD_LCTL, KC_X)
#define CTL_DOT MT(MOD_RCTL, KC_DOT)
#define SFT_SLS MT(MOD_RSFT, KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_preonic_grid( \
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,  KC_ESC,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        SFT_Z,   CTL_X,   KC_C,    KC_V,    KC_B,    KC_TAB,  KC_ESC,  KC_N,    KC_M,    KC_COMM, CTL_DOT, SFT_SLS,
        _______, KC_LGUI, KC_LALT, MO(1),   KC_ENT,  KC_ENT,  KC_SPC,  KC_SPC,  KC_BSPC, KC_INS,  KC_QUOT, TT(1)
    ),
    [1] = LAYOUT_preonic_grid( \
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  KC_GRV,  _______
    ),
};
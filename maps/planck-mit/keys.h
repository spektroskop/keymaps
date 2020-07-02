#pragma once

enum {
    SELECT = SAFE_RANGE,
    ALT_TAB,
    GUI_TAB,
    CTL_TAB,
};

// R1

#define L101    KC_Q
#define L102    KC_W
#define L103    KC_E
#define L104    KC_R
#define L105    KC_T

#define R101    KC_Y
#define R102    KC_U
#define R103    KC_I
#define R104    KC_O
#define R105    KC_P

// R2

#define L201    KC_A
#define L202    KC_S
#define L203    KC_D
#define L204    KC_F
#define L205    KC_G

#define R201    KC_H
#define R202    KC_J
#define R203    KC_K
#define R204    KC_L
#define R205    KC_QUOT

// R3

#define L301     LT(_NAV, KC_Z)
#define L302     LCTL_T(KC_X)
#define L303     LALT_T(KC_C)
#define L304     LGUI_T(KC_V)
#define L305     KC_B

#define R301     KC_N
#define R302     RGUI_T(KC_M)
#define R303     LALT_T(KC_COMM)
#define R304     RCTL_T(KC_DOT)
#define R305     LT(_NAV, KC_SLSH)

// LEFT THUMB

#define LT1      LT(_NAV, KC_ENT)
#define LT2      LT(_LSFT, KC_ESC)
#define LT3      OSL(_RSYM)

// RIGHT THUMB

#define RT1      OSL(_LSYM)
#define RT2      LT(_RSFT, KC_SPC)
#define RT3      LT(_NAV, KC_INS)


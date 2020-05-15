#include QMK_KEYBOARD_H

enum layers {
    _BASE1, _BASE2,
    _LSFT, _RSFT,
    _SYM,
    _NOR,
    _SEL,
    _MOUSE,
    _FUNC,
};

enum keycodes {
    XK_SYM = SAFE_RANGE,
    XK_SEL,
};

#define GUI_ESC LGUI_T(KC_ESC)
#define LANG LCTL(KC_SPACE)
#define GUI_1 LGUI(KC_1)
#define GUI_2 LGUI(KC_2)
#define GUI_3 LGUI(KC_3)
#define SFT_TAB S(KC_TAB)
#define SFT_INS S(KC_INS)
#define SFT_DEL S(KC_DEL)

#define DF_1 DF(_BASE1)
#define DF_2 DF(_BASE2)
#define LT_ENT1 LT(_LSFT, KC_ENT)
#define LT_SPC1 LT(_RSFT, KC_SPC)
#define LT_ENT2 LT(_SYM, KC_ENT)
#define LT_SPC2 LT(_SYM, KC_SPC)
#define SFT_Z LSFT_T(KC_Z)
#define SFT_SLSH RSFT_T(KC_SLSH)
#define FUN_DEL LT(_FUNC, KC_DEL)
#define FUN_INS LT(_FUNC, KC_INS)
#define MOUSE TG(_MOUSE)
#define NOR MO(_NOR)

#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)

#define EUR_AA ALGR(KC_W)
#define EUR_AE ALGR(KC_Q)
#define EUR_OE ALGR(KC_L)

#define __zzz__ _______

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE1] = LAYOUT_planck_grid(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,  KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        NOR,     FUN_DEL, OS_LALT, LT_ENT1, OS_LCTL, GUI_ESC, GUI_ESC, OS_RCTL, LT_SPC1, OS_LALT, FUN_INS, KC_RGUI
    ),

    [_BASE2] = LAYOUT_planck_grid(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,  KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        SFT_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  SFT_SLSH,
        NOR,     FUN_DEL, OS_LALT, LT_ENT2, OS_LCTL, GUI_ESC, GUI_ESC, OS_RCTL, LT_SPC2, OS_LALT, FUN_INS, KC_RGUI
    ),

    [_LSFT] = LAYOUT_planck_grid(
        S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), XXXXXXX, XXXXXXX, S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P),
        S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), SFT_TAB, _______, S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_COLN,
        S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), KC_LCBR, KC_RCBR, S(KC_N), S(KC_M), KC_LT,   KC_GT,   KC_QUES,
        XXXXXXX, KC_DEL,  _______, __zzz__, _______, _______, _______, _______, XK_SYM,  _______, SFT_INS, _______
    ),

    [_RSFT] = LAYOUT_planck_grid(
        S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), XXXXXXX, XXXXXXX, S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P),
        S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), SFT_TAB, _______, S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_COLN,
        S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), KC_LCBR, KC_RCBR, S(KC_N), S(KC_M), KC_LT,   KC_GT,   KC_QUES,
        XXXXXXX, KC_DEL,  _______, XK_SYM,  _______, _______, _______, _______, __zzz__, _______, SFT_INS, _______
    ),

    [_SYM] = LAYOUT_planck_grid(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_GRV,  KC_QUOT, KC_BSLS, KC_MINS, KC_EQL,  XXXXXXX, XXXXXXX, KC_TILD, KC_DQUO, KC_COMM, KC_DOT,  KC_SLSH,
        XXXXXXX, KC_DEL,  _______, __zzz__, _______, _______, _______, _______, __zzz__, KC_PIPE, KC_UNDS, KC_PLUS
    ),

    [_FUNC] = LAYOUT_planck_grid(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        XK_SEL,  GUI_1,   GUI_2,   GUI_3,   XXXXXXX, DF_1,    DF_2,    XXXXXXX, MOUSE,   XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, __zzz__, _______, KC_ENT,  _______, RESET,   RESET,   _______, KC_SPC,  _______, __zzz__, _______
    ),

    [_MOUSE] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, KC_Q,    KC_W,    KC_E,   XXXXXXX,  XXXXXXX, XXXXXXX, KC_WH_D, KC_MS_U, KC_WH_U, XXXXXXX,
        KC_LSFT, KC_LCTL, KC_A,    KC_S,    KC_D,   XXXXXXX,  XXXXXXX, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,
        XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,   XXXXXXX,  XXXXXXX, XXXXXXX, MOUSE,   XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN2, KC_SPC, _______,  _______, KC_BTN3, KC_BTN1, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_SEL] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        __zzz__, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, __zzz__, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NOR] = LAYOUT_planck_grid(
        _______, _______, EUR_AE,  _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, EUR_OE,  _______,
        EUR_AA,  _______, _______, _______, _______, KC_TAB,  _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______,
        __zzz__, KC_DEL,  _______, KC_ENT,  _______, LANG,    LANG,    _______, KC_SPC,  _______, KC_INS,  _______
    ),
};

void keyboard_post_init_user(void) {
  rgb_matrix_disable();
}

void set_led_levels(int left, int right) {
    planck_ez_left_led_level(left);
    planck_ez_right_led_level(right);
}

bool is_press(keyrecord_t *record) {
    return record->event.pressed;
}

bool is_release(keyrecord_t *record) {
    return !record->event.pressed;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _SYM:
        if (layer_state_is(_LSFT)) {
            set_led_levels(0, 32);
        } else if (layer_state_is(_RSFT)) {
            set_led_levels(32, 0);
        }

        break;

    case _MOUSE:
        set_led_levels(32, 32);
        break;

    default:
        set_led_levels(0, 0);
    }

    return state;
}

bool sym_hold = false;
bool sym_bspc = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case XK_SYM:
        if (is_release(record))  {
            if (sym_bspc) {
                unregister_code(KC_BSPC);
                sym_bspc = true;
            }

            sym_hold = false;
        } else if (layer_state_is(_SYM)) {
            if (layer_state_is(_LSFT)) {
                register_code(KC_BSPC);
                sym_bspc = true;
            } else if (layer_state_is(_RSFT)) {
                tap_code(KC_TAB);
            }
        } else {
            layer_invert(_SYM);
            sym_hold = true;
        }

    case GUI_ESC:
        if (is_release(record) && layer_state_is(_SYM)) {
            layer_invert(_SYM);
            return false;
        }

    case LT_ENT1:
    case LT_SPC1:
        if (is_release(record) && layer_state_is(_SYM)) {
            layer_move(_BASE1);
        }

    case XK_SEL:
        if (is_press(record)) {
            layer_move(_SEL);
            register_code(KC_LGUI);
            tap_code(KC_GRV);
        }

    case FUN_DEL:
    case FUN_INS:
        if (is_release(record) && layer_state_is(_SEL)) {
            layer_off(_SEL);
            unregister_code(KC_LGUI);
        }
    }

    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case XK_SYM:
        break;

    default:
        if (sym_hold) {
            layer_invert(_SYM);
            sym_hold = false;
        }
    }
}

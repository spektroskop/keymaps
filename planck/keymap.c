#include QMK_KEYBOARD_H
#include <print.h>

enum layers {
    _BASE,
    _LSFT,
    _RSFT,
    _SYM,
    _FUN,
    _NOR,
};

enum keycodes {
    XK_SYM = SAFE_RANGE,
};

enum combos {
  ESC_COMBO,
};

const uint16_t PROGMEM esc_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [ESC_COMBO] = COMBO(esc_combo, KC_ESC),
};

#define ___z___ _______

#define BRC_FUN LT(_FUN, KC_LBRC)
#define ENT_SFT LT(_LSFT, KC_ENT)
#define TAB_CTL MT(MOD_LCTL, KC_TAB)
#define S_TAB S(KC_TAB)

#define INS_ALT MT(MOD_LALT, KC_INS)
#define SPC_SFT LT(_RSFT, KC_SPC)
#define BRC_GUI MT(MOD_RGUI, KC_RBRC)
#define S_INS S(KC_INS)

#define NOR_V LT(_NOR, KC_V)
#define NOR_M LT(_NOR, KC_M)
#define EUR_AA ALGR(KC_W)
#define EUR_AE ALGR(KC_Q)
#define EUR_OE ALGR(KC_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ,-----------------------------------------------------------------------.
     * |  q     w     e     r     t                 y     u     i     o     p  |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |  a     s     d     f     g                 h     j esc k     l     ;  |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |  z     x     c     v     b                 n     m     ,     .    /   |
     * |                   nor                           nor                   |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----'
     * |              [    ent   tab               ins   spc    ]              |
     * |             fun   sft   ctl               alt   sft   gui             |
     * |                   esc                           bsp                   |
     * `-----------------------------------------------+-----+-----+-----+-----'
     */

    [_BASE] = LAYOUT_planck_grid(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    NOR_V,   KC_B,    _______, _______, KC_N,    NOR_M,   KC_COMM, KC_DOT,  KC_SLSH,
        _______, _______, BRC_FUN, ENT_SFT, TAB_CTL, _______, _______, INS_ALT, SPC_SFT, BRC_GUI, _______, _______
    ),

    [_LSFT] = LAYOUT_planck_grid(
        S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), _______, _______, S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P),
        S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), _______, _______, S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_COLN,
        S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), _______, _______, S(KC_N), S(KC_M), KC_LT,   KC_GT,   KC_QUES,
        _______, _______, KC_LCBR, ___z___, S_TAB,   _______, _______, S_INS,   XK_SYM,  KC_RCBR, _______, _______
    ),

    [_RSFT] = LAYOUT_planck_grid(
        S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), _______, _______, S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P),
        S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), _______, _______, S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_COLN,
        S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), _______, _______, S(KC_N), S(KC_M), KC_LT,   KC_GT,   KC_QUES,
        _______, _______, KC_LCBR, XK_SYM,  S_TAB,   _______, _______, S_INS,   ___z___, KC_RCBR,   _______, _______
    ),

    /*
     * ,-----------------------------------------------------------------------.
     * |  !     @     #     $     %                 ^     &     *     (     )  |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |  1     2     3     4     5                 6     7     8     9     0  |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |  `     '     \     -     =                 ~     "     ,     .     _  |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----'
     * |                          +                 |                          |
     * `-----------------------------------------------+-----+-----+-----+-----'
     */

    [_SYM] = LAYOUT_planck_grid(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_GRV,  KC_QUOT, KC_SLSH, KC_MINS, KC_EQL,  _______, _______, KC_TILD, KC_DQUO, KC_COMM, KC_DOT,  KC_UNDS,
        _______, _______, _______, ___z___, KC_PLUS, _______, _______, KC_PIPE, ___z___, _______, _______, _______
    ),

    /*
     * ,-----------------------------------------------------------------------.
     * | f1    f2    f3    f4    f5                f6    f7    f8    f9    f10 |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * | f11  home   pgup  pgdn  end               left  down  up   right  f12 |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |                                                                       |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----'
     * |                                                                       |
     * `-----------------------------------------------+-----+-----+-----+-----'
     */

    [_FUN] = LAYOUT_planck_grid(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_F11,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, ___z___, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, RESET,   _______, _______
    ),

    [_NOR] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, EUR_AE,  XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, EUR_OE,  XXXXXXX,
        EUR_AA,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, ___z___, XXXXXXX, _______, _______, XXXXXXX, ___z___, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, XXXXXXX, KC_LSFT, XXXXXXX, _______, _______, XXXXXXX, KC_RSFT, XXXXXXX, _______, _______
    ),
};


void keyboard_post_init_user(void) {
  rgb_matrix_disable();
}

void set_led_levels(int left, int right) {
    planck_ez_left_led_level(left);
    planck_ez_right_led_level(right);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _SYM:
        if (layer_state_is(_LSFT)) {
            set_led_levels(0, 16);
        } else if (layer_state_is(_RSFT)) {
            set_led_levels(16, 0);
        }

        break;

    case _FUN:
        set_led_levels(16, 16);

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
        if (layer_state_is(_SYM)) {
            if (record->event.pressed) {
              // sym_hold = true;

                if (layer_state_is(_LSFT)) {
                    register_code(KC_BSPC);
                    sym_bspc = true;
                } else if (layer_state_is(_RSFT)) {
                    tap_code(KC_ESC);
                }
            } else {
                if (!layer_state_is(_LSFT) && !layer_state_is(_RSFT)) {
                  layer_off(_SYM);
                  break;
                }

                sym_hold = false;

                if (sym_bspc) {
                    sym_bspc = false;
                    unregister_code(KC_BSPC);
                }
            }
        } else {
            if (record->event.pressed) {
                sym_hold = true;
                layer_on(_SYM);
            }
        }

        break;

    case ENT_SFT:
    case SPC_SFT:
        if (!record->event.pressed) {
            if (layer_state_is(_SYM)) {
              if (sym_hold) {
                sym_hold = false;
              } else {
                layer_off(_SYM);
              }
            }
        }

        break;
    }

    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ENT_SFT:
    case SPC_SFT:
        break;

    case XK_SYM:
        break;

    default:
        if (sym_hold) {
            sym_hold = false;
            layer_off(_SYM);
        }
    }
}

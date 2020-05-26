#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _LSFT,
    _RSFT,
    _SYM,
    _FUN,
    _NOR,
};

enum keycodes {
    SYM = SAFE_RANGE,
    SELECT,
};

#define ___z___ _______

#define CTL_COM CTL_T(KC_COMM)
#define CTL_DOT CTL_T(KC_DOT)

#define SYM_F LT(_SYM, KC_F)
#define SYM_J LT(_SYM, KC_J)

#define NOR_V LT(_NOR, KC_V)
#define NOR_M LT(_NOR, KC_M)

#define FUN MO(_FUN)
#define TAB_FUN LT(_FUN, KC_TAB)
#define ENT_SFT LT(_LSFT, KC_ENT)
#define ESC_SFT LT(_LSFT, KC_ESC)
#define BRC_CTL MT(MOD_LCTL, KC_LBRC)
#define S_TAB S(KC_TAB)

#define BRC_ALT MT(MOD_LALT, KC_RBRC)
#define SPC_SFT LT(_RSFT, KC_SPC)
#define INS_GUI MT(MOD_RGUI, KC_INS)
#define S_INS S(KC_INS)

#define GUI_1 LGUI(KC_1)
#define GUI_2 LGUI(KC_2)
#define GUI_3 LGUI(KC_3)

#define EUR_AA ALGR(KC_W)
#define EUR_AE ALGR(KC_Q)
#define EUR_OE ALGR(KC_L)

enum combos {
    PIPE_COMBO,
    UNDS_COMBO,
    PLUS_COMBO,
};

const uint16_t PROGMEM pipe_combo[] = {KC_QUOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM unds_combo[] = {KC_SLSH, KC_MINS, COMBO_END};
const uint16_t PROGMEM plus_combo[] = {KC_MINS, KC_EQL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [PIPE_COMBO] = COMBO(pipe_combo, KC_PIPE),
  [UNDS_COMBO] = COMBO(unds_combo, KC_UNDS),
  [PLUS_COMBO] = COMBO(plus_combo, KC_PLUS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*---------------------------------------------------------------------*\
    |        w     e     r     t                 h     u     i     o        |
    |        W     E     R     T                 H     U     I     O        |
    |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
    |  ,     s     d     f     g                bsp    j     k     l     .  |
    |  ;     S     D     F     G                       J     K     L     :  |
    | ctl               sym                           sym               ctl |
    |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
    |  a     x     c     v     b                 n     m     p     q     y  |
    |  A     X     C     V     B                 N     M     P     Q     Y  |
    |                   nor                           nor                   |
    |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
    |  z          tab   esc    [                 ]    spc   ins          /  |
    |  Z          fun   sft   ctl               alt   sft   gui          ?  |
    |                   ent                           bsp                   |
    \*---------------------------------------------------------------------*/

    [_BASE] = LAYOUT_planck_grid(
        _______, KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, KC_H,    KC_U,    KC_I,    KC_O,    _______,
        CTL_COM, KC_S,    KC_D,    SYM_F,   KC_G,    _______, _______, KC_BSPC, SYM_J,   KC_K,    KC_L,    CTL_DOT,
        KC_A,    KC_X,    KC_C,    NOR_V,   KC_B,    _______, _______, KC_N,    NOR_M,   KC_P,    KC_Q,    KC_Y,
        KC_Z,    _______, TAB_FUN, ESC_SFT, BRC_CTL, _______, _______, BRC_ALT, SPC_SFT, INS_GUI, _______, KC_SLSH
    ),

    [_LSFT] = LAYOUT_planck_grid(
        _______, S(KC_W), S(KC_E), S(KC_R), S(KC_T), _______, _______, S(KC_H), S(KC_U), S(KC_I), S(KC_O), _______,
        KC_SCLN, S(KC_S), S(KC_D), S(KC_F), S(KC_G), _______, _______, KC_BSPC, S(KC_J), S(KC_K), S(KC_L), KC_COLN,
        S(KC_A), S(KC_X), S(KC_C), S(KC_V), S(KC_B), _______, _______, S(KC_N), S(KC_M), S(KC_P), S(KC_Q), S(KC_Y),
        S(KC_Z), _______, S_TAB,   ___z___, KC_LCBR, _______, _______, KC_RCBR, SYM,     S_INS,   _______, KC_QUES
    ),

    [_RSFT] = LAYOUT_planck_grid(
        _______, S(KC_W), S(KC_E), S(KC_R), S(KC_T), _______, _______, S(KC_H), S(KC_U), S(KC_I), S(KC_O), _______,
        KC_SCLN, S(KC_S), S(KC_D), S(KC_F), S(KC_G), _______, _______, KC_BSPC, S(KC_J), S(KC_K), S(KC_L), KC_COLN,
        S(KC_A), S(KC_X), S(KC_C), S(KC_V), S(KC_B), _______, _______, S(KC_N), S(KC_M), S(KC_P), S(KC_Q), S(KC_Y),
        S(KC_Z), _______, S_TAB,   SYM,     KC_LCBR, _______, _______, KC_RCBR, ___z___, S_INS,   _______, KC_QUES
    ),

    /*---------------------------------------------------------------------*\
    |  !     @     #     $     %                 ^     &     *     (     )  |
    |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
    |  1     2     3     4     5                 6     7     8     9     0  |
    |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
    |  `     '  |  \  _  -  +  =                 ~     "     ,     .     /  |
    |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
    |              |           +                 _           :              |
    \*---------------------------------------------------------------------*/

    [_SYM] = LAYOUT_planck_grid(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_GRV,  KC_QUOT, KC_SLSH, KC_MINS, KC_EQL,  _______, _______, KC_TILD, KC_DQUO, KC_COMM, KC_DOT,  KC_SCLN,
        _______, _______, KC_PIPE, ___z___, KC_PLUS, _______, _______, KC_UNDS, ___z___, KC_COLN, _______, _______
    ),

    /*---------------------------------------------------------------------*\
    |gui 1 gui 2 gui 3  vol+ vol-               f1    f2    f3    f4    f5  |
    |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
    | sel  home   pgup  pgdn  end               left  down  up   right      |
    |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
    |                                           f6    f7    f8    f9    f10 |
    |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----'
    |                         rst                     f11   f12             |
    \*---------------------------------------------------------------------*/

    [_FUN] = LAYOUT_planck_grid(
        GUI_1,   GUI_2,   GUI_3,   KC_VOLU, KC_VOLD, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
        SELECT,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        KC_ASDN, KC_ASUP, KC_ASRP, XXXXXXX, XXXXXXX, _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        _______, _______, ___z___, XXXXXXX, RESET,   _______, _______, XXXXXXX, KC_F11,  KC_F12,  _______, _______
    ),

    [_NOR] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, EUR_AE,  XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, EUR_OE,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        EUR_AA,  XXXXXXX, XXXXXXX, ___z___, XXXXXXX, _______, _______, XXXXXXX, ___z___, XXXXXXX, XXXXXXX, XXXXXXX,
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
bool sel = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SYM:
        if (layer_state_is(_SYM)) {
            if (record->event.pressed) {
              // sym_hold = true;

                if (layer_state_is(_LSFT)) {
                    register_code(KC_BSPC);
                    sym_bspc = true;
                } else if (layer_state_is(_RSFT)) {
                    // tap_code(KC_ESC);
                    tap_code(KC_ENT);
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
    case ESC_SFT:
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

    case SELECT:
        if (record->event.pressed) {
            sel = true;
            register_code(KC_LGUI);
            tap_code(KC_GRV);
        }

    case TAB_FUN:
        if (!record->event.pressed) {
            if (sel) {
                unregister_code(KC_LGUI);
            }
        }
    }

    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ENT_SFT:
    case ESC_SFT:
    case SPC_SFT:
        break;

    case SYM:
        break;

    default:
        if (sym_hold) {
            sym_hold = false;
            layer_off(_SYM);
        }
    }
}

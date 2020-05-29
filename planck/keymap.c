#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _LSFT,
    _RSFT,
    _LSYM,
    _RSYM,
    _FUN,
    _NOR,
};

enum keycodes {
    SELECT = SAFE_RANGE,
};

#define ___z___ _______
#define ___x___ XXXXXXX

#define GUI_Z GUI_T(KC_Z)
#define CTL_X CTL_T(KC_X)
#define ALT_C ALT_T(KC_C)

#define ESC_FUN LT(_FUN, KC_ESC)
#define ENT_SFT LT(_LSFT, KC_ENT)
#define RSYM TT(_RSYM)
#define S_TAB S(KC_TAB)

#define ALT_COM ALT_T(KC_COMM)
#define CTL_DOT CTL_T(KC_DOT)
#define GUI_SLS GUI_T(KC_SLSH)

#define SPC_SFT LT(_RSFT, KC_SPC)
#define LSYM TT(_LSYM)
#define INS_NOR LT(_NOR, KC_TAB)
#define S_INS S(KC_INS)

#define EUR_AA ALGR(KC_W)
#define EUR_AE ALGR(KC_Q)
#define EUR_OE ALGR(KC_L)

#define GUI_1 LGUI(KC_1)
#define GUI_2 LGUI(KC_2)
#define GUI_3 LGUI(KC_3)

enum combos {
    RESET_COMBO,
    GRV_COMBO,  TILD_COMBO,
    MINS_COMBO, UNDS_COMBO,
    EQL_COMBO,  PLUS_COMBO,
    BSLS_COMBO, PIPE_COMBO,
    SCLN_COMBO, COLN_COMBO,
};

const uint16_t PROGMEM reset_combo[] = {KC_Q, KC_P, COMBO_END};
const uint16_t PROGMEM grv_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM tild_combo[] = {S(KC_Q), S(KC_W), COMBO_END};
const uint16_t PROGMEM mins_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM unds_combo[] = {S(KC_U), S(KC_I), COMBO_END};
const uint16_t PROGMEM eql_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM plus_combo[] = {S(KC_I), S(KC_O), COMBO_END};
const uint16_t PROGMEM bsls_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM pipe_combo[] = {S(KC_O), S(KC_P), COMBO_END};
const uint16_t PROGMEM scln_combo[] = {KC_L, KC_QUOT, COMBO_END};
const uint16_t PROGMEM coln_combo[] = {S(KC_L), S(KC_QUOT), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [RESET_COMBO] = COMBO_ACTION(reset_combo),
  [GRV_COMBO] = COMBO(grv_combo, KC_GRV),
  [TILD_COMBO] = COMBO(tild_combo, KC_TILD),
  [MINS_COMBO] = COMBO(mins_combo, KC_MINS),
  [UNDS_COMBO] = COMBO(unds_combo, KC_UNDS),
  [EQL_COMBO] = COMBO(eql_combo, KC_EQL),
  [PLUS_COMBO] = COMBO(plus_combo, KC_PLUS),
  [BSLS_COMBO] = COMBO(bsls_combo, KC_BSLS),
  [PIPE_COMBO] = COMBO(pipe_combo, KC_PIPE),
  [SCLN_COMBO] = COMBO(scln_combo, KC_SCLN),
  [COLN_COMBO] = COMBO(coln_combo, KC_COLN),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case RESET_COMBO:
      if (pressed) {
        reset_keyboard();
      }

      break;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*---------------------------------------------------------------------*\
    |  q  `  w     e     r     t                 y     u  -  i  =  o  \  p  |  qp = reset
    |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
    |  a     s     d     f     g                 h     j     k     l  ;  '  |
    |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
    |  z     x     c     v     b                 n     m     ,     .     /  |
    | gui   ctl   alt                                       alt   ctl   gui |
    |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
    |             esc   ent   tab               bsp   spc   ins             |
    |             fun   sft                           sft   nor             |
    \*---------------------------------------------------------------------*/

    [_BASE] = LAYOUT_planck_grid(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    ___x___, ___x___, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    ___x___, ___x___, KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,
        GUI_Z,   CTL_X,   ALT_C,   KC_V,    KC_B,    ___x___, ___x___, KC_N,    KC_M,    ALT_COM, CTL_DOT, GUI_SLS,
        ___x___, ___x___, ESC_FUN, ENT_SFT, KC_TAB,  ___x___, ___x___, KC_BSPC, SPC_SFT, INS_NOR, ___x___, ___x___
    ),

    [_NOR] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, EUR_AE,  XXXXXXX, XXXXXXX, ___x___, ___x___, XXXXXXX, XXXXXXX, XXXXXXX, EUR_OE,  XXXXXXX,
        EUR_AA,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ___x___, ___x___, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ___x___, ___x___, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        ___x___, ___x___, XXXXXXX, KC_LSFT, XXXXXXX, ___x___, ___x___, XXXXXXX, KC_RSFT, XXXXXXX, ___x___, ___x___
    ),

    /*---------------------------------------------------------------------*\
    |  Q  ~  W     E     R     T                 Y     U  _  I  +  O  |  P  |
    |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
    |  A     S     D     F     G                 H     J     J     L  :  "  |
    |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
    |  Z     X     C     V     B                 N     M     <     >     ?  |
    |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
    |                        s-tab              del   sym  s-ins            |
    \*---------------------------------------------------------------------*/

    [_LSFT] = LAYOUT_planck_grid(
        S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), ___x___, ___x___, S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P),
        S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), ___x___, ___x___, S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_DQUO,
        S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), ___x___, ___x___, S(KC_N), S(KC_M), KC_LT,   KC_GT,   KC_QUES,
        ___x___, ___x___, _______, ___z___, S_TAB,   ___x___, ___x___, KC_DEL, LSYM,    S_INS,   ___x___, ___x___
    ),

    [_RSFT] = LAYOUT_planck_grid(
        S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), ___x___, ___x___, S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P),
        S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), ___x___, ___x___, S(KC_H), S(KC_J), S(KC_K), S(KC_L), KC_DQUO,
        S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), ___x___, ___x___, S(KC_N), S(KC_M), KC_LT,   KC_GT,   KC_QUES,
        ___x___, ___x___, _______, RSYM,    S_TAB,   ___x___, ___x___, KC_DEL,  ___z___, S_INS,   ___x___, ___x___
    ),

    /*---------------------------------------------------------------------*\
    |  !     @     #     $     %                 ^     &     *     (     )  |
    |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
    |  1     2     3     4     5                 6     7     8     9     0  |
    |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
    |                    }     ]                 [     {     ,     .        |
    |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
    |                                                                       |
    \*---------------------------------------------------------------------*/

    [_LSYM] = LAYOUT_planck_grid(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, ___x___, ___x___, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    ___x___, ___x___, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_RCBR, KC_RBRC, ___x___, ___x___, KC_LBRC, KC_LCBR, KC_COMM, KC_DOT, XXXXXXX,
        ___x___, ___x___, _______, ___z___, KC_TAB,  ___x___, ___x___, KC_BSPC, ___z___, _______, ___x___, ___x___
    ),

    [_RSYM] = LAYOUT_planck_grid(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, ___x___, ___x___, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    ___x___, ___x___, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_RCBR, KC_RBRC, ___x___, ___x___, KC_LBRC, KC_LCBR, KC_COMM, KC_DOT, XXXXXXX,
        ___x___, ___x___, _______, ___z___, KC_TAB,  ___x___, ___x___, KC_BSPC, ___z___, _______, ___x___, ___x___
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
        GUI_1,   GUI_2,   GUI_3,   KC_VOLU, KC_VOLD, ___x___, ___x___, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
        SELECT,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,  ___x___, ___x___, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        KC_ASDN, KC_ASUP, KC_ASRP, XXXXXXX, XXXXXXX, ___x___, ___x___, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        ___x___, ___x___, ___z___, XXXXXXX, RESET,   ___x___, ___x___, XXXXXXX, KC_F11,  KC_F12,  ___x___, ___x___
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
    case _LSYM: set_led_levels(16, 0); break;
    case _RSYM: set_led_levels(0, 16); break;
    case _FUN: set_led_levels(16, 16); break;
    default: set_led_levels(0, 0);
    }

    return state;
}

bool select = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ENT_SFT:
    case SPC_SFT:
        if (!record->event.pressed) {
            if (layer_state_is(_LSYM)) {
                layer_off(_LSYM);
            } else if (layer_state_is(_RSYM)) {
                layer_off(_RSYM);
            }
        }

        break;

    case SELECT:
        if (record->event.pressed) {
            select = true;
            register_code(KC_LGUI);
            tap_code(KC_GRV);
        }

        break;

    case ESC_FUN:
        if (!record->event.pressed) {
            if (select) {
                unregister_code(KC_LGUI);
            }
        }

        break;
    }

    return true;
}


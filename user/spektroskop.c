#include QMK_KEYBOARD_H
#include "spektroskop.h"

bool is_release(keyrecord_t *record) {
  return !record->event.pressed;
}

bool is_press(keyrecord_t *record) {
  return record->event.pressed;
}

bool gui_tab_active = false;
bool alt_tab_active = false;
bool ctl_tab_active = false;

void activate_ctl_tab(void) {
    ctl_tab_active = true;
    register_code(KC_LCTL);
    tap_code(KC_TAB);
}

void deactivate_ctl_tab(void) {
    ctl_tab_active = false;
    unregister_code(KC_LCTL);
}

void activate_alt_tab(void) {
    alt_tab_active = true;
    register_code(KC_LALT);
    tap_code(KC_TAB);
}

void deactivate_alt_tab(void) {
    alt_tab_active = false;
    unregister_code(KC_LALT);
}

void activate_gui_tab(void) {
    gui_tab_active = true;
    register_code(KC_LGUI);
    tap_code(KC_TAB);
}

void deactivate_gui_tab(void) {
    gui_tab_active = false;
    unregister_code(KC_LGUI);
}

void deactivate_tabs(keyrecord_t *record) {
  if (is_release(record)) {
    if (alt_tab_active) deactivate_alt_tab();
    if (ctl_tab_active) deactivate_ctl_tab();
    if (gui_tab_active) deactivate_gui_tab();
  }
}

void activate_tabs_base(struct tabs args) {
  if (is_press(args.record)) {
    if (args.keycode == args.gui_tab_code) {
      if (ctl_tab_active) {
          deactivate_ctl_tab();
          activate_gui_tab();
      } else if (alt_tab_active) {
          deactivate_alt_tab();
          activate_gui_tab();
      } else if (gui_tab_active) {
          tap_code(KC_TAB);
      } else {
          activate_gui_tab();
      }
    } else if (args.keycode == args.alt_tab_code)  {
      if (ctl_tab_active) {
          deactivate_ctl_tab();
          activate_alt_tab();
      } else if (gui_tab_active) {
          deactivate_gui_tab();
          activate_alt_tab();
      } else if (alt_tab_active) {
          tap_code(KC_TAB);
      } else {
          activate_alt_tab();
      }
    } else if (args.keycode == args.ctl_tab_code) {
      if (alt_tab_active) {
          deactivate_alt_tab();
          activate_ctl_tab();
      } else if (gui_tab_active) {
          deactivate_gui_tab();
          activate_ctl_tab();
      } else if (ctl_tab_active) {
          tap_code(KC_TAB);
      } else {
          activate_ctl_tab();
      }
    }
  }
}

bool sym_hold = false;

void handle_sft_sym_base(struct sft_sym args) {
  if (args.keycode == args.lsym_code || args.keycode == args.rsym_code) {
    sym_hold = args.record->event.pressed;
  } else if (args.keycode == args.lsft_code || args.keycode == args.rsft_code) {
    if (is_release(args.record)) {
      if (sym_hold) return;

      layer_off(args.lsym_layer);
      layer_off(args.rsym_layer);
    }
  }
}

bool clear_oneshots(keyrecord_t *record) {
  bool r = true;
  uint8_t mods = 0;
  if ((mods = get_oneshot_mods()) && !has_oneshot_mods_timed_out()) {
    clear_oneshot_mods();
    unregister_mods(mods);
    r = false;
  }

  if ((mods = get_oneshot_locked_mods())) {
    clear_oneshot_locked_mods();
    unregister_mods(mods);
    r = false;
  }

  if (is_oneshot_layer_active()) {
    layer_clear();
    r = false;
  }

  return r;
}

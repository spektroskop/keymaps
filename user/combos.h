// Based on https://blog.gboards.ca/2020/02/adventures-in-obscure-c-features-2020.html

#pragma once

#define __combo_enum(name, target, ...) name,
#define __combo_data(name, target, ...) const uint16_t PROGMEM __##name[] = {__VA_ARGS__, COMBO_END};
#define __combo(name, target, ...) [name] = COMBO(__##name, target),
#define __combo_action(name, target, ...) [name] = COMBO_ACTION(__##name),

#undef combo
#define combo __combo_enum
#undef combo_action
#define combo_action __combo_enum
enum __combos__ {
    #include "user_combos.def"
    #include "combos.def"
};

#undef combo
#define combo __combo_data
#undef combo_action
#define combo_action __combo_data
#include "user_combos.def"
#include "combos.def"

#undef combo
#define combo __combo
#undef combo_action
#define combo_action __combo_action

combo_t key_combos[] = {
    #include "user_combos.def"
    #include "combos.def"
};

#undef combo
#undef combo_action

int COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);

/* Copyright 2025 Plodah
 * Copyright 2021 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 */

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
};

enum keymap_keycodes {
    KB_DPI_CONFIG = QK_KB_0,
    KB_DRAG_SCROLL,
    BETTER_DRAG_SCROLL_MOMENTARY,
    BETTER_DRAG_SCROLL_TOGGLE,
    PL_MSJG,
    PL_TSKN,
    PL_TSKP,
    DPI_SNIPER_A_MOMENTARY,
    DPI_SNIPER_A_TOGGLE,
    DPI_SNIPER_B_MOMENTARY,
    DPI_SNIPER_B_TOGGLE,
    BETTER_DRAG_ACTION_A_MOMENTARY,
    BETTER_DRAG_ACTION_B_MOMENTARY,
    TBO_TG1,
    TBO_MO1,
    TBO_TG2,
    TBO_MO2,
    TBO_TG3,
    TBO_MO3,
    TBO_TG4,
    TBO_MO4,
    MOR_MAN,
    MOR_DIT,
    MOR_DSH,
};

enum tap_dance_codes {
    TD_DRAGSCROLL,
    TD_NANO_CLICK,
};

#include "common.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        TD(TD_NANO_CLICK)
    )
};

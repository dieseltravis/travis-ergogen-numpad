// Copyright 2023 QMK
// Copyright 2024 Travis Hardiman
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _FUNC,
    _RGB,
    _FOUR
};

/* ?
#define LAYOUT(  K03, \
	K00, K01, K02, K13, \
	K10, K11, K12,      \
	K20, K21, K22, K23, \
	K30, K31, K32,      \
	K40,      K42, K43  \
) { \
	{ K00,   K01,   K02,   K03 }, \
	{ K10,   K11,   K12,   K13 }, \
	{ K20,   K21,   K22,   K23 }, \
	{ K30,   K31,   K32,   KC_NO }, \
	{ K40,   KC_NO, K42,   K43 }  \
}
*/

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD,     KC_VOLU) },
    [_FUNC] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_RGB] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [_FOUR] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*              ◜⤺◝
     *             ⤹rot⤸
     *              ◟⤻◞
     * ┌───┬───┬───┬───┐
     * │TG1│ / │ * │ - │
     * ├───┼───┼───┼───┤
     * │ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┤ + │
     * │ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │   │
     * ├───┴───┼───┤Ent│
     * │   0   │ . │   │
     * └───────┴───┴───┘
     */
    [_BASE] = LAYOUT_travis(       KC_MUTE,
        TG(1),   KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,
        KC_P0,            KC_PDOT, KC_PENT
    ),

    /*              ◜⤺◝
     *             ⤹rot⤸
     *              ◟⤻◞
     * ┌───┬───┬───┬───┐
     * │TG2│ / │ * │ - │
     * ├───┼───┼───┼───┤
     * │Hom│ ↑ │PgU│   │
     * ├───┼───┼───┤ + │
     * │ ← │   │ → │   │
     * ├───┼───┼───┼───┤
     * │End│ ↓ │PgD│   │
     * ├───┴───┼───┤Ent│
     * │Insert │Del│   │
     * └───────┴───┘───┘
     */
    [_FUNC] = LAYOUT_travis(       _______,
        TG(2),   _______, _______, _______,
        KC_HOME, KC_UP,   KC_PGUP,
        KC_LEFT, _______, KC_RGHT, _______,
        KC_END,  KC_DOWN, KC_PGDN,
        KC_INS,           KC_DEL,  _______
    ),

    /*              ◜⤺◝
     *             ⤹RGB⤸
     *              ◟⤻◞
     * ┌───┬───┬───┬───┐
     * │TG0│ / │ * │ - │
     * ├───┼───┼───┼───┤
     * │Hom│ ↑ │PgU│   │
     * ├───┼───┼───┤ + │
     * │ ← │   │ → │   │
     * ├───┼───┼───┼───┤
     * │End│ ↓ │PgD│   │
     * ├───┴───┼───┤Ent│
     * │Insert │Del│   │
     * └───────┴───┘───┘
     */
    [_RGB] = LAYOUT_travis(        RGB_TOG,
        TG(3),   _______, _______, _______,
        RGB_M_X, RGB_M_G, RGB_M_T,
        RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_SPI,
        RGB_M_P, RGB_M_B, RGB_M_R,
        RGB_RMOD,         RGB_MOD, RGB_SPD
    ),

    [_FOUR] = LAYOUT_travis(       _______,
        TG(0),   _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______,
        _______,          _______, _______
    ),
  };


// SSD1306 OLED driver logic
#ifdef OLED_ENABLE
static void render_logo(void) {
  static const char PROGMEM qmk_logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
      0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
      0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
  };

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
  oled_write_P(PSTR("Layer: "), false);
  switch (get_highest_layer(layer_state)) {
    case _BASE:
      oled_write_ln_P(PSTR("Base"), false);
      break;
    case _FUNC:
      oled_write_ln_P(PSTR("Function"), false);
      break;
    case _RGB:
      oled_write_ln_P(PSTR("RGB"), false);
      break;
    case _FOUR:
      oled_write_ln_P(PSTR("Extra"), false);
      break;
    default:
      oled_write_ln_P(PSTR("Undefined"), false);
  }

  // Host Keyboard LED Status
  led_t led_state = host_keyboard_led_state();
  oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
  oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
  oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_180;
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
      render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
      render_logo();  // Renders a static logo
      oled_scroll_left();  // Turns on scrolling
  }

  return false;
}

#endif

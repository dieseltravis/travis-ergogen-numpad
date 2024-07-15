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
  static const char PROGMEM rgbkb_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(rgbkb_logo, false);
}

static void render_status(void) {
  // Render to mode icon
  static const char PROGMEM mode_logo[4][4] = {
    {0x95,0x96,0},
    {0xb5,0xb6,0},
    {0x97,0x98,0},
    {0xb7,0xb8,0} };

  if (keymap_config.swap_lalt_lgui != false) {
    oled_write_ln_P(mode_logo[0], false);
    oled_write_ln_P(mode_logo[1], false);
  } else {
    oled_write_ln_P(mode_logo[2], false);
    oled_write_ln_P(mode_logo[3], false);
  }

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
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
    default:
      oled_write_ln_P(PSTR("Undefined"), false);
  }

  // Host Keyboard LED Status
  led_t led_state = host_keyboard_led_state();
  oled_write_P(led_state.num_lock ? PSTR("NUMLCK ") : PSTR("       "), false);
  oled_write_P(led_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
  oled_write_ln_P(led_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
    oled_scroll_left();
  }
    return false;
}

#endif

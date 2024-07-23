// Copyright 2023 QMK
// Copyright 2024 Travis Hardiman (@dieseltravis)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Workaround for freezing after MacOS sleep
#define NO_USB_STARTUP_CHECK

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

//#define OLED_DISPLAY_128X32
//#define I2C1_SCL_PIN        GP17
//#define I2C1_SDA_PIN        GP16
//#define I2C_DRIVER I2CD0
#define OLED_BRIGHTNESS 128
//#define OLED_FONT_H "keyboards/1upkeyboards/pi40/lib/glcdfont.c"

#define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_GRB

/* Optional encoder pins */
//#define ENCODERS_PAD_A { B2 }
//#define ENCODERS_PAD_B { B6 }
//#define ENCODER_RESOLUTIONS { 2 }

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

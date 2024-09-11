#include QMK_KEYBOARD_H
#include "screen_app.h"

enum layer_names {
    _LAYER1,
    _LAYER2,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER1] = LAYOUT(
        KC_NO,
        KC_ESC,KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,KC_EQUAL,KC_BSPC,KC_PGUP,
        KC_ESC,KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LBRC,KC_RBRC,KC_BSLS,KC_PGDN,
        KC_ESC,KC_CAPS,KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,KC_ENT,KC_HOME,
        KC_ESC,MO(_LAYER2),KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSFT,KC_UP,KC_END,
        KC_ESC,KC_LCTL,KC_LCMD,KC_LALT,KC_SPACE,KC_RCTL,KC_RCMD,KC_LEFT,KC_DOWN,KC_RIGHT
    ),
    [_LAYER2] = LAYOUT(
        KC_NO,
        KC_ESC,KC_GRAVE,KC_2,KC_1,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,KC_EQUAL,KC_BSPC,KC_PGUP,
        KC_ESC,KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LBRC,KC_RBRC,KC_BSLS,KC_PGDN,
        KC_ESC,KC_CAPS,KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,KC_ENT,KC_HOME,
        KC_ESC,MO(_LAYER2),KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSFT,KC_UP,KC_END,
        KC_ESC,KC_LCTL,KC_LCMD,KC_LALT,KC_SPACE,KC_RCTL,KC_RCMD,KC_LEFT,KC_DOWN,KC_RIGHT
    )
};
// clang-format on

// OLED STUFF STARTS HERE
// based on https://github.com/qmk/qmk_firmware/blob/master/keyboards/kyria/keymaps/j-inc/keymap.c

// In your rules.mk make sure you have:
// OLED_ENABLE = yes
// WPM_ENABLE = yes

#ifdef OLED_ENABLE

// Used to draw on to the oled screen
bool oled_task_user(void) {
    app_draw();
    return false;
}

// Display seems to be a 64x128 mounted horizontally.
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;
}
#endif

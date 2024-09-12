#include QMK_KEYBOARD_H
#include "screen_app.h"

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

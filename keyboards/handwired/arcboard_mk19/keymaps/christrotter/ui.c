// Copyright 2023 Chris Trotter (@christrotter)
// SPDX-License-Identifier: GPL-2.0-or-later

#include <qp.h>
#include "arcboard_mk19.c"
#include "graphics/futura40.qff.c"

static painter_font_handle_t font;
static painter_device_t display;

const char *current_layer_name(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            return "qwerty";
        case _NAV:
            return "nav";
        case _SYMBOLS:
            return "symbols";
        case _MOUSE:
            return "mouse";
    }
    return "unknown";
}

void init_ui(void) {
    font = qp_load_font_mem(font_futura40);
    display = qp_gc9a01_make_spi_device(240, 240, DISPLAY2_CS_PIN, DISPLAY_DC_PIN, DISPLAY_RST_PIN, DISPLAY_SPI_DIVISOR, DISPLAY_SPI_MODE);
    if (!(is_keyboard_left())) {
        qp_init(display, QP_ROTATION_0);
        setPinOutput(DISPLAY_LED_PIN);
        writePinHigh(DISPLAY_LED_PIN);
        qp_rect(display, 0, 0, 240, 240, HSV_BLUE, true);
        qp_flush(display);
    }
}

void draw_ui_user(void) {
    if (!(is_keyboard_left())) {
        uint16_t width;
        uint16_t height;
        qp_get_geometry(display, &width, &height, NULL, NULL, NULL);
        #if defined(CONSOLE_ENABLE)
            char buf[32] = {0};
        #endif
        bool layer_state_redraw = false;
        static uint32_t last_layer_state   = 0;
        if (last_layer_state  != layer_state) {
            last_layer_state   = layer_state;
            layer_state_redraw = true;
        }
        if (layer_state_redraw) {
            extern const char *current_layer_name(void);
            const char        *layer_name = current_layer_name();
            const char        *mouse = "mouse";
            const char        *qwerty = "qwerty";
            const char        *nav = "nav";
            const char        *symbols = "symbols";
            int ypos = 150;
            #if defined(CONSOLE_ENABLE)
                snprintf(buf, sizeof(buf), "%s", layer_name);
            #endif
            int mouse_layer = strcmp(layer_name, mouse);
            int qwerty_layer = strcmp(layer_name, qwerty);
            int nav_layer = strcmp(layer_name, nav);
            int symbols_layer = strcmp(layer_name, symbols);
            if (qwerty_layer==0) {
                qp_drawtext_recolor(display, 35, ypos, font, "  QWERTY  ", HSV_WHITE, HSV_BLACK);
            }
            if (mouse_layer==0) {
                qp_drawtext_recolor(display, 45, ypos, font, "  MOUSE  ", HSV_WHITE, HSV_BLACK);
            }
            if (nav_layer==0) {
                qp_drawtext_recolor(display, 75, ypos, font, "    NAV    ", HSV_WHITE, HSV_BLACK);
            }
            if (symbols_layer==0) {
                qp_drawtext_recolor(display, 25, ypos, font, " SYMBOLS ", HSV_WHITE, HSV_BLACK);
            }
        }
        qp_flush(display);
    }
}

void keyboard_post_init_kb(void) {
    init_ui();   // Initialise the display
}
void housekeeping_task_user(void) {
    static uint32_t last_draw = 0;
    if (timer_elapsed32(last_draw) > 33) { // Throttle to 30fps
        last_draw = timer_read32();
        draw_ui_user();
    }
}
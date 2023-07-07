/*
 * Copyright 2023 Chris Trotter <ctrotter@gmail.com> (@christrotter)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Publicw License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"
#include "arcboard_mk17.h"
#include "keymap.h"

#if defined(POINTING_DEVICE_ENABLE)
    #if defined(CONSOLE_ENABLE)
        #include "print.h"
        static uint32_t last_draw = 0;
    #endif
    extern bool set_scrolling;

    void pointing_device_init_user(void) {
        set_auto_mouse_enable(true);
    }
    void pointing_device_init_kb(void) {
        pointing_device_init_user(); // set auto mouse layer
    }

    report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
        #if defined(CONSOLE_ENABLE)
        if (timer_elapsed32(last_draw) > 10000) { // every 10s write our cpi out to console
            last_draw = timer_read32();
            if (is_keyboard_left()) {
                uprintf("left cpi is: %d \n", pointing_device_get_cpi());
            }
            else {
                uprintf("right cpi is: %d \n", pointing_device_get_cpi());
            }
        }
        #endif
        if (set_scrolling) {
            pointing_device_set_cpi(DRAGSCROLL_CPI);
            right_report.h -= right_report.x; // -= to invert x-axis
            right_report.v = right_report.y;
            right_report.x = 0;
            right_report.y = 0;
        } else {
            pointing_device_set_cpi(PMW33XX_CPI);
        }
        return pointing_device_combine_reports(left_report, right_report);
    }
#endif

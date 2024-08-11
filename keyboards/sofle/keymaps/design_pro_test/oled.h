#ifndef OLED_H
#define OLED_H

#ifdef OLED_ENABLE

#include QMK_KEYBOARD_H

oled_rotation_t oled_init_user(oled_rotation_t rotation);
bool oled_task_user(void);

#endif // OLED_ENABLE

#endif // OLED_H

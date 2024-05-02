#ifndef __MOTOR_H
#define __MOTOR_H
#include "main.h"
extern uint8_t led_flag;
extern uint8_t led_slow;
void motor_con(char order);
void beep_con(uint8_t state);
void blue_order(void);
void motor_init(void);
void led_init(void);
void led_con(void);
void beep_con(uint8_t state);
#endif

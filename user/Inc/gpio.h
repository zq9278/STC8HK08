#include "STC8G_H_GPIO.h"
#ifndef __GPIO_H__
#define __GPIO_H__

/*
 *									by zhangqi at 2024/04/22
 */
#define LEDG_ON      P35 = 1
#define LEDG_OFF     P35 = 0
#define LEDR_OFF     P34 = 0
#define LEDR_ON      P34 = 1
#define READ_KEY_PIN P36

typedef enum {
    false = 0,
    true  = 1
} bool;

void GPIO_config(void);
bool isLongPress(void);
void enterLowPowerMode(void);
#endif

#ifndef __HW_DRIVER_LED_H__
#define __HW_DRIVER_LED_H__

#include "hw_def.h" ////추가됐넹
#include "led.h"
#include "uart.h"
#include "cli.h"
#include "my_gpio.h"//main.h 뒤에 위치해야함
#include "button.h"
#include "temp.h"


void hwInit(void);

#endif //__HW_DRIVER_LED_H__
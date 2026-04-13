#include "hw_def.h"
#include <stdint.h>

void apInit(){
    hwInit();
}

void apMain(){
    while(1){

        //HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
        // HAL_Delay(1000);
        //Delay(1000);

        ledOn();
        HAL_Delay(1000);
        ledOff();
        HAL_Delay(1000);

        //uartWrite(0,(uint8_t *)"HEllOW", 7);
        uartPrintf(0,(uint8_t *)"HEllOW %d\r\n", 10);

    }
}
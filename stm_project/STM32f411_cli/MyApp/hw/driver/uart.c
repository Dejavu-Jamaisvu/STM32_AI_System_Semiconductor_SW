
#include "uart.h"  
#include <stdint.h>
#include <stdio.h>
#include <string.h>
extern UART_HandleTypeDef huart2;

#define TIMEOUT 100

bool uartInit(void){

    return uartOpen(0, 115200);

}
bool uartOpen(uint8_t ch, uint32_t baudrate){
    if(huart2.Init.BaudRate!=baudrate)
        huart2.Init.BaudRate=baudrate;


    if(HAL_UART_DeInit(&huart2)!=HAL_OK)
        return false;

    if(HAL_UART_Init(&huart2)!=HAL_OK)
        return false;

    return true;
}

bool uartClose(uint8_t ch){

    return true;
}


uint8_t uartRead(uint8_t ch)
{
    uint8_t ret=0;


    return ret;

}

uint32_t uartWrite(uint8_t ch, uint8_t *p_data, uint32_t len)
{
    if(HAL_UART_Transmit(&huart2, p_data, len, TIMEOUT)==HAL_OK)
        return len;

    return 0;

}

uint32_t uartPrintf(uint8_t ch, const char *fmt, ...){


    char buf[128];
    uint32_t len;
    va_list args;

    va_start(args, fmt);
    len = vsnprintf(buf, 128, fmt, args);
    va_end(args);

    return uartWrite(ch, (uint8_t *) buf, len);
}

#include "uart.h"  
#include <stdint.h>
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
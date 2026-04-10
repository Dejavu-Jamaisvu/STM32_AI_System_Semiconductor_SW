//#include "hw_def.h"
#include "led.h"
void ledInit(void)
{


}

void ledOn(void)
{   //HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin( GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
}
void ledOff(void)
{
    //HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
}

void ledToggle(){
    //HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}
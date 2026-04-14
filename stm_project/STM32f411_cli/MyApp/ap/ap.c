#include "cli.h"
#include "hw_def.h"
#include "bsp.h"
#include <stdint.h>
#include <string.h>

void cliLed(uint8_t argc, char** argv){
    if(argc == 2){
        if(strcmp(argv[1], "on") == 0){
            ledOn();
            cliPrintf("LED ON\r\n");
        }
        else if(strcmp(argv[1], "off") == 0){
            ledOff();
            cliPrintf("LED OFF\r\n");
        }else if(strcmp(argv[1], "toggle") == 0){
            ledToggle();
            cliPrintf("LED TOGGLE\r\n");
        }else{
            cliPrintf("Invalid Command\r\n");
        }
    }else{
        cliPrintf("Usage: led [on|off|toggle]\r\n");
    }
}

void cliInfo(uint8_t argc, char** argv)
{
    if(argc == 2 || strcmp(argv[1],"uptime") == 0){
        cliPrintf("System Uptime: %d ms \r\n", millis());
    } else {
        cliPrintf("Usage: info [uptime]\r\n");
    }
}

void cliSys(uint8_t argc, char** argv)
{
    if(argc == 2 && strcmp(argv[1],"reset") == 0) {
        NVIC_SystemReset();
    }else{
        cliPrintf("Usage: sys [reset]\r\n");
    }

}
void apInit(){
    hwInit();
    cliAdd("led", cliLed);
    cliAdd("info", cliInfo);
    cliAdd("sys", cliSys);

}

void apMain(){

    uartPrintf(0,"HEllOW world!! \r\n");//(uint8_t *)

    while(1){

        //HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
        // HAL_Delay(1000);
        //Delay(1000);

        // ledOn();
        // HAL_Delay(1000);
        // ledOff();
        // HAL_Delay(1000);
        // uartWrite(0,(uint8_t *)"HEllOW", 7);
        
        // uartPrintf(0,(uint8_t *)"HEllOW %d\r\n", 10);

        // if(uartAvailable(0)>0){
        //     uint8_t ch = uartRead(0);

        //     uartPrintf(0,"%c", ch);
        // }
        //HAL_Delay(500);


        cliMain();



    }
}
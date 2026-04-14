#include "bsp.h"
#include "cli.h"
#include "hw_def.h"
#include "main.h" //

#include <ctype.h> // tolower()를 위해 추가
#include <stdint.h>
#include <stdlib.h> // atoi()를 위해 추가
#include <string.h>

// argv[1] : "read" "write"
// argv[2] : pin "A5", "B12"
void cliGpio(uint8_t argc, char **argv)
{

    if (argc >= 3) {
        char port_char = tolower(argv[2][0]);
        int pin_num = atoi(&argv[2][1]);

        uint8_t port_idx = port_char - 'a';

        if (strcmp(argv[1], "read") == 0) {

            int8_t state = gpioExtRead(port_idx, pin_num);
            if (state < 0) {
                cliPrintf("Invalid Port or Pin (ex:a5, b12)\r\n");
            } else {
                cliPrintf("GPIO %c%d=%d\r\n", toupper(port_char), pin_num, state);
            }
        } else if (strcmp(argv[1], "write") == 0 && argc == 4) {
            int val = atoi(argv[3]);
            if (gpioExtWrite(port_idx, pin_num, val) == true) {
                cliPrintf("GPIO %c%d Set to %d\r\n", toupper(port_char), pin_num, val);

            } else {
                cliPrintf("Invalid Port or Pin (ex:a5, b12)\r\n");
            }
        } else {
            cliPrintf("Usage: gpio read[a~h][0~15]\r\n");
            cliPrintf("       gpio write[a~h][0~15] [0|1]\r\n");
        }
    } else {
        cliPrintf("Usage: gpio read[a~h][0~15]\r\n");
        cliPrintf("       gpio write[a~h][0~15] [0|1]\r\n");
    }
}
void cliLed(uint8_t argc, char **argv)
{
    if (argc == 2) {
        if (strcmp(argv[1], "on") == 0) {
            ledOn();
            cliPrintf("LED ON\r\n");
        } else if (strcmp(argv[1], "off") == 0) {
            ledOff();
            cliPrintf("LED OFF\r\n");
        } else if (strcmp(argv[1], "toggle") == 0) {
            ledToggle();
            cliPrintf("LED TOGGLE\r\n");
        } else {
            cliPrintf("Invalid Command\r\n");
        }
    } else {
        cliPrintf("Usage: led [on|off|toggle]\r\n");
    }
}

void cliInfo(uint8_t argc, char **argv)
{

    if (argc == 1) {
        cliPrintf("=========================================\r\n");
        cliPrintf(" HW Model    :   STM32F411\r\n");
        cliPrintf(" FW Version  : V1.0.0\r\n");
        cliPrintf(" Build Date  : %s %s\r\n", __DATE__, __TIME__);

        uint32_t uid0 = HAL_GetUIDw0();
        uint32_t uid1 = HAL_GetUIDw1();
        uint32_t uid2 = HAL_GetUIDw2();
        uint32_t dev = HAL_GetDEVID();

        // uint32_t hal = HAL_GetHalVersion();
        // uint32_t rev = HAL_GetREVID();

        cliPrintf(" Serial Num  : %08x-%08x-%08x\r\n", uid0, uid1, uid2);
        cliPrintf(" DevicID     : %08x\r\n", dev);
        cliPrintf("=========================================\r\n");
    }

    if (argc == 2 || strcmp(argv[1], "uptime") == 0) {
        cliPrintf("System Uptime: %d ms \r\n", millis());
    } else {
        cliPrintf("Usage: info\r\n");
        cliPrintf("       info [uptime]\r\n");
    }
}

void cliSys(uint8_t argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "reset") == 0) {
        NVIC_SystemReset();
    } else {
        cliPrintf("Usage: sys [reset]\r\n");
    }
}
void apInit()
{
    hwInit();
    cliAdd("led", cliLed);
    cliAdd("info", cliInfo);
    cliAdd("sys", cliSys);
    cliAdd("gpio", cliGpio);
}

void apMain()
{

    uartPrintf(0, "HEllOW world!! \r\n"); //(uint8_t *)

    while (1) {

        // HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
        //  HAL_Delay(1000);
        // Delay(1000);

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
        // HAL_Delay(500);

        cliMain();
    }
}
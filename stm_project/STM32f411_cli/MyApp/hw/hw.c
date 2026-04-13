//#include "driver/uart.h"

// #include "hw_def.h"
#include "hw.h"
#include "driver/cli.h"

void hwInit(void)
{
    ledInit();
    uartInit();
    cliInit();
    // uartOpen(0, 9600);

}
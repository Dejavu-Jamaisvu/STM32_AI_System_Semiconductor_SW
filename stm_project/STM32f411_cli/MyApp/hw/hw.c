//#include "driver/uart.h"
#include "hw.h"


void hwInit(void)
{
    ledInit();
    uartInit();
    uartOpen(0, 9600);

}
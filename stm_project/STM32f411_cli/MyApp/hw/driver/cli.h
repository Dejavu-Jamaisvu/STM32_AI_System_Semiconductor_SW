#ifndef HW_DRIVER_CLI_H_
#define HW_DRIVER_CLI_H

#include "def.h"
#include "hw_def.h"
#include "uart.h"

// #include <stdint.h>
// #include <string.h>
// #include <stdarg.h>
// #include <stdio.h>

void cliInit();
void cliMain();
void cliPrintf(const char *fmt, ...);

void cliParseArgs(char* line_buf);
bool cliAdd(const char* cmd_str, void (*cmd_func)(uint8_t argc, char** argv));//char* argv[]
void cliRunCommand();

#endif //_HW_DRIVER_CLI_H
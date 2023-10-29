#include "StdTypes.h"
#include "Utils.h"
#include "Connect_To_Pc_Interface.h"
#include "UART_Interface.h"

char Buffer[max_size];
Task_t Tasks[NO_of_tasks]={0};
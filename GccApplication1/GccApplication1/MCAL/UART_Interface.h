

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
#include "StdTypes.h"
#include "UART_CFG.h"
#define  NULL 0
typedef enum{
	BAUDRATE_2400=207,
	BAUDRATE_4800=103,
	BAUDRATE_9600=51
	}BudeRate_t;



void UART_Init(BudeRate_t baudrate);
void UART_Send(u8 data);
u8 UART_Recever(void);
void UART_RX_InterruptEnable();
void UART_TX_InterruptEnable();

void UART_RX_InterruptDisable();
void UART_TX_InterruptDisable();

#endif /* UART_INTERFACE_H_ */
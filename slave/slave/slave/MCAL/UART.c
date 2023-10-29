#include "StdTypes.h"
#include "Utils.h"
#include "MemroyMap.h"
#include "UART_Interface.h"
#include "UART_CFG.h"

static void (*UART_RX_Fptr)(void)=NULL;
static void (*UART_TX_Fptr)(void)=NULL;

void UART_Init(BudeRate_t baudrate)
{
	//CHOISE BAUDRATE
	UBRRL=51;
	
	//SLECT FRAM 
	//Default 
		CLEAR_BIT(UCSRA,U2X);

	//ENABLE TX AND  RX
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
}

void UART_Send(u8 data)
{
	while(!READ_BIT(UCSRA,UDRE));//busy wait  and  blocking
	UDR=data;
}

u8 UART_Recever(void)
{
	while(!READ_BIT(UCSRA,RXC));//busy wait  and  blocking
	return UDR;
}
void UART_RX_InterruptEnable()
{
	SET_BIT(UCSRB,RXCIE);
	
}
void UART_RX_InterruptDisable()
{
	CLEAR_BIT(UCSRB,RXCIE);
	
}
void UART_TX_InterruptEnable()
{
	SET_BIT(UCSRB,TXCIE);
}
void UART_TX_InterruptDisable()
{
		CLEAR_BIT(UCSRB,TXCIE);

}
void UART_RX_SetCallBack(void(*LocalFptr)(void))
{
	UART_RX_Fptr=LocalFptr;
}
void UART_TX_SetCallBack(void(*LocalFptr)(void))
{
	UART_TX_Fptr=LocalFptr;
}
void UART_SendNoblock(u8 data)
{
	UDR=data;
}
u8 UART_ReceiveNoBlock(void){
	return UDR;
}
ISR(UART_TX_vect)
{
	if (UART_TX_Fptr!=NULL)
	{
		UART_TX_Fptr();
	}
}
ISR(UART_RX_vect)
{
	if (UART_RX_Fptr!=NULL)
	{
		UART_RX_Fptr();
	}
}
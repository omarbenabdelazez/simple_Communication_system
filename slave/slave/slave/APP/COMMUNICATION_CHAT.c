#define  F_CPU 8000000
#include  <util/delay.h>



#include "StdTypes.h"
#include "Utils.h"
#include "UART_Interface.h"
#include "SPI_Services.h"
#include "UART_Services.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"

u8 buffer_resive[20];
u8 buffer_send[20];
volatile bool_type  flag_Resive=FALSE;
void spi_resive_String()
{
	u8 i=0;
	
	for (i=0;i<20;i++)
	{
		buffer_resive[i]=spi_resive();

	}
	UART_SendStringAsynch(buffer_resive);
	LCD_SetCursor(0,0);
	LCD_WriteString("res:");
	LCD_WriteString(buffer_resive);
	LCD_WriteString("  ");
}
void resive_String()
{
	static u8 index;
	u8 temp=UART_ReceiveNoBlock();
	
	if (temp==0x0D)
	{
		buffer_send[index++]='\0';
		index=0;
		LCD_SetCursor(1,0);
		LCD_WriteString(buffer_send);
		LCD_WriteString("   ");
		DIO_WritePin(PINB0,HIGH);
		_delay_ms(1);
		DIO_WritePin(PINB0,LOW);

		spi_send_string(buffer_send);
	}
	else
	{
		
		buffer_send[index]=temp;
		index++;
		
	}
}
void start_chat()
{
		//This  fun used  to start chat  and  enabale  RX and Tx in uart
		UART_RX_InterruptEnable();
		UART_RX_SetCallBack(resive_String);
	
}
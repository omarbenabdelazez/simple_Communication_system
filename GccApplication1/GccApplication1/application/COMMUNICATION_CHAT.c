#include "StdTypes.h"
#include "Utils.h"
#include "UART_Interface.h"
#include "UART_Services.h"



 u8 buffer_resive[20];
 u8 buffer_from_slave[20];
 u8 flag_chat=FALSE;
void resive_String()
{
	static u8 index;
	u8 temp=UART_ReceiveNoBlock();
	
	if (temp==0x0D)
	{
		buffer_resive[index++]='\0';
		index=0;
		flag_chat=TRUE;
		
		
	}
	else
	{
		
		buffer_resive[index]=temp;
		index++;
		
	}
}

void  start_chat(void)
{
	//This  fun used  to start chat  and  enabale  RX and Tx in uart 
	UART_RX_InterruptEnable();
	UART_RX_SetCallBack(resive_String);
}
void communcation_chat_runnable(void)
{
	if (flag_chat==TRUE)
	{
		spi_send_string(buffer_resive);
		LCD_SetCursor(0,0);
		LCD_WriteString("send:");
		LCD_WriteString(buffer_resive);
		LCD_WriteString("                ");
		flag_chat=FALSE;
	}
	
}
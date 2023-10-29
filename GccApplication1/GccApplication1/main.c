	#define  F_CPU 8000000
	#include <util/delay.h>

#include "Utils.h"
#include "StdTypes.h"
#include "MemroyMap.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "ADC_Interface.h"
#include "SENSORS_Interface.h"
#include "Timers.h"
#include "Ultrasonic_Interface.h"
#include "RGB_Interface.h"
#include "UART_Interface.h"
#include "UART_Services.h"
#include "CommunicationWithPC.h"
#include "SPI_Interface.h"
#include "COMMUNICATION_CHAT_Interface.h"
#include "EX_Intrrupt_Interface.h"

void resive(void)
{
	u8 i=0;
	
	for(i=0;i<20;i++)
	{
		
		buffer_from_slave[i]=spi_send_resive(1);
	
		_delay_ms(5);
		
	}
	UART_SendStringAsynch(buffer_from_slave);
	LCD_SetCursor(1,0);
	LCD_WriteString("res:");
	LCD_WriteString(buffer_from_slave);
	LCD_WriteString("                ");
	buffer_from_slave[0]=0x0D;
	buffer_from_slave[1]=0;
	UART_SendStringAsynch(buffer_from_slave);

	

	
}


int main(void)
{
DIO_Init();
//ADC_Init(VREF_VCC,ADC_SCALER_64);
LCD_Init();
RGB_Init();
UART_Init(BAUDRATE_9600);
/*start_communication();*/
start_chat();
SPI_Init(MASTER);
EXI_Init();
EXI_Enable(EX_INT1);
EXI_Mode(EX_INT1,FALLING_EDGE);
EXI_SetCallBack(EX_INT1,resive);

sei();

	while (1) 
    {
		communcation_chat_runnable();
		
}
}
/*

	if (flag_communication==TRUE){
		
		Communication_Runnable();
		flag_communication=FALSE;
	}
	*/
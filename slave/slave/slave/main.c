
#define  F_CPU 8000000
#include  <util/delay.h>


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

#include "SPI_Interface.h"
#include "COMMUNICATION_CHAT_Interface.h"

int main(void)
{
	DIO_Init();
	//ADC_Init(VREF_VCC,ADC_SCALER_64);
	LCD_Init();
	RGB_Init();
	UART_Init(BAUDRATE_9600);
	/*start_communication();*/
	SPI_Init(SLAVE);
	start_chat();
	sei();
    /* Replace with your application code */
    while (1) 
    {
	
		
		
		spi_resive_String();
		
		
    }
}


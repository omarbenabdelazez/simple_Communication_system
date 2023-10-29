#define  F_CPU 8000000
#include <util/delay.h>
#include "Utils.h"
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "SPI_Interface.h"
#include "SPI_Services.h"


void spi_send_string(u8 *str)
{
	u8 i=0;

	for(i=0;i<20;i++)
	{
		spi_send_resive(str[i]);
		_delay_ms(5);
	
	}
	
}
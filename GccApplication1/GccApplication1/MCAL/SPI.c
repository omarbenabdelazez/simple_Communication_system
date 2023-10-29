#include "StdTypes.h"
#include "Utils.h"
#include "MemroyMap.h"
#include "SPI_Interface.h"


void SPI_Init(select_t mood)
{
	//select master or slave
	switch (mood)
	{
		case MASTER:
		SET_BIT(SPCR,MSTR);
		break;
		case SLAVE:
		CLEAR_BIT(SPCR,MSTR);
		break;
	}
	
	
	//clock DEFAULT setting   to  2MHZ
	
	
	
	
	//Enable spi
		SET_BIT(SPCR,SPE);
}

u8 spi_send_resive(u8 data)
{
	SPDR=data;
	while (!READ_BIT(SPSR,SPIF))
	{
	};
	return SPDR;

}
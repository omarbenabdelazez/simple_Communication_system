


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

typedef enum{
	MASTER,
	SLAVE
	}select_t;

void SPI_Init(select_t mood);

u8 spi_send_resive(u8 data);



#endif /* SPI_INTERFACE_H_ */
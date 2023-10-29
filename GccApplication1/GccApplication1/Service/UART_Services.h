

#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

/********************************** DEFINE*****************************************/
#define  LITTLE  1
#define  BIG     0
//*********************************************************************************

//*************************proto types of  functions**********************************************  

void UART_SendString(char *str);
void UART_ReceiveString(char *str);
void UART_SendNumber(u32 num);
u32 UART_ReceiverNumber();
u8 CheckEndian(void);
u32 Endian_Convert(u32 num);
void UART_SendStringCheckSum(u8*str);
u8 UART_ReceiveStringCheckSum(u8*str);

void UART_SendStringAsynch(char *str);

//********************************************************************************************
#endif /* UART_SERVICES_H_ */
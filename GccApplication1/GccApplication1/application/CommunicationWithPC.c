#include "StdTypes.h"
#include "CommunicationWithPC.h"
#include "DIO_Interface.h"
#include "UART_Interface.h"
#include "UART_Services.h"
#include "LCD_Interface.h"
volatile bool_type flag_communication=FALSE;
u8 Buffer[20]={0};
void led_on(int num)
{
switch (num)
{
	case 1:
	DIO_WritePin(PINC0,HIGH);
	break;
	case 2:
	DIO_WritePin(PINC1,HIGH);
	break;
	
}
}
void led_off(u8 num)
{
	switch (num)
	{
		case 1:
		DIO_WritePin(PINC0,LOW);
		break;
		case 2:
		DIO_WritePin(PINC1,LOW);
		break;
		
	}
}
void buzzer_on(void)
{
	DIO_WritePin(PINC2,HIGH);
}
void buzzer_off(void)
{
	DIO_WritePin(PINC2,LOW);
}

task_t tasks[MAX_TASK]={{"led on",led_on},
						{"led off",led_off},
						{"buzzer on",buzzer_on},
						{"buzzer off",buzzer_off}
									};

void Receive_string(void)
{
	static u8 index=0;
	u8 temp=UART_ReceiveNoBlock();
	if (temp==0x0D)
	{
		Buffer[index++]='\0';
		index=0;
		flag_communication=TRUE;
		
	}
	else
	{
		
		Buffer[index]=temp;
		index++;
		
	}
}



void start_communication(void)
{
	UART_RX_InterruptEnable();
	UART_RX_SetCallBack(Receive_string);
}

void Communication_Runnable(void)
{
	 searching_sting();
	
}

void searching_sting(u8 *index)
{

	for (u8 i=0;i<MAX_TASK;i++)
	{
		if (string_compare((tasks[i].str),Buffer)==1)
		{
			LCD_WriteString("true");
			sperate_number(i,Buffer);
			
		}
		
	}
}
u8 string_compare(u8 *task,u8 *Buffer)
{
	for (u8 i=0;task[i]!=0;i++)
	{
		if(task[i]!=Buffer[i])
		{
			return 0;
		}
	}
	return 1;
}
void sperate_number(u8 index,u8 *buffer)
{
	u8 num=0;
	for (u8 i=0;buffer[i]!=0;i++)
	{
		if (Buffer[i]>='0'&&buffer[i]<='9'){
			num=num*10+(buffer[i]-'0');
		}
	}	
	LCD_WriteString(tasks[index].str);
		LCD_WriteNumber(num);

	tasks[index].ptr(num);
}
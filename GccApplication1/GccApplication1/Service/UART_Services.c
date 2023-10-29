#include "StdTypes.h"
#include "UART_Interface.h"
#include "UART_Services.h"

u8 flag_Send=0;

void UART_SendString(char *str)
	{
		u8 i=0;
		for(i=0;str[i];i++)
		{
		UART_Send(str[i]);
		}
	
	}


void UART_ReceiveString(char *str)
	{
		u8 i=0;
		str[i]=UART_Recever();
		for(;str[i]!=0X0D;)
			{
				i++;	
			str[i]=UART_Recever();
			}
			str[i]='\0';
	}
	
	void UART_SendNumber(u32 num)
	{
		
		UART_Send((u8)num);
		UART_Send((u8)(num>>8));
		UART_Send((u8)(num>>16));
		UART_Send((u8)(num>>24));
		
		//another  solution  
		/*
			u8 *p=&num;
			UART_Send((u8) p[0]);
			UART_Send((u8) p[1]);
			UART_Send((u8) p[2]);
			UART_Send((u8) p[3]);
		*/
	}
	
	
	u32 UART_ReceiverNumber()
	{
		u32 num;
		u8 b0=UART_Recever();
		u8 b1=UART_Recever();
		u8 b2=UART_Recever();
		u8 b3=UART_Recever();
		num= (u32)b0|((u32)b1<<8)|((u32)b2<<16)|((u32)b3<<24);
		
		//another  solution
		/*
		u8 *p=&num;
		p[0]=UART_Recever();
		p[1]=UART_Recever();
		p[2]=UART_Recever();
		p[3]=UART_Recever();
		*/
	}
	
	
	
u8 CheckEndian(void)
	{
		u32 num=1;
		u8 *p=&num;
		if(*p==1)
			{
				return LITTLE;
			}
		else
			{
				return BIG	;
			}
	
	}
	
	
	u32 Endian_Convert(u32 num)
	{
		u8 temp;
		u8 *p=&num;
		temp=p[0];
		p[0]=p[3];
		p[3]=temp;
		temp=p[1];
		p[1]=p[2];
		p[2]=temp;
		
		
		//another  solution
		
		//num=(num>>24)|(num<<24)|((num>>8)&0x0000ff00)|((num<<8)&0x00ff0000);
		
		
		return num;
	}
	
	
	
	
	
	void UART_SendStringCheckSum(u8*str)
	{
		u8 i=0;
		u8 len;
		u16 sum=0;
		for(i=0;str[i];i++)
		{
			sum+=str[i];	
		}
		len=i;
		UART_Send(len);
		for(i=0;str[i];i++)
		{
			UART_Send(str[i]);	
		}
		UART_Send((u8) sum);
		UART_Send((u8) (sum>>8));
		
	}
	
	
	
	u8 UART_ReceiveStringCheckSum(u8*str)
	{
	    u8 i,len,b0,b1;
		u16 sumcal,sum;
		len=UART_Recever();
		for(i=0;i<len;i++)
		{
			str[i]=UART_Recever();
			sumcal+=str[i];
		}
		b0=UART_Recever();
		b1=UART_Recever();
		sum=(u16)b0|((u16)b1<<8);
		if (sum==sumcal)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	
	
	
	void TX_Fuc(void);
	static u8 *TXStr;
	void UART_SendStringAsynch(char *str)
	{
			UART_SendNoblock(str[0]);
			UART_TX_InterruptEnable();
			UART_TX_SetCallBack(TX_Fuc);
			TXStr=str;
				
	}
	
	void TX_Fuc(void)
	{
		static u8 i=1;
		if(TXStr[i]!=0)
		{
				UART_SendNoblock(TXStr[i]);
				i++;
		}
		else
		{
				i=1;	
				flag_Send=1;
		}
	}
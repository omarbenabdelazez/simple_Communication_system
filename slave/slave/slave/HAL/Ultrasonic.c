#define  F_CPU 8000000
#include <util/delay.h>
#include "DIO_Interface.h"
#include "Timers.h"
#include "Ultrasonic_Interface.h"

static u16 T1,T2,Time;
static u8 flag;
static void calculate_UltrasonicTiming_ICU()
{
	if (flag==0)
	{
		T1=ICR1;
		Timer1_InputCaptureEdge(FALLING);
		flag=1;
	}
	else if (flag==1)
	{
		T2=ICR1;
		flag=2;
	}
}

void Ultrasonic_Init()
{
	Timer1_Init(TIMER1_NORMAL_MODE,TIMER1_SCALER_8);
	Timer1_ICU_SetCallBack(calculate_UltrasonicTiming_ICU);
	Timer1_ICU_InterruptEnable();
}
u16 ULTRASONIC_GetDistance(void)
{
	u16 distance;
	TCNT1=0;
	Timer1_InputCaptureEdge(RISING);
	DIO_WritePin(ultrasonic_pin,HIGH);
	_delay_us(10);
	DIO_WritePin(ultrasonic_pin,LOW);
	while(flag<=2)
	{
	
	}
		Time=T1+T2;
		distance=Time/58;
		return distance;

	
}
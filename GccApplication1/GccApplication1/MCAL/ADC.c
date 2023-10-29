#include "Utils.h"
#include "StdTypes.h"
#include "MemroyMap.h"
#include "ADC_Interface.h"



void  ADC_Init(ADC_VoltRef_type Volt,ADC_Prescaler_type scaler){
	//slecet Vref
	switch(Volt)
	{
		case VREF_AREF:
		CLEAR_BIT(ADMUX,REFS1);
		CLEAR_BIT(ADMUX,REFS0);
		break;
		
		
		case VREF_VCC:
		CLEAR_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
		
		
		case VREF_256:
		SET_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
		
	}
	
	/*clock*/
	ADCSRA=ADCSRA&0xf8;
	scaler=scaler&0x07;
	ADCSRA=ADCSRA|scaler;
	
	
	
	/*ADC Enable*/
	SET_BIT(ADCSRA,ADEN);
}

u16 ADC_Read(ADC_Channel_type channle)
{
	
	/*select chanel*/
	ADMUX=ADMUX&0xe0;
	if (channle>7)
	{
		channle=7;
	}
	ADMUX=ADMUX|channle;
	
	/*start convertion*/
	SET_BIT(ADCSRA,ADSC);
	/*wait  until read*/
	while(READ_BIT(ADCSRA,ADSC))
	{
		
	};
	
	/*get read*/

	return ADC;
	
}
u16 Read_Volt(ADC_Channel_type channle){
	u16 adc=ADC_Read(channle);
	u16 volt=((u32)5000*adc)/1023;
	return volt;
}



#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef enum
{
	VREF_AREF,
	VREF_VCC,
	VREF_256	
}ADC_VoltRef_type;
	
typedef enum
{
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128
}ADC_Prescaler_type;
	
	
typedef enum{
	CH0,
	CH1,
	CH2,
	CH3,
	CH4,
	CH5,
	CH6,
	CH7
}ADC_Channel_type;





void  ADC_Init(ADC_VoltRef_type Volt,ADC_Prescaler_type scaler);
u16 ADC_Read(ADC_Channel_type channle);
u16 Read_Volt(ADC_Channel_type channle);


#endif /* ADC_INTERFACE_H_ */
#include "Utils.h"
#include "StdTypes.h"
#include "SENSORS_Interface.h"
#include "ADC_Interface.h"
#include "SENSORS_CFG.h"
u8 read_pot(void)
{
	u16 adc=ADC_Read(POT_CH);
	u8 pot=((u32)100*adc)/1023;
	return pot	;
}

u16 temp_read(void)
{
	u16 volt =Read_Volt(LM35);
	u16 temp=volt;
	return temp;
}
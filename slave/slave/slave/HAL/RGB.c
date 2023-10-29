#include "StdTypes.h"
#include "MemroyMap.h"
#include "Utils.h"
#include "Timers.h"
#include "RGB_Interface.h"
#include "LCD_Interface.h"
void RGB_Init(void)
{
	// initialize Timer 0
	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8);
	TIMER0_OC0Mode(OC0_INVERTING);
	
	// initialize Timer 1
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	Timer1_OCRA1Mode(OCRA_INVERTING);
	Timer1_OCRB1Mode(OCRB_NON_INVERTING);

	// set Top Value in ICR Register
	ICR1=255;

}
void set_color(ColorName_type color)
{
	if (color<NO_OF_COLOR)
	{
		RED_PIN=colors[color][0];
		GREEN_PIN=colors[color][1];
		BLUE_PIN=colors[color][2];
	}
}

void RGB_ToggleColors()
{
	for (u8 i=0;i<15;i++)
	{
		ColorName_type color=i;
				RED_PIN=colors[i][0];
				GREEN_PIN=colors[i][1];
				BLUE_PIN=colors[i][2];
				LCD_SetCursor(0,0);
				LCD_WriteNumber(i);
				LCD_WriteString("   ");
				_delay_ms(DELAY_TIME);
	}
}
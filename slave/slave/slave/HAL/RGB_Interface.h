/*
 * RGB_Interface.h
 *
 * Created: 10/15/2023 5:14:24 PM
 *  Author: Omar
 */ 


#ifndef RGB_INTERFACE_H_
#define RGB_INTERFACE_H_

#define  F_CPU 8000000
#include <util/delay.h>
/********************************pin mapping  of  The RGP LED***********/
#define RED_PIN		OCR0
#define BLUE_PIN	OCR1B
#define GREEN_PIN	OCR1A

#define  NO_OF_COLOR 15
#define DELAY_TIME 300
/*********************************************************************/

u16 colors[][3];
typedef enum{
	Red,
	Green,
	Blue,
	Black,
	Magenta,
	Cyan,
	Maroon,
	Olive,
	Navy,
	Yellow_Green,
	Purple,
	Teal,
	Gray,
	DarkGray,
	White,
	}ColorName_type;


void RGB_Init(void);
void set_color( ColorName_type color);
void RGB_ToggleColors(void);


#endif /* RGB_INTERFACE_H_ */
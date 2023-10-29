
#include "MemroyMap.h"
#include "StdTypes.h"
#include "Utils.h"
#include "EX_Intrrupt_Interface.h"

/****************************Pointer to functions to be assigned to ISR*********************************/

static void (*INT0_Fptr) (void)=NULLPTR;
static void (*INT1_Fptr) (void)=NULLPTR;
static void (*INT2_Fptr) (void)=NULLPTR;





/************************************Enable/Disable functions***********************************/




void EXI_Enable(EXInterruptSource_type interrupt){
	//this  function  used  when want enable  any	external  interrupt
	switch (interrupt){
		case EX_INT0:
			SET_BIT(GICR,INT0);
		break;
		
		case EX_INT1:
			SET_BIT(GICR,INT1);
		break;
		
		case EX_INT2:
			SET_BIT(GICR,INT2);
		break;
	}
}
void EXI_Disable(EXInterruptSource_type interrupt){
		//this  function  used  when want   Disable  any  external interrupt
		switch (interrupt){
			case EX_INT0:
						CLEAR_BIT(GICR,INT0);
			break;
			
			case EX_INT1:
						CLEAR_BIT(GICR,INT1);
			break;
			
			case EX_INT2:
						CLEAR_BIT(GICR,INT2);
			break;
		}

}

void EXI_Init(void){
	EXI_Mode(EX_INT0,FALLING_EDGE);
	EXI_Mode(EX_INT1,FALLING_EDGE);
	EXI_Mode(EX_INT2,FALLING_EDGE);
}

/************************************Control function*****************************/

void EXI_Mode(EXInterruptSource_type interrupt,TriggerEdge_type mode){
	switch(interrupt){
		case EX_INT0:
		switch(mode){
			case LOW_LEVEL:
					CLEAR_BIT(MCUCR,ISC10);
					CLEAR_BIT(MCUCR,ISC11);
				break;
			case ANY_LOGIC_CHANGE:
					SET_BIT(MCUCR,ISC10);
					CLEAR_BIT(MCUCR,ISC11);
				break;
			case FALLING_EDGE:
					CLEAR_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
				break;
			case RISING_EDGE:
					SET_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
				break;
		}
			break;
		case EX_INT1:
		switch(mode){
			case LOW_LEVEL:
					CLEAR_BIT(MCUCR,ISC00);
					CLEAR_BIT(MCUCR,ISC01);	
				break;
			case ANY_LOGIC_CHANGE:
					SET_BIT(MCUCR,ISC00);
					CLEAR_BIT(MCUCR,ISC01);
				break;
			case FALLING_EDGE:
					CLEAR_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
				break;
			case RISING_EDGE:
					SET_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
				break;
		}
			break;
		case EX_INT2:
		switch(mode){
			case FALLING_EDGE:
					CLEAR_BIT(MCUCR,ISC2);
				break;
			case RISING_EDGE:
					SET_BIT(MCUCR,ISC2);
				break;
			default:
					CLEAR_BIT(MCUCR,ISC2);
		}
		break;
		
	}
	
}
/************************************Call back functions*********************************************/
void EXI_SetCallBack(EXInterruptSource_type Interrupt,void(*LocalPtr)(void))
{
	switch(Interrupt){
		case EX_INT0:
		INT0_Fptr=LocalPtr;
		break;
		case EX_INT1:
		INT1_Fptr=LocalPtr;
		break;
		case EX_INT2:
		INT2_Fptr=LocalPtr;
		break;
		
	}
}


/*******************************ISR********************************/

ISR(INT0_vect)
{
	if (INT0_Fptr!=NULLPTR)
	{
		INT0_Fptr();
	}
}
ISR(INT1_vect,ISR_NOBLOCK)
{
	if (INT1_Fptr!=NULLPTR)
	{
		INT1_Fptr();
	}
}
ISR(INT2_vect)
{
	if (INT2_Fptr!=NULLPTR)
	{
		INT2_Fptr();
	}
	
}

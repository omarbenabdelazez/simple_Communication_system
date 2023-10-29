

#ifndef EX_INTRRUPT_INTERFACE_H_
#define EX_INTRRUPT_INTERFACE_H_

#define NULLPTR  0

typedef enum{
	LOW_LEVEL,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
	}TriggerEdge_type;
typedef enum{
	EX_INT0=0,
	EX_INT1,
	EX_INT2
	}EXInterruptSource_type;

void EXI_Init(void);
void EXI_Enable(EXInterruptSource_type interrupt);
void EXI_Disable(EXInterruptSource_type interrupt);
void EXI_Mode(EXInterruptSource_type interrupt,TriggerEdge_type mode);
void EXI_SetCallBack(EXInterruptSource_type Interrupt,void(*LocalPtr)(void));

#endif /* EX_INTRRUPT_INTERFACE_H_ */
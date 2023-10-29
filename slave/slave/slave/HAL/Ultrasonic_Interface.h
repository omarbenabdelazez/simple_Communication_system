
#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_


#define  ultrasonic_pin   PIND0
void  Ultrasonic_Init();
static void calculate_UltrasonicTiming_ICU();
u16 ULTRASONIC_GetDistance(void);


#endif /* ULTRASONIC_INTERFACE_H_ */
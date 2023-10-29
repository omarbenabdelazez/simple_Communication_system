/*
 * Utils.h
 *
 * Created: 3/27/2023 12:16:22 AM
 *  Author: hanaa
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define  READ_BIT(reg,bit)   ((reg>>bit)&1)
#define  SET_BIT(reg,bit)    (reg=reg|(1<<bit))
#define  CLEAR_BIT(reg,bit)  (reg=reg&~(1<<bit))
#define  TOG_BIT(reg,bit)     (reg=reg^(1<<bit))




#endif /* UTILS_H_ */
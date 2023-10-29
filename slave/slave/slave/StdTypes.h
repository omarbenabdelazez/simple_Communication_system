


#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned int u16;
typedef signed int s16;

typedef unsigned long u32;
typedef signed long s32;

#define  MAX_U8    ((u8)255)
#define  MIN_U8    ((u8)0)

#define   MAX_S8   ((u8)127)
#define   MIN_S8   ((u8)-128)

typedef enum{
	OK=0,
	NOK,
	OUT_OF_RANGE,
	NULL_PTR
}Error_t; 


typedef enum
	{
		FALSE,
		TRUE
	}bool_type;

#endif /* STDTYPES_H_ */
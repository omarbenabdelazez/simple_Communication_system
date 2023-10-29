


#ifndef COMMUNICATIONWITHPC_H_
#define COMMUNICATIONWITHPC_H_


#define  MAX_TASK  4

 extern volatile bool_type flag_communication;
 

typedef struct
{
	u8 *str;
	void(*ptr)(u8);
	}task_t;




/*********************************ProtoType *******************************/
void start_communication(void);
void searching_sting();
void Receive_string(void);
void Communication_Runnable(void);
u8 string_compare(u8 *task,u8 *Buffer);

#endif /* COMMUNICATIONWITHPC_H_ */
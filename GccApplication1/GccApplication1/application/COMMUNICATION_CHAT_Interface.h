

#ifndef COMMUNICATION_CHAT_INTERFACE_H_
#define COMMUNICATION_CHAT_INTERFACE_H_
extern u8 buffer_resive[20];
extern  u8 buffer_from_slave[20];
extern volatile bool_type flag_chat;
void  start_chat(void);
void resive_String();
void communcation_chat_runnable(void);



#endif /* COMMUNICATION_CHAT_INTERFACE_H_ */
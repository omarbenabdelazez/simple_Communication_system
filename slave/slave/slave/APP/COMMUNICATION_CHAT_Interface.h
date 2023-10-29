

#ifndef COMMUNICATION_CHAT_INTERFACE_H_
#define COMMUNICATION_CHAT_INTERFACE_H_
extern volatile bool_type flag_Resive;
 extern u8 buffer_resive[20];
 extern u8 buffer_send[20];
void communication_chat();
void spi_resive_String();
void start_chat();

#endif /* COMMUNICATION_CHAT_INTERFACE_H_ */
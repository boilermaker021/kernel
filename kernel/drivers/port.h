#ifndef PORT_H
#define PORT_H

#define VGA_PORT 0x3d4

unsigned char port_byte_in(unsigned short port);
void port_byte_out(unsigned short port, unsigned char data);
unsigned short port_word_in(unsigned short port);
void port_word_out(unsigned short port, unsigned short data);


#endif
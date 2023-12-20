#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <stdint.h>


extern volatile char *framebuffer_addr;
extern volatile uint32_t framebuffer_pitch;
extern volatile uint32_t framebuffer_width;
extern volatile uint32_t framebuffer_height;
extern volatile uint8_t framebuffer_bpp;
extern volatile uint8_t framebuffer_pixelwidth;

uint32_t colortoint(uint8_t red, uint8_t green, uint8_t blue);



#endif
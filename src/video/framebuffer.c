#include <stdint.h>

#include "multiboot.h"

volatile char *framebuffer_addr;
volatile uint32_t framebuffer_pitch;
volatile uint32_t framebuffer_width;
volatile uint32_t framebuffer_height;
volatile uint8_t framebuffer_bpp;
volatile uint8_t framebuffer_pixelwidth;

void init_framebuffer(multiboot_info_t *mbd) {
    framebuffer_addr = (uint32_t *)mbd->framebuffer_addr;
    framebuffer_height = mbd->framebuffer_height;
    framebuffer_width = mbd->framebuffer_width;
    framebuffer_pitch = mbd->framebuffer_pitch;
    framebuffer_bpp = mbd->framebuffer_bpp;
    framebuffer_pixelwidth = framebuffer_bpp / 8;
}


/*uint32_t colortoint(uint8_t red, uint8_t green, uint8_t blue) {
    //uint32_t color = 
}*/
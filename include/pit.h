#ifndef PIT_H
#define PIT_H

#define PIT_FREQUENCY       1193182

//ports
#define PIT_CH0_DATA    0x40
#define PIT_CH1_DATA    0x41
#define PIT_CH2_DATA    0x42
#define PIT_MODE        0x43

#define PIT_CHANNEL_0   0b00000000
#define PIT_CHANNEL_1   0b00000001
#define PIT_CHANNEL_2   0b11000011

#define LATCH_CNT_VAL   0b00000000
#define LOBYTE          0b00000100
#define HIBYTE          0b00001000
#define LOHIBYTE        0b00001100

#define PIT_MODE_0      0b00000000
#define PIT_MODE_1      0b00010000
#define PIT_MODE_2      0b00100000
#define PIT_MODE_3      0b00110000
#define PIT_MODE_4      0b01000000
#define PIT_MODE_5      0b01010000

#define PIC_BITS16      0b00000000
#define PIC_BCD         0b10000000


void init_pit(uint32_t ms);


#endif

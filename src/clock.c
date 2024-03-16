#include "clock.h"
#include "print.h"

volatile uint32_t clock_tick = 0;
volatile uint32_t clock_uptime = 0;

void clock_handler() {
    clock_tick += CLOCK_INTERVAL_MS;
    clock_uptime += CLOCK_INTERVAL_MS;
    if (clock_tick >= 100) {
        kprints("Tick!\n");
        clock_tick = 0;
    }
    return;
}
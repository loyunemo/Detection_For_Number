#ifndef _LED_H_
#define _LED_H_

#include "gpio.h"

enum LED{
    G,
    R,
    Y,
    SHUT
};

void LED_Init(void);
void Ignite(enum LED input);

#endif

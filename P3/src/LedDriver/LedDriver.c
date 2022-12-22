#include <stdint.h>

#include "include/LedDriver/LedDriver.h"

static uint16_t* ledAddress;

void LedDriver_Create(uint16_t* address)
{
    ledAddress = address;
    *address = 0;
}

void LedDriver_Destory(void)
{
    ;
}

void LedDriver_TurnOn(int ledNumber)
{
    *ledAddress = 1;
}

void LedDriver_TurnOff(int ledNumber)
{
    *ledAddress = 0;
}


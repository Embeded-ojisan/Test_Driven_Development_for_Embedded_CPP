#include <stdint.h>

#include "include/LedDriver/LedDriver.h"

enum
{
    ALL_LEDS_ON = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON
};

static uint16_t* ledAddress;
static uint16_t ledsImage;

void LedDriver_Create(uint16_t*);
void LedDriver_Destory(void);

void LedDriver_TurnOn(int);
void LedDriver_TurnAllOn(void);

void LedDriver_TurnOff(int);

static uint16_t convertLedNumberToBit(int);

static void UpdateHardware(void);

void LedDriver_Create(uint16_t* address)
{
    ledAddress = address;
    ledsImage = ALL_LEDS_OFF;
    *address = ledsImage;
}

void LedDriver_Destory(void)
{
    ;
}

void LedDriver_TurnOn(int ledNumber)
{
    if(ledNumber <= 0 || 16 < ledNumber)
    {
        return;
    }

    ledsImage |= convertLedNumberToBit(ledNumber);
    UpdateHardware();
}

void LedDriver_TurnAllOn(void)
{
    ledsImage = (uint16_t)(ALL_LEDS_ON);
    UpdateHardware();
}

void LedDriver_TurnOff(int ledNumber)
{
    if(ledNumber <= 0 || 16 < ledNumber)
    {
        return;
    }
    
    ledsImage &= (uint16_t)(~(convertLedNumberToBit(ledNumber)));
    UpdateHardware();
}

static uint16_t convertLedNumberToBit(int ledNumber)
{
    return( (uint16_t)( 1 << ( ledNumber - 1 ) ) );
}

static void UpdateHardware(void)
{
    *ledAddress = ledsImage;
}

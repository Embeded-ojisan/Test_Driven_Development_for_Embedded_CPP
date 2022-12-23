
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "include/LedDriver/LedDriver.h"

enum
{
    ALL_LEDS_ON = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON
};

enum
{
    FIRST_LED = 1,
    LAST_LED = 16
};

static uint16_t* ledAddress;
static uint16_t ledsImage;

void LedDriver_Create(uint16_t*);
void LedDriver_Destory(void);

void LedDriver_TurnOn(int);
void LedDriver_TurnAllOn(void);

void LedDriver_TurnOff(int);
void LedDriver_TurnAllOff(void);

bool LedDriver_IsOn(int);
bool LedDriver_IsOff(int);

static uint16_t convertLedNumberToBit(int);

static void setLedImageBit(int);
static void clearLedImageBit(int);

static void UpdateHardware(void);

static bool IsLedOutOfBounds(int LedNumber);


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
    if(IsLedOutOfBounds(ledNumber))
    {
        return;
    }

    setLedImageBit(ledNumber);
    UpdateHardware();
}

void LedDriver_TurnAllOn(void)
{
    ledsImage = (uint16_t)(ALL_LEDS_ON);
    UpdateHardware();
}

void LedDriver_TurnOff(int ledNumber)
{
    if(IsLedOutOfBounds(ledNumber))
    {
        return;
    }

    clearLedImageBit(ledNumber);
    UpdateHardware();
}

void LedDriver_TurnAllOff(void)
{
    ledsImage = ALL_LEDS_OFF;
    UpdateHardware();
}


bool LedDriver_IsOn(int ledNumber)
{
    if(IsLedOutOfBounds(ledNumber))
    {
        return false;
    }

    return 0 != (ledsImage & convertLedNumberToBit(ledNumber));
}

bool LedDriver_IsOff(int ledNumber)
{
    return !LedDriver_IsOn(ledNumber);
}

static uint16_t convertLedNumberToBit(int ledNumber)
{
    return( (uint16_t)( 1 << ( ledNumber - 1 ) ) );
}

static void setLedImageBit(int ledNumber)
{
    ledsImage |= convertLedNumberToBit(ledNumber);
}

static void clearLedImageBit(int ledNumber)
{
    ledsImage &= (uint16_t)~(convertLedNumberToBit(ledNumber));
}

static void UpdateHardware(void)
{
    *ledAddress = ledsImage;
}

static bool IsLedOutOfBounds(int ledNumber)
{
    return (ledNumber < FIRST_LED) || (LAST_LED < ledNumber);
}

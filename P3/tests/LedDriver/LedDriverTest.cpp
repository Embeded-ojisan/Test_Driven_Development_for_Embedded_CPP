
extern "C"
{
#include <stdint.h>
#include "include/LedDriver/LedDriver.h"
}

#include "CppUTest/TestHarness.h"

static uint16_t virtualleds;

TEST_GROUP(LedDriver)
{
    ;
    void setup()
    {
        LedDriver_Create(&virtualleds);
    }

    void teardown()
    {
        ;
    }

};

TEST(LedDriver, LedOffAfterCreate)
{
    uint16_t virtualleds = 0xffff;
    LedDriver_Create(&virtualleds);
    BYTES_EQUAL(0, virtualleds);
}

TEST(LedDriver, TurnOnLedOne)
{
    LedDriver_TurnOn(1);
    BYTES_EQUAL(1, virtualleds);
}

TEST(LedDriver, TurnOffLedOne)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    BYTES_EQUAL(0, virtualleds);
}




extern "C"
{
#include <stdint.h>

#include "include/LedDriver/LedDriver.h"
#include "include/util/RuntimeError.h"

#include "mocks/RuntimeErrorStub.h"
}

#include "CppUTest/TestHarness.h"

static uint16_t virtualleds;

TEST_GROUP(LedDriver)
{
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

TEST(LedDriver, TurnOnMultipleLeds)
{
    LedDriver_TurnOn(9);
    LedDriver_TurnOn(8);
    LedDriver_TurnOff(8);
    BYTES_EQUAL(0x100, virtualleds);
}

TEST(LedDriver, AllOn)
{
    LedDriver_TurnAllOn();
    BYTES_EQUAL(0xffff, virtualleds);
}

TEST(LedDriver, TurnOffAnyLed)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(8);
    BYTES_EQUAL(0xff7f, virtualleds);
}

TEST(LedDriver, UpperAndLowerBounds)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOn(16);
    BYTES_EQUAL(0x8001, virtualleds);
}

TEST(LedDriver, OutOfBoundsChangesNothing)
{
    LedDriver_TurnOn(-1);
    LedDriver_TurnOn(0);
    LedDriver_TurnOn(17);
    LedDriver_TurnOn(3141);
    BYTES_EQUAL(0x0, virtualleds);
}

TEST(LedDriver, OutOfBoundsTurnOffDoesNoHarm)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(-1);
    LedDriver_TurnOff(0);
    LedDriver_TurnOff(17);
    LedDriver_TurnOff(3141);
    BYTES_EQUAL(0xffff, virtualleds);
}

TEST(LedDriver, OutOfBoundsProducesRuntimeError)
{
    LedDriver_TurnOn(-1);
    RUNTIME_ERROR("LED Driver: out-of-bounds LED", -1);
    STRCMP_EQUAL("LED Driver: out-of-bounds LED", RuntimeErrorStub_GetLastError());
    BYTES_EQUAL(-1, RuntimeErrorStub_GetLastParameter());
}

TEST(LedDriver, IsOn)
{
    CHECK_FALSE(LedDriver_IsOn(11));
    LedDriver_TurnOn(11);
    CHECK_TRUE(LedDriver_IsOn(11));
}


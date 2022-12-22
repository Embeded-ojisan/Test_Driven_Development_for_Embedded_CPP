
extern "C"
{
#include <stdint.h>
#include "include/LedDriver/LedDriver.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(LedDriver)
{
    ;
    void setup()
    {
        ;
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



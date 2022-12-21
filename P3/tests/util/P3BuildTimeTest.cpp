#include "CppUTest/TestHarness.h"
#include "P3BuildTime.h"

TEST_GROUP(P3BuildTime)
{
  P3BuildTime* projectBuildTime;

  void setup()
  {
    projectBuildTime = new P3BuildTime();
  }
  void teardown()
  {
    delete projectBuildTime;
  }
};

TEST(P3BuildTime, Create)
{
  CHECK(0 != projectBuildTime->GetDateTime());
}


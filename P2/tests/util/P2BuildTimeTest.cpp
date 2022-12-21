#include "CppUTest/TestHarness.h"
#include "P2BuildTime.h"

TEST_GROUP(P2BuildTime)
{
  P2BuildTime* projectBuildTime;

  void setup()
  {
    projectBuildTime = new P2BuildTime();
  }
  void teardown()
  {
    delete projectBuildTime;
  }
};

TEST(P2BuildTime, Create)
{
  CHECK(0 != projectBuildTime->GetDateTime());
}


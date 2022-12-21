#include "CppUTest/TestHarness.h"
#include "2nd_partBuildTime.h"

TEST_GROUP(2nd_partBuildTime)
{
  2nd_partBuildTime* projectBuildTime;

  void setup()
  {
    projectBuildTime = new 2nd_partBuildTime();
  }
  void teardown()
  {
    delete projectBuildTime;
  }
};

TEST(2nd_partBuildTime, Create)
{
  CHECK(0 != projectBuildTime->GetDateTime());
}


#include "2nd_partBuildTime.h"

2nd_partBuildTime::2nd_partBuildTime()
: dateTime(__DATE__ " " __TIME__)
{
}

2nd_partBuildTime::~2nd_partBuildTime()
{
}

const char* 2nd_partBuildTime::GetDateTime()
{
    return dateTime;
}


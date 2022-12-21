#include "P3BuildTime.h"

P3BuildTime::P3BuildTime()
: dateTime(__DATE__ " " __TIME__)
{
}

P3BuildTime::~P3BuildTime()
{
}

const char* P3BuildTime::GetDateTime()
{
    return dateTime;
}


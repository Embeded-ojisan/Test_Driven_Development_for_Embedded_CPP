#include "P2BuildTime.h"

P2BuildTime::P2BuildTime()
: dateTime(__DATE__ " " __TIME__)
{
}

P2BuildTime::~P2BuildTime()
{
}

const char* P2BuildTime::GetDateTime()
{
    return dateTime;
}


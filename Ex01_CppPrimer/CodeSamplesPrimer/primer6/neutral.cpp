#include "neutral.h"

Neutral::Neutral(bool p1, bool p2)
{
    in1 = p1;
    in2 = p2;
    out = false;
}

void Neutral::setIn1(bool p1)
{
    in1 = p1;
}

void Neutral::setIn2(bool p1)
{
    in2 = p1;
}

bool Neutral::getOut()
{
    return out;
}


#include "and.h"

And::And(bool p1, bool p2) : Neutral(p1,p2)
{

}

void And::setIn1(bool p1)
{
    Neutral::setIn1(p1);
    this->andLogic();
}

void And::setIn2(bool p1)
{
    Neutral::setIn2(p1);
    this->andLogic();
}

void And::andLogic()
{
    out = in1 && in2;
}


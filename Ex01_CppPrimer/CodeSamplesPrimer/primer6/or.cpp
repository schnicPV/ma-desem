#include "or.h"


Or::Or(bool p1, bool p2) : Neutral(p1,p2)
{

}

void Or::setIn1(bool p1)
{
    Neutral::setIn1(p1);
    this->orLogic();
}

void Or::setIn2(bool p1)
{
    Neutral::setIn2(p1);
    this->orLogic();
}

void Or::orLogic()
{
    out = in1 || in2;
}

#ifndef AND_H
#define AND_H
#include "neutral.h"

class And : public Neutral
{
public:
    And(bool p1, bool p2);
    void setIn1(bool p1);
    void setIn2(bool p1);
private:
    void andLogic();
};

#endif // AND_H


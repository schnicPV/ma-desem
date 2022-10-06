#ifndef OR_H
#define OR_H
#include "neutral.h"

class Or : public Neutral
{
public:
    Or(bool p1, bool p2);
    void setIn1(bool p1);
    void setIn2(bool p1);
private:
    void orLogic();
};

#endif // OR_H

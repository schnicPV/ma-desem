#ifndef TO_BUTTON_H
#define TO_BUTTON_H

#include "bstate.h"

class ToButton
{
public:
    virtual BState checkButtonState() = 0;
};

#endif // TO_BUTTON_H

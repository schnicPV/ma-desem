#ifndef TOBUTTON_H
#define TOBUTTON_H

#include "bstate.h"

class ToButton
{
public:
    virtual BState checkButtonState() = 0;
};

#endif // TOBUTTON_H

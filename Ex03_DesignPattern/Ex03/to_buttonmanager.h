#ifndef TO_BUTTONMANAGER_H
#define TO_BUTTONMANAGER_H

#include "bstate.h"

class ToButtonManager
{
public:
    virtual void pressed() = 0;
    virtual void released() = 0;
};

#endif // TO_BUTTONMANAGER_H

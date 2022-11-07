#ifndef TOBUTTONMANAGER_H
#define TOBUTTONMANAGER_H

#include "bstate.h"

class ToButtonManager
{
public:
    virtual void pressed() = 0;
    virtual void released() = 0;
};


#endif // TOBUTTONMANAGER_H

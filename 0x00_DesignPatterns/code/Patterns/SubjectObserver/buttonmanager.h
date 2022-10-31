

#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H

#include "observer.h"

class ButtonManager : public IObserver
{
public:
    ButtonManager();
    void update();
};

#endif // BUTTONMANAGER_H




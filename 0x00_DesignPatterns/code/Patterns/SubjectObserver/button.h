

#ifndef BUTTON_H
#define BUTTON_H

#include "subject.h"

class Button : public Subject
{
public:
    Button();
    void setState(int state);
private:
    int state;
};

#endif // BUTTON_H



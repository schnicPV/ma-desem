

#include "button.h"

Button::Button()
{
    state = 0;
}

void Button::setState(int state)
{
    int oldState = this->state;
    this->state = state;
    if (oldState != this->state)
        this->notify();
}



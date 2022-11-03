#ifndef TO_BUTTON_H
#define TO_BUTTON_H

enum BState
{
    PRESSED, RELEASED
};

class ToButton
{
public:
    ToButton();
    void checkButtonState();
};

#endif // TO_BUTTON_H

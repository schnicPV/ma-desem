#ifndef BSTATE_H
#define BSTATE_H

#include <string>

enum BState
{
    PRESSED, RELEASED
};

std::string enum2str(BState e);

#endif // BSTATE_H

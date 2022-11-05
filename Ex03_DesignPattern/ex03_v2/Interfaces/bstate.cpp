#include <string>
#include "bstate.h"

std::string enum2str(BState e)
{
    switch(e)
    {
        case PRESSED: return "PRESSED";
        case RELEASED: return "RELEASED";
    }
    return "UNDEF";
}

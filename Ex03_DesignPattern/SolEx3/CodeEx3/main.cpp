#include "Application/factory.h"

int main()
{
    Factory f;
    f.initialize();
    f.buildApplication();
    f.button()->testMe();
    f.button()->testMe();
    f.button()->testMe();
    f.buttonManager()->testMe();
    return 0;
}

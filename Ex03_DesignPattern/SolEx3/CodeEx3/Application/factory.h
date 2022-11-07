#ifndef FACTORY_H
#define FACTORY_H

#include "buttonmanager.h"
#include "../Board/button.h"

class Factory
{
public:
    void initialize();
    ~Factory();
    void buildApplication();
    ButtonManager* buttonManager();
    Button* button();

private:
    Button* pButton;
    ButtonManager* pManager;
};

#endif // FACTORY_H

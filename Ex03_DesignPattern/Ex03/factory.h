#ifndef FACTORY_H
#define FACTORY_H

#include "button.h"
#include "buttonmanager.h"

class Factory
{
public:
    Factory();
    void initialize();
    void buildApplication();
    ButtonManager* buttonManager();
    Button* button();

private:
    Button* pButton;
    ButtonManager* pManager;
};

#endif // FACTORY_H

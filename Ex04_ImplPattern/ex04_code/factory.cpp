#include "factory.h"

#include "button.h"
#include "buttonmanager.h"
#include "blinker.h"
#include "testbench.h"

void Factory::initialize()
{
    pManager = nullptr;
    pButton = nullptr;
}

Factory::~Factory()
{
    delete pManager;
    delete pButton;
}

void Factory::buildApplication()
{
    //initialize
    button()->initialize();
    buttonManager()->initialize();
    blinker()->initialize();
    testBench()->initialize();

    // initialize releations
    button()->initializeRelations();
    buttonManager()->initializeRelations(button());
    testBench()->initializeRelations(button());

    //subscribe the button manager to the button
    button()->setButtonManager(buttonManager());

    //start
    buttonManager()->start();
    blinker()->start();
    testBench()->start();

}

ButtonManager * Factory::buttonManager()
{
    if (!pManager) pManager = &ButtonManager::instance();
    return pManager;
}

Button * Factory::button()
{
    if (!pButton) pButton = new Button();
    return pButton;
}

Blinker * Factory::blinker()
{
    static Blinker blinker;

    return &blinker;
}


TestBench * Factory::testBench()
{
    static TestBench tb;

    return &tb;
}

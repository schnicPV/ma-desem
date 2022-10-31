

#include "button.h"
#include "buttonmanager.h"
#include <iostream>

int main(int argc, char *argv[])
{
    Button but;
    ButtonManager bMan;

    but.subscribe(&bMan);
    but.setState(1);
    but.setState(0);
    but.setState(0); //will not notify
    std::cout <<"one more observer\n";
    ButtonManager otherBMan;
    but.subscribe(&otherBMan);
    but.setState(1);
    std::cout <<"unsubscribe one observer\n";
    but.unSubscribe(&bMan);
    but.setState(0);
}


#include <iostream>
#include "neutral.h"
#include "and.h"
#include "or.h"

using namespace std;

int main()
{
    //base class pointer
    Neutral* pBase;

    And a1(false,false);
    pBase = &a1;
    cout << a1.getOut() << endl;
    a1.setIn1(true);
    //would not do the same
    //pBase->setIn1(true);
    cout << a1.getOut() << endl;
    a1.setIn2(true);
    cout << a1.getOut() << endl;
    //would do the same
    cout << pBase->getOut() << endl;

    Or o1(false,false);
    pBase = &o1;
    cout << o1.getOut() << endl;
    o1.setIn1(true);
    //would not do the same
    //pBase->setIn1(true);
    cout << o1.getOut() << endl;
    o1.setIn2(true);
    cout << o1.getOut() << endl;
    //would do the same
    cout << pBase->getOut() << endl;
    return 0;
}


#include <iostream>
using namespace std;

#include "factory.h"

int main()
{
    // parameters
    bool running = true;
    string input_answer = "";

    cout << "============================================================================================================================" << endl;
    cout << "[MSGE] Create new Factory ... " << endl;
    Factory* pFactory = new Factory();
    cout << "[MSGE] Initialize Factory ... " << endl;
    pFactory->initialize();
    cout << "[MSGE] Build Factory Application ... " << endl;
    pFactory->buildApplication();

    // main loop
    while(running)
    {
        // user object definitions
        cout << "============================================================================================================================" << endl;
        cout << "[x] Start White Box Test Factory ... " << endl;

        // print all objects (printinfo)
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "[Q] Which test do you want to execute? (b = Button / m = Button Manager) : ";
        cin >> input_answer;

        if(((input_answer == "b") || (input_answer == "B")))
        {
            pFactory->button()->testMe();
        }
        else if(((input_answer == "m") || (input_answer == "M")))
        {
            pFactory->buttonManager()->testMe();
        }
        else
        {
            cout << "[ERRR] Invalid test selected! " << endl;
        }
        input_answer = "";

        // ask user if more objects should be stored
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "[Q] Do you want to do another test? (y/n) : ";
        cin >> input_answer;

        if(!((input_answer == "y") || (input_answer == "Y")))
        {
            running = false;
        }
    }
    cout << "============================================================================================================================" << endl;
    return 0;
}

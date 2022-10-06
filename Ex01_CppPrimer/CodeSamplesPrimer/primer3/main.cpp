#include <iostream>
using namespace std;


int main()
{
    int i=10;
    int j=20;
    //pointer
    cout << i <<endl;
    int* pInt;    //this is a pointer
    pInt = &i;    //store the address of i in pI
    cout << pInt << ',' << *pInt << endl;
    *pInt = 77;
    cout << i << endl; //this will say 77
    pInt=&j;  //pointers can be reassigned
    cout << pInt << ',' << *pInt << endl;

    //reference
    int& rI=i;    //rI is a reference to i
                  //you could also say
                  //rI is an alias for i
    cout << rI <<endl;
    rI=55;
    cout << i <<endl; //this will say 55

    //references can not be reassigned

    return 0;

}


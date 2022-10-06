#include <iostream>
using namespace std;

//prototypes
void display(int i);   //signature display(int)
void display(float f); //signature display(float)
void byRef(int &i);    //signature byref(int&)
void byPointer(int* i); //signature byPoinbter(int*)

int main()
{
    display((float)5/3);
    int z=3;
    byRef(z);       //z has value 33 after call
    byPointer(&z);  //z has value 12 after call
    display(z);
    return 0;
}
//definition of functions (implementation)
void display(int i)
{
    cout << i <<endl;
}
void display(float f)
{
    cout << f <<endl;
}
void byRef(int &i)
{
    cout << i <<endl;
    i =33;
}
void byPointer(int* i)
{
    cout << *i <<endl;
    *i = 12;
}



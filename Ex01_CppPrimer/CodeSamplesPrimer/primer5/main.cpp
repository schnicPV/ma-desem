#include <iostream>
using namespace std;

#include "vehicle.h"

int main()
{
    //dynamic, using parameter constructor
    Vehicle* pV1 = new Vehicle(3, 20, green);

    //on stack, using default constructor
    Vehicle v2;

    pV1->drive();
    v2.drive();

    //this will call the destructor
    delete pV1;
}


















/*
int main()
{
    //in the stack of main()
    //these objects die when
    //leaving the main()-scope
    Vehicle car;
    Vehicle lorry;
    Vehicle rocket;
    Vehicle bicycle;
    car.drive();
    lorry.drive();
    rocket.drive();
    bicycle.drive();


    //in the dynamic memory
    //create the objects
    Vehicle* pCar = new Vehicle;
    pCar->drive();
    Vehicle* pLorry = new Vehicle;
    pLorry->drive();
    //give the memory back
    //is equal to
    //DESTROY the objects
    delete pCar;
    delete pLorry;

    return 0;
}

*/


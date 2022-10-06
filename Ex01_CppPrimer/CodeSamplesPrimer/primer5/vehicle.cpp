#include "vehicle.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle() : vehicleColor(red), power(50)
{
    cout << "vehicle created" << endl;
    nbrOfWheels = 4;
}
Vehicle::Vehicle(int w, int p, color c) :
         nbrOfWheels(w),power(p)
{
    cout << "vehicle created" << endl;
    vehicleColor = c;
}
Vehicle::~Vehicle()
{
    cout << "vehicle destroyed" << endl;
}
void Vehicle::drive()
{
    cout << "driving"  << endl;
}



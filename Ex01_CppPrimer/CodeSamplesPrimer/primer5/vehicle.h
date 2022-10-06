#ifndef VEHICLE_H
#define VEHICLE_H
enum color
{
    red, blue, green, yellow
};

class Vehicle
{
public:
    Vehicle();
    Vehicle(int w, int p, color c);
    ~Vehicle();
    void drive();
private:
    int nbrOfWheels;
    int power;
    color vehicleColor;
};

#endif // VEHICLE_H



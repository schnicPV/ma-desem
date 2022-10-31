#include <iostream>
using namespace std;

class IGeometry
{
public:
    virtual void setGeometry(int x, int y, int length, int height) = 0;
};


class Client
{
private:
    IGeometry* theTarget;
public:
    Client(IGeometry* p)
    {
        theTarget = p;
    }
    void useGeometry()
    {
        cout <<"x1,y1=" <<10 <<"," <<10 <<", width=" <<50  <<", heigth=" <<20  <<endl;
        theTarget->setGeometry(10,10,50,20);
    }
};

class GeometryA
{
    public:
    void setGeometry(int x1, int y1, int x2, int y2)
    {
        cout <<"x1,y1=" <<x1 <<"," <<y1 <<", x2,y2=" <<x2 <<"," <<y2  <<endl;
    }
};

class GeometryAdapter : public IGeometry
{
private:
    GeometryA* theAdapted;
public:

    GeometryAdapter(GeometryA* p)
    {
        theAdapted = p;
    }

    void setGeometry(int x, int y, int length, int heigth)
    {
        theAdapted->setGeometry(x,y,x+length,y+heigth);
    }
};

int main()
{
    GeometryA geoLib;
    GeometryAdapter ga(&geoLib);
    Client c(&ga);
    c.useGeometry();

    return 0;
}


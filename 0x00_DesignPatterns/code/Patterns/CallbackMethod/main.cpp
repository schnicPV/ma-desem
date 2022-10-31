#include <iostream>
#include <functional>
using namespace std;

class Handler;

class Hardware
{
 public:
    typedef function<void (Hardware* hw,
                           int p1,
                           int p2)> callbackMethod;
    void setCBM(callbackMethod p)
    {
        cbm = p;
    }
    void transmit()
    {
        cout <<"transmitting" <<endl;
    }
    void interrupt()
    {
        int irqflag = 1, irqValue = 11;
        if (cbm)
        {
            cbm(this, irqflag, irqValue);
        }
    }
private:
    callbackMethod cbm;
};

class Handler
{
private:
    Hardware* theHardware;
public:
    Handler()
    {
        theHardware = NULL;
    }
    void initializeRelations(Hardware* p)
    {
        theHardware = p;
        // Bind this pointer to member function.
        Hardware::callbackMethod cbm =
                  bind(&Handler::onReceive, this,
                       placeholders::_1,
                       placeholders::_2,
                       placeholders::_3);
        theHardware->setCBM(cbm);
    }
    void transmitData()
    {
        theHardware->transmit();
    }
private:
    void onReceive(Hardware* p1, int p2, int p3)
    {
        cout <<"receiving from " <<p1
             <<" values " <<p2 << ", " <<p3 <<endl;
    }
};

int main()
{
    Hardware trx;
    Handler ctrl;
    ctrl.initializeRelations(&trx);
    ctrl.transmitData();
    trx.interrupt();
    return 0;
}


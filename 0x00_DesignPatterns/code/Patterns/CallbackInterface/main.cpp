#include <iostream>
using namespace std;

class Controller;

class Transceiver
{
 public:
    class Callback
    {
    public:
        virtual void onReceive() = 0;
    };
    void subscribe(Callback* p)
    {
        pCallback = p;
    }
    void send()
    {
        cout <<"sending" <<endl;
    }

    Transceiver()
    {
        pCallback = NULL;
    }
    void interrupt()
    {
        pCallback->onReceive();
    }
private:
    Callback* pCallback;
};

class Controller : private Transceiver::Callback
{
private:
    Transceiver* pTransceiver;
    void onReceive()
    {
        cout <<"receiving" <<endl;
    }
public:
    Controller()
    {
        pTransceiver = NULL;
    }
    void initializeRelations(Transceiver* p)
    {
        pTransceiver = p;
        pTransceiver->subscribe(this);
    }
    void transmitData()
    {
        pTransceiver->send();
    }
};

int main()
{
    Transceiver trx;
    Controller ctrl;
    ctrl.initializeRelations(&trx);
    ctrl.transmitData();
    trx.interrupt();
    //ctrl.onReceive();  //:-))
    return 0;
}



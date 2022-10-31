#include <iostream>
using namespace std;

namespace sap
{
    class LayerA
    {
    public:
        virtual void indication() = 0;
    };
    class LayerB
    {
    public:
        virtual void request() = 0;
    };
}

class LayerAEntity : public sap::LayerA
{
private:
    sap::LayerB* pLayerB;
    void indication()
    {
        cout <<"indication from layerB" <<endl;
    }
public:
    LayerAEntity()
    {
        pLayerB = NULL;
    }
    void initializeRelations(sap::LayerB* p)
    {
        pLayerB = p;
    }

    void requestService()
    {
        pLayerB->request();
    }
};

class LayerBEntity : public sap::LayerB
{
private:
    sap::LayerA* pLayerA;
    void request()
    {
        cout <<"request from layer A" <<endl;
    }
public:
    LayerBEntity()
    {
        pLayerA = NULL;
    }
    void setLayerA(sap::LayerA* p)
    {
        pLayerA = p;
    }
    void indicateService()
    {
        pLayerA->indication();
    }
};

int main()
{
    LayerAEntity la;
    LayerBEntity lb;
    la.initializeRelations(&lb);
    lb.setLayerA(&la);
    la.requestService();
    lb.indicateService();
    //not possible
    //la.indication(); :-)))
    //lb.request();    :-)))
    return 0;
}



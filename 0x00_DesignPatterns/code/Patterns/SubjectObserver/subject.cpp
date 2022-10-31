

#include "subject.h"
#include <iostream>

Subject::Subject()
{
    for (int i=0; i<MAX; i++)
        obsList[i]=NULL;
}

void Subject::subscribe(IObserver *obs)
{
    for (int i=0; i<MAX; i++)
        if (obsList[i]==NULL)
        {
            obsList[i]=obs;
            break;
        }
}

void Subject::unSubscribe(IObserver *obs)
{
    for (int i=0; i<MAX; i++)
        if (obsList[i]==obs)
        {
            obsList[i]=NULL;
        }
}

void Subject::notify()
{
    for (int i=0; i<MAX; i++)
        if (obsList[i]!=NULL)
            obsList[i]->update();
}



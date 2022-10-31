

#ifndef SUBJECT_H
#define SUBJECT_H

#define MAX 10
#include "observer.h"

class Subject
{
public:
    Subject();
    void subscribe(IObserver* obs);
    void unSubscribe(IObserver* obs);
protected:
    void notify();
private:
    IObserver* obsList[MAX];
};

#endif // SUBJECT_H



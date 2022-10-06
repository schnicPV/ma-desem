#ifndef NEUTRAL_H
#define NEUTRAL_H

class Neutral
{
public:
    Neutral(bool p1, bool p2);
    void setIn1(bool p1);
    void setIn2(bool p1);
    bool getOut();
protected:
    bool in1;
    bool in2;
    bool out;
};

#endif // NEUTRAL_H


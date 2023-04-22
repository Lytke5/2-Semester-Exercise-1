#ifndef PONY_H
#define PONY_H
#include <iostream>
#include "position.h"

using namespace std;

class Pony
{
protected:
    int geburtsJahr;
    string name;
    Position ort;
public:
    Pony();
    string gibName();
    int gibGeburtsjahr();
    void setzePos(const Position&);
    virtual bool istReitbar(int);
    void zeigeInfo();
};

#endif // PONY_H

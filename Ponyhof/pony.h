#ifndef PONY_H
#define PONY_H
#include <iostream>
#include "position.h"
#include <fstream>

using namespace std;

class Pony
{
protected:
    int geburtsJahr;
    string name;
    Position ort;
public:
    Pony();
    Pony(float x_, float y_);
    const string gibName();
    const int gibGeburtsjahr();
    void setzePos(const Position&);
    virtual bool istReitbar(int);
    void speicherPony(string* race, bool* yesNo);
    const void zeigeInfo();
    ~Pony();
};

#endif // PONY_H

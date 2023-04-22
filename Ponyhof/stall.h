#ifndef STALL_H
#define STALL_H
#include "pony.h"
#define SIZE 20


class Stall
{
private:
    Pony* pferdeboxen[SIZE];
public:
    Stall();
    int belegteBoxen();
    bool einstellen(Pony*);
    Pony* herausholen(std::string);
    float durchschnittsalter();
    void stallReset();
    //void weidegang(?);
    void zeigeInfo();
};

#endif // STALL_H

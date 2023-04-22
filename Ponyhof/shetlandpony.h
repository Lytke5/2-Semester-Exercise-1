#ifndef SHETLANDPONY_H
#define SHETLANDPONY_H
#include "pony.h"


class Shetlandpony : public Pony
{
private:
    bool kinderlieb;
public:
    Shetlandpony(int y, string n, bool k);
    bool istKinderlieb();
    bool istReitbar(int) override;
    void zeigeInfo();
};

#endif // SHETLANDPONY_H

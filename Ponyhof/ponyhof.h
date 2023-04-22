#ifndef PONYHOF_H
#define PONYHOF_H
#include "stall.h"
#include "pony.h"
#include <vector>


class Ponyhof
{
private:
    Stall stallung;
    std::vector<Pony*> beimReiten;
    // ? weide
public:
    Ponyhof();
    void userDialog();

};

#endif // PONYHOF_H

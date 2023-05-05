#include <iostream>
#include "ponyhof.h"

using namespace std;

unsigned ponyHufe(unsigned numPonys)
{
    if(numPonys == 1)
        return 4;
    else
        return 4 + ponyHufe(--numPonys);
}

int main()
{
    Ponyhof* myPonyhof = new Ponyhof();
    ponyHufe(10);

    myPonyhof->userDialog();
    delete myPonyhof;
    return 0;
}

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
    Ponyhof myPonyhof;
    ponyHufe(10);

    myPonyhof.userDialog();
    return 0;
}

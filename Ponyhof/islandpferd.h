#ifndef ISLANDPFERD_H
#define ISLANDPFERD_H
#include "pony.h"


class IslandPferd : public Pony
{
private:
    bool ekzemer;
public:
    IslandPferd(int y, string n, bool e);
    bool hatEkzem();
    bool istReitbar(int) override;
    void zeigeInfo();
};

#endif // ISLANDPFERD_H

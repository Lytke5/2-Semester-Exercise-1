#include "pony.h"
#include "shetlandpony.h"
#include "islandpferd.h"

Pony::Pony()
{


}

string Pony::gibName()
{
    return name;
}

int Pony::gibGeburtsjahr()
{
    return geburtsJahr;
}

bool Pony::istReitbar(int age)
{
    if (Shetlandpony* newPony = dynamic_cast<Shetlandpony*>(this)) {
        return newPony->istReitbar(age);
    } else if (IslandPferd* newPony = dynamic_cast<IslandPferd*>(this)) {
        return newPony->istReitbar(age);
    }
    return false;
}

void Pony::zeigeInfo()
{
    if (Shetlandpony* newPony = dynamic_cast<Shetlandpony*>(this)) {
        newPony->zeigeInfo();
    } else if (IslandPferd* newPony = dynamic_cast<IslandPferd*>(this)) {
        newPony->zeigeInfo();
    }
}

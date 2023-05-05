#include "pony.h"
#include "shetlandpony.h"
#include "islandpferd.h"
#include <fstream>

Pony::Pony()
{
    ort = Position(0,0);
}
Pony::Pony(float x_, float y_)
{
    ort = Position(x_, y_);
}

const string Pony::gibName()
{
    return name;
}

const int Pony::gibGeburtsjahr()
{
    return geburtsJahr;
}

void Pony::setzePos(const Position &newPosition)
{
    ort = newPosition;
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

void Pony::speicherPony(string* race, bool* yesNo)
{
    if (Shetlandpony* savePony = dynamic_cast<Shetlandpony*>(this)) {
        *race = "Shetlandpony";
        if(savePony->istKinderlieb())
            *yesNo = "y";
        else
            *yesNo = "n";
    }
 else if (IslandPferd* savePony = dynamic_cast<IslandPferd*>(this)) {
    *race = "Islandpferd";
    if(savePony->hatEkzem())
        *yesNo = "y";
    else
        *yesNo = "n";
    }
}

const void Pony::zeigeInfo()
{
    if (Shetlandpony* newPony = dynamic_cast<Shetlandpony*>(this)) {
        newPony->zeigeInfo();
    } else if (IslandPferd* newPony = dynamic_cast<IslandPferd*>(this)) {
        newPony->zeigeInfo();
    }
}

Pony::~Pony(){
    cout << "Tschau" <<endl;
}



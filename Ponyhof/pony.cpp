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

string Pony::gibName()
{
    return name;
}

int Pony::gibGeburtsjahr()
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

void Pony::speicherPony()
{
    ofstream myfile;
    myfile.open("ponys.txt");
    if (Shetlandpony* savePony = dynamic_cast<Shetlandpony*>(this)) {
        if (myfile.is_open()) {
            myfile << "Shetlandpony" << endl;
            myfile << savePony->gibName() << endl;
            myfile << savePony->gibGeburtsjahr() << endl;
            if(savePony->istKinderlieb())
                myfile << "y" << endl;
            else
                myfile << "n" << endl;
        }
    } else if (IslandPferd* savePony = dynamic_cast<IslandPferd*>(this)) {
        if (myfile.is_open()) {
            myfile << "Islandpferd" << endl;
            myfile << savePony->gibName() << endl;
            myfile << savePony->gibGeburtsjahr() << endl;
            if(savePony->hatEkzem())
                myfile << "y" << endl;
            else
                myfile << "n" << endl;
        }
    }
        myfile.close();
}

void Pony::zeigeInfo()
{
    if (Shetlandpony* newPony = dynamic_cast<Shetlandpony*>(this)) {
        newPony->zeigeInfo();
    } else if (IslandPferd* newPony = dynamic_cast<IslandPferd*>(this)) {
        newPony->zeigeInfo();
    }
}



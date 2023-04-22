#include "stall.h"

using namespace std;

Stall::Stall()
{

}

int Stall::belegteBoxen()
{
    int count = 0;
    for(int i = 0; i < SIZE; i++)
    {
        if(pferdeboxen[i] != NULL)
            count++;
    }
    return count;
}

bool Stall::einstellen(Pony* newPony)
{
    for(int i = 0; i < SIZE; i++)
    {
        if(pferdeboxen[i] == NULL)
        {
            pferdeboxen[i] = newPony;
            return true;
        }
    }
    return false;
}

Pony* Stall::herausholen(string name)
{
    int age;
    Pony* currPony;
    for(int i = 0; i < SIZE; i++)
    {
        if(pferdeboxen[i]->gibName() == name)
        {
            currPony = pferdeboxen[i];
            pferdeboxen[i] = NULL;
            cout << "Alter des Reiters: ";
            cin >> age;
            if(currPony->istReitbar(age))
            {
                cout << "Pony wird geritten" << endl;
                return currPony;
            }
            else
            {
                cout << "Der Reiter enspricht nicht dem erforderlichen Alter" << endl;
                for(int i = 0; i < SIZE; i++)
                {
                    if(pferdeboxen[i] == NULL)
                    {
                        pferdeboxen[i] = currPony;
                        break;
                    }
                }
                return NULL;
            }
        }
    }
    cout << "Falscher Name" << endl;
    return NULL;
}

void Stall::stallReset()
{
    for(int i = 0; i < SIZE; i++)
    {
        pferdeboxen[i] = NULL;
    }
}

void Stall::zeigeInfo()
{
    cout << "Aktuell sind " << belegteBoxen() << " Boxen belegt" << endl << endl;

    for(int i = 0; i < SIZE; i++)
    {
        pferdeboxen[i]->zeigeInfo();
    }
}

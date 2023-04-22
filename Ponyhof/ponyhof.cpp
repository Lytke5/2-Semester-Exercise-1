#include <fstream>
#include "ponyhof.h"
#include "islandpferd.h"
#include "shetlandpony.h"

using namespace std;
Ponyhof::Ponyhof()
{
    string race;
    string name;
    int birthYear;
    bool yesNo;
    string line;
    ifstream myfile("ponys.txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            race = line;

            getline(myfile, line);
            name = line;

            getline(myfile, line);
            birthYear = stoi(line);

            getline(myfile, line);
            if(line == "y")
                yesNo = true;
            else
                yesNo = false;
            if(race == "Shetlandpony")
            {
                Shetlandpony* newPony = new Shetlandpony(birthYear, name, yesNo);
                stallung.einstellen(newPony);
            }
            else
            {
                IslandPferd* newPony = new IslandPferd(birthYear, name, yesNo);
                stallung.einstellen(newPony);
            }
        }
        myfile.close();
    }
}
void Ponyhof::userDialog()
{
    int input;
    do{
        do{
            cout << endl;
            cout << "1 Pony einstellen" << endl;
            cout << "2 Pony zum Reiten holen" << endl;
            cout << "3 Ponys kontrollieren" << endl;
            cout << "4 Ponys auf Weide schicken" << endl;
            cout << "0 Programm beenden" << endl;
            cin >> input;
        }while(input < 0 || input > 4);

        switch (input) {
        case 1:
        {
            int race;
            string name;
            int birthYear;
            char yn;
            bool yesNo;
            cout << "Welche Rasse? (1: Shetlandpony, 2: Islandpferd)" << endl;

            cin >> race;
            cout << "Geburtsjahr: ";
            cin >> birthYear;
            cout << "Name: ";
            cin >> name;
            if(race == 1)
            {
                cout << "Kinderlieb (y/n): ";
                cin >> yn;
                if(yn == 'y')
                    yesNo = true;
                else
                    yesNo = false;
                Shetlandpony* newPony = new Shetlandpony(birthYear, name, yesNo);
                bool freeSpace = stallung.einstellen(newPony);
                if(freeSpace)
                    cout << "Das neue Pony ist nun im Stall" << endl;
                else
                {
                    delete newPony;
                    cout << "Kein Platz für das Pony mehr im Stall" << endl;
                }
            }
            else if(race == 2)
            {
                cout << "Ekzemer (y/n): ";
                cin >> yn;
                if(yn == 'y')
                    yesNo = true;
                else
                    yesNo = false;
                IslandPferd* newPony = new IslandPferd(birthYear, name, yesNo);
                bool freeSpace = stallung.einstellen(newPony);
                if(freeSpace)
                    cout << "Das neue Pony ist nun im Stall" << endl;
                else
                {
                    delete newPony;
                    cout << "Kein Platz für das Pony mehr im Stall" << endl;
                }
            }
            break;
        }
        case 2:
        {
            Pony* currPony;
            string name;
            cout << "Welches Pony soll herausgeholt werden: ";
            cin >> name;
            currPony = stallung.herausholen(name);

            if(currPony != NULL)
                beimReiten.push_back(currPony);

            break;
        }
        case 3:
            stallung.zeigeInfo();
            cout << "Aktuell werden " << beimReiten.size() << " Ponys geritten" << endl << endl;
            for(int i = 0; i < weide.size(); i++)
                weide[i]->zeigeInfo();
            cout << "Aktuell sind " << weide.size() << " Ponys auf der Weide" << endl;
            break;

        case 4:
            stallung.weidegang(&weide);
            break;
        }
    }while(input != 0);

    for(int i = 0; i < beimReiten.size(); i++)
    {
        stallung.einstellen(beimReiten[i]);
    }
}

Ponyhof::~Ponyhof()
{
    for(int i = 0; i < SIZE; i++)
    {
        Pony* currPony = stallung.herausholen(i);
        if(currPony != NULL)
            currPony->speicherPony();
    }
}

#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include "unownable.h"
#include "board.h"
#include "ownable.h"
#include "academicbuilding.h"

using namespace std;

bool Unownable::isAcademic() { return false; }

void OSAP::handleEvent(Player* p) {
    cout << p->getName() << " collected $200 from OSAP!" << endl;
    p->setBalance(p->getBalance() + 200);
}
void TimsLine::handleEvent(Player* p) { return; }
void GoToTims::handleEvent(Player* p) {
    cout << "You are banished to the DC Tims line!!!!" << endl;
    removePlayer(p);
    p->turnsInLine = 1;
    p->setCurPos(30);
    b->locations[30]->addPlayer(p);
    
}
void GooseNesting::handleEvent(Player* p) {
    cout << p->getName() << " was attacked by geese! Honk honk honk honk honk honk" << endl;
}
void Tuition::handleEvent(Player* p) {
    int worth = p->getBalance();
    for (auto i : p->getBuildings()) {
        worth += i->getWorth();
    }
    cout << "You must pay tuition." << endl
        << "1. Pay $300" << endl
        << "2. Pay 10% of your total worth, which comes out to $" << worth*0.1 << endl;
    
    string cmd;
    getline(cin, cmd);
    while (cmd != "1" && cmd != "2") {
        cout << "Input must be 1 or 2!" << endl;
        getline(cin, cmd);
    }

    int owed = 0;
    if (cmd == "1") owed = 300;
    if (cmd == "2") owed = worth * 0.1;

    if (p->getBalance() < owed) {
        cout << "You don't have enough money to pay tuition!" << endl;
        p->insolvency(owed);
    } else {
        cout << p->getName() << " paid their tuition!" << endl;
        p->setBalance(p->getBalance() - owed);
    }
    
}

void Coop::handleEvent(Player* p) {
    if (p->getBalance() < 150) {
        cout << "You don't have enough money to pay the coop fee ($150)!" << endl;
        p->insolvency(150);
    } else {
        cout << p->getName() << " paid $150 in coop fees! And they still don't have a job!" << endl;
        p->setBalance(p->getBalance() - 150);
    }
}
void SLC::handleEvent(Player* p) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();    
    std::default_random_engine rng{seed};

    int timChance = rng()%100;
    if (timChance == 0 && b->cups < 4) {
        cout << p->getName() << " landed at SLC and received a Roll Up the Rim cup! You can use this to get out of the DC Tims line." << endl;
        p->setCups(p->getCups() + 1);
        b->cups++;
        return;
    }

    int choice = table[rng()%24];       // Picks random action from SLC table according to probability

    // MOVE FORWARDS / BACKWARDS
    if (choice != 100 && choice != 200) {
        int prevPos = p->getCurPos();
        int newPos = prevPos + choice;
        if (newPos < 0) newPos = 40 - newPos;
        else if (newPos > 39) newPos = newPos - 40;

        b->getLocationsArray()[prevPos]->removePlayer(p);
        p->setCurPos(newPos);
        b->getLocationsArray()[newPos]->addPlayer(p);

        cout << p->getName() << " landed at SLC! They moved " << choice << " spaces to " 
            << b->getLocationsArray()[newPos]->getName() << "!" << endl;

        //Player passed OSAP
        if (newPos == 20 || newPos == 19) {
            b->getLocationsArray()[20]->handleEvent(p);
        }

        if (newPos != 20) b->getLocationsArray()[newPos]->handleEvent(p);

    } else {
        int newPos = 0;
        if (choice == 100) newPos = 30;         //Go to DC Tims line
        else newPos = 20;                       //Advance to OSAP

        int prevPos = p->getCurPos();
        b->getLocationsArray()[prevPos]->removePlayer(p);
        p->setCurPos(newPos);
        b->getLocationsArray()[newPos]->addPlayer(p);

        int moves = 0;
        if (prevPos > newPos) moves = 40 - (prevPos-newPos);
        else moves = newPos - prevPos;

        cout << p->getName() << " landed at SLC! They moved " << moves << " spaces to";
        cout << ((choice == 100) ? " collect OSAP!" : " the DC Tims Line") << endl;  

        if (choice == 200 || prevPos >= 31 || prevPos <= 19) {   
            b->getLocationsArray()[20]->handleEvent(p);
        }
    }



}
void NeedlesHall::handleEvent(Player* p) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();    
    std::default_random_engine rng{seed};

    int timChance = rng()%100;
    if (timChance == 0 && b->cups < 4) {
        cout << p->getName() << " landed at Needles Hall and received a Roll Up the Rim cup! You can use this to get out of the DC Tims line." << endl;
        p->setCups(p->getCups() + 1);
        b->cups++;
        return;
    }

    int choice = table[rng()%18];

    cout << p->getName() << " landed at Needles Hall! Their balance has changed by " << choice << endl;
    if (p->getBalance() + choice >= 0) {
        p->setBalance(p->getBalance() + choice);
    } else {
        cout << p->getName() << "can't afford to pay the Needles Hall toll!" << endl;
        p->insolvency(-choice, nullptr);
    }




}

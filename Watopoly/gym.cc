#include <iostream>
#include "gym.h"
#include "board.h"

using namespace std;

Gym::Gym(string name, Board* b, int price, bool mortgage): 
                                Ownable(name, b, price, mortgage) {}

int Gym::getTuition(Player* p) {
    if (getOwner()->gyms == 1) {
        return 4 * p->roll;
    } else if (getOwner()->gyms == 2) {
        return 10 * p->roll;
    }

    cout << "ERROR: GYMS DID NOT EQUAL 1 OR 2" << endl;
    return -1;
}

void Gym::handlePurchase(Player* p) {
    p->gyms++;
}

bool Gym::isAcademic() { return false; }

int Gym::getWorth() {
    return getPrice();
}

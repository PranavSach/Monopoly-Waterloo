#include <iostream>
#include "residence.h"
#include "board.h"

using namespace std;

Residence::Residence(string name, Board* b, int price, bool mortgage): 
                                Ownable(name, b, price, mortgage) {}

int Residence::getTuition(Player* p) {
    if (getOwner()->residences == 1) {
        return 25;
    } else if (getOwner()->residences == 2) {
        return 50;
    } else if (getOwner()->residences == 3) {
        return 100;
    } else if (getOwner()->residences == 4) {
        return 200;
    }

    cout << "ERROR: ResidenceS DID NOT EQUAL 1,2,3, or 4!" << endl;
    return -1;
}

void Residence::handlePurchase(Player* p) {
    p->residences++;
}

bool Residence::isAcademic() { return false; }

int Residence::getWorth() {
    return getPrice();
}

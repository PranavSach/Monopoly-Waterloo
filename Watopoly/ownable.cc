#include <iostream>
#include "board.h"
#include "ownable.h"


using namespace std;

// p1 pays p2  n amount of money
void pay(Player* p1, Player* p2, int n) {
    p1->setBalance(p1->getBalance() - n);
    p2->setBalance(p2->getBalance() + n);
}

Ownable::Ownable(string name, Board* b, int price, bool mortgaged): 
                                Location(name, b), price{price}, mortgaged{mortgaged}, owner{nullptr} {}


int Ownable::getPrice() { return price; }
Player* Ownable::getOwner() { return owner; }
void Ownable::setOwner(Player* player) { owner = player; }
bool Ownable::isMortgaged() { return mortgaged; }
void Ownable::setMortgaged(bool mortgaged) { this->mortgaged = mortgaged; }


void Ownable::mortgage() {
    mortgaged = true;
    owner->setBalance(owner->getBalance() + getPrice()*0.5);
    cout << "You mortgaged " << getName() << "! You got $" << getPrice()*0.5 << "!" << endl;

}

//void Ownable::mortgageLoad() {
//    mortgaged = true;
    /*owner->setBalance(owner->getBalance() + getPrice()*0.5);
    cout << "You mortgaged " << getName() << "! You got $" << getPrice()*0.5 << "!" << endl;*/

//}

void Ownable::mortgageLoad() {
    mortgaged = true;
    /*owner->setBalance(owner->getBalance() + getPrice()*0.5);
    cout << "You mortgaged " << getName() << "! You got $" << getPrice()*0.5 << "!" << endl;*/

}

void Ownable::unmortgage(bool deal) {
    mortgaged = false;
    int price = deal? (getPrice()*0.5) : (getPrice()*0.6);
    owner->setBalance(owner->getBalance() - price);
    cout << "You unmortgaged " << getName() << "! You paid $" << getPrice()*0.6 << "!" << endl;

}


void Ownable::handleEvent(Player* p) {
    if (getOwner() == p || mortgaged) return;
    if (getOwner() == nullptr) {
        if (p->getBalance() < getPrice()) {
            cout << "You don't have enough money to buy " << getName() << " :(" << endl << "The property will now be auctioned." << endl;
            b->auction(this);
            return;
        }

        cout << "Would you like to buy " << getName() << "? It costs $"<< getPrice() <<".(yes/no)" << endl;
        string input;
        getline(cin, input);
        //cin >> input;
        while (input != "yes" && input != "no") {
            cout << "Input must be \"yes\" or \"no\"!" << endl;
            getline(cin, input);
            //cin.ignore();
        }

        if (input == "yes") {
            p->setBalance(p->getBalance() - getPrice());
            setOwner(p);
            p->addBuilding(this);
            handlePurchase(p);

        } else if (input == "no") {
            b->auction(this);
        }
    } else {

        if (p->getBalance() >= getTuition(p)) {
            pay(p, getOwner(), getTuition(p));
            cout << p->getName() << " paid " << getOwner()->getName() << " " << getTuition(p) << " dollars!" << endl;
        } else {
            cout << "You dont have enough money to pay " << getOwner()->getName() << " their tuition!" << endl;
            p->insolvency(getTuition(p), getOwner());
        }
    }
}



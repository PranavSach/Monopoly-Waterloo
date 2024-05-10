#include <algorithm>
#include "player.h"


using namespace std;

Player::Player(string name, const char character, int curPos, int balance, int cups): 
                    name{name}, character{character}, curPos{curPos}, balance{balance},
                    cups{cups}, gyms{0}, residences{0}, roll{0}, turnsInLine{0}, 
                    insolvent{false}, debt{0}, oweTo{nullptr}, inAuction{false}, bid{0},
                    bankrupt{false} {}

char Player::getChar() { return character; }
string Player::getName() { return name; }
int Player::getBalance() { return balance; }
void Player::setBalance(int n) { balance = n; }
int Player::getCurPos(){ return curPos; }
void Player::setCurPos(int newPos){ curPos = newPos; }
void Player::addBuilding(Ownable* building){ ownedBuildings.push_back(building); }
void Player::removeBuilding(Ownable* building){ 
    vector<Ownable* >::iterator it = find(ownedBuildings.begin(), ownedBuildings.end(), building);
    if (it != ownedBuildings.end()) {
        ownedBuildings.erase(it);
    }
 }
int Player::numBuildings() { return ownedBuildings.size(); }
std::vector<Ownable*> Player::getBuildings() { return ownedBuildings; }
int Player::getCups(){ return cups; }
void Player::setCups(int n){ cups = n; }

void Player::insolvency(int debt, Player* to){
    insolvent = true;
    this->debt = debt;
    this->oweTo = to;
}

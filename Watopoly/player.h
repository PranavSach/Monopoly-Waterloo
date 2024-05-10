#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <vector>
#include <string>

class Location;
class Ownable;
class Player {
    std::string name;
    const char character;
    int curPos;
    int balance;
    int cups;
    std::vector<Ownable*> ownedBuildings;



public:
    int roll;
    int gyms;
    int residences;
    int turnsInLine;
    bool insolvent;
    int debt;
    Player* oweTo;
    bool inAuction;
    int bid;

    bool bankrupt;

    Player(std::string name, const char character, int curPos, int balance, int cups);
    char getChar();
    std::string getName();
    int getBalance();
    void setBalance(int n);
    int getCurPos();
    void setCurPos(int newPos);
    void addBuilding(Ownable* building);
    void removeBuilding(Ownable* building);
    int numBuildings();
    std::vector<Ownable*> getBuildings();
    int getCups();
    void setCups(int n);

    void insolvency(int debt, Player* to = nullptr);



};




#endif

#ifndef __LOCATION_H__
#define __LOCATION_H__
#include <vector>
#include <string>
#include "player.h"

class Board;
class Location {
    std::string name;
    //std::vector<Player *> playersHere;
protected:
    Board* b;
public:
    std::vector<Player *> playersHere;
    Location(std::string name, Board* b);
    virtual void handleEvent(Player* p) = 0;
    void addPlayer(Player *p);
    void removePlayer(Player *p);
    std::string getName();
    virtual bool isAcademic() = 0;

    
};

#endif

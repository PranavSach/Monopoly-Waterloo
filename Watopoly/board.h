#ifndef __BOARD_H__
#define __BOARD_H__
#include <vector>
#include <string>
#include "location.h"
#include "player.h"
#include "display.h"

class AcademicBuilding;
class Board {
    //std::vector<Location*> locations;
    Player* curPlayer;
    Display* d;
    int playerCount;

public:
    //std::vector<Location*> locations;
    // change
    int cups;
    Location* locations[40];
    std::vector<Player*> players;
    std::vector<std::vector<int>> monopolies;

    Board();
    ~Board();
    bool roll(int d1 = 0, int d2 = 0, bool testing = false);
    void next();
    void trade(Player* p, Ownable* o1, Ownable* o2);
    void trade(Player* p, int money, Ownable* o);
    void trade(Player* p, Ownable* o, int money);
    void improve(AcademicBuilding* ac, bool buy);
    void mortgage(Ownable* o);
    void unmortgage(Ownable* o, bool deal = false);
    void bankrupt();
    void assets();
    void all();
    void load(std::string name);
    void loadPlayers();
    void saveGame(std::string filename);

    void auction(Ownable* o);

    const std::vector<Location*>& getLocations();
    Location** getLocationsArray();
    Display* getDisplay();
    Player* getCurrentPlayer();
    void setCurrentPlayer(Player* p);
    Location* findLocation(std::string name);
    Player* findPlayer(std::string name);
};

#endif

#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__
#include <vector>
#include <string>
#include "board.h"

class Controller {
    Board* b;

public:
    bool testing;
    Controller();
    ~Controller();
    void play();
    void load(std::string name);
    void loadPlayers();


};

#endif

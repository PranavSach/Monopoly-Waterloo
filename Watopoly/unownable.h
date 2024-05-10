#ifndef __UNOWNABLE_H__
#define __UNOWNABLE_H__
#include <vector>
#include <string>
#include "location.h"

class Unownable : public Location {
public:
    Unownable(std::string name, Board* b) : Location(name, b) {}
    bool isAcademic() override;

};

class OSAP : public Unownable {
public:
    OSAP(std::string name, Board* b): Unownable(name, b) {}
    void handleEvent(Player* p) override;
};

class TimsLine : public Unownable {
public:
    TimsLine(std::string name, Board* b): Unownable(name, b) {}
    void handleEvent(Player* p) override;
};

class GoToTims : public Unownable {
public:
    GoToTims(std::string name, Board* b): Unownable(name, b) {}
    void handleEvent(Player* p) override;
};

class GooseNesting : public Unownable {
public:
    GooseNesting(std::string name, Board* b): Unownable(name, b) {}
    void handleEvent(Player* p) override;
};

class Tuition : public Unownable {
public:
    Tuition(std::string name, Board* b): Unownable(name, b) {}
    void handleEvent(Player* p) override;
};

class Coop : public Unownable{ 
    public:
    Coop(std::string name, Board* b): Unownable(name, b) {}
    void handleEvent(Player* p) override;
};

class SLC : public Unownable {
    std::vector<int> table;
public:
    SLC(std::string name, Board* b): Unownable(name, b) {
        table = {-3,-3,-3,          // Back 3: 1/8 chance
                -2,-2,-2,-2,        // Back 2: 1/6 chance
                -1,-1,-1,-1,        // Back 1: 1/6 chance
                1,1,1,              // Forward 1: 1/8 chance
                2,2,2,2,            // Forward 2: 1/6 chance
                3,3,3,3,            // Forward 3: 1/6 chance
                100,                // DC Tims Line: 1/24 chance
                200                 // OSAP: 1/24 chance
        };
    }
    void handleEvent(Player* p) override;
};

class NeedlesHall : public Unownable {
    std::vector<int> table;
public:
    NeedlesHall(std::string name, Board* b): Unownable(name, b) {
        table = {-200,                  // -200: 1/18 chance
                -100, -100,             // -100: 1/9 chance
                -50, -50, -50,          // -50: 1/6 chance
                25, 25, 25, 25, 25, 25, // 25: 1/3 chance
                50, 50, 50,             // 50: 1/6 chance
                100, 100,               // 100: 1/9 chance
                200                     // 200: 1/18 chance
        };
    }
    void handleEvent(Player* p) override;
};

#endif

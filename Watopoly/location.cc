#include <iostream>
#include "location.h"

using namespace std;

Location::Location(string name, Board* b): b{b}, name{name} {}

string Location::getName() {
    return name;
}

void Location::addPlayer(Player* p) {
    playersHere.push_back(p);
}

void Location::removePlayer(Player* p) {
    for (auto it = playersHere.begin(); it != playersHere.end(); it++ ) {
        if (*it == p) {
            //cout << "OWW" << endl;
            playersHere.erase(it);
            return;

        }
    }
}

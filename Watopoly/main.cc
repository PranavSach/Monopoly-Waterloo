#include <iostream>
#include "controller.h"
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    Controller* c = new Controller;
    bool loaded = false;
    if (argc >= 2){
        for (int i = 1; i < argc; i++) {
            if (string(argv[i]) == "-load") {
                string name = argv[i+1];
                c->load(name);
                loaded = true;
            }
            if(string(argv[i]) == "-testing") {
                c->testing = true;
            }
        }
    }
    if(!loaded) {
        c->loadPlayers();
    }
    if(!loaded) cin.ignore();

    c->play();

    delete c;
}

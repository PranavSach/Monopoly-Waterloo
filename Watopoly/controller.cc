#include <iostream>
#include <sstream>
#include <algorithm>
#include "controller.h"
#include "ownable.h"
#include "academicbuilding.h"

using namespace std;

Controller::Controller(): testing{false} {
    b = new Board;

}

Controller::~Controller() {
    delete b;
}

void Controller::load(string name){
    b->load(name);
}

void Controller::loadPlayers(){
    b->loadPlayers();
}

void Controller::play() {
    //bool testing = true;
    bool turnFinished = false;
    bool rolled = false;
    bool playerInsolvent;
    int doubleCount = 0;

    b->getDisplay()->render();

    //cin.ignore();
    while (true) {
        Player* curPlayer = b->getCurrentPlayer();
        playerInsolvent = curPlayer->insolvent;

        turnFinished = false;
        
        
        string line;
        string cmd;
        cout << "It is " << curPlayer->getName() << "'s turn!" << endl;
        if (curPlayer->turnsInLine > 0 && !playerInsolvent && !rolled) {
            cout << "You are in the Tims Line, roll doubles to leave." << endl;
        }
        //cin >> cmd;
        
        getline(cin, line);

        istringstream iss{line};
        iss >> cmd;

        

        
        if (cmd == "roll" && !playerInsolvent) {
            if (rolled) { 
                cout << "You have already rolled." << endl;
            } else {
                if (testing) {
                    int d1 = 0;
                    int d2 = 0;
                    bool diceSpecified = false;

                    if(iss >> d1) diceSpecified = true;
                    if(iss >> d2) diceSpecified = true;
                    
                    rolled = !b->roll(d1,d2, diceSpecified);
                } else {
                    rolled = !b->roll();
                }
                if (!rolled) {
                    doubleCount++;
                    if (doubleCount == 3) {
                        cout << "You rolled doubles 3 times in a row! >:( You're under arrest for being too good, go to the DC Tims Line." << endl;
                        rolled = true;
                        doubleCount = 0;
                        b->locations[10]->handleEvent(curPlayer);
                        continue;
                    }
                    cout << "You rolled doubles! You get to roll again!" << endl;
                    

                }
            }

        } else if (cmd == "next" && !playerInsolvent) {
            if (!rolled) {
                cout << "You have to roll before you can finish your turn." << endl;
            } else {
                turnFinished = true;
            }
        } else if (cmd == "trade") {
            string name;
            string give;
            string receive;

            iss>>name;
            iss>>give;
            iss>>receive;

            if (!iss) {
                cout << "You need a (name) argument, a (give) argument and a (receive) argument." << endl;
                continue;
            }

            Player* to = b->findPlayer(name);

            if (!to) {
                cout << name << "is not the name of a player." << endl;
                continue;
            }
            
            istringstream issgive{give};
            istringstream issreceive{receive};

            int igive;
            int ireceive;
            issgive>>igive;
            issreceive>>ireceive;

            if(issgive && issreceive) {
                cout << "Both give and receive cannot be money!" << endl;
                continue;
            }
            if (issgive) {
                //cout << "GIVE INT, RECEIEVE PROP" << endl;
                Ownable* o = dynamic_cast<Ownable*>(b->findLocation(receive));
                if (o) {
                    b->trade(to, igive, o);
                } else {
                    cout << receive << " is not an ownable building." << endl;
                }
            } else if (issreceive) {
                //cout << "GIVE PROP, RECEIEVE INT" << endl;
                Ownable* o = dynamic_cast<Ownable*>(b->findLocation(give));
                if (o) {
                    b->trade(to, o, ireceive);
                } else {
                    cout << give << " is not an ownable building." << endl;
                }
            } else {
                //cout << "GIVE PROP, RECEIEVE PROP" << endl;
                Ownable* o1 = dynamic_cast<Ownable*>(b->findLocation(give));
                Ownable* o2 = dynamic_cast<Ownable*>(b->findLocation(receive));

                if (!o1) {
                    cout << give << " is not an ownable building." << endl;
                } else if (!o2) {
                    cout << receive << " is not an ownable building." << endl;
                } else {
                    b->trade(to,o1,o2);
                }
            }


            

            

        } else if (cmd == "improve") {
            string property;
            if (!(iss>>property)) {
                cout << "Please specify a property." << endl;
            } else {
                string buysell;
                if (!(iss>>buysell) || (buysell != "buy" && buysell != "sell")) {
                    cout << "Please specify whether you want to buy/sell an improvement." << endl;
                } else {
                    Location* loc = b->findLocation(property);
                    if (loc) {
                        AcademicBuilding* ac = dynamic_cast<AcademicBuilding*>(loc);
                        if (ac) {
                            b->improve(ac, buysell == "buy");
                        } else {
                            cout << loc->getName() << "is not an academic building!" << endl; 
                        }
                    } else {
                        cout << property << "is not a property!" << endl;
                    }
                }
            }

        } else if (cmd == "mortgage") {
            string property;
            if (!(iss>>property)) {
                cout << "Please specify a property." << endl;
            } else {
                Location* loc = b->findLocation(property);
                if (loc) {
                    Ownable* o = dynamic_cast<Ownable*>(loc);
                    if (o) {
                        b->mortgage(o);
                    } else {
                        cout << loc->getName() << "is not an ownable property!" << endl; 
                    }
                } else {
                    cout << property << "is not a property!" << endl;
                }
            }

        } else if (cmd == "unmortgage" && !playerInsolvent) {
            string property;
            if (!(iss>>property)) {
                cout << "Please specify a property." << endl;
            } else {
                Location* loc = b->findLocation(property);
                if (loc) {
                    Ownable* o = dynamic_cast<Ownable*>(loc);
                    if (o) {
                        b->unmortgage(o);
                    } else {
                        cout << loc->getName() << "is not an ownable property!" << endl; 
                    }
                } else {
                    cout << property << "is not a property!" << endl;
                }
            }
        } else if (cmd == "bankrupt") {
            if (!playerInsolvent) {
                cout << "You aren't insolvent, so you can't declare bankruptcy." << endl;
            } else {
                if (b->players.size() == 2) {
                    Player* winner;
                    for (auto i : b->players) {
                        if (i != curPlayer) {
                            winner = i;
                            break;
                        }
                    }

                    cout << endl;
                    for (int i = 0; i < 20; i++) {
                        cout << "\\o/";
                    }
                    cout << endl;
                    cout << winner->getName() << " HAS WON!!!" << endl;
                    cout << "\\o/ CONGRATULATIONS \\o/" << endl; 
                    for (int i = 0; i < 25; i++) {
                        cout << "o7";
                    }
                    cout << endl;
                    return;

                }
                b->bankrupt();
                turnFinished = true;


            }
        } else if (cmd == "assets") {
            b->assets();

        } else if (cmd == "all") {
            b->all();

        }  else if (cmd == "quit") {
            return;
        } else if (cmd == "save"){
            string filename;
            iss >> filename;
            b->saveGame(filename);
        }

        if (playerInsolvent && curPlayer->getBalance() >= curPlayer->debt && !curPlayer->bankrupt) {
            
            curPlayer->setBalance(curPlayer->getBalance() - curPlayer->debt);


            cout << curPlayer->getName() << " successfully gathered enough funds to pay off what they owe!" << endl;
            cout << curPlayer->getName() << " paid ";
            if (curPlayer->oweTo == nullptr) {
                cout << curPlayer->debt << " to the school!" << endl;
            } else {
                curPlayer->oweTo->setBalance(curPlayer->oweTo->getBalance() + curPlayer->debt);
                cout << curPlayer->debt << " to " << curPlayer->oweTo->getName() << "!" << endl;
            }
            curPlayer->insolvent = false;
            curPlayer->debt = 0;
            curPlayer->oweTo = nullptr;
        }

        playerInsolvent = curPlayer->insolvent;

        if (playerInsolvent && !curPlayer->bankrupt) {
            cout << "You are insolvent. Either raise funds to pay what you owe ($" << curPlayer->debt << "), or declare bankruptcy." << endl
                << "You may mortgage properties, sell improvements, and trade with other players to raise funds." << endl;
        }

        if (turnFinished && !playerInsolvent || curPlayer->bankrupt ) {
            rolled = false;
            doubleCount = 0;
            for (auto it = b->players.begin(); it != b->players.end(); it++) {
                if (*it == curPlayer) {
                    if (it+1 == b->players.end()) {
                        b->setCurrentPlayer(b->players[0]);
                    } else {
                        b->setCurrentPlayer(*(it+1));
                    }
                    break;
                }
            }
        }

        if (curPlayer->bankrupt) {
            vector<Player* >::iterator cur = find(b->players.begin(), b->players.end(), curPlayer);
            b->players.erase(cur);
            delete curPlayer;
        }

        
    }

}

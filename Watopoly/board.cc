#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <random>
#include <chrono>
#include <algorithm>
#include "board.h"
#include "academicbuilding.h"
#include "gym.h"
#include "residence.h"
#include "unownable.h"

using namespace std;

Board::Board(): cups{4}, playerCount{0} {
    d = new Display(this);

    /*locations.push_back(new AcademicBuilding("DC", this, 400, false, 0, 50));
    locations.push_back(new AcademicBuilding("MC", this, 350, false, 0, 35));
    locations.push_back(new AcademicBuilding("DP", this, 500, false, 0, 55));
    */

    locations[0] = new GooseNesting("Goose Nesting", this);
    locations[1] = new AcademicBuilding("EV1", this, 220, false, 150, 18, 90, 250 ,700, 875, 1050, 0);
    locations[2] = new NeedlesHall("NEEDLES HALL", this);
    locations[3] = new AcademicBuilding("EV2", this, 220, false, 150, 18, 90, 250, 700, 875, 1050, 0);
    locations[4] = new AcademicBuilding("EV3", this, 240, false, 150, 20, 100, 300, 750, 925, 1100, 0);
    locations[5] = new Residence("V1", this, 200, false);
    locations[6] = new AcademicBuilding("PHYS", this, 260, false, 150, 22, 110, 330, 800, 975, 1150, 1);
    locations[7] = new AcademicBuilding("B1", this, 260, false, 150, 22, 110, 330, 800, 975, 1150, 1);
    locations[8] = new Gym("CIF", this, 150, false);
    locations[9] = new AcademicBuilding("B2", this, 280, false, 150, 24, 120, 360 , 850, 1025, 1200, 1);
    locations[10] = new GoToTims("Go To Tims", this);
    locations[11] = new AcademicBuilding("EIT", this, 300, false, 200, 26, 130, 390, 900, 1100, 1275, 2);
    locations[12] = new AcademicBuilding("ESC", this, 300, false, 200, 26, 130, 390, 900, 1100, 1275, 2);
    locations[13] = new SLC("SLC", this);
    locations[14] = new AcademicBuilding("C2", this, 320, false, 200, 28, 150, 450, 1000, 1200, 1400, 2);
    locations[15] = new Residence("REV", this, 200, false);
    locations[16] = new NeedlesHall("NEEDLES HALL", this);
    locations[17] = new AcademicBuilding("MC", this, 350, false, 200, 35, 175, 500, 1100, 1300, 1500, 3);
    locations[18] = new Coop("COOP FEE", this);
    locations[19] = new AcademicBuilding("DC", this, 400, false, 200, 50, 200, 600, 1400, 1700, 2000, 3);
    locations[20] = new OSAP("COLLECT OSAP", this);
    locations[21] = new AcademicBuilding("AL", this, 40, false, 50, 2, 10, 30, 90, 160, 250, 4);
    locations[22] = new SLC("SLC", this);
    locations[23] = new AcademicBuilding("ML", this, 60, false, 50, 4, 20, 60, 180, 320, 450, 4);
    locations[24] = new Tuition("TUITION", this);
    locations[25] = new Residence("MKV", this, 200, false);
    locations[26] = new AcademicBuilding("ECH", this, 100, false, 50, 6, 30, 90, 270, 400, 550, 5);
    locations[27] = new NeedlesHall("NEEDLES HALL", this);
    locations[28] = new AcademicBuilding("PAS", this, 100, false, 50, 6, 30, 90, 270, 400, 550, 5);
    locations[29] = new AcademicBuilding("HH", this, 120, false, 50, 8, 40, 100, 300, 450, 600, 5);
    locations[30] = new TimsLine("DC Tims Line", this);
    locations[31] = new AcademicBuilding("RCH", this, 140, false, 100, 10, 50, 150, 450, 625, 750, 6);
    locations[32] = new Gym("PAC", this, 150, false);
    locations[33] = new AcademicBuilding("DWE", this, 140, false, 100, 10, 50, 150, 450, 625, 750, 6);
    locations[34] = new AcademicBuilding("CPH", this, 160, false, 100, 12, 60, 180, 500, 700, 900, 6);
    locations[35] = new Residence("UWP", this, 200, false);
    locations[36] = new AcademicBuilding("LHI", this, 180, false, 100, 14, 70, 200, 550, 750, 950, 7);
    locations[37] = new SLC("SLC", this);
    locations[38] = new AcademicBuilding("BMH", this, 180, false, 100, 14, 70, 200, 550, 750, 950, 7);
    locations[39] = new AcademicBuilding("OPT", this, 200, false, 100, 16, 80, 220, 600, 800, 1000, 7);

    
    monopolies.push_back(std::vector<int>{1,3,4});
    monopolies.push_back(std::vector<int>{6,7,9});
    monopolies.push_back(std::vector<int>{11,12,14});
    monopolies.push_back(std::vector<int>{17,19});
    monopolies.push_back(std::vector<int>{21,23});
    monopolies.push_back(std::vector<int>{26,28,29});
    monopolies.push_back(std::vector<int>{31,33,34});
    monopolies.push_back(std::vector<int>{36,38,39});

    /*players.push_back(new Player("Pranav", 'P', 20, 500, 0));
    players.push_back(new Player("DannyBoy", 'D', 20, 500, 0));
    players.push_back(new Player("Britches", 'B', 20, 500, 0));
    players.push_back(new Player("Arya", 'A', 20, 500, 0));

    locations[20]->addPlayer(players[0]);
    locations[20]->addPlayer(players[1]);
    locations[20]->addPlayer(players[2]);
    locations[20]->addPlayer(players[3]);
    

    curPlayer = players[0];*/

}

void Board::saveGame(string filename){
    ofstream myfile(filename);
    myfile << playerCount << endl;
    int playerIndex = 0;
    for (int i = 0; i < playerCount; i++){
        if (players[i] == getCurrentPlayer()){
            playerIndex = i;
        }
    }
    for (int i = 0; i < playerCount; i++){
        int curPos = players[playerIndex]->getCurPos() + 20;
        if (curPos >= 40){
            curPos = curPos - 40;
        }
        myfile << players[playerIndex]->getName() << " " << players[playerIndex]->getChar() << " " << players[playerIndex]->getCups() << " " << 
        players[playerIndex]->getBalance() << " " << curPos;
        if (curPos == 10){
            if (players[playerIndex]->turnsInLine > 0){
                myfile << " 1 " << players[playerIndex]->turnsInLine - 1<< endl;
            }
            else{
                myfile << " 0 " << endl;
            }
        }
        else {
            myfile << endl;
        }
        playerIndex++;
        if (playerIndex >= playerCount){
            playerIndex = 0;
        }
    }
    for (int i = 0; i < 40; i++){
        int pos;
        pos = i + 20;
        if (pos >= 40){
            pos = pos - 40;
        }
        if (i == 0 || i == 2 || i == 4||i == 7||i == 10||i == 17||i == 20||i == 22||i == 30||i == 33||
        i == 36||i == 38){
            continue;
        }
        myfile << locations[pos]->getName() << " ";
        Ownable* cur = static_cast<Ownable*> (locations[pos]);
        if (cur->getOwner() == nullptr){
            myfile << "BANK ";
        }
        else {
            myfile << cur->getOwner()->getName() << " ";
        }
        if (cur->isMortgaged() == true){
            myfile << "-1" << endl;
        }
        else {
            if (cur->isAcademic()){
                AcademicBuilding* accur = static_cast<AcademicBuilding*> (locations[pos]);
                myfile << accur->getImprovements() << endl;
            }
            else{
                myfile << "0" << endl;
            }
        }

    }
    myfile.close();
}

void Board::loadPlayers(){
    cout << "Please enter the number of players currently playing : (number must be between 2 and 8)" << endl;
    int number;
    while (cin >> number){
        if (!(number >= 2 && number <= 8)){
            cout << "Number out of the range! Please re-enter" << endl;
            continue;
        }
        else {
            playerCount = number; 
            break; 
        }
    }
    for (int i = 0; i < playerCount; i++){
        cout << "Enter Player " << i+1 << "'s name (make sure it is one word)" << endl;
        string name;
        cin >> name;
        bool repeatedName = false;
        if (name == "BANK"){
            cout << "BANK is an invalid player name! Please re-enter." << endl;
            i--;
            continue;
        }
        for (auto j:players){
            if ( name == j->getName()){
                cout << "This name has already been selected. Kindly choose another name." << endl;
                repeatedName = true;
                break;
            }
        }
        if (repeatedName == true){
            i--;
            continue;
        }
        cout << "Choose out of the following characters: (Enter the corresponding Char)" << endl;
        cout << "Name:  Goose    GRT Bus    Tim Hortons Doughnut    Professor    Student    Money    Laptop    Pink tie" << endl;
        cout << "Char:    G         B                 D                 P           S         $         L         T" << endl;
        char input;
        while (cin >> input){
            bool error = false;
            for (auto i: players){
                if ( input == i->getChar()){
                    cout << "This character has already been selected. Kindly choose another character." << endl;
                    error = true;
                    break;
                }
            }
            if (error == true){
                continue;
            }
            if (input == 'G'){
                players.push_back(new Player(name, 'G', 20, 1500, 0));
                break;
            }
            else if (input == 'B'){
                players.push_back(new Player(name, 'B', 20, 1500, 0));
                break;
            }
            else if (input == 'D'){
                players.push_back(new Player(name, 'D', 20, 1500, 0));
                break;
            }
            else if (input == 'P'){
                players.push_back(new Player(name, 'P', 20, 1500, 0));
                break;
            }
            else if (input == 'S'){
                players.push_back(new Player(name, 'S', 20, 1500, 0));
                break;
            }
            else if (input == '$'){
                players.push_back(new Player(name, '$', 20, 1500, 0));
                break;
            }
            else if (input == 'L'){
                players.push_back(new Player(name, 'L', 20, 1500, 0));
                break;
            }
            else if (input == 'T'){
                players.push_back(new Player(name, 'T', 20, 1500, 0));
                break;
            }
            else {
                cout << "Not a valid Char. Please re-enter" << endl; 
            }
        }
    }
    for (int i = 0; i < playerCount; i++){
        locations[20]->addPlayer(players[i]);
    }
    curPlayer = players[0];
}

Board::~Board() {
    delete d;
    for (int i = 0; i < 40; i++){
        delete locations[i];
    }
    for (auto i : players) {
        delete i;
    }
}

void Board::load(string name){
    string line;
    ifstream file(name);
    getline(file, line);
    istringstream iss(line);
    iss >> playerCount;
    while (true){
        for (int i = 0; i < playerCount; i++){
            getline(file, line);
            istringstream iss(line);
            string playerName;
            char c;
            int cups;
            int money;
            int pos;
            bool inLine;
            int posInLine;
            iss >> playerName;
            iss >> c;
            iss >> cups;
            iss >> money;
            iss >> pos;
            pos = pos + 20;
            if (pos >= 40){
                pos = pos - 40;
            }
            if (pos == 30){
                iss >> inLine;
                if (inLine == true){
                    iss >> posInLine;
                }
            }
            players.push_back(new Player(playerName, c, pos, money, cups));
            locations[pos]->addPlayer(players[i]);
            if (inLine == true){
                players[i]->turnsInLine = posInLine+1;
            }
        }
            for (int i = 0; i < 40; i ++){
                if (i == 0 || i == 2 || i == 4||i == 7||i == 10||i == 17||i == 20||i == 22||i == 30||i == 33||
                    i == 36||i == 38){
                    continue;
                }
                int pos = i;
                pos = pos + 20;
                if (pos >= 40){
                    pos = pos - 40;
                }
                getline(file, line);
                istringstream iss(line);
                string buildingName;
                string ownerName;
                int improvements;
                iss >> buildingName;
                iss >> ownerName;
                iss >> improvements;
                if (ownerName == "BANK"){
                    continue;
                }
                else{
                    Ownable* cur = static_cast<Ownable*> (locations[pos]);
                    cur->setOwner(findPlayer(ownerName));
                    findPlayer(ownerName)->addBuilding(cur);
                    if (improvements == -1){
                        cur->mortgageLoad();
                    }
                    else if (cur->isAcademic() == true){
                        AcademicBuilding* cur = static_cast<AcademicBuilding*> (locations[pos]);
                        cur->setImprovements(improvements);
                    }
                    else{
                        if (i == 12 || i == 28){
                            findPlayer(ownerName)->gyms++;
                        }
                        else {
                            findPlayer(ownerName)->residences++;
                        }
                    }
                    
                    
                    
                }
            }
            break;

        }
    curPlayer = players[0];
}
bool Board::roll(int d1, int d2, bool testing) {

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();    
    std::default_random_engine rng{seed};

    int dice1, dice2;

    if (!testing) {
        dice1 = rng()%6 + 1;
        dice2 = rng()%6 + 1;
    } else {
        dice1 = d1;
        dice2 = d2;
    }



    int moves = dice1 + dice2;

    curPlayer->roll = moves;

    if (curPlayer->turnsInLine > 0) {
        if (dice1 == dice2) {
            cout << "You rolled doubles! You get to leave the DC Tims line!" << endl;
            curPlayer->turnsInLine = 0;
        } else {
            cout << "1. Pay $50 to leave the line" << endl
                << "2. Use a Tims Cup to leave the line (You currently have " << curPlayer->getCups() << " cups.)" << endl;
            if (curPlayer->turnsInLine < 3) {
                cout << "3. Don't leave the line (You must leave after 3 turns in line!)" << endl;
            }

            string cmd;
            while (getline(cin, cmd)) {
                if (cmd == "1") {
                    if (curPlayer->getBalance() < 50) {
                        cout << "You can't afford to pay $50 to leave the DC Tims Line!" << endl;
                        curPlayer->insolvency(50);
                        return false;
                    }
                    curPlayer->setBalance(curPlayer->getBalance() - 50);
                    curPlayer->turnsInLine = 0;
                    break;
                } else if (cmd == "2") {
                    if (curPlayer->getCups() > 0) {
                        curPlayer->setCups(curPlayer->getCups() - 1);
                        curPlayer->turnsInLine = 0;
                        cups--;
                        break;
                    } else {
                        cout << "You don't have any Tims Cups!" << endl;
                    }
                    
                } else if (cmd == "3") {
                    curPlayer->turnsInLine++;
                    break;
                } else {
                    if (curPlayer->turnsInLine >= 3) {
                        cout << "Input must be 1 or 2!" << endl;
                    } else {
                        cout << "Input must be 1, 2, or 3!" << endl;
                    }
                }
            }
        }
    }

    if (curPlayer->turnsInLine > 0) return false;

    int prevPos = curPlayer->getCurPos();
    if (moves + curPlayer->getCurPos() >= 40) { //magic number for now, last index
        locations[curPlayer->getCurPos()]->removePlayer(curPlayer);
        curPlayer->setCurPos((moves+curPlayer->getCurPos()) - 40);
        locations[curPlayer->getCurPos()]->addPlayer(curPlayer);
    } else {
        locations[curPlayer->getCurPos()]->removePlayer(curPlayer);
        curPlayer->setCurPos(curPlayer->getCurPos()+moves);
        locations[curPlayer->getCurPos()]->addPlayer(curPlayer);
    }


    d->render();

    cout << "First dice: " << dice1 << ", Second dice: " << dice2 << endl;


    if (prevPos < 20 && moves >= 20-prevPos ||
        prevPos > 20 && moves >= (40-prevPos) + 20 ) {
            locations[20]->handleEvent(curPlayer);
        }

    if (curPlayer->getCurPos() != 20) locations[curPlayer->getCurPos()]->handleEvent(curPlayer);

    return (dice1 == dice2);
    //cin.clear();
    //cin.ignore(1000, '\n');
}


void Board::improve(AcademicBuilding* ac, bool buy) {
    if (ac->getOwner() != curPlayer) {
        cout << "You don't own " << ac->getName() << "!" << endl;
        return;
    }
    if (buy) {
        if (ac->getOwner()->getBalance() < ac->getImpCost()) {
            cout << "You can't afford to buy an improvement ($" << ac->getImpCost() << ") for this building." << endl;
            return;
        }

        for (auto i : monopolies[ac->getMonopoly()]) {
            if (dynamic_cast<AcademicBuilding*>(locations[i])->getOwner() != curPlayer) {
                cout << "You don't own the monopoly associated with " << ac->getName() 
                    << ", so you can't purchase any improvements." << endl;
                return;
            }
        }

        if (ac->getImprovements() < 5) {
            ac->setImprovements(ac->getImprovements() + 1);
            ac->getOwner()->setBalance(ac->getOwner()->getBalance() - ac->getImpCost());
            cout << ac->getOwner()->getName() << " purchased an improvement for " << ac->getName() << " for $" 
                << ac->getImpCost() << "!" << endl;
        } else {
            cout << ac->getName() << " has the maximum number of improvements." << endl;
        }

    } else {
        if (ac->getImprovements() < 1) {
            cout << ac->getName() << " doesn't have any improvements on it to sell." << endl;
            return;
        } else {
            ac->setImprovements(ac->getImprovements() - 1);
            ac->getOwner()->setBalance(ac->getOwner()->getBalance() + ac->getImpCost()*0.5);
            cout << ac->getOwner()->getName() << " sold an improvement from " << ac->getName() << " for $" 
                << ac->getImpCost()*0.5 << "!" << endl;

        }
    }
}


void Board::mortgage(Ownable* o) {
    if (o->getOwner() != curPlayer) {
        cout << "You don't own " << o->getName() << "!" << endl;
        return;
    }
    if (o->isMortgaged()) {
        cout << o->getName() << "is already mortgaged!" << endl;
        return;
    }

    if (o->isAcademic()) {
        if (static_cast<AcademicBuilding*>(o)->getImprovements() > 0) {
            cout << "You must sell all improvements on " << o->getName() << " before you can mortgage it!" << endl;
            return;
        }
    }

    o->mortgage();
}

void Board::unmortgage(Ownable* o, bool deal) {
    if (o->getOwner() != curPlayer) {
        cout << "You don't own " << o->getName() << "!" << endl;
        return;
    }
    if (!o->isMortgaged()) {
        cout << o->getName() << " is already unmortgaged!" << endl;
        return;
    }
    if (!deal) {
        if (curPlayer->getBalance() < o->getPrice()*0.6) {
            cout << "You can't afford to unmortgage " << o->getName() << "! It costs 60% of " 
                << o->getName() << "'s price to unmortgage it, which is $" << o->getPrice()*0.6 << endl;
            return;
        }
    } else {
        if (curPlayer->getBalance() < o->getPrice()*0.5) {
            cout << "You can't afford to unmortgage " << o->getName() << "! It costs 50% of " 
                << o->getName() << "'s price to unmortgage it, which is $" << o->getPrice()*0.5 << endl;
            return;
        }
    }

    o->unmortgage(deal);

}


Location** Board::getLocationsArray() {
    return this->locations;
}

Display* Board::getDisplay() {
    return d;
}

Player* Board::getCurrentPlayer() {
    return curPlayer;
}

void Board::setCurrentPlayer(Player* p) {
    curPlayer = p;
}

void Board::assets() {
    cout << "Player: \t" << curPlayer->getName() << endl;
    cout << "Balance: \t" << curPlayer->getBalance() << endl;
    cout << "Gyms: \t\t" << curPlayer->gyms << endl;
    cout << "Residences: \t" << curPlayer->residences << endl;
    cout << "Owns: " << endl;
    for (int i = 0; i < curPlayer->numBuildings(); i++) {
        cout << "\t\t" << curPlayer->getBuildings()[i]->getName() << endl;
    }

}

void Board::all() {
    ostringstream pl;
    ostringstream bal;
    ostringstream gym;
    ostringstream res;
    ostringstream owns;

    pl << "Players: \t\t\t";
    bal << "Balance: \t\t\t";
    gym << "Gyms: \t\t\t\t";
    res << "Residences: \t\t\t";
    owns << "Owns: \t\t\t\t";

    for (auto i : players) {
        if (i->bankrupt) continue;
        pl << i->getName() << "\t";
        bal << i->getBalance() << "\t";
        gym << i->gyms << "\t";
        res << i->residences << "\t";
    }

    int i = 0;
    bool loop = true;
    while (loop) {
        for (auto j : players) {
            if (j->bankrupt) continue;
            owns << ((j->numBuildings() > i) ? j->getBuildings()[i]->getName() : "") << "\t";
        }
        owns << endl << "\t\t\t\t";

        loop = false;
        for (auto j : players) {
            if (j->bankrupt) continue;
            if (j->numBuildings() > i) loop = true;
        }

        i++;
    }
    
    cout << pl.str() << endl << bal.str() << endl << gym.str() << endl << res.str() << endl << owns.str() << endl;
}


Location* Board::findLocation(string name) {
    for (auto i : locations) {
        if (i->getName() == name) return i;
    }
    return nullptr;
}

Player* Board::findPlayer(string name) {
    for (auto i : players) {
        if (i->getName() == name) return i;
    }
    return nullptr;
}

void Board::bankrupt() {
    cout << string(50, '#') << endl;
    cout << curPlayer->getName() << " has gone BANKRUPT! They are OUT!" << endl;
    if (curPlayer->oweTo == nullptr) {
        cout << "As they owe money to the school, all their properties will now go up for auction!" << endl;
    } else {
        cout << "As they owe money to " << curPlayer->oweTo->getName() << ", all their assets will go to them!" << endl;
    }
    cout << string(50, '#') << endl;
    cout << "Press enter to continue." << endl;
    string s;
    getline(cin, s);
    cout << endl;

    //vector<Player* >::iterator cur = find(players.begin(), players.end(), curPlayer);
    //players.erase(cur);

    curPlayer->bankrupt = true;

    locations[curPlayer->getCurPos()]->removePlayer(curPlayer);


    if (curPlayer->oweTo == nullptr) {
        cups += curPlayer->getCups();
        vector<Ownable*> buildings = curPlayer->getBuildings();
        for (auto i : buildings) {
            i->setMortgaged(false);
            i->setOwner(nullptr);
            curPlayer->removeBuilding(i);
            auction(i);
        }
    } else {
        Player* oweTo = curPlayer->oweTo;

        oweTo->setCups(oweTo->getCups() + curPlayer->getCups());
        oweTo->setBalance(oweTo->getBalance() + curPlayer->getBalance());

        vector<Ownable*> buildings = curPlayer->getBuildings();
        for (auto i : buildings) {
            if (i->isMortgaged()) {
                if (oweTo->getBalance() < i->getPrice()*0.1) {
                    cout << oweTo->getName() << " cannot afford to pay the 10% upon receiving mortgaged property " << i->getName() << "." << endl
                        << i->getName() << " will therefore go out on the open market." << endl;
                    i->setOwner(nullptr);
                    curPlayer->removeBuilding(i);
                    i->setMortgaged(false);

                    continue;
                } else {
                    oweTo->setBalance(oweTo->getBalance() - i->getPrice()*0.1);
                    cout << oweTo->getName() << " paid $" << i->getPrice()*0.1 << ", as they received " << i->getName() << ", which was mortgaged." << endl;
                    cout << "Would you like to unmortgage the property for only 50% of its price? This comes out to $" << i->getPrice()*0.5 << endl;
                    cout << "1. Yes" << endl << "2. No" << endl;
                    string cmd;
                    while (getline(cin, cmd)) {
                        if (cmd == "all") {
                            all();
                        } else if (cmd != "1" && cmd != "2") {
                            cout << "Input must be 1 or 2!" << endl;
                        } else {
                            break;
                        }
                    }

                    if (cmd == "1") {
                        i->unmortgage(true);
                    }

                }
            }
            i->setOwner(oweTo);
            curPlayer->removeBuilding(i);
            oweTo->addBuilding(i);
            if (dynamic_cast<Residence*>(i)) {
                oweTo->residences++;
            }
            if (dynamic_cast<Gym*>(i)) {
                oweTo->gyms++;
            }
        }

    
    }
    
    //delete curPlayer;
}


void Board::auction(Ownable* o) {
    cout << string(50, '*') << endl;
    cout << "The auction for " << o->getName() << " will now begin!" << endl;
    int playersLeft = players.size();
    for (auto i : players) {
        i->inAuction = true;
        if (i->bankrupt) {
            i->inAuction = false;
            playersLeft -= 1;
        }
    }

    int bid = 0;
    

    while (true) {
        for (auto i : players) {
            if (i->inAuction) cout << string(50, '*') << endl;
            if (playersLeft == 1 && i->inAuction) {
                cout << i->getName() << " has won the auction!" << endl
                    << i->getName() << " will get " << o->getName() << " for $" 
                    << bid << "!" << endl;
                o->setOwner(i);
                i->addBuilding(o);
                i->setBalance(i->getBalance() - bid);
                return;
            }
            
            if (!i->inAuction) continue; 
            if (i->getBalance() < bid) {
                cout << i->getName() << ", you don't have enough money to raise the bid. You are out of the auction." << endl;
                i->inAuction = false;
                playersLeft -= 1;
                continue;
            }
            cout << "The current bid is " << bid << "." << endl;
            cout << i->getName() << ", you can either:" << endl
                << "a) Raise the bid by entering a new bid." << endl 
                << "b) Drop out by entering 0." << endl;

            string cmd;
            int newBid;
            Player* recent;
            while (getline(cin,cmd)) {
                istringstream iss{cmd};
                if (cmd == "all") {
                    all();
                } else if (!(iss>>newBid)) {
                    cout << "Input must be a number!" << endl;
                } else {
                    if (newBid <= bid && newBid != 0) {
                        cout << "The new bid must be greater than the previous bid!" << endl;
                    } else if (newBid > bid && i->getBalance() < newBid) {
                        cout << "You don't have enough money to bid that much." << endl;
                    } else {
                        break;
                    }
                }
            }
            


            if (newBid == 0) {
                cout << i->getName() << " has dropped out of the auction." << endl;
                i->inAuction = false;
                playersLeft -= 1;
                continue;
            } else {
                recent = i;
                bid = newBid;

            }

        }
    }
}

void Board::trade(Player* p, Ownable* o1, Ownable* o2) {
    if (o1->getOwner() != curPlayer) {
        cout << curPlayer->getName() << " doesn't own " << o1->getName() << "!" << endl;
        return;
    } else if (o2->getOwner() != p) {
        cout << p->getName() << " doesn't own " << o2->getName() << "!" << endl;
        return;
    }

    AcademicBuilding* ac1 = dynamic_cast<AcademicBuilding*>(o1);
    AcademicBuilding* ac2 = dynamic_cast<AcademicBuilding*>(o2);

    if (ac1) {
        for (auto i : monopolies[ac1->getMonopoly()]) {
            if (dynamic_cast<AcademicBuilding*>(locations[i])->getImprovements() > 0) {
                cout << locations[i]->getName() << ", a building in the monopoly of " 
                    << ac1->getName() << ", has improvements, and thus the trade has been cancelled." << endl;
                return; 
            }
        }
    }

    if (ac2) {
        for (auto i : monopolies[ac2->getMonopoly()]) {
            if (dynamic_cast<AcademicBuilding*>(locations[i])->getImprovements() > 0) {
                cout << locations[i]->getName() << ", a building in the monopoly of " 
                    << ac2->getName() << ", has improvements, and thus the trade has been cancelled." << endl;
                return; 
            }
        }
    }


    cout << curPlayer->getName() << " would like to trade " << o1->getName() << " for " 
        << o2->getName() << "!" << endl << p->getName() << ", what say ye?" << endl;
    cout << "1. Accept" << endl << "2. Refuse" << endl;

    string cmd;
    while (getline(cin, cmd)) {
        if (cmd == "all") {
            all();
        } else if (cmd != "1" && cmd != "2") {
            cout << "Input must be 1 or 2." << endl;
        } else {
            break;
        }
    }

    if (cmd == "1") {
        o1->setOwner(p);
        o2->setOwner(curPlayer);
        p->addBuilding(o1);
        curPlayer->removeBuilding(o1);
        curPlayer->addBuilding(o2);
        p->removeBuilding(o2);
        cout << curPlayer->getName() << " gave " << p->getName() << " " << o1->getName() << "!" << endl;
        cout << p->getName() << " gave " << curPlayer->getName() << " " << o2->getName() << "!" << endl;


    } else if (cmd == "2") {
        cout << "The trade was rejected." << endl;
    }



}
void Board::trade(Player *p, int money, Ownable* o) {
    if (o->getOwner() != p) {
        cout << p->getName() << " doesn't own " << o->getName() << "!" << endl;
        return;
    }

    if (curPlayer->getBalance() < money) {
        cout << curPlayer->getName() << " doesn't have enough money for this trade." << endl;
        return;
    }

    AcademicBuilding* ac = dynamic_cast<AcademicBuilding*>(o);

    if (ac) {
        for (auto i : monopolies[ac->getMonopoly()]) {
            if (dynamic_cast<AcademicBuilding*>(locations[i])->getImprovements() > 0) {
                cout << locations[i]->getName() << ", a building in the monopoly of " 
                    << ac->getName() << ", has improvements, and thus the trade has been cancelled." << endl;
                return; 
            }
        }
    }

    cout << curPlayer->getName() << " would like to trade $" << money << " for " 
        << o->getName() << "!" << endl << p->getName() << ", what say ye?" << endl;
    cout << "1. Accept" << endl << "2. Refuse" << endl;

    string cmd;
    while (getline(cin, cmd)) {
        if (cmd == "all") {
            all();
        } else if (cmd != "1" && cmd != "2") {
            cout << "Input must be 1 or 2." << endl;
        } else {
            break;
        }
    }

    if (cmd == "1") {
        
        o->setOwner(curPlayer);
        curPlayer->addBuilding(o);
        p->removeBuilding(o);

        curPlayer->setBalance(curPlayer->getBalance() - money);
        p->setBalance(p->getBalance() + money);

        cout << curPlayer->getName() << " gave " << p->getName() << " $" << money << "!" << endl;
        cout << p->getName() << " gave " << curPlayer->getName() << " " << o->getName() << "!" << endl;



    } else if (cmd == "2") {
        cout << "The trade was rejected." << endl;
    }
}

void Board::trade(Player *p, Ownable* o, int money) {
    if (o->getOwner() != curPlayer) {
        cout << curPlayer->getName() << " doesn't own " << o->getName() << "!" << endl;
        return;
    }

    if (p->getBalance() < money) {
        cout << p->getName() << " doesn't have enough money for this trade." << endl;
        return;
    }

    AcademicBuilding* ac = dynamic_cast<AcademicBuilding*>(o);

    if (ac) {
        for (auto i : monopolies[ac->getMonopoly()]) {
            if (dynamic_cast<AcademicBuilding*>(locations[i])->getImprovements() > 0) {
                cout << locations[i]->getName() << ", a building in the monopoly of " 
                    << ac->getName() << ", has improvements, and thus the trade has been cancelled." << endl;
                return; 
            }
        }
    }

    cout << curPlayer->getName() << " would like to trade " << o->getName() << " for $" 
        << money << "!" << endl << p->getName() << ", what say ye?" << endl;
    cout << "1. Accept" << endl << "2. Refuse" << endl;

    string cmd;
    while (getline(cin, cmd)) {
        if (cmd == "all") {
            all();
        } else if (cmd != "1" && cmd != "2") {
            cout << "Input must be 1 or 2." << endl;
        } else {
            break;
        }
    }

    if (cmd == "1") {
        
        o->setOwner(p);
        p->addBuilding(o);
        curPlayer->removeBuilding(o);

        p->setBalance(p->getBalance() - money);
        curPlayer->setBalance(curPlayer->getBalance() + money);

        cout << curPlayer->getName() << " gave " << p->getName() << " " << o->getName() << "!" << endl;
        cout << p->getName() << " gave " << curPlayer->getName() << " $" << money << "!" << endl;
        


    } else if (cmd == "2") {
        cout << "The trade was rejected." << endl;
    }
}

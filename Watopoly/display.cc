#include <iostream>
#include <string>
#include "display.h"
#include "board.h"
#include "academicbuilding.h"
//#include "location.h"



using namespace std;

Display::Display(Board* b): b{b} {}

void Display::render() {
    char board[67][100];
    for (int i = 0; i < 67; i++){
        for(int j = 0; j < 100; j++){
            board[i][j] = ' ';
        }
    }
    for (int i = 0; i < 100; i++){
        board[0][i] = '_';
    }
    for (int i = 0; i < 100; i++){
        board[66][i] = '_';
    }
    for (int i = 0; i < 100; i++){
        board[6][i] = '_';
    }
    for (int i = 0; i < 100; i++){
        board[60][i] = '_';
    }

    for (int i = 1; i < 67; i++){
        board[i][0] = '|';
    }
    for (int i = 1; i < 67; i++){
        board[i][9] = '|';
    }
    for (int i = 1; i < 67; i++){
        board[i][99] = '|';
    }
    for (int i = 1; i < 67; i++){
        board[i][90] = '|';
    }
    for (int i = 1; i < 7; i++){
        for (int j = 18; j < 90; j=j+9){
            board[i][j] = '|';
        }
    }
    for (int i = 61; i < 67; i++){
        for (int j = 18; j < 90; j=j+9){
            board[i][j] = '|';
        }
    }
    for (int i = 12; i < 60; i=i+6){
        for (int j = 1; j < 9; j++){
            board[i][j] = '_';
        }
    }
    for (int i = 12; i < 60; i=i+6){
        for (int j = 91; j < 99; j++){
            board[i][j] = '_';
        }
    }

    Location** locations = b->getLocationsArray();

    for (int i = 0; i < 40; i++) {
        if (i < 11){
            if (locations[i]->isAcademic() == true){
                AcademicBuilding* cur = static_cast<AcademicBuilding*> (locations[i]);
                int improvements = cur->getImprovements();
                for (int j = 0; j < improvements; j++){
                    board[1][(i*9) + j + 1] = 'I';
                }
                for (int j = 0; j < 8; j++){
                    board[2][(i*9) + j + 1] = '-';
                }
                string name = locations[i]->getName();
                for (int j = 0; j < name.length(); j++){
                    if (name[j] == ' '){
                        j++;
                        int x = 0;
                       while (j < name.length()){
                        board[4][(i*9) + x + 1] = name[j];
                        x++;
                        j++;
                       }
                       break;
                    }
                    board[3][(i*9) + j + 1] = name[j];
                }
                for (int j = 0; j < locations[i]->playersHere.size(); j++) {
                    board[5][(i*9) + j + 1] = locations[i]->playersHere[j]->getChar();
                }
            }
            else {
                string name = locations[i]->getName();
                for (int j = 0; j < name.length(); j++){
                    if (name[j] == ' '){
                        j++;
                        int x = 0;
                       while (j < name.length()){
                        board[2][(i*9) + x + 1] = name[j];
                        x++;
                        j++;
                       }
                       break;
                    }
                    board[1][(i*9) + j + 1] = name[j];
                }
                for (int j = 0; j < locations[i]->playersHere.size(); j++) {
                    board[3][(i*9) + j + 1] = locations[i]->playersHere[j]->getChar();
                }
            }
                
        }
        else if (i < 21){
            if (locations[i]->isAcademic() == true){
                AcademicBuilding* cur = static_cast<AcademicBuilding*> (locations[i]);
                int improvements = cur->getImprovements();
                for (int j = 0; j < improvements; j++){
                    board[(i-10)*6 + 1][91 + j] = 'I';
                }
                for (int j = 0; j < 8; j++){
                    board[(i-10)*6 + 2][91 + j] = '-';
                }
                string name = locations[i]->getName();
                for (int j = 0; j < name.length(); j++){
                    if (name[j] == ' '){
                        j++;
                        int x = 0;
                       while (j < name.length()){
                        board[(i-10)*6 + 4][91 + x] = name[j];
                        x++;
                        j++;
                       }
                       break;
                    }
                    board[(i-10)*6 + 3][91 + j] = name[j];
                }
                for (int j = 0; j < locations[i]->playersHere.size(); j++) {
                    board[(i-10)*6 + 5][91 + j] = locations[i]->playersHere[j]->getChar();
                }
            }
            else {
                string name = locations[i]->getName();
                for (int j = 0; j < name.length(); j++){
                    if (name[j] == ' '){
                        j++;
                        int x = 0;
                       while (j < name.length()){
                        board[(i-10)*6 + 2][91 + x] = name[j];
                        x++;
                        j++;
                       }
                       break;
                    }
                    board[(i-10)*6 + 1][91 + j] = name[j];
                }
                for (int j = 0; j < locations[i]->playersHere.size(); j++) {
                    board[(i-10)*6 + 3][91 + j] = locations[i]->playersHere[j]->getChar();
                }
            }
                
        }
        else if (i < 31){
            if (locations[i]->isAcademic() == true){
                AcademicBuilding* cur = static_cast<AcademicBuilding*> (locations[i]);
                int improvements = cur->getImprovements();
                for (int j = 0; j < improvements; j++){
                    board[61][91 - (i - 20)* 9 + j] = 'I';
                }
                for (int j = 0; j < 8; j++){
                    board[62][91 - (i - 20)* 9 + j] = '-';
                }
                string name = locations[i]->getName();
                for (int j = 0; j < name.length(); j++){
                    if (name[j] == ' '){
                        j++;
                        int x= 0;
                       while (j < name.length()){
                        board[64][91 - (i - 20)* 9 + x] = name[j];
                        j++;
                        x++;
                       }
                       break;
                    }
                    board[63][91 - (i - 20)* 9 + j] = name[j];
                }
                for (int j = 0; j < locations[i]->playersHere.size(); j++) {
                    board[65][91 - (i - 20)* 9 + j] = locations[i]->playersHere[j]->getChar();
                }
            }
            else {
                string name = locations[i]->getName();
                int x = 0;
                for (int j = 0; j < name.length(); j++){
                    if (name[0] == 'D'){
                        while (j < 7){
                            board[61][91 - (i - 20)* 9 + j] = name[j];
                            j++;
                        }
                        if (j == 7){
                            j++;
                            continue;
                        }
                        board[62][91 - (i - 20)* 9 + x] = name[j];
                        x++;
                        continue;

                    }
                    if (name[j] == ' '){
                        j++;
                        int x =0;
                       while (j < name.length()){
                        board[62][91 - (i - 20)* 9 + x] = name[j];
                        j++;
                        x++;
                       }
                       break;
                    }
                    board[61][91 - (i - 20)* 9 + j] = name[j];
                }
                for (int j = 0; j < locations[i]->playersHere.size(); j++) {
                    board[63][91 - (i - 20)* 9 + j] = locations[i]->playersHere[j]->getChar();
                }
            }
                
        }
        else if (i < 40){
            if (locations[i]->isAcademic() == true){
                AcademicBuilding* cur = static_cast<AcademicBuilding*> (locations[i]);
                int improvements = cur->getImprovements();
                for (int j = 0; j < improvements; j++){
                    board[61 - (i-30)*6][1 + j] = 'I';
                }
                for (int j = 0; j < 8; j++){
                    board[62 - (i-30)*6][1 + j] = '-';
                }
                string name = locations[i]->getName();
                for (int j = 0; j < name.length(); j++){
                    if (name[j] == ' '){
                        j++;
                        int x = 0;
                       while (j < name.length()){
                        board[64 - (i-30)*6][1 + x] = name[j];
                        j++;
                        x++;
                       }
                       break;
                    }
                    board[63 - (i-30)*6][1 + j] = name[j];
                }
                for (int j = 0; j < locations[i]->playersHere.size(); j++) {
                    board[65 - (i-30)*6][1 + j] = locations[i]->playersHere[j]->getChar();
                }
            }
            else {
                string name = locations[i]->getName();
                for (int j = 0; j < name.length(); j++){
                    if (name[j] == ' '){
                        j++;
                        int x = 0;
                       while (j < name.length()){
                        board[62 - (i-30)*6][1 + x] = name[j];
                        j++;
                        x++;
                       }
                       break;
                    }
                    board[61 - (i-30)*6][1 + j] = name[j];
                }
                for (int j = 0; j < locations[i]->playersHere.size(); j++) {
                    board[63 - (i-30)*6][1 + j] = locations[i]->playersHere[j]->getChar();
                }
            }
                
        }
        
    }
    for (int i = 0; i < 67; i++){
        for(int j = 0; j < 100; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
}









    


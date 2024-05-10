#include <iostream>
#include "academicbuilding.h"
#include "board.h"

using namespace std;

AcademicBuilding::AcademicBuilding(string name, Board* b, int price, bool mortgage, int impCost, 
                                    int t1, int t2, int t3, int t4, int t5, int t6, int monopoly):
                                    Ownable(name, b, price, mortgage), impCost{impCost}, improvements{0},
                                    monopoly{monopoly} {
    tuition[0] = t1;
    tuition[1] = t2;
    tuition[2] = t3;
    tuition[3] = t4;
    tuition[4] = t5;
    tuition[5] = t6;
                                    }





int AcademicBuilding::getTuition(Player* p) {
    return this->tuition[improvements];
}

void AcademicBuilding::handlePurchase(Player* p) {}


bool AcademicBuilding::isAcademic() { return true;}

int AcademicBuilding::getImprovements() {return improvements;}
void AcademicBuilding::setImprovements(int n) { improvements = n; }
int AcademicBuilding::getImpCost() {return impCost;}
int AcademicBuilding::getWorth() {
    return getPrice() + getImprovements() * getImpCost();
}
int AcademicBuilding::getMonopoly() { return monopoly; }

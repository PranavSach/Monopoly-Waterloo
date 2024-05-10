#ifndef __ACADEMICBUILDING_H__
#define __ACADEMICBUILDING_H__
#include <vector>
#include <string>
#include "ownable.h"

class AcademicBuilding : public Ownable {
    int improvements;
    int tuition[6] = {0};
    int impCost;
    int monopoly;

public:
    AcademicBuilding(std::string name, Board* b, int price, bool mortgage, int impCost, 
                        int t1, int t2, int t3, int t4, int t5, int t6, int monopoly);
    int getTuition(Player* p) override;
    void handlePurchase(Player* p) override;
    bool isAcademic() override ;
    int getImprovements();
    void setImprovements(int n);
    int getImpCost();
    int getWorth() override;
    int getMonopoly();


};

#endif

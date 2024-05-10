#ifndef __RESIDENCE_H__
#define __RESIDENCE_H__
#include <vector>
#include <string>
#include "ownable.h"


class Residence : public Ownable {
public:
    Residence(std::string name, Board* b, int price, bool mortgage);
    int getTuition(Player* p) override;
    void handlePurchase(Player* p);
    bool isAcademic() override ;  
    int getWorth() override;
};

#endif

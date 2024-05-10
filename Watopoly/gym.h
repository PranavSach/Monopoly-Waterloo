#ifndef __GYM_H__
#define __GYM_H__
#include <vector>
#include <string>
#include "ownable.h"


class Gym : public Ownable {
public:
    Gym(std::string name, Board* b, int price, bool mortgage);
    int getTuition(Player* p) override;
    void handlePurchase(Player* p) override;
    bool isAcademic() override ;
    int getWorth() override;
};

#endif

#ifndef __OWNABLE_H__
#define __OWNABLE_H__
#include <vector>
#include <string>
#include "location.h"


class Ownable : public Location {
    int price;
    bool mortgaged;
    Player* owner;
public:
    Ownable(std::string name, Board* b, int price, bool mortgaged);
    virtual int getTuition(Player* p) = 0;
    void handleEvent(Player* p) override;
    virtual bool isAcademic() = 0;
    int getPrice();
    Player* getOwner();
    void setOwner(Player* player);
    bool isMortgaged();
    void setMortgaged(bool mortgaged);
    void mortgage();
    void mortgageLoad();
    void unmortgage(bool deal = false);
    virtual void handlePurchase(Player* p) = 0;
    virtual int getWorth() = 0;

    //virtual void handleEvent(Player* p) = 0;


};

#endif

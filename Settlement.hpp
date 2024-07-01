#ifndef SETTLEMENT_H
#define SETTLEMENT_H

//roibr23@gmail.com 322695883

#include <cstddef> 

class Player; 

class Settlement {
public:
    Settlement(Player* owner = nullptr);
    Player* getOwner() const;
    void setOwner(Player* owner);

private:
    Player* owner;
};

#endif // SETTLEMENT_H

#ifndef ROAD_H
#define ROAD_H

//roibr23@gmail.com 322695883

#include <cstddef> 

class Player; 

class Road {
public:
    Road(Player* owner = nullptr);
    Player* getOwner() const;
    void setOwner(Player* owner);

private:
    Player* owner;
};

#endif // ROAD_H

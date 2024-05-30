#ifndef VICTORYPOINTCARD_H
#define VICTORYPOINTCARD_H

#include "Card.hpp"
#include <iostream>

//roibr23@gmail.com 322695883

class VictoryPointCard : public Card {
public:
    void play() override {
        std::cout << "Victory point card played: Gain a victory point." << std::endl;
    }
};

#endif // VICTORYPOINTCARD_H

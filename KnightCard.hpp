#ifndef KNIGHTCARD_H
#define KNIGHTCARD_H

#include "Card.hpp"
#include <iostream>

//roibr23@gmail.com 322695883

class KnightCard : public Card {
public:
    void play() override {
        std::cout << "Knight card" << std::endl;
    }
};

#endif // KNIGHTCARD_H

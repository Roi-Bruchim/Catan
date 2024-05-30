#include "Settlement.hpp"
#include "Player.hpp"

//roibr23@gmail.com 322695883

Settlement::Settlement(Player* owner) : owner(owner) {}

Player* Settlement::getOwner() const {
    return owner;
}

void Settlement::setOwner(Player* owner) {
    this->owner = owner;
}

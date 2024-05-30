#include "Road.hpp"
#include "Player.hpp"

//roibr23@gmail.com 322695883

Road::Road(Player* owner) : owner(owner) {}

Player* Road::getOwner() const {
    return owner;
}

void Road::setOwner(Player* owner) {
    this->owner = owner;
}

#include "Tile.hpp"
#include <iostream>

//roibr23@gmail.com 322695883

Tile::Tile() : resource(""), number(0), roads(6, nullptr), settlements(6, nullptr) {
}

Tile::Tile(const std::string& resource, int number) : resource(resource), number(number), roads(6, nullptr), settlements(6, nullptr) {
    std::cout << "Tile created with resource " << resource << " and number " << number << std::endl;
}

std::string Tile::getResource() const {
    return resource;
}

int Tile::getNumber() const {
    return number;
}

std::vector<Road*>& Tile::getRoads() {
    return roads;
}

std::vector<Settlement*>& Tile::getSettlements() {
    return settlements;
}

const std::vector<Road*>& Tile::getRoads() const {
    return roads;
}

const std::vector<Settlement*>& Tile::getSettlements() const {
    return settlements;
}

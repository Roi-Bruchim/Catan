#include "Board.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

//roibr23@gmail.com 322695883

Board::Board() {
    setupBoard();
}

void Board::setupBoard() {
    initializeTiles();
    initializeRoads();
    initializeSettlements();
}

void Board::initializeTiles() {
    std::vector<std::string> resources = {"wood", "brick", "grain", "ore", "wool"};
    std::vector<int> numbers = {2, 3, 3, 4, 4, 5, 5, 6, 6, 8, 8, 9, 9, 10, 10, 11, 11, 12};

    std::srand(std::time(nullptr));

    tiles["Forest"] = Tile("wood", 5);
    tiles["Hills"] = Tile("brick", 6);
    tiles["Agricultural Land"] = Tile("grain", 3);
    tiles["Desert"] = Tile("grain", 4);
    tiles["Mountains"] = Tile("ore", 9);
    tiles["Pasture Land"] = Tile("wool", 8);

    for (const auto& tile : tiles) {
        std::cout << "Initialized tile: " << tile.first << " with resource " << tile.second.getResource() << " and number " << tile.second.getNumber() << std::endl;
    }
}

void Board::initializeRoads() {
    for (auto& tilePair : tiles) {
        Tile& tile = tilePair.second;
        for (int i = 0; i < 6; ++i) {
            if (tile.getRoads()[i] == nullptr) {
                tile.getRoads()[i] = new Road();
            }
        }
        std::cout << "Initialized roads for tile: " << tilePair.first << std::endl;
    }
}

void Board::initializeSettlements() {
    for (auto& tilePair : tiles) {
        Tile& tile = tilePair.second;
        for (int i = 0; i < 6; ++i) {
            if (tile.getSettlements()[i] == nullptr) {
                tile.getSettlements()[i] = new Settlement();
            }
        }
        std::cout << "Initialized settlements for tile: " << tilePair.first << std::endl;
    }
}

void Board::printBoard() const {
    for (const auto& tilePair : tiles) {
        const Tile& tile = tilePair.second;
        std::cout << tile.getResource() << "(" << tile.getNumber() << ") ";
    }
    std::cout << std::endl;
}

void Board::placeSettlement(const std::string& hex, int position, Player& player) {
    std::cout << "Attempting to place settlement for player " << player.getName() << " at " << hex << " position " << position << std::endl;

    if (position < 0 || position >= 6) {
        std::cout << "Invalid settlement position: " << position << std::endl;
        throw std::invalid_argument("Settlement position out of bounds");
    }

    if (isSettlementPlaceable(hex, position)) {
        Settlement* settlement = tiles[hex].getSettlements()[position];
        if (settlement == nullptr) {
            std::cout << "Error: Settlement pointer at position " << position << " is null." << std::endl;
            throw std::runtime_error("Null settlement pointer");
        }
        settlement->setOwner(&player);
        std::cout << "Placed settlement for player " << player.getName() << " at " << hex << " position " << position << std::endl;
    } else {
        std::cout << "Settlement cannot be placed at " << hex << " position " << position << std::endl;
        throw std::invalid_argument("Settlement cannot be placed here.");
    }
}

void Board::placeRoad(const std::string& hex, int position, Player& player) {
    std::cout << "Attempting to place road for player " << player.getName() << " at " << hex << " position " << position << std::endl;

    if (position < 0 || position >= 6) {
        std::cout << "Invalid road position: " << position << std::endl;
        throw std::invalid_argument("Road position out of bounds");
    }

    Road* road = tiles[hex].getRoads()[position];
    if (road == nullptr) {
        std::cout << "Error: Road pointer at position " << position << " is null." << std::endl;
        throw std::runtime_error("Null road pointer");
    }
    if (road->getOwner() != nullptr) {
        std::cout << "Road already exists at " << hex << " position " << position << std::endl;
        return;  // Do not throw, just return to avoid crashing the program
    }
    road->setOwner(&player);
    std::cout << "Placed road for player " << player.getName() << " at " << hex << " position " << position << std::endl;
}

bool Board::isRoadPlaceable(const std::string& hex, int position) const {
    return tiles.at(hex).getRoads()[position]->getOwner() == nullptr;
}




void Board::distributeResources(int roll, Player& currentPlayer) {
    for (auto& tilePair : tiles) {
        Tile& tile = tilePair.second;
        if (tile.getNumber() == roll) {
            for (Settlement* settlement : tile.getSettlements()) {
                if (settlement->getOwner() != nullptr) {
                    settlement->getOwner()->addResource(tile.getResource(), 1);
                }
            }
        }
    }
}

bool Board::isSettlementPlaceable(const std::string& hex, int position) const {
    return tiles.at(hex).getSettlements()[position]->getOwner() == nullptr;
}


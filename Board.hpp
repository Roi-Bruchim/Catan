#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <map>
#include "Tile.hpp"
#include "Player.hpp"

//roibr23@gmail.com 322695883

class Board {
public:
    Board();
    void setupBoard();
    void printBoard() const;
    void placeSettlement(const std::string& hex, int position, Player& player);
    void placeRoad(const std::string& hex, int position, Player& player);
    void distributeResources(int roll, Player& currentPlayer);
    bool isSettlementPlaceable(const std::string& hex, int position) const;
    bool isRoadPlaceable(const std::string& hex, int position) const;

private:
    std::map<std::string, Tile> tiles;
    void initializeTiles();
    void initializeRoads();
    void initializeSettlements();
};

#endif // BOARD_H

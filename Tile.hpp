#ifndef TILE_H
#define TILE_H

#include <string>
#include <vector>
#include "Road.hpp"
#include "Settlement.hpp"

//roibr23@gmail.com 322695883

class Tile {
public:
    Tile();
    Tile(const std::string& resource, int number);
    std::string getResource() const;
    int getNumber() const;
    std::vector<Road*>& getRoads();
    std::vector<Settlement*>& getSettlements();
    const std::vector<Road*>& getRoads() const;
    const std::vector<Settlement*>& getSettlements() const;

private:
    std::string resource;
    int number;
    std::vector<Road*> roads;        // List of roads around the tile
    std::vector<Settlement*> settlements; // List of settlements around the tile
};

#endif // TILE_H

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "Card.hpp"
#include "Board.hpp"

//roibr23@gmail.com 322695883

class Board; 

class Player {
public:
    Player(const std::string& name);
    void placeSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
    void placeRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
    void rollDice(Board& board);
    void endTurn();
    void trade(Player& other, const std::string& giveResource, const std::string& receiveResource, int giveAmount, int receiveAmount);
    void buyDevelopmentCard();
    void useCard(int index);
    void printPoints() const;
    void printResources() const;
    void addResource(const std::string& resource, int amount);
    void removeResource(const std::string& resource, int amount);
    std::string getName() const;
    int getPoints() const;
    const std::map<std::string, int>& getResources() const;
    void setPoints(int pts);

private:
    std::string name;
    int points;
    std::map<std::string, int> resources;
    std::vector<std::shared_ptr<Card>> cards;
    static int turnCounter;
};

#endif // PLAYER_H

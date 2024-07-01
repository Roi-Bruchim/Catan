#include "Player.hpp"
#include "KnightCard.hpp"
#include "VictoryPointCard.hpp"
#include <iostream>
#include <cstdlib>

//roibr23@gmail.com 322695883

int Player::turnCounter = 0;

Player::Player(const std::string& name) : name(name), points(2) {
    resources = {{"wood", 0}, {"brick", 0}, {"grain", 0}, {"ore", 0}, {"wool", 0}};
    std::cout << "Player " << name << " created with 2 points." << std::endl;
}

void Player::placeSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board) {
    for (size_t i = 0; i < places.size(); ++i) {
        std::cout << "Placing settlement at " << places[i] << " with number " << placesNum[i] << std::endl;
        board.placeSettlement(places[i], placesNum[i], *this);
    }
    points += 1; // Each settlement gives 1 point
    std::cout << "Settlement placed. Current points: " << points << std::endl;
}

void Player::placeRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board) {
    for (size_t i = 0; i < places.size(); ++i) {
        std::cout << "Placing road at " << places[i] << " with number " << placesNum[i] << std::endl;
        board.placeRoad(places[i], placesNum[i], *this);
    }
    std::cout << "Road placed." << std::endl;
}

void Player::rollDice(Board& board) {
    int roll = (std::rand() % 6 + 1) + (std::rand() % 6 + 1);
    std::cout << name << " rolled a " << roll << std::endl;
    board.distributeResources(roll, *this);
}

void Player::endTurn() {
    ++turnCounter;
    std::cout << name << " ends turn." << std::endl;
}

void Player::trade(Player& other, const std::string& giveResource, const std::string& receiveResource, int giveAmount, int receiveAmount) {
    if (resources[giveResource] >= giveAmount && other.resources[receiveResource] >= receiveAmount) {
        resources[giveResource] -= giveAmount;
        resources[receiveResource] += receiveAmount;
        other.resources[receiveResource] -= receiveAmount;
        other.resources[giveResource] += giveAmount;
        std::cout << name << " traded " << giveAmount << " " << giveResource << " for " << receiveAmount << " " << receiveResource << " with " << other.getName() << std::endl;
    } else {
        throw std::invalid_argument("Trade not possible due to insufficient resources.");
    }
}

void Player::buyDevelopmentCard() {
    int cardType = std::rand() % 2; // 0 for Knight, 1 for Victory Point
    if (cardType == 0) {
        cards.push_back(std::make_shared<KnightCard>());
    } else {
        cards.push_back(std::make_shared<VictoryPointCard>());
        points += 1; // Victory Point card gives 1 point
    }
    std::cout << name << " bought a development card." << std::endl;
}

void Player::useCard(int index) {
    if (index >= 0 && index < cards.size()) {
        cards[index]->play();
        cards.erase(cards.begin() + index);
    } else {
        std::cout << "Invalid card index." << std::endl;
    }
}

void Player::printPoints() const {
    std::cout << name << " has " << points << " points." << std::endl;
}

void Player::printResources() const {
    std::cout << name << " has the following resources:" << std::endl;
    for (const auto& resource : resources) {
        std::cout << resource.first << ": " << resource.second << std::endl;
    }
}

void Player::addResource(const std::string& resource, int amount) {
    resources[resource] += amount;
}

void Player::removeResource(const std::string& resource, int amount) {
    if (resources[resource] >= amount) {
        resources[resource] -= amount;
    } else {
        throw std::invalid_argument("Not enough " + resource + " to remove.");
    }
}

std::string Player::getName() const {
    return name;
}

int Player::getPoints() const {
    return points;
}

const std::map<std::string, int>& Player::getResources() const {
    return resources;
}

void Player::setPoints(int pts) {
    points = pts;
}

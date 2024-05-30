#include "Catan.hpp"
#include <iostream>

//roibr23@gmail.com 322695883

Catan::Catan(Player& p1, Player& p2, Player& p3) : players{&p1, &p2, &p3}, board(), currentTurn(0) {
    currentPlayer = players[0];
}

void Catan::ChooseStartingPlayer() {
    std::cout << currentPlayer->getName() << " is the starting player." << std::endl;
}

Board& Catan::getBoard() {
    return board;
}

void Catan::printWinner() {
    Player* winner = nullptr;
    for (auto* player : players) {
        if (player->getPoints() >= 10) {
            winner = player;
            break;
        }
    }
    if (winner) {
        std::cout << "The winner is " << winner->getName() << "!" << std::endl;
    } else {
        std::cout << "No winner yet." << std::endl;
    }
}

Player& Catan::getCurrentPlayer() {
    return *currentPlayer;
}

void Catan::nextTurn() {
    currentTurn = (currentTurn + 1) % players.size();
    currentPlayer = players[currentTurn];
    std::cout << "It's now " << currentPlayer->getName() << "'s turn." << std::endl;
}

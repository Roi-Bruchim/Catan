#ifndef CATAN_HPP
#define CATAN_HPP

//roibr23@gmail.com 322695883

#include "Player.hpp"
#include "Board.hpp"
#include <vector>

class Catan {
public:
    Catan(Player& p1, Player& p2, Player& p3);
    void ChooseStartingPlayer();
    Board& getBoard();
    void printWinner();
    Player& getCurrentPlayer();
    void nextTurn();

private:
    std::vector<Player*> players;
    Board board;
    Player* currentPlayer;
    int currentTurn;
};

#endif // CATAN_HPP

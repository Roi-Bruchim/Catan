#include <iostream>
#include <stdexcept>
#include <vector>
#include "Catan.hpp"
#include "Player.hpp"
#include "Board.hpp"

using namespace std;

//roibr23@gmail.com 322695883

int main() {
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    Catan catan(p1, p2, p3);
    catan.ChooseStartingPlayer();
    Board& board = catan.getBoard();

    vector<string> places = {"Forest", "Hills"};
    vector<int> placesNum = {1, 2}; // Ensure positions are within range 0-5
    p1.placeSettlement(places, placesNum, board);
    p1.placeRoad(places, placesNum, board);

    places = {"Agricultural Land", "Desert"};
    placesNum = {3, 4};
    p1.placeSettlement(places, placesNum, board);
    p1.placeRoad(places, placesNum, board);

    places = {"Mountains", "Pasture Land"};
    placesNum = {1, 2};
    p2.placeSettlement(places, placesNum, board);
    p2.placeRoad(places, placesNum, board);

    try {
        p3.placeSettlement(places, placesNum, board);
    } catch (const std::exception &e) {
        cout << e.what() << endl;
    }

    places = {"Forest", "Pasture Land"};
    placesNum = {3, 4};
    p2.placeSettlement(places, placesNum, board);
    p2.placeRoad(places, placesNum, board);

    places = {"Mountains", "Pasture Land"};
    placesNum = {0, 1};
    p3.placeSettlement(places, placesNum, board);
    p3.placeRoad(places, placesNum, board);

    places = {"Agricultural Land", "Pasture Land"};
    placesNum = {2, 3};
    p3.placeSettlement(places, placesNum, board);
    p3.placeRoad(places, placesNum, board);

    p1.rollDice(board);  // Changed to pass the board reference
    try {
        p1.placeRoad({"Forest", "Hills"}, {1, 3}, board);  // Ensure unique positions
    } catch (const std::exception &e) {
        cout << e.what() << endl;
    }
    p1.endTurn();

    p2.rollDice(board);  // Changed to pass the board reference
    p2.endTurn();

    p3.rollDice(board);  // Changed to pass the board reference
    p3.endTurn();

    try {
        p2.rollDice(board);  // Changed to pass the board reference
    } catch (const std::exception &e) {
        cout << e.what() << endl;
    }

    p1.rollDice(board);  // Changed to pass the board reference
    try {
        p1.trade(p2, "wood", "brick", 1, 1);
    } catch (const std::exception &e) {
        cout << e.what() << endl;
    }
    p1.endTurn();

    p2.rollDice(board);  // Changed to pass the board reference
    try {
        p2.buyDevelopmentCard();
    } catch (const std::exception &e) {
        cout << e.what() << endl;
    }
    p2.endTurn();

    p1.printPoints();
    p2.printPoints();
    p3.printPoints();

    p1.printResources();
    p2.printResources();
    p3.printResources();

    catan.printWinner();

    return 0;
}

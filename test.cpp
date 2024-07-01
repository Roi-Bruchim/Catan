#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Player.hpp"
#include "Board.hpp"
#include "KnightCard.hpp"
#include "VictoryPointCard.hpp"
#include "Catan.hpp"

TEST_CASE("Player creation and resource management") {
    Player p("TestPlayer");
    CHECK(p.getName() == "TestPlayer");
    CHECK(p.getPoints() == 2);

    p.addResource("wood", 3);
    p.addResource("brick", 2);
    CHECK(p.getPoints() == 2);
    CHECK_NOTHROW(p.removeResource("wood", 2));
    CHECK_THROWS(p.removeResource("brick", 3)); // Should throw because only 2 bricks are available
}

TEST_CASE("Settlement placement") {
    Board board;
    Player p("TestPlayer");

    std::vector<std::string> places = {"Forest", "Hills"};
    std::vector<int> placesNum = {1, 2};
    CHECK_NOTHROW(p.placeSettlement(places, placesNum, board));
    CHECK(p.getPoints() == 3);
}

TEST_CASE("Road placement") {
    Board board;
    Player p("TestPlayer");

    std::vector<std::string> places = {"Forest", "Hills"};
    std::vector<int> placesNum = {1, 2};
    p.placeSettlement(places, placesNum, board); // Need to place settlement first
    CHECK_NOTHROW(p.placeRoad(places, placesNum, board));
}

TEST_CASE("Development card purchase and usage") {
    Player p("TestPlayer");

    CHECK_NOTHROW(p.buyDevelopmentCard());
    CHECK(p.getPoints() >= 2); // Could be 2 or 3 depending on the card
    p.useCard(0);
    CHECK(p.getPoints() >= 2);
}

TEST_CASE("Resource trading between players") {
    Player p1("Player1");
    Player p2("Player2");

    p1.addResource("wood", 3);
    p2.addResource("brick", 2);

    CHECK(p1.getResources().at("wood") == 3);
    CHECK(p2.getResources().at("brick") == 2);

    CHECK_NOTHROW(p1.trade(p2, "wood", "brick", 1, 1));
    CHECK(p1.getResources().at("wood") == 2);
    CHECK(p1.getResources().at("brick") == 1);
    CHECK(p2.getResources().at("brick") == 1);
    CHECK(p2.getResources().at("wood") == 1);

    // Trying an invalid trade (p1 does not have 4 wood)
    CHECK_THROWS(p1.trade(p2, "wood", "brick", 4, 1));
    // Trying an invalid trade (p2 does not have 3 bricks)
    CHECK_THROWS(p1.trade(p2, "wood", "brick", 1, 3));
}

TEST_CASE("Check victory condition") {
    Player p1("Player1");
    Player p2("Player2");
    Player p3("Player3");

    Catan catan(p1, p2, p3);

    // Directly setting points to 10 to simulate a win
    p1.setPoints(10);

    CHECK(p1.getPoints() == 10);

    catan.printWinner();
}

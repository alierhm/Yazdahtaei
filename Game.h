#ifndef GAME_H
#define GAME_H
#pragma once
#include "Background.h"
#include "Player.h"
#include "Repository.h"
#include <string_view>
#include <string>
using namespace std;

inline string someUnknownFileNameString_ThatMustNotBeReused = "fullRepository.dat";
// shouldn't be reused anywhere out of this header file

class Game {
    Repository m_repository;
    Background m_background;
    vector<Player> m_players;
    int m_numberOfPlayers;
    int m_idOfLastPlayerThatCollectedSomeCards{0};
public:
    Game(string_view numberOfPlayers);
    int play(Player &player);
    void calculateScores();
    void setNumberOfPlayers_Usernames_And_Passwords(string_view numberOfPlayers);
    void initializeRepositoryAndBackground();
    void initializePlayers(string_view numberOfPlayers);
    void runTheMainPartOfTheGame();
    void showScores();
    void calculateRanks();
    void showRanks();
};


#endif //GAME_H

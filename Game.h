#ifndef GAME_H
#define GAME_H
#pragma once
#include "Background.h"
#include "Player.h"
#include "Repository.h"
#include <string>
#include <string_view>
#include <variant>

using PartialDeck = variant<string, vector<Card>>;
using namespace std;

inline string someUnknownFileNameString_ThatMustNotBeReused =
    "fullRepository.dat";

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
  void setNumberOfPlayers(string_view numberOfPlayers);
  void initializeRepositoryAndBackground();
  void initializePlayers(string_view numberOfPlayers);
  void runTheMainPartOfTheGame();
  void showScores();
  void calculateRanks();
  void showRanks();
  void saveHistory();
  bool allOfPlayersHaveNoCardsInTheirHands();
  void writeString(ofstream &ofs, const string &str);
  string readString(ifstream &ifs);
};

#endif // GAME_H

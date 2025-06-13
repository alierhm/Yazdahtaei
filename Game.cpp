
#include "Game.h"
#include "getPasswordFromUser.h"
#include "sumOfNumberOfCards.h"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <format>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>

using PartialDeck = variant<string, vector<Card>>;
using namespace std;

Game::Game(string_view numberOfPlayers)
    : m_numberOfPlayers{0}, m_idOfLastPlayerThatCollectedSomeCards{0} {
  setNumberOfPlayers(numberOfPlayers);
  initializePlayers(numberOfPlayers);
  runTheMainPartOfTheGame();
  cout << format("\n\n==========================\nOK! The game is over.\n\n");
  saveHistory();
  showScores(); // scores are already calculated before ending the game
  calculateRanks();
  showRanks();
}

int Game::play(Player &player) {
  int idOfLastPlayerThatCollectedSomeCards{0};
  string cardNumberInputFromUser;
  for (;;) {
    m_background.show();
    player.showCardsInHand();
    cout << format("Which card do you want to play?\n");
    cout << format("Enter a number between 1 and {}: ",
                   player.howManyCardsInHand());
    getline(cin, cardNumberInputFromUser);
    bool gotAValidCardNumberToThrow{false};
    for (int k{0}; k < player.howManyCardsInHand(); ++k) {
      if (cardNumberInputFromUser == to_string(k + 1)) {
        gotAValidCardNumberToThrow = true;
        break;
      }
    }
    if (!gotAValidCardNumberToThrow) {
      cout << format("Invalid Input! Try again.\n");
    } else {
      break; // got a valid card number to throw
    }
  }
  vector<vector<Card>> matches; // vector of matches
  int actualNumberOfTheChosenCard{
      player.getIthCardInHand(stoi(cardNumberInputFromUser)).getNumber()};
  if (!m_background.empty()) {
    if (actualNumberOfTheChosenCard >= 11) {
      if (actualNumberOfTheChosenCard == 11) {
        int numberOfJacksOrNumbersInBackground{0};
        for (auto &backCard : m_background.getStack()) {
          if (backCard.getNumber() <= 11) {
            ++numberOfJacksOrNumbersInBackground;
          }
        }
        if (numberOfJacksOrNumbersInBackground >= 0) {
          vector<Card> matchForJack;
          for (auto &backCard : m_background.getStack()) {
            if (backCard.getNumber() <= 11) {
              matchForJack.push_back(backCard);
            }
          }
          matches.push_back(matchForJack);
        }
      } else if (actualNumberOfTheChosenCard == 12) {
        for (auto &backCard : m_background.getStack()) {
          if (backCard.getNumber() == 12) {
            vector<Card> matchForQueen;
            matchForQueen.push_back(backCard);
            matches.push_back(matchForQueen);
          }
        }
      } else if (actualNumberOfTheChosenCard == 13) {
        for (auto &backCard : m_background.getStack()) {
          if (backCard.getNumber() == 13) {
            vector<Card> matchForKing;
            matchForKing.push_back(backCard);
            matches.push_back(matchForKing);
          }
        }
      }
    } else {
      vector<vector<Card>> combinationsOfSize1FromBackground{
          m_background.getCombinationsOfSize(1)};
      for (auto &combination : combinationsOfSize1FromBackground) {
        int sumOfNumberOfCardsInCombination{sumOfNumberOfCards(combination)};
        if ((actualNumberOfTheChosenCard + sumOfNumberOfCardsInCombination) ==
            11) {
          matches.push_back(combination);
        }
      }
      if (m_background.size() >= 2) {
        vector<vector<Card>> combinationsOfSize2FromBackground{
            m_background.getCombinationsOfSize(2)};
        for (auto &combination : combinationsOfSize2FromBackground) {
          int sumOfNumberOfCardsInCombination{sumOfNumberOfCards(combination)};
          if ((actualNumberOfTheChosenCard + sumOfNumberOfCardsInCombination) ==
              11) {
            matches.push_back(combination);
          }
        }
        if (m_background.size() >= 3) {
          vector<vector<Card>> combinationsOfSize3FromBackground{
              m_background.getCombinationsOfSize(3)};
          for (auto &combination : combinationsOfSize3FromBackground) {
            int sumOfNumberOfCardsInCombination{
                sumOfNumberOfCards(combination)};
            if ((actualNumberOfTheChosenCard +
                 sumOfNumberOfCardsInCombination) == 11) {
              matches.push_back(combination);
            }
          }
          if (m_background.size() >= 4) {
            vector<vector<Card>> combinationsOfSize4FromBackground{
                m_background.getCombinationsOfSize(4)};
            for (auto &combination : combinationsOfSize4FromBackground) {
              int sumOfNumberOfCardsInCombination{
                  sumOfNumberOfCards(combination)};
              if ((actualNumberOfTheChosenCard +
                   sumOfNumberOfCardsInCombination) == 11) {
                matches.push_back(combination);
              }
            }
            if (m_background.size() >= 5) {
              vector<vector<Card>> combinationsOfSize5FromBackground{
                  m_background.getCombinationsOfSize(5)};
              for (auto &combination : combinationsOfSize5FromBackground) {
                int sumOfNumberOfCardsInCombination{
                    sumOfNumberOfCards(combination)};
                if ((actualNumberOfTheChosenCard +
                     sumOfNumberOfCardsInCombination) == 11) {
                  matches.push_back(combination);
                }
              }
              if (m_background.size() >= 6) {
                vector<vector<Card>> combinationsOfSize6FromBackground{
                    m_background.getCombinationsOfSize(6)};
                for (auto &combination : combinationsOfSize6FromBackground) {
                  int sumOfNumberOfCardsInCombination{
                      sumOfNumberOfCards(combination)};
                  if ((actualNumberOfTheChosenCard +
                       sumOfNumberOfCardsInCombination) == 11) {
                    matches.push_back(combination);
                  }
                }
                if (m_background.size() >= 7) {
                  vector<vector<Card>> combinationsOfSize7FromBackground{
                      m_background.getCombinationsOfSize(7)};
                  for (auto &combination : combinationsOfSize7FromBackground) {
                    int sumOfNumberOfCardsInCombination{
                        sumOfNumberOfCards(combination)};
                    if ((actualNumberOfTheChosenCard +
                         sumOfNumberOfCardsInCombination) == 11) {
                      matches.push_back(combination);
                    }
                  }
                  if (m_background.size() >= 8) {
                    vector<vector<Card>> combinationsOfSize8FromBackground{
                        m_background.getCombinationsOfSize(8)};
                    for (auto &combination :
                         combinationsOfSize8FromBackground) {
                      int sumOfNumberOfCardsInCombination{
                          sumOfNumberOfCards(combination)};
                      if ((actualNumberOfTheChosenCard +
                           sumOfNumberOfCardsInCombination) == 11) {
                        matches.push_back(combination);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if (matches.empty()) {
      cout << format("No match found for the chosen card.\n");
      m_background.push_back(
          player.erase_Ith_Card_In_Hand(stoi(cardNumberInputFromUser)));
    } else {
      idOfLastPlayerThatCollectedSomeCards = player.getId();
      cout << format("Some match(es) found for the chosen card:\n\n");
      for (auto &match : matches) {
        // print the matches
        static int numOfMatch{1};
        cout << format("{}{} match: ", numOfMatch,
                       (numOfMatch == 1)   ? "st"
                       : (numOfMatch == 2) ? "nd"
                       : (numOfMatch == 3) ? "rd"
                                           : "th");
        for (auto &card : match) {
          card.toString();
          cout << "   ";
        }
        cout << "\n\n";
        numOfMatch++;
      }
      bool validInputToChooseAMatch{false};
      string matchNumberInputFromUser;
      while (!validInputToChooseAMatch) {
        // get input from the player to choose a match
        cout << format("Choose a match to collect the cards (enter a number "
                       "between 1 and {}): ",
                       matches.size());
        getline(cin, matchNumberInputFromUser);
        for (int k{0}; k < matches.size(); ++k) {
          if (matchNumberInputFromUser == to_string(k + 1)) {
            validInputToChooseAMatch = true;
            break;
          }
        }
        if (!validInputToChooseAMatch) {
          cout << format("Invalid Input! Try again.\n");
        }
      }
      vector<Card> cardsToCollect;
      cardsToCollect = matches.at(stoi(matchNumberInputFromUser) - 1);
      cardsToCollect.push_back(
          player.erase_Ith_Card_In_Hand(stoi(cardNumberInputFromUser)));
      m_background.erase(matches.at(stoi(matchNumberInputFromUser) - 1));
      player.insertCollectedCards(cardsToCollect);
      cardsToCollect = {};
      if (m_background.empty() && actualNumberOfTheChosenCard != 11 &&
          !m_repository.empty()) {
        cout << format("Congratulations! You won a sur!\n");
        player.addSurCount();
      }
    }
  } else {
    m_background.push_back(
        player.erase_Ith_Card_In_Hand(stoi(cardNumberInputFromUser)));
  }

  return idOfLastPlayerThatCollectedSomeCards;
}

void Game::calculateScores() {
  vector<int> clubsCounts(m_players.size());
  for (int i{0}; i < m_players.size(); ++i) {
    for (int j{0}; j < m_players.at(i).getCollectedCards().size(); ++j) {
      if (m_players.at(i).getCollectedCards().at(j).getSuit() == "Clubs") {
        clubsCounts.at(i)++;
      }
      if (m_players.at(i).getCollectedCards().at(j).getNumber() == 11 ||
          m_players.at(i).getCollectedCards().at(j).getNumber() == 1) {
        m_players.at(i).addScore(1);
      }
      if (m_players.at(i).getCollectedCards().at(j).getNumber() == 10 &&
          m_players.at(i).getCollectedCards().at(j).getSuit() == "Diamonds") {
        m_players.at(i).addScore(3);
      }
      if (m_players.at(i).getCollectedCards().at(j).getNumber() == 2 &&
          m_players.at(i).getCollectedCards().at(j).getSuit() == "Clubs") {
        m_players.at(i).addScore(2);
      }
    }
  }
  bool equalityExists{false};
  for (int k{0}; k < clubsCounts.size(); ++k) {
    for (int l{0}; l < clubsCounts.size(); ++l) {
      if (k != l && clubsCounts.at(k) == clubsCounts.at(l)) {
        equalityExists = true;
      }
    }
  }
  if (!equalityExists) {
    int maxClubsCount{-1};
    int indexOfMaxClubsCountPlayer{-1};
    for (int g{0}; g < clubsCounts.size(); ++g) {
      if (clubsCounts.at(g) > maxClubsCount) {
        maxClubsCount = clubsCounts.at(g);
        indexOfMaxClubsCountPlayer = g;
      }
    }
    m_players.at(indexOfMaxClubsCountPlayer).addScore(7);
  }
  vector<Player> players_copy;
  for (auto &player : m_players) {
    players_copy.push_back(player);
  }
  function<void(int, int)> swap = [&players_copy](int i, int j) {
    Player temp = players_copy.at(i);
    players_copy.at(i) = players_copy.at(j);
    players_copy.at(j) = temp;
  };
  for (int h{0}; h < players_copy.size() - 1; ++h) {
    for (int i{0}; i < players_copy.size() - 1 - h; ++i) {
      if (players_copy.at(i).getSurCount() >
          players_copy.at(i + 1).getSurCount()) {
        swap(i, i + 1);
      }
    }
  }
  for (auto &player : m_players) {
    player.addScore((player.getSurCount() - players_copy.at(0).getSurCount()) *
                    5);
  }
}

void Game::setNumberOfPlayers(string_view numberOfPlayers) {
  string stringNumOfPlayers{numberOfPlayers};
  m_numberOfPlayers = stoi(stringNumOfPlayers);
}

void Game::initializeRepositoryAndBackground() {
  string fullRepositoryFileName = "fullRepository.dat";
  string &nameOfInFile = fullRepositoryFileName;
  PartialDeck deck = nameOfInFile;
  m_repository.fill(deck);
  m_repository.shuffleOut();
  m_background.fill(m_repository.get4FromDeck());
  for (;;) {
    int jacksCount{0}, queensCount{0}, kingsCount{0};
    static int numberOfTimes1JackOccurred{0};
    for (int k{1}; k <= 3; ++k) {
      for (auto &backCard : m_background.getStack()) {
        if (backCard.getNumber() == ((k == 1) ? 11 : (k == 2) ? 12 : 13)) {
          ++((k == 1) ? jacksCount : (k == 2) ? queensCount : kingsCount);
        }
      }
    }
    if (jacksCount >= 2 || queensCount > 2 || kingsCount > 2) {
      if (numberOfTimes1JackOccurred == 1) {
        numberOfTimes1JackOccurred = 0;
      }
      for (int i{0}; i < 4; ++i) {
        m_repository.push_back(m_background.pop_back());
      }
      m_repository.shuffleOut();
      m_background.fill(m_repository.get4FromDeck());
      continue;
    }
    if (jacksCount == 1) {
      if (numberOfTimes1JackOccurred == 0) {
        numberOfTimes1JackOccurred = 1;
      } else if (numberOfTimes1JackOccurred == 1) {
        numberOfTimes1JackOccurred = 0;
        for (int i{0}; i < 4; ++i) {
          m_repository.push_back(m_background.pop_back());
        }
        m_repository.shuffleOut();
        m_background.fill(m_repository.get4FromDeck());
        continue;
      }
      Card jack("Hearts", 11);
      for (auto backCard : m_background.getStack()) {
        if (backCard.getNumber() == 11) {
          jack = backCard;
          m_background.erase(backCard);
          break;
        }
      }
      m_repository.pushInTheMiddle(jack);
      m_background.push_back(m_repository.back());
      continue;
    }
    break;
  }
}

void Game::initializePlayers(string_view numberOfPlayers) {

  if (numberOfPlayers == "4")
    cout << format("Players 1 and 3, then players 2 and 4, are teammates.\n\n");
  while (m_players.size() < m_numberOfPlayers) {
    string optionToRegisterOrLogin{""}, username{""}, password{""};
    bool loginWasSuccessful{false};
    while (!loginWasSuccessful) {
      cout << format("Hello player {}! Do you want to register or login? (1: "
                     "register, 2: login)\n",
                     m_players.size() + 1);
      while (true) {
        getline(cin, optionToRegisterOrLogin);
        if (optionToRegisterOrLogin == "1" || optionToRegisterOrLogin == "2") {
          break;
        } else {
          cout << format("Invalid input. Please enter 1 or 2.\n");
        }
      }
      if (optionToRegisterOrLogin == "1") // register
      {
        while (true) {
          cout << format("Enter a username: ");
          getline(cin, username);
          if (username != "") {
            break;
          } else {
            cout << format("Invalid input. Please enter a username.\n");
          }
        }
        while (true) {
          cout << format("Enter a password: ");
          password = getPasswordFromUser();
          if (password != "") {
            break;
          } else {
            cout << format("Invalid input. Please enter a password.\n");
          }
        }
        ifstream inUserPass{"usernamesAndPasswords.dat", ios::in | ios::binary};
        if (!inUserPass) {
          cerr << format("Cannot verify your credentials.\n");
          exit(EXIT_FAILURE);
        }
        if (inUserPass.good()) {
          vector<vector<string>> usernamesAndPasswords;
          size_t len = 0;
          inUserPass.read(reinterpret_cast<char *>(&len), sizeof(len));
          vector<string> usernameAndPassword(2);
          while (inUserPass) {
            for (int j{0}; j < 2; ++j) {
              usernameAndPassword.at(j) = readString(inUserPass);
            }
            usernamesAndPasswords.push_back(usernameAndPassword);
            inUserPass.read(reinterpret_cast<char *>(&len), sizeof(len));
          }
          inUserPass.close();
          bool found = false;
          for (auto &pair : usernamesAndPasswords) {
            if (pair.at(0) == username) {
              found = true;
              break;
            }
          }
          if (found) {
            loginWasSuccessful = false;
            cout << format("Username already exists. Please try again.\n");
          } else {
            ofstream outUserPass{"usernamesAndPasswords.dat",
                                 ios::binary | ios::app};
            if (!outUserPass) {
              cerr << format(
                  "Cannot save your credentials because the file "
                  "\"usernamesAndPasswords.dat\" cannot be opened.\n");
              exit(EXIT_FAILURE);
            }
            usernameAndPassword.at(0) = username;
            usernameAndPassword.at(1) = password;
            size_t vectorSize = usernameAndPassword.size();
            outUserPass.write(reinterpret_cast<const char *>(&vectorSize),
                              sizeof(vectorSize));
            for (const auto &str : usernameAndPassword) {
              writeString(outUserPass, str);
            }
            outUserPass.close();
            cout << format("Registration successful!\n");
            loginWasSuccessful = true;
          }
        }
      } else // login
      {
        while (true) {
          cout << format("Enter your username: ");
          getline(cin, username);
          if (username != "") {
            break;
          } else {
            cout << format("Invalid input. Please enter a username.\n");
          }
        }
        while (true) {
          cout << format("Enter your password: ");
          password = getPasswordFromUser();
          if (password != "") {
            break;
          } else {
            cout << format("Invalid input. Please enter a password.\n");
          }
        }
        ifstream inUserPass1{"usernamesAndPasswords.dat",
                             ios::in | ios::binary};
        if (!inUserPass1) {
          cerr << format("Cannot verify your credentials because the file "
                         "\"usernamesAndPasswords.dat\" cannot be opened.\n");
          exit(EXIT_FAILURE);
        }
        if (inUserPass1.good()) {
          vector<vector<string>> usernamesAndPasswords;
          size_t len = 0;
          inUserPass1.read(reinterpret_cast<char *>(&len), sizeof(len));
          vector<string> usernameAndPassword(2);
          while (inUserPass1) {
            for (int j{0}; j < 2; ++j) {
              usernameAndPassword.at(j) = readString(inUserPass1);
            }
            usernamesAndPasswords.push_back(usernameAndPassword);
            inUserPass1.read(reinterpret_cast<char *>(&len), sizeof(len));
          }
          inUserPass1.close();
          bool found = false;
          for (auto &pair : usernamesAndPasswords) {
            if (pair.at(0) == username && pair.at(1) == password) {
              found = true;
              break;
            }
          }
          if (found) {
            cout << format("Login successful!\n");
            loginWasSuccessful = true;
          } else {
            cout << format("Invalid username or password. Please try again.\n");
            loginWasSuccessful = false;
          }
        }
      }
    }
    string name;
    while (true) {
      cout << format("Enter your name: ");
      getline(cin, name);
      if (!name.empty()) {
        break;
      } else {
        cout << "Invalid input. Please enter a name." << endl;
      }
    }
    Player player(m_players.size() + 1, name, username, password);
    m_players.push_back(player);
  }
}

void Game::runTheMainPartOfTheGame() {
  while (true) {
    // play the game (game plays)
    bool theGameMustBeContinued{true};
    int maximScore{0};
    for (auto &player : m_players) {
      if (player.getScore() > maximScore)
        maximScore = player.getScore();
    }
    if (maximScore >= 62 && m_repository.empty() && m_background.empty() &&
        allOfPlayersHaveNoCardsInTheirHands()) {
      if (m_numberOfPlayers == 2 || m_numberOfPlayers == 3) {
        vector<int> scores;
        for (auto &player : m_players) {
          scores.push_back(player.getScore());
        }
        sort(begin(scores), end(scores));
        bool flag{false};
        for (int l{0}; l < scores.size() - 1; ++l) {
          if (scores.at(l + 1) <= scores.at(l)) {
            flag = true;
            break;
          }
        }
        if (!flag) {
          // the game must be over
          theGameMustBeContinued = false;
        } else {
          theGameMustBeContinued = true; // the game must be continued
        }
      } else {
        int scoreOfTeam1{0}, scoreOfTeam2{0};
        scoreOfTeam1 = m_players.at(0).getScore() + m_players.at(2).getScore();
        scoreOfTeam2 = m_players.at(1).getScore() + m_players.at(3).getScore();
        if (scoreOfTeam1 > scoreOfTeam2 || scoreOfTeam2 > scoreOfTeam1) {
          theGameMustBeContinued = false;// game must be over
        } else {
          theGameMustBeContinued = true; // game must be continued
        }
      }
    }

    if (m_repository.empty() && theGameMustBeContinued) {
      initializeRepositoryAndBackground();
      m_idOfLastPlayerThatCollectedSomeCards = 0;
    }

    if (theGameMustBeContinued) {
      for (auto &player : m_players) {
        player.assign_cards_in_hand(m_repository.get4FromDeck());
      }
      for (int o{0}; o < 4; ++o) {
        for (int u{0}; u < m_players.size(); ++u) {
          // player u plays a card
          // check if player u can collect cards from background
          // if yes, collect cards and update score
          // if no, put the played card on the background
          Player &currentPlayer{m_players.at(u)};
          cout << format("It's {}'s turn to play.\n", currentPlayer.getName());
          int tempId = play(currentPlayer);
          if (tempId != 0) {
            m_idOfLastPlayerThatCollectedSomeCards = tempId;
          }
        }
      }
      if (m_repository.empty() && !m_background.empty()) {
        vector<Card> backgroundCardsAfterClearing(m_background.clear());
        m_players.at(m_idOfLastPlayerThatCollectedSomeCards - 1)
            .insertCollectedCards(backgroundCardsAfterClearing);
        cout << format(
            "\n{} was the last player who collected cards in this "
            "round and because the background cards are not empty, "
            "he/she collects them all.\n",
            m_players.at(m_idOfLastPlayerThatCollectedSomeCards - 1).getName());
        calculateScores();
      } else if (m_repository.empty() && m_background.empty()) {
        calculateScores();
      }
    }
    int maxScore{0};
    for (auto &player : m_players) {
      if (player.getScore() > maxScore)
        maxScore = player.getScore();
    }
    if (maxScore >= 62 && m_repository.empty() && m_background.empty()) {
      if (m_numberOfPlayers == 2 || m_numberOfPlayers == 3) {
        vector<int> scores;
        for (auto &player : m_players) {
          scores.push_back(player.getScore());
        }
        sort(begin(scores), end(scores));
        bool flag{false};
        for (int l{0}; l < scores.size() - 1; ++l) {
          if (scores.at(l + 1) <= scores.at(l)) {
            flag = true;
            break;
          }
        }
        if (!flag) {
          break; // stop playing the game
        } else {
          continue; // continue playing the game
        }
      } else {
        int scoreOfTeam1{0}, scoreOfTeam2{0};
        scoreOfTeam1 = m_players.at(0).getScore() + m_players.at(2).getScore();
        scoreOfTeam2 = m_players.at(1).getScore() + m_players.at(3).getScore();
        if (scoreOfTeam1 > scoreOfTeam2 || scoreOfTeam2 > scoreOfTeam1) {
          break;
        } else {
          continue;
        }
      }
    }
  }
}

void Game::showScores() {
  cout << format("Scores:\n");
  for (auto &player : m_players) {
    cout << format("{}: {}\n", player.getName(), player.getScore());
  }
}

void Game::calculateRanks() {
  vector<Player *> playersToRankByScore;
  for (Player &player : m_players) {
    playersToRankByScore.push_back(&player);
  }
  for (int e{0}; e < m_players.size() - 1; ++e) {
    for (int r{0}; r < m_players.size() - 1 - e; ++r) {
      if (playersToRankByScore.at(r)->getScore() >
          playersToRankByScore.at(r + 1)->getScore()) {
        swap(playersToRankByScore.at(r), playersToRankByScore.at(r + 1));
      }
    }
  }
  for (int q{0}; q < m_players.size(); ++q) {
    playersToRankByScore.at(q)->setRank(q + 1);
  }
}

void Game::showRanks() {
  cout << format("\nRankings:\n");
  if (m_numberOfPlayers == 2 || m_numberOfPlayers == 3) {
    for (auto &player : m_players) {
      cout << format("Player {}: {}\n", player.getName(), player.getRank());
    }
  } else {
    int scoreOfTeam1{0}, scoreOfTeam2{0};
    scoreOfTeam1 = m_players.at(0).getScore() + m_players.at(2).getScore();
    scoreOfTeam2 = m_players.at(1).getScore() + m_players.at(3).getScore();
    if (scoreOfTeam1 > scoreOfTeam2) {
      cout << format("Team 1: 1\nTeam 2: 2\n");
    } else if (scoreOfTeam2 > scoreOfTeam1) {
      cout << format("Team 2: 1\nTeam 1: 2\n");
    }
  }
}

void Game::saveHistory() {
  if (m_numberOfPlayers == 2) {
    ofstream outHistory{"teamsOf2ThatHavePlayedTheGame.txt", ios::app};
    if (!outHistory) {
      cerr << format(
          "Cannot save history because the file "
          "\"teamsOf2ThatHavePlayedTheGame.dat\" cannot be opened.\n");
      exit(EXIT_FAILURE);
    } else {

      for (auto &player : m_players) {
        outHistory << "Player " << player.getId()
                   << ":   Name: " << player.getName()
                   << ", Username: " << player.getUsername()
                   << ", Score: " << player.getScore()
                   << ", Rank: " << player.getRank() << ". \n";
      }
      outHistory.close();
    }
  } else if (m_numberOfPlayers == 3) {
    ofstream outHistory{"teamsOf3ThatHavePlayedTheGame.txt", ios::app};
    if (!outHistory) {
      cerr << format(
          "Cannot save history because the file "
          "\"teamsOf3ThatHavePlayedTheGame.dat\" cannot be opened.\n");
      exit(EXIT_FAILURE);
    } else {
      for (auto &player : m_players) {
        outHistory << "Player " << player.getId()
                   << ":   Name: " << player.getName()
                   << ", Username: " << player.getUsername()
                   << ", Score: " << player.getScore()
                   << ", Rank: " << player.getRank() << ". \n";
      }
      outHistory.close();
    }
  } else if (m_numberOfPlayers == 4) {
    ofstream outHistory{"teamsOf4ThatHavePlayedTheGame.txt", ios::app};
    if (!outHistory) {
      cerr << format(
          "Cannot save history because the file "
          "\"teamsOf4ThatHavePlayedTheGame.dat\" cannot be opened.\n");
      exit(EXIT_FAILURE);
    } else {
      for (auto &player : m_players) {
        outHistory << "Player " << player.getId()
                   << ":   Name: " << player.getName()
                   << ", Username: " << player.getUsername()
                   << ", Score: " << player.getScore()
                   << ", Rank: " << player.getRank() << ". \n";
      }
      outHistory.close();
    }
  } else {
    cerr << format("Invalid number of players!\n");
    exit(EXIT_FAILURE);
  }
}

bool Game::allOfPlayersHaveNoCardsInTheirHands() {
  bool allOfPlayersHaveNoCardsInTheirHands{true};
  for (auto &player : m_players) {
    if (!player.getCardsInHand().empty()) {
      allOfPlayersHaveNoCardsInTheirHands = false;
      break;
    }
  }
  return allOfPlayersHaveNoCardsInTheirHands;
}

void Game::writeString(ofstream &ofs, const string &str) {
  size_t len = str.length();
  ofs.write(reinterpret_cast<const char *>(&len), sizeof(len));
  ofs.write(str.c_str(), len);
}

string Game::readString(ifstream &ifs) {
  size_t len = 0;
  ifs.read(reinterpret_cast<char *>(&len), sizeof(len));
  if (!ifs)
    return "";

  vector<char> vectorOfChars(len);
  ifs.read(vectorOfChars.data(), len);
  return string(vectorOfChars.begin(), vectorOfChars.end());
}

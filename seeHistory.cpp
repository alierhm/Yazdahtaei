//
// Created by Ali on 6/12/2025.
//
#include "seeHistory.h"
#include <format>
#include <string>
string readString(ifstream &ifs);
void seeHistory() {
  string username{""}, password{""};
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
  ifstream inUserPass{"usernamesAndPasswords.dat", ios::in | ios::binary};
  if (!inUserPass) {
    cerr << format("Cannot verify your credentials because the file "
                   "\"usernamesAndPasswords.dat\" cannot be opened.\n");
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
      if (pair.at(0) == username && pair.at(1) == password) {
        found = true;
        break;
      }
    }
    if (found) {
      string teamsThatThePlayerHasPlayedWith;
      ifstream inputTeamsOf2ThatHavePlayedTheGame{
          "teamsOf2ThatHavePlayedTheGame.txt"};
      if (!inputTeamsOf2ThatHavePlayedTheGame) {
        cerr << format("Couldn't open the file to show history of teams of two "
                       "players!\n");
        exit(EXIT_FAILURE);
      } else {
        string teamsOf2ThatHavePlayed;
        string teamOf2ThatHasPlayed, player1, player2;
        for (int i{0}; i < 2; ++i) {
          getline(inputTeamsOf2ThatHavePlayedTheGame,
                  (i == 0) ? player1 : player2);
        }
        teamOf2ThatHasPlayed = player1 + "\n" + player2 + "\n";
        while (inputTeamsOf2ThatHavePlayedTheGame) {
          if (teamOf2ThatHasPlayed.find(username) != std::string::npos) {
            teamsOf2ThatHavePlayed += teamOf2ThatHasPlayed;
          }
          for (int i{0}; i < 2; ++i) {
            getline(inputTeamsOf2ThatHavePlayedTheGame,
                    (i == 0) ? player1 : player2);
          }
          teamOf2ThatHasPlayed = player1 + "\n" + player2 + "\n";
        }
        teamsThatThePlayerHasPlayedWith +=
            "\n\n==========================\nTeams of 2 that you've played "
            "with: \n" +
            ((teamsOf2ThatHavePlayed == "") ? "No Teams available!\n"
                                            : teamsOf2ThatHavePlayed);
        inputTeamsOf2ThatHavePlayedTheGame.close();
      }

      // continuing the same for 3- and 4-player teams
      ifstream inputTeamsOf3ThatHavePlayedTheGame{
          "teamsOf3ThatHavePlayedTheGame.txt"};
      if (!inputTeamsOf3ThatHavePlayedTheGame) {
        cerr << format("Couldn't open the file to show history of teams of "
                       "three players!\n");
        exit(EXIT_FAILURE);
      } else {
        string teamsOf3ThatHavePlayed;
        string teamOf3ThatHasPlayed, player1, player2, player3;
        for (int i{0}; i < 3; ++i) {
          getline(inputTeamsOf3ThatHavePlayedTheGame, (i == 0)   ? player1
                                                      : (i == 1) ? player3
                                                                 : player3);
        }
        teamOf3ThatHasPlayed = player1 + "\n" + player2 + "\n" + player3 + "\n";
        while (inputTeamsOf3ThatHavePlayedTheGame) {
          if (teamOf3ThatHasPlayed.find(username) != std::string::npos) {
            teamsOf3ThatHavePlayed += teamOf3ThatHasPlayed;
          }
          for (int i{0}; i < 3; ++i) {
            getline(inputTeamsOf3ThatHavePlayedTheGame, (i == 0)   ? player1
                                                        : (i == 1) ? player3
                                                                   : player3);
          }
          teamOf3ThatHasPlayed =
              player1 + "\n" + player2 + "\n" + player3 + "\n";
        }
        teamsThatThePlayerHasPlayedWith +=
            "\n==========================\nTeams of 3 that you've played "
            "with: \n" +
            ((teamsOf3ThatHavePlayed == "") ? "No Teams available!\n"
                                            : teamsOf3ThatHavePlayed);
        inputTeamsOf3ThatHavePlayedTheGame.close();
      }

      ifstream inputTeamsOf4ThatHavePlayedTheGame{
          "teamsOf4ThatHavePlayedTheGame.txt"};
      if (!inputTeamsOf4ThatHavePlayedTheGame) {
        cerr << format("Couldn't open the file to show history of teams of "
                       "four players!\n");
        exit(EXIT_FAILURE);
      } else {
        string teamsOf4ThatHavePlayed;
        string teamOf4ThatHasPlayed, player;
        for (int i{0}; i < 4; ++i) {
          getline(inputTeamsOf4ThatHavePlayedTheGame, player);
          player += "\n";
          teamOf4ThatHasPlayed += player;
        }
        while (inputTeamsOf4ThatHavePlayedTheGame) {
          if (teamOf4ThatHasPlayed.find(username) != std::string::npos) {
            teamsOf4ThatHavePlayed += teamOf4ThatHasPlayed;
          }
          for (int i{0}; i < 4; ++i) {
            getline(inputTeamsOf4ThatHavePlayedTheGame, player);
            player += "\n";
            teamOf4ThatHasPlayed += player;
          }
        }
        teamsThatThePlayerHasPlayedWith +=
            "\n==========================\nTeams of 4 that you've played "
            "with: \n" +
            ((teamsOf4ThatHavePlayed == "") ? "No Teams available!\n"
                                            : teamsOf4ThatHavePlayed);
        inputTeamsOf4ThatHavePlayedTheGame.close();
      }

      if (teamsThatThePlayerHasPlayedWith == "") {
        cout << format("You haven't played any games yet.\n");
      } else {
        cout << format("\n==========================\n");
        cout << format("Here is your game history:\n");
        cout << teamsThatThePlayerHasPlayedWith;
      }
    }
    if (!found) {
      cout << format("No such user has ever played the game.\n");
      return;
    }
  }
}

string readString(ifstream &ifs) {
  size_t len = 0;
  ifs.read(reinterpret_cast<char *>(&len), sizeof(len));
  if (!ifs)
    return "";

  vector<char> vectorOfChars(len);
  ifs.read(vectorOfChars.data(), len);
  return string(vectorOfChars.begin(), vectorOfChars.end());
}

#include "Game.h"
#include "seeHistory.h"
#include <format>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ofstream outUserPass{"usernamesAndPasswords.dat", ios::binary | ios::app};
  outUserPass.close();
  ofstream outHistory1{"teamsOf2ThatHavePlayedTheGame.txt", ios::app};
  outHistory1.close();
  ofstream outHistory2{"teamsOf3ThatHavePlayedTheGame.txt", ios::app};
  outHistory2.close();
  ofstream outHistory3{"teamsOf4ThatHavePlayedTheGame.txt", ios::app};
  outHistory3.close();
  bool wantToPlay = true;
  while (wantToPlay) {
    cout << "Welcome to 'Yazdahtaei' game" << endl;
    string input{""};
    while (true) {
      cout << "Do you want to continue? (yes/no): ";
      getline(cin, input);
      if (input == "yes" || input == "no") {
        break;
      } else {
        cout << "Invalid input. Please enter 'yes' or 'no'." << endl;
      }
    }
    if (input == "no") {
      cout << format("OK, goodbye!\n");
      wantToPlay = false;
      break;
    }
    string condition{""};
    while (true) {
      cout << format(
          "Do you want to play or see history?\n     1: Play    2.: History\n");
      getline(cin, condition);
      if (condition == "1" || condition == "2") {
        break;
      } else {
        cout << "Invalid input. Please enter '1' or '2'." << endl;
      }
    }
    if (condition == "2") {
      seeHistory();
      continue;
    }
    if (condition == "1") {
      string numberOfPlayers{"0"};
      while (true) {
        cout << "Enter the number of players (2-4): ";
        getline(cin, numberOfPlayers);
        if (numberOfPlayers == "2" || numberOfPlayers == "3" ||
            numberOfPlayers == "4") {
          break;
        } else {
          cout << "Invalid input. Please enter a number between 2 and 4; "
                  "without any space before/after."
               << endl;
        }
      }

      Game game(numberOfPlayers);
    }
  }

  return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <random>
#include <stdexcept>
#include "Card.h"
#include "DeckOfCards.h"
#include "DemonstrableCards.h"
#include "Game.h"
#include "Repository.h"
#include "Background.h"
#include "Player.h"
#include "CollectedCards.h"
#include "CardsInHand.h"

using namespace std;

int main()
{
    while (true)
    {
        cout << "Welcome to 'Yazdahtaei' game" << endl;
        string numberOfPlayers;
        while (true)
        {
            cout << "Enter the number of players (2-4): ";
            getline(cin, numberOfPlayers);
            if (numberOfPlayers == "2" || numberOfPlayers == "3" || numberOfPlayers == "4")
            {
                break;
            }
            else
            {
                cout << "Invalid input. Please enter a number between 2 and 4." << endl;
            }
        }

        Game game(numberOfPlayers);
    }

    return 0;
}

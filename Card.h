// Card class definition
#ifndef CARD_H
#define CARD_H
#pragma once
#include <string>
#include <string_view>
using namespace std;

class Card {
    std::string m_suit; // Clubs, Diamonds, Hearts, Spades
    int m_number; // 1-13; 1 = Ace, 11 = Jack, 12 = Queen, 13 = King
public:
    Card(string_view suit, int number);

    void setSuit(string_view suit);

    void setNumber(int &number);

    const string &getSuit() const;

    const int &getNumber() const;

    bool operator==(const Card &other) const;

    bool operator!=(const Card &other) const;

    void toString() const;
};

#endif //CARD_H

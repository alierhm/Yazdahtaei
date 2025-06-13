// Card class definition
#ifndef CARD_H
#define CARD_H
#pragma once
#include <string>

using namespace std;

class Card {
  char m_suit[9]; // Clubs, Diamonds, Hearts, Spades
  int m_number;   // 1-13; 1 = Ace, 11 = Jack, 12 = Queen, 13 = King

public:
  Card(string suit = "Hearts", int number = 1);

  void setSuit(string suit);

  void setNumber(int &number);

  const string getSuit() const;

  const int getNumber() const;

  bool operator==(const Card &other) const;

  bool operator!=(const Card &other) const;

  void toString() const;
};

#endif // CARD_H

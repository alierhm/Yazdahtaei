
#include "Card.h"

#include <cstddef>
#include <format>
#include <iostream>

using std::string;

Card::Card(string suit, int number) {
  setSuit(suit);
  setNumber(number);
}

void Card::setSuit(string suit) {
  size_t length = suit.size();
  suit.copy(m_suit, length);
  m_suit[length] = '\0';
}

void Card::setNumber(int &number) { m_number = number; }

const string Card::getSuit() const { return m_suit; }

const int Card::getNumber() const { return m_number; }

bool Card::operator==(const Card &other) const {
  if (other.getSuit() == this->m_suit && other.getNumber() == this->m_number) {
    return true;
  } else {
    return false;
  }
}

bool Card::operator!=(const Card &other) const {
  if (other.getSuit() != this->m_suit || other.getNumber() != this->m_number) {
    return true;
  } else {
    return false;
  }
}

void Card::toString() const {
  cout << format("{} of {}",
                 (m_number == 11)   ? "Jack"
                 : (m_number == 12) ? "Queen"
                 : (m_number == 13) ? "King"
                 : (m_number == 1)  ? "A"
                                    : format("{}", m_number),
                 string(m_suit));
}

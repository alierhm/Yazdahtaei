#include  "Card.h"

#include <format>
#include <iostream>

Card::Card(string_view suit, int number) {
    setSuit(suit);
    setNumber(number);
}

void Card::setSuit(string_view suit) {
    m_suit = suit;
}

void Card::setNumber(int &number) {
    m_number = number;
}

const string &Card::getSuit() const {
    return m_suit;
}

const int &Card::getNumber() const {
    return m_number;
}

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
    cout << format("{} of {}\n",
                   (m_number == 11)
                       ? "Jack"
                       : (m_number == 12)
                             ? "Queen"
                             : (m_number == 13)
                                   ? "King"
                                   : format("{}",m_number), m_suit);
}

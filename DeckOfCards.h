#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H
#pragma once
#include "Card.h"
#include <vector>
#include <variant>
#include <string>
using namespace std;
using PartialDeck = variant<string, vector<Card>>;

class DeckOfCards {
protected:
    vector<Card> m_cards;

public:
    virtual void fill(PartialDeck deck) = 0;
    virtual ~DeckOfCards() = default;
};

#endif //DECKOFCARDS_H

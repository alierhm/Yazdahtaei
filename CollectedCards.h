

#ifndef COLLECTEDCARDS_H
#define COLLECTEDCARDS_H
#pragma once
#include "DemonstrableCards.h"
#include "DeckOfCards.h"
#include "Card.h"
#include <vector>

class CollectedCards : public DemonstrableCards, public DeckOfCards {
public:
    virtual ~CollectedCards() = default;
    void fill(PartialDeck deck) override;
    void show() override;
    void insert(vector<Card>& cards);
    vector<Card> getCards();
    void setCards(const std::vector<Card>& cards);
};



#endif //COLLECTEDCARDS_H

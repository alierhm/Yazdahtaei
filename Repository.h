#ifndef REPOSITORY_H
#define REPOSITORY_H
#pragma once
#include "DeckOfCards.h"
#include <vector>

class Repository final : public DeckOfCards {
public:

    void fill(PartialDeck deck) override;
    void shuffleOut();
    vector<Card> &get4FromDeck();
    void pushInTheMiddle(Card card);
    void push_back(Card card);
    Card back() const;
    bool empty() const;
    std::vector<Card> getAllCards() const;
    void setCards(const std::vector<Card>& cards);
};

#endif //REPOSITORY_H

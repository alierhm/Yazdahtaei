

#ifndef CARDSINHAND_H
#define CARDSINHAND_H
#pragma once
#include "DemonstrableCards.h"


class CardsInHand : public DemonstrableCards, public DeckOfCards {
public:
    void show() override;
    void fill(PartialDeck deck) override;
    int size();
    Card getIthCard(int i);
    Card erase(int i);
    void assign(vector<Card> cards);
    void insert(vector<Card>& cards);
    std::vector<Card> getCards() const;
    void setCards(const std::vector<Card>& cards);
};



#endif //CARDSINHAND_H

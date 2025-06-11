#ifndef BACKGROUND_H
#define BACKGROUND_H
#pragma once
#include "DemonstrableCards.h"
#include "Repository.h"
using namespace std;
using PartialDeck = variant<string, vector<Card> >;

class Background : public DemonstrableCards, public DeckOfCards {
public:
    void show() override;

    bool empty();

    void fill(PartialDeck deck) override;

    vector<Card> &getStack();

    void push_back(Card card);

    Card pop_back();

    template<typename T>
    void erase(T card_s);

    int size();

    std::vector<std::vector<Card> > getCombinationsOfSize(int k);

    vector<Card> clear();
};


#endif //BACKGROUND_H

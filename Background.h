#ifndef BACKGROUND_H
#define BACKGROUND_H
#pragma once
#include "DemonstrableCards.h"
#include "Repository.h"
#include<algorithm>
#include <type_traits>
using namespace std;
using PartialDeck = variant<string, vector<Card> >;

class Background : public DemonstrableCards, public DeckOfCards {
public:
    virtual ~Background() = default;

    void show() override;

    bool empty();

    void fill(PartialDeck deck) override;

    vector<Card> &getStack();

    void push_back(Card card);

    Card pop_back();

    template<typename T>
    void erase(T card_s) {
        using DecayedT = std::decay_t<T>;
        if constexpr (std::is_same_v<DecayedT, Card>) {
            auto cardToErase = std::find(m_cards.begin(), m_cards.end(), card_s);
            if (cardToErase != m_cards.end()) {
                m_cards.erase(cardToErase);
            }
        } else if constexpr (std::is_same_v<DecayedT, std::vector<Card> >) {
            for (auto &card: card_s) {
                auto cardToErase = std::find(m_cards.begin(), m_cards.end(), card);
                if (cardToErase != m_cards.end()) {
                    m_cards.erase(cardToErase);
                }
            }
        } else {
            static_assert(false, "Unsupported type for Background::erase template function.");
        }
    }

    int size();

    std::vector<std::vector<Card> > getCombinationsOfSize(int k);

    vector<Card> clear();
};


#endif //BACKGROUND_H

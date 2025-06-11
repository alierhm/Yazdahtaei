#include <iostream>
#include <format>
#include <stdexcept>
#include "Background.h"

#include <functional>
using namespace std;


void Background::fill(PartialDeck deck) {
    m_cards = std::get<std::vector<Card>>(deck);
}

void Background::show() {
    cout << format("Here are the cards on the background:\n");
    if (empty()) {
        cout << format("No Cards on the Background\n");
        return;
    }
    for (auto &card: m_cards) {
        card.toString();
        cout << "\n";
    }
}

vector<Card> &Background::getStack() {
    return m_cards;
}

void Background::push_back(Card card) {
    m_cards.push_back(card);
}

template<typename T>
void Background::erase(T card_s) {
    bool caught = false;
    try {
        card_s.size(); // if instead of std::vector<Card>, T is the type 'Card', the exception will be thrown
    } catch (const std::exception &e) {
        caught = true;
    }
    if (caught) {
        auto cardToErase = std::find(m_cards.begin(), m_cards.end(), card_s);
        if (cardToErase != m_cards.end()) {
            m_cards.erase(cardToErase);
        }
    } else {
        // erase the combination of cards from the background
        for (auto &card: card_s) {
            auto cardToErase = std::find(m_cards.begin(), m_cards.end(), card);
            if (cardToErase != m_cards.end()) {
                m_cards.erase(find(m_cards.begin(), m_cards.end(), card));
            }
        }
    }
}

Card Background::pop_back() {
    Card card = m_cards.back();
    m_cards.pop_back();
    return card;
}

bool Background::empty() {
    return m_cards.empty();
}

int Background::size() {
    return m_cards.size();
}

std::vector<std::vector<Card> > Background::getCombinationsOfSize(int k) {
    std::vector<std::vector<Card> > result;
    std::vector<Card> currentCombination;
    int n = size();
    function<void(int, int)> generate =
            [&](int start, int count) {
        if (count == k) {
            result.push_back(currentCombination);
            return;
        }

        for (int i = start; i < n; ++i) {
            currentCombination.push_back(m_cards[i]);
            generate(i + 1, count + 1);
            currentCombination.pop_back();
        }
    };
    generate(0, 0);
    return result;
}

vector<Card> Background::clear() {
    vector<Card> backgroundCards = m_cards;
    m_cards.clear();
    return backgroundCards;
}

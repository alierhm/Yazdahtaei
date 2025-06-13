
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

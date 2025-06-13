
#include "CollectedCards.h"
#include "Card.h"
#include <format>
#include <iostream>
using namespace std;

void CollectedCards::insert(vector<Card> &cards) {
    m_cards.insert(m_cards.end(), cards.begin(), cards.end());
}

vector<Card> CollectedCards::getCards() {
    return m_cards;
}

void CollectedCards::setCards(const std::vector<Card> &cards) { m_cards = cards; }

void CollectedCards::fill(PartialDeck deck) {
    m_cards = get<vector<Card> >(deck);
}

void CollectedCards::show() {
    cout << format("Here are your collected cards:\n");
    if (m_cards.empty()) {
        cout << format("No collected cards!\n");
    } else {
        for (auto &card: m_cards) {
            card.toString();
            cout << "\n";
        }
    }
}


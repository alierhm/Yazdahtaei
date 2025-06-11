#include<iostream>
#include<format>
#include "CardsInHand.h"


void CardsInHand::fill(PartialDeck deck) {
    m_cards = std::get<std::vector<Card> >(deck);
}

void CardsInHand::show() {
    if (m_cards.empty()) {
        cout << format("No Cards in your hand\n");
    } else {
        cout << format("Here are the cards in your hand:\n");
        for (auto &card: m_cards) {
            card.toString();
            cout << "\n";
        }
    }
}

int CardsInHand::size() {
    return m_cards.size();
}

Card CardsInHand::getIthCard(int i) {
    return m_cards.at(i - 1);
}

Card CardsInHand::erase(int i) {
    Card card = m_cards.at(i - 1);
    m_cards.erase(m_cards.begin() + i - 1);
    return card;
}

void CardsInHand::assign(vector<Card> cards) {
    m_cards.assign(cards.begin(), cards.end());
}

void CardsInHand::insert(vector<Card> &cards) {
    m_cards.insert(m_cards.end(), cards.begin(), cards.end());
}

std::vector<Card> CardsInHand::getCards() const { return m_cards; }
void CardsInHand::setCards(const std::vector<Card> &cards) { m_cards = cards; }

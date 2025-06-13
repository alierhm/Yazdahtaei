
#include "Repository.h"
#include <fstream>
#include <random>
#include <vector>
#include <string>
using namespace std;


void Repository::fill(PartialDeck deck) {
    ifstream inFile{std::get<string>(deck), ios::in | ios::binary};
    m_cards.resize(52);
    if (inFile.good()) {
        inFile.read(reinterpret_cast<char *>(m_cards.data()), (m_cards.size() * sizeof(Card)));
        inFile.close();
    } else {        
        for (int i{0}; i < 4; ++i) {
            for (int j{0}; j < 13; ++j) {
                int n = j + 1;
                const Card card((i == 0) ? "Clubs" : (i == 1) ? "Diamonds" : (i == 2) ? "Hearts" : "Spades", n);
                m_cards.push_back(card);
            }
        }
        ofstream outFile{"fullRepository.dat", ios::out | ios::binary};
        outFile.write(reinterpret_cast<char *>(m_cards.data()),
                      static_cast<streamsize>(m_cards.size() * sizeof(Card)));
        outFile.close();
    }
}

void Repository::shuffleOut() {
    vector<Card> shuffledCards;
    while (!m_cards.empty()) {
        random_device rd;
        mt19937 g(rd());
        uniform_int_distribution<int> dist(0, m_cards.size() - 1);
        int randomIndex = dist(g);
        shuffledCards.push_back(m_cards.at(randomIndex));
        m_cards.erase(m_cards.begin() + randomIndex);
    }
    m_cards = shuffledCards;
}

vector<Card> Repository::get4FromDeck() {
    vector<Card> vectorOfSize4;
    for (int i{0}; i < 4; ++i) {
        vectorOfSize4.push_back(*(m_cards.rbegin() + i));
    }
    for (int i{0}; i<4 ; ++i) {
        m_cards.pop_back();
    }
    return vectorOfSize4;
}

void Repository::pushInTheMiddle(Card card) {
    m_cards.insert(m_cards.begin() + m_cards.size() / 2, card);
}

void Repository::push_back(Card card) {
    m_cards.push_back(card);
}
Card Repository::back() const{
    return m_cards.back();
}
bool Repository::empty() const {
    return m_cards.empty();
}
std::vector<Card> Repository::getAllCards() const {
    return m_cards;
}
void Repository::setCards(const std::vector<Card>& cards) { m_cards = cards; }
//
// Created by Ali on 6/12/2025.
//

#include "sumOfNumberOfCards.h"
#include <numeric>
int sumOfNumberOfCards(vector<Card> cards) {
    vector<int> cardNumbers;
    for (const auto &card : cards) {
        cardNumbers.push_back(card.getNumber());
    }
    int sum{accumulate(begin(cardNumbers), end(cardNumbers), 0, [](const auto &x, const auto &y) { return x + y; })};
    return sum;
}
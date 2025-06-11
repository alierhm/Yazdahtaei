#ifndef SUMOFNUMBEROFCARDS_H
#define SUMOFNUMBEROFCARDS_H
#pragma once
#include "Card.h"
#include <vector>
#include <numeric>
using namespace std;

inline int sumOfNumberOfCards(vector<Card> cards) {
    int sum{accumulate(begin(cards), end(cards), 0, [](const auto &x, const auto &y) { return x + y; })};
    return sum;
}
#endif //SUMOFNUMBEROFCARDS_H

//
// Created by Ali on 6/8/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include <string>
#include <string_view>

#include "CardsInHand.h"
#include "CollectedCards.h"

using namespace std;


class Player {
    string m_name;
    string m_username;
    string m_password;
    int m_score;
    int m_id;
    int m_surCount;
    CollectedCards m_collectedCards; // Cards collected by the player
    CardsInHand m_cardsInHand;
    int m_rank;
public:
    Player(int id = 0, string_view name = "", string_view username = "", string_view password = "");    
    void setName(string_view name);
    string getName();
    void setId(int& id);
    int getId();
    string getUsername();
    void setUsername(string_view username);
    string getPassword();
    void setPassword(string_view password);
    void setRank(int rank);
    int getRank();
    void assign_cards_in_hand(vector<Card> cards);
    int getScore() const;
    void showCardsInHand();
    int howManyCardsInHand();
    Card getIthCardInHand(int i);
    Card erase_Ith_Card_In_Hand(int i);
    void insertCollectedCards(vector<Card>& cards);
    void addScore(int score);
    void addSurCount();
    int getSurCount();
    vector<Card> getCollectedCards();
    vector<Card> getCardsInHand();
};


#endif //PLAYER_H

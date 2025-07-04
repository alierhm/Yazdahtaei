
#include "Player.h"

Player::Player(int id, string_view name, string_view username, string_view password) : m_name{name}, m_id{id}, m_score{0}, m_surCount{0}, m_rank{0}, m_username{username}, m_password{password}
{
}

void Player::setId(int &id)
{
    m_id = id;
}

int Player::getId()
{
    return m_id;
}

void Player::setName(string_view name)
{
    m_name = name;
}

void Player::assign_cards_in_hand(vector<Card> cards)
{
    m_cardsInHand.assign(cards);
}

int Player::getScore() const
{
    return m_score;
}

string Player::getName()
{
    return m_name;
}

void Player::showCardsInHand()
{
    m_cardsInHand.show();
}

int Player::howManyCardsInHand()
{
    return m_cardsInHand.size();
}

Card Player::getIthCardInHand(int i)
{
    return m_cardsInHand.getIthCard(i);
}

Card Player::erase_Ith_Card_In_Hand(int i)
{
    return m_cardsInHand.erase(i);
}

void Player::insertCollectedCards(vector<Card> &cards)
{
    m_collectedCards.insert(cards);
}

void Player::addScore(int score)
{
    m_score += score;
}

void Player::addSurCount()
{
    m_surCount++;
}

int Player::getSurCount()
{
    return m_surCount;
}

vector<Card> Player::getCollectedCards()
{
    return m_collectedCards.getCards();
}

void Player::setRank(int rank)
{
    m_rank = rank;
}

int Player::getRank()
{
    return m_rank;
}

string Player::getUsername()
{
    return m_username;
}

void Player::setUsername(string_view username)
{
    m_username = username;
}

string Player::getPassword()
{
    return m_password;
}

void Player::setPassword(string_view password)
{
    m_password = password;
}

vector<Card> Player::getCardsInHand()
{
    return m_cardsInHand.getCards();
}
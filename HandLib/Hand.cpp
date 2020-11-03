#include "Hand.h"

Hand::Hand()
{
}

Hand::Hand(const Hand& hand)
{
  this->cards = hand.cards;
}

int Hand::getValue()
{
  int res = 0;
  int aceCount = 0;
  for (int i = 0; i < cards.size(); i++) // all aces cost 11
  {
    res += cards[i].getValue();
    if (cards[i].getType() == Ace)
      aceCount++;
  }
  for (int i = 0; i < aceCount; i++) // aces may have the value 1 or 11
    if (res > 21)
      res -= 10;
    else
      break;
  return res;
}

bool Hand::isOverflowed()
{
  return this->getValue() > 21;
}

void Hand::addCard(const Card& card)
{
  this->cards.push_back(card);
}

void Hand::clear()
{
  this->cards.clear();
}

void Hand::openCard(int number)
{
  if (number >= 0 && number < this->cards.size())
    this->cards[number].open();
  else
    throw std::exception("Number of card out of hand size");
}

std::string Hand::toString()
{
  std::string res;
  for (int i = 0; i < cards.size(); i++)
  {
    res += (cards[i].toString() + " ");
  }
  return res;
}

Hand& Hand::operator=(const Hand& hand)
{
  if (this == &hand)
    return *this;
  this->cards = hand.cards;
  return *this;
}
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
  if (cards.size() == 2 && aceCount == 2)
    return 21;
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

Hand& Hand::operator=(const Hand& hand)
{
  if (this == &hand)
    return *this;
  this->cards = hand.cards;
  return *this;
}
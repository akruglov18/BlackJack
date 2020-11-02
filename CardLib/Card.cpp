#include "Card.h"
#include <algorithm>

Card::Card(int _value, int _suit) : Value(_value), Suit(_suit)
{
}

Card::Card(const Card& card)
{
  this->Value = card.Value;
  this->Suit = card.Suit;
}

int Card::getValue()
{
  if (this->Value == Ace)
    return 11;
  return std::min(10, this->Value);
}


int Card::getType()
{
  return this->Value;
}

int Card::getSuit()
{
  return this->Suit;
}

Card& Card::operator=(const Card& card)
{
  if (this == &card)
    return *this;
  this->Value = card.Value;
  this->Suit = card.Suit;
  return *this;
}
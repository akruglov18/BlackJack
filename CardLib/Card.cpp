#include "Card.h"
#include <algorithm>



Card::Card(int _value, int _suit, bool _isHidden) : Value(_value), Suit(_suit), isHidden(_isHidden)
{
}

Card::Card(const Card& card)
{
  this->Value = card.Value;
  this->Suit = card.Suit;
  this->isHidden = card.isHidden;
}

void Card::open()
{
  this->isHidden = false;
}

int Card::getValue() const
{
  if (this->Value == Ace)
    return 11;
  return std::min(10, this->Value);
}


int Card::getType() const
{
  return this->Value;
}

int Card::getSuit() const
{
  return this->Suit;
}

Card& Card::operator=(const Card& card)
{
  if (this == &card)
    return *this;
  this->Value = card.Value;
  this->Suit = card.Suit;
  this->isHidden = card.isHidden;
  return *this;
}

std::string Card::toString() const
{
  if (isHidden)
    return "**";
  std::string res;
  switch (Value) 
  {
  case Two:
    res += "2";
    break;
  case Three:
    res += "3";
    break;
  case Four:
    res += "4";
    break;
  case Five:
    res += "5";
    break;
  case Six:
    res += "6";
    break;
  case Seven:
    res += "7";
    break;
  case Eight:
    res += "8";
    break;
  case Nine:
    res += "9";
    break;
  case Ten:
    res += "10";
    break;
  case Jack:
    res += "J";
    break;
  case Queen:
    res += "Q";
    break;
  case King:
    res += "K";
    break;
  case Ace:
    res += "A";
    break;
  }

  switch (Suit)
  {
  case Diamonds:
    res += "D";
    break;
  case Spades:
    res += "S";
    break;
  case Clubs:
    res += "C";
    break;
  case Hearts:
    res += "H";
    break;
  }

  return res;
}

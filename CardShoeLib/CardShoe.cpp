#include "CardShoe.h"
#include <algorithm>
#include <stdexcept>

CardShoe::CardShoe(int _deckCount)
{
  this->deckCount = _deckCount;
  for (int i = 0; i < deckCount; i++)
  {
    for (int suit = Spades; suit <= Diamonds; suit++) // 4 suit
    {
      for (int value = Two; value <= Ace; value++)
      {
        Card card(value, suit);
        this->shoe.push_back(card);
      }
    }
  }
}

CardShoe::CardShoe(const CardShoe& _CardShoe)
{
  this->deckCount = _CardShoe.deckCount;
  this->shoe = _CardShoe.shoe;
}

void CardShoe::randomShuffle()
{
  random_shuffle(shoe.begin(), shoe.end());
}

void CardShoe::rebuild()
{
  CardShoe newDeck(this->deckCount);
  *this = newDeck;
}

int CardShoe::getSize()
{
  return shoe.size();
}

Card CardShoe::getCard(bool toOpen)
{
  if (!shoe.empty())
  {
    Card card = shoe.back();
    if(toOpen)
      card.open();
    shoe.pop_back();
    return card;
  }
  else
    throw new std::exception("CardShoe is empty");
}

CardShoe& CardShoe::operator=(const CardShoe& _CardShoe)
{
  if (this == &_CardShoe)
    return *this;
  this->deckCount = _CardShoe.deckCount;
  this->shoe = _CardShoe.shoe;
  return *this;
}
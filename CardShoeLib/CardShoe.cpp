#include "CardShoe.h"
#include <algorithm>
#include <stdexcept>

CardShoe::CardShoe(int _deckCount)
{

  this->deckCount = _deckCount;
  for (int i = 0; i < deckCount; i++)
  {
    for (int suit = 0; suit < 4; suit++) // 4 suit
    {
      for (int value = Two; value <= Ace; value++)
      {
        Card card(value, suit);
        this->decks.push_back(card);
      }
    }
  }
}

CardShoe::CardShoe(const CardShoe& _deck)
{
  this->deckCount = _deck.deckCount;
  this->decks = _deck.decks;
}

void CardShoe::randomShuffle()
{
  random_shuffle(decks.begin(), decks.end());
}

void CardShoe::rebuild()
{
  CardShoe newDeck(this->deckCount);
  *this = newDeck;
}

int CardShoe::getSize()
{
  return decks.size();
}

Card CardShoe::getCard()
{
  if (!decks.empty())
  {
    Card card = decks.back();
    decks.pop_back();
    return card;
  }
  else
    throw new std::exception("CardShoe is empty");
}

CardShoe& CardShoe::operator=(const CardShoe& _deck)
{
  if (this == &_deck)
    return *this;
  this->deckCount = _deck.deckCount;
  this->decks = _deck.decks;
  return *this;
}

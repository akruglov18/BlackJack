#include "Deck.h"
#include <algorithm>

Deck::Deck(int _deckCount)
{

  this->deckCount = _deckCount;
  for (int i = 0; i < deckCount; i++)
  {
    for (int suit = 0; suit < 4; suit++) // 4 suit
    {
      for (int value = Two; value <= Ace; value++)
      {
        Card card(value, suit);
        this->deck.push_back(card);
      }
    }
  }
}

Deck::Deck(const Deck& _deck)
{
  this->deckCount = _deck.deckCount;
  this->deck = _deck.deck;
}

void Deck::randomShuffle()
{
  random_shuffle(deck.begin(), deck.end());
}

void Deck::rebuild()
{
  Deck newDeck(this->deckCount);
  *this = newDeck;
}

int Deck::getSize()
{
  return deck.size();
}

Card Deck::getCard()
{
  if (!deck.empty())
  {
    Card card = deck.back();
    deck.pop_back();
    return card;
  }
  else
    throw new std::exception("Deck is empty");
}

Deck& Deck::operator=(const Deck& _deck)
{
  if (this == &_deck)
    return *this;
  this->deckCount = _deck.deckCount;
  this->deck = _deck.deck;
  return *this;
}

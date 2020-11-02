#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

using namespace std;

class Deck {
private:
  vector<Card> deck;
  int deckCount;
public:
  Deck(int _deckCount=1);
  Deck(const Deck& _deck);

  void randomShuffle();
  void rebuild();
  int getSize();
  Card getCard();

  Deck& operator=(const Deck& _deck);
};

#endif
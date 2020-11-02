#ifndef CARD_SHOE_H
#define CARD_SHOE_H

#include "Card.h"
#include <vector>

class CardShoe {
private:
  std::vector<Card> decks;
  int deckCount;
public:
  CardShoe(int _deckCount=1);
  CardShoe(const CardShoe& _deck);

  void randomShuffle();
  void rebuild();
  int getSize();
  Card getCard();

  CardShoe& operator=(const CardShoe& _deck);
};

#endif
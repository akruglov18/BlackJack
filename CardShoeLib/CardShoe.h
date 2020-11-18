#ifndef CARD_SHOE_H
#define CARD_SHOE_H

#include "Card.h"
#include <vector>

enum Visible : bool{
  Hide=false, Open = true
};

class CardShoe {
private:
  std::vector<Card> shoe;
  int deckCount;
  int minCount;
public:
  CardShoe(int _deckCount=1);
  CardShoe(const CardShoe& _CardShoe);

  void randomShuffle();
  void rebuild();
  bool isNeededRebuild();
  int getSize();
  Card getCard(bool toOpen);

  CardShoe& operator=(const CardShoe& _CardShoe);

};

#endif
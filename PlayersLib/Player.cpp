#include "Players.h"

bool Players::isBusted()
{
  return this->hand.isOverflowed();
}

void Players::takeCard(const Card& card)
{
  this->hand.addCard(card);
}

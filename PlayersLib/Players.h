#ifndef PLAYERS_H
#define PLAYERS_H

#include "Hand.h"
#include "Card.h"

class Players {
protected:
  Hand hand;
public:
  bool isBusted();
  void takeCard(const Card& card);
};

#endif
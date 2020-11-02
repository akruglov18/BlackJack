#ifndef DEALER_H
#define DEALER_H

#include <Players.h>
#include <CardShoe.h>

class Dealer : Players {
public:
  Card giveCard(CardShoe& _deck);
  //void buildDeck();
};

#endif

#ifndef DEALER_H
#define DEALER_H

#include <Players.h>
#include <Deck.h>

class Dealer : Players {
public:
  Card giveCard(Deck& _deck);
  //void buildDeck();
};

#endif

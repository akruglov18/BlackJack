#include "Dealer.h"

Card Dealer::giveCard(Deck& _deck)
{
  return _deck.getCard();
}

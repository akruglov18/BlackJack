#include "Dealer.h"

Card Dealer::giveCard(CardShoe& _deck)
{
  return _deck.getCard();
}

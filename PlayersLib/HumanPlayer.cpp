#include "HumanPlayer.h"
#include "EventHandler.h"

void HumanPlayer::makeTurn(CardShoe& cardShoe, Dealer& dealer)
{
  while(!this->isBusted() && this->getHandValue() != 21)
  {
    PlayerDecision decision = EventHandler::playerChoice();
    if (decision == PlayerDecision::Stand)
      return;
    if (decision == PlayerDecision::Hit)
    {
      this->takeCard(dealer.giveCard(cardShoe, Visible::Open));
    }
  }
}

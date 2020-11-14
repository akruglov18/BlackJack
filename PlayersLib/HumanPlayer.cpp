#include <HumanPlayer.h>
#include <EventHandler.h>

HumanPlayer::HumanPlayer(int _bank, std::string _name)
{
  this->bank = _bank;
  this->name = _name;
}

HumanPlayer::HumanPlayer(const HumanPlayer& _player)
{
  this->bank = _player.bank;
  this->hand = _player.hand;
  this->name = _player.name;
}

void HumanPlayer::makeTurn(CardShoe& cardShoe, Dealer& dealer)
{
  while(!this->isBusted() && this->getHand().getValue() != 21)
  {
    PlayerDecision decision = EventHandler::playerChoice();

    if (decision == PlayerDecision::Stand)
    {
      return;
    }
    if (decision == PlayerDecision::Hit)
    {
      this->takeCard(dealer.giveCard(cardShoe, Visible::Open));
    }
    if (decision == PlayerDecision::Double)
    {
      if (this->getBank() >= this->getBet().getValue()*2)
      {
        this->getBet().doubleBet();
        this->takeCard(dealer.giveCard(cardShoe, Visible::Open));
        return;
      }
      std::cout << "Lack of money"<<std::endl;
    }
  }
}

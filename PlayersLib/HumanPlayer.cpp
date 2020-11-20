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

void HumanPlayer::makeTurn(Dealer& dealer)
{
  if (this->getHand().hasBlackJack())
  {
    bool isPlayed = false;
    if (dealer.getFirstCard() == CardsValues::Ace)
    {
      if (EventHandler::offerToPayBlackJack())       // the situation when player has BJ
      {                                              // and dealer has Ace by first card
        isPlayed = true;                             // if he accept this offer 
        this->changeBank(this->getBet().getValue()); // he will get money 1 to 1 else he will try to get 3 to 2
      }
    }
    else
    {
      isPlayed = true;                                     // player has BJ
      this->changeBank(this->getBet().getValue() * 3 / 2); // and he can only take a money 3 to 2
    }
    if (isPlayed)
    {
      std::cout << this->makeGameResult(GameResult::BlackJack) << std::endl;
      this->clearHand();
      this->getBet().clearBet();
      EventHandler::updatePlayerState(*this);
      return;
    }
  }

  if (dealer.getFirstCard() == CardsValues::Ace && !this->getHand().hasBlackJack())
  {
    bool decision = EventHandler::offerInsurance();
    if (decision)
      this->getBet().makeInsurance();
  }
  while(!this->isBusted() && this->getHand().getValue() != 21)
  {
    PlayerDecision decision = EventHandler::playerChoice();

    if (decision == PlayerDecision::Double && this->getHand().size() > 2)
    {
      std::cout << "You can't double when your count of cards is bigger than 2" << std::endl;
      continue;
    }

    if (decision == PlayerDecision::Stand)
    {
      return;
    }
    if (decision == PlayerDecision::Hit)
    {
      this->takeCard(dealer.giveCard(Visible::Open));
    }
    if (decision == PlayerDecision::Double)
    {
      if (this->getBank() >= this->getBet().getValue()*2)
      {
        this->getBet().doubleBet();
        this->takeCard(dealer.giveCard(Visible::Open));
        return;
      }
      std::cout << "Lack of money"<<std::endl;
    }
  }
}

void HumanPlayer::makeBet()
{
  int playerBet = EventHandler::getBet(*this);
  this->getBet().makeBet(playerBet);
  EventHandler::updatePlayerState(*this);
}

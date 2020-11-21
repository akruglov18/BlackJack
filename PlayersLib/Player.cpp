#include "Player.h"
#include <Dealer.h>
#include <EventHandler.h>

Player::Player(int _bank, std::string _name)
{
  bank = _bank;
  name = _name;
}

Player::Player(const Player& player)
{
  bank = player.bank;
  hand = player.hand;
}

void Player::makeBet()
{
  getBet().makeBet(std::min(50, bank));
  EventHandler::updatePlayerState(*this);
}

void Player::makeTurn(Dealer& dealer)
{
  if (this->getHand().hasBlackJack())
  {
    if (dealer.getFirstCard() == CardsValues::Ace)
    {
      // get money 1 to 1
      this->changeBank(this->getBet().getValue());
    }
    else
    {
      this->changeBank(this->getBet().getValue() * 3 / 2); // take money 3 to 2
    }
    std::cout << this->makeGameResult(GameResult::BlackJack) << std::endl;
    this->clearHand();
    this->getBet().clearBet();
    EventHandler::updatePlayerState(*this);
    return;
  }
  while (getHand().getValue() < 17)
  {
    takeCard(dealer.giveCard(Visible::Open));
    EventHandler::updatePlayerState(*this);
  }
}

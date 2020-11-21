#include "Dealer.h"
#include "EventHandler.h"

Dealer::Dealer()
{
  name = "Dealer";
  bank = 0;
}

Dealer::Dealer(const Dealer& dealer)
{
  bank = dealer.bank;
  hand = dealer.hand;
  name = dealer.name;
  *(_CardShoe) = *(dealer._CardShoe);
}

Card Dealer::giveCard(bool toOpen)
{
  return _CardShoe->getCard(toOpen);
}

void Dealer::shuffleCardShoe()
{
  _CardShoe->randomShuffle();
}

void Dealer::setCardShoe(CardShoe& cardShoe)
{
  _CardShoe = &cardShoe;
}

void Dealer::dealCards(std::vector<IPlayer*> players)
{
  //cards to player
  for (int i = 0; i < 2; i++)
    for (int i = 0; i < players.size(); i++)
      players[i]->takeCard(this->giveCard(Visible::Open));

  bool FirstDealerCard = true;
  for (int i = 0; i < 2; i++)
  {
    if (FirstDealerCard)
    {
      FirstDealerCard = false;
      this->takeCard(this->giveCard( Visible::Open));
    }
    else
      this->takeCard(this->giveCard(Visible::Hide));
  }
}

void Dealer::openSecondCard()
{
  this->hand.openCard(1);
  EventHandler::updatePlayerState(*this);
}

int Dealer::getFirstCard() const
{
  return this->hand.getCardType(0);
}

void Dealer::playRound(CardShoe& _CardShoe, std::vector<IPlayer*> players)
{
  //start round
  for (int i = 0; i < players.size(); i++)
  {
    players[i]->makeBet();
  }
  this->dealCards(players);

  for (int i = 0; i < players.size(); i++) // all players turns
  {
    players[i]->makeTurn(*this);
  }

  if (EventHandler::isAllPlayersMakeTurn(players))
  {
    this->clearHand();
    return;
  }
  //dealer shows hidden card and dealer makes turn
  this->makeTurn(*this);

  // results of round
  for (int i = 0; i < players.size(); i++)
  {
    EventHandler::paymentStage(*this, players[i]);
    //waiting();
  }
  this->clearHand();
}

void Dealer::makeTurn(Dealer& dealer)
{
  this->openSecondCard();
  while (this->getHand().getValue() < 17)
  {
    this->takeCard(this->giveCard(Visible::Open));
  }
}

void Dealer::makeBet()
{
  this->getBet().makeBet(0);
}

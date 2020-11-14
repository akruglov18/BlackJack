#include "Dealer.h"
#include "EventHandler.h"

Dealer::Dealer(std::string _name)
{
  this->name = _name;
  this->bank = 0;
}

Dealer::Dealer(const Dealer& dealer)
{
  this->bank = dealer.bank;
  this->hand = dealer.hand;
  this->name = dealer.name;
}

Card Dealer::giveCard(CardShoe& _CardShoe, bool toOpen)
{
  return _CardShoe.getCard(toOpen);
}

void Dealer::shuffleCardShoe(CardShoe& _CardShoe)
{
  srand(time(0));
  _CardShoe.randomShuffle();
}

void Dealer::dealCards(CardShoe& _CardShoe, std::vector<IPlayer*> players)
{
  //cards to player
  for (int i = 0; i < 2; i++)
    for (int i = 0; i < players.size(); i++)
      players[i]->takeCard(this->giveCard(_CardShoe, Visible::Open));

  bool FirstDealerCard = true;
  for (int i = 0; i < 2; i++)
  {
    if (FirstDealerCard)
    {
      FirstDealerCard = false;
      this->takeCard(this->giveCard(_CardShoe, Visible::Open));
    }
    else
      this->takeCard(this->giveCard(_CardShoe, Visible::Hide));
  }
}

void Dealer::openSecondCard()
{
  this->hand.openCard(1);
  EventHandler::updatePlayerState(*this);
}

int Dealer::getFirstCard() const
{
  return this->hand.getCardValue(0);
}

void Dealer::playRound(CardShoe& _CardShoe, std::vector<IPlayer*> players)
{
  //start round
  for (int i = 0; i < players.size(); i++)
  {
    int playerBet = EventHandler::getBet(*players[i]);
    players[i]->getBet().makeBet(playerBet);
    EventHandler::updatePlayerState(*players[i]);
  }
  this->dealCards(_CardShoe, players);

  for (int i = 0; i < players.size(); i++) // all players turns
  {
    if (this->getFirstCard() == CardsValues::Ace)
    {
      bool decision = EventHandler::offerInsurance();
      if (decision)
        players[i]->getBet().makeInsurance();
    }
    players[i]->makeTurn(_CardShoe, *this);
  }
  //dealer shows hidden card and dealer makes turn
  this->makeTurn(_CardShoe, *this);

  // results of round
  for (int i = 0; i < players.size(); i++)
  {
    EventHandler::paymentStage(*this, players[i]);
    //waiting();
  }
  this->clearHand();
}

void Dealer::makeTurn(CardShoe& cardShoe, Dealer& dealer)
{
  this->openSecondCard();
  while (this->getHand().getValue() < 17)
  {
    this->takeCard(this->giveCard(cardShoe, Visible::Open));
  }
}


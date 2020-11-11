#include "Dealer.h"

Dealer::Dealer(const Dealer& dealer)
{
  this->hand = dealer.hand;
}

Card Dealer::giveCard(CardShoe& _CardShoe, bool toOpen)
{
  return _CardShoe.getCard(toOpen);
}

void Dealer::clearPlayersHands(std::vector<IPlayer*> players)
{
  this->clearHand();
  for (int i = 0; i < players.size(); i++)
    players[i]->clearHand();
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
}

void Dealer::playRound(CardShoe& _CardShoe, std::vector<IPlayer*> players)
{
  //start round
  this->dealCards(_CardShoe, players);

  for (int i = 0; i < players.size(); i++) // all players turn
  {
    players[i]->makeTurn(_CardShoe, *this);
  }

  //show dealer hidden card
  this->openSecondCard();

  // dealers turn
  this->makeTurn(_CardShoe, *this);
  //waiting();

  // results of round
  int DealerSum = this->getHandValue();
  bool isDealerBusted = this->isBusted();

  for (int i = 0; i < players.size(); i++)
  {
    IPlayer* player = players[i];
    int PlayerSum = player->getHandValue();
    bool isPlayerBusted = player->isBusted();

    GameResult res;
    if (isPlayerBusted)
      res = GameResult::Lose;
    else if (isDealerBusted || PlayerSum > DealerSum)
      res = GameResult::Win;
    else if (PlayerSum < DealerSum)
      res = GameResult::Lose;
    else
      res = GameResult::Push;

    std::cout<<player[i].makeGameResult(res)<<std::endl;
    //waiting();
  }
  this->clearPlayersHands(players);
}

void Dealer::makeTurn(CardShoe& cardShoe, Dealer& dealer)
{
  while (this->getHand().getValue() <= 17)
  {
    this->takeCard(this->giveCard(cardShoe, Visible::Open));
  }
}

Dealer& Dealer::operator=(const Dealer& dealer)
{
  if (this == &dealer)
    return *this;
  this->hand = dealer.hand;
  return *this;
}

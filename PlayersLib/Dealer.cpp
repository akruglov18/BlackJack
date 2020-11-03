#include "Dealer.h"

void waiting()
{
  std::cout << "Enter any key";
  getchar();
}

void Dealer::showAllHands(std::vector<Players*> players)
{
  for (int i = 0; i < players.size(); i++)
    std::cout << players[i]->getHand().toString() << std::endl;
  std::cout << this->getHand().toString() << std::endl;
}

Dealer::Dealer(const Dealer& dealer)
{
  this->hand = dealer.hand;
}

Card Dealer::giveCard(CardShoe& _CardShoe, bool toOpen)
{
  return _CardShoe.getCard(toOpen);
}

void Dealer::clearPlayersHands(std::vector<Players*> players)
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

void Dealer::dealCards(CardShoe& _CardShoe, std::vector<Players*> players)
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
  this->showAllHands(players);
}

void Dealer::openSecondCard()
{
  this->hand.openCard(1);
}

void Dealer::playRound(CardShoe& _CardShoe, std::vector<Players*> players)
{
  this->dealCards(_CardShoe, players);

  for (int i = 0; i < players.size(); i++) // all players turn
  {
    Players* player = players[i];
    while (!player->isBusted() && player->getHandValue() != 21)
    {
      PlayerDecision decision = player->getPlayerDecision();
      if (decision == PlayerDecision::Stand)
        break;
      if (decision == PlayerDecision::Hit)
      {
        player->takeCard(this->giveCard(_CardShoe, Visible::Open));
        system("cls");
        this->showAllHands(players);
      }
    }
  }

  //show dealer hidden card
  this->openSecondCard();
  system("cls");
  this->showAllHands(players);

  // dealers turn
  while (!this->isBusted() && this->getHandValue() != 21)
  {
    PlayerDecision dealerDecision = this->getPlayerDecision();
    if (dealerDecision == PlayerDecision::Stand)
      break;
    if (dealerDecision == PlayerDecision::Hit)
    {
      this->takeCard(this->giveCard(_CardShoe, Visible::Open));
      system("cls");
      this->showAllHands(players);
    }
  }

  waiting();

  // results of round

  int DealerSum = this->getHandValue();
  bool isDealerBusted = this->isBusted();

  for (int i = 0; i < players.size(); i++)
  {
    Players* player = players[i];
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

    waiting();
  }


  this->clearPlayersHands(players);
}

PlayerDecision Dealer::getPlayerDecision()
{
  if (this->hand.getValue() < 17)
    return PlayerDecision::Hit;
  else
    return PlayerDecision::Stand;
}

Dealer& Dealer::operator=(const Dealer& dealer)
{
  if (this == &dealer)
    return *this;
  this->hand = dealer.hand;
  return *this;
}

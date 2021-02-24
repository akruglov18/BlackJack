#include "EventHandler.h"
#include <iostream>
#include <string>
#include <Hand.h>


int EventHandler::getBet(const IPlayer& player)
{
  while (true)
  {
    std::cout << "Make a starting bet" << std::endl;
    int bet;
    std::cin >> bet;
    if (bet > 0 && bet<=player.getBank())
      return bet;
    else
      std::cout << "Incorrect number" << std::endl;
  }
}

PlayerDecision EventHandler::playerChoice()
{
  std::cout << "Your turn" << std::endl;
  while (true)
  {
    std::string decision;
    do 
    {
      std::getline(std::cin, decision);
    } while (decision.size() == 0);
    if (decision == "hit")
    {
      return PlayerDecision::Hit;
    }
    if (decision == "stand")
    {
      return PlayerDecision::Stand;
    }
    if (decision == "double")
    {
      return PlayerDecision::Double;
    }
    if (decision == "split")
    {
      return PlayerDecision::Split;
    }
    std::cout << "Incorrect command" << std::endl;
  }
}

bool EventHandler::offerInsurance()
{
  std::cout << "Make insurance?"<<std::endl;
  std::string decision;
  do
  {
    std::getline(std::cin, decision);
  } while (decision.empty());
  if (decision == "yes")
    return true;
  return false;
}

bool EventHandler::offerToPayBlackJack()
{
  std::cout << "Do you want to get your money 1 to 1?"<<std::endl;
  std::string decision;
  std::cin >> decision;
  if (decision == "yes")
    return true;
  return false;
}

void EventHandler::updatePlayerState(const IPlayer& player)
{
  std::cout << "##############" << std::endl; //# - 14 times
  std::cout << player.getName() << std::endl;
  if (player.getName() != "Dealer")
  {
    std::cout << "Money: " << player.getBank() << std::endl;
    std::cout << "Current bet: " << player.getBet().getValue() << std::endl;
  }
  std::cout << player.getHand().toString()<<"("<<player.getHand().getValue()<<")"<<std::endl;
  std::cout << std::endl;
  std::cout << "##############" << std::endl; //# - 14 times
}

void EventHandler::paymentStage(Dealer& dealer, IPlayer* player)
{
  if (player->getHand().size() == 0) // means that player has already played
    return;                         // he has got the money for a blackjack
  int DealerSum = dealer.getHand().getValue();
  bool isDealerBusted = dealer.isBusted();
  int PlayerSum = player->getHand().getValue();
  bool isPlayerBusted = player->isBusted();
  
  GameResult res;
  if (player->getHand().hasBlackJack() && !dealer.getHand().hasBlackJack()) // the situation where player has BJ
  {                                                                         // and dealer doesn't have BJ
    res = GameResult::BlackJack;                                            // but his first card was Ace
  }
  else
  {
    if (isPlayerBusted)
      res = GameResult::Lose;                            // player Lose
    else if (isDealerBusted || PlayerSum > DealerSum)
      res = GameResult::Win;                             //player Win
    else if (PlayerSum < DealerSum)
      res = GameResult::Lose;                            // player Lose
    else
      res = GameResult::Push;                            // push
  }

  if (player->getBet().wasInsurance())
    if (dealer.getHand().hasBlackJack())
      player->changeBank(player->getBet().getInsuranceValue() * 2);
    else
      player->changeBank(-player->getBet().getInsuranceValue());

  if (res == GameResult::BlackJack)
    player->changeBank(player->getBet().getValue() * 3 / 2); // 3 to 2

  if (res == GameResult::Lose)
    player->changeBank(-player->getBet().getValue());

  if (res == GameResult::Win)
    player->changeBank(player->getBet().getValue());

  if (res == GameResult::Push)
  {  //nothing
  }

  std::cout << player->makeGameResult(res) << std::endl;
  player->clearHand();
  player->getBet().clearBet();
  EventHandler::updatePlayerState(*player);
}

bool EventHandler::isAllPlayersMakeTurn(std::vector<IPlayer*>& players)
{
  for (int i = 0; i < players.size(); i++)
    if (players[i]->getHand().size() >= 2)
      return false;
  return true;
}

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

void EventHandler::updatePlayerState(const IPlayer& player)
{
  std::cout << "##############" << std::endl; //# - 14 times
  std::cout << player.getName() << std::endl;
  if (player.getName() != "Dealer")
  {
    std::cout << "Money: " << player.getBank() << std::endl;
    std::cout << "Current bet: " << player.getBet().getValue() << std::endl;
  }
  std::cout << player.getHand().toString()<<std::endl;
  std::cout << std::endl;
  std::cout << "##############" << std::endl; //# - 14 times
}

void EventHandler::paymentStage(Dealer& dealer, IPlayer* player)
{
  int DealerSum = dealer.getHand().getValue();
  bool isDealerBusted = dealer.isBusted();
  int PlayerSum = player->getHand().getValue();
  bool isPlayerBusted = player->isBusted();

  GameResult res;
  if (isPlayerBusted)
    res = GameResult::Lose;                            // player Lose
  else if (isDealerBusted || PlayerSum > DealerSum)
    res = GameResult::Win;                             //playerWin
  else if (PlayerSum < DealerSum)
    res = GameResult::Lose;                            // player Lose
  else
    res = GameResult::Push;                            // push

  if (res == GameResult::Lose)
  {
    player->changeBank(-player->getBet().getValue()); //negative number
  }
  if (res == GameResult::Win)
  {
    player->changeBank(player->getBet().getValue()); //positive number
  }
  if (res == GameResult::Push)
  {
    //nothing
  }

  std::cout << player->makeGameResult(res) << std::endl;
  player->clearHand();
  player->getBet().clearBet();
  EventHandler::updatePlayerState(*player);
}


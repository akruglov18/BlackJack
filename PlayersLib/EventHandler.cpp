#include "EventHandler.h"
#include <iostream>
#include <string>
#include <Hand.h>


PlayerDecision EventHandler::playerChoice()
{
  std::cout << "Your turn" << std::endl;
  while (true)
  {
    std::string decision;
    std::getline(std::cin, decision);
    if (decision == "hit")
    {
      return PlayerDecision::Hit;
    }
    if (decision == "stand")
    {
      return PlayerDecision::Stand;
    }
    if (decision == "split")
    {
      return PlayerDecision::Split;
    }
    std::cout << "Incorrect command" << std::endl;
  }
}

void EventHandler::playerTookCard(Hand& hand)
{
  std::cout << "##############" << std::endl; //# - 14 times
  std::cout << std::endl;
  std::cout << hand.toString()<<std::endl;
  std::cout << std::endl;
  std::cout << "##############" << std::endl; //# - 14 times
}

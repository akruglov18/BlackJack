#include "HumanPlayer.h"

PlayerDecision HumanPlayer::getPlayerDecision()
{
  while (true) 
  {
    std::cout << "Make a decision: hit or stand "<<std::endl;
    std::string decision;
    std::getline(std::cin, decision);
    if (decision == "stand")
      return PlayerDecision::Stand;
    else if (decision == "hit")
      return PlayerDecision::Hit;
    else
      std::cout << "Incorrect word"<<std::endl;
  }
}

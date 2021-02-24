#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "IPlayer.h"
#include <iostream>
#include <string>
#include <Dealer.h>

class HumanPlayer : public IPlayer {
public:
  HumanPlayer(int _bank, std::string _name = "Player");
  HumanPlayer(const HumanPlayer& player);
  void makeTurn(Dealer& dealer) override;
  void makeBet()override;

};
#endif // ! HUMAN_PLAYER_H

#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "IPlayer.h"
#include <iostream>
#include <string>
#include <Dealer.h>

class HumanPlayer : public IPlayer {
public:
  void makeTurn(CardShoe& cardShoe, Dealer& dealer) override;

};
#endif // ! HUMAN_PLAYER_H

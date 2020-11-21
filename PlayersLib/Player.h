#ifndef PLAYER_H
#define PLAYER_H

#include "IPlayer.h"

class Player : public IPlayer {
public:
  Player(int bank, std::string name);
  Player(const Player& player);
  void makeBet() override;
  void makeTurn(Dealer& dealer) override;
};

#endif
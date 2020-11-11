#ifndef PLAYER_H
#define PLAYER_H

#include "IPlayer.h"

class Player : public IPlayer {
public:
  Player();
  Player(const Player& player);

};

#endif
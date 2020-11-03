#include "Players.h"
#include "Player.h"

Player::Player()
{
}

Player::Player(const Player& player)
{
  this->hand = player.hand;
}
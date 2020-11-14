#include "IPlayer.h"
#include "Player.h"

Player::Player()
{
  bank = 0;
}

Player::Player(const Player& player)
{
  this->bank = player.bank;
  this->hand = player.hand;
}
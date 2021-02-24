#include"IPlayer.h"
#include "EventHandler.h"

bool IPlayer::isBusted() const
{
  return this->hand.isOverflowed();
}

void IPlayer::takeCard(const Card& card)
{
  this->hand.addCard(card);
  EventHandler::updatePlayerState(*this);
}

void IPlayer::clearHand()
{
  this->hand.clear();
}

Hand IPlayer::getHand() const
{
  return this->hand;
}

Bet& IPlayer::getBet()
{
  return this->bet;
}

const Bet& IPlayer::getBet() const
{
  return this->bet;
}

int IPlayer::getBank() const
{
  return this->bank;
}

std::string IPlayer::getName() const
{
  return this->name;
}

void IPlayer::changeBank(int added)
{
  this->bank += added;
}

std::string IPlayer::makeGameResult(const GameResult& game_res) const
{
  switch (game_res)
  {
  case BlackJack:
    return "BlackJack";
  case Push:
    return "Draw";
  case Lose:
    return "Lose";
  case Win:
    return "Victory";
  default:
    throw new std::exception("Unexpected Game Result");
  }
}



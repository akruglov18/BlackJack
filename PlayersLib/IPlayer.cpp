#include"IPlayer.h"
#include "EventHandler.h"

bool IPlayer::isBusted()
{
  return this->hand.isOverflowed();
}

void IPlayer::takeCard(const Card& card)
{
  this->hand.addCard(card);
  EventHandler::playerTookCard(this->hand);
}

void IPlayer::clearHand()
{
  this->hand.clear();
}

int IPlayer::getHandValue()
{
  return this->hand.getValue();
}

Hand IPlayer::getHand()
{
  return this->hand;
}

std::string IPlayer::makeGameResult(const GameResult& game_res)
{
  switch (game_res)
  {
  case Push:
    return "Draw";
  case Lose:
    return "Lose";
  case Win:
    return "Victory";
  default:
    throw new std::exception("Strange game result");
  }
}



#include"Players.h"

bool Players::isBusted()
{
  return this->hand.isOverflowed();
}

void Players::takeCard(const Card& card)
{
  this->hand.addCard(card);
}

void Players::clearHand()
{
  this->hand.clear();
}

int Players::getHandValue()
{
  return this->hand.getValue();
}

Hand Players::getHand()
{
  return this->hand;
}

std::string Players::makeGameResult(const GameResult& game_res)
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



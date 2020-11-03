#ifndef PLAYERS_H
#define PLAYERS_H

#include "Hand.h"
#include "Card.h"

enum PlayerDecision{ 
  Stand, Hit, Double, Split
};

enum GameResult {
  Push, Lose, Win
};

class Players {
protected:
  Hand hand;
public:
  bool isBusted();
  void takeCard(const Card& card);
  void clearHand();
  int getHandValue();
  Hand getHand();
  virtual PlayerDecision getPlayerDecision() = 0;
  virtual std::string makeGameResult(const GameResult& game_res);
};

#endif
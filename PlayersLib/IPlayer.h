#ifndef IPLAYER_H
#define IPLAYER_H

#include "Hand.h"
#include "Card.h"
#include <CardShoe.h>

class Dealer;

enum GameResult {
  Push, Lose, Win
};

class IPlayer {
protected:
  Hand hand;
public:
  bool isBusted();
  void takeCard(const Card& card);
  void clearHand();
  int getHandValue();
  Hand getHand();
  virtual std::string makeGameResult(const GameResult& game_res);
  virtual void makeTurn(CardShoe& cardShoe, Dealer& dealer) = 0;
};

#endif
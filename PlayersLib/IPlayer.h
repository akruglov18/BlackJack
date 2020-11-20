#ifndef IPLAYER_H
#define IPLAYER_H

#include <Hand.h>
#include <Card.h>
#include <CardShoe.h>
#include <Bet.h>

class Dealer;

enum GameResult {
  Push, Lose, Win, BlackJack
};

class IPlayer {
protected:
  std::string name;
  int bank;
  Bet bet;
  Hand hand;
public:
  bool isBusted() const;
  void takeCard(const Card& card);
  void clearHand();
  Hand getHand() const;
  Bet& getBet();
  const Bet& getBet() const;
  int getBank() const;
  std::string getName() const;
  void changeBank(int added);
  virtual void makeBet() = 0;
  virtual std::string makeGameResult(const GameResult& game_res) const;
  virtual void makeTurn(Dealer& dealer) = 0;
};

#endif
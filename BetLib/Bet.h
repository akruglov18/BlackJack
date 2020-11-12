#pragma once

class Bet {
private:
  int currentBet;
public:
  Bet();
  Bet(const Bet& bet);
  void makeBet(int bet);
  void increaseBet(int bet);
  void doubleBet();
  int getValue() const;
  void clearBet();
};
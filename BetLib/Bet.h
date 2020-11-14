#pragma once

class Bet {
private:
  int currentBet;
public:
  Bet(int bet=0);
  Bet(const Bet& bet);
  void makeBet(int bet);
  void doubleBet();
  int getValue() const;
  void clearBet();
};
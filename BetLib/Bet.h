#pragma once

class Bet {
private:
  int currentBet;
  int insuranceBet;
public:
  Bet(int bet=0);
  Bet(const Bet& bet);
  void makeBet(int bet);
  void makeInsurance();
  bool wasInsurance();
  void doubleBet();
  int getValue() const;
  int getInsuranceValue() const;
  void clearBet();
};
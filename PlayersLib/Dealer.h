#ifndef DEALER_H
#define DEALER_H

#include "IPlayer.h"
#include "CardShoe.h"
#include <iostream>
#include <ctime>
#include <string>

class Dealer : public IPlayer {
private:
  CardShoe* _CardShoe;
public:
  Dealer();
  Dealer(const Dealer& dealer);
  Card giveCard(bool toOpen);
  void shuffleCardShoe();
  void setCardShoe(CardShoe& cardShoe);
  void dealCards(std::vector<IPlayer*> players);
  void openSecondCard();
  int getFirstCard() const;
  void playRound(CardShoe& _CardShoe, std::vector<IPlayer*> players);
  void makeTurn(Dealer& dealer) override;
  void makeBet() override;
};

#endif

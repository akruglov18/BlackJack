#ifndef DEALER_H
#define DEALER_H

#include "IPlayer.h"
#include "CardShoe.h"
#include <iostream>
#include <ctime>
#include <string>

class Dealer : public IPlayer {
public:
  Dealer(std::string _name = "Dealer");
  Dealer(const Dealer& dealer);
  Card giveCard(CardShoe& _CardShoe, bool toOpen);
  void shuffleCardShoe(CardShoe& _CardShoe);
  void dealCards(CardShoe& _CardShoe, std::vector<IPlayer*> players);
  void openSecondCard();
  int getFirstCard() const;
  void playRound(CardShoe& _CardShoe, std::vector<IPlayer*> players);
  void makeTurn(CardShoe& cardShoe, Dealer& dealer) override;
};

#endif

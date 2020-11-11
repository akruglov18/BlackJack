#ifndef DEALER_H
#define DEALER_H

#include "IPlayer.h"
#include "CardShoe.h"
#include <iostream>
#include <ctime>

class Dealer : public IPlayer {
public:
  Dealer() {};
  Dealer(const Dealer& dealer);
  Card giveCard(CardShoe& _CardShoe, bool toOpen);
  void clearPlayersHands(std::vector<IPlayer*> players);
  void shuffleCardShoe(CardShoe& _CardShoe);
  void dealCards(CardShoe& _CardShoe, std::vector<IPlayer*> players);
  void openSecondCard();
  void playRound(CardShoe& _CardShoe, std::vector<IPlayer*> players);
  void makeTurn(CardShoe& cardShoe, Dealer& dealer) override;
  Dealer& operator=(const Dealer& dealer);
};

#endif

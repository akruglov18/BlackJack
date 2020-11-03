#ifndef DEALER_H
#define DEALER_H

#include "Players.h"
#include "Player.h"
#include "CardShoe.h"
#include <iostream>
#include <ctime>

class Dealer : public Players {
private:
  void showAllHands(std::vector<Players*> players);
public:
  Dealer() {};
  Dealer(const Dealer& dealer);
  Card giveCard(CardShoe& _CardShoe, bool toOpen);
  void clearPlayersHands(std::vector<Players*> players);
  void shuffleCardShoe(CardShoe& _CardShoe);
  void dealCards(CardShoe& _CardShoe, std::vector<Players*> players);
  void openSecondCard();
  void playRound(CardShoe& _CardShoe, std::vector<Players*> players);
  PlayerDecision getPlayerDecision() override;
  Dealer& operator=(const Dealer& dealer);
};

#endif

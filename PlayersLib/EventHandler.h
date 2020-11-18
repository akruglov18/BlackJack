#pragma once

#include<Hand.h>
#include<IPlayer.h>
#include<Dealer.h>
#include<Player.h>

enum PlayerDecision {
  Hit = 0, Stand, Double, Split
};

class EventHandler {
public:
  static int getBet(const IPlayer& player);
  static PlayerDecision playerChoice();
  static bool offerInsurance();
  static bool offerToPayBlackJack();
  static void updatePlayerState(const IPlayer& player);
  static void paymentStage(Dealer& dealer, IPlayer* player);
  static bool isAllPlayersMakeTurn(std::vector<IPlayer*>& players);
};
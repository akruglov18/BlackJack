#pragma once

enum PlayerDecision {
  Hit = 0, Stand, Split
};

class EventHandler {
public:
  static PlayerDecision playerChoice();
  static void playerTookCard( Hand& hand);
};
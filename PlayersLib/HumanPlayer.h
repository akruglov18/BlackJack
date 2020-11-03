#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "Players.h"
#include <iostream>
#include <string>

class HumanPlayer : public Players {
public:
  PlayerDecision getPlayerDecision() override;

};
#endif // ! HUMAN_PLAYER_H

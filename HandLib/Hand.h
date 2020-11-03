#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <vector>

class Hand {
private:
  std::vector<Card> cards;
public:
  Hand();
  Hand(const Hand& hand);
  int getValue();
  bool isOverflowed();
  void addCard(const Card& card);
  void clear();
  void openCard(int number);
  std::string toString();

  Hand& operator=(const Hand& hand);
};

#endif // ! HAND_H
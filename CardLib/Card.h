#ifndef CARD_H
#define CARD_H

#include <string>

enum Suits{ Spades = 0, Hearts, Clubs, Diamonds };

enum CardsValues { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, 
  Ace};

class Card {
private:
  int Suit;
  int Value;
  bool isHidden;
public:
  Card(int _value, int _suit = 0, bool _isHidden = true);
  Card(const Card& card);

  void open();
  int getValue() const;
  int getSuit() const;
  int getType() const;
  
  Card& operator=(const Card& card);

  std::string toString() const;
};

#endif
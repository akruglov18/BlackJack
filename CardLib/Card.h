#ifndef CARD_H
#define CARD_H

enum Suits{ Spades = 0, Hearts, Clubs, Diamonds };
enum Values { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, 
  Ace};

class Card {
private:
  int Suit;
  int Value;
public:
  Card(int _value, int _suit = 0);
  Card(const Card& card);

  int getValue();
  int getSuit();
  int getType();
  
  Card& operator=(const Card& card);
};

#endif
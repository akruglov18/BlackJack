#include"Dealer.h"
#include"Player.h"
#include"Deck.h"
#include<vector>

class Game {
private:
  Dealer dealer;
  std::vector<Player> players;
  CardShoe deck;
public:
  Game(int countPlayers);
};
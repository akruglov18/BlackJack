#include"Dealer.h"
#include"Player.h"
#include"CardShoe.h"
#include<vector>

class Game {
private:
  Dealer dealer;
  std::vector<Players*> players;
  CardShoe cardShoe;
public:
  Game(int deckCount = 4);

  void addPlayer(Players* player);
  CardShoe& getCardShoe();

  void PlayGame();
};
#include"Game.h"

Game::Game(int deckCount)
{
  this->cardShoe = *(new CardShoe(deckCount));
}

void Game::addPlayer(IPlayer* player)
{
  players.push_back(player);
}

CardShoe& Game::getCardShoe()
{
  return this->cardShoe;
}

void Game::PlayGame()
{
  srand(time(0));
  dealer.setCardShoe(this->cardShoe);
  dealer.shuffleCardShoe();
  while (true)
  {
    if (cardShoe.isNeededRebuild())
      cardShoe.rebuild();
    dealer.playRound(cardShoe, players);
  }
}

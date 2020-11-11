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
  dealer.shuffleCardShoe(cardShoe);

  while (true)
  {
    dealer.playRound(cardShoe, players);
  }
}

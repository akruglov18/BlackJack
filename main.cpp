#include <iostream>
#include <Game.h>
#include <HumanPlayer.h>
#include <Player.h>

using namespace std;

int main(){
  Game table(4);
  table.addPlayer(new HumanPlayer(500, "Player"));
  table.addPlayer(new Player(500, "Bot"));
  table.PlayGame();
}
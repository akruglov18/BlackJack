#include <iostream>
#include <Game.h>
#include <HumanPlayer.h>

using namespace std;

int main(){
  Game table(4);
  table.addPlayer(new HumanPlayer(500));
  table.PlayGame();
}
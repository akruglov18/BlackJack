#include <Bet.h>

Bet::Bet(int bet)
{
	this->currentBet = bet;
}

Bet::Bet(const Bet& bet)
{
	this->currentBet = bet.currentBet;
}

void Bet::makeBet(int bet)
{
	this->currentBet += bet;
}

void Bet::doubleBet()
{
	this->currentBet *= 2;
}

int Bet::getValue() const
{
	return this->currentBet;
}

void Bet::clearBet()
{
	this->currentBet = 0;
}

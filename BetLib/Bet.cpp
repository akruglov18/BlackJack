#include <Bet.h>

Bet::Bet(int bet)
{
	this->currentBet = bet;
	this->insuranceBet = 0;
}

Bet::Bet(const Bet& bet)
{
	this->currentBet = bet.currentBet;
	this->insuranceBet = 0;
}

void Bet::makeBet(int bet)
{
	this->currentBet += bet;
}

void Bet::makeInsurance()
{
	this->insuranceBet = currentBet / 2;
}

bool Bet::wasInsurance()
{
	return insuranceBet > 0;
}

void Bet::doubleBet()
{
	this->currentBet *= 2;
}

int Bet::getValue() const
{
	return this->currentBet;
}

int Bet::getInsuranceValue() const
{
	return this->insuranceBet;
}

void Bet::clearBet()
{
	this->currentBet = 0;
	this->insuranceBet = 0;
}

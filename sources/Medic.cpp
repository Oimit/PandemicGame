#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Medic.hpp"
using namespace std;
using namespace pandemic;

Player &Medic::treat(City c)
{
	if (mCurrentCity != c)
	{
		throw invalid_argument("player dosen't in the city.");
	}
	if (mBoard[c] == 0)
	{
		throw invalid_argument("There are 0 infections in that city.");
	}
	mBoard[c] = 0;
	return *this;
}

void Medic::cureCurrentCity()
{
	if (mBoard.isCured(mBoard.getColor(mCurrentCity)))
	{
		mBoard[mCurrentCity] = 0;
	}
}
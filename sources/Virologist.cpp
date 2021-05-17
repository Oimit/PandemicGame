#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Virologist.hpp"
using namespace std;
using namespace pandemic;

Player &Virologist::treat(City c)
{
	if (c != mCurrentCity && mPlayerCards.find(c) == mPlayerCards.end())
	{
		throw invalid_argument("cann't treat city that not contain in the cards");
	}
	if (mBoard[c] == 0)
	{
		throw invalid_argument("There are 0 infections in that city.");
	}

	Color col = mBoard.getColor(c);
	if (mBoard.isCured(col))
	{
		mBoard[c] = 0;
	}
	else
	{
		mBoard[c]--;
	}
	return *this;
}

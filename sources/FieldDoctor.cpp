#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;

Player &FieldDoctor::treat(City c)
{
	if (c != mCurrentCity && !mBoard.isCitiesConnected(mCurrentCity, c))
	{
		throw invalid_argument("City is not connected");
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

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Scientist.hpp"
using namespace std;
using namespace pandemic;

Player &Scientist::discover_cure(Color col)
{
	if (!mBoard.isStationExists(mCurrentCity))
	{
		throw invalid_argument("current city dosen't contain resaerchStation");
	}
	int counter = 0;
	for (const auto &t : mPlayerCards)
	{
		if (mBoard.getColor(t) == col)
		{
			counter++;
		}
	}
	if (counter < num)
	{
		throw invalid_argument("player dosen't have a minimum 5 cards of that color");
	}
	if (!mBoard.isCured(col))
	{
		int counter = 1;
		auto it = mPlayerCards.begin();
		while (it != mPlayerCards.end())
		{
			if (mBoard.getColor(*it) == col)
			{
				it = mPlayerCards.erase(it);
				counter++;
				if (counter == num)
				{
					break;
				}
			}
			else
			{
				++it;
			}
		}
		mBoard.addCureColor(col);
	}
	return *this;
}

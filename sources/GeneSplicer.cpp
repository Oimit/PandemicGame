#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;
const int MINIMUM_CARDS_TO_DISCOVER_CURE = 5;

Player &GeneSplicer::discover_cure(Color col)
{
	if (!mBoard.isStationExists(mCurrentCity))
	{
		throw invalid_argument("current city dosen't contain resaerchStation");
	}
	if (mPlayerCards.size() < MINIMUM_CARDS_TO_DISCOVER_CURE)
	{
		throw invalid_argument("player dosen't have a minimum 5 cards of that color");
	}
	if (!mBoard.isCured(col))
	{
		int counter = 1;
		auto it = mPlayerCards.begin();
		while (it != mPlayerCards.end())
		{
			it = mPlayerCards.erase(it);
			counter++;
			if (counter == MINIMUM_CARDS_TO_DISCOVER_CURE)
			{
				break;
			}
			++it;
		}
		mBoard.addCureColor(col);
	}
	return *this;
}

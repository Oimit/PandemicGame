#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
using namespace std;
using namespace pandemic;
const int MINIMUM_CARDS_TO_DISCOVER_CURE = 5;

Player &Researcher::discover_cure(Color col)
{
	int counter = 0;
	for (const auto &t : mPlayerCards)
	{
		if (mBoard.getColor(t) == col)
		{
			counter++;
		}
	}
	if (counter < MINIMUM_CARDS_TO_DISCOVER_CURE)
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
				if (counter == MINIMUM_CARDS_TO_DISCOVER_CURE)
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
#include "Player.hpp"
#include <iostream>

using namespace pandemic;
using namespace std;
const int MINIMUM_CARDS_TO_DISCOVER_CURE = 5;

Player &Player::drive(City c)
{
	if (mCurrentCity == c)
	{
		throw invalid_argument("You are already in that city.");
	}
	if (mBoard.isCitiesConnected(mCurrentCity, c))
	{
		mCurrentCity = c;
	}
	else
	{
		throw invalid_argument("This cities aren't connected.");
	}
	cureCurrentCity();
	return *this;
}

Player &Player::fly_direct(City city)
{
	if (!(mPlayerCards.find(city) != mPlayerCards.end()))
	{
		throw invalid_argument("city dosen't contain in player cards");
	}
	mCurrentCity = city;
	mPlayerCards.erase(city);
	cureCurrentCity();
	return *this;
}

Player &Player::fly_charter(City c)
{
	if (!(mPlayerCards.find(mCurrentCity) != mPlayerCards.end()))
	{
		throw invalid_argument("city dosen't contain in player cards");
	}
	mPlayerCards.erase(mCurrentCity);
	mCurrentCity = c;
	cureCurrentCity();
	return *this;
}

Player &Player::fly_shuttle(City c)
{
	if (mCurrentCity == c)
	{
		throw invalid_argument("cannot flight to the same city");
	}
	if ((mBoard.isStationExists(mCurrentCity)) && (mBoard.isStationExists(c)))
	{
		mCurrentCity = c;
	}
	else
	{
		throw invalid_argument("city dosen't have reaserch station.");
	}
	cureCurrentCity();
	return *this;
}

Player &Player::build()
{
	if (!(mPlayerCards.find(mCurrentCity) != mPlayerCards.end()))
	{
		throw invalid_argument("city dosen't have reaserch station1.");
	}
	if (mBoard.isStationExists(mCurrentCity))
	{
		return *this;
	}
	mBoard.buildResearchStation(mCurrentCity);
	mPlayerCards.erase(mCurrentCity);
	return *this;
}

Player &Player::discover_cure(Color col)
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
	if (counter < MINIMUM_CARDS_TO_DISCOVER_CURE)
	{
		throw invalid_argument("player dosen't have a minimum 5 cards of that color");
	}
	if (!mBoard.isCured(col))
	{
		int counter = 1;
		auto itr = mPlayerCards.begin();
		while (itr != mPlayerCards.end())
		{
			if (mBoard.getColor(*itr) == col)
			{
				itr = mPlayerCards.erase(itr);
				counter++;
				if (counter == MINIMUM_CARDS_TO_DISCOVER_CURE)
				{
					break;
				}
			}
			else
			{
				++itr;
			}
		}
		mBoard.addCureColor(col);
	}
	return *this;
}

Player &Player::treat(City c)
{
	if (mCurrentCity != c)
	{
		throw invalid_argument("player dosen't in the city.");
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

Player &Player::take_card(City c)
{
	mPlayerCards.insert(c);
	return *this;
}

Board Player::getBoard()
{
	return mBoard;
}
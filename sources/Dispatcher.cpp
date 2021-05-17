#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;

Player &Dispatcher::fly_direct(City city)
{
	if (city == mCurrentCity)
	{
		throw invalid_argument("Cann't fly from same city");
	}
	if (mBoard.isStationExists(mCurrentCity))
	{
		mCurrentCity = city;
	}
	else
	{
		Player::fly_direct(city);
	}
	return *this;
}
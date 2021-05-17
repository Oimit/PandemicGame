#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "OperationsExpert.hpp"
using namespace std;
using namespace pandemic;

Player &OperationsExpert::build()
{
	mBoard.buildResearchStation(mCurrentCity);
	return *this;
}

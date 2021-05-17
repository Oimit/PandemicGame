#pragma once
#include <string>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
using namespace std;

namespace pandemic
{
    class Dispatcher : public Player
    {
    public:
        Dispatcher(Board &b, City c) : Player(b, c, "Dispatcher") {}
        Player &fly_direct(City c);
    };
}
#pragma once
#include <string>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic
{
    class Scientist : public Player
    {
    private:
        int num;

    public:
        Scientist(Board &b, City c, int n) : Player(b, c, "Scientist"), num(n) {}
        Player &discover_cure(Color col);
    };
}
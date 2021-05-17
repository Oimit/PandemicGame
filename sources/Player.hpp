#pragma once
#include "Board.hpp"
#include "Color.hpp"

#include <string>
#include <set>
using namespace std;

namespace pandemic
{
    class Player
    {
    protected:
        Board &mBoard;
        City mCurrentCity;
        string mPlayerRole;
        set<City> mPlayerCards;

    public:
        Player(Board &b, City c, string r) : mBoard(b), mCurrentCity(c), mPlayerRole(r){};
        Player(Board &b, City c) : mBoard(b), mCurrentCity(c){};
        virtual Player &drive(City c);
        virtual Player &fly_direct(City c);
        virtual Player &fly_charter(City c);
        virtual Player &fly_shuttle(City c);
        virtual Player &build();
        virtual Player &discover_cure(Color col);
        virtual Player &treat(City c);
        string role()
        {
            return mPlayerRole;
        }
        virtual Player &take_card(City);
        virtual void cureCurrentCity(){};
        Board getBoard();
    };
}
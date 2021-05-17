#pragma once

#include "City.hpp"
#include <ostream>
#include <map>
#include "Color.hpp"
#include <string>
#include <set>
using namespace std;

namespace pandemic
{
  class Board
  {

  private:
    map<City, Color> mColorCity;
    map<City, set<City>> mConnectionsMap;
    map<City, int> mLevelDisease;
    set<City> mResaerchStations;
    set<Color> mCuredColors;

  public:
    Board();
    int &operator[](City c);
    friend ostream &operator<<(ostream &os, const Board &b);
    bool is_clean();
    void remove_cures();
    void remove_stations();
    void buildResearchStation(City city);
    bool isStationExists(City city);
    bool isCitiesConnected(City &c1, City &c2);
    Color getColor(City city);
    void addCureColor(Color color);
    bool isCured(Color color);
  };
}
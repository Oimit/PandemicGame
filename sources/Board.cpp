#include "Board.hpp"
#include <map>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
using namespace pandemic;

inline City fromStringCity(string const &city)
{
	if (city == "Algiers")
	{
		return Algiers;
	}
	if (city == "Atlanta")
	{
		return Atlanta;
	}
	if (city == "Baghdad")
	{
		return Baghdad;
	}
	if (city == "Bangkok")
	{
		return Bangkok;
	}
	if (city == "Beijing")
	{
		return Beijing;
	}
	if (city == "Bogota")
	{
		return Bogota;
	}
	if (city == "BuenosAires")
	{
		return BuenosAires;
	}
	if (city == "BuenosAires")
	{
		return BuenosAires;
	}
	if (city == "Cairo")
	{
		return Cairo;
	}
	if (city == "Chennai")
	{
		return Chennai;
	}
	if (city == "Chicago")
	{
		return Chicago;
	}
	if (city == "Delhi")
	{
		return Delhi;
	}
	if (city == "Essen")
	{
		return Essen;
	}
	if (city == "HoChiMinhCity")
	{
		return HoChiMinhCity;
	}
	if (city == "HongKong")
	{
		return HongKong;
	}
	if (city == "Istanbul")
	{
		return Istanbul;
	}
	if (city == "Jakarta")
	{
		return Jakarta;
	}
	if (city == "Johannesburg")
	{
		return Johannesburg;
	}
	if (city == "Karachi")
	{
		return Karachi;
	}
	if (city == "Khartoum")
	{
		return Khartoum;
	}
	if (city == "Kinshasa")
	{
		return Kinshasa;
	}
	if (city == "Lagos")
	{
		return Lagos;
	}
	if (city == "Kolkata")
	{
		return Kolkata;
	}
	if (city == "Lima")
	{
		return Lima;
	}
	if (city == "London")
	{
		return London;
	}
	if (city == "LosAngeles")
	{
		return LosAngeles;
	}
	if (city == "Madrid")
	{
		return Madrid;
	}
	if (city == "MexicoCity")
	{
		return MexicoCity;
	}
	if (city == "Miami")
	{
		return Miami;
	}
	if (city == "Milan")
	{
		return Milan;
	}
	if (city == "Montreal")
	{
		return Montreal;
	}
	if (city == "Manila")
	{
		return Manila;
	}
	if (city == "Moscow")
	{
		return Moscow;
	}
	if (city == "Mumbai")
	{
		return Mumbai;
	}
	if (city == "Manila")
	{
		return Manila;
	}
	if (city == "NewYork")
	{
		return NewYork;
	}
	if (city == "Osaka")
	{
		return Osaka;
	}
	if (city == "Paris")
	{
		return Paris;
	}
	if (city == "Riyadh")
	{
		return Riyadh;
	}
	if (city == "SanFrancisco")
	{
		return SanFrancisco;
	}
	if (city == "Santiago")
	{
		return Santiago;
	}
	if (city == "SaoPaulo")
	{
		return SaoPaulo;
	}
	if (city == "Seoul")
	{
		return Seoul;
	}
	if (city == "Shanghai")
	{
		return Shanghai;
	}
	if (city == "StPetersburg")
	{
		return StPetersburg;
	}
	if (city == "Sydney")
	{
		return Sydney;
	}
	if (city == "Taipei")
	{
		return Taipei;
	}
	if (city == "Tehran")
	{
		return Tehran;
	}
	if (city == "Tokyo")
	{
		return Tokyo;
	}
	if (city == "Washington")
	{
		return Washington;
	}
	return Washington;
}

inline Color fromStringColor(string const &color)
{

	if (color == "Yellow")
	{
		return Yellow;
	}
	if (color == "Blue")
	{
		return Blue;
	}
	if (color == "Black")
	{
		return Black;
	}
	if (color == "Red")
	{
		return Red;
	}
	return Red;
}

Board::Board()
{
	ifstream file{"cities_map.txt"};
	if (file.is_open())
	{
		string mainCity;
		string color;
		string mConnectionToMainCity;
		string connectedCities;
		City mainCityEnum = Miami;

		while (!file.eof())
		{
			file >> mainCity >> color;
			mainCityEnum = fromStringCity(mainCity);
			mColorCity.insert({mainCityEnum, fromStringColor(color)});
			set<City> conc;
			mLevelDisease.insert({mainCityEnum, 0});
			getline(file, mConnectionToMainCity);
			stringstream lineStreamer;
			lineStreamer << mConnectionToMainCity;
			while (lineStreamer >> connectedCities)
			{
				mConnectionsMap[mainCityEnum].insert(fromStringCity(connectedCities));
			}
			conc.clear();
		}
	}
	else
	{
		throw invalid_argument("Invalid file.");
	}
}

bool Board::isCitiesConnected(City &c1, City &c2)
{
	return mConnectionsMap[c1].contains(c2);
}

int &Board::operator[](City c)
{
	return mLevelDisease[c];
}

bool Board::is_clean()
{
	for (const auto &p : mLevelDisease)
	{
		if (p.second != 0) 
		{
			return false;
		}
	}
	return true;
}

void Board::remove_cures()
{
	mCuredColors.clear();
}

void Board::remove_stations()
{
	mResaerchStations.clear();
}

void Board::buildResearchStation(City city)
{
	mResaerchStations.insert(city);
}

bool Board::isStationExists(City city)
{
	return mResaerchStations.find(city) != mResaerchStations.end();
}

Color Board::getColor(City city)
{
	return mColorCity[city];
}

void Board::addCureColor(Color color)
{
	mCuredColors.insert(color);
}

bool Board::isCured(Color color)
{
	return mCuredColors.find(color) != mCuredColors.end();
}

ostream &pandemic::operator<<(ostream &os, const Board &b)
{
	os << " Amit Cohen " << endl;
	return os;
}

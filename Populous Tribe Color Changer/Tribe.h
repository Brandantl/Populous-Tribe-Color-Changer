// Brandan Tyler Lasley 2015
// 3-30-2015 02:30 

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "Unit.h"
#include <fstream>
#include <string>
#include <sstream>

class Tribe {

public:
	enum player {
		blue = 0,
		red,
		yellow,
		green
	};

	Tribe();
	~Tribe();

	RGB getColor(player);
	bool setColor(RGB, player);
	void setSegments(RGB*, player);
	RGB getSegments(int, player);

	bool readFromDisk(char *);
	bool writeToDisk(char *);
private:
	// Vars
	const int MAX_TRIBES = 4;
	const static std::string files[];
	Unit * Tribes;

	// Functions
	std::string to_string(int value);
};


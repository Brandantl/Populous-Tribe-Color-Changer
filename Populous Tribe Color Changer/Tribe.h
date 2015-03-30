#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "RGB.h"
#include <fstream>
#include <istream>
#include <string>
#include <sstream>

using namespace std;

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

	bool readFromDisk(char *);
	bool writeToDisk(char *);
private:
	// Vars
	const int MAX_TRIBES = 4;
	const static string files[];
	RGB * Tribes;

	// Functions
	std::string to_string(int value);
};


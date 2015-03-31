// Brandan Tyler Lasley 2015
// 3-30-2015 02:30 

#include "RGB.h"

class Unit {
public:
	Unit();
	~Unit();
	RGB getColor(); 
	RGB getSegments(int);
	void setSegments(RGB*);
private:
	int MAX_SEGMENTS = 8;
	RGB * unitSegments;
};
// Brandan Tyler Lasley 2015
// 3-30-2015 02:30 
#include "Unit.h"

Unit::Unit() {
	unitSegments = nullptr;
}

Unit::~Unit() {
	delete[] unitSegments;
} 

RGB Unit::getColor() {
	return unitSegments[0];
}

void Unit::setColor(RGB* col) {
	if (unitSegments != nullptr) { 
		delete[] unitSegments;
	}
	unitSegments = col;
}

RGB Unit::getSegments(int idx) {
	if (unitSegments == nullptr) {
		return RGB(0, 0, 0);
	}
	return unitSegments[idx];
}

#include "RGB.h"

RGB::RGB() {
	red = 0;
	green = 0;
	blue = 0;
}

RGB::RGB(unsigned char R, unsigned char G, unsigned char B) {
	red = R;
	green = G;
	blue = B;
}

void RGB::setRed(unsigned char R) {
	red = R;
}
void RGB::setGreen(unsigned char G) {
	green = G;
}

void RGB::setBlue(unsigned char B){
	blue = B;
}

unsigned char RGB::getRed() const {
	return +red;
}
unsigned char RGB::getGreen() const {
	return +green;
}

unsigned char RGB::getBlue() const {
	return +blue;
}
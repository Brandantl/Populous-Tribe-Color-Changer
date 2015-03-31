// Brandan Tyler Lasley 2015
// 3-30-2015 02:30 

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

RGB * RGB::generateSegments() {
	RGB * segments = new RGB[8];
	RGB tmp(red,green,blue);
	segments[0] = tmp;
	for (int i = 1; i < 8; i++) {
		tmp = makeSegment(tmp);
		segments[i] = tmp;
	}
	return segments;
}

RGB RGB::makeSegment(RGB c) {
	float RcorrectionFactor = 0.0220f;
	float GcorrectionFactor = 0.0220f;
	float BcorrectionFactor = 0.0220f;

	float r = ((255 + c.getRed()) * RcorrectionFactor) + c.getRed();
	float g = ((255 + c.getGreen()) * GcorrectionFactor) + c.getGreen();
	float b = ((255 + c.getBlue()) * BcorrectionFactor) + c.getBlue();

	if (r > 255) {
		r = 254;
	}
	if (g > 255) {
		g = 254;
	}
	if (b > 255) {
		b = 254;

	}
	return RGB(round(r), round(g), round(b));
}
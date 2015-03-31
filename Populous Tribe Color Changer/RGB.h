// Brandan Tyler Lasley 2015
// 3-30-2015 02:30 

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <math.h> 
class RGB {

public:
	RGB();
	RGB(unsigned char, unsigned char, unsigned char);

	void setRed(unsigned char);
	void setGreen(unsigned char);
	void setBlue(unsigned char);


	unsigned char getRed() const;
	unsigned char getGreen() const;
	unsigned char getBlue() const;

	RGB * generateSegments();
private:
	unsigned char red;
	unsigned char green;
	unsigned char blue;

	RGB makeSegment(RGB);
};
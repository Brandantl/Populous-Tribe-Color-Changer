#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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

private:
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};
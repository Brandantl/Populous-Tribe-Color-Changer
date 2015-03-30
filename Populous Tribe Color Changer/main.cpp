// Brandan Tyler Lasley 2015
// 3-30-2015 02:30 

#include "Tribe.h"
#include <iostream>
using namespace std;

// Driver
int main() {
	Tribe t;
	t.readFromDisk("C:\\Program Files (x86)\\Bullfrog\\Populous");

	cout << "Reading colors from file..." << endl << endl;

	cout << "Blue: " << endl;
	RGB color = t.getColor(Tribe::blue);
	cout << +color.getRed() << " " << +color.getGreen() << " " << +color.getBlue() << endl << endl;

	cout << "Red: " << endl;
	color = t.getColor(Tribe::red);
	cout << +color.getRed() << " " << +color.getGreen() << " " << +color.getBlue() << endl << endl;

	cout << "Yellow: " << endl;
	color = t.getColor(Tribe::yellow);
	cout << +color.getRed() << " " << +color.getGreen() << " " << +color.getBlue() << endl << endl;

	cout << "Green: " << endl;
	color = t.getColor(Tribe::green);
	cout << +color.getRed() << " " << +color.getGreen() << " " << +color.getBlue() << endl << endl;


	cout << "Changing blues color to Bisque (255-228-196) " << endl; 
	t.setColor(RGB(255, 228, 196), Tribe::blue);

	cout << "Saving File" << endl;
	t.writeToDisk("C:\\Program Files (x86)\\Bullfrog\\Populous");

	cout << "Reading from disk" << endl << endl;
	t.readFromDisk("C:\\Program Files (x86)\\Bullfrog\\Populous");

	cout << "Reading colors from file..." << endl << endl;

	cout << "Blue: " << endl;
    color = t.getColor(Tribe::blue);
	cout << +color.getRed() << " " << +color.getGreen() << " " << +color.getBlue() << endl << endl;

	cout << "Red: " << endl;
	color = t.getColor(Tribe::red);
	cout << +color.getRed() << " " << +color.getGreen() << " " << +color.getBlue() << endl << endl;

	cout << "Yellow: " << endl;
	color = t.getColor(Tribe::yellow);
	cout << +color.getRed() << " " << +color.getGreen() << " " << +color.getBlue() << endl << endl;

	cout << "Green: " << endl;
	color = t.getColor(Tribe::green);
	cout << +color.getRed() << " " << +color.getGreen() << " " << +color.getBlue() << endl << endl;

	cin.get();
	return 1;
}
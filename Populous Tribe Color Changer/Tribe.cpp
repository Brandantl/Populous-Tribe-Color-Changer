// Brandan Tyler Lasley 2015
// 3-30-2015 02:30 
#include "Tribe.h"

const std::string Tribe::files[] = {
	"0", "1", "2", "3", "4", "5", "6", "7",
	"8", "9", "a", "b", "c", "d",
	"e", "f", "g", "h", "i",
	"j", "k", "l", "m", "n",
	"o", "p", "q", "r", "s",
	"t", "u", "v", "w", "x",
	"y", "z"
};

Tribe::Tribe() {
	Tribes = new Unit[MAX_TRIBES];
}

Tribe::~Tribe() {
	delete[] this->Tribes;
}

RGB Tribe::getColor(player _player) {
	return Tribes[_player].getColor();
}

bool Tribe::setColor(RGB col, player _player) {
	Tribes[_player].setSegments(col.generateSegments());
	return true;
}

bool Tribe::readFromDisk(char * popDataDir) {
	char * path = new char[std::strlen(popDataDir) + std::strlen("\\data\\pal0-") + std::strlen(".dat") + 2];
	std::strcpy(path, popDataDir);
	std::strcat(path, "\\data\\pal0-");
	std::strcat(path, Tribe::to_string(0).c_str());
	std::strcat(path, ".dat");

	std::ifstream reader;
	reader.open(path, std::ios::binary | std::ios::in);

	RGB * segments = new RGB[8];
	char R, G, B, D;
	// Get Blue
	reader.seekg(864);
	for (int i = 0; i < 8; i++) {
		reader.read(&R, 1);
		reader.read(&G, 1);
		reader.read(&B, 1);
		reader.read(&D, 1);
		segments[i] = RGB(R, G, B);
	}
	Tribes[blue].setSegments(segments);

	segments = new RGB[8];
	// Get Green
	reader.seekg(896);
	for (int i = 0; i < 8; i++) {
		reader.read(&R, 1);
		reader.read(&G, 1);
		reader.read(&B, 1);
		reader.read(&D, 1);
		segments[i] = RGB(R, G, B);
	}
	Tribes[green].setSegments(segments);

	segments = new RGB[8];
	// Get Yellow
	reader.seekg(936);
	for (int i = 0; i < 8; i++) {
		reader.read(&R, 1);
		reader.read(&G, 1);
		reader.read(&B, 1);
		reader.read(&D, 1);
		segments[i] = RGB(R, G, B);
	}
	Tribes[yellow].setSegments(segments);

	segments = new RGB[8];
	// Get Red
	reader.seekg(964);
	for (int i = 0; i < 8; i++) {
		reader.read(&R, 1);
		reader.read(&G, 1);
		reader.read(&B, 1);
		reader.read(&D, 1);
		segments[i] = RGB(R, G, B);
	}
	Tribes[red].setSegments(segments);

	reader.close();
	delete[] path;
	return true;
}

bool Tribe::writeToDisk(char * popDataDir) {
	for (int i = 0; i < 36; i++) {
		char * path = new char[std::strlen(popDataDir) + std::strlen("\\data\\pal0-") + std::strlen(".dat") + 2];
		std::strcpy(path, popDataDir);
		std::strcat(path, "\\data\\pal0-");
		std::strcat(path, files[i].c_str());
		std::strcat(path, ".dat");

		std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);

		file.seekg(864);
		for (int x = 0; x < 8; x++) {
			file << static_cast<unsigned char>(Tribes[blue].getSegments(x).getRed());
			file << static_cast<unsigned char>(Tribes[blue].getSegments(x).getGreen());
			file << static_cast<unsigned char>(Tribes[blue].getSegments(x).getBlue());
			file << static_cast<unsigned char>(0);
		}

		file.seekg(896);
		for (int x = 0; x < 8; x++) {
			file << static_cast<unsigned char>(Tribes[green].getSegments(x).getRed());
			file << static_cast<unsigned char>(Tribes[green].getSegments(x).getGreen());
			file << static_cast<unsigned char>(Tribes[green].getSegments(x).getBlue());
			file << static_cast<unsigned char>(0);
		}

		file.seekg(936);
		for (int x = 0; x < 8; x++) {
			file << static_cast<unsigned char>(Tribes[yellow].getSegments(x).getRed());
			file << static_cast<unsigned char>(Tribes[yellow].getSegments(x).getGreen());
			file << static_cast<unsigned char>(Tribes[yellow].getSegments(x).getBlue());
			file << static_cast<unsigned char>(0);
		}

		file.seekg(964);
		for (int x = 0; x < 8; x++) {
			file << static_cast<unsigned char>(Tribes[red].getSegments(x).getRed());
			file << static_cast<unsigned char>(Tribes[red].getSegments(x).getGreen());
			file << static_cast<unsigned char>(Tribes[red].getSegments(x).getBlue());
			file << static_cast<unsigned char>(0);
		}

		file.close();
		delete[] path;
	}
	return true;
}

void Tribe::setSegments(RGB* seg, player _player) {
	Tribes[_player].setSegments(seg);
}

RGB Tribe::getSegments(int idx, player _player) {
	return Tribes[_player].getSegments(idx);
}

std::string Tribe::to_string(int value)
{
	std::ostringstream os;
	os << value;
	return os.str();
}
#include "Tribe.h"

const string Tribe::files[] = {
	"0", "1", "2", "3", "4", "5", "6", "7",
	"8", "9", "a", "b", "c", "d",
	"e", "f", "g", "h", "i",
	"j", "k", "l", "m", "n",
	"o", "p", "q", "r", "s",
	"t", "u", "v", "w", "x",
	"y", "z"
};

Tribe::Tribe() {
	Tribes = new RGB[MAX_TRIBES];
}

Tribe::~Tribe() {
	delete[] this->Tribes;
}

RGB Tribe::getColor(player _player) {
	return Tribes[_player];
}

bool Tribe::setColor(RGB col, player _player) {
	Tribes[_player] = col;
	return true;
}

bool Tribe::readFromDisk(char * popDataDir) {
	char * path = new char[std::strlen(popDataDir) + std::strlen("\\data\\pal0-") + std::strlen(".dat") + 2];
	std::strcpy(path, popDataDir);
	std::strcat(path, "\\data\\pal0-");
	std::strcat(path, Tribe::to_string(0).c_str());
	std::strcat(path, ".dat");

	ifstream reader;
	reader.open(path, ios::binary | ios::in);

	char R, G, B;
	// Get Blue
	reader.seekg(864);
	reader.read(&R, 1);
	reader.read(&G, 1);
	reader.read(&B, 1);
	this->setColor(RGB(R, G, B), blue);

	// Get Green
	reader.seekg(896);
	reader.read(&R, 1);
	reader.read(&G, 1);
	reader.read(&B, 1);
	this->setColor(RGB(R, G, B), green);

	// Get Yellow
	reader.seekg(936);
	reader.read(&R, 1);
	reader.read(&G, 1);
	reader.read(&B, 1);
	this->setColor(RGB(R, G, B), yellow);

	// Get Red
	reader.seekg(964);
	reader.read(&R, 1);
	reader.read(&G, 1);
	reader.read(&B, 1);
	this->setColor(RGB(R, G, B), red);

	reader.close();
	return true;
}

bool Tribe::writeToDisk(char * popDataDir) {
	for (int i = 0; i < 36; i++) {
		char * path = new char[std::strlen(popDataDir) + std::strlen("\\data\\pal0-") + std::strlen(".dat") + 2];
		std::strcpy(path, popDataDir);
		std::strcat(path, "\\data\\pal0-");
		std::strcat(path, files[i].c_str() );
		std::strcat(path, ".dat");

		FILE* pFile;
		pFile = fopen(path, "wb");
		fseek(pFile, 216 * 4, SEEK_SET);

		for (int j = 0; j < 31; j++) {
			if (j < 8) {
				char buffer[] = { Tribes[blue].getRed(), Tribes[blue].getGreen(), Tribes[blue].getBlue() };
				fwrite(buffer, sizeof(unsigned char), 3, pFile);
				fwrite("", sizeof(unsigned char), 1, pFile);
			}
			else if (j < 16) {
				char buffer[] = { Tribes[green].getRed(), Tribes[green].getGreen(), Tribes[green].getBlue() };
				fwrite(buffer, sizeof(unsigned char), 3, pFile);
				fwrite("", sizeof(unsigned char), 1, pFile);
			}
			else if (j < 24) {
				char buffer[] = { Tribes[yellow].getRed(), Tribes[yellow].getGreen(), Tribes[yellow].getBlue() };
				fwrite(buffer, sizeof(unsigned char), 3, pFile);
				fwrite("", sizeof(unsigned char), 1, pFile);
			}
			else if (j < 32) {
				char buffer[] = { Tribes[red].getRed(), Tribes[red].getGreen(), Tribes[red].getBlue() };
				fwrite(buffer, sizeof(unsigned char), 3, pFile);
				fwrite("", sizeof(unsigned char), 1, pFile);
			}
		}
		fclose(pFile);
	}
	return true;
}

std::string Tribe::to_string(int value)
{
	std::ostringstream os;
	os << value;
	return os.str();
}
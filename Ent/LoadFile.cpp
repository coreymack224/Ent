//LoadFile
#include"LoadFile.h"

string LoadFile(string filename) {
	ifstream file(filename);
	return string(istreambuf_iterator<char>(file), istreambuf_iterator<char>());
}
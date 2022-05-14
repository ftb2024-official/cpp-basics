#include <iostream>

using namespace std;

int main() {
	const int arrayLength = 11;
	char name[arrayLength] = "Khojiakbar";
	int vowelsNum(0); // кол-во гласных букв

	for(char *ptr = name; ptr < name + arrayLength; ++ptr) {
		switch(*ptr) {
			case 'A':
			case 'a':
			case 'E':
			case 'e':
			case 'I':
			case 'i':
			case 'O':
			case 'o':
			case 'U':
			case 'u':
				++vowelsNum;
		}
	}

	cout << "'" << name << "' has " << vowelsNum << " vowels\n";

	return 0;
}
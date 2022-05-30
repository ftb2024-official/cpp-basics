#include <iostream>

using namespace std;

enum class Type {
	INT,
	DOUBLE,
	CSTRING
};

void printValue(void *ptr, Type type) {
	switch(type) {
		case Type::INT:
			cout << *static_cast<int*>(ptr) << endl;
			break;
		case Type::DOUBLE:
			cout << *static_cast<double*>(ptr) << endl;
			break;
		case Type::CSTRING:
			cout << static_cast<char*>(ptr) << endl;
			break;
	}
}

int main() {
	int nValue = 7;
	double dValue = 9.9;
	char chValue[] = "Jackie Chan";

	printValue(&nValue, Type::INT);
	printValue(&dValue, Type::DOUBLE);
	printValue(&chValue, Type::CSTRING);

	return 0;
}
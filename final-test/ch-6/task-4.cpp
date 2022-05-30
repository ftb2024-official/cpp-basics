#include <iostream>

using namespace std;

void printCString(const char *str) {
	while(*str != '\0') {
		cout << *str << " ";
		++str;
	}
}

int main() {
	printCString("Hello World");

	return 0;
}
#include <iostream>

using namespace std;

int main() {
	char sym = 97;

	while(sym <= 122) {
		cout << static_cast<char>(sym - 32) << sym << " ";

		++sym;
	}

	return 0;
}
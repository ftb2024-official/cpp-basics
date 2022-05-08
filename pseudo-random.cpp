#include <iostream>
#include <ctime>
#include <random>

using namespace std;

int main() {
	random_device rd;
	mt19937_64 mersenne(rd());

	for(int i = 1; i <= 10; ++i) {
		cout << i << ": " << mersenne() << endl;
	}

	return 0;
}
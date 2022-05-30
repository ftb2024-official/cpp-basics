#include <iostream>

using namespace std;

void swap(int &x, int &y) {
	int temp;

	temp = x;
	x = y;
	y = temp;
}

int main() {
	int x = 5, y = 7;

	swap(x, y);

	if(x == 7 && y == 5)
		cout << "It works!";
	else
		cout << "It doesn't work!";

	return 0;
}
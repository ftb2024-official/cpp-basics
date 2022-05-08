#include <iostream>

using namespace std;

int main() {
	int choice;

	do {
		cout << "Please make a selection: \n";
		cout << "1) Addition\n";
		cout << "2) Subtraction\n";
		cout << "3) Multiplication\n";
		cout << "4) Division\n";
		cin >> choice;
	} while(choice != 1 && choice != 2 && choice != 3 && choice != 4);

	cout << "You selected oprion #" << choice << endl;

	return 0;
}
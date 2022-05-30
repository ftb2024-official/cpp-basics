#include <iostream>

using namespace std;

int main() {
	cout << "How many names would you like to enter?: ";
	unsigned int length;
	cin >> length;
	cin.ignore(32767, '\n');

	string *names = new string[length];

	for(int index = 0; index < length; ++index) {
		cout << "\tEnter name #" << index + 1 << ": ";
		getline(cin, names[index]);
	}

	for(int startIndex = 0; startIndex < length - 1; ++startIndex) {
		int smallestIndex = startIndex;

		for(int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
			if(names[currentIndex] < names[smallestIndex])
				smallestIndex = currentIndex;

		swap(names[startIndex], names[smallestIndex]);
	}

	cout << "\nSorted list: \n";

	for(int index = 0; index < length; ++index)
		cout << "\tName #" << index + 1 << ": " << names[index] << endl;

	return 0;
}